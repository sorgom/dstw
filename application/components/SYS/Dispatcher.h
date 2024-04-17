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

    void reset();
    void index();

    const PosRes assign(const ComName& name, E_Comp comp, size_t pos);
    
    void dispatch(const ComTeleFld& tele) const;
    void dispatch(const ComTeleGui&   tele) const;

    void dispatch(size_t id, ComTeleFld&& tele) const;
    void dispatch(size_t id, ComTeleGui&& tele) const;

    IL_INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NcpIndex mIndx;
    template <typename T> 
    void forward(I_Provider& prov, const Ncp& ncp, const T& tele) const
    {
        if (prov.size() > ncp.pos)
        {
            prov.at(ncp.pos).process(tele);
        }
    }
};

#endif // H_