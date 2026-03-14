/* ASM dump from: rb_backend.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/rb_backend.cpp */

#include "common_types.h"
#include "imports.h"

extern int g_rb_tess_type_counts[8]; /* diagnostic */
extern int g_rb_tess_type_idxzero[8]; /* diagnostic */
int g_rb_last_tess_type = 0; /* diagnostic */
int g_dsc_techtype[3] = {0};
int g_dsc_surfcount[3] = {0};
int g_rdsl_ignore_decal = 0;
int g_rdsl_ignore_techm1 = 0;
int g_rdsl_ignore_technull = 0;
int g_rdsl_noignore = 0;
int g_rdsl_sortchange = 0;
int g_rdsl_bf_entry = 0;
void *g_technull_mat = 0;
int g_technull_type = 0;
int g_technull_saved = 0;

void rdsl_log_null_technique2(void *material, int techType)
{
    (void)material;
    (void)techType;
}

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/profile.h"
 *   #include "PC/gfx_d3d/rb_backend.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "PC/gfx_d3d/r_material.h"
 *   #include "PC/gfx_d3d/rb_state.h"
 */

extern int printf(const char *, ...);
static const char rb_rdsl_fmt[] = "[RB_RDSL#%d] surfs=%p count=%d tech=%d order=%d\n";
static const char rb_dxstate_skip_fmt[] = "[DRAWSURF_SKIP#%d] dxState+0x20c8=%d\n";
int rb_drawsurfscmd_count = 0;
int rb_drawsurfscmd_dxskip = 0;

static int diag_rb_frame = 0;
static int diag_rb_cmds_in_frame = 0;
static int diag_rb_has_drawsurfs = 0;
static int diag_rb_has_beginview = 0;
static int diag_rb_skip_this_frame = 0;
static void diag_rb_cmd(int cmdType) {
    (void)cmdType;
}

static int diag_rb_entry_count = 0;
static void diag_rb_entry(void) {
    (void)diag_rb_entry_count;
}

extern unsigned char dxState[];
static void diag_rb_frame_start(void) {
    (void)dxState;
}

extern int rb_rdsl_call_count;
extern int g_dip_gl_draw;
extern int g_rb_endsurface_count;
extern int g_rb_endsurface_draw;
extern int g_rb_endsurface_nomaterial;
extern int g_rb_endsurface_notechnique;
extern int g_rb_endsurface_dxstate;
extern int g_rb_endsurface_idxzero;
extern int g_rb_endsurface_flag1skip;
extern int g_rb_endsurface_flag2skip;
extern int g_dip_drawflag_zero;
extern int g_dip_vs_null;
extern int g_dip_vs_bound;
extern int g_dip_vs_skip;
extern int g_dip_numelems_zero;
extern int g_dip_is_tri;
extern int g_technull_saved;
extern void *g_technull_mat;
extern int g_technull_type;
extern int g_tess_since_begin;
extern int g_rb_tess_type_counts[];
extern int g_rb_last_tess_type;
extern int g_rb_exec_count;
extern int g_dsc_techtype[];
extern int g_dsc_surfcount[];
extern int rb_drawsurfscmd_dxskip;
static void diag_rb_frame_end(void) {
    static int last_print = 0;
    /* Print first 5 frames, then every 60 frames up to 900 */
    if (g_rb_exec_count > last_print && (g_rb_exec_count <= 5 || (g_rb_exec_count % 60 == 0 && g_rb_exec_count <= 900))) {
        fprintf(stderr, "[RB f%d] rdsl=%d es=%d/%d nomat=%d notech=%d dxst=%d idx0=%d f1=%d f2=%d gl=%d tri=%d df0=%d dsc=%d/%d/%d tnull=%d sort=%d bf=%d tt=%d/%d\n",
            g_rb_exec_count, rb_rdsl_call_count, g_rb_endsurface_count, g_rb_endsurface_draw,
            g_rb_endsurface_nomaterial, g_rb_endsurface_notechnique, g_rb_endsurface_dxstate,
            g_rb_endsurface_idxzero, g_rb_endsurface_flag1skip, g_rb_endsurface_flag2skip,
            g_dip_gl_draw, g_dip_is_tri, g_dip_drawflag_zero,
            rb_drawsurfscmd_count, g_dsc_surfcount[0], g_dsc_surfcount[1],
            g_rdsl_ignore_technull,
            g_rdsl_sortchange, g_rdsl_bf_entry,
            g_dsc_techtype[0], g_dsc_techtype[1]);
        last_print = g_rb_exec_count;
    }
    /* Reset per-frame counters */
    rb_rdsl_call_count = 0;
    g_rb_endsurface_count = 0;
    g_rb_endsurface_draw = 0;
    g_rb_endsurface_nomaterial = 0;
    g_rb_endsurface_notechnique = 0;
    g_rb_endsurface_dxstate = 0;
    g_rb_endsurface_idxzero = 0;
    g_rb_endsurface_flag1skip = 0;
    g_rb_endsurface_flag2skip = 0;
    g_dip_gl_draw = 0;
    g_dip_is_tri = 0;
    g_dip_drawflag_zero = 0;
    g_dip_vs_null = 0;
    g_dip_vs_bound = 0;
    g_dip_vs_skip = 0;
    g_dip_numelems_zero = 0;
    g_rdsl_ignore_technull = 0;
    g_rdsl_ignore_decal = 0;
    g_rdsl_ignore_techm1 = 0;
    g_rdsl_noignore = 0;
    g_rdsl_sortchange = 0;
    g_rdsl_bf_entry = 0;
    rb_drawsurfscmd_count = 0;
    rb_drawsurfscmd_dxskip = 0;
    g_technull_saved = 0;
    memset(g_rb_tess_type_counts, 0, sizeof(int) * 8);
    g_tess_since_begin = 0;
}

extern struct materialCommands_t tess; /* 0x0 */
extern struct r_backEndGlobals_t backEnd; /* 0x0 */
extern const GfxBackEndData *backEndData; /* 0x0 */
extern GLuint g_FenceID; /* 0x0 */
extern const byte color_table[8][4]; /* color_table — rodata.c */
extern const Bool refEntIsInWorldSpace[10]; /* refEntIsInWorldSpace — rodata.c */

extern void RB_TessBad(const surfaceType_t *surfType);
extern void RB_TessPoly(const surfaceType_t *surfType);
extern void RB_TessBackEndEntity(const surfaceType_t *surfType);
extern void RB_TessXModelSkinned(const surfaceType_t *surfType);
extern void RB_TessXModelRigid(const surfaceType_t *surfType);
extern void RB_TessStaticModelCached(const surfaceType_t *surfType);
extern void RB_TessTriangles(const surfaceType_t *surfType);

static void (*const rb_tessTable[8])(const surfaceType_t *) = {
    RB_TessBad,               /* SF_BAD */
    RB_TessPoly,              /* SF_POLY */
    RB_TessBackEndEntity,     /* SF_ENTITY */
    RB_TessXModelSkinned,     /* SF_XMODEL_SKINNED */
    RB_TessXModelRigid,       /* SF_XMODEL_RIGID */
    RB_TessStaticModelCached, /* SF_STATICMODEL_CACHED */
    RB_TessTriangles,         /* SF_TRIANGLES */
    RB_TessBad                /* SF_RAW_GEOMETRY */
}; /* rb_tessTable */

extern FontHandle R_RegisterFont(const char *fontName, int imageTrack);
extern void RB_TouchAllImages(void);
extern int ColorIndex(int c);
extern void RB_EndSurface(void);
extern void RB_BeginSurface(const Material *material, MaterialTechniqueType techType, int lmapIndex);
extern void diag_rb_draw(unsigned int x_hex, unsigned int y_hex, unsigned int mat_ptr);
extern void *Image_GetSurface(void *image);
extern void RB_TessEntity(void *entity);
extern Bool Material_IsDefault(MaterialHandle handle);
extern BOOL QueryPerformanceFrequency(void *lpPerformanceFrequency);
extern void RB_DrawSun(const void *sunData);
extern void RB_SetShadowLookupMatrix(const void *matrix);
extern void RB_UpdateViewportConstants(void);
extern void RB_UpdateViewport(void);
extern void RB_SetRenderTarget(int renderTargetId);
extern void RB_DrawSunPostEffects(const void *sunData);
extern void *RB_GetActiveWorldMatrix(void);
extern void MatrixIdentity44(void *matrix);
extern void RB_ChangedWorldMatrix(float worldScale);
extern void RB_SetMatricesForView(const void *viewParms);
extern float floorf(float x);
extern const char *R_ErrorDescription(HRESULT hr);
extern void R_Error(int level, const char *msg, ...);
extern void R_FlushStaticModelCache(void);
extern void R_SetColorMappings(void);
extern void RB_SetViewport(const void *viewport);
extern BOOL QueryPerformanceCounter(void *lpPerformanceCount);

void RB_SetCodeConstant(int constant, vec_t x, vec_t y, vec_t z, vec_t w);
static void RB_GotoCmd(GfxRenderCommandExecState *execState);
static void RB_ReturnCmd(GfxRenderCommandExecState *execState);
void RB_SetGammaRamp(const GfxGammaRamp *gammaTable);
static void RB_TouchAllImagesCmd(GfxRenderCommandExecState *execState);
qboolean RB_IsGpuFenceFinished(void);
void RB_GpuWaited(int ticks);
static void RB_EndFrame_real(void);
void RB_EndFrame(void)
{
    RB_EndFrame_real();
}
void RB_InitBackendGlobalStructs(void);
void RB_RegisterBackendAssets(void);
void RB_LookupColor(int c, byte *color);
static void RB_CallCmd(GfxRenderCommandExecState *execState);
static void RB_SetClipPlanesCmd(GfxRenderCommandExecState *execState);
static void RB_StretchRawCmd(GfxRenderCommandExecState *execState);
static void RB_DrawSunCmd(GfxRenderCommandExecState *execState);
void RB_ClearScreen(int whichToClear, const vec_t *color, float depth, int stencil);
static void RB_ClearScreenCmd(GfxRenderCommandExecState *execState);
static void RB_UpdateColorInternal(const vec_t *floatColor, byte *color);
void RB_UpdateColor(const vec_t *color_allies, const vec_t *color_axis);
void RB_AdaptiveGpuSyncWait(void);
void RB_AdaptiveGpuSyncTarget(void);
static void RB_EndBenchmarkGpu_impl(void *time);
static void RB_EndBenchmarkGpu(void);
static void RB_BeginBenchmarkGpu_impl(void *time);
static void RB_BeginBenchmarkGpu(void);
void RB_Set3D(void);
static void RB_SetMaterialColorCmd(GfxRenderCommandExecState *execState);
static void RB_SetLightPropertiesCmd(GfxRenderCommandExecState *execState);
static void RB_SetStencilRefValueCmd(GfxRenderCommandExecState *execState);
static void RB_SetShadowCookieCmd(GfxRenderCommandExecState *execState);
static void RB_BeginViewCmd(GfxRenderCommandExecState *execState);
static void RB_SetViewportCmd(GfxRenderCommandExecState *execState);
static void RB_SetRenderTargetCmd(GfxRenderCommandExecState *execState);
static void RB_RenderDrawSurfList(GfxDrawSurf *drawSurfs, int drawSurfCount, MaterialTechniqueType techType, GfxDrawSurfOrder order);
static void RB_DrawSurfsCmd(GfxRenderCommandExecState *execState);
static void RB_DrawSunPostEffectsCmd(GfxRenderCommandExecState *execState);
static void RB_Set2D(void);
static void RB_DrawTrianglesCmd(GfxRenderCommandExecState *execState);
static void RB_SaveScreenCmd(GfxRenderCommandExecState *execState);
static void RB_ApplyEarlyPostEffectsCmd(GfxRenderCommandExecState *execState);
static void RB_DrawSpriteCmd(GfxRenderCommandExecState *execState);
void RB_DrawLines2D(int count, int width, const GfxPointVertex *verts);
void RB_DrawTextInSpace(const char *text, FontHandle font, const vec_t *org, const vec_t *xPixelStep, const vec_t *yPixelStep, D3DCOLOR color);
static void RB_DrawTextInSpaceCmd(GfxRenderCommandExecState *execState);
static float RB_TestFillPass3D(const Material *material, MaterialTechniqueType techType);
void RB_DrawStretchPic(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, D3DCOLOR color, GfxPrimStatsTarget statsTarget);
static void RB_StretchPicCmd(GfxRenderCommandExecState *execState);
static float RB_BenchmarkRepeatedCalls(float width, float height);
void RB_ExecuteRenderCommands(const void *data);
void RB_DrawFullScreenColoredQuad(const Material *material, float s0, float t0, float s1, float t1, D3DCOLOR color);
static void RB_DrawFullScreenColoredQuadCmd(GfxRenderCommandExecState *execState);
static void RB_BlendSavedScreenCmd(GfxRenderCommandExecState *execState);
static void RB_BlurShadowCookieCmd(GfxRenderCommandExecState *execState);
static void RB_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float xScale, float yScale, const GfxColor color, int style, int cursorPos, int cursor);
static void RB_DrawTextCmd(GfxRenderCommandExecState *execState);
static void RB_ApplyLatePostEffectsCmd(GfxRenderCommandExecState *execState);
static void RB_StretchPicRotateCmd(GfxRenderCommandExecState *execState);
static void RB_DrawQuadPicCmd(GfxRenderCommandExecState *execState);
void RB_DrawLines3D(int count, int width, const GfxPointVertex *verts, int depthTest);
static void RB_DrawLinesCmd(GfxRenderCommandExecState *execState);
static void RB_StencilPlanesCmd(GfxRenderCommandExecState *execState);
static void RB_DrawPointsCmd(GfxRenderCommandExecState *execState);

void (*const RB_RenderCommandTable[34])(GfxRenderCommandExecState *execState) = {
    NULL,
    RB_GotoCmd,
    RB_CallCmd,
    RB_ReturnCmd,
    RB_SetMaterialColorCmd,
    RB_SetLightPropertiesCmd,
    NULL,
    NULL,
    NULL,
    NULL,
    RB_SaveScreenCmd,
    RB_ClearScreenCmd,
    RB_BeginViewCmd,
    RB_SetViewportCmd,
    RB_SetRenderTargetCmd,
    RB_StretchPicCmd,
    RB_StretchPicRotateCmd,
    RB_StretchRawCmd,
    RB_DrawQuadPicCmd,
    RB_DrawSpriteCmd,
    RB_DrawFullScreenColoredQuadCmd,
    RB_DrawTextCmd,
    RB_DrawTextInSpaceCmd,
    RB_DrawSurfsCmd,
    RB_DrawSunCmd,
    RB_ApplyEarlyPostEffectsCmd,
    RB_ApplyLatePostEffectsCmd,
    RB_DrawSunPostEffectsCmd,
    NULL,
    RB_BlendSavedScreenCmd,
    NULL,
    NULL,
    NULL,
    RB_TouchAllImagesCmd,
};

/* line 4245 */
void RB_SetCodeConstant(int constant, vec_t x, vec_t y, vec_t z, vec_t w)
{
    vec_t *v = (vec_t *)((char *)&backEnd + constant * 16 - 0x800);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

/* line 577 */
static void RB_GotoCmd(GfxRenderCommandExecState *execState)
{
    *(void **)execState = *(void **)((byte *)*(void **)execState + 4);
}

/* line 600 */
static void RB_ReturnCmd(GfxRenderCommandExecState *execState)
{
    int idx = *(int *)((byte *)execState + 4) - 1;
    *(int *)((byte *)execState + 4) = idx;
    *(void **)execState = *(void **)((byte *)execState + 8 + idx * 4);
}

/* line 1750 */
void RB_SetGammaRamp(const GfxGammaRamp *gammaTable)
{
    unsigned short d3dGammaRamp[256 * 3]; /* R, G, B channels */
    int i;
    byte *dx;
    void *dev;
    void **vt;

    /* Copy grayscale gamma ramp to all three D3D channels */
    for (i = 0; i < 256; i++) {
        d3dGammaRamp[i] = gammaTable->entries[i];
        d3dGammaRamp[i + 256] = gammaTable->entries[i];
        d3dGammaRamp[i + 512] = gammaTable->entries[i];
    }

    /* IDirect3DDevice9::SetGammaRamp(swapChain, flags=0, &ramp) */
    dx = (byte *)imp_dx;
    dev = *(void **)(dx + 8);
    vt = *(void ***)dev;
    ((void (*)(void *, int, int, void *))vt[0x54 / 4])(dev, *(int *)(dx + 0x2d44), 0, d3dGammaRamp);
}

/* line 2430 */
static void RB_TouchAllImagesCmd(GfxRenderCommandExecState *execState)
{
    unsigned char *cmd;

    RB_TouchAllImages();
    cmd = *(unsigned char **)execState;
    *(unsigned char **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 3300 */
qboolean RB_IsGpuFenceFinished(void)
{
    byte *dx = (byte *)imp_dx;
    qboolean finished;

    if (!dx[0x2d68])
        return 1;

    finished = glTestFenceAPPLE(g_FenceID) != 0;
    if (finished)
        glDeleteFencesAPPLE(1, &g_FenceID);
    if (finished) {
        dx[0x2d68] = 0;
        return 1;
    }
    return 0;
}

/* line 3214 */
void RB_GpuWaited(int ticks)
{
    *(int *)((byte *)(void *)imp_dx + 0x2d64) = ticks;
}

/* line 3710 */
static void RB_EndFrame_real(void)
{
    char *dx = (char *)imp_dx;
    void *device;
    void **vtable;
    HRESULT hr;
    char *r_gamma_cvar;
    char *r_ignoreHwGamma_cvar;
    void (*Cvar_ClearModified)(void *);

    /* IDirect3DDevice9::Present(NULL, NULL, NULL, NULL) — vtable offset 0x44 */
    device = *(void **)(dx + 8);
    vtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, void *, void *, void *, void *))(vtable[0x44 / 4]))(device, NULL, NULL, NULL, NULL);

    if (hr < 0) {
        if (hr != (HRESULT)0x88760868) { /* D3DERR_DEVICELOST */
            R_Error(0, "Direct3DDevice9::Present failed: %s\n", R_ErrorDescription(hr));
        }
        *(byte *)(dx + 0x2d3c) = 1; /* deviceLost = true */
        R_FlushStaticModelCache();
    }

    /* Reset index buffer lock position */
    dx = (char *)imp_dx;
    *(int *)*(void **)(dx + 0x2d8c) = 0;

    /* backEnd.in2d = false */
    *(byte *)((char *)&backEnd + 1213) = 0;

    /* Check if gamma cvars were modified */
    r_gamma_cvar = *(char **)imp_r_gamma;
    r_ignoreHwGamma_cvar = *(char **)imp_r_ignoreHwGamma;

    if (*(byte *)(r_gamma_cvar + 7) || *(byte *)(r_ignoreHwGamma_cvar + 7)) {
        /* Clear modified flags via ri->Cvar_ClearModified (offset 0x88) */
        Cvar_ClearModified = *(void (**)(void *))((char *)imp_ri + 0x88);
        Cvar_ClearModified(r_gamma_cvar);

        r_ignoreHwGamma_cvar = *(char **)imp_r_ignoreHwGamma;
        Cvar_ClearModified(r_ignoreHwGamma_cvar);

        if (!*(byte *)(r_ignoreHwGamma_cvar + 8)) {
            R_SetColorMappings();
            return;
        }
    }
}

void RB_InitSceneViewport(void);

/* line 4215 */
void RB_InitBackendGlobalStructs(void)
{
    memset(&backEnd, 0, 0x36e90);
    *(int *)((char *)&backEnd + 1096) = 3;
    *(int *)((char *)&backEnd + 11908) = 0xe;
    *(int *)((char *)&backEnd + 11912) = 0xe;
    RB_InitSceneViewport();
}

/* line 4234 */
void RB_RegisterBackendAssets(void)
{
    *(FontHandle *)((char *)&backEnd + 224904) = R_RegisterFont("fonts/smalldevfont", 1);
}

/* line 2828 */
void RB_LookupColor(int c, byte *color)
{
    int idx = ColorIndex((byte)c);
    if (idx <= 7) {
        *(unsigned int *)color = ((const unsigned int *)color_table)[idx];
    } else if ((byte)c == '8') {
        *(unsigned int *)color = *(unsigned int *)((char *)&backEnd + 1220);
    } else if ((byte)c == '9') {
        *(unsigned int *)color = *(unsigned int *)((char *)&backEnd + 1216);
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
}

/* line 587 */
static void RB_CallCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    int idx = *(int *)((byte *)execState + 4);

    /* Save return address (cmd + size) onto the call stack */
    *(void **)((byte *)execState + 8 + idx * 4) = cmd + *(unsigned short *)(cmd + 2);
    *(int *)((byte *)execState + 4) = idx + 1;

    /* Jump to the call target */
    *(void **)execState = *(void **)(cmd + 4);
}

/* line 1339 */
static void RB_SetClipPlanesCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    int planeCount = *(int *)(cmd + 4);
    void *device;
    void **vtable;
    int i;

    /* Update clip plane enable render state if changed */
    if (planeCount != *(int *)((char *)imp_dxState + 0x2154)) {
        /* IDirect3DDevice9::SetRenderState(D3DRS_CLIPPLANEENABLE, (1<<count)-1) — vtable 0xE4 */
        do {
            device = *(void **)((char *)imp_dx + 8);
            vtable = *(void ***)device;
            ((HRESULT (*)(void *, DWORD, DWORD))(vtable[0xE4 / 4]))(
                device, 0x98, (DWORD)((1 << planeCount) - 1));
        } while (*(volatile int *)imp_alwaysfails);

        *(int *)((char *)imp_dxState + 0x2154) = planeCount;
    }

    /* Set each clip plane — planes start at cmd+8, 16 bytes each */
    if (planeCount > 0) {
        byte *planeData = cmd + 8;
        for (i = 0; i < planeCount; i++) {
            /* IDirect3DDevice9::SetClipPlane(i, planeData) — vtable 0xDC */
            do {
                device = *(void **)((char *)imp_dx + 8);
                vtable = *(void ***)device;
                ((HRESULT (*)(void *, DWORD, const float *))(vtable[0xDC / 4]))(
                    device, (DWORD)i, (const float *)planeData);
            } while (*(volatile int *)imp_alwaysfails);
            planeData += 16;
        }
    }

    /* Advance command pointer */
    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 843 */
static void RB_StretchRawCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    int x     = *(int *)(cmd + 4);
    int y     = *(int *)(cmd + 8);
    int w     = *(int *)(cmd + 0xc);
    int h     = *(int *)(cmd + 0x10);
    int cols  = *(int *)(cmd + 0x14);
    int rows  = *(int *)(cmd + 0x18);
    byte *data = *(byte **)(cmd + 0x1c);
    void *rawTexture = NULL;
    void *device;
    void **devVtable;
    void **texVtable;
    HRESULT hr;
    int lockedRect[2]; /* [0]=Pitch, [1]=pBits */
    int dstRect[4];
    void *surface = NULL;
    byte *dest;
    int pitch;
    int rowBytes;
    int i;

    /* IDirect3DDevice9::CreateTexture(cols, rows, 1, 0, D3DFMT_X8R8G8B8, D3DPOOL_DEFAULT, &rawTexture, NULL) — vtable 0x5C */
    device = *(void **)((char *)imp_dx + 8);
    devVtable = *(void ***)device;
    hr = ((HRESULT (*)(void *, UINT, UINT, UINT, DWORD, DWORD, DWORD, void **, void *))(devVtable[0x5C / 4]))(
        device, (UINT)cols, (UINT)rows, 1, 0, 0x16, 0, &rawTexture, NULL);

    if (hr >= 0) {
        /* IDirect3DTexture9::LockRect(0, &lockedRect, NULL, D3DLOCK_DISCARD) — vtable 0x4C */
        do {
            texVtable = *(void ***)rawTexture;
            ((HRESULT (*)(void *, UINT, void *, void *, DWORD))(texVtable[0x4C / 4]))(
                rawTexture, 0, lockedRect, NULL, 0x2000);
        } while (*(volatile int *)imp_alwaysfails);

        dest = (byte *)(size_t)lockedRect[1]; /* pBits */
        pitch = lockedRect[0]; /* Pitch */

        /* Copy pixel data row by row */
        if (rows > 0) {
            rowBytes = cols * 4;
            for (i = 0; i < rows; i++) {
                memcpy(dest, data, rowBytes);
                data += rowBytes;
                dest += pitch;
            }
        }

        /* IDirect3DTexture9::UnlockRect(0) — vtable 0x50 */
        texVtable = *(void ***)rawTexture;
        ((HRESULT (*)(void *, UINT))(texVtable[0x50 / 4]))(rawTexture, 0);

        /* Build destination RECT */
        dstRect[0] = x;
        dstRect[1] = y;
        dstRect[2] = x + w;
        dstRect[3] = y + h;

        /* IDirect3DTexture9::GetSurfaceLevel(0, &surface) — vtable 0x48 */
        texVtable = *(void ***)rawTexture;
        ((HRESULT (*)(void *, UINT, void **))(texVtable[0x48 / 4]))(rawTexture, 0, &surface);

        /* IDirect3DDevice9::StretchRect(surface, NULL, backBuffer, &dstRect, D3DTEXF_LINEAR) — vtable 0x88 */
        {
            char *dx = (char *)imp_dx;
            void *backBuffer = *(void **)(dx + 0x2c34);
            device = *(void **)(dx + 8);
            devVtable = *(void ***)device;
            ((HRESULT (*)(void *, void *, void *, void *, void *, DWORD))(devVtable[0x88 / 4]))(
                device, surface, NULL, backBuffer, dstRect, 2);
        }

        /* Release surface and texture — vtable 0x08 = Release */
        ((ULONG (*)(void *))(*(void ***)surface)[0x08 / 4])(surface);
        ((ULONG (*)(void *))(*(void ***)rawTexture)[0x08 / 4])(rawTexture);
    }

    /* Advance command pointer */
    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 1246 */
static void RB_DrawSunCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    RB_DrawSun(*(void **)(cmd + 4));
    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 1366 */
void RB_ClearScreen(int whichToClear, const vec_t *color, float depth, int stencil)
{
    DWORD clearFlags = 0;
    int viewport[4];
    byte r, g, b, a;
    DWORD d3dColor;
    void *device;
    void **vtable;

    /* Build D3DCLEAR flags from whichToClear bitmask */
    if (whichToClear & 2)
        clearFlags |= 2;  /* D3DCLEAR_ZBUFFER */
    if (whichToClear & 4)
        clearFlags |= 4;  /* D3DCLEAR_STENCIL */
    if (whichToClear & 1)
        clearFlags |= 1;  /* D3DCLEAR_TARGET */

    /* Set viewport to full render target */
    viewport[0] = 0;
    viewport[1] = 0;
    viewport[2] = *(int *)((char *)imp_dxState + 0x209c);
    viewport[3] = *(int *)((char *)imp_dxState + 0x20a0);
    RB_SetViewport(viewport);
    *(byte *)((char *)&backEnd + 1212) = 1;

    /* Convert float color [0..1] to byte [0..255] with clamping */
    r = (byte)(int)floorf(color[0] * 255.0f + 0.5f);
    g = (byte)(int)floorf(color[1] * 255.0f + 0.5f);
    b = (byte)(int)floorf(color[2] * 255.0f + 0.5f);
    a = (byte)(int)floorf(color[3] * 255.0f + 0.5f);

    /* Pack ARGB color */
    d3dColor = ((DWORD)a << 24) | ((DWORD)r << 16) | ((DWORD)g << 8) | (DWORD)b;

    /* IDirect3DDevice9::Clear(0, NULL, flags, color, depth, stencil) — vtable 0xAC */
    do {
        device = *(void **)((char *)imp_dx + 8);
        vtable = *(void ***)device;
        ((HRESULT (*)(void *, DWORD, void *, DWORD, DWORD, float, DWORD))(vtable[0xAC / 4]))(
            device, 0, NULL, clearFlags, d3dColor, depth, (DWORD)(byte)stencil);
    } while (*(volatile int *)imp_alwaysfails);
}

/* line 1417 */
static void RB_ClearScreenCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    RB_ClearScreen(cmd[4], (const vec_t *)(cmd + 12), *(float *)(cmd + 8), cmd[5]);
    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2888 */
static void RB_UpdateColorInternal(const vec_t *floatColor, byte *color)
{
    color[0] = (byte)(int)floorf(floatColor[0] * 255.0f + 0.5f);
    color[1] = (byte)(int)floorf(floatColor[1] * 255.0f + 0.5f);
    color[2] = (byte)(int)floorf(floatColor[2] * 255.0f + 0.5f);
    color[3] = (byte)(int)floorf(floatColor[3] * 255.0f + 0.5f);
}

/* line 2897 */
void RB_UpdateColor(const vec_t *color_allies, const vec_t *color_axis)
{
    RB_UpdateColorInternal(color_allies, (byte *)((char *)&backEnd + 1220));
    RB_UpdateColorInternal(color_axis, (byte *)((char *)&backEnd + 1216));
}

/* line 3220 */
static inline unsigned int rdtsc_lo(void)
{
    unsigned int lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo) : : "edx");
    return lo;
}

void RB_AdaptiveGpuSyncWait(void)
{
    byte *dx = (byte *)imp_dx;
    long long startTime;
    long long waitedTime;
    int syncTarget, diff;

    if (*(int *)(dx + 0x2c20) != 3) {
        /* Not adaptive sync mode — just check fence once */
        if (dx[0x2d68]) {
            qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
            if (finished)
                glDeleteFencesAPPLE(1, &g_FenceID);
            if (finished)
                dx[0x2d68] = 0;
        }
        return;
    }

    /* Compute start time minus GPU waited ticks (sign-extended to 64-bit) */
    startTime = (long long)rdtsc_lo() - (long long)*(int *)(dx + 0x2d64);
    *(int *)(dx + 0x2d64) = 0;
    waitedTime = 0;

    /* Spin-wait for fence with timeout */
    for (;;) {
        dx = (byte *)imp_dx;
        if (dx[0x2d68]) {
            qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
            if (finished)
                glDeleteFencesAPPLE(1, &g_FenceID);
            if (finished) {
                dx[0x2d68] = 0;
                dx = (byte *)imp_dx;
                break;
            }
            /* Check timeout: if elapsed > 0x7fffffff ticks, give up */
            waitedTime = (long long)rdtsc_lo() - startTime;
            if (waitedTime > 0x7fffffffLL)
                return;
        } else {
            break;
        }
    }

    /* Update adaptive sync target: exponential moving average
     * syncTarget = (syncTarget + waitedTime) / 2 */
    syncTarget = *(int *)(dx + 0x2d60);
    diff = syncTarget - (int)waitedTime;
    syncTarget -= (diff + ((unsigned int)diff >> 31)) >> 1;
    *(int *)(dx + 0x2d60) = syncTarget;
}

/* line 3252 */
void RB_AdaptiveGpuSyncTarget(void)
{
    byte *dx = (byte *)imp_dx;
    int val;

    if (dx[0x2d68]) {
        qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
        if (finished)
            glDeleteFencesAPPLE(1, &g_FenceID);
        if (!finished)
            return;
        dx[0x2d68] = 0;
    }

    /* Subtract target and clamp to non-negative */
    val = *(int *)(dx + 0x2d60) - 0x4e20;
    if (val < 0)
        val = 0;
    *(int *)(dx + 0x2d60) = val;
}

/* line 3363 */
static void RB_EndBenchmarkGpu_impl(void *time)
{
    byte *dx;
    void *device;
    void **vtable;

    /* IDirect3DDevice9::EndScene — vtable 0xA8 */
    do {
        dx = (byte *)imp_dx;
        device = *(void **)(dx + 8);
        vtable = *(void ***)device;
        ((HRESULT (*)(void *))(vtable[0xA8 / 4]))(device);
    } while (*(volatile int *)imp_alwaysfails);

    /* Clear benchmarking flag */
    dx = (byte *)imp_dx;
    dx[0x2d3d] = 0;

    /* Wait for any pending fence to finish */
    while (dx[0x2d68]) {
        qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
        if (finished)
            glDeleteFencesAPPLE(1, &g_FenceID);
        if (finished) {
            dx[0x2d68] = 0;
            break;
        }
        dx = (byte *)imp_dx;
    }

    /* Generate and set a new fence */
    glGenFencesAPPLE(1, &g_FenceID);
    glSetFenceAPPLE(g_FenceID);
    dx = (byte *)imp_dx;
    dx[0x2d68] = 1;

    /* Wait for the new fence to complete */
    while (dx[0x2d68]) {
        qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
        if (finished)
            glDeleteFencesAPPLE(1, &g_FenceID);
        if (finished) {
            dx[0x2d68] = 0;
            break;
        }
        dx = (byte *)imp_dx;
    }

    /* Record end time */
    QueryPerformanceCounter(time);
}

/* Naked trampoline: marshals eax (time pointer) to stack arg */
static __attribute__((naked))
void RB_EndBenchmarkGpu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %eax\n"
        "calll RB_EndBenchmarkGpu_impl\n"
        "addl $4, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3352 */
static void RB_BeginBenchmarkGpu_impl(void *time)
{
    byte *dx;
    void *device;
    void **vtable;

    /* Wait for any pending fence to finish */
    dx = (byte *)imp_dx;
    while (dx[0x2d68]) {
        qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
        if (finished)
            glDeleteFencesAPPLE(1, &g_FenceID);
        if (finished) {
            dx[0x2d68] = 0;
            break;
        }
        dx = (byte *)imp_dx;
    }

    /* Generate and set a new fence */
    glGenFencesAPPLE(1, &g_FenceID);
    glSetFenceAPPLE(g_FenceID);
    dx = (byte *)imp_dx;
    dx[0x2d68] = 1;

    /* Wait for the new fence to complete */
    while (dx[0x2d68]) {
        qboolean finished = glTestFenceAPPLE(g_FenceID) != 0;
        if (finished)
            glDeleteFencesAPPLE(1, &g_FenceID);
        if (finished) {
            dx[0x2d68] = 0;
            break;
        }
        dx = (byte *)imp_dx;
    }

    /* Record begin time */
    QueryPerformanceCounter(time);

    /* Set benchmarking flag */
    dx = (byte *)imp_dx;
    dx[0x2d3d] = 1;

    /* IDirect3DDevice9::BeginScene — vtable 0xA4 */
    do {
        dx = (byte *)imp_dx;
        device = *(void **)(dx + 8);
        vtable = *(void ***)device;
        ((HRESULT (*)(void *))(vtable[0xA4 / 4]))(device);
    } while (*(volatile int *)imp_alwaysfails);
}

/* Naked trampoline: marshals eax (time pointer) to stack arg */
static __attribute__((naked))
void RB_BeginBenchmarkGpu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %eax\n"
        "calll RB_BeginBenchmarkGpu_impl\n"
        "addl $4, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 326 */
void RB_Set3D(void)
{
    int *vp;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    *(byte *)((char *)&backEnd + 1213) = 0;
    MatrixIdentity44(RB_GetActiveWorldMatrix());
    RB_ChangedWorldMatrix(1.0f);
    RB_SetMatricesForView(*(void **)((char *)&backEnd + 968));

    /* Copy view axes from viewParms to backEnd as vec4s */
    vp = *(int **)((char *)&backEnd + 968);
    *(int *)((char *)&backEnd + 176) = vp[0];
    *(int *)((char *)&backEnd + 180) = vp[1];
    *(int *)((char *)&backEnd + 184) = vp[2];
    *(int *)((char *)&backEnd + 188) = 0x3f800000; /* 1.0f */

    *(int *)((char *)&backEnd + 192) = vp[3];
    *(int *)((char *)&backEnd + 196) = vp[4];
    *(int *)((char *)&backEnd + 200) = vp[5];
    *(int *)((char *)&backEnd + 204) = 0;

    *(int *)((char *)&backEnd + 208) = vp[6];
    *(int *)((char *)&backEnd + 212) = vp[7];
    *(int *)((char *)&backEnd + 216) = vp[8];
    *(int *)((char *)&backEnd + 220) = 0;

    *(int *)((char *)&backEnd + 224) = vp[9];
    *(int *)((char *)&backEnd + 228) = vp[10];
    *(int *)((char *)&backEnd + 232) = vp[11];
    *(int *)((char *)&backEnd + 236) = 0;
}

