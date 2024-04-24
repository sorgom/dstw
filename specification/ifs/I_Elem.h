//  ============================================================
//  interface Elem
//  processing:
//  - commands from GUI
//  - states from field
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include "DataTypes.h"

class I_Elem
{
public:
    //  process field states
    virtual void fromFld(const ComData& data) = 0;

    //  process GUI commands
    virtual void fromGui(const ComData& data) = 0;

    //  this is test code: type info if relevant
    virtual E_Type type() const = 0;
};
