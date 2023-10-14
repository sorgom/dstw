//  ============================================================
//  interface RastaPort
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_RASTAPORT_H
#define I_RASTAPORT_H

#include <ifs/DataTypes.h>

enum E_RastaType
{
    RASTA_TSW,
    RASTA_SIG
};

class I_RastaPort
{
public:
    virtual void send(const RastaTelegram& tele) = 0;
};

#endif // H_