/* line 2463 */
static void RB_SetMaterialColorCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    /* Copy vec4 material color from cmd+4 to backEnd+432 */
    *(int *)((char *)&backEnd + 432) = *(int *)(cmd + 4);
    *(int *)((char *)&backEnd + 436) = *(int *)(cmd + 8);
    *(int *)((char *)&backEnd + 440) = *(int *)(cmd + 12);
    *(int *)((char *)&backEnd + 444) = *(int *)(cmd + 16);

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2475 */
/* line 2475 */
static void RB_SetLightPropertiesCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;
    char *be = (char *)&backEnd;
    int idx;
    int lightOfs; /* idx * 68 */
    int compactOfs; /* idx * 16 */

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    idx = *(int *)(cmd + 4);
    lightOfs = idx * 68; /* (idx << 6) + idx * 4 */
    compactOfs = idx * 16;

    /* Copy light color/direction vectors from cmd to per-light arrays */
    /* color1 (cmd+0x18) → backEnd+0x2EA0+lightOfs */
    *(int *)(be + 0x2ea0 + lightOfs + 0)  = *(int *)(cmd + 0x18);
    *(int *)(be + 0x2ea0 + lightOfs + 4)  = *(int *)(cmd + 0x1c);
    *(int *)(be + 0x2ea0 + lightOfs + 8)  = *(int *)(cmd + 0x20);
    *(int *)(be + 0x2ea0 + lightOfs + 12) = *(int *)(cmd + 0x24);

    /* color2 (cmd+0x28) → backEnd+0x2EB0+lightOfs */
    *(int *)(be + 0x2eb0 + lightOfs + 0)  = *(int *)(cmd + 0x28);
    *(int *)(be + 0x2eb0 + lightOfs + 4)  = *(int *)(cmd + 0x2c);
    *(int *)(be + 0x2eb0 + lightOfs + 8)  = *(int *)(cmd + 0x30);
    *(int *)(be + 0x2eb0 + lightOfs + 12) = *(int *)(cmd + 0x34);

    /* color3 (cmd+0x38) → backEnd+0x2EC0+lightOfs */
    *(int *)(be + 0x2ec0 + lightOfs + 0)  = *(int *)(cmd + 0x38);
    *(int *)(be + 0x2ec0 + lightOfs + 4)  = *(int *)(cmd + 0x3c);
    *(int *)(be + 0x2ec0 + lightOfs + 8)  = *(int *)(cmd + 0x40);
    *(int *)(be + 0x2ec0 + lightOfs + 12) = *(int *)(cmd + 0x44);

    /* attenuation scalar (cmd+0x48) → backEnd+0x2ED0+lightOfs */
    *(int *)(be + 0x2ed0 + lightOfs) = *(int *)(cmd + 0x48);

    /* position (cmd+0x08) → backEnd+0x2E90+lightOfs */
    *(int *)(be + 0x2e90 + lightOfs + 0)  = *(int *)(cmd + 0x08);
    *(int *)(be + 0x2e90 + lightOfs + 4)  = *(int *)(cmd + 0x0c);
    *(int *)(be + 0x2e90 + lightOfs + 8)  = *(int *)(cmd + 0x10);
    *(int *)(be + 0x2e90 + lightOfs + 12) = *(int *)(cmd + 0x14);

    /* Copy per-light data to compact arrays */
    /* position → backEnd+compactOfs+0x30 */
    *(int *)(be + compactOfs + 0x30 + 0)  = *(int *)(be + 0x2e90 + lightOfs + 0);
    *(int *)(be + compactOfs + 0x30 + 4)  = *(int *)(be + 0x2e90 + lightOfs + 4);
    *(int *)(be + compactOfs + 0x30 + 8)  = *(int *)(be + 0x2e90 + lightOfs + 8);
    *(int *)(be + compactOfs + 0x30 + 12) = *(int *)(be + 0x2e90 + lightOfs + 12);

    /* color1 → backEnd+compactOfs+0x70 */
    *(int *)(be + compactOfs + 0x70 + 0)  = *(int *)(be + 0x2ea0 + lightOfs + 0);
    *(int *)(be + compactOfs + 0x70 + 4)  = *(int *)(be + 0x2ea0 + lightOfs + 4);
    *(int *)(be + compactOfs + 0x70 + 8)  = *(int *)(be + 0x2ea0 + lightOfs + 8);
    *(int *)(be + compactOfs + 0x70 + 12) = *(int *)(be + 0x2ea0 + lightOfs + 12);

    /* color2 → backEnd+compactOfs+0x50 */
    *(int *)(be + compactOfs + 0x50 + 0)  = *(int *)(be + 0x2eb0 + lightOfs + 0);
    *(int *)(be + compactOfs + 0x50 + 4)  = *(int *)(be + 0x2eb0 + lightOfs + 4);
    *(int *)(be + compactOfs + 0x50 + 8)  = *(int *)(be + 0x2eb0 + lightOfs + 8);
    *(int *)(be + compactOfs + 0x50 + 12) = *(int *)(be + 0x2eb0 + lightOfs + 12);

    /* color3 → backEnd+compactOfs+0x90 */
    *(int *)(be + compactOfs + 0x90 + 0)  = *(int *)(be + 0x2ec0 + lightOfs + 0);
    *(int *)(be + compactOfs + 0x90 + 4)  = *(int *)(be + 0x2ec0 + lightOfs + 4);
    *(int *)(be + compactOfs + 0x90 + 8)  = *(int *)(be + 0x2ec0 + lightOfs + 8);
    *(int *)(be + compactOfs + 0x90 + 12) = *(int *)(be + 0x2ec0 + lightOfs + 12);

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 1281 */
static void RB_SetStencilRefValueCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;
    int stencilRef;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    stencilRef = *(int *)(cmd + 4);

    if (*(int *)((byte *)imp_dxState + 0x2010) != stencilRef) {
        /* D3D SetRenderState(D3DRS_STENCILREF, stencilRef) */
        do {
            void *dev = *(void **)((byte *)imp_dx + 8);
            void **vt = *(void ***)dev;
            ((int (*)(void *, int, int))vt[0xe4 / 4])(dev, 0x39, stencilRef);
        } while (*(int *)imp_alwaysfails);
        *(int *)((byte *)imp_dxState + 0x2010) = stencilRef;
    }

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 1258 */
static void RB_SetShadowCookieCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;
    float shadowMapSize, invSize;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    RB_SetShadowLookupMatrix(cmd + 4);

    shadowMapSize = (float)*(int *)((byte *)imp_dx + 0x2c8c);
    invSize = 1.0f / shadowMapSize;

    /* Shadow map size constants */
    *(float *)((char *)&backEnd + 704) = shadowMapSize;
    *(float *)((char *)&backEnd + 708) = shadowMapSize;
    *(float *)((char *)&backEnd + 712) = invSize;
    *(float *)((char *)&backEnd + 716) = invSize;

    /* Shadow intensity */
    *(int *)((char *)&backEnd + 720) = 0;
    *(int *)((char *)&backEnd + 724) = 0;
    *(int *)((char *)&backEnd + 728) = 0;
    *(int *)((char *)&backEnd + 732) = *(int *)(cmd + 0x44);

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2761 */
static __attribute__((naked))
void RB_BeginViewCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2761 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* execState */
        /* { scope 1 */
        "movl (%esi), %ebx\n" /* line 2765 | execState, cmd */
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd5af4_000d5ddd\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd5af4_000d5ddd\n"
        ".Lfd5af4_000d5b18:\n"
        "movl 0x2c(%ebx), %eax\n" /* line 2769 | cmd */
        "movl %eax, backEnd+948\n"
        "movl 4(%ebx), %eax\n" /* line 2771 | cmd */
        "movl %eax, backEnd+952\n"
        "movl 8(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+956\n"
        "movl 0xc(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+960\n"
        "movl 0x10(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+964\n"
        "movl 0x14(%ebx), %edx\n" /* line 2772 | cmd */
        "movl %edx, backEnd+968\n"
        "movl 0x18(%ebx), %eax\n" /* line 2773 | cmd */
        "movl %eax, backEnd+972\n"
        "movl 0x1c(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+976\n"
        "movl 0x20(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+980\n"
        "movl 0x24(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+984\n"
        "movl 0x28(%ebx), %eax\n" /* cmd */
        "movl %eax, backEnd+988\n"
        "movl 0x30(%edx), %eax\n" /* line 2775 */
        "movl %eax, backEnd+992\n"
        "movl 0x34(%edx), %eax\n" /* line 2776 */
        "movl %eax, backEnd+996\n"
        "movl 0x38(%edx), %eax\n" /* line 2777 */
        "movl %eax, backEnd+1000\n"
        "movl 0x3c(%edx), %eax\n" /* line 2778 */
        "movl %eax, backEnd+1004\n"
        "movl 0xc8(%edx), %eax\n" /* line 2780 */
        "movl %eax, backEnd+1008\n"
        "movl 0xcc(%edx), %eax\n"
        "movl %eax, backEnd+1012\n"
        "movl 0xd0(%edx), %eax\n"
        "movl %eax, backEnd+1016\n"
        "movl 0xd4(%edx), %eax\n"
        "movl %eax, backEnd+1020\n"
        "movl 0xd8(%edx), %eax\n"
        "movl %eax, backEnd+1024\n"
        "movl 0xdc(%edx), %eax\n"
        "movl %eax, backEnd+1028\n"
        "movl 0xe0(%edx), %eax\n"
        "movl %eax, backEnd+1032\n"
        "movl 0xe4(%edx), %eax\n"
        "movl %eax, backEnd+1036\n"
        "movl 0xe8(%edx), %eax\n"
        "movl %eax, backEnd+1040\n"
        "movl 0xec(%edx), %eax\n"
        "movl %eax, backEnd+1044\n"
        "movl 0xf0(%edx), %eax\n"
        "movl %eax, backEnd+1048\n"
        "movl 0xf4(%edx), %eax\n"
        "movl %eax, backEnd+1052\n"
        "movl 0xf8(%edx), %eax\n"
        "movl %eax, backEnd+1056\n"
        "movl 0xfc(%edx), %eax\n"
        "movl %eax, backEnd+1060\n"
        "movl 0x100(%edx), %eax\n"
        "movl %eax, backEnd+1064\n"
        "movl 0x104(%edx), %eax\n"
        "movl %eax, backEnd+1068\n"
        "movl $0, backEnd+1072\n" /* line 2781 */
        "movl $1, backEnd+1076\n" /* line 2782 */
        "movl imp_vidConfig, %edx\n" /* line 2783 */
        "movl (%edx), %eax\n"
        "movl %eax, backEnd+1080\n"
        "movl 4(%edx), %eax\n" /* line 2784 */
        "movl %eax, backEnd+1084\n"
        "movl imp_dxState, %eax\n" /* line 2797 */
        "movl 0x20a4(%eax), %ebx\n" /* cmd */
        "testl %ebx, %ebx\n" /* cmd */
        "je .Lfd5af4_000d5e31\n"
        ".Lfd5af4_000d5c7d:\n"
        "movl backEnd+968, %eax\n" /* line 2732 */
        "leal 0x108(%eax), %ebx\n"
        "movss lit4_002ed5d0, %xmm6\n" /* line 2740 | 1.0f */
        "movaps %xmm6, %xmm2\n"
        "divss 0x3c(%ebx), %xmm2\n"
        "movaps %xmm2, %xmm3\n" /* line 2741 */
        "mulss 0x38(%ebx), %xmm3\n"
        "subss 8(%eax), %xmm3\n"
        "movaps %xmm2, %xmm1\n"
        "mulss 0x34(%ebx), %xmm1\n"
        "subss 4(%eax), %xmm1\n"
        "movaps %xmm2, %xmm0\n" /* line 447 */
        "mulss 0x30(%ebx), %xmm0\n"
        "subss (%eax), %xmm0\n"
        "movss %xmm0, backEnd+240\n"
        "movss %xmm1, backEnd+244\n" /* line 448 */
        "movss %xmm3, backEnd+248\n" /* line 449 */
        "movl $0, backEnd+252\n" /* line 450 */
        "movaps %xmm2, %xmm5\n" /* line 2745 */
        "addss %xmm2, %xmm5\n"
        "movl backEnd+1080, %edx\n" /* line 2750 */
        "cvtsi2ssl %edx, %xmm0\n"
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lfd5af4_000d5de7\n"
        "movaps %xmm6, %xmm1\n"
        ".Lfd5af4_000d5cfd:\n"
        "divss %xmm1, %xmm0\n" /* line 2750 */
        "movaps %xmm6, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movl backEnd+1084, %edx\n" /* line 2751 */
        "cvtsi2ssl %edx, %xmm3\n"
        "cmpl $1, %edx\n" /* line 144 */
        "jbe .Lfd5af4_000d5e29\n"
        ".Lfd5af4_000d5d1e:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lfd5af4_000d5d28:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lfd5af4_000d5e3b\n"
        "subl $1, %eax\n"
        "jne .Lfd5af4_000d5d28\n"
        "testl %ecx, %ecx\n"
        "js .Lfd5af4_000d5e52\n"
        ".Lfd5af4_000d5d3f:\n"
        "cvtsi2ssl %ecx, %xmm4\n"
        ".Lfd5af4_000d5d43:\n"
        "mulss %xmm5, %xmm0\n" /* line 2752 */
        "movaps %xmm0, %xmm2\n"
        "mulss 8(%ebx), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 4(%ebx), %xmm1\n"
        "mulss (%ebx), %xmm0\n" /* line 447 */
        "movss %xmm0, backEnd+256\n"
        "movss %xmm1, backEnd+260\n" /* line 448 */
        "movss %xmm2, backEnd+264\n" /* line 449 */
        "movl $0, backEnd+268\n" /* line 450 */
        "divss %xmm4, %xmm3\n" /* line 2753 */
        "movaps %xmm6, %xmm0\n"
        "divss %xmm3, %xmm0\n"
        "xorps color_table+32, %xmm5\n"
        "mulss %xmm5, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        "mulss 0x18(%ebx), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "mulss 0x14(%ebx), %xmm1\n"
        "mulss 0x10(%ebx), %xmm0\n" /* line 447 */
        "movss %xmm0, backEnd+272\n"
        "movss %xmm1, backEnd+276\n" /* line 448 */
        "movss %xmm2, backEnd+280\n" /* line 449 */
        "movl $0, backEnd+284\n" /* line 450 */
        "calll RB_Set3D\n" /* line 2801 */
        "movl (%esi), %edx\n" /* line 169 */
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        "popl %ebx\n" /* line 2804 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd5af4_000d5ddd:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfd5af4_000d5b18\n"
        ".Lfd5af4_000d5de7:\n"
        "movl $1, %ecx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lfd5af4_000d5df1:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lfd5af4_000d5e7e\n"
        "subl $1, %eax\n"
        "jne .Lfd5af4_000d5df1\n"
        "testl %ecx, %ecx\n"
        "js .Lfd5af4_000d5e68\n"
        ".Lfd5af4_000d5e04:\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "divss %xmm1, %xmm0\n" /* line 2750 */
        "movaps %xmm6, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "movl backEnd+1084, %edx\n" /* line 2751 */
        "cvtsi2ssl %edx, %xmm3\n"
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lfd5af4_000d5d1e\n"
        ".Lfd5af4_000d5e29:\n"
        "movaps %xmm6, %xmm4\n"
        "jmp .Lfd5af4_000d5d43\n"
        ".Lfd5af4_000d5e31:\n"
        "calll RB_UpdateViewportConstants\n" /* line 2798 */
        "jmp .Lfd5af4_000d5c7d\n"
        ".Lfd5af4_000d5e3b:\n"
        "testl %ecx, %ecx\n" /* line 144 */
        "jns .Lfd5af4_000d5d3f\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm4\n"
        "addss %xmm4, %xmm4\n"
        "jmp .Lfd5af4_000d5d43\n"
        ".Lfd5af4_000d5e52:\n"
        "movl %ecx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm4\n"
        "addss %xmm4, %xmm4\n"
        "jmp .Lfd5af4_000d5d43\n"
        ".Lfd5af4_000d5e68:\n"
        "movl %ecx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lfd5af4_000d5cfd\n"
        ".Lfd5af4_000d5e7e:\n"
        "testl %ecx, %ecx\n"
        "jns .Lfd5af4_000d5e04\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm1\n"
        "addss %xmm1, %xmm1\n"
        "jmp .Lfd5af4_000d5cfd\n"
    );
}

/* line 2807 */
static void RB_SetViewportCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    /* Copy viewport rect from cmd to backEnd */
    *(int *)((char *)&backEnd + 992) = *(int *)(cmd + 4);
    *(int *)((char *)&backEnd + 996) = *(int *)(cmd + 8);
    *(int *)((char *)&backEnd + 1000) = *(int *)(cmd + 12);
    *(int *)((char *)&backEnd + 1004) = *(int *)(cmd + 16);
    *(byte *)((char *)&backEnd + 1212) = 1;
    RB_UpdateViewportConstants();

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2501 */
static void RB_SetRenderTargetCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    RB_SetRenderTarget(*(int *)(cmd + 4));

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 936 */
int rb_rdsl_diag = 0;
int rb_rdsl_call_count = 0;
__attribute__((naked))
void RB_RenderDrawSurfList(GfxDrawSurf *drawSurfs, int drawSurfCount, MaterialTechniqueType techType, GfxDrawSurfOrder order)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 936 */
        "movl %esp, %ebp\n"
        "incl rb_rdsl_call_count\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: radians, w, z */
        "movl $backEnd+1096, backEnd+1088\n" /* line 995 */
        "movl $0, backEnd+1092\n" /* line 996 */
        "movl 0x14(%ebp), %edi\n" /* line 1002 | order, drawSurf */
        "testl %edi, %edi\n" /* drawSurf */
        "jne .Lfd5f2e_000d61aa\n"
        "movl 8(%ebp), %edi\n" /* drawSurfs, drawSurf */
        "movl $1, %eax\n"
        ".Lfd5f2e_000d5f5e:\n"
        "movl 0xc(%ebp), %esi\n" /* line 1014 | drawSurfCount */
        "testl %esi, %esi\n"
        "jg .Lfd5f2e_000d5ff6\n"
        "movb $1, -0x5a(%ebp)\n" /* isWorldSpaceEntPrev */
        "movl $0, -0x54(%ebp)\n" /* depthRange */
        ".Lfd5f2e_000d5f74:\n"
        "movl tess+370640, %ebx\n" /* line 261 */
        "testl %ebx, %ebx\n"
        "jne .Lfd5f2e_000d5fb6\n"
        "movl tess+370656, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfd5f2e_000d5fb6\n"
        "movl -0x54(%ebp), %edx\n" /* line 1158 | depthRange */
        "testl %edx, %edx\n"
        "jne .Lfd5f2e_000d5fc2\n"
        ".Lfd5f2e_000d5f8f:\n"
        "cmpb $0, -0x5a(%ebp)\n" /* line 1165 | isWorldSpaceEntPrev */
        "jne .Lfd5f2e_000d5f9a\n"
        "calll RB_PopMatrixStack\n" /* line 1166 */
        ".Lfd5f2e_000d5f9a:\n"
        "movl $0, backEnd+1088\n" /* line 1169 */
        "movl $0, backEnd+1092\n" /* line 1170 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1173 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: radians, w, z */
        ".Lfd5f2e_000d5fb6:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl -0x54(%ebp), %edx\n" /* line 1158 | depthRange */
        "testl %edx, %edx\n"
        "je .Lfd5f2e_000d5f8f\n"
        ".Lfd5f2e_000d5fc2:\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1160 */
        "movl $0, (%esp)\n"
        "calll RB_SetDepthRange\n"
        "cmpl $8, -0x54(%ebp)\n" /* line 1161 | depthRange */
        "jne .Lfd5f2e_000d5f8f\n"
        "movl backEnd+968, %eax\n" /* line 1162 */
        "movl 0xc0(%eax), %eax\n"
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetDepthHackNearClip\n"
        "jmp .Lfd5f2e_000d5f8f\n"
        ".Lfd5f2e_000d5ff6:\n"
        "shll $3, %eax\n" /* line 1014 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x10(%ebp), %eax\n" /* techType */
        "movl %eax, -0x3c(%ebp)\n" /* actualTechTypePrev */
        "movl $0, -0x64(%ebp)\n" /* materialPrev */
        "movl $0x1f, -0x60(%ebp)\n" /* lightmapPrev */
        "movb $0, -0x5c(%ebp)\n" /* ignoreSurfs */
        "movb $1, -0x5b(%ebp)\n" /* isWorldSpaceEnt */
        "movl $0x7fe, -0x58(%ebp)\n" /* entityIndexPrev */
        "movl $0, -0x50(%ebp)\n" /* depthRangePrev */
        "movl $0xffffffff, -0x48(%ebp)\n" /* prevSort */
        "pxor %xmm0, %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* materialTime */
        "movss lit4_002ed684, %xmm0\n" /* 3.4028234663852886e+38f */
        "movss %xmm0, -0x40(%ebp)\n" /* materialTimePrev */
        "movl $0, -0x4c(%ebp)\n" /* iteration */
        "movl $0, -0x54(%ebp)\n" /* depthRange */
        "movb $1, -0x5a(%ebp)\n" /* isWorldSpaceEntPrev */
        "movl (%edi), %eax\n" /* line 1016 | drawSurf */
        "cmpl -0x48(%ebp), %eax\n" /* prevSort */
        "je .Lfd5f2e_000d610b\n"
        ".Lfd5f2e_000d6060:\n"
        "incl g_rdsl_sortchange\n"
        "movl %eax, -0x48(%ebp)\n" /* line 1027 | prevSort */
        "leal -0x20(%ebp), %eax\n" /* line 1028 | lightmap */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* material */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* entityIndex */
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* prevSort */
        "movl %eax, (%esp)\n"
        "calll R_DecomposeSort\n"
        "movl -0x24(%ebp), %edx\n" /* line 1029 | entityIndex */
        "movl -0x20(%ebp), %eax\n" /* lightmap, lmapIndex */
        /* { scope 2 */
        /* { scope 3 */
        "cmpl $6, 0x10(%ebp)\n" /* line 881 | techType */
        "je .Lfd5f2e_000d6168\n"
        ".Lfd5f2e_000d6093:\n"
        "movl imp_r_depthPrepassModels, %eax\n" /* line 892 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfd5f2e_000d60ad\n"
        "movl 0x10(%ebp), %ebx\n" /* techType */
        "testl %ebx, %ebx\n"
        "je .Lfd5f2e_000d6122\n"
        "cmpl $2, 0x10(%ebp)\n" /* techType */
        "je .Lfd5f2e_000d6122\n"
        ".Lfd5f2e_000d60ad:\n"
        "movl 0x10(%ebp), %eax\n" /* line 900 | techType */
        "subl $3, %eax\n"
        "movl 0x10(%ebp), %ebx\n" /* techType */
        "cmpl $0x17, %eax\n" /* line 905 */
        "jbe .Lfd5f2e_000d619e\n"
        /* } scope */
        /* } scope */
        ".Lfd5f2e_000d60bf:\n"
        "incl g_rdsl_bf_entry\n"
        "movl -0x1c(%ebp), %esi\n" /* line 1032 | material */
        "movl imp_r_drawDecals, %eax\n" /* line 917 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfd5f2e_000d60d5\n"
        "testb $0x30, 0x30(%esi)\n"
        "je .Lfd5f2e_000d60d5\n"
        "incl g_rdsl_ignore_decal\n"
        "jmp .Lfd5f2e_000d60e9\n"
        ".Lfd5f2e_000d60d5:\n"
        "cmpl $-1, %ebx\n" /* line 926 */
        "jne .Lfd5f2e_000d60d5b\n"
        "incl g_rdsl_ignore_techm1\n"
        "jmp .Lfd5f2e_000d60e9\n"
        ".Lfd5f2e_000d60d5b:\n"
        "movl 0x38(%esi), %eax\n" /* line 929 */
        "movl 4(%eax, %ebx, 4), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfd5f2e_000d61cc\n"
        "incl g_rdsl_ignore_technull\n"
        /* Save material ptr and techtype for first NULL tech occurrence */
        /* Only save for LIGHTMAP type (6) */
        "cmpl $6, %ebx\n"
        "jne .Lskip_technull_save\n"
        "cmpl $30, g_technull_saved\n"
        "jge .Lskip_technull_save\n"
        "movl %esi, g_technull_mat\n"
        "movl %ebx, g_technull_type\n"
        "incl g_technull_saved\n"
        ".Lskip_technull_save:\n"
        ".Lfd5f2e_000d60e9:\n"
        "movb $1, -0x5c(%ebp)\n" /* line 1032 | ignoreSurfs */
        ".Lfd5f2e_000d60ed:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 1014 | iteration */
        "addl -0x2c(%ebp), %edi\n" /* drawSurf */
        "movl -0x4c(%ebp), %eax\n" /* iteration */
        "cmpl %eax, 0xc(%ebp)\n" /* drawSurfCount */
        "je .Lfd5f2e_000d5f74\n"
        "movl (%edi), %eax\n" /* line 1016 | drawSurf */
        "cmpl -0x48(%ebp), %eax\n" /* prevSort */
        "jne .Lfd5f2e_000d6060\n"
        ".Lfd5f2e_000d610b:\n"
        "cmpb $0, -0x5c(%ebp)\n" /* line 1018 | ignoreSurfs */
        "jne .Lfd5f2e_000d60ed\n"
        ".Lfd5f2e_000d6111:\n"
        "movl 4(%edi), %eax\n" /* line 1151 | drawSurf */
        "movl (%eax), %edx\n"
        "incl g_rb_tess_type_counts(, %edx, 4)\n" /* diagnostic: count per type */
        "movl %edx, g_rb_last_tess_type\n" /* diagnostic: track last type for idxzero */
        "incl g_tess_since_begin\n"
        "movl %eax, (%esp)\n"
        "calll *rb_tessTable(, %edx, 4)\n"
        "jmp .Lfd5f2e_000d60ed\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd5f2e_000d6122:\n"
        "cmpl $0x7ff, %edx\n" /* line 894 */
        "je .Lfd5f2e_000d615e\n"
        "cmpl $0x7fd, %edx\n" /* line 897 */
        "jg .Lfd5f2e_000d60ad\n"
        "leal (, %edx, 8), %eax\n" /* line 899 */
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl backEnd+964, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "cmpl $2, (%eax)\n" /* line 900 */
        "jg .Lfd5f2e_000d60ad\n"
        "testb $1, 5(%eax)\n"
        "jne .Lfd5f2e_000d60ad\n"
        ".Lfd5f2e_000d615e:\n"
        "movl $0xffffffff, %ebx\n" /* line 908 */
        "jmp .Lfd5f2e_000d60bf\n"
        ".Lfd5f2e_000d6168:\n"
        "cmpl $0x1f, %eax\n" /* line 881 */
        "jne .Lfd5f2e_000d6093\n"
        "cmpl $0x7fe, %edx\n" /* line 883 */
        "je .Lfd5f2e_000d6199\n"
        "cmpl $0x7ff, %edx\n" /* line 885 */
        "je .Lfd5f2e_000d61c5\n"
        "leal (, %edx, 8), %eax\n" /* line 887 */
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl backEnd+964, %edx\n"
        "cmpl $2, (%edx, %eax, 4)\n"
        "je .Lfd5f2e_000d61be\n"
        ".Lfd5f2e_000d6199:\n"
        "movl $9, %ebx\n" /* line 900 */
        ".Lfd5f2e_000d619e:\n"
        "calll RB_FogOffset\n" /* line 907 */
        "addl %eax, %ebx\n" /* line 908 */
        "jmp .Lfd5f2e_000d60bf\n"
        /* } scope */
        /* } scope */
        ".Lfd5f2e_000d61aa:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1010 | drawSurfCount */
        "movl 8(%ebp), %edx\n" /* drawSurfs */
        "leal -8(%edx, %eax, 8), %edi\n" /* drawSurf */
        "movl $0xffffffff, %eax\n"
        "jmp .Lfd5f2e_000d5f5e\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfd5f2e_000d61be:\n"
        "movl $0xc, %ebx\n" /* line 887 */
        "jmp .Lfd5f2e_000d619e\n"
        ".Lfd5f2e_000d61c5:\n"
        "movl $0xf, %ebx\n" /* line 885 */
        "jmp .Lfd5f2e_000d619e\n"
        /* } scope */
        /* } scope */
        ".Lfd5f2e_000d61cc:\n"
        "incl g_rdsl_noignore\n"
        "movb $0, -0x5c(%ebp)\n" /* line 1032 | ignoreSurfs */
        "movl -0x24(%ebp), %ecx\n" /* line 1036 | entityIndex */
        "cmpl %ecx, -0x58(%ebp)\n" /* entityIndexPrev */
        "je .Lfd5f2e_000d6580\n"
        "leal -0x7fe(%ecx), %eax\n" /* line 1043 */
        "cmpl $1, %eax\n"
        "jbe .Lfd5f2e_000d6589\n"
        "leal (, %ecx, 8), %eax\n"
        "subl %ecx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl backEnd+964, %edx\n"
        "movl (%edx, %eax, 4), %eax\n"
        "cmpb $0, refEntIsInWorldSpace(%eax)\n"
        "jne .Lfd5f2e_000d6589\n"
        "movb $0, -0x5b(%ebp)\n" /* isWorldSpaceEnt */
        ".Lfd5f2e_000d6211:\n"
        "movb $0, -0x59(%ebp)\n" /* line 1047 | entityMergable */
        ".Lfd5f2e_000d6215:\n"
        "cmpl $0x7fe, %ecx\n" /* line 1049 */
        "je .Lfd5f2e_000d6572\n"
        "leal (, %ecx, 8), %eax\n" /* line 1052 */
        "subl %ecx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl backEnd+964, %edx\n"
        "movss 0x5c(%edx, %eax, 4), %xmm0\n"
        "movss %xmm0, -0x44(%ebp)\n" /* materialTime */
        ".Lfd5f2e_000d623e:\n"
        "cmpl %esi, -0x64(%ebp)\n" /* line 1055 | materialPrev */
        "je .Lfd5f2e_000d64df\n"
        ".Lfd5f2e_000d6247:\n"
        "movl tess+370640, %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfd5f2e_000d625a\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd5f2e_000d6262\n"
        ".Lfd5f2e_000d625a:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl -0x1c(%ebp), %esi\n" /* material */
        ".Lfd5f2e_000d6262:\n"
        "movss -0x44(%ebp), %xmm0\n" /* line 1058 | materialTime */
        "ucomiss -0x40(%ebp), %xmm0\n" /* materialTimePrev */
        "jp .Lfd5f2e_000d6497\n"
        "jne .Lfd5f2e_000d6497\n"
        ".Lfd5f2e_000d6277:\n"
        "movl -0x20(%ebp), %eax\n" /* line 1060 | lightmap */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* actualTechType */
        "movl %esi, (%esp)\n"
        "calll RB_BeginSurface\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1061 | material */
        "movl %eax, -0x64(%ebp)\n" /* materialPrev */
        "movl -0x20(%ebp), %edx\n" /* line 1062 | lightmap */
        "movl %edx, -0x60(%ebp)\n" /* lightmapPrev */
        "movss -0x44(%ebp), %xmm0\n" /* materialTime */
        "movss %xmm0, -0x40(%ebp)\n" /* materialTimePrev */
        "movl %ebx, -0x3c(%ebp)\n" /* actualTechType, actualTechTypePrev */
        "movl -0x24(%ebp), %ecx\n" /* entityIndex */
        ".Lfd5f2e_000d62a6:\n"
        "cmpl %ecx, -0x58(%ebp)\n" /* line 1067 | entityIndexPrev */
        "je .Lfd5f2e_000d6111\n"
        "cmpl $0x7fe, %ecx\n" /* line 1072 */
        "je .Lfd5f2e_000d647e\n"
        "cmpl $0x7ff, %ecx\n" /* line 1078 */
        "je .Lfd5f2e_000d647e\n"
        "leal (, %ecx, 8), %eax\n" /* line 1088 */
        "subl %ecx, %eax\n"
        "leal (%ecx, %eax, 4), %eax\n"
        "movl backEnd+964, %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, backEnd+1088\n"
        "cmpl $1, (%eax)\n" /* line 1089 */
        "jle .Lfd5f2e_000d6467\n"
        "movl $0, backEnd+1092\n" /* line 1092 */
        ".Lfd5f2e_000d62f4:\n"
        "cmpb $0, -0x5b(%ebp)\n" /* line 1095 | isWorldSpaceEnt */
        "je .Lfd5f2e_000d6339\n"
        "cmpb $0, -0x5a(%ebp)\n" /* line 1097 | isWorldSpaceEntPrev */
        "jne .Lfd5f2e_000d6305\n"
        "calll RB_PopMatrixStack\n" /* line 1098 */
        ".Lfd5f2e_000d6305:\n"
        "movl -0x50(%ebp), %eax\n" /* line 1100 | depthRangePrev */
        "testl %eax, %eax\n"
        "je .Lfd5f2e_000d6327\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1102 */
        "movl $0, (%esp)\n"
        "calll RB_SetDepthRange\n"
        "movl $0, -0x50(%ebp)\n" /* depthRangePrev */
        ".Lfd5f2e_000d6327:\n"
        "movl -0x24(%ebp), %eax\n" /* line 1145 | entityIndex */
        "movl %eax, -0x58(%ebp)\n" /* entityIndexPrev */
        "movzbl -0x5b(%ebp), %edx\n" /* isWorldSpaceEnt */
        "movb %dl, -0x5a(%ebp)\n" /* isWorldSpaceEntPrev */
        "jmp .Lfd5f2e_000d6111\n"
        ".Lfd5f2e_000d6339:\n"
        "cmpb $0, -0x5a(%ebp)\n" /* line 1108 | isWorldSpaceEntPrev */
        "je .Lfd5f2e_000d6344\n"
        "calll RB_PushMatrixStack\n" /* line 1109 */
        ".Lfd5f2e_000d6344:\n"
        "movl backEnd+1088, %eax\n" /* line 1110 */
        "movl %eax, (%esp)\n"
        "calll RB_SetWorldMatrixForEntity\n"
        "movl backEnd+1088, %eax\n" /* line 1113 */
        "movl 4(%eax), %eax\n"
        "andl $0x18, %eax\n"
        "movl %eax, -0x54(%ebp)\n" /* depthRange */
        "cmpl %eax, -0x50(%ebp)\n" /* line 1114 | depthRangePrev */
        "je .Lfd5f2e_000d6327\n"
        "movl tess+370640, %eax\n" /* line 1116 */
        "testl %eax, %eax\n"
        "jne .Lfd5f2e_000d6376\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd5f2e_000d63c5\n"
        ".Lfd5f2e_000d6376:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfd5f2e_000d63c5\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd5f2e_000d63ba\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd5f2e_000d63bf\n"
        ".Lfd5f2e_000d63ba:\n"
        "calll RB_EndSurface\n" /* line 262 */
        ".Lfd5f2e_000d63bf:\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        ".Lfd5f2e_000d63c5:\n"
        "cmpl $8, -0x54(%ebp)\n" /* line 1122 | depthRange */
        "je .Lfd5f2e_000d641b\n"
        "jg .Lfd5f2e_000d63f9\n"
        "movl -0x54(%ebp), %esi\n" /* depthRange */
        "testl %esi, %esi\n"
        "jne .Lfd5f2e_000d63e8\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1125 */
        "movl $0, (%esp)\n"
        "calll RB_SetDepthRange\n"
        ".Lfd5f2e_000d63e8:\n"
        "cmpl $8, -0x50(%ebp)\n" /* line 1138 | depthRangePrev */
        "je .Lfd5f2e_000d6444\n"
        "movl -0x54(%ebp), %eax\n" /* depthRange */
        "movl %eax, -0x50(%ebp)\n" /* depthRangePrev */
        "jmp .Lfd5f2e_000d6327\n"
        ".Lfd5f2e_000d63f9:\n"
        "cmpl $0x10, -0x54(%ebp)\n" /* line 1122 | depthRange */
        "je .Lfd5f2e_000d6405\n"
        "cmpl $0x18, -0x54(%ebp)\n" /* depthRange */
        "jne .Lfd5f2e_000d63e8\n"
        ".Lfd5f2e_000d6405:\n"
        "movl $0x3f000000, 4(%esp)\n" /* line 1135 */
        "movl $0, (%esp)\n"
        "calll RB_SetDepthRange\n"
        "jmp .Lfd5f2e_000d63e8\n"
        ".Lfd5f2e_000d641b:\n"
        "movl backEnd+968, %eax\n" /* line 1129 */
        "movl 0x148(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetDepthHackNearClip\n"
        "movl $0x3e4ccccd, 4(%esp)\n" /* line 1130 */
        "movl $0, (%esp)\n"
        "calll RB_SetDepthRange\n"
        "jmp .Lfd5f2e_000d63e8\n"
        ".Lfd5f2e_000d6444:\n"
        "movl backEnd+968, %eax\n" /* line 1139 */
        "movl 0xc0(%eax), %eax\n"
        "xorl $0x80000000, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetDepthHackNearClip\n"
        "movl -0x54(%ebp), %edx\n" /* depthRange */
        "movl %edx, -0x50(%ebp)\n" /* depthRangePrev */
        "jmp .Lfd5f2e_000d6327\n"
        ".Lfd5f2e_000d6467:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 1090 */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal backEnd+12056(, %eax, 8), %eax\n"
        "movl %eax, backEnd+1092\n"
        "jmp .Lfd5f2e_000d62f4\n"
        ".Lfd5f2e_000d647e:\n"
        "movl $backEnd+1096, backEnd+1088\n" /* line 1080 */
        "movl $0, backEnd+1092\n" /* line 1081 */
        "jmp .Lfd5f2e_000d62f4\n"
        ".Lfd5f2e_000d6497:\n"
        "movss backEnd+956, %xmm0\n" /* line 1059 */
        "subss -0x44(%ebp), %xmm0\n" /* materialTime */
        "movss %xmm0, -0x34(%ebp)\n" /* w */
        "movss %xmm0, (%esp)\n" /* line 861 */
        "calll floorf\n"
        "fstps -0x68(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* w */
        "subss -0x68(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* z */
        "movl imp_r_rendererInUse, %eax\n" /* line 864 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfd5f2e_000d6518\n"
        "movss %xmm0, backEnd+1244\n" /* line 866 */
        "jmp .Lfd5f2e_000d6277\n"
        ".Lfd5f2e_000d64df:\n"
        "movl -0x60(%ebp), %eax\n" /* line 1055 | lightmapPrev */
        "cmpl -0x20(%ebp), %eax\n" /* lightmap */
        "jne .Lfd5f2e_000d6247\n"
        "cmpl %ebx, -0x3c(%ebp)\n" /* actualTechType, actualTechTypePrev */
        "jne .Lfd5f2e_000d6247\n"
        "movss -0x44(%ebp), %xmm0\n" /* materialTime */
        "ucomiss -0x40(%ebp), %xmm0\n" /* materialTimePrev */
        "jne .Lfd5f2e_000d6247\n"
        "jp .Lfd5f2e_000d6247\n"
        "cmpb $0, -0x59(%ebp)\n" /* entityMergable */
        "jne .Lfd5f2e_000d62a6\n"
        "jmp .Lfd5f2e_000d6247\n"
        ".Lfd5f2e_000d6518:\n"
        "cvtss2sd -0x30(%ebp), %xmm0\n" /* line 871 | z */
        "mulsd lit8_00307c98, %xmm0\n" /* 6.283185307179586 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 486 */
        "calll cosf\n"
        "fstps backEnd+36\n"
        /* } scope */
        /* { scope 2 */
        "movss -0x38(%ebp), %xmm0\n" /* line 485 | radians */
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps backEnd+32\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 449 | z */
        "movss %xmm0, backEnd+40\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 450 | w */
        "movss %xmm0, backEnd+44\n"
        "jmp .Lfd5f2e_000d6277\n"
        /* } scope */
        ".Lfd5f2e_000d6572:\n"
        "pxor %xmm0, %xmm0\n" /* line 1049 */
        "movss %xmm0, -0x44(%ebp)\n" /* materialTime */
        "jmp .Lfd5f2e_000d623e\n"
        ".Lfd5f2e_000d6580:\n"
        "movb $1, -0x59(%ebp)\n" /* line 1036 | entityMergable */
        "jmp .Lfd5f2e_000d623e\n"
        ".Lfd5f2e_000d6589:\n"
        "movb $1, -0x5b(%ebp)\n" /* line 1043 | isWorldSpaceEnt */
        "cmpb $0, -0x5a(%ebp)\n" /* line 1047 | isWorldSpaceEntPrev */
        "je .Lfd5f2e_000d6211\n"
        "movb $1, -0x59(%ebp)\n" /* entityMergable */
        "jmp .Lfd5f2e_000d6215\n"
    );
}

/* line 1222 */
static void RB_DrawSurfsCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;
    int idx;

    cmd = *(byte **)execState;
    /* Advance cmd pointer before processing */
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    if (*(byte *)((char *)&backEnd + 1213))
        RB_Set3D();

    if (*(byte *)((char *)&backEnd + 1212))
        RB_UpdateViewport();

    /* Diagnostic logging */
    rb_drawsurfscmd_count++;
    idx = rb_drawsurfscmd_count - 1;
    if (idx < 3) {
        g_dsc_techtype[idx] = *(int *)(cmd + 0x10);
        g_dsc_surfcount[idx] = *(int *)(cmd + 0xc);
    }

    /* Check dxState skip flag */
    if (*(byte *)((byte *)imp_dxState + 0x20c8)) {
        rb_drawsurfscmd_dxskip++;
        return;
    }

    RB_RenderDrawSurfList(
        *(GfxDrawSurf **)(cmd + 8),
        *(int *)(cmd + 0xc),
        *(int *)(cmd + 0x10),
        *(int *)(cmd + 4));
}

