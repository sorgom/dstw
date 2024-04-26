#include <COM/Com.h>
#include <SYS/IL.h>

INSTANCE_DEF(Com)

void Com::run()
{
    mRunning = true;
    I_TCP_Listener& listenerFld = IL::getTCP_Listener_Fld();
    I_TCP_Listener& listenerGui = IL::getTCP_Listener_Gui();
    I_TCP_Listener& listenerCtrl = IL::getTCP_Listener_Ctrl();

    I_TCP_Client &clientFld = IL::getTCP_Client_Fld();
    I_TCP_Client &clientGui = IL::getTCP_Client_Gui();
    I_TCP_Client &clientCtrl = IL::getTCP_Client_Ctrl();

    const ComSetup& setup = IL::getReader().getComSetup();

    I_TCP& tcp = IL::getTCP();

    bool ok = tcp.init()
        and listenerFld.listen(setup.portFld)
        and listenerGui.listen(setup.portGui)
        and listenerCtrl.listen(setup.portCtrl);

    if (not ok)
    {
        IL::getLog().log(COMP_COM, RET_ERR_STARTUP);
    }
    else
    {
        tcp.setTimeout(setup.timeout);
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
        } 
    }
    tcp.cleanup();
}

void Com::stop()
{
    mRunning = false;
}