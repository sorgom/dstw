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
#include <ifs/I_Com.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/I_Hub.h>
#include <ifs/CompEnums.h>
#include <ifs/I_Log.h>
#include <ifs/I_Provider.h>
#include <ifs/I_Reader.h>
#include <ifs/CompEnums.h>
#include <ifs/CompEnums.h>
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
    IL_DEC(Log)
    IL_DEC(Reader)
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