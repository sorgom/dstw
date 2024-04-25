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
        tcp.setTimeout(10);
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

        //  bind socket 1 to port 8080
        //  should be ok
        STEP(3)
        {
            const bool res = tcp.bind(s1, 8080);
            L_CHECK_TRUE(res);
        }

        //  bind socket 2 to same port 8080
        //  should fail
        STEP(4)
        {
            INT32 s2 = tcp.socket();
            L_CHECK_TRUE(s2 >= 0);
            const bool res = tcp.bind(s2, 8080);
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
            INT32 s2 = -1;
            const bool res = tcp.listen(s2);
            L_CHECK_FALSE(res);
        }

        //  select on socket 1
        //  should be ok with no result
        STEP(7)
        {
            INT32 res = tcp.select(s1);
            L_CHECK_EQUAL(0, res);
        }
        // select on invalid socket
        // should fail
        STEP(8)
        {
            INT32 res = tcp.select(s1 + 100);
            L_CHECK_EQUAL(-1, res);
        }

        tcp.close(s1);
        L_CHECK_TRUE(s1 < 0);

        tcp.cleanup();
    }
} // namespace
