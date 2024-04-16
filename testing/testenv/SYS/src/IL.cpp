#include <SYS/IL.h>

#include <mocks/M_Instances.h>
#include <BAS/coding.h>

#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Com.h>
#include <SYS/Dispatcher.h>
#include <SYS/Log.h>
#include <SYS/Reader.h>
#include <TSW/TSW_Provider.h>
#include <mocks/M_Com.h>
#include <mocks/M_Dispatcher.h>
#include <mocks/M_Log.h>
#include <mocks/M_Provider.h>


template <class T>
class ILPLug
{
public:
    inline ILPLug(T& ref):
        mDefault(ref),
        mPointer(&ref)
    {}

    inline void set(T& ref)
    {
        mPointer = &ref;
    }

    inline void reset()
    {
        mPointer = &mDefault;
    }

    inline T& ref() const
    {
        return *mPointer;
    }

private:
    T& mDefault;
    T* mPointer;
    NOCOPY(ILPLug)
    ILPLug();
};    

class ILPLugs
{
public:
    INSTANCE_DEC(ILPLugs)

    void reset();

    ILPLug<I_Com> mCom;
    ILPLug<I_Dispatcher> mDispatcher;
    ILPLug<I_Provider> mLCR_Provider;
    ILPLug<I_Provider> mSIG_Provider;
    ILPLug<I_Provider> mTSW_Provider;
    ILPLug<I_Log> mLog;

    inline void prodCom() { mCom.set(Com::instance()); }
    inline void prodDispatcher() { mDispatcher.set(Dispatcher::instance()); }
    inline void prodLCR_Provider() { mLCR_Provider.set(LCR_Provider::instance()); }
    inline void prodSIG_Provider() { mSIG_Provider.set(SIG_Provider::instance()); }
    inline void prodTSW_Provider() { mTSW_Provider.set(TSW_Provider::instance()); }
    inline void prodLog() { mLog.set(Log::instance()); }
    inline void prod()
    {
        prodCom();
        prodDispatcher();
        prodLCR_Provider();
        prodSIG_Provider();
        prodTSW_Provider();
        prodLog();
    }

    NOCOPY(ILPLugs)
private:
    ILPLugs();
};

INSTANCE_DEF(ILPLugs)

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

namespace IL
{
    I_Com& getCom() { return ILPLugs::instance().mCom.ref(); }
    void setCom(I_Com& ref) { ILPLugs::instance().mCom.set(ref); }

    I_Dispatcher& getDispatcher() { return ILPLugs::instance().mDispatcher.ref(); }
    void setDispatcher(I_Dispatcher& ref) { ILPLugs::instance().mDispatcher.set(ref); }

    I_Provider& getLCR_Provider() { return ILPLugs::instance().mLCR_Provider.ref(); }
    void setLCR_Provider(I_Provider& ref) { ILPLugs::instance().mLCR_Provider.set(ref); }

    I_Provider& getSIG_Provider() { return ILPLugs::instance().mSIG_Provider.ref(); }
    void setSIG_Provider(I_Provider& ref) { ILPLugs::instance().mSIG_Provider.set(ref); }

    I_Provider& getTSW_Provider() { return ILPLugs::instance().mTSW_Provider.ref(); }
    void setTSW_Provider(I_Provider& ref) { ILPLugs::instance().mTSW_Provider.set(ref); }

    I_Log& getLog() { return ILPLugs::instance().mLog.ref(); }
    void setLog(I_Log& ref) { ILPLugs::instance().mLog.set(ref); }

    void reset() { ILPLugs::instance().reset(); }
    void prod() { ILPLugs::instance().prod(); }
} // namespace

