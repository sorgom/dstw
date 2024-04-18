//  ============================================================
//  test of module TSW_Provider
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <TSW/TSW_Provider.h>

namespace test
{
    class TestGroupTSP : public TestGroupBase
    {
    protected:
        TSW_Provider mSUT;
        GenProjData<2, 0, 0, 0> mData;
    };

    TEST_GROUP_BASE(TSW_03, TestGroupTSP) {};

    //  test type: equivalence class test
    //  load valid ProjData TSW
    TEST(TSW_03, T01)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.tswName(0), COMP_TSW, 0, 0);
        m_Dispatcher().expectAssign(mData.tswName(1), COMP_TSW, 1, 1);
        mSUT.load(mData.pTSW(), mData.numTSW());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(2, mSUT.size())

        STEP(2)
        I_Elem& tsw = mSUT.at(1);
        play(tsw);
    }

    //  test type: equivalence class test
    //  load valid ProjData TSW Dispatcher returns PosRes invalid
    TEST(TSW_03, T02)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.tswName(0), COMP_TSW, 0, 0);
        m_Dispatcher().expectAssign(mData.tswName(1), COMP_TSW, 1, -1);
        m_Log().expectLog(COMP_TSW, ERR_STARTUP);
        mSUT.load(mData.pTSW(), mData.numTSW());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, mSUT.size())
    }

    //  test type: coverage
    //  retrieve instance / at
    TEST(TSW_03, T03)
    {
        unmock();
        I_Provider& inst = TSW_Provider::instance();
        play(inst);
    }
}
