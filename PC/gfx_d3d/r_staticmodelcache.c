/* ASM dump from: r_staticmodelcache.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_staticmodelcache.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "Mac/Tools/MacFastCopy.h"
 *   #include "PC/gfx_d3d/r_local.h"
 */

static static_model_cache_t s_cache; /* 0xc88580 */

void R_InitStaticModelIndexCache(void);
void R_StaticModelCacheStats_f(void);
void R_UsedCachedStaticModelSurface(GfxStaticModelSurfaceCached *surf);
void R_SkinStaticModelCachedCmd(SkinStaticModelCachedCmd *skinCmd, SkinBuffers *skinBuffers);
void R_InitStaticModelCache(void);
static void SMC_FreeCachedSurface_r(static_model_cache_t *cache, int levelsToLeaf);
void R_StaticModelCacheFlush_f(void);
void R_ShutdownStaticModelCache(void);
static Bool SMC_GetFreeBlockOfSize(static_model_cache_t *cache, int listIndex);
GfxStaticModelSurfaceCached * R_CacheStaticModelSurface(GfxStaticSurface *staticSurf, const XSurface *xsurf, int smodelIndex, const Material *material);
void R_FlushStaticModelCache(void);

/* line 781 */
__attribute__((naked))
void R_InitStaticModelIndexCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 781 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0xc0000, (%esp)\n" /* line 783 */
        "movl 0x195eee0, %eax\n"
        "calll *0xc(%eax)\n"
        "movl 0x195eed0, %edx\n"
        "movl %eax, 0x2dc8(%edx)\n"
        "leave\n" /* line 784 */
        "retl\n"
    );
}

/* line 819 */
__attribute__((naked))
void R_StaticModelCacheStats_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 819 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eee0, %ebx\n" /* line 821 */
        "cvtsi2ssl 0xc949b0, %xmm0\n"
        "mulss 0x2ed798, %xmm0\n" /* 100.0f */
        "mulss 0x2ed854, %xmm0\n" /* 1.52587890625e-05f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x224aa0, 4(%esp)\n" /* "%.2f%% of cache is currently allocated.
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl 0xc949b0, %eax\n" /* line 822 */
        "testl %eax, %eax\n"
        "je .Lfe031c_000e0398\n"
        "cvtsi2ssl 0xc949b4, %xmm0\n" /* line 823 */
        "mulss 0x2ed798, %xmm0\n" /* 100.0f */
        "cvtsi2ssl %eax, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x224acc, 4(%esp)\n" /* "%.2f%% allocated cache vertices are used.
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        ".Lfe031c_000e0398:\n"
        "addl $0x14, %esp\n" /* line 824 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 713 */
