//  ============================================================
//  test of modules SIG_(X)
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SIG/SIG_X.h>

namespace test
{
    class TestGroupSIG : public TestGroupBase
    {
    protected:
        const size_t mId;
        SIG_H mSIG_H;
        Ref<I_Elem> rSUT;
        inline TestGroupSIG():
            mId(123),
            mSIG_H(mId),
            rSUT(mSIG_H)
        {}
        inline void setSUT(I_Elem& sig)
        {
            rSUT.set(sig);
        }
        inline I_Elem& mSUT()
        {
            return rSUT.ref();
        }

        void FLD(
            UINT8 fldState,
            UINT8 fldSpeed,
            UINT8 stateToGui = NO_PARAM,
            UINT8 speedToGui = PARAM_UNDEF
        )
        {
            SUBSTEPS()
            STEP(1)
            const ComData dataGui{stateToGui, speedToGui};
            if (stateToGui != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
            }
            mSUT().fromFld(ComData{fldState, fldSpeed});
            CHECK_N_CLEAR()
            ENDSTEPS()
        }

        void CMD
        (
            UINT8 guiState,
            UINT8 guiSpeed,
            UINT8 stateToFld = NO_PARAM,
            UINT8 speedToFld = PARAM_UNDEF,
            UINT8 stateToGui = PARAM_UNDEF,
            UINT8 speedToGui = PARAM_UNDEF

        )
        {
            SUBSTEPS()
            STEP(1)
            const ComData dataFld{stateToFld, speedToFld};
            const ComData dataGui{stateToGui, speedToGui};
            if (stateToFld != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
                m_Dispatcher().expectToFld(mId, dataFld);
            }
            mSUT().fromGui(ComData{guiState, guiSpeed});
            CHECK_N_CLEAR()
            ENDSTEPS()
        }

        void FLD_H(
            UINT8 fldState,
            UINT8 stateToGui = NO_PARAM,
            UINT8 speed = PARAM_UNDEF
        )
        {
            SUBSTEPS()
            STEP(1)
            const ComData dataGui{stateToGui, PARAM_UNDEF};
            if (stateToGui != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
            }
            mSUT().fromFld(ComData{fldState, speed});
            CHECK_N_CLEAR()
            ENDSTEPS()
        }

        void CMD_H
        (
            UINT8 guiState,
            UINT8 stateToFld = NO_PARAM,
            UINT8 stateToGui = PARAM_UNDEF,
            UINT8 speed = PARAM_UNDEF
        )
        {
            SUBSTEPS()
            STEP(1)
            const ComData dataFld{stateToFld, PARAM_UNDEF};
            const ComData dataGui{stateToGui, PARAM_UNDEF};
            if (stateToFld != NO_PARAM)
            {
                m_Dispatcher().expectToGui(mId, dataGui);
                m_Dispatcher().expectToFld(mId, dataFld);
            }
            mSUT().fromGui(ComData{guiState, speed});
            CHECK_N_CLEAR()
            ENDSTEPS()
        }
    };

    TEST_GROUP_BASE(SIG_01, TestGroupSIG) {};

