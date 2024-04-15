//  ============================================================
//  interface Provider and derived interfaces:
//  - I_TSW_Provider
//  - I_SIG_Provider
//  - I_LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_PROVIDER_H
#define I_PROVIDER_H

#include "ProjItem.h"
#include "I_Elem.h"
#include "SystemEnums.h"

class I_Provider
{
public:
    virtual bool has(size_t pos) const = 0;
    virtual I_Elem& at(size_t pos) = 0;

    virtual void reset() = 0;
    virtual void load(const ProjItem* data, UINT32 num) = 0;
};

class I_TSW_Provider : public I_Provider
{};

class I_SIG_Provider : public I_Provider
{};

class I_LCR_Provider : public I_Provider
{};



#endif // H_