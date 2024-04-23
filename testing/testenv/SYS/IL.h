//  ============================================================
//  Interface Locator IL
//  - production application version
//  - no exchange of providers 
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <mocks/ILPlugs.h>

namespace IL
{
    inline I_Com& getCom() { return test::ILPLugs::instance().mCom.ref(); }
    inline I_Dispatcher& getDispatcher() { return test::ILPLugs::instance().mDispatcher.ref(); }
    inline I_Log& getLog() { return test::ILPLugs::instance().mLog.ref(); }
    inline I_Provider& getLCR_Provider() { return test::ILPLugs::instance().mLCR_Provider.ref(); }
    inline I_Provider& getSIG_Provider() { return test::ILPLugs::instance().mSIG_Provider.ref(); }
    inline I_Provider& getTSW_Provider() { return test::ILPLugs::instance().mTSW_Provider.ref(); }
    inline I_Reader& getReader() { return Reader::instance(); }
} // namespace

