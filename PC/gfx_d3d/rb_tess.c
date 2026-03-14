/* ASM dump from: rb_tess.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_tess.cpp */

#include "common_types.h"
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

static inline char *RB_TessBase(void)
{
    return (char *)imp_tess;
}

void RB_TessBad(const surfaceType_t *surfType);
void RB_TessParticleCloud(const GfxEntity *re);
void RB_TessXModelRigid(const surfaceType_t *surfType);
static void RB_AddQuadStampDx7(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddQuadStamp(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddQuadStampDx7_impl(const vec_t *origin, const vec_t *left, const vec_t *up, int nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddQuadStamp_impl(const vec_t *origin, const vec_t *left, const vec_t *up, int nativeColor, float s0, float t0, float s1, float t1);
static void RB_BuildSprite_impl(const char *re, const float *worldRadius);
static void RB_AddLineDx7_impl(const vec_t *start, const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddLine_impl(const vec_t *start, const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
static void RB_BuildSprite(void);
static void RB_AddLineDx7(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddLine(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1);
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
    char *dxCaps;
    char *tess;
    char *backEnd;
    char *backEndData;
    char *dxGlobals;
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
    dxCaps = *(char **)imp_r_rendererInUse;
    dxCaps = *(char **)dxCaps;
    if (*(int *)(dxCaps + 8) == 2) {
        return;
    }

    /* Flush if surface has existing data */
    tess = RB_TessBase();
    if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
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

        /* Copy camera view axis (3x3 matrix at backEnd->viewParms+0x48) */
        backEnd = (char *)imp_backEnd;
        camAxis = (float *)(*(char **)(backEnd + 0x3c8) + 0x48);
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

    /* Store viewAxis to backEnd+0x310 */
    backEnd = (char *)imp_backEnd;
    *(float *)(backEnd + 0x310) = viewAxis[0];
    *(float *)(backEnd + 0x314) = viewAxis[1];
    *(float *)(backEnd + 0x318) = viewAxis[2];
    *(float *)(backEnd + 0x31c) = viewAxis[3];

    /* Convert materialRGBA to float color and store to backEnd+0x300 */
    *(float *)(backEnd + 0x300) = (float)re->materialRGBA[0] * oneOver255;
    *(float *)(backEnd + 0x304) = (float)re->materialRGBA[1] * oneOver255;
    *(float *)(backEnd + 0x308) = (float)re->materialRGBA[2] * oneOver255;
    *(float *)(backEnd + 0x30c) = (float)re->materialRGBA[3] * oneOver255;

    /* Set up index and vertex buffers from DxGlobals */
    dxGlobals = (char *)imp_dx;
    ib = *(IDirect3DIndexBuffer9 **)(dxGlobals + 0x2dbc);
    backEndData = (char *)imp_dxState;
    if (ib != *(IDirect3DIndexBuffer9 **)(backEndData + 0x20cc)) {
        RB_ChangeIndices(ib);
    }

    vb = *(IDirect3DVertexBuffer9 **)(dxGlobals + 0x2db8);
    if (vb != *(IDirect3DVertexBuffer9 **)(backEndData + 0x20d0) ||
        *(int *)(backEndData + 0x20d4) != 0 ||
        *(int *)(backEndData + 0x20d8) != 0x14) {
        RB_ChangeStreamSource(0, vb, 0, 0x14);
    }

    RB_DrawTechnique(2, &args);
}

/* line 1406 */
void RB_TessXModelRigid(const surfaceType_t *surfType)
{
    char *tess;
    char *backEndData;
    char *dxCaps;
    XSurface *xsurf;
    GfxDrawPrimArgs args;
    IDirect3DVertexBuffer9 *vb;
    IDirect3DIndexBuffer9 *ib;
    int vertexStride;
    D3DMATRIX *worldMatrix;
    float *boneAxis;
    char *entity;

    tess = RB_TessBase();

    /* Flush if surface has existing data */
    if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
        RB_EndSurface();
    }

    /* Get XSurface from surfType (GfxModelRigidSurface: +0 surfType, +4 xsurf) */
    xsurf = *(XSurface **)((byte *)surfType + 4);

    /* Set up draw prim args */
    args.firstVertexFromBase = 0;
    args.vertexCount = (int)xsurf->vertCount;
    args.primCount = (int)xsurf->triCount;
    args.u.buf.baseVertex = 0;
    args.u.buf.baseIndex = 0;

    /* Change index buffer if needed */
    ib = xsurf->indexBuffer;
    backEndData = (char *)imp_dxState;
    if (ib != *(IDirect3DIndexBuffer9 **)(backEndData + 0x20cc)) {
        RB_ChangeIndices(ib);
    }

    /* Determine vertex stride based on DX level */
    vb = xsurf->surfRigid.vb;
    dxCaps = *(char **)imp_r_rendererInUse;
    dxCaps = *(char **)dxCaps;
    if (*(int *)(dxCaps + 8) == 2) {
        vertexStride = 0x24;
    } else {
        vertexStride = 0x40;
    }

    /* Change stream source if needed */
    if (vb != *(IDirect3DVertexBuffer9 **)(backEndData + 0x20d0) ||
        *(int *)(backEndData + 0x20d4) != 0 ||
        *(int *)(backEndData + 0x20d8) != vertexStride) {
        RB_ChangeStreamSource(0, vb, 0, vertexStride);
    }

    /* Push matrix and set up world transform from boneAxis */
    RB_PushMatrixStack();

    entity = *(char **)((byte *)(void *)imp_backEnd + 0x440);
    boneAxis = (float *)((byte *)surfType + 8);

    worldMatrix = RB_GetActiveWorldMatrix();
    /* Row 0: boneAxis[0] */
    ((float *)worldMatrix)[0] = boneAxis[0];
    ((float *)worldMatrix)[1] = boneAxis[1];
    ((float *)worldMatrix)[2] = boneAxis[2];
    ((float *)worldMatrix)[3] = 0.0f;
    /* Row 1: boneAxis[1] */
    ((float *)worldMatrix)[4] = boneAxis[3];
    ((float *)worldMatrix)[5] = boneAxis[4];
    ((float *)worldMatrix)[6] = boneAxis[5];
    ((float *)worldMatrix)[7] = 0.0f;
    /* Row 2: boneAxis[2] */
    ((float *)worldMatrix)[8] = boneAxis[6];
    ((float *)worldMatrix)[9] = boneAxis[7];
    ((float *)worldMatrix)[10] = boneAxis[8];
    ((float *)worldMatrix)[11] = 0.0f;
    /* Row 3: boneAxis[3] (translation) */
    ((float *)worldMatrix)[12] = boneAxis[9];
    ((float *)worldMatrix)[13] = boneAxis[10];
    ((float *)worldMatrix)[14] = boneAxis[11];
    ((float *)worldMatrix)[15] = 1.0f;

    RB_ChangedWorldMatrix(*(float *)(entity + 0x38));

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
    char *tess, *backEnd, *viewParms;
    unsigned short *indices;
    char *v0, *v1, *v2, *v3;
    int vc, ic;
    float lx, ly, lz, ux, uy, uz, nx, ny, nz;
    float *from;
    void *savedMat;

    tess = RB_TessBase();

    /* Flush tessellation buffer on vertex/index overflow */
    if (*(int *)(tess + 0x5a7d4) + 4 > 0x154a ||
        *(int *)(tess + 0x5a7d0) + 6 > 0x100000) {
        savedMat = *(void **)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(*(void **)(tess + 0x5a7bc),
                        *(int *)(tess + 0x5a7c0),
                        *(int *)(tess + 0x5a7c4));
        if (*(void **)(tess + 0x5a7cc) != savedMat) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0)
                RB_EndSurface();
            *(void **)(tess + 0x5a7cc) = savedMat;
        }
    }

    vc = *(int *)(tess + 0x5a7d4);
    ic = *(int *)(tess + 0x5a7d0);
    indices = *(unsigned short **)(tess + 0x5a7b0);

    /* 6 indices for 2 triangles: (v0,v1,v3) and (v3,v1,v2) */
    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 3);
    indices[ic + 3] = (unsigned short)(vc + 3);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 2);

    /* Vertex base pointer: Dx7 stride = 36 bytes */
    v0 = (char *)imp_tess + (unsigned short)vc * 36;
    v1 = v0 + 36;
    v2 = v0 + 72;
    v3 = v0 + 108;

    /* 4 corners: origin +/- left +/- up */
    lx = left[0]; ly = left[1]; lz = left[2];
    ux = up[0];   uy = up[1];   uz = up[2];

    *(float *)(v0 + 0x00) = origin[0] + lx + ux;
    *(float *)(v0 + 0x04) = origin[1] + ly + uy;
    *(float *)(v0 + 0x08) = origin[2] + lz + uz;

    *(float *)(v1 + 0x00) = origin[0] - lx + ux;
    *(float *)(v1 + 0x04) = origin[1] - ly + uy;
    *(float *)(v1 + 0x08) = origin[2] - lz + uz;

    *(float *)(v2 + 0x00) = origin[0] - lx - ux;
    *(float *)(v2 + 0x04) = origin[1] - ly - uy;
    *(float *)(v2 + 0x08) = origin[2] - lz - uz;

    *(float *)(v3 + 0x00) = origin[0] + lx - ux;
    *(float *)(v3 + 0x04) = origin[1] + ly - uy;
    *(float *)(v3 + 0x08) = origin[2] + lz - uz;

    /* Normal: negate viewParms "from" direction
     * (faceAxis+112 = 0x80000000 sign-flip mask, i.e. negation) */
    backEnd = (char *)imp_backEnd;
    viewParms = *(char **)(backEnd + 0x3c8);
    from = (float *)(viewParms + 0x0c);
    nx = -from[0]; ny = -from[1]; nz = -from[2];

    *(float *)(v0 + 0x0c) = nx; *(float *)(v0 + 0x10) = ny; *(float *)(v0 + 0x14) = nz;
    *(float *)(v1 + 0x0c) = nx; *(float *)(v1 + 0x10) = ny; *(float *)(v1 + 0x14) = nz;
    *(float *)(v2 + 0x0c) = nx; *(float *)(v2 + 0x10) = ny; *(float *)(v2 + 0x14) = nz;
    *(float *)(v3 + 0x0c) = nx; *(float *)(v3 + 0x10) = ny; *(float *)(v3 + 0x14) = nz;

    /* Color at +0x18 */
    *(int *)(v0 + 0x18) = nativeColor;
    *(int *)(v1 + 0x18) = nativeColor;
    *(int *)(v2 + 0x18) = nativeColor;
    *(int *)(v3 + 0x18) = nativeColor;

    /* Texcoords at +0x1c/+0x20: (s0,t0), (s1,t0), (s1,t1), (s0,t1) */
    *(float *)(v0 + 0x1c) = s0; *(float *)(v0 + 0x20) = t0;
    *(float *)(v1 + 0x1c) = s1; *(float *)(v1 + 0x20) = t0;
    *(float *)(v2 + 0x1c) = s1; *(float *)(v2 + 0x20) = t1;
    *(float *)(v3 + 0x1c) = s0; *(float *)(v3 + 0x20) = t1;

    *(int *)(tess + 0x5a7d4) = vc + 4;  /* vertexCount += 4 */
    *(int *)(tess + 0x5a7d0) = ic + 6;  /* indexCount += 6 */
}

