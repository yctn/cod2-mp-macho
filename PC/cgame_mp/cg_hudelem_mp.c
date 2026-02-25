/* ASM dump from: cg_hudelem_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_hudelem_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

Bool CG_AreHudElemsHidden(void);
float CG_AlignHudElemX(int alignOrg, float x, float width);
float CG_AlignHudElemY(int alignOrg, float y, float height);
int compare_hudelems(const inflate_huft *pe0, const inflate_huft *pe1);
static inflate_huft CG_DrawHudElemString(const char *text, const hudelem_t *elem);
static inflate_huft CG_GetHudElemInfo(const hudelem_t *elem, char *hudElemString);
inflate_huft CG_Draw2dHudElems(qboolean foreground);
inflate_huft CG_Draw3dHudElems(void);

/* line 32 */
__attribute__((naked))
Bool CG_AreHudElemsHidden(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 0x195f584, %eax\n" /* line 34 */
        "movl (%eax), %eax\n"
        "movl 0x2bdc8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1dda68_001dda86\n"
        "movl $1, %eax\n"
        ".Lf1dda68_001dda84:\n"
        "leave\n" /* line 35 */
        "retl\n"
        ".Lf1dda68_001dda86:\n"
        "calll CL_GetKeyCatchers\n" /* line 34 */
        "testb $8, %al\n"
        "jne .Lf1dda68_001dda93\n"
        ".Lf1dda68_001dda8f:\n"
        "xorl %eax, %eax\n"
        "leave\n" /* line 35 */
        "retl\n"
        ".Lf1dda68_001dda93:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n" /* line 34 */
        "testb %al, %al\n"
        "jne .Lf1dda68_001dda8f\n"
        "movl $1, %eax\n"
        "jmp .Lf1dda68_001dda84\n"
    );
}

/* line 227 */
__attribute__((naked))
float CG_AlignHudElemX(int alignOrg, float x, float width)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 227 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* alignOrg */
        "movss 0x10(%ebp), %xmm0\n" /* width */
        "sarl $2, %eax\n" /* line 229 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddaa4_001ddad7\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddaa4_001ddac4\n"
        "flds 0xc(%ebp)\n" /* line 241 | x */
        "popl %ebp\n"
        "retl\n"
        ".Lf1ddaa4_001ddac4:\n"
        "movss 0xc(%ebp), %xmm1\n" /* line 236 | x */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ebp)\n" /* x */
        "flds 0xc(%ebp)\n" /* line 241 | x */
        "popl %ebp\n"
        "retl\n"
        ".Lf1ddaa4_001ddad7:\n"
        "mulss 0x2ed63c, %xmm0\n" /* line 234 | -0.5f */
        "addss 0xc(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 0xc(%ebp)\n" /* x */
        "flds 0xc(%ebp)\n" /* line 241 | x */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 244 */
__attribute__((naked))
float CG_AlignHudElemY(int alignOrg, float y, float height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 244 */
        "movl %esp, %ebp\n"
        "movss 0x10(%ebp), %xmm0\n" /* height */
        "movl 8(%ebp), %eax\n" /* line 246 | alignOrg */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddaee_001ddb1e\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddaee_001ddb0b\n"
        "flds 0xc(%ebp)\n" /* line 258 | y */
        "popl %ebp\n"
        "retl\n"
        ".Lf1ddaee_001ddb0b:\n"
        "movss 0xc(%ebp), %xmm1\n" /* line 253 | y */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%ebp)\n" /* y */
        "flds 0xc(%ebp)\n" /* line 258 | y */
        "popl %ebp\n"
        "retl\n"
        ".Lf1ddaee_001ddb1e:\n"
        "mulss 0x2ed63c, %xmm0\n" /* line 251 | -0.5f */
        "addss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 0xc(%ebp)\n" /* y */
        "flds 0xc(%ebp)\n" /* line 258 | y */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 738 */
__attribute__((naked))
int compare_hudelems(const inflate_huft *pe0, const inflate_huft *pe1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 738 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 742 | pe0 */
        "movl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* pe1 */
        "movl (%eax), %eax\n"
        "movss 0x78(%edx), %xmm0\n" /* delta */
        "subss 0x78(%eax), %xmm0\n" /* delta */
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 744 | 0.0f */
        "jb .Lf1ddb36_001ddb64\n"
        ".Lf1ddb36_001ddb56:\n"
        "xorl %eax, %eax\n" /* line 746 */
        "ucomiss 0x2ed5e8, %xmm0\n" /* 0.0f */
        "seta %al\n"
        /* } scope */
        "popl %ebp\n" /* line 749 */
        "retl\n"
        /* { scope 1 */
        ".Lf1ddb36_001ddb64:\n"
        "jp .Lf1ddb36_001ddb56\n" /* line 744 */
        "movl $0xffffffff, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 749 */
        "retl\n"
    );
}

/* line 522 */
static __attribute__((naked))
inflate_huft CG_DrawHudElemString(const char *text, const hudelem_t *elem)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, %edi\n" /* cghe */
        /* { scope 1 */
        "movss 0x10(%ecx), %xmm1\n" /* line 537 */
        "subss 0x224(%ecx), %xmm1\n"
        "xorps 0x303920, %xmm1\n"
        /* { scope 2: dummyX, dummyY */
        /* { scope 3 */
        "movl 0x64(%edx), %edx\n" /* line 285 */
        "testl %edx, %edx\n"
        "jle .Lf1ddb6e_001ddbbd\n"
        "movl 0x195f584, %eax\n" /* line 288 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl -0x40(%ebp), %ecx\n"
        "subl 0x60(%ecx), %eax\n"
        "testl %eax, %eax\n" /* line 289 */
        "jle .Lf1ddb6e_001ddd73\n"
        "cmpl %eax, %edx\n" /* line 291 */
        "jg .Lf1ddb6e_001ddce4\n"
        /* } scope */
        ".Lf1ddb6e_001ddbbd:\n"
        "movss 4(%edi), %xmm0\n" /* line 337 */
        "movl -0x40(%ebp), %edx\n" /* line 246 */
        "movl 0x18(%edx), %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddb6e_001ddd3e\n"
        ".Lf1ddb6e_001ddbd4:\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddb6e_001ddd79\n"
        /* } scope */
        ".Lf1ddb6e_001ddbdd:\n"
        "movl 0x220(%edi), %eax\n" /* line 538 | cghe */
        "movl %eax, 4(%esp)\n"
        "movl 0x21c(%edi), %eax\n" /* cghe */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "calll CL_NormalizedTextScale\n"
        "fsts -0x30(%ebp)\n" /* scaleX */
        "fstps -0x1c(%ebp)\n" /* line 539 | scaleY */
        "movl -0x40(%ebp), %eax\n" /* line 540 */
        "movl 0x1c(%eax), %edx\n" /* alignScreen */
        /* { scope 2: dummyX, dummyY */
        /* { scope 3 */
        "xorl %ebx, %ebx\n" /* line 352 */
        "movl %ebx, -0x28(%ebp)\n" /* dummyX */
        "movl %ebx, -0x2c(%ebp)\n" /* line 353 | dummyY */
        "movl %edx, %eax\n" /* line 356 */
        "andl $7, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "sarl $3, %edx\n"
        "andl $7, %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* scaleY */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* scaleX */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %edx\n" /* dummyY */
        "movl %edx, 4(%esp)\n"
        "leal -0x28(%ebp), %esi\n" /* dummyX */
        "movl %esi, (%esp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movl %ebx, -0x20(%ebp)\n" /* line 542 | dx */
        "movl 0x224(%edi), %eax\n" /* line 543 | cghe */
        "movl %eax, -0x24(%ebp)\n" /* dy */
        "movl -0x40(%ebp), %ecx\n" /* line 544 */
        "movl 0x1c(%ecx), %eax\n" /* alignScreen */
        /* { scope 2: dummyX, dummyY */
        /* { scope 3 */
        "movl %ebx, -0x2c(%ebp)\n" /* line 352 | dummyY */
        "movl %ebx, -0x28(%ebp)\n" /* line 353 | dummyX */
        "movl %eax, %edx\n" /* line 356 */
        "andl $7, %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "sarl $3, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* dy */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* dx */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* dummyY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movl $3, 0x20(%esp)\n" /* line 546 */
        "leal 0x228(%edi), %eax\n" /* cghe */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* scaleY */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* scaleX */
        "movl %eax, 0x14(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "addss -0x24(%ebp), %xmm0\n" /* dy */
        "movss %xmm0, 0x10(%esp)\n"
        "movl (%edi), %eax\n" /* cghe */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x21c(%edi), %eax\n" /* cghe */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CL_DrawTextPhysical\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 547 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: dummyX, dummyY */
        /* { scope 3 */
        ".Lf1ddb6e_001ddce4:\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 294 */
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm2\n"
        /* } scope */
        "ucomiss 0x2ed5d0, %xmm2\n" /* line 336 | 1.0f */
        "je .Lf1ddb6e_001ddd4f\n"
        ".Lf1ddb6e_001ddcf9:\n"
        "movss 4(%edi), %xmm0\n" /* line 339 */
        "movl -0x40(%ebp), %ecx\n" /* line 246 */
        "movl 0x58(%ecx), %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddb6e_001ddd82\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddb6e_001ddd6a\n"
        "movaps %xmm0, %xmm3\n"
        /* { scope 3 */
        ".Lf1ddb6e_001ddd14:\n"
        "movl -0x40(%ebp), %edx\n"
        "movl 0x18(%edx), %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddb6e_001ddd93\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddb6e_001ddda1\n"
        /* } scope */
        ".Lf1ddb6e_001ddd27:\n"
        "movaps %xmm3, %xmm1\n" /* line 341 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm3, %xmm0\n"
        "jmp .Lf1ddb6e_001ddbdd\n"
        ".Lf1ddb6e_001ddd3e:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 251 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1ddb6e_001ddbdd\n"
        ".Lf1ddb6e_001ddd4f:\n"
        "jp .Lf1ddb6e_001ddcf9\n" /* line 336 */
        "movss 4(%edi), %xmm0\n" /* line 337 */
        "movl -0x40(%ebp), %edx\n" /* line 246 */
        "movl 0x18(%edx), %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "jne .Lf1ddb6e_001ddbd4\n"
        "jmp .Lf1ddb6e_001ddd3e\n"
        ".Lf1ddb6e_001ddd6a:\n"
        "movaps %xmm0, %xmm3\n" /* line 253 */
        "subss %xmm1, %xmm3\n"
        "jmp .Lf1ddb6e_001ddd14\n"
        ".Lf1ddb6e_001ddd73:\n"
        "pxor %xmm2, %xmm2\n"
        "jmp .Lf1ddb6e_001ddcf9\n"
        ".Lf1ddb6e_001ddd79:\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf1ddb6e_001ddbdd\n"
        ".Lf1ddb6e_001ddd82:\n"
        "movaps %xmm1, %xmm3\n" /* line 251 */
        "mulss 0x2ed63c, %xmm3\n" /* -0.5f */
        "addss %xmm0, %xmm3\n"
        "jmp .Lf1ddb6e_001ddd14\n"
        /* { scope 3 */
        ".Lf1ddb6e_001ddd93:\n"
        "mulss 0x2ed63c, %xmm1\n" /* -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1ddb6e_001ddd27\n"
        ".Lf1ddb6e_001ddda1:\n"
        "subss %xmm1, %xmm0\n" /* line 253 */
        "jmp .Lf1ddb6e_001ddd27\n"
    );
}

