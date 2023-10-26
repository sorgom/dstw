//  ============================================================
//  class TSW_Hub implements I_TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_HUB_H
#define TSW_HUB_H

#include <baselib/coding.h>
#include <baselib/InstanceMacros.h>
#include <ifs/I_TSW_Hub.h>

class TSW_Hub : public I_TSW_Hub
{
public:
    inline TSW_Hub()
    {}

    void toFld(UINT32 id, INT32 cmd) const;
    void toGui(UINT32 id, INT32 state) const;

    void fromFld(const FldState& tele, UINT32 pos);
    void fromGui(const GuiCmd&   tele, UINT32 pos);

    DDI_INSTANCE_DEC(TSW_Hub)

    NOCOPY(TSW_Hub)
};

#endif // _H
