//  ============================================================
//  test of COM TCP base
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <COM/TCP.h>
#include <TCP/TCP_Client.h>
#include <ifs/DataTypes.h>

namespace test
{

    TEST_GROUP_BASE(COM_01, TestGroupBase) {};

    TEST(COM_01, T01)
    {
        I_TCP& tcp = TCP::instance();
        tcp.setTimeout(5);
        TCP_Client client;
        INT32 res = 0;
        bool ok = false;
        CHAR buffer[sizeof(ComTele) + 10];

        INT32 s1 = -1, s2 = -1;

        //  init TCP
        STEP(1)
        ok = tcp.init();
        L_CHECK_TRUE(ok);
        
        //  create socket 1
        STEP(2)
        s1 = tcp.socket();
        L_CHECK_TRUE(s1 >= 0);

        //  bind socket 1 to port field
        //  should be ok
        STEP(3)
        ok = tcp.bind(s1, tcpPortFld);
        L_CHECK_TRUE(ok);

        //  bind socket 2 to same port field
        //  should fail
        STEP(4)
        s2 = tcp.socket();
        L_CHECK_TRUE(s2 >= 0);
        ok = tcp.bind(s2, tcpPortFld);
        L_CHECK_FALSE(ok);
        tcp.close(s2);
        L_CHECK_TRUE(s2 < 0);

        //  listen on socket 1
        //  should be ok
        STEP(5)
        ok = tcp.listen(s1);
        L_CHECK_TRUE(ok);

        //  listen on invalid socket
        //  should fail
        STEP(6)
        s2 = -1;
        ok = tcp.listen(s2);
        L_CHECK_FALSE(ok);

        //  select on socket 1
        //  should be ok with no result
        STEP(7)
        res = tcp.select(s1);
        L_CHECK_EQUAL(0, res);

        // select on invalid socket
        // should fail
        STEP(8)
        res = tcp.select(s1 + 100);
        L_CHECK_EQUAL(-1, res);

        //  select with client connected
        //  - accept client
        //  - select on client socket
        //    - without activity
        //    - with close activity 
        
        //  connection to bound port must be ok
        STEP(9)
        const bool con = client.connect(tcpPortFld);
        L_CHECK_TRUE(con);

        //  select on listener should return 1
        STEP(10)
        res = tcp.select(s1);
        L_CHECK_EQUAL(1, res);

        //  accept client must return valid socket
        STEP(11)
        s2 = tcp.accept(s1);
        L_CHECK_TRUE(s2 >= 0);

        //  no activity: select on client socket must return 0
        STEP(12)
        res = tcp.select(s2);
        L_CHECK_EQUAL(0, res);

        //  client sends data: 1 ComTele
        STEP(13)
        const ComTele tele{};
        ok = client.send(tele);
        L_CHECK_TRUE(ok);

        //  select on client socket should return 1 for activity
        STEP(14)
        res = tcp.select(s2);
        L_CHECK_EQUAL(1, res);

        //  recv on client socket should return size of ComTele
        STEP(15)
        res = tcp.recv(s2, buffer, sizeof(buffer));
        L_CHECK_EQUAL(sizeof(ComTele), res);

        //  close client
        //  select on listener should return 1 for activity
        STEP(16)
        client.close();
        res = tcp.select(s2);
        L_CHECK_EQUAL(1, res);

        //  recv on client socket should return 0
        //  when client closed
        STEP(17)
        res = tcp.recv(s2, buffer, sizeof(buffer));
        L_CHECK_EQUAL(0, res);
        
        //  close client socket for test cleanup
        tcp.close(s2);

        //  accept on invalid socket
        //  should fail
        STEP(18)
        res = tcp.accept(s1 + 100);
        L_CHECK_TRUE(res < 0);

        tcp.close(s1);
        L_CHECK_TRUE(s1 < 0);

        tcp.cleanup();
    }
} // namespace
