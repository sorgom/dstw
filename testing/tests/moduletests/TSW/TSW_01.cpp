//  ============================================================
//  test of module TSW
//  according to test plan TSW_states.md
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

        inline TestGroupTSW():
            mId(123),
            mSUT(mId)
        {}
        void FLD(const INT32 fldState, const INT32 expStateGui = -1)
        {
            if (expStateGui > -1)
            {
                m_TSW_Hub().expectToGui(mId, expStateGui);
            }
            mSUT.fromFld(fldState);
            CHECK_N_CLEAR()
        }

        void CMD(const INT32 guiCmd, const INT32 expCmdField = -1, const INT32 expStateGui = 0)
        {
            if (expCmdField > -1)
            {
                m_TSW_Hub().expectToFld(mId, expCmdField);
                m_TSW_Hub().expectToGui(mId, expStateGui);
            }
            mSUT.fromGui(guiCmd);
            CHECK_N_CLEAR()
        }
    };
    
    TEST_GROUP_BASE(TSW_01, TestGroupTSW) {};

    //  test type: equivalence class test
    //  all TSW transitions acc. to TSW_states.md
    TEST(TSW_01, T01)
    {
        STEP(1)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(2)
        CMD(TSW_GUI_GMD_RIGHT);
        STEP(3)
        CMD(TSW_GUI_GMD_WU);

        STEP(4)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(5)
        CMD(TSW_GUI_GMD_LEFT);
        STEP(6)
        CMD(TSW_GUI_GMD_RIGHT);
        STEP(7)
        CMD(TSW_GUI_GMD_WU);
        STEP(8)
        FLD(TSW_STATE_DEFECT);

        STEP(9)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(10)
        CMD(TSW_GUI_GMD_WU);
        STEP(11)
        FLD(TSW_STATE_UNDEF);

        STEP(12)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(13)
        CMD(TSW_GUI_GMD_LEFT);
        STEP(14)
        CMD(TSW_GUI_GMD_WU);

        STEP(15)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        
        STEP(16)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(17)
        CMD(TSW_GUI_GMD_LEFT);
        STEP(18)
        FLD(TSW_STATE_LEFT);

        STEP(19)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(20)
        CMD(TSW_GUI_GMD_RIGHT);
        STEP(21)
        FLD(TSW_STATE_RIGHT);

        STEP(22)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(23)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(24)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(25)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(26)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(27)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(28)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(29)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(30)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(31)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(32)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(33)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(34)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(35)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(36)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(37)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(38)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(39)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(40)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(41)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(42)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(43)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(44)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(45)
        CMD(TSW_GUI_GMD_WU, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(46)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(47)
        CMD(TSW_GUI_GMD_WU, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(48)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
    }

    //  test type: equivalence class test
    //  illegal values from GUI and field
    TEST(TSW_01, T02)
    {
        STEP(1)
        m_Log().expectLog(MOD_TSW, ERR_MATCH);
        CMD(1000);

        STEP(2)
        m_Log().expectLog(MOD_TSW, ERR_MATCH);
        FLD(1000);
    }
}
