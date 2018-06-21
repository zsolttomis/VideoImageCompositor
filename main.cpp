/*
 * Copyright (c) 2016, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "NvUtils.h"
#include "NvVideoConverter.h"
#include <fstream>
#include <queue>
#include <pthread.h>
#include <errno.h>
#include <fstream>
#include <iostream>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <chrono>
#include <memory>

#include "include/nvToolsExt.h"

#define INPUT_WIDTH 3840
#define INPUT_HEIGHT 1080
#define INPUT_PIXFMT V4L2_PIX_FMT_YUV420M

#define OUTPUT_WIDTH 2560
#define OUTPUT_HEIGHT 720
#define OUTPUT_PIXFMT V4L2_PIX_FMT_NV12M

// Attributes for NVIDIA tools extensions SDK NVTX for marking ranges  in NVIDIA system profiler
nvtxEventAttributes_t WriteFrame = {0};
nvtxEventAttributes_t Q_CapturePlane = {0};
nvtxEventAttributes_t DQ_CapturePlane = {0};
nvtxEventAttributes_t DQ_OutputPlane = {0};
nvtxEventAttributes_t ReadFrame = {0};
nvtxEventAttributes_t Q_OutputPlane = {0};
nvtxRangeId_t rangeId;



// Time stamp for measurements
std::chrono::time_point<std::chrono::high_resolution_clock> begin;

class nvvidconv {
public:
    nvvidconv(uint32_t inputWidth_, uint32_t inputHeight_, uint32_t inputFMT_, uint32_t outputWidth_, uint32_t outputHeight_, uint32_t outputFMT_) :
    conv(NvVideoConverter::createVideoConverter("conv")), inputWidth(inputWidth_), inputHeight(inputHeight_), inputFMT(inputFMT_), outputWidth(outputWidth_), outputHeight(outputHeight_), outputFMT(outputFMT_), inError(false)
    {
        if(conv)
        {
            conv->setOutputPlaneFormat(inputFMT_, inputWidth, inputHeight, V4L2_NV_BUFFER_LAYOUT_PITCH);
            conv->setCapturePlaneFormat(outputFMT_, outputWidth_, outputHeight_, V4L2_NV_BUFFER_LAYOUT_PITCH);
            conv->output_plane.setupPlane(V4L2_MEMORY_MMAP, 10, true, false);
            conv->capture_plane.setupPlane(V4L2_MEMORY_MMAP, 10, true, false);
            conv->output_plane.setStreamStatus(true);
            conv->capture_plane.setStreamStatus(true);
            conv->capture_plane.setDQThreadCallback(DequeueCapturePlaneBufferCallback);
            conv->capture_plane.startDQThread(this);

            in_file = std::make_unique<std::ifstream>("in");
            out_file = std::make_unique<std::ofstream>("out");
        }
    }

    void abort()
    {
        inError = true;
        conv->abort();
    }

    uint32_t getNumberOfCapturePlaneBuffers(){
        return conv->capture_plane.getNumBuffers();
    }

    uint32_t getNumberOfOutputPlaneBuffers(){
        return conv->output_plane.getNumBuffers();
    }

    NvBuffer* getOutputPlaneBuffer(uint32_t buffNum){
        return conv->output_plane.getNthBuffer(buffNum);
    }

    void QueueCapturePlaneBuffer(struct v4l2_buffer &v4l2_buf){
        int ret = conv->capture_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            std::cerr << "Error while queueing buffer capture plane" << std::endl;
            abort();
        }
    }

    void QueueOutputPlaneBuffer(struct v4l2_buffer &v4l2_buf){
        int ret = conv->output_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            std::cerr << "Error while queueing buffer output plane" << std::endl;
            abort();
        }
    }

    NvBuffer* DequeueOutputPlaneBuffer(struct v4l2_buffer &v4l2_buf){
        NvBuffer *buffer;
        if (conv->output_plane.dqBuffer(v4l2_buf, &buffer, NULL, 100) < 0)
        {
            std::cerr << "ERROR while DQing buffer at conv output plane" << std::endl;
            abort();
        }
        return buffer;
    }

    bool isInError(){
        return (inError || conv->isInError());
    }

    static bool DequeueCapturePlaneBufferCallback(struct v4l2_buffer *v4l2_buf, NvBuffer * buffer, NvBuffer * shared_buffer, void *arg)
    {
        nvvidconv * self = static_cast<nvvidconv*>(arg);
       nvtxRangeEnd(rangeId);

        if (!v4l2_buf)
        {
            std::cerr << "Failed to dequeue buffer from conv capture plane" << std::endl;
            self->abort();
            return false;
        }

        if (v4l2_buf->m.planes[0].bytesused == 0)
        {
            return false;
        }

        rangeId = nvtxRangeStartEx(&WriteFrame);

        write_video_frame(self->out_file.get(), *buffer);
        nvtxRangeEnd(rangeId);

        begin = std::chrono::high_resolution_clock::now();

        rangeId = nvtxRangeStartEx(&Q_CapturePlane);

        if (self->conv->capture_plane.qBuffer(*v4l2_buf, buffer) < 0)
        {
            std::cerr << "Error queueing buffer on conv0 capture plane" << std::endl;
            self->abort();
            return false;
        }

        nvtxRangeEnd(rangeId);

        rangeId = nvtxRangeStartEx(&DQ_CapturePlane);

        return true;
    }

        const std::unique_ptr<NvVideoConverter> conv;
    std::unique_ptr<std::ifstream> in_file;
    std::unique_ptr<std::ofstream> out_file;

private:

    uint32_t inputWidth;
    uint32_t inputHeight;
    uint32_t inputFMT;
    uint32_t outputWidth;
    uint32_t outputHeight;
    uint32_t outputFMT;
    bool inError;
};


int main(int argc, char *argv[])
{
    // Attributes for NVIDIA tools extensions SDK NVTX for marking ranges  in NVIDIA system profiler
    WriteFrame.version = NVTX_VERSION;
    WriteFrame.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
    WriteFrame.colorType = NVTX_COLOR_ARGB;
    WriteFrame.color = 0xFFFF0000;
    WriteFrame.messageType = NVTX_MESSAGE_TYPE_ASCII;
    WriteFrame.message.ascii = "Write Frame";

    Q_CapturePlane.version = NVTX_VERSION;
    Q_CapturePlane.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
    Q_CapturePlane.colorType = NVTX_COLOR_ARGB;
    Q_CapturePlane.color = 0xFF00FF00;
    Q_CapturePlane.messageType = NVTX_MESSAGE_TYPE_ASCII;
    Q_CapturePlane.message.ascii = "Queue Capture plane";

    DQ_CapturePlane.version = NVTX_VERSION;
    DQ_CapturePlane.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
    DQ_CapturePlane.colorType = NVTX_COLOR_ARGB;
    DQ_CapturePlane.color = 0xFF00FFFF;
    DQ_CapturePlane.messageType = NVTX_MESSAGE_TYPE_ASCII;
    DQ_CapturePlane.message.ascii = "DeQueue Capture plane";

    DQ_OutputPlane.version = NVTX_VERSION;
    DQ_OutputPlane.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
    DQ_OutputPlane.colorType = NVTX_COLOR_ARGB;
    DQ_OutputPlane.color = 0xFF0000FF;
    DQ_OutputPlane.messageType = NVTX_MESSAGE_TYPE_ASCII;
    DQ_OutputPlane.message.ascii = "DeQueue Output Plane";

    ReadFrame.version = NVTX_VERSION;
    ReadFrame.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
    ReadFrame.colorType = NVTX_COLOR_ARGB;
    ReadFrame.color = 0xFFFF00FF;
    ReadFrame.messageType = NVTX_MESSAGE_TYPE_ASCII;
    ReadFrame.message.ascii = "Read Frame";

    Q_OutputPlane.version = NVTX_VERSION;
    Q_OutputPlane.size = NVTX_EVENT_ATTRIB_STRUCT_SIZE;
    Q_OutputPlane.colorType = NVTX_COLOR_ARGB;
    Q_OutputPlane.color = 0xFFFFFF00;
    Q_OutputPlane.messageType = NVTX_MESSAGE_TYPE_ASCII;
    Q_OutputPlane.message.ascii = "Queue Output plane";

    bool eos = false;


    nvvidconv converter(INPUT_WIDTH, INPUT_HEIGHT, INPUT_PIXFMT, OUTPUT_WIDTH, OUTPUT_HEIGHT, OUTPUT_PIXFMT);

    // Enqueue all empty conv0 capture plane buffers
    for (uint32_t i = 0; i < converter.getNumberOfCapturePlaneBuffers(); ++i)
    {
        struct v4l2_buffer v4l2_buf;
        struct v4l2_plane planes[MAX_PLANES];

        v4l2_buf.index = i;
        v4l2_buf.m.planes = planes;

        converter.QueueCapturePlaneBuffer(v4l2_buf);
    }

    // Read video frame from file and queue buffer on conv0 output plane
    for (uint32_t i = 0; i < converter.getNumberOfOutputPlaneBuffers() && !converter.isInError() && !eos; i++)
    {
        struct v4l2_buffer v4l2_buf;
        struct v4l2_plane planes[MAX_PLANES];
        v4l2_buf.index = i;
        v4l2_buf.m.planes = planes;

        NvBuffer* buffer = converter.getOutputPlaneBuffer(i);

        if (read_video_frame(converter.in_file.get(), *buffer) < 0)
        {
            std::cerr << "Could not read complete frame from input file" << std::endl;
            v4l2_buf.m.planes[0].bytesused = 0;
            eos = true;
        }

        converter.QueueOutputPlaneBuffer(v4l2_buf);
    }

    uint32_t count =0;

    // Read video frame from file till EOS is reached and queue buffer on conv0 output plane
    while (!converter.isInError() && !eos)
    {
        std::cout << count++ << std::endl;
        struct v4l2_buffer v4l2_buf;
        struct v4l2_plane planes[MAX_PLANES];
        v4l2_buf.m.planes = planes;

        rangeId = nvtxRangeStartEx(&DQ_OutputPlane);
        NvBuffer *buffer = converter.DequeueOutputPlaneBuffer(v4l2_buf);
        nvtxRangeEnd(rangeId);

        rangeId = nvtxRangeStartEx(&ReadFrame);

        if (read_video_frame(converter.in_file.get(), *buffer) < 0)
        {
            std::cerr << "Could not read complete frame from input file" << std::endl;
            v4l2_buf.m.planes[0].bytesused = 0;
            eos = true;
        }
        nvtxRangeEnd(rangeId);

        rangeId = nvtxRangeStartEx(&Q_OutputPlane);
        converter.QueueOutputPlaneBuffer(v4l2_buf);
        nvtxRangeEnd(rangeId);
    }

    if (!converter.isInError())
    {
        // Wait till all capture plane buffers on conv0 and conv1 are dequeued
        converter.conv->waitForIdle(-1);
    }


    converter.isInError() ? std::cout << "App run failed" << std::endl : std::cout << "App run was successful" << std::endl;
    return 0;
}


/*
#include "NvUtils.h"
#include "NvBuffer.h"
#include "NvLogging.h"
#include <fstream>

int
read_video_frame(std::ifstream * stream, NvBuffer & buffer)
{
    uint32_t i, j;
    char *data;

    for (i = 0; i < buffer.n_planes; i++)
    {
        NvBuffer::NvBufferPlane &plane = buffer.planes[i];
        std::streamsize bytes_to_read =
            plane.fmt.bytesperpixel * plane.fmt.width;
        data = (char *) plane.data;
        plane.bytesused = 0;
        stream->seekg(bytes_to_read*plane.fmt.height ,std::ios::cur);
        if(stream->peek() ==EOF){
            return -1;
        }
        //for (j = 0; j < plane.fmt.height; j++)
        //{
        //    stream->read(data, bytes_to_read);
        //    if (stream->gcount() < bytes_to_read)
        //        return -1;
        //    data += plane.fmt.stride;
        //}
        plane.bytesused = plane.fmt.stride * plane.fmt.height;
    }
    return 0;
}

int
write_video_frame(std::ofstream * stream, NvBuffer &buffer)
{
    uint32_t i, j;
    char *data;

    for (i = 0; i < buffer.n_planes; i++)
    {
        NvBuffer::NvBufferPlane &plane = buffer.planes[i];
        size_t bytes_to_write =
            plane.fmt.bytesperpixel * plane.fmt.width;

        data = (char *) plane.data;
        for (j = 0; j < plane.fmt.height; j++)
        {
            //stream->write(data, bytes_to_write);
            //if (!stream->good())
            //    return -1;
            data += plane.fmt.stride;
        }
    }
    return 0;
}

*/
