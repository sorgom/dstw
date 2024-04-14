//  ============================================================
//  interface LCR_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LCR_HUB_H
#define I_LCR_HUB_H

#include "ComTypes.h"
#include "I_LCR.h"

class I_LCR_Hub
{
public:
    virtual void toFld(size_t id, UINT8 state) const = 0;
    virtual void toGui(size_t id, UINT8 state, UINT8 ubk = LCR_UBK_STATE_UNDEF) const = 0;

    virtual void fromDsp(size_t pos, const ComTeleFld& tele) const = 0;
    virtual void fromDsp(size_t pos, const ComTeleGui&   tele) const = 0;
};

#endif // H_