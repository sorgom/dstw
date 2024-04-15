//  ============================================================
//  component specific enumerations
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef COMP_ENUMS_H
#define COMP_ENUMS_H

#include "SystemEnums.h"

//  ============================================================
//  SIG types and states
//  ============================================================
enum E_SigType : UINT8
{
    SIG_TYPE_H = 100,
    SIG_TYPE_N,
    SIG_TYPE_H_N,
    SIG_TYPE_S
};

enum E_SigState : UINT8
{
    SIG_STATE_UNDEF = PARAM_UNDEF,
    SIG_STATE_DEFECT = 201,

    SIG_STATE_H0,
    SIG_STATE_H1,
    SIG_STATE_N0,
    SIG_STATE_N1,
    SIG_STATE_H0_N0,
    SIG_STATE_H0_N1,
    SIG_STATE_H1_N0,
    SIG_STATE_H1_N1,

    SIG_STATE_WAIT_H0,
    SIG_STATE_WAIT_H1,
    SIG_STATE_WAIT_N0,
    SIG_STATE_WAIT_N1,
    SIG_STATE_WAIT_H0_N0,
    SIG_STATE_WAIT_H0_N1,
    SIG_STATE_WAIT_H1_N0,
    SIG_STATE_WAIT_H1_N1
};

//  ============================================================
//  TSW commands and states
//  ============================================================
enum E_TswState : UINT8
{
    TSW_STATE_LEFT = 101,
    TSW_STATE_RIGHT,
    TSW_STATE_UNDEF,
    TSW_STATE_DEFECT,
    TSW_STATE_WAIT_LEFT,
    TSW_STATE_WAIT_RIGHT
};

enum E_TswGuiCmd : UINT8
{
    TSW_GUI_GMD_WU = 201,
    TSW_GUI_GMD_LEFT,
    TSW_GUI_GMD_RIGHT
};

//  ============================================================
//  TSW types and states
//  ============================================================
enum E_LcrType : UINT8
{
    LCR_TYPE_LCR = 100,
    LCR_TYPE_LCR_UBK
};

enum E_LcrState : UINT8
{
    LCR_STATE_UNDEF = PARAM_UNDEF,
    LCR_STATE_DEFECT = 101,
    LCR_STATE_OPEN,
    LCR_STATE_CLOSED,
    LCR_STATE_WAIT_OPEN,
    LCR_STATE_WAIT_CLOSED
};

enum E_LcrUbkState : UINT8
{
    LCR_UBK_STATE_UNDEF = PARAM_UNDEF,
    LCR_UBK_STATE_DEFECT = 201,
    LCR_UBK_STATE_OCCUPIED,
    LCR_UBK_STATE_FREE
};

#endif // _H