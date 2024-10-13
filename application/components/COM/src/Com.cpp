#include <COM/Com.h>
#include <SYS/IL.h>

INSTANCE_DEF(Com)

void Com::run()
{
    mRunning = false;

    I_TCP_Listener& listenerFld = IL::getTCP_Listener_Fld();
    I_TCP_Listener& listenerGui = IL::getTCP_Listener_Gui();
    I_TCP_Listener& listenerCtrl = IL::getTCP_Listener_Ctrl();

    I_TCP_Con &clientFld = IL::getTCP_Con_Fld();
    I_TCP_Con &clientGui = IL::getTCP_Con_Gui();
    I_TCP_Con &clientCtrl = IL::getTCP_Con_Ctrl();

    I_TCP& tcp = IL::getTCP();

    const ComSetup& setup = IL::getReader().getComSetup();

    bool ok = tcp.init()
        and listenerFld.listen(setup.portFld)
        and listenerGui.listen(setup.portGui)
        and listenerCtrl.listen(setup.portCtrl);

    if (ok)
    {
        tcp.setTimeout(setup.timeout);
        mRunning = true;
    }
    else
    {
        IL::getLog().log(COMP_COM, RET_ERR_STARTUP);
    }

    while (ok and mRunning)
    {
        ok =
            listenerFld.select()
            and listenerGui.select()
            and listenerCtrl.select()
            and clientFld.select()
            and clientGui.select()
            and clientCtrl.select();

        if (not ok)
        {
            IL::getLog().log(COMP_COM, RET_ERR_COM);
            mRunning = false;
        }
    }

    listenerFld.close();
    listenerGui.close();
    listenerCtrl.close();
    clientFld.close();
    clientGui.close();
    clientCtrl.close();
    tcp.cleanup();
}

void Com::stop()
{
    mRunning = false;
}

void Com::toFld(const ComTele& tele) const
{
    IL::getTCP_Con_Fld().send(tele);
}

void Com::toGui(const ComTele& tele) const
{
    IL::getTCP_Con_Gui().send(tele);
}
