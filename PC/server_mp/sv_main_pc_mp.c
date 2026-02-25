/* ASM dump from: sv_main_pc_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/server_mp/sv_main_pc_mp.cpp */

#include "common_types.h"
#include "imports.h"

static int lasttime; /* 0xf31680 */
static netadr_t adr; /* 0xf31684 */

void SV_FlushRedirect(char *outputbuf);
void SVC_RemoteCommand(struct netadr_t from, msg_t *msg);
void SV_MatchEnd(void);
const netadr_t * SV_MasterAddress(void);
void SV_MasterGameCompleteStatus(void);
void SV_MasterHeartbeat(const char *hbname);
void SV_MasterShutdown(void);

/* line 180 */
__attribute__((naked))
void SV_FlushRedirect(char *outputbuf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 180 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x57c, %esp\n"
        "movl 8(%ebp), %edx\n" /* outputbuf */
        /* { scope 1 */
        "cld\n" /* line 187 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %esi\n" /* len */
        "cmpl $0x50e, %esi\n" /* line 188 | len */
        "jg .Lf19195c_001919ed\n"
        ".Lf19195c_00191984:\n"
        "movl %edx, 0xc(%esp)\n" /* line 199 */
        "movl $0x2b01c8, 8(%esp)\n" /* "print
%s" */
        "movl $0x514, 4(%esp)\n"
        "leal -0x544(%ebp), %ebx\n" /* buf */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x195f284, %eax\n" /* line 200 */
        "movl 0xa05c(%eax), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl 0xa060(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0xa064(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        /* } scope */
        "addl $0x57c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19195c_001919ed:\n"
        "movl %edx, %edi\n" /* line 188 */
        ".Lf19195c_001919ef:\n"
        "leal 0x50e(%edi), %eax\n" /* line 180 */
        "movl %eax, -0x54c(%ebp)\n"
        "movzbl 0x50e(%edi), %ebx\n" /* line 190 */
        "movb %bl, -0x559(%ebp)\n" /* c */
        "movb $0, 0x50e(%edi)\n" /* line 191 */
        "movl %edi, 0xc(%esp)\n" /* line 192 */
        "movl $0x2b01c8, 8(%esp)\n" /* "print
%s" */
        "movl $0x514, 4(%esp)\n"
        "leal -0x544(%ebp), %eax\n" /* buf */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x195f284, %ebx\n" /* line 193 */
        "movl 0xa05c(%ebx), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movl 0xa060(%ebx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0xa064(%ebx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "leal -0x544(%ebp), %ebx\n" /* buf */
        "movl %ebx, 0x10(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "subl $0x50e, %esi\n" /* line 194 | len */
        "movzbl -0x559(%ebp), %eax\n" /* line 196 | c */
        "movb %al, 0x50e(%edi)\n"
        "movl -0x54c(%ebp), %edi\n"
        "cmpl $0x50e, %esi\n" /* line 188 | len */
        "jg .Lf19195c_001919ef\n"
        "movl %edi, %edx\n"
        "jmp .Lf19195c_00191984\n"
    );
}

