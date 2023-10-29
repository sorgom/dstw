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
#include <SIG/SIG_Hub.h>
#include <SIG/SIG_Provider.h>
#include <TSW/TSW_Hub.h>
#include <TSW/TSW_Provider.h>
#include <system/Com.h>
#include <system/Dispatcher.h>
#include <system/Loader.h>
#include <system/Logger.h>
#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Logger.h>
#include <mocks/M_SIG.h>
#include <mocks/M_SIG_Hub.h>
#include <mocks/M_SIG_Provider.h>
#include <mocks/M_TSW.h>
#include <mocks/M_TSW_Hub.h>
#include <mocks/M_TSW_Provider.h>
//## END

//  I_NAME& getNAME();
//  void setNAME(I_NAME& ref);
#define DDI_DEC(NAME) \
    I_ ## NAME& get ## NAME(); \
    void set ## NAME(I_ ## NAME& ref);

namespace ddi
{
    //# DDI_DEC
    DDI_DEC(Com)
    DDI_DEC(Dispatcher)
    DDI_DEC(Loader)
    DDI_DEC(Logger)
    DDI_DEC(SIG)
    DDI_DEC(SIG_Hub)
    DDI_DEC(SIG_Provider)
    DDI_DEC(TSW)
    DDI_DEC(TSW_Hub)
    DDI_DEC(TSW_Provider)
    //# END

    void reset();
}

#endif // _H