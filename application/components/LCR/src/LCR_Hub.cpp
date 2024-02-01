#include <LCR/LCR_Hub.h>

#include <BAS/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(LCR_Hub)

void LCR_Hub::fromDsp(const size_t pos, const FldState& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1, tele.state2);
    }
    else
    {pass();}
}

void LCR_Hub::fromDsp(const size_t pos, const GuiCmd& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1);
    }
    else
    {pass();}
}

void LCR_Hub::toFld(const size_t id, const INT32 state) const
{
    IL::getDispatcher().dispatch(id, CmdFld(state));
}

void LCR_Hub::toGui(const size_t id, const INT32 state, const INT32 ubk) const
{
    IL::getDispatcher().dispatch(id, StateGui(state, ubk));
}


