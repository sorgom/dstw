//  ============================================================
//  test of mocks
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

namespace test
{
    TEST_GROUP_BASE(DT_01, TestGroupBase) {};

    TEST(DT_01, T01)
    {
        ComData dt1{11, 22};
        ComData dt2 = dt1;
        CHECK_EQUAL(dt1.param1, dt2.param1);
        CHECK_EQUAL(dt1.param2, dt2.param2);

        const ComName nm1;
        const ComTele tl3{nm1, dt1};
        CHECK_EQUAL(dt1.param1, tl3.data.param1);
        CHECK_EQUAL(dt1.param2, tl3.data.param2);
    }
    //  call mock explicitly
    TEST(DT_01, T02)
    {
        STEP(1)
            ComData d1 {11, 111};
            m_Dispatcher().expectToFld(1, d1);
        // ComData d2 {11, 121};
        m_Dispatcher().toFld(1, ComData{11, 121});
        CHECK_N_CLEAR()
    }
    // //  call mock from IL
    // TEST(DT_01, T02)
    // {
    //     STEP(1)
    //     m_Dispatcher().expectDispatch(1, ComTeleFld(11, 111));
    //     m_Dispatcher().expectDispatch(2, ComTeleGui(22, 122));
    //     m_Dispatcher().expectDispatch(3, ComTeleFld(33));
    //     m_Dispatcher().expectDispatch(4, ComTeleGui(44));
    //     IL::getDispatcher().dispatch(4, ComTeleGui(44));
    //     IL::getDispatcher().dispatch(3, ComTeleFld(33));
    //     IL::getDispatcher().dispatch(2, ComTeleGui(22, 122));
    //     IL::getDispatcher().dispatch(1, ComTeleFld(11, 111));
    //     CHECK_N_CLEAR()
    // }
}
