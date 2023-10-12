#include <testlib/CppUTest.h>
#include <testlib/TestGroupBase.h>
#include <mocks/M_Instances.h>

#include <TrackSwitch/TrackSwitch.h>

namespace test
{
    class TestGroupTSW : public TestGroupBase
    {
    protected:
        const UINT32 mId = 12345;
        TrackSwitch mSUT;
        M_TrackSwitchPort& mPort;

        inline TestGroupTSW():
            mSUT(mId),
            mPort(m_TrackSwitchPort())
        {
            mock_TrackSwitchPort();
        }
    };

    TEST_GROUP_BASE(TSW, TestGroupTSW)
    {};

    //! test type: equivalence class test
    //! TrackSwitch transitions & reactions pt. 1
    TEST(TSW, T01)
    {
        SETUP()
        STEP(1)
        //  stimulation: WU() to initial state
        //  reaction   : none
        mSUT.WU();
        CHECK_N_CLEAR()

        STEP(2)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT
        mPort.expectToGui(mId, TSW_TO_GUI_LEFT);
        mSUT.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(3)
        //  stimulation: WU()
        //  reaction   :
        //      cmd to field: RIGHT
        //      cmd to GUI: WAIT_RIGHT
        mPort.expectToFld(mId, TSW_TO_FLD_RIGHT);
        mPort.expectToGui(mId, TSW_TO_GUI_WAIT_RIGHT);
        mSUT.WU();
        CHECK_N_CLEAR()

        STEP(4)
        //  stimulation: WU() repeated
        //  reaction   : none
        mSUT.WU();
        CHECK_N_CLEAR()

        STEP(5)
        //  stimulation: feedback from field: RIGHT
        //  reaction   : cmd to GUI: RIGHT
        mPort.expectToGui(mId, TSW_TO_GUI_RIGHT);
        mSUT.fromFld(TSW_FROM_FLD_RIGHT);
        CHECK_N_CLEAR()

        STEP(6)
        //  stimulation: WU()
        //  reaction   :
        //      cmd to field: LEFT
        //      cmd to GUI: WAIT_LEFT
        mPort.expectToFld(mId, TSW_TO_FLD_LEFT);
        mPort.expectToGui(mId, TSW_TO_GUI_WAIT_LEFT);
        mSUT.WU();
        CHECK_N_CLEAR()

        STEP(7)
        //  stimulation: WU() repeated
        //  reaction   : none
        mSUT.WU();
        CHECK_N_CLEAR()

        STEP(8)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT
        mPort.expectToGui(mId, TSW_TO_GUI_LEFT);
        mSUT.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(9)
        //  stimulation: feedback from field: LEFT repeated
        //  reaction   : none
        mPort.expectToGui(mId, TSW_TO_GUI_LEFT);
        mSUT.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()
    }

}