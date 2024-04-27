#pragma once

#include <ifs/I_Com.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/I_Log.h>
#include <ifs/I_Provider.h>
#include <ifs/I_Reader.h>
#include <ifs/I_TCP.h>

#include <BAS/coding.h>

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
        ILPLug<I_Reader> mReader;
        ILPLug<I_Log> mLog;
        ILPLug<I_TCP> mTCP;
        ILPLug<I_TCP_Con> mTCP_Con_Fld;
        ILPLug<I_TCP_Con> mTCP_Con_Gui;
        ILPLug<I_TCP_Con> mTCP_Con_Ctrl;
        ILPLug<I_TCP_Listener> mTCP_Listener_Fld;
        ILPLug<I_TCP_Listener> mTCP_Listener_Gui;
        ILPLug<I_TCP_Listener> mTCP_Listener_Ctrl;

        void unmock();

        NOCOPY(ILPLugs)
    private:
        ILPLugs();
    };

} // namespace

