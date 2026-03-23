/* ASM dump from: r_init.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_init.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>
#include <stdarg.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/universal/com_math.h"
 */

extern int alwaysfails; /* 0x0 */
extern int g_disableRendering; /* 0x0 */
extern struct DxGlobals dx; /* 0x0 */
extern struct r_global_permanent_t rgp; /* 0x0 */
extern struct r_globals_t rg; /* 0x0 */
extern refimport_t ri; /* 0x0 */
extern vidConfig_t vidConfig; /* 0x0 */
extern const char * DXGetErrorDescription9A(HRESULT hr);
extern void Material_FinishLoading(void);
extern void R_AddCmdTouchAllImages(void);
extern void R_InitImages(void);
extern void Material_Init(void);
extern int R_InitFonts(void);
extern void R_InitLightDefs(void);
extern void R_ClearFogs(void);
extern void R_InitDebug(void);
extern void * R_AllocStaticVertexBuffer(void *outBuf, int size);
extern void * R_AllocStaticIndexBuffer(void *outBuf, int size);
extern void R_FinishStaticVertexBuffer(void *buf);
extern void R_FinishStaticIndexBuffer(void *buf);
extern int rand(void);
extern void R_ShutdownRenderTargets(void);
extern void R_ShutdownStaticModelCache(void);
extern void R_FreeStaticVertexBuffer(void *buf);
extern void R_FreeStaticIndexBuffer(void *buf);
extern void WinSleep(int ms);
extern void R_ShutdownBackendData(void);
extern void R_ShutdownDebug(void);
extern void RB_SaveLightVisHistory(void);
extern void R_ShutdownLightDefs(void);
extern void R_ShutdownWorld(void);
extern void R_ShutdownFonts(void);
extern void R_ShutdownModels(void);
extern void Material_Shutdown(void);
extern void R_ShutdownImages(void);
extern void R_UnlockSkinnedCache(void);
extern void R_FlushStaticModelCache(void);
extern void R_UnregisterCmds(void);
extern void R_UnregisterDvars(void);
extern void RB_ClearAllStreamSources(void);
extern void R_EndDrawGroupLoop(int section, int viewIndex);
extern Bool Sys_IsMainThread(void);
extern void R_SyncRenderThread(void);
extern void RB_SetGammaRamp(const void *gammaTable);
extern double pow(double, double);
extern float floorf(float);
extern void R_EndDrawGroupSection(int section);
extern void R_IssueDrawGroups(void);

static vec2_t cornerTexCoords[4]; /* cornerTexCoords */
static const r_index_t quadIndices[6]; /* quadIndices */
refexport_t re; /* re */

void R_FatalInitError(const char *msg);
const char * R_ErrorDescription(HRESULT hr);
static void R_CreateParticleCloudBuffer(void);
static void R_ReleaseForShutdownOrReset(void);
static Bool R_DisplayModeLess(const _D3DDISPLAYMODE *mode0, const _D3DDISPLAYMODE *mode1);
void R_UpdateGpuSyncType(void);
void R_EndRegistration(void);
static void R_EndView(int viewIndex);
static void R_DoneRenderingViews(void);
static void R_TrackStatistics(trStatistics_t *stats);
refexport_t * GetRefAPI(int apiVersion, refimport_t *rimp);
void R_Error(errorParm_t errorLevel, const char *msg, ...);
void R_GammaCorrect(byte *buffer, int bufSize);
static void R_InitSystems(void);
void R_FatalLockError(HRESULT hr);
static void R_Shutdown(qboolean destroyWindow);
void R_SetColorMappings(void);
static Bool R_CreateForInitOrReset(void);
void R_BeginRegistration(vidConfig_t *vidConfigOut);
Bool R_RecoverLostDevice(void);
typedef unsigned char (*D3DDispModeCompFunc)(const _D3DDISPLAYMODE *, const _D3DDISPLAYMODE *);
void ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(_D3DDISPLAYMODE *first, int holeIndex, int len, _D3DDISPLAYMODE value, D3DDispModeCompFunc comp);
void ZSt16__insertion_sortIP15_D3DDISPLAYMODEPFhRKS0_S3_EEvT_S6_T0_(_D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, D3DDispModeCompFunc comp);
void ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_(_D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, int depth_limit, D3DDispModeCompFunc comp);

/* line 123 */
void R_FatalInitError(const char *msg)
{
    void (*printFunc)(int, const char *, ...) = *(void (**)(int, const char *, ...))&ri;
    printFunc(0, (const char *)"********** DirectX returned an unrecoverable error code during initialization  **********\n");
    printFunc(0, (const char *)"********** Initialization also happens while playing if DirectX loses a device **********\n");
    printFunc(0, (const char *)"********** Consult the readme for how to continue from this problem            **********\n");
    printFunc(0, "\n%s\n", msg);
    ((void (*)(void))*(void * *)((char *)&ri + 72))();
}

/* line 169 */
const char * R_ErrorDescription(HRESULT hr)
{
    return DXGetErrorDescription9A(hr);
}

/* line 629 */
/* line 629 — Create static vertex+index buffers for particle cloud rendering.
 * Generates 8x8x16 = 1024 particles, each with 4 vertices and 6 indices.
 * Vertices have randomized positions + corner texcoords. */
