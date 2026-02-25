/* ASM dump from: dvar_cmds.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/dvar_cmds.cpp */

#include "common_types.h"
#include "imports.h"

static char info1[1024]; /* 0x497f00 */
static char info2[8192]; /* 0x495f00 */

void Dvar_ForEach(void (*callback)());
static void Dvar_GetCombinedString(void);
qboolean Dvar_Command(void);
static Bool Dvar_ToggleInternal(void);
void Dvar_Toggle_f(void);
void Dvar_TogglePrint_f(void);
void Dvar_Set_f(void);
static void Dvar_RegisterBool_f(void);
static void Dvar_RegisterInt_f(void);
static void Dvar_RegisterFloat_f(void);
void Dvar_SetU_f(void);
void Dvar_SetS_f(void);
void Dvar_SetA_f(void);
void Dvar_SetFromDvar_f(void);
void Dvar_Reset_f(void);
void Dvar_WriteVariables(fileHandle_t f);
void Dvar_WriteDefaults(fileHandle_t f);
void Dvar_List_f(void);
void Com_DvarDump(print_msg_type_t type);
void Dvar_Dump_f(void);
void SV_SetConfig(int start, int max, int bit);
char * Dvar_InfoString(int bit);
char * Dvar_InfoString_Big(int bit);
void Dvar_AddCommands(void);

