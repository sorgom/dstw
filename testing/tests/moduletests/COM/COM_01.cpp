//  ============================================================
//  test of COM TCP
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <COM/TCP.h>
#include <TCP/TCP_Client.h>

namespace test
{

    TEST_GROUP_BASE(COM_01, TestGroupBase) {};

    TEST(COM_01, T01)
    {
        I_TCP& tcp = TCP::instance();
        tcp.setTimeout(5);
        TCP_Client client;
        //  init TCP
        STEP(1)
        {
            const bool res = tcp.init();
            L_CHECK_TRUE(res);
        }
        //  create socket 1
        STEP(2)
        INT32 s1 = tcp.socket();
        L_CHECK_TRUE(s1 >= 0);

        //  bind socket 1 to port field
        //  should be ok
        STEP(3)
        {
            const bool res = tcp.bind(s1, Port_Fld);
            L_CHECK_TRUE(res);
        }

        //  bind socket 2 to same port field
        //  should fail
        STEP(4)
        {
            INT32 s2 = tcp.socket();
            L_CHECK_TRUE(s2 >= 0);
            const bool res = tcp.bind(s2, Port_Fld);
            L_CHECK_FALSE(res);
            tcp.close(s2);
            L_CHECK_TRUE(s2 < 0);
        }

        //  listen on socket 1
        //  should be ok
        STEP(5)
        {
            const bool res = tcp.listen(s1);
            L_CHECK_TRUE(res);
        }
        //  listen on invalid socket
        //  should fail
        STEP(6)
        {
            const INT32 s2 = -1;
            const bool res = tcp.listen(s2);
            L_CHECK_FALSE(res);
        }

        //  select on socket 1
        //  should be ok with no result
        STEP(7)
        {
            const INT32 res = tcp.select(s1);
            L_CHECK_EQUAL(0, res);
        }

        // select on invalid socket
        // should fail
        STEP(8)
        {
            const INT32 res = tcp.select(s1 + 100);
            L_CHECK_EQUAL(-1, res);
        }

        //  select with client connected
        //  - accept client
        //  - select on client socket
        //    - without activity
        //    - with close activity 
        STEP(9)
        {
            SUBSTEPS()
            //  connection to bound port must be ok
            STEP(1)
            const bool con = client.connect(Port_Fld);
            L_CHECK_TRUE(con);

            //  select on listener should return 1
            STEP(2)
            INT32 res = tcp.select(s1);
            L_CHECK_EQUAL(1, res);

            //  accept client must return valid socket
            STEP(3)
            INT32 s2 = tcp.accept(s1);
            L_CHECK_TRUE(s2 >= 0);

            //  no activity: select on client socket must return 0
            STEP(4)
            res = tcp.select(s2);
            L_CHECK_EQUAL(0, res);

            //  close client
            //  select on listener should return 1 for activity
            STEP(5)
            client.close();
            res = tcp.select(s2);
            L_CHECK_EQUAL(1, res);

            //  recv on client socket should return 0
            //  when client closed
            STEP(6)
            CHAR buffer[10];
            res = tcp.recv(s2, buffer, 10);
            L_CHECK_EQUAL(0, res);
            
            //  close client socket for test cleanup
            tcp.close(s2);
            ENDSTEPS()
        }

        //  accept on invalid socket
        //  should fail
        STEP(10)
        {
            const INT32 res = tcp.accept(s1 + 100);
            L_CHECK_TRUE(res < 0);
        }        

        tcp.close(s1);
        L_CHECK_TRUE(s1 < 0);

        tcp.cleanup();
    }
} // namespace
