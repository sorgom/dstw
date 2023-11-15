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
            mData.setSigType(0, SIG_TYPE_H);
            mData.setSigType(1, SIG_TYPE_N); 
            mData.setSigType(2, SIG_TYPE_H_N); 
        }
    };

    TEST_GROUP_BASE(SIG_03, TestGroupSIP)
    {};

    //  test type: size check
    TEST(SIG_03, T01)
    {
        STEP(1)
        L_CHECK_EQUAL_SIZE(SIG_X, SIG_H)
        L_CHECK_EQUAL_SIZE(SIG_X, SIG_N)
        L_CHECK_EQUAL_SIZE(SIG_X, SIG_H_N)
    }

    //  test type: equivalence class test
    //  load valid ProjData SIG
    TEST(SIG_03, T02)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.sigName(0), SUBSYS_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigName(1), SUBSYS_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigName(2), SUBSYS_SIG, 2, 2);
        mSUT.load(mData.pSIG, mData.numSIG);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(mSUT.has(2))
        L_CHECK_FALSE(mSUT.has(3))
        L_CHECK_EQUAL(SIG_TYPE_H,   mSUT.at(0).type())
        L_CHECK_EQUAL(SIG_TYPE_N,   mSUT.at(1).type())
        L_CHECK_EQUAL(SIG_TYPE_H_N, mSUT.at(2).type())
    }

    //  test type: equivalence class test
    //  load invalid ProjData SIG (unknown type)
    TEST(SIG_03, T03)
    {
        SETUP()
        mData.setSigType(2, SIG_TYPE_H + 100); 
        
        STEP(1)
        m_Dispatcher().expectAssign(mData.sigName(0), SUBSYS_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigName(1), SUBSYS_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigName(2), SUBSYS_SIG, 2, 2);
        m_Log().expectLog(MOD_SIG_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pSIG, mData.numSIG);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }

    //  test type: equivalence class test
    //  load invalid ProjData SIG (too many)
    TEST(SIG_03, T04)
    {
        STEP(1)
        m_Log().expectLog(MOD_SIG_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pSIG, CAPACITY_SIG + 1);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }

    //  test type: equivalence class test
    //  load valid ProjData SIG Dispatcher returns negative value
    TEST(SIG_03, T05)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.sigName(0), SUBSYS_SIG, 0, 0);
        m_Dispatcher().expectAssign(mData.sigName(1), SUBSYS_SIG, 1, 1);
        m_Dispatcher().expectAssign(mData.sigName(2), SUBSYS_SIG, 2, -1);
        m_Log().expectLog(MOD_SIG_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pSIG, mData.numSIG);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }
    
    //  test type: coverage
    //  retrieve instance
    TEST(SIG_03, T06)
    {
        unmock();
        I_SIG_Provider& inst = IL::getSIG_Provider();
    }
}