/* line 399 */
static __attribute__((naked))
inflate_huft CG_GetHudElemInfo(const hudelem_t *elem, char *hudElemString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 399 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %edx, %esi\n" /* cghe */
        "movl %ecx, -0x44(%ebp)\n"
        /* { scope 1: from, to, lerp */
        "movl %eax, %edx\n" /* line 405 */
        "movl 0x14(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de60e\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de638\n"
        "testl %eax, %eax\n"
        "je .Lf1ddda8_001de424\n"
        "movb $0, 0x14(%esi)\n" /* line 427 | cghe */
        "movl -0x40(%ebp), %eax\n" /* line 429 */
        "movl 0x30(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf1ddda8_001de481\n"
        ".Lf1ddda8_001dddea:\n"
        "movl %eax, %edx\n"
        ".Lf1ddda8_001dddec:\n"
        "movb $0, 0x118(%esi)\n" /* line 432 | cghe */
        "movl (%edx), %eax\n" /* line 434 */
        "cmpl $0xa, %eax\n"
        "ja .Lf1ddda8_001dde27\n"
        "jmpl *0x303930(, %eax, 4)\n"
        "movl $0x14, (%esp)\n" /* line 445 */
        "calll CL_GetConfigString\n"
        ".Lf1ddda8_001dde0d:\n"
        "movl $0x100, 8(%esp)\n" /* line 460 */
        "movl %eax, 4(%esp)\n"
        "leal 0x118(%esi), %eax\n" /* cghe */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        ".Lf1ddda8_001dde27:\n"
        "cmpb $0, 0x14(%esi)\n" /* line 466 | cghe */
        "je .Lf1ddda8_001ddf50\n"
        "cmpb $0, 0x118(%esi)\n" /* cghe */
        "je .Lf1ddda8_001de66d\n"
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* labelIndex */
        "jmp .Lf1ddda8_001dde5e\n"
        /* { scope 2 */
        ".Lf1ddda8_001dde44:\n"
        "leal 1(%ebx), %edx\n" /* line 374 | labelIndex */
        ".Lf1ddda8_001dde47:\n"
        "movl -0x44(%ebp), %ebx\n" /* line 376 | labelIndex */
        "movb %al, (%ecx, %ebx)\n"
        "addl $1, %ecx\n" /* line 377 */
        "cmpl $0xff, %ecx\n" /* line 367 */
        "je .Lf1ddda8_001de96b\n"
        "movl %edx, %ebx\n" /* labelIndex */
        ".Lf1ddda8_001dde5e:\n"
        "movzbl 0x14(%ebx, %esi), %eax\n" /* labelIndex */
        "testb %al, %al\n"
        "je .Lf1ddda8_001dde7f\n"
        "cmpb $0x26, %al\n" /* line 371 */
        "jne .Lf1ddda8_001dde44\n"
        "leal 1(%ebx), %edx\n" /* labelIndex */
        "cmpb $0x26, 0x14(%edx, %esi)\n"
        "jne .Lf1ddda8_001dde47\n"
        "cmpb $0x31, 0x16(%ebx, %esi)\n" /* labelIndex */
        "jne .Lf1ddda8_001dde47\n"
        "addl $3, %ebx\n" /* line 373 | labelIndex */
        ".Lf1ddda8_001dde7f:\n"
        "cmpl $0xfe, %ecx\n" /* line 379 */
        "jg .Lf1ddda8_001ddef1\n"
        "movzbl 0x118(%esi), %eax\n"
        "testb %al, %al\n"
        "je .Lf1ddda8_001ddec0\n"
        "movl -0x44(%ebp), %edx\n"
        "leal (%ecx, %edx), %edi\n" /* hours */
        "movl %esi, %edx\n"
        ".Lf1ddda8_001dde9a:\n"
        "movb %al, (%edi)\n" /* line 381 | hours */
        "addl $1, %ecx\n" /* line 382 */
        "cmpl $0xff, %ecx\n" /* line 379 */
        "je .Lf1ddda8_001ddef1\n"
        "movzbl 0x119(%edx), %eax\n"
        "addl $1, %edi\n" /* hours */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lf1ddda8_001dde9a\n"
        "cmpl $0xfe, %ecx\n" /* line 384 */
        "jg .Lf1ddda8_001ddef1\n"
        ".Lf1ddda8_001ddec0:\n"
        "movzbl 0x14(%ebx, %esi), %eax\n" /* labelIndex */
        "testb %al, %al\n"
        "je .Lf1ddda8_001ddef1\n"
        "movl -0x44(%ebp), %edi\n" /* hours */
        "addl %ecx, %edi\n" /* hours */
        "leal 0x14(%ebx, %esi), %edx\n" /* labelIndex */
        ".Lf1ddda8_001dded2:\n"
        "movb %al, (%edi)\n" /* line 386 | hours */
        "addl $1, %ecx\n" /* line 387 */
        "cmpl $0xff, %ecx\n" /* line 384 */
        "je .Lf1ddda8_001de96b\n"
        "movzbl 1(%edx), %eax\n"
        "addl $1, %edi\n" /* hours */
        "addl $1, %edx\n"
        "testb %al, %al\n"
        "jne .Lf1ddda8_001dded2\n"
        ".Lf1ddda8_001ddef1:\n"
        "movl -0x44(%ebp), %eax\n" /* line 391 */
        "movb $0, (%eax, %ecx)\n"
        "leal 0x118(%esi), %ebx\n" /* line 392 | labelIndex */
        "movl $0x100, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* labelIndex */
        "calll memcpy\n"
        "movl 0x220(%esi), %eax\n" /* line 40 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 393 */
        "movss %xmm0, 0x218(%esi)\n"
        "movb $0, 0x14(%esi)\n" /* line 394 */
        "movl $0, 0x114(%esi)\n" /* line 395 */
        /* } scope */
        ".Lf1ddda8_001ddf50:\n"
        "movl $0, 0x114(%esi)\n" /* line 472 | cghe */
        ".Lf1ddda8_001ddf5a:\n"
        "cmpb $0, 0x118(%esi)\n" /* line 474 | cghe */
        "jne .Lf1ddda8_001de5cf\n"
        "pxor %xmm4, %xmm4\n" /* line 477 */
        "movss %xmm4, 0x218(%esi)\n" /* cghe */
        ".Lf1ddda8_001ddf73:\n"
        "movl -0x40(%ebp), %edx\n" /* line 164 */
        "cmpl $0xd, (%edx)\n"
        "ja .Lf1ddda8_001de1bf\n"
        "movl (%edx), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x7be, %eax\n"
        "je .Lf1ddda8_001de498\n"
        "movss 0x114(%esi), %xmm0\n" /* line 175 */
        "addss 0x218(%esi), %xmm0\n"
        "movl -0x40(%ebp), %edx\n"
        "movss %xmm0, 0xc(%esi)\n" /* line 479 | cghe */
        /* { scope 2 */
        "cmpl $0xd, (%edx)\n" /* line 194 */
        "jbe .Lf1ddda8_001de1d3\n"
        ".Lf1ddda8_001ddfb4:\n"
        "movaps %xmm4, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x10(%esi)\n" /* line 480 | cghe */
        /* { scope 2 */
        "movl -0x40(%ebp), %edx\n" /* line 308 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esi)\n"
        /* { scope 3: dummyWidth, dummyHeight */
        "movl %edx, %ecx\n" /* line 285 */
        "movl 0x64(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf1ddda8_001de214\n"
        ".Lf1ddda8_001ddfd2:\n"
        "movl 0x195f584, %eax\n" /* line 288 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x60(%ecx), %eax\n"
        "testl %eax, %eax\n" /* line 289 */
        "jle .Lf1ddda8_001de8fe\n"
        "cmpl %eax, %edx\n" /* line 291 */
        "jg .Lf1ddda8_001de21c\n"
        ".Lf1ddda8_001ddff2:\n"
        "movss 0x10(%esi), %xmm3\n"
        /* } scope */
        ".Lf1ddda8_001ddff7:\n"
        "leal 4(%esi), %ebx\n" /* line 316 | orgY */
        "movss 0xc(%esi), %xmm1\n"
        "movl -0x40(%ebp), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "movss 4(%eax), %xmm0\n"
        "movl 0x1c(%eax), %edx\n" /* alignScreen */
        "movl 0x18(%eax), %ecx\n"
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 229 */
        "sarl $2, %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de8cf\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de911\n"
        /* } scope */
        ".Lf1ddda8_001de02c:\n"
        "movss %xmm0, (%esi)\n" /* line 271 | x */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de8ed\n"
        ".Lf1ddda8_001de03e:\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de908\n"
        /* } scope */
        ".Lf1ddda8_001de047:\n"
        "movss %xmm2, (%ebx)\n" /* line 272 | y, minutes */
        "movl $0, -0x20(%ebp)\n" /* line 273 | dummyWidth */
        "movl $0, -0x1c(%ebp)\n" /* line 274 | dummyHeight */
        "movl %edx, %eax\n" /* line 277 */
        "andl $7, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "sarl $3, %edx\n"
        "andl $7, %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* dummyHeight */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* dummyWidth */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* minutes */
        "movl %esi, (%esp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movss 0x2ed5d8, %xmm1\n" /* line 428 | 0.5f */
        "movss (%esi), %xmm0\n" /* cghe */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x68(%ebp)\n"
        "calll floorf\n"
        "fstps -0x4c(%ebp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%esi)\n" /* cghe */
        "movss -0x68(%ebp), %xmm1\n"
        "addss 4(%esi), %xmm1\n" /* cghe */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x50(%ebp)\n"
        "cvttss2si -0x50(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esi)\n" /* cghe */
        /* } scope */
        "movl 0x195f584, %eax\n" /* line 488 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl -0x40(%ebp), %edx\n"
        "subl 0x28(%edx), %eax\n"
        "movl 0x2c(%edx), %edx\n" /* line 490 */
        "testl %edx, %edx\n"
        "jle .Lf1ddda8_001de3c1\n"
        ".Lf1ddda8_001de0f8:\n"
        "cmpl %edx, %eax\n"
        "jge .Lf1ddda8_001de3c1\n"
        "pxor %xmm2, %xmm2\n" /* line 492 */
        "testl %eax, %eax\n"
        "js .Lf1ddda8_001de10c\n"
        "cvtsi2ssl %eax, %xmm2\n"
        ".Lf1ddda8_001de10c:\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 495 */
        "divss %xmm0, %xmm2\n"
        "movl -0x40(%ebp), %ebx\n" /* line 502 | labelIndex */
        "movzbl 0x24(%ebx), %edx\n" /* labelIndex */
        "cvtsi2ssl %edx, %xmm1\n"
        "movzbl 0x20(%ebx), %eax\n" /* labelIndex */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2ed5cc, %xmm3\n" /* 0.003921568859368563f */
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, 0x228(%esi)\n" /* cghe */
        "movzbl 0x25(%ebx), %edx\n" /* line 503 | labelIndex */
        "cvtsi2ssl %edx, %xmm1\n"
        "movzbl 0x21(%ebx), %eax\n" /* labelIndex */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, 0x22c(%esi)\n" /* cghe */
        "movzbl 0x26(%ebx), %edx\n" /* line 504 | labelIndex */
        "cvtsi2ssl %edx, %xmm1\n"
        "movzbl 0x22(%ebx), %eax\n" /* labelIndex */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, 0x230(%esi)\n" /* cghe */
        "movzbl 0x27(%ebx), %edx\n" /* line 505 | labelIndex */
        "cvtsi2ssl %edx, %xmm1\n"
        "movzbl 0x23(%ebx), %eax\n" /* labelIndex */
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "movss %xmm1, 0x234(%esi)\n" /* cghe */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: from, to, lerp */
        ".Lf1ddda8_001de1bf:\n"
        "movaps %xmm4, %xmm0\n" /* line 164 */
        "movl -0x40(%ebp), %edx\n"
        ".Lf1ddda8_001de1c5:\n"
        "movss %xmm0, 0xc(%esi)\n" /* line 479 | cghe */
        /* { scope 2 */
        "cmpl $0xd, (%edx)\n" /* line 194 */
        "ja .Lf1ddda8_001ddfb4\n"
        ".Lf1ddda8_001de1d3:\n"
        "movl (%edx), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x7be, %eax\n"
        "je .Lf1ddda8_001de530\n"
        "movss 0x224(%esi), %xmm2\n" /* line 205 */
        "movaps %xmm2, %xmm1\n"
        ".Lf1ddda8_001de1f2:\n"
        "movaps %xmm1, %xmm0\n" /* line 220 */
        "maxss %xmm2, %xmm0\n"
        /* } scope */
        "movss %xmm0, 0x10(%esi)\n" /* line 480 | cghe */
        /* { scope 2 */
        "movl -0x40(%ebp), %edx\n" /* line 308 */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esi)\n"
        /* { scope 3: dummyWidth, dummyHeight */
        "movl %edx, %ecx\n" /* line 285 */
        "movl 0x64(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jg .Lf1ddda8_001ddfd2\n"
        ".Lf1ddda8_001de214:\n"
        "movaps %xmm0, %xmm3\n"
        "jmp .Lf1ddda8_001ddff7\n"
        ".Lf1ddda8_001de21c:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 294 */
        "movss %xmm0, -0x3c(%ebp)\n" /* lerp */
        "cvtsi2ssl %edx, %xmm0\n"
        "movss -0x3c(%ebp), %xmm1\n" /* lerp */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* lerp */
        /* } scope */
        "ucomiss 0x2ed5d0, %xmm1\n" /* line 314 | 1.0f */
        "je .Lf1ddda8_001de662\n"
        ".Lf1ddda8_001de244:\n"
        "movss 0x10(%esi), %xmm3\n" /* line 322 */
        "movss 0xc(%esi), %xmm1\n"
        "movl -0x40(%ebp), %edx\n" /* alignScreen */
        "movss 0x54(%edx), %xmm2\n"
        "movss 0x50(%edx), %xmm0\n"
        "movl %edx, %ecx\n" /* alignScreen */
        "movl 0x5c(%edx), %edx\n" /* alignScreen */
        "movl 0x58(%ecx), %ecx\n"
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 229 */
        "sarl $2, %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de92b\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de6ed\n"
        /* } scope */
        ".Lf1ddda8_001de27d:\n"
        "movss %xmm0, -0x30(%ebp)\n" /* line 271 | x, from */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de91a\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de6e4\n"
        /* } scope */
        ".Lf1ddda8_001de299:\n"
        "movss %xmm2, -0x2c(%ebp)\n" /* line 272 | y */
        "movl $0, -0x20(%ebp)\n" /* line 273 | dummyWidth */
        "movl $0, -0x1c(%ebp)\n" /* line 274 | dummyHeight */
        "movl %edx, %eax\n" /* line 277 */
        "andl $7, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "sarl $3, %edx\n"
        "andl $7, %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %edi\n" /* dummyHeight, hours */
        "movl %edi, 0xc(%esp)\n" /* hours */
        "leal -0x20(%ebp), %ebx\n" /* dummyWidth, minutes */
        "movl %ebx, 8(%esp)\n" /* minutes */
        "leal -0x30(%ebp), %edx\n" /* from */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movss 0x10(%esi), %xmm3\n" /* line 323 */
        "movss 0xc(%esi), %xmm1\n"
        "movl -0x40(%ebp), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "movss 4(%eax), %xmm0\n"
        "movl 0x1c(%eax), %edx\n" /* alignScreen */
        "movl 0x18(%eax), %ecx\n"
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 229 */
        "sarl $2, %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de94d\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de6db\n"
        /* } scope */
        ".Lf1ddda8_001de316:\n"
        "movss %xmm0, -0x28(%ebp)\n" /* line 271 | x, to */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1ddda8_001de93c\n"
        "cmpl $2, %eax\n"
        "je .Lf1ddda8_001de6d2\n"
        /* } scope */
        ".Lf1ddda8_001de332:\n"
        "movss %xmm2, -0x24(%ebp)\n" /* line 272 | y */
        "xorl %eax, %eax\n" /* line 273 */
        "movl %eax, -0x20(%ebp)\n" /* dummyWidth */
        "movl %eax, -0x1c(%ebp)\n" /* line 274 | dummyHeight */
        "movl %edx, %eax\n" /* line 277 */
        "andl $7, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "sarl $3, %edx\n"
        "andl $7, %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n" /* hours */
        "movl %ebx, 8(%esp)\n" /* minutes */
        "leal -0x28(%ebp), %edx\n" /* to */
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movss -0x30(%ebp), %xmm1\n" /* line 324 | from */
        "movss -0x28(%ebp), %xmm0\n" /* to */
        "subss %xmm1, %xmm0\n"
        "mulss -0x3c(%ebp), %xmm0\n" /* lerp */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, (%esi)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 325 */
        "movss -0x24(%ebp), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss -0x3c(%ebp), %xmm0\n" /* lerp */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esi)\n"
        /* } scope */
        "movl 0x195f584, %eax\n" /* line 488 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "movl -0x40(%ebp), %edx\n"
        "subl 0x28(%edx), %eax\n"
        "movl 0x2c(%edx), %edx\n" /* line 490 */
        "testl %edx, %edx\n"
        "jg .Lf1ddda8_001de0f8\n"
        ".Lf1ddda8_001de3c1:\n"
        "movl -0x40(%ebp), %edx\n" /* line 509 */
        "movzbl 0x20(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x228(%esi)\n" /* cghe */
        "movzbl 0x21(%edx), %eax\n" /* line 510 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x22c(%esi)\n" /* cghe */
        "movzbl 0x22(%edx), %eax\n" /* line 511 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x230(%esi)\n" /* cghe */
        "movzbl 0x23(%edx), %eax\n" /* line 512 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, 0x234(%esi)\n" /* cghe */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 519 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: from, to, lerp */
        ".Lf1ddda8_001de424:\n"
        "movss 0x2ed604, %xmm0\n" /* line 408 | 0.25f */
        "mulss 0x10(%edx), %xmm0\n"
        "movss %xmm0, 0x220(%esi)\n" /* cghe */
        "movss %xmm0, 4(%esp)\n" /* line 409 */
        "movl $0, (%esp)\n"
        ".Lf1ddda8_001de446:\n"
        "calll UI_GetFontHandle\n" /* line 419 */
        "movl %eax, 0x21c(%esi)\n" /* cghe */
        "movl 0x220(%esi), %edx\n" /* line 420 | cghe */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss %xmm1, 0x224(%esi)\n" /* cghe */
        "movb $0, 0x14(%esi)\n" /* line 427 | cghe */
        "movl -0x40(%ebp), %eax\n" /* line 429 */
        "movl 0x30(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1ddda8_001dddea\n"
        ".Lf1ddda8_001de481:\n"
        "leal 0x14(%esi), %eax\n" /* line 430 | cghe */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_SafeTranslateHudElemString\n"
        "movl -0x40(%ebp), %edx\n"
        "jmp .Lf1ddda8_001dddec\n"
        ".Lf1ddda8_001de498:\n"
        "testl $0x1840, %eax\n" /* line 164 */
        "je .Lf1ddda8_001de6ba\n"
        "movss 0x114(%esi), %xmm6\n" /* line 179 */
        /* { scope 2 */
        "movl -0x40(%ebp), %ecx\n" /* line 134 */
        "movl 0x34(%ecx), %eax\n" /* width */
        /* { scope 3: dummyWidth, dummyHeight */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1ddda8_001de95e\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        /* } scope */
        ".Lf1ddda8_001de4bd:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 135 | minutes */
        "movl 0x4c(%ebx), %edx\n" /* minutes */
        "testl %edx, %edx\n"
        "jle .Lf1ddda8_001de521\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n" /* minutes */
        "cmpl %eax, %edx\n"
        "jle .Lf1ddda8_001de521\n"
        "movl 0x40(%ebx), %ecx\n" /* line 138 | minutes, width */
        /* { scope 3: dummyWidth, dummyHeight */
        "testl %ecx, %ecx\n" /* line 121 */
        "je .Lf1ddda8_001de993\n"
        "cvtsi2ssl %ecx, %xmm5\n" /* line 122 */
        /* } scope */
        ".Lf1ddda8_001de4ea:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 139 */
        "cvtsi2ssl %edx, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm7\n"
        "divss %xmm0, %xmm7\n"
        "mulss %xmm7, %xmm1\n"
        "ucomiss %xmm1, %xmm4\n" /* line 406 */
        "ja .Lf1ddda8_001dead4\n"
        "minss %xmm1, %xmm3\n" /* line 408 */
        "movaps %xmm3, %xmm1\n"
        ".Lf1ddda8_001de515:\n"
        "subss %xmm5, %xmm2\n" /* line 141 */
        "mulss %xmm1, %xmm2\n"
        "addss %xmm5, %xmm2\n"
        /* } scope */
        ".Lf1ddda8_001de521:\n"
        "movaps %xmm2, %xmm0\n" /* line 179 */
        "addss %xmm6, %xmm0\n"
        "movl -0x40(%ebp), %edx\n"
        "jmp .Lf1ddda8_001de1c5\n"
        /* { scope 2 */
        ".Lf1ddda8_001de530:\n"
        "testl $0x2040, %eax\n" /* line 194 */
        "jne .Lf1ddda8_001de6a5\n"
        "testb $0x18, %ah\n"
        "je .Lf1ddda8_001ddfb4\n"
        /* { scope 3: dummyWidth, dummyHeight */
        "movl -0x40(%ebp), %ecx\n" /* line 151 */
        "movl 0x38(%ecx), %eax\n" /* width */
        /* { scope 4 */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1ddda8_001de97c\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        "movss 0x224(%esi), %xmm1\n"
        /* } scope */
        ".Lf1ddda8_001de55e:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 152 | minutes */
        "movl 0x4c(%ebx), %edx\n" /* minutes */
        "testl %edx, %edx\n"
        "jle .Lf1ddda8_001de1f2\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n" /* minutes */
        "cmpl %eax, %edx\n"
        "jle .Lf1ddda8_001de1f2\n"
        "movl 0x44(%ebx), %ecx\n" /* line 155 | minutes, width */
        /* { scope 4 */
        "testl %ecx, %ecx\n" /* line 121 */
        "je .Lf1ddda8_001deacc\n"
        "cvtsi2ssl %ecx, %xmm6\n" /* line 122 */
        /* } scope */
        ".Lf1ddda8_001de593:\n"
        "cvtsi2ssl %eax, %xmm3\n" /* line 156 */
        "cvtsi2ssl %edx, %xmm0\n"
        "movss 0x2ed5d0, %xmm5\n" /* 1.0f */
        "movaps %xmm5, %xmm7\n"
        "divss %xmm0, %xmm7\n"
        "mulss %xmm7, %xmm3\n"
        "ucomiss %xmm3, %xmm4\n" /* line 406 */
        "ja .Lf1ddda8_001deadc\n"
        "minss %xmm3, %xmm5\n" /* line 408 */
        "movaps %xmm5, %xmm3\n"
        ".Lf1ddda8_001de5be:\n"
        "subss %xmm6, %xmm2\n" /* line 158 */
        "mulss %xmm3, %xmm2\n"
        "addss %xmm6, %xmm2\n"
        "jmp .Lf1ddda8_001de1f2\n"
        /* } scope */
        /* } scope */
        ".Lf1ddda8_001de5cf:\n"
        "movl 0x220(%esi), %eax\n" /* line 40 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal 0x118(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 475 */
        "movss %xmm0, 0x218(%esi)\n" /* cghe */
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf1ddda8_001ddf73\n"
        ".Lf1ddda8_001de60e:\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 413 | 0.5f */
        "movl -0x40(%ebp), %ecx\n"
        "mulss 0x10(%ecx), %xmm0\n"
        "movss %xmm0, 0x220(%esi)\n" /* cghe */
        "movss %xmm0, 4(%esp)\n" /* line 414 */
        "movl $4, (%esp)\n"
        "jmp .Lf1ddda8_001de446\n"
        ".Lf1ddda8_001de638:\n"
        "movss 0x2eda84, %xmm0\n" /* line 418 | 0.3333333432674408f */
        "movl -0x40(%ebp), %ebx\n" /* labelIndex */
        "mulss 0x10(%ebx), %xmm0\n" /* labelIndex */
        "movss %xmm0, 0x220(%esi)\n" /* cghe */
        "movss %xmm0, 4(%esp)\n" /* line 419 */
        "movl $5, (%esp)\n"
        "jmp .Lf1ddda8_001de446\n"
        /* { scope 2 */
        ".Lf1ddda8_001de662:\n"
        "jnp .Lf1ddda8_001ddff2\n" /* line 314 */
        "jmp .Lf1ddda8_001de244\n"
        /* } scope */
        ".Lf1ddda8_001de66d:\n"
        "movl 0x220(%esi), %eax\n" /* line 40 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x21c(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal 0x14(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 470 */
        "movss %xmm0, 0x114(%esi)\n" /* cghe */
        "jmp .Lf1ddda8_001ddf5a\n"
        /* { scope 2 */
        ".Lf1ddda8_001de6a5:\n"
        "movl -0x40(%ebp), %eax\n" /* line 213 */
        "cvtsi2ssl 0x38(%eax), %xmm2\n"
        "movss 0x224(%esi), %xmm1\n"
        "jmp .Lf1ddda8_001de1f2\n"
        /* } scope */
        ".Lf1ddda8_001de6ba:\n"
        "testb $0x20, %ah\n" /* line 164 */
        "je .Lf1ddda8_001de1bf\n"
        "movl -0x40(%ebp), %eax\n" /* line 181 */
        "cvtsi2ssl 0x34(%eax), %xmm0\n"
        "movl %eax, %edx\n"
        "jmp .Lf1ddda8_001de1c5\n"
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ddda8_001de6d2:\n"
        "subss %xmm3, %xmm2\n" /* line 253 */
        "jmp .Lf1ddda8_001de332\n"
        /* } scope */
        /* { scope 5 */
        ".Lf1ddda8_001de6db:\n"
        "subss %xmm1, %xmm0\n" /* line 236 */
        "jmp .Lf1ddda8_001de316\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ddda8_001de6e4:\n"
        "subss %xmm3, %xmm2\n" /* line 253 */
        "jmp .Lf1ddda8_001de299\n"
        /* } scope */
        /* { scope 5 */
        ".Lf1ddda8_001de6ed:\n"
        "subss %xmm1, %xmm0\n" /* line 236 */
        "jmp .Lf1ddda8_001de27d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        "subl $7, %eax\n" /* line 48 */
        "cmpl $5, %eax\n"
        "jbe .Lf1ddda8_001de975\n"
        ".Lf1ddda8_001de702:\n"
        "xorl %ecx, %ecx\n" /* line 69 */
        /* } scope */
        ".Lf1ddda8_001de704:\n"
        "movl $0x7482296b, %eax\n" /* line 105 */
        "imull %ecx\n"
        "movl %edx, %edi\n" /* hours */
        "sarl $0xe, %edi\n" /* hours */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edi\n" /* hours */
        "leal (%edi, %edi, 4), %eax\n" /* line 106 | hours */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "subl %eax, %ecx\n"
        "movl $0x1b4e81b5, %eax\n" /* line 107 */
        "imull %ecx\n"
        "movl %edx, %ebx\n" /* minutes */
        "sarl $6, %ebx\n" /* minutes */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* minutes */
        "leal (%ebx, %ebx, 4), %edx\n" /* line 108 | minutes */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $3, %eax\n"
        "subl %eax, %ecx\n"
        "movl $0x66666667, %eax\n" /* line 109 */
        "imull %ecx\n"
        "sarl $2, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 110 */
        "addl %eax, %eax\n"
        "subl %eax, %ecx\n"
        "testl %edi, %edi\n" /* line 112 | hours */
        "je .Lf1ddda8_001deaaf\n"
        "movl %ecx, 0x10(%esp)\n" /* line 113 */
        "movl %edx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* minutes */
        "movl %edi, 4(%esp)\n" /* hours */
        "movl $0x2b804c, (%esp)\n" /* "%i:%02i:%02i.%i" */
        "calll va\n"
        "jmp .Lf1ddda8_001dde0d\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        "subl $7, %eax\n" /* line 48 */
        "cmpl $5, %eax\n"
        "jbe .Lf1ddda8_001de98c\n"
        ".Lf1ddda8_001de79c:\n"
        "xorl %ecx, %ecx\n" /* line 69 */
        /* } scope */
        ".Lf1ddda8_001de79e:\n"
        "movl $0x91a2b3c5, %edx\n" /* line 84 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "leal (%edx, %ecx), %edi\n" /* hours */
        "sarl $0xb, %edi\n" /* hours */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edi\n" /* hours */
        "movl %edi, %eax\n" /* line 85 | hours */
        "shll $4, %eax\n"
        "movl %edi, %edx\n" /* hours */
        "shll $8, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "movl $0x88888889, %edx\n" /* line 86 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "leal (%edx, %ecx), %ebx\n" /* minutes */
        "sarl $5, %ebx\n" /* minutes */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %ebx\n" /* minutes */
        "leal (, %ebx, 4), %edx\n" /* line 87 */
        "movl %ebx, %eax\n" /* minutes */
        "shll $6, %eax\n"
        "subl %edx, %eax\n"
        "subl %eax, %ecx\n"
        "testl %edi, %edi\n" /* line 89 | hours */
        "je .Lf1ddda8_001dea96\n"
        "movl %ecx, 0xc(%esp)\n" /* line 90 */
        "movl %ebx, 8(%esp)\n" /* minutes */
        "movl %edi, 4(%esp)\n" /* hours */
        "movl $0x2b8034, (%esp)\n" /* "%i:%02i:%02i" */
        "calll va\n"
        "jmp .Lf1ddda8_001dde0d\n"
        /* } scope */
        "movl $0x13, (%esp)\n" /* line 442 */
        "calll CL_GetConfigString\n"
        "jmp .Lf1ddda8_001dde0d\n"
        "movl -0x40(%ebp), %ebx\n" /* line 448 | labelIndex */
        "movl 0x74(%ebx), %edx\n" /* labelIndex */
        "testl %edx, %edx\n"
        "je .Lf1ddda8_001dde27\n"
        "leal 0x118(%esi), %eax\n" /* line 449 | cghe */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CG_SafeTranslateHudElemString\n"
        "jmp .Lf1ddda8_001dde27\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movl -0x40(%ebp), %ecx\n"
        "addss 0x70(%ecx), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x48(%ebp)\n"
        "cvttss2si -0x48(%ebp), %ecx\n"
        "cmpl $0x3f, %ecx\n" /* line 438 */
        "ja .Lf1ddda8_001dde27\n"
        "movl $0x100, 8(%esp)\n" /* line 439 */
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl 0x195f584, %edx\n"
        "movl (%edx), %edx\n"
        "leal 0xe0920(%edx, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x118(%esi), %eax\n" /* cghe */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf1ddda8_001dde27\n"
        "movl -0x40(%ebp), %ecx\n" /* line 460 */
        "cvtss2sd 0x70(%ecx), %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x217c20, (%esp)\n" /* "%g" */
        "calll va\n"
        "jmp .Lf1ddda8_001dde0d\n"
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ddda8_001de8cf:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 234 | -0.5f */
        "addss %xmm1, %xmm0\n"
        /* } scope */
        "movss %xmm0, (%esi)\n" /* line 271 | x */
        /* { scope 5 */
        "movl %ecx, %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "jne .Lf1ddda8_001de03e\n"
        ".Lf1ddda8_001de8ed:\n"
        "mulss 0x2ed63c, %xmm3\n" /* line 251 | -0.5f */
        "addss %xmm3, %xmm2\n"
        "jmp .Lf1ddda8_001de047\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1ddda8_001de8fe:\n"
        "movss %xmm4, -0x3c(%ebp)\n" /* line 428 | lerp */
        "jmp .Lf1ddda8_001de244\n"
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ddda8_001de908:\n"
        "subss %xmm3, %xmm2\n" /* line 253 */
        "jmp .Lf1ddda8_001de047\n"
        /* } scope */
        /* { scope 5 */
        ".Lf1ddda8_001de911:\n"
        "subss %xmm1, %xmm0\n" /* line 236 */
        "jmp .Lf1ddda8_001de02c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ddda8_001de91a:\n"
        "mulss 0x2ed63c, %xmm3\n" /* line 251 | -0.5f */
        "addss %xmm3, %xmm2\n"
        "jmp .Lf1ddda8_001de299\n"
        /* } scope */
        /* { scope 5 */
        ".Lf1ddda8_001de92b:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 234 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1ddda8_001de27d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1ddda8_001de93c:\n"
        "mulss 0x2ed63c, %xmm3\n" /* line 251 | -0.5f */
        "addss %xmm3, %xmm2\n"
        "jmp .Lf1ddda8_001de332\n"
        /* } scope */
        /* { scope 5 */
        ".Lf1ddda8_001de94d:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 234 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1ddda8_001de316\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        ".Lf1ddda8_001de95e:\n"
        "movss 0x224(%esi), %xmm2\n" /* line 124 */
        "jmp .Lf1ddda8_001de4bd\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1ddda8_001de96b:\n"
        "movl $0xff, %ecx\n" /* line 384 */
        "jmp .Lf1ddda8_001ddef1\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        ".Lf1ddda8_001de975:\n"
        "jmpl *0x30395c(, %eax, 4)\n" /* line 48 */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        ".Lf1ddda8_001de97c:\n"
        "movss 0x224(%esi), %xmm2\n" /* line 124 */
        "movaps %xmm2, %xmm1\n"
        "jmp .Lf1ddda8_001de55e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        ".Lf1ddda8_001de98c:\n"
        "jmpl *0x303974(, %eax, 4)\n" /* line 48 */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        ".Lf1ddda8_001de993:\n"
        "movss 0x224(%esi), %xmm5\n" /* line 124 */
        "jmp .Lf1ddda8_001de4ea\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        "movl 0x195f584, %eax\n" /* line 51 */
        "movl (%eax), %edx\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "subl 0x25bb0(%edx), %eax\n"
        "leal 0x3e7(%eax), %ebx\n" /* time */
        ".Lf1ddda8_001de9b9:\n"
        "testl %ebx, %ebx\n" /* line 69 | time */
        "js .Lf1ddda8_001de702\n"
        "movl $0x51eb851f, %eax\n"
        "imull %ebx\n" /* time */
        "movl %edx, %ecx\n"
        "sarl $5, %ecx\n"
        "movl %ebx, %eax\n" /* time */
        "sarl $0x1f, %eax\n"
        "subl %eax, %ecx\n"
        "jmp .Lf1ddda8_001de704\n"
        "movl 0x195f584, %eax\n" /* line 54 */
        "movl (%eax), %edx\n"
        "movl -0x40(%ebp), %ebx\n" /* time */
        "movl 0x68(%ebx), %eax\n" /* time */
        "subl 0x25bb0(%edx), %eax\n"
        "leal 0x63(%eax), %ebx\n" /* time */
        "jmp .Lf1ddda8_001de9b9\n"
        "movl 0x195f584, %eax\n" /* line 57 */
        "movl (%eax), %eax\n"
        "movl -0x40(%ebp), %edx\n"
        "movl 0x68(%edx), %ebx\n" /* time */
        "subl 0x25bb0(%eax), %ebx\n" /* time */
        "jmp .Lf1ddda8_001de9b9\n"
        "movl 0x195f584, %eax\n" /* line 62 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %ebx\n" /* time */
        "movl -0x40(%ebp), %ecx\n"
        "subl 0x68(%ecx), %ebx\n" /* time */
        "jmp .Lf1ddda8_001de9b9\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        "movl 0x195f584, %eax\n" /* line 51 */
        "movl (%eax), %edx\n"
        "movl -0x40(%ebp), %ecx\n"
        "movl 0x68(%ecx), %eax\n"
        "subl 0x25bb0(%edx), %eax\n"
        "leal 0x3e7(%eax), %ebx\n" /* time */
        ".Lf1ddda8_001dea34:\n"
        "testl %ebx, %ebx\n" /* line 69 | time */
        "js .Lf1ddda8_001de79c\n"
        "movl $0x10624dd3, %eax\n"
        "imull %ebx\n" /* time */
        "movl %edx, %ecx\n"
        "sarl $6, %ecx\n"
        "movl %ebx, %eax\n" /* time */
        "sarl $0x1f, %eax\n"
        "subl %eax, %ecx\n"
        "jmp .Lf1ddda8_001de79e\n"
        "movl 0x195f584, %eax\n" /* line 54 */
        "movl (%eax), %edx\n"
        "movl -0x40(%ebp), %ebx\n" /* time */
        "movl 0x68(%ebx), %eax\n" /* time */
        "subl 0x25bb0(%edx), %eax\n"
        "leal 0x63(%eax), %ebx\n" /* time */
        "jmp .Lf1ddda8_001dea34\n"
        "movl 0x195f584, %eax\n" /* line 57 */
        "movl (%eax), %eax\n"
        "movl -0x40(%ebp), %edx\n"
        "movl 0x68(%edx), %ebx\n" /* time */
        "subl 0x25bb0(%eax), %ebx\n" /* time */
        "jmp .Lf1ddda8_001dea34\n"
        "movl 0x195f584, %eax\n" /* line 62 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %ebx\n" /* time */
        "movl -0x40(%ebp), %ecx\n"
        "subl 0x68(%ecx), %ebx\n" /* time */
        "jmp .Lf1ddda8_001dea34\n"
        /* } scope */
        ".Lf1ddda8_001dea96:\n"
        "movl %ecx, 8(%esp)\n" /* line 92 */
        "movl %ebx, 4(%esp)\n" /* minutes */
        "movl $0x2b8044, (%esp)\n" /* "%i:%02i" */
        "calll va\n"
        "jmp .Lf1ddda8_001dde0d\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ddda8_001deaaf:\n"
        "movl %ecx, 0xc(%esp)\n" /* line 115 */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* minutes */
        "movl $0x2b805c, (%esp)\n" /* "%i:%02i.%i" */
        "calll va\n"
        "jmp .Lf1ddda8_001dde0d\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        /* { scope 4 */
        ".Lf1ddda8_001deacc:\n"
        "movaps %xmm1, %xmm6\n" /* line 124 */
        "jmp .Lf1ddda8_001de593\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf1ddda8_001dead4:\n"
        "movaps %xmm4, %xmm1\n" /* line 406 */
        "jmp .Lf1ddda8_001de515\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3: dummyWidth, dummyHeight */
        ".Lf1ddda8_001deadc:\n"
        "movaps %xmm4, %xmm3\n"
        "jmp .Lf1ddda8_001de5be\n"
    );
}

