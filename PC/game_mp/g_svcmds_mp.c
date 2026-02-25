/* ASM dump from: g_svcmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/game_mp/g_svcmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

static ipFilter_t ipFilters[1024]; /* 0xfe8120 */
static int numIPFilters; /* 0xfe8100 */

void Svcmd_RemoveIP_f(void);
void Svcmd_EntityList_f(void);
static void AddIP(void);
void G_ProcessIPBans(void);
qboolean ConsoleCommand(void);

/* line 217 */
__attribute__((naked))
void Svcmd_RemoveIP_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 217 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x84c, %esp\n"
        /* { scope 1 */
        "calll SV_Cmd_Argc\n" /* line 223 */
        "subl $1, %eax\n"
        "jle .Lf1c89b4_001c8b7d\n"
        "movl $0x400, 8(%esp)\n" /* line 229 */
        "leal -0x420(%ebp), %eax\n" /* str */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl $1, %eax\n"
        /* { scope 2: num, b, m */
        /* { scope 3 */
        ".Lf1c89b4_001c89f1:\n"
        "movb $0, -0x1d(%eax, %ebp)\n" /* line 73 */
        "movb $0, -0x21(%eax, %ebp)\n" /* line 74 */
        "addl $1, %eax\n"
        "cmpl $5, %eax\n" /* line 71 */
        "jne .Lf1c89b4_001c89f1\n"
        "leal -0x420(%ebp), %edi\n" /* str */
        "movl $1, %ebx\n"
        "leal -0x820(%ebp), %esi\n" /* num */
        ".Lf1c89b4_001c8a14:\n"
        "movzbl (%edi), %edx\n" /* line 79 */
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "ja .Lf1c89b4_001c8b94\n"
        "xorl %ecx, %ecx\n" /* line 81 */
        ".Lf1c89b4_001c8a24:\n"
        "movb %dl, (%ecx, %esi)\n" /* line 88 */
        "addl $1, %ecx\n"
        "movzbl (%ecx, %edi), %edx\n" /* line 86 */
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "jbe .Lf1c89b4_001c8a24\n"
        "leal (%ecx, %edi), %edi\n"
        "movb $0, -0x820(%ebp, %ecx)\n" /* line 90 */
        "movl %esi, (%esp)\n" /* line 91 */
        "calll atoi\n"
        "movb %al, -0x1d(%ebx, %ebp)\n"
        "testb %al, %al\n" /* line 92 */
        "je .Lf1c89b4_001c8a55\n"
        "movb $0xff, -0x21(%ebx, %ebp)\n" /* line 93 */
        ".Lf1c89b4_001c8a55:\n"
        "cmpb $0, (%edi)\n" /* line 95 */
        "je .Lf1c89b4_001c8a65\n"
        "addl $1, %edi\n" /* line 97 */
        "addl $1, %ebx\n"
        "cmpl $5, %ebx\n" /* line 77 */
        "jne .Lf1c89b4_001c8a14\n"
        ".Lf1c89b4_001c8a65:\n"
        "movl -0x20(%ebp), %ebx\n" /* line 100 | m */
        "movl -0x1c(%ebp), %edi\n" /* line 101 | b */
        /* } scope */
        /* } scope */
        "movl numIPFilters, %ecx\n" /* line 234 */
        "testl %ecx, %ecx\n"
        "jle .Lf1c89b4_001c8b5c\n"
        "xorl %edx, %edx\n"
        "movl $ipFilters, %eax\n"
        "jmp .Lf1c89b4_001c8a90\n"
        ".Lf1c89b4_001c8a82:\n"
        "addl $1, %edx\n"
        "addl $8, %eax\n"
        "cmpl %ecx, %edx\n"
        "je .Lf1c89b4_001c8b5c\n"
        ".Lf1c89b4_001c8a90:\n"
        "cmpl %ebx, (%eax)\n" /* line 236 */
        "jne .Lf1c89b4_001c8a82\n"
        "cmpl %edi, 4(%eax)\n" /* s */
        "jne .Lf1c89b4_001c8a82\n"
        "movl $ipFilters, %eax\n" /* line 238 */
        "movl $0xffffffff, 4(%eax, %edx, 8)\n"
        "movl $0x2b6a3c, (%esp)\n" /* line 239 */
        "calll Com_Printf\n"
        "movb $0, -0x820(%ebp)\n" /* line 118 | num */
        "movl numIPFilters, %eax\n" /* line 119 */
        "testl %eax, %eax\n"
        "jle .Lf1c89b4_001c8b47\n"
        "movl $0, -0x82c(%ebp)\n"
        "movl $ipFilters, %ebx\n"
        ".Lf1c89b4_001c8ad5:\n"
        "movl 4(%ebx), %eax\n" /* line 121 */
        "cmpl $-1, %eax\n"
        "je .Lf1c89b4_001c8b2f\n"
        "movl %eax, -0x20(%ebp)\n" /* line 124 | m */
        "cld\n" /* line 125 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movzbl -0x1d(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movzbl -0x1e(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x1f(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x20(%ebp), %eax\n" /* m */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2b6a48, 8(%esp)\n" /* "%i.%i.%i.%i " */
        "movl $0x400, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%esi, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf1c89b4_001c8b2f:\n"
        "addl $1, -0x82c(%ebp)\n" /* line 119 */
        "addl $8, %ebx\n"
        "movl -0x82c(%ebp), %eax\n"
        "cmpl numIPFilters, %eax\n"
        "jl .Lf1c89b4_001c8ad5\n"
        ".Lf1c89b4_001c8b47:\n"
        "movl %esi, 4(%esp)\n" /* line 128 */
        "movl 0x195f76c, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf1c89b4_001c8b72\n"
        ".Lf1c89b4_001c8b5c:\n"
        "leal -0x420(%ebp), %eax\n" /* line 246 | str */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b6a58, (%esp)\n" /* "Didn't find %s.
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1c89b4_001c8b72:\n"
        "addl $0x84c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c89b4_001c8b7d:\n"
        "movl $0x2b6a04, (%esp)\n" /* line 225 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x84c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: num, b, m */
        /* { scope 3 */
        ".Lf1c89b4_001c8b94:\n"
        "movl %edi, 4(%esp)\n" /* line 81 */
        "movl $0x2b6a24, (%esp)\n" /* "Bad filter address: %s
" */
        "calll Com_Printf\n"
        "jmp .Lf1c89b4_001c8b72\n"
    );
}

