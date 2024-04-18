#include <mocks/ILPlugs.h>
#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>

ILPLugs::ILPLugs():
    mCom(test::M_Com::instance()),
    mDispatcher(test::M_Dispatcher::instance()),
    mLCR_Provider(test::M_LCR_Provider::instance()),
    mSIG_Provider(test::M_SIG_Provider::instance()),
    mTSW_Provider(test::M_TSW_Provider::instance()),
    mLog(test::M_Log::instance())
{}

void ILPLugs::reset()
{
    mCom.reset();
    mDispatcher.reset();
    mLCR_Provider.reset();
    mSIG_Provider.reset();
    mTSW_Provider.reset();
    mLog.reset();
}

INSTANCE_DEF(ILPLugs)

