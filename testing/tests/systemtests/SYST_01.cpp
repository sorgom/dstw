//  ============================================================
//  system tests SIG
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SYS/Reader.h>
#include <SYS/Dispatcher.h>
#include <SIG/SIG_Provider.h>
namespace test
{

    TEST_GROUP_BASE(SYST_01, TestGroupBase) {};

    //  test type: blackbox test
    TEST(SYST_01, T01)
    {
        SETUP()
        unmock();
        mock_Com();
        mock_Log();
        I_Dispatcher& dispatcher = Dispatcher::instance();
        I_Reader& reader = Reader::instance();
        I_Provider& provider = SIG_Provider::instance();

        const CONST_C_STRING fname = "tmp.dat";
        {
            GenProjData<0, TEST_NUM_SIG, 0, 0> projData;
            projData.dump(fname);
        }
        reader.read(fname);    

        L_CHECK_EQUAL(TEST_NUM_SIG, provider.size())

        STEP(1)
        //  signal type SIG_H (default)
        //  stimulation: send SIG field states H0 to dispatcher
        //  expectation: GUI states H0 to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < TEST_NUM_SIG; ++n)
        {
            STEP(n)
            ComTele tele{{}, {SIG_STATE_H0, PARAM_UNDEF}};
            nameElement(tele, TEST_NUM_SIG - n, "SIG");

            m_Com().expectToGui(tele);
            dispatcher.fromFld(tele);
            CHECK_N_CLEAR()
        }
        ENDSTEPS()

        STEP(2)
        //  stimulation: send GUI commands SIG_STATE_H1 to dispatcher
        //  expectation: 
        //  -   commands SIG_STATE_H1 to Com
        //  -   GUI states SIG_STATE_WAIT to Com
        SUBSTEPS()
        for (UINT32 n = 0; n < TEST_NUM_SIG; ++n)
        {
            STEP(n)
            ComTele fromGui{{}, {SIG_STATE_H1, PARAM_UNDEF}};
            ComTele toGui{{}, {SIG_STATE_WAIT_H1, PARAM_UNDEF}};
            nameElement(fromGui, TEST_NUM_SIG - n, "SIG");
            toGui.name = fromGui.name;

            m_Com().expectToFld(fromGui);
            m_Com().expectToGui(toGui);
            dispatcher.fromGui(fromGui);
            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }
}
