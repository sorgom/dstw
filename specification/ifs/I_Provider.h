//  ============================================================
//  interface Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_PROVIDER_H
#define I_PROVIDER_H

#include "ProjTypes.h"
#include "SystemEnums.h"

template <typename ELEM, typename PROJ>
class I_Provider
{
public:
    virtual bool has(size_t pos) const = 0;
    virtual ELEM& at(size_t pos) = 0;

    virtual void reset() = 0;
    virtual void load(const PROJ* data, UINT32 num) = 0;
};


#endif // H_