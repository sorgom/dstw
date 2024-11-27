//  ============================================================
//  Interface Locator IL
//  - production application version
//  - no exchange of providers
//  ============================================================
//  created by Manfred Sorgo

#ifndef IL_H
#define IL_H

#include <COM/Com.h>
#include <COM/TCP_Com.h>
#include <COM/TCP.h>
#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Dispatcher.h>
#include <SYS/Log.h>
#include <SYS/Reader.h>
#include <TSW/TSW_Provider.h>

namespace IL
{
    inline I_Com& getCom() { return Com::instance(); }
    inline I_Dispatcher& getDispatcher() { return Dispatcher::instance(); }
    inline I_Log& getLog() { return Log::instance(); }
    inline I_Provider& getLCR_Provider() { return LCR_Provider::instance(); }
    inline I_Provider& getSIG_Provider() { return SIG_Provider::instance(); }
    inline I_Provider& getTSW_Provider() { return TSW_Provider::instance(); }
    inline I_Reader& getReader() { return Reader::instance(); }
    inline I_TCP& getTCP() { return TCP::instance(); }
    inline I_TCP_Con& getTCP_Con_Fld() { return TCP_Con_Fld::instance(); }
    inline I_TCP_Con& getTCP_Con_Gui() { return TCP_Con_Gui::instance(); }
    inline I_TCP_Con& getTCP_Con_Ctrl() { return TCP_Con_Ctrl::instance(); }
    inline I_TCP_Listener& getTCP_Listener_Fld() { return TCP_Listener_Fld::instance(); }
    inline I_TCP_Listener& getTCP_Listener_Gui() { return TCP_Listener_Gui::instance(); }
    inline I_TCP_Listener& getTCP_Listener_Ctrl() { return TCP_Listener_Ctrl::instance(); }
} // namespace
#endif // _H
