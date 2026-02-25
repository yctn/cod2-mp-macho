/* ASM dump from: cg_consolecmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_consolecmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

static const consoleCommand_t commandsList[21]; /* 0x333bc0 */

void CG_TargetCommand_f(void);
static void CG_SizeUp_f(void);
static void CG_SizeDown_f(void);
static void CG_Viewpos_f(void);
void CG_ScoresUp_f(void);
void CG_ScoresDown_f(void);
static void CG_ShellShock_f(void);
static void CG_ShellShock_Load_f(void);
static void CG_ShellShock_Save_f(void);
static void CG_TellTarget_f(void);
static void CG_QuickMessage_f(void);
static void CG_VoiceChat_f(void);
static void CG_TeamVoiceChat_f(void);
qboolean CG_ConsoleCommand(void);
void CG_InitConsoleCommands(void);

/* line 17 */
__attribute__((naked))
void CG_TargetCommand_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 17 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "calll CG_CrosshairPlayer\n" /* line 22 */
        "movl %eax, %esi\n" /* targetNum */
        "testl %eax, %eax\n" /* line 23 */
        "je .Lf1d07ac_001d07fe\n"
        "movl $4, 8(%esp)\n" /* line 28 */
        "leal -0xc(%ebp), %ebx\n" /* test */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 29 */
        "calll atoi\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* targetNum */
        "movl $0x2b73ac, (%esp)\n" /* "gc %i %i" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        /* } scope */
        ".Lf1d07ac_001d07fe:\n"
        "addl $0x20, %esp\n" /* line 30 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 40 */
static __attribute__((naked))
void CG_SizeUp_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 40 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f84c, %eax\n" /* line 42 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "addl $0xa, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "leave\n" /* line 43 */
        "retl\n"
    );
}

/* line 53 */
static __attribute__((naked))
void CG_SizeDown_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 53 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f84c, %eax\n" /* line 55 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "subl $0xa, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "leave\n" /* line 56 */
        "retl\n"
    );
}

/* line 66 */
static __attribute__((naked))
void CG_Viewpos_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 66 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0x195f584, %eax\n" /* line 68 */
        "movl (%eax), %edx\n"
        "cvttss2si 0x285cc(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si 0x28590(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si 0x2858c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvttss2si 0x28588(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b73b8, (%esp)\n" /* "(%i %i %i) : %i
" */
        "calll Com_Printf\n"
        "leave\n" /* line 69 */
        "retl\n"
    );
}

/* line 77 */
__attribute__((naked))
void CG_ScoresUp_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll CG_ScoreboardDisplayed\n" /* line 79 */
        "testl %eax, %eax\n"
        "je .Lf1d0896_001d08c2\n"
        "movl 0x195f584, %eax\n" /* line 82 */
        "movl (%eax), %eax\n"
        "movl $0, 0x2b534(%eax)\n"
        "movl 0x25bb0(%eax), %edx\n" /* line 84 */
        "movl %edx, 0x2b538(%eax)\n"
        ".Lf1d0896_001d08c2:\n"
        "leave\n" /* line 86 */
        "retl\n"
    );
}

/* line 95 */
__attribute__((naked))
void CG_ScoresDown_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195f584, %eax\n" /* line 97 */
        "movl (%eax), %ebx\n"
        "movl 0x25bb0(%ebx), %edx\n"
        "movl 0x2aefc(%ebx), %eax\n"
        "addl $0x7d0, %eax\n"
        "cmpl %edx, %eax\n"
        "jl .Lf1d08c4_001d08f7\n"
        "movl $1, 0x2b534(%ebx)\n" /* line 123 */
        ".Lf1d08c4_001d08f1:\n"
        "addl $0x14, %esp\n" /* line 126 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d08c4_001d08f7:\n"
        "movl %edx, 0x2aefc(%ebx)\n" /* line 101 */
        "movl $0x2b3bec, (%esp)\n" /* line 102 */
        "calll CL_AddReliableCommand\n"
        "calll CG_ScoreboardDisplayed\n" /* line 106 */
        "testl %eax, %eax\n"
        "jne .Lf1d08c4_001d08f1\n"
        "movl $0, 0x2af00(%ebx)\n" /* line 108 */
        "movl $0, 0x2b53c(%ebx)\n" /* line 109 */
        "movl $1, 0x2b534(%ebx)\n" /* line 111 */
        "addl $0x14, %esp\n" /* line 126 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 153 */
