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
        mock_Com();
        I_Dispatcher& dispatcher = Dispatcher::instance();
        I_Reader& reader = Reader::instance();
        I_Provider& provider = TSW_Provider::instance();
        const CONST_C_STRING fname = "tmp.dat";
        {
            GenProjData<TEST_NUM_TSW, 0, 0, 0> projData;
            projData.dump(fname);
        }
        reader.read(fname);

        L_CHECK_EQUAL(TEST_NUM_TSW, provider.size())

        STEP(1)
        //  stimulation: send TSW field states LEFT to dispatcher
        //  expectation: GUI states LEFT to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < TEST_NUM_TSW; ++n)
        {
            LSTEP(n)
            ComTele tele{{}, {TSW_STATE_LEFT, PARAM_UNDEF}};
            nameElement(tele, TEST_NUM_TSW - n, "TSW");

            m_Com().expectToGui(tele);
            dispatcher.fromFld(tele);
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
            STEP(n)
            ComTele fromGui{{}, {TSW_GUI_CMD_WU, PARAM_UNDEF}};
            ComTele toFld{{}, {TSW_STATE_RIGHT, PARAM_UNDEF}};
            ComTele toGui{{}, {TSW_STATE_WAIT_RIGHT, PARAM_UNDEF}};
            nameElement(fromGui, TEST_NUM_TSW - n, "TSW");
            toFld.name = fromGui.name;
            toGui.name = fromGui.name;

            m_Com().expectToFld(toFld);
            m_Com().expectToGui(toGui);
            dispatcher.fromGui(fromGui);
            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