/* line 1991 */
static void RB_DrawSunPostEffectsCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    cmd = *(byte **)execState;
    RB_DrawSunPostEffects(*(void **)(cmd + 4));

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 197 */
static __attribute__((naked))
void RB_Set2D(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 197 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1bc, %esp\n"
        /* { scope 1 */
        "movl tess+370640, %ebx\n" /* line 261 */
        "testl %ebx, %ebx\n"
        "jne .Lfd6670_000d66b1\n"
        "movl tess+370656, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfd6670_000d66b1\n"
        "movb $1, backEnd+1213\n" /* line 212 */
        "leal -0x28(%ebp), %eax\n" /* line 214 | viewport */
        "movl %eax, (%esp)\n"
        "calll RB_GetViewport\n"
        "testb %al, %al\n"
        "jne .Lfd6670_000d66cc\n"
        /* } scope */
        ".Lfd6670_000d66a6:\n"
        "addl $0x1bc, %esp\n" /* line 296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd6670_000d66b1:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movb $1, backEnd+1213\n" /* line 212 */
        "leal -0x28(%ebp), %eax\n" /* line 214 | viewport */
        "movl %eax, (%esp)\n"
        "calll RB_GetViewport\n"
        "testb %al, %al\n"
        "je .Lfd6670_000d66a6\n"
        ".Lfd6670_000d66cc:\n"
        "cvtsi2ssl -0x20(%ebp), %xmm0\n" /* line 218 */
        "movss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movaps %xmm2, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* line 219 */
        "movaps %xmm2, %xmm3\n"
        "divss %xmm0, %xmm3\n"
        "movaps %xmm3, %xmm0\n"
        "cld\n" /* line 221 */
        "movl $0x10, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0xa8(%ebp), %edi\n" /* transform */
        "rep stosl %eax, %es:(%edi)\n"
        "addss %xmm1, %xmm1\n" /* line 222 */
        "movss %xmm1, -0xa8(%ebp)\n" /* transform */
        "mulss lit4_002ed628, %xmm0\n" /* line 223 | -2.0f */
        "movss %xmm0, -0x94(%ebp)\n"
        "movl $0xbf800000, -0x78(%ebp)\n" /* line 231 */
        "movss %xmm2, -0x74(%ebp)\n" /* line 232 */
        "movss %xmm2, -0x80(%ebp)\n" /* line 245 */
        "movss %xmm2, -0x6c(%ebp)\n" /* line 247 */
        "leal -0x68(%ebp), %eax\n" /* line 249 | identity */
        "movl %eax, (%esp)\n"
        "calll MatrixIdentity44\n"
        "movl backEnd+11904, %edx\n" /* line 251 */
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edx, %eax\n"
        "shll $7, %eax\n"
        "subl %ecx, %eax\n"
        "subl %edx, %eax\n"
        "shll $5, %eax\n"
        "leal backEnd+1248(%eax), %esi\n" /* activeMatrices */
        "movl -0xa8(%ebp), %eax\n" /* line 252 | transform */
        "movl %eax, 0x340(%esi)\n" /* activeMatrices */
        "movl -0xa4(%ebp), %eax\n"
        "movl %eax, 0x344(%esi)\n" /* activeMatrices */
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, 0x348(%esi)\n" /* activeMatrices */
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, 0x34c(%esi)\n" /* activeMatrices */
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, 0x350(%esi)\n" /* activeMatrices */
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, 0x354(%esi)\n" /* activeMatrices */
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, 0x358(%esi)\n" /* activeMatrices */
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, 0x35c(%esi)\n" /* activeMatrices */
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, 0x360(%esi)\n" /* activeMatrices */
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, 0x364(%esi)\n" /* activeMatrices */
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, 0x368(%esi)\n" /* activeMatrices */
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, 0x36c(%esi)\n" /* activeMatrices */
        "movl -0x78(%ebp), %eax\n"
        "movl %eax, 0x370(%esi)\n" /* activeMatrices */
        "movl -0x74(%ebp), %eax\n"
        "movl %eax, 0x374(%esi)\n" /* activeMatrices */
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, 0x378(%esi)\n" /* activeMatrices */
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 0x37c(%esi)\n" /* activeMatrices */
        "movb $1, 0x440(%esi)\n" /* line 253 | activeMatrices */
        "movl %esi, %eax\n" /* activeMatrices */
        "movl $1, %edx\n"
        ".Lfd6670_000d6815:\n"
        "movb $0, 0x441(%eax)\n" /* line 255 */
        "addl $1, %edx\n" /* line 254 */
        "addl $1, %eax\n"
        "cmpl $4, %edx\n"
        "jne .Lfd6670_000d6815\n"
        "movl %esi, %eax\n" /* activeMatrices */
        "movl %esi, %edx\n" /* activeMatrices */
        "movl $4, %ecx\n"
        "movl -0x68(%ebp), %ebx\n" /* identity */
        "movl %ebx, -0x170(%ebp)\n"
        "movl -0x64(%ebp), %ebx\n"
        "movl %ebx, -0x174(%ebp)\n"
        "movl -0x60(%ebp), %ebx\n"
        "movl %ebx, -0x178(%ebp)\n"
        "movl -0x5c(%ebp), %ebx\n"
        "movl %ebx, -0x17c(%ebp)\n"
        "movl -0x58(%ebp), %ebx\n"
        "movl %ebx, -0x180(%ebp)\n"
        "movl -0x54(%ebp), %ebx\n"
        "movl %ebx, -0x184(%ebp)\n"
        "movl -0x50(%ebp), %ebx\n"
        "movl %ebx, -0x188(%ebp)\n"
        "movl -0x4c(%ebp), %ebx\n"
        "movl %ebx, -0x18c(%ebp)\n"
        "movl -0x48(%ebp), %ebx\n"
        "movl %ebx, -0x190(%ebp)\n"
        "movl -0x44(%ebp), %ebx\n"
        "movl %ebx, -0x194(%ebp)\n"
        "movl -0x40(%ebp), %ebx\n"
        "movl %ebx, -0x198(%ebp)\n"
        "movl -0x3c(%ebp), %ebx\n"
        "movl %ebx, -0x19c(%ebp)\n"
        "movl -0x38(%ebp), %ebx\n"
        "movl %ebx, -0x1a0(%ebp)\n"
        "movl -0x34(%ebp), %ebx\n"
        "movl %ebx, -0x1a4(%ebp)\n"
        "movl -0x30(%ebp), %edi\n"
        "movl -0x2c(%ebp), %ebx\n"
        "movl %ebx, -0x1ac(%ebp)\n"
        ".Lfd6670_000d68ba:\n"
        "movl -0x170(%ebp), %ebx\n" /* line 259 */
        "movl %ebx, 0x10(%eax)\n"
        "movl -0x174(%ebp), %ebx\n"
        "movl %ebx, 0x14(%eax)\n"
        "movl -0x178(%ebp), %ebx\n"
        "movl %ebx, 0x18(%eax)\n"
        "movl -0x17c(%ebp), %ebx\n"
        "movl %ebx, 0x1c(%eax)\n"
        "movl -0x180(%ebp), %ebx\n"
        "movl %ebx, 0x20(%eax)\n"
        "movl -0x184(%ebp), %ebx\n"
        "movl %ebx, 0x24(%eax)\n"
        "movl -0x188(%ebp), %ebx\n"
        "movl %ebx, 0x28(%eax)\n"
        "movl -0x18c(%ebp), %ebx\n"
        "movl %ebx, 0x2c(%eax)\n"
        "movl -0x190(%ebp), %ebx\n"
        "movl %ebx, 0x30(%eax)\n"
        "movl -0x194(%ebp), %ebx\n"
        "movl %ebx, 0x34(%eax)\n"
        "movl -0x198(%ebp), %ebx\n"
        "movl %ebx, 0x38(%eax)\n"
        "movl -0x19c(%ebp), %ebx\n"
        "movl %ebx, 0x3c(%eax)\n"
        "movl -0x1a0(%ebp), %ebx\n"
        "movl %ebx, 0x40(%eax)\n"
        "movl -0x1a4(%ebp), %ebx\n"
        "movl %ebx, 0x44(%eax)\n"
        "movl %edi, 0x48(%eax)\n"
        "movl -0x1ac(%ebp), %ebx\n"
        "movl %ebx, 0x4c(%eax)\n"
        "movb $1, 0x110(%edx)\n" /* line 260 */
        "addl $0x40, %eax\n"
        "addl $1, %edx\n"
        "subl $1, %ecx\n" /* line 257 */
        "jne .Lfd6670_000d68ba\n"
        "leal 0x230(%esi), %eax\n" /* line 262 | activeMatrices */
        "leal 0x10(%esi), %edi\n" /* activeMatrices */
        "movl $0x110, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal 0x450(%esi), %eax\n" /* line 263 | activeMatrices */
        "movl %eax, -0x16c(%ebp)\n"
        "movl $0x110, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal 0x670(%esi), %eax\n" /* line 264 | activeMatrices */
        "leal 0x340(%esi), %ebx\n" /* activeMatrices */
        "movl $0x110, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal 0x780(%esi), %eax\n" /* line 265 | activeMatrices */
        "movl $0x110, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x230(%esi), %eax\n" /* line 267 | activeMatrices */
        "movl %eax, -0xe8(%ebp)\n" /* OGLView */
        "movl 0x234(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xe4(%ebp)\n"
        "movl 0x238(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xe0(%ebp)\n"
        "movl 0x23c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xdc(%ebp)\n"
        "movl 0x240(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xd8(%ebp)\n"
        "movl 0x244(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xd4(%ebp)\n"
        "movl 0x248(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xd0(%ebp)\n"
        "movl 0x24c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xcc(%ebp)\n"
        "movl 0x250(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xc8(%ebp)\n"
        "movl 0x254(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xc4(%ebp)\n"
        "movl 0x258(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xc0(%ebp)\n"
        "movl 0x25c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xbc(%ebp)\n"
        "movl 0x260(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xb8(%ebp)\n"
        "movl 0x264(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xb4(%ebp)\n"
        "movl 0x268(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xb0(%ebp)\n"
        "movl 0x26c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xac(%ebp)\n"
        "movl 0x340(%esi), %eax\n" /* line 269 | activeMatrices */
        "movl %eax, -0x128(%ebp)\n" /* OGLProjection */
        "movl 0x344(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x124(%ebp)\n"
        "movl 0x348(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x120(%ebp)\n"
        "movl 0x34c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x11c(%ebp)\n"
        "movl 0x350(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x118(%ebp)\n"
        "movl 0x354(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x114(%ebp)\n"
        "movl 0x358(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x110(%ebp)\n"
        "movl 0x35c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x10c(%ebp)\n"
        "movl 0x360(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x108(%ebp)\n"
        "movl 0x364(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x104(%ebp)\n"
        "movl 0x368(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0x100(%ebp)\n"
        "movl 0x36c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xfc(%ebp)\n"
        "movl 0x370(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xf8(%ebp)\n"
        "movl 0x374(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xf4(%ebp)\n"
        "movl 0x378(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xf0(%ebp)\n"
        "movl 0x37c(%esi), %eax\n" /* activeMatrices */
        "movl %eax, -0xec(%ebp)\n"
        "movss refEntIsInWorldSpace+16, %xmm1\n" /* line 270 */
        "movss -0xe0(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xe0(%ebp)\n"
        "movss -0xd0(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xd0(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss -0xb0(%ebp), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, -0xb0(%ebp)\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm0\n" /* line 273 */
        "movss %xmm0, 8(%esp)\n"
        "cvtsi2ssl -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "leal -0x128(%ebp), %edx\n" /* OGLProjection */
        "movl %edx, (%esp)\n"
        "calll MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL\n"
        "leal -0x168(%ebp), %ebx\n" /* line 276 | OGLWorldView */
        "movl %ebx, 8(%esp)\n"
        "leal -0xe8(%ebp), %ecx\n" /* OGLView */
        "movl %ecx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll MatrixMultiply44\n"
        "leal 0xcd0(%esi), %eax\n" /* line 277 | activeMatrices */
        "movl %eax, 8(%esp)\n"
        "leal -0x128(%ebp), %eax\n" /* OGLProjection */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MatrixMultiply44\n"
        "leal 0x120(%esi), %eax\n" /* line 279 | activeMatrices */
        "movl $0x110, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal 0x560(%esi), %eax\n" /* line 280 | activeMatrices */
        "movl $0x110, 8(%esp)\n"
        "movl -0x16c(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal 0x890(%esi), %eax\n" /* line 281 | activeMatrices */
        "movl $0x110, 8(%esp)\n"
        "movl -0x16c(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 284 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd6670_000d6ccf\n"
        ".Lfd6670_000d6c68:\n"
        "xorl %eax, %eax\n" /* line 447 */
        "movl %eax, backEnd+176\n"
        "movl %eax, backEnd+180\n" /* line 448 */
        "movl $0x3f800000, %edx\n" /* line 449 */
        "movl %edx, backEnd+184\n"
        "movl %edx, backEnd+188\n" /* line 450 */
        "movl %eax, backEnd+192\n" /* line 447 */
        "movl %eax, backEnd+196\n" /* line 448 */
        "movl %edx, backEnd+200\n" /* line 449 */
        "movl %eax, backEnd+204\n" /* line 450 */
        "movl %edx, backEnd+208\n" /* line 447 */
        "movl %eax, backEnd+212\n" /* line 448 */
        "movl %eax, backEnd+216\n" /* line 449 */
        "movl %eax, backEnd+220\n" /* line 450 */
        "movl %eax, backEnd+224\n" /* line 447 */
        "movl %edx, backEnd+228\n" /* line 448 */
        "movl %eax, backEnd+232\n" /* line 449 */
        "movl %eax, backEnd+236\n" /* line 450 */
        /* } scope */
        "addl $0x1bc, %esp\n" /* line 296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd6670_000d6ccf:\n"
        "movl imp_dx, %esi\n" /* activeMatrices */
        "movl imp_alwaysfails, %ebx\n"
        /* { scope 1 */
        ".Lfd6670_000d6cdb:\n"
        "movl 8(%esi), %eax\n" /* line 286 | activeMatrices */
        "movl (%eax), %edx\n"
        "leal -0x68(%ebp), %ecx\n" /* identity */
        "movl %ecx, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%ebx), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfd6670_000d6cdb\n"
        "movl imp_dx, %esi\n" /* activeMatrices */
        "movl imp_alwaysfails, %ebx\n"
        ".Lfd6670_000d6d0a:\n"
        "movl 8(%esi), %eax\n" /* line 287 | activeMatrices */
        "movl (%eax), %edx\n"
        "leal -0x68(%ebp), %ecx\n" /* identity */
        "movl %ecx, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd6670_000d6d0a\n"
        "movl imp_dx, %esi\n" /* activeMatrices */
        "movl imp_alwaysfails, %ebx\n"
        ".Lfd6670_000d6d39:\n"
        "movl 8(%esi), %eax\n" /* line 288 | activeMatrices */
        "movl (%eax), %edx\n"
        "leal -0xa8(%ebp), %ecx\n" /* transform */
        "movl %ecx, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xb0(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd6670_000d6d39\n"
        "jmp .Lfd6670_000d6c68\n"
    );
}

/* line 2388 */
static __attribute__((naked))
void RB_DrawTrianglesCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2388 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 2406 | execState */
        "movl (%edx), %eax\n"
        "movswl 0xe(%eax), %ecx\n" /* line 2409 */
        "movl %ecx, -0x50(%ebp)\n"
        "shll $4, %ecx\n" /* line 2410 */
        "addl $0x10, %ecx\n"
        "movl -0x50(%ebp), %ebx\n" /* line 2412 | stOffset */
        "leal (%ebx, %ebx, 2), %edx\n" /* stOffset */
        "leal (%ecx, %edx, 4), %edx\n"
        "leal (%edx, %ebx, 4), %ebx\n" /* line 2414 | stOffset */
        "leal 0x10(%eax), %esi\n" /* line 2418 | techType */
        "movl %esi, -0x48(%ebp)\n" /* techType, xyzw */
        "leal (%eax, %ecx), %ecx\n" /* line 2419 */
        "movl %ecx, -0x44(%ebp)\n" /* normal */
        "leal (%eax, %edx), %edx\n" /* line 2420 */
        "movl %edx, -0x40(%ebp)\n" /* color */
        "leal (%eax, %ebx), %edx\n" /* line 2421 */
        "movl %edx, -0x3c(%ebp)\n" /* st */
        "movl -0x50(%ebp), %ecx\n" /* line 2422 */
        "leal (%ebx, %ecx, 8), %edx\n" /* stOffset */
        "leal (%eax, %edx), %edi\n" /* indices */
        "movswl 0xc(%eax), %ebx\n" /* line 2423 | stOffset */
        "movl %ebx, -0x4c(%ebp)\n" /* stOffset */
        "movl 8(%eax), %esi\n" /* techType */
        "movl 4(%eax), %ebx\n" /* stOffset */
        /* { scope 2 */
        "movl tess+370640, %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfd6d64_000d7067\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd6d64_000d7067\n"
        "cmpb $0, backEnd+1213\n" /* line 2368 */
        "jne .Lfd6d64_000d7079\n"
        /* { scope 3: z, y, x */
        ".Lfd6d64_000d6de1:\n"
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfd6d64_000d708a\n"
        ".Lfd6d64_000d6ded:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd6d64_000d70a3\n"
        ".Lfd6d64_000d6dfa:\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd6d64_000d70a3\n"
        ".Lfd6d64_000d6e07:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfd6d64_000d6e1b:\n"
        "movl tess+370644, %edx\n" /* line 344 */
        "movl -0x50(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfd6d64_000d70ad\n"
        "movl -0x4c(%ebp), %eax\n"
        "addl tess+370640, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jg .Lfd6d64_000d70ad\n"
        ".Lfd6d64_000d6e45:\n"
        "movl -0x4c(%ebp), %eax\n" /* line 2375 */
        "testl %eax, %eax\n"
        "jle .Lfd6d64_000d6e79\n"
        "xorl %ebx, %ebx\n" /* material */
        "jmp .Lfd6d64_000d6e56\n"
        ".Lfd6d64_000d6e50:\n"
        "movl tess+370644, %edx\n"
        ".Lfd6d64_000d6e56:\n"
        "movl %ebx, %ecx\n" /* line 2376 | material */
        "addl tess+370640, %ecx\n"
        "addw (%edi, %ebx, 2), %dx\n"
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx, 2)\n"
        "addl $1, %ebx\n" /* line 2375 | material */
        "cmpl %ebx, -0x4c(%ebp)\n" /* material */
        "jne .Lfd6d64_000d6e50\n"
        "movl tess+370644, %edx\n"
        ".Lfd6d64_000d6e79:\n"
        "movl -0x50(%ebp), %esi\n" /* line 2378 | techType */
        "testl %esi, %esi\n" /* techType */
        "jle .Lfd6d64_000d703a\n"
        /* { scope 3: z, y, x */
        "movl imp_r_rendererInUse, %eax\n" /* line 414 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl -0x40(%ebp), %esi\n" /* color */
        "movl %esi, -0x28(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n" /* st */
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x44(%ebp), %ecx\n" /* normal */
        "movl %ecx, -0x20(%ebp)\n"
        "movl -0x48(%ebp), %edi\n" /* xyzw */
        "movl $0, -0x1c(%ebp)\n"
        "movl %eax, %ebx\n"
        "jmp .Lfd6d64_000d6f67\n"
        ".Lfd6d64_000d6eb1:\n"
        "movl %eax, %edx\n" /* line 424 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss %xmm2, 8(%eax)\n" /* line 449 */
        "movss %xmm3, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 425 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl %ebx, tess(%ecx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movss -0x34(%ebp), %xmm0\n" /* line 193 | z */
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "movl -0x28(%ebp), %ebx\n" /* line 606 | v */
        "movl (%ebx), %eax\n" /* v */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 427 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 30 | x */
        "movss %xmm0, tess(%eax)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 31 | y */
        "movss %xmm0, 4(%ecx)\n"
        /* } scope */
        "addl $tess+48, %edx\n" /* line 428 */
        "leal 4(%edx), %ebx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, %esi\n" /* line 191 */
        "movl %esi, 4(%edx)\n"
        "xorl %eax, %eax\n" /* line 192 */
        "movl %eax, 4(%ebx)\n"
        "movl %eax, 8(%ebx)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %edx\n" /* line 429 | v */
        /* { scope 4 */
        "movl %eax, 8(%ecx)\n" /* line 191 */
        "movl %esi, 4(%edx)\n" /* line 192 */
        "movl %eax, 8(%edx)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "addl $1, -0x1c(%ebp)\n" /* line 2378 */
        "addl $4, -0x28(%ebp)\n"
        "addl $8, -0x24(%ebp)\n"
        "addl $0xc, -0x20(%ebp)\n"
        "addl $0x10, %edi\n"
        "movl -0x1c(%ebp), %eax\n"
        "cmpl %eax, -0x50(%ebp)\n"
        "je .Lfd6d64_000d7034\n"
        ".Lfd6d64_000d6f5e:\n"
        "movl tess+370644, %edx\n"
        "movl -0x24(%ebp), %ebx\n" /* material */
        ".Lfd6d64_000d6f67:\n"
        "movss 4(%ebx), %xmm0\n" /* line 2379 | material */
        "movss %xmm0, -0x30(%ebp)\n" /* y */
        "movss (%ebx), %xmm0\n" /* material */
        "movss %xmm0, -0x2c(%ebp)\n" /* x */
        "movl -0x20(%ebp), %eax\n" /* vertIndex */
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* z */
        "movl 4(%eax), %esi\n" /* techType */
        "movl (%eax), %ebx\n" /* material */
        "movss 0xc(%edi), %xmm3\n"
        "movss 8(%edi), %xmm2\n"
        "movss 4(%edi), %xmm1\n"
        "movss (%edi), %xmm0\n"
        "movl -0x1c(%ebp), %eax\n" /* vertIndex */
        "addl %edx, %eax\n" /* vertIndex */
        /* { scope 3: z, y, x */
        "movl -0x38(%ebp), %edx\n" /* line 414 */
        "cmpl $2, 8(%edx)\n"
        "jne .Lfd6d64_000d6eb1\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 416 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "divss %xmm3, %xmm0\n" /* line 191 */
        "movss %xmm0, tess(%eax)\n"
        "divss %xmm3, %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%edx)\n"
        "divss %xmm3, %xmm2\n" /* line 193 */
        "movss %xmm2, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 417 | v */
        /* { scope 4 */
        "movl %ebx, 0xc(%edx)\n" /* line 191 */
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movss -0x34(%ebp), %xmm0\n" /* line 193 | z */
        "movss %xmm0, 8(%ecx)\n"
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x28(%ebp), %ecx\n"
        "movl (%ecx), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 419 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 30 | x */
        "movss %xmm0, 0xc(%eax)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 31 | y */
        "movss %xmm0, 0x10(%eax)\n"
        /* } scope */
        "addl $1, -0x1c(%ebp)\n" /* line 2378 */
        "addl $4, -0x28(%ebp)\n"
        "addl $8, -0x24(%ebp)\n"
        "addl $0xc, -0x20(%ebp)\n"
        "addl $0x10, %edi\n"
        "movl -0x1c(%ebp), %eax\n"
        "cmpl %eax, -0x50(%ebp)\n"
        "jne .Lfd6d64_000d6f5e\n"
        ".Lfd6d64_000d7034:\n"
        "movl tess+370644, %edx\n"
        ".Lfd6d64_000d703a:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 2381 */
        "addl %ecx, tess+370640\n"
        "movl -0x50(%ebp), %eax\n" /* line 2382 */
        "addl %edx, %eax\n"
        "movl %eax, tess+370644\n"
        "calll RB_EndSurface\n" /* line 2384 */
        /* } scope */
        "movl 8(%ebp), %ebx\n" /* line 169 | execState */
        "movl (%ebx), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%ebx)\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2426 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfd6d64_000d7067:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "cmpb $0, backEnd+1213\n" /* line 2368 */
        "je .Lfd6d64_000d6de1\n"
        ".Lfd6d64_000d7079:\n"
        "calll RB_Set3D\n" /* line 2369 */
        /* { scope 3: z, y, x */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "jne .Lfd6d64_000d6ded\n"
        ".Lfd6d64_000d708a:\n"
        "cmpl tess+370624, %esi\n"
        "je .Lfd6d64_000d6e1b\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "je .Lfd6d64_000d6dfa\n"
        ".Lfd6d64_000d70a3:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfd6d64_000d6e07\n"
        /* } scope */
        ".Lfd6d64_000d70ad:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfd6d64_000d7118\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd6d64_000d7102\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd6d64_000d7102\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %edx\n"
        "jmp .Lfd6d64_000d6e45\n"
        ".Lfd6d64_000d7102:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %edx\n"
        "jmp .Lfd6d64_000d6e45\n"
        ".Lfd6d64_000d7118:\n"
        "movl tess+370644, %edx\n"
        "jmp .Lfd6d64_000d6e45\n"
    );
}

