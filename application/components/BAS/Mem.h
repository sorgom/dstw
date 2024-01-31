//  ============================================================
//  type safe memset & memcpy
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

    //  memset a byte array
    template <size_t N>
    inline static void set(BYTE(& a)[N], BYTE b = 0)
    {
        std::memset(a, b, N);
    }

    template <size_t N>
    inline static void cpy(CHAR(& trg)[N], const CHAR(& src)[N])
    {
        std::memcpy(trg, src, N);
    }

    template <size_t N>
    inline static void cpy(BYTE(& trg)[N], const BYTE(& src)[N])
    {
        std::memcpy(trg, src, N);
    }

    //  memset a byte array
    template <size_t N>
    inline static void cpy(BYTE(& a)[N], BYTE b = 0)
    {
        std::memset(a, b, N);
    }

    // //  memset a data object with given byte
    // template <class T>
    // inline static void set(T& ref, UINT8 b = 0)
    // {
    //     std::memset(&ref, b, sizeof(T));
    // }

    // //  set all bytes of a data object to zero
    // template <class T>
    // inline static void zero(T& ref)
    // {
    //     std::memset(&ref, 0, sizeof(T));
    // }

    //  copy bytes from source data object to target data object
    template <class T>
    inline static void cpy(T& ref, const T& src)
    {
        std::memcpy(&ref, &src, sizeof(T));
    }

    template <class T>
    inline static void cpy(PTR p, const T& src)
    {
        std::memcpy(p, &src, sizeof(T));
    }

    //  mem compare two objects
    template <class T>
    inline static INT32 cmp(const T& r1, const T& r2)
    {
        return std::memcmp(&r1, &r2, sizeof(T));
    }

};
#endif // _H
