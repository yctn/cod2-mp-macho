/* ASM dump from: cl_net_chan_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_net_chan_mp.cpp */

#include "common_types.h"
#include "imports.h"

void CL_Netchan_Decode(byte *data, int size);
void CL_Netchan_TransmitNextFragment(netchan_t *chan);
void CL_Netchan_Transmit(netchan_t *chan, byte *data, int length);
void CL_Netchan_AddOOBProfilePacket(int iLength);
void CL_Netchan_SendOOBPacket(int iLength, const void *pData, netadr_t to);
void CL_Netchan_PrintProfileStats(qboolean bPrintToConsole);

/* line 58 */
__attribute__((naked))
void CL_Netchan_Decode(byte *data, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 58 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl 0x195ee8c, %eax\n" /* line 63 */
        "movl (%eax), %edx\n"
        "movl 0x134(%edx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x138(%eax, %edx), %edi\n" /* string */
        "movl 0x20138(%edx), %eax\n" /* line 66 */
        "movzbl 0x128(%edx), %ebx\n" /* key */
        "xorb %al, %bl\n" /* key */
        "movl 0xc(%ebp), %eax\n" /* line 67 | size */
        "testl %eax, %eax\n"
        "jle .Lf18dd10_0018dd92\n"
        "xorl %esi, %esi\n" /* index */
        "xorl %edx, %edx\n"
        "jmp .Lf18dd10_0018dd6d\n"
        ".Lf18dd10_0018dd4c:\n"
        "movl %edi, %eax\n" /* line 70 | string */
        "movl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 73 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "movl 8(%ebp), %eax\n" /* line 76 | data */
        "xorb %bl, (%edx, %eax)\n" /* key */
        "addl $1, %edx\n" /* line 67 */
        "cmpl 0xc(%ebp), %edx\n" /* size */
        "je .Lf18dd10_0018dd92\n"
        ".Lf18dd10_0018dd6d:\n"
        "leal (%edi, %esi), %eax\n" /* line 70 | string */
        "cmpb $0, (%eax)\n"
        "je .Lf18dd10_0018dd4c\n"
        "addl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 73 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "movl 8(%ebp), %eax\n" /* line 76 | data */
        "xorb %bl, (%edx, %eax)\n" /* key */
        "addl $1, %edx\n" /* line 67 */
        "cmpl 0xc(%ebp), %edx\n" /* size */
        "jne .Lf18dd10_0018dd6d\n"
        /* } scope */
        ".Lf18dd10_0018dd92:\n"
        "popl %ebx\n" /* line 78 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 88 */
__attribute__((naked))
void CL_Netchan_TransmitNextFragment(netchan_t *chan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 90 | chan */
        "movl %eax, (%esp)\n"
        "calll Netchan_TransmitNextFragment\n"
        "leave\n" /* line 91 */
        "retl\n"
    );
}

/* line 99 */
__attribute__((naked))
void CL_Netchan_Transmit(netchan_t *chan, byte *data, int length)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 102 | length */
        "subl $9, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* size */
        "movl 0xc(%ebp), %edi\n" /* data */
        "addl $9, %edi\n" /* data */
        /* { scope 1: string */
        /* { scope 2 */
        "movl 0x195ee8c, %eax\n" /* line 30 */
        "movl (%eax), %edx\n"
        "movl 0x2013c(%edx), %eax\n"
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "leal 0x20144(%eax, %edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* string */
        "movl 0x195ee78, %eax\n" /* line 33 */
        "movl (%eax), %eax\n"
        "movl 0x8628(%eax), %eax\n"
        "movzbl 0x128(%edx), %ebx\n" /* key */
        "xorb %al, %bl\n" /* key */
        "xorb 0x20138(%edx), %bl\n" /* key */
        "movl -0x20(%ebp), %edx\n" /* line 34 | size */
        "testl %edx, %edx\n"
        "jle .Lf18ddac_0018de4d\n"
        "xorl %esi, %esi\n" /* index */
        "xorl %edx, %edx\n"
        "jmp .Lf18ddac_0018de29\n"
        ".Lf18ddac_0018de0a:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 37 | string */
        "movl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 40 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "xorb %bl, (%edi, %edx)\n" /* line 43 | key */
        "addl $1, %edx\n" /* line 34 */
        "cmpl %edx, -0x20(%ebp)\n" /* size */
        "je .Lf18ddac_0018de4d\n"
        ".Lf18ddac_0018de29:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 37 | string */
        "addl %esi, %eax\n" /* index */
        "cmpb $0, (%eax)\n"
        "je .Lf18ddac_0018de0a\n"
        "addl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 40 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "xorb %bl, (%edi, %edx)\n" /* line 43 | key */
        "addl $1, %edx\n" /* line 34 */
        "cmpl %edx, -0x20(%ebp)\n" /* size */
        "jne .Lf18ddac_0018de29\n"
        /* } scope */
        /* } scope */
        ".Lf18ddac_0018de4d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 104 | data */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* length */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* chan */
        "movl %eax, (%esp)\n"
        "calll Netchan_Transmit\n"
        "addl $0x2c, %esp\n" /* line 111 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 119 */
