/* ASM dump from: r_rendercmds.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_rendercmds.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern SkinBuffers g_skinBuffers[1]; /* 0x0 */
extern GfxBackEndData *frontEndDataOut; /* 0x0 */
extern byte g_dummyBuf[]; /* g_dummyBuf */
extern r_global_permanent_t rgp; /* imp_rgp */
extern void R_ShutdownDebugEntry(void *entry);
extern void R_UnlockSkinnedCache(void);
extern void R_UpdateGfxEntityBounds(GfxEntity *ent);
extern void R_SkinGfxEntity(GfxEntity *ent);
extern void R_SkinStaticModelCachedCmd(SkinStaticModelCachedCmd *skinCmd, SkinBuffers *skinBuffers);
extern void R_SkinXModelCmd(SkinXModelCmd *skinCmd, int context);
extern void R_SkinRigidXModelCmd(SkinRigidXModelCmd *skinRigidCmd);
extern void FX_UpdateScheduledEffectsBolt(void);
extern void FX_UpdateScheduledEffectsNonBolt(void);
extern const float AngleNormalize360(const float angle);
extern void R_ConvertColorToBytes(const vec_t *colorFloat, byte *colorBytes);
extern void RB_ExecuteRenderCommands(const void *data);
extern void RB_EndFrame(void);
extern void R_LockSkinnedCache(int lock);
extern void R_InitDebugEntry(DebugGlobals *debugGlobalsEntry);
extern void R_TransferDebugGlobals(DebugGlobals *debugGlobalsEntry);
extern void R_UpdateGpuSyncType(void);
extern void R_UpdateLightsFromDvars(void);
extern int R_SetSunFromDvars(sunflare_t *sun);
extern void RB_CreateDynamicBuffers(void);
extern void RB_AdaptiveGpuSyncTarget(void);
extern void Material_Sort(void);
extern struct r_globals_t rg; /* imp_rg */

extern unsigned char s_backEndData[]; /* s_backEndData */
extern GfxCmdArray *s_cmdList; /* s_cmdList */
extern struct GfxDebugFrameGlob s_debugFrameGlob; /* s_debugFrameGlob */

void R_ShutdownBackendData(void);
static __attribute_regparm__(3) void R_ProcessFrontendCmdInternal(int type, void *data, int isRenderThread);
void R_AddFrontendCmd(int type, void *data);
void R_SyncRenderThread(void);
GfxViewParms * R_AllocViewParms(void);
void R_BeginDebugFrame(void);
void R_AddCmdTouchAllImages(void);
void R_AbortRenderCommands(void);
void R_BeginFrame(void);
static void R_BeginFrame_impl(void);
void R_UpdateEffectsBolt(void);
void R_UpdateEffectsNonBolt(void);
void R_UpdateXModelBoundsDelayed(GfxEntity *ent);
void R_SkinGfxEntityDelayed(GfxEntity *ent);
void R_InitBackendData(void);
void R_EndFrame(void);
static void R_EndFrame_impl(void);
void R_AddCmdDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount, MaterialTechniqueType techType);
int R_BeginDelayedDrawing(void);
void R_EndDelayedDrawing(int marker);
void R_IssueDelayedDrawing(int marker);
void R_AddCmdDrawStretchPic(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material);
void R_AddCmdDrawStretchPicRotate(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const vec_t *color, MaterialHandle material);
void R_AddCmdDrawStretchRaw(int x, int y, int w, int h, int cols, int rows, const byte *data, int client, qboolean dirty);
void R_AddCmdDrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor);
void R_AddCmdDrawTextInSpace(const char *text, FontHandle font, const vec_t *org, const vec_t *xPixelStep, const vec_t *yPixelStep, const vec_t *color);
void R_AddCmdDrawQuadPic(vec2_t *verts, const vec_t *color, MaterialHandle material);
void R_AddCmdDrawSprite(MaterialHandle material, const byte *rgbaColor, const vec_t *pos, float radius, float minScreenRadius, int renderFxFlags);
void R_AddCmdDrawFullScreenColoredQuad(float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material);
void R_AddCmdSetMaterialColor(const vec_t *color);
void R_AddCmdLightProperties(int lightIndex, const GfxLight *light);
void R_AddCmdSetRenderTarget(GfxRenderTargetId renderTargetId);
void R_AddCmdDrawSun(int viewIndex);
void R_AddCmdBeginView(int viewCount, const GfxSceneDef *sceneDef, const GfxViewParms *viewParms, const GfxLodParms *lodParms);
void R_AddCmdSetViewport(int x, int y, int width, int height);
void R_EndDebugFrame(void);
void R_AddCmdApplyEarlyPostEffects(void);
void R_AddCmdApplyLatePostEffects(float blurRadius);
void R_AddCmdDrawSunPostEffects(int viewIndex);
void R_AddCmdClearScreen(int whichToClear, const vec_t *color, float depth, int stencil);
void R_AddCmdSaveScreen(void);
void R_AddCmdBlendSavedScreen(int fadeMsec);

