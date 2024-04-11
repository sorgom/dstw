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
    //  subsystems assign themselves with:
    //  - element name
    //  - subsystem id
    //  - own processing element position
    //  and shall receive:
    //  - dispatcher id
    //  ============================================================
    virtual const PosRes assign(const ComName& name, E_Comp comp, size_t pos) = 0;

    //  ============================================================
    //  field states shall be dispatched to subsystems
    //  ============================================================
    virtual void dispatch(const ComFldState& tele) const = 0;

    //  ============================================================
    //  GUI commands shall be dispatched to subsystems
    //  ============================================================
    virtual void dispatch(const ComGuiCmd& tele) const = 0;

    //  ============================================================
    //  commands from subsystems shall be dispatched to field
    //  ============================================================
    virtual void dispatch(size_t id, ComCmdFld&& tele) const = 0;

    //  ============================================================
    //  states from subsystems shall be dispatched to GUI
    //  ============================================================
    virtual void dispatch(size_t id, ComStateGui&& tele) const = 0;
};

#endif // H_
