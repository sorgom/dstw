//  ============================================================
//  class SIG_Hub implements I_SIG_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_HUB_H
#define SIG_HUB_H

#include <BAS/BAS_Hub.h>

class SIG_Hub : public BAS_Hub
{
public:
    inline SIG_Hub() = default;

    IL_INSTANCE_DEC(SIG_Hub)

    NOCOPY(SIG_Hub)
protected:
    inline I_Provider& getProvider() const
    {
        return IL::getSIG_Provider();
    }    
};

#endif // _H