static void R_ResetCmdListState(void)
{
    if (s_cmdList == NULL) {
        return;
    }

    s_cmdList->usedTotal = 0;
    s_cmdList->usedCritical = 0;
    s_cmdList->lastCmd = NULL;
}

static Bool R_ClearModifiedDvar(const dvar_t *dvar)
{
    refimport_t *ri;

    if (!dvar->modified) {
        return 0;
    }

    ri = (refimport_t *)imp_ri;
    ri->Dvar_ClearModified(dvar);
    return 1;
}

static void R_ResetFrameBackendData(GfxBackEndData *data)
{
    s_cmdList = &data->commands;
    R_ResetCmdListState();
    data->drawSurfCount = 0;
    data->surfPos = 0;
    data->entityCount = 0;
    data->polyCount = 0;
    data->polyVertCount = 0;
    data->viewParmCount = 0;
    data->debugGlobals.vertCount = 0;
    data->debugGlobals.stringCount = 0;
    data->debugGlobals.lineCount = 0;
}

static void R_SelectSkinnedCacheForFrame(GfxBackEndData *data, DxGlobals *dx)
{
    dx->dynamicBufferFrame = (dx->dynamicBufferFrame + 1) & 1;
    data->skinnedCacheVb = &dx->skinnedCacheVbPool[dx->dynamicBufferFrame];
    data->skinnedCacheVb->used = 0;
}

static GfxCmdCall *R_AllocDelayedCall(short id, int *marker)
{
    int used;
    GfxCmdCall *cmd;

    used = s_cmdList->usedTotal;
    if (marker) {
        *marker = used;
    }

    cmd = (GfxCmdCall *)((char *)s_cmdList + used);
    if (0x30000 - used > 7) {
        s_cmdList->usedTotal = used + 8;
        s_cmdList->usedCritical += 8;
        s_cmdList->lastCmd = &cmd->header;
        cmd->header.id = id;
        cmd->header.byteCount = 8;
    } else {
        s_cmdList->lastCmd = NULL;
    }

    return cmd;
}

static void *R_AllocCmd(int byteCount, int criticalByteCount, unsigned short id)
{
    int usedBytes;
    int availBytes;
    GfxCmdHeader *cmd;

    usedBytes = s_cmdList->usedTotal;
    availBytes = 0x30000 - usedBytes + s_cmdList->usedCritical - 0x2000;
    if (availBytes <= byteCount - 1) {
        s_cmdList->lastCmd = NULL;
        return NULL;
    }

    cmd = (GfxCmdHeader *)((byte *)s_cmdList + usedBytes);
    s_cmdList->usedTotal = usedBytes + byteCount;
    s_cmdList->usedCritical += criticalByteCount;
    s_cmdList->lastCmd = cmd;
    cmd->id = id;
    cmd->byteCount = byteCount;
    return cmd;
}

static void *R_AllocCriticalCmd(int byteCount, unsigned short id)
{
    int usedBytes;
    GfxCmdHeader *cmd;

    usedBytes = s_cmdList->usedTotal;
    if (0x30000 - usedBytes <= byteCount - 1) {
        s_cmdList->lastCmd = NULL;
        return NULL;
    }

    cmd = (GfxCmdHeader *)((byte *)s_cmdList + usedBytes);
    s_cmdList->usedTotal = usedBytes + byteCount;
    s_cmdList->usedCritical += byteCount;
    s_cmdList->lastCmd = cmd;
    cmd->id = id;
    cmd->byteCount = byteCount;
    return cmd;
}

