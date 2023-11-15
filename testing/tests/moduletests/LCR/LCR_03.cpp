//  ============================================================
//  test of module LCR_Provider
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <LCR/LCR_Provider.h>

namespace test
{
    class TestGroupLCP : public TestGroupBase
    {
    protected:
        LCR_Provider mSUT;
        GenProjData<1, 1, 2, 1> mData;
        inline TestGroupLCP()
        {
            mData.setLcrType(0, LCR_TYPE_LCR);
            mData.setLcrType(1, LCR_TYPE_LCR_UBK); 
        }
    };

    TEST_GROUP_BASE(LCR_03, TestGroupLCP)
    {};

    //  test type: size check
    TEST(LCR_03, T01)
    {
        STEP(1)
        L_CHECK_EQUAL_SIZE(LCR_X, LCR)
        L_CHECK_EQUAL_SIZE(LCR_X, LCR_UBK)
    }

    //  test type: equivalence class test
    //  load valid ProjData LCR
    TEST(LCR_03, T02)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrName(0), SUBSYS_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrName(1), SUBSYS_LCR, 1, 1);
        mSUT.load(mData.pLCR, mData.numLCR);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(mSUT.has(1))
        L_CHECK_FALSE(mSUT.has(2))
        L_CHECK_EQUAL(LCR_TYPE_LCR,     mSUT.at(0).type())
        L_CHECK_EQUAL(LCR_TYPE_LCR_UBK, mSUT.at(1).type())
    }

    //  test type: equivalence class test
    //  load invalid ProjData LCR (unknown type)
    TEST(LCR_03, T03)
    {
        SETUP()
        mData.setLcrType(1, LCR_TYPE_LCR_UBK + 100); 
        
        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrName(0), SUBSYS_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrName(1), SUBSYS_LCR, 1, 1);
        m_Log().expectLog(MOD_LCR_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pLCR, mData.numLCR);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }

    //  test type: equivalence class test
    //  load invalid ProjData LCR (too many)
    TEST(LCR_03, T04)
    {
        STEP(1)
        m_Log().expectLog(MOD_LCR_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pLCR, CAPACITY_LCR + 1);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }

    //  test type: equivalence class test
    //  load valid ProjData LCR Dispatcher returns negative value
    TEST(LCR_03, T05)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrName(0), SUBSYS_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrName(1), SUBSYS_LCR, 1, -1);
        m_Log().expectLog(MOD_LCR_PROVIDER, ERR_STARTUP);
        mSUT.load(mData.pLCR, mData.numLCR);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(mSUT.has(0))
    }
    
    //  test type: coverage
    //  retrieve instance
    TEST(LCR_03, T06)
    {
        I_LCR_Provider& inst = LCR_Provider::instance();
    }
}