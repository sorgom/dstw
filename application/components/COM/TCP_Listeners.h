//  ============================================================
//  TCP listener classes and instances
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_TCP.h>
#include <BAS/coding.h>

class Tcp_Listener_Base : public I_TCP_Listener
{
public:
    bool listen(UINT16 port) override;
    
    bool select() override;

    void close() override;

    NOCOPY(Tcp_Listener_Base)

protected:
    Tcp_Listener_Base() = default;
    virtual I_TCP_Con& getCon() const = 0;
private:
    INT32 mSocket = -1;
};

class TCP_Listener_Fld : public Tcp_Listener_Base
{
public:
    inline TCP_Listener_Fld() = default;
    INSTANCE_DEC(TCP_Listener_Fld)
    NOCOPY(TCP_Listener_Fld)
protected:
    I_TCP_Con& getCon() const override;
};

class TCP_Listener_Gui : public Tcp_Listener_Base
{
public:
    inline TCP_Listener_Gui() = default;
    INSTANCE_DEC(TCP_Listener_Gui)
    NOCOPY(TCP_Listener_Gui)
protected:
    I_TCP_Con& getCon() const override;
};

class TCP_Listener_Ctrl : public Tcp_Listener_Base
{
public:
    inline TCP_Listener_Ctrl() = default;
    INSTANCE_DEC(TCP_Listener_Ctrl)
    NOCOPY(TCP_Listener_Ctrl)
protected:
    I_TCP_Con& getCon() const override;
};