/* ASM dump from: win_net.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/win32/win_net.cpp */

#include "common_types.h"
#include "imports.h"

static qboolean usingSocks; /* 0xff0d64 */
static qboolean networkingEnabled; /* 0xff0d4c */
static const dvar_t *net_noudp; /* 0xff0d48 */
static const dvar_t *net_noipx; /* 0xff0d44 */
static const dvar_t *net_socksEnabled; /* 0xff0d40 */
static const dvar_t *net_socksServer; /* 0xff0d3c */
static const dvar_t *net_socksPort; /* 0xff0d38 */
static const dvar_t *net_socksUsername; /* 0xff0d34 */
static const dvar_t *net_socksPassword; /* 0xff0d30 */
static sockaddr socksRelayAddr; /* 0xff0d54 */
static SOCKET ip_socket; /* 0xff0b80 */
static int numIP; /* 0xff0dc0 */
static byte localIP[16][4]; /* 0xff0d80 */
static WSADATA winsockdata; /* 0xff0ba0 */
static qboolean winsockInitialized; /* 0xff0b84 */
static SOCKET socks_socket; /* 0xff0d50 */
static SOCKET ipx_socket; /* 0xff1de0 */
static char socksBuf[4096]; /* 0xff0de0 */

qboolean Sys_IsLANAddress(netadr_t adr);
jpeg_alloc Sys_ShowIP(void);
static qboolean NET_GetDvars(void);
jpeg_alloc NET_Sleep(int msec);
qboolean Sys_StringToAdr(const char *s, netadr_t *a);
qboolean Sys_GetPacket(netadr_t *net_from, msg_t *net_message);
Bool Sys_SendPacket(int length, const jpeg_alloc *data, netadr_t to);
jpeg_alloc NET_OpenIP(void);
jpeg_alloc NET_Config(qboolean enableNetworking);
jpeg_alloc NET_Init(void);
jpeg_alloc NET_Restart(void);

/* line 568 */
__attribute__((naked))
qboolean Sys_IsLANAddress(netadr_t adr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 568 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movzbl 0xe(%ebp), %edi\n"
        "movzbl 0xd(%ebp), %eax\n"
        "movb %al, -0x1c(%ebp)\n"
        "movzbl 0xc(%ebp), %ecx\n"
        "movl 8(%ebp), %eax\n" /* adr */
        /* { scope 1 */
        "cmpl $2, %eax\n" /* line 572 */
        "je .Lf1e5bb8_001e5bf5\n"
        "testl %eax, %eax\n" /* line 577 */
        "je .Lf1e5bb8_001e5bf5\n"
        "cmpl $4, %eax\n" /* line 589 */
        "je .Lf1e5bb8_001e5beb\n"
        ".Lf1e5bb8_001e5be1:\n"
        "xorl %eax, %eax\n" /* line 635 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 642 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e5bb8_001e5beb:\n"
        "cmpb $0xa, %cl\n" /* line 598 */
        "je .Lf1e5bb8_001e5bf5\n"
        "cmpb $0x7f, %cl\n" /* line 608 */
        "jne .Lf1e5bb8_001e5c02\n"
        ".Lf1e5bb8_001e5bf5:\n"
        "movl $1, %eax\n" /* line 635 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 642 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e5bb8_001e5c02:\n"
        "movzbl -0x1c(%ebp), %eax\n" /* line 616 */
        "movl $4, 8(%ebp)\n" /* adr */
        "movl 0xc(%ebp), %edx\n"
        "cmpw $0xfea9, %dx\n"
        "je .Lf1e5bb8_001e5bf5\n"
        "cmpb $0xac, %cl\n" /* line 623 */
        "je .Lf1e5bb8_001e5c56\n"
        ".Lf1e5bb8_001e5c1c:\n"
        "cmpw $0xa8c0, %dx\n" /* line 630 */
        "je .Lf1e5bb8_001e5bf5\n"
        "movl numIP, %esi\n" /* line 635 */
        "testl %esi, %esi\n"
        "jle .Lf1e5bb8_001e5be1\n"
        "xorl %edx, %edx\n" /* line 630 */
        "movl $localIP, %eax\n"
        "jmp .Lf1e5bb8_001e5c40\n"
        ".Lf1e5bb8_001e5c36:\n"
        "addl $1, %edx\n" /* line 635 */
        "addl $4, %eax\n"
        "cmpl %esi, %edx\n"
        "je .Lf1e5bb8_001e5be1\n"
        ".Lf1e5bb8_001e5c40:\n"
        "cmpb (%eax), %cl\n" /* line 637 */
        "jne .Lf1e5bb8_001e5c36\n"
        "movzbl -0x1c(%ebp), %ebx\n"
        "cmpb 1(%eax), %bl\n"
        "jne .Lf1e5bb8_001e5c36\n"
        "movl %edi, %ebx\n"
        "cmpb 2(%eax), %bl\n"
        "jne .Lf1e5bb8_001e5c36\n"
        "jmp .Lf1e5bb8_001e5bf5\n"
        ".Lf1e5bb8_001e5c56:\n"
        "andl $0xf0, %eax\n" /* line 623 */
        "cmpl $0x10, %eax\n"
        "jne .Lf1e5bb8_001e5c1c\n"
        "jmp .Lf1e5bb8_001e5bf5\n"
    );
}

