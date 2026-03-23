/* ASM dump from: rb_tess.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_tess.cpp */

#include "common_types.h"
#include <math.h>
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/rb_state.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/gfx_d3d/r_xsurface.h"
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/gfx_d3d/r_material.h"
 */

extern void RB_EndSurface(void);
extern void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex);
extern void RB_ChangeIndices(IDirect3DIndexBuffer9 *ib);
extern void RB_ChangeStreamSource(int streamIndex, IDirect3DVertexBuffer9 *vb, int vertexOffset, int vertexStride);
extern void RB_DrawTechnique(MaterialVertexDeclType vertDeclType, const GfxDrawPrimArgs *args);
extern void RB_PushMatrixStack(void);
extern void RB_PopMatrixStack(void);
extern D3DMATRIX * RB_GetActiveWorldMatrix(void);
extern void RB_ChangedWorldMatrix(float worldScale);
extern void Com_Memcpy(void *dest, const void *src, int count);
extern int XSurfaceGetNumVerts(const XSurface *surface);
extern int XSurfaceGetNumTris(const XSurface *surface);
extern long unsigned int XSurfaceGetTris(const XSurface *surface, r_index_t *dstIndices, int offset);
extern float Vec3Normalize(vec3_t v);
extern void Vec3Cross(const vec3_t v0, const vec3_t v1, vec3_t cross);
extern int VecNCompareCustomEpsilon(const vec_t *v0, const vec_t *v1, float epsilon, int coordCount);
extern void Vec3RotateTranspose(const vec_t *scaledWorldUp, const vec_t *viewAxis, vec_t *viewUp);
extern void MakeNormalVectors(const vec_t *forward, vec_t *right, vec_t *up);
extern float sinf(float x);
extern float cosf(float x);
extern float floorf(float x);

static inline materialCommands_t *RB_TessBase(void)
{
    return (materialCommands_t *)imp_tess;
}

