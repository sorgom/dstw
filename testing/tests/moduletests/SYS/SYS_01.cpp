//  ============================================================
//  test of module Reader
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Reader.h>

namespace test
{
    class TestGroupRDR : public TestGroupBase
    {
    protected:
        Reader mSUT;
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
            m_Log().expectLog(COMP_SYS, ERR_STARTUP);
        }

        void wrongSize(int dev)
        {
            std::ofstream os(fname, std::ios::binary);
            constexpr static const UINT32 nums[] = { 1, 1, 1, 1 };
            os.write(reinterpret_cast<const CHAR*>(nums), 4 * sizeof(UINT32));

            constexpr static const size_t wSize = sizeof(ProjItem) * 4;

            for (size_t n = 0; n < wSize + dev; ++n)
            {
                os << ' ';
            }
            os.close();
            expectFail();
            mSUT.read(fname);
        }
    };

    const CONST_C_STRING TestGroupRDR::fname = "tmp.dat";


    TEST_GROUP_BASE(SYS_01, TestGroupRDR) {};

    //  test type: equivalence class test
    //  successfully load data 
    TEST(SYS_01, T01)
    {
        STEP(1)
        expectClear();
        GenProjData<> data;
        m_TSW_Provider().expectLoad(data.numTSW());
        m_SIG_Provider().expectLoad(data.numSIG());
        m_LCR_Provider().expectLoad(data.numLCR());
        m_Dispatcher().expectIndex();
        data.dump(fname);
        mSUT.read(fname);
        CHECK_N_CLEAR()
    }

    //  test type: equivalence class test
    //  failure: file does not exist 
    TEST(SYS_01, T02)
    {
        STEP(1)
        expectFail();
        mSUT.read("does_not_exist.dat");
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
    }

    //  test type: equivalence class test
    //  failure: file smaller than header
    TEST(SYS_01, T04)
    {
        SETUP()
        std::ofstream os(fname, std::ios::binary);
        for (size_t n = 0; n < 4 * sizeof(UINT32) - 1; ++n)
        {
            os << ' ';
        }
        os.close();

        STEP(1)
        expectFail();
        mSUT.read(fname);
        CHECK_N_CLEAR()
    }

    //  test type: coverage
    //  retrieve instance
    TEST(SYS_01, T05)
    {
        I_Reader& inst = Reader::instance();
        play(inst);
    }
}