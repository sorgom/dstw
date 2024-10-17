//  ============================================================
//  test of Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Dispatcher.h>

namespace test
{
    TEST_GROUP_BASE(SYS_02, TestGroupBase)
    {
        void init()
        {
            I_Dispatcher& dsp = Dispatcher::instance();
            dsp.clear();
            dsp.assign(genComAddr(1, "TSW"), COMP_TSW, 1);
            dsp.assign(genComAddr(2, "SIG"), COMP_SIG, 2);
            dsp.assign(genComAddr(3, "LCR"), COMP_LCR, 3);
            dsp.assign(genComAddr(4, "SEG"), COMP_SEG, 4);
            dsp.index();
        }
    };

    //  test type: equivalence class test
    //  Dispatcher dispatch state telegrams from field
    TEST(SYS_02, T01)
    {
        SETUP()
        init();
        const I_Dispatcher& dsp = Dispatcher::instance();

        const ComData data{11, 22};
        ComTele tele{{}, data};

        STEP(1)
        adrrElement(tele, 1, "TSW");
        m_TSW_Provider().expectSize(2);
        m_TSW().expectFromFld(data);
        dsp.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(2)
        adrrElement(tele, 2, "SIG");
        m_SIG_Provider().expectSize(3);
        m_SIG().expectFromFld(data);
        dsp.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(3)
        adrrElement(tele, 3, "LCR");
        m_LCR_Provider().expectSize(4);
        m_LCR().expectFromFld(data);
        dsp.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        adrrElement(tele, 4, "SEG");
        dsp.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_SYS, RET_ERR_MATCH);
        adrrElement(tele, 2, "TSW");
        dsp.fromFld(tele);
        CHECK_N_CLEAR()
    }
    //  test type: equivalence class test
    //  Dispatcher dispatch cmd telegrams from GUI
    TEST(SYS_02, T02)
    {
        SETUP()
        init();
        const I_Dispatcher& dsp = Dispatcher::instance();

        const ComData data{33, 44};
        ComTele tele{{}, data};

        STEP(1)
        adrrElement(tele, 1, "TSW");
        m_TSW_Provider().expectSize(2);
        m_TSW().expectFromGui(data);
        dsp.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(2)
        adrrElement(tele, 2, "SIG");
        m_SIG_Provider().expectSize(3);
        m_SIG().expectFromGui(data);
        dsp.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(3)
        adrrElement(tele, 3, "LCR");
        m_LCR_Provider().expectSize(4);
        m_LCR().expectFromGui(data);
        dsp.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        adrrElement(tele, 4, "SEG");
        dsp.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_SYS, RET_ERR_MATCH);
        adrrElement(tele, 2, "TSW");
        dsp.fromGui(tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch cmds to field
    TEST(SYS_02, T03)
    {
        SETUP()
        init();
        const I_Dispatcher& dsp = Dispatcher::instance();

        const ComData data{55, 66};
        ComTele teleExp{{}, data};

        STEP(1)
        adrrElement(teleExp, 1, "TSW");
        m_Com().expectToFld(teleExp);
        dsp.toFld(0, data);
        CHECK_N_CLEAR()

        STEP(2)
        adrrElement(teleExp, 2, "SIG");
        m_Com().expectToFld(teleExp);
        dsp.toFld(1, data);
        CHECK_N_CLEAR()

        STEP(3)
        adrrElement(teleExp, 3, "LCR");
        m_Com().expectToFld(teleExp);
        dsp.toFld(2, data);
        CHECK_N_CLEAR()

        STEP(4)
        adrrElement(teleExp, 4, "SEG");
        m_Com().expectToFld(teleExp);
        dsp.toFld(3, data);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        dsp.toFld(4, data);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch states to GUI
    TEST(SYS_02, T04)
    {
        SETUP()
        init();
        const I_Dispatcher& dsp = Dispatcher::instance();

        const ComData data{77, 88};
        ComTele teleExp{{}, data};

        STEP(1)
        adrrElement(teleExp, 1, "TSW");
        m_Com().expectToGui(teleExp);
        dsp.toGui(0, data);
        CHECK_N_CLEAR()

        STEP(2)
        adrrElement(teleExp, 2, "SIG");
        m_Com().expectToGui(teleExp);
        dsp.toGui(1, data);
        CHECK_N_CLEAR()

        STEP(3)
        adrrElement(teleExp, 3, "LCR");
        m_Com().expectToGui(teleExp);
        dsp.toGui(2, data);
        CHECK_N_CLEAR()

        STEP(4)
        adrrElement(teleExp, 4, "SEG");
        m_Com().expectToGui(teleExp);
        dsp.toGui(3, data);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        dsp.toGui(4, data);
        CHECK_N_CLEAR()
    }

    //  test type: coverage
    //  unmatchable subsytem identifier
    TEST(SYS_02, T05)
    {
        SETUP()
        I_Dispatcher& dsp = Dispatcher::instance();
        dsp.clear();

        E_Comp comp = (E_Comp) 255;
        dsp.assign(genComAddr(1, "TSW"), comp, 1);
        dsp.index();

        STEP(1)
        const ComTele tele{genComAddr(1, "TSW"), {99, 111}};
        dsp.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(2)
        dsp.fromGui(tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher duplicate assignments -> index error
    TEST(SYS_02, T06)
    {
        I_Dispatcher& dsp = Dispatcher::instance();
        dsp.clear();
        dsp.assign(genComAddr(1, "TSW"), COMP_TSW, 1);
        dsp.assign(genComAddr(1, "TSW"), COMP_TSW, 2);
        dsp.assign(genComAddr(3, "LCR"), COMP_LCR, 3);
        dsp.assign(genComAddr(4, "SEG"), COMP_SEG, 4);
        CHECK_N_CLEAR()

        m_Log().expectLog(COMP_SYS, RET_ERR_STARTUP);
        dsp.index();
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  telegrams from field and GUI
    //  Provider returns wrong size
    TEST(SYS_02, T07)
    {
        SETUP()
        init();
        const I_Dispatcher& dsp = Dispatcher::instance();

        const ComData data{33, 44};
        ComTele tele{{}, data};
        adrrElement(tele, 1, "TSW");

        STEP(1)
        m_TSW_Provider().expectSize(1);
        m_Log().expectLog(COMP_SYS, RET_ERR_RANGE);
        dsp.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(2)
        m_TSW_Provider().expectSize(1);
        m_Log().expectLog(COMP_SYS, RET_ERR_RANGE);
        dsp.fromFld(tele);
        CHECK_N_CLEAR()
    }
    //  test type: equivalence class test
    //  reGui
    TEST(SYS_02, T08)
    {
        SETUP()
        const I_Dispatcher& dsp = Dispatcher::instance();

        STEP(1)
        m_TSW_Provider().expectSize(0);
        m_SIG_Provider().expectSize(0);
        m_LCR_Provider().expectSize(0);
        dsp.reGui();
        CHECK_N_CLEAR()

        STEP(2)
        m_TSW_Provider().expectSize(1);
        m_SIG_Provider().expectSize(2);
        m_LCR_Provider().expectSize(3);
        m_TSW().expectToGui(1);
        m_SIG().expectToGui(2);
        m_LCR().expectToGui(3);
        dsp.reGui();
        CHECK_N_CLEAR()
    }
}
