//  ============================================================
//  test of module SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SIG/SIG_Provider.h>
#include <SIG/SIG_X.h>

namespace test
{
    TEST_GROUP_BASE(SIG_02, TestGroupBase)
    {
    protected:
        GenProjData<1, 3, 1, 1> mData;
        void setup()
        {
            mData.setSigType(0, TYPE_SIG_H);
            mData.setSigType(1, TYPE_SIG_N);
            mData.setSigType(2, TYPE_SIG_H_N);
        }
    };

    //  test type: equivalence class test
    //  load valid ProjData SIG
    TEST(SIG_02, T01)
    {
        SETUP()
        I_Provider& prv = SIG_Provider::instance();

        STEP(1)
        m_Dispatcher().expectAssign(mData.sigAddr(0), COMP_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigAddr(1), COMP_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigAddr(2), COMP_SIG, 2, 2);
        prv.load(mData.pSIG(), mData.numSIG());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(3, prv.size())
        L_CHECK_ELEM_TYPE(SIG_H,   prv.at(0))
        L_CHECK_ELEM_TYPE(SIG_N,   prv.at(1))
        L_CHECK_ELEM_TYPE(SIG_H_N, prv.at(2))
    }

    //  test type: equivalence class test
    //  load invalid ProjData SIG (unknown type)
    TEST(SIG_02, T02)
    {
        SETUP()
        I_Provider& prv = SIG_Provider::instance();
        mData.setSigType(2, TYPE_SIG_H + 100);

        STEP(1)
        m_Dispatcher().expectAssign(mData.sigAddr(0), COMP_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigAddr(1), COMP_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigAddr(2), COMP_SIG, 2, 2);
        m_Log().expectLog(COMP_SIG, RET_ERR_STARTUP);
        prv.load(mData.pSIG(), mData.numSIG());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, prv.size())
    }

    //  test type: equivalence class test
    //  load valid ProjData SIG Dispatcher returns negative value
    TEST(SIG_02, T03)
    {
        SETUP()
        I_Provider& prv = SIG_Provider::instance();

        STEP(1)
        m_Dispatcher().expectAssign(mData.sigAddr(0), COMP_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigAddr(1), COMP_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigAddr(2), COMP_SIG, 2, -1);
        m_Log().expectLog(COMP_SIG, RET_ERR_STARTUP);
        prv.load(mData.pSIG(), mData.numSIG());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, prv.size())
    }
}
