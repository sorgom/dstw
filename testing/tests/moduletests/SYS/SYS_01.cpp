//  ============================================================
//  test of module Reader, Log
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <SYS/Reader.h>
#include <SYS/Log.h>

namespace test
{
    class TestGroupRDR : public TestGroupBase
    {
    protected:
        static const CONST_C_STRING fname;
        void expectClear()
        {
            m_Dispatcher().expectClear();
            m_TSW_Provider().expectClear();
            m_SIG_Provider().expectClear();
            m_LCR_Provider().expectClear();
        }
        void expectFail()
        {
            expectClear();
            m_Log().expectLog(COMP_SYS, RET_ERR_STARTUP);
        }

        void wrongSize(int dev, const UINT32 n = 1)
        {
            std::ofstream os(fname, std::ios::binary);
            const UINT32 nums[] = { n, n, n, n };
            os.write(reinterpret_cast<const CHAR*>(nums), 4 * sizeof(UINT32));

            const size_t wSize = sizeof(ProjItem) * n * 4 + sizeof(ComSetup) + dev;

            for (size_t i = 0; i < wSize; ++i)
            {
                os << ' ';
            }
            os.close();
            expectFail();
            Reader::instance().read(fname);
        }
    };

    const CONST_C_STRING TestGroupRDR::fname = "tmp.dat";


    TEST_GROUP_BASE(SYS_01, TestGroupRDR) {};

    //  test type: equivalence class test
    //  successfully load data
    TEST(SYS_01, T01)
    {
        SETUP()
        I_Reader& rdr = Reader::instance();

        STEP(1)
        expectClear();
        GenProjData<> data;
        m_TSW_Provider().expectLoad(data.numTSW());
        m_SIG_Provider().expectLoad(data.numSIG());
        m_LCR_Provider().expectLoad(data.numLCR());
        m_Dispatcher().expectIndex();
        data.dump(fname);
        rdr.read(fname);
        CHECK_N_CLEAR()

        STEP(2)
        const ComSetup& cs = rdr.getComSetup();
        L_CHECK_EQUAL(tcpPortFld,  cs.portFld)
        L_CHECK_EQUAL(tcpPortGui,  cs.portGui)
        L_CHECK_EQUAL(tcpPortCtrl, cs.portCtrl)
        L_CHECK_EQUAL(tcpTimeout,  cs.timeout)
    }

    //  test type: equivalence class test
    //  failure: file does not exist
    TEST(SYS_01, T02)
    {
        SETUP()
        I_Reader& rdr = Reader::instance();

        STEP(1)
        expectFail();
        rdr.read("does_not_exist.dat");
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  failure: file size mismatch
    TEST(SYS_01, T03)
    {
        STEP(1)
        //  too small
        wrongSize(-1);
        CHECK_N_CLEAR()

        STEP(2)
        //  too large
        wrongSize(+1);
        CHECK_N_CLEAR()

        STEP(3)
        //  no data
        wrongSize(0, 0);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  failure: file smaller than header
    TEST(SYS_01, T04)
    {
        SETUP()
        I_Reader& rdr = Reader::instance();

        std::ofstream os(fname, std::ios::binary);
        for (size_t n = 0; n < 4 * sizeof(UINT32) - 1; ++n)
        {
            os << ' ';
        }
        os.close();

        STEP(1)
        expectFail();
        rdr.read(fname);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  log instance, log, maxerr
    TEST(SYS_01, T05)
    {
        STEP(1)
        I_Log& logm = Log::instance();
        logm.log(COMP_SYS, RET_ERR_MATCH);
        logm.log(COMP_SYS, RET_ERR_STARTUP);

        STEP(2)
        const I_Log& logc = Log::instance();
        const E_Ret ret = logc.maxerr();
        L_CHECK_EQUAL(RET_ERR_STARTUP, ret)
    }
}
