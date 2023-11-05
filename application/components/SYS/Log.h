//  ============================================================
//  class Log implements I_Log
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef LOG_H
#define LOG_H

#include <ifs/I_Log.h>
#include <BAS/coding.h>

class Log : public I_Log
{
public:
    inline Log() {}
    inline void log(E_Mod mod, E_Err err) {}

    IL_INSTANCE_DEC(Log)

    NOCOPY(Log)
};

#endif // H_