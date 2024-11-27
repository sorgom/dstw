//  ============================================================
//  network (big endian) byte order conversion
//  see: https://en.wikipedia.org/wiki/Endianness
//  ============================================================
//  created by Manfred Sorgo
#ifndef NET_H
#define NET_H

#include <codebase/BaseTypes.h>
#include <ifs/DataTypes.h>
#include <BAS/coding.h>

#include <type_traits>

class Net
{
public:
    static const bool isBig;

    template <typename NUM>
    static void toN(ByteArrayFor<NUM>& b, const NUM n)
    {
        toNet(b, n);
    }

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

    //  explicit ComData Net exchange
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
    // net byte positions for 16 bit values
    static const size_t pn20, pn21;
    // net byte positions for 32 bit values
    static const size_t pn40, pn41, pn42, pn43;

    template <typename NUM>
    constexpr static void check()
    {
        static_assert(std::is_integral_v<NUM>);
        static_assert(sizeof(NUM) == 2 or sizeof(NUM) == 4);
    }

    template <typename NUM>
    static void toNet(UINT8* b, const NUM n)
    {
        check<NUM>();
        const UINT8* p = reinterpret_cast<const UINT8*>(&n);
        if constexpr (sizeof(NUM) == 2)
        {
            b[pn20] = p[0];
            b[pn21] = p[1];
        }
        else
        {
            b[pn40] = p[0];
            b[pn41] = p[1];
            b[pn42] = p[2];
            b[pn43] = p[3];
        }
    }

    template <typename NUM>
    static void toHost(NUM& n, const UINT8* b)
    {
        check<NUM>();
        UINT8* p = reinterpret_cast<UINT8*>(&n);
        if constexpr (sizeof(NUM) == 2)
        {
            p[0] = b[pn20];
            p[1] = b[pn21];
        }
        else
        {
            p[0] = b[pn40];
            p[1] = b[pn41];
            p[2] = b[pn42];
            p[3] = b[pn43];
        }
    }
};

#endif // _H
