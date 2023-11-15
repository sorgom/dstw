//  ============================================================
//  interface LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_LCR_PROVIDER_H
#define I_LCR_PROVIDER_H

#include <ifs/I_LCR.h>
#include <ifs/ProjData.h>

class I_LCR_Provider
{
public:
    virtual bool has(UINT32 pos) const = 0;
    virtual I_LCR& at(UINT32 pos) = 0;

    virtual void load(const ProjLCR* data, UINT32 num) = 0;
};


#endif // H_