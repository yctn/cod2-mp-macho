/* Converted to C from ASM: MacWinSock.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWinSock.cp */
/* Linux replacement: thin wrappers around POSIX socket APIs */

#include "common_types.h"
#include "imports.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>

int closesocket(SOCKET s)
{
    return close(s);
}

int ioctlsocket(SOCKET s, long int cmd, u_long *argp)
{
    if (cmd == 0x8004667e) {
        int flags = fcntl(s, F_GETFL, 0);

        if (flags == -1) {
            return -1;
        }

        if (argp && *argp) {
            flags |= O_NONBLOCK;
        } else {
            flags &= ~O_NONBLOCK;
        }

        return fcntl(s, F_SETFL, flags);
    }

    return ioctl(s, cmd, argp);
}

int WSAStartup(int wVersionRequired, LPWSADATA lpWSAData)
{
    memset(lpWSAData, 0, 0x190);
    *(short *)lpWSAData = (short)wVersionRequired;
    return 0;
}

int WSAGetLastError(void)
{
    int err = errno;

    switch (err) {
    case EAGAIN:
#if EWOULDBLOCK != EAGAIN
    case EWOULDBLOCK:
#endif
        return 10035;
    case EINPROGRESS:
        return 10036;
    case EMSGSIZE:
        return 10040;
    case EAFNOSUPPORT:
        return 10047;
    case EADDRNOTAVAIL:
        return 10049;
    case ENETDOWN:
        return 10050;
    case ECONNRESET:
        return 10054;
    case ECONNREFUSED:
        return 10061;
    default:
        return err;
    }
}
