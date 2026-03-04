/* Decompiled from: cl_cgame_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_cgame_mp.cpp */

#include "common_types.h"
#include "imports.h"

#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

extern void Com_Error(errorParm_t code, const char *fmt, ...);
extern void Com_Printf(const char *fmt, ...);
extern void Com_DPrintf(const char *fmt, ...);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern const char *Com_Parse(const char **buf_p);
extern void Com_LoadBsp(const char *name);
extern void Com_UnloadBsp(void);
extern void Com_TouchMemory(void);
extern void Com_InitDObj(void);
extern void Com_SetWeaponInfoMemory(int mode);
extern void Com_FreeWeaponInfoMemory(int mode);
extern void Com_UnloadSoundAliases(int mode);
extern void Com_LoadSoundAliases(const char *loadspec, const char *zone, int flag);
extern snd_alias_t *Com_PickSoundAlias(const char *aliasname);
extern const char *Cmd_Argv(int n);
extern int Cmd_Argc(void);
extern void Cmd_TokenizeString(const char *text);
extern void Cmd_TokenizeString2(const char *text, int flags);
extern void Cmd_AddCommand(const char *cmd, void (*func)(void));
extern int I_stricmp(const char *s1, const char *s2);
extern int I_strnicmp(const char *s1, const char *s2, int n);
extern void I_strncat(char *dest, const char *src, int maxLen);
extern void I_strncpyz(char *dest, const char *src, int maxLen);
extern void CM_LoadMap(const char *name, int *checksum);
extern void CM_LinkWorld(void);
extern void CG_Init(int serverMessageNum, int serverCommandSequence, int clientNum);
extern void CG_Shutdown(void);
extern qboolean CG_ConsoleCommand(void);
extern void CG_DrawStringExt(float x, float y, const char *string, int maxChars, int shadow, int flags, float charHeight, int bold);
extern void CG_ArchiveState(MemoryFile *memFile);
extern void CL_SystemInfoChanged(void);
extern void CL_StartHunkUsers(void);
extern void CL_ReadDemoMessage(void);
extern int CL_GetSkelTimeStamp(int localClientNum);
extern void *CL_AllocSkelMemory(int localClientNum, int size);
extern void CL_ConsolePrint(int channel, const char *text, int duration, int lineWidth);
extern int DObjSkelExists(const struct DObj_s *obj, int timeStamp);
extern qboolean DObjSkelIsBoneUpToDate(const struct DObj_s *obj, int boneIndex);
extern qboolean DObjSkelAreBonesUpToDate(const struct DObj_s *obj, int *partBits);
extern int DObjGetAllocSkelSize(const struct DObj_s *obj);
extern void DObjCreateSkel(const struct DObj_s *obj, void *mem, int timeStamp);
extern void FX_AdjustCamera(refdef_t *refdef, float zfar);
extern int FS_FOpenFileByMode(const char *filename, int *handle, int mode);
extern int FS_FOpenFileWrite(const char *filename);
extern void FS_Read(void *buffer, int len, int handle);
extern int FS_Write(const void *buffer, int len, int handle);
extern void FS_FCloseFile(int handle);
extern void FS_Printf(int handle, const char *fmt, ...);
extern int Hunk_Used(void);
extern void *Z_MallocInternal(int size);
extern void Z_FreeInternal(void *ptr);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern const char *GetBspExtension(void);
extern int Sys_Milliseconds(void);
extern void Con_Close(void);
extern void Con_ClearNotify(void);
extern void Con_ClearSubtitles(void);
extern const char *SEH_SafeTranslateString(const char *text);
extern const char *SEH_StringEd_GetString(const char *text);
extern const char *UI_ReplaceConversionString(const char *base, const char *replacement);
extern void UI_SetActiveMenu(int menu);
extern int UI_GetActiveMenu(void);
extern qboolean UI_IsFullscreen(void);
extern void UI_CloseFocusedMenu(void);
extern void UI_KeyEvent(int key, int down);
extern void SCR_UpdateScreenInternal(void);
extern void Cbuf_AddText(const char *text);
extern void Dvar_SetString(void *dvar, const char *value);
extern void Dvar_SetInt(void *dvar, int value);
extern int Dvar_GetInt(const char *name);
extern void Dvar_GetUnpackedColorByName(const char *name, float *color);
extern void CalcScreenPlacement(float *x, float *y, float *w, float *h, int horzAlign, int vertAlign);
extern void SetScreenScaling(float scaleX, float scaleY, int x, int y, int w, int h);
extern void StatMon_Warning(int type, int threshold, const char *msg);
extern const char *va(const char *fmt, ...);
extern unsigned char ColorIndex(unsigned char c);
extern int atoi(const char *str);
extern char *strcat(char *dest, const char *src);

static int warnCount; /* warnCount */
static int warnCount_00f13084; /* warnCount */
static char bigConfigString[8192]; /* bigConfigString */
static vec4_t g_color_table[8]; /* g_color_table */

#define RE         ((refexport_t *)imp_re)
#define CLS        ((char *)imp_cls)
#define CL_LOCAL   ((char *)*(void **)imp_cl)
#define CLUI_STATE ((char *)*(void **)imp_clc)

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

/* Helper: inline CL_FirstSnapshot logic */
static void CL_FirstSnapshot(void)
{
    char *cl = CL_LOCAL;
    char *clui = CLUI_STATE;

    *(int *)clui = 8; /* CA_ACTIVE */
    int serverTime = *(int *)(cl + 0x20);
    char *cls = CLS;
    *(int *)(cl + 0x26fc) = serverTime - *(int *)(cls + 0x118);
    *(int *)(cl + 0x26f4) = serverTime;
    *(int *)(clui + 0x407c4) = serverTime;

    /* Execute autorecord command if set */
    char *autorecDvar = *(char **)*(void **)imp_cl_activeAction;
    const char *autorecStr = *(const char **)(autorecDvar + 8);
    if (*autorecStr) {
        Cbuf_AddText(autorecStr);
        Cbuf_AddText("\n");
        Dvar_SetString(autorecDvar, "");
    }
}

