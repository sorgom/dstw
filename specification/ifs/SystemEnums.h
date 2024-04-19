//  ============================================================
//  system wide enumerations
//  -   E_Comp  components
//  -   E_Err   errors
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SYSTEMENUMS_H
#define SYSTEMENUMS_H

#include <codebase/BaseTypes.h>

enum E_Comp : UINT8
{
    COMP_TSW,
    COMP_SIG,
    COMP_LCR,
    COMP_SEG,
    COMP_SYS
};

enum E_Err : UINT8
{
    NO_ERR,
    ERR_MATCH,
    ERR_RANGE,
    ERR_STARTUP
};
                
enum E_Param : UINT8
{
    PARAM_UNDEF = 255
};

#endif // _H