//  ============================================================
//  Interface Locator IL
//  - module test version
//  - all providers can be exchanged by mocks
//  - if no provider implemented in application: mock only
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef IL_H
#define IL_H

//## INCLUDES
#include <LCR/LCR_Hub.h>
#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Hub.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Com.h>
#include <SYS/Dispatcher.h>
#include <SYS/Loader.h>
#include <SYS/Log.h>
#include <TSW/TSW_Hub.h>
#include <TSW/TSW_Provider.h>
#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_LCR.h>
#include <mocks/M_LCR_Hub.h>
#include <mocks/M_LCR_Provider.h>
#include <mocks/M_Log.h>
#include <mocks/M_SIG.h>
#include <mocks/M_SIG_Hub.h>
#include <mocks/M_SIG_Provider.h>
#include <mocks/M_TSW.h>
#include <mocks/M_TSW_Hub.h>
#include <mocks/M_TSW_Provider.h>
//## END

#include <BAS/coding.h>

//  static I_NAME& getNAME();
//  static void setNAME(I_NAME& ref);
#define IL_DEC(NAME) \
    static I_ ## NAME& get ## NAME(); \
    static void set ## NAME(I_ ## NAME& ref);

class IL
{
public:
    //# IL_DEC
    IL_DEC(Com)
    IL_DEC(Dispatcher)
    IL_DEC(LCR)
    IL_DEC(LCR_Hub)
    IL_DEC(LCR_Provider)
    IL_DEC(Loader)
    IL_DEC(Log)
    IL_DEC(SIG)
    IL_DEC(SIG_Hub)
    IL_DEC(SIG_Provider)
    IL_DEC(TSW)
    IL_DEC(TSW_Hub)
    IL_DEC(TSW_Provider)
    //# END

    static void reset();

    NOCOPY(IL)
    IL();    
};

#endif // _H