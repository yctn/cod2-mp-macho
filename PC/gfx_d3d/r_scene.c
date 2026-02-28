/* ASM dump from: r_scene.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_scene.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_surface.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

extern struct GfxScene scene; /* 0x0 */
static int warnCount; /* 0x7f1dcc */
static int warnCount_007f1dd0; /* 0x7f1dd0 */
static int warnCount_007f1dd0; /* 0x7f1dd0 */
static int warnCount_007f1dd0; /* 0x7f1dd0 */
static GfxViewParms lockPvsViewParms; /* 0x7f1c80 */
static surfaceType_t s_entitySurface; /* 0x311088 */
static byte s_XModelSurfaceSize[8]; /* 0x311080 */

static int R_CompareDumpSceneEntities(const void *e0, const void *e1);
void R_UpdateGfxEntityBounds(GfxEntity *ent);
void R_SkinGfxEntity(GfxEntity *ent);
void R_DecomposeSort(unsigned int sortValue, int *entIndex, const Material * *material, int *lmapIndex);
void R_ClearScene(void);
void R_AddLightToScene(const vec_t *org, float radius, float r, float g, float b);
void R_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts);
void qsortDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount);
void R_AddXModelSurfaces(int entIndex);
void R_AddBModelSurfaces(GfxSceneEntity *sceneEnt, int entIndex);
void R_AddPolyToScene(MaterialHandle materialHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts);
void R_AddDrawSurfForSurface(GfxSurface *surf, int entIndex);
static void R_SetViewParmsForScene(void);
void R_SetLodOrigin(const refdef_t *refdef);
static void R_AddClearCommandsForFrameBuffer(void);
void R_RenderScene(const refdef_t *refdef);
int R_AddStaticModelToScene(int smodelIndex);
GfxEntity * R_AddRefEntityToScene(const GfxEntity *refEnt, GfxModel sceneModel, const struct centity_s *cent);

/* line 121 */
static __attribute__((naked))
int R_CompareDumpSceneEntities(const void *e0, const void *e1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 128 | e0 */
        "movl (%eax), %ecx\n"
        "movl 0xc(%ebp), %eax\n" /* line 129 | e1 */
        "movl (%eax), %ebx\n"
        "movl 0x195eef4, %eax\n" /* line 130 */
        "movl (%eax), %edx\n"
        "leal (, %ecx, 8), %eax\n"
        "subl %ecx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 0xa0010(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal (, %ebx, 8), %eax\n" /* line 131 */
        "subl %ebx, %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "leal 0xa0010(%edx, %eax, 4), %esi\n"
        "movl -0x1c(%ebp), %eax\n" /* line 133 */
        "movl (%eax), %edx\n"
        "movl %edx, %eax\n" /* line 134 */
        "subl (%esi), %eax\n"
        "jne .Lfc54f0_000c5585\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 137 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %ecx\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 138 */
        "leal (%ebx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %edi\n"
        "cmpl $2, %edx\n" /* line 139 */
        "jle .Lfc54f0_000c558d\n"
        "cmpl $3, %edx\n"
        "je .Lfc54f0_000c55a0\n"
        ".Lfc54f0_000c5562:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 149 */
        "movl 0x54(%eax), %edx\n"
        "subl 0x54(%esi), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "negl %eax\n"
        /* } scope */
        ".Lfc54f0_000c5585:\n"
        "addl $0x2c, %esp\n" /* line 151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc54f0_000c558d:\n"
        "cmpl $1, %edx\n" /* line 139 */
        "jl .Lfc54f0_000c55ab\n"
        "movl 4(%ecx), %eax\n" /* line 145 */
        "subl 4(%edi), %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 151 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc54f0_000c55a0:\n"
        "movl 4(%ecx), %eax\n" /* line 147 */
        "subl 4(%edi), %eax\n"
        "sarl $5, %eax\n"
        "jmp .Lfc54f0_000c5585\n"
        ".Lfc54f0_000c55ab:\n"
        "testl %edx, %edx\n" /* line 139 */
        "jne .Lfc54f0_000c5562\n"
        "movl $0, 4(%esp)\n" /* line 142 */
        "movl 4(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, %ebx\n"
        "movl $0, 4(%esp)\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "subl %eax, %ebx\n"
        "movl %ebx, %eax\n"
        "jmp .Lfc54f0_000c5585\n"
    );
}

/* line 354 */
__attribute__((naked))
void R_UpdateGfxEntityBounds(GfxEntity *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 354 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* ent */
        "movl %ecx, 4(%esp)\n" /* line 365 */
        "subl 0x1155010, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $7, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%ecx, %edx, 8), %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "leal 0x11555c4(, %edx, 4), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_UpdateXModelBounds\n"
        "leave\n" /* line 366 */
        "retl\n"
    );
}

/* line 369 */
__attribute__((naked))
void R_SkinGfxEntity(GfxEntity *ent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 369 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* ent */
        /* { scope 1 */
        "movl %esi, %ecx\n" /* line 378 | ent */
        "subl 0x1155010, %ecx\n"
        "sarl $2, %ecx\n"
        "movl %ecx, %edx\n"
        "shll $7, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%ecx, %edx, 8), %edx\n"
        "movl %edx, %eax\n"
        "shll $0xe, %eax\n"
        "subl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %ecx, %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 2), %ebx\n" /* sceneEnt */
        "leal (%eax, %ebx, 4), %ebx\n" /* sceneEnt */
        "leal 0x11555c4(, %ebx, 4), %ebx\n" /* sceneEnt */
        "movl %esi, 4(%esp)\n" /* line 380 | ent */
        "movl %ebx, (%esp)\n" /* sceneEnt */
        "calll R_UpdateXModelBounds\n"
        "movl %esi, 4(%esp)\n" /* line 381 | ent */
        "movl %ebx, (%esp)\n" /* sceneEnt */
        "calll R_SkinSceneDObj\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 382 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 608 */
void R_DecomposeSort(unsigned int sortValue, int *entIndex, const Material * *material, int *lmapIndex)
{
    int ent, matIndex;
    int *base = *(int **)0x195eebc;

    if ((int)sortValue >= 0) {
        ent = (sortValue >> 4) & 0xfff;
        if (ent >= 0x800)
            ent = 0x7fe;
        *entIndex = ent;
        matIndex = (sortValue >> 21) & 0x3ff;
        *material = (const Material *)*(void **)((byte *)base + 8 + matIndex * 4);
        *lmapIndex = (sortValue >> 16) & 0x1f;
    } else {
        ent = (sortValue >> 19) & 0xfff;
        if (ent >= 0x800)
            ent = 0x7fe;
        *entIndex = ent;
        matIndex = (sortValue >> 9) & 0x3ff;
        *material = (const Material *)*(void **)((byte *)base + 8 + matIndex * 4);
        *lmapIndex = (sortValue >> 4) & 0x1f;
    }
}

/* line 1374 */
__attribute__((naked))
void R_ClearScene(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1374 */
        "movl %esp, %ebp\n"
        "addl $1, scene\n" /* line 1384 */
        "movl $0, 0x1155014\n" /* line 1394 */
        "movl $0, 0x11555b8\n" /* line 1396 */
        "movl 0x195eef4, %eax\n" /* line 1397 */
        "movl (%eax), %ecx\n"
        "movl 4(%ecx), %eax\n"
        "leal 8(%ecx, %eax, 8), %eax\n"
        "movl %eax, 0x11555bc\n"
        "movl $0, 0x11555c0\n" /* line 1399 */
        "movl $0, 0x115500c\n" /* line 1401 */
        "movl 0xa000c(%ecx), %edx\n" /* line 1402 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0xa0010(%ecx, %eax, 4), %eax\n"
        "movl %eax, 0x1155010\n"
        "movl $0, 0x116f55c\n" /* line 1404 */
        "popl %ebp\n" /* line 1407 */
        "jmp R_ClearDpvsScene\n" /* line 1406 */
    );
}

