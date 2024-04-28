
#include <TCP/TCP_Client.h>
#include <ifs/DataTypes.h>
#include <testlib/testValues.h>

INT32 main()
{
    test::TCP_Client client;
    client.connect(test::tcpPortCtrl);
    client.send(ComTele{{}, {COM_CTRL_STOP, COM_CTRL_STOP}});
    client.close();
    return 0;
}