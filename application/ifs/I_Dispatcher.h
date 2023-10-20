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
    //  subsytems assign themselfs with:
    //  - element name
    //  - subsystem id
    //  - own processing element position
    //  and shall recieve:
    //  - dispatcher id
    //  ============================================================
    virtual INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos) = 0;

    //  ============================================================
    //  when sending telegrams
    //  subsytems shall retieve the assigned name with:
    //  - dispatcher id returned at assignement
    //  ============================================================
    virtual bool label(ElementName& name, UINT32 id) const = 0;

    //  ============================================================
    //  field states shall be dispatched to subsystems
    //  ============================================================
    virtual bool dispatch(const FldState& tele) const = 0;

    //  ============================================================
    //  GUI commands shall be dispatched to subsystems
    //  ============================================================
    virtual bool dispatch(const GuiCmd&   tele) const = 0;

};

#endif // H_