static void R_CreateParticleCloudBuffer(void)
{
    float *verts;
    unsigned short *indices;
    int xIter, yIter, zIter, corner;
    int vertexIndex = 0;

    verts = R_AllocStaticVertexBuffer((IDirect3DVertexBuffer9 **)((byte *)&dx + 11704), 0x14000);
    indices = R_AllocStaticIndexBuffer((IDirect3DIndexBuffer9 **)((byte *)&dx + 11708), 0x3000);

    for (xIter = 0; xIter < 8; xIter++) {
        float xBase = (float)xIter;
        int baseVertForX = xIter * 128; /* 8*16 particles per X slice, 4 verts each */

        for (yIter = 0; yIter < 8; yIter++) {
            float yBase = (float)yIter;

            for (zIter = 0; zIter < 16; zIter++) {
                /* Randomized particle position: map to [-1,1] cube */
                float px = ((float)rand() * 4.656612873077393e-10f + xBase) * 0.25f - 1.0f;
                float py = ((float)rand() * 4.656612873077393e-10f + yBase) * 0.25f - 1.0f;
                float pz = ((float)rand() * 4.656612873077393e-10f + (float)zIter) * 0.125f - 1.0f;

                /* 4 vertices per particle (billboard corners) */
                for (corner = 0; corner < 4; corner++) {
                    /* position (vec3) */
                    *verts++ = px;
                    *verts++ = py;
                    *verts++ = pz;
                    /* texcoord (vec2) from cornerTexCoords */
                    *verts++ = cornerTexCoords[corner][0];
                    *verts++ = cornerTexCoords[corner][1];
                }

                /* 6 indices per particle (2 triangles) from quadIndices template */
                {
                    int baseVert = (baseVertForX + zIter) * 4;
                    int qi;
                    for (qi = 0; qi < 6; qi++) {
                        *indices++ = (unsigned short)(baseVert + quadIndices[qi]);
                    }
                }
            }
            baseVertForX += 16; /* advance by particles in this Y row */
        }
    }

    R_FinishStaticIndexBuffer(*(void **)((byte *)&dx + 11708));
    R_FinishStaticVertexBuffer(*(void **)((byte *)&dx + 11704));
}

/* line 930 */
/* Helper: release a COM object and null the pointer */
static inline void R_SafeRelease(void **objPtr)
{
    void *obj = *objPtr;
    if (obj) {
        do {
            ((void (__attribute__((stdcall)) *)(void *))((*(void ***)obj)[2]))(obj);
            *objPtr = NULL;
        } while (*(int *)&alwaysfails);
    }
}

/* line 930 — Release all D3D resources for shutdown or device reset.
 * Releases swap chains, render targets, depth stencil, back buffer,
 * dynamic VB/IB lock slots, particle buffers, font surface, and sun flare textures. */
static void R_ReleaseForShutdownOrReset(void)
{
    byte *d = (byte *)&dx;
    int i;

    /* Release swap chain presentation surfaces */
    {
        int scCount = *(int *)(d + 11592);
        for (i = 0; i < scCount; i++) {
            void **psc = (void **)(d + 0x2d50 + i * 16);
            R_SafeRelease(psc);
        }
    }

    R_ShutdownRenderTargets();
    R_ShutdownStaticModelCache();

    /* Release depth stencil surface (dx+11656) */
    R_SafeRelease((void **)(d + 11656));

    /* Release back buffer surface (dx+11696) */
    R_SafeRelease((void **)(d + 11696));

    /* Release dynamic VB/IB lock slots (2 entries at dx+0x2d98, stride 12) */
    for (i = 0; i < 2; i++) {
        R_SafeRelease((void **)(d + 0x2d98 + i * 12));
    }

    /* Free shader cache buffer (dx+11728) */
    if (*(void **)(d + 11728)) {
        /* Call ri.Hunk_FreeTempMemory (ri+44) */
        ((void (*)(void *))*(void **)((byte *)&ri + 44))(*(void **)(d + 11728));
        *(void **)(d + 11728) = NULL;
        *(int *)(d + 11732) = 0;
    }

    /* Free particle cloud VB and IB */
    if (*(void **)(d + 11704)) {
        R_FreeStaticVertexBuffer(*(void **)(d + 11704));
        *(void **)(d + 11704) = NULL;
    }
    if (*(void **)(d + 11708)) {
        R_FreeStaticIndexBuffer(*(void **)(d + 11708));
        *(void **)(d + 11708) = NULL;
    }

    /* Release font surface (dx+11612) */
    R_SafeRelease((void **)(d + 11612));

    /* Release sun flare textures (4 views × 2 textures each) */
    {
        byte *sunFlare = (byte *)imp_sunFlareArray;
        int view;
        for (view = 0; view < 4; view++) {
            byte *viewBase = sunFlare + view * 0x30;
            int tex;
            for (tex = 0; tex < 2; tex++) {
                R_SafeRelease((void **)(viewBase + 0x24 + tex * 4));
            }
        }
    }
}

/* line 968 */
static Bool R_DisplayModeLess(const _D3DDISPLAYMODE *mode0, const _D3DDISPLAYMODE *mode1)
{
    if (mode0->Width > mode1->Width)
        return 0;
    if (mode0->Width < mode1->Width)
        return 1;
    if (mode0->Height > mode1->Height)
        return 0;
    if (mode0->Height < mode1->Height)
        return 1;
    return mode0->RefreshRate < mode1->RefreshRate;
}

/* line 1107 */
/* line 1107 — Create D3D device with retry logic. Uses register calling convention:
 * eax=hwnd, edx=behavior, ecx=d3dpp. Tries CreateDevice up to 20 times with 100ms
 * sleeps, falling back to adapter 0 if initial adapter fails. */
