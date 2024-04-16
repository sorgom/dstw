
#include <BAS/BAS_Provider.h>
#include <SYS/IL.h>

void BAS_Provider::load(const ProjItem* data, const UINT32 num)
{
    reset();
    mElems.reserve(num);
    bool ok = true;
    for (UINT32 n = 0; ok and (n < num); ++n, ++data)
    {
        const PosRes res = IL::getDispatcher().assign(data->name, comp(), n);
        ok = res.valid;
        if (ok)
        {
            ok = add(res.pos, *data);
        }
        else 
        { pass(); }
    }
    if (not ok)
    {
        reset();
        IL::getLog().log(comp(), ERR_STARTUP);
    }
    else 
    { pass(); }

}