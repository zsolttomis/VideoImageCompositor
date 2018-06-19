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



#ifndef _NVTOOLSEXT_CORE2_GENERATED_INL_
#define _NVTOOLSEXT_CORE2_GENERATED_INL_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef NVTX_NO_IMPL
#ifndef NVTX_DISABLE
typedef void (NVTX_API * nvtxDomainMarkEx_impl_fntype)(nvtxDomainHandle_t domain, const nvtxEventAttributes_t* eventAttrib);
typedef nvtxRangeId_t (NVTX_API * nvtxDomainRangeStartEx_impl_fntype)(nvtxDomainHandle_t domain, const nvtxEventAttributes_t* eventAttrib);
typedef void (NVTX_API * nvtxDomainRangeEnd_impl_fntype)(nvtxDomainHandle_t domain, nvtxRangeId_t id);
typedef int (NVTX_API * nvtxDomainRangePushEx_impl_fntype)(nvtxDomainHandle_t domain, const nvtxEventAttributes_t* eventAttrib);
typedef int (NVTX_API * nvtxDomainRangePop_impl_fntype)(nvtxDomainHandle_t domain);
typedef nvtxResourceHandle_t (NVTX_API * nvtxDomainResourceCreate_impl_fntype)(nvtxDomainHandle_t domain, nvtxResourceAttributes_t* attribs);
typedef void (NVTX_API * nvtxDomainResourceDestroy_impl_fntype)(nvtxResourceHandle_t resource);
typedef void (NVTX_API * nvtxDomainNameCategoryA_impl_fntype)(nvtxDomainHandle_t domain, uint32_t category, const char* name);
typedef void (NVTX_API * nvtxDomainNameCategoryW_impl_fntype)(nvtxDomainHandle_t domain, uint32_t category, const wchar_t* name);
typedef nvtxStringHandle_t (NVTX_API * nvtxDomainRegisterStringA_impl_fntype)(nvtxDomainHandle_t domain, const char* string);
typedef nvtxStringHandle_t (NVTX_API * nvtxDomainRegisterStringW_impl_fntype)(nvtxDomainHandle_t domain, const wchar_t* string);
typedef nvtxDomainHandle_t (NVTX_API * nvtxDomainCreateA_impl_fntype)(const char* message);
typedef nvtxDomainHandle_t (NVTX_API * nvtxDomainCreateW_impl_fntype)(const wchar_t* message);
typedef void (NVTX_API * nvtxDomainDestroy_impl_fntype)(nvtxDomainHandle_t domain);
extern nvtxDomainMarkEx_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainMarkEx_impl_fnptr);
extern nvtxDomainRangeStartEx_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangeStartEx_impl_fnptr);
extern nvtxDomainRangeEnd_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangeEnd_impl_fnptr);
extern nvtxDomainRangePushEx_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangePushEx_impl_fnptr);
extern nvtxDomainRangePop_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangePop_impl_fnptr);
extern nvtxDomainResourceCreate_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainResourceCreate_impl_fnptr);
extern nvtxDomainResourceDestroy_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainResourceDestroy_impl_fnptr);
extern nvtxDomainNameCategoryA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainNameCategoryA_impl_fnptr);
extern nvtxDomainNameCategoryW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainNameCategoryW_impl_fnptr);
extern nvtxDomainRegisterStringA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainRegisterStringA_impl_fnptr);
extern nvtxDomainRegisterStringW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainRegisterStringW_impl_fnptr);
extern nvtxDomainCreateA_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainCreateA_impl_fnptr);
extern nvtxDomainCreateW_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainCreateW_impl_fnptr);
extern nvtxDomainDestroy_impl_fntype NVTX_VERSIONED_IDENTIFIER(nvtxDomainDestroy_impl_fnptr);
#endif /*NVTX_DISABLE*/

NVTX_DECLSPEC void NVTX_API nvtxDomainMarkEx(nvtxDomainHandle_t domain, const nvtxEventAttributes_t* eventAttrib)
{
#ifndef NVTX_DISABLE
    nvtxDomainMarkEx_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainMarkEx_impl_fnptr);
    if(local!=0)
        (*local)(domain, eventAttrib);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC nvtxRangeId_t NVTX_API nvtxDomainRangeStartEx(nvtxDomainHandle_t domain, const nvtxEventAttributes_t* eventAttrib)
{
#ifndef NVTX_DISABLE
    nvtxDomainRangeStartEx_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangeStartEx_impl_fnptr);
    if(local!=0)
        return (*local)(domain, eventAttrib);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxRangeId_t)0;
}