static __attribute__((naked))
void RB_AddQuadStampDx7(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1)
{
    /* Marshal register args (eax=origin,edx=left,ecx=up,xmm0-3=s0-t1,4(%esp)=nativeColor)
     * to standard C calling convention for _impl */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $16, %esp\n"
        "movss %xmm0, -4(%ebp)\n"
        "movss %xmm1, -8(%ebp)\n"
        "movss %xmm2, -12(%ebp)\n"
        "movss %xmm3, -16(%ebp)\n"
        "pushl -16(%ebp)\n"
        "pushl -12(%ebp)\n"
        "pushl -8(%ebp)\n"
        "pushl -4(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_AddQuadStampDx7_impl\n"
        "addl $32, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
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
    char *tess, *backEnd, *viewParms;
    unsigned short *indices;
    char *v0, *v1, *v2, *v3;
    int vc, ic;
    float lx, ly, lz, ux, uy, uz, nx, ny, nz;
    float *from;
    void *savedMat;

    tess = RB_TessBase();

    /* Flush tessellation buffer on vertex/index overflow */
    if (*(int *)(tess + 0x5a7d4) + 4 > 0x154a ||
        *(int *)(tess + 0x5a7d0) + 6 > 0x100000) {
        savedMat = *(void **)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(*(void **)(tess + 0x5a7bc),
                        *(int *)(tess + 0x5a7c0),
                        *(int *)(tess + 0x5a7c4));
        if (*(void **)(tess + 0x5a7cc) != savedMat) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0)
                RB_EndSurface();
            *(void **)(tess + 0x5a7cc) = savedMat;
        }
    }

    vc = *(int *)(tess + 0x5a7d4);
    ic = *(int *)(tess + 0x5a7d0);
    indices = *(unsigned short **)(tess + 0x5a7b0);

    /* 6 indices for 2 triangles: (v0,v1,v3) and (v3,v1,v2) */
    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 3);
    indices[ic + 3] = (unsigned short)(vc + 3);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 2);

    /* Vertex base pointer: non-Dx7 stride = 64 bytes */
    v0 = (char *)imp_tess + (unsigned short)vc * 64;
    v1 = v0 + 64;
    v2 = v0 + 128;
    v3 = v0 + 192;

    /* 4 corners: origin +/- left +/- up */
    lx = left[0]; ly = left[1]; lz = left[2];
    ux = up[0];   uy = up[1];   uz = up[2];

    *(float *)(v0 + 0x00) = origin[0] + lx + ux;
    *(float *)(v0 + 0x04) = origin[1] + ly + uy;
    *(float *)(v0 + 0x08) = origin[2] + lz + uz;

    *(float *)(v1 + 0x00) = origin[0] - lx + ux;
    *(float *)(v1 + 0x04) = origin[1] - ly + uy;
    *(float *)(v1 + 0x08) = origin[2] - lz + uz;

    *(float *)(v2 + 0x00) = origin[0] - lx - ux;
    *(float *)(v2 + 0x04) = origin[1] - ly - uy;
    *(float *)(v2 + 0x08) = origin[2] - lz - uz;

    *(float *)(v3 + 0x00) = origin[0] + lx - ux;
    *(float *)(v3 + 0x04) = origin[1] + ly - uy;
    *(float *)(v3 + 0x08) = origin[2] + lz - uz;

    /* Scalar 1.0f at +0x0c in each vertex */
    *(float *)(v0 + 0x0c) = 1.0f;
    *(float *)(v1 + 0x0c) = 1.0f;
    *(float *)(v2 + 0x0c) = 1.0f;
    *(float *)(v3 + 0x0c) = 1.0f;

    /* Normal at +0x10: negate viewParms "from" direction
     * (faceAxis+128 = 0x80000000 sign-flip = negate) */
    backEnd = (char *)imp_backEnd;
    viewParms = *(char **)(backEnd + 0x3c8);
    from = (float *)(viewParms + 0x0c);
    nx = -from[0]; ny = -from[1]; nz = -from[2];

    *(float *)(v0 + 0x10) = nx; *(float *)(v0 + 0x14) = ny; *(float *)(v0 + 0x18) = nz;
    *(float *)(v1 + 0x10) = nx; *(float *)(v1 + 0x14) = ny; *(float *)(v1 + 0x18) = nz;
    *(float *)(v2 + 0x10) = nx; *(float *)(v2 + 0x14) = ny; *(float *)(v2 + 0x18) = nz;
    *(float *)(v3 + 0x10) = nx; *(float *)(v3 + 0x14) = ny; *(float *)(v3 + 0x18) = nz;

    /* Color at +0x1c */
    *(int *)(v0 + 0x1c) = nativeColor;
    *(int *)(v1 + 0x1c) = nativeColor;
    *(int *)(v2 + 0x1c) = nativeColor;
    *(int *)(v3 + 0x1c) = nativeColor;

    /* Texcoords at +0x20/+0x24: (s0,t0), (s1,t0), (s1,t1), (s0,t1) */
    *(float *)(v0 + 0x20) = s0; *(float *)(v0 + 0x24) = t0;
    *(float *)(v1 + 0x20) = s1; *(float *)(v1 + 0x24) = t0;
    *(float *)(v2 + 0x20) = s1; *(float *)(v2 + 0x24) = t1;
    *(float *)(v3 + 0x20) = s0; *(float *)(v3 + 0x24) = t1;

    /* Up vector at +0x28 (stored as-is, no sign flip) */
    *(float *)(v0 + 0x28) = up[0]; *(float *)(v0 + 0x2c) = up[1]; *(float *)(v0 + 0x30) = up[2];
    *(float *)(v1 + 0x28) = up[0]; *(float *)(v1 + 0x2c) = up[1]; *(float *)(v1 + 0x30) = up[2];
    *(float *)(v2 + 0x28) = up[0]; *(float *)(v2 + 0x2c) = up[1]; *(float *)(v2 + 0x30) = up[2];
    *(float *)(v3 + 0x28) = up[0]; *(float *)(v3 + 0x2c) = up[1]; *(float *)(v3 + 0x30) = up[2];

    /* Left vector at +0x34 (sign-flipped: faceAxis+128 = 0x80000000 = negate) */
    *(float *)(v0 + 0x34) = -left[0]; *(float *)(v0 + 0x38) = -left[1]; *(float *)(v0 + 0x3c) = -left[2];
    *(float *)(v1 + 0x34) = -left[0]; *(float *)(v1 + 0x38) = -left[1]; *(float *)(v1 + 0x3c) = -left[2];
    *(float *)(v2 + 0x34) = -left[0]; *(float *)(v2 + 0x38) = -left[1]; *(float *)(v2 + 0x3c) = -left[2];
    *(float *)(v3 + 0x34) = -left[0]; *(float *)(v3 + 0x38) = -left[1]; *(float *)(v3 + 0x3c) = -left[2];

    *(int *)(tess + 0x5a7d4) = vc + 4;  /* vertexCount += 4 */
    *(int *)(tess + 0x5a7d0) = ic + 6;  /* indexCount += 6 */
}

static __attribute__((naked))
void RB_AddQuadStamp(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1)
{
    /* Marshal register args (eax=origin,edx=left,ecx=up,xmm0-3=s0-t1,4(%esp)=nativeColor)
     * to standard C calling convention for _impl */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $16, %esp\n"
        "movss %xmm0, -4(%ebp)\n"
        "movss %xmm1, -8(%ebp)\n"
        "movss %xmm2, -12(%ebp)\n"
        "movss %xmm3, -16(%ebp)\n"
        "pushl -16(%ebp)\n"
        "pushl -12(%ebp)\n"
        "pushl -8(%ebp)\n"
        "pushl -4(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_AddQuadStamp_impl\n"
        "addl $32, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* Calling convention: eax=re, edx=worldRadius (float[2]) */
static void RB_BuildSprite_impl(const char *re, const float *worldRadius)
{
    float worldOrigin[3], left[3], up[3];
    float scale, angle, sinA, cosA;
    int nativeColor;
    int ncols, nrows, totalFrames, frame, row, col;
    float s0, t0, s1, t1;
    char *backEnd, *viewParms;
    char *material;
    char *r_rendererInUse;

    /* Copy origin from re->0x3c */
    worldOrigin[0] = *(float *)(re + 0x3c);
    worldOrigin[1] = *(float *)(re + 0x40);
    worldOrigin[2] = *(float *)(re + 0x44);

    /* Flag at re+5 bit 0x10: if set, offset z by worldRadius[1] */
    if (*(unsigned char *)(re + 5) & 0x10) {
        worldOrigin[2] += worldRadius[1];
    }

    /* re->0x6c = rotation angle */
    angle = *(float *)(re + 0x6c);

    backEnd = (char *)imp_backEnd;
    viewParms = *(char **)(backEnd + 0x3c8);

    if (angle == 0.0f) {
        /* Scale left axis by worldRadius[0], up axis by worldRadius[1] */
        scale = worldRadius[0];
        left[0] = *(float *)(viewParms + 0x18) * scale;
        left[1] = *(float *)(viewParms + 0x1c) * scale;
        left[2] = *(float *)(viewParms + 0x20) * scale;
        scale = worldRadius[1];
        up[0] = *(float *)(viewParms + 0x24) * scale;
        up[1] = *(float *)(viewParms + 0x28) * scale;
        up[2] = *(float *)(viewParms + 0x2c) * scale;
    } else {
        /* Apply rotation: angle in degrees -> radians */
        float radians = (float)((double)angle * 0.017453292519943295);
        sinA = sinf(radians);
        cosA = cosf(radians);

        /* left = cos*worldRadius[0]*leftAxis + (-sin)*worldRadius[0]*upAxis */
        left[0] = cosA * worldRadius[0] * *(float *)(viewParms + 0x18)
                + (-sinA) * worldRadius[0] * *(float *)(viewParms + 0x24);
        left[1] = cosA * worldRadius[0] * *(float *)(viewParms + 0x1c)
                + (-sinA) * worldRadius[0] * *(float *)(viewParms + 0x28);
        left[2] = cosA * worldRadius[0] * *(float *)(viewParms + 0x20)
                + (-sinA) * worldRadius[0] * *(float *)(viewParms + 0x2c);

        /* up = cos*worldRadius[1]*upAxis + sin*worldRadius[1]*leftAxis */
        up[0] = cosA * worldRadius[1] * *(float *)(viewParms + 0x24)
              + sinA  * worldRadius[1] * *(float *)(viewParms + 0x18);
        up[1] = cosA * worldRadius[1] * *(float *)(viewParms + 0x28)
              + sinA  * worldRadius[1] * *(float *)(viewParms + 0x1c);
        up[2] = cosA * worldRadius[1] * *(float *)(viewParms + 0x2c)
              + sinA  * worldRadius[1] * *(float *)(viewParms + 0x20);
    }

    /* nativeColor from re->0x5b,0x58,0x59,0x5a (byte order) */
    ((unsigned char *)&nativeColor)[0] = *(unsigned char *)(re + 0x5b);
    ((unsigned char *)&nativeColor)[1] = *(unsigned char *)(re + 0x58);
    ((unsigned char *)&nativeColor)[2] = *(unsigned char *)(re + 0x59);
    ((unsigned char *)&nativeColor)[3] = *(unsigned char *)(re + 0x5a);

    /* Animation frame UVs */
    material = *(char **)(re + 0x54);
    ncols = *(unsigned char *)(material + 0x0e);
    nrows = *(unsigned char *)(material + 0x0f);
    totalFrames = ncols * nrows;

    if (totalFrames == 1) {
        s0 = 0.0f; t0 = 0.0f; s1 = 1.0f; t1 = 1.0f;
    } else {
        float inv_nrows = 1.0f / (float)nrows;
        float inv_ncols = 1.0f / (float)ncols;
        frame = *(int *)(re + 0x60);
        row = frame / nrows;
        col = frame % nrows;
        s0 = (float)col * inv_nrows;
        t0 = (float)row * inv_ncols;
        s1 = s0 + inv_nrows;
        t1 = t0 + inv_ncols;
    }

    /* Dispatch to renderer */
    r_rendererInUse = *(char **)imp_r_rendererInUse;
    if (*(int *)(r_rendererInUse + 8) == 2) {
        RB_AddQuadStampDx7_impl(worldOrigin, left, up, nativeColor, s0, t0, s1, t1);
    } else {
        RB_AddQuadStamp_impl(worldOrigin, left, up, nativeColor, s0, t0, s1, t1);
    }
}

/* line 299 */
static __attribute__((naked))
void RB_BuildSprite(void)
{
    /* Marshal register args (eax=re, edx=worldRadius) to standard C calling convention */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_BuildSprite_impl\n"
        "addl $8, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
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
    char *tess = RB_TessBase();
    char *backEnd = (char *)imp_backEnd;
    void *savedMat;
    int vc, ic;
    unsigned short *indices;
    char *v0, *v1, *v2, *v3;
    float v1v[3], v2v[3], tangent[3], halfTangent[3], binormal[3], normal[3];
    float *viewOrigin;

    /* Flush tessellation buffer on overflow */
    if (*(int *)(tess + 0x5a7d4) + 4 > 0x154a ||
        *(int *)(tess + 0x5a7d0) + 6 > 0x100000) {
        savedMat = *(void **)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(*(void **)(tess + 0x5a7bc), *(int *)(tess + 0x5a7c0), *(int *)(tess + 0x5a7c4));
        if (*(void **)(tess + 0x5a7cc) != savedMat) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0)
                RB_EndSurface();
            *(void **)(tess + 0x5a7cc) = savedMat;
        }
    }

    /* Compute tangent = cross(start-view, end-view), normalize */
    viewOrigin = (float *)(*(char **)(backEnd + 0x3c8));
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

    vc = *(int *)(tess + 0x5a7d4);
    ic = *(int *)(tess + 0x5a7d0);
    indices = *(unsigned short **)(tess + 0x5a7b0);

    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 2);
    indices[ic + 3] = (unsigned short)(vc + 2);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 3);

    /* Vertex base: Dx7 stride = 36 bytes */
    v0 = tess + (unsigned short)vc * 36;
    v1 = v0 + 36;
    v2 = v0 + 72;
    v3 = v0 + 108;

    /* Positions */
    *(float *)(v0 + 0x00) = start[0] + halfTangent[0]; *(float *)(v0 + 0x04) = start[1] + halfTangent[1]; *(float *)(v0 + 0x08) = start[2] + halfTangent[2];
    *(float *)(v1 + 0x00) = start[0] - halfTangent[0]; *(float *)(v1 + 0x04) = start[1] - halfTangent[1]; *(float *)(v1 + 0x08) = start[2] - halfTangent[2];
    *(float *)(v2 + 0x00) = end[0]   + halfTangent[0]; *(float *)(v2 + 0x04) = end[1]   + halfTangent[1]; *(float *)(v2 + 0x08) = end[2]   + halfTangent[2];
    *(float *)(v3 + 0x00) = end[0]   - halfTangent[0]; *(float *)(v3 + 0x04) = end[1]   - halfTangent[1]; *(float *)(v3 + 0x08) = end[2]   - halfTangent[2];

    /* Normals at +0x0c */
    *(float *)(v0 + 0x0c) = normal[0]; *(float *)(v0 + 0x10) = normal[1]; *(float *)(v0 + 0x14) = normal[2];
    *(float *)(v1 + 0x0c) = normal[0]; *(float *)(v1 + 0x10) = normal[1]; *(float *)(v1 + 0x14) = normal[2];
    *(float *)(v2 + 0x0c) = normal[0]; *(float *)(v2 + 0x10) = normal[1]; *(float *)(v2 + 0x14) = normal[2];
    *(float *)(v3 + 0x0c) = normal[0]; *(float *)(v3 + 0x10) = normal[1]; *(float *)(v3 + 0x14) = normal[2];

    /* Colors at +0x18 */
    *(int *)(v0 + 0x18) = nativeColor;
    *(int *)(v1 + 0x18) = nativeColor;
    *(int *)(v2 + 0x18) = nativeColor;
    *(int *)(v3 + 0x18) = nativeColor;

    /* UVs at +0x1c/+0x20: v0=(s0,t0), v1=(s1,t0), v2=(s0,t1), v3=(s1,t1) */
    *(float *)(v0 + 0x1c) = s0; *(float *)(v0 + 0x20) = t0;
    *(float *)(v1 + 0x1c) = s1; *(float *)(v1 + 0x20) = t0;
    *(float *)(v2 + 0x1c) = s0; *(float *)(v2 + 0x20) = t1;
    *(float *)(v3 + 0x1c) = s1; *(float *)(v3 + 0x20) = t1;

    *(int *)(tess + 0x5a7d4) = vc + 4;
    *(int *)(tess + 0x5a7d0) = ic + 6;
}