/* line 650 */
__attribute__((naked))
jpeg_alloc Sys_ShowIP(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 650 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl numIP, %eax\n" /* line 654 */
        "testl %eax, %eax\n"
        "jg .Lf1e5c62_001e5c7a\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 658 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e5c62_001e5c7a:\n"
        "xorl %esi, %esi\n" /* line 654 | i */
        "movl $0xff0d83, %ebx\n"
        ".Lf1e5c62_001e5c81:\n"
        "movzbl (%ebx), %eax\n" /* line 656 */
        "movl %eax, 0x10(%esp)\n"
        "movzbl -1(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl -2(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl -3(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b88b0, (%esp)\n" /* "IP: %i.%i.%i.%i
" */
        "calll Com_Printf\n"
        "addl $1, %esi\n" /* line 654 | i */
        "addl $4, %ebx\n"
        "cmpl %esi, numIP\n" /* i */
        "jg .Lf1e5c62_001e5c81\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 658 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1216 */
static __attribute__((naked))
qboolean NET_GetDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1216 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl net_noudp, %eax\n" /* line 1222 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5cdc\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lf1e5cc2_001e5e5b\n"
        ".Lf1e5cc2_001e5cdc:\n"
        "xorl %ebx, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5cde:\n"
        "movl $0x1021, 8(%esp)\n" /* line 1224 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b88c4, (%esp)\n" /* "net_noudp" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, net_noudp\n"
        "movl net_noipx, %eax\n" /* line 1226 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5d14\n"
        "cmpb $0, 7(%eax)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5d14:\n"
        "movl $0x1021, 8(%esp)\n" /* line 1228 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b88d0, (%esp)\n" /* "net_noipx" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, net_noipx\n"
        "movl net_socksEnabled, %eax\n" /* line 1230 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5d4a\n"
        "cmpb $0, 7(%eax)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5d4a:\n"
        "movl $0x1021, 8(%esp)\n" /* line 1232 */
        "movl $0, 4(%esp)\n"
        "movl $0x2b88dc, (%esp)\n" /* "net_socksEnabled" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, net_socksEnabled\n"
        "movl net_socksServer, %eax\n" /* line 1234 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5d80\n"
        "cmpb $0, 7(%eax)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5d80:\n"
        "movl $0x1021, 8(%esp)\n" /* line 1236 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b88f0, (%esp)\n" /* "net_socksServer" */
        "calll Dvar_RegisterString\n"
        "movl %eax, net_socksServer\n"
        "movl net_socksPort, %eax\n" /* line 1238 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5db6\n"
        "cmpb $0, 7(%eax)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5db6:\n"
        "movl $0x1021, 0x10(%esp)\n" /* line 1240 */
        "movl $0xffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x438, 4(%esp)\n"
        "movl $0x2b8900, (%esp)\n" /* "net_socksPort" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, net_socksPort\n"
        "movl net_socksUsername, %eax\n" /* line 1242 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5dfc\n"
        "cmpb $0, 7(%eax)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5dfc:\n"
        "movl $0x1021, 8(%esp)\n" /* line 1244 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b8910, (%esp)\n" /* "net_socksUsername" */
        "calll Dvar_RegisterString\n"
        "movl %eax, net_socksUsername\n"
        "movl net_socksPassword, %eax\n" /* line 1246 */
        "testl %eax, %eax\n"
        "je .Lf1e5cc2_001e5e32\n"
        "cmpb $0, 7(%eax)\n"
        "movl $1, %eax\n"
        "cmovnel %eax, %ebx\n" /* modified */
        ".Lf1e5cc2_001e5e32:\n"
        "movl $0x1021, 8(%esp)\n" /* line 1248 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2b8924, (%esp)\n" /* "net_socksPassword" */
        "calll Dvar_RegisterString\n"
        "movl %eax, net_socksPassword\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1251 | modified */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e5cc2_001e5e5b:\n"
        "movl $1, %ebx\n" /* line 1222 | modified */
        "jmp .Lf1e5cc2_001e5cde\n"
    );
}

