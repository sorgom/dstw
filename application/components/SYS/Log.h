//  ============================================================
//  class Log implements I_Log
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo

#ifndef LOG_H
#define LOG_H

#include <ifs/I_Log.h>
#include <BAS/coding.h>

class Log : public I_Log
{
public:

    std::ostream& log(E_Comp comp, E_Ret ret);

    inline E_Ret maxerr() const
    {
        return mErr;
    }

    INSTANCE_DEC(Log)

    NOCOPY(Log)
private:
    E_Ret mErr = RET_NO_ERR;
    inline Log() = default;
};
#endif // _H