/* line 877 */
static __attribute__((naked))
void RB_AddLineDx7(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    /* Marshal register args (eax=start,edx=end,xmm0=width,ecx=nativeColor,
     * xmm1=s0,xmm2=t0,xmm3=s1,4(%esp)=t1) to standard C calling convention */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $16, %esp\n"
        "movss %xmm0, -4(%ebp)\n"
        "movss %xmm1, -8(%ebp)\n"
        "movss %xmm2, -12(%ebp)\n"
        "movss %xmm3, -16(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl -16(%ebp)\n"
        "pushl -12(%ebp)\n"
        "pushl -8(%ebp)\n"
        "pushl %ecx\n"
        "pushl -4(%ebp)\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_AddLineDx7_impl\n"
        "addl $32, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
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
    char *tess = RB_TessBase();
    char *backEnd = (char *)imp_backEnd;
    void *savedMat;
    int vc, ic;
    unsigned short *indices;
    char *v0, *v1, *v2, *v3;
    float v1v[3], v2v[3], tangent[3], halfTangent[3], binormal[3], normal[3];
    float *viewOrigin;

    /* Flush tessellation buffer on overflow */
    if (*(int *)(tess + 0x5a7d4) + 4 > 0x154a ||
        *(int *)(tess + 0x5a7d0) + 6 > 0x100000) {
        savedMat = *(void **)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(*(void **)(tess + 0x5a7bc), *(int *)(tess + 0x5a7c0), *(int *)(tess + 0x5a7c4));
        if (*(void **)(tess + 0x5a7cc) != savedMat) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0)
                RB_EndSurface();
            *(void **)(tess + 0x5a7cc) = savedMat;
        }
    }

    /* Compute tangent = cross(start-view, end-view), normalize */
    viewOrigin = (float *)(*(char **)(backEnd + 0x3c8));
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

    vc = *(int *)(tess + 0x5a7d4);
    ic = *(int *)(tess + 0x5a7d0);
    indices = *(unsigned short **)(tess + 0x5a7b0);

    indices[ic + 0] = (unsigned short)vc;
    indices[ic + 1] = (unsigned short)(vc + 1);
    indices[ic + 2] = (unsigned short)(vc + 2);
    indices[ic + 3] = (unsigned short)(vc + 2);
    indices[ic + 4] = (unsigned short)(vc + 1);
    indices[ic + 5] = (unsigned short)(vc + 3);

    /* Vertex base: non-Dx7 stride = 64 bytes */
    v0 = tess + (unsigned short)vc * 64;
    v1 = v0 + 64;
    v2 = v0 + 128;
    v3 = v0 + 192;

    /* Positions */
    *(float *)(v0 + 0x00) = start[0] + halfTangent[0]; *(float *)(v0 + 0x04) = start[1] + halfTangent[1]; *(float *)(v0 + 0x08) = start[2] + halfTangent[2];
    *(float *)(v1 + 0x00) = start[0] - halfTangent[0]; *(float *)(v1 + 0x04) = start[1] - halfTangent[1]; *(float *)(v1 + 0x08) = start[2] - halfTangent[2];
    *(float *)(v2 + 0x00) = end[0]   + halfTangent[0]; *(float *)(v2 + 0x04) = end[1]   + halfTangent[1]; *(float *)(v2 + 0x08) = end[2]   + halfTangent[2];
    *(float *)(v3 + 0x00) = end[0]   - halfTangent[0]; *(float *)(v3 + 0x04) = end[1]   - halfTangent[1]; *(float *)(v3 + 0x08) = end[2]   - halfTangent[2];

    /* W = 1.0 at +0x0c */
    *(float *)(v0 + 0x0c) = 1.0f;
    *(float *)(v1 + 0x0c) = 1.0f;
    *(float *)(v2 + 0x0c) = 1.0f;
    *(float *)(v3 + 0x0c) = 1.0f;

    /* Normals at +0x10 */
    *(float *)(v0 + 0x10) = normal[0]; *(float *)(v0 + 0x14) = normal[1]; *(float *)(v0 + 0x18) = normal[2];
    *(float *)(v1 + 0x10) = normal[0]; *(float *)(v1 + 0x14) = normal[1]; *(float *)(v1 + 0x18) = normal[2];
    *(float *)(v2 + 0x10) = normal[0]; *(float *)(v2 + 0x14) = normal[1]; *(float *)(v2 + 0x18) = normal[2];
    *(float *)(v3 + 0x10) = normal[0]; *(float *)(v3 + 0x14) = normal[1]; *(float *)(v3 + 0x18) = normal[2];

    /* Colors at +0x1c */
    *(int *)(v0 + 0x1c) = nativeColor;
    *(int *)(v1 + 0x1c) = nativeColor;
    *(int *)(v2 + 0x1c) = nativeColor;
    *(int *)(v3 + 0x1c) = nativeColor;

    /* UVs at +0x20/+0x24: v0=(s0,t0), v1=(s1,t0), v2=(s0,t1), v3=(s1,t1) */
    *(float *)(v0 + 0x20) = s0; *(float *)(v0 + 0x24) = t0;
    *(float *)(v1 + 0x20) = s1; *(float *)(v1 + 0x24) = t0;
    *(float *)(v2 + 0x20) = s0; *(float *)(v2 + 0x24) = t1;
    *(float *)(v3 + 0x20) = s1; *(float *)(v3 + 0x24) = t1;

    /* Binormals at +0x28 */
    *(float *)(v0 + 0x28) = binormal[0]; *(float *)(v0 + 0x2c) = binormal[1]; *(float *)(v0 + 0x30) = binormal[2];
    *(float *)(v1 + 0x28) = binormal[0]; *(float *)(v1 + 0x2c) = binormal[1]; *(float *)(v1 + 0x30) = binormal[2];
    *(float *)(v2 + 0x28) = binormal[0]; *(float *)(v2 + 0x2c) = binormal[1]; *(float *)(v2 + 0x30) = binormal[2];
    *(float *)(v3 + 0x28) = binormal[0]; *(float *)(v3 + 0x2c) = binormal[1]; *(float *)(v3 + 0x30) = binormal[2];

    /* Tangents at +0x34 */
    *(float *)(v0 + 0x34) = tangent[0]; *(float *)(v0 + 0x38) = tangent[1]; *(float *)(v0 + 0x3c) = tangent[2];
    *(float *)(v1 + 0x34) = tangent[0]; *(float *)(v1 + 0x38) = tangent[1]; *(float *)(v1 + 0x3c) = tangent[2];
    *(float *)(v2 + 0x34) = tangent[0]; *(float *)(v2 + 0x38) = tangent[1]; *(float *)(v2 + 0x3c) = tangent[2];
    *(float *)(v3 + 0x34) = tangent[0]; *(float *)(v3 + 0x38) = tangent[1]; *(float *)(v3 + 0x3c) = tangent[2];

    *(int *)(tess + 0x5a7d4) = vc + 4;
    *(int *)(tess + 0x5a7d0) = ic + 6;
}