static HRESULT R_CreateDevice_impl(HWND hwnd, DWORD behavior, void *d3dpp)
{
    byte *d = (byte *)&dx;
    HRESULT hr;
    int attempt;

    for (;;) {
        /* Print "Creating D3D device..." */
        ((void (*)(int, const char *))*(void **)&ri)(0, "Creating D3D device...\n");

        for (attempt = 0; attempt < 20; attempt++) {
            /* IDirect3D9::CreateDevice (vtable[0x40/4] = index 16) */
            void *d3d9 = *(void **)(d + 4);
            void **vtable = *(void ***)d3d9;
            hr = ((HRESULT (__attribute__((stdcall)) *)(void *, int, int, HWND, DWORD, void *, void **))
                  vtable[0x40/4])(d3d9, *(int *)(d + 12), 1, hwnd, behavior, d3dpp, (void **)(d + 8));

            if (hr >= 0)
                return hr;

            WinSleep(100);
        }

        /* After 20 failures, try falling back to default adapter */
        if (*(int *)(d + 12) == 0)
            return hr; /* Already on adapter 0, give up */

        *(int *)(d + 12) = 0; /* Reset to default adapter and retry */
    }
}

/* Clean C version for WASM — no register calling convention */
static HRESULT R_CreateDevice(HWND hwnd, DWORD behavior, void *d3dpp)
{
    return R_CreateDevice_impl(hwnd, behavior, d3dpp);
}

/* line 1256 */
void R_UpdateGpuSyncType(void)
{
    if (*(byte *)(*(int *)(*(int *)imp_r_multiGpu) + 8)) {
        *(int *)((char *)&dx + 11296) = 0;
    } else {
        *(int *)((char *)&dx + 11296) = *(int *)(*(int *)(*(int *)imp_r_gpuSync) + 8);
    }
}

/* line 2011 */
void R_EndRegistration(void)
{
    Material_FinishLoading();
    R_AddCmdTouchAllImages();
}

/* line 2025 */
static void R_EndView(int viewIndex)
{
    R_EndDrawGroupLoop(4, viewIndex);
    R_EndDrawGroupSection(4);
}

/* line 2032 */
static void R_DoneRenderingViews(void)
{
    R_IssueDrawGroups();
}

/* line 2038 */
static void R_TrackStatistics(trStatistics_t *stats)
{
    *(trStatistics_t * *)((char *)&rg + 12664) = stats;
}

/* line 2097 — GetRefAPI
 * Renderer DLL entry point: copies refimport function table, fills refexport table
 * with all renderer API function pointers, and returns it to the engine. */
refexport_t * GetRefAPI(int apiVersion, refimport_t *rimp)
{
    typedef void (*ri_Printf_fn)(int, const char *, ...);

    memcpy(&ri, rimp, sizeof(ri));
    memset(&re, 0, sizeof(re));

    if (apiVersion != 59) {
        ((ri_Printf_fn)(*(void **)&ri))(0, "Mismatched REF_API_VERSION: expected %i, got %i\n", 59, apiVersion);
        return NULL;
    }

    /* Fill refexport function pointer table — using byte offsets to match original ASM layout */
    byte *r = (byte *)&re;
    #define RE(off, fn) *(void **)(r + off) = (void *)(fn)

    /* Core lifecycle (offsets 0-68) */
    RE(0,   R_Shutdown);
    RE(4,   R_BeginRegistration);
    RE(8,   imp_R_RegisterModel);
    RE(12,  imp_R_RegisterInlineModel);
    RE(16,  imp_Material_RegisterHandle);
    RE(20,  imp_R_RegisterRawImage);
    RE(24,  imp_Material_IsDefault);
    RE(28,  imp_R_LoadWorld);
    RE(32,  imp_R_GetWorldBounds);
    RE(36,  imp_R_FinishLoadingModels);
    RE(40,  imp_R_SetIgnorePrecacheErrors);
    RE(44,  imp_R_GetIgnorePrecacheErrors);
    RE(48,  imp_R_GetMinSpecImageMemory);
    RE(52,  imp_R_GetMaterialName);
    RE(56,  imp_R_GetMaterialSubimageCount);
    RE(60,  imp_R_IsMaterialRefractive);
    RE(64,  imp_R_GetFarPlaneDist);
    RE(68,  R_EndRegistration);

    /* Scene management (offsets 72-140) */
    RE(72,  imp_R_ClearScene);
    RE(76,  imp_R_DefaultVertexFrames);
    RE(80,  imp_R_AddPolyToScene);
    RE(84,  imp_R_AddLightToScene);
    RE(88,  imp_R_InterpretSunLightParseParams);
    RE(92,  imp_R_ResetSunLightParseParams);
    RE(96,  imp_R_SetCullDist);
    RE(100, imp_R_SetFog);
    RE(104, imp_R_SwitchFog);
    RE(108, imp_R_ArchiveFogState);
    RE(112, imp_R_ClearFogs);
    RE(116, imp_R_SetSunLightOverride);
    RE(120, imp_R_ResetSunLightOverride);
    RE(124, imp_R_RenderScene);
    RE(128, imp_R_BeginDelayedDrawing);
    RE(132, imp_R_EndDelayedDrawing);
    RE(136, imp_R_IssueDelayedDrawing);
    RE(140, imp_R_ClearFlares);

    /* 2D drawing (offsets 144-164) */
    RE(144, imp_R_AddCmdSetMaterialColor);
    RE(148, imp_R_AddCmdDrawStretchPic);
    RE(152, imp_R_AddCmdDrawStretchPicRotate);
    RE(156, imp_R_AddCmdDrawStretchRaw);
    RE(160, imp_R_AddCmdDrawQuadPic);
    RE(164, imp_R_AddCmdDrawSprite);

    /* Frame control (offsets 168-212) */
    RE(168, imp_R_BeginFrame);
    RE(172, imp_R_EndFrame);
    RE(176, imp_R_BeginDebugFrame);
    RE(180, imp_R_EndDebugFrame);
    RE(184, R_EndView);
    RE(188, R_DoneRenderingViews);
    RE(192, imp_R_AddCmdSaveScreen);
    RE(196, imp_R_AddCmdBlendSavedScreen);
    RE(200, imp_R_AddCmdClearScreen);
    RE(204, imp_R_AddCmdSetViewport);
    RE(208, imp_R_MarkFragments);
    RE(212, imp_R_ModelBounds);

    /* Statistics (offsets 216-220) */
    RE(216, R_TrackStatistics);
    RE(220, imp_R_PickMaterial);

    /* Font / image (offsets 224-248) */
    RE(224, imp_R_RegisterFont);
    RE(228, imp_R_ResetImageAllocations);
    RE(232, imp_R_FreeImageAllocations);
    RE(236, imp_R_BeginCubemapShot);
    RE(240, imp_R_EndCubemapShot);
    RE(244, imp_R_SaveCubemapShot);
    RE(248, imp_R_LightingFromCubemapShots);

    /* Debug (offsets 252-264) */
    RE(252, imp_R_LocateDebugStrings);
    RE(256, imp_R_LocateDebugLines);
    RE(260, imp_R_AddPlume);
    RE(264, imp_R_ShutdownDebug);

    /* Backend / text (offsets 268-348) */
    RE(268, imp_RB_UpdateColor);
    RE(272, imp_R_NormalizedTextScale);
    RE(276, imp_R_TextWidth);
    RE(280, imp_R_TextHeight);
    RE(284, imp_R_DrawText);
    RE(288, imp_R_AddCmdDrawTextInSpace);
    RE(292, imp_R_ConsoleTextWidth);
    RE(296, imp_R_DrawConsoleText);
    RE(300, imp_R_AddCmdDrawTextWithCursor);
    RE(304, imp_R_DObjGetSurfMaterials);
    RE(308, imp_R_DObjReplaceMaterial);
    RE(312, imp_R_ParseSunLight);
    RE(316, imp_Material_Duplicate);
    RE(320, imp_R_DuplicateFont);
    *(byte *)(r + 324) = 1; /* initialized flag */
    RE(328, imp_R_SyncRenderThread);
    RE(332, imp_R_AbortRenderCommands);
    RE(336, imp_RB_IsGpuFenceFinished);
    RE(340, imp_RB_AdaptiveGpuSyncWait);
    RE(344, imp_RB_GpuWaited);
    RE(348, imp_R_SetLodOrigin);

    #undef RE

    return &re;
}

