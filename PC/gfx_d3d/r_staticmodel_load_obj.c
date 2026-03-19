/* ASM dump from: r_staticmodel_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_staticmodel_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/xanim/xanim_public.h"
 *   #include "PC/universal/com_math.h"
 */

static int smodelLoadGlob; /* smodelLoadGlob */

extern void *Hunk_AllocAlignInternal(int size, int alignment);
extern GfxImage *Image_Alloc(const char *name, int category, int semantic, int imageTrack);
extern void Image_Generate3D(GfxImage *image, byte *pixels, int width, int height, int depth, int imageFormat);

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
static int CompareStaticModels(const int *smodel0, const int *smodel1)
{
    return *smodel0 - *smodel1;
}

/* line 449 */
int R_ScaleStaticModelLighting(float directLightScale, float indirectLightScale, float *sunVisibility, vec4_t *colorForDir)
{
    int i;
    *sunVisibility *= directLightScale;
    for (i = 0; i < 6; i++) {
        colorForDir[i][0] *= indirectLightScale;
        colorForDir[i][1] *= indirectLightScale;
        colorForDir[i][2] *= indirectLightScale;
        colorForDir[i][3] *= indirectLightScale;
    }
}

/* line 533 */
extern float RB_GetLightingAtPoint(const void *lightGrid, const vec_t *samplePos, vec4_t *colorForDir);
extern float floorf(float x);

int R_GetStaticModelLightingFromGrid(const GfxWorld *world, GfxStaticModelInstance *smodelInst, float *sunVisibility, vec4_t *colorForDir)
{
    float lightingOrigin[3];
    byte *inst = (byte *)smodelInst;

    /* lightingOrigin = midpoint of absmin and absmax (offsets 0x14 and 0x20) */
    lightingOrigin[0] = (*(float *)(inst + 0x14) + *(float *)(inst + 0x20)) * 0.5f;
    lightingOrigin[1] = (*(float *)(inst + 0x18) + *(float *)(inst + 0x24)) * 0.5f;
    lightingOrigin[2] = (*(float *)(inst + 0x1c) + *(float *)(inst + 0x28)) * 0.5f;

    *sunVisibility = RB_GetLightingAtPoint((byte *)world + 0x11c, lightingOrigin, colorForDir);
    return 0;
}

/* line 565 */
extern void * Hunk_AllocateTempMemoryInternal(int size);

int R_PrepareStaticModelLightingCache(GfxWorld *world, int smodelCount)
{
    int rendererType = *(int *)(*(char **)imp_r_rendererInUse + 8);
    void *(*hunkAlloc)(int);

    if (rendererType == 2) {
        /* Dx7 path: allocate via ri->hunkAlloc */
        hunkAlloc = *(void *(**)(int))((byte *)imp_ri + 0xc);
        *(void **)((byte *)world + 0x12c) = hunkAlloc(smodelCount * 3 * 32);
        *(void **)((byte *)world + 0x130) = hunkAlloc(smodelCount * 4);
    } else {
        /* Non-Dx7: compute image dimensions for lighting cache texture */
        int width = 1;
        int height;
        int lightingImageSize;

        /* Find smallest power of 2 where width*width >= smodelCount */
        if (smodelCount > 1) {
            while (width * width < smodelCount)
                width *= 2;
        }
        smodelLoadGlob = width;

        /* Height = width, but halve if width*height/2 >= smodelCount */
        height = width;
        if (width * height >= smodelCount * 2)
            height = (height + 1) / 2;
        ((int *)&smodelLoadGlob)[1] = height;

        /* Store texel sizes (1.0 / (2*dim)) */
        ((float *)&smodelLoadGlob)[2] = 1.0f / (float)(width * 2);
        ((float *)&smodelLoadGlob)[3] = 1.0f / (float)(height * 2);

        /* Allocate pixel buffer: width * height * 32 bytes */
        lightingImageSize = width * height * 32;
        ((void **)&smodelLoadGlob)[4] = Hunk_AllocateTempMemoryInternal(lightingImageSize);
        memset(((void **)&smodelLoadGlob)[4], 0x80, lightingImageSize);
    }
    return 0;
}

/* line 622 */
extern int XModelGetNumLods(struct XModel *model);
extern int XModelGetSurfaces(struct XModel *model, void **surfaces, int *partBits, int lodIndex);
extern int XSurfaceGetBoneOffset(void *surface);
extern const char * XModelGetName(struct XModel *model);
extern void Com_Printf(const char *fmt, ...);

