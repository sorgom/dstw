#include <TSW/TSW_Provider.h>
#include <SYS/IL.h>

IL_INSTANCE_DEF(TSW_Provider)

void TSW_Provider::load(const ProjTSW* data, const UINT32 num)
{
    reset();
    mElems.reserve(num);
    bool ok = true;
    for (UINT32 n = 0; ok and (n < num); ++n, ++data)
    {
        const PosRes res = IL::getDispatcher().assign(data->name, COMP_TSW, n);
        ok = res.valid;
        if (ok)
        {
            mElems.add<TSW>(res.pos);
        }
        else 
        { pass(); }
    }
    if (not ok)
    {
        reset();
        IL::getLog().log(MOD_TSW_PROVIDER, ERR_STARTUP);
    }
    else 
    { pass(); }
}
