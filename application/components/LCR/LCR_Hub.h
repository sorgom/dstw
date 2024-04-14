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
    inline LCR_Hub() = default;

    void toFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const;
    void toGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const;

    void fromDsp(size_t pos, const ComTeleFld& tele) const;
    void fromDsp(size_t pos, const ComTeleGui& tele) const;

    IL_INSTANCE_DEC(LCR_Hub)

    NOCOPY(LCR_Hub)
};

#endif // _H