/* line 46 */
__attribute__((naked))
void Dvar_ForEach(void (*callback)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 46 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* callback */
        /* { scope 1 */
        "movl 0x195ed28, %eax\n" /* line 50 */
        "movl (%eax), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf500f8_0005011c\n"
        ".Lf500f8_0005010e:\n"
        "movl (%ebx), %eax\n" /* line 51 | dvar */
        "movl %eax, (%esp)\n"
        "calll *%esi\n" /* callback */
        "movl 0x1c(%ebx), %ebx\n" /* line 50 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf500f8_0005010e\n"
        /* } scope */
        ".Lf500f8_0005011c:\n"
        "addl $0x10, %esp\n" /* line 52 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 55 */
static __attribute__((naked))
void Dvar_GetCombinedString(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* combined */
        "movl %edx, %ebx\n" /* first */
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 59 */
        "movb $0, (%esi)\n" /* line 61 | combined */
        "cmpl %ebx, %eax\n" /* line 63 | i */
        "jg .Lf50124_00050145\n"
        /* } scope */
        ".Lf50124_0005013d:\n"
        "addl $0x2c, %esp\n" /* line 74 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50124_00050145:\n"
        "movl $0, -0x1c(%ebp)\n" /* line 63 | l */
        "movl %eax, -0x24(%ebp)\n"
        "subl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        ".Lf50124_00050155:\n"
        "movl %ebx, (%esp)\n" /* line 65 | i */
        "calll Cmd_Argv\n"
        "leal 1(%eax), %edi\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x1c(%ebp), %eax\n" /* l */
        "leal -1(%ecx, %eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* l */
        "cmpl $0xffd, %eax\n" /* line 66 */
        "jg .Lf50124_0005013d\n"
        "movl %ebx, (%esp)\n" /* line 69 | i */
        "calll Cmd_Argv\n"
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* combined */
        "calll I_strncat\n"
        "cmpl -0x20(%ebp), %ebx\n" /* line 70 | i */
        "je .Lf50124_000501b6\n"
        "movl $0x217914, 8(%esp)\n" /* line 71 */
        "movl $__mh_execute_header, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* combined */
        "calll I_strncat\n"
        ".Lf50124_000501b6:\n"
        "addl $1, %ebx\n" /* line 63 | i */
        "cmpl %ebx, -0x24(%ebp)\n" /* i */
        "jne .Lf50124_00050155\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 74 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 84 */
__attribute__((naked))
qboolean Dvar_Command(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 84 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1010, %esp\n"
        /* { scope 1 */
        "movl $0, (%esp)\n" /* line 90 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "movl %eax, %esi\n" /* dvar */
        "testl %eax, %eax\n" /* line 91 */
        "je .Lf501c6_00050293\n"
        "calll Cmd_Argc\n" /* line 95 */
        "subl $1, %eax\n"
        "je .Lf501c6_00050232\n"
        "leal -0x1008(%ebp), %ebx\n" /* line 105 | combined */
        "movl $1, %edx\n"
        "movl %ebx, %eax\n"
        "calll Dvar_GetCombinedString\n"
        "movl $0, (%esp)\n" /* line 106 */
        "calll Cmd_Argv\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetCommand\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1010, %esp\n" /* line 108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf501c6_00050232:\n"
        "movl %esi, (%esp)\n" /* line 97 | dvar */
        "calll Dvar_DisplayableResetValue\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* dvar */
        "calll Dvar_DisplayableValue\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl (%esi), %eax\n" /* dvar */
        "movl %eax, 4(%esp)\n"
        "movl $0x219078, (%esp)\n" /* ""%s" is: "%s^7" default: "%s^7"
" */
        "calll Com_Printf\n"
        "movl %esi, (%esp)\n" /* line 98 | dvar */
        "calll Dvar_HasLatchedValue\n"
        "testb %al, %al\n"
        "jne .Lf501c6_0005029f\n"
        ".Lf501c6_0005026a:\n"
        "movl 0x14(%esi), %eax\n" /* line 100 | dvar */
        "movl 0x18(%esi), %edx\n" /* dvar */
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movzbl 6(%esi), %eax\n" /* dvar */
        "movl %eax, (%esp)\n"
        "calll Dvar_PrintDomain\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x1010, %esp\n" /* line 108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf501c6_00050293:\n"
        "xorl %eax, %eax\n" /* line 91 */
        /* } scope */
        "addl $0x1010, %esp\n" /* line 108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf501c6_0005029f:\n"
        "movl %esi, (%esp)\n" /* line 99 | dvar */
        "calll Dvar_DisplayableLatchedValue\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21909c, (%esp)\n" /* "latched: "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf501c6_0005026a\n"
    );
}

/* line 176 */
static __attribute__((naked))
Bool Dvar_ToggleInternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 176 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 185 */
        "subl $1, %eax\n"
        "jle .Lf502ba_000503a6\n"
        "movl $1, (%esp)\n" /* line 192 */
        "calll Cmd_Argv\n"
        "movl %eax, -0x20(%ebp)\n" /* dvarName */
        "movl %eax, (%esp)\n" /* line 195 */
        "calll Dvar_FindVar\n"
        "movl %eax, %edi\n" /* dvar */
        "testl %eax, %eax\n" /* line 196 */
        "je .Lf502ba_000503d3\n"
        "calll Cmd_Argc\n" /* line 202 */
        "cmpl $2, %eax\n"
        "je .Lf502ba_00050390\n"
        "movl %edi, (%esp)\n" /* line 205 | dvar */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, -0x1c(%ebp)\n" /* string */
        "movl $2, %ebx\n" /* argString */
        "jmp .Lf502ba_00050327\n"
        ".Lf502ba_00050312:\n"
        "movl %ebx, 4(%esp)\n" /* line 216 | argString */
        "movl -0x1c(%ebp), %ecx\n" /* string */
        "movl %ecx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf502ba_0005036c\n"
        ".Lf502ba_00050325:\n"
        "movl %esi, %ebx\n" /* line 219 | argString */
        ".Lf502ba_00050327:\n"
        "leal 1(%ebx), %esi\n" /* line 206 | argString */
        "calll Cmd_Argc\n"
        "cmpl %esi, %eax\n"
        "jle .Lf502ba_000503f0\n"
        "movl %ebx, (%esp)\n" /* line 208 | argString */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* argString */
        "cmpb $6, 6(%edi)\n" /* line 209 | dvar */
        "jne .Lf502ba_00050312\n"
        "movl %eax, 4(%esp)\n" /* line 211 */
        "movl %edi, (%esp)\n" /* dvar */
        "calll Dvar_IndexStringToEnumString\n"
        "cmpb $0, (%eax)\n" /* line 212 */
        "cmovnel %eax, %ebx\n" /* argString */
        "movl %ebx, 4(%esp)\n" /* line 216 | argString */
        "movl -0x1c(%ebp), %ecx\n" /* string */
        "movl %ecx, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf502ba_00050325\n"
        ".Lf502ba_0005036c:\n"
        "movl %esi, (%esp)\n" /* line 218 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetCommand\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf502ba_00050390:\n"
        "movzbl 6(%edi), %eax\n" /* line 115 */
        "cmpl $8, %eax\n"
        "jbe .Lf502ba_000503cc\n"
        "xorl %eax, %eax\n" /* line 160 */
        ".Lf502ba_0005039b:\n"
        "movzbl %al, %eax\n" /* line 203 */
        /* } scope */
        ".Lf502ba_0005039e:\n"
        "addl $0x2c, %esp\n" /* line 233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf502ba_000503a6:\n"
        "movl $0, (%esp)\n" /* line 188 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2190ac, (%esp)\n" /* "USAGE: %s <variable> <optional value sequence>
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf502ba_000503cc:\n"
        "jmpl *0x2f0220(, %eax, 4)\n" /* line 115 */
        ".Lf502ba_000503d3:\n"
        "movl -0x20(%ebp), %eax\n" /* line 198 | dvarName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2190dc, (%esp)\n" /* "toggle failed: dvar '%s' not found.
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf502ba_000503f0:\n"
        "movl $2, (%esp)\n" /* line 223 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* argString */
        "cmpb $6, 6(%edi)\n" /* line 224 | dvar */
        "je .Lf502ba_00050555\n"
        ".Lf502ba_00050408:\n"
        "movl %ebx, 4(%esp)\n" /* line 231 | argString */
        "movl -0x20(%ebp), %eax\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetCommand\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 233 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl $1, 8(%esp)\n" /* line 118 */
        "xorl %eax, %eax\n"
        "cmpb $0, 8(%edi)\n"
        "sete %al\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetBoolFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        "movss 0x14(%edi), %xmm1\n" /* line 139 */
        "pxor %xmm2, %xmm2\n"
        "ucomiss %xmm1, %xmm2\n"
        "jb .Lf502ba_00050529\n"
        "movss 0x18(%edi), %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jb .Lf502ba_00050529\n"
        "ucomiss 8(%edi), %xmm2\n" /* line 141 */
        "jp .Lf502ba_0005047e\n"
        "je .Lf502ba_000505ea\n"
        ".Lf502ba_0005047e:\n"
        "movl $1, 8(%esp)\n" /* line 142 */
        "movss %xmm2, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetFloatFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        "movl 0x14(%edi), %eax\n" /* line 122 */
        "testl %eax, %eax\n"
        "jle .Lf502ba_000505b3\n"
        ".Lf502ba_000504ac:\n"
        "cmpl 8(%edi), %eax\n" /* line 131 */
        "je .Lf502ba_0005058f\n"
        "movl $1, 8(%esp)\n" /* line 134 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetIntFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        "movl 0x14(%edi), %edx\n" /* line 164 */
        "testl %edx, %edx\n"
        "jne .Lf502ba_00050503\n"
        "movl $1, %eax\n" /* line 165 */
        ".Lf502ba_000504e2:\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        "movl (%edi), %eax\n" /* line 160 */
        "movl %eax, 4(%esp)\n"
        "movl $0x219104, (%esp)\n" /* "'toggle' with no arguments makes no sense for dvar '%s'
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf502ba_0005039b\n"
        ".Lf502ba_00050503:\n"
        "movl $1, 8(%esp)\n" /* line 165 */
        "movl 8(%edi), %eax\n"
        "addl $1, %eax\n"
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetIntFromSource\n"
        "movl $1, %eax\n"
        "jmp .Lf502ba_000504e2\n"
        ".Lf502ba_00050529:\n"
        "ucomiss 8(%edi), %xmm1\n" /* line 148 */
        "jne .Lf502ba_0005056c\n"
        "jp .Lf502ba_0005056c\n"
        "movl $1, 8(%esp)\n" /* line 149 */
        "movl 0x18(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetFloatFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        ".Lf502ba_00050555:\n"
        "movl %eax, 4(%esp)\n" /* line 226 */
        "movl %edi, (%esp)\n" /* dvar */
        "calll Dvar_IndexStringToEnumString\n"
        "cmpb $0, (%eax)\n" /* line 227 */
        "cmovnel %eax, %ebx\n" /* argString */
        "jmp .Lf502ba_00050408\n"
        ".Lf502ba_0005056c:\n"
        "movl $1, 8(%esp)\n" /* line 151 */
        "movss %xmm1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetFloatFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        ".Lf502ba_0005058f:\n"
        "movl $1, 8(%esp)\n" /* line 132 */
        "movl 0x18(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetIntFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        ".Lf502ba_000505b3:\n"
        "movl 0x18(%edi), %edx\n" /* line 122 */
        "testl %edx, %edx\n"
        "jle .Lf502ba_000504ac\n"
        "movl 8(%edi), %eax\n" /* line 124 */
        "testl %eax, %eax\n"
        "je .Lf502ba_0005060f\n"
        "movl $1, 8(%esp)\n" /* line 125 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetIntFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        ".Lf502ba_000505ea:\n"
        "movl $1, 8(%esp)\n" /* line 144 */
        "movl $0x3f800000, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetFloatFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
        ".Lf502ba_0005060f:\n"
        "movl $1, 8(%esp)\n" /* line 127 */
        "movl $1, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Dvar_SetIntFromSource\n"
        "movl $1, %eax\n"
        "movzbl %al, %eax\n" /* line 203 */
        "jmp .Lf502ba_0005039e\n"
    );
}

/* line 244 */
__attribute__((naked))
void Dvar_Toggle_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 244 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll Dvar_ToggleInternal\n" /* line 246 */
        "leave\n" /* line 247 */
        "retl\n"
    );
}

