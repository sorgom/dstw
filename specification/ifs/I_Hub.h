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

class I_LCR_Hub : public I_Hub
{};
class I_SIG_Hub : public I_Hub
{};
class I_TSW_Hub : public I_Hub
{};


#endif // H_