//  ============================================================
//  projectation data types
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJDATA_H
#define PROJDATA_H

#include <BAS/BaseTypes.h>


#include <BAS/packBegin.h>

struct ElementName
{
    CHAR chars[9];
};

struct ProjTSW
{
    ElementName name;
};

struct ProjSIG
{
    ElementName name;
    INT32 type;
};

struct ProjLCR
{
    ElementName name;
    INT32 type;
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

#include <BAS/packEnd.h>



#endif // H_