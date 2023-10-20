//  ============================================================
//  service locator pattern
//  - module test version
//  - providers can be exchanged by mocks
//  - if no provider implemented in application: mock only
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef DDI_H
#define DDI_H

//## INCLUDES
#include <Dispatcher/Dispatcher.h>
#include <TrackSwitch/TrackSwitchProvider.h>
#include <TrackSwitch/TrackSwitchHub.h>
#include <mocks/M_FldCom.h>
#include <mocks/M_SignalPort.h>
#include <mocks/M_TrackSwitch.h>
#include <mocks/M_TrackSwitchProvider.h>
#include <mocks/M_TrackSwitchHub.h>
//## END

//  I_NAME& getNAME();
//  void setNAME(I_NAME& ref);
#define DDI_DEC(NAME) \
    I_ ## NAME& get ## NAME(); \
    void set ## NAME(I_ ## NAME& ref);

namespace ddi
{
    //# DDI_DEC
    DDI_DEC(Dispatcher)
    DDI_DEC(FldCom)
    DDI_DEC(SignalPort)
    DDI_DEC(TrackSwitch)
    DDI_DEC(TrackSwitchProvider)
    DDI_DEC(TrackSwitchHub)
    //# END

    void reset();
}

#endif // _H