/* line 780 */
__attribute__((naked))
inflate_huft CG_Draw2dHudElems(qboolean foreground)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 780 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4dc, %esp\n"
        /* { scope 1: cghe, hudElemString */
        /* { scope 2: width, height, materialName, faceMaterial, ... */
        "movl 0x195f584, %eax\n" /* line 758 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, %edx\n"
        "xorl %esi, %esi\n"
        "addl $0x1734, %eax\n"
        "jmp .Lf1deae4_001deb1d\n"
        ".Lf1deae4_001deb08:\n"
        "movl %eax, -0x160(%ebp, %esi, 4)\n" /* line 764 */
        "addl $1, %esi\n" /* line 765 */
        "subl $-0x80, %eax\n"
        "subl $-0x80, %edx\n"
        "cmpl $0x1f, %esi\n" /* line 760 */
        "je .Lf1deae4_001deb27\n"
        ".Lf1deae4_001deb1d:\n"
        "movl 0x1728(%edx), %ebx\n" /* line 762 | i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf1deae4_001deb08\n"
        ".Lf1deae4_001deb27:\n"
        "movl %ecx, %eax\n" /* line 760 */
        "leal (, %esi, 4), %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "leal 0x7a8(%eax), %edx\n"
        "jmp .Lf1deae4_001deb55\n"
        ".Lf1deae4_001deb3a:\n"
        "movl %edx, -0x160(%ebp, %ecx)\n" /* line 771 */
        "addl $1, %esi\n" /* line 772 */
        "addl $1, %ebx\n" /* line 767 | i */
        "subl $-0x80, %edx\n"
        "subl $-0x80, %eax\n"
        "addl $4, %ecx\n"
        "cmpl $0x1f, %ebx\n" /* i */
        "je .Lf1deae4_001deb5f\n"
        ".Lf1deae4_001deb55:\n"
        "movl 0x7a8(%eax), %edi\n" /* line 769 | material */
        "testl %edi, %edi\n" /* material */
        "jne .Lf1deae4_001deb3a\n"
        ".Lf1deae4_001deb5f:\n"
        "movl $compare_hudelems, 0xc(%esp)\n" /* line 775 */
        "movl $4, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x160(%ebp), %eax\n" /* elems */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        /* } scope */
        "cmpl $0, %esi\n" /* line 787 | elemCount */
        "je .Lf1deae4_001dee60\n"
        "jle .Lf1deae4_001dee60\n" /* line 794 */
        "movl $0, -0x4a4(%ebp)\n" /* line 787 | i */
        "jmp .Lf1deae4_001debaf\n"
        ".Lf1deae4_001deb9c:\n"
        "addl $1, -0x4a4(%ebp)\n" /* line 794 | i */
        "cmpl %esi, -0x4a4(%ebp)\n" /* elemCount, i */
        "je .Lf1deae4_001dee60\n"
        ".Lf1deae4_001debaf:\n"
        "movl -0x4a4(%ebp), %eax\n" /* line 796 | i */
        "movl -0x160(%ebp, %eax, 4), %ebx\n" /* i */
        "movl 8(%ebp), %eax\n" /* foreground */
        "cmpl %eax, 0x7c(%ebx)\n" /* i */
        "jne .Lf1deae4_001deb9c\n"
        /* { scope 2: width, height, materialName, faceMaterial, ... */
        "cmpl $0xd, (%ebx)\n" /* line 668 */
        "je .Lf1deae4_001deb9c\n"
        "leal -0x260(%ebp), %ecx\n" /* line 671 | hudElemString */
        "leal -0x498(%ebp), %edi\n" /* cghe, material */
        "movl %edi, %edx\n" /* material */
        "movl %ebx, %eax\n"
        "calll CG_GetHudElemInfo\n"
        "pxor %xmm0, %xmm0\n" /* line 673 */
        "ucomiss -0x264(%ebp), %xmm0\n"
        "jp .Lf1deae4_001debed\n"
        "je .Lf1deae4_001deb9c\n"
        ".Lf1deae4_001debed:\n"
        "cmpb $0, -0x484(%ebp)\n" /* line 676 */
        "jne .Lf1deae4_001dee6b\n"
        ".Lf1deae4_001debfa:\n"
        "cmpl $0xc, (%ebx)\n" /* line 682 */
        "ja .Lf1deae4_001deb9c\n"
        "movl (%ebx), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x7be, %eax\n"
        "jne .Lf1deae4_001dee97\n"
        "testb $0x40, %al\n"
        "je .Lf1deae4_001deeb8\n"
        /* { scope 3 */
        "movl $0x40, 8(%esp)\n" /* line 595 */
        "leal -0x68(%ebp), %edi\n" /* materialName, material */
        "movl %edi, 4(%esp)\n" /* material */
        "movl 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_ServerMaterialName\n"
        "testl %eax, %eax\n"
        "je .Lf1deae4_001deb9c\n"
        "movl $7, 4(%esp)\n" /* line 597 */
        "movl %edi, (%esp)\n" /* material */
        "calll CL_RegisterMaterial\n"
        "movl %eax, %edi\n" /* material */
        /* { scope 4: dummyX, dummyY, dummyY */
        "movl 0x34(%ebx), %eax\n" /* line 134 | width */
        /* { scope 5 */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1deae4_001df227\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001dec5e:\n"
        "movl 0x4c(%ebx), %ecx\n" /* line 135 */
        "testl %ecx, %ecx\n"
        "jle .Lf1deae4_001df21e\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf1deae4_001df21e\n"
        "movl 0x40(%ebx), %edx\n" /* line 138 | width */
        /* { scope 5 */
        "testl %edx, %edx\n" /* line 121 */
        "je .Lf1deae4_001df3b2\n"
        "cvtsi2ssl %edx, %xmm4\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001dec90:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 139 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm5\n"
        "divss %xmm0, %xmm5\n"
        "mulss %xmm5, %xmm1\n"
        "pxor %xmm5, %xmm5\n" /* line 406 */
        "ucomiss %xmm1, %xmm5\n"
        "ja .Lf1deae4_001df3aa\n"
        "minss %xmm1, %xmm3\n" /* line 408 */
        "movaps %xmm3, %xmm1\n"
        ".Lf1deae4_001decbf:\n"
        "subss %xmm4, %xmm2\n" /* line 141 */
        "mulss %xmm1, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        /* } scope */
        ".Lf1deae4_001deccb:\n"
        "movss %xmm2, -0x20(%ebp)\n" /* line 599 | width */
        /* { scope 4: dummyX, dummyY, dummyY */
        "movl 0x38(%ebx), %eax\n" /* line 151 | width */
        /* { scope 5 */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1deae4_001df234\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001decdf:\n"
        "movl 0x4c(%ebx), %ecx\n" /* line 152 */
        "testl %ecx, %ecx\n"
        "jle .Lf1deae4_001ded40\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf1deae4_001ded40\n"
        "movl 0x44(%ebx), %edx\n" /* line 155 | width */
        /* { scope 5 */
        "testl %edx, %edx\n" /* line 121 */
        "je .Lf1deae4_001df37f\n"
        "cvtsi2ssl %edx, %xmm4\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001ded09:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 156 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm6\n"
        "divss %xmm0, %xmm6\n"
        "mulss %xmm6, %xmm1\n"
        "ucomiss %xmm1, %xmm5\n" /* line 406 */
        "ja .Lf1deae4_001df377\n"
        "minss %xmm1, %xmm3\n" /* line 408 */
        "movaps %xmm3, %xmm1\n"
        ".Lf1deae4_001ded34:\n"
        "subss %xmm4, %xmm2\n" /* line 158 */
        "mulss %xmm1, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        /* } scope */
        ".Lf1deae4_001ded40:\n"
        "movss %xmm2, -0x28(%ebp)\n" /* line 600 | height */
        "movss -0x488(%ebp), %xmm1\n" /* line 601 */
        "subss %xmm2, %xmm1\n"
        "xorps 0x303990, %xmm1\n"
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        "movl 0x64(%ebx), %edx\n" /* line 285 */
        "testl %edx, %edx\n"
        "jle .Lf1deae4_001ded9a\n"
        "movl 0x195f584, %eax\n" /* line 288 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x60(%ebx), %eax\n"
        "testl %eax, %eax\n" /* line 289 */
        "jle .Lf1deae4_001df24a\n"
        "cmpl %eax, %edx\n" /* line 291 */
        "jle .Lf1deae4_001ded9a\n"
        "cvtsi2ssl %eax, %xmm3\n" /* line 294 */
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        /* } scope */
        "ucomiss 0x2ed5d0, %xmm3\n" /* line 336 | 1.0f */
        "jne .Lf1deae4_001df24d\n"
        "jp .Lf1deae4_001df24d\n"
        ".Lf1deae4_001ded9a:\n"
        "movss -0x494(%ebp), %xmm0\n" /* line 337 */
        "movl 0x18(%ebx), %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1deae4_001df2df\n"
        "cmpl $2, %eax\n"
        "jne .Lf1deae4_001dedba\n"
        "subss %xmm1, %xmm0\n" /* line 253 */
        /* } scope */
        ".Lf1deae4_001dedba:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 603 | alignScreen */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        "movl $0, -0x24(%ebp)\n" /* line 352 | dummyX */
        "movl $0, -0x1c(%ebp)\n" /* line 353 | dummyY */
        "movl %eax, %edx\n" /* line 356 */
        "andl $7, %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "sarl $3, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* width */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* dummyY */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* dummyX */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x4b8(%ebp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movl %edi, 0x24(%esp)\n" /* line 604 | material */
        "leal -0x270(%ebp), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* width */
        "movl %eax, 8(%esp)\n"
        "movss -0x4b8(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl -0x498(%ebp), %eax\n" /* cghe */
        "movl %eax, (%esp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        "jmp .Lf1deae4_001deb9c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1deae4_001dee60:\n"
        "addl $0x4dc, %esp\n" /* line 803 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: cghe, hudElemString */
        /* { scope 2: width, height, materialName, faceMaterial, ... */
        ".Lf1deae4_001dee6b:\n"
        "leal -0x484(%ebp), %eax\n" /* line 678 */
        "movl %edi, %ecx\n" /* material */
        "movl %ebx, %edx\n"
        "calll CG_DrawHudElemString\n"
        "movss -0x498(%ebp), %xmm0\n" /* line 679 | cghe */
        "addss -0x384(%ebp), %xmm0\n"
        "movss %xmm0, -0x498(%ebp)\n" /* cghe */
        "jmp .Lf1deae4_001debfa\n"
        ".Lf1deae4_001dee97:\n"
        "cmpb $0, -0x380(%ebp)\n" /* line 693 */
        "je .Lf1deae4_001deb9c\n"
        "leal -0x380(%ebp), %eax\n" /* line 694 */
        "movl %edi, %ecx\n" /* material */
        "movl %ebx, %edx\n"
        "calll CG_DrawHudElemString\n"
        "jmp .Lf1deae4_001deb9c\n"
        ".Lf1deae4_001deeb8:\n"
        "testb $0x18, %ah\n" /* line 682 */
        "je .Lf1deae4_001deb9c\n"
        /* { scope 3 */
        "movl $0x3a, 8(%esp)\n" /* line 563 */
        "leal -0x68(%ebp), %edi\n" /* materialName, handMaterial */
        "movl %edi, 4(%esp)\n" /* handMaterial */
        "movl 0x3c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_ServerMaterialName\n"
        "testl %eax, %eax\n"
        "je .Lf1deae4_001deb9c\n"
        "movl $7, 4(%esp)\n" /* line 565 */
        "movl %edi, (%esp)\n" /* handMaterial */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, -0x4a0(%ebp)\n" /* faceMaterial */
        "movl $0x2b8068, 8(%esp)\n" /* line 566 */
        "movl $0x40, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* handMaterial */
        "calll I_strncat\n"
        "movl $7, 4(%esp)\n" /* line 567 */
        "movl %edi, (%esp)\n" /* handMaterial */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, %edi\n" /* handMaterial */
        "movl (%ebx), %eax\n" /* line 48 */
        "subl $7, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lf1deae4_001df241\n"
        "jmpl *0x3039a0(, %eax, 4)\n"
        "movl 0x195f584, %eax\n" /* line 51 */
        "movl (%eax), %edx\n"
        "movl 0x68(%ebx), %eax\n"
        "subl 0x25bb0(%edx), %eax\n"
        "leal 0x3e7(%eax), %edx\n"
        ".Lf1deae4_001def4e:\n"
        "testl %edx, %edx\n" /* line 69 */
        "js .Lf1deae4_001df241\n"
        "cvtsi2ssl %edx, %xmm1\n"
        ".Lf1deae4_001def5a:\n"
        "movl 0x6c(%ebx), %eax\n" /* line 570 */
        "testl %eax, %eax\n"
        "je .Lf1deae4_001df2b5\n"
        "mulss 0x2ed638, %xmm1\n" /* line 571 | 360.0f */
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x49c(%ebp)\n" /* angle */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001def85:\n"
        "movl 0x34(%ebx), %eax\n" /* line 134 | width */
        /* { scope 5 */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1deae4_001df2a8\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001def94:\n"
        "movl 0x4c(%ebx), %ecx\n" /* line 135 */
        "testl %ecx, %ecx\n"
        "jle .Lf1deae4_001df29f\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf1deae4_001df29f\n"
        "movl 0x40(%ebx), %edx\n" /* line 138 | width */
        /* { scope 5 */
        "testl %edx, %edx\n" /* line 121 */
        "je .Lf1deae4_001df2f0\n"
        "cvtsi2ssl %edx, %xmm4\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001defc6:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 139 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm5\n"
        "divss %xmm0, %xmm5\n"
        "mulss %xmm5, %xmm1\n"
        "pxor %xmm5, %xmm5\n" /* line 406 */
        "ucomiss %xmm1, %xmm5\n"
        "ja .Lf1deae4_001df416\n"
        "minss %xmm1, %xmm3\n" /* line 408 */
        "movaps %xmm3, %xmm1\n"
        ".Lf1deae4_001deff5:\n"
        "subss %xmm4, %xmm2\n" /* line 141 */
        "mulss %xmm1, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        /* } scope */
        ".Lf1deae4_001df001:\n"
        "movss %xmm2, -0x24(%ebp)\n" /* line 575 | dummyX */
        /* { scope 4: dummyX, dummyY, dummyY */
        "movl 0x38(%ebx), %eax\n" /* line 151 | width */
        /* { scope 5 */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1deae4_001df2d2\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001df015:\n"
        "movl 0x4c(%ebx), %ecx\n" /* line 152 */
        "testl %ecx, %ecx\n"
        "jle .Lf1deae4_001df076\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf1deae4_001df076\n"
        "movl 0x44(%ebx), %edx\n" /* line 155 | width */
        /* { scope 5 */
        "testl %edx, %edx\n" /* line 121 */
        "je .Lf1deae4_001df38c\n"
        "cvtsi2ssl %edx, %xmm4\n" /* line 122 */
        /* } scope */
        ".Lf1deae4_001df03f:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 156 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss 0x2ed5d0, %xmm3\n" /* 1.0f */
        "movaps %xmm3, %xmm6\n"
        "divss %xmm0, %xmm6\n"
        "mulss %xmm6, %xmm1\n"
        "ucomiss %xmm1, %xmm5\n" /* line 406 */
        "ja .Lf1deae4_001df40e\n"
        "minss %xmm1, %xmm3\n" /* line 408 */
        "movaps %xmm3, %xmm1\n"
        ".Lf1deae4_001df06a:\n"
        "subss %xmm4, %xmm2\n" /* line 158 */
        "mulss %xmm1, %xmm2\n"
        "addss %xmm4, %xmm2\n"
        /* } scope */
        ".Lf1deae4_001df076:\n"
        "movss %xmm2, -0x28(%ebp)\n" /* line 576 | height */
        "movss -0x488(%ebp), %xmm1\n" /* line 577 */
        "subss %xmm2, %xmm1\n"
        "xorps 0x303990, %xmm1\n"
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        "movl 0x64(%ebx), %edx\n" /* line 285 */
        "testl %edx, %edx\n"
        "jle .Lf1deae4_001df0d0\n"
        "movl 0x195f584, %eax\n" /* line 288 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x60(%ebx), %eax\n"
        "testl %eax, %eax\n" /* line 289 */
        "jle .Lf1deae4_001df2fd\n"
        "cmpl %eax, %edx\n" /* line 291 */
        "jle .Lf1deae4_001df0d0\n"
        "cvtsi2ssl %eax, %xmm3\n" /* line 294 */
        "cvtsi2ssl %edx, %xmm0\n"
        "divss %xmm0, %xmm3\n"
        /* } scope */
        "ucomiss 0x2ed5d0, %xmm3\n" /* line 336 | 1.0f */
        "jne .Lf1deae4_001df300\n"
        "jp .Lf1deae4_001df300\n"
        ".Lf1deae4_001df0d0:\n"
        "movss -0x494(%ebp), %xmm0\n" /* line 337 */
        "movl 0x18(%ebx), %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1deae4_001df399\n"
        "cmpl $2, %eax\n"
        "je .Lf1deae4_001df3bf\n"
        /* } scope */
        ".Lf1deae4_001df0f0:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 579 | alignScreen */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        "movl $0, -0x1c(%ebp)\n" /* line 352 | dummyY */
        "movl $0, -0x20(%ebp)\n" /* line 353 | width */
        "movl %eax, %edx\n" /* line 356 */
        "andl $7, %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "sarl $3, %eax\n"
        "andl $7, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* dummyX */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* width */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* dummyY */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x4b8(%ebp)\n"
        "calll CalcScreenPlacement\n"
        /* } scope */
        /* } scope */
        "movl -0x4a0(%ebp), %eax\n" /* line 580 | faceMaterial */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x270(%ebp), %ebx\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* dummyX */
        "movl %eax, 8(%esp)\n"
        "movss -0x4b8(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl -0x498(%ebp), %eax\n" /* cghe */
        "movl %eax, (%esp)\n"
        "calll CL_DrawStretchPicPhysical\n"
        "movl %edi, 0x18(%esp)\n" /* line 581 | handMaterial */
        "movl %ebx, 0x14(%esp)\n"
        "movss -0x49c(%ebp), %xmm1\n" /* angle */
        "movss %xmm1, 0x10(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* dummyX */
        "movl %eax, 8(%esp)\n"
        "movss -0x4b8(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl -0x498(%ebp), %eax\n" /* cghe */
        "movl %eax, (%esp)\n"
        "calll CG_DrawRotatedPicPhysical\n"
        "jmp .Lf1deae4_001deb9c\n"
        "movl 0x195f584, %eax\n" /* line 54 */
        "movl (%eax), %edx\n"
        "movl 0x68(%ebx), %eax\n"
        "subl 0x25bb0(%edx), %eax\n"
        "leal 0x63(%eax), %edx\n"
        "jmp .Lf1deae4_001def4e\n"
        "movl 0x195f584, %eax\n" /* line 57 */
        "movl (%eax), %eax\n"
        "movl 0x68(%ebx), %edx\n"
        "subl 0x25bb0(%eax), %edx\n"
        "jmp .Lf1deae4_001def4e\n"
        "movl 0x195f584, %eax\n" /* line 62 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %edx\n"
        "subl 0x68(%ebx), %edx\n"
        "jmp .Lf1deae4_001def4e\n"
        ".Lf1deae4_001df21e:\n"
        "pxor %xmm5, %xmm5\n"
        "jmp .Lf1deae4_001deccb\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df227:\n"
        "movss -0x274(%ebp), %xmm2\n" /* line 124 */
        "jmp .Lf1deae4_001dec5e\n"
        /* } scope */
        /* } scope */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df234:\n"
        "movss -0x274(%ebp), %xmm2\n"
        "jmp .Lf1deae4_001decdf\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        ".Lf1deae4_001df241:\n"
        "pxor %xmm1, %xmm1\n" /* line 69 */
        "jmp .Lf1deae4_001def5a\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df24a:\n"
        "movaps %xmm5, %xmm3\n" /* line 253 */
        ".Lf1deae4_001df24d:\n"
        "movss -0x494(%ebp), %xmm0\n" /* line 339 */
        "movl 0x58(%ebx), %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1deae4_001df363\n"
        "cmpl $2, %eax\n"
        "je .Lf1deae4_001df402\n"
        "movaps %xmm0, %xmm2\n"
        /* { scope 5 */
        ".Lf1deae4_001df270:\n"
        "movl 0x18(%ebx), %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1deae4_001df352\n"
        "cmpl $2, %eax\n"
        "je .Lf1deae4_001df41e\n"
        /* } scope */
        ".Lf1deae4_001df288:\n"
        "movaps %xmm2, %xmm1\n" /* line 341 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "jmp .Lf1deae4_001dedba\n"
        ".Lf1deae4_001df29f:\n"
        "pxor %xmm5, %xmm5\n"
        "jmp .Lf1deae4_001df001\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df2a8:\n"
        "movss -0x274(%ebp), %xmm2\n" /* line 124 */
        "jmp .Lf1deae4_001def94\n"
        /* } scope */
        /* } scope */
        ".Lf1deae4_001df2b5:\n"
        "mulss 0x2eda88, %xmm1\n" /* line 573 | 0.006000000052154064f */
        "movss %xmm1, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x49c(%ebp)\n" /* angle */
        "jmp .Lf1deae4_001def85\n"
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df2d2:\n"
        "movss -0x274(%ebp), %xmm2\n" /* line 124 */
        "jmp .Lf1deae4_001df015\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df2df:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 251 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1deae4_001dedba\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df2f0:\n"
        "movss -0x274(%ebp), %xmm4\n" /* line 124 */
        "jmp .Lf1deae4_001defc6\n"
        /* } scope */
        /* } scope */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df2fd:\n"
        "movaps %xmm5, %xmm3\n" /* line 253 */
        ".Lf1deae4_001df300:\n"
        "movss -0x494(%ebp), %xmm0\n" /* line 339 */
        "movl 0x58(%ebx), %eax\n" /* line 246 */
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1deae4_001df3ee\n"
        "cmpl $2, %eax\n"
        "je .Lf1deae4_001df3e2\n"
        "movaps %xmm0, %xmm2\n"
        /* { scope 5 */
        ".Lf1deae4_001df323:\n"
        "movl 0x18(%ebx), %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf1deae4_001df3d1\n"
        "cmpl $2, %eax\n"
        "je .Lf1deae4_001df3c8\n"
        /* } scope */
        ".Lf1deae4_001df33b:\n"
        "movaps %xmm2, %xmm1\n" /* line 341 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "addss %xmm2, %xmm0\n"
        "jmp .Lf1deae4_001df0f0\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df352:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 251 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1deae4_001df288\n"
        /* } scope */
        ".Lf1deae4_001df363:\n"
        "movaps %xmm1, %xmm2\n"
        "mulss 0x2ed63c, %xmm2\n" /* -0.5f */
        "addss %xmm0, %xmm2\n"
        "jmp .Lf1deae4_001df270\n"
        /* } scope */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df377:\n"
        "movaps %xmm5, %xmm1\n" /* line 406 */
        "jmp .Lf1deae4_001ded34\n"
        /* { scope 5 */
        ".Lf1deae4_001df37f:\n"
        "movss -0x274(%ebp), %xmm4\n" /* line 124 */
        "jmp .Lf1deae4_001ded09\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df38c:\n"
        "movss -0x274(%ebp), %xmm4\n"
        "jmp .Lf1deae4_001df03f\n"
        /* } scope */
        /* } scope */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df399:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 251 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1deae4_001df0f0\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df3aa:\n"
        "movaps %xmm5, %xmm1\n" /* line 406 */
        "jmp .Lf1deae4_001decbf\n"
        /* { scope 5 */
        ".Lf1deae4_001df3b2:\n"
        "movss -0x274(%ebp), %xmm4\n" /* line 124 */
        "jmp .Lf1deae4_001dec90\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df3bf:\n"
        "subss %xmm1, %xmm0\n" /* line 253 */
        "jmp .Lf1deae4_001df0f0\n"
        /* { scope 5 */
        ".Lf1deae4_001df3c8:\n"
        "subss %xmm1, %xmm0\n"
        "jmp .Lf1deae4_001df33b\n"
        ".Lf1deae4_001df3d1:\n"
        "mulss 0x2ed63c, %xmm1\n" /* line 251 | -0.5f */
        "addss %xmm1, %xmm0\n"
        "jmp .Lf1deae4_001df33b\n"
        /* } scope */
        ".Lf1deae4_001df3e2:\n"
        "movaps %xmm0, %xmm2\n" /* line 253 */
        "subss %xmm1, %xmm2\n"
        "jmp .Lf1deae4_001df323\n"
        ".Lf1deae4_001df3ee:\n"
        "movaps %xmm1, %xmm2\n" /* line 251 */
        "mulss 0x2ed63c, %xmm2\n" /* -0.5f */
        "addss %xmm0, %xmm2\n"
        "jmp .Lf1deae4_001df323\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df402:\n"
        "movaps %xmm0, %xmm2\n" /* line 253 */
        "subss %xmm1, %xmm2\n"
        "jmp .Lf1deae4_001df270\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df40e:\n"
        "movaps %xmm5, %xmm1\n" /* line 406 */
        "jmp .Lf1deae4_001df06a\n"
        /* } scope */
        /* { scope 4: dummyX, dummyY, dummyY */
        ".Lf1deae4_001df416:\n"
        "movaps %xmm5, %xmm1\n"
        "jmp .Lf1deae4_001deff5\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4: dummyX, dummyY, dummyY */
        /* { scope 5 */
        ".Lf1deae4_001df41e:\n"
        "subss %xmm1, %xmm0\n" /* line 253 */
        "jmp .Lf1deae4_001df288\n"
    );
}