/* line 1625 */
__attribute__((naked))
jpeg_alloc NET_Sleep(int msec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1625 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %edi\n" /* msec */
        /* { scope 1 */
        "movl ip_socket, %edx\n" /* line 1632 */
        "testl %edx, %edx\n"
        "je .Lf1e5e66_001e5f18\n"
        "leal -0xa0(%ebp), %esi\n" /* line 1635 | fdset */
        "movl $0x80, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memset\n"
        "movl ip_socket, %ebx\n" /* line 1638 */
        "movl %ebx, %edx\n"
        "shrl $5, %edx\n"
        "movl %ebx, %ecx\n"
        "andl $0x1f, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "orl %eax, -0xa0(%ebp, %edx, 4)\n"
        "movl $0x10624dd3, %edx\n" /* line 1639 */
        "movl %edi, %eax\n" /* msec */
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %edi, %eax\n" /* msec */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* timeout */
        "leal (%edx, %edx, 4), %edx\n" /* line 1640 */
        "leal (%edx, %edx, 4), %edx\n"
        "leal (%edx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "subl %edx, %edi\n" /* msec */
        "leal (%edi, %edi, 4), %eax\n" /* msec */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 1641 | timeout */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "addl $1, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll select\n"
        /* } scope */
        ".Lf1e5e66_001e5f18:\n"
        "addl $0xbc, %esp\n" /* line 1645 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 364 */
__attribute__((naked))
qboolean Sys_StringToAdr(const char *s, netadr_t *a)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 364 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        "movl 0xc(%ebp), %esi\n" /* a */
        /* { scope 1 */
        /* { scope 2 */
        "leal -0x28(%ebp), %edi\n" /* line 251 | sadr */
        "movl $0, -0x28(%ebp)\n" /* sadr */
        "movl $0, -0x24(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n"
        "movb $2, -0x27(%ebp)\n" /* line 274 */
        "movw $0, -0x26(%ebp)\n" /* line 275 */
        "movsbl (%ebx), %eax\n" /* line 277 */
        "movl %eax, (%esp)\n"
        "calll I_isdigit\n"
        "testb %al, %al\n"
        "je .Lf1e5f24_001e5f89\n"
        "movl %ebx, (%esp)\n" /* line 279 */
        "calll inet_addr\n"
        "movl %eax, -0x24(%ebp)\n"
        /* } scope */
        "cmpb $2, -0x27(%ebp)\n" /* line 338 */
        "je .Lf1e5f24_001e5fa5\n"
        ".Lf1e5f24_001e5f7c:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1e5f24_001e5f81:\n"
        "addl $0x2c, %esp\n" /* line 375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e5f24_001e5f89:\n"
        "movl %ebx, (%esp)\n" /* line 283 */
        "calll gethostbyname\n"
        "testl %eax, %eax\n"
        "je .Lf1e5f24_001e5f81\n"
        "movl 0x10(%eax), %eax\n" /* line 287 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        /* } scope */
        "cmpb $2, -0x27(%ebp)\n" /* line 338 */
        "jne .Lf1e5f24_001e5f7c\n"
        ".Lf1e5f24_001e5fa5:\n"
        "movl $4, (%esi)\n" /* line 340 */
        "movl 4(%edi), %eax\n" /* line 341 */
        "movl %eax, 4(%esi)\n"
        "movzwl 2(%edi), %eax\n" /* line 342 */
        "movw %ax, 8(%esi)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 389 */
__attribute__((naked))
qboolean Sys_GetPacket(netadr_t *net_from, msg_t *net_message)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 389 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "xorl %ebx, %ebx\n"
        /* { scope 1 */
        ".Lf1e5fc6_001e5fd1:\n"
        "movl ip_socket, %esi\n" /* line 402 | net_socket */
        "testl %esi, %esi\n" /* line 409 | net_socket */
        "jne .Lf1e5fc6_001e5ffb\n"
        ".Lf1e5fc6_001e5fdb:\n"
        "addl $1, %ebx\n" /* line 398 | protocol */
        "cmpl $1, %ebx\n" /* protocol */
        "jle .Lf1e5fc6_001e5fed\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1e5fc6_001e5fe5:\n"
        "addl $0x6c, %esp\n" /* line 465 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e5fc6_001e5fed:\n"
        "testl %ebx, %ebx\n" /* line 400 | protocol */
        "je .Lf1e5fc6_001e5fd1\n"
        "movl ipx_socket, %esi\n" /* line 406 | net_socket */
        "testl %esi, %esi\n" /* line 409 | net_socket */
        "je .Lf1e5fc6_001e5fdb\n"
        ".Lf1e5fc6_001e5ffb:\n"
        "movl $0x10, -0x1c(%ebp)\n" /* line 414 | fromlen */
        "leal -0x1c(%ebp), %eax\n" /* line 416 | fromlen */
        "movl %eax, 0x14(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* from */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* net_message */
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* net_socket */
        "calll recvfrom\n"
        "movl %eax, -0x4c(%ebp)\n"
        "addl $1, %eax\n" /* line 417 */
        "je .Lf1e5fc6_001e6195\n"
        "cmpl ip_socket, %esi\n" /* line 429 | net_socket */
        "je .Lf1e5fc6_001e6166\n"
        ".Lf1e5fc6_001e6049:\n"
        "movl usingSocks, %ecx\n" /* line 434 */
        "testl %ecx, %ecx\n"
        "jne .Lf1e5fc6_001e60af\n"
        ".Lf1e5fc6_001e6053:\n"
        "cmpb $2, -0x37(%ebp)\n" /* line 338 */
        "je .Lf1e5fc6_001e6179\n"
        ".Lf1e5fc6_001e605d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 451 | net_message */
        "movl $0, 0x10(%eax)\n"
        ".Lf1e5fc6_001e6067:\n"
        "movl -0x4c(%ebp), %esi\n" /* line 454 | net_socket */
        "movl 0xc(%ebp), %edx\n" /* net_message */
        "cmpl 8(%edx), %esi\n" /* net_socket */
        "jne .Lf1e5fc6_001e61d4\n"
        "movl 8(%ebp), %edi\n" /* line 456 | net_from */
        "movl (%edi), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movl 4(%edi), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b894c, (%esp)\n" /* "Oversize packet from %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e5fc6_001e5fdb\n"
        ".Lf1e5fc6_001e60af:\n"
        "cmpl ip_socket, %esi\n" /* line 434 | net_socket */
        "jne .Lf1e5fc6_001e6053\n"
        "movl $socksRelayAddr, -0x3c(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* fromlen */
        "cld\n"
        "cmpl %ecx, %ecx\n"
        "leal -0x38(%ebp), %esi\n" /* from, net_socket */
        "movl $socksRelayAddr, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* net_socket */
        "movl $0, %edx\n"
        "je .Lf1e5fc6_001e60df\n"
        "movzbl -1(%esi), %edx\n" /* net_socket */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1e5fc6_001e60df:\n"
        "testl %edx, %edx\n"
        "jne .Lf1e5fc6_001e6053\n"
        "cmpl $9, -0x4c(%ebp)\n" /* line 436 */
        "jle .Lf1e5fc6_001e5fdb\n"
        "movl 0xc(%ebp), %edx\n" /* net_message */
        "movl 4(%edx), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1e5fc6_001e5fdb\n"
        "cmpb $0, 1(%eax)\n"
        "jne .Lf1e5fc6_001e5fdb\n"
        "cmpb $0, 2(%eax)\n"
        "jne .Lf1e5fc6_001e5fdb\n"
        "cmpb $1, 3(%eax)\n"
        "jne .Lf1e5fc6_001e5fdb\n"
        "movl 8(%ebp), %esi\n" /* line 440 | net_from, net_socket */
        "movl $4, (%esi)\n" /* net_socket */
        "movl 4(%edx), %eax\n" /* line 441 */
        "movzbl 4(%eax), %eax\n"
        "movb %al, 4(%esi)\n" /* net_socket */
        "movl 4(%edx), %eax\n" /* line 442 */
        "movzbl 5(%eax), %eax\n"
        "movb %al, 5(%esi)\n" /* net_socket */
        "movl 4(%edx), %eax\n" /* line 443 */
        "movzbl 6(%eax), %eax\n"
        "movb %al, 6(%esi)\n" /* net_socket */
        "movl 4(%edx), %eax\n" /* line 444 */
        "movzbl 7(%eax), %eax\n"
        "movb %al, 7(%esi)\n" /* net_socket */
        "movl 4(%edx), %eax\n" /* line 445 */
        "movzwl 8(%eax), %eax\n"
        "movw %ax, 8(%esi)\n" /* net_socket */
        "movl $0xa, 0x10(%edx)\n" /* line 446 */
        "jmp .Lf1e5fc6_001e6067\n"
        ".Lf1e5fc6_001e6166:\n"
        "movl $0, -0x30(%ebp)\n" /* line 431 */
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf1e5fc6_001e6049\n"
        ".Lf1e5fc6_001e6179:\n"
        "movl 8(%ebp), %edi\n" /* line 340 | net_from */
        "movl $4, (%edi)\n"
        "movl -0x34(%ebp), %eax\n" /* line 341 */
        "movl %eax, 4(%edi)\n"
        "movzwl -0x36(%ebp), %eax\n" /* line 342 */
        "movw %ax, 8(%edi)\n"
        "jmp .Lf1e5fc6_001e605d\n"
        ".Lf1e5fc6_001e6195:\n"
        "calll WSAGetLastError\n" /* line 419 */
        "cmpl $0x2733, %eax\n" /* line 421 */
        "je .Lf1e5fc6_001e5fdb\n"
        "cmpl $0x2746, %eax\n"
        "je .Lf1e5fc6_001e5fdb\n"
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 425 */
        "movl $0x2b8938, (%esp)\n" /* "NET_GetPacket: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e5fc6_001e5fdb\n"
        ".Lf1e5fc6_001e61d4:\n"
        "movl 0xc(%ebp), %eax\n" /* line 460 | net_message */
        "movl %esi, 0xc(%eax)\n" /* net_socket */
        "movl $1, %eax\n"
        "jmp .Lf1e5fc6_001e5fe5\n"
    );
}