/* line 214 */
__attribute__((naked))
void SVC_RemoteCommand(struct netadr_t from, msg_t *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 214 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x444c, %esp\n"
        "movl 0x10(%ebp), %edi\n"
        "movzbl 0xf(%ebp), %eax\n"
        "movb %al, -0x4429(%ebp)\n"
        "movzbl 0xe(%ebp), %edx\n"
        "movb %dl, -0x442a(%ebp)\n"
        "movzbl 0xd(%ebp), %ecx\n"
        "movb %cl, -0x442b(%ebp)\n"
        "movzbl 0xc(%ebp), %eax\n"
        "movb %al, -0x442c(%ebp)\n"
        "movl 8(%ebp), %esi\n" /* from */
        /* { scope 1 */
        "calll Com_Milliseconds\n" /* line 227 */
        "movl %eax, %edx\n"
        "movl lasttime, %eax\n" /* line 228 */
        "testl %eax, %eax\n"
        "je .Lf191aa0_00191afa\n"
        "movl %edx, %ecx\n"
        "subl %eax, %ecx\n"
        "cmpl $0x1f3, %ecx\n"
        "jle .Lf191aa0_00191c2d\n"
        ".Lf191aa0_00191afa:\n"
        "movl %edx, lasttime\n" /* line 232 */
        "movl $1, (%esp)\n" /* line 234 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, -0x4430(%ebp)\n" /* password */
        "movl 0x195f2f4, %eax\n" /* line 235 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf191aa0_00191c38\n"
        ".Lf191aa0_00191b25:\n"
        "movl $2, (%esp)\n" /* line 238 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %ebx\n" /* len */
        "movw %di, -0x28(%ebp)\n"
        "movzbl -0x4429(%ebp), %edx\n"
        "movb %dl, -0x29(%ebp)\n"
        "movzbl -0x442a(%ebp), %ecx\n"
        "movb %cl, -0x2a(%ebp)\n"
        "movzbl -0x442b(%ebp), %eax\n"
        "movb %al, -0x2b(%ebp)\n"
        "movzbl -0x442c(%ebp), %edx\n"
        "movb %dl, -0x2c(%ebp)\n"
        "movl %esi, -0x30(%ebp)\n" /* i */
        "movl %esi, (%esp)\n" /* i */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %ebx, 8(%esp)\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b01d4, (%esp)\n" /* "Bad rcon from %s:
%s
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* len */
        ".Lf191aa0_00191b8e:\n"
        "movl 0x195f284, %eax\n" /* line 247 */
        "movw %di, 0xa064(%eax)\n"
        "movzbl -0x4429(%ebp), %edx\n"
        "movb %dl, 0xa063(%eax)\n"
        "movzbl -0x442a(%ebp), %ecx\n"
        "movb %cl, 0xa062(%eax)\n"
        "movzbl -0x442b(%ebp), %edx\n"
        "movb %dl, 0xa061(%eax)\n"
        "movzbl -0x442c(%ebp), %ecx\n"
        "movb %cl, 0xa060(%eax)\n"
        "movl %esi, 0xa05c(%eax)\n" /* i */
        "movl $SV_FlushRedirect, 8(%esp)\n" /* line 252 */
        "movl $0x3ff0, 4(%esp)\n"
        "leal -0x4420(%ebp), %eax\n" /* sv_outputbuf */
        "movl %eax, (%esp)\n"
        "calll Com_BeginRedirect\n"
        "movl 0x195f2f4, %eax\n" /* line 254 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf191aa0_00191cc3\n"
        "testl %ebx, %ebx\n" /* line 258 | len */
        "jne .Lf191aa0_00191cef\n"
        "movl -0x4430(%ebp), %eax\n" /* line 260 | password */
        "cmpb $0, (%eax)\n"
        "jne .Lf191aa0_00191cd9\n"
        "movl $0x2b0254, (%esp)\n" /* line 263 */
        "calll Com_Printf\n"
        ".Lf191aa0_00191c28:\n"
        "calll Com_EndRedirect\n" /* line 282 */
        /* } scope */
        ".Lf191aa0_00191c2d:\n"
        "addl $0x444c, %esp\n" /* line 283 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191aa0_00191c38:\n"
        "movl %eax, 4(%esp)\n" /* line 235 */
        "movl -0x4430(%ebp), %eax\n" /* password */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf191aa0_00191b25\n"
        "movl $2, (%esp)\n" /* line 243 */
        "calll SV_Cmd_Argv\n"
        "movl %eax, %ebx\n" /* len */
        "movw %di, -0x1c(%ebp)\n"
        "movzbl -0x4429(%ebp), %ecx\n"
        "movb %cl, -0x1d(%ebp)\n"
        "movzbl -0x442a(%ebp), %eax\n"
        "movb %al, -0x1e(%ebp)\n"
        "movzbl -0x442b(%ebp), %edx\n"
        "movb %dl, -0x1f(%ebp)\n"
        "movzbl -0x442c(%ebp), %ecx\n"
        "movb %cl, -0x20(%ebp)\n"
        "movl %esi, -0x24(%ebp)\n" /* i */
        "movl %esi, (%esp)\n" /* i */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "calll NET_AdrToString\n"
        "movl %ebx, 8(%esp)\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b01ec, (%esp)\n" /* "Rcon from %s:
%s
" */
        "calll Com_Printf\n"
        "movl $1, %ebx\n" /* len */
        "jmp .Lf191aa0_00191b8e\n"
        ".Lf191aa0_00191cc3:\n"
        "movl $0x2b0200, (%esp)\n" /* line 256 */
        "calll Com_Printf\n"
        "calll Com_EndRedirect\n" /* line 282 */
        "jmp .Lf191aa0_00191c2d\n"
        ".Lf191aa0_00191cd9:\n"
        "movl $0x2b0240, (%esp)\n" /* line 261 */
        "calll Com_Printf\n"
        "calll Com_EndRedirect\n" /* line 282 */
        "jmp .Lf191aa0_00191c2d\n"
        ".Lf191aa0_00191cef:\n"
        "xorl %ebx, %ebx\n" /* line 258 | len */
        "movl $2, %esi\n" /* i */
        "jmp .Lf191aa0_00191d4f\n"
        ".Lf191aa0_00191cf8:\n"
        "movl %esi, (%esp)\n" /* line 272 | i */
        "calll SV_Cmd_Argv\n"
        "movl $1, 0x10(%esp)\n"
        "movl $0x400, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* len */
        "leal -0x430(%ebp), %ebx\n" /* remaining, len */
        "movl %ebx, 4(%esp)\n" /* len */
        "movl %eax, (%esp)\n"
        "calll Com_AddToString\n"
        "movl $0, 0x10(%esp)\n" /* line 273 */
        "movl $0x400, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* len */
        "movl $0x217914, (%esp)\n" /* " " */
        "calll Com_AddToString\n"
        "movl %eax, %ebx\n" /* len */
        "addl $1, %esi\n" /* line 270 | i */
        ".Lf191aa0_00191d4f:\n"
        "calll SV_Cmd_Argc\n"
        "cmpl %eax, %esi\n" /* i */
        "jl .Lf191aa0_00191cf8\n"
        "cmpl $0x3ff, %ebx\n" /* line 275 | len */
        "jg .Lf191aa0_00191c28\n"
        "movb $0, -0x430(%ebp, %ebx)\n" /* line 277 */
        "leal -0x430(%ebp), %eax\n" /* line 278 | remaining */
        "movl %eax, (%esp)\n"
        "calll SV_Cmd_ExecuteString\n"
        "calll Com_EndRedirect\n" /* line 282 */
        "jmp .Lf191aa0_00191c2d\n"
    );
}

