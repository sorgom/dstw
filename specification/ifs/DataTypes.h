//  ============================================================
//  structured data types
//  ============================================================
//  created by Manfred Sorgo

#ifndef DATATYPES_H
#define DATATYPES_H

#include "values.h"
#include <codebase/BaseTypes.h>
#include <codebase/Mem.h>
#include <codebase/nocopy.h>

#include <codebase/packBegin.h>

//  communication telegrams
//  Com telegrams element identifier
constexpr auto ComAddrSize = 12;

struct ComAddr
{
    CHAR chars[ComAddrSize];
    inline ComAddr() = default;
    inline ComAddr(const ComAddr& src)
    {
        Mem::cpy(chars, src.chars);
    }
    inline bool operator>(const ComAddr& b) const
    {
        return Mem::cmp(chars, b.chars) > 0;
    }
};

static_assert(ComAddrSize == sizeof(ComAddr));

//  standard telegram size
constexpr auto ComTelegramSize = ComAddrSize + 8;

constexpr auto ComDataSize = 8;

//  Com telegrams data
struct ComData
{
    UINT8 param1 = PARAM_UNDEF;
    UINT8 param2 = PARAM_UNDEF;
    UINT8 param3 = PARAM_UNDEF;
    UINT8 param4 = PARAM_UNDEF;
    UINT8 param5 = PARAM_UNDEF;
    UINT8 param6 = PARAM_UNDEF;
    UINT8 param7 = PARAM_UNDEF;
    UINT8 param8 = PARAM_UNDEF;
};
static_assert(ComDataSize == sizeof(ComData));

//  Com telegram
struct ComTele
{
    ComAddr addr;
    ComData data;
};

static_assert(ComAddrSize + ComDataSize == sizeof(ComTele));

//  project items
struct ProjItem
{
    ComAddr addr;
    UINT8 type;
    UINT8 reserve[7];
};
static_assert(ComAddrSize + 8 == sizeof(ProjItem));

//  Com TCP setup
struct ComSetup
{
    //  TCP port field
    UINT16 portFld;
    //  TCP port DiB
    UINT16 portGui;
    //  TCP port control
    UINT16 portCtrl;
    //  TCP select timeout ms
    UINT16 timeout;
};
static_assert(8 == sizeof(ComSetup));

//  result of a find operation
struct PosRes
{
    const bool valid;
    const size_t pos;
    inline PosRes(bool valid, size_t pos = 0) :
        valid(valid),
        pos(pos)
    {}
    NODEF(PosRes)
};

#include <codebase/packEnd.h>

//  byte array
template <size_t N>
using ByteArray = UINT8[N];

#endif // _H
