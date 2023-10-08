#include <testenv/CppUTest.h>
#include <testenv/TestGroupBase.h>
#include <mocks/M_TrackSwitchPort.h>

#include <TrackSwitch/TrackSwitch.h>

namespace test
{
    class TestGroupTSW : public TestGroupBase
    {
    protected:
        M_TrackSwitchPort mTrackSwitchPort;
        TrackSwitch mTrackSwitch;

        inline TestGroupTSW():
            mTrackSwitch(mTrackSwitchPort)
        {}
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
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(2)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT
        mTrackSwitchPort.expectToGui(TSW_TO_GUI_LEFT);
        mTrackSwitch.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(3)
        //  stimulation: WU()
        //  reaction   :
        //      cmd to field: RIGHT
        //      cmd to GUI: WAIT_RIGHT
        mTrackSwitchPort.expectToFld(TSW_TO_FLD_RIGHT);
        mTrackSwitchPort.expectToGui(TSW_TO_GUI_WAIT_RIGHT);
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(4)
        //  stimulation: WU() repeated
        //  reaction   : none
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(5)
        //  stimulation: feedback from field: RIGHT
        //  reaction   : cmd to GUI: RIGHT
        mTrackSwitchPort.expectToGui(TSW_TO_GUI_RIGHT);
        mTrackSwitch.fromFld(TSW_FROM_FLD_RIGHT);
        CHECK_N_CLEAR()

        STEP(6)
        //  stimulation: WU()
        //  reaction   :
        //      cmd to field: LEFT
        //      cmd to GUI: WAIT_LEFT
        mTrackSwitchPort.expectToFld(TSW_TO_FLD_LEFT);
        mTrackSwitchPort.expectToGui(TSW_TO_GUI_WAIT_LEFT);
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(7)
        //  stimulation: WU() repeated
        //  reaction   : none
        mTrackSwitch.WU();
        CHECK_N_CLEAR()

        STEP(8)
        //  stimulation: feedback from field: LEFT
        //  reaction   : cmd to GUI: LEFT
        mTrackSwitchPort.expectToGui(TSW_TO_GUI_LEFT);
        mTrackSwitch.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(9)
        //  stimulation: feedback from field: LEFT repeated
        //  reaction   : none
        mTrackSwitchPort.expectToGui(TSW_TO_GUI_LEFT);
        mTrackSwitch.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()
    }

}