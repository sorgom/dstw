//  ============================================================
//  Interface Locator IL
//  - module test version
//  - all providers can be exchanged by mocks
//  - if no provider implemented in application: mock only
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef IL_H
#define IL_H

#include <ifs/CompEnums.h>
#include <ifs/I_Com.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/I_Hub.h>
#include <ifs/I_Log.h>
#include <ifs/I_Provider.h>
#include <ifs/I_Reader.h>

#include <BAS/coding.h>

namespace IL
{
    I_Com& getCom();
    void setCom(I_Com& ref);

    I_Dispatcher& getDispatcher();
    void setDispatcher(I_Dispatcher& ref);

    I_Provider& getLCR_Provider();
    void setLCR_Provider(I_Provider& ref);

    I_Provider& getSIG_Provider();
    void setSIG_Provider(I_Provider& ref);

    I_Provider& getTSW_Provider();
    void setTSW_Provider(I_Provider& ref);

    I_Log& getLog();
    void setLog(I_Log& ref);

    void reset();
    void prod();
} // namespace

#endif // _H