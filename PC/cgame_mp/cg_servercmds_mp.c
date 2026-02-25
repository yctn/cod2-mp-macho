/* ASM dump from: cg_servercmds_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_servercmds_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

void CG_ParseServerinfo(void);
void CG_ParseCodinfo(void);
static void CG_AddToTeamChat(void);
static void CG_OpenScriptMenu(void);
void CG_CheckOpenWaitingScriptMenu(void);
void CG_CloseScriptMenu(void);
void CG_MenuShowNotify(int menuToShow);
static void CG_SetClientDvarFromServer(void);
void CG_ParseFog(void);
static void CG_DeactivateChannelVolCmd(void);
static void CG_SetChannelVolCmd(void);
static void CG_DeactivateReverbCmd(void);
void CG_SetConfigValues(void);
void CG_MapRestart(qboolean savepersist);
void CG_ServerCommand(void);
void CG_ExecuteNewServerCommands(int latestSequence);

/* line 148 */
__attribute__((naked))
void CG_ParseServerinfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 148 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 153 */
        "calll CL_GetConfigString\n"
        "movl %eax, %edi\n" /* info */
        "movl $0x2a714c, 4(%esp)\n" /* line 154 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %esi\n"
        "leal 0x5ec4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movl $0x2a7100, 4(%esp)\n" /* line 155 */
        "movl %edi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x5ea4(%esi), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n" /* mapname */
        "calll strncpy\n"
        "movl 0x5ea0(%esi), %eax\n" /* line 156 */
        "testl %eax, %eax\n"
        "jne .Lf1df74c_001df7d8\n"
        "movl %ebx, 4(%esp)\n" /* line 157 | mapname */
        "movl $0x2a7100, (%esp)\n" /* "g_gametype" */
        "calll Dvar_SetStringByName\n"
        ".Lf1df74c_001df7d8:\n"
        "movl $0x2a70dc, 4(%esp)\n" /* line 158 */
        "movl %edi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x5fc4(%esi)\n"
        "movl $0x2a7124, 4(%esp)\n" /* line 160 */
        "movl %edi, (%esp)\n" /* info */
        "calll Info_ValueForKey\n"
        "movl %eax, %ebx\n" /* mapname */
        "calll GetBspExtension\n" /* line 161 */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* mapname */
        "movl $0x2a74ac, 8(%esp)\n" /* "maps/mp/%s.%s" */
        "movl $0x40, 4(%esp)\n"
        "leal 0x5fc8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 162 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 172 */
__attribute__((naked))
void CG_ParseCodinfo(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 172 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195f5c4, %eax\n" /* line 178 */
        "movl (%eax), %eax\n"
        "movl 0x5ea0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1df83c_001df85c\n"
        /* } scope */
        ".Lf1df83c_001df855:\n"
        "addl $0x10, %esp\n" /* line 189 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1df83c_001df85c:\n"
        "movl $0x8e, %esi\n" /* line 179 */
        "jmp .Lf1df83c_001df885\n"
        ".Lf1df83c_001df863:\n"
        "leal 0x60(%esi), %eax\n" /* line 186 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 4(%esp)\n" /* line 187 */
        "movl %ebx, (%esp)\n" /* key */
        "calll Dvar_SetFromStringByName\n"
        "addl $1, %esi\n"
        "cmpl $0xee, %esi\n" /* line 181 */
        "je .Lf1df83c_001df855\n"
        ".Lf1df83c_001df885:\n"
        "movl %esi, (%esp)\n" /* line 183 */
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* key */
        "cmpb $0, (%eax)\n" /* line 184 */
        "jne .Lf1df83c_001df863\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 189 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 540 */
static __attribute__((naked))
void CG_AddToTeamChat(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 540 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %esi\n" /* str */
        /* { scope 1 */
        "movl 0x195f7e4, %eax\n" /* line 547 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n" /* chatHeight */
        "testl %edi, %edi\n" /* line 548 | chatHeight */
        "je .Lf1df89c_001dfa01\n"
        "movl 0x195f810, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1df89c_001dfa01\n"
        "movl 0x195f5c4, %eax\n" /* line 557 */
        "movl (%eax), %ebx\n" /* len */
        "movl 0xba14(%ebx), %eax\n" /* len */
        "cltd\n"
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ecx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xb170(%eax, %ebx), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movb $0, 0xc(%eax)\n" /* line 558 */
        "xorl %ebx, %ebx\n" /* len */
        "movl $0x37, -0x10(%ebp)\n" /* lastcolor */
        "movl $0, -0x14(%ebp)\n" /* ls */
        "jmp .Lf1df89c_001df92d\n"
        ".Lf1df89c_001df909:\n"
        "movl %esi, %edx\n" /* line 565 | str */
        "cmpb $0x5e, (%esi)\n" /* line 586 | str */
        "je .Lf1df89c_001df9cb\n"
        ".Lf1df89c_001df914:\n"
        "addl $1, %esi\n" /* str */
        "addl $1, %ebx\n" /* len */
        ".Lf1df89c_001df91a:\n"
        "movzbl (%edx), %eax\n" /* line 593 */
        "cmpb $0x20, %al\n"
        "movl -0x14(%ebp), %edx\n" /* ls */
        "cmovel %ecx, %edx\n"
        "movl %edx, -0x14(%ebp)\n" /* ls */
        "movb %al, (%ecx)\n" /* line 597 */
        "addl $1, %ecx\n"
        ".Lf1df89c_001df92d:\n"
        "cmpb $0, (%esi)\n" /* line 563 | str */
        "je .Lf1df89c_001dfa2c\n"
        "cmpl $0x59, %ebx\n" /* line 565 | len */
        "jle .Lf1df89c_001df909\n"
        "movl -0x14(%ebp), %ebx\n" /* line 567 | ls, len */
        "testl %ebx, %ebx\n" /* len */
        "je .Lf1df89c_001df950\n"
        "movl %ecx, %edx\n" /* line 569 */
        "subl -0x14(%ebp), %edx\n" /* ls */
        "movl %esi, %eax\n" /* str */
        "subl %edx, %eax\n"
        "leal 1(%eax), %esi\n" /* line 570 | str */
        "subl %edx, %ecx\n" /* line 571 */
        ".Lf1df89c_001df950:\n"
        "movb $0, (%ecx)\n" /* line 573 */
        "movl 0x195f5c4, %edx\n" /* line 575 */
        "movl (%edx), %ebx\n" /* len */
        "movl 0xba14(%ebx), %eax\n" /* len */
        "movl %eax, -0x18(%ebp)\n"
        "cltd\n"
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %ecx\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x25bb0(%edx), %edx\n"
        "movl %edx, 0xb9f4(%ebx, %ecx, 4)\n" /* len */
        "movl -0x18(%ebp), %eax\n" /* line 577 */
        "addl $1, %eax\n"
        "movl %eax, 0xba14(%ebx)\n" /* len */
        "cltd\n" /* line 578 */
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl %edx, %ecx\n"
        "shll $8, %ecx\n"
        "addl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xb170(%eax, %ebx), %eax\n"
        "movb $0x5e, 0xc(%eax)\n" /* line 580 */
        "movzbl -0x10(%ebp), %edx\n" /* line 581 | lastcolor */
        "movb %dl, 0xd(%eax)\n"
        "leal 0xe(%eax), %ecx\n"
        "testl %esi, %esi\n" /* line 586 | str */
        "je .Lf1df89c_001dfa7f\n"
        "movl %esi, %edx\n" /* str */
        "xorl %ebx, %ebx\n" /* len */
        "movl $0, -0x14(%ebp)\n" /* ls */
        "cmpb $0x5e, (%esi)\n" /* str */
        "jne .Lf1df89c_001df914\n"
        ".Lf1df89c_001df9cb:\n"
        "addl $1, %esi\n" /* str */
        "movzbl 1(%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf1df89c_001dfa24\n"
        "cmpb $0x5e, %al\n"
        "je .Lf1df89c_001dfa24\n"
        "cmpb $0x2f, %al\n"
        "jle .Lf1df89c_001dfa24\n"
        "cmpb $0x39, %al\n"
        "jg .Lf1df89c_001dfa24\n"
        "movb $0x5e, (%ecx)\n" /* line 588 */
        "movzbl 1(%edx), %esi\n" /* line 589 | str */
        "movl %esi, %eax\n" /* str */
        "movsbl %al, %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* lastcolor */
        "movl %esi, %eax\n" /* line 590 | str */
        "movb %al, 1(%ecx)\n"
        "addl $2, %ecx\n"
        "leal 2(%edx), %esi\n" /* str */
        "jmp .Lf1df89c_001df92d\n"
        ".Lf1df89c_001dfa01:\n"
        "movl 0x195f5c4, %eax\n" /* line 551 */
        "movl (%eax), %eax\n"
        "movl $0, 0xba18(%eax)\n"
        "movl $0, 0xba14(%eax)\n"
        /* } scope */
        ".Lf1df89c_001dfa1c:\n"
        "addl $0x10, %esp\n" /* line 607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1df89c_001dfa24:\n"
        "addl $1, %ebx\n" /* line 586 | len */
        "jmp .Lf1df89c_001df91a\n"
        ".Lf1df89c_001dfa2c:\n"
        "movb $0, (%ecx)\n" /* line 600 */
        "movl 0x195f5c4, %eax\n" /* line 602 */
        "movl (%eax), %ebx\n" /* len */
        "movl 0xba14(%ebx), %esi\n" /* len, str */
        "movl %esi, %eax\n" /* str */
        "cltd\n"
        "idivl %edi\n" /* chatHeight */
        "movl %edx, %ecx\n"
        "movl 0x195f584, %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 0xb9f4(%ebx, %ecx, 4)\n" /* len */
        "leal 1(%esi), %edx\n" /* line 603 | str */
        "movl %edx, 0xba14(%ebx)\n" /* len */
        "movl %edx, %eax\n" /* line 605 */
        "subl 0xba18(%ebx), %eax\n" /* len */
        "cmpl %eax, %edi\n" /* chatHeight */
        "jge .Lf1df89c_001dfa1c\n"
        "movl %edx, %eax\n" /* line 606 */
        "subl %edi, %eax\n" /* chatHeight */
        "movl %eax, 0xba18(%ebx)\n" /* len */
        /* } scope */
        "addl $0x10, %esp\n" /* line 607 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1df89c_001dfa7f:\n"
        "movl $0, -0x14(%ebp)\n" /* line 591 | ls */
        "xorl %edx, %edx\n"
        "movl $1, %esi\n" /* str */
        "movl $1, %ebx\n" /* len */
        "jmp .Lf1df89c_001df91a\n"
    );
}

