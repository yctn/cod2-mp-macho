/* ASM dump from: cl_cgame_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_cgame_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static int warnCount; /* 0xf13080 */
static int warnCount_00f13084; /* 0xf13084 */
static int warnCount_00f13084; /* 0xf13084 */
static int warnCount_00f13084; /* 0xf13084 */
static char bigConfigString[8192]; /* 0xf11080 */
static vec4_t g_color_table[8]; /* 0x302b20 */

void CL_GetScreenDimensions(int *width, int *height, float *aspect);
qboolean CL_GetUserCmd(int cmdNumber, usercmd_t *ucmd);
int CL_GetCurrentCmdNumber(void);
void CL_GetCurrentSnapshotNumber(int *snapshotNumber, int *serverTime);
qboolean CL_GetSnapshot(int snapshotNumber, snapshot_t *snapshot);
void CL_SetUserCmdValue(int userCmdValue, int holdableValue, float sensitivityScale);
void CL_SetUserCmdInShellshock(qboolean shocked);
void CL_AddCgameCommand(const char *cmdName);
void CL_ConfigstringModified(void);
qboolean CL_GetServerCommand(int serverCommandNumber);
void CL_SetExpectedHunkUsage(const char *mapname);
void CL_CM_LoadMap(const char *mapname);
void CL_ShutdownCGame(void);
qboolean CL_DObjCreateSkelForBone(struct DObj_s *obj, int boneIndex, int localClientNum);
qboolean CL_DObjCreateSkelForBones(const struct DObj_s *obj, int *partBits, int localClientNum);
void CL_SubtitlePrint(const char *pszText, int iDuration, int iLineWidth);
const char * CL_GetConfigString(int index);
snd_alias_t * CL_PickSoundAlias(const char *aliasname);
struct XModel * CL_RegisterModel(const char *name);
struct GfxBrushModel * CL_RegisterInlineModel(int modelIndex);
void CL_FinishLoadingModels(void);
MaterialHandle CL_RegisterMaterial(const char *name, int imageTrack);
MaterialHandle CL_RegisterMaterialNoMip(const char *name, int imageTrack);
MaterialHandle CL_Material_Duplicate(MaterialHandle mtlCopy, const char *name);
void CL_DuplicateFont(FontHandle fontCopy, const char *name);
void CL_ClearScene(void);
void CL_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts);
void CL_AddPolyToScene(MaterialHandle mtlHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts);
void CL_AddLightToScene(const vec_t *org, float radius, float r, float g, float b);
void CL_SetFog(int fogvar, float start, float end, int r, int g, int b, float density);
void CL_SwitchFog(int fogvar, int startTime, int transitionTime);
void CL_RenderScene(const refdef_t *fd);
int CL_BeginDelayedDrawing(void);
void CL_EndDelayedDrawing(int marker);
void CL_IssueDelayedDrawing(int marker);
void CL_SetViewport(int x, int y, int width, int height);
void CL_SaveScreen(void);
void CL_BlendSavedScreen(int fadeMsec);
void CL_DrawStretchPicPhysical(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material);
void CL_DrawQuadPic(int (*verts)[16][4], const vec_t *color, MaterialHandle material);
void CL_DrawSprite(MaterialHandle material, const byte *rgbaColor, const vec_t *pos, float radius, float minScreenRadius, int renderFxFlags);
void CL_ModelBounds(struct GfxBrushModel *model, vec_t *mins, vec_t *maxs);
int CL_MarkFragments(objective_t * (*points)[4], const vec_t *origin, objective_t * (*axis)[4], float radius, int maxPoints, GfxWorldVertex *verts, int maxFragments, GfxMarkFragment *fragmentBuffer, MaterialHandle markMaterial);
void CL_TrackStatistics(trStatistics_t *pStats);
qboolean CL_PickMaterial(const vec_t *org, const vec_t *dir, char *pszName, char *pszSurfaceFlags, char *pszContents, int iMaxChars);
void CL_LoadSoundAliases(const char *loadspec);
qboolean CL_Popup(const char *menu);
void CL_ClosePopup(const char *menu);
void CL_CloseInGameMenu(void);
void CL_CloseAllMenus(void);
void CL_SetWeaponInfoMemory(void);
void CL_FreeWeaponInfoMemory(void);
void CL_FX_AdjustCamera(refdef_t *refdef);
void CL_CapTurnRate(float maxPitchSpeed, float maxYawSpeed);
void LoadWorld(const char *mapname);
void CL_UpdateLevelHunkUsage(void);
void CL_StartLoading(const char *mapname, const char *gametype);
void CL_InitCGame(void);
qboolean CL_GameCommand(void);
void CL_AdjustTimeDelta(void);
void CL_SetADS(int ads);
void CL_DrawString(int x, int y, const char *pszString, qboolean bShadow, int iCharHeight);
void CL_ArchiveClientState(MemoryFile *memFile);
void CL_SetLodOrigin(const refdef_t *fd);
void CL_LookupColor(int c, vec_t *color);
void CL_SetUserCmdAimValues(vec_t *kickAngles);
void CL_UpdateColor(void);
void CL_SetFullScreenViewport(void);
void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material);
void CL_SyncTimes(void);
void CL_SetCGameTime(void);

/* line 79 */
__attribute__((naked))
void CL_GetScreenDimensions(int *width, int *height, float *aspect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "movl 0x195ecac, %edx\n" /* line 85 */
        "movl 0x2a0a64(%edx), %ecx\n"
        "movl 8(%ebp), %eax\n" /* width */
        "movl %ecx, (%eax)\n"
        "movl 0x2a0a68(%edx), %ecx\n" /* line 86 */
        "movl 0xc(%ebp), %eax\n" /* height */
        "movl %ecx, (%eax)\n"
        "movl 0x2a0a74(%edx), %edx\n" /* line 87 */
        "movl 0x10(%ebp), %eax\n" /* aspect */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 88 */
        "retl\n"
    );
}

/* line 91 */
__attribute__((naked))
qboolean CL_GetUserCmd(int cmdNumber, usercmd_t *ucmd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 91 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* cmdNumber */
        "movl 0xc(%ebp), %esi\n" /* ucmd */
        "movl 0x195ee78, %eax\n" /* line 96 */
        "movl (%eax), %ebx\n"
        "movl 0x4945c(%ebx), %eax\n"
        "cmpl %edi, %eax\n" /* cmdNumber */
        "jl .Lf1788a0_0017891f\n"
        ".Lf1788a0_001788c0:\n"
        "addl $-0x80, %eax\n" /* line 103 */
        "cmpl %eax, %edi\n" /* cmdNumber */
        "jle .Lf1788a0_00178915\n"
        "movl %edi, %eax\n" /* line 108 | cmdNumber */
        "andl $0x7f, %eax\n"
        "leal (, %eax, 4), %edx\n"
        "shll $5, %eax\n"
        "subl %edx, %eax\n"
        "leal 0x48650(%eax, %ebx), %eax\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, (%esi)\n" /* ucmd */
        "movl 0x10(%eax), %edx\n"
        "movl %edx, 4(%esi)\n" /* ucmd */
        "movl 0x14(%eax), %edx\n"
        "movl %edx, 8(%esi)\n" /* ucmd */
        "movl 0x18(%eax), %edx\n"
        "movl %edx, 0xc(%esi)\n" /* ucmd */
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, 0x10(%esi)\n" /* ucmd */
        "movl 0x20(%eax), %edx\n"
        "movl %edx, 0x14(%esi)\n" /* ucmd */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, 0x18(%esi)\n" /* ucmd */
        "movl $1, %eax\n"
        "addl $0x1c, %esp\n" /* line 111 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1788a0_00178915:\n"
        "xorl %eax, %eax\n" /* line 103 */
        "addl $0x1c, %esp\n" /* line 111 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1788a0_0017891f:\n"
        "movl %eax, 0xc(%esp)\n" /* line 98 */
        "movl %edi, 8(%esp)\n" /* cmdNumber */
        "movl $0x2ad9e8, 4(%esp)\n" /* "CL_GetUserCmd: %i >= %i" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x4945c(%ebx), %eax\n"
        "jmp .Lf1788a0_001788c0\n"
    );
}

/* line 114 */
__attribute__((naked))
int CL_GetCurrentCmdNumber(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 114 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x4945c(%eax), %eax\n"
        "popl %ebp\n" /* line 117 */
        "retl\n"
    );
}

/* line 125 */
__attribute__((naked))
void CL_GetCurrentSnapshotNumber(int *snapshotNumber, int *serverTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 125 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 127 */
        "movl (%eax), %ecx\n"
        "movl 0x24(%ecx), %edx\n"
        "movl 8(%ebp), %eax\n" /* snapshotNumber */
        "movl %edx, (%eax)\n"
        "movl 0x20(%ecx), %edx\n" /* line 128 */
        "movl 0xc(%ebp), %eax\n" /* serverTime */
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 129 */
        "retl\n"
    );
}

