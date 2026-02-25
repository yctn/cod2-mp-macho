/* ASM dump from: sv_net_chan_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_net_chan_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

void SV_Netchan_Decode(client_t *client, byte *data, int size);
Bool SV_Netchan_TransmitNextFragment(netchan_t *chan);
Bool SV_Netchan_Transmit(client_t *client, byte *data, int length);
void SV_Netchan_AddOOBProfilePacket(int iLength);
void SV_Netchan_PrintProfileStats(qboolean bPrintToConsole);

/* line 57 */
__attribute__((naked))
void SV_Netchan_Decode(client_t *client, byte *data, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* client */
        /* { scope 1 */
        "movl 0x20810(%ecx), %eax\n" /* line 64 */
        "andl $0x7f, %eax\n"
        "movl %eax, %edx\n"
        "shll $0xa, %edx\n"
        "leal 0x400(%edx, %eax, 8), %eax\n"
        "leal 0xc(%ecx, %eax), %edi\n" /* string */
        "movl 0x765f8(%ecx), %eax\n" /* line 67 */
        "movzbl COpenGL_SetColorMaterialEnable(%ecx), %ebx\n" /* key */
        "xorb %al, %bl\n" /* key */
        "xorb 0x20818(%ecx), %bl\n" /* key */
        "movl 0x10(%ebp), %eax\n" /* line 68 | size */
        "testl %eax, %eax\n"
        "jle .Lf18e5f4_0018e67e\n"
        "xorl %esi, %esi\n" /* index */
        "xorl %edx, %edx\n"
        "jmp .Lf18e5f4_0018e659\n"
        ".Lf18e5f4_0018e638:\n"
        "movl %edi, %eax\n" /* line 71 | string */
        "movl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 74 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "movl 0xc(%ebp), %eax\n" /* line 77 | data */
        "xorb %bl, (%edx, %eax)\n" /* key */
        "addl $1, %edx\n" /* line 68 */
        "cmpl %edx, 0x10(%ebp)\n" /* size */
        "je .Lf18e5f4_0018e67e\n"
        ".Lf18e5f4_0018e659:\n"
        "leal (%edi, %esi), %eax\n" /* line 71 | string */
        "cmpb $0, (%eax)\n"
        "je .Lf18e5f4_0018e638\n"
        "addl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 74 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "movl 0xc(%ebp), %eax\n" /* line 77 | data */
        "xorb %bl, (%edx, %eax)\n" /* key */
        "addl $1, %edx\n" /* line 68 */
        "cmpl %edx, 0x10(%ebp)\n" /* size */
        "jne .Lf18e5f4_0018e659\n"
        /* } scope */
        ".Lf18e5f4_0018e67e:\n"
        "popl %ebx\n" /* line 79 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 89 */
__attribute__((naked))
Bool SV_Netchan_TransmitNextFragment(netchan_t *chan)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 89 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 91 | chan */
        "movl %eax, (%esp)\n"
        "calll Netchan_TransmitNextFragment\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 92 */
        "retl\n"
    );
}

/* line 100 */
__attribute__((naked))
Bool SV_Netchan_Transmit(client_t *client, byte *data, int length)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 100 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* line 103 | length */
        "subl $4, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* size */
        "movl 0xc(%ebp), %edi\n" /* data */
        "addl $4, %edi\n" /* data */
        /* { scope 1: string */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 25 | client */
        "addl $0x20844, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* string */
        "movl 8(%ebp), %edx\n" /* line 28 | client */
        "movl 0x6e5b4(%edx), %eax\n"
        "movzbl COpenGL_SetColorMaterialEnable(%edx), %ebx\n" /* key */
        "xorb %al, %bl\n" /* key */
        "movl -0x20(%ebp), %edx\n" /* line 29 | size */
        "testl %edx, %edx\n"
        "jle .Lf18e69a_0018e720\n"
        "xorl %esi, %esi\n" /* index */
        "xorl %edx, %edx\n"
        "jmp .Lf18e69a_0018e6fc\n"
        ".Lf18e69a_0018e6dd:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 32 | string */
        "movl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 35 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "xorb %bl, (%edi, %edx)\n" /* line 38 | key */
        "addl $1, %edx\n" /* line 29 */
        "cmpl -0x20(%ebp), %edx\n" /* size */
        "je .Lf18e69a_0018e720\n"
        ".Lf18e69a_0018e6fc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 32 | string */
        "addl %esi, %eax\n" /* index */
        "cmpb $0, (%eax)\n"
        "je .Lf18e69a_0018e6dd\n"
        "addl $1, %esi\n" /* index */
        "movzbl (%eax), %eax\n" /* line 35 */
        "movl %edx, %ecx\n"
        "andl $1, %ecx\n"
        "shll %cl, %eax\n"
        "xorb %al, %bl\n" /* key */
        "xorb %bl, (%edi, %edx)\n" /* line 38 | key */
        "addl $1, %edx\n" /* line 29 */
        "cmpl -0x20(%ebp), %edx\n" /* size */
        "jne .Lf18e69a_0018e6fc\n"
        /* } scope */
        /* } scope */
        ".Lf18e69a_0018e720:\n"
        "movl 0xc(%ebp), %eax\n" /* line 105 | data */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* length */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* client */
        "addl $0x6e5b4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Netchan_Transmit\n"
        "movzbl %al, %eax\n"
        "addl $0x2c, %esp\n" /* line 106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 114 */
