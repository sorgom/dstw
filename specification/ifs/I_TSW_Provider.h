//  ============================================================
//  interface TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_PROVIDER_H
#define I_TSW_PROVIDER_H

#include <ifs/I_TSW.h>

class I_TSW_Provider
{
public:
    virtual void reset() = 0;
    virtual UINT32 capacity() const = 0;
    virtual bool has(UINT32 pos) const = 0;
    virtual void add(UINT32 id) = 0;
    virtual I_TSW& at(UINT32 pos) = 0;
};

#endif // H_