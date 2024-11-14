#include <COM/TCP.h>
#include <BAS/coverage.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close
#endif

INSTANCE_DEF(TCP)

void TCP::setTimeout(const UINT32 ms)
{
    mSec = ms / 1000;
    mMicro = (ms % 1000) * 1000;
}

bool TCP::init()
{
#ifdef _WIN32
    WSADATA wsaData;
    return WSAStartup(MAKEWORD(2, 2), &wsaData) == 0;
#else
    return true;
#endif
}

void TCP::cleanup()
{
#ifdef _WIN32
    WSACleanup();
#endif
}

INT32 TCP::socket() const
{
    return ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

bool TCP::bind(const INT32 socket, const UINT16 port) const
{
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY; // INADDR_LOOPBACK;
    addr.sin_port = htons(port);
    return ::bind(socket, (const sockaddr*)&addr, sizeof(addr)) >= 0;
}

bool TCP::listen(const INT32 socket) const
{
    return ::listen(socket, SOMAXCONN) >= 0;
}

E_Select TCP::select(const INT32 socket) const
{
    fd_set readfds;
#ifdef _WIN32
#pragma warning(disable:4389)
#endif
 // interns of fd_set macros must not be coverage instrumented
COVERAGE_PAUSE
    FD_ZERO(&readfds);
    FD_SET(socket, &readfds);
COVERAGE_RESUME
#ifdef _WIN32
#pragma warning(default:4389)
#endif
    timeval timeout;
    timeout.tv_sec = mSec;
    timeout.tv_usec = mMicro;
    E_Select ret = SELECT_NONE;
    if (::select(socket + 1, &readfds, nullptr, nullptr, &timeout) < 0)
    {
        ret = SELECT_ERR;
    }
    else if (FD_ISSET(socket, &readfds))
    {
        ret = SELECT_READY;
    }
    return ret;
}

INT32 TCP::accept(const INT32 socket) const
{
    return ::accept(socket, nullptr, nullptr);
}

INT32 TCP::recv(const INT32 socket, PTR buffer, const size_t size) const
{
    return ::recv(socket, reinterpret_cast<CHAR*>(buffer), size, 0);
}

INT32 TCP::send(const INT32 socket, CPTR buffer, const size_t size) const
{
    return ::send(socket, reinterpret_cast<const CHAR*>(buffer), size, 0);
}

void TCP::close(INT32& socket) const
{
    if (socket >= 0)
    {
        ::closesocket(socket);
        socket = -1;
    }
}