/* line 258 */
__attribute__((naked))
void Dvar_TogglePrint_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 258 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "calll Dvar_ToggleInternal\n" /* line 264 */
        "testb %al, %al\n"
        "je .Lf50642_00050684\n"
        "movl $1, (%esp)\n" /* line 268 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n"
        "movl %eax, (%esp)\n" /* line 270 */
        "calll Dvar_FindVar\n"
        "movl %eax, (%esp)\n" /* line 272 */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 8(%esp)\n" /* line 274 */
        "movl %ebx, 4(%esp)\n"
        "movl $0x219140, (%esp)\n" /* "%s toggled to %s
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50642_00050684:\n"
        "addl $0x14, %esp\n" /* line 275 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 287 */
__attribute__((naked))
void Dvar_Set_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 287 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x1014, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 293 */
        "cmpl $2, %eax\n" /* line 294 */
        "jg .Lf5068a_000506b3\n"
        "movl $0x219154, (%esp)\n" /* line 296 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1014, %esp\n" /* line 309 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5068a_000506b3:\n"
        "movl $1, (%esp)\n" /* line 300 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n" /* line 301 */
        "calll Dvar_IsValidName\n"
        "testb %al, %al\n"
        "je .Lf5068a_000506fe\n"
        "leal -0x1008(%ebp), %ebx\n" /* line 307 | combined */
        "movl $2, %edx\n"
        "movl %ebx, %eax\n"
        "calll Dvar_GetCombinedString\n"
        "movl $1, (%esp)\n" /* line 308 */
        "calll Cmd_Argv\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetCommand\n"
        /* } scope */
        "addl $0x1014, %esp\n" /* line 309 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf5068a_000506fe:\n"
        "movl $1, (%esp)\n" /* line 303 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x219174, (%esp)\n" /* "invalid variable name: %s
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1014, %esp\n" /* line 309 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 312 */
static __attribute__((naked))
void Dvar_RegisterBool_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 312 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 319 */
        "cmpl $3, %eax\n" /* line 320 */
        "je .Lf50724_00050759\n"
        "movl $0, (%esp)\n" /* line 322 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x219190, (%esp)\n" /* "USAGE: %s <name> <default>
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50724_00050752:\n"
        "addl $0x10, %esp\n" /* line 337 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50724_00050759:\n"
        "movl $1, (%esp)\n" /* line 326 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* dvarName */
        "movl $2, (%esp)\n" /* line 327 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movl %eax, %esi\n" /* value */
        "movl %ebx, (%esp)\n" /* line 328 | dvarName */
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 329 */
        "je .Lf50724_000507ba\n"
        "movzbl 6(%eax), %edx\n"
        "cmpb $7, %dl\n"
        "je .Lf50724_000507b4\n"
        "testb %dl, %dl\n" /* line 335 */
        "je .Lf50724_00050752\n"
        ".Lf50724_0005079b:\n"
        "movl (%eax), %eax\n" /* line 336 */
        "movl %eax, 4(%esp)\n"
        "movl $0x2191ac, (%esp)\n" /* "dvar '%s' is not a boolean dvar
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 337 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50724_000507b4:\n"
        "testb $0x40, 5(%eax)\n" /* line 329 */
        "je .Lf50724_0005079b\n"
        ".Lf50724_000507ba:\n"
        "movl $0x4000, 8(%esp)\n" /* line 331 */
        "movl %esi, %edx\n" /* value */
        "movzbl %dl, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dvarName */
        "calll Dvar_RegisterBool\n"
        "jmp .Lf50724_00050752\n"
    );
}

