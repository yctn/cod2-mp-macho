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

void RB_TessBad(const surfaceType_t *surfType);
void RB_TessParticleCloud(const GfxEntity *re);
void RB_TessXModelRigid(const surfaceType_t *surfType);
static void RB_AddQuadStampDx7(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1);
static void RB_AddQuadStamp(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1);
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
    tess = *(char **)imp_tess;
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
        backEnd = *(char **)imp_backEnd;
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
    backEnd = *(char **)imp_backEnd;
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
    dxGlobals = *(char **)imp_dx;
    ib = *(IDirect3DIndexBuffer9 **)(dxGlobals + 0x2dbc);
    backEndData = *(char **)imp_dxState;
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

    tess = *(char **)imp_tess;

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
    backEndData = *(char **)imp_dxState;
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

    entity = *(char **)((byte *)*(void **)imp_backEnd + 0x440);
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
static __attribute__((naked))
void RB_AddQuadStampDx7(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 205 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* origin */
        "movl %edx, -0x24(%ebp)\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movss %xmm2, -0x34(%ebp)\n"
        "movss %xmm3, -0x38(%ebp)\n"
        /* { scope 1 */
        "movl imp_tess, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lffe872_000febcc\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lffe872_000fe929\n"
        "movl imp_tess, %esi\n"
        ".Lffe872_000fe8c7:\n"
        "movl 0x5a7cc(%esi), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl 0x5a7c4(%esi), %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lffe872_000fe929\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lffe872_000febb3\n"
        "movl 0x5a7e0(%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lffe872_000febb3\n"
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffe872_000fe935\n"
        ".Lffe872_000fe929:\n"
        "movl imp_tess, %edx\n"
        "movl imp_tess, %esi\n"
        ".Lffe872_000fe935:\n"
        "movl 0x5a7d4(%edx), %ebx\n" /* line 216 */
        "movl %ebx, %edx\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 217 */
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %bx, (%eax, %ecx, 2)\n"
        "leal 1(%ebx), %esi\n" /* line 218 */
        "movl imp_tess, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movw %si, 2(%eax, %ecx, 2)\n"
        "leal 3(%edx), %ebx\n" /* line 219 */
        "movl imp_tess, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movw %bx, 4(%eax, %ecx, 2)\n"
        "movl imp_tess, %eax\n" /* line 220 */
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movw %bx, 6(%eax, %ecx, 2)\n"
        "movl imp_tess, %ebx\n" /* line 221 */
        "movl 0x5a7d0(%ebx), %ecx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "movw %si, 8(%eax, %ecx, 2)\n"
        "movl %ebx, %esi\n" /* line 222 */
        "movl 0x5a7d0(%ebx), %ebx\n"
        "movl 0x5a7b0(%esi), %ecx\n"
        "leal 2(%edx), %eax\n"
        "movw %ax, 0xa(%ecx, %ebx, 2)\n"
        "movzwl %dx, %edx\n" /* line 224 */
        "leal (%edx, %edx, 8), %edx\n"
        "leal (%esi, %edx, 4), %edx\n"
        "movl -0x24(%ebp), %eax\n" /* line 240 */
        "movss (%eax), %xmm3\n"
        "movl -0x28(%ebp), %ebx\n"
        "movss (%ebx), %xmm5\n"
        "movaps %xmm3, %xmm6\n"
        "addss %xmm5, %xmm6\n"
        "movss 4(%eax), %xmm2\n" /* line 241 */
        "movss 4(%ebx), %xmm4\n"
        "movaps %xmm2, %xmm7\n"
        "addss %xmm4, %xmm7\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss 8(%ebx), %xmm0\n"
        "movss -0x3c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "subss %xmm5, %xmm3\n" /* line 248 */
        "subss %xmm4, %xmm2\n" /* line 249 */
        "movss -0x3c(%ebp), %xmm1\n" /* line 250 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n" /* origin */
        "movss %xmm0, (%edx)\n"
        "movaps %xmm7, %xmm0\n" /* line 241 */
        "addss 4(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 4(%edx)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 8(%edx)\n"
        "leal 0x24(%edx), %eax\n" /* line 228 */
        "movl %eax, -0x20(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0x24(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x48(%edx), %esi\n" /* line 229 */
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 0x48(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm7, %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0x6c(%edx), %ebx\n" /* line 230 */
        "addss (%edi), %xmm3\n" /* line 240 | origin */
        "movss %xmm3, 0x6c(%edx)\n"
        "addss 4(%edi), %xmm2\n" /* line 241 | origin */
        "movss %xmm2, 4(%ebx)\n"
        "addss 8(%edi), %xmm1\n" /* line 242 | origin */
        "movss %xmm1, 8(%ebx)\n"
        "movl imp_backEnd, %eax\n" /* line 232 */
        "movl 0x3c8(%eax), %eax\n"
        "leal 0xc(%eax), %ecx\n" /* from */
        /* { scope 2 */
        "movss faceAxis+112, %xmm0\n" /* line 216 */
        "movss 0xc(%eax), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm2\n" /* line 217 */
        "xorps %xmm0, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        /* } scope */
        "leal 0xc(%edx), %eax\n" /* line 233 | to */
        /* { scope 2 */
        "movss %xmm3, 0xc(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x30(%edx), %eax\n" /* line 234 | to */
        /* { scope 2 */
        "movss %xmm3, 0x30(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x54(%edx), %eax\n" /* line 235 | to */
        /* { scope 2 */
        "movss %xmm3, 0x54(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x78(%edx), %eax\n" /* line 236 | to */
        /* { scope 2 */
        "movss %xmm3, 0x78(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movss -0x2c(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x1c(%edx)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0x20(%edx)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x40(%edx)\n"
        "movss %xmm1, 0x44(%edx)\n" /* line 31 */
        "movss %xmm0, 0x64(%edx)\n" /* line 30 */
        "movss -0x38(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0x68(%edx)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x88(%edx)\n"
        "movss %xmm1, 0x8c(%edx)\n" /* line 31 */
        "movl 8(%ebp), %eax\n" /* line 243 | nativeColor */
        "movl %eax, 0x18(%edx)\n"
        "movl -0x20(%ebp), %edx\n" /* line 244 */
        "movl %eax, 0x18(%edx)\n"
        "movl %eax, 0x18(%esi)\n" /* line 245 */
        "movl %eax, 0x18(%ebx)\n" /* line 246 */
        "movl imp_tess, %ebx\n" /* line 248 */
        "addl $4, 0x5a7d4(%ebx)\n"
        "addl $6, 0x5a7d0(%ebx)\n" /* line 249 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 250 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffe872_000febb3:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffe872_000fe935\n"
        ".Lffe872_000febcc:\n"
        "movl %edx, %esi\n"
        "jmp .Lffe872_000fe8c7\n"
    );
}

/* line 138 */
static __attribute__((naked))
void RB_AddQuadStamp(const vec_t *left, const vec_t *up, const int nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl %eax, %edi\n" /* origin */
        "movl %edx, -0x2c(%ebp)\n"
        "movl %ecx, -0x30(%ebp)\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movss %xmm2, -0x3c(%ebp)\n"
        "movss %xmm3, -0x40(%ebp)\n"
        /* { scope 1 */
        "movl imp_tess, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lffebd4_000ff026\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lffebd4_000fec91\n"
        "movl imp_tess, %ecx\n"
        ".Lffebd4_000fec29:\n"
        "movl 0x5a7cc(%ecx), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl imp_tess, %esi\n" /* line 331 */
        "movl 0x5a7c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lffebd4_000fec91\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lffebd4_000ff00d\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lffebd4_000ff00d\n"
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffebd4_000fec9d\n"
        ".Lffebd4_000fec91:\n"
        "movl imp_tess, %edx\n"
        "movl imp_tess, %esi\n"
        ".Lffebd4_000fec9d:\n"
        "movl 0x5a7d4(%edx), %ebx\n" /* line 151 */
        "movl %ebx, %edx\n"
        "movl 0x5a7d0(%esi), %ecx\n" /* line 152 */
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %bx, (%eax, %ecx, 2)\n"
        "leal 1(%ebx), %esi\n" /* line 153 */
        "movl imp_tess, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movw %si, 2(%eax, %ecx, 2)\n"
        "leal 3(%edx), %ebx\n" /* line 154 */
        "movl imp_tess, %eax\n"
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movw %bx, 4(%eax, %ecx, 2)\n"
        "movl imp_tess, %eax\n" /* line 155 */
        "movl 0x5a7d0(%eax), %ecx\n"
        "movl 0x5a7b0(%eax), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movw %bx, 6(%eax, %ecx, 2)\n"
        "movl imp_tess, %ebx\n" /* line 156 */
        "movl 0x5a7d0(%ebx), %ecx\n"
        "movl 0x5a7b0(%ebx), %eax\n"
        "movw %si, 8(%eax, %ecx, 2)\n"
        "movl %ebx, %esi\n" /* line 157 */
        "movl 0x5a7d0(%ebx), %ebx\n"
        "movl 0x5a7b0(%esi), %ecx\n"
        "leal 2(%edx), %eax\n"
        "movw %ax, 0xa(%ecx, %ebx, 2)\n"
        "movzwl %dx, %edx\n" /* line 159 */
        "shll $6, %edx\n"
        "addl %esi, %edx\n"
        "movl -0x2c(%ebp), %eax\n" /* line 240 */
        "movss (%eax), %xmm3\n"
        "movl -0x30(%ebp), %ecx\n"
        "movss (%ecx), %xmm5\n"
        "movaps %xmm3, %xmm6\n"
        "addss %xmm5, %xmm6\n"
        "movss 4(%eax), %xmm2\n" /* line 241 */
        "movss 4(%ecx), %xmm4\n"
        "movaps %xmm2, %xmm7\n"
        "addss %xmm4, %xmm7\n"
        "movss 8(%eax), %xmm0\n" /* line 242 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 8(%ecx), %xmm0\n"
        "movss -0x4c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "subss %xmm5, %xmm3\n" /* line 248 */
        "subss %xmm4, %xmm2\n" /* line 249 */
        "movss -0x4c(%ebp), %xmm1\n" /* line 250 */
        "subss %xmm0, %xmm1\n"
        "movaps %xmm6, %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n" /* origin */
        "movss %xmm0, (%edx)\n"
        "movaps %xmm7, %xmm0\n" /* line 241 */
        "addss 4(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 4(%edx)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 242 */
        "addss 8(%edi), %xmm0\n" /* origin */
        "movss %xmm0, 8(%edx)\n"
        "leal 0x40(%edx), %eax\n" /* line 163 */
        "movl %eax, -0x28(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0x40(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x80(%edx), %ecx\n" /* line 164 */
        "movl %ecx, -0x24(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss %xmm6, %xmm0\n"
        "movss %xmm0, 0x80(%edx)\n"
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss %xmm7, %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "leal 0xc0(%edx), %ebx\n" /* line 165 */
        "movl %ebx, -0x20(%ebp)\n"
        "addss (%edi), %xmm3\n" /* line 240 | origin */
        "movss %xmm3, 0xc0(%edx)\n"
        "addss 4(%edi), %xmm2\n" /* line 241 | origin */
        "movss %xmm2, 4(%ebx)\n"
        "addss 8(%edi), %xmm1\n" /* line 242 | origin */
        "movss %xmm1, 8(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 166 */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x28(%ebp), %esi\n" /* line 167 */
        "movl %eax, 0xc(%esi)\n"
        "movl %eax, 0xc(%ecx)\n" /* line 168 */
        "movl %eax, 0xc(%ebx)\n" /* line 169 */
        "movl imp_backEnd, %eax\n" /* line 171 */
        "movl 0x3c8(%eax), %eax\n"
        "leal 0xc(%eax), %ecx\n" /* from */
        /* { scope 2 */
        "movss faceAxis+128, %xmm0\n" /* line 216 */
        "movss 0xc(%eax), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm2\n" /* line 217 */
        "xorps %xmm0, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 172 | to */
        /* { scope 2 */
        "movss %xmm3, 0x10(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x50(%edx), %eax\n" /* line 173 | to */
        /* { scope 2 */
        "movss %xmm3, 0x50(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x90(%edx), %eax\n" /* line 174 | to */
        /* { scope 2 */
        "movss %xmm3, 0x90(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xd0(%edx), %eax\n" /* line 175 | to */
        /* { scope 2 */
        "movss %xmm3, 0xd0(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 199 */
        "movl (%eax), %ecx\n"
        "movl 4(%eax), %ebx\n" /* line 200 */
        "movl 8(%eax), %esi\n" /* line 201 */
        "leal 0x28(%edx), %eax\n" /* line 178 | to */
        /* { scope 2 */
        "movl %ecx, 0x28(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x68(%edx), %eax\n" /* line 179 | to */
        /* { scope 2 */
        "movl %ecx, 0x68(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xa8(%edx), %eax\n" /* line 180 | to */
        /* { scope 2 */
        "movl %ecx, 0xa8(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xe8(%edx), %eax\n" /* line 181 | to */
        /* { scope 2 */
        "movl %ecx, 0xe8(%edx)\n" /* line 199 */
        "movl %ebx, 4(%eax)\n" /* line 200 */
        "movl %esi, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movl -0x2c(%ebp), %ecx\n" /* line 216 */
        "movss (%ecx), %xmm3\n"
        "xorps %xmm0, %xmm3\n"
        "movss 4(%ecx), %xmm2\n" /* line 217 */
        "xorps %xmm0, %xmm2\n"
        "movss 8(%ecx), %xmm1\n" /* line 218 */
        "xorps %xmm0, %xmm1\n"
        "leal 0x34(%edx), %eax\n" /* line 184 | to */
        /* { scope 2 */
        "movss %xmm3, 0x34(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0x74(%edx), %eax\n" /* line 185 | to */
        /* { scope 2 */
        "movss %xmm3, 0x74(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xb4(%edx), %eax\n" /* line 186 | to */
        /* { scope 2 */
        "movss %xmm3, 0xb4(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "leal 0xf4(%edx), %eax\n" /* line 187 | to */
        /* { scope 2 */
        "movss %xmm3, 0xf4(%edx)\n" /* line 199 */
        "movss %xmm2, 4(%eax)\n" /* line 200 */
        "movss %xmm1, 8(%eax)\n" /* line 201 */
        /* } scope */
        "movss -0x34(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x20(%edx)\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0x24(%edx)\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x60(%edx)\n"
        "movss %xmm1, 0x64(%edx)\n" /* line 31 */
        "movss %xmm0, 0xa0(%edx)\n" /* line 30 */
        "movss -0x40(%ebp), %xmm1\n" /* line 31 */
        "movss %xmm1, 0xa4(%edx)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0xe0(%edx)\n"
        "movss %xmm1, 0xe4(%edx)\n" /* line 31 */
        "movl 8(%ebp), %eax\n" /* line 194 | nativeColor */
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 195 */
        "movl %eax, 0x1c(%edx)\n"
        "movl -0x24(%ebp), %ecx\n" /* line 196 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl -0x20(%ebp), %ebx\n" /* line 197 */
        "movl %eax, 0x1c(%ebx)\n"
        "movl imp_tess, %esi\n" /* line 199 */
        "addl $4, 0x5a7d4(%esi)\n"
        "addl $6, 0x5a7d0(%esi)\n" /* line 200 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lffebd4_000ff00d:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        "movl %eax, %esi\n"
        "jmp .Lffebd4_000fec9d\n"
        ".Lffebd4_000ff026:\n"
        "movl %edx, %ecx\n"
        "jmp .Lffebd4_000fec29\n"
    );
}

/* line 299 */
static __attribute__((naked))
void RB_BuildSprite(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 299 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, %ebx\n" /* re */
        "movl %edx, %esi\n" /* worldRadius */
        /* { scope 1 */
        "leal 0x3c(%eax), %eax\n" /* line 317 | from */
        /* { scope 2 */
        "movl 0x3c(%ebx), %edx\n" /* line 199 */
        "movl %edx, -0x28(%ebp)\n" /* worldOrigin */
        "movl 4(%eax), %edx\n" /* line 200 */
        "movl %edx, -0x24(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, -0x20(%ebp)\n"
        /* } scope */
        "testb $0x10, 5(%ebx)\n" /* line 319 | re */
        "jne .Lfff02e_000ff17d\n"
        "leal 4(%esi), %edi\n" /* worldRadius */
        "movss 0x6c(%ebx), %xmm0\n" /* line 322 | re */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lfff02e_000ff19c\n"
        ".Lfff02e_000ff073:\n"
        "jp .Lfff02e_000ff19c\n"
        "movss (%esi), %xmm1\n" /* line 324 | worldRadius, scale */
        "movl imp_backEnd, %eax\n"
        "movl 0x3c8(%eax), %eax\n"
        "leal 0x18(%eax), %edx\n" /* v */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* left */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "movss (%edi), %xmm1\n" /* line 325 | scale */
        "leal 0x24(%eax), %edx\n" /* v */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* up */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 4(%edx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 8(%edx), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x38(%ebp)\n"
        /* } scope */
        ".Lfff02e_000ff0da:\n"
        "movzbl 0x5b(%ebx), %eax\n" /* line 341 | re */
        "movb %al, -0x1c(%ebp)\n" /* nativeColor */
        "movzbl 0x58(%ebx), %eax\n" /* line 342 | re */
        "movb %al, -0x1b(%ebp)\n"
        "movzbl 0x59(%ebx), %eax\n" /* line 343 | re */
        "movb %al, -0x1a(%ebp)\n"
        "movzbl 0x5a(%ebx), %eax\n" /* line 344 | re */
        "movb %al, -0x19(%ebp)\n"
        /* { scope 2 */
        "movl 0x54(%ebx), %eax\n" /* line 207 */
        "movzbl 0xe(%eax), %ecx\n" /* line 266 */
        "movzbl 0xf(%eax), %edx\n"
        "movl %ecx, %eax\n" /* line 271 */
        "imull %edx, %eax\n"
        "subl $1, %eax\n"
        "je .Lfff02e_000ff2dd\n"
        "cvtsi2ssl %edx, %xmm1\n" /* line 283 */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movaps %xmm0, %xmm2\n"
        "divss %xmm1, %xmm2\n"
        "cvtsi2ssl %ecx, %xmm1\n" /* line 284 */
        "divss %xmm1, %xmm0\n"
        "movl 0x60(%ebx), %eax\n" /* line 286 */
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
        ".Lfff02e_000ff14d:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 352 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfff02e_000ff2be\n"
        "leal -0x40(%ebp), %ecx\n" /* line 358 | up */
        "leal -0x34(%ebp), %edx\n" /* left */
        "leal -0x28(%ebp), %eax\n" /* worldOrigin */
        "movl -0x1c(%ebp), %ebx\n" /* nativeColor, re */
        "movl %ebx, (%esp)\n" /* re */
        "movaps %xmm4, %xmm0\n"
        "calll RB_AddQuadStamp\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 359 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfff02e_000ff17d:\n"
        "leal 4(%esi), %edi\n" /* line 320 | worldRadius */
        "addss 4(%esi), %xmm0\n" /* worldRadius */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0x6c(%ebx), %xmm0\n" /* line 322 | re */
        "pxor %xmm1, %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "je .Lfff02e_000ff073\n"
        ".Lfff02e_000ff19c:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 329 */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* angle */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm3\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 486 | angle */
        "movss %xmm0, (%esp)\n"
        "movss %xmm3, -0x68(%ebp)\n"
        "calll cosf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm2\n"
        "movaps %xmm2, %xmm1\n" /* line 332 | scale */
        "mulss (%esi), %xmm1\n" /* worldRadius, scale */
        "movl imp_backEnd, %eax\n"
        "movl 0x3c8(%eax), %eax\n"
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 272 */
        "mulss 0x18(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* left */
        "movaps %xmm1, %xmm0\n" /* line 273 */
        "mulss 0x1c(%eax), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "mulss 0x20(%eax), %xmm1\n" /* line 274 */
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "movss -0x68(%ebp), %xmm3\n" /* line 333 */
        "movaps %xmm3, %xmm1\n" /* scale */
        "xorps faceAxis+144, %xmm1\n" /* scale */
        "mulss (%esi), %xmm1\n" /* worldRadius, scale */
        /* { scope 2 */
        "movaps %xmm1, %xmm0\n" /* line 288 */
        "mulss 0x24(%eax), %xmm0\n"
        "addss -0x34(%ebp), %xmm0\n" /* left */
        "movss %xmm0, -0x34(%ebp)\n" /* left */
        "movaps %xmm1, %xmm0\n" /* line 289 */
        "mulss 0x28(%eax), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "mulss 0x2c(%eax), %xmm1\n" /* line 290 */
        "addss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        /* } scope */
        "mulss (%edi), %xmm2\n" /* line 335 | scale */
        /* { scope 2 */
        "movaps %xmm2, %xmm0\n" /* line 272 */
        "mulss 0x24(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n" /* up */
        "movaps %xmm2, %xmm0\n" /* line 273 */
        "mulss 0x28(%eax), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 0x2c(%eax), %xmm2\n" /* line 274 */
        "movss %xmm2, -0x38(%ebp)\n"
        /* } scope */
        "mulss (%edi), %xmm3\n" /* line 336 | scale */
        /* { scope 2 */
        "movaps %xmm3, %xmm0\n" /* line 288 */
        "mulss 0x18(%eax), %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n" /* up */
        "movss %xmm0, -0x40(%ebp)\n" /* up */
        "movaps %xmm3, %xmm0\n" /* line 289 */
        "mulss 0x1c(%eax), %xmm0\n"
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "mulss 0x20(%eax), %xmm3\n" /* line 290 */
        "addss %xmm2, %xmm3\n"
        "movss %xmm3, -0x38(%ebp)\n"
        "jmp .Lfff02e_000ff0da\n"
        /* } scope */
        ".Lfff02e_000ff2be:\n"
        "leal -0x40(%ebp), %ecx\n" /* line 354 | up */
        "leal -0x34(%ebp), %edx\n" /* left */
        "leal -0x28(%ebp), %eax\n" /* worldOrigin */
        "movl -0x1c(%ebp), %ebx\n" /* nativeColor, re */
        "movl %ebx, (%esp)\n" /* re */
        "movaps %xmm4, %xmm0\n"
        "calll RB_AddQuadStampDx7\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 359 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfff02e_000ff2dd:\n"
        "movss lit4_002ed5d0, %xmm2\n" /* line 271 | 1.0f */
        "movaps %xmm2, %xmm3\n"
        "pxor %xmm4, %xmm4\n"
        "movaps %xmm4, %xmm1\n"
        "jmp .Lfff02e_000ff14d\n"
    );
}

/* line 877 */
static __attribute__((naked))
void RB_AddLineDx7(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 877 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %edi\n" /* start */
        "movl %edx, -0x7c(%ebp)\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "movss %xmm2, -0x8c(%ebp)\n"
        "movss %xmm3, -0x90(%ebp)\n"
        /* { scope 1 */
        "movl imp_backEnd, %eax\n" /* line 888 | b */
        "movl 0x3c8(%eax), %eax\n" /* b */
        /* { scope 2 */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* v1 */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x74(%ebp)\n"
        "movss 4(%edi), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "leal 8(%edi), %ecx\n" /* line 250 */
        "movl %ecx, -0x70(%ebp)\n"
        "movss 8(%edi), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "movl -0x7c(%ebp), %esi\n" /* line 248 */
        "movss (%esi), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* v2 */
        "addl $4, %esi\n" /* line 249 */
        "movl %esi, -0x6c(%ebp)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movss 4(%edx), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "addl $8, %edx\n" /* line 250 */
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x7c(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "leal -0x24(%ebp), %esi\n" /* line 890 | tangent */
        "movl %esi, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* v2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* v1 */
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %esi, (%esp)\n" /* line 891 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* tangent */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 248 */
        "movss (%eax), %xmm0\n"
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* binormal */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 895 | binormal, vbase */
        "movl %ebx, (%esp)\n" /* vbase */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 896 | normal */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* vbase */
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "movl imp_tess, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfff2f4_000ff733\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfff2f4_000ff71e\n"
        "movl imp_tess, %ecx\n"
        ".Lfff2f4_000ff47c:\n"
        "movl 0x5a7cc(%ecx), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl imp_tess, %esi\n" /* line 331 */
        "movl 0x5a7c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lfff2f4_000ff71e\n"
        "movl 0x5a7d0(%esi), %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfff2f4_000ff729\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfff2f4_000ff729\n"
        ".Lfff2f4_000ff4d7:\n"
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %edx\n"
        ".Lfff2f4_000ff4e4:\n"
        "movl 0x5a7d4(%edx), %eax\n" /* line 901 */
        "leal (%eax, %eax, 8), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%eax)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x74(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x70(%ebp), %esi\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        "leal 0x24(%eax), %edx\n" /* line 903 */
        "movl %edx, -0x78(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0x24(%eax)\n"
        "movss (%ecx), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss (%esi), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "leal 0x48(%eax), %esi\n" /* line 904 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "movl -0x7c(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 0x48(%eax)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x6c(%ebp), %edi\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x68(%ebp), %edx\n"
        "addss (%edx), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0x6c(%eax), %ebx\n" /* line 905 | vbase */
        "movss (%ecx), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0x6c(%eax)\n"
        "movss (%edi), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movss (%edx), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "leal 0xc(%eax), %ecx\n" /* line 907 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0xc(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "leal 0x30(%eax), %ecx\n" /* line 908 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0x30(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "leal 0x54(%eax), %ecx\n" /* line 909 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0x54(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "leal 0x78(%eax), %ecx\n" /* line 910 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %edx\n" /* line 199 | normal */
        "movl %edx, 0x78(%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 200 */
        "movl %edx, 4(%ecx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 201 */
        "movl %edx, 8(%ecx)\n"
        /* } scope */
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x1c(%eax)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x20(%eax)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x40(%eax)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x44(%eax)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x64(%eax)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0x68(%eax)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x88(%eax)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0x8c(%eax)\n"
        "movl -0x84(%ebp), %edx\n" /* line 917 */
        "movl %edx, 0x18(%eax)\n"
        "movl -0x78(%ebp), %ecx\n" /* line 918 */
        "movl %edx, 0x18(%ecx)\n"
        "movl %edx, 0x18(%esi)\n" /* line 919 */
        "movl %edx, 0x18(%ebx)\n" /* line 920 | vbase */
        "movl imp_tess, %esi\n" /* line 922 */
        "movl 0x5a7d4(%esi), %ecx\n"
        "movl %ecx, %ebx\n" /* vbase */
        "movl 0x5a7d0(%esi), %edx\n" /* line 923 */
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %cx, (%eax, %edx, 2)\n"
        "leal 1(%ecx), %esi\n" /* line 924 */
        "movl imp_tess, %edi\n" /* start */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 2(%eax, %edx, 2)\n"
        "leal 2(%ecx), %ecx\n" /* line 925 */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 927 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 928 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 8(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 929 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "addl $3, %ebx\n" /* vbase */
        "movw %bx, 0xa(%eax, %edx, 2)\n" /* vbase */
        "addl $4, 0x5a7d4(%edi)\n" /* line 931 | start */
        "addl $6, 0x5a7d0(%edi)\n" /* line 932 | start */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 933 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfff2f4_000ff71e:\n"
        "movl imp_tess, %edx\n"
        "jmp .Lfff2f4_000ff4e4\n"
        /* { scope 1 */
        ".Lfff2f4_000ff729:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfff2f4_000ff4d7\n"
        ".Lfff2f4_000ff733:\n"
        "movl %edx, %ecx\n"
        "jmp .Lfff2f4_000ff47c\n"
    );
}

/* line 803 */
static __attribute__((naked))
void RB_AddLine(const vec_t *end, float width, D3DCOLOR nativeColor, float s0, float t0, float s1, float t1)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 803 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl %eax, %edi\n" /* start */
        "movl %edx, -0x7c(%ebp)\n"
        "movss %xmm0, -0x80(%ebp)\n"
        "movl %ecx, -0x84(%ebp)\n"
        "movss %xmm1, -0x88(%ebp)\n"
        "movss %xmm2, -0x8c(%ebp)\n"
        "movss %xmm3, -0x90(%ebp)\n"
        /* { scope 1 */
        "movl imp_backEnd, %eax\n" /* line 814 | b */
        "movl 0x3c8(%eax), %eax\n" /* b */
        /* { scope 2 */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* v1 */
        "leal 4(%edi), %edx\n" /* line 249 */
        "movl %edx, -0x74(%ebp)\n"
        "movss 4(%edi), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n"
        "leal 8(%edi), %ecx\n" /* line 250 */
        "movl %ecx, -0x70(%ebp)\n"
        "movss 8(%edi), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "movl -0x7c(%ebp), %esi\n" /* line 248 */
        "movss (%esi), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, -0x54(%ebp)\n" /* v2 */
        "addl $4, %esi\n" /* line 249 */
        "movl %esi, -0x6c(%ebp)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movss 4(%edx), %xmm0\n"
        "subss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x50(%ebp)\n"
        "addl $8, %edx\n" /* line 250 */
        "movl %edx, -0x68(%ebp)\n"
        "movl -0x7c(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm0\n"
        "subss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n"
        "leal -0x24(%ebp), %esi\n" /* line 816 | tangent */
        "movl %esi, 8(%esp)\n"
        "leal -0x54(%ebp), %eax\n" /* v2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* v1 */
        "movl %eax, (%esp)\n"
        "calll Vec3Cross\n"
        "movl %esi, (%esp)\n" /* line 817 */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 272 */
        "mulss -0x24(%ebp), %xmm0\n" /* tangent */
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 273 */
        "mulss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, -0x60(%ebp)\n"
        "movss -0x80(%ebp), %xmm0\n" /* line 274 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x64(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 248 */
        "movss (%eax), %xmm0\n"
        "subss (%edi), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* binormal */
        "movss 4(%eax), %xmm0\n" /* line 249 */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 8(%eax), %xmm0\n" /* line 250 */
        "subss 8(%edi), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "leal -0x30(%ebp), %ebx\n" /* line 821 | binormal, vbase */
        "movl %ebx, (%esp)\n" /* vbase */
        "calll Vec3Normalize\n"
        "fstp %st(0)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 822 | normal */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* vbase */
        "movl %esi, (%esp)\n"
        "calll Vec3Cross\n"
        "movl imp_tess, %edx\n" /* line 344 */
        "movl 0x5a7d4(%edx), %eax\n"
        "addl $4, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfff73a_000ffc69\n"
        "movl 0x5a7d0(%edx), %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfff73a_000ffc54\n"
        "movl imp_tess, %ecx\n"
        ".Lfff73a_000ff8c2:\n"
        "movl 0x5a7cc(%ecx), %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl imp_tess, %esi\n" /* line 331 */
        "movl 0x5a7c4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x5a7c0(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5a7bc(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl 0x5a7cc(%esi), %ebx\n" /* line 310 */
        "je .Lfff73a_000ffc54\n"
        "movl 0x5a7d0(%esi), %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfff73a_000ffc5f\n"
        "movl 0x5a7e0(%esi), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfff73a_000ffc5f\n"
        ".Lfff73a_000ff91d:\n"
        "movl imp_tess, %eax\n" /* line 313 */
        "movl %ebx, 0x5a7cc(%eax)\n"
        "movl %eax, %ecx\n"
        ".Lfff73a_000ff92a:\n"
        "movl 0x5a7d4(%ecx), %edx\n" /* line 827 */
        "shll $6, %edx\n"
        "addl %ecx, %edx\n"
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "addss (%edi), %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x74(%ebp), %esi\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x70(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "leal 0x40(%edx), %ecx\n" /* line 829 */
        "movl %ecx, -0x78(%ebp)\n"
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0x40(%edx)\n"
        "movss (%esi), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ecx)\n"
        "movss (%eax), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ecx)\n"
        "leal 0x80(%edx), %esi\n" /* line 830 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 240 */
        "movl -0x7c(%ebp), %edi\n"
        "addss (%edi), %xmm0\n"
        "movss %xmm0, 0x80(%edx)\n"
        "movss -0x60(%ebp), %xmm0\n" /* line 241 */
        "movl -0x6c(%ebp), %eax\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 4(%esi)\n"
        "movss -0x64(%ebp), %xmm0\n" /* line 242 */
        "movl -0x68(%ebp), %ecx\n"
        "addss (%ecx), %xmm0\n"
        "movss %xmm0, 8(%esi)\n"
        "leal 0xc0(%edx), %ebx\n" /* line 831 | vbase */
        "movss (%edi), %xmm0\n" /* line 248 */
        "subss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc0(%edx)\n"
        "movss (%eax), %xmm0\n" /* line 249 */
        "subss -0x60(%ebp), %xmm0\n"
        "movss %xmm0, 4(%ebx)\n"
        "movss (%ecx), %xmm0\n" /* line 250 */
        "subss -0x64(%ebp), %xmm0\n"
        "movss %xmm0, 8(%ebx)\n"
        "movl $0x3f800000, %eax\n" /* line 832 */
        "movl %eax, 0xc(%edx)\n"
        "movl -0x78(%ebp), %edi\n" /* line 833 | start */
        "movl %eax, 0xc(%edi)\n" /* start */
        "movl %eax, 0xc(%esi)\n" /* line 834 */
        "movl %eax, 0xc(%ebx)\n" /* line 835 | vbase */
        "leal 0x10(%edx), %ecx\n" /* line 837 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0x10(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x50(%edx), %ecx\n" /* line 838 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0x50(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x90(%edx), %ecx\n" /* line 839 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0x90(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xd0(%edx), %ecx\n" /* line 840 | to */
        /* { scope 2 */
        "movl -0x3c(%ebp), %eax\n" /* line 199 | normal */
        "movl %eax, 0xd0(%edx)\n"
        "movl -0x38(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x34(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x28(%edx), %ecx\n" /* line 842 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0x28(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x68(%edx), %ecx\n" /* line 843 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0x68(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xa8(%edx), %ecx\n" /* line 844 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0xa8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xe8(%edx), %ecx\n" /* line 845 | to */
        /* { scope 2 */
        "movl -0x30(%ebp), %eax\n" /* line 199 | binormal */
        "movl %eax, 0xe8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x34(%edx), %ecx\n" /* line 847 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0x34(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x74(%edx), %ecx\n" /* line 848 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0x74(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xb4(%edx), %ecx\n" /* line 849 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0xb4(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0xf4(%edx), %ecx\n" /* line 850 | to */
        /* { scope 2 */
        "movl -0x24(%ebp), %eax\n" /* line 199 | tangent */
        "movl %eax, 0xf4(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x20(%edx)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x24(%edx)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0x60(%edx)\n"
        "movss -0x8c(%ebp), %xmm0\n" /* line 31 */
        "movss %xmm0, 0x64(%edx)\n"
        "movss -0x88(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0xa0(%edx)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0xa4(%edx)\n"
        "movss -0x90(%ebp), %xmm0\n" /* line 30 */
        "movss %xmm0, 0xe0(%edx)\n"
        "movss 8(%ebp), %xmm0\n" /* line 31 | t1 */
        "movss %xmm0, 0xe4(%edx)\n"
        "movl -0x84(%ebp), %eax\n" /* line 857 */
        "movl %eax, 0x1c(%edx)\n"
        "movl %eax, 0x1c(%edi)\n" /* line 858 | start */
        "movl %eax, 0x1c(%esi)\n" /* line 859 */
        "movl %eax, 0x1c(%ebx)\n" /* line 860 | vbase */
        "movl imp_tess, %edx\n" /* line 862 */
        "movl 0x5a7d4(%edx), %ecx\n"
        "movl %ecx, %ebx\n" /* vbase */
        "movl %edx, %esi\n" /* line 863 */
        "movl 0x5a7d0(%edx), %edx\n"
        "movl 0x5a7b0(%esi), %eax\n"
        "movw %cx, (%eax, %edx, 2)\n"
        "leal 1(%ecx), %esi\n" /* line 864 */
        "movl imp_tess, %edi\n" /* start */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 2(%eax, %edx, 2)\n"
        "leal 2(%ecx), %ecx\n" /* line 865 */
        "movl 0x5a7d0(%edi), %edx\n" /* start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 867 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 868 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "movw %si, 8(%eax, %edx, 2)\n"
        "movl 0x5a7d0(%edi), %edx\n" /* line 869 | start */
        "movl 0x5a7b0(%edi), %eax\n" /* start */
        "addl $3, %ebx\n" /* vbase */
        "movw %bx, 0xa(%eax, %edx, 2)\n" /* vbase */
        "addl $4, 0x5a7d4(%edi)\n" /* line 871 | start */
        "addl $6, 0x5a7d0(%edi)\n" /* line 872 | start */
        /* } scope */
        "addl $0x9c, %esp\n" /* line 873 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfff73a_000ffc54:\n"
        "movl imp_tess, %ecx\n"
        "jmp .Lfff73a_000ff92a\n"
        /* { scope 1 */
        ".Lfff73a_000ffc5f:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfff73a_000ff91d\n"
        ".Lfff73a_000ffc69:\n"
        "movl %edx, %ecx\n"
        "jmp .Lfff73a_000ff8c2\n"
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
        "jmpl *faceAxis+176(, %eax, 4)\n"
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
        "andl $g_effectVisArray+4351, -0xd0(%ebp)\n" /* mtlColor */
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
        "movb 0x5b(%edi), %bl\n" /* line 1130 | color */
        "movzbl 0x58(%edi), %eax\n" /* line 1131 */
        "movb %al, %bh\n" /* color */
        "movzbl 0x59(%edi), %eax\n" /* line 1132 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %ebx\n" /* color */
        "orl %eax, %ebx\n" /* color */
        "movzbl 0x5a(%edi), %eax\n" /* line 1133 */
        "shll $0x18, %eax\n"
        "andl $g_effectVisArray+4351, %ebx\n" /* color */
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
        "movl %edi, (%esp)\n" /* line 1182 | re */
        "calll RB_TessParticleCloud\n"
        "jmp .Lfffc70_000ffe08\n"
        /* { scope 1: from, screenOffset, b, a, ... */
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
        "andl $g_effectVisArray+4351, %ecx\n"
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
        "andl $g_effectVisArray+4351, -0xcc(%ebp)\n" /* mtlColor */
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
    );
}

/* line 1193 */
void RB_TessBackEndEntity(const surfaceType_t *surfType)
{
    RB_TessEntity((const GfxEntity *)*(void **)((byte *)*(void **)imp_backEnd + 0x440));
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

    tess = *(char **)imp_tess;

    /* Check if sorted index matches (poly mode = 1) */
    if (*(int *)(tess + 0x5a7cc) != 1) {
        if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
            RB_EndSurface();
        }
        tess = *(char **)imp_tess;
        *(int *)(tess + 0x5a7cc) = 1;
    }

    vertCount = (int)*(unsigned short *)((byte *)surfType + 0xa);
    indexCount = vertCount * 3 - 6;

    /* RB_CheckOverflow */
    if (vertCount + *(int *)(tess + 0x5a7d4) > 0x154a ||
        indexCount + *(int *)(tess + 0x5a7d0) > 0x100000) {
        sortedIndex = *(int *)(tess + 0x5a7cc);
        RB_EndSurface();
        tess = *(char **)imp_tess;
        RB_BeginSurface(
            *(const Material **)(tess + 0x5a7bc),
            *(MaterialTechniqueType *)(tess + 0x5a7c0),
            *(int *)(tess + 0x5a7c4));
        tess = *(char **)imp_tess;
        if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                RB_EndSurface();
            }
            tess = *(char **)imp_tess;
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
            tess = *(char **)imp_tess;
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
        tess = *(char **)imp_tess;
        vertBase = *(int *)(tess + 0x5a7d4);
        dest = tess + vertBase * 68;
        src = *(char **)((byte *)surfType + 0xc);
        memcpy(dest, src, vertCount * 68);
    }

    /* Generate triangle fan indices */
    triCount = vertCount - 2;
    if (triCount > 0) {
        tess = *(char **)imp_tess;
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
    tess = *(char **)imp_tess;
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

    tess = *(char **)imp_tess;

    /* RB_CheckOverflow for cached triangles */
    if (triIndexCount + *(int *)(tess + 0x5a7e0) > 0x100000) {
        sortedIndex = *(int *)(tess + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(
            *(const Material **)(tess + 0x5a7bc),
            *(MaterialTechniqueType *)(tess + 0x5a7c0),
            *(int *)(tess + 0x5a7c4));
        tess = *(char **)imp_tess;
        if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                RB_EndSurface();
                tess = *(char **)imp_tess;
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
    src = *(char **)(*(char **)imp_dx + 0x2dc8) + *(int *)(*(void **)((byte *)surfType + 8)) * 12;
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
        tess = *(char **)imp_tess;

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
        backEndData = *(char **)imp_dxState;
        if (xsurf->indexBuffer != *(IDirect3DIndexBuffer9 **)(backEndData + 0x20cc)) {
            RB_ChangeIndices(xsurf->indexBuffer);
        }

        /* Get skinned vertex buffer from viewParms */
        vb = *(IDirect3DVertexBuffer9 **)((byte *)*(void **)(*(char **)imp_backEndData) + 0x217c78 + 8);

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
        tess = *(char **)imp_tess;
        if (vertexCount + *(int *)(tess + 0x5a7d4) > 0x154a ||
            triIndexCount + *(int *)(tess + 0x5a7d0) > 0x100000) {
            sortedIndex = *(int *)(tess + 0x5a7cc);
            RB_EndSurface();
            tess = *(char **)imp_tess;
            RB_BeginSurface(
                *(const Material **)(tess + 0x5a7bc),
                *(MaterialTechniqueType *)(tess + 0x5a7c0),
                *(int *)(tess + 0x5a7c4));
            tess = *(char **)imp_tess;
            if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
                if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                    RB_EndSurface();
                }
                tess = *(char **)imp_tess;
                *(int *)(tess + 0x5a7cc) = sortedIndex;
            }
        }

        /* Flush if index count is odd (alignment issue) */
        if (*(int *)(tess + 0x5a7d0) & 1) {
            sortedIndex = *(int *)(tess + 0x5a7cc);
            RB_EndSurface();
            tess = *(char **)imp_tess;
            RB_BeginSurface(
                *(const Material **)(tess + 0x5a7bc),
                *(MaterialTechniqueType *)(tess + 0x5a7c0),
                *(int *)(tess + 0x5a7c4));
            tess = *(char **)imp_tess;
            if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
                if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                    RB_EndSurface();
                }
                tess = *(char **)imp_tess;
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
        tess = *(char **)imp_tess;
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
void RB_TessTriangles(const surfaceType_t *surfType)
{
    char *tess;
    int sortedIndex;
    srfTriangles_t *tri = (srfTriangles_t *)surfType;

    tess = *(char **)imp_tess;

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
                tess = *(char **)imp_tess;
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
        tess = *(char **)imp_tess;
        if (sortedIndex != *(int *)(tess + 0x5a7cc)) {
            if (*(int *)(tess + 0x5a7d0) != 0 || *(int *)(tess + 0x5a7e0) != 0) {
                RB_EndSurface();
                tess = *(char **)imp_tess;
            }
            *(int *)(tess + 0x5a7cc) = sortedIndex;
        }
    }

    /* Set triangle mode */
    *(int *)(tess + 0x5a7b8) = 1;

    /* Copy index data */
    Com_Memcpy(
        *(char **)(tess + 0x5a7b4) + *(int *)(tess + 0x5a7e0) * 2,
        (void *)tri->indices,
        (int)tri->indexCount * 2);

    /* Update state */
    *(int *)(tess + 0x5a7e0) += (int)tri->indexCount;
    *(int *)(tess + 0x5a7e8) = tri->firstVertex;
    *(int *)(tess + 0x5a7e4) = (int)tri->vertexCount;
}