/* line 137 */
__attribute__((naked))
qboolean CL_GetSnapshot(int snapshotNumber, snapshot_t *snapshot)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 137 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* snapshotNumber */
        /* { scope 1 */
        "movl 0x195ee78, %eax\n" /* line 146 */
        "movl (%eax), %ebx\n"
        "cmpl %esi, 0x24(%ebx)\n" /* i */
        "jl .Lf178974_00178b61\n"
        ".Lf178974_00178990:\n"
        "movl 0x24(%ebx), %eax\n" /* line 152 */
        "subl %esi, %eax\n" /* i */
        "cmpl $0x1f, %eax\n"
        "jg .Lf178974_00178b57\n"
        "movl %esi, %eax\n" /* line 158 | i */
        "andl $0x1f, %eax\n"
        "leal (%eax, %eax, 4), %ecx\n"
        "movl %ecx, %edx\n"
        "shll $5, %edx\n"
        "subl %ecx, %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "leal 0x495e0(%ebx, %edx, 8), %edi\n" /* clSnap */
        "movl (%edi), %eax\n" /* line 159 | clSnap */
        "testl %eax, %eax\n"
        "je .Lf178974_00178b57\n"
        "movl 0x85d0(%ebx), %eax\n" /* line 166 */
        "subl 0x26cc(%edi), %eax\n" /* clSnap */
        "cmpl $0x7ff, %eax\n"
        "jg .Lf178974_00178b57\n"
        "movl 0x85d4(%ebx), %eax\n" /* line 173 */
        "subl 0x26d0(%edi), %eax\n" /* clSnap */
        "cmpl $0x7ff, %eax\n"
        "jg .Lf178974_00178b57\n"
        "movl 4(%edi), %eax\n" /* line 179 | clSnap */
        "movl 0xc(%ebp), %edx\n" /* snapshot */
        "movl %eax, (%edx)\n"
        "movl 0x26d4(%edi), %eax\n" /* line 180 | clSnap */
        "movl %eax, 0x12dbc(%edx)\n"
        "movl 0x14(%edi), %eax\n" /* line 181 | clSnap */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* line 182 | clSnap */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 183 | snapshot */
        "addl $0xc, %edx\n"
        "leal 0x1c(%edi), %eax\n" /* clSnap */
        "movl $0x26a8, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 0x26c4(%edi), %eax\n" /* line 185 | clSnap */
        "movl %eax, -0x20(%ebp)\n" /* count */
        "cmpl $0x100, %eax\n" /* line 186 */
        "jle .Lf178974_00178b7a\n"
        "movl 0x195ed14, %eax\n" /* line 188 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf178974_00178b81\n"
        "movl $0x2ada40, 8(%esp)\n" /* line 189 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $4, (%esp)\n"
        "calll StatMon_Warning\n"
        "movl $0x100, -0x20(%ebp)\n" /* count */
        "movl -0x20(%ebp), %edx\n" /* count */
        ".Lf178974_00178a7a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 194 | snapshot */
        "movl %edx, 0x26b4(%eax)\n"
        "testl %edx, %edx\n" /* line 200 */
        "jle .Lf178974_00178ad7\n"
        "movl %eax, %ebx\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf178974_00178a8b:\n"
        "movl %esi, %eax\n" /* line 202 | i */
        "addl 0x26cc(%edi), %eax\n" /* clSnap */
        "andl $0x7ff, %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "shll $8, %eax\n"
        "subl %edx, %eax\n"
        "movl 0x195ee78, %edx\n"
        "addl (%edx), %eax\n"
        "addl $0xd30e0, %eax\n"
        "leal 0x26bc(%ebx), %edx\n"
        "movl $0xf0, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %esi\n" /* line 200 | i */
        "addl $0xf0, %ebx\n"
        "cmpl %esi, -0x20(%ebp)\n" /* i, count */
        "jne .Lf178974_00178a8b\n"
        ".Lf178974_00178ad7:\n"
        "movl 0x26c8(%edi), %eax\n" /* line 212 | clSnap */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $0x41, %eax\n" /* line 213 */
        "movl $0x40, %eax\n"
        "cmovll -0x1c(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* line 217 | snapshot */
        "movl %eax, 0x26b8(%edx)\n"
        "testl %eax, %eax\n" /* line 218 */
        "jle .Lf178974_00178b4a\n"
        "movl %edx, %ebx\n"
        "xorl %esi, %esi\n" /* i */
        ".Lf178974_00178b00:\n"
        "movl %esi, %eax\n" /* line 220 | i */
        "addl 0x26d0(%edi), %eax\n" /* clSnap */
        "andl $0x7ff, %eax\n"
        "leal (%eax, %eax, 2), %edx\n"
        "shll $3, %edx\n"
        "subl %eax, %edx\n"
        "shll $2, %edx\n"
        "movl 0x195ee78, %eax\n"
        "addl (%eax), %edx\n"
        "addl $0x14b0e0, %edx\n"
        "leal 0x116bc(%ebx), %eax\n"
        "movl $0x5c, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %esi\n" /* line 218 | i */
        "addl $0x5c, %ebx\n"
        "cmpl %esi, -0x1c(%ebp)\n" /* i */
        "jne .Lf178974_00178b00\n"
        ".Lf178974_00178b4a:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf178974_00178b57:\n"
        "xorl %eax, %eax\n" /* line 218 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 226 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf178974_00178b61:\n"
        "movl $0x2ada04, 4(%esp)\n" /* line 148 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf178974_00178990\n"
        ".Lf178974_00178b7a:\n"
        "movl %eax, %edx\n"
        "jmp .Lf178974_00178a7a\n"
        ".Lf178974_00178b81:\n"
        "movl $0x100, 8(%esp)\n" /* line 191 */
        "movl -0x20(%ebp), %edx\n" /* count */
        "movl %edx, 4(%esp)\n"
        "movl $0x2ada60, (%esp)\n" /* "CL_GetSnapshot: truncated %i entities to %i
" */
        "calll Com_DPrintf\n"
        "movl $0x100, -0x20(%ebp)\n" /* count */
        "movl -0x20(%ebp), %edx\n" /* count */
        "jmp .Lf178974_00178a7a\n"
    );
}

/* line 234 */
__attribute__((naked))
void CL_SetUserCmdValue(int userCmdValue, int holdableValue, float sensitivityScale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 234 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 236 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* userCmdValue */
        "movl %eax, 0x85f8(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 237 | holdableValue */
        "movl %eax, 0x85fc(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 238 | sensitivityScale */
        "movl %eax, 0x8604(%edx)\n"
        "popl %ebp\n" /* line 239 */
        "retl\n"
    );
}

/* line 258 */
__attribute__((naked))
void CL_SetUserCmdInShellshock(qboolean shocked)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 258 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 260 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* shocked */
        "movl %eax, 0x8600(%edx)\n"
        "popl %ebp\n" /* line 261 */
        "retl\n"
    );
}

/* line 275 */
__attribute__((naked))
void CL_AddCgameCommand(const char *cmdName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 275 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, 4(%esp)\n" /* line 277 */
        "movl 8(%ebp), %eax\n" /* cmdName */
        "movl %eax, (%esp)\n"
        "calll Cmd_AddCommand\n"
        "leave\n" /* line 278 */
        "retl\n"
    );
}

