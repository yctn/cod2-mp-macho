/* ASM dump from: cg_info_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_info_mp.cpp */

#include "common_types.h"
#include "imports.h"

void CG_LoadingString(const char *s);
void CG_DrawInformation(qboolean serverLoading);

/* line 16 */
__attribute__((naked))
void CG_LoadingString(const char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 16 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        "movl $0x400, 8(%esp)\n" /* line 18 */
        "movl %ebx, 4(%esp)\n" /* s */
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x2a5fc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "testl %ebx, %ebx\n" /* line 20 | s */
        "je .Lf1e1c54_001e1c87\n"
        "cmpb $0, (%ebx)\n" /* s */
        "jne .Lf1e1c54_001e1c91\n"
        ".Lf1e1c54_001e1c87:\n"
        "addl $0x14, %esp\n" /* line 24 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SCR_UpdateScreen\n" /* line 23 */
        ".Lf1e1c54_001e1c91:\n"
        "movl %ebx, 4(%esp)\n" /* line 21 | s */
        "movl $0x2b8384, (%esp)\n" /* "LOADING... %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Com_Printf\n"
        "addl $0x14, %esp\n" /* line 24 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SCR_UpdateScreen\n" /* line 23 */
    );
}

/* line 27 */
__attribute__((naked))
void CG_DrawInformation(qboolean serverLoading)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x44c, %esp\n"
        "movl 8(%ebp), %esi\n" /* serverLoading */
        /* { scope 1 */
        "testl %esi, %esi\n" /* line 50 | serverLoading */
        "je .Lf1e1cb4_001e1f0e\n"
        "movl 0x195ecb4, %ebx\n" /* line 58 | pos */
        "movl (%ebx), %eax\n" /* pos */
        "cmpb $0, 0xdc(%eax)\n"
        "je .Lf1e1cb4_001e1daf\n"
        ".Lf1e1cb4_001e1ce0:\n"
        "movl $0, (%esp)\n" /* line 72 */
        "calll CL_GetConfigString\n"
        "testl %esi, %esi\n" /* line 74 | serverLoading */
        "je .Lf1e1cb4_001e1d77\n"
        "movl $0x400, 8(%esp)\n" /* line 76 */
        "movl 0x195ecb4, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x5c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* string, pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll I_strncpyz\n"
        ".Lf1e1cb4_001e1d18:\n"
        "movzbl -0x418(%ebp), %eax\n" /* line 88 | string */
        "testb %al, %al\n"
        "jne .Lf1e1cb4_001e1d47\n"
        ".Lf1e1cb4_001e1d23:\n"
        "calll UI_DrawMapLevelshot\n" /* line 91 */
        "movl $0x2b8394, (%esp)\n" /* line 95 */
        "calll Dvar_GetInt\n"
        "testl %eax, %eax\n" /* line 96 */
        "jle .Lf1e1cb4_001e1de8\n"
        /* } scope */
        ".Lf1e1cb4_001e1d3c:\n"
        "addl $0x44c, %esp\n" /* line 137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e1cb4_001e1d47:\n"
        "movsbl %al, %eax\n" /* line 89 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, (%ebx)\n" /* pos */
        "addl $1, %ebx\n" /* line 88 | pos */
        "movzbl (%ebx), %eax\n" /* pos */
        "testb %al, %al\n"
        "je .Lf1e1cb4_001e1d23\n"
        "movsbl %al, %eax\n" /* line 89 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, (%ebx)\n" /* pos */
        "addl $1, %ebx\n" /* line 88 | pos */
        "movzbl (%ebx), %eax\n" /* pos */
        "testb %al, %al\n"
        "jne .Lf1e1cb4_001e1d47\n"
        "jmp .Lf1e1cb4_001e1d23\n"
        ".Lf1e1cb4_001e1d77:\n"
        "movl $0x2a7124, 4(%esp)\n" /* line 80 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "cmpb $0, (%eax)\n" /* line 82 */
        "je .Lf1e1cb4_001e1f31\n"
        "movl $0x400, 8(%esp)\n" /* line 84 */
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* string, pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll I_strncpyz\n"
        "jmp .Lf1e1cb4_001e1d18\n"
        ".Lf1e1cb4_001e1daf:\n"
        "movb $0, 0x4ed(%eax)\n" /* line 60 */
        "calll CG_CloseScriptMenu\n" /* line 61 */
        "calll CG_CloseScriptMenu\n" /* line 62 */
        "movl (%ebx), %eax\n" /* line 63 | pos */
        "movb $1, 0x4ed(%eax)\n"
        "calll CL_CloseAllMenus\n" /* line 65 */
        "movl $0, (%esp)\n" /* line 66 */
        "calll SND_StopSounds\n"
        "movl (%ebx), %eax\n" /* line 68 | pos */
        "movb $1, 0xdc(%eax)\n"
        "jmp .Lf1e1cb4_001e1ce0\n"
        ".Lf1e1cb4_001e1de8:\n"
        "testl %esi, %esi\n" /* line 107 | serverLoading */
        "je .Lf1e1cb4_001e1d3c\n"
        "movl 0x195f958, %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf1e1cb4_001e1d3c\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 111 */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x41c(%ebp)\n" /* font */
        "calll Sys_Milliseconds\n" /* line 113 */
        "movl %eax, %ecx\n"
        "movl $0x57619f1, %edx\n" /* line 115 */
        "imull %edx\n"
        "sarl $4, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "andl $3, %edx\n"
        "cmpl $2, %edx\n"
        "je .Lf1e1cb4_001e1f66\n"
        "cmpl $3, %edx\n"
        "je .Lf1e1cb4_001e1f70\n"
        "subl $1, %edx\n"
        "je .Lf1e1cb4_001e1f5c\n"
        "movl $0x2157b8, %edi\n" /* dots */
        ".Lf1e1cb4_001e1e53:\n"
        "movl $0x2b83ac, (%esp)\n" /* line 131 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* pos */
        "movl $0x3f000000, 0xc(%esp)\n" /* line 132 */
        "movl -0x41c(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl %eax, %esi\n" /* serverLoading */
        "movl %edi, 8(%esp)\n" /* line 133 | dots */
        "movl %ebx, 4(%esp)\n" /* pos */
        "movl $0x215f50, (%esp)\n" /* "%s%s" */
        "calll va\n"
        "movl $3, 0x24(%esp)\n" /* line 136 */
        "movl 0x195ed2c, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3f000000, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x43db8000, 0x10(%esp)\n"
        "cvtsi2ssl %esi, %xmm1\n" /* serverLoading */
        "movss 0x2ed860, %xmm0\n" /* 640.0f */
        "subss %xmm1, %xmm0\n"
        "mulss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x41c(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x44c, %esp\n" /* line 137 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e1cb4_001e1f0e:\n"
        "movl 0x195ecb4, %edx\n" /* line 52 */
        "movl (%edx), %eax\n"
        "movb $0, 0x5c(%eax)\n"
        "movl (%edx), %eax\n" /* line 53 */
        "movb $0, 0x9c(%eax)\n"
        "movl (%edx), %eax\n" /* line 54 */
        "movb $0, 0xdc(%eax)\n"
        "jmp .Lf1e1cb4_001e1ce0\n"
        ".Lf1e1cb4_001e1f31:\n"
        "movl $0x2a7124, (%esp)\n" /* line 83 */
        "calll Dvar_GetString\n"
        "movl $0x400, 8(%esp)\n" /* line 84 */
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %ebx\n" /* string, pos */
        "movl %ebx, (%esp)\n" /* pos */
        "calll I_strncpyz\n"
        "jmp .Lf1e1cb4_001e1d18\n"
        ".Lf1e1cb4_001e1f5c:\n"
        "movl $0x217ff8, %edi\n" /* line 115 | dots */
        "jmp .Lf1e1cb4_001e1e53\n"
        ".Lf1e1cb4_001e1f66:\n"
        "movl $0x216ca0, %edi\n" /* line 119 | dots */
        "jmp .Lf1e1cb4_001e1e53\n"
        ".Lf1e1cb4_001e1f70:\n"
        "movl $0x2228e0, %edi\n" /* line 115 | dots */
        "jmp .Lf1e1cb4_001e1e53\n"
    );
}

