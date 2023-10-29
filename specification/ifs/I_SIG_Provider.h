//  ============================================================
//  interface SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIG_PROVIDER_H
#define I_SIG_PROVIDER_H

#include <ifs/I_SIG.h>
#include <ifs/ProjData.h>

class I_SIG_Provider
{
public:
    virtual bool has(UINT32 pos) const = 0;
    virtual I_SIG& at(UINT32 pos) = 0;

    virtual void load(const ProjSIG* data, UINT32 num) = 0;
};

#endif // H_