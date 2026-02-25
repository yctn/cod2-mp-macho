/* ASM dump from: r_font_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_font_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

Font * R_LoadFont(const char *fontName, int imageTrack);

/* line 38 */
__attribute__((naked))
Font * R_LoadFont(const char *fontName, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* fontName */
        /* { scope 1 */
        "movl $1, 8(%esp)\n" /* line 46 */
        "leal -0x1c(%ebp), %eax\n" /* fileHandle */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* fontName */
        "calll FS_FOpenFileRead\n"
        "movl %eax, %esi\n" /* len */
        "testl %eax, %eax\n" /* line 47 */
        "js .Lffc214_000fc2c1\n"
        "cmpl $0xf, %eax\n" /* line 56 */
        "jbe .Lffc214_000fc2f6\n"
        "leal 4(%eax), %eax\n" /* line 63 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, %edi\n" /* font */
        "movl -0x1c(%ebp), %eax\n" /* line 64 | fileHandle */
        "movl %eax, 8(%esp)\n"
        "movl $0x10, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* font */
        "calll FS_Read\n"
        "leal 0x14(%edi), %ebx\n" /* line 65 | font, fontName */
        "movl -0x1c(%ebp), %eax\n" /* fileHandle */
        "movl %eax, 8(%esp)\n"
        "leal -0x10(%esi), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* fontName */
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 66 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %ebx, 0x10(%edi)\n" /* line 74 | fontName, font */
        "leal 4(%edi), %eax\n" /* line 79 | font */
        "addl %eax, (%edi)\n" /* font */
        "movl 0xc(%ebp), %edx\n" /* line 81 | imageTrack */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "addl 0xc(%edi), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll Material_RegisterHandle\n"
        "movl %eax, 0xc(%edi)\n" /* font */
        /* } scope */
        ".Lffc214_000fc2b7:\n"
        "movl %edi, %eax\n" /* line 84 | font */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc214_000fc2c1:\n"
        "cmpl $-2, %eax\n" /* line 49 */
        "je .Lffc214_000fc2e2\n"
        "movl %ebx, 4(%esp)\n" /* line 52 | fontName */
        "movl $0x226980, (%esp)\n" /* "^1ERROR: Couldn't find font '%s'
" */
        "calll Com_Printf\n"
        "xorl %edi, %edi\n" /* font */
        /* } scope */
        "movl %edi, %eax\n" /* line 84 | font */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffc214_000fc2e2:\n"
        "movl %ebx, 4(%esp)\n" /* line 50 | fontName */
        "movl $0x226938, (%esp)\n" /* "^1ERROR: Couldn't find font in iwd files or localized direct" */
        "calll Com_Printf\n"
        "xorl %edi, %edi\n" /* font */
        "jmp .Lffc214_000fc2b7\n"
        ".Lffc214_000fc2f6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 58 | fileHandle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %ebx, 4(%esp)\n" /* line 59 | fontName */
        "movl $0x2269a4, (%esp)\n" /* "^1ERROR: Font file '%s' too small
" */
        "calll Com_Printf\n"
        "xorl %edi, %edi\n" /* font */
        "jmp .Lffc214_000fc2b7\n"
    );
}

