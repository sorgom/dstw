//  ============================================================
//  test of mocks
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

namespace test
{
    TEST_GROUP_BASE(DT_01, TestGroupBase) {};

    //  call mock explicitly
    TEST(DT_01, T01)
    {
        STEP(1)
        m_Dispatcher().expectDispatch(1, ComTeleFld(11, 111));
        m_Dispatcher().expectDispatch(2, ComTeleGui(22, 122));
        m_Dispatcher().expectDispatch(3, ComTeleFld(33));
        m_Dispatcher().expectDispatch(4, ComTeleGui(44));
        m_Dispatcher().dispatch(4, ComTeleGui(44));
        m_Dispatcher().dispatch(3, ComTeleFld(33));
        m_Dispatcher().dispatch(2, ComTeleGui(22, 122));
        m_Dispatcher().dispatch(1, ComTeleFld(11, 111));
        CHECK_N_CLEAR()
    }
    //  call mock from IL
    TEST(DT_01, T02)
    {
        STEP(1)
        m_Dispatcher().expectDispatch(1, ComTeleFld(11, 111));
        m_Dispatcher().expectDispatch(2, ComTeleGui(22, 122));
        m_Dispatcher().expectDispatch(3, ComTeleFld(33));
        m_Dispatcher().expectDispatch(4, ComTeleGui(44));
        IL::getDispatcher().dispatch(4, ComTeleGui(44));
        IL::getDispatcher().dispatch(3, ComTeleFld(33));
        IL::getDispatcher().dispatch(2, ComTeleGui(22, 122));
        IL::getDispatcher().dispatch(1, ComTeleFld(11, 111));
        CHECK_N_CLEAR()
    }
}
