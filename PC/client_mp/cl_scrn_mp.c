/* ASM dump from: cl_scrn_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_scrn_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern qboolean scr_initialized; /* 0x0 */
extern Bool updateScreenCalled; /* 0x0 */
static const char * szShotName[6]; /* 0x312604 */

void SCR_DrawSmallStringExt(int x, int y, const char *string, const vec_t *setColor);
void SCR_DrawConsoleString(int x, int y, const short int *string, int maxChars, const vec_t *setColor);
void SCR_Init(void);
float CL_GetMenuBlurRadius(void);
static void CL_CubemapShotUsage(void);
void CL_CubemapShot_f(void);
static void SCR_UpdateFrame(void);
void SCR_UpdateScreenInternal(void);
void SCR_UpdateScreen(void);

/* line 77 */
__attribute__((naked))
void SCR_DrawSmallStringExt(int x, int y, const char *string, const vec_t *setColor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x195eca8, %esi\n" /* line 83 */
        "movl 0x195ecac, %ebx\n"
        "movl 0x2a0a60(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x118(%esi)\n"
        "movl $0, 0x20(%esp)\n" /* line 84 */
        "movl 0x14(%ebp), %edx\n" /* setColor */
        "movl %edx, 0x1c(%esp)\n"
        "movl $0x3f800000, %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "cvtsi2ssl 0xc(%ebp), %xmm0\n" /* y */
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x2a0a60(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll *0x11c(%esi)\n"
        "addl $0x30, %esp\n" /* line 85 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 96 */
__attribute__((naked))
void SCR_DrawConsoleString(int x, int y, const short int *string, int maxChars, const vec_t *setColor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 0x195eca8, %esi\n" /* line 102 */
        "movl 0x195ecac, %ebx\n"
        "movl 0x2a0a60(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x118(%esi)\n"
        "movl $0, 0x20(%esp)\n" /* line 103 */
        "movl 0x18(%ebp), %edx\n" /* setColor */
        "movl %edx, 0x1c(%esp)\n"
        "movl $0x3f800000, %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "cvtsi2ssl 0xc(%ebp), %xmm0\n" /* y */
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x2a0a60(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll *0x128(%esi)\n"
        "addl $0x30, %esp\n" /* line 104 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
void SCR_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "movl $1, scr_initialized\n" /* line 142 */
        "popl %ebp\n" /* line 143 */
        "retl\n"
    );
}

/* line 302 */
__attribute__((naked))
float CL_GetMenuBlurRadius(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 302 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 304 */
        "movl (%eax), %eax\n"
        "testb $8, 4(%eax)\n"
        "je .Lf1712c8_001712f9\n"
        "movl 0x195ecac, %eax\n"
        "movl 0x110(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1712c8_001712f9\n"
        "movl 0x195ee8c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl $1, (%eax)\n"
        "je .Lf1712c8_001712f9\n"
        "popl %ebp\n" /* line 308 */
        "jmp UI_GetBlurRadius\n" /* line 305 */
        ".Lf1712c8_001712f9:\n"
        "fldz\n"
        "popl %ebp\n" /* line 308 */
        "retl\n"
    );
}

/* line 451 */
static __attribute__((naked))
void CL_CubemapShotUsage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 451 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2aca1c, (%esp)\n" /* line 453 */
        "calll Com_Printf\n"
        "movl $0x2aca70, (%esp)\n" /* line 454 */
        "calll Com_Printf\n"
        "movl $0x2aca9c, (%esp)\n" /* line 455 */
        "calll Com_Printf\n"
        "movl $0x28, 4(%esp)\n" /* line 456 */
        "movl $0x2acad8, (%esp)\n" /* "basefilename must not exceed %i chars
" */
        "calll Com_Printf\n"
        "movl $0x2acb00, (%esp)\n" /* line 457 */
        "calll Com_Printf\n"
        "movl $0x2acb5c, (%esp)\n" /* line 458 */
        "calll Com_Printf\n"
        "movl $0x2acbb8, (%esp)\n" /* line 459 */
        "calll Com_Printf\n"
        "movl $0x2acc18, (%esp)\n" /* line 460 */
        "calll Com_Printf\n"
        "movl $0x2acc70, (%esp)\n" /* line 461 */
        "calll Com_Printf\n"
        "movl $0x2acca8, (%esp)\n" /* line 462 */
        "calll Com_Printf\n"
        "leave\n" /* line 463 */
        "retl\n"
    );
}