static __attribute__((naked))
void CG_ShellShock_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x124, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 158 */
        "cmpl $2, %eax\n"
        "je .Lf1d0936_001d0968\n"
        "cmpl $3, %eax\n"
        "je .Lf1d0936_001d09fa\n"
        "movl $0x2b73cc, (%esp)\n" /* line 170 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf1d0936_001d095f:\n"
        "addl $0x124, %esp\n" /* line 177 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d0936_001d0968:\n"
        "leal -0x108(%ebp), %ebx\n" /* arg */
        /* { scope 1 */
        ".Lf1d0936_001d096e:\n"
        "movl $0x100, 8(%esp)\n" /* line 166 */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 167 */
        "calll atof\n"
        "fstpl -0x110(%ebp)\n"
        "movl 0x195f5c4, %eax\n" /* line 174 */
        "movl (%eax), %eax\n"
        "addl $0x68c4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_SetShellShockParmsFromDvars\n"
        "movl 0x195f584, %eax\n" /* line 175 */
        "movl (%eax), %ebx\n"
        "movl 0x25bb0(%ebx), %eax\n"
        "movl %eax, 0x2ccf8(%ebx)\n"
        "cvtsd2ss -0x110(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x114(%ebp)\n"
        "cvttss2si -0x114(%ebp), %eax\n"
        "movl %eax, 0x2ccfc(%ebx)\n"
        /* } scope */
        "addl $0x124, %esp\n" /* line 177 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0936_001d09fa:\n"
        "movl $0x100, 8(%esp)\n" /* line 161 */
        "leal -0x108(%ebp), %ebx\n" /* arg */
        "movl %ebx, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 162 */
        "calll CG_LoadShellShockDvars\n"
        "testl %eax, %eax\n"
        "jne .Lf1d0936_001d096e\n"
        "jmp .Lf1d0936_001d095f\n"
    );
}

/* line 185 */
static __attribute__((naked))
void CG_ShellShock_Load_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 185 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 189 */
        "cmpl $2, %eax\n"
        "je .Lf1d0a2e_001d0a51\n"
        "movl $0x2b73fc, (%esp)\n" /* line 191 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0a2e_001d0a51:\n"
        "movl $0x40, 8(%esp)\n" /* line 195 */
        "leal -0x48(%ebp), %ebx\n" /* name */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 196 */
        "calll CG_LoadShellShockDvars\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 197 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 205 */
static __attribute__((naked))
void CG_ShellShock_Save_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 205 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 209 */
        "cmpl $2, %eax\n"
        "je .Lf1d0a7a_001d0a9d\n"
        "movl $0x2b7420, (%esp)\n" /* line 211 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0a7a_001d0a9d:\n"
        "movl $0x40, 8(%esp)\n" /* line 215 */
        "leal -0x48(%ebp), %ebx\n" /* name */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, (%esp)\n" /* line 216 */
        "calll CG_SaveShellShockDvars\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 220 */
static __attribute__((naked))
void CG_TellTarget_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x120, %esp\n"
        /* { scope 1 */
        "calll CG_CrosshairPlayer\n" /* line 226 */
        "movl %eax, %esi\n" /* clientNum */
        "cmpl $-1, %eax\n" /* line 227 */
        "je .Lf1d0ac6_001d0b21\n"
        "movl $0x80, 4(%esp)\n" /* line 232 */
        "leal -0x108(%ebp), %ebx\n" /* message */
        "movl %ebx, (%esp)\n"
        "calll Cmd_ArgsBuffer\n"
        "movl %ebx, 0x10(%esp)\n" /* line 233 */
        "movl %esi, 0xc(%esp)\n" /* clientNum */
        "movl $0x2b7444, 8(%esp)\n" /* "tell %i "%s"" */
        "movl $0x80, 4(%esp)\n"
        "leal -0x88(%ebp), %ebx\n" /* command */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl %ebx, (%esp)\n" /* line 234 */
        "calll CL_AddReliableCommand\n"
        /* } scope */
        ".Lf1d0ac6_001d0b21:\n"
        "addl $0x120, %esp\n" /* line 235 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 238 */
static __attribute__((naked))
void CG_QuickMessage_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 238 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f584, %eax\n" /* line 240 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d0b2c_001d0b46\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 242 */
        "jne .Lf1d0b2c_001d0b48\n"
        ".Lf1d0b2c_001d0b46:\n"
        "leave\n" /* line 246 */
        "retl\n"
        ".Lf1d0b2c_001d0b48:\n"
        "movl $0x2adcb8, (%esp)\n" /* line 245 */
        "calll CL_Popup\n"
        "leave\n" /* line 246 */
        "retl\n"
    );
}

