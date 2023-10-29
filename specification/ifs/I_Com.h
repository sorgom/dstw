//  ============================================================
//  Interface Com
//  - field and GUI communication device
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef I_COM_H
#define I_COM_H

#include <ifs/DataTypes.h>

class I_Com
{
public:
    virtual void send(const CmdFld&   tele) const = 0;
    virtual void send(const StateGui& tele) const = 0;
};

#endif // H_