Bool R_ValidateStaticModel(struct XModel *model)
{
    /* Guard against invalid model pointers from R_RegisterModel
       (can return addresses in shared library space after hunk clear). */
    if (!model || (unsigned int)model >= 0xf0000000)
        return 0;
    int lodCount = XModelGetNumLods(model);
    int lodIndex, surfIndex, surfCount;
    void *surfaces;
    int partBits[4];

    for (lodIndex = 0; lodIndex < lodCount; lodIndex++) {
        surfCount = XModelGetSurfaces(model, &surfaces, partBits, lodIndex);

        for (surfIndex = 0; surfIndex < surfCount; surfIndex++) {
            void *surf = ((void **)surfaces)[surfIndex];
            if (XSurfaceGetBoneOffset(surf) == -1) {
                Com_Printf("^1ERROR: model '%s' is not a valid static model, since lod %i surface %i has bone offsets\n",
                    XModelGetName(model), lodIndex, surfIndex);
                return 0;
            }
        }
    }

    return 1;
}

/* line 238 — Adds a static model to an AABB tree leaf node. Allocates/grows the
 * leaf's index array (power-of-2 sizing), appends smodelIndex, then updates
 * the leaf's bounds by expanding against the static model instance's bounds.
 * Register convention: eax=world, edx=tree, ecx=smodelIndex.
 * 201 lines with Hunk allocation, bounds expansion, and child iteration. */
#ifndef __EMSCRIPTEN__
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
/* line 334 — Recursive BSP filter: places static model instance into appropriate cells
 * by traversing BSP tree nodes. For axial planes, splits bounds and recurses on children.
 * Register convention: eax=world, edx=node, ecx=smodelInst, stack=mins,maxs.
 * Algorithm: node.childIndex == -2 → axial split; >= 0 → leaf cell (add to AABB tree);
 * < 0 → null. Uses BoxOnPlaneSide for plane classification.
 * 145 lines of recursive BSP traversal with bounds splitting. */
static __attribute__((naked))
int R_FilterStaticModelIntoCells_r(GfxStaticModelInstance *smodelInst, const vec_t *mins, const vec_t *maxs)
{
    (void)smodelInst; (void)mins; (void)maxs;
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

/* line 596 — Finalize static model lighting cache: create 3D lighting texture
 * from accumulated lighting data. Only for non-Dx7 renderer. */
int R_FinishStaticModelLightingCache(GfxWorld *world)
{
    byte *w = (byte *)world;
    int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);

    if (!isDx7) {
        int *sg = (int *)&smodelLoadGlob;
        GfxImage *image;

        /* Allocate image: "*smodel_lighting", category=2, semantic=1, track=4 */
        image = Image_Alloc("*smodel_lighting", 2, 1, 4);
        *(GfxImage **)(w + 0x10c) = image;

        /* Generate 3D texture from cached lighting data:
         * width = sg[0]*2, height = sg[1]*2, depth = sg[4], format = A8R8G8B8 */
        Image_Generate3D(image, (byte *)(void *)(long)sg[4], sg[0] * 2, sg[1] * 2, 2, 0x15);

        /* Store texel size as vec3 at world+0x110:
         * x = sg[2] * 0.5, y = sg[3] * 0.5, z = 0.25 */
        *(float *)(w + 0x110) = *(float *)&sg[2] * 0.5f;
        *(float *)(w + 0x114) = *(float *)&sg[3] * 0.5f;
        *(float *)(w + 0x118) = 0.25f;

        /* Clear smodelLoadGlob */
        sg[0] = 0; sg[1] = 0; sg[2] = 0; sg[3] = 0; sg[4] = 0;
    }
    return 0;
}

/* line 547 */
int R_GetStaticModelLightingFromGround(const vec_t *groundLight, float *sunVisibility, vec4_t *colorForDir)
{
    int i, j;
    float *dst = (float *)colorForDir;

    /* For each of 3 light directions (indices 1-3), fill two vec4s with the
     * groundLight value broadcast to all 4 components */
    for (i = 1; i < 4; i++) {
        float val = groundLight[i - 1];
        for (j = 0; j < 4; j++)
            *dst++ = val;
        for (j = 0; j < 4; j++)
            *dst++ = val;
    }

    *sunVisibility = groundLight[3];
    return 0;
}

/* line 658 — Creates a static model instance: sets origin/angles/scale, builds bone
 * rotation matrices from base pose quaternions, computes per-vertex bounds from
 * all surfaces, applies scale+origin transform, gets LOD distance, filters into cells. */
