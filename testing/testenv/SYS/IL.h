//  ============================================================
//  Interface Locator IL
//  - test version
//  - exchange of providers by default
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <mocks/ILPlugs.h>
#include <SYS/Reader.h>
namespace IL
{
    inline I_Com& getCom() { return test::ILPLugs::instance().mCom.ref(); }
    inline I_Dispatcher& getDispatcher() { return test::ILPLugs::instance().mDispatcher.ref(); }
    inline I_Log& getLog() { return test::ILPLugs::instance().mLog.ref(); }
    inline I_Provider& getLCR_Provider() { return test::ILPLugs::instance().mLCR_Provider.ref(); }
    inline I_Provider& getSIG_Provider() { return test::ILPLugs::instance().mSIG_Provider.ref(); }
    inline I_Provider& getTSW_Provider() { return test::ILPLugs::instance().mTSW_Provider.ref(); }
    inline I_Reader& getReader() { return test::ILPLugs::instance().mReader.ref(); }
    inline I_TCP_Client& getTCP_Client_Ctrl() { return test::ILPLugs::instance().mTCP_Client_Ctrl.ref(); }
    inline I_TCP_Client& getTCP_Client_Fld() { return test::ILPLugs::instance().mTCP_Client_Fld.ref(); }
    inline I_TCP_Client& getTCP_Client_Gui() { return test::ILPLugs::instance().mTCP_Client_Gui.ref(); }
    inline I_TCP_Listener& getTCP_Listener_Ctrl() { return test::ILPLugs::instance().mTCP_Listener_Ctrl.ref(); }
    inline I_TCP_Listener& getTCP_Listener_Fld() { return test::ILPLugs::instance().mTCP_Listener_Fld.ref(); }
    inline I_TCP_Listener& getTCP_Listener_Gui() { return test::ILPLugs::instance().mTCP_Listener_Gui.ref(); }
    inline I_TCP& getTCP() { return test::ILPLugs::instance().mTCP.ref(); }
} // namespace

