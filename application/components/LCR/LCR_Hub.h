//  ============================================================
//  class LCR_Hub implements I_LCR_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef LCR_HUB_H
#define LCR_HUB_H

#include <BAS/BAS_Hub.h>

class LCR_Hub : public BAS_Hub
{
public:
    inline LCR_Hub() = default;

    IL_INSTANCE_DEC(LCR_Hub)

    NOCOPY(LCR_Hub)
protected:
    inline I_Provider& getProvider() const
    {
        return IL::getLCR_Provider();
    }    
};

#endif // _H
