//  ============================================================
//  Dispatcher implements I_Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <BAS/coding.h>
#include <BAS/NtpIndex.h>
#include <ifs/I_Dispatcher.h>

class Dispatcher : public I_Dispatcher
{
public:
    inline Dispatcher() = default;

    void reset();
    void index();

    const PosRes assign(const ComName& name, E_Comp comp, size_t pos);
    
    void dispatch(const ComFldState& tele) const;
    void dispatch(const ComGuiCmd&   tele) const;

    void dispatch(size_t id, ComCmdFld&&   tele) const;
    void dispatch(size_t id, ComStateGui&& tele) const;

    IL_INSTANCE_DEC(Dispatcher)

    NOCOPY(Dispatcher)

private:
    NtpIndex mIndx;
};

#endif // H_