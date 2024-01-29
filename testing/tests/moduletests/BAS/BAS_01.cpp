//  ============================================================
//  test of basic functionality
//  - sizes of base types
//  - pack headers
//  - some proj data sizes
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <ifs/PosRes.h>

namespace test
{

    TEST_GROUP_BASE(BAS_01, TestGroupBase) {};

#define S_CHECK(SIZE, TYPE) \
    L_CHECK_EQUAL(SIZE, sizeof(TYPE))    
    
    //  integer sizes (check)
    TEST(BAS_01, T01)
    {
        STEP(1)
        S_CHECK(1, UINT8)
        S_CHECK(2, UINT16)
        S_CHECK(4, UINT32)

        STEP(2)
        S_CHECK(1, INT8)
        S_CHECK(2, INT16)
        S_CHECK(4, INT32)

        STEP(3)
        S_CHECK(1, BYTE)
        S_CHECK(1, CHAR)
    }

    struct Unpacked
    {
        UINT8  m1;
        UINT32 m2;
    };

    #include <BAS/packBegin.h>

    struct Packed
    {
        UINT8  m1;
        UINT32 m2;
    };

    #include <BAS/packEnd.h>

    //  Test of pack 
    TEST(BAS_01, T02)
    {
        STEP(1)
        S_CHECK(8, Unpacked)

        STEP(2)
        S_CHECK(5, Packed)
    }

    //  proj data sizes
    TEST(BAS_01, T03)
    {
        STEP(1)
        S_CHECK(13, ProjSIG)
        S_CHECK( 9, ProjTSW)
    }

    PosRes getPosRes(INT32 i)
    {
        return i < 0 ? PosRes {0, false} : PosRes {static_cast<size_t>(i), true};
    }

    TEST(BAS_01, T04)
    {
        STEP(1)
        const auto r1 = getPosRes(100);
        L_CHECK_EQUAL(100, r1.pos);
        L_CHECK_TRUE(r1.valid)
        const auto r2 = getPosRes(-1);
        L_CHECK_EQUAL(0, r2.pos);
        L_CHECK_FALSE(r2.valid)
    }

}
