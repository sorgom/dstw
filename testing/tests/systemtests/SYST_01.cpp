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
        unmock();
        mock_Com();
        const CONST_C_STRING fname = "tmp.dat";
        {
            GenProjData<1, CAPACITY_SIG> projData;
            projData.dump(fname);
        }
        IL::getReader().read(fname);    

        L_CHECK_TRUE(IL::getSIG_Provider().has(CAPACITY_SIG - 1))

        STEP(1)
        //  signal type SIG_H (default)
        //  stimulation: send SIG field states H0 to dispatcher
        //  expectation: GUI states H0 to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < CAPACITY_SIG; ++n)
        {
            LSTEP(n)
            ComFldState fldState(SIG_STATE_H0);
            nameElement(fldState, CAPACITY_SIG - n, "SIG");

            ComStateGui stateGui(SIG_STATE_H0);
            stateGui.name = fldState.name;

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
            ComGuiCmd guiCmd(SIG_STATE_H1);
            nameElement(guiCmd, CAPACITY_SIG - n, "SIG");

            ComCmdFld cmdFld(SIG_STATE_H1);
            cmdFld.name = guiCmd.name;

            ComStateGui stateGui(SIG_STATE_WAIT_H1);
            stateGui.name = guiCmd.name;

            m_Com().expectSend(cmdFld);
            m_Com().expectSend(stateGui);
            IL::getDispatcher().dispatch(guiCmd);

            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