/* line 286 */
__attribute__((naked))
void CL_ConfigstringModified(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 286 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5ebc, %esp\n"
        /* { scope 1 */
        "movl $1, (%esp)\n" /* line 294 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, -0x5eb0(%ebp)\n" /* index */
        "cmpl $0x7ff, %eax\n" /* line 295 */
        "ja .Lf178c08_00178de5\n"
        ".Lf178c08_00178c39:\n"
        "movl $2, (%esp)\n" /* line 299 */
        "calll Cmd_Argv\n"
        "movl %eax, -0x5eb8(%ebp)\n" /* s */
        "movl 0x195ee78, %eax\n" /* line 301 */
        "movl (%eax), %esi\n"
        "movl -0x5eb0(%ebp), %edx\n" /* line 302 | index */
        "movl 0x270c(%esi, %edx, 4), %eax\n"
        "leal 0x470c(%esi, %eax), %eax\n"
        "movl -0x5eb8(%ebp), %ecx\n" /* s */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf178c08_00178c87\n"
        /* } scope */
        ".Lf178c08_00178c7c:\n"
        "addl $0x5ebc, %esp\n" /* line 349 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf178c08_00178c87:\n"
        "leal -0x5e9c(%ebp), %eax\n" /* line 308 | oldGs */
        "leal 0x270c(%esi), %ebx\n" /* dup */
        "movl $0x5e84, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* dup */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0x5e84, 8(%esp)\n" /* line 310 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* dup */
        "calll memset\n"
        "movl $1, 0x858c(%esi)\n" /* line 313 */
        "movl $0, -0x5eb4(%ebp)\n" /* i */
        "jmp .Lf178c08_00178cec\n"
        ".Lf178c08_00178cd5:\n"
        "addl $1, -0x5eb4(%ebp)\n" /* line 315 | i */
        "cmpl $0x800, -0x5eb4(%ebp)\n" /* i */
        "je .Lf178c08_00178d9e\n"
        ".Lf178c08_00178cec:\n"
        "movl -0x5eb4(%ebp), %eax\n" /* line 317 | i */
        "cmpl %eax, -0x5eb0(%ebp)\n" /* index */
        "je .Lf178c08_00178dbb\n"
        "movl -0x5e9c(%ebp, %eax, 4), %eax\n" /* line 323 */
        "leal -0x3e9c(%ebp, %eax), %ebx\n" /* dup */
        ".Lf178c08_00178d0c:\n"
        "cmpb $0, (%ebx)\n" /* line 325 | dup */
        "je .Lf178c08_00178cd5\n"
        "cld\n" /* line 330 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* dup */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "leal -1(%esi), %eax\n"
        "movl %eax, -0x5eac(%ebp)\n" /* len */
        "movl 0x195ee78, %eax\n" /* line 332 */
        "movl (%eax), %edi\n"
        "movl 0x858c(%edi), %edx\n"
        "movl -0x5eac(%ebp), %ecx\n" /* len */
        "leal 1(%ecx, %edx), %eax\n"
        "cmpl $0x3e80, %eax\n"
        "jg .Lf178c08_00178dc6\n"
        ".Lf178c08_00178d48:\n"
        "movl -0x5eb4(%ebp), %eax\n" /* line 338 | i */
        "movl %edx, 0x270c(%edi, %eax, 4)\n"
        "leal 0x470c(%edi, %edx), %eax\n" /* line 339 */
        "movl %esi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* dup */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0x858c(%edi), %edx\n" /* line 340 */
        "addl %edx, -0x5eac(%ebp)\n" /* len */
        "movl -0x5eac(%ebp), %eax\n" /* len */
        "addl $1, %eax\n"
        "movl %eax, 0x858c(%edi)\n"
        "addl $1, -0x5eb4(%ebp)\n" /* line 315 | i */
        "cmpl $0x800, -0x5eb4(%ebp)\n" /* i */
        "jne .Lf178c08_00178cec\n"
        ".Lf178c08_00178d9e:\n"
        "cmpl $1, -0x5eb0(%ebp)\n" /* line 343 | index */
        "jne .Lf178c08_00178c7c\n"
        "calll CL_SystemInfoChanged\n" /* line 346 */
        /* } scope */
        "addl $0x5ebc, %esp\n" /* line 349 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf178c08_00178dbb:\n"
        "movl -0x5eb8(%ebp), %ebx\n" /* line 317 | s, dup */
        "jmp .Lf178c08_00178d0c\n"
        ".Lf178c08_00178dc6:\n"
        "movl $0x2adab4, 4(%esp)\n" /* line 334 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x858c(%edi), %edx\n"
        "jmp .Lf178c08_00178d48\n"
        ".Lf178c08_00178de5:\n"
        "movl $0x2ada90, 4(%esp)\n" /* line 297 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf178c08_00178c39\n"
    );
}

/* line 359 */
__attribute__((naked))
qboolean CL_GetServerCommand(int serverCommandNumber)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 359 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl 0x195ee8c, %edi\n" /* line 367 */
        "movl (%edi), %edx\n"
        "movl 0x2013c(%edx), %eax\n"
        "addl $-0x80, %eax\n"
        "cmpl 8(%ebp), %eax\n" /* serverCommandNumber */
        "jge .Lf178dfe_00178e8c\n"
        "movl 8(%ebp), %esi\n" /* serverCommandNumber, s */
        "andl $0x7f, %esi\n" /* s */
        "movl (%edi), %ebx\n" /* line 382 | i */
        "movl 8(%ebp), %eax\n" /* serverCommandNumber */
        "cmpl 0x2013c(%ebx), %eax\n" /* i */
        "jg .Lf178dfe_00178f1e\n"
        ".Lf178dfe_00178e34:\n"
        "movl %eax, %ecx\n"
        "shll $0xa, %esi\n" /* line 387 | s */
        "leal 0x20144(%esi, %ebx), %esi\n" /* s */
        "movl %ecx, 0x20140(%ebx)\n" /* line 388 | i */
        "movl 0x195f5e8, %eax\n" /* line 390 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf178dfe_00178f56\n"
        ".Lf178dfe_00178e57:\n"
        "movl %esi, (%esp)\n" /* line 394 | s */
        "calll Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 395 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* i */
        "calll Cmd_Argc\n" /* line 396 */
        "movl %eax, %edx\n"
        "movsbl (%ebx), %eax\n" /* line 398 | i */
        "subl $0x42, %eax\n"
        "cmpl $0x38, %eax\n"
        "jbe .Lf178dfe_00178ea0\n"
        ".Lf178dfe_00178e7f:\n"
        "movl $1, %eax\n" /* line 451 */
        /* } scope */
        ".Lf178dfe_00178e84:\n"
        "addl $0x3c, %esp\n" /* line 459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf178dfe_00178e8c:\n"
        "movl 0x407a0(%edx), %edx\n" /* line 371 */
        "testl %edx, %edx\n"
        "je .Lf178dfe_00178ea7\n"
        "xorl %eax, %eax\n" /* line 423 */
        /* } scope */
        ".Lf178dfe_00178e98:\n"
        "addl $0x3c, %esp\n" /* line 459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf178dfe_00178ea0:\n"
        "jmpl *0x302ba0(, %eax, 4)\n" /* line 398 */
        ".Lf178dfe_00178ea7:\n"
        "movl $0x2adad4, (%esp)\n" /* line 374 */
        "calll Com_Printf\n"
        "movl 8(%ebp), %esi\n" /* line 375 | serverCommandNumber, s */
        "andl $0x7f, %esi\n" /* s */
        "movl %esi, 4(%esp)\n" /* s */
        "movl $0x2adaf8, (%esp)\n" /* "serverCommandNumber: %d
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* i */
        ".Lf178dfe_00178ecb:\n"
        "movl %ebx, %eax\n" /* line 377 | i */
        "andl $0x7f, %eax\n"
        "shll $0xa, %eax\n"
        "addl (%edi), %eax\n"
        "addl $0x20144, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $0x2adb14, (%esp)\n" /* "cmd %5d: %s
" */
        "calll Com_Printf\n"
        "addl $1, %ebx\n" /* line 376 | i */
        "cmpl $0x80, %ebx\n" /* i */
        "jne .Lf178dfe_00178ecb\n"
        "movl $0x2adb24, 4(%esp)\n" /* line 379 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl (%edi), %ebx\n" /* line 382 | i */
        "movl 8(%ebp), %eax\n" /* serverCommandNumber */
        "cmpl 0x2013c(%ebx), %eax\n" /* i */
        "jle .Lf178dfe_00178e34\n"
        ".Lf178dfe_00178f1e:\n"
        "movl $0x2adb58, 4(%esp)\n" /* line 384 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %ecx\n" /* serverCommandNumber */
        "shll $0xa, %esi\n" /* line 387 | s */
        "leal 0x20144(%esi, %ebx), %esi\n" /* s */
        "movl %ecx, 0x20140(%ebx)\n" /* line 388 | i */
        "movl 0x195f5e8, %eax\n" /* line 390 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf178dfe_00178e57\n"
        ".Lf178dfe_00178f56:\n"
        "movl %esi, 8(%esp)\n" /* line 391 | s */
        "movl %ecx, 4(%esp)\n"
        "movl $0x2adb84, (%esp)\n" /* "serverCommand: %i : %s
" */
        "calll Com_DPrintf\n"
        "jmp .Lf178dfe_00178e57\n"
        "subl $1, %edx\n" /* line 406 */
        "jg .Lf178dfe_00179127\n"
        "movl $0x215f8c, 4(%esp)\n" /* line 409 */
        "movl $2, (%esp)\n"
        "calll Com_Error\n"
        ".Lf178dfe_00178f8c:\n"
        "movl $3, 4(%esp)\n" /* line 412 */
        "movl %esi, (%esp)\n" /* s */
        "calll Cmd_TokenizeString2\n"
        "movl $2, (%esp)\n" /* line 413 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* i */
        "movl $1, (%esp)\n"
        "calll Cmd_Argv\n"
        "movl %ebx, 0x14(%esp)\n" /* i */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x64, 0xc(%esp)\n"
        "movl $0x2adbb8, 8(%esp)\n" /* "%c %s %s" */
        "movl $0x2000, 4(%esp)\n"
        "movl $bigConfigString, (%esp)\n"
        "calll Com_sprintf\n"
        "xorl %eax, %eax\n" /* line 423 */
        "jmp .Lf178dfe_00178e98\n"
        "movl $3, 4(%esp)\n" /* line 417 */
        "movl %esi, (%esp)\n" /* s */
        "calll Cmd_TokenizeString2\n"
        "movl $2, (%esp)\n" /* line 418 */
        "calll Cmd_Argv\n"
        "movl %eax, %ebx\n" /* i */
        "movl $bigConfigString, %edi\n" /* line 419 */
        "xorl %edx, %edx\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %esi\n" /* s */
        "notl %esi\n" /* s */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* i */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -2(%ecx, %esi), %ecx\n"
        "cmpl $0x1fff, %ecx\n"
        "ja .Lf178dfe_00179183\n"
        ".Lf178dfe_00179037:\n"
        "movl %ebx, 4(%esp)\n" /* line 423 | i */
        "movl $bigConfigString, (%esp)\n"
        "calll strcat\n"
        "xorl %eax, %eax\n"
        "jmp .Lf178dfe_00178e98\n"
        "movl $3, 4(%esp)\n" /* line 427 */
        "movl %esi, (%esp)\n" /* s */
        "calll Cmd_TokenizeString2\n"
        "movl $2, (%esp)\n" /* line 428 */
        "calll Cmd_Argv\n"
        "movl %eax, %esi\n" /* s */
        "xorl %edx, %edx\n" /* line 429 */
        "cld\n"
        "movl $bigConfigString, %edi\n"
        "movl $0xffffffff, %ecx\n"
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* s */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x1c(%ebp), %eax\n"
        "leal -1(%ecx, %eax), %ecx\n"
        "cmpl $0x1fff, %ecx\n"
        "ja .Lf178dfe_0017916a\n"
        ".Lf178dfe_001790a0:\n"
        "movl %esi, 4(%esp)\n" /* line 433 | s */
        "movl $bigConfigString, (%esp)\n"
        "calll strcat\n"
        "movl $bigConfigString, %esi\n" /* s */
        "jmp .Lf178dfe_00178e57\n"
        "calll Con_ClearNotify\n" /* line 448 */
        "calll Con_ClearSubtitles\n" /* line 449 */
        "movl 0x195ee78, %eax\n" /* line 450 */
        "movl (%eax), %eax\n"
        "addl $0x4865c, %eax\n"
        "movl $0xe00, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0x195eca8, %eax\n" /* line 451 */
        "calll *0x8c(%eax)\n"
        "jmp .Lf178dfe_00178e7f\n"
        "movl $3, 4(%esp)\n" /* line 438 */
        "movl %esi, (%esp)\n" /* s */
        "calll Cmd_TokenizeString2\n"
        "calll CL_ConfigstringModified\n" /* line 439 */
        "movl $3, 4(%esp)\n" /* line 441 */
        "movl %esi, (%esp)\n" /* s */
        "calll Cmd_TokenizeString2\n"
        "movl $1, %eax\n"
        "jmp .Lf178dfe_00178e84\n"
        ".Lf178dfe_00179127:\n"
        "movl $1, (%esp)\n" /* line 407 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll SEH_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* i */
        "movl $0x2adb9c, (%esp)\n" /* "EXE_SERVERDISCONNECTREASON" */
        "calll SEH_SafeTranslateString\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversionString\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf178dfe_00178f8c\n"
        ".Lf178dfe_0017916a:\n"
        "movl $0x2adbc4, 4(%esp)\n" /* line 431 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf178dfe_001790a0\n"
        ".Lf178dfe_00179183:\n"
        "movl $0x2adbc4, 4(%esp)\n" /* line 421 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf178dfe_00179037\n"
    );
}

/* line 470 */
__attribute__((naked))
void CL_SetExpectedHunkUsage(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 470 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 479 */
        "leal -0x1c(%ebp), %eax\n" /* handle */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a70ec, (%esp)\n" /* "hunkusage.dat" */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %esi\n" /* len */
        "testl %eax, %eax\n" /* line 480 */
        "js .Lf17919c_00179271\n"
        "leal 1(%eax), %ebx\n" /* line 483 */
        "movl %ebx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n" /* buf */
        "movl %ebx, 8(%esp)\n" /* line 484 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %eax\n" /* line 486 | handle */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* len */
        "movl %edi, (%esp)\n" /* buf */
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 487 | handle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %edi, -0x20(%ebp)\n" /* line 490 | buf, buftrav */
        "leal -0x20(%ebp), %ebx\n" /* buftrav */
        ".Lf17919c_0017920f:\n"
        "movl %ebx, (%esp)\n" /* line 491 */
        "calll Com_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf17919c_00179269\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17919c_00179269\n"
        "movl 8(%ebp), %edx\n" /* line 493 | mapname */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17919c_0017920f\n"
        "movl %ebx, (%esp)\n" /* line 496 */
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 497 */
        "je .Lf17919c_0017920f\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17919c_0017920f\n"
        "movl %eax, (%esp)\n" /* line 500 */
        "calll atoi\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195f2fc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl %edi, (%esp)\n" /* line 501 | buf */
        "calll Z_FreeInternal\n"
        "jmp .Lf17919c_00179288\n"
        ".Lf17919c_00179269:\n"
        "movl %edi, (%esp)\n" /* line 507 | buf */
        "calll Z_FreeInternal\n"
        ".Lf17919c_00179271:\n"
        "movl $0, 4(%esp)\n" /* line 510 */
        "movl 0x195f2fc, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        /* } scope */
        ".Lf17919c_00179288:\n"
        "addl $0x2c, %esp\n" /* line 511 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 522 */
__attribute__((naked))
void CL_CM_LoadMap(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 522 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* mapname */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 526 | mapname */
        "calll Com_LoadBsp\n"
        "leal -0xc(%ebp), %eax\n" /* line 527 | checksum */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* mapname */
        "calll CM_LoadMap\n"
        "movl 0x195ecbc, %eax\n" /* line 529 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf179290_001792c3\n"
        "calll CM_LinkWorld\n" /* line 530 */
        /* } scope */
        ".Lf179290_001792c3:\n"
        "addl $0x24, %esp\n" /* line 531 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 539 */
__attribute__((naked))
void CL_ShutdownCGame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 539 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $1, (%esp)\n" /* line 542 */
        "calll Com_UnloadSoundAliases\n"
        "movl 0x195ee78, %eax\n" /* line 545 */
        "movl (%eax), %ebx\n"
        "cmpb $0, 0xa(%ebx)\n"
        "je .Lf1792ca_001792f7\n"
        "calll CG_Shutdown\n" /* line 551 */
        "movb $0, 0xa(%ebx)\n" /* line 553 */
        "movb $0, 9(%ebx)\n" /* line 554 */
        ".Lf1792ca_001792f7:\n"
        "addl $0x14, %esp\n" /* line 555 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 565 */
__attribute__((naked))
qboolean CL_DObjCreateSkelForBone(struct DObj_s *obj, int boneIndex, int localClientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 565 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* obj */
        "movl 0xc(%ebp), %eax\n" /* boneIndex */
        "movl %eax, -0x1c(%ebp)\n" /* boneIndex */
        "movl 0x10(%ebp), %edi\n" /* localClientNum */
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 574 | localClientNum */
        "calll CL_GetSkelTimeStamp\n"
        "movl %eax, %ebx\n" /* timeStamp */
        "movl %eax, 4(%esp)\n" /* line 576 */
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjSkelExists\n"
        "testl %eax, %eax\n"
        "je .Lf1792fe_00179342\n"
        "movl -0x1c(%ebp), %eax\n" /* line 577 | boneIndex */
        "movl %eax, 0xc(%ebp)\n" /* boneIndex */
        "movl %esi, 8(%ebp)\n" /* obj */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjSkelIsBoneUpToDate\n" /* line 577 */
        ".Lf1792fe_00179342:\n"
        "movl %esi, (%esp)\n" /* line 579 | obj */
        "calll DObjGetAllocSkelSize\n"
        "movl %eax, 4(%esp)\n" /* line 580 */
        "movl %edi, (%esp)\n" /* localClientNum */
        "calll CL_AllocSkelMemory\n"
        "testl %eax, %eax\n" /* line 581 */
        "je .Lf1792fe_00179374\n"
        "movl %ebx, 8(%esp)\n" /* line 583 | timeStamp */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjCreateSkel\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1792fe_00179374:\n"
        "cmpl warnCount, %ebx\n" /* line 587 | timeStamp */
        "je .Lf1792fe_0017938e\n"
        "movl %ebx, warnCount\n" /* line 589 | timeStamp */
        "movl $0x2adbe4, (%esp)\n" /* line 590 */
        "calll Com_Printf\n"
        ".Lf1792fe_0017938e:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 594 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 604 */
__attribute__((naked))
qboolean CL_DObjCreateSkelForBones(const struct DObj_s *obj, int *partBits, int localClientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 604 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* obj */
        "movl 0xc(%ebp), %eax\n" /* partBits */
        "movl %eax, -0x1c(%ebp)\n" /* partBits */
        "movl 0x10(%ebp), %edi\n" /* localClientNum */
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 613 | localClientNum */
        "calll CL_GetSkelTimeStamp\n"
        "movl %eax, %ebx\n" /* timeStamp */
        "movl %eax, 4(%esp)\n" /* line 615 */
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjSkelExists\n"
        "testl %eax, %eax\n"
        "je .Lf17939c_001793e0\n"
        "movl -0x1c(%ebp), %eax\n" /* line 616 | partBits */
        "movl %eax, 0xc(%ebp)\n" /* partBits */
        "movl %esi, 8(%ebp)\n" /* obj */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp DObjSkelAreBonesUpToDate\n" /* line 616 */
        ".Lf17939c_001793e0:\n"
        "movl %esi, (%esp)\n" /* line 618 | obj */
        "calll DObjGetAllocSkelSize\n"
        "movl %eax, 4(%esp)\n" /* line 619 */
        "movl %edi, (%esp)\n" /* localClientNum */
        "calll CL_AllocSkelMemory\n"
        "testl %eax, %eax\n" /* line 620 */
        "je .Lf17939c_00179412\n"
        "movl %ebx, 8(%esp)\n" /* line 622 | timeStamp */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* obj */
        "calll DObjCreateSkel\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17939c_00179412:\n"
        "cmpl warnCount, %ebx\n" /* line 626 | timeStamp */
        "je .Lf17939c_0017942c\n"
        "movl %ebx, warnCount\n" /* line 628 | timeStamp */
        "movl $0x2adbe4, (%esp)\n" /* line 629 */
        "calll Com_Printf\n"
        ".Lf17939c_0017942c:\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 633 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 686 */
__attribute__((naked))
void CL_SubtitlePrint(const char *pszText, int iDuration, int iLineWidth)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 686 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* pszText */
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 690 | pszText */
        "calll SEH_StringEd_GetString\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 691 */
        "je .Lf17943c_00179478\n"
        "movl 0x10(%ebp), %eax\n" /* line 705 | iLineWidth */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* iDuration */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll CL_ConsolePrint\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 706 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17943c_00179478:\n"
        "movl 0x195f574, %eax\n" /* line 693 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17943c_001794f2\n"
        "movl 0x195f570, %eax\n" /* line 695 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17943c_001794e0\n"
        "movl %ebx, 8(%esp)\n" /* line 696 | pszText */
        "movl $0x2adc28, 4(%esp)\n" /* "Could not translate subtitle text: "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf17943c_001794aa:\n"
        "movl %ebx, 4(%esp)\n" /* line 699 | pszText */
        "movl $0x216bdc, (%esp)\n" /* "^1UNLOCALIZED(^7%s^1)^7" */
        "calll va\n"
        "movl %eax, %edx\n"
        "movl 0x10(%ebp), %eax\n" /* line 705 | iLineWidth */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* iDuration */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll CL_ConsolePrint\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 706 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17943c_001794e0:\n"
        "movl %ebx, 4(%esp)\n" /* line 698 | pszText */
        "movl $0x2adc50, (%esp)\n" /* "^3WARNING: Could not translate subtitle text: "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf17943c_001794aa\n"
        ".Lf17943c_001794f2:\n"
        "movl %ebx, %edx\n" /* line 693 | pszText */
        "movl 0x10(%ebp), %eax\n" /* line 705 | iLineWidth */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* iDuration */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $3, (%esp)\n"
        "calll CL_ConsolePrint\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 706 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 714 */
__attribute__((naked))
const char * CL_GetConfigString(int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 714 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 719 */
        "movl (%eax), %eax\n"
        "movl 8(%ebp), %edx\n" /* index */
        "movl 0x270c(%eax, %edx, 4), %edx\n"
        "leal 0x470c(%eax, %edx), %eax\n"
        "popl %ebp\n" /* line 720 */
        "retl\n"
    );
}

/* line 729 */
__attribute__((naked))
snd_alias_t * CL_PickSoundAlias(const char *aliasname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 729 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 732 */
        "jmp Com_PickSoundAlias\n" /* line 731 */
    );
}

/* line 753 */
__attribute__((naked))
struct XModel * CL_RegisterModel(const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 753 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 755 */
        "movl 8(%eax), %ecx\n"
        "popl %ebp\n" /* line 756 */
        "jmpl *%ecx\n" /* line 755 */
    );
}

/* line 765 */
__attribute__((naked))
struct GfxBrushModel * CL_RegisterInlineModel(int modelIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 765 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 767 */
        "movl 0xc(%eax), %ecx\n"
        "popl %ebp\n" /* line 768 */
        "jmpl *%ecx\n" /* line 767 */
    );
}

/* line 777 */
__attribute__((naked))
void CL_FinishLoadingModels(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 777 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 780 */
        "movl 0x24(%eax), %ecx\n"
        "popl %ebp\n" /* line 782 */
        "jmpl *%ecx\n" /* line 780 */
    );
}

