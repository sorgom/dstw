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
#include <SIG/SIG_Hub.h>
#include <SIG/SIG_Provider.h>
#include <TSW/TSW_Hub.h>
#include <TSW/TSW_Provider.h>
#include <system/Com.h>
#include <system/Dispatcher.h>
#include <system/Loader.h>
//## END

//  I_NAME& getNAME() { return NAME::instance(); }
#define DDI_INLINE(NAME) \
    inline I_ ## NAME& get ## NAME() { return NAME::instance(); }

namespace ddi
{
    //# DDI_INLINE
    DDI_INLINE(Com)
    DDI_INLINE(Dispatcher)
    DDI_INLINE(Loader)
    DDI_INLINE(SIG_Hub)
    DDI_INLINE(SIG_Provider)
    DDI_INLINE(TSW_Hub)
    DDI_INLINE(TSW_Provider)
    //# END
}

#endif // _H