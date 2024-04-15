//  ============================================================
//  class BAS_Hub implements I_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef BAS_HUB_H
#define BAS_HUB_H

#include <BAS/coding.h>
#include <ifs/I_Hub.h>
#include <ifs/I_Provider.h>
#include <SYS/IL.h>

class BAS_Hub : public I_Hub
{
public:

    inline void toFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
    {
        IL::getDispatcher().dispatch(id, ComTeleFld(param1, param2));
    }

    inline void toGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const
    {
        IL::getDispatcher().dispatch(id, ComTeleGui(param1, param2));
    }

    void fromDsp(size_t pos, const ComTeleFld& tele) const;

    void fromDsp(size_t pos, const ComTeleGui& tele) const;

protected:
    virtual I_Provider& getProvider() const = 0;
};

#endif // _H