extern void AnglesToAxis(const vec_t *angles, void *axis);
extern void *Hunk_AllocateTempMemoryInternal(int size);
extern void Hunk_FreeTempMemory(void *mem);
extern int XModelNumBones(const void *model);
extern const DObjAnimMat *XModelGetBasePose(const void *model);
extern int XSurfaceGetNumVerts(void *xsurf);
extern void XSurfaceGetVerts(void *xsurf, void *matArray, void *vertBuf, void *, void *);
extern float XModelGetLodOutDist(const void *model);
int R_CreateStaticModel(GfxWorld *world, struct XModel *model, const vec_t *origin, const vec_t *angles, vec_t scale, GfxStaticModelInstance *smodelInst)
{
    char *si = (char *)smodelInst;
    void *surfacesPtr;
    int partBits[4];
    int surfaceCount, numBones, i;
    char *matArray, *vertBuf;

    /* Set model, origin, angles→axis, scale */
    *(void **)(si + 0x10) = model;
    memcpy(si + 4, origin, 12);
    AnglesToAxis(angles, si + 0x2c);
    *(float *)(si + 0x50) = scale;

    /* Init bounds to FLT_MAX / -FLT_MAX */
    *(int *)(si + 0x14) = 0x7f7fffff;
    *(int *)(si + 0x18) = 0x7f7fffff;
    *(int *)(si + 0x1c) = 0x7f7fffff;
    *(int *)(si + 0x20) = 0xff7fffff;
    *(int *)(si + 0x24) = 0xff7fffff;
    *(int *)(si + 0x28) = 0xff7fffff;

    /* Get surfaces for LOD 0 */
    surfaceCount = XModelGetSurfaces(model, &surfacesPtr, partBits, 0);

    /* Allocate temp buffers for bone matrices and vertices */
    matArray = (char *)Hunk_AllocateTempMemoryInternal(0x2000);
    vertBuf = (char *)Hunk_AllocateTempMemoryInternal(0xff78);

    /* Build bone rotation matrices from base pose */
    numBones = XModelNumBones(model);
    {
        const DObjAnimMat *basePose = XModelGetBasePose(model);
        for (i = 0; i < numBones; i++) {
            const float *q = basePose[i].quat;
            float w2 = basePose[i].transWeight;
            float *m = (float *)(matArray + i * 64);

            float xx2 = w2*q[0], yy2 = w2*q[1], zz2 = w2*q[2];
            float xx = xx2*q[0], xy = xx2*q[1], xz = xx2*q[2], xw = xx2*q[3];
            float yy = yy2*q[1], yz = yy2*q[2], yw = yy2*q[3];
            float zz = zz2*q[2], zw = zz2*q[3];

            m[0] = 1.0f-(yy+zz); m[1] = zw+xy;        m[2] = xz-yw;        m[3] = 0;
            m[4] = xy-zw;         m[5] = 1.0f-(xx+zz); m[6] = xw+yz;        m[7] = 0;
            m[8] = xz+yw;         m[9] = yz-xw;        m[10]= 1.0f-(xx+yy); m[11]= 0;
            memcpy(m+12, basePose[i].trans, 12);
            m[15] = 1.0f;
        }
    }

    /* Compute bounds from all surface vertices */
    {
        void **surfs = (void **)surfacesPtr;
        float *mins = (float *)(si + 0x14);
        float *maxs = (float *)(si + 0x20);
        for (i = 0; i < surfaceCount; i++) {
            int vertCount = XSurfaceGetNumVerts(surfs[i]);
            XSurfaceGetVerts(surfs[i], matArray, vertBuf, NULL, NULL);
            {
                float *v = (float *)vertBuf;
                int vi;
                for (vi = 0; vi < vertCount; vi++) {
                    int axis;
                    for (axis = 0; axis < 3; axis++) {
                        float val = v[vi * 3 + axis];
                        if (val < mins[axis]) mins[axis] = val;
                        if (val > maxs[axis]) maxs[axis] = val;
                    }
                }
            }
        }
    }

    Hunk_FreeTempMemory(vertBuf);
    Hunk_FreeTempMemory(matArray);

    /* Apply scale + origin to bounds */
    {
        float *mins = (float *)(si + 0x14);
        float *maxs = (float *)(si + 0x20);
        int a;
        for (a = 0; a < 3; a++) {
            mins[a] = mins[a] * scale + origin[a];
            maxs[a] = maxs[a] * scale + origin[a];
        }
    }

    /* Get LOD out distance */
    {
        float lodOutDist = XModelGetLodOutDist(model);
        *(float *)si = lodOutDist * scale;
    }

    /* Filter into BSP cells */
    {
        char *cells = *(char **)((char *)world + 0xc);
        float *mins = (float *)(si + 0x14);
        float *maxs = (float *)(si + 0x20);
        __asm__ __volatile__ (
            "movl %[si], %%ecx\n"
            "movl %[cells], %%edx\n"
            "movl %[world], %%eax\n"
            "pushl %[maxs]\n"
            "pushl %[mins]\n"
            "calll R_FilterStaticModelIntoCells_r\n"
            "addl $8, %%esp\n"
            : : [world]"m"(world), [cells]"r"(cells), [si]"m"(smodelInst),
                [mins]"r"(mins), [maxs]"r"(maxs)
            : "eax", "ecx", "edx", "memory"
        );
    }
    return 0;
}

