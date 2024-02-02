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
constexpr auto SI32 = sizeof(INT32);

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
static_assert(NumElementNameChars == sizeof(ElementName));

struct ProjTSW
{
    ElementName name;
};
static_assert(NumElementNameChars == sizeof(ProjTSW));

struct ProjSIG
{
    ElementName name;
    INT32 type;
};
static_assert(NumElementNameChars + SI32 == sizeof(ProjSIG));

struct ProjLCR
{
    ElementName name;
    INT32 type;
};
static_assert(NumElementNameChars + SI32 == sizeof(ProjLCR));

struct ProjSEG
{
    ElementName name;
};
static_assert(NumElementNameChars == sizeof(ProjSEG));

#include <BAS/packEnd.h>

#endif // H_