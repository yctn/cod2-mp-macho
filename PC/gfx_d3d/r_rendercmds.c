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

/* line 158 */
void R_ShutdownBackendData(void)
{
    R_ShutdownDebugEntry((void *)((char *)&s_backEndData + 2399512));
}

/* line 253 */
static __attribute__((naked)) __attribute__((regparm(3)))
void R_ProcessFrontendCmdInternal(int type, void *data, int isRenderThread)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 253 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $7, %eax\n" /* line 255 | type */
        "ja .Lfc7d30_000c7d4e\n"
        "jmpl *.Ljt_c7d30_0(, %eax, 4)\n"
        ".Lfc7d30_000c7d42:\n"
        "movl %ecx, 4(%esp)\n" /* line 271 | context */
        "movl %edx, (%esp)\n" /* data */
        "calll R_SkinXModelCmd\n"
        ".Lfc7d30_000c7d4e:\n"
        "leave\n" /* line 298 */
        "retl\n"
        ".Lfc7d30_000c7d50:\n"
        "movl (%edx), %eax\n" /* line 258 | data, type */
        "movl %eax, (%esp)\n" /* type */
        "calll R_UpdateGfxEntityBounds\n"
        "leave\n" /* line 298 */
        "retl\n"
        ".Lfc7d30_000c7d5c:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 276 | context, type */
        "shll $0xd, %eax\n" /* type */
        "addl $g_skinBuffers, %eax\n" /* type */
        "movl %eax, 4(%esp)\n" /* type */
        "movl %edx, (%esp)\n" /* data */
        "calll R_SkinStaticModelCachedCmd\n"
        "leave\n" /* line 298 */
        "retl\n"
        ".Lfc7d30_000c7d75:\n"
        "leave\n"
        "jmp FX_UpdateScheduledEffectsBolt\n" /* line 281 */
        ".Lfc7d30_000c7d7b:\n"
        "leave\n" /* line 298 */
        "jmp FX_UpdateScheduledEffectsNonBolt\n" /* line 288 */
        ".Lfc7d30_000c7d81:\n"
        "movl %edx, (%esp)\n" /* line 266 | data */
        "calll R_SkinRigidXModelCmd\n"
        "leave\n" /* line 298 */
        "retl\n"
        ".Lfc7d30_000c7d8b:\n"
        "movl (%edx), %eax\n" /* line 262 | data, type */
        "movl %eax, (%esp)\n" /* type */
        "calll R_SkinGfxEntity\n"
        "leave\n" /* line 298 */
        "retl\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_c7d30_0:\n"
        ".long .Lfc7d30_000c7d50\n"
        ".long .Lfc7d30_000c7d8b\n"
        ".long .Lfc7d30_000c7d81\n"
        ".long .Lfc7d30_000c7d7b\n"
        ".long .Lfc7d30_000c7d75\n"
        ".long .Lfc7d30_000c7d5c\n"
        ".long .Lfc7d30_000c7d42\n"
        ".long .Lfc7d30_000c7d42\n"
        ".text\n"
    );
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
__attribute__((naked))
void R_AbortRenderCommands(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 889 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl imp_rg, %eax\n" /* line 894 */
        "cmpb $0, (%eax)\n"
        "jne .Lfc7e86_000c7e9d\n"
        ".Lfc7e86_000c7e97:\n"
        "addl $0x14, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfc7e86_000c7e9d:\n"
        "calll R_UnlockSkinnedCache\n" /* line 903 */
        "movl frontEndDataOut, %eax\n" /* line 656 */
        "addl $0x219d0c, %eax\n" /* offset into GfxBackEndData */
        "movl $0, 0x30000(%eax)\n" /* line 657 */
        "movl $0, 0x30004(%eax)\n" /* line 658 */
        "movl $0, 0x30008(%eax)\n" /* line 659 */
        "movl imp_dx, %ebx\n" /* line 830 */
        "movl 0x2dd4(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc7e86_000c7e97\n"
        "movl %eax, 4(%esp)\n" /* line 832 */
        "movl 0x2dd0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x28(%eax)\n"
        "movl $0, 0x2dd4(%ebx)\n" /* line 833 */
        "addl $0x14, %esp\n" /* line 923 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
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
__attribute__((naked))
void R_AddCmdDrawSurfs(GfxDrawSurf *drawSurfs, int drawSurfCount, MaterialTechniqueType techType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1506 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x13, %eax\n"
        "jg .Lfc863e_000c8672\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc863e_000c866f:\n"
        "popl %ebx\n" /* line 1509 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc863e_000c8672:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x14(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x17, (%edx)\n" /* line 964 */
        "movw $0x14, 2(%edx)\n" /* line 965 */
        "movl %edx, %eax\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1496 */
        "je .Lfc863e_000c866f\n"
        "movl $0, 4(%edx)\n" /* line 1499 */
        "movl 8(%ebp), %edx\n" /* line 1500 | drawSurfs */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 1501 | drawSurfCount */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 1502 | techType */
        "movl %edx, 0x10(%eax)\n"
        "popl %ebx\n" /* line 1509 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 991 */
__attribute__((naked))
int R_BeginDelayedDrawing(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 991 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 998 */
        "movl 0x30000(%ecx), %ebx\n" /* marker */
        /* { scope 2 */
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lfc86b2_000c86e6\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %eax, %eax\n"
        /* } scope */
        "movl $0, 4(%eax)\n" /* line 1003 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1010 | marker */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc86b2_000c86e6:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 8(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $8, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $1, (%edx)\n" /* line 964 */
        "movw $8, 2(%edx)\n" /* line 965 */
        "movl %edx, %eax\n"
        /* } scope */
        "movl $0, 4(%eax)\n" /* line 1003 */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1010 | marker */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
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
__attribute__((naked))
void R_IssueDelayedDrawing(int marker)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1037 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lfc8780_000c87b5\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %edx, %edx\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1053 | marker */
        "leal 8(%ecx, %eax), %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebx\n" /* line 1054 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc8780_000c87b5:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 8(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $8, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $2, (%edx)\n" /* line 964 */
        "movw $8, 2(%edx)\n" /* line 965 */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1053 | marker */
        "leal 8(%ecx, %eax), %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebx\n" /* line 1054 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1153 */
int g_addcmd_count = 0; /* diagnostic */
static int g_addcmd_diag = 0;
void diag_addcmd_hex(unsigned int xi, unsigned int yi) {
    (void)g_addcmd_diag;
    (void)xi;
    (void)yi;
}
__attribute__((naked))
void R_AddCmdDrawStretchPic(float x, float y, float w, float h, float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1153 */
        "movl %esp, %ebp\n"
        "incl g_addcmd_count\n"
        /* DIAGNOSTIC: dump x,y,retaddr */
        "pushal\n"
        "pushl 4(%ebp)\n"
        "pushl 0xc(%ebp)\n"
        "pushl 8(%ebp)\n"
        "calll diag_addcmd\n"
        "addl $12, %esp\n"
        "popal\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %edi\n" /* x */
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, -0x10(%ebp)\n" /* y */
        "movss 0x10(%ebp), %xmm0\n" /* w */
        "movss %xmm0, -0x14(%ebp)\n" /* w */
        "movss 0x14(%ebp), %xmm0\n" /* h */
        "movss %xmm0, -0x18(%ebp)\n" /* h */
        "movss 0x18(%ebp), %xmm0\n" /* s0 */
        "movss %xmm0, -0x1c(%ebp)\n" /* s0 */
        "movss 0x1c(%ebp), %xmm0\n" /* t0 */
        "movss %xmm0, -0x20(%ebp)\n" /* t0 */
        "movss 0x20(%ebp), %xmm0\n" /* s1 */
        "movss %xmm0, -0x24(%ebp)\n" /* s1 */
        "movss 0x24(%ebp), %xmm0\n" /* t1 */
        "movss %xmm0, -0x28(%ebp)\n" /* t1 */
        "movl 0x28(%ebp), %eax\n" /* color */
        "movl %eax, -0x2c(%ebp)\n" /* color */
        "movl 0x2c(%ebp), %esi\n" /* material */
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x2b, %eax\n"
        "jg .Lfc87e6_000c8876\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc87e6_000c886e:\n"
        "addl $0x20, %esp\n" /* line 1172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc87e6_000c8876:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x2c(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0xf, (%edx)\n" /* line 964 */
        "movw $0x2c, 2(%edx)\n" /* line 965 */
        "movl %edx, %eax\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1159 */
        "je .Lfc87e6_000c886e\n"
        "movl %esi, 4(%edx)\n" /* line 1162 | material */
        "movl %edi, 8(%edx)\n" /* line 1163 | x */
        "movss -0x10(%ebp), %xmm0\n" /* line 1164 | y */
        "movss %xmm0, 0xc(%edx)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 1165 | w */
        "movss %xmm0, 0x10(%edx)\n"
        "movss -0x18(%ebp), %xmm0\n" /* line 1166 | h */
        "movss %xmm0, 0x14(%edx)\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 1167 | s0 */
        "movss %xmm0, 0x18(%edx)\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 1168 | t0 */
        "movss %xmm0, 0x1c(%edx)\n"
        "movss -0x24(%ebp), %xmm0\n" /* line 1169 | s1 */
        "movss %xmm0, 0x20(%edx)\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 1170 | t1 */
        "movss %xmm0, 0x24(%edx)\n"
        "addl $0x28, %eax\n" /* line 1171 */
        "movl %eax, 0xc(%ebp)\n" /* y */
        "movl -0x2c(%ebp), %eax\n" /* color */
        "movl %eax, 8(%ebp)\n" /* x */
        "addl $0x20, %esp\n" /* line 1172 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp R_ConvertColorToBytes\n" /* line 1171 */
    );
}

/* line 1175 */
__attribute__((naked))
void R_AddCmdDrawStretchPicRotate(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float angle, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1175 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x2f, %eax\n"
        "jg .Lfc88fe_000c8938\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc88fe_000c8932:\n"
        "addl $0x14, %esp\n" /* line 1195 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc88fe_000c8938:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x30(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x10, (%edx)\n" /* line 964 */
        "movw $0x30, 2(%edx)\n" /* line 965 */
        "movl %edx, %ebx\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1181 */
        "je .Lfc88fe_000c8932\n"
        "movl 0x30(%ebp), %eax\n" /* line 1184 | material */
        "movl %eax, 4(%edx)\n"
        "movss 8(%ebp), %xmm0\n" /* line 1185 | x */
        "movss %xmm0, 8(%edx)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 1186 | y */
        "movss %xmm0, 0xc(%edx)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 1187 | w */
        "movss %xmm0, 0x10(%edx)\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 1188 | h */
        "movss %xmm0, 0x14(%edx)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 1189 | s0 */
        "movss %xmm0, 0x18(%edx)\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 1190 | t0 */
        "movss %xmm0, 0x1c(%edx)\n"
        "movss 0x20(%ebp), %xmm0\n" /* line 1191 | s1 */
        "movss %xmm0, 0x20(%edx)\n"
        "movss 0x24(%ebp), %xmm0\n" /* line 1192 | t1 */
        "movss %xmm0, 0x24(%edx)\n"
        "leal 0x28(%edx), %eax\n" /* line 1193 */
        "movl %eax, 4(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* color */
        "movl %eax, (%esp)\n"
        "calll R_ConvertColorToBytes\n"
        "movss 0x28(%ebp), %xmm0\n" /* line 1194 | angle */
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c(%ebx)\n"
        "addl $0x14, %esp\n" /* line 1195 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1198 */
__attribute__((naked))
void R_AddCmdDrawStretchRaw(int x, int y, int w, int h, int cols, int rows, const byte *data, int client, qboolean dirty)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1198 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x27, %eax\n"
        "jg .Lfc89dc_000c8a10\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc89dc_000c8a0d:\n"
        "popl %ebx\n" /* line 1216 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc89dc_000c8a10:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x28(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x11, (%edx)\n" /* line 964 */
        "movw $0x28, 2(%edx)\n" /* line 965 */
        "movl %edx, %eax\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1204 */
        "je .Lfc89dc_000c8a0d\n"
        "movl 8(%ebp), %edx\n" /* line 1207 | x */
        "movl %edx, 4(%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 1208 | y */
        "movl %edx, 8(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* line 1209 | w */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x14(%ebp), %edx\n" /* line 1210 | h */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x18(%ebp), %edx\n" /* line 1211 | cols */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x1c(%ebp), %edx\n" /* line 1212 | rows */
        "movl %edx, 0x18(%eax)\n"
        "movl 0x20(%ebp), %edx\n" /* line 1213 | data */
        "movl %edx, 0x1c(%eax)\n"
        "movl 0x24(%ebp), %edx\n" /* line 1214 | client */
        "movl %edx, 0x20(%eax)\n"
        "movl 0x28(%ebp), %edx\n" /* line 1215 | dirty */
        "movl %edx, 0x24(%eax)\n"
        "popl %ebx\n" /* line 1216 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1219 */
__attribute__((naked))
void R_AddCmdDrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1219 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* text */
        "movl 0x30(%ebp), %eax\n" /* cursor */
        "movl %eax, -0x20(%ebp)\n"
        /* { scope 1 */
        "cmpb $0, (%esi)\n" /* line 1227 | text */
        "jne .Lfc8a6c_000c8a8e\n"
        "movl 0x2c(%ebp), %ebx\n" /* cursorPos */
        "testl %ebx, %ebx\n"
        "js .Lfc8a6c_000c8b66\n"
        ".Lfc8a6c_000c8a8e:\n"
        "cld\n" /* line 1230 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* text */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* len */
        "leal 0x30(%ecx), %ebx\n" /* line 1236 */
        "andl $0xfffffffc, %ebx\n"
        /* { scope 2 */
        "movl s_cmdList, %edi\n" /* line 950 */
        "movl 0x30000(%edi), %ecx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ecx, %eax\n"
        "addl 0x30004(%edi), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl %eax, %ebx\n"
        "jg .Lfc8a6c_000c8b6e\n"
        "leal (%edi, %ecx), %edx\n" /* line 960 */
        "leal (%ebx, %ecx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%edi)\n"
        "movl %edx, 0x30008(%edi)\n" /* line 963 */
        "movw $0x15, (%edx)\n" /* line 964 */
        "movw %bx, 2(%edx)\n" /* line 965 */
        "movl %edx, %edi\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1240 */
        "je .Lfc8a6c_000c8b66\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 1243 | x */
        "movss %xmm0, 4(%edx)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 1244 | y */
        "movss %xmm0, 8(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1245 | font */
        "movl %eax, 0xc(%edx)\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 1246 | xScale */
        "movss %xmm0, 0x10(%edx)\n"
        "movss 0x20(%ebp), %xmm0\n" /* line 1247 | yScale */
        "movss %xmm0, 0x14(%edx)\n"
        "leal 0x18(%edx), %eax\n" /* line 1248 */
        "movl %eax, 4(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* color */
        "movl %eax, (%esp)\n"
        "calll R_ConvertColorToBytes\n"
        "movl 0x28(%ebp), %edx\n" /* line 1249 | style */
        "movl %edx, 0x1c(%edi)\n"
        "movl 0x2c(%ebp), %eax\n" /* line 1250 | cursorPos */
        "movl %eax, 0x20(%edi)\n"
        "movzbl -0x20(%ebp), %edx\n" /* line 1251 */
        "movb %dl, 0x24(%edi)\n"
        "movl 0xc(%ebp), %eax\n" /* line 1252 | maxChars */
        "movl %eax, 0x28(%edi)\n"
        "leal 0x2c(%edi), %eax\n" /* line 1255 */
        "movl -0x1c(%ebp), %edx\n" /* len */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* text */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1258 | len */
        "movb $0, 0x2c(%eax, %edi)\n"
        /* } scope */
        ".Lfc8a6c_000c8b66:\n"
        "addl $0x2c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc8a6c_000c8b6e:\n"
        "movl $0, 0x30008(%edi)\n" /* line 956 */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1259 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1262 */
__attribute__((naked))
void R_AddCmdDrawTextInSpace(const char *text, FontHandle font, const vec_t *org, const vec_t *xPixelStep, const vec_t *yPixelStep, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1262 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* text */
        /* { scope 1 */
        "cmpb $0, (%esi)\n" /* line 1269 | text */
        "jne .Lfc8b80_000c8b99\n"
        /* } scope */
        ".Lfc8b80_000c8b91:\n"
        "addl $0x2c, %esp\n" /* line 1296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc8b80_000c8b99:\n"
        "cld\n" /* line 1272 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* text */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* len */
        "leal 0x33(%ecx), %ebx\n" /* line 1278 */
        "andl $0xfffffffc, %ebx\n"
        /* { scope 2 */
        "movl s_cmdList, %edi\n" /* line 950 */
        "movl 0x30000(%edi), %ecx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ecx, %eax\n"
        "addl 0x30004(%edi), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl %eax, %ebx\n"
        "jle .Lfc8b80_000c8be7\n"
        "movl $0, 0x30008(%edi)\n" /* line 956 */
        /* } scope */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc8b80_000c8be7:\n"
        "leal (%edi, %ecx), %edx\n" /* line 960 */
        "leal (%ebx, %ecx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%edi)\n"
        "movl %edx, 0x30008(%edi)\n" /* line 963 */
        "movw $0x16, (%edx)\n" /* line 964 */
        "movw %bx, 2(%edx)\n" /* line 965 */
        "movl %edx, %ebx\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1282 */
        "je .Lfc8b80_000c8b91\n"
        "leal 4(%edx), %edx\n" /* line 1285 | to */
        /* { scope 2 */
        "movl 0x10(%ebp), %ecx\n" /* line 199 | org */
        "movl (%ecx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1286 | font */
        "movl %eax, 0x10(%ebx)\n"
        "leal 0x14(%ebx), %edx\n" /* line 1287 | to */
        /* { scope 2 */
        "movl 0x14(%ebp), %ecx\n" /* line 199 | xPixelStep */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x20(%ebx), %edx\n" /* line 1288 | to */
        /* { scope 2 */
        "movl 0x18(%ebp), %ecx\n" /* line 199 | yPixelStep */
        "movl (%ecx), %eax\n"
        "movl %eax, 0x20(%ebx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0x2c(%ebx), %eax\n" /* line 1289 */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* color */
        "movl %eax, (%esp)\n"
        "calll R_ConvertColorToBytes\n"
        "leal 0x30(%ebx), %eax\n" /* line 1292 */
        "movl -0x1c(%ebp), %edx\n" /* len */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* text */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 1295 | len */
        "movb $0, 0x30(%ecx, %ebx)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1296 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1299 */
__attribute__((naked))
void R_AddCmdDrawQuadPic(vec2_t *verts, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1299 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %edi\n" /* verts */
        "movl 0xc(%ebp), %eax\n" /* color */
        "movl %eax, -0x10(%ebp)\n" /* color */
        "movl 0x10(%ebp), %eax\n" /* material */
        "movl %eax, -0x14(%ebp)\n" /* material */
        /* { scope 1 */
        /* { scope 2 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x2b, %eax\n"
        "jg .Lfc8c8c_000c8cd9\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        /* } scope */
        ".Lfc8c8c_000c8cd1:\n"
        "addl $8, %esp\n" /* line 1313 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfc8c8c_000c8cd9:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x2c(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x12, (%edx)\n" /* line 964 */
        "movw $0x2c, 2(%edx)\n" /* line 965 */
        "movl %edx, %esi\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1306 */
        "je .Lfc8c8c_000c8cd1\n"
        "movl -0x14(%ebp), %eax\n" /* line 1309 | material */
        "movl %eax, 4(%edx)\n"
        "xorl %ebx, %ebx\n" /* cornerIndex */
        ".Lfc8c8c_000c8d04:\n"
        "leal (, %ebx, 8), %eax\n" /* line 1311 */
        "leal (%esi, %eax), %ecx\n"
        "addl %edi, %eax\n" /* line 1299 | verts */
        "movl (%eax), %edx\n" /* line 37 */
        "movl %edx, 8(%ecx)\n"
        "movl 4(%eax), %eax\n" /* line 38 */
        "movl %eax, 0xc(%ecx)\n"
        "addl $1, %ebx\n" /* line 1310 | cornerIndex */
        "cmpl $4, %ebx\n" /* cornerIndex */
        "jne .Lfc8c8c_000c8d04\n"
        "leal 0x28(%esi), %eax\n" /* line 1312 */
        "movl %eax, 0xc(%ebp)\n" /* color */
        "movl -0x10(%ebp), %eax\n" /* color */
        "movl %eax, 8(%ebp)\n" /* verts */
        /* } scope */
        "addl $8, %esp\n" /* line 1313 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp R_ConvertColorToBytes\n" /* line 1312 */
    );
}

/* line 1316 */
__attribute__((naked))
void R_AddCmdDrawSprite(MaterialHandle material, const byte *rgbaColor, const vec_t *pos, float radius, float minScreenRadius, int renderFxFlags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1316 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0x10(%ebp), %esi\n" /* pos */
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x23, %eax\n"
        "jg .Lfc8d3c_000c8d75\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc8d3c_000c8d71:\n"
        "popl %ebx\n" /* line 1331 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc8d3c_000c8d75:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x24(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x13, (%edx)\n" /* line 964 */
        "movw $0x24, 2(%edx)\n" /* line 965 */
        "movl %edx, %ecx\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1322 */
        "je .Lfc8d3c_000c8d71\n"
        "movl 8(%ebp), %eax\n" /* line 1325 | material */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 606 | rgbaColor */
        "movl (%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "leal 0xc(%ecx), %edx\n" /* line 1327 | to */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 199 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movss 0x14(%ebp), %xmm0\n" /* line 1328 | radius */
        "movss %xmm0, 0x18(%ecx)\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 1329 | minScreenRadius */
        "movss %xmm0, 0x1c(%ecx)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1330 | renderFxFlags */
        "movl %eax, 0x20(%ecx)\n"
        "popl %ebx\n" /* line 1331 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1334 */
__attribute__((naked))
void R_AddCmdDrawFullScreenColoredQuad(float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1334 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edi\n" /* s0 */
        "movss 0xc(%ebp), %xmm0\n" /* t0 */
        "movss %xmm0, -0x10(%ebp)\n" /* t0 */
        "movss 0x10(%ebp), %xmm0\n" /* s1 */
        "movss %xmm0, -0x14(%ebp)\n" /* s1 */
        "movss 0x14(%ebp), %xmm0\n" /* t1 */
        "movss %xmm0, -0x18(%ebp)\n" /* t1 */
        "movl 0x18(%ebp), %eax\n" /* color */
        "movl %eax, -0x1c(%ebp)\n" /* color */
        "movl 0x1c(%ebp), %esi\n" /* material */
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0x1b, %eax\n"
        "jg .Lfc8dd8_000c8e40\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc8dd8_000c8e38:\n"
        "addl $0x10, %esp\n" /* line 1349 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc8dd8_000c8e40:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x1c(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x14, (%edx)\n" /* line 964 */
        "movw $0x1c, 2(%edx)\n" /* line 965 */
        "movl %edx, %eax\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1340 */
        "je .Lfc8dd8_000c8e38\n"
        "movl %esi, 4(%edx)\n" /* line 1343 | material */
        "movl %edi, 8(%edx)\n" /* line 1344 | s0 */
        "movss -0x10(%ebp), %xmm0\n" /* line 1345 | t0 */
        "movss %xmm0, 0xc(%edx)\n"
        "movss -0x14(%ebp), %xmm0\n" /* line 1346 | s1 */
        "movss %xmm0, 0x10(%edx)\n"
        "movss -0x18(%ebp), %xmm0\n" /* line 1347 | t1 */
        "movss %xmm0, 0x14(%edx)\n"
        "addl $0x18, %eax\n" /* line 1348 */
        "movl %eax, 0xc(%ebp)\n" /* t0 */
        "movl -0x1c(%ebp), %eax\n" /* color */
        "movl %eax, 8(%ebp)\n" /* s0 */
        "addl $0x10, %esp\n" /* line 1349 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp R_ConvertColorToBytes\n" /* line 1348 */
    );
}

/* line 1352 */
__attribute__((naked))
void R_AddCmdSetMaterialColor(const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1352 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* color */
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $0x13, %eax\n"
        "jg .Lfc8ea0_000c8eee\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %ecx, %ecx\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 1360 | color */
        "je .Lfc8ea0_000c8f18\n"
        ".Lfc8ea0_000c8ed0:\n"
        "leal 4(%ecx), %edx\n" /* line 1361 | to */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 456 */
        "movl %eax, 4(%ecx)\n"
        "movl 4(%esi), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "popl %ebx\n" /* line 1364 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc8ea0_000c8eee:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x14(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $0x14, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $4, (%edx)\n" /* line 964 */
        "movw $0x14, 2(%edx)\n" /* line 965 */
        "movl %edx, %ecx\n"
        /* } scope */
        "testl %esi, %esi\n" /* line 1360 | color */
        "jne .Lfc8ea0_000c8ed0\n"
        ".Lfc8ea0_000c8f18:\n"
        "leal 4(%ecx), %edx\n" /* line 1363 | v */
        /* { scope 1 */
        "xorl %eax, %eax\n" /* line 438 */
        "movl %eax, 4(%ecx)\n"
        "movl %eax, 4(%edx)\n" /* line 439 */
        "movl %eax, 8(%edx)\n" /* line 440 */
        "movl %eax, 0xc(%edx)\n" /* line 441 */
        /* } scope */
        "popl %ebx\n" /* line 1364 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1367 */
__attribute__((naked))
void R_AddCmdLightProperties(int lightIndex, const GfxLight *light)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1367 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl s_cmdList, %ebx\n" /* line 950 */
        "movl 0x30000(%ebx), %esi\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %esi, %eax\n"
        "cmpl $0x4b, %eax\n"
        "jg .Lfc8f2e_000c9035\n"
        "movl $0, 0x30008(%ebx)\n" /* line 956 */
        "movl $0, -0x10(%ebp)\n"
        "movl -0x10(%ebp), %edx\n"
        /* } scope */
        ".Lfc8f2e_000c8f67:\n"
        "movl 8(%ebp), %eax\n" /* line 1378 | lightIndex */
        "movl %eax, 4(%edx)\n"
        "movl %edx, %ecx\n" /* line 1379 | from, to */
        "addl $8, %ecx\n" /* to */
        "movl 0xc(%ebp), %edx\n" /* light, from */
        "addl $4, %edx\n" /* from */
        /* { scope 1 */
        "movl 0xc(%ebp), %ebx\n" /* line 456 | light */
        "movl 4(%ebx), %eax\n"
        "movl -0x10(%ebp), %esi\n"
        "movl %eax, 8(%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1380 | light */
        "movl 0x1c(%eax), %ebx\n" /* z */
        "movl 0x18(%eax), %edx\n" /* y */
        "movl %esi, %ecx\n" /* v */
        "addl $0x28, %ecx\n" /* v */
        /* { scope 1 */
        "movl 0x14(%eax), %eax\n" /* line 447 */
        "movl -0x10(%ebp), %esi\n"
        "movl %eax, 0x28(%esi)\n"
        "movl %edx, 4(%ecx)\n" /* line 448 */
        "movl %ebx, 8(%ecx)\n" /* line 449 */
        "movl $0x3f800000, %esi\n" /* line 450 */
        "movl %esi, 0xc(%ecx)\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 1381 | light */
        "movl 0x28(%eax), %edi\n" /* z */
        "movl 0x24(%eax), %ebx\n" /* y */
        "movl -0x10(%ebp), %edx\n" /* v */
        "addl $0x18, %edx\n" /* v */
        /* { scope 1 */
        "movss 0x20(%eax), %xmm0\n" /* line 447 */
        "movl -0x10(%ebp), %eax\n"
        "movss %xmm0, 0x18(%eax)\n"
        "movl %ebx, 4(%edx)\n" /* line 448 */
        "movl %edi, 8(%edx)\n" /* line 449 */
        "movl %esi, 0xc(%edx)\n" /* line 450 */
        /* } scope */
        "movl %eax, %edx\n" /* line 1382 | result */
        "addl $0x38, %edx\n" /* result */
        "movl imp_r_specularColorScale, %eax\n"
        "movl (%eax), %eax\n"
        "movss 8(%eax), %xmm1\n" /* scale */
        /* { scope 1 */
        "movaps %xmm1, %xmm0\n" /* line 519 */
        "movl -0x10(%ebp), %ebx\n"
        "mulss 0x28(%ebx), %xmm0\n"
        "movss %xmm0, 0x38(%ebx)\n"
        "movaps %xmm1, %xmm0\n" /* line 520 */
        "mulss 4(%ecx), %xmm0\n"
        "movss %xmm0, 4(%edx)\n"
        "movaps %xmm1, %xmm0\n" /* line 521 */
        "mulss 8(%ecx), %xmm0\n"
        "movss %xmm0, 8(%edx)\n"
        "mulss 0xc(%ecx), %xmm1\n" /* line 522 */
        "movss %xmm1, 0xc(%edx)\n"
        /* } scope */
        "movl 0xc(%ebp), %esi\n" /* line 1383 | light */
        "movl (%esi), %eax\n"
        "movl %eax, 0x48(%ebx)\n" /* y */
        "addl $8, %esp\n" /* line 1384 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc8f2e_000c9035:\n"
        "leal (%ebx, %esi), %edx\n" /* line 960 */
        "leal 0x4c(%esi), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ebx)\n"
        "addl $0x4c, 0x30004(%ebx)\n" /* line 962 */
        "movl %edx, 0x30008(%ebx)\n" /* line 963 */
        "movw $5, (%edx)\n" /* line 964 */
        "movw $0x4c, 2(%edx)\n" /* line 965 */
        "movl %edx, -0x10(%ebp)\n"
        "jmp .Lfc8f2e_000c8f67\n"
    );
}

/* line 1452 */
__attribute__((naked))
void R_AddCmdSetRenderTarget(GfxRenderTargetId renderTargetId)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1452 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lfc9062_000c9093\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %edx, %edx\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1459 | renderTargetId */
        "movl %eax, 4(%edx)\n"
        "popl %ebx\n" /* line 1460 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc9062_000c9093:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 8(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $8, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0xe, (%edx)\n" /* line 964 */
        "movw $8, 2(%edx)\n" /* line 965 */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1459 | renderTargetId */
        "movl %eax, 4(%edx)\n"
        "popl %ebx\n" /* line 1460 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1518 */
__attribute__((naked))
void R_AddCmdDrawSun(int viewIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1518 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lfc90c0_000c90fc\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %edx, %edx\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1527 | viewIndex */
        "movl %eax, 4(%edx)\n"
        "popl %ebx\n" /* line 1528 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc90c0_000c90fc:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 8(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x18, (%edx)\n" /* line 964 */
        "movw $8, 2(%edx)\n" /* line 965 */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1527 | viewIndex */
        "movl %eax, 4(%edx)\n"
        "popl %ebx\n" /* line 1528 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1604 */
__attribute__((naked))
void R_AddCmdBeginView(int viewCount, const GfxSceneDef *sceneDef, const GfxViewParms *viewParms, const GfxLodParms *lodParms)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1604 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* sceneDef */
        "movl 0x14(%ebp), %edi\n" /* lodParms */
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $0x2f, %eax\n"
        "jg .Lfc9122_000c9197\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %edx, %edx\n"
        /* } scope */
        ".Lfc9122_000c9152:\n"
        "movl 8(%ebp), %eax\n" /* line 1613 | viewCount */
        "movl %eax, 0x2c(%edx)\n"
        "movl (%esi), %eax\n" /* line 1614 | sceneDef */
        "movl %eax, 4(%edx)\n"
        "movl 4(%esi), %eax\n" /* sceneDef */
        "movl %eax, 8(%edx)\n"
        "movl 8(%esi), %eax\n" /* sceneDef */
        "movl %eax, 0xc(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* sceneDef */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1615 | viewParms */
        "movl %eax, 0x14(%edx)\n"
        "movl (%edi), %eax\n" /* line 1616 | lodParms */
        "movl %eax, 0x18(%edx)\n"
        "movl 4(%edi), %eax\n" /* lodParms */
        "movl %eax, 0x1c(%edx)\n"
        "movl 8(%edi), %eax\n" /* lodParms */
        "movl %eax, 0x20(%edx)\n"
        "movl 0xc(%edi), %eax\n" /* lodParms */
        "movl %eax, 0x24(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* lodParms */
        "movl %eax, 0x28(%edx)\n"
        "popl %ebx\n" /* line 1617 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc9122_000c9197:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x30(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $0x30, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0xc, (%edx)\n" /* line 964 */
        "movw $0x30, 2(%edx)\n" /* line 965 */
        "jmp .Lfc9122_000c9152\n"
    );
}

/* line 1620 */
__attribute__((naked))
void R_AddCmdSetViewport(int x, int y, int width, int height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1620 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $0x13, %eax\n"
        "jg .Lfc91be_000c9201\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %edx, %edx\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1631 | x */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 1632 | y */
        "movl %eax, 8(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1633 | width */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 1634 | height */
        "movl %eax, 0x10(%edx)\n"
        "popl %ebx\n" /* line 1635 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc91be_000c9201:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x14(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $0x14, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0xd, (%edx)\n" /* line 964 */
        "movw $0x14, 2(%edx)\n" /* line 965 */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1631 | x */
        "movl %eax, 4(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 1632 | y */
        "movl %eax, 8(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1633 | width */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 1634 | height */
        "movl %eax, 0x10(%edx)\n"
        "popl %ebx\n" /* line 1635 */
        "popl %ebp\n"
        "retl\n"
    );
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
__attribute__((naked))
void R_AddCmdApplyEarlyPostEffects(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1867 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lfc9326_000c935a\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        "popl %ebx\n" /* line 1873 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc9326_000c935a:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 4(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x19, (%edx)\n" /* line 964 */
        "movw $4, 2(%edx)\n" /* line 965 */
        /* } scope */
        "popl %ebx\n" /* line 1873 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1876 */
__attribute__((naked))
void R_AddCmdApplyLatePostEffects(float blurRadius)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1876 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lfc937a_000c93ae\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc937a_000c93ab:\n"
        "popl %ebx\n" /* line 1886 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc937a_000c93ae:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 8(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x1a, (%edx)\n" /* line 964 */
        "movw $8, 2(%edx)\n" /* line 965 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1882 */
        "je .Lfc937a_000c93ab\n"
        "movss 8(%ebp), %xmm0\n" /* line 1885 | blurRadius */
        "movss %xmm0, 4(%edx)\n"
        "popl %ebx\n" /* line 1886 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1889 */
__attribute__((naked))
void R_AddCmdDrawSunPostEffects(int viewIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1889 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lfc93dc_000c9410\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        ".Lfc93dc_000c940d:\n"
        "popl %ebx\n" /* line 1901 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc93dc_000c9410:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 8(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x1b, (%edx)\n" /* line 964 */
        "movw $8, 2(%edx)\n" /* line 965 */
        "movl %edx, %eax\n" /* line 966 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1897 */
        "je .Lfc93dc_000c940d\n"
        "movl 8(%ebp), %edx\n" /* line 1900 | viewIndex */
        "movl %edx, 4(%eax)\n"
        "popl %ebx\n" /* line 1901 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1913 */
__attribute__((naked))
void R_AddCmdClearScreen(int whichToClear, const vec_t *color, float depth, int stencil)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1913 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %esi\n" /* color */
        "movzbl 0x14(%ebp), %edi\n" /* stencil */
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $0x1b, %eax\n"
        "jg .Lfc943c_000c949d\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        "xorl %ecx, %ecx\n"
        /* } scope */
        ".Lfc943c_000c946d:\n"
        "movl 8(%ebp), %eax\n" /* line 1926 | whichToClear */
        "movb %al, 4(%ecx)\n"
        "movl %edi, %eax\n" /* line 1928 | stencil */
        "movb %al, 5(%ecx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 1929 | depth */
        "movl %eax, 8(%ecx)\n"
        "leal 0xc(%ecx), %edx\n" /* line 1930 | to */
        /* { scope 1 */
        "movl (%esi), %eax\n" /* line 456 */
        "movl %eax, 0xc(%ecx)\n"
        "movl 4(%esi), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%esi), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "popl %ebx\n" /* line 1931 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc943c_000c949d:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0x1c(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $0x1c, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0xb, (%edx)\n" /* line 964 */
        "movw $0x1c, 2(%edx)\n" /* line 965 */
        "movl %edx, %ecx\n"
        "jmp .Lfc943c_000c946d\n"
    );
}

/* line 1934 */
__attribute__((naked))
void R_AddCmdSaveScreen(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1934 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "cmpl $3, %eax\n"
        "jg .Lfc94c6_000c94ef\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        "popl %ebx\n" /* line 1941 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc94c6_000c94ef:\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 4(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "addl $4, 0x30004(%ecx)\n" /* line 962 */
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0xa, (%edx)\n" /* line 964 */
        "movw $4, 2(%edx)\n" /* line 965 */
        /* } scope */
        "popl %ebx\n" /* line 1941 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1944 */
__attribute__((naked))
void R_AddCmdBlendSavedScreen(int fadeMsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1944 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %esi\n" /* fadeMsec */
        "testl %esi, %esi\n" /* line 1948 | fadeMsec */
        "jle .Lfc9516_000c9569\n"
        /* { scope 1 */
        "movl s_cmdList, %ecx\n" /* line 950 */
        "movl 0x30000(%ecx), %ebx\n"
        "movl $0x30000, %eax\n" /* line 953 */
        "subl %ebx, %eax\n"
        "addl 0x30004(%ecx), %eax\n"
        "subl $0x2000, %eax\n"
        "cmpl $0xb, %eax\n"
        "jle .Lfc9516_000c956d\n"
        "leal (%ecx, %ebx), %edx\n" /* line 960 */
        "leal 0xc(%ebx), %eax\n" /* line 961 */
        "movl %eax, 0x30000(%ecx)\n"
        "movl %edx, 0x30008(%ecx)\n" /* line 963 */
        "movw $0x1d, (%edx)\n" /* line 964 */
        "movw $0xc, 2(%edx)\n" /* line 965 */
        /* } scope */
        "testl %edx, %edx\n" /* line 1953 */
        "je .Lfc9516_000c9569\n"
        "movl %esi, 4(%edx)\n" /* line 1956 | fadeMsec */
        ".Lfc9516_000c9569:\n"
        "popl %ebx\n" /* line 1957 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc9516_000c956d:\n"
        "movl $0, 0x30008(%ecx)\n" /* line 956 */
        /* } scope */
        "popl %ebx\n" /* line 1957 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