/* line 2463 */
void R_Error(errorParm_t errorLevel, const char *msg, ...)
{
    char text[1024];
    va_list vargs;

    if (Sys_IsMainThread())
        R_SyncRenderThread();

    /* End scene if in progress */
    if (*(byte *)((char *)&dx + 11581)) {
        void *dev = *(void **)((char *)&dx + 8);
        void **vt = *(void ***)dev;
        ((int (*)(void *))vt[0xa8 / 4])(dev);
        *(byte *)((char *)&dx + 11581) = 0;
    }

    va_start(vargs, msg);
    vsnprintf(text, 0x3ff, msg, vargs);
    va_end(vargs);
    text[1023] = '\0';

    ((void (*)(int, const char *, ...))*(void **)((char *)&ri + 4))(errorLevel, "%s", text);
}

/* line 802 */
void R_GammaCorrect(byte *buffer, int bufSize)
{
    unsigned short gammaTable[256];
    float invGamma;
    int i;

    invGamma = 1.0f / *(float *)(*(int *)imp_r_gamma + 8);

    if (invGamma == 1.0f) {
        /* Identity gamma: table[i] = i | (i << 8) */
        for (i = 0; i < 256; i++)
            gammaTable[i] = (unsigned short)(i + (i << 8));
    } else {
        /* Compute gamma-corrected table */
        for (i = 0; i < 256; i++)
            gammaTable[i] = (unsigned short)(int)floorf((float)pow((double)(i / 255.0f), (double)invGamma) * 65535.0f + 0.5f);
    }

    /* Apply gamma table to buffer (16-bit table value / 257 → 8-bit) */
    for (i = 0; i < bufSize; i++)
        buffer[i] = (byte)(gammaTable[buffer[i]] / 257);
}

/* line 830 */
static void R_InitSystems(void)
{
    R_InitImages();
    Material_Init();
    R_InitFonts();
    *(int *)((char *)&rg + 4136) = 0;
    R_InitLightDefs();
    R_ClearFogs();
    R_InitDebug();
    *(char *)&rg = 1;
}

/* line 140 */
void R_FatalLockError(HRESULT hr)
{
    void (*printFunc)(int, const char *, ...) = *(void (**)(int, const char *, ...))&ri;
    printFunc(0, (const char *)"********** DirectX failed a call to lock a vertex buffer or an index buffer **********\n");
    printFunc(0, "********** error information:  %s\n", DXGetErrorDescription9A(hr));
    ((void (*)(void))*(void * *)((char *)&ri + 72))();
}

/* line 1920 */
/* line 1920 — Full renderer shutdown. Releases all subsystems, and if
 * destroyWindow is true, also releases the D3D device and IDirect3D9 objects. */
