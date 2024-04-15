#include <SYS/IL.h>

#include <LCR/LCR_Hub.h>
#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Hub.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Com.h>
#include <SYS/Dispatcher.h>
#include <SYS/Log.h>
#include <SYS/Reader.h>
#include <TSW/TSW_Hub.h>
#include <TSW/TSW_Provider.h>

namespace IL
{
    I_Com& getCom() { return Com::instance(); }
    I_Dispatcher& getDispatcher() { return Dispatcher::instance(); }
    I_Hub& getLCR_Hub() { return LCR_Hub::instance(); }
    I_Hub& getSIG_Hub() { return SIG_Hub::instance(); }
    I_Hub& getTSW_Hub() { return TSW_Hub::instance(); }
    I_Log& getLog() { return Log::instance(); }
    I_Provider& getLCR_Provider() { return LCR_Provider::instance(); }
    I_Provider& getSIG_Provider() { return SIG_Provider::instance(); }
    I_Provider& getTSW_Provider() { return TSW_Provider::instance(); }
    I_Reader& getReader() { return Reader::instance(); }
} // namespace