    //  test type: equivalence class test
    //  transitions SIG_H
    TEST(SIG_01, T01)
    {
        STEP(1)
        FLD_H(SIG_STATE_H0, SIG_STATE_H0);
        STEP(2)
        CMD_H(SIG_STATE_H0);
        STEP(3)
        FLD_H(SIG_STATE_H0);
        STEP(4)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(5)
        FLD_H(SIG_STATE_UNDEF);
        STEP(6)
        FLD_H(SIG_STATE_H1, SIG_STATE_H1);
        STEP(7)
        CMD_H(SIG_STATE_H1);
        STEP(8)
        FLD_H(SIG_STATE_H1);
        STEP(9)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(10)
        FLD_H(SIG_STATE_DEFECT, SIG_STATE_DEFECT);
        STEP(11)
        CMD_H(SIG_STATE_H0);
        STEP(12)
        CMD_H(SIG_STATE_H1);
        STEP(13)
        FLD_H(SIG_STATE_DEFECT);
        STEP(14)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(15)
        CMD_H(SIG_STATE_H0, SIG_STATE_H0, SIG_STATE_WAIT_H0);
        STEP(16)
        CMD_H(SIG_STATE_H0);
        STEP(17)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(18)
        CMD_H(SIG_STATE_H1, SIG_STATE_H1, SIG_STATE_WAIT_H1);
        STEP(19)
        CMD_H(SIG_STATE_H1);
        STEP(20)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(21)
        FLD_H(SIG_STATE_DEFECT, SIG_STATE_DEFECT);
        STEP(22)
        FLD_H(SIG_STATE_H0, SIG_STATE_H0);
        STEP(23)
        FLD_H(SIG_STATE_H1, SIG_STATE_H1);
        STEP(24)
        FLD_H(SIG_STATE_H0, SIG_STATE_H0);
        STEP(25)
        FLD_H(SIG_STATE_DEFECT, SIG_STATE_DEFECT);
        STEP(26)
        FLD_H(SIG_STATE_H1, SIG_STATE_H1);
        STEP(27)
        FLD_H(SIG_STATE_DEFECT, SIG_STATE_DEFECT);
        STEP(28)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(29)
        CMD_H(SIG_STATE_H0, SIG_STATE_H0, SIG_STATE_WAIT_H0);
        STEP(30)
        FLD_H(SIG_STATE_H0, SIG_STATE_H0);
        STEP(31)
        CMD_H(SIG_STATE_H1, SIG_STATE_H1, SIG_STATE_WAIT_H1);
        STEP(32)
        FLD_H(SIG_STATE_H0, SIG_STATE_H0);
        STEP(33)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(34)
        CMD_H(SIG_STATE_H0, SIG_STATE_H0, SIG_STATE_WAIT_H0);
        STEP(35)
        FLD_H(SIG_STATE_H1, SIG_STATE_H1);
        STEP(36)
        CMD_H(SIG_STATE_H0, SIG_STATE_H0, SIG_STATE_WAIT_H0);
        STEP(37)
        FLD_H(SIG_STATE_DEFECT, SIG_STATE_DEFECT);
        STEP(38)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(39)
        CMD_H(SIG_STATE_H1, SIG_STATE_H1, SIG_STATE_WAIT_H1);
        STEP(40)
        FLD_H(SIG_STATE_H1, SIG_STATE_H1);
        STEP(41)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(42)
        CMD_H(SIG_STATE_H1, SIG_STATE_H1, SIG_STATE_WAIT_H1);
        STEP(43)
        FLD_H(SIG_STATE_DEFECT, SIG_STATE_DEFECT);
        STEP(44)
        FLD_H(SIG_STATE_UNDEF, SIG_STATE_UNDEF);
        STEP(45)
        CMD_H(SIG_STATE_H1, SIG_STATE_H1, SIG_STATE_WAIT_H1);
        STEP(46)
        CMD_H(SIG_STATE_H0, SIG_STATE_H0, SIG_STATE_WAIT_H0);
        STEP(47)
        CMD_H(SIG_STATE_H1, SIG_STATE_H1, SIG_STATE_WAIT_H1);
    }