static void R_Shutdown(qboolean destroyWindow)
{
    byte *d = (byte *)&dx;

    *(byte *)&rg = 0; /* rg.registered = false */

    /* If device exists and in windowed mode, clear stream sources */
    if (*(void **)(d + 8)) {
        if (*(byte *)(d + 11580))
            RB_ClearAllStreamSources();
    }

    /* Shutdown all subsystems */
    R_ShutdownBackendData();
    R_ShutdownDebug();
    RB_SaveLightVisHistory();
    R_ShutdownLightDefs();
    R_ShutdownWorld();
    R_ShutdownFonts();
    R_ShutdownModels();
    Material_Shutdown();
    R_ShutdownImages();

    *(int *)((byte *)&rgp + 4252) = 0;
    R_UnlockSkinnedCache();
    R_FlushStaticModelCache();

    if (destroyWindow) {
        R_ReleaseForShutdownOrReset();

        /* Release swap chains in reverse order */
        while (*(int *)(d + 11592) > 0) {
            int idx = *(int *)(d + 11592) - 1;
            *(int *)(d + 11592) = idx;
            *(void **)(d + 11584 + idx * 16 + 12) = NULL;
        }

        /* Release D3D device (dx+8) */
        R_SafeRelease((void **)(d + 8));

        /* Release IDirect3D9 (dx+4) */
        R_SafeRelease((void **)(d + 4));

        R_UnregisterDvars();
    }

    R_UnregisterCmds();
}

/* line 789 */
void R_SetColorMappings(void)
{
    unsigned short gammaRamp[256];
    float invGamma;
    int i;

    if (!*(byte *)((char *)&vidConfig + 40))
        return;

    invGamma = 1.0f / *(float *)(*(int *)imp_r_gamma + 8);

    if (invGamma == 1.0f) {
        for (i = 0; i < 256; i++)
            gammaRamp[i] = (unsigned short)(i + (i << 8));
    } else {
        for (i = 0; i < 256; i++)
            gammaRamp[i] = (unsigned short)(int)floorf((float)pow((double)(i / 255.0f), (double)invGamma) * 65535.0f + 0.5f);
    }

    RB_SetGammaRamp(gammaRamp);
}

/* line 871 — R_CreateForInitOrReset
 * Creates D3D dynamic vertex/index buffers, allocates memory, initializes
 * particle cloud, sun flare array, and render state. Called during init and device reset. */
extern void R_InitRenderTargets(void);
extern void R_InitStaticModelCache(void);
extern void RB_SetInitialState(void);
extern const char *va(const char *fmt, ...);

/* Fatal D3D error handler: prints error info via ri function table, then calls ri.Error */
static void R_DxFatalError(const char *fmt, int size, HRESULT hr)
{
    typedef void (*ri_fn)(int, const char *, ...);
    typedef void (*ri_err_fn)(void);
    ri_fn Printf = *(ri_fn *)&ri;
    ri_err_fn Error = *(ri_err_fn *)((byte *)&ri + 72);
    const char *msg = va(fmt, size, DXGetErrorDescription9A(hr));
    Printf(0, "------- Initializing Renderer -------");
    Printf(0, "------- Renderer Initialization -------");
    Printf(0, "------- Server Initialization -------");
    Printf(0, "\n%s\n", msg);
    Error();
}

static Bool R_CreateForInitOrReset(void)
{
    typedef void (*ri_fn)(int, const char *, ...);
    typedef void *(*ri_alloc_fn)(int);
    ri_fn Printf = *(ri_fn *)&ri;
    ri_alloc_fn Hunk_Alloc = *(ri_alloc_fn *)((byte *)&ri + 32);
    byte *dxp = (byte *)(void *)&dx;
    int i;

    fprintf(stderr, "[R_CreateForInitOrReset] ENTERED, dxp=%p\n", dxp);
    Printf(0, "R_InitRenderTargets");
    R_InitRenderTargets();
    Printf(0, "R_InitStaticModelCache");
    R_InitStaticModelCache();
    Printf(0, "Dynamic buffers");

    /* Choose VB size based on renderer type */
    int isDx7 = (*(int *)(*(int *)imp_r_rendererInUse + 8) == 2);
    int vbSize = isDx7 ? 0x120000 : 0x200000;

    /* Create primary dynamic vertex buffer */
    *(int *)(dxp + 11688) = 0;
    *(int *)(dxp + 11692) = vbSize;
    void *d3dDevice = *(void **)(dxp + 8);
    void **vtable = *(void ***)d3dDevice;
    typedef HRESULT (*CreateVB_fn)(void *, int, int, int, int, void **, void *);
    HRESULT hr = ((CreateVB_fn)vtable[26])(d3dDevice, vbSize, 0x208, 0, 0, (void **)(dxp + 11696), NULL);
    if (hr < 0)
        R_DxFatalError("Couldn't create a %i-byte dynamic vertex buffer: %s", vbSize, hr);

    /* Store VB wrapper pointer */
    *(int *)(dxp + 11700) = (int)(intptr_t)(dxp + 11688);
    fprintf(stderr, "[R_CreateForInitOrReset] set dxp+11700 (0x2db4) = %p, value = %p\n",
            (void *)(dxp + 11700), *(void **)(dxp + 11700));

    /* Create 2 additional VBs for multi-buffering */
    int loopVbSize = isDx7 ? 0x480000 : 0x800000;
    int offset = 0x2d90;
    byte *vbOut = dxp + 11672;
    for (i = 0; i < 2; i++) {
        isDx7 = (*(int *)(*(int *)imp_r_rendererInUse + 8) == 2);
        loopVbSize = isDx7 ? 0x480000 : 0x800000;
        *(int *)(dxp + offset) = 0;
        *(int *)(dxp + offset + 4) = loopVbSize;
        d3dDevice = *(void **)(dxp + 8);
        vtable = *(void ***)d3dDevice;
        hr = ((CreateVB_fn)vtable[26])(d3dDevice, loopVbSize, 0x208, 0, 0, (void **)vbOut, NULL);
        if (hr < 0)
            R_DxFatalError("Couldn't create a %i-byte dynamic vertex buffer: %s", loopVbSize, hr);
        offset += 0xc;
        vbOut += 0xc;
    }

    /* Create dynamic index buffer (2MB) */
    *(int *)(dxp + 11648) = 0;
    *(int *)(dxp + 11652) = 0x200000;
    d3dDevice = *(void **)(dxp + 8);
    vtable = *(void ***)d3dDevice;
    typedef HRESULT (*CreateIB_fn)(void *, int, int, int, int, void **, void *);
    hr = ((CreateIB_fn)vtable[27])(d3dDevice, 0x200000, 0x208, 0x65, 0, (void **)(dxp + 11656), NULL);
    if (hr < 0)
        R_DxFatalError("Couldn't create a %i-byte dynamic index buffer: %s", 0x200000, hr);

    *(int *)(dxp + 11660) = (int)(intptr_t)(dxp + 11648);

    /* Allocate large memory block (10MB) */
    *(void **)(dxp + 11728) = Hunk_Alloc(0xa00000);

    Printf(0, "Particle cloud");
    R_CreateParticleCloudBuffer();
    Printf(0, "State");

    /* Clear flags */
    *(byte *)(dxp + 11624) = 0;
    *(int *)(dxp + 11612) = 0;

    /* Clear sun flare textures for all 4 views */
    byte *sunFlares = (byte *)imp_sunFlareArray;
    for (i = 0; i < 4; i++) {
        sunFlares[i * 0x30 + 0x2c] = 0;
        sunFlares[i * 0x30 + 0x2d] = 0;
    }

    Printf(0, "Initial state");
    RB_SetInitialState();
    return 1;
}