/* line 158 */
void R_ShutdownBackendData(void)
{
    R_ShutdownDebugEntry((void *)((char *)&s_backEndData + 2399512));
}

/* line 253 */
static __attribute_regparm__(3)
void R_ProcessFrontendCmdInternal(int type, void *data, int isRenderThread)
{
    switch (type) {
    case 0:
        R_UpdateGfxEntityBounds(*(GfxEntity **)data);
        break;
    case 1:
        R_SkinGfxEntity(*(GfxEntity **)data);
        break;
    case 2:
        R_SkinRigidXModelCmd((SkinRigidXModelCmd *)data);
        break;
    case 3:
        FX_UpdateScheduledEffectsNonBolt();
        break;
    case 4:
        FX_UpdateScheduledEffectsBolt();
        break;
    case 5:
        R_SkinStaticModelCachedCmd((SkinStaticModelCachedCmd *)data, ((SkinBuffers *)g_skinBuffers) + isRenderThread);
        break;
    case 6:
    case 7:
        R_SkinXModelCmd((SkinXModelCmd *)data, isRenderThread);
        break;
    default:
        break;
    }
}

/* line 512 */
void R_AddFrontendCmd(int type, void *data)
{
    R_ProcessFrontendCmdInternal(type, data, 0);
}

/* line 626 */
void R_SyncRenderThread(void)
{
}

/* line 1140 */
GfxViewParms * R_AllocViewParms(void)
{
    int index = frontEndDataOut->viewParmCount;
    frontEndDataOut->viewParmCount = index + 1;
    return &frontEndDataOut->viewParms[index];
}

/* line 1806 */
void R_BeginDebugFrame(void)
{
    if (!*(char *)imp_rg)
        return;
    *(GfxCmdArray **)&s_debugFrameGlob = s_cmdList;
    *(GfxBackEndData * *)((char *)&s_debugFrameGlob + 4) = frontEndDataOut;
    if (((DxGlobals *)imp_dx)->dynamicBufferFrame) { /* TODO: verify offset 0x2dc0 maps to dynamicBufferFrame */
        *(char *)((char *)&s_debugFrameGlob + 8) = 1;
        R_UnlockSkinnedCache();
    }
    s_cmdList = (GfxCmdArray *)((char *)&s_debugFrameGlob + 2202904);
    frontEndDataOut = (GfxBackEndData *)((char *)&s_debugFrameGlob + 12);
}

/* line 2102 */
void R_AddCmdTouchAllImages(void)
{
    int usedBytes = s_cmdList->usedTotal;
    int availBytes = (int)sizeof(s_cmdList->cmds) - usedBytes + s_cmdList->usedCritical - 0x2000;
    if (availBytes <= 3) {
        s_cmdList->lastCmd = NULL;
        return;
    }
    char *cmdBuf = (char *)s_cmdList->cmds + usedBytes;
    s_cmdList->usedTotal = usedBytes + 4;
    s_cmdList->lastCmd = (GfxCmdHeader *)cmdBuf;
    *(short *)cmdBuf = 0x21;
    *(short *)(cmdBuf + 2) = 4;
}

/* line 889 */
void R_AbortRenderCommands(void)
{
    DxGlobals *dx;
    refimport_t *ri;

    if (!*(byte *)imp_rg) {
        return;
    }

    R_UnlockSkinnedCache();
    frontEndDataOut->commands.usedTotal = 0;
    frontEndDataOut->commands.usedCritical = 0;
    frontEndDataOut->commands.lastCmd = NULL;

    dx = (DxGlobals *)imp_dx;
    if (!dx->tempSkinPos) {
        return;
    }

    ri = (refimport_t *)imp_ri;
    ri->Z_VirtualDecommitInternal(dx->tempSkinBuf, dx->tempSkinPos);
    dx->tempSkinPos = 0;
}

