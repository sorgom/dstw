#include <TSW/TSW_Hub.h>

#include <SYS/IL.h>

INSTANCE_DEF(TSW_Hub)

void TSW_Hub::fromDsp(const size_t pos, const ComTeleFld& tele) const
{
    I_TSW_Provider& prov = IL::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.param1);
    }
    else
    { pass(); }
}

void TSW_Hub::fromDsp(const size_t pos, const ComTeleGui& tele) const
{
    I_TSW_Provider& prov = IL::getTSW_Provider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.param1);
    }
    else
    { pass(); }
}

void TSW_Hub::toFld(const size_t id, const UINT8 param1, const UINT8 param2) const
{
    IL::getDispatcher().dispatch(id, ComTeleFld(param1, param2));
}

void TSW_Hub::toGui(const size_t id, const UINT8 param1, const UINT8 param2) const
{
    IL::getDispatcher().dispatch(id, ComTeleGui(param1, param2));
}

