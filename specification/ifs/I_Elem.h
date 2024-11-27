//  ============================================================
//  interface Elem
//  processing:
//  - commands from GUI
//  - states from field
//  ============================================================
//  created by Manfred Sorgo

#ifndef I_ELEM_H
#define I_ELEM_H

#include "DataTypes.h"

class I_Elem
{
public:
    //  process field states
    virtual void fromFld(const ComData& data) = 0;

    //  process GUI commands
    virtual void fromGui(const ComData& data) = 0;

    //  re-send current state to GUI
    virtual void toGui() const = 0;

    inline virtual ~I_Elem() = default;
};
#endif // _H