__attribute__((naked))
void R_UsedCachedStaticModelSurface(GfxStaticModelSurfaceCached *surf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 713 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* surf */
        /* { scope 1 */
        "subl $s_cache, %edx\n" /* line 721 */
        "movl $0x5397829d, %eax\n"
        "mull %edx\n"
        "shrl $7, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $3, %eax\n"
        "leal s_cache(%eax), %ecx\n"
        "movl 0x195eef4, %edx\n" /* line 725 */
        "movl (%edx), %edx\n"
        "movl (%edx), %edx\n"
        "movl %edx, 8(%ecx)\n"
        "movl 4(%ecx), %ebx\n" /* line 134 */
        "movl s_cache(%eax), %edx\n"
        "movl %edx, (%ebx)\n"
        "movl s_cache(%eax), %edx\n" /* line 135 */
        "movl %ebx, 4(%edx)\n"
        "movl $0xc949a8, s_cache(%eax)\n" /* line 125 */
        "movl 0xc949ac, %eax\n" /* line 126 */
        "movl %eax, 4(%ecx)\n"
        "movl %ecx, 0xc949ac\n" /* line 127 */
        "movl 4(%ecx), %eax\n" /* line 128 */
        "movl %ecx, (%eax)\n"
        /* } scope */
        "popl %ebx\n" /* line 729 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 592 */
__attribute__((naked))
void R_SkinStaticModelCachedCmd(SkinStaticModelCachedCmd *skinCmd, SkinBuffers *skinBuffers)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 592 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4ec, %esp\n"
        "movl 8(%ebp), %edi\n" /* skinCmd */
        /* { scope 1: xx, yy, zw, verts, ... */
        "movl (%edi), %eax\n" /* line 607 | skinCmd */
        "movl %eax, -0x47c(%ebp)\n" /* cached */
        "movl 8(%eax), %edx\n" /* line 608 */
        "movl %edx, -0x480(%ebp)\n" /* xsurf */
        "movl 0x195eebc, %ecx\n" /* line 609 */
        "movl 0x109c(%ecx), %eax\n"
        "movl 4(%edi), %ebx\n" /* skinCmd, smodelInst */
        "leal (%ebx, %ebx, 2), %ebx\n" /* smodelInst */
        "shll $5, %ebx\n" /* smodelInst */
        "addl 0xf8(%eax), %ebx\n" /* smodelInst */
        "movl 0x195eee0, %eax\n" /* line 610 */
        "movl 0x1a4(%eax), %esi\n" /* pSrc */
        "movl %edx, (%esp)\n"
        "calll XSurfaceGetBoneOffset\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* smodelInst */
        "movl %eax, (%esp)\n"
        "calll *%esi\n" /* pSrc */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        "movss 0x1c(%eax), %xmm1\n" /* line 350 | scale */
        /* { scope 3: i, lightCount */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss (%eax), %xmm3\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss 4(%eax), %xmm6\n"
        "mulss 8(%eax), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 352 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, -0x478(%ebp)\n" /* xx */
        "movss 4(%eax), %xmm4\n" /* line 353 */
        "movaps %xmm3, %xmm5\n"
        "mulss %xmm4, %xmm5\n"
        "movss 8(%eax), %xmm2\n" /* line 354 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss 0xc(%eax), %xmm0\n" /* line 355 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm6, %xmm4\n" /* line 357 */
        "movss %xmm4, -0x474(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm4\n" /* line 358 */
        "mulss %xmm2, %xmm4\n"
        "mulss %xmm0, %xmm6\n" /* line 359 */
        "mulss %xmm1, %xmm2\n" /* line 361 */
        "mulss %xmm0, %xmm1\n" /* line 362 */
        "movss %xmm1, -0x4bc(%ebp)\n" /* zw */
        "movss -0x474(%ebp), %xmm0\n" /* line 364 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0xc8(%ebp)\n" /* boneMatrix */
        "movss -0x4bc(%ebp), %xmm0\n" /* line 365 | zw */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movaps %xmm7, %xmm0\n" /* line 366 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "xorl %edx, %edx\n" /* line 367 */
        "movl %edx, -0xbc(%ebp)\n"
        "subss -0x4bc(%ebp), %xmm5\n" /* line 369 | zw */
        "movss %xmm5, -0xb8(%ebp)\n"
        "addss -0x478(%ebp), %xmm2\n" /* line 370 | xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0xb4(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 371 */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n"
        "movl %edx, -0xac(%ebp)\n" /* line 372 */
        "addss %xmm6, %xmm7\n" /* line 374 */
        "movss %xmm7, -0xa8(%ebp)\n"
        "subss %xmm3, %xmm4\n" /* line 375 */
        "movss %xmm4, -0xa4(%ebp)\n"
        "movss -0x478(%ebp), %xmm0\n" /* line 376 | xx */
        "addss -0x474(%ebp), %xmm0\n" /* yy */
        "movss %xmm0, -0x478(%ebp)\n" /* xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x478(%ebp), %xmm0\n" /* xx */
        "movss %xmm0, -0xa0(%ebp)\n"
        "movl %edx, -0x9c(%ebp)\n" /* line 377 */
        "leal 0x10(%eax), %edx\n" /* line 383 | from */
        /* { scope 3: i, lightCount */
        "movl 0x10(%eax), %eax\n" /* line 199 */
        "movl %eax, -0x98(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x94(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x90(%ebp)\n"
        /* } scope */
        "movl $0x3f800000, -0x8c(%ebp)\n" /* line 384 */
        /* } scope */
        "leal -0x7c(%ebp), %esi\n" /* line 613 | useAxis, pSrc */
        "movl %esi, 0x10(%esp)\n" /* pSrc */
        "movl 0x50(%ebx), %eax\n" /* smodelInst */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x2c(%ebx), %eax\n" /* smodelInst */
        "movl %eax, 8(%esp)\n"
        "addl $4, %ebx\n" /* smodelInst */
        "movl %ebx, 4(%esp)\n" /* smodelInst */
        "leal -0xc8(%ebp), %eax\n" /* boneMatrix */
        "movl %eax, (%esp)\n"
        "calll R_GetRigidTransform\n"
        "leal -0x4c(%ebp), %eax\n" /* line 615 | normAxis */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pSrc */
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "leal -0x40(%ebp), %eax\n" /* line 616 */
        "movl %eax, 4(%esp)\n"
        "leal -0x70(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "leal -0x34(%ebp), %eax\n" /* line 617 */
        "movl %eax, 4(%esp)\n"
        "leal -0x64(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "movl 8(%edi), %ebx\n" /* line 621 | skinCmd, smodelInst */
        "movl 4(%edi), %ecx\n" /* skinCmd */
        "movl -0x480(%ebp), %edx\n" /* xsurf */
        "movzwl 2(%edx), %edx\n"
        "movw %dx, -0x482(%ebp)\n"
        "movswl %dx, %eax\n"
        "movl %eax, -0x458(%ebp)\n" /* vertCount */
        "movl -0x47c(%ebp), %edx\n" /* cached */
        "movl (%edx), %edx\n"
        "movl %edx, -0x454(%ebp)\n" /* baseVertIndex */
        "movl -0x480(%ebp), %eax\n" /* xsurf */
        "movl 0xc(%eax), %edi\n" /* skinCmd */
        "movl 0x195eec0, %eax\n" /* line 580 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe0408_000e0a64\n"
        "movl 0xc(%ebp), %ebx\n" /* line 587 | skinBuffers, material */
        "addl $0x2000, %ebx\n" /* material */
        "movl %ebx, -0x45c(%ebp)\n" /* material, verts */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        "movl 0x195eebc, %eax\n" /* line 393 */
        "movl 0x109c(%eax), %edx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl 0xf8(%edx), %eax\n"
        "leal 0x54(%eax), %ebx\n" /* baseLightingCoords */
        "movss 0x2ed824, %xmm1\n" /* line 428 | 32768.0f */
        "movss 0x54(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x4b8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x498(%ebp)\n"
        "cvttss2si -0x498(%ebp), %eax\n"
        "movw %ax, -0x428(%ebp)\n"
        "movss -0x4b8(%ebp), %xmm1\n"
        "mulss 4(%ebx), %xmm1\n" /* baseLightingCoords */
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x49c(%ebp)\n"
        "cvttss2si -0x49c(%ebp), %edx\n"
        "movw %dx, -0x438(%ebp)\n"
        "movl -0x458(%ebp), %edx\n" /* line 400 | vertCount */
        "testl %edx, %edx\n"
        "jg .Lfe0408_000e08af\n"
        ".Lfe0408_000e072a:\n"
        "movl 0x195eed0, %eax\n" /* line 439 */
        "movl 0x2dc4(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0x1001, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x458(%ebp), %eax\n" /* vertCount */
        "shll $6, %eax\n"
        "movl %eax, 8(%esp)\n"
        "shll $6, -0x454(%ebp)\n" /* baseVertIndex */
        "movl -0x454(%ebp), %ebx\n" /* baseVertIndex, baseLightingCoords */
        "movl %ebx, 4(%esp)\n" /* baseLightingCoords */
        "movl %edx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 441 */
        "js .Lfe0408_000e0f50\n"
        ".Lfe0408_000e0772:\n"
        "movl -0x45c(%ebp), %eax\n" /* line 446 | verts */
        "movl %eax, -0x44c(%ebp)\n" /* pSrc */
        "movl -0x1c(%ebp), %edi\n" /* line 447 | bufferData, pDst */
        "movl $0, (%esp)\n" /* line 448 */
        "calll CColorConverter_GetColorConverter\n"
        "movl %eax, -0x448(%ebp)\n" /* c */
        /* { scope 4 */
        "cmpw $0, -0x482(%ebp)\n" /* line 450 */
        "jne .Lfe0408_000e07c6\n"
        /* } scope */
        ".Lfe0408_000e079d:\n"
        "movl 0x195eed0, %eax\n" /* line 467 */
        "movl 0x2dc4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe0408_000e079d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfe0408_000e07bb:\n"
        "addl $0x4ec, %esp\n" /* line 627 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, yy, zw, verts, ... */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        /* { scope 4 */
        ".Lfe0408_000e07c6:\n"
        "movl $0, -0x444(%ebp)\n" /* line 450 | i */
        "leal 0x34(%edi), %esi\n" /* pDst */
        "movl -0x44c(%ebp), %ebx\n" /* pSrc, baseLightingCoords */
        "addl $0x34, %ebx\n" /* baseLightingCoords */
        /* { scope 5 */
        ".Lfe0408_000e07dc:\n"
        "movl -0x30(%ebx), %edx\n" /* line 28 | Temp2 */
        "movl -0x2c(%ebx), %ecx\n" /* line 29 | Temp3 */
        "movl -0x34(%ebx), %eax\n" /* line 31 */
        "movl %eax, -0x34(%esi)\n"
        "movl %edx, -0x30(%esi)\n" /* line 32 */
        "movl %ecx, -0x2c(%esi)\n" /* line 33 */
        /* } scope */
        /* { scope 5 */
        "movl -0x24(%ebx), %edx\n" /* line 28 | Temp2 */
        "movl -0x20(%ebx), %ecx\n" /* line 29 | Temp3 */
        "movl -0x28(%ebx), %eax\n" /* line 31 */
        "movl %eax, -0x28(%esi)\n"
        "movl %edx, -0x24(%esi)\n" /* line 32 */
        "movl %ecx, -0x20(%esi)\n" /* line 33 */
        /* } scope */
        "movl -0x448(%ebp), %ecx\n" /* line 454 | c */
        "movl (%ecx), %edx\n"
        "movl -0x44c(%ebp), %eax\n" /* pSrc */
        "addl $0x18, %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x18(%edi), %eax\n" /* pDst */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        /* { scope 5 */
        "movl -0x14(%ebx), %edx\n" /* line 18 | Temp2 */
        "movl -0x18(%ebx), %eax\n" /* line 20 */
        "movl %eax, -0x18(%esi)\n"
        "movl %edx, -0x14(%esi)\n" /* line 21 */
        /* } scope */
        "movzwl -0x10(%ebx), %eax\n" /* line 456 | baseLightingCoords */
        "movw %ax, -0x10(%esi)\n"
        "movzwl -0xe(%ebx), %eax\n" /* line 457 | baseLightingCoords */
        "movw %ax, -0xe(%esi)\n"
        /* { scope 5 */
        "movl -8(%ebx), %edx\n" /* line 28 | Temp2 */
        "movl -4(%ebx), %ecx\n" /* line 29 | Temp3 */
        "movl -0xc(%ebx), %eax\n" /* line 31 */
        "movl %eax, -0xc(%esi)\n"
        "movl %edx, -8(%esi)\n" /* line 32 */
        "movl %ecx, -4(%esi)\n" /* line 33 */
        /* } scope */
        /* { scope 5 */
        "movl 4(%ebx), %edx\n" /* line 28 | Temp2 */
        "movl 8(%ebx), %ecx\n" /* line 29 | Temp3 */
        "movl (%ebx), %eax\n" /* line 31 */
        "movl %eax, (%esi)\n"
        "movl %edx, 4(%esi)\n" /* line 32 */
        "movl %ecx, 8(%esi)\n" /* line 33 */
        /* } scope */
        "addl $1, -0x444(%ebp)\n" /* line 450 | i */
        "addl $0x40, -0x44c(%ebp)\n" /* pSrc */
        "addl $0x40, %ebx\n" /* baseLightingCoords */
        "addl $0x40, %edi\n" /* pDst */
        "addl $0x40, %esi\n"
        "movl -0x458(%ebp), %eax\n" /* vertCount */
        "cmpl %eax, -0x444(%ebp)\n" /* i */
        "jb .Lfe0408_000e07dc\n"
        /* } scope */
        "movl 0x195eed0, %eax\n" /* line 467 */
        "movl 0x2dc4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe0408_000e079d\n"
        "jmp .Lfe0408_000e07bb\n"
        ".Lfe0408_000e08af:\n"
        "movl -0x45c(%ebp), %ecx\n" /* line 400 | verts */
        "movl %ecx, -0x40c(%ebp)\n"
        "movl $0, -0x450(%ebp)\n" /* vertIndex */
        "movl %ecx, %ebx\n" /* baseLightingCoords */
        "jmp .Lfe0408_000e08cf\n"
        ".Lfe0408_000e08c9:\n"
        "movl -0x40c(%ebp), %ebx\n" /* baseLightingCoords */
        /* { scope 4 */
        ".Lfe0408_000e08cf:\n"
        "movss 0x30(%edi), %xmm1\n" /* line 405 */
        "mulss -0x7c(%ebp), %xmm1\n" /* useAxis */
        "movss 0x34(%edi), %xmm0\n"
        "mulss -0x70(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edi), %xmm0\n"
        "mulss -0x64(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x58(%ebp), %xmm1\n"
        "movss %xmm1, (%ebx)\n" /* baseLightingCoords */
        "movss 0x30(%edi), %xmm1\n" /* line 406 */
        "mulss -0x78(%ebp), %xmm1\n"
        "movss 0x34(%edi), %xmm0\n"
        "mulss -0x6c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edi), %xmm0\n"
        "mulss -0x60(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x54(%ebp), %xmm1\n"
        "movss %xmm1, 4(%ebx)\n" /* baseLightingCoords */
        "movss 0x30(%edi), %xmm1\n" /* line 407 */
        "mulss -0x74(%ebp), %xmm1\n"
        "movss 0x34(%edi), %xmm0\n"
        "mulss -0x68(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x38(%edi), %xmm0\n"
        "mulss -0x5c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x50(%ebp), %xmm1\n"
        "movss %xmm1, 8(%ebx)\n" /* baseLightingCoords */
        "movl %ebx, %eax\n" /* line 409 | baseLightingCoords */
        "addl $0xc, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %eax\n" /* normAxis */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "movzbl 0xc(%edi), %edx\n" /* line 412 */
        "movb %dl, -0x4c9(%ebp)\n"
        "movzbl 0xd(%edi), %ebx\n" /* line 413 | baseLightingCoords */
        "movzbl 0xe(%edi), %esi\n" /* line 414 */
        "movl -0x40c(%ebp), %edx\n" /* line 417 | pDst */
        "addl $0x18, %edx\n" /* pDst */
        "movzbl 0xf(%edi), %ecx\n" /* line 419 */
        "movl -0x40c(%ebp), %eax\n"
        "movb %cl, 0x18(%eax)\n"
        "movzbl -0x4c9(%ebp), %ecx\n" /* line 420 */
        "movb %cl, 1(%edx)\n"
        "movb %bl, 2(%edx)\n" /* line 421 | baseLightingCoords */
        "movl %esi, %ebx\n" /* line 422 | baseLightingCoords */
        "movb %bl, 3(%edx)\n" /* baseLightingCoords */
        "movl 0x1c(%edi), %eax\n" /* line 426 */
        "movl -0x40c(%ebp), %edx\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x2c(%edi), %eax\n" /* line 427 */
        "movl %eax, 0x20(%edx)\n"
        "movl -0x428(%ebp), %ecx\n" /* line 428 */
        "movw %cx, 0x24(%edx)\n"
        "movl -0x438(%ebp), %ebx\n" /* line 429 | baseLightingCoords */
        "movw %bx, 0x26(%edx)\n" /* baseLightingCoords */
        "movl %edx, %eax\n" /* line 431 */
        "addl $0x28, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %eax\n" /* normAxis */
        "movl %eax, (%esp)\n"
        "calll AxisTransformVector\n"
        "movl -0x40c(%ebp), %eax\n" /* line 432 */
        "addl $0x34, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x28(%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x24(%edi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x20(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %edx\n" /* normAxis */
        "movl %edx, (%esp)\n"
        "calll AxisTransformVector\n"
        /* } scope */
        "addl $1, -0x450(%ebp)\n" /* line 400 | vertIndex */
        "addl $0x40, %edi\n"
        "addl $0x40, -0x40c(%ebp)\n"
        "movl -0x450(%ebp), %ecx\n" /* vertIndex */
        "cmpl %ecx, -0x458(%ebp)\n" /* vertCount */
        "jne .Lfe0408_000e08c9\n"
        "jmp .Lfe0408_000e072a\n"
        /* } scope */
        /* } scope */
        ".Lfe0408_000e0a64:\n"
        "movl 0xc(%ebp), %edx\n" /* line 582 | skinBuffers */
        "addl $0x2000, %edx\n"
        "movl %edx, -0x470(%ebp)\n" /* verts */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        "movl 0x195eebc, %eax\n" /* line 524 */
        "movl 0x109c(%eax), %edx\n"
        "movl $8, 0x10(%esp)\n"
        "leal -0x408(%ebp), %eax\n" /* lights */
        "movl %eax, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* baseLightingCoords */
        "movl 0x130(%edx), %eax\n"
        "movl (%eax, %ecx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl 0x12c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DeriveEntityLights\n"
        "movl %eax, -0x464(%ebp)\n" /* lightCount */
        "movl -0x458(%ebp), %eax\n" /* line 526 | vertCount */
        "testl %eax, %eax\n"
        "jg .Lfe0408_000e0b65\n"
        ".Lfe0408_000e0ac9:\n"
        "movl 0x195eed0, %eax\n" /* line 546 */
        "movl 0x2dc4(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0x1001, 0x10(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* bufferData */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x458(%ebp), %ebx\n" /* vertCount, baseLightingCoords */
        "leal (%ebx, %ebx, 2), %eax\n" /* baseLightingCoords */
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x454(%ebp), %ebx\n" /* baseVertIndex, baseLightingCoords */
        "leal (%ebx, %ebx, 2), %eax\n" /* baseLightingCoords */
        "shll $3, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 548 */
        "js .Lfe0408_000e0f5d\n"
        ".Lfe0408_000e0b13:\n"
        "movl -0x470(%ebp), %esi\n" /* line 553 | verts, pSrc */
        "movl -0x1c(%ebp), %ebx\n" /* line 554 | bufferData, pDst */
        "movl $0, (%esp)\n" /* line 555 */
        "calll CColorConverter_GetColorConverter\n"
        "movl %eax, -0x468(%ebp)\n" /* c */
        /* { scope 4 */
        "cmpw $0, -0x482(%ebp)\n" /* line 558 */
        "jne .Lfe0408_000e0efb\n"
        /* } scope */
        ".Lfe0408_000e0b3c:\n"
        "movl 0x195eed0, %eax\n" /* line 570 */
        "movl 0x2dc4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl 0x195f0e0, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfe0408_000e0b3c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x4ec, %esp\n" /* line 627 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: xx, yy, zw, verts, ... */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        ".Lfe0408_000e0b65:\n"
        "movl $0, -0x46c(%ebp)\n" /* line 526 | vertIndex */
        "movl 0xc(%ebp), %esi\n" /* skinBuffers */
        "addl $0x200c, %esi\n"
        "leal 0xc(%edi), %ebx\n" /* pDst, baseLightingCoords */
        ".Lfe0408_000e0b7b:\n"
        "movss 0x24(%ebx), %xmm1\n" /* line 531 | baseLightingCoords */
        "mulss -0x7c(%ebp), %xmm1\n" /* useAxis */
        "movss 0x28(%ebx), %xmm0\n" /* baseLightingCoords */
        "mulss -0x70(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2c(%ebx), %xmm0\n" /* baseLightingCoords */
        "mulss -0x64(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x58(%ebp), %xmm1\n"
        "movss %xmm1, -0xc(%esi)\n"
        "movss 0x24(%ebx), %xmm1\n" /* line 532 | baseLightingCoords */
        "mulss -0x78(%ebp), %xmm1\n"
        "movss 0x28(%ebx), %xmm0\n" /* baseLightingCoords */
        "mulss -0x6c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2c(%ebx), %xmm0\n" /* baseLightingCoords */
        "mulss -0x60(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x54(%ebp), %xmm1\n"
        "movss %xmm1, -8(%esi)\n"
        "movss 0x24(%ebx), %xmm1\n" /* line 533 | baseLightingCoords */
        "mulss -0x74(%ebp), %xmm1\n"
        "movss 0x28(%ebx), %xmm0\n" /* baseLightingCoords */
        "mulss -0x68(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss 0x2c(%ebx), %xmm0\n" /* baseLightingCoords */
        "mulss -0x5c(%ebp), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "addss -0x50(%ebp), %xmm1\n"
        "movss %xmm1, -4(%esi)\n"
        "movl 0x10(%ebx), %eax\n" /* line 535 | baseLightingCoords */
        "movl %eax, 4(%esi)\n"
        "movl 0x20(%ebx), %eax\n" /* line 536 | baseLightingCoords */
        "movl %eax, 8(%esi)\n"
        "leal -0x28(%ebp), %edx\n" /* line 538 | normal */
        "movl %edx, 0x10(%esp)\n"
        "movl -4(%ebx), %eax\n" /* baseLightingCoords */
        "movl %eax, 0xc(%esp)\n"
        "movl -8(%ebx), %eax\n" /* baseLightingCoords */
        "movl %eax, 8(%esp)\n"
        "movl -0xc(%ebx), %eax\n" /* baseLightingCoords */
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %ecx\n" /* normAxis */
        "movl %ecx, (%esp)\n"
        "calll AxisTransformVector\n"
        /* { scope 4 */
        /* { scope 5 */
        "movl -0x464(%ebp), %edi\n" /* line 482 | lightCount, pDst */
        "testl %edi, %edi\n" /* pDst */
        "jg .Lfe0408_000e0e03\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm5\n"
        "movaps %xmm3, %xmm4\n"
        ".Lfe0408_000e0c56:\n"
        "movzbl 2(%ebx), %eax\n" /* line 497 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss %xmm4, %xmm1\n"
        "mulss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "movzbl 1(%ebx), %eax\n" /* line 498 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0x43c(%ebp)\n"
        "movzbl (%ebx), %eax\n" /* line 499 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x440(%ebp)\n"
        "movzbl 3(%ebx), %eax\n" /* line 428 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss 0x2ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x4b8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x488(%ebp)\n"
        "cvttss2si -0x488(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "movss -0x4b8(%ebp), %xmm1\n"
        "js .Lfe0408_000e0ee8\n"
        "movl $0xff, %edx\n"
        /* { scope 6 */
        ".Lfe0408_000e0d03:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfe0408_000e0d05:\n"
        "movb %al, (%esi)\n" /* line 503 */
        "leal 1(%esi), %edi\n" /* line 504 | pDst */
        "movaps %xmm1, %xmm0\n" /* line 428 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x48c(%ebp)\n"
        "cvttss2si -0x48c(%ebp), %edx\n"
        "movl %edx, %ecx\n" /* line 154 */
        "subl $0xff, %ecx\n"
        "js .Lfe0408_000e0ed5\n"
        "movl $0xff, %edx\n"
        /* { scope 6 */
        ".Lfe0408_000e0d48:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfe0408_000e0d4a:\n"
        "movb %al, (%edi)\n" /* line 504 | pDst */
        "leal 2(%esi), %edi\n" /* line 505 | pDst */
        "movss -0x43c(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x490(%ebp)\n"
        "cvttss2si -0x490(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lfe0408_000e0ec2\n"
        "movl $0xff, %edx\n"
        /* { scope 6 */
        ".Lfe0408_000e0d91:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfe0408_000e0d93:\n"
        "movb %al, (%edi)\n" /* line 505 | pDst */
        "leal 3(%esi), %edi\n" /* line 506 | pDst */
        "movss -0x440(%ebp), %xmm0\n" /* line 428 */
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x494(%ebp)\n"
        "cvttss2si -0x494(%ebp), %edx\n"
        "movl %edx, %ecx\n" /* line 154 */
        "subl $0xff, %ecx\n"
        "js .Lfe0408_000e0eaf\n"
        "movl $0xff, %edx\n"
        /* { scope 6 */
        ".Lfe0408_000e0ddb:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lfe0408_000e0ddd:\n"
        "movb %al, (%edi)\n" /* line 506 | pDst */
        /* } scope */
        /* } scope */
        "addl $1, -0x46c(%ebp)\n" /* line 526 | vertIndex */
        "addl $0x40, %ebx\n" /* baseLightingCoords */
        "addl $0x18, %esi\n"
        "movl -0x46c(%ebp), %eax\n" /* vertIndex */
        "cmpl %eax, -0x458(%ebp)\n" /* vertCount */
        "jne .Lfe0408_000e0b7b\n"
        "jmp .Lfe0408_000e0ac9\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lfe0408_000e0e03:\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 488 | normal */
        "movss %xmm0, -0x460(%ebp)\n"
        "movss -0x24(%ebp), %xmm7\n"
        "movss -0x20(%ebp), %xmm6\n"
        "xorl %edx, %edx\n"
        "pxor %xmm3, %xmm3\n"
        "movaps %xmm3, %xmm5\n"
        "movaps %xmm3, %xmm4\n"
        "leal -0x3e4(%ebp), %eax\n"
        "movss 0x2f26e0, %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lfe0408_000e0e41\n"
        ".Lfe0408_000e0e39:\n"
        "movss -0x460(%ebp), %xmm1\n"
        ".Lfe0408_000e0e41:\n"
        "addss (%eax), %xmm4\n" /* line 485 */
        "addss 4(%eax), %xmm5\n" /* line 486 */
        "addss 8(%eax), %xmm3\n" /* line 487 */
        "mulss 0x1c(%eax), %xmm1\n" /* line 488 */
        "movaps %xmm7, %xmm0\n"
        "mulss 0x20(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n"
        "mulss 0x24(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "xorps %xmm2, %xmm1\n" /* line 489 */
        "pxor %xmm0, %xmm0\n" /* line 490 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lfe0408_000e0e9c\n"
        "movaps %xmm1, %xmm0\n" /* line 492 */
        "mulss -0x20(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "movaps %xmm1, %xmm0\n" /* line 493 */
        "mulss -0x1c(%eax), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 494 */
        "mulss -0x18(%eax), %xmm0\n"
        "addss %xmm0, %xmm3\n"
        ".Lfe0408_000e0e9c:\n"
        "addl $1, %edx\n" /* line 482 */
        "addl $0x68, %eax\n"
        "cmpl %edx, -0x464(%ebp)\n" /* lightCount */
        "jne .Lfe0408_000e0e39\n"
        "jmp .Lfe0408_000e0c56\n"
        ".Lfe0408_000e0eaf:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 6 */
        "testl %eax, %eax\n"
        "js .Lfe0408_000e0ddb\n"
        "xorl %eax, %eax\n"
        "jmp .Lfe0408_000e0ddd\n"
        /* } scope */
        ".Lfe0408_000e0ec2:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 6 */
        "testl %eax, %eax\n"
        "js .Lfe0408_000e0d91\n"
        "xorl %eax, %eax\n"
        "jmp .Lfe0408_000e0d93\n"
        /* } scope */
        ".Lfe0408_000e0ed5:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 6 */
        "testl %eax, %eax\n"
        "js .Lfe0408_000e0d48\n"
        "xorl %eax, %eax\n"
        "jmp .Lfe0408_000e0d4a\n"
        /* } scope */
        ".Lfe0408_000e0ee8:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 6 */
        "testl %eax, %eax\n"
        "js .Lfe0408_000e0d03\n"
        "xorl %eax, %eax\n"
        "jmp .Lfe0408_000e0d05\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4 */
        ".Lfe0408_000e0efb:\n"
        "xorl %edi, %edi\n" /* line 558 | i */
        /* { scope 5 */
        ".Lfe0408_000e0efd:\n"
        "movl 4(%esi), %edx\n" /* line 28 | Temp2 */
        "movl 8(%esi), %ecx\n" /* line 29 | Temp3 */
        "movl (%esi), %eax\n" /* line 31 */
        "movl %eax, (%ebx)\n"
        "movl %edx, 4(%ebx)\n" /* line 32 */
        "movl %ecx, 8(%ebx)\n" /* line 33 */
        /* } scope */
        "movl -0x468(%ebp), %eax\n" /* line 561 | c */
        "movl (%eax), %edx\n"
        "leal 0xc(%esi), %eax\n" /* pSrc */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* pDst */
        "movl %eax, 4(%esp)\n"
        "movl -0x468(%ebp), %ecx\n" /* c */
        "movl %ecx, (%esp)\n"
        "calll *(%edx)\n"
        /* { scope 5 */
        "movl 0x14(%esi), %edx\n" /* line 18 | Temp2 */
        "movl 0x10(%esi), %eax\n" /* line 20 */
        "movl %eax, 0x10(%ebx)\n"
        "movl %edx, 0x14(%ebx)\n" /* line 21 */
        /* } scope */
        "addl $1, %edi\n" /* line 558 | i */
        "addl $0x18, %esi\n" /* pSrc */
        "addl $0x18, %ebx\n" /* pDst */
        "cmpl %edi, -0x458(%ebp)\n" /* i, vertCount */
        "ja .Lfe0408_000e0efd\n"
        "jmp .Lfe0408_000e0b3c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        ".Lfe0408_000e0f50:\n"
        "movl %eax, (%esp)\n" /* line 442 */
        "calll R_FatalLockError\n"
        "jmp .Lfe0408_000e0772\n"
        /* } scope */
        /* } scope */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        ".Lfe0408_000e0f5d:\n"
        "movl %eax, (%esp)\n" /* line 549 */
        "calll R_FatalLockError\n"
        "jmp .Lfe0408_000e0b13\n"
    );
}

