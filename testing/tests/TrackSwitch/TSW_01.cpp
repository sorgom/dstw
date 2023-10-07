#include <testenv/CppUTest.h>
#include <testenv/TestGroupBase.h>
#include <mocks/M_TrackSwitchToField.h>
#include <mocks/M_TrackSwitchToGui.h>

#include <TrackSwitch/TrackSwitch.h>

namespace test
{
    class TestGroupTSW : public TestGroupBase
    {
    protected:
        M_TrackSwitchToField mTrackSwitchToField;
        M_TrackSwitchToGui   mTrackSwitchToGui;
        TrackSwitch mTrackSwitch;

        inline TestGroupTSW():
            mTrackSwitch(
                mTrackSwitchToField,
                mTrackSwitchToGui
            )
        {}
    };

    TEST_GROUP_BASE(TSW, TestGroupTSW)
    {};

    TEST(TSW, T01)
    {
        SETUP()
        STEP(1)
        //  stimulation: WU() to initial state
        //  reaction   : none
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(2)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT       
        mTrackSwitchToGui.expectCmd(TSW_TO_GUI_LEFT);
        mTrackSwitch.rcv(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(3)
        //  stimulation: WU()
        //  reaction   : 
        //      cmd to field: RIGHT
        //      cmd to GUI: WAIT_RIGHT
        mTrackSwitchToField.expectCmd(TSW_TO_FLD_RIGHT);
        mTrackSwitchToGui.expectCmd(TSW_TO_GUI_WAIT_RIGHT);
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(4)
        //  stimulation: WU() repeated
        //  reaction   : none
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(5)
        //  stimulation: WU() repeated
        //  reaction   : none
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(6)
        //  stimulation: feedback from field: RIGHT
        //  reaction   : cmd to GUI: RIGHT       
        mTrackSwitchToGui.expectCmd(TSW_TO_GUI_RIGHT);
        mTrackSwitch.rcv(TSW_FROM_FLD_RIGHT);
        CHECK_N_CLEAR()

        STEP(7)
        //  stimulation: WU()
        //  reaction   : 
        //      cmd to field: LEFT
        //      cmd to GUI: WAIT_LEFT
        mTrackSwitchToField.expectCmd(TSW_TO_FLD_LEFT);
        mTrackSwitchToGui.expectCmd(TSW_TO_GUI_WAIT_LEFT);
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(8)
        //  stimulation: WU() repeated
        //  reaction   : none
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(9)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT       
        mTrackSwitchToGui.expectCmd(TSW_TO_GUI_LEFT);
        mTrackSwitch.rcv(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        //  This test fails: second feedback of same type
        STEP(10)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT       
        mTrackSwitchToGui.expectCmd(TSW_TO_GUI_LEFT);
        mTrackSwitch.rcv(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()
    }

}