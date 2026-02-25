/* ASM dump from: r_cmds.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_cmds.cpp */

#include "common_types.h"
#include "imports.h"

static void R_Cmd_ApplyPicmip(void);
static void R_Cmd_Screenshot(void);
static void R_Cmd_ScreenshotJpeg(void);
void R_RegisterCmds(void);
void R_UnregisterCmds(void);

/* line 15 */
static __attribute__((naked))
void R_Cmd_ApplyPicmip(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 15 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 18 */
        "jmp Material_UpdatePicmipAll\n" /* line 17 */
    );
}

/* line 28 */
static __attribute__((naked))
void R_Cmd_Screenshot(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, (%esp)\n" /* line 30 */
        "calll R_ScreenshotCommand\n"
        "leave\n" /* line 31 */
        "retl\n"
    );
}

/* line 34 */
static __attribute__((naked))
void R_Cmd_ScreenshotJpeg(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 36 */
        "calll R_ScreenshotCommand\n"
        "leave\n" /* line 37 */
        "retl\n"
    );
}

/* line 40 */
__attribute__((naked))
void R_RegisterCmds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 40 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eee0, %ebx\n" /* line 42 */
        "movl $R_Cmd_Screenshot, 4(%esp)\n"
        "movl $0x225608, (%esp)\n" /* "screenshot" */
        "calll *0xf8(%ebx)\n"
        "movl $R_Cmd_ScreenshotJpeg, 4(%esp)\n" /* line 43 */
        "movl $0x225aa0, (%esp)\n" /* "screenshotJpeg" */
        "calll *0xf8(%ebx)\n"
        "movl 0x195f1ec, %eax\n" /* line 45 */
        "movl %eax, 4(%esp)\n"
        "movl $0x225ab0, (%esp)\n" /* "imagelist" */
        "calll *0xf8(%ebx)\n"
        "movl $R_Cmd_ApplyPicmip, 4(%esp)\n" /* line 49 */
        "movl $0x225abc, (%esp)\n" /* "r_applyPicmip" */
        "calll *0xf8(%ebx)\n"
        "movl 0x195f1e8, %eax\n" /* line 50 */
        "movl %eax, 4(%esp)\n"
        "movl $0x225acc, (%esp)\n" /* "reloadmaterialtextures" */
        "calll *0xf8(%ebx)\n"
        "movl 0x195f1f0, %eax\n" /* line 51 */
        "movl %eax, 4(%esp)\n"
        "movl $0x225ae4, (%esp)\n" /* "r_loadsun" */
        "calll *0xf8(%ebx)\n"
        "movl 0x195f1dc, %eax\n" /* line 54 */
        "movl %eax, 4(%esp)\n"
        "movl $0x225af0, (%esp)\n" /* "r_savesun" */
        "calll *0xf8(%ebx)\n"
        "movl 0x195f1e0, %eax\n" /* line 69 */
        "movl %eax, 4(%esp)\n"
        "movl $0x225afc, (%esp)\n" /* "r_smc_stats" */
        "calll *0xf8(%ebx)\n"
        "movl 0x195f1e4, %eax\n" /* line 70 */
        "movl %eax, 4(%esp)\n"
        "movl $0x225b08, (%esp)\n" /* "r_smc_flush" */
        "calll *0xf8(%ebx)\n"
        "addl $0x14, %esp\n" /* line 72 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 75 */
__attribute__((naked))
void R_UnregisterCmds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eee0, %ebx\n" /* line 77 */
        "movl $0x225abc, (%esp)\n" /* "r_applyPicmip" */
        "calll *0xfc(%ebx)\n"
        "movl $0x225b14, (%esp)\n" /* line 78 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225608, (%esp)\n" /* line 79 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225aa0, (%esp)\n" /* line 80 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225ab0, (%esp)\n" /* line 81 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225acc, (%esp)\n" /* line 82 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225ae4, (%esp)\n" /* line 83 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225af0, (%esp)\n" /* line 84 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225afc, (%esp)\n" /* line 99 */
        "calll *0xfc(%ebx)\n"
        "movl $0x225b08, (%esp)\n" /* line 100 */
        "calll *0xfc(%ebx)\n"
        "addl $0x14, %esp\n" /* line 102 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

