//  ============================================================
//  test of modules LCR_(X)
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <LCR/LCR_X.h>

namespace test
{
    class TestGroupLCR : public TestGroupBase
    {
    protected:
        const size_t mId;
        LCR mLCR;
        Ref<I_Elem> rSUT;
        inline TestGroupLCR():
            mId(123),
            mLCR(mId),
            rSUT(mLCR)
        {}

        inline void setSUT(I_Elem& lcr)
        {
            rSUT.set(lcr);
        }

        inline I_Elem& mSUT()
        {
            return rSUT.ref();
        }

        void FLD(
            UINT8 fldState,
            UINT8 fldUbk,
            UINT8 stateToGui = NO_PARAM,
            UINT8 ubkToGui = PARAM_UNDEF
        )
        {
            SUBSTEPS()
            STEP(1)
            const ComData dataGui{stateToGui, ubkToGui};
            if (stateToGui != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
            }
            mSUT().fromFld(ComData{fldState, fldUbk});
            CHECK_N_CLEAR()
            ENDSTEPS()
        }

        void CMD
        (
            UINT8 guiState,
            UINT8 stateToFld = NO_PARAM,
            UINT8 stateToGui = PARAM_UNDEF,
            UINT8 ubkToGui = PARAM_UNDEF
        )
        {
            SUBSTEPS()
            STEP(1)
            const ComData dataFld{stateToFld, PARAM_UNDEF};
            const ComData dataGui{stateToGui, ubkToGui};
            if (stateToFld != NO_PARAM)
            {
                m_Dispatcher().expectToFld(mId, dataFld);
                m_Dispatcher().expectToGui(mId, dataGui);
            }
            mSUT().fromGui(ComData{guiState, PARAM_UNDEF});
            CHECK_N_CLEAR()
            ENDSTEPS()
        }

