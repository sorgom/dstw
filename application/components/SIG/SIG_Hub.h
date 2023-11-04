//  ============================================================
//  class SIG_Hub implements I_SIG_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_HUB_H
#define SIG_HUB_H

#include <BAS/coding.h>
#include <ifs/I_SIG_Hub.h>

class SIG_Hub : public I_SIG_Hub
{
public:
    inline SIG_Hub()
    {}

    void toFld(UINT32 id, INT32 state, INT32 speed) const;
    void toGui(UINT32 id, INT32 state, INT32 speed) const;

    void fromDsp(UINT32 pos, const FldState& tele) const;
    void fromDsp(UINT32 pos, const GuiCmd&   tele) const;

    IL_INSTANCE_DEC(SIG_Hub)

    NOCOPY(SIG_Hub)
};

#endif // _H
