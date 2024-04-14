//  ============================================================
//  class SIG_Hub implements I_SIG_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef SIG_HUB_H
#define SIG_HUB_H

#include <BAS/coding.h>
#include <ifs/I_SIG_Hub.h>

class SIG_Hub : public I_SIG_Hub
{
public:
    inline SIG_Hub()
    {}

    void toFld(size_t id, UINT8 state, UINT8 speed = 0) const;
    void toGui(size_t id, UINT8 state, UINT8 speed = 0) const;

    void fromDsp(size_t pos, const ComTeleFld& tele) const;
    void fromDsp(size_t pos, const ComTeleGui&   tele) const;

    IL_INSTANCE_DEC(SIG_Hub)

    NOCOPY(SIG_Hub)
};

#endif // _H