/* line 774 */
__attribute__((naked))
void R_InitStaticModelCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 774 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x195eec0, %eax\n" /* line 1067 */
        "movl (%eax), %eax\n"
        "movl $0x240000, %esi\n" /* "
DP4 oPos.w, v0, c23[3];
DP3 r0.x, v1, c4[0];
DP3 r0.y, v1, " */
        "cmpl $2, 8(%eax)\n"
        "movl $0x400000, %eax\n"
        "cmovnel %eax, %esi\n"
        "movl 0x195eed0, %ebx\n"
        "addl $0x2dc4, %ebx\n"
        "movl 0x195f0e0, %edi\n"
        ".Lfe0f6a_000e0f9d:\n"
        "movl 0x195eed0, %edx\n" /* line 748 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x400208, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x68(%edx)\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe0f6a_000e0f9d\n"
        "movl $0xc438, 8(%esp)\n" /* line 758 */
        "movl $0, 4(%esp)\n"
        "movl $s_cache, (%esp)\n"
        "calll memset\n"
        "movl $0xc949a8, 0xc949a8\n" /* line 760 */
        "movl $0xc949a8, 0xc949ac\n" /* line 761 */
        "xorl %ecx, %ecx\n"
        "movl $s_cache, %edx\n"
        "movl $0xc94980, %eax\n"
        ".Lfe0f6a_000e1018:\n"
        "movl %eax, 0xc400(%edx)\n" /* line 765 */
        "movl %eax, 0xc404(%edx)\n" /* line 766 */
        "addl $1, %ecx\n" /* line 763 */
        "addl $8, %eax\n"
        "addl $8, %edx\n"
        "cmpl $5, %ecx\n"
        "jne .Lfe0f6a_000e1018\n"
        "xorl %ebx, %ebx\n"
        "movl $0xc88600, %ecx\n"
        "movl 0xc94984, %edx\n"
        "jmp .Lfe0f6a_000e1043\n"
        ".Lfe0f6a_000e1041:\n"
        "movl %eax, %edx\n"
        ".Lfe0f6a_000e1043:\n"
        "leal 8(%ecx), %eax\n" /* line 770 */
        "movl $0xc94980, 8(%ecx)\n" /* line 125 */
        "movl %edx, 0xc(%ecx)\n" /* line 126 */
        "movl %eax, 0xc94984\n" /* line 127 */
        "movl 0xc(%ecx), %edx\n" /* line 128 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* line 769 */
        "addl $0x188, %ecx\n"
        "cmpl $0x80, %ebx\n"
        "jne .Lfe0f6a_000e1041\n"
        "addl $0x2c, %esp\n" /* line 778 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 147 */