/* line 492 */
__attribute__((naked))
void R_AddLightToScene(const vec_t *org, float radius, float r, float g, float b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 492 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* org */
        "movss 0xc(%ebp), %xmm0\n" /* radius */
        /* { scope 1 */
        "movl 0x195eec8, %eax\n" /* line 497 */
        "cmpb $0, (%eax)\n"
        "je .Lfc579a_000c583b\n"
        "movl 0x195eebc, %ebx\n" /* line 501 */
        "movl 0x109c(%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfc579a_000c583b\n"
        "ucomiss 0x2ed5e8, %xmm0\n" /* line 507 | 0.0f */
        "jp .Lfc579a_000c57d0\n"
        "jbe .Lfc579a_000c583b\n"
        ".Lfc579a_000c57d0:\n"
        "movl 0x1155014, %edx\n" /* line 509 */
        "movl 0x195eeac, %eax\n"
        "movl (%eax), %eax\n"
        "cmpl 8(%eax), %edx\n"
        "jge .Lfc579a_000c583b\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 512 */
        "leal (%edx, %eax, 2), %eax\n"
        "leal 0x1155010(, %eax, 4), %eax\n"
        "leal 8(%eax), %ecx\n"
        "addl $1, %edx\n" /* line 513 */
        "movl %edx, 0x1155014\n"
        "movl 0x1028(%ebx), %edx\n" /* line 515 */
        "movl %edx, 8(%eax)\n"
        "leal 0xc(%eax), %ebx\n" /* line 516 | to */
        /* { scope 2 */
        "movl (%esi), %edx\n" /* line 199 */
        "movl %edx, 0xc(%eax)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "movss %xmm0, 0x10(%ecx)\n" /* line 517 */
        "movss 0x10(%ebp), %xmm0\n" /* line 519 | r */
        "movss %xmm0, 0x14(%ecx)\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 520 | g */
        "movss %xmm0, 0x18(%ecx)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 521 | b */
        "movss %xmm0, 0x1c(%ecx)\n"
        /* } scope */
        ".Lfc579a_000c583b:\n"
        "popl %ebx\n" /* line 522 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 424 */
__attribute__((naked))
void R_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 424 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* vertCount */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 429 | vertCount */
        "jle .Lfc5840_000c58a2\n"
        "movl 0xc(%ebp), %edx\n" /* verts */
        "xorl %ecx, %ecx\n"
        ".Lfc5840_000c5850:\n"
        "leal 0xc(%edx), %eax\n" /* line 431 | v */
        /* { scope 2 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 0x2c(%edx), %eax\n" /* line 432 | v */
        /* { scope 2 */
        "movl $0, 0x2c(%edx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 0x38(%edx), %eax\n" /* line 433 | v */
        /* { scope 2 */
        "movl $0x3f800000, 0x38(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "addl $1, %ecx\n" /* line 429 */
        "addl $0x44, %edx\n"
        "cmpl %ecx, %ebx\n" /* vertCount */
        "jne .Lfc5840_000c5850\n"
        /* } scope */
        ".Lfc5840_000c58a2:\n"
        "popl %ebx\n" /* line 444 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 731 */
__attribute__((naked))
void qsortDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 731 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "movl 8(%ebp), %edx\n" /* drawSurfs */
        "movl 0xc(%ebp), %eax\n" /* drawSurfCount */
        /* { scope 1 */
        "cmpl $1, %eax\n" /* line 746 */
        "jle .Lfc58a6_000c5b2b\n"
        "leal -8(%edx, %eax, 8), %eax\n" /* line 751 */
        "movl %eax, -0x120(%ebp)\n" /* hiEnd */
        "movl %edx, %edi\n" /* loEnd */
        "movl $0, -0x114(%ebp)\n" /* stackPos */
        ".Lfc58a6_000c58d7:\n"
        "subl %edi, %eax\n" /* line 758 | loEnd */
        "sarl $3, %eax\n"
        "shrl $3, %eax\n"
        "addl $1, %eax\n"
        "cmpl $8, %eax\n" /* line 761 */
        "jg .Lfc58a6_000c5992\n"
        ".Lfc58a6_000c58eb:\n"
        "cmpl -0x120(%ebp), %edi\n" /* line 717 | hiEnd */
        "jae .Lfc58a6_000c5955\n"
        "leal 8(%edi), %ecx\n"
        "movl %ecx, -0x10c(%ebp)\n"
        "movl %ecx, %eax\n"
        "jmp .Lfc58a6_000c5935\n"
        ".Lfc58a6_000c5900:\n"
        "movl %edi, %esi\n" /* line 720 */
        ".Lfc58a6_000c5902:\n"
        "movl (%esi), %ecx\n" /* line 706 */
        "movl 4(%esi), %ebx\n"
        "movl -0x120(%ebp), %edx\n" /* line 707 | hiEnd */
        "movl (%edx), %eax\n"
        "movl 4(%edx), %edx\n"
        "movl %eax, (%esi)\n"
        "movl %edx, 4(%esi)\n"
        "movl -0x120(%ebp), %eax\n" /* line 708 | hiEnd */
        "movl %ecx, (%eax)\n"
        "movl %ebx, 4(%eax)\n"
        "subl $8, %eax\n" /* line 726 */
        "movl %eax, -0x120(%ebp)\n" /* hiEnd */
        "cmpl %eax, %edi\n" /* line 717 */
        "jae .Lfc58a6_000c5955\n"
        "movl -0x10c(%ebp), %eax\n"
        ".Lfc58a6_000c5935:\n"
        "cmpl %eax, -0x120(%ebp)\n" /* line 720 | hiEnd */
        "jb .Lfc58a6_000c5900\n"
        "movl %eax, %edx\n"
        "movl %edi, %esi\n"
        ".Lfc58a6_000c5941:\n"
        "movl (%edx), %eax\n" /* line 722 */
        "cmpl (%esi), %eax\n"
        "cmoval %edx, %esi\n"
        "addl $8, %edx\n" /* line 720 */
        "cmpl %edx, -0x120(%ebp)\n" /* hiEnd */
        "jae .Lfc58a6_000c5941\n"
        "jmp .Lfc58a6_000c5902\n"
        ".Lfc58a6_000c5955:\n"
        "subl $1, -0x114(%ebp)\n" /* line 846 | stackPos */
        "js .Lfc58a6_000c5b2b\n"
        "movl -0x114(%ebp), %eax\n" /* line 848 | stackPos */
        "movl -0x90(%ebp, %eax, 4), %edi\n" /* loEnd */
        "movl -0x108(%ebp, %eax, 4), %edx\n" /* line 849 */
        "movl %edx, -0x120(%ebp)\n" /* hiEnd */
        "movl %edx, %eax\n"
        "subl %edi, %eax\n" /* line 758 | loEnd */
        "sarl $3, %eax\n"
        "shrl $3, %eax\n"
        "addl $1, %eax\n"
        "cmpl $8, %eax\n" /* line 761 */
        "jle .Lfc58a6_000c58eb\n"
        ".Lfc58a6_000c5992:\n"
        "sarl $1, %eax\n" /* line 776 */
        "leal (%edi, %eax, 8), %esi\n" /* loEnd, mid */
        "movl (%esi), %ecx\n" /* line 706 */
        "movl 4(%esi), %ebx\n"
        "movl (%edi), %eax\n" /* line 707 */
        "movl 4(%edi), %edx\n"
        "movl %eax, (%esi)\n"
        "movl %edx, 4(%esi)\n"
        "movl %ecx, (%edi)\n" /* line 708 */
        "movl %ebx, 4(%edi)\n"
        "movl -0x120(%ebp), %edx\n" /* line 786 | hiEnd */
        "addl $8, %edx\n"
        "movl %edx, -0x118(%ebp)\n" /* hiWalk */
        "leal 8(%edi), %ecx\n" /* loEnd */
        "movl %ecx, -0x110(%ebp)\n"
        "movl %edi, -0x11c(%ebp)\n" /* loEnd, loWalk */
        "addl $8, -0x11c(%ebp)\n" /* line 792 | loWalk */
        "movl -0x11c(%ebp), %eax\n" /* line 790 | loWalk */
        "cmpl %eax, -0x120(%ebp)\n" /* hiEnd */
        "jae .Lfc58a6_000c5a5d\n"
        ".Lfc58a6_000c59de:\n"
        "movl -0x118(%ebp), %esi\n" /* hiWalk, mid */
        "subl $8, %esi\n" /* mid */
        "movl %esi, %edx\n" /* mid */
        "jmp .Lfc58a6_000c59ee\n"
        ".Lfc58a6_000c59eb:\n"
        "subl $8, %esi\n" /* mid */
        ".Lfc58a6_000c59ee:\n"
        "movl %esi, -0x118(%ebp)\n" /* line 797 | mid, hiWalk */
        "cmpl %esi, %edi\n" /* line 795 | mid, loEnd */
        "jae .Lfc58a6_000c5a01\n"
        "movl (%edx), %eax\n"
        "subl $8, %edx\n"
        "cmpl (%edi), %eax\n" /* loEnd */
        "jae .Lfc58a6_000c59eb\n"
        ".Lfc58a6_000c5a01:\n"
        "cmpl %esi, -0x11c(%ebp)\n" /* line 800 | mid, loWalk */
        "ja .Lfc58a6_000c5a6e\n"
        "movl -0x110(%ebp), %edx\n" /* line 706 */
        "movl (%edx), %eax\n"
        "movl 4(%edx), %edx\n"
        "movl %eax, -0x140(%ebp)\n"
        "movl %edx, -0x13c(%ebp)\n"
        "movl (%esi), %eax\n" /* line 707 */
        "movl 4(%esi), %edx\n"
        "movl -0x11c(%ebp), %ecx\n" /* loWalk */
        "movl %eax, (%ecx)\n"
        "movl %edx, 4(%ecx)\n"
        "movl -0x140(%ebp), %eax\n" /* line 708 */
        "movl -0x13c(%ebp), %edx\n"
        "movl %eax, (%esi)\n"
        "movl %edx, 4(%esi)\n"
        ".Lfc58a6_000c5a41:\n"
        "addl $8, -0x110(%ebp)\n" /* line 786 */
        "addl $8, -0x11c(%ebp)\n" /* line 792 | loWalk */
        "movl -0x11c(%ebp), %eax\n" /* line 790 | loWalk */
        "cmpl %eax, -0x120(%ebp)\n" /* hiEnd */
        "jb .Lfc58a6_000c59de\n"
        ".Lfc58a6_000c5a5d:\n"
        "movl -0x110(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "cmpl (%edi), %eax\n" /* loEnd */
        "jbe .Lfc58a6_000c5a41\n"
        "jmp .Lfc58a6_000c59de\n"
        ".Lfc58a6_000c5a6e:\n"
        "movl (%edi), %ecx\n" /* line 706 */
        "movl 4(%edi), %ebx\n"
        "movl (%esi), %eax\n" /* line 707 */
        "movl 4(%esi), %edx\n"
        "movl %eax, (%edi)\n"
        "movl %edx, 4(%edi)\n"
        "movl %ecx, (%esi)\n" /* line 708 */
        "movl %ebx, 4(%esi)\n"
        "movl %esi, %edx\n" /* line 811 | mid */
        "subl %edi, %edx\n" /* loEnd */
        "subl $8, %edx\n"
        "sarl $3, %edx\n"
        "movl -0x120(%ebp), %eax\n" /* hiEnd */
        "subl -0x11c(%ebp), %eax\n" /* loWalk */
        "sarl $3, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lfc58a6_000c5ae2\n"
        "leal -8(%esi), %eax\n" /* line 813 | mid */
        "cmpl %eax, %edi\n" /* loEnd */
        "jae .Lfc58a6_000c5ac3\n"
        "movl -0x114(%ebp), %edx\n" /* line 815 | stackPos */
        "movl %edi, -0x90(%ebp, %edx, 4)\n" /* loEnd */
        "movl %eax, -0x108(%ebp, %edx, 4)\n" /* line 816 */
        "addl $1, %edx\n" /* line 817 */
        "movl %edx, -0x114(%ebp)\n" /* stackPos */
        ".Lfc58a6_000c5ac3:\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 820 | loWalk */
        "cmpl %ecx, -0x120(%ebp)\n" /* hiEnd */
        "jbe .Lfc58a6_000c5955\n"
        "movl %ecx, %edi\n" /* loEnd */
        "movl -0x120(%ebp), %eax\n" /* hiEnd */
        "jmp .Lfc58a6_000c58d7\n"
        ".Lfc58a6_000c5ae2:\n"
        "movl -0x11c(%ebp), %eax\n" /* line 828 | loWalk */
        "cmpl %eax, -0x120(%ebp)\n" /* hiEnd */
        "jbe .Lfc58a6_000c5b13\n"
        "movl -0x114(%ebp), %edx\n" /* line 830 | stackPos */
        "movl %eax, -0x90(%ebp, %edx, 4)\n"
        "movl -0x120(%ebp), %ecx\n" /* line 831 | hiEnd */
        "movl %ecx, -0x108(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 832 */
        "movl %edx, -0x114(%ebp)\n" /* stackPos */
        ".Lfc58a6_000c5b13:\n"
        "subl $8, %esi\n" /* line 835 | mid */
        "movl %esi, -0x120(%ebp)\n" /* mid, hiEnd */
        "cmpl %esi, %edi\n" /* mid, loEnd */
        "jae .Lfc58a6_000c5955\n"
        "movl %esi, %eax\n" /* mid */
        "jmp .Lfc58a6_000c58d7\n"
        /* } scope */
        ".Lfc58a6_000c5b2b:\n"
        "addl $0x13c, %esp\n" /* line 852 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 905 */
__attribute__((naked))
void R_AddXModelSurfaces(int entIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 905 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1: drawSurf */
        "movl 8(%ebp), %edx\n" /* line 915 | entIndex */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %edi\n" /* sceneEnt */
        "movl %edx, %eax\n" /* line 918 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x1155010, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* ent */
        "movl 0x30(%edi), %esi\n" /* line 923 | sceneEnt, modelSurf */
        "movl 0x10(%edi), %edx\n" /* line 925 | sceneEnt */
        "testl %edx, %edx\n"
        "jle .Lfc5b38_000c5c47\n"
        "movl $0, -0x2c(%ebp)\n" /* surfIndex */
        "movl $0, -0x28(%ebp)\n" /* totalTriCount */
        "movl $0, -0x24(%ebp)\n" /* totalVertCount */
        "jmp .Lfc5b38_000c5bb8\n"
        ".Lfc5b38_000c5b8c:\n"
        "movl 0x195eed4, %eax\n" /* line 939 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc5b38_000c5c8d\n"
        ".Lfc5b38_000c5b9d:\n"
        "movl (%esi), %eax\n" /* line 942 | modelSurf */
        "movzbl s_XModelSurfaceSize(%eax), %eax\n"
        "addl %eax, %esi\n" /* modelSurf */
        "movl 0x10(%edi), %edx\n" /* sceneEnt */
        ".Lfc5b38_000c5bab:\n"
        "addl $1, -0x2c(%ebp)\n" /* line 925 | surfIndex */
        "cmpl %edx, -0x2c(%ebp)\n" /* surfIndex */
        "jge .Lfc5b38_000c5c55\n"
        ".Lfc5b38_000c5bb8:\n"
        "movl 0x2c(%edi), %eax\n" /* line 927 | sceneEnt */
        "movl -0x2c(%ebp), %ecx\n" /* surfIndex */
        "movl (%eax, %ecx, 4), %ebx\n" /* material */
        "testl %ebx, %ebx\n" /* line 928 | material */
        "je .Lfc5b38_000c5bab\n"
        "movl $0x7ff, %ecx\n" /* line 932 */
        "cmpl $5, (%esi)\n" /* modelSurf */
        "cmovnel 8(%ebp), %ecx\n" /* entIndex */
        /* { scope 2 */
        "movl 0x195eef4, %eax\n" /* line 655 */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n"
        "cmpl $0xffff, %eax\n"
        "jg .Lfc5b38_000c5c22\n"
        "leal 8(%edx, %eax, 8), %edx\n" /* line 660 */
        "movl %edx, -0x1c(%ebp)\n" /* drawSurf */
        "movl (%esi), %edx\n" /* line 663 */
        "cmpl $2, %edx\n" /* line 667 */
        "je .Lfc5b38_000c5ca0\n"
        ".Lfc5b38_000c5bf4:\n"
        "shll $4, %ecx\n" /* line 676 */
        "addl %ecx, %edx\n"
        "movzwl 0xa(%ebx), %eax\n" /* line 677 */
        "shll $0x15, %eax\n"
        "leal 0x1f0000(%edx, %eax), %eax\n" /* line 678 */
        ".Lfc5b38_000c5c07:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 680 | drawSurf */
        "movl %eax, (%edx)\n"
        "movl %esi, 4(%edx)\n" /* line 681 */
        "addl $1, 0x11555b8\n" /* line 685 */
        "movl 0x195eef4, %ecx\n" /* line 686 */
        "movl (%ecx), %eax\n"
        "addl $1, 4(%eax)\n"
        /* } scope */
        ".Lfc5b38_000c5c22:\n"
        "movl 0x195eeb0, %edx\n" /* line 937 */
        "movl (%edx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc5b38_000c5b8c\n"
        "movl 4(%esi), %eax\n" /* line 938 | modelSurf */
        "movl %eax, (%esp)\n"
        "calll XSurfaceGetNumTris\n"
        "addl %eax, -0x28(%ebp)\n" /* totalTriCount */
        "jmp .Lfc5b38_000c5b9d\n"
        ".Lfc5b38_000c5c47:\n"
        "movl $0, -0x28(%ebp)\n" /* line 925 | totalTriCount */
        "movl $0, -0x24(%ebp)\n" /* totalVertCount */
        ".Lfc5b38_000c5c55:\n"
        "movl 0x195eeb0, %ecx\n" /* line 945 */
        "movl (%ecx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc5b38_000c5d1c\n"
        "movl 0x195eed4, %eax\n" /* line 947 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc5b38_000c5cc7\n"
        "movl 0x195eedc, %eax\n" /* line 949 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc5b38_000c5d25\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 951 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawSurf */
        ".Lfc5b38_000c5c8d:\n"
        "movl 4(%esi), %eax\n" /* line 940 | modelSurf */
        "movl %eax, (%esp)\n"
        "calll XSurfaceGetNumVerts\n"
        "addl %eax, -0x24(%ebp)\n" /* totalVertCount */
        "jmp .Lfc5b38_000c5b9d\n"
        /* { scope 2 */
        ".Lfc5b38_000c5ca0:\n"
        "movl 0x195ed68, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc5b38_000c5bf4\n"
        "shll $0x13, %ecx\n" /* line 670 */
        "movzwl 0xa(%ebx), %eax\n" /* line 671 */
        "shll $9, %eax\n"
        "leal -0x7ffffe0e(%ecx, %eax), %eax\n" /* line 672 */
        "jmp .Lfc5b38_000c5c07\n"
        /* } scope */
        ".Lfc5b38_000c5cc7:\n"
        "movl -0x24(%ebp), %edx\n" /* line 948 | totalVertCount */
        "movl %edx, 4(%esp)\n"
        ".Lfc5b38_000c5cce:\n"
        "movl $0x21785c, (%esp)\n" /* line 950 */
        "calll va\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195eee8, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* ent */
        "addl $0x3c, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x195eec8, %eax\n"
        "movl 0x3190(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195eef4, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_AddScaledDebugString\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 951 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: drawSurf */
        ".Lfc5b38_000c5d1c:\n"
        "movl -0x28(%ebp), %eax\n" /* line 946 | totalTriCount */
        "movl %eax, 4(%esp)\n"
        "jmp .Lfc5b38_000c5cce\n"
        ".Lfc5b38_000c5d25:\n"
        "movl %edx, 4(%esp)\n" /* line 950 */
        "jmp .Lfc5b38_000c5cce\n"
    );
}

