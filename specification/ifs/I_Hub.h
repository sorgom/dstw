//  ============================================================
//  interface Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_HUB_H
#define I_HUB_H

#include "ComTypes.h"
#include "SystemEnums.h"

class I_Hub
{
public:
    virtual void toFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const = 0;
    virtual void toGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const = 0;

    virtual void fromDsp(size_t pos, const ComTeleFld& tele) const = 0;
    virtual void fromDsp(size_t pos, const ComTeleGui& tele) const = 0;
};

#endif // H_