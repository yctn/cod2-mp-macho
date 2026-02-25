/* ASM dump from: r_sky_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_sky_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

void R_LoadSunThroughDvars(const char *sunName, sunflare_t *sun);
void R_LoadSun(const char *name, sunflare_t *sun);

/* line 10 */
__attribute__((naked))
void R_LoadSunThroughDvars(const char *sunName, sunflare_t *sun)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 10 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 19 | sunName */
        "movl %eax, 4(%esp)\n"
        "movl $0x2266c0, (%esp)\n" /* "sun/%s.sun" */
        "calll va\n"
        "movl %eax, %esi\n" /* fullpath */
        "leal -0xc(%ebp), %eax\n" /* line 20 | sunFile */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* fullpath */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 21 */
        "js .Lffb71c_000fb790\n"
        "movl -0xc(%ebp), %ebx\n" /* line 31 | sunFile */
        "calll R_GetSundvarsSize\n"
        "movl %esi, 0xc(%esp)\n" /* fullpath */
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195f238, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_LoadDvarsFromBuffer\n"
        "testl %eax, %eax\n"
        "jne .Lffb71c_000fb783\n"
        ".Lffb71c_000fb771:\n"
        "movl -0xc(%ebp), %eax\n" /* line 34 | sunFile */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 35 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffb71c_000fb783:\n"
        "movl 0xc(%ebp), %eax\n" /* line 32 | sun */
        "movl %eax, (%esp)\n"
        "calll R_SetSunFromDvars\n"
        "jmp .Lffb71c_000fb771\n"
        ".Lffb71c_000fb790:\n"
        "movl %esi, 4(%esp)\n" /* line 23 | fullpath */
        "movl $0x226904, (%esp)\n" /* "^3WARNING: couldn't load sun file '%s'
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 35 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 38 */
__attribute__((naked))
void R_LoadSun(const char *name, sunflare_t *sun)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "movl 0xc(%ebp), %esi\n" /* sun */
        /* { scope 1 */
        "movl $0x60, 8(%esp)\n" /* line 48 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* sun */
        "calll Com_Memset\n"
        "movzbl (%ebx), %eax\n" /* line 54 | name */
        "testb %al, %al\n"
        "je .Lffb7a8_000fb840\n"
        "movl %ebx, %edx\n" /* name */
        "movl %ebx, %ecx\n" /* name */
        "jmp .Lffb7a8_000fb7e9\n"
        ".Lffb7a8_000fb7db:\n"
        "cmpb $0x5c, %al\n" /* line 56 */
        "je .Lffb7a8_000fb7ed\n"
        "addl $1, %edx\n"
        "movzbl (%edx), %eax\n" /* line 54 */
        "testb %al, %al\n"
        "je .Lffb7a8_000fb7f9\n"
        ".Lffb7a8_000fb7e9:\n"
        "cmpb $0x2f, %al\n" /* line 56 */
        "jne .Lffb7a8_000fb7db\n"
        ".Lffb7a8_000fb7ed:\n"
        "leal 1(%edx), %ecx\n" /* line 57 */
        "movl %ecx, %edx\n"
        "movzbl (%edx), %eax\n" /* line 54 */
        "testb %al, %al\n"
        "jne .Lffb7a8_000fb7e9\n"
        ".Lffb7a8_000fb7f9:\n"
        "movl $0x40, 8(%esp)\n" /* line 60 */
        "movl %ecx, 4(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* sunFile, name */
        "movl %ebx, (%esp)\n" /* name */
        "calll I_strncpyz\n"
        "movl $0x2e, 4(%esp)\n" /* line 63 */
        "movl %ebx, (%esp)\n" /* name */
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 64 */
        "je .Lffb7a8_000fb827\n"
        "movb $0, (%eax)\n" /* line 65 */
        ".Lffb7a8_000fb827:\n"
        "cmpb $0, -0x48(%ebp)\n" /* line 67 | sunFile */
        "je .Lffb7a8_000fb839\n"
        "movl %esi, 4(%esp)\n" /* line 68 | sun */
        "movl %ebx, (%esp)\n" /* name */
        "calll R_LoadSunThroughDvars\n"
        /* } scope */
        ".Lffb7a8_000fb839:\n"
        "addl $0x50, %esp\n" /* line 69 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffb7a8_000fb840:\n"
        "movl %ebx, %ecx\n" /* line 54 | name */
        "jmp .Lffb7a8_000fb7f9\n"
    );
}

