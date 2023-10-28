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

    TEST_GROUP_BASE(DSP_01, TestGroupDSP) {};

    //  test type: equivalence class test
    //  Dispatcher assign and label
    TEST(DSP_01, T01)
    {
        SETUP()
        //  assign element names equivalent to capacity
        mSUT.assign(genElementName(1, "TSW"), SUBSYS_TSW, 1);
        mSUT.assign(genElementName(2, "SIG"), SUBSYS_SIG, 2);
        mSUT.assign(genElementName(3, "LCR"), SUBSYS_LCR, 3);
        mSUT.assign(genElementName(4, "SEG"), SUBSYS_SEG, 4);
        mSUT.index();

        FldState fldState;
        GuiCmd guiCmd;
        Mem::zero(fldState);
        Mem::zero(guiCmd);

        // FldState
        STEP(1)
        genElementName(fldState.name, 1, "TSW");
        m_TSW_Hub().expectFromDsp(1, fldState);
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(2)
        genElementName(fldState.name, 2, "SIG");
        m_SIG_Hub().expectFromDsp(2, fldState);
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(3)
        //  LCR not part of current implementation
        genElementName(fldState.name, 3, "LCR");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        genElementName(fldState.name, 4, "SEG");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        genElementName(fldState.name, 2, "TSW");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        // GuiCmd
        STEP(6)
        genElementName(guiCmd.name, 1, "TSW");
        m_TSW_Hub().expectFromDsp(1, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(7)
        genElementName(guiCmd.name, 2, "SIG");
        m_SIG_Hub().expectFromDsp(2, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(8)
        //  LCR not part of current implementation
        genElementName(guiCmd.name, 3, "LCR");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(9)
        //  SEG not part of current implementation
        genElementName(guiCmd.name, 4, "SEG");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(10)
        //  not assigned
        genElementName(guiCmd.name, 2, "TSW");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher to field / GUI
    TEST(DSP_01, T02)
    {
        //  TODO
    }

    //  test type: coverage
    //  retrieve instance
    TEST(DSP_01, T03)
    {
        unmock();
        I_Dispatcher& inst = ddi::getDispatcher();
    }
}