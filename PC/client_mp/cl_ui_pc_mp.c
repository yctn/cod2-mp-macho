/* ASM dump from: cl_ui_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_ui_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"

int LAN_AddServer(int source, const char *name, const char *address);
int LAN_RemoveServer(int source, const char *addr);
int LAN_GetServerAddressString(int source, int n, char *buf, int buflen);
int LAN_LoadCachedServers(void);
int LAN_SaveServersToCache(void);

/* line 25 */
__attribute__((naked))
int LAN_AddServer(int source, const char *name, const char *address)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "cmpl $2, 8(%ebp)\n" /* line 34 | source */
        "je .Lf1c5154_001c5170\n"
        ".Lf1c5154_001c5163:\n"
        "movl $0xffffffff, %eax\n" /* line 60 */
        /* } scope */
        ".Lf1c5154_001c5168:\n"
        "addl $0x6c, %esp\n" /* line 69 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c5154_001c5170:\n"
        "movl 0x195ecac, %ebx\n" /* line 44 */
        "cmpl $0x7f, 0x29c644(%ebx)\n"
        "jg .Lf1c5154_001c5163\n"
        "leal -0x3c(%ebp), %eax\n" /* line 46 | adr */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* address */
        "movl %eax, (%esp)\n"
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "je .Lf1c5154_001c521e\n"
        "movl 0x29c644(%ebx), %eax\n" /* line 49 */
        "testl %eax, %eax\n"
        "jg .Lf1c5154_001c5228\n"
        "movl %ebx, %esi\n"
        ".Lf1c5154_001c51a9:\n"
        "movl 0x29c644(%esi), %edx\n" /* line 55 */
        ".Lf1c5154_001c51af:\n"
        "movl %edx, %eax\n" /* line 57 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %edx\n"
        "leal 0x29c648(%esi), %ebx\n"
        "movl -0x3c(%ebp), %eax\n" /* adr */
        "movl %eax, (%edx, %ebx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%edx, %ebx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 8(%edx, %ebx)\n"
        "movl $0x20, 8(%esp)\n" /* line 58 */
        "movl 0xc(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl 0x29c644(%esi), %eax\n"
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0x20(%eax, %ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl 0x29c644(%esi), %eax\n" /* line 59 */
        "movl %eax, %edx\n"
        "shll $7, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movb $1, 0xf(%eax, %ebx)\n"
        "addl $1, 0x29c644(%esi)\n" /* line 60 */
        "movl $1, %eax\n"
        "jmp .Lf1c5154_001c5168\n"
        ".Lf1c5154_001c521e:\n"
        "movl $0xfffffffe, %eax\n" /* line 46 */
        "jmp .Lf1c5154_001c5168\n"
        ".Lf1c5154_001c5228:\n"
        "movl $0, -0x4c(%ebp)\n" /* line 49 | i */
        "leal 0x29c648(%ebx), %edi\n"
        "jmp .Lf1c5154_001c5256\n"
        ".Lf1c5154_001c5237:\n"
        "addl $1, -0x4c(%ebp)\n" /* i */
        "addl $0x88, %edi\n"
        "movl 0x195ecac, %esi\n"
        "movl -0x4c(%ebp), %eax\n" /* i */
        "cmpl 0x29c644(%esi), %eax\n"
        "jge .Lf1c5154_001c51a9\n"
        ".Lf1c5154_001c5256:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 51 | adr */
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x38(%ebp), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl -0x34(%ebp), %ebx\n"
        "movl %ebx, -0x28(%ebp)\n"
        "movl (%edi), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl 4(%edi), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* adr */
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf1c5154_001c5237\n"
        "movl 0x195ecac, %esi\n" /* line 55 */
        "movl 0x29c644(%esi), %edx\n"
        "cmpl -0x4c(%ebp), %edx\n" /* i */
        "jle .Lf1c5154_001c51af\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1c5154_001c5168\n"
    );
}

