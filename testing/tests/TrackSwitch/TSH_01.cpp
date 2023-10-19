#include <testlib/TestGroupBase.h>
#include <TrackSwitch/TrackSwitchHub.h>

namespace test
{
    class TestGroupTSH : public TestGroupBase
    {
    protected:
        TrackSwitchHub mSUT;
        M_FldCom& mCom;
        CmdFld mTele;

        inline TestGroupTSH():
            mCom(m_FldCom())
        {
            mock_FldCom();
            Mem::zero(mTele);
        }
    };

    TEST_GROUP_BASE(TSH_01, TestGroupTSH)
    {};

    //! test type: equivalence class test
    TEST(TSH_01, T01)
    {
        STEP(1)
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_LEFT);
        CHECK_N_CLEAR()
    }
    //! test type: equivalence class test
    TEST(TSH_01, T02)
    {
        STEP(1)
        mCom.expectSend();
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_RIGHT);
        CHECK_N_CLEAR()
    }
}