#include <testlib/CppUTest.h>
#include <testlib/TestGroupBase.h>
#include <mocks/M_Instances.h>

#include <TrackSwitch/TrackSwitchPort.h>
#include <baselib/Mem.h>

namespace test
{
    class TestGroupTSP : public TestGroupBase
    {
    protected:
        TrackSwitchPort mSUT;
        M_FldCom& mCom;
        // static RastaTelegram mTele;
        FldTelegram mTele;

        inline TestGroupTSP():
            mCom(m_FldCom())
        {
            mock_FldCom();
            Mem::zero(mTele);
        }
    };

    TEST_GROUP_BASE(TSP_01, TestGroupTSP)
    {};

    //! test type: equivalence class test
    TEST(TSP_01, T01)
    {
        STEP(1)
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_LEFT);
        CHECK_N_CLEAR()
    }
    //! test type: equivalence class test
    TEST(TSP_01, T02)
    {
        STEP(1)
        mCom.expectSend();
        mCom.expectSend();
        mSUT.toFld(123, TSW_TO_FLD_RIGHT);
        CHECK_N_CLEAR()
    }
}