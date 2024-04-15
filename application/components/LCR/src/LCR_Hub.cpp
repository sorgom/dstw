#include <LCR/LCR_Hub.h>

#include <SYS/IL.h>

IL_INSTANCE_DEF(LCR_Hub)

void LCR_Hub::fromDsp(const size_t pos, const ComTeleFld& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.param1, tele.param2);
    }
    else
    { pass(); }
}

void LCR_Hub::fromDsp(const size_t pos, const ComTeleGui& tele) const
{
    I_LCR_Provider& prov = IL::getLCR_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.param1);
    }
    else
    { pass(); }
}

void LCR_Hub::toFld(const size_t id, const UINT8 param1, const UINT8 param2) const
{
    IL::getDispatcher().dispatch(id, ComTeleFld(param1, param2));
}

void LCR_Hub::toGui(const size_t id, const UINT8 param1, const UINT8 param2) const
{
    IL::getDispatcher().dispatch(id, ComTeleGui(param1, param2));
}