static __attribute__((naked))
void SMC_FreeCachedSurface_r(static_model_cache_t *cache, int levelsToLeaf)
{
    __asm__ __volatile__ (
        ".Lfe1074_000e1074:\n"
        "pushl %ebp\n" /* line 147 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl %edx, %esi\n" /* nodeIndex, tree */
        "movl %ecx, %edx\n" /* nodeIndex */
        "movl 8(%ebp), %edi\n" /* levelsToLeaf */
        /* { scope 1: lodLevel, levelsToLeaf */
        "cmpw $0, 0xc(%esi, %ecx, 4)\n" /* line 155 | tree */
        "jne .Lfe1074_000e10b3\n"
        ".Lfe1074_000e108f:\n"
        "leal 1(%edx), %eax\n" /* line 158 | nodeIndex */
        "movl %edi, %ecx\n" /* surf */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e1094:\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x80(%eax, %esi), %eax\n"
        "movl 0xc(%eax), %ecx\n" /* line 134 */
        "movl 8(%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lfe1074_000e10ab:\n"
        "addl $0x7c, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lodLevel, levelsToLeaf */
        ".Lfe1074_000e10b3:\n"
        "movw $0, 0xc(%esi, %ecx, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %ecx, 4)\n" /* line 164 | tree */
        "jne .Lfe1074_000e129d\n"
        "leal -3(%edi), %eax\n" /* surf */
        "movl %eax, -0x2c(%ebp)\n"
        "leal -2(%edi), %ecx\n" /* surf */
        "movl %ecx, -0x28(%ebp)\n"
        "addl $3, %edi\n" /* surf */
        "movl %edi, -0x24(%ebp)\n" /* surf */
        "jmp .Lfe1074_000e11f4\n"
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e10dc:\n"
        "movl %edx, %edi\n" /* line 157 | nodeIndex, surf */
        "addl $2, %edi\n" /* surf */
        "movl %edi, %eax\n" /* line 158 | surf */
        "movzbl -0x5c(%ebp), %ecx\n" /* levelsToLeaf */
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x80(%eax, %esi), %eax\n"
        "movl 0xc(%eax), %ecx\n" /* line 134 */
        "movl 8(%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        /* } scope */
        /* } scope */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e10fe:\n"
        "cmpw $0, 0xc(%esi, %edi, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e160f\n"
        "movw $0, 0xc(%esi, %edi, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %edi, 4)\n" /* line 164 | tree */
        "jne .Lfe1074_000e161e\n"
        "addl %edi, %edi\n" /* line 185 | surf */
        "movl %edi, -0x40(%ebp)\n" /* surf */
        "movl %edi, %ecx\n" /* surf */
        "addl $1, %ecx\n"
        "movl %ecx, -0x6c(%ebp)\n" /* nodeIndex */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        "cmpw $0, 0xc(%esi, %ecx, 4)\n" /* line 155 | tree */
        "jne .Lfe1074_000e1310\n"
        "movl %edi, %ebx\n" /* line 157 | surf, staticSurf */
        "addl $2, %ebx\n" /* staticSurf */
        "movl %ebx, %eax\n" /* line 158 | staticSurf */
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x80(%eax, %esi), %eax\n"
        "movl 0xc(%eax), %ecx\n" /* line 134 */
        "movl 8(%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        /* } scope */
        /* } scope */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e1157:\n"
        "cmpw $0, 0xc(%esi, %ebx, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e1690\n"
        "movw $0, 0xc(%esi, %ebx, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %ebx, 4)\n" /* line 164 | tree */
        "jne .Lfe1074_000e169f\n"
        "addl %ebx, %ebx\n" /* line 185 | nodeIndex */
        "leal 1(%ebx), %ecx\n" /* nodeIndex */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 2(%ebx), %edx\n" /* line 186 | nodeIndex */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        "cmpw $0, 0xc(%esi, %edx, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e1711\n"
        "movw $0, 0xc(%esi, %edx, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %edx, 4)\n" /* line 164 | tree */
        "jne .Lfe1074_000e171d\n"
        "movl -0x2c(%ebp), %edi\n" /* line 181 | surf */
        "subl $1, %edi\n" /* surf */
        "leal (%edx, %edx), %ebx\n" /* line 185 | nodeIndex */
        "leal 1(%ebx), %ecx\n" /* nodeIndex */
        "movl %edi, (%esp)\n" /* surf */
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 2(%ebx), %edx\n" /* line 186 | nodeIndex */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "cmpw $0, 0xc(%esi, %edx, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e108f\n"
        "movw $0, 0xc(%esi, %edx, 4)\n" /* line 162 | tree */
        "subl $4, -0x2c(%ebp)\n"
        "subl $4, -0x28(%ebp)\n"
        "subl $4, -0x24(%ebp)\n"
        "cmpb $0, 0xe(%esi, %edx, 4)\n" /* line 164 | tree */
        "jne .Lfe1074_000e129d\n"
        "movl -0x2c(%ebp), %eax\n"
        ".Lfe1074_000e11f4:\n"
        "addl $2, %eax\n" /* line 182 */
        "movl %eax, -0x5c(%ebp)\n" /* levelsToLeaf */
        "addl %edx, %edx\n" /* line 185 | nodeIndex */
        "movl %edx, -0x64(%ebp)\n" /* nodeIndex */
        "movl %edx, %ebx\n" /* nodeIndex */
        "addl $1, %ebx\n" /* nodeIndex */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        "cmpw $0, 0xc(%esi, %ebx, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e10dc\n"
        "movw $0, 0xc(%esi, %ebx, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %ebx, 4)\n" /* line 164 | tree */
        "je .Lfe1074_000e139d\n"
        "movl -0x64(%ebp), %edi\n" /* line 166 | surf */
        "addl $2, %edi\n" /* surf */
        "movl %edi, %eax\n" /* line 167 | surf */
        "movzbl -0x5c(%ebp), %ecx\n" /* levelsToLeaf */
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* surf */
        "movl 0xc(%eax), %ecx\n" /* line 168 */
        "cmpl %eax, (%ecx)\n" /* line 172 */
        "je .Lfe1074_000e1581\n"
        "movl %ecx, %edx\n" /* line 175 | nodeIndex */
        "movl $0, -0x50(%ebp)\n" /* lodLevel */
        ".Lfe1074_000e124e:\n"
        "addl $1, -0x50(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x50(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e126d\n"
        "movl 4(%edx), %eax\n" /* line 172 | nodeIndex */
        "addl $4, %edx\n" /* nodeIndex */
        "cmpl -0x54(%ebp), %eax\n" /* surf */
        "jne .Lfe1074_000e124e\n"
        ".Lfe1074_000e1263:\n"
        "movl -0x50(%ebp), %eax\n" /* line 174 | lodLevel */
        "movl $0, (%ecx, %eax, 4)\n"
        ".Lfe1074_000e126d:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 178 */
        "addl $7, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* nodeIndex */
        "subl %eax, 0xc430(%edx)\n" /* nodeIndex */
        "movl -0x54(%ebp), %ecx\n" /* line 179 | surf */
        "movl 8(%ecx), %eax\n"
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%edx)\n" /* nodeIndex */
        "movb $0, 0xe(%esi, %ebx, 4)\n" /* line 181 | tree */
        "jmp .Lfe1074_000e10fe\n"
        /* } scope */
        /* } scope */
        ".Lfe1074_000e129d:\n"
        "leal 1(%edx), %eax\n" /* line 167 | nodeIndex */
        "movl %edi, %ecx\n" /* surf */
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %ebx\n" /* staticSurf */
        "movl 0xc(%ebx), %eax\n" /* line 168 | staticSurf */
        "movl %eax, -0x20(%ebp)\n"
        "cmpl %ebx, (%eax)\n" /* line 172 | staticSurf */
        "je .Lfe1074_000e1575\n"
        "movl %eax, %ecx\n"
        "movl $0, -0x60(%ebp)\n" /* line 175 | lodLevel */
        ".Lfe1074_000e12c2:\n"
        "addl $1, -0x60(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x60(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e12e3\n"
        "movl 4(%ecx), %eax\n" /* line 172 */
        "addl $4, %ecx\n"
        "cmpl %ebx, %eax\n" /* staticSurf */
        "jne .Lfe1074_000e12c2\n"
        ".Lfe1074_000e12d6:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 174 | lodLevel */
        "movl -0x20(%ebp), %eax\n"
        "movl $0, (%eax, %ecx, 4)\n"
        ".Lfe1074_000e12e3:\n"
        "leal 5(%edi), %ecx\n" /* line 178 | surf */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        ".Lfe1074_000e12e6:\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %ecx\n"
        "subl %eax, 0xc430(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 179 | staticSurf */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%ecx)\n"
        "movb $0, 0xe(%esi, %edx, 4)\n" /* line 181 | tree */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 187 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: lodLevel, levelsToLeaf */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        ".Lfe1074_000e1310:\n"
        "movw $0, 0xc(%esi, %ecx, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %ecx, 4)\n" /* line 164 | tree */
        "je .Lfe1074_000e1533\n"
        "movl -0x40(%ebp), %ebx\n" /* line 166 | staticSurf */
        "addl $2, %ebx\n" /* staticSurf */
        "movl %ebx, %eax\n" /* line 167 | staticSurf */
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %edi\n" /* surf */
        "movl 0xc(%edi), %eax\n" /* line 168 | surf */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl (%eax), %edi\n" /* line 172 | surf */
        "je .Lfe1074_000e1569\n"
        "movl %eax, %edx\n" /* nodeIndex */
        "movl $0, -0x38(%ebp)\n" /* line 175 | lodLevel */
        ".Lfe1074_000e134e:\n"
        "addl $1, -0x38(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x38(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e136f\n"
        "movl 4(%edx), %eax\n" /* line 172 | nodeIndex */
        "addl $4, %edx\n" /* nodeIndex */
        "cmpl %eax, %edi\n" /* surf */
        "jne .Lfe1074_000e134e\n"
        ".Lfe1074_000e1362:\n"
        "movl -0x38(%ebp), %edx\n" /* line 174 | lodLevel, nodeIndex */
        "movl -0x1c(%ebp), %ecx\n"
        "movl $0, (%ecx, %edx, 4)\n"
        ".Lfe1074_000e136f:\n"
        "movl $1, %eax\n" /* line 178 */
        "movzbl -0x24(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* nodeIndex */
        "subl %eax, 0xc430(%edx)\n" /* nodeIndex */
        "movl 8(%edi), %eax\n" /* line 179 | surf */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%edx)\n" /* nodeIndex */
        "movl -0x6c(%ebp), %ecx\n" /* line 181 | nodeIndex */
        "movb $0, 0xe(%esi, %ecx, 4)\n" /* tree */
        "jmp .Lfe1074_000e1157\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e139d:\n"
        "addl %ebx, %ebx\n" /* line 185 | nodeIndex */
        "movl %ebx, -0x58(%ebp)\n" /* nodeIndex */
        "movl %ebx, %eax\n" /* nodeIndex */
        "addl $1, %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* nodeIndex */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        "cmpw $0, 0xc(%esi, %eax, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e14d9\n"
        "movw $0, 0xc(%esi, %eax, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %eax, 4)\n" /* line 164 | tree */
        "je .Lfe1074_000e158d\n"
        "movl -0x58(%ebp), %edi\n" /* line 166 | surf */
        "addl $2, %edi\n" /* surf */
        "movl %edi, %eax\n" /* line 167 | surf */
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %ebx\n" /* staticSurf */
        "movl 0xc(%ebx), %eax\n" /* line 168 | staticSurf */
        "movl %eax, -0x48(%ebp)\n" /* staticSurf */
        "cmpl %ebx, (%eax)\n" /* line 172 | staticSurf */
        "je .Lfe1074_000e1603\n"
        "movl %eax, %edx\n" /* nodeIndex */
        "movl $0, -0x4c(%ebp)\n" /* line 175 | lodLevel */
        ".Lfe1074_000e13f4:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x4c(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e1415\n"
        "movl 4(%edx), %eax\n" /* line 172 | nodeIndex */
        "addl $4, %edx\n" /* nodeIndex */
        "cmpl %ebx, %eax\n" /* staticSurf */
        "jne .Lfe1074_000e13f4\n"
        ".Lfe1074_000e1408:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 174 | lodLevel, nodeIndex */
        "movl -0x48(%ebp), %ecx\n" /* staticSurf */
        "movl $0, (%ecx, %edx, 4)\n"
        ".Lfe1074_000e1415:\n"
        "movl $1, %eax\n" /* line 178 */
        "movzbl -0x24(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* nodeIndex */
        "subl %eax, 0xc430(%edx)\n" /* nodeIndex */
        "movl 8(%ebx), %eax\n" /* line 179 | staticSurf */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%edx)\n" /* nodeIndex */
        "movl -0x6c(%ebp), %ecx\n" /* line 181 | nodeIndex */
        "movb $0, 0xe(%esi, %ecx, 4)\n" /* tree */
        /* } scope */
        /* } scope */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        "cmpw $0, 0xc(%esi, %edi, 4)\n" /* line 155 | tree */
        "je .Lfe1074_000e1507\n"
        ".Lfe1074_000e144a:\n"
        "movw $0, 0xc(%esi, %edi, 4)\n" /* line 162 | tree */
        "cmpb $0, 0xe(%esi, %edi, 4)\n" /* line 164 | tree */
        "je .Lfe1074_000e15c3\n"
        "movl -0x58(%ebp), %eax\n" /* line 167 */
        "addl $3, %eax\n"
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* nodeIndex */
        "movl 0xc(%eax), %ebx\n" /* line 168 | staticSurf */
        "cmpl %eax, (%ebx)\n" /* line 172 | staticSurf */
        "je .Lfe1074_000e15f7\n"
        "movl %ebx, %edx\n" /* line 175 | staticSurf, nodeIndex */
        "movl $0, -0x44(%ebp)\n" /* lodLevel */
        ".Lfe1074_000e1486:\n"
        "addl $1, -0x44(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x44(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e14a5\n"
        "movl 4(%edx), %eax\n" /* line 172 | nodeIndex */
        "addl $4, %edx\n" /* nodeIndex */
        "cmpl -0x6c(%ebp), %eax\n" /* nodeIndex */
        "jne .Lfe1074_000e1486\n"
        ".Lfe1074_000e149b:\n"
        "movl -0x44(%ebp), %eax\n" /* line 174 | lodLevel */
        "movl $0, (%ebx, %eax, 4)\n" /* staticSurf */
        ".Lfe1074_000e14a5:\n"
        "movl $1, %eax\n" /* line 178 */
        "movzbl -0x24(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* nodeIndex */
        "subl %eax, 0xc430(%edx)\n" /* nodeIndex */
        "movl -0x6c(%ebp), %ecx\n" /* line 179 | nodeIndex */
        "movl 8(%ecx), %eax\n"
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%edx)\n" /* nodeIndex */
        "movb $0, 0xe(%esi, %edi, 4)\n" /* line 181 | tree */
        "movl -0x64(%ebp), %edi\n" /* surf */
        "addl $2, %edi\n" /* surf */
        "jmp .Lfe1074_000e10fe\n"
        /* } scope */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        ".Lfe1074_000e14d9:\n"
        "movl %ebx, %edi\n" /* line 157 | staticSurf, surf */
        "addl $2, %edi\n" /* surf */
        "movl %edi, %eax\n" /* line 158 | surf */
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x80(%eax, %esi), %eax\n"
        "movl 0xc(%eax), %ecx\n" /* line 134 */
        "movl 8(%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        /* } scope */
        /* } scope */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        ".Lfe1074_000e14fb:\n"
        "cmpw $0, 0xc(%esi, %edi, 4)\n" /* line 155 | tree */
        "jne .Lfe1074_000e144a\n"
        ".Lfe1074_000e1507:\n"
        "movl -0x58(%ebp), %eax\n" /* line 158 */
        "addl $3, %eax\n"
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x80(%eax, %esi), %eax\n"
        "movl 0xc(%eax), %ecx\n" /* line 134 */
        "movl 8(%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl 8(%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        "movl -0x64(%ebp), %edi\n"
        "addl $2, %edi\n"
        "jmp .Lfe1074_000e10fe\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        ".Lfe1074_000e1533:\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 185 | nodeIndex */
        "addl %ebx, %ebx\n" /* nodeIndex */
        "leal 1(%ebx), %ecx\n" /* nodeIndex */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 2(%ebx), %ecx\n" /* line 186 | nodeIndex */
        "movl -0x2c(%ebp), %edx\n" /* nodeIndex */
        "movl %edx, (%esp)\n" /* nodeIndex */
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl -0x40(%ebp), %ebx\n" /* nodeIndex */
        "addl $2, %ebx\n" /* nodeIndex */
        "jmp .Lfe1074_000e1157\n"
        ".Lfe1074_000e1569:\n"
        "movl $0, -0x38(%ebp)\n" /* line 173 | lodLevel */
        "jmp .Lfe1074_000e1362\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfe1074_000e1575:\n"
        "movl $0, -0x60(%ebp)\n" /* lodLevel */
        "jmp .Lfe1074_000e12d6\n"
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e1581:\n"
        "movl $0, -0x50(%ebp)\n" /* lodLevel */
        "jmp .Lfe1074_000e1263\n"
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        ".Lfe1074_000e158d:\n"
        "movl -0x6c(%ebp), %ebx\n" /* line 185 | nodeIndex */
        "addl %ebx, %ebx\n" /* nodeIndex */
        "leal 1(%ebx), %ecx\n" /* nodeIndex */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 2(%ebx), %ecx\n" /* line 186 | nodeIndex */
        "movl -0x2c(%ebp), %edx\n" /* nodeIndex */
        "movl %edx, (%esp)\n" /* nodeIndex */
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl -0x58(%ebp), %edi\n" /* surf */
        "addl $2, %edi\n" /* surf */
        "jmp .Lfe1074_000e14fb\n"
        /* } scope */
        /* } scope */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        ".Lfe1074_000e15c3:\n"
        "leal (%edi, %edi), %ebx\n" /* line 185 | surf, nodeIndex */
        "leal 1(%ebx), %ecx\n" /* nodeIndex */
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 2(%ebx), %ecx\n" /* line 186 | nodeIndex */
        "movl -0x2c(%ebp), %edx\n" /* nodeIndex */
        "movl %edx, (%esp)\n" /* nodeIndex */
        "movl %esi, %edx\n" /* tree, nodeIndex */
        "movl -0x68(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl -0x64(%ebp), %edi\n" /* surf */
        "addl $2, %edi\n" /* surf */
        "jmp .Lfe1074_000e10fe\n"
        ".Lfe1074_000e15f7:\n"
        "movl $0, -0x44(%ebp)\n" /* line 173 | lodLevel */
        "jmp .Lfe1074_000e149b\n"
        /* } scope */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        ".Lfe1074_000e1603:\n"
        "movl $0, -0x4c(%ebp)\n" /* lodLevel */
        "jmp .Lfe1074_000e1408\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: surf, lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e160f:\n"
        "movl -0x64(%ebp), %eax\n" /* line 158 */
        "addl $3, %eax\n"
        "movzbl -0x5c(%ebp), %ecx\n" /* levelsToLeaf */
        "jmp .Lfe1074_000e1094\n"
        ".Lfe1074_000e161e:\n"
        "movl -0x64(%ebp), %eax\n" /* line 167 */
        "addl $3, %eax\n"
        "movzbl -0x5c(%ebp), %ecx\n" /* levelsToLeaf */
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %ebx\n" /* staticSurf */
        "movl 0xc(%ebx), %ecx\n" /* line 168 | staticSurf */
        "cmpl (%ecx), %ebx\n" /* line 172 | staticSurf */
        "je .Lfe1074_000e1772\n"
        "movl %ecx, %edx\n" /* line 175 | nodeIndex */
        "movl $0, -0x3c(%ebp)\n" /* lodLevel */
        ".Lfe1074_000e1645:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x3c(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e1663\n"
        "movl 4(%edx), %eax\n" /* line 172 | nodeIndex */
        "addl $4, %edx\n" /* nodeIndex */
        "cmpl %eax, %ebx\n" /* staticSurf */
        "jne .Lfe1074_000e1645\n"
        ".Lfe1074_000e1659:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 174 | lodLevel */
        "movl $0, (%ecx, %eax, 4)\n"
        ".Lfe1074_000e1663:\n"
        "movl -0x5c(%ebp), %ecx\n" /* line 178 | levelsToLeaf */
        "addl $5, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* nodeIndex */
        "subl %eax, 0xc430(%edx)\n" /* nodeIndex */
        "movl 8(%ebx), %eax\n" /* line 179 | staticSurf */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%edx)\n" /* nodeIndex */
        "movb $0, 0xe(%esi, %edi, 4)\n" /* line 181 | tree */
        "jmp .Lfe1074_000e10ab\n"
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        ".Lfe1074_000e1690:\n"
        "movl -0x40(%ebp), %eax\n" /* line 158 */
        "addl $3, %eax\n"
        "movzbl -0x28(%ebp), %ecx\n"
        "jmp .Lfe1074_000e1094\n"
        ".Lfe1074_000e169f:\n"
        "movl -0x40(%ebp), %eax\n" /* line 167 */
        "addl $3, %eax\n"
        "movzbl -0x28(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %edi\n" /* surf */
        "movl 0xc(%edi), %ecx\n" /* line 168 | surf */
        "cmpl (%ecx), %edi\n" /* line 172 | surf */
        "je .Lfe1074_000e1766\n"
        "movl %ecx, %edx\n" /* line 175 | nodeIndex */
        "movl $0, -0x34(%ebp)\n" /* lodLevel */
        ".Lfe1074_000e16c6:\n"
        "addl $1, -0x34(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x34(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e16e4\n"
        "movl 4(%edx), %eax\n" /* line 172 | nodeIndex */
        "addl $4, %edx\n" /* nodeIndex */
        "cmpl %eax, %edi\n" /* surf */
        "jne .Lfe1074_000e16c6\n"
        ".Lfe1074_000e16da:\n"
        "movl -0x34(%ebp), %eax\n" /* line 174 | lodLevel */
        "movl $0, (%ecx, %eax, 4)\n"
        ".Lfe1074_000e16e4:\n"
        "movl -0x28(%ebp), %ecx\n" /* line 178 */
        "addl $5, %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* nodeIndex */
        "subl %eax, 0xc430(%edx)\n" /* nodeIndex */
        "movl 8(%edi), %eax\n" /* line 179 | surf */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc434(%edx)\n" /* nodeIndex */
        "movb $0, 0xe(%esi, %ebx, 4)\n" /* line 181 | tree */
        "jmp .Lfe1074_000e10ab\n"
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        ".Lfe1074_000e1711:\n"
        "leal 3(%ebx), %eax\n" /* line 158 | staticSurf */
        "movzbl -0x2c(%ebp), %ecx\n"
        "jmp .Lfe1074_000e1094\n"
        ".Lfe1074_000e171d:\n"
        "leal 3(%ebx), %eax\n" /* line 167 | staticSurf */
        "movzbl -0x2c(%ebp), %ecx\n"
        "shll %cl, %eax\n"
        "shll $4, %eax\n"
        "leal -0x78(%eax, %esi), %ebx\n" /* staticSurf */
        "movl 0xc(%ebx), %edi\n" /* line 168 | staticSurf, surf */
        "cmpl (%edi), %ebx\n" /* line 172 | surf, staticSurf */
        "je .Lfe1074_000e177e\n"
        "movl %edi, %ecx\n" /* line 175 | surf */
        "movl $0, -0x30(%ebp)\n" /* lodLevel */
        ".Lfe1074_000e173d:\n"
        "addl $1, -0x30(%ebp)\n" /* line 170 | lodLevel */
        "cmpl $4, -0x30(%ebp)\n" /* lodLevel */
        "je .Lfe1074_000e175b\n"
        "movl 4(%ecx), %eax\n" /* line 172 */
        "addl $4, %ecx\n"
        "cmpl %eax, %ebx\n" /* staticSurf */
        "jne .Lfe1074_000e173d\n"
        ".Lfe1074_000e1751:\n"
        "movl -0x30(%ebp), %eax\n" /* line 174 | lodLevel */
        "movl $0, (%edi, %eax, 4)\n" /* surf */
        ".Lfe1074_000e175b:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 178 */
        "addl $5, %ecx\n"
        "jmp .Lfe1074_000e12e6\n"
        /* } scope */
        /* } scope */
        ".Lfe1074_000e1766:\n"
        "movl $0, -0x34(%ebp)\n" /* line 173 | lodLevel */
        "jmp .Lfe1074_000e16da\n"
        /* } scope */
        ".Lfe1074_000e1772:\n"
        "movl $0, -0x3c(%ebp)\n" /* lodLevel */
        "jmp .Lfe1074_000e1659\n"
        /* { scope 3: lodLevel, nodeIndex, lodLevel */
        /* { scope 4: lodLevel, lodLevel, staticSurf */
        /* { scope 5 */
        ".Lfe1074_000e177e:\n"
        "movl $0, -0x30(%ebp)\n" /* lodLevel */
        "jmp .Lfe1074_000e1751\n"
    );
}

