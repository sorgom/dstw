//  ============================================================
//  interface Loader
//  the Loader is called at system start and shall:
//  -   reset I_Dispatcher
//  -   distribute load to subsystems
//  -   call indexing of I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef I_LOADER_H
#define I_LOADER_H

#include <ifs/ProjData.h>

class I_Loader
{
public:
    virtual void load(const ProjData& data) const = 0;
};

#endif // H_