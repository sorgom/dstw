//  ============================================================
//  test of module Loader
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Loader.h>

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

        STEP(1)
        m_Dispatcher().expectReset();
        m_TSW_Provider().expectLoad(projData.pTSW, projData.numTSW);
        m_SIG_Provider().expectLoad(projData.pSIG, projData.numSIG);
        m_Dispatcher().expectIndex();
        mSUT.load(projData);
        CHECK_N_CLEAR()
    }

    //  test type: coverage
    //  retrieve instance
    TEST(LDR_01, T03)
    {
        I_Loader& inst = Loader::instance();
    }
}