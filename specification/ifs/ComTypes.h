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

//  common telegram format
struct ComTele
{
    ComName name;
    const UINT8 param1;
    const UINT8 param2;
    inline ComTele(UINT8 param1 = PARAM_UNDEF, UINT8 param2 = PARAM_UNDEF):
        param1(param1),
        param2(param2)
    {}
    NOCOPY(ComTele)
};
static_assert(ComTelegramSize == sizeof(ComTele));

//  field communication telegram
struct ComTeleFld : ComTele
{
    inline ComTeleFld(UINT8 param1 = PARAM_UNDEF, UINT8 param2 = PARAM_UNDEF):
        ComTele(param1, param2)
    {}
    NOCOPY(ComTeleFld)
};

//  DiB communication telegram
struct ComTeleGui : ComTele
{
    inline ComTeleGui(UINT8 param1 = PARAM_UNDEF, UINT8 param2 = PARAM_UNDEF):
        ComTele(param1, param2)
    {}
    NOCOPY(ComTeleGui)
};

#include <codebase/packEnd.h>

#endif // H_