/* line 79 */
void CL_GetScreenDimensions(int *width, int *height, float *aspect)
{
    char *cls = CLS;
    *width = *(int *)(cls + 0x2a0a64);
    *height = *(int *)(cls + 0x2a0a68);
    *aspect = *(float *)(cls + 0x2a0a74);
}

/* line 91 */
qboolean CL_GetUserCmd(int cmdNumber, usercmd_t *ucmd)
{
    char *cl = CL_LOCAL;
    int currentCmd = *(int *)(cl + 0x4945c);

    if (currentCmd < cmdNumber) {
        Com_Error(ERR_DROP, "CL_GetUserCmd: %i >= %i", cmdNumber, currentCmd);
        currentCmd = *(int *)(cl + 0x4945c);
    }

    if (cmdNumber <= currentCmd - 128) {
        return 0;
    }

    int idx = cmdNumber & 0x7f;
    char *cmdEntry = cl + 0x48650 + idx * 28;
    memcpy(ucmd, cmdEntry + 12, 28);
    return 1;
}

/* line 114 */
int CL_GetCurrentCmdNumber(void)
{
    char *cl = CL_LOCAL;
    return *(int *)(cl + 0x4945c);
}

/* line 125 */
void CL_GetCurrentSnapshotNumber(int *snapshotNumber, int *serverTime)
{
    char *cl = CL_LOCAL;
    *snapshotNumber = *(int *)(cl + 0x24);
    *serverTime = *(int *)(cl + 0x20);
}

/* line 137 */
qboolean CL_GetSnapshot(int snapshotNumber, snapshot_t *snapshot)
{
    char *cl = CL_LOCAL;
    int count;
    int i;

    if (*(int *)(cl + 0x24) < snapshotNumber) {
        Com_Error(ERR_DROP, "CL_GetSnapshot: snapshotNumber > cl.snap.messageNum");
    }

    if (*(int *)(cl + 0x24) - snapshotNumber > 0x1f) {
        return 0;
    }

    /* Calculate snapshot entry: array at cl+0x495e0, stride 9944 bytes, 32 entries */
    int idx = snapshotNumber & 0x1f;
    char *clSnap = cl + 0x495e0 + idx * 9944;

    if (*(int *)clSnap == 0) {
        return 0;
    }

    if (*(int *)(cl + 0x85d0) - *(int *)(clSnap + 0x26cc) > 0x7ff) {
        return 0;
    }
    if (*(int *)(cl + 0x85d4) - *(int *)(clSnap + 0x26d0) > 0x7ff) {
        return 0;
    }

    /* Copy basic snapshot fields */
    *(int *)((char *)snapshot) = *(int *)(clSnap + 4);
    *(int *)((char *)snapshot + 0x12dbc) = *(int *)(clSnap + 0x26d4);
    *(int *)((char *)snapshot + 4) = *(int *)(clSnap + 0x14);
    *(int *)((char *)snapshot + 8) = *(int *)(clSnap + 8);

    /* Copy playerstate data */
    memcpy((char *)snapshot + 0xc, clSnap + 0x1c, 0x26a8);

    /* Entity states count */
    count = *(int *)(clSnap + 0x26c4);
    if (count > 256) {
        char *statmonCfg = *(char **)*(void **)imp_com_statmon;
        if (*(unsigned char *)(statmonCfg + 8)) {
            StatMon_Warning(4, 3000, "CL_GetSnapshot: truncated entities");
        } else {
            Com_DPrintf("CL_GetSnapshot: truncated %i entities to %i\n", count, 256);
        }
        count = 256;
    }

    *(int *)((char *)snapshot + 0x26b4) = count;

    /* Copy entity states: stride 0xF0 (240) bytes, circular buffer at cl+0xd30e0 */
    for (i = 0; i < count; i++) {
        int entIdx = (i + *(int *)(clSnap + 0x26cc)) & 0x7ff;
        char *src = cl + 0xd30e0 + entIdx * 240;
        char *dst = (char *)snapshot + 0x26bc + i * 240;
        memcpy(dst, src, 240);
    }

    /* Client states count, clamped to 64 */
    int clientCount = *(int *)(clSnap + 0x26c8);
    if (clientCount > 64) {
        clientCount = 64;
    }
    *(int *)((char *)snapshot + 0x26b8) = clientCount;

    /* Copy client states: stride 0x5C (92) bytes, circular buffer at cl+0x14b0e0 */
    for (i = 0; i < clientCount; i++) {
        int cliIdx = (i + *(int *)(clSnap + 0x26d0)) & 0x7ff;
        char *src = cl + 0x14b0e0 + cliIdx * 92;
        char *dst = (char *)snapshot + 0x116bc + i * 92;
        memcpy(dst, src, 92);
    }

    return 1;
}

/* line 234 */
void CL_SetUserCmdValue(int userCmdValue, int holdableValue, float sensitivityScale)
{
    char *cl = CL_LOCAL;
    *(int *)(cl + 0x85f8) = userCmdValue;
    *(int *)(cl + 0x85fc) = holdableValue;
    *(float *)(cl + 0x8604) = sensitivityScale;
}

/* line 258 */
void CL_SetUserCmdInShellshock(qboolean shocked)
{
    char *cl = CL_LOCAL;
    *(int *)(cl + 0x8600) = shocked;
}

/* line 275 */
void CL_AddCgameCommand(const char *cmdName)
{
    Cmd_AddCommand(cmdName, 0);
}