/* line 1739 */
static void R_BeginFrame_impl(void)
{
    refimport_t *ri;
    const dvar_t *forceLod;
    int lodIndex;
    Bool lightsChanged;
    Bool gpuSyncChanged;

    if (!rg.registered) {
        return;
    }

    if (rgp.materialLoaded) {
        rgp.materialLoaded = 0;
        Material_Sort();
    }

    if (rgp.world != NULL) {
        lightsChanged = R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakAmbient);
        lightsChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakDiffuseFraction);
        lightsChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakSunLight);
        lightsChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakAmbientColor);
        lightsChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakSunColor);
        lightsChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakSunDiffuseColor);
        lightsChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_lightTweakSunDirection);
        if (lightsChanged) {
            R_UpdateLightsFromDvars();
        }
    }

    if ((*(const dvar_t **)imp_r_sun_from_dvars)->current.enabled && rgp.world != NULL) {
        R_SetSunFromDvars(&rgp.world->sun);
    }

    gpuSyncChanged = R_ClearModifiedDvar(*(const dvar_t **)imp_r_gpuSync);
    gpuSyncChanged |= R_ClearModifiedDvar(*(const dvar_t **)imp_r_multiGpu);
    if (gpuSyncChanged) {
        R_UpdateGpuSyncType();
    }

    ri = (refimport_t *)imp_ri;
    forceLod = *(const dvar_t **)imp_r_forceLod;
    if (forceLod->current.integer != forceLod->reset.integer) {
        for (lodIndex = 0; lodIndex < 4; ++lodIndex) {
            ((void (*)(int, float))ri->XModelSetTestLods)(lodIndex, (forceLod->current.integer == lodIndex) ? 0.001f : 0.0f);
        }
    } else {
        ((void (*)(int, float))ri->XModelSetTestLods)(0, (*(const dvar_t **)imp_r_highLodDist)->current.value);
        ((void (*)(int, float))ri->XModelSetTestLods)(1, (*(const dvar_t **)imp_r_mediumLodDist)->current.value);
        ((void (*)(int, float))ri->XModelSetTestLods)(2, (*(const dvar_t **)imp_r_lowLodDist)->current.value);
        ((void (*)(int, float))ri->XModelSetTestLods)(3, (*(const dvar_t **)imp_r_lowestLodDist)->current.value);
    }

    ((void (*)(qboolean))ri->CL_FlushDebugData)(0);
    if ((*(const dvar_t **)imp_r_skinCache)->current.enabled) {
        R_LockSkinnedCache(0);
    }
}

void R_BeginFrame(void)
{
    R_BeginFrame_impl();
    R_ResetCmdListState();
}

/* line 594 */
void R_UpdateEffectsBolt(void)
{
    R_ProcessFrontendCmdInternal(4, g_dummyBuf, 0);
}

/* line 604 */
void R_UpdateEffectsNonBolt(void)
{
    R_ProcessFrontendCmdInternal(3, g_dummyBuf, 0);
}

/* line 614 */
void R_UpdateXModelBoundsDelayed(GfxEntity *ent)
{
    R_ProcessFrontendCmdInternal(0, &ent, 0);
}

/* line 620 */
void R_SkinGfxEntityDelayed(GfxEntity *ent)
{
    R_ProcessFrontendCmdInternal(1, &ent, 0);
}

/* line 135 */
void R_InitBackendData(void)
{
    DxGlobals *dx;
    GfxBackEndData *data;

    R_InitDebugEntry(&((GfxBackEndData *)s_backEndData)->debugGlobals);
    RB_CreateDynamicBuffers();

    if (frontEndDataOut != NULL) {
        frontEndDataOut->commands.usedTotal = 0;
        frontEndDataOut->commands.usedCritical = 0;
        frontEndDataOut->commands.lastCmd = NULL;
        return;
    }

    data = (GfxBackEndData *)s_backEndData;
    frontEndDataOut = data;
    data->frameCount = ++rg.frameCountInternal;

    R_UnlockSkinnedCache();

    dx = (DxGlobals *)imp_dx;
    R_SelectSkinnedCacheForFrame(data, dx);
    R_ResetFrameBackendData(data);
}

