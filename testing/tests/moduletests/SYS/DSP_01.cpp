//  ============================================================
//  test of module Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Dispatcher.h>

#include <qnd/useCout.h>

namespace test
{
    class TestGroupDSP : public TestGroupBase
    {
    protected:
        Dispatcher mSUT;
        inline TestGroupDSP()
        {
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
        nameElement(fldState, 1, "TSW");
        m_TSW_Hub().expectFromDsp(1, fldState);
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(fldState, 2, "SIG");
        m_SIG_Hub().expectFromDsp(2, fldState);
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(3)
        //  LCR not part of current implementation
        nameElement(fldState, 3, "LCR");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(fldState, 4, "SEG");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(MOD_DISPATCHER, ERR_MATCH);
        nameElement(fldState, 2, "TSW");
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
        nameElement(guiCmd, 1, "TSW");
        m_TSW_Hub().expectFromDsp(1, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(guiCmd, 2, "SIG");
        m_SIG_Hub().expectFromDsp(2, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(3)
        //  LCR not part of current implementation
        nameElement(guiCmd, 3, "LCR");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(guiCmd, 4, "SEG");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(MOD_DISPATCHER, ERR_MATCH);
        nameElement(guiCmd, 2, "TSW");
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
        nameElement(cmdExp, 1, "TSW");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(0, cmdIn);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(cmdExp, 2, "SIG");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(1, cmdIn);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(cmdExp, 3, "LCR");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(2, cmdIn);
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(cmdExp, 4, "SEG");
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
        nameElement(stateExp, 1, "TSW");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(0, stateIn);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(stateExp, 2, "SIG");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(1, stateIn);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(stateExp, 3, "LCR");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(2, stateIn);
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(stateExp, 4, "SEG");
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
        for (UINT32 n = 0; n < CAPACITY_DSP; ++n)
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
        I_Dispatcher& inst = Dispatcher::instance();
    }

    //  test type: coverage
    //  unmatchable subsytem identifier
    TEST(DSP_01, T07)
    {
        SETUP()
        mSUT.reset();
        E_Subsys subs = (E_Subsys) 1000;
        mSUT.assign(genElementName(1, "TSW"), subs, 1);
        mSUT.index();
        
        STEP(1)
        FldState fldState = {0};
        nameElement(fldState, 1, "TSW");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()    

        STEP(2)
        GuiCmd guiCmd;
        nameElement(guiCmd, 1, "TSW");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()    

    }
}
