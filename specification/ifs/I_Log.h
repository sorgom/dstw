//  ============================================================
//  interface Log
//  - runtime error logging
//  ============================================================
//  created by Manfred Sorgo

#ifndef I_LOG_H
#define I_LOG_H

#include "values.h"
#include <ostream>

class I_Log
{
public:
    virtual std::ostream& log(E_Comp comp, E_Ret ret) = 0;
    virtual E_Ret maxerr() const = 0;
};
#endif // _H
