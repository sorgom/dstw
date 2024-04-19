#include <SYS/IL.h>

#include <mocks/M_Instances.h>
#include <BAS/coding.h>
#include <mocks/ILPlugs.h>

namespace IL
{
    I_Dispatcher& getDispatcher() { return test::ILPLugs::instance().mDispatcher.ref(); }
    I_Provider& getLCR_Provider() { return test::ILPLugs::instance().mLCR_Provider.ref(); }
    I_Provider& getSIG_Provider() { return test::ILPLugs::instance().mSIG_Provider.ref(); }
    I_Provider& getTSW_Provider() { return test::ILPLugs::instance().mTSW_Provider.ref(); }
    I_Log& getLog() { return test::ILPLugs::instance().mLog.ref(); }
} // namespace

