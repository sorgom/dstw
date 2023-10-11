//  TEST ENV DDI

#pragma once
#ifndef DDI_H
#define DDI_H

//## INCLUDES
#include <TrackSwitch/TrackSwitchPort.h>
#include <mocks/M_SignalPort.h>
#include <mocks/M_TrackSwitchPort.h>
//## END

//  I_NAME& getNAME();
//  void setNAME(I_NAME& ref);
#define DDI_DEC(NAME) \
    I_ ## NAME& get ## NAME(); \
    void set ## NAME(I_ ## NAME& ref);

namespace ddi
{
    //# DDI_DEC
    DDI_DEC(SignalPort)
    DDI_DEC(TrackSwitchPort)
    //# END

    void reset();
}

#endif // _H