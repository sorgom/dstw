#include <SIG/SIG_Provider.h>
#include <SYS/IL.h>

INSTANCE_DEF(SIG_Provider)

void SIG_Provider::load(const ProjSIG* const data, const UINT32 num)
{
    I_Dispatcher& disp = IL::getDispatcher();
    mSIGs.reset();
    bool ok = true;

    if (num > mSIGs.capacity())
    { 
        ok = false;
    }
    else
    {
        for (UINT32 n = 0; ok and (n < num); ++n)
        {
            const ProjSIG& proj = data[n];
            const INT32 id = disp.assign(proj.name, SUBSYS_SIG, n);
            if (id < 0)
            {
                ok = false;
            }
            else
            {
                switch (proj.type)
                {
                    case SIG_TYPE_H:
                        mSIGs.add(SIG_H(id));
                        break;
                    case SIG_TYPE_N:
                        mSIGs.add(SIG_N(id));
                        break;
                    case SIG_TYPE_H_N:
                        mSIGs.add(SIG_H_N(id));
                        break;
                    default:
                        ok = false;
                        break;
                } 
            }
        }
    }
    if (ok)
    { pass(); }
    else
    {
        mSIGs.reset();
        IL::getLog().log(MOD_SIG_PROVIDER, ERR_STARTUP);
    }
}
