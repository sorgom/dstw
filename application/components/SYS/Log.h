//  ============================================================
//  class Log implements I_Log
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo 

#pragma once

#include <ifs/I_Log.h>
#include <BAS/coding.h>

class Log : public I_Log
{
public:
    inline Log() = default;

    std::ostream& log(E_Comp comp, E_Ret ret);

    inline E_Ret maxerr() const
    {
        return mErr;
    }

    INSTANCE_DEC(Log)

    NOCOPY(Log)
private:
    E_Ret mErr = RET_NO_ERR;
};
