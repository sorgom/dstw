#include <testlib/TestGroupBase.h>
#include <TSW/TSW_Hub.h>

namespace test
{
    class TestGroupTSH : public TestGroupBase
    {
    protected:
        TSW_Hub mSUT;
        M_FldCom& mCom;
        CmdFld mTele;

        inline TestGroupTSH():
            mCom(m_FldCom())
        {
            mock_FldCom();
            Mem::zero(mTele);
        }
    };

    TEST_GROUP_BASE(TSW_02, TestGroupTSH)
    {};

    //! test type: equivalence class test
    TEST(TSW_02, T01)
    {
        STEP(1)
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_LEFT);
        CHECK_N_CLEAR()
    }
    //! test type: equivalence class test
    TEST(TSW_02, T02)
    {
        STEP(1)
        mCom.expectSend();
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_RIGHT);
        CHECK_N_CLEAR()
    }
}