/* line 255 */
__attribute__((naked))
void Svcmd_EntityList_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 255 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195f6a0, %eax\n" /* line 261 */
        "cmpl $1, 0xc(%eax)\n"
        "jle .Lf1c8ba6_001c8c3d\n"
        "movl $1, %esi\n" /* e */
        "movl 0x195f688, %ebx\n"
        "addl $0x32c, %ebx\n"
        "jmp .Lf1c8ba6_001c8bde\n"
        ".Lf1c8ba6_001c8bd0:\n"
        "addl $1, %esi\n" /* e */
        "addl $0x230, %ebx\n"
        "cmpl %esi, 0xc(%eax)\n" /* e */
        "jle .Lf1c8ba6_001c8c3d\n"
        ".Lf1c8ba6_001c8bde:\n"
        "cmpb $0, (%ebx)\n" /* line 263 */
        "je .Lf1c8ba6_001c8bd0\n"
        "movl %esi, 4(%esp)\n" /* line 267 | e */
        "movl $0x2b6a6c, (%esp)\n" /* "%3i:" */
        "calll Com_Printf\n"
        "movl -0xf8(%ebx), %eax\n" /* line 268 */
        "cmpl $6, %eax\n"
        "ja .Lf1c8ba6_001c8c05\n"
        "jmpl *0x303380(, %eax, 4)\n"
        ".Lf1c8ba6_001c8c05:\n"
        "movl %eax, 4(%esp)\n" /* line 289 */
        "movl $0x2b6b04, (%esp)\n" /* "%3i                 " */
        "calll Com_Printf\n"
        ".Lf1c8ba6_001c8c15:\n"
        "movzwl 0x6c(%ebx), %eax\n" /* line 293 */
        "testw %ax, %ax\n"
        "jne .Lf1c8ba6_001c8c44\n"
        ".Lf1c8ba6_001c8c1e:\n"
        "movl $0x2160e8, (%esp)\n" /* line 297 */
        "calll Com_Printf\n"
        "movl 0x195f6a0, %eax\n"
        "addl $1, %esi\n" /* line 261 | e */
        "addl $0x230, %ebx\n"
        "cmpl %esi, 0xc(%eax)\n" /* e */
        "jg .Lf1c8ba6_001c8bde\n"
        /* } scope */
        ".Lf1c8ba6_001c8c3d:\n"
        "addl $0x10, %esp\n" /* line 299 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c8ba6_001c8c44:\n"
        "movzwl %ax, %eax\n" /* line 295 */
        "movl %eax, (%esp)\n"
        "calll SL_ConvertToString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c1e\n"
        "movl $0x2b6a74, (%esp)\n" /* line 271 */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c15\n"
        "movl $0x2b6aec, (%esp)\n" /* line 286 */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c15\n"
        "movl $0x2b6ad4, (%esp)\n" /* line 283 */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c15\n"
        "movl $0x2b6abc, (%esp)\n" /* line 280 */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c15\n"
        "movl $0x2b6aa4, (%esp)\n" /* line 277 */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c15\n"
        "movl $0x2b6a8c, (%esp)\n" /* line 274 */
        "calll Com_Printf\n"
        "jmp .Lf1c8ba6_001c8c15\n"
    );
}

