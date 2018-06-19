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

#include "nvToolsExt.h"

#define INPUT_WIDTH 1920
#define INPUT_HEIGHT 1080
#define INPUT_PIXFMT V4L2_PIX_FMT_YUV420M

#define OUTPUT_WIDTH 1280
#define OUTPUT_HEIGHT 720
#define OUTPUT_PIXFMT V4L2_PIX_FMT_NV12M

#define BUF_TYPE_NVPL 0

typedef struct
{
    NvVideoConverter *conv0;

    char *in_file_path;
    std::ifstream * in_file;

    char *out_file_path;
    std::ofstream * out_file;

    pthread_cond_t queue_cond;

    bool got_error;

    std::chrono::time_point<std::chrono::high_resolution_clock> begin;
} context_t;


using namespace std;

static void
abort(context_t * ctx)
{
    ctx->got_error = true;
    ctx->conv0->abort();
    pthread_cond_broadcast(&ctx->queue_cond);
}

static bool
conv0_capture_dqbuf_thread_callback(struct v4l2_buffer *v4l2_buf,
                                   NvBuffer * buffer, NvBuffer * shared_buffer,
                                   void *arg)
{
    context_t *ctx = (context_t *) arg;

    std::cout << std::chrono::duration<double, std::micro>{std::chrono::high_resolution_clock::now() - ctx->begin}.count() << " us" << std::endl;

    if (!v4l2_buf)
    {
        cerr << "Failed to dequeue buffer from conv0 capture plane" << endl;
        abort(ctx);
        return false;
    }

    if (v4l2_buf->m.planes[0].bytesused == 0)
    {
        return false;
    }

    write_video_frame(ctx->out_file, *buffer);

    ctx->begin = std::chrono::high_resolution_clock::now();

    if (ctx->conv0->capture_plane.qBuffer(*v4l2_buf, buffer) < 0)
    {
        cerr << "Error queueing buffer on conv0 capture plane" << endl;
        abort(ctx);
        return false;
    }

    return true;
}


int
main(int argc, char *argv[])
{

    nvtxRangePush("cucc");

    context_t ctx;
    NvVideoConverter *main_conv;
    int ret = 0;
    int error = 0;
    bool eos = false;

    ctx.in_file = new ifstream("in");

    ctx.out_file = new ofstream("out");

    ctx.conv0 = NvVideoConverter::createVideoConverter("conv0");

    main_conv = ctx.conv0;

    ret = main_conv->setFlipMethod(V4L2_FLIP_METHOD_IDENTITY);

    ret = main_conv->setInterpolationMethod(V4L2_INTERPOLATION_NEAREST);

    ret = main_conv->setTnrAlgorithm(V4L2_TNR_ALGO_ORIGINAL);

    ret = ctx.conv0->setOutputPlaneFormat(INPUT_PIXFMT, INPUT_WIDTH, INPUT_HEIGHT, V4L2_NV_BUFFER_LAYOUT_PITCH);

    ret = ctx.conv0->setCapturePlaneFormat(OUTPUT_PIXFMT, OUTPUT_WIDTH, OUTPUT_HEIGHT, V4L2_NV_BUFFER_LAYOUT_PITCH);

    ret = ctx.conv0->output_plane.setupPlane(V4L2_MEMORY_MMAP, 10, true, false);

    ret = ctx.conv0->capture_plane.setupPlane(V4L2_MEMORY_MMAP, 10, true, false);

    ret = ctx.conv0->output_plane.setStreamStatus(true);

    ret = ctx.conv0->capture_plane.setStreamStatus(true);

    ctx.conv0->capture_plane.setDQThreadCallback(conv0_capture_dqbuf_thread_callback);

    ctx.conv0->capture_plane.startDQThread(&ctx);

    // Enqueue all empty conv0 capture plane buffers
    for (uint32_t i = 0; i < ctx.conv0->capture_plane.getNumBuffers(); i++)
    {
        struct v4l2_buffer v4l2_buf;
        struct v4l2_plane planes[MAX_PLANES];

        v4l2_buf.index = i;
        v4l2_buf.m.planes = planes;

        ret = ctx.conv0->capture_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            cerr << "Error while queueing buffer at conv0 capture plane" << endl;
            abort(&ctx);
            goto cleanup;
        }
    }

    // Read video frame from file and queue buffer on conv0 output plane
    for (uint32_t i = 0; i < ctx.conv0->output_plane.getNumBuffers() && !ctx.got_error && !eos; i++)
    {
        struct v4l2_buffer v4l2_buf;
        struct v4l2_plane planes[MAX_PLANES];
        NvBuffer *buffer = ctx.conv0->output_plane.getNthBuffer(i);

        v4l2_buf.index = i;
        v4l2_buf.m.planes = planes;

        if (read_video_frame(ctx.in_file, *buffer) < 0)
        {
            cerr << "Could not read complete frame from input file" << endl;
            cerr << "File read complete." << endl;
            v4l2_buf.m.planes[0].bytesused = 0;
            eos = true;
        }

        ret = ctx.conv0->output_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            cerr << "Error while queueing buffer at conv0 output plane" << endl;
            abort(&ctx);
            goto cleanup;
        }
    }

    // Read video frame from file till EOS is reached and queue buffer on conv0 output plane
    while (!ctx.got_error && !ctx.conv0->isInError() && !eos)
    {
        struct v4l2_buffer v4l2_buf;
        struct v4l2_plane planes[MAX_PLANES];
        NvBuffer *buffer;

        v4l2_buf.m.planes = planes;

        if (ctx.conv0->output_plane.dqBuffer(v4l2_buf, &buffer, NULL, 100) < 0)
        {
            cerr << "ERROR while DQing buffer at conv0 output plane" << endl;
            abort(&ctx);
            goto cleanup;
        }

        if (read_video_frame(ctx.in_file, *buffer) < 0)
        {
            cerr << "Could not read complete frame from input file" << endl;
            cerr << "File read complete." << endl;
            v4l2_buf.m.planes[0].bytesused = 0;
            eos = true;
        }

        //ctx.begin = std::chrono::high_resolution_clock::now();
        ret = ctx.conv0->output_plane.qBuffer(v4l2_buf, NULL);
        if (ret < 0)
        {
            cerr << "Error while queueing buffer at conv0 output plane" << endl;
            abort(&ctx);
            goto cleanup;
        }
    }

    if (!ctx.got_error)
    {
        // Wait till all capture plane buffers on conv0 and conv1 are dequeued
        ctx.conv0->waitForIdle(-1);
    }

cleanup:
    if (ctx.conv0 && ctx.conv0->isInError())
    {
        cerr << "VideoConverter0 is in error" << endl;
        error = 1;
    }

    if (ctx.got_error)
    {
        error = 1;
    }

    delete ctx.in_file;
    delete ctx.out_file;
    delete ctx.conv0;

    if (error)
    {
        cout << "App run failed" << endl;
    }
    else
    {
        cout << "App run was successful" << endl;
    }

    nvtxRangePop();

    return -error;
}