        //  all transitions of LCR state with constant UBK state
        void stateTransitions()
        {
            SUBSTEPS()
            STEP(1)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF, LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(2)
            CMD(LCR_STATE_CLOSED);
            STEP(3)
            CMD(LCR_STATE_OPEN);
            STEP(4)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(5)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(6)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(7)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(8)
            CMD(LCR_STATE_OPEN);
            STEP(9)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(10)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(11)
            FLD(LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF, LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(12)
            CMD(LCR_STATE_CLOSED);
            STEP(13)
            FLD(LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(14)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(15)
            CMD(LCR_STATE_OPEN, LCR_STATE_OPEN, LCR_STATE_WAIT_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(16)
            CMD(LCR_STATE_OPEN);
            STEP(17)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(18)
            CMD(LCR_STATE_CLOSED, LCR_STATE_CLOSED, LCR_STATE_WAIT_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(19)
            CMD(LCR_STATE_CLOSED);
            STEP(20)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(21)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(22)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF, LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(23)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(24)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF, LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(25)
            FLD(LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF, LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(26)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF, LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(27)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(28)
            FLD(LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF, LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(29)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(30)
            CMD(LCR_STATE_CLOSED, LCR_STATE_CLOSED, LCR_STATE_WAIT_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(31)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF, LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(32)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(33)
            CMD(LCR_STATE_OPEN, LCR_STATE_OPEN, LCR_STATE_WAIT_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(34)
            FLD(LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF, LCR_STATE_DEFECT, LCR_UBK_STATE_UNDEF);
            STEP(35)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(36)
            CMD(LCR_STATE_OPEN, LCR_STATE_OPEN, LCR_STATE_WAIT_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(37)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(38)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(39)
            CMD(LCR_STATE_OPEN, LCR_STATE_OPEN, LCR_STATE_WAIT_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(40)
            FLD(LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF, LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(41)
            CMD(LCR_STATE_OPEN, LCR_STATE_OPEN, LCR_STATE_WAIT_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(42)
            CMD(LCR_STATE_CLOSED, LCR_STATE_CLOSED, LCR_STATE_WAIT_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(43)
            FLD(LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF, LCR_STATE_OPEN, LCR_UBK_STATE_UNDEF);
            STEP(44)
            CMD(LCR_STATE_CLOSED, LCR_STATE_CLOSED, LCR_STATE_WAIT_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(45)
            FLD(LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF, LCR_STATE_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(46)
            FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
            STEP(47)
            CMD(LCR_STATE_CLOSED, LCR_STATE_CLOSED, LCR_STATE_WAIT_CLOSED, LCR_UBK_STATE_UNDEF);
            STEP(48)
            CMD(LCR_STATE_OPEN, LCR_STATE_OPEN, LCR_STATE_WAIT_OPEN, LCR_UBK_STATE_UNDEF);
            ENDSTEPS()
        }
    };

    TEST_GROUP_BASE(LCR_01, TestGroupLCR)
    {};

    //  test type: equivalence class test
    //  - state transitions LCR
    TEST(LCR_01, T01)
    {
        STEP(1)
        stateTransitions();
    }

    //  test type: equivalence class test
    //  LCR PARAM_UNKNOWN states / PARAM_UNKNOWN UBK
    TEST(LCR_01, T02)
    {
        STEP(1)
        m_Log().expectLog(COMP_LCR, RET_ERR_MATCH);
        FLD(PARAM_UNKNOWN, LCR_UBK_STATE_UNDEF);

        STEP(2)
        m_Log().expectLog(COMP_LCR, RET_ERR_MATCH);
        CMD(PARAM_UNKNOWN);

        STEP(3)
        FLD(LCR_STATE_UNDEF, PARAM_UNKNOWN);
    }

    //  test type: equivalence class test
    //  state transitions LCR_UBK
    TEST(LCR_01, T03)
    {
        SETUP()
        LCR_UBK lcr(mId);
        setSUT(lcr);

        STEP(1)
        stateTransitions();
    }

    //  test type: equivalence class test
    //  UBK transitions LCR_UBK with constant LCR state
    TEST(LCR_01, T04)
    {
        SETUP()
        LCR_UBK lcr(mId);
        setSUT(lcr);

        STEP(1)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT, LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT);
        STEP(2)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT);
        STEP(3)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
        STEP(4)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
        STEP(5)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED, LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED);
        STEP(6)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED);
        STEP(7)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
        STEP(8)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_FREE, LCR_STATE_UNDEF, LCR_UBK_STATE_FREE);
        STEP(9)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_FREE);
        STEP(10)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF, LCR_STATE_UNDEF, LCR_UBK_STATE_UNDEF);
        STEP(11)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED, LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED);
        STEP(12)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT, LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT);
        STEP(13)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED, LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED);
        STEP(14)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT, LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT);
        STEP(15)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_FREE, LCR_STATE_UNDEF, LCR_UBK_STATE_FREE);
        STEP(16)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT, LCR_STATE_UNDEF, LCR_UBK_STATE_DEFECT);
        STEP(17)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED, LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED);
        STEP(18)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_FREE, LCR_STATE_UNDEF, LCR_UBK_STATE_FREE);
        STEP(19)
        FLD(LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED, LCR_STATE_UNDEF, LCR_UBK_STATE_OCCUPIED);
    }

    //  test type: equivalence class test
    //  LCR UBK PARAM_UNKNOWN states / PARAM_UNKNOWN UBK
    TEST(LCR_01, T05)
    {
        SETUP()
        LCR_UBK lcr(mId);
        setSUT(lcr);

        STEP(1)
        m_Log().expectLog(COMP_LCR, RET_ERR_MATCH);
        FLD(PARAM_UNKNOWN, LCR_UBK_STATE_UNDEF);

        STEP(2)
        m_Log().expectLog(COMP_LCR, RET_ERR_MATCH);
        CMD(PARAM_UNKNOWN);

        STEP(3)
        m_Log().expectLog(COMP_LCR, RET_ERR_MATCH);
        FLD(LCR_STATE_UNDEF, PARAM_UNKNOWN);

        STEP(4)
        m_Log().expectLog(COMP_LCR, RET_ERR_MATCH);
        FLD(PARAM_UNKNOWN, PARAM_UNKNOWN);
    }
}
