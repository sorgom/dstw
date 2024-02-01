//  ============================================================
//  size safe memset, memcpy, memcmp
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef MEM_H
#define MEM_H

#include <BAS/BaseTypes.h>
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

    //  mem compare two objects
    template <class T>
    inline static auto cmp(const T& r1, const T& r2)
    {
        return std::memcmp(&r1, &r2, sizeof(T));
    }

};
#endif // _H
