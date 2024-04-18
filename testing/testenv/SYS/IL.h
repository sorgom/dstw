//  ============================================================
//  Interface Locator IL
//  - module test version
//  - all providers can be exchanged by mocks
//  - if no provider implemented in application: mock only
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TEST_IL_H
#define TEST_IL_H

#include <ifs/CompEnums.h>
#include <ifs/I_Com.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/I_Log.h>
#include <ifs/I_Provider.h>
#include <ifs/I_Reader.h>

#include <BAS/coding.h>

namespace IL
{
    I_Com& getCom();
    I_Dispatcher& getDispatcher();
    I_Provider& getLCR_Provider();
    I_Provider& getSIG_Provider();
    I_Provider& getTSW_Provider();
    I_Log& getLog();
 } // namespace

#endif // _H