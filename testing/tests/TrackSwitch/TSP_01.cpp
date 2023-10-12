#include <testlib/CppUTest.h>
#include <testlib/TestGroupBase.h>
#include <mocks/M_Instances.h>

#include <TrackSwitch/TrackSwitchPort.h>
#include <baselib/Mem.h>
#include <iostream>
using std::cout;
using std::endl;

namespace test
{
    class TestGroupTSP : public TestGroupBase
    {
    protected:
        TrackSwitchPort mSUT;
        M_RastaPort& mPort;
        // static RastaTelegram mTele;
        RastaTelegram mTele;

        inline TestGroupTSP():
            mPort(m_RastaPort())
        {
            mock_RastaPort();
            Mem::zero(mTele);
            mTele.type = RASTA_TSW;
        }
    };

    // RastaTelegram TestGroupTSP::mTele = {0};

    TEST_GROUP_BASE(TSP, TestGroupTSP)
    {};

    //! test type: equivalence class test
    TEST(TSP, T01)
    {
        STEP(1)
        mTele.id = 123;
        mTele.state1 = TSW_TO_FLD_RIGHT;
        mPort.expectSend(mTele);
        mSUT.toFld(123, TSW_TO_FLD_LEFT);
        CHECK_N_CLEAR()
    }
    //! test type: equivalence class test
    TEST(TSP, T02)
    {
        STEP(1)
        mTele.id = 123;
        mTele.state1 = TSW_TO_FLD_RIGHT;
        mPort.expectSend(mTele);
        mPort.expectSend(mTele);
        mSUT.toFld(123, TSW_TO_FLD_RIGHT);
        CHECK_N_CLEAR()
    }
}