/* line 477 */
__attribute__((naked))
Bool Sys_SendPacket(int length, const jpeg_alloc *data, netadr_t to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 477 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %edx\n" /* line 483 | to */
        "cmpl $3, %edx\n"
        "je .Lf1e61e4_001e6217\n"
        "cmpl $4, %edx\n" /* line 487 */
        "je .Lf1e61e4_001e6217\n"
        "movl $0x2b8968, 4(%esp)\n" /* line 503 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x34, %esp\n" /* line 556 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e61e4_001e6217:\n"
        "movl ip_socket, %ebx\n" /* line 489 | net_socket */
        "testl %ebx, %ebx\n" /* line 507 | net_socket */
        "jne .Lf1e61e4_001e622c\n"
        /* { scope 2 */
        ".Lf1e61e4_001e6221:\n"
        "movl $1, %eax\n" /* line 552 */
        /* } scope */
        /* } scope */
        ".Lf1e61e4_001e6226:\n"
        "addl $0x34, %esp\n" /* line 556 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e61e4_001e622c:\n"
        "movl $0, -0x18(%ebp)\n" /* line 302 | addr */
        "movl $0, -0x14(%ebp)\n"
        "movl $0, -0x10(%ebp)\n"
        "movl $0, -0xc(%ebp)\n"
        "cmpl $3, %edx\n" /* line 304 */
        "je .Lf1e61e4_001e62f1\n"
        "cmpl $4, %edx\n" /* line 310 */
        "je .Lf1e61e4_001e62db\n"
        ".Lf1e61e4_001e625a:\n"
        "movl usingSocks, %eax\n" /* line 515 */
        "testl %eax, %eax\n"
        "je .Lf1e61e4_001e626c\n"
        "cmpl $4, %edx\n"
        "je .Lf1e61e4_001e6313\n"
        ".Lf1e61e4_001e626c:\n"
        "movl $0x10, 0x14(%esp)\n" /* line 528 */
        "leal -0x18(%ebp), %eax\n" /* addr */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* length */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* net_socket */
        "calll sendto\n"
        ".Lf1e61e4_001e6299:\n"
        "addl $1, %eax\n" /* line 530 */
        "jne .Lf1e61e4_001e6221\n"
        /* { scope 2 */
        "calll WSAGetLastError\n" /* line 532 */
        "cmpl $0x2733, %eax\n" /* line 535 */
        "je .Lf1e61e4_001e6221\n"
        "cmpl $0x2741, %eax\n" /* line 544 */
        "je .Lf1e61e4_001e6308\n"
        ".Lf1e61e4_001e62b5:\n"
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 550 */
        "movl $0x2b898c, (%esp)\n" /* "Sys_SendPacket: %s
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e61e4_001e6226\n"
        /* } scope */
        ".Lf1e61e4_001e62db:\n"
        "movb $2, -0x17(%ebp)\n" /* line 312 */
        "movl 0x14(%ebp), %eax\n" /* line 313 */
        "movl %eax, -0x14(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 314 */
        "movw %ax, -0x16(%ebp)\n"
        "jmp .Lf1e61e4_001e625a\n"
        ".Lf1e61e4_001e62f1:\n"
        "movb $2, -0x17(%ebp)\n" /* line 306 */
        "movl 0x18(%ebp), %eax\n" /* line 307 */
        "movw %ax, -0x16(%ebp)\n"
        "movl $0xffffffff, -0x14(%ebp)\n" /* line 308 */
        "jmp .Lf1e61e4_001e625a\n"
        /* { scope 2 */
        ".Lf1e61e4_001e6308:\n"
        "cmpl $3, 0x10(%ebp)\n" /* line 544 | to */
        "jne .Lf1e61e4_001e62b5\n"
        "jmp .Lf1e61e4_001e6221\n"
        /* } scope */
        ".Lf1e61e4_001e6313:\n"
        "movb $0, socksBuf\n" /* line 517 */
        "movb $0, 0xff0de1\n" /* line 518 */
        "movb $0, 0xff0de2\n" /* line 519 */
        "movb $1, 0xff0de3\n" /* line 520 */
        "movl -0x14(%ebp), %eax\n" /* line 521 */
        "movl %eax, 0xff0de4\n"
        "movzwl -0x16(%ebp), %eax\n" /* line 522 */
        "movw %ax, 0xff0de8\n"
        "movl 8(%ebp), %eax\n" /* line 523 | length */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* data */
        "movl %eax, 4(%esp)\n"
        "movl $0xff0dea, (%esp)\n"
        "calll memcpy\n"
        "movl $0x10, 0x14(%esp)\n" /* line 524 */
        "movl $socksRelayAddr, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 8(%ebp), %eax\n" /* length */
        "addl $0xa, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $socksBuf, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* net_socket */
        "calll sendto\n"
        "jmp .Lf1e61e4_001e6299\n"
    );
}