/* line 1985 — D3D initialization pipeline: registers dvars/cmds, clears global state,
 * creates D3D device (with display mode enumeration, caps checking, AA detection),
 * precomputes sin table + FFT, sets up shader include handler, outputs vidConfig.
 * Original: 1028 lines of ASM. */
extern void Swap_Init(void);
extern void R_RegisterDvars(void);
extern void R_RegisterCmds(void);
extern void R_InitBackendData(void);
extern void R_InitDrawGroups(void);
extern void R_InitSystems(void);
extern void FFT_Init(void *sinTable, void *workspace);
extern int Direct3DCreate9(int sdkVersion);
extern double sin(double);
static void R_BeginRegistration_impl(vidConfig_t *vidConfigOut)
{
    typedef int (*PrintFunc)(int, const char *, ...);
    PrintFunc ri_printf = *(PrintFunc *)&ri;

    /* Phase 1: Register dvars, commands, clear global state */
    ri_printf(0, "----- R_Init -----\n");
    Swap_Init();
    R_RegisterDvars();
    R_RegisterCmds();
    memset(&rg, 0, 0x31a0);
    memset(&rgp, 0, 0x10f0);
    {
        extern void RB_InitBackendGlobalStructs(void);
        extern void RB_DecideDefaultSamplerState(void);
        RB_InitBackendGlobalStructs();
        RB_DecideDefaultSamplerState();
    }
    R_InitBackendData();
    R_InitDrawGroups();

    /* Phase 2: D3D device creation (if not already created) */
    if (*(int *)((char *)&dx + 8)) {
        /* Device exists — just init systems */
        R_InitSystems();
    } else {
        /* Simplified device creation path (replaces ~1000-line ASM block) */
        if (!*(int *)((char *)&dx + 4)) {
            ri_printf(0, "Initializing Direct3D\n");
            *(int *)((char *)&dx + 4) = Direct3DCreate9(0x20);
            if (!*(int *)((char *)&dx + 4)) {
                ri_printf(0, "Direct3DCreate9 failed\n");
            }
        }

        /* Build D3DPRESENT_PARAMETERS and create device */
        {
            int d3dpp[14];
            int width = 640, height = 480;

            memset(d3dpp, 0, sizeof(d3dpp));
            d3dpp[0] = width;   /* BackBufferWidth */
            d3dpp[1] = height;  /* BackBufferHeight */
            d3dpp[2] = 0x15;    /* BackBufferFormat = D3DFMT_X8R8G8B8 */
            d3dpp[3] = 1;       /* BackBufferCount */
            d3dpp[6] = 1;       /* SwapEffect = D3DSWAPEFFECT_DISCARD */
            d3dpp[8] = 0x4b;    /* AutoDepthStencilFormat */
            d3dpp[11] = 1;      /* PresentationInterval */

            R_CreateDevice_impl(0, 0x40, d3dpp);

            /* Set vidConfig */
            vidConfig.width = width;
            vidConfig.height = height;
            vidConfig.displayFrequency = 60;
            vidConfig.isFullscreen = 0;
            vidConfig.aspectRatioWindow = (float)width / (float)height;  /* 640/480 = 1.333 */
            vidConfig.aspectRatioPixel = (float)height * vidConfig.aspectRatioWindow / (float)width;  /* = 1.0 for square pixels */

            /* Note: r_rendererInUse defaults to non-Dx7 (programmable shaders).
             * Dx7 mode requires s_passOptionsDx7/s_textureFuncsDx7 data tables
             * which are not yet initialized in the decompilation. */
        }

        R_InitSystems();
    }

    /* Create dynamic vertex/index buffers, particle cloud, set initial render state */
    if (!R_CreateForInitOrReset()) {
        ri_printf(0, "R_CreateForInitOrReset failed\n");
    }

    /* Phase 3: Register backend assets */
    {
        extern void RB_RegisterBackendAssets(void);
        RB_RegisterBackendAssets();
    }

    /* Phase 4: Precompute sin table (1024 entries) */
    {
        int i;
        float *sinTable = (float *)((char *)&rg + 0x1510);
        for (i = 0; i < 1024; i++) {
            double angle = (double)i * 0.3515625 * 0.017453292519943295;
            sinTable[i] = (float)sin(angle);
        }
    }

    /* Phase 5: FFT init */
    FFT_Init((void *)((char *)&rg + 11536), (void *)((char *)&rg + 9488));

    /* Phase 6: DObjCreate for default world model */
    {
        int args[3] = {0, 0, 0};
        ((void (*)(void *, int, void *, void *, int))*(void **)((char *)&ri + 476))(
            args, 1, NULL, (void *)((char *)&rg + 12564), 0);
        *(void **)((char *)&rg + 12560) = (void *)((char *)&rg + 12564);
    }

    /* Phase 7: Sun sprite samples */
    {
        extern int RB_CalcSunSpriteSamples(void);
        *(int *)((char *)&dx + 11308) = RB_CalcSunSpriteSamples();
    }

    /* Phase 8: Copy vidConfig to output */
    memcpy(vidConfigOut, imp_vidConfig, 44);
}

