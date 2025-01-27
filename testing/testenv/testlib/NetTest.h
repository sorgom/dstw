//  ============================================================
//  network (big endian) byte order conversion
//  see: https://en.wikipedia.org/wiki/Endianness
//  ============================================================
//  created by Manfred Sorgo
#ifndef NET_TEST_H
#define NET_TEST_H

#include <codebase/BaseTypes.h>
#include <testlib/testValues.h>

namespace test
{
class NetTest
{
public:
    inline static UINT16 toN(const UINT16 h)
    {
        return adapt16(h);
    }
    inline static UINT16 toN(const E_TcpVals h)
    {
        return adapt16(h);
    }
    inline static UINT16 toH(const UINT16 n)
    {
        return adapt16(n);
    }

    inline static UINT32 toN(const UINT32 h)
    {
        return adapt32(h);
    }
    inline static UINT32 toH(const UINT32 n)
    {
        return adapt32(n);
    }

    inline static INT16 toN(const INT16 h)
    {
        return static_cast<INT16>(toN(static_cast<const UINT16>(h)));
    }
    inline static INT16 toH(const INT16 n)
    {
        return static_cast<INT16>(toH(static_cast<const UINT16>(n)));
    }

    inline static INT32 toN(const INT32 h)
    {
        return static_cast<INT32>(toN(static_cast<const UINT32>(h)));
    }
    inline static INT32 toH(const INT32 n)
    {
        return static_cast<INT32>(toH(static_cast<const UINT32>(n)));
    }

    NetTest() = delete;
private:

    using af16 = UINT16 (*) (const UINT16);
    using af32 = UINT32 (*) (const UINT32);

    static const af16 keep16, swap16, adapt16;
    static const af32 keep32, swap32, adapt32;

};
} // namespace
#endif // _H
