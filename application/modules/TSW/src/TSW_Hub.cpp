#include <TSW/TSW_Hub.h>

#include <baselib/Mem.h>
#include <ddi/ddi.h>

INSTANCE_DEF(TSW_Hub)

void TSW_Hub::fromFld(const FldState& tele, const UINT32 pos)
{
    I_TSW_Provider& prov = ddi::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1);
    }
    else
    {pass();}
}

void TSW_Hub::fromGui(const GuiCmd& tele, const UINT32 pos)
{
    I_TSW_Provider& prov = ddi::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1);
    }
    else
    {pass();}
}

void TSW_Hub::toFld(const UINT32 id, const INT32 cmd) const
{
    static CmdFld tele;
    Mem::zero(tele);
    if (ddi::getDispatcher().label(tele.name, id))
    {
        tele.cmd1 = cmd;
        ddi::getFldCom().send(tele);
    }
    else
    {pass();}
}

void TSW_Hub::toGui(const UINT32 id, const INT32 state) const
{
    static StateGui tele;
    Mem::zero(tele);
    if (ddi::getDispatcher().label(tele.name, id))
    {
        tele.state1 = state;
        ddi::getGuiCom().send(tele);
    }
    else
    {pass();}
}


