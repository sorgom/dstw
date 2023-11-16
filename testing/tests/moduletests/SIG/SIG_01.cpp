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
        const UINT32 mId;
        SIG_H mSIG_H;
        Ref<I_SIG> rSUT;
        inline TestGroupSIG():
            mId(123),
            mSIG_H(mId),
            rSUT(mSIG_H)
        {}
        inline void setSUT(I_SIG& sig)
        {
            rSUT.set(sig);
        }
        inline I_SIG& mSUT()
        {
            return rSUT.ref();
        }

        void FLD(
            INT32 fldState,
            INT32 fldSpeed,
            INT32 stateToGui = -1,
            INT32 speedToGui = 0
        )
        {
            SUBSTEPS()
            STEP(1)
            if (stateToGui >= 0)
            {
                m_SIG_Hub().expectToGui(mId, stateToGui, speedToGui);
            }
            mSUT().fromFld(fldState, fldSpeed);
            CHECK_N_CLEAR()
            ENDSTEPS()
        }

        void CMD
        (
            INT32 guiState,
            INT32 guiSpeed,
            INT32 stateToFld = -1,
            INT32 speedToFld = 0,
            INT32 stateToGui = 0,
            INT32 speedToGui = 0

        )
        {
            SUBSTEPS()
            STEP(1)
            if (stateToFld >= 0)
            {
                m_SIG_Hub().expectToFld(mId, stateToFld, speedToFld);
                m_SIG_Hub().expectToGui(mId, stateToGui, speedToGui);
            }
            mSUT().fromGui(guiState, guiSpeed);
            CHECK_N_CLEAR()
            ENDSTEPS()
        }
    };

    TEST_GROUP_BASE(SIG_01, TestGroupSIG)
    {};

    //  test type: equivalence class test
    //  transitions SIG_H
    TEST(SIG_01, T01)
    {
        STEP(1)
        FLD(SIG_STATE_H0, 0, SIG_STATE_H0, 0);
        STEP(2)
        CMD(SIG_STATE_H0, 0);
        STEP(3)
        FLD(SIG_STATE_H0, 0);
        STEP(4)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(5)
        FLD(SIG_STATE_UNDEF, 0);
        STEP(6)
        FLD(SIG_STATE_H1, 0, SIG_STATE_H1, 0);
        STEP(7)
        CMD(SIG_STATE_H1, 0);
        STEP(8)
        FLD(SIG_STATE_H1, 0);
        STEP(9)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(10)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(11)
        CMD(SIG_STATE_H0, 0);
        STEP(12)
        CMD(SIG_STATE_H1, 0);
        STEP(13)
        FLD(SIG_STATE_DEFECT, 0);
        STEP(14)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(15)
        CMD(SIG_STATE_H0, 0, SIG_STATE_H0, 0, SIG_STATE_WAIT_H0, 0);
        STEP(16)
        CMD(SIG_STATE_H0, 0);
        STEP(17)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(18)
        CMD(SIG_STATE_H1, 0, SIG_STATE_H1, 0, SIG_STATE_WAIT_H1, 0);
        STEP(19)
        CMD(SIG_STATE_H1, 0);
        STEP(20)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(21)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(22)
        FLD(SIG_STATE_H0, 0, SIG_STATE_H0, 0);
        STEP(23)
        FLD(SIG_STATE_H1, 0, SIG_STATE_H1, 0);
        STEP(24)
        FLD(SIG_STATE_H0, 0, SIG_STATE_H0, 0);
        STEP(25)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(26)
        FLD(SIG_STATE_H1, 0, SIG_STATE_H1, 0);
        STEP(27)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(28)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(29)
        CMD(SIG_STATE_H0, 0, SIG_STATE_H0, 0, SIG_STATE_WAIT_H0, 0);
        STEP(30)
        FLD(SIG_STATE_H0, 0, SIG_STATE_H0, 0);
        STEP(31)
        CMD(SIG_STATE_H1, 0, SIG_STATE_H1, 0, SIG_STATE_WAIT_H1, 0);
        STEP(32)
        FLD(SIG_STATE_H0, 0, SIG_STATE_H0, 0);
        STEP(33)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(34)
        CMD(SIG_STATE_H0, 0, SIG_STATE_H0, 0, SIG_STATE_WAIT_H0, 0);
        STEP(35)
        FLD(SIG_STATE_H1, 0, SIG_STATE_H1, 0);
        STEP(36)
        CMD(SIG_STATE_H0, 0, SIG_STATE_H0, 0, SIG_STATE_WAIT_H0, 0);
        STEP(37)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(38)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(39)
        CMD(SIG_STATE_H1, 0, SIG_STATE_H1, 0, SIG_STATE_WAIT_H1, 0);
        STEP(40)
        FLD(SIG_STATE_H1, 0, SIG_STATE_H1, 0);
        STEP(41)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(42)
        CMD(SIG_STATE_H1, 0, SIG_STATE_H1, 0, SIG_STATE_WAIT_H1, 0);
        STEP(43)
        FLD(SIG_STATE_DEFECT, 0, SIG_STATE_DEFECT, 0);
        STEP(44)
        FLD(SIG_STATE_UNDEF, 0, SIG_STATE_UNDEF, 0);
        STEP(45)
        CMD(SIG_STATE_H1, 0, SIG_STATE_H1, 0, SIG_STATE_WAIT_H1, 0);
        STEP(46)
        CMD(SIG_STATE_H0, 0, SIG_STATE_H0, 0, SIG_STATE_WAIT_H0, 0);
        STEP(47)
        CMD(SIG_STATE_H1, 0, SIG_STATE_H1, 0, SIG_STATE_WAIT_H1, 0);
    }

    //  test type: equivalence class test
    //  SIG_H unkown states and speed change
    TEST(SIG_01, T02)
    {
        STEP(1)
        m_Log().expectLog(MOD_SIG, ERR_MATCH);
        CMD(10000, 0);

        STEP(2)
        m_Log().expectLog(MOD_SIG, ERR_MATCH);
        FLD(10000, 0);

        STEP(3)
        CMD(SIG_STATE_H0, 10, SIG_STATE_H0, 0, SIG_STATE_WAIT_H0, 0);

        STEP(4)
        FLD(SIG_STATE_H0, 20, SIG_STATE_H0, 0);

        STEP(5)
        CMD(SIG_STATE_H0, 30);

        STEP(6)
        FLD(SIG_STATE_H0, 40);
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
        m_Log().expectLog(MOD_SIG, ERR_MATCH);
        CMD(10000, 0);

        STEP(2)
        m_Log().expectLog(MOD_SIG, ERR_MATCH);
        FLD(10000, 0);

        STEP(3)
        CMD(SIG_STATE_N0, 10, SIG_STATE_N0, 10, SIG_STATE_WAIT_N0, 0);

        STEP(4)
        FLD(SIG_STATE_N0, 10, SIG_STATE_N0, 10);

        STEP(5)
        m_SIG_Hub().expectToFld(mId, SIG_STATE_N0, 20);
        CMD(SIG_STATE_N0, 20);

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
        m_Log().expectLog(MOD_SIG, ERR_MATCH);
        CMD(10000, 0);

        STEP(2)
        m_Log().expectLog(MOD_SIG, ERR_MATCH);
        FLD(10000, 0);

        STEP(3)
        CMD(SIG_STATE_H1_N0, 0, SIG_STATE_H1_N0, 0, SIG_STATE_WAIT_H1_N0, 0);

        STEP(4)
        m_SIG_Hub().expectToFld(mId, SIG_STATE_H1_N0, 10);
        CMD(SIG_STATE_H1_N0, 10);

        STEP(5)
        m_SIG_Hub().expectToGui(mId, SIG_STATE_H1_N0, 10);
        FLD(SIG_STATE_H1_N0, 10);

        STEP(6)
        CMD(SIG_STATE_H1_N0, 10);

        STEP(7)
        FLD(SIG_STATE_H1_N0, 10);
    }
}
