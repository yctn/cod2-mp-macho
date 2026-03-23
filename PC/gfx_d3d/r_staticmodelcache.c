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

extern refimport_t ri; /* imp_ri */
extern GfxBackEndData *frontEndDataOut;
/* g_dxCaps was imp_r_rendererInUse, g_dx was imp_dx, g_dxIter was imp_alwaysfails */
extern r_global_permanent_t rgp; /* imp_rgp */

void R_AddFrontendCmd(int type, void *data);
void R_InitStaticModelIndexCache(void);
void R_StaticModelCacheStats_f(void);
void R_UsedCachedStaticModelSurface(GfxStaticModelSurfaceCached *surf);
void R_SkinStaticModelCachedCmd(SkinStaticModelCachedCmd *skinCmd, SkinBuffers *skinBuffers);
void R_InitStaticModelCache(void);
static __attribute_regparm__(3) void SMC_FreeCachedSurface_r(static_model_cache_t *cache, void *tree, int nodeIndex, int levelsToLeaf);
void R_StaticModelCacheFlush_f(void);
void R_ShutdownStaticModelCache(void);
static __attribute_regparm__(2) Bool SMC_GetFreeBlockOfSize(static_model_cache_t *cache, int listIndex);
GfxStaticModelSurfaceCached * R_CacheStaticModelSurface(GfxStaticSurface *staticSurf, const XSurface *xsurf, int smodelIndex, const Material *material);
void R_FlushStaticModelCache(void);

/* line 781 */
void R_InitStaticModelIndexCache(void)
{
    void *mem = ((refimport_t *)imp_ri)->Hunk_AllocInternal(0xc0000);
    ((DxGlobals *)imp_dx)->smodelCacheIndices = (r_index_t *)mem; /* TODO: verify offset 0x2dc8 maps to smodelCacheIndices */
}

