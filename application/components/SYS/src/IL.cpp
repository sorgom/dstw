#include <SYS/IL.h>

#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Dispatcher.h>
#include <SYS/Log.h>
#include <SYS/Reader.h>
#include <TSW/TSW_Provider.h>

namespace IL
{
    I_Dispatcher& getDispatcher() { return Dispatcher::instance(); }
    I_Log& getLog() { return Log::instance(); }
    I_Provider& getLCR_Provider() { return LCR_Provider::instance(); }
    I_Provider& getSIG_Provider() { return SIG_Provider::instance(); }
    I_Provider& getTSW_Provider() { return TSW_Provider::instance(); }
    I_Reader& getReader() { return Reader::instance(); }
} // namespace