/* line 692 */
static __attribute__((naked))
void CG_OpenScriptMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 692 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 700 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %esi\n" /* menuIndex */
        "cmpl $0x1f, %eax\n" /* line 701 */
        "jbe .Lf1dfa98_001dfaec\n"
        "movl %eax, 4(%esp)\n" /* line 703 */
        "movl $0x2b8070, (%esp)\n" /* "Server tried to open a bad script menu index: %i
" */
        ".Lf1dfa98_001dfac7:\n"
        "calll Com_Printf\n" /* line 714 */
        "movl %esi, 4(%esp)\n" /* line 715 | menuIndex */
        "movl $0x2b80a4, (%esp)\n" /* "cmd mr %i bad
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        /* } scope */
        ".Lf1dfa98_001dfae4:\n"
        "addl $0x2c, %esp\n" /* line 755 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dfa98_001dfaec:\n"
        "leal 0x4de(%eax), %eax\n" /* line 709 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, %edi\n" /* pszMenu */
        "cmpb $0, (%eax)\n" /* line 712 */
        "je .Lf1dfa98_001dfbed\n"
        "calll Cmd_Argc\n" /* line 720 */
        "cmpl $2, %eax\n"
        "jg .Lf1dfa98_001dfc0e\n"
        ".Lf1dfa98_001dfb13:\n"
        "movb $0, -0x19(%ebp)\n" /* noMouseControl */
        ".Lf1dfa98_001dfb17:\n"
        "movl $0x100, 8(%esp)\n" /* line 726 */
        "movl %edi, 4(%esp)\n" /* pszMenu */
        "movl 0x195ecb4, %ebx\n"
        "movl (%ebx), %eax\n"
        "addl $0x2e4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 727 */
        "movl %esi, 0x3e4(%eax)\n" /* menuIndex */
        "cmpb $0, -0x19(%ebp)\n" /* line 730 | noMouseControl */
        "je .Lf1dfa98_001dfbfd\n"
        "movl $0x2adc98, (%esp)\n" /* line 731 */
        "calll CL_Popup\n"
        ".Lf1dfa98_001dfb56:\n"
        "testl %eax, %eax\n" /* line 735 */
        "jne .Lf1dfa98_001dfae4\n"
        "movl 0x195ecb4, %ebx\n" /* line 738 */
        "movl (%ebx), %eax\n"
        "movb $0, 0x2e4(%eax)\n"
        "movl (%ebx), %eax\n" /* line 739 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%ebx), %eax\n" /* line 741 */
        "cmpb $0, 0x3e8(%eax)\n"
        "je .Lf1dfa98_001dfbb9\n"
        "addl $0x3e8, %eax\n" /* line 743 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* pszMenu */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dfa98_001dfae4\n"
        "movl (%ebx), %eax\n" /* line 747 */
        "movl 0x4e8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b80f0, (%esp)\n" /* "cmd mr %i noop
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        ".Lf1dfa98_001dfbb9:\n"
        "movl $0x100, 8(%esp)\n" /* line 751 */
        "movl %edi, 4(%esp)\n" /* pszMenu */
        "movl (%ebx), %eax\n"
        "addl $0x3e8, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl (%ebx), %eax\n" /* line 752 */
        "movl %esi, 0x4e8(%eax)\n" /* menuIndex */
        "movl (%ebx), %eax\n" /* line 753 */
        "movzbl -0x19(%ebp), %edx\n" /* noMouseControl */
        "movb %dl, 0x4ec(%eax)\n"
        "jmp .Lf1dfa98_001dfae4\n"
        ".Lf1dfa98_001dfbed:\n"
        "movl %esi, 4(%esp)\n" /* line 714 | menuIndex */
        "movl $0x2b80b4, (%esp)\n" /* "Server tried to open a non-loaded script menu index: %i
" */
        "jmp .Lf1dfa98_001dfac7\n"
        ".Lf1dfa98_001dfbfd:\n"
        "movl $0x2adc84, (%esp)\n" /* line 733 */
        "calll CL_Popup\n"
        "jmp .Lf1dfa98_001dfb56\n"
        ".Lf1dfa98_001dfc0e:\n"
        "movl $2, (%esp)\n" /* line 720 */
        "calll CG_Argv\n"
        "testl %eax, %eax\n"
        "je .Lf1dfa98_001dfb13\n"
        "movl $2, (%esp)\n"
        "calll CG_Argv\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1dfa98_001dfb13\n"
        "movb $1, -0x19(%ebp)\n" /* noMouseControl */
        "jmp .Lf1dfa98_001dfb17\n"
    );
}

/* line 763 */
__attribute__((naked))
void CG_CheckOpenWaitingScriptMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 763 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195ecb4, %ebx\n" /* line 765 */
        "movl (%ebx), %edx\n"
        "cmpb $0, 0x3e8(%edx)\n"
        "jne .Lf1dfc40_001dfc5e\n"
        "addl $0x14, %esp\n" /* line 797 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dfc40_001dfc5e:\n"
        "leal 0x3e8(%edx), %eax\n" /* line 770 */
        "movl %eax, 4(%esp)\n"
        "leal 0x2e4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl (%ebx), %edx\n" /* line 771 */
        "movl 0x4e8(%edx), %eax\n"
        "movl %eax, 0x3e4(%edx)\n"
        "movl (%ebx), %eax\n" /* line 773 */
        "cmpb $0, 0x4ec(%eax)\n"
        "je .Lf1dfc40_001dfcc9\n"
        "movl $0x2adc98, (%esp)\n" /* line 780 */
        "calll CL_Popup\n"
        "testl %eax, %eax\n" /* line 784 */
        "je .Lf1dfc40_001dfcd9\n"
        ".Lf1dfc40_001dfc9f:\n"
        "movl 0x195ecb4, %edx\n" /* line 786 */
        "movl (%edx), %eax\n"
        "movb $0, 0x3e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 787 */
        "movl $0xffffffff, 0x4e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 788 */
        "movb $0, 0x4ec(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 797 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1dfc40_001dfcc9:\n"
        "movl $0x2adc84, (%esp)\n" /* line 782 */
        "calll CL_Popup\n"
        "testl %eax, %eax\n" /* line 784 */
        "jne .Lf1dfc40_001dfc9f\n"
        ".Lf1dfc40_001dfcd9:\n"
        "movl 0x195ecb4, %eax\n" /* line 793 */
        "movl (%eax), %edx\n"
        "movb $0, 0x2e4(%edx)\n"
        "movl (%eax), %eax\n" /* line 794 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 797 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 805 */
