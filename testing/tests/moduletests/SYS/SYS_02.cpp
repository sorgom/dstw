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
            mSUT.reset();
            mSUT.assign(genComName(1, "TSW"), SUBSYS_TSW, 1);
            mSUT.assign(genComName(2, "SIG"), SUBSYS_SIG, 2);
            mSUT.assign(genComName(3, "LCR"), SUBSYS_LCR, 3);
            mSUT.assign(genComName(4, "SEG"), SUBSYS_SEG, 4);
            mSUT.index();
        }
    };

    TEST_GROUP_BASE(SYS_02, TestGroupDSP) {};

    //  test type: equivalence class test
    //  Dispatcher dispatch state telegrams from field
    TEST(SYS_02, T01)
    {
        SETUP()
        ComFldState fldState;

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
        nameElement(fldState, 3, "LCR");
        m_LCR_Hub().expectFromDsp(3, fldState);
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(fldState, 4, "SEG");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(MOD_SYS_DISPATCHER, ERR_MATCH);
        nameElement(fldState, 2, "TSW");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()
    }
    //  test type: equivalence class test
    //  Dispatcher dispatch cmd telegrams from GUI
    TEST(SYS_02, T02)
    {
        SETUP()
        ComGuiCmd guiCmd;
    
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
        m_LCR_Hub().expectFromDsp(3, guiCmd);
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(guiCmd, 4, "SEG");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(MOD_SYS_DISPATCHER, ERR_MATCH);
        nameElement(guiCmd, 2, "TSW");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch cmds to field
    TEST(SYS_02, T03)
    {
        SETUP()
        ComCmdFld cmdExp;

        STEP(1)
        nameElement(cmdExp, 1, "TSW");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(0, ComCmdFld());
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(cmdExp, 2, "SIG");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(1, ComCmdFld());
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(cmdExp, 3, "LCR");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(2, ComCmdFld());
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(cmdExp, 4, "SEG");
        m_Com().expectSend(cmdExp);
        mSUT.dispatch(3, ComCmdFld());
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.dispatch(4, ComCmdFld());
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch states to GUI
    TEST(SYS_02, T04)
    {
        SETUP()
        ComStateGui stateExp;

        STEP(1)
        nameElement(stateExp, 1, "TSW");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(0, ComStateGui());
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(stateExp, 2, "SIG");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(1, ComStateGui());
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(stateExp, 3, "LCR");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(2, ComStateGui());
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(stateExp, 4, "SEG");
        m_Com().expectSend(stateExp);
        mSUT.dispatch(3, ComStateGui());
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.dispatch(4, ComStateGui());
        CHECK_N_CLEAR()
    }

    //  test type: boundary
    //  assignment out of range
    TEST(SYS_02, T05)
    {
        mSUT.reset();
        STEP(1)
        SUBSTEPS()
        for (UINT16 n = 0; n < CAPACITY_DSP; ++n)
        {
            LSTEP(n)
            const PosRes res = mSUT.assign(genComName(n, "TSW"), SUBSYS_TSW, n);
            L_CHECK_EQUAL(n, res.pos)
            L_CHECK_TRUE(res.valid)
        }
        ENDSTEPS()
        const PosRes res = mSUT.assign(genComName(1, "TSW"), SUBSYS_TSW, 1);
        L_CHECK_FALSE(res.valid)
    }

    //  test type: coverage
    //  retrieve instance
    TEST(SYS_02, T06)
    {
        unmock();
        I_Dispatcher& inst = IL::getDispatcher();
        play(inst);
    }

    //  test type: coverage
    //  unmatchable subsytem identifier
    TEST(SYS_02, T07)
    {
        SETUP()
        mSUT.reset();
        E_Subsys subs = (E_Subsys) 100;
        mSUT.assign(genComName(1, "TSW"), subs, 1);
        mSUT.index();
        
        STEP(1)
        ComFldState fldState;
        nameElement(fldState, 1, "TSW");
        mSUT.dispatch(fldState);
        CHECK_N_CLEAR()    

        STEP(2)
        ComGuiCmd guiCmd;
        nameElement(guiCmd, 1, "TSW");
        mSUT.dispatch(guiCmd);
        CHECK_N_CLEAR()    

    }

    //  test type: equivalence class test
    //  Dispatcher duplicate assignments -> index error
    TEST(SYS_02, T08)
    {
        mSUT.reset();
        mSUT.assign(genComName(1, "TSW"), SUBSYS_TSW, 1);
        mSUT.assign(genComName(1, "TSW"), SUBSYS_TSW, 2);
        mSUT.assign(genComName(3, "LCR"), SUBSYS_LCR, 3);
        mSUT.assign(genComName(4, "SEG"), SUBSYS_SEG, 4);
        CHECK_N_CLEAR()

        m_Log().expectLog(MOD_SYS_DISPATCHER, ERR_STARTUP);
        mSUT.index();
        CHECK_N_CLEAR()
    }
}