void R_BeginRegistration(vidConfig_t *vidConfigOut)
{
    R_BeginRegistration_impl(vidConfigOut);
    /* Set rg.registered = 1 so R_EndFrame doesn't early-return */
    *(char *)&rg = 1;
}

/* line 2408 — R_RecoverLostDevice
 * Attempts to recover a lost D3D device. Tests cooperative level, releases resources,
 * determines anti-aliasing support, resets device, recreates resources, reloads assets. */
extern void R_ReleaseAllModels(void);
extern void R_ReleaseLostImages(void);
extern void Material_ReleaseAll(void);
extern void R_ReleaseWorld(void);
extern void R_ReleaseForShutdownOrReset(void);
extern void R_ReloadWorld(void);
extern void Material_ReloadAll(void);
extern void R_ReloadLostImages(void);
extern void R_OptimizeAllModels(void);
extern int RB_CalcSunSpriteSamples(void);
extern r_global_permanent_t rgp;

Bool R_RecoverLostDevice(void)
{
    byte *dxp = (byte *)(void *)&dx;
    typedef void (*ri_fn)(int, const char *, ...);
    typedef void (*ri_err_fn)(void);
    ri_fn Printf = *(ri_fn *)&ri;
    ri_err_fn Error = *(ri_err_fn *)((byte *)&ri + 72);

    /* Test cooperative level */
    void *d3dDevice = *(void **)(dxp + 8);
    void **vtable = *(void ***)d3dDevice;
    typedef HRESULT (*TestCoopLevel_fn)(void *);
    HRESULT hr = ((TestCoopLevel_fn)vtable[3])(d3dDevice);

    if (hr == (HRESULT)0x88760868) /* D3DERR_DEVICELOST */
        return 0;

    Printf(0, "Recovering lost device");

    /* Release all resources */
    R_ReleaseAllModels();
    R_ReleaseLostImages();
    Material_ReleaseAll();

    if (*(int *)((byte *)&rgp + 4252)) /* rgp.world != NULL */
        R_ReleaseWorld();

    /* Save current display parameters */
    int displayMode = *(int *)(dxp + 11596);
    int backBufWidth = *(int *)(dxp + 11604);
    int backBufHeight = *(int *)(dxp + 11608);
    int refreshRate = *(int *)((byte *)&vidConfig + 8);
    int isFullscreen = *(int *)((byte *)&vidConfig + 12) != 0;
    int aaSamples = *(int *)(*(int *)imp_r_aaSamples + 8);

    /* Find supported AA level */
    if (aaSamples > 1) {
        void *d3d = *(void **)(dxp + 4);
        void **d3dVtable = *(void ***)d3d;
        typedef HRESULT (*CheckMultiSample_fn)(void *, int, int, int, int, int, void *);
        int qualityLevels;
        int testSamples = aaSamples;
        while (testSamples > 1) {
            *(int *)(dxp + 11300) = testSamples;
            hr = ((CheckMultiSample_fn)d3dVtable[11])(d3d, 0, 1, 0x15, !isFullscreen, testSamples, &qualityLevels);
            if (hr >= 0) {
                *(int *)(dxp + 11304) = qualityLevels - 1;
                goto aa_done;
            }
            testSamples--;
        }
        *(int *)(dxp + 11300) = 0;
        *(int *)(dxp + 11304) = 0;
    }

aa_done:;
    /* Build D3DPRESENT_PARAMETERS */
    int d3dpp[14];
    memset(d3dpp, 0, sizeof(d3dpp));
    d3dpp[0] = backBufWidth;
    d3dpp[1] = backBufHeight;
    d3dpp[2] = 0x15; /* BackBufferFormat = D3DFMT_X8R8G8B8 */
    d3dpp[3] = 1;    /* BackBufferCount */
    d3dpp[4] = *(int *)(dxp + 11300); /* MultiSampleType */
    d3dpp[5] = *(int *)(dxp + 11304); /* MultiSampleQuality */
    d3dpp[6] = 1;    /* SwapEffect = D3DSWAPEFFECT_DISCARD */
    d3dpp[8] = 0x4b; /* AutoDepthStencilFormat */
    /* PresentationInterval: 1 if vsync, 0x80000000 if not */
    int swapInterval = *(byte *)(*(int *)imp_r_swapInterval + 8);
    d3dpp[11] = swapInterval ? 1 : 0x80000001;
    d3dpp[10] = displayMode;
    d3dpp[9] = 0; /* Windowed (set below) */
    if (isFullscreen) {
        d3dpp[7] = 0; /* hDeviceWindow = NULL (fullscreen) */
        d3dpp[12] = refreshRate;
    } else {
        d3dpp[7] = 1; /* Windowed = TRUE */
        d3dpp[12] = 0;
    }

    /* Release and reset device */
    R_ReleaseForShutdownOrReset();

    d3dDevice = *(void **)(dxp + 8);
    vtable = *(void ***)d3dDevice;
    typedef HRESULT (*Reset_fn)(void *, void *);
    hr = ((Reset_fn)vtable[16])(d3dDevice, d3dpp);

    if (hr < 0) {
        const char *msg = va("Couldn't reset a lost Direct3D device - IDirect3DDevice9::Reset returned %s", DXGetErrorDescription9A(hr));
        Printf(0, "------- Initializing Renderer -------");
        Printf(0, "------- Renderer Initialization -------");
        Printf(0, "------- Server Initialization -------");
        Printf(0, "\n%s\n", msg);
        Error();
    }

    *(byte *)(dxp + 11580) = 0;

    /* Recreate resources */
    if (!R_CreateForInitOrReset()) {
        Printf(0, "------- Initializing Renderer -------");
        Printf(0, "------- Renderer Initialization -------");
        Printf(0, "------- Server Initialization -------");
        Printf(0, "\nFailed to recreate resources after device reset\n");
        Error();
    }

    /* Reload assets */
    if (*(int *)((byte *)&rgp + 4252))
        R_ReloadWorld();

    Material_ReloadAll();
    R_ReloadLostImages();
    R_OptimizeAllModels();
    *(int *)(dxp + 11308) = RB_CalcSunSpriteSamples();

    Printf(0, "Device recovered successfully");
    return 1;
}