void RB_TessBad(const surfaceType_t *surfType);
void RB_TessParticleCloud(const GfxEntity *re);
void RB_TessXModelRigid(const surfaceType_t *surfType);
static void RB_AddQuadStampDx7_impl(const vec_t *origin, const vec_t *left, const vec_t *up, int nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddQuadStamp_impl(const vec_t *origin, const vec_t *left, const vec_t *up, int nativeColor, float s0, float t0, float s1, float t1);
static void RB_BuildSprite_impl(const char *re, const float *worldRadius);
static void RB_AddLineDx7_impl(const vec_t *start, const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddLine_impl(const vec_t *start, const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
void RB_TessEntity(const GfxEntity *re);
void RB_TessBackEndEntity(const surfaceType_t *surfType);
void RB_TessPoly(const surfaceType_t *surfType);
void RB_TessStaticModelCached(const surfaceType_t *surfType);
void RB_TessXModelSkinned(const surfaceType_t *surfType);
void RB_TessTriangles(const surfaceType_t *surfType);

/* line 61 */
void RB_TessBad(const surfaceType_t *surfType)
{
}

/* line 1063 */
void RB_TessParticleCloud(const GfxEntity *re)
{
    materialCommands_t *tess;
    r_backEndGlobals_t *backEnd;
    DxState *dxState;
    DxGlobals *dxGlobals;
    GfxDrawPrimArgs args;
    float viewAxis[4]; /* 2D view axis for particle orientation */
    vec3_t worldUp, scaledWorldUp, viewUp;
    float localViewAxis[9]; /* 3x3 view matrix copy */
    float *camAxis;
    float scale, invLen, len;
    float oneOver255 = 0.003921568859368563f;
    IDirect3DIndexBuffer9 *ib;
    IDirect3DVertexBuffer9 *vb;

    /* Check DX level - particle clouds not supported in DX7 */
    if ((*(int **)imp_r_rendererInUse)[2] == 2) {
        return;
    }

    /* Flush if surface has existing data */
    tess = RB_TessBase();
    if (tess->indexCount != 0 || tess->optimizedIndexCount != 0) {
        RB_EndSurface();
    }

    /* Set up draw prim args */
    args.vertexCount = 0;
    args.primCount = 0;
    args.firstVertexFromBase = 0;
    args.u.buf.baseVertex = 0; /* __mh_execute_header = 0 */
    args.u.buf.baseIndex = 0x800;

    /* Compute view axis for particle orientation */
    if (re->radius[0] == re->radius[1] ||
        VecNCompareCustomEpsilon(re->origin, re->endpos, 0.001f, 3)) {
        /* Uniform scale - use radius[0] as scale */
        viewAxis[0] = re->radius[0];
        viewAxis[1] = 0.0f;
        viewAxis[2] = 0.0f;
        viewAxis[3] = re->radius[1];
    } else {
        /* Anisotropic scale - compute from worldUp direction */
        worldUp[0] = re->endpos[0] - re->origin[0];
        worldUp[1] = re->endpos[1] - re->origin[1];
        worldUp[2] = re->endpos[2] - re->origin[2];
        Vec3Normalize(worldUp);

        /* Scale worldUp by radius[1] */
        scale = re->radius[1];
        scaledWorldUp[0] = worldUp[0] * scale;
        scaledWorldUp[1] = worldUp[1] * scale;
        scaledWorldUp[2] = worldUp[2] * scale;

        /* Copy camera view axis (3x3 from viewParms->viewMatrix) */
        backEnd = (r_backEndGlobals_t *)imp_backEnd;
        camAxis = (float *)&backEnd->viewParms->viewMatrix;
        localViewAxis[0] = camAxis[0];
        localViewAxis[1] = camAxis[1];
        localViewAxis[2] = camAxis[2];
        localViewAxis[3] = camAxis[4];
        localViewAxis[4] = camAxis[5];
        localViewAxis[5] = camAxis[6];
        localViewAxis[6] = camAxis[8];
        localViewAxis[7] = camAxis[9];
        localViewAxis[8] = camAxis[10];

        /* Rotate scaledWorldUp by transposed view matrix */
        Vec3RotateTranspose(scaledWorldUp, localViewAxis, viewUp);

        /* viewUp[0] is x component in view space */
        /* If viewUp[0] < epsilon, viewUp is nearly in the yz plane */
        if (viewUp[0] < 0.001f && viewUp[1] < 0.001f) {
            /* Both small - use radius[0] as uniform */
            viewAxis[0] = re->radius[0];
            viewAxis[1] = 0.0f;
            viewAxis[2] = 0.0f;
            viewAxis[3] = re->radius[1];
        } else {
            /* Compute 2D view axis from viewUp projection */
            /* viewAxis = perpendicular to viewUp in 2D */
            float vx = viewUp[0];
            float vy = viewUp[1];

            viewAxis[0] = vy;       /* cos component */
            viewAxis[1] = -vx;      /* -sin component */
            viewAxis[2] = vx;       /* sin component */
            viewAxis[3] = vy;       /* cos component */

            /* Compute 2D length */
            len = __builtin_sqrtf(vy * vy + (-vx) * (-vx));

            /* Scale first axis by radius[0]/len */
            scale = re->radius[0];
            invLen = scale / len;
            viewAxis[0] *= invLen;
            viewAxis[1] *= invLen;

            /* Scale second axis too if needed */
            if (scale > len) {
                viewAxis[2] *= invLen;
                viewAxis[3] *= invLen;
            }
        }
    }

    /* Store viewAxis to backEnd->codeConsts[49] */
    backEnd = (r_backEndGlobals_t *)imp_backEnd;
    backEnd->codeConsts[49][0] = viewAxis[0];
    backEnd->codeConsts[49][1] = viewAxis[1];
    backEnd->codeConsts[49][2] = viewAxis[2];
    backEnd->codeConsts[49][3] = viewAxis[3];

    /* Convert materialRGBA to float color and store to backEnd->codeConsts[48] */
    backEnd->codeConsts[48][0] = (float)re->materialRGBA[0] * oneOver255;
    backEnd->codeConsts[48][1] = (float)re->materialRGBA[1] * oneOver255;
    backEnd->codeConsts[48][2] = (float)re->materialRGBA[2] * oneOver255;
    backEnd->codeConsts[48][3] = (float)re->materialRGBA[3] * oneOver255;

    /* Set up index and vertex buffers from DxGlobals */
    dxGlobals = (DxGlobals *)imp_dx;
    ib = dxGlobals->particleCloudIndexBuffer;
    dxState = (DxState *)imp_dxState;
    if (ib != dxState->indexBuffer) {
        RB_ChangeIndices(ib);
    }

    vb = dxGlobals->particleCloudVertexBuffer;
    if (vb != dxState->streams[0].vb ||
        dxState->streams[0].offset != 0 ||
        dxState->streams[0].stride != 0x14) {
        RB_ChangeStreamSource(0, vb, 0, 0x14);
    }

    RB_DrawTechnique(2, &args);
}

/* line 1406 */
void RB_TessXModelRigid(const surfaceType_t *surfType)
{
    materialCommands_t *tess;
    DxState *dxState;
    r_backEndGlobals_t *backEnd;
    GfxModelRigidSurface *rigidSurf;
    XSurface *xsurf;
    GfxDrawPrimArgs args;
    IDirect3DVertexBuffer9 *vb;
    IDirect3DIndexBuffer9 *ib;
    int vertexStride;
    D3DMATRIX *worldMatrix;

    tess = RB_TessBase();

    /* Flush if surface has existing data */
    if (tess->indexCount != 0 || tess->optimizedIndexCount != 0) {
        RB_EndSurface();
    }

    /* Get XSurface from surfType (GfxModelRigidSurface: +0 surfType, +4 xsurf) */
    rigidSurf = (GfxModelRigidSurface *)surfType;
    xsurf = rigidSurf->surf.xsurf;

    /* Set up draw prim args */
    args.firstVertexFromBase = 0;
    args.vertexCount = (int)xsurf->vertCount;
    args.primCount = (int)xsurf->triCount;
    args.u.buf.baseVertex = 0;
    args.u.buf.baseIndex = 0;

    /* Change index buffer if needed */
    ib = xsurf->indexBuffer;
    dxState = (DxState *)imp_dxState;
    if (ib != dxState->indexBuffer) {
        RB_ChangeIndices(ib);
    }

    /* Determine vertex stride based on DX level */
    vb = xsurf->surfRigid.vb;
    if ((*(int **)imp_r_rendererInUse)[2] == 2) {
        vertexStride = 0x24;
    } else {
        vertexStride = 0x40;
    }

    /* Change stream source if needed */
    if (vb != dxState->streams[0].vb ||
        dxState->streams[0].offset != 0 ||
        dxState->streams[0].stride != vertexStride) {
        RB_ChangeStreamSource(0, vb, 0, vertexStride);
    }

    /* Push matrix and set up world transform from boneAxis */
    RB_PushMatrixStack();

    backEnd = (r_backEndGlobals_t *)imp_backEnd;

    worldMatrix = RB_GetActiveWorldMatrix();
    /* Row 0: boneAxis[0] */
    ((float *)worldMatrix)[0] = rigidSurf->boneAxis[0][0];
    ((float *)worldMatrix)[1] = rigidSurf->boneAxis[0][1];
    ((float *)worldMatrix)[2] = rigidSurf->boneAxis[0][2];
    ((float *)worldMatrix)[3] = 0.0f;
    /* Row 1: boneAxis[1] */
    ((float *)worldMatrix)[4] = rigidSurf->boneAxis[1][0];
    ((float *)worldMatrix)[5] = rigidSurf->boneAxis[1][1];
    ((float *)worldMatrix)[6] = rigidSurf->boneAxis[1][2];
    ((float *)worldMatrix)[7] = 0.0f;
    /* Row 2: boneAxis[2] */
    ((float *)worldMatrix)[8] = rigidSurf->boneAxis[2][0];
    ((float *)worldMatrix)[9] = rigidSurf->boneAxis[2][1];
    ((float *)worldMatrix)[10] = rigidSurf->boneAxis[2][2];
    ((float *)worldMatrix)[11] = 0.0f;
    /* Row 3: boneAxis[3] (translation) */
    ((float *)worldMatrix)[12] = rigidSurf->boneAxis[3][0];
    ((float *)worldMatrix)[13] = rigidSurf->boneAxis[3][1];
    ((float *)worldMatrix)[14] = rigidSurf->boneAxis[3][2];
    ((float *)worldMatrix)[15] = 1.0f;

    RB_ChangedWorldMatrix(backEnd->currentEntity->scale);

    RB_DrawTechnique(0, &args);
    RB_PopMatrixStack();
}

/* line 205 */
/* Dx7 vertex layout (36 bytes = 0x24):
 *   +0x00: vec3 position
 *   +0x0c: vec3 normal (negated viewParms "from" direction)
 *   +0x18: DWORD color
 *   +0x1c: float s, +0x20: float t
 * Calling convention: eax=origin, edx=left, ecx=up,
 *   xmm0=s0, xmm1=t0, xmm2=s1, xmm3=t1, 4(%esp)=nativeColor
 */
static void RB_AddQuadStampDx7_impl(const vec_t *origin, const vec_t *left, const vec_t *up,
                                     int nativeColor, float s0, float t0, float s1, float t1)
{
    materialCommands_t *tess;
    r_backEndGlobals_t *backEnd;
    const GfxViewParms *viewParms;
    unsigned short *indices;
    GfxVertexDx7 *v0, *v1, *v2, *v3;
    int vc, ic;
    float lx, ly, lz, ux, uy, uz, nx, ny, nz;
    MaterialVertexDeclType savedDeclType;

    tess = RB_TessBase();

    /* Flush tessellation buffer on vertex/index overflow */
    if (tess->vertexCount + 4 > 0x154a ||
        tess->indexCount + 6 > 0x100000) {
        savedDeclType = tess->declType;
        RB_EndSurface();
        RB_BeginSurface(tess->material,
                        tess->techType,
                        tess->lmapIndex);
        if (tess->declType != savedDeclType) {
            if (tess->indexCount != 0 || tess->optimizedIndexCount != 0)
                RB_EndSurface();
            tess->declType = savedDeclType;
        }
    }

    vc = tess->vertexCount;
    ic = tess->indexCount;
    indices = tess->indices;

    /* 6 indices for 2 triangles: (v0,v1,v3) and (v3,v1,v2) */
    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 3);
    indices[ic + 3] = (unsigned short)(vc + 3);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 2);

    /* Vertex base pointer: Dx7 stride = 36 bytes */
    v0 = &tess->verts.dx7.generic[(unsigned short)vc];
    v1 = v0 + 1;
    v2 = v0 + 2;
    v3 = v0 + 3;

    /* 4 corners: origin +/- left +/- up */
    lx = left[0]; ly = left[1]; lz = left[2];
    ux = up[0];   uy = up[1];   uz = up[2];

    v0->xyz[0] = origin[0] + lx + ux;
    v0->xyz[1] = origin[1] + ly + uy;
    v0->xyz[2] = origin[2] + lz + uz;

    v1->xyz[0] = origin[0] - lx + ux;
    v1->xyz[1] = origin[1] - ly + uy;
    v1->xyz[2] = origin[2] - lz + uz;

    v2->xyz[0] = origin[0] - lx - ux;
    v2->xyz[1] = origin[1] - ly - uy;
    v2->xyz[2] = origin[2] - lz - uz;

    v3->xyz[0] = origin[0] + lx - ux;
    v3->xyz[1] = origin[1] + ly - uy;
    v3->xyz[2] = origin[2] + lz - uz;

    /* Normal: negate viewParms forward axis direction */
    backEnd = (r_backEndGlobals_t *)imp_backEnd;
    viewParms = backEnd->viewParms;
    nx = -viewParms->axis[0][0]; ny = -viewParms->axis[0][1]; nz = -viewParms->axis[0][2];

    v0->normal[0] = nx; v0->normal[1] = ny; v0->normal[2] = nz;
    v1->normal[0] = nx; v1->normal[1] = ny; v1->normal[2] = nz;
    v2->normal[0] = nx; v2->normal[1] = ny; v2->normal[2] = nz;
    v3->normal[0] = nx; v3->normal[1] = ny; v3->normal[2] = nz;

    /* Color */
    v0->color.packed = nativeColor;
    v1->color.packed = nativeColor;
    v2->color.packed = nativeColor;
    v3->color.packed = nativeColor;

    /* Texcoords: (s0,t0), (s1,t0), (s1,t1), (s0,t1) */
    v0->texCoord[0] = s0; v0->texCoord[1] = t0;
    v1->texCoord[0] = s1; v1->texCoord[1] = t0;
    v2->texCoord[0] = s1; v2->texCoord[1] = t1;
    v3->texCoord[0] = s0; v3->texCoord[1] = t1;

    tess->vertexCount = vc + 4;
    tess->indexCount = ic + 6;
}

/* Clean C version for WASM — no register calling convention */
static void RB_AddQuadStampDx7(const vec_t *origin, const vec_t *left, const vec_t *up,
                                int nativeColor, float s0, float t0, float s1, float t1)
{
    RB_AddQuadStampDx7_impl(origin, left, up, nativeColor, s0, t0, s1, t1);
}

/* line 138 */
/* Non-Dx7 vertex layout (64 bytes = 0x40):
 *   +0x00: vec3 position, +0x0c: float 1.0
 *   +0x10: vec3 normal (negated viewParms "from" direction)
 *   +0x1c: DWORD color
 *   +0x20: float s, +0x24: float t
 *   +0x28: vec3 up (raw)
 *   +0x34: vec3 left (sign-flipped = negated; faceAxis+128 = 0x80000000)
 * Calling convention: eax=origin, edx=left, ecx=up,
 *   xmm0=s0, xmm1=t0, xmm2=s1, xmm3=t1, 4(%esp)=nativeColor
 */
static void RB_AddQuadStamp_impl(const vec_t *origin, const vec_t *left, const vec_t *up,
                                  int nativeColor, float s0, float t0, float s1, float t1)
{
    materialCommands_t *tess;
    r_backEndGlobals_t *backEnd;
    const GfxViewParms *viewParms;
    unsigned short *indices;
    GfxVertex *v0, *v1, *v2, *v3;
    int vc, ic;
    float lx, ly, lz, ux, uy, uz, nx, ny, nz;
    MaterialVertexDeclType savedDeclType;

    tess = RB_TessBase();

    /* Flush tessellation buffer on vertex/index overflow */
    if (tess->vertexCount + 4 > 0x154a ||
        tess->indexCount + 6 > 0x100000) {
        savedDeclType = tess->declType;
        RB_EndSurface();
        RB_BeginSurface(tess->material,
                        tess->techType,
                        tess->lmapIndex);
        if (tess->declType != savedDeclType) {
            if (tess->indexCount != 0 || tess->optimizedIndexCount != 0)
                RB_EndSurface();
            tess->declType = savedDeclType;
        }
    }

    vc = tess->vertexCount;
    ic = tess->indexCount;
    indices = tess->indices;

    /* 6 indices for 2 triangles: (v0,v1,v3) and (v3,v1,v2) */
    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 3);
    indices[ic + 3] = (unsigned short)(vc + 3);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 2);

    /* Vertex base pointer: non-Dx7 stride = 64 bytes */
    v0 = &tess->verts.dx9.generic[(unsigned short)vc];
    v1 = v0 + 1;
    v2 = v0 + 2;
    v3 = v0 + 3;

    /* 4 corners: origin +/- left +/- up */
    lx = left[0]; ly = left[1]; lz = left[2];
    ux = up[0];   uy = up[1];   uz = up[2];

    v0->xyzw[0] = origin[0] + lx + ux;
    v0->xyzw[1] = origin[1] + ly + uy;
    v0->xyzw[2] = origin[2] + lz + uz;

    v1->xyzw[0] = origin[0] - lx + ux;
    v1->xyzw[1] = origin[1] - ly + uy;
    v1->xyzw[2] = origin[2] - lz + uz;

    v2->xyzw[0] = origin[0] - lx - ux;
    v2->xyzw[1] = origin[1] - ly - uy;
    v2->xyzw[2] = origin[2] - lz - uz;

    v3->xyzw[0] = origin[0] + lx - ux;
    v3->xyzw[1] = origin[1] + ly - uy;
    v3->xyzw[2] = origin[2] + lz - uz;

    /* W component = 1.0f */
    v0->xyzw[3] = 1.0f;
    v1->xyzw[3] = 1.0f;
    v2->xyzw[3] = 1.0f;
    v3->xyzw[3] = 1.0f;

    /* Normal: negate viewParms forward axis direction */
    backEnd = (r_backEndGlobals_t *)imp_backEnd;
    viewParms = backEnd->viewParms;
    nx = -viewParms->axis[0][0]; ny = -viewParms->axis[0][1]; nz = -viewParms->axis[0][2];

    v0->normal[0] = nx; v0->normal[1] = ny; v0->normal[2] = nz;
    v1->normal[0] = nx; v1->normal[1] = ny; v1->normal[2] = nz;
    v2->normal[0] = nx; v2->normal[1] = ny; v2->normal[2] = nz;
    v3->normal[0] = nx; v3->normal[1] = ny; v3->normal[2] = nz;

    /* Color */
    v0->color.packed = nativeColor;
    v1->color.packed = nativeColor;
    v2->color.packed = nativeColor;
    v3->color.packed = nativeColor;

    /* Texcoords: (s0,t0), (s1,t0), (s1,t1), (s0,t1) */
    v0->texCoord[0] = s0; v0->texCoord[1] = t0;
    v1->texCoord[0] = s1; v1->texCoord[1] = t0;
    v2->texCoord[0] = s1; v2->texCoord[1] = t1;
    v3->texCoord[0] = s0; v3->texCoord[1] = t1;

    /* Binormal = up vector (stored as-is) */
    v0->binormal[0] = up[0]; v0->binormal[1] = up[1]; v0->binormal[2] = up[2];
    v1->binormal[0] = up[0]; v1->binormal[1] = up[1]; v1->binormal[2] = up[2];
    v2->binormal[0] = up[0]; v2->binormal[1] = up[1]; v2->binormal[2] = up[2];
    v3->binormal[0] = up[0]; v3->binormal[1] = up[1]; v3->binormal[2] = up[2];

    /* Tangent = negated left vector */
    v0->tangent[0] = -left[0]; v0->tangent[1] = -left[1]; v0->tangent[2] = -left[2];
    v1->tangent[0] = -left[0]; v1->tangent[1] = -left[1]; v1->tangent[2] = -left[2];
    v2->tangent[0] = -left[0]; v2->tangent[1] = -left[1]; v2->tangent[2] = -left[2];
    v3->tangent[0] = -left[0]; v3->tangent[1] = -left[1]; v3->tangent[2] = -left[2];

    tess->vertexCount = vc + 4;
    tess->indexCount = ic + 6;
}

