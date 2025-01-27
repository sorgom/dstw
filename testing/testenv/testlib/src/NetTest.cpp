#include <testlib/NetTest.h>

namespace test
{

const NetTest::af16 NetTest::keep16 = [](const UINT16 u) { return u; };
const NetTest::af16 NetTest::swap16 = [](const UINT16 u)
    {
        union
        {
            UINT16 u;
            UINT8 b[2];
        } src, trg;
        src.u = u;
        trg.b[0] = src.b[1];
        trg.b[1] = src.b[0];
        return trg.u;
    };

const NetTest::af32 NetTest::keep32 = [](const UINT32 u) { return u; };
const NetTest::af32 NetTest::swap32 = [](const UINT32 u)
    {
        union
        {
            UINT32 u;
            UINT8 b[4];
        } src, trg;
        src.u = u;
        trg.b[0] = src.b[3];
        trg.b[1] = src.b[2];
        trg.b[2] = src.b[1];
        trg.b[3] = src.b[0];
        return trg.u;
    };

const UINT16 t16 = 0x0A0B;
const bool isBig = *reinterpret_cast<const UINT8*>(&t16) == 0x0A;

const NetTest::af16 NetTest::adapt16 = isBig ? keep16 : swap16;
const NetTest::af32 NetTest::adapt32 = isBig ? keep32 : swap32;

} // namespace
