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
    };

    TEST_GROUP_BASE(SIG_02, TestGroupSIH) {};

    //  test type: equivalence class test
    //  fromDsp FldState
    TEST(SIG_02, T01)
    {
        SETUP()
        const FldState tele(101, 102);
        
        STEP(1)
        //  good case
        m_SIG_Provider().expectHas(11, true);
        m_SIG().expectFromFld(101, 102);
        mSUT.fromDsp(11, tele);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_SIG_Provider().expectHas(11, false);
        mSUT.fromDsp(11, tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  fromDsp GuiCmd
    TEST(SIG_02, T02)
    {
        SETUP()
        const GuiCmd tele(201, 202);
        
        STEP(1)
        //  good case
        m_SIG_Provider().expectHas(22, true);
        m_SIG().expectFromGui(201, 202);
        mSUT.fromDsp(22, tele);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_SIG_Provider().expectHas(22, false);
        mSUT.fromDsp(22, tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toFld
    TEST(SIG_02, T03)
    {
        SETUP()
        CmdFld tele(301, 302);
        
        STEP(1)
        m_Dispatcher().expectDispatch(3, tele);
        mSUT.toFld(3, 301, 302);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toGui
    TEST(SIG_02, T04)
    {
        SETUP()
        StateGui tele(401, 402);
        
        STEP(1)
        m_Dispatcher().expectDispatch(4, tele);
        mSUT.toGui(4, 401, 402);
        CHECK_N_CLEAR()
    }
   
    //  test type: coverage
    //  retrieve instance
    TEST(SIG_02, T05)
    {
        unmock();
        I_SIG_Hub& inst = IL::getSIG_Hub();
        play(inst);
    }
}