NVTX_DECLSPEC void NVTX_API nvtxDomainRangeEnd(nvtxDomainHandle_t domain, nvtxRangeId_t id)
{
#ifndef NVTX_DISABLE
    nvtxDomainRangeEnd_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangeEnd_impl_fnptr);
    if(local!=0)
        (*local)(domain, id);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC int NVTX_API nvtxDomainRangePushEx(nvtxDomainHandle_t domain, const nvtxEventAttributes_t* eventAttrib)
{
#ifndef NVTX_DISABLE
    nvtxDomainRangePushEx_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangePushEx_impl_fnptr);
    if(local!=0)
        return (*local)(domain, eventAttrib);
    else
#endif  /*NVTX_DISABLE*/
        return (int)NVTX_NO_PUSH_POP_TRACKING;
}

NVTX_DECLSPEC int NVTX_API nvtxDomainRangePop(nvtxDomainHandle_t domain)
{
#ifndef NVTX_DISABLE
    nvtxDomainRangePop_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainRangePop_impl_fnptr);
    if(local!=0)
        return (*local)(domain);
    else
#endif  /*NVTX_DISABLE*/
        return (int)NVTX_NO_PUSH_POP_TRACKING;
}

NVTX_DECLSPEC nvtxResourceHandle_t NVTX_API nvtxDomainResourceCreate(nvtxDomainHandle_t domain, nvtxResourceAttributes_t* attribs)
{
#ifndef NVTX_DISABLE
    nvtxDomainResourceCreate_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainResourceCreate_impl_fnptr);
    if(local!=0)
        return (*local)(domain, attribs);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxResourceHandle_t)0;
}

NVTX_DECLSPEC void NVTX_API nvtxDomainResourceDestroy(nvtxResourceHandle_t resource)
{
#ifndef NVTX_DISABLE
    nvtxDomainResourceDestroy_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainResourceDestroy_impl_fnptr);
    if(local!=0)
        (*local)(resource);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxDomainNameCategoryA(nvtxDomainHandle_t domain, uint32_t category, const char* name)
{
#ifndef NVTX_DISABLE
    nvtxDomainNameCategoryA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainNameCategoryA_impl_fnptr);
    if(local!=0)
        (*local)(domain, category, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC void NVTX_API nvtxDomainNameCategoryW(nvtxDomainHandle_t domain, uint32_t category, const wchar_t* name)
{
#ifndef NVTX_DISABLE
    nvtxDomainNameCategoryW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainNameCategoryW_impl_fnptr);
    if(local!=0)
        (*local)(domain, category, name);
#endif /*NVTX_DISABLE*/
}

NVTX_DECLSPEC nvtxStringHandle_t NVTX_API nvtxDomainRegisterStringA(nvtxDomainHandle_t domain, const char* string)
{
#ifndef NVTX_DISABLE
    nvtxDomainRegisterStringA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainRegisterStringA_impl_fnptr);
    if(local!=0)
        return (*local)(domain, string);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxStringHandle_t)0;
}

NVTX_DECLSPEC nvtxStringHandle_t NVTX_API nvtxDomainRegisterStringW(nvtxDomainHandle_t domain, const wchar_t* string)
{
#ifndef NVTX_DISABLE
    nvtxDomainRegisterStringW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainRegisterStringW_impl_fnptr);
    if(local!=0)
        return (*local)(domain, string);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxStringHandle_t)0;
}

NVTX_DECLSPEC nvtxDomainHandle_t NVTX_API nvtxDomainCreateA(const char* message)
{
#ifndef NVTX_DISABLE
    nvtxDomainCreateA_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainCreateA_impl_fnptr);
    if(local!=0)
        return (*local)(message);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxDomainHandle_t)0;
}

NVTX_DECLSPEC nvtxDomainHandle_t NVTX_API nvtxDomainCreateW(const wchar_t* message)
{
#ifndef NVTX_DISABLE
    nvtxDomainCreateW_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainCreateW_impl_fnptr);
    if(local!=0)
        return (*local)(message);
    else
#endif  /*NVTX_DISABLE*/
        return (nvtxDomainHandle_t)0;
}

NVTX_DECLSPEC void NVTX_API nvtxDomainDestroy(nvtxDomainHandle_t domain)
{
#ifndef NVTX_DISABLE
    nvtxDomainDestroy_impl_fntype local = NVTX_VERSIONED_IDENTIFIER(nvtxDomainDestroy_impl_fnptr);
    if(local!=0)
        (*local)(domain);
#endif /*NVTX_DISABLE*/
}

#endif /*NVTX_NO_IMPL*/

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /*_NVTOOLSEXT_CORE2_GENERATED_INL_*/
