#include <mocks/ILPlugs.h>

#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>
#include <mocks/M_Reader.h>
#include <mocks/M_TCP.h>
#include <mocks/M_TCP_Con.h>
#include <mocks/M_TCP_Listener.h>

#include <COM/TCP.h>
#include <COM/TCP_Cons.h>
#include <COM/TCP_Listeners.h>
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
        mReader(M_Reader::instance()),
        mLog(M_Log::instance()),
        mTCP(M_TCP::instance()),
        mTCP_Con_Fld(M_TCP_Con_Fld::instance()),
        mTCP_Con_Gui(M_TCP_Con_Gui::instance()),
        mTCP_Con_Ctrl(M_TCP_Con_Ctrl::instance()),
        mTCP_Listener_Fld(M_TCP_Listener_Fld::instance()),
        mTCP_Listener_Gui(M_TCP_Listener_Gui::instance()),
        mTCP_Listener_Ctrl(M_TCP_Listener_Ctrl::instance())
    {}

    void ILPLugs::reset()
    {
        mCom.reset();
        mDispatcher.reset();
        mLCR_Provider.reset();
        mSIG_Provider.reset();
        mTSW_Provider.reset();
        mReader.reset();
        mLog.reset();
        mTCP.reset();
        mTCP_Con_Fld.reset();
        mTCP_Con_Gui.reset();
        mTCP_Con_Ctrl.reset();
        mTCP_Listener_Fld.reset();
        mTCP_Listener_Gui.reset();
        mTCP_Listener_Ctrl.reset();
    }

    void ILPLugs::unmock()
    {
        mCom.set(Com::instance());
        mDispatcher.set(Dispatcher::instance());
        mLCR_Provider.set(LCR_Provider::instance());
        mSIG_Provider.set(SIG_Provider::instance());
        mTSW_Provider.set(TSW_Provider::instance());
        mReader.set(Reader::instance());
        mLog.set(Log::instance());
        mTCP.set(TCP::instance());
        mTCP_Con_Fld.set(TCP_Con_Fld::instance());
        mTCP_Con_Gui.set(TCP_Con_Gui::instance());
        mTCP_Con_Ctrl.set(TCP_Con_Ctrl::instance());
        mTCP_Listener_Fld.set(TCP_Listener_Fld::instance());
        mTCP_Listener_Gui.set(TCP_Listener_Gui::instance());
        mTCP_Listener_Ctrl.set(TCP_Listener_Ctrl::instance());
    }

    INSTANCE_DEF(ILPLugs)

} // namespace