/* line 340 */
static __attribute__((naked))
void Dvar_RegisterInt_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 340 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 349 */
        "cmpl $5, %eax\n" /* line 350 */
        "je .Lf507d8_0005080f\n"
        "movl $0, (%esp)\n" /* line 352 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2191d0, (%esp)\n" /* "USAGE: %s <name> <default> <min> <max>
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf507d8_00050807:\n"
        "addl $0x3c, %esp\n" /* line 375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf507d8_0005080f:\n"
        "movl $1, (%esp)\n" /* line 356 */
        "calll Cmd_Argv\n"
        "movl %eax, %edi\n" /* dvarName */
        "movl $2, (%esp)\n" /* line 357 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x1c(%ebp)\n" /* value */
        "movl $3, (%esp)\n" /* line 358 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %esi\n" /* min */
        "movl $4, (%esp)\n" /* line 359 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* max */
        "cmpl %eax, %esi\n" /* line 360 | min */
        "jg .Lf507d8_00050897\n"
        "movl %edi, (%esp)\n" /* line 366 | dvarName */
        "calll Dvar_FindVar\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 367 */
        "je .Lf507d8_000508bd\n"
        "movzbl 6(%eax), %eax\n"
        "cmpb $7, %al\n"
        "je .Lf507d8_000508b7\n"
        ".Lf507d8_0005087a:\n"
        "subb $5, %al\n" /* line 373 */
        "cmpb $1, %al\n"
        "jbe .Lf507d8_00050807\n"
        "movl (%edx), %eax\n" /* line 374 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21922c, (%esp)\n" /* "dvar '%s' is not an integer dvar
" */
        "calll Com_Printf\n"
        "jmp .Lf507d8_00050807\n"
        ".Lf507d8_00050897:\n"
        "movl %eax, 0xc(%esp)\n" /* line 362 */
        "movl %esi, 8(%esp)\n" /* min */
        "movl %edi, 4(%esp)\n" /* dvarName */
        "movl $0x2191f8, (%esp)\n" /* "dvar %s: min %i should not be greater than max %i
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf507d8_000508b7:\n"
        "testb $0x40, 5(%edx)\n" /* line 367 */
        "je .Lf507d8_0005087a\n"
        ".Lf507d8_000508bd:\n"
        "movl $0x4000, 0x10(%esp)\n" /* line 369 */
        "movl %ebx, 0xc(%esp)\n" /* max */
        "movl %esi, 8(%esp)\n" /* min */
        "movl -0x1c(%ebp), %eax\n" /* value */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* dvarName */
        "calll Dvar_RegisterInt\n"
        "jmp .Lf507d8_00050807\n"
    );
}

/* line 378 */
static __attribute__((naked))
void Dvar_RegisterFloat_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 378 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 387 */
        "cmpl $5, %eax\n" /* line 388 */
        "je .Lf508e2_00050915\n"
        "movl $0, (%esp)\n" /* line 390 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2191d0, (%esp)\n" /* "USAGE: %s <name> <default> <min> <max>
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf508e2_0005090f:\n"
        "addl $0x54, %esp\n" /* line 413 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf508e2_00050915:\n"
        "movl $1, (%esp)\n" /* line 394 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* dvarName */
        "movl $2, (%esp)\n" /* line 395 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x30(%ebp)\n"
        "cvtsd2ss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* value */
        "movl $3, (%esp)\n" /* line 396 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x28(%ebp)\n"
        "cvtsd2ss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n" /* min */
        "movl $4, (%esp)\n" /* line 397 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x20(%ebp)\n"
        "cvtsd2ss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n" /* max */
        "movss -0x10(%ebp), %xmm0\n" /* line 398 | min */
        "ucomiss -0xc(%ebp), %xmm0\n" /* max */
        "ja .Lf508e2_000509c6\n"
        "movl %ebx, (%esp)\n" /* line 404 | dvarName */
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 405 */
        "je .Lf508e2_000509f8\n"
        "movzbl 6(%eax), %edx\n"
        "cmpb $7, %dl\n"
        "je .Lf508e2_000509f2\n"
        "subb $1, %dl\n" /* line 411 */
        "je .Lf508e2_0005090f\n"
        ".Lf508e2_000509af:\n"
        "movl (%eax), %eax\n" /* line 412 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21922c, (%esp)\n" /* "dvar '%s' is not an integer dvar
" */
        "calll Com_Printf\n"
        "jmp .Lf508e2_0005090f\n"
        ".Lf508e2_000509c6:\n"
        "cvtss2sd -0xc(%ebp), %xmm0\n" /* line 400 | max */
        "movsd %xmm0, 0x10(%esp)\n"
        "cvtss2sd -0x10(%ebp), %xmm0\n" /* min */
        "movsd %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* dvarName */
        "movl $0x219250, (%esp)\n" /* "dvar %s: min %g should not be greater than max %g
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 413 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf508e2_000509f2:\n"
        "testb $0x40, 5(%eax)\n" /* line 405 */
        "je .Lf508e2_000509af\n"
        ".Lf508e2_000509f8:\n"
        "movl $0x4000, 0x10(%esp)\n" /* line 407 */
        "movss -0xc(%ebp), %xmm0\n" /* max */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x10(%ebp), %xmm0\n" /* min */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x14(%ebp), %xmm0\n" /* value */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dvarName */
        "calll Dvar_RegisterFloat\n"
        "jmp .Lf508e2_0005090f\n"
    );
}

