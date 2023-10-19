#include <TrackSwitch/TrackSwitchPort.h>

#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>
#include <ddi/ddi.h>

INSTANCE_DEF(TrackSwitchPort)

bool TrackSwitchPort::load(const UINT32 num, const TrackSwitchProj* const data)
{
    I_TrackSwitchFactory& factory = ddi::getTrackSwitchFactory();
    I_Dispatcher& disp = ddi::getDispatcher();

    bool ok = true;
    factory.reset();
    if (num > factory.capacity())
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
                factory.reset();
            }
            else
            { 
                factory.add(id);
            }
        }
    }
    return ok;
}



