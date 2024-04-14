//  ============================================================
//  system tests TSW
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

namespace test
{

    TEST_GROUP_BASE(SYST_02, TestGroupBase) {};

    //  test type: blackbox test
    //  
    TEST(SYST_02, T01)
    {
        SETUP()
        unmock();
        mock_Com();
        const CONST_C_STRING fname = "tmp.dat";
        {
            GenProjData<TEST_NUM_TSW> projData;
            projData.dump(fname);
        }
        IL::getReader().read(fname);

        L_CHECK_TRUE(IL::getTSW_Provider().has(TEST_NUM_TSW - 1))

        STEP(1)
        //  stimulation: send TSW field states LEFT to dispatcher
        //  expectation: GUI states LEFT to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < TEST_NUM_TSW; ++n)
        {
            LSTEP(n)
            ComFldState fldState(TSW_STATE_LEFT);
            nameElement(fldState, TEST_NUM_TSW - n, "TSW");

            ComStateGui stateGui(TSW_STATE_LEFT);
            stateGui.name = fldState.name;

            m_Com().expectSend(stateGui);
            IL::getDispatcher().dispatch(fldState);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()

        STEP(2)
        //  stimulation: send GUI commands WU to dispatcher
        //  expectation: 
        //  -   commands RIGHT to Com
        //  -   GUI states WAIT_RIGHT to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < TEST_NUM_TSW; ++n)
        {
            LSTEP(n)
            ComGuiCmd guiCmd(TSW_GUI_GMD_WU);
            nameElement(guiCmd, TEST_NUM_TSW - n, "TSW");

            ComCmdFld cmdFld(TSW_STATE_RIGHT);
            cmdFld.name = guiCmd.name;

            ComStateGui stateGui(TSW_STATE_WAIT_RIGHT);
            stateGui.name = guiCmd.name;

            m_Com().expectSend(cmdFld);
            m_Com().expectSend(stateGui);
            IL::getDispatcher().dispatch(guiCmd);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
