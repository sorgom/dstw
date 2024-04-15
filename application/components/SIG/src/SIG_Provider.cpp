#include <SIG/SIG_Provider.h>
#include <SYS/IL.h>

IL_INSTANCE_DEF(SIG_Provider)

void SIG_Provider::load(const ProjSIG* data, const UINT32 num)
{
    reset();
    mElems.reserve(num);
    bool ok = true;
    for (UINT32 n = 0; ok and (n < num); ++n, ++data)
    {
        const PosRes res = IL::getDispatcher().assign(data->name, COMP_SIG, n);
        ok = res.valid;
        if (ok)
        {
            switch (data->type)
            {
                case SIG_TYPE_H:
                    mElems.add<SIG_H>(res.pos);
                    break;
                case SIG_TYPE_N:
                    mElems.add<SIG_N>(res.pos);
                    break;
                case SIG_TYPE_H_N:
                    mElems.add<SIG_H_N>(res.pos);
                    break;
                default:
                    ok = false;
                    break;
            }
        }
        else 
        { pass(); }
    }
    if (not ok)
    {
        reset();
        IL::getLog().log(MOD_SIG_PROVIDER, ERR_STARTUP);
    }
    else 
    { pass(); }
}
