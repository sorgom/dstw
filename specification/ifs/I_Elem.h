//  ============================================================
//  interface Elem
//  processing:
//  - GUI telegrams
//  - field telegrams
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_ELEM_H
#define I_ELEM_H

#include "ComTypes.h"

class I_Elem
{
public:
    //  process GUI telegram
    virtual void process(const ComTeleGui& tele) = 0;

    //  process field telegram
    virtual void process(const ComTeleFld& tele) = 0;

//  this is test code: type info if relevant
    virtual UINT8 type() { return 0; }    
};


#endif // H_