__attribute__((naked))
void CL_Netchan_AddOOBProfilePacket(int iLength)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195f67c, %eax\n" /* line 121 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf18de6e_0018deb5\n"
        "movl 0x195ee8c, %eax\n" /* line 123 */
        "movl (%eax), %ebx\n"
        "leal 0x48800(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movl $0, 8(%esp)\n" /* line 124 */
        "movl 8(%ebp), %eax\n" /* iLength */
        "movl %eax, 4(%esp)\n"
        "movl 0x48800(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_AddPacket\n"
        ".Lf18de6e_0018deb5:\n"
        "addl $0x14, %esp\n" /* line 126 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 134 */
__attribute__((naked))
void CL_Netchan_SendOOBPacket(int iLength, const void *pData, netadr_t to)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 134 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* iLength */
        "movl %eax, -0x30(%ebp)\n" /* iLength */
        "movl 0xc(%ebp), %edx\n" /* pData */
        "movl %edx, -0x34(%ebp)\n" /* pData */
        "movl 0x18(%ebp), %esi\n"
        "movzbl 0x17(%ebp), %edi\n"
        "movzbl 0x16(%ebp), %eax\n"
        "movb %al, -0x29(%ebp)\n"
        "movzbl 0x15(%ebp), %edx\n"
        "movb %dl, -0x2a(%ebp)\n"
        "movzbl 0x14(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movl 0x10(%ebp), %ebx\n" /* to */
        "movl -0x34(%ebp), %edx\n" /* line 139 | pData */
        "cmpl $-1, (%edx)\n"
        "je .Lf18debe_0018df06\n"
        "movl $0x2afbf0, (%esp)\n" /* line 140 */
        "calll Com_Printf\n"
        ".Lf18debe_0018df06:\n"
        "movl 0x195ee8c, %eax\n" /* line 142 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "addl $0x48800, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movw %si, -0x1c(%ebp)\n" /* line 143 */
        "movl %edi, %eax\n"
        "movb %al, -0x1d(%ebp)\n"
        "movzbl -0x29(%ebp), %edx\n"
        "movb %dl, -0x1e(%ebp)\n"
        "movzbl -0x2a(%ebp), %eax\n"
        "movb %al, -0x1f(%ebp)\n"
        "movzbl -0x2b(%ebp), %edx\n"
        "movb %dl, -0x20(%ebp)\n"
        "movl %ebx, -0x24(%ebp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* pData */
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %edx\n" /* iLength */
        "movl %edx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_SendPacket\n"
        "movl 0x195f67c, %eax\n" /* line 121 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf18debe_0018df83\n"
        "addl $0x5c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18debe_0018df83:\n"
        "movl -0x38(%ebp), %eax\n" /* line 123 */
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movl $0, 0x10(%ebp)\n" /* line 124 | to */
        "movl -0x30(%ebp), %edx\n" /* iLength */
        "movl %edx, 0xc(%ebp)\n" /* pData */
        "movl -0x3c(%ebp), %edx\n"
        "movl 0x48800(%edx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* iLength */
        "addl $0x5c, %esp\n" /* line 145 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp NetProf_AddPacket\n" /* line 124 */
    );
}

