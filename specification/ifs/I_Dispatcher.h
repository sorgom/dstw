//  ============================================================
//  interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include "values.h"
#include "DataTypes.h"

class I_Dispatcher
{
public:
    virtual void clear() = 0;
    virtual void index() = 0;

    //  when loading project data
    //  components providers (TSW, SIG, LCR, SEG)
    //  assign themselves with:
    //  - element name
    //  - component id
    //  - own processing element position
    //  and shall receive:
    //  - dispatcher id (position of responsible dispatcher element)
    virtual const PosRes assign(const ComName& name, E_Comp comp, size_t pos) = 0;

    //  field state telegrams shall be dispatched to components
    virtual void fromFld(const ComTele& tele) const = 0;

    //  GUI command telegrams shall be dispatched to components
    virtual void fromGui(const ComTele& tele) const = 0;

    //  element commands shall be dispatched to field
    virtual void toFld(size_t id, const ComData& data) const = 0;

    //  element states shall be dispatched to GUI
    virtual void toGui(size_t id, const ComData& data) const = 0;

    //  dispatcher shall re-send all GUI states when triggered
    virtual void reGui() const = 0;
};
