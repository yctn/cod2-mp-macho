/* ASM dump from: MacWinSock.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWinSock.cp */

#include "common_types.h"
#include "imports.h"

int closesocket(SOCKET s);
int ioctlsocket(SOCKET s, long int cmd, u_long *argp);
int WSAStartup(int wVersionRequired, LPWSADATA lpWSAData);
int WSAGetLastError(void);

/* line 15 */
__attribute__((naked))
int closesocket(SOCKET s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 15 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 18 */
        "jmp close\n" /* line 17 */
    );
}

/* line 25 */
__attribute__((naked))
int ioctlsocket(SOCKET s, long int cmd, u_long *argp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 28 */
        "jmp ioctl\n" /* line 27 */
    );
}

/* line 34 */
__attribute__((naked))
int WSAStartup(int wVersionRequired, LPWSADATA lpWSAData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* wVersionRequired */
        "movl 0xc(%ebp), %ebx\n" /* lpWSAData */
        "movl $0x190, 8(%esp)\n" /* line 37 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* lpWSAData */
        "calll memset\n"
        "movw %si, (%ebx)\n" /* line 40 | lpWSAData */
        "xorl %eax, %eax\n" /* line 43 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 54 */
__attribute__((naked))
int WSAGetLastError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 54 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "calll ___error\n" /* line 56 */
        "movl (%eax), %eax\n" /* error */
        "leal -1(%eax), %edx\n" /* line 60 */
        "leal 0x2710(%eax), %ecx\n" /* line 62 */
        "cmpl $0x57, %edx\n"
        "cmovbel %ecx, %eax\n"
        /* } scope */
        "leave\n" /* line 66 */
        "retl\n"
    );
}

