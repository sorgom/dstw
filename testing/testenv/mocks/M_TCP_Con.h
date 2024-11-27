//  ============================================================
//  mock for interface I_TCP_Con
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_TCP_CON_H
#define M_TCP_CON_H

#include <ifs/I_TCP.h>
#include "M_Base.h"

namespace test
{
    class M_TCP_Con : public I_TCP_Con, private M_Base
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

        NOCOPY(M_TCP_Con)
        NODEF(M_TCP_Con)
    protected:
        inline M_TCP_Con(const CONST_C_STRING name) : M_Base(name) {}

    };

    class M_TCP_Con_Fld : public M_TCP_Con
    {
    public:
        INSTANCE_DEC(M_TCP_Con_Fld)
        NOCOPY(M_TCP_Con_Fld)
    private:
        M_TCP_Con_Fld() : M_TCP_Con("TCP_Con_Fld") {}
    };

    class M_TCP_Con_Gui : public M_TCP_Con
    {
    public:
        INSTANCE_DEC(M_TCP_Con_Gui)
        NOCOPY(M_TCP_Con_Gui)
    private:
        M_TCP_Con_Gui() : M_TCP_Con("TCP_Con_Gui") {}
    };

    class M_TCP_Con_Ctrl : public M_TCP_Con
    {
    public:
        INSTANCE_DEC(M_TCP_Con_Ctrl)
        NOCOPY(M_TCP_Con_Ctrl)
    private:
        M_TCP_Con_Ctrl() : M_TCP_Con("TCP_Con_Ctrl") {}
    };

} // namespace
#endif // _H