/* line 137 */
static __attribute__((naked))
void AddIP(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 137 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        "movl %eax, %edi\n" /* str */
        /* { scope 1: f */
        "movl numIPFilters, %ecx\n" /* line 141 */
        "testl %ecx, %ecx\n"
        "jle .Lf1c8cbe_001c8d14\n"
        "cmpl $-1, 0xfe8124\n" /* line 142 */
        "je .Lf1c8cbe_001c8d14\n"
        "movl $0, -0x434(%ebp)\n" /* line 143 | i */
        "movl $ipFilters, %edx\n"
        ".Lf1c8cbe_001c8cee:\n"
        "addl $1, -0x434(%ebp)\n" /* line 141 | i */
        "cmpl %ecx, -0x434(%ebp)\n" /* i */
        "je .Lf1c8cbe_001c8e86\n"
        "movl 0xc(%edx), %eax\n" /* line 142 */
        "addl $8, %edx\n"
        "addl $1, %eax\n"
        "jne .Lf1c8cbe_001c8cee\n"
        "movl -0x434(%ebp), %edx\n" /* i */
        "jmp .Lf1c8cbe_001c8d2c\n"
        ".Lf1c8cbe_001c8d14:\n"
        "testl %ecx, %ecx\n" /* line 144 */
        "je .Lf1c8cbe_001c8e71\n"
        "movl $0, -0x434(%ebp)\n" /* i */
        "movl -0x434(%ebp), %edx\n" /* i */
        ".Lf1c8cbe_001c8d2c:\n"
        "leal ipFilters(, %edx, 8), %edx\n" /* line 154 */
        "movl %edx, -0x430(%ebp)\n" /* f */
        "movl $1, %eax\n"
        /* { scope 2: num, b, m */
        /* { scope 3 */
        ".Lf1c8cbe_001c8d3e:\n"
        "movb $0, -0x1d(%eax, %ebp)\n" /* line 73 */
        "movb $0, -0x21(%eax, %ebp)\n" /* line 74 */
        "addl $1, %eax\n"
        "cmpl $5, %eax\n" /* line 71 */
        "jne .Lf1c8cbe_001c8d3e\n"
        "movl $1, %esi\n"
        "leal -0x420(%ebp), %ebx\n" /* num */
        ".Lf1c8cbe_001c8d5b:\n"
        "movzbl (%edi), %edx\n" /* line 79 */
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "ja .Lf1c8cbe_001c8e9c\n"
        /* } scope */
        /* } scope */
        "xorl %ecx, %ecx\n" /* line 155 */
        /* { scope 2: num, b, m */
        /* { scope 3 */
        ".Lf1c8cbe_001c8d6b:\n"
        "movb %dl, (%ecx, %ebx)\n" /* line 88 */
        "addl $1, %ecx\n"
        "movzbl (%ecx, %edi), %edx\n" /* line 86 */
        "leal -0x30(%edx), %eax\n"
        "cmpb $9, %al\n"
        "jbe .Lf1c8cbe_001c8d6b\n"
        "leal (%ecx, %edi), %edi\n"
        "movb $0, -0x420(%ebp, %ecx)\n" /* line 90 */
        "movl %ebx, (%esp)\n" /* line 91 */
        "calll atoi\n"
        "movb %al, -0x1d(%esi, %ebp)\n"
        "testb %al, %al\n" /* line 92 */
        "je .Lf1c8cbe_001c8d9c\n"
        "movb $0xff, -0x21(%esi, %ebp)\n" /* line 93 */
        ".Lf1c8cbe_001c8d9c:\n"
        "cmpb $0, (%edi)\n" /* line 95 */
        "je .Lf1c8cbe_001c8dac\n"
        "addl $1, %edi\n" /* line 97 */
        "addl $1, %esi\n"
        "cmpl $5, %esi\n" /* line 77 */
        "jne .Lf1c8cbe_001c8d5b\n"
        ".Lf1c8cbe_001c8dac:\n"
        "movl -0x20(%ebp), %eax\n" /* line 100 | m */
        "movl -0x430(%ebp), %edx\n" /* f */
        "movl %eax, (%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 101 | b */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lf1c8cbe_001c8dbd:\n"
        "movb $0, -0x420(%ebp)\n" /* line 118 | num */
        "movl numIPFilters, %esi\n" /* line 119 */
        "testl %esi, %esi\n"
        "jle .Lf1c8cbe_001c8e53\n"
        "movl $0, -0x42c(%ebp)\n"
        "movl $ipFilters, %esi\n"
        ".Lf1c8cbe_001c8de1:\n"
        "movl 4(%esi), %eax\n" /* line 121 */
        "cmpl $-1, %eax\n"
        "je .Lf1c8cbe_001c8e3b\n"
        "movl %eax, -0x20(%ebp)\n" /* line 124 | m */
        "cld\n" /* line 125 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movzbl -0x1d(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movzbl -0x1e(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movzbl -0x1f(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl -0x20(%ebp), %eax\n" /* m */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2b6a48, 8(%esp)\n" /* "%i.%i.%i.%i " */
        "movl $0x400, %eax\n"
        "subl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%ebx, %ecx), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf1c8cbe_001c8e3b:\n"
        "addl $1, -0x42c(%ebp)\n" /* line 119 */
        "addl $8, %esi\n"
        "movl -0x42c(%ebp), %edx\n"
        "cmpl numIPFilters, %edx\n"
        "jl .Lf1c8cbe_001c8de1\n"
        ".Lf1c8cbe_001c8e53:\n"
        "movl %ebx, 4(%esp)\n" /* line 128 */
        "movl 0x195f76c, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        /* } scope */
        ".Lf1c8cbe_001c8e66:\n"
        "addl $0x44c, %esp\n" /* line 158 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: f */
        ".Lf1c8cbe_001c8e71:\n"
        "leal 1(%ecx), %eax\n" /* line 151 */
        "movl %eax, numIPFilters\n"
        "movl %ecx, -0x434(%ebp)\n" /* i */
        "movl %ecx, %edx\n"
        "jmp .Lf1c8cbe_001c8d2c\n"
        ".Lf1c8cbe_001c8e86:\n"
        "cmpl $0x400, %ecx\n" /* line 146 */
        "jne .Lf1c8cbe_001c8e71\n"
        "movl $0x2b6b1c, (%esp)\n" /* line 148 */
        "calll Com_Printf\n"
        "jmp .Lf1c8cbe_001c8e66\n"
        /* { scope 2: num, b, m */
        /* { scope 3 */
        ".Lf1c8cbe_001c8e9c:\n"
        "movl %edi, 4(%esp)\n" /* line 81 */
        "movl $0x2b6a24, (%esp)\n" /* "Bad filter address: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "movl -0x434(%ebp), %eax\n" /* line 155 | i */
        "movl $0xffffffff, 0xfe8124(, %eax, 8)\n"
        "jmp .Lf1c8cbe_001c8dbd\n"
    );
}

