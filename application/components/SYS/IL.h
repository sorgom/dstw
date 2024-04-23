//  ============================================================
//  Interface Locator IL
//  - production application version
//  - no exchange of providers 
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Dispatcher.h>
#include <SYS/Com.h>
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
} // namespace

