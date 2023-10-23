//  ============================================================
//  system tests vol. 1
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
        GenProjData<> projData;
        mock_FldCom();
        mock_GuiCom();
        ddi::getLoader().load(projData);

        L_CHECK_TRUE(ddi::getTSW_Provider().has(CAPACITY_TSW - 1))

        STEP(1)
        //  stimulation: send TSW field states LEFT to dispatcher
        //  expectation: GUI stats LEFT to GuiCom
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_TSW; ++n)
        {
            LSTEP(n)
            FldState fldState;
            genElementName(fldState.name, CAPACITY_TSW - n, "TSW");
            fldState.state = TSW_FROM_FLD_LEFT;

            StateGui stateGui;
            Mem::copy(stateGui.name, fldState.name);
            stateGui.state = TSW_TO_GUI_LEFT;

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
            GuiCmd guiCmd;
            genElementName(guiCmd.name, CAPACITY_TSW - n, "TSW");
            guiCmd.cmd = TSW_GUI_GMD_WU;

            CmdFld cmdFld;
            Mem::copy(cmdFld.name, guiCmd.name);
            cmdFld.cmd = TSW_TO_FLD_RIGHT;

            StateGui stateGui;
            Mem::copy(stateGui.name, guiCmd.name);
            stateGui.state = TSW_TO_GUI_WAIT_RIGHT;

            m_FldCom().expectSend(cmdFld);
            m_GuiCom().expectSend(stateGui);
            ddi::getDispatcher().dispatch(guiCmd);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
