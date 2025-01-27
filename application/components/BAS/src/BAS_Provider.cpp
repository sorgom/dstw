
#include <BAS/BAS_Provider.h>
#include <SYS/IL.h>

void X_Provider::load(const ProjItem* const data, const UINT32 num)
{
    clear();
    mElems.reserve(num);
    bool ok = true;
    const ProjItem* pd = data;
    for (UINT32 n = 0; ok and (n < num); ++n, ++pd)
    {
        const PosRes res = IL::getDispatcher().assign(pd->addr, comp(), n);
        ok = res.valid and add(res.pos, *pd);
    }
    if (not ok)
    {
        clear();
        IL::getLog().log(comp(), RET_ERR_STARTUP);
    }
}
