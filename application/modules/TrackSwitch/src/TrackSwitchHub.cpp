#include <TrackSwitch/TrackSwitchHub.h>

#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>
#include <ddi/ddi.h>

INSTANCE_DEF(TrackSwitchHub)

bool TrackSwitchHub::load(const UINT32 num, const TrackSwitchProj* const data)
{
    I_TrackSwitchProvider& prov = ddi::getTrackSwitchProvider();
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



