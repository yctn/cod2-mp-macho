/* ASM dump from: rb_shade.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_shade.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/gfx_d3d/rb_state.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_shade.h"
 */

extern const float lightGridLookupMatrix[4][4]; /* rodata.c */
extern const vec4_t debugShaderConsts[]; /* rodata.c */
extern const GfxStateOverride overrideEnableRenormalize; /* rodata.c */
extern const DWORD s_fvfForVertDeclType[]; /* rodata.c */

static inline char *RB_TessBase(void)
{
    return (char *)imp_tess;
}

void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex);
int RB_SetIndexData(const r_index_t *indices, int indexCount);
static void RB_GetTextureFromCode(void);
static void RB_SetEntityHwLightsDx7(void);
void RB_CreateDynamicBuffers(void);
static void RB_SetupLighting(void);
void RB_SetVertexData(unsigned int streamIndex, const void *data, int vertexCount, int stride);
static const float * RB_GetCodeMatrix(int source, int firstRow);
static void RB_DrawSingleTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args, const GfxStateOverride *stateOverride);
void RB_DrawTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args);
void RB_EndSurface(void);

/* line 1587 */
void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex)
{
    char *tess = RB_TessBase();
    *(int *)(tess + 0x5a7cc) = 0;
    *(int *)(tess + 0x5a7b8) = 0;
    *(int *)(tess + 0x5a7d0) = 0;
    *(int *)(tess + 0x5a7d4) = 0;
    *(int *)(tess + 0x5a7d8) = 0;
    *(int *)(tess + 0x5a7dc) = 0;
    *(const Material **)(tess + 0x5a7bc) = material;
    *(MaterialTechniqueType *)(tess + 0x5a7c0) = techType;
    *(int *)(tess + 0x5a7c4) = lmapIndex;
}