/* line 425 */
__attribute__((naked))
void Dvar_SetU_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 425 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 429 */
        "cmpl $2, %eax\n"
        "jg .Lf50a2e_00050a4c\n"
        "movl $0x219284, (%esp)\n" /* line 431 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50a2e_00050a4a:\n"
        "leave\n" /* line 441 */
        "retl\n"
        /* { scope 1 */
        ".Lf50a2e_00050a4c:\n"
        "calll Dvar_Set_f\n" /* line 434 */
        "movl $1, (%esp)\n" /* line 435 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 436 */
        "je .Lf50a2e_00050a4a\n"
        "movl $2, 4(%esp)\n" /* line 440 */
        "movl %eax, (%esp)\n"
        "calll Dvar_AddFlags\n"
        /* } scope */
        "leave\n" /* line 441 */
        "retl\n"
    );
}

/* line 453 */
__attribute__((naked))
void Dvar_SetS_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 453 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 457 */
        "cmpl $2, %eax\n"
        "jg .Lf50a7c_00050a9a\n"
        "movl $0x2192a4, (%esp)\n" /* line 459 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50a7c_00050a98:\n"
        "leave\n" /* line 468 */
        "retl\n"
        /* { scope 1 */
        ".Lf50a7c_00050a9a:\n"
        "calll Dvar_Set_f\n" /* line 462 */
        "movl $1, (%esp)\n" /* line 463 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 464 */
        "je .Lf50a7c_00050a98\n"
        "movl $4, 4(%esp)\n" /* line 467 */
        "movl %eax, (%esp)\n"
        "calll Dvar_AddFlags\n"
        /* } scope */
        "leave\n" /* line 468 */
        "retl\n"
    );
}

/* line 478 */
__attribute__((naked))
void Dvar_SetA_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 478 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 482 */
        "cmpl $2, %eax\n"
        "jg .Lf50aca_00050ae8\n"
        "movl $0x2192c4, (%esp)\n" /* line 484 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50aca_00050ae6:\n"
        "leave\n" /* line 493 */
        "retl\n"
        /* { scope 1 */
        ".Lf50aca_00050ae8:\n"
        "calll Dvar_Set_f\n" /* line 487 */
        "movl $1, (%esp)\n" /* line 488 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 489 */
        "je .Lf50aca_00050ae6\n"
        "movl $1, 4(%esp)\n" /* line 492 */
        "movl %eax, (%esp)\n"
        "calll Dvar_AddFlags\n"
        /* } scope */
        "leave\n" /* line 493 */
        "retl\n"
    );
}

/* line 501 */
__attribute__((naked))
void Dvar_SetFromDvar_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 501 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 505 */
        "cmpl $3, %eax\n"
        "je .Lf50b18_00050b3b\n"
        "movl $0x2192e4, (%esp)\n" /* line 507 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50b18_00050b35:\n"
        "addl $0x14, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50b18_00050b3b:\n"
        "movl $2, (%esp)\n" /* line 511 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 512 */
        "je .Lf50b18_00050b7b\n"
        "movl %eax, (%esp)\n" /* line 518 */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, %ebx\n"
        "movl $1, (%esp)\n"
        "calll Cmd_Argv\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetCommand\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50b18_00050b7b:\n"
        "movl $2, (%esp)\n" /* line 514 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x219314, (%esp)\n" /* "dvar '%s' doesn't exist
" */
        "calll Com_Printf\n"
        "jmp .Lf50b18_00050b35\n"
    );
}

/* line 527 */
__attribute__((naked))
void Dvar_Reset_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 527 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 531 */
        "cmpl $2, %eax\n"
        "je .Lf50b9a_00050bb8\n"
        "movl $0x219330, (%esp)\n" /* line 533 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf50b9a_00050bb6:\n"
        "leave\n" /* line 542 */
        "retl\n"
        /* { scope 1 */
        ".Lf50b9a_00050bb8:\n"
        "movl $1, (%esp)\n" /* line 537 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 538 */
        "je .Lf50b9a_00050bb6\n"
        "movl $1, 4(%esp)\n" /* line 541 */
        "movl %eax, (%esp)\n"
        "calll Dvar_Reset\n"
        /* } scope */
        "leave\n" /* line 542 */
        "retl\n"
    );
}

