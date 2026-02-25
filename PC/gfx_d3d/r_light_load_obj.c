/* ASM dump from: r_light_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_light_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

GfxLightDef * R_LoadLightDef(const char *name);

/* line 58 */
__attribute__((naked))
GfxLightDef * R_LoadLightDef(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 58 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 68 | name */
        "movl %eax, 4(%esp)\n"
        "movl $0x22692c, (%esp)\n" /* "lights/%s" */
        "calll va\n"
        "leal -0x1c(%ebp), %edx\n" /* line 69 | file */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll FS_ReadFile\n"
        "cmpl $0, %eax\n" /* line 70 */
        "jl .Lffc08c_000fc201\n"
        "je .Lffc08c_000fc1f6\n" /* line 73 */
        "movl $0x18, (%esp)\n" /* line 79 */
        "calll Hunk_AllocInternal\n"
        "movl %eax, -0x2c(%ebp)\n" /* def */
        "xorl %ebx, %ebx\n" /* line 80 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl 8(%ebp), %edi\n" /* name */
        "movl %ebx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl -0x2c(%ebp), %edx\n" /* def */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 82 | file */
        "movzbl (%edx), %eax\n" /* line 84 */
        "movl -0x2c(%ebp), %ecx\n" /* def */
        "movl %eax, (%ecx)\n"
        /* { scope 2 */
        "movzbl 1(%edx), %eax\n" /* line 20 */
        "movb %al, 8(%ecx)\n"
        "leal 2(%edx), %esi\n" /* line 21 */
        "cld\n" /* line 24 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "movl %ebx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, %ebx\n" /* line 25 */
        "subl $1, %ebx\n"
        "jne .Lffc08c_000fc190\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 28 | def */
        "movl $0, 4(%ecx)\n"
        "leal (%esi, %ebx), %edx\n" /* line 29 */
        /* } scope */
        /* { scope 2 */
        "movzbl 1(%edx), %eax\n" /* line 20 */
        "movl -0x2c(%ebp), %ecx\n" /* def */
        "movb %al, 0x10(%ecx)\n"
        "addl $2, %edx\n" /* line 23 */
        "cld\n" /* line 24 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "cmpl $-2, %ecx\n"
        "jne .Lffc08c_000fc1d3\n"
        ".Lffc08c_000fc14d:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 28 | def */
        "movl $0, 0xc(%ecx)\n"
        /* } scope */
        ".Lffc08c_000fc157:\n"
        "movl 8(%ebp), %eax\n" /* line 88 | name */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %edx\n" /* def */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 89 | def */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strlwr\n"
        "movl -0x1c(%ebp), %eax\n" /* line 91 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 94 | def */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lffc08c_000fc190:\n"
        "movl $5, 8(%esp)\n" /* line 26 */
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Image_Register\n"
        "movl -0x2c(%ebp), %edx\n" /* def */
        "movl %eax, 4(%edx)\n"
        "leal (%esi, %ebx), %edx\n" /* line 29 */
        /* } scope */
        /* { scope 2 */
        "movzbl 1(%edx), %eax\n" /* line 20 */
        "movl -0x2c(%ebp), %ecx\n" /* def */
        "movb %al, 0x10(%ecx)\n"
        "addl $2, %edx\n" /* line 23 */
        "cld\n" /* line 24 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "cmpl $-2, %ecx\n"
        "je .Lffc08c_000fc14d\n"
        ".Lffc08c_000fc1d3:\n"
        "movl $5, 8(%esp)\n" /* line 26 */
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Image_Register\n"
        "movl -0x2c(%ebp), %edx\n" /* def */
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lffc08c_000fc157\n"
        /* } scope */
        ".Lffc08c_000fc1f6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 75 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        ".Lffc08c_000fc201:\n"
        "movl $0, -0x2c(%ebp)\n" /* def */
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 94 | def */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

