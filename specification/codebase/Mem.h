//  ============================================================
//  apply size safe memset, memcpy, memcmp
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <codebase/BaseTypes.h>
#include <cstring>

class Mem
{
public:
    //  memset a char array
    template <size_t N>
    inline static void set(CHAR(& a)[N], CHAR b = 0)
    {
        std::memset(a, b, N);
    }

    //  memcpy char array
    template <size_t N>
    inline static void cpy(CHAR(& trg)[N], const CHAR(& src)[N])
    {
        std::memcpy(trg, src, N);
    }

    //  mem compare two char arrays
    template <size_t N>
    inline static auto cmp(const CHAR(& c1)[N], const CHAR(& c2)[N])
    {
        return std::memcmp(c1, c2, N);
    }
};