__attribute__((naked))
void SV_Netchan_AddOOBProfilePacket(int iLength)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 114 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195f67c, %eax\n" /* line 116 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf18e74a_0018e790\n"
        "movl 0x195f284, %ebx\n" /* line 118 */
        "leal 0xa074(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_PrepProfiling\n"
        "movl $0, 8(%esp)\n" /* line 119 */
        "movl 8(%ebp), %eax\n" /* iLength */
        "movl %eax, 4(%esp)\n"
        "movl 0xa074(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_AddPacket\n"
        ".Lf18e74a_0018e790:\n"
        "addl $0x14, %esp\n" /* line 121 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 199 */
__attribute__((naked))
void SV_Netchan_PrintProfileStats(qboolean bPrintToConsole)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4cc, %esp\n"
        /* { scope 1 */
        "movl 0x195f284, %ebx\n" /* line 225 | iFragmentTotal */
        "movl 0xc(%ebx), %eax\n" /* iFragmentTotal */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018ef9b\n"
        "movl 0xa074(%ebx), %eax\n" /* line 154 */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018e7da\n"
        "movl %eax, (%esp)\n" /* line 156 */
        "calll NetProf_UpdateStatistics\n"
        "movl 0xa074(%ebx), %eax\n" /* line 157 */
        "addl $0x2f0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_UpdateStatistics\n"
        ".Lf18e798_0018e7da:\n"
        "movl 0xc(%ebx), %ebx\n" /* line 160 */
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf18e798_0018e82d\n"
        "xorl %esi, %esi\n"
        "movl %edx, %edi\n"
        ".Lf18e798_0018e7f0:\n"
        "movl (%ebx), %eax\n" /* line 162 */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018e81d\n"
        "movl 0x765e8(%ebx), %eax\n" /* line 165 */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018e81d\n"
        "movl %eax, (%esp)\n" /* line 168 */
        "calll NetProf_UpdateStatistics\n"
        "movl 0x765e8(%ebx), %eax\n" /* line 169 */
        "addl $0x2f0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll NetProf_UpdateStatistics\n"
        "movl %edi, %edx\n"
        ".Lf18e798_0018e81d:\n"
        "addl $1, %esi\n" /* line 160 */
        "addl $0x78f0c, %ebx\n"
        "movl (%edx), %eax\n"
        "cmpl %esi, 8(%eax)\n"
        "jg .Lf18e798_0018e7f0\n"
        ".Lf18e798_0018e82d:\n"
        "movl 8(%ebp), %esi\n" /* line 230 | bPrintToConsole, iTotalMinRecieved */
        "testl %esi, %esi\n" /* iTotalMinRecieved */
        "jne .Lf18e798_0018f21a\n"
        ".Lf18e798_0018e838:\n"
        "movl $0x2afc2c, 8(%esp)\n" /* line 232 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %eax\n" /* szLine */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %ebx\n" /* line 233 | bPrintToConsole, iFragmentTotal */
        "testl %ebx, %ebx\n" /* iFragmentTotal */
        "je .Lf18e798_0018efa6\n"
        "leal -0x438(%ebp), %edx\n" /* line 234 | szLine */
        "movl %edx, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl $0x50, -0x44c(%ebp)\n" /* iYPos */
        ".Lf18e798_0018e881:\n"
        "movl $0x2afdc0, 8(%esp)\n" /* line 240 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %esi\n" /* szLine, iTotalMinRecieved */
        "movl %esi, (%esp)\n" /* iTotalMinRecieved */
        "calll Com_sprintf\n"
        "movl 8(%ebp), %ecx\n" /* line 241 | bPrintToConsole */
        "testl %ecx, %ecx\n"
        "je .Lf18e798_0018f025\n"
        "movl %esi, 4(%esp)\n" /* line 242 | iTotalMinRecieved */
        "movl $0x21dcd4, (%esp)\n" /* "%s

" */
        "calll Com_Printf\n"
        ".Lf18e798_0018e8ba:\n"
        "movl $0x2afdd8, 8(%esp)\n" /* line 251 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %edx\n" /* szLine */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %edx\n" /* line 252 | bPrintToConsole */
        "testl %edx, %edx\n"
        "je .Lf18e798_0018f18d\n"
        "leal -0x438(%ebp), %ecx\n" /* line 253 | szLine */
        "movl %ecx, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18e798_0018e8f9:\n"
        "movl $0x2afe3c, 8(%esp)\n" /* line 259 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %eax\n" /* szLine */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 260 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018f0de\n"
        "leal -0x438(%ebp), %edx\n" /* line 261 | szLine */
        "movl %edx, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl 0x195f284, %ebx\n" /* line 271 | iFragmentTotal */
        "movl 0xa074(%ebx), %ecx\n" /* iFragmentTotal */
        "testl %ecx, %ecx\n"
        "je .Lf18e798_0018f129\n"
        ".Lf18e798_0018e94c:\n"
        "movl 0x2d4(%ecx), %edi\n" /* line 275 | pStream */
        "movl %edi, -0x470(%ebp)\n" /* pStream, iTotalBPSSent */
        "movl 0x2dc(%ecx), %eax\n" /* line 276 */
        "movl %eax, -0x468(%ebp)\n" /* iTotalPacketsSent */
        "movl 0x2e0(%ecx), %edx\n" /* line 277 */
        "movl %edx, -0x464(%ebp)\n" /* iTotalFragmentsSent */
        "movl 0x5c4(%ecx), %esi\n" /* line 279 | iTotalMinRecieved */
        "movl %esi, -0x46c(%ebp)\n" /* iTotalMinRecieved, iTotalBPSRecieved */
        "movl 0x5cc(%ecx), %edi\n" /* line 280 | pStream */
        "movl %edi, -0x460(%ebp)\n" /* pStream, iTotalPacketsRecieved */
        "movl 0x5d0(%ecx), %eax\n" /* line 281 */
        "movl %eax, -0x45c(%ebp)\n" /* iTotalFragmentsRecieved */
        "movl 0x2e8(%ecx), %edx\n" /* line 283 */
        "movl %edx, -0x458(%ebp)\n" /* iTotalMaxSent */
        "xorl %edx, %edx\n"
        "movl -0x458(%ebp), %eax\n" /* iTotalMaxSent */
        "testl %eax, %eax\n"
        "movl -0x458(%ebp), %esi\n" /* iTotalMaxSent, iTotalMinRecieved */
        "cmovlel %edx, %esi\n" /* iTotalMinRecieved */
        "movl %esi, -0x458(%ebp)\n" /* iTotalMinRecieved, iTotalMaxSent */
        "movl 0x2ec(%ecx), %edi\n" /* line 285 | pStream */
        "movl $0x270f, %eax\n"
        "cmpl $0x270f, %edi\n" /* pStream */
        "cmovgel %eax, %edi\n" /* pStream */
        "movl %edi, -0x454(%ebp)\n" /* pStream, iTotalMinSent */
        "movl 0x5d8(%ecx), %esi\n" /* line 287 | iTotalMinRecieved */
        "testl %esi, %esi\n" /* iTotalMinRecieved */
        "cmovgl %esi, %edx\n" /* iTotalMinRecieved */
        "movl %edx, -0x450(%ebp)\n" /* iTotalMaxRecieved */
        "movl 0x5dc(%ecx), %esi\n" /* line 289 | iTotalMinRecieved */
        "cmpl $0x270f, %esi\n" /* iTotalMinRecieved */
        "cmovgel %eax, %esi\n" /* iTotalMinRecieved */
        ".Lf18e798_0018e9f3:\n"
        "movl 0xc(%ebx), %ecx\n" /* line 293 | iFragmentTotal */
        "movl 0x195f290, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf18e798_0018ead7\n"
        "movl $1, %ebx\n" /* iFragmentTotal */
        "leal 1(%eax), %edi\n" /* pStream */
        ".Lf18e798_0018ea10:\n"
        "movl (%ecx), %eax\n" /* line 295 */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018eac6\n"
        "movl 0x765e8(%ecx), %edx\n" /* line 298 */
        "testl %edx, %edx\n"
        "je .Lf18e798_0018eac6\n"
        "movl 0x2d4(%edx), %eax\n" /* line 303 */
        "addl %eax, -0x470(%ebp)\n" /* iTotalBPSSent */
        "movl 0x2dc(%edx), %eax\n" /* line 304 */
        "addl %eax, -0x468(%ebp)\n" /* iTotalPacketsSent */
        "movl 0x2e0(%edx), %eax\n" /* line 305 */
        "addl %eax, -0x464(%ebp)\n" /* iTotalFragmentsSent */
        "movl 0x5c4(%edx), %eax\n" /* line 307 */
        "addl %eax, -0x46c(%ebp)\n" /* iTotalBPSRecieved */
        "movl 0x5cc(%edx), %eax\n" /* line 308 */
        "addl %eax, -0x460(%ebp)\n" /* iTotalPacketsRecieved */
        "movl 0x5d0(%edx), %eax\n" /* line 309 */
        "addl %eax, -0x45c(%ebp)\n" /* iTotalFragmentsRecieved */
        "movl 0x2e8(%edx), %eax\n" /* line 311 */
        "cmpl %eax, -0x458(%ebp)\n" /* iTotalMaxSent */
        "cmovgel -0x458(%ebp), %eax\n" /* iTotalMaxSent */
        "movl %eax, -0x458(%ebp)\n" /* iTotalMaxSent */
        "movl 0x2ec(%edx), %eax\n" /* line 313 */
        "cmpl %eax, -0x454(%ebp)\n" /* iTotalMinSent */
        "cmovlel -0x454(%ebp), %eax\n" /* iTotalMinSent */
        "movl %eax, -0x454(%ebp)\n" /* iTotalMinSent */
        "movl 0x5d8(%edx), %eax\n" /* line 315 */
        "cmpl %eax, -0x450(%ebp)\n" /* iTotalMaxRecieved */
        "cmovgel -0x450(%ebp), %eax\n" /* iTotalMaxRecieved */
        "movl %eax, -0x450(%ebp)\n" /* iTotalMaxRecieved */
        "movl 0x5dc(%edx), %eax\n" /* line 317 */
        "cmpl %eax, %esi\n" /* iTotalMinRecieved */
        "cmovgl %eax, %esi\n" /* iTotalMinRecieved */
        ".Lf18e798_0018eac6:\n"
        "addl $0x78f0c, %ecx\n" /* line 293 */
        "addl $1, %ebx\n" /* iFragmentTotal */
        "cmpl %ebx, %edi\n" /* iFragmentTotal, pStream */
        "jne .Lf18e798_0018ea10\n"
        ".Lf18e798_0018ead7:\n"
        "movl -0x460(%ebp), %edx\n" /* line 322 | iTotalPacketsRecieved */
        "addl -0x468(%ebp), %edx\n" /* iTotalPacketsSent */
        "testl %edx, %edx\n"
        "jle .Lf18e798_0018f20c\n"
        "movl -0x464(%ebp), %eax\n" /* iTotalFragmentsSent */
        "addl -0x45c(%ebp), %eax\n" /* iTotalFragmentsRecieved */
        "testl %eax, %eax\n"
        "jle .Lf18e798_0018f20c\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 323 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "movl %edx, %edi\n" /* pStream */
        "cltd\n"
        "idivl %edi\n" /* pStream */
        "movl %eax, %ebx\n" /* iFragmentTotal */
        ".Lf18e798_0018eb15:\n"
        "cvtsi2ssl %esi, %xmm2\n" /* line 327 | iTotalMinRecieved */
        "cvtsi2ssl -0x454(%ebp), %xmm1\n" /* iTotalMinSent */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 45 */
        "subss %xmm1, %xmm0\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm2, %xmm4\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm4\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm4, %xmm0\n"
        /* } scope */
        "cvtss2sd %xmm0, %xmm4\n" /* line 327 */
        "cvtsi2ssl -0x450(%ebp), %xmm2\n" /* iTotalMaxRecieved */
        "cvtsi2ssl -0x458(%ebp), %xmm1\n" /* iTotalMaxSent */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 45 */
        "subss %xmm2, %xmm0\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm3, %xmm0\n"
        "andps %xmm0, %xmm5\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm5, %xmm0\n"
        /* } scope */
        "cvtss2sd %xmm0, %xmm0\n" /* line 327 */
        "movl -0x470(%ebp), %ecx\n" /* iTotalBPSSent */
        "addl -0x46c(%ebp), %ecx\n" /* iTotalBPSRecieved */
        "movl -0x460(%ebp), %eax\n" /* iTotalPacketsRecieved */
        "testl %eax, %eax\n"
        "jne .Lf18e798_0018f0bb\n"
        "xorl %edi, %edi\n" /* pStream */
        ".Lf18e798_0018eb89:\n"
        "movl -0x468(%ebp), %eax\n" /* iTotalPacketsSent */
        "testl %eax, %eax\n"
        "jne .Lf18e798_0018f0a0\n"
        "xorl %eax, %eax\n"
        ".Lf18e798_0018eb99:\n"
        "movl %ebx, 0x40(%esp)\n" /* iFragmentTotal */
        "movsd %xmm4, 0x38(%esp)\n"
        "movsd %xmm0, 0x30(%esp)\n"
        "movl %ecx, 0x2c(%esp)\n"
        "movl %edi, 0x28(%esp)\n" /* pStream */
        "movl %esi, 0x24(%esp)\n" /* iTotalMinRecieved */
        "movl -0x450(%ebp), %ecx\n" /* iTotalMaxRecieved */
        "movl %ecx, 0x20(%esp)\n"
        "movl -0x46c(%ebp), %esi\n" /* iTotalBPSRecieved, iTotalMinRecieved */
        "movl %esi, 0x1c(%esp)\n" /* iTotalMinRecieved */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x454(%ebp), %edi\n" /* iTotalMinSent, pStream */
        "movl %edi, 0x14(%esp)\n" /* pStream */
        "movl -0x458(%ebp), %eax\n" /* iTotalMaxSent */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x470(%ebp), %edx\n" /* iTotalBPSSent */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x2afea0, 8(%esp)\n" /* "              Totals:%6i|%5i|%5i| %3i%%|%6i|%5i|%5i| %3i%%|%" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %ecx\n" /* szLine */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 328 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018f064\n"
        "leal -0x438(%ebp), %esi\n" /* line 329 | szLine, iTotalMinRecieved */
        "movl %esi, 4(%esp)\n" /* iTotalMinRecieved */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18e798_0018ec2a:\n"
        "movl 0x195f284, %eax\n" /* line 336 */
        "movl 0xa074(%eax), %eax\n"
        "movl %eax, -0x43c(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf18e798_0018f286\n"
        "movl 0x2dc(%eax), %edx\n" /* line 340 */
        "addl 0x5cc(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf18e798_0018f213\n"
        "movl %eax, %ecx\n"
        "movl 0x2e0(%eax), %eax\n"
        "addl 0x5d0(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf18e798_0018f213\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 342 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %edx, %esi\n" /* iTotalMinRecieved */
        "cltd\n"
        "idivl %esi\n" /* iTotalMinRecieved */
        ".Lf18e798_0018ec7b:\n"
        "movl -0x43c(%ebp), %edi\n" /* line 349 | pStream */
        "movl 0x5dc(%edi), %edi\n" /* pStream */
        "movl %edi, -0x440(%ebp)\n" /* pStream */
        "cvtsi2ssl %edi, %xmm1\n" /* pStream */
        "movl -0x43c(%ebp), %edx\n"
        "movl 0x2ec(%edx), %edx\n"
        "movl %edx, -0x444(%ebp)\n"
        "cvtsi2ssl %edx, %xmm0\n"
        /* { scope 2 */
        "movaps %xmm1, %xmm3\n" /* line 45 */
        "subss %xmm0, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm4, %xmm3\n"
        "andps %xmm3, %xmm2\n"
        "andnps %xmm0, %xmm3\n"
        "orps %xmm2, %xmm3\n"
        /* } scope */
        "movl -0x43c(%ebp), %edx\n" /* line 349 */
        "movl 0x5d8(%edx), %ecx\n"
        "cvtsi2ssl %ecx, %xmm2\n"
        "movl 0x2e8(%edx), %esi\n" /* iTotalMinRecieved */
        "cvtsi2ssl %esi, %xmm0\n" /* iTotalMinRecieved */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        /* } scope */
        "movl 0x2d4(%edx), %ebx\n" /* line 349 | iFragmentTotal */
        "movl %edx, %edi\n" /* pStream */
        "movl 0x5c4(%edx), %edx\n"
        "movl %eax, 0x40(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0x38(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0x30(%esp)\n"
        "leal (%ebx, %edx), %eax\n" /* iFragmentTotal */
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x5d4(%edi), %eax\n" /* pStream */
        "movl %eax, 0x28(%esp)\n"
        "movl -0x440(%ebp), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %ecx, 0x20(%esp)\n"
        "movl %edx, 0x1c(%esp)\n"
        "movl 0x2e4(%edi), %eax\n" /* pStream */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x444(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n" /* iTotalMinRecieved */
        "movl %ebx, 0xc(%esp)\n" /* iFragmentTotal */
        "movl $0x2afef0, 8(%esp)\n" /* "  OutOfBand Messages: %5i|%5i|%5i| %3i%%| %5i|%5i|%5i| %3i%%" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %ecx\n" /* szLine */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %edi\n" /* line 350 | bPrintToConsole, pStream */
        "testl %edi, %edi\n" /* pStream */
        "je .Lf18e798_0018f1d0\n"
        "leal -0x438(%ebp), %esi\n" /* line 351 | szLine, iTotalMinRecieved */
        "movl %esi, 4(%esp)\n" /* iTotalMinRecieved */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lf18e798_0018ed99:\n"
        "movl 0x195f284, %eax\n" /* line 369 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x448(%ebp)\n"
        "movl 0x195f290, %edx\n"
        "movl (%edx), %eax\n"
        "movl 8(%eax), %ebx\n" /* iFragmentTotal */
        "testl %ebx, %ebx\n" /* iFragmentTotal */
        "jle .Lf18e798_0018ef9b\n"
        "movl $0, -0x474(%ebp)\n" /* i */
        "jmp .Lf18e798_0018ede8\n"
        ".Lf18e798_0018edc6:\n"
        "addl $1, -0x474(%ebp)\n" /* i */
        "addl $0x78f0c, -0x448(%ebp)\n"
        "movl (%edx), %eax\n"
        "movl -0x474(%ebp), %edi\n" /* i, pStream */
        "cmpl 8(%eax), %edi\n" /* pStream */
        "jge .Lf18e798_0018ef9b\n"
        ".Lf18e798_0018ede8:\n"
        "movl -0x448(%ebp), %eax\n" /* line 371 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf18e798_0018edc6\n"
        "movl $0x11, 8(%esp)\n" /* line 374 */
        "addl $0x20c48, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* szClientName */
        "movl %edx, (%esp)\n"
        "calll strncpy\n"
        "movb $0, -0x28(%ebp)\n" /* line 375 */
        "movl -0x448(%ebp), %ecx\n" /* line 377 */
        "movl 0x765e8(%ecx), %edi\n" /* pStream */
        "testl %edi, %edi\n" /* line 379 | pStream */
        "je .Lf18e798_0018f22b\n"
        "movl 0x2dc(%edi), %edx\n" /* line 381 | pStream */
        "addl 0x5cc(%edi), %edx\n" /* pStream */
        "testl %edx, %edx\n"
        "jle .Lf18e798_0018f1c9\n"
        "movl 0x2e0(%edi), %eax\n" /* pStream */
        "addl 0x5d0(%edi), %eax\n" /* pStream */
        "testl %eax, %eax\n"
        "jle .Lf18e798_0018f1c9\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 383 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %edx, %esi\n" /* iTotalMinRecieved */
        "cltd\n"
        "idivl %esi\n" /* iTotalMinRecieved */
        ".Lf18e798_0018ee5e:\n"
        "movl 0x5dc(%edi), %edx\n" /* line 390 | pStream */
        "movl %edx, -0x478(%ebp)\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "movl 0x2ec(%edi), %ecx\n" /* pStream */
        "movl %ecx, -0x47c(%ebp)\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        /* { scope 2 */
        "movaps %xmm1, %xmm3\n" /* line 45 */
        "subss %xmm0, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm1, %xmm2\n"
        "cmpltss %xmm4, %xmm3\n"
        "andps %xmm3, %xmm2\n"
        "andnps %xmm0, %xmm3\n"
        "orps %xmm2, %xmm3\n"
        /* } scope */
        "movl 0x5d8(%edi), %ecx\n" /* line 390 | pStream */
        "cvtsi2ssl %ecx, %xmm2\n"
        "movl 0x2e8(%edi), %esi\n" /* pStream, iTotalMinRecieved */
        "cvtsi2ssl %esi, %xmm0\n" /* iTotalMinRecieved */
        /* { scope 2 */
        "movaps %xmm0, %xmm1\n" /* line 45 */
        "subss %xmm2, %xmm1\n"
        "movaps %xmm2, %xmm5\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm5\n"
        "andnps %xmm0, %xmm1\n"
        "orps %xmm5, %xmm1\n"
        /* } scope */
        "movl 0x2d4(%edi), %ebx\n" /* line 390 | pStream, iFragmentTotal */
        "movl 0x5c4(%edi), %edx\n" /* pStream */
        "movl %eax, 0x48(%esp)\n"
        "cvtss2sd %xmm3, %xmm3\n"
        "movsd %xmm3, 0x40(%esp)\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0x38(%esp)\n"
        "leal (%ebx, %edx), %eax\n" /* iFragmentTotal */
        "movl %eax, 0x34(%esp)\n"
        "movl 0x5d4(%edi), %eax\n" /* pStream */
        "movl %eax, 0x30(%esp)\n"
        "movl -0x478(%ebp), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl %ecx, 0x28(%esp)\n"
        "movl %edx, 0x24(%esp)\n"
        "movl 0x2e4(%edi), %eax\n" /* pStream */
        "movl %eax, 0x20(%esp)\n"
        "movl -0x47c(%ebp), %edx\n"
        "movl %edx, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n" /* iTotalMinRecieved */
        "movl %ebx, 0x14(%esp)\n" /* iFragmentTotal */
        "leal -0x38(%ebp), %ecx\n" /* szClientName */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x474(%ebp), %esi\n" /* i, iTotalMinRecieved */
        "movl %esi, 0xc(%esp)\n" /* iTotalMinRecieved */
        "movl $0x2affa8, 8(%esp)\n" /* "#%2i-%16s: %5i|%5i|%5i| %3i%%| %5i|%5i|%5i| %3i%%| %5i|%5i|%" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %edi\n" /* szLine, pStream */
        "movl %edi, (%esp)\n" /* pStream */
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 391 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018efe3\n"
        "movl %edi, 4(%esp)\n" /* line 392 | pStream */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl 0x195f290, %edx\n"
        "addl $1, -0x474(%ebp)\n" /* line 369 | i */
        "addl $0x78f0c, -0x448(%ebp)\n"
        "movl (%edx), %eax\n"
        "movl -0x474(%ebp), %edi\n" /* i, pStream */
        "cmpl 8(%eax), %edi\n" /* pStream */
        "jl .Lf18e798_0018ede8\n"
        /* } scope */
        ".Lf18e798_0018ef9b:\n"
        "addl $0x4cc, %esp\n" /* line 409 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf18e798_0018efa6:\n"
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %ecx\n" /* szLine */
        "movl %ecx, 8(%esp)\n"
        "movl $0x5a, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl $0x5a, -0x44c(%ebp)\n" /* iYPos */
        "jmp .Lf18e798_0018e881\n"
        ".Lf18e798_0018efe3:\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 395 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %edx\n" /* szLine */
        "movl %edx, 8(%esp)\n"
        "movl -0x44c(%ebp), %ecx\n" /* iYPos */
        "movl %ecx, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl 0x195f290, %edx\n"
        "jmp .Lf18e798_0018edc6\n"
        ".Lf18e798_0018f025:\n"
        "movl $8, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %eax\n" /* szLine */
        "movl %eax, 8(%esp)\n"
        "movl -0x44c(%ebp), %eax\n" /* iYPos */
        "addl $0xa, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "addl $0x14, -0x44c(%ebp)\n" /* line 247 | iYPos */
        "jmp .Lf18e798_0018e8ba\n"
        ".Lf18e798_0018f064:\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 332 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %edi\n" /* szLine */
        "movl %edi, 8(%esp)\n"
        "movl -0x44c(%ebp), %eax\n" /* iYPos */
        "movl %eax, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18e798_0018ec2a\n"
        ".Lf18e798_0018f0a0:\n"
        "movl -0x464(%ebp), %edx\n" /* line 327 | iTotalFragmentsSent */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "cltd\n"
        "idivl -0x468(%ebp)\n" /* iTotalPacketsSent */
        "jmp .Lf18e798_0018eb99\n"
        ".Lf18e798_0018f0bb:\n"
        "movl -0x45c(%ebp), %edx\n" /* iTotalFragmentsRecieved */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 4), %edx\n"
        "movl %edx, %eax\n"
        "cltd\n"
        "idivl -0x460(%ebp)\n" /* iTotalPacketsRecieved */
        "movl %eax, %edi\n" /* pStream */
        "jmp .Lf18e798_0018eb89\n"
        ".Lf18e798_0018f0de:\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 264 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %ecx\n" /* szLine */
        "movl %ecx, 8(%esp)\n"
        "movl -0x44c(%ebp), %esi\n" /* iYPos */
        "movl %esi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl 0x195f284, %ebx\n" /* line 271 | iFragmentTotal */
        "movl 0xa074(%ebx), %ecx\n" /* iFragmentTotal */
        "testl %ecx, %ecx\n"
        "jne .Lf18e798_0018e94c\n"
        ".Lf18e798_0018f129:\n"
        "movl $0, -0x470(%ebp)\n" /* iTotalBPSSent */
        "movl $0, -0x46c(%ebp)\n" /* iTotalBPSRecieved */
        "movl $0, -0x468(%ebp)\n" /* iTotalPacketsSent */
        "movl $0, -0x464(%ebp)\n" /* iTotalFragmentsSent */
        "movl $0, -0x460(%ebp)\n" /* iTotalPacketsRecieved */
        "movl $0, -0x45c(%ebp)\n" /* iTotalFragmentsRecieved */
        "movl $0, -0x458(%ebp)\n" /* iTotalMaxSent */
        "movl $0x270f, -0x454(%ebp)\n" /* iTotalMinSent */
        "movl $0, -0x450(%ebp)\n" /* iTotalMaxRecieved */
        "movl $0x270f, %esi\n" /* iTotalMinRecieved */
        "jmp .Lf18e798_0018e9f3\n"
        ".Lf18e798_0018f18d:\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 256 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %esi\n" /* szLine */
        "movl %esi, 8(%esp)\n"
        "movl -0x44c(%ebp), %edi\n" /* iYPos */
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18e798_0018e8f9\n"
        ".Lf18e798_0018f1c9:\n"
        "xorl %eax, %eax\n" /* line 381 */
        "jmp .Lf18e798_0018ee5e\n"
        ".Lf18e798_0018f1d0:\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 354 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %edi\n" /* szLine */
        "movl %edi, 8(%esp)\n"
        "movl -0x44c(%ebp), %eax\n" /* iYPos */
        "movl %eax, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18e798_0018ed99\n"
        ".Lf18e798_0018f20c:\n"
        "xorl %ebx, %ebx\n" /* line 322 | iFragmentTotal */
        "jmp .Lf18e798_0018eb15\n"
        ".Lf18e798_0018f213:\n"
        "xorl %eax, %eax\n" /* line 340 */
        "jmp .Lf18e798_0018ec7b\n"
        ".Lf18e798_0018f21a:\n"
        "movl $0x2afc28, (%esp)\n" /* line 231 */
        "calll Com_Printf\n"
        "jmp .Lf18e798_0018e838\n"
        ".Lf18e798_0018f22b:\n"
        "leal -0x38(%ebp), %esi\n" /* line 400 | szClientName, iTotalMinRecieved */
        "movl %esi, 0x10(%esp)\n" /* iTotalMinRecieved */
        "movl -0x474(%ebp), %edi\n" /* i, pStream */
        "movl %edi, 0xc(%esp)\n" /* pStream */
        "movl $0x2afff0, 8(%esp)\n" /* "#%2i-%16s:     0|    0|    0|   0%%|     0|    0|    0|   0%" */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %eax\n" /* szLine */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %eax\n" /* line 401 | bPrintToConsole */
        "testl %eax, %eax\n"
        "je .Lf18e798_0018f2e7\n"
        "leal -0x438(%ebp), %edx\n" /* line 402 | szLine */
        "movl %edx, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl 0x195f290, %edx\n"
        "jmp .Lf18e798_0018edc6\n"
        ".Lf18e798_0018f286:\n"
        "movl $0x2aff44, 8(%esp)\n" /* line 359 */
        "movl $0x400, 4(%esp)\n"
        "leal -0x438(%ebp), %edx\n" /* szLine */
        "movl %edx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 8(%ebp), %esi\n" /* line 360 | bPrintToConsole, iTotalMinRecieved */
        "testl %esi, %esi\n" /* iTotalMinRecieved */
        "jne .Lf18e798_0018f329\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 364 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %esi\n" /* szLine */
        "movl %esi, 8(%esp)\n"
        "movl -0x44c(%ebp), %edi\n" /* iYPos */
        "movl %edi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "jmp .Lf18e798_0018ed99\n"
        ".Lf18e798_0018f2e7:\n"
        "addl $0xa, -0x44c(%ebp)\n" /* line 405 | iYPos */
        "movl $8, 0x10(%esp)\n" /* line 188 */
        "movl $0, 0xc(%esp)\n"
        "leal -0x438(%ebp), %ecx\n" /* szLine */
        "movl %ecx, 8(%esp)\n"
        "movl -0x44c(%ebp), %esi\n" /* iYPos */
        "movl %esi, 4(%esp)\n"
        "movl $0x20, (%esp)\n"
        "calll CL_DrawString\n"
        "movl 0x195f290, %edx\n"
        "jmp .Lf18e798_0018edc6\n"
        ".Lf18e798_0018f329:\n"
        "leal -0x438(%ebp), %ecx\n" /* line 361 | szLine */
        "movl %ecx, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf18e798_0018ed99\n"
    );
}

