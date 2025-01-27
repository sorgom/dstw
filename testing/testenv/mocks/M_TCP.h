//  ============================================================
//  mock for interface I_TCP
//  ============================================================
//  created by Manfred Sorgo

#ifndef M_TCP_H
#define M_TCP_H

#include <ifs/I_TCP.h>
#include "M_Base.h"
#include <cstring>

namespace test
{
    class M_TCP : public I_TCP, private M_Base
    {
    public:
        INSTANCE_DEC(M_TCP)
        NOCOPY(M_TCP)

        inline void setTimeout(UINT32 ms)
        {
            call("setTimeout").PARAM(ms);
        }
        inline void expectSetTimeout(UINT32 ms) const
        {
            expect("setTimeout").PARAM(ms);
        }

        inline bool init()
        {
            return static_cast<bool>(call("init").RETURN_DEF_BOOL(true));
        }
        inline void expectInit(bool ret = true) const
        {
            expect("init").AND_RETURN_BOOL(ret);
        }

        inline void cleanup()
        {
            call("cleanup");
        }
        inline void expectCleanup() const
        {
            expect("cleanup");
        }

        inline INT32 socket() const
        {
            return call("socket").RETURN_DEF_INT(0);
        }
        inline void expectSocket(INT32 ret = 0) const
        {
            expect("socket").AND_RETURN(ret);
        }

        inline bool bind(INT32 socket, UINT16 port) const
        {
            return static_cast<bool>(call("bind").PARAM(socket).PARAM(port).RETURN_DEF_BOOL(true));
        }
        inline void expectBind(INT32 socket, UINT16 port, bool ret = true) const
        {
            expect("bind").PARAM(socket).PARAM(port).AND_RETURN_BOOL(ret);
        }

        inline bool listen(INT32 socket) const
        {
            return static_cast<bool>(call("listen").PARAM(socket).RETURN_DEF_BOOL(true));
        }
        inline void expectListen(INT32 socket, bool ret = true) const
        {
            expect("listen").PARAM(socket).AND_RETURN_BOOL(ret);
        }

        inline E_Select select(INT32 socket) const
        {
            return static_cast<E_Select>(call("select").PARAM(socket).RETURN_DEF_INT(0));
        }
        inline void expectSelect(INT32 socket, E_Select ret = SELECT_NONE) const
        {
            expect("select").PARAM(socket).AND_RETURN(ret);
        }

        inline INT32 accept(INT32 socket) const
        {
            return call("accept").PARAM(socket).RETURN_DEF_INT(0);
        }
        inline void expectAccept(INT32 socket, INT32 ret = 0) const
        {
            expect("accept").PARAM(socket).AND_RETURN(ret);
        }

        inline INT32 recv(INT32 socket, PTR buffer, size_t size) const
        {
            const INT32 res = call("recv").PARAM(socket).PARAM(size).RETURN_DEF_INT(size);
            if (
                mTele != nullptr and
                size == sizeof(ComTele) and
                static_cast<size_t>(res) == size
            )
            {
                std::memcpy(buffer, mTele, size);
            }
            mTele = nullptr;
            return res;
        }
        inline void expectRecv(INT32 socket, size_t size, INT32 ret = 0) const
        {
            expect("recv").PARAM(socket).PARAM(size).AND_RETURN(ret);
        }
        inline void expectRecv(INT32 socket, const ComTele& tele) const
        {
            const INT32 size = sizeof(ComTele);
            mTele = &tele;
            expect("recv").PARAM(socket).PARAM(size).AND_RETURN(size);
        }

        inline INT32 send(INT32 socket, CPTR buffer, size_t size) const
        {
            return call("send").PARAM(socket).PARAM(size).RETURN_DEF_INT(size);
        }
        inline void expectSend(INT32 socket, size_t size, INT32 ret = 0) const
        {
            expect("send").PARAM(socket).PARAM(size).AND_RETURN(ret);
        }

        inline void close(INT32& socket) const
        {
            call("close").PARAM(socket);
        }
        inline void expectClose(INT32 socket) const
        {
            expect("close").PARAM(socket);
        }
        inline void expectClose() const
        {
            expect("close").IGNORE();
        }
    private:
        using TelePtr = const ComTele*;
        mutable TelePtr mTele = nullptr;
        inline M_TCP() : M_Base("Tcp") {}
    };
} // namespace
#endif // _H
