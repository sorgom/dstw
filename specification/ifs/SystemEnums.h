//  ============================================================
//  system wide enumerations
//  -   E_Comp  components
//  -   E_Mod   modules
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

enum E_Mod : UINT8
{
    MOD_SYS_COM,
    MOD_SYS_DISPATCHER,
    MOD_SYS_READER,
    MOD_TSW,
    MOD_TSW_HUB,
    MOD_TSW_PROVIDER,
    MOD_SIG,
    MOD_SIG_HUB,
    MOD_SIG_PROVIDER,
    MOD_LCR,
    MOD_LCR_HUB,
    MOD_LCR_PROVIDER,
    MOD_SEG,
    MOD_SEG_HUB,
    MOD_SEG_PROVIDER
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