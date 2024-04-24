//  ============================================================
//  interface Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include "I_Elem.h"
#include "DataTypes.h"

class I_Provider
{
public:
    virtual size_t size() const = 0;
    virtual I_Elem& at(size_t pos) = 0;

    virtual void clear() = 0;
    virtual void load(const ProjItem* data, UINT32 num) = 0;
};
