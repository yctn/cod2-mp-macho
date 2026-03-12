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

extern unsigned char s_backEndData[]; /* s_backEndData */
extern GfxCmdArray *s_cmdList; /* s_cmdList */
extern struct GfxDebugFrameGlob s_debugFrameGlob; /* s_debugFrameGlob */

void R_ShutdownBackendData(void);
static __attribute__((regparm(3))) void R_ProcessFrontendCmdInternal(int type, void *data, int isRenderThread);
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
static __attribute__((regparm(3)))
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
    int index = *(int *)((char *)frontEndDataOut + 0x217c7c);
    *(int *)((char *)frontEndDataOut + 0x217c7c) = index + 1;
    return (GfxViewParms *)((char *)frontEndDataOut + 0x217c80 + index * 332);
}

/* line 1806 */
void R_BeginDebugFrame(void)
{
    if (!*(char *)imp_rg)
        return;
    *(GfxCmdArray **)&s_debugFrameGlob = s_cmdList;
    *(GfxBackEndData * *)((char *)&s_debugFrameGlob + 4) = frontEndDataOut;
    if (*(int *)((char *)imp_dx + 0x2dc0)) {
        *(char *)((char *)&s_debugFrameGlob + 8) = 1;
        R_UnlockSkinnedCache();
    }
    s_cmdList = (GfxCmdArray *)((char *)&s_debugFrameGlob + 2202904);
    frontEndDataOut = (GfxBackEndData *)((char *)&s_debugFrameGlob + 12);
}