/* line 287 */
__attribute__((naked))
void SV_MatchEnd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 289 */
        "retl\n"
    );
}

/* line 32 */
__attribute__((naked))
const netadr_t * SV_MasterAddress(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "movl adr, %eax\n" /* line 38 */
        "testl %eax, %eax\n"
        "je .Lf191d8a_00191da0\n"
        /* } scope */
        "movl $adr, %eax\n" /* line 56 */
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191d8a_00191da0:\n"
        "movl $0x2a9298, 4(%esp)\n" /* line 40 */
        "movl $0x2a92b4, (%esp)\n" /* "Resolving %s
" */
        "calll Com_Printf\n"
        "movl $adr, 4(%esp)\n" /* line 41 */
        "movl $0x2a9298, (%esp)\n" /* "cod2master.activision.com" */
        "calll NET_StringToAdr\n"
        "testl %eax, %eax\n"
        "jne .Lf191d8a_00191ddf\n"
        "movl $0x2b0298, (%esp)\n" /* line 44 */
        "calll Com_Printf\n"
        /* } scope */
        "movl $adr, %eax\n" /* line 56 */
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191d8a_00191ddf:\n"
        "movw $0xe650, 0xf3168c\n" /* line 49 */
        "movl $0x50e6, 0x14(%esp)\n" /* line 50 */
        "movzbl 0xf3168b, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movzbl 0xf3168a, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movzbl 0xf31689, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl 0xf31688, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b02d0, (%esp)\n" /* "cod2master.activision.com resolved to %i.%i.%i.%i:%i
" */
        "calll Com_Printf\n"
        /* } scope */
        "movl $adr, %eax\n" /* line 56 */
        "leave\n"
        "retl\n"
    );
}

