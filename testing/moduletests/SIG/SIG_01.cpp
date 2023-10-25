//  ============================================================
//  test of module SIG X
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SIG/SIG_X.h>

namespace test
{

    TEST_GROUP_BASE(SIG_01, TestGroupBase)
    {};

    //  test type: sizes check
    TEST(SIG_01, T01)
    {
        L_CHECK_EQUAL_SIZE(SIG, SIG_H)
        L_CHECK_EQUAL_SIZE(SIG, SIG_N)
        L_CHECK_EQUAL_SIZE(SIG, SIG_H_N)
    }
}