#include <SIG/SIG_Provider.h>
#include <ddi/ddi.h>

INSTANCE_DEF(SIG_Provider)

bool SIG_Provider::load(const ProjSIG* const data, const UINT32 num)
{
    I_Dispatcher& disp = ddi::getDispatcher();
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
                mSIGs.reset();
            }
            else
            {
                switch (proj.type)
                {
                    case SIG_TYPE_H:
                        new (mSIGs.addPtr()) SIG_H(id);
                        break;
                    case SIG_TYPE_N:
                        new (mSIGs.addPtr()) SIG_N(id);
                        break;
                    case SIG_TYPE_H_N:
                        new (mSIGs.addPtr()) SIG_H_N(id);
                        break;
                    default:
                        ok = false;
                        mSIGs.reset();
                        break;
                } 
            }
        }
    }
    return ok;
}
