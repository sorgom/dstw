#include <BAS/BAS_Hub.h>

void BAS_Hub::fromDsp(const size_t pos, const ComTeleFld& tele) const
{
    I_Provider& prov = getProvider();
    if (prov.has(pos))
    {
        prov.at(pos).fromFld(tele.param1, tele.param2);
    }
}

void BAS_Hub::fromDsp(const size_t pos, const ComTeleGui& tele) const
{
    I_Provider& prov = getProvider();
    if (prov.has(pos))
    {
        prov.at(pos).fromGui(tele.param1, tele.param2);
    }
}
