//  ============================================================
//  mock for interface I_TCP_Listener
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_TCP_LISTENER_H
#define M_TCP_LISTENER_H

#include <ifs/I_TCP.h>
#include "M_Base.h"

namespace test
{
    class M_TCP_Listener : public I_TCP_Listener, private M_Base
    {
    public:

        inline bool listen(UINT16 port) override
        {
            return static_cast<bool>(call("listen").PARAM(port).RETURN_DEF_BOOL(true));
        }
        inline void expectListen(UINT16 port, bool ret = true) const
        {
            expect("listen").PARAM(port).AND_RETURN_BOOL(ret);
        }

        inline bool select() override
        {
            return static_cast<bool>(call("select").RETURN_DEF_BOOL(true));
        }
        inline void expectSelect(bool ret = true) const
        {
            expect("select").AND_RETURN_BOOL(ret);
        }

        inline void close() override
        {
            call("close");
        }
        inline void expectClose() const
        {
            expect("close");
        }

        NOCOPY(M_TCP_Listener)
        NODEF(M_TCP_Listener)

    protected:
        inline M_TCP_Listener(const CONST_C_STRING name) : M_Base(name) {}
    };

    class M_TCP_Listener_Fld : public M_TCP_Listener
    {
    public:
        INSTANCE_DEC(M_TCP_Listener_Fld)
        NOCOPY(M_TCP_Listener_Fld)
    private:
        M_TCP_Listener_Fld() : M_TCP_Listener("TCP_Listener_Fld") {}
    };

    class M_TCP_Listener_Gui : public M_TCP_Listener
    {
    public:
        INSTANCE_DEC(M_TCP_Listener_Gui)
        NOCOPY(M_TCP_Listener_Gui)
    private:
        M_TCP_Listener_Gui() : M_TCP_Listener("TCP_Listener_Gui") {}
    };

    class M_TCP_Listener_Ctrl : public M_TCP_Listener
    {
    public:
        INSTANCE_DEC(M_TCP_Listener_Ctrl)
        NOCOPY(M_TCP_Listener_Ctrl)
    private:
        M_TCP_Listener_Ctrl() : M_TCP_Listener("TCP_Listener_Ctrl") {}
    };

} // namespace
#endif // _H
