//  ============================================================
//  test of module TSW
//  according to test plan tests_TSW.csv
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <TSW/TSW.h>

namespace test
{

    class TestGroupTSW : public TestGroupBase
    {
    protected:
        const UINT32 mId;
        TSW mSUT;
        const M_TSW_Hub& mHub;

        inline TestGroupTSW():
            mId(123),
            mSUT(mId),
            mHub(m_TSW_Hub())
        {}
        void FLD(const INT32 fldState, const INT32 stateGui = -1)
        {
            if (stateGui > -1)
            {
                mHub.expectToGui(mId, stateGui);
            }
            mSUT.fromFld(fldState);
            CHECK_N_CLEAR()
        }

        void CMD(const INT32 guiCmd, const INT32 cmdField = -1, const INT32 stateGui = 0)
        {
            if (cmdField > -1)
            {
                mHub.expectToFld(mId, cmdField);
                mHub.expectToGui(mId, stateGui);
            }
            mSUT.fromGui(guiCmd);
            CHECK_N_CLEAR()
        }
    };
    
    TEST_GROUP_BASE(TSW_01, TestGroupTSW) {};

    //  test type: equivalence class test
    //  TSW transitions & reactions pt. 1
    TEST(TSW_01, T01)
    {
        STEP(1)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(1)
        CMD(TSW_GUI_GMD_RIGHT);

        STEP(1)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);

    }
    // //  test type: equivalence class test
    // //  TSW transitions & reactions pt. 1
    // TEST(TSW_01, T01)
    // {
    //     SETUP()
    //     const M_TSW_Hub& hub = m_TSW_Hub();
    //     const UINT32 id = 123;
    //     TSW SUT(id);

    //     STEP(1)
    //     hub.expectToGui(id, TSW_STATE_DEFECT);
    //     SUT.fromFld(TSW_STATE_DEFECT);
    //     CHECK_N_CLEAR()

    //     STEP(2)
    //     SUT.fromFld(TSW_STATE_DEFECT);
    //     CHECK_N_CLEAR()

    //     STEP(3)
    //     SUT.fromGui(TSW_GUI_GMD_WU);
    //     CHECK_N_CLEAR()

    //     STEP(4)
    //     hub.expectToGui(id, TSW_STATE_UNDEF);
    //     SUT.fromFld(TSW_STATE_UNDEF);
    //     CHECK_N_CLEAR()

    //     STEP(5)
    //     SUT.fromFld(TSW_STATE_UNDEF);
    //     CHECK_N_CLEAR()

    //     STEP(6)
    //     SUT.fromGui(TSW_GUI_GMD_WU);
    //     CHECK_N_CLEAR()

    //     STEP(7)
    //     hub.expectToGui(id, TSW_STATE_LEFT);
    //     SUT.fromFld(TSW_STATE_LEFT);
    //     CHECK_N_CLEAR()

    //     STEP(8)
    //     SUT.fromGui(TSW_GUI_GMD_LEFT);
    //     CHECK_N_CLEAR()

    //     STEP(9)
    //     SUT.fromFld(TSW_STATE_LEFT);
    //     CHECK_N_CLEAR()

    //     STEP(10)
    //     hub.expectToFld(id, TSW_STATE_RIGHT);
    //     hub.expectToGui(id, TSW_STATE_WAIT_RIGHT);
    //     SUT.fromGui(TSW_GUI_GMD_WU);
    //     CHECK_N_CLEAR()

    //     STEP(11)
    //     SUT.fromGui(TSW_GUI_GMD_WU);
    //     CHECK_N_CLEAR()

    //     STEP(12)
    //     hub.expectToGui(id, TSW_STATE_RIGHT);
    //     SUT.fromFld(TSW_STATE_RIGHT);
    //     CHECK_N_CLEAR()

    //     STEP(13)
    //     SUT.fromGui(TSW_GUI_GMD_RIGHT);
    //     CHECK_N_CLEAR()

    //     STEP(14)
    //     SUT.fromFld(TSW_STATE_RIGHT);
    //     CHECK_N_CLEAR()

    //     STEP(15)
    //     hub.expectToFld(id, TSW_STATE_LEFT);
    //     hub.expectToGui(id, TSW_STATE_WAIT_LEFT);
    //     SUT.fromGui(TSW_GUI_GMD_WU);
    //     CHECK_N_CLEAR()

    //     STEP(16)
    //     SUT.fromGui(TSW_GUI_GMD_WU);
    //     CHECK_N_CLEAR()

    //     STEP(17)
    //     hub.expectToFld(id, TSW_STATE_RIGHT);
    //     hub.expectToGui(id, TSW_STATE_WAIT_RIGHT);
    //     SUT.fromGui(TSW_GUI_GMD_RIGHT);
    //     CHECK_N_CLEAR()

    //     STEP(18)
    //     SUT.fromGui(TSW_GUI_GMD_RIGHT);
    //     CHECK_N_CLEAR()

    //     STEP(19)
    //     hub.expectToFld(id, TSW_STATE_LEFT);
    //     hub.expectToGui(id, TSW_STATE_WAIT_LEFT);
    //     SUT.fromGui(TSW_GUI_GMD_LEFT);
    //     CHECK_N_CLEAR()

    //     STEP(20)
    //     SUT.fromGui(TSW_GUI_GMD_LEFT);
    //     CHECK_N_CLEAR()

    //     STEP(21)
    //     m_Log().expectLog(MOD_TSW, ERR_MATCH);
    //     SUT.fromFld(-1);
    //     CHECK_N_CLEAR()

    //     STEP(22)
    //     m_Log().expectLog(MOD_TSW, ERR_MATCH);
    //     SUT.fromGui(-1);
    //     CHECK_N_CLEAR()
    // }
}