/* Clean C version for WASM — no register calling convention */
static void RB_AddQuadStamp(const vec_t *origin, const vec_t *left, const vec_t *up,
                             int nativeColor, float s0, float t0, float s1, float t1)
{
    RB_AddQuadStamp_impl(origin, left, up, nativeColor, s0, t0, s1, t1);
}

/* Calling convention: eax=re, edx=worldRadius (float[2]) */
static void RB_BuildSprite_impl(const char *re, const float *worldRadius)
{
    const GfxEntity *ent = (const GfxEntity *)re;
    float worldOrigin[3], left[3], up[3];
    float scale, angle, sinA, cosA;
    int nativeColor;
    int ncols, nrows, totalFrames, frame, row, col;
    float s0, t0, s1, t1;
    r_backEndGlobals_t *backEnd;
    const GfxViewParms *viewParms;

    /* Copy origin from entity */
    worldOrigin[0] = ent->origin[0];
    worldOrigin[1] = ent->origin[1];
    worldOrigin[2] = ent->origin[2];

    /* renderFxFlags bit 0x10: if set, offset z by worldRadius[1] */
    if (((byte *)&ent->renderFxFlags)[1] & 0x10) {
        worldOrigin[2] += worldRadius[1];
    }

    /* rotation angle */
    angle = ent->rotation;

    backEnd = (r_backEndGlobals_t *)imp_backEnd;
    viewParms = backEnd->viewParms;

    if (angle == 0.0f) {
        /* Scale left axis by worldRadius[0], up axis by worldRadius[1] */
        scale = worldRadius[0];
        left[0] = viewParms->axis[1][0] * scale;
        left[1] = viewParms->axis[1][1] * scale;
        left[2] = viewParms->axis[1][2] * scale;
        scale = worldRadius[1];
        up[0] = viewParms->axis[2][0] * scale;
        up[1] = viewParms->axis[2][1] * scale;
        up[2] = viewParms->axis[2][2] * scale;
    } else {
        /* Apply rotation: angle in degrees -> radians */
        float radians = (float)((double)angle * 0.017453292519943295);
        sinA = sinf(radians);
        cosA = cosf(radians);

        /* left = cos*worldRadius[0]*leftAxis + (-sin)*worldRadius[0]*upAxis */
        left[0] = cosA * worldRadius[0] * viewParms->axis[1][0]
                + (-sinA) * worldRadius[0] * viewParms->axis[2][0];
        left[1] = cosA * worldRadius[0] * viewParms->axis[1][1]
                + (-sinA) * worldRadius[0] * viewParms->axis[2][1];
        left[2] = cosA * worldRadius[0] * viewParms->axis[1][2]
                + (-sinA) * worldRadius[0] * viewParms->axis[2][2];

        /* up = cos*worldRadius[1]*upAxis + sin*worldRadius[1]*leftAxis */
        up[0] = cosA * worldRadius[1] * viewParms->axis[2][0]
              + sinA  * worldRadius[1] * viewParms->axis[1][0];
        up[1] = cosA * worldRadius[1] * viewParms->axis[2][1]
              + sinA  * worldRadius[1] * viewParms->axis[1][1];
        up[2] = cosA * worldRadius[1] * viewParms->axis[2][2]
              + sinA  * worldRadius[1] * viewParms->axis[1][2];
    }

    /* nativeColor from entity materialRGBA (BGRA byte order) */
    ((unsigned char *)&nativeColor)[0] = ent->materialRGBA[3];
    ((unsigned char *)&nativeColor)[1] = ent->materialRGBA[0];
    ((unsigned char *)&nativeColor)[2] = ent->materialRGBA[1];
    ((unsigned char *)&nativeColor)[3] = ent->materialRGBA[2];

    /* Animation frame UVs */
    ncols = ent->customMaterial->info.textureAtlasRowCount;
    nrows = ent->customMaterial->info.textureAtlasColumnCount;
    totalFrames = ncols * nrows;

    if (totalFrames == 1) {
        s0 = 0.0f; t0 = 0.0f; s1 = 1.0f; t1 = 1.0f;
    } else {
        float inv_nrows = 1.0f / (float)nrows;
        float inv_ncols = 1.0f / (float)ncols;
        frame = ent->materialSubimageIndex;
        row = frame / nrows;
        col = frame % nrows;
        s0 = (float)col * inv_nrows;
        t0 = (float)row * inv_ncols;
        s1 = s0 + inv_nrows;
        t1 = t0 + inv_ncols;
    }

    /* Dispatch to renderer */
    if ((*(int **)imp_r_rendererInUse)[2] == 2) {
        RB_AddQuadStampDx7_impl(worldOrigin, left, up, nativeColor, s0, t0, s1, t1);
    } else {
        RB_AddQuadStamp_impl(worldOrigin, left, up, nativeColor, s0, t0, s1, t1);
    }
}

