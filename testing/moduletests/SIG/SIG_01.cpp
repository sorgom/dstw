//  ============================================================
//  test of modules SIG_(X)
//  according to test plan tests_SIG_X.csv
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
        Ref<I_SIG> mSUT;
        inline TestGroupSIG():
            mId(123),
            mSIG_H(mId),
            mSUT(mSIG_H)
        {
            mockAll();
        }
        inline void setSUT(I_SIG& sig)
        {
            mSUT = sig;
        }

        void fromFldToGui(
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

        void fromGuiToFldToGui
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
    //  SIG_H from field
    TEST(SIG_01, T01)
    {
        STEP(1)
        fromFldToGui(SIG_STATE_H0, 10, SIG_STATE_H0, 0);
        STEP(2)
        fromFldToGui(SIG_STATE_H0, 20);

        STEP(3)
        fromFldToGui(SIG_STATE_H1, 10, SIG_STATE_H1, 0);
        STEP(4)
        fromFldToGui(SIG_STATE_H1, 20);

        STEP(5)
        fromFldToGui(SIG_STATE_UNDEF, 10, SIG_STATE_UNDEF, 0);
        STEP(6)
        fromFldToGui(SIG_STATE_UNDEF, 20);

        STEP(7)
        fromFldToGui(SIG_STATE_DEFECT, 10, SIG_STATE_DEFECT, 0);
        STEP(8)
        fromFldToGui(SIG_STATE_DEFECT, 20);

        STEP(9)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromFldToGui(SIG_STATE_N0, 10);
    }

    //  test type: equivalence class test
    //  SIG_H from GUI
    TEST(SIG_01, T02)
    {
        STEP(1)
        fromGuiToFldToGui(SIG_STATE_H0, 10, SIG_STATE_H0, 0, SIG_STATE_WAIT, 0);
        STEP(2)
        fromGuiToFldToGui(SIG_STATE_H0, 20);

        STEP(3)
        fromGuiToFldToGui(SIG_STATE_H1, 10, SIG_STATE_H1, 0, SIG_STATE_WAIT, 0);
        STEP(4)
        fromGuiToFldToGui(SIG_STATE_H1, 20);

        STEP(5)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_UNDEF, 10);
        STEP(6)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_DEFECT, 20);
        STEP(7)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_N0, 10);
    }

    //  test type: equivalence class test
    //  SIG_N from field
    TEST(SIG_01, T03)
    {
        SETUP()
        SIG_N sig(mId);
        setSUT(sig);

        STEP(1)
        fromFldToGui(SIG_STATE_N0, 10, SIG_STATE_N0, 10);
        STEP(2)
        fromFldToGui(SIG_STATE_N0, 20, SIG_STATE_N0, 20);
        STEP(3)
        fromFldToGui(SIG_STATE_N0, 20);

        STEP(4)
        fromFldToGui(SIG_STATE_N1, 10, SIG_STATE_N1, 10);
        STEP(5)
        fromFldToGui(SIG_STATE_N1, 20, SIG_STATE_N1, 20);
        STEP(6)
        fromFldToGui(SIG_STATE_N1, 20);

        STEP(7)
        fromFldToGui(SIG_STATE_UNDEF, 10, SIG_STATE_UNDEF, 0);
        STEP(8)
        fromFldToGui(SIG_STATE_UNDEF, 20);

        STEP(9)
        fromFldToGui(SIG_STATE_DEFECT, 10, SIG_STATE_DEFECT, 0);
        STEP(10)
        fromFldToGui(SIG_STATE_DEFECT, 20);

        STEP(11)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromFldToGui(SIG_STATE_H0, 10);
    }

    //  test type: equivalence class test
    //  SIG_N from GUI
    TEST(SIG_01, T04)
    {
        SETUP()
        SIG_N sig(mId);
        setSUT(sig);
        fromFldToGui(SIG_STATE_N1, 15, SIG_STATE_N1, 15);

        STEP(1)
        fromGuiToFldToGui(SIG_STATE_N0, 10, SIG_STATE_N0, 10, SIG_STATE_WAIT, 15);
        STEP(2)
        fromGuiToFldToGui(SIG_STATE_N0, 20, SIG_STATE_N0, 20, SIG_STATE_WAIT, 15);
        STEP(3)
        fromGuiToFldToGui(SIG_STATE_N0, 20);

        STEP(4)
        fromGuiToFldToGui(SIG_STATE_N1, 10, SIG_STATE_N1, 10, SIG_STATE_WAIT, 15);
        STEP(5)
        fromGuiToFldToGui(SIG_STATE_N1, 20, SIG_STATE_N1, 20, SIG_STATE_WAIT, 15);
        STEP(6)
        fromGuiToFldToGui(SIG_STATE_N1, 20);

        STEP(7)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_UNDEF, 10);
        STEP(8)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_DEFECT, 20);
        STEP(9)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_H1, 10);
    }

    //  test type: equivalence class test
    //  SIG_H_N from field
    TEST(SIG_01, T05)
    {
        SETUP()
        SIG_H_N sig(mId);
        setSUT(sig);

        STEP(1)
        fromFldToGui(SIG_STATE_H0_N0, 10, SIG_STATE_H0_N0, 10);
        STEP(2)
        fromFldToGui(SIG_STATE_H0_N0, 20, SIG_STATE_H0_N0, 20);
        STEP(3)
        fromFldToGui(SIG_STATE_H0_N0, 20);

        STEP(4)
        fromFldToGui(SIG_STATE_H0_N1, 10, SIG_STATE_H0_N1, 10);
        STEP(5)
        fromFldToGui(SIG_STATE_H0_N1, 20, SIG_STATE_H0_N1, 20);
        STEP(6)
        fromFldToGui(SIG_STATE_H0_N1, 20);

        STEP(7)
        fromFldToGui(SIG_STATE_H1_N0, 10, SIG_STATE_H1_N0, 10);
        STEP(8)
        fromFldToGui(SIG_STATE_H1_N0, 20, SIG_STATE_H1_N0, 20);
        STEP(9)
        fromFldToGui(SIG_STATE_H1_N0, 20);

        STEP(10)
        fromFldToGui(SIG_STATE_H1_N1, 10, SIG_STATE_H1_N1, 10);
        STEP(11)
        fromFldToGui(SIG_STATE_H1_N1, 20, SIG_STATE_H1_N1, 20);
        STEP(12)
        fromFldToGui(SIG_STATE_H1_N1, 20);

        STEP(13)
        fromFldToGui(SIG_STATE_UNDEF, 10, SIG_STATE_UNDEF, 0);
        STEP(14)
        fromFldToGui(SIG_STATE_UNDEF, 20);

        STEP(15)
        fromFldToGui(SIG_STATE_DEFECT, 10, SIG_STATE_DEFECT, 0);
        STEP(16)
        fromFldToGui(SIG_STATE_DEFECT, 20);

        STEP(17)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromFldToGui(SIG_STATE_H0, 10);
    }

    //  test type: equivalence class test
    //  SIG_H_N from GUI
    TEST(SIG_01, T06)
    {
        SETUP()
        SIG_H_N sig(mId);
        setSUT(sig);
        fromFldToGui(SIG_STATE_H1_N1, 15, SIG_STATE_H1_N1, 15);

        STEP(1)
        fromGuiToFldToGui(SIG_STATE_H0_N0, 10, SIG_STATE_H0_N0, 10, SIG_STATE_WAIT, 15);
        STEP(2)
        fromGuiToFldToGui(SIG_STATE_H0_N0, 20, SIG_STATE_H0_N0, 20, SIG_STATE_WAIT, 15);
        STEP(3)
        fromGuiToFldToGui(SIG_STATE_H0_N0, 20);

        STEP(4)
        fromGuiToFldToGui(SIG_STATE_H0_N1, 10, SIG_STATE_H0_N1, 10, SIG_STATE_WAIT, 15);
        STEP(5)
        fromGuiToFldToGui(SIG_STATE_H0_N1, 20, SIG_STATE_H0_N1, 20, SIG_STATE_WAIT, 15);
        STEP(6)
        fromGuiToFldToGui(SIG_STATE_H0_N1, 20);

        STEP(7)
        fromGuiToFldToGui(SIG_STATE_H1_N0, 10, SIG_STATE_H1_N0, 10, SIG_STATE_WAIT, 15);
        STEP(8)
        fromGuiToFldToGui(SIG_STATE_H1_N0, 20, SIG_STATE_H1_N0, 20, SIG_STATE_WAIT, 15);
        STEP(9)
        fromGuiToFldToGui(SIG_STATE_H1_N0, 20);

        STEP(10)
        fromGuiToFldToGui(SIG_STATE_H1_N1, 10, SIG_STATE_H1_N1, 10, SIG_STATE_WAIT, 15);
        STEP(11)
        fromGuiToFldToGui(SIG_STATE_H1_N1, 20, SIG_STATE_H1_N1, 20, SIG_STATE_WAIT, 15);
        STEP(12)
        fromGuiToFldToGui(SIG_STATE_H1_N1, 20);

        STEP(13)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_UNDEF, 10);
        STEP(14)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_DEFECT, 20);
        STEP(15)
        m_Logger().expectLog(COMP_SIG, ERR_MATCH);
        fromGuiToFldToGui(SIG_STATE_N0, 10);
    }
}