__attribute__((naked))
void CG_CloseScriptMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 805 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2adc84, (%esp)\n" /* line 808 */
        "calll CL_ClosePopup\n"
        "movl $0x2adc98, (%esp)\n" /* line 809 */
        "calll CL_ClosePopup\n"
        "movl 0x195ecb4, %edx\n" /* line 812 */
        "movl (%edx), %eax\n"
        "movb $0, 0x1de(%eax)\n"
        "movl (%edx), %eax\n" /* line 813 */
        "movl $0xffffffff, 0x2e0(%eax)\n"
        "movl (%edx), %eax\n" /* line 814 */
        "movb $0, 0x2e4(%eax)\n"
        "movl (%edx), %eax\n" /* line 815 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%edx), %eax\n" /* line 816 */
        "movb $0, 0x3e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 817 */
        "movl $0xffffffff, 0x4e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 818 */
        "movb $0, 0x4ec(%eax)\n"
        "leave\n" /* line 819 */
        "retl\n"
    );
}

/* line 825 */
__attribute__((naked))
void CG_MenuShowNotify(int menuToShow)
{
    __asm__ __volatile__ (
        ".Lf1dfd68_001dfd68:\n"
        "pushl %ebp\n" /* line 825 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* menuToShow */
        /* { scope 1 */
        "cmpl $5, %eax\n" /* line 829 */
        "ja .Lf1dfd68_001dfddb\n"
        "jmpl *0x3039c0(, %eax, 4)\n"
        "movl $4, (%esp)\n" /* line 844 */
        "calll CG_MenuShowNotify\n"
        "movl 0x195f584, %eax\n" /* line 846 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5c8(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5c8(%eax)\n" /* line 848 */
        "calll CL_GetLocalClientActiveCount\n" /* line 849 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff1f\n"
        "movl $0x2b703c, 4(%esp)\n" /* line 852 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        ".Lf1dfd68_001dfdc7:\n"
        "testl %eax, %eax\n" /* line 898 */
        "je .Lf1dfd68_001dfddb\n"
        "movl $4, 4(%esp)\n" /* line 899 */
        "movl %eax, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        /* } scope */
        ".Lf1dfd68_001dfddb:\n"
        "leave\n" /* line 905 */
        "retl\n"
        /* { scope 1 */
        "movl 0x195f584, %eax\n" /* line 832 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5c4(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5c4(%eax)\n" /* line 834 */
        "calll CL_GetLocalClientActiveCount\n" /* line 835 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff87\n"
        "movl $0x2b7030, 4(%esp)\n" /* line 838 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        "movl 0x195f584, %eax\n" /* line 894 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2b538(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2b538(%eax)\n" /* line 896 */
        "movl $0x2b7074, 4(%esp)\n" /* line 897 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        "movl 0x195f584, %eax\n" /* line 882 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5d0(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5d0(%eax)\n" /* line 884 */
        "calll CL_GetLocalClientActiveCount\n" /* line 885 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff53\n"
        "movl $0x2b7064, 4(%esp)\n" /* line 888 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        "movl 0x195f584, %eax\n" /* line 870 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5cc(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5cc(%eax)\n" /* line 872 */
        "calll CL_GetLocalClientActiveCount\n" /* line 873 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff39\n"
        "movl $0x2b704c, 4(%esp)\n" /* line 876 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        "movl 0x195f584, %eax\n" /* line 858 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, 0x2c5c0(%eax)\n"
        "jge .Lf1dfd68_001dfddb\n"
        "movl %edx, 0x2c5c0(%eax)\n" /* line 860 */
        "calll CL_GetLocalClientActiveCount\n" /* line 861 */
        "subl $1, %eax\n"
        "je .Lf1dfd68_001dff6d\n"
        "movl $0x2a79e8, 4(%esp)\n" /* line 864 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff1f:\n"
        "movl $0x2b5978, 4(%esp)\n" /* line 850 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff39:\n"
        "movl $0x221984, 4(%esp)\n" /* line 874 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff53:\n"
        "movl $0x2b7058, 4(%esp)\n" /* line 886 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff6d:\n"
        "movl $0x2a79e0, 4(%esp)\n" /* line 862 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
        ".Lf1dfd68_001dff87:\n"
        "movl $0x2b7028, 4(%esp)\n" /* line 836 */
        "movl 0x195f7d4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "jmp .Lf1dfd68_001dfdc7\n"
    );
}

/* line 1165 */
static __attribute__((naked))
void CG_SetClientDvarFromServer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1165 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %ebx\n" /* dvarname */
        "movl %edx, %esi\n" /* value */
        "movl $0x2b8100, 4(%esp)\n" /* line 1167 */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1dffa2_001dffe9\n"
        "movl $0x400, 8(%esp)\n" /* line 1147 */
        "movl %esi, 4(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x2a9fc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dffa2_001dffe9:\n"
        "movl $0x2b8114, 4(%esp)\n" /* line 1169 */
        "movl %ebx, (%esp)\n" /* dvarname */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dffa2_001e0024\n"
        "movl $0x2b8120, 4(%esp)\n" /* line 1171 */
        "movl %ebx, (%esp)\n" /* dvarname */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1dffa2_001e0041\n"
        "movl %esi, 4(%esp)\n" /* line 1174 | value */
        "movl %ebx, (%esp)\n" /* dvarname */
        "calll Dvar_SetFromStringByName\n"
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dffa2_001e0024:\n"
        "movl %esi, (%esp)\n" /* line 1170 | value */
        "calll atoi\n"
        /* { scope 1 */
        "movl 0x195f584, %edx\n" /* line 1154 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x2bdc8(%edx)\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1dffa2_001e0041:\n"
        "movl $0x100, 8(%esp)\n" /* line 1161 */
        "movl %esi, 4(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x2adfc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $0x10, %esp\n" /* line 1175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 272 */
