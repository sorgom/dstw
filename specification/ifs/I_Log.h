//  ============================================================
//  interface Log
//  - runtime error logging
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LOGGER_H
#define I_LOGGER_H

#include "values.h"

class I_Log
{
public:
    virtual void log(E_Comp comp, E_Ret ret) = 0;
    virtual E_Ret maxerr() const = 0;
};

#endif // H_