/* line 76 */
__attribute__((naked))
int LAN_RemoveServer(int source, const char *addr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 76 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: comp */
        "cmpl $2, 8(%ebp)\n" /* line 82 | source */
        "je .Lf1c52b8_001c52cf\n"
        /* } scope */
        ".Lf1c52b8_001c52c7:\n"
        "addl $0x6c, %esp\n" /* line 112 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: comp */
        /* { scope 2 */
        ".Lf1c52b8_001c52cf:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 95 | comp */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* addr */
        "movl %eax, (%esp)\n"
        "calll NET_StringToAdr\n"
        "movl 0x195ecac, %eax\n" /* line 96 */
        "movl 0x29c644(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1c52b8_001c52c7\n"
        "movl $0, -0x50(%ebp)\n" /* i */
        "addl $0x29c648, %eax\n" /* "1.xyz, r0, c0.x;
MUL    r0, r1, v0;
MAD r1.xyz, v0, -r1, c23" */
        "movl %eax, -0x4c(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lf1c52b8_001c5321\n"
        ".Lf1c52b8_001c5303:\n"
        "addl $1, -0x50(%ebp)\n" /* i */
        "addl $0x88, -0x4c(%ebp)\n"
        "movl 0x195ecac, %eax\n"
        "movl -0x50(%ebp), %edx\n" /* i */
        "cmpl 0x29c644(%eax), %edx\n"
        "jge .Lf1c52b8_001c52c7\n"
        "movl -0x4c(%ebp), %edx\n"
        ".Lf1c52b8_001c5321:\n"
        "movl (%edx), %edi\n" /* line 98 */
        "movl %edi, -0x30(%ebp)\n"
        "movl 4(%edx), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl 8(%edx), %ebx\n"
        "movl %ebx, -0x28(%ebp)\n"
        "movl -0x3c(%ebp), %ecx\n" /* comp */
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x38(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_CompareAdr\n"
        "testl %eax, %eax\n"
        "je .Lf1c52b8_001c5303\n"
        /* { scope 3 */
        "movl 0x195ecac, %edi\n" /* line 102 */
        "movl 0x29c644(%edi), %eax\n"
        "subl $1, %eax\n"
        "cmpl %eax, -0x50(%ebp)\n" /* i */
        "jl .Lf1c52b8_001c5383\n"
        ".Lf1c52b8_001c5378:\n"
        "movl %eax, 0x29c644(%edi)\n" /* line 107 */
        "jmp .Lf1c52b8_001c52c7\n"
        ".Lf1c52b8_001c5383:\n"
        "movl -0x50(%ebp), %eax\n" /* line 102 | i */
        "shll $7, %eax\n"
        "movl -0x50(%ebp), %edx\n" /* i */
        "leal (%eax, %edx, 8), %esi\n"
        "movl %edx, %ebx\n" /* j */
        ".Lf1c52b8_001c5391:\n"
        "leal 0x29c648(%edi, %esi), %edx\n" /* line 104 */
        "movl $0x88, 8(%esp)\n"
        "leal 0x88(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_Memcpy\n"
        "addl $1, %ebx\n" /* line 105 | j */
        "movl 0x29c644(%edi), %eax\n" /* line 102 */
        "subl $1, %eax\n"
        "addl $0x88, %esi\n"
        "cmpl %eax, %ebx\n" /* j */
        "jl .Lf1c52b8_001c5391\n"
        "jmp .Lf1c52b8_001c5378\n"
    );
}

/* line 120 */
__attribute__((naked))
int LAN_GetServerAddressString(int source, int n, char *buf, int buflen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 8(%ebp), %eax\n" /* source */
        "movl 0xc(%ebp), %edx\n" /* n */
        "movl 0x10(%ebp), %ebx\n" /* buf */
        "movl 0x14(%ebp), %esi\n" /* buflen */
        "cmpl $1, %eax\n" /* line 122 */
        "je .Lf1c53ca_001c5448\n"
        "cmpl $2, %eax\n"
        "je .Lf1c53ca_001c547d\n"
        "testl %eax, %eax\n"
        "je .Lf1c53ca_001c53fa\n"
        ".Lf1c53ca_001c53f0:\n"
        "movb $0, (%ebx)\n" /* line 150 | buf */
        "addl $0x40, %esp\n" /* line 151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1c53ca_001c53fa:\n"
        "cmpl $0x7f, %edx\n" /* line 125 */
        "ja .Lf1c53ca_001c53f0\n"
        "movl %edx, %eax\n" /* line 127 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "addl $0x130, %eax\n"
        "movl 0xc(%eax), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        ".Lf1c53ca_001c5424:\n"
        "movl %ecx, (%esp)\n" /* line 135 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %esi, 0x10(%ebp)\n" /* buflen, buf */
        "movl %eax, 0xc(%ebp)\n" /* n */
        "movl %ebx, 8(%ebp)\n" /* buf, source */
        "addl $0x40, %esp\n" /* line 151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp I_strncpyz\n" /* line 135 */
        ".Lf1c53ca_001c5448:\n"
        "testl %edx, %edx\n" /* line 133 */
        "js .Lf1c53ca_001c53f0\n"
        "movl 0x195ecac, %ecx\n"
        "cmpl 0x4540(%ecx), %edx\n"
        "jge .Lf1c53ca_001c53f0\n"
        "movl %edx, %eax\n" /* line 135 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "leal 0x4540(%eax, %ecx), %eax\n"
        "movl 4(%eax), %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "jmp .Lf1c53ca_001c5424\n"
        ".Lf1c53ca_001c547d:\n"
        "cmpl $0x7f, %edx\n" /* line 142 */
        "ja .Lf1c53ca_001c53f0\n"
        "movl %edx, %eax\n" /* line 144 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %eax\n"
        "addl 0x195ecac, %eax\n"
        "addl $0x29c640, %eax\n" /* "ADD    r1.xyz, r0, c0.x;
MUL    r0, r1, v0;
MAD r1.xyz, v0, " */
        "movl 8(%eax), %ecx\n"
        "movl %ecx, -0x14(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0xc(%ebp)\n"
        "jmp .Lf1c53ca_001c5424\n"
    );
}