/* line 553 */
__attribute__((naked))
void Dvar_WriteVariables(fileHandle_t f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 553 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0x195ed28, %eax\n" /* line 557 */
        "movl (%eax), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf50be2_00050bfd\n"
        "jmp .Lf50be2_00050c45\n"
        ".Lf50be2_00050bf6:\n"
        "movl 0x1c(%ebx), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf50be2_00050c45\n"
        ".Lf50be2_00050bfd:\n"
        "movl $0x21934c, 4(%esp)\n" /* line 559 */
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf50be2_00050bf6\n"
        "testb $1, 4(%ebx)\n" /* line 561 | dvar */
        "je .Lf50be2_00050bf6\n"
        "movl %ebx, (%esp)\n" /* line 566 | dvar */
        "calll Dvar_DisplayableLatchedValue\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, 8(%esp)\n"
        "movl $0x219358, 4(%esp)\n" /* "seta %s "%s"
" */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 557 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf50be2_00050bfd\n"
        /* } scope */
        ".Lf50be2_00050c45:\n"
        "addl $0x14, %esp\n" /* line 568 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 579 */
__attribute__((naked))
void Dvar_WriteDefaults(fileHandle_t f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 579 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 0x195ed28, %eax\n" /* line 583 */
        "movl (%eax), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf50c4c_00050c67\n"
        "jmp .Lf50c4c_00050cb4\n"
        ".Lf50c4c_00050c60:\n"
        "movl 0x1c(%ebx), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf50c4c_00050cb4\n"
        ".Lf50c4c_00050c67:\n"
        "movl $0x21934c, 4(%esp)\n" /* line 585 */
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf50c4c_00050c60\n"
        "movzwl 4(%ebx), %eax\n" /* line 587 | dvar */
        "testl $0x40c0, %eax\n"
        "jne .Lf50c4c_00050c60\n"
        "movl %ebx, (%esp)\n" /* line 589 | dvar */
        "calll Dvar_DisplayableResetValue\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, 8(%esp)\n"
        "movl $0x219368, 4(%esp)\n" /* "set %s "%s"
" */
        "movl 8(%ebp), %eax\n" /* f */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 583 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf50c4c_00050c67\n"
        /* } scope */
        ".Lf50c4c_00050cb4:\n"
        "addl $0x14, %esp\n" /* line 591 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 599 */
__attribute__((naked))
void Dvar_List_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 599 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 604 */
        "subl $1, %eax\n"
        "jle .Lf50cba_00050e8b\n"
        "movl $1, (%esp)\n" /* line 606 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n" /* match */
        ".Lf50cba_00050cde:\n"
        "movl 0x195ed28, %eax\n" /* line 613 */
        "movl (%eax), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf50cba_00050dab\n"
        "jmp .Lf50cba_00050e6d\n"
        ".Lf50cba_00050cf2:\n"
        "movl $0x219378, (%esp)\n" /* line 623 */
        "calll Com_Printf\n"
        "testb $2, 4(%ebx)\n" /* line 627 | dvar */
        "je .Lf50cba_00050dee\n"
        ".Lf50cba_00050d08:\n"
        "movl $0x21937c, (%esp)\n" /* line 628 */
        "calll Com_Printf\n"
        "testb $0x40, 4(%ebx)\n" /* line 632 | dvar */
        "je .Lf50cba_00050e04\n"
        ".Lf50cba_00050d1e:\n"
        "movl $0x219380, (%esp)\n" /* line 633 */
        "calll Com_Printf\n"
        "testb $0x10, 4(%ebx)\n" /* line 636 | dvar */
        "je .Lf50cba_00050e1a\n"
        ".Lf50cba_00050d34:\n"
        "movl $0x219384, (%esp)\n" /* line 637 */
        "calll Com_Printf\n"
        "testb $1, 4(%ebx)\n" /* line 640 | dvar */
        "je .Lf50cba_00050e30\n"
        ".Lf50cba_00050d4a:\n"
        "movl $0x219388, (%esp)\n" /* line 641 */
        "calll Com_Printf\n"
        "testb $0x20, 4(%ebx)\n" /* line 644 | dvar */
        "je .Lf50cba_00050e46\n"
        ".Lf50cba_00050d60:\n"
        "movl $0x21938c, (%esp)\n" /* line 645 */
        "calll Com_Printf\n"
        "cmpb $0, 4(%ebx)\n" /* line 648 | dvar */
        "jns .Lf50cba_00050e5c\n"
        ".Lf50cba_00050d76:\n"
        "movl $0x219390, (%esp)\n" /* line 649 */
        "calll Com_Printf\n"
        ".Lf50cba_00050d82:\n"
        "movl %ebx, (%esp)\n" /* line 653 | dvar */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, 4(%esp)\n"
        "movl $0x219394, (%esp)\n" /* " %s "%s"
" */
        "calll Com_Printf\n"
        ".Lf50cba_00050da0:\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 613 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf50cba_00050e6d\n"
        ".Lf50cba_00050dab:\n"
        "testl %esi, %esi\n" /* line 615 | match */
        "je .Lf50cba_00050dc9\n"
        "movl $0, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* match */
        "calll Com_Filter\n"
        "testb %al, %al\n"
        "je .Lf50cba_00050da0\n"
        ".Lf50cba_00050dc9:\n"
        "movzwl 4(%ebx), %eax\n" /* line 619 | dvar */
        "testl $0x404, %eax\n"
        "jne .Lf50cba_00050cf2\n"
        "movl $0x217914, (%esp)\n" /* line 625 */
        "calll Com_Printf\n"
        "testb $2, 4(%ebx)\n" /* line 627 | dvar */
        "jne .Lf50cba_00050d08\n"
        ".Lf50cba_00050dee:\n"
        "movl $0x217914, (%esp)\n" /* line 631 */
        "calll Com_Printf\n"
        "testb $0x40, 4(%ebx)\n" /* line 632 | dvar */
        "jne .Lf50cba_00050d1e\n"
        ".Lf50cba_00050e04:\n"
        "movl $0x217914, (%esp)\n" /* line 635 */
        "calll Com_Printf\n"
        "testb $0x10, 4(%ebx)\n" /* line 636 | dvar */
        "jne .Lf50cba_00050d34\n"
        ".Lf50cba_00050e1a:\n"
        "movl $0x217914, (%esp)\n" /* line 639 */
        "calll Com_Printf\n"
        "testb $1, 4(%ebx)\n" /* line 640 | dvar */
        "jne .Lf50cba_00050d4a\n"
        ".Lf50cba_00050e30:\n"
        "movl $0x217914, (%esp)\n" /* line 643 */
        "calll Com_Printf\n"
        "testb $0x20, 4(%ebx)\n" /* line 644 | dvar */
        "jne .Lf50cba_00050d60\n"
        ".Lf50cba_00050e46:\n"
        "movl $0x217914, (%esp)\n" /* line 647 */
        "calll Com_Printf\n"
        "cmpb $0, 4(%ebx)\n" /* line 648 | dvar */
        "js .Lf50cba_00050d76\n"
        ".Lf50cba_00050e5c:\n"
        "movl $0x217914, (%esp)\n" /* line 651 */
        "calll Com_Printf\n"
        "jmp .Lf50cba_00050d82\n"
        ".Lf50cba_00050e6d:\n"
        "movl 0x195ed24, %eax\n" /* line 656 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2193a0, (%esp)\n" /* "
%i total dvars
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 657 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50cba_00050e8b:\n"
        "xorl %esi, %esi\n" /* line 604 | match */
        "jmp .Lf50cba_00050cde\n"
    );
}

