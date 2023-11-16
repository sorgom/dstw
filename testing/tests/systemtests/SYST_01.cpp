//  ============================================================
//  system tests SIG
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>

namespace test
{

    TEST_GROUP_BASE(SYST_01, TestGroupBase) {};

    //  test type: blackbox test
    //  
    TEST(SYST_01, T01)
    {
        SETUP()
        GenProjData<1, CAPACITY_SIG> projData;
        unmock();
        mock_Com();
        IL::getLoader().load(projData);

        L_CHECK_TRUE(IL::getSIG_Provider().has(CAPACITY_SIG - 1))

        FldState fldState;
        StateGui stateGui;
        GuiCmd   guiCmd;
        CmdFld   cmdFld;

        Mem::zero(fldState);
        Mem::zero(stateGui);
        Mem::zero(guiCmd);
        Mem::zero(cmdFld);

        STEP(1)
        //  signal type SIG_H (default)
        //  stimulation: send SIG field states H0 to dispatcher
        //  expectation: GUI states H0 to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_SIG; ++n)
        {
            LSTEP(n)
            nameElement(fldState, CAPACITY_SIG - n, "SIG");
            fldState.state1 = SIG_STATE_H0;

            Mem::cpy(stateGui.name, fldState.name);
            stateGui.state1 = SIG_STATE_H0;

            m_Com().expectSend(stateGui);
            IL::getDispatcher().dispatch(fldState);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()

        STEP(2)
        //  stimulation: send GUI commands SIG_STATE_H1 to dispatcher
        //  expectation: 
        //  -   commands SIG_STATE_H1 to Com
        //  -   GUI states SIG_STATE_WAIT to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_SIG; ++n)
        {
            LSTEP(n)
            nameElement(guiCmd, CAPACITY_SIG - n, "SIG");
            guiCmd.cmd1 = SIG_STATE_H1;

            Mem::cpy(cmdFld.name, guiCmd.name);
            cmdFld.cmd1 = SIG_STATE_H1;

            Mem::cpy(stateGui.name, guiCmd.name);
            stateGui.state1 = SIG_STATE_WAIT_H1;

            m_Com().expectSend(cmdFld);
            m_Com().expectSend(stateGui);
            IL::getDispatcher().dispatch(guiCmd);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