/* line 803 */
__attribute__((naked))
MaterialHandle CL_RegisterMaterial(const char *name, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 803 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 805 | imageTrack */
        "movl %eax, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x10(%eax)\n"
        "leave\n" /* line 806 */
        "retl\n"
    );
}

/* line 815 */
__attribute__((naked))
MaterialHandle CL_RegisterMaterialNoMip(const char *name, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 815 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 817 | imageTrack */
        "movl %eax, 8(%esp)\n"
        "movl $0x30, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x10(%eax)\n"
        "leave\n" /* line 818 */
        "retl\n"
    );
}

/* line 828 */
__attribute__((naked))
MaterialHandle CL_Material_Duplicate(MaterialHandle mtlCopy, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 828 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 830 */
        "movl 0x13c(%eax), %ecx\n"
        "popl %ebp\n" /* line 831 */
        "jmpl *%ecx\n" /* line 830 */
    );
}

/* line 840 */
__attribute__((naked))
void CL_DuplicateFont(FontHandle fontCopy, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 840 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 842 */
        "movl 0x140(%eax), %ecx\n"
        "popl %ebp\n" /* line 843 */
        "jmpl *%ecx\n" /* line 842 */
    );
}

/* line 853 */
__attribute__((naked))
void CL_ClearScene(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 853 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 856 */
        "movl 0x48(%eax), %ecx\n"
        "popl %ebp\n" /* line 857 */
        "jmpl *%ecx\n" /* line 856 */
    );
}

/* line 886 */
__attribute__((naked))
void CL_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 886 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 888 */
        "movl 0x4c(%eax), %ecx\n"
        "popl %ebp\n" /* line 889 */
        "jmpl *%ecx\n" /* line 888 */
    );
}

/* line 892 */
__attribute__((naked))
void CL_AddPolyToScene(MaterialHandle mtlHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 892 */
        "movl %esp, %ebp\n"
        "movzwl 0xc(%ebp), %edx\n" /* lmapIndex */
        "movzwl 0x10(%ebp), %eax\n" /* vertCount */
        "movl %eax, 0x10(%ebp)\n" /* line 894 | vertCount */
        "movl %edx, 0xc(%ebp)\n" /* lmapIndex */
        "movl 0x195eca8, %eax\n"
        "movl 0x50(%eax), %ecx\n"
        "popl %ebp\n" /* line 895 */
        "jmpl *%ecx\n" /* line 894 */
    );
}

/* line 904 */
__attribute__((naked))
void CL_AddLightToScene(const vec_t *org, float radius, float r, float g, float b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 904 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 906 */
        "movl 0x54(%eax), %ecx\n"
        "popl %ebp\n" /* line 907 */
        "jmpl *%ecx\n" /* line 906 */
    );
}

/* line 916 */
__attribute__((naked))
void CL_SetFog(int fogvar, float start, float end, int r, int g, int b, float density)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 916 */
        "movl %esp, %ebp\n"
        "movzbl 0x1c(%ebp), %eax\n" /* line 918 | b */
        "movl %eax, 0x1c(%ebp)\n" /* b */
        "movzbl 0x18(%ebp), %eax\n" /* g */
        "movl %eax, 0x18(%ebp)\n" /* g */
        "movzbl 0x14(%ebp), %eax\n" /* r */
        "movl %eax, 0x14(%ebp)\n" /* r */
        "movl 0x195eca8, %eax\n"
        "movl 0x64(%eax), %ecx\n"
        "popl %ebp\n" /* line 919 */
        "jmpl *%ecx\n" /* line 918 */
    );
}

/* line 928 */
__attribute__((naked))
void CL_SwitchFog(int fogvar, int startTime, int transitionTime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 928 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 930 */
        "movl 0x68(%eax), %ecx\n"
        "popl %ebp\n" /* line 931 */
        "jmpl *%ecx\n" /* line 930 */
    );
}

/* line 940 */
__attribute__((naked))
void CL_RenderScene(const refdef_t *fd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 940 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 942 */
        "movl 0x7c(%eax), %ecx\n"
        "popl %ebp\n" /* line 943 */
        "jmpl *%ecx\n" /* line 942 */
    );
}

/* line 946 */
__attribute__((naked))
int CL_BeginDelayedDrawing(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 946 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 948 */
        "movl 0x80(%eax), %ecx\n"
        "popl %ebp\n" /* line 949 */
        "jmpl *%ecx\n" /* line 948 */
    );
}

/* line 952 */
__attribute__((naked))
void CL_EndDelayedDrawing(int marker)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 952 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 954 */
        "movl 0x84(%eax), %ecx\n"
        "popl %ebp\n" /* line 955 */
        "jmpl *%ecx\n" /* line 954 */
    );
}

/* line 958 */
__attribute__((naked))
void CL_IssueDelayedDrawing(int marker)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 958 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 960 */
        "movl 0x88(%eax), %ecx\n"
        "popl %ebp\n" /* line 961 */
        "jmpl *%ecx\n" /* line 960 */
    );
}

/* line 971 */
__attribute__((naked))
void CL_SetViewport(int x, int y, int width, int height)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 971 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 973 */
        "movl 0xcc(%eax), %ecx\n"
        "popl %ebp\n" /* line 974 */
        "jmpl *%ecx\n" /* line 973 */
    );
}

/* line 983 */
__attribute__((naked))
void CL_SaveScreen(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 983 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 985 */
        "movl 0xc0(%eax), %ecx\n"
        "popl %ebp\n" /* line 986 */
        "jmpl *%ecx\n" /* line 985 */
    );
}

/* line 995 */
__attribute__((naked))
void CL_BlendSavedScreen(int fadeMsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 995 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 997 */
        "movl 0xc4(%eax), %ecx\n"
        "popl %ebp\n" /* line 998 */
        "jmpl *%ecx\n" /* line 997 */
    );
}

/* line 1001 */
__attribute__((naked))
void CL_DrawStretchPicPhysical(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1001 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1003 */
        "movl 0x94(%eax), %ecx\n"
        "popl %ebp\n" /* line 1004 */
        "jmpl *%ecx\n" /* line 1003 */
    );
}

/* line 1026 */
__attribute__((naked))
void CL_DrawQuadPic(int (*verts)[16][4], const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1026 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1028 */
        "movl 0xa0(%eax), %ecx\n"
        "popl %ebp\n" /* line 1029 */
        "jmpl *%ecx\n" /* line 1028 */
    );
}