/* line 471 */
__attribute__((naked))
void CL_CubemapShot_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 471 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1 */
        "movl 0x195ee78, %eax\n" /* line 484 */
        "movl (%eax), %eax\n"
        "cmpb $0, 9(%eax)\n"
        "jne .Lf171386_001713b6\n"
        "movl $0x2acd18, (%esp)\n" /* line 486 */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf171386_001713ab:\n"
        "addl $0xbc, %esp\n" /* line 562 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf171386_001713b6:\n"
        "calll Cmd_Argc\n" /* line 490 */
        "cmpl $2, %eax\n"
        "jg .Lf171386_001713d0\n"
        ".Lf171386_001713c0:\n"
        "calll CL_CubemapShotUsage\n" /* line 539 */
        /* } scope */
        "addl $0xbc, %esp\n" /* line 562 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf171386_001713d0:\n"
        "movl $2, (%esp)\n" /* line 490 */
        "calll Cmd_Argv\n"
        "movl %eax, %edi\n" /* size */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* size */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x28, %ecx\n"
        "ja .Lf171386_001713c0\n"
        "movl $2, (%esp)\n" /* line 496 */
        "calll Cmd_Argv\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x64(%ebp), %eax\n" /* szBaseName */
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl $1, (%esp)\n" /* line 497 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %edi\n" /* size */
        "leal -4(%eax), %eax\n" /* line 498 */
        "cmpl $0x3fc, %eax\n"
        "ja .Lf171386_001713c0\n"
        "leal -1(%edi), %eax\n" /* size */
        "testl %eax, %edi\n" /* size */
        "jne .Lf171386_001713c0\n"
        "xorl %eax, %eax\n" /* line 183 */
        "movl %eax, -0x24(%ebp)\n" /* rgb */
        "movl %eax, -0x20(%ebp)\n" /* line 184 */
        "movl %eax, -0x1c(%ebp)\n" /* line 185 */
        "calll Cmd_Argc\n" /* line 508 */
        "cmpl $7, %eax\n"
        "je .Lf171386_00171578\n"
        "calll Cmd_Argc\n" /* line 521 */
        "cmpl $6, %eax\n"
        "je .Lf171386_00171634\n"
        "calll Cmd_Argc\n" /* line 537 */
        "cmpl $3, %eax\n"
        "jne .Lf171386_001713c0\n"
        "movb $0, -0x71(%ebp)\n" /* isLightingShot */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x70(%ebp)\n" /* n0 */
        "movss 0x2ed90c, %xmm0\n" /* 1.3329999446868896f */
        "movss %xmm0, -0x6c(%ebp)\n" /* n1 */
        ".Lf171386_00171487:\n"
        "movl $0, (%esp)\n" /* line 543 */
        "calll CL_ResetSkeletonCache\n"
        "movl $1, %ebx\n"
        "movl 0x195eca8, %esi\n"
        ".Lf171386_0017149e:\n"
        "movl $1, 4(%esp)\n" /* line 547 */
        "movl %edi, (%esp)\n" /* size */
        "calll *0xec(%esi)\n"
        "calll *0xa8(%esi)\n" /* line 549 */
        "calll CL_ClearScene\n" /* line 550 */
        "movl $0, 0x10(%esp)\n" /* line 551 */
        "movl %edi, 0xc(%esp)\n" /* size */
        "movl %ebx, 8(%esp)\n"
        "movl 0x195ee8c, %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x407a0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ee78, %edx\n"
        "movl (%edx), %eax\n"
        "movl 0x26f0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawActiveFrame\n"
        "calll *0xac(%esi)\n" /* line 552 */
        "movl %ebx, (%esp)\n" /* line 554 */
        "calll *0xf0(%esi)\n"
        "addl $1, %ebx\n" /* line 545 */
        "cmpl $7, %ebx\n"
        "jne .Lf171386_0017149e\n"
        "cmpb $0, -0x71(%ebp)\n" /* line 557 | isLightingShot */
        "jne .Lf171386_001716cf\n"
        ".Lf171386_0017151b:\n"
        "movl $1, %edi\n" /* line 558 | size */
        "movl $szShotName, %esi\n"
        ".Lf171386_00171525:\n"
        "movl 0x195eca8, %eax\n" /* line 561 */
        "movl 0xf4(%eax), %ebx\n"
        "movl (%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x64(%ebp), %edx\n" /* szBaseName */
        "movl %edx, 4(%esp)\n"
        "movl $0x2acd54, (%esp)\n" /* "env/%s%s.tga" */
        "calll va\n"
        "movss -0x6c(%ebp), %xmm0\n" /* n1 */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x70(%ebp), %xmm0\n" /* n0 */
        "movss %xmm0, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* size */
        "movl %eax, (%esp)\n"
        "calll *%ebx\n"
        "addl $1, %edi\n" /* line 560 | size */
        "addl $4, %esi\n"
        "cmpl $7, %edi\n" /* size */
        "jne .Lf171386_00171525\n"
        "jmp .Lf171386_001713ab\n"
        ".Lf171386_00171578:\n"
        "movl $3, (%esp)\n" /* line 510 */
        "calll Cmd_Argv\n"
        "movl $0x2acd40, 4(%esp)\n" /* "lighting" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf171386_001713c0\n"
        "movl $4, (%esp)\n" /* line 516 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0xa0(%ebp)\n"
        "cvtsd2ss -0xa0(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n" /* rgb */
        "movl $5, (%esp)\n" /* line 517 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x98(%ebp)\n"
        "cvtsd2ss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl $6, (%esp)\n" /* line 518 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x90(%ebp)\n"
        "cvtsd2ss -0x90(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movb $1, -0x71(%ebp)\n" /* isLightingShot */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x70(%ebp)\n" /* n0 */
        "movss 0x2ed90c, %xmm0\n" /* 1.3329999446868896f */
        "movss %xmm0, -0x6c(%ebp)\n" /* n1 */
        "jmp .Lf171386_00171487\n"
        ".Lf171386_00171634:\n"
        "movl $3, (%esp)\n" /* line 523 */
        "calll Cmd_Argv\n"
        "movl $0x2acd4c, 4(%esp)\n" /* "fresnel" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf171386_001713c0\n"
        "movl $4, (%esp)\n" /* line 529 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x88(%ebp)\n"
        "cvtsd2ss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n" /* n0 */
        "movl $5, (%esp)\n" /* line 530 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x80(%ebp)\n"
        "cvtsd2ss -0x80(%ebp), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n" /* n1 */
        "movss -0x70(%ebp), %xmm0\n" /* line 531 | n0 */
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jp .Lf171386_001716b4\n"
        "jb .Lf171386_001713c0\n"
        ".Lf171386_001716b4:\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss -0x6c(%ebp), %xmm0\n" /* n1 */
        "ja .Lf171386_001713c0\n"
        "movb $0, -0x71(%ebp)\n" /* line 540 | isLightingShot */
        "jmp .Lf171386_00171487\n"
        ".Lf171386_001716cf:\n"
        "leal -0x24(%ebp), %eax\n" /* line 558 | rgb */
        "movl %eax, (%esp)\n"
        "calll *0xf8(%esi)\n"
        "jmp .Lf171386_0017151b\n"
    );
}