/* line 1771 */
static void R_EndFrame_impl(void)
{
    DxGlobals *dx;
    refimport_t *ri;
    GfxBackEndData *data;

    if (!rg.registered) {
        return;
    }

    RB_AdaptiveGpuSyncTarget();
    R_UnlockSkinnedCache();

    ri = (refimport_t *)imp_ri;
    ri->CL_UpdateDebugData();
    R_TransferDebugGlobals(&frontEndDataOut->debugGlobals);

    R_AllocCriticalCmd(4, 0);
    RB_ExecuteRenderCommands(frontEndDataOut);
    RB_EndFrame();

    data = (GfxBackEndData *)s_backEndData;
    frontEndDataOut = data;
    data->frameCount = ++rg.frameCountInternal;

    R_UnlockSkinnedCache();
    dx = (DxGlobals *)imp_dx;
    R_SelectSkinnedCacheForFrame(data, dx);
    R_ResetFrameBackendData(data);

    if (dx->tempSkinPos != 0) {
        ri->Z_VirtualDecommitInternal(dx->tempSkinBuf, dx->tempSkinPos);
        dx->tempSkinPos = 0;
    }
}

static const char rb_diag_cmdlist_fmt[] = "";
static int g_endframe_count = 0;
void R_EndFrame(void)
{
    R_EndFrame_impl();
    R_ResetCmdListState();
}

/* line 1506 */
void R_AddCmdDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount, MaterialTechniqueType techType)
{
    GfxCmdDrawSurfs *cmd;
    int usedBytes;
    int availBytes;

    usedBytes = s_cmdList->usedTotal;
    availBytes = 0x30000 - usedBytes + s_cmdList->usedCritical - 0x2000;
    if (availBytes <= 0x13) {
        s_cmdList->lastCmd = NULL;
        return;
    }

    cmd = (GfxCmdDrawSurfs *)((byte *)s_cmdList + usedBytes);
    s_cmdList->usedTotal = usedBytes + 0x14;
    s_cmdList->lastCmd = &cmd->header;
    cmd->header.id = 0x17;
    cmd->header.byteCount = 0x14;
    cmd->order = GFX_DRAW_SURFS_ITER_FORWARD;
    cmd->drawSurfs = drawSurfs;
    cmd->drawSurfCount = drawSurfCount;
    cmd->techType = techType;
}

/* line 991 */
int R_BeginDelayedDrawing(void)
{
    int marker;
    GfxCmdCall *cmd;

    cmd = R_AllocDelayedCall(1, &marker);
    cmd->subCmd = NULL;
    return marker;
}

/* line 1013 */
void R_EndDelayedDrawing(int marker)
{
    int used = s_cmdList->usedTotal;
    if ((int)sizeof(s_cmdList->cmds) - used > 3) {
        char *cmd = (char *)s_cmdList->cmds + used;
        s_cmdList->usedTotal = used + 4;
        s_cmdList->usedCritical += 4;
        s_cmdList->lastCmd = (GfxCmdHeader *)cmd;
        *(short *)cmd = 3;
        *(short *)(cmd + 2) = 4;
        used = s_cmdList->usedTotal;
    } else {
        s_cmdList->lastCmd = NULL;
    }
    *(int *)(cmdList + 4 + marker) = (int)(cmdList + used);
}

/* line 1037 */
void R_IssueDelayedDrawing(int marker)
{
    GfxCmdCall *cmd;

    cmd = R_AllocDelayedCall(2, NULL);
    cmd->subCmd = (char *)s_cmdList + marker + 8;
}

/* line 1153 */
void R_AddCmdDrawStretchPic(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material)
{
    GfxCmdStretchPic *cmd;

    cmd = (GfxCmdStretchPic *)R_AllocCmd(0x2c, 0, 0xf);
    if (cmd == NULL) {
        return;
    }

    cmd->material = material;
    cmd->x = x;
    cmd->y = y;
    cmd->w = w;
    cmd->h = h;
    cmd->s0 = s0;
    cmd->t0 = t0;
    cmd->s1 = s1;
    cmd->t1 = t1;
    R_ConvertColorToBytes(color, cmd->color.array);
}

