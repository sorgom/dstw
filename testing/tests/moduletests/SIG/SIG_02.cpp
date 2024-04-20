//  ============================================================
//  test of module SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SIG/SIG_Provider.h>

namespace test
{
    class TestGroupSIP : public TestGroupBase
    {
    protected:
        SIG_Provider mSUT;
        GenProjData<1, 3, 1, 1> mData;
        inline TestGroupSIP()
        {
            mData.setSigType(0, TYPE_SIG_H);
            mData.setSigType(1, TYPE_SIG_N); 
            mData.setSigType(2, TYPE_SIG_H_N); 
        }
    };

    TEST_GROUP_BASE(SIG_03, TestGroupSIP)
    {};

    //  test type: equivalence class test
    //  load valid ProjData SIG
    TEST(SIG_03, T01)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.sigName(0), COMP_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigName(1), COMP_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigName(2), COMP_SIG, 2, 2);
        mSUT.load(mData.pSIG(), mData.numSIG());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(3, mSUT.size())
        L_CHECK_EQUAL(TYPE_SIG_H,   mSUT.at(0).type())
        L_CHECK_EQUAL(TYPE_SIG_N,   mSUT.at(1).type())
        L_CHECK_EQUAL(TYPE_SIG_H_N, mSUT.at(2).type())
    }

    //  test type: equivalence class test
    //  load invalid ProjData SIG (unknown type)
    TEST(SIG_03, T02)
    {
        SETUP()
        mData.setSigType(2, TYPE_SIG_H + 100); 
        
        STEP(1)
        m_Dispatcher().expectAssign(mData.sigName(0), COMP_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigName(1), COMP_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigName(2), COMP_SIG, 2, 2);
        m_Log().expectLog(COMP_SIG, RET_ERR_STARTUP);
        mSUT.load(mData.pSIG(), mData.numSIG());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, mSUT.size())
    }

    //  test type: equivalence class test
    //  load valid ProjData SIG Dispatcher returns negative value
    TEST(SIG_03, T03)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.sigName(0), COMP_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigName(1), COMP_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigName(2), COMP_SIG, 2, -1);
        m_Log().expectLog(COMP_SIG, RET_ERR_STARTUP);
        mSUT.load(mData.pSIG(), mData.numSIG());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, mSUT.size())
    }
    
    //  test type: coverage
    //  retrieve instance
    TEST(SIG_03, T04)
    {
        I_Provider& inst = SIG_Provider::instance();
        play(inst);
    }
}