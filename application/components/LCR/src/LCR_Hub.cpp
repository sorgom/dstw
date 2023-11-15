#include <LCR/LCR_Hub.h>

#include <BAS/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(LCR_Hub)

void LCR_Hub::fromDsp(const UINT32 pos, const FldState& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1, tele.state2);
    }
    else
    {pass();}
}

void LCR_Hub::fromDsp(const UINT32 pos, const GuiCmd&   tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1);
    }
    else
    {pass();}
}

void LCR_Hub::toFld(const UINT32 id, const INT32 state) const
{
    static CmdFld tele;
    Mem::zero(tele);
    tele.cmd1 = state;
    IL::getDispatcher().dispatch(id, tele);
}

void LCR_Hub::toGui(const UINT32 id, const INT32 state, const INT32 ubk) const
{
    static StateGui tele;
    Mem::zero(tele);
    tele.state1 = state;
    tele.state2 = ubk;
    IL::getDispatcher().dispatch(id, tele);
}