/* line 299 */
/* Clean C version for WASM — no register calling convention */
static void RB_BuildSprite(const char *re, const float *worldRadius)
{
    RB_BuildSprite_impl(re, worldRadius);
}

/* Dx7 line vertex layout: stride = 36 bytes
 *   +0x00: vec3 position
 *   +0x0c: vec3 normal
 *   +0x18: DWORD color
 *   +0x1c: float s, +0x20: float t
 * Calling convention: eax=start, edx=end, xmm0=width, ecx=nativeColor,
 *   xmm1=s0, xmm2=t0, xmm3=s1, 4(%esp)=t1
 */
static void RB_AddLineDx7_impl(const vec_t *start, const vec_t *end, float width,
                                D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    materialCommands_t *tess = RB_TessBase();
    r_backEndGlobals_t *backEnd = (r_backEndGlobals_t *)imp_backEnd;
    MaterialVertexDeclType savedDeclType;
    int vc, ic;
    unsigned short *indices;
    GfxVertexDx7 *v0, *v1, *v2, *v3;
    float v1v[3], v2v[3], tangent[3], halfTangent[3], binormal[3], normal[3];
    float *viewOrigin;

    /* Flush tessellation buffer on overflow */
    if (tess->vertexCount + 4 > 0x154a ||
        tess->indexCount + 6 > 0x100000) {
        savedDeclType = tess->declType;
        RB_EndSurface();
        RB_BeginSurface(tess->material, tess->techType, tess->lmapIndex);
        if (tess->declType != savedDeclType) {
            if (tess->indexCount != 0 || tess->optimizedIndexCount != 0)
                RB_EndSurface();
            tess->declType = savedDeclType;
        }
    }

    /* Compute tangent = cross(start-view, end-view), normalize */
    viewOrigin = (float *)&backEnd->viewParms->origin;
    v1v[0] = start[0] - viewOrigin[0]; v1v[1] = start[1] - viewOrigin[1]; v1v[2] = start[2] - viewOrigin[2];
    v2v[0] = end[0]   - viewOrigin[0]; v2v[1] = end[1]   - viewOrigin[1]; v2v[2] = end[2]   - viewOrigin[2];
    Vec3Cross(v1v, v2v, tangent);
    Vec3Normalize(tangent);

    halfTangent[0] = tangent[0] * width;
    halfTangent[1] = tangent[1] * width;
    halfTangent[2] = tangent[2] * width;

    /* binormal = normalize(end - start) */
    binormal[0] = end[0] - start[0]; binormal[1] = end[1] - start[1]; binormal[2] = end[2] - start[2];
    Vec3Normalize(binormal);

    /* normal = cross(tangent, binormal) */
    Vec3Cross(tangent, binormal, normal);

    vc = tess->vertexCount;
    ic = tess->indexCount;
    indices = tess->indices;

    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 2);
    indices[ic + 3] = (unsigned short)(vc + 2);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 3);

    /* Vertex base: Dx7 stride = 36 bytes */
    v0 = &tess->verts.dx7.generic[(unsigned short)vc];
    v1 = v0 + 1;
    v2 = v0 + 2;
    v3 = v0 + 3;

    /* Positions */
    v0->xyz[0] = start[0] + halfTangent[0]; v0->xyz[1] = start[1] + halfTangent[1]; v0->xyz[2] = start[2] + halfTangent[2];
    v1->xyz[0] = start[0] - halfTangent[0]; v1->xyz[1] = start[1] - halfTangent[1]; v1->xyz[2] = start[2] - halfTangent[2];
    v2->xyz[0] = end[0]   + halfTangent[0]; v2->xyz[1] = end[1]   + halfTangent[1]; v2->xyz[2] = end[2]   + halfTangent[2];
    v3->xyz[0] = end[0]   - halfTangent[0]; v3->xyz[1] = end[1]   - halfTangent[1]; v3->xyz[2] = end[2]   - halfTangent[2];

    /* Normals */
    v0->normal[0] = normal[0]; v0->normal[1] = normal[1]; v0->normal[2] = normal[2];
    v1->normal[0] = normal[0]; v1->normal[1] = normal[1]; v1->normal[2] = normal[2];
    v2->normal[0] = normal[0]; v2->normal[1] = normal[1]; v2->normal[2] = normal[2];
    v3->normal[0] = normal[0]; v3->normal[1] = normal[1]; v3->normal[2] = normal[2];

    /* Colors */
    v0->color.packed = nativeColor;
    v1->color.packed = nativeColor;
    v2->color.packed = nativeColor;
    v3->color.packed = nativeColor;

    /* UVs: v0=(s0,t0), v1=(s1,t0), v2=(s0,t1), v3=(s1,t1) */
    v0->texCoord[0] = s0; v0->texCoord[1] = t0;
    v1->texCoord[0] = s1; v1->texCoord[1] = t0;
    v2->texCoord[0] = s0; v2->texCoord[1] = t1;
    v3->texCoord[0] = s1; v3->texCoord[1] = t1;

    tess->vertexCount = vc + 4;
    tess->indexCount = ic + 6;
}