/* line 166 */
__attribute__((naked))
void G_ProcessIPBans(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        /* { scope 1 */
        "movl $0, numIPFilters\n" /* line 172 */
        "movl $0x400, 8(%esp)\n" /* line 174 */
        "movl 0x195f76c, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x408(%ebp), %ebx\n" /* str, s */
        "movl %ebx, (%esp)\n" /* s */
        "calll I_strncpyz\n"
        "movl %ebx, %esi\n" /* s, t */
        "cmpb $0, (%esi)\n" /* line 176 | t */
        "je .Lf1c8ec2_001c8f2b\n"
        ".Lf1c8ec2_001c8f02:\n"
        "movl $0x20, 4(%esp)\n" /* line 178 */
        "movl %ebx, (%esp)\n" /* s */
        "calll strchr\n"
        "movl %eax, %ebx\n" /* s */
        "testl %eax, %eax\n" /* line 179 */
        "je .Lf1c8ec2_001c8f2b\n"
        "cmpb $0x20, (%eax)\n" /* line 181 */
        "je .Lf1c8ec2_001c8f35\n"
        ".Lf1c8ec2_001c8f1d:\n"
        "movl %esi, %eax\n" /* line 184 | t */
        "calll AddIP\n"
        "movl %ebx, %esi\n" /* s, t */
        ".Lf1c8ec2_001c8f26:\n"
        "cmpb $0, (%esi)\n" /* line 176 | t */
        "jne .Lf1c8ec2_001c8f02\n"
        /* } scope */
        ".Lf1c8ec2_001c8f2b:\n"
        "addl $0x410, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c8ec2_001c8f35:\n"
        "movb $0, (%ebx)\n" /* line 182 | s */
        "addl $1, %ebx\n" /* s */
        "cmpb $0x20, (%ebx)\n" /* line 181 | s */
        "je .Lf1c8ec2_001c8f35\n"
        "cmpb $0, (%esi)\n" /* line 183 | t */
        "jne .Lf1c8ec2_001c8f1d\n"
        "movl %ebx, %esi\n" /* line 184 | s, t */
        "jmp .Lf1c8ec2_001c8f26\n"
    );
}

