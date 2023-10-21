//  ============================================================
//  test of module TSW
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <TSW/TSW.h>

namespace test
{
    class TestGroupTSW : public TestGroupBase
    {
    protected:
        const UINT32 mId;
        TSW mSUT;
        M_TSW_Hub& mHub;

        inline TestGroupTSW():
            mId(12345),
            mSUT(mId),
            mHub(m_TSW_Hub())
        {
            mock_TSW_Hub();
        }
    };

    TEST_GROUP_BASE(TSW_01, TestGroupTSW)
    {};

    //  test type: equivalence class test
    //  TSW transitions & reactions pt. 1
    TEST(TSW_01, T01)
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
        mHub.expectToGui(mId, TSW_TO_GUI_LEFT);
        mSUT.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(3)
        //  stimulation: WU()
        //  reaction   :
        //      cmd to field: RIGHT
        //      cmd to GUI: WAIT_RIGHT
        mHub.expectToFld(mId, TSW_TO_FLD_RIGHT);
        mHub.expectToGui(mId, TSW_TO_GUI_WAIT_RIGHT);
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
        mHub.expectToGui(mId, TSW_TO_GUI_RIGHT);
        mSUT.fromFld(TSW_FROM_FLD_RIGHT);
        CHECK_N_CLEAR()

        STEP(6)
        //  stimulation: WU()
        //  reaction   :
        //      cmd to field: LEFT
        //      cmd to GUI: WAIT_LEFT
        mHub.expectToFld(mId, TSW_TO_FLD_LEFT);
        mHub.expectToGui(mId, TSW_TO_GUI_WAIT_LEFT);
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
        mHub.expectToGui(mId, TSW_TO_GUI_LEFT);
        mSUT.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()

        STEP(9)
        //  stimulation: feedback from field: LEFT repeated
        //  reaction   : none
        mSUT.fromFld(TSW_FROM_FLD_LEFT);
        CHECK_N_CLEAR()
    }

}