__attribute__((naked))
void CG_ParseFog(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x84, %esp\n"
        /* { scope 1 */
        "movl $0xc, (%esp)\n" /* line 284 */
        "calll CL_GetConfigString\n"
        "movl %eax, -0xc(%ebp)\n" /* info */
        "leal -0xc(%ebp), %ebx\n" /* line 285 | info, transitionTime */
        "movl %ebx, (%esp)\n" /* transitionTime */
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n" /* line 286 */
        "calll atof\n"
        "fstpl -0x50(%ebp)\n"
        "cvtsd2ss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* start */
        "movl %ebx, (%esp)\n" /* line 287 | transitionTime */
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 289 */
        "je .Lf1e0068_001e00b2\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf1e0068_001e00e1\n"
        ".Lf1e0068_001e00b2:\n"
        "cvttss2si -0x1c(%ebp), %eax\n" /* line 293 | start */
        "movl %eax, 8(%esp)\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CL_SwitchFog\n"
        /* } scope */
        "addl $0x84, %esp\n" /* line 308 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e0068_001e00e1:\n"
        "movl %eax, (%esp)\n" /* line 297 */
        "calll atof\n"
        "fstpl -0x48(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 300 | transitionTime */
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x40(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 301 | transitionTime */
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x38(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 302 | transitionTime */
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x30(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 303 | transitionTime */
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x28(%ebp)\n"
        "movl %ebx, (%esp)\n" /* line 304 | transitionTime */
        "calll Com_Parse\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* transitionTime */
        "cvtsd2ss -0x40(%ebp), %xmm0\n" /* line 306 */
        "movss %xmm0, 0x18(%esp)\n"
        "cvtsd2ss -0x28(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x54(%ebp)\n"
        "cvttss2si -0x54(%ebp), %eax\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x58(%ebp)\n"
        "cvttss2si -0x58(%ebp), %eax\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvtsd2ss -0x38(%ebp), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x5c(%ebp)\n"
        "cvttss2si -0x5c(%ebp), %eax\n"
        "movzbl %al, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvtsd2ss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* start */
        "movss %xmm0, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll CL_SetFog\n"
        "movl %ebx, 8(%esp)\n" /* line 307 | transitionTime */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll CL_SwitchFog\n"
        /* } scope */
        "addl $0x84, %esp\n" /* line 308 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1097 */
static __attribute__((naked))
void CG_DeactivateChannelVolCmd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1097 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 1103 */
        "cmpl $3, %eax\n" /* line 1104 */
        "je .Lf1e022c_001e0253\n"
        "movl %eax, 4(%esp)\n" /* line 1106 */
        "movl $0x2b8134, (%esp)\n" /* "ERROR: CG_DeactivateChannelVolCmd called with %i args (shoul" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 1113 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e022c_001e0253:\n"
        "movl $1, (%esp)\n" /* line 1110 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* prio */
        "movl $2, (%esp)\n" /* line 1111 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x14(%ebp)\n"
        "cvttss2si -0x14(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 45 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1e022c_001e02cf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1e022c_001e02bd:\n"
        "movl %eax, 4(%esp)\n" /* line 1112 */
        "movl %ebx, (%esp)\n" /* prio */
        "calll SND_DeactivateChannelVolumes\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 1113 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e022c_001e02cf:\n"
        "cvttss2si %xmm2, %eax\n" /* line 45 */
        "jmp .Lf1e022c_001e02bd\n"
    );
}

/* line 1071 */
static __attribute__((naked))
void CG_SetChannelVolCmd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1071 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 1078 */
        "cmpl $4, %eax\n" /* line 1079 */
        "je .Lf1e02d6_001e02ff\n"
        "movl %eax, 4(%esp)\n" /* line 1081 */
        "movl $0x2b817c, (%esp)\n" /* "ERROR: CG_SetChannelVolCmd called with %i args (should be 4)" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1089 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e02d6_001e02ff:\n"
        "movl $1, (%esp)\n" /* line 1085 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %esi\n" /* prio */
        "movl $2, (%esp)\n" /* line 1086 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* shockIndex */
        "movl $3, (%esp)\n" /* line 1087 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x14(%ebp)\n"
        "cvttss2si -0x14(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 45 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1e02d6_001e03ad\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1e02d6_001e037f:\n"
        "movl %eax, 8(%esp)\n" /* line 1088 */
        "movl %ebx, %eax\n" /* shockIndex */
        "shll $7, %eax\n"
        "leal 0x68f0(%eax, %ebx, 4), %eax\n"
        "movl 0x195f5c4, %edx\n"
        "addl (%edx), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* prio */
        "calll SND_SetChannelVolumes\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1089 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e02d6_001e03ad:\n"
        "cvttss2si %xmm2, %eax\n" /* line 45 */
        "jmp .Lf1e02d6_001e037f\n"
    );
}

/* line 1047 */
static __attribute__((naked))
void CG_DeactivateReverbCmd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1047 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 1053 */
        "cmpl $3, %eax\n" /* line 1054 */
        "je .Lf1e03b4_001e03db\n"
        "movl %eax, 4(%esp)\n" /* line 1056 */
        "movl $0x2b81bc, (%esp)\n" /* "ERROR: CG_DeactivateReverbCmd called with %i args (should be" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 1063 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e03b4_001e03db:\n"
        "movl $1, (%esp)\n" /* line 1060 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* prio */
        "movl $2, (%esp)\n" /* line 1061 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x14(%ebp)\n"
        "cvttss2si -0x14(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        /* { scope 2 */
        "pxor %xmm1, %xmm1\n" /* line 45 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1e03b4_001e0457\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf1e03b4_001e0445:\n"
        "movl %eax, 4(%esp)\n" /* line 1062 */
        "movl %ebx, (%esp)\n" /* prio */
        "calll SND_DeactivateEnvironmentEffects\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 1063 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1e03b4_001e0457:\n"
        "cvttss2si %xmm2, %eax\n" /* line 45 */
        "jmp .Lf1e03b4_001e0445\n"
    );
}

