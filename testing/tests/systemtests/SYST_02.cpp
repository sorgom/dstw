//  ============================================================
//  system tests TSW
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(SYST_02, TestGroupBase) {};

    //  test type: blackbox test
    //  
    TEST(SYST_02, T01)
    {
        SETUP()
        GenProjData<CAPACITY_TSW> projData;
        unmock();
        mock_Com();
        IL::getLoader().load(projData);

        L_CHECK_TRUE(IL::getTSW_Provider().has(CAPACITY_TSW - 1))

        FldState fldState;
        StateGui stateGui;
        GuiCmd   guiCmd;
        CmdFld   cmdFld;

        Mem::zero(fldState);
        Mem::zero(stateGui);
        Mem::zero(guiCmd);
        Mem::zero(cmdFld);

        STEP(1)
        //  stimulation: send TSW field states LEFT to dispatcher
        //  expectation: GUI states LEFT to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_TSW; ++n)
        {
            LSTEP(n)
            nameElement(fldState, CAPACITY_TSW - n, "TSW");
            fldState.state1 = TSW_STATE_LEFT;

            Mem::cpy(stateGui.name, fldState.name);
            stateGui.state1 = TSW_STATE_LEFT;

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
        for (UINT32 n = 0; n < CAPACITY_TSW; ++n)
        {
            LSTEP(n)
            nameElement(guiCmd, CAPACITY_TSW - n, "TSW");
            guiCmd.cmd1 = TSW_GUI_GMD_WU;

            Mem::cpy(cmdFld.name, guiCmd.name);
            cmdFld.cmd1 = TSW_STATE_RIGHT;

            Mem::cpy(stateGui.name, guiCmd.name);
            stateGui.state1 = TSW_STATE_WAIT_RIGHT;

            m_Com().expectSend(cmdFld);
            m_Com().expectSend(stateGui);
            IL::getDispatcher().dispatch(guiCmd);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
