//  ============================================================
//  TCP listener and connection classes and instances
//  ============================================================
//  created by Manfred Sorgo

#ifndef TCP_COM_H
#define TCP_COM_H

#include <ifs/I_TCP.h>
#include <BAS/coding.h>
#include <ostream>

class TCP_Com_Base
{
protected:
    static std::ostream& comerr();
};

//  ============================================================
//  TCP listeners
//  ============================================================
class Tcp_Listener_Base :
    public I_TCP_Listener,
    private TCP_Com_Base
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
    INSTANCE_DEC(TCP_Listener_Fld)
    NOCOPY(TCP_Listener_Fld)
protected:
    I_TCP_Con& getCon() const override;
private:
    inline TCP_Listener_Fld() = default;
};

class TCP_Listener_Gui : public Tcp_Listener_Base
{
public:
    INSTANCE_DEC(TCP_Listener_Gui)
    NOCOPY(TCP_Listener_Gui)
protected:
    I_TCP_Con& getCon() const override;
private:
    inline TCP_Listener_Gui() = default;
};

class TCP_Listener_Ctrl : public Tcp_Listener_Base
{
public:
    INSTANCE_DEC(TCP_Listener_Ctrl)
    NOCOPY(TCP_Listener_Ctrl)
protected:
    I_TCP_Con& getCon() const override;
private:
    inline TCP_Listener_Ctrl() = default;
};

//  ============================================================
//  TCP connections
//  ============================================================
//  base tcp communication client
class TCP_Con_Base :
    public I_TCP_Con,
    private TCP_Com_Base
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
    INSTANCE_DEC(TCP_Con_Fld)
    NOCOPY(TCP_Con_Fld)
protected:
    void onAccept() const override;
    void forward(const ComTele& tele) const override;
private:
    inline TCP_Con_Fld() = default;
};

//  GUI tcp communication client
class TCP_Con_Gui : public TCP_Con_Base
{
public:
    INSTANCE_DEC(TCP_Con_Gui)
    NOCOPY(TCP_Con_Gui)
protected:
    void onAccept() const override;
    void forward(const ComTele& tele) const override;
private:
    inline TCP_Con_Gui() = default;
};

//  control tcp communication client
class TCP_Con_Ctrl : public TCP_Con_Base
{
public:
    INSTANCE_DEC(TCP_Con_Ctrl)
    NOCOPY(TCP_Con_Ctrl)
protected:
    inline void onAccept() const override {}
    void forward(const ComTele& tele) const override;
private:
    inline TCP_Con_Ctrl() = default;
};
#endif // _H
