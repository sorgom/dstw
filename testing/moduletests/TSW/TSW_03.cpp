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
        GenProjData<2> mData;
        inline TestGroupTSP()
        {
            mockAll();
        }
    };

    TEST_GROUP_BASE(TSW_03, TestGroupTSP)
    {};

    //  test type: equivalence class test
    //  load valid ProjData TSW
    TEST(TSW_03, T01)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.tswName(0), SUBSYS_TSW, 0, 0);
        m_Dispatcher().expectAssign(mData.tswName(1), SUBSYS_TSW, 1, 1);
        mSUT.load(mData.pTSW, mData.numTSW);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(mSUT.has(1))
        L_CHECK_FALSE(mSUT.has(2))
    }

    //  test type: equivalence class test
    //  load invalid ProjData TSW (too many)
    TEST(TSW_03, T02)
    {
        STEP(1)
        m_Logger().expectLog(COMP_TSW_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pTSW, CAPACITY_TSW + 1);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }

    //  test type: equivalence class test
    //  load valid ProjData TSW Dispatcher returns negative value
    TEST(TSW_03, T03)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.tswName(0), SUBSYS_TSW, 0, 0);
        m_Dispatcher().expectAssign(mData.tswName(1), SUBSYS_TSW, 1, -1);
        m_Logger().expectLog(COMP_TSW_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pTSW, mData.numTSW);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }
    //  test type: coverage
    //  retrieve instance
    TEST(TSW_03, T04)
    {
        unmock();
        I_TSW_Provider& inst = ddi::getTSW_Provider();
    }
}