/* line 286 */
void CL_ConfigstringModified(void)
{
    char oldGs[0x5e84];
    int index;
    const char *s;
    int i, len;
    char *cl;

    index = atoi(Cmd_Argv(1));
    if ((unsigned int)index > 0x7ff) {
        Com_Error(ERR_DROP, "CL_ConfigstringModified: bad index");
    }

    s = Cmd_Argv(2);

    cl = CL_LOCAL;
    /* Check if configstring changed */
    {
        int offset = *(int *)(cl + 0x270c + index * 4);
        const char *old = cl + 0x470c + offset;
        if (strcmp(old, s) == 0)
            return;
    }

    /* Backup old configstring data */
    memcpy(oldGs, cl + 0x270c, 0x5e84);

    /* Reset configstring area */
    memset(cl + 0x270c, 0, 0x5e84);
    *(int *)(cl + 0x858c) = 1;

    /* Rebuild configstrings */
    for (i = 0; i < 0x800; i++) {
        const char *dup;

        if (i == index) {
            dup = s;
        } else {
            int oldOff = *(int *)((char *)oldGs + i * 4);
            dup = (char *)oldGs + 0x2000 + oldOff;
        }

        if (*dup == '\0')
            continue;

        len = strlen(dup) + 1;
        cl = CL_LOCAL;
        int writePos = *(int *)(cl + 0x858c);
        if (writePos + len > 0x3e80) {
            Com_Error(ERR_DROP, "CL_ConfigstringModified: overflow");
            writePos = *(int *)(cl + 0x858c);
        }

        *(int *)(cl + 0x270c + i * 4) = writePos;
        memcpy(cl + 0x470c + writePos, dup, len);
        *(int *)(cl + 0x858c) = writePos + len;
    }

    if (index == 1) {
        CL_SystemInfoChanged();
    }
}

/* line 359 */
qboolean CL_GetServerCommand(int serverCommandNumber)
{
    char *clui = CLUI_STATE;
    char *s;
    const char *cmd;
    int argc;

    if (serverCommandNumber <= *(int *)(clui + 0x2013c) - 128) {
        if (*(int *)(clui + 0x407a0)) {
            return 0;
        }
        Com_Printf("CL_GetServerCommand: a]command was lost\n");
        Com_Printf("serverCommandNumber: %d\n", serverCommandNumber & 0x7f);
        {
            int j;
            for (j = 0; j < 128; j++) {
                char *clui2 = CLUI_STATE;
                Com_Printf("cmd %5d: %s\n", j, clui2 + 0x20144 + (j & 0x7f) * 1024);
            }
        }
        Com_Error(ERR_DROP, "CL_GetServerCommand: too many missed");
    }

    clui = CLUI_STATE;
    if (serverCommandNumber > *(int *)(clui + 0x2013c)) {
        Com_Error(ERR_DROP, "CL_GetServerCommand: requested beyond last");
    }

    s = clui + 0x20144 + (serverCommandNumber & 0x7f) * 1024;
    *(int *)(clui + 0x20140) = serverCommandNumber;

    {
        char *debugCvar = *(char **)*(void **)imp_cl_showServerCommands;
        if (*(unsigned char *)(debugCvar + 8)) {
            Com_DPrintf("serverCommand: %i : %s\n", serverCommandNumber, s);
        }
    }

restart:
    Cmd_TokenizeString(s);
    cmd = Cmd_Argv(0);
    argc = Cmd_Argc();

    if (cmd[0] < 'B' || cmd[0] > 'z') {
        return 1;
    }

    switch (cmd[0]) {
    case 'd':
        if (argc - 1 <= 0) {
            Com_Error(ERR_SERVERDISCONNECT, "EXE_DISCONNECTED");
        }
        {
            const char *reason = SEH_SafeTranslateString(Cmd_Argv(1));
            const char *base = SEH_SafeTranslateString("EXE_SERVERDISCONNECTREASON");
            const char *msg = UI_ReplaceConversionString(base, reason);
            Com_Error(ERR_SERVERDISCONNECT, msg);
        }
        /* fall through after Com_Error */
    case 'B':
        Cmd_TokenizeString2(s, 3);
        {
            const char *arg2 = Cmd_Argv(2);
            const char *arg1 = Cmd_Argv(1);
            Com_sprintf(bigConfigString, 0x2000, "%c %s %s", 'd', arg1, arg2);
        }
        return 0;
    case 'b':
        Cmd_TokenizeString2(s, 3);
        {
            const char *arg2 = Cmd_Argv(2);
            if (strlen(bigConfigString) + strlen(arg2) > 0x1fff) {
                Com_Error(ERR_DROP, "BCS overflow");
            }
            strcat(bigConfigString, arg2);
        }
        return 0;
    case 'c':
        Cmd_TokenizeString2(s, 3);
        {
            const char *arg2 = Cmd_Argv(2);
            if (strlen(bigConfigString) + strlen(arg2) + 1 > 0x1fff) {
                Com_Error(ERR_DROP, "BCS overflow");
            }
            strcat(bigConfigString, arg2);
        }
        s = bigConfigString;
        goto restart;
    case 'z':
        Con_ClearNotify();
        Con_ClearSubtitles();
        memset(CL_LOCAL + 0x4865c, 0, 0xe00);
        RE->ClearFlares();
        return 1;
    case 'C':
        Cmd_TokenizeString2(s, 3);
        CL_ConfigstringModified();
        Cmd_TokenizeString2(s, 3);
        return 1;
    default:
        return 1;
    }
}

/* line 470 */
void CL_SetExpectedHunkUsage(const char *mapname)
{
    int handle;
    int len;
    char *buf;
    const char *buftrav;
    const char *token;

    len = FS_FOpenFileByMode("hunkusage.dat", &handle, 0);
    if (len < 0) {
        goto set_default;
    }

    buf = (char *)Z_MallocInternal(len + 1);
    memset(buf, 0, len + 1);
    FS_Read(buf, len, handle);
    FS_FCloseFile(handle);

    buftrav = buf;
    while (1) {
        token = Com_Parse(&buftrav);
        if (!token || *token == '\0')
            break;

        if (I_stricmp(token, mapname) != 0)
            continue;

        token = Com_Parse(&buftrav);
        if (!token || *token == '\0')
            continue;

        Dvar_SetInt(*(void **)*(void **)imp_com_expectedHunkUsage, atoi(token));
        Z_FreeInternal(buf);
        return;
    }

    Z_FreeInternal(buf);

set_default:
    Dvar_SetInt(*(void **)*(void **)imp_com_expectedHunkUsage, 0);
}

