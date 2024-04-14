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
    //  fromDsp ComTeleFld
    TEST(TSW_02, T01)
    {
        SETUP()
        const ComTeleFld tele(101);
        
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
    //  fromDsp ComTeleGui
    TEST(TSW_02, T02)
    {
        SETUP()
        const ComTeleGui tele(202);
        
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
        STEP(1)
        m_Dispatcher().expectDispatch(1, ComTeleFld(103));
        mSUT.toFld(1, 103);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  toGui
    TEST(TSW_02, T04)
    {
        STEP(1)
        m_Dispatcher().expectDispatch(2, ComTeleGui(204));
        mSUT.toGui(2, 204);
        CHECK_N_CLEAR()
    }
   
    //  test type: coverage
    //  retrieve instance
    TEST(TSW_02, T05)
    {
        unmock();
        I_TSW_Hub& inst = IL::getTSW_Hub();
        play(inst);
    }
}