/* line 359 */
__attribute__((naked))
void CG_SetConfigValues(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 359 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195f5c4, %eax\n" /* line 363 */
        "movl (%eax), %ebx\n" /* i */
        "movl $5, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63b8(%ebx)\n" /* i */
        "movl $6, (%esp)\n" /* line 364 */
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63bc(%ebx)\n" /* i */
        "movl $0xd, (%esp)\n" /* line 365 */
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63b4(%ebx)\n" /* i */
        "movl $0, 8(%esp)\n" /* line 367 */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll CL_SwitchFog\n"
        "movl $0x4de, %esi\n"
        "jmp .Lf1e045e_001e04f2\n"
        ".Lf1e045e_001e04e7:\n"
        "addl $1, %esi\n" /* line 369 */
        "cmpl $0x4fe, %esi\n"
        "je .Lf1e045e_001e0538\n"
        /* { scope 2 */
        ".Lf1e045e_001e04f2:\n"
        "movl %esi, (%esp)\n" /* line 322 */
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n" /* pszConfigString */
        "cmpb $0, (%eax)\n" /* line 323 */
        "je .Lf1e045e_001e04e7\n"
        "movl $7, 4(%esp)\n" /* line 326 */
        "movl %eax, (%esp)\n"
        "calll Load_ScriptMenu\n"
        "testl %eax, %eax\n"
        "jne .Lf1e045e_001e04e7\n"
        "movl %ebx, 8(%esp)\n" /* line 327 | pszConfigString */
        "movl $0x2b8200, 4(%esp)\n" /* "Could not load script menu file '%s'
" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "addl $1, %esi\n" /* line 369 */
        "cmpl $0x4fe, %esi\n"
        "jne .Lf1e045e_001e04f2\n"
        ".Lf1e045e_001e0538:\n"
        "movl $0x17, %ebx\n" /* i */
        ".Lf1e045e_001e053d:\n"
        "movl %ebx, (%esp)\n" /* line 373 | i */
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "addl $1, %ebx\n" /* line 372 | i */
        "cmpl $0x1f, %ebx\n" /* i */
        "jne .Lf1e045e_001e053d\n"
        ".Lf1e045e_001e055d:\n"
        "movl %ebx, (%esp)\n" /* line 376 | i */
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "addl $1, %ebx\n" /* line 375 | i */
        "cmpl $0x2e, %ebx\n" /* i */
        "jne .Lf1e045e_001e055d\n"
        "movw $0x61f, %bx\n" /* i */
        "jmp .Lf1e045e_001e058e\n"
        ".Lf1e045e_001e0583:\n"
        "addl $1, %ebx\n" /* line 378 | i */
        "cmpl $0x69e, %ebx\n" /* i */
        "je .Lf1e045e_001e05b6\n"
        /* { scope 2 */
        ".Lf1e045e_001e058e:\n"
        "movl %ebx, (%esp)\n" /* line 343 | pszConfigString */
        "calll CL_GetConfigString\n"
        "cmpb $0, (%eax)\n" /* line 344 */
        "je .Lf1e045e_001e0583\n"
        "movl $7, 4(%esp)\n" /* line 347 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        /* } scope */
        "addl $1, %ebx\n" /* line 378 | i */
        "cmpl $0x69e, %ebx\n" /* i */
        "jne .Lf1e045e_001e058e\n"
        /* } scope */
        ".Lf1e045e_001e05b6:\n"
        "addl $0x10, %esp\n" /* line 380 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 621 */
__attribute__((naked))
void CG_MapRestart(qboolean savepersist)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 621 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* savepersist */
        "movl 0x195f940, %eax\n" /* line 623 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1e05be_001e07bf\n"
        ".Lf1e05be_001e05dc:\n"
        "movl 0x195f584, %eax\n" /* line 626 */
        "movl (%eax), %ebx\n"
        "movl $0, 0x2b990(%ebx)\n"
        "movl $0, 0x2bdf0(%ebx)\n" /* line 627 */
        "movl $1, 0x2be00(%ebx)\n" /* line 628 */
        "calll CG_InitLocalEntities\n" /* line 630 */
        "calll CG_InitMarkPolys\n" /* line 631 */
        "calll FX_FreeActive\n" /* line 632 */
        "movl 0x195f5c4, %eax\n" /* line 634 */
        "movl (%eax), %eax\n"
        "movl $0, 0x6088(%eax)\n"
        "movl $1, 0x25bbc(%ebx)\n" /* line 636 */
        "movl $0, (%esp)\n" /* line 638 */
        "calll SND_StopSounds\n"
        "calll CG_StartAmbient\n" /* line 640 */
        "movl $0, 0x2c5a4(%ebx)\n" /* line 642 */
        "movl $0, 0x2bf0c(%ebx)\n" /* line 645 */
        "leal 0x2be74(%ebx), %eax\n" /* line 646 */
        "movl $0x60, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x2be60(%ebx), %eax\n" /* line 649 */
        "movl $0, 0x2be60(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0x2be6c(%ebx)\n" /* line 650 */
        "movl $0, 4(%esp)\n" /* line 652 */
        "movl 0x195f860, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl 0x195ecb4, %esi\n" /* line 655 */
        "movl (%esi), %eax\n"
        "movl $0, 8(%eax)\n"
        "movl $0, (%esp)\n" /* line 658 */
        "calll CL_SetADS\n"
        "testl %edi, %edi\n" /* line 660 | savepersist */
        "jne .Lf1e05be_001e07a7\n"
        "movl (%esi), %eax\n" /* line 664 */
        "movb $0, 0x4ed(%eax)\n"
        "movl $0x2adc84, (%esp)\n" /* line 808 */
        "calll CL_ClosePopup\n"
        "movl $0x2adc98, (%esp)\n" /* line 809 */
        "calll CL_ClosePopup\n"
        "movl (%esi), %eax\n" /* line 812 */
        "movb $0, 0x1de(%eax)\n"
        "movl (%esi), %eax\n" /* line 813 */
        "movl $0xffffffff, 0x2e0(%eax)\n"
        "movl (%esi), %eax\n" /* line 814 */
        "movb $0, 0x2e4(%eax)\n"
        "movl (%esi), %eax\n" /* line 815 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%esi), %eax\n" /* line 816 */
        "movb $0, 0x3e8(%eax)\n"
        "movl (%esi), %eax\n" /* line 817 */
        "movl $0xffffffff, 0x4e8(%eax)\n"
        "movl (%esi), %eax\n" /* line 818 */
        "movb $0, 0x4ec(%eax)\n"
        "movl $0x2adc84, (%esp)\n" /* line 808 */
        "calll CL_ClosePopup\n"
        "movl $0x2adc98, (%esp)\n" /* line 809 */
        "calll CL_ClosePopup\n"
        "movl (%esi), %eax\n" /* line 812 */
        "movb $0, 0x1de(%eax)\n"
        "movl (%esi), %eax\n" /* line 813 */
        "movl $0xffffffff, 0x2e0(%eax)\n"
        "movl (%esi), %eax\n" /* line 814 */
        "movb $0, 0x2e4(%eax)\n"
        "movl (%esi), %eax\n" /* line 815 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%esi), %eax\n" /* line 816 */
        "movb $0, 0x3e8(%eax)\n"
        "movl (%esi), %eax\n" /* line 817 */
        "movl $0xffffffff, 0x4e8(%eax)\n"
        "movl (%esi), %eax\n" /* line 818 */
        "movb $0, 0x4ec(%eax)\n"
        "movl (%esi), %eax\n" /* line 667 */
        "movb $1, 0x4ed(%eax)\n"
        "calll CL_CloseAllMenus\n" /* line 669 */
        ".Lf1e05be_001e07a7:\n"
        "calll CG_ScoresUp_f\n" /* line 673 */
        "movb $0, 0x2a9fc(%ebx)\n" /* line 676 */
        "addl $0x1c, %esp\n" /* line 684 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CL_SyncTimes\n" /* line 678 */
        ".Lf1e05be_001e07bf:\n"
        "movl $0x2b8228, (%esp)\n" /* line 624 */
        "calll Com_Printf\n"
        "jmp .Lf1e05be_001e05dc\n"
    );
}

