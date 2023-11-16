#include <LCR/LCR_Provider.h>
#include <SYS/IL.h>

INSTANCE_DEF(LCR_Provider)

void LCR_Provider::load(const ProjLCR* const data, const UINT32 num)
{
    I_Dispatcher& disp = IL::getDispatcher();
    mLCRs.reset();
    bool ok = true;

    if (num > mLCRs.capacity())
    { 
        ok = false;
    }
    else
    {
        for (UINT32 n = 0; ok and (n < num); ++n)
        {
            const ProjLCR& proj = data[n];
            const INT32 id = disp.assign(proj.name, SUBSYS_LCR, n);
            if (id < 0)
            {
                ok = false;
            }
            else
            {
                switch (proj.type)
                {
                    case LCR_TYPE_LCR:
                        mLCRs.add(LCR(id));
                        break;
                    case LCR_TYPE_LCR_UBK:
                        mLCRs.add(LCR_UBK(id));
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
        mLCRs.reset();
        IL::getLog().log(MOD_LCR_PROVIDER, ERR_STARTUP);
    }
}
