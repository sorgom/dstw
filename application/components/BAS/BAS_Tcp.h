//  ============================================================
//  base classes for TCP system
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include <ifs/I_Tcp.h>
#include <BAS/coding.h>

class BAS_Tcp_Listener : public I_Tcp_Listener
{
public:
    bool listen(UINT16 port) override;
    
    bool select() override;

    NOCOPY(BAS_Tcp_Listener)

protected:
    BAS_Tcp_Listener() = default;
    virtual I_Tcp_Client& getClient() = 0;
    INT32 mSocket = -1;
};