/* line 2064 */
/* line 2064 */
static void RB_SaveScreenCmd(GfxRenderCommandExecState *execState)
{
    char *dx;
    void *imageSurface;
    byte *cmd;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    dx = (char *)imp_dx;
    imageSurface = Image_GetSurface(*(void **)(dx + 0x2cbc));

    /* StretchRect: copy back buffer to save surface (vtable[0x88/4]) */
    do {
        void *device = *(void **)(dx + 8);
        void **vtable = *(void ***)device;
        void *backBuffer = *(void **)((char *)imp_dxState + 0x20a8);
        ((int (__attribute__((stdcall)) *)(void *, void *, void *, void *, void *, int))vtable[0x88/4])(
            device, backBuffer, NULL, imageSurface, NULL, 2);
    } while (*(int *)imp_alwaysfails);

    /* Release imageSurface (vtable[2]) */
    do {
        ((int (__attribute__((stdcall)) *)(void *))((*(void ***)imageSurface)[2]))(imageSurface);
    } while (*(int *)imp_alwaysfails);

    /* Store current viewParms index as saved screen frame */
    *(int *)((char *)imp_rgp + 0x10e0) = *(int *)((char *)&backEnd + 952);

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2036 */
/* line 2036 */
static void RB_ApplyEarlyPostEffectsCmd(GfxRenderCommandExecState *execState)
{
    int needCopy;
    byte *cmd;

    if (*(int *)((byte *)&tess + 370640) || *(int *)((byte *)&tess + 370656))
        RB_EndSurface();

    /* Set render target to post-effect target */
    *(int *)((char *)&backEnd + 11908) = 0xe;

    /* Check if distortion is enabled */
    needCopy = *(byte *)(*(char **)imp_r_distortion + 8);

    if (!needCopy) {
        /* Check glow support: not Dx7, hardware supports it, glow enabled, not fullbright */
        int isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);
        if (!isDx7 && *(byte *)((char *)imp_dx + 0x2d7d)) {
            if (*(byte *)(*(char **)imp_r_glow + 8)) {
                needCopy = !*(byte *)(*(char **)imp_r_fullbright + 8);
            }
        }
    }

    if (needCopy) {
        char *dx = (char *)imp_dx;
        void *imageSurface = Image_GetSurface(*(void **)(dx + 0x2c44));

        /* StretchRect: copy back buffer to post-effect surface */
        do {
            void *device = *(void **)(dx + 8);
            void **vtable = *(void ***)device;
            void *backBuffer = *(void **)((char *)imp_dxState + 0x20a8);
            ((int (__attribute__((stdcall)) *)(void *, void *, void *, void *, void *, int))vtable[0x88/4])(
                device, backBuffer, NULL, imageSurface, NULL, 2);
        } while (*(int *)imp_alwaysfails);

        /* Release imageSurface */
        do {
            ((int (__attribute__((stdcall)) *)(void *))((*(void ***)imageSurface)[2]))(imageSurface);
        } while (*(int *)imp_alwaysfails);

        *(int *)((char *)&backEnd + 11908) = 1;
    }

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 718 */
/* line 718 */
static void RB_DrawSpriteCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd;
    const Material *spriteMaterial;
    char *t = (char *)&tess;
    byte entity[0x74]; /* local GfxEntity-like struct for RB_TessEntity */

    cmd = *(byte **)execState;

    /* Switch to 3D mode if in 2D */
    if (!*((byte *)&backEnd + 0x4bd))
        RB_Set3D();

    spriteMaterial = *(const Material **)(cmd + 4);

    /* Begin surface if material or technique changed */
    if (spriteMaterial != *(const Material **)(t + 0x5a7bc) ||
        *(MaterialTechniqueType *)(t + 0x5a7c0) != 3) {
        if (*(int *)(t + 0x5a7d0) != 0 || *(int *)(t + 0x5a7e0) != 0)
            RB_EndSurface();
        RB_BeginSurface(spriteMaterial, 3, 0x1f);
    }

    /* Build entity on stack */
    memset(entity, 0, 0x74);

    /* origin (entity+0x3c) = cmd+0x0c (vec3) */
    *(int *)(entity + 0x3c) = *(int *)(cmd + 0x0c);
    *(int *)(entity + 0x40) = *(int *)(cmd + 0x10);
    *(int *)(entity + 0x44) = *(int *)(cmd + 0x14);

    /* material (entity+0x54) = cmd+4 */
    *(int *)(entity + 0x54) = *(int *)(cmd + 4);

    /* surfaceType (entity+0x00) = 4 */
    *(int *)(entity + 0x00) = 4;

    /* materialTime (entity+0x04) = cmd+0x20 */
    *(int *)(entity + 0x04) = *(int *)(cmd + 0x20);

    /* radius[0] = radius[1] = cmd+0x18 */
    *(int *)(entity + 0x64) = *(int *)(cmd + 0x18);
    *(int *)(entity + 0x68) = *(int *)(cmd + 0x18);

    /* scale (entity+0x70) = cmd+0x1c */
    *(int *)(entity + 0x70) = *(int *)(cmd + 0x1c);

    /* color (entity+0x58) = cmd+8 */
    *(int *)(entity + 0x58) = *(int *)(cmd + 8);

    RB_TessEntity(entity);

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2226 */
__attribute__((naked))
void RB_DrawLines2D(int count, int width, const GfxPointVertex *verts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2226 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl imp_rgp, %eax\n"
        "movl 0x1038(%eax), %ebx\n"
        /* { scope 1 */
        /* { scope 2: from */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfd743e_000d7ab9\n"
        ".Lfd743e_000d745e:\n"
        "movl tess+370640, %edi\n" /* line 261 */
        "testl %edi, %edi\n"
        "jne .Lfd743e_000d7499\n"
        "movl tess+370656, %esi\n"
        "testl %esi, %esi\n"
        "jne .Lfd743e_000d7499\n"
        ".Lfd743e_000d7472:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfd743e_000d748a:\n"
        "movl 8(%ebp), %ebx\n" /* line 2235 | count, material */
        "testl %ebx, %ebx\n" /* material */
        "jg .Lfd743e_000d74a0\n"
        /* } scope */
        ".Lfd743e_000d7491:\n"
        "addl $0x4c, %esp\n" /* line 2261 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: from */
        ".Lfd743e_000d7499:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfd743e_000d7472\n"
        /* } scope */
        ".Lfd743e_000d74a0:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2235 | verts */
        "addl $0x10, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl $0, -0x38(%ebp)\n" /* lineIndex */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* verts */
        "addl $0x1c, %edi\n"
        "movl %eax, %esi\n"
        "movl %eax, %ebx\n" /* material */
        "jmp .Lfd743e_000d77c5\n"
        /* { scope 2: from */
        ".Lfd743e_000d74c2:\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, %ebx\n" /* line 450 */
        "movl %ebx, 0xc(%eax)\n"
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 381 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, tess(%ecx)\n"
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %ebx, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* { scope 3 */
        "movl -0x10(%edi), %eax\n" /* line 606 */
        "movl %eax, tess+12(%ecx)\n"
        /* } scope */
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ebx, 4(%edx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 3 */
        "movl %esi, 8(%ecx)\n" /* line 191 */
        "movl %ebx, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd743e_000d7533:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2256 */
        "movl 8(%eax), %ecx\n"
        "movss 4(%eax), %xmm1\n"
        "subss -0x1c(%ebp), %xmm1\n"
        "movss (%eax), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* delta */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ebx\n" /* line 370 */
        "movl (%ebx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd743e_000d7a62\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 381 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl (%edi), %eax\n" /* line 606 */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd743e_000d7600:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2257 */
        "movl 8(%eax), %ecx\n"
        "movss 4(%eax), %xmm1\n"
        "addss -0x1c(%ebp), %xmm1\n"
        "movss (%eax), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n" /* delta */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ebx\n" /* line 370 */
        "movl (%ebx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd743e_000d7a0b\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 381 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl (%edi), %eax\n" /* line 606 */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd743e_000d76cd:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2258 */
        "movl (%eax), %ecx\n"
        "movss -0x18(%edi), %xmm1\n"
        "addss -0x1c(%ebp), %xmm1\n"
        "movss -0x1c(%edi), %xmm0\n"
        "addss -0x20(%ebp), %xmm0\n" /* delta */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ebx\n" /* line 370 */
        "movl (%ebx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd743e_000d79b1\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 381 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0x34(%ebp), %ebx\n" /* line 606 | from */
        "movl (%ebx), %eax\n"
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd743e_000d779d:\n"
        "addl $4, tess+370644\n" /* line 2259 */
        "addl $1, -0x38(%ebp)\n" /* line 2235 | lineIndex */
        "addl $0x20, -0x30(%ebp)\n"
        "addl $0x20, %edi\n"
        "addl $0x20, -0x3c(%ebp)\n"
        "movl -0x38(%ebp), %eax\n" /* lineIndex */
        "cmpl %eax, 8(%ebp)\n" /* count */
        "je .Lfd743e_000d7491\n"
        "movl -0x30(%ebp), %esi\n"
        "movl -0x3c(%ebp), %ebx\n" /* material */
        ".Lfd743e_000d77c5:\n"
        "subl $0x10, %esi\n" /* line 2226 */
        "movss 4(%ebx), %xmm0\n" /* line 2240 | material */
        "subss -0x18(%edi), %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* delta */
        "movss -0x1c(%edi), %xmm0\n" /* line 2241 */
        "subss (%ebx), %xmm0\n" /* material */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 2242 | delta */
        "movl %eax, (%esp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 2243 | 0.5f */
        "movss -0x20(%ebp), %xmm1\n" /* delta */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n" /* delta */
        "mulss -0x1c(%ebp), %xmm0\n" /* line 2244 */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl tess+370644, %edx\n" /* line 344 */
        "leal 4(%edx), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfd743e_000d7832\n"
        "movl tess+370640, %ecx\n"
        "leal 6(%ecx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfd743e_000d7892\n"
        ".Lfd743e_000d7832:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfd743e_000d7886\n"
        "movl tess+370640, %ecx\n" /* line 261 */
        "testl %ecx, %ecx\n"
        "jne .Lfd743e_000d79a7\n"
        "movl tess+370656, %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfd743e_000d79a7\n"
        ".Lfd743e_000d7880:\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        ".Lfd743e_000d7886:\n"
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        ".Lfd743e_000d7892:\n"
        "addl $1, %edx\n" /* line 2247 */
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2248 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 2(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2249 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2250 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2251 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 8(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2252 */
        "addl $3, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 0xa(%eax, %edx, 2)\n"
        "addl $6, tess+370640\n" /* line 2253 */
        "addl $0xc, %esi\n" /* line 2255 */
        "movl %esi, -0x34(%ebp)\n" /* from */
        "movl -0x30(%ebp), %ecx\n" /* line 2226 */
        "subl $8, %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl -0x14(%edi), %ecx\n" /* line 2255 */
        "movss -0x18(%edi), %xmm1\n"
        "subss -0x1c(%ebp), %xmm1\n"
        "movss -0x1c(%edi), %xmm0\n"
        "subss -0x20(%ebp), %xmm0\n" /* delta */
        "movl tess+370644, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ebx\n" /* line 370 */
        "movl (%ebx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfd743e_000d74c2\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 3 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, 0xc(%edx)\n"
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x10(%edi), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl %esi, 0xc(%eax)\n" /* line 30 */
        "movl %esi, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd743e_000d7533\n"
        /* } scope */
        ".Lfd743e_000d79a7:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfd743e_000d7880\n"
        /* { scope 2: from */
        ".Lfd743e_000d79b1:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x34(%ebp), %ecx\n" /* from */
        "movl (%ecx), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd743e_000d779d\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfd743e_000d7a0b:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl (%edi), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd743e_000d76cd\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfd743e_000d7a62:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl (%edi), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd743e_000d7600\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfd743e_000d7ab9:\n"
        "cmpl $3, tess+370624\n" /* line 300 */
        "jne .Lfd743e_000d745e\n"
        "jmp .Lfd743e_000d748a\n"
    );
}

/* line 3063 */
__attribute__((naked))
void RB_DrawTextInSpace(const char *text, FontHandle font, const vec_t *org, const vec_t *xPixelStep, const vec_t *yPixelStep, D3DCOLOR color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3063 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* org */
        /* { scope 1: unpackedColor */
        "movl 0xc(%ebp), %eax\n" /* line 207 | font */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* material */
        "movl backEnd+968, %eax\n" /* line 3079 */
        "movl %eax, (%esp)\n"
        "calll RB_SetMatricesForView\n"
        "movss lit4_002ed63c, %xmm1\n" /* line 288 | -0.5f */
        "movl 0x14(%ebp), %edx\n" /* xPixelStep */
        "movss (%edx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "addss (%ebx), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "addl $4, %edx\n" /* line 289 */
        "movl %edx, -0x74(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* xPixelStep */
        "movss 4(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "addss 4(%ebx), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "addl $8, %eax\n" /* line 290 */
        "movl %eax, -0x70(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* xPixelStep */
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "addss 8(%ebx), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 288 | yPixelStep */
        "movss (%eax), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "addl $4, %eax\n" /* line 289 */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x18(%ebp), %edx\n" /* yPixelStep */
        "movss 4(%edx), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "addl $8, %edx\n" /* line 290 */
        "movl %edx, -0x68(%ebp)\n"
        "movl 0x18(%ebp), %ecx\n" /* yPixelStep */
        "mulss 8(%ecx), %xmm1\n"
        "addss -0x40(%ebp), %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 3083 | text */
        "cmpb $0, (%eax)\n"
        "jne .Lfd7acc_000d8023\n"
        /* } scope */
        ".Lfd7acc_000d7ba9:\n"
        "addl $0x8c, %esp\n" /* line 3098 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: unpackedColor */
        /* { scope 2: vertIndex */
        ".Lfd7acc_000d7bb4:\n"
        "calll RB_EndSurface\n" /* line 262 */
        ".Lfd7acc_000d7bb9:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl -0x78(%ebp), %ecx\n" /* material */
        "movl %ecx, (%esp)\n"
        "calll RB_BeginSurface\n"
        ".Lfd7acc_000d7bd4:\n"
        "movl tess+370644, %edx\n" /* line 344 */
        "leal 4(%edx), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfd7acc_000d7bf4\n"
        "movl tess+370640, %ecx\n"
        "leal 6(%ecx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfd7acc_000d7c53\n"
        ".Lfd7acc_000d7bf4:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfd7acc_000d82d4\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd7acc_000d7c3c\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd7acc_000d7c41\n"
        ".Lfd7acc_000d7c3c:\n"
        "calll RB_EndSurface\n" /* line 262 */
        ".Lfd7acc_000d7c41:\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        ".Lfd7acc_000d7c53:\n"
        "movl %edx, %ebx\n" /* line 3042 | x */
        "movzwl %cx, %edx\n" /* line 3043 */
        "leal 4(%ebx), %eax\n" /* line 3045 | x */
        "movl %eax, tess+370644\n"
        "leal 6(%ecx), %eax\n" /* line 3046 */
        "movl %eax, tess+370640\n"
        "addl %edx, %edx\n" /* line 3048 */
        "leal 3(%ebx), %ecx\n" /* x */
        "movl tess+370608, %eax\n"
        "movw %cx, (%eax, %edx)\n"
        "movl tess+370608, %eax\n" /* line 3049 */
        "movw %bx, 2(%eax, %edx)\n" /* x */
        "leal 2(%ebx), %ecx\n" /* line 3050 | x */
        "movl tess+370608, %eax\n"
        "movw %cx, 4(%edx, %eax)\n"
        "movl tess+370608, %eax\n" /* line 3051 */
        "movw %cx, 6(%edx, %eax)\n"
        "movl tess+370608, %eax\n" /* line 3052 */
        "movw %bx, 8(%edx, %eax)\n" /* x */
        "leal 1(%ebx), %ecx\n" /* line 3053 | x */
        "movl tess+370608, %eax\n"
        "movw %cx, 0xa(%edx, %eax)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 3055 | color */
        "movl %eax, -0x1c(%ebp)\n" /* unpackedColor */
        "movss 0xc(%edi), %xmm0\n" /* line 3056 */
        "movss %xmm0, -0x60(%ebp)\n" /* y */
        "movss 8(%edi), %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n" /* x */
        "movzwl %bx, %esi\n" /* x, vertCount */
        "movl %esi, -0x64(%ebp)\n" /* vertCount, vertIndex */
        /* { scope 3: y, x */
        "movl imp_r_rendererInUse, %edx\n" /* line 370 */
        "movl (%edx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd7acc_000d8256\n"
        "movl %esi, %edx\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 447 */
        "movss %xmm0, tess(%edx)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 448 */
        "movss %xmm1, 4(%eax)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 449 */
        "movss %xmm0, 8(%eax)\n"
        "movl $0x3f800000, %ebx\n" /* line 450 | x */
        "movl %ebx, 0xc(%eax)\n" /* x */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 381 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, tess(%eax)\n"
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl %ebx, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x1c(%ebp), %ecx\n" /* line 606 | unpackedColor */
        "movl %ecx, -0x7c(%ebp)\n"
        "movl %ecx, tess+12(%eax)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 30 | x */
        "movss %xmm0, tess(%eax)\n"
        "movss -0x60(%ebp), %xmm1\n" /* line 31 | y */
        "movss %xmm1, 4(%ecx)\n"
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl %ebx, 4(%edx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 4 */
        "movl %esi, 8(%ecx)\n" /* line 191 */
        "movl %ebx, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd7acc_000d7d75:\n"
        "movl 0xc(%edi), %esi\n" /* line 3057 | vertCount */
        "movl 0x10(%edi), %ebx\n" /* x */
        "movss -0x34(%ebp), %xmm0\n"
        "addss -0x58(%ebp), %xmm0\n"
        "movss -0x30(%ebp), %xmm5\n"
        "addss -0x54(%ebp), %xmm5\n"
        "movss -0x2c(%ebp), %xmm6\n"
        "addss -0x50(%ebp), %xmm6\n"
        "movl -0x64(%ebp), %edx\n" /* vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 3: y, x */
        "movl imp_r_rendererInUse, %ecx\n" /* line 370 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd7acc_000d8204\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm6, tess(%edx)\n" /* line 447 */
        "movss %xmm5, 4(%eax)\n" /* line 448 */
        "movss %xmm0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 381 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x7c(%ebp), %ecx\n" /* line 606 */
        "movl %ecx, tess+12(%eax)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl %ebx, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd7acc_000d7e45:\n"
        "movl 0x14(%edi), %esi\n" /* line 3058 | vertCount */
        "movl 0x10(%edi), %ebx\n" /* x */
        "addss -0x4c(%ebp), %xmm0\n"
        "addss -0x48(%ebp), %xmm5\n"
        "addss -0x44(%ebp), %xmm6\n"
        "movl -0x64(%ebp), %edx\n" /* vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 3: y, x */
        "movl imp_r_rendererInUse, %ecx\n" /* line 370 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd7acc_000d81b2\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm6, tess(%edx)\n" /* line 447 */
        "movss %xmm5, 4(%eax)\n" /* line 448 */
        "movss %xmm0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 381 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x7c(%ebp), %ecx\n" /* line 606 */
        "movl %ecx, tess+12(%eax)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl %ebx, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfd7acc_000d7f06:\n"
        "movl 0x14(%edi), %esi\n" /* line 3059 | vertCount */
        "movl 8(%edi), %ebx\n" /* x */
        "movss -0x34(%ebp), %xmm1\n"
        "addss -0x4c(%ebp), %xmm1\n"
        "movss -0x30(%ebp), %xmm2\n"
        "addss -0x48(%ebp), %xmm2\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "addss -0x44(%ebp), %xmm0\n"
        "movl -0x64(%ebp), %edx\n" /* vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 3: y, x */
        "movl imp_r_rendererInUse, %ecx\n" /* line 370 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd7acc_000d8160\n"
        "shll $6, %edx\n" /* line 380 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm2, 4(%eax)\n" /* line 448 */
        "movss %xmm1, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 381 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x7c(%ebp), %ecx\n" /* line 606 */
        "movl %ecx, tess+12(%eax)\n"
        "leal 0x20(%edx), %eax\n" /* line 383 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl %ebx, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 384 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 385 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfd7acc_000d7fd6:\n"
        "movzbl 4(%edi), %eax\n" /* line 3096 | glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        /* { scope 2: vertIndex */
        "movaps %xmm0, %xmm1\n" /* line 288 */
        "movl 0x14(%ebp), %eax\n" /* xPixelStep */
        "mulss (%eax), %xmm1\n"
        "addss -0x38(%ebp), %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movaps %xmm0, %xmm1\n" /* line 289 */
        "movl -0x74(%ebp), %edx\n"
        "mulss (%edx), %xmm1\n"
        "addss -0x3c(%ebp), %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        "movl -0x70(%ebp), %ecx\n" /* line 290 */
        "mulss (%ecx), %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 3083 | text */
        "cmpb $0, (%eax)\n"
        "je .Lfd7acc_000d7ba9\n"
        ".Lfd7acc_000d8023:\n"
        "movl $0, 4(%esp)\n" /* line 3085 */
        "leal 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x118(%eax)\n"
        "movl %eax, 4(%esp)\n" /* line 3088 */
        "movl 0xc(%ebp), %edx\n" /* font */
        "movl %edx, (%esp)\n"
        "calll R_GetCharacterGlyph\n"
        "movl %eax, %edi\n" /* glyph */
        "movsbl 2(%eax), %eax\n" /* line 3089 */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        /* { scope 2: vertIndex */
        "movl 0x14(%ebp), %ecx\n" /* line 288 | xPixelStep */
        "movss (%ecx), %xmm6\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm6, %xmm1\n"
        "addss -0x38(%ebp), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movl -0x74(%ebp), %eax\n" /* line 289 */
        "movss (%eax), %xmm5\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "addss -0x3c(%ebp), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movl -0x70(%ebp), %eax\n" /* line 290 */
        "movss (%eax), %xmm4\n"
        "mulss %xmm4, %xmm0\n"
        "addss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movsbl 3(%edi), %eax\n" /* line 3090 | glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        /* { scope 2: vertIndex */
        "movl 0x18(%ebp), %edx\n" /* line 288 | yPixelStep */
        "movss (%edx), %xmm3\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm3, %xmm1\n"
        "addss -0x2c(%ebp), %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "movl -0x6c(%ebp), %ecx\n" /* line 289 */
        "movss (%ecx), %xmm2\n"
        "movaps %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "movl -0x68(%ebp), %eax\n" /* line 290 */
        "movss (%eax), %xmm1\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x34(%ebp), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        /* } scope */
        "movzbl 5(%edi), %eax\n" /* line 3091 | glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        /* { scope 2: vertIndex */
        "mulss %xmm0, %xmm6\n" /* line 272 */
        "movss %xmm6, -0x50(%ebp)\n"
        "mulss %xmm0, %xmm5\n" /* line 273 */
        "movss %xmm5, -0x54(%ebp)\n"
        "mulss %xmm0, %xmm4\n" /* line 274 */
        "movss %xmm4, -0x58(%ebp)\n"
        /* } scope */
        "movzbl 6(%edi), %eax\n" /* line 3092 | glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* scale */
        /* { scope 2: vertIndex */
        "mulss %xmm0, %xmm3\n" /* line 272 */
        "movss %xmm3, -0x44(%ebp)\n"
        "mulss %xmm0, %xmm2\n" /* line 273 */
        "movss %xmm2, -0x48(%ebp)\n"
        "mulss %xmm0, %xmm1\n" /* line 274 */
        "movss %xmm1, -0x4c(%ebp)\n"
        /* } scope */
        /* { scope 2: vertIndex */
        "movl -0x78(%ebp), %edx\n" /* line 300 | material */
        "cmpl tess+370620, %edx\n"
        "je .Lfd7acc_000d82c2\n"
        ".Lfd7acc_000d813c:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd7acc_000d7bb4\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd7acc_000d7bb9\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfd7acc_000d7bb9\n"
        /* { scope 3: y, x */
        ".Lfd7acc_000d8160:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm2, 4(%edx)\n" /* line 192 */
        "movss %xmm1, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl %ebx, 0xc(%eax)\n" /* line 30 */
        "movl %esi, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd7acc_000d7fd6\n"
        /* } scope */
        /* { scope 3: y, x */
        ".Lfd7acc_000d81b2:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm6, tess(%eax)\n" /* line 191 */
        "movss %xmm5, 4(%edx)\n" /* line 192 */
        "movss %xmm0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl %ebx, 0xc(%eax)\n" /* line 30 */
        "movl %esi, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd7acc_000d7f06\n"
        /* } scope */
        /* { scope 3: y, x */
        ".Lfd7acc_000d8204:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm6, tess(%eax)\n" /* line 191 */
        "movss %xmm5, 4(%edx)\n" /* line 192 */
        "movss %xmm0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movl %ebx, 0xc(%eax)\n" /* line 30 */
        "movl %esi, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfd7acc_000d7e45\n"
        /* } scope */
        /* { scope 3: y, x */
        ".Lfd7acc_000d8256:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 372 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss -0x2c(%ebp), %xmm0\n" /* line 191 */
        "movss %xmm0, tess(%eax)\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%edx)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 193 */
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 373 | v */
        /* { scope 4 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, 0xc(%edx)\n"
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x1c(%ebp), %edx\n" /* unpackedColor */
        "movl %edx, -0x7c(%ebp)\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 375 */
        "movss -0x5c(%ebp), %xmm0\n" /* line 30 | x */
        "movss %xmm0, 0xc(%eax)\n"
        "movss -0x60(%ebp), %xmm1\n" /* line 31 | y */
        "movss %xmm1, 0x10(%eax)\n"
        "jmp .Lfd7acc_000d7d75\n"
        /* } scope */
        ".Lfd7acc_000d82c2:\n"
        "cmpl $3, tess+370624\n" /* line 300 */
        "jne .Lfd7acc_000d813c\n"
        "jmp .Lfd7acc_000d7bd4\n"
        ".Lfd7acc_000d82d4:\n"
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        "jmp .Lfd7acc_000d7c53\n"
    );
}

/* line 3113 */
/* line 3113 */
static void RB_DrawTextInSpaceCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;

    RB_DrawTextInSpace(
        (const char *)(cmd + 0x30),      /* text */
        *(FontHandle *)(cmd + 0x10),     /* font */
        (const vec_t *)(cmd + 4),        /* org */
        (const vec_t *)(cmd + 0x14),     /* xPixelStep */
        (const vec_t *)(cmd + 0x20),     /* yPixelStep */
        *(D3DCOLOR *)(cmd + 0x2c));      /* color */

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 3416 */
static __attribute__((naked))
float RB_TestFillPass3D(const Material *material, MaterialTechniqueType techType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3416 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10c, %esp\n"
        "movl %eax, -0xec(%ebp)\n"
        "movl %edx, -0xf0(%ebp)\n"
        /* { scope 1: frequency */
        "xorl %edi, %edi\n" /* line 183 */
        "movl %edi, -0x40(%ebp)\n" /* origin */
        "movl %edi, -0x3c(%ebp)\n" /* line 184 */
        "movl %edi, -0x38(%ebp)\n" /* line 185 */
        "movl $0x3f800000, -0x64(%ebp)\n" /* line 191 | axis */
        "leal -0x64(%ebp), %eax\n" /* line 192 | axis */
        "movl %edi, -0x60(%ebp)\n"
        "movl %edi, -0x5c(%ebp)\n" /* line 193 */
        "movl %edi, -0x58(%ebp)\n" /* line 191 */
        "movl $0x3f800000, -0x54(%ebp)\n" /* line 192 */
        "movl %edi, -0x50(%ebp)\n" /* line 193 */
        "movl %edi, -0x4c(%ebp)\n" /* line 191 */
        "movl %edi, -0x48(%ebp)\n" /* line 192 */
        "movl $0x3f800000, -0x44(%ebp)\n" /* line 193 */
        "movl %eax, 8(%esp)\n" /* line 3434 */
        "leal -0x40(%ebp), %eax\n" /* origin */
        "movl %eax, 4(%esp)\n"
        "leal -0xa4(%ebp), %esi\n" /* view */
        "movl %esi, (%esp)\n"
        "calll MatrixForViewer\n"
        "movl $0x3f666666, 0xc(%esp)\n" /* line 3435 */
        "movl $0x42b40000, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0xe4(%ebp), %ebx\n" /* projection, iterationCount */
        "movl %ebx, (%esp)\n" /* iterationCount */
        "calll InfinitePerspectiveMatrix\n"
        "calll RB_Set3D\n" /* line 3437 */
        "calll RB_PushMatrixStack\n" /* line 3438 */
        "calll RB_GetActiveWorldMatrix\n" /* line 3439 */
        "movl %eax, (%esp)\n" /* line 3440 */
        "calll MatrixIdentity44\n"
        "movl $0x3f800000, (%esp)\n" /* line 3441 */
        "calll RB_ChangedWorldMatrix\n"
        "movl %esi, (%esp)\n" /* line 3442 */
        "calll RB_SetViewMatrix\n"
        "movl %ebx, (%esp)\n" /* line 3443 | iterationCount */
        "calll RB_SetProjectionMatrix\n"
        "movl $backEnd+1096, backEnd+1088\n" /* line 3445 */
        "movl $0, backEnd+1092\n" /* line 3446 */
        "movl $0x3f800000, backEnd+80\n" /* line 447 */
        "movl $0x3f800000, backEnd+84\n" /* line 448 */
        "movl $0x3f800000, backEnd+88\n" /* line 449 */
        "movl $0x3f800000, backEnd+92\n" /* line 450 */
        "movl %edi, backEnd+48\n" /* line 447 */
        "movl %edi, backEnd+52\n" /* line 448 */
        "movl %edi, backEnd+56\n" /* line 449 */
        "movl $0x3f800000, backEnd+60\n" /* line 450 */
        "movl %edi, backEnd+176\n" /* line 447 */
        "movl %edi, backEnd+180\n" /* line 448 */
        "movl %edi, backEnd+184\n" /* line 449 */
        "movl $0x3f800000, backEnd+188\n" /* line 450 */
        "movl $0, 8(%esp)\n" /* line 3452 */
        "movl -0xf0(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xec(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "movss -0x40(%ebp), %xmm5\n" /* line 240 | origin */
        "addss -0x64(%ebp), %xmm5\n" /* axis */
        "movss %xmm5, -0x40(%ebp)\n" /* origin */
        "movss -0x3c(%ebp), %xmm4\n" /* line 241 */
        "addss -0x60(%ebp), %xmm4\n"
        "movss %xmm4, -0x3c(%ebp)\n"
        "movss -0x38(%ebp), %xmm3\n" /* line 242 */
        "addss -0x5c(%ebp), %xmm3\n"
        "movss %xmm3, -0x38(%ebp)\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* line 3457 | white */
        "movaps %xmm3, %xmm2\n" /* line 3458 */
        "addss -0x50(%ebp), %xmm2\n"
        "addss -0x44(%ebp), %xmm2\n"
        "movaps %xmm4, %xmm1\n"
        "addss -0x54(%ebp), %xmm1\n"
        "addss -0x48(%ebp), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "addss -0x58(%ebp), %xmm0\n"
        "addss -0x4c(%ebp), %xmm0\n"
        "movl imp_r_rendererInUse, %ebx\n" /* line 370 */
        "movl (%ebx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfd8330_000d88aa\n"
        /* { scope 2 */
        "movss %xmm0, tess\n" /* line 447 */
        "movss %xmm1, tess+4\n" /* line 448 */
        "movss %xmm2, tess+8\n" /* line 449 */
        "movl $0x3f800000, tess+12\n" /* line 450 */
        /* } scope */
        "movl %edi, tess+16\n" /* line 191 */
        "movl %edi, tess+20\n" /* line 192 */
        "movl $0x3f800000, tess+24\n" /* line 193 */
        "leal -0x1c(%ebp), %ecx\n" /* line 606 | white */
        "movl $0xffffffff, tess+28\n"
        "movl %edi, tess+32\n" /* line 30 */
        "movl %edi, tess+36\n" /* line 31 */
        "movl $0x3f800000, tess+52\n" /* line 191 */
        "movl %edi, tess+56\n" /* line 192 */
        "movl %edi, tess+60\n" /* line 193 */
        "movl %edi, tess+40\n" /* line 191 */
        "movl $0x3f800000, tess+44\n" /* line 192 */
        "movl %edi, tess+48\n" /* line 193 */
        ".Lfd8330_000d856a:\n"
        "movaps %xmm3, %xmm2\n" /* line 3459 */
        "subss -0x50(%ebp), %xmm2\n"
        "addss -0x44(%ebp), %xmm2\n"
        "movaps %xmm4, %xmm1\n"
        "subss -0x54(%ebp), %xmm1\n"
        "addss -0x48(%ebp), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "subss -0x58(%ebp), %xmm0\n"
        "addss -0x4c(%ebp), %xmm0\n"
        "movl (%ebx), %eax\n" /* line 370 */
        "cmpl $2, 8(%eax)\n"
        "je .Lfd8330_000d89a0\n"
        /* { scope 2 */
        "movss %xmm0, tess\n" /* line 447 */
        "movss %xmm1, tess+4\n" /* line 448 */
        "movss %xmm2, tess+8\n" /* line 449 */
        "movl $0x3f800000, %edx\n" /* line 450 */
        "movl %edx, tess+12\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, tess+16\n"
        "movl %eax, tess+20\n" /* line 192 */
        "movl %edx, tess+24\n" /* line 193 */
        "movl (%ecx), %ecx\n" /* line 606 */
        "movl %ecx, tess+28\n"
        "movl %edx, tess+32\n" /* line 30 */
        "movl %eax, tess+36\n" /* line 31 */
        "movl %edx, tess+52\n" /* line 191 */
        "movl %eax, tess+56\n" /* line 192 */
        "movl %eax, tess+60\n" /* line 193 */
        "movl %eax, tess+40\n" /* line 191 */
        "movl %edx, tess+44\n" /* line 192 */
        "movl %eax, tess+48\n" /* line 193 */
        ".Lfd8330_000d8605:\n"
        "movaps %xmm3, %xmm2\n" /* line 3460 */
        "subss -0x50(%ebp), %xmm2\n"
        "subss -0x44(%ebp), %xmm2\n"
        "movaps %xmm4, %xmm1\n"
        "subss -0x54(%ebp), %xmm1\n"
        "subss -0x48(%ebp), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "subss -0x58(%ebp), %xmm0\n"
        "subss -0x4c(%ebp), %xmm0\n"
        "movl (%ebx), %eax\n" /* line 370 */
        "cmpl $2, 8(%eax)\n"
        "je .Lfd8330_000d894b\n"
        /* { scope 2 */
        "movss %xmm0, tess\n" /* line 447 */
        "movss %xmm1, tess+4\n" /* line 448 */
        "movss %xmm2, tess+8\n" /* line 449 */
        "movl $0x3f800000, tess+12\n" /* line 450 */
        /* } scope */
        "movl $0, tess+16\n" /* line 191 */
        "movl $0, tess+20\n" /* line 192 */
        "movl $0x3f800000, tess+24\n" /* line 193 */
        "movl %ecx, tess+28\n" /* line 606 */
        "movl $0x3f800000, tess+32\n" /* line 30 */
        "movl $0x3f800000, tess+36\n" /* line 31 */
        "movl $0x3f800000, tess+52\n" /* line 191 */
        "movl $0, tess+56\n" /* line 192 */
        "movl $0, tess+60\n" /* line 193 */
        "movl $0, tess+40\n" /* line 191 */
        "movl $0x3f800000, tess+44\n" /* line 192 */
        "movl $0, tess+48\n" /* line 193 */
        ".Lfd8330_000d86ce:\n"
        "movaps %xmm3, %xmm2\n" /* line 3461 */
        "addss -0x50(%ebp), %xmm2\n"
        "subss -0x44(%ebp), %xmm2\n"
        "movaps %xmm4, %xmm1\n"
        "addss -0x54(%ebp), %xmm1\n"
        "subss -0x48(%ebp), %xmm1\n"
        "movaps %xmm5, %xmm0\n"
        "addss -0x58(%ebp), %xmm0\n"
        "subss -0x4c(%ebp), %xmm0\n"
        "movl (%ebx), %eax\n" /* line 370 */
        "cmpl $2, 8(%eax)\n"
        "je .Lfd8330_000d88f6\n"
        /* { scope 2 */
        "movss %xmm0, tess\n" /* line 447 */
        "movss %xmm1, tess+4\n" /* line 448 */
        "movss %xmm2, tess+8\n" /* line 449 */
        "movl $0x3f800000, tess+12\n" /* line 450 */
        /* } scope */
        "movl $0, tess+16\n" /* line 191 */
        "movl $0, tess+20\n" /* line 192 */
        "movl $0x3f800000, tess+24\n" /* line 193 */
        "movl %ecx, tess+28\n" /* line 606 */
        "movl $0, tess+32\n" /* line 30 */
        "movl $0x3f800000, tess+36\n" /* line 31 */
        "movl $0x3f800000, tess+52\n" /* line 191 */
        "movl $0, tess+56\n" /* line 192 */
        "movl $0, tess+60\n" /* line 193 */
        "movl $0, tess+40\n" /* line 191 */
        "movl $0x3f800000, tess+44\n" /* line 192 */
        "movl $0, tess+48\n" /* line 193 */
        ".Lfd8330_000d8797:\n"
        "movl $4, tess+370644\n" /* line 3462 */
        "movl imp_r_testFill, %eax\n" /* line 3464 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* iterationCount */
        "testl %ebx, %ebx\n" /* line 3465 | iterationCount */
        "jle .Lfd8330_000d8836\n"
        "xorl %ecx, %ecx\n"
        "movl tess+370640, %edx\n"
        ".Lfd8330_000d87bb:\n"
        "movl tess+370608, %eax\n" /* line 3467 */
        "movw $3, (%eax, %edx, 2)\n"
        "movl tess+370640, %edx\n" /* line 3468 */
        "movl tess+370608, %eax\n"
        "movw $0, 2(%eax, %edx, 2)\n"
        "movl tess+370640, %edx\n" /* line 3469 */
        "movl tess+370608, %eax\n"
        "movw $2, 4(%eax, %edx, 2)\n"
        "movl tess+370640, %edx\n" /* line 3470 */
        "movl tess+370608, %eax\n"
        "movw $2, 6(%eax, %edx, 2)\n"
        "movl tess+370640, %edx\n" /* line 3471 */
        "movl tess+370608, %eax\n"
        "movw $0, 8(%eax, %edx, 2)\n"
        "movl tess+370640, %edx\n" /* line 3472 */
        "movl tess+370608, %eax\n"
        "movw $1, 0xa(%eax, %edx, 2)\n"
        "movl tess+370640, %eax\n" /* line 3473 */
        "addl $6, %eax\n"
        "movl %eax, %edx\n"
        "movl %eax, tess+370640\n"
        "addl $1, %ecx\n" /* line 3465 */
        "cmpl %ecx, %ebx\n" /* iterationCount */
        "jne .Lfd8330_000d87bb\n"
        ".Lfd8330_000d8836:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 3476 | beginTime */
        "calll RB_BeginBenchmarkGpu\n"
        "calll RB_EndSurface\n" /* line 3478 */
        "leal -0x24(%ebp), %eax\n" /* line 3480 | endTime */
        "calll RB_EndBenchmarkGpu\n"
        "calll RB_PopMatrixStack\n" /* line 3482 */
        /* { scope 2 */
        "leal -0x34(%ebp), %eax\n" /* line 3378 | frequency */
        "movl %eax, (%esp)\n"
        "calll QueryPerformanceFrequency\n"
        "cvtsi2sdl %ebx, %xmm1\n"
        "movl -0x24(%ebp), %eax\n" /* endTime */
        "movl -0x20(%ebp), %edx\n"
        "subl -0x2c(%ebp), %eax\n" /* beginTime */
        "sbbl -0x28(%ebp), %edx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "fildll (%esp)\n"
        "fstpl -0x100(%ebp)\n"
        "movsd -0x100(%ebp), %xmm0\n"
        "fildll -0x34(%ebp)\n" /* frequency */
        "fstpl -0xf8(%ebp)\n"
        "divsd -0xf8(%ebp), %xmm0\n"
        "divsd %xmm0, %xmm1\n"
        "divsd lit8_00307cd8, %xmm1\n" /* 60.0 */
        /* } scope */
        /* } scope */
        "cvtsd2ss %xmm1, %xmm0\n" /* line 3485 */
        "addl $0x114, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: frequency */
        ".Lfd8330_000d88aa:\n"
        "movss %xmm0, tess\n" /* line 191 */
        "movss %xmm1, tess+4\n" /* line 192 */
        "movss %xmm2, tess+8\n" /* line 193 */
        "movl %edi, tess+12\n" /* line 191 */
        "movl %edi, tess+16\n" /* line 192 */
        "movl $0x3f800000, tess+20\n" /* line 193 */
        "leal -0x1c(%ebp), %ecx\n" /* line 606 | white */
        "movl $0xffffffff, tess+24\n"
        "movl %edi, tess+28\n" /* line 30 */
        "movl %edi, tess+32\n" /* line 31 */
        "jmp .Lfd8330_000d856a\n"
        ".Lfd8330_000d88f6:\n"
        "movss %xmm0, tess\n" /* line 191 */
        "movss %xmm1, tess+4\n" /* line 192 */
        "movss %xmm2, tess+8\n" /* line 193 */
        "movl $0, tess+12\n" /* line 191 */
        "movl $0, tess+16\n" /* line 192 */
        "movl $0x3f800000, tess+20\n" /* line 193 */
        "movl %ecx, tess+24\n" /* line 606 */
        "movl $0, tess+28\n" /* line 30 */
        "movl $0x3f800000, tess+32\n" /* line 31 */
        "jmp .Lfd8330_000d8797\n"
        ".Lfd8330_000d894b:\n"
        "movss %xmm0, tess\n" /* line 191 */
        "movss %xmm1, tess+4\n" /* line 192 */
        "movss %xmm2, tess+8\n" /* line 193 */
        "movl $0, tess+12\n" /* line 191 */
        "movl $0, tess+16\n" /* line 192 */
        "movl $0x3f800000, tess+20\n" /* line 193 */
        "movl %ecx, tess+24\n" /* line 606 */
        "movl $0x3f800000, tess+28\n" /* line 30 */
        "movl $0x3f800000, tess+32\n" /* line 31 */
        "jmp .Lfd8330_000d86ce\n"
        ".Lfd8330_000d89a0:\n"
        "movss %xmm0, tess\n" /* line 191 */
        "movss %xmm1, tess+4\n" /* line 192 */
        "movss %xmm2, tess+8\n" /* line 193 */
        "xorl %eax, %eax\n" /* line 191 */
        "movl %eax, tess+12\n"
        "movl %eax, tess+16\n" /* line 192 */
        "movl $0x3f800000, %edx\n" /* line 193 */
        "movl %edx, tess+20\n"
        "movl (%ecx), %ecx\n" /* line 606 */
        "movl %ecx, tess+24\n"
        "movl %edx, tess+28\n" /* line 30 */
        "movl %eax, tess+32\n" /* line 31 */
        "jmp .Lfd8330_000d8605\n"
    );
}

/* line 433 */
/* line 433 */
void RB_DrawStretchPic(const Material *material, float x, float y, float w, float h, float s0, float t0, float s1, float t1, D3DCOLOR color, GfxPrimStatsTarget statsTarget)
{
    char *t = (char *)&tess;
    r_index_t *indices;
    int vc, ic;
    int isDx7;
    int savedDecl;

    (void)statsTarget;

    if (!material)
        return;

    /* Enter 2D mode if not already active */
    if (!*((byte *)&backEnd + 0x4bd))
        RB_Set2D();

    /* Begin surface if material or technique changed */
    if (material != *(const Material **)(t + 0x5a7bc) ||
        *(MaterialTechniqueType *)(t + 0x5a7c0) != 3) { /* TECHNIQUE_UNLIT */
        if (*(int *)(t + 0x5a7d0) != 0 || *(int *)(t + 0x5a7e0) != 0)
            RB_EndSurface();
        RB_BeginSurface(material, 3, 0x1f); /* TECHNIQUE_UNLIT, lmapIndex=31 */
    }

    /* Check tess buffer overflow: need 4 verts + 6 indices */
    vc = *(int *)(t + 0x5a7d4); /* vertexCount */
    ic = *(int *)(t + 0x5a7d0); /* indexCount */
    if (vc + 4 > 0x154a || ic + 6 > 0x100000) {
        /* Flush and re-begin, preserving declType */
        savedDecl = *(int *)(t + 0x5a7cc);
        RB_EndSurface();
        RB_BeginSurface(*(const Material **)(t + 0x5a7bc),
                        *(MaterialTechniqueType *)(t + 0x5a7c0),
                        *(int *)(t + 0x5a7c4));
        if (*(int *)(t + 0x5a7cc) != savedDecl) {
            if (*(int *)(t + 0x5a7d0) != 0 || *(int *)(t + 0x5a7e0) != 0)
                RB_EndSurface();
            *(int *)(t + 0x5a7cc) = savedDecl;
        }
        vc = *(int *)(t + 0x5a7d4);
        ic = *(int *)(t + 0x5a7d0);
    }

    /* Write 6 indices for 2 triangles: (vc+3, vc, vc+2), (vc+2, vc, vc+1) */
    indices = *(r_index_t **)(t + 0x5a7b0);
    indices[ic + 0] = (r_index_t)(vc + 3);
    indices[ic + 1] = (r_index_t)vc;
    indices[ic + 2] = (r_index_t)(vc + 2);
    indices[ic + 3] = (r_index_t)(vc + 2);
    indices[ic + 4] = (r_index_t)vc;
    indices[ic + 5] = (r_index_t)(vc + 1);

    isDx7 = (*(int *)(*(char **)imp_r_rendererInUse + 8) == 2);

    /* Diagnostic: log vertex positions */
    diag_rb_draw(*(unsigned int *)&x, *(unsigned int *)&y, (unsigned int)(uintptr_t)material);

    if (isDx7) {
        /* Dx7 vertex layout: stride 36 (0x24)
         *   +0x00: vec3 position, +0x0c: vec3 normal, +0x18: color, +0x1c: vec2 texcoord */
        char *v0 = t + vc * 36;
        char *v1 = v0 + 36;
        char *v2 = v0 + 72;
        char *v3 = v0 + 108;

        /* Vertex 0: (x, y) texcoord (s0, t0) */
        *(float *)(v0 + 0x00) = x;
        *(float *)(v0 + 0x04) = y;
        *(float *)(v0 + 0x08) = 0.0f;
        *(float *)(v0 + 0x0c) = 0.0f;
        *(float *)(v0 + 0x10) = 0.0f;
        *(float *)(v0 + 0x14) = 1.0f;
        *(D3DCOLOR *)(v0 + 0x18) = color;
        *(float *)(v0 + 0x1c) = s0;
        *(float *)(v0 + 0x20) = t0;

        /* Vertex 1: (x+w, y) texcoord (s1, t0) */
        *(float *)(v1 + 0x00) = x + w;
        *(float *)(v1 + 0x04) = y;
        *(float *)(v1 + 0x08) = 0.0f;
        *(float *)(v1 + 0x0c) = 0.0f;
        *(float *)(v1 + 0x10) = 0.0f;
        *(float *)(v1 + 0x14) = 1.0f;
        *(D3DCOLOR *)(v1 + 0x18) = color;
        *(float *)(v1 + 0x1c) = s1;
        *(float *)(v1 + 0x20) = t0;

        /* Vertex 2: (x+w, y+h) texcoord (s1, t1) */
        *(float *)(v2 + 0x00) = x + w;
        *(float *)(v2 + 0x04) = y + h;
        *(float *)(v2 + 0x08) = 0.0f;
        *(float *)(v2 + 0x0c) = 0.0f;
        *(float *)(v2 + 0x10) = 0.0f;
        *(float *)(v2 + 0x14) = 1.0f;
        *(D3DCOLOR *)(v2 + 0x18) = color;
        *(float *)(v2 + 0x1c) = s1;
        *(float *)(v2 + 0x20) = t1;

        /* Vertex 3: (x, y+h) texcoord (s0, t1) */
        *(float *)(v3 + 0x00) = x;
        *(float *)(v3 + 0x04) = y + h;
        *(float *)(v3 + 0x08) = 0.0f;
        *(float *)(v3 + 0x0c) = 0.0f;
        *(float *)(v3 + 0x10) = 0.0f;
        *(float *)(v3 + 0x14) = 1.0f;
        *(D3DCOLOR *)(v3 + 0x18) = color;
        *(float *)(v3 + 0x1c) = s0;
        *(float *)(v3 + 0x20) = t1;
    } else {
        /* Non-Dx7 vertex layout: stride 64 (0x40)
         *   +0x00: vec4 pos, +0x10: vec3 normal, +0x1c: color,
         *   +0x20: vec2 texcoord, +0x28: vec3 binormal, +0x34: vec3 tangent */
        char *v0 = t + vc * 64;
        char *v1 = v0 + 64;
        char *v2 = v0 + 128;
        char *v3 = v0 + 192;

        /* Vertex 0: (x, y) texcoord (s0, t0) */
        *(float *)(v0 + 0x00) = x;
        *(float *)(v0 + 0x04) = y;
        *(float *)(v0 + 0x08) = 0.0f;
        *(float *)(v0 + 0x0c) = 1.0f;
        *(float *)(v0 + 0x10) = 0.0f;
        *(float *)(v0 + 0x14) = 0.0f;
        *(float *)(v0 + 0x18) = 1.0f;
        *(D3DCOLOR *)(v0 + 0x1c) = color;
        *(float *)(v0 + 0x20) = s0;
        *(float *)(v0 + 0x24) = t0;
        *(float *)(v0 + 0x28) = 0.0f;  /* binormal */
        *(float *)(v0 + 0x2c) = 1.0f;
        *(float *)(v0 + 0x30) = 0.0f;
        *(float *)(v0 + 0x34) = 1.0f;  /* tangent */
        *(float *)(v0 + 0x38) = 0.0f;
        *(float *)(v0 + 0x3c) = 0.0f;

        /* Vertex 1: (x+w, y) texcoord (s1, t0) */
        *(float *)(v1 + 0x00) = x + w;
        *(float *)(v1 + 0x04) = y;
        *(float *)(v1 + 0x08) = 0.0f;
        *(float *)(v1 + 0x0c) = 1.0f;
        *(float *)(v1 + 0x10) = 0.0f;
        *(float *)(v1 + 0x14) = 0.0f;
        *(float *)(v1 + 0x18) = 1.0f;
        *(D3DCOLOR *)(v1 + 0x1c) = color;
        *(float *)(v1 + 0x20) = s1;
        *(float *)(v1 + 0x24) = t0;
        *(float *)(v1 + 0x28) = 0.0f;
        *(float *)(v1 + 0x2c) = 1.0f;
        *(float *)(v1 + 0x30) = 0.0f;
        *(float *)(v1 + 0x34) = 1.0f;
        *(float *)(v1 + 0x38) = 0.0f;
        *(float *)(v1 + 0x3c) = 0.0f;

        /* Vertex 2: (x+w, y+h) texcoord (s1, t1) */
        *(float *)(v2 + 0x00) = x + w;
        *(float *)(v2 + 0x04) = y + h;
        *(float *)(v2 + 0x08) = 0.0f;
        *(float *)(v2 + 0x0c) = 1.0f;
        *(float *)(v2 + 0x10) = 0.0f;
        *(float *)(v2 + 0x14) = 0.0f;
        *(float *)(v2 + 0x18) = 1.0f;
        *(D3DCOLOR *)(v2 + 0x1c) = color;
        *(float *)(v2 + 0x20) = s1;
        *(float *)(v2 + 0x24) = t1;
        *(float *)(v2 + 0x28) = 0.0f;
        *(float *)(v2 + 0x2c) = 1.0f;
        *(float *)(v2 + 0x30) = 0.0f;
        *(float *)(v2 + 0x34) = 1.0f;
        *(float *)(v2 + 0x38) = 0.0f;
        *(float *)(v2 + 0x3c) = 0.0f;

        /* Vertex 3: (x, y+h) texcoord (s0, t1) */
        *(float *)(v3 + 0x00) = x;
        *(float *)(v3 + 0x04) = y + h;
        *(float *)(v3 + 0x08) = 0.0f;
        *(float *)(v3 + 0x0c) = 1.0f;
        *(float *)(v3 + 0x10) = 0.0f;
        *(float *)(v3 + 0x14) = 0.0f;
        *(float *)(v3 + 0x18) = 1.0f;
        *(D3DCOLOR *)(v3 + 0x1c) = color;
        *(float *)(v3 + 0x20) = s0;
        *(float *)(v3 + 0x24) = t1;
        *(float *)(v3 + 0x28) = 0.0f;
        *(float *)(v3 + 0x2c) = 1.0f;
        *(float *)(v3 + 0x30) = 0.0f;
        *(float *)(v3 + 0x34) = 1.0f;
        *(float *)(v3 + 0x38) = 0.0f;
        *(float *)(v3 + 0x3c) = 0.0f;
    }

    *(int *)(t + 0x5a7d4) += 4; /* vertexCount += 4 */
    *(int *)(t + 0x5a7d0) += 6; /* indexCount += 6 */
}

/* line 609 */
static void RB_StretchPicCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;

    RB_DrawStretchPic(
        *(const Material **)(cmd + 4),  /* material */
        *(float *)(cmd + 8),            /* x */
        *(float *)(cmd + 0xc),          /* y */
        *(float *)(cmd + 0x10),         /* w */
        *(float *)(cmd + 0x14),         /* h */
        *(float *)(cmd + 0x18),         /* s0 */
        *(float *)(cmd + 0x1c),         /* t0 */
        *(float *)(cmd + 0x20),         /* s1 */
        *(float *)(cmd + 0x24),         /* t1 */
        *(D3DCOLOR *)(cmd + 0x28),      /* color */
        8);                             /* statsTarget */

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 3383 */
/* line 3383 */
static float RB_BenchmarkRepeatedCalls_impl(const Material *material, int iterationCount, float width, float height)
{
    long long beginTime, endTime, frequency;
    int i;

    if (Material_IsDefault((MaterialHandle)material))
        return 0.0f;

    RB_BeginBenchmarkGpu_impl(&beginTime);

    for (i = 0; i < iterationCount; i++) {
        RB_DrawStretchPic(material, 0.0f, 0.0f, width, height,
                          0.0f, 0.0f, 1.0f, 1.0f, 0xffffffff, 10);
    }

    RB_EndSurface();
    RB_EndBenchmarkGpu_impl(&endTime);

    QueryPerformanceFrequency(&frequency);

    {
        double elapsed = (double)(endTime - beginTime) / (double)frequency;
        return (float)((double)iterationCount / elapsed);
    }
}

/* Naked trampoline: marshals register args (eax=material, edx=iterationCount,
 * xmm0=width, xmm1=height) to stack for _impl */
static __attribute__((naked))
float RB_BenchmarkRepeatedCalls(float width, float height)
{
    __asm__ __volatile__ (
        "subl $16, %esp\n"
        "movss %xmm1, 12(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll RB_BenchmarkRepeatedCalls_impl\n"
        "addl $16, %esp\n"
        "retl\n"
    );
}

int g_rb_exec_count = 0; /* diagnostic */
static const char rb_diag_fmt[] = "";
static const char rb_diag_dispatch_fmt[] = "";
static const char rb_endframe_fmt[] = "";
static const char rb_diag_post_fmt[] = "";
int g_rb_dispatch_count = 0; /* diagnostic: how many commands dispatched */
int g_rb_first_cmd = -1; /* diagnostic: first command word seen */
int g_rb_skip_reason = 0; /* diagnostic: 1=disableRendering, 2=needToTouch+recover_fail, 3=skipBackEnd, 4=empty_buf */
/* line 3915 */
__attribute__((naked))
void RB_ExecuteRenderCommands(const void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3915 */
        "movl %esp, %ebp\n"
        "incl g_rb_exec_count\n"
        "calll diag_rb_frame_start\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl $0, backEndData\n" /* line 3926 */
        "movl imp_g_disableRendering, %eax\n" /* line 3928 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfd9182_diag_noDisable\n"
        "movl $1, g_rb_skip_reason\n" /* diagnostic: disableRendering */
        "movl $1, diag_rb_skip_this_frame\n"
        "jmp .Lfd9182_000d9535\n"
        ".Lfd9182_diag_noDisable:\n"
        "movl imp_dx, %esi\n" /* line 3932 */
        "cmpb $0, 0x2d3c(%esi)\n"
        "je .Lfd9182_000d956f\n"
        ".Lfd9182_000d91b7:\n"
        "movzbl 0x2d3c(%esi), %edi\n" /* line 3939 | needToTouchImages */
        "movl %edi, %eax\n" /* line 3941 | needToTouchImages */
        "testb %al, %al\n"
        "jne .Lfd9182_000d9547\n"
        "movl 8(%ebp), %edx\n" /* line 3951 | data */
        "movl %edx, backEndData\n"
        "movl imp_r_textureMode, %eax\n" /* line 3854 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lfd9182_000d99cd\n"
        ".Lfd9182_000d91e2:\n"
        "movl imp_r_anisotropy, %eax\n" /* line 3860 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lfd9182_000d99f1\n"
        ".Lfd9182_000d91f3:\n"
        "movl imp_r_cosinePowerMapShift, %ebx\n" /* line 3866 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lfd9182_000d9a16\n"
        ".Lfd9182_000d9205:\n"
        "movl imp_r_outdoorFeather, %ebx\n" /* line 3872 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lfd9182_000d9a43\n"
        ".Lfd9182_000d9217:\n"
        "movl imp_r_aaAlpha, %eax\n" /* line 3879 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "jne .Lfd9182_000d9a7b\n"
        ".Lfd9182_000d9228:\n"
        "movl imp_dx, %esi\n" /* line 3686 */
        "movl 0x2c20(%esi), %eax\n"
        "cmpl $3, %eax\n"
        "je .Lfd9182_000d9aae\n"
        "subl $1, %eax\n" /* line 3690 */
        "je .Lfd9182_000d9c05\n"
        ".Lfd9182_000d9246:\n"
        "movb $1, 0x2d3d(%esi)\n" /* line 3699 */
        "jmp .Lfd9182_000d9255\n"
        ".Lfd9182_000d924f:\n"
        "movl imp_dx, %esi\n"
        ".Lfd9182_000d9255:\n"
        "movl 8(%esi), %eax\n" /* line 3700 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xa4(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfd9182_000d924f\n"
        "addl $1, backEnd+944\n" /* line 3706 */
        "movl %edi, %ecx\n" /* line 3958 | needToTouchImages */
        "testb %cl, %cl\n"
        "jne .Lfd9182_000d9bee\n"
        ".Lfd9182_000d927f:\n"
        "movl imp_r_skipBackEnd, %eax\n" /* line 3962 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfd9182_diag_noSkip\n"
        "movl $3, g_rb_skip_reason\n" /* diagnostic: skipBackEnd */
        "movl $3, diag_rb_skip_this_frame\n"
        "jmp .Lfd9182_000d9594\n"
        ".Lfd9182_diag_noSkip:\n"
        "movl backEndData, %edx\n" /* line 3970 */
        "leal 0x219d0c(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* execState */
        "movl $0, -0x24(%ebp)\n" /* line 3971 */
        "movzwl 0x219d0c(%edx), %eax\n" /* line 3980 */
        "movl %eax, g_rb_first_cmd\n" /* diagnostic: record first cmd */
        /* DIAG: print skip reason + first cmd for first 5 frames */
        "cmpl $5, g_rb_exec_count\n"
        "jg .Lfd9182_diag_skip_print\n"
        "pushal\n"
        "pushl %eax\n"
        "pushl g_rb_exec_count\n"
        "pushl $rb_diag_fmt\n"
        "calll printf\n"
        "addl $12, %esp\n"
        "popal\n"
        ".Lfd9182_diag_skip_print:\n"
        "testw %ax, %ax\n"
        "jne .Lfd9182_000d9c52\n"
        "movl $4, g_rb_skip_reason\n" /* diagnostic: empty buffer */
        "movl $4, diag_rb_skip_this_frame\n"
        ".Lfd9182_000d92b6:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd9182_000d953d\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd9182_000d953d\n"
        ".Lfd9182_000d92d0:\n"
        "movl backEnd+968, %edx\n" /* line 4008 */
        "testl %edx, %edx\n"
        "je .Lfd9182_000d92ec\n"
        "movl imp_developer, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd9182_000d9bf8\n"
        ".Lfd9182_000d92ec:\n"
        "movl imp_dxState, %eax\n" /* line 212 */
        "movl 0x20cc(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd9182_000d9307\n"
        "movl $0, (%esp)\n" /* line 213 */
        "calll RB_ChangeIndices\n"
        ".Lfd9182_000d9307:\n"
        "calll RB_ClearAllStreamSources\n" /* line 4014 */
        "movl imp_dx, %edi\n" /* needToTouchImages */
        "movl imp_alwaysfails, %ebx\n"
        ".Lfd9182_000d9318:\n"
        "movl 8(%edi), %eax\n" /* line 4015 | needToTouchImages */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xa8(%edx)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd9182_000d9318\n"
        "movb $0, 0x2d3d(%edi)\n" /* line 4016 | needToTouchImages */
        "movl imp_r_testFill, %edx\n" /* line 4018 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lfd9182_000d9398\n"
        "movl imp_r_testFillEnable, %eax\n" /* line 3491 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfd9182_000d95f4\n"
        "movl imp_ri, %ebx\n" /* line 3493 */
        "movl $str_002245d8, 4(%esp)\n" /* "Fill testing uses extra textures and materials, so it is usu" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $str_00224628, 4(%esp)\n" /* line 3494 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        ".Lfd9182_000d937b:\n"
        "movl $0, 4(%esp)\n" /* line 4021 */
        "movl imp_r_testFill, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x98(%eax)\n"
        ".Lfd9182_000d9398:\n"
        "movl imp_r_testTransform, %esi\n" /* line 4024 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jle .Lfd9182_000d94df\n"
        "movl imp_rgp, %eax\n" /* line 3641 */
        "movl 0x1038(%eax), %eax\n"
        "movl $0x552, %edx\n"
        "pxor %xmm1, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3642 | 60.0f */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl imp_ri, %ebx\n" /* line 3656 */
        "movl $str_00224674, 4(%esp)\n" /* "-----------------------------------------------
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 3657 */
        "movl $0, 0xc(%esp)\n"
        "movl $str_00224980, 4(%esp)\n" /* "static vertex data    %8.0f verts/sec @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 3658 */
        "movl $0, 0xc(%esp)\n"
        "movl $str_002249b0, 4(%esp)\n" /* "static vertex data    %8.0f tris/sec @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 3659 */
        "movl $0, 0xc(%esp)\n"
        "movl $str_002249e0, 4(%esp)\n" /* "skinned vertex data   %8.0f verts/sec @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $0, 8(%esp)\n" /* line 3660 */
        "movl $0, 0xc(%esp)\n"
        "movl $str_00224a10, 4(%esp)\n" /* "skinned vertex data   %8.0f tris/sec @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 3661 */
        "mulss lit4_002ed608, %xmm0\n" /* 4.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224a40, 4(%esp)\n" /* "dynamic vertex data   %8.0f verts/sec @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 3662 */
        "addss %xmm0, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224a70, 4(%esp)\n" /* "dynamic vertex data   %8.0f tris/sec @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $str_00224674, 4(%esp)\n" /* line 3663 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n"
        "movl $0, 4(%esp)\n" /* line 4027 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x98(%ebx)\n"
        ".Lfd9182_000d94df:\n"
        "movl imp_dx, %esi\n" /* line 4031 */
        "movl 0x2c20(%esi), %eax\n"
        "cmpl $3, %eax\n"
        "je .Lfd9182_000d9c72\n"
        "cmpl $2, %eax\n" /* line 4035 */
        "jne .Lfd9182_000d9535\n"
        "movl %esi, %edi\n" /* needToTouchImages */
        ".Lfd9182_000d94fb:\n"
        "cmpb $0, 0x2d68(%esi)\n" /* line 3309 */
        "jne .Lfd9182_000d9b14\n"
        ".Lfd9182_000d9508:\n"
        "movl $g_FenceID, 4(%esp)\n" /* line 3202 */
        "movl $1, (%esp)\n"
        "calll glGenFencesAPPLE\n"
        "movl g_FenceID, %eax\n" /* line 3203 */
        "movl %eax, (%esp)\n"
        "calll glSetFenceAPPLE\n"
        "movl imp_dx, %eax\n" /* line 3206 */
        "movb $1, 0x2d68(%eax)\n"
        /* } scope */
        ".Lfd9182_000d9535:\n"
        "calll diag_rb_frame_end\n"
        "addl $0x4c, %esp\n" /* line 4075 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd9182_000d953d:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfd9182_000d92d0\n"
        ".Lfd9182_000d9547:\n"
        "calll R_RecoverLostDevice\n" /* line 3943 */
        "testb %al, %al\n"
        "je .Lfd9182_000d9535\n"
        "movl 8(%ebp), %edx\n" /* line 3951 | data */
        "movl %edx, backEndData\n"
        "movl imp_r_textureMode, %eax\n" /* line 3854 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "je .Lfd9182_000d91e2\n"
        "jmp .Lfd9182_000d99cd\n"
        ".Lfd9182_000d956f:\n"
        "movl 8(%esi), %eax\n" /* line 3934 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "addl $0x7789f798, %eax\n" /* line 3935 */
        "cmpl $1, %eax\n"
        "ja .Lfd9182_000d91b7\n"
        "movb $1, 0x2d3c(%esi)\n" /* line 3936 */
        "jmp .Lfd9182_000d91b7\n"
        ".Lfd9182_000d9594:\n"
        "cmpb $0, backEnd+1212\n" /* line 3994 */
        "jne .Lfd9182_000d9c48\n"
        ".Lfd9182_000d95a1:\n"
        "movl imp_dx, %eax\n" /* line 3996 */
        "movl 8(%eax), %eax\n"
        "movl (%eax), %edx\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xac(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd9182_000d95a1\n"
        "jmp .Lfd9182_000d92b6\n"
        ".Lfd9182_000d95f4:\n"
        "movl $str_00224674, 4(%esp)\n" /* line 3498 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %ecx\n"
        "calll *(%ecx)\n"
        "movl imp_ri, %eax\n" /* line 3499 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_dxState, %esi\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x105c(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3499 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002246a8, 4(%esp)\n" /* "normal fill                 %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3500 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1060(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3500 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002246dc, 4(%esp)\n" /* "alpha blend fill            %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3501 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1064(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3501 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224710, 4(%esp)\n" /* "alpha test pass fill        %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3502 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1068(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3502 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224744, 4(%esp)\n" /* "alpha test fail fill        %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3503 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x106c(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3503 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224778, 4(%esp)\n" /* "additive fill               %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3504 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1070(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3504 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002247ac, 4(%esp)\n" /* "depth only fill             %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3505 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1074(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3505 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002247e0, 4(%esp)\n" /* "1-sided stencil keep fill   %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3506 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1078(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3506 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224814, 4(%esp)\n" /* "1-sided stencil reject fill %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "cmpb $0, 0x2d78(%edi)\n" /* line 3507 */
        "jne .Lfd9182_000d9b3d\n"
        ".Lfd9182_000d98ce:\n"
        "movl imp_ri, %eax\n" /* line 3512 */
        "movl (%eax), %ebx\n"
        "movl imp_rgp, %edx\n"
        "movl 0x1084(%edx), %eax\n"
        "movl $0x12, %edx\n"
        "calll RB_TestFillPass3D\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002248b0, 4(%esp)\n" /* "phong point bump fill       %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %ecx\n" /* line 3513 */
        "movl (%ecx), %ebx\n"
        "movl imp_rgp, %edx\n"
        "movl 0x1088(%edx), %eax\n"
        "movl $0x12, %edx\n"
        "calll RB_TestFillPass3D\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_002248e4, 4(%esp)\n" /* "phong point bump+spec fill  %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %ecx\n" /* line 3514 */
        "movl (%ecx), %ebx\n"
        "movl imp_rgp, %edx\n"
        "movl 0x1084(%edx), %eax\n"
        "movl $9, %edx\n"
        "calll RB_TestFillPass3D\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224918, 4(%esp)\n" /* "phong dir bump fill         %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %ecx\n" /* line 3515 */
        "movl (%ecx), %ebx\n"
        "movl imp_rgp, %edx\n"
        "movl 0x1088(%edx), %eax\n"
        "movl $9, %edx\n"
        "calll RB_TestFillPass3D\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_0022494c, 4(%esp)\n" /* "phong dir bump+spec fill    %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl $str_00224674, 4(%esp)\n" /* line 3516 */
        "movl $0, (%esp)\n"
        "movl imp_ri, %ecx\n"
        "calll *(%ecx)\n"
        "jmp .Lfd9182_000d937b\n"
        ".Lfd9182_000d99cd:\n"
        "movl %eax, (%esp)\n" /* line 3856 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "calll RB_DecideDefaultSamplerState\n" /* line 3857 */
        "movl imp_r_anisotropy, %eax\n" /* line 3860 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "je .Lfd9182_000d91f3\n"
        ".Lfd9182_000d99f1:\n"
        "movl %eax, (%esp)\n" /* line 3862 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "calll RB_SetAnisotropy\n" /* line 3863 */
        "movl imp_r_cosinePowerMapShift, %ebx\n" /* line 3866 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "je .Lfd9182_000d9205\n"
        ".Lfd9182_000d9a16:\n"
        "movl %eax, (%esp)\n" /* line 3868 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl (%ebx), %eax\n" /* line 3869 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_RebuildCosinePowerMap\n"
        "movl imp_r_outdoorFeather, %ebx\n" /* line 3872 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "je .Lfd9182_000d9217\n"
        ".Lfd9182_000d9a43:\n"
        "movl %eax, (%esp)\n" /* line 3874 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl (%ebx), %eax\n" /* line 3847 */
        "movl 8(%eax), %eax\n"
        "movl %eax, backEnd+800\n" /* line 447 */
        "movl %eax, backEnd+804\n" /* line 448 */
        "movl %eax, backEnd+808\n" /* line 449 */
        "movl %eax, backEnd+812\n" /* line 450 */
        "movl imp_r_aaAlpha, %eax\n" /* line 3879 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n"
        "je .Lfd9182_000d9228\n"
        ".Lfd9182_000d9a7b:\n"
        "movl %eax, (%esp)\n" /* line 3881 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "cmpb $0, 0x2d7e(%esi)\n" /* line 3882 */
        "je .Lfd9182_000d9228\n"
        "movl imp_dxState, %eax\n" /* line 3883 */
        "movl 0x2008(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_SetAlphaAntiAliasingState\n"
        "jmp .Lfd9182_000d9228\n"
        ".Lfd9182_000d9aae:\n"
        "cmpb $0, 0x2d68(%esi)\n" /* line 3309 */
        "je .Lfd9182_000d9246\n"
        "movl g_FenceID, %eax\n" /* line 3155 */
        "movl %eax, (%esp)\n"
        "calll glTestFenceAPPLE\n"
        "testb %al, %al\n" /* line 3165 */
        "setne %bl\n"
        "testb %bl, %bl\n" /* line 3167 */
        "jne .Lfd9182_000d9cb7\n"
        ".Lfd9182_000d9ad5:\n"
        "testb %bl, %bl\n" /* line 3317 */
        "jne .Lfd9182_000d9cab\n"
        "rdtsc\n" /* line 33 */
        "movl %eax, -0x30(%ebp)\n" /* line 3285 */
        ".Lfd9182_000d9ae2:\n"
        "movl imp_dx, %esi\n" /* line 3309 */
        "cmpb $0, 0x2d68(%esi)\n"
        "jne .Lfd9182_000d9d2d\n"
        ".Lfd9182_000d9af5:\n"
        "rdtsc\n" /* line 33 */
        "subl -0x30(%ebp), %eax\n" /* line 3296 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal 3(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $2, %eax\n"
        "addl %eax, 0x2d60(%esi)\n"
        "jmp .Lfd9182_000d9246\n"
        ".Lfd9182_000d9b14:\n"
        "movl g_FenceID, %eax\n" /* line 3155 */
        "movl %eax, (%esp)\n"
        "calll glTestFenceAPPLE\n"
        "testb %al, %al\n" /* line 3165 */
        "setne %bl\n"
        "testb %bl, %bl\n" /* line 3167 */
        "jne .Lfd9182_000d9cf6\n"
        ".Lfd9182_000d9b2e:\n"
        "testb %bl, %bl\n" /* line 3317 */
        "jne .Lfd9182_000d9c9f\n"
        "movl %edi, %esi\n"
        "jmp .Lfd9182_000d94fb\n"
        ".Lfd9182_000d9b3d:\n"
        "movl imp_ri, %eax\n" /* line 3509 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x107c(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3509 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_00224848, 4(%esp)\n" /* "2-sided stencil keep fill   %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_ri, %eax\n" /* line 3510 */
        "movl (%eax), %ebx\n"
        "movl imp_r_testFill, %edx\n" /* line 3411 */
        "movl (%edx), %eax\n"
        "movl 8(%eax), %edx\n"
        "movl imp_rgp, %ecx\n"
        "movl 0x1080(%ecx), %eax\n"
        "cvtsi2ssl 0x20a0(%esi), %xmm1\n"
        "cvtsi2ssl 0x209c(%esi), %xmm0\n"
        "calll RB_BenchmarkRepeatedCalls\n"
        "divss lit4_002ed7c8, %xmm0\n" /* line 3510 | 60.0f */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_0022487c, 4(%esp)\n" /* "2-sided stencil reject fill %4.1f overdraw @ 60Hz
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "jmp .Lfd9182_000d98ce\n"
        ".Lfd9182_000d9bee:\n"
        "calll RB_TouchAllImages\n" /* line 3959 */
        "jmp .Lfd9182_000d927f\n"
        ".Lfd9182_000d9bf8:\n"
        "movl %edx, (%esp)\n" /* line 4009 */
        "calll RB_DrawDebug\n"
        "jmp .Lfd9182_000d92ec\n"
        ".Lfd9182_000d9c05:\n"
        "movl %esi, -0x34(%ebp)\n"
        ".Lfd9182_000d9c08:\n"
        "cmpb $0, 0x2d68(%esi)\n" /* line 3309 */
        "jne .Lfd9182_000d9cd0\n"
        ".Lfd9182_000d9c15:\n"
        "movl $g_FenceID, 4(%esp)\n" /* line 3202 */
        "movl $1, (%esp)\n"
        "calll glGenFencesAPPLE\n"
        "movl g_FenceID, %eax\n" /* line 3203 */
        "movl %eax, (%esp)\n"
        "calll glSetFenceAPPLE\n"
        "movl imp_dx, %esi\n" /* line 3206 */
        "movb $1, 0x2d68(%esi)\n"
        "jmp .Lfd9182_000d9246\n"
        ".Lfd9182_000d9c48:\n"
        "calll RB_UpdateViewport\n" /* line 3995 */
        "jmp .Lfd9182_000d95a1\n"
        ".Lfd9182_000d9c52:\n"
        "leal -0x28(%ebp), %ebx\n" /* execState */
        ".Lfd9182_000d9c55:\n"
        "movzwl %ax, %eax\n" /* line 3985 */
        "incl g_rb_dispatch_count\n" /* diagnostic */
        /* DIAG: call diag_rb_cmd for every dispatched command */
        "pushl %eax\n"
        "pushl %eax\n"
        "calll diag_rb_cmd\n"
        "addl $4, %esp\n"
        "popl %eax\n"
        "movl %ebx, (%esp)\n"
        "calll *RB_RenderCommandTable(, %eax, 4)\n"
        /* DIAG: print after dispatch returns */
        "cmpl $20, g_rb_dispatch_count\n"
        "jg .Lfd9182_diag_skip_post\n"
        "pushal\n"
        "pushl $rb_diag_post_fmt\n"
        "calll printf\n"
        "addl $4, %esp\n"
        "popal\n"
        ".Lfd9182_diag_skip_post:\n"
        "movl -0x28(%ebp), %eax\n" /* line 3980 | execState */
        "movzwl (%eax), %eax\n"
        "testw %ax, %ax\n"
        "jne .Lfd9182_000d9c55\n"
        "jmp .Lfd9182_000d92b6\n"
        ".Lfd9182_000d9c72:\n"
        "movl $g_FenceID, 4(%esp)\n" /* line 3202 */
        "movl $1, (%esp)\n"
        "calll glGenFencesAPPLE\n"
        "movl g_FenceID, %eax\n" /* line 3203 */
        "movl %eax, (%esp)\n"
        "calll glSetFenceAPPLE\n"
        "movb $1, 0x2d68(%esi)\n" /* line 3206 */
        "jmp .Lfd9182_000d9535\n"
        ".Lfd9182_000d9c9f:\n"
        "movb $0, 0x2d68(%esi)\n" /* line 3319 */
        "jmp .Lfd9182_000d9508\n"
        ".Lfd9182_000d9cab:\n"
        "movb $0, 0x2d68(%esi)\n"
        "jmp .Lfd9182_000d9246\n"
        ".Lfd9182_000d9cb7:\n"
        "movl $g_FenceID, 4(%esp)\n" /* line 3169 */
        "movl $1, (%esp)\n"
        "calll glDeleteFencesAPPLE\n"
        "jmp .Lfd9182_000d9ad5\n"
        ".Lfd9182_000d9cd0:\n"
        "movl g_FenceID, %eax\n" /* line 3155 */
        "movl %eax, (%esp)\n"
        "calll glTestFenceAPPLE\n"
        "testb %al, %al\n" /* line 3165 */
        "setne %bl\n"
        "testb %bl, %bl\n" /* line 3167 */
        "jne .Lfd9182_000d9d17\n"
        ".Lfd9182_000d9ce6:\n"
        "testb %bl, %bl\n" /* line 3317 */
        "je .Lfd9182_000d9d0f\n"
        "movb $0, 0x2d68(%esi)\n" /* line 3319 */
        "jmp .Lfd9182_000d9c15\n"
        ".Lfd9182_000d9cf6:\n"
        "movl $g_FenceID, 4(%esp)\n" /* line 3169 */
        "movl $1, (%esp)\n"
        "calll glDeleteFencesAPPLE\n"
        "jmp .Lfd9182_000d9b2e\n"
        ".Lfd9182_000d9d0f:\n"
        "movl -0x34(%ebp), %esi\n"
        "jmp .Lfd9182_000d9c08\n"
        ".Lfd9182_000d9d17:\n"
        "movl $g_FenceID, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteFencesAPPLE\n"
        "jmp .Lfd9182_000d9ce6\n"
        ".Lfd9182_000d9d2d:\n"
        "movl g_FenceID, %eax\n" /* line 3155 */
        "movl %eax, (%esp)\n"
        "calll glTestFenceAPPLE\n"
        "testb %al, %al\n" /* line 3165 */
        "setne %bl\n"
        "testb %bl, %bl\n" /* line 3167 */
        "jne .Lfd9182_000d9d66\n"
        ".Lfd9182_000d9d43:\n"
        "testb %bl, %bl\n" /* line 3317 */
        "je .Lfd9182_000d9d53\n"
        ".Lfd9182_000d9d47:\n"
        "movb $0, 0x2d68(%esi)\n" /* line 3319 */
        "jmp .Lfd9182_000d9af5\n"
        ".Lfd9182_000d9d53:\n"
        "rdtsc\n" /* line 33 */
        "subl -0x30(%ebp), %eax\n" /* line 3289 */
        "cmpl 0x2d60(%esi), %eax\n"
        "jle .Lfd9182_000d9ae2\n"
        "jmp .Lfd9182_000d9d47\n"
        ".Lfd9182_000d9d66:\n"
        "movl $g_FenceID, 4(%esp)\n" /* line 3169 */
        "movl $1, (%esp)\n"
        "calll glDeleteFencesAPPLE\n"
        "jmp .Lfd9182_000d9d43\n"
    );
}

/* line 466 */
void RB_DrawFullScreenColoredQuad(const Material *material, float s0, float t0, float s1, float t1, D3DCOLOR color)
{
    char *dxState_ptr = (char *)imp_dxState;
    float w = (float)*(int *)(dxState_ptr + 0x209c);
    float h = (float)*(int *)(dxState_ptr + 0x20a0);

    RB_DrawStretchPic(material, 0.0f, 0.0f, w, h, s0, t0, s1, t1, color, 0xa);
}

/* line 748 */
static void RB_DrawFullScreenColoredQuadCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    float w = (float)*(int *)((byte *)imp_dxState + 0x209c);
    float h = (float)*(int *)((byte *)imp_dxState + 0x20a0);

    RB_DrawStretchPic(
        *(const Material **)(cmd + 4),
        0.0f, 0.0f, w, h,
        *(float *)(cmd + 8), *(float *)(cmd + 12),
        *(float *)(cmd + 16), *(float *)(cmd + 20),
        *(D3DCOLOR *)(cmd + 24), 0xa);

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 2074 */
static __attribute__((naked))
void RB_BlendSavedScreenCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2074 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %edi\n" /* execState */
        /* { scope 1 */
        "movl (%edi), %ebx\n" /* line 2082 | execState, cmd */
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfd9e64_000d9eba\n"
        "movl tess+370656, %esi\n"
        "testl %esi, %esi\n"
        "jne .Lfd9e64_000d9eba\n"
        "cmpb $0, backEnd+1213\n" /* line 2088 */
        "je .Lfd9e64_000d9ec8\n"
        ".Lfd9e64_000d9e8e:\n"
        "movl imp_rgp, %esi\n" /* line 2094 | material */
        "movl backEnd+952, %eax\n"
        "subl 0x10e0(%esi), %eax\n" /* line 2095 | material */
        "js .Lfd9e64_000d9ea8\n"
        "movl 4(%ebx), %edx\n" /* cmd */
        "cmpl %edx, %eax\n"
        "jl .Lfd9e64_000d9ecf\n"
        ".Lfd9e64_000d9ea8:\n"
        "movl (%edi), %edx\n" /* line 169 */
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2122 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd9e64_000d9eba:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "cmpb $0, backEnd+1213\n" /* line 2088 */
        "jne .Lfd9e64_000d9e8e\n"
        ".Lfd9e64_000d9ec8:\n"
        "calll RB_Set2D\n" /* line 2090 */
        "jmp .Lfd9e64_000d9e8e\n"
        ".Lfd9e64_000d9ecf:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 2097 */
        "cvtsi2ssl %edx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, 8(%esp)\n"
        "movl $0x40000000, (%esp)\n"
        "movl $0x3f847ae1, 4(%esp)\n"
        "calll pow\n"
        "fstpl -0x38(%ebp)\n"
        "cvtsd2ss -0x38(%ebp), %xmm0\n"
        "ucomiss lit4_002ed858, %xmm0\n" /* line 2098 | 0.9900000095367432f */
        "jbe .Lfd9e64_000da034\n"
        "movss lit4_002ed85c, %xmm0\n" /* 252.4499969482422f */
        ".Lfd9e64_000d9f16:\n"
        "addss lit4_002ed5d8, %xmm0\n" /* line 428 | 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x3c(%ebp)\n"
        "cvttss2si -0x3c(%ebp), %eax\n"
        "movb %al, -0x1c(%ebp)\n" /* color */
        "movb $0xff, -0x1b(%ebp)\n" /* line 2110 */
        "movb $0xff, -0x1a(%ebp)\n" /* line 2111 */
        "movb $0xff, -0x19(%ebp)\n" /* line 2112 */
        "movl imp_dx, %eax\n" /* line 360 */
        "movl 0x2cbc(%eax), %eax\n"
        "movl %eax, backEnd+11916\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2118 | color */
        "movl %eax, -0x2c(%ebp)\n" /* color */
        "movl 0x10d0(%esi), %esi\n" /* material */
        /* { scope 2: color */
        "movl imp_dxState, %eax\n" /* line 491 */
        "movl 0x209c(%eax), %edx\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "movl 0x20a0(%eax), %ebx\n" /* line 492 */
        "cvtsi2ssl %ebx, %xmm2\n"
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lfd9e64_000da012\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        ".Lfd9e64_000d9f85:\n"
        "movaps %xmm3, %xmm1\n" /* line 494 */
        "divss %xmm0, %xmm1\n"
        /* { scope 3 */
        "cmpl $1, %ebx\n" /* line 144 */
        "ja .Lfd9e64_000d9ff3\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        /* { scope 3 */
        ".Lfd9e64_000d9f99:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 473 */
        "movl -0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 0x24(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movss %xmm1, 0x1c(%esp)\n"
        "movaps %xmm2, %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss %xmm3, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        /* } scope */
        /* } scope */
        "movl (%edi), %edx\n" /* line 169 */
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%edi)\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 2122 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: color */
        /* { scope 3 */
        ".Lfd9e64_000d9ff3:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lfd9e64_000d9ffd:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ebx\n"
        "jbe .Lfd9e64_000da054\n"
        "subl $1, %eax\n"
        "jne .Lfd9e64_000d9ffd\n"
        "testl %edx, %edx\n"
        "js .Lfd9e64_000da067\n"
        ".Lfd9e64_000da00c:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "jmp .Lfd9e64_000d9f99\n"
        /* } scope */
        /* { scope 3 */
        ".Lfd9e64_000da012:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lfd9e64_000da01c:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lfd9e64_000da041\n"
        "subl $1, %eax\n"
        "jne .Lfd9e64_000da01c\n"
        "testl %ecx, %ecx\n"
        "js .Lfd9e64_000da07d\n"
        ".Lfd9e64_000da02b:\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "jmp .Lfd9e64_000d9f85\n"
        /* } scope */
        /* } scope */
        ".Lfd9e64_000da034:\n"
        "mulss lit4_002ed5d4, %xmm0\n" /* line 2098 | 255.0f */
        "jmp .Lfd9e64_000d9f16\n"
        /* { scope 2: color */
        /* { scope 3 */
        ".Lfd9e64_000da041:\n"
        "testl %ecx, %ecx\n" /* line 144 */
        "jns .Lfd9e64_000da02b\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfd9e64_000d9f85\n"
        /* } scope */
        /* { scope 3 */
        ".Lfd9e64_000da054:\n"
        "testl %edx, %edx\n"
        "jns .Lfd9e64_000da00c\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfd9e64_000d9f99\n"
        ".Lfd9e64_000da067:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfd9e64_000d9f99\n"
        /* } scope */
        /* { scope 3 */
        ".Lfd9e64_000da07d:\n"
        "movl %ecx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfd9e64_000d9f85\n"
    );
}

