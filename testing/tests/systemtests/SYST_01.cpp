//  ============================================================
//  system tests vol. 1
//  requiring a running application (in background)
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/CppUTest.h>

#include <codebase/Mem.h>
#include <comparators/ostreams.h>
#include <ifs/values.h>
#include <testlib/TestLib.h>
#include <testlib/testValues.h>
#include <TestSteps/TestSteps.h>

#include <TCP/TCP_Client.h>

#include <iostream>
using std::cerr, std::endl;

namespace test
{
    class TestGroupSYST : public Utest
    {
    protected:
        TestGroupSYST() = default;
        TCP_Client clientFld;
        TCP_Client clientGui;
        TCP_Client clientCtrl;
        bool ok = false;
        INT32 res = 0;

        //  check if application is running
        void connect()
        {
            SUBSTEPS()
            STEP(1)
            const bool ok = 
                clientFld.connect(tcpPortFld) and
                clientGui.connect(tcpPortGui) and
                clientCtrl.connect(tcpPortCtrl);

            L_CHECK_TRUE(ok)
            ENDSTEPS()
        }

        //  terminate all connections
        void close()
        {
            clientFld.close();
            clientGui.close();
            clientCtrl.close();
        }

        void setup()
        {
            connect();
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
        ok = clientCtrl.send(ts);
        L_CHECK_TRUE(ok)

        //  receive pong telegram
        STEP(2)
        ComTele tr;
        ok = clientCtrl.recv(tr);
        L_CHECK_TRUE(ok)
        res = Mem::cmp(tr, ts);
        L_CHECK_EQUAL(0, res)
    }

    //  switch a track switch state from field
    TEST(SYST_01, T02)
    {
        //  send switch state telegram from field
        STEP(1)
        const ComTele ts{genComName(1, "TSW"), { TSW_STATE_LEFT, PARAM_UNDEF }};
        ok = clientFld.send(ts);
        L_CHECK_TRUE(ok)

        //  receive switch state telegram to GUI
        STEP(2)
        ComTele tr;
        ok = clientGui.recv(tr);
        L_CHECK_TRUE(ok)
        res = Mem::cmp(tr, ts);
        L_CHECK_EQUAL(0, res)
    }

    //  switch a track switch state from GUI
    TEST(SYST_01, T03)
    {
        //  send switch state telegram from GUI
        STEP(1)
        const ComName cname {genComName(2, "TSW")};
        ok = clientGui.send(ComTele{cname, { TSW_CMD_RIGHT, PARAM_UNDEF }});
        L_CHECK_TRUE(ok)

        //  receive switch state telegram to field
        //  receive wait state telegram to GUI
        STEP(2)
        const ComTele txf{cname, { TSW_STATE_RIGHT, PARAM_UNDEF }};
        const ComTele txg{cname, { TSW_STATE_WAIT_RIGHT, PARAM_UNDEF }};
        ComTele tr;
        
        ok = clientFld.recv(tr);
        L_CHECK_TRUE(ok)
        res = Mem::cmp(tr, txf);
        L_CHECK_EQUAL(0, res)

        ok = clientGui.recv(tr);
        L_CHECK_TRUE(ok)
        res = Mem::cmp(tr, txg);
        L_CHECK_EQUAL(0, res)
    }
}
