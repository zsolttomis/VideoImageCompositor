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



#ifndef _NVTOOLSEXT_CORE_GENERATED_INL_
#define _NVTOOLSEXT_CORE_GENERATED_INL_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef NVTX_NO_IMPL
#ifndef NVTX_DISABLE
typedef void (NVTX_API * nvtxMarkEx_impl_fntype)(const nvtxEventAttributes_t* eventAttrib);
typedef void (NVTX_API * nvtxMarkA_impl_fntype)(const char* message);
typedef void (NVTX_API * nvtxMarkW_impl_fntype)(const wchar_t* message);
typedef nvtxRangeId_t (NVTX_API * nvtxRangeStartEx_impl_fntype)(const nvtxEventAttributes_t* eventAttrib);
typedef nvtxRangeId_t (NVTX_API * nvtxRangeStartA_impl_fntype)(const char* message);
typedef nvtxRangeId_t (NVTX_API * nvtxRangeStartW_impl_fntype)(const wchar_t* message);
typedef void (NVTX_API * nvtxRangeEnd_impl_fntype)(nvtxRangeId_t id);
typedef int (NVTX_API * nvtxRangePushEx_impl_fntype)(const nvtxEventAttributes_t* eventAttrib);
typedef int (NVTX_API * nvtxRangePushA_impl_fntype)(const char* message);
typedef int (NVTX_API * nvtxRangePushW_impl_fntype)(const wchar_t* message);
typedef int (NVTX_API * nvtxRangePop_impl_fntype)(void);
typedef void (NVTX_API * nvtxNameCategoryA_impl_fntype)(uint32_t category, const char* name);
typedef void (NVTX_API * nvtxNameCategoryW_impl_fntype)(uint32_t category, const wchar_t* name);
typedef void (NVTX_API * nvtxNameOsThreadA_impl_fntype)(uint32_t threadId, const char* name);
typedef void (NVTX_API * nvtxNameOsThreadW_impl_fntype)(uint32_t threadId, const wchar_t* name);
extern nvtxMarkEx_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxMarkEx_impl_fnptr);
extern nvtxMarkA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxMarkA_impl_fnptr);
extern nvtxMarkW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxMarkW_impl_fnptr);
extern nvtxRangeStartEx_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangeStartEx_impl_fnptr);
extern nvtxRangeStartA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangeStartA_impl_fnptr);
extern nvtxRangeStartW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangeStartW_impl_fnptr);
extern nvtxRangeEnd_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangeEnd_impl_fnptr);
extern nvtxRangePushEx_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangePushEx_impl_fnptr);
extern nvtxRangePushA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangePushA_impl_fnptr);
extern nvtxRangePushW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangePushW_impl_fnptr);
extern nvtxRangePop_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxRangePop_impl_fnptr);
extern nvtxNameCategoryA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameCategoryA_impl_fnptr);
extern nvtxNameCategoryW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameCategoryW_impl_fnptr);
extern nvtxNameOsThreadA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameOsThreadA_impl_fnptr);
extern nvtxNameOsThreadW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxNameOsThreadW_impl_fnptr);
#endif /*NVTX_DISABLE*/

NVTX_DECLSPEC void NVTX_API nvtxMarkEx(const nvtxEventAttributes_t* eventAttrib)
{
#ifndef NVTX_DISABLE
    nvtxMarkEx_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxMarkEx_impl_fnptr);
    if(local!=0)
        (*local)(eventAttrib);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxMarkA(const char* message)
{
#ifndef NVTX_DISABLE
    nvtxMarkA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxMarkA_impl_fnptr);
    if(local!=0)
        (*local)(message);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxMarkW(const wchar_t* message)
{
#ifndef NVTX_DISABLE
    nvtxMarkW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxMarkW_impl_fnptr);
    if(local!=0)
        (*local)(message);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxRangeStartEx(const nvtxEventAttributes_t* eventAttrib)
{
#ifndef NVTX_DISABLE
    nvtxRangeStartEx_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangeStartEx_impl_fnptr);
    if(local!=0)
        return (*local)(eventAttrib);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxRangeId_t)0;
}

NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxRangeStartA(const char* message)
{
#ifndef NVTX_DISABLE
    nvtxRangeStartA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangeStartA_impl_fnptr);
    if(local!=0)
        return (*local)(message);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxRangeId_t)0;
}

NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxRangeStartW(const wchar_t* message)
{
#ifndef NVTX_DISABLE
    nvtxRangeStartW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangeStartW_impl_fnptr);
    if(local!=0)
        return (*local)(message);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxRangeId_t)0;
}

NVTX_DECLSPEC void NVTX_API nvtxRangeEnd(nvtxRangeId_t id)
{
#ifndef NVTX_DISABLE
    nvtxRangeEnd_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangeEnd_impl_fnptr);
    if(local!=0)
        (*local)(id);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC int NVTX_API nvtxRangePushEx(const nvtxEventAttributes_t* eventAttrib)
{
#ifndef NVTX_DISABLE
    nvtxRangePushEx_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangePushEx_impl_fnptr);
    if(local!=0)
        return (*local)(eventAttrib);
    else
#endif  /*NVTX_DISABLE*/
        return (int)NVTX_NO_PUSH_POP_TRACKING;
}

NVTX_DECLSPEC int NVTX_API nvtxRangePushA(const char* message)
{
#ifndef NVTX_DISABLE
    nvtxRangePushA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangePushA_impl_fnptr);
    if(local!=0)
        return (*local)(message);
    else
#endif  /*NVTX_DISABLE*/
        return (int)NVTX_NO_PUSH_POP_TRACKING;
}

NVTX_DECLSPEC int NVTX_API nvtxRangePushW(const wchar_t* message)
{
#ifndef NVTX_DISABLE
    nvtxRangePushW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangePushW_impl_fnptr);
    if(local!=0)
        return (*local)(message);
    else
#endif  /*NVTX_DISABLE*/
        return (int)NVTX_NO_PUSH_POP_TRACKING;
}

NVTX_DECLSPEC int NVTX_API nvtxRangePop(void)
{
#ifndef NVTX_DISABLE
    nvtxRangePop_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxRangePop_impl_fnptr);
    if(local!=0)
        return (*local)();
    else
#endif  /*NVTX_DISABLE*/
        return (int)NVTX_NO_PUSH_POP_TRACKING;
}

NVTX_DECLSPEC void NVTX_API nvtxNameCategoryA(uint32_t category, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameCategoryA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameCategoryA_impl_fnptr);
    if(local!=0)
        (*local)(category, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameCategoryW(uint32_t category, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameCategoryW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameCategoryW_impl_fnptr);
    if(local!=0)
        (*local)(category, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameOsThreadA(uint32_t threadId, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxNameOsThreadA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameOsThreadA_impl_fnptr);
    if(local!=0)
        (*local)(threadId, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxNameOsThreadW(uint32_t threadId, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxNameOsThreadW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxNameOsThreadW_impl_fnptr);
    if(local!=0)
        (*local)(threadId, name);
#endif /*NVTX_DISABLE*/
}

#endif /*NVTX_NO_IMPL*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /*_NVTOOLSEXT_CORE_GENERATED_INL_*/
