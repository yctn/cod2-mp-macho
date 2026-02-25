/* Converted to C from ASM: MacWinSock.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWinSock.cp */

#include "common_types.h"
#include "imports.h"

extern int close(int fd);
extern int ioctl(int fd, unsigned long request, ...);
extern int *__error(void);

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
    int error = *__error();
    if ((unsigned int)(error - 1) <= 0x57)
        return error + 0x2710;
    return error;
}