/* line 1032 */
__attribute__((naked))
void CL_DrawSprite(MaterialHandle material, const byte *rgbaColor, const vec_t *pos, float radius, float minScreenRadius, int renderFxFlags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1032 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1034 */
        "movl 0xa4(%eax), %ecx\n"
        "popl %ebp\n" /* line 1035 */
        "jmpl *%ecx\n" /* line 1034 */
    );
}

/* line 1044 */
__attribute__((naked))
void CL_ModelBounds(struct GfxBrushModel *model, vec_t *mins, vec_t *maxs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1044 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1046 */
        "movl 0xd4(%eax), %ecx\n"
        "popl %ebp\n" /* line 1047 */
        "jmpl *%ecx\n" /* line 1046 */
    );
}

/* line 1056 */
__attribute__((naked))
int CL_MarkFragments(objective_t * (*points)[4], const vec_t *origin, objective_t * (*axis)[4], float radius, int maxPoints, GfxWorldVertex *verts, int maxFragments, GfxMarkFragment *fragmentBuffer, MaterialHandle markMaterial)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1056 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1058 */
        "movl 0xd0(%eax), %ecx\n"
        "popl %ebp\n" /* line 1059 */
        "jmpl *%ecx\n" /* line 1058 */
    );
}

/* line 1068 */
__attribute__((naked))
void CL_TrackStatistics(trStatistics_t *pStats)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1068 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1070 */
        "movl 0xd8(%eax), %ecx\n"
        "popl %ebp\n" /* line 1071 */
        "jmpl *%ecx\n" /* line 1070 */
    );
}

/* line 1080 */
__attribute__((naked))
qboolean CL_PickMaterial(const vec_t *org, const vec_t *dir, char *pszName, char *pszSurfaceFlags, char *pszContents, int iMaxChars)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1080 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1082 */
        "movl 0xdc(%eax), %ecx\n"
        "popl %ebp\n" /* line 1083 */
        "jmpl *%ecx\n" /* line 1082 */
    );
}

/* line 1093 */
__attribute__((naked))
void CL_LoadSoundAliases(const char *loadspec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1093 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, 8(%esp)\n" /* line 1095 */
        "movl $0x21f990, 4(%esp)\n" /* "all_mp" */
        "movl 8(%ebp), %eax\n" /* loadspec */
        "movl %eax, (%esp)\n"
        "calll Com_LoadSoundAliases\n"
        "leave\n" /* line 1096 */
        "retl\n"
    );
}

/* line 1106 */
__attribute__((naked))
qboolean CL_Popup(const char *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1106 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* menu */
        "movl 0x195ee8c, %eax\n" /* line 1109 */
        "movl (%eax), %eax\n"
        "cmpl $8, (%eax)\n"
        "je .Lf179772_00179790\n"
        ".Lf179772_00179788:\n"
        "xorl %eax, %eax\n" /* line 1124 */
        ".Lf179772_0017978a:\n"
        "addl $0x14, %esp\n" /* line 1127 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf179772_00179790:\n"
        "movl 0x407a0(%eax), %ecx\n" /* line 1109 */
        "testl %ecx, %ecx\n"
        "jne .Lf179772_00179788\n"
        "calll UI_IsFullscreen\n"
        "testl %eax, %eax\n"
        "jne .Lf179772_00179788\n"
        "movl $0x2adcb8, 4(%esp)\n" /* line 1113 */
        "movl %ebx, (%esp)\n" /* menu */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf179772_001797da\n"
        "movl $0x13, 8(%esp)\n" /* line 1119 */
        "movl $0x2adc84, 4(%esp)\n" /* "UIMENU_SCRIPT_POPUP" */
        "movl %ebx, (%esp)\n" /* menu */
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf179772_001797ed\n"
        "movl $1, %eax\n"
        "jmp .Lf179772_0017978a\n"
        ".Lf179772_001797da:\n"
        "movl $8, (%esp)\n" /* line 1114 */
        "calll UI_SetActiveMenu\n"
        "movl $1, %eax\n"
        "jmp .Lf179772_0017978a\n"
        ".Lf179772_001797ed:\n"
        "movl $0x2adc98, 4(%esp)\n" /* line 1121 */
        "movl %ebx, (%esp)\n" /* menu */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf179772_00179812\n"
        "movl $0xa, 8(%ebp)\n" /* line 1122 | menu */
        "addl $0x14, %esp\n" /* line 1127 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp UI_SetActiveMenu\n" /* line 1122 */
        ".Lf179772_00179812:\n"
        "movl $9, 8(%ebp)\n" /* line 1124 | menu */
        "addl $0x14, %esp\n" /* line 1127 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp UI_SetActiveMenu\n" /* line 1124 */
    );
}

/* line 1136 */
__attribute__((naked))
void CL_ClosePopup(const char *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1136 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* menu */
        "calll UI_IsFullscreen\n" /* line 1139 */
        "testl %eax, %eax\n"
        "je .Lf179824_0017983d\n"
        ".Lf179824_00179837:\n"
        "addl $0x14, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf179824_0017983d:\n"
        "movl $0x2adc98, 4(%esp)\n" /* line 1141 */
        "movl %ebx, (%esp)\n" /* menu */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf179824_0017985b\n"
        "calll UI_GetActiveMenu\n"
        "cmpl $9, %eax\n"
        "je .Lf179824_00179879\n"
        ".Lf179824_0017985b:\n"
        "movl $0x2adc84, 4(%esp)\n" /* "UIMENU_SCRIPT_POPUP" */
        "movl %ebx, (%esp)\n" /* menu */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf179824_00179837\n"
        "calll UI_GetActiveMenu\n"
        "cmpl $9, %eax\n"
        "jne .Lf179824_00179837\n"
        ".Lf179824_00179879:\n"
        "addl $0x14, %esp\n" /* line 1144 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp UI_CloseFocusedMenu\n" /* line 1142 */
    );
}

/* line 1152 */
__attribute__((naked))
void CL_CloseInGameMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1152 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll UI_IsFullscreen\n" /* line 1155 */
        "testl %eax, %eax\n"
        "je .Lf179884_00179895\n"
        ".Lf179884_00179893:\n"
        "leave\n" /* line 1157 */
        "retl\n"
        ".Lf179884_00179895:\n"
        "calll UI_GetActiveMenu\n" /* line 1155 */
        "cmpl $2, %eax\n"
        "jne .Lf179884_00179893\n"
        "leave\n" /* line 1157 */
        "jmp UI_CloseFocusedMenu\n" /* line 1156 */
    );
}

/* line 1166 */
__attribute__((naked))
void CL_CloseAllMenus(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1166 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll UI_IsFullscreen\n" /* line 1168 */
        "testl %eax, %eax\n"
        "je .Lf1798a6_001798b7\n"
        "leave\n" /* line 1174 */
        "retl\n"
        ".Lf1798a6_001798b7:\n"
        "movl $1, 4(%esp)\n" /* line 1170 */
        "movl $0x1b, (%esp)\n"
        "calll UI_KeyEvent\n"
        "movl $1, 4(%esp)\n" /* line 1171 */
        "movl $0x1b, (%esp)\n"
        "calll UI_KeyEvent\n"
        "movl $1, 4(%esp)\n" /* line 1172 */
        "movl $0x1b, (%esp)\n"
        "calll UI_KeyEvent\n"
        "leave\n" /* line 1174 */
        "retl\n"
    );
}

/* line 1183 */
__attribute__((naked))
void CL_SetWeaponInfoMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1183 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, (%esp)\n" /* line 1185 */
        "calll Com_SetWeaponInfoMemory\n"
        "leave\n" /* line 1186 */
        "retl\n"
    );
}

/* line 1195 */
__attribute__((naked))
void CL_FreeWeaponInfoMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1195 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, (%esp)\n" /* line 1197 */
        "calll Com_FreeWeaponInfoMemory\n"
        "leave\n" /* line 1198 */
        "retl\n"
    );
}

/* line 1235 */
__attribute__((naked))
void CL_FX_AdjustCamera(refdef_t *refdef)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1235 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195eca8, %eax\n" /* line 1237 */
        "calll *0x40(%eax)\n"
        "fstps 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* refdef */
        "movl %eax, (%esp)\n"
        "calll FX_AdjustCamera\n"
        "leave\n" /* line 1238 */
        "retl\n"
    );
}

/* line 1247 */
__attribute__((naked))
void CL_CapTurnRate(float maxPitchSpeed, float maxYawSpeed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1247 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 1249 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* maxPitchSpeed */
        "movl %eax, 0x8608(%edx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 1250 | maxYawSpeed */
        "movl %eax, 0x860c(%edx)\n"
        "popl %ebp\n" /* line 1251 */
        "retl\n"
    );
}

/* line 1285 */
__attribute__((naked))
void LoadWorld(const char *mapname)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1285 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, 4(%esp)\n" /* line 1287 */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x1c(%eax)\n"
        "leave\n" /* line 1289 */
        "jmp Com_UnloadBsp\n" /* line 1288 */
    );
}

