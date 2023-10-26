//  ============================================================
//  test of module SIG_Hub
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SIG/SIG_Hub.h>

namespace test
{
    class TestGroupSIH : public TestGroupBase
    {
    protected:
        SIG_Hub mSUT;
        inline TestGroupSIH()
        {
            mockAll();
        }
    };

    TEST_GROUP_BASE(SIG_02, TestGroupSIH) {};

    //  test type: equivalence class test
    //  fromFld
    TEST(SIG_02, T01)
    {
        SETUP()
        FldState tele;
        Mem::zero(tele);
        tele.state1 = 101;
        tele.state2 = 102;
        
        STEP(1)
        //  good case
        m_SIG_Provider().expectHas(11, true);
        m_SIG().expectFromFld(101, 102);
        mSUT.fromFld(tele, 11);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_SIG_Provider().expectHas(11, false);
        mSUT.fromFld(tele, 11);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  fromGui
    TEST(SIG_02, T02)
    {
        SETUP()
        GuiCmd tele;
        Mem::zero(tele);
        tele.cmd1 = 201;
        tele.cmd2 = 202;
        
        STEP(1)
        //  good case
        m_SIG_Provider().expectHas(22, true);
        m_SIG().expectFromGui(201, 202);
        mSUT.fromGui(tele, 22);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_SIG_Provider().expectHas(22, false);
        mSUT.fromGui(tele, 22);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toFld
    TEST(SIG_02, T03)
    {
        SETUP()
        CmdFld tele;
        Mem::zero(tele);
        tele.cmd1 = 301;
        tele.cmd2 = 302;

        genElementName(tele.name, 33);
        m_Dispatcher().setLabel(tele.name);
        
        STEP(1)
        //  good case
        m_Dispatcher().expectLabel(3, true);
        m_FldCom().expectSend(tele);
        mSUT.toFld(3, 301, 302);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_Dispatcher().expectLabel(3, false);
        mSUT.toFld(3, 301, 302);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toGui
    TEST(SIG_02, T04)
    {
        SETUP()
        StateGui tele;
        Mem::zero(tele);
        tele.state1 = 401;
        tele.state2 = 402;

        genElementName(tele.name, 44);
        m_Dispatcher().setLabel(tele.name);
        
        STEP(1)
        //  good case
        m_Dispatcher().expectLabel(4, true);
        m_GuiCom().expectSend(tele);
        mSUT.toGui(4, 401, 402);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_Dispatcher().expectLabel(4, false);
        mSUT.toGui(4, 401, 402);
        CHECK_N_CLEAR()
    }
   
    //  test type: coverage
    //  retrieve instance
    TEST(SIG_02, T05)
    {
        unmock();
        I_SIG_Hub& inst = ddi::getSIG_Hub();
    }
}