/* line 1175 */
void R_AddCmdDrawStretchPicRotate(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const vec_t *color, MaterialHandle material)
{
    GfxCmdStretchPicRotate *cmd;

    cmd = (GfxCmdStretchPicRotate *)R_AllocCmd(0x30, 0, 0x10);
    if (cmd == NULL) {
        return;
    }

    cmd->material = material;
    cmd->x = x;
    cmd->y = y;
    cmd->w = w;
    cmd->h = h;
    cmd->s0 = s0;
    cmd->t0 = t0;
    cmd->s1 = s1;
    cmd->t1 = t1;
    R_ConvertColorToBytes(color, cmd->color.array);
    cmd->rotation = AngleNormalize360(angle);
}

/* line 1198 */
void R_AddCmdDrawStretchRaw(int x, int y, int w, int h, int cols, int rows, const byte *data, int client, qboolean dirty)
{
    GfxCmdStretchRaw *cmd;

    cmd = (GfxCmdStretchRaw *)R_AllocCmd(0x28, 0, 0x11);
    if (cmd == NULL) {
        return;
    }

    cmd->x = x;
    cmd->y = y;
    cmd->w = w;
    cmd->h = h;
    cmd->cols = cols;
    cmd->rows = rows;
    cmd->data = data;
    cmd->client = client;
    cmd->dirty = dirty;
}

/* line 1219 */
void R_AddCmdDrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor)
{
    int byteCount;
    int len;
    int textIndex;
    char *cmdText;
    GfxCmdDrawText *cmd;

    if (*text == '\0' && cursorPos < 0) {
        return;
    }

    len = 0;
    while (text[len] != '\0') {
        ++len;
    }

    byteCount = (len + 0x31) & ~3;
    cmd = (GfxCmdDrawText *)R_AllocCmd(byteCount, 0, 0x15);
    if (cmd == NULL) {
        return;
    }

    cmd->x = x;
    cmd->y = y;
    cmd->font = font;
    cmd->xScale = xScale;
    cmd->yScale = yScale;
    R_ConvertColorToBytes(color, cmd->color.array);
    cmd->style = style;
    cmd->cursorPos = cursorPos;
    cmd->cursor = (char)cursor;
    cmd->maxChars = maxChars;

    cmdText = cmd->text;
    for (textIndex = 0; textIndex < len; ++textIndex) {
        cmdText[textIndex] = text[textIndex];
    }
    cmdText[len] = '\0';
}

/* line 1262 */
void R_AddCmdDrawTextInSpace(const char *text, FontHandle font, const vec_t *org, const vec_t *xPixelStep, const vec_t *yPixelStep, const vec_t *color)
{
    int byteCount;
    int len;
    int textIndex;
    char *cmdText;
    GfxCmdDrawTextInSpace *cmd;

    if (*text == '\0') {
        return;
    }

    len = 0;
    while (text[len] != '\0') {
        ++len;
    }

    byteCount = (len + 0x34) & ~3;
    cmd = (GfxCmdDrawTextInSpace *)R_AllocCmd(byteCount, 0, 0x16);
    if (cmd == NULL) {
        return;
    }

    cmd->org[0] = org[0];
    cmd->org[1] = org[1];
    cmd->org[2] = org[2];
    cmd->font = font;
    cmd->xPixelStep[0] = xPixelStep[0];
    cmd->xPixelStep[1] = xPixelStep[1];
    cmd->xPixelStep[2] = xPixelStep[2];
    cmd->yPixelStep[0] = yPixelStep[0];
    cmd->yPixelStep[1] = yPixelStep[1];
    cmd->yPixelStep[2] = yPixelStep[2];
    R_ConvertColorToBytes(color, cmd->color.array);

    cmdText = cmd->text;
    for (textIndex = 0; textIndex < len; ++textIndex) {
        cmdText[textIndex] = text[textIndex];
    }
    cmdText[len] = '\0';
}

/* line 1299 */
void R_AddCmdDrawQuadPic(vec2_t *verts, const vec_t *color, MaterialHandle material)
{
    int cornerIndex;
    GfxCmdDrawQuadPic *cmd;

    cmd = (GfxCmdDrawQuadPic *)R_AllocCmd(0x2c, 0, 0x12);
    if (cmd == NULL) {
        return;
    }

    cmd->material = material;
    for (cornerIndex = 0; cornerIndex < 4; ++cornerIndex) {
        cmd->verts[cornerIndex][0] = verts[cornerIndex][0];
        cmd->verts[cornerIndex][1] = verts[cornerIndex][1];
    }
    R_ConvertColorToBytes(color, cmd->color.array);
}