/* line 827 */
__attribute__((naked))
void R_StaticModelCacheFlush_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 827 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc949ac, %ebx\n" /* line 791 */
        "testl %ebx, %ebx\n"
        "jne .Lfe1788_000e17ee\n"
        "jmp .Lfe1788_000e18e6\n"
        ".Lfe1788_000e17a0:\n"
        "leal 0x88(%ebx), %esi\n" /* line 158 */
        "movl 4(%esi), %eax\n" /* line 134 */
        "movl 0x88(%ebx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0x88(%ebx), %edx\n" /* line 135 */
        "movl %eax, 4(%edx)\n"
        ".Lfe1788_000e17ba:\n"
        "movl 0xc949ac, %eax\n" /* line 802 */
        "movl 4(%eax), %ecx\n" /* line 134 */
        "movl (%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl (%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        "movl $0xc94980, 0x88(%ebx)\n" /* line 125 */
        "movl 0xc94984, %eax\n" /* line 126 */
        "movl %eax, 4(%esi)\n"
        "movl %esi, 0xc94984\n" /* line 127 */
        "movl 4(%esi), %eax\n" /* line 128 */
        "movl %esi, (%eax)\n"
        "movl 0xc949ac, %ebx\n" /* line 797 */
        ".Lfe1788_000e17ee:\n"
        "cmpl $0xc949a8, %ebx\n"
        "je .Lfe1788_000e185b\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 155 */
        "je .Lfe1788_000e17a0\n"
        "movw $0, 0xc(%ebx)\n" /* line 162 */
        "cmpb $0, 0xe(%ebx)\n" /* line 164 */
        "je .Lfe1788_000e18ee\n"
        "leal 0x88(%ebx), %esi\n" /* line 167 */
        "movl 0xc(%esi), %ecx\n" /* line 168 */
        "cmpl %esi, (%ecx)\n" /* line 172 */
        "je .Lfe1788_000e1929\n"
        "movl %ecx, %edx\n" /* line 175 */
        "xorl %edi, %edi\n"
        ".Lfe1788_000e1822:\n"
        "addl $1, %edi\n" /* line 170 */
        "cmpl $4, %edi\n"
        "je .Lfe1788_000e183b\n"
        "movl 4(%edx), %eax\n" /* line 172 */
        "addl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lfe1788_000e1822\n"
        ".Lfe1788_000e1834:\n"
        "movl $0, (%ecx, %edi, 4)\n" /* line 174 */
        ".Lfe1788_000e183b:\n"
        "subl $0x200, 0xc949b0\n" /* line 178 */
        "movl 8(%esi), %eax\n" /* line 179 */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc949b4\n"
        "movb $0, 0xe(%ebx)\n" /* line 181 */
        "jmp .Lfe1788_000e17ba\n"
        ".Lfe1788_000e185b:\n"
        "movl $0xc438, 8(%esp)\n" /* line 758 */
        "movl $0, 4(%esp)\n"
        "movl $s_cache, (%esp)\n"
        "calll memset\n"
        "movl $0xc949a8, 0xc949a8\n" /* line 760 */
        "movl $0xc949a8, 0xc949ac\n" /* line 761 */
        "xorl %ecx, %ecx\n"
        "movl $s_cache, %edx\n"
        "movl $0xc94980, %eax\n"
        ".Lfe1788_000e1897:\n"
        "movl %eax, 0xc400(%edx)\n" /* line 765 */
        "movl %eax, 0xc404(%edx)\n" /* line 766 */
        "addl $1, %ecx\n" /* line 763 */
        "addl $8, %eax\n"
        "addl $8, %edx\n"
        "cmpl $5, %ecx\n"
        "jne .Lfe1788_000e1897\n"
        "xorl %ebx, %ebx\n"
        "movl $0xc88600, %ecx\n"
        ".Lfe1788_000e18b8:\n"
        "leal 8(%ecx), %eax\n" /* line 770 */
        "movl $0xc94980, 8(%ecx)\n" /* line 125 */
        "movl 0xc94984, %edx\n" /* line 126 */
        "movl %edx, 0xc(%ecx)\n"
        "movl %eax, 0xc94984\n" /* line 127 */
        "movl 0xc(%ecx), %edx\n" /* line 128 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* line 769 */
        "addl $0x188, %ecx\n"
        "cmpl $0x80, %ebx\n"
        "jne .Lfe1788_000e18b8\n"
        ".Lfe1788_000e18e6:\n"
        "addl $0x1c, %esp\n" /* line 830 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe1788_000e18ee:\n"
        "movl $3, (%esp)\n" /* line 185 */
        "movl $1, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $s_cache, %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl $3, (%esp)\n" /* line 186 */
        "movl $2, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $s_cache, %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 0x88(%ebx), %esi\n"
        "jmp .Lfe1788_000e17ba\n"
        ".Lfe1788_000e1929:\n"
        "xorl %edi, %edi\n" /* line 173 */
        "jmp .Lfe1788_000e1834\n"
    );
}