/* line 1189 */
__attribute__((naked))
void CG_ServerCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30c, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 1199 */
        "calll CG_Argv\n"
        "movsbl (%eax), %eax\n" /* line 1201 */
        "cmpl $0x76, %eax\n"
        "ja .Lf1e07d0_001e08ae\n"
        "jmpl *0x3039d8(, %eax, 4)\n"
        ".Lf1e07d0_001e07fb:\n"
        "cmpl $5, %ebx\n" /* line 470 */
        "je .Lf1e07d0_001e14b5\n"
        "cmpl $6, %ebx\n" /* line 474 */
        "je .Lf1e07d0_001e149b\n"
        "cmpl $0xd, %ebx\n" /* line 478 */
        "je .Lf1e07d0_001e1481\n"
        "cmpl $0xf, %ebx\n" /* line 482 */
        "je .Lf1e07d0_001e1467\n"
        "cmpl $0x11, %ebx\n" /* line 486 */
        "je .Lf1e07d0_001e144d\n"
        "cmpl $0x12, %ebx\n" /* line 490 */
        "je .Lf1e07d0_001e1433\n"
        "cmpl $0x10, %ebx\n" /* line 494 */
        "je .Lf1e07d0_001e136d\n"
        "cmpl $0xc, %ebx\n" /* line 498 */
        "je .Lf1e07d0_001e152f\n"
        "leal -0x14e(%ebx), %esi\n" /* line 502 */
        "cmpl $0xff, %esi\n"
        "jbe .Lf1e07d0_001e1352\n"
        "leal -0x34e(%ebx), %esi\n" /* line 506 */
        "cmpl $0x3f, %esi\n"
        "jbe .Lf1e07d0_001e1337\n"
        "leal -0x48e(%ebx), %esi\n" /* line 510 */
        "cmpl $0xf, %esi\n"
        "ja .Lf1e07d0_001e12fd\n"
        "cmpb $0, (%edi)\n" /* line 512 */
        "je .Lf1e07d0_001e08a3\n"
        "movl %edi, (%esp)\n"
        "calll CG_LoadShellShockDvars\n"
        "testl %eax, %eax\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl %esi, %eax\n" /* line 513 */
        "shll $7, %eax\n"
        "leal 0x68c0(%eax, %esi, 4), %eax\n"
        "movl 0x195f5c4, %edx\n"
        "addl (%edx), %eax\n"
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_SetShellShockParmsFromDvars\n"
        /* } scope */
        ".Lf1e07d0_001e08a3:\n"
        "addl $0x30c, %esp\n" /* line 1369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e07d0_001e08ae:\n"
        "movl $0, (%esp)\n" /* line 1357 */
        "calll CG_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8350, (%esp)\n" /* "Unknown client game command: %s
" */
        "calll Com_Printf\n"
        "calll Cmd_Argc\n" /* line 1359 */
        "movl %eax, %esi\n" /* argc */
        "cmpl $1, %eax\n" /* line 1360 */
        "jle .Lf1e07d0_001e08a3\n"
        "leal -1(%eax), %eax\n" /* line 1362 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2b8374, (%esp)\n" /* "Arguments(%i):" */
        "calll Com_Printf\n"
        "movl $1, %ebx\n" /* weapIndex */
        ".Lf1e07d0_001e08ee:\n"
        "movl %ebx, (%esp)\n" /* line 1364 | weapIndex */
        "calll CG_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2abc2c, (%esp)\n" /* " %s" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 1363 | weapIndex */
        "cmpl %ebx, %esi\n" /* weapIndex, argc */
        "jne .Lf1e07d0_001e08ee\n"
        "movl $0x2160e8, (%esp)\n" /* line 1365 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x30c, %esp\n" /* line 1369 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 1230 */
        "calll CG_Argv\n"
        "leal -0x1b2(%ebp), %ebx\n" /* hudElemString, weapIndex */
        "movl %ebx, 8(%esp)\n" /* weapIndex */
        "movl $0x2b8250, 4(%esp)\n" /* "game message" */
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl %ebx, (%esp)\n" /* line 1231 | weapIndex */
        "calll CG_GameMessage\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1327 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* weapIndex */
        "testl %eax, %eax\n" /* line 1328 */
        "je .Lf1e07d0_001e0987\n"
        "movl %eax, (%esp)\n"
        "calll BG_GetWeaponDef\n"
        "movl 0x84(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0987:\n"
        "movl %ebx, (%esp)\n" /* line 1329 | weapIndex */
        "calll CG_SetEquippedOffHand\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CG_DeactivateReverbCmd\n" /* line 1284 */
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CG_SetChannelVolCmd\n" /* line 1288 */
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CG_DeactivateChannelVolCmd\n" /* line 1292 */
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1345 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n" /* score */
        "calll atoi\n"
        /* { scope 2 */
        "movl 0x195f5c4, %edx\n" /* line 1008 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x63b8(%edx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        /* } scope */
        "movl $1, (%esp)\n" /* line 1349 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n" /* score */
        "calll atoi\n"
        /* { scope 2 */
        "movl 0x195f5c4, %edx\n" /* line 1008 */
        "movl (%edx), %edx\n"
        "movl %eax, 0x63bc(%edx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        /* } scope */
        "movl $1, (%esp)\n" /* line 1353 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll CG_MenuShowNotify\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1334 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll CL_ResetPlayerMuting\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CL_CloseInGameMenu\n" /* line 1308 */
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1208 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll CG_SelectWeaponIndex\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $0, (%esp)\n" /* line 1323 */
        "calll CG_MapRestart\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 434 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n"
        "movl %eax, (%esp)\n" /* line 437 */
        "calll CL_GetConfigString\n"
        "movl %eax, %edi\n"
        "cmpl $7, %ebx\n" /* line 440 */
        "je .Lf1e07d0_001e12d6\n"
        "cmpl $8, %ebx\n" /* line 444 */
        "je .Lf1e07d0_001e12e0\n"
        "cmpl $3, %ebx\n" /* line 448 */
        "je .Lf1e07d0_001e12ea\n"
        "testl %ebx, %ebx\n" /* line 452 */
        "je .Lf1e07d0_001e12b1\n"
        "leal -0x8e(%ebx), %eax\n" /* line 456 */
        "cmpl $0xbf, %eax\n"
        "ja .Lf1e07d0_001e07fb\n"
        "movl 0x195f5c4, %eax\n" /* line 178 */
        "movl (%eax), %eax\n"
        "movl 0x5ea0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1e07d0_001e08a3\n"
        "movl $0x8e, %esi\n"
        "jmp .Lf1e07d0_001e0b14\n"
        ".Lf1e07d0_001e0aee:\n"
        "leal 0x60(%esi), %eax\n" /* line 186 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, 4(%esp)\n" /* line 187 */
        "movl %ebx, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "addl $1, %esi\n"
        "cmpl $0xee, %esi\n" /* line 181 */
        "je .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0b14:\n"
        "movl %esi, (%esp)\n" /* line 183 */
        "calll CL_GetConfigString\n"
        "movl %eax, %ebx\n"
        "cmpb $0, (%eax)\n" /* line 184 */
        "jne .Lf1e07d0_001e0aee\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl 0x195f584, %esi\n" /* line 44 */
        "movl (%esi), %ebx\n"
        "movl $1, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af00(%ebx)\n"
        "cmpl $0x40, %eax\n" /* line 45 */
        "jle .Lf1e07d0_001e0b59\n"
        "movl $0x40, 0x2af00(%ebx)\n" /* line 46 */
        ".Lf1e07d0_001e0b59:\n"
        "leal 0x2af04(%ebx), %eax\n" /* line 48 */
        "movl $0, 0x2af04(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl $2, (%esp)\n" /* line 49 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af08(%ebx)\n"
        "movl $3, (%esp)\n" /* line 50 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af0c(%ebx)\n"
        "leal 0x2af34(%ebx), %eax\n" /* line 57 */
        "movl $0x600, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x2af14(%ebx), %eax\n" /* line 58 */
        "movl $0, 0x2af14(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "leal 0x2af24(%ebx), %eax\n" /* line 59 */
        "movl $0, 0x2af24(%ebx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0, 0xc(%eax)\n"
        "movl 0x2af00(%ebx), %ecx\n" /* line 60 */
        "testl %ecx, %ecx\n"
        "jg .Lf1e07d0_001e0fbe\n"
        "movl 0x195f584, %esi\n"
        "movl (%esi), %ecx\n"
        ".Lf1e07d0_001e0c30:\n"
        "xorl %ebx, %ebx\n"
        ".Lf1e07d0_001e0c32:\n"
        "movl 0x2af24(%ecx, %ebx, 4), %edx\n" /* line 96 */
        "testl %edx, %edx\n"
        "jle .Lf1e07d0_001e0fa7\n"
        "movl 0x2af14(%ecx, %ebx, 4), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf1e07d0_001e0fa7\n"
        "movl %edx, %esi\n" /* line 99 */
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, 0x2af14(%ecx, %ebx, 4)\n"
        ".Lf1e07d0_001e0c5c:\n"
        "addl $1, %ebx\n" /* line 94 */
        "cmpl $4, %ebx\n"
        "jne .Lf1e07d0_001e0c32\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1216 */
        "calll CG_Argv\n"
        "leal -0x1b2(%ebp), %ebx\n" /* hudElemString, weapIndex */
        "movl %ebx, 8(%esp)\n" /* weapIndex */
        "movl $0x2b8238, 4(%esp)\n" /* "announcement message" */
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl %ebx, (%esp)\n" /* line 1217 | weapIndex */
        "calll CG_BoldGameMessage\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1235 */
        "calll CG_Argv\n"
        "leal -0x1b2(%ebp), %ebx\n" /* hudElemString, weapIndex */
        "movl %ebx, 8(%esp)\n" /* weapIndex */
        "movl $0x2b8260, 4(%esp)\n" /* "bold game message" */
        "movl %eax, (%esp)\n"
        "calll CG_TranslateHudElemMessage\n"
        "movl %ebx, (%esp)\n" /* line 1236 | weapIndex */
        "calll CG_BoldGameMessage\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl 0x195f94c, %eax\n" /* line 1240 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1243 */
        "calll CG_Argv\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2b8274, 4(%esp)\n" /* "chat message" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x96, 8(%esp)\n" /* line 1245 */
        "movl %eax, 4(%esp)\n"
        "leal -0xb2(%ebp), %ebx\n" /* text, weapIndex */
        "movl %ebx, (%esp)\n" /* weapIndex */
        "calll I_strncpyz\n"
        /* { scope 2 */
        "movzbl -0xb2(%ebp), %eax\n" /* line 990 | text */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e0fb7\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %edx\n"
        ".Lf1e07d0_001e0d31:\n"
        "cmpb $0x19, %al\n" /* line 992 */
        "je .Lf1e07d0_001e0d3f\n"
        "movb %al, -0xb2(%ebp, %ecx)\n" /* line 994 */
        "addl $1, %ecx\n"
        ".Lf1e07d0_001e0d3f:\n"
        "movzbl 1(%edx), %eax\n" /* line 990 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lf1e07d0_001e0d31\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1e07d0_001e0d4a:\n"
        "movl %ecx, %eax\n"
        ".Lf1e07d0_001e0d4c:\n"
        "movb $0, -0xb2(%ebp, %eax)\n" /* line 996 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1256 | weapIndex */
        "calll CG_AddToTeamChat\n"
        "movl %ebx, 4(%esp)\n" /* line 1257 | weapIndex */
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1252 */
        "calll CG_Argv\n"
        "movl $0, 8(%esp)\n"
        "movl $0x2b8284, 4(%esp)\n" /* "team chat message" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x96, 8(%esp)\n" /* line 1254 */
        "movl %eax, 4(%esp)\n"
        "leal -0xb2(%ebp), %ebx\n" /* text, weapIndex */
        "movl %ebx, (%esp)\n" /* weapIndex */
        "calll I_strncpyz\n"
        /* { scope 2 */
        "movzbl -0xb2(%ebp), %eax\n" /* line 990 | text */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e0fb7\n"
        "xorl %ecx, %ecx\n"
        "movl %ebx, %edx\n"
        ".Lf1e07d0_001e0dc1:\n"
        "cmpb $0x19, %al\n" /* line 992 */
        "je .Lf1e07d0_001e0dcf\n"
        "movb %al, -0xb2(%ebp, %ecx)\n" /* line 994 */
        "addl $1, %ecx\n"
        ".Lf1e07d0_001e0dcf:\n"
        "movzbl 1(%edx), %eax\n" /* line 990 */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lf1e07d0_001e0dc1\n"
        "jmp .Lf1e07d0_001e0d4a\n"
        /* } scope */
        "calll CG_PlaySoundOnFirstClient\n" /* line 1265 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1266 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll CL_PickSoundAlias\n"
        "movl $1, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SND_PlayMusicAlias\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CG_PlaySoundOnFirstClient\n" /* line 1270 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1271 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, (%esp)\n"
        "calll SND_StopMusic\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CG_PlaySoundOnFirstClient\n" /* line 1275 */
        "testb %al, %al\n"
        "je .Lf1e07d0_001e08a3\n"
        "movl $2, (%esp)\n" /* line 1276 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* weapIndex */
        "movl $1, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2e8(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* weapIndex */
        "cvtsd2ss -0x2e8(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll Cmd_Argc\n" /* line 1026 */
        "cmpl $6, %eax\n" /* line 1027 */
        "je .Lf1e07d0_001e1167\n"
        "movl %eax, 4(%esp)\n" /* line 1029 */
        "movl $0x2b8298, (%esp)\n" /* "ERROR: CG_ReverbCmd called with %i args (should be 6)
" */
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll Cmd_Argc\n" /* line 1127 */
        "cmpl $2, %eax\n" /* line 1128 */
        "je .Lf1e07d0_001e1274\n"
        "movl %eax, 4(%esp)\n" /* line 1130 */
        "movl $0x2b82d0, (%esp)\n" /* "ERROR: CG_LocalSound called with %i args (should be 2)
" */
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $0x2adc84, (%esp)\n" /* line 808 */
        "calll CL_ClosePopup\n"
        "movl $0x2adc98, (%esp)\n" /* line 809 */
        "calll CL_ClosePopup\n"
        "movl 0x195ecb4, %edx\n" /* line 812 */
        "movl (%edx), %eax\n"
        "movb $0, 0x1de(%eax)\n"
        "movl (%edx), %eax\n" /* line 813 */
        "movl $0xffffffff, 0x2e0(%eax)\n"
        "movl (%edx), %eax\n" /* line 814 */
        "movb $0, 0x2e4(%eax)\n"
        "movl (%edx), %eax\n" /* line 815 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%edx), %eax\n" /* line 816 */
        "movb $0, 0x3e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 817 */
        "movl $0xffffffff, 0x4e8(%eax)\n"
        "movl (%edx), %eax\n" /* line 818 */
        "movb $0, 0x4ec(%eax)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "calll CG_OpenScriptMenu\n" /* line 1300 */
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1312 */
        "calll CG_Argv\n"
        "movl $0x96, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0xb2(%ebp), %ebx\n" /* text, weapIndex */
        "movl %ebx, (%esp)\n" /* weapIndex */
        "calll I_strncpyz\n"
        "movl $2, (%esp)\n" /* line 1313 */
        "calll CG_Argv\n"
        "movl %eax, %edx\n"
        "movl %ebx, %eax\n" /* weapIndex */
        "calll CG_SetClientDvarFromServer\n"
        "jmp .Lf1e07d0_001e08a3\n"
        "movl $1, (%esp)\n" /* line 1261 */
        "calll CG_MapRestart\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e0fa7:\n"
        "movl $0, 0x2af14(%ecx, %ebx, 4)\n" /* line 97 */
        "jmp .Lf1e07d0_001e0c5c\n"
        /* { scope 2 */
        ".Lf1e07d0_001e0fb7:\n"
        "xorl %eax, %eax\n" /* line 990 */
        "jmp .Lf1e07d0_001e0d4c\n"
        /* } scope */
        ".Lf1e07d0_001e0fbe:\n"
        "movl $0, -0x2e0(%ebp)\n" /* line 60 */
        "movl $4, %edi\n"
        "movl %esi, -0x2f0(%ebp)\n"
        "movl $0, -0x2f4(%ebp)\n"
        "jmp .Lf1e07d0_001e104f\n"
        ".Lf1e07d0_001e0fdf:\n"
        "movl 0xe0940(%eax), %eax\n" /* line 79 */
        ".Lf1e07d0_001e0fe5:\n"
        "movl -0x2f4(%ebp), %edx\n"
        "movl %eax, 0x2af44(%edx, %esi)\n"
        "movl -0x2f0(%ebp), %esi\n" /* line 81 */
        "movl (%esi), %ecx\n"
        "movl -0x2f4(%ebp), %edx\n"
        "addl %ecx, %edx\n"
        "movl 0x2af44(%edx), %eax\n"
        "addl $1, 0x2af24(%ecx, %eax, 4)\n"
        "movl 0x2af44(%edx), %ebx\n" /* line 82 */
        "movl 0x2af14(%ecx, %ebx, 4), %eax\n"
        "addl 0x2af3c(%edx), %eax\n"
        "movl %eax, 0x2af14(%ecx, %ebx, 4)\n"
        "addl $1, -0x2e0(%ebp)\n" /* line 60 */
        "addl $0x18, -0x2f4(%ebp)\n"
        "movl %ecx, %ebx\n"
        "addl $5, %edi\n"
        "movl -0x2e0(%ebp), %eax\n"
        "cmpl %eax, 0x2af00(%ecx)\n"
        "jle .Lf1e07d0_001e0c30\n"
        ".Lf1e07d0_001e104f:\n"
        "movl %edi, (%esp)\n" /* line 62 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl -0x2f4(%ebp), %edx\n"
        "movl %eax, 0x2af34(%edx, %ebx)\n"
        "movl 0x195f584, %eax\n" /* line 63 */
        "movl (%eax), %esi\n"
        "leal 1(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl -0x2f4(%ebp), %ebx\n"
        "addl %esi, %ebx\n"
        "movl %eax, 0x2af38(%ebx)\n"
        "leal 2(%edi), %eax\n" /* line 64 */
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af3c(%ebx)\n"
        "leal 3(%edi), %eax\n" /* line 65 */
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x2af40(%ebx)\n"
        "leal 4(%edi), %eax\n" /* line 66 */
        "movl %eax, (%esp)\n"
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edx\n"
        "leal -1(%eax), %eax\n" /* line 68 */
        "cmpl $7, %eax\n"
        "jbe .Lf1e07d0_001e1141\n"
        ".Lf1e07d0_001e10e3:\n"
        "cmpl $0x3f, 0x2af34(%ebx)\n" /* line 74 */
        "jbe .Lf1e07d0_001e10f6\n"
        "movl $0, 0x2af34(%ebx)\n" /* line 75 */
        ".Lf1e07d0_001e10f6:\n"
        "movl 0x2af34(%ebx), %edx\n" /* line 77 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0x2af38(%ebx), %edx\n"
        "movl %edx, 0xe0948(%esi, %eax, 8)\n"
        "movl 0x2af34(%ebx), %edx\n" /* line 79 */
        "leal (%edx, %edx, 4), %ecx\n"
        "movl %ecx, %eax\n"
        "shll $4, %eax\n"
        "subl %ecx, %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%esi, %eax, 8), %eax\n"
        "movl 0xe0914(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1e07d0_001e0fdf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1e07d0_001e0fe5\n"
        ".Lf1e07d0_001e1141:\n"
        "leal 0x16(%edx), %eax\n" /* line 70 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n" /* line 71 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x2af48(%ebx)\n"
        "jmp .Lf1e07d0_001e10e3\n"
        ".Lf1e07d0_001e1167:\n"
        "movl $1, (%esp)\n" /* line 1033 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %esi\n"
        "movl $3, (%esp)\n" /* line 1034 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2d8(%ebp)\n"
        "cvtsd2ss -0x2d8(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c0(%ebp)\n"
        "movl $4, (%esp)\n" /* line 1035 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2d0(%ebp)\n"
        "cvtsd2ss -0x2d0(%ebp), %xmm0\n"
        "movss %xmm0, -0x2bc(%ebp)\n"
        "movl $5, (%esp)\n" /* line 1036 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x2c8(%ebp)\n"
        "movl $2, (%esp)\n" /* line 1037 */
        "calll CG_Argv\n"
        "movl %eax, %ebx\n"
        "cvtsd2ss -0x2c8(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x2ec(%ebp)\n"
        "cvttss2si -0x2ec(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "pxor %xmm1, %xmm1\n" /* line 45 */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf1e07d0_001e12f4\n"
        "xorl %eax, %eax\n"
        ".Lf1e07d0_001e1243:\n"
        "movl %eax, 0x10(%esp)\n" /* line 1038 */
        "movss -0x2bc(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x2c0(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll SND_SetEnvironmentEffects\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1274:\n"
        "movl $1, (%esp)\n" /* line 1134 */
        "calll CG_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edx\n"
        "leal -1(%eax), %eax\n" /* line 1135 */
        "cmpl $0xff, %eax\n"
        "jbe .Lf1e07d0_001e12bb\n"
        "movl $0x100, 8(%esp)\n" /* line 1137 */
        "movl %edx, 4(%esp)\n"
        "movl $0x2b8308, (%esp)\n" /* "ERROR: CG_LocalSound called with index %i (should be in rang" */
        "calll Com_Printf\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12b1:\n"
        "calll CG_ParseServerinfo\n" /* line 454 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12bb:\n"
        "leal 0x24e(%edx), %eax\n" /* line 1140 */
        "movl %eax, (%esp)\n"
        "calll CL_GetConfigString\n"
        "movl %eax, (%esp)\n" /* line 1141 */
        "calll CG_PlayClientSoundAliasByName\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12d6:\n"
        "calll CG_SetupWeaponDef\n" /* line 442 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12e0:\n"
        "calll CG_RegisterItems\n" /* line 446 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12ea:\n"
        "calll CG_StartAmbient\n" /* line 450 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e12f4:\n"
        "cvttss2si %xmm2, %eax\n" /* line 45 */
        "jmp .Lf1e07d0_001e1243\n"
        ".Lf1e07d0_001e12fd:\n"
        "leal -0x17(%ebx), %eax\n" /* line 515 */
        "cmpl $7, %eax\n"
        "jbe .Lf1e07d0_001e14ec\n"
        "leal -0x1f(%ebx), %eax\n" /* line 519 */
        "cmpl $0xe, %eax\n"
        "jbe .Lf1e07d0_001e14cf\n"
        "leal -0x61e(%ebx), %eax\n" /* line 523 */
        "cmpl $0x7f, %eax\n"
        "jbe .Lf1e07d0_001e1509\n"
        "cmpl $0xb, %ebx\n" /* line 527 */
        "jne .Lf1e07d0_001e08a3\n"
        "calll CG_NorthDirectionChanged\n" /* line 529 */
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1337:\n"
        "movl 0x195f5c4, %eax\n" /* line 508 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll FX_RegisterEffect\n"
        "movl %eax, 0x67c0(%ebx, %esi, 4)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1352:\n"
        "movl 0x195f5c4, %eax\n" /* line 504 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll CL_RegisterModel\n"
        "movl %eax, 0x63c0(%ebx, %esi, 4)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e136d:\n"
        "movl $0, -0x2dc(%ebp)\n" /* line 494 */
        "xorl %esi, %esi\n"
        ".Lf1e07d0_001e1379:\n"
        "leal (%edi, %esi), %ebx\n" /* line 393 */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_GetMapDisplayNameFromPartialLoadNameMatch\n"
        "testl %eax, %eax\n" /* line 395 */
        "je .Lf1e07d0_001e13c0\n"
        "movzbl (%eax), %edx\n" /* line 401 */
        "testb %dl, %dl\n"
        "je .Lf1e07d0_001e13ba\n"
        "leal -0x2b2(%ebp), %ecx\n"
        "addl -0x2dc(%ebp), %ecx\n"
        "xorl %ebx, %ebx\n"
        ".Lf1e07d0_001e13a4:\n"
        "movb %dl, (%ecx)\n" /* line 403 */
        "addl $1, %ebx\n" /* line 405 */
        "movzbl (%ebx, %eax), %edx\n" /* line 401 */
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf1e07d0_001e13a4\n"
        "addl %ebx, -0x2dc(%ebp)\n"
        ".Lf1e07d0_001e13ba:\n"
        "addl -0x1c(%ebp), %esi\n" /* line 408 */
        "leal (%esi, %edi), %ebx\n"
        ".Lf1e07d0_001e13c0:\n"
        "movzbl (%ebx), %eax\n" /* line 411 */
        "movl -0x2dc(%ebp), %edx\n"
        "movb %al, -0x2b2(%ebp, %edx)\n"
        "addl $1, %edx\n" /* line 412 */
        "movl %edx, -0x2dc(%ebp)\n"
        "cmpb $0, (%ebx)\n" /* line 414 */
        "je .Lf1e07d0_001e13e9\n"
        "addl $1, %esi\n" /* line 391 */
        "cmpl $0xff, %esi\n"
        "jle .Lf1e07d0_001e1379\n"
        ".Lf1e07d0_001e13e9:\n"
        "movb $0, -0x1b3(%ebp)\n" /* line 418 */
        "movl $0, 8(%esp)\n" /* line 420 */
        "movl $0x2a79f4, 4(%esp)\n" /* "vote string" */
        "leal -0x2b2(%ebp), %esi\n"
        "movl %esi, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x6094, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1433:\n"
        "movl 0x195f5c4, %eax\n" /* line 492 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x6090(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e144d:\n"
        "movl 0x195f5c4, %eax\n" /* line 488 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x608c(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1467:\n"
        "movl 0x195f5c4, %eax\n" /* line 484 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x6088(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1481:\n"
        "movl 0x195f5c4, %eax\n" /* line 480 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63b4(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e149b:\n"
        "movl 0x195f5c4, %eax\n" /* line 476 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63bc(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e14b5:\n"
        "movl 0x195f5c4, %eax\n" /* line 472 */
        "movl (%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll atoi\n"
        "movl %eax, 0x63b8(%ebx)\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e14cf:\n"
        "movl %ebx, (%esp)\n" /* line 521 */
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e14ec:\n"
        "movl %ebx, (%esp)\n" /* line 517 */
        "calll CL_GetConfigString\n"
        "movl $7, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e1509:\n"
        "movl %ebx, (%esp)\n" /* line 343 */
        "calll CL_GetConfigString\n"
        "cmpb $0, (%eax)\n" /* line 344 */
        "je .Lf1e07d0_001e08a3\n"
        "movl $7, 4(%esp)\n" /* line 347 */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "jmp .Lf1e07d0_001e08a3\n"
        ".Lf1e07d0_001e152f:\n"
        "calll CG_ParseFog\n" /* line 500 */
        "jmp .Lf1e07d0_001e08a3\n"
    );
}

/* line 1380 */
__attribute__((naked))
void CG_ExecuteNewServerCommands(int latestSequence)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1380 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* latestSequence */
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %ebx\n"
        ".Lf1e153a_001e154c:\n"
        "movl 0x5e98(%ebx), %eax\n" /* line 1382 */
        "cmpl %esi, %eax\n" /* latestSequence */
        "jge .Lf1e153a_001e157a\n"
        ".Lf1e153a_001e1556:\n"
        "addl $1, %eax\n" /* line 1386 */
        "movl %eax, 0x5e98(%ebx)\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetServerCommand\n"
        "testl %eax, %eax\n"
        "je .Lf1e153a_001e154c\n"
        "calll CG_ServerCommand\n" /* line 1387 */
        "movl 0x5e98(%ebx), %eax\n" /* line 1382 */
        "cmpl %esi, %eax\n" /* latestSequence */
        "jl .Lf1e153a_001e1556\n"
        ".Lf1e153a_001e157a:\n"
        "addl $0x10, %esp\n" /* line 1389 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

