//  ============================================================
//  test of module Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <system/Dispatcher.h>

namespace test
{
    class TestGroupDSP : public TestGroupBase
    {
    protected:
        Dispatcher mSUT;
        ElementName mName;
        inline TestGroupDSP()
        {
            mockAll();
            mSUT.reset();
        }
    };

    TEST_GROUP_BASE(DSP_01, TestGroupDSP)
    {};

    //  test type: equivalence class test
    //  Dispatcher assign and label
    TEST(DSP_01, T01)
    {
        INT32 ret = false;
        bool ok = false;
        STEP(1)
        //  assign element names equivalent to capacity
        SUBSTEPS()
        for (UINT32 pos = 0; pos < CAPACITY_ELEMENTS; ++pos)
        {
            LSTEP(pos)
            ret = mSUT.assign(genElementName(CAPACITY_ELEMENTS - pos, "TSW"), SUBSYS_TSW, pos);
            CHECK_N_CLEAR()
            L_CHECK_EQUAL(pos, ret)
        }
        ENDSTEPS()

        STEP(2)
        //  assign one more
        ret = mSUT.assign(genElementName(0, "SIG"), SUBSYS_SIG, 0);
        L_CHECK_EQUAL(-1, ret)
        
        STEP(3)
        mSUT.index();
        
        STEP(4)
        //  label inside range
        ok = mSUT.label(mName, CAPACITY_ELEMENTS - 1);
        L_CHECK_TRUE(ok);
        L_CHECK_ELEMENT_NAME(genElementName(1, "TSW"), mName)
        
        STEP(5)
        //  label outside range
        ok = mSUT.label(mName, CAPACITY_ELEMENTS);
        L_CHECK_FALSE(ok);
    }

    //  test type: equivalence class test
    //  Dispatcher assign and label
    TEST(DSP_01, T02)
    {
        SETUP()
        //  assign element names equivalent to capacity
        mSUT.assign(genElementName(1, "TSW"), SUBSYS_TSW, 1);
        mSUT.assign(genElementName(2, "SIG"), SUBSYS_SIG, 2);
        mSUT.assign(genElementName(3, "LCR"), SUBSYS_LCR, 3);
        mSUT.assign(genElementName(4, "SEG"), SUBSYS_SEG, 4);

        mSUT.index();

        INT32 ret = false;
        bool ok = false;
        FldState fldState;
        GuiCmd guiCmd;
        Mem::zero(fldState);
        Mem::zero(guiCmd);

        // FldState
        STEP(1)
        genElementName(fldState.name, 1, "TSW");
        m_TSW_Hub().expectFromFld(fldState, 1);
        ok = mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(2)
        genElementName(fldState.name, 2, "SIG");
        m_SIG_Hub().expectFromFld(fldState, 2);
        ok = mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(3)
        genElementName(fldState.name, 3, "LCR");
        //  LCR not part of current implementation
        ok = mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(4)
        genElementName(fldState.name, 4, "SEG");
        //  SEG not part of current implementation
        ok = mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(5)
        genElementName(fldState.name, 2, "TSW");
        ok = mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok);

        // GuiCmd
        STEP(6)
        genElementName(guiCmd.name, 1, "TSW");
        m_TSW_Hub().expectFromGui(guiCmd, 1);
        ok = mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(7)
        genElementName(guiCmd.name, 2, "SIG");
        m_SIG_Hub().expectFromGui(guiCmd, 2);
        ok = mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(8)
        genElementName(guiCmd.name, 3, "LCR");
        //  LCR not part of current implementation
        ok = mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(9)
        genElementName(guiCmd.name, 4, "SEG");
        //  SEG not part of current implementation
        ok = mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok);

        STEP(10)
        genElementName(guiCmd.name, 2, "TSW");
        ok = mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok);
    }

    //  test type: coverage
    //  retrieve instance
    TEST(DSP_01, T03)
    {
        unmock();
        I_Dispatcher& inst = ddi::getDispatcher();
    }
}