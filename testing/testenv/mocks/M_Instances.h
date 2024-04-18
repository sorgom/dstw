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

#include "ILPlugs.h"
#include "M_Com.h"
#include "M_Dispatcher.h"
#include "M_Elem.h"
#include "M_Log.h"
#include "M_Provider.h"

namespace test
{
    inline M_Com& m_Com() { return M_Com::instance(); }
    inline void mock_Com() { ILPLugs::instance().mCom.set(m_Com()); }

    inline M_Dispatcher& m_Dispatcher() { return M_Dispatcher::instance(); }
    inline M_LCR_Provider& m_LCR_Provider() { return M_LCR_Provider::instance(); }
    inline M_SIG_Provider& m_SIG_Provider() { return M_SIG_Provider::instance(); }
    inline M_TSW_Provider& m_TSW_Provider() { return M_TSW_Provider::instance(); }
    inline M_Log& m_Log() { return M_Log::instance(); }
    inline M_LCR& m_LCR() { return M_LCR::instance(); }
    inline M_SIG& m_SIG() { return M_SIG::instance(); }
    inline M_TSW& m_TSW() { return M_TSW::instance(); }

    inline void unmock() { ILPLugs::instance().prod(); }
    inline void mockAll() { ILPLugs::instance().reset(); }
}

#endif // _H