/* line 883 */
__attribute__((naked))
void R_AddBModelSurfaces(GfxSceneEntity *sceneEnt, int entIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 883 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* sceneEnt */
        /* { scope 1 */
        "movl $5, 0xc(%edx)\n" /* line 892 */
        "movl 0x195eefc, %eax\n" /* line 894 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc5d2c_000c5e2f\n"
        "movl 4(%edx), %edx\n" /* line 897 */
        "movl %edx, -0x1c(%ebp)\n" /* bmodel */
        "movl 0x1c(%edx), %eax\n" /* line 900 */
        "movl 0x18(%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lfc5d2c_000c5e2f\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (, %eax, 4), %ebx\n"
        "movl $0, -0x18(%ebp)\n" /* count */
        "movl 0xc(%ebp), %eax\n" /* entIndex */
        "shll $0x13, %eax\n"
        "subl $0x7ffffffe, %eax\n"
        "movl %eax, -0x10(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* entIndex */
        "shll $4, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "jmp .Lfc5d2c_000c5dcd\n"
        /* { scope 2 */
        /* { scope 3: drawSurf */
        /* { scope 4 */
        ".Lfc5d2c_000c5d8e:\n"
        "addl -0x20(%ebp), %edx\n" /* line 676 */
        "movzwl 0xa(%esi), %eax\n" /* line 677 */
        "shll $0x15, %eax\n"
        "addl %eax, %edx\n"
        "shll $0x10, %ecx\n" /* line 678 */
        "leal (%edx, %ecx), %eax\n"
        ".Lfc5d2c_000c5da0:\n"
        "movl -0x14(%ebp), %edx\n" /* line 680 | drawSurf */
        "movl %eax, (%edx)\n"
        "movl %edi, 4(%edx)\n" /* line 681 */
        "addl $1, 0x11555b8\n" /* line 685 */
        "movl 0x195eef4, %edx\n" /* line 686 */
        "movl (%edx), %eax\n"
        "addl $1, 4(%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfc5d2c_000c5dbb:\n"
        "addl $1, -0x18(%ebp)\n" /* line 900 | count */
        "addl $0xc, %ebx\n"
        "movl -0x18(%ebp), %edx\n" /* count */
        "movl -0x1c(%ebp), %eax\n" /* bmodel */
        "cmpl %edx, 0x18(%eax)\n"
        "jle .Lfc5d2c_000c5e2f\n"
        ".Lfc5d2c_000c5dcd:\n"
        "movl 0x195eebc, %edx\n" /* line 901 */
        "movl 0x109c(%edx), %eax\n" /* surf */
        "movl 0x14(%eax), %edx\n"
        "leal (%ebx, %edx), %eax\n" /* surf */
        /* { scope 2 */
        "movzwl 4(%eax), %ecx\n" /* line 698 | lmapIndex */
        "movl (%eax), %esi\n" /* material */
        "movl 8(%eax), %edi\n" /* surface */
        /* { scope 3: drawSurf */
        /* { scope 4 */
        "movl 0x195eef4, %eax\n" /* line 655 */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n"
        "cmpl $0xffff, %eax\n"
        "jg .Lfc5d2c_000c5dbb\n"
        "leal 8(%edx, %eax, 8), %edx\n" /* line 660 */
        "movl %edx, -0x14(%ebp)\n" /* drawSurf */
        "movl (%edi), %edx\n" /* line 663 */
        "cmpl $2, %edx\n" /* line 667 */
        "jne .Lfc5d2c_000c5d8e\n"
        "movl 0x195ed68, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc5d2c_000c5d8e\n"
        "movzwl 0xa(%esi), %eax\n" /* line 671 */
        "shll $9, %eax\n"
        "addl -0x10(%ebp), %eax\n"
        "shll $4, %ecx\n" /* line 672 */
        "addl %ecx, %eax\n"
        "jmp .Lfc5d2c_000c5da0\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfc5d2c_000c5e2f:\n"
        "addl $0x18, %esp\n" /* line 902 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 447 */
__attribute__((naked))
void R_AddPolyToScene(MaterialHandle materialHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 447 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* materialHandle */
        "movl 0xc(%ebp), %ebx\n" /* lmapIndex */
        "movl 0x10(%ebp), %esi\n" /* vertCount */
        "movw %bx, -0x22(%ebp)\n" /* lmapIndex */
        "movl %esi, %ecx\n" /* vertCount */
        /* { scope 1 */
        "movl 0x195eec8, %eax\n" /* line 458 */
        "cmpb $0, (%eax)\n"
        "je .Lfc5e38_000c5f85\n"
        "testl %edi, %edi\n" /* line 465 | materialHandle */
        "je .Lfc5e38_000c5f95\n"
        ".Lfc5e38_000c5e66:\n"
        "movl 0x195eef4, %eax\n" /* line 468 */
        "movl (%eax), %edx\n"
        "movzwl %cx, %ecx\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl %ecx, %eax\n"
        "addl 0x18fc74(%edx), %eax\n"
        "cmpl $0x2000, %eax\n"
        "jg .Lfc5e38_000c5f85\n"
        "movl 0x187c70(%edx), %eax\n"
        "cmpl $0x7ff, %eax\n"
        "jg .Lfc5e38_000c5f85\n"
        "shll $4, %eax\n" /* line 471 */
        "leal 0x187c70(%eax, %edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "addl $4, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* poly */
        "movl -0x28(%ebp), %edx\n" /* line 472 */
        "movl $1, 4(%edx)\n"
        "movl %edi, 4(%eax)\n" /* line 473 | materialHandle */
        "movw %bx, 8(%eax)\n" /* line 474 */
        "movw %si, 0xa(%eax)\n" /* line 475 */
        "movl 0x195eef4, %eax\n" /* line 476 */
        "movl (%eax), %ecx\n"
        "movl 0x18fc74(%ecx), %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "leal 0x18fc70(%edx, %eax, 4), %eax\n"
        "leal 8(%ecx, %eax), %ecx\n"
        "movl -0x1c(%ebp), %edx\n" /* poly */
        "movl %ecx, 0xc(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 479 */
        "shll $6, %eax\n"
        "movl -0x20(%ebp), %edx\n"
        "leal (%eax, %edx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* verts */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x11555c0, %eax\n" /* line 482 */
        "andl $0x800007ff, %eax\n"
        "js .Lfc5e38_000c5fa5\n"
        ".Lfc5e38_000c5f11:\n"
        "leal 0x800(%eax), %ecx\n"
        "movzwl -0x22(%ebp), %ebx\n" /* line 484 | lmapIndex */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x195eef4, %eax\n" /* line 655 */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n"
        "cmpl $0xffff, %eax\n"
        "jg .Lfc5e38_000c5f8d\n"
        "leal 8(%edx, %eax, 8), %esi\n" /* line 660 | drawSurf */
        "movl -0x28(%ebp), %eax\n" /* line 663 */
        "movl 4(%eax), %edx\n"
        "cmpl $2, %edx\n" /* line 667 */
        "je .Lfc5e38_000c5fb5\n"
        ".Lfc5e38_000c5f3b:\n"
        "shll $4, %ecx\n" /* line 676 */
        "addl %ecx, %edx\n"
        "movzwl 0xa(%edi), %eax\n" /* line 677 | materialHandle */
        "shll $0x15, %eax\n"
        "addl %eax, %edx\n"
        "shll $0x10, %ebx\n" /* line 678 | lmapIndex */
        "leal (%edx, %ebx), %eax\n"
        ".Lfc5e38_000c5f4f:\n"
        "movl %eax, (%esi)\n" /* line 680 | drawSurf */
        "movl -0x1c(%ebp), %edx\n" /* line 681 | poly */
        "movl %edx, 4(%esi)\n" /* drawSurf */
        "addl $1, 0x11555b8\n" /* line 685 */
        "movl 0x195eef4, %edx\n" /* line 686 */
        "movl (%edx), %eax\n"
        "addl $1, 4(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lfc5e38_000c5f6a:\n"
        "movl (%edx), %eax\n" /* line 486 */
        "addl $1, 0x187c70(%eax)\n"
        "movl (%edx), %eax\n" /* line 487 */
        "movl -0x20(%ebp), %edx\n"
        "addl %edx, 0x18fc74(%eax)\n"
        "addl $1, 0x11555c0\n" /* line 488 */
        /* } scope */
        ".Lfc5e38_000c5f85:\n"
        "addl $0x2c, %esp\n" /* line 489 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc5e38_000c5f8d:\n"
        "movl 0x195eef4, %edx\n"
        "jmp .Lfc5e38_000c5f6a\n"
        /* { scope 1 */
        ".Lfc5e38_000c5f95:\n"
        "movl 0x195eebc, %eax\n" /* line 466 */
        "movl 0x102c(%eax), %edi\n" /* materialHandle */
        "jmp .Lfc5e38_000c5e66\n"
        ".Lfc5e38_000c5fa5:\n"
        "subl $1, %eax\n" /* line 482 */
        "orl $0xfffff800, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lfc5e38_000c5f11\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc5e38_000c5fb5:\n"
        "movl 0x195ed68, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc5e38_000c5f3b\n"
        "shll $0x13, %ecx\n" /* line 670 */
        "movzwl 0xa(%edi), %eax\n" /* line 671 | materialHandle */
        "shll $9, %eax\n"
        "leal -0x7ffffffe(%ecx, %eax), %eax\n"
        "shll $4, %ebx\n" /* line 672 | lmapIndex */
        "addl %ebx, %eax\n" /* lmapIndex */
        "jmp .Lfc5e38_000c5f4f\n"
    );
}

