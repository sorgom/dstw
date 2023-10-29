//  ============================================================
//  class FldCom implements I_FldCom
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef FLDCOM_H
#define FLDCOM_H

#include <ifs/I_FldCom.h>
#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>

class FldCom : public I_FldCom
{
public:
    inline void send(const CmdFld& tele) const {}

    DDI_INSTANCE_DEC(FldCom)

    NOCOPY(FldCom)
};

#endif // H_