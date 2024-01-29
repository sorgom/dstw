//  ============================================================
//  projectation data types
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJDATA_H
#define PROJDATA_H

#include <BAS/BaseTypes.h>
#include <BAS/Mem.h>


#include <BAS/packBegin.h>

struct ElementName
{
    CHAR chars[9];
    inline ElementName() = default;
    inline ElementName(const ElementName& src)
    {
        Mem::cpy(chars, src.chars);
    }
};
static_assert(9 == sizeof(ElementName));

struct ProjTSW
{
    ElementName name;
};
static_assert(9 == sizeof(ProjTSW));

struct ProjSIG
{
    ElementName name;
    INT32 type;
};
static_assert(13 == sizeof(ProjSIG));

struct ProjLCR
{
    ElementName name;
    INT32 type;
};
static_assert(13 == sizeof(ProjLCR));

struct ProjSEG
{
    ElementName name;
};
static_assert(9 == sizeof(ProjSEG));

struct ProjData
{
    UINT32 numTSW;
    UINT32 numSIG;
    UINT32 numLCR;
    UINT32 numSEG;
    const ProjTSW* pTSW;
    const ProjSIG* pSIG;
    const ProjLCR* pLCR;
    const ProjSEG* pSEG;
};

#include <BAS/packEnd.h>



#endif // H_