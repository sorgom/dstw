//  ============================================================
//  interface Loader
//  the Loader is called at sytem start and shall:
//  -   reset I_Dispatcher
//  -   distribute load to subsytems
//  -   call indexing of I_Dispatcher
//  -   in case of any subsystem load failure
//      -   reset I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef I_LOADER_H
#define I_LOADER_H

#include <ifs/ProjData.h>

class I_Loader
{
public:
    virtual bool load(const ProjData& data) const = 0;
};

#endif // H_