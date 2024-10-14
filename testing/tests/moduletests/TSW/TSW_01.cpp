//  ============================================================
//  test of module TSW
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <TSW/TSW.h>

namespace test
{

    class TestGroupTSW : public TestGroupBase
    {
    protected:
        const size_t mId;
        TSW mSUT;

        inline TestGroupTSW():
            mId(123),
            mSUT(mId)
        {}
        void FLD(const UINT8 fldState, const UINT8 expStateGui = NO_PARAM)
        {
            const ComData dataGui{expStateGui, PARAM_UNDEF};
            if (expStateGui != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
            }
            mSUT.fromFld(ComData{fldState});
            CHECK_N_CLEAR()
        }

        void CMD(const UINT8 guiCmd, const UINT8 expCmdField = NO_PARAM, const UINT8 expStateGui = PARAM_UNDEF)
        {
            const ComData dataGui{expStateGui, PARAM_UNDEF};
            const ComData dataFld{expCmdField, PARAM_UNDEF};
            if (expCmdField != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
                m_Dispatcher().expectToFld(mId, dataFld);
            }
            mSUT.fromGui(ComData{guiCmd});
            CHECK_N_CLEAR()
        }
    };

    TEST_GROUP_BASE(TSW_01, TestGroupTSW) {};

    //  test type: equivalence class test
    //  transitions TSW
    TEST(TSW_01, T01)
    {
        STEP(1)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(2)
        CMD(TSW_CMD_LEFT);
        STEP(3)
        FLD(TSW_STATE_LEFT);
        STEP(4)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(5)
        CMD(TSW_CMD_WU);
        STEP(6)
        FLD(TSW_STATE_UNDEF);
        STEP(7)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(8)
        CMD(TSW_CMD_RIGHT);
        STEP(9)
        FLD(TSW_STATE_RIGHT);
        STEP(10)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(11)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(12)
        CMD(TSW_CMD_LEFT);
        STEP(13)
        CMD(TSW_CMD_RIGHT);
        STEP(14)
        CMD(TSW_CMD_WU);
        STEP(15)
        FLD(TSW_STATE_DEFECT);
        STEP(16)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(17)
        CMD(TSW_CMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(18)
        CMD(TSW_CMD_LEFT);
        STEP(19)
        CMD(TSW_CMD_WU);
        STEP(20)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(21)
        CMD(TSW_CMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(22)
        CMD(TSW_CMD_RIGHT);
        STEP(23)
        CMD(TSW_CMD_WU);
        STEP(24)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(25)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(26)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(27)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(28)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(29)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(30)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(31)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(32)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(33)
        CMD(TSW_CMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(34)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(35)
        CMD(TSW_CMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(36)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(37)
        CMD(TSW_CMD_WU, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(38)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(39)
        CMD(TSW_CMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(40)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(41)
        CMD(TSW_CMD_WU, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(42)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(43)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(44)
        CMD(TSW_CMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(45)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(46)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(47)
        CMD(TSW_CMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(48)
        CMD(TSW_CMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(49)
        CMD(TSW_CMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
    }

    //  test type: equivalence class test
    //  illegal values from GUI and field
    TEST(TSW_01, T02)
    {
        STEP(1)
        m_Log().expectLog(COMP_TSW, RET_ERR_MATCH);
        CMD(PARAM_UNKNOWN);

        STEP(2)
        m_Log().expectLog(COMP_TSW, RET_ERR_MATCH);
        FLD(PARAM_UNKNOWN);
    }
}