/* line 1868 */
static __attribute__((naked))
void RB_BlurShadowCookieCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1868 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: screenWidth, screenHeight, screenWidth, screenHeight */
        "movl tess+370640, %ecx\n" /* line 261 */
        "testl %ecx, %ecx\n"
        "jne .Lfda094_000da0d7\n"
        "movl tess+370656, %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfda094_000da0d7\n"
        "movl imp_sc_blur, %eax\n" /* line 1880 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lfda094_000da0ea\n"
        ".Lfda094_000da0bf:\n"
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 1887 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: screenWidth, screenHeight, screenWidth, screenHeight */
        ".Lfda094_000da0d7:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "movl imp_sc_blur, %eax\n" /* line 1880 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfda094_000da0bf\n"
        ".Lfda094_000da0ea:\n"
        "movl $0, -0x2c(%ebp)\n" /* blurIter */
        "movl imp_dxState, %edi\n"
        "movl imp_alwaysfails, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl imp_dx, %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl %edi, -0x38(%ebp)\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl %edx, %eax\n"
        /* { scope 2: image */
        ".Lfda094_000da113:\n"
        "cvtsi2ssl 0x209c(%edi), %xmm0\n" /* line 1850 */
        "movss %xmm0, -0x28(%ebp)\n" /* screenWidth */
        "cvtsi2ssl 0x20a0(%edi), %xmm0\n" /* line 1851 */
        "movss %xmm0, -0x24(%ebp)\n" /* screenHeight */
        "movl 0x2c94(%eax), %esi\n" /* line 1854 */
        /* { scope 3 */
        "movl %esi, (%esp)\n" /* line 563 */
        "calll Image_GetSurface\n"
        "movl %eax, %ebx\n" /* imageSurface */
        ".Lfda094_000da13d:\n"
        "movl imp_dx, %edx\n" /* line 566 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl $2, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* imageSurface */
        "movl $0, 8(%esp)\n"
        "movl 0x20a8(%edi), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x88(%ecx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfda094_000da13d\n"
        ".Lfda094_000da180:\n"
        "movl (%ebx), %eax\n" /* line 568 | imageSurface */
        "movl %ebx, (%esp)\n" /* imageSurface */
        "calll *8(%eax)\n"
        "movl imp_alwaysfails, %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfda094_000da180\n"
        /* } scope */
        /* { scope 3 */
        "movl %esi, backEnd+11916\n" /* line 360 */
        /* } scope */
        "movl $0xa, 0x28(%esp)\n" /* line 1863 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f7f0000, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0x3c400000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0x24(%ebp), %xmm0\n" /* screenHeight */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n" /* screenWidth */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl imp_rgp, %edx\n"
        "movl 0x1054(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1864 */
        /* } scope */
        /* { scope 2: image */
        "cvtsi2ssl 0x209c(%edi), %xmm0\n" /* line 1850 */
        "movss %xmm0, -0x20(%ebp)\n" /* screenWidth */
        "cvtsi2ssl 0x20a0(%edi), %xmm0\n" /* line 1851 */
        "movss %xmm0, -0x1c(%ebp)\n" /* screenHeight */
        "movl imp_dx, %eax\n" /* line 1854 */
        "movl 0x2c94(%eax), %eax\n"
        "movl %eax, -0x4c(%ebp)\n" /* image */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 563 */
        "calll Image_GetSurface\n"
        "movl %eax, %ebx\n" /* imageSurface */
        ".Lfda094_000da245:\n"
        "movl -0x34(%ebp), %edx\n" /* line 566 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %ecx\n"
        "movl $2, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* imageSurface */
        "movl $0, 8(%esp)\n"
        "movl -0x38(%ebp), %esi\n"
        "movl 0x20a8(%esi), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x88(%ecx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfda094_000da245\n"
        ".Lfda094_000da288:\n"
        "movl (%ebx), %eax\n" /* line 568 | imageSurface */
        "movl %ebx, (%esp)\n" /* imageSurface */
        "calll *8(%eax)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfda094_000da288\n"
        /* } scope */
        /* { scope 3 */
        "movl -0x4c(%ebp), %esi\n" /* line 360 | image */
        "movl %esi, backEnd+11916\n"
        /* } scope */
        "movl $0xa, 0x28(%esp)\n" /* line 1863 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f7d0000, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0x3b800000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* screenHeight */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* screenWidth */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl imp_rgp, %edx\n"
        "movl 0x1054(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1864 */
        /* } scope */
        "addl $1, -0x2c(%ebp)\n" /* line 1880 | blurIter */
        "movl imp_sc_blur, %eax\n"
        "movl (%eax), %eax\n"
        "movl -0x2c(%ebp), %esi\n" /* blurIter, image */
        "cmpl 8(%eax), %esi\n" /* image */
        "jge .Lfda094_000da0bf\n"
        "movl imp_dx, %eax\n"
        "jmp .Lfda094_000da113\n"
    );
}