/* line 1104 */
__attribute__((naked))
jpeg_alloc NET_OpenIP(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1104 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2bc, %esp\n"
        /* { scope 1: port */
        "movl $0x1020, 8(%esp)\n" /* line 1110 */
        "movl $0x2a8ab8, 4(%esp)\n" /* "localhost" */
        "movl $0x2b89a0, (%esp)\n" /* "net_ip" */
        "calll Dvar_RegisterString\n"
        "movl %eax, -0x290(%ebp)\n" /* ip */
        "movl $0x1020, 0x10(%esp)\n" /* line 1111 */
        "movl $0xffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x7120, 4(%esp)\n"
        "movl $0x2b89a8, (%esp)\n" /* "net_port" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, -0x28c(%ebp)\n" /* port */
        "movl $0, -0x288(%ebp)\n" /* i */
        "jmp .Lf1e6392_001e64cd\n"
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        ".Lf1e6392_001e6401:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 697 | _true */
        "movl %eax, 8(%esp)\n"
        "movl $0x8004667e, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newsocket */
        "calll ioctlsocket\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e67cb\n"
        "leal -0x20(%ebp), %eax\n" /* line 704 | i */
        "movl %ebx, -0x294(%ebp)\n" /* newsocket */
        "movl $4, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x20, 8(%esp)\n"
        "movl $0xffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newsocket */
        "calll setsockopt\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e68c3\n"
        "testl %edi, %edi\n" /* line 710 */
        "je .Lf1e6392_001e6464\n"
        "cmpb $0, (%edi)\n"
        "jne .Lf1e6392_001e6840\n"
        ".Lf1e6392_001e6464:\n"
        "movl $0, -0x2c(%ebp)\n" /* line 712 */
        ".Lf1e6392_001e646b:\n"
        "cmpl $-1, %esi\n" /* line 719 */
        "jne .Lf1e6392_001e6765\n"
        "movw $0, -0x2e(%ebp)\n" /* line 721 */
        "movb $2, -0x2f(%ebp)\n" /* line 728 */
        "movl $0x10, 8(%esp)\n" /* line 730 */
        "leal -0x30(%ebp), %eax\n" /* address */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newsocket */
        "calll bind\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e6793\n"
        ".Lf1e6392_001e649e:\n"
        "movl %ebx, %eax\n" /* newsocket */
        /* } scope */
        /* } scope */
        ".Lf1e6392_001e64a0:\n"
        "movl %eax, ip_socket\n" /* line 1118 */
        "movl -0x294(%ebp), %eax\n" /* line 1119 */
        "testl %eax, %eax\n"
        "jne .Lf1e6392_001e6560\n"
        ".Lf1e6392_001e64b3:\n"
        "addl $1, -0x288(%ebp)\n" /* line 1116 | i */
        "cmpl $0xa, -0x288(%ebp)\n" /* i */
        "je .Lf1e6392_001e68ac\n"
        "movl -0x28c(%ebp), %eax\n" /* port */
        ".Lf1e6392_001e64cd:\n"
        "movl -0x288(%ebp), %esi\n" /* line 1118 | i, port */
        "addl 8(%eax), %esi\n" /* port */
        "movl -0x290(%ebp), %edx\n" /* ip */
        "movl 8(%edx), %edi\n" /* s */
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        "movl $1, -0x1c(%ebp)\n" /* line 672 | _true */
        "movl $1, -0x20(%ebp)\n" /* line 673 | i */
        "testl %edi, %edi\n" /* line 676 */
        "je .Lf1e6392_001e67fb\n"
        "movl %esi, 8(%esp)\n" /* line 678 */
        "movl %edi, 4(%esp)\n"
        "movl $0x2b89b4, (%esp)\n" /* "Opening IP socket: %s:%i
" */
        "calll Com_Printf\n"
        ".Lf1e6392_001e6509:\n"
        "movl $0x11, 8(%esp)\n" /* line 685 */
        "movl $2, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll socket\n"
        "movl %eax, %ebx\n" /* newsocket */
        "cmpl $-1, %eax\n"
        "jne .Lf1e6392_001e6401\n"
        "calll WSAGetLastError\n" /* line 687 */
        "cmpl $0x273f, %eax\n" /* line 688 */
        "jne .Lf1e6392_001e6810\n"
        "movl $0, -0x294(%ebp)\n"
        "xorw %ax, %ax\n"
        /* } scope */
        /* } scope */
        "movl %eax, ip_socket\n" /* line 1118 */
        "movl -0x294(%ebp), %eax\n" /* line 1119 */
        "testl %eax, %eax\n"
        "je .Lf1e6392_001e64b3\n"
        ".Lf1e6392_001e6560:\n"
        "movl -0x288(%ebp), %eax\n" /* line 1121 | i */
        "movl -0x28c(%ebp), %edx\n" /* port */
        "addl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl net_socksEnabled, %eax\n" /* line 1122 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e6392_001e6935\n"
        ".Lf1e6392_001e658a:\n"
        "movl $0, numIP\n" /* line 973 */
        "movl $0x200, -0x30(%ebp)\n" /* line 975 | address */
        "leal -0x270(%ebp), %edi\n" /* line 976 | s */
        "movl %edi, -0x2c(%ebp)\n" /* s */
        "movl $0, 8(%esp)\n" /* line 980 */
        "movl $2, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll socket\n"
        "movl %eax, -0x280(%ebp)\n"
        "testl %eax, %eax\n"
        "js .Lf1e6392_001e69b9\n"
        "leal -0x30(%ebp), %eax\n" /* line 985 | address */
        "movl %eax, 8(%esp)\n"
        "movl $0xc0086924, 4(%esp)\n"
        "movl -0x280(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ioctl\n"
        "testl %eax, %eax\n"
        "jne .Lf1e6392_001e6903\n"
        "movl -0x2c(%ebp), %esi\n" /* line 991 */
        "movl %esi, %edi\n" /* s */
        "movl -0x30(%ebp), %edx\n" /* line 992 | address */
        "movl %edx, -0x29c(%ebp)\n"
        "leal (%esi, %edx), %eax\n"
        "cmpl %eax, %esi\n"
        "jae .Lf1e6392_001e691c\n"
        "jmp .Lf1e6392_001e6632\n"
        ".Lf1e6392_001e660e:\n"
        "movl -0x29c(%ebp), %ecx\n"
        ".Lf1e6392_001e6614:\n"
        "movzbl 0x10(%esi), %eax\n" /* line 1040 */
        "subl $0x10, %eax\n"
        "movl $0, %edx\n"
        "cmovsl %edx, %eax\n"
        "leal 0x20(%eax, %esi), %esi\n"
        "leal (%edi, %ecx), %eax\n" /* line 992 | s */
        "cmpl %eax, %esi\n"
        "jae .Lf1e6392_001e691c\n"
        ".Lf1e6392_001e6632:\n"
        "cmpb $0x12, 0x11(%esi)\n" /* line 998 */
        "jne .Lf1e6392_001e660e\n"
        "movl %edi, %ebx\n" /* line 1000 | s, newsocket */
        "movl -0x29c(%ebp), %ecx\n" /* line 1001 */
        "leal (%edi, %ecx), %eax\n" /* s */
        "cmpl %eax, %edi\n" /* s */
        "jae .Lf1e6392_001e6614\n"
        "jmp .Lf1e6392_001e6668\n"
        ".Lf1e6392_001e6649:\n"
        "movzbl 0x10(%ebx), %eax\n" /* line 1037 | newsocket */
        "subl $0x10, %eax\n"
        "movl $0, %edx\n"
        "cmovsl %edx, %eax\n"
        "leal 0x20(%eax, %ebx), %ebx\n" /* newsocket */
        "movl -0x29c(%ebp), %eax\n" /* line 1001 */
        "addl %edi, %eax\n" /* s */
        "cmpl %eax, %ebx\n" /* newsocket */
        "jae .Lf1e6392_001e660e\n"
        ".Lf1e6392_001e6668:\n"
        "cmpb $2, 0x11(%ebx)\n" /* line 1002 | newsocket */
        "jne .Lf1e6392_001e6649\n"
        "movl $0x10, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newsocket */
        "calll strncmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1e6392_001e6649\n"
        "movl %esi, %eax\n"
        "movl $0x10, %edx\n"
        ".Lf1e6392_001e668d:\n"
        "cmpb $0, (%eax)\n" /* line 1006 */
        "je .Lf1e6392_001e669a\n"
        "addl $1, %eax\n" /* line 1007 */
        "subl $1, %edx\n" /* line 1005 */
        "jne .Lf1e6392_001e668d\n"
        ".Lf1e6392_001e669a:\n"
        "cmpb $0x18, 0x14(%esi)\n" /* line 1011 */
        "je .Lf1e6392_001e6649\n"
        "movl $0x10, 8(%esp)\n" /* line 1013 */
        "movl %ebx, 4(%esp)\n" /* newsocket */
        "leal -0x70(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "leal -0x70(%ebp), %edx\n" /* line 1014 | buf */
        "movl %edx, 8(%esp)\n"
        "movl $0xc020690d, 4(%esp)\n"
        "movl -0x280(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll ioctl\n"
        "testl %eax, %eax\n"
        "js .Lf1e6392_001e6b02\n"
        "movl -0x5c(%ebp), %eax\n" /* line 56 */
        "bswapl %eax\n"
        "movl numIP, %ecx\n" /* line 1023 */
        "movl %eax, %edx\n"
        "sarl $0x18, %edx\n"
        "movb %dl, localIP(, %ecx, 4)\n"
        "movl %eax, %edx\n" /* line 1024 */
        "sarl $0x10, %edx\n"
        "movb %dl, 0xff0d81(, %ecx, 4)\n"
        "movl %eax, %edx\n" /* line 1025 */
        "sarl $8, %edx\n"
        "movb %dl, 0xff0d82(, %ecx, 4)\n"
        "movb %al, 0xff0d83(, %ecx, 4)\n" /* line 1026 */
        "movl %ebx, 0x14(%esp)\n" /* line 1027 | newsocket */
        "movzbl %al, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl 0xff0d82(, %ecx, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl 0xff0d81(, %ecx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl localIP(, %ecx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8d58, (%esp)\n" /* "IP: %i.%i.%i.%i (%s)
" */
        "calll Com_Printf\n"
        "addl $1, numIP\n" /* line 1028 */
        "movl -0x2c(%ebp), %edi\n" /* s */
        "movl -0x30(%ebp), %edx\n" /* address */
        "movl %edx, -0x29c(%ebp)\n"
        "jmp .Lf1e6392_001e6649\n"
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        ".Lf1e6392_001e6765:\n"
        "movl %esi, %eax\n" /* line 46 */
        "rolw $8, %ax\n"
        "movw %ax, -0x2e(%ebp)\n" /* line 725 */
        "movb $2, -0x2f(%ebp)\n" /* line 728 */
        "movl $0x10, 8(%esp)\n" /* line 730 */
        "leal -0x30(%ebp), %eax\n" /* address */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* newsocket */
        "calll bind\n"
        "addl $1, %eax\n"
        "jne .Lf1e6392_001e649e\n"
        ".Lf1e6392_001e6793:\n"
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 732 */
        "movl $0x2b8a80, (%esp)\n" /* "WARNING: UDP_OpenSocket: bind: %s
" */
        "calll Com_Printf\n"
        "movl %ebx, (%esp)\n" /* line 733 | newsocket */
        "calll closesocket\n"
        "movl $0, -0x294(%ebp)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e6392_001e64a0\n"
        ".Lf1e6392_001e67cb:\n"
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 699 */
        "movl $0x2b8a1c, (%esp)\n" /* "WARNING: UDP_OpenSocket: ioctl FIONBIO: %s
" */
        "calll Com_Printf\n"
        "movl $0, -0x294(%ebp)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e6392_001e64a0\n"
        ".Lf1e6392_001e67fb:\n"
        "movl %esi, 4(%esp)\n" /* line 682 */
        "movl $0x2b89d0, (%esp)\n" /* "Opening IP socket: localhost:%i
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e6509\n"
        ".Lf1e6392_001e6810:\n"
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 690 */
        "movl $0x2b89f4, (%esp)\n" /* "WARNING: UDP_OpenSocket: socket: %s
" */
        "calll Com_Printf\n"
        "movl $0, -0x294(%ebp)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e6392_001e64a0\n"
        ".Lf1e6392_001e6840:\n"
        "movl $0x2a8ab8, 4(%esp)\n" /* line 710 */
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1e6392_001e6464\n"
        /* { scope 4 */
        /* { scope 5 */
        "movl $0, -0x30(%ebp)\n" /* line 251 | address */
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl $0, -0x24(%ebp)\n"
        "movb $2, -0x2f(%ebp)\n" /* line 274 */
        "movw $0, -0x2e(%ebp)\n" /* line 275 */
        "movsbl (%edi), %eax\n" /* line 277 */
        "movl %eax, (%esp)\n"
        "calll I_isdigit\n"
        "testb %al, %al\n"
        "jne .Lf1e6392_001e68f3\n"
        "movl %edi, (%esp)\n" /* line 283 */
        "calll gethostbyname\n"
        "testl %eax, %eax\n"
        "je .Lf1e6392_001e646b\n"
        "movl 0x10(%eax), %eax\n" /* line 287 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1e6392_001e646b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e6392_001e68ac:\n"
        "movl $0x2b8d70, (%esp)\n" /* line 1129 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1e6392_001e68b8:\n"
        "addl $0x2bc, %esp\n" /* line 1130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: port */
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        ".Lf1e6392_001e68c3:\n"
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 706 */
        "movl $0x2b8a48, (%esp)\n" /* "WARNING: UDP_OpenSocket: setsockopt SO_BROADCAST: %s
" */
        "calll Com_Printf\n"
        "movl $0, -0x294(%ebp)\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e6392_001e64a0\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1e6392_001e68f3:\n"
        "movl %edi, (%esp)\n" /* line 279 */
        "calll inet_addr\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1e6392_001e646b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e6392_001e6903:\n"
        "calll ___error\n" /* line 986 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8cb8, (%esp)\n" /* "NET_GetLocalAddress: Unable to get list of network interface" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e68b8\n"
        ".Lf1e6392_001e691c:\n"
        "movl -0x280(%ebp), %eax\n" /* line 1043 */
        "movl %eax, (%esp)\n"
        "calll close\n"
        /* } scope */
        "addl $0x2bc, %esp\n" /* line 1130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: port */
        ".Lf1e6392_001e6935:\n"
        "movl -0x288(%ebp), %eax\n" /* line 1123 | i */
        "movl -0x28c(%ebp), %ecx\n" /* port */
        "addl 8(%ecx), %eax\n"
        "movl %eax, -0x284(%ebp)\n" /* port */
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        "movl $0, usingSocks\n" /* line 757 */
        "movl $0x2b8aa4, (%esp)\n" /* line 759 */
        "calll Com_Printf\n"
        "movl $6, 8(%esp)\n" /* line 761 */
        "movl $1, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll socket\n"
        "movl %eax, socks_socket\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e6acf\n"
        "movl net_socksServer, %eax\n" /* line 768 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll gethostbyname\n"
        "testl %eax, %eax\n" /* line 769 */
        "je .Lf1e6392_001e6b3c\n"
        "cmpl $2, 8(%eax)\n" /* line 775 */
        "je .Lf1e6392_001e69d5\n"
        "movl $0x2b8b1c, (%esp)\n" /* line 777 */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        /* } scope */
        /* } scope */
        ".Lf1e6392_001e69b9:\n"
        "calll ___error\n" /* line 981 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8c74, (%esp)\n" /* "NET_GetLocalAddress: Unable to create temporary socket, errn" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e68b8\n"
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        ".Lf1e6392_001e69d5:\n"
        "movb $2, -0x2f(%ebp)\n" /* line 780 */
        "movl 0x10(%eax), %eax\n" /* line 781 */
        "movl (%eax), %eax\n"
        "movl (%eax), %edi\n" /* s */
        "movl %edi, -0x2c(%ebp)\n" /* s */
        "movl net_socksPort, %eax\n"
        "movzwl 8(%eax), %eax\n"
        /* { scope 4 */
        "rolw $8, %ax\n" /* line 46 */
        /* } scope */
        "movw %ax, -0x2e(%ebp)\n" /* line 782 | data */
        "leal -0x30(%ebp), %eax\n" /* line 784 | address */
        "movl $0x10, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll connect\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e6b8e\n"
        "movl net_socksUsername, %eax\n" /* line 792 */
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1e6392_001e6af8\n"
        "movl net_socksPassword, %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1e6392_001e6af8\n"
        "xorl %eax, %eax\n"
        ".Lf1e6392_001e6a3d:\n"
        "movb $5, -0x70(%ebp)\n" /* line 801 | buf */
        "testl %eax, %eax\n" /* line 803 */
        "je .Lf1e6392_001e6b2e\n"
        "movb $2, -0x6f(%ebp)\n" /* line 805 */
        "movl $4, %edx\n"
        ".Lf1e6392_001e6a52:\n"
        "negb %al\n" /* line 816 */
        "andb $2, %al\n"
        "movb %al, -0x6e(%ebp)\n"
        "movl $0, 0xc(%esp)\n" /* line 818 */
        "movl %edx, 8(%esp)\n"
        "leal -0x70(%ebp), %edx\n" /* buf */
        "movl %edx, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll send\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e6b65\n"
        "movl $0, 0xc(%esp)\n" /* line 826 */
        "movl $0x40, 8(%esp)\n"
        "leal -0x70(%ebp), %ecx\n" /* buf */
        "movl %ecx, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll recv\n"
        "cmpl $-1, %eax\n" /* line 827 */
        "je .Lf1e6392_001e6bb7\n"
        "cmpl $2, %eax\n" /* line 833 */
        "jne .Lf1e6392_001e6abe\n"
        "cmpb $5, -0x70(%ebp)\n" /* buf */
        "je .Lf1e6392_001e6be0\n"
        ".Lf1e6392_001e6abe:\n"
        "movl $0x2b8bb8, (%esp)\n" /* line 926 */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6acf:\n"
        "calll WSAGetLastError\n" /* line 763 */
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 764 */
        "movl $0x2b8acc, (%esp)\n" /* "WARNING: NET_OpenSocks: socket: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6af8:\n"
        "movl $1, %eax\n" /* line 792 */
        "jmp .Lf1e6392_001e6a3d\n"
        /* } scope */
        /* } scope */
        ".Lf1e6392_001e6b02:\n"
        "calll ___error\n" /* line 1015 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* newsocket */
        "movl $0x2b8d04, (%esp)\n" /* "NET_GetLocalAddress: Unable to get local address for interfa" */
        "calll Com_Printf\n"
        "movl -0x2c(%ebp), %edi\n" /* s */
        "movl -0x30(%ebp), %eax\n" /* address */
        "movl %eax, -0x29c(%ebp)\n"
        "jmp .Lf1e6392_001e6649\n"
        /* { scope 2: address, _true, i, buf */
        /* { scope 3 */
        ".Lf1e6392_001e6b2e:\n"
        "movb $1, -0x6f(%ebp)\n" /* line 810 */
        "movl $3, %edx\n"
        "jmp .Lf1e6392_001e6a52\n"
        ".Lf1e6392_001e6b3c:\n"
        "calll WSAGetLastError\n" /* line 771 */
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 772 */
        "movl $0x2b8af0, (%esp)\n" /* "WARNING: NET_OpenSocks: gethostbyname: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6b65:\n"
        "calll WSAGetLastError\n" /* line 875 */
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 876 */
        "movl $0x2b8b80, (%esp)\n" /* "NET_OpenSocks: send: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6b8e:\n"
        "calll WSAGetLastError\n" /* line 786 */
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 787 */
        "movl $0x2b8b64, (%esp)\n" /* "NET_OpenSocks: connect: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6bb7:\n"
        "calll WSAGetLastError\n" /* line 920 */
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 921 */
        "movl $0x2b8b9c, (%esp)\n" /* "NET_OpenSocks: recv: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6be0:\n"
        "movzbl -0x6f(%ebp), %eax\n" /* line 838 */
        "testb %al, %al\n"
        "je .Lf1e6392_001e6c01\n"
        "cmpb $2, %al\n"
        "je .Lf1e6392_001e6cc3\n"
        "movl $0x2b8bd8, (%esp)\n" /* line 845 */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6c01:\n"
        "movb $5, -0x70(%ebp)\n" /* line 902 | buf */
        "movb $3, -0x6f(%ebp)\n" /* line 903 */
        "movb $0, -0x6e(%ebp)\n" /* line 904 */
        "movb $1, -0x6d(%ebp)\n" /* line 905 */
        "movl $0, -0x6c(%ebp)\n" /* line 906 */
        "movl -0x284(%ebp), %eax\n" /* line 46 | port */
        "rolw $8, %ax\n"
        "movw %ax, -0x68(%ebp)\n" /* line 907 */
        "movl $0, 0xc(%esp)\n" /* line 909 */
        "movl $0xa, 8(%esp)\n"
        "leal -0x70(%ebp), %edx\n" /* buf */
        "movl %edx, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll send\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e6e2f\n"
        ".Lf1e6392_001e6c53:\n"
        "movl $0, 0xc(%esp)\n" /* line 917 */
        "movl $0x40, 8(%esp)\n"
        "leal -0x70(%ebp), %ecx\n" /* buf */
        "movl %ecx, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll recv\n"
        "cmpl $-1, %eax\n" /* line 918 */
        "je .Lf1e6392_001e6bb7\n"
        "subl $1, %eax\n" /* line 924 */
        "jle .Lf1e6392_001e6abe\n"
        "cmpb $5, -0x70(%ebp)\n" /* buf */
        "jne .Lf1e6392_001e6abe\n"
        "movzbl -0x6f(%ebp), %eax\n" /* line 930 */
        "testb %al, %al\n"
        "jne .Lf1e6392_001e6e17\n"
        "movzbl -0x6d(%ebp), %eax\n" /* line 935 */
        "cmpb $1, %al\n"
        "je .Lf1e6392_001e6ddc\n"
        "movzbl %al, %eax\n" /* line 937 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8c44, (%esp)\n" /* "NET_OpenSocks: relay address is not IPV4: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6cc3:\n"
        "movl net_socksUsername, %eax\n" /* line 856 */
        "movl %eax, -0x27c(%ebp)\n"
        "movl 8(%eax), %edi\n" /* s */
        "xorl %edx, %edx\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* s */
        "notl %ecx\n"
        "movl %ecx, -0x298(%ebp)\n"
        "movl %ecx, %esi\n"
        "subl $1, %esi\n"
        "movl net_socksPassword, %eax\n" /* line 857 */
        "movl 8(%eax), %edi\n" /* s */
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* s */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* newsocket */
        "movb $1, -0x70(%ebp)\n" /* line 859 | buf */
        "movl %esi, %edx\n" /* line 860 */
        "movb %dl, -0x6f(%ebp)\n"
        "testl %esi, %esi\n" /* line 861 */
        "je .Lf1e6392_001e6d29\n"
        "leal -0x6e(%ebp), %edx\n" /* line 863 */
        "movl -0x27c(%ebp), %ecx\n"
        "movl 8(%ecx), %eax\n"
        "movl %esi, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        ".Lf1e6392_001e6d29:\n"
        "movb %bl, -0x6e(%ebp, %esi)\n" /* line 865 | newsocket */
        "testl %ebx, %ebx\n" /* line 866 | newsocket */
        "je .Lf1e6392_001e6d54\n"
        "movl -0x298(%ebp), %edx\n" /* line 868 */
        "leal -0x6e(%edx, %ebp), %eax\n"
        "movl net_socksPassword, %edx\n"
        "movl 8(%edx), %edx\n"
        "movl %ebx, 8(%esp)\n" /* newsocket */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        ".Lf1e6392_001e6d54:\n"
        "movl $0, 0xc(%esp)\n" /* line 873 */
        "leal 3(%esi, %ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x70(%ebp), %ecx\n" /* buf */
        "movl %ecx, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll send\n"
        "addl $1, %eax\n"
        "je .Lf1e6392_001e6b65\n"
        "movl $0, 0xc(%esp)\n" /* line 882 */
        "movl $0x40, 8(%esp)\n"
        "leal -0x70(%ebp), %eax\n" /* buf */
        "movl %eax, 4(%esp)\n"
        "movl socks_socket, %eax\n"
        "movl %eax, (%esp)\n"
        "calll recv\n"
        "cmpl $-1, %eax\n" /* line 883 */
        "je .Lf1e6392_001e6bb7\n"
        "cmpl $2, %eax\n" /* line 889 */
        "jne .Lf1e6392_001e6abe\n"
        "cmpb $1, -0x70(%ebp)\n" /* buf */
        "jne .Lf1e6392_001e6abe\n"
        "cmpb $0, -0x6f(%ebp)\n" /* line 894 */
        "je .Lf1e6392_001e6c01\n"
        "movl $0x2b8bf8, (%esp)\n" /* line 896 */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6ddc:\n"
        "movb $2, 0xff0d55\n" /* line 941 */
        "movl -0x6c(%ebp), %eax\n" /* line 942 */
        "movl %eax, 0xff0d58\n"
        "movl -0x68(%ebp), %eax\n" /* line 943 */
        "movw %ax, 0xff0d56\n"
        "movl $0, 0xff0d5c\n" /* line 944 */
        "movl $0, 0xff0d60\n"
        "movl $1, usingSocks\n" /* line 946 */
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6e17:\n"
        "movzbl %al, %eax\n" /* line 932 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8c20, (%esp)\n" /* "NET_OpenSocks: request denied: %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e658a\n"
        ".Lf1e6392_001e6e2f:\n"
        "calll WSAGetLastError\n" /* line 911 */
        "calll ___error\n" /* line 125 */
        "movl (%eax), %eax\n" /* line 126 */
        "movl %eax, (%esp)\n"
        "calll strerror\n"
        "movl %eax, 4(%esp)\n" /* line 912 */
        "movl $0x2b8b80, (%esp)\n" /* "NET_OpenSocks: send: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e6392_001e6c53\n"
    );
}

/* line 1259 */
__attribute__((naked))
jpeg_alloc NET_Config(qboolean enableNetworking)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1259 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* enableNetworking */
        /* { scope 1 */
        "calll NET_GetDvars\n" /* line 1266 */
        "movl %eax, %edx\n"
        "movl net_noudp, %eax\n" /* line 1268 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e6e58_001e6e86\n"
        "movl net_noipx, %eax\n"
        "cmpb $0, 8(%eax)\n"
        "movl $0, %eax\n"
        "cmovnel %eax, %ebx\n" /* enableNetworking */
        ".Lf1e6e58_001e6e86:\n"
        "cmpl networkingEnabled, %ebx\n" /* line 1272 | enableNetworking */
        "je .Lf1e6e58_001e6ee9\n"
        "testl %ebx, %ebx\n" /* line 1292 | enableNetworking */
        "je .Lf1e6e58_001e6ed5\n"
        "xorl %eax, %eax\n"
        "movl $1, %esi\n" /* start */
        ".Lf1e6e58_001e6e99:\n"
        "movl %ebx, networkingEnabled\n" /* line 1302 | enableNetworking */
        "testl %eax, %eax\n" /* line 1305 */
        "je .Lf1e6e58_001e6ebf\n"
        ".Lf1e6e58_001e6ea3:\n"
        "movl ip_socket, %edx\n" /* line 1307 */
        "leal -1(%edx), %eax\n"
        "cmpl $-3, %eax\n"
        "jbe .Lf1e6e58_001e6f0c\n"
        ".Lf1e6e58_001e6eb1:\n"
        "movl socks_socket, %edx\n" /* line 1313 */
        "leal -1(%edx), %eax\n"
        "cmpl $-3, %eax\n"
        "jbe .Lf1e6e58_001e6ef8\n"
        ".Lf1e6e58_001e6ebf:\n"
        "testl %esi, %esi\n" /* line 1328 | start */
        "je .Lf1e6e58_001e6ece\n"
        "movl net_noudp, %eax\n" /* line 1330 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf1e6e58_001e6ede\n"
        /* } scope */
        ".Lf1e6e58_001e6ece:\n"
        "addl $0x10, %esp\n" /* line 1341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e6e58_001e6ed5:\n"
        "movl $1, %eax\n" /* line 1292 */
        "xorl %esi, %esi\n" /* start */
        "jmp .Lf1e6e58_001e6e99\n"
        /* } scope */
        ".Lf1e6e58_001e6ede:\n"
        "addl $0x10, %esp\n" /* line 1341 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp NET_OpenIP\n" /* line 1332 */
        ".Lf1e6e58_001e6ee9:\n"
        "testl %edx, %edx\n" /* line 1272 */
        "je .Lf1e6e58_001e6ece\n"
        "testl %ebx, %ebx\n" /* line 1279 | enableNetworking */
        "je .Lf1e6e58_001e6ece\n"
        "movl $1, %esi\n" /* start */
        "jmp .Lf1e6e58_001e6ea3\n"
        ".Lf1e6e58_001e6ef8:\n"
        "movl %edx, (%esp)\n" /* line 1315 */
        "calll closesocket\n"
        "movl $0, socks_socket\n" /* line 1316 */
        "jmp .Lf1e6e58_001e6ebf\n"
        ".Lf1e6e58_001e6f0c:\n"
        "movl %edx, (%esp)\n" /* line 1309 */
        "calll closesocket\n"
        "movl $0, ip_socket\n" /* line 1310 */
        "jmp .Lf1e6e58_001e6eb1\n"
    );
}

/* line 1564 */
__attribute__((naked))
jpeg_alloc NET_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1564 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $winsockdata, 4(%esp)\n" /* line 1574 */
        "movl $0x101, (%esp)\n"
        "calll WSAStartup\n"
        "testl %eax, %eax\n" /* line 1575 */
        "je .Lf1e6f20_001e6f50\n"
        "movl %eax, 4(%esp)\n" /* line 1578 */
        "movl $0x2b8d94, (%esp)\n" /* "WARNING: Network initialization failed, returned %d
" */
        "calll Com_Printf\n"
        /* } scope */
        "leave\n" /* line 1615 */
        "retl\n"
        /* { scope 1 */
        ".Lf1e6f20_001e6f50:\n"
        "movl $1, winsockInitialized\n" /* line 1585 */
        "movl $0x2b8dcc, (%esp)\n" /* line 1587 */
        "calll Com_Printf\n"
        "calll NET_GetDvars\n" /* line 1599 */
        "movl $1, (%esp)\n" /* line 1602 */
        "calll NET_Config\n"
        /* } scope */
        "leave\n" /* line 1615 */
        "retl\n"
    );
}

/* line 1366 */
jpeg_alloc NET_Restart(void)
{
    NET_Config(networkingEnabled);
}