/* line 696 */
__attribute__((naked))
void R_AddDrawSurfForSurface(GfxSurface *surf, int entIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 696 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $4, %esp\n"
        "movl 8(%ebp), %eax\n" /* surf */
        "movl 0xc(%ebp), %ecx\n" /* entIndex */
        "movzwl 4(%eax), %ebx\n" /* line 698 | lmapIndex */
        "movl (%eax), %edi\n" /* material */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x10(%ebp)\n" /* surface */
        /* { scope 1 */
        /* { scope 2 */
        "movl 0x195eef4, %eax\n" /* line 655 */
        "movl (%eax), %edx\n"
        "movl 4(%edx), %eax\n"
        "cmpl $0xffff, %eax\n"
        "jg .Lfc5fe4_000c604d\n"
        "leal 8(%edx, %eax, 8), %esi\n" /* line 660 | drawSurf */
        "movl -0x10(%ebp), %eax\n" /* line 663 | surface */
        "movl (%eax), %edx\n"
        "cmpl $2, %edx\n" /* line 667 */
        "je .Lfc5fe4_000c6055\n"
        ".Lfc5fe4_000c601e:\n"
        "shll $4, %ecx\n" /* line 676 */
        "addl %ecx, %edx\n"
        "movzwl 0xa(%edi), %eax\n" /* line 677 */
        "shll $0x15, %eax\n"
        "addl %eax, %edx\n"
        "shll $0x10, %ebx\n" /* line 678 */
        "leal (%edx, %ebx), %eax\n"
        ".Lfc5fe4_000c6032:\n"
        "movl %eax, (%esi)\n" /* line 680 | drawSurf */
        "movl -0x10(%ebp), %edx\n" /* line 681 | surface */
        "movl %edx, 4(%esi)\n" /* drawSurf */
        "addl $1, 0x11555b8\n" /* line 685 */
        "movl 0x195eef4, %edx\n" /* line 686 */
        "movl (%edx), %eax\n"
        "addl $1, 4(%eax)\n"
        /* } scope */
        /* } scope */
        ".Lfc5fe4_000c604d:\n"
        "addl $4, %esp\n" /* line 699 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc5fe4_000c6055:\n"
        "movl 0x195ed68, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc5fe4_000c601e\n"
        "shll $0x13, %ecx\n" /* line 670 */
        "movzwl 0xa(%edi), %eax\n" /* line 671 */
        "shll $9, %eax\n"
        "leal -0x7ffffffe(%ecx, %eax), %eax\n"
        "shll $4, %ebx\n" /* line 672 */
        "addl %ebx, %eax\n"
        "jmp .Lfc5fe4_000c6032\n"
    );
}

/* line 1410 */
static __attribute__((naked))
void R_SetViewParmsForScene(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1410 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %esi\n" /* refdef */
        "movl %edx, %edi\n" /* viewParms */
        /* { scope 1 */
        "movl $0x14c, 8(%esp)\n" /* line 1415 */
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl (%esi), %eax\n" /* line 1416 | refdef */
        "movl %eax, 0x30(%edi)\n" /* viewParms */
        "movl 4(%esi), %eax\n" /* line 1417 | refdef */
        "movl %eax, 0x34(%edi)\n" /* viewParms */
        "movl 8(%esi), %eax\n" /* line 1418 | refdef */
        "movl %eax, 0x38(%edi)\n" /* viewParms */
        "movl 0xc(%esi), %eax\n" /* line 1419 | refdef */
        "movl %eax, 0x3c(%edi)\n" /* viewParms */
        "movl $0, 0x40(%edi)\n" /* line 1420 | viewParms */
        "movl $0x3f800000, 0x44(%edi)\n" /* line 1421 | viewParms */
        "leal 0x18(%esi), %edx\n" /* line 1423 | refdef, from */
        /* { scope 2 */
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, (%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%edi)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%edi)\n"
        /* } scope */
        "leal 0xc(%edi), %ebx\n" /* line 1424 | viewParms, to */
        "leal 0x24(%esi), %edx\n" /* refdef, from */
        /* { scope 2 */
        "movl 0x24(%esi), %eax\n" /* line 199 */
        "movl %eax, 0xc(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "leal 0x18(%edi), %ecx\n" /* line 1425 | viewParms, to */
        "leal 0x30(%esi), %edx\n" /* refdef, from */
        /* { scope 2 */
        "movl 0x30(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x18(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x24(%edi), %ecx\n" /* line 1426 | viewParms, to */
        "leal 0x3c(%esi), %edx\n" /* refdef, from */
        /* { scope 2 */
        "movl 0x3c(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x24(%edi)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x48(%edi), %eax\n" /* line 1427 | viewParms */
        "movl %eax, -0x20(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* to */
        "movl %edi, 4(%esp)\n" /* viewParms */
        "movl %eax, (%esp)\n"
        "calll MatrixForViewer\n"
        "movss 0x4c(%esi), %xmm2\n" /* line 1429 | refdef */
        "pxor %xmm0, %xmm0\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lfc607a_000c6177\n"
        "movl 0x195eecc, %eax\n" /* line 589 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm2\n"
        "movss 0x2ed738, %xmm1\n" /* line 45 | 0.009999999776482582f */
        "movaps %xmm1, %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm2, %xmm3\n"
        "cmpltss %xmm4, %xmm0\n"
        "andps %xmm0, %xmm3\n"
        "andnps %xmm1, %xmm0\n"
        "orps %xmm3, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        ".Lfc607a_000c6177:\n"
        "leal 0x88(%edi), %eax\n" /* line 595 */
        "movl %eax, -0x1c(%ebp)\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll InfinitePerspectiveMatrix\n"
        "movl 0x195eef8, %eax\n" /* line 597 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x148(%edi)\n"
        "leal 0xc8(%edi), %ebx\n" /* line 603 */
        "movl %ebx, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MatrixMultiply44\n"
        "leal 0x108(%edi), %eax\n" /* line 604 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixInverse44\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1433 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1447 */
__attribute__((naked))
void R_SetLodOrigin(const refdef_t *refdef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1447 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* refdef */
        "movl 0x195ef0c, %ebx\n" /* line 1453 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lfc61e6_000c6302\n"
        ".Lfc61e6_000c6203:\n"
        "cmpb $0, 8(%eax)\n" /* line 1459 */
        "je .Lfc61e6_000c6267\n"
        "movl 0x195eec8, %ebx\n" /* line 199 */
        "movl lockPvsViewParms, %eax\n"
        "movl %eax, 0x317c(%ebx)\n"
        "movl 0x7f1c84, %eax\n" /* line 200 */
        "movl %eax, 0x3180(%ebx)\n"
        "movl 0x7f1c88, %eax\n" /* line 201 */
        "movl %eax, 0x3184(%ebx)\n"
        ".Lfc61e6_000c6230:\n"
        "movl 0x195ef00, %eax\n" /* line 1464 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x3188(%ebx)\n"
        "movl 0x195ef08, %eax\n" /* line 1465 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 0x318c(%ebx)\n"
        "movss 0x10(%esi), %xmm0\n" /* line 1466 | refdef */
        "ucomiss 0x2ed7d8, %xmm0\n" /* 80.0f */
        "jp .Lfc61e6_000c628d\n"
        "jne .Lfc61e6_000c628d\n"
        "addl $0x20, %esp\n" /* line 1473 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc61e6_000c6267:\n"
        "leal 0x18(%esi), %edx\n" /* line 1462 | refdef, from */
        /* { scope 1 */
        "movl 0x195eec8, %ebx\n" /* line 199 */
        "movl 0x18(%esi), %eax\n"
        "movl %eax, 0x317c(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x3180(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x3184(%ebx)\n"
        "jmp .Lfc61e6_000c6230\n"
        /* } scope */
        /* { scope 1 */
        ".Lfc61e6_000c628d:\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 1468 | 0.5f, invFovScale */
        "cvtss2sd %xmm0, %xmm0\n" /* invFovScale */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295, invFovScale */
        "movsd %xmm0, (%esp)\n" /* invFovScale */
        "calll tan\n"
        "fstpl -0x10(%ebp)\n"
        "movl $0x4ae74487, (%esp)\n"
        "movl $0x3fe65718, 4(%esp)\n"
        "calll tan\n"
        "fstpl -0x18(%ebp)\n"
        "movsd -0x10(%ebp), %xmm0\n" /* invFovScale */
        "divsd -0x18(%ebp), %xmm0\n" /* invFovScale */
        "movsd %xmm0, -0x10(%ebp)\n" /* invFovScale */
        "cvtsd2ss %xmm0, %xmm0\n" /* invFovScale */
        "movaps %xmm0, %xmm1\n" /* line 1470 */
        "mulss 0x3188(%ebx), %xmm1\n"
        "movss %xmm1, 0x3188(%ebx)\n"
        "mulss 0x318c(%ebx), %xmm0\n" /* line 1471 */
        "movss %xmm0, 0x318c(%ebx)\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1473 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc61e6_000c6302:\n"
        "movl %eax, (%esp)\n" /* line 1455 */
        "movl 0x195eee0, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $lockPvsViewParms, %edx\n" /* line 1456 */
        "movl %esi, %eax\n" /* refdef */
        "calll R_SetViewParmsForScene\n"
        "movl (%ebx), %eax\n"
        "jmp .Lfc61e6_000c6203\n"
    );
}

/* line 1030 */
static __attribute__((naked))
void R_AddClearCommandsForFrameBuffer(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1030 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl %eax, %edx\n" /* dynamicShadowType */
        /* { scope 1 */
        "movl 0x195eed0, %eax\n" /* line 1038 */
        "movl 0x2c28(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc6324_000c6344\n"
        "subl $1, %edx\n" /* dynamicShadowType */
        "je .Lfc6324_000c6431\n"
        ".Lfc6324_000c6344:\n"
        "movl $7, %ecx\n"
        ".Lfc6324_000c6349:\n"
        "movl 0x195eec8, %edx\n" /* line 1009 */
        "cmpb $0, 0x14c8(%edx)\n"
        "je .Lfc6324_000c63c4\n"
        "movzbl 0x14ba(%edx), %eax\n" /* line 741 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n" /* clearColor */
        "movzbl 0x14b9(%edx), %eax\n" /* line 742 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n"
        "movzbl 0x14b8(%edx), %eax\n" /* line 743 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        "movl $0x3f800000, -0xc(%ebp)\n" /* line 1012 */
        "movl $0, 0xc(%esp)\n" /* line 1045 */
        "movl $0x3f800000, 8(%esp)\n"
        "leal -0x18(%ebp), %eax\n" /* clearColor */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdClearScreen\n"
        /* } scope */
        "leave\n" /* line 1046 */
        "retl\n"
        /* { scope 1 */
        ".Lfc6324_000c63c4:\n"
        "movl 0x195eec4, %eax\n" /* line 1025 */
        "movl (%eax), %eax\n"
        "leal 8(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movzbl 8(%eax), %eax\n" /* line 705 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0x2ed5cc, %xmm1\n" /* 0.003921568859368563f */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x18(%ebp)\n" /* clearColor */
        "movzbl 1(%edx), %eax\n" /* line 706 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x14(%ebp)\n"
        "movzbl 2(%edx), %eax\n" /* line 707 */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x10(%ebp)\n"
        /* } scope */
        "movl $0x3f800000, -0xc(%ebp)\n" /* line 1026 */
        "movl $0, 0xc(%esp)\n" /* line 1045 */
        "movl $0x3f800000, 8(%esp)\n"
        "leal -0x18(%ebp), %eax\n" /* clearColor */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdClearScreen\n"
        /* } scope */
        "leave\n" /* line 1046 */
        "retl\n"
        /* { scope 1 */
        ".Lfc6324_000c6431:\n"
        "movl $1, %ecx\n" /* line 1038 */
        "jmp .Lfc6324_000c6349\n"
    );
}

