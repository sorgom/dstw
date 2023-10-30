//  ============================================================
//  interface TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_PROVIDER_H
#define I_TSW_PROVIDER_H

#include <ifs/I_TSW.h>
#include <ifs/ProjData.h>

class I_TSW_Provider
{
public:
    virtual bool has(UINT32 pos) const = 0;
    virtual I_TSW& at(UINT32 pos) = 0;

    virtual void load(const ProjTSW* data, UINT32 num) = 0;
};

#endif // H_