/* line 187 */
__attribute__((naked))
void CL_Netchan_PrintProfileStats(qboolean bPrintToConsole)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 187 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        /* { scope 1 */
        "movl 0x195ee8c, %eax\n" /* line 155 */
        "movl (%eax), %ebx\n"
        "movl 0x487fc(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018dfec\n"
        "movl %eax, (%esp)\n" /* line 157 */
        "calll NetProf_UpdateStatistics\n"
        "movl 0x487fc(%ebx), %eax\n" /* line 158 */
        "addl $0x2f0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_UpdateStatistics\n"
        ".Lf18dfb4_0018dfec:\n"
        "movl 0x48800(%ebx), %eax\n" /* line 161 */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e011\n"
        "movl %eax, (%esp)\n" /* line 163 */
        "calll NetProf_UpdateStatistics\n"
        "movl 0x48800(%ebx), %eax\n" /* line 164 */
        "addl $0x2f0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_UpdateStatistics\n"
        ".Lf18dfb4_0018e011:\n"
        "movl 8(%ebp), %eax\n" /* line 201 | bPrintToConsole */
        "testl %eax, %eax\n"
        "jne .Lf18dfb4_0018e54a\n"
        ".Lf18dfb4_0018e01c:\n"
        "movl $0x2afc2c, 8(%esp)\n" /* line 203 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x418(%ebp), %esi\n" /* szLine */
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 204 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e2d1\n"
        "movl %esi, 4(%esp)\n" /* line 205 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl $0x50, %edi\n" /* iYPos */
        "movl $0x2afc44, 8(%esp)\n" /* line 209 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 210 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e321\n"
        ".Lf18dfb4_0018e07d:\n"
        "movl %esi, 4(%esp)\n" /* line 211 */
        "movl $0x21dcd4, (%esp)\n" /* "%s

" */
        "calll Com_Printf\n"
        "movl $0x2afc5c, 8(%esp)\n" /* line 218 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 219 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e36e\n"
        ".Lf18dfb4_0018e0b0:\n"
        "movl %esi, 4(%esp)\n" /* line 220 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl 0x195ee8c, %eax\n" /* line 225 */
        "movl (%eax), %eax\n"
        "movl 0x48800(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf18dfb4_0018e3aa\n"
        ".Lf18dfb4_0018e0d5:\n"
        "movl 0x2d4(%ebx), %eax\n" /* line 229 */
        "movl %eax, -0x420(%ebp)\n" /* iTotalBPSSent */
        "movl 0x5c4(%ebx), %eax\n" /* line 230 */
        "movl %eax, -0x41c(%ebp)\n" /* iTotalBPSRecieved */
        "movl 0x2ec(%ebx), %eax\n" /* line 232 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2e8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x420(%ebp), %eax\n" /* iTotalBPSSent */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2afc84, 8(%esp)\n" /* "    OOB Sent: %5i %5i %5i    -" */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 233 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e429\n"
        "movl %esi, 4(%esp)\n" /* line 234 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18dfb4_0018e13e:\n"
        "movl 0x5dc(%ebx), %eax\n" /* line 238 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x5d8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x5c4(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2afca4, 8(%esp)\n" /* "OOB Recieved: %5i %5i %5i    -" */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %ecx\n" /* line 239 | bPrintToConsole */
        "testl %ecx, %ecx\n"
        "je .Lf18dfb4_0018e51e\n"
        "movl %esi, 4(%esp)\n" /* line 240 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18dfb4_0018e18f:\n"
        "movl 0x195ee8c, %eax\n" /* line 259 */
        "movl (%eax), %eax\n"
        "movl 0x487fc(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf18dfb4_0018e487\n"
        "movl 0x2d4(%ebx), %edx\n" /* line 263 */
        "addl %edx, -0x420(%ebp)\n" /* iTotalBPSSent */
        "movl 0x5c4(%ebx), %eax\n" /* line 264 */
        "addl %eax, -0x41c(%ebp)\n" /* iTotalBPSRecieved */
        "movl 0x2e4(%ebx), %eax\n" /* line 266 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x2ec(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2e8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $0x2afd14, 8(%esp)\n" /* "        Sent: %5i %5i %5i  %3i%%" */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 267 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e4f2\n"
        "movl %esi, 4(%esp)\n" /* line 268 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18dfb4_0018e211:\n"
        "movl 0x5d4(%ebx), %eax\n" /* line 272 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x5dc(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x5d8(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x5c4(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2afd38, 8(%esp)\n" /* "    Recieved: %5i %5i %5i  %3i%%" */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 273 | bPrintToConsole */
        "testl %eax, %eax\n"
        "jne .Lf18dfb4_0018e4dd\n"
        ".Lf18dfb4_0018e25c:\n"
        "addl $0xa, %edi\n" /* line 290 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        ".Lf18dfb4_0018e283:\n"
        "movl -0x420(%ebp), %eax\n" /* line 295 | iTotalBPSSent */
        "addl -0x41c(%ebp), %eax\n" /* iTotalBPSRecieved */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2afdac, 8(%esp)\n" /* "       Total: %5i" */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 296 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e455\n"
        "movl %esi, 4(%esp)\n" /* line 297 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18dfb4_0018e2d1:\n"
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl $0x5a, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl $0x5a, %edi\n"
        "movl $0x2afc44, 8(%esp)\n" /* line 209 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 210 | bPrintToConsole */
        "testl %eax, %eax\n"
        "jne .Lf18dfb4_0018e07d\n"
        ".Lf18dfb4_0018e321:\n"
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "leal 0xa(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "addl $0x14, %edi\n" /* line 215 | iYPos */
        "movl $0x2afc5c, 8(%esp)\n" /* line 218 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 219 | bPrintToConsole */
        "testl %eax, %eax\n"
        "jne .Lf18dfb4_0018e0b0\n"
        ".Lf18dfb4_0018e36e:\n"
        "addl $0xa, %edi\n" /* line 222 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl 0x195ee8c, %eax\n" /* line 225 */
        "movl (%eax), %eax\n"
        "movl 0x48800(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf18dfb4_0018e0d5\n"
        ".Lf18dfb4_0018e3aa:\n"
        "movl $0x2afcc4, 8(%esp)\n" /* line 246 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %edx\n" /* line 247 | bPrintToConsole */
        "testl %edx, %edx\n"
        "je .Lf18dfb4_0018e5c7\n"
        "movl %esi, 4(%esp)\n" /* line 248 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18dfb4_0018e3dd:\n"
        "movl $0x2afcec, 8(%esp)\n" /* line 252 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 253 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e587\n"
        "movl %esi, 4(%esp)\n" /* line 254 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl $0, -0x420(%ebp)\n" /* iTotalBPSSent */
        "movl $0, -0x41c(%ebp)\n" /* iTotalBPSRecieved */
        "jmp .Lf18dfb4_0018e18f\n"
        ".Lf18dfb4_0018e429:\n"
        "addl $0xa, %edi\n" /* line 236 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18dfb4_0018e13e\n"
        ".Lf18dfb4_0018e455:\n"
        "movl $0xa, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "leal 0xa(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18dfb4_0018e487:\n"
        "movl $0x2afd5c, 8(%esp)\n" /* line 280 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 281 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e55b\n"
        "movl %esi, 4(%esp)\n" /* line 282 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18dfb4_0018e4ba:\n"
        "movl $0x2afd84, 8(%esp)\n" /* line 286 */
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 287 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18dfb4_0018e25c\n"
        ".Lf18dfb4_0018e4dd:\n"
        "movl %esi, 4(%esp)\n" /* line 288 */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf18dfb4_0018e283\n"
        ".Lf18dfb4_0018e4f2:\n"
        "addl $0xa, %edi\n" /* line 270 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18dfb4_0018e211\n"
        ".Lf18dfb4_0018e51e:\n"
        "addl $0xa, %edi\n" /* line 242 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18dfb4_0018e18f\n"
        ".Lf18dfb4_0018e54a:\n"
        "movl $0x2afc28, (%esp)\n" /* line 202 */
        "calll Com_Printf\n"
        "jmp .Lf18dfb4_0018e01c\n"
        ".Lf18dfb4_0018e55b:\n"
        "addl $0xa, %edi\n" /* line 284 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18dfb4_0018e4ba\n"
        ".Lf18dfb4_0018e587:\n"
        "addl $0xa, %edi\n" /* line 256 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl $0, -0x420(%ebp)\n" /* iTotalBPSSent */
        "movl $0, -0x41c(%ebp)\n" /* iTotalBPSRecieved */
        "jmp .Lf18dfb4_0018e18f\n"
        ".Lf18dfb4_0018e5c7:\n"
        "addl $0xa, %edi\n" /* line 250 | iYPos */
        "movl $0xa, 0x10(%esp)\n" /* line 178 */
        "movl $0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18dfb4_0018e3dd\n"
    );
}

