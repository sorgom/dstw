//  ============================================================
//  class LCR_Hub implements I_LCR_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_HUB_H
#define LCR_HUB_H

#include <BAS/coding.h>
#include <ifs/I_LCR_Hub.h>

class LCR_Hub : public I_LCR_Hub
{
public:
    inline LCR_Hub()
    {}

    void toFld(size_t id, INT32 state) const;
    void toGui(size_t id, INT32 state, INT32 ubk) const;

    void fromDsp(size_t pos, const FldState& tele) const;
    void fromDsp(size_t pos, const GuiCmd&   tele) const;

    IL_INSTANCE_DEC(LCR_Hub)

    NOCOPY(LCR_Hub)
};

#endif // _H
