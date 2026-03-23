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

    /* lightingOrigin = midpoint of absmin and absmax */
    lightingOrigin[0] = (smodelInst->mins[0] + smodelInst->maxs[0]) * 0.5f;
    lightingOrigin[1] = (smodelInst->mins[1] + smodelInst->maxs[1]) * 0.5f;
    lightingOrigin[2] = (smodelInst->mins[2] + smodelInst->maxs[2]) * 0.5f;

    *sunVisibility = RB_GetLightingAtPoint(&world->lightGrid, lightingOrigin, colorForDir);
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
        hunkAlloc = ((refimport_t *)imp_ri)->Hunk_AllocInternal;
        world->smodelLightingColorTable = (vec4_t (*)[6])hunkAlloc(smodelCount * 3 * 32);
        world->smodelLightingSunVisTable = (float *)hunkAlloc(smodelCount * 4);
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
    GfxStaticModelInstance *smodelInst;
    GfxAabbTree *aabb;
    int count;

    /* smodelIndex * sizeof(GfxStaticModelInstance) */
    smodelInstOffset = smodelIndex * 96;

top:
    aabb = (GfxAabbTree *)tree;
    count = aabb->staticModelCount;

    /* Check if count is a power of 2 (needs reallocation) or non-power-of-2 (append) */
    {
        int test = count - 1;
        if ((test & count) != 0) {
            /* Non-power-of-2: existing array has room, just append */
            aabb->staticModels[count] = smodelIndex;
            aabb->staticModelCount = count + 1;
        } else {
            /* Power of 2 (or 0): need to allocate a new, larger array */
            int allocCount;
            int *newIndices;

            if (count == 0)
                allocCount = 1;
            else
                allocCount = count * 2;

            newIndices = (int *)Hunk_AllocateTempMemoryInternal(allocCount * 4);
            memcpy(newIndices, aabb->staticModels, count * 4);
            aabb->staticModels = newIndices;
            newIndices[count] = smodelIndex;
            aabb->staticModelCount = count + 1;
        }
    }

    /* Check for children */
    {
        int childCount = aabb->childCount;
        if (childCount == 0)
            return 0;

        /* Compute smodelInst pointer */
        smodelInst = (GfxStaticModelInstance *)((byte *)((GfxWorld *)world)->smodelInsts + smodelInstOffset);

        if (childCount > 0) {
            GfxAabbTree *children = (GfxAabbTree *)(intptr_t)aabb->children;
            GfxAabbTree *child = children;
            int i;

            /* Check each child's bounds against smodelInst bounds */
            for (i = 0; i < childCount; i++, child++) {
                if (child->mins[0] > smodelInst->mins[0])
                    continue;
                if (child->mins[1] > smodelInst->mins[1])
                    continue;
                if (child->mins[2] > smodelInst->mins[2])
                    continue;
                if (smodelInst->maxs[0] > child->maxs[0])
                    continue;
                if (smodelInst->maxs[1] > child->maxs[1])
                    continue;
                if (smodelInst->maxs[2] > child->maxs[2])
                    continue;

                /* Child fully contains the smodel -- tail-recurse into it */
                tree = (byte *)child;
                goto top;
            }

            /* No child contained the smodel. Walk children starting from [0] looking for
             * one with surfaceCount == 0, then check next siblings. */
            {
                GfxAabbTree *firstChild = children;
                int firstSibChildCount = firstChild->surfaceCount;

                if (firstSibChildCount != 0) {
                    child = firstChild;
                } else {
                    int si;
                    for (si = 1; si < childCount; si++) {
                        int sibChildCount = children[si].surfaceCount;
                        if (sibChildCount != 0)
                            break;
                    }
                    child = firstChild;
                }

                /* Expand bounds of 'child' to include smodelInst and recurse */
                {
                    int a;
                    for (a = 0; a < 3; a++) {
                        float smin = smodelInst->mins[a];
                        float smax = smodelInst->maxs[a];
                        if (smin < child->mins[a])
                            child->mins[a] = smin;
                        if (smax > child->maxs[a])
                            child->maxs[a] = smax;
                    }
                    tree = (byte *)child;
                    goto top;
                }
            }
        }

        /* childCount <= 0: allocate a new child */
        {
            int existingCount = childCount;
            int allocSize = (existingCount + 1) * sizeof(GfxAabbTree);
            byte *newChildren = (byte *)Hunk_AllocAlignInternal(allocSize, 4);
            memcpy(newChildren, (void *)(intptr_t)aabb->children, existingCount * sizeof(GfxAabbTree));
            aabb->children = (int)(intptr_t)newChildren;

            {
                GfxAabbTree *newChild = (GfxAabbTree *)(newChildren + existingCount * sizeof(GfxAabbTree));
                aabb->childCount = existingCount + 1;

                /* Copy smodelInst absmin/absmax as new child bounds */
                memcpy(newChild->mins, smodelInst->mins, 12);
                memcpy(newChild->maxs, smodelInst->maxs, 12);

                tree = (byte *)newChild;
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

