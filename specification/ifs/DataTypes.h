//  ============================================================
//  structured data types
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef DATAYPES_H
#define DATAYPES_H

#include "values.h"
#include <codebase/BaseTypes.h>
#include <codebase/Mem.h>
#include <codebase/nocopy.h>

#include <codebase/packBegin.h>

//  ============================================================
//  - communication telegrams
//  ============================================================

//  Com telegrams element identifier
constexpr auto ComNameSize = 12;

struct ComName
{
    CHAR chars[ComNameSize];
    inline ComName() = default;
    inline ComName(const ComName& src)
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
constexpr auto ComTelegramSize = ComNameSize + 8;

//  Com telegrams data
struct ComData
{
    UINT8 param1 = PARAM_UNDEF;
    UINT8 param2 = PARAM_UNDEF;
    UINT8 reserve[6];
};

//  Com telegram
struct ComTele
{
    ComName name;
    ComData data;
};

static_assert(ComTelegramSize == sizeof(ComTele));

//  ============================================================
//  - project items
//  ============================================================
struct ProjItem
{
    ComName name;
    UINT8 type;
    UINT8 reserve[7];
};
static_assert(ComNameSize + 8 == sizeof(ProjItem));

#include <codebase/packEnd.h>

//  ============================================================
//  - result of a find operation
//  ============================================================
struct PosRes
{
    const size_t pos;
    const bool valid;
    inline PosRes(size_t pos, bool valid):
        pos(pos),
        valid(valid)
    {}
    NODEF(PosRes)
};

#endif // H_