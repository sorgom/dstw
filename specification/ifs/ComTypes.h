//  ============================================================
//  communication telegram types
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef COMTYPES_H
#define COMTYPES_H

#include <codebase/BaseTypes.h>
#include <codebase/nocopy.h>
#include <codebase/Mem.h>
#include "SystemEnums.h"

#include <codebase/packBegin.h>

//  Com telegrams element identifier
constexpr auto ComNameSize = 12;

struct ComName
{
    CHAR chars[ComNameSize];
    inline ComName()
    {
        Mem::set(chars);
    }
    inline ComName(const ComName& src)
    {
        Mem::cpy(chars, src.chars);
    }
    inline ComName(const ComName&& src)
    {
        Mem::cpy(chars, src.chars);
    }
    inline void operator=(const ComName& src)
    {
        Mem::cpy(chars, src.chars);
    }
    inline bool operator>(const ComName& b) const
    {
        return Mem::cmp(chars, b.chars) > 0;
    }
};

static_assert(ComNameSize == sizeof(ComName));

//  standard telegram size
constexpr auto ComTelegramSize = ComNameSize + 2;

//  Com telegrams data
struct ComData
{
    UINT8 param1;
    UINT8 param2;
};

//  Com telegram
struct ComTele
{
    ComName name;
    ComData data;
};

static_assert(sizeof(ComTele) == ComTelegramSize);

#include <codebase/packEnd.h>

#endif // H_