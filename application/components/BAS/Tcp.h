//  ============================================================
//  implementation TCP base system 
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_Tcp.h>
#include <BAS/coding.h>

class Tcp : public I_Tcp
{
public:
    void setSelectTimeout(UINT32 ms);

    bool init();

    void cleanup();

    INT32 socket() const;

    bool bind(INT32 socket, UINT16 port) const;

    bool listen(INT32 socket) const;

    INT32 select(INT32 socket) const;

    INT32 accept(INT32 socket) const;

    INT32 recv(INT32 socket, CHAR* buffer, size_t size) const;

    INT32 send(INT32 socket, const CHAR* buffer, size_t size) const;

    void close(INT32 socket) const;

    INSTANCE_DEC(Tcp)

    NOCOPY(Tcp)
private:
    Tcp() = default;
    UINT32 mSec = 0;
    UINT32 mMicro = 10000;    
};