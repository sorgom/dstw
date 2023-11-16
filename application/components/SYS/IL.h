//  ============================================================
//  Interface Locator IL
//  - production application version
//  - no exchange of providers 
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
//## END

#include <BAS/coding.h>

//  inline static I_NAME& getNAME() { return NAME::instance(); }
#define IL_INLINE(NAME) \
    inline static I_ ## NAME& get ## NAME() { return NAME::instance(); }

class IL
{
public:
    //# IL_INLINE
    IL_INLINE(Com)
    IL_INLINE(Dispatcher)
    IL_INLINE(LCR_Hub)
    IL_INLINE(LCR_Provider)
    IL_INLINE(Loader)
    IL_INLINE(Log)
    IL_INLINE(SIG_Hub)
    IL_INLINE(SIG_Provider)
    IL_INLINE(TSW_Hub)
    IL_INLINE(TSW_Provider)
    //# END

    NOCOPY(IL)
    IL();
};

#endif // _H