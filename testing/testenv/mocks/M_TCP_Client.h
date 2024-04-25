//  ============================================================
//  mock for interface I_TCP_Client
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_TCP.h>
#include "M_Base.h"

namespace test
{
    class M_TCP_Client : public I_TCP_Client, private M_Base
    {
    public:

        inline bool accept(INT32 socket)
        {
            return static_cast<bool>(call("accept").PARAM(socket).RETURN_DEF_BOOL(true));
        }
        inline void expectAccept(INT32 socket, bool ret = true) const
        {
            expect("accept").PARAM(socket).AND_RETURN_BOOL(ret);
        }

        inline bool select()
        {
            return static_cast<bool>(call("select").RETURN_DEF_BOOL(true));
        }
        inline void expectSelect(bool ret = true) const
        {
            expect("select").AND_RETURN_BOOL(ret);
        }

        inline void close()
        {
            call("close");
        }
        inline void expectClose() const
        {
            expect("close");
        }

        inline void send(const ComTele& tele) const
        {
            call("send").TPARAM(ComTele, tele);
        }
        inline void expectSend(const ComTele& tele) const
        {
            expect("send").TPARAM(ComTele, tele);
        }

        NOCOPY(M_TCP_Client)
        NODEF(M_TCP_Client)
    protected:
        inline M_TCP_Client(const CONST_C_STRING name) : M_Base(name) {}

    };

    class M_TCP_Client_Fld : public M_TCP_Client
    {
    public:
        inline M_TCP_Client_Fld() : M_TCP_Client("TCP_Client_Fld") {}
        INSTANCE_DEC(M_TCP_Client_Fld)
        NOCOPY(M_TCP_Client_Fld)
    };

    class M_TCP_Client_Gui : public M_TCP_Client
    {   
    public:
        inline M_TCP_Client_Gui() : M_TCP_Client("TCP_Client_Gui") {}
        INSTANCE_DEC(M_TCP_Client_Gui)
        NOCOPY(M_TCP_Client_Gui)
    };

    class M_TCP_Client_Ctrl : public M_TCP_Client
    {
    public:
        inline M_TCP_Client_Ctrl() : M_TCP_Client("TCP_Client_Ctrl") {}
        INSTANCE_DEC(M_TCP_Client_Ctrl)
        NOCOPY(M_TCP_Client_Ctrl)
    };

} // namespace