/* line 810 */
__attribute__((naked))
void R_ShutdownStaticModelCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 810 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc949ac, %ebx\n" /* line 791 */
        "testl %ebx, %ebx\n"
        "jne .Lfe1930_000e1996\n"
        "jmp .Lfe1930_000e1a92\n"
        ".Lfe1930_000e1948:\n"
        "leal 0x88(%ebx), %esi\n" /* line 158 */
        "movl 4(%esi), %eax\n" /* line 134 */
        "movl 0x88(%ebx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0x88(%ebx), %edx\n" /* line 135 */
        "movl %eax, 4(%edx)\n"
        ".Lfe1930_000e1962:\n"
        "movl 0xc949ac, %eax\n" /* line 802 */
        "movl 4(%eax), %ecx\n" /* line 134 */
        "movl (%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl (%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        "movl $0xc94980, 0x88(%ebx)\n" /* line 125 */
        "movl 0xc94984, %eax\n" /* line 126 */
        "movl %eax, 4(%esi)\n"
        "movl %esi, 0xc94984\n" /* line 127 */
        "movl 4(%esi), %eax\n" /* line 128 */
        "movl %esi, (%eax)\n"
        "movl 0xc949ac, %ebx\n" /* line 797 */
        ".Lfe1930_000e1996:\n"
        "cmpl $0xc949a8, %ebx\n"
        "je .Lfe1930_000e1a03\n"
        "cmpw $0, 0xc(%ebx)\n" /* line 155 */
        "je .Lfe1930_000e1948\n"
        "movw $0, 0xc(%ebx)\n" /* line 162 */
        "cmpb $0, 0xe(%ebx)\n" /* line 164 */
        "je .Lfe1930_000e1ad4\n"
        "leal 0x88(%ebx), %esi\n" /* line 167 */
        "movl 0xc(%esi), %ecx\n" /* line 168 */
        "cmpl %esi, (%ecx)\n" /* line 172 */
        "je .Lfe1930_000e1b0f\n"
        "movl %ecx, %edx\n" /* line 175 */
        "xorl %edi, %edi\n"
        ".Lfe1930_000e19ca:\n"
        "addl $1, %edi\n" /* line 170 */
        "cmpl $4, %edi\n"
        "je .Lfe1930_000e19e3\n"
        "movl 4(%edx), %eax\n" /* line 172 */
        "addl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lfe1930_000e19ca\n"
        ".Lfe1930_000e19dc:\n"
        "movl $0, (%ecx, %edi, 4)\n" /* line 174 */
        ".Lfe1930_000e19e3:\n"
        "subl $0x200, 0xc949b0\n" /* line 178 */
        "movl 8(%esi), %eax\n" /* line 179 */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc949b4\n"
        "movb $0, 0xe(%ebx)\n" /* line 181 */
        "jmp .Lfe1930_000e1962\n"
        ".Lfe1930_000e1a03:\n"
        "movl $0xc438, 8(%esp)\n" /* line 758 */
        "movl $0, 4(%esp)\n"
        "movl $s_cache, (%esp)\n"
        "calll memset\n"
        "movl $0xc949a8, 0xc949a8\n" /* line 760 */
        "movl $0xc949a8, 0xc949ac\n" /* line 761 */
        "xorl %ecx, %ecx\n"
        "movl $s_cache, %edx\n"
        "movl $0xc94980, %eax\n"
        ".Lfe1930_000e1a3f:\n"
        "movl %eax, 0xc400(%edx)\n" /* line 765 */
        "movl %eax, 0xc404(%edx)\n" /* line 766 */
        "addl $1, %ecx\n" /* line 763 */
        "addl $8, %eax\n"
        "addl $8, %edx\n"
        "cmpl $5, %ecx\n"
        "jne .Lfe1930_000e1a3f\n"
        "xorl %ebx, %ebx\n"
        "movl $0xc88600, %ecx\n"
        "movl 0xc94984, %edx\n"
        "jmp .Lfe1930_000e1a6a\n"
        ".Lfe1930_000e1a68:\n"
        "movl %eax, %edx\n"
        ".Lfe1930_000e1a6a:\n"
        "leal 8(%ecx), %eax\n" /* line 770 */
        "movl $0xc94980, 8(%ecx)\n" /* line 125 */
        "movl %edx, 0xc(%ecx)\n" /* line 126 */
        "movl %eax, 0xc94984\n" /* line 127 */
        "movl 0xc(%ecx), %edx\n" /* line 128 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* line 769 */
        "addl $0x188, %ecx\n"
        "cmpl $0x80, %ebx\n"
        "jne .Lfe1930_000e1a68\n"
        ".Lfe1930_000e1a92:\n"
        "movl 0x195eed0, %ebx\n" /* line 813 */
        "movl 0x2dc4(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfe1930_000e1acc\n"
        "movl 0x195f0e0, %edi\n"
        "movl %ebx, %esi\n"
        "jmp .Lfe1930_000e1aae\n"
        ".Lfe1930_000e1aac:\n"
        "movl %esi, %ebx\n" /* line 814 */
        ".Lfe1930_000e1aae:\n"
        "movl 0x2dc4(%ebx), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, 0x2dc4(%ebx)\n"
        "movl (%edi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfe1930_000e1aac\n"
        ".Lfe1930_000e1acc:\n"
        "addl $0x1c, %esp\n" /* line 815 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe1930_000e1ad4:\n"
        "movl $3, (%esp)\n" /* line 185 */
        "movl $1, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $s_cache, %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl $3, (%esp)\n" /* line 186 */
        "movl $2, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $s_cache, %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 0x88(%ebx), %esi\n"
        "jmp .Lfe1930_000e1962\n"
        ".Lfe1930_000e1b0f:\n"
        "xorl %edi, %edi\n" /* line 173 */
        "jmp .Lfe1930_000e19dc\n"
    );
}