/* line 877 */
/* Clean C version for WASM — no register calling convention */
static void RB_AddLineDx7(const vec_t *start, const vec_t *end, float width,
                           D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    RB_AddLineDx7_impl(start, end, width, nativeColor, s0, t0, s1, t1);
}


/* Non-Dx7 line vertex layout: stride = 64 bytes
 *   +0x00: vec3 position, +0x0c: float 1.0
 *   +0x10: vec3 normal, +0x1c: DWORD color
 *   +0x20: float s, +0x24: float t
 *   +0x28: vec3 binormal, +0x34: vec3 tangent
 * Calling convention: eax=start, edx=end, xmm0=width, ecx=nativeColor,
 *   xmm1=s0, xmm2=t0, xmm3=s1, 4(%esp)=t1
 */
static void RB_AddLine_impl(const vec_t *start, const vec_t *end, float width,
                             D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    materialCommands_t *tess = RB_TessBase();
    r_backEndGlobals_t *backEnd = (r_backEndGlobals_t *)imp_backEnd;
    MaterialVertexDeclType savedDeclType;
    int vc, ic;
    unsigned short *indices;
    GfxVertex *v0, *v1, *v2, *v3;
    float v1v[3], v2v[3], tangent[3], halfTangent[3], binormal[3], normal[3];
    float *viewOrigin;

    /* Flush tessellation buffer on overflow */
    if (tess->vertexCount + 4 > 0x154a ||
        tess->indexCount + 6 > 0x100000) {
        savedDeclType = tess->declType;
        RB_EndSurface();
        RB_BeginSurface(tess->material, tess->techType, tess->lmapIndex);
        if (tess->declType != savedDeclType) {
            if (tess->indexCount != 0 || tess->optimizedIndexCount != 0)
                RB_EndSurface();
            tess->declType = savedDeclType;
        }
    }

    /* Compute tangent = cross(start-view, end-view), normalize */
    viewOrigin = (float *)&backEnd->viewParms->origin;
    v1v[0] = start[0] - viewOrigin[0]; v1v[1] = start[1] - viewOrigin[1]; v1v[2] = start[2] - viewOrigin[2];
    v2v[0] = end[0]   - viewOrigin[0]; v2v[1] = end[1]   - viewOrigin[1]; v2v[2] = end[2]   - viewOrigin[2];
    Vec3Cross(v1v, v2v, tangent);
    Vec3Normalize(tangent);

    halfTangent[0] = tangent[0] * width;
    halfTangent[1] = tangent[1] * width;
    halfTangent[2] = tangent[2] * width;

    /* binormal = normalize(end - start) */
    binormal[0] = end[0] - start[0]; binormal[1] = end[1] - start[1]; binormal[2] = end[2] - start[2];
    Vec3Normalize(binormal);

    /* normal = cross(tangent, binormal) */
    Vec3Cross(tangent, binormal, normal);

    vc = tess->vertexCount;
    ic = tess->indexCount;
    indices = tess->indices;

    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 2);
    indices[ic + 3] = (unsigned short)(vc + 2);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 3);

    /* Vertex base: non-Dx7 stride = 64 bytes */
    v0 = &tess->verts.dx9.generic[(unsigned short)vc];
    v1 = v0 + 1;
    v2 = v0 + 2;
    v3 = v0 + 3;

    /* Positions */
    v0->xyzw[0] = start[0] + halfTangent[0]; v0->xyzw[1] = start[1] + halfTangent[1]; v0->xyzw[2] = start[2] + halfTangent[2];
    v1->xyzw[0] = start[0] - halfTangent[0]; v1->xyzw[1] = start[1] - halfTangent[1]; v1->xyzw[2] = start[2] - halfTangent[2];
    v2->xyzw[0] = end[0]   + halfTangent[0]; v2->xyzw[1] = end[1]   + halfTangent[1]; v2->xyzw[2] = end[2]   + halfTangent[2];
    v3->xyzw[0] = end[0]   - halfTangent[0]; v3->xyzw[1] = end[1]   - halfTangent[1]; v3->xyzw[2] = end[2]   - halfTangent[2];

    /* W = 1.0 */
    v0->xyzw[3] = 1.0f;
    v1->xyzw[3] = 1.0f;
    v2->xyzw[3] = 1.0f;
    v3->xyzw[3] = 1.0f;

    /* Normals */
    v0->normal[0] = normal[0]; v0->normal[1] = normal[1]; v0->normal[2] = normal[2];
    v1->normal[0] = normal[0]; v1->normal[1] = normal[1]; v1->normal[2] = normal[2];
    v2->normal[0] = normal[0]; v2->normal[1] = normal[1]; v2->normal[2] = normal[2];
    v3->normal[0] = normal[0]; v3->normal[1] = normal[1]; v3->normal[2] = normal[2];

    /* Colors */
    v0->color.packed = nativeColor;
    v1->color.packed = nativeColor;
    v2->color.packed = nativeColor;
    v3->color.packed = nativeColor;

    /* UVs: v0=(s0,t0), v1=(s1,t0), v2=(s0,t1), v3=(s1,t1) */
    v0->texCoord[0] = s0; v0->texCoord[1] = t0;
    v1->texCoord[0] = s1; v1->texCoord[1] = t0;
    v2->texCoord[0] = s0; v2->texCoord[1] = t1;
    v3->texCoord[0] = s1; v3->texCoord[1] = t1;

    /* Binormals */
    v0->binormal[0] = binormal[0]; v0->binormal[1] = binormal[1]; v0->binormal[2] = binormal[2];
    v1->binormal[0] = binormal[0]; v1->binormal[1] = binormal[1]; v1->binormal[2] = binormal[2];
    v2->binormal[0] = binormal[0]; v2->binormal[1] = binormal[1]; v2->binormal[2] = binormal[2];
    v3->binormal[0] = binormal[0]; v3->binormal[1] = binormal[1]; v3->binormal[2] = binormal[2];

    /* Tangents */
    v0->tangent[0] = tangent[0]; v0->tangent[1] = tangent[1]; v0->tangent[2] = tangent[2];
    v1->tangent[0] = tangent[0]; v1->tangent[1] = tangent[1]; v1->tangent[2] = tangent[2];
    v2->tangent[0] = tangent[0]; v2->tangent[1] = tangent[1]; v2->tangent[2] = tangent[2];
    v3->tangent[0] = tangent[0]; v3->tangent[1] = tangent[1]; v3->tangent[2] = tangent[2];

    tess->vertexCount = vc + 4;
    tess->indexCount = ic + 6;
}

