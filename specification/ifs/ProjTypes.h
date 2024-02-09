//  ============================================================
//  projectation data types
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJTYPES_H
#define PROJTYPES_H

#include "ComTypes.h"

#include <codebase/packBegin.h>

struct ProjTSW
{
    ComName name;
};
static_assert(ComNameSize == sizeof(ProjTSW));

struct ProjSIG
{
    ComName name;
    UINT8 type;
};
static_assert(ComNameSize + 1 == sizeof(ProjSIG));

struct ProjLCR
{
    ComName name;
    UINT8 type;
};
static_assert(ComNameSize + 1 == sizeof(ProjLCR));

struct ProjSEG
{
    ComName name;
};
static_assert(ComNameSize == sizeof(ProjSEG));

#include <codebase/packEnd.h>

#endif // H_