/* line 338 */
static __attribute__((naked))
void SCR_UpdateFrame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 338 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x45c, %esp\n"
        "movl 0x195eca8, %ebx\n" /* line 347 */
        "calll *0xa8(%ebx)\n"
        "calll CL_ClearScene\n" /* line 383 */
        "movl $0, (%esp)\n" /* line 384 */
        "calll CL_ResetSkeletonCache\n"
        "movl 0x195ecac, %esi\n" /* line 184 */
        "movl 0x110(%esi), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf1716e0_00171822\n"
        "movl 0x195ee8c, %eax\n" /* line 190 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl $8, %eax\n"
        "je .Lf1716e0_00171756\n"
        "subl $1, %eax\n"
        "je .Lf1716e0_00171756\n"
        "movl $0, 0xc(%esp)\n" /* line 191 */
        "movl $0, 8(%esp)\n"
        "movl 0x195f58c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll *0xc8(%ebx)\n"
        ".Lf1716e0_00171756:\n"
        "movl 0x118(%esi), %eax\n" /* line 193 */
        "movl %eax, (%esp)\n"
        "calll UI_UpdateTime\n"
        "calll UI_IsFullscreen\n" /* line 197 */
        "testl %eax, %eax\n"
        "je .Lf1716e0_00171809\n"
        "movl 0x195ee8c, %eax\n" /* line 268 */
        "movl (%eax), %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf1716e0_0017178c\n"
        "cmpl $7, %edx\n"
        "jle .Lf1716e0_001717a0\n"
        "cmpl $8, %edx\n"
        "je .Lf1716e0_00171879\n"
        ".Lf1716e0_0017178c:\n"
        "movl $0x2acd64, 4(%esp)\n" /* line 271 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf1716e0_001717a0:\n"
        "movl 0x195ee78, %eax\n" /* line 292 */
        "movl (%eax), %eax\n"
        "testb $8, 4(%eax)\n"
        "je .Lf1716e0_001717be\n"
        "movl 0x195ee8c, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl $1, (%eax)\n"
        "je .Lf1716e0_001717be\n"
        "calll UI_Refresh\n" /* line 293 */
        ".Lf1716e0_001717be:\n"
        "movl 0x195f5e0, %eax\n" /* line 295 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf1716e0_0017186f\n"
        ".Lf1716e0_001717d0:\n"
        "movl $0, (%esp)\n" /* line 298 */
        "movl 0x195eca8, %eax\n"
        "calll *0xb8(%eax)\n"
        ".Lf1716e0_001717e2:\n"
        "movl 0x195eca8, %ebx\n" /* line 388 */
        "calll *0xbc(%ebx)\n"
        "calll Con_DrawConsole\n" /* line 174 */
        "calll *0xac(%ebx)\n" /* line 392 */
        "calll Sys_IsMainThread\n" /* line 394 */
        "addl $0x45c, %esp\n" /* line 396 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1716e0_00171809:\n"
        "movl 0x195ee8c, %eax\n" /* line 199 */
        "movl (%eax), %edx\n"
        "cmpl $8, (%edx)\n"
        "ja .Lf1716e0_0017178c\n"
        "movl (%edx), %eax\n"
        "jmpl *0x302ae0(, %eax, 4)\n"
        ".Lf1716e0_00171822:\n"
        "movl $0, 0xc(%esp)\n" /* line 186 */
        "movl $0, 8(%esp)\n"
        "movl 0x195f58c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll *0xc8(%ebx)\n"
        "movl 0x195eca8, %ebx\n" /* line 388 */
        "calll *0xbc(%ebx)\n"
        "calll Con_DrawConsole\n" /* line 174 */
        "calll *0xac(%ebx)\n" /* line 392 */
        "calll Sys_IsMainThread\n" /* line 394 */
        "addl $0x45c, %esp\n" /* line 396 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1716e0_0017186f:\n"
        "calll Net_DisplayProfile\n" /* line 296 */
        "jmp .Lf1716e0_001717d0\n"
        ".Lf1716e0_00171879:\n"
        "movl $0, 0x10(%esp)\n" /* line 159 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 0x407a0(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x26f0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawActiveFrame\n"
        "testl %eax, %eax\n" /* line 285 */
        "jne .Lf1716e0_001717a0\n"
        "calll CL_SendCmdInternal\n" /* line 286 */
        "jmp .Lf1716e0_001717a0\n"
        "movl $0, (%esp)\n" /* line 214 */
        "calll SND_StopSounds\n"
        "calll Sys_IsMainThread\n" /* line 216 */
        "testb %al, %al\n"
        "jne .Lf1716e0_00171a86\n"
        "calll CL_AnyLocalClientChallenging\n" /* line 224 */
        "testb %al, %al\n"
        "je .Lf1716e0_001717a0\n"
        "calll UI_Refresh\n" /* line 253 */
        "calll UI_DrawConnectScreen\n" /* line 254 */
        "jmp .Lf1716e0_001717a0\n"
        "movl $1, 0x10(%esp)\n" /* line 159 */
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpl $0, 0x407a0(%edx)\n"
        "setne %al\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x26f0(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawActiveFrame\n"
        "testl %eax, %eax\n" /* line 260 */
        "je .Lf1716e0_00171a97\n"
        ".Lf1716e0_00171944:\n"
        "movl 0x195ee8c, %eax\n" /* line 124 */
        "movl (%eax), %ebx\n"
        "movl 0x4079c(%ebx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf1716e0_001717a0\n"
        "movl 0x407b0(%ebx), %eax\n" /* line 127 */
        "movl %eax, (%esp)\n"
        "calll FS_FTell\n"
        "leal 0x3ff(%eax), %edx\n" /* line 128 */
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0xa, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x4075c(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2acd8c, 4(%esp)\n" /* "RECORDING %s: %ik" */
        "leal -0x438(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "leal -0x38(%ebp), %ebx\n" /* line 130 */
        "movl %ebx, 4(%esp)\n"
        "movl $0x37, (%esp)\n"
        "calll CL_LookupColor\n"
        "movl $0x40a00000, -0x1c(%ebp)\n" /* line 131 */
        "movl $0x43ef8000, -0x20(%ebp)\n" /* line 132 */
        "movl 0x195eca8, %edi\n" /* line 133 */
        "movl $0x3eaaaaab, 4(%esp)\n"
        "movl 0x195ecac, %esi\n"
        "movl 0x2a0a60(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x110(%edi)\n"
        "fsts -0x24(%ebp)\n"
        "fstps -0x28(%ebp)\n" /* line 134 */
        "movl $1, 0x14(%esp)\n" /* line 135 */
        "movl $1, 0x10(%esp)\n"
        "leal -0x28(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movl $0, 0x20(%esp)\n" /* line 136 */
        "movl %ebx, 0x1c(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2a0a60(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "leal -0x438(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x11c(%edi)\n"
        "jmp .Lf1716e0_001717a0\n"
        "calll SCR_DrawCinematic\n" /* line 205 */
        "jmp .Lf1716e0_001717a0\n"
        "calll CL_DrawLogo\n" /* line 208 */
        "movl 0x195ee8c, %eax\n" /* line 209 */
        "movl (%eax), %eax\n"
        "cmpl $2, (%eax)\n"
        "jne .Lf1716e0_001717e2\n"
        "jmp .Lf1716e0_001717a0\n"
        ".Lf1716e0_00171a86:\n"
        "movl $1, (%esp)\n" /* line 245 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lf1716e0_001717a0\n"
        ".Lf1716e0_00171a97:\n"
        "calll CL_SendCmdInternal\n" /* line 261 */
        "jmp .Lf1716e0_00171944\n"
    );
}

