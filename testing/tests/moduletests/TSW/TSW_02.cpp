//  ============================================================
//  test of module TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <TSW/TSW_Provider.h>

namespace test
{
    TEST_GROUP_BASE(TSW_02, TestGroupBase)
    {
    protected:
        GenProjData<2, 0, 0, 0> mData;
    };

    //  test type: equivalence class test
    //  load valid ProjData TSW
    TEST(TSW_02, T01)
    {
        SETUP()
        I_Provider& prv = TSW_Provider::instance();

        STEP(1)
        m_Dispatcher().expectAssign(mData.tswAddr(0), COMP_TSW, 0, 0);
        m_Dispatcher().expectAssign(mData.tswAddr(1), COMP_TSW, 1, 1);
        prv.load(mData.pTSW(), mData.numTSW());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(2, prv.size())

        STEP(2)
        I_Elem& tsw = prv.at(1);
        play(tsw);
    }

    //  test type: equivalence class test
    //  load valid ProjData TSW Dispatcher returns PosRes invalid
    TEST(TSW_02, T02)
    {
        SETUP()
        I_Provider& prv = TSW_Provider::instance();

        STEP(1)
        m_Dispatcher().expectAssign(mData.tswAddr(0), COMP_TSW, 0, 0);
        m_Dispatcher().expectAssign(mData.tswAddr(1), COMP_TSW, 1, -1);
        m_Log().expectLog(COMP_TSW, RET_ERR_STARTUP);
        prv.load(mData.pTSW(), mData.numTSW());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, prv.size())
    }
}
