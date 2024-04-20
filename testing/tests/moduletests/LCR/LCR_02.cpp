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
        GenProjData<0, 0, 2, 0> mData;
        inline TestGroupLCP()
        {
            mData.setLcrType(0, TYPE_LCR);
            mData.setLcrType(1, TYPE_LCR_UBK); 
        }
    };

    TEST_GROUP_BASE(LCR_02, TestGroupLCP)
    {};

    //  test type: equivalence class test
    //  load valid ProjData LCR
    TEST(LCR_02, T01)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrName(0), COMP_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrName(1), COMP_LCR, 1, 1);
        mSUT.load(mData.pLCR(), mData.numLCR());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(2, mSUT.size())
        L_CHECK_EQUAL(TYPE_LCR, mSUT.at(0).type())
        L_CHECK_EQUAL(TYPE_LCR_UBK, mSUT.at(1).type())
    }

    //  test type: equivalence class test
    //  load invalid ProjData LCR (unknown type)
    TEST(LCR_02, T02)
    {
        SETUP()
        mData.setLcrType(1, TYPE_LCR_UBK + 100); 
        
        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrName(0), COMP_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrName(1), COMP_LCR, 1, 1);
        m_Log().expectLog(COMP_LCR, RET_ERR_STARTUP);
        mSUT.load(mData.pLCR(), mData.numLCR());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, mSUT.size())
    }

    //  test type: equivalence class test
    //  load valid ProjData LCR Dispatcher returns PosRes invalid
    TEST(LCR_02, T03)
    {
        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrName(0), COMP_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrName(1), COMP_LCR, 1, -1);
        m_Log().expectLog(COMP_LCR, RET_ERR_STARTUP);
        mSUT.load(mData.pLCR(), mData.numLCR());
        CHECK_N_CLEAR()
    }
    
    //  test type: coverage
    //  retrieve instance
    TEST(LCR_02, T04)
    {
        I_Provider& inst = LCR_Provider::instance();
        play(inst);
    }
}