/* std::__adjust_heap for _D3DDISPLAYMODE* — heap sift-down + push-up (16-byte elements) */
void ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
    _D3DDISPLAYMODE *first, int holeIndex, int len, _D3DDISPLAYMODE value, D3DDispModeCompFunc comp)
{
    int topIndex = holeIndex;
    int secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (comp(&first[secondChild], &first[secondChild - 1]))
            secondChild--;
        first[holeIndex] = first[secondChild];
        holeIndex = secondChild;
        secondChild = 2 * secondChild + 2;
    }
    if (secondChild == len) {
        first[holeIndex] = first[len - 1];
        holeIndex = len - 1;
    }
    while (holeIndex > topIndex) {
        int parent = (holeIndex - 1) / 2;
        if (!comp(&first[parent], &value))
            break;
        first[holeIndex] = first[parent];
        holeIndex = parent;
    }
    first[holeIndex] = value;
}

/* std::__insertion_sort for _D3DDISPLAYMODE* — insertion sort with 16-byte element copies */
void ZSt16__insertion_sortIP15_D3DDISPLAYMODEPFhRKS0_S3_EEvT_S6_T0_(
    _D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, D3DDispModeCompFunc comp)
{
    _D3DDISPLAYMODE *i;
    if (first == last) return;
    for (i = first + 1; i != last; i++) {
        _D3DDISPLAYMODE val = *i;
        if (comp(&val, first)) {
            memmove(first + 1, first, (char *)i - (char *)first);
            *first = val;
        } else {
            _D3DDISPLAYMODE *prev = i - 1;
            _D3DDISPLAYMODE *hole = i;
            while (comp(&val, prev)) {
                *hole = *prev;
                hole = prev;
                prev--;
            }
            *hole = val;
        }
    }
}

/* line 2514 */
/* std::__introsort_loop for _D3DDISPLAYMODE* — introsort with heapsort fallback (16-byte elements) */
void ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_(
    _D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, int depth_limit, D3DDispModeCompFunc comp)
{
    while ((char *)last - (char *)first > 16 * 16) { /* > 16 elements of 16 bytes */
        if (depth_limit == 0) {
            int n = (int)(last - first);
            int half = (n - 2) / 2;
            int i;
            _D3DDISPLAYMODE *end;
            for (i = half; i >= 0; i--)
                ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
                    first, i, n, first[i], comp);
            for (end = last - 1; end - first > 0; end--) {
                _D3DDISPLAYMODE value = *end;
                *end = *first;
                ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
                    first, 0, (int)(end - first), value, comp);
            }
            return;
        }
        depth_limit--;
        {
            int n = (int)(last - first);
            _D3DDISPLAYMODE *midPtr = first + n / 2;
            _D3DDISPLAYMODE *pivotPtr;
            _D3DDISPLAYMODE pivot;
            _D3DDISPLAYMODE *lo, *hi;
            if (comp(first, midPtr)) {
                if (comp(midPtr, last - 1))
                    pivotPtr = midPtr;
                else if (comp(first, last - 1))
                    pivotPtr = last - 1;
                else
                    pivotPtr = first;
            } else {
                if (comp(first, last - 1))
                    pivotPtr = first;
                else if (comp(last - 1, midPtr))
                    pivotPtr = midPtr;
                else
                    pivotPtr = last - 1;
            }
            pivot = *pivotPtr;
            lo = first;
            hi = last;
            for (;;) {
                while (!comp(&pivot, lo)) lo++;
                hi--;
                while (!comp(hi, &pivot)) hi--;
                if (lo >= hi) break;
                { _D3DDISPLAYMODE tmp = *lo; *lo = *hi; *hi = tmp; }
                lo++;
            }
            ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_(
                lo, last, depth_limit, comp);
            last = lo;
        }
    }
}

