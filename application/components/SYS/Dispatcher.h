//  ============================================================
//  Dispatcher implements I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <BAS/coding.h>
#include <BAS/NcpIndex.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/I_Provider.h>

class Dispatcher : public I_Dispatcher
{
public:
    inline Dispatcher() = default;

    void clear();
    void index();

    const PosRes assign(const ComName& name, E_Comp comp, size_t pos);
    
    void fromFld(const ComTele& tele) const;
    void fromGui(const ComTele& tele) const;

    void toFld(size_t id, const ComData& data) const;
    void toGui(size_t id, const ComData& data) const;

    INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NcpIndex mIndx;
    static void forwardFld(I_Provider& prov, const Ncp& ncp, const ComTele& tele);
    static void forwardGui(I_Provider& prov, const Ncp& ncp, const ComTele& tele);
};

#endif // H_