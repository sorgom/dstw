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
    };

    TEST_GROUP_BASE(TSW_02, TestGroupTSH) {};

    //  test type: equivalence class test
    //  fromDsp FldState
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
        mSUT.fromDsp(11, tele);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_TSW_Provider().expectHas(11, false);
        mSUT.fromDsp(11, tele);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  fromDsp GuiCmd
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
        mSUT.fromDsp(22, tele);
        CHECK_N_CLEAR()

        STEP(2)
        //  fail case
        m_TSW_Provider().expectHas(22, false);
        mSUT.fromDsp(22, tele);
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
        
        STEP(1)
        m_Dispatcher().expectDispatch(3, tele);
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
        
        STEP(1)
        m_Dispatcher().expectDispatch(4, tele);
        mSUT.toGui(4, 404);
        CHECK_N_CLEAR()
    }
   
    //  test type: coverage
    //  retrieve instance
    TEST(TSW_02, T05)
    {
        I_TSW_Hub& inst = TSW_Hub::instance();
    }
}
