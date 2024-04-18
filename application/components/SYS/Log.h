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
#include <algorithm>

class Log : public I_Log
{
public:
    inline Log(): mErr(NO_ERR) {}
    inline void log(E_Comp comp, E_Err err)
    {
        mErr = std::max(mErr, err);
    }

    inline E_Err maxerr() const
    {
        return mErr;
    }

    INSTANCE_DEC(Log)

    NOCOPY(Log)
private:
    E_Err mErr;
};

#endif // H_