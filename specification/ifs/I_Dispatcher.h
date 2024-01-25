//  ============================================================
//  interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_DISPATCHER_H
#define I_DISPATCHER_H

#include <ifs/SystemEnums.h>
#include <ifs/DataTypes.h>

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
    virtual INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos) = 0;

    //  ============================================================
    //  field states shall be dispatched to subsystems
    //  ============================================================
    virtual void dispatch(const FldState& tele) const = 0;

    //  ============================================================
    //  GUI commands shall be dispatched to subsystems
    //  ============================================================
    virtual void dispatch(const GuiCmd& tele) const = 0;

    //  ============================================================
    //  commands from subsystems shall be dispatched to field
    //  ============================================================
    virtual void dispatch(UINT32 id, const CmdFld& tele) const = 0;

    //  ============================================================
    //  states from subsystems shall be dispatched to GUI
    //  ============================================================
    virtual void dispatch(UINT32 id, const StateGui& tele) const = 0;
};

#endif // H_