/* line 132 */
__attribute__((naked))
int RB_SetIndexData(const r_index_t *indices, int indexCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 132 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %edi\n" /* line 146 | indexCount, indexDataSize */
        "addl %edi, %edi\n" /* indexDataSize */
        "movl imp_dx, %esi\n" /* line 149 | lockFlags */
        "movl 0x2d8c(%esi), %edx\n" /* lockFlags */
        "movl %edi, %eax\n" /* indexDataSize */
        "addl (%edx), %eax\n"
        "cmpl 4(%edx), %eax\n"
        "setg %al\n"
        "testb %al, %al\n" /* line 150 */
        "je .Lff6e6a_000f6e9e\n"
        "movl $0, (%edx)\n" /* line 151 */
        "movl 0x2d8c(%esi), %edx\n" /* lockFlags */
        ".Lff6e6a_000f6e9e:\n"
        "movl (%edx), %ecx\n" /* line 153 */
        "testl %ecx, %ecx\n"
        "jne .Lff6e6a_000f6eb0\n"
        "leal 0x2d80(%esi), %edx\n" /* line 155 | lockFlags */
        "movl %edx, 0x2d8c(%esi)\n" /* lockFlags */
        ".Lff6e6a_000f6eb0:\n"
        "movl (%edx), %ecx\n" /* line 164 */
        "movl %ecx, %ebx\n" /* dxIb */
        "shrl $1, %ebx\n" /* dxIb */
        "movl %ebx, -0x2c(%ebp)\n" /* dxIb, baseIndex */
        "movl 8(%edx), %ebx\n" /* line 1011 | dxIb */
        "testb %al, %al\n" /* line 170 */
        "jne .Lff6e6a_000f6efc\n"
        "movl 0x2c20(%esi), %edx\n" /* lockFlags */
        "testl %edx, %edx\n"
        "je .Lff6e6a_000f6ef8\n"
        ".Lff6e6a_000f6eca:\n"
        "movl $__mh_execute_header, %esi\n" /* lockFlags */
        "leal -0x1c(%ebp), %eax\n" /* line 180 | bufferData */
        "movl (%ebx), %edx\n" /* dxIb */
        "movl %esi, 0x10(%esp)\n" /* lockFlags */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* indexDataSize */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dxIb */
        "calll *0x2c(%edx)\n"
        "testl %eax, %eax\n" /* line 182 */
        "jns .Lff6e6a_000f6f20\n"
        ".Lff6e6a_000f6eee:\n"
        "movl %eax, (%esp)\n" /* line 183 */
        "calll R_FatalLockError\n"
        "jmp .Lff6e6a_000f6f20\n"
        ".Lff6e6a_000f6ef8:\n"
        "testl %ecx, %ecx\n" /* line 170 */
        "jne .Lff6e6a_000f6eca\n"
        ".Lff6e6a_000f6efc:\n"
        "movl $0x2000, %esi\n" /* lockFlags */
        "leal -0x1c(%ebp), %eax\n" /* line 180 | bufferData */
        "movl (%ebx), %edx\n" /* dxIb */
        "movl %esi, 0x10(%esp)\n" /* lockFlags */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* indexDataSize */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dxIb */
        "calll *0x2c(%edx)\n"
        "testl %eax, %eax\n" /* line 182 */
        "js .Lff6e6a_000f6eee\n"
        ".Lff6e6a_000f6f20:\n"
        "movl %edi, 8(%esp)\n" /* line 192 | indexDataSize */
        "movl 8(%ebp), %eax\n" /* indices */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl imp_alwaysfails, %esi\n" /* lockFlags */
        ".Lff6e6a_000f6f3c:\n"
        "movl (%ebx), %eax\n" /* line 197 | dxIb */
        "movl %ebx, (%esp)\n" /* dxIb */
        "calll *0x30(%eax)\n"
        "movl (%esi), %eax\n" /* lockFlags */
        "testl %eax, %eax\n"
        "jne .Lff6e6a_000f6f3c\n"
        "movl imp_dxState, %eax\n" /* line 212 */
        "cmpl 0x20cc(%eax), %ebx\n" /* dxIb */
        "je .Lff6e6a_000f6f5f\n"
        "movl %ebx, (%esp)\n" /* line 213 | dxIb */
        "calll RB_ChangeIndices\n"
        ".Lff6e6a_000f6f5f:\n"
        "movl imp_dx, %eax\n" /* line 201 */
        "movl 0x2d8c(%eax), %eax\n"
        "addl %edi, (%eax)\n" /* indexDataSize */
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 206 | baseIndex */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 522 */
static __attribute__((naked))
void RB_GetTextureFromCode(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl %eax, %ebx\n" /* codeTexture */
        "movl %edx, %esi\n" /* image */
        "movl %ecx, %edi\n" /* samplerState */
        "cmpl $0x17, %eax\n" /* line 527 */
        "ja .Lff6f78_000f6f93\n"
        "jmpl *.Ljt_f6f78_0(, %eax, 4)\n"
        ".Lff6f78_000f6f93:\n"
        "movb $0, (%ecx)\n" /* line 659 */
        "movl $0, (%edx)\n" /* line 660 */
        ".Lff6f78_000f6f9c:\n"
        "addl $0x1c, %esp\n" /* line 663 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff6f78_000f6fa4:\n"
        "movl imp_rgp, %eax\n" /* line 530 */
        "movl 0x100c(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $1, (%ecx)\n" /* line 531 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f6fb6:\n"
        "movl imp_rgp, %eax\n" /* line 535 */
        "movl 0x1008(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $1, (%ecx)\n" /* line 536 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f6fc8:\n"
        "movl imp_rgp, %eax\n" /* line 540 */
        "movl 0x1010(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $1, (%ecx)\n" /* line 541 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f6fda:\n"
        "movl imp_rgp, %eax\n" /* line 545 */
        "movl 0x1014(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%ecx)\n" /* line 546 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f6fec:\n"
        "movl imp_rgp, %ebx\n" /* line 550 | codeTexture */
        "movl 0x109c(%ebx), %eax\n" /* codeTexture */
        "testl %eax, %eax\n"
        "je .Lff6f78_000f725b\n"
        "movl 0x10c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff6f78_000f725b\n"
        ".Lff6f78_000f700e:\n"
        "movl 0x109c(%ebx), %eax\n" /* line 552 | codeTexture */
        "movl 0x10c(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movb $0x72, (%edi)\n" /* line 553 | samplerState */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f7024:\n"
        "movl imp_rgp, %eax\n" /* line 558 */
        "movl 0x1008(%eax, %ebx, 4), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%ecx)\n" /* line 559 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f703a:\n"
        "movl imp_rgp, %eax\n" /* line 563 */
        "movl 0x1018(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%ecx)\n" /* line 564 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f704f:\n"
        "movl imp_tess, %eax\n" /* line 572 */
        "cmpl $0x1f, 0x5a7c4(%eax)\n"
        "je .Lff6f78_000f729d\n"
        "movl %eax, %edx\n"
        ".Lff6f78_000f7063:\n"
        "movl imp_rgp, %ecx\n" /* line 582 */
        "movl 0x5a7c4(%edx), %eax\n"
        "shll $4, %eax\n"
        "leal (%eax, %ebx, 4), %eax\n"
        "movl 0x109c(%ecx), %edx\n"
        "addl 0x108(%edx), %eax\n"
        "movl -0x20(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movb $0x32, (%edi)\n" /* line 583 | samplerState */
        "movl imp_r_lightMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff6f78_000f6f9c\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff6f78_000f728d\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff6f78_000f6f9c\n"
        "movl 0x100c(%ecx), %eax\n" /* line 464 */
        "movl %eax, (%esi)\n"
        "movb $1, (%edi)\n" /* line 465 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f70bd:\n"
        "movl imp_dx, %eax\n" /* line 595 */
        "movl 0x2c80(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%ecx)\n" /* line 596 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f70d2:\n"
        "movl imp_backEnd, %eax\n" /* line 609 */
        "movl 0x2e8c(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%ecx)\n" /* line 610 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f70e7:\n"
        "movl imp_backEnd, %eax\n" /* line 614 */
        "movl 0x2e84(%eax), %eax\n"
        ".Lff6f78_000f70f2:\n"
        "leal (%eax, %eax, 4), %eax\n" /* line 619 */
        "shll $2, %eax\n"
        "addl imp_dx, %eax\n"
        "movl 0x2c30(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movb $0x32, (%edi)\n" /* line 648 | samplerState */
        ".Lff6f78_000f7109:\n"
        "addl $0x1c, %esp\n" /* line 663 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff6f78_000f7111:\n"
        "movl imp_backEnd, %eax\n" /* line 619 */
        "movl 0x2e88(%eax), %eax\n"
        "jmp .Lff6f78_000f70f2\n"
        ".Lff6f78_000f711e:\n"
        "movl imp_rgp, %ebx\n" /* line 624 | codeTexture */
        "movl 0x109c(%ebx), %eax\n" /* codeTexture */
        "testl %eax, %eax\n"
        "je .Lff6f78_000f7242\n"
        "movl 0x20(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff6f78_000f7242\n"
        ".Lff6f78_000f713d:\n"
        "movl 0x109c(%ebx), %eax\n" /* line 626 | codeTexture */
        "movl 0x20(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movl 0x109c(%ebx), %eax\n" /* line 627 | codeTexture */
        "movzbl 0x24(%eax), %eax\n"
        "movb %al, (%edi)\n" /* samplerState */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f7159:\n"
        "shll $6, %eax\n" /* line 634 */
        "leal -0x484(%eax, %ebx, 4), %eax\n"
        "addl imp_backEnd, %eax\n"
        "movl 0x2ed0(%eax), %edx\n"
        "movl 0xc(%edx), %edx\n"
        "movl %edx, (%esi)\n" /* image */
        "movl 0x2ed0(%eax), %eax\n" /* line 635 */
        "movzbl 0x10(%eax), %eax\n"
        "movb %al, (%ecx)\n"
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f7185:\n"
        "movl imp_rgp, %ebx\n" /* line 588 | codeTexture */
        "movl 0x109c(%ebx), %eax\n" /* codeTexture */
        "testl %eax, %eax\n"
        "je .Lff6f78_000f7274\n"
        "movl 0x200(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff6f78_000f7274\n"
        ".Lff6f78_000f71a7:\n"
        "movl 0x109c(%ebx), %eax\n" /* line 590 | codeTexture */
        "movl 0x200(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movb $0x32, (%edi)\n" /* line 591 | samplerState */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f71bd:\n"
        "movl $0, (%edx)\n" /* line 640 */
        "movb $0x31, (%ecx)\n" /* line 641 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f71cb:\n"
        "movl imp_sc_enable, %eax\n" /* line 600 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lff6f78_000f722d\n"
        "movl imp_backEnd, %eax\n"
        "movl 0x440(%eax), %eax\n"
        "cmpl $2, (%eax)\n"
        "jg .Lff6f78_000f71ee\n"
        "testb $1, 5(%eax)\n"
        "je .Lff6f78_000f722d\n"
        ".Lff6f78_000f71ee:\n"
        "movl imp_dx, %eax\n" /* line 602 */
        "movl 0x2c6c(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movb $0x32, (%edi)\n" /* line 648 | samplerState */
        "jmp .Lff6f78_000f7109\n"
        ".Lff6f78_000f7203:\n"
        "movl imp_rgp, %eax\n" /* line 652 */
        "movl 0x10a0(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%edi)\n" /* line 648 | samplerState */
        "jmp .Lff6f78_000f7109\n"
        ".Lff6f78_000f7218:\n"
        "movl imp_rgp, %eax\n" /* line 647 */
        "movl 0x10a4(%eax), %eax\n"
        "movl %eax, (%edx)\n"
        "movb $0x32, (%edi)\n" /* line 648 | samplerState */
        "jmp .Lff6f78_000f7109\n"
        ".Lff6f78_000f722d:\n"
        "movl imp_rgp, %eax\n" /* line 604 */
        "movl 0x1008(%eax), %eax\n"
        "movl %eax, (%esi)\n" /* image */
        "movb $0x32, (%edi)\n" /* line 648 | samplerState */
        "jmp .Lff6f78_000f7109\n"
        ".Lff6f78_000f7242:\n"
        "movl $str_00226828, 4(%esp)\n" /* line 625 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lff6f78_000f713d\n"
        ".Lff6f78_000f725b:\n"
        "movl $str_002266cc, 4(%esp)\n" /* line 551 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lff6f78_000f700e\n"
        ".Lff6f78_000f7274:\n"
        "movl $str_002267f4, 4(%esp)\n" /* line 589 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lff6f78_000f71a7\n"
        ".Lff6f78_000f728d:\n"
        "movl 0x1008(%ecx), %eax\n" /* line 457 */
        "movl %eax, (%esi)\n"
        "movb $1, (%edi)\n" /* line 458 */
        "jmp .Lff6f78_000f6f9c\n"
        ".Lff6f78_000f729d:\n"
        "movl 0x5a7bc(%eax), %eax\n" /* line 580 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00226700, 4(%esp)\n" /* "Material '%s' tried to use a lightmap but doesn't have one s" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "movl imp_tess, %edx\n"
        "jmp .Lff6f78_000f7063\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f6f78_0:\n"
        ".long .Lff6f78_000f6fa4\n"
        ".long .Lff6f78_000f6fb6\n"
        ".long .Lff6f78_000f6fc8\n"
        ".long .Lff6f78_000f6fda\n"
        ".long .Lff6f78_000f6fec\n"
        ".long .Lff6f78_000f7024\n"
        ".long .Lff6f78_000f7024\n"
        ".long .Lff6f78_000f703a\n"
        ".long .Lff6f78_000f704f\n"
        ".long .Lff6f78_000f704f\n"
        ".long .Lff6f78_000f704f\n"
        ".long .Lff6f78_000f704f\n"
        ".long .Lff6f78_000f70bd\n"
        ".long .Lff6f78_000f70d2\n"
        ".long .Lff6f78_000f70e7\n"
        ".long .Lff6f78_000f7111\n"
        ".long .Lff6f78_000f711e\n"
        ".long .Lff6f78_000f7159\n"
        ".long .Lff6f78_000f7159\n"
        ".long .Lff6f78_000f71cb\n"
        ".long .Lff6f78_000f7185\n"
        ".long .Lff6f78_000f71bd\n"
        ".long .Lff6f78_000f7203\n"
        ".long .Lff6f78_000f7218\n"
        ".text\n"
    );
}

/* line 1481 */
static __attribute__((naked))
void RB_SetEntityHwLightsDx7(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1481 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x37c, %esp\n"
        /* { scope 1 */
        "movl $8, 0x10(%esp)\n" /* line 1487 */
        "leal -0x358(%ebp), %esi\n" /* lights */
        "movl %esi, 0xc(%esp)\n"
        "movl imp_tess, %edx\n"
        "movl 0x5a7bc(%edx), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n" /* sunVisibility */
        "movl %eax, (%esp)\n" /* colorForDir */
        "calll RB_DeriveEntityLights\n"
        "movl %eax, -0x360(%ebp)\n" /* colorForDir, lightCount */
        "testl %eax, %eax\n" /* line 1489 | colorForDir */
        "jg .Lff72c8_000f7363\n"
        "movl $0, -0x35c(%ebp)\n" /* lightIndex */
        "xorl %ebx, %ebx\n"
        ".Lff72c8_000f731a:\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff72c8_000f7326:\n"
        "movl 8(%edi), %eax\n" /* line 1495 | colorForDir */
        "movl (%eax), %edx\n" /* colorForDir */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* colorForDir */
        "calll *0xd4(%edx)\n"
        "movl (%esi), %eax\n" /* colorForDir */
        "testl %eax, %eax\n" /* colorForDir */
        "jne .Lff72c8_000f7326\n"
        "addl $1, -0x35c(%ebp)\n" /* line 1494 | lightIndex */
        "movl -0x35c(%ebp), %ebx\n" /* lightIndex */
        "cmpl $7, %ebx\n"
        "jbe .Lff72c8_000f7326\n"
        /* } scope */
        "addl $0x37c, %esp\n" /* line 1496 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff72c8_000f7363:\n"
        "xorl %ebx, %ebx\n" /* line 1489 */
        "movl imp_dx, %edi\n"
        "movl %edi, %edx\n"
        "jmp .Lff72c8_000f7375\n"
        ".Lff72c8_000f736f:\n"
        "movl imp_dx, %edx\n"
        ".Lff72c8_000f7375:\n"
        "movl 8(%edx), %eax\n" /* line 1491 | colorForDir */
        "movl (%eax), %edx\n" /* colorForDir */
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* colorForDir */
        "calll *0xd4(%edx)\n"
        "movl imp_alwaysfails, %eax\n" /* colorForDir */
        "movl (%eax), %eax\n" /* colorForDir */
        "testl %eax, %eax\n" /* colorForDir */
        "jne .Lff72c8_000f736f\n"
        ".Lff72c8_000f739a:\n"
        "movl 8(%edi), %eax\n" /* line 1492 | colorForDir */
        "movl (%eax), %edx\n" /* colorForDir */
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n" /* colorForDir */
        "calll *0xcc(%edx)\n"
        "movl imp_alwaysfails, %edx\n"
        "movl (%edx), %eax\n" /* colorForDir */
        "testl %eax, %eax\n" /* colorForDir */
        "jne .Lff72c8_000f739a\n"
        "addl $1, %ebx\n" /* line 1489 */
        "addl $0x68, %esi\n"
        "cmpl %ebx, -0x360(%ebp)\n" /* lightCount */
        "jne .Lff72c8_000f736f\n"
        "movl -0x360(%ebp), %eax\n" /* lightCount, colorForDir */
        "movl %eax, -0x35c(%ebp)\n" /* colorForDir, lightIndex */
        "movl %eax, %ebx\n" /* colorForDir */
        "cmpl $7, %eax\n" /* line 1494 | colorForDir */
        "jbe .Lff72c8_000f731a\n"
        /* } scope */
        "addl $0x37c, %esp\n" /* line 1496 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1785 */
__attribute__((naked))
void RB_CreateDynamicBuffers(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1785 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl imp_ri, %esi\n" /* line 1799 */
        "movl $0x200000, (%esp)\n"
        "calll *0xc(%esi)\n"
        "movl imp_tess, %ebx\n"
        "movl %eax, 0x5a7b0(%ebx)\n"
        "movl $0x200000, (%esp)\n" /* line 1800 */
        "calll *0xc(%esi)\n"
        "movl %eax, 0x5a7b4(%ebx)\n"
        "addl $0x10, %esp\n" /* line 1802 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1500 */
static __attribute__((naked))
void RB_SetupLighting(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1500 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1503 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff7428_000f75ab\n"
        "movl imp_backEnd, %esi\n" /* line 1525 */
        "movl 0x444(%esi), %edx\n"
        "testl %edx, %edx\n"
        "je .Lff7428_000f7607\n"
        "movl (%edx), %eax\n" /* line 1527 */
        "cmpl 0x3b4(%esi), %eax\n"
        "je .Lff7428_000f7477\n"
        "movl %edx, 4(%esp)\n" /* line 1529 */
        "movl 0x440(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetupEntityLighting\n"
        "movl 0x444(%esi), %edx\n"
        ".Lff7428_000f7477:\n"
        "movl 4(%edx), %eax\n" /* line 1533 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2eb8(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2eb4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x2eb0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x85, (%esp)\n"
        "calll RB_SetCodeConstant\n"
        "movl 0x444(%esi), %eax\n"
        "leal 8(%eax), %edx\n"
        "leal 0x120(%esi), %ecx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 8(%eax), %eax\n" /* line 456 */
        "movl %eax, 0x120(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x444(%esi), %eax\n"
        "leal 0x18(%eax), %edx\n"
        /* } scope */
        "leal 0x130(%esi), %ecx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 0x18(%eax), %eax\n" /* line 456 */
        "movl %eax, 0x130(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x444(%esi), %eax\n"
        "leal 0x28(%eax), %edx\n"
        /* } scope */
        "leal 0x140(%esi), %ecx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 0x28(%eax), %eax\n" /* line 456 */
        "movl %eax, 0x140(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x444(%esi), %eax\n"
        "leal 0x38(%eax), %edx\n"
        /* } scope */
        "leal 0x150(%esi), %ecx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 0x38(%eax), %eax\n" /* line 456 */
        "movl %eax, 0x150(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x444(%esi), %eax\n"
        "leal 0x48(%eax), %edx\n"
        /* } scope */
        "leal 0x160(%esi), %ecx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 0x48(%eax), %eax\n" /* line 456 */
        "movl %eax, 0x160(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x444(%esi), %eax\n"
        "leal 0x58(%eax), %edx\n"
        /* } scope */
        "leal 0x170(%esi), %ecx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 0x58(%eax), %eax\n" /* line 456 */
        "movl %eax, 0x170(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        ".Lff7428_000f75a4:\n"
        "addl $0x20, %esp\n" /* line 1553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff7428_000f75ab:\n"
        "movl imp_tess, %eax\n" /* line 1505 */
        "movl 0x5a7c0(%eax), %eax\n"
        "subl $0xf, %eax\n"
        "cmpl $2, %eax\n"
        "jbe .Lff7428_000f75a4\n"
        "movl imp_backEnd, %ebx\n" /* line 1508 */
        "movl 0x444(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lff7428_000f76a3\n"
        "movl (%edx), %eax\n" /* line 1510 */
        "cmpl 0x3b4(%ebx), %eax\n"
        "je .Lff7428_000f75f4\n"
        "movl %edx, 4(%esp)\n" /* line 1512 */
        "movl 0x440(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetupEntityLighting\n"
        "movl 0x444(%ebx), %edx\n"
        ".Lff7428_000f75f4:\n"
        "leal 8(%edx), %eax\n" /* line 1515 */
        "movss 4(%edx), %xmm0\n"
        ".Lff7428_000f75fc:\n"
        "addl $0x20, %esp\n" /* line 1553 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp RB_SetEntityHwLightsDx7\n" /* line 1519 */
        ".Lff7428_000f7607:\n"
        "leal 0x50(%esi), %edx\n" /* line 275 | to */
        /* { scope 1 */
        "movl 0x2eb0(%esi), %eax\n" /* line 456 */
        "movl %eax, 0x50(%esi)\n"
        "movl 0x2eb4(%esi), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 0x2eb8(%esi), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0x2ebc(%esi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movl 0x440(%esi), %eax\n" /* line 1547 */
        "cmpl $2, (%eax)\n"
        "jne .Lff7428_000f75a4\n"
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "leal 0x110(%eax), %edx\n"
        "leal 0x190(%esi), %ecx\n" /* line 284 | to */
        /* { scope 1 */
        "movl 0x110(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x190(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "xorl %ebx, %ebx\n" /* line 285 */
        "movl %ebx, 0x19c(%esi)\n"
        "movl 0x440(%esi), %eax\n"
        "leal 8(%eax), %edx\n"
        "leal 0x180(%esi), %ecx\n" /* line 284 | to */
        /* { scope 1 */
        "movl 8(%eax), %eax\n" /* line 199 */
        "movl %eax, 0x180(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl %ebx, 0x18c(%esi)\n" /* line 285 */
        "jmp .Lff7428_000f75a4\n"
        ".Lff7428_000f76a3:\n"
        "movl 0x440(%ebx), %edx\n" /* line 1517 */
        "cmpl $2, (%edx)\n"
        "jne .Lff7428_000f75a4\n"
        "movl 8(%edx), %eax\n" /* line 1519 */
        "movss 0xc(%edx), %xmm0\n"
        "jmp .Lff7428_000f75fc\n"
    );
}

/* line 210 */
__attribute__((naked))
void RB_SetVertexData(unsigned int streamIndex, const void *data, int vertexCount, int stride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        /* { scope 1: i, i, i, i, ... */
        "movl 0x14(%ebp), %eax\n" /* line 224 | stride */
        "imull 0x10(%ebp), %eax\n" /* vertexCount */
        "movl %eax, -0xd8(%ebp)\n" /* totalSize */
        "movl imp_dx, %eax\n" /* line 245 | vb */
        "movl 0x2db4(%eax), %eax\n" /* vb */
        /* { scope 2: y, color, tx, ty, ... */
        "movl 8(%eax), %edx\n" /* line 1005 */
        "movl %edx, -0xdc(%ebp)\n" /* dxVb */
        /* } scope */
        "movl (%eax), %edx\n" /* line 253 */
        "cmpl $1, %edx\n"
        "sbbl %eax, %eax\n"
        "andl $__mh_execute_header, %eax\n"
        "addl $__mh_execute_header, %eax\n"
        "movl -0xdc(%ebp), %ebx\n" /* line 255 | dxVb */
        "movl (%ebx), %ecx\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd8(%ebp), %esi\n" /* totalSize */
        "movl %esi, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 257 */
        "js .Lff76c0_000f7da3\n"
        ".Lff76c0_000f772d:\n"
        "movl -0xd8(%ebp), %eax\n" /* line 265 | totalSize */
        "cltd\n"
        "idivl 0x14(%ebp)\n" /* stride */
        "movl %eax, -0xe0(%ebp)\n"
        "movl 0x14(%ebp), %ebx\n" /* line 266 | stride, strideInDWords */
        "shrl $2, %ebx\n" /* strideInDWords */
        "movl 0xc(%ebp), %edx\n" /* line 267 | data */
        "movl %edx, -0xd4(%ebp)\n" /* pSrc */
        "movl -0x1c(%ebp), %esi\n" /* line 268 | bufferData */
        "movl %esi, -0xd0(%ebp)\n" /* pDst */
        "movl $0, (%esp)\n" /* line 270 */
        "calll CColorConverter_GetColorConverter\n"
        "movl %eax, -0xcc(%ebp)\n" /* c */
        "movl 0x14(%ebp), %eax\n" /* line 271 | stride */
        "subl $0x14, %eax\n"
        "cmpl $0x30, %eax\n"
        "ja .Lff76c0_000f7795\n"
        "jmpl *.Ljt_f76c0_0(, %eax, 4)\n"
        ".Lff76c0_000f7779:\n"
        "movl -0xd8(%ebp), %edx\n" /* line 324 | totalSize */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* data, x */
        "movl %ebx, 4(%esp)\n" /* x */
        "movl -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        ".Lff76c0_000f7795:\n"
        "movl -0xdc(%ebp), %edx\n" /* line 439 | dxVb */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%eax)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff76c0_000f7795\n"
        "movl imp_dx, %ebx\n" /* line 442 | nx */
        "movl 0x2db4(%ebx), %eax\n" /* nx */
        "movl (%eax), %ecx\n" /* vertexOffset */
        /* { scope 2: y, color, tx, ty, ... */
        "movl 8(%ebp), %esi\n" /* line 220 | streamIndex */
        "leal (%esi, %esi, 2), %eax\n"
        "shll $2, %eax\n"
        "addl imp_dxState, %eax\n"
        "leal 0x20d0(%eax), %edx\n"
        "movl -0xdc(%ebp), %esi\n" /* dxVb */
        "cmpl 0x20d0(%eax), %esi\n"
        "je .Lff76c0_000f781a\n"
        "movl 0x14(%ebp), %edx\n" /* stride */
        "movl %esi, %ebx\n"
        ".Lff76c0_000f77e4:\n"
        "movl %edx, 0xc(%esp)\n" /* line 221 */
        "movl %ecx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* streamIndex */
        "movl %esi, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        "movl imp_dx, %ebx\n"
        /* } scope */
        ".Lff76c0_000f7801:\n"
        "movl 0x2db4(%ebx), %eax\n" /* line 443 | nx */
        "movl -0xd8(%ebp), %edx\n" /* totalSize */
        "addl %edx, (%eax)\n"
        /* } scope */
        "addl $0x11c, %esp\n" /* line 446 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, i, i, i, ... */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f781a:\n"
        "cmpl 4(%edx), %ecx\n" /* line 220 */
        "je .Lff76c0_000f7db0\n"
        "movl 0x14(%ebp), %edx\n" /* stride */
        "movl -0xdc(%ebp), %ebx\n" /* dxVb */
        "jmp .Lff76c0_000f77e4\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f782e:\n"
        "movl -0xe0(%ebp), %eax\n" /* line 388 */
        "testl %eax, %eax\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* w */
        "movl %ebx, -0x2c(%ebp)\n" /* w */
        "movl $0, -0x68(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7849:\n"
        "movl -0xd4(%ebp), %ebx\n" /* line 391 | pSrc, w */
        "movl 4(%ebx), %ebx\n" /* w */
        "movl %ebx, -0xfc(%ebp)\n" /* w, y */
        "movl -0xd4(%ebp), %esi\n" /* line 392 | pSrc, nx */
        "movl 8(%esi), %ecx\n" /* nx, z */
        "movl 0xc(%esi), %ebx\n" /* line 393 | nx */
        "movl %esi, %eax\n" /* line 394 | ny */
        "movl 0x10(%esi), %esi\n" /* ny */
        "movl 0x14(%eax), %edi\n" /* line 395 | nz */
        "movl 0x1c(%eax), %edx\n" /* line 397 */
        "movl %edx, -0x64(%ebp)\n" /* tx */
        "movl 0x20(%eax), %eax\n" /* line 398 */
        "movl %eax, -0x60(%ebp)\n" /* ty */
        "movl -0xd4(%ebp), %edx\n" /* line 399 | pSrc */
        "movl 0x24(%edx), %edx\n"
        "movl %edx, -0x5c(%ebp)\n" /* lx */
        "movl -0xd4(%ebp), %eax\n" /* line 400 | pSrc */
        "movl 0x28(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* ly */
        "movl -0xd4(%ebp), %edx\n" /* line 401 | pSrc */
        "movl 0x2c(%edx), %edx\n"
        "movl %edx, -0x54(%ebp)\n" /* bnx */
        "movl -0xd4(%ebp), %eax\n" /* line 402 | pSrc */
        "movl 0x30(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* bny */
        "movl -0xd4(%ebp), %edx\n" /* line 403 | pSrc */
        "movl 0x34(%edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* bnz */
        "movl -0xd4(%ebp), %eax\n" /* line 404 | pSrc */
        "movl 0x38(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* tanx */
        "movl -0xd4(%ebp), %edx\n" /* line 405 | pSrc */
        "movl 0x3c(%edx), %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* tany */
        "movl -0xd4(%ebp), %eax\n" /* line 406 | pSrc */
        "movl 0x40(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* tanz */
        "movl -0xd4(%ebp), %edx\n" /* line 408 | pSrc */
        "movl (%edx), %edx\n"
        "movl -0xd0(%ebp), %eax\n" /* pDst */
        "movl %edx, (%eax)\n"
        "movl -0xfc(%ebp), %edx\n" /* line 409 | y */
        "movl %edx, 4(%eax)\n"
        "movl %ecx, 8(%eax)\n" /* line 410 */
        "movl %ebx, 0xc(%eax)\n" /* line 411 | nx */
        "movl %esi, 0x10(%eax)\n" /* line 412 | ny */
        "movl %edi, 0x14(%eax)\n" /* line 413 | nz */
        "movl -0xcc(%ebp), %ebx\n" /* line 414 | c, nx */
        "movl (%ebx), %edx\n" /* nx */
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* color, ny */
        "movl %esi, 4(%esp)\n" /* ny */
        "movl %ebx, (%esp)\n" /* nx */
        "calll *(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 415 | color */
        "movl -0xd0(%ebp), %edx\n" /* pDst */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x64(%ebp), %ebx\n" /* line 416 | tx, nx */
        "movl %ebx, 0x1c(%edx)\n" /* nx */
        "movl -0x60(%ebp), %esi\n" /* line 417 | ty, ny */
        "movl %esi, 0x20(%edx)\n" /* ny */
        "movl -0x5c(%ebp), %eax\n" /* line 418 | lx */
        "movl %eax, 0x24(%edx)\n"
        "movl -0x58(%ebp), %ebx\n" /* line 419 | ly, nx */
        "movl %ebx, 0x28(%edx)\n" /* nx */
        "movl -0x54(%ebp), %esi\n" /* line 420 | bnx, ny */
        "movl %esi, 0x2c(%edx)\n" /* ny */
        "movl -0x50(%ebp), %eax\n" /* line 421 | bny */
        "movl %eax, 0x30(%edx)\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 422 | bnz, nx */
        "movl %ebx, 0x34(%edx)\n" /* nx */
        "movl -0x48(%ebp), %esi\n" /* line 423 | tanx, ny */
        "movl %esi, 0x38(%edx)\n" /* ny */
        "movl -0x44(%ebp), %eax\n" /* line 424 | tany */
        "movl %eax, 0x3c(%edx)\n"
        "movl -0x40(%ebp), %ebx\n" /* line 425 | tanz, nx */
        "movl %ebx, 0x40(%edx)\n" /* nx */
        /* } scope */
        "addl $1, -0x68(%ebp)\n" /* line 388 | i */
        "movl -0x2c(%ebp), %esi\n" /* nx */
        "addl %esi, -0xd4(%ebp)\n" /* nx, pSrc */
        "addl %esi, %edx\n" /* nx */
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0x68(%ebp), %eax\n" /* i */
        "cmpl %eax, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7849\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f798f:\n"
        "movl -0xe0(%ebp), %edi\n" /* line 347 | z */
        "testl %edi, %edi\n" /* z */
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* x */
        "movl %ebx, -0x30(%ebp)\n" /* x */
        "movl $0, -0x90(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f79ad:\n"
        "movl -0xd4(%ebp), %ebx\n" /* line 350 | pSrc, x */
        "movl 4(%ebx), %ebx\n" /* x */
        "movl %ebx, -0xfc(%ebp)\n" /* x, y */
        "movl -0xd4(%ebp), %esi\n" /* line 351 | pSrc, y */
        "movl 8(%esi), %ecx\n" /* y, z */
        "movl 0xc(%esi), %ebx\n" /* line 352 | y, w */
        "movl %esi, %eax\n" /* line 353 | nx */
        "movl 0x10(%esi), %esi\n" /* nx */
        "movl 0x14(%eax), %edi\n" /* line 354 | ny */
        "movl 0x18(%eax), %edx\n" /* line 355 */
        "movl %edx, -0x8c(%ebp)\n" /* nz */
        "movl 0x20(%eax), %eax\n" /* line 357 */
        "movl %eax, -0x88(%ebp)\n" /* tx */
        "movl -0xd4(%ebp), %edx\n" /* line 358 | pSrc */
        "movl 0x24(%edx), %edx\n"
        "movl %edx, -0x84(%ebp)\n" /* ty */
        "movl -0xd4(%ebp), %eax\n" /* line 359 | pSrc */
        "movl 0x28(%eax), %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* bnx */
        "movl -0xd4(%ebp), %edx\n" /* line 360 | pSrc */
        "movl 0x2c(%edx), %edx\n"
        "movl %edx, -0x7c(%ebp)\n" /* bny */
        "movl -0xd4(%ebp), %eax\n" /* line 361 | pSrc */
        "movl 0x30(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* bnz */
        "movl -0xd4(%ebp), %edx\n" /* line 362 | pSrc */
        "movl 0x34(%edx), %edx\n"
        "movl %edx, -0x74(%ebp)\n" /* tanx */
        "movl -0xd4(%ebp), %eax\n" /* line 363 | pSrc */
        "movl 0x38(%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* tany */
        "movl -0xd4(%ebp), %edx\n" /* line 364 | pSrc */
        "movl 0x3c(%edx), %edx\n"
        "movl %edx, -0x6c(%ebp)\n" /* tanz */
        "movl -0xd4(%ebp), %eax\n" /* line 366 | pSrc */
        "movl (%eax), %eax\n"
        "movl -0xd0(%ebp), %edx\n" /* pDst */
        "movl %eax, (%edx)\n"
        "movl -0xfc(%ebp), %eax\n" /* line 367 | y */
        "movl %eax, 4(%edx)\n"
        "movl %ecx, 8(%edx)\n" /* line 368 */
        "movl %ebx, 0xc(%edx)\n" /* line 369 | w */
        "movl %esi, 0x10(%edx)\n" /* line 370 | nx */
        "movl %edi, 0x14(%edx)\n" /* line 371 | ny */
        "movl -0x8c(%ebp), %ebx\n" /* line 372 | nz, w */
        "movl %ebx, 0x18(%edx)\n" /* w */
        "movl -0xcc(%ebp), %esi\n" /* line 374 | c, nx */
        "movl (%esi), %edx\n" /* nx */
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0x1c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* nx */
        "calll *(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 375 | color */
        "movl -0xd0(%ebp), %edx\n" /* pDst */
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x88(%ebp), %ebx\n" /* line 377 | tx, w */
        "movl %ebx, 0x20(%edx)\n" /* w */
        "movl -0x84(%ebp), %esi\n" /* line 378 | ty, nx */
        "movl %esi, 0x24(%edx)\n" /* nx */
        "movl -0x80(%ebp), %eax\n" /* line 379 | bnx */
        "movl %eax, 0x28(%edx)\n"
        "movl -0x7c(%ebp), %ebx\n" /* line 380 | bny, w */
        "movl %ebx, 0x2c(%edx)\n" /* w */
        "movl -0x78(%ebp), %esi\n" /* line 381 | bnz, nx */
        "movl %esi, 0x30(%edx)\n" /* nx */
        "movl -0x74(%ebp), %eax\n" /* line 382 | tanx */
        "movl %eax, 0x34(%edx)\n"
        "movl -0x70(%ebp), %ebx\n" /* line 383 | tany, w */
        "movl %ebx, 0x38(%edx)\n" /* w */
        "movl -0x6c(%ebp), %esi\n" /* line 384 | tanz, nx */
        "movl %esi, 0x3c(%edx)\n" /* nx */
        /* } scope */
        "addl $1, -0x90(%ebp)\n" /* line 347 | i */
        "movl -0x30(%ebp), %eax\n"
        "addl %eax, -0xd4(%ebp)\n" /* pSrc */
        "addl %eax, %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0x90(%ebp), %edx\n" /* i */
        "cmpl %edx, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f79ad\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7af9:\n"
        "movl -0xe0(%ebp), %esi\n" /* line 274 */
        "testl %esi, %esi\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* strideInDWords */
        "movl %ebx, -0x34(%ebp)\n" /* strideInDWords */
        "movl $0, -0xc8(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7b17:\n"
        "movl -0xd4(%ebp), %eax\n" /* line 276 | pSrc */
        "movl (%eax), %ebx\n" /* x */
        "movl 4(%eax), %esi\n" /* line 277 | y */
        "movl 8(%eax), %edi\n" /* line 278 | z */
        "movl 0xc(%eax), %edx\n" /* line 279 */
        "movl %edx, -0xc4(%ebp)\n" /* nx */
        "movl 0x10(%eax), %eax\n" /* line 280 */
        "movl %eax, -0xc0(%ebp)\n" /* ny */
        "movl -0xd4(%ebp), %edx\n" /* line 281 | pSrc */
        "movl 0x14(%edx), %edx\n"
        "movl %edx, -0xbc(%ebp)\n" /* nz */
        "movl -0xd4(%ebp), %eax\n" /* line 283 | pSrc */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0xb8(%ebp)\n" /* tx */
        "movl -0xd4(%ebp), %edx\n" /* line 284 | pSrc */
        "movl 0x20(%edx), %edx\n"
        "movl %edx, -0xb4(%ebp)\n" /* ty */
        "movl -0xcc(%ebp), %eax\n" /* line 286 | c */
        "movl (%eax), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl -0xcc(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 288 | pDst */
        "movl %ebx, (%edx)\n" /* x */
        "movl %esi, 4(%edx)\n" /* line 289 | y */
        "movl %edi, 8(%edx)\n" /* line 290 | z */
        "movl -0xc4(%ebp), %ebx\n" /* line 291 | nx, x */
        "movl %ebx, 0xc(%edx)\n" /* x */
        "movl -0xc0(%ebp), %esi\n" /* line 292 | ny, y */
        "movl %esi, 0x10(%edx)\n" /* y */
        "movl -0xbc(%ebp), %eax\n" /* line 293 | nz */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 294 | color */
        "movl %eax, 0x18(%edx)\n"
        "movl -0xb8(%ebp), %ebx\n" /* line 295 | tx, x */
        "movl %ebx, 0x1c(%edx)\n" /* x */
        "movl -0xb4(%ebp), %esi\n" /* line 296 | ty, y */
        "movl %esi, 0x20(%edx)\n" /* y */
        /* } scope */
        "addl $1, -0xc8(%ebp)\n" /* line 274 | i */
        "movl -0x34(%ebp), %eax\n"
        "addl %eax, -0xd4(%ebp)\n" /* pSrc */
        "addl %eax, %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0xc8(%ebp), %edx\n" /* i */
        "cmpl %edx, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7b17\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7bfb:\n"
        "movl -0xe0(%ebp), %ecx\n" /* line 300 */
        "testl %ecx, %ecx\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* x */
        "movl %ebx, -0x38(%ebp)\n" /* x */
        "movl $0, -0xb0(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7c19:\n"
        "movl -0xd4(%ebp), %esi\n" /* line 302 | pSrc, y */
        "movl (%esi), %ebx\n" /* y, x */
        "movl %esi, %eax\n" /* line 303 | y */
        "movl 4(%esi), %esi\n" /* y */
        "movl 8(%eax), %edi\n" /* line 304 | z */
        "movl 0x10(%eax), %edx\n" /* line 306 */
        "movl %edx, -0xac(%ebp)\n" /* tx0 */
        "movl 0x14(%eax), %eax\n" /* line 307 */
        "movl %eax, -0xa8(%ebp)\n" /* ty0 */
        "movl -0xd4(%ebp), %edx\n" /* line 308 | pSrc */
        "movl 0x18(%edx), %edx\n"
        "movl %edx, -0xa4(%ebp)\n" /* tx1 */
        "movl -0xd4(%ebp), %eax\n" /* line 309 | pSrc */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, -0xa0(%ebp)\n" /* ty1 */
        "movl -0xcc(%ebp), %eax\n" /* line 311 | c */
        "movl (%eax), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0xc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl -0xcc(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 313 | pDst */
        "movl %ebx, (%edx)\n" /* x */
        "movl %esi, 4(%edx)\n" /* line 314 | y */
        "movl %edi, 8(%edx)\n" /* line 315 | z */
        "movl -0x20(%ebp), %eax\n" /* line 316 | color */
        "movl %eax, 0xc(%edx)\n"
        "movl -0xac(%ebp), %ebx\n" /* line 317 | tx0, x */
        "movl %ebx, 0x10(%edx)\n" /* x */
        "movl -0xa8(%ebp), %esi\n" /* line 318 | ty0, y */
        "movl %esi, 0x14(%edx)\n" /* y */
        "movl -0xa4(%ebp), %eax\n" /* line 319 | tx1 */
        "movl %eax, 0x18(%edx)\n"
        "movl -0xa0(%ebp), %ebx\n" /* line 320 | ty1, x */
        "movl %ebx, 0x1c(%edx)\n" /* x */
        /* } scope */
        "addl $1, -0xb0(%ebp)\n" /* line 300 | i */
        "movl -0x38(%ebp), %esi\n" /* y */
        "addl %esi, -0xd4(%ebp)\n" /* y, pSrc */
        "addl %esi, %edx\n" /* y */
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0xb0(%ebp), %eax\n" /* i */
        "cmpl %eax, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7c19\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7ce7:\n"
        "movl -0xe0(%ebp), %edx\n" /* line 327 */
        "testl %edx, %edx\n"
        "je .Lff76c0_000f7795\n"
        "shll $2, %ebx\n" /* x */
        "movl %ebx, -0x3c(%ebp)\n" /* x */
        "movl $0, -0x9c(%ebp)\n" /* i */
        /* { scope 3 */
        ".Lff76c0_000f7d05:\n"
        "movl -0xd4(%ebp), %esi\n" /* line 329 | pSrc, y */
        "movl (%esi), %ebx\n" /* y, x */
        "movl %esi, %eax\n" /* line 330 | y */
        "movl 4(%esi), %esi\n" /* y */
        "movl 8(%eax), %edi\n" /* line 331 | z */
        "movl 0x10(%eax), %edx\n" /* line 333 */
        "movl %edx, -0x98(%ebp)\n" /* tx */
        "movl 0x14(%eax), %eax\n" /* line 334 */
        "movl %eax, -0x94(%ebp)\n" /* ty */
        "movl -0xcc(%ebp), %eax\n" /* line 336 | c */
        "movl (%eax), %edx\n"
        "movl -0xd4(%ebp), %eax\n" /* pSrc */
        "addl $0xc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl -0xcc(%ebp), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll *(%edx)\n"
        "movl -0xd0(%ebp), %edx\n" /* line 338 | pDst */
        "movl %ebx, (%edx)\n" /* x */
        "movl %esi, 4(%edx)\n" /* line 339 | y */
        "movl %edi, 8(%edx)\n" /* line 340 | z */
        "movl -0x20(%ebp), %eax\n" /* line 341 | color */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x98(%ebp), %ebx\n" /* line 342 | tx, x */
        "movl %ebx, 0x10(%edx)\n" /* x */
        "movl -0x94(%ebp), %esi\n" /* line 343 | ty, y */
        "movl %esi, 0x14(%edx)\n" /* y */
        /* } scope */
        "addl $1, -0x9c(%ebp)\n" /* line 327 | i */
        "movl -0x3c(%ebp), %eax\n"
        "addl %eax, -0xd4(%ebp)\n" /* pSrc */
        "addl %eax, %edx\n"
        "movl %edx, -0xd0(%ebp)\n" /* pDst */
        "movl -0x9c(%ebp), %edx\n" /* i */
        "cmpl %edx, -0xe0(%ebp)\n"
        "ja .Lff76c0_000f7d05\n"
        "jmp .Lff76c0_000f7795\n"
        /* } scope */
        ".Lff76c0_000f7da3:\n"
        "movl %eax, (%esp)\n" /* line 258 */
        "calll R_FatalLockError\n"
        "jmp .Lff76c0_000f772d\n"
        /* { scope 2: y, color, tx, ty, ... */
        ".Lff76c0_000f7db0:\n"
        "movl 0x14(%ebp), %eax\n" /* line 220 | stride */
        "cmpl 8(%edx), %eax\n"
        "je .Lff76c0_000f7801\n"
        "movl %eax, %edx\n"
        "movl -0xdc(%ebp), %ebx\n" /* dxVb */
        "jmp .Lff76c0_000f77e4\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f76c0_0:\n"
        ".long .Lff76c0_000f7779\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7ce7\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7bfb\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7af9\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f798f\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f7795\n"
        ".long .Lff76c0_000f782e\n"
        ".text\n"
    );
}

/* line 710 */
static __attribute__((naked))
const float * RB_GetCodeMatrix(int source, int firstRow)
{
    __asm__ __volatile__ (
        ".Lff7dca_000f7dca:\n"
        "pushl %ebp\n" /* line 710 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        "movl %eax, -0x138(%ebp)\n"
        "movl %edx, -0x13c(%ebp)\n"
        /* { scope 1: OGLWorld, OGLView, OGLWorldView, OGLProjection, ... */
        "movl imp_backEnd, %ebx\n" /* line 719 */
        "movl 0x2e80(%ebx), %edx\n"
        "movl %edx, %ecx\n" /* rowCount */
        "shll $4, %ecx\n" /* rowCount */
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n" /* rowCount */
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal 0x4e0(%eax, %ebx), %eax\n"
        "movl %eax, -0x134(%ebp)\n" /* activeMatrices */
        "movl -0x138(%ebp), %eax\n" /* line 726 */
        "andl $0xfffffffc, %eax\n"
        "subl $0xbc, %eax\n"
        "cmpl $0x30, %eax\n"
        "ja .Lff7dca_000f7e26\n"
        "jmpl *.Ljt_f7dca_0(, %eax, 4)\n"
        ".Lff7dca_000f7e26:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x14c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: OGLWorld, OGLView, OGLWorldView, OGLProjection, ... */
        ".Lff7dca_000f7e33:\n"
        "movl -0x134(%ebp), %eax\n" /* line 729 | activeMatrices */
        "addl $0x10, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        ".Lff7dca_000f7e42:\n"
        "movl -0x138(%ebp), %esi\n" /* line 864 | matrixIndex */
        "andl $3, %esi\n" /* matrixIndex */
        "cmpb $0, 0x100(%esi, %eax)\n" /* line 865 | matrixIndex */
        "jne .Lff7dca_000f7ea9\n"
        "movl %esi, %edi\n" /* line 867 | matrixIndex, transposeIndex */
        "xorl $2, %edi\n" /* transposeIndex */
        "cmpb $0, 0x100(%edi, %eax)\n" /* line 868 | transposeIndex */
        "jne .Lff7dca_000f8697\n"
        "movl %esi, %edx\n" /* line 875 | matrixIndex */
        "xorl $1, %edx\n"
        "movl -0x130(%ebp), %ecx\n" /* line 876 | codeMatrix, rowCount */
        "cmpb $0, 0x100(%edx, %ecx)\n"
        "je .Lff7dca_000f863e\n"
        "movl %esi, %eax\n" /* line 878 | matrixIndex */
        "shll $6, %eax\n"
        "addl %ecx, %eax\n" /* rowCount */
        "movl %eax, 4(%esp)\n"
        "shll $6, %edx\n"
        "movl %ecx, %eax\n" /* rowCount */
        "addl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixInverse44\n"
        "movl -0x130(%ebp), %eax\n" /* line 879 | codeMatrix */
        "movb $1, 0x100(%esi, %eax)\n" /* matrixIndex */
        ".Lff7dca_000f7ea9:\n"
        "movl -0x13c(%ebp), %edx\n" /* line 894 */
        "leal (%edx, %esi, 4), %eax\n"
        "shll $4, %eax\n"
        "addl -0x130(%ebp), %eax\n" /* codeMatrix */
        /* } scope */
        "addl $0x14c, %esp\n" /* line 895 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: OGLWorld, OGLView, OGLWorldView, OGLProjection, ... */
        ".Lff7dca_000f7ec6:\n"
        "movl -0x134(%ebp), %edx\n" /* line 733 | activeMatrices */
        "addl $0x230, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        "movl %edx, %eax\n"
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7edf:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 737 | activeMatrices, rowCount */
        "addl $0x340, %ecx\n" /* rowCount */
        "movl %ecx, -0x130(%ebp)\n" /* rowCount, codeMatrix */
        "movl %ecx, %eax\n" /* rowCount */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7ef8:\n"
        "movl -0x134(%ebp), %eax\n" /* line 741 | activeMatrices */
        "addl $0x450, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 742 */
        "jne .Lff7dca_000f7e42\n"
        "movl %eax, 8(%esp)\n" /* line 744 */
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x230, %eax\n"
        ".Lff7dca_000f7f25:\n"
        "movl %eax, 4(%esp)\n" /* line 835 */
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %edx\n" /* line 836 | codeMatrix */
        "movb $1, 0x100(%edx)\n"
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7f52:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 750 | activeMatrices, rowCount */
        "addl $0x670, %ecx\n" /* rowCount */
        "movl %ecx, -0x130(%ebp)\n" /* rowCount, codeMatrix */
        "cmpb $0, 0x100(%ecx)\n" /* line 751 | rowCount */
        "je .Lff7dca_000f85a0\n"
        ".Lff7dca_000f7f71:\n"
        "movl %ecx, %eax\n" /* rowCount */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7f78:\n"
        "movl -0x134(%ebp), %edx\n" /* line 759 | activeMatrices */
        "addl $0x780, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%edx)\n" /* line 760 */
        "jne .Lff7dca_000f856a\n"
        "movl -0x134(%ebp), %ecx\n" /* line 762 | activeMatrices, rowCount */
        "cmpb $0, 0x550(%ecx)\n" /* rowCount */
        "je .Lff7dca_000f86cc\n"
        "leal 0x450(%ecx), %ebx\n" /* rowCount */
        "movl %ecx, %eax\n" /* rowCount */
        ".Lff7dca_000f7fb2:\n"
        "movl -0x130(%ebp), %ecx\n" /* line 767 | codeMatrix, rowCount */
        "movl %ecx, 8(%esp)\n" /* rowCount */
        "addl $0x340, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %eax\n" /* line 768 | codeMatrix */
        "movb $1, 0x100(%eax)\n"
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f7fe5:\n"
        "movl -0x134(%ebp), %edx\n" /* line 774 | activeMatrices */
        "addl $0xcd0, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        /* { scope 2 */
        "movl $4, %ecx\n" /* line 778 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbc, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "leal -0x68(%ebp), %ebx\n" /* OGLWorld */
        "movl (%eax), %edx\n"
        "movl %edx, -0x68(%ebp)\n" /* OGLWorld */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x54(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl $4, %ecx\n" /* line 780 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc0, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "leal -0xa8(%ebp), %ecx\n" /* OGLView, rowCount */
        "movl (%eax), %edx\n"
        "movl %edx, -0xa8(%ebp)\n" /* OGLView */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0xa4(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0xa0(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x98(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x94(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x8c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x84(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x74(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movss lightGridLookupMatrix+368, %xmm1\n" /* line 782 */
        "movss -0xa0(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "movss -0x90(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movss -0x70(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "leal -0xe8(%ebp), %esi\n" /* line 784 | OGLWorldView, matrixIndex */
        "movl %esi, 8(%esp)\n" /* matrixIndex */
        "movl %ecx, 4(%esp)\n" /* rowCount */
        "movl %ebx, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl $4, %ecx\n" /* line 786 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc4, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "leal -0x128(%ebp), %ebx\n" /* OGLProjection */
        "movl (%eax), %edx\n"
        "movl %edx, -0x128(%ebp)\n" /* OGLProjection */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x124(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x120(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x11c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x118(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x114(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x110(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x10c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x108(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x104(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x100(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0xfc(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0xf8(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0xf4(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0xf0(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0xec(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 789 | viewport */
        "movl %eax, (%esp)\n"
        "calll RB_GetViewport\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* line 790 */
        "movss %xmm0, 8(%esp)\n"
        "cvtsi2ssl -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL\n"
        "movl -0x130(%ebp), %ecx\n" /* line 792 | codeMatrix, rowCount */
        "movl %ecx, 8(%esp)\n" /* rowCount */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* matrixIndex */
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %eax\n" /* line 793 | codeMatrix */
        "movb $1, 0x100(%eax)\n"
        "movb $0, 0x101(%eax)\n" /* line 794 */
        "movb $0, 0x102(%eax)\n" /* line 795 */
        "movb $0, 0x103(%eax)\n" /* line 796 */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        /* } scope */
        ".Lff7dca_000f826e:\n"
        "movl -0x134(%ebp), %eax\n" /* line 822 | activeMatrices */
        "addl $0x560, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 823 */
        "jne .Lff7dca_000f7e42\n"
        "movl $4, %ecx\n" /* line 825 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xd0, %eax\n"
        ".Lff7dca_000f8298:\n"
        "calll RB_GetCodeMatrix\n" /* line 815 */
        "movss lit4_002ed5d0, %xmm1\n" /* line 816 | 1.0f, scale */
        "movl -0x134(%ebp), %edx\n" /* activeMatrices */
        "divss (%edx), %xmm1\n" /* scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 691 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, 0x560(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 692 */
        "mulss 4(%eax), %xmm0\n"
        "movl -0x130(%ebp), %ecx\n" /* codeMatrix */
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 693 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "movl 0xc(%eax), %edx\n" /* line 694 */
        ".Lff7dca_000f82e1:\n"
        "movl %edx, 0xc(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 695 */
        "mulss 0x10(%eax), %xmm0\n"
        "movss %xmm0, 0x10(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 696 */
        "mulss 0x14(%eax), %xmm0\n"
        "movss %xmm0, 0x14(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 697 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, 0x18(%ecx)\n"
        "movl 0x1c(%eax), %edx\n" /* line 698 */
        "movl %edx, 0x1c(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 699 */
        "mulss 0x20(%eax), %xmm0\n"
        "movss %xmm0, 0x20(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 700 */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, 0x24(%ecx)\n"
        "mulss 0x28(%eax), %xmm1\n" /* line 701 */
        "movss %xmm1, 0x28(%ecx)\n"
        "movl 0x2c(%eax), %edx\n" /* line 702 */
        "movl %edx, 0x2c(%ecx)\n"
        "movl 0x30(%eax), %edx\n" /* line 703 */
        "movl %edx, 0x30(%ecx)\n"
        "movl 0x34(%eax), %edx\n" /* line 704 */
        "movl %edx, 0x34(%ecx)\n"
        "movl 0x38(%eax), %edx\n" /* line 705 */
        "movl %edx, 0x38(%ecx)\n"
        "movl 0x3c(%eax), %eax\n" /* line 706 */
        "movl %eax, 0x3c(%ecx)\n"
        /* } scope */
        "movb $1, 0x100(%ecx)\n" /* line 817 | rowCount */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f8365:\n"
        "movl -0x134(%ebp), %eax\n" /* line 832 | activeMatrices */
        "addl $0x9a0, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 833 */
        "jne .Lff7dca_000f7e42\n"
        "movl %eax, 8(%esp)\n" /* line 835 */
        "leal 0x36e48(%ebx), %eax\n"
        "jmp .Lff7dca_000f7f25\n"
        ".Lff7dca_000f8392:\n"
        "movl -0x134(%ebp), %ecx\n" /* line 841 | activeMatrices, rowCount */
        "addl $0xab0, %ecx\n" /* rowCount */
        "movl %ecx, -0x130(%ebp)\n" /* rowCount, codeMatrix */
        "cmpb $0, 0x100(%ecx)\n" /* line 842 | rowCount */
        "jne .Lff7dca_000f7f71\n"
        "movl $4, %ecx\n" /* line 844 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbf, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl -0x130(%ebp), %edx\n" /* line 845 | codeMatrix */
        "movl %edx, 8(%esp)\n"
        "movl $lightGridLookupMatrix, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %ecx\n" /* line 846 | codeMatrix, rowCount */
        "movb $1, 0x100(%ecx)\n" /* rowCount */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f83f4:\n"
        "movl -0x134(%ebp), %eax\n" /* line 851 | activeMatrices */
        "addl $0xbc0, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 852 */
        "jne .Lff7dca_000f7e42\n"
        /* { scope 2 */
        "movl imp_r_outdoorAwayBias, %eax\n" /* line 932 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* awayBias */
        "movl imp_r_outdoorDownBias, %eax\n" /* line 933 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x12c(%ebp)\n" /* downBias */
        "movl $4, %ecx\n" /* line 936 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbc, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl %eax, %edi\n" /* worldMatrix */
        "movl $4, %ecx\n" /* line 937 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc1, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "xorl %edx, %edx\n" /* line 447 */
        "movl %edx, -0xa8(%ebp)\n" /* OGLView */
        "movl %edx, -0xa4(%ebp)\n" /* line 448 */
        "xorl $0x80000000, %ebx\n" /* line 449 */
        "movl %ebx, -0xa0(%ebp)\n"
        "movl %edx, -0x9c(%ebp)\n" /* line 450 */
        "leal -0x68(%ebp), %esi\n" /* line 939 | OGLWorld, matrixIndex */
        "movl %esi, 8(%esp)\n" /* matrixIndex */
        "movl %eax, 4(%esp)\n"
        "leal -0xa8(%ebp), %eax\n" /* OGLView */
        "movl %eax, (%esp)\n"
        "calll MatrixTransformVector44\n"
        "movss -0x12c(%ebp), %xmm0\n" /* line 940 | downBias */
        "addss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 942 | viewport */
        "movl %eax, 8(%esp)\n"
        "movl imp_rgp, %ebx\n" /* awayBias */
        "movl 0x109c(%ebx), %eax\n" /* awayBias */
        "addl $0x1c0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* matrixIndex */
        "calll MatrixTransformVector44\n"
        "movl -0x130(%ebp), %eax\n" /* line 943 | codeMatrix */
        "movl %eax, 8(%esp)\n"
        "movl 0x109c(%ebx), %eax\n" /* awayBias */
        "addl $0x1c0, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* worldMatrix */
        "calll MatrixMultiply44\n"
        "movl -0x134(%ebp), %eax\n" /* line 944 | activeMatrices, sum */
        "addl $0xbf0, %eax\n" /* sum */
        /* { scope 3 */
        "movl -0x134(%ebp), %edx\n" /* line 483 | activeMatrices */
        "movss 0xbf0(%edx), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n" /* viewport */
        "movss %xmm0, 0xbf0(%edx)\n"
        "movss 4(%eax), %xmm0\n" /* line 484 */
        "addss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%eax), %xmm0\n" /* line 485 */
        "addss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movss 0xc(%eax), %xmm0\n" /* line 486 */
        "addss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        /* } scope */
        /* } scope */
        "movl -0x130(%ebp), %ecx\n" /* line 855 | codeMatrix, rowCount */
        "movb $1, 0x100(%ecx)\n" /* rowCount */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f854f:\n"
        "movl -0x134(%ebp), %edx\n" /* line 802 | activeMatrices */
        "addl $0x120, %edx\n"
        "movl %edx, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%edx)\n" /* line 803 */
        "je .Lff7dca_000f85de\n"
        ".Lff7dca_000f856a:\n"
        "movl %edx, %eax\n"
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f8571:\n"
        "movl -0x134(%ebp), %eax\n" /* line 812 | activeMatrices */
        "addl $0x560, %eax\n"
        "movl %eax, -0x130(%ebp)\n" /* codeMatrix */
        "cmpb $0, 0x100(%eax)\n" /* line 813 */
        "jne .Lff7dca_000f7e42\n"
        "movl $4, %ecx\n" /* line 815 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xc8, %eax\n"
        "jmp .Lff7dca_000f8298\n"
        ".Lff7dca_000f85a0:\n"
        "movl %ecx, 8(%esp)\n" /* line 753 | rowCount */
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x340, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "addl $0x230, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x130(%ebp), %eax\n" /* line 754 | codeMatrix */
        "movb $1, 0x100(%eax)\n"
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "jmp .Lff7dca_000f7e42\n"
        ".Lff7dca_000f85de:\n"
        "movl $4, %ecx\n" /* line 805 | rowCount */
        "xorl %edx, %edx\n"
        "movl $0xbc, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 806 | 1.0f, scale */
        "movl -0x134(%ebp), %ecx\n" /* activeMatrices, rowCount */
        "divss (%ecx), %xmm1\n" /* rowCount, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 691 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, 0x120(%ecx)\n"
        "movaps %xmm1, %xmm0\n" /* line 692 */
        "mulss 4(%eax), %xmm0\n"
        "movl -0x130(%ebp), %edx\n" /* codeMatrix */
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 693 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "movl 0xc(%eax), %edx\n" /* line 694 */
        "movl -0x130(%ebp), %ecx\n" /* codeMatrix */
        "jmp .Lff7dca_000f82e1\n"
        /* } scope */
        ".Lff7dca_000f863e:\n"
        "movl %edi, %ebx\n" /* line 885 | transposeIndex */
        "shll $6, %ebx\n"
        "addl -0x130(%ebp), %ebx\n" /* codeMatrix */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, %eax\n" /* matrixIndex */
        "xorl $3, %eax\n"
        "shll $6, %eax\n"
        "addl -0x130(%ebp), %eax\n" /* codeMatrix */
        "movl %eax, (%esp)\n"
        "calll MatrixTranspose44\n"
        "movl -0x130(%ebp), %edx\n" /* line 886 | codeMatrix */
        "movb $1, 0x100(%edi, %edx)\n" /* transposeIndex */
        "movl %esi, %eax\n" /* line 887 | matrixIndex */
        "shll $6, %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixInverse44\n"
        "movl -0x130(%ebp), %ecx\n" /* line 888 | codeMatrix, rowCount */
        "movb $1, 0x100(%esi, %ecx)\n" /* matrixIndex */
        "jmp .Lff7dca_000f7ea9\n"
        ".Lff7dca_000f8697:\n"
        "movl %esi, %eax\n" /* line 870 | matrixIndex */
        "shll $6, %eax\n"
        "addl -0x130(%ebp), %eax\n" /* codeMatrix */
        "movl %eax, 4(%esp)\n"
        "shll $6, %edi\n" /* transposeIndex */
        "movl -0x130(%ebp), %eax\n" /* codeMatrix */
        "addl %edi, %eax\n" /* transposeIndex */
        "movl %eax, (%esp)\n"
        "calll MatrixTranspose44\n"
        "movl -0x130(%ebp), %edx\n" /* line 871 | codeMatrix */
        "movb $1, 0x100(%esi, %edx)\n" /* matrixIndex */
        "jmp .Lff7dca_000f7ea9\n"
        ".Lff7dca_000f86cc:\n"
        "movl %ecx, %ebx\n" /* line 764 | rowCount */
        "addl $0x450, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %ecx, %eax\n" /* rowCount */
        "addl $0x230, %eax\n"
        "movl %eax, 4(%esp)\n"
        "subl $0x220, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "movl -0x134(%ebp), %eax\n" /* line 765 | activeMatrices */
        "movb $1, 0x550(%eax)\n"
        "movl -0x134(%ebp), %eax\n" /* activeMatrices */
        "jmp .Lff7dca_000f7fb2\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f7dca_0:\n"
        ".long .Lff7dca_000f7e33\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7ec6\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7edf\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7ef8\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7f52\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7f78\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7fe5\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f854f\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f8571\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f826e\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f8365\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f8392\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f7e26\n"
        ".long .Lff7dca_000f83f4\n"
        ".text\n"
    );
}

/* line 1439 */
static __attribute__((naked))
void RB_DrawSingleTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args, const GfxStateOverride *stateOverride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1439 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18c, %esp\n"
        "movl %edx, -0xdc(%ebp)\n"
        "movl %ecx, -0xe0(%ebp)\n"
        /* { scope 1: pass, stateBits */
        "movl imp_tess, %esi\n" /* line 1444 | constantIndex */
        "movl 0x5a7bc(%esi), %edx\n" /* constantIndex */
        "movl 0x38(%edx), %edx\n"
        "movl 4(%edx, %eax, 4), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "cmpl $0x21, %eax\n" /* line 1450 | techType */
        "je .Lff8708_000f9b4b\n"
        ".Lff8708_000f873f:\n"
        "movl imp_g_special, %eax\n" /* line 1457 | techType */
        "cmpl $3, -0xdc(%ebp)\n"
        "sete (%eax)\n" /* techType */
        "cmpw $0, 6(%edx)\n" /* line 1459 */
        "je .Lff8708_000f9175\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl $0, -0xd8(%ebp)\n" /* passIndex */
        "movl imp_r_rendererInUse, %eax\n" /* line 1429 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff8708_000f8d5f\n"
        ".Lff8708_000f8777:\n"
        "movl -0xd8(%ebp), %eax\n" /* line 1436 | passIndex */
        "shll $2, %eax\n"
        "movl -0xd8(%ebp), %edx\n" /* passIndex */
        "shll $5, %edx\n"
        "subl %eax, %edx\n"
        "movl -0x3c(%ebp), %ebx\n" /* fvf */
        "addl %edx, %ebx\n" /* fvf */
        "leal 8(%ebx), %eax\n" /* fvf */
        "movl %eax, -0xc0(%ebp)\n" /* pass */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "movl %eax, %edx\n" /* line 1273 */
        "movl 4(%eax), %eax\n"
        "movl -0xdc(%ebp), %ecx\n"
        "movl 8(%eax, %ecx, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9b02\n"
        ".Lff8708_000f87b0:\n"
        "movl 0x5a7bc(%esi), %esi\n" /* line 1279 | constantIndex */
        "addl $0x2c, %esi\n" /* constantIndex */
        "movl %esi, -0xb8(%ebp)\n" /* constantIndex, refStateBits */
        "movl 8(%ebx), %ebx\n" /* codeConst */
        "movl %ebx, -0x44(%ebp)\n" /* codeConst */
        "movl $1, %edx\n"
        "movl %esi, %ebx\n" /* constantIndex, codeConst */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f87cc:\n"
        "movl -4(%ebx, %edx, 4), %eax\n" /* line 1247 | codeConst */
        "movl %eax, -0x2c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n"
        "cmpl $3, %edx\n" /* line 1246 */
        "jne .Lff8708_000f91e8\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl $0, -0xbc(%ebp)\n" /* ruleSetIndex */
        "movl %eax, %edx\n"
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jle .Lff8708_000f8c62\n"
        ".Lff8708_000f87ff:\n"
        "movl -0xb8(%ebp), %ecx\n" /* line 1223 | refStateBits */
        "movl (%ecx), %edi\n"
        "xorl %ecx, %ecx\n"
        "movl %eax, %edx\n"
        "jmp .Lff8708_000f881b\n"
        ".Lff8708_000f880d:\n"
        "addl $1, %ecx\n" /* line 1219 */
        "addl $0x20, %edx\n"
        "cmpl %esi, %ecx\n" /* constantIndex */
        "je .Lff8708_000f8c62\n"
        ".Lff8708_000f881b:\n"
        "leal 4(%edx), %ebx\n" /* line 1221 | codeConst */
        "movl %ebx, -0x170(%ebp)\n" /* codeConst, rule */
        "movl %edi, %eax\n" /* line 1223 */
        "andl 4(%edx), %eax\n"
        "cmpl 0xc(%edx), %eax\n"
        "jne .Lff8708_000f880d\n"
        "movl -0xb8(%ebp), %ebx\n" /* refStateBits, codeConst */
        "movl 4(%ebx), %eax\n" /* codeConst */
        "andl 8(%edx), %eax\n"
        "cmpl 0x10(%edx), %eax\n"
        "jne .Lff8708_000f880d\n"
        "movl -0x170(%ebp), %ecx\n" /* rule */
        "movl $1, %ebx\n" /* codeConst */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f8850:\n"
        "movl -4(%edx), %eax\n" /* line 1227 */
        "andl 0x18(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "orl 0x10(%ecx), %eax\n" /* line 1228 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* codeConst */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1225 | codeConst */
        "jne .Lff8708_000f8850\n"
        /* } scope */
        /* } scope */
        "addl $1, -0xbc(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x50(%ebp)\n"
        "cmpl $0xb, -0xbc(%ebp)\n" /* ruleSetIndex */
        "jne .Lff8708_000f8cb2\n"
        /* } scope */
        ".Lff8708_000f8885:\n"
        "movl 8(%ebp), %eax\n" /* line 1281 | stateOverride */
        "testl %eax, %eax\n"
        "je .Lff8708_000f88b3\n"
        "movl 8(%ebp), %ecx\n" /* stateOverride */
        "movl $1, %ebx\n" /* codeConst */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f889a:\n"
        "movl -4(%edx), %eax\n" /* line 1285 */
        "andl (%ecx), %eax\n"
        "orl 8(%ecx), %eax\n" /* line 1286 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* codeConst */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1283 | codeConst */
        "jne .Lff8708_000f889a\n"
        ".Lff8708_000f88b3:\n"
        "movl imp_backEnd, %eax\n" /* line 1290 */
        "cmpb $0, 0x4bd(%eax)\n"
        "je .Lff8708_000f88c5\n"
        "andl $0xffffffcf, -0x24(%ebp)\n" /* line 1291 */
        ".Lff8708_000f88c5:\n"
        "movl -0x28(%ebp), %eax\n" /* line 155 | stateBits */
        "movl imp_dxState, %esi\n"
        "cmpl 0x2000(%esi), %eax\n"
        "je .Lff8708_000f88e7\n"
        "movl %eax, (%esp)\n" /* line 158 */
        "calll RB_ChangeState_0\n"
        "movl -0x28(%ebp), %eax\n" /* line 160 | stateBits */
        "movl %eax, 0x2000(%esi)\n"
        ".Lff8708_000f88e7:\n"
        "movl -0x24(%ebp), %eax\n" /* line 163 */
        "cmpl 0x2004(%esi), %eax\n"
        "je .Lff8708_000f8903\n"
        "movl %eax, (%esp)\n" /* line 166 */
        "calll RB_ChangeState_1\n"
        "movl -0x24(%ebp), %eax\n" /* line 168 */
        "movl %eax, 0x2004(%esi)\n"
        ".Lff8708_000f8903:\n"
        "movl $0, (%esp)\n" /* line 1304 */
        "calll RB_UpdateFogColor\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 1306 | pass */
        "movl 0xc(%ecx), %eax\n"
        "movl 0xc(%eax), %ebx\n" /* shader */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "cmpl 0x2138(%esi), %ebx\n" /* line 227 */
        "je .Lff8708_000f97d0\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff8708_000f8933:\n"
        "movl 8(%edi), %eax\n" /* line 231 */
        "movl (%eax), %edx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1ac(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8933\n"
        "movl imp_dxState, %edx\n" /* line 232 */
        "movl %ebx, 0x2138(%edx)\n"
        /* } scope */
        ".Lff8708_000f8957:\n"
        "movl -0xc0(%ebp), %ebx\n" /* line 1307 | pass, shader */
        "movl 8(%ebx), %eax\n" /* shader */
        "movl 0xc(%eax), %ebx\n" /* shader */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "cmpl 0x213c(%edx), %ebx\n" /* line 240 */
        "je .Lff8708_000f899b\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff8708_000f8977:\n"
        "movl 8(%edi), %eax\n" /* line 244 */
        "movl (%eax), %edx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x170(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8977\n"
        "movl imp_dxState, %edx\n" /* line 245 */
        "movl %ebx, 0x213c(%edx)\n"
        /* } scope */
        ".Lff8708_000f899b:\n"
        "movl -0xc0(%ebp), %ecx\n" /* line 1308 | pass */
        "movl 4(%ecx), %eax\n"
        "movl -0xdc(%ebp), %ecx\n"
        "movl 8(%eax, %ecx, 4), %ebx\n" /* decl */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "cmpl 0x2140(%edx), %ebx\n" /* line 256 */
        "je .Lff8708_000f89ef\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n"
        ".Lff8708_000f89c2:\n"
        "movl 8(%edi), %eax\n" /* line 260 */
        "movl (%eax), %edx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x15c(%edx)\n"
        "movl (%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f89c2\n"
        "movl imp_dxState, %eax\n" /* line 261 */
        "movl %ebx, 0x2140(%eax)\n"
        "movl $0, 0x2144(%eax)\n" /* line 262 */
        /* } scope */
        ".Lff8708_000f89ef:\n"
        "movl -0xc0(%ebp), %ebx\n" /* line 1310 | pass, decl */
        "movzwl 0x10(%ebx), %ebx\n" /* decl */
        "movl %ebx, -0xb4(%ebp)\n" /* decl, routingCount */
        "movl -0xc0(%ebp), %eax\n" /* pass */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        "testl %ebx, %ebx\n" /* line 1131 | textureIndex */
        "jle .Lff8708_000f8c18\n"
        "movl $0, -0xb0(%ebp)\n" /* routingIndex */
        "movl imp_dx, %edx\n"
        "movl %edx, -0xf0(%ebp)\n"
        "movl imp_alwaysfails, %ecx\n"
        "movl %ecx, -0xf4(%ebp)\n"
        "movl %edx, -0xf8(%ebp)\n"
        "movl %ecx, -0xfc(%ebp)\n"
        "jmp .Lff8708_000f8aaf\n"
        ".Lff8708_000f8a43:\n"
        "movl -0x40(%ebp), %edx\n" /* line 1136 */
        "movl 4(%edx), %ebx\n" /* data */
        "movzwl 2(%edx), %ecx\n"
        "movl %ecx, -0xa4(%ebp)\n" /* destIndex */
        /* { scope 6 */
        "shll $4, %ecx\n" /* line 996 */
        "movl imp_dxState, %eax\n"
        "addl %eax, %ecx\n"
        "movl %ecx, -0x174(%ebp)\n"
        "movl $0x10, -0xe8(%ebp)\n"
        "cld\n"
        "movl %ecx, %esi\n" /* constantIndex */
        "movl %ebx, %edi\n" /* textureIndex */
        "movl $0x10, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f8a8a\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f8a8a:\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f969d\n"
        /* } scope */
        ".Lff8708_000f8a92:\n"
        "addl $8, -0x40(%ebp)\n" /* line 1158 */
        "addl $1, -0xb0(%ebp)\n" /* line 1131 | routingIndex */
        "movl -0xb0(%ebp), %eax\n" /* routingIndex */
        "cmpl %eax, -0xb4(%ebp)\n" /* routingCount */
        "je .Lff8708_000f8c18\n"
        ".Lff8708_000f8aaf:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1133 | textureIndex */
        "movzwl (%ebx), %eax\n" /* textureIndex */
        "cmpw $1, %ax\n"
        "je .Lff8708_000f91f3\n"
        "jb .Lff8708_000f8a43\n"
        "cmpw $2, %ax\n"
        "jne .Lff8708_000f8a92\n"
        "movl -0x40(%ebp), %eax\n" /* line 1145 */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* literalName */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_tess, %edx\n" /* line 971 */
        "movl 0x5a7bc(%edx), %eax\n"
        "movzwl 0x36(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f8b27\n"
        "movl 0x40(%eax), %ecx\n" /* line 973 */
        "movl -0x98(%ebp), %eax\n" /* line 974 | literalName */
        "cmpl (%ecx), %eax\n"
        "je .Lff8708_000f8b14\n"
        "leal 0x14(%ecx), %ebx\n" /* textureIndex */
        "movl %ebx, %edx\n" /* textureIndex */
        "xorl %esi, %esi\n" /* constantIndex */
        ".Lff8708_000f8afb:\n"
        "addl $1, %esi\n" /* line 971 | constantIndex */
        "cmpl %edi, %esi\n" /* constantIndex */
        "je .Lff8708_000f8b27\n"
        "movl %ebx, %ecx\n" /* textureIndex */
        "movl (%edx), %eax\n" /* line 974 */
        "leal 0x14(%ebx), %ebx\n" /* textureIndex */
        "addl $0x14, %edx\n"
        "cmpl %eax, -0x98(%ebp)\n" /* literalName */
        "jne .Lff8708_000f8afb\n"
        ".Lff8708_000f8b14:\n"
        "addl $4, %ecx\n" /* line 976 */
        "movl %ecx, -0xa8(%ebp)\n" /* data */
        "movl $1, -0xac(%ebp)\n" /* rowCount */
        /* } scope */
        /* } scope */
        ".Lff8708_000f8b27:\n"
        "movl -0x40(%ebp), %ecx\n" /* line 1146 */
        "movzwl 2(%ecx), %ecx\n"
        "movl %ecx, -0x94(%ebp)\n" /* destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 991 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f8b59\n"
        "movl -0xac(%ebp), %ecx\n" /* line 993 | rowCount */
        "testl %ecx, %ecx\n"
        "jle .Lff8708_000f8b59\n"
        "xorl %eax, %eax\n" /* line 991 */
        ".Lff8708_000f8b4e:\n"
        "addl $1, %eax\n" /* line 993 */
        "cmpl -0xac(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f8b4e\n"
        ".Lff8708_000f8b59:\n"
        "movl -0xac(%ebp), %ebx\n" /* line 996 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0x94(%ebp), %eax\n" /* destIndex */
        "shll $4, %eax\n"
        "movl imp_dxState, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x90(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %eax, %esi\n" /* constantIndex */
        "movl -0xa8(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f8b99\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f8b99:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f8a92\n"
        "movl %ebx, 8(%esp)\n" /* line 998 | textureIndex */
        "movl -0xa8(%ebp), %ecx\n" /* data */
        "movl %ecx, 4(%esp)\n"
        "movl -0x90(%ebp), %ebx\n" /* textureIndex */
        "movl %ebx, (%esp)\n" /* textureIndex */
        "calll memcpy\n"
        ".Lff8708_000f8bbd:\n"
        "movl -0xf8(%ebp), %edx\n" /* line 999 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl -0xac(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xa8(%ebp), %ebx\n" /* data, textureIndex */
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0x94(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x178(%edx)\n"
        "movl -0xfc(%ebp), %ebx\n" /* textureIndex */
        "movl (%ebx), %eax\n" /* textureIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8bbd\n"
        /* } scope */
        /* } scope */
        "addl $8, -0x40(%ebp)\n" /* line 1158 */
        "addl $1, -0xb0(%ebp)\n" /* line 1131 | routingIndex */
        "movl -0xb0(%ebp), %eax\n" /* routingIndex */
        "cmpl %eax, -0xb4(%ebp)\n" /* routingCount */
        "jne .Lff8708_000f8aaf\n"
        /* } scope */
        /* } scope */
        ".Lff8708_000f8c18:\n"
        "movl -0xc0(%ebp), %edx\n" /* line 1311 | pass */
        "movzwl 0x12(%edx), %edx\n"
        "movl %edx, -0x8c(%ebp)\n" /* routingCount */
        "movl -0xc0(%ebp), %ecx\n" /* pass */
        "movl 0x18(%ecx), %ecx\n"
        "movl %ecx, -0x88(%ebp)\n" /* routingData */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        "testl %edx, %edx\n" /* line 1173 */
        "jle .Lff8708_000f90fc\n"
        "movl $0, -0x84(%ebp)\n" /* routingIndex */
        ".Lff8708_000f8c49:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 1175 | routingData, codeConst */
        "movzwl (%ebx), %eax\n" /* codeConst */
        "cmpl $4, %eax\n"
        "ja .Lff8708_000f9357\n"
        "jmpl *.Ljt_f8708_0(, %eax, 4)\n"
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f8c62:\n"
        "movl imp_tess, %eax\n" /* line 1252 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0xbc(%ebp), %eax\n" /* ruleSetIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00226858, 4(%esp)\n" /* "No rule in stateMap '%s' rule set %i matched the current mat" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "addl $1, -0xbc(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x50(%ebp)\n"
        "cmpl $0xb, -0xbc(%ebp)\n" /* ruleSetIndex */
        "je .Lff8708_000f8885\n"
        ".Lff8708_000f8cb2:\n"
        "movl -0x50(%ebp), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jg .Lff8708_000f87ff\n"
        "jmp .Lff8708_000f8c62\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f8cc4:\n"
        "movl -0x4c(%ebp), %ebx\n" /* line 1464 | fvf */
        "cmpb $0, 0xd(%ebx)\n" /* fvf */
        "je .Lff8708_000f910d\n"
        "movl $0, (%esp)\n" /* line 1466 */
        "calll RB_SetViewMatrixForWDx7\n"
        "movl imp_backEnd, %eax\n" /* line 75 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lff8708_000f9bf2\n"
        "movl -0xe0(%ebp), %eax\n" /* line 77 */
        "movl 8(%eax), %ebx\n"
        "movl imp_r_drawPrimFloor, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n"
        "jl .Lff8708_000f8d1e\n"
        "movl imp_r_drawPrimCap, %eax\n" /* line 79 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9aa6\n"
        "cmpl %eax, %ebx\n"
        "jle .Lff8708_000f9aa6\n"
        ".Lff8708_000f8d1e:\n"
        "movl $0x3f800000, (%esp)\n" /* line 1468 */
        "calll RB_SetViewMatrixForWDx7\n"
        ".Lff8708_000f8d2a:\n"
        "addl $1, -0xd8(%ebp)\n" /* line 1459 | passIndex */
        "addl $0x5c, -0x4c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movzwl 6(%edx), %eax\n" /* techType */
        "cmpl %eax, -0xd8(%ebp)\n" /* techType, passIndex */
        "jge .Lff8708_000f9170\n"
        ".Lff8708_000f8d48:\n"
        "movl imp_tess, %esi\n" /* constantIndex */
        "movl imp_r_rendererInUse, %eax\n" /* line 1429 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lff8708_000f8777\n"
        ".Lff8708_000f8d5f:\n"
        "movl -0xd8(%ebp), %ecx\n" /* line 1431 | passIndex */
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $3, %eax\n"
        "subl %ecx, %eax\n"
        "movl -0x3c(%ebp), %ebx\n" /* fvf */
        "leal (%ebx, %eax, 4), %eax\n" /* fvf */
        "leal 8(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        "movl 0x5a7bc(%esi), %esi\n" /* line 1372 | constantIndex */
        "addl $0x2c, %esi\n" /* constantIndex */
        "movl %esi, -0xcc(%ebp)\n" /* constantIndex, refStateBits */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0xd4(%ebp)\n" /* stateMap */
        "movl $1, %edx\n"
        "movl %esi, %ecx\n" /* constantIndex */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f8d98:\n"
        "movl -4(%ecx, %edx, 4), %eax\n" /* line 1247 */
        "movl %eax, -0x2c(%ebp, %edx, 4)\n"
        "addl $1, %edx\n"
        "cmpl $3, %edx\n" /* line 1246 */
        "jne .Lff8708_000f96f3\n"
        "movl -0xd4(%ebp), %ebx\n" /* stateMap, codeConst */
        "movl %ebx, -0x54(%ebp)\n" /* codeConst */
        "movl $0, -0xd0(%ebp)\n" /* ruleSetIndex */
        "movl %ebx, %edx\n" /* codeConst */
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jle .Lff8708_000f9183\n"
        ".Lff8708_000f8dce:\n"
        "movl -0xcc(%ebp), %ecx\n" /* line 1223 | refStateBits */
        "movl (%ecx), %edi\n"
        "xorl %ecx, %ecx\n"
        "movl %eax, %edx\n"
        "jmp .Lff8708_000f8dea\n"
        ".Lff8708_000f8ddc:\n"
        "addl $1, %ecx\n" /* line 1219 */
        "addl $0x20, %edx\n"
        "cmpl %ecx, %esi\n" /* constantIndex */
        "je .Lff8708_000f9183\n"
        ".Lff8708_000f8dea:\n"
        "leal 4(%edx), %ebx\n" /* line 1221 | codeConst */
        "movl %ebx, -0x170(%ebp)\n" /* codeConst, rule */
        "movl %edi, %eax\n" /* line 1223 */
        "andl 4(%edx), %eax\n"
        "cmpl 0xc(%edx), %eax\n"
        "jne .Lff8708_000f8ddc\n"
        "movl -0xcc(%ebp), %ebx\n" /* refStateBits, codeConst */
        "movl 4(%ebx), %eax\n" /* codeConst */
        "andl 8(%edx), %eax\n"
        "cmpl 0x10(%edx), %eax\n"
        "jne .Lff8708_000f8ddc\n"
        "movl -0x170(%ebp), %ecx\n" /* rule */
        "movl $1, %ebx\n" /* codeConst */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f8e1f:\n"
        "movl -4(%edx), %eax\n" /* line 1227 */
        "andl 0x18(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "orl 0x10(%ecx), %eax\n" /* line 1228 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* codeConst */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1225 | codeConst */
        "jne .Lff8708_000f8e1f\n"
        /* } scope */
        /* } scope */
        "addl $1, -0xd0(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x54(%ebp)\n"
        "cmpl $0xb, -0xd0(%ebp)\n" /* ruleSetIndex */
        "jne .Lff8708_000f91d6\n"
        /* } scope */
        /* } scope */
        ".Lff8708_000f8e54:\n"
        "movl 8(%ebp), %eax\n" /* line 1373 | stateOverride */
        "testl %eax, %eax\n"
        "je .Lff8708_000f8e82\n"
        "movl 8(%ebp), %ecx\n" /* stateOverride */
        "movl $1, %ebx\n" /* decl */
        "leal -0x28(%ebp), %edx\n" /* stateBits */
        "addl $4, %edx\n"
        ".Lff8708_000f8e69:\n"
        "movl -4(%edx), %eax\n" /* line 1377 */
        "andl (%ecx), %eax\n"
        "orl 8(%ecx), %eax\n" /* line 1378 */
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n" /* decl */
        "addl $4, %edx\n"
        "addl $4, %ecx\n"
        "cmpl $3, %ebx\n" /* line 1375 | decl */
        "jne .Lff8708_000f8e69\n"
        ".Lff8708_000f8e82:\n"
        "movl imp_backEnd, %eax\n" /* line 1381 */
        "cmpb $0, 0x4bd(%eax)\n"
        "je .Lff8708_000f8e94\n"
        "andl $0xffffffcf, -0x24(%ebp)\n" /* line 1382 */
        ".Lff8708_000f8e94:\n"
        "movl -0x28(%ebp), %eax\n" /* line 155 | stateBits */
        "movl imp_dxState, %ebx\n"
        "cmpl 0x2000(%ebx), %eax\n"
        "je .Lff8708_000f8eb6\n"
        "movl %eax, (%esp)\n" /* line 158 */
        "calll RB_ChangeState_0\n"
        "movl -0x28(%ebp), %eax\n" /* line 160 | stateBits */
        "movl %eax, 0x2000(%ebx)\n"
        ".Lff8708_000f8eb6:\n"
        "movl -0x24(%ebp), %eax\n" /* line 163 */
        "cmpl 0x2004(%ebx), %eax\n"
        "je .Lff8708_000f8ed2\n"
        "movl %eax, (%esp)\n" /* line 166 */
        "calll RB_ChangeState_1\n"
        "movl -0x24(%ebp), %eax\n" /* line 168 */
        "movl %eax, 0x2004(%ebx)\n"
        ".Lff8708_000f8ed2:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 1392 */
        "cmpb $1, 8(%ecx)\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_UpdateFogColor\n"
        "movl %ebx, %edx\n" /* line 1395 | decl */
        "movzbl 0x2094(%ebx), %eax\n" /* decl */
        "movl -0x48(%ebp), %ebx\n" /* decl */
        "cmpb 4(%ebx), %al\n" /* decl */
        "je .Lff8708_000f8f45\n"
        "movl imp_dx, %esi\n" /* constantIndex */
        "movl imp_alwaysfails, %ebx\n" /* decl */
        ".Lff8708_000f8f05:\n"
        "movl 8(%esi), %eax\n" /* line 1397 | constantIndex */
        "movl (%eax), %ecx\n"
        "movl -0x48(%ebp), %edx\n"
        "cmpb $0, 4(%edx)\n"
        "setne %dl\n"
        "movzbl %dl, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0x89, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xe4(%ecx)\n"
        "movl (%ebx), %edi\n" /* decl */
        "testl %edi, %edi\n"
        "jne .Lff8708_000f8f05\n"
        "movl imp_dxState, %edx\n" /* line 1398 */
        "movl -0x48(%ebp), %ecx\n"
        "movzbl 4(%ecx), %eax\n"
        "movb %al, 0x2094(%edx)\n"
        ".Lff8708_000f8f45:\n"
        "movl -0xdc(%ebp), %eax\n" /* line 1402 */
        "movl s_fvfForVertDeclType(, %eax, 4), %ebx\n" /* fvf */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "movl 0x2140(%edx), %ecx\n" /* line 272 */
        "testl %ecx, %ecx\n"
        "je .Lff8708_000f9805\n"
        ".Lff8708_000f8f60:\n"
        "movl imp_dx, %eax\n" /* line 275 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n" /* to */
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x164(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f8f60\n"
        "movl imp_dxState, %eax\n" /* line 276 */
        "movl %ebx, 0x2144(%eax)\n"
        "movl $0, 0x2140(%eax)\n" /* line 277 */
        /* } scope */
        "movl -0x48(%ebp), %edx\n" /* line 1404 */
        "cmpb $0, 7(%edx)\n"
        "jne .Lff8708_000f981e\n"
        ".Lff8708_000f8fa4:\n"
        "movl $0xffffffff, %ecx\n"
        ".Lff8708_000f8fa9:\n"
        "movl %ecx, (%esp)\n" /* line 1409 */
        "calll RB_SetSamplerConstantDx7\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl $0, -0xc4(%ebp)\n" /* samplerIndex */
        "movl imp_dxState, %edx\n"
        "movl %edx, -0x58(%ebp)\n"
        "movl %eax, -0x100(%ebp)\n"
        "movl %eax, %ecx\n"
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpw $3, 0xc(%ecx)\n" /* line 1321 */
        "je .Lff8708_000f9747\n"
        ".Lff8708_000f8fdd:\n"
        "movl 0x10(%ecx), %eax\n" /* line 1328 */
        "movl %eax, -0xc8(%ebp)\n" /* textureName */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        "movl imp_tess, %eax\n" /* line 671 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movzwl 0x34(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f9795\n"
        "movl 0x3c(%eax), %esi\n" /* line 673 */
        "movl -0xc8(%ebp), %ebx\n" /* line 674 | textureName, textureIndex */
        "cmpl (%esi), %ebx\n" /* textureIndex */
        "je .Lff8708_000f902e\n"
        "leal 0xc(%esi), %ecx\n"
        "movl %ecx, %edx\n"
        "xorl %ebx, %ebx\n" /* textureIndex */
        ".Lff8708_000f9011:\n"
        "addl $1, %ebx\n" /* line 671 | textureIndex */
        "cmpl %edi, %ebx\n" /* textureIndex */
        "je .Lff8708_000f9795\n"
        "movl %ecx, %esi\n"
        "movl (%edx), %eax\n" /* line 674 */
        "leal 0xc(%ecx), %ecx\n"
        "addl $0xc, %edx\n"
        "cmpl %eax, -0xc8(%ebp)\n" /* textureName */
        "jne .Lff8708_000f9011\n"
        ".Lff8708_000f902e:\n"
        "cmpb $5, 5(%esi)\n" /* line 676 */
        "je .Lff8708_000f9b3a\n"
        "movl 8(%esi), %edx\n" /* line 679 */
        "movl %edx, -0x20(%ebp)\n" /* image */
        ".Lff8708_000f903e:\n"
        "movzbl 4(%esi), %eax\n" /* line 680 */
        "movb %al, -0x19(%ebp)\n" /* samplerState */
        /* { scope 6 */
        "cmpl $3, (%edx)\n" /* line 482 */
        "je .Lff8708_000f975d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f904e:\n"
        "movl %edx, 8(%esp)\n" /* line 1330 */
        "movzbl -0x19(%ebp), %eax\n" /* samplerState */
        "movl %eax, 4(%esp)\n"
        "movl -0xc4(%ebp), %eax\n" /* samplerIndex */
        "movl %eax, (%esp)\n"
        "calll RB_SetSampler\n"
        "movl -0x5c(%ebp), %edx\n"
        "movzbl 9(%edx), %eax\n"
        /* } scope */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "movl -0x58(%ebp), %ecx\n" /* line 176 */
        "cmpb 0x2095(%ecx), %al\n"
        "jne .Lff8708_000f96fe\n"
        "cmpb $2, %al\n"
        "je .Lff8708_000f96fe\n"
        /* } scope */
        "addl $1, -0xc4(%ebp)\n" /* line 1411 | samplerIndex */
        "addl $8, -0x100(%ebp)\n"
        "addl $1, -0x5c(%ebp)\n"
        "addl $1, -0x58(%ebp)\n"
        "cmpl $2, -0xc4(%ebp)\n" /* samplerIndex */
        "jne .Lff8708_000f9736\n"
        ".Lff8708_000f90a9:\n"
        "movl -0x48(%ebp), %ebx\n" /* fvf */
        "xorl %edi, %edi\n"
        "movl imp_dxState, %esi\n" /* constantIndex */
        ".Lff8708_000f90b4:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 1419 | fvf, texStageBits */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpl 0x2014(%esi), %eax\n" /* line 187 */
        "je .Lff8708_000f90d1\n"
        "movl %eax, 0x2014(%esi)\n" /* line 189 */
        "movl %eax, 4(%esp)\n" /* line 191 */
        "movl %edi, (%esp)\n"
        "calll RB_ChangeColorStageState\n"
        /* } scope */
        ".Lff8708_000f90d1:\n"
        "movl 0x3c(%ebx), %eax\n" /* line 1420 | fvf, texStageBits */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpl 0x2034(%esi), %eax\n" /* line 199 */
        "je .Lff8708_000f90ee\n"
        "movl %eax, 0x2034(%esi)\n" /* line 201 */
        "movl %eax, 4(%esp)\n" /* line 203 */
        "movl %edi, (%esp)\n"
        "calll RB_ChangeAlphaStageState\n"
        /* } scope */
        ".Lff8708_000f90ee:\n"
        "addl $1, %edi\n" /* line 1417 */
        "addl $4, %ebx\n" /* fvf */
        "addl $4, %esi\n" /* constantIndex */
        "cmpl $8, %edi\n"
        "jne .Lff8708_000f90b4\n"
        /* } scope */
        ".Lff8708_000f90fc:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1464 | techType */
        "movl (%eax), %eax\n" /* techType */
        "cmpl $2, 8(%eax)\n" /* techType */
        "je .Lff8708_000f8cc4\n"
        ".Lff8708_000f910d:\n"
        "movl imp_backEnd, %eax\n" /* line 75 */
        "cmpb $0, 0x4bd(%eax)\n"
        "jne .Lff8708_000f97c2\n"
        "movl -0xe0(%ebp), %eax\n" /* line 77 */
        "movl 8(%eax), %ebx\n"
        "movl imp_r_drawPrimFloor, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %ebx\n"
        "jl .Lff8708_000f8d2a\n"
        "movl imp_r_drawPrimCap, %eax\n" /* line 79 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9385\n"
        "cmpl %eax, %ebx\n"
        "jle .Lff8708_000f9385\n"
        "addl $1, -0xd8(%ebp)\n" /* line 1459 | passIndex */
        "addl $0x5c, -0x4c(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movzwl 6(%edx), %eax\n" /* techType */
        "cmpl %eax, -0xd8(%ebp)\n" /* techType, passIndex */
        "jl .Lff8708_000f8d48\n"
        ".Lff8708_000f9170:\n"
        "movl imp_g_special, %eax\n" /* techType */
        ".Lff8708_000f9175:\n"
        "movb $0, (%eax)\n" /* line 1474 | techType */
        /* } scope */
        "addl $0x18c, %esp\n" /* line 1477 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pass, stateBits */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        ".Lff8708_000f9183:\n"
        "movl imp_tess, %eax\n" /* line 1252 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0xd0(%ebp), %eax\n" /* ruleSetIndex */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd4(%ebp), %edx\n" /* stateMap */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00226858, 4(%esp)\n" /* "No rule in stateMap '%s' rule set %i matched the current mat" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "addl $1, -0xd0(%ebp)\n" /* line 1249 | ruleSetIndex */
        "addl $4, -0x54(%ebp)\n"
        "cmpl $0xb, -0xd0(%ebp)\n" /* ruleSetIndex */
        "je .Lff8708_000f8e54\n"
        ".Lff8708_000f91d6:\n"
        "movl -0x54(%ebp), %edx\n"
        "movl 4(%edx), %eax\n" /* line 1251 | ruleSet */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        "movl (%eax), %esi\n" /* line 1219 | constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jg .Lff8708_000f8dce\n"
        "jmp .Lff8708_000f9183\n"
        ".Lff8708_000f91e8:\n"
        "movl -0xb8(%ebp), %ebx\n" /* refStateBits, codeConst */
        "jmp .Lff8708_000f87cc\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f91f3:\n"
        "addl $4, %ebx\n" /* line 1140 | codeConst */
        /* { scope 6 */
        "movl -0x40(%ebp), %edx\n" /* line 953 */
        "movzwl 4(%edx), %eax\n"
        "cmpw $0xba, %ax\n"
        "ja .Lff8708_000f979d\n"
        "movzwl %ax, %eax\n" /* line 292 */
        "shll $4, %eax\n"
        "subl $0x800, %eax\n"
        "movl imp_backEnd, %ecx\n"
        "addl %ecx, %eax\n"
        "movl %eax, -0xa8(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 956 | textureIndex */
        "movl %ebx, -0xac(%ebp)\n" /* textureIndex, rowCount */
        /* } scope */
        ".Lff8708_000f922a:\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1141 | codeConst */
        "movzwl 2(%ebx), %ebx\n" /* codeConst */
        "movl %ebx, -0xa0(%ebp)\n" /* codeConst, destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 991 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f925c\n"
        "movl -0xac(%ebp), %edx\n" /* line 993 | rowCount */
        "testl %edx, %edx\n"
        "jle .Lff8708_000f925c\n"
        "xorl %eax, %eax\n" /* line 991 */
        ".Lff8708_000f9251:\n"
        "addl $1, %eax\n" /* line 993 */
        "cmpl -0xac(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f9251\n"
        ".Lff8708_000f925c:\n"
        "movl -0xac(%ebp), %ebx\n" /* line 996 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0xa0(%ebp), %eax\n" /* destIndex */
        "shll $4, %eax\n"
        "movl imp_dxState, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %eax, %esi\n" /* constantIndex */
        "movl -0xa8(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f929c\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f929c:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f8a92\n"
        "movl %ebx, 8(%esp)\n" /* line 998 | textureIndex */
        "movl -0xa8(%ebp), %ecx\n" /* data */
        "movl %ecx, 4(%esp)\n"
        "movl -0x9c(%ebp), %ebx\n" /* textureIndex */
        "movl %ebx, (%esp)\n" /* textureIndex */
        "calll memcpy\n"
        ".Lff8708_000f92c0:\n"
        "movl -0xf0(%ebp), %edx\n" /* line 999 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl -0xac(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0xa8(%ebp), %ebx\n" /* data, textureIndex */
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0xa0(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x178(%edx)\n"
        "movl -0xf4(%ebp), %ebx\n" /* textureIndex */
        "movl (%ebx), %eax\n" /* textureIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f92c0\n"
        "jmp .Lff8708_000f8a92\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f9303:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1178 | routingData */
        "movl 4(%eax), %ebx\n" /* data */
        "movzwl 2(%eax), %edx\n"
        "movl %edx, -0x78(%ebp)\n" /* destIndex */
        /* { scope 6 */
        "shll $4, %edx\n" /* line 1065 */
        "movl imp_dxState, %eax\n"
        "leal 0x1000(%edx, %eax), %edx\n"
        "movl %edx, -0x174(%ebp)\n"
        "movl $0x10, -0xec(%ebp)\n"
        "cld\n"
        "movl %edx, %esi\n" /* constantIndex */
        "movl %ebx, %edi\n" /* textureIndex */
        "movl $0x10, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f934f\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f934f:\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f9a49\n"
        /* } scope */
        ".Lff8708_000f9357:\n"
        "addl $8, -0x88(%ebp)\n" /* line 1205 | routingData */
        "addl $1, -0x84(%ebp)\n" /* line 1173 | routingIndex */
        "movl -0x84(%ebp), %ecx\n" /* routingIndex */
        "cmpl %ecx, -0x8c(%ebp)\n" /* routingCount */
        "jne .Lff8708_000f8c49\n"
        "jmp .Lff8708_000f90fc\n"
        ".Lff8708_000f937c:\n"
        "movl -0xe0(%ebp), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* codeConst */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f9385:\n"
        "movl imp_dx, %eax\n" /* line 98 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x148(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f937c\n"
        "jmp .Lff8708_000f8d2a\n"
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f93d5:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 1182 | routingData, codeConst */
        "addl $4, %ebx\n" /* codeConst */
        /* { scope 6 */
        "movl -0x88(%ebp), %edx\n" /* line 953 | routingData */
        "movzwl 4(%edx), %eax\n"
        "cmpw $0xba, %ax\n"
        "ja .Lff8708_000f9a2a\n"
        "movzwl %ax, %eax\n" /* line 292 */
        "shll $4, %eax\n"
        "movl imp_backEnd, %edx\n"
        "leal -0x800(%eax, %edx), %eax\n"
        "movl %eax, -0x7c(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 956 | textureIndex */
        "movl %ebx, -0x80(%ebp)\n" /* textureIndex, rowCount */
        /* } scope */
        ".Lff8708_000f940f:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1183 | routingData */
        "movzwl 2(%eax), %eax\n"
        "movl %eax, -0x74(%ebp)\n" /* destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 1060 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lff8708_000f943b\n"
        "movl -0x80(%ebp), %ebx\n" /* line 1062 | rowCount, textureIndex */
        "testl %ebx, %ebx\n" /* textureIndex */
        "jle .Lff8708_000f943b\n"
        "xorl %eax, %eax\n" /* line 1060 */
        ".Lff8708_000f9433:\n"
        "addl $1, %eax\n" /* line 1062 */
        "cmpl -0x80(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f9433\n"
        ".Lff8708_000f943b:\n"
        "movl -0x80(%ebp), %ebx\n" /* line 1065 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0x74(%ebp), %edx\n" /* destIndex */
        "shll $4, %edx\n"
        "movl imp_dxState, %eax\n"
        "leal 0x1000(%edx, %eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %edx, %esi\n" /* constantIndex */
        "movl -0x7c(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f9473\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f9473:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9357\n"
        "movl %ebx, 8(%esp)\n" /* line 1067 | textureIndex */
        "movl -0x7c(%ebp), %edx\n" /* data */
        "movl %edx, 4(%esp)\n"
        "movl -0x70(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl imp_dx, %esi\n" /* constantIndex */
        "movl imp_alwaysfails, %ebx\n" /* textureIndex */
        ".Lff8708_000f949d:\n"
        "movl 8(%esi), %eax\n" /* line 1068 | constantIndex */
        "movl (%eax), %edx\n"
        "movl -0x80(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %ecx\n" /* data */
        "movl %ecx, 8(%esp)\n"
        "movl -0x74(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1b4(%edx)\n"
        "movl (%ebx), %edx\n" /* textureIndex */
        "testl %edx, %edx\n"
        "jne .Lff8708_000f949d\n"
        "jmp .Lff8708_000f9357\n"
        /* } scope */
        /* } scope */
        ".Lff8708_000f94cb:\n"
        "leal -0x19(%ebp), %ecx\n" /* line 1192 | samplerState */
        "leal -0x20(%ebp), %edx\n" /* image */
        "movl -0x88(%ebp), %ebx\n" /* routingData, codeConst */
        "movl 4(%ebx), %eax\n" /* codeConst */
        "calll RB_GetTextureFromCode\n"
        "movl -0x20(%ebp), %eax\n" /* line 1193 | image */
        "movl %eax, 8(%esp)\n"
        "movzbl -0x19(%ebp), %eax\n" /* samplerState */
        "movl %eax, 4(%esp)\n"
        "movzwl 2(%ebx), %eax\n" /* codeConst */
        "movl %eax, (%esp)\n"
        "calll RB_SetSampler\n"
        "jmp .Lff8708_000f9357\n"
        ".Lff8708_000f94ff:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1197 | routingData */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* textureName */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_tess, %eax\n" /* line 671 */
        "movl 0x5a7bc(%eax), %eax\n"
        "movzwl 0x34(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f97fd\n"
        "movl 0x3c(%eax), %esi\n" /* line 673 */
        "movl -0x60(%ebp), %ecx\n" /* line 674 | textureName */
        "cmpl (%esi), %ecx\n"
        "je .Lff8708_000f954d\n"
        "leal 0xc(%esi), %ecx\n"
        "movl %ecx, %edx\n"
        "xorl %ebx, %ebx\n" /* textureIndex */
        ".Lff8708_000f9533:\n"
        "addl $1, %ebx\n" /* line 671 | textureIndex */
        "cmpl %edi, %ebx\n" /* textureIndex */
        "je .Lff8708_000f97fd\n"
        "movl %ecx, %esi\n"
        "movl (%edx), %eax\n" /* line 674 */
        "leal 0xc(%ecx), %ecx\n"
        "addl $0xc, %edx\n"
        "cmpl %eax, -0x60(%ebp)\n" /* textureName */
        "jne .Lff8708_000f9533\n"
        ".Lff8708_000f954d:\n"
        "cmpb $5, 5(%esi)\n" /* line 676 */
        "je .Lff8708_000f9be1\n"
        "movl 8(%esi), %edx\n" /* line 679 */
        "movl %edx, -0x20(%ebp)\n" /* image */
        ".Lff8708_000f955d:\n"
        "movzbl 4(%esi), %eax\n" /* line 680 */
        "movb %al, -0x19(%ebp)\n" /* samplerState */
        /* { scope 8 */
        "cmpl $3, (%edx)\n" /* line 482 */
        "je .Lff8708_000f9b8c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f956d:\n"
        "movl %edx, 8(%esp)\n" /* line 1198 */
        "movzbl -0x19(%ebp), %eax\n" /* samplerState */
        "movl %eax, 4(%esp)\n"
        "movl -0x88(%ebp), %edx\n" /* routingData */
        "movzwl 2(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetSampler\n"
        "jmp .Lff8708_000f9357\n"
        ".Lff8708_000f9590:\n"
        "movl -0x88(%ebp), %ebx\n" /* line 1187 | routingData, codeConst */
        "movl 4(%ebx), %ebx\n" /* codeConst */
        "movl %ebx, -0x6c(%ebp)\n" /* codeConst, literalName */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_tess, %esi\n" /* line 971 | constantIndex */
        "movl 0x5a7bc(%esi), %eax\n" /* constantIndex */
        "movzwl 0x36(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jle .Lff8708_000f95e1\n"
        "movl 0x40(%eax), %ecx\n" /* line 973 */
        "cmpl (%ecx), %ebx\n" /* line 974 | textureIndex */
        "je .Lff8708_000f95d4\n"
        "leal 0x14(%ecx), %ebx\n" /* textureIndex */
        "movl %ebx, %edx\n" /* textureIndex */
        "xorl %esi, %esi\n" /* constantIndex */
        ".Lff8708_000f95be:\n"
        "addl $1, %esi\n" /* line 971 | constantIndex */
        "cmpl %edi, %esi\n" /* constantIndex */
        "je .Lff8708_000f95e1\n"
        "movl %ebx, %ecx\n" /* textureIndex */
        "movl (%edx), %eax\n" /* line 974 */
        "leal 0x14(%ebx), %ebx\n" /* textureIndex */
        "addl $0x14, %edx\n"
        "cmpl %eax, -0x6c(%ebp)\n" /* literalName */
        "jne .Lff8708_000f95be\n"
        ".Lff8708_000f95d4:\n"
        "addl $4, %ecx\n" /* line 976 */
        "movl %ecx, -0x7c(%ebp)\n" /* data */
        "movl $1, -0x80(%ebp)\n" /* rowCount */
        /* } scope */
        /* } scope */
        ".Lff8708_000f95e1:\n"
        "movl -0x88(%ebp), %eax\n" /* line 1188 | routingData */
        "movzwl 2(%eax), %eax\n"
        "movl %eax, -0x68(%ebp)\n" /* destIndex */
        /* { scope 6 */
        /* { scope 7 */
        "movl imp_r_logFile, %eax\n" /* line 1060 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f960d\n"
        "movl -0x80(%ebp), %esi\n" /* line 1062 | rowCount, constantIndex */
        "testl %esi, %esi\n" /* constantIndex */
        "jle .Lff8708_000f960d\n"
        "xorl %eax, %eax\n" /* line 1060 */
        ".Lff8708_000f9605:\n"
        "addl $1, %eax\n" /* line 1062 */
        "cmpl -0x80(%ebp), %eax\n" /* rowCount */
        "jne .Lff8708_000f9605\n"
        ".Lff8708_000f960d:\n"
        "movl -0x80(%ebp), %ebx\n" /* line 1065 | rowCount, textureIndex */
        "shll $4, %ebx\n" /* textureIndex */
        "movl -0x68(%ebp), %edx\n" /* destIndex */
        "shll $4, %edx\n"
        "movl imp_dxState, %eax\n"
        "leal 0x1000(%edx, %eax), %edx\n"
        "movl %edx, -0x64(%ebp)\n"
        "cld\n"
        "cmpl %ebx, %ebx\n" /* textureIndex */
        "movl %edx, %esi\n" /* constantIndex */
        "movl -0x7c(%ebp), %edi\n" /* data */
        "movl %ebx, %ecx\n" /* textureIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* constantIndex */
        "movl $0, %eax\n"
        "je .Lff8708_000f9645\n"
        "movzbl -1(%esi), %eax\n" /* constantIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lff8708_000f9645:\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f9357\n"
        "movl %ebx, 8(%esp)\n" /* line 1067 | textureIndex */
        "movl -0x7c(%ebp), %edx\n" /* data */
        "movl %edx, 4(%esp)\n"
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl imp_dx, %esi\n" /* constantIndex */
        "movl imp_alwaysfails, %ebx\n" /* textureIndex */
        ".Lff8708_000f966f:\n"
        "movl 8(%esi), %eax\n" /* line 1068 | constantIndex */
        "movl (%eax), %edx\n"
        "movl -0x80(%ebp), %ecx\n" /* rowCount */
        "movl %ecx, 0xc(%esp)\n"
        "movl -0x7c(%ebp), %ecx\n" /* data */
        "movl %ecx, 8(%esp)\n"
        "movl -0x68(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1b4(%edx)\n"
        "movl (%ebx), %eax\n" /* textureIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f966f\n"
        "jmp .Lff8708_000f9357\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f969d:\n"
        "movl (%ebx), %eax\n" /* line 998 | textureIndex */
        "movl -0x174(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 0xc(%edx)\n"
        ".Lff8708_000f96b9:\n"
        "movl imp_dx, %ecx\n" /* line 999 */
        "movl 8(%ecx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0xa4(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x178(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f96b9\n"
        "jmp .Lff8708_000f8a92\n"
        ".Lff8708_000f96f3:\n"
        "movl -0xcc(%ebp), %ecx\n" /* refStateBits */
        "jmp .Lff8708_000f8d98\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f96fe:\n"
        "movzbl %al, %eax\n" /* line 179 */
        "movl %eax, 4(%esp)\n"
        "movl -0xc4(%ebp), %ebx\n" /* samplerIndex */
        "movl %ebx, (%esp)\n"
        "calll RB_ChangeGenTexCoords\n"
        /* } scope */
        "addl $1, -0xc4(%ebp)\n" /* line 1411 | samplerIndex */
        "addl $8, -0x100(%ebp)\n"
        "addl $1, -0x5c(%ebp)\n"
        "addl $1, -0x58(%ebp)\n"
        "cmpl $2, -0xc4(%ebp)\n" /* samplerIndex */
        "je .Lff8708_000f90a9\n"
        ".Lff8708_000f9736:\n"
        "movl -0x100(%ebp), %ecx\n"
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        "cmpw $3, 0xc(%ecx)\n" /* line 1321 */
        "jne .Lff8708_000f8fdd\n"
        ".Lff8708_000f9747:\n"
        "movl 0x10(%ecx), %eax\n" /* line 1323 */
        "leal -0x19(%ebp), %ecx\n" /* samplerState */
        "leal -0x20(%ebp), %edx\n" /* image */
        "calll RB_GetTextureFromCode\n"
        "movl -0x20(%ebp), %edx\n" /* image */
        "jmp .Lff8708_000f904e\n"
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f975d:\n"
        "movzbl 5(%esi), %eax\n" /* line 486 */
        "cmpb $3, %al\n"
        "je .Lff8708_000f9c6b\n"
        "jbe .Lff8708_000f9c00\n"
        "cmpb $4, %al\n"
        "je .Lff8708_000f9c94\n"
        "cmpb $5, %al\n"
        "jne .Lff8708_000f904e\n"
        "movl 8(%esi), %eax\n" /* line 508 */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RB_UploadWaterTexture\n"
        "movb $6, -0x19(%ebp)\n" /* line 509 | samplerState */
        ".Lff8708_000f9795:\n"
        "movl -0x20(%ebp), %edx\n" /* image */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f979d:\n"
        "movzbl 3(%ebx), %ecx\n" /* line 960 | textureIndex */
        "movzbl 2(%ebx), %edx\n" /* textureIndex */
        "movzwl %ax, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl %eax, -0xa8(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 961 | textureIndex */
        "movl %ebx, -0xac(%ebp)\n" /* textureIndex, rowCount */
        "jmp .Lff8708_000f922a\n"
        ".Lff8708_000f97c2:\n"
        "movl -0xe0(%ebp), %edx\n"
        "movl 8(%edx), %ebx\n" /* textureIndex */
        "jmp .Lff8708_000f9385\n"
        ".Lff8708_000f97d0:\n"
        "movl %esi, %edx\n" /* texdef */
        "jmp .Lff8708_000f8957\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f97d7:\n"
        "cmpb $4, %al\n" /* line 486 */
        "je .Lff8708_000f9ccc\n"
        "cmpb $5, %al\n"
        "jne .Lff8708_000f956d\n"
        "movl 8(%esi), %eax\n" /* line 508 */
        "movl 0x1c(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll RB_UploadWaterTexture\n"
        "movb $6, -0x19(%ebp)\n" /* line 509 | samplerState */
        ".Lff8708_000f97fd:\n"
        "movl -0x20(%ebp), %edx\n" /* image */
        "jmp .Lff8708_000f956d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f9805:\n"
        "cmpl 0x2144(%edx), %ebx\n" /* line 272 */
        "jne .Lff8708_000f8f60\n"
        /* } scope */
        "movl -0x48(%ebp), %edx\n" /* line 1404 */
        "cmpb $0, 7(%edx)\n"
        "je .Lff8708_000f8fa4\n"
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f981e:\n"
        "movl imp_backEnd, %eax\n" /* line 1346 */
        "movss 0x3bc(%eax), %xmm0\n"
        "movl imp_r_objectiveColorDx7Min, %eax\n" /* line 1348 */
        "movl (%eax), %eax\n"
        "leal 8(%eax), %edx\n" /* from */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        "movzbl 8(%eax), %eax\n" /* line 705 */
        "cvtsi2ssl %eax, %xmm3\n"
        "movss lit4_002ed5cc, %xmm5\n" /* 0.003921568859368563f */
        "mulss %xmm5, %xmm3\n"
        "movzbl 1(%edx), %eax\n" /* line 706 */
        "cvtsi2ssl %eax, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "movzbl 2(%edx), %eax\n" /* line 707 */
        "cvtsi2ssl %eax, %xmm6\n"
        "mulss %xmm5, %xmm6\n"
        "movzbl 3(%edx), %eax\n" /* line 708 */
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        /* } scope */
        "movl imp_r_objectiveColorDx7Max, %eax\n" /* line 1349 */
        "movl (%eax), %ebx\n" /* decl */
        "leal 8(%ebx), %esi\n" /* decl, constantIndex */
        "movss %xmm0, (%esp)\n" /* line 1347 */
        "movss %xmm0, -0x118(%ebp)\n"
        "movss %xmm1, -0x128(%ebp)\n"
        "movss %xmm3, -0x138(%ebp)\n"
        "movss %xmm4, -0x148(%ebp)\n"
        "movss %xmm5, -0x158(%ebp)\n"
        "movss %xmm6, -0x168(%ebp)\n"
        "calll floorf\n"
        "fstps -0xe4(%ebp)\n"
        "movss -0x118(%ebp), %xmm0\n"
        "subss -0xe4(%ebp), %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x16c(%ebp)\n"
        "movss -0x16c(%ebp), %xmm2\n"
        "mulss lit4_002ed63c, %xmm2\n" /* -0.5f */
        "addss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "movzbl 3(%esi), %eax\n" /* line 1354 | constantIndex */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x158(%ebp), %xmm5\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x128(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss lit4_002ed5d4, %xmm7\n" /* 255.0f */
        "mulss %xmm7, %xmm1\n"
        "fnstcw -0x2a(%ebp)\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x2c(%ebp)\n"
        "movss %xmm1, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, %ecx\n"
        "shll $0x18, %ecx\n"
        "movzbl 8(%ebx), %eax\n" /* decl */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x138(%ebp), %xmm3\n"
        "subss %xmm3, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm3\n"
        "mulss %xmm7, %xmm3\n"
        "movss %xmm3, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "shll $0x10, %eax\n"
        "orl %eax, %ecx\n"
        "movzbl 1(%esi), %eax\n" /* constantIndex */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x148(%ebp), %xmm4\n"
        "subss %xmm4, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss %xmm7, %xmm4\n"
        "movss %xmm4, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "shll $8, %eax\n"
        "orl %eax, %ecx\n"
        "movzbl 2(%esi), %eax\n" /* constantIndex */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "movss -0x168(%ebp), %xmm6\n"
        "subss %xmm6, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "addss %xmm2, %xmm6\n"
        "mulss %xmm7, %xmm6\n"
        "movss %xmm6, -0x16c(%ebp)\n"
        "flds -0x16c(%ebp)\n"
        "fldcw -0x2c(%ebp)\n"
        "fistpll -0x38(%ebp)\n"
        "fldcw -0x2a(%ebp)\n"
        "movl -0x38(%ebp), %eax\n"
        "orl %eax, %ecx\n"
        "jmp .Lff8708_000f8fa9\n"
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9a2a:\n"
        "movzbl 3(%ebx), %ecx\n" /* line 960 | textureIndex */
        "movzbl 2(%ebx), %edx\n" /* textureIndex */
        "movzwl %ax, %eax\n"
        "calll RB_GetCodeMatrix\n"
        "movl %eax, -0x7c(%ebp)\n" /* data */
        "movzbl 3(%ebx), %ebx\n" /* line 961 | textureIndex */
        "movl %ebx, -0x80(%ebp)\n" /* textureIndex, rowCount */
        "jmp .Lff8708_000f940f\n"
        /* } scope */
        /* { scope 6 */
        ".Lff8708_000f9a49:\n"
        "movl (%ebx), %eax\n" /* line 1067 | textureIndex */
        "movl -0x174(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n" /* textureIndex */
        "movl %eax, 0xc(%edx)\n"
        "movl imp_dx, %edi\n"
        "movl imp_alwaysfails, %esi\n" /* constantIndex */
        ".Lff8708_000f9a71:\n"
        "movl 8(%edi), %eax\n" /* line 1068 */
        "movl (%eax), %edx\n"
        "movl $1, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* textureIndex */
        "movl -0x78(%ebp), %ecx\n" /* destIndex */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x1b4(%edx)\n"
        "movl (%esi), %eax\n" /* constantIndex */
        "testl %eax, %eax\n"
        "jne .Lff8708_000f9a71\n"
        "jmp .Lff8708_000f9357\n"
        ".Lff8708_000f9a9d:\n"
        "movl -0xe0(%ebp), %ecx\n"
        "movl 8(%ecx), %ebx\n" /* textureIndex */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f9aa6:\n"
        "movl imp_dx, %eax\n" /* line 98 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl -0xe0(%ebp), %ebx\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x148(%ecx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff8708_000f9a9d\n"
        "movl $0x3f800000, (%esp)\n" /* line 1468 */
        "calll RB_SetViewMatrixForWDx7\n"
        "jmp .Lff8708_000f8d2a\n"
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        ".Lff8708_000f9b02:\n"
        "movl 0x5a7bc(%esi), %eax\n" /* line 1276 | constantIndex */
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl $str_002268b4, 4(%esp)\n" /* "Vertex type %i doesn't have the information used by shader %" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "movl imp_tess, %esi\n" /* constantIndex */
        "jmp .Lff8708_000f87b0\n"
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        ".Lff8708_000f9b3a:\n"
        "movl 8(%esi), %eax\n" /* line 677 */
        "movl 0x1c(%eax), %eax\n"
        "movl 0x40(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "jmp .Lff8708_000f903e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff8708_000f9b4b:\n"
        "movl imp_r_debugShader, %eax\n" /* line 1451 | techType */
        "movl (%eax), %eax\n" /* techType */
        "movl 8(%eax), %eax\n" /* techType */
        "shll $4, %eax\n" /* techType */
        "leal debugShaderConsts(%eax), %ecx\n" /* techType */
        "movl imp_backEnd, %edx\n" /* line 275 | to */
        "addl $0x1a0, %edx\n" /* to */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        "movl debugShaderConsts(%eax), %eax\n" /* line 456 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x3c(%ebp), %edx\n"
        "jmp .Lff8708_000f873f\n"
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9b8c:\n"
        "movzbl 5(%esi), %eax\n" /* line 486 */
        "cmpb $3, %al\n"
        "je .Lff8708_000f9c43\n"
        "ja .Lff8708_000f97d7\n"
        "cmpb $2, %al\n"
        "jne .Lff8708_000f956d\n"
        "movl imp_r_colorMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f956d\n"
        ".Lff8708_000f9bb8:\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff8708_000f9d13\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff8708_000f956d\n"
        "movl imp_rgp, %eax\n" /* line 464 */
        "movl 0x100c(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 465 | samplerState */
        "jmp .Lff8708_000f956d\n"
        /* } scope */
        ".Lff8708_000f9be1:\n"
        "movl 8(%esi), %eax\n" /* line 677 */
        "movl 0x1c(%eax), %eax\n"
        "movl 0x40(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "jmp .Lff8708_000f955d\n"
        ".Lff8708_000f9bf2:\n"
        "movl -0xe0(%ebp), %edx\n"
        "movl 8(%edx), %ebx\n" /* textureIndex */
        "jmp .Lff8708_000f9aa6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9c00:\n"
        "cmpb $2, %al\n" /* line 486 */
        "jne .Lff8708_000f904e\n"
        "movl imp_r_colorMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f904e\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff8708_000f9ce3\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff8708_000f904e\n"
        "movl imp_rgp, %eax\n" /* line 464 */
        "movl 0x100c(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 465 | samplerState */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9c43:\n"
        "movl imp_r_normalMap, %eax\n" /* line 497 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jne .Lff8708_000f956d\n"
        "movl imp_rgp, %eax\n" /* line 499 */
        "movl 0x1010(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 500 | samplerState */
        "jmp .Lff8708_000f956d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9c6b:\n"
        "movl imp_r_normalMap, %eax\n" /* line 497 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "jne .Lff8708_000f904e\n"
        "movl imp_rgp, %ebx\n" /* line 499 */
        "movl 0x1010(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 500 | samplerState */
        "jmp .Lff8708_000f904e\n"
        ".Lff8708_000f9c94:\n"
        "movl imp_r_specularMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f904e\n"
        "cmpl $1, %eax\n" /* line 455 */
        "je .Lff8708_000f9cfb\n"
        "cmpl $2, %eax\n" /* line 462 */
        "jne .Lff8708_000f904e\n"
        "movl imp_rgp, %ecx\n" /* line 464 */
        "movl 0x100c(%ecx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 465 | samplerState */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9ccc:\n"
        "movl imp_r_specularMap, %eax\n" /* line 452 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lff8708_000f956d\n"
        "jmp .Lff8708_000f9bb8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        ".Lff8708_000f9ce3:\n"
        "movl imp_rgp, %ecx\n" /* line 457 */
        "movl 0x1008(%ecx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 458 | samplerState */
        "jmp .Lff8708_000f904e\n"
        ".Lff8708_000f9cfb:\n"
        "movl imp_rgp, %ebx\n" /* line 457 */
        "movl 0x1008(%ebx), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 458 | samplerState */
        "jmp .Lff8708_000f904e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: stateBits, stateMap, image, samplerState, ... */
        /* { scope 3: ruleSetIndex, routingCount, routingCount, routingData, ... */
        /* { scope 4: refStateBits, routingIndex, rowCount, data, ... */
        /* { scope 5: destIndex, literalName, destIndex, rule, ... */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lff8708_000f9d13:\n"
        "movl imp_rgp, %eax\n" /* line 457 */
        "movl 0x1008(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* image */
        "movb $1, -0x19(%ebp)\n" /* line 458 | samplerState */
        "jmp .Lff8708_000f956d\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_f8708_0:\n"
        ".long .Lff8708_000f9303\n"
        ".long .Lff8708_000f93d5\n"
        ".long .Lff8708_000f9590\n"
        ".long .Lff8708_000f94cb\n"
        ".long .Lff8708_000f94ff\n"
        ".text\n"
    );
}

/* line 1556 */
__attribute__((naked))
void RB_DrawTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1556 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %edi\n" /* vertDeclType */
        "movl 0xc(%ebp), %esi\n" /* args */
        /* { scope 1 */
        "movl imp_backEnd, %eax\n" /* line 1562 */
        "cmpb $0, 0x4bc(%eax)\n"
        "jne .Lff9d2a_000f9dd9\n"
        ".Lff9d2a_000f9d4b:\n"
        "movl imp_tess, %ebx\n" /* line 1567 */
        "movl 0x5a7c0(%ebx), %edx\n"
        "leal -6(%edx), %eax\n"
        "cmpl $0xb, %eax\n"
        "jbe .Lff9d2a_000f9dcc\n"
        ".Lff9d2a_000f9d5f:\n"
        "leal -3(%edx), %eax\n" /* line 1569 */
        "cmpl $0x17, %eax\n"
        "jbe .Lff9d2a_000f9dc5\n"
        ".Lff9d2a_000f9d67:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1575 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff9d2a_000f9d94\n"
        ".Lff9d2a_000f9d74:\n"
        "xorl %edx, %edx\n" /* line 1577 */
        "movl imp_tess, %eax\n" /* line 1582 */
        "movl 0x5a7c0(%eax), %eax\n"
        "movl %edx, 8(%ebp)\n" /* vertDeclType */
        "movl %esi, %ecx\n" /* args */
        "movl %edi, %edx\n" /* vertDeclType */
        /* } scope */
        "addl $0xc, %esp\n" /* line 1584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp RB_DrawSingleTechnique\n" /* line 1582 */
        ".Lff9d2a_000f9d94:\n"
        "movl 0x5a7c0(%ebx), %eax\n" /* line 1577 */
        "subl $9, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lff9d2a_000f9d74\n"
        "movl $overrideEnableRenormalize, %edx\n"
        "movl imp_tess, %eax\n" /* line 1582 */
        "movl 0x5a7c0(%eax), %eax\n"
        "movl %edx, 8(%ebp)\n" /* vertDeclType */
        "movl %esi, %ecx\n" /* args */
        "movl %edi, %edx\n" /* vertDeclType */
        /* } scope */
        "addl $0xc, %esp\n" /* line 1584 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp RB_DrawSingleTechnique\n" /* line 1582 */
        ".Lff9d2a_000f9dc5:\n"
        "calll RB_SetIteratorFog\n" /* line 1570 */
        "jmp .Lff9d2a_000f9d67\n"
        ".Lff9d2a_000f9dcc:\n"
        "calll RB_SetupLighting\n" /* line 1568 */
        "movl 0x5a7c0(%ebx), %edx\n"
        "jmp .Lff9d2a_000f9d5f\n"
        ".Lff9d2a_000f9dd9:\n"
        "calll RB_UpdateViewport\n" /* line 1563 */
        "jmp .Lff9d2a_000f9d4b\n"
    );
}

int g_rb_endsurface_count = 0; /* diagnostic */
int g_rb_endsurface_notechnique = 0; /* diagnostic: technique==NULL */
int g_rb_endsurface_dxstate = 0; /* diagnostic: dxState+0x20c8 non-zero */
int g_rb_endsurface_draw = 0; /* diagnostic: reached RB_DrawSingleTechnique */
/* line 1712 */
__attribute__((naked))
void RB_EndSurface(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1712 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl imp_tess, %edi\n"
        "movl 0x5a7bc(%edi), %eax\n"
        "movl 0x38(%eax), %edx\n"
        "movl 0x5a7c0(%edi), %eax\n"
        "movl 4(%edx, %eax, 4), %ebx\n"
        /* { scope 1 */
        "incl g_rb_endsurface_count\n" /* diagnostic */
        "testl %ebx, %ebx\n" /* line 1695 */
        "jne .Lff9de4_diag_has_tech\n"
        "incl g_rb_endsurface_notechnique\n" /* diagnostic: no technique */
        "jmp .Lff9de4_000f9e2b\n"
        ".Lff9de4_diag_has_tech:\n"
        "movl imp_backEnd, %esi\n" /* line 1698 */
        "cmpb $0, 0x4bc(%esi)\n"
        "jne .Lff9de4_000f9fa6\n"
        ".Lff9de4_000f9e1d:\n"
        "movl imp_dxState, %eax\n" /* line 1700 */
        "cmpb $0, 0x20c8(%eax)\n"
        "je .Lff9de4_000f9e51\n"
        "incl g_rb_endsurface_dxstate\n" /* diagnostic: dxState caused skip */
        /* } scope */
        ".Lff9de4_000f9e2b:\n"
        "movl $0, 0x5a7e0(%edi)\n" /* line 1725 */
        "movl $0, 0x5a7d0(%edi)\n" /* line 1726 */
        "movl $0, 0x5a7d4(%edi)\n" /* line 1727 */
        ".Lff9de4_000f9e49:\n"
        "addl $0x3c, %esp\n" /* line 1765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff9de4_000f9e51:\n"
        "movzwl 4(%ebx), %eax\n" /* line 1703 */
        "testb $1, %al\n"
        "je .Lff9de4_000f9e62\n"
        "cmpl $0xe, 0x2e84(%esi)\n"
        "je .Lff9de4_000f9e2b\n"
        ".Lff9de4_000f9e62:\n"
        "testb $2, %al\n" /* line 1705 */
        "jne .Lff9de4_000f9fb0\n"
        /* } scope */
        ".Lff9de4_000f9e6a:\n"
        "movl 0x5a7e0(%edi), %ecx\n" /* line 1738 */
        "testl %ecx, %ecx\n"
        "jne .Lff9de4_000f9fd7\n"
        ".Lff9de4_000f9e78:\n"
        "movl 0x5a7d0(%edi), %ecx\n" /* line 1744 */
        "testl %ecx, %ecx\n"
        "je .Lff9de4_000f9e49\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1667 */
        "movl 0x5a7d4(%edi), %eax\n" /* line 1668 */
        "movl %eax, -0x28(%ebp)\n"
        "movl $0x55555556, %edx\n" /* line 1669 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "cmpl $1, 0x5a7cc(%edi)\n" /* line 1672 */
        "je .Lff9de4_000fa11c\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1067 */
        "movl (%eax), %edx\n"
        "movl $0x24, %eax\n"
        "cmpl $2, 8(%edx)\n"
        "movl $0x40, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* line 1675 */
        ".Lff9de4_000f9ecd:\n"
        "movl %ecx, 4(%esp)\n" /* line 1678 */
        "movl 0x5a7b0(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetIndexData\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl imp_dx, %eax\n" /* line 27 */
        "movl 0x2db4(%eax), %edx\n"
        "movl 0x5a7d4(%edi), %eax\n"
        "imull -0x20(%ebp), %eax\n"
        "addl (%edx), %eax\n"
        "cmpl 4(%edx), %eax\n"
        "jle .Lff9de4_000f9f04\n"
        "movl $0, (%edx)\n" /* line 28 */
        ".Lff9de4_000f9f04:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1681 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x5a7d4(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_SetVertexData\n"
        "movl $0, -0x20(%ebp)\n" /* line 1682 */
        "movl 0x5a7cc(%edi), %esi\n" /* line 1685 */
        "movl imp_backEnd, %eax\n" /* line 1562 */
        "cmpb $0, 0x4bc(%eax)\n"
        "jne .Lff9de4_000fa112\n"
        ".Lff9de4_000f9f44:\n"
        "movl 0x5a7c0(%edi), %edx\n" /* line 1567 */
        "leal -6(%edx), %eax\n"
        "cmpl $0xb, %eax\n"
        "jbe .Lff9de4_000fa102\n"
        ".Lff9de4_000f9f56:\n"
        "leal -3(%edx), %eax\n" /* line 1569 */
        "cmpl $0x17, %eax\n"
        "jbe .Lff9de4_000fa0f8\n"
        ".Lff9de4_000f9f62:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1575 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff9de4_000f9fc2\n"
        ".Lff9de4_000f9f6f:\n"
        "xorl %edx, %edx\n" /* line 1577 */
        ".Lff9de4_000f9f71:\n"
        "leal -0x2c(%ebp), %ecx\n" /* line 1582 */
        "movl imp_tess, %ebx\n"
        "movl 0x5a7c0(%ebx), %eax\n"
        "movl %edx, (%esp)\n"
        "movl %esi, %edx\n"
        "incl g_rb_endsurface_draw\n" /* diagnostic: reached draw */
        "calll RB_DrawSingleTechnique\n"
        "movl $0, 0x5a7d0(%ebx)\n" /* line 1686 */
        "movl $0, 0x5a7d4(%ebx)\n" /* line 1687 */
        "addl $0x3c, %esp\n" /* line 1765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff9de4_000f9fa6:\n"
        "calll RB_UpdateViewport\n" /* line 1699 */
        "jmp .Lff9de4_000f9e1d\n"
        ".Lff9de4_000f9fb0:\n"
        "cmpl $0xe, 0x2e88(%esi)\n" /* line 1705 */
        "jne .Lff9de4_000f9e6a\n"
        "jmp .Lff9de4_000f9e2b\n"
        /* } scope */
        ".Lff9de4_000f9fc2:\n"
        "movl 0x5a7c0(%edi), %eax\n" /* line 1577 */
        "subl $9, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lff9de4_000f9f6f\n"
        "movl $overrideEnableRenormalize, %edx\n"
        "jmp .Lff9de4_000f9f71\n"
        ".Lff9de4_000f9fd7:\n"
        "movl 0x5a7e8(%edi), %eax\n" /* line 1624 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1625 */
        "movl 0x5a7e4(%edi), %eax\n" /* line 1626 */
        "movl %eax, -0x28(%ebp)\n"
        "movl $0x55555556, %edx\n" /* line 1627 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, 4(%esp)\n" /* line 1629 */
        "movl 0x5a7b4(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetIndexData\n"
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $1, 0x5a7b8(%edi)\n" /* line 1631 */
        "je .Lff9de4_000fa19b\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1089 */
        "movl (%eax), %eax\n"
        "movl $0x18, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x40, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl imp_dx, %eax\n" /* line 1024 */
        "movl 0x2dc4(%eax), %ecx\n"
        "movl imp_dxState, %eax\n" /* line 220 */
        "cmpl 0x20d0(%eax), %ecx\n"
        "je .Lff9de4_000fa13c\n"
        ".Lff9de4_000fa059:\n"
        "movl %edx, 0xc(%esp)\n" /* line 221 */
        "movl $0, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        ".Lff9de4_000fa075:\n"
        "movl imp_backEnd, %eax\n" /* line 1562 */
        "cmpb $0, 0x4bc(%eax)\n"
        "jne .Lff9de4_000fa175\n"
        ".Lff9de4_000fa087:\n"
        "movl imp_tess, %ebx\n" /* line 1567 */
        "movl 0x5a7c0(%ebx), %edx\n"
        "leal -6(%edx), %eax\n"
        "cmpl $0xb, %eax\n"
        "jbe .Lff9de4_000fa165\n"
        ".Lff9de4_000fa09f:\n"
        "leal -3(%edx), %eax\n" /* line 1569 */
        "cmpl $0x17, %eax\n"
        "jbe .Lff9de4_000fa15b\n"
        ".Lff9de4_000fa0ab:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1575 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff9de4_000fa17f\n"
        ".Lff9de4_000fa0bc:\n"
        "xorl %edx, %edx\n" /* line 1577 */
        ".Lff9de4_000fa0be:\n"
        "leal -0x2c(%ebp), %ecx\n" /* line 1582 */
        "movl imp_tess, %eax\n"
        "movl 0x5a7c0(%eax), %eax\n"
        "movl %edx, (%esp)\n"
        "movl $3, %edx\n"
        "calll RB_DrawSingleTechnique\n"
        ".Lff9de4_000fa0d9:\n"
        "movl imp_tess, %edi\n" /* line 1653 */
        "movl $0, 0x5a7e0(%edi)\n"
        "movl $0, 0x5a7b8(%edi)\n" /* line 1654 */
        "jmp .Lff9de4_000f9e78\n"
        ".Lff9de4_000fa0f8:\n"
        "calll RB_SetIteratorFog\n" /* line 1570 */
        "jmp .Lff9de4_000f9f62\n"
        ".Lff9de4_000fa102:\n"
        "calll RB_SetupLighting\n" /* line 1568 */
        "movl 0x5a7c0(%edi), %edx\n"
        "jmp .Lff9de4_000f9f56\n"
        ".Lff9de4_000fa112:\n"
        "calll RB_UpdateViewport\n" /* line 1563 */
        "jmp .Lff9de4_000f9f44\n"
        ".Lff9de4_000fa11c:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1078 */
        "movl (%eax), %edx\n"
        "movl $0x20, %eax\n"
        "cmpl $2, 8(%edx)\n"
        "movl $0x44, %edx\n"
        "cmovnel %edx, %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* line 1673 */
        "jmp .Lff9de4_000f9ecd\n"
        ".Lff9de4_000fa13c:\n"
        "movl 0x20d4(%eax), %ebx\n" /* line 220 */
        "testl %ebx, %ebx\n"
        "jne .Lff9de4_000fa059\n"
        "cmpl 0x20d8(%eax), %edx\n"
        "jne .Lff9de4_000fa059\n"
        "jmp .Lff9de4_000fa075\n"
        ".Lff9de4_000fa15b:\n"
        "calll RB_SetIteratorFog\n" /* line 1570 */
        "jmp .Lff9de4_000fa0ab\n"
        ".Lff9de4_000fa165:\n"
        "calll RB_SetupLighting\n" /* line 1568 */
        "movl 0x5a7c0(%ebx), %edx\n"
        "jmp .Lff9de4_000fa09f\n"
        ".Lff9de4_000fa175:\n"
        "calll RB_UpdateViewport\n" /* line 1563 */
        "jmp .Lff9de4_000fa087\n"
        ".Lff9de4_000fa17f:\n"
        "movl 0x5a7c0(%ebx), %eax\n" /* line 1577 */
        "subl $9, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lff9de4_000fa0bc\n"
        "movl $overrideEnableRenormalize, %edx\n"
        "jmp .Lff9de4_000fa0be\n"
        ".Lff9de4_000fa19b:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1078 */
        "movl (%eax), %eax\n"
        "movl $0x20, %edx\n"
        "cmpl $2, 8(%eax)\n"
        "movl $0x44, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl imp_rgp, %eax\n" /* line 1638 */
        "movl 0x109c(%eax), %eax\n"
        "movl 0x30(%eax), %ecx\n"
        "movl imp_dxState, %eax\n" /* line 220 */
        "cmpl 0x20d0(%eax), %ecx\n"
        "je .Lff9de4_000fa260\n"
        ".Lff9de4_000fa1d2:\n"
        "movl %edx, 0xc(%esp)\n" /* line 221 */
        "movl $0, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll RB_ChangeStreamSource\n"
        ".Lff9de4_000fa1ee:\n"
        "movl imp_backEnd, %eax\n" /* line 1562 */
        "cmpb $0, 0x4bc(%eax)\n"
        "jne .Lff9de4_000fa293\n"
        ".Lff9de4_000fa200:\n"
        "movl imp_tess, %ebx\n" /* line 1567 */
        "movl 0x5a7c0(%ebx), %edx\n"
        "leal -6(%edx), %eax\n"
        "cmpl $0xb, %eax\n"
        "jbe .Lff9de4_000fa286\n"
        ".Lff9de4_000fa214:\n"
        "leal -3(%edx), %eax\n" /* line 1569 */
        "cmpl $0x17, %eax\n"
        "jbe .Lff9de4_000fa27f\n"
        ".Lff9de4_000fa21c:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1575 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lff9de4_000fa24b\n"
        ".Lff9de4_000fa229:\n"
        "xorl %edx, %edx\n" /* line 1577 */
        ".Lff9de4_000fa22b:\n"
        "leal -0x2c(%ebp), %ecx\n" /* line 1582 */
        "movl imp_tess, %eax\n"
        "movl 0x5a7c0(%eax), %eax\n"
        "movl %edx, (%esp)\n"
        "movl $1, %edx\n"
        "calll RB_DrawSingleTechnique\n"
        "jmp .Lff9de4_000fa0d9\n"
        ".Lff9de4_000fa24b:\n"
        "movl 0x5a7c0(%ebx), %eax\n" /* line 1577 */
        "subl $9, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lff9de4_000fa229\n"
        "movl $overrideEnableRenormalize, %edx\n"
        "jmp .Lff9de4_000fa22b\n"
        ".Lff9de4_000fa260:\n"
        "movl 0x20d4(%eax), %esi\n" /* line 220 */
        "testl %esi, %esi\n"
        "jne .Lff9de4_000fa1d2\n"
        "cmpl 0x20d8(%eax), %edx\n"
        "jne .Lff9de4_000fa1d2\n"
        "jmp .Lff9de4_000fa1ee\n"
        ".Lff9de4_000fa27f:\n"
        "calll RB_SetIteratorFog\n" /* line 1570 */
        "jmp .Lff9de4_000fa21c\n"
        ".Lff9de4_000fa286:\n"
        "calll RB_SetupLighting\n" /* line 1568 */
        "movl 0x5a7c0(%ebx), %edx\n"
        "jmp .Lff9de4_000fa214\n"
        ".Lff9de4_000fa293:\n"
        "calll RB_UpdateViewport\n" /* line 1563 */
        "jmp .Lff9de4_000fa200\n"
    );
}