/* line 1476 */
__attribute__((naked))
void R_RenderScene(const refdef_t *refdef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1476 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* refdef */
        /* { scope 1: pointLightPartitions */
        "movl 0x195eec8, %ebx\n" /* line 1491 | drawSurfs */
        "cmpb $0, (%ebx)\n" /* drawSurfs */
        "je .Lfc643c_000c6a10\n"
        "movl 0x195eed8, %eax\n" /* line 1501 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc643c_000c6a10\n"
        "movl 0x195eebc, %eax\n" /* line 1507 */
        "movl 0x109c(%eax), %edi\n" /* drawSurfCount */
        "testl %edi, %edi\n" /* drawSurfCount */
        "je .Lfc643c_000c713b\n"
        ".Lfc643c_000c647e:\n"
        "movl 0x48(%esi), %eax\n" /* line 1510 | refdef */
        "movl %eax, 0x1155004\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 1511 */
        "mulss 0x2ed658, %xmm0\n" /* 0.0010000000474974513f */
        "movss %xmm0, 0x1155008\n"
        "leal 0x18(%esi), %edx\n" /* line 1513 | refdef, from */
        /* { scope 2: pointLightCount, viewIndex */
        "movl 0x18(%esi), %eax\n" /* line 199 */
        "movl %eax, 4(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 8(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0xc(%ebx)\n"
        /* } scope */
        "leal 0x24(%esi), %edx\n" /* line 1514 | refdef, from */
        /* { scope 2: pointLightCount, viewIndex */
        "movl 0x24(%esi), %eax\n" /* line 199 */
        "movl %eax, 0x10(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 0x14(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 0x18(%ebx)\n"
        /* } scope */
        "calll R_AllocViewParms\n" /* line 1516 */
        "movl %eax, -0x2c1c(%ebp)\n"
        "movl %eax, %edx\n" /* line 1517 */
        "movl %esi, %eax\n" /* refdef */
        "calll R_SetViewParmsForScene\n"
        "movss 0x50(%esi), %xmm0\n" /* line 1442 | light */
        "movss %xmm0, -0x2c30(%ebp)\n"
        "movl 0x195eeec, %edx\n" /* line 1443 */
        "movl 8(%esi), %eax\n" /* light */
        "cmpl (%edx), %eax\n"
        "je .Lfc643c_000c6f9c\n"
        ".Lfc643c_000c64f6:\n"
        "movb $0, -0x2c55(%ebp)\n"
        ".Lfc643c_000c64fd:\n"
        "movl 0x195ef0c, %eax\n" /* line 1526 */
        "movl (%eax), %eax\n"
        "movl $lockPvsViewParms, -0x2c5c(%ebp)\n" /* viewParmsDraw */
        "cmpb $0, 8(%eax)\n"
        "movl $lockPvsViewParms, %eax\n"
        "cmovel -0x2c1c(%ebp), %eax\n"
        "movl %eax, -0x2c5c(%ebp)\n" /* viewParmsDraw */
        /* { scope 2: pointLightCount, viewIndex */
        "movl 0x1155004, %ebx\n" /* line 536 */
        "movl 0x195eec8, %ecx\n"
        "movl 0x14f4(%ecx), %edx\n"
        "cmpl %edx, %ebx\n"
        "jl .Lfc643c_000c6a31\n"
        "movl 0x14ec(%ecx), %eax\n" /* line 538 */
        "movl %eax, 0x14ac(%ecx)\n"
        "movl 0x14f0(%ecx), %eax\n"
        "movl %eax, 0x14b0(%ecx)\n"
        "movl %edx, 0x14b4(%ecx)\n"
        "movl 0x14f8(%ecx), %eax\n"
        "movl %eax, 0x14b8(%ecx)\n"
        "movl 0x14fc(%ecx), %eax\n"
        "movl %eax, 0x14bc(%ecx)\n"
        "movl 0x1500(%ecx), %eax\n"
        "movl %eax, 0x14c0(%ecx)\n"
        "movl 0x1504(%ecx), %eax\n"
        "movl %eax, 0x14c4(%ecx)\n"
        "movl 0x1508(%ecx), %eax\n"
        "movl %eax, 0x14c8(%ecx)\n"
        ".Lfc643c_000c6598:\n"
        "movl 0x150c(%ecx), %ebx\n" /* line 575 */
        "testl %ebx, %ebx\n"
        "je .Lfc643c_000c6a1b\n"
        "movl 0x195eef4, %eax\n" /* line 577 */
        "movl (%eax), %edx\n"
        "movl 0x14ac(%ecx), %eax\n"
        "movl %eax, 0x219cec(%edx)\n"
        "movl 0x14b0(%ecx), %eax\n"
        "movl %eax, 0x219cf0(%edx)\n"
        "movl 0x14b4(%ecx), %eax\n"
        "movl %eax, 0x219cf4(%edx)\n"
        "movl 0x14b8(%ecx), %eax\n"
        "movl %eax, 0x219cf8(%edx)\n"
        "movl 0x14bc(%ecx), %eax\n"
        "movl %eax, 0x219cfc(%edx)\n"
        "movl 0x14c0(%ecx), %eax\n"
        "movl %eax, 0x219d00(%edx)\n"
        "movl 0x14c4(%ecx), %eax\n"
        "movl %eax, 0x219d04(%edx)\n"
        "movl 0x14c8(%ecx), %eax\n"
        "movl %eax, 0x219d08(%edx)\n"
        /* } scope */
        ".Lfc643c_000c660d:\n"
        "movl 0x54(%esi), %esi\n" /* line 1532 | refdef */
        "movl %esi, -0x2c48(%ebp)\n" /* refdef, viewIndex */
        /* { scope 2: pointLightCount, viewIndex */
        "movl -0x2c5c(%ebp), %edx\n" /* line 1315 | viewParmsDraw */
        "movl %edx, (%esp)\n"
        "calll R_CellForPoint\n"
        "movl %eax, %edx\n"
        /* { scope 3: partitionIndex */
        "movl 0x195eebc, %eax\n" /* line 956 */
        "movl 0x109c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6651\n"
        "movl 0x100(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfc643c_000c6651\n"
        "movl %edx, 4(%esp)\n" /* line 959 */
        "movl -0x2c5c(%ebp), %ecx\n" /* viewParmsDraw */
        "movl %ecx, (%esp)\n"
        "calll R_AddWorldSurfacesDpvs\n"
        /* } scope */
        ".Lfc643c_000c6651:\n"
        "calll CG_AddMarks\n" /* line 1328 */
        "calll FX_DrawScheduledEffects\n" /* line 1329 */
        "movl 0x11555b8, %eax\n" /* line 1331 */
        "movl %eax, -0x2c54(%ebp)\n"
        "movl 0x11555bc, %edx\n" /* line 1332 */
        "movl %edx, -0x2c50(%ebp)\n"
        "movl %eax, 4(%esp)\n" /* line 878 */
        "movl %edx, (%esp)\n"
        "calll qsortDrawSurfs\n"
        "movl 0x195eec0, %eax\n" /* line 1158 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfc643c_000c669d\n"
        "movl 0x195eeac, %eax\n" /* line 1161 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfc643c_000c7300\n"
        ".Lfc643c_000c669d:\n"
        "movl $0, -0x2c4c(%ebp)\n" /* line 1341 | pointLightCount */
        ".Lfc643c_000c66a7:\n"
        "movl 0x195ef04, %eax\n" /* line 1279 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc643c_000c6ea1\n"
        "movl 0x195eec0, %eax\n" /* line 1284 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfc643c_000c7080\n"
        "movl 0x195eef0, %eax\n" /* line 1289 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6aac\n"
        "movl 0x195eec8, %eax\n" /* line 1215 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $0, (%esp)\n" /* line 1216 */
        "calll R_AddCmdSetRenderTarget\n"
        "xorl %eax, %eax\n" /* line 1217 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "movl $0x21, 8(%esp)\n" /* line 1218 */
        ".Lfc643c_000c6723:\n"
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        ".Lfc643c_000c673b:\n"
        "movl 0x195eee4, %eax\n" /* line 1353 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6771\n"
        "testb $2, %al\n" /* line 1355 */
        "jne .Lfc643c_000c7038\n"
        ".Lfc643c_000c6751:\n"
        "movl $0x1d, 8(%esp)\n" /* line 1357 */
        "movl -0x2c54(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        ".Lfc643c_000c6771:\n"
        "calll R_UnlockSkinnedCache\n" /* line 1366 */
        /* } scope */
        "movl 0x195eeb4, %eax\n" /* line 1536 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lfc643c_000c6a10\n"
        "cmpl 0x115500c, %edx\n"
        "jge .Lfc643c_000c6a10\n"
        "movl $0, 4(%esp)\n" /* line 1538 */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x98(%eax)\n"
        "movl $0x222e04, -0xc18(%ebp)\n" /* line 188 | pointLightPartitions */
        "movl $0x217dc8, -0xc14(%ebp)\n" /* "xmodel" */
        "movl $0x222e0c, -0xc10(%ebp)\n" /* "smodel" */
        "movl $0x222e14, -0xc0c(%ebp)\n" /* "bmodel" */
        "movl $0x222e1c, -0xc08(%ebp)\n" /* "sprite" */
        "movl $0x222e24, -0xc04(%ebp)\n" /* "rail core" */
        "movl $0x219e5c, -0xc00(%ebp)\n" /* "cloud" */
        "movl $0x222e30, -0xbfc(%ebp)\n" /* "oriented" */
        "movl $0x219df4, -0xbf8(%ebp)\n" /* "line" */
        "movl $0x219e04, -0xbf4(%ebp)\n" /* "cylinder" */
        "movl 0x115500c, %eax\n" /* line 193 */
        "testl %eax, %eax\n"
        "je .Lfc643c_000c7154\n"
        "xorl %eax, %eax\n"
        "movl 0x115500c, %edx\n"
        ".Lfc643c_000c6823:\n"
        "movl %eax, -0x2c10(%ebp, %eax, 4)\n" /* line 194 */
        "addl $1, %eax\n" /* line 193 */
        "cmpl %eax, %edx\n"
        "jne .Lfc643c_000c6823\n"
        ".Lfc643c_000c6831:\n"
        "movl $R_CompareDumpSceneEntities, 0xc(%esp)\n" /* line 196 */
        "movl $4, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c10(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl 0x115500c, %eax\n" /* line 198 */
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6a10\n"
        "movl $0, -0x2c38(%ebp)\n"
        "movl -0x2c38(%ebp), %ecx\n"
        ".Lfc643c_000c6870:\n"
        "movl -0x2c10(%ebp, %ecx, 4), %edx\n" /* line 200 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %eax\n"
        "movl %eax, -0x2c40(%ebp)\n"
        "movl 0x195eef4, %ebx\n" /* line 201 */
        "leal (, %edx, 8), %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl (%ebx), %edx\n"
        "leal 0xa0010(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x2c3c(%ebp)\n"
        "addl $1, %ecx\n" /* line 158 */
        "movl %ecx, -0x2c34(%ebp)\n"
        "cmpl 0x115500c, %ecx\n"
        "je .Lfc643c_000c6e66\n"
        "movl -0x2c38(%ebp), %eax\n"
        "leal -0x2c10(%ebp, %eax, 4), %eax\n"
        "movl %eax, -0x2c28(%ebp)\n"
        "shll $2, %ecx\n"
        "movl %ecx, -0x2c24(%ebp)\n"
        "movl %eax, %edx\n"
        ".Lfc643c_000c68de:\n"
        "movl (%edx), %ecx\n" /* line 128 */
        "movl -0x2c24(%ebp), %eax\n" /* line 129 */
        "movl -0x2c10(%ebp, %eax), %esi\n"
        "movl (%ebx), %eax\n" /* line 130 */
        "leal (, %ecx, 8), %edx\n"
        "subl %ecx, %edx\n"
        "leal (%ecx, %edx, 4), %edx\n"
        "leal 0xa0010(%eax, %edx, 4), %edx\n"
        "movl %edx, -0x2c2c(%ebp)\n"
        "leal (, %esi, 8), %edx\n" /* line 131 */
        "subl %esi, %edx\n"
        "leal (%esi, %edx, 4), %edx\n"
        "leal 0xa0010(%eax, %edx, 4), %ebx\n"
        "movl -0x2c2c(%ebp), %edx\n" /* line 133 */
        "movl (%edx), %edi\n"
        "cmpl (%ebx), %edi\n" /* line 134 */
        "jne .Lfc643c_000c698e\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 137 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %edx\n"
        "leal (%esi, %esi, 2), %eax\n" /* line 138 */
        "leal (%esi, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %esi\n"
        "cmpl $2, %edi\n" /* line 139 */
        "jg .Lfc643c_000c6e32\n"
        "cmpl $1, %edi\n"
        "jl .Lfc643c_000c6fff\n"
        "movl 4(%edx), %eax\n" /* line 145 */
        "subl 4(%esi), %eax\n"
        ".Lfc643c_000c6959:\n"
        "testl %eax, %eax\n" /* line 160 */
        "jne .Lfc643c_000c698e\n"
        "addl $1, -0x2c34(%ebp)\n" /* line 158 */
        "addl $4, -0x2c24(%ebp)\n"
        "movl -0x2c34(%ebp), %eax\n"
        "cmpl 0x115500c, %eax\n"
        "je .Lfc643c_000c6ff2\n"
        "movl 0x195eef4, %ebx\n"
        "movl -0x2c28(%ebp), %edx\n"
        "jmp .Lfc643c_000c68de\n"
        ".Lfc643c_000c698e:\n"
        "movl -0x2c34(%ebp), %ebx\n"
        "movl -0x2c3c(%ebp), %edx\n"
        ".Lfc643c_000c699a:\n"
        "subl -0x2c38(%ebp), %ebx\n" /* line 164 */
        "movl (%edx), %eax\n" /* line 203 */
        "movl -0xc18(%ebp, %eax, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0x222e3c, (%esp)\n" /* "%3i: %-8s: " */
        "calll Com_Printf\n"
        "movl -0x2c3c(%ebp), %ecx\n" /* line 204 */
        "movl (%ecx), %eax\n"
        "cmpl $2, %eax\n"
        "jg .Lfc643c_000c6e05\n"
        "cmpl $1, %eax\n"
        "jl .Lfc643c_000c6fb4\n"
        "movl -0x2c40(%ebp), %ecx\n" /* line 212 */
        "movl 4(%ecx), %eax\n"
        ".Lfc643c_000c69e0:\n"
        "movl %eax, (%esp)\n"
        "calll XModelGetName\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        ".Lfc643c_000c69f8:\n"
        "addl %ebx, -0x2c38(%ebp)\n" /* line 198 */
        "movl -0x2c38(%ebp), %ecx\n"
        "cmpl %ecx, 0x115500c\n"
        "jne .Lfc643c_000c6870\n"
        /* } scope */
        ".Lfc643c_000c6a10:\n"
        "addl $0x2c7c, %esp\n" /* line 1541 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pointLightPartitions */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6a1b:\n"
        "movl 0x195eef4, %eax\n" /* line 582 */
        "movl (%eax), %eax\n"
        "movl $0, 0x219cec(%eax)\n"
        "jmp .Lfc643c_000c660d\n"
        ".Lfc643c_000c6a31:\n"
        "movl 0x14cc(%ecx), %eax\n" /* line 542 */
        "cmpl 0x14ec(%ecx), %eax\n"
        "je .Lfc643c_000c6c92\n"
        "movl 0x14ec(%ecx), %eax\n" /* line 544 */
        "movl %eax, 0x14ac(%ecx)\n"
        "movl 0x14f0(%ecx), %eax\n"
        "movl %eax, 0x14b0(%ecx)\n"
        "movl %edx, 0x14b4(%ecx)\n"
        "movl 0x14f8(%ecx), %eax\n"
        "movl %eax, 0x14b8(%ecx)\n"
        "movl 0x14fc(%ecx), %eax\n"
        "movl %eax, 0x14bc(%ecx)\n"
        "movl 0x1500(%ecx), %eax\n"
        "movl %eax, 0x14c0(%ecx)\n"
        "movl 0x1504(%ecx), %eax\n"
        "movl %eax, 0x14c4(%ecx)\n"
        "movl 0x1508(%ecx), %eax\n"
        "movl %eax, 0x14c8(%ecx)\n"
        "movl $0, 0x14f4(%ecx)\n" /* line 545 */
        "jmp .Lfc643c_000c6598\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6aac:\n"
        "movl $2, (%esp)\n" /* line 1232 */
        "calll R_BeginDrawGroupSection\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c71c4\n"
        ".Lfc643c_000c6ac0:\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1240 | viewIndex */
        "movl %ecx, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl 0x195eec8, %eax\n" /* line 1242 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $1, 8(%esp)\n" /* line 1243 */
        "movl -0x2c54(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl $6, 8(%esp)\n" /* line 1244 */
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1245 | viewIndex */
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSun\n"
        "movl -0x2c48(%ebp), %eax\n" /* line 1246 | viewIndex */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll R_EndDrawGroupLoop\n"
        "testl %eax, %eax\n"
        "jne .Lfc643c_000c6b78\n"
        "cmpb $0, -0x2c55(%ebp)\n" /* line 1249 */
        "jne .Lfc643c_000c7076\n"
        ".Lfc643c_000c6b78:\n"
        "movl $2, (%esp)\n" /* line 1252 */
        "calll R_EndDrawGroupSection\n"
        "movl $3, (%esp)\n" /* line 1254 */
        "calll R_BeginDrawGroupSection\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1256 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl 0x195eec8, %eax\n" /* line 1258 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        /* { scope 3: partitionIndex */
        /* { scope 4 */
        "movl -0x2c4c(%ebp), %eax\n" /* line 986 | pointLightCount */
        "testl %eax, %eax\n"
        "jg .Lfc643c_000c723a\n"
        /* } scope */
        /* } scope */
        ".Lfc643c_000c6be1:\n"
        "movl $0x15, 8(%esp)\n" /* line 1260 */
        "movl -0x2c54(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1261 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_EndDrawGroupLoop\n"
        "movl $3, (%esp)\n" /* line 1263 */
        "calll R_EndDrawGroupSection\n"
        "movl $4, (%esp)\n" /* line 1265 */
        "calll R_BeginDrawGroupSection\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1267 | viewIndex */
        "movl %ecx, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl 0x195eec8, %eax\n" /* line 1269 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "cmpb $0, -0x2c55(%ebp)\n" /* line 1270 */
        "jne .Lfc643c_000c7223\n"
        ".Lfc643c_000c6c7f:\n"
        "movl -0x2c48(%ebp), %eax\n" /* line 1273 | viewIndex */
        "movl %eax, (%esp)\n"
        "calll R_AddCmdDrawSunPostEffects\n"
        "jmp .Lfc643c_000c673b\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6c92:\n"
        "movl 0x14f0(%ecx), %edi\n" /* line 549 */
        "movl %edx, %eax\n"
        "subl %edi, %eax\n"
        "testl %eax, %eax\n" /* line 550 */
        "jle .Lfc643c_000c72f0\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        ".Lfc643c_000c6cb0:\n"
        "subl %edi, %ebx\n" /* line 553 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "minss %xmm2, %xmm0\n" /* line 554 */
        "movaps %xmm0, %xmm2\n"
        "movss 0x14dc(%ecx), %xmm1\n" /* line 557 */
        "movss 0x14fc(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14bc(%ecx)\n"
        "movss 0x14e0(%ecx), %xmm1\n" /* line 558 */
        "movss 0x1500(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14c0(%ecx)\n"
        "movss 0x14e4(%ecx), %xmm1\n" /* line 561 */
        "movss 0x1504(%ecx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x14c4(%ecx)\n"
        "movzbl 0x14d8(%ecx), %edx\n" /* line 527 */
        "cvtsi2ssl %edx, %xmm1\n" /* line 563 */
        "movzbl 0x14f8(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14b8(%ecx)\n"
        "movzbl 0x14d9(%ecx), %edx\n" /* line 527 */
        "cvtsi2ssl %edx, %xmm1\n" /* line 564 */
        "movzbl 0x14f9(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14b9(%ecx)\n"
        "movzbl 0x14da(%ecx), %edx\n" /* line 527 */
        "cvtsi2ssl %edx, %xmm1\n" /* line 565 */
        "movzbl 0x14fa(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14ba(%ecx)\n"
        /* { scope 3: partitionIndex */
        "movzbl 0x14db(%ecx), %edx\n" /* line 527 */
        /* } scope */
        "cvtsi2ssl %edx, %xmm1\n" /* line 566 */
        "movzbl 0x14fb(%ecx), %eax\n"
        "subl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss %xmm0, %xmm2\n" /* frac */
        "addss %xmm2, %xmm1\n" /* frac */
        "cvttss2si %xmm1, %eax\n"
        "movb %al, 0x14bb(%ecx)\n"
        "movl 0x14ec(%ecx), %eax\n" /* line 568 */
        "movl %eax, 0x14ac(%ecx)\n"
        "movb $1, 0x14c8(%ecx)\n" /* line 569 */
        "cmpb $0, 0x150a(%ecx)\n" /* line 571 */
        "je .Lfc643c_000c7062\n"
        ".Lfc643c_000c6df5:\n"
        "movl $1, %eax\n"
        ".Lfc643c_000c6dfa:\n"
        "movb %al, 0x14ca(%ecx)\n"
        "jmp .Lfc643c_000c6598\n"
        /* } scope */
        ".Lfc643c_000c6e05:\n"
        "cmpl $3, %eax\n" /* line 204 */
        "je .Lfc643c_000c6e6f\n"
        ".Lfc643c_000c6e0a:\n"
        "movl -0x2c3c(%ebp), %edx\n" /* line 220 */
        "movl 0x54(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c6fe8\n"
        "movl (%eax), %eax\n"
        ".Lfc643c_000c6e1d:\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "jmp .Lfc643c_000c69f8\n"
        ".Lfc643c_000c6e32:\n"
        "cmpl $3, %edi\n" /* line 139 */
        "je .Lfc643c_000c6fda\n"
        ".Lfc643c_000c6e3b:\n"
        "movl -0x2c2c(%ebp), %ecx\n" /* line 149 */
        "movl 0x54(%ecx), %edx\n"
        "subl 0x54(%ebx), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "negl %eax\n"
        "jmp .Lfc643c_000c6959\n"
        ".Lfc643c_000c6e66:\n"
        "movl %ecx, %ebx\n"
        "movl %eax, %edx\n"
        "jmp .Lfc643c_000c699a\n"
        ".Lfc643c_000c6e6f:\n"
        "movl 0x195eebc, %eax\n" /* line 216 */
        "movl 0x109c(%eax), %edx\n"
        "movl -0x2c40(%ebp), %ecx\n"
        "movl 4(%ecx), %eax\n"
        "subl 0x138(%edx), %eax\n"
        "sarl $5, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x222e48, (%esp)\n" /* "*%i
" */
        "calll Com_Printf\n"
        "jmp .Lfc643c_000c69f8\n"
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c6ea1:\n"
        "movl $3, (%esp)\n" /* line 1185 */
        "calll R_BeginDrawGroupSection\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c7186\n"
        ".Lfc643c_000c6eb5:\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1192 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl 0x195eec8, %ebx\n" /* line 1194 | drawSurfs */
        "addl $0x317c, %ebx\n" /* drawSurfs */
        "movl %ebx, 0xc(%esp)\n" /* drawSurfs */
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $3, 8(%esp)\n" /* line 1195 */
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1196 | viewIndex */
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSun\n"
        "movl -0x2c48(%ebp), %eax\n" /* line 1197 | viewIndex */
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll R_EndDrawGroupLoop\n"
        "movl $3, (%esp)\n" /* line 1199 */
        "calll R_EndDrawGroupSection\n"
        "movl $4, (%esp)\n" /* line 1201 */
        "calll R_BeginDrawGroupSection\n"
        "testl %eax, %eax\n"
        "je .Lfc643c_000c715b\n"
        ".Lfc643c_000c6f5e:\n"
        "movl -0x2c48(%ebp), %edx\n" /* line 1206 | viewIndex */
        "movl %edx, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll R_BeginDrawGroupLoop\n"
        "movl %ebx, 0xc(%esp)\n" /* line 1208 | drawSurfs */
        "movl -0x2c1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "jmp .Lfc643c_000c673b\n"
        /* } scope */
        ".Lfc643c_000c6f9c:\n"
        "movl 0xc(%esi), %eax\n" /* line 1443 | light */
        "cmpl 4(%edx), %eax\n"
        "jne .Lfc643c_000c64f6\n"
        "movb $1, -0x2c55(%ebp)\n"
        "jmp .Lfc643c_000c64fd\n"
        ".Lfc643c_000c6fb4:\n"
        "testl %eax, %eax\n" /* line 204 */
        "jne .Lfc643c_000c6e0a\n"
        "movl $0, 4(%esp)\n" /* line 207 */
        "movl -0x2c40(%ebp), %edx\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "jmp .Lfc643c_000c69e0\n"
        ".Lfc643c_000c6fda:\n"
        "movl 4(%edx), %eax\n" /* line 147 */
        "subl 4(%esi), %eax\n"
        "sarl $5, %eax\n"
        "jmp .Lfc643c_000c6959\n"
        ".Lfc643c_000c6fe8:\n"
        "movl $0x222e50, %eax\n" /* line 220 */
        "jmp .Lfc643c_000c6e1d\n"
        ".Lfc643c_000c6ff2:\n"
        "movl %eax, %ebx\n"
        "movl -0x2c3c(%ebp), %edx\n"
        "jmp .Lfc643c_000c699a\n"
        ".Lfc643c_000c6fff:\n"
        "testl %edi, %edi\n" /* line 139 */
        "jne .Lfc643c_000c6e3b\n"
        "movl $0, 4(%esp)\n" /* line 142 */
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "movl %eax, %ebx\n"
        "movl $0, 4(%esp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjGetModel\n"
        "subl %eax, %ebx\n"
        "movl %ebx, %eax\n"
        "jmp .Lfc643c_000c6959\n"
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7038:\n"
        "movl $0, 0xc(%esp)\n" /* line 1356 */
        "movl $0x3f800000, 8(%esp)\n"
        "movl 0x195ed2c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $6, (%esp)\n"
        "calll R_AddCmdClearScreen\n"
        "jmp .Lfc643c_000c6751\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7062:\n"
        "cmpb $0, 0x14ea(%ecx)\n" /* line 571 */
        "jne .Lfc643c_000c6df5\n"
        "xorl %eax, %eax\n"
        "jmp .Lfc643c_000c6dfa\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7076:\n"
        "calll R_AddCmdApplyEarlyPostEffects\n" /* line 1250 */
        "jmp .Lfc643c_000c6b78\n"
        ".Lfc643c_000c7080:\n"
        "movl 0x195eec8, %eax\n" /* line 1171 */
        "addl $0x317c, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2c1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1155004, 4(%esp)\n"
        "movl scene, %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_AddCmdBeginView\n"
        "movl $0, (%esp)\n" /* line 1172 */
        "calll R_AddCmdSetRenderTarget\n"
        "xorl %eax, %eax\n" /* line 1173 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "movl 0x195eebc, %eax\n" /* line 1174 */
        "movl 0x109c(%eax), %eax\n"
        "addl $0xb4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdLightProperties\n"
        "movl $1, 8(%esp)\n" /* line 1175 */
        "movl -0x2c54(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl $6, 8(%esp)\n" /* line 1176 */
        "movl -0x2c54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x2c50(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll R_AddCmdDrawSurfs\n"
        "movl -0x2c48(%ebp), %ecx\n" /* line 1177 | viewIndex */
        "movl %ecx, (%esp)\n"
        "calll R_AddCmdDrawSun\n"
        "movl $0x15, 8(%esp)\n" /* line 1178 */
        "jmp .Lfc643c_000c6723\n"
        /* } scope */
        ".Lfc643c_000c713b:\n"
        "movl $0x222de4, 4(%esp)\n" /* line 1508 */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfc643c_000c647e\n"
        ".Lfc643c_000c7154:\n"
        "xorl %eax, %eax\n" /* line 193 */
        "jmp .Lfc643c_000c6831\n"
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c715b:\n"
        "movl 0x195eeec, %eax\n" /* line 1203 */
        "movl 4(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdSetViewport\n"
        "jmp .Lfc643c_000c6f5e\n"
        ".Lfc643c_000c7186:\n"
        "movl $0, (%esp)\n" /* line 1187 */
        "calll R_AddCmdSetRenderTarget\n"
        "movl 0x195eeec, %eax\n" /* line 1189 */
        "movl 4(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdSetViewport\n"
        "xorl %eax, %eax\n" /* line 1190 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "jmp .Lfc643c_000c6eb5\n"
        ".Lfc643c_000c71c4:\n"
        "movl $0, (%esp)\n" /* line 1234 */
        "calll R_AddCmdSetRenderTarget\n"
        "movl 0x195eeec, %edx\n" /* line 1236 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdSetViewport\n"
        "xorl %eax, %eax\n" /* line 1057 */
        "calll R_AddClearCommandsForFrameBuffer\n"
        "movl 0x195eebc, %eax\n" /* line 1238 */
        "movl 0x109c(%eax), %eax\n"
        "addl $0xb4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdLightProperties\n"
        "jmp .Lfc643c_000c6ac0\n"
        ".Lfc643c_000c7223:\n"
        "movss -0x2c30(%ebp), %xmm0\n" /* line 1271 */
        "movss %xmm0, (%esp)\n"
        "calll R_AddCmdApplyLatePostEffects\n"
        "jmp .Lfc643c_000c6c7f\n"
        /* { scope 3: partitionIndex */
        /* { scope 4 */
        ".Lfc643c_000c723a:\n"
        "movl $0, -0x2c44(%ebp)\n" /* line 986 | partitionIndex */
        "leal -0xc18(%ebp), %eax\n" /* pointLightPartitions */
        "movl %eax, -0x2c20(%ebp)\n"
        "movl %eax, %edx\n"
        "jmp .Lfc643c_000c725a\n"
        ".Lfc643c_000c7254:\n"
        "movl -0x2c20(%ebp), %edx\n"
        ".Lfc643c_000c725a:\n"
        "movl (%edx), %esi\n" /* line 988 | light */
        "movl 4(%edx), %ebx\n" /* line 989 | drawSurfs */
        "movl 0x11555bc, %eax\n"
        "leal (%eax, %ebx, 8), %ebx\n" /* drawSurfs */
        "movl 8(%edx), %edi\n" /* line 990 | drawSurfCount */
        "movl 0x195eebc, %ecx\n" /* line 996 */
        "movl 0x1048(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x195ed2c, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll R_AddCmdDrawFullScreenColoredQuad\n"
        "movl %esi, 4(%esp)\n" /* line 997 | light */
        "movl $0, (%esp)\n"
        "calll R_AddCmdLightProperties\n"
        "movl $0x12, 8(%esp)\n" /* line 998 */
        "movl %edi, 4(%esp)\n" /* drawSurfCount */
        "movl %ebx, (%esp)\n" /* drawSurfs */
        "calll R_AddCmdDrawSurfs\n"
        "addl $1, -0x2c44(%ebp)\n" /* line 986 | partitionIndex */
        "addl $0xc, -0x2c20(%ebp)\n"
        "movl -0x2c44(%ebp), %edx\n" /* partitionIndex */
        "cmpl %edx, -0x2c4c(%ebp)\n" /* pointLightCount */
        "jne .Lfc643c_000c7254\n"
        "jmp .Lfc643c_000c6be1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c72f0:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 550 | 1.0f */
        "movaps %xmm0, %xmm1\n"
        "jmp .Lfc643c_000c6cb0\n"
        /* } scope */
        /* { scope 2: pointLightCount, viewIndex */
        ".Lfc643c_000c7300:\n"
        "movl $0x100, 0xc(%esp)\n" /* line 1342 */
        "leal -0xc18(%ebp), %eax\n" /* pointLightPartitions */
        "movl %eax, 8(%esp)\n"
        "movl -0x2c54(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x2c50(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_GetPointLightPartitions\n"
        "movl %eax, -0x2c4c(%ebp)\n" /* pointLightCount */
        "jmp .Lfc643c_000c66a7\n"
    );
}

