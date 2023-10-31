//  ============================================================
//  test of module TSW
//  according to test plan tests_TSW.csv
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <TSW/TSW.h>

namespace test
{

    TEST_GROUP_BASE(TSW_01, TestGroupBase)
    {};

    //  test type: equivalence class test
    //  TSW transitions & reactions pt. 1
    TEST(TSW_01, T01)
    {
        SETUP()
        mockAll();
        const M_TSW_Hub& hub = m_TSW_Hub();
        const UINT32 id = 123;
        TSW SUT(id);

        STEP(1)
        hub.expectToGui(id, TSW_STATE_DEFECT);
        SUT.fromFld(TSW_STATE_DEFECT);
        CHECK_N_CLEAR()

        STEP(2)
        SUT.fromFld(TSW_STATE_DEFECT);
        CHECK_N_CLEAR()

        STEP(3)
        SUT.fromGui(TSW_GUI_GMD_WU);
        CHECK_N_CLEAR()

        STEP(4)
        hub.expectToGui(id, TSW_STATE_UNDEF);
        SUT.fromFld(TSW_STATE_UNDEF);
        CHECK_N_CLEAR()

        STEP(5)
        SUT.fromFld(TSW_STATE_UNDEF);
        CHECK_N_CLEAR()

        STEP(6)
        SUT.fromGui(TSW_GUI_GMD_WU);
        CHECK_N_CLEAR()

        STEP(7)
        hub.expectToGui(id, TSW_STATE_LEFT);
        SUT.fromFld(TSW_STATE_LEFT);
        CHECK_N_CLEAR()

        STEP(8)
        SUT.fromFld(TSW_STATE_LEFT);
        CHECK_N_CLEAR()

        STEP(9)
        hub.expectToFld(id, TSW_STATE_RIGHT);
        hub.expectToGui(id, TSW_STATE_WAIT_RIGHT);
        SUT.fromGui(TSW_GUI_GMD_WU);
        CHECK_N_CLEAR()

        STEP(10)
        SUT.fromGui(TSW_GUI_GMD_WU);
        CHECK_N_CLEAR()

        STEP(11)
        hub.expectToGui(id, TSW_STATE_RIGHT);
        SUT.fromFld(TSW_STATE_RIGHT);
        CHECK_N_CLEAR()

        STEP(12)
        SUT.fromFld(TSW_STATE_RIGHT);
        CHECK_N_CLEAR()

        STEP(13)
        hub.expectToFld(id, TSW_STATE_LEFT);
        hub.expectToGui(id, TSW_STATE_WAIT_LEFT);
        SUT.fromGui(TSW_GUI_GMD_WU);
        CHECK_N_CLEAR()

        STEP(14)
        SUT.fromGui(TSW_GUI_GMD_WU);
        CHECK_N_CLEAR()

        STEP(15)
        hub.expectToFld(id, TSW_STATE_RIGHT);
        hub.expectToGui(id, TSW_STATE_WAIT_RIGHT);
        SUT.fromGui(TSW_GUI_GMD_RIGHT);
        CHECK_N_CLEAR()

        STEP(16)
        SUT.fromGui(TSW_GUI_GMD_RIGHT);
        CHECK_N_CLEAR()

        STEP(17)
        hub.expectToFld(id, TSW_STATE_LEFT);
        hub.expectToGui(id, TSW_STATE_WAIT_LEFT);
        SUT.fromGui(TSW_GUI_GMD_LEFT);
        CHECK_N_CLEAR()

        STEP(18)
        SUT.fromGui(TSW_GUI_GMD_LEFT);
        CHECK_N_CLEAR()

        STEP(19)
        m_Log().expectLog(COMP_TSW, ERR_MATCH);
        SUT.fromFld(-1);
        CHECK_N_CLEAR()

        STEP(20)
        m_Log().expectLog(COMP_TSW, ERR_MATCH);
        SUT.fromGui(-1);
        CHECK_N_CLEAR()
   }
}