/* line 2102 */
void R_AddCmdTouchAllImages(void)
{
    int usedBytes = *(int *)((char *)s_cmdList + 0x30000);
    int availBytes = 0x30000 - usedBytes + *(int *)((char *)s_cmdList + 0x30004) - 0x2000;
    if (availBytes <= 3) {
        *(int *)((char *)s_cmdList + 0x30008) = 0;
        return;
    }
    char *cmdBuf = (char *)s_cmdList + usedBytes;
    *(int *)((char *)s_cmdList + 0x30000) = usedBytes + 4;
    *(void **)((char *)s_cmdList + 0x30008) = cmdBuf;
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
__attribute__((naked))
static void R_BeginFrame_impl(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1739 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_rg, %eax\n" /* line 1742 */
        "cmpb $0, (%eax)\n"
        "je .Lfc7f00_000c80b5\n"
        "movl imp_rgp, %ebx\n" /* line 1746 */
        "movl (%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfc7f00_000c80bb\n"
        ".Lfc7f00_000c7f25:\n"
        "movl 0x109c(%ebx), %edx\n" /* line 1652 */
        "testl %edx, %edx\n"
        "je .Lfc7f00_000c7fca\n"
        "movl imp_r_lightTweakAmbient, %eax\n" /* line 1664 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c81b5\n"
        "xorl %ebx, %ebx\n"
        "movl imp_r_lightTweakDiffuseFraction, %eax\n" /* line 1665 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c81d9\n"
        ".Lfc7f00_000c7f57:\n"
        "xorl %eax, %eax\n"
        "orb %al, %bl\n" /* line 1665 */
        "movl imp_r_lightTweakSunLight, %eax\n" /* line 1666 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c81ff\n"
        ".Lfc7f00_000c7f6c:\n"
        "xorl %eax, %eax\n"
        "orb %al, %bl\n" /* line 1666 */
        "movl imp_r_lightTweakAmbientColor, %eax\n" /* line 1667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c8225\n"
        ".Lfc7f00_000c7f81:\n"
        "xorl %eax, %eax\n"
        "orb %al, %bl\n" /* line 1667 */
        "movl imp_r_lightTweakSunColor, %eax\n" /* line 1668 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c824b\n"
        ".Lfc7f00_000c7f96:\n"
        "xorl %eax, %eax\n"
        "orb %al, %bl\n" /* line 1668 */
        "movl imp_r_lightTweakSunDiffuseColor, %eax\n" /* line 1669 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c8271\n"
        ".Lfc7f00_000c7fab:\n"
        "xorl %eax, %eax\n"
        "orb %al, %bl\n" /* line 1669 */
        "movl imp_r_lightTweakSunDirection, %eax\n" /* line 1670 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c8297\n"
        ".Lfc7f00_000c7fc0:\n"
        "xorl %eax, %eax\n"
        ".Lfc7f00_000c7fc2:\n"
        "orb %bl, %al\n" /* line 1712 */
        "jne .Lfc7f00_000c819a\n"
        ".Lfc7f00_000c7fca:\n"
        "movl imp_r_sun_from_dvars, %eax\n" /* line 1726 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7f00_000c7ff3\n"
        ".Lfc7f00_000c7fd7:\n"
        "movl imp_rgp, %eax\n"
        "movl 0x109c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc7f00_000c7ff3\n"
        "addl $0x160, %eax\n" /* line 1727 */
        "movl %eax, (%esp)\n"
        "calll R_SetSunFromDvars\n"
        ".Lfc7f00_000c7ff3:\n"
        "movl imp_r_gpuSync, %eax\n" /* line 1684 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c80cb\n"
        "xorl %ebx, %ebx\n"
        "movl imp_r_multiGpu, %eax\n" /* line 1685 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "jne .Lfc7f00_000c80ef\n"
        ".Lfc7f00_000c8017:\n"
        "xorl %eax, %eax\n"
        "orb %bl, %al\n" /* line 1731 */
        "jne .Lfc7f00_000c810a\n"
        ".Lfc7f00_000c8021:\n"
        "movl imp_r_forceLod, %ecx\n" /* line 1695 */
        "movl (%ecx), %edx\n"
        "movl 8(%edx), %eax\n"
        "cmpl 0x10(%edx), %eax\n"
        "je .Lfc7f00_000c8123\n"
        ".Lfc7f00_000c8035:\n"
        "xorl %ebx, %ebx\n"
        "movl imp_ri, %eax\n" /* line 1698 */
        "movl 0x178(%eax), %edx\n"
        "movl (%ecx), %eax\n"
        "cmpl %ebx, 8(%eax)\n"
        "je .Lfc7f00_000c8077\n"
        ".Lfc7f00_000c8049:\n"
        "movl $0x3a83126f, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *%edx\n"
        "addl $1, %ebx\n" /* line 1697 */
        "cmpl $4, %ebx\n"
        "je .Lfc7f00_000c808a\n"
        ".Lfc7f00_000c805f:\n"
        "movl imp_r_forceLod, %ecx\n"
        "movl imp_ri, %eax\n" /* line 1698 */
        "movl 0x178(%eax), %edx\n"
        "movl (%ecx), %eax\n"
        "cmpl %ebx, 8(%eax)\n"
        "jne .Lfc7f00_000c8049\n"
        ".Lfc7f00_000c8077:\n"
        "xorl %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *%edx\n"
        "addl $1, %ebx\n" /* line 1697 */
        "cmpl $4, %ebx\n"
        "jne .Lfc7f00_000c805f\n"
        ".Lfc7f00_000c808a:\n"
        "movl $0, (%esp)\n" /* line 1762 */
        "movl imp_ri, %eax\n"
        "calll *0x120(%eax)\n"
        "movl imp_r_skinCache, %eax\n" /* line 1765 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7f00_000c80b5\n"
        "movl $0, (%esp)\n" /* line 1766 */
        "calll R_LockSkinnedCache\n"
        ".Lfc7f00_000c80b5:\n"
        "addl $0x14, %esp\n" /* line 1768 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc7f00_000c80bb:\n"
        "movl $0, (%ebx)\n" /* line 1748 */
        "calll Material_Sort\n" /* line 1749 */
        "jmp .Lfc7f00_000c7f25\n"
        ".Lfc7f00_000c80cb:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %ebx\n"
        "movl imp_r_multiGpu, %eax\n" /* line 1685 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c8017\n"
        ".Lfc7f00_000c80ef:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "orb %bl, %al\n" /* line 1731 */
        "je .Lfc7f00_000c8021\n"
        ".Lfc7f00_000c810a:\n"
        "calll R_UpdateGpuSyncType\n" /* line 1732 */
        "movl imp_r_forceLod, %ecx\n" /* line 1695 */
        "movl (%ecx), %edx\n"
        "movl 8(%edx), %eax\n"
        "cmpl 0x10(%edx), %eax\n"
        "jne .Lfc7f00_000c8035\n"
        ".Lfc7f00_000c8123:\n"
        "movl imp_ri, %ebx\n" /* line 1702 */
        "movl imp_r_highLodDist, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *0x178(%ebx)\n"
        "movl imp_r_mediumLodDist, %eax\n" /* line 1703 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll *0x178(%ebx)\n"
        "movl imp_r_lowLodDist, %eax\n" /* line 1704 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll *0x178(%ebx)\n"
        "movl imp_r_lowestLodDist, %eax\n" /* line 1705 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll *0x178(%ebx)\n"
        "jmp .Lfc7f00_000c808a\n"
        ".Lfc7f00_000c819a:\n"
        "calll R_UpdateLightsFromDvars\n" /* line 1713 */
        "movl imp_r_sun_from_dvars, %eax\n" /* line 1726 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfc7f00_000c7ff3\n"
        "jmp .Lfc7f00_000c7fd7\n"
        ".Lfc7f00_000c81b5:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %ebx\n"
        "movl imp_r_lightTweakDiffuseFraction, %eax\n" /* line 1665 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c7f57\n"
        ".Lfc7f00_000c81d9:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "orb %al, %bl\n" /* line 1665 */
        "movl imp_r_lightTweakSunLight, %eax\n" /* line 1666 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c7f6c\n"
        ".Lfc7f00_000c81ff:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "orb %al, %bl\n" /* line 1666 */
        "movl imp_r_lightTweakAmbientColor, %eax\n" /* line 1667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c7f81\n"
        ".Lfc7f00_000c8225:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "orb %al, %bl\n" /* line 1667 */
        "movl imp_r_lightTweakSunColor, %eax\n" /* line 1668 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c7f96\n"
        ".Lfc7f00_000c824b:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "orb %al, %bl\n" /* line 1668 */
        "movl imp_r_lightTweakSunDiffuseColor, %eax\n" /* line 1669 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c7fab\n"
        ".Lfc7f00_000c8271:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "orb %al, %bl\n" /* line 1669 */
        "movl imp_r_lightTweakSunDirection, %eax\n" /* line 1670 */
        "movl (%eax), %eax\n"
        "cmpb $0, 7(%eax)\n" /* line 1640 */
        "je .Lfc7f00_000c7fc0\n"
        ".Lfc7f00_000c8297:\n"
        "movl %eax, (%esp)\n" /* line 1643 */
        "movl imp_ri, %eax\n"
        "calll *0x88(%eax)\n"
        "movl $1, %eax\n"
        "jmp .Lfc7f00_000c7fc2\n"
    );
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
__attribute__((naked))
void R_InitBackendData(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $s_backEndData + 2399512, (%esp)\n" /* line 140 */
        "calll R_InitDebugEntry\n"
        "calll RB_CreateDynamicBuffers\n" /* line 143 */
        "movl frontEndDataOut, %eax\n" /* line 146 */
        "testl %eax, %eax\n"
        "je .Lfc8308_000c834d\n"
        "addl $0x219d0c, %eax\n" /* line 656 */
        "movl $0, 0x30000(%eax)\n" /* line 657 */
        "movl $0, 0x30004(%eax)\n" /* line 658 */
        "movl $0, 0x30008(%eax)\n" /* line 659 */
        "leave\n" /* line 150 */
        "retl\n"
        ".Lfc8308_000c834d:\n"
        "movl $s_backEndData, frontEndDataOut\n" /* line 1067 */
        "movl imp_rg, %eax\n" /* line 1070 */
        "movl 0x1c(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x1c(%eax)\n"
        "movl %edx, s_backEndData\n" /* line 1074 */
        "calll R_UnlockSkinnedCache\n" /* line 1081 */
        "movl imp_dx, %edx\n" /* line 1084 */
        "movl 0x2dcc(%edx), %eax\n"
        "addl $1, %eax\n"
        "andl $0x80000001, %eax\n"
        "js .Lfc8308_000c843b\n"
        ".Lfc8308_000c838a:\n"
        "movl %eax, 0x2dcc(%edx)\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 1085 */
        "leal 0x2d90(%edx, %eax, 4), %eax\n"
        "movl frontEndDataOut, %edx\n"
        "movl %eax, 0x217c78(%edx)\n"
        "movl frontEndDataOut, %eax\n" /* line 1093 */
        "movl 0x217c78(%eax), %eax\n"
        "movl $0, (%eax)\n"
        "movl frontEndDataOut, %edx\n" /* line 1095 */
        "leal 0x219d0c(%edx), %eax\n"
        "movl %eax, s_cmdList\n"
        "movl $0, 4(%edx)\n" /* line 1120 */
        "movl frontEndDataOut, %eax\n" /* line 1121 */
        "movl $0, 0x80008(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1122 */
        "movl $0, 0xa000c(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1123 */
        "movl $0, 0x187c70(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1124 */
        "movl $0, 0x18fc74(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1130 */
        "movl $0, 0x217c7c(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1132 */
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl $0, 0x34(%eax)\n" /* line 1134 */
        "movl $0, 0x1c(%eax)\n" /* line 1135 */
        "movl $0, 4(%eax)\n" /* line 1136 */
        "leave\n" /* line 150 */
        "retl\n"
        ".Lfc8308_000c843b:\n"
        "subl $1, %eax\n" /* line 1084 */
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lfc8308_000c838a\n"
    );
}