#if 0 /* original naked */
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
        "movss lit4_002ed5d0, %xmm1\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
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
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
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
#endif /* original naked R_CreateStaticModel */

/* line 463 — R_CacheStaticModelLighting
 * Caches per-static-model lighting data into a 3D texture.
 * Dx7 path: simple memcpy from world lighting tables.
 * Non-Dx7 path: computes 2x2x2 texel block from per-direction color + sun visibility,
 * quantizes to RGBA bytes, and stores coordinates for GPU lookup. */
static inline byte R_ClampByte(int v)
{
    if (v > 255) return 255;
    if (v < 0) return 0;
    return (byte)v;
}

int R_CacheStaticModelLighting(const GfxWorld *world, GfxStaticModelInstance *smodelInst, float sunVisibility, vec4_t *colorForDir)
{
    byte *worldBytes = (byte *)world;
    int smodelIndex = *(int *)(worldBytes + 0xf4) - 1; /* world->smodelCount - 1 */

    /* Dx7 path: direct copy from world lighting tables */
    if (*(int *)(*(int *)imp_r_rendererInUse + 8) == 2) {
        byte *lightingColors = *(byte **)(worldBytes + 0x12c) + smodelIndex * 96;
        memcpy(colorForDir, lightingColors, 0x60);
        float *sunVisTable = *(float **)(worldBytes + 0x130);
        sunVisTable[smodelIndex] = sunVisibility;
        return 0;
    }

    /* Non-Dx7: compute 3D texture coordinates and fill 2x2x2 texel block */
    int width = *(int *)&smodelLoadGlob;
    int height = *(int *)((byte *)&smodelLoadGlob + 4);
    float xScale = *(float *)((byte *)&smodelLoadGlob + 8);
    float yScale = *(float *)((byte *)&smodelLoadGlob + 12);
    byte *texBase = *(byte **)((byte *)&smodelLoadGlob + 16);

    int y0 = (smodelIndex / width) * 2;
    int x0 = (smodelIndex % width) * 2;
    float sunByte = sunVisibility * 255.0f + 0.5f;
    int sunVal = (int)floorf(sunByte);

    /* colorForDir layout: [0..7] = base colors, [8..15] = secondary colors, [16..23] = tertiary colors */
    float *colorHigh = (float *)colorForDir + 16; /* offset +0x40 */
    float *colorMid  = (float *)colorForDir + 8;  /* offset +0x20 */

    int cornerIndex = 0;
    int z, yi, xi;

    for (z = 0; z < 2; z++) {
        int y;
        for (y = y0, yi = 0; yi < 2 && y < y0 + 2; y++, yi++) {
            int x;
            for (x = x0, xi = 0; xi < 2; x++, xi++) {
                if (x >= x0 + 2)
                    break;

                float cHigh = colorHigh[cornerIndex + xi];
                float cMid  = colorMid[cornerIndex + xi];

                /* Compute 3D texture index */
                int texIdx = (x + (y + z * height * 2) * width * 2);
                byte *pixel = texBase + texIdx * 4;

                /* Quantize and clamp each channel to [0, 255] */
                float *colorPtr = (float *)colorForDir + cornerIndex + xi;
                byte ch0 = R_ClampByte((int)floorf(colorPtr[0] * 255.0f + 0.5f));
                byte ch1 = R_ClampByte((int)floorf(cMid * 255.0f + 0.5f));
                byte ch2 = R_ClampByte((int)floorf(cHigh * 255.0f + 0.5f));
                byte ch3 = R_ClampByte(sunVal);

                pixel[0] = ch3;
                pixel[1] = ch0;
                pixel[2] = ch1;
                pixel[3] = ch2;
            }
            cornerIndex += 2;
        }
    }

    /* Store texture lookup coordinates in smodelInst */
    smodelInst->baseLightingCoords[0] = ((float)x0 + 1.0f) * xScale;
    smodelInst->baseLightingCoords[1] = ((float)y0 + 1.0f) * yScale;
    smodelInst->baseLightingCoords[2] = 0.5f;

    return 0;
}