/* line 806 */
__attribute__((naked))
inflate_huft CG_Draw3dHudElems(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 806 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4cc, %esp\n"
        /* { scope 1: cghe, hudElemString */
        "movl 0x195f584, %eax\n" /* line 34 */
        "movl (%eax), %eax\n"
        "movl 0x2bdc8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf1df428_001df6b9\n"
        ".Lf1df428_001df449:\n"
        "movl $1, %eax\n"
        ".Lf1df428_001df44e:\n"
        "testl %eax, %eax\n" /* line 812 */
        "jne .Lf1df428_001df6ae\n"
        /* { scope 2: materialName, pos */
        "movl 0x195f584, %eax\n" /* line 758 */
        "movl (%eax), %eax\n"
        "movl 0x24(%eax), %eax\n"
        "leal 0xc(%eax), %ecx\n"
        "movl %ecx, %edx\n"
        "xorl %esi, %esi\n"
        "addl $0x1734, %eax\n"
        "jmp .Lf1df428_001df483\n"
        ".Lf1df428_001df46e:\n"
        "movl %eax, -0x160(%ebp, %esi, 4)\n" /* line 764 */
        "addl $1, %esi\n" /* line 765 */
        "subl $-0x80, %eax\n"
        "subl $-0x80, %edx\n"
        "cmpl $0x1f, %esi\n" /* line 760 */
        "je .Lf1df428_001df48d\n"
        ".Lf1df428_001df483:\n"
        "movl 0x1728(%edx), %ebx\n" /* line 762 | i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf1df428_001df46e\n"
        ".Lf1df428_001df48d:\n"
        "movl %ecx, %eax\n" /* line 760 */
        "leal (, %esi, 4), %ecx\n"
        "xorl %ebx, %ebx\n" /* i */
        "leal 0x7a8(%eax), %edx\n"
        "jmp .Lf1df428_001df4bb\n"
        ".Lf1df428_001df4a0:\n"
        "movl %edx, -0x160(%ebp, %ecx)\n" /* line 771 */
        "addl $1, %esi\n" /* line 772 */
        "addl $1, %ebx\n" /* line 767 | i */
        "subl $-0x80, %edx\n"
        "subl $-0x80, %eax\n"
        "addl $4, %ecx\n"
        "cmpl $0x1f, %ebx\n" /* i */
        "je .Lf1df428_001df4c5\n"
        ".Lf1df428_001df4bb:\n"
        "movl 0x7a8(%eax), %edi\n" /* line 769 */
        "testl %edi, %edi\n"
        "jne .Lf1df428_001df4a0\n"
        ".Lf1df428_001df4c5:\n"
        "movl $compare_hudelems, 0xc(%esp)\n" /* line 775 */
        "movl $4, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x160(%ebp), %eax\n" /* elems */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        /* } scope */
        "cmpl $0, %esi\n" /* line 816 | elemCount */
        "je .Lf1df428_001df6ae\n"
        "jle .Lf1df428_001df6ae\n" /* line 819 */
        "xorl %edi, %edi\n" /* line 816 | i */
        "jmp .Lf1df428_001df505\n"
        ".Lf1df428_001df4fa:\n"
        "addl $1, %edi\n" /* line 819 | i */
        "cmpl %esi, %edi\n" /* elemCount, i */
        "je .Lf1df428_001df6ae\n"
        ".Lf1df428_001df505:\n"
        "movl -0x160(%ebp, %edi, 4), %ebx\n" /* line 816 | i */
        /* { scope 2: materialName, pos */
        "cmpl $0xd, (%ebx)\n" /* line 715 | elem */
        "jne .Lf1df428_001df4fa\n"
        "leal -0x260(%ebp), %ecx\n" /* line 718 | hudElemString */
        "leal -0x498(%ebp), %edx\n" /* cghe */
        "movl %ebx, %eax\n" /* elem */
        "calll CG_GetHudElemInfo\n"
        "cmpb $0, -0x484(%ebp)\n" /* line 720 */
        "jne .Lf1df428_001df6dd\n"
        ".Lf1df428_001df531:\n"
        "cmpl $0xd, (%ebx)\n" /* line 726 | elem */
        "jne .Lf1df428_001df4fa\n"
        /* { scope 3: material */
        "cmpb $0, 0x23(%ebx)\n" /* line 643 | renderFxFlags */
        "je .Lf1df428_001df4fa\n"
        "movl $0x40, 8(%esp)\n" /* line 645 */
        "leal -0x68(%ebp), %eax\n" /* materialName */
        "movl %eax, 4(%esp)\n"
        "movl 0x3c(%ebx), %eax\n" /* renderFxFlags */
        "movl %eax, (%esp)\n"
        "calll CG_ServerMaterialName\n"
        "testl %eax, %eax\n"
        "je .Lf1df428_001df4fa\n"
        "movl $7, 4(%esp)\n" /* line 648 */
        "leal -0x68(%ebp), %eax\n" /* materialName */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterial\n"
        "movl %eax, -0x49c(%ebp)\n" /* material */
        /* { scope 4: rgbaColor */
        /* { scope 5 */
        "movl 0x38(%ebx), %eax\n" /* line 151 | width */
        /* { scope 6 */
        "testl %eax, %eax\n" /* line 121 */
        "je .Lf1df428_001df716\n"
        "cvtsi2ssl %eax, %xmm2\n" /* line 122 */
        /* } scope */
        ".Lf1df428_001df582:\n"
        "movl 0x4c(%ebx), %ecx\n" /* line 152 */
        "testl %ecx, %ecx\n"
        "jle .Lf1df428_001df70d\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl 0x48(%ebx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jle .Lf1df428_001df70d\n"
        "movl 0x44(%ebx), %edx\n" /* line 155 | width */
        /* { scope 6 */
        "testl %edx, %edx\n" /* line 121 */
        "je .Lf1df428_001df735\n"
        "cvtsi2ssl %edx, %xmm3\n" /* line 122 */
        /* } scope */
        ".Lf1df428_001df5b4:\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 156 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss 0x2ed5d0, %xmm4\n" /* 1.0f */
        "divss %xmm0, %xmm4\n"
        "mulss %xmm4, %xmm1\n"
        "pxor %xmm4, %xmm4\n" /* line 406 */
        "ucomiss %xmm1, %xmm4\n"
        "ja .Lf1df428_001df742\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 408 | 1.0f */
        "minss %xmm1, %xmm0\n"
        "movaps %xmm0, %xmm1\n"
        ".Lf1df428_001df5e8:\n"
        "subss %xmm3, %xmm2\n" /* line 158 */
        "mulss %xmm1, %xmm2\n"
        "addss %xmm3, %xmm2\n"
        /* } scope */
        /* } scope */
        ".Lf1df428_001df5f4:\n"
        "ucomiss %xmm4, %xmm2\n" /* line 650 */
        "jp .Lf1df428_001df5ff\n"
        "je .Lf1df428_001df4fa\n"
        ".Lf1df428_001df5ff:\n"
        "movl 4(%ebx), %eax\n" /* line 653 | elem */
        "movl %eax, -0x28(%ebp)\n" /* pos */
        "movl 8(%ebx), %eax\n" /* line 654 | elem */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 655 | elem */
        "movl %eax, -0x20(%ebp)\n"
        "movzbl 0x23(%ebx), %eax\n" /* line 657 | elem */
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed5d4, %xmm3\n" /* 255.0f */
        "divss %xmm3, %xmm1\n"
        /* { scope 4: rgbaColor */
        /* { scope 5 */
        "movss 0x70(%ebx), %xmm0\n" /* line 618 | renderFxFlags */
        "ucomiss %xmm4, %xmm0\n"
        "ja .Lf1df428_001df723\n"
        "xorl %ebx, %ebx\n" /* renderFxFlags */
        ".Lf1df428_001df635:\n"
        "movb $0xff, -0x1c(%ebp)\n" /* line 664 | rgbaColor */
        "movb $0xff, -0x1b(%ebp)\n" /* line 665 */
        "movb $0xff, -0x1a(%ebp)\n" /* line 666 */
        "movaps %xmm1, %xmm0\n" /* line 428 */
        "mulss %xmm3, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x4b8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x4a0(%ebp)\n"
        "cvttss2si -0x4a0(%ebp), %eax\n"
        "movb %al, -0x19(%ebp)\n"
        "movl %ebx, 0x14(%esp)\n" /* line 631 | renderFxFlags */
        "movl $0, 0x10(%esp)\n"
        "movss -0x4b8(%ebp), %xmm2\n"
        "movss %xmm2, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* pos */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* rgbaColor */
        "movl %eax, 4(%esp)\n"
        "movl -0x49c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll CL_DrawSprite\n"
        "jmp .Lf1df428_001df4fa\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1df428_001df6ae:\n"
        "addl $0x4cc, %esp\n" /* line 821 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: cghe, hudElemString */
        ".Lf1df428_001df6b9:\n"
        "calll CL_GetKeyCatchers\n" /* line 34 */
        "testb $8, %al\n"
        "jne .Lf1df428_001df6c9\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1df428_001df44e\n"
        ".Lf1df428_001df6c9:\n"
        "calll CL_GetDisplayHUDWithKeycatchUI\n"
        "testb %al, %al\n"
        "je .Lf1df428_001df449\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1df428_001df44e\n"
        /* { scope 2: materialName, pos */
        ".Lf1df428_001df6dd:\n"
        "leal -0x498(%ebp), %ecx\n" /* line 722 | cghe */
        "movl %ebx, %edx\n" /* elem */
        "leal -0x484(%ebp), %eax\n"
        "calll CG_DrawHudElemString\n"
        "movss -0x498(%ebp), %xmm0\n" /* line 723 | cghe */
        "addss -0x384(%ebp), %xmm0\n"
        "movss %xmm0, -0x498(%ebp)\n" /* cghe */
        "jmp .Lf1df428_001df531\n"
        ".Lf1df428_001df70d:\n"
        "pxor %xmm4, %xmm4\n"
        "jmp .Lf1df428_001df5f4\n"
        /* { scope 3: material */
        /* { scope 4: rgbaColor */
        /* { scope 5 */
        /* { scope 6 */
        ".Lf1df428_001df716:\n"
        "movss -0x274(%ebp), %xmm2\n" /* line 124 */
        "jmp .Lf1df428_001df582\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: rgbaColor */
        /* { scope 5 */
        ".Lf1df428_001df723:\n"
        "mulss 0x2eda8c, %xmm2\n" /* line 621 | 0.00430000014603138f */
        "movl $0x3000, %ebx\n" /* renderFxFlags */
        "jmp .Lf1df428_001df635\n"
        /* } scope */
        /* } scope */
        /* { scope 4: rgbaColor */
        /* { scope 5 */
        /* { scope 6 */
        ".Lf1df428_001df735:\n"
        "movss -0x274(%ebp), %xmm3\n" /* line 124 */
        "jmp .Lf1df428_001df5b4\n"
        /* } scope */
        ".Lf1df428_001df742:\n"
        "movaps %xmm4, %xmm1\n" /* line 406 */
        "jmp .Lf1df428_001df5e8\n"
    );
}

