#include <SIG/SIG_Hub.h>

#include <BAS/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(SIG_Hub)

void SIG_Hub::fromDsp(const UINT32 pos, const FldState& tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1, tele.state2);
    }
    else
    {pass();}
}

void SIG_Hub::fromDsp(const UINT32 pos, const GuiCmd&   tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
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
    tele.cmd1 = state;
    tele.cmd2 = speed;
    IL::getDispatcher().dispatch(id, tele);
}

void SIG_Hub::toGui(const UINT32 id, const INT32 state, const INT32 speed) const
{
    static StateGui tele;
    Mem::zero(tele);
    tele.state1 = state;
    tele.state2 = speed;
    IL::getDispatcher().dispatch(id, tele);
}


