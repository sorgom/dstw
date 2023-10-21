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
        M_FldCom& mCom;
        M_TSW_Provider& mProv;
        CmdFld mTele;

        inline TestGroupTSH():
            mCom(m_FldCom()),
            mProv(m_TSW_Provider())
        {
            mockAll();
            Mem::zero(mTele);
            mProv.setSize(1);
        }
    };

    TEST_GROUP_BASE(TSW_02, TestGroupTSH)
    {};

    //! test type: equivalence class test
    TEST(TSW_02, T01)
    {
        STEP(1)
        mSUT.toFld(123, TSW_TO_FLD_LEFT);
        CHECK_N_CLEAR()
    }
    //! test type: equivalence class test
    TEST(TSW_02, T02)
    {
        STEP(1)
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_RIGHT);
        CHECK_N_CLEAR()
    }
}