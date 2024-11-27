//  ============================================================
//  mock instances for IL and tests
//  for interface I_<NAME>
//  - function m_<NAME>() returns mock instance
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_INSTANCES_H
#define M_INSTANCES_H

#include "M_Com.h"
#include "M_Dispatcher.h"
#include "M_Elem.h"
#include "M_Log.h"
#include "M_Provider.h"
#include "M_Reader.h"
#include "M_TCP_Con.h"
#include "M_TCP_Listener.h"
#include "M_TCP.h"

namespace test
{
    inline M_Com& m_Com() { return M_Com::instance(); }
    inline M_Dispatcher& m_Dispatcher() { return M_Dispatcher::instance(); }
    inline M_LCR_Provider& m_LCR_Provider() { return M_LCR_Provider::instance(); }
    inline M_LCR& m_LCR() { return M_LCR::instance(); }
    inline M_Log& m_Log() { return M_Log::instance(); }
    inline M_Reader& m_Reader() { return M_Reader::instance(); }
    inline M_SIG_Provider& m_SIG_Provider() { return M_SIG_Provider::instance(); }
    inline M_SIG& m_SIG() { return M_SIG::instance(); }
    inline M_TCP_Con_Ctrl& m_TCP_Con_Ctrl() { return M_TCP_Con_Ctrl::instance(); }
    inline M_TCP_Con_Fld& m_TCP_Con_Fld() { return M_TCP_Con_Fld::instance(); }
    inline M_TCP_Con_Gui& m_TCP_Con_Gui() { return M_TCP_Con_Gui::instance(); }
    inline M_TCP_Listener_Ctrl& m_TCP_Listener_Ctrl() { return M_TCP_Listener_Ctrl::instance(); }
    inline M_TCP_Listener_Fld& m_TCP_Listener_Fld() { return M_TCP_Listener_Fld::instance(); }
    inline M_TCP_Listener_Gui& m_TCP_Listener_Gui() { return M_TCP_Listener_Gui::instance(); }
    inline M_TCP& m_TCP() { return M_TCP::instance(); }
    inline M_TSW_Provider& m_TSW_Provider() { return M_TSW_Provider::instance(); }
    inline M_TSW& m_TSW() { return M_TSW::instance(); }
}
#endif // _H