    //  test type: equivalence class test
    //  SIG_H unkown states and speed change
    TEST(SIG_01, T02)
    {
        STEP(1)
        m_Log().expectLog(COMP_SIG, RET_ERR_MATCH);
        CMD_H(PARAM_UNKNOWN);

        STEP(2)
        m_Log().expectLog(COMP_SIG, RET_ERR_MATCH);
        FLD_H(PARAM_UNKNOWN);

        STEP(3)
        CMD_H(SIG_STATE_H0, SIG_STATE_H0, SIG_STATE_WAIT_H0, 22);

        STEP(4)
        FLD_H(SIG_STATE_H0, SIG_STATE_H0, 20);

        STEP(5)
        mSUT().fromGui(ComData{SIG_STATE_H0, 30});
        CHECK_N_CLEAR()

        STEP(6)
        mSUT().fromFld(ComData{SIG_STATE_H0, 40});
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  transitions SIG_N
    TEST(SIG_01, T03)
    {
        SETUP()
        SIG_N sig(mId);
        setSUT(sig);

        STEP(1)
        FLD(SIG_STATE_N0, 0, SIG_STATE_N0, 0);
        STEP(2)
        CMD(SIG_STATE_N0, 0);
        STEP(3)
        FLD(SIG_STATE_N0, 0);
        STEP(4)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(5)
        FLD(SIG_STATE_UNDEF, 0);
        STEP(6)
        FLD(SIG_STATE_N1, 0, SIG_STATE_N1, 0);
        STEP(7)
        CMD(SIG_STATE_N1, 0);
        STEP(8)
        FLD(SIG_STATE_N1, 0);
        STEP(9)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(10)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(11)
        CMD(SIG_STATE_N0, 0);
        STEP(12)
        CMD(SIG_STATE_N1, 0);
        STEP(13)
        FLD(SIG_STATE_DEFECT, 0);
        STEP(14)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(15)
        CMD(SIG_STATE_N1, 0, SIG_STATE_N1, 0, SIG_STATE_WAIT_N1, 0);
        STEP(16)
        CMD(SIG_STATE_N1, 0);
        STEP(17)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(18)
        CMD(SIG_STATE_N0, 0, SIG_STATE_N0, 0, SIG_STATE_WAIT_N0, 0);
        STEP(19)
        CMD(SIG_STATE_N0, 0);
        STEP(20)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(21)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(22)
        FLD(SIG_STATE_N0, 0, SIG_STATE_N0, 0);
        STEP(23)
        FLD(SIG_STATE_N1, 0, SIG_STATE_N1, 0);
        STEP(24)
        FLD(SIG_STATE_N0, 0, SIG_STATE_N0, 0);
        STEP(25)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(26)
        FLD(SIG_STATE_N1, 0, SIG_STATE_N1, 0);
        STEP(27)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(28)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(29)
        CMD(SIG_STATE_N0, 0, SIG_STATE_N0, 0, SIG_STATE_WAIT_N0, 0);
        STEP(30)
        FLD(SIG_STATE_N0, 0, SIG_STATE_N0, 0);
        STEP(31)
        CMD(SIG_STATE_N1, 0, SIG_STATE_N1, 0, SIG_STATE_WAIT_N1, 0);
        STEP(32)
        FLD(SIG_STATE_N0, 0, SIG_STATE_N0, 0);
        STEP(33)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(34)
        CMD(SIG_STATE_N0, 0, SIG_STATE_N0, 0, SIG_STATE_WAIT_N0, 0);
        STEP(35)
        FLD(SIG_STATE_N1, 0, SIG_STATE_N1, 0);
        STEP(36)
        CMD(SIG_STATE_N0, 0, SIG_STATE_N0, 0, SIG_STATE_WAIT_N0, 0);
        STEP(37)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(38)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(39)
        CMD(SIG_STATE_N1, 0, SIG_STATE_N1, 0, SIG_STATE_WAIT_N1, 0);
        STEP(40)
        FLD(SIG_STATE_N1, 0, SIG_STATE_N1, 0);
        STEP(41)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(42)
        CMD(SIG_STATE_N1, 0, SIG_STATE_N1, 0, SIG_STATE_WAIT_N1, 0);
        STEP(43)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(44)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(45)
        CMD(SIG_STATE_N0, 0, SIG_STATE_N0, 0, SIG_STATE_WAIT_N0, 0);
        STEP(46)
        CMD(SIG_STATE_N1, 0, SIG_STATE_N1, 0, SIG_STATE_WAIT_N1, 0);
        STEP(47)
        CMD(SIG_STATE_N0, 0, SIG_STATE_N0, 0, SIG_STATE_WAIT_N0, 0);
    }

    //  test type: equivalence class test
    //  SIG_N unkown states and speed change
    TEST(SIG_01, T04)
    {
        SETUP()
        SIG_N sig(mId);
        setSUT(sig);

        STEP(1)
        m_Log().expectLog(COMP_SIG, RET_ERR_MATCH);
        CMD(PARAM_UNKNOWN, 0);

        STEP(2)
        m_Log().expectLog(COMP_SIG, RET_ERR_MATCH);
        FLD(PARAM_UNKNOWN, 0);

        STEP(3)
        CMD(SIG_STATE_N0, 10, SIG_STATE_N0, 10, SIG_STATE_WAIT_N0, 0);

        STEP(4)
        FLD(SIG_STATE_N0, 10, SIG_STATE_N0, 10);

        STEP(5)
        {
            const ComData dataFld{SIG_STATE_N0, 20};
            m_Dispatcher().expectToFld(mId, dataFld);
            CMD(SIG_STATE_N0, 20);
        }
        STEP(6)
        FLD(SIG_STATE_N0, 20, SIG_STATE_N0, 20);

        STEP(7)
        CMD(SIG_STATE_N0, 20);

        STEP(8)
        FLD(SIG_STATE_N0, 20);
    }

    //  test type: equivalence class test
    //  transitions SIG_H_N
    TEST(SIG_01, T05)
    {
        SETUP()
        SIG_H_N sig(mId);
        setSUT(sig);

        STEP(1)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(2)
        CMD(SIG_STATE_H0_N0, 0);
        STEP(3)
        CMD(SIG_STATE_H0_N1, 0);
        STEP(4)
        CMD(SIG_STATE_H1_N0, 0);
        STEP(5)
        CMD(SIG_STATE_H1_N1, 0);
        STEP(6)
        FLD(SIG_STATE_DEFECT, 0);
        STEP(7)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(8)
        FLD(SIG_STATE_UNDEF, 0);
        STEP(9)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(10)
        CMD(SIG_STATE_H0_N0, 0);
        STEP(11)
        FLD(SIG_STATE_H0_N0, 0);
        STEP(12)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(13)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(14)
        CMD(SIG_STATE_H0_N1, 0);
        STEP(15)
        FLD(SIG_STATE_H0_N1, 0);
        STEP(16)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(17)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(18)
        CMD(SIG_STATE_H1_N0, 0);
        STEP(19)
        FLD(SIG_STATE_H1_N0, 0);
        STEP(20)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(21)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(22)
        CMD(SIG_STATE_H1_N1, 0);
        STEP(23)
        FLD(SIG_STATE_H1_N1, 0);
        STEP(24)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(25)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(26)
        CMD(SIG_STATE_H0_N0, 0);
        STEP(27)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(28)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(29)
        CMD(SIG_STATE_H0_N1, 0);
        STEP(30)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(31)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(32)
        CMD(SIG_STATE_H1_N0, 0);
        STEP(33)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(34)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(35)
        CMD(SIG_STATE_H1_N1, 0);
        STEP(36)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(37)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(38)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(39)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(40)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(41)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(42)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(43)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(44)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(45)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(46)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(47)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(48)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(49)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(50)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(51)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(52)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(53)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(54)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(55)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(56)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(57)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(58)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(59)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(60)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(61)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(62)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(63)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(64)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(65)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(66)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(67)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(68)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(69)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(70)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(71)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(72)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(73)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(74)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(75)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(76)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(77)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(78)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(79)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(80)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(81)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(82)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(83)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(84)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(85)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(86)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(87)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(88)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(89)
        FLD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0);
        STEP(90)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(91)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(92)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(93)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(94)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(95)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(96)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(97)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(98)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(99)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(100)
        FLD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0);
        STEP(101)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(102)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(103)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(104)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(105)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(106)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(107)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(108)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(109)
        FLD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0);
        STEP(110)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(111)
        FLD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0);
        STEP(112)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(113)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(114)
        CMD(SIG_STATE_H0_N0, 0, SIG_STATE_H0_N0, 0, SIG_STATE_WAIT_H0_N0, 0);
        STEP(115)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(116)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(117)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
        STEP(118)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(119)
        CMD(SIG_STATE_H0_N1, 0, SIG_STATE_H0_N1, 0, SIG_STATE_WAIT_H0_N1, 0);
        STEP(120)
        CMD(SIG_STATE_H1_N1, 0, SIG_STATE_H1_N1, 0, SIG_STATE_WAIT_H1_N1, 0);
        STEP(121)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);
    }

    //  test type: equivalence class test
    //  SIG_H_N unkown states and speed change
    TEST(SIG_01, T06)
    {
        SETUP()
        SIG_H_N sig(mId);
        setSUT(sig);

        STEP(1)
        m_Log().expectLog(COMP_SIG, RET_ERR_MATCH);
        CMD(PARAM_UNKNOWN, 0);

        STEP(2)
        m_Log().expectLog(COMP_SIG, RET_ERR_MATCH);
        FLD(PARAM_UNKNOWN, 0);

        STEP(3)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);

        STEP(4)
        {
            const ComData dataFld{SIG_STATE_H1_N0, 10};
            m_Dispatcher().expectToFld(mId, dataFld);
            CMD(SIG_STATE_H1_N0, 10);
        }

        STEP(5)
        {
            const ComData dataGui{SIG_STATE_H1_N0, 10};
            m_Dispatcher().expectToGui(mId, dataGui);
            FLD(SIG_STATE_H1_N0, 10);
        }

        STEP(6)
        CMD(SIG_STATE_H1_N0, 10);

        STEP(7)
        FLD(SIG_STATE_H1_N0, 10);
    }
}
