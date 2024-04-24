#include <mocks/ILPlugs.h>

#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>
#include <mocks/M_Tcp.h>

#include <BAS/Tcp.h>
#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <COM/Com.h>
#include <SYS/Dispatcher.h>
#include <SYS/Log.h>
#include <SYS/Reader.h>
#include <TSW/TSW_Provider.h>


namespace test
{

    ILPLugs::ILPLugs():
        mCom(M_Com::instance()),
        mDispatcher(M_Dispatcher::instance()),
        mLCR_Provider(M_LCR_Provider::instance()),
        mSIG_Provider(M_SIG_Provider::instance()),
        mTSW_Provider(M_TSW_Provider::instance()),
        mLog(M_Log::instance()),
        mTcp(M_Tcp::instance())
    {}

    void ILPLugs::reset()
    {
        mCom.reset();
        mDispatcher.reset();
        mLCR_Provider.reset();
        mSIG_Provider.reset();
        mTSW_Provider.reset();
        mLog.reset();
        mTcp.reset();
    }

    void ILPLugs::unmock()
    {
        mCom.set(Com::instance());
        mDispatcher.set(Dispatcher::instance());
        mLCR_Provider.set(LCR_Provider::instance());
        mSIG_Provider.set(SIG_Provider::instance());
        mTSW_Provider.set(TSW_Provider::instance());
        mLog.set(Log::instance());
        mTcp.set(Tcp::instance());
    }

    INSTANCE_DEF(ILPLugs)

} // namespace