/* line 803 */
static __attribute__((naked))
void RB_AddLine(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    /* Marshal register args (eax=start,edx=end,xmm0=width,ecx=nativeColor,
     * xmm1=s0,xmm2=t0,xmm3=s1,4(%esp)=t1) to standard C calling convention */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "subl $16, %esp\n"
        "movss %xmm0, -4(%ebp)\n"
        "movss %xmm1, -8(%ebp)\n"
        "movss %xmm2, -12(%ebp)\n"
        "movss %xmm3, -16(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl -16(%ebp)\n"
        "pushl -12(%ebp)\n"
        "pushl -8(%ebp)\n"
        "pushl %ecx\n"
        "pushl -4(%ebp)\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll RB_AddLine_impl\n"
        "addl $32, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1151 */
__attribute__((naked))
void RB_TessEntity(const GfxEntity *re)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1151 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* color */
        "movl 8(%ebp), %edi\n" /* re */
        "movl (%edi), %eax\n" /* line 1157 | re */
        "subl $4, %eax\n"
        "cmpl $5, %eax\n"
        "ja .Lfffc70_000ffe08\n"
        "jmpl *.Ljt_ffc70_0(, %eax, 4)\n"
        ".Lfffc70_000ffc98:\n"
        "testb $0x20, 5(%edi)\n" /* line 514 */
        "jne .Lfffc70_00100586\n"
        /* { scope 1: from, screenOffset, b, a, ... */
        "leal 0x64(%edi), %eax\n" /* line 489 */
        "movl %eax, -0xc8(%ebp)\n" /* from */
        /* { scope 2: worldOffset */
        "movss 0x64(%edi), %xmm3\n" /* line 37 */
        "movss %xmm3, -0x30(%ebp)\n" /* worldRadius */
        "leal 0x68(%edi), %esi\n" /* line 38 */
        "movss 0x68(%edi), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "pxor %xmm4, %xmm4\n" /* line 491 */
        "movss 0x70(%edi), %xmm6\n"
        "ucomiss %xmm4, %xmm6\n"
        "jbe .Lfffc70_000ffdfe\n"
        "leal 0x3c(%edi), %edx\n" /* line 493 */
        /* { scope 2: worldOffset */
        /* { scope 3 */
        "movl imp_backEnd, %eax\n" /* line 368 */
        "movl 0x3c8(%eax), %ecx\n"
        "leal 0xc8(%ecx), %ebx\n"
        "movss 0x3c(%edi), %xmm2\n" /* line 371 */
        "mulss 0xc(%ebx), %xmm2\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x1c(%ebx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x2c(%ebx), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x3c(%ebx), %xmm2\n"
        /* } scope */
        "ucomiss %xmm2, %xmm4\n" /* line 442 */
        "jae .Lfffc70_000ffe08\n"
        "leal 0x18(%ecx), %eax\n" /* line 445 | dir */
        "movaps %xmm3, %xmm0\n" /* scale */
        "xorps faceAxis+160, %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm5\n" /* line 288 */
        "mulss 0x18(%ecx), %xmm5\n"
        "addss (%ecx), %xmm5\n"
        "movaps %xmm0, %xmm4\n" /* line 289 */
        "mulss 4(%eax), %xmm4\n"
        "addss 4(%ecx), %xmm4\n"
        "movaps %xmm0, %xmm3\n" /* line 290 */
        "mulss 8(%eax), %xmm3\n"
        "addss 8(%ecx), %xmm3\n"
        /* } scope */
        "leal 0x24(%ecx), %eax\n" /* line 446 | dir */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x24(%ecx), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm4\n"
        "mulss 8(%eax), %xmm1\n" /* line 290 */
        "addss %xmm1, %xmm3\n"
        "movl %ebx, %eax\n"
        "xorl %edx, %edx\n"
        /* } scope */
        /* { scope 3 */
        ".Lfffc70_000ffd77:\n"
        "movaps %xmm5, %xmm0\n" /* line 384 */
        "mulss (%eax), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "mulss 0x10(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm1\n"
        "mulss 0x20(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "addss 0x30(%eax), %xmm0\n"
        "movss %xmm0, -0x24(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 383 */
        "addl $4, %eax\n"
        "cmpl $2, %edx\n"
        "jne .Lfffc70_000ffd77\n"
        /* } scope */
        "movss lit4_002ed5d0, %xmm0\n" /* line 449 | 1.0f, scale */
        "divss %xmm2, %xmm0\n" /* scale */
        /* { scope 3 */
        "movaps %xmm0, %xmm1\n" /* line 86 */
        "mulss -0x24(%ebp), %xmm1\n" /* screenOffset */
        "movss %xmm1, -0x24(%ebp)\n" /* screenOffset */
        "mulss -0x20(%ebp), %xmm0\n" /* line 87 */
        "movss %xmm0, -0x20(%ebp)\n"
        /* } scope */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        /* } scope */
        "ucomiss %xmm0, %xmm6\n" /* line 499 */
        "jbe .Lfffc70_000ffdfe\n"
        "divss %xmm0, %xmm6\n" /* line 501 */
        "movaps %xmm6, %xmm0\n"
        /* { scope 2: worldOffset */
        "movaps %xmm6, %xmm1\n" /* line 86 */
        "movl -0xc8(%ebp), %edx\n" /* from */
        "mulss (%edx), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* worldRadius */
        "mulss (%esi), %xmm0\n" /* line 87 */
        "movss %xmm0, -0x2c(%ebp)\n"
        /* } scope */
        ".Lfffc70_000ffdfe:\n"
        "leal -0x30(%ebp), %edx\n" /* line 506 | worldRadius */
        "movl %edi, %eax\n"
        "calll RB_BuildSprite\n"
        /* } scope */
        ".Lfffc70_000ffe08:\n"
        "addl $0x13c, %esp\n" /* line 1190 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfffc70_000ffe13:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1173 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100996\n"
        /* { scope 1: from, screenOffset, b, a, ... */
        "leal 0x48(%edi), %ebx\n" /* line 604 */
        "movl %ebx, -0x7c(%ebp)\n" /* b */
        "leal 0x3c(%edi), %esi\n"
        "movl %esi, -0x78(%ebp)\n" /* a */
        /* { scope 2: worldOffset */
        "movss 0x3c(%edi), %xmm2\n" /* line 256 */
        "addss 0x48(%edi), %xmm2\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm2\n"
        "leal 0x40(%edi), %eax\n" /* line 257 */
        "movl %eax, -0x74(%ebp)\n"
        "leal 0x4c(%edi), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movss 0x40(%edi), %xmm1\n"
        "addss 0x4c(%edi), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "leal 0x44(%edi), %ecx\n" /* line 258 */
        "movl %ecx, -0x6c(%ebp)\n"
        "leal 0x50(%edi), %ebx\n"
        "movl %ebx, -0x68(%ebp)\n"
        "movss 0x44(%edi), %xmm0\n"
        "addss 0x50(%edi), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        /* } scope */
        "movl imp_backEnd, %ebx\n" /* line 248 */
        "subss 0x3cc(%ebx), %xmm2\n"
        "movss %xmm2, -0x48(%ebp)\n" /* midpoint */
        "subss 0x3d0(%ebx), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x44(%ebp)\n"
        "subss 0x3d4(%ebx), %xmm0\n" /* line 250 */
        "movss %xmm0, -0x40(%ebp)\n"
        "leal -0x48(%ebp), %eax\n" /* line 606 | midpoint */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0xf8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm0\n"
        "mulss 0x3d8(%ebx), %xmm0\n" /* line 428 */
        "addss 0x3dc(%ebx), %xmm0\n"
        "mulss lit4_002ed890, %xmm0\n" /* -0.0009765625f */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "mulss lit4_002ed830, %xmm0\n" /* 32.0f */
        "movss -0xf8(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd8(%ebp)\n"
        "cvttss2si -0xd8(%ebp), %ecx\n"
        "cmpl $7, %ecx\n" /* line 611 */
        "jg .Lfffc70_00100644\n"
        "movl $0x30, %esi\n"
        "movl $0x10, -0x60(%ebp)\n"
        "movss lit4_002ed740, %xmm0\n" /* 8.0f */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movl -0x60(%ebp), %edx\n"
        ".Lfffc70_000fff39:\n"
        "movl imp_tess, %ebx\n" /* line 344 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "leal 2(%edx, %eax), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfffc70_000fff5e\n"
        "addl 0x5a7d0(%ebx), %esi\n"
        "cmpl $0x100000, %esi\n"
        "jle .Lfffc70_000fffba\n"
        ".Lfffc70_000fff5e:\n"
        "movl 0x5a7cc(%ebx), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%ebx), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%ebx), %esi\n" /* line 310 */
        "je .Lfffc70_000fffba\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfffc70_00100668\n"
        "movl 0x5a7e0(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lfffc70_00100668\n"
        ".Lfffc70_000fffaf:\n"
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %esi, 0x5a7cc(%eax)\n"
        ".Lfffc70_000fffba:\n"
        "movl -0x78(%ebp), %ecx\n" /* line 248 | a */
        "movss (%ecx), %xmm0\n"
        "movl -0x7c(%ebp), %ebx\n" /* b */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* forward */
        "movl -0x74(%ebp), %esi\n" /* line 249 */
        "movss (%esi), %xmm0\n"
        "movl -0x70(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movl -0x6c(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm0\n"
        "movl -0x68(%ebp), %ecx\n"
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* line 620 | forward */
        "movl %ebx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x24(%ebp), %eax\n" /* line 621 | screenOffset */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* worldRadius */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MakeNormalVectors\n"
        "movl imp_tess, %ebx\n" /* line 623 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "shll $6, %eax\n"
        "addl %ebx, %eax\n"
        "movl %eax, -0x80(%ebp)\n" /* vert */
        "leal 0x58(%edi), %edx\n" /* line 625 | rgbaFrom */
        "movzbl 1(%edx), %ecx\n"
        /* { scope 2: worldOffset */
        "movzbl 0x58(%edi), %eax\n" /* line 655 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, -0xd0(%ebp)\n" /* mtlColor */
        "orl %eax, -0xd0(%ebp)\n" /* mtlColor */
        "movl -0xd0(%ebp), %eax\n" /* line 656 | mtlColor */
        "movb %cl, %ah\n"
        "movl %eax, -0xd0(%ebp)\n" /* mtlColor */
        "movb 2(%edx), %al\n" /* line 657 */
        "movl %eax, -0xd0(%ebp)\n" /* mtlColor */
        "movzbl 3(%edx), %eax\n" /* line 658 */
        "shll $0x18, %eax\n"
        "andl $0x00FFFFFF, -0xd0(%ebp)\n" /* mtlColor */
        "orl %eax, -0xd0(%ebp)\n" /* mtlColor */
        /* } scope */
        "movss lit4_002ed5d0, %xmm0\n" /* line 627 | 1.0f */
        "divss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n" /* sDelta */
        "cvtss2sd %xmm0, %xmm0\n" /* line 631 */
        "mulsd lit8_00307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n" /* radians */
        /* { scope 2: worldOffset */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x84(%ebp)\n" /* sinAngleDelta */
        "movss -0x64(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm5\n"
        /* } scope */
        "movl -0x60(%ebp), %ecx\n" /* line 635 */
        "testl %ecx, %ecx\n"
        "jg .Lfffc70_00100672\n"
        "xorl %eax, %eax\n"
        "movl -0x80(%ebp), %edx\n" /* vert */
        "addl $0x40, %edx\n"
        "movl %edx, -0xdc(%ebp)\n"
        ".Lfffc70_001000e6:\n"
        "shll $6, %eax\n" /* line 667 */
        "addl -0x80(%ebp), %eax\n" /* vert */
        "movl -0x80(%ebp), %ecx\n" /* line 456 | vert */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 457 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 458 */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%ecx), %edx\n" /* line 459 */
        "movl %edx, 0xc(%eax)\n"
        "movl $0x3f800000, 0x20(%eax)\n" /* line 668 */
        "movl $0x3f800000, 0x24(%eax)\n" /* line 669 */
        "movl -0xd0(%ebp), %ebx\n" /* line 670 | mtlColor */
        "movl %ebx, 0x1c(%eax)\n"
        "leal 0x40(%eax), %ecx\n" /* line 672 */
        "movl -0x80(%ebp), %esi\n" /* line 456 | vert */
        "movl 0x40(%esi), %edx\n"
        "movl %edx, 0x40(%eax)\n"
        "movl -0xdc(%ebp), %edx\n" /* line 457 */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        "movl $0x3f800000, 0x20(%ecx)\n" /* line 673 */
        "movl $0, 0x24(%ecx)\n" /* line 674 */
        "movl %ebx, 0x1c(%ecx)\n" /* line 675 */
        "movl imp_tess, %ecx\n" /* line 677 */
        "movl 0x5a7d4(%ecx), %ecx\n"
        "addl %ecx, -0x60(%ebp)\n"
        "movl -0x60(%ebp), %eax\n"
        "addl $2, %eax\n"
        "movl imp_tess, %ebx\n"
        "movl %eax, 0x5a7d4(%ebx)\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100177:\n"
        "movb 0x5b(%edi), %bl\n" /* line 1130 | color */
        "movzbl 0x58(%edi), %eax\n" /* line 1131 */
        "movb %al, %bh\n" /* color */
        "movzbl 0x59(%edi), %eax\n" /* line 1132 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ebx\n" /* color */
        "orl %eax, %ebx\n" /* color */
        "movzbl 0x5a(%edi), %eax\n" /* line 1133 */
        "shll $0x18, %eax\n"
        "andl $0x00FFFFFF, %ebx\n" /* color */
        "orl %eax, %ebx\n" /* color */
        /* { scope 2: worldOffset */
        "movl 0x54(%edi), %eax\n" /* line 207 */
        "movzbl 0xe(%eax), %ecx\n" /* line 266 */
        "movzbl 0xf(%eax), %edx\n"
        "movl %ecx, %eax\n" /* line 271 */
        "imull %edx, %eax\n"
        "subl $1, %eax\n"
        "je .Lfffc70_0010097f\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 283 */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 284 */
        "divss %xmm1, %xmm0\n"
        "movl 0x60(%edi), %eax\n" /* line 286 */
        "movl %edx, %esi\n"
        "cltd\n"
        "idivl %esi\n"
        "cvtsi2ssl %edx, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "cvtsi2ssl %eax, %xmm4\n" /* line 287 */
        "mulss %xmm0, %xmm4\n"
        "movaps %xmm2, %xmm3\n" /* line 288 */
        "addss %xmm1, %xmm3\n"
        "movaps %xmm0, %xmm5\n" /* line 289 */
        "addss %xmm4, %xmm5\n"
        /* } scope */
        ".Lfffc70_001001f8:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1141 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100960\n"
        "movss 0x64(%edi), %xmm0\n" /* line 1147 */
        "leal 0x48(%edi), %edx\n"
        "leal 0x3c(%edi), %eax\n"
        "movss %xmm5, (%esp)\n"
        "movaps %xmm4, %xmm2\n"
        "movl %ebx, %ecx\n" /* color */
        "calll RB_AddLine\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100228:\n"
        "movss 0x64(%edi), %xmm0\n" /* line 535 */
        "movss %xmm0, -0xc4(%ebp)\n" /* scale */
        "movss 0x68(%edi), %xmm0\n" /* line 536 */
        "movss %xmm0, -0xc0(%ebp)\n" /* scale */
        "pxor %xmm0, %xmm0\n" /* line 538 */
        "ucomiss 0x6c(%edi), %xmm0\n"
        "jne .Lfffc70_0010042e\n"
        "jp .Lfffc70_0010042e\n"
        "leal -0x48(%ebp), %esi\n" /* line 540 | midpoint */
        "movl %esi, 8(%esp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* forward */
        "movl %ebx, 4(%esp)\n"
        "leal 0x14(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MakeNormalVectors\n"
        /* { scope 2: worldOffset */
        "movss -0xc4(%ebp), %xmm0\n" /* line 272 | scale */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "movss %xmm0, -0x3c(%ebp)\n" /* forward */
        "movss -0xc4(%ebp), %xmm0\n" /* line 273 | scale */
        "mulss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n" /* line 274 | scale */
        "mulss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        /* { scope 2: worldOffset */
        "movss -0xc0(%ebp), %xmm0\n" /* line 272 | scale */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "movss %xmm0, -0x48(%ebp)\n" /* midpoint */
        "movss -0xc0(%ebp), %xmm0\n" /* line 273 | scale */
        "mulss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n" /* line 274 | scale */
        "mulss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        ".Lfffc70_001002db:\n"
        "movzbl 0x5b(%edi), %eax\n" /* line 559 */
        "movb %al, -0x30(%ebp)\n" /* worldRadius */
        "movzbl 0x58(%edi), %eax\n" /* line 560 */
        "movb %al, -0x2f(%ebp)\n"
        "movzbl 0x59(%edi), %eax\n" /* line 561 */
        "movb %al, -0x2e(%ebp)\n"
        "movzbl 0x5a(%edi), %eax\n" /* line 562 */
        "movb %al, -0x2d(%ebp)\n"
        /* { scope 2: worldOffset */
        "movl 0x54(%edi), %eax\n" /* line 207 */
        "movzbl 0xe(%eax), %ecx\n" /* line 266 */
        "movzbl 0xf(%eax), %edx\n"
        "movl %ecx, %eax\n" /* line 271 */
        "imull %edx, %eax\n"
        "subl $1, %eax\n"
        "je .Lfffc70_00100d68\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 283 */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 284 */
        "divss %xmm1, %xmm0\n"
        "movl 0x60(%edi), %eax\n" /* line 286 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "cvtsi2ssl %edx, %xmm4\n"
        "mulss %xmm2, %xmm4\n"
        "cvtsi2ssl %eax, %xmm1\n" /* line 287 */
        "mulss %xmm0, %xmm1\n"
        "addss %xmm4, %xmm2\n" /* line 288 */
        "movaps %xmm0, %xmm3\n" /* line 289 */
        "addss %xmm1, %xmm3\n"
        /* } scope */
        ".Lfffc70_0010034e:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 569 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100d4e\n"
        "leal 0x3c(%edi), %eax\n" /* line 575 */
        "movl -0x30(%ebp), %edx\n" /* worldRadius */
        "movl %edx, (%esp)\n"
        "movaps %xmm4, %xmm0\n"
        "movl %esi, %ecx\n"
        "movl %ebx, %edx\n"
        "calll RB_AddQuadStamp\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        ".Lfffc70_00100379:\n"
        "movl %edi, (%esp)\n" /* line 1182 | re */
        "calll RB_TessParticleCloud\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100386:\n"
        "leal 0x3c(%edi), %ebx\n" /* line 945 | from */
        "leal 0x48(%edi), %edx\n" /* line 946 */
        /* { scope 2: worldOffset */
        "movss 0x48(%edi), %xmm0\n" /* line 248 */
        "subss 0x3c(%edi), %xmm0\n"
        "movss 4(%edx), %xmm1\n" /* line 249 */
        "subss 4(%ebx), %xmm1\n"
        "movss 8(%edx), %xmm2\n" /* line 250 */
        "subss 8(%ebx), %xmm2\n"
        /* } scope */
        "mulss %xmm0, %xmm0\n" /* line 81 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm2\n"
        "addss %xmm2, %xmm0\n"
        "sqrtss %xmm0, %xmm1\n"
        "movb 0x5b(%edi), %cl\n" /* line 951 */
        "movzbl 0x58(%edi), %eax\n" /* line 952 */
        "movb %al, %ch\n"
        "movzbl 0x59(%edi), %eax\n" /* line 953 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ecx\n"
        "orl %eax, %ecx\n"
        "movzbl 0x5a(%edi), %eax\n" /* line 954 */
        "shll $0x18, %eax\n"
        "andl $0x00FFFFFF, %ecx\n"
        "orl %eax, %ecx\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 960 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfffc70_00100d1a\n"
        "movl imp_r_railCoreWidth, %eax\n" /* line 966 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss lit4_002ed5c4, %xmm1\n" /* 0.00390625f */
        "movss %xmm1, (%esp)\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movl %ebx, %eax\n" /* b */
        "calll RB_AddLine\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_0010042e:\n"
        "leal -0x48(%ebp), %esi\n" /* line 546 | midpoint */
        "movl %esi, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* screenOffset */
        "movl %eax, 4(%esp)\n"
        "leal 0x14(%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MakeNormalVectors\n"
        "cvtss2sd 0x6c(%edi), %xmm0\n" /* line 548 */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0xbc(%ebp)\n" /* radians */
        /* { scope 2: worldOffset */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm3\n"
        "movss -0xbc(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0xf8(%ebp)\n"
        "calll cosf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm2\n"
        /* } scope */
        "movss -0xc4(%ebp), %xmm0\n" /* line 551 | scale */
        "mulss %xmm2, %xmm0\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm0, %xmm1\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm1\n" /* screenOffset */
        "movss %xmm1, -0x3c(%ebp)\n" /* forward */
        "movaps %xmm0, %xmm1\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm0\n" /* line 274 */
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movss -0xf8(%ebp), %xmm3\n" /* line 552 */
        "movaps %xmm3, %xmm1\n" /* scale */
        "xorps faceAxis+160, %xmm1\n" /* scale */
        "mulss -0xc4(%ebp), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "addss -0x3c(%ebp), %xmm0\n" /* forward */
        "movss %xmm0, -0x3c(%ebp)\n" /* forward */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss -0x34(%ebp), %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        /* } scope */
        "mulss -0xc0(%ebp), %xmm2\n" /* line 554 | scale */
        /* { scope 2: worldOffset */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "movss %xmm0, -0x48(%ebp)\n" /* midpoint */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x40(%ebp), %xmm2\n" /* line 274 */
        /* } scope */
        "mulss -0xc0(%ebp), %xmm3\n" /* line 555 | scale */
        /* { scope 2: worldOffset */
        "movaps %xmm3, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* screenOffset */
        "addss -0x48(%ebp), %xmm0\n" /* midpoint */
        "movss %xmm0, -0x48(%ebp)\n" /* midpoint */
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "mulss -0x1c(%ebp), %xmm3\n" /* line 290 */
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, -0x40(%ebp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* forward */
        "jmp .Lfffc70_001002db\n"
        /* } scope */
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100586:\n"
        "movss 0x68(%edi), %xmm1\n" /* line 468 | screenHeight */
        "leal 0x3c(%edi), %edx\n"
        /* { scope 2: worldOffset */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        "movl imp_backEnd, %eax\n" /* line 368 */
        "movl 0x3c8(%eax), %ecx\n"
        "leal 0xc8(%ecx), %eax\n"
        "movss 0x3c(%edi), %xmm2\n" /* line 371 */
        "mulss 0xc(%eax), %xmm2\n"
        "movss 4(%edx), %xmm0\n"
        "mulss 0x1c(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "movss 8(%edx), %xmm0\n"
        "mulss 0x2c(%eax), %xmm0\n"
        "addss %xmm0, %xmm2\n"
        "addss 0x3c(%eax), %xmm2\n"
        /* } scope */
        /* } scope */
        "ucomiss lit4_002ed5e8, %xmm2\n" /* line 406 | 0.0f */
        "jp .Lfffc70_001005d9\n"
        "jbe .Lfffc70_000ffe08\n"
        ".Lfffc70_001005d9:\n"
        "addss %xmm1, %xmm1\n" /* line 410 */
        "leal 0x108(%ecx), %eax\n"
        "xorl %edx, %edx\n"
        ".Lfffc70_001005e5:\n"
        "movaps %xmm1, %xmm0\n" /* line 415 */
        "mulss 0x10(%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp, %edx, 4)\n"
        "addl $1, %edx\n" /* line 414 */
        "addl $4, %eax\n"
        "cmpl $3, %edx\n"
        "jne .Lfffc70_001005e5\n"
        "leal 0x24(%ecx), %eax\n" /* line 417 */
        "movss -0x30(%ebp), %xmm1\n" /* line 418 | worldRadius */
        "mulss 0x24(%ecx), %xmm1\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x28(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        /* } scope */
        /* } scope */
        "movss %xmm1, -0x24(%ebp)\n" /* line 472 | screenOffset */
        "leal -0x24(%ebp), %edx\n" /* line 474 | screenOffset */
        "movl %edi, %eax\n"
        "calll RB_BuildSprite\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100644:\n"
        "cmpl $0x20, %ecx\n" /* line 613 */
        "jle .Lfffc70_00100d7f\n"
        "movl $0xc0, %esi\n"
        "movl $0x40, -0x60(%ebp)\n"
        "movl $0x42000000, -0x5c(%ebp)\n"
        "movl -0x60(%ebp), %edx\n"
        "jmp .Lfffc70_000fff39\n"
        ".Lfffc70_00100668:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfffc70_000fffaf\n"
        ".Lfffc70_00100672:\n"
        "movl -0x80(%ebp), %esi\n" /* line 642 | vert */
        "movl %esi, %ecx\n" /* line 1151 */
        "addl $0x40, %ecx\n"
        "movl %ecx, -0xdc(%ebp)\n"
        "movl %esi, %ebx\n" /* color */
        "addl $0x60, %ebx\n" /* color */
        "movl %ebx, -0x4c(%ebp)\n" /* color */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movl $0, -0x88(%ebp)\n" /* segmentX2 */
        "jmp .Lfffc70_001006a6\n"
        ".Lfffc70_001006a3:\n"
        "movaps %xmm1, %xmm2\n" /* line 635 */
        ".Lfffc70_001006a6:\n"
        "movaps %xmm2, %xmm1\n" /* line 637 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm0\n" /* worldRadius */
        "movl -0x78(%ebp), %eax\n" /* a */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movl -0x74(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "movl -0x6c(%ebp), %ecx\n"
        "addss (%ecx), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 638 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* screenOffset */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%esi), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movl $0x3f800000, 0xc(%esi)\n" /* line 639 */
        "movss %xmm4, 0x20(%esi)\n" /* line 640 */
        "movl $0x3f800000, 0x24(%esi)\n" /* line 641 */
        "movl -0xd0(%ebp), %ebx\n" /* line 642 | mtlColor */
        "movl %ebx, 0x1c(%esi)\n"
        "movl -0x88(%ebp), %edx\n" /* line 644 | segmentX2 */
        "shll $6, %edx\n"
        "movl -0x80(%ebp), %eax\n" /* vert */
        "addl %edx, %eax\n"
        "leal 0x40(%eax), %ecx\n" /* result */
        "movaps %xmm2, %xmm1\n" /* scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x30(%ebp), %xmm0\n" /* worldRadius */
        "movl -0x7c(%ebp), %ebx\n" /* b */
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, 0x40(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x2c(%ebp), %xmm0\n"
        "movl -0x70(%ebp), %ebx\n"
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, 0x44(%eax)\n"
        "mulss -0x28(%ebp), %xmm1\n" /* line 290 */
        "movl -0x68(%ebp), %ebx\n"
        "addss (%ebx), %xmm1\n"
        "movss %xmm1, 0x48(%eax)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 645 | scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x24(%ebp), %xmm0\n" /* screenOffset */
        "addss 0x40(%eax), %xmm0\n"
        "movss %xmm0, 0x40(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x20(%ebp), %xmm0\n"
        "addss 4(%ecx), %xmm0\n"
        "movss %xmm0, 0x44(%eax)\n"
        "mulss -0x1c(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%ecx), %xmm1\n"
        "movss %xmm1, 0x48(%eax)\n"
        /* } scope */
        "addl -0xdc(%ebp), %edx\n" /* line 646 */
        "movl $0x3f800000, 0xc(%edx)\n"
        "movl -0x4c(%ebp), %eax\n" /* line 647 */
        "movss %xmm4, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 648 */
        "movl -0xd0(%ebp), %ecx\n" /* line 649 | mtlColor */
        "movl %ecx, 0x1c(%edx)\n"
        "addss -0x8c(%ebp), %xmm4\n" /* line 651 | sDelta */
        "movaps %xmm2, %xmm1\n" /* line 652 */
        "mulss %xmm5, %xmm1\n"
        "movss -0x84(%ebp), %xmm0\n" /* sinAngleDelta */
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm3\n" /* line 653 */
        "mulss -0x84(%ebp), %xmm2\n" /* sinAngleDelta */
        "subss %xmm2, %xmm3\n"
        "movl -0x88(%ebp), %ecx\n" /* segmentX2 */
        "movl imp_tess, %eax\n" /* line 656 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x120(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x120(%ebp), %eax\n"
        "movw %dx, (%eax, %ebx, 2)\n"
        "movl imp_tess, %edx\n" /* line 657 */
        "movl 0x5a7d0(%edx), %ebx\n"
        "movl 0x5a7b0(%edx), %eax\n"
        "movl %eax, -0x124(%ebp)\n"
        "movzwl 0x5a7d4(%edx), %eax\n"
        "addl %ecx, %eax\n"
        "movw %ax, -0xfe(%ebp)\n"
        "addl $1, %eax\n"
        "movl -0x124(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl imp_tess, %eax\n" /* line 658 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x128(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x128(%ebp), %edx\n"
        "movw %ax, 4(%edx, %ebx, 2)\n"
        "movl imp_tess, %eax\n" /* line 659 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "addl $3, %ebx\n"
        "movl %ebx, 0x5a7d0(%eax)\n"
        "movl 0x5a7b0(%eax), %edx\n" /* line 661 */
        "movl %edx, -0x12c(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x12c(%ebp), %edx\n"
        "movw %ax, (%edx, %ebx, 2)\n"
        "movl imp_tess, %eax\n" /* line 662 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x130(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $2, %eax\n"
        "movl -0x130(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl imp_tess, %ebx\n" /* line 663 */
        "movl 0x5a7d0(%ebx), %edx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "addw 0x5a7d4(%ebx), %cx\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "addl $3, 0x5a7d0(%ebx)\n" /* line 664 */
        "addl $2, -0x88(%ebp)\n" /* line 635 | segmentX2 */
        "subl $-0x80, %esi\n"
        "subl $-0x80, -0x4c(%ebp)\n"
        "movl -0x88(%ebp), %eax\n" /* segmentX2 */
        "cmpl %eax, -0x60(%ebp)\n"
        "jg .Lfffc70_001006a3\n"
        "jmp .Lfffc70_001000e6\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100960:\n"
        "movss 0x64(%edi), %xmm0\n" /* line 1143 */
        "leal 0x48(%edi), %edx\n"
        "leal 0x3c(%edi), %eax\n"
        "movss %xmm5, (%esp)\n"
        "movaps %xmm4, %xmm2\n"
        "movl %ebx, %ecx\n" /* color */
        "calll RB_AddLineDx7\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 2: worldOffset */
        ".Lfffc70_0010097f:\n"
        "movss lit4_002ed5d0, %xmm3\n" /* line 271 | 1.0f */
        "movaps %xmm3, %xmm5\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm1, %xmm4\n"
        "jmp .Lfffc70_001001f8\n"
        /* } scope */
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100996:\n"
        "leal 0x48(%edi), %eax\n" /* line 702 */
        "movl %eax, -0xa8(%ebp)\n" /* b */
        "leal 0x3c(%edi), %edx\n"
        "movl %edx, -0xa4(%ebp)\n" /* a */
        /* { scope 2: worldOffset */
        "movss 0x3c(%edi), %xmm2\n" /* line 256 */
        "addss 0x48(%edi), %xmm2\n"
        "movss lit4_002ed5d8, %xmm3\n" /* 0.5f */
        "mulss %xmm3, %xmm2\n"
        "leal 0x40(%edi), %ecx\n" /* line 257 */
        "movl %ecx, -0xa0(%ebp)\n"
        "leal 0x4c(%edi), %ebx\n"
        "movl %ebx, -0x9c(%ebp)\n"
        "movss 0x40(%edi), %xmm1\n"
        "addss 0x4c(%edi), %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "leal 0x44(%edi), %esi\n" /* line 258 */
        "movl %esi, -0x98(%ebp)\n"
        "leal 0x50(%edi), %eax\n"
        "movl %eax, -0x94(%ebp)\n"
        "movss 0x44(%edi), %xmm0\n"
        "addss 0x50(%edi), %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        /* } scope */
        "movl imp_backEnd, %ebx\n" /* line 248 */
        "subss 0x3cc(%ebx), %xmm2\n"
        "movss %xmm2, -0x24(%ebp)\n" /* screenOffset */
        "subss 0x3d0(%ebx), %xmm1\n" /* line 249 */
        "movss %xmm1, -0x20(%ebp)\n"
        "subss 0x3d4(%ebx), %xmm0\n" /* line 250 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 704 | screenOffset */
        "movl %eax, (%esp)\n"
        "movss %xmm3, -0xf8(%ebp)\n"
        "calll Vec3Normalize\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm0\n"
        "mulss 0x3d8(%ebx), %xmm0\n" /* line 428 */
        "addss 0x3dc(%ebx), %xmm0\n"
        "mulss lit4_002ed890, %xmm0\n" /* -0.0009765625f */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "mulss lit4_002ed830, %xmm0\n" /* 32.0f */
        "movss -0xf8(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xd4(%ebp)\n"
        "cvttss2si -0xd4(%ebp), %ecx\n"
        "cmpl $7, %ecx\n" /* line 709 */
        "jg .Lfffc70_00100d99\n"
        "movl $0x30, %esi\n"
        "movl $0x10, -0x58(%ebp)\n"
        "movss lit4_002ed740, %xmm0\n" /* 8.0f */
        "movss %xmm0, -0x54(%ebp)\n"
        "movl -0x58(%ebp), %edx\n"
        ".Lfffc70_00100abd:\n"
        "movl imp_tess, %ebx\n" /* line 344 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "leal 2(%edx, %eax), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfffc70_00100ae2\n"
        "addl 0x5a7d0(%ebx), %esi\n"
        "cmpl $0x100000, %esi\n"
        "jle .Lfffc70_00100b3e\n"
        ".Lfffc70_00100ae2:\n"
        "movl 0x5a7cc(%ebx), %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%ebx), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%ebx), %esi\n" /* line 310 */
        "je .Lfffc70_00100b3e\n"
        "movl 0x5a7d0(%ebx), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfffc70_00100d10\n"
        "movl 0x5a7e0(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfffc70_00100d10\n"
        ".Lfffc70_00100b33:\n"
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %esi, 0x5a7cc(%eax)\n"
        ".Lfffc70_00100b3e:\n"
        "movl -0xa4(%ebp), %ecx\n" /* line 248 | a */
        "movss (%ecx), %xmm0\n"
        "movl -0xa8(%ebp), %ebx\n" /* b */
        "subss (%ebx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* worldRadius */
        "movl -0xa0(%ebp), %esi\n" /* line 249 */
        "movss (%esi), %xmm0\n"
        "movl -0x9c(%ebp), %eax\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl -0x98(%ebp), %edx\n" /* line 250 */
        "movss (%edx), %xmm0\n"
        "movl -0x94(%ebp), %ecx\n"
        "subss (%ecx), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 718 | worldRadius */
        "movl %ebx, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x48(%ebp), %eax\n" /* line 719 | midpoint */
        "movl %eax, 8(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* forward */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MakeNormalVectors\n"
        "movl imp_tess, %ebx\n" /* line 721 */
        "movl 0x5a7d4(%ebx), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%ebx, %eax, 4), %eax\n"
        "movl %eax, -0xac(%ebp)\n" /* vert */
        "leal 0x58(%edi), %edx\n" /* line 723 | rgbaFrom */
        "movzbl 1(%edx), %ecx\n"
        /* { scope 2: worldOffset */
        "movzbl 0x58(%edi), %eax\n" /* line 655 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, -0xcc(%ebp)\n" /* mtlColor */
        "orl %eax, -0xcc(%ebp)\n" /* mtlColor */
        "movl -0xcc(%ebp), %eax\n" /* line 656 | mtlColor */
        "movb %cl, %ah\n"
        "movl %eax, -0xcc(%ebp)\n" /* mtlColor */
        "movb 2(%edx), %al\n" /* line 657 */
        "movl %eax, -0xcc(%ebp)\n" /* mtlColor */
        "movzbl 3(%edx), %eax\n" /* line 658 */
        "shll $0x18, %eax\n"
        "andl $0x00FFFFFF, -0xcc(%ebp)\n" /* mtlColor */
        "orl %eax, -0xcc(%ebp)\n" /* mtlColor */
        /* } scope */
        "movss lit4_002ed5d0, %xmm0\n" /* line 725 | 1.0f */
        "divss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, -0xb8(%ebp)\n" /* sDelta */
        "cvtss2sd %xmm0, %xmm0\n" /* line 729 */
        "mulsd lit8_00307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n" /* radians */
        /* { scope 2: worldOffset */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0xb0(%ebp)\n" /* sinAngleDelta */
        "movss -0x90(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm5\n"
        /* } scope */
        "movl -0x58(%ebp), %eax\n" /* line 733 */
        "testl %eax, %eax\n"
        "jg .Lfffc70_00100dbd\n"
        "xorl %eax, %eax\n"
        ".Lfffc70_00100c7a:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 763 */
        "movl -0xac(%ebp), %edx\n" /* vert */
        "leal (%edx, %eax, 4), %eax\n"
        "movl %edx, %ecx\n" /* line 199 */
        "movl (%edx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 200 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 201 */
        "movl %edx, 8(%eax)\n"
        "movl $0x3f800000, 0x1c(%eax)\n" /* line 764 */
        "movl $0x3f800000, 0x20(%eax)\n" /* line 765 */
        "movl -0xcc(%ebp), %ebx\n" /* line 766 | mtlColor */
        "movl %ebx, 0x18(%eax)\n"
        "leal 0x24(%eax), %ecx\n" /* line 768 */
        "movl -0xac(%ebp), %ebx\n" /* vert, from */
        "addl $0x24, %ebx\n" /* from */
        /* { scope 2: worldOffset */
        "movl -0xac(%ebp), %esi\n" /* line 199 | vert */
        "movl 0x24(%esi), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl $0x3f800000, 0x1c(%ecx)\n" /* line 769 */
        "movl $0, 0x20(%ecx)\n" /* line 770 */
        "movl -0xcc(%ebp), %eax\n" /* line 771 | mtlColor */
        "movl %eax, 0x18(%ecx)\n"
        "movl imp_tess, %edx\n" /* line 773 */
        "movl 0x5a7d4(%edx), %edx\n"
        "addl %edx, -0x58(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "addl $2, %eax\n"
        "movl imp_tess, %ecx\n"
        "movl %eax, 0x5a7d4(%ecx)\n"
        "jmp .Lfffc70_000ffe08\n"
        ".Lfffc70_00100d10:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfffc70_00100b33\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d1a:\n"
        "movl imp_r_railCoreWidth, %eax\n" /* line 962 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss lit4_002ed5c4, %xmm1\n" /* 0.00390625f */
        "movss %xmm1, (%esp)\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm1\n"
        "movl %ebx, %eax\n" /* b */
        "calll RB_AddLineDx7\n"
        "jmp .Lfffc70_000ffe08\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d4e:\n"
        "leal 0x3c(%edi), %eax\n" /* line 571 */
        "movl -0x30(%ebp), %edx\n" /* worldRadius */
        "movl %edx, (%esp)\n"
        "movaps %xmm4, %xmm0\n"
        "movl %esi, %ecx\n"
        "movl %ebx, %edx\n"
        "calll RB_AddQuadStampDx7\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 2: worldOffset */
        ".Lfffc70_00100d68:\n"
        "movss lit4_002ed5d0, %xmm2\n" /* line 271 | 1.0f */
        "movaps %xmm2, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        "jmp .Lfffc70_0010034e\n"
        /* } scope */
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d7f:\n"
        "leal (%ecx, %ecx), %edx\n" /* line 613 */
        "leal (%edx, %ecx), %eax\n"
        "leal (%eax, %eax), %esi\n"
        "movl %edx, -0x60(%ebp)\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "jmp .Lfffc70_000fff39\n"
        /* } scope */
        /* { scope 1: from, screenOffset, b, a, ... */
        ".Lfffc70_00100d99:\n"
        "cmpl $0x20, %ecx\n" /* line 711 */
        "jle .Lfffc70_00101099\n"
        "movl $0xc0, %esi\n"
        "movl $0x40, -0x58(%ebp)\n"
        "movl $0x42000000, -0x54(%ebp)\n"
        "movl -0x58(%ebp), %edx\n"
        "jmp .Lfffc70_00100abd\n"
        ".Lfffc70_00100dbd:\n"
        "movl -0xac(%ebp), %esi\n" /* line 739 | vert */
        "movl %esi, %eax\n"
        "addl $0x40, %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "pxor %xmm2, %xmm2\n"
        "movaps %xmm2, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movl $0, -0xb4(%ebp)\n" /* segmentX2 */
        "jmp .Lfffc70_00100de9\n"
        ".Lfffc70_00100de6:\n"
        "movaps %xmm1, %xmm2\n" /* line 733 */
        ".Lfffc70_00100de9:\n"
        "movaps %xmm2, %xmm1\n" /* line 735 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "movl -0xa4(%ebp), %edx\n" /* a */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x38(%ebp), %xmm0\n"
        "movl -0xa0(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "movl -0x98(%ebp), %ebx\n"
        "addss (%ebx), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 736 | scale */
        "mulss 0x68(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "addss (%esi), %xmm0\n"
        "movss %xmm0, (%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%esi), %xmm1\n"
        "movss %xmm1, 8(%esi)\n"
        /* } scope */
        "movss %xmm4, 0x1c(%esi)\n" /* line 737 */
        "movl $0x3f800000, 0x20(%esi)\n" /* line 738 */
        "movl -0xcc(%ebp), %eax\n" /* line 739 | mtlColor */
        "movl %eax, 0x18(%esi)\n"
        "leal 0x24(%esi), %eax\n" /* line 741 | result */
        "movaps %xmm2, %xmm1\n" /* scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x3c(%ebp), %xmm0\n" /* forward */
        "movl -0xa8(%ebp), %edx\n" /* b */
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x38(%ebp), %xmm0\n"
        "movl -0x9c(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 0x28(%esi)\n"
        "mulss -0x34(%ebp), %xmm1\n" /* line 290 */
        "movl -0x94(%ebp), %ebx\n"
        "addss (%ebx), %xmm1\n"
        "movss %xmm1, 0x2c(%esi)\n"
        /* } scope */
        "movaps %xmm3, %xmm1\n" /* line 742 | scale */
        "mulss 0x64(%edi), %xmm1\n" /* scale */
        /* { scope 2: worldOffset */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss -0x48(%ebp), %xmm0\n" /* midpoint */
        "addss 0x24(%esi), %xmm0\n"
        "movss %xmm0, 0x24(%esi)\n"
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss -0x44(%ebp), %xmm0\n"
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, 0x28(%esi)\n"
        "mulss -0x40(%ebp), %xmm1\n" /* line 290 */
        "addss 8(%eax), %xmm1\n"
        "movss %xmm1, 0x2c(%esi)\n"
        /* } scope */
        "movl -0x50(%ebp), %eax\n" /* line 743 */
        "movss %xmm4, (%eax)\n"
        "movl $0, 4(%eax)\n" /* line 744 */
        "movl -0xcc(%ebp), %edx\n" /* line 745 | mtlColor */
        "movl %edx, -4(%eax)\n"
        "addss -0xb8(%ebp), %xmm4\n" /* line 747 | sDelta */
        "movaps %xmm2, %xmm1\n" /* line 748 */
        "mulss %xmm5, %xmm1\n"
        "movss -0xb0(%ebp), %xmm0\n" /* sinAngleDelta */
        "mulss %xmm3, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm3\n" /* line 749 */
        "mulss -0xb0(%ebp), %xmm2\n" /* sinAngleDelta */
        "subss %xmm2, %xmm3\n"
        "movl -0xb4(%ebp), %ecx\n" /* segmentX2 */
        "movl imp_tess, %eax\n" /* line 752 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x10c(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl -0x10c(%ebp), %eax\n"
        "movw %dx, (%eax, %ebx, 2)\n"
        "movl imp_tess, %edx\n" /* line 753 */
        "movl 0x5a7d0(%edx), %ebx\n"
        "movl 0x5a7b0(%edx), %eax\n"
        "movl %eax, -0x110(%ebp)\n"
        "movzwl 0x5a7d4(%edx), %eax\n"
        "addl %ecx, %eax\n"
        "movw %ax, -0xfe(%ebp)\n"
        "addl $1, %eax\n"
        "movl -0x110(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl imp_tess, %eax\n" /* line 754 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x114(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x114(%ebp), %edx\n"
        "movw %ax, 4(%edx, %ebx, 2)\n"
        "movl imp_tess, %eax\n" /* line 755 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "addl $3, %ebx\n"
        "movl %ebx, 0x5a7d0(%eax)\n"
        "movl 0x5a7b0(%eax), %edx\n" /* line 757 */
        "movl %edx, -0x118(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $3, %eax\n"
        "movl -0x118(%ebp), %edx\n"
        "movw %ax, (%edx, %ebx, 2)\n"
        "movl imp_tess, %eax\n" /* line 758 */
        "movl 0x5a7d0(%eax), %ebx\n"
        "movl 0x5a7b0(%eax), %edx\n"
        "movl %edx, -0x11c(%ebp)\n"
        "movzwl 0x5a7d4(%eax), %edx\n"
        "addl %ecx, %edx\n"
        "movl %edx, %eax\n"
        "addl $2, %eax\n"
        "movl -0x11c(%ebp), %edx\n"
        "movw %ax, 2(%edx, %ebx, 2)\n"
        "movl imp_tess, %ebx\n" /* line 759 */
        "movl 0x5a7d0(%ebx), %edx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "addw 0x5a7d4(%ebx), %cx\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "addl $3, 0x5a7d0(%ebx)\n" /* line 760 */
        "addl $2, -0xb4(%ebp)\n" /* line 733 | segmentX2 */
        "addl $0x48, %esi\n"
        "addl $0x48, -0x50(%ebp)\n"
        "movl -0x58(%ebp), %eax\n"
        "cmpl %eax, -0xb4(%ebp)\n" /* segmentX2 */
        "jl .Lfffc70_00100de6\n"
        "movl -0xb4(%ebp), %eax\n" /* segmentX2 */
        "jmp .Lfffc70_00100c7a\n"
        ".Lfffc70_00101099:\n"
        "leal (%ecx, %ecx), %edx\n" /* line 711 */
        "leal (%edx, %ecx), %eax\n"
        "leal (%eax, %eax), %esi\n"
        "movl %edx, -0x58(%ebp)\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n"
        "jmp .Lfffc70_00100abd\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_ffc70_0:\n"
        ".long .Lfffc70_000ffc98\n"
        ".long .Lfffc70_00100386\n"
        ".long .Lfffc70_00100379\n"
        ".long .Lfffc70_00100228\n"
        ".long .Lfffc70_00100177\n"
        ".long .Lfffc70_000ffe13\n"
        ".text\n"
    );
}

/* line 1193 */
void RB_TessBackEndEntity(const surfaceType_t *surfType)
{
    RB_TessEntity((const GfxEntity *)*(void **)((byte *)(void *)imp_backEnd + 0x440));
}

/* line 75 */
void RB_TessPoly(const surfaceType_t *surfType)
{
    char *tess;
    int sortedIndex;
    int vertCount;
    int indexCount;
    int vertBase;
    int i;
    int triCount;
    char *dxCaps;
    char *src;
    char *dest;
    unsigned short *indices;

    tess = RB_TessBase();

    /* Check if sorted index matches (poly mode = 1) */
    if (*(int *)(tess + 0x5a7cc) != 1) {
        if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
            RB_EndSurface();
        }
        tess = RB_TessBase();
        *(int *)(tess + 0x5a7cc) = 1;
    }

    vertCount = (int)*(unsigned short *)((byte *)surfType + 0xa);
    indexCount = vertCount * 3 - 6;

    /* RB_CheckOverflow */
    if (vertCount + *(int *)(tess + 0x5a7d4) > 0x154a ||
        indexCount + *(int *)(tess + 0x5a7d0) > 0x100000) {
        sortedIndex = *(int *)(tess + 0x5a7cc);
        RB_EndSurface();
        tess = RB_TessBase();
        RB_BeginSurface(
            *(const Material **)(tess + 0x5a7bc),
            *(MaterialTechniqueType *)(tess + 0x5a7c0),
            *(int *)(tess + 0x5a7c4));
        tess = RB_TessBase();
        if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                RB_EndSurface();
            }
            tess = RB_TessBase();
            *(int *)(tess + 0x5a7cc) = sortedIndex;
            vertCount = (int)*(unsigned short *)((byte *)surfType + 0xa);
        }
    }

    /* Check DX level for vertex copy method */
    dxCaps = *(char **)imp_r_rendererInUse;
    dxCaps = *(char **)dxCaps;

    if (*(int *)(dxCaps + 8) == 2) {
        /* DX7 mode: per-vertex copy, dest stride = 32, src stride = 0x44 */
        src = *(char **)((byte *)surfType + 0xc);
        for (i = 0; i < vertCount; i++) {
            char *srcVert = src + i * 0x44;
            tess = RB_TessBase();
            vertBase = *(int *)(tess + 0x5a7d4);
            dest = tess + (vertBase + i) * 32;

            /* Copy position (vec3 = 12 bytes) */
            *(int *)(dest + 0) = *(int *)(srcVert + 0);
            *(int *)(dest + 4) = *(int *)(srcVert + 4);
            *(int *)(dest + 8) = *(int *)(srcVert + 8);

            /* Copy D3DCOLOR (4 bytes at src+0x18 -> dest+0xc) */
            *(int *)(dest + 0xc) = *(int *)(srcVert + 0x18);

            /* Copy texcoord set 1 (8 bytes at src+0x1c -> dest+0x10) */
            *(int *)(dest + 0x10) = *(int *)(srcVert + 0x1c);
            *(int *)(dest + 0x14) = *(int *)(srcVert + 0x20);

            /* Copy texcoord set 2 (8 bytes at src+0x24 -> dest+0x18) */
            *(int *)(dest + 0x18) = *(int *)(srcVert + 0x24);
            *(int *)(dest + 0x1c) = *(int *)(srcVert + 0x28);
        }
    } else {
        /* DX9 mode: memcpy with stride 68 (0x44) */
        tess = RB_TessBase();
        vertBase = *(int *)(tess + 0x5a7d4);
        dest = tess + vertBase * 68;
        src = *(char **)((byte *)surfType + 0xc);
        memcpy(dest, src, vertCount * 68);
    }

    /* Generate triangle fan indices */
    triCount = vertCount - 2;
    if (triCount > 0) {
        tess = RB_TessBase();
        for (i = 0; i < triCount; i++) {
            int idxOff = *(int *)(tess + 0x5a7d0);
            indices = (unsigned short *)(*(char **)(tess + 0x5a7b0) + idxOff * 2);
            vertBase = *(unsigned short *)(tess + 0x5a7d4);

            indices[0] = (unsigned short)vertBase;
            indices[1] = (unsigned short)(i + vertBase + 1);
            indices[2] = (unsigned short)(i + vertBase + 2);
            *(int *)(tess + 0x5a7d0) += 3;
        }
    }

    /* Update vertex count */
    vertCount = (int)*(unsigned short *)((byte *)surfType + 0xa);
    tess = RB_TessBase();
    *(int *)(tess + 0x5a7d4) += vertCount;
}

