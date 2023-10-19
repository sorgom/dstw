//  ============================================================
//  interface TrackSwitchFactory
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TRACKSWITCHFACTORY_H
#define I_TRACKSWITCHFACTORY_H

#include <ifs/I_TrackSwitch.h>

class I_TrackSwitchFactory
{
public:
    virtual void reset() = 0;
    virtual UINT32 size() const = 0;
    virtual UINT32 capacity() const = 0;
    virtual void add(UINT32 id) = 0;
    virtual I_TrackSwitch& at(UINT32 pos) = 0;
};

#endif // H_