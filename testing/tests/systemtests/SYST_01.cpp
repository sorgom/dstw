//  ============================================================
//  system tests vol. 1
//  requiring a running application (in background)
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <mocks/M_TCP_Client.h>
#include <COM/TCP.h>

#include <thread>
#include <chrono>

namespace test
{
    class TestGroupSYST : public Utest
    {
    protected:
        TestGroupSYST() = default;

        M_TCP_Client clientFld{"FLD"};
        M_TCP_Client clientGui{"GUI"};
        M_TCP_Client clientCtrl{"CTRL"};

        bool ok = false;
        INT32 res = 0;

        //  check if application is running
        void connect()
        {
            SUBSTEPS()
            STEP(1)
            ok = TCP_Client::init();
            L_CHECK_TRUE(ok)
            STEP(2)
            clientFld.connect(tcpPortFld);
            clientGui.connect(tcpPortGui);
            clientCtrl.connect(tcpPortCtrl);
            ENDSTEPS()
        }

        //  terminate all connections
        void close()
        {
            clientFld.close();
            clientGui.close();
            clientCtrl.close();
            TCP_Client::cleanup();
        }

        void setup()
        {
            connect();
        }
        
        //  check all clients for received telegrams
        void recvAll()
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            clientFld.recv();
            clientGui.recv();
            clientCtrl.recv();
        }

        inline void teardown()
        {
            close();
        }

    };

    #define SETUP_CONNECT() SETUP() if (not connect()) { close(); return; }

    TEST_GROUP_BASE(SYST_01, TestGroupSYST) {};

    //  ping pong test
    TEST(SYST_01, T01)
    {
        //  send ping telegram
        STEP(1)
        const ComTele ts{genComName(22, "PING"), { COM_CTRL_PING, COM_CTRL_PING }};
        clientCtrl.expectRecv(ts);
        clientCtrl.send(ts);
        recvAll();
        CHECK_N_CLEAR()
    }

    //  track switches 1, 11, 21, ...
    //  initial state: UNDEF
    //  STEP(1)
    //  send GUI command WU
    //  - no telegrams to field or GUI
    //  STEP(2)
    //  send switch state telegrams from field
    //  - receive identical switch state telegrams to GUI
    //  UNDEF to LEFT
    //  STEP(3)
    //  send GUI command WU
    //  - field should receive RIGHT
    //  - GUI should receive WAIT_RIGHT
    TEST(SYST_01, T02)
    {
        STEP(1)
        SUBSTEPS()
        for (UINT16 n = 1; n < TEST_NUM_TSW; n += 10)
        {
            STEP(n)
            const ComName cname {genComName(n, "TSW")};
            const ComTele txgs{cname, { TSW_CMD_WU, PARAM_UNDEF }};
            clientGui.send(txgs);
            recvAll();
            CHECK_N_CLEAR()
        }
        ENDSTEPS()

        STEP(2)
        SUBSTEPS()
        for (UINT16 n = 1; n < TEST_NUM_TSW; n += 10)
        {
            STEP(n)
            const ComName cname {genComName(n, "TSW")};
            const ComTele txf{cname, { TSW_STATE_LEFT, PARAM_UNDEF }};
            clientGui.expectRecv(txf);
            clientFld.send(txf);
            recvAll();
            CHECK_N_CLEAR()
        }
        ENDSTEPS()

        STEP(3)
        SUBSTEPS()
        for (UINT16 n = 1; n < TEST_NUM_TSW; n += 10)
        {
            STEP(n)
            const ComName cname {genComName(n, "TSW")};
            const ComTele txgs{cname, { TSW_CMD_WU, PARAM_UNDEF }};
            const ComTele txfr{cname, { TSW_STATE_RIGHT, PARAM_UNDEF }};
            const ComTele txgr{cname, { TSW_STATE_WAIT_RIGHT, PARAM_UNDEF }};
            clientFld.expectRecv(txfr);
            clientGui.expectRecv(txgr);
            clientGui.send(txgs);
            recvAll();
            CHECK_N_CLEAR()
        }
        ENDSTEPS()
    }

    //  this is a heavy one
    //  call for reGui
    TEST(SYST_01, T03)
    {
        STEP(1)
        clientGui.expectRecv(TEST_NUM_TSW + TEST_NUM_SIG + TEST_NUM_LCR);
        clientCtrl.send(ComTele{{}, { COM_CTRL_RE_GUI, COM_CTRL_RE_GUI }});
        recvAll();
        CHECK_N_CLEAR()
    }

}