/* line 1485 */
void RB_TessStaticModelCached(const surfaceType_t *surfType)
{
    char *tess;
    int triIndexCount;
    int sortedIndex;
    int baseVertIndex;
    char *dest;
    char *src;

    /* surfType[1] is a pointer (XSurface*), triCount is signed short at offset 4 */
    triIndexCount = (int)(*(short *)((byte *)*(void **)((byte *)surfType + 4) + 4)) * 3;

    tess = RB_TessBase();

    /* RB_CheckOverflow for cached triangles */
    if (triIndexCount + *(int *)(tess + 0x5a7e0) > 0x100000) {
        sortedIndex = *(int *)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(
            *(const Material **)(tess + 0x5a7bc),
            *(MaterialTechniqueType *)(tess + 0x5a7c0),
            *(int *)(tess + 0x5a7c4));
        tess = RB_TessBase();
        if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                RB_EndSurface();
                tess = RB_TessBase();
            }
            *(int *)(tess + 0x5a7cc) = sortedIndex;
        }
    }

    /* Set cached mode */
    *(int *)(tess + 0x5a7b8) = 2;
    *(int *)(tess + 0x5a7e8) = 0;
    *(int *)(tess + 0x5a7e4) = 0x10000;

    /* Compute dest and update triIndexCount */
    baseVertIndex = *(int *)(tess + 0x5a7e0);
    dest = *(char **)(tess + 0x5a7b4) + baseVertIndex * 2;
    *(int *)(tess + 0x5a7e0) = baseVertIndex + triIndexCount;

    /* Copy cached triangle data from DxGlobals static model cache */
    src = *(char **)((char *)imp_dx + 0x2dc8) + *(int *)(*(void **)((byte *)surfType + 8)) * 12;
    Com_Memcpy(dest, src, triIndexCount * 2);
}

