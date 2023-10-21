//  ============================================================
//  projectation data types
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJDATA_H
#define PROJDATA_H

#include <baselib/BaseTypes.h>


#include <baselib/packBegin.h>

struct ElementName
{
    CHAR chars[16];
};

struct ProjTSW
{
    ElementName name;
};

struct ProjSIG
{
    ElementName name;
};

struct ProjLCR
{
    ElementName name;
};

struct ProjSEG
{
    ElementName name;
};

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

#include <baselib/packEnd.h>



#endif // H_