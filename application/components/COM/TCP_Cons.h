//  ============================================================
//  TCP client classes and instances
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_TCP.h>
#include <ifs/DataTypes.h>
#include <BAS/coding.h>

//  base tcp communication client
class TCP_Con_Base : public I_TCP_Con
{
public:
    bool accept(INT32 socket) override;
    bool select() override;
    void close() override;
    void send(const ComTele& tele) const override;
    NOCOPY(TCP_Con_Base)
protected:
    inline TCP_Con_Base() = default;
    virtual void onAccept() const = 0;
    virtual void forward(const ComTele& tele) const = 0;
private:
    INT32 mSocket = -1;
    ComTele mTele;
};

//  field tcp communication client
class TCP_Con_Fld : public TCP_Con_Base
{
public:
    inline TCP_Con_Fld() = default;
    INSTANCE_DEC(TCP_Con_Fld)
    NOCOPY(TCP_Con_Fld)
protected:
    void onAccept() const override;
    void forward(const ComTele& tele) const override;
};

//  GUI tcp communication client
class TCP_Con_Gui : public TCP_Con_Base
{
public:
    inline TCP_Con_Gui() = default;
    INSTANCE_DEC(TCP_Con_Gui)  
    NOCOPY(TCP_Con_Gui) 
protected:
    void onAccept() const override;
    void forward(const ComTele& tele) const override;
};

//  control tcp communication client
class TCP_Con_Ctrl : public TCP_Con_Base
{
public:
    inline TCP_Con_Ctrl() = default;
    INSTANCE_DEC(TCP_Con_Ctrl)
    NOCOPY(TCP_Con_Ctrl)
protected:
    inline void onAccept() const override {}
    void forward(const ComTele& tele) const override;
};