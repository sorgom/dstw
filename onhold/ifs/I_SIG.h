//  ============================================================
//  interface SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIG_H
#define I_SIG_H

#include "SystemEnums.h"
#include "I_SIG_Hub.h"

class I_SIG
{
public:
//  commands from GUI

    virtual E_Result HN0() = 0;
    virtual E_Result HN1() = 0;

//  infos from field element

    virtual void fromFld(E_SigTromFld rcv) = 0;
};

#endif // _H