/* line 1771 */
__attribute__((naked))
static void R_EndFrame_impl(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1771 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_rg, %eax\n" /* line 1774 */
        "cmpb $0, (%eax)\n"
        "jne .Lfc844a_000c8461\n"
        ".Lfc844a_000c845b:\n"
        "addl $0x14, %esp\n" /* line 1803 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc844a_000c8461:\n"
        "calll RB_AdaptiveGpuSyncTarget\n" /* line 1779 */
        "calll R_UnlockSkinnedCache\n" /* line 1781 */
        "movl imp_ri, %eax\n" /* line 1785 */
        "calll *0x11c(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1787 */
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl %eax, (%esp)\n"
        "calll R_TransferDebugGlobals\n"
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        /* DIAG: print s_cmdList, usedTotal, remaining before backend exec */
        /* Print for frames 1-10 AND 100-110 (gameplay) */
        "cmpl $10, g_endframe_count\n"
        "jle .Lfc844a_diag_print2\n"
        "cmpl $100, g_endframe_count\n"
        "jl .Lfc844a_diag_skip2\n"
        "cmpl $110, g_endframe_count\n"
        "jg .Lfc844a_diag_skip2\n"
        ".Lfc844a_diag_print2:\n"
        "pushal\n"
        "movl $0x30000, %eax\n"
        "subl %ebx, %eax\n"
        "pushl %eax\n"
        "pushl %ebx\n"
        "pushl %ecx\n"
        "pushl $rb_diag_cmdlist_fmt\n"
        "calll printf\n"
        "addl $16, %esp\n"
        "popal\n"
        ".Lfc844a_diag_skip2:\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lfc844a_000c8607\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        ".Lfc844a_000c84ae:\n"
        "movl frontEndDataOut, %eax\n" /* line 864 */
        "movl %eax, (%esp)\n"
        "calll RB_ExecuteRenderCommands\n"
        "calll RB_EndFrame\n" /* line 865 */
        "movl $s_backEndData, frontEndDataOut\n" /* line 1067 */
        "movl imp_rg, %eax\n" /* line 1070 */
        "movl 0x1c(%eax), %edx\n"
        "addl $1, %edx\n"
        "movl %edx, 0x1c(%eax)\n"
        "movl %edx, s_backEndData\n" /* line 1074 */
        "calll R_UnlockSkinnedCache\n" /* line 1081 */
        "movl imp_dx, %ebx\n" /* line 1084 */
        "movl 0x2dcc(%ebx), %eax\n"
        "addl $1, %eax\n"
        "andl $0x80000001, %eax\n"
        "js .Lfc844a_000c8630\n"
        ".Lfc844a_000c8525:\n"
        "movl %eax, 0x2dcc(%ebx)\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 1085 */
        "leal 0x2d90(%ebx, %eax, 4), %eax\n"
        "movl frontEndDataOut, %edx\n"
        "movl %eax, 0x217c78(%edx)\n"
        "movl frontEndDataOut, %eax\n" /* line 1093 */
        "movl 0x217c78(%eax), %eax\n"
        "movl $0, (%eax)\n"
        "movl frontEndDataOut, %edx\n" /* line 1095 */
        "leal 0x219d0c(%edx), %eax\n"
        "movl %eax, s_cmdList\n"
        "movl $0, 4(%edx)\n" /* line 1120 */
        "movl frontEndDataOut, %eax\n" /* line 1121 */
        "movl $0, 0x80008(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1122 */
        "movl $0, 0xa000c(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1123 */
        "movl $0, 0x187c70(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1124 */
        "movl $0, 0x18fc74(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1130 */
        "movl $0, 0x217c7c(%eax)\n"
        "movl frontEndDataOut, %eax\n" /* line 1132 */
        "addl $0x249d18, %eax\n" /* "x;
DP4 oPos.y, v0, c23[1];
MAX r0.w, r0.w, c0.y;
DP4 oPos.z," */
        "movl $0, 0x34(%eax)\n" /* line 1134 */
        "movl $0, 0x1c(%eax)\n" /* line 1135 */
        "movl $0, 4(%eax)\n" /* line 1136 */
        "movl 0x2dd4(%ebx), %eax\n" /* line 830 */
        "testl %eax, %eax\n"
        "je .Lfc844a_000c845b\n"
        "movl %eax, 4(%esp)\n" /* line 832 */
        "movl 0x2dd0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x28(%eax)\n"
        "movl $0, 0x2dd4(%ebx)\n" /* line 833 */
        "addl $0x14, %esp\n" /* line 1803 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc844a_000c8607:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 4(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $4, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0, (%edx)\n" /* line 964 */
        "movw $4, 2(%edx)\n" /* line 965 */
        "jmp .Lfc844a_000c84ae\n"
        ".Lfc844a_000c8630:\n"
        "subl $1, %eax\n" /* line 1084 */
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lfc844a_000c8525\n"
    );
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
    char *cmdList = (char *)s_cmdList;
    int used = *(int *)(cmdList + 0x30000);
    if (0x30000 - used > 3) {
        char *cmd = cmdList + used;
        *(int *)(cmdList + 0x30000) = used + 4;
        *(int *)(cmdList + 0x30004) += 4;
        *(int *)(cmdList + 0x30008) = (int)cmd;
        *(short *)cmd = 3;
        *(short *)(cmd + 2) = 4;
        used = *(int *)(cmdList + 0x30000);
    } else {
        *(int *)(cmdList + 0x30008) = 0;
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

    cmdText = (char *)((byte *)cmd + 0x2c);
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

    cmdText = (char *)((byte *)cmd + 0x30);
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
__attribute__((naked))
void R_EndDebugFrame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1838 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_rg, %eax\n" /* line 1841 */
        "cmpb $0, (%eax)\n"
        "je .Lfc9240_000c92e2\n"
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lfc9240_000c92e8\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        ".Lfc9240_000c9277:\n"
        "movl frontEndDataOut, %eax\n" /* line 1848 */
        "movl %eax, (%esp)\n"
        "calll RB_ExecuteRenderCommands\n"
        "calll RB_EndFrame\n" /* line 1849 */
        "movl s_debugFrameGlob, %eax\n" /* line 1851 */
        "movl %eax, s_cmdList\n"
        "movl s_debugFrameGlob+4, %eax\n" /* line 1852 */
        "movl %eax, frontEndDataOut\n"
        "cmpb $0, s_debugFrameGlob+8\n" /* line 1855 */
        "jne .Lfc9240_000c9311\n"
        ".Lfc9240_000c92ce:\n"
        "movl $0, s_debugFrameGlob\n" /* line 1862 */
        "movl $0, s_debugFrameGlob+4\n" /* line 1863 */
        ".Lfc9240_000c92e2:\n"
        "addl $0x14, %esp\n" /* line 1864 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc9240_000c92e8:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 4(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $4, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0, (%edx)\n" /* line 964 */
        "movw $4, 2(%edx)\n" /* line 965 */
        "jmp .Lfc9240_000c9277\n"
        ".Lfc9240_000c9311:\n"
        "movb $0, s_debugFrameGlob+8\n" /* line 1857 */
        "movl $1, (%esp)\n" /* line 1858 */
        "calll R_LockSkinnedCache\n"
        "jmp .Lfc9240_000c92ce\n"
    );
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