/* line 196 */
__attribute__((naked))
int LAN_LoadCachedServers(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 196 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "leal -0xc(%ebp), %eax\n" /* line 201 | fileIn */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b6980, (%esp)\n" /* "servercache.dat" */
        "calll FS_SV_FOpenFileRead\n"
        "testl %eax, %eax\n"
        "jne .Lf1c54b0_001c54ef\n"
        ".Lf1c54b0_001c54cf:\n"
        "movl 0x195ecac, %eax\n" /* line 212 */
        "movl $0, 0x4540(%eax)\n"
        "movl $0, 0x29c644(%eax)\n" /* line 213 */
        /* } scope */
        ".Lf1c54b0_001c54e8:\n"
        "addl $0x20, %esp\n" /* line 214 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c54b0_001c54ef:\n"
        "movl -0xc(%ebp), %ebx\n" /* line 203 | fileIn */
        /* { scope 2: size, version */
        /* { scope 3 */
        "movl %ebx, 8(%esp)\n" /* line 166 */
        "movl $4, 4(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* version */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $4, %eax\n"
        "je .Lf1c54b0_001c5526\n"
        ".Lf1c54b0_001c550e:\n"
        "xorl %ebx, %ebx\n" /* line 184 */
        /* } scope */
        /* } scope */
        ".Lf1c54b0_001c5510:\n"
        "movl -0xc(%ebp), %eax\n" /* line 204 | fileIn */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "testl %ebx, %ebx\n" /* line 205 | fileIn */
        "je .Lf1c54b0_001c54cf\n"
        "calll CL_SortGlobalServers\n" /* line 207 */
        "jmp .Lf1c54b0_001c54e8\n"
        /* { scope 2: size, version */
        /* { scope 3 */
        ".Lf1c54b0_001c5526:\n"
        "cmpl $1, -0x14(%ebp)\n" /* line 168 | version */
        "jne .Lf1c54b0_001c550e\n"
        "movl %ebx, 8(%esp)\n" /* line 170 */
        "movl $4, 4(%esp)\n"
        "movl 0x195ecac, %esi\n"
        "leal 0x4540(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $4, %eax\n"
        "jne .Lf1c54b0_001c550e\n"
        "cmpl $0x4e1f, 0x4540(%esi)\n" /* line 172 */
        "ja .Lf1c54b0_001c550e\n"
        "movl %ebx, 8(%esp)\n" /* line 174 */
        "movl $4, 4(%esp)\n"
        "leal 0x29c644(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $4, %eax\n"
        "jne .Lf1c54b0_001c550e\n"
        "cmpl $0x7f, 0x29c644(%esi)\n" /* line 176 */
        "ja .Lf1c54b0_001c550e\n"
        "movl %ebx, 8(%esp)\n" /* line 178 */
        "movl $4, 4(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* size */
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $4, %eax\n"
        "jne .Lf1c54b0_001c550e\n"
        "cmpl $0x29c500, -0x10(%ebp)\n" /* line 180 | size */
        "jne .Lf1c54b0_001c550e\n"
        "movl %ebx, 8(%esp)\n" /* line 182 */
        "movl $0x298100, 4(%esp)\n" /* "fogcoord.x, 0;MIN  r15.x, r15.x, 1;LRP oC0AfterFog.xyz, r15." */
        "leal 0x4544(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $0x298100, %eax\n" /* "fogcoord.x, 0;MIN  r15.x, r15.x, 1;LRP oC0AfterFog.xyz, r15." */
        "jne .Lf1c54b0_001c550e\n"
        "movl %ebx, 8(%esp)\n" /* line 184 */
        "movl $0x4400, 4(%esp)\n"
        "leal 0x29c648(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Read\n"
        "cmpl $0x4400, %eax\n"
        "jne .Lf1c54b0_001c550e\n"
        "movl $1, %ebx\n"
        "jmp .Lf1c54b0_001c5510\n"
    );
}

