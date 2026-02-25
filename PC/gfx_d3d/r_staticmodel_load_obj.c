/* ASM dump from: r_staticmodel_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_staticmodel_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/com_math.h"
 */

static int smodelLoadGlob; /* 0xce7100 */

static int CompareStaticModels(const int *smodel0, const int *smodel1);
int R_ScaleStaticModelLighting(float directLightScale, float indirectLightScale, float *sunVisibility, vec4_t *colorForDir);
int R_GetStaticModelLightingFromGrid(const GfxWorld *world, GfxStaticModelInstance *smodelInst, float *sunVisibility, vec4_t *colorForDir);
int R_PrepareStaticModelLightingCache(GfxWorld *world, int smodelCount);
Bool R_ValidateStaticModel(struct XModel *model);
static int R_AddStaticModelToAabbTree_r(GfxWorld *world, int smodelIndex);
static int R_FilterStaticModelIntoCells_r(GfxStaticModelInstance *smodelInst, const vec_t *mins, const vec_t *maxs);
int R_FinishStaticModelLightingCache(GfxWorld *world);
int R_GetStaticModelLightingFromGround(const vec_t *groundLight, float *sunVisibility, vec4_t *colorForDir);
int R_CreateStaticModel(GfxWorld *world, struct XModel *model, const vec_t *origin, const vec_t *angles, vec_t scale, GfxStaticModelInstance *smodelInst);
int R_CacheStaticModelLighting(const GfxWorld *world, GfxStaticModelInstance *smodelInst, float sunVisibility, vec4_t *colorForDir);
int R_SortGfxAabbTree(GfxWorld *world, GfxAabbTree *tree);
int R_AllocStaticModels(GfxAabbTree *tree);

/* line 86 */
static __attribute__((naked))
int CompareStaticModels(const int *smodel0, const int *smodel1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 86 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* smodel0 */
        "movl (%eax), %eax\n" /* smodel0 */
        "movl 0xc(%ebp), %edx\n" /* smodel1 */
        "subl (%edx), %eax\n" /* smodel0 */
        "popl %ebp\n" /* line 89 */
        "retl\n"
    );
}

/* line 449 */
__attribute__((naked))
int R_ScaleStaticModelLighting(float directLightScale, float indirectLightScale, float *sunVisibility, vec4_t *colorForDir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 449 */
        "movl %esp, %ebp\n"
        "movss 8(%ebp), %xmm0\n" /* directLightScale */
        "movss 0xc(%ebp), %xmm1\n" /* indirectLightScale */
        "movl 0x10(%ebp), %eax\n" /* sunVisibility */
        "mulss (%eax), %xmm0\n" /* line 456 */
        "movss %xmm0, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* colorForDir */
        "movl $6, %edx\n"
        ".Lf107214_00107234:\n"
        "movaps %xmm1, %xmm0\n" /* line 519 */
        "mulss (%eax), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 520 */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 521 */
        "mulss 8(%eax), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 522 */
        "mulss 0xc(%eax), %xmm0\n"
        "movss %xmm0, 0xc(%eax)\n"
        "addl $0x10, %eax\n"
        "subl $1, %edx\n" /* line 458 */
        "jne .Lf107214_00107234\n"
        "popl %ebp\n" /* line 460 */
        "retl\n"
    );
}

/* line 533 */
__attribute__((naked))
int R_GetStaticModelLightingFromGrid(const GfxWorld *world, GfxStaticModelInstance *smodelInst, float *sunVisibility, vec4_t *colorForDir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 533 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* smodelInst, sunVisibility */
        "leal 0x14(%eax), %edx\n"
        "leal 0x20(%eax), %ecx\n"
        /* { scope 1 */
        /* { scope 2 */
        "movss 0x14(%eax), %xmm0\n" /* line 256 */
        "addss 0x20(%eax), %xmm0\n"
        "movss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n" /* lightingOrigin */
        "movss 4(%edx), %xmm0\n" /* line 257 */
        "addss 4(%ecx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movss 8(%edx), %xmm0\n" /* line 258 */
        "addss 8(%ecx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc(%ebp)\n"
        /* } scope */
        "movl 0x14(%ebp), %eax\n" /* line 543 | colorForDir */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* lightingOrigin */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* world */
        "addl $0x11c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_GetLightingAtPoint\n"
        "movl 0x10(%ebp), %eax\n" /* sunVisibility */
        "fstps (%eax)\n"
        /* } scope */
        "leave\n" /* line 544 */
        "retl\n"
    );
}

/* line 565 */
__attribute__((naked))
int R_PrepareStaticModelLightingCache(GfxWorld *world, int smodelCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 565 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* smodelCount */
        /* { scope 1 */
        "movl 0x195eec0, %eax\n" /* line 570 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf1072e6_001073c2\n"
        "movl $1, smodelLoadGlob\n" /* line 578 */
        "cmpl $1, %esi\n" /* line 579 | smodelCount */
        "jg .Lf1072e6_001073a7\n"
        "movl $1, %ecx\n"
        ".Lf1072e6_0010731a:\n"
        "movl %ecx, 0xce7104\n" /* line 582 */
        "movl %ecx, %edx\n" /* line 583 */
        "imull smodelLoadGlob, %edx\n"
        "leal (%esi, %esi), %eax\n" /* smodelCount */
        "cmpl %eax, %edx\n"
        "jl .Lf1072e6_0010733a\n"
        "leal 1(%ecx), %eax\n" /* line 584 */
        "sarl $1, %eax\n"
        "movl %eax, 0xce7104\n"
        ".Lf1072e6_0010733a:\n"
        "movl smodelLoadGlob, %ebx\n" /* line 586 | lightingImageSize */
        "leal (%ebx, %ebx), %eax\n" /* lightingImageSize */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movss %xmm2, 0xce7108\n"
        "movl 0xce7104, %eax\n" /* line 587 */
        "addl %eax, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0xce710c\n"
        "imull 0xce7104, %ebx\n" /* line 590 | lightingImageSize */
        "shll $5, %ebx\n" /* lightingImageSize */
        "movl %ebx, (%esp)\n" /* line 591 | lightingImageSize */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, 0xce7110\n"
        "movl %ebx, 8(%esp)\n" /* line 592 | lightingImageSize */
        "movl $0x80, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1072e6_001073a7:\n"
        "movl $1, %ecx\n" /* line 579 */
        ".Lf1072e6_001073ac:\n"
        "addl %ecx, %ecx\n" /* line 580 */
        "movl %ecx, %eax\n" /* line 579 */
        "imull %ecx, %eax\n"
        "cmpl %esi, %eax\n" /* smodelCount */
        "jl .Lf1072e6_001073ac\n"
        "movl %ecx, smodelLoadGlob\n"
        "jmp .Lf1072e6_0010731a\n"
        ".Lf1072e6_001073c2:\n"
        "movl 0x195eee0, %ebx\n" /* line 572 | lightingImageSize */
        "leal (%esi, %esi, 2), %eax\n" /* smodelCount */
        "shll $5, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebx)\n" /* lightingImageSize */
        "movl 8(%ebp), %edx\n" /* world */
        "movl %eax, 0x12c(%edx)\n"
        "leal (, %esi, 4), %eax\n" /* line 573 */
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebx)\n" /* lightingImageSize */
        "movl 8(%ebp), %edx\n" /* world */
        "movl %eax, 0x130(%edx)\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 622 */
__attribute__((naked))
Bool R_ValidateStaticModel(struct XModel *model)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 622 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 631 | model */
        "movl %eax, (%esp)\n"
        "calll XModelGetNumLods\n"
        "movl %eax, -0x2c(%ebp)\n" /* lodCount */
        "testl %eax, %eax\n" /* line 632 */
        "jg .Lf1073fa_00107422\n"
        ".Lf1073fa_00107415:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 655 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1073fa_00107422:\n"
        "xorl %edi, %edi\n" /* line 632 | lodIndex */
        "jmp .Lf1073fa_0010742e\n"
        ".Lf1073fa_00107426:\n"
        "addl $1, %edi\n" /* lodIndex */
        "cmpl %edi, -0x2c(%ebp)\n" /* lodIndex, lodCount */
        "je .Lf1073fa_00107415\n"
        ".Lf1073fa_0010742e:\n"
        "leal -0x20(%ebp), %eax\n" /* line 634 | partBits */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* lodIndex */
        "leal -0x1c(%ebp), %eax\n" /* surfaces */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* model */
        "movl %eax, (%esp)\n"
        "calll XModelGetSurfaces\n"
        "movl %eax, %esi\n" /* surfCount */
        "testl %eax, %eax\n" /* line 635 */
        "jle .Lf1073fa_00107426\n"
        "xorl %ebx, %ebx\n" /* surfIndex */
        "jmp .Lf1073fa_0010745c\n"
        ".Lf1073fa_00107455:\n"
        "addl $1, %ebx\n" /* surfIndex */
        "cmpl %ebx, %esi\n" /* surfIndex, surfCount */
        "je .Lf1073fa_00107426\n"
        ".Lf1073fa_0010745c:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 637 | surfaces */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll XSurfaceGetBoneOffset\n"
        "addl $1, %eax\n"
        "jne .Lf1073fa_00107455\n"
        "movl 8(%ebp), %eax\n" /* line 639 | model */
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %ebx, 0xc(%esp)\n" /* surfIndex */
        "movl %edi, 8(%esp)\n" /* lodIndex */
        "movl %eax, 4(%esp)\n"
        "movl $0x228ae4, (%esp)\n" /* "^1ERROR: model '%s' is not a valid static model, since lod %" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 655 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 238 */
