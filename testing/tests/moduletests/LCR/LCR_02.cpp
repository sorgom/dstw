//  ============================================================
//  test of module LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <LCR/LCR_Provider.h>
#include <LCR/LCR_X.h>

namespace test
{
    TEST_GROUP_BASE(LCR_02, TestGroupBase)
    {
    protected:
        GenProjData<0, 0, 2, 0> mData;
        void setup()
        {
            mData.setLcrType(0, TYPE_LCR);
            mData.setLcrType(1, TYPE_LCR_UBK);
        }
    };

    //  test type: equivalence class test
    //  load valid ProjData LCR
    TEST(LCR_02, T01)
    {
        SETUP()
        I_Provider& prv = LCR_Provider::instance();

        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrAddr(0), COMP_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrAddr(1), COMP_LCR, 1, 1);
        prv.load(mData.pLCR(), mData.numLCR());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(2, prv.size())
        L_CHECK_ELEM_TYPE(LCR,     prv.at(0))
        L_CHECK_ELEM_TYPE(LCR_UBK, prv.at(1))
    }

    //  test type: equivalence class test
    //  load invalid ProjData LCR (unknown type)
    TEST(LCR_02, T02)
    {
        SETUP()
        I_Provider& prv = LCR_Provider::instance();
        mData.setLcrType(1, TYPE_LCR_UBK + 100);

        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrAddr(0), COMP_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrAddr(1), COMP_LCR, 1, 1);
        m_Log().expectLog(COMP_LCR, RET_ERR_STARTUP);
        prv.load(mData.pLCR(), mData.numLCR());
        CHECK_N_CLEAR()
        L_CHECK_EQUAL(0, prv.size())
    }

    //  test type: equivalence class test
    //  load valid ProjData LCR Dispatcher returns PosRes invalid
    TEST(LCR_02, T03)
    {
        SETUP()
        I_Provider& prv = LCR_Provider::instance();

        STEP(1)
        m_Dispatcher().expectAssign(mData.lcrAddr(0), COMP_LCR, 0, 0);
        m_Dispatcher().expectAssign(mData.lcrAddr(1), COMP_LCR, 1, -1);
        m_Log().expectLog(COMP_LCR, RET_ERR_STARTUP);
        prv.load(mData.pLCR(), mData.numLCR());
        CHECK_N_CLEAR()
    }
}
