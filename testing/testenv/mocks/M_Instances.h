//  ============================================================
//  mock instances (for ddi)
//  for interface I_<NAME>
//  - function m_<NAME>() returns mock instance 
//  - function mock_<NAME>() plugs mock instance into ddi
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_INSTANCES_H
#define M_INSTANCES_H

#include <ddi/ddi.h>

//## INCLUDES_LOCAL
#include "M_RastaPort.h"
#include "M_SignalPort.h"
#include "M_TrackSwitchPort.h"
//## END

#define MOCK_DEC(NAME) \
    M_ ## NAME& m_ ## NAME(); \
    inline void mock_ ## NAME() { ddi::set ## NAME(m_ ## NAME()); }

namespace test
{
    //# MOCK_DEC
    MOCK_DEC(RastaPort)
    MOCK_DEC(SignalPort)
    MOCK_DEC(TrackSwitchPort)
    //# END

    inline void unmock() { ddi::reset(); }
}

#endif // _H