static __attribute__((naked))
int R_AddStaticModelToAabbTree_r(GfxWorld *world, int smodelIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 238 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %edx, %esi\n" /* tree */
        "movl %ecx, -0x28(%ebp)\n"
        /* { scope 1 */
        "leal (%ecx, %ecx, 2), %eax\n" /* line 262 */
        "shll $5, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        ".Lf10749c_001074b6:\n"
        "movl 0x20(%esi), %edx\n" /* line 248 | tree */
        "leal -1(%edx), %eax\n"
        "testl %eax, %edx\n"
        "jne .Lf10749c_00107612\n"
        ".Lf10749c_001074c4:\n"
        "testl %edx, %edx\n" /* line 250 */
        "jne .Lf10749c_001076b1\n"
        "movl $1, %eax\n"
        ".Lf10749c_001074d1:\n"
        "shll $2, %eax\n" /* line 251 */
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, %ebx\n"
        "movl 0x20(%esi), %eax\n" /* line 252 | tree */
        "shll $2, %eax\n"
        "movl 0x24(%esi), %edx\n" /* tree */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl %ebx, 0x24(%esi)\n" /* line 253 | tree */
        "movl 0x20(%esi), %edx\n" /* tree */
        "movl %ebx, %eax\n"
        "movl -0x28(%ebp), %ecx\n" /* line 256 */
        "movl %ecx, (%eax, %edx, 4)\n"
        "addl $1, 0x20(%esi)\n" /* line 257 | tree */
        "movl 0x28(%esi), %ebx\n" /* line 259 | tree */
        "testl %ebx, %ebx\n"
        "je .Lf10749c_0010762a\n"
        ".Lf10749c_00107514:\n"
        "movl -0x2c(%ebp), %edi\n" /* line 262 | smodelInst */
        "movl -0x24(%ebp), %eax\n"
        "addl 0xf8(%eax), %edi\n" /* smodelInst */
        "testl %ebx, %ebx\n" /* line 264 */
        "jle .Lf10749c_00107632\n"
        "movl 0x2c(%esi), %ecx\n" /* line 266 | tree */
        "movl %ecx, -0x1c(%ebp)\n"
        "movss 0x14(%edi), %xmm1\n" /* line 267 | smodelInst */
        "movl %ecx, %edx\n"
        "xorl %eax, %eax\n"
        ".Lf10749c_00107537:\n"
        "movss (%edx), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf10749c_0010757b\n"
        "movss 4(%edx), %xmm0\n" /* line 269 */
        "ucomiss 0x18(%edi), %xmm0\n" /* smodelInst */
        "ja .Lf10749c_0010757b\n"
        "movss 8(%edx), %xmm0\n" /* line 271 */
        "ucomiss 0x1c(%edi), %xmm0\n" /* smodelInst */
        "ja .Lf10749c_0010757b\n"
        "movss 0x20(%edi), %xmm0\n" /* line 273 | smodelInst */
        "ucomiss 0xc(%edx), %xmm0\n"
        "ja .Lf10749c_0010757b\n"
        "movss 0x24(%edi), %xmm0\n" /* line 275 | smodelInst */
        "ucomiss 0x10(%edx), %xmm0\n"
        "ja .Lf10749c_0010757b\n"
        "movss 0x28(%edi), %xmm0\n" /* line 277 | smodelInst */
        "ucomiss 0x14(%edx), %xmm0\n"
        "jbe .Lf10749c_001076c0\n"
        ".Lf10749c_0010757b:\n"
        "addl $1, %eax\n" /* line 264 */
        "addl $0x30, %edx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf10749c_00107537\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 286 */
        "movl 0x18(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf10749c_001076b9\n"
        "addl $0x30, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl -0x1c(%ebp), %ecx\n"
        "addl $0x48, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf10749c_001075a1:\n"
        "addl $1, %edx\n" /* line 283 */
        "cmpl %edx, %ebx\n"
        "je .Lf10749c_00107632\n"
        "movl -0x20(%ebp), %eax\n" /* line 264 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl (%ecx), %eax\n" /* line 286 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "addl $0x30, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "addl $0x30, %ecx\n"
        "movl -0x3c(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf10749c_001075a1\n"
        "movl -0x1c(%ebp), %eax\n"
        ".Lf10749c_001075cd:\n"
        "movl %edi, %edx\n" /* line 287 | smodelInst */
        "movl $3, %ecx\n"
        ".Lf10749c_001075d4:\n"
        "movss 0x14(%edx), %xmm1\n" /* line 291 */
        "movss (%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf10749c_001075e6\n"
        "movss %xmm1, (%eax)\n" /* line 292 */
        ".Lf10749c_001075e6:\n"
        "movss 0x20(%edx), %xmm0\n" /* line 293 */
        "ucomiss 0xc(%eax), %xmm0\n"
        "jbe .Lf10749c_001075f6\n"
        "movss %xmm0, 0xc(%eax)\n" /* line 294 */
        ".Lf10749c_001075f6:\n"
        "addl $4, %eax\n"
        "addl $4, %edx\n"
        "subl $1, %ecx\n" /* line 289 */
        "jne .Lf10749c_001075d4\n"
        "movl -0x1c(%ebp), %esi\n" /* tree */
        "movl 0x20(%esi), %edx\n" /* line 248 | tree */
        "leal -1(%edx), %eax\n"
        "testl %eax, %edx\n"
        "je .Lf10749c_001074c4\n"
        ".Lf10749c_00107612:\n"
        "movl 0x24(%esi), %eax\n" /* tree */
        "movl -0x28(%ebp), %ecx\n" /* line 256 */
        "movl %ecx, (%eax, %edx, 4)\n"
        "addl $1, 0x20(%esi)\n" /* line 257 | tree */
        "movl 0x28(%esi), %ebx\n" /* line 259 | tree */
        "testl %ebx, %ebx\n"
        "jne .Lf10749c_00107514\n"
        /* } scope */
        ".Lf10749c_0010762a:\n"
        "addl $0x4c, %esp\n" /* line 312 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf10749c_00107632:\n"
        "movl $4, 4(%esp)\n" /* line 302 */
        "leal (%ebx, %ebx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl $0x30, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl 0x28(%esi), %eax\n" /* line 303 | tree */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl 0x2c(%esi), %edx\n" /* tree */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl %ebx, 0x2c(%esi)\n" /* line 304 | tree */
        "movl 0x28(%esi), %eax\n" /* line 306 | tree */
        "leal (%eax, %eax, 2), %edx\n"
        "shll $4, %edx\n"
        "leal (%ebx, %edx), %edx\n"
        "addl $1, %eax\n" /* line 307 */
        "movl %eax, 0x28(%esi)\n" /* tree */
        "leal 0x14(%edi), %ecx\n" /* line 309 | smodelInst, from */
        /* { scope 2 */
        "movl 0x14(%edi), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ebx\n" /* line 310 | to */
        "leal 0x20(%edi), %ecx\n" /* smodelInst, from */
        /* { scope 2 */
        "movl 0x20(%edi), %eax\n" /* line 199 */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        "movl %edx, %esi\n"
        "jmp .Lf10749c_001074b6\n"
        /* } scope */
        ".Lf10749c_001076b1:\n"
        "leal (%edx, %edx), %eax\n" /* line 250 */
        "jmp .Lf10749c_001074d1\n"
        ".Lf10749c_001076b9:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf10749c_001075cd\n"
        ".Lf10749c_001076c0:\n"
        "movl %edx, %esi\n" /* line 262 | tree */
        "jmp .Lf10749c_001074b6\n"
    );
}

/* line 334 */
static __attribute__((naked))
int R_FilterStaticModelIntoCells_r(GfxStaticModelInstance *smodelInst, const vec_t *mins, const vec_t *maxs)
{
    __asm__ __volatile__ (
        ".Lf1076c8_001076c8:\n"
        "pushl %ebp\n" /* line 334 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl %eax, %edi\n" /* world */
        "movl %edx, %esi\n" /* node */
        "movl %ecx, -0x3c(%ebp)\n"
        /* { scope 1: localmins, localmaxs */
        "movl 8(%edx), %ebx\n" /* line 338 */
        "cmpl $-2, %ebx\n"
        "je .Lf1076c8_0010773d\n"
        "testl %ebx, %ebx\n" /* line 341 */
        "js .Lf1076c8_00107735\n"
        /* { scope 2 */
        "subl 0xf8(%eax), %ecx\n" /* line 325 */
        "sarl $5, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %ecx\n"
        "movl 0x100(%edi), %edx\n" /* line 326 */
        "leal (, %ebx, 4), %eax\n"
        "shll $6, %ebx\n"
        "subl %eax, %ebx\n"
        "movl 0x1c(%ebx, %edx), %edx\n"
        "movl 0x20(%edx), %ebx\n" /* line 328 */
        "testl %ebx, %ebx\n"
        "je .Lf1076c8_0010772e\n"
        "movl 0x24(%edx), %eax\n"
        "cmpl -4(%eax, %ebx, 4), %ecx\n"
        "je .Lf1076c8_00107735\n"
        ".Lf1076c8_0010772e:\n"
        "movl %edi, %eax\n" /* line 330 */
        "calll R_AddStaticModelToAabbTree_r\n"
        /* } scope */
        /* } scope */
        ".Lf1076c8_00107735:\n"
        "addl $0x4c, %esp\n" /* line 386 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: localmins, localmaxs */
        ".Lf1076c8_0010773d:\n"
        "movl 0xc(%edx), %eax\n" /* line 350 */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* maxs */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* mins */
        "movl %edx, (%esp)\n"
        "calll BoxOnPlaneSide\n"
        "cmpl $3, %eax\n" /* line 351 */
        "jne .Lf1076c8_001077df\n"
        "movl 0xc(%esi), %ecx\n" /* line 353 | node */
        "cmpb $2, 0x10(%ecx)\n"
        "ja .Lf1076c8_00107803\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 199 | mins */
        "movl (%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* localmins */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x1c(%ebp)\n"
        "movzbl 0x10(%ecx), %edx\n" /* line 360 */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x24(%ebp, %edx, 4)\n"
        "movl 0xc(%ebp), %edx\n" /* line 199 | maxs */
        "movl (%edx), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* localmaxs */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x28(%ebp)\n"
        "movzbl 0x10(%ecx), %edx\n" /* line 362 */
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, -0x30(%ebp, %edx, 4)\n"
        "movzbl 0x10(%ecx), %eax\n" /* line 367 */
        "movl 0xc(%ebp), %edx\n" /* maxs */
        "movss (%edx, %eax, 4), %xmm0\n"
        "ucomiss -0x24(%ebp, %eax, 4), %xmm0\n"
        "ja .Lf1076c8_001077e8\n"
        ".Lf1076c8_001077bd:\n"
        "movl 0x14(%esi), %edx\n" /* line 369 | node */
        "leal -0x30(%ebp), %eax\n" /* localmaxs */
        /* } scope */
        ".Lf1076c8_001077c3:\n"
        "movl %eax, 4(%esp)\n" /* line 384 */
        "movl 8(%ebp), %eax\n" /* mins */
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %edi, %eax\n" /* world */
        "calll R_FilterStaticModelIntoCells_r\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 386 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: localmins, localmaxs */
        ".Lf1076c8_001077df:\n"
        "movl 0xc(%esi, %eax, 4), %edx\n" /* line 384 | node */
        "movl 0xc(%ebp), %eax\n" /* maxs */
        "jmp .Lf1076c8_001077c3\n"
        ".Lf1076c8_001077e8:\n"
        "movl %edx, %eax\n"
        /* { scope 2 */
        "movl 0x10(%esi), %edx\n" /* line 368 | node */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* localmins */
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %edi, %eax\n" /* world */
        "calll R_FilterStaticModelIntoCells_r\n"
        "jmp .Lf1076c8_001077bd\n"
        /* } scope */
        ".Lf1076c8_00107803:\n"
        "movl 0x10(%esi), %edx\n" /* line 376 | node */
        "movl 0xc(%ebp), %eax\n" /* maxs */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* mins */
        "movl %eax, (%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %edi, %eax\n" /* world */
        "calll R_FilterStaticModelIntoCells_r\n"
        "movl 0x14(%esi), %edx\n" /* line 377 | node */
        "movl 0xc(%ebp), %eax\n" /* maxs */
        "jmp .Lf1076c8_001077c3\n"
    );
}

