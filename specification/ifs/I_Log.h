//  ============================================================
//  interface Log
//  - runtime error logging
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LOGGER_H
#define I_LOGGER_H

#include "SystemEnums.h"

class I_Log
{
public:
    virtual void log(E_Comp comp, E_Err err) = 0;
};

#endif // H_