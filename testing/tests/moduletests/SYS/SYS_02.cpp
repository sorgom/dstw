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
            mSUT.clear();
            mSUT.assign(genComName(1, "TSW"), COMP_TSW, 1);
            mSUT.assign(genComName(2, "SIG"), COMP_SIG, 2);
            mSUT.assign(genComName(3, "LCR"), COMP_LCR, 3);
            mSUT.assign(genComName(4, "SEG"), COMP_SEG, 4);
            mSUT.index();
        }
    };

    TEST_GROUP_BASE(SYS_02, TestGroupDSP) {};

    //  test type: equivalence class test
    //  Dispatcher dispatch state telegrams from field
    TEST(SYS_02, T01)
    {
        SETUP()
        ComTeleFld tele;

        STEP(1)
        nameElement(tele, 1, "TSW");
        m_TSW_Provider().expectSize(2);
        m_TSW().expectProcess(tele);
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(tele, 2, "SIG");
        m_SIG_Provider().expectSize(3);
        m_SIG().expectProcess(tele);
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(tele, 3, "LCR");
        m_LCR_Provider().expectSize(4);
        m_LCR().expectProcess(tele);
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(tele, 4, "SEG");
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_SYS, ERR_MATCH);
        nameElement(tele, 2, "TSW");
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()
    }
    //  test type: equivalence class test
    //  Dispatcher dispatch cmd telegrams from GUI
    TEST(SYS_02, T02)
    {
        SETUP()
        ComTeleGui tele;
    
        STEP(1)
        nameElement(tele, 1, "TSW");
        m_TSW_Provider().expectSize(2);
        m_TSW().expectProcess(tele);
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(tele, 2, "SIG");
        m_SIG_Provider().expectSize(3);
        m_SIG().expectProcess(tele);
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(tele, 3, "LCR");
        m_LCR_Provider().expectSize(4);
        m_LCR().expectProcess(tele);
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(tele, 4, "SEG");
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_SYS, ERR_MATCH);
        nameElement(tele, 2, "TSW");
        mSUT.dispatch(tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch cmds to field
    TEST(SYS_02, T03)
    {
        SETUP()
        ComTeleFld teleExp;

        STEP(1)
        nameElement(teleExp, 1, "TSW");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(0, ComTeleFld());
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(teleExp, 2, "SIG");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(1, ComTeleFld());
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(teleExp, 3, "LCR");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(2, ComTeleFld());
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(teleExp, 4, "SEG");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(3, ComTeleFld());
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.dispatch(4, ComTeleFld());
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch states to GUI
    TEST(SYS_02, T04)
    {
        SETUP()
        ComTeleGui teleExp;

        STEP(1)
        nameElement(teleExp, 1, "TSW");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(0, ComTeleGui());
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(teleExp, 2, "SIG");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(1, ComTeleGui());
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(teleExp, 3, "LCR");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(2, ComTeleGui());
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(teleExp, 4, "SEG");
        m_Com().expectSend(teleExp);
        mSUT.dispatch(3, ComTeleGui());
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.dispatch(4, ComTeleGui());
        CHECK_N_CLEAR()
    }

    //  test type: coverage
    //  retrieve instance
    TEST(SYS_02, T05)
    {
        I_Dispatcher& inst = Dispatcher::instance();
        play(inst);
    }

    //  test type: coverage
    //  unmatchable subsytem identifier
    TEST(SYS_02, T06)
    {
        SETUP()
        mSUT.clear();
        E_Comp comp = (E_Comp) 100;
        mSUT.assign(genComName(1, "TSW"), comp, 1);
        mSUT.index();
        
        STEP(1)
        ComTeleFld teleF;
        nameElement(teleF, 1, "TSW");
        mSUT.dispatch(teleF);
        CHECK_N_CLEAR()    

        STEP(2)
        ComTeleGui teleG;
        nameElement(teleG, 1, "TSW");
        mSUT.dispatch(teleG);
        CHECK_N_CLEAR()    
    }

    //  test type: equivalence class test
    //  Dispatcher duplicate assignments -> index error
    TEST(SYS_02, T07)
    {
        mSUT.clear();
        mSUT.assign(genComName(1, "TSW"), COMP_TSW, 1);
        mSUT.assign(genComName(1, "TSW"), COMP_TSW, 2);
        mSUT.assign(genComName(3, "LCR"), COMP_LCR, 3);
        mSUT.assign(genComName(4, "SEG"), COMP_SEG, 4);
        CHECK_N_CLEAR()

        m_Log().expectLog(COMP_SYS, ERR_STARTUP);
        mSUT.index();
        CHECK_N_CLEAR()
    }
}
