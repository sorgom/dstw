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

constexpr auto NumElementNameChars = 9;

struct ElementName
{
    CHAR chars[NumElementNameChars];
    inline ElementName()
    {
        Mem::set(chars);
    }
    inline ElementName(const ElementName& src)
    {
        Mem::cpy(chars, src.chars);
    }
    inline void operator=(const ElementName& src)
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

#include <BAS/packEnd.h>

#endif // H_