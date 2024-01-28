#include <TSW/TSW_Provider.h>
#include <SYS/IL.h>

INSTANCE_DEF(TSW_Provider)

void TSW_Provider::load(const ProjTSW* const data, const UINT32 num)
{
    I_Dispatcher& disp = IL::getDispatcher();
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
            const size_t id = disp.assign(data[n].name, SUBSYS_TSW, n);
            if (id == Dispatcher::invalidPos)
            {
                ok = false;
            }
            else
            { 
                mTSWs.newT<TSW>(id);
            }
        }
    }
    if (ok)
    { pass(); }
    else
    {
        mTSWs.reset();
        IL::getLog().log(MOD_TSW_PROVIDER, ERR_STARTUP);
    }
}