/* line 1367 */
void RB_TessXModelSkinned(const surfaceType_t *surfType)
{
    GfxModelSkinnedSurface *skinSurf = (GfxModelSkinnedSurface *)surfType;
    XSurface *xsurf;
    char *tess;
    char *backEndData;
    char *dxCaps;
    int vertexStride;
    GfxDrawPrimArgs args;
    IDirect3DVertexBuffer9 *vb;
    int sortedIndex;
    int vertexCount;
    int triIndexCount;
    int vertBase;
    int isDx7;

    xsurf = skinSurf->surf.xsurf;

    /* Check if skinnedCachedOffset >= 0 (hardware skinning path) */
    if (skinSurf->skinnedCachedOffset >= 0) {
        /* Hardware skinning path: use pre-computed buffers */
        tess = RB_TessBase();

        /* Flush if surface has existing data */
        if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
            RB_EndSurface();
        }

        /* Determine vertex stride based on DX level */
        dxCaps = *(char **)imp_r_rendererInUse;
        dxCaps = *(char **)dxCaps;
        isDx7 = (*(int *)(dxCaps + 8) == 2);
        vertexStride = isDx7 ? 0x24 : 0x40;

        /* Set up draw prim args */
        args.u.buf.baseIndex = 0;
        args.u.buf.baseVertex = skinSurf->skinnedCachedOffset / vertexStride;
        args.firstVertexFromBase = 0;
        args.vertexCount = (int)xsurf->vertCount;
        args.primCount = (int)xsurf->triCount;

        /* Change index buffer if needed */
        backEndData = (char *)imp_dxState;
        if (xsurf->indexBuffer != *(IDirect3DIndexBuffer9 **)(backEndData + 0x20cc)) {
            RB_ChangeIndices(xsurf->indexBuffer);
        }

        /* Get skinned vertex buffer from viewParms */
        vb = *(IDirect3DVertexBuffer9 **)((byte *)*(void **)((char *)imp_backEndData) + 0x217c78 + 8);

        /* Change stream source if needed */
        if (vb != *(IDirect3DVertexBuffer9 **)(backEndData + 0x20d0) ||
            *(int *)(backEndData + 0x20d4) != 0 ||
            *(int *)(backEndData + 0x20d8) != vertexStride) {
            RB_ChangeStreamSource(0, vb, 0, vertexStride);
        }

        RB_DrawTechnique(0, &args);
    } else {
        /* Software skinning path: copy vertex data into tess buffer */
        vertexCount = XSurfaceGetNumVerts(xsurf);
        triIndexCount = XSurfaceGetNumTris(xsurf) * 3;

        /* RB_CheckOverflow */
        tess = RB_TessBase();
        if (vertexCount + *(int *)(tess + 0x5a7d4) > 0x154a ||
            triIndexCount + *(int *)(tess + 0x5a7d0) > 0x100000) {
            sortedIndex = *(int *)(tess + 0x5a7cc);
            RB_EndSurface();
            tess = RB_TessBase();
            RB_BeginSurface(
                *(const Material **)(tess + 0x5a7bc),
                *(MaterialTechniqueType *)(tess + 0x5a7c0),
                *(int *)(tess + 0x5a7c4));
            tess = RB_TessBase();
            if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
                if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                    RB_EndSurface();
                }
                tess = RB_TessBase();
                *(int *)(tess + 0x5a7cc) = sortedIndex;
            }
        }

        /* Flush if index count is odd (alignment issue) */
        if (*(int *)(tess + 0x5a7d0) & 1) {
            sortedIndex = *(int *)(tess + 0x5a7cc);
            RB_EndSurface();
            tess = RB_TessBase();
            RB_BeginSurface(
                *(const Material **)(tess + 0x5a7bc),
                *(MaterialTechniqueType *)(tess + 0x5a7c0),
                *(int *)(tess + 0x5a7c4));
            tess = RB_TessBase();
            if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
                if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                    RB_EndSurface();
                }
                tess = RB_TessBase();
                *(int *)(tess + 0x5a7cc) = sortedIndex;
            }
        }

        /* Copy vertex data into tess buffer */
        vertBase = *(unsigned short *)(tess + 0x5a7d4);
        dxCaps = *(char **)imp_r_rendererInUse;
        dxCaps = *(char **)dxCaps;

        if (*(int *)(dxCaps + 8) == 2) {
            /* DX7 mode: vertex size = 0x24 (36 bytes), stride = vertCount * 36 */
            Com_Memcpy(tess + vertBase * 36, (void *)skinSurf->skinnedVert.variant, vertexCount * 36);
        } else {
            /* DX9 mode: vertex size = 0x40 (64 bytes), stride = vertCount * 64 */
            Com_Memcpy(tess + vertBase * 64, (void *)skinSurf->skinnedVert.variant, vertexCount * 64);
        }

        /* Update vertex count */
        tess = RB_TessBase();
        *(int *)(tess + 0x5a7d4) += vertexCount;

        /* Copy triangle indices with vertex offset */
        XSurfaceGetTris(xsurf,
            (r_index_t *)(*(char **)(tess + 0x5a7b0) + *(int *)(tess + 0x5a7d0) * 2),
            vertBase);

        /* Update index count */
        *(int *)(tess + 0x5a7d0) += triIndexCount;
    }
}

