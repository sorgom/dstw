//  ============================================================
//  Interface FldCom
//  - field communication device
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef I_FLDCOM_H
#define I_FLDCOM_H

#include <ifs/DataTypes.h>

class I_FldCom
{
public:
    virtual void send(const CmdFld& tele) const = 0;
};

#endif // H_