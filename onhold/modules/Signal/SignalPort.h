#pragma once
#ifndef SIG_HUB_H
#define SIG_HUB_H

#include <ifs/I_SIG_Hub.h>
#include <baselib/InstanceMacros.h>

class SIG_Hub : public I_SIG_Hub
{
public:
//  NO_COV >>
    inline void toFld(E_SigToFld cmd) const {}
    inline void toGui(E_SigToGui cmd) const {}
//  << NO_COV

    DDI_INSTANCE_DEC(SIG_Hub)
};

#endif // _H