/* line 2904 */
static __attribute__((naked))
void RB_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float xScale, float yScale, const GfxColor color, int style, int cursorPos, int cursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2904 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xdc, %esp\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl %ecx, -0x64(%ebp)\n"
        "movss %xmm2, -0x68(%ebp)\n"
        "movss %xmm3, -0x6c(%ebp)\n"
        "movzbl 0x14(%ebp), %edx\n" /* cursor */
        "movb %dl, -0x6d(%ebp)\n" /* cursor */
        /* { scope 1 */
        "movl 8(%ebp), %edi\n" /* line 2921 | color, newColor */
        "movl %edi, %ecx\n" /* line 2935 | newColor */
        "movzbl %cl, %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n" /* newBlack */
        "movl -0x64(%ebp), %edx\n" /* line 207 */
        "movl 0xc(%edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n" /* material */
        "movss lit4_002ed63c, %xmm2\n" /* line 2948 | -0.5f */
        "movss -0x68(%ebp), %xmm3\n"
        "mulss %xmm2, %xmm3\n"
        "addss %xmm3, %xmm0\n" /* x */
        "movss %xmm0, -0x34(%ebp)\n" /* x */
        "movss -0x6c(%ebp), %xmm4\n" /* line 2949 */
        "mulss %xmm2, %xmm4\n"
        "addss %xmm4, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "movl %edi, %ecx\n" /* line 2972 | newColor */
        "movb %cl, -0x55(%ebp)\n"
        "movss %xmm0, -0x30(%ebp)\n" /* x */
        "pxor %xmm0, %xmm0\n" /* x */
        "movss %xmm0, -0x50(%ebp)\n" /* x, xAdj */
        "movl $0, -0x54(%ebp)\n" /* count */
        ".Lfda33c_000da3bc:\n"
        "cmpb $0, (%eax)\n" /* line 2954 */
        "je .Lfda33c_000da58f\n"
        ".Lfda33c_000da3c5:\n"
        "movl -0x60(%ebp), %ebx\n" /* glyph */
        "testl %ebx, %ebx\n" /* glyph */
        "je .Lfda33c_000da58f\n"
        "movl $0, 4(%esp)\n" /* line 2956 */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "movl imp_ri, %edx\n"
        "calll *0x118(%edx)\n"
        "cmpl $0x5e, %eax\n" /* line 2959 */
        "je .Lfda33c_000da5a6\n"
        "cmpl $0xa, %eax\n" /* line 2990 */
        "je .Lfda33c_000da642\n"
        "cmpl $0xd, %eax\n" /* line 2996 */
        "je .Lfda33c_000da7a9\n"
        ".Lfda33c_000da405:\n"
        "movl %eax, 4(%esp)\n" /* line 3002 */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_GetCharacterGlyph\n"
        "movl %eax, %esi\n" /* glyph */
        "movsbl 2(%eax), %eax\n" /* line 3003 */
        "cvtsi2ssl %eax, %xmm0\n" /* x */
        "movss -0x68(%ebp), %xmm2\n"
        "mulss %xmm0, %xmm2\n" /* x */
        "movss %xmm2, -0x50(%ebp)\n" /* xAdj */
        "movsbl 3(%esi), %eax\n" /* line 3004 | glyph */
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss -0x6c(%ebp), %xmm1\n"
        "cmpl $3, 0xc(%ebp)\n" /* line 3006 | style */
        "je .Lfda33c_000da8f7\n"
        "cmpl $6, 0xc(%ebp)\n" /* style */
        "je .Lfda33c_000da66b\n"
        "addss -0x38(%ebp), %xmm1\n"
        "movss %xmm1, -0x40(%ebp)\n"
        "movss -0x30(%ebp), %xmm3\n"
        "addss -0x50(%ebp), %xmm3\n" /* xAdj */
        "movss %xmm3, -0x3c(%ebp)\n"
        "movaps %xmm1, %xmm2\n"
        ".Lfda33c_000da469:\n"
        "movzbl 6(%esi), %eax\n" /* line 3011 | glyph */
        "cvtsi2ssl %eax, %xmm1\n" /* h */
        "mulss -0x6c(%ebp), %xmm1\n" /* h */
        "movzbl 5(%esi), %eax\n" /* glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* w */
        "mulss -0x68(%ebp), %xmm0\n" /* w */
        /* { scope 2: x */
        "movl $8, 0x28(%esp)\n" /* line 2868 */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm2, 8(%esp)\n"
        "movss %xmm3, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "calll RB_DrawStretchPic\n"
        "movss lit4_002ed604, %xmm2\n" /* line 2870 | 0.25f */
        "addss -0x3c(%ebp), %xmm2\n"
        "movss %xmm2, -0x48(%ebp)\n"
        "movl $8, 0x28(%esp)\n"
        "movl %edi, 0x24(%esp)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0x98(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss lit4_002ed604, %xmm3\n" /* 0.25f */
        "addss -0x40(%ebp), %xmm3\n"
        "movss %xmm3, 8(%esp)\n"
        "movss %xmm2, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        /* } scope */
        "movl -0x54(%ebp), %edx\n" /* line 3013 | count */
        "cmpl %edx, 0x10(%ebp)\n" /* cursorPos */
        "je .Lfda33c_000da7bb\n"
        ".Lfda33c_000da564:\n"
        "movzbl 4(%esi), %eax\n" /* line 3016 | glyph */
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x68(%ebp), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "addl $1, -0x54(%ebp)\n" /* line 3017 | count */
        "subl $1, -0x60(%ebp)\n" /* line 3018 */
        "movl -0x2c(%ebp), %eax\n"
        "cmpb $0, (%eax)\n" /* line 2954 */
        "jne .Lfda33c_000da3c5\n"
        ".Lfda33c_000da58f:\n"
        "movl -0x54(%ebp), %edx\n" /* line 3021 | count */
        "cmpl %edx, 0x10(%ebp)\n" /* cursorPos */
        "je .Lfda33c_000da904\n"
        /* } scope */
        ".Lfda33c_000da59b:\n"
        "addl $0xdc, %esp\n" /* line 3023 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfda33c_000da5a6:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 2959 */
        "testl %edx, %edx\n"
        "je .Lfda33c_000da405\n"
        "movzbl (%edx), %edx\n"
        "cmpb $0x5e, %dl\n"
        "je .Lfda33c_000da405\n"
        "cmpb $0x2f, %dl\n"
        "jle .Lfda33c_000da405\n"
        "cmpb $0x39, %dl\n"
        "jg .Lfda33c_000da405\n"
        "movzbl %dl, %eax\n" /* line 2961 */
        "movl %eax, (%esp)\n"
        "calll ColorIndex\n"
        "movl %eax, %ebx\n" /* glyph */
        "movl $0x37, (%esp)\n"
        "calll ColorIndex\n"
        "cmpb %al, %bl\n" /* glyph */
        "je .Lfda33c_000daa5b\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2967 | rgbColor */
        "movl %eax, 4(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movzbl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_LookupColor\n"
        "movl %edi, %ecx\n" /* line 2972 | newColor */
        "movb -0x55(%ebp), %cl\n"
        "movzbl -0x1c(%ebp), %eax\n" /* line 2973 | rgbColor */
        "movb %al, %ch\n"
        "movl %ecx, %edi\n" /* newColor */
        "movzbl -0x1b(%ebp), %eax\n" /* line 2974 */
        "shll $0x10, %eax\n"
        "andl $0xff00ffff, %edi\n" /* newColor */
        "orl %eax, %edi\n" /* newColor */
        "movzbl -0x1a(%ebp), %eax\n" /* line 2975 */
        "shll $0x18, %eax\n"
        "andl $0x00FFFFFF, %edi\n" /* newColor */
        "orl %eax, %edi\n" /* newColor */
        ".Lfda33c_000da630:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2986 */
        "addl $1, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "addl $2, -0x54(%ebp)\n" /* line 2987 | count */
        "jmp .Lfda33c_000da3bc\n"
        ".Lfda33c_000da642:\n"
        "movl -0x64(%ebp), %eax\n" /* line 2993 */
        "cvtsi2ssl 4(%eax), %xmm0\n" /* x */
        "mulss -0x6c(%ebp), %xmm0\n" /* x */
        "addss -0x38(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x38(%ebp)\n" /* x */
        "movss -0x34(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x30(%ebp)\n" /* x */
        "movl -0x2c(%ebp), %eax\n"
        "jmp .Lfda33c_000da3bc\n"
        ".Lfda33c_000da66b:\n"
        "movss lit4_002ed62c, %xmm2\n" /* line 3006 | 2.0f */
        ".Lfda33c_000da673:\n"
        "movzbl 6(%esi), %eax\n" /* line 3009 | glyph */
        "cvtsi2ssl %eax, %xmm3\n" /* h */
        "mulss -0x6c(%ebp), %xmm3\n" /* h */
        "movzbl 5(%esi), %eax\n" /* glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* w */
        "mulss -0x68(%ebp), %xmm0\n" /* w */
        "addss -0x38(%ebp), %xmm1\n" /* y */
        "movss %xmm1, -0x40(%ebp)\n" /* y */
        "addss %xmm2, %xmm1\n" /* x, y */
        "movss -0x30(%ebp), %xmm4\n"
        "addss -0x50(%ebp), %xmm4\n" /* xAdj */
        "movss %xmm4, -0x3c(%ebp)\n"
        "addss %xmm4, %xmm2\n" /* x */
        /* { scope 2: x */
        "movl $8, 0x28(%esp)\n" /* line 2868 */
        "movl -0x5c(%ebp), %eax\n" /* newBlack */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm3, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm2, 4(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* material */
        "movl %edx, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "movss %xmm3, -0xb8(%ebp)\n"
        "calll RB_DrawStretchPic\n"
        "movl $8, 0x28(%esp)\n" /* line 2870 */
        "movl -0x5c(%ebp), %ecx\n" /* newBlack */
        "movl %ecx, 0x24(%esp)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0xb8(%ebp), %xmm3\n"
        "movss %xmm3, 0x10(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss -0x98(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "addss %xmm0, %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "movss -0x40(%ebp), %xmm2\n"
        "movss -0x3c(%ebp), %xmm3\n"
        "jmp .Lfda33c_000da469\n"
        /* } scope */
        ".Lfda33c_000da7a9:\n"
        "movss -0x34(%ebp), %xmm2\n" /* line 2996 */
        "movss %xmm2, -0x30(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "jmp .Lfda33c_000da3bc\n"
        ".Lfda33c_000da7bb:\n"
        "movl imp_ri, %ecx\n" /* line 2880 */
        "calll *8(%ecx)\n"
        "leal 0xff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "testb $1, %ah\n"
        "jne .Lfda33c_000da564\n"
        "movzbl -0x6d(%ebp), %eax\n" /* line 2883 | cursor */
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_GetCharacterGlyph\n"
        "movl %eax, %ebx\n"
        "movzbl 6(%eax), %eax\n" /* line 2884 */
        "cvtsi2ssl %eax, %xmm2\n" /* h */
        "mulss -0x6c(%ebp), %xmm2\n" /* h */
        "movzbl 5(%ebx), %eax\n" /* glyph */
        "cvtsi2ssl %eax, %xmm1\n" /* y */
        "mulss -0x68(%ebp), %xmm1\n" /* y */
        "movsbl 3(%ebx), %eax\n" /* glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* y */
        "mulss -0x6c(%ebp), %xmm0\n" /* y */
        "addss -0x38(%ebp), %xmm0\n" /* y */
        /* { scope 2: x */
        "movl $8, 0x28(%esp)\n" /* line 2868 */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x3c(%ebp), %xmm3\n"
        "movss %xmm3, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "calll RB_DrawStretchPic\n"
        "movl $8, 0x28(%esp)\n" /* line 2870 */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss -0x98(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "addss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "jmp .Lfda33c_000da564\n"
        /* } scope */
        ".Lfda33c_000da8f7:\n"
        "movss lit4_002ed5d0, %xmm2\n" /* line 3006 | 1.0f */
        "jmp .Lfda33c_000da673\n"
        ".Lfda33c_000da904:\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 3022 */
        "addss -0x50(%ebp), %xmm0\n" /* xAdj */
        "movss %xmm0, -0x44(%ebp)\n" /* x */
        "movzbl -0x6d(%ebp), %ebx\n" /* cursor */
        /* { scope 2: x */
        "movl imp_ri, %eax\n" /* line 2880 */
        "calll *8(%eax)\n"
        "leal 0xff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "testb $1, %ah\n"
        "jne .Lfda33c_000da59b\n"
        "movzbl %bl, %eax\n" /* line 2883 */
        "movl %eax, 4(%esp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_GetCharacterGlyph\n"
        "movl %eax, %ebx\n"
        "movzbl 6(%eax), %eax\n" /* line 2884 */
        "cvtsi2ssl %eax, %xmm2\n" /* h */
        "mulss -0x6c(%ebp), %xmm2\n" /* h */
        "movzbl 5(%ebx), %eax\n" /* glyph */
        "cvtsi2ssl %eax, %xmm0\n" /* y */
        "mulss -0x68(%ebp), %xmm0\n" /* y */
        "movsbl 3(%ebx), %eax\n" /* glyph */
        "cvtsi2ssl %eax, %xmm1\n" /* y */
        "mulss -0x6c(%ebp), %xmm1\n" /* y */
        "addss -0x38(%ebp), %xmm1\n" /* y */
        /* { scope 3 */
        "movl $8, 0x28(%esp)\n" /* line 2868 */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss -0x44(%ebp), %xmm3\n" /* x */
        "movss %xmm3, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x88(%ebp)\n"
        "movss %xmm1, -0x98(%ebp)\n"
        "movss %xmm2, -0xa8(%ebp)\n"
        "calll RB_DrawStretchPic\n"
        "movl $8, 0x28(%esp)\n" /* line 2870 */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss lit4_002ed604, %xmm0\n" /* 0.25f */
        "movss -0x98(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "addss -0x44(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 4(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* material */
        "movl %edx, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "addl $0xdc, %esp\n" /* line 3023 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfda33c_000daa5b:\n"
        "movl 8(%ebp), %edi\n" /* line 2963 | color, newColor */
        "jmp .Lfda33c_000da630\n"
    );
}

/* line 3101 */
static __attribute__((naked))
void RB_DrawTextCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3101 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 3105 | execState */
        "movl (%edx), %eax\n"
        "movsbl 0x24(%eax), %esi\n" /* line 3107 */
        "movl 0x20(%eax), %edi\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x18(%eax), %ebx\n"
        "movss 0x14(%eax), %xmm3\n"
        "movss 0x10(%eax), %xmm2\n"
        "movss 8(%eax), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        "movl 0xc(%eax), %ecx\n"
        "movl 0x28(%eax), %edx\n"
        "addl $0x2c, %eax\n"
        "movl %esi, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl -0x1c(%ebp), %esi\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_DrawTextWithCursor\n"
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3110 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2004 */
static __attribute__((naked))
void RB_ApplyLatePostEffectsCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2004 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        /* { scope 1: blurRadius */
        "movl 8(%ebp), %eax\n" /* line 2011 | execState */
        "movl (%eax), %ebx\n" /* cmd */
        "movl tess+370640, %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfdaace_000dadb3\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdaace_000dadb3\n"
        ".Lfdaace_000daafa:\n"
        "movl imp_dxState, %eax\n" /* line 2014 */
        "movl 0x2098(%eax), %eax\n"
        "movl %eax, -0x6c(%ebp)\n" /* frameBufferTarget */
        "movl $0xe, backEnd+11912\n" /* line 2016 */
        "movss 4(%ebx), %xmm0\n" /* line 2022 | cmd */
        "movss %xmm0, -0x68(%ebp)\n" /* blurRadius */
        "movl imp_r_rendererInUse, %eax\n" /* line 1795 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "cmpl $2, %edx\n"
        "je .Lfdaace_000dab3d\n"
        "movl imp_dx, %eax\n" /* line 1798 */
        "cmpb $0, 0x2d7d(%eax)\n"
        "jne .Lfdaace_000dadbd\n"
        ".Lfdaace_000dab3d:\n"
        "movl imp_r_showFbColorDebug, %eax\n" /* line 1921 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdaace_000dab6c\n"
        /* { scope 2 */
        "cmpl $2, %edx\n" /* line 1780 */
        "je .Lfdaace_000dad53\n"
        "movl imp_r_blur, %eax\n" /* line 1784 */
        "movl (%eax), %eax\n"
        "pxor %xmm1, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfdaace_000db241\n"
        /* } scope */
        /* { scope 2 */
        ".Lfdaace_000dab6c:\n"
        "movl imp_dx, %ebx\n" /* line 563 */
        "movl 0x2c58(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_GetSurface\n"
        "movl %eax, %esi\n" /* imageSurface */
        "movl %ebx, -0xbc(%ebp)\n"
        "movl imp_alwaysfails, %edi\n" /* material */
        "movl %ebx, %edx\n"
        "jmp .Lfdaace_000dab98\n"
        ".Lfdaace_000dab92:\n"
        "movl -0xbc(%ebp), %edx\n"
        ".Lfdaace_000dab98:\n"
        "movl 8(%edx), %eax\n" /* line 566 */
        "movl (%eax), %ecx\n"
        "movl $2, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* imageSurface */
        "movl $0, 8(%esp)\n"
        "movl imp_dxState, %ebx\n"
        "movl 0x20a8(%ebx), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x88(%ecx)\n"
        "movl (%edi), %eax\n" /* material */
        "testl %eax, %eax\n"
        "jne .Lfdaace_000dab92\n"
        "movl imp_alwaysfails, %ebx\n"
        ".Lfdaace_000dabde:\n"
        "movl (%esi), %eax\n" /* line 568 | imageSurface */
        "movl %esi, (%esp)\n" /* imageSurface */
        "calll *8(%eax)\n"
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdaace_000dabde\n"
        /* } scope */
        "movl $2, backEnd+11912\n" /* line 1946 */
        "movl imp_r_rendererInUse, %edx\n" /* line 1795 */
        "movl (%edx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdaace_000dac18\n"
        "movl imp_dx, %eax\n" /* line 1798 */
        "cmpb $0, 0x2d7d(%eax)\n"
        "jne .Lfdaace_000daddd\n"
        ".Lfdaace_000dac16:\n"
        "movl (%edx), %eax\n"
        ".Lfdaace_000dac18:\n"
        "cmpl $2, 8(%eax)\n" /* line 1780 */
        "je .Lfdaace_000dad53\n"
        "movl imp_r_blur, %eax\n" /* line 1784 */
        "movl (%eax), %eax\n"
        "pxor %xmm1, %xmm1\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfdaace_000db22b\n"
        "movss -0x68(%ebp), %xmm1\n" /* blurRadius */
        ".Lfdaace_000dac40:\n"
        "movl imp_r_blur, %eax\n" /* line 1896 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "mulss %xmm0, %xmm0\n" /* line 1899 */
        "mulss %xmm1, %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "sqrtss %xmm0, %xmm0\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl $0x40400000, (%esp)\n" /* line 1727 */
        "movss %xmm0, -0x98(%ebp)\n"
        "calll GetVirtualWidthFromRealWidth\n"
        "fstps -0x2c(%ebp)\n"
        "movl $0xffffffff, %esi\n" /* line 1728 | color */
        "movss -0x98(%ebp), %xmm0\n" /* line 1729 */
        "movss -0x2c(%ebp), %xmm2\n"
        "ucomiss %xmm0, %xmm2\n"
        "ja .Lfdaace_000db2a8\n"
        ".Lfdaace_000dac8e:\n"
        "movl $8, 4(%esp)\n" /* line 1741 */
        "movss %xmm0, (%esp)\n"
        "calll RB_GaussianFilterImage\n"
        "movl $0, (%esp)\n" /* line 1742 */
        "calll RB_SetRenderTarget\n"
        "movl imp_dx, %eax\n" /* line 360 */
        "movl 0x2cd0(%eax), %eax\n"
        "movl %eax, backEnd+11916\n"
        "movl imp_rgp, %eax\n" /* line 1744 */
        "movl 0x10ac(%eax), %edi\n" /* material */
        /* { scope 4 */
        "movl imp_dxState, %eax\n" /* line 491 */
        "movl 0x209c(%eax), %edx\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "movl 0x20a0(%eax), %ebx\n" /* line 492 */
        "cvtsi2ssl %ebx, %xmm2\n"
        /* { scope 5 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lfdaace_000db1cb\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        ".Lfdaace_000dacf1:\n"
        "movaps %xmm3, %xmm1\n" /* line 494 */
        "divss %xmm0, %xmm1\n"
        /* { scope 5 */
        "cmpl $1, %ebx\n" /* line 144 */
        "ja .Lfdaace_000db1a1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        /* } scope */
        /* { scope 5 */
        ".Lfdaace_000dad09:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 473 */
        "movl %esi, 0x24(%esp)\n"
        "movaps %xmm2, %xmm4\n"
        "divss %xmm0, %xmm4\n"
        "movss %xmm4, 0x20(%esp)\n"
        "movss %xmm1, 0x1c(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss %xmm3, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        /* } scope */
        /* } scope */
        "calll RB_EndSurface\n" /* line 1745 */
        /* } scope */
        /* } scope */
        ".Lfdaace_000dad53:\n"
        "movl -0x6c(%ebp), %eax\n" /* line 2026 | frameBufferTarget */
        "movl %eax, (%esp)\n"
        "calll RB_SetRenderTarget\n"
        "movl imp_r_showFbColorDebug, %eax\n" /* line 1811 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "cmpl $1, %edx\n"
        "je .Lfdaace_000db2de\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 1818 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdaace_000dad98\n"
        "cmpl $2, %edx\n" /* line 1822 */
        "je .Lfdaace_000db52d\n"
        "movl imp_sc_showDebug, %eax\n" /* line 1836 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfdaace_000db052\n"
        ".Lfdaace_000dad98:\n"
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 2033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: blurRadius */
        ".Lfdaace_000dadb3:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdaace_000daafa\n"
        ".Lfdaace_000dadbd:\n"
        "movl imp_r_glow, %eax\n" /* line 1801 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfdaace_000db1f5\n"
        ".Lfdaace_000dadce:\n"
        "xorl %eax, %eax\n"
        ".Lfdaace_000dadd0:\n"
        "testl %eax, %eax\n" /* line 1909 */
        "jne .Lfdaace_000dab6c\n"
        "jmp .Lfdaace_000dab3d\n"
        ".Lfdaace_000daddd:\n"
        "movl imp_r_glow, %eax\n" /* line 1801 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfdaace_000db210\n"
        ".Lfdaace_000dadee:\n"
        "xorl %eax, %eax\n"
        ".Lfdaace_000dadf0:\n"
        "testl %eax, %eax\n" /* line 1966 */
        "je .Lfdaace_000dac16\n"
        "movl imp_r_glowBloomCutoff, %eax\n" /* line 1709 */
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n"
        "movl imp_r_glowBloomDesaturation, %eax\n" /* line 1711 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movss %xmm1, backEnd+512\n" /* line 447 */
        "movss lit4_002ed5d0, %xmm0\n" /* line 448 | 1.0f */
        "movaps %xmm0, %xmm2\n"
        "subss %xmm1, %xmm2\n"
        "divss %xmm2, %xmm0\n"
        "movss %xmm0, backEnd+516\n"
        "pxor %xmm2, %xmm2\n" /* line 449 */
        "movss %xmm2, backEnd+520\n"
        "movl %eax, backEnd+524\n" /* line 450 */
        "xorl %edx, %edx\n"
        "leal -0x20(%ebp), %edi\n"
        "movl imp_r_glowBloomIntensity, %esi\n"
        "movl imp_r_glowSkyBleedIntensity, %eax\n"
        "movl %eax, -0x78(%ebp)\n"
        "movl imp_r_glowRadius, %ebx\n"
        ".Lfdaace_000dae5b:\n"
        "leal (%edx, %edi), %ecx\n" /* line 2004 */
        "movl $0, (%ecx)\n" /* line 1681 */
        "movl (%edx, %esi), %eax\n" /* line 1682 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lfdaace_000db87f\n"
        ".Lfdaace_000dae75:\n"
        "movl (%edx, %ebx), %eax\n" /* line 1683 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%ecx)\n"
        ".Lfdaace_000dae7d:\n"
        "addl $4, %edx\n"
        "cmpl $8, %edx\n" /* line 1679 */
        "jne .Lfdaace_000dae5b\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1686 */
        "ucomiss %xmm2, %xmm0\n"
        "jp .Lfdaace_000dae95\n"
        "je .Lfdaace_000db84a\n"
        ".Lfdaace_000dae95:\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 1689 */
        "ucomiss %xmm2, %xmm1\n"
        "jp .Lfdaace_000db841\n"
        "jne .Lfdaace_000db841\n"
        ".Lfdaace_000daea9:\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 1692 */
        "movss %xmm1, -0x1c(%ebp)\n" /* line 1693 */
        "movl $1, %eax\n"
        ".Lfdaace_000daeb8:\n"
        "movl %eax, backEnd+1228\n" /* line 1715 */
        "movl imp_g_TotalFilterPasses, %eax\n" /* line 1716 */
        "movl $0, (%eax)\n"
        "movl %edi, (%esp)\n" /* line 1717 | material */
        "calll RB_GlowFilterImage\n"
        "movl $0, (%esp)\n" /* line 1969 */
        "calll RB_SetRenderTarget\n"
        "movl backEnd+1228, %esi\n" /* line 1659 | imageSurface */
        "movl backEnd+1232, %eax\n" /* line 1660 */
        "testl %eax, %eax\n"
        "jle .Lfdaace_000db4dc\n"
        "movl $0, -0x64(%ebp)\n"
        "movl $backEnd, %edi\n" /* material */
        "jmp .Lfdaace_000daff6\n"
        ".Lfdaace_000daf00:\n"
        "movl imp_rgp, %ecx\n" /* line 1637 */
        "movl 0x10d8(%ecx), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n"
        ".Lfdaace_000daf0f:\n"
        "movss %xmm0, backEnd+528\n" /* line 447 */
        "movl $0, backEnd+532\n" /* line 448 */
        "movl $0, backEnd+536\n" /* line 449 */
        "movl %eax, backEnd+540\n" /* line 450 */
        "movl %edx, backEnd+11916\n" /* line 360 */
        "movl imp_dxState, %eax\n" /* line 491 */
        "movl 0x209c(%eax), %edx\n"
        "cvtsi2ssl %edx, %xmm3\n"
        "movl 0x20a0(%eax), %ebx\n" /* line 492 */
        "cvtsi2ssl %ebx, %xmm2\n"
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lfdaace_000db27e\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        ".Lfdaace_000daf60:\n"
        "movaps %xmm3, %xmm1\n" /* line 494 */
        "divss %xmm0, %xmm1\n"
        "cmpl $1, %ebx\n" /* line 144 */
        "ja .Lfdaace_000db254\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        ".Lfdaace_000daf78:\n"
        "movl $0xa, 0x28(%esp)\n" /* line 473 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movaps %xmm2, %xmm4\n"
        "divss %xmm0, %xmm4\n"
        "movss %xmm4, 0x20(%esp)\n"
        "movss %xmm1, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss %xmm2, 0x10(%esp)\n"
        "movss %xmm3, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1645 */
        "movl $1, %eax\n" /* line 1666 */
        "subl %esi, %eax\n" /* imageSurface */
        "movl %eax, %esi\n" /* imageSurface */
        "addl $1, -0x64(%ebp)\n" /* line 1660 */
        "addl $4, %edi\n" /* material */
        "movl -0x64(%ebp), %edx\n"
        "cmpl backEnd+1232, %edx\n"
        "jge .Lfdaace_000db4dc\n"
        ".Lfdaace_000daff6:\n"
        "movl 0x4d4(%edi), %edx\n" /* line 1662 | material */
        "movl imp_rgp, %ecx\n" /* line 1632 */
        "movl 0x109c(%ecx), %eax\n"
        "movl 0x20(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfdaace_000db4f3\n"
        "movl imp_r_glowSkyBleedIntensity, %eax\n"
        "movl (%eax, %esi, 4), %eax\n"
        "movss 8(%eax), %xmm0\n"
        "pxor %xmm2, %xmm2\n"
        ".Lfdaace_000db024:\n"
        "movl imp_r_glowBloomIntensity, %eax\n" /* line 1633 */
        "movl (%eax, %esi, 4), %eax\n"
        "movl 8(%eax), %eax\n"
        "ucomiss %xmm2, %xmm0\n" /* line 1634 */
        "jne .Lfdaace_000daf00\n"
        "jp .Lfdaace_000daf00\n"
        "movl imp_rgp, %ebx\n" /* line 1635 */
        "movl 0x10dc(%ebx), %ebx\n"
        "movl %ebx, -0x60(%ebp)\n"
        "jmp .Lfdaace_000daf0f\n"
        ".Lfdaace_000db052:\n"
        "movl imp_dxState, %eax\n" /* line 1596 */
        "cvtsi2ssl 0x209c(%eax), %xmm1\n"
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "mulss %xmm2, %xmm1\n"
        "cvtsi2ssl 0x20a0(%eax), %xmm0\n" /* line 1597 */
        "mulss %xmm2, %xmm0\n"
        "movl backEnd+432, %ebx\n" /* line 456 */
        "movl backEnd+436, %esi\n" /* line 457 */
        "movl backEnd+440, %edi\n" /* line 458 */
        "movss backEnd+444, %xmm4\n" /* line 459 */
        "movss %xmm4, -0x30(%ebp)\n"
        "movl $0, (%esp)\n" /* line 1603 */
        "movss %xmm0, -0x98(%ebp)\n"
        "movss %xmm1, -0xa8(%ebp)\n"
        "movss %xmm2, -0xb8(%ebp)\n"
        "calll RB_SetRenderTarget\n"
        "movl imp_dx, %eax\n" /* line 360 */
        "movl 0x2c6c(%eax), %eax\n"
        "movl %eax, backEnd+11916\n"
        "movl $0x3eaa7efa, %eax\n" /* line 447 */
        "movl %eax, backEnd+432\n"
        "movl $0x3eab020c, backEnd+436\n" /* line 448 */
        "movl %eax, backEnd+440\n" /* line 449 */
        "movl $0, backEnd+444\n" /* line 450 */
        "movl $0xa, 0x28(%esp)\n" /* line 1614 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f400000, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0x3e800000, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0xa8(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0xb8(%ebp), %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "mulss %xmm2, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movl imp_rgp, %eax\n"
        "movl 0x108c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1615 */
        "movl %ebx, backEnd+432\n" /* line 456 */
        "movl %esi, backEnd+436\n" /* line 457 */
        "movl %edi, backEnd+440\n" /* line 458 */
        "movss -0x30(%ebp), %xmm0\n" /* line 459 */
        "movss %xmm0, backEnd+444\n"
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 2033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: blurRadius */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfdaace_000db1a1:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lfdaace_000db1ab:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ebx\n"
        "jbe .Lfdaace_000db868\n"
        "subl $1, %eax\n"
        "jne .Lfdaace_000db1ab\n"
        "testl %edx, %edx\n"
        "js .Lfdaace_000db8e6\n"
        ".Lfdaace_000db1c2:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "jmp .Lfdaace_000dad09\n"
        /* } scope */
        /* { scope 5 */
        ".Lfdaace_000db1cb:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lfdaace_000db1d5:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lfdaace_000db851\n"
        "subl $1, %eax\n"
        "jne .Lfdaace_000db1d5\n"
        "testl %ecx, %ecx\n"
        "js .Lfdaace_000db8fc\n"
        ".Lfdaace_000db1ec:\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "jmp .Lfdaace_000dacf1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfdaace_000db1f5:\n"
        "movl imp_r_fullbright, %eax\n" /* line 1801 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfdaace_000dadce\n"
        "movl $1, %eax\n"
        "jmp .Lfdaace_000dadd0\n"
        ".Lfdaace_000db210:\n"
        "movl imp_r_fullbright, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfdaace_000dadee\n"
        "movl $1, %eax\n"
        "jmp .Lfdaace_000dadf0\n"
        ".Lfdaace_000db22b:\n"
        "movss -0x68(%ebp), %xmm0\n" /* line 1786 | blurRadius */
        "ucomiss %xmm1, %xmm0\n"
        "jbe .Lfdaace_000dad53\n"
        "movaps %xmm0, %xmm1\n"
        "jmp .Lfdaace_000dac40\n"
        /* { scope 2 */
        ".Lfdaace_000db241:\n"
        "movss -0x68(%ebp), %xmm2\n" /* blurRadius */
        "ucomiss %xmm1, %xmm2\n"
        "ja .Lfdaace_000dab6c\n"
        "jmp .Lfdaace_000dad53\n"
        /* } scope */
        ".Lfdaace_000db254:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lfdaace_000db25e:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ebx\n"
        "jbe .Lfdaace_000db4ff\n"
        "subl $1, %eax\n"
        "jne .Lfdaace_000db25e\n"
        "testl %edx, %edx\n"
        "js .Lfdaace_000db8d0\n"
        ".Lfdaace_000db275:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "jmp .Lfdaace_000daf78\n"
        ".Lfdaace_000db27e:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lfdaace_000db288:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lfdaace_000db516\n"
        "subl $1, %eax\n"
        "jne .Lfdaace_000db288\n"
        "testl %ecx, %ecx\n"
        "js .Lfdaace_000db8ba\n"
        ".Lfdaace_000db29f:\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "jmp .Lfdaace_000daf60\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lfdaace_000db2a8:\n"
        "divss %xmm2, %xmm0\n" /* line 428 */
        "mulss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x7c(%ebp)\n"
        "cvttss2si -0x7c(%ebp), %eax\n"
        "movl %esi, %edx\n"
        "movb %al, %dl\n"
        "movl %edx, %esi\n"
        "movss -0x2c(%ebp), %xmm0\n"
        "jmp .Lfdaace_000dac8e\n"
        /* } scope */
        /* } scope */
        ".Lfdaace_000db2de:\n"
        "movl imp_dxState, %eax\n" /* line 1529 */
        "cvtsi2ssl 0x209c(%eax), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss -0x5c(%ebp), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x5c(%ebp)\n"
        "cvtsi2ssl 0x20a0(%eax), %xmm2\n" /* line 1530 */
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, -0x58(%ebp)\n"
        "mulss %xmm0, %xmm1\n" /* line 1531 */
        "movss %xmm1, -0x54(%ebp)\n"
        "mulss %xmm2, %xmm0\n" /* line 1532 */
        "orl $0x00FF0000, %ebx\n" /* line 655 */
        "movb $0, %bh\n" /* line 656 */
        "xorb %bl, %bl\n" /* line 657 */
        "orl $0xff000000, %ebx\n" /* line 658 */
        "movl $0xa, 0x28(%esp)\n" /* line 1535 */
        "movl %ebx, 0x24(%esp)\n"
        "movl $0x3f800000, %esi\n" /* imageSurface */
        "movl %esi, 0x20(%esp)\n" /* imageSurface */
        "movl %esi, 0x1c(%esp)\n" /* imageSurface */
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movl imp_rgp, %edi\n" /* material */
        "movl 0x1090(%edi), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x98(%ebp)\n"
        "calll RB_DrawStretchPic\n"
        "andl $0xff00ffff, -0x70(%ebp)\n" /* line 655 */
        "movl -0x70(%ebp), %eax\n" /* line 656 */
        "movb $0xff, %ah\n"
        "xorb %al, %al\n" /* line 657 */
        "movl %eax, -0x70(%ebp)\n"
        "orl $0xff000000, %eax\n" /* line 658 */
        "movl $0xa, 0x28(%esp)\n" /* line 1538 */
        "movl %eax, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* imageSurface */
        "movl %esi, 0x1c(%esp)\n" /* imageSurface */
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x54(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x5c(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl 0x1090(%edi), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "andl $0xff00ffff, -0x74(%ebp)\n" /* line 655 */
        "movl -0x74(%ebp), %eax\n" /* line 656 */
        "movb $0, %ah\n"
        "movb $0xff, %al\n" /* line 657 */
        "movl %eax, -0x74(%ebp)\n"
        "orl $0xff000000, %eax\n" /* line 658 */
        "movl $0xa, 0x28(%esp)\n" /* line 1541 */
        "movl %eax, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* imageSurface */
        "movl %esi, 0x1c(%esp)\n" /* imageSurface */
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x54(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x58(%ebp), %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movl 0x1090(%edi), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "movl $0xa, 0x28(%esp)\n" /* line 1544 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* imageSurface */
        "movl %esi, 0x1c(%esp)\n" /* imageSurface */
        "movl %ebx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x54(%ebp), %xmm3\n"
        "movss %xmm3, 0xc(%esp)\n"
        "movss -0x58(%ebp), %xmm4\n"
        "movss %xmm4, 8(%esp)\n"
        "movss -0x5c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl 0x1094(%edi), %eax\n" /* material */
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1546 */
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 2033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: blurRadius */
        ".Lfdaace_000db4dc:\n"
        "movl $0, backEnd+1232\n" /* line 1668 */
        "movl imp_r_rendererInUse, %edx\n"
        "movl (%edx), %eax\n"
        "jmp .Lfdaace_000dac18\n"
        ".Lfdaace_000db4f3:\n"
        "pxor %xmm0, %xmm0\n" /* line 1632 */
        "movaps %xmm0, %xmm2\n"
        "jmp .Lfdaace_000db024\n"
        ".Lfdaace_000db4ff:\n"
        "testl %edx, %edx\n" /* line 144 */
        "jns .Lfdaace_000db275\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000daf78\n"
        ".Lfdaace_000db516:\n"
        "testl %ecx, %ecx\n"
        "jns .Lfdaace_000db29f\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000daf60\n"
        ".Lfdaace_000db52d:\n"
        "movl imp_dxState, %eax\n" /* line 1484 */
        "cvtsi2ssl 0x209c(%eax), %xmm1\n"
        "movss lit4_002ed5d8, %xmm2\n" /* 0.5f */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x50(%ebp)\n"
        "cvtsi2ssl 0x20a0(%eax), %xmm3\n" /* line 1485 */
        "movss lit4_002ed5d8, %xmm4\n" /* 0.5f */
        "mulss %xmm3, %xmm4\n"
        "movss %xmm4, -0x4c(%ebp)\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 1486 | 0.5f */
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n"
        "movss lit4_002ed5d8, %xmm1\n" /* line 1487 | 0.5f */
        "mulss %xmm4, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss backEnd+432, %xmm2\n" /* line 456 */
        "movss %xmm2, -0x34(%ebp)\n"
        "movss backEnd+436, %xmm3\n" /* line 457 */
        "movss %xmm3, -0x38(%ebp)\n"
        "movss backEnd+440, %xmm4\n" /* line 458 */
        "movss %xmm4, -0x3c(%ebp)\n"
        "movss backEnd+444, %xmm0\n" /* line 459 */
        "movss %xmm0, -0x40(%ebp)\n"
        "movl imp_dx, %eax\n" /* line 360 */
        "movl 0x2c6c(%eax), %eax\n"
        "movl %eax, backEnd+11916\n"
        "movl $0, (%esp)\n" /* line 1492 */
        "calll RB_SetRenderTarget\n"
        "movl $0x3f800000, backEnd+432\n" /* line 447 */
        "xorl %ebx, %ebx\n" /* line 448 */
        "movl %ebx, backEnd+436\n"
        "movl %ebx, backEnd+440\n" /* line 449 */
        "movl %ebx, backEnd+444\n" /* line 450 */
        "movl $0xa, 0x28(%esp)\n" /* line 1502 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f000000, 0x20(%esp)\n"
        "movl $0x3f000000, 0x1c(%esp)\n"
        "movl $0x3e800000, %edi\n" /* material */
        "movl %edi, 0x18(%esp)\n" /* material */
        "movl %edi, 0x14(%esp)\n" /* material */
        "movss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0x48(%ebp), %xmm2\n"
        "movss %xmm2, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm2, 4(%esp)\n"
        "movl imp_rgp, %edx\n"
        "movl 0x108c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1503 */
        "movl %ebx, backEnd+432\n" /* line 447 */
        "movl $0x3f800000, backEnd+436\n" /* line 448 */
        "movl %ebx, backEnd+440\n" /* line 449 */
        "movl %ebx, backEnd+444\n" /* line 450 */
        "movl $0xa, 0x28(%esp)\n" /* line 1506 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl $0x3f000000, 0x20(%esp)\n"
        "movl $0x3f400000, %esi\n" /* imageSurface */
        "movl %esi, 0x1c(%esp)\n" /* imageSurface */
        "movl %edi, 0x18(%esp)\n" /* material */
        "movl $0x3f000000, 0x14(%esp)\n"
        "movss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x50(%ebp), %xmm2\n"
        "movss %xmm2, 4(%esp)\n"
        "movl imp_rgp, %edx\n"
        "movl 0x108c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1507 */
        "movl %ebx, backEnd+432\n" /* line 447 */
        "movl %ebx, backEnd+436\n" /* line 448 */
        "movl $0x3f800000, backEnd+440\n" /* line 449 */
        "movl %ebx, backEnd+444\n" /* line 450 */
        "movl $0xa, 0x28(%esp)\n" /* line 1510 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* imageSurface */
        "movl $0x3f000000, 0x1c(%esp)\n"
        "movl $0x3f000000, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* material */
        "movss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x4c(%ebp), %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movl imp_rgp, %edx\n"
        "movl 0x108c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1511 */
        "movl %ebx, backEnd+432\n" /* line 447 */
        "movl %ebx, backEnd+436\n" /* line 448 */
        "movl %ebx, backEnd+440\n" /* line 449 */
        "movl $0x3f800000, backEnd+444\n" /* line 450 */
        "movl $0xa, 0x28(%esp)\n" /* line 1514 */
        "movl $0xffffffff, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* imageSurface */
        "movl %esi, 0x1c(%esp)\n" /* imageSurface */
        "movl $0x3f000000, 0x18(%esp)\n"
        "movl $0x3f000000, 0x14(%esp)\n"
        "movss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x4c(%ebp), %xmm2\n"
        "movss %xmm2, 8(%esp)\n"
        "movss -0x50(%ebp), %xmm3\n"
        "movss %xmm3, 4(%esp)\n"
        "movl imp_rgp, %edx\n"
        "movl 0x108c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_DrawStretchPic\n"
        "calll RB_EndSurface\n" /* line 1515 */
        "movss -0x34(%ebp), %xmm0\n" /* line 456 */
        "movss %xmm0, backEnd+432\n"
        "movss -0x38(%ebp), %xmm1\n" /* line 457 */
        "movss %xmm1, backEnd+436\n"
        "movss -0x3c(%ebp), %xmm2\n" /* line 458 */
        "movss %xmm2, backEnd+440\n"
        "movss -0x40(%ebp), %xmm3\n" /* line 459 */
        "movss %xmm3, backEnd+444\n"
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0xfc, %esp\n" /* line 2033 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: blurRadius */
        ".Lfdaace_000db841:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 1689 */
        "ja .Lfdaace_000daea9\n"
        ".Lfdaace_000db84a:\n"
        "xorl %eax, %eax\n" /* line 1693 */
        "jmp .Lfdaace_000daeb8\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfdaace_000db851:\n"
        "testl %ecx, %ecx\n" /* line 144 */
        "jns .Lfdaace_000db1ec\n"
        "shrl $1, %ecx\n"
        "cvtsi2ssl %ecx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000dacf1\n"
        /* } scope */
        /* { scope 5 */
        ".Lfdaace_000db868:\n"
        "testl %edx, %edx\n"
        "jns .Lfdaace_000db1c2\n"
        "shrl $1, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000dad09\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfdaace_000db87f:\n"
        "movl imp_rgp, %eax\n" /* line 1682 */
        "movl 0x109c(%eax), %eax\n"
        "movl %eax, -0xcc(%ebp)\n"
        "movl 0x20(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfdaace_000dae7d\n"
        "movl -0x78(%ebp), %eax\n"
        "movl (%edx, %eax), %eax\n"
        "movl %eax, -0xd0(%ebp)\n"
        "movss 8(%eax), %xmm0\n"
        "ucomiss %xmm2, %xmm0\n"
        "ja .Lfdaace_000dae75\n"
        "jmp .Lfdaace_000dae7d\n"
        ".Lfdaace_000db8ba:\n"
        "movl %ecx, %eax\n" /* line 144 */
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000daf60\n"
        ".Lfdaace_000db8d0:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000daf78\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        /* { scope 5 */
        ".Lfdaace_000db8e6:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000dad09\n"
        /* } scope */
        /* { scope 5 */
        ".Lfdaace_000db8fc:\n"
        "movl %ecx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %ecx\n"
        "orl %ecx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lfdaace_000dacf1\n"
    );
}

/* line 620 */
static __attribute__((naked))
void RB_StretchPicRotateCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 620 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: radians, vertIndex */
        "movl 8(%ebp), %eax\n" /* line 634 | execState */
        "movl (%eax), %edi\n" /* cmd */
        "cmpb $0, backEnd+1213\n" /* line 636 */
        "je .Lfdb912_000dbe65\n"
        "movl 4(%edi), %ebx\n" /* line 642 | cmd, material */
        /* { scope 2: y, x, y, y, ... */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfdb912_000dbe79\n"
        ".Lfdb912_000db93c:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdb912_000dbe4e\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdb912_000dbe4e\n"
        ".Lfdb912_000db956:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdb912_000db96e:\n"
        "movl tess+370644, %ecx\n" /* line 344 */
        "leal 4(%ecx), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfdb912_000dbdf1\n"
        "movl tess+370640, %edx\n"
        "leal 6(%edx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jg .Lfdb912_000dbdf1\n"
        ".Lfdb912_000db996:\n"
        "movl %ecx, %ebx\n" /* line 646 | material */
        "leal 4(%ecx), %eax\n" /* line 649 */
        "movl %eax, tess+370644\n"
        "leal 6(%edx), %eax\n" /* line 650 */
        "movl %eax, tess+370640\n"
        "leal (%edx, %edx), %ecx\n" /* line 652 */
        "leal 3(%ebx), %edx\n" /* material */
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx)\n"
        "movl tess+370608, %eax\n" /* line 653 */
        "movw %bx, 2(%eax, %ecx)\n" /* material */
        "leal 2(%ebx), %edx\n" /* line 654 | material */
        "movl tess+370608, %eax\n"
        "movw %dx, 4(%ecx, %eax)\n"
        "movl tess+370608, %eax\n" /* line 655 */
        "movw %dx, 6(%ecx, %eax)\n"
        "movl tess+370608, %eax\n" /* line 656 */
        "movw %bx, 8(%ecx, %eax)\n" /* material */
        "leal 1(%ebx), %edx\n" /* line 657 | material */
        "movl tess+370608, %eax\n"
        "movw %dx, 0xa(%ecx, %eax)\n"
        "movss lit4_002ed5d8, %xmm1\n" /* line 659 | 0.5f */
        "movss 0x10(%edi), %xmm0\n" /* cmd */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n" /* halfWidth */
        "mulss 0x14(%edi), %xmm1\n" /* line 660 | cmd */
        "addss 8(%edi), %xmm0\n" /* line 661 | cmd */
        "movss %xmm0, -0x44(%ebp)\n" /* midX */
        "movaps %xmm1, %xmm2\n" /* line 662 */
        "addss 0xc(%edi), %xmm2\n" /* cmd */
        "movss %xmm2, -0x40(%ebp)\n" /* midY */
        "cvtss2sd 0x2c(%edi), %xmm0\n" /* line 663 | cmd */
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* radians */
        /* { scope 2: y, x, y, y, ... */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "movss %xmm1, -0x68(%ebp)\n"
        "calll sinf\n"
        "fstps -0x50(%ebp)\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        /* } scope */
        "movss -0x3c(%ebp), %xmm6\n" /* line 664 | halfWidth */
        "mulss %xmm0, %xmm6\n"
        "movss -0x3c(%ebp), %xmm5\n" /* line 665 | halfWidth */
        "mulss -0x50(%ebp), %xmm5\n"
        "movss -0x68(%ebp), %xmm1\n" /* line 666 */
        "movaps %xmm1, %xmm4\n"
        "xorps refEntIsInWorldSpace+32, %xmm4\n"
        "mulss -0x50(%ebp), %xmm4\n"
        "mulss %xmm1, %xmm0\n" /* line 667 */
        "movl 0x28(%edi), %eax\n" /* line 669 | cmd */
        "movl %eax, -0x4c(%ebp)\n"
        "movss 0x1c(%edi), %xmm1\n" /* cmd */
        "movss %xmm1, -0x2c(%ebp)\n" /* y */
        "movss 0x18(%edi), %xmm2\n" /* cmd */
        "movss %xmm2, -0x28(%ebp)\n" /* x */
        "movss -0x40(%ebp), %xmm1\n" /* midY */
        "subss %xmm5, %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movaps %xmm1, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "movss -0x44(%ebp), %xmm7\n" /* midX */
        "subss %xmm6, %xmm7\n"
        "movaps %xmm7, %xmm2\n"
        "subss %xmm4, %xmm2\n"
        "movzwl %bx, %esi\n" /* material, vertCount */
        "movl %esi, -0x34(%ebp)\n" /* vertCount, vertIndex */
        /* { scope 2: y, x, y, y, ... */
        "movl imp_r_rendererInUse, %eax\n" /* line 348 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdb912_000dbf9d\n"
        "movl %esi, %edx\n"
        "shll $6, %edx\n" /* line 358 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm2, tess(%edx)\n" /* line 447 */
        "movss %xmm3, 4(%eax)\n" /* line 448 */
        "xorl %esi, %esi\n" /* line 449 | x */
        "movl %esi, 8(%eax)\n" /* x */
        "movl $0x3f800000, %ebx\n" /* line 450 */
        "movl %ebx, 0xc(%eax)\n"
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 191 */
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl %ebx, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x4c(%ebp), %eax\n" /* line 360 */
        "movl %eax, tess+28(%edx)\n"
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movss -0x28(%ebp), %xmm1\n" /* line 30 | x */
        "movss %xmm1, tess(%eax)\n"
        "movss -0x2c(%ebp), %xmm2\n" /* line 31 | y */
        "movss %xmm2, 4(%ecx)\n"
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ebx, 4(%edx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl %esi, 8(%ecx)\n" /* line 191 */
        "movl %ebx, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdb912_000dbb65:\n"
        "movl 0x28(%edi), %ebx\n" /* line 670 | cmd, material */
        "movss 0x1c(%edi), %xmm1\n" /* cmd */
        "movss %xmm1, -0x24(%ebp)\n" /* y */
        "movl 0x20(%edi), %esi\n" /* cmd, vertCount */
        "movss -0x40(%ebp), %xmm1\n" /* midY */
        "addss %xmm5, %xmm1\n"
        "movaps %xmm1, %xmm3\n"
        "subss %xmm0, %xmm3\n"
        "movss -0x44(%ebp), %xmm5\n" /* midX */
        "addss %xmm6, %xmm5\n"
        "movaps %xmm5, %xmm2\n"
        "subss %xmm4, %xmm2\n"
        "movl -0x34(%ebp), %eax\n" /* vertIndex */
        "addl $1, %eax\n" /* vertIndex */
        /* { scope 2: y, x, y, y, ... */
        "movl -0x30(%ebp), %edx\n" /* line 348 */
        "cmpl $2, 8(%edx)\n"
        "je .Lfdb912_000dbf48\n"
        "movl %eax, %edx\n" /* line 358 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm2, tess(%edx)\n" /* line 447 */
        "movss %xmm3, 4(%eax)\n" /* line 448 */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, tess+28(%edx)\n" /* line 360 */
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movss -0x24(%ebp), %xmm2\n" /* line 31 | y */
        "movss %xmm2, 4(%ecx)\n"
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdb912_000dbc44:\n"
        "movl 0x28(%edi), %ebx\n" /* line 671 | cmd, material */
        "movss 0x24(%edi), %xmm2\n" /* cmd */
        "movss %xmm2, -0x20(%ebp)\n" /* y */
        "movl 0x20(%edi), %esi\n" /* cmd, vertCount */
        "addss %xmm0, %xmm1\n"
        "movaps %xmm4, %xmm2\n"
        "addss %xmm5, %xmm2\n"
        "movl -0x34(%ebp), %eax\n" /* vertIndex */
        "addl $2, %eax\n" /* vertIndex */
        /* { scope 2: y, x, y, y, ... */
        "movl -0x30(%ebp), %edx\n" /* line 348 */
        "cmpl $2, 8(%edx)\n"
        "je .Lfdb912_000dbef3\n"
        "movl %eax, %edx\n" /* line 358 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm2, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, tess+28(%edx)\n" /* line 360 */
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movss -0x20(%ebp), %xmm2\n" /* line 31 | y */
        "movss %xmm2, 4(%ecx)\n"
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdb912_000dbd0e:\n"
        "movl 0x28(%edi), %ebx\n" /* line 672 | cmd, material */
        "movss 0x24(%edi), %xmm1\n" /* cmd */
        "movss %xmm1, -0x1c(%ebp)\n" /* y */
        "movl 0x18(%edi), %esi\n" /* cmd, vertCount */
        "addss -0x48(%ebp), %xmm0\n"
        "movaps %xmm4, %xmm1\n"
        "addss %xmm7, %xmm1\n"
        "movl -0x34(%ebp), %eax\n" /* vertIndex */
        "addl $3, %eax\n" /* vertIndex */
        /* { scope 2: y, x, y, y, ... */
        "movl -0x30(%ebp), %edx\n" /* line 348 */
        "cmpl $2, 8(%edx)\n"
        "je .Lfdb912_000dbe8b\n"
        "movl %eax, %edx\n" /* line 358 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm1, tess(%edx)\n" /* line 447 */
        "movss %xmm0, 4(%eax)\n" /* line 448 */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, tess+28(%edx)\n" /* line 360 */
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movss -0x1c(%ebp), %xmm1\n" /* line 31 | y */
        "movss %xmm1, 4(%ecx)\n"
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 675 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: radians, vertIndex */
        ".Lfdb912_000dbdf1:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfdb912_000dbe3d\n"
        "movl tess+370640, %esi\n" /* line 261 */
        "testl %esi, %esi\n"
        "jne .Lfdb912_000dbe58\n"
        "movl tess+370656, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfdb912_000dbe58\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        ".Lfdb912_000dbe3d:\n"
        "movl tess+370644, %ecx\n"
        "movl tess+370640, %edx\n"
        "jmp .Lfdb912_000db996\n"
        /* { scope 2: y, x, y, y, ... */
        ".Lfdb912_000dbe4e:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdb912_000db956\n"
        /* } scope */
        ".Lfdb912_000dbe58:\n"
        "calll RB_EndSurface\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "jmp .Lfdb912_000dbe3d\n"
        ".Lfdb912_000dbe65:\n"
        "calll RB_Set2D\n" /* line 638 */
        "movl 4(%edi), %ebx\n" /* line 642 | cmd, material */
        /* { scope 2: y, x, y, y, ... */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "jne .Lfdb912_000db93c\n"
        ".Lfdb912_000dbe79:\n"
        "cmpl $3, tess+370624\n"
        "jne .Lfdb912_000db93c\n"
        "jmp .Lfdb912_000db96e\n"
        /* } scope */
        /* { scope 2: y, x, y, y, ... */
        ".Lfdb912_000dbe8b:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm1, tess(%eax)\n" /* line 191 */
        "movss %xmm0, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, tess+24(%eax)\n" /* line 352 */
        "addl $tess+16, %eax\n" /* line 353 */
        "movl %esi, 0xc(%eax)\n" /* line 30 */
        "movss -0x1c(%ebp), %xmm0\n" /* line 31 | y */
        "movss %xmm0, 0x10(%eax)\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 675 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: radians, vertIndex */
        /* { scope 2: y, x, y, y, ... */
        ".Lfdb912_000dbef3:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm2, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, tess+24(%eax)\n" /* line 352 */
        "addl $tess+16, %eax\n" /* line 353 */
        "movl %esi, 0xc(%eax)\n" /* line 30 */
        "movss -0x20(%ebp), %xmm1\n" /* line 31 | y */
        "movss %xmm1, 0x10(%eax)\n"
        "jmp .Lfdb912_000dbd0e\n"
        /* } scope */
        /* { scope 2: y, x, y, y, ... */
        ".Lfdb912_000dbf48:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm2, tess(%eax)\n" /* line 191 */
        "movss %xmm3, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %ebx, tess+24(%eax)\n" /* line 352 */
        "addl $tess+16, %eax\n" /* line 353 */
        "movl %esi, 0xc(%eax)\n" /* line 30 */
        "movss -0x24(%ebp), %xmm2\n" /* line 31 | y */
        "movss %xmm2, 0x10(%eax)\n"
        "jmp .Lfdb912_000dbc44\n"
        /* } scope */
        /* { scope 2: y, x, y, y, ... */
        ".Lfdb912_000dbf9d:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm2, tess(%eax)\n" /* line 191 */
        "movss %xmm3, 4(%edx)\n" /* line 192 */
        "xorl %esi, %esi\n" /* line 193 */
        "movl %esi, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl %esi, 0xc(%edx)\n" /* line 191 */
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x4c(%ebp), %edx\n" /* line 352 */
        "movl %edx, tess+24(%eax)\n"
        "addl $tess+16, %eax\n" /* line 353 */
        "movss -0x28(%ebp), %xmm1\n" /* line 30 | x */
        "movss %xmm1, 0xc(%eax)\n"
        "movss -0x2c(%ebp), %xmm2\n" /* line 31 | y */
        "movss %xmm2, 0x10(%eax)\n"
        "jmp .Lfdb912_000dbb65\n"
    );
}

/* line 678 */
static __attribute__((naked))
void RB_DrawQuadPicCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 678 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1: vertIndex */
        "movl 8(%ebp), %eax\n" /* line 684 | execState */
        "movl (%eax), %edi\n" /* cmd */
        "cmpb $0, backEnd+1213\n" /* line 686 */
        "je .Lfdbff2_000dc422\n"
        "movl 4(%edi), %ebx\n" /* line 692 | cmd, material */
        /* { scope 2 */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfdbff2_000dc436\n"
        ".Lfdbff2_000dc01c:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdbff2_000dc3fc\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdbff2_000dc3fc\n"
        ".Lfdbff2_000dc036:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdbff2_000dc04e:\n"
        "movl tess+370644, %ecx\n" /* line 344 */
        "leal 4(%ecx), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfdbff2_000dc39d\n"
        "movl tess+370640, %edx\n"
        "leal 6(%edx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jg .Lfdbff2_000dc39d\n"
        ".Lfdbff2_000dc076:\n"
        "movl %ecx, %ebx\n" /* line 696 | material */
        "movl %ecx, %esi\n" /* vertCount */
        "leal 4(%ecx), %eax\n" /* line 699 */
        "movl %eax, tess+370644\n"
        "leal 6(%edx), %eax\n" /* line 700 */
        "movl %eax, tess+370640\n"
        "leal (%edx, %edx), %ecx\n" /* line 702 */
        "leal 3(%ebx), %edx\n" /* material */
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx)\n"
        "movl tess+370608, %eax\n" /* line 703 */
        "movw %bx, 2(%eax, %ecx)\n" /* material */
        "leal 2(%ebx), %edx\n" /* line 704 | material */
        "movl tess+370608, %eax\n"
        "movw %dx, 4(%ecx, %eax)\n"
        "movl tess+370608, %eax\n" /* line 705 */
        "movw %dx, 6(%ecx, %eax)\n"
        "movl tess+370608, %eax\n" /* line 706 */
        "movw %bx, 8(%ecx, %eax)\n" /* material */
        "leal 1(%ebx), %edx\n" /* line 707 | material */
        "movl tess+370608, %eax\n"
        "movw %dx, 0xa(%ecx, %eax)\n"
        "movl 0x28(%edi), %edx\n" /* line 709 | cmd */
        "movl %edx, -0x24(%ebp)\n"
        "movl 0xc(%edi), %ebx\n" /* cmd, material */
        "movl 8(%edi), %ecx\n" /* cmd */
        "movzwl %si, %esi\n" /* vertCount */
        "movl %esi, -0x20(%ebp)\n" /* vertCount, vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %eax\n" /* line 348 */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdbff2_000dc551\n"
        "movl %esi, %edx\n"
        "shll $6, %edx\n" /* line 358 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%edx)\n" /* line 447 */
        "movl %ebx, 4(%eax)\n" /* line 448 | y */
        "xorl %esi, %esi\n" /* line 449 */
        "movl %esi, 8(%eax)\n"
        "movl $0x3f800000, %ebx\n" /* line 450 | y */
        "movl %ebx, 0xc(%eax)\n" /* y */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 191 */
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl %ebx, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x24(%ebp), %eax\n" /* line 360 */
        "movl %eax, tess+28(%edx)\n"
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ebx, 4(%edx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl %esi, 8(%ecx)\n" /* line 191 */
        "movl %ebx, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdbff2_000dc166:\n"
        "movl 0x28(%edi), %esi\n" /* line 710 | cmd, vertCount */
        "movl 0x14(%edi), %ebx\n" /* cmd, material */
        "movl 0x10(%edi), %ecx\n" /* cmd */
        "movl -0x20(%ebp), %eax\n" /* vertIndex */
        "addl $1, %eax\n" /* vertIndex */
        /* { scope 2 */
        "movl -0x1c(%ebp), %edx\n" /* line 348 */
        "cmpl $2, 8(%edx)\n"
        "je .Lfdbff2_000dc4ff\n"
        "movl %eax, %edx\n" /* line 358 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%edx)\n" /* line 447 */
        "movl %ebx, 4(%eax)\n" /* line 448 | y */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %esi, tess+28(%edx)\n" /* line 360 */
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdbff2_000dc21b:\n"
        "movl 0x28(%edi), %esi\n" /* line 711 | cmd, vertCount */
        "movl 0x1c(%edi), %ebx\n" /* cmd, material */
        "movl 0x18(%edi), %ecx\n" /* cmd */
        "movl -0x20(%ebp), %eax\n" /* vertIndex */
        "addl $2, %eax\n" /* vertIndex */
        /* { scope 2 */
        "movl -0x1c(%ebp), %edx\n" /* line 348 */
        "cmpl $2, 8(%edx)\n"
        "je .Lfdbff2_000dc4ad\n"
        "movl %eax, %edx\n" /* line 358 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%edx)\n" /* line 447 */
        "movl %ebx, 4(%eax)\n" /* line 448 | y */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %esi, tess+28(%edx)\n" /* line 360 */
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdbff2_000dc2d0:\n"
        "movl 0x28(%edi), %esi\n" /* line 712 | cmd, vertCount */
        "movl 0x24(%edi), %ebx\n" /* cmd, material */
        "movl 0x20(%edi), %ecx\n" /* cmd */
        "movl -0x20(%ebp), %eax\n" /* vertIndex */
        "addl $3, %eax\n" /* vertIndex */
        /* { scope 2 */
        "movl -0x1c(%ebp), %edx\n" /* line 348 */
        "cmpl $2, 8(%edx)\n"
        "je .Lfdbff2_000dc448\n"
        "movl %eax, %edx\n" /* line 358 | v */
        "shll $6, %edx\n"
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%edx)\n" /* line 447 */
        "movl %ebx, 4(%eax)\n" /* line 448 | y */
        "movl $0, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 359 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %esi, tess+28(%edx)\n" /* line 360 */
        "leal 0x20(%edx), %eax\n" /* line 361 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 362 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 363 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 715 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vertIndex */
        ".Lfdbff2_000dc39d:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfdbff2_000dc594\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdbff2_000dc406\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdbff2_000dc406\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %ecx\n"
        "movl tess+370640, %edx\n"
        "jmp .Lfdbff2_000dc076\n"
        /* { scope 2 */
        ".Lfdbff2_000dc3fc:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdbff2_000dc036\n"
        /* } scope */
        ".Lfdbff2_000dc406:\n"
        "calll RB_EndSurface\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %ecx\n"
        "movl tess+370640, %edx\n"
        "jmp .Lfdbff2_000dc076\n"
        ".Lfdbff2_000dc422:\n"
        "calll RB_Set2D\n" /* line 688 */
        "movl 4(%edi), %ebx\n" /* line 692 | cmd, material */
        /* { scope 2 */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "jne .Lfdbff2_000dc01c\n"
        ".Lfdbff2_000dc436:\n"
        "cmpl $3, tess+370624\n"
        "jne .Lfdbff2_000dc01c\n"
        "jmp .Lfdbff2_000dc04e\n"
        /* } scope */
        /* { scope 2 */
        ".Lfdbff2_000dc448:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%eax)\n" /* line 191 */
        "movl %ebx, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %esi, tess+24(%eax)\n" /* line 352 */
        "addl $tess+16, %eax\n" /* line 353 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 715 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: vertIndex */
        /* { scope 2 */
        ".Lfdbff2_000dc4ad:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%eax)\n" /* line 191 */
        "movl %ebx, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %esi, tess+24(%eax)\n" /* line 352 */
        "addl $tess+16, %eax\n" /* line 353 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdbff2_000dc2d0\n"
        /* } scope */
        /* { scope 2 */
        ".Lfdbff2_000dc4ff:\n"
        "leal (%eax, %eax, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%eax)\n" /* line 191 */
        "movl %ebx, 4(%edx)\n" /* line 192 */
        "movl $0, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %esi, tess+24(%eax)\n" /* line 352 */
        "addl $tess+16, %eax\n" /* line 353 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdbff2_000dc21b\n"
        /* } scope */
        /* { scope 2 */
        ".Lfdbff2_000dc551:\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 350 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movl %ecx, tess(%eax)\n" /* line 191 */
        "movl %ebx, 4(%edx)\n" /* line 192 */
        "xorl %esi, %esi\n" /* line 193 */
        "movl %esi, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 351 | v */
        /* { scope 3 */
        "movl %esi, 0xc(%edx)\n" /* line 191 */
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl -0x24(%ebp), %edx\n" /* line 352 */
        "movl %edx, tess+24(%eax)\n"
        "addl $tess+16, %eax\n" /* line 353 */
        "movl %esi, 0xc(%eax)\n" /* line 30 */
        "movl %esi, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdbff2_000dc166\n"
        ".Lfdbff2_000dc594:\n"
        "movl tess+370644, %ecx\n"
        "movl tess+370640, %edx\n"
        "jmp .Lfdbff2_000dc076\n"
    );
}