/* line 691 */
__attribute__((naked))
void Com_DvarDump(print_msg_type_t type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 691 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x203c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 698 */
        "subl $1, %eax\n"
        "jle .Lf50e92_000510de\n"
        "movl $1, (%esp)\n" /* line 700 */
        "calll Cmd_Argv\n"
        "movl %eax, -0x201c(%ebp)\n" /* match */
        ".Lf50e92_00050ebe:\n"
        "movl 8(%ebp), %esi\n" /* line 707 | type */
        "testl %esi, %esi\n"
        "jne .Lf50e92_00050edf\n"
        "movl 0x195ed20, %eax\n" /* line 709 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf50e92_00050fd3\n"
        "movl 8(%eax), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf50e92_00050fd3\n"
        ".Lf50e92_00050edf:\n"
        "movl $0x2193b4, 4(%esp)\n" /* line 714 */
        "movl 8(%ebp), %eax\n" /* type */
        "movl %eax, (%esp)\n"
        "calll Com_PrintMessage\n"
        "movl 0x195ed28, %eax\n" /* line 715 */
        "movl (%eax), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf50e92_000510ed\n"
        "xorl %edi, %edi\n" /* i */
        "movl -0x201c(%ebp), %ecx\n" /* match */
        "testl %ecx, %ecx\n"
        "jne .Lf50e92_0005104f\n"
        ".Lf50e92_00050f11:\n"
        "movl %ebx, (%esp)\n" /* line 720 | var */
        "calll Dvar_HasLatchedValue\n"
        "testb %al, %al\n"
        "je .Lf50e92_00051074\n"
        "movl %ebx, (%esp)\n" /* line 721 | var */
        "calll Dvar_DisplayableLatchedValue\n"
        "movl %eax, %esi\n"
        "movl %ebx, (%esp)\n" /* var */
        "calll Dvar_DisplayableValue\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x219408, 8(%esp)\n" /* "      %s "%s" -- latched "%s"
" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* message */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf50e92_00050f5f:\n"
        "leal -0x2018(%ebp), %eax\n" /* line 724 | message */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* type */
        "movl %eax, (%esp)\n"
        "calll Com_PrintMessage\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 715 | var */
        "addl $1, %edi\n" /* i */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf50e92_00050f11\n"
        ".Lf50e92_00050f7e:\n"
        "movl 0x195ed24, %eax\n" /* line 727 */
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* i */
        "movl $0x219438, 8(%esp)\n" /* "
%i total dvars
%i dvar indexes
" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* message */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x2018(%ebp), %eax\n" /* line 728 | message */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* type */
        "movl %eax, (%esp)\n"
        "calll Com_PrintMessage\n"
        "movl $0x21945c, 4(%esp)\n" /* line 729 */
        "movl 8(%ebp), %eax\n" /* type */
        "movl %eax, (%esp)\n"
        "calll Com_PrintMessage\n"
        /* } scope */
        ".Lf50e92_00050fd3:\n"
        "addl $0x203c, %esp\n" /* line 730 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf50e92_00050fde:\n"
        "movl %ebx, (%esp)\n" /* line 720 | var */
        "calll Dvar_HasLatchedValue\n"
        "testb %al, %al\n"
        "je .Lf50e92_000510a9\n"
        "movl %ebx, (%esp)\n" /* line 721 | var */
        "calll Dvar_DisplayableLatchedValue\n"
        "movl %eax, %esi\n"
        "movl %ebx, (%esp)\n" /* var */
        "calll Dvar_DisplayableValue\n"
        "movl %esi, 0x14(%esp)\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x219408, 8(%esp)\n" /* "      %s "%s" -- latched "%s"
" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* message */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf50e92_0005102c:\n"
        "leal -0x2018(%ebp), %eax\n" /* line 724 | message */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* type */
        "movl %eax, (%esp)\n"
        "calll Com_PrintMessage\n"
        ".Lf50e92_00051041:\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 715 | var */
        "addl $1, %edi\n" /* i */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf50e92_00050f7e\n"
        ".Lf50e92_0005104f:\n"
        "movl $0, 8(%esp)\n" /* line 717 */
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 4(%esp)\n"
        "movl -0x201c(%ebp), %eax\n" /* match */
        "movl %eax, (%esp)\n"
        "calll Com_Filter\n"
        "testb %al, %al\n"
        "je .Lf50e92_00051041\n"
        "jmp .Lf50e92_00050fde\n"
        ".Lf50e92_00051074:\n"
        "movl %ebx, (%esp)\n" /* line 723 | var */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x219428, 8(%esp)\n" /* "      %s "%s"
" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* message */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf50e92_00050f5f\n"
        ".Lf50e92_000510a9:\n"
        "movl %ebx, (%esp)\n" /* var */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x219428, 8(%esp)\n" /* "      %s "%s"
" */
        "movl $0x2000, 4(%esp)\n"
        "leal -0x2018(%ebp), %eax\n" /* message */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf50e92_0005102c\n"
        ".Lf50e92_000510de:\n"
        "movl $0, -0x201c(%ebp)\n" /* line 698 | match */
        "jmp .Lf50e92_00050ebe\n"
        ".Lf50e92_000510ed:\n"
        "xorl %edi, %edi\n" /* line 715 | i */
        "jmp .Lf50e92_00050f7e\n"
    );
}

/* line 738 */
__attribute__((naked))
void Dvar_Dump_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 738 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 740 */
        "calll Com_DvarDump\n"
        "leave\n" /* line 741 */
        "retl\n"
    );
}

