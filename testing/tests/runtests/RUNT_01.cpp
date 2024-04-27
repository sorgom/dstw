//  ============================================================
//  runtime tests vol. 1
//  tests for runtime behaviour
//  require a running application (in background)
//  ============================================================
//  created by Manfred Sorgo

#include <testlib/TestGroupBase.h>
#include <TCP/TCP_Client.h>

#include <iostream>
using std::cerr, std::endl;

namespace test
{
    class TestGroupRT : public TestGroupBase
    {
    public:
        TestGroupRT() = default;
    protected:
        TCP_Client clientFld;
        TCP_Client clientGui;
        TCP_Client clientCtrl;
        bool ok = false;

        //  check if application is running
        bool connect()
        {
            const bool ok = 
                clientFld.connect(tcpPortFld) and
                clientGui.connect(tcpPortGui) and
                clientCtrl.connect(tcpPortCtrl);
            if (not ok)
            {
                cerr << '\n' << "* application not running *" << '\n';
                close();
            }
            return ok;
        }

        //  terminate all connections
        void close()
        {
            clientFld.close();
            clientGui.close();
            clientCtrl.close();
        }
    };

    #define SETUP_CONNECT() SETUP() if (not connect()) {return; }

    TEST_GROUP_BASE(RUNT_01, TestGroupRT) {};

    TEST(RUNT_01, T01)
    {
        SETUP_CONNECT()
    }
}
