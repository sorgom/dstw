//  ============================================================
//  interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_DISPATCHER_H
#define I_DISPATCHER_H

#include "SystemEnums.h"
#include "ComTypes.h"
#include "PosRes.h"

class I_Dispatcher
{
public:
    virtual void reset() = 0;
    virtual void index() = 0;

    //  ============================================================
    //  when loading project data
    //  components providers (TSW, SIG, LCR, SEG) 
    //  assign themselves with:
    //  - element name
    //  - component id
    //  - own processing element position
    //  and shall receive:
    //  - dispatcher id (position of responsible dispatcher element)
    //  ============================================================
    virtual const PosRes assign(const ComName& name, E_Comp comp, size_t pos) = 0;

    //  ============================================================
    //  field states shall be dispatched to components
    //  ============================================================
    virtual void dispatch(const ComTeleFld& tele) const = 0;

    //  ============================================================
    //  GUI commands shall be dispatched to components
    //  ============================================================
    virtual void dispatch(const ComTeleGui& tele) const = 0;

    //  ============================================================
    //  commands from components shall be dispatched to field
    //  ============================================================
    virtual void dispatch(size_t id, ComTeleFld&& tele) const = 0;

    //  ============================================================
    //  states from components shall be dispatched to GUI
    //  ============================================================
    virtual void dispatch(size_t id, ComTeleGui&& tele) const = 0;
};

#endif // H_
