/* ASM dump from: r_surfbounds.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_surfbounds.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_surface.h"
 */

extern const vec_t * (*R_BoundsForDrawSurfTable[8])(); /* 0x0 */
static int surfBoundsGlob; /* 0xce7000 */

const vec_t * R_BoundsForSurf_Triangles(const GfxDrawSurf *drawSurf, int entIndex);
const vec_t * R_BoundsForSurf_ModelInst(const GfxDrawSurf *drawSurf, int entIndex);
const vec_t * R_BoundsForSurf_StaticModelCached(const GfxDrawSurf *drawSurf, int entIndex);
const vec_t * R_BoundsForDrawSurf(const GfxDrawSurf *surf);

/* line 14 */
__attribute__((naked))
const vec_t * R_BoundsForSurf_Triangles(const GfxDrawSurf *drawSurf, int entIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 14 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* entIndex */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 22 | drawSurf */
        "movl 4(%eax), %ecx\n"
        "addl $4, %ecx\n"
        "cmpl $0x7fd, %edx\n" /* line 25 */
        "jle .Lffbf88_000fbfa6\n"
        "movl %ecx, %eax\n" /* line 26 */
        /* } scope */
        "leave\n" /* line 42 */
        "retl\n"
        /* { scope 1 */
        ".Lffbf88_000fbfa6:\n"
        "leal (, %edx, 8), %eax\n" /* line 34 */
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x195f0f4, %edx\n"
        "movl 0x10(%edx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl $surfBoundsGlob, 0xc(%esp)\n" /* line 37 */
        "leal 0x14(%eax), %edx\n"
        "movl %edx, 8(%esp)\n"
        "addl $0x3c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll GetRotatedBounds\n"
        "movl $surfBoundsGlob, %eax\n"
        /* } scope */
        "leave\n" /* line 42 */
        "retl\n"
    );
}

/* line 45 */
__attribute__((naked))
const vec_t * R_BoundsForSurf_ModelInst(const GfxDrawSurf *drawSurf, int entIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 45 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* entIndex */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x195f0f4, %edx\n" /* entIndex */
        "leal 0x5d8(%edx, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 59 */
        "retl\n"
    );
}

/* line 64 */
__attribute__((naked))
const vec_t * R_BoundsForSurf_StaticModelCached(const GfxDrawSurf *drawSurf, int entIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 64 */
        "movl %esp, %ebp\n"
        "movl 0x195eebc, %eax\n" /* drawSurf */
        "movl 0x109c(%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* drawSurf */
        "movl 4(%eax), %eax\n" /* drawSurf */
        "movl 8(%eax), %eax\n" /* drawSurf */
        "movl 4(%eax), %eax\n" /* drawSurf */
        "leal (%eax, %eax, 2), %eax\n" /* drawSurf */
        "shll $5, %eax\n" /* drawSurf */
        "addl 0xf8(%edx), %eax\n" /* drawSurf */
        "addl $0x14, %eax\n" /* drawSurf */
        "popl %ebp\n" /* line 90 */
        "retl\n"
    );
}

/* line 113 */
__attribute__((naked))
const vec_t * R_BoundsForDrawSurf(const GfxDrawSurf *surf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 113 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ecx\n" /* surf */
        /* { scope 1 */
        "movl 4(%ecx), %eax\n" /* line 122 */
        "movl (%eax), %eax\n"
        "movl R_BoundsForDrawSurfTable(, %eax, 4), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lffc02c_000fc081\n"
        "movl (%ecx), %eax\n" /* line 125 | sortValue */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 79 */
        "js .Lffc02c_000fc074\n"
        "movl %eax, %edx\n" /* line 82 */
        "shrl $4, %edx\n"
        "andl $0xfff, %edx\n"
        ".Lffc02c_000fc057:\n"
        "cmpl $0x800, %edx\n" /* line 84 */
        "movl $0x7fe, %eax\n"
        "cmovgel %eax, %edx\n"
        /* } scope */
        "movl %edx, 4(%esp)\n" /* line 126 */
        "movl %ecx, (%esp)\n"
        "calll *%ebx\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 130 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lffc02c_000fc074:\n"
        "movl %eax, %edx\n" /* line 80 */
        "shrl $0x13, %edx\n"
        "andl $0xfff, %edx\n"
        "jmp .Lffc02c_000fc057\n"
        /* } scope */
        ".Lffc02c_000fc081:\n"
        "xorl %eax, %eax\n" /* line 122 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 130 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

