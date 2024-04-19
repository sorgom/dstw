//  ============================================================
//  Interface Locator IL
//  - production application version
//  - no exchange of providers 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef IL_H
#define IL_H

#include <ifs/I_Com.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/values.h>
#include <ifs/I_Log.h>
#include <ifs/I_Provider.h>
#include <ifs/I_Reader.h>

#include <BAS/coding.h>

namespace IL
{
    I_Com& getCom();
    I_Dispatcher& getDispatcher();
    I_Log& getLog();
    I_Provider& getLCR_Provider();
    I_Provider& getSIG_Provider();
    I_Provider& getTSW_Provider();
    I_Reader& getReader();
} // namespace

#endif // _H