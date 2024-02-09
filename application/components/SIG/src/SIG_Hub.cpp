#include <SIG/SIG_Hub.h>

#include <codebase/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(SIG_Hub)

void SIG_Hub::fromDsp(const size_t pos, const ComFldState& tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.state1, tele.state2);
    }
    else
    {pass();}
}

void SIG_Hub::fromDsp(const size_t pos, const ComGuiCmd&   tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.cmd1, tele.cmd2);
    }
    else
    {pass();}
}

void SIG_Hub::toFld(const size_t id, const UINT8 state, const UINT8 speed) const
{
    // ComCmdFld tele(state, speed);
    IL::getDispatcher().dispatch(id, ComCmdFld(state, speed));
}

void SIG_Hub::toGui(const size_t id, const UINT8 state, const UINT8 speed) const
{
    // ComStateGui tele(state, speed);
    IL::getDispatcher().dispatch(id, ComStateGui(state, speed));
}


