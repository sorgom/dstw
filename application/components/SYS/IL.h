//  ============================================================
//  Interface Locator IL
//  - production application version
//  - no exchange of providers 
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <COM/TCP.h>
#include <COM/TCP_Clients.h>
#include <COM/TCP_Listeners.h>
#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <COM/Com.h>
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
    inline I_TCP_Client& getTCP_Client_Fld() { return TCP_Client_Fld::instance(); }
    inline I_TCP_Client& getTCP_Client_Gui() { return TCP_Client_Gui::instance(); }
    inline I_TCP_Client& getTCP_Client_Ctrl() { return TCP_Client_Ctrl::instance(); }
    inline I_TCP_Listener& getTCP_Listener_Fld() { return TCP_Listener_Fld::instance(); }
    inline I_TCP_Listener& getTCP_Listener_Gui() { return TCP_Listener_Gui::instance(); }
    inline I_TCP_Listener& getTCP_Listener_Ctrl() { return TCP_Listener_Ctrl::instance(); }
} // namespace

