#include <SIG/SIG_Hub.h>

#include <codebase/Mem.h>
#include <SYS/IL.h>

INSTANCE_DEF(SIG_Hub)

void SIG_Hub::fromDsp(const size_t pos, const ComTeleFld& tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.param1, tele.param2);
    }
    else
    { pass(); }
}

void SIG_Hub::fromDsp(const size_t pos, const ComTeleGui&   tele) const
{
    I_SIG_Provider& prov = IL::getSIG_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.param1, tele.param2);
    }
    else
    { pass(); }
}

void SIG_Hub::toFld(const size_t id, const UINT8 state, const UINT8 speed) const
{
    IL::getDispatcher().dispatch(id, ComTeleFld(state, speed));
}

void SIG_Hub::toGui(const size_t id, const UINT8 state, const UINT8 speed) const
{
    IL::getDispatcher().dispatch(id, ComTeleGui(state, speed));
}


