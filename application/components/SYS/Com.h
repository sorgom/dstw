//  ============================================================
//  class Com implements I_Com
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef COM_H
#define COM_H

#include <ifs/I_Com.h>
#include <BAS/coding.h>

class Com : public I_Com
{
public:
    inline Com() {}
    inline void send(const CmdFld&   tele) const {}
    inline void send(const StateGui& tele) const {}

    IL_INSTANCE_DEC(Com)

    NOCOPY(Com)
};

#endif // H_