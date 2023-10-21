#include <TSW/TSW_Hub.h>

#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>
#include <ddi/ddi.h>

INSTANCE_DEF(TSW_Hub)

bool TSW_Hub::load(const UINT32 num, const ProjTSW* const data)
{
    I_TSW_Provider& prov = ddi::getTSW_Provider();
    I_Dispatcher& disp = ddi::getDispatcher();

    bool ok = true;
    prov.reset();
    if (num > prov.capacity())
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
                prov.reset();
            }
            else
            { 
                prov.add(id);
            }
        }
    }
    return ok;
}



