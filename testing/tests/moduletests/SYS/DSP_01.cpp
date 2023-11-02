//  ============================================================
//  test of module Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Dispatcher.h>

namespace test
{
    class TestGroupDSP : public TestGroupBase
    {
    protected:
        Dispatcher mSUT;
        inline TestGroupDSP()
        {
            mockAll();
            mSUT.reset();
            mSUT.assign(genElementName(1, "TSW"), SUBSYS_TSW, 1);
            mSUT.assign(genElementName(2, "SIG"), SUBSYS_SIG, 2);
            mSUT.assign(genElementName(3, "LCR"), SUBSYS_LCR, 3);
            mSUT.assign(genElementName(4, "SEG"), SUBSYS_SEG, 4);
            mSUT.index();
        }
    };

    TEST_GROUP_BASE(DSP_01, TestGroupDSP) {};

    //  test type: equivalence class test
    //  Dispatcher dispatch state telegrams from field
    TEST(DSP_01, T01)
    {
        SETUP()
        FldState fldState;
        Mem::zero(fldState);

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
        m_Log().expectLog(COMP_DISPATCHER, ERR_MATCH);
        genElementName(fldState.name, 2, "TSW");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
    }
    //  test type: equivalence class test
    //  Dispatcher dispatch cmd telegrams from GUI
    TEST(DSP_01, T02)
    {
        SETUP()
        GuiCmd guiCmd;
        Mem::zero(guiCmd);

        STEP(1)
        genElementName(guiCmd.name, 1, "TSW");
        m_TSW_Hub().expectFromDsp(1, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(2)
        genElementName(guiCmd.name, 2, "SIG");
        m_SIG_Hub().expectFromDsp(2, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(3)
        //  LCR not part of current implementation
        genElementName(guiCmd.name, 3, "LCR");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        genElementName(guiCmd.name, 4, "SEG");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_DISPATCHER, ERR_MATCH);
        genElementName(guiCmd.name, 2, "TSW");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch cmds to field
    TEST(DSP_01, T03)
    {
        SETUP()
        CmdFld cmdIn;
        CmdFld cmdExp;
        Mem::zero(cmdIn);
        Mem::zero(cmdExp);

        STEP(1)
        genElementName(cmdExp.name, 1, "TSW");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(0, cmdIn);
        CHECK_N_CLEAR()

        STEP(2)
        genElementName(cmdExp.name, 2, "SIG");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(1, cmdIn);
        CHECK_N_CLEAR()

        STEP(3)
        genElementName(cmdExp.name, 3, "LCR");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(2, cmdIn);
        CHECK_N_CLEAR()

        STEP(4)
        genElementName(cmdExp.name, 4, "SEG");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(3, cmdIn);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.dispatch(4, cmdIn);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch states to GUI
    TEST(DSP_01, T04)
    {
        SETUP()
        StateGui stateIn;
        StateGui stateExp;
        Mem::zero(stateIn);
        Mem::zero(stateExp);

        STEP(1)
        genElementName(stateExp.name, 1, "TSW");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(0, stateIn);
        CHECK_N_CLEAR()

        STEP(2)
        genElementName(stateExp.name, 2, "SIG");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(1, stateIn);
        CHECK_N_CLEAR()

        STEP(3)
        genElementName(stateExp.name, 3, "LCR");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(2, stateIn);
        CHECK_N_CLEAR()

        STEP(4)
        genElementName(stateExp.name, 4, "SEG");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(3, stateIn);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.dispatch(4, stateIn);
        CHECK_N_CLEAR()
    }

    //  test type: boundary
    //  assignment out of range
    TEST(DSP_01, T05)
    {
        mSUT.reset();
        STEP(1)
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_ELEMENTS; ++n)
        {
            LSTEP(n)
            const INT32 ret = mSUT.assign(genElementName(n, "TSW"), SUBSYS_TSW, n);
            L_CHECK_EQUAL(n, ret)

        }
        ENDSTEPS()
        const INT32 ret = mSUT.assign(genElementName(1, "TSW"), SUBSYS_TSW, 1);
        L_CHECK_TRUE(ret < 0)
    }

    //  test type: coverage
    //  retrieve instance
    TEST(DSP_01, T06)
    {
        unmock();
        I_Dispatcher& inst = IL::getDispatcher();
    }
}
