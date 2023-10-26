//  ============================================================
//  test of module TSW_Hub
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <TSW/TSW_Hub.h>

namespace test
{
    class TestGroupTSH : public TestGroupBase
    {
    protected:
        TSW_Hub mSUT;
        inline TestGroupTSH()
        {
            mockAll();
        }
    };

    TEST_GROUP_BASE(TSW_02, TestGroupTSH) {};

    //  test type: equivalence class test
    //  fromFld
    TEST(TSW_02, T01)
    {
        SETUP()
        FldState tele;
        Mem::zero(tele);
        tele.state1 = 101;
        
        STEP(1)
        //  good case
        m_TSW_Provider().expectHas(11, true);
        m_TSW().expectFromFld(101);
        mSUT.fromFld(tele, 11);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_TSW_Provider().expectHas(11, false);
        mSUT.fromFld(tele, 11);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  fromGui
    TEST(TSW_02, T02)
    {
        SETUP()
        GuiCmd tele;
        Mem::zero(tele);
        tele.cmd1 = 202;
        
        STEP(1)
        //  good case
        m_TSW_Provider().expectHas(22, true);
        m_TSW().expectFromGui(202);
        mSUT.fromGui(tele, 22);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_TSW_Provider().expectHas(22, false);
        mSUT.fromGui(tele, 22);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toFld
    TEST(TSW_02, T03)
    {
        SETUP()
        CmdFld tele;
        Mem::zero(tele);
        tele.cmd1 = 303;
        genElementName(tele.name, 33);
        m_Dispatcher().setLabel(tele.name);
        
        STEP(1)
        //  good case
        m_Dispatcher().expectLabel(3, true);
        m_FldCom().expectSend(tele);
        mSUT.toFld(3, 303);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_Dispatcher().expectLabel(3, false);
        mSUT.toFld(3, 303);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toGui
    TEST(TSW_02, T04)
    {
        SETUP()
        StateGui tele;
        Mem::zero(tele);
        tele.state1 = 404;
        genElementName(tele.name, 44);
        m_Dispatcher().setLabel(tele.name);
        
        STEP(1)
        //  good case
        m_Dispatcher().expectLabel(4, true);
        m_GuiCom().expectSend(tele);
        mSUT.toGui(4, 404);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_Dispatcher().expectLabel(4, false);
        mSUT.toGui(4, 404);
        CHECK_N_CLEAR()
    }
   
    //  test type: coverage
    //  retrieve instance
    TEST(TSW_02, T05)
    {
        unmock();
        I_TSW_Hub& inst = ddi::getTSW_Hub();
    }
}
