//  ============================================================
//  test of module TSW_Hub
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <TSW/TSW_Hub.h>

namespace test
{
    class TestGroupTSH : public TestGroupBase
    {
    protected:
        TSW_Hub mSUT;
        M_FldCom&       mCom;
        M_TSW_Provider& mProv;
        M_Dispatcher&   mDisp;
        GenProjData<10, 1, 1, 1> mProjData;

        inline TestGroupTSH():
            mCom(m_FldCom()),
            mProv(m_TSW_Provider()),
            mDisp(m_Dispatcher())
        {
            mockAll();
            mProv.setSize(1);
        }
    };

    TEST_GROUP_BASE(TSW_02, TestGroupTSH)
    {};

    //  test type: equivalence class test
    //  load ProjData TSW
    //  10 data, regular responses
    TEST(TSW_02, T01)
    {
        STEP(1)
        mProv.setCapacity(10);
        mProv.expectReset();
        mDisp.expectNumAssign(SUBSYS_TSW, 10);
        mProv.expectNumAdd(10);
        const bool ret = mSUT.load(mProjData.pTSW, mProjData.numTSW);
        CHECK_N_CLEAR()
        L_CHECK_TRUE(ret)
    }

    //  test type: equivalence class test
    //  load ProjData TSW
    //  10 data, Dispatcher returns -1 at second assignment
    TEST(TSW_02, T02)
    {
        STEP(1)
        mProv.setCapacity(10);
        mProv.expectReset();
        mDisp.expectAssign(SUBSYS_TSW,  0, 55);
        mProv.expectAdd(55);
        mDisp.expectAssign(SUBSYS_TSW,  1, -1);
        mProv.expectReset();
        const bool ret = mSUT.load(mProjData.pTSW, mProjData.numTSW);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ret)
    }

    //  test type: equivalence class test
    //  load ProjData TSW
    //  10 data, Provider capacity too small
    TEST(TSW_02, T03)
    {
        STEP(1)
        mProv.setCapacity(9);
        mProv.expectReset();
        const bool ret = mSUT.load(mProjData.pTSW, mProjData.numTSW);
        CHECK_N_CLEAR()
        L_CHECK_FALSE(ret)
    }
}