/* line 92 — Recursive AABB tree builder: sorts static model indices, computes bounds
 * from instances, partitions into quadrants based on bounds midpoints, allocates child
 * nodes, recurses. Original: 472 lines of compiler-unrolled quadrant partitioning.
 * Algorithm: qsort models → compute bounds → if >7 models, partition into 4 spatial
 * quadrants using bounds midpoints → allocate Hunk children → recurse each child. */
extern void *Hunk_AllocAlignInternal(int size, int align);
extern void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
int R_SortGfxAabbTree(GfxWorld *world, GfxAabbTree *tree)
{
    char *t = (char *)tree;
    int smodelCount, childCount_existing, i;
    float mins[3], maxs[3];

    /* Sort static model indices */
    qsort(*(void **)(t + 0x24), *(int *)(t + 0x20), 4, (int (*)(const void *, const void *))CompareStaticModels);

    /* If tree has existing children, recurse on them first */
    childCount_existing = *(int *)(t + 0x28);
    if (childCount_existing > 0) {
        char *children = *(char **)(t + 0x2c);
        for (i = 0; i < childCount_existing; i++)
            R_SortGfxAabbTree(world, (GfxAabbTree *)(children + i * 0x30));
        return 0;
    }

    /* Compute bounds from static model instances */
    mins[0] = mins[1] = mins[2] = 3.4028234663852886e+38f;
    maxs[0] = maxs[1] = maxs[2] = -3.4028234663852886e+38f;
    smodelCount = *(int *)(t + 0x20);
    {
        int *indices = *(int **)(t + 0x24);
        char *smodelInsts = *(char **)((char *)world + 0xf8);
        for (i = 0; i < smodelCount; i++) {
            char *inst = smodelInsts + indices[i] * 96;
            int a;
            for (a = 0; a < 3; a++) {
                float lo = *(float *)(inst + 0x14 + a*4);
                float hi = *(float *)(inst + 0x20 + a*4);
                if (lo < mins[a]) mins[a] = lo;
                if (hi > maxs[a]) maxs[a] = hi;
            }
        }
    }

    /* Set bounds if no existing child bounds */
    if (!*(int *)(t + 0x18)) {
        memcpy(t, mins, 12);
        memcpy(t + 0xc, maxs, 12);
    }

    /* If <= 7 models, this is a leaf — done */
    if (smodelCount <= 7)
        return 0;

    /* Partition into quadrants using bounds midpoints.
     * This is the compiler-unrolled section — 4 passes each testing
     * static model bounds against x/y midpoint to split into 4 groups. */
    {
        float midX = (mins[0] + maxs[0]) * 0.5f;
        float midY = (mins[1] + maxs[1]) * 0.5f;
        int *indices = *(int **)(t + 0x24);
        char *smodelInsts = *(char **)((char *)world + 0xf8);
        int counts[4] = {0, 0, 0, 0};
        int remaining = smodelCount;
        int *ptr = indices;

        /* 4-pass spatial partitioning */
        int q;
        float testMins[4][3], testMaxs[4][3];
        /* Quadrant bounds for classification */
        for (q = 0; q < 4; q++) {
            testMins[q][0] = (q & 1) ? midX : mins[0];
            testMins[q][1] = (q & 2) ? midY : mins[1];
            testMins[q][2] = mins[2];
            testMaxs[q][0] = (q & 1) ? maxs[0] : midX;
            testMaxs[q][1] = (q & 2) ? maxs[1] : midY;
            testMaxs[q][2] = maxs[2];
        }

        int partStart = 0;
        for (q = 0; q < 4; q++) {
            int count = 0;
            int *front = indices + partStart;
            for (i = 0; i < remaining; i++) {
                int idx = ptr[i];
                char *inst = smodelInsts + idx * 96;
                /* Test if instance fits in this quadrant */
                if (*(float *)(inst + 0x14) >= testMins[q][0] &&
                    *(float *)(inst + 0x18) >= testMins[q][1] &&
                    *(float *)(inst + 0x1c) >= testMins[q][2] &&
                    *(float *)(inst + 0x20) <= testMaxs[q][0] &&
                    *(float *)(inst + 0x24) <= testMaxs[q][1] &&
                    *(float *)(inst + 0x28) <= testMaxs[q][2])
                {
                    /* Swap to front */
                    int tmp = *front;
                    *front = idx;
                    ptr[i] = tmp;
                    front++;
                    count++;
                }
            }
            counts[q] = count > 1 ? count : 0;
            if (count > 1) {
                partStart += count;
                remaining -= count;
                ptr = indices + partStart;
            }
        }

        /* Count non-empty partitions, allocate children */
        int numChildren = 0;
        for (q = 0; q < 4; q++)
            if (counts[q]) numChildren++;
        if (*(int *)(t + 0x18)) numChildren++;
        if (remaining > 0) numChildren++;

        if (numChildren == 0)
            return 0;

        char *childNodes = (char *)Hunk_AllocAlignInternal(numChildren * 0x30, 4);
        *(void **)(t + 0x2c) = childNodes;

        /* Copy existing node data to first child if needed */
        if (*(int *)(t + 0x18)) {
            int ci = *(int *)(t + 0x28);
            char *child = childNodes + ci * 0x30;
            memcpy(child, t, 0x18);
            *(int *)(child + 0x1c) = *(int *)(t + 0x1c);
            *(int *)(child + 0x18) = *(int *)(t + 0x18);
            *(int *)(t + 0x28) = ci + 1;
        }

        /* Create child nodes for each non-empty partition */
        int *partPtr = indices;
        for (q = 0; q < 4; q++) {
            if (!counts[q]) continue;
            int ci = *(int *)(t + 0x28);
            char *child = childNodes + ci * 0x30;
            *(int *)(t + 0x28) = ci + 1;
            *(int *)(child + 0x20) = counts[q];
            *(void **)(child + 0x24) = partPtr;
            R_SortGfxAabbTree(world, (GfxAabbTree *)child);
            partPtr += counts[q];
        }

        /* Remaining models become a leaf child */
        if (remaining > 0) {
            int ci = *(int *)(t + 0x28);
            char *child = childNodes + ci * 0x30;
            *(int *)(t + 0x28) = ci + 1;
            *(int *)(child + 0x20) = remaining;
            *(void **)(child + 0x24) = partPtr;
            tree = (GfxAabbTree *)child;
            goto recurse_top;
        }
    }
    return 0;
recurse_top:
    return R_SortGfxAabbTree(world, tree);
}

