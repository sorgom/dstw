//  ============================================================
//  test of Net
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <testlib/NetTest.h>
#include <BAS/Net.h>

#include <limits>

namespace test
{
    TEST_GROUP_BASE(BAS_03, TestGroupBase)
    {};

    //  test type: equivalence class test
    //  byte order conversion: unsigned
    TEST(BAS_03, T01)
    {
        STEP(1)
        {
            const UINT16 h = 0x010F;
            const auto na = Net::toN(h);
            const auto nt = NetTest::toN(h);
            L_CHECK_EQUAL(nt, na);

            const auto ha = Net::toH(na);
            L_CHECK_EQUAL(h, ha);
        }
        STEP(2)
        {
            const UINT32 h = 0x01020408;
            const auto na = Net::toN(h);
            const auto nt = NetTest::toN(h);
            L_CHECK_EQUAL(nt, na);

            const auto ha = Net::toH(na);
            L_CHECK_EQUAL(h, ha);
        }
    }

    //  test type: equivalence class test
    //  byte order conversion: signed
    TEST(BAS_03, T02)
    {
        STEP(1)
        {
            const INT16 h = INT16_MAX;
            const auto na = Net::toN(h);
            const auto nt = NetTest::toN(h);
            L_CHECK_EQUAL(nt, na);

            const auto ha = Net::toH(na);
            L_CHECK_EQUAL(h, ha);
        }
        STEP(2)
        {
            const INT16 h = INT16_MIN;
            const auto na = Net::toN(h);
            const auto nt = NetTest::toN(h);
            L_CHECK_EQUAL(nt, na);

            const auto ha = Net::toH(na);
            L_CHECK_EQUAL(h, ha);
        }
        STEP(3)
        {
            const INT32 h = INT32_MAX;
            const auto na = Net::toN(h);
            const auto nt = NetTest::toN(h);
            L_CHECK_EQUAL(nt, na);

            const auto ha = Net::toH(na);
            L_CHECK_EQUAL(h, ha);
        }
        STEP(3)
        {
            const INT32 h = INT32_MIN;
            const auto na = Net::toN(h);
            const auto nt = NetTest::toN(h);
            L_CHECK_EQUAL(nt, na);

            const auto ha = Net::toH(na);
            L_CHECK_EQUAL(h, ha);
        }
    }

} // namespace