/* line 596 */
__attribute__((naked))
int R_FinishStaticModelLightingCache(GfxWorld *world)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 596 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* world */
        "movl 0x195eec0, %eax\n" /* line 602 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf107826_0010790d\n"
        "movl $4, 0xc(%esp)\n" /* line 609 */
        "movl $1, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl $0x228b80, (%esp)\n" /* "*smodel_lighting" */
        "calll Image_Alloc\n"
        "movl %eax, 0x10c(%ebx)\n" /* world */
        "movl $0x15, 0x14(%esp)\n" /* line 614 */
        "movl $2, 0x10(%esp)\n"
        "movl 0xce7104, %edx\n"
        "addl %edx, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl smodelLoadGlob, %edx\n"
        "addl %edx, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xce7110, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Image_Generate3D\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 616 | 0.5f */
        "movss 0xce710c, %xmm1\n" /* y */
        "mulss %xmm0, %xmm1\n" /* y */
        "leal 0x110(%ebx), %eax\n" /* world, v */
        /* { scope 1 */
        "mulss 0xce7108, %xmm0\n" /* line 191 */
        "movss %xmm0, 0x110(%ebx)\n"
        "movss %xmm1, 4(%eax)\n" /* line 192 */
        "movl $0x3e800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl $0, smodelLoadGlob\n" /* line 618 */
        "movl $0, 0xce7104\n"
        "movl $0, 0xce7108\n"
        "movl $0, 0xce710c\n"
        "movl $0, 0xce7110\n"
        ".Lf107826_0010790d:\n"
        "addl $0x24, %esp\n" /* line 619 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 547 */
