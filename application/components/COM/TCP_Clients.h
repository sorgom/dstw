//  ============================================================
//  TCP client classes and instances
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_TCP.h>
#include <ifs/DataTypes.h>
#include <BAS/coding.h>

//  base tcp communication client
class TCP_CLient_Base : public I_TCP_Client
{
public:
    bool accept(INT32 socket) override;
    bool select() override;
    void close() override;
    void send(const ComTele& tele) const override;
    NOCOPY(TCP_CLient_Base)
protected:
    inline TCP_CLient_Base() = default;
    virtual void onAccept() const = 0;
    virtual void forward(const ComTele& tele) const = 0;
private:
    INT32 mSocket = -1;
    CHAR mBuffer[sizeof(ComTele)];
};

//  field tcp communication client
class TCP_Client_Fld : public TCP_CLient_Base
{
public:
    inline TCP_Client_Fld() = default;
    INSTANCE_DEC(TCP_Client_Fld)
    NOCOPY(TCP_Client_Fld)
protected:
    void onAccept() const override;
    void forward(const ComTele& tele) const override;
};

//  GUI tcp communication client
class TCP_Client_Gui : public TCP_CLient_Base
{
public:
    inline TCP_Client_Gui() = default;
    INSTANCE_DEC(TCP_Client_Gui)  
    NOCOPY(TCP_Client_Gui) 
protected:
    void onAccept() const override;
    void forward(const ComTele& tele) const override;
};

//  control tcp communication client
class TCP_Client_Ctrl : public TCP_CLient_Base
{
public:
    inline TCP_Client_Ctrl() = default;
    INSTANCE_DEC(TCP_Client_Ctrl)
    NOCOPY(TCP_Client_Ctrl)
protected:
    inline void onAccept() const override {}
    void forward(const ComTele& tele) const override;
};