/* line 1306 */
__attribute__((naked))
void CL_UpdateLevelHunkUsage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1306 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        /* { scope 1 */
        "calll Hunk_Used\n" /* line 1318 */
        "movl %eax, -0x12c(%ebp)\n" /* memusage */
        "movl $0, 8(%esp)\n" /* line 1320 */
        "leal -0x1c(%ebp), %eax\n" /* handle */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a70ec, (%esp)\n" /* "hunkusage.dat" */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %edi\n" /* len */
        "testl %eax, %eax\n" /* line 1321 */
        "js .Lf17997e_00179b89\n"
        "leal 1(%eax), %ebx\n" /* line 1324 */
        "movl %ebx, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, -0x130(%ebp)\n" /* buf */
        "movl %ebx, 8(%esp)\n" /* line 1325 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl %ebx, (%esp)\n" /* line 1326 */
        "calll Z_MallocInternal\n"
        "movl %eax, %esi\n" /* outbuf */
        "movl %ebx, 8(%esp)\n" /* line 1327 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1329 | handle */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* len */
        "movl -0x130(%ebp), %edi\n" /* buf, len */
        "movl %edi, (%esp)\n" /* len */
        "calll FS_Read\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1330 | handle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl %edi, -0x20(%ebp)\n" /* line 1333 | len, buftrav */
        "movb $0, (%esi)\n" /* line 1335 | outbuf */
        ".Lf17997e_00179a27:\n"
        "leal -0x20(%ebp), %edi\n" /* line 1336 | buftrav, len */
        "movl %edi, (%esp)\n" /* len */
        "calll Com_Parse\n"
        "movl %eax, %edi\n" /* len */
        "testl %eax, %eax\n"
        "je .Lf17997e_00179b05\n"
        ".Lf17997e_00179a3c:\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17997e_00179b05\n"
        "movl 0x195ee78, %eax\n" /* line 1338 */
        "movl (%eax), %eax\n"
        "addl $0x8590, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* len */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17997e_00179aa0\n"
        "leal -0x20(%ebp), %eax\n" /* line 1341 | buftrav */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 1342 */
        "je .Lf17997e_00179a27\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17997e_00179a27\n"
        "movl %eax, (%esp)\n" /* line 1344 */
        "calll atoi\n"
        "cmpl %eax, -0x12c(%ebp)\n" /* memusage */
        "jne .Lf17997e_00179a27\n"
        "movl -0x130(%ebp), %edi\n" /* line 1346 | buf, len */
        "movl %edi, (%esp)\n" /* len */
        "calll Z_FreeInternal\n"
        "movl %esi, (%esp)\n" /* line 1347 | outbuf */
        "calll Z_FreeInternal\n"
        "jmp .Lf17997e_00179c40\n"
        ".Lf17997e_00179aa0:\n"
        "movl %edi, 8(%esp)\n" /* line 1354 | len */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* outbuf */
        "calll I_strncat\n"
        "movl $0x217914, 8(%esp)\n" /* line 1355 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* outbuf */
        "calll I_strncat\n"
        "leal -0x20(%ebp), %eax\n" /* line 1356 | buftrav */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "testl %eax, %eax\n" /* line 1357 */
        "je .Lf17997e_00179adc\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf17997e_00179c4b\n"
        ".Lf17997e_00179adc:\n"
        "movl $0x2adcd0, 4(%esp)\n" /* line 1364 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "leal -0x20(%ebp), %edi\n" /* line 1336 | buftrav, len */
        "movl %edi, (%esp)\n" /* len */
        "calll Com_Parse\n"
        "movl %eax, %edi\n" /* len */
        "testl %eax, %eax\n"
        "jne .Lf17997e_00179a3c\n"
        ".Lf17997e_00179b05:\n"
        "movl $0x2a70ec, (%esp)\n" /* line 1377 */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, -0x1c(%ebp)\n" /* handle */
        "testl %eax, %eax\n" /* line 1378 */
        "je .Lf17997e_00179c8d\n"
        ".Lf17997e_00179b1c:\n"
        "cld\n" /* line 1381 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* outbuf, len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1382 | handle */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* outbuf */
        "calll FS_Write\n"
        "cmpl %eax, %ebx\n"
        "je .Lf17997e_00179b68\n"
        "movl $0x2a70ec, 4(%esp)\n" /* line 1383 */
        "movl $0x2add04, (%esp)\n" /* "EXE_ERR_CANT_WRITE%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf17997e_00179b68:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1384 | handle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl -0x130(%ebp), %eax\n" /* line 1386 | buf */
        "movl %eax, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl %esi, (%esp)\n" /* line 1387 | outbuf */
        "calll Z_FreeInternal\n"
        ".Lf17997e_00179b89:\n"
        "movl $2, 8(%esp)\n" /* line 1390 */
        "leal -0x1c(%ebp), %edi\n" /* handle, len */
        "movl %edi, 4(%esp)\n" /* len */
        "movl $0x2a70ec, (%esp)\n" /* "hunkusage.dat" */
        "calll FS_FOpenFileByMode\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 1391 | handle */
        "testl %ebx, %ebx\n"
        "je .Lf17997e_00179c74\n"
        ".Lf17997e_00179baf:\n"
        "movl -0x12c(%ebp), %eax\n" /* line 1393 | memusage */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x195ee78, %eax\n"
        "movl (%eax), %eax\n"
        "addl $0x8590, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2add3c, 8(%esp)\n" /* "%s %i
" */
        "movl $0x100, 4(%esp)\n"
        "leal -0x120(%ebp), %ebx\n" /* outstr */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1394 | handle */
        "movl %eax, 8(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_Write\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1395 | handle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $0, 8(%esp)\n" /* line 1398 */
        "leal -0x1c(%ebp), %eax\n" /* handle */
        "movl %eax, 4(%esp)\n"
        "movl $0x2a70ec, (%esp)\n" /* "hunkusage.dat" */
        "calll FS_FOpenFileByMode\n"
        "testl %eax, %eax\n" /* line 1399 */
        "js .Lf17997e_00179c40\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1400 | handle */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        /* } scope */
        ".Lf17997e_00179c40:\n"
        "addl $0x14c, %esp\n" /* line 1402 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17997e_00179c4b:\n"
        "movl %eax, 8(%esp)\n" /* line 1359 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* outbuf */
        "calll I_strncat\n"
        "movl $0x2160e8, 8(%esp)\n" /* line 1360 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* outbuf */
        "calll I_strncat\n"
        "jmp .Lf17997e_00179a27\n"
        ".Lf17997e_00179c74:\n"
        "movl $0x2add1c, 4(%esp)\n" /* line 1392 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf17997e_00179baf\n"
        ".Lf17997e_00179c8d:\n"
        "movl $0x2a70ec, 4(%esp)\n" /* line 1379 */
        "movl $0x2adcec, (%esp)\n" /* "EXE_ERR_CANT_CREATE%s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf17997e_00179b1c\n"
    );
}

/* line 1411 */
__attribute__((naked))
void CL_StartLoading(const char *mapname, const char *gametype)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1411 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "movl 0x195ecb4, %eax\n" /* line 1413 */
        "movl (%eax), %eax\n"
        "movl 4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf179cb6_00179ccc\n"
        "leave\n" /* line 1418 */
        "retl\n"
        ".Lf179cb6_00179ccc:\n"
        "calll CL_StartHunkUsers\n" /* line 1416 */
        "leave\n" /* line 1418 */
        "jmp SCR_UpdateScreenInternal\n" /* line 1417 */
    );
}

/* line 1426 */
__attribute__((naked))
void CL_InitCGame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1426 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "calll Sys_Milliseconds\n" /* line 1435 */
        "movl %eax, %edi\n" /* t1 */
        "calll Con_Close\n" /* line 1438 */
        "movl 0x195ee78, %eax\n" /* line 1441 */
        "movl (%eax), %esi\n"
        "movl $0x2a7124, 4(%esp)\n" /* line 1442 */
        "movl 0x270c(%esi), %eax\n"
        "leal 0x470c(%esi, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mapname */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "calll GetBspExtension\n" /* line 1447 */
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x2a74ac, 8(%esp)\n" /* "maps/mp/%s.%s" */
        "movl $0x40, 4(%esp)\n"
        "leal 0x8590(%esi), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl 0x195ecbc, %eax\n" /* line 1455 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf179cd8_00179d6d\n"
        "calll Com_InitDObj\n" /* line 1457 */
        "movl %ebx, (%esp)\n" /* line 1460 */
        "calll CL_SetExpectedHunkUsage\n"
        ".Lf179cd8_00179d6d:\n"
        "movl 0x195ee8c, %eax\n" /* line 1468 */
        "movl (%eax), %ebx\n"
        "movl $6, (%ebx)\n"
        "movb $1, 0xa(%esi)\n" /* line 1473 */
        "movl 8(%ebx), %eax\n" /* line 1474 */
        "movl %eax, 8(%esp)\n"
        "movl 0x20140(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x20138(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CG_Init\n"
        "movb $1, 9(%esi)\n" /* line 1479 */
        "movl $7, (%ebx)\n" /* line 1487 */
        "calll Sys_Milliseconds\n" /* line 1489 */
        "subl %edi, %eax\n" /* line 1491 | t1 */
        "cvtsi2sdl %eax, %xmm0\n"
        "divsd 0x307d50, %xmm0\n" /* 1000.0 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2add44, (%esp)\n" /* "CL_InitCGame: %5.2f seconds
" */
        "calll Com_Printf\n"
        "movl 0x195eca8, %eax\n" /* line 1495 */
        "calll *0x44(%eax)\n"
        "calll Com_TouchMemory\n" /* line 1499 */
        "calll Con_ClearNotify\n" /* line 1503 */
        "calll Con_ClearSubtitles\n" /* line 1504 */
        "calll CL_UpdateLevelHunkUsage\n" /* line 1508 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1518 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1528 */
__attribute__((naked))
qboolean CL_GameCommand(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1528 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 1530 */
        "movl (%eax), %eax\n"
        "cmpb $0, 9(%eax)\n"
        "jne .Lf179df0_00179e04\n"
        "xorl %eax, %eax\n" /* line 1536 */
        "popl %ebp\n"
        "retl\n"
        ".Lf179df0_00179e04:\n"
        "popl %ebp\n"
        "jmp CG_ConsoleCommand\n" /* line 1535 */
    );
}

/* line 1561 */
__attribute__((naked))
void CL_AdjustTimeDelta(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1561 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x195ee78, %edi\n" /* line 1567 */
        "movl (%edi), %ebx\n"
        "movl $0, 0x2708(%ebx)\n"
        "movl 0x195ee8c, %eax\n" /* line 1570 */
        "movl (%eax), %eax\n"
        "movl 0x407a0(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf179e0a_00179efd\n"
        "movl 0x20(%ebx), %eax\n" /* line 1575 */
        "movl %eax, %ecx\n"
        "subl 0x2700(%ebx), %ecx\n"
        "movl 0x195ecac, %edx\n" /* line 1577 */
        "subl 0x118(%edx), %eax\n"
        "subl %ecx, %eax\n"
        "leal -5(%eax), %esi\n" /* newDelta */
        "movl 0x26fc(%ebx), %edx\n" /* line 1578 */
        "movl %esi, %eax\n" /* newDelta */
        "subl %edx, %eax\n"
        "testl %eax, %eax\n" /* line 1580 */
        "jle .Lf179e0a_00179f90\n"
        "cmpl $0x1f4, %ecx\n" /* line 1582 */
        "jbe .Lf179e0a_00179f3b\n"
        ".Lf179e0a_00179e74:\n"
        "cmpl $0x1f4, %eax\n" /* line 1594 */
        "jg .Lf179e0a_00179f05\n"
        ".Lf179e0a_00179e7f:\n"
        "cmpl $0x64, %eax\n" /* line 1607 */
        "jle .Lf179e0a_00179f43\n"
        "movl 0x195f5ec, %ebx\n" /* line 1610 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf179e0a_00179f79\n"
        ".Lf179e0a_00179e9a:\n"
        "movl (%edi), %edx\n" /* line 1614 */
        "movl %esi, %eax\n" /* newDelta */
        "addl 0x26fc(%edx), %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, 0x26fc(%edx)\n"
        ".Lf179e0a_00179eac:\n"
        "movl (%ebx), %eax\n" /* line 1642 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf179e0a_00179efd\n"
        "movl 0x195ee78, %eax\n" /* line 1644 */
        "movl (%eax), %ebx\n"
        "movl 0x20(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x195ecac, %eax\n"
        "movl 0x118(%eax), %eax\n"
        "addl 0x26fc(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x2add78, (%esp)\n" /* "client time: %i, server time: %i
" */
        "calll Com_Printf\n"
        "movl 0x26fc(%ebx), %eax\n" /* line 1645 */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* newDelta */
        "movl $0x2add9c, (%esp)\n" /* "snapshot delta: %i, time delta: %i
" */
        "calll Com_Printf\n"
        /* } scope */
        ".Lf179e0a_00179efd:\n"
        "addl $0x1c, %esp\n" /* line 1647 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf179e0a_00179f05:\n"
        "movl %esi, 0x26fc(%ebx)\n" /* line 1599 | newDelta */
        "movl (%edi), %eax\n" /* line 1600 */
        "movl 0x20(%eax), %edx\n"
        "movl %edx, 0x26f4(%eax)\n"
        "movl %edx, 0x26f0(%eax)\n" /* line 1601 */
        "movl 0x195f5ec, %ebx\n" /* line 1602 */
        "movl (%ebx), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf179e0a_00179efd\n"
        "movl $0x2add64, (%esp)\n" /* line 1604 */
        "calll Com_Printf\n"
        "jmp .Lf179e0a_00179eac\n"
        ".Lf179e0a_00179f3b:\n"
        "subl %ecx, %eax\n" /* line 1585 */
        "jns .Lf179e0a_00179e74\n"
        ".Lf179e0a_00179f43:\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 1623 | 1.0f */
        "movl 0x195f4a8, %eax\n"
        "ucomiss (%eax), %xmm0\n"
        "jne .Lf179e0a_00179fa2\n"
        "jp .Lf179e0a_00179fa2\n"
        "movl 0x2704(%ebx), %eax\n" /* line 1625 */
        "testl %eax, %eax\n"
        "jne .Lf179e0a_00179fad\n"
        "cmpl %edx, %esi\n" /* line 1630 | newDelta */
        "jle .Lf179e0a_00179fcb\n"
        "leal 1(%edx), %eax\n" /* line 1633 */
        "movl %eax, 0x26fc(%ebx)\n"
        "movl 0x195f5ec, %ebx\n"
        "jmp .Lf179e0a_00179eac\n"
        ".Lf179e0a_00179f79:\n"
        "movl $0x2add70, (%esp)\n" /* line 1612 */
        "calll Com_Printf\n"
        "movl 0x195ee78, %edi\n"
        "jmp .Lf179e0a_00179e9a\n"
        ".Lf179e0a_00179f90:\n"
        "negl %eax\n" /* line 1591 */
        "cmpl $0x1f4, %eax\n" /* line 1594 */
        "jle .Lf179e0a_00179e7f\n"
        "jmp .Lf179e0a_00179f05\n"
        ".Lf179e0a_00179fa2:\n"
        "movl 0x195f5ec, %ebx\n"
        "jmp .Lf179e0a_00179eac\n"
        ".Lf179e0a_00179fad:\n"
        "movl $0, 0x2704(%ebx)\n" /* line 1627 */
        "movl (%edi), %eax\n" /* line 1628 */
        "subl $2, 0x26fc(%eax)\n"
        "movl 0x195f5ec, %ebx\n"
        "jmp .Lf179e0a_00179eac\n"
        ".Lf179e0a_00179fcb:\n"
        "jge .Lf179e0a_00179fa2\n" /* line 1635 */
        "leal -1(%edx), %eax\n" /* line 1637 */
        "movl %eax, 0x26fc(%ebx)\n"
        "movl 0x195f5ec, %ebx\n"
        "jmp .Lf179e0a_00179eac\n"
    );
}