/* line 220 */
static __attribute__((naked))
Bool SMC_GetFreeBlockOfSize(static_model_cache_t *cache, int listIndex)
{
    __asm__ __volatile__ (
        ".Lfe1b16_000e1b16:\n"
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, -0x20(%ebp)\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 232 */
        "jne .Lfe1b16_000e1bb7\n"
        "movl 0xc428(%eax), %ebx\n" /* line 197 */
        "movl 0x195eef4, %eax\n" /* line 203 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "subl 8(%ebx), %eax\n"
        "cmpl $2, %eax\n"
        "jle .Lfe1b16_000e1c6f\n"
        /* { scope 2 */
        /* { scope 3 */
        "cmpw $0, 0xc(%ebx)\n" /* line 155 */
        "je .Lfe1b16_000e1c7c\n"
        "movw $0, 0xc(%ebx)\n" /* line 162 */
        "cmpb $0, 0xe(%ebx)\n" /* line 164 */
        "je .Lfe1b16_000e1cfc\n"
        "leal 0x88(%ebx), %ecx\n" /* line 167 */
        "movl 0xc(%ecx), %esi\n" /* line 168 */
        "cmpl %ecx, (%esi)\n" /* line 172 */
        "je .Lfe1b16_000e1d33\n"
        "movl %esi, %edx\n" /* line 175 */
        "xorl %edi, %edi\n" /* lodLevel */
        ".Lfe1b16_000e1b78:\n"
        "addl $1, %edi\n" /* line 170 | lodLevel */
        "cmpl $4, %edi\n" /* lodLevel */
        "je .Lfe1b16_000e1b91\n"
        "movl 4(%edx), %eax\n" /* line 172 */
        "addl $4, %edx\n"
        "cmpl %ecx, %eax\n"
        "jne .Lfe1b16_000e1b78\n"
        ".Lfe1b16_000e1b8a:\n"
        "movl $0, (%esi, %edi, 4)\n" /* line 174 */
        ".Lfe1b16_000e1b91:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 178 */
        "subl $0x200, 0xc430(%eax)\n"
        "movl 8(%ecx), %eax\n" /* line 179 */
        "movswl 2(%eax), %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "subl %eax, 0xc434(%edx)\n"
        "movb $0, 0xe(%ebx)\n" /* line 181 */
        "jmp .Lfe1b16_000e1c96\n"
        ".Lfe1b16_000e1bb7:\n"
        "movl %edx, %ebx\n"
        /* } scope */
        /* } scope */
        "subl $1, %ebx\n" /* line 235 | tree */
        "movl -0x1c(%ebp), %edx\n"
        "leal 0xc400(%edx, %ebx, 8), %eax\n"
        "cmpl %eax, 0xc404(%edx, %ebx, 8)\n"
        "je .Lfe1b16_000e1ce7\n"
        "movl %edx, %eax\n"
        ".Lfe1b16_000e1bd5:\n"
        "movl 0xc404(%eax, %ebx, 8), %esi\n" /* line 241 | block */
        "movl 4(%esi), %edx\n" /* line 134 */
        "movl (%esi), %eax\n"
        "movl %eax, (%edx)\n"
        "movl (%esi), %eax\n" /* line 135 */
        "movl %edx, 4(%eax)\n"
        "movl %esi, %edx\n" /* line 253 | block */
        "subl -0x1c(%ebp), %edx\n"
        "movl $0x5397829d, %eax\n"
        "mull %edx\n"
        "shrl $7, %edx\n"
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl -0x1c(%ebp), %edx\n"
        "leal (%edx, %eax, 8), %edi\n" /* tree */
        "cmpl $1, -0x20(%ebp)\n" /* line 254 */
        "je .Lfe1b16_000e1cc8\n"
        ".Lfe1b16_000e1c0f:\n"
        "movl -0x20(%ebp), %eax\n" /* line 267 */
        "leal 0xc400(%edx, %eax, 8), %ebx\n" /* list */
        /* { scope 2 */
        "movl %ebx, (%esi)\n" /* line 125 */
        "movl 4(%ebx), %eax\n" /* line 126 */
        "movl %eax, 4(%esi)\n"
        "movl %esi, 4(%ebx)\n" /* line 127 */
        "movl 4(%esi), %eax\n" /* line 128 */
        "movl %esi, (%eax)\n"
        /* } scope */
        "leal 0x88(%edi), %eax\n" /* line 270 | tree */
        "movl %esi, %edx\n" /* block */
        "subl %eax, %edx\n"
        "shrl $4, %edx\n"
        "movl $4, %ecx\n"
        "subl -0x20(%ebp), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "addl %eax, %edx\n"
        "shll $4, %edx\n"
        "leal 0x80(%edx, %edi), %edx\n"
        "leal 8(%edx), %eax\n"
        "movl %ebx, 8(%edx)\n" /* line 125 */
        "movl %esi, 4(%eax)\n" /* line 126 */
        "movl %eax, 4(%ebx)\n" /* line 127 */
        "movl 4(%eax), %edx\n" /* line 128 */
        "movl %eax, (%edx)\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lfe1b16_000e1c67:\n"
        "addl $0x2c, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe1b16_000e1c6f:\n"
        "xorl %eax, %eax\n" /* line 203 */
        "movzbl %al, %eax\n" /* line 233 */
        /* } scope */
        ".Lfe1b16_000e1c74:\n"
        "addl $0x2c, %esp\n" /* line 274 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfe1b16_000e1c7c:\n"
        "leal 0x88(%ebx), %ecx\n" /* line 158 */
        "movl 4(%ecx), %eax\n" /* line 134 */
        "movl 0x88(%ebx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0x88(%ebx), %edx\n" /* line 135 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lfe1b16_000e1c96:\n"
        "movl 4(%ebx), %edx\n" /* line 134 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl (%ebx), %eax\n" /* line 135 */
        "movl %edx, 4(%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 210 | list */
        "addl $0xc400, %eax\n" /* list */
        /* { scope 2 */
        "movl %eax, 0x88(%ebx)\n" /* line 125 */
        "movl 4(%eax), %edx\n" /* line 126 */
        "movl %edx, 4(%ecx)\n"
        "movl %ecx, 4(%eax)\n" /* line 127 */
        "movl 4(%ecx), %eax\n" /* line 128 */
        "movl %ecx, (%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        "movzbl %al, %eax\n" /* line 233 */
        "jmp .Lfe1b16_000e1c74\n"
        ".Lfe1b16_000e1cc8:\n"
        "movl %edx, %eax\n" /* line 255 | list */
        "addl $0xc428, %eax\n" /* list */
        /* { scope 2 */
        "movl %eax, (%edi)\n" /* line 125 */
        "movl 4(%eax), %edx\n" /* line 126 */
        "movl %edx, 4(%edi)\n"
        "movl %edi, 4(%eax)\n" /* line 127 */
        "movl 4(%edi), %eax\n" /* line 128 */
        "movl %edi, (%eax)\n"
        "movl -0x1c(%ebp), %edx\n"
        "jmp .Lfe1b16_000e1c0f\n"
        ".Lfe1b16_000e1ce7:\n"
        "movl %edx, %eax\n"
        /* } scope */
        "movl %ebx, %edx\n" /* line 237 | tree */
        "calll SMC_GetFreeBlockOfSize\n"
        "testb %al, %al\n"
        "je .Lfe1b16_000e1d3a\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lfe1b16_000e1bd5\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfe1b16_000e1cfc:\n"
        "movl $3, (%esp)\n" /* line 185 */
        "movl $1, %ecx\n"
        "movl %ebx, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl $3, (%esp)\n" /* line 186 */
        "movl $2, %ecx\n"
        "movl %ebx, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 0x88(%ebx), %ecx\n"
        "jmp .Lfe1b16_000e1c96\n"
        ".Lfe1b16_000e1d33:\n"
        "xorl %edi, %edi\n" /* line 173 | lodLevel */
        "jmp .Lfe1b16_000e1b8a\n"
        /* } scope */
        /* } scope */
        ".Lfe1b16_000e1d3a:\n"
        "xorl %eax, %eax\n" /* line 237 */
        "jmp .Lfe1b16_000e1c67\n"
    );
}

