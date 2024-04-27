//  ============================================================
//  interface TCP base system
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include "DataTypes.h"

class I_TCP
{
public:
    //  set elect timeout in milli seconds
    virtual void setTimeout(UINT32 ms) = 0;

    //  initialize TCP system
    virtual bool init() = 0;

    //  finalize TCP system
    virtual void cleanup() = 0;

    //  create a TCP socket
    virtual INT32 socket() const = 0;

    //  bind a TCP socket to a port
    virtual bool bind(INT32 socket, UINT16 port) const = 0;

    //  listen to a TCP socket
    virtual bool listen(INT32 socket) const = 0;

    //  read select a socket
    //  -1 on error
    //   0 if no socket is ready
    //   1 if socket is ready
    virtual INT32 select(INT32 socket) const = 0;

    //  accept a connection
    virtual INT32 accept(INT32 socket) const = 0;

    //  receive data
    virtual INT32 recv(INT32 socket, PTR buffer, size_t size) const = 0;

    //  send data
    virtual INT32 send(INT32 socket, CPTR buffer, size_t size) const = 0;

    //  close a socket
    virtual void close(INT32& socket) const = 0;
};

class I_TCP_Listener
{
public:
    //  listen at given port
    virtual bool listen(UINT16 port) = 0;
    //  check for client connects
    virtual bool select() = 0;
    //  close listener
    virtual void close() = 0;
};

class I_TCP_Client
{
public:
    //  accept connection
    virtual bool accept(INT32 socket) = 0;
    //  check for client activity
    virtual bool select() = 0;
    //  send COM telegram
    virtual void send(const ComTele& tele) const = 0;
    //  close client
    virtual void close() = 0;
};