/* line 1876 */
__attribute__((naked))
void CL_SetADS(int ads)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1876 */
        "movl %esp, %ebp\n"
        "movl 0x195ee78, %eax\n" /* line 1878 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* ads */
        "movb %al, 0xb(%edx)\n"
        "popl %ebp\n" /* line 1879 */
        "retl\n"
    );
}

/* line 1888 */
__attribute__((naked))
void CL_DrawString(int x, int y, const char *pszString, qboolean bShadow, int iCharHeight)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1888 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0x195ee78, %eax\n" /* line 1890 */
        "movl (%eax), %eax\n"
        "cmpb $0, 9(%eax)\n"
        "jne .Lf179ff4_0017a009\n"
        "leave\n" /* line 1894 */
        "retl\n"
        ".Lf179ff4_0017a009:\n"
        "movl $1, 0x1c(%esp)\n" /* line 1893 */
        "cvtsi2ssl 0x18(%ebp), %xmm0\n" /* iCharHeight */
        "movss %xmm0, 0x18(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* bShadow */
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* pszString */
        "movl %eax, 8(%esp)\n"
        "cvtsi2ssl 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "cvtsi2ssl 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CG_DrawStringExt\n"
        "leave\n" /* line 1894 */
        "retl\n"
    );
}

/* line 1897 */
__attribute__((naked))
void CL_ArchiveClientState(MemoryFile *memFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1897 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* memFile */
        "movl %ebx, (%esp)\n" /* line 1899 | memFile */
        "calll CG_ArchiveState\n"
        "movl %ebx, 8(%ebp)\n" /* line 1900 | memFile */
        "movl 0x195eca8, %eax\n"
        "movl 0x6c(%eax), %ecx\n"
        "addl $0x14, %esp\n" /* line 1901 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 1900 */
    );
}

/* line 1968 */
__attribute__((naked))
void CL_SetLodOrigin(const refdef_t *fd)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1968 */
        "movl %esp, %ebp\n"
        "movl 0x195eca8, %eax\n" /* line 1970 */
        "movl 0x15c(%eax), %ecx\n"
        "popl %ebp\n" /* line 1971 */
        "jmpl *%ecx\n" /* line 1970 */
    );
}

/* line 1909 */
__attribute__((naked))
void CL_LookupColor(int c, vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1909 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* color */
        "movzbl 8(%ebp), %ebx\n" /* c */
        /* { scope 1 */
        "movzbl %bl, %eax\n" /* line 1913 | c */
        "movl %eax, (%esp)\n"
        "calll ColorIndex\n"
        "movzbl %al, %eax\n"
        "cmpl $7, %eax\n" /* line 1914 */
        "ja .Lf17a08c_0017a0d8\n"
        "shll $4, %eax\n" /* line 1916 */
        "leal g_color_table(%eax), %edx\n" /* from */
        /* { scope 2 */
        "movl g_color_table(%eax), %eax\n" /* line 456 */
        /* } scope */
        /* { scope 2 */
        ".Lf17a08c_0017a0bd:\n"
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n" /* line 457 */
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n" /* line 458 */
        "movl %eax, 8(%esi)\n"
        "movl 0xc(%edx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1934 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17a08c_0017a0d8:\n"
        "cmpb $0x38, %bl\n" /* line 1920 | c */
        "je .Lf17a08c_0017a0f9\n"
        "cmpb $0x39, %bl\n" /* c */
        "je .Lf17a08c_0017a10e\n"
        "movl $0x3f800000, %eax\n" /* line 447 */
        "movl %eax, (%esi)\n"
        "movl %eax, 4(%esi)\n" /* line 448 */
        "movl %eax, 8(%esi)\n" /* line 449 */
        "movl %eax, 0xc(%esi)\n" /* line 450 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1934 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17a08c_0017a0f9:\n"
        "movl 0x195ee78, %eax\n" /* line 1920 */
        "movl (%eax), %eax\n"
        "leal 0x862c(%eax), %edx\n"
        /* { scope 2 */
        "movl 0x862c(%eax), %eax\n" /* line 456 */
        "jmp .Lf17a08c_0017a0bd\n"
        ".Lf17a08c_0017a10e:\n"
        "movl 0x195ee78, %eax\n" /* line 1924 */
        "movl (%eax), %eax\n"
        "leal 0x863c(%eax), %edx\n"
        /* } scope */
        /* { scope 2 */
        "movl 0x863c(%eax), %eax\n" /* line 456 */
        "jmp .Lf17a08c_0017a0bd\n"
    );
}

/* line 247 */
__attribute__((naked))
void CL_SetUserCmdAimValues(vec_t *kickAngles)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 247 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* kickAngles */
        "movl 0x195ee78, %eax\n" /* line 249 */
        "movl (%eax), %ecx\n"
        "leal 0x8610(%ecx), %ebx\n" /* to */
        /* { scope 1 */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, 0x8610(%ecx)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "popl %ebx\n" /* line 250 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1954 */