/* line 819 */
void R_StaticModelCacheStats_f(void)
{
    ri.Printf(0, "%.2f%% of cache is currently allocated.\n",
               (double)((float)s_cache.stats.allocatedVerts * 100.0f * (1.0f / 65536.0f)));
    if (s_cache.stats.allocatedVerts) {
        ri.Printf(0, "%.2f%% allocated cache vertices are used.\n",
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
    tree->frameCount = frontEndDataOut->frameCount;

    /* Remove tree from its current usedlist position */
    ((static_model_tree_list_t *)tree->usedlist.next)->prev = tree->usedlist.prev;
    ((static_model_tree_list_t *)tree->usedlist.prev)->next = tree->usedlist.next;

    /* Insert tree at front of usedlist */
    tree->usedlist.prev = (int)&s_cache.usedlist;
    tree->usedlist.next = s_cache.usedlist.next;
    s_cache.usedlist.next = (int)&tree->usedlist;
    ((static_model_tree_list_t *)tree->usedlist.next)->prev = (int)&tree->usedlist;
}

/* line 592 — Static model cached skinning command processor: builds bone rotation
 * matrices from entity quaternion + axis + scale, transforms per-surface vertices
 * through bone matrices, writes to cached vertex buffer for reuse across frames.
 * Handles single-bone (rigid) and multi-bone (weighted) paths, Dx7/non-Dx7 layouts.
 * 786 lines of quaternion→matrix + vertex transformation + VB lock/write.
 * Uses cdecl calling convention (all stack args). */
/* R_SkinStaticModelCachedCmd — Static model cached skinning.
 * Builds bone rotation matrix from entity quaternion, transforms vertices
 * through bone matrix, writes to cached vertex buffer.
 * Two paths: non-Dx7 (stride 0x40) and Dx7 (stride 0x18).
 * Non-Dx7 path also computes per-vertex lighting from entity lights. */
extern void AxisTransformVector(const void *matrix, float x, float y, float z, vec_t *out);
extern float Vec3NormalizeTo(const vec_t *v, vec_t *out);
extern int RB_DeriveEntityLights(vec4_t *colorForDir, float sunVisibility, const Material *material, D3DLIGHT9 *lights, int maxLights);
extern void R_FatalLockError(HRESULT hr);
extern void *CColorConverter_GetColorConverter(int mode);
extern int XSurfaceGetBoneOffset(void *surface);
extern float floorf(float x);

void R_SkinStaticModelCachedCmd(SkinStaticModelCachedCmd *skinCmd, SkinBuffers *skinBuffers)
{
    byte *cached;
    byte *xsurf;
    byte *smodelInst;
    int smodelIndex;
    int isDx7;
    float boneMatrix[16]; /* 4x4 rotation+translation matrix */
    float useAxis[12];    /* 3x3 axis for vertex transform */
    float normAxis[9];    /* 3x3 normalized axis for normal transform */
    int vertCount;
    int baseVertIndex;
    byte *skinVerts;
    byte *pSrc;
    byte *pDst;
    void *bufferData;
    void *colorConverter;
    short baseLightingCoords[2];
    int i;
    HRESULT hr;

    /* Extract fields from skinCmd */
    cached = *(byte **)skinCmd;                     /* skinCmd->cached */
    xsurf = *(byte **)(cached + 8);                 /* cached->xsurf */
    smodelIndex = *((int *)skinCmd + 1);             /* skinCmd->smodelIndex */

    /* Get smodelInst from rgp */
    {
        GfxWorld *world = rgp.world;
        smodelInst = (byte *)(world->smodelInsts + smodelIndex);
    }

    /* Get bone offset for this surface */
    {
        byte *ri_ptr = (byte *)imp_ri;
        void *(*getBoneData)(int, int);
        byte *boneData;
        int boneOffset;

        getBoneData = *(void *(**)(int, int))((byte *)imp_ri + 0x1a4); /* TODO: unknown refimport offset 0x1a4 */
        boneOffset = XSurfaceGetBoneOffset(xsurf);
        boneData = (byte *)getBoneData((int)(intptr_t)((GfxStaticModelInstance *)smodelInst)->model, boneOffset);

        /* Build bone rotation matrix from quaternion at boneData */
        {
            float *q = (float *)boneData;
            float w2 = q[7]; /* transWeight at offset 0x1c */
            float x2 = w2 * q[0], y2 = w2 * q[1], z2 = w2 * q[2];
            float xx = x2 * q[0], xy = x2 * q[1], xz = x2 * q[2], xw = x2 * q[3];
            float yy = y2 * q[1], yz = y2 * q[2], yw = y2 * q[3];
            float zz = z2 * q[2], zw = z2 * q[3];

            boneMatrix[0]  = 1.0f - (yy + zz);
            boneMatrix[1]  = zw + xy;
            boneMatrix[2]  = xz - yw;
            boneMatrix[3]  = 0;
            boneMatrix[4]  = xy - zw;
            boneMatrix[5]  = 1.0f - (xx + zz);
            boneMatrix[6]  = xw + yz;
            boneMatrix[7]  = 0;
            boneMatrix[8]  = xz + yw;
            boneMatrix[9]  = yz - xw;
            boneMatrix[10] = 1.0f - (xx + yy);
            boneMatrix[11] = 0;
            /* Translation from boneData+0x10 */
            boneMatrix[12] = q[4]; /* trans[0] */
            boneMatrix[13] = q[5]; /* trans[1] */
            boneMatrix[14] = q[6]; /* trans[2] */
            boneMatrix[15] = 1.0f;
        }
    }

    /* R_GetRigidTransform: compute useAxis (3x4 transform matrix) */
    {
        extern void R_GetRigidTransform(const float *boneMatrix, const float *origin,
            const float *axis, float scale, float *outAxis);
        R_GetRigidTransform(boneMatrix,
            (float *)((GfxStaticModelInstance *)smodelInst)->origin,
            (float *)((GfxStaticModelInstance *)smodelInst)->axis,
            ((GfxStaticModelInstance *)smodelInst)->scale, useAxis);
    }

    /* Normalize useAxis rows into normAxis */
    Vec3NormalizeTo(useAxis + 0, normAxis + 0);
    Vec3NormalizeTo(useAxis + 3, normAxis + 3);
    Vec3NormalizeTo(useAxis + 6, normAxis + 6);

    /* Get vertex info */
    {
        const XSurface *xs = (const XSurface *)xsurf;
        vertCount = (int)xs->vertCount;
        baseVertIndex = *(int *)cached;
    }

    /* Get source vertex data */
    skinVerts = (byte *)((const XSurface *)xsurf)->verts;

    /* Check renderer type for Dx7 vs non-Dx7 path */
    isDx7 = (*(int *)(*(byte **)imp_r_rendererInUse + 8) == 2);

    if (!isDx7) {
        /* Non-Dx7 path: stride 0x40, includes lighting */
        pSrc = (byte *)skinBuffers + 0x2000;

        /* Compute base lighting coordinates */
        {
            byte *world2 = (byte *)rgp.world;
            float *blc = (float *)(*(byte **)(world2 + 0xf8) + smodelIndex * 96 + 0x54);
            float val;

            val = blc[0] * 32768.0f + 0.5f;
            baseLightingCoords[0] = (short)(int)floorf(val);
            val = blc[1] * 32768.0f + 0.5f;
            baseLightingCoords[1] = (short)(int)floorf(val);
        }

        /* Transform vertices: position through useAxis, normal through normAxis */
        if (vertCount > 0) {
            byte *src = pSrc;
            byte *dst = pSrc; /* writes back in-place into skinBuffers */

            for (i = 0; i < vertCount; i++) {
                const XVertexInfo *sv = (const XVertexInfo *)skinVerts + i;
                GfxSModelCachedVertex *dv = (GfxSModelCachedVertex *)src + i;
                GfxSModelCachedVertex *dvd = (GfxSModelCachedVertex *)dst + i;

                /* Transform position: pos = useAxis * srcPos + translation */
                dv->xyz[0] = sv->offset[0] * useAxis[0] + sv->offset[1] * useAxis[3] + sv->offset[2] * useAxis[6] + useAxis[9];
                dv->xyz[1] = sv->offset[0] * useAxis[1] + sv->offset[1] * useAxis[4] + sv->offset[2] * useAxis[7] + useAxis[10];
                dv->xyz[2] = sv->offset[0] * useAxis[2] + sv->offset[1] * useAxis[5] + sv->offset[2] * useAxis[8] + useAxis[11];

                /* Transform normal through normAxis */
                AxisTransformVector(normAxis, sv->normal[0], sv->normal[1], sv->normal[2], dvd->normal);

                /* Copy color bytes */
                dvd->color.array[0] = sv->color[3];
                dvd->color.array[1] = sv->color[0];
                dvd->color.array[2] = sv->color[1];
                dvd->color.array[3] = sv->color[2];

                /* Copy texcoords */
                dvd->texCoord[0] = sv->texCoordX;
                dvd->texCoord[1] = sv->texCoordY;

                /* Store base lighting coords */
                dvd->baseLightingCoords[0] = baseLightingCoords[0];
                dvd->baseLightingCoords[1] = baseLightingCoords[1];

                /* Transform tangent (binormal in XVertexInfo) through normAxis */
                AxisTransformVector(normAxis, sv->binormal[0], sv->binormal[1], sv->binormal[2], dvd->binormal);

                /* Transform binormal (tangent in XVertexInfo) through normAxis */
                AxisTransformVector(normAxis, sv->tangent[0], sv->tangent[1], sv->tangent[2], dvd->tangent);
            }
        }

        /* Lock vertex buffer and copy data */
        {
            IDirect3DVertexBuffer9 *vb = ((DxGlobals *)imp_dx)->smodelCacheVb;
            void **vtable = *(void ***)vb;
            int lockSize = vertCount * 0x40;
            int lockOffset = baseVertIndex * 0x40;

            hr = ((int (*)(void *, int, int, void **, int))vtable[0x2c/4])(
                vb, lockOffset, lockSize, &bufferData, 0x1001);
            if (hr < 0) {
                R_FatalLockError(hr);
            }

            /* Copy transformed vertices to VB via color converter */
            colorConverter = CColorConverter_GetColorConverter(0);

            if (vertCount > 0) {
                byte *src2 = pSrc;
                byte *dst2 = (byte *)bufferData;

                for (i = 0; i < vertCount; i++) {
                    /* Copy position (12 bytes) */
                    memcpy(dst2, src2, 12);
                    /* Convert color */
                    {
                        void **ccvt = *(void ***)colorConverter;
                        ((void (*)(void *, void *, void *))ccvt[0])(colorConverter,
                            dst2 + 0x18, src2 + 0x18);
                    }
                    /* Copy remaining vertex data */
                    memcpy(dst2 + 0xc, src2 + 0xc, 8);
                    memcpy(dst2 + 0x10, src2 + 0x10, 8);
                    memcpy(dst2 + 0x24, src2 + 0x24, 4);
                    memcpy(dst2 + 0x26, src2 + 0x26, 2);
                    memcpy(dst2 + 0x28, src2 + 0x28, 12);
                    memcpy(dst2 + 0x34, src2 + 0x34, 12);

                    src2 += 0x40;
                    dst2 += 0x40;
                }
            }

            /* Unlock VB */
            do {
                vtable = *(void ***)vb;
                ((void (*)(void *))vtable[0x30/4])(vb);
            } while (*(volatile int *)imp_alwaysfails != 0);
        }
    } else {
        /* Dx7 path: stride 0x18, simpler vertex layout */
        D3DLIGHT9 lights[8];
        int lightCount;

        pSrc = (byte *)skinBuffers + 0x2000;

        /* Derive entity lights for Dx7 */
        {
            GfxWorld *world3 = rgp.world;
            float *sunVisPtr = world3->smodelLightingSunVisTable;
            byte *lightingColors = (byte *)world3->smodelLightingColorTable;

            lightCount = RB_DeriveEntityLights(
                (vec4_t *)(lightingColors + smodelIndex * 96),
                sunVisPtr[smodelIndex],
                NULL, lights, 8);
        }

        /* Transform vertices: position + normal, then compute Dx7 lighting color */
        if (vertCount > 0) {
            GfxSModelCachedVertexDx7 *pSrcDx7 = (GfxSModelCachedVertexDx7 *)((byte *)skinBuffers + 0x2000);
            (void)skinVerts; /* srcVert was unused */

            for (i = 0; i < vertCount; i++) {
                const XVertexInfo *sv = (const XVertexInfo *)skinVerts + i;
                float normal[3];

                /* Transform position */
                pSrcDx7[i].xyz[0] = sv->offset[0] * useAxis[0] + sv->offset[1] * useAxis[3] + sv->offset[2] * useAxis[6] + useAxis[9];
                pSrcDx7[i].xyz[1] = sv->offset[0] * useAxis[1] + sv->offset[1] * useAxis[4] + sv->offset[2] * useAxis[7] + useAxis[10];
                pSrcDx7[i].xyz[2] = sv->offset[0] * useAxis[2] + sv->offset[1] * useAxis[5] + sv->offset[2] * useAxis[8] + useAxis[11];

                /* Transform normal */
                AxisTransformVector(normAxis, sv->normal[0], sv->normal[1], sv->normal[2], normal);

                /* Copy texcoords */
                pSrcDx7[i].texCoord[0] = sv->texCoordX;
                pSrcDx7[i].texCoord[1] = sv->texCoordY;

                /* Compute lighting color from entity lights */
                {
                    float r = 0.0f, g = 0.0f, b = 0.0f;
                    int li;

                    for (li = 0; li < lightCount; li++) {
                        float *lightData = (float *)&lights[li];
                        float dot = normal[0] * lightData[0x1c/4] +
                                    normal[1] * lightData[0x20/4] +
                                    normal[2] * lightData[0x24/4];
                        /* Negate and clamp */
                        dot = -dot; /* xorps with sign bit */
                        if (dot > 0.0f) {
                            r += dot * lightData[-0x20/4];
                            g += dot * lightData[-0x1c/4];
                            b += dot * lightData[-0x18/4];
                        }
                    }

                    /* Quantize and clamp to [0, 255] */
                    {
                        const byte *srcColor = sv->color;
                        byte *dstColor = (byte *)&pSrcDx7[i].color;
                        float oneOver255 = 0.003921568859368563f;
                        int ch;

                        ch = (int)floorf(r * (float)srcColor[2] * oneOver255 * 255.0f + 0.5f);
                        if (ch > 255) ch = 255; if (ch < 0) ch = 0;
                        dstColor[0] = (byte)ch;

                        ch = (int)floorf(b * (float)srcColor[1] * oneOver255 * 255.0f + 0.5f);
                        if (ch > 255) ch = 255; if (ch < 0) ch = 0;
                        dstColor[1] = (byte)ch;

                        ch = (int)floorf(g * (float)srcColor[0] * oneOver255 * 255.0f + 0.5f);
                        if (ch > 255) ch = 255; if (ch < 0) ch = 0;
                        dstColor[2] = (byte)ch;

                        ch = (int)floorf((float)srcColor[3] * oneOver255 * 255.0f + 0.5f);
                        if (ch > 255) ch = 255; if (ch < 0) ch = 0;
                        dstColor[3] = (byte)ch;
                    }
                }
            }
        }

        /* Lock VB and copy Dx7 vertices */
        {
            byte *dx = (byte *)imp_dx;
            byte *vb = (byte *)((DxGlobals *)dx)->smodelCacheVb;
            void **vtable = *(void ***)vb;
            int lockSize = vertCount * 0x18;
            int lockOffset = baseVertIndex * 0x18;

            hr = ((int (*)(void *, int, int, void **, int))vtable[0x2c/4])(
                vb, lockOffset, lockSize, &bufferData, 0x1001);
            if (hr < 0) {
                R_FatalLockError(hr);
            }

            pSrc = (byte *)skinBuffers + 0x2000;
            pDst = (byte *)bufferData;
            colorConverter = CColorConverter_GetColorConverter(0);

            if (vertCount > 0) {
                for (i = 0; i < vertCount; i++) {
                    /* Copy position (12 bytes) */
                    memcpy(pDst, pSrc, 12);
                    /* Convert color */
                    {
                        void **ccvt = *(void ***)colorConverter;
                        ((void (*)(void *, void *, void *))ccvt[0])(colorConverter,
                            pDst + 0xc, pSrc + 0xc);
                    }
                    /* Copy texcoords (8 bytes) */
                    memcpy(pDst + 0x10, pSrc + 0x10, 8);
                    pSrc += 0x18;
                    pDst += 0x18;
                }
            }

            /* Unlock VB */
            do {
                vtable = *(void ***)vb;
                ((void (*)(void *))vtable[0x30/4])(vb);
            } while (*(volatile int *)imp_alwaysfails != 0);
        }
    }
}
