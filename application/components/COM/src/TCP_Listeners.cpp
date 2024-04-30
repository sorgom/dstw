#include <COM/TCP_Listeners.h>
#include <SYS/IL.h>

bool Tcp_Listener_Base::listen(const UINT16 port)
{
    const I_TCP& tcp = IL::getTCP();
    bool ok = true;
    mSocket = tcp.socket();
    if (mSocket < 0)
    {
        ok = false;
        IL::getLog().log(COMP_COM, RET_ERR_COM) << "E socket " << port << std::endl;
    }
    else if (not tcp.bind(mSocket, port))
    {
        ok = false;
        IL::getLog().log(COMP_COM, RET_ERR_COM) << "E bind " << port << std::endl;
    }
    else if (not tcp.listen(mSocket))
    {
        ok = false;
        IL::getLog().log(COMP_COM, RET_ERR_COM) << "E listen " << port << std::endl;
    }
    else
    { pass();}

    if (not ok)
    {
        tcp.close(mSocket);
    }
    return ok;
}

bool Tcp_Listener_Base::select()
{
    const I_TCP& tcp = IL::getTCP();
    const INT32 res = tcp.select(mSocket);
    bool ok = 
        (res == 0)
        or (res > 0 and getCon().accept(mSocket));

    if (not ok) 
    {
        tcp.close(mSocket);
    }
    return ok;
}

void Tcp_Listener_Base::close()
{
    IL::getTCP().close(mSocket);
}

I_TCP_Con& TCP_Listener_Fld::getCon() const
{
    return IL::getTCP_Con_Fld();
}
INSTANCE_DEF(TCP_Listener_Fld)

I_TCP_Con& TCP_Listener_Gui::getCon() const
{
    return IL::getTCP_Con_Gui();
}
INSTANCE_DEF(TCP_Listener_Gui)

I_TCP_Con& TCP_Listener_Ctrl::getCon() const
{
    return IL::getTCP_Con_Ctrl();
}
INSTANCE_DEF(TCP_Listener_Ctrl)