/* This file was procedurally generated!  Do not modify this file by hand.  */

/*
* Copyright 2009-2016  NVIDIA Corporation.  All rights reserved.
*
* NOTICE TO USER:
*
* This source code is subject to NVIDIA ownership rights under U.S. and
* international Copyright laws.
*
* This software and the information contained herein is PROPRIETARY and
* CONFIDENTIAL to NVIDIA and is being provided under the terms and conditions
* of a form of NVIDIA software license agreement.
*
* NVIDIA MAKES NO REPRESENTATION ABOUT THE SUITABILITY OF THIS SOURCE
* CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT EXPRESS OR
* IMPLIED WARRANTY OF ANY KIND.  NVIDIA DISCLAIMS ALL WARRANTIES WITH
* REGARD TO THIS SOURCE CODE, INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL,
* OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
* OF USE, DATA OR PROFITS,  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
* OR OTHER TORTIOUS ACTION,  ARISING OUT OF OR IN CONNECTION WITH THE USE
* OR PERFORMANCE OF THIS SOURCE CODE.
*
* U.S. Government End Users.   This source code is a "commercial item" as
* that term is defined at  48 C.F.R. 2.101 (OCT 1995), consisting  of
* "commercial computer  software"  and "commercial computer software
* documentation" as such terms are  used in 48 C.F.R. 12.212 (SEPT 1995)
* and is provided to the U.S. Government only as a commercial end item.
* Consistent with 48 C.F.R.12.212 and 48 C.F.R. 227.7202-1 through
* 227.7202-4 (JUNE 1995), all U.S. Government End Users acquire the
* source code with only those rights set forth herein.
*
* Any use of this source code in individual and commercial software must
* include, in the user documentation and internal comments to the code,
* the above Disclaimer and U.S. Government End Users Notice.
*/



#ifndef _NVTOOLSEXT_OPENCL_GENERATED_INL_
#define _NVTOOLSEXT_OPENCL_GENERATED_INL_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef NVTX_NO_IMPL
#ifndef NVTX_DISABLE
typedef void (NVTX_API * nvtxNameClDeviceA_impl_fntype)(cl_device_id device, const char* name);
typedef void (NVTX_API * nvtxNameClDeviceW_impl_fntype)(cl_device_id device, const wchar_t* name);
typedef void (NVTX_API * nvtxNameClContextA_impl_fntype)(cl_context context, const char* name);
typedef void (NVTX_API * nvtxNameClContextW_impl_fntype)(cl_context context, const wchar_t* name);
typedef void (NVTX_API * nvtxNameClCommandQueueA_impl_fntype)(cl_command_queue command_queue, const char* name);
typedef void (NVTX_API * nvtxNameClCommandQueueW_impl_fntype)(cl_command_queue command_queue, const wchar_t* name);
typedef void (NVTX_API * nvtxNameClMemObjectA_impl_fntype)(cl_mem memobj, const char* name);
typedef void (NVTX_API * nvtxNameClMemObjectW_impl_fntype)(cl_mem memobj, const wchar_t* name);
typedef void (NVTX_API * nvtxNameClSamplerA_impl_fntype)(cl_sampler sampler, const char* name);
typedef void (NVTX_API * nvtxNameClSamplerW_impl_fntype)(cl_sampler sampler, const wchar_t* name);
typedef void (NVTX_API * nvtxNameClProgramA_impl_fntype)(cl_program program, const char* name);
typedef void (NVTX_API * nvtxNameClProgramW_impl_fntype)(cl_program program, const wchar_t* name);
typedef void (NVTX_API * nvtxNameClEventA_impl_fntype)(cl_event evnt, const char* name);
typedef void (NVTX_API * nvtxNameClEventW_impl_fntype)(cl_event evnt, const wchar_t* name);
extern nvtxNameClDeviceA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClDeviceA_impl_fnptr);
extern nvtxNameClDeviceW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClDeviceW_impl_fnptr);
extern nvtxNameClContextA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClContextA_impl_fnptr);
extern nvtxNameClContextW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClContextW_impl_fnptr);
extern nvtxNameClCommandQueueA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClCommandQueueA_impl_fnptr);
extern nvtxNameClCommandQueueW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClCommandQueueW_impl_fnptr);
extern nvtxNameClMemObjectA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClMemObjectA_impl_fnptr);
extern nvtxNameClMemObjectW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClMemObjectW_impl_fnptr);
extern nvtxNameClSamplerA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClSamplerA_impl_fnptr);
extern nvtxNameClSamplerW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClSamplerW_impl_fnptr);
extern nvtxNameClProgramA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClProgramA_impl_fnptr);
extern nvtxNameClProgramW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClProgramW_impl_fnptr);
extern nvtxNameClEventA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClEventA_impl_fnptr);
extern nvtxNameClEventW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameClEventW_impl_fnptr);
#endif /*NVTX_DISABLE*/

NVTX_DECLSPEC void NVTX_API nvtxNameClDeviceA(cl_device_id device, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClDeviceA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClDeviceA_impl_fnptr);
    if(local!=0)
        (*local)(device, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClDeviceW(cl_device_id device, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClDeviceW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClDeviceW_impl_fnptr);
    if(local!=0)
        (*local)(device, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClContextA(cl_context context, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClContextA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClContextA_impl_fnptr);
    if(local!=0)
        (*local)(context, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClContextW(cl_context context, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClContextW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClContextW_impl_fnptr);
    if(local!=0)
        (*local)(context, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClCommandQueueA(cl_command_queue command_queue, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClCommandQueueA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClCommandQueueA_impl_fnptr);
    if(local!=0)
        (*local)(command_queue, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClCommandQueueW(cl_command_queue command_queue, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClCommandQueueW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClCommandQueueW_impl_fnptr);
    if(local!=0)
        (*local)(command_queue, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClMemObjectA(cl_mem memobj, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClMemObjectA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClMemObjectA_impl_fnptr);
    if(local!=0)
        (*local)(memobj, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClMemObjectW(cl_mem memobj, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClMemObjectW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClMemObjectW_impl_fnptr);
    if(local!=0)
        (*local)(memobj, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClSamplerA(cl_sampler sampler, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClSamplerA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClSamplerA_impl_fnptr);
    if(local!=0)
        (*local)(sampler, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClSamplerW(cl_sampler sampler, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClSamplerW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClSamplerW_impl_fnptr);
    if(local!=0)
        (*local)(sampler, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClProgramA(cl_program program, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClProgramA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClProgramA_impl_fnptr);
    if(local!=0)
        (*local)(program, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClProgramW(cl_program program, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClProgramW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClProgramW_impl_fnptr);
    if(local!=0)
        (*local)(program, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClEventA(cl_event evnt, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClEventA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClEventA_impl_fnptr);
    if(local!=0)
        (*local)(evnt, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameClEventW(cl_event evnt, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameClEventW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameClEventW_impl_fnptr);
    if(local!=0)
        (*local)(evnt, name);
#endif /*NVTX_DISABLE*/
}

#endif /*NVTX_NO_IMPL*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /*_NVTOOLSEXT_OPENCL_GENERATED_INL_*/
