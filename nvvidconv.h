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

class nvvidconv {
public:
    nvvidconv(uint32_t inputWidth_, uint32_t inputHeight_, uint32_t inputFMT_, uint32_t outputWidth_, uint32_t outputHeight_, uint32_t outputFMT_, NvV4l2ElementPlane::dqThreadCallback callback_ = nullptr) :
    conv(NvVideoConverter::createVideoConverter("conv")), inputWidth(inputWidth_), inputHeight(inputHeight_), inputFMT(inputFMT_),
    outputWidth(outputWidth_), outputHeight(outputHeight_), outputFMT(outputFMT_), inError(false)
    {
        if(conv)
        {
            conv->setOutputPlaneFormat(inputFMT_, inputWidth, inputHeight, V4L2_NV_BUFFER_LAYOUT_PITCH);
            conv->setCapturePlaneFormat(outputFMT_, outputWidth_, outputHeight_, V4L2_NV_BUFFER_LAYOUT_PITCH);
            conv->output_plane.setupPlane(V4L2_MEMORY_MMAP, 10, true, false);
            conv->capture_plane.setupPlane(V4L2_MEMORY_MMAP, 10, true, false);
            conv->output_plane.setStreamStatus(true);
            conv->capture_plane.setStreamStatus(true);
            conv->capture_plane.setDQThreadCallback( (nullptr == callback_) ? DequeueCapturePlaneBufferCallback : callback_);
            conv->capture_plane.startDQThread(this);
        } else {
            std::cerr << "Error while construct NvVideoConverter" << std::endl;
            abort();
        }
    }

    void abort()
    {
        inError = true;
        conv->abort();
    }

    uint32_t getNumberOfCapturePlaneBuffers()
    {
        return conv->capture_plane.getNumBuffers();
    }

    uint32_t getNumberOfOutputPlaneBuffers()
    {
        return conv->output_plane.getNumBuffers();
    }

    NvBuffer* getOutputPlaneBuffer(uint32_t buffNum)
    {
        return conv->output_plane.getNthBuffer(buffNum);
    }

    void QueueCapturePlaneBuffer(struct v4l2_buffer &v4l2_buf)
    {
        int ret = conv->capture_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            std::cerr << "Error while queueing buffer capture plane" << std::endl;
            abort();
        }
    }

    void QueueOutputPlaneBuffer(struct v4l2_buffer &v4l2_buf)
    {
        int ret = conv->output_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            std::cerr << "Error while queueing buffer output plane" << std::endl;
            abort();
        }
    }

    NvBuffer* DequeueOutputPlaneBuffer(struct v4l2_buffer &v4l2_buf)
    {
        NvBuffer *buffer;
        if (conv->output_plane.dqBuffer(v4l2_buf, &buffer, NULL, 100) < 0)
        {
            std::cerr << "ERROR while DQing buffer at conv output plane" << std::endl;
            abort();
        }
        return buffer;
    }

    bool isInError()
    {
        return (inError || conv->isInError());
    }

    static bool DequeueCapturePlaneBufferCallback(struct v4l2_buffer *v4l2_buf, NvBuffer * buffer, NvBuffer * shared_buffer, void *arg)
    {
        nvvidconv * self = static_cast<nvvidconv*>(arg);
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
        if (self->conv->capture_plane.qBuffer(*v4l2_buf, buffer) < 0)
        {
            std::cerr << "Error queueing buffer on conv0 capture plane" << std::endl;
            self->abort();
            return false;
        }
        return true;
    }

    void waitForIdle(){
        if (!isInError())
        {
            conv->waitForIdle(-1);
        }
    }

protected:
    const std::unique_ptr<NvVideoConverter> conv;
    uint32_t inputWidth;
    uint32_t inputHeight;
    uint32_t inputFMT;
    uint32_t outputWidth;
    uint32_t outputHeight;
    uint32_t outputFMT;
    bool inError;
};
