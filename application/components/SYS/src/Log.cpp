#include <SYS/Log.h>

#include <algorithm>
#include <iostream>

INSTANCE_DEF(Log)

std::ostream& Log::log(E_Comp comp, E_Ret ret)
{
    mErr = std::max(mErr, ret);
    return std::cerr;
}
