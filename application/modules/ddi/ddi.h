//  ============================================================
//  service locator pattern
//  - production application version
//  - no exchange of providers 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef DDI_H
#define DDI_H

//## INCLUDES
#include <TrackSwitch/TrackSwitchPort.h>
//## END

//  I_NAME& getNAME() { return NAME::instance(); }
#define DDI_INLINE(NAME) \
    inline I_ ## NAME& get ## NAME() { return NAME::instance(); }

namespace ddi
{
    //# DDI_INLINE
    DDI_INLINE(TrackSwitchPort)
    //# END
}

#endif // _H