/* line 2273 */
__attribute__((naked))
void RB_DrawLines3D(int count, int width, const GfxPointVertex *verts, int depthTest)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x11c, %esp\n"
        "movzbl 0x14(%ebp), %eax\n" /* depthTest */
        "movb %al, -0xc9(%ebp)\n" /* depthTest */
        "movl imp_rgp, %eax\n"
        "movl 0x1044(%eax), %ebx\n" /* from */
        /* { scope 1 */
        /* { scope 2: from */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfdc5a6_000dd1ca\n"
        ".Lfdc5a6_000dc5d3:\n"
        "movl tess+370640, %edi\n" /* line 261 */
        "testl %edi, %edi\n"
        "jne .Lfdc5a6_000dc6cd\n"
        "movl tess+370656, %esi\n"
        "testl %esi, %esi\n"
        "jne .Lfdc5a6_000dc6cd\n"
        ".Lfdc5a6_000dc5ef:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdc5a6_000dc607:\n"
        "cmpb $0, -0xc9(%ebp)\n" /* line 2288 | depthTest */
        "jne .Lfdc5a6_000dc627\n"
        "movl imp_rgp, %eax\n" /* line 2289 */
        "movl 0x1044(%eax), %edx\n" /* mtl */
        /* { scope 2: from */
        "movl 0x30(%edx), %eax\n" /* line 2269 */
        "andl $0xfffffff1, %eax\n"
        "orl $2, %eax\n"
        "movl %eax, 0x30(%edx)\n"
        /* } scope */
        ".Lfdc5a6_000dc627:\n"
        "leal -0x70(%ebp), %ebx\n" /* line 2293 | identity, material */
        "movl %ebx, (%esp)\n" /* material */
        "calll MatrixIdentity44\n"
        "movl %ebx, (%esp)\n" /* line 2294 | material */
        "calll RB_SetProjectionMatrix\n"
        "movl %ebx, (%esp)\n" /* line 2295 | material */
        "calll RB_SetViewMatrix\n"
        "movl backEnd+968, %edx\n" /* line 2297 */
        "leal 0xc8(%edx), %ecx\n"
        "movl %ecx, -0xb8(%ebp)\n" /* transform */
        "cvtsi2ssl 0xc(%ebp), %xmm1\n" /* line 2299 | width */
        "movl imp_dxState, %eax\n"
        "cvtsi2ssl 0x209c(%eax), %xmm0\n"
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movss %xmm2, -0xb4(%ebp)\n" /* invWidth */
        "cvtsi2ssl 0x20a0(%eax), %xmm0\n" /* line 2300 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0xb0(%ebp)\n" /* invHeight */
        "movl 8(%ebp), %ebx\n" /* line 2301 | count, material */
        "testl %ebx, %ebx\n" /* material */
        "jg .Lfdc5a6_000dc6d7\n"
        ".Lfdc5a6_000dc690:\n"
        "calll RB_EndSurface\n" /* line 2338 */
        "movl backEnd+968, %eax\n" /* line 2340 */
        "movl %eax, (%esp)\n"
        "calll RB_SetMatricesForView\n"
        "cmpb $0, -0xc9(%ebp)\n" /* line 2342 | depthTest */
        "jne .Lfdc5a6_000dc6c2\n"
        "movl imp_rgp, %eax\n" /* line 2343 */
        "movl 0x1044(%eax), %edx\n" /* mtl */
        /* { scope 2: from */
        "movl 0x30(%edx), %eax\n" /* line 2269 */
        "andl $0xfffffff1, %eax\n"
        "orl $4, %eax\n"
        "movl %eax, 0x30(%edx)\n"
        /* } scope */
        /* } scope */
        ".Lfdc5a6_000dc6c2:\n"
        "addl $0x11c, %esp\n" /* line 2344 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: from */
        ".Lfdc5a6_000dc6cd:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdc5a6_000dc5ef\n"
        /* } scope */
        ".Lfdc5a6_000dc6d7:\n"
        "leal 0xd8(%edx), %eax\n" /* line 2301 */
        "movl %eax, -0x88(%ebp)\n"
        "leal 0xe8(%edx), %ecx\n"
        "movl %ecx, -0x84(%ebp)\n"
        "addl $0xf8, %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl 0x10(%ebp), %edi\n" /* line 2273 | verts */
        "addl $0x10, %edi\n"
        "movl %edi, -0x7c(%ebp)\n"
        "movl $0, -0xbc(%ebp)\n" /* lineIndex */
        "jmp .Lfdc5a6_000dca59\n"
        /* { scope 2: from */
        ".Lfdc5a6_000dc710:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss -0x94(%ebp), %xmm0\n" /* line 449 */
        "movss %xmm0, 8(%eax)\n"
        "movss -0x98(%ebp), %xmm2\n" /* line 450 */
        "movss %xmm2, 0xc(%eax)\n"
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, tess(%ecx)\n"
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, %ebx\n" /* line 193 */
        "movl %ebx, 8(%eax)\n"
        /* } scope */
        /* { scope 3 */
        "movl -0xa8(%ebp), %eax\n" /* line 606 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, tess+12(%ecx)\n"
        /* } scope */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl %ebx, 4(%edx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl %esi, 8(%ecx)\n" /* line 191 */
        "movl %ebx, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdc5a6_000dc79b:\n"
        "leal 0xc(%edi), %ebx\n" /* line 2333 | material */
        "movss -0xa0(%ebp), %xmm1\n"
        "subss -0x24(%ebp), %xmm1\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "subss -0x28(%ebp), %xmm0\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdc5a6_000dd15c\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss -0xa4(%ebp), %xmm0\n" /* line 449 */
        "movss %xmm0, 8(%eax)\n"
        "movss %xmm5, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* { scope 3 */
        "movl 0xc(%edi), %eax\n" /* line 606 */
        "movl %eax, tess+12(%ecx)\n"
        /* } scope */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdc5a6_000dc875:\n"
        "movss -0xa0(%ebp), %xmm1\n" /* line 2334 */
        "addss -0x24(%ebp), %xmm1\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "addss -0x28(%ebp), %xmm0\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdc5a6_000dd0ef\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss -0xa4(%ebp), %xmm2\n" /* line 449 */
        "movss %xmm2, 8(%eax)\n"
        "movss %xmm5, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl (%ebx), %eax\n" /* line 606 | from */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdc5a6_000dc94b:\n"
        "movss -0x90(%ebp), %xmm1\n" /* line 2335 */
        "addss -0x2c(%ebp), %xmm1\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "addss -0x30(%ebp), %xmm0\n" /* offset */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdc5a6_000dd070\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss -0x94(%ebp), %xmm0\n" /* line 449 */
        "movss %xmm0, 8(%eax)\n"
        "movss -0x98(%ebp), %xmm2\n" /* line 450 */
        "movss %xmm2, 0xc(%eax)\n"
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0xac(%ebp), %ebx\n" /* line 606 | from */
        "movl (%ebx), %eax\n" /* from */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdc5a6_000dca2f:\n"
        "addl $4, tess+370644\n" /* line 2336 */
        "addl $1, -0xbc(%ebp)\n" /* line 2301 | lineIndex */
        "addl $0x20, -0x7c(%ebp)\n"
        "addl $0x20, %edi\n"
        "movl -0xbc(%ebp), %eax\n" /* lineIndex */
        "cmpl %eax, 8(%ebp)\n" /* count */
        "je .Lfdc5a6_000dc690\n"
        "movl -0x84(%ebp), %ecx\n"
        ".Lfdc5a6_000dca59:\n"
        "leal -0x10(%edi), %ebx\n" /* line 2273 | from */
        "movl %ebx, -0xa8(%ebp)\n" /* from */
        "movl -0xb8(%ebp), %eax\n" /* line 2304 | transform */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xf8(%ebp)\n"
        "movss -0xc(%edi), %xmm1\n"
        "movl -0x88(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "movss -8(%edi), %xmm2\n"
        "movl -0x84(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0xf4(%ebp)\n"
        "movss -0x10(%edi), %xmm0\n"
        "mulss -0xf8(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movss -0xc8(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x8c(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss -0x8c(%ebp), %xmm0\n"
        "addss -0xf4(%ebp), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movl -0xb8(%ebp), %eax\n" /* line 2305 | transform */
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0xf0(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movss 4(%eax), %xmm6\n"
        "movss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movss 4(%eax), %xmm0\n"
        "movss %xmm0, -0xec(%ebp)\n"
        "movss -0x10(%edi), %xmm0\n"
        "mulss -0xf0(%ebp), %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm0\n"
        "addss -0x90(%ebp), %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "addss -0x90(%ebp), %xmm0\n"
        "addss -0xec(%ebp), %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movl -0xb8(%ebp), %eax\n" /* line 2306 | transform */
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0xe8(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movss 8(%eax), %xmm5\n"
        "movss 8(%ecx), %xmm7\n"
        "movl -0x80(%ebp), %ecx\n"
        "movss 8(%ecx), %xmm0\n"
        "movss %xmm0, -0xe4(%ebp)\n"
        "movss -0x10(%edi), %xmm0\n"
        "mulss -0xe8(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        "mulss %xmm5, %xmm0\n"
        "addss -0x94(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm7, %xmm0\n"
        "addss -0x94(%ebp), %xmm0\n"
        "addss -0xe4(%ebp), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movl -0xb8(%ebp), %eax\n" /* line 2307 | transform */
        "movss 0xc(%eax), %xmm0\n"
        "movss %xmm0, -0xe0(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movss 0xc(%eax), %xmm3\n"
        "movl -0x84(%ebp), %ecx\n"
        "movss 0xc(%ecx), %xmm4\n"
        "movl -0x80(%ebp), %ebx\n" /* material */
        "movss 0xc(%ebx), %xmm0\n" /* material */
        "movss %xmm0, -0xdc(%ebp)\n"
        "movss -0x10(%edi), %xmm0\n"
        "mulss -0xe0(%ebp), %xmm0\n"
        "mulss %xmm3, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "mulss %xmm4, %xmm2\n"
        "addss %xmm1, %xmm2\n"
        "addss -0xdc(%ebp), %xmm2\n"
        "movss %xmm2, -0x98(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n" /* line 2310 */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x10c(%ebp)\n"
        "movss 4(%eax), %xmm1\n"
        "movss 8(%eax), %xmm2\n"
        "movss -0xf8(%ebp), %xmm0\n"
        "mulss -0x10c(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0xc8(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0xc8(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "addss -0xc8(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0xc4(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xc4(%ebp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "addss -0xc4(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0xf4(%ebp), %xmm0\n"
        "addss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movss -0xf0(%ebp), %xmm0\n" /* line 2311 */
        "mulss -0x10c(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm6\n"
        "addss %xmm0, %xmm6\n"
        "movss -0xc0(%ebp), %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movaps %xmm6, %xmm0\n"
        "addss -0xc0(%ebp), %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "movss -0xec(%ebp), %xmm0\n"
        "addss -0xa0(%ebp), %xmm0\n"
        "movss %xmm0, -0xa0(%ebp)\n"
        "movss -0xe8(%ebp), %xmm0\n" /* line 2312 */
        "mulss -0x10c(%ebp), %xmm0\n"
        "mulss %xmm1, %xmm5\n"
        "addss %xmm0, %xmm5\n"
        "mulss %xmm2, %xmm7\n"
        "addss %xmm5, %xmm7\n"
        "movss -0xe4(%ebp), %xmm0\n"
        "addss %xmm7, %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "movss -0xe0(%ebp), %xmm5\n" /* line 2313 */
        "mulss -0x10c(%ebp), %xmm5\n"
        "mulss %xmm1, %xmm3\n"
        "addss %xmm3, %xmm5\n"
        "mulss %xmm2, %xmm4\n"
        "addss %xmm4, %xmm5\n"
        "addss -0xdc(%ebp), %xmm5\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 2315 */
        "mulss -0xa0(%ebp), %xmm0\n"
        "movss -0x90(%ebp), %xmm1\n"
        "mulss %xmm5, %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n" /* delta */
        "movss -0x8c(%ebp), %xmm0\n" /* line 2316 */
        "mulss %xmm5, %xmm0\n"
        "movss -0x98(%ebp), %xmm1\n"
        "mulss -0x9c(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 2317 | delta */
        "movl %eax, (%esp)\n"
        "movss %xmm5, -0x108(%ebp)\n"
        "calll Vec2Normalize\n"
        "fstp %st(0)\n"
        "movss -0xb4(%ebp), %xmm0\n" /* line 2318 | invWidth */
        "mulss -0x20(%ebp), %xmm0\n" /* delta */
        "movss %xmm0, -0x20(%ebp)\n" /* delta */
        "movss -0xb0(%ebp), %xmm0\n" /* line 2319 | invHeight */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss -0x98(%ebp), %xmm0\n" /* line 86 */
        "mulss -0x20(%ebp), %xmm0\n" /* delta */
        "movss %xmm0, -0x30(%ebp)\n" /* offset */
        "movss -0x98(%ebp), %xmm0\n" /* line 87 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss -0x108(%ebp), %xmm5\n" /* line 86 */
        "movaps %xmm5, %xmm0\n"
        "mulss -0x20(%ebp), %xmm0\n" /* delta */
        "movss %xmm0, -0x28(%ebp)\n"
        "movaps %xmm5, %xmm0\n" /* line 87 */
        "mulss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl tess+370644, %edx\n" /* line 344 */
        "leal 4(%edx), %eax\n"
        "cmpl $0x154a, %eax\n"
        "jg .Lfdc5a6_000dceb2\n"
        "movl tess+370640, %ecx\n"
        "leal 6(%ecx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfdc5a6_000dcf2f\n"
        ".Lfdc5a6_000dceb2:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "movss %xmm5, -0x108(%ebp)\n" /* line 329 */
        "calll RB_EndSurface\n"
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "movss -0x108(%ebp), %xmm5\n"
        "je .Lfdc5a6_000dcf23\n"
        "movl tess+370640, %ecx\n" /* line 261 */
        "testl %ecx, %ecx\n"
        "jne .Lfdc5a6_000dcf08\n"
        "movl tess+370656, %edx\n"
        "testl %edx, %edx\n"
        "je .Lfdc5a6_000dcf1d\n"
        ".Lfdc5a6_000dcf08:\n"
        "movss %xmm5, -0x108(%ebp)\n" /* line 262 */
        "calll RB_EndSurface\n"
        "movss -0x108(%ebp), %xmm5\n"
        ".Lfdc5a6_000dcf1d:\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        ".Lfdc5a6_000dcf23:\n"
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        ".Lfdc5a6_000dcf2f:\n"
        "addl $3, %edx\n" /* line 2324 */
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2325 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 2(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2326 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2327 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2328 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 8(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2329 */
        "addl $1, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 0xa(%eax, %edx, 2)\n"
        "addl $6, tess+370640\n" /* line 2330 */
        "movl -0xa8(%ebp), %ecx\n" /* line 2332 */
        "addl $0xc, %ecx\n"
        "movl %ecx, -0xac(%ebp)\n" /* from */
        "movss -0x90(%ebp), %xmm1\n"
        "subss -0x2c(%ebp), %xmm1\n"
        "movss -0x8c(%ebp), %xmm0\n"
        "subss -0x30(%ebp), %xmm0\n" /* offset */
        "movl tess+370644, %edx\n" /* vertIndex */
        /* { scope 2: from */
        "movl imp_r_rendererInUse, %ebx\n" /* line 392 */
        "movl (%ebx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdc5a6_000dc710\n"
        "leal (%edx, %edx, 8), %edx\n" /* line 394 | v */
        "shll $2, %edx\n" /* v */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "divss -0x98(%ebp), %xmm0\n" /* line 191 */
        "movss %xmm0, tess(%edx)\n"
        "divss -0x98(%ebp), %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%eax)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 193 */
        "divss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "leal 0xc(%eax), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, 0xc(%eax)\n"
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %edx\n" /* line 606 */
        "movl -0xa8(%ebp), %ecx\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, tess+8(%edx)\n"
        "addl $tess, %edx\n" /* line 397 */
        "movl %esi, 0xc(%edx)\n" /* line 30 */
        "movl %esi, 0x10(%edx)\n" /* line 31 */
        "jmp .Lfdc5a6_000dc79b\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfdc5a6_000dd070:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "divss -0x98(%ebp), %xmm0\n" /* line 191 */
        "movss %xmm0, tess(%eax)\n"
        "divss -0x98(%ebp), %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%edx)\n"
        "movss -0x94(%ebp), %xmm0\n" /* line 193 */
        "divss -0x98(%ebp), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0xac(%ebp), %ecx\n" /* from */
        "movl (%ecx), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdc5a6_000dca2f\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfdc5a6_000dd0ef:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "divss %xmm5, %xmm0\n" /* line 191 */
        "movss %xmm0, tess(%eax)\n"
        "divss %xmm5, %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%edx)\n"
        "movss -0xa4(%ebp), %xmm0\n" /* line 193 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl (%ebx), %edx\n" /* from */
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdc5a6_000dc94b\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfdc5a6_000dd15c:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "divss %xmm5, %xmm0\n" /* line 191 */
        "movss %xmm0, tess(%eax)\n"
        "divss %xmm5, %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%edx)\n"
        "movss -0xa4(%ebp), %xmm0\n" /* line 193 */
        "divss %xmm5, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl 0xc(%edi), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdc5a6_000dc875\n"
        /* } scope */
        /* { scope 2: from */
        ".Lfdc5a6_000dd1ca:\n"
        "cmpl $3, tess+370624\n" /* line 300 */
        "jne .Lfdc5a6_000dc5d3\n"
        "jmp .Lfdc5a6_000dc607\n"
    );
}

/* line 2347 */
static void RB_DrawLinesCmd(GfxRenderCommandExecState *execState)
{
    byte *cmd = *(byte **)execState;
    int count = *(short *)(cmd + 4);
    int width = *(short *)(cmd + 6);
    const GfxPointVertex *verts = (const GfxPointVertex *)(cmd + 8);

    if (*(byte *)((char *)&backEnd + 1213)) {
        /* 2D mode */
        RB_DrawLines2D(count, width, verts);
    } else {
        /* 3D mode */
        RB_DrawLines3D(count, width, verts, 1);
    }

    cmd = *(byte **)execState;
    *(byte **)execState = cmd + *(unsigned short *)(cmd + 2);
}

/* line 1298 */
static __attribute__((naked))
void RB_StencilPlanesCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1298 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1306 | execState */
        "movl (%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* cmd */
        "movl imp_rgp, %eax\n"
        "movl 0x1034(%eax), %ebx\n"
        /* { scope 2 */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfdd250_000dd8d0\n"
        ".Lfdd250_000dd278:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdd250_000dd6e5\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdd250_000dd6e5\n"
        ".Lfdd250_000dd292:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdd250_000dd2aa:\n"
        "movl $0xffffffff, -0x1c(%ebp)\n" /* line 1311 | white */
        "movl -0x34(%ebp), %edx\n" /* line 1312 | cmd */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfdd250_000dd6be\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* planeIndex */
        "movl tess+370644, %edx\n"
        ".Lfdd250_000dd2cf:\n"
        "leal 4(%edx), %eax\n" /* line 344 */
        "cmpl $0x154a, %eax\n"
        "jg .Lfdd250_000dd2e8\n"
        "movl tess+370640, %eax\n"
        "addl $6, %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfdd250_000dd344\n"
        ".Lfdd250_000dd2e8:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "je .Lfdd250_000dd8c5\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdd250_000dd6db\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdd250_000dd6db\n"
        ".Lfdd250_000dd338:\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %edx\n"
        ".Lfdd250_000dd344:\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 1316 */
        "movss 0xc(%ecx), %xmm1\n"
        "movaps %xmm1, %xmm2\n" /* line 1317 */
        "movl -0x34(%ebp), %eax\n" /* cmd */
        "subss 4(%eax), %xmm2\n"
        "movaps %xmm1, %xmm3\n" /* line 1318 */
        "xorps refEntIsInWorldSpace+48, %xmm3\n"
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd250_000dd6ef\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 2 */
        "movss %xmm3, tess(%edx)\n" /* line 447 */
        "movss %xmm3, 4(%eax)\n" /* line 448 */
        "movss %xmm2, 8(%eax)\n" /* line 449 */
        "movss %xmm1, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 403 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 2 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, tess(%eax)\n"
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, %ebx\n" /* line 193 */
        "movl %ebx, 8(%ecx)\n"
        /* } scope */
        "movl -0x1c(%ebp), %edi\n" /* line 606 | white */
        "movl %edi, tess+12(%eax)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 2 */
        "movl %esi, tess(%eax)\n" /* line 30 */
        "movl %esi, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 2 */
        "movl %ebx, 4(%edx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 2 */
        "movl %esi, 8(%ecx)\n" /* line 191 */
        "movl %ebx, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 1319 | vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd250_000dd75f\n"
        ".Lfdd250_000dd403:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm3, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss %xmm2, 8(%eax)\n" /* line 449 */
        "movss %xmm1, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 403 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %edi, tess+12(%eax)\n" /* line 606 */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 1320 | vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd250_000dd7e1\n"
        ".Lfdd250_000dd4b5:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm1, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss %xmm2, 8(%eax)\n" /* line 449 */
        "movss %xmm1, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 403 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %edi, tess+12(%eax)\n" /* line 606 */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 1321 | vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd250_000dd85c\n"
        ".Lfdd250_000dd567:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movss %xmm1, tess(%edx)\n" /* line 447 */
        "movss %xmm3, 4(%eax)\n" /* line 448 */
        "movss %xmm2, 8(%eax)\n" /* line 449 */
        "movss %xmm1, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %eax\n" /* line 403 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "movl %edi, tess+12(%eax)\n" /* line 606 */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 3 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 3 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 3 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdd250_000dd5fe:\n"
        "movl tess+370644, %ecx\n" /* line 1323 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, (%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 1324 */
        "addl $1, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 2(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 1325 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 1326 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 1327 */
        "addl $3, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 8(%eax, %edx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 1328 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 0xa(%eax, %edx, 2)\n"
        "movl tess+370644, %eax\n" /* line 1330 */
        "addl $4, %eax\n"
        "movl %eax, %edx\n"
        "movl %eax, tess+370644\n"
        "addl $6, tess+370640\n" /* line 1331 */
        "addl $1, -0x30(%ebp)\n" /* line 1312 | planeIndex */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %ecx\n" /* planeIndex */
        "movl -0x34(%ebp), %eax\n" /* cmd */
        "cmpl %ecx, 8(%eax)\n"
        "jg .Lfdd250_000dd2cf\n"
        ".Lfdd250_000dd6be:\n"
        "calll RB_EndSurface\n" /* line 1333 */
        "movl 8(%ebp), %eax\n" /* line 169 | execState */
        "movl (%eax), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl 8(%ebp), %edx\n" /* execState */
        "movl %eax, (%edx)\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 1336 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfdd250_000dd6db:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdd250_000dd338\n"
        /* { scope 2 */
        ".Lfdd250_000dd6e5:\n"
        "calll RB_EndSurface\n"
        "jmp .Lfdd250_000dd292\n"
        /* } scope */
        ".Lfdd250_000dd6ef:\n"
        "movaps %xmm3, %xmm0\n" /* line 394 | y */
        "divss %xmm1, %xmm0\n" /* y */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 2 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm0, 4(%edx)\n" /* line 192 */
        "movaps %xmm2, %xmm0\n" /* line 193 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 2 */
        "xorl %esi, %esi\n" /* line 191 */
        "movl %esi, 0xc(%edx)\n"
        "movl %esi, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x1c(%ebp), %edi\n" /* white */
        "movl %edi, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl %esi, 0xc(%eax)\n" /* line 30 */
        "movl %esi, 0x10(%eax)\n" /* line 31 */
        "movl tess+370644, %edx\n" /* line 1319 | vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd250_000dd403\n"
        ".Lfdd250_000dd75f:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movaps %xmm3, %xmm0\n" /* line 191 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, tess(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 192 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm2, %xmm0\n" /* line 193 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl %edi, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 1320 | vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd250_000dd4b5\n"
        ".Lfdd250_000dd7e1:\n"
        "movaps %xmm1, %xmm0\n" /* line 394 | y */
        "divss %xmm1, %xmm0\n" /* y */
        "leal (%edx, %edx, 8), %eax\n"
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm0, 4(%edx)\n" /* line 192 */
        "movaps %xmm2, %xmm0\n" /* line 193 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl %edi, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 1321 | vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 2 */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd250_000dd567\n"
        ".Lfdd250_000dd85c:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 */
        "shll $2, %eax\n"
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 3 */
        "movaps %xmm1, %xmm0\n" /* line 191 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, tess(%eax)\n"
        "movaps %xmm3, %xmm0\n" /* line 192 */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "divss %xmm1, %xmm2\n" /* line 193 */
        "movss %xmm2, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 3 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl %edi, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdd250_000dd5fe\n"
        ".Lfdd250_000dd8c5:\n"
        "movl tess+370644, %edx\n"
        "jmp .Lfdd250_000dd344\n"
        /* } scope */
        /* { scope 2 */
        ".Lfdd250_000dd8d0:\n"
        "cmpl $3, tess+370624\n" /* line 300 */
        "jne .Lfdd250_000dd278\n"
        "jmp .Lfdd250_000dd2aa\n"
    );
}

/* line 2211 */
static __attribute__((naked))
void RB_DrawPointsCmd(GfxRenderCommandExecState *execState)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2211 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1: pointIndex, v, size, identity, ... */
        "movl 8(%ebp), %eax\n" /* line 2215 | execState */
        "movl (%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n" /* cmd */
        "cmpb $0, backEnd+1213\n" /* line 2217 */
        "je .Lfdd8e2_000dde4e\n"
        "movl imp_rgp, %eax\n"
        "movl 0x1038(%eax), %ebx\n" /* material */
        /* { scope 2 */
        /* { scope 3: from */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfdd8e2_000de88e\n"
        ".Lfdd8e2_000dd91d:\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdd8e2_000de6c9\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfdd8e2_000de6c9\n"
        ".Lfdd8e2_000dd937:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdd8e2_000dd94f:\n"
        "movl -0x98(%ebp), %edx\n" /* line 2134 | cmd */
        "movswl 6(%edx), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, -0x8c(%ebp)\n" /* size */
        "addl $8, %edx\n" /* line 2135 */
        "movl %edx, -0x90(%ebp)\n" /* v */
        "movl -0x98(%ebp), %eax\n" /* cmd */
        "cmpw $0, 4(%eax)\n"
        "jle .Lfdd8e2_000dde36\n"
        "movl $0, -0x94(%ebp)\n" /* pointIndex */
        "movl tess+370644, %edx\n"
        "movl %eax, %ebx\n" /* material */
        "addl $0xc, %ebx\n" /* material */
        ".Lfdd8e2_000dd99c:\n"
        "leal 4(%edx), %eax\n" /* line 344 */
        "cmpl $0x154a, %eax\n"
        "jg .Lfdd8e2_000dd9b6\n"
        "movl tess+370640, %ecx\n"
        "leal 6(%ecx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfdd8e2_000dda19\n"
        ".Lfdd8e2_000dd9b6:\n"
        "movl tess+370636, %esi\n" /* line 327 */
        "calll RB_EndSurface\n" /* line 329 */
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %esi\n" /* line 310 */
        "je .Lfdd8e2_000de86c\n"
        "movl tess+370640, %eax\n" /* line 261 */
        "testl %eax, %eax\n"
        "jne .Lfdd8e2_000de6b5\n"
        "movl tess+370656, %edi\n"
        "testl %edi, %edi\n"
        "jne .Lfdd8e2_000de6b5\n"
        ".Lfdd8e2_000dda07:\n"
        "movl %esi, tess+370636\n" /* line 313 */
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        ".Lfdd8e2_000dda19:\n"
        "addl $1, %edx\n" /* line 2138 */
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2139 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 2(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2140 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2141 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2142 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 8(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2143 */
        "addl $3, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 0xa(%eax, %edx, 2)\n"
        "addl $6, tess+370640\n" /* line 2144 */
        "movl -0x90(%ebp), %edx\n" /* line 2146 | v, vertIndex */
        "addl $0xc, %edx\n" /* vertIndex */
        "movl %edx, -0x88(%ebp)\n" /* vertIndex, from */
        "movl -0x90(%ebp), %edi\n" /* line 2211 | v */
        "addl $8, %edi\n" /* v */
        "movl 4(%ebx), %ecx\n" /* line 2146 | material */
        "movss (%ebx), %xmm1\n" /* material */
        "subss -0x8c(%ebp), %xmm1\n" /* size */
        "movss -4(%ebx), %xmm0\n" /* material */
        "subss -0x8c(%ebp), %xmm0\n" /* size */
        "movl tess+370644, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de7ea\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, %esi\n" /* line 450 */
        "movl %esi, 0xc(%eax)\n"
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl %esi, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* { scope 4 */
        "movl 8(%ebx), %eax\n" /* line 606 | from */
        "movl %eax, tess+12(%ecx)\n"
        /* } scope */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl %esi, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdd8e2_000ddb81:\n"
        "movl (%edi), %ecx\n" /* line 2147 */
        "movss -0x8c(%ebp), %xmm1\n" /* size */
        "addss (%ebx), %xmm1\n" /* material */
        "movss -4(%ebx), %xmm0\n" /* material */
        "subss -0x8c(%ebp), %xmm0\n" /* size */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de78d\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0x88(%ebp), %esi\n" /* line 606 | from */
        "movl (%esi), %eax\n"
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdd8e2_000ddc56:\n"
        "movl (%edi), %ecx\n" /* line 2148 */
        "movss -0x8c(%ebp), %xmm1\n" /* size */
        "addss (%ebx), %xmm1\n" /* material */
        "movss -0x8c(%ebp), %xmm0\n" /* size */
        "addss -4(%ebx), %xmm0\n" /* material */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de730\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0x88(%ebp), %esi\n" /* line 606 | from */
        "movl (%esi), %eax\n"
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdd8e2_000ddd2b:\n"
        "movl (%edi), %ecx\n" /* line 2149 */
        "movss (%ebx), %xmm0\n" /* material */
        "subss -0x8c(%ebp), %xmm0\n" /* size */
        "movss -0x8c(%ebp), %xmm1\n" /* size */
        "addss -4(%ebx), %xmm1\n" /* material */
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de6d3\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm1, tess(%edx)\n" /* line 447 */
        "movss %xmm0, 4(%eax)\n" /* line 448 */
        "movl %ecx, 8(%eax)\n" /* line 449 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl -0x88(%ebp), %esi\n" /* line 606 | from */
        "movl (%esi), %eax\n"
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdd8e2_000dde00:\n"
        "movl tess+370644, %edx\n" /* line 2150 */
        "addl $4, %edx\n"
        "movl %edx, tess+370644\n"
        "addl $1, -0x94(%ebp)\n" /* line 2135 | pointIndex */
        "addl $0x10, -0x90(%ebp)\n" /* v */
        "addl $0x10, %ebx\n" /* material */
        "movl -0x98(%ebp), %ecx\n" /* cmd */
        "movswl 4(%ecx), %eax\n"
        "cmpl -0x94(%ebp), %eax\n" /* pointIndex */
        "jg .Lfdd8e2_000dd99c\n"
        /* } scope */
        ".Lfdd8e2_000dde36:\n"
        "movl 8(%ebp), %esi\n" /* line 169 | execState */
        "movl (%esi), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 2223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pointIndex, v, size, identity, ... */
        /* { scope 2 */
        ".Lfdd8e2_000dde4e:\n"
        "movl imp_rgp, %eax\n" /* line 2135 */
        "movl 0x1040(%eax), %ebx\n" /* material */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: from */
        "cmpl tess+370620, %ebx\n" /* line 300 */
        "je .Lfdd8e2_000de8a0\n"
        ".Lfdd8e2_000dde65:\n"
        "movl tess+370640, %esi\n" /* line 261 */
        "testl %esi, %esi\n"
        "jne .Lfdd8e2_000de6bf\n"
        "movl tess+370656, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfdd8e2_000de6bf\n"
        ".Lfdd8e2_000dde81:\n"
        "movl $0x1f, 8(%esp)\n" /* line 303 */
        "movl $3, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll RB_BeginSurface\n"
        /* } scope */
        ".Lfdd8e2_000dde99:\n"
        "leal -0x58(%ebp), %ebx\n" /* line 2171 | identity, material */
        "movl %ebx, (%esp)\n" /* material */
        "calll MatrixIdentity44\n"
        "movl %ebx, (%esp)\n" /* line 2172 | material */
        "calll RB_SetProjectionMatrix\n"
        "movl %ebx, (%esp)\n" /* line 2173 | material */
        "calll RB_SetViewMatrix\n"
        "movl backEnd+968, %edx\n" /* line 2175 */
        "leal 0xc8(%edx), %esi\n"
        "movl %esi, -0x80(%ebp)\n" /* transform */
        "movl -0x98(%ebp), %ecx\n" /* line 2177 | cmd */
        "movswl 6(%ecx), %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movl imp_dxState, %eax\n"
        "cvtsi2ssl 0x209c(%eax), %xmm0\n"
        "movaps %xmm1, %xmm2\n"
        "divss %xmm0, %xmm2\n"
        "movss %xmm2, -0x7c(%ebp)\n" /* invWidth */
        "cvtsi2ssl 0x20a0(%eax), %xmm0\n" /* line 2178 */
        "divss %xmm0, %xmm1\n"
        "movss %xmm1, -0x78(%ebp)\n" /* invHeight */
        "movl %ecx, %edi\n" /* line 2179 | v */
        "addl $8, %edi\n" /* v */
        "cmpw $0, 4(%ecx)\n"
        "jle .Lfdd8e2_000de842\n"
        "leal 0xd8(%edx), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "leal 0xe8(%edx), %ecx\n"
        "movl %ecx, -0x60(%ebp)\n"
        "addl $0xf8, %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movl $0, -0x84(%ebp)\n" /* pointIndex */
        "movl tess+370644, %edx\n"
        "jmp .Lfdd8e2_000de233\n"
        /* { scope 3: from */
        ".Lfdd8e2_000ddf3b:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm2, tess(%edx)\n" /* line 447 */
        "movss %xmm6, 4(%eax)\n" /* line 448 */
        "movss %xmm5, 8(%eax)\n" /* line 449 */
        "movss %xmm4, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, %esi\n" /* line 193 */
        "movl %esi, 8(%eax)\n"
        /* } scope */
        /* { scope 4 */
        "movl 0xc(%edi), %eax\n" /* line 606 */
        "movl %eax, tess+12(%ecx)\n"
        /* } scope */
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl %esi, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl %esi, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movss -0x74(%ebp), %xmm1\n" /* line 2200 */
        "addss -0x6c(%ebp), %xmm1\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de544\n"
        ".Lfdd8e2_000ddff3:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm2, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss %xmm5, 8(%eax)\n" /* line 449 */
        "movss %xmm4, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl (%ebx), %eax\n" /* line 606 | from */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movss -0x70(%ebp), %xmm3\n" /* line 2201 */
        "addss -0x68(%ebp), %xmm3\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de5cf\n"
        ".Lfdd8e2_000de0b1:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm3, tess(%edx)\n" /* line 447 */
        "movss %xmm1, 4(%eax)\n" /* line 448 */
        "movss %xmm5, 8(%eax)\n" /* line 449 */
        "movss %xmm4, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl (%ebx), %eax\n" /* line 606 | from */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0x3f800000, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 2202 | vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfdd8e2_000de650\n"
        ".Lfdd8e2_000de165:\n"
        "shll $6, %edx\n" /* line 402 */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movss %xmm3, tess(%edx)\n" /* line 447 */
        "movss %xmm6, 4(%eax)\n" /* line 448 */
        "movss %xmm5, 8(%eax)\n" /* line 449 */
        "movss %xmm4, 0xc(%eax)\n" /* line 450 */
        /* } scope */
        "leal 0x10(%edx), %ecx\n" /* line 403 */
        "leal tess(%ecx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0, tess(%ecx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0x3f800000, 8(%eax)\n" /* line 193 */
        /* } scope */
        "movl (%ebx), %eax\n" /* line 606 | from */
        "movl %eax, tess+12(%ecx)\n"
        "leal 0x20(%edx), %eax\n" /* line 405 */
        "leal tess(%eax), %ecx\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, tess(%eax)\n" /* line 30 */
        "movl $0, 4(%ecx)\n" /* line 31 */
        /* } scope */
        "addl $tess+48, %edx\n" /* line 406 */
        "leal 4(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movl $0x3f800000, 4(%edx)\n" /* line 191 */
        "movl $0, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        "leal 8(%ecx), %eax\n" /* line 407 | v */
        /* { scope 4 */
        "movl $0, 8(%ecx)\n" /* line 191 */
        "movl $0x3f800000, 4(%eax)\n" /* line 192 */
        "movl $0, 8(%eax)\n" /* line 193 */
        /* } scope */
        /* } scope */
        ".Lfdd8e2_000de1fe:\n"
        "movl tess+370644, %eax\n" /* line 2203 */
        "addl $4, %eax\n"
        "movl %eax, %edx\n"
        "movl %eax, tess+370644\n"
        "addl $1, -0x84(%ebp)\n" /* line 2179 | pointIndex */
        "addl $0x10, %edi\n" /* v */
        "movl -0x98(%ebp), %ecx\n" /* cmd */
        "movswl 4(%ecx), %eax\n"
        "cmpl %eax, -0x84(%ebp)\n" /* pointIndex */
        "jge .Lfdd8e2_000de842\n"
        "movl -0x64(%ebp), %eax\n"
        "movl -0x60(%ebp), %ecx\n"
        ".Lfdd8e2_000de233:\n"
        "movss (%edi), %xmm3\n" /* line 2181 | v */
        "movss 4(%edi), %xmm1\n" /* v */
        "movss 8(%edi), %xmm2\n" /* v */
        "movaps %xmm3, %xmm0\n"
        "movl -0x80(%ebp), %esi\n" /* transform */
        "mulss (%esi), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        "mulss (%eax), %xmm0\n"
        "addss -0x70(%ebp), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss (%ecx), %xmm0\n"
        "addss -0x70(%ebp), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "movl -0x5c(%ebp), %esi\n"
        "addss (%esi), %xmm0\n"
        "movss %xmm0, -0x70(%ebp)\n"
        "movaps %xmm3, %xmm0\n" /* line 2182 */
        "movl -0x80(%ebp), %eax\n" /* transform */
        "mulss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        "movl -0x64(%ebp), %eax\n"
        "mulss 4(%eax), %xmm0\n"
        "addss -0x74(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 4(%ecx), %xmm0\n"
        "addss -0x74(%ebp), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "addss 4(%esi), %xmm0\n"
        "movss %xmm0, -0x74(%ebp)\n"
        "movaps %xmm3, %xmm5\n" /* line 2183 */
        "movl -0x80(%ebp), %ecx\n" /* transform */
        "mulss 8(%ecx), %xmm5\n"
        "movaps %xmm1, %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movaps %xmm2, %xmm0\n"
        "movl -0x60(%ebp), %esi\n"
        "mulss 8(%esi), %xmm0\n"
        "addss %xmm0, %xmm5\n"
        "movl -0x5c(%ebp), %eax\n"
        "addss 8(%eax), %xmm5\n"
        "movaps %xmm3, %xmm4\n" /* line 2184 */
        "mulss 0xc(%ecx), %xmm4\n"
        "movl -0x64(%ebp), %ecx\n"
        "mulss 0xc(%ecx), %xmm1\n"
        "addss %xmm1, %xmm4\n"
        "mulss 0xc(%esi), %xmm2\n"
        "addss %xmm2, %xmm4\n"
        "addss 0xc(%eax), %xmm4\n"
        "movss -0x7c(%ebp), %xmm0\n" /* line 2186 | invWidth */
        "mulss %xmm4, %xmm0\n"
        "movss %xmm0, -0x68(%ebp)\n"
        "movss -0x78(%ebp), %xmm1\n" /* line 2187 | invHeight */
        "mulss %xmm4, %xmm1\n"
        "movss %xmm1, -0x6c(%ebp)\n"
        "movaps %xmm4, %xmm0\n" /* line 2188 */
        "mulss lit4_002ed670, %xmm0\n" /* -0.0010000000474974513f */
        "addss %xmm0, %xmm5\n"
        "leal 4(%edx), %eax\n" /* line 344 */
        "cmpl $0x154a, %eax\n"
        "jg .Lfdd8e2_000de358\n"
        "movl tess+370640, %ecx\n"
        "leal 6(%ecx), %eax\n"
        "cmpl $0x100000, %eax\n"
        "jle .Lfdd8e2_000de3f8\n"
        ".Lfdd8e2_000de358:\n"
        "movl tess+370636, %ebx\n" /* line 327 */
        "movss %xmm4, -0xa8(%ebp)\n" /* line 329 */
        "movss %xmm5, -0xb8(%ebp)\n"
        "calll RB_EndSurface\n"
        "movl tess+370628, %eax\n" /* line 331 */
        "movl %eax, 8(%esp)\n"
        "movl tess+370624, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl tess+370620, %eax\n"
        "movl %eax, (%esp)\n"
        "calll RB_BeginSurface\n"
        "cmpl tess+370636, %ebx\n" /* line 310 */
        "movss -0xa8(%ebp), %xmm4\n"
        "movss -0xb8(%ebp), %xmm5\n"
        "je .Lfdd8e2_000de87d\n"
        "movl tess+370640, %edx\n" /* line 261 */
        "testl %edx, %edx\n"
        "jne .Lfdd8e2_000de3c1\n"
        "movl tess+370656, %eax\n"
        "testl %eax, %eax\n"
        "je .Lfdd8e2_000de3e6\n"
        ".Lfdd8e2_000de3c1:\n"
        "movss %xmm4, -0xa8(%ebp)\n" /* line 262 */
        "movss %xmm5, -0xb8(%ebp)\n"
        "calll RB_EndSurface\n"
        "movss -0xb8(%ebp), %xmm5\n"
        "movss -0xa8(%ebp), %xmm4\n"
        ".Lfdd8e2_000de3e6:\n"
        "movl %ebx, tess+370636\n" /* line 313 */
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        ".Lfdd8e2_000de3f8:\n"
        "addl $3, %edx\n" /* line 2191 */
        "movl tess+370608, %eax\n"
        "movw %dx, (%eax, %ecx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2192 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 2(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2193 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 4(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2194 */
        "addl $2, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 6(%eax, %edx, 2)\n"
        "movl tess+370644, %ecx\n" /* line 2195 */
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 8(%eax, %edx, 2)\n"
        "movzwl tess+370644, %ecx\n" /* line 2196 */
        "addl $1, %ecx\n"
        "movl tess+370640, %edx\n"
        "movl tess+370608, %eax\n"
        "movw %cx, 0xa(%eax, %edx, 2)\n"
        "addl $6, tess+370640\n" /* line 2197 */
        "leal 0xc(%edi), %ebx\n" /* line 2199 | v, material */
        "movss -0x74(%ebp), %xmm6\n"
        "subss -0x6c(%ebp), %xmm6\n"
        "movss -0x70(%ebp), %xmm2\n"
        "subss -0x68(%ebp), %xmm2\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd8e2_000ddf3b\n"
        "leal (%edx, %edx, 8), %edx\n" /* line 394 | v */
        "shll $2, %edx\n" /* v */
        "leal tess(%edx), %eax\n" /* v */
        /* { scope 4 */
        "movaps %xmm2, %xmm0\n" /* line 191 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, tess(%edx)\n"
        "movaps %xmm6, %xmm0\n" /* line 192 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%eax)\n"
        "movaps %xmm5, %xmm0\n" /* line 193 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, 8(%eax)\n"
        /* } scope */
        "leal 0xc(%eax), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%eax)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %edx\n" /* line 606 */
        "movl 0xc(%edi), %eax\n"
        "movl %eax, tess+8(%edx)\n"
        "addl $tess, %edx\n" /* line 397 */
        "movl $0, 0xc(%edx)\n" /* line 30 */
        "movl $0, 0x10(%edx)\n" /* line 31 */
        /* } scope */
        "movss -0x74(%ebp), %xmm1\n" /* line 2200 */
        "addss -0x6c(%ebp), %xmm1\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $1, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd8e2_000ddff3\n"
        ".Lfdd8e2_000de544:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "divss %xmm4, %xmm2\n" /* line 191 */
        "movss %xmm2, tess(%eax)\n"
        "movaps %xmm1, %xmm0\n" /* line 192 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm5, %xmm0\n" /* line 193 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl (%ebx), %edx\n" /* from */
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        /* } scope */
        "movss -0x70(%ebp), %xmm3\n" /* line 2201 */
        "addss -0x68(%ebp), %xmm3\n"
        "movl tess+370644, %edx\n" /* vertIndex */
        "addl $2, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %ecx\n" /* line 392 */
        "movl (%ecx), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd8e2_000de0b1\n"
        ".Lfdd8e2_000de5cf:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movaps %xmm3, %xmm0\n" /* line 191 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, tess(%eax)\n"
        "divss %xmm4, %xmm1\n" /* line 192 */
        "movss %xmm1, 4(%edx)\n"
        "movaps %xmm5, %xmm0\n" /* line 193 */
        "divss %xmm4, %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl (%ebx), %edx\n" /* from */
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        /* } scope */
        "movl tess+370644, %edx\n" /* line 2202 | vertIndex */
        "addl $3, %edx\n" /* vertIndex */
        /* { scope 3: from */
        "movl imp_r_rendererInUse, %esi\n" /* line 392 */
        "movl (%esi), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfdd8e2_000de165\n"
        ".Lfdd8e2_000de650:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "divss %xmm4, %xmm3\n" /* line 191 */
        "movss %xmm3, tess(%eax)\n"
        "divss %xmm4, %xmm6\n" /* line 192 */
        "movss %xmm6, 4(%edx)\n"
        "divss %xmm4, %xmm5\n" /* line 193 */
        "movss %xmm5, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl (%ebx), %edx\n" /* from */
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdd8e2_000de1fe\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfdd8e2_000de6b5:\n"
        "calll RB_EndSurface\n" /* line 262 */
        "jmp .Lfdd8e2_000dda07\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3: from */
        ".Lfdd8e2_000de6bf:\n"
        "calll RB_EndSurface\n"
        "jmp .Lfdd8e2_000dde81\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: from */
        ".Lfdd8e2_000de6c9:\n"
        "calll RB_EndSurface\n"
        "jmp .Lfdd8e2_000dd937\n"
        /* } scope */
        /* { scope 3: from */
        ".Lfdd8e2_000de6d3:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm1, tess(%eax)\n" /* line 191 */
        "movss %xmm0, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x88(%ebp), %ecx\n" /* from */
        "movl (%ecx), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdd8e2_000dde00\n"
        /* } scope */
        /* { scope 3: from */
        ".Lfdd8e2_000de730:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x88(%ebp), %ecx\n" /* from */
        "movl (%ecx), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0x3f800000, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdd8e2_000ddd2b\n"
        /* } scope */
        /* { scope 3: from */
        ".Lfdd8e2_000de78d:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl -0x88(%ebp), %ecx\n" /* from */
        "movl (%ecx), %edx\n"
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0x3f800000, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdd8e2_000ddc56\n"
        /* } scope */
        /* { scope 3: from */
        ".Lfdd8e2_000de7ea:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 394 | v */
        "shll $2, %eax\n" /* v */
        "leal tess(%eax), %edx\n" /* v */
        /* { scope 4 */
        "movss %xmm0, tess(%eax)\n" /* line 191 */
        "movss %xmm1, 4(%edx)\n" /* line 192 */
        "movl %ecx, 8(%edx)\n" /* line 193 */
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 395 | v */
        /* { scope 4 */
        "movl $0, 0xc(%edx)\n" /* line 191 */
        "movl $0, 4(%ecx)\n" /* line 192 */
        "movl $0x3f800000, 8(%ecx)\n" /* line 193 */
        /* } scope */
        "addl $0x10, %eax\n" /* line 606 */
        "movl 8(%ebx), %edx\n" /* from */
        "movl %edx, tess+8(%eax)\n"
        "addl $tess, %eax\n" /* line 397 */
        "movl $0, 0xc(%eax)\n" /* line 30 */
        "movl $0, 0x10(%eax)\n" /* line 31 */
        "jmp .Lfdd8e2_000ddb81\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lfdd8e2_000de842:\n"
        "calll RB_EndSurface\n" /* line 2205 */
        "movl backEnd+968, %eax\n" /* line 2207 */
        "movl %eax, (%esp)\n"
        "calll RB_SetMatricesForView\n"
        /* } scope */
        "movl 8(%ebp), %esi\n" /* line 169 | execState */
        "movl (%esi), %edx\n"
        "movzwl 2(%edx), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%esi)\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 2223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfdd8e2_000de86c:\n"
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        "jmp .Lfdd8e2_000dda19\n"
        ".Lfdd8e2_000de87d:\n"
        "movl tess+370644, %edx\n"
        "movl tess+370640, %ecx\n"
        "jmp .Lfdd8e2_000de3f8\n"
        /* { scope 1: pointIndex, v, size, identity, ... */
        /* { scope 2 */
        /* { scope 3: from */
        ".Lfdd8e2_000de88e:\n"
        "cmpl $3, tess+370624\n" /* line 300 */
        "jne .Lfdd8e2_000dd91d\n"
        "jmp .Lfdd8e2_000dd94f\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: from */
        ".Lfdd8e2_000de8a0:\n"
        "cmpl $3, tess+370624\n"
        "jne .Lfdd8e2_000dde65\n"
        "jmp .Lfdd8e2_000dde99\n"
    );
}
