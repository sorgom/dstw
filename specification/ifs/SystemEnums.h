//  ============================================================
//  system wide enumerations
//  -   E_Subsys subsytems 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SYSTEMENUMS_H
#define SYSTEMENUMS_H

enum E_Subsys
{
    SUBSYS_TSW,
    SUBSYS_SIG,
    SUBSYS_SEG,
    SUBSYS_LCR
};

enum E_Comp
{
    COMP_COM,
    COMP_DISPATCHER,
    COMP_LOADER,
    COMP_SIG,
    COMP_SIG_HUB,
    COMP_SIG_PROVIDER,
    COMP_TSW,
    COMP_TSW_HUB,
    COMP_TSW_PROVIDER
};

enum E_Err
{
    ERR_MATCH,
    ERR_RANGE,
    ERR_STARTUP
};
                

#endif // _H