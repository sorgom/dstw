//  ============================================================
//  test of modules Dispatcher
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
        const ComData data{11, 22};
        ComTele tele{{}, data};

        STEP(1)
        nameElement(tele, 1, "TSW");
        m_TSW_Provider().expectSize(2);
        m_TSW().expectFromFld(data);
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(tele, 2, "SIG");
        m_SIG_Provider().expectSize(3);
        m_SIG().expectFromFld(data);
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(tele, 3, "LCR");
        m_LCR_Provider().expectSize(4);
        m_LCR().expectFromFld(data);
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(tele, 4, "SEG");
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_SYS, RET_ERR_MATCH);
        nameElement(tele, 2, "TSW");
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()
    }
    //  test type: equivalence class test
    //  Dispatcher dispatch cmd telegrams from GUI
    TEST(SYS_02, T02)
    {
        SETUP()
        const ComData data{33, 44};
        ComTele tele{{}, data};

        STEP(1)
        nameElement(tele, 1, "TSW");
        m_TSW_Provider().expectSize(2);
        m_TSW().expectFromGui(data);
        mSUT.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(tele, 2, "SIG");
        m_SIG_Provider().expectSize(3);
        m_SIG().expectFromGui(data);
        mSUT.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(tele, 3, "LCR");
        m_LCR_Provider().expectSize(4);
        m_LCR().expectFromGui(data);
        mSUT.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(4)
        //  SEG not part of current implementation
        nameElement(tele, 4, "SEG");
        mSUT.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        m_Log().expectLog(COMP_SYS, RET_ERR_MATCH);
        nameElement(tele, 2, "TSW");
        mSUT.fromGui(tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch cmds to field
    TEST(SYS_02, T03)
    {
        SETUP()
        const ComData data{55, 66};
        ComTele teleExp{{}, data};

        STEP(1)
        nameElement(teleExp, 1, "TSW");
        m_Com().expectToFld(teleExp);
        mSUT.toFld(0, data);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(teleExp, 2, "SIG");
        m_Com().expectToFld(teleExp);
        mSUT.toFld(1, data);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(teleExp, 3, "LCR");
        m_Com().expectToFld(teleExp);
        mSUT.toFld(2, data);
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(teleExp, 4, "SEG");
        m_Com().expectToFld(teleExp);
        mSUT.toFld(3, data);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.toFld(4, data);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  Dispatcher dispatch states to GUI
    TEST(SYS_02, T04)
    {
        SETUP()
        const ComData data{77, 88};
        ComTele teleExp{{}, data};

        STEP(1)
        nameElement(teleExp, 1, "TSW");
        m_Com().expectToGui(teleExp);
        mSUT.toGui(0, data);
        CHECK_N_CLEAR()

        STEP(2)
        nameElement(teleExp, 2, "SIG");
        m_Com().expectToGui(teleExp);
        mSUT.toGui(1, data);
        CHECK_N_CLEAR()

        STEP(3)
        nameElement(teleExp, 3, "LCR");
        m_Com().expectToGui(teleExp);
        mSUT.toGui(2, data);
        CHECK_N_CLEAR()

        STEP(4)
        nameElement(teleExp, 4, "SEG");
        m_Com().expectToGui(teleExp);
        mSUT.toGui(3, data);
        CHECK_N_CLEAR()

        STEP(5)
        //  not assigned
        mSUT.toGui(4, data);
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
        ComTele tele{{}, {99, 111}};
        nameElement(tele, 1, "TSW");
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()    

        STEP(2)
        mSUT.fromGui(tele);
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

        m_Log().expectLog(COMP_SYS, RET_ERR_STARTUP);
        mSUT.index();
        CHECK_N_CLEAR()
    }
    
    //  test type: equivalence class test
    //  telegrams from field and GUI
    //  Provider returns wrong size
    TEST(SYS_02, T08)
    {
        SETUP()
        const ComData data{33, 44};
        ComTele tele{{}, data};
        nameElement(tele, 1, "TSW");

        STEP(1)
        m_TSW_Provider().expectSize(1);
        m_Log().expectLog(COMP_SYS, RET_ERR_RANGE);
        mSUT.fromGui(tele);
        CHECK_N_CLEAR()

        STEP(2)
        m_TSW_Provider().expectSize(1);
        m_Log().expectLog(COMP_SYS, RET_ERR_RANGE);
        mSUT.fromFld(tele);
        CHECK_N_CLEAR()
    }
}