/* line 249 */
static __attribute__((naked))
void CG_VoiceChat_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 253 */
        "cmpl $2, %eax\n"
        "je .Lf1d0b56_001d0b6d\n"
        /* } scope */
        ".Lf1d0b56_001d0b67:\n"
        "addl $0x54, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0b56_001d0b6d:\n"
        "movl 0x195f584, %eax\n" /* line 257 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d0b56_001d0b87\n"
        "cmpl $5, 0x10(%eax)\n"
        "je .Lf1d0b56_001d0b87\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 259 */
        "je .Lf1d0b56_001d0bc0\n"
        ".Lf1d0b56_001d0b87:\n"
        "movl $0x40, 8(%esp)\n" /* line 266 */
        "leal -0x48(%ebp), %ebx\n" /* chatCmd */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, 4(%esp)\n" /* line 268 */
        "movl $0x2b7470, (%esp)\n" /* "cmd vsay %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0b56_001d0bc0:\n"
        "movl $0x2b7454, (%esp)\n" /* line 261 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf1d0b56_001d0b67\n"
    );
}

/* line 272 */
static __attribute__((naked))
void CG_TeamVoiceChat_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 276 */
        "cmpl $2, %eax\n"
        "je .Lf1d0bde_001d0bf5\n"
        /* } scope */
        ".Lf1d0bde_001d0bef:\n"
        "addl $0x54, %esp\n" /* line 292 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0bde_001d0bf5:\n"
        "movl 0x195f584, %eax\n" /* line 280 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d0bde_001d0c0f\n"
        "cmpl $5, 0x10(%eax)\n"
        "je .Lf1d0bde_001d0c0f\n"
        "testb $0x80, 0x1a(%eax)\n" /* line 282 */
        "je .Lf1d0bde_001d0c48\n"
        ".Lf1d0bde_001d0c0f:\n"
        "movl $0x40, 8(%esp)\n" /* line 289 */
        "leal -0x48(%ebp), %ebx\n" /* chatCmd */
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Cmd_ArgvBuffer\n"
        "movl %ebx, 4(%esp)\n" /* line 291 */
        "movl $0x2b7480, (%esp)\n" /* "cmd vsay_team %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 292 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0bde_001d0c48:\n"
        "movl $0x2b7454, (%esp)\n" /* line 284 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf1d0bde_001d0bef\n"
    );
}

/* line 365 */
__attribute__((naked))
qboolean CG_ConsoleCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 365 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 371 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1d0c66_001d0cb8\n"
        "movl $0, (%esp)\n" /* line 374 */
        "calll CG_Argv\n"
        "movl %eax, %edi\n" /* cmd */
        "movl commandsList, %eax\n" /* line 376 */
        "testl %eax, %eax\n"
        "je .Lf1d0c66_001d0cb8\n"
        "xorl %esi, %esi\n" /* i */
        "movl $commandsList, %ebx\n"
        ".Lf1d0c66_001d0c9b:\n"
        "movl %eax, 4(%esp)\n" /* line 378 */
        "movl %edi, (%esp)\n" /* cmd */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1d0c66_001d0cc2\n"
        "addl $1, %esi\n" /* line 376 | i */
        "movl 8(%ebx), %eax\n"
        "addl $8, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf1d0c66_001d0c9b\n"
        ".Lf1d0c66_001d0cb8:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1d0c66_001d0cba:\n"
        "addl $0x1c, %esp\n" /* line 387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0c66_001d0cc2:\n"
        "movl 0x333bc4(, %esi, 8), %eax\n" /* line 380 */
        "testl %eax, %eax\n"
        "je .Lf1d0c66_001d0cdc\n"
        "calll *%eax\n" /* line 381 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1d0c66_001d0cdc:\n"
        "movb $1, %al\n" /* line 380 */
        "jmp .Lf1d0c66_001d0cba\n"
    );
}

/* line 400 */
__attribute__((naked))
void CG_InitConsoleCommands(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 400 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl commandsList, %eax\n" /* line 404 */
        "testl %eax, %eax\n"
        "je .Lf1d0ce0_001d0d07\n"
        "movl $commandsList, %ebx\n"
        ".Lf1d0ce0_001d0cf5:\n"
        "movl %eax, (%esp)\n" /* line 405 */
        "calll CL_AddCgameCommand\n"
        "movl 8(%ebx), %eax\n" /* line 404 */
        "addl $8, %ebx\n"
        "testl %eax, %eax\n"
        "jne .Lf1d0ce0_001d0cf5\n"
        ".Lf1d0ce0_001d0d07:\n"
        "movl $0x2b3c2c, (%esp)\n" /* line 411 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3bf8, (%esp)\n" /* line 412 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c00, (%esp)\n" /* line 413 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c08, (%esp)\n" /* line 414 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c0c, (%esp)\n" /* line 415 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c14, (%esp)\n" /* line 416 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c20, (%esp)\n" /* line 417 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c28, (%esp)\n" /* line 418 */
        "calll CL_AddCgameCommand\n"
        "movl $0x225628, (%esp)\n" /* line 419 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c6c, (%esp)\n" /* line 420 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b7494, (%esp)\n" /* line 421 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b74a0, (%esp)\n" /* line 422 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2ac704, (%esp)\n" /* line 425 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3bc4, (%esp)\n" /* line 426 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2ac708, (%esp)\n" /* line 427 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2aa728, (%esp)\n" /* line 435 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b74a8, (%esp)\n" /* line 436 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c54, (%esp)\n" /* line 437 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c60, (%esp)\n" /* line 438 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c34, (%esp)\n" /* line 442 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c40, (%esp)\n" /* line 443 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2b3c84, (%esp)\n" /* line 448 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2aded8, (%esp)\n" /* line 451 */
        "calll CL_AddCgameCommand\n"
        "movl $0x2adee4, (%esp)\n" /* line 452 */
        "calll CL_AddCgameCommand\n"
        "addl $0x14, %esp\n" /* line 454 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

