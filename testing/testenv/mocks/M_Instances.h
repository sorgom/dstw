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
#include "M_Dispatcher.h"
#include "M_FldCom.h"
#include "M_GuiCom.h"
#include "M_TSW.h"
#include "M_TSW_Hub.h"
#include "M_TSW_Provider.h"
//## END

#define MOCK_DEC(NAME) \
    inline M_ ## NAME& m_ ## NAME() { return M_ ## NAME::instance(); } \
    inline void mock_ ## NAME() { ddi::set ## NAME(m_ ## NAME()); }

namespace test
{
    //# MOCK_DEC
    MOCK_DEC(Dispatcher)
    MOCK_DEC(FldCom)
    MOCK_DEC(GuiCom)
    MOCK_DEC(TSW)
    MOCK_DEC(TSW_Hub)
    MOCK_DEC(TSW_Provider)
    //# END

    inline void unmock() { ddi::reset(); }
    void mockAll();
}

#endif // _H