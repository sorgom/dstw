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

#include "I_LCR.h"
class I_LCR_Provider : public I_Provider<I_LCR, ProjLCR>
{};

#include "I_SIG.h"
class I_SIG_Provider : public I_Provider<I_SIG, ProjSIG>
{};

#include "I_TSW.h"
class I_TSW_Provider : public I_Provider<I_TSW, ProjTSW>
{};

#endif // H_