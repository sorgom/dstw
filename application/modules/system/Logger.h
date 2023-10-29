//  ============================================================
//  class Logger implements I_Logger
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <ifs/I_Logger.h>
#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>

class Logger : public I_Logger
{
public:
    inline Logger() {}

    inline void log(E_Comp comp, E_Err err) {}

    DDI_INSTANCE_DEC(Logger)

    NOCOPY(Logger)
};

#endif // H_