/* line 1316 */
void R_AddCmdDrawSprite(MaterialHandle material, const byte *rgbaColor, const vec_t *pos, float radius, float minScreenRadius, int renderFxFlags)
{
    GfxCmdDrawSprite *cmd;

    cmd = (GfxCmdDrawSprite *)R_AllocCmd(0x24, 0, 0x13);
    if (cmd == NULL) {
        return;
    }

    cmd->material = material;
    cmd->rgbaColor.array[0] = rgbaColor[0];
    cmd->rgbaColor.array[1] = rgbaColor[1];
    cmd->rgbaColor.array[2] = rgbaColor[2];
    cmd->rgbaColor.array[3] = rgbaColor[3];
    cmd->pos[0] = pos[0];
    cmd->pos[1] = pos[1];
    cmd->pos[2] = pos[2];
    cmd->radius = radius;
    cmd->minScreenRadius = minScreenRadius;
    cmd->renderFxFlags = renderFxFlags;
}

/* line 1334 */
void R_AddCmdDrawFullScreenColoredQuad(float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material)
{
    GfxCmdDrawFullScreenColoredQuad *cmd;

    cmd = (GfxCmdDrawFullScreenColoredQuad *)R_AllocCmd(0x1c, 0, 0x14);
    if (cmd == NULL) {
        return;
    }

    cmd->material = material;
    cmd->s0 = s0;
    cmd->t0 = t0;
    cmd->s1 = s1;
    cmd->t1 = t1;
    R_ConvertColorToBytes(color, cmd->color.array);
}

/* line 1352 */
void R_AddCmdSetMaterialColor(const vec_t *color)
{
    GfxCmdSetMaterialColor *cmd;

    cmd = (GfxCmdSetMaterialColor *)R_AllocCriticalCmd(0x14, 4);
    if (cmd == NULL) {
        return;
    }

    if (color != NULL) {
        cmd->color[0] = color[0];
        cmd->color[1] = color[1];
        cmd->color[2] = color[2];
        cmd->color[3] = color[3];
    } else {
        cmd->color[0] = 0.0f;
        cmd->color[1] = 0.0f;
        cmd->color[2] = 0.0f;
        cmd->color[3] = 0.0f;
    }
}

/* line 1367 */
void R_AddCmdLightProperties(int lightIndex, const GfxLight *light)
{
    float scale;
    GfxCmdSetLightProperties *cmd;

    cmd = (GfxCmdSetLightProperties *)R_AllocCriticalCmd(0x4c, 5);
    if (cmd == NULL) {
        return;
    }

    cmd->lightIndex = lightIndex;
    cmd->position[0] = light->position[0];
    cmd->position[1] = light->position[1];
    cmd->position[2] = light->position[2];
    cmd->position[3] = light->position[3];

    cmd->ambient[0] = light->u.dir.ambientColor[0];
    cmd->ambient[1] = light->u.dir.ambientColor[1];
    cmd->ambient[2] = light->u.dir.ambientColor[2];
    cmd->ambient[3] = 1.0f;

    cmd->color[0] = light->color[0];
    cmd->color[1] = light->color[1];
    cmd->color[2] = light->color[2];
    cmd->color[3] = 1.0f;

    scale = (*(const dvar_t **)imp_r_specularColorScale)->current.value;
    cmd->specular[0] = cmd->color[0] * scale;
    cmd->specular[1] = cmd->color[1] * scale;
    cmd->specular[2] = cmd->color[2] * scale;
    cmd->specular[3] = scale;
    cmd->lightDef = light->def;
}

/* line 1452 */
void R_AddCmdSetRenderTarget(GfxRenderTargetId renderTargetId)
{
    GfxCmdSetRenderTarget *cmd;

    cmd = (GfxCmdSetRenderTarget *)R_AllocCriticalCmd(8, 0xe);
    if (cmd == NULL) {
        return;
    }

    cmd->renderTargetId = renderTargetId;
}

