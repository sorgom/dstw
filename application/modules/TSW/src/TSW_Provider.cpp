#include <TSW/TSW_Provider.h>
#include <ddi/ddi.h>

INSTANCE_DEF(TSW_Provider)

void TSW_Provider::load(const ProjTSW* const data, const UINT32 num)
{
    I_Dispatcher& disp = ddi::getDispatcher();
    mTSWs.reset();
    bool ok = true;
    if (num > mTSWs.capacity())
    { 
        ok = false;
    }
    else
    {
        for (UINT32 n = 0; ok and (n < num); ++n)
        {
            const INT32 id = disp.assign(data[n].name, SUBSYS_TSW, n);
            if (id < 0)
            {
                ok = false;
            }
            else
            { 
                new (mTSWs.addPtr()) TSW(id);
            }
        }
    }
    if (ok)
    { pass(); }
    else
    {
        mTSWs.reset();
        ddi::getLog().log(COMP_TSW_PROVIDER, ERR_STARTUP);
    }
}
