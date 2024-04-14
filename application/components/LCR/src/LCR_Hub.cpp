#include <LCR/LCR_Hub.h>

#include <codebase/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(LCR_Hub)

void LCR_Hub::fromDsp(const size_t pos, const ComFldState& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.param1, tele.param2);
    }
    else
    { pass(); }
}

void LCR_Hub::fromDsp(const size_t pos, const ComGuiCmd& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.param1);
    }
    else
    { pass(); }
}

void LCR_Hub::toFld(const size_t id, const UINT8 state) const
{
    IL::getDispatcher().dispatch(id, ComCmdFld(state));
}

void LCR_Hub::toGui(const size_t id, const UINT8 state, const UINT8 ubk) const
{
    IL::getDispatcher().dispatch(id, ComStateGui(state, ubk));
}