/* line 522 */
void CL_CM_LoadMap(const char *mapname)
{
    int checksum;

    Com_LoadBsp(mapname);
    CM_LoadMap(mapname, &checksum);

    if (!*(unsigned char *)(*(char **)*(void **)imp_com_sv_running + 8)) {
        CM_LinkWorld();
    }
}

/* line 539 */
void CL_ShutdownCGame(void)
{
    char *cl;

    Com_UnloadSoundAliases(1);
    cl = CL_LOCAL;
    if (*(unsigned char *)(cl + 0xa)) {
        CG_Shutdown();
        *(unsigned char *)(cl + 0xa) = 0;
        *(unsigned char *)(cl + 9) = 0;
    }
}

/* line 565 */
qboolean CL_DObjCreateSkelForBone(struct DObj_s *obj, int boneIndex, int localClientNum)
{
    int timeStamp;
    void *mem;

    timeStamp = CL_GetSkelTimeStamp(localClientNum);

    if (DObjSkelExists(obj, timeStamp)) {
        return DObjSkelIsBoneUpToDate(obj, boneIndex);
    }

    mem = CL_AllocSkelMemory(localClientNum, DObjGetAllocSkelSize(obj));
    if (mem) {
        DObjCreateSkel(obj, mem, timeStamp);
        return 0;
    }

    if (timeStamp != warnCount) {
        warnCount = timeStamp;
        Com_Printf("CL_DObjCreateSkelForBone: Not enough skel memory\n");
    }
    return 1;
}

/* line 604 */
qboolean CL_DObjCreateSkelForBones(const struct DObj_s *obj, int *partBits, int localClientNum)
{
    int timeStamp;
    void *mem;

    timeStamp = CL_GetSkelTimeStamp(localClientNum);

    if (DObjSkelExists(obj, timeStamp)) {
        return DObjSkelAreBonesUpToDate(obj, partBits);
    }

    mem = CL_AllocSkelMemory(localClientNum, DObjGetAllocSkelSize(obj));
    if (mem) {
        DObjCreateSkel(obj, mem, timeStamp);
        return 0;
    }

    if (timeStamp != warnCount) {
        warnCount = timeStamp;
        Com_Printf("CL_DObjCreateSkelForBone: Not enough skel memory\n");
    }
    return 1;
}

/* line 686 */
void CL_SubtitlePrint(const char *pszText, int iDuration, int iLineWidth)
{
    const char *translated = SEH_StringEd_GetString(pszText);

    if (translated) {
        CL_ConsolePrint(3, translated, iDuration, iLineWidth);
        return;
    }

    {
        char *locCvar = *(char **)*(void **)imp_loc_warnings;
        if (!*(unsigned char *)(locCvar + 8)) {
            CL_ConsolePrint(3, pszText, iDuration, iLineWidth);
            return;
        }
    }

    {
        char *devCvar = *(char **)*(void **)imp_loc_warningsAsErrors;
        if (*(unsigned char *)(devCvar + 8)) {
            Com_Error(ERR_FATAL, "Could not translate subtitle text: \"%s\"", pszText);
        } else {
            Com_Printf("^3WARNING: Could not translate subtitle text: \"%s\"\n", pszText);
        }
    }

    CL_ConsolePrint(3, va("^1UNLOCALIZED(^7%s^1)^7", pszText), iDuration, iLineWidth);
}

/* line 714 */
const char *CL_GetConfigString(int index)
{
    char *cl = CL_LOCAL;
    int offset = *(int *)(cl + 0x270c + index * 4);
    return cl + 0x470c + offset;
}

/* line 729 */
snd_alias_t *CL_PickSoundAlias(const char *aliasname)
{
    return Com_PickSoundAlias(aliasname);
}

/* line 753 */
struct XModel *CL_RegisterModel(const char *name)
{
    return RE->RegisterModel(name);
}

/* line 765 */
struct GfxBrushModel *CL_RegisterInlineModel(int modelIndex)
{
    return RE->RegisterInlineModel(modelIndex);
}

/* line 777 */
void CL_FinishLoadingModels(void)
{
    RE->FinishLoadingModels();
}

/* line 803 */
MaterialHandle CL_RegisterMaterial(const char *name, int imageTrack)
{
    return RE->RegisterMaterial(name, 3, imageTrack);
}

/* line 815 */
MaterialHandle CL_RegisterMaterialNoMip(const char *name, int imageTrack)
{
    return RE->RegisterMaterial(name, 0x30, imageTrack);
}

/* line 828 */
MaterialHandle CL_Material_Duplicate(MaterialHandle mtlCopy, const char *name)
{
    return RE->Material_Duplicate(mtlCopy, name);
}

/* line 840 */
void CL_DuplicateFont(FontHandle fontCopy, const char *name)
{
    RE->DuplicateFont(fontCopy, name);
}

/* line 853 */
void CL_ClearScene(void)
{
    RE->ClearScene();
}

/* line 886 */
void CL_DefaultVertexFrames(int vertCount, GfxWorldVertex *verts)
{
    RE->DefaultVertexFrames(vertCount, verts);
}

/* line 892 */
void CL_AddPolyToScene(MaterialHandle mtlHandle, int lmapIndex, int vertCount, const GfxWorldVertex *verts)
{
    RE->AddPolyToScene(mtlHandle, (unsigned short)lmapIndex, (unsigned short)vertCount, verts);
}

/* line 904 */
void CL_AddLightToScene(const vec_t *org, float radius, float r, float g, float b)
{
    RE->AddLightToScene(org, radius, r, g, b);
}