/* line 355 */
__attribute__((naked))
qboolean ConsoleCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 355 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x814, %esp\n"
        /* { scope 1 */
        "movl $0x400, 8(%esp)\n" /* line 359 */
        "leal -0x408(%ebp), %ebx\n" /* cmd */
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl $0x2b6b50, 4(%esp)\n" /* line 361 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c8f4a_001c8f99\n"
        "calll Svcmd_EntityList_f\n" /* line 363 */
        "movl $1, %eax\n"
        /* } scope */
        ".Lf1c8f4a_001c8f90:\n"
        "addl $0x814, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c8f4a_001c8f99:\n"
        "movl $0x2b6b5c, 4(%esp)\n" /* line 367 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1c8f4a_001c8feb\n"
        "movl $0x2b6b64, 4(%esp)\n" /* line 373 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1c8f4a_001c9028\n"
        "movl $0x2b6b70, 4(%esp)\n" /* line 379 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1c8f4a_001c90ab\n"
        "movl 0x195f704, %eax\n" /* line 385 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1c8f4a_001c9051\n"
        ".Lf1c8f4a_001c8fe7:\n"
        "xorl %eax, %eax\n" /* line 390 */
        "jmp .Lf1c8f4a_001c8f90\n"
        ".Lf1c8f4a_001c8feb:\n"
        "calll SV_Cmd_Argc\n" /* line 199 */
        "subl $1, %eax\n"
        "jle .Lf1c8f4a_001c903b\n"
        "movl $0x400, 8(%esp)\n" /* line 205 */
        "leal -0x808(%ebp), %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll SV_Cmd_ArgvBuffer\n"
        "movl %ebx, %eax\n" /* line 207 */
        "calll AddIP\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x814, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c8f4a_001c9028:\n"
        "calll Svcmd_RemoveIP_f\n" /* line 375 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x814, %esp\n" /* line 395 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1c8f4a_001c903b:\n"
        "movl $0x2b6b34, (%esp)\n" /* line 201 */
        "calll Com_Printf\n"
        "movl $1, %eax\n"
        "jmp .Lf1c8f4a_001c8f90\n"
        ".Lf1c8f4a_001c9051:\n"
        "movl $0x2ac704, 4(%esp)\n" /* line 387 */
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1c8f4a_001c8fe7\n"
        "movl $1, (%esp)\n" /* line 389 */
        "calll ConcatArgs\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x65, 4(%esp)\n"
        "movl $0x2b6b84, (%esp)\n" /* "%c "GAME_SERVER: %s"" */
        "calll va\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xffffffff, (%esp)\n"
        "calll SV_GameSendServerCommand\n"
        "movl $1, %eax\n"
        "jmp .Lf1c8f4a_001c8f90\n"
        ".Lf1c8f4a_001c90ab:\n"
        "movl $0x2b6b78, 4(%esp)\n" /* line 381 */
        "movl $1, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $1, %eax\n"
        "jmp .Lf1c8f4a_001c8f90\n"
    );
}

