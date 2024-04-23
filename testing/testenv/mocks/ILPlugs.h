#pragma once

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

        void unmock();

        NOCOPY(ILPLugs)
    private:
        ILPLugs();
    };

} // namespace

