#pragma once
#ifndef ILPLUGS_H
#define ILPLUGS_H

#include <LCR/LCR_Provider.h>
#include <SIG/SIG_Provider.h>
#include <SYS/Com.h>
#include <SYS/Dispatcher.h>
#include <SYS/Log.h>
#include <SYS/Reader.h>
#include <TSW/TSW_Provider.h>

namespace test
{

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

} // namespace

#endif // _H