/* line 124 */
__attribute__((naked))
void SV_MasterGameCompleteStatus(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl 0x195ec98, %eax\n" /* line 129 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf191e30_00191e48\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf191e30_00191e4e\n"
        /* } scope */
        ".Lf191e30_00191e48:\n"
        "addl $0x24, %esp\n" /* line 144 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191e30_00191e4e:\n"
        "calll SV_MasterAddress\n" /* line 135 */
        "movl %eax, %ebx\n" /* adr */
        "cmpl $1, (%eax)\n" /* line 137 */
        "je .Lf191e30_00191e48\n"
        "movl $0x2b0308, (%esp)\n" /* line 139 */
        "calll Com_Printf\n"
        "movl (%ebx), %ecx\n" /* line 142 | adr */
        "movl %ecx, -0x14(%ebp)\n"
        "movl 4(%ebx), %edx\n" /* adr */
        "movl %edx, -0x10(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* adr */
        "movl %eax, -0xc(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll SVC_GameCompleteStatus\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 144 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 74 */
__attribute__((naked))
void SV_MasterHeartbeat(const char *hbname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0x195ec98, %eax\n" /* line 84 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf191e8e_00191ea8\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf191e8e_00191eb0\n"
        /* } scope */
        ".Lf191e8e_00191ea8:\n"
        "addl $0x4c, %esp\n" /* line 114 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191e8e_00191eb0:\n"
        "movl 0x195f284, %esi\n" /* line 90 */
        "movl 4(%esi), %eax\n"
        "cmpl 0x54(%esi), %eax\n"
        "jge .Lf191e8e_00191efe\n"
        ".Lf191e8e_00191ebe:\n"
        "cmpl 0x58(%esi), %eax\n" /* line 105 */
        "jl .Lf191e8e_00191ea8\n"
        "addl $0x927c0, %eax\n" /* line 107 */
        "movl %eax, 0x58(%esi)\n"
        "calll SV_MasterAddress\n" /* line 109 */
        "cmpl $1, (%eax)\n" /* line 111 */
        "je .Lf191e8e_00191ea8\n"
        "movl (%eax), %ecx\n" /* line 112 */
        "movl %ecx, -0x24(%ebp)\n"
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll SVC_Status\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 114 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf191e8e_00191efe:\n"
        "addl $0x2bf20, %eax\n" /* line 92 */
        "movl %eax, 0x54(%esi)\n"
        "calll SV_MasterAddress\n" /* line 94 */
        "movl %eax, %edi\n"
        "cmpl $1, (%eax)\n" /* line 96 */
        "je .Lf191e8e_00191f66\n"
        "movl $0x2b0344, (%esp)\n" /* line 98 */
        "calll Com_Printf\n"
        "movl 8(%ebp), %eax\n" /* line 101 | hbname */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b0374, (%esp)\n" /* "heartbeat %s
" */
        "calll va\n"
        "movl (%edi), %ebx\n"
        "movl %ebx, -0x30(%ebp)\n"
        "movl 4(%edi), %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl 8(%edi), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_OutOfBandPrint\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf191e8e_00191ebe\n"
        ".Lf191e8e_00191f66:\n"
        "movl 4(%esi), %eax\n"
        "jmp .Lf191e8e_00191ebe\n"
    );
}

/* line 154 */
__attribute__((naked))
void SV_MasterShutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 154 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f284, %eax\n" /* line 157 */
        "movl $0x80000000, 0x54(%eax)\n"
        "movl $0x2b0384, (%esp)\n" /* line 158 */
        "calll SV_MasterHeartbeat\n"
        "leave\n" /* line 166 */
        "retl\n"
    );
}