/* line 272 */
__attribute__((naked))
int R_AddStaticModelToScene(int smodelIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x195eeb8, %eax\n" /* line 235 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7336_000c74cc\n"
        "movl 0x115500c, %esi\n" /* line 241 */
        "cmpl $0x7fd, %esi\n"
        "ja .Lfc7336_000c7536\n"
        "movl 0x195eef4, %eax\n" /* line 243 */
        "movl (%eax), %edx\n"
        "movl 0xa000c(%edx), %eax\n"
        "cmpl $0x1ff7, %eax\n"
        "ja .Lfc7336_000c74c2\n"
        "addl $1, %eax\n" /* line 249 */
        "movl %eax, 0xa000c(%edx)\n"
        "addl $1, 0x115500c\n" /* line 250 */
        "testl %esi, %esi\n" /* line 280 | entIndex */
        "js .Lfc7336_000c74cc\n"
        "leal (, %esi, 8), %eax\n" /* line 283 */
        "subl %esi, %eax\n" /* entIndex */
        "leal (%esi, %eax, 4), %eax\n" /* entIndex */
        "movl 0x1155010, %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* backEndRefEnt */
        "movl 8(%ebp), %eax\n" /* line 285 | smodelIndex */
        "leal (%eax, %eax, 2), %edi\n"
        "shll $5, %edi\n"
        "movl 0x195eebc, %edx\n"
        "movl 0x109c(%edx), %eax\n"
        "movl 0xf8(%eax), %eax\n"
        "addl %edi, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* smodelInst */
        "movl $0x74, 8(%esp)\n" /* line 88 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memset\n"
        "movl $2, (%ebx)\n" /* line 289 | backEndRefEnt */
        "leal 0x3c(%ebx), %ecx\n" /* line 291 | backEndRefEnt, to */
        "movl -0x1c(%ebp), %edx\n" /* smodelInst, from */
        "addl $4, %edx\n" /* from */
        /* { scope 2 */
        "movl -0x1c(%ebp), %eax\n" /* line 199 | smodelInst */
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x3c(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x14(%ebx), %eax\n" /* line 292 | backEndRefEnt */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* smodelInst */
        "addl $0x2c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll AxisCopy\n"
        "movl -0x1c(%ebp), %edx\n" /* line 293 | smodelInst */
        "movl 0x50(%edx), %eax\n"
        "movl %eax, 0x38(%ebx)\n" /* backEndRefEnt */
        "movl 0x195eec0, %eax\n" /* line 295 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfc7336_000c74db\n"
        "leal 8(%ebx), %ecx\n" /* line 303 | backEndRefEnt, to */
        "movl -0x1c(%ebp), %edx\n" /* smodelInst, from */
        "addl $0x54, %edx\n" /* from */
        /* { scope 2 */
        "movl -0x1c(%ebp), %edi\n" /* line 199 | smodelInst */
        "movl 0x54(%edi), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lfc7336_000c7454:\n"
        "leal (%esi, %esi, 2), %edx\n" /* line 306 | entIndex */
        "leal (%esi, %edx, 4), %edx\n" /* entIndex */
        "leal 0x11555c0(, %edx, 4), %edx\n"
        "leal 4(%edx), %ebx\n" /* backEndRefEnt */
        "cld\n" /* line 80 */
        "movl $0xd, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $2, 0xc(%ebx)\n" /* line 309 | backEndRefEnt */
        "movl -0x1c(%ebp), %ecx\n" /* line 310 | smodelInst */
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 4(%ebx)\n" /* backEndRefEnt */
        "leal 0x18(%edx), %ebx\n" /* line 311 | to */
        "movl -0x1c(%ebp), %ecx\n" /* smodelInst, from */
        "addl $0x14, %ecx\n" /* from */
        /* { scope 2 */
        "movl -0x1c(%ebp), %edi\n" /* line 199 | smodelInst */
        "movl 0x14(%edi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "leal 0x24(%edx), %ebx\n" /* line 312 | to */
        "movl %edi, %ecx\n" /* from */
        "addl $0x20, %ecx\n" /* from */
        /* { scope 2 */
        "movl 0x20(%edi), %eax\n" /* line 199 */
        "movl %eax, 0x24(%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        /* } scope */
        "movl %esi, %eax\n" /* line 315 | entIndex */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc7336_000c74c2:\n"
        "movl (%edx), %eax\n" /* line 254 */
        "cmpl warnCount, %eax\n"
        "jne .Lfc7336_000c750c\n"
        /* { scope 2 */
        ".Lfc7336_000c74cc:\n"
        "movl $0xffffffff, %esi\n" /* line 314 | entIndex */
        /* } scope */
        /* } scope */
        ".Lfc7336_000c74d1:\n"
        "movl %esi, %eax\n" /* line 315 | entIndex */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc7336_000c74db:\n"
        "movl 0x195eebc, %ecx\n" /* line 297 */
        "movl 0x109c(%ecx), %edx\n"
        "movl %edi, %eax\n"
        "addl 0x12c(%edx), %eax\n"
        "movl %eax, 8(%ebx)\n" /* backEndRefEnt */
        "movl 0x109c(%ecx), %eax\n" /* line 298 */
        "movl 0x130(%eax), %eax\n"
        "movl 8(%ebp), %edi\n" /* smodelIndex */
        "movl (%eax, %edi, 4), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* backEndRefEnt */
        "jmp .Lfc7336_000c7454\n"
        ".Lfc7336_000c750c:\n"
        "movl %eax, warnCount\n" /* line 256 */
        "movl $0x1ff8, 8(%esp)\n" /* line 257 */
        "movl $0x222d94, 4(%esp)\n" /* "too many visible models (more than %i)
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "movl $0xffffffff, %esi\n"
        "jmp .Lfc7336_000c74d1\n"
        ".Lfc7336_000c7536:\n"
        "movl 0x195eef4, %eax\n" /* line 263 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfc7336_000c74cc\n"
        "movl %eax, warnCount\n" /* line 265 */
        "movl $0x7fe, 8(%esp)\n" /* line 266 */
        "movl $0x222dbc, 4(%esp)\n" /* "too many scene entities (more than %i)
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "movl $0xffffffff, %esi\n"
        "jmp .Lfc7336_000c74d1\n"
    );
}

/* line 385 */
__attribute__((naked))
GfxEntity * R_AddRefEntityToScene(const GfxEntity *refEnt, GfxModel sceneModel, const struct centity_s *cent)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* refEnt */
        /* { scope 1 */
        "cmpl $1, (%esi)\n" /* line 394 | refEnt */
        "jle .Lfc7574_000c77a3\n"
        "movl 0x195ed14, %eax\n" /* line 399 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfc7574_000c76de\n"
        ".Lfc7574_000c759a:\n"
        "movl (%esi), %eax\n" /* line 402 | refEnt */
        "cmpl $9, %eax\n"
        "ja .Lfc7574_000c7722\n"
        ".Lfc7574_000c75a5:\n"
        "movl 0x195eef4, %eax\n" /* line 405 */
        "movl (%eax), %edx\n"
        "movl 0xa000c(%edx), %ecx\n"
        "cmpl $0x1ff7, %ecx\n"
        "ja .Lfc7574_000c76c4\n"
        "movl 0x195eeb8, %eax\n" /* line 235 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7574_000c76d2\n"
        "movl 0x115500c, %ebx\n" /* line 241 */
        "cmpl $0x7fd, %ebx\n"
        "ja .Lfc7574_000c773f\n"
        "leal 1(%ecx), %eax\n" /* line 249 */
        "movl %eax, 0xa000c(%edx)\n"
        "addl $1, 0x115500c\n" /* line 250 */
        "testl %ebx, %ebx\n" /* line 416 | backEndRefEnt */
        "js .Lfc7574_000c76d2\n"
        /* { scope 2: sceneEnt, sceneEnt */
        "leal (%ebx, %ebx, 2), %eax\n" /* line 100 */
        "leal (%ebx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* sceneEnt */
        "leal (, %ebx, 8), %eax\n" /* line 101 */
        "subl %ebx, %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl %eax, %edi\n" /* backEndRefEnt */
        "addl 0x1155010, %edi\n" /* backEndRefEnt */
        "movl $0x74, 8(%esp)\n" /* line 105 */
        "movl %esi, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* backEndRefEnt */
        "calll memcpy\n"
        "pxor %xmm0, %xmm0\n" /* line 106 */
        "ucomiss 0x38(%esi), %xmm0\n"
        "jne .Lfc7574_000c764a\n"
        "jp .Lfc7574_000c764a\n"
        "movl $0x3f800000, 0x38(%edi)\n" /* line 107 | backEndRefEnt */
        /* { scope 3 */
        ".Lfc7574_000c764a:\n"
        "cld\n" /* line 80 */
        "movl $0xd, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x1c(%ebp), %edi\n" /* sceneEnt */
        "rep stosl %eax, %es:(%edi)\n"
        /* } scope */
        "cmpl $3, (%esi)\n" /* line 111 */
        "jle .Lfc7574_000c7795\n"
        "movl 0x54(%esi), %ecx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl 0x195eef4, %edi\n" /* line 655 | backEndRefEnt */
        "movl (%edi), %edx\n" /* backEndRefEnt */
        "movl 4(%edx), %eax\n"
        "cmpl $0xffff, %eax\n"
        "jg .Lfc7574_000c76b1\n"
        "leal 8(%edx, %eax, 8), %esi\n" /* line 660 | drawSurf */
        "movl s_entitySurface, %edx\n" /* line 663 */
        "cmpl $2, %edx\n" /* line 667 */
        "je .Lfc7574_000c787c\n"
        ".Lfc7574_000c7688:\n"
        "shll $4, %ebx\n" /* line 676 | backEndRefEnt */
        "addl %ebx, %edx\n" /* backEndRefEnt */
        "movzwl 0xa(%ecx), %eax\n" /* line 677 */
        "shll $0x15, %eax\n"
        "leal 0x1f0000(%edx, %eax), %eax\n" /* line 678 */
        ".Lfc7574_000c769b:\n"
        "movl %eax, (%esi)\n" /* line 680 | drawSurf */
        "movl $s_entitySurface, 4(%esi)\n" /* line 681 | drawSurf */
        "addl $1, 0x11555b8\n" /* line 685 */
        "movl (%edi), %eax\n" /* line 686 | backEndRefEnt */
        "addl $1, 4(%eax)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfc7574_000c76b1:\n"
        "movl -0x28(%ebp), %ebx\n" /* line 420 | backEndRefEnt */
        "addl 0x1155010, %ebx\n" /* backEndRefEnt */
        /* } scope */
        "movl %ebx, %eax\n" /* line 421 | backEndRefEnt */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc7574_000c76c4:\n"
        "movl (%edx), %eax\n" /* line 407 */
        "cmpl warnCount, %eax\n"
        "jne .Lfc7574_000c7773\n"
        ".Lfc7574_000c76d2:\n"
        "xorl %ebx, %ebx\n" /* line 420 | backEndRefEnt */
        /* } scope */
        ".Lfc7574_000c76d4:\n"
        "movl %ebx, %eax\n" /* line 421 | backEndRefEnt */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc7574_000c76de:\n"
        "movl 0x195eef4, %eax\n" /* line 399 */
        "movl (%eax), %eax\n"
        "cmpl $0x1cc4, 0xa000c(%eax)\n"
        "jbe .Lfc7574_000c759a\n"
        "movl $0x222e58, 8(%esp)\n" /* line 400 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $5, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x124(%eax)\n"
        "movl (%esi), %eax\n" /* line 402 | refEnt */
        "cmpl $9, %eax\n"
        "jbe .Lfc7574_000c75a5\n"
        ".Lfc7574_000c7722:\n"
        "movl %eax, 8(%esp)\n" /* line 403 */
        "movl $0x222e74, 4(%esp)\n" /* "R_AddRefEntityToScene: bad reType %i" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfc7574_000c75a5\n"
        ".Lfc7574_000c773f:\n"
        "movl (%edx), %eax\n" /* line 263 */
        "cmpl warnCount, %eax\n"
        "je .Lfc7574_000c76d2\n"
        ".Lfc7574_000c7749:\n"
        "movl %eax, warnCount\n" /* line 265 */
        "movl $0x7fe, 8(%esp)\n" /* line 266 */
        "movl $0x222dbc, 4(%esp)\n" /* "too many scene entities (more than %i)
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lfc7574_000c76d4\n"
        ".Lfc7574_000c7773:\n"
        "movl %eax, warnCount\n" /* line 409 */
        "movl $0x222e9c, 4(%esp)\n" /* line 410 */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "xorl %ebx, %ebx\n" /* backEndRefEnt */
        "jmp .Lfc7574_000c76d4\n"
        /* { scope 2: sceneEnt, sceneEnt */
        ".Lfc7574_000c7795:\n"
        "movl 0xc(%ebp), %eax\n" /* line 117 | sceneModel */
        "movl -0x1c(%ebp), %edx\n" /* sceneEnt */
        "movl %eax, 4(%edx)\n"
        "jmp .Lfc7574_000c76b1\n"
        /* } scope */
        /* { scope 2: sceneEnt, sceneEnt */
        ".Lfc7574_000c77a3:\n"
        "movl 0x195eeb8, %eax\n" /* line 235 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7574_000c76d2\n"
        "movl 0x115500c, %eax\n" /* line 241 */
        "movl %eax, -0x24(%ebp)\n"
        "cmpl $0x7fd, %eax\n"
        "ja .Lfc7574_000c78db\n"
        "movl 0x195eef4, %eax\n" /* line 243 */
        "movl (%eax), %edx\n"
        "movl 0xa000c(%edx), %eax\n"
        "cmpl $0x1ff7, %eax\n"
        "ja .Lfc7574_000c78a3\n"
        "addl $1, %eax\n" /* line 249 */
        "movl %eax, 0xa000c(%edx)\n"
        "addl $1, 0x115500c\n" /* line 250 */
        "movl -0x24(%ebp), %eax\n" /* line 331 */
        "testl %eax, %eax\n"
        "js .Lfc7574_000c76d2\n"
        "movl -0x24(%ebp), %edx\n" /* line 334 */
        "leal (%edx, %edx, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal 0x11555c4(, %eax, 4), %eax\n"
        "movl %eax, -0x20(%ebp)\n" /* sceneEnt */
        "movl %edx, %eax\n" /* line 335 */
        "shll $3, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl 0x1155010, %edx\n"
        "leal (%edx, %eax, 4), %ebx\n" /* backEndRefEnt */
        "movl $0x74, 8(%esp)\n" /* line 337 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* backEndRefEnt */
        "calll memcpy\n"
        "pxor %xmm0, %xmm0\n" /* line 338 */
        "ucomiss 0x38(%esi), %xmm0\n"
        "jne .Lfc7574_000c7847\n"
        "jp .Lfc7574_000c7847\n"
        "movl $0x3f800000, 0x38(%ebx)\n" /* line 339 | backEndRefEnt */
        /* { scope 3 */
        ".Lfc7574_000c7847:\n"
        "cld\n" /* line 80 */
        "movl $0xd, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x20(%ebp), %edi\n" /* sceneEnt */
        "rep stosl %eax, %es:(%edi)\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 342 | sceneModel */
        "movl -0x20(%ebp), %eax\n" /* sceneEnt */
        "movl %edx, 4(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 343 | cent */
        "movl %edx, 8(%eax)\n"
        "cmpl $1, (%esi)\n" /* line 346 */
        "jne .Lfc7574_000c76d4\n"
        "movl -0x24(%ebp), %eax\n" /* line 347 */
        "movl %eax, (%esp)\n"
        "calll R_DrawModel\n"
        "jmp .Lfc7574_000c76d4\n"
        /* } scope */
        /* { scope 2: sceneEnt, sceneEnt */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfc7574_000c787c:\n"
        "movl 0x195ed68, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7574_000c7688\n"
        "shll $0x13, %ebx\n" /* line 670 | backEndRefEnt */
        "movzwl 0xa(%ecx), %eax\n" /* line 671 */
        "shll $9, %eax\n"
        "leal -0x7ffffe0e(%ebx, %eax), %eax\n" /* line 672 | backEndRefEnt */
        "jmp .Lfc7574_000c769b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: sceneEnt, sceneEnt */
        ".Lfc7574_000c78a3:\n"
        "movl (%edx), %eax\n" /* line 254 */
        "cmpl warnCount, %eax\n"
        "je .Lfc7574_000c76d2\n"
        "movl %eax, warnCount\n" /* line 256 */
        "movl $0x1ff8, 8(%esp)\n" /* line 257 */
        "movl $0x222d94, 4(%esp)\n" /* "too many visible models (more than %i)
" */
        "movl $2, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *(%eax)\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lfc7574_000c76d4\n"
        ".Lfc7574_000c78db:\n"
        "movl 0x195eef4, %eax\n" /* line 263 */
        "movl (%eax), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl warnCount, %eax\n"
        "je .Lfc7574_000c76d2\n"
        "jmp .Lfc7574_000c7749\n"
    );
}

