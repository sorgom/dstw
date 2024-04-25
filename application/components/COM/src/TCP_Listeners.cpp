#include <COM/TCP_Listeners.h>
#include <SYS/IL.h>

bool Tcp_Listener_Base::listen(const UINT16 port)
{
    const I_TCP& tcp = IL::getTCP();
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

bool Tcp_Listener_Base::select()
{
    const I_TCP& tcp = IL::getTCP();
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

void Tcp_Listener_Base::close()
{
    IL::getTCP().close(mSocket);
}

I_TCP_Client& TCP_Listener_Fld::getClient() const
{
    return IL::getTCP_Client_Fld();
}
INSTANCE_DEF(TCP_Listener_Fld)

I_TCP_Client& TCP_Listener_Gui::getClient() const
{
    return IL::getTCP_Client_Gui();
}
INSTANCE_DEF(TCP_Listener_Gui)

I_TCP_Client& TCP_Listener_Ctrl::getClient() const
{
    return IL::getTCP_Client_Ctrl();
}
INSTANCE_DEF(TCP_Listener_Ctrl)