__attribute__((naked))
int R_GetStaticModelLightingFromGround(const vec_t *groundLight, float *sunVisibility, vec4_t *colorForDir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 547 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* groundLight */
        "movl 0x10(%ebp), %edx\n" /* colorForDir */
        "movl $1, %ebx\n"
        "leal 4(%esi), %ecx\n" /* groundLight */
        ".Lf107914_00107927:\n"
        "movl -4(%ecx), %eax\n" /* line 557 | w */
        /* { scope 1 */
        "movl %eax, (%edx)\n" /* line 447 */
        "movl %eax, 4(%edx)\n" /* line 448 */
        "movl %eax, 8(%edx)\n" /* line 449 */
        "movl %eax, 0xc(%edx)\n" /* line 450 */
        /* } scope */
        "movl -4(%ecx), %eax\n" /* line 558 | w */
        /* { scope 1 */
        "movl %eax, 0x10(%edx)\n" /* line 447 */
        "movl %eax, 0x14(%edx)\n" /* line 448 */
        "movl %eax, 0x18(%edx)\n" /* line 449 */
        "movl %eax, 0x1c(%edx)\n" /* line 450 */
        "addl $1, %ebx\n"
        "addl $4, %ecx\n"
        "addl $0x20, %edx\n"
        /* } scope */
        "cmpl $4, %ebx\n" /* line 555 */
        "jne .Lf107914_00107927\n"
        "movl 0xc(%esi), %edx\n" /* line 561 | groundLight */
        "movl 0xc(%ebp), %eax\n" /* sunVisibility */
        "movl %edx, (%eax)\n"
        "popl %ebx\n" /* line 562 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 658 */
__attribute__((naked))
int R_CreateStaticModel(GfxWorld *world, struct XModel *model, const vec_t *origin, const vec_t *angles, vec_t scale, GfxStaticModelInstance *smodelInst)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 658 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* line 660 | model */
        "movl 0x1c(%ebp), %eax\n" /* smodelInst */
        "movl %edx, 0x10(%eax)\n"
        "movl %eax, %edx\n" /* line 662 | to */
        "addl $4, %edx\n" /* to */
        /* { scope 1: v, v */
        "movl 0x10(%ebp), %ecx\n" /* line 199 | origin */
        "movl (%ecx), %eax\n"
        "movl 0x1c(%ebp), %ecx\n" /* smodelInst */
        "movl %eax, 4(%ecx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 200 | origin */
        "addl $4, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* origin */
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "addl $8, %ecx\n" /* line 201 */
        "movl %ecx, -0x64(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* origin */
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0x1c(%ebp), %eax\n" /* line 663 | smodelInst */
        "addl $0x2c, %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* angles */
        "movl %eax, (%esp)\n"
        "calll AnglesToAxis\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 664 | scale */
        "movl 0x1c(%ebp), %edx\n" /* smodelInst */
        "movss %xmm0, 0x50(%edx)\n"
        "addl $0x20, %edx\n" /* line 666 */
        "movl %edx, -0x3c(%ebp)\n" /* v */
        "movl 0x1c(%ebp), %eax\n" /* smodelInst */
        "addl $0x14, %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* v */
        /* { scope 1: v, v */
        /* { scope 2: xx, yy, zw */
        "movl $0x7f7fffff, %eax\n" /* line 191 */
        "movl 0x1c(%ebp), %edx\n" /* smodelInst */
        "movl %eax, 0x14(%edx)\n"
        "addl $0x18, %edx\n" /* line 192 */
        "movl %edx, -0x44(%ebp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* smodelInst */
        "movl %eax, 0x18(%ecx)\n"
        "addl $0x1c, %ecx\n" /* line 193 */
        "movl %ecx, -0x40(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n" /* smodelInst */
        "movl %eax, 0x1c(%edx)\n"
        /* } scope */
        /* { scope 2: xx, yy, zw */
        "movl $0xff7fffff, %eax\n" /* line 191 */
        "movl %eax, 0x20(%edx)\n"
        "addl $0x24, %edx\n" /* line 192 */
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* smodelInst */
        "movl %eax, 0x24(%ecx)\n"
        "addl $0x28, %ecx\n" /* line 193 */
        "movl %ecx, -0x34(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n" /* smodelInst */
        "movl %eax, 0x28(%edx)\n"
        /* } scope */
        "leal -0x20(%ebp), %eax\n" /* line 409 | partBits */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* surfaces */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* model */
        "movl %ecx, (%esp)\n"
        "calll XModelGetSurfaces\n"
        "movl %eax, -0x60(%ebp)\n" /* surfaceCount */
        "movl $0x2000, (%esp)\n" /* line 412 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x4c(%ebp)\n" /* matArray */
        "movl $0xff78, (%esp)\n" /* line 413 */
        "calll Hunk_AllocateTempMemoryInternal\n"
        "movl %eax, -0x5c(%ebp)\n" /* vert */
        "movl 0xc(%ebp), %eax\n" /* line 415 | model */
        "movl %eax, (%esp)\n"
        "calll XModelNumBones\n"
        "movl %eax, %edi\n" /* numBones */
        "movl 0xc(%ebp), %edx\n" /* line 418 | model */
        "movl %edx, (%esp)\n"
        "calll XModelGetBasePose\n"
        "testl %edi, %edi\n" /* line 420 | numBones */
        "jle .Lf10795e_00107bc1\n"
        "movl -0x4c(%ebp), %ecx\n" /* matArray */
        "xorl %esi, %esi\n" /* boneIndex */
        "leal 0x10(%eax), %ebx\n" /* xsurf */
        /* { scope 2: xx, yy, zw */
        /* { scope 3 */
        ".Lf10795e_00107a85:\n"
        "movss 0xc(%ebx), %xmm1\n" /* line 350 | scale */
        /* { scope 4 */
        "movaps %xmm1, %xmm3\n" /* line 272 */
        "mulss -0x10(%ebx), %xmm3\n"
        "movaps %xmm1, %xmm6\n" /* line 273 */
        "mulss -0xc(%ebx), %xmm6\n"
        "mulss -8(%ebx), %xmm1\n" /* line 274 */
        /* } scope */
        "movaps %xmm3, %xmm0\n" /* line 352 */
        "mulss -0x10(%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* xx */
        "movss -0xc(%ebx), %xmm5\n" /* line 353 */
        "movaps %xmm3, %xmm4\n"
        "mulss %xmm5, %xmm4\n"
        "movss -8(%ebx), %xmm2\n" /* line 354 */
        "movaps %xmm3, %xmm7\n"
        "mulss %xmm2, %xmm7\n"
        "movss -4(%ebx), %xmm0\n" /* line 355 */
        "mulss %xmm0, %xmm3\n"
        "mulss %xmm6, %xmm5\n" /* line 357 */
        "movss %xmm5, -0x2c(%ebp)\n" /* yy */
        "movaps %xmm6, %xmm5\n" /* line 358 */
        "mulss %xmm2, %xmm5\n"
        "mulss %xmm0, %xmm6\n" /* line 359 */
        "mulss %xmm1, %xmm2\n" /* line 361 */
        "mulss %xmm0, %xmm1\n" /* line 362 */
        "movss %xmm1, -0x7c(%ebp)\n" /* zw */
        "movss -0x2c(%ebp), %xmm0\n" /* line 364 | yy */
        "addss %xmm2, %xmm0\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, (%ecx)\n"
        "movss -0x7c(%ebp), %xmm0\n" /* line 365 | zw */
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movaps %xmm7, %xmm0\n" /* line 366 */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "movl $0, 0xc(%ecx)\n" /* line 367 */
        "subss -0x7c(%ebp), %xmm4\n" /* line 369 | zw */
        "movss %xmm4, 0x10(%ecx)\n"
        "addss -0x30(%ebp), %xmm2\n" /* line 370 | xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0x14(%ecx)\n"
        "movaps %xmm3, %xmm0\n" /* line 371 */
        "addss %xmm5, %xmm0\n"
        "movss %xmm0, 0x18(%ecx)\n"
        "movl $0, 0x1c(%ecx)\n" /* line 372 */
        "addss %xmm6, %xmm7\n" /* line 374 */
        "movss %xmm7, 0x20(%ecx)\n"
        "subss %xmm3, %xmm5\n" /* line 375 */
        "movss %xmm5, 0x24(%ecx)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 376 | xx */
        "addss -0x2c(%ebp), %xmm0\n" /* yy */
        "movss %xmm0, -0x30(%ebp)\n" /* xx */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "subss -0x30(%ebp), %xmm0\n" /* xx */
        "movss %xmm0, 0x28(%ecx)\n"
        "movl $0, 0x2c(%ecx)\n" /* line 377 */
        "leal 0x30(%ecx), %edx\n" /* line 383 | to */
        /* { scope 4 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0x30(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl $0x3f800000, 0x3c(%ecx)\n" /* line 384 */
        /* } scope */
        /* } scope */
        "addl $1, %esi\n" /* line 420 | boneIndex */
        "addl $0x20, %ebx\n" /* xsurf */
        "addl $0x40, %ecx\n"
        "cmpl %esi, %edi\n" /* boneIndex, numBones */
        "jne .Lf10795e_00107a85\n"
        ".Lf10795e_00107bc1:\n"
        "movl -0x60(%ebp), %eax\n" /* line 424 | surfaceCount */
        "testl %eax, %eax\n"
        "jg .Lf10795e_00107cbe\n"
        ".Lf10795e_00107bcc:\n"
        "movl -0x5c(%ebp), %edx\n" /* line 444 | vert */
        "movl %edx, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 445 | matArray */
        "movl %ecx, (%esp)\n"
        "calll Hunk_FreeTempMemory\n"
        /* } scope */
        "movss 0x18(%ebp), %xmm0\n" /* line 288 | scale */
        "movl -0x48(%ebp), %eax\n" /* v */
        "mulss (%eax), %xmm0\n"
        "movl 0x10(%ebp), %edx\n" /* origin */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 289 | scale */
        "mulss 4(%eax), %xmm0\n"
        "movl -0x68(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movl -0x44(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 290 | scale */
        "movl -0x48(%ebp), %edx\n" /* v */
        "mulss 8(%edx), %xmm0\n"
        "movl -0x64(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movl -0x40(%ebp), %eax\n"
        "movss %xmm0, (%eax)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 288 | scale */
        "movl -0x3c(%ebp), %edx\n" /* v */
        "mulss (%edx), %xmm0\n"
        "movl 0x10(%ebp), %ecx\n" /* origin */
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 289 | scale */
        "mulss 4(%edx), %xmm0\n"
        "movl -0x68(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movl -0x38(%ebp), %edx\n"
        "movss %xmm0, (%edx)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 290 | scale */
        "movl -0x3c(%ebp), %ecx\n" /* v */
        "mulss 8(%ecx), %xmm0\n"
        "movl -0x64(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movl -0x34(%ebp), %edx\n"
        "movss %xmm0, (%edx)\n"
        "movl 0xc(%ebp), %ecx\n" /* line 671 | model */
        "movl %ecx, (%esp)\n"
        "calll XModelGetLodOutDist\n"
        "fstps -0x6c(%ebp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "mulss -0x6c(%ebp), %xmm0\n"
        "movl 0x1c(%ebp), %eax\n" /* smodelInst */
        "movss %xmm0, (%eax)\n"
        "movl 8(%ebp), %ecx\n" /* line 675 | world */
        "movl 0xc(%ecx), %edx\n"
        "movl -0x3c(%ebp), %eax\n" /* v */
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %ecx\n" /* v */
        "movl %ecx, (%esp)\n"
        "movl 0x1c(%ebp), %ecx\n" /* smodelInst */
        "movl 8(%ebp), %eax\n" /* world */
        "calll R_FilterStaticModelIntoCells_r\n"
        "addl $0x9c, %esp\n" /* line 676 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: v, v */
        ".Lf10795e_00107cbe:\n"
        "movl $0, -0x58(%ebp)\n" /* line 424 | index */
        "movl -0x70(%ebp), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl -0x70(%ebp), %edx\n"
        "addl $0x18, %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* index */
        ".Lf10795e_00107cda:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 426 | surfaces */
        "movl (%eax, %ecx, 4), %ebx\n" /* xsurf */
        "movl %ebx, (%esp)\n" /* line 427 | xsurf */
        "calll XSurfaceGetNumVerts\n"
        "movl %eax, -0x50(%ebp)\n" /* vertCount */
        "movl $0, 0x10(%esp)\n" /* line 428 */
        "movl $0, 0xc(%esp)\n"
        "movl -0x5c(%ebp), %eax\n" /* vert */
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* matArray */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* xsurf */
        "calll XSurfaceGetVerts\n"
        "movl -0x50(%ebp), %eax\n" /* line 431 | vertCount */
        "testl %eax, %eax\n"
        "jle .Lf10795e_00107d9e\n"
        "movl -0x5c(%ebp), %esi\n" /* vert, boneIndex */
        "movl $0, -0x54(%ebp)\n" /* vertIndex */
        ".Lf10795e_00107d26:\n"
        "movl -0x70(%ebp), %ebx\n" /* xsurf */
        "movl -0x74(%ebp), %ecx\n"
        "movl $1, %edi\n" /* numBones */
        ".Lf10795e_00107d31:\n"
        "movss (%esi), %xmm1\n" /* line 435 | boneIndex */
        "mulss (%ebx), %xmm1\n" /* xsurf */
        "movss 4(%esi), %xmm0\n" /* boneIndex */
        "mulss (%ecx), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "leal (, %edi, 4), %eax\n"
        "movss 8(%esi), %xmm0\n" /* boneIndex */
        "movl -0x78(%ebp), %edx\n"
        "mulss -4(%edx, %eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movl -0x48(%ebp), %edx\n" /* line 658 | v */
        "addl %eax, %edx\n" /* angles */
        "movss -4(%edx), %xmm0\n" /* line 436 */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf10795e_00107d73\n"
        "movss %xmm1, -4(%edx)\n" /* line 437 */
        ".Lf10795e_00107d73:\n"
        "addl -0x3c(%ebp), %eax\n" /* line 658 | v, angles */
        "ucomiss -4(%eax), %xmm1\n" /* line 438 */
        "jbe .Lf10795e_00107d81\n"
        "movss %xmm1, -4(%eax)\n" /* line 439 */
        ".Lf10795e_00107d81:\n"
        "addl $1, %edi\n" /* numBones */
        "addl $4, %ebx\n" /* xsurf */
        "addl $4, %ecx\n"
        "cmpl $4, %edi\n" /* line 433 | numBones */
        "jne .Lf10795e_00107d31\n"
        "addl $1, -0x54(%ebp)\n" /* line 431 | vertIndex */
        "addl $0xc, %esi\n" /* boneIndex */
        "movl -0x54(%ebp), %ecx\n" /* vertIndex */
        "cmpl %ecx, -0x50(%ebp)\n" /* vertCount */
        "jne .Lf10795e_00107d26\n"
        ".Lf10795e_00107d9e:\n"
        "addl $1, -0x58(%ebp)\n" /* line 424 | index */
        "movl -0x58(%ebp), %eax\n" /* index */
        "cmpl %eax, -0x60(%ebp)\n" /* surfaceCount */
        "je .Lf10795e_00107bcc\n"
        "movl %eax, %ecx\n"
        "jmp .Lf10795e_00107cda\n"
    );
}

