//  ============================================================
//  interface SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIG_TYPE_H
#define I_SIG_TYPE_H

#include <baselib/BaseTypes.h>

enum E_SigType
{
    SIG_TYPE_MAIN = 100,
    SIG_TYPE_SUPP,
    SIG_TYPE_MAIN_SUPP,
    SIG_TYPE_SHUNT
};

class I_SIG
{
public:
//  commands from GUI
    virtual void fromGui(INT32 cmd1, INT32 cmd2, INT32 cmd3) = 0;

//  infos from field element
    virtual void fromFld(INT32 state1, INT32 state2, INT32 state3) = 0;

//  type info
    virtual INT32 type() const = 0;    
};

#endif // _H