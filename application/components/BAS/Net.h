//  ============================================================
//  network (big endian) byte order conversion
//  see: https://en.wikipedia.org/wiki/Endianness
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef BAS_NET_H
#define BAS_NET_H

#include <codebase/BaseTypes.h>
#include <ifs/DataTypes.h>

#include <type_traits>

class Net
{
public:
    //  store host byte order numerical type
    //  into network byte order byte array
    template <typename NUM>
    static void toN(ByteArrayFor<NUM>& b, const NUM n)
    {
        toNet(b, n);
    }

    //  retrieve host byte order numerical type
    //  from network byte order byte array
    template <typename NUM>
    static void toH(NUM& n, const ByteArrayFor<NUM>& b)
    {
        toHost(n, b);
    }

    //  store host byte order numerical type
    //  into network byte order struct object
    template <typename NUM, class T, size_t P=0>
    static void toN(T& obj, const NUM n)
    {
        static_assert(P + sizeof(NUM) <= sizeof(T));
        toNet(reinterpret_cast<UINT8*>(&obj) + P, n);
    }

    //  retrieve host byte order numerical type
    //  from network byte order struct object
    template <typename NUM, class T, size_t P=0>
    static void toH(NUM& n, const T& obj)
    {
        static_assert(P + sizeof(NUM) <= sizeof(T));
        toHost(n, reinterpret_cast<const UINT8*>(&obj) + P);
    }

    //  ComData exchange
    //  - UINT16
    //  - UINT32
    //  - INT16
    //  - INT32

    template <size_t P=0>
    static void toN(ComData& obj, const UINT16 n)
    {
        toN<UINT16, ComData, P>(obj, n);
    }

    template <size_t P=0>
    static void toH(UINT16& n, const ComData& obj)
    {
        toH<UINT16, ComData, P>(n, obj);
    }

    template <size_t P=0>
    static void toN(ComData& obj, const UINT32 n)
    {
        toN<UINT32, ComData, P>(obj, n);
    }

    template <size_t P=0>
    static void toH(UINT32& n, const ComData& obj)
    {
        toH<UINT32, ComData, P>(n, obj);
    }

    template <size_t P=0>
    static void toN(ComData& obj, const INT16 n)
    {
        toN<INT16, ComData, P>(obj, n);
    }

    template <size_t P=0>
    static void toH(INT16& n, const ComData& obj)
    {
        toH<INT16, ComData, P>(n, obj);
    }

    template <size_t P=0>
    static void toN(ComData& obj, const INT32 n)
    {
        toN<INT32, ComData, P>(obj, n);
    }

    template <size_t P=0>
    static void toH(INT32& n, const ComData& obj)
    {
        toH<INT32, ComData, P>(n, obj);
    }

private:
    template <typename NUM>
    static void toNet(UINT8* b, const NUM n)
    {
        static_assert(std::is_integral_v<NUM>);
        size_t j = sizeof(NUM) - 1;
        for (size_t i = 0; i < sizeof(NUM); ++i, --j)
        {
            b[j] = static_cast<BYTE>(n >> (i * 8));
        }
    }
    template <typename NUM>
    static void toHost(NUM& n, const UINT8* b)
    {
        static_assert(std::is_integral_v<NUM>);
        n = 0;
        size_t j = sizeof(NUM) - 1;
        for (size_t i = 0; i < sizeof(NUM); ++i, --j)
        {
            n |= static_cast<NUM>(b[j]) << (i * 8);
        }
    }
};

#endif // _H
