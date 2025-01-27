//  ============================================================
//  implementation TCP base system
//  ============================================================
//  created by Manfred Sorgo

#ifndef TCP_H
#define TCP_H

#include <ifs/I_TCP.h>
#include <BAS/coding.h>

class TCP : public I_TCP
{
public:
    void setTimeout(UINT32 ms);

    bool init();

    void cleanup();

    INT32 socket() const;

    bool bind(INT32 socket, UINT16 port) const;

    bool listen(INT32 socket) const;

    E_Select select(INT32 socket) const;

    INT32 accept(INT32 socket) const;

    INT32 recv(INT32 socket, PTR buffer, size_t size) const;

    INT32 send(INT32 socket, CPTR buffer, size_t size) const;

    void close(INT32& socket) const;

    INSTANCE_DEC(TCP)

    NOCOPY(TCP)
private:
    TCP() = default;
    UINT32 mSec = 0;
    UINT32 mMicro = 10000;
};
#endif // _H
