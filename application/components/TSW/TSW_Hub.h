//  ============================================================
//  class TSW_Hub implements I_TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_HUB_H
#define TSW_HUB_H

#include <BAS/BAS_Hub.h>

class TSW_Hub : public BAS_Hub
{
public:
    inline TSW_Hub() = default;

    IL_INSTANCE_DEC(TSW_Hub)

    NOCOPY(TSW_Hub)
protected:
    inline I_Provider& getProvider() const
    {
        return IL::getTSW_Provider();
    }    
};

#endif // _H
