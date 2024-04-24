#include <BAS/BAS_Tcp.h>
#include <SYS/IL.h>

bool BAS_Tcp_Listener::listen(const UINT16 port)
{
    const I_Tcp& tcp = IL::getTcp();
    mSocket = tcp.socket();
    const bool ok =
        (mSocket >= 0)
        and tcp.bind(mSocket, port)
        and tcp.listen(mSocket);
    if (ok)
    {
        pass();
    }
    else
    {
        tcp.close(mSocket);
    }
    return ok;
}

bool BAS_Tcp_Listener::select()
{
    const I_Tcp& tcp = IL::getTcp();
    bool ok = false;
    const INT32 res = tcp.select(mSocket);
    if (res > 0)
    {
        ok = getClient().accept(mSocket);
    }
    if (res == 0)
    {
        ok = true;
    }
    else
    {
        tcp.close(mSocket);
    }
    return ok;
}