#include <SYS/IL.h>

#include <mocks/M_Instances.h>
#include <BAS/coding.h>
#include <mocks/ILPlugs.h>

namespace IL
{
    I_Dispatcher& getDispatcher() { return ILPLugs::instance().mDispatcher.ref(); }
    I_Provider& getLCR_Provider() { return ILPLugs::instance().mLCR_Provider.ref(); }
    I_Provider& getSIG_Provider() { return ILPLugs::instance().mSIG_Provider.ref(); }
    I_Provider& getTSW_Provider() { return ILPLugs::instance().mTSW_Provider.ref(); }
    I_Log& getLog() { return ILPLugs::instance().mLog.ref(); }
} // namespace

