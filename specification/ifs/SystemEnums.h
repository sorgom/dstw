//  ============================================================
//  system wide enumerations
//  -   E_Result commonly used result type
//  -   E_Subsys subsytems 
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SYSTEMENUMS_H
#define SYSTEMENUMS_H

enum E_Result
{
    RESULT_FAIL = -1,
    RESULT_OK   = 0
};

enum E_Subsys
{
    SUBSYS_TSW,
    SUBSYS_SIG,
    SUBSYS_SEG,
    SUBSYS_LCR
};

#endif // _H