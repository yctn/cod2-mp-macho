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

static static_model_cache_t s_cache; /* s_cache */

extern refimport_t *ri; /* imp_ri */
extern GfxBackEndData **gfxBuf; /* imp_frontEndDataOut */
extern void **g_dxCaps; /* imp_r_rendererInUse */
extern byte *g_dx; /* imp_dx */
extern volatile int *g_dxIter; /* imp_alwaysfails */
extern r_global_permanent_t *rgp; /* imp_rgp */

void R_AddFrontendCmd(int type, void *data);
void R_InitStaticModelIndexCache(void);
void R_StaticModelCacheStats_f(void);
void R_UsedCachedStaticModelSurface(GfxStaticModelSurfaceCached *surf);
void R_SkinStaticModelCachedCmd(SkinStaticModelCachedCmd *skinCmd, SkinBuffers *skinBuffers);
void R_InitStaticModelCache(void);
static __attribute__((regparm(3))) void SMC_FreeCachedSurface_r(static_model_cache_t *cache, void *tree, int nodeIndex, int levelsToLeaf);
void R_StaticModelCacheFlush_f(void);
void R_ShutdownStaticModelCache(void);
static __attribute__((regparm(2))) Bool SMC_GetFreeBlockOfSize(static_model_cache_t *cache, int listIndex);
GfxStaticModelSurfaceCached * R_CacheStaticModelSurface(GfxStaticSurface *staticSurf, const XSurface *xsurf, int smodelIndex, const Material *material);
void R_FlushStaticModelCache(void);

/* line 781 */
void R_InitStaticModelIndexCache(void)
{
    void *mem = ((void *(*)(int))(*(void **)(*(int *)imp_ri + 0xc)))(0xc0000);
    *(void **)(*(int *)imp_dx + 0x2dc8) = mem;
}

/* line 819 */
void R_StaticModelCacheStats_f(void)
{
    ri->Printf(0, "%.2f%% of cache is currently allocated.\n",
               (double)((float)s_cache.stats.allocatedVerts * 100.0f * (1.0f / 65536.0f)));
    if (s_cache.stats.allocatedVerts) {
        ri->Printf(0, "%.2f%% allocated cache vertices are used.\n",
                   (double)((float)s_cache.stats.usedVerts * 100.0f / (float)s_cache.stats.allocatedVerts));
    }
}

