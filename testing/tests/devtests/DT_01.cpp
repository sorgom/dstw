//  ============================================================
//  test of mocks
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

namespace test
{
    TEST_GROUP_BASE(DT_01, TestGroupBase) {};

    //  call mock explicitly
    TEST(DT_01, T02)
    {
        STEP(1)
        ComData d1 {11, 111};
        m_Dispatcher().expectToFld(1, d1);
        // ComData d2 {11, 121};
        m_Dispatcher().toFld(1, ComData{11, 111});
        CHECK_N_CLEAR()
    }
}