/* line 1553 */
int g_tt_last_cached = -1;
void *g_tt_last_tess = 0;
int g_tt_seq = 0;
int g_tt_last_seq = 0;
void RB_TessTriangles(const surfaceType_t *surfType)
{
    char *tess;
    int sortedIndex;
    srfTriangles_t *tri = (srfTriangles_t *)surfType;

    tess = RB_TessBase();

    /* Check if we need to flush existing cached data due to buffer mismatch */
    if (*(int *)(tess + 0x5a7e0) != 0) {
        if (*(int *)(tess + 0x5a7e8) != tri->firstVertex ||
            *(int *)(tess + 0x5a7e4) != (int)tri->vertexCount) {
            /* Buffer mismatch - flush and restart */
            sortedIndex = *(int *)(tess + 0x5a7cc);
            RB_EndSurface();
            RB_BeginSurface(
                *(const Material **)(tess + 0x5a7bc),
                *(MaterialTechniqueType *)(tess + 0x5a7c0),
                *(int *)(tess + 0x5a7c4));
            if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
                if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                    RB_EndSurface();
                }
                tess = RB_TessBase();
                *(int *)(tess + 0x5a7cc) = sortedIndex;
            }
        }
    }

    /* Check overflow for cached indices */
    if ((int)tri->indexCount + *(int *)(tess + 0x5a7e0) > 0x100000) {
        sortedIndex = *(int *)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(
            *(const Material **)(tess + 0x5a7bc),
            *(MaterialTechniqueType *)(tess + 0x5a7c0),
            *(int *)(tess + 0x5a7c4));
        tess = RB_TessBase();
        if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                RB_EndSurface();
                tess = RB_TessBase();
            }
            *(int *)(tess + 0x5a7cc) = sortedIndex;
        }
    }

    /* Set triangle mode */
    *(int *)(tess + 0x5a7b8) = 1;

    /* diagnostic: log first few TessTriangles calls */
    {
        static int tess_tri_diag = 0;
        if (tess_tri_diag < 20) {
            fprintf(stderr, "[TessTri#%d] ic=%d vc=%d fv=%d tess=%p cached_before=%d\n",
                    tess_tri_diag, (int)tri->indexCount, (int)tri->vertexCount,
                    tri->firstVertex, (void *)tess, *(int *)(tess + 0x5a7e0));
            tess_tri_diag++;
        }
    }

    /* Copy index data */
    Com_Memcpy(
        *(char **)(tess + 0x5a7b4) + *(int *)(tess + 0x5a7e0) * 2,
        (void *)tri->indices,
        (int)tri->indexCount * 2);

    /* Update state */
    {
        int *cached_ptr = (int *)(tess + 0x5a7e0);
        *cached_ptr += (int)tri->indexCount;
        g_tt_last_cached = *cached_ptr;
        g_tt_last_tess = tess;
        g_tt_last_seq = ++g_tt_seq;
        {
            static int ttwaddr = 0;
            if (ttwaddr < 3) {
                fprintf(stderr, "[TT-WRITE#%d] ptr=%p val=%d ic=%d tess=%p\n",
                        ttwaddr, (void *)cached_ptr, *cached_ptr, (int)tri->indexCount, (void *)tess);
                ttwaddr++;
            }
        }
    }
    *(int *)(tess + 0x5a7e8) = tri->firstVertex;
    *(int *)(tess + 0x5a7e4) = (int)tri->vertexCount;
}