/* line 463 */
__attribute__((naked))
int R_CacheStaticModelLighting(const GfxWorld *world, GfxStaticModelInstance *smodelInst, float sunVisibility, vec4_t *colorForDir)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 463 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %esi\n" /* world */
        /* { scope 1: comparand */
        "movl 0xf4(%esi), %ebx\n" /* line 479 | world, smodelIndex */
        "subl $1, %ebx\n" /* smodelIndex */
        "movl 0x195eec0, %eax\n" /* line 483 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf107db6_00108084\n"
        "movl %ebx, %eax\n" /* line 494 | smodelIndex */
        "cltd\n"
        "idivl smodelLoadGlob\n"
        "movl %eax, %ecx\n"
        "addl %edx, %edx\n"
        "movl %edx, -0x50(%ebp)\n" /* x0 */
        "addl %ecx, %ecx\n" /* line 495 */
        "movl %ecx, -0x4c(%ebp)\n" /* y0 */
        "movl %ecx, %edx\n"
        "addl $2, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl -0x50(%ebp), %eax\n" /* x0 */
        "addl $2, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "mulss 0x10(%ebp), %xmm0\n" /* sunVisibility */
        "movss %xmm0, -0x30(%ebp)\n"
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl $0, -0x54(%ebp)\n" /* cornerIndex */
        "movl $0, -0x44(%ebp)\n" /* z */
        "movl 0x14(%ebp), %eax\n" /* colorForDir */
        "addl $0x40, %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebp), %edx\n" /* colorForDir */
        "addl $0x20, %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        ".Lf107db6_00107e49:\n"
        "movl -0x38(%ebp), %eax\n" /* line 499 */
        "cmpl %eax, -0x4c(%ebp)\n" /* y0 */
        "jge .Lf107db6_00107e6c\n"
        "movl -0x4c(%ebp), %edi\n" /* y0, y */
        "movl $2, -0x28(%ebp)\n"
        ".Lf107db6_00107e5b:\n"
        "movl -0x34(%ebp), %eax\n" /* line 501 */
        "cmpl %eax, -0x50(%ebp)\n" /* x0 */
        "jl .Lf107db6_00107ebf\n"
        ".Lf107db6_00107e63:\n"
        "addl $1, %edi\n" /* line 499 | y */
        "subl $1, -0x28(%ebp)\n"
        "jne .Lf107db6_00107e5b\n"
        ".Lf107db6_00107e6c:\n"
        "addl $1, -0x44(%ebp)\n" /* line 497 | z */
        "cmpl $2, -0x44(%ebp)\n" /* z */
        "jne .Lf107db6_00107e49\n"
        "cvtsi2ssl -0x50(%ebp), %xmm0\n" /* line 527 | x0 */
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        "addss %xmm1, %xmm0\n"
        "mulss 0xce7108, %xmm0\n"
        "movl 0xc(%ebp), %eax\n" /* smodelInst */
        "movss %xmm0, 0x54(%eax)\n"
        "cvtsi2ssl -0x4c(%ebp), %xmm0\n" /* line 528 | y0 */
        "addss %xmm1, %xmm0\n"
        "mulss 0xce710c, %xmm0\n"
        "movss %xmm0, 0x58(%eax)\n"
        "movl $0x3f000000, 0x5c(%eax)\n" /* line 529 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: comparand */
        ".Lf107db6_00107ebf:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 428 */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x64(%ebp)\n"
        "cvttss2si -0x64(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "subl $0xff, %eax\n" /* line 178 */
        "movl %eax, -0x40(%ebp)\n" /* comparand */
        "movl -0x1c(%ebp), %edx\n"
        "negl %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* cornerIndex */
        "movl 0x14(%ebp), %edx\n" /* colorForDir */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x50(%ebp), %edx\n" /* x0 */
        "movl %edx, -0x48(%ebp)\n" /* x */
        "xorl %esi, %esi\n"
        ".Lf107db6_00107efd:\n"
        "movl -0x54(%ebp), %edx\n" /* line 463 | cornerIndex */
        "leal (%esi, %edx), %eax\n" /* world */
        "shll $2, %eax\n" /* line 503 */
        "movl -0x68(%ebp), %edx\n"
        "movss (%edx, %eax), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n"
        "movss (%edx, %eax), %xmm1\n"
        "movl -0x44(%ebp), %eax\n" /* line 504 | z */
        "imull 0xce7104, %eax\n"
        "leal (%edi, %eax, 2), %eax\n" /* y */
        "imull smodelLoadGlob, %eax\n"
        "movl -0x48(%ebp), %edx\n" /* x */
        "leal (%edx, %eax, 2), %eax\n"
        "movl 0xce7110, %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* smodelIndex */
        "movl -0x24(%ebp), %eax\n" /* line 428 */
        "movss (%eax), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "calll floorf\n"
        "fstps -0x58(%ebp)\n"
        "cvttss2si -0x58(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "movss -0x88(%ebp), %xmm1\n"
        "js .Lf107db6_00108040\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf107db6_00107f89:\n"
        "movb %dl, -0x2a(%ebp)\n"
        /* } scope */
        ".Lf107db6_00107f8c:\n"
        "mulss 0x2ed5d4, %xmm1\n" /* line 428 | 255.0f */
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x5c(%ebp)\n"
        "cvttss2si -0x5c(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lf107db6_0010806f\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf107db6_00107fc0:\n"
        "movb %dl, -0x29(%ebp)\n"
        /* } scope */
        ".Lf107db6_00107fc3:\n"
        "movss 0x2ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "mulss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x60(%ebp)\n"
        "cvttss2si -0x60(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lf107db6_00108063\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf107db6_00108002:\n"
        "movl %edx, %eax\n"
        /* } scope */
        /* { scope 2 */
        ".Lf107db6_00108004:\n"
        "movl -0x40(%ebp), %edx\n" /* comparand */
        "testl %edx, %edx\n"
        "js .Lf107db6_00108055\n"
        "movl $0xff, %edx\n"
        /* } scope */
        ".Lf107db6_00108010:\n"
        "movb %dl, (%ebx)\n" /* line 512 | smodelIndex */
        "movzbl -0x2a(%ebp), %edx\n"
        "movb %dl, 1(%ebx)\n" /* smodelIndex */
        "movzbl -0x29(%ebp), %edx\n"
        "movb %dl, 2(%ebx)\n" /* smodelIndex */
        "movb %al, 3(%ebx)\n" /* smodelIndex */
        "addl $1, -0x48(%ebp)\n" /* line 501 | x */
        "addl $1, %esi\n" /* world */
        "addl $4, -0x24(%ebp)\n"
        "cmpl $2, %esi\n" /* world */
        "jne .Lf107db6_00107efd\n"
        "addl $2, -0x54(%ebp)\n" /* cornerIndex */
        "jmp .Lf107db6_00107e63\n"
        ".Lf107db6_00108040:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf107db6_00107f89\n"
        "movb $0, -0x2a(%ebp)\n"
        "jmp .Lf107db6_00107f8c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf107db6_00108055:\n"
        "movl -0x1c(%ebp), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl -0x20(%ebp), %ecx\n"
        "testl %ecx, %ecx\n"
        "js .Lf107db6_00108010\n"
        "xorl %edx, %edx\n"
        "jmp .Lf107db6_00108010\n"
        /* } scope */
        ".Lf107db6_00108063:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf107db6_00108002\n"
        "xorl %eax, %eax\n"
        "jmp .Lf107db6_00108004\n"
        /* } scope */
        ".Lf107db6_0010806f:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf107db6_00107fc0\n"
        "movb $0, -0x29(%ebp)\n"
        "jmp .Lf107db6_00107fc3\n"
        /* } scope */
        ".Lf107db6_00108084:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 486 | smodelIndex */
        "shll $5, %eax\n"
        "addl 0x12c(%esi), %eax\n" /* world */
        "movl $0x60, 8(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* colorForDir */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x130(%esi), %eax\n" /* line 487 | world */
        "movss 0x10(%ebp), %xmm0\n" /* sunVisibility */
        "movss %xmm0, (%eax, %ebx, 4)\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 530 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 92 */
