#include <TSW/TSW_Hub.h>

#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>
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
    static CmdFld cmdFld;
    Mem::zero(cmdFld);
    if (ddi::getDispatcher().label(cmdFld.name, id))
    {
        cmdFld.cmd1 = cmd;
        ddi::getFldCom().send(cmdFld);
    }
    else
    {pass();}
}

void TSW_Hub::toGui(const UINT32 id, const INT32 state) const
{
    static StateGui stateGui;
    Mem::zero(stateGui);
    if (ddi::getDispatcher().label(stateGui.name, id))
    {
        stateGui.state1 = state;
        ddi::getGuiCom().send(stateGui);
    }
    else
    {pass();}
}