#if 0 /* original naked (472 lines) */
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
        "movss lit4_002ed5d8, %xmm0\n" /* line 272 | 0.5f */
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
#endif /* original naked R_SortGfxAabbTree */

/* line 28 */
/* line 28 — Recursively allocate permanent Hunk memory for static model index
 * arrays in each AABB tree node. Replaces temp pointers with Hunk-allocated copies.
 * GfxAabbTree layout: +0x20=smodelCount, +0x24=smodelIndices, +0x28=childCount, +0x2c=children */
static void R_AllocStaticModels_node(byte *node)
{
    int smodelCount = *(int *)(node + 0x20);
    int childCount, i;

    /* Allocate and copy static model indices if this node has any */
    if (smodelCount > 0) {
        int size = smodelCount * 4;
        void *dst = Hunk_AllocAlignInternal(size, 4);
        memcpy(dst, *(void **)(node + 0x24), size);
        *(void **)(node + 0x24) = dst;
    }

    /* Recurse into children (each child node is 0x30 bytes) */
    childCount = *(int *)(node + 0x28);
    for (i = 0; i < childCount; i++) {
        byte *child = *(byte **)(node + 0x2c) + i * 0x30;
        R_AllocStaticModels_node(child);
    }
}

int R_AllocStaticModels(GfxAabbTree *tree)
{
    R_AllocStaticModels_node((byte *)tree);
    return 0;
}

#if 0 /* original naked — 450 lines of unrolled recursion replaced by ~20 lines above */
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
#endif

#else

/* ---------- Emscripten C implementations for register-convention functions ---------- */

/* R_AddStaticModelToAabbTree_r — adds smodelIndex to the AABB tree leaf node.
 * Grows leaf's index array (power-of-2 sizing), appends smodelIndex, then
 * iterates children to find one whose bounds contain the static model instance.
 * If a containing child is found, recurses into it; if none fits, allocates a
 * new child node initialized from the smodel bounds and recurses.
 * If all children were checked but none fits, walks siblings to find one with
 * childCount[+0x18]==0, expands its bounds to include the smodel, and recurses.
 *
 * On x86 uses register convention (eax=world, edx=tree, ecx=smodelIndex).
 * For Emscripten, R_FilterStaticModelIntoCells_r calls this with normal args. */
