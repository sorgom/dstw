#include <COM/TCP_Cons.h>
#include <SYS/IL.h>

//  ============================================================
//  base client
//  ============================================================
bool TCP_CLient_Base::accept(const INT32 socket)
{
    close();
    mSocket = IL::getTCP().accept(socket);
    const bool ok = mSocket >= 0;
    if (ok)
    {
        onAccept();
    }
    else
    { pass(); }
    return ok;
}

bool TCP_CLient_Base::select()
{
    const I_TCP& tcp = IL::getTCP();
    bool ok = true;
    // not operating
    if (mSocket < 0)
    { pass(); }
    else
    {
        const INT32 res = tcp.select(mSocket);
        //  activity on socket
        if (res > 0)
        {
            const INT32 len = tcp.recv(mSocket, &mTele, sizeof(ComTele));
            //  valid telegram received
            if (len == sizeof(ComTele))
            {
                forward(mTele);
            }
            //  close event
            else if (len <= 0)
            {
                close();
            }
            //  invalid data size
            else
            {
                ok = false; 
                close();    
            }
        }
        //  select error
        else if (res < 0)
        {
            ok = false;
            close();
        }
        //  no activity
        else
        { pass(); }
    }
    return ok;
}

void TCP_CLient_Base::close()
{
    IL::getTCP().close(mSocket);
}

void TCP_CLient_Base::send(const ComTele& tele) const
{
    if (mSocket >= 0)
    {
        IL::getTCP().send(mSocket, reinterpret_cast<const CHAR*>(&tele), sizeof(ComTele));
    }
    else
    { pass(); }
}

//  field client
INSTANCE_DEF(TCP_Con_Fld)

void TCP_Con_Fld::onAccept() const
{
    //  TODO: Dispatcher must recall all states
}

void TCP_Con_Fld::forward(const ComTele& tele) const
{
    IL::getDispatcher().fromFld(tele);
}

//  GUI client
INSTANCE_DEF(TCP_Con_Gui)

void TCP_Con_Gui::onAccept() const
{
    //  TODO: Dispatcher resend all states
    //  call I_Elem::resend() or similar
}

void TCP_Con_Gui::forward(const ComTele& tele) const
{
    IL::getDispatcher().fromGui(tele);
}

//  control client
INSTANCE_DEF(TCP_Con_Ctrl)

void TCP_Con_Ctrl::forward(const ComTele& tele) const
{
    //  evaluate telegram
    //  - stop
    if (
        tele.data.param1 == COM_CTRL_STOP and
        tele.data.param2 == COM_CTRL_STOP
    )
    {
        IL::getCom().stop();
    }
    //  - ping
    else if (
        tele.data.param1 == COM_CTRL_PING and
        tele.data.param2 == COM_CTRL_PING
    )
    {
        send(tele);
    }
    else
    { pass();}
}