__attribute__((naked))
int R_SortGfxAabbTree(GfxWorld *world, GfxAabbTree *tree)
{
    __asm__ __volatile__ (
        ".Lf1080c2_001080c2:\n"
        "pushl %ebp\n" /* line 92 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* tree */
        /* { scope 1: childCount, childCount, childCount, childCount */
        ".Lf1080c2_001080d1:\n"
        "movl $CompareStaticModels, 0xc(%esp)\n" /* line 111 */
        "movl $4, 8(%esp)\n"
        "movl 0x20(%edi), %eax\n" /* tree */
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%edi), %eax\n" /* tree */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl 0x28(%edi), %eax\n" /* line 113 | tree */
        "testl %eax, %eax\n"
        "jne .Lf1080c2_00108602\n"
        "movl $0x7f7fffff, %eax\n" /* line 191 */
        "movl %eax, -0x24(%ebp)\n" /* mins */
        "movl %eax, -0x20(%ebp)\n" /* line 192 */
        "movl %eax, -0x1c(%ebp)\n" /* line 193 */
        "movl $0xff7fffff, %eax\n" /* line 191 */
        "movl %eax, -0x30(%ebp)\n" /* maxs */
        "movl %eax, -0x2c(%ebp)\n" /* line 192 */
        "movl %eax, -0x28(%ebp)\n" /* line 193 */
        "movl 0x20(%edi), %edx\n" /* line 123 | tree */
        "movl %edx, -0x60(%ebp)\n"
        "testl %edx, %edx\n"
        "jle .Lf1080c2_00108196\n"
        "movl 0x24(%edi), %esi\n" /* line 125 | tree, childIndex */
        "movl %esi, -0x5c(%ebp)\n" /* childIndex */
        "movl 8(%ebp), %eax\n" /* line 126 | world */
        "movl 0xf8(%eax), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "xorl %esi, %esi\n" /* childIndex */
        ".Lf1080c2_00108138:\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl (%edx, %esi, 4), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "shll $5, %eax\n"
        "movl -0x7c(%ebp), %edx\n"
        "addl %eax, %edx\n"
        "movl $1, %ebx\n" /* smodelChildIndex */
        ".Lf1080c2_0010814e:\n"
        "leal (, %ebx, 4), %ecx\n" /* line 92 */
        "leal -0x24(%ebp), %eax\n" /* mins */
        "addl %ecx, %eax\n"
        "movss 0x14(%edx), %xmm1\n" /* line 130 */
        "movss -4(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lf1080c2_0010816e\n"
        "movss %xmm1, -4(%eax)\n" /* line 131 */
        ".Lf1080c2_0010816e:\n"
        "leal -0x30(%ebp), %eax\n" /* line 92 | maxs */
        "addl %ecx, %eax\n"
        "movss 0x20(%edx), %xmm0\n" /* line 132 */
        "ucomiss -4(%eax), %xmm0\n"
        "jbe .Lf1080c2_00108183\n"
        "movss %xmm0, -4(%eax)\n" /* line 133 */
        ".Lf1080c2_00108183:\n"
        "addl $1, %ebx\n" /* smodelChildIndex */
        "addl $4, %edx\n"
        "cmpl $4, %ebx\n" /* line 128 | smodelChildIndex */
        "jne .Lf1080c2_0010814e\n"
        "addl $1, %esi\n" /* line 123 | childIndex */
        "cmpl -0x60(%ebp), %esi\n" /* childIndex */
        "jne .Lf1080c2_00108138\n"
        ".Lf1080c2_00108196:\n"
        "movl 0x18(%edi), %eax\n" /* line 137 | tree */
        "testl %eax, %eax\n"
        "jne .Lf1080c2_001081c3\n"
        "movl -0x24(%ebp), %eax\n" /* line 199 | mins */
        "movl %eax, (%edi)\n" /* tree */
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n" /* tree */
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edi)\n" /* tree */
        "leal 0xc(%edi), %edx\n" /* line 140 | tree, to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | maxs */
        "movl %eax, 0xc(%edi)\n" /* tree */
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf1080c2_001081c3:\n"
        "movl 0x20(%edi), %esi\n" /* line 143 | tree, childIndex */
        "movl %esi, -0x9c(%ebp)\n" /* childIndex, staticModelCount */
        "cmpl $7, %esi\n" /* childIndex */
        "jle .Lf1080c2_00108609\n"
        "movss -0x24(%ebp), %xmm1\n" /* line 240 | mins */
        "movss -0x30(%ebp), %xmm6\n" /* maxs */
        "movaps %xmm1, %xmm2\n"
        "addss %xmm6, %xmm2\n"
        "movss -0x20(%ebp), %xmm3\n" /* line 241 */
        "movss -0x2c(%ebp), %xmm7\n"
        "movaps %xmm3, %xmm5\n"
        "addss %xmm7, %xmm5\n"
        "movss -0x1c(%ebp), %xmm4\n" /* line 242 */
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movss 0x2ed5d8, %xmm0\n" /* line 272 | 0.5f */
        "mulss %xmm0, %xmm2\n"
        "mulss %xmm0, %xmm5\n" /* line 273 */
        "movl 0x24(%edi), %eax\n" /* line 149 | tree */
        "movl %eax, -0x78(%ebp)\n" /* staticModels */
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        "movl $0, -0x70(%ebp)\n" /* childCount */
        "movl %eax, %ecx\n"
        "movl %eax, -0x8c(%ebp)\n"
        /* { scope 2 */
        ".Lf1080c2_0010822d:\n"
        "movl (%ecx), %edx\n" /* line 60 */
        "leal (%edx, %edx, 2), %eax\n" /* line 61 */
        "shll $5, %eax\n"
        "movl 8(%ebp), %esi\n" /* world */
        "addl 0xf8(%esi), %eax\n"
        "ucomiss 0x14(%eax), %xmm1\n" /* line 63 */
        "ja .Lf1080c2_00108288\n"
        "ucomiss 0x18(%eax), %xmm3\n" /* line 65 */
        "ja .Lf1080c2_00108288\n"
        "ucomiss 0x1c(%eax), %xmm4\n" /* line 67 */
        "ja .Lf1080c2_00108288\n"
        "movss 0x20(%eax), %xmm0\n" /* line 69 */
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lf1080c2_00108288\n"
        "movss 0x24(%eax), %xmm0\n" /* line 71 */
        "ucomiss %xmm7, %xmm0\n"
        "ja .Lf1080c2_00108288\n"
        "movss 0x28(%eax), %xmm0\n" /* line 73 */
        "ucomiss -0x74(%ebp), %xmm0\n"
        "ja .Lf1080c2_00108288\n"
        "movl -0x8c(%ebp), %esi\n" /* line 76 */
        "movl (%esi), %eax\n"
        "movl %edx, (%esi)\n" /* line 77 */
        "movl %eax, (%ecx)\n" /* line 78 */
        "addl $1, -0x70(%ebp)\n" /* line 79 | childCount */
        "addl $4, %esi\n"
        "movl %esi, -0x8c(%ebp)\n"
        ".Lf1080c2_00108288:\n"
        "addl $1, %ebx\n" /* line 58 | smodelChildIndex */
        "addl $4, %ecx\n"
        "cmpl %ebx, -0x9c(%ebp)\n" /* smodelChildIndex, staticModelCount */
        "jne .Lf1080c2_0010822d\n"
        "cmpl $1, -0x70(%ebp)\n" /* line 82 | childCount */
        "jle .Lf1080c2_001085f1\n"
        "movl -0x70(%ebp), %eax\n" /* childCount */
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf1080c2_001082a5:\n"
        "movl %edx, -0x40(%ebp)\n" /* line 156 | childCount */
        "movl -0x78(%ebp), %esi\n" /* line 157 | staticModels, childIndex */
        "leal (%esi, %eax, 4), %eax\n" /* childIndex */
        "movl %eax, -0x54(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 158 | staticModelCount */
        "subl %edx, %eax\n"
        "movl %eax, -0x9c(%ebp)\n" /* staticModelCount */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 58 */
        "jle .Lf1080c2_001085e0\n"
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        "movl $0, -0x6c(%ebp)\n" /* childCount */
        "movl -0x54(%ebp), %ecx\n"
        "movl %ecx, -0x88(%ebp)\n"
        ".Lf1080c2_001082d9:\n"
        "movl (%ecx), %edx\n" /* line 60 */
        "leal (%edx, %edx, 2), %eax\n" /* line 61 */
        "shll $5, %eax\n"
        "movl 8(%ebp), %esi\n" /* world */
        "addl 0xf8(%esi), %eax\n"
        "ucomiss 0x14(%eax), %xmm2\n" /* line 63 */
        "ja .Lf1080c2_00108334\n"
        "ucomiss 0x18(%eax), %xmm3\n" /* line 65 */
        "ja .Lf1080c2_00108334\n"
        "ucomiss 0x1c(%eax), %xmm4\n" /* line 67 */
        "ja .Lf1080c2_00108334\n"
        "movss 0x20(%eax), %xmm0\n" /* line 69 */
        "ucomiss %xmm6, %xmm0\n"
        "ja .Lf1080c2_00108334\n"
        "movss 0x24(%eax), %xmm0\n" /* line 71 */
        "ucomiss %xmm7, %xmm0\n"
        "ja .Lf1080c2_00108334\n"
        "movss 0x28(%eax), %xmm0\n" /* line 73 */
        "ucomiss -0x74(%ebp), %xmm0\n"
        "ja .Lf1080c2_00108334\n"
        "movl -0x88(%ebp), %esi\n" /* line 76 */
        "movl (%esi), %eax\n"
        "movl %edx, (%esi)\n" /* line 77 */
        "movl %eax, (%ecx)\n" /* line 78 */
        "addl $1, -0x6c(%ebp)\n" /* line 79 | childCount */
        "addl $4, %esi\n"
        "movl %esi, -0x88(%ebp)\n"
        ".Lf1080c2_00108334:\n"
        "addl $1, %ebx\n" /* line 58 | smodelChildIndex */
        "addl $4, %ecx\n"
        "cmpl %ebx, -0x9c(%ebp)\n" /* smodelChildIndex, staticModelCount */
        "jne .Lf1080c2_001082d9\n"
        "cmpl $1, -0x6c(%ebp)\n" /* line 82 | childCount */
        "jle .Lf1080c2_001085e0\n"
        "movl -0x6c(%ebp), %eax\n" /* childCount */
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf1080c2_00108351:\n"
        "movl %edx, -0x3c(%ebp)\n" /* line 164 */
        "movl -0x54(%ebp), %esi\n" /* line 165 | childIndex */
        "leal (%esi, %eax, 4), %eax\n" /* childIndex */
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 166 | staticModelCount */
        "subl %edx, %eax\n"
        "movl %eax, -0x9c(%ebp)\n" /* staticModelCount */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 58 */
        "jle .Lf1080c2_001085cf\n"
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        "movl $0, -0x68(%ebp)\n" /* childCount */
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, -0x84(%ebp)\n"
        ".Lf1080c2_00108385:\n"
        "movl (%ecx), %edx\n" /* line 60 */
        "leal (%edx, %edx, 2), %eax\n" /* line 61 */
        "shll $5, %eax\n"
        "movl 8(%ebp), %esi\n" /* world */
        "addl 0xf8(%esi), %eax\n"
        "ucomiss 0x14(%eax), %xmm1\n" /* line 63 */
        "ja .Lf1080c2_001083e0\n"
        "ucomiss 0x18(%eax), %xmm3\n" /* line 65 */
        "ja .Lf1080c2_001083e0\n"
        "ucomiss 0x1c(%eax), %xmm4\n" /* line 67 */
        "ja .Lf1080c2_001083e0\n"
        "movss 0x20(%eax), %xmm0\n" /* line 69 */
        "ucomiss %xmm6, %xmm0\n"
        "ja .Lf1080c2_001083e0\n"
        "movss 0x24(%eax), %xmm0\n" /* line 71 */
        "ucomiss %xmm5, %xmm0\n"
        "ja .Lf1080c2_001083e0\n"
        "movss 0x28(%eax), %xmm0\n" /* line 73 */
        "ucomiss -0x74(%ebp), %xmm0\n"
        "ja .Lf1080c2_001083e0\n"
        "movl -0x84(%ebp), %esi\n" /* line 76 */
        "movl (%esi), %eax\n"
        "movl %edx, (%esi)\n" /* line 77 */
        "movl %eax, (%ecx)\n" /* line 78 */
        "addl $1, -0x68(%ebp)\n" /* line 79 | childCount */
        "addl $4, %esi\n"
        "movl %esi, -0x84(%ebp)\n"
        ".Lf1080c2_001083e0:\n"
        "addl $1, %ebx\n" /* line 58 | smodelChildIndex */
        "addl $4, %ecx\n"
        "cmpl %ebx, -0x9c(%ebp)\n" /* smodelChildIndex, staticModelCount */
        "jne .Lf1080c2_00108385\n"
        "cmpl $1, -0x68(%ebp)\n" /* line 82 | childCount */
        "jle .Lf1080c2_001085cf\n"
        "movl -0x68(%ebp), %eax\n" /* childCount */
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf1080c2_001083fd:\n"
        "movl %edx, -0x38(%ebp)\n" /* line 172 */
        "movl -0x4c(%ebp), %esi\n" /* line 173 | childIndex */
        "leal (%esi, %eax, 4), %eax\n" /* childIndex */
        "movl -0x9c(%ebp), %esi\n" /* line 174 | staticModelCount, childIndex */
        "subl %edx, %esi\n" /* childIndex */
        "movl %esi, -0x9c(%ebp)\n" /* childIndex, staticModelCount */
        /* { scope 2 */
        "testl %esi, %esi\n" /* line 58 */
        "jle .Lf1080c2_001085c3\n"
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        "movl $0, -0x64(%ebp)\n" /* childCount */
        "movl %eax, %ecx\n"
        "movl %eax, -0x80(%ebp)\n"
        ".Lf1080c2_0010842a:\n"
        "movl (%ecx), %edx\n" /* line 60 */
        "leal (%edx, %edx, 2), %eax\n" /* line 61 */
        "shll $5, %eax\n"
        "movl 8(%ebp), %esi\n" /* world */
        "addl 0xf8(%esi), %eax\n"
        "ucomiss 0x14(%eax), %xmm1\n" /* line 63 */
        "ja .Lf1080c2_0010847f\n"
        "ucomiss 0x18(%eax), %xmm5\n" /* line 65 */
        "ja .Lf1080c2_0010847f\n"
        "ucomiss 0x1c(%eax), %xmm4\n" /* line 67 */
        "ja .Lf1080c2_0010847f\n"
        "movss 0x20(%eax), %xmm0\n" /* line 69 */
        "ucomiss %xmm6, %xmm0\n"
        "ja .Lf1080c2_0010847f\n"
        "movss 0x24(%eax), %xmm0\n" /* line 71 */
        "ucomiss %xmm7, %xmm0\n"
        "ja .Lf1080c2_0010847f\n"
        "movss 0x28(%eax), %xmm0\n" /* line 73 */
        "ucomiss -0x74(%ebp), %xmm0\n"
        "ja .Lf1080c2_0010847f\n"
        "movl -0x80(%ebp), %esi\n" /* line 76 */
        "movl (%esi), %eax\n"
        "movl %edx, (%esi)\n" /* line 77 */
        "movl %eax, (%ecx)\n" /* line 78 */
        "addl $1, -0x64(%ebp)\n" /* line 79 | childCount */
        "addl $4, %esi\n"
        "movl %esi, -0x80(%ebp)\n"
        ".Lf1080c2_0010847f:\n"
        "addl $1, %ebx\n" /* line 58 | smodelChildIndex */
        "addl $4, %ecx\n"
        "cmpl %ebx, -0x9c(%ebp)\n" /* smodelChildIndex, staticModelCount */
        "jne .Lf1080c2_0010842a\n"
        "cmpl $1, -0x64(%ebp)\n" /* line 82 | childCount */
        "jle .Lf1080c2_001085c3\n"
        /* } scope */
        ".Lf1080c2_00108497:\n"
        "movl -0x64(%ebp), %eax\n" /* line 180 | childCount */
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x9c(%ebp), %ebx\n" /* line 182 | staticModelCount, smodelChildIndex */
        "subl %eax, %ebx\n" /* smodelChildIndex */
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf1080c2_001084a9:\n"
        "xorl %eax, %eax\n" /* line 187 */
        "cmpl $0, -0x40(%ebp, %edx, 4)\n"
        "setne %al\n"
        "addl %eax, %ecx\n"
        "addl $1, %edx\n" /* line 186 */
        "cmpl $4, %edx\n"
        "jne .Lf1080c2_001084a9\n"
        "testl %ecx, %ecx\n" /* line 189 */
        "je .Lf1080c2_00108609\n"
        "cmpl $1, 0x18(%edi)\n" /* line 193 | tree */
        "sbbl $-1, %ecx\n"
        "cmpl $1, %ebx\n" /* line 196 | smodelChildIndex */
        "sbbl $-1, %ecx\n"
        "movl $4, 4(%esp)\n" /* line 198 */
        "leal (%ecx, %ecx, 2), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ecx\n"
        "movl %eax, 0x2c(%edi)\n" /* tree */
        "movl 0x18(%edi), %esi\n" /* line 200 | tree, childIndex */
        "testl %esi, %esi\n" /* childIndex */
        "je .Lf1080c2_0010853a\n"
        "movl 0x28(%edi), %eax\n" /* line 202 | tree */
        "leal (%eax, %eax, 2), %edx\n"
        "shll $4, %edx\n"
        "leal (%ecx, %edx), %edx\n"
        "addl $1, %eax\n" /* line 203 */
        "movl %eax, 0x28(%edi)\n" /* tree */
        "movl (%edi), %eax\n" /* line 199 | tree */
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %eax\n" /* line 200 | tree */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | tree */
        "movl %eax, 8(%edx)\n"
        "leal 0xc(%edx), %ebx\n" /* line 205 | to */
        "leal 0xc(%edi), %ecx\n" /* tree, from */
        /* { scope 2 */
        "movl 0xc(%edi), %eax\n" /* line 199 | tree */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n" /* smodelChildIndex */
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n" /* smodelChildIndex */
        /* } scope */
        "movl 0x1c(%edi), %eax\n" /* line 206 | tree */
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x18(%edi), %eax\n" /* line 207 | tree */
        "movl %eax, 0x18(%edx)\n"
        ".Lf1080c2_0010853a:\n"
        "movl 0x24(%edi), %edx\n" /* line 210 | tree */
        "movl %edx, -0x50(%ebp)\n"
        "movl 0x20(%edi), %esi\n" /* line 211 | tree, childIndex */
        "movl %esi, -0x58(%ebp)\n" /* childIndex */
        "movl $1, %esi\n" /* childIndex */
        ".Lf1080c2_0010854b:\n"
        "movl -0x44(%ebp, %esi, 4), %ebx\n" /* line 215 | to */
        "testl %ebx, %ebx\n" /* line 216 | to */
        "jne .Lf1080c2_0010858b\n"
        ".Lf1080c2_00108553:\n"
        "addl $1, %esi\n" /* line 224 | childIndex */
        "cmpl $5, %esi\n" /* line 213 | childIndex */
        "jne .Lf1080c2_0010854b\n"
        "movl -0x58(%ebp), %ebx\n" /* line 227 | to */
        "testl %ebx, %ebx\n" /* to */
        "je .Lf1080c2_00108609\n"
        "movl 0x28(%edi), %edx\n" /* line 229 | tree */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl 0x2c(%edi), %eax\n" /* tree */
        "addl $1, %edx\n" /* line 230 */
        "movl %edx, 0x28(%edi)\n" /* tree */
        "movl -0x58(%ebp), %esi\n" /* line 231 | childIndex */
        "movl %esi, 0x20(%eax)\n" /* childIndex */
        "movl -0x50(%ebp), %edx\n" /* line 232 */
        "movl %edx, 0x24(%eax)\n"
        "movl %eax, %edi\n" /* tree */
        "jmp .Lf1080c2_001080d1\n"
        ".Lf1080c2_0010858b:\n"
        "movl 0x28(%edi), %edx\n" /* line 218 | tree */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $4, %eax\n"
        "addl 0x2c(%edi), %eax\n" /* tree */
        "addl $1, %edx\n" /* line 219 */
        "movl %edx, 0x28(%edi)\n" /* tree */
        "movl %ebx, 0x20(%eax)\n" /* line 220 | to */
        "movl -0x50(%ebp), %edx\n" /* line 221 */
        "movl %edx, 0x24(%eax)\n"
        "movl %eax, 4(%esp)\n" /* line 222 */
        "movl 8(%ebp), %eax\n" /* world */
        "movl %eax, (%esp)\n"
        "calll R_SortGfxAabbTree\n"
        "movl -0x50(%ebp), %edx\n" /* line 223 */
        "leal (%edx, %ebx, 4), %edx\n"
        "movl %edx, -0x50(%ebp)\n"
        "subl %ebx, -0x58(%ebp)\n" /* line 224 | to */
        "jmp .Lf1080c2_00108553\n"
        /* { scope 2 */
        ".Lf1080c2_001085c3:\n"
        "movl $0, -0x64(%ebp)\n" /* line 82 | childCount */
        "jmp .Lf1080c2_00108497\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1080c2_001085cf:\n"
        "movl $0, -0x68(%ebp)\n" /* childCount */
        "xorl %eax, %eax\n"
        "movl -0x68(%ebp), %edx\n" /* childCount */
        "jmp .Lf1080c2_001083fd\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1080c2_001085e0:\n"
        "movl $0, -0x6c(%ebp)\n" /* childCount */
        "xorl %eax, %eax\n"
        "movl -0x6c(%ebp), %edx\n" /* childCount */
        "jmp .Lf1080c2_00108351\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1080c2_001085f1:\n"
        "movl $0, -0x70(%ebp)\n" /* childCount */
        "xorl %eax, %eax\n"
        "movl -0x70(%ebp), %edx\n" /* childCount */
        "jmp .Lf1080c2_001082a5\n"
        /* } scope */
        ".Lf1080c2_00108602:\n"
        "movl 0x28(%edi), %ecx\n" /* line 115 | tree */
        "testl %ecx, %ecx\n"
        "jg .Lf1080c2_00108614\n"
        /* } scope */
        ".Lf1080c2_00108609:\n"
        "addl $0xac, %esp\n" /* line 235 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: childCount, childCount, childCount, childCount */
        ".Lf1080c2_00108614:\n"
        "xorl %esi, %esi\n" /* line 115 | childIndex */
        "xorl %ebx, %ebx\n" /* smodelChildIndex */
        ".Lf1080c2_00108618:\n"
        "movl %ebx, %eax\n" /* line 116 | smodelChildIndex */
        "addl 0x2c(%edi), %eax\n" /* tree */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* world */
        "movl %eax, (%esp)\n"
        "calll R_SortGfxAabbTree\n"
        "addl $1, %esi\n" /* line 115 | childIndex */
        "addl $0x30, %ebx\n" /* smodelChildIndex */
        "cmpl %esi, 0x28(%edi)\n" /* childIndex, tree */
        "jg .Lf1080c2_00108618\n"
        "jmp .Lf1080c2_00108609\n"
    );
}