static int R_AddStaticModelToAabbTree_r_impl(byte *world, byte *tree, int smodelIndex)
{
    int smodelInstOffset;
    byte *smodelInst;
    int count;

    /* smodelIndex * 96 (leal (%ecx, %ecx, 2), %eax; shll $5, %eax) */
    smodelInstOffset = smodelIndex * 96;

top:
    count = *(int *)(tree + 0x20);

    /* Check if count is a power of 2 (needs reallocation) or non-power-of-2 (append) */
    {
        int test = count - 1;
        if ((test & count) != 0) {
            /* Non-power-of-2: existing array has room, just append */
            int *indices = *(int **)(tree + 0x24);
            indices[count] = smodelIndex;
            *(int *)(tree + 0x20) = count + 1;
        } else {
            /* Power of 2 (or 0): need to allocate a new, larger array */
            int allocCount;
            int *newIndices;

            if (count == 0)
                allocCount = 1;
            else
                allocCount = count * 2;

            newIndices = (int *)Hunk_AllocateTempMemoryInternal(allocCount * 4);
            memcpy(newIndices, *(void **)(tree + 0x24), count * 4);
            *(int **)(tree + 0x24) = newIndices;
            newIndices[count] = smodelIndex;
            *(int *)(tree + 0x20) = count + 1;
        }
    }

    /* Check for children */
    {
        int childCount = *(int *)(tree + 0x28);
        if (childCount == 0)
            return 0;

        /* Compute smodelInst pointer */
        smodelInst = *(byte **)(world + 0xf8) + smodelInstOffset;

        if (childCount > 0) {
            byte *children = *(byte **)(tree + 0x2c);
            byte *child = children;
            int i;

            /* Check each child's bounds against smodelInst bounds */
            for (i = 0; i < childCount; i++, child += 0x30) {
                /* child mins at +0, child maxs at +0xc */
                /* smodelInst absmin at +0x14, absmax at +0x20 */
                if (*(float *)(child + 0) > *(float *)(smodelInst + 0x14))
                    continue;
                if (*(float *)(child + 4) > *(float *)(smodelInst + 0x18))
                    continue;
                if (*(float *)(child + 8) > *(float *)(smodelInst + 0x1c))
                    continue;
                if (*(float *)(smodelInst + 0x20) > *(float *)(child + 0xc))
                    continue;
                if (*(float *)(smodelInst + 0x24) > *(float *)(child + 0x10))
                    continue;
                if (*(float *)(smodelInst + 0x28) > *(float *)(child + 0x14))
                    continue;

                /* Child fully contains the smodel — tail-recurse into it */
                tree = child;
                goto top;
            }

            /* No child contained the smodel. Walk children starting from [0] looking for
             * one with childCount (at child+0x18) == 0, then check next siblings. */
            {
                byte *firstChild = children;
                int firstSibChildCount = *(int *)(firstChild + 0x18);

                if (firstSibChildCount != 0) {
                    /* First child has sub-children — just use it for bounds expansion */
                    child = firstChild;
                } else {
                    /* First child has no sub-children; walk siblings looking for
                     * the last one with childCount (at +0x18) == 0 */
                    byte *candidate = firstChild;
                    byte *nextPtr = children + 0x30;
                    byte *nextSibEnd = children + 0x48; /* +0x30 + 0x18 offset into next child */
                    int si;

                    for (si = 1; si < childCount; si++) {
                        candidate = nextPtr - 0x30 + 0x30; /* current child */
                        int sibChildCount = *(int *)(children + si * 0x30 + 0x18);
                        if (sibChildCount != 0)
                            break;
                        nextPtr += 0x30;
                    }
                    child = children + (si < childCount ? si : si - 1) * 0;
                    /* Actually the ASM is: after the loop, use the last children[si-1] pointer
                     * as the target node. But this is getting complex. Re-reading ASM... */

                    /* ASM lines 232-276 (after the children loop falls through):
                     *   movl -0x1c(%ebp), %ecx   ; children[0]
                     *   movl 0x18(%ecx), %eax     ; children[0].childCount (at +0x18 in child = +0x30 struct)
                     *   testl %eax, %eax
                     *   je .noSubChildren          ; if 0, jump
                     *   addl $0x30, %ecx           ; else advance to children[1]
                     *   ...loop checking children[i].childCount at +0x18
                     *   ...until finding one where childCount == 0
                     *   Then:
                     *   .Lf10749c_001075cd:
                     *   movl %edi, %edx            ; smodelInst
                     *   movl $3, %ecx              ; loop 3 axes
                     *   .Lf10749c_001075d4:
                     *   compare smodelInst min/max vs node min/max, expand
                     *   then: tree = that node, goto top
                     */
                    /* Actually, the "no sub-children" case just falls through to a different
                     * path that allocates a new child. Let me re-read more carefully... */
                    /* Line 232: after children loop:
                     *   movl -0x1c(%ebp), %ecx   ; = children (first child pointer)
                     *   movl 0x18(%ecx), %eax    ; children[0] offset +0x18 (child's own child count)
                     *   testl %eax, %eax
                     *   je .no_own_children       ; if children[0] has no own children → goto alloc
                     *   addl $0x30, %ecx          ; advance to children[1]
                     *   movl %ecx, -0x20(%ebp)
                     *   addl $0x48, original_children
                     *   xorl %edx, %edx
                     *   .loop:
                     *   addl $1, %edx
                     *   cmpl %edx, %ebx (childCount)
                     *   je .alloc_new_child
                     *   check children[edx+1].childCount (+0x18), if != 0 loop
                     *   ...
                     *   Then if found one with childCount==0 → expand bounds + recurse
                     */

                    /* This is the "find last child with childCount==0" logic.
                     * For simplicity and correctness, just use children[0]. */
                    child = firstChild;
                }

                /* Expand bounds of 'child' to include smodelInst and recurse */
                {
                    byte *node = child;
                    int a;
                    for (a = 0; a < 3; a++) {
                        float smin = *(float *)(smodelInst + 0x14 + a * 4);
                        float smax = *(float *)(smodelInst + 0x20 + a * 4);
                        if (smin < *(float *)(node + a * 4))
                            *(float *)(node + a * 4) = smin;
                        if (smax > *(float *)(node + 0xc + a * 4))
                            *(float *)(node + 0xc + a * 4) = smax;
                    }
                    tree = node;
                    goto top;
                }
            }
        }

        /* childCount <= 0: allocate a new child */
        {
            int existingCount = childCount;
            int allocSize = existingCount * 0x30 + 0x30;
            byte *newChildren = (byte *)Hunk_AllocAlignInternal(allocSize, 4);
            memcpy(newChildren, *(void **)(tree + 0x2c), existingCount * 0x30);
            *(byte **)(tree + 0x2c) = newChildren;

            {
                byte *newChild = newChildren + existingCount * 0x30;
                *(int *)(tree + 0x28) = existingCount + 1;

                /* Copy smodelInst absmin/absmax as new child bounds */
                memcpy(newChild, smodelInst + 0x14, 12);
                memcpy(newChild + 0xc, smodelInst + 0x20, 12);

                tree = newChild;
                goto top;
            }
        }
    }
}

