//  ============================================================
//  mock instances (mostly for IL)
//  for interface I_<NAME>
//  - function m_<NAME>() returns mock instance 
//  - function mock_<NAME>() plugs mock instance into IL
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_INSTANCES_H
#define M_INSTANCES_H

#include "../SYS/IL.h"

#include "M_Com.h"
#include "M_Dispatcher.h"
#include "M_Elem.h"
#include "M_Log.h"
#include "M_Provider.h"

namespace test
{
    inline M_Com& m_Com() { return M_Com::instance(); }
    inline void mock_Com() { IL::setCom(m_Com()); }

    inline M_Dispatcher& m_Dispatcher() { return M_Dispatcher::instance(); }
    inline void mock_Dispatcher() { IL::setDispatcher(m_Dispatcher()); }

    inline M_LCR_Provider& m_LCR_Provider() { return M_LCR_Provider::instance(); }
    inline void mock_LCR_Provider() { IL::setLCR_Provider(m_LCR_Provider()); }

    inline M_SIG_Provider& m_SIG_Provider() { return M_SIG_Provider::instance(); }
    inline void mock_SIG_Provider() { IL::setSIG_Provider(m_SIG_Provider()); }

    inline M_TSW_Provider& m_TSW_Provider() { return M_TSW_Provider::instance(); }
    inline void mock_TSW_Provider() { IL::setTSW_Provider(m_TSW_Provider()); }

    inline M_Log& m_Log() { return M_Log::instance(); }
    inline void mock_Log() { IL::setLog(m_Log()); }

    inline M_LCR& m_LCR() { return M_LCR::instance(); }
    inline M_SIG& m_SIG() { return M_SIG::instance(); }
    inline M_TSW& m_TSW() { return M_TSW::instance(); }

    inline void unmock() { IL::prod(); }
    inline void mockAll() { IL::clear(); }
}

#endif // _H