__attribute__((naked))
void CL_UpdateColor(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1954 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0x195ee78, %eax\n" /* line 1956 */
        "movl (%eax), %ebx\n"
        "leal 0x862c(%ebx), %esi\n" /* color */
        /* { scope 1 */
        "movl %esi, 4(%esp)\n" /* line 1944 */
        "movl $0x2addc0, (%esp)\n" /* "g_TeamColor_Allies" */
        "calll Dvar_GetUnpackedColorByName\n"
        "movl $0x3f800000, %edi\n" /* line 1945 */
        "movl %edi, 0xc(%esi)\n"
        /* } scope */
        "addl $0x863c, %ebx\n" /* line 1957 | color */
        /* { scope 1 */
        "movl %ebx, 4(%esp)\n" /* line 1944 */
        "movl $0x2addd4, (%esp)\n" /* "g_TeamColor_Axis" */
        "calll Dvar_GetUnpackedColorByName\n"
        "movl %edi, 0xc(%ebx)\n" /* line 1945 */
        /* } scope */
        "movl %ebx, 4(%esp)\n" /* line 1959 | color */
        "movl %esi, (%esp)\n" /* color */
        "movl 0x195eca8, %eax\n"
        "calll *0x10c(%eax)\n"
        "addl $0x1c, %esp\n" /* line 1960 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 964 */
__attribute__((naked))
void CL_SetFullScreenViewport(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 964 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0x195ecac, %ebx\n" /* line 973 */
        "movl 0x2a0a68(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2a0a64(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0xcc(%eax)\n"
        "movl 0x2a0a68(%ebx), %eax\n" /* line 967 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2a0a64(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x3f800000, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll SetScreenScaling\n"
        "addl $0x24, %esp\n" /* line 968 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1007 */
__attribute__((naked))
void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1007 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        "movl 0x1c(%ebp), %eax\n" /* line 1009 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x14(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x10(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "leal 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movl 0x34(%ebp), %eax\n" /* line 1003 | material */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x30(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* t2 */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* s2 */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* t1 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* s1 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* h */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "movl 0x195eca8, %eax\n"
        "calll *0x94(%eax)\n"
        "leave\n" /* line 1011 */
        "retl\n"
    );
}

/* line 1272 */
__attribute__((naked))
void CL_SyncTimes(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1272 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0x195ee8c, %eax\n" /* line 1274 */
        "movl (%eax), %ebx\n"
        "cmpl $8, (%ebx)\n"
        "je .Lf17a2ae_0017a2c9\n"
        ".Lf17a2ae_0017a2c2:\n"
        "addl $0x10, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17a2ae_0017a2c9:\n"
        "movl 0x195ee78, %eax\n" /* line 1658 */
        "movl (%eax), %ecx\n"
        "testb $2, 0x1c(%ecx)\n"
        "jne .Lf17a2ae_0017a2c2\n"
        "movl $8, (%ebx)\n" /* line 1662 */
        "movl 0x20(%ecx), %edx\n" /* line 1665 */
        "movl 0x195ecac, %eax\n"
        "movl %edx, %esi\n"
        "subl 0x118(%eax), %esi\n"
        "movl %esi, 0x26fc(%ecx)\n"
        "movl %edx, 0x26f4(%ecx)\n" /* line 1666 */
        "movl %edx, 0x407c4(%ebx)\n" /* line 1668 */
        "movl 0x195f5f0, %ebx\n" /* line 1674 */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17a2ae_0017a2c2\n"
        "movl %eax, (%esp)\n" /* line 1676 */
        "calll Cbuf_AddText\n"
        "movl $0x2160e8, (%esp)\n" /* line 1677 */
        "calll Cbuf_AddText\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1678 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "addl $0x10, %esp\n" /* line 1276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1743 */
__attribute__((naked))
void CL_SetCGameTime(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1743 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0x195ee8c, %eax\n" /* line 1746 */
        "movl (%eax), %edx\n"
        "movl (%edx), %eax\n"
        "cmpl $8, %eax\n"
        "je .Lf17a33c_0017a405\n"
        "cmpl $7, %eax\n" /* line 1748 */
        "je .Lf17a33c_0017a364\n"
        ".Lf17a33c_0017a35c:\n"
        "addl $0x2c, %esp\n" /* line 1865 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17a33c_0017a364:\n"
        "movl 0x407a0(%edx), %eax\n" /* line 1752 */
        "testl %eax, %eax\n"
        "je .Lf17a33c_0017a38f\n"
        "movl 0x407ac(%edx), %eax\n" /* line 1756 */
        "testl %eax, %eax\n"
        "jne .Lf17a33c_0017a38a\n"
        "movl $1, 0x407ac(%edx)\n" /* line 1758 */
        "addl $0x2c, %esp\n" /* line 1865 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17a33c_0017a38a:\n"
        "calll CL_ReadDemoMessage\n" /* line 1761 */
        ".Lf17a33c_0017a38f:\n"
        "movl 0x195ee78, %eax\n" /* line 1763 */
        "movl (%eax), %ebx\n"
        "movl 0x2708(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17a33c_0017a3f4\n"
        "movl $0, 0x2708(%ebx)\n" /* line 1765 */
        "testb $2, 0x1c(%ebx)\n" /* line 1658 */
        "jne .Lf17a33c_0017a3f4\n"
        "movl 0x195ee8c, %edx\n" /* line 1662 */
        "movl (%edx), %ecx\n"
        "movl $8, (%ecx)\n"
        "movl 0x20(%ebx), %edx\n" /* line 1665 */
        "movl 0x195ecac, %eax\n"
        "movl %edx, %esi\n"
        "subl 0x118(%eax), %esi\n"
        "movl %esi, 0x26fc(%ebx)\n"
        "movl %edx, 0x26f4(%ebx)\n" /* line 1666 */
        "movl %edx, 0x407c4(%ecx)\n" /* line 1668 */
        "movl 0x195f5f0, %ebx\n" /* line 1674 */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf17a33c_0017a6d7\n"
        ".Lf17a33c_0017a3f4:\n"
        "movl 0x195ee8c, %edx\n" /* line 1768 */
        "movl (%edx), %eax\n"
        "cmpl $8, (%eax)\n"
        "jne .Lf17a33c_0017a35c\n"
        ".Lf17a33c_0017a405:\n"
        "movl 0x195ee78, %eax\n" /* line 1775 */
        "movl (%eax), %eax\n"
        "movl 0x18(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf17a33c_0017a5e7\n"
        ".Lf17a33c_0017a417:\n"
        "movl 0x195f564, %eax\n" /* line 1781 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf17a33c_0017a5b7\n"
        ".Lf17a33c_0017a429:\n"
        "movl 0x195ee78, %edi\n" /* line 1787 */
        "movl (%edi), %ebx\n"
        "movl 0x20(%ebx), %eax\n"
        "cmpl 0x26f8(%ebx), %eax\n"
        "jl .Lf17a33c_0017a600\n"
        ".Lf17a33c_0017a440:\n"
        "movl (%edi), %edx\n" /* line 1800 */
        "movl 0x20(%edx), %ebx\n"
        "movl %ebx, 0x26f8(%edx)\n"
        "movl 0x195ee8c, %ecx\n" /* line 1804 */
        "movl (%ecx), %eax\n"
        "movl 0x407a0(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf17a33c_0017a540\n"
        "movl 0x195f5f4, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17a33c_0017a540\n"
        ".Lf17a33c_0017a472:\n"
        "movl (%edi), %ebx\n" /* line 1834 */
        "movl 0x2708(%ebx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf17a33c_0017a694\n"
        ".Lf17a33c_0017a482:\n"
        "movl 0x195ee8c, %eax\n" /* line 1839 */
        "movl (%eax), %esi\n"
        "movl 0x407a0(%esi), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf17a33c_0017a35c\n"
        "movl 0x407a4(%esi), %eax\n" /* line 1852 */
        "testl %eax, %eax\n"
        "je .Lf17a33c_0017a510\n"
        "movl 0x407b4(%esi), %eax\n" /* line 1723 */
        "testl %eax, %eax\n"
        "je .Lf17a33c_0017a702\n"
        ".Lf17a33c_0017a4af:\n"
        "calll Sys_Milliseconds\n" /* line 1726 */
        "movl %eax, %ebx\n"
        "movl 0x195ee8c, %ecx\n" /* line 1727 */
        "movl (%ecx), %edx\n"
        "movl 0x407bc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf17a33c_0017a69e\n"
        "movl %ebx, 0x407bc(%edx)\n" /* line 1728 */
        ".Lf17a33c_0017a4d2:\n"
        "movl 0x195ee8c, %esi\n" /* line 1731 */
        "movl (%esi), %edx\n"
        "movl %ebx, 0x407c0(%edx)\n"
        "movl 0x407b8(%edx), %eax\n" /* line 1733 */
        "addl $1, %eax\n"
        "movl %eax, 0x407b8(%edx)\n"
        "movl 0x195ee78, %edi\n" /* line 1734 */
        "movl (%edi), %ecx\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0x407c4(%edx), %edx\n"
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, 0x26f0(%ecx)\n"
        "movl %ecx, %edx\n"
        "jmp .Lf17a33c_0017a518\n"
        ".Lf17a33c_0017a510:\n"
        "movl 0x195ee78, %edi\n"
        "movl (%edi), %edx\n"
        ".Lf17a33c_0017a518:\n"
        "movl 0x26f0(%edx), %eax\n" /* line 1855 */
        "cmpl 0x20(%edx), %eax\n"
        "jl .Lf17a33c_0017a35c\n"
        "calll CL_ReadDemoMessage\n" /* line 1859 */
        "movl 0x195ee8c, %eax\n" /* line 1860 */
        "movl (%eax), %eax\n"
        "cmpl $8, (%eax)\n"
        "je .Lf17a33c_0017a510\n"
        "addl $0x2c, %esp\n" /* line 1865 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17a33c_0017a540:\n"
        "movl 0x195ecac, %esi\n" /* line 1811 */
        "movl 0x26fc(%edx), %ecx\n"
        "movl 0x118(%esi), %eax\n"
        "addl %ecx, %eax\n"
        "movl %eax, 0x26f0(%edx)\n"
        "movl 0x26f4(%edx), %eax\n" /* line 1815 */
        "cmpl %eax, 0x26f0(%edx)\n"
        "jge .Lf17a33c_0017a5df\n"
        "movl %eax, 0x26f0(%edx)\n" /* line 1817 */
        ".Lf17a33c_0017a56e:\n"
        "movl %eax, 0x26f4(%edx)\n" /* line 1819 */
        "addl 0x118(%esi), %ecx\n" /* line 1823 */
        "leal -5(%ebx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jl .Lf17a33c_0017a472\n"
        "movl $1, 0x2704(%edx)\n" /* line 1825 */
        "movl 0x195f5ec, %eax\n" /* line 1826 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17a33c_0017a472\n"
        "movl $0x2ade3c, (%esp)\n" /* line 1827 */
        "calll Com_Printf\n"
        "movl 0x195ee78, %edi\n"
        "jmp .Lf17a33c_0017a472\n"
        ".Lf17a33c_0017a5b7:\n"
        "movl 0x195ed18, %eax\n" /* line 1781 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf17a33c_0017a429\n"
        "movl 0x195ecbc, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17a33c_0017a429\n"
        "jmp .Lf17a33c_0017a35c\n"
        ".Lf17a33c_0017a5df:\n"
        "movl 0x26f0(%edx), %eax\n"
        "jmp .Lf17a33c_0017a56e\n"
        ".Lf17a33c_0017a5e7:\n"
        "movl $0x2adde8, 4(%esp)\n" /* line 1777 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf17a33c_0017a417\n"
        ".Lf17a33c_0017a600:\n"
        "movl $0x2a8ab8, 4(%esp)\n" /* line 1790 */
        "movl 0x195ecac, %esi\n"
        "leal 8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf17a33c_0017a78f\n"
        "testb $2, 0x1c(%ebx)\n" /* line 1658 */
        "jne .Lf17a33c_0017a440\n"
        "movl 0x195ee8c, %eax\n" /* line 1662 */
        "movl (%eax), %ecx\n"
        "movl $8, (%ecx)\n"
        "movl 0x20(%ebx), %eax\n" /* line 1665 */
        "movl %eax, %edx\n"
        "subl 0x118(%esi), %edx\n"
        "movl %edx, 0x26fc(%ebx)\n"
        "movl %eax, 0x26f4(%ebx)\n" /* line 1666 */
        "movl %eax, 0x407c4(%ecx)\n" /* line 1668 */
        "movl 0x195f5f0, %ebx\n" /* line 1674 */
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf17a33c_0017a440\n"
        "movl %eax, (%esp)\n" /* line 1676 */
        "calll Cbuf_AddText\n"
        "movl $0x2160e8, (%esp)\n" /* line 1677 */
        "calll Cbuf_AddText\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1678 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf17a33c_0017a440\n"
        ".Lf17a33c_0017a694:\n"
        "calll CL_AdjustTimeDelta\n" /* line 1836 */
        "jmp .Lf17a33c_0017a482\n"
        ".Lf17a33c_0017a69e:\n"
        "movl 0x407b4(%edx), %ecx\n" /* line 1729 */
        "testl %ecx, %ecx\n"
        "je .Lf17a33c_0017a4d2\n"
        "movl %ebx, %eax\n" /* line 1730 */
        "subl 0x407c0(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x407b8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2ade78, 4(%esp)\n" /* "%i,%i
" */
        "movl %ecx, (%esp)\n"
        "calll FS_Printf\n"
        "jmp .Lf17a33c_0017a4d2\n"
        ".Lf17a33c_0017a6d7:\n"
        "movl %eax, (%esp)\n" /* line 1676 */
        "calll Cbuf_AddText\n"
        "movl $0x2160e8, (%esp)\n" /* line 1677 */
        "calll Cbuf_AddText\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 1678 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf17a33c_0017a3f4\n"
        ".Lf17a33c_0017a702:\n"
        "movl $0x223dd8, (%esp)\n" /* line 1724 */
        "calll Dvar_GetInt\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal 0x8590(%ebx), %edi\n" /* line 1696 */
        "movzbl 0x8590(%ebx), %eax\n" /* line 1697 */
        "testb %al, %al\n"
        "je .Lf17a33c_0017a765\n"
        "movl %edi, %ecx\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf17a33c_0017a73c\n"
        ".Lf17a33c_0017a728:\n"
        "cmpb $0x5c, %al\n" /* line 1699 */
        "je .Lf17a33c_0017a740\n"
        "cmpb $0x2e, %al\n" /* line 1704 */
        "je .Lf17a33c_0017a7a8\n"
        "leal 1(%ecx), %edx\n"
        ".Lf17a33c_0017a733:\n"
        "movzbl (%edx), %eax\n" /* line 1697 */
        "testb %al, %al\n"
        "je .Lf17a33c_0017a749\n"
        "movl %edx, %ecx\n"
        ".Lf17a33c_0017a73c:\n"
        "cmpb $0x2f, %al\n" /* line 1699 */
        "jne .Lf17a33c_0017a728\n"
        ".Lf17a33c_0017a740:\n"
        "leal 1(%ecx), %edi\n" /* line 1701 */
        "movl %edi, %edx\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lf17a33c_0017a733\n"
        ".Lf17a33c_0017a749:\n"
        "testl %ebx, %ebx\n" /* line 1710 */
        "je .Lf17a33c_0017a765\n"
        "movl %edi, 4(%esp)\n" /* line 1713 */
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll va\n"
        "subl %edi, %ebx\n" /* line 1714 */
        "movb $0, (%eax, %ebx)\n"
        "movl %eax, %edi\n" /* line 1715 */
        ".Lf17a33c_0017a765:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1724 */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $0x2ade58, (%esp)\n" /* "demos/timedemo_%s_mode_%i.csv" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll FS_FOpenFileWrite\n"
        "movl %eax, 0x407b4(%esi)\n"
        "jmp .Lf17a33c_0017a4af\n"
        ".Lf17a33c_0017a78f:\n"
        "movl $0x2ade0c, 4(%esp)\n" /* line 1797 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf17a33c_0017a440\n"
        ".Lf17a33c_0017a7a8:\n"
        "leal 1(%ecx), %edx\n" /* line 1704 */
        "movl %ecx, %ebx\n"
        "jmp .Lf17a33c_0017a733\n"
    );
}

