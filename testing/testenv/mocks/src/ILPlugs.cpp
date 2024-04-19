#include <mocks/ILPlugs.h>
#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>

namespace test
{

    ILPLugs::ILPLugs():
        mCom(M_Com::instance()),
        mDispatcher(M_Dispatcher::instance()),
        mLCR_Provider(M_LCR_Provider::instance()),
        mSIG_Provider(M_SIG_Provider::instance()),
        mTSW_Provider(M_TSW_Provider::instance()),
        mLog(M_Log::instance())
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

} // namespace
