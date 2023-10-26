//  ============================================================
//  test of module Loader
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <system/Loader.h>

namespace test
{
    TEST_GROUP_BASE(LDR_01, TestGroupBase) {};

    //  test type: equivalence class test
    //  load data 
    TEST(LDR_01, T01)
    {
        SETUP()
        Loader mSUT;
        GenProjData<> projData;
        mockAll();

        bool ok = false;

        STEP(1)
        //  TSW_Provider loads
        //  SIG_Provider loads
        m_Dispatcher().expectReset();
        m_TSW_Provider().expectLoad(projData.pTSW, projData.numTSW, true);
        m_SIG_Provider().expectLoad(projData.pSIG, projData.numSIG, true);
        m_Dispatcher().expectIndex();
        ok = mSUT.load(projData);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ok)

        STEP(2)
        //  TSW_Provider fails
        m_Dispatcher().expectReset();
        m_TSW_Provider().expectLoad(projData.pTSW, projData.numTSW, false);
        m_Dispatcher().expectReset();
        ok = mSUT.load(projData);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)

        STEP(3)
        //  TSW_Provider loads
        //  SIG_Provider fails
        m_Dispatcher().expectReset();
        m_TSW_Provider().expectLoad(projData.pTSW, projData.numTSW, true);
        m_SIG_Provider().expectLoad(projData.pSIG, projData.numSIG, false);
        m_Dispatcher().expectReset();
        ok = mSUT.load(projData);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ok)
   }

    //  test type: coverage
    //  retrieve instance
    TEST(LDR_01, T03)
    {
        unmock();
        I_Loader& inst = ddi::getLoader();
    }
}