/* line 224 */
__attribute__((naked))
int LAN_SaveServersToCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 224 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl $0x2b6980, (%esp)\n" /* line 239 */
        "calll FS_SV_FOpenFileWrite\n"
        "movl %eax, -0x2c(%ebp)\n" /* fileOut */
        "testl %eax, %eax\n" /* line 240 */
        "jne .Lf1c5606_001c562a\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 273 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c5606_001c562a:\n"
        "movl $1, -0x20(%ebp)\n" /* line 243 | version */
        "movl %eax, 8(%esp)\n" /* line 244 */
        "movl $4, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* version */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl 0x195ecac, %esi\n" /* line 246 */
        "movl 0x4540(%esi), %edx\n"
        "subl $1, %edx\n"
        "js .Lf1c5606_001c56f0\n"
        "movl %esi, -0x30(%ebp)\n"
        "jmp .Lf1c5606_001c569d\n"
        ".Lf1c5606_001c5662:\n"
        "testl %edx, %edx\n" /* line 251 */
        "je .Lf1c5606_001c56f0\n"
        "leal -1(%edx), %ebx\n" /* line 255 */
        "movl %ebx, %eax\n"
        "shll $7, %eax\n"
        "leal 0x4540(%eax, %ebx, 8), %eax\n"
        "leal 4(%eax, %esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x4544(%ecx, %esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll NET_CompareAdrSigned\n"
        "testl %eax, %eax\n"
        "je .Lf1c5606_001c56b4\n"
        "testl %ebx, %ebx\n" /* line 246 */
        "js .Lf1c5606_001c56f0\n"
        ".Lf1c5606_001c5698:\n"
        "movl %ebx, %edx\n"
        "movl -0x30(%ebp), %esi\n"
        ".Lf1c5606_001c569d:\n"
        "movl %edx, %eax\n" /* line 249 */
        "shll $7, %eax\n"
        "leal (%eax, %edx, 8), %ecx\n"
        "leal (%ecx, %esi), %edi\n"
        "cmpb $2, 0x455d(%edi)\n"
        "jbe .Lf1c5606_001c5662\n"
        "leal -1(%edx), %ebx\n"
        ".Lf1c5606_001c56b4:\n"
        "movl 0x4540(%esi), %eax\n" /* line 259 */
        "subl $1, %eax\n"
        "movl %eax, 0x4540(%esi)\n"
        "movl %eax, %edx\n" /* line 260 */
        "shll $7, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0x4544(%edi), %edx\n"
        "leal 0x4544(%eax, %esi), %eax\n"
        "movl $0x88, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "testl %ebx, %ebx\n" /* line 246 */
        "jns .Lf1c5606_001c5698\n"
        ".Lf1c5606_001c56f0:\n"
        "calll CL_SortGlobalServers\n" /* line 263 */
        "movl -0x2c(%ebp), %eax\n" /* line 265 | fileOut */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl 0x195ecac, %ebx\n"
        "leal 0x4540(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x2c(%ebp), %eax\n" /* line 266 | fileOut */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal 0x29c644(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl $0x29c500, -0x1c(%ebp)\n" /* line 268 | size */
        "movl -0x2c(%ebp), %eax\n" /* line 269 | fileOut */
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* size */
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x2c(%ebp), %eax\n" /* line 270 | fileOut */
        "movl %eax, 8(%esp)\n"
        "movl $0x298100, 4(%esp)\n" /* "fogcoord.x, 0;MIN  r15.x, r15.x, 1;LRP oC0AfterFog.xyz, r15." */
        "leal 0x4544(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x2c(%ebp), %eax\n" /* line 271 | fileOut */
        "movl %eax, 8(%esp)\n"
        "movl $0x4400, 4(%esp)\n"
        "addl $0x29c648, %ebx\n" /* "1.xyz, r0, c0.x;
MUL    r0, r1, v0;
MAD r1.xyz, v0, -r1, c23" */
        "movl %ebx, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x2c(%ebp), %eax\n" /* line 272 | fileOut */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 273 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

