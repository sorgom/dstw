//  ============================================================
//  class GuiCom implements I_GuiCom
//  - currently without functionality
//  ============================================================
//  created by Manfred Sorgo 

#pragma once
#ifndef GUICOM_H
#define GUICOM_H

#include <ifs/I_GuiCom.h>
#include <baselib/InstanceMacros.h>
#include <baselib/coding.h>

class GuiCom : public I_GuiCom
{
public:
    inline GuiCom() {}

    inline void send(const StateGui& tele) const {}

    DDI_INSTANCE_DEC(GuiCom)

    NOCOPY(GuiCom)
};

#endif // H_