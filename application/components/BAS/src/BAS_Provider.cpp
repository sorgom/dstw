
#include <BAS/BAS_Provider.h>
#include <SYS/IL.h>

void BAS_Provider::load(const ProjItem* data, const UINT32 num)
{
    clear();
    mElems.reserve(num);
    bool ok = true;
    for (UINT32 n = 0; ok and (n < num); ++n, ++data)
    {
        const PosRes res = IL::getDispatcher().assign(data->addr, comp(), n);
        ok = res.valid and add(res.pos, *data);
    }
    if (not ok)
    {
        clear();
        IL::getLog().log(comp(), RET_ERR_STARTUP);
    }
}
