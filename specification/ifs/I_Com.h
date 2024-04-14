//  ============================================================
//  Interface Com
//  - field and GUI communication device
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef I_COM_H
#define I_COM_H

#include "ComTypes.h"

class I_Com
{
public:
    virtual void send(const ComTeleFld&   tele) const = 0;
    virtual void send(const ComTeleGui& tele) const = 0;
};

#endif // H_