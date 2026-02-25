/* ASM dump from: r_fog.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_fog.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/memfile.h"
 */

void R_ClearFogs(void);
void R_SetFog(int fogvar, float start, float end, int r, int g, int b, float density);
void R_SwitchFog(int fogvar, int startTime, int transitionTime);
void R_ArchiveFogState(MemoryFile *memFile);

/* line 14 */
__attribute__((naked))
void R_ClearFogs(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 14 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eec8, %ebx\n" /* line 16 */
        "leal 0x146c(%ebx), %eax\n"
        "movl $0xa0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0, 0x150c(%ebx)\n" /* line 17 */
        "addl $0x14, %esp\n" /* line 18 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 21 */
__attribute__((naked))
void R_SetFog(int fogvar, float start, float end, int r, int g, int b, float density)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 21 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movss 0x20(%ebp), %xmm1\n" /* density */
        "movzbl 0x18(%ebp), %esi\n" /* g */
        "movzbl 0x1c(%ebp), %edi\n" /* b */
        "movl 8(%ebp), %ebx\n" /* line 26 | fogvar */
        "shll $5, %ebx\n"
        "movl 0x195eec8, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "leal 0x1460(%ebx, %eax), %ecx\n"
        "leal 0x18(%ecx), %edx\n" /* v */
        /* { scope 1 */
        "movzbl 0x14(%ebp), %eax\n" /* line 655 | r */
        "movb %al, 2(%edx)\n"
        "movl %esi, %eax\n" /* line 656 | g */
        "movb %al, 1(%edx)\n"
        "movl %edi, %eax\n" /* line 657 | b */
        "movb %al, 0x18(%ecx)\n"
        "movb $0xff, 3(%edx)\n" /* line 658 */
        /* } scope */
        "movl -0x10(%ebp), %edx\n" /* line 27 */
        "leal (%ebx, %edx), %ecx\n"
        "leal 0x1470(%ecx), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* start */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 28 | end */
        "movl %eax, 0x10(%edx)\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 29 | 1.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lfd2e5c_000d2ef5\n"
        "movl $1, 0x146c(%ecx)\n" /* line 31 */
        "movb $1, 0x19(%edx)\n" /* line 32 */
        "movb $0, 0x1a(%edx)\n" /* line 33 */
        "movss %xmm0, 0x14(%edx)\n" /* line 34 */
        "shll $5, 8(%ebp)\n" /* line 43 | fogvar */
        "movl 8(%ebp), %eax\n" /* fogvar */
        "movl -0x10(%ebp), %edx\n"
        "movb $1, 0x1488(%eax, %edx)\n"
        "addl $4, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd2e5c_000d2ef5:\n"
        "movl $2, 0x146c(%ecx)\n" /* line 38 */
        "movb $1, 0x19(%edx)\n" /* line 39 */
        "movb $0, 0x1a(%edx)\n" /* line 40 */
        "movss %xmm1, 0x14(%edx)\n" /* line 41 */
        "shll $5, 8(%ebp)\n" /* line 43 | fogvar */
        "movl 8(%ebp), %eax\n" /* fogvar */
        "movl -0x10(%ebp), %edx\n"
        "movb $1, 0x1488(%eax, %edx)\n"
        "addl $4, %esp\n" /* line 44 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 47 */
__attribute__((naked))
void R_SwitchFog(int fogvar, int startTime, int transitionTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 47 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* fogvar */
        "movl 0x10(%ebp), %ebx\n" /* transitionTime */
        "movl 0x195eec8, %ecx\n" /* line 51 */
        "movl %eax, 0x150c(%ecx)\n"
        "cmpb $0, 0x14c8(%ecx)\n" /* line 52 */
        "je .Lfd2f26_000d3034\n"
        "movl 0x14ac(%ecx), %eax\n" /* line 54 */
        "movl %eax, 0x14cc(%ecx)\n"
        "movl 0x14b0(%ecx), %eax\n"
        "movl %eax, 0x14d0(%ecx)\n"
        "movl 0x14b4(%ecx), %eax\n"
        "movl %eax, 0x14d4(%ecx)\n"
        "movl 0x14b8(%ecx), %eax\n"
        "movl %eax, 0x14d8(%ecx)\n"
        "movl 0x14bc(%ecx), %eax\n"
        "movl %eax, 0x14dc(%ecx)\n"
        "movl 0x14c0(%ecx), %eax\n"
        "movl %eax, 0x14e0(%ecx)\n"
        "movl 0x14c4(%ecx), %eax\n"
        "movl %eax, 0x14e4(%ecx)\n"
        "movl 0x14c8(%ecx), %eax\n"
        "movl %eax, 0x14e8(%ecx)\n"
        ".Lfd2f26_000d2fa9:\n"
        "movl 0x150c(%ecx), %eax\n" /* line 61 */
        "shll $5, %eax\n"
        "leal 0x1460(%eax, %ecx), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, 0x14ec(%ecx)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, 0x14f0(%ecx)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, 0x14f4(%ecx)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, 0x14f8(%ecx)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, 0x14fc(%ecx)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, 0x1500(%ecx)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, 0x1504(%ecx)\n"
        "movl 0x28(%eax), %eax\n"
        "movl %eax, 0x1508(%ecx)\n"
        "testl %ebx, %ebx\n" /* line 63 | transitionTime */
        "jne .Lfd2f26_000d301c\n"
        "movl $0, 0x14f0(%ecx)\n" /* line 65 */
        "movl $0, 0x14f4(%ecx)\n" /* line 66 */
        "popl %ebx\n" /* line 73 */
        "popl %ebp\n"
        "retl\n"
        ".Lfd2f26_000d301c:\n"
        "movl 0xc(%ebp), %eax\n" /* line 70 | startTime */
        "movl %eax, 0x14f0(%ecx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 71 | startTime */
        "leal (%ebx, %edx), %eax\n" /* transitionTime */
        "movl %eax, 0x14f4(%ecx)\n"
        "popl %ebx\n" /* line 73 */
        "popl %ebp\n"
        "retl\n"
        ".Lfd2f26_000d3034:\n"
        "shll $5, %eax\n" /* line 58 */
        "leal 0x1460(%eax, %ecx), %edx\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0x14cc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x14d0(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14d4(%ecx)\n"
        "movl 0x18(%edx), %eax\n"
        "movl %eax, 0x14d8(%ecx)\n"
        "movl 0x1c(%edx), %eax\n"
        "movl %eax, 0x14dc(%ecx)\n"
        "movl 0x20(%edx), %eax\n"
        "movl %eax, 0x14e0(%ecx)\n"
        "movl 0x24(%edx), %eax\n"
        "movl %eax, 0x14e4(%ecx)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 0x14e8(%ecx)\n"
        "xorl %ebx, %ebx\n" /* transitionTime */
        "jmp .Lfd2f26_000d2fa9\n"
    );
}

/* line 92 */
__attribute__((naked))
void R_ArchiveFogState(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 92 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* memFile */
        "movl 0x195eec8, %ebx\n" /* line 167 */
        "leal 0x146c(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0xa0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* memFile */
        "calll *0x10(%esi)\n" /* memFile */
        "addl $0x150c, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* memFile */
        "calll *0x10(%esi)\n" /* memFile */
        "addl $0x10, %esp\n" /* line 106 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

