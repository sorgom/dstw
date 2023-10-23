//  ============================================================
//  Interface GuiCom
//  - field communication device
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef I_GUICOM_H
#define I_GUICOM_H

#include <ifs/DataTypes.h>

class I_GuiCom
{
public:
    virtual bool send(const StateGui& tele) const = 0;
};

#endif // H_