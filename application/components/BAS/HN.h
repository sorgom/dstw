//  ============================================================
//  host and network byte order
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef HN_H
#define HN_H

#include <BAS/coding.h>

class HN
{
public:
    inline static UINT32 toN(const UINT32 val)
    {
        return adapt32(val);
    }

    inline static UINT32 toH(const UINT32 val)
    {
        return adapt32(val);
    }

    inline static UINT16 toN(const UINT16 val)
    {
        return adapt16(val);
    }

    inline static UINT16 toH(const UINT16 val)
    {
        return adapt16(val);
    }

    NODEF(HN)
    NOCOPY(HN)
private:
    static const UINT32 checkNum;
    static const bool isLittle;

    using Adapt32 = UINT32 (*)(UINT32);
    static const Adapt32 adapt32;
    static const Adapt32 keep32;
    static const Adapt32 chng32;

    using Adapt16 = UINT16 (*)(UINT16);
    static const Adapt16 adapt16;
    static const Adapt16 keep16;
    static const Adapt16 chng16;
};


#endif // H_