/* line 916 */
void CL_SetFog(int fogvar, float start, float end, int r, int g, int b, float density)
{
    RE->SetFog(fogvar, start, end, (unsigned char)r, (unsigned char)g, (unsigned char)b, density);
}

/* line 928 */
void CL_SwitchFog(int fogvar, int startTime, int transitionTime)
{
    RE->SwitchFog(fogvar, startTime, transitionTime);
}

/* line 940 */
void CL_RenderScene(const refdef_t *fd)
{
    RE->RenderScene(fd);
}

/* line 946 */
int CL_BeginDelayedDrawing(void)
{
    return RE->BeginDelayedDrawing();
}

/* line 952 */
void CL_EndDelayedDrawing(int marker)
{
    RE->EndDelayedDrawing(marker);
}

/* line 958 */
void CL_IssueDelayedDrawing(int marker)
{
    RE->IssueDelayedDrawing(marker);
}

/* line 971 */
void CL_SetViewport(int x, int y, int width, int height)
{
    RE->SetViewport(x, y, width, height);
}

/* line 983 */
void CL_SaveScreen(void)
{
    RE->SaveScreen();
}

/* line 995 */
void CL_BlendSavedScreen(int fadeMsec)
{
    RE->BlendSavedScreen(fadeMsec);
}

/* line 1001 */
void CL_DrawStretchPicPhysical(float x, float y, float w, float h, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material)
{
    RE->DrawStretchPic(x, y, w, h, s1, t1, s2, t2, color, material);
}

/* line 1026 */
void CL_DrawQuadPic(int (*verts)[16][4], const vec_t *color, MaterialHandle material)
{
    RE->DrawQuadPic(verts, color, material);
}

/* line 1032 */
void CL_DrawSprite(MaterialHandle material, const byte *rgbaColor, const vec_t *pos, float radius, float minScreenRadius, int renderFxFlags)
{
    RE->DrawSprite(material, rgbaColor, pos, radius, minScreenRadius, renderFxFlags);
}

/* line 1044 */
void CL_ModelBounds(struct GfxBrushModel *model, vec_t *mins, vec_t *maxs)
{
    RE->ModelBounds(model, mins, maxs);
}

/* line 1056 */
int CL_MarkFragments(objective_t * (*points)[4], const vec_t *origin, objective_t * (*axis)[4], float radius, int maxPoints, GfxWorldVertex *verts, int maxFragments, GfxMarkFragment *fragmentBuffer, MaterialHandle markMaterial)
{
    return RE->MarkFragments(points, origin, axis, radius, maxPoints, verts, maxFragments, fragmentBuffer, markMaterial);
}

/* line 1068 */
void CL_TrackStatistics(trStatistics_t *pStats)
{
    RE->TrackStatistics(pStats);
}

/* line 1080 */
qboolean CL_PickMaterial(const vec_t *org, const vec_t *dir, char *pszName, char *pszSurfaceFlags, char *pszContents, int iMaxChars)
{
    return RE->PickMaterial(org, dir, pszName, pszSurfaceFlags, pszContents, iMaxChars);
}

/* line 1093 */
void CL_LoadSoundAliases(const char *loadspec)
{
    Com_LoadSoundAliases(loadspec, "all_mp", 1);
}

/* line 1106 */
qboolean CL_Popup(const char *menu)
{
    char *clui = CLUI_STATE;

    if (*(int *)clui != 8)
        return 0;

    if (*(int *)(clui + 0x407a0))
        return 0;

    if (UI_IsFullscreen())
        return 0;

    if (I_stricmp(menu, "UIMENU_INGAME") == 0) {
        UI_SetActiveMenu(8);
        return 1;
    }

    if (I_strnicmp(menu, "UIMENU_SCRIPT_POPUP", 0x13) != 0) {
        return 1;
    }

    if (I_stricmp(menu, "UIMENU_SCRIPT_POPUP_SUBMENU") == 0) {
        UI_SetActiveMenu(10);
        return 1;
    }

    UI_SetActiveMenu(9);
    return 1;
}

/* line 1136 */
void CL_ClosePopup(const char *menu)
{
    if (UI_IsFullscreen())
        return;

    if (I_stricmp(menu, "UIMENU_SCRIPT_POPUP_SUBMENU") == 0) {
        if (UI_GetActiveMenu() == 9) {
            UI_CloseFocusedMenu();
        }
        return;
    }

    if (I_stricmp(menu, "UIMENU_SCRIPT_POPUP") == 0 && UI_GetActiveMenu() == 9) {
        UI_CloseFocusedMenu();
    }
}

/* line 1152 */
void CL_CloseInGameMenu(void)
{
    if (UI_IsFullscreen())
        return;
    if (UI_GetActiveMenu() != 2)
        return;
    UI_CloseFocusedMenu();
}

/* line 1166 */
void CL_CloseAllMenus(void)
{
    if (UI_IsFullscreen())
        return;
    UI_KeyEvent(0x1b, 1);
    UI_KeyEvent(0x1b, 1);
    UI_KeyEvent(0x1b, 1);
}

/* line 1183 */
void CL_SetWeaponInfoMemory(void)
{
    Com_SetWeaponInfoMemory(2);
}

/* line 1195 */
void CL_FreeWeaponInfoMemory(void)
{
    Com_FreeWeaponInfoMemory(2);
}

/* line 1235 */
void CL_FX_AdjustCamera(refdef_t *refdef)
{
    float zfar = RE->GetFarPlaneDist();
    FX_AdjustCamera(refdef, zfar);
}

/* line 1247 */
void CL_CapTurnRate(float maxPitchSpeed, float maxYawSpeed)
{
    char *cl = CL_LOCAL;
    *(float *)(cl + 0x8608) = maxPitchSpeed;
    *(float *)(cl + 0x860c) = maxYawSpeed;
}

/* line 1285 */
void LoadWorld(const char *mapname)
{
    RE->LoadWorld(mapname, 0);
    Com_UnloadBsp();
}

/* line 1306 */
void CL_UpdateLevelHunkUsage(void)
{
    int handle;
    int len;
    int memusage;
    char *buf;
    char *outbuf;
    const char *buftrav;
    const char *token;
    char outstr[256];
    int buflen;

    memusage = Hunk_Used();

    len = FS_FOpenFileByMode("hunkusage.dat", &handle, 0);
    if (len < 0)
        goto write_new;

    buflen = len + 1;
    buf = (char *)Z_MallocInternal(buflen);
    memset(buf, 0, buflen);
    outbuf = (char *)Z_MallocInternal(buflen);
    memset(outbuf, 0, buflen);

    FS_Read(buf, len, handle);
    FS_FCloseFile(handle);

    buftrav = buf;
    outbuf[0] = '\0';

    while (1) {
        token = Com_Parse(&buftrav);
        if (!token || *token == '\0')
            break;

        /* Check if this is our map */
        {
            char *cl = CL_LOCAL;
            if (I_stricmp(token, cl + 0x8590) == 0) {
                token = Com_Parse(&buftrav);
                if (!token || *token == '\0')
                    continue;
                if (memusage == atoi(token)) {
                    Z_FreeInternal(buf);
                    Z_FreeInternal(outbuf);
                    goto write_new;
                }
                continue;
            }
        }

        /* Copy non-matching entries to output */
        I_strncat(outbuf, token, buflen);
        I_strncat(outbuf, " ", buflen);

        token = Com_Parse(&buftrav);
        if (!token || *token == '\0') {
            Com_Error(ERR_DROP, "CL_UpdateLevelHunkUsage: bad hunkusage.dat");
            continue;
        }

        I_strncat(outbuf, token, buflen);
        I_strncat(outbuf, "\n", buflen);
    }

    /* Write updated file */
    handle = FS_FOpenFileWrite("hunkusage.dat");
    if (!handle) {
        Com_Error(ERR_DROP, va("EXE_ERR_CANT_CREATE%s", "hunkusage.dat"));
    }

    {
        int outLen = strlen(outbuf);
        if (FS_Write(outbuf, outLen, handle) != outLen) {
            Com_Error(ERR_DROP, va("EXE_ERR_CANT_WRITE%s", "hunkusage.dat"));
        }
    }
    FS_FCloseFile(handle);

    Z_FreeInternal(buf);
    Z_FreeInternal(outbuf);

write_new:
    /* Append our entry */
    len = FS_FOpenFileByMode("hunkusage.dat", &handle, 2);
    if (!handle) {
        Com_Error(ERR_DROP, "CL_UpdateLevelHunkUsage: cannot open for append");
    }

    {
        char *cl = CL_LOCAL;
        Com_sprintf(outstr, 256, "%s %i\n", cl + 0x8590, memusage);
    }
    FS_Write(outstr, strlen(outstr), handle);
    FS_FCloseFile(handle);

    /* Verify file is readable */
    len = FS_FOpenFileByMode("hunkusage.dat", &handle, 0);
    if (len >= 0) {
        FS_FCloseFile(handle);
    }
}

/* line 1411 */
void CL_StartLoading(const char *mapname, const char *gametype)
{
    char *ptr = *(char **)*(void **)imp_legacyHacks;
    if (*(int *)(ptr + 4) == 0)
        return;
    CL_StartHunkUsers();
    SCR_UpdateScreenInternal();
}

/* line 1426 */
void CL_InitCGame(void)
{
    int t1;
    char mapname[64];
    char *cl;

    t1 = Sys_Milliseconds();
    Con_Close();

    cl = CL_LOCAL;
    {
        int offset = *(int *)(cl + 0x270c);
        const char *systemInfo = cl + 0x470c + offset;
        I_strncpyz(mapname, Info_ValueForKey(systemInfo, "mapname"), 64);
    }

    {
        const char *ext = GetBspExtension();
        Com_sprintf(cl + 0x8590, 64, "maps/mp/%s.%s", mapname, ext);
    }

    if (!*(unsigned char *)(*(char **)*(void **)imp_com_sv_running + 8)) {
        Com_InitDObj();
        CL_SetExpectedHunkUsage(cl + 0x8590);
    }

    {
        char *clui = CLUI_STATE;
        *(int *)clui = 6;
        *(unsigned char *)(cl + 0xa) = 1;
        CG_Init(*(int *)(clui + 8), *(int *)(clui + 0x20140), *(int *)(clui + 0x20138));
        *(unsigned char *)(cl + 9) = 1;
        *(int *)clui = 7;
    }

    {
        int t2 = Sys_Milliseconds();
        double elapsed = (double)(t2 - t1) / 1000.0;
        Com_Printf("CL_InitCGame: %5.2f seconds\n", elapsed);
    }

    RE->EndRegistration();
    Com_TouchMemory();
    Con_ClearNotify();
    Con_ClearSubtitles();
    CL_UpdateLevelHunkUsage();
}

/* line 1528 */
qboolean CL_GameCommand(void)
{
    char *cl = CL_LOCAL;
    if (!*(unsigned char *)(cl + 9))
        return 0;
    return CG_ConsoleCommand();
}