/* line 1518 */
void R_AddCmdDrawSun(int viewIndex)
{
    GfxCmdDrawSunPostEffects *cmd;

    cmd = (GfxCmdDrawSunPostEffects *)R_AllocCmd(8, 0, 0x18);
    if (cmd == NULL) {
        return;
    }

    cmd->viewIndex = viewIndex;
}

/* line 1604 */
void R_AddCmdBeginView(int viewCount, const GfxSceneDef *sceneDef, const GfxViewParms *viewParms, const GfxLodParms *lodParms)
{
    GfxCmdBeginView *cmd;

    cmd = (GfxCmdBeginView *)R_AllocCriticalCmd(0x30, 0xc);
    if (cmd == NULL) {
        return;
    }

    cmd->sceneDef = *sceneDef;
    cmd->viewParms = viewParms;
    cmd->lodParms = *lodParms;
    cmd->viewCount = viewCount;
}

/* line 1620 */
void R_AddCmdSetViewport(int x, int y, int width, int height)
{
    GfxCmdSetViewport *cmd;

    cmd = (GfxCmdSetViewport *)R_AllocCriticalCmd(0x14, 0xd);
    if (cmd == NULL) {
        return;
    }

    cmd->viewport.x = x;
    cmd->viewport.y = y;
    cmd->viewport.width = width;
    cmd->viewport.height = height;
}

/* line 1838 */
void R_EndDebugFrame(void)
{
    if (*(byte *)imp_rg == 0) {
        return;
    }

    R_AllocCriticalCmd(4, 0);

    RB_ExecuteRenderCommands(frontEndDataOut);
    RB_EndFrame();

    s_cmdList = s_debugFrameGlob.restoreCmdList;
    frontEndDataOut = s_debugFrameGlob.restoreFrontEndDataOut;
    if (s_debugFrameGlob.restoreSkinnedCache) {
        s_debugFrameGlob.restoreSkinnedCache = 0;
        R_LockSkinnedCache(1);
    }

    s_debugFrameGlob.restoreCmdList = NULL;
    s_debugFrameGlob.restoreFrontEndDataOut = NULL;
}

/* line 1867 */
void R_AddCmdApplyEarlyPostEffects(void)
{
    if (R_AllocCmd(4, 0, 0x19) == NULL) {
        return;
    }
}

/* line 1876 */
void R_AddCmdApplyLatePostEffects(float blurRadius)
{
    GfxCmdApplyLatePostEffects *cmd;

    cmd = (GfxCmdApplyLatePostEffects *)R_AllocCmd(8, 0, 0x1a);
    if (cmd == NULL) {
        return;
    }

    cmd->blurRadius = blurRadius;
}

/* line 1889 */
void R_AddCmdDrawSunPostEffects(int viewIndex)
{
    GfxCmdDrawSunPostEffects *cmd;

    cmd = (GfxCmdDrawSunPostEffects *)R_AllocCmd(8, 0, 0x1b);
    if (cmd == NULL) {
        return;
    }

    cmd->viewIndex = viewIndex;
}

/* line 1913 */
void R_AddCmdClearScreen(int whichToClear, const vec_t *color, float depth, int stencil)
{
    GfxCmdClearScreen *cmd;

    cmd = (GfxCmdClearScreen *)R_AllocCriticalCmd(0x1c, 0xb);
    if (cmd == NULL) {
        return;
    }

    cmd->whichToClear = (byte)whichToClear;
    cmd->stencil = (byte)stencil;
    cmd->depth = depth;
    cmd->color[0] = color[0];
    cmd->color[1] = color[1];
    cmd->color[2] = color[2];
    cmd->color[3] = color[3];
}

/* line 1934 */
void R_AddCmdSaveScreen(void)
{
    if (R_AllocCriticalCmd(4, 0xa) == NULL) {
        return;
    }
}

/* line 1944 */
void R_AddCmdBlendSavedScreen(int fadeMsec)
{
    GfxCmdBlendSavedScreen *cmd;

    if (fadeMsec <= 0) {
        return;
    }

    cmd = (GfxCmdBlendSavedScreen *)R_AllocCmd(0xc, 0, 0x1d);
    if (cmd == NULL) {
        return;
    }

    cmd->fadeMsec = fadeMsec;
}