/* line 661 */
__attribute__((naked))
GfxStaticModelSurfaceCached * R_CacheStaticModelSurface(GfxStaticSurface *staticSurf, const XSurface *xsurf, int smodelIndex, const Material *material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 661 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: index, nodeIndex */
        "movl 0x195eed0, %eax\n" /* line 675 */
        "cmpb $0, 0x2d3c(%eax)\n"
        "je .Lfe1d42_000e1d6b\n"
        /* { scope 2 */
        ".Lfe1d42_000e1d59:\n"
        "movl $0, -0x30(%ebp)\n" /* line 650 | cached */
        /* } scope */
        /* } scope */
        ".Lfe1d42_000e1d60:\n"
        "movl -0x30(%ebp), %eax\n" /* line 710 | cached */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: index, nodeIndex */
        ".Lfe1d42_000e1d6b:\n"
        "movl 0xc(%ebp), %edx\n" /* line 679 | xsurf */
        "movzwl 2(%edx), %eax\n"
        "cmpw $0x200, %ax\n"
        "jg .Lfe1d42_000e1d59\n"
        "cwtl\n" /* line 683 */
        "cmpl $0x20, %eax\n"
        "jg .Lfe1d42_000e1f0d\n"
        "movl $5, %edi\n" /* bitCount */
        "movl $0x20, -0x34(%ebp)\n"
        "movl $4, %ebx\n" /* twoDstIndices */
        /* { scope 2 */
        ".Lfe1d42_000e1d93:\n"
        "leal 0xc94980(, %ebx, 8), %eax\n" /* line 291 */
        "cmpl %eax, 0xc94984(, %ebx, 8)\n"
        "je .Lfe1d42_000e1f32\n"
        ".Lfe1d42_000e1da7:\n"
        "movl 0xc94984(, %ebx, 8), %ecx\n" /* line 299 */
        /* { scope 3 */
        "movl 4(%ecx), %edx\n" /* line 134 */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl (%ecx), %eax\n" /* line 135 */
        "movl %edx, 4(%eax)\n"
        /* } scope */
        "movl %ecx, %edx\n" /* line 304 */
        "subl $s_cache, %edx\n"
        "movl $0x5397829d, %eax\n"
        "mull %edx\n"
        "shrl $7, %edx\n"
        "leal (%edx, %edx, 2), %eax\n" /* line 309 */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "shll $3, %eax\n"
        "leal s_cache(%eax), %esi\n" /* tree */
        "testl %ebx, %ebx\n" /* line 310 */
        "jne .Lfe1d42_000e1dfe\n"
        "movl $0xc949a8, s_cache(%eax)\n" /* line 125 */
        "movl 0xc949ac, %eax\n" /* line 126 */
        "movl %eax, 4(%esi)\n"
        "movl %esi, 0xc949ac\n" /* line 127 */
        "movl 4(%esi), %eax\n" /* line 128 */
        "movl %esi, (%eax)\n"
        ".Lfe1d42_000e1dfe:\n"
        "leal 0x88(%esi), %eax\n" /* line 314 | tree */
        "subl %eax, %ecx\n"
        "shrl $4, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n" /* index */
        "movl %ecx, %eax\n" /* line 323 */
        "addl $0x10, %eax\n"
        "movl $4, %ecx\n"
        "subl %ebx, %ecx\n"
        "sarl %cl, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* nodeIndex */
        "movb $1, 0xe(%esi, %eax, 4)\n" /* line 325 | tree */
        "testl %eax, %eax\n" /* line 327 */
        "js .Lfe1d42_000e1e49\n"
        "movl $1, %eax\n"
        "movl %eax, %ebx\n"
        "movl %edi, %ecx\n"
        "shll %cl, %ebx\n"
        "movl -0x3c(%ebp), %eax\n" /* nodeIndex */
        ".Lfe1d42_000e1e37:\n"
        "addw %bx, 0xc(%esi, %eax, 4)\n" /* line 329 | tree */
        "movl -0x3c(%ebp), %eax\n" /* line 330 | nodeIndex */
        "subl $1, %eax\n"
        "sarl $1, %eax\n" /* line 327 */
        "movl %eax, -0x3c(%ebp)\n" /* nodeIndex */
        "jns .Lfe1d42_000e1e37\n"
        ".Lfe1d42_000e1e49:\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 333 | index */
        "shll $4, %ebx\n"
        "leal 0x80(%ebx, %esi), %ebx\n"
        "leal 8(%ebx), %ecx\n"
        "movl %ecx, -0x30(%ebp)\n" /* cached */
        "shll $4, %edx\n" /* line 334 */
        "addl -0x2c(%ebp), %edx\n" /* index */
        "shll $5, %edx\n"
        "movl %edx, 8(%ebx)\n"
        /* } scope */
        "movl -0x34(%ebp), %eax\n" /* line 692 */
        "addl %eax, 0xc949b0\n"
        "movl 0xc(%ebp), %edx\n" /* line 693 | xsurf */
        "movswl 2(%edx), %eax\n"
        "addl %eax, 0xc949b4\n"
        "movl 8(%ebp), %eax\n" /* line 695 | staticSurf */
        "movl %eax, 0xc(%ecx)\n"
        "movl %edx, 8(%ecx)\n" /* line 696 */
        "movl 0x10(%ebp), %edx\n" /* line 697 | smodelIndex */
        "movl %edx, 4(%ecx)\n"
        "movl %ecx, -0x24(%ebp)\n" /* line 700 | skinSmodelCmd */
        "movl %edx, -0x20(%ebp)\n" /* line 701 */
        "movl 0x14(%ebp), %ecx\n" /* line 703 | material */
        "movl %ecx, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 705 | skinSmodelCmd */
        "movl %eax, 4(%esp)\n"
        "movl $5, (%esp)\n"
        "calll R_AddFrontendCmd\n"
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 638 | cached */
        "movl 8(%eax), %ecx\n"
        "movl 8(%ebx), %eax\n" /* line 639 | twoDstIndices */
        "movl %eax, %edi\n" /* twoBaseOffsets */
        "shll $0x10, %edi\n" /* twoBaseOffsets */
        "orl %eax, %edi\n" /* twoBaseOffsets */
        "movl 8(%ecx), %esi\n" /* line 640 | twoSrcIndices */
        "leal (%eax, %eax, 2), %eax\n" /* line 644 */
        "movl 0x195eed0, %edx\n"
        "movl 0x2dc8(%edx), %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* twoDstIndices */
        "movzwl 4(%ecx), %edx\n" /* line 646 */
        "movl %edx, %eax\n"
        "shrw $0xf, %ax\n"
        "addl %edx, %eax\n"
        "sarw $1, %ax\n"
        "movswl %ax, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lfe1d42_000e1ee5:\n"
        "movl %edi, %eax\n" /* line 652 | twoBaseOffsets */
        "addl (%esi), %eax\n" /* twoSrcIndices */
        "movl %eax, (%ebx)\n" /* twoDstIndices */
        "movl %edi, %eax\n" /* line 653 | twoBaseOffsets */
        "addl 4(%esi), %eax\n" /* twoSrcIndices */
        "movl %eax, 4(%ebx)\n" /* twoDstIndices */
        "movl %edi, %eax\n" /* line 654 | twoBaseOffsets */
        "addl 8(%esi), %eax\n" /* twoSrcIndices */
        "movl %eax, 8(%ebx)\n" /* twoDstIndices */
        "addl $0xc, %ebx\n" /* twoDstIndices */
        "addl $0xc, %esi\n" /* twoSrcIndices */
        "addl $1, %edx\n"
        "cmpl %edx, %ecx\n" /* line 650 */
        "jne .Lfe1d42_000e1ee5\n"
        "jmp .Lfe1d42_000e1d60\n"
        /* } scope */
        ".Lfe1d42_000e1f0d:\n"
        "movl $5, %edi\n" /* line 683 | bitCount */
        ".Lfe1d42_000e1f12:\n"
        "addl $1, %edi\n" /* line 684 | bitCount */
        "movl $1, -0x34(%ebp)\n" /* line 683 */
        "movl %edi, %ecx\n" /* bitCount */
        "shll %cl, -0x34(%ebp)\n"
        "cmpl -0x34(%ebp), %eax\n"
        "jg .Lfe1d42_000e1f12\n"
        "movl $9, %ebx\n" /* twoDstIndices */
        "subl %edi, %ebx\n" /* bitCount, twoDstIndices */
        "jmp .Lfe1d42_000e1d93\n"
        /* { scope 2 */
        ".Lfe1d42_000e1f32:\n"
        "movl %ebx, %edx\n" /* line 294 */
        "movl $s_cache, %eax\n"
        "calll SMC_GetFreeBlockOfSize\n"
        "testb %al, %al\n"
        "jne .Lfe1d42_000e1da7\n"
        "jmp .Lfe1d42_000e1d59\n"
    );
}

/* line 787 */
__attribute__((naked))
void R_FlushStaticModelCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 787 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc949ac, %ebx\n" /* line 791 */
        "testl %ebx, %ebx\n"
        "jne .Lfe1f4c_000e1fb2\n"
        "jmp .Lfe1f4c_000e20aa\n"
        /* { scope 1 */
        ".Lfe1f4c_000e1f64:\n"
        "leal 0x88(%ebx), %esi\n" /* line 158 */
        "movl 4(%esi), %eax\n" /* line 134 */
        "movl 0x88(%ebx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 0x88(%ebx), %edx\n" /* line 135 */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        ".Lfe1f4c_000e1f7e:\n"
        "movl 0xc949ac, %eax\n" /* line 802 | node */
        /* { scope 1 */
        "movl 4(%eax), %ecx\n" /* line 134 */
        "movl (%eax), %edx\n"
        "movl %edx, (%ecx)\n"
        "movl (%eax), %eax\n" /* line 135 */
        "movl %ecx, 4(%eax)\n"
        /* } scope */
        "movl $0xc94980, 0x88(%ebx)\n" /* line 125 */
        "movl 0xc94984, %eax\n" /* line 126 */
        "movl %eax, 4(%esi)\n"
        "movl %esi, 0xc94984\n" /* line 127 */
        "movl 4(%esi), %eax\n" /* line 128 */
        "movl %esi, (%eax)\n"
        "movl 0xc949ac, %ebx\n" /* line 797 */
        ".Lfe1f4c_000e1fb2:\n"
        "cmpl $0xc949a8, %ebx\n"
        "je .Lfe1f4c_000e201f\n"
        /* { scope 1 */
        "cmpw $0, 0xc(%ebx)\n" /* line 155 */
        "je .Lfe1f4c_000e1f64\n"
        "movw $0, 0xc(%ebx)\n" /* line 162 */
        "cmpb $0, 0xe(%ebx)\n" /* line 164 */
        "je .Lfe1f4c_000e20b2\n"
        "leal 0x88(%ebx), %esi\n" /* line 167 */
        "movl 0xc(%esi), %ecx\n" /* line 168 */
        "cmpl %esi, (%ecx)\n" /* line 172 */
        "je .Lfe1f4c_000e20ed\n"
        "movl %ecx, %edx\n" /* line 175 */
        "xorl %edi, %edi\n" /* lodLevel */
        ".Lfe1f4c_000e1fe6:\n"
        "addl $1, %edi\n" /* line 170 | lodLevel */
        "cmpl $4, %edi\n" /* lodLevel */
        "je .Lfe1f4c_000e1fff\n"
        "movl 4(%edx), %eax\n" /* line 172 */
        "addl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lfe1f4c_000e1fe6\n"
        ".Lfe1f4c_000e1ff8:\n"
        "movl $0, (%ecx, %edi, 4)\n" /* line 174 */
        ".Lfe1f4c_000e1fff:\n"
        "subl $0x200, 0xc949b0\n" /* line 178 */
        "movl 8(%esi), %eax\n" /* line 179 */
        "movswl 2(%eax), %eax\n"
        "subl %eax, 0xc949b4\n"
        "movb $0, 0xe(%ebx)\n" /* line 181 */
        "jmp .Lfe1f4c_000e1f7e\n"
        /* } scope */
        ".Lfe1f4c_000e201f:\n"
        "movl $0xc438, 8(%esp)\n" /* line 758 */
        "movl $0, 4(%esp)\n"
        "movl $s_cache, (%esp)\n"
        "calll memset\n"
        "movl $0xc949a8, 0xc949a8\n" /* line 760 */
        "movl $0xc949a8, 0xc949ac\n" /* line 761 */
        "xorl %ecx, %ecx\n"
        "movl $s_cache, %edx\n"
        "movl $0xc94980, %eax\n"
        ".Lfe1f4c_000e205b:\n"
        "movl %eax, 0xc400(%edx)\n" /* line 765 */
        "movl %eax, 0xc404(%edx)\n" /* line 766 */
        "addl $1, %ecx\n" /* line 763 */
        "addl $8, %eax\n"
        "addl $8, %edx\n"
        "cmpl $5, %ecx\n"
        "jne .Lfe1f4c_000e205b\n"
        "xorl %ebx, %ebx\n"
        "movl $0xc88600, %ecx\n"
        ".Lfe1f4c_000e207c:\n"
        "leal 8(%ecx), %eax\n" /* line 770 */
        "movl $0xc94980, 8(%ecx)\n" /* line 125 */
        "movl 0xc94984, %edx\n" /* line 126 */
        "movl %edx, 0xc(%ecx)\n"
        "movl %eax, 0xc94984\n" /* line 127 */
        "movl 0xc(%ecx), %edx\n" /* line 128 */
        "movl %eax, (%edx)\n"
        "addl $1, %ebx\n" /* line 769 */
        "addl $0x188, %ecx\n"
        "cmpl $0x80, %ebx\n"
        "jne .Lfe1f4c_000e207c\n"
        ".Lfe1f4c_000e20aa:\n"
        "addl $0x1c, %esp\n" /* line 806 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe1f4c_000e20b2:\n"
        "movl $3, (%esp)\n" /* line 185 */
        "movl $1, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $s_cache, %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "movl $3, (%esp)\n" /* line 186 */
        "movl $2, %ecx\n"
        "movl %ebx, %edx\n"
        "movl $s_cache, %eax\n"
        "calll SMC_FreeCachedSurface_r\n"
        "leal 0x88(%ebx), %esi\n"
        "jmp .Lfe1f4c_000e1f7e\n"
        ".Lfe1f4c_000e20ed:\n"
        "xorl %edi, %edi\n" /* line 173 | lodLevel */
        "jmp .Lfe1f4c_000e1ff8\n"
    );
}

