/* Converted to C from ASM: MacWinSock.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWinSock.cp */
/* Linux replacement: thin wrappers around POSIX socket APIs */

#include "common_types.h"
#include "imports.h"

#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>

int closesocket(SOCKET s)
{
    return close(s);
}

int ioctlsocket(SOCKET s, long int cmd, u_long *argp)
{
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
    /* Map POSIX errors 1-87 to WinSock range (10001+) */
    if (err >= 1 && err <= 87) {
        return err + 10000;
    }
    return err;
}
