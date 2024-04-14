//  ============================================================
//  class TSW_Hub implements I_TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_HUB_H
#define TSW_HUB_H

#include <BAS/coding.h>
#include <ifs/I_TSW_Hub.h>

class TSW_Hub : public I_TSW_Hub
{
public:
    inline TSW_Hub()
    {}

    void toFld(size_t id, UINT8 cmd) const;
    void toGui(size_t id, UINT8 state) const;

    void fromDsp(size_t pos, const ComTeleFld& tele) const;
    void fromDsp(size_t pos, const ComTeleGui&   tele) const;

    IL_INSTANCE_DEC(TSW_Hub)

    NOCOPY(TSW_Hub)
};

#endif // _H