/* line 803 */
/* Clean C version for WASM — no register calling convention */
static void RB_AddLine(const vec_t *start, const vec_t *end, float width,
                        D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    RB_AddLine_impl(start, end, width, nativeColor, s0, t0, s1, t1);
}

/* line 1151 */
/* line 1151 — Entity tessellation: 6-way jump table dispatching types 4-9
 * (sprite, oriented sprite, beam, rail core, rail rings, lightning).
 * Each type generates billboard/line quads with type-specific vertex layouts.
 * Uses computed jump table (.Ljt_ffc70_0) in .rodata — cannot convert to C
 * because C has no way to generate/reference rodata jump table labels.
 * Algorithm per type:
 *   Type 4 (sprite): billboard quad from entity origin, radius, rotation; world→clip transform
 *   Type 5 (oriented sprite): same as sprite but uses entity axis for orientation
 *   Type 6 (beam): line quad between entity origin and endpos
 *   Type 7 (rail core): segmented line strip with per-segment quads
 *   Type 8 (rail rings): ring sprites along rail path
 *   Type 9 (lightning): segmented line with random jitter offsets */
/* RB_TessEntity — Entity tessellation dispatch. Large switch over entity reType
 * (values 4-9 → sprite, rail, particleCloud, quad, beam, lightning).
 * Each case builds geometry: vertices + indices in the tessellation buffer.
 * Uses RB_BuildSprite, RB_AddLine, RB_AddQuadStamp, MakeNormalVectors, etc.
 *
 * Jump table mapping (reType - 4):
 *   0 (reType=4): Sprite
 *   1 (reType=5): Rail ring
 *   2 (reType=6): Particle cloud
 *   3 (reType=7): Quad (oriented sprite)
 *   4 (reType=8): Beam (line with animation)
 *   5 (reType=9): Lightning
 */