/* line 713 */
void R_UsedCachedStaticModelSurface(GfxStaticModelSurfaceCached *surf)
{
    int treeIndex;

    treeIndex = ((unsigned int)((char *)surf - (char *)&s_cache)) / sizeof(static_model_tree_t);
    static_model_tree_t *tree = &s_cache.trees[treeIndex];

    /* Update frame count */
    tree->frameCount = (*gfxBuf)->frameCount;

    /* Remove tree from its current usedlist position */
    ((static_model_tree_list_t *)tree->usedlist.next)->prev = tree->usedlist.prev;
    ((static_model_tree_list_t *)tree->usedlist.prev)->next = tree->usedlist.next;

    /* Insert tree at front of usedlist */
    tree->usedlist.prev = (int)&s_cache.usedlist;
    tree->usedlist.next = s_cache.usedlist.next;
    s_cache.usedlist.next = (int)&tree->usedlist;
    ((static_model_tree_list_t *)tree->usedlist.next)->prev = (int)&tree->usedlist;
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
        "movl imp_rgp, %ecx\n" /* line 609 */
        "movl 0x109c(%ecx), %eax\n"
        "movl 4(%edi), %ebx\n" /* skinCmd, smodelInst */
        "leal (%ebx, %ebx, 2), %ebx\n" /* smodelInst */
        "shll $5, %ebx\n" /* smodelInst */
        "addl 0xf8(%eax), %ebx\n" /* smodelInst */
        "movl imp_ri, %eax\n" /* line 610 */
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
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
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
        "movl imp_r_rendererInUse, %eax\n" /* line 580 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe0408_000e0a64\n"
        "movl 0xc(%ebp), %ebx\n" /* line 587 | skinBuffers, material */
        "addl $0x2000, %ebx\n" /* material */
        "movl %ebx, -0x45c(%ebp)\n" /* material, verts */
        /* { scope 2: vertIndex, bufferData, pSrc, c, ... */
        /* { scope 3: i, lightCount */
        "movl imp_rgp, %eax\n" /* line 393 */
        "movl 0x109c(%eax), %edx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $5, %eax\n"
        "addl 0xf8(%edx), %eax\n"
        "leal 0x54(%eax), %ebx\n" /* baseLightingCoords */
        "movss lit4_002ed824, %xmm1\n" /* line 428 | 32768.0f */
        "movss 0x54(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x4b8(%ebp)\n"
        "calll floorf\n"
        "fstps -0x498(%ebp)\n"
        "cvttss2si -0x498(%ebp), %eax\n"
        "movw %ax, -0x428(%ebp)\n"
        "movss -0x4b8(%ebp), %xmm1\n"
        "mulss 4(%ebx), %xmm1\n" /* baseLightingCoords */
        "addss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x49c(%ebp)\n"
        "cvttss2si -0x49c(%ebp), %edx\n"
        "movw %dx, -0x438(%ebp)\n"
        "movl -0x458(%ebp), %edx\n" /* line 400 | vertCount */
        "testl %edx, %edx\n"
        "jg .Lfe0408_000e08af\n"
        ".Lfe0408_000e072a:\n"
        "movl imp_dx, %eax\n" /* line 439 */
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
        "movl imp_dx, %eax\n" /* line 467 */
        "movl 0x2dc4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
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
        "movl imp_dx, %eax\n" /* line 467 */
        "movl 0x2dc4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
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
        "movl imp_rgp, %eax\n" /* line 524 */
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
        "movl imp_dx, %eax\n" /* line 546 */
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
        "movl imp_dx, %eax\n" /* line 570 */
        "movl 0x2dc4(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
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
        "mulss lit4_002ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "movzbl 1(%ebx), %eax\n" /* line 498 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm5\n"
        "movss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "mulss %xmm5, %xmm0\n"
        "movss %xmm0, -0x43c(%ebp)\n"
        "movzbl (%ebx), %eax\n" /* line 499 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm3\n"
        "movss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "mulss %xmm3, %xmm0\n"
        "movss %xmm0, -0x440(%ebp)\n"
        "movzbl 3(%ebx), %eax\n" /* line 428 | baseLightingCoords */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5cc, %xmm0\n" /* 0.003921568859368563f */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
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
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
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
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
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
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
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
        "movss refEntIsInWorldSpace+80, %xmm2\n"
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
void R_InitStaticModelCache(void)
{
    int size;
    int i;
    void *device;
    void **vtable;
    static_model_node_list_t *freenode;

    /* Determine VB size based on device caps */
    size = 0x240000;
    if (((int *)*(void **)g_dxCaps)[2] != 2) {
        size = 0x400000;
    }

    /* Create vertex buffer (retry loop for device lost) */
    do {
        device = *(void **)(g_dx + 8);
        vtable = *(void ***)device;
        ((int (__attribute__((stdcall)) *)(void *, int, int, int, int, void *, int))vtable[0x68 / 4])(
            device, size, 0x400208, 0, 0, (void *)(g_dx + 0x2dc4), 0);
    } while (*g_dxIter != 0);

    /* Reset the cache */
    memset(&s_cache, 0, sizeof(s_cache));

    /* Initialize usedlist as empty (self-pointing) */
    s_cache.usedlist.prev = (int)&s_cache.usedlist;
    s_cache.usedlist.next = (int)&s_cache.usedlist;

    /* Initialize each freelist as empty (self-pointing) */
    for (i = 0; i < 5; i++) {
        s_cache.freelist[i].prev = (int)&s_cache.freelist[i];
        s_cache.freelist[i].next = (int)&s_cache.freelist[i];
    }

    /* Insert each tree's first leaf freenode into freelist[0] */
    for (i = 0; i < 128; i++) {
        freenode = &s_cache.trees[i].leafs[0].freenode;
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;
    }
}

/* line 147 */
static __attribute__((naked)) __attribute__((regparm(3)))
void SMC_FreeCachedSurface_r(static_model_cache_t *cache, void *tree, int nodeIndex, int levelsToLeaf)
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
void R_StaticModelCacheFlush_f(void)
{
    static_model_tree_t *tree;
    static_model_node_list_t *freenode;
    GfxStaticModelSurfaceCached *leaf;
    GfxStaticSurface *surface;
    static_model_tree_list_t *node;
    int lodLevel;
    int i;

    tree = (static_model_tree_t *)s_cache.usedlist.next;
    if (!tree)
        return;

    while ((int)tree != (int)&s_cache.usedlist) {
        freenode = &tree->leafs[0].freenode;
        leaf = &tree->leafs[0].surf;

        if (tree->nodes[0].usedVerts == 0) {
            /* Leaf not allocated, unlink freenode from its freelist */
            ((static_model_node_list_t *)freenode->next)->prev = freenode->prev;
            ((static_model_node_list_t *)freenode->prev)->next = freenode->next;
        } else {
            tree->nodes[0].usedVerts = 0;

            if (tree->nodes[0].inuse == 0) {
                /* No children allocated, recursively free child nodes */
                SMC_FreeCachedSurface_r(&s_cache, (void *)tree, 1, 3);
                SMC_FreeCachedSurface_r(&s_cache, (void *)tree, 2, 3);
                freenode = &tree->leafs[0].freenode;
            } else {
                /* Has children: clear the surface's cached LOD pointer */
                surface = leaf->surface;
                lodLevel = 0;
                if (surface->cachedLods[0] != leaf) {
                    for (lodLevel = 1; lodLevel < 4; lodLevel++) {
                        if (surface->cachedLods[lodLevel] == leaf)
                            break;
                    }
                }
                if (lodLevel < 4) {
                    surface->cachedLods[lodLevel] = NULL;
                }

                s_cache.stats.allocatedVerts -= 0x200;
                s_cache.stats.usedVerts -= leaf->xsurf->vertCount;
                tree->nodes[0].inuse = 0;
            }
        }

        /* Remove tree from usedlist */
        node = (static_model_tree_list_t *)s_cache.usedlist.next;
        ((static_model_tree_list_t *)node->next)->prev = node->prev;
        ((static_model_tree_list_t *)node->prev)->next = node->next;

        /* Insert tree's leaf[0] freenode into freelist[0] */
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;

        tree = (static_model_tree_t *)s_cache.usedlist.next;
    }

    /* Reinitialize cache */
    memset(&s_cache, 0, sizeof(s_cache));

    s_cache.usedlist.prev = (int)&s_cache.usedlist;
    s_cache.usedlist.next = (int)&s_cache.usedlist;

    for (i = 0; i < 5; i++) {
        s_cache.freelist[i].prev = (int)&s_cache.freelist[i];
        s_cache.freelist[i].next = (int)&s_cache.freelist[i];
    }

    for (i = 0; i < 128; i++) {
        freenode = &s_cache.trees[i].leafs[0].freenode;
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;
    }
}

/* line 810 */
void R_ShutdownStaticModelCache(void)
{
    static_model_tree_t *tree;
    static_model_node_list_t *freenode;
    GfxStaticModelSurfaceCached *leaf;
    GfxStaticSurface *surface;
    static_model_tree_list_t *node;
    int lodLevel;
    int i;
    void *vb;
    void **vtable;

    tree = (static_model_tree_t *)s_cache.usedlist.next;
    if (!tree)
        goto release_vb;

    while ((int)tree != (int)&s_cache.usedlist) {
        freenode = &tree->leafs[0].freenode;
        leaf = &tree->leafs[0].surf;

        if (tree->nodes[0].usedVerts == 0) {
            /* Leaf not allocated, unlink freenode from its freelist */
            ((static_model_node_list_t *)freenode->next)->prev = freenode->prev;
            ((static_model_node_list_t *)freenode->prev)->next = freenode->next;
        } else {
            tree->nodes[0].usedVerts = 0;

            if (tree->nodes[0].inuse == 0) {
                /* No children allocated, recursively free child nodes */
                SMC_FreeCachedSurface_r(&s_cache, (void *)tree, 1, 3);
                SMC_FreeCachedSurface_r(&s_cache, (void *)tree, 2, 3);
                freenode = &tree->leafs[0].freenode;
            } else {
                /* Has children: clear the surface's cached LOD pointer */
                surface = leaf->surface;
                lodLevel = 0;
                if (surface->cachedLods[0] != leaf) {
                    for (lodLevel = 1; lodLevel < 4; lodLevel++) {
                        if (surface->cachedLods[lodLevel] == leaf)
                            break;
                    }
                }
                if (lodLevel < 4) {
                    surface->cachedLods[lodLevel] = NULL;
                }

                s_cache.stats.allocatedVerts -= 0x200;
                s_cache.stats.usedVerts -= leaf->xsurf->vertCount;
                tree->nodes[0].inuse = 0;
            }
        }

        /* Remove tree from usedlist */
        node = (static_model_tree_list_t *)s_cache.usedlist.next;
        ((static_model_tree_list_t *)node->next)->prev = node->prev;
        ((static_model_tree_list_t *)node->prev)->next = node->next;

        /* Insert tree's leaf[0] freenode into freelist[0] */
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;

        tree = (static_model_tree_t *)s_cache.usedlist.next;
    }

    /* Reinitialize cache */
    memset(&s_cache, 0, sizeof(s_cache));

    s_cache.usedlist.prev = (int)&s_cache.usedlist;
    s_cache.usedlist.next = (int)&s_cache.usedlist;

    for (i = 0; i < 5; i++) {
        s_cache.freelist[i].prev = (int)&s_cache.freelist[i];
        s_cache.freelist[i].next = (int)&s_cache.freelist[i];
    }

    for (i = 0; i < 128; i++) {
        freenode = &s_cache.trees[i].leafs[0].freenode;
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;
    }

release_vb:
    /* Release the smodel cache vertex buffer */
    vb = *(void **)(g_dx + 0x2dc4);
    if (vb) {
        do {
            vb = *(void **)(g_dx + 0x2dc4);
            vtable = *(void ***)vb;
            ((int (__attribute__((stdcall)) *)(void *))vtable[8 / 4])(vb);
            *(void **)(g_dx + 0x2dc4) = NULL;
        } while (*g_dxIter != 0);
    }
}

/* line 220 */
static __attribute__((regparm(2)))
Bool SMC_GetFreeBlockOfSize(static_model_cache_t *cache, int listIndex)
{
    static_model_tree_t *tree;
    static_model_node_list_t *block;
    static_model_node_list_t *freenode;
    static_model_node_list_t *buddyFreenode;
    static_model_node_list_t *list;
    GfxStaticModelSurfaceCached *leaf;
    GfxStaticSurface *surface;
    int parentListIndex;
    int treeIndex;
    int leafIndex, buddyLeafIndex;
    int lodLevel;

    if (listIndex == 0) {
        /* Evict LRU tree from usedlist */
        tree = (static_model_tree_t *)cache->usedlist.prev;

        /* Check if tree was used recently enough */
        if ((*gfxBuf)->frameCount - tree->frameCount <= 2)
            return (Bool)0;

        freenode = &tree->leafs[0].freenode;
        leaf = &tree->leafs[0].surf;

        if (tree->nodes[0].usedVerts == 0) {
            /* Leaf not allocated, unlink freenode from its freelist */
            ((static_model_node_list_t *)freenode->next)->prev = freenode->prev;
            ((static_model_node_list_t *)freenode->prev)->next = freenode->next;
        } else {
            tree->nodes[0].usedVerts = 0;

            if (tree->nodes[0].inuse == 0) {
                /* No children, recursively free child nodes */
                SMC_FreeCachedSurface_r(cache, (void *)tree, 1, 3);
                SMC_FreeCachedSurface_r(cache, (void *)tree, 2, 3);
                freenode = &tree->leafs[0].freenode;
            } else {
                /* Has children: clear parent surface pointer */
                surface = leaf->surface;
                lodLevel = 0;
                if (surface->cachedLods[0] != leaf) {
                    for (lodLevel = 1; lodLevel < 4; lodLevel++) {
                        if (surface->cachedLods[lodLevel] == leaf)
                            break;
                    }
                }
                if (lodLevel < 4) {
                    surface->cachedLods[lodLevel] = NULL;
                }

                cache->stats.allocatedVerts -= 0x200;
                cache->stats.usedVerts -= leaf->xsurf->vertCount;
                tree->nodes[0].inuse = 0;
            }
        }

        /* Unlink tree from usedlist */
        ((static_model_tree_list_t *)tree->usedlist.next)->prev = tree->usedlist.prev;
        ((static_model_tree_list_t *)tree->usedlist.prev)->next = tree->usedlist.next;

        /* Insert leaf freenode into freelist[0] */
        list = &cache->freelist[0];
        freenode->prev = (int)list;
        freenode->next = list->next;
        list->next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;

        return (Bool)1;
    }

    /* listIndex > 0: split a larger block */
    parentListIndex = listIndex - 1;

    /* Check if parent freelist has blocks */
    if (cache->freelist[parentListIndex].next == (int)&cache->freelist[parentListIndex]) {
        /* Parent freelist empty, recurse */
        if (!SMC_GetFreeBlockOfSize(cache, parentListIndex))
            return 0;
    }

    /* Take block from parent freelist */
    block = (static_model_node_list_t *)cache->freelist[parentListIndex].next;

    /* Unlink block from parent freelist */
    ((static_model_node_list_t *)block->next)->prev = block->prev;
    ((static_model_node_list_t *)block->prev)->next = block->next;

    /* Compute tree index from block address */
    treeIndex = ((unsigned int)((char *)block - (char *)cache)) / sizeof(static_model_tree_t);
    tree = &cache->trees[treeIndex];

    /* If listIndex == 1, insert tree into usedlist */
    if (listIndex == 1) {
        tree->usedlist.prev = (int)&cache->usedlist;
        tree->usedlist.next = cache->usedlist.next;
        cache->usedlist.next = (int)&tree->usedlist;
        ((static_model_tree_list_t *)tree->usedlist.next)->prev = (int)&tree->usedlist;
    }

    /* Insert block into freelist[listIndex] (first half) */
    list = &cache->freelist[listIndex];
    block->prev = (int)list;
    block->next = list->next;
    list->next = (int)block;
    ((static_model_node_list_t *)block->next)->prev = (int)block;

    /* Compute buddy block (second half) and insert into freelist[listIndex] */
    leafIndex = ((char *)block - (char *)&tree->leafs[0]) / 16;
    buddyLeafIndex = leafIndex + (1 << (4 - listIndex));
    buddyFreenode = &tree->leafs[buddyLeafIndex].freenode;

    buddyFreenode->prev = (int)list;
    buddyFreenode->next = (int)block;
    list->next = (int)buddyFreenode;
    ((static_model_node_list_t *)buddyFreenode->next)->prev = (int)buddyFreenode;

    return 1;
}

/* line 661 */
GfxStaticModelSurfaceCached * R_CacheStaticModelSurface(GfxStaticSurface *staticSurf, const XSurface *xsurf, int smodelIndex, const Material *material)
{
    GfxStaticModelSurfaceCached *cached;
    static_model_tree_t *tree;
    static_model_node_list_t *block;
    int bitCount, blockSize, listIndex;
    int vertCount;
    int treeIndex, leafIndex, nodeIndex;
    int vertAlloc;
    int baseVertIndex;
    unsigned int twoBaseOffsets;
    int *twoSrcIndices;
    int *twoDstIndices;
    int numTriPairs;
    int i;
    SkinStaticModelCachedCmd skinCmd;

    /* Check if device is lost */
    if (g_dx[0x2d3c] != 0)
        return NULL;

    /* Check vertex count limit */
    vertCount = xsurf->vertCount;
    if (vertCount > 0x200)
        return NULL;

    /* Determine block size and freelist index */
    if (vertCount <= 0x20) {
        bitCount = 5;
        blockSize = 0x20;
        listIndex = 4;
    } else {
        bitCount = 5;
        do {
            bitCount++;
            blockSize = 1 << bitCount;
        } while (vertCount > blockSize);
        listIndex = 9 - bitCount;
    }

    /* Try to get a free block */
    if (s_cache.freelist[listIndex].next == (int)&s_cache.freelist[listIndex]) {
        if (!SMC_GetFreeBlockOfSize(&s_cache, listIndex))
            return NULL;
    }

    /* Take block from the end of the freelist */
    block = (static_model_node_list_t *)s_cache.freelist[listIndex].next;

    /* Unlink block from freelist */
    ((static_model_node_list_t *)block->next)->prev = block->prev;
    ((static_model_node_list_t *)block->prev)->next = block->next;

    /* Compute tree index from block address */
    treeIndex = ((unsigned int)((char *)block - (char *)&s_cache)) / sizeof(static_model_tree_t);
    tree = &s_cache.trees[treeIndex];

    /* If listIndex == 0 (whole tree block), insert tree into usedlist */
    if (listIndex == 0) {
        tree->usedlist.prev = (int)&s_cache.usedlist;
        tree->usedlist.next = s_cache.usedlist.next;
        s_cache.usedlist.next = (int)&tree->usedlist;
        ((static_model_tree_list_t *)tree->usedlist.next)->prev = (int)&tree->usedlist;
    }

    /* Compute leaf index within tree */
    leafIndex = ((char *)block - (char *)&tree->leafs[0]) / 16;

    /* Compute node index in the binary tree */
    nodeIndex = ((leafIndex + 16) >> (4 - listIndex)) - 1;

    /* Mark node as in-use */
    tree->nodes[nodeIndex].inuse = 1;

    /* Propagate usedVerts up the tree */
    vertAlloc = 1 << bitCount;
    while (nodeIndex >= 0) {
        tree->nodes[nodeIndex].usedVerts += vertAlloc;
        nodeIndex = (nodeIndex - 1) >> 1;
    }

    /* Set up the cached surface */
    cached = &tree->leafs[leafIndex].surf;
    baseVertIndex = (treeIndex * 16 + leafIndex) * 32;
    cached->baseVertIndex = baseVertIndex;

    /* Update stats */
    s_cache.stats.allocatedVerts += blockSize;
    s_cache.stats.usedVerts += xsurf->vertCount;

    /* Fill in cached surface fields */
    cached->surface = staticSurf;
    cached->xsurf = xsurf;
    cached->smodelIndex = smodelIndex;

    /* Submit skinning command */
    skinCmd.cached = cached;
    skinCmd.smodelIndex = smodelIndex;
    skinCmd.material = material;
    R_AddFrontendCmd(5, &skinCmd);

    /* Copy and offset indices */
    twoBaseOffsets = (baseVertIndex << 16) | (baseVertIndex & 0xFFFF);
    twoSrcIndices = (int *)xsurf->triIndices;
    twoDstIndices = (int *)(*(int *)(g_dx + 0x2dc8) + baseVertIndex * 12);
    numTriPairs = (short)((xsurf->triCount + (((unsigned short)xsurf->triCount) >> 15)) >> 1);

    for (i = 0; i < numTriPairs; i++) {
        twoDstIndices[0] = twoBaseOffsets + twoSrcIndices[0];
        twoDstIndices[1] = twoBaseOffsets + twoSrcIndices[1];
        twoDstIndices[2] = twoBaseOffsets + twoSrcIndices[2];
        twoDstIndices += 3;
        twoSrcIndices += 3;
    }

    return cached;
}

/* line 787 */
void R_FlushStaticModelCache(void)
{
    static_model_tree_t *tree;
    static_model_node_list_t *freenode;
    GfxStaticModelSurfaceCached *leaf;
    GfxStaticSurface *surface;
    static_model_tree_list_t *node;
    int lodLevel;
    int i;

    tree = (static_model_tree_t *)s_cache.usedlist.next;
    if (!tree)
        return;

    while ((int)tree != (int)&s_cache.usedlist) {
        freenode = &tree->leafs[0].freenode;
        leaf = &tree->leafs[0].surf;

        if (tree->nodes[0].usedVerts == 0) {
            /* Leaf not allocated, unlink freenode from its freelist */
            ((static_model_node_list_t *)freenode->next)->prev = freenode->prev;
            ((static_model_node_list_t *)freenode->prev)->next = freenode->next;
        } else {
            tree->nodes[0].usedVerts = 0;

            if (tree->nodes[0].inuse == 0) {
                /* No children allocated, recursively free child nodes */
                SMC_FreeCachedSurface_r(&s_cache, (void *)tree, 1, 3);
                SMC_FreeCachedSurface_r(&s_cache, (void *)tree, 2, 3);
                freenode = &tree->leafs[0].freenode;
            } else {
                /* Has children: clear the surface's cached LOD pointer */
                surface = leaf->surface;
                lodLevel = 0;
                if (surface->cachedLods[0] != leaf) {
                    for (lodLevel = 1; lodLevel < 4; lodLevel++) {
                        if (surface->cachedLods[lodLevel] == leaf)
                            break;
                    }
                }
                if (lodLevel < 4) {
                    surface->cachedLods[lodLevel] = NULL;
                }

                s_cache.stats.allocatedVerts -= 0x200;
                s_cache.stats.usedVerts -= (short)leaf->xsurf->vertCount;
                tree->nodes[0].inuse = 0;
            }
        }

        /* Remove tree from usedlist (unlink s_cache.usedlist.next) */
        node = (static_model_tree_list_t *)s_cache.usedlist.next;
        ((static_model_tree_list_t *)node->next)->prev = node->prev;
        ((static_model_tree_list_t *)node->prev)->next = node->next;

        /* Insert tree's leaf[0] freenode into freelist[0] */
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;

        /* Re-read next tree from usedlist */
        tree = (static_model_tree_t *)s_cache.usedlist.next;
    }

    /* Reinitialize cache */
    memset(&s_cache, 0, sizeof(s_cache));

    s_cache.usedlist.prev = (int)&s_cache.usedlist;
    s_cache.usedlist.next = (int)&s_cache.usedlist;

    for (i = 0; i < 5; i++) {
        s_cache.freelist[i].prev = (int)&s_cache.freelist[i];
        s_cache.freelist[i].next = (int)&s_cache.freelist[i];
    }

    for (i = 0; i < 128; i++) {
        freenode = &s_cache.trees[i].leafs[0].freenode;
        freenode->prev = (int)&s_cache.freelist[0];
        freenode->next = s_cache.freelist[0].next;
        s_cache.freelist[0].next = (int)freenode;
        ((static_model_node_list_t *)freenode->next)->prev = (int)freenode;
    }
}