/* line 403 */
__attribute__((naked))
void SCR_UpdateScreenInternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 403 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "cmpb $0, updateScreenCalled\n" /* line 407 */
        "jne .Lf171aa2_00171ae4\n"
        "movl 0x195ee8c, %eax\n" /* line 415 */
        "movl (%eax), %eax\n"
        "cmpl $6, (%eax)\n"
        "je .Lf171aa2_00171ae6\n"
        ".Lf171aa2_00171abd:\n"
        "movl scr_initialized, %eax\n" /* line 418 */
        "testl %eax, %eax\n"
        "je .Lf171aa2_00171ae4\n"
        "movl 0x195eea4, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf171aa2_00171ae4\n"
        "movb $1, updateScreenCalled\n" /* line 425 */
        "calll SCR_UpdateFrame\n" /* line 428 */
        "movb $0, updateScreenCalled\n" /* line 431 */
        ".Lf171aa2_00171ae4:\n"
        "leave\n" /* line 435 */
        "retl\n"
        ".Lf171aa2_00171ae6:\n"
        "calll Sys_LoadingKeepAlive\n" /* line 416 */
        "jmp .Lf171aa2_00171abd\n"
    );
}

/* line 438 */
__attribute__((naked))
void SCR_UpdateScreen(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 438 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "cmpb $0, updateScreenCalled\n" /* line 407 */
        "jne .Lf171aee_00171b30\n"
        "movl 0x195ee8c, %eax\n" /* line 415 */
        "movl (%eax), %eax\n"
        "cmpl $6, (%eax)\n"
        "je .Lf171aee_00171b32\n"
        ".Lf171aee_00171b09:\n"
        "movl scr_initialized, %eax\n" /* line 418 */
        "testl %eax, %eax\n"
        "je .Lf171aee_00171b30\n"
        "movl 0x195eea4, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf171aee_00171b30\n"
        "movb $1, updateScreenCalled\n" /* line 425 */
        "calll SCR_UpdateFrame\n" /* line 428 */
        "movb $0, updateScreenCalled\n" /* line 431 */
        ".Lf171aee_00171b30:\n"
        "leave\n" /* line 443 */
        "retl\n"
        ".Lf171aee_00171b32:\n"
        "calll Sys_LoadingKeepAlive\n" /* line 416 */
        "jmp .Lf171aee_00171b09\n"
    );
}

