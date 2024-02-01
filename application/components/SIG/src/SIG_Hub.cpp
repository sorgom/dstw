#include <SIG/SIG_Hub.h>

#include <BAS/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(SIG_Hub)

void SIG_Hub::fromDsp(const size_t pos, const FldState& tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1, tele.state2);
    }
    else
    {pass();}
}

void SIG_Hub::fromDsp(const size_t pos, const GuiCmd&   tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1, tele.cmd2);
    }
    else
    {pass();}
}

void SIG_Hub::toFld(const size_t id, const INT32 state, const INT32 speed) const
{
    // CmdFld tele(state, speed);
    IL::getDispatcher().dispatch(id, CmdFld(state, speed));
}

void SIG_Hub::toGui(const size_t id, const INT32 state, const INT32 speed) const
{
    // StateGui tele(state, speed);
    IL::getDispatcher().dispatch(id, StateGui(state, speed));
}


