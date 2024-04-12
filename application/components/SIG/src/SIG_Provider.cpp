#include <SIG/SIG_Provider.h>
#include <SYS/IL.h>

INSTANCE_DEF(SIG_Provider)

void SIG_Provider::load(const ProjSIG* const data, const UINT32 num)
{
    I_Dispatcher& disp = IL::getDispatcher();
    reset();
    bool ok = mElems.reserve(num) >= num;

    for (UINT32 n = 0; ok and (n < num); ++n)
    {
        const ProjSIG& proj = data[n];
        const PosRes res = disp.assign(proj.name, COMP_SIG, n);
        if (res.valid)
        {
            switch (proj.type)
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
        {
            ok = false;
        }
    }
    if (ok)
    { pass(); }
    else
    {
        reset();
        IL::getLog().log(MOD_SIG_PROVIDER, ERR_STARTUP);
    }
}
