//  ============================================================
//  system tests vol. 1: TSW
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

#include <qnd/useCout.h>

namespace test
{

    TEST_GROUP_BASE(SYS_01, TestGroupBase) {};

    //  test type: blackbox test
    //  
    TEST(SYS_01, T01)
    {
        SETUP()
        GenProjData<CAPACITY_TSW> projData;
        mock_FldCom();
        mock_GuiCom();
        ddi::getLoader().load(projData);

        L_CHECK_TRUE(ddi::getTSW_Provider().has(CAPACITY_TSW - 1))

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
        //  expectation: GUI states LEFT to GuiCom
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_TSW; ++n)
        {
            LSTEP(n)
            genElementName(fldState.name, CAPACITY_TSW - n, "TSW");
            fldState.state1 = TSW_STATE_LEFT;

            Mem::copy(stateGui.name, fldState.name);
            stateGui.state1 = TSW_STATE_LEFT;

            m_GuiCom().expectSend(stateGui);
            ddi::getDispatcher().dispatch(fldState);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()

        STEP(2)
        //  stimulation: send GUI commands WU to dispatcher
        //  expectation: 
        //  -   commands RIGHT to FldCom
        //  -   GUI states WAIT_RIGHT to GuiCom
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_TSW; ++n)
        {
            LSTEP(n)
            genElementName(guiCmd.name, CAPACITY_TSW - n, "TSW");
            guiCmd.cmd1 = TSW_GUI_GMD_WU;

            Mem::copy(cmdFld.name, guiCmd.name);
            cmdFld.cmd1 = TSW_STATE_RIGHT;

            Mem::copy(stateGui.name, guiCmd.name);
            stateGui.state1 = TSW_STATE_WAIT_RIGHT;

            m_FldCom().expectSend(cmdFld);
            m_GuiCom().expectSend(stateGui);
            ddi::getDispatcher().dispatch(guiCmd);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