/* line 751 */
__attribute__((naked))
void SV_SetConfig(int start, int max, int bit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 751 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* max */
        "movl 0x10(%ebp), %esi\n" /* bit */
        /* { scope 1 */
        "movl 0x195ed28, %eax\n" /* line 755 */
        "movl (%eax), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf51108_0005112b\n"
        "jmp .Lf51108_0005115b\n"
        ".Lf51108_00051124:\n"
        "movl 0x1c(%ebx), %ebx\n" /* dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "je .Lf51108_0005115b\n"
        ".Lf51108_0005112b:\n"
        "movzwl 4(%ebx), %eax\n" /* line 757 | dvar */
        "testl %esi, %eax\n" /* bit */
        "je .Lf51108_00051124\n"
        "movl %ebx, (%esp)\n" /* line 758 | dvar */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%ebx), %eax\n" /* dvar */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* max */
        "movl 8(%ebp), %eax\n" /* start */
        "movl %eax, (%esp)\n"
        "calll SV_SetConfigValueForKey\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 755 | dvar */
        "testl %ebx, %ebx\n" /* dvar */
        "jne .Lf51108_0005112b\n"
        /* } scope */
        ".Lf51108_0005115b:\n"
        "addl $0x1c, %esp\n" /* line 760 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 770 */
__attribute__((naked))
char * Dvar_InfoString(int bit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 770 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* bit */
        /* { scope 1 */
        "movb $0, info1\n" /* line 778 */
        "movl 0x195ed28, %eax\n" /* line 780 */
        "movl (%eax), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf51164_0005118a\n"
        "jmp .Lf51164_000511b7\n"
        ".Lf51164_00051183:\n"
        "movl 0x1c(%ebx), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf51164_000511b7\n"
        ".Lf51164_0005118a:\n"
        "movzwl 4(%ebx), %eax\n" /* line 782 | var */
        "testl %eax, %esi\n" /* bit */
        "je .Lf51164_00051183\n"
        "movl %ebx, (%esp)\n" /* line 783 | var */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 4(%esp)\n"
        "movl $info1, (%esp)\n"
        "calll Info_SetValueForKey\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 780 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf51164_0005118a\n"
        ".Lf51164_000511b7:\n"
        "andl $2, %esi\n" /* line 786 | bit */
        "je .Lf51164_000511e0\n"
        "movl $0, (%esp)\n" /* line 796 */
        "calll CL_GetUsernameForLocalClient\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2194b4, 4(%esp)\n" /* "name" */
        "movl $info1, (%esp)\n"
        "calll Info_SetValueForKey\n"
        /* } scope */
        ".Lf51164_000511e0:\n"
        "movl $info1, %eax\n" /* line 805 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 815 */
__attribute__((naked))
char * Dvar_InfoString_Big(int bit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 815 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* bit */
        /* { scope 1 */
        "movb $0, info2\n" /* line 819 */
        "movl 0x195ed28, %eax\n" /* line 821 */
        "movl (%eax), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf511ec_00051212\n"
        "jmp .Lf511ec_0005123f\n"
        ".Lf511ec_0005120b:\n"
        "movl 0x1c(%ebx), %ebx\n" /* var */
        "testl %ebx, %ebx\n" /* var */
        "je .Lf511ec_0005123f\n"
        ".Lf511ec_00051212:\n"
        "movzwl 4(%ebx), %eax\n" /* line 823 | var */
        "testl %esi, %eax\n" /* bit */
        "je .Lf511ec_0005120b\n"
        "movl %ebx, (%esp)\n" /* line 824 | var */
        "calll Dvar_DisplayableValue\n"
        "movl %eax, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* var */
        "movl %eax, 4(%esp)\n"
        "movl $info2, (%esp)\n"
        "calll Info_SetValueForKey_Big\n"
        "movl 0x1c(%ebx), %ebx\n" /* line 821 | var */
        "testl %ebx, %ebx\n" /* var */
        "jne .Lf511ec_00051212\n"
        /* } scope */
        ".Lf511ec_0005123f:\n"
        "movl $info2, %eax\n" /* line 827 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 837 */
__attribute__((naked))
void Dvar_AddCommands(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 837 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $Dvar_Toggle_f, 4(%esp)\n" /* line 839 */
        "movl $0x215d3c, (%esp)\n" /* "toggle" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_TogglePrint_f, 4(%esp)\n" /* line 840 */
        "movl $0x2194bc, (%esp)\n" /* "togglep" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_Set_f, 4(%esp)\n" /* line 841 */
        "movl $0x2160dc, (%esp)\n" /* "set" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_SetS_f, 4(%esp)\n" /* line 842 */
        "movl $0x2194c4, (%esp)\n" /* "sets" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_SetA_f, 4(%esp)\n" /* line 843 */
        "movl $0x2160e0, (%esp)\n" /* "seta" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_SetFromDvar_f, 4(%esp)\n" /* line 844 */
        "movl $0x2194cc, (%esp)\n" /* "setfromdvar" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_Reset_f, 4(%esp)\n" /* line 845 */
        "movl $0x2194d8, (%esp)\n" /* "reset" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_List_f, 4(%esp)\n" /* line 846 */
        "movl $0x2194e0, (%esp)\n" /* "dvarlist" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_Dump_f, 4(%esp)\n" /* line 847 */
        "movl $0x2194ec, (%esp)\n" /* "dvardump" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_RegisterBool_f, 4(%esp)\n" /* line 849 */
        "movl $0x2194f8, (%esp)\n" /* "dvar_bool" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_RegisterInt_f, 4(%esp)\n" /* line 850 */
        "movl $0x219504, (%esp)\n" /* "dvar_int" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_RegisterFloat_f, 4(%esp)\n" /* line 851 */
        "movl $0x219510, (%esp)\n" /* "dvar_float" */
        "calll Cmd_AddCommand\n"
        "movl $Dvar_SetU_f, 4(%esp)\n" /* line 853 */
        "movl $0x21951c, (%esp)\n" /* "setu" */
        "calll Cmd_AddCommand\n"
        "leave\n" /* line 857 */
        "retl\n"
    );
}