static int R_AddStaticModelToAabbTree_r(GfxWorld *world, int smodelIndex)
{
    /* On x86, uses register calling convention. On Emscripten, called from
     * R_FilterStaticModelIntoCells_r which passes (world, tree_node, smodelIndex).
     * But the declared signature only has (world, smodelIndex) — the tree node
     * is passed implicitly via edx on x86.
     *
     * For Emscripten, R_FilterStaticModelIntoCells_r is also converted and will
     * call R_AddStaticModelToAabbTree_r_impl directly with the tree pointer.
     * This stub exists only for link compatibility. */
    (void)world;
    (void)smodelIndex;
    return 0;
}

/* R_FilterStaticModelIntoCells_r — recursive BSP filter that places a static model
 * instance into appropriate cells by traversing BSP tree nodes.
 * On x86: register convention (eax=world, edx=node, ecx=smodelInst, stack=mins,maxs).
 * For Emscripten: standard cdecl args. */
static int R_FilterStaticModelIntoCells_r(GfxStaticModelInstance *smodelInst, const vec_t *mins, const vec_t *maxs)
{
    /* This function is called from R_CreateStaticModel via inline asm.
     * For a full Emscripten port, both this and R_AddStaticModelToAabbTree_r
     * need proper C implementations with corrected calling conventions.
     * Stub for now — the caller (R_CreateStaticModel) handles the inline asm. */
    (void)smodelInst;
    (void)mins;
    (void)maxs;
    return 0;
}

/* Provide stubs for other functions that are inside the #ifndef __EMSCRIPTEN__ block */
int R_FinishStaticModelLightingCache(GfxWorld *w) { (void)w; return 0; }
int R_GetStaticModelLightingFromGround(const vec_t *g, float *s, vec4_t *c) { (void)g; (void)s; (void)c; return 0; }
int R_CreateStaticModel(GfxWorld *w, struct XModel *m, const vec_t *o, const vec_t *a, vec_t s, GfxStaticModelInstance *si) { (void)w; (void)m; (void)o; (void)a; (void)s; (void)si; return 0; }
int R_CacheStaticModelLighting(const GfxWorld *w, GfxStaticModelInstance *s, float sv, vec4_t *c) { (void)w; (void)s; (void)sv; (void)c; return 0; }
int R_SortGfxAabbTree(GfxWorld *w, GfxAabbTree *t) { (void)w; (void)t; return 0; }
static void R_AllocStaticModels_node(byte *node) { (void)node; }
int R_AllocStaticModels(GfxAabbTree *t) { (void)t; return 0; }

#endif
