//  ============================================================
//  system wide specified values
//  ============================================================
//  created by Manfred Sorgo

#ifndef VALUES_H
#define VALUES_H

#include <codebase/BaseTypes.h>

//  component identifiers
enum E_Comp : UINT8
{
    COMP_COM,
    COMP_TSW,
    COMP_SIG,
    COMP_LCR,
    COMP_SEG,
    COMP_SYS
};

//  return types
enum E_Ret : UINT8
{
    // no error
    RET_NO_ERR,
    //  element name not found
    //  or received state not valid
    RET_ERR_MATCH,
    //  element position out of range
    RET_ERR_RANGE,
    //  startup error in component
    RET_ERR_STARTUP,
    //  communication error
    RET_ERR_COM
};

//  reserved parameter values
enum E_Param : UINT8
{
    //  value not defined
    PARAM_UNDEF = 255
};

//  module types
enum E_Type : UINT8
{
    TYPE_LCR = 100,
    TYPE_LCR_UBK,
    TYPE_SEG,
    TYPE_SIG_H,
    TYPE_SIG_H_N,
    TYPE_SIG_N,
    TYPE_SIG_S,
    TYPE_TSW,
    TYPE_UNDEF = PARAM_UNDEF
};

//  SIG states
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

//  TSW commands and states
enum E_TswState : UINT8
{
    TSW_STATE_UNDEF = PARAM_UNDEF,
    TSW_STATE_LEFT = 101,
    TSW_STATE_RIGHT,
    TSW_STATE_DEFECT,
    TSW_STATE_WAIT_LEFT,
    TSW_STATE_WAIT_RIGHT
};

enum E_TswCmd : UINT8
{
    TSW_CMD_WU = 221,
    TSW_CMD_LEFT,
    TSW_CMD_RIGHT
};

//  LCR states
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

//  COM control
enum E_ComCtrl : UINT8
{
    COM_CTRL_STOP = 101,
    COM_CTRL_PING,
    COM_CTRL_RE_GUI
};
#endif // _H