/* line 28 */
__attribute__((naked))
int R_AllocStaticModels(GfxAabbTree *tree)
{
    __asm__ __volatile__ (
        ".Lf10863a_0010863a:\n"
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: tree */
        "movl 8(%ebp), %edx\n" /* line 33 | tree */
        "movl 0x20(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf10863a_00108684\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl 8(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        ".Lf10863a_00108684:\n"
        "movl 8(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %edi\n" /* childIndex */
        "testl %edi, %edi\n" /* childIndex */
        "jle .Lf10863a_00108ae3\n"
        "movl $0, -0x74(%ebp)\n" /* childIndex */
        "movl $0, -0x1c(%ebp)\n"
        ".Lf10863a_001086a0:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 41 */
        "movl 8(%ebp), %ecx\n" /* tree */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* tree */
        /* { scope 2: childIndex */
        /* { scope 3: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_001086ea\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x70(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x70(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        ".Lf10863a_001086ea:\n"
        "movl -0x70(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf10863a_00108acc\n"
        "movl $0, -0x6c(%ebp)\n" /* childIndex */
        "movl $0, -0x20(%ebp)\n"
        ".Lf10863a_00108706:\n"
        "movl -0x20(%ebp), %eax\n" /* line 41 */
        "movl -0x70(%ebp), %ecx\n" /* tree */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x68(%ebp)\n" /* tree */
        /* { scope 4: childIndex */
        /* { scope 5: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_00108750\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x68(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x68(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        ".Lf10863a_00108750:\n"
        "movl -0x68(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lf10863a_00108ab5\n"
        "movl $0, -0x64(%ebp)\n" /* childIndex */
        "movl $0, -0x24(%ebp)\n"
        ".Lf10863a_0010876c:\n"
        "movl -0x24(%ebp), %eax\n" /* line 41 */
        "movl -0x68(%ebp), %ecx\n" /* tree */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x60(%ebp)\n" /* tree */
        /* { scope 6: childIndex */
        /* { scope 7: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_001087b6\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x60(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x60(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        ".Lf10863a_001087b6:\n"
        "movl -0x60(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf10863a_00108a9e\n"
        "movl $0, -0x5c(%ebp)\n" /* childIndex */
        "movl $0, -0x28(%ebp)\n"
        ".Lf10863a_001087d2:\n"
        "movl -0x28(%ebp), %eax\n" /* line 41 */
        "movl -0x60(%ebp), %ecx\n" /* tree */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* tree */
        /* { scope 8: childIndex */
        /* { scope 9: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_0010881c\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x58(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x58(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        ".Lf10863a_0010881c:\n"
        "movl -0x58(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf10863a_00108a87\n"
        "movl $0, -0x54(%ebp)\n" /* childIndex */
        "movl $0, -0x2c(%ebp)\n"
        "movl -0x58(%ebp), %ecx\n" /* tree */
        "movl -0x2c(%ebp), %eax\n" /* line 41 */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* tree */
        /* { scope 10: childIndex */
        /* { scope 11: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "jne .Lf10863a_00108a4b\n"
        ".Lf10863a_0010884f:\n"
        "movl -0x50(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf10863a_00108a22\n"
        "movl $0, -0x4c(%ebp)\n" /* childIndex */
        "movl $0, -0x30(%ebp)\n"
        "movl -0x50(%ebp), %ecx\n" /* tree */
        "movl -0x30(%ebp), %eax\n" /* line 41 */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* tree */
        /* { scope 12: childIndex */
        /* { scope 13: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "jne .Lf10863a_001089aa\n"
        ".Lf10863a_00108882:\n"
        "movl -0x48(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf10863a_0010897d\n"
        "movl $0, -0x44(%ebp)\n" /* childIndex */
        "movl $0, -0x34(%ebp)\n"
        "movl -0x48(%ebp), %ecx\n" /* tree */
        ".Lf10863a_001088a1:\n"
        "movl -0x34(%ebp), %eax\n" /* line 41 */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* tree */
        /* { scope 14: childIndex */
        /* { scope 15 */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "jne .Lf10863a_001089e6\n"
        ".Lf10863a_001088b5:\n"
        "movl -0x40(%ebp), %edx\n" /* line 40 | tree */
        "movl 0x28(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf10863a_00108966\n"
        "movl $0, -0x3c(%ebp)\n" /* childIndex */
        "movl $0, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %ecx\n" /* tree */
        "jmp .Lf10863a_001088f2\n"
        /* { scope 16 */
        /* { scope 17 */
        ".Lf10863a_001088d6:\n"
        "movl 0x28(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf10863a_00108937\n"
        /* } scope */
        /* } scope */
        ".Lf10863a_001088dd:\n"
        "addl $1, -0x3c(%ebp)\n" /* childIndex */
        "addl $0x30, -0x38(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n" /* childIndex */
        "movl -0x40(%ebp), %eax\n" /* tree */
        "cmpl 0x28(%eax), %edx\n"
        "jge .Lf10863a_00108966\n"
        ".Lf10863a_001088f0:\n"
        "movl %eax, %ecx\n"
        ".Lf10863a_001088f2:\n"
        "movl -0x38(%ebp), %esi\n" /* line 41 | tree */
        "addl 0x2c(%ecx), %esi\n" /* tree */
        /* { scope 16 */
        /* { scope 17 */
        "movl 0x20(%esi), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_001088d6\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl 0x20(%esi), %eax\n" /* line 36 */
        "shll $2, %eax\n"
        "movl 0x24(%esi), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl %ebx, 0x24(%esi)\n" /* line 37 */
        "movl 0x28(%esi), %eax\n" /* line 40 */
        "testl %eax, %eax\n"
        "jle .Lf10863a_001088dd\n"
        ".Lf10863a_00108937:\n"
        "xorl %edi, %edi\n" /* childIndex */
        "xorl %ebx, %ebx\n"
        ".Lf10863a_0010893b:\n"
        "movl %ebx, %eax\n" /* line 41 */
        "addl 0x2c(%esi), %eax\n" /* tree */
        "movl %eax, (%esp)\n"
        "calll R_AllocStaticModels\n"
        "addl $1, %edi\n" /* line 40 | childIndex */
        "addl $0x30, %ebx\n"
        "cmpl 0x28(%esi), %edi\n" /* childIndex */
        "jl .Lf10863a_0010893b\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x3c(%ebp)\n" /* childIndex */
        "addl $0x30, -0x38(%ebp)\n"
        "movl -0x3c(%ebp), %edx\n" /* childIndex */
        "movl -0x40(%ebp), %eax\n" /* tree */
        "cmpl 0x28(%eax), %edx\n"
        "jl .Lf10863a_001088f0\n"
        /* } scope */
        /* } scope */
        ".Lf10863a_00108966:\n"
        "addl $1, -0x44(%ebp)\n" /* childIndex */
        "addl $0x30, -0x34(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* childIndex */
        "movl -0x48(%ebp), %ecx\n" /* tree */
        "cmpl 0x28(%ecx), %eax\n"
        "jl .Lf10863a_001088a1\n"
        /* } scope */
        /* } scope */
        ".Lf10863a_0010897d:\n"
        "addl $1, -0x4c(%ebp)\n" /* childIndex */
        "addl $0x30, -0x30(%ebp)\n"
        "movl -0x4c(%ebp), %ecx\n" /* childIndex */
        "movl -0x50(%ebp), %edx\n" /* tree */
        "cmpl 0x28(%edx), %ecx\n"
        "jge .Lf10863a_00108a22\n"
        "movl %edx, %ecx\n"
        "movl -0x30(%ebp), %eax\n" /* line 41 */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* tree */
        /* { scope 12: childIndex */
        /* { scope 13: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_00108882\n"
        ".Lf10863a_001089aa:\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x48(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x48(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        "jmp .Lf10863a_00108882\n"
        /* { scope 14: childIndex */
        /* { scope 15 */
        ".Lf10863a_001089e6:\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x40(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x40(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        "jmp .Lf10863a_001088b5\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf10863a_00108a22:\n"
        "addl $1, -0x54(%ebp)\n" /* line 40 | childIndex */
        "addl $0x30, -0x2c(%ebp)\n"
        "movl -0x54(%ebp), %edx\n" /* childIndex */
        "movl -0x58(%ebp), %eax\n" /* tree */
        "cmpl 0x28(%eax), %edx\n"
        "jge .Lf10863a_00108a87\n"
        "movl %eax, %ecx\n"
        "movl -0x2c(%ebp), %eax\n" /* line 41 */
        "addl 0x2c(%ecx), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* tree */
        /* { scope 10: childIndex */
        /* { scope 11: tree */
        "movl 0x20(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf10863a_0010884f\n"
        ".Lf10863a_00108a4b:\n"
        "movl $4, 4(%esp)\n" /* line 35 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocAlignInternal\n"
        "movl %eax, %ebx\n"
        "movl -0x50(%ebp), %ecx\n" /* line 36 | tree */
        "movl 0x20(%ecx), %eax\n"
        "shll $2, %eax\n"
        "movl 0x24(%ecx), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x50(%ebp), %eax\n" /* line 37 | tree */
        "movl %ebx, 0x24(%eax)\n"
        "jmp .Lf10863a_0010884f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf10863a_00108a87:\n"
        "addl $1, -0x5c(%ebp)\n" /* line 40 | childIndex */
        "addl $0x30, -0x28(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* childIndex */
        "movl -0x60(%ebp), %ecx\n" /* tree */
        "cmpl 0x28(%ecx), %eax\n"
        "jl .Lf10863a_001087d2\n"
        /* } scope */
        /* } scope */
        ".Lf10863a_00108a9e:\n"
        "addl $1, -0x64(%ebp)\n" /* childIndex */
        "addl $0x30, -0x24(%ebp)\n"
        "movl -0x64(%ebp), %ecx\n" /* childIndex */
        "movl -0x68(%ebp), %edx\n" /* tree */
        "cmpl %ecx, 0x28(%edx)\n"
        "jg .Lf10863a_0010876c\n"
        /* } scope */
        /* } scope */
        ".Lf10863a_00108ab5:\n"
        "addl $1, -0x6c(%ebp)\n" /* childIndex */
        "addl $0x30, -0x20(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n" /* childIndex */
        "movl -0x70(%ebp), %eax\n" /* tree */
        "cmpl 0x28(%eax), %edx\n"
        "jl .Lf10863a_00108706\n"
        /* } scope */
        /* } scope */
        ".Lf10863a_00108acc:\n"
        "addl $1, -0x74(%ebp)\n" /* childIndex */
        "addl $0x30, -0x1c(%ebp)\n"
        "movl -0x74(%ebp), %eax\n" /* childIndex */
        "movl 8(%ebp), %ecx\n" /* tree */
        "cmpl 0x28(%ecx), %eax\n"
        "jl .Lf10863a_001086a0\n"
        /* } scope */
        ".Lf10863a_00108ae3:\n"
        "addl $0x7c, %esp\n" /* line 42 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