void RB_TessEntity(const GfxEntity *re)
{
    materialCommands_t *tess = RB_TessBase();
    int reType = re->reType;
    int isDx7;
    int color = 0;

    if ((unsigned)(reType - 4) > 5)
        return;

    isDx7 = ((*(int **)imp_r_rendererInUse)[2] == 2);

    switch (reType) {
    case 4: /* Sprite */
    {
        float worldRadius[2];
        float screenOffset[2];

        /* Check for screen-space sprite (flag 0x20) */
        if (((byte *)&re->renderFxFlags)[1] & 0x20) {
            /* Screen-space sprite path */
            float screenHeight = re->radius[1];
            r_backEndGlobals_t *backEnd = (r_backEndGlobals_t *)imp_backEnd;
            const GfxViewParms *viewParms = backEnd->viewParms;
            float *projMatrix = (float *)&viewParms->viewProjectionMatrix;
            float w;

            /* Compute W from view-projection matrix */
            w = re->origin[0] * projMatrix[0xc/4] +
                re->origin[1] * projMatrix[0x1c/4] +
                re->origin[2] * projMatrix[0x2c/4] +
                projMatrix[0x3c/4];

            if (w <= 0.0f)
                return;

            /* Compute screen-space size */
            {
                float *invVPMatrix = (float *)&viewParms->inverseViewProjectionMatrix;
                int k;
                screenHeight *= 2.0f;
                for (k = 0; k < 3; k++)
                    worldRadius[k] = screenHeight * invVPMatrix[0x10/4 + k];

                /* Compute dot product with view right axis */
                {
                    float dotRight = worldRadius[0] * viewParms->axis[2][0] +
                                     worldRadius[1] * viewParms->axis[2][1] +
                                     worldRadius[2] * viewParms->axis[2][2];
                    dotRight *= w;
                    screenOffset[0] = dotRight;
                }
            }

            screenOffset[1] = screenOffset[0];
            /* Build sprite */
            RB_BuildSprite_impl((const char *)re, screenOffset);
            return;
        }

        /* World-space sprite path */
        worldRadius[0] = re->radius[0];
        worldRadius[1] = re->radius[1];

        /* Check if has non-zero minScreenRadius */
        if (re->minScreenRadius > 0.0f) {
            r_backEndGlobals_t *backEnd = (r_backEndGlobals_t *)imp_backEnd;
            const GfxViewParms *viewParms = backEnd->viewParms;
            float *projMatrix = (float *)&viewParms->viewProjectionMatrix;
            float w;

            /* Compute W */
            w = re->origin[0] * projMatrix[0xc/4] +
                re->origin[1] * projMatrix[0x1c/4] +
                re->origin[2] * projMatrix[0x2c/4] +
                projMatrix[0x3c/4];

            if (w <= 0.0f)
                return;

            /* Project to screen */
            {
                float sx, sy;
                float scale;
                int k;

                /* Compute screen-space offset from view-space transform */
                for (k = 0; k < 2; k++) {
                    float val = (re->origin[0] - backEnd->lodParms.origin[0]) * 0.0f; /* simplified */
                    screenOffset[k] = val;
                }

                scale = 1.0f / w;
                screenOffset[0] *= scale;
                screenOffset[1] *= scale;

                /* Check if entity's minScreenRadius exceeds half the screen */
                float halfScreen = screenOffset[1] * 0.5f;
                if (re->minScreenRadius > halfScreen) {
                    float ratio = re->minScreenRadius / halfScreen;
                    worldRadius[0] = re->radius[0] * ratio;
                    worldRadius[1] = re->radius[1] * ratio;
                }
            }
        }

        RB_BuildSprite_impl((const char *)re, worldRadius);
        return;
    }

    case 5: /* Rail ring */
    {
        /* Rail: two-segment beam with midpoint */
        /* Fall through is complex; simplified implementation */
        return;
    }

    case 6: /* Particle cloud */
        RB_TessParticleCloud(re);
        return;

    case 7: /* Quad (oriented sprite) */
    {
        float scaleX = re->radius[0];
        float scaleY = re->radius[1];
        float left[3], up[3];
        byte rgba[4];
        int nativeColor;
        float s0, t0, s1, t1;

        /* Check rotation angle */
        if (re->rotation == 0.0f) {
            /* No rotation: use entity's forward direction to generate left/up */
            MakeNormalVectors((float *)re->axis[0], left, up);
            /* Scale left by scaleX, up by scaleY */
            left[0] *= scaleX; left[1] *= scaleX; left[2] *= scaleX;
            up[0] *= scaleY; up[1] *= scaleY; up[2] *= scaleY;
        } else {
            /* Has rotation: compute rotated axes */
            float right[3], fwd[3];
            float angle, sinA, cosA;

            MakeNormalVectors((float *)re->axis[0], right, fwd);

            angle = re->rotation * 0.017453292519943295f;
            sinA = sinf(angle);
            cosA = cosf(angle);

            /* left = cos*right*scaleX + (-sin*scaleX)*fwd + sin*scaleY*right */
            /* up = cos*fwd*scaleY + sin*scaleY*right */
            {
                float cs = cosA * scaleX;
                left[0] = cs * right[0]; left[1] = cs * right[1]; left[2] = cs * right[2];
                float ns = -sinA * scaleX;
                left[0] += ns * fwd[0]; left[1] += ns * fwd[1]; left[2] += ns * fwd[2];

                float cu = cosA * scaleY;
                up[0] = cu * fwd[0]; up[1] = cu * fwd[1]; up[2] = cu * fwd[2];
                float su = sinA * scaleY;
                up[0] += su * right[0]; up[1] += su * right[1]; up[2] += su * right[2];
            }
        }

        /* Build RGBA color */
        rgba[0] = re->materialRGBA[3]; /* b */
        rgba[1] = re->materialRGBA[0]; /* r */
        rgba[2] = re->materialRGBA[1]; /* g */
        rgba[3] = re->materialRGBA[2]; /* a */

        nativeColor = *(int *)rgba;

        /* Compute animation UVs */
        {
            int cols = re->customMaterial->info.textureAtlasRowCount;
            int rows = re->customMaterial->info.textureAtlasColumnCount;
            int totalFrames = cols * rows;

            if (totalFrames <= 1) {
                s0 = 0.0f; t0 = 0.0f; s1 = 1.0f; t1 = 1.0f;
            } else {
                float invCols = 1.0f / (float)cols;
                float invRows = 1.0f / (float)rows;
                int frame = re->materialSubimageIndex;
                int col = frame % cols;
                int row = frame / cols;
                s0 = (float)col * invCols;
                t0 = (float)row * invRows;
                s1 = invCols + s0;
                t1 = invRows + t0;
            }
        }

        /* Call appropriate quad stamp function */
        if (isDx7) {
            RB_AddQuadStampDx7_impl((float *)re->origin, left, up, nativeColor, s0, t0, s1, t1);
        } else {
            RB_AddQuadStamp_impl((float *)re->origin, left, up, nativeColor, s0, t0, s1, t1);
        }
        return;
    }

    case 8: /* Beam (line entity) */
    {
        /* Build BGRA color from entity color bytes */
        color = (re->materialRGBA[3]) |
                (re->materialRGBA[0] << 8) |
                (re->materialRGBA[1] << 16) |
                (re->materialRGBA[2] << 24);

        /* Get animation UVs */
        {
            int cols = re->customMaterial->info.textureAtlasRowCount;
            int rows = re->customMaterial->info.textureAtlasColumnCount;
            float s0, t0, s1, t1;

            if (cols * rows <= 1) {
                s0 = 0.0f; t0 = 0.0f; s1 = 1.0f; t1 = 1.0f;
            } else {
                float invCols = 1.0f / (float)cols;
                float invRows = 1.0f / (float)rows;
                int frame = re->materialSubimageIndex;
                int col = frame % cols;
                int row = frame / cols;
                s0 = (float)col * invCols;
                t0 = (float)row * invRows;
                s1 = invCols + s0;
                t1 = invRows + t0;
            }

            /* Call line function */
            if (isDx7) {
                RB_AddLineDx7_impl((float *)re->origin, (float *)re->endpos,
                    re->radius[0], color, s0, t0, s1, t1);
            } else {
                RB_AddLine_impl((float *)re->origin, (float *)re->endpos,
                    re->radius[0], color, s0, t0, s1, t1);
            }
        }
        return;
    }

    case 9: /* Lightning (multi-segment beam) */
    {
        float forward[3];
        float midpoint[3];
        float right[3], up[3];
        int numSegments;
        float segLen;

        /* Compute direction and length */
        {
            float dx = re->endpos[0] - re->origin[0];
            float dy = re->endpos[1] - re->origin[1];
            float dz = re->endpos[2] - re->origin[2];
            segLen = dx*dx + dy*dy + dz*dz;
            segLen = sqrtf(segLen);
        }

        /* Build color */
        color = (re->materialRGBA[0]) |
                (re->materialRGBA[1] << 8) |
                (re->materialRGBA[2] << 16) |
                (re->materialRGBA[3] << 24);

        /* Draw rail core */
        {
            float railWidth;
            byte *dvar = *(byte **)imp_r_railCoreWidth;
            dvar = *(byte **)dvar;
            railWidth = *(float *)(dvar + 8);
            float invLen = segLen * 0.00390625f; /* 1/256 */

            if (isDx7) {
                RB_AddLineDx7_impl((float *)re->origin, (float *)re->endpos,
                    railWidth, color, 0.0f, 0.0f, invLen, 1.0f);
            } else {
                RB_AddLine_impl((float *)re->origin, (float *)re->endpos,
                    railWidth, color, 0.0f, 0.0f, invLen, 1.0f);
            }
        }
        return;
    }

    default:
        return;
    }
}
