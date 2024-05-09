//  ============================================================
//  Dispatcher implements I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once

#include <BAS/coding.h>
#include <BAS/NcpIndex.h>
#include <ifs/I_Dispatcher.h>
#include <ifs/I_Provider.h>

class Dispatcher : public I_Dispatcher
{
public:

    void clear() override;
    void index() override;

    const PosRes assign(const ComName& name, E_Comp comp, size_t pos) override;
    
    void fromFld(const ComTele& tele) const override;
    void fromGui(const ComTele& tele) const override;

    void toFld(size_t id, const ComData& data) const override;
    void toGui(size_t id, const ComData& data) const override;

    void reGui() const override;

    INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NcpIndex mIndx;
    inline Dispatcher() = default;
    static void forwardFld(I_Provider& prov, const Ncp& ncp, const ComTele& tele);
    static void forwardGui(I_Provider& prov, const Ncp& ncp, const ComTele& tele);
    static void reGui(I_Provider& prov);
};