/* line 1561 */
void CL_AdjustTimeDelta(void)
{
    char *cl;
    char *clui;
    int serverTime, frameTime, newDelta, serverTimeDelta, deltaDiff;

    cl = CL_LOCAL;
    *(int *)(cl + 0x2708) = 0;

    clui = CLUI_STATE;
    if (*(int *)(clui + 0x407a0))
        return;

    serverTime = *(int *)(cl + 0x20);
    frameTime = serverTime - *(int *)(cl + 0x2700);

    {
        char *cls = CLS;
        newDelta = serverTime - *(int *)(cls + 0x118) - frameTime - 5;
    }
    serverTimeDelta = *(int *)(cl + 0x26fc);
    deltaDiff = newDelta - serverTimeDelta;

    if (deltaDiff > 0) {
        if (frameTime <= 500) {
            deltaDiff -= frameTime;
            if (deltaDiff < 0)
                goto smooth;
        }
    } else {
        deltaDiff = -deltaDiff;
    }

    /* Check for big time jump */
    if (deltaDiff > 500) {
        *(int *)(cl + 0x26fc) = newDelta;
        cl = CL_LOCAL;
        *(int *)(cl + 0x26f4) = *(int *)(cl + 0x20);
        *(int *)(cl + 0x26f0) = *(int *)(cl + 0x20);
        {
            char *debugCvar = *(char **)*(void **)imp_cl_showTimeDelta;
            if (*(unsigned char *)(debugCvar + 8)) {
                Com_Printf("cl_showTimeDelta: reset\n");
            }
        }
        goto debug_print;
    }

    if (deltaDiff > 100) {
        /* Average the delta */
        {
            char *debugCvar = *(char **)*(void **)imp_cl_showTimeDelta;
            if (*(unsigned char *)(debugCvar + 8)) {
                Com_Printf("cl_showTimeDelta: average\n");
            }
        }
        cl = CL_LOCAL;
        *(int *)(cl + 0x26fc) = (newDelta + *(int *)(cl + 0x26fc)) >> 1;
        goto debug_print;
    }

smooth:
    {
        float timescale = *(float *)*(void **)imp_com_timescaleValue;
        if (timescale != 1.0f)
            goto debug_print;
    }

    if (*(int *)(cl + 0x2704)) {
        *(int *)(cl + 0x2704) = 0;
        cl = CL_LOCAL;
        *(int *)(cl + 0x26fc) -= 2;
    } else if (newDelta > serverTimeDelta) {
        *(int *)(cl + 0x26fc) = serverTimeDelta + 1;
    } else if (newDelta < serverTimeDelta) {
        *(int *)(cl + 0x26fc) = serverTimeDelta - 1;
    }

debug_print:
    {
        char *debugCvar = *(char **)*(void **)imp_cl_showTimeDelta;
        if (*(unsigned char *)(debugCvar + 8)) {
            cl = CL_LOCAL;
            {
                char *cls = CLS;
                Com_Printf("client time: %i, server time: %i\n",
                    *(int *)(cls + 0x118) + *(int *)(cl + 0x26fc),
                    *(int *)(cl + 0x20));
            }
            Com_Printf("snapshot delta: %i, time delta: %i\n",
                newDelta, *(int *)(cl + 0x26fc));
        }
    }
}

/* line 1876 */
void CL_SetADS(int ads)
{
    char *cl = CL_LOCAL;
    *(unsigned char *)(cl + 0xb) = (unsigned char)ads;
}

/* line 1888 */
void CL_DrawString(int x, int y, const char *pszString, qboolean bShadow, int iCharHeight)
{
    char *cl = CL_LOCAL;
    if (!*(unsigned char *)(cl + 9))
        return;
    CG_DrawStringExt((float)x, (float)y, pszString, 0, 0, bShadow, (float)iCharHeight, 1);
}

/* line 1897 */
void CL_ArchiveClientState(MemoryFile *memFile)
{
    CG_ArchiveState(memFile);
    RE->ArchiveFogState(memFile);
}

/* line 1968 */
void CL_SetLodOrigin(const refdef_t *fd)
{
    RE->SetLodOrigin(fd);
}

/* line 1909 */
void CL_LookupColor(int c, vec_t *color)
{
    unsigned char idx = ColorIndex((unsigned char)c);
    float *src;

    if (idx <= 7) {
        src = (float *)&g_color_table[idx];
    } else if ((unsigned char)c == '8') {
        src = (float *)(CL_LOCAL + 0x862c);
    } else if ((unsigned char)c == '9') {
        src = (float *)(CL_LOCAL + 0x863c);
    } else {
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        return;
    }

    color[0] = src[0];
    color[1] = src[1];
    color[2] = src[2];
    color[3] = src[3];
}

/* line 247 */
void CL_SetUserCmdAimValues(vec_t *kickAngles)
{
    char *cl = CL_LOCAL;
    *(float *)(cl + 0x8610) = kickAngles[0];
    *(float *)(cl + 0x8614) = kickAngles[1];
    *(float *)(cl + 0x8618) = kickAngles[2];
}

/* line 1954 */
void CL_UpdateColor(void)
{
    char *cl = CL_LOCAL;
    float *alliesColor = (float *)(cl + 0x862c);
    float *axisColor = (float *)(cl + 0x863c);

    Dvar_GetUnpackedColorByName("g_TeamColor_Allies", alliesColor);
    alliesColor[3] = 1.0f;

    Dvar_GetUnpackedColorByName("g_TeamColor_Axis", axisColor);
    axisColor[3] = 1.0f;

    RE->UpdateColor(alliesColor, axisColor);
}

/* line 964 */
void CL_SetFullScreenViewport(void)
{
    char *cls = CLS;
    int width = *(int *)(cls + 0x2a0a64);
    int height = *(int *)(cls + 0x2a0a68);

    RE->SetViewport(0, 0, width, height);
    SetScreenScaling(1.0f, 1.0f, 0, 0, width, height);
}

/* line 1007 */
void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s1, float t1, float s2, float t2, const vec_t *color, MaterialHandle material)
{
    CalcScreenPlacement(&x, &y, &w, &h, horzAlign, vertAlign);
    RE->DrawStretchPic(x, y, w, h, s1, t1, s2, t2, color, material);
}

/* line 1272 */
void CL_SyncTimes(void)
{
    char *clui = CLUI_STATE;
    if (*(int *)clui != 8)
        return;

    {
        char *cl = CL_LOCAL;
        if (*(unsigned char *)(cl + 0x1c) & 2)
            return;
    }

    CL_FirstSnapshot();
}

