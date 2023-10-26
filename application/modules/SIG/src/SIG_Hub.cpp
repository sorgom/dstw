#include <SIG/SIG_Hub.h>

#include <baselib/Mem.h>
#include <ddi/ddi.h>

INSTANCE_DEF(SIG_Hub)

void SIG_Hub::fromFld(const FldState& tele, const UINT32 pos)
{
    I_SIG_Provider& prov = ddi::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1, tele.state2);
    }
    else
    {pass();}
}

void SIG_Hub::fromGui(const GuiCmd& tele, const UINT32 pos)
{
    I_SIG_Provider& prov = ddi::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1, tele.cmd2);
    }
    else
    {pass();}
}

void SIG_Hub::toFld(const UINT32 id, const INT32 state, const INT32 speed) const
{
    static CmdFld tele;
    Mem::zero(tele);
    if (ddi::getDispatcher().label(tele.name, id))
    {
        tele.cmd1 = state;
        tele.cmd2 = speed;
        ddi::getFldCom().send(tele);
    }
    else
    {pass();}
}

void SIG_Hub::toGui(const UINT32 id, const INT32 state, const INT32 speed) const
{
    static StateGui tele;
    Mem::zero(tele);
    if (ddi::getDispatcher().label(tele.name, id))
    {
        tele.state1 = state;
        tele.state2 = speed;
        ddi::getGuiCom().send(tele);
    }
    else
    {pass();}
}


