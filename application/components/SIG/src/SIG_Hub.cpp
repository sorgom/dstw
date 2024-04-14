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

void SIG_Hub::toFld(const size_t id, UINT8 param1, UINT8 param2) const
{
    IL::getDispatcher().dispatch(id, ComTeleFld(param1, param2));
}

void SIG_Hub::toGui(const size_t id, UINT8 param1, UINT8 param2) const
{
    IL::getDispatcher().dispatch(id, ComTeleGui(param1, param2));
}