/* line 1743 */
void CL_SetCGameTime(void)
{
    char *clui;
    char *cl;
    int state;

    clui = CLUI_STATE;
    state = *(int *)clui;

    if (state != 8 && state != 7)
        return;

    if (state == 7) {
        /* CA_PRIMED */
        if (*(int *)(clui + 0x407a0)) {
            /* Demo playing */
            if (!*(int *)(clui + 0x407ac)) {
                *(int *)(clui + 0x407ac) = 1;
                return;
            }
            CL_ReadDemoMessage();
        }

        cl = CL_LOCAL;
        if (*(int *)(cl + 0x2708)) {
            *(int *)(cl + 0x2708) = 0;
            if (!(*(unsigned char *)(cl + 0x1c) & 2)) {
                CL_FirstSnapshot();
            }
        }

        clui = CLUI_STATE;
        if (*(int *)clui != 8)
            return;
    }

    /* CA_ACTIVE */
    cl = CL_LOCAL;
    if (!*(int *)(cl + 0x18)) {
        Com_Error(ERR_DROP, "CL_SetCGameTime: no snapshot");
    }

    /* Check sv_paused / loading */
    {
        char *tsCvar = *(char **)*(void **)imp_sv_paused;
        if (*(int *)(tsCvar + 8)) {
            char *loadCvar = *(char **)*(void **)imp_cl_paused;
            if (*(int *)(loadCvar + 8)) {
                char *rendCvar = *(char **)*(void **)imp_com_sv_running;
                if (*(unsigned char *)(rendCvar + 8))
                    return;
            }
        }
    }

    cl = CL_LOCAL;
    {
        int serverTime = *(int *)(cl + 0x20);
        if (serverTime < *(int *)(cl + 0x26f8)) {
            char *cls = CLS;
            if (I_stricmp((char *)(cls + 8), "localhost") != 0) {
                Com_Error(ERR_DROP, "cl.snap.serverTime < cl.oldFrameServerTime");
            }
            /* Reset via CL_FirstSnapshot */
            if (!(*(unsigned char *)(cl + 0x1c) & 2)) {
                CL_FirstSnapshot();
            }
        }
    }

    cl = CL_LOCAL;
    {
        int serverTime = *(int *)(cl + 0x20);
        *(int *)(cl + 0x26f8) = serverTime;
    }

    clui = CLUI_STATE;
    {
        int demoPlaying = *(int *)(clui + 0x407a0);
        char *cls = CLS;

        if (!demoPlaying || !*(unsigned char *)(*(char **)*(void **)imp_cl_freezeDemo + 8)) {
            /* Live game or not timedemo */
            int timeDelta = *(int *)(cl + 0x26fc);
            int realtime = *(int *)(cls + 0x118);
            *(int *)(cl + 0x26f0) = realtime + timeDelta;

            int oldServerTime = *(int *)(cl + 0x26f4);
            if (*(int *)(cl + 0x26f0) < oldServerTime) {
                *(int *)(cl + 0x26f0) = oldServerTime;
            }
            *(int *)(cl + 0x26f4) = *(int *)(cl + 0x26f0);

            int serverTime = *(int *)(cl + 0x20);
            if (timeDelta + realtime < serverTime - 5) {
                *(int *)(cl + 0x2704) = 1;
                {
                    char *debugCvar = *(char **)*(void **)imp_cl_showTimeDelta;
                    if (*(unsigned char *)(debugCvar + 8)) {
                        Com_Printf("%.6f extrapolating\n");
                    }
                }
            }
        } else {
            /* Timedemo mode */
            if (!*(int *)(clui + 0x407b4)) {
                /* Open timedemo CSV file */
                char *mapPath = cl + 0x8590;
                char *base = mapPath;
                char *dotPos = 0;
                while (*mapPath) {
                    if (*mapPath == '/' || *mapPath == '\\') {
                        base = mapPath + 1;
                        dotPos = 0;
                    } else if (*mapPath == '.') {
                        dotPos = mapPath;
                    }
                    mapPath++;
                }
                {
                    const char *name;
                    if (dotPos) {
                        name = va("%s", base);
                        ((char *)name)[dotPos - base] = '\0';
                    } else {
                        name = base;
                    }
                    int mode = Dvar_GetInt("cl_timedemoMode");
                    *(int *)(clui + 0x407b4) = FS_FOpenFileWrite(va("demos/timedemo_%s_mode_%i.csv", name, mode));
                }
            }

            {
                int msec = Sys_Milliseconds();
                clui = CLUI_STATE;
                if (!*(int *)(clui + 0x407bc)) {
                    *(int *)(clui + 0x407bc) = msec;
                } else if (*(int *)(clui + 0x407b4)) {
                    FS_Printf(*(int *)(clui + 0x407b4), "%i,%i\n",
                        *(int *)(clui + 0x407b8),
                        msec - *(int *)(clui + 0x407c0));
                }
                *(int *)(clui + 0x407c0) = msec;
                int frameNum = *(int *)(clui + 0x407b8) + 1;
                *(int *)(clui + 0x407b8) = frameNum;
                cl = CL_LOCAL;
                *(int *)(cl + 0x26f0) = *(int *)(clui + 0x407c4) + frameNum * 50;
            }
        }
    }

    cl = CL_LOCAL;
    /* Check newSnapshots and adjust time delta */
    if (*(int *)(cl + 0x2708)) {
        CL_AdjustTimeDelta();
    }

    clui = CLUI_STATE;
    if (!*(int *)(clui + 0x407a0))
        return;

    /* Demo playback: advance snapshots */
    if (!*(int *)(clui + 0x407a4)) {
        cl = CL_LOCAL;
    } else {
        cl = CL_LOCAL;
    }

    while (*(int *)(cl + 0x26f0) >= *(int *)(cl + 0x20)) {
        CL_ReadDemoMessage();
        clui = CLUI_STATE;
        if (*(int *)clui != 8)
            return;
        cl = CL_LOCAL;
    }
}
