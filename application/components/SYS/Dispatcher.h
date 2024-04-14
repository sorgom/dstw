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

class Dispatcher : public I_Dispatcher
{
public:
    inline Dispatcher() = default;

    void reset();
    void index();

    const PosRes assign(const ComName& name, E_Comp comp, size_t pos);
    
    void dispatch(const ComTeleFld& tele) const;
    void dispatch(const ComTeleGui&   tele) const;

    void dispatch(size_t id, ComTeleFld&&   tele) const;
    void dispatch(size_t id, ComTeleGui&& tele) const;

    IL_INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NcpIndex mIndx;
};

#endif // H_