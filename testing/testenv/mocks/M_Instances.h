//  ============================================================
//  mock instances (for IL)
//  for interface I_<NAME>
//  - function m_<NAME>() returns mock instance 
//  - function mock_<NAME>() plugs mock instance into IL
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_INSTANCES_H
#define M_INSTANCES_H

#include <SYS/IL.h>

//## INCLUDES_LOCAL
#include "M_Com.h"
#include "M_Dispatcher.h"
#include "M_LCR.h"
#include "M_LCR_Hub.h"
#include "M_LCR_Provider.h"
#include "M_Log.h"
#include "M_SIG.h"
#include "M_SIG_Hub.h"
#include "M_SIG_Provider.h"
#include "M_TSW.h"
#include "M_TSW_Hub.h"
#include "M_TSW_Provider.h"
//## END

#define MOCK_DEC(NAME) \
    inline M_ ## NAME& m_ ## NAME() { return M_ ## NAME::instance(); } \
    inline void mock_ ## NAME() { IL::set ## NAME(m_ ## NAME()); }

namespace test
{
    //# MOCK_DEC
    MOCK_DEC(Com)
    MOCK_DEC(Dispatcher)
    MOCK_DEC(LCR)
    MOCK_DEC(LCR_Hub)
    MOCK_DEC(LCR_Provider)
    MOCK_DEC(Log)
    MOCK_DEC(SIG)
    MOCK_DEC(SIG_Hub)
    MOCK_DEC(SIG_Provider)
    MOCK_DEC(TSW)
    MOCK_DEC(TSW_Hub)
    MOCK_DEC(TSW_Provider)
    //# END

    inline void unmock() { IL::reset(); }
    void mockAll();
}

#endif // _H