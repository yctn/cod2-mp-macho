/* ASM dump from: ui_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui_mp/ui_main_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

void diag_drawtext(const char *text, void *font, float x, float y, float scale) {
    (void)text;
    (void)font;
    (void)x;
    (void)y;
    (void)scale;
}

extern const char *va(const char *fmt, ...);
extern const dvar_t *ui_smallFont; /* 0x0 */
extern const dvar_t *ui_bigFont; /* 0x0 */
extern const dvar_t *ui_extraBigFont; /* 0x0 */
extern const dvar_t *ui_netSource; /* 0x0 */
extern const dvar_t *ui_currentMap; /* 0x0 */
extern const dvar_t *ui_netGameType; /* 0x0 */
extern const dvar_t *ui_joinGameType; /* 0x0 */
extern const dvar_t *ui_dedicated; /* 0x0 */
extern const dvar_t *ui_currentNetMap; /* 0x0 */
extern const dvar_t *ui_browserShowFull; /* 0x0 */
extern const dvar_t *ui_browserShowEmpty; /* 0x0 */
extern const dvar_t *ui_browserShowPassword; /* 0x0 */
extern const dvar_t *ui_browserShowNoPassword; /* 0x0 */
extern const dvar_t *ui_browserShowPure; /* 0x0 */
extern const dvar_t *ui_browserFriendlyfire; /* 0x0 */
extern const dvar_t *ui_browserKillcam; /* 0x0 */
extern const dvar_t *ui_serverStatusTimeOut; /* 0x0 */
extern struct sharedUiInfo_t sharedUiInfo; /* 0x0 */
extern uiInfo_t *uiInfo; /* 0x0 */
extern uiInfo_t uiInfoArray[1]; /* 0x0 */
extern const dvar_t *ui_gametype; /* 0x0 */
extern const dvar_t *ui_netGameTypeName; /* 0x0 */
extern const dvar_t *ui_browserShowDedicated; /* 0x0 */
extern const dvar_t *ui_browserMod; /* 0x0 */
extern const dvar_t *ui_playerProfileCount; /* 0x0 */
extern const dvar_t *ui_playerProfileSelected; /* 0x0 */
extern const dvar_t *ui_playerProfileNameNew; /* 0x0 */
extern serverStatusDvar_t serverStatusDvars[23]; /* 0x0 */
static char errorString[1024]; /* errorString */
static char info[1024]; /* info */
static qboolean bypassKeyClear; /* bypassKeyClear */
static int numclean; /* numclean */
static char info_00ecf960[1024]; /* info */
static char clientBuff[32]; /* clientBuff */
extern int lastColumn; /* lastColumn */
static int lastTime; /* lastTime */
static char info_00ecf960[1024]; /* info */
static char info_00ecf960[1024]; /* info */
static char info_00ecf960[1024]; /* info */
static int numFound; /* numFound */
static int numTimeOuts; /* numTimeOuts */
extern char dlText[16]; /* dlText */
extern char etaText[18]; /* etaText */
extern char xferText[15]; /* xferText */
extern int tleEstimates[80]; /* tleEstimates */
static int tleIndex; /* tleIndex */
static char g_mapname[64]; /* g_mapname */
static char g_gametype[64]; /* g_gametype */
static Bool g_ingameMenusLoaded; /* g_ingameMenusLoaded */
extern const char * MonthAbbrev[12]; /* MonthAbbrev */
extern const char * netSources[3]; /* netSources */
static const serverFilter_t serverFilters[1]; /* serverFilters */
static char menuBuf2[32768]; /* menuBuf2 */
static int ui_serverFilterType; /* ui_serverFilterType */

extern void Menus_CloseAll(uiInfo_t *info);
extern qboolean Menus_AnyFullScreenVisible(uiInfo_t *info);
extern void LAN_SaveServersToCache(void);
extern void Menus_OpenByName(uiInfo_t *info, const char *name);
extern void Menus_CloseByName(uiInfo_t *info, const char *name);
extern const char *Cmd_Args(int startIndex);

/* Forward declarations for functions called from converted ASM */
extern int CL_RegisterMaterialNoMip(const char *name, int flags);
extern int CL_RegisterFont(const char *name, int flags);
extern int Com_FindSoundAlias(const char *name);
extern void CL_DrawStretchPic(float x, float y, float w, float h, int horzAlign, int vertAlign, float s0, float t0, float s1, float t1, const vec_t *color, MaterialHandle material);
extern float CL_NormalizedTextScale(FontHandle font, float scale);
extern int CL_TextWidth(const char *text, int maxChars, FontHandle font);
extern int CL_TextHeight(FontHandle font);
extern float GetRealHeightFromVirtualHeight(float scale);
extern void CalcScreenPlacement(float *x, float *y, float *xScale, float *yScale, int horzAlign, int vertAlign);
extern void CalcSplitScreenTextOffset(FontHandle font, float *y);
extern void CL_DrawTextPhysical(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, int style, const vec_t *color, int textStyle);
extern void CL_DrawTextPhysicalWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, float xScale, float yScale, int style, const vec_t *color, int textStyle, int cursorPos, int cursor);
extern void GetClientState(void *cstate);
extern const char *CL_GetConfigString(int index);
extern const char *Info_ValueForKey(const char *s, const char *key);
extern int GetClientname(int index, char *name, int nameSize);
extern void I_strncpyz(char *dest, const char *src, int len);
extern void I_CleanStr(char *str);
extern int I_stricmp(const char *s1, const char *s2);
extern int I_strnicmp(const char *s1, const char *s2, int n);
extern void I_strncat(char *dest, const char *src, int len);
extern int FS_FOpenFileByMode(const char *name, int *f, int mode);
extern int FS_Read(void *buf, int len, int f);
extern void FS_FCloseFile(int f);
extern void Com_Printf(const char *fmt, ...);
extern int UI_LoadMenu(const char *name, int imageTrack);
extern void UI_AddMenuList(uiInfo_t *info, int menuList);
extern void UI_MapLoadInfo(const char *csv);
extern void UI_FillRect(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color);
extern void *Menus_FindByName(uiInfo_t *info, const char *name);
extern void Menu_Paint(uiInfo_t *info, void *menu, int full);
extern void Dvar_SetInt(const void *dvar, int value);
extern void Dvar_SetString(const void *dvar, const char *value);
extern void Dvar_SetIntByName(const char *name, int value);
extern void Dvar_SetBoolByName(const char *name, int value);
extern void Dvar_SetStringByName(const char *name, const char *value);
extern int Dvar_GetInt(const char *name);
extern int Dvar_GetBool(const char *name);
extern float Dvar_GetFloat(const char *name);
extern const char *Dvar_GetString(const char *name);
extern const char *Dvar_GetVariantString(const char *name);
extern void Dvar_SetFloatByName(const char *name, float value);
extern void Dvar_SetFromStringByNameFromSource(const char *name, const char *value, int source);
extern const void *Dvar_FindVar(const char *name);
extern int SEH_VerifyLanguageSelection(int lang);
extern const char *SEH_StringEd_GetString(const char *ref);
extern void Com_Error(int level, const char *fmt, ...);
extern int String_Parse(const char **args, char *buf, int bufSize);
extern int LAN_GetServerStatus(const char *addr, char *info, int infoSize);
extern int LAN_AddServer(int source, const char *name, const char *addr);
extern void LAN_GetServerInfo(int source, int index, char *info, int infoSize);
extern int LAN_GetServerCount(int source);
extern void LAN_ResetPings(int source);
extern int LAN_WaitServerResponse(int source);
extern int LAN_CompareServers(int source, int sortKey, int sortDir, int s1, int s2);
extern int LAN_ServerIsDirty(int source, int index);
extern int LAN_GetServerPing(int source, int index);
extern void LAN_MarkServerDirty(int source, int index, int dirty);
extern int LAN_UpdateDirtyPings(int source);
extern void LAN_GetServerAddressString(int source, int index, char *addr, int addrSize);
extern void LAN_RemoveServer(int source, const char *addr);
extern void LAN_LoadCachedServers(void);
extern void CIN_StopCinematic(int handle);
extern int CIN_PlayCinematic(const char *name, int x, int y, int w, int h, int flags);
extern void CIN_RunCinematic(int handle);
extern void CIN_SetExtents(int handle, int x, int y, int w, int h);
extern void CIN_DrawCinematic(int handle);
extern void UI_DrawHandlePic(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color, int material);
extern void Key_SetCatcher(int catcher);
extern int Key_GetCatcher(void);
extern void Key_ClearStates(void);
extern int Menu_Count(uiInfo_t *info);
extern void *Menu_GetFocused(uiInfo_t *info);
extern void Menu_HandleKey(uiInfo_t *info, void *menu, int key, int down);
extern void Menu_PaintAll(uiInfo_t *info);
extern void Menu_SetFeederSelection(uiInfo_t *info, int feederID, int feederId2, int index, const char *name);
extern void Menu_Setup(uiInfo_t *info);
extern void Display_MouseMove(uiInfo_t *info, int flags, int x, int y);
extern int Display_KeyBindPending(void);
extern void SND_FadeAllSounds(float gain, int time);
extern int Sys_Milliseconds(void);
extern float Voice_GetVoiceLevel(void);
extern void Com_RealTime(void *q);
extern int FS_GetFileList(const char *path, const char *ext, int flags, char *buf, int bufSize);
extern const char *Com_Parse(const char **buf);
extern const char *String_Alloc(const char *s);
extern void String_Init(void);
extern void CL_GetScreenDimensions(int *w, int *h, int *aspect);
extern const void *Dvar_RegisterInt(const char *name, int value, int min, int max, int flags);
extern const void *Dvar_RegisterFloat(const char *name, float value, float min, float max, int flags);
extern const void *Dvar_RegisterBool_mac(const char *name, int value, int flags);
extern const void *Dvar_RegisterString_mac(const char *name, const char *value, int flags);
extern void UI_LoadArenas(void);
extern int UI_LoadMenus(const char *name, int imageTrack);
extern void UI_LoadSoundAliases(void);
extern void Controls_SetDefaults(void);
extern void Controls_GetConfig(void);
extern void Controls_SetConfig(int apply);
extern void CG_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, float special, int font, float scale, vec_t *color, int material, int textStyle);
extern const char *CG_GameTypeString(void);
extern const char *CG_GetKillerText(void);
extern const char *SEH_LocalizeTextMessage(const char *msg, const char *fmt, const char *ctx);
extern void LerpColor(const vec_t *a, const vec_t *b, vec_t *c, float t);
extern void Item_SetCursorPos(void *item, int pos);
extern int Item_ListBox_MaxScroll(void *item);
extern void ListBox_SetStartPos(void *listPtr, int pos);
extern void ListBox_SetEndPos(void *listPtr, int pos);
extern void ListBox_SetCursorPos(void *listPtr, int pos);
extern int CL_IsPlayerTalking(int index);
extern int CL_IsPlayerMuted(int index);
extern void CL_MutePlayer(int index);
extern int Int_Parse(const char **args, int *out);
extern void CLUI_GetCDKey(char *buf, int bufSize, int part);
extern void CLUI_SetCDKey(const char *key, int part);
extern int CL_CDKeyValidate(const char *key1, const char *key2);
extern void CG_DrawInformation(int loading);
extern char *FS_ListFiles(const char *path, const char *ext, int flags, int *numFiles);
extern void FS_FreeFileList(char **list);
extern void I_strupr(char *str);
extern void Com_ChangePlayerProfile(int index);
extern void Com_DeletePlayerProfile(int index);
extern int Com_NewPlayerProfile(const char *name);
/* snprintf already declared in stdio.h */
extern void Cbuf_ExecuteText(int execWhen, const char *text);
extern void Com_sprintf(char *buf, int size, const char *fmt, ...);
extern int ___toupper(int c);
extern int ___tolower(int c);

void UI_AssetCache(void);
void UI_DrawSides(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color);
void UI_DrawTopBottom(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color);
int UI_TextWidth(const char *text, int maxChars, FontHandle font, float scale);
int UI_TextHeight(FontHandle font, float scale);
FontHandle UI_GetFontHandle(int fontEnum, float scale);
void UI_UpdateTime(int realtime);
void UI_Shutdown(void);
char * GetMenuBuffer(const char *filename);
qboolean Load_ScriptMenu(const char *pszMenu, int imageTrack);
static void UI_DrawMapPreview(void);
const char * UI_GetMapDisplayName(const char *pszMap);
const char * UI_GetMapDisplayNameFromPartialLoadNameMatch(const char *pszMap, int *mapLoadNameLen);
const char * UI_GetGameTypeDisplayName(const char *pszGameType);
static void UI_BuildPlayerList(void);
void UI_DrawMapLevelshot(void);
void UI_LoadIngameMenus(void);
void UI_SetMap(const char *mapname, const char *gametype);
qboolean UI_OwnerDrawVisible(int flags);
static int UI_ServersQsortCompare(const void *arg1, const void *arg2);
static int UI_PlayerProfilesQsortCompare(const void *arg1, const void *arg2);
static void UI_SelectCurrentMap(void);
qboolean UI_CheckExecKey(int key);
static void UI_VerifyLanguage(void);
const char * UI_SafeTranslateString(const char *reference);
static void UI_AddServerToFavoritesList(const char * *p, const char * *out);
static Bool UI_GetOpenOrCloseMenuOnDvarArgs(char *testValue, char *menuName);
static int UI_GetServerStatusInfo(serverStatusInfo_t *info);
void UI_FeederSelection(float feederID, int index);
static void UI_GetGameTypesList(void);
void UI_Pause(qboolean b);
void UI_OpenMenu_f(void);
void UI_CloseMenu_f(void);
void UI_Init(void);
void UI_KeyEvent(int key, qboolean down);
void UI_MouseEvent(int dx, int dy);
uiMenuCommand_t UI_GetActiveMenu(void);
qboolean UI_SetActiveMenu(int menu);
qboolean UI_IsFullscreen(void);
static void UI_ReadableSize(char *buf);
float UI_GetBlurRadius(void);
qboolean UI_AnyFullScreenMenuVisible(void);
const char * UI_ReplaceConversions(const char *sourceString, ConversionArguments *arguments);
const char * UI_ReplaceConversionString(const char *sourceString, const char *replaceString);
void UI_CloseAll(void);
void UI_CloseFocusedMenu(void);
void UI_OverrideCursorPos(rectDef_t (*item)[16]);
Bool UI_DrawRecordLevel(rectDef_t *rect);
MaterialHandle UI_FeederItemImage(const float feederID, int index);
void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style);
void UI_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style, int cursorPos, int cursor);
static void UI_StartServerRefresh(qboolean full);
static void UI_BuildServerDisplayList(qboolean force);
qboolean UI_OwnerDrawHandleKey(int ownerDraw, int flags, float *special, int key);
const char * UI_FeederItemText(float feederID, int index, int column, MaterialHandle *handle);
void UI_DrawRect(float x, float y, float width, float height, int horzAlign, int vertAlign, float size, const vec_t *color);
int UI_OwnerDrawWidth(int ownerDraw, FontHandle font, float scale);
void UI_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, float special, FontHandle font, float scale, vec_t *color, MaterialHandle material, int textStyle);
static void UI_BuildFindPlayerList(void);
static void UI_BuildServerStatus(void);
void UI_Refresh(void);
void UI_RunMenuScript(const char * *args);
int UI_FeederCount(float feederID);
static void UI_DisplayDownloadInfo(const char *downloadName, float centerPoint, float yStart, FontHandle font, float scale);
void UI_DrawConnectScreen(void);

/* line 323 */
void UI_AssetCache(void)
{
    *(int *)((char *)&sharedUiInfo + 32) = CL_RegisterMaterialNoMip("white", 3);
    *(int *)((char *)&sharedUiInfo + 16) = CL_RegisterMaterialNoMip("ui/assets/scrollbar.tga", 3);
    *(int *)((char *)&sharedUiInfo + 4) = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_dwn_a.tga", 3);
    *(int *)((char *)&sharedUiInfo + 0) = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_up_a.tga", 3);
    *(int *)((char *)&sharedUiInfo + 8) = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_left.tga", 3);
    *(int *)((char *)&sharedUiInfo + 12) = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_right.tga", 3);
    *(int *)((char *)&sharedUiInfo + 20) = CL_RegisterMaterialNoMip("ui/assets/scrollbar_thumb.tga", 3);
    *(int *)((char *)&sharedUiInfo + 24) = CL_RegisterMaterialNoMip("ui/assets/slider2.tga", 3);
    *(int *)((char *)&sharedUiInfo + 28) = CL_RegisterMaterialNoMip("ui/assets/sliderbutt_1", 3);
    *(int *)((char *)&sharedUiInfo + 36) = CL_RegisterMaterialNoMip("$cursor", 0);
    *(int *)((char *)&sharedUiInfo + 40) = CL_RegisterFont("$bigfont", 0);
    *(int *)((char *)&sharedUiInfo + 44) = CL_RegisterFont("$smallfont", 0);
    *(int *)((char *)&sharedUiInfo + 48) = CL_RegisterFont("$consolefont", 0);
    *(int *)((char *)&sharedUiInfo + 52) = CL_RegisterFont("$boldfont", 0);
    *(int *)((char *)&sharedUiInfo + 56) = CL_RegisterFont("$font", 0);
    *(int *)((char *)&sharedUiInfo + 60) = CL_RegisterFont("$extrabigfont", 0);
    *(int *)((char *)&sharedUiInfo + 64) = Com_FindSoundAlias("ui_mp_map_select");
}

/* line 347 */
void UI_DrawSides(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    MaterialHandle white = *(MaterialHandle *)((char *)&sharedUiInfo + 32);
    CL_DrawStretchPic(x, y, size, h, horzAlign, vertAlign, 0, 0, 0, 0, color, white);
    CL_DrawStretchPic(x + w - size, y, size, h, horzAlign, vertAlign, 0, 0, 0, 0, color, white);
}

/* line 354 */
void UI_DrawTopBottom(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    MaterialHandle white = *(MaterialHandle *)((char *)&sharedUiInfo + 32);
    CL_DrawStretchPic(x, y, w, size, horzAlign, vertAlign, 0, 0, 0, 0, color, white);
    CL_DrawStretchPic(x, y + h - size, w, size, horzAlign, vertAlign, 0, 0, 0, 0, color, white);
}

/* line 375 */
int UI_TextWidth(const char *text, int maxChars, FontHandle font, float scale)
{
    float actualScale = CL_NormalizedTextScale(font, scale);
    return (int)((float)CL_TextWidth(text, maxChars, font) * actualScale);
}

/* line 384 */
int UI_TextHeight(FontHandle font, float scale)
{
    float actualScale = CL_NormalizedTextScale(font, scale);
    return (int)((float)CL_TextHeight(font) * actualScale);
}

/* line 434 */
FontHandle UI_GetFontHandle(int fontEnum, float scale)
{
    float realHeight;
    if (fontEnum == 2)
        return *(FontHandle *)((char *)&sharedUiInfo + 40); /* bigfont */
    if (fontEnum == 3)
        return *(FontHandle *)((char *)&sharedUiInfo + 44); /* smallfont */
    if (fontEnum == 5)
        return *(FontHandle *)((char *)&sharedUiInfo + 48); /* consolefont */

    realHeight = GetRealHeightFromVirtualHeight(scale);

    if (fontEnum == 4) {
        if (*(float *)((char *)ui_smallFont + 8) >= realHeight)
            return *(FontHandle *)((char *)&sharedUiInfo + 44); /* smallfont */
        if (*(float *)((char *)ui_bigFont + 8) >= realHeight)
            return *(FontHandle *)((char *)&sharedUiInfo + 52); /* boldfont */
        return *(FontHandle *)((char *)&sharedUiInfo + 56); /* font */
    }

    /* default path */
    if (*(float *)((char *)ui_smallFont + 8) >= realHeight)
        return *(FontHandle *)((char *)&sharedUiInfo + 44); /* smallfont */
    if (realHeight >= *(float *)((char *)ui_extraBigFont + 8))
        return *(FontHandle *)((char *)&sharedUiInfo + 60); /* extrabigfont */
    if (realHeight >= *(float *)((char *)ui_bigFont + 8))
        return *(FontHandle *)((char *)&sharedUiInfo + 40); /* bigfont */
    return *(FontHandle *)((char *)&sharedUiInfo + 56); /* font */
}

/* line 479 */
void UI_UpdateTime(int realtime)
{
    int *ui = (int *)uiInfo;
    int slot, sum, i;

    /* uiInfo->frametime = realtime - uiInfo->uiDC.realTime */
    ui[2] = realtime - ui[1];
    /* uiInfo->uiDC.realTime = realtime */
    ui[1] = realtime;

    /* slot = uiInfo->timeIndex & 3 (signed modulo) */
    slot = *(int *)((byte *)uiInfo + 0x488);
    slot = ((slot - 1) | ~3) + 1; /* handles negative: signed % 4 */
    if (slot < 0) slot = ((slot - 1) | (int)0xfffffffc) + 1;
    /* Actually the original just does: slot = uiInfo->timeIndex % 4, with sign handling */
    slot = *(int *)((byte *)uiInfo + 0x488) & 3;

    /* uiInfo->previousTimes[slot] = uiInfo->frametime */
    *(int *)((byte *)uiInfo + 0x48c + slot * 4) = ui[2];
    /* uiInfo->timeIndex++ */
    *(int *)((byte *)uiInfo + 0x488) += 1;

    if (*(int *)((byte *)uiInfo + 0x488) <= 4)
        return;

    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += *(int *)((byte *)uiInfo + 0x48c + i * 4);
    }
    if (sum == 0)
        *(float *)((byte *)uiInfo + 0x24) = (float)4000;
    else
        *(float *)((byte *)uiInfo + 0x24) = (float)(4000 / sum);
}

/* line 542 */
void UI_Shutdown(void)
{
    Menus_CloseAll(uiInfo);
    *(int *)((char *)&sharedUiInfo + 32) = 0;
    LAN_SaveServersToCache();
}

/* line 551 */
char * GetMenuBuffer(const char *filename)
{
    int f;
    int len;

    len = FS_FOpenFileByMode(filename, &f, 0);
    if (!f) {
        Com_Printf("^1menu file not found: %s, using default\n", filename);
        return 0;
    }
    if (len > 0x7fff) {
        Com_Printf("^1menu file too large: %s is %i, max allowed is %i", filename, len, 0x8000);
        FS_FCloseFile(f);
        return 0;
    }
    FS_Read(menuBuf2, len, f);
    menuBuf2[len] = 0;
    FS_FCloseFile(f);
    return menuBuf2;
}

/* line 615 */
qboolean Load_ScriptMenu(const char *pszMenu, int imageTrack)
{
    char szMenuFile[256];
    int menuList;

    /* "ui_mp/scriptmenus/" */
    szMenuFile[0] = 'u'; szMenuFile[1] = 'i'; szMenuFile[2] = '_'; szMenuFile[3] = 'm';
    szMenuFile[4] = 'p'; szMenuFile[5] = '/'; szMenuFile[6] = 's'; szMenuFile[7] = 'c';
    szMenuFile[8] = 'r'; szMenuFile[9] = 'i'; szMenuFile[10] = 'p'; szMenuFile[11] = 't';
    szMenuFile[12] = 'm'; szMenuFile[13] = 'e'; szMenuFile[14] = 'n'; szMenuFile[15] = 'u';
    szMenuFile[16] = 's'; szMenuFile[17] = '/'; szMenuFile[18] = 0;

    I_strncat(szMenuFile, pszMenu, 0x100);
    I_strncat(szMenuFile, ".menu", 0x100);

    menuList = UI_LoadMenu(szMenuFile, imageTrack);
    if (!menuList)
        return 0;

    UI_AddMenuList(uiInfo, menuList);
    return 1;
}

/* line 701 */
static __attribute__((naked))
void UI_DrawMapPreview(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 701 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl %eax, %ebx\n" /* rect */
        "movl %edx, %esi\n" /* color */
        /* { scope 1 */
        "testl %ecx, %ecx\n" /* line 703 | net */
        "je .Lf14f098_0014f14f\n"
        "movl ui_currentNetMap, %eax\n"
        "movl 8(%eax), %edx\n" /* map */
        ".Lf14f098_0014f0b4:\n"
        "testl %edx, %edx\n" /* line 705 */
        "js .Lf14f098_0014f10d\n"
        "cmpl sharedUiInfo+4944, %edx\n"
        "jge .Lf14f098_0014f10d\n"
        ".Lf14f098_0014f0c0:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 714 */
        "leal (%edx, %eax, 8), %eax\n"
        "movl sharedUiInfo+5104(, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14f098_0014f139\n"
        ".Lf14f098_0014f0d1:\n"
        "movl %eax, 0x1c(%esp)\n" /* line 720 */
        "movl %esi, 0x18(%esp)\n" /* color */
        "movl 0x14(%ebx), %eax\n" /* rect */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* rect */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* rect */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n" /* rect */
        "movl %eax, 8(%esp)\n"
        "movl 4(%ebx), %eax\n" /* rect */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 722 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f098_0014f10d:\n"
        "testl %ecx, %ecx\n" /* line 707 | net */
        "jne .Lf14f098_0014f15c\n"
        "movl $0, 4(%esp)\n" /* line 710 */
        "movl ui_currentMap, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "xorl %edx, %edx\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 714 */
        "leal (%edx, %eax, 8), %eax\n"
        "movl sharedUiInfo+5104(, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf14f098_0014f0d1\n"
        ".Lf14f098_0014f139:\n"
        "movl $3, 4(%esp)\n" /* line 720 */
        "movl $str_002aa05c, (%esp)\n" /* "menu/art/unknownmap" */
        "calll CL_RegisterMaterialNoMip\n"
        "jmp .Lf14f098_0014f0d1\n"
        ".Lf14f098_0014f14f:\n"
        "movl ui_currentMap, %eax\n" /* line 703 */
        "movl 8(%eax), %edx\n" /* map */
        "jmp .Lf14f098_0014f0b4\n"
        ".Lf14f098_0014f15c:\n"
        "movl $0, 4(%esp)\n" /* line 708 */
        "movl ui_currentNetMap, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "xorl %edx, %edx\n"
        "jmp .Lf14f098_0014f0c0\n"
    );
}

/* line 787 */
const char * UI_GetMapDisplayName(const char *pszMap)
{
    int i;
    int count = *(int *)((char *)&sharedUiInfo + 4944);
    for (i = 0; i < count; i++) {
        const char *loadName = *(const char **)((char *)&sharedUiInfo + 0x1358 + i * 0xa4);
        if (I_stricmp(pszMap, loadName) == 0) {
            return *(const char **)((char *)&sharedUiInfo + 4948 + i * 0xa4);
        }
    }
    return pszMap;
}

/* line 799 */
const char * UI_GetMapDisplayNameFromPartialLoadNameMatch(const char *pszMap, int *mapLoadNameLen)
{
    int i;
    int count = *(int *)((char *)&sharedUiInfo + 4944);
    for (i = 0; i < count; i++) {
        const char *loadName = *(const char **)((char *)&sharedUiInfo + 0x1358 + i * 0xa4);
        int len = strlen(loadName);
        *mapLoadNameLen = len;
        if (I_strnicmp(pszMap, loadName, len) == 0) {
            return *(const char **)((char *)&sharedUiInfo + 4948 + i * 0xa4);
        }
    }
    return 0;
}

/* line 816 */
const char * UI_GetGameTypeDisplayName(const char *pszGameType)
{
    int i;
    int count = *(int *)((char *)&sharedUiInfo + 4424);
    for (i = 0; i < count; i++) {
        const char *name = *(const char **)((char *)&sharedUiInfo + 0x114c + i * 8);
        if (I_stricmp(pszGameType, name) == 0) {
            return *(const char **)((char *)&sharedUiInfo + 4432 + i * 8);
        }
    }
    return pszGameType;
}

/* line 892 */
static __attribute__((naked))
void UI_BuildPlayerList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 892 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x84c, %esp\n"
        /* { scope 1 */
        "leal -0x844(%ebp), %eax\n" /* line 900 | cs */
        "movl %eax, (%esp)\n"
        "calll GetClientState\n"
        "movl $0, (%esp)\n" /* line 901 */
        "calll CL_GetConfigString\n"
        "movl $str_002a70dc, 4(%esp)\n" /* line 902 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %esi\n" /* count */
        "movl $0x100, 8(%esp)\n" /* line 903 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl $sharedUiInfo+4168, (%esp)\n"
        "calll memset\n"
        "movl $0, sharedUiInfo+68\n" /* line 904 */
        "testl %esi, %esi\n" /* line 905 | count */
        "jg .Lf14f2b6_0014f32b\n"
        /* } scope */
        ".Lf14f2b6_0014f320:\n"
        "addl $0x84c, %esp\n" /* line 915 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f2b6_0014f32b:\n"
        "xorl %ebx, %ebx\n" /* line 905 | n */
        "leal -0x38(%ebp), %edi\n" /* szName */
        "jmp .Lf14f2b6_0014f339\n"
        ".Lf14f2b6_0014f332:\n"
        "addl $1, %ebx\n" /* n */
        "cmpl %ebx, %esi\n" /* n, count */
        "je .Lf14f2b6_0014f320\n"
        ".Lf14f2b6_0014f339:\n"
        "movl $0x20, 8(%esp)\n" /* line 907 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* n */
        "calll GetClientname\n"
        "testl %eax, %eax\n"
        "je .Lf14f2b6_0014f332\n"
        "movl sharedUiInfo+68, %eax\n" /* line 909 */
        "movl %ebx, sharedUiInfo+4168(, %eax, 4)\n" /* n */
        "movl $0x20, 8(%esp)\n" /* line 910 */
        "movl %edi, 4(%esp)\n"
        "shll $5, %eax\n"
        "addl $sharedUiInfo+72, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl sharedUiInfo+68, %eax\n" /* line 911 */
        "shll $5, %eax\n"
        "addl $sharedUiInfo+72, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_CleanStr\n"
        "addl $1, sharedUiInfo+68\n" /* line 912 */
        "jmp .Lf14f2b6_0014f332\n"
    );
}

/* UI_DrawMapLevelshot — draw map preview or black rect */
void UI_DrawMapLevelshot(void)
{
    if (g_mapname[0]) {
        void *menu = Menus_FindByName(uiInfo, "connect_levelshot");
        if (menu) {
            *(int *)((byte *)uiInfo + 0x28) = 0;
            Menu_Paint(uiInfo, menu, 1);
            return;
        }
    }
    /* No map — draw black rect (480x640) */
    UI_FillRect(0, 0, 640.0f, 480.0f, 0, 0, (const vec_t *)imp_colorBlack);
}

/* line 994 */
void UI_LoadIngameMenus(void)
{
    if (g_ingameMenusLoaded)
        return;
    g_ingameMenusLoaded = 1;
    UI_AddMenuList(uiInfo, UI_LoadMenus("ui_mp/ingame.txt", 3));
}

/* line 1007 */
void UI_SetMap(const char *mapname, const char *gametype)
{
    I_strncpyz(g_mapname, mapname, 0x40);
    I_strncpyz(g_gametype, gametype, 0x40);
    if (g_mapname[0]) {
        UI_MapLoadInfo(va("maps/mp/%s.csv", g_mapname));
    }
}

/* line 1275 */
qboolean UI_OwnerDrawVisible(int flags)
{
    qboolean visible = 1;

    if (flags & 4) {
        if (*(int *)((char *)ui_netSource + 8) != 2) {
            visible = 0;
        }
    }

    if (flags & 0x1000) {
        if (*(int *)((char *)ui_netSource + 8) == 2) {
            visible = 0;
        }
    }

    return visible;
}

/* line 1506 */
static int UI_ServersQsortCompare(const void *arg1, const void *arg2)
{
    int s1 = *(const int *)arg1;
    int s2 = *(const int *)arg2;
    return LAN_CompareServers(
        *(int *)((char *)ui_netSource + 8),
        *(int *)((char *)&sharedUiInfo + 28640),
        *(int *)((char *)&sharedUiInfo + 28644),
        s1, s2);
}

/* line 1591 */
static int UI_PlayerProfilesQsortCompare(const void *arg1, const void *arg2)
{
    int idx1 = *(const int *)arg1;
    int idx2 = *(const int *)arg2;
    int result;

    if (idx1 == idx2)
        return 0;

    result = I_stricmp(
        *(const char **)((byte *)uiInfo + 0x284 + idx1 * 4),
        *(const char **)((byte *)uiInfo + 0x284 + idx2 * 4));

    if (*(int *)((byte *)uiInfo + 0x384) == 0)
        result = -result;

    return result;
}

/* line 2656 */
static __attribute__((naked))
void UI_SelectCurrentMap(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2656 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x87c, %esp\n"
        /* { scope 1 */
        "leal -0x864(%ebp), %eax\n" /* line 2664 | cstate */
        "movl %eax, (%esp)\n"
        "calll GetClientState\n"
        "cmpl $8, -0x864(%ebp)\n" /* line 2666 | cstate */
        "je .Lf14f5a0_0014f5ce\n"
        /* } scope */
        ".Lf14f5a0_0014f5c3:\n"
        "addl $0x87c, %esp\n" /* line 2692 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f5a0_0014f5ce:\n"
        "movl $0, (%esp)\n" /* line 2669 */
        "calll CL_GetConfigString\n"
        "cmpb $0, (%eax)\n" /* line 2670 */
        "je .Lf14f5a0_0014f5c3\n"
        "movl $str_002a7124, 4(%esp)\n" /* line 2673 */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szMap */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl sharedUiInfo+4944, %eax\n" /* line 2676 */
        "testl %eax, %eax\n"
        "jle .Lf14f5a0_0014f5c3\n"
        "xorl %esi, %esi\n" /* i */
        "xorl %edi, %edi\n" /* iCount */
        "movl $sharedUiInfo, %ebx\n"
        "jmp .Lf14f5a0_0014f62b\n"
        ".Lf14f5a0_0014f61a:\n"
        "addl $1, %esi\n" /* i */
        "addl $0xa4, %ebx\n"
        "cmpl sharedUiInfo+4944, %esi\n" /* i */
        "jge .Lf14f5a0_0014f5c3\n"
        ".Lf14f5a0_0014f62b:\n"
        "movl 0x13f4(%ebx), %eax\n" /* line 2678 */
        "testl %eax, %eax\n"
        "je .Lf14f5a0_0014f61a\n"
        "movl 0x1354(%ebx), %eax\n" /* line 2680 */
        "movl %eax, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* szMap */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf14f5a0_0014f653\n"
        "addl $1, %edi\n" /* line 2689 | iCount */
        "jmp .Lf14f5a0_0014f61a\n"
        ".Lf14f5a0_0014f653:\n"
        "movl $str_002aa094, 0x10(%esp)\n" /* line 2682 */
        "movl %edi, 0xc(%esp)\n" /* iCount */
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "jmp .Lf14f5a0_0014f5c3\n"
    );
}

/* line 1849 */
qboolean UI_CheckExecKey(int key)
{
    void *menu;
    int *node;

    menu = Menu_GetFocused(uiInfo);

    /* if editing a field, key is "exec" */
    if (*(int *)(*(int *)imp_g_editingField))
        return 1;

    if (key > 0x100)
        return 0;
    if (!menu)
        return 0;

    /* walk key bind linked list at menu+0x250 */
    node = *(int **)((byte *)menu + 0x250);
    while (node) {
        if (*node == key)
            return 1;
        node = *(int **)((byte *)node + 8);
    }
    return 0;
}

/* line 1928 */
static void UI_VerifyLanguage(void)
{
    int oldLanguage = Dvar_GetInt("loc_language");
    int newLanguage = Dvar_GetInt("ui_language");
    int verified = SEH_VerifyLanguageSelection(newLanguage);

    if (verified != newLanguage)
        Dvar_SetIntByName("ui_language", verified);

    if (oldLanguage != newLanguage)
        Dvar_SetBoolByName("ui_languagechanged", 1);
    else
        Dvar_SetBoolByName("ui_languagechanged", 0);
}

/* UI_SafeTranslateString — translate string reference, with fallback error handling */
extern void *imp_loc_warnings;
extern void *imp_loc_warningsAsErrors;
const char * UI_SafeTranslateString(const char *reference)
{
    const char *ref = reference;

    /* Strip 0x15 prefix if present */
    if (ref[0] == 0x15)
        ref++;

    /* Try to translate */
    const char *translated = SEH_StringEd_GetString(ref);
    if (translated)
        return translated;

    /* Translation failed — check warning settings */
    byte *locWarn = *(byte **)imp_loc_warnings;
    if (*(byte *)(locWarn + 8)) {
        byte *locErr = *(byte **)imp_loc_warningsAsErrors;
        if (*(byte *)(locErr + 8)) {
            Com_Error(6, "Could not translate string \"%s\"", ref);
        } else {
            Com_Printf(0, "^3WARNING: Could not translate string \"%s\"\n", ref);
        }
        /* Build error string: "^1UNLOCALIZED(^7" + ref + "^1)^7" */
        strcpy(errorString, "^1UNLOCALIZED(^7");
        I_strncat(errorString, ref, 0x400);
        I_strncat(errorString, "^1)^7", 0x400);
        return errorString;
    }

    /* No warnings — just return raw reference */
    strcpy(errorString, ref);
    return errorString;
}

/* line 1958 */
static __attribute__((naked))
void UI_AddServerToFavoritesList(const char * *p, const char * *out)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1958 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl %edx, %ebx\n" /* pszAddress */
        /* { scope 1 */
        "cmpb $0, (%eax)\n" /* line 1962 */
        "je 0x14f90d\n"
        "cmpb $0, (%edx)\n" /* line 1967 */
        "je .Lf14f850_0014f8d7\n"
        "movl %edx, 8(%esp)\n" /* line 1974 */
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll LAN_AddServer\n"
        "testl %eax, %eax\n" /* line 1975 */
        "je 0x14f975\n"
        "cmpl $-1, %eax\n" /* line 1981 */
        "je 0x14f9ab\n"
        "cmpl $-2, %eax\n" /* line 1987 */
        "je 0x14f943\n"
        "movl $str_002aa218, (%esp)\n" /* line 1996 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll va\n"
        "movl %ebx, 4(%esp)\n" /* pszAddress */
        "movl %eax, (%esp)\n"
        "calll Com_Printf\n"
        "movl $str_002aa22c, 4(%esp)\n" /* line 1997 */
        "movl $str_002aa144, (%esp)\n" /* "ui_favorite_message" */
        "calll Dvar_SetStringByName\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 2000 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f850_0014f8d7:\n"
        "movl $str_002aa158, (%esp)\n" /* line 1969 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "movl $str_002aa174, 4(%esp)\n" /* line 1970 */
        "movl $str_002aa144, (%esp)\n" /* "ui_favorite_message" */
        "calll Dvar_SetStringByName\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 2000 */
        "popl %ebx\n"
        "popl %ebp\n"
    );
}

/* line 2061 */
static __attribute__((naked))
Bool UI_GetOpenOrCloseMenuOnDvarArgs(char *testValue, char *menuName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2061 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %ebx\n" /* args */
        "movl %edx, %esi\n" /* cmd */
        "movl $0x400, 8(%esp)\n" /* line 2063 */
        "movl %ecx, 4(%esp)\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf14f9e0_0014fa1d\n"
        "movl %esi, 4(%esp)\n" /* line 2065 | cmd */
        "movl $str_002aa240, (%esp)\n" /* "%s: invalid dvar name.
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 2082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14f9e0_0014fa1d:\n"
        "movl $0x400, 8(%esp)\n" /* line 2069 */
        "movl 8(%ebp), %eax\n" /* testValue */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* args */
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf14f9e0_0014fa5f\n"
        "movl $0x400, 8(%esp)\n" /* line 2075 */
        "movl 0xc(%ebp), %eax\n" /* menuName */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* args */
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf14f9e0_0014fa78\n"
        "movl $1, %eax\n"
        "addl $0x10, %esp\n" /* line 2082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14f9e0_0014fa5f:\n"
        "movl %esi, 4(%esp)\n" /* line 2071 | cmd */
        "movl $str_002aa258, (%esp)\n" /* "%s: invalid test value.
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 2082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14f9e0_0014fa78:\n"
        "movl %esi, 4(%esp)\n" /* line 2077 | cmd */
        "movl $str_002aa274, (%esp)\n" /* "%s: invalid menu name.
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "addl $0x10, %esp\n" /* line 2082 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3140 */
static __attribute__((naked))
int UI_GetServerStatusInfo(serverStatusInfo_t *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3140 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* serverAddress */
        "movl %edx, -0x38(%ebp)\n"
        /* { scope 1: index */
        "testl %edx, %edx\n" /* line 3145 */
        "je .Lf14fa92_0014fe95\n"
        "movl $0xd04, 8(%esp)\n" /* line 3150 */
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl -0x38(%ebp), %edx\n" /* line 3151 */
        "addl $0x840, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* p */
        "movl $0x400, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* serverAddress */
        "calll LAN_GetServerStatus\n"
        "testl %eax, %eax\n"
        "jne .Lf14fa92_0014faec\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3239 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: index */
        ".Lf14fa92_0014faec:\n"
        "movl $0x40, 8(%esp)\n" /* line 3153 */
        "movl %ebx, 4(%esp)\n" /* serverAddress */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x38(%ebp), %ebx\n" /* line 3156 | serverAddress */
        "movl $str_002a9ad0, 0x40(%ebx)\n" /* serverAddress */
        "movl $str_002157b8, 0x44(%ebx)\n" /* line 3157 | serverAddress */
        "movl $str_002157b8, 0x48(%ebx)\n" /* line 3158 | serverAddress */
        "movl %ebx, 0x4c(%ebx)\n" /* line 3159 | serverAddress */
        "movl $1, 0xd00(%ebx)\n" /* line 3160 | serverAddress */
        "movl -0x34(%ebp), %ecx\n" /* line 3162 | p */
        "testl %ecx, %ecx\n"
        "je .Lf14fa92_0014feb7\n"
        "movl -0x38(%ebp), %eax\n"
        "cmpb $0, 0x840(%eax)\n"
        "jne .Lf14fa92_0014fcea\n"
        "movl $1, %ebx\n" /* serverAddress */
        ".Lf14fa92_0014fb48:\n"
        "cmpl $0x7c, %ebx\n" /* line 3184 | serverAddress */
        "jg .Lf14fa92_0014fd98\n"
        "movl %ebx, %eax\n" /* line 3187 | serverAddress */
        "shll $4, %eax\n"
        "addl -0x38(%ebp), %eax\n"
        "movl $str_002157b8, 0x40(%eax)\n"
        "movl $str_002157b8, 0x44(%eax)\n" /* line 3188 */
        "movl $str_002157b8, 0x48(%eax)\n" /* line 3189 */
        "movl $str_002157b8, 0x4c(%eax)\n" /* line 3190 */
        "movl %ebx, %eax\n" /* line 3193 | serverAddress */
        "shll $4, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "leal 0x10(%eax, %edx), %eax\n"
        "movl $str_002aa28c, 0x40(%eax)\n" /* "@EXE_SV_INFO_NUM" */
        "movl $str_002aa2a0, 0x44(%eax)\n" /* line 3194 */
        "movl $str_002aa2b4, 0x48(%eax)\n" /* line 3195 */
        "movl $str_002aa2c8, 0x4c(%eax)\n" /* line 3196 */
        "leal 2(%ebx), %eax\n" /* line 3197 | serverAddress */
        "movl %eax, 0xd00(%edx)\n"
        "movl -0x34(%ebp), %edx\n" /* line 3201 | p */
        "testl %edx, %edx\n"
        "je .Lf14fa92_0014fd98\n"
        "movl -0x34(%ebp), %edx\n" /* p */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf14fa92_0014fd98\n"
        "movl $0, -0x30(%ebp)\n" /* i */
        "movl $0, -0x2c(%ebp)\n" /* len */
        "jmp .Lf14fa92_0014fcda\n"
        ".Lf14fa92_0014fbd2:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 3204 | p */
        "movb $0, (%ecx)\n"
        "addl $1, %ecx\n" /* line 3205 */
        "movl %ecx, -0x34(%ebp)\n" /* p */
        "je .Lf14fa92_0014fd98\n"
        "movl %ecx, %ebx\n" /* serverAddress */
        ".Lf14fa92_0014fbe6:\n"
        "movl $0x20, 4(%esp)\n" /* line 3208 */
        "movl %ebx, (%esp)\n" /* serverAddress */
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 3209 */
        "je .Lf14fa92_0014fd98\n"
        "movb $0, (%eax)\n" /* line 3211 */
        "addl $1, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x20, 4(%esp)\n" /* line 3213 */
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 3214 */
        "je .Lf14fa92_0014fd98\n"
        "movb $0, (%eax)\n" /* line 3216 */
        "addl $1, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 3218 | len */
        "movl -0x38(%ebp), %edx\n"
        "leal 0xc40(%eax, %edx), %edi\n"
        "movl -0x30(%ebp), %ecx\n" /* i */
        "movl %ecx, 0xc(%esp)\n"
        "movl $str_00215a64, 8(%esp)\n" /* "%d" */
        "movl $0xc0, %eax\n"
        "subl -0x2c(%ebp), %eax\n" /* len */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Com_sprintf\n"
        "movl -0x38(%ebp), %eax\n" /* line 3219 */
        "movl 0xd00(%eax), %ebx\n" /* serverAddress */
        "movl %ebx, %edx\n" /* serverAddress */
        "shll $4, %edx\n"
        "addl %eax, %edx\n"
        "movl %edi, 0x40(%edx)\n"
        "cld\n" /* line 3220 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl %ecx, -0x2c(%ebp)\n" /* len */
        "movl -0x34(%ebp), %ecx\n" /* line 3221 | p */
        "movl %ecx, 0x44(%edx)\n"
        "movl -0x20(%ebp), %eax\n" /* line 3222 */
        "movl %eax, 0x48(%edx)\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 3223 */
        "movl %ecx, 0x4c(%edx)\n"
        "addl $1, %ebx\n" /* line 3224 | serverAddress */
        "movl -0x38(%ebp), %eax\n"
        "movl %ebx, 0xd00(%eax)\n" /* serverAddress */
        "cmpl $0x7f, %ebx\n" /* line 3225 | serverAddress */
        "jg .Lf14fa92_0014fd98\n"
        "movl $0x5c, 4(%esp)\n" /* line 3227 */
        "movl %ecx, (%esp)\n"
        "calll strchr\n"
        "testl %eax, %eax\n" /* line 3228 */
        "je .Lf14fa92_0014fd98\n"
        "movb $0, (%eax)\n" /* line 3230 */
        "addl $1, -0x30(%ebp)\n" /* line 3232 | i */
        "movl %eax, %edx\n" /* line 3201 */
        "addl $1, %edx\n"
        "movl %edx, -0x34(%ebp)\n" /* p */
        "je .Lf14fa92_0014fd98\n"
        "movzbl 1(%eax), %eax\n"
        "testb %al, %al\n"
        "je .Lf14fa92_0014fd98\n"
        ".Lf14fa92_0014fcda:\n"
        "cmpb $0x5c, %al\n" /* line 3203 */
        "je .Lf14fa92_0014fbd2\n"
        "movl -0x34(%ebp), %ebx\n" /* p, serverAddress */
        "jmp .Lf14fa92_0014fbe6\n"
        ".Lf14fa92_0014fcea:\n"
        "movl $0x5c, 4(%esp)\n" /* line 3164 */
        "movl -0x34(%ebp), %eax\n" /* p */
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "movl %eax, -0x34(%ebp)\n" /* p */
        "testl %eax, %eax\n" /* line 3165 */
        "je .Lf14fa92_0014fed3\n"
        "movb $0, (%eax)\n" /* line 3167 */
        "addl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* p */
        "cmpb $0x5c, (%eax)\n" /* line 3168 */
        "je .Lf14fa92_0014fec5\n"
        "movl %eax, %ecx\n"
        "movl -0x38(%ebp), %edx\n" /* line 3170 */
        "movl 0xd00(%edx), %ebx\n" /* serverAddress */
        "movl %ebx, %eax\n" /* serverAddress */
        "shll $4, %eax\n"
        "addl %edx, %eax\n"
        "movl %ecx, 0x40(%eax)\n"
        "movl $str_002157b8, 0x44(%eax)\n" /* line 3171 */
        "movl $str_002157b8, 0x48(%eax)\n" /* line 3172 */
        "movl $0x5c, 4(%esp)\n" /* line 3173 */
        "movl %ecx, (%esp)\n"
        "calll strchr\n"
        "movl %eax, -0x34(%ebp)\n" /* p */
        "testl %eax, %eax\n" /* line 3174 */
        "je .Lf14fa92_0014fb48\n"
        "movb $0, (%eax)\n" /* line 3176 */
        "addl $1, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* p */
        "movl -0x38(%ebp), %ebx\n" /* line 3177 | serverAddress */
        "movl 0xd00(%ebx), %edx\n" /* serverAddress */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl -0x34(%ebp), %ecx\n" /* p */
        "movl %ecx, 0x4c(%eax, %ebx)\n"
        "leal 1(%edx), %eax\n" /* line 3179 */
        "movl %eax, 0xd00(%ebx)\n" /* serverAddress */
        "cmpl $0x7f, %eax\n" /* line 3180 */
        "jg .Lf14fa92_0014fd91\n"
        "testl %ecx, %ecx\n" /* line 3162 */
        "je .Lf14fa92_0014fd91\n"
        "cmpb $0, (%ecx)\n"
        "jne .Lf14fa92_0014fcea\n"
        ".Lf14fa92_0014fd91:\n"
        "movl %eax, %ebx\n" /* serverAddress */
        "jmp .Lf14fa92_0014fb48\n"
        /* { scope 2 */
        ".Lf14fa92_0014fd98:\n"
        "movl serverStatusDvars, %eax\n" /* line 3100 */
        "testl %eax, %eax\n"
        "je .Lf14fa92_0014fe61\n"
        "movl $0, -0x28(%ebp)\n" /* index */
        "movl $serverStatusDvars+12, -0x24(%ebp)\n"
        ".Lf14fa92_0014fdb3:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 3102 */
        "movl 0xd00(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf14fa92_0014fe4e\n"
        "xorl %esi, %esi\n" /* j */
        "jmp .Lf14fa92_0014fdd9\n"
        ".Lf14fa92_0014fdc8:\n"
        "addl $1, %esi\n" /* j */
        "addl $0x10, %ebx\n"
        "movl -0x38(%ebp), %edx\n"
        "cmpl 0xd00(%edx), %esi\n" /* j */
        "jge .Lf14fa92_0014fe4e\n"
        ".Lf14fa92_0014fdd9:\n"
        "movl 0x44(%ebx), %eax\n" /* line 3104 */
        "testl %eax, %eax\n"
        "je .Lf14fa92_0014fdc8\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf14fa92_0014fdc8\n"
        "movl 0x40(%ebx), %eax\n" /* line 3107 */
        "movl %eax, 4(%esp)\n"
        "movl -0x24(%ebp), %ecx\n"
        "movl -0xc(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14fa92_0014fdc8\n"
        "movl -0x28(%ebp), %eax\n" /* line 3110 | index */
        "shll $4, %eax\n"
        "movl -0x38(%ebp), %edx\n"
        "leal (%eax, %edx), %edi\n"
        "movl 0x40(%edi), %edx\n"
        "movl 0x4c(%edi), %ecx\n" /* line 3111 */
        "movl 0x40(%ebx), %eax\n" /* line 3112 */
        "movl %eax, 0x40(%edi)\n"
        "movl 0x4c(%ebx), %eax\n" /* line 3113 */
        "movl %eax, 0x4c(%edi)\n"
        "movl %edx, 0x40(%ebx)\n" /* line 3114 */
        "movl %ecx, 0x4c(%ebx)\n" /* line 3115 */
        "movl -0x24(%ebp), %ecx\n" /* line 3117 */
        "movl -8(%ecx), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf14fa92_0014fe91\n"
        "movl %eax, 0x40(%edi)\n" /* line 3118 */
        "movl -0x24(%ebp), %eax\n"
        ".Lf14fa92_0014fe33:\n"
        "cmpl $1, -4(%eax)\n" /* line 3120 */
        "je .Lf14fa92_0014fe6e\n"
        "addl $1, -0x28(%ebp)\n" /* line 3128 | index */
        ".Lf14fa92_0014fe3d:\n"
        "addl $1, %esi\n" /* line 3102 | j */
        "addl $0x10, %ebx\n"
        "movl -0x38(%ebp), %edx\n"
        "cmpl 0xd00(%edx), %esi\n" /* j */
        "jl .Lf14fa92_0014fdd9\n"
        ".Lf14fa92_0014fe4e:\n"
        "movl -0x24(%ebp), %ecx\n" /* line 3100 */
        "movl (%ecx), %eax\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf14fa92_0014fdb3\n"
        ".Lf14fa92_0014fe61:\n"
        "movl $1, %eax\n" /* line 3102 */
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3239 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: index */
        /* { scope 2 */
        ".Lf14fa92_0014fe6e:\n"
        "movl 0x4c(%edi), %eax\n" /* line 3122 */
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl $str_002aa2dc, %edx\n" /* line 3123 */
        "testl %eax, %eax\n"
        "movl $str_002aa2e8, %eax\n" /* "@EXE_NO" */
        "cmovel %eax, %edx\n"
        "movl %edx, 0x4c(%edi)\n"
        "addl $1, -0x28(%ebp)\n" /* line 3128 | index */
        "jmp .Lf14fa92_0014fe3d\n"
        ".Lf14fa92_0014fe91:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf14fa92_0014fe33\n"
        /* } scope */
        ".Lf14fa92_0014fe95:\n"
        "movl $0, 8(%esp)\n" /* line 3147 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerStatus\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3239 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14fa92_0014feb7:\n"
        "movl -0x38(%ebp), %eax\n"
        "movl 0xd00(%eax), %ebx\n" /* serverAddress */
        "jmp .Lf14fa92_0014fb48\n"
        ".Lf14fa92_0014fec5:\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl 0xd00(%ecx), %ebx\n" /* serverAddress */
        "jmp .Lf14fa92_0014fb48\n"
        ".Lf14fa92_0014fed3:\n"
        "movl -0x38(%ebp), %edx\n"
        "movl 0xd00(%edx), %ebx\n" /* serverAddress */
        "jmp .Lf14fa92_0014fb48\n"
    );
}

/* line 3884 */
void UI_FeederSelection(float feederID, int index)
{
    if (feederID == 4.0f) {
        /* map selection */
        int mapVal = *(int *)((byte *)ui_currentNetMap + 8);
        int offset = mapVal * 164;
        int cinHandle = *(int *)((byte *)&sharedUiInfo + 4972 + offset);
        int numMaps, visCount, actual, i;

        if (cinHandle >= 0) {
            CIN_StopCinematic(cinHandle);
            *(int *)((byte *)&sharedUiInfo + 4960 + 12 + offset) = -1;
        }

        /* find actual map index from visible index */
        numMaps = *(int *)((byte *)&sharedUiInfo + 4944);
        visCount = 0;
        actual = 0;
        for (i = 0; i < numMaps; i++) {
            if (*(int *)((byte *)&sharedUiInfo + i * 0xa4 + 0x13f4) != 0) {
                if (visCount == index) {
                    actual = i;
                    goto map_found;
                }
                visCount++;
            }
        }
        actual = 0;
map_found:
        Dvar_SetInt(ui_currentMap, actual);
        Dvar_SetInt(ui_currentNetMap, actual);

    } else if (feederID == 2.0f) {
        /* server selection */
        char *name;
        char *p;

        if (*(int *)((byte *)&sharedUiInfo + 108660) >= 1)
            *(int *)((byte *)&sharedUiInfo + 28656) = index;

        LAN_GetServerInfo(*(int *)((byte *)ui_netSource + 8),
                          *(int *)((byte *)&sharedUiInfo + 28660 + index * 4),
                          info, 0x400);
        name = (char *)va("levelshots/%s", Info_ValueForKey(info, "mapname"));

        /* lowercase the name */
        for (p = name; *p; p++)
            *p = ___tolower((int)(signed char)*p);

        *(int *)((byte *)&sharedUiInfo + 108680) = CL_RegisterMaterialNoMip(name, 3);
        if (*(int *)((byte *)&sharedUiInfo + 108684) >= 0) {
            CIN_StopCinematic(*(int *)((byte *)&sharedUiInfo + 108684));
            *(int *)((byte *)&sharedUiInfo + 108684) = -1;
        }

    } else if (feederID == 7.0f || feederID == 20.0f) {
        /* player list selection */
        *(int *)((byte *)uiInfo + 0x27c) = index;

    } else if (feederID == 9.0f) {
        *(int *)((byte *)&sharedUiInfo + 26488) = index;

    } else if (feederID == 24.0f) {
        /* player profile selection */
        if (index >= 0 && index < *(int *)((byte *)uiInfo + 0x280)) {
            int sortedIdx = *(int *)((byte *)uiInfo + 0x388 + index * 4);
            const char *profileName = *(const char **)((byte *)uiInfo + 0x284 + sortedIdx * 4);
            Dvar_SetString(ui_playerProfileSelected, profileName);
        }
    }
}

/* line 4003 */
static void UI_GetGameTypesList(void)
{
    char szGameTypeList[0x1000];
    int iNumGameTypeScripts;
    int i;
    char *pszFileName;
    const char *pBuffParse;

    *(int *)((byte *)&sharedUiInfo + 4424) = 0;
    *(int *)((byte *)&sharedUiInfo + 4684) = 0;

    /* add "All" entry */
    *(const char **)((byte *)&sharedUiInfo + 4688) = String_Alloc("All");
    {
        int idx = *(int *)((byte *)&sharedUiInfo + 4684);
        *(const char **)((byte *)&sharedUiInfo + 4692 + idx * 8) = str_002157b8;
    }
    *(int *)((byte *)&sharedUiInfo + 4684) += 1;

    iNumGameTypeScripts = FS_GetFileList("maps/mp/gametypes", "gsc", 0, szGameTypeList, 0x1000);

    if (iNumGameTypeScripts > 0) {
        pszFileName = szGameTypeList;

        for (i = 0; i < iNumGameTypeScripts; i++) {
            int iLen = strlen(pszFileName);
            char *pszEnd;
            int numTypes;

            /* skip files starting with _ */
            if (pszFileName[0] == '_') {
                pszFileName += iLen + 1;
                continue;
            }

            /* strip .gsc extension */
            pszEnd = pszFileName + iLen;
            if (I_stricmp(pszEnd - 4, ".gsc") == 0) {
                pszFileName[iLen - 4] = '\0';
            }

            numTypes = *(int *)((byte *)&sharedUiInfo + 4424);
            if (numTypes == 32 || *(int *)((byte *)&sharedUiInfo + 4684) == 32) {
                Com_Printf("Too many game type scripts found! Only loading the first %i\n", 31);
                break;
            }

            /* store game type script name */
            *(const char **)((byte *)&sharedUiInfo + 4428 + numTypes * 8) = String_Alloc(pszFileName);

            /* copy script name to game type names list */
            {
                int gt = *(int *)((byte *)&sharedUiInfo + 4424);
                const char *scriptName = *(const char **)((byte *)&sharedUiInfo + 4428 + gt * 8);
                int nameIdx = *(int *)((byte *)&sharedUiInfo + 4684);
                *(const char **)((byte *)&sharedUiInfo + 4688 + nameIdx * 8) = scriptName;
            }

            /* parse display name from .txt file */
            pBuffParse = GetMenuBuffer(va("maps/mp/gametypes/%s.txt", pszFileName));
            if (pBuffParse) {
                const char *parsed = Com_Parse(&pBuffParse);
                int gt2 = *(int *)((byte *)&sharedUiInfo + 4424);
                *(const char **)((byte *)&sharedUiInfo + 4432 + gt2 * 8) = String_Alloc(parsed);
                {
                    const char *displayName = *(const char **)((byte *)&sharedUiInfo + 4432 + *(int *)((byte *)&sharedUiInfo + 4424) * 8);
                    int nameIdx2 = *(int *)((byte *)&sharedUiInfo + 4684);
                    *(const char **)((byte *)&sharedUiInfo + 4692 + nameIdx2 * 8) = displayName;
                }
            } else {
                /* no .txt file: copy script name as display name */
                int gt3 = *(int *)((byte *)&sharedUiInfo + 4424);
                *(const char **)((byte *)&sharedUiInfo + 4432 + gt3 * 8) = *(const char **)((byte *)&sharedUiInfo + 4428 + gt3 * 8);
                {
                    const char *displayName2 = *(const char **)((byte *)&sharedUiInfo + 4432 + *(int *)((byte *)&sharedUiInfo + 4424) * 8);
                    int nameIdx3 = *(int *)((byte *)&sharedUiInfo + 4684);
                    *(const char **)((byte *)&sharedUiInfo + 4692 + nameIdx3 * 8) = displayName2;
                }
            }

            *(int *)((byte *)&sharedUiInfo + 4424) += 1;
            *(int *)((byte *)&sharedUiInfo + 4684) += 1;
            pszFileName = pszEnd + 1;
        }
    }

    if (*(int *)((byte *)&sharedUiInfo + 4424) == 0) {
        Com_Error(0, "\x15No game type scripts found in maps/mp/gametypes folder");
    }
}

/* line 4101 */
void UI_Pause(qboolean b)
{
    if (b) {
        Dvar_SetIntByName("cl_paused", 1);
        Key_SetCatcher(8);
    } else {
        Key_SetCatcher(Key_GetCatcher() & ~8);
        Key_ClearStates();
        Dvar_SetIntByName("cl_paused", 0);
    }
}

/* line 4124 */
void UI_OpenMenu_f(void)
{
    Menus_OpenByName(uiInfo, Cmd_Args(1));
}

/* line 4136 */
void UI_CloseMenu_f(void)
{
    Menus_CloseByName(uiInfo, Cmd_Args(1));
}

/* line 4148 */
void UI_Init(void)
{
    byte *legacyBase;
    int width, height;
    int menuList;
    int netGameTypeIdx;
    float mPitch;

    *(int *)uiInfo = 0;
    g_ingameMenusLoaded = 0;

    UI_LoadSoundAliases();

    /* register dvars */
    Dvar_RegisterBool_mac("g_allowvote", 1, 0x1001);
    Dvar_RegisterBool_mac("cg_brass", 1, 0x1001);
    Dvar_RegisterBool_mac("cg_marks", 1, 0x1001);

    Dvar_RegisterString_mac("server1", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server2", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server3", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server4", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server5", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server6", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server7", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server8", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server9", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server10", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server11", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server12", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server13", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server14", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server15", str_002157b8, 0x1001);
    Dvar_RegisterString_mac("server16", str_002157b8, 0x1001);

    ui_netSource = Dvar_RegisterInt("ui_netSource", 0, 0, 2, 0x1001);
    ui_smallFont = Dvar_RegisterFloat("ui_smallFont", 0.25f, 0.0f, 1.0f, 0x1001);
    ui_bigFont = Dvar_RegisterFloat("ui_bigFont", 0.4f, 0.0f, 1.0f, 0x1001);
    ui_extraBigFont = Dvar_RegisterFloat("ui_extraBigFont", 0.55f, 0.0f, 1.0f, 0x1001);
    ui_currentMap = Dvar_RegisterInt("ui_currentMap", 0, 0, 0x7fffffff, 0x1001);
    ui_gametype = Dvar_RegisterInt("ui_gametype", 3, 0, 0x7fffffff, 0x1001);
    ui_joinGameType = Dvar_RegisterInt("ui_joinGametype", 0, 0, 0x7fffffff, 0x1001);
    ui_netGameTypeName = Dvar_RegisterString_mac("ui_netGametypeName", str_002157b8, 0x1001);
    ui_dedicated = Dvar_RegisterInt("ui_dedicated", 0, 0, 2, 0x1001);
    ui_currentNetMap = Dvar_RegisterInt("ui_currentNetMap", 0, 0, 0x7fffffff, 0x1001);
    ui_browserShowFull = Dvar_RegisterBool_mac("ui_browserShowFull", 1, 0x1001);
    ui_browserShowEmpty = Dvar_RegisterBool_mac("ui_browserShowEmpty", 1, 0x1001);
    ui_browserShowPassword = Dvar_RegisterBool_mac("ui_browserShowPassword", 1, 0x1001);
    ui_browserShowNoPassword = Dvar_RegisterBool_mac("ui_browserShowNoPassword", 1, 0x1001);
    ui_browserShowPure = Dvar_RegisterBool_mac("ui_browserShowPure", 1, 0x1001);
    ui_browserShowDedicated = Dvar_RegisterBool_mac("ui_browserShowDedicated", 0, 0x1001);
    ui_browserMod = Dvar_RegisterInt("ui_browserMod", -1, -1, 0x7fffffff, 0x1001);
    ui_browserFriendlyfire = Dvar_RegisterInt("ui_browserFriendlyfire", -1, (int)0x80000000, 0x7fffffff, 0x1001);
    ui_browserKillcam = Dvar_RegisterInt("ui_browserKillcam", -1, (int)0x80000000, 0x7fffffff, 0x1001);
    ui_serverStatusTimeOut = Dvar_RegisterInt("ui_serverStatusTimeOut", 7000, 0, 0x7fffffff, 0x1001);
    ui_playerProfileCount = Dvar_RegisterInt("ui_playerProfileCount", 0, (int)0x80000000, 0x7fffffff, 0x1040);
    ui_playerProfileSelected = Dvar_RegisterString_mac("ui_playerProfileSelected", str_002157b8, 0x1040);
    ui_playerProfileNameNew = Dvar_RegisterString_mac("ui_playerProfileNameNew", str_002157b8, 0x1000);

    /* initialize legacy hacks state */
    legacyBase = *(byte **)imp_legacyHacksArray;
    *(byte *)(legacyBase + 0x2e4) = 0;
    *(int *)(legacyBase + 0x3e4) = -1;
    *(byte *)(legacyBase + 0x1de) = 0;
    *(int *)(legacyBase + 0x2e0) = -1;
    *(byte *)(legacyBase + 0x4ed) = 1;
    *(byte *)(legacyBase + 0x3e8) = 0;
    *(int *)(legacyBase + 0x4e8) = -1;
    *(byte *)(legacyBase + 0x4ec) = 0;

    String_Init();
    Menu_Setup(uiInfo);

    /* get screen dimensions */
    CL_GetScreenDimensions((int *)((byte *)uiInfo + 0x18), (int *)((byte *)uiInfo + 0x1c), (int *)((byte *)uiInfo + 0x20));

    width = *(int *)((byte *)uiInfo + 0x18);
    height = *(int *)((byte *)uiInfo + 0x1c);

    /* widescreen check: width*480 > height*640 */
    if (width * 480 > height * 640) {
        /* calculate horizontal offset for widescreen */
        *(float *)uiInfo = ((float)width + (float)height * -1.3333333730697632f) * 0.5f;
    } else {
        *(int *)uiInfo = 0;
    }

    Sys_Milliseconds();
    UI_GetGameTypesList();

    ui_netGameType = Dvar_RegisterInt("ui_netGametype", 0, 0, *(int *)((byte *)&sharedUiInfo + 4424) - 1, 0x1001);

    UI_LoadArenas();

    menuList = UI_LoadMenus("ui_mp/menus.txt", 3);
    UI_AddMenuList(uiInfo, menuList);

    if (g_mapname[0] != '\0') {
        UI_MapLoadInfo(va("maps/mp/%s.csv", g_mapname));
    }

    UI_AssetCache();
    Menus_CloseAll(uiInfo);

    /* register server hardware icons */
    *(int *)((byte *)&sharedUiInfo + 25940) = CL_RegisterMaterialNoMip("server_hardware_unknown", 3);
    *(int *)((byte *)&sharedUiInfo + 25944) = CL_RegisterMaterialNoMip("server_hardware_linux_dedicated", 3);
    *(int *)((byte *)&sharedUiInfo + 25948) = CL_RegisterMaterialNoMip("server_hardware_win_dedicated", 3);
    *(int *)((byte *)&sharedUiInfo + 25952) = CL_RegisterMaterialNoMip("server_hardware_mac_dedicated", 3);
    *(int *)((byte *)&sharedUiInfo + 25960) = CL_RegisterMaterialNoMip("server_hardware_win_listen", 3);
    *(int *)((byte *)&sharedUiInfo + 25964) = CL_RegisterMaterialNoMip("server_hardware_mac_listen", 3);

    LAN_LoadCachedServers();

    /* sort servers if sort key changed */
    if (*(int *)((byte *)&sharedUiInfo + 28640) != 9) {
        *(int *)((byte *)&sharedUiInfo + 28640) = 9;
        qsort((byte *)&sharedUiInfo + 28660, *(int *)((byte *)&sharedUiInfo + 108660), 4, UI_ServersQsortCompare);
    }

    /* set mouse pitch */
    mPitch = Dvar_GetFloat("m_pitch");
    Dvar_SetBoolByName("ui_mousePitch", mPitch < 0.0f ? 1 : 0);

    *(int *)((byte *)&sharedUiInfo + 108684) = -1;
    *(int *)((byte *)&sharedUiInfo + 27524) = -1;

    /* set net game type name dvar */
    netGameTypeIdx = *(int *)((byte *)ui_netGameType + 8);
    Dvar_SetString(ui_netGameTypeName, *(const char **)((byte *)&sharedUiInfo + 4428 + netGameTypeIdx * 8));

    Dvar_RegisterBool_mac("ui_multiplayer", 1, 0x1040);
}

/* line 4274 */
void UI_KeyEvent_impl(int key, qboolean down)
{
    void *menu;

    if (Menu_Count(uiInfo) <= 0)
        return;

    menu = Menu_GetFocused(uiInfo);
    if (menu) {
        if (Dvar_GetBool("cl_bypassMouseInput"))
            bypassKeyClear = 1;

        if (key == 0x1b && down && !Menus_AnyFullScreenVisible(uiInfo) && *(int *)((byte *)menu + 0x24c) == 0) {
            /* ESC on non-fullscreen menu with no parent */
            Menus_CloseAll(uiInfo);
        } else {
            Menu_HandleKey(uiInfo, menu, key, down);
        }

        if (Menu_GetFocused(uiInfo))
            return;
    }

    /* no focused menu */
    if (!(Key_GetCatcher() & 8))
        return;

    Key_SetCatcher(Key_GetCatcher() & ~8);
    if (!bypassKeyClear)
        Key_ClearStates();
    bypassKeyClear = 0;
    Dvar_SetIntByName("cl_paused", 0);
}

void UI_KeyEvent(int key, qboolean down)
{
    UI_KeyEvent_impl(key, down);
}

/* line 4340 */
void UI_MouseEvent(int dx, int dy)
{
    int *cursorX = (int *)((byte *)uiInfo + 0xc);
    int *cursorY = (int *)((byte *)uiInfo + 0x10);

    *cursorX += dx;
    if (*cursorX < 0)
        *cursorX = 0;
    else if (*cursorX > 640)
        *cursorX = 640;

    *cursorY += dy;
    if (*cursorY < 0)
        *cursorY = 0;
    else if (*cursorY > 480)
        *cursorY = 480;

    if (Menu_Count(uiInfo) > 0) {
        Display_MouseMove(uiInfo, 0, *cursorX, *cursorY);
    }
}

/* line 4364 */
uiMenuCommand_t UI_GetActiveMenu(void)
{
    return *(uiMenuCommand_t *)((byte *)uiInfo + 0x49c);
}

/* line 4386 */
qboolean UI_SetActiveMenu(int menu)
{
    byte *legacyBase;
    void *pFocus;
    const char *errorMsg;

    if (Menu_Count(uiInfo) <= 0)
        return 0;

    /* don't overwrite activeMenu for values 9 or 10 */
    if (menu != 9 && menu != 10)
        *(int *)((byte *)uiInfo + 0x49c) = menu;

    if ((unsigned)menu > 11)
        return 0;

    switch (menu) {
    case 0: /* UIMENU_NONE */
        Key_SetCatcher(Key_GetCatcher() & ~8);
        Dvar_SetIntByName("cl_paused", 0);
        Menus_CloseAll(uiInfo);
        return 1;

    case 1: /* UIMENU_MAIN */
        Key_SetCatcher(8);
        Menus_OpenByName(uiInfo, "main");
        errorMsg = Dvar_GetString("com_errorMessage");
        if (errorMsg[0] != '\0' && I_stricmp(errorMsg, ";") != 0) {
            Menus_OpenByName(uiInfo, "error_popmenu");
        }
        SND_FadeAllSounds(1.0f, 1000);
        return 1;

    case 2: /* UIMENU_INGAME */
        {
            int opened;
            const char *cgMenuName = (const char *)(*(byte **)imp_cg + 0x2adfc);
            Key_SetCatcher(8);
            Menus_CloseAll(uiInfo);
            /* Menus_OpenByName actually returns success in eax despite void decl */
            __asm__ __volatile__ (
                "movl %1, 4(%%esp)\n"
                "movl %2, (%%esp)\n"
                "calll Menus_OpenByName\n"
                "movl %%eax, %0\n"
                : "=r"(opened)
                : "r"(cgMenuName), "r"(uiInfo)
                : "eax", "ecx", "edx", "memory"
            );
            if (!opened) {
                Menus_OpenByName(uiInfo, "main");
            }
        }
        return 1;

    case 3: /* needcd */
        Key_SetCatcher(8);
        Menus_OpenByName(uiInfo, "needcd");
        return 1;

    case 4: /* badcd */
        Key_SetCatcher(8);
        Menus_OpenByName(uiInfo, "badcd");
        return 1;

    case 5: /* team */
        Key_SetCatcher(8);
        Menus_OpenByName(uiInfo, "team");
        return 1;

    case 6:
    case 7:
        return 0;

    case 8: /* quickmessage */
        *(int *)((byte *)uiInfo + 0xc) = 0x27f;
        *(int *)((byte *)uiInfo + 0x10) = 0x1df;
        Key_SetCatcher(8);
        *(byte *)(*(byte **)imp_cl + 8) = 1;
        Menus_CloseAll(uiInfo);
        Menus_OpenByName(uiInfo, "quickmessage");
        return 1;

    case 9:
    case 10: /* ingame menu with legacy hacks */
        pFocus = Menu_GetFocused(uiInfo);
        if (pFocus) {
            int activeMenu = *(int *)((byte *)uiInfo + 0x49c);
            if (activeMenu != 9 && activeMenu != 10)
                return 0;
        }

        legacyBase = *(byte **)imp_legacyHacks;

        if (pFocus) {
            /* check if focused menu name matches buf */
            if (I_stricmp(*(const char **)((byte *)pFocus + 0xc0), (const char *)(legacyBase + 0x2e4)) == 0)
                return 1;
        }

        *(int *)((byte *)uiInfo + 0x49c) = 9;

        if (menu == 10) {
            *(int *)((byte *)uiInfo + 0xc) = 0x27f;
            *(int *)((byte *)uiInfo + 0x10) = 0x1df;
        }

        Key_SetCatcher(8);
        Menus_CloseAll(uiInfo);

        /* copy buf to secondary location, save/clear state */
        strcpy((char *)(legacyBase + 0x1de), (const char *)(legacyBase + 0x2e4));
        *(int *)(legacyBase + 0x2e0) = *(int *)(legacyBase + 0x3e4);
        *(byte *)(legacyBase + 0x2e4) = 0;
        *(int *)(legacyBase + 0x3e4) = -1;

        Menus_OpenByName(uiInfo, (const char *)(legacyBase + 0x1de));
        return 1;

    case 11: /* player_profile */
        Key_SetCatcher(8);
        Menus_OpenByName(uiInfo, "player_profile");
        SND_FadeAllSounds(1.0f, 1000);
        return 1;
    }

    return 0;
}

/* line 4646 */
qboolean UI_IsFullscreen(void)
{
    return Menus_AnyFullScreenVisible(uiInfo);
}

/* line 4654 */
static __attribute__((naked))
void UI_ReadableSize(char *buf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4654 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, %esi\n" /* bufsize */
        "movl %ecx, %ebx\n" /* value */
        "cmpl $0x40000000, %ecx\n" /* line 4660 */
        "jg .Lf1511aa_00151293\n"
        "cmpl $0x100000, %ecx\n" /* line 4665 */
        "jg .Lf1511aa_00151210\n"
        "cmpl $0x400, %ecx\n" /* line 4670 */
        "jle .Lf1511aa_001512f0\n"
        "movl $str_002aa78c, (%esp)\n" /* line 4672 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 0x10(%esp)\n"
        "sarl $0xa, %ebx\n" /* value */
        ".Lf1511aa_001511ed:\n"
        "movl %ebx, 0xc(%esp)\n" /* line 4676 | value */
        "movl $str_002aa79c, 8(%esp)\n" /* "%d %s" */
        "movl %esi, 4(%esp)\n" /* bufsize */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "addl $0x3c, %esp\n" /* line 4678 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1511aa_00151210:\n"
        "movl %ecx, %eax\n" /* line 4667 */
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_00215a64, 8(%esp)\n" /* "%d" */
        "movl %edx, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $str_002aa77c, (%esp)\n" /* line 4668 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 0x10(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %edx, %edx\n"
        "movl -0x1c(%ebp), %edi\n"
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "andl $0xfffff, %ebx\n" /* value */
        "leal (%ebx, %ebx, 4), %eax\n" /* value */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "js .Lf1511aa_00151312\n"
        ".Lf1511aa_00151269:\n"
        "sarl $0x14, %eax\n"
        ".Lf1511aa_0015126c:\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002aa770, 8(%esp)\n" /* ".%02d %s" */
        "subl %edx, %esi\n" /* bufsize */
        "movl %esi, 4(%esp)\n" /* bufsize */
        "movl -0x1c(%ebp), %eax\n"
        "addl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "addl $0x3c, %esp\n" /* line 4678 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1511aa_00151293:\n"
        "movl %ecx, %eax\n" /* line 4662 */
        "sarl $0x1e, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_00215a64, 8(%esp)\n" /* "%d" */
        "movl %edx, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $str_002aa760, (%esp)\n" /* line 4663 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 0x10(%esp)\n"
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %edx, %edx\n"
        "movl -0x1c(%ebp), %edi\n"
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %edx\n"
        "andl $0x3fffffff, %ebx\n" /* value */
        "leal (%ebx, %ebx, 4), %eax\n" /* value */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "js .Lf1511aa_00151305\n"
        "sarl $0x1e, %eax\n"
        "jmp .Lf1511aa_0015126c\n"
        ".Lf1511aa_001512f0:\n"
        "movl $str_002aa7a4, (%esp)\n" /* line 4676 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 0x10(%esp)\n"
        "jmp .Lf1511aa_001511ed\n"
        ".Lf1511aa_00151305:\n"
        "addl $0x3fffffff, %eax\n" /* line 4663 */
        "sarl $0x1e, %eax\n"
        "jmp .Lf1511aa_0015126c\n"
        ".Lf1511aa_00151312:\n"
        "addl $0xfffff, %eax\n" /* line 4668 */
        "jmp .Lf1511aa_00151269\n"
    );
}

/* line 4984 */
float UI_GetBlurRadius(void)
{
    return *(float *)((byte *)uiInfo + 0x28);
}

/* line 5196 */
qboolean UI_AnyFullScreenMenuVisible(void)
{
    return Menus_AnyFullScreenVisible(uiInfo);
}

/* line 5232 */
const char * UI_ReplaceConversions(const char *sourceString, ConversionArguments *arguments)
{
    char outputString[0x400];
    int sourceStringLength;
    int index;
    int outputStringCounter;

    /* if no "&&" in source, return as-is */
    if (!strstr(sourceString, "&&"))
        return sourceString;

    sourceStringLength = strlen(sourceString);
    memset(outputString, 0, 0x400);

    if (sourceStringLength <= 0)
        return va(outputString);

    outputStringCounter = 0;
    index = 0;

    while (index < sourceStringLength) {
        /* check for "&&" at current position */
        if (sourceString[index] == '&' && sourceString[index + 1] == '&') {
            /* check if next char is a digit */
            unsigned int c = (unsigned char)sourceString[index + 2];
            {
                /* BSD ctype digit check via __DefaultRuneLocale */
                extern void *__DefaultRuneLocale;
                unsigned int *rt = (unsigned int *)__DefaultRuneLocale;
                if (c <= 0xff && (rt[13 + c] & 4)) {
                    /* found &&N pattern */
                    int argIndex = c - '1';
                    const char *argStr = arguments->args[argIndex];
                    int argLen = strlen(argStr);
                    int j;

                    for (j = 0; j < argLen; j++) {
                        outputString[outputStringCounter] = argStr[j];
                        outputStringCounter++;
                    }
                    index += 3;
                    continue;
                }
            }
        }

        /* not a conversion, copy character */
        outputString[outputStringCounter] = sourceString[index];
        outputStringCounter++;
        index++;
    }

    return va(outputString);
}

/* UI_ReplaceConversionString — build convArgs with 1 replacement string, call UI_ReplaceConversions */
const char *UI_ReplaceConversionString(const char *sourceString, const char *replaceString)
{
    int convArgs[10];
    memset(convArgs, 0, sizeof(convArgs));
    convArgs[0] = 1;
    convArgs[1] = (int)replaceString;
    return UI_ReplaceConversions(sourceString, (ConversionArguments *)convArgs);
}

/* line 5293 */
void UI_CloseAll(void)
{
    Menus_CloseAll(uiInfo);
}

/* line 5299 */
void UI_CloseFocusedMenu(void)
{
    if (Menu_Count(uiInfo) <= 0)
        return;

    if (!Menu_GetFocused(uiInfo)) {
        if (Key_GetCatcher() & 8) {
            Key_SetCatcher(Key_GetCatcher() & ~8);
        }
        return;
    }

    if (!Menus_AnyFullScreenVisible(uiInfo)) {
        Menus_CloseAll(uiInfo);
    }
}

/* line 3812 */
void UI_OverrideCursorPos(rectDef_t (*item)[16])
{
    byte *itemPtr = (byte *)item;
    float feederFloat = *(float *)(itemPtr + 0x2d8);

    if (feederFloat == 4.0f) {
        int testMapIndex = *(int *)((byte *)ui_currentNetMap + 8);
        int numMaps = *(int *)((byte *)&sharedUiInfo + 4944);
        int visCount = 0;
        int i;

        for (i = 0; i < numMaps; i++) {
            if (*(int *)((byte *)&sharedUiInfo + i * 0xa4 + 0x13f4) != 0) {
                if (i == testMapIndex)
                    goto found;
                visCount++;
            }
        }
        visCount = 0;
found:
        Item_SetCursorPos(item, visCount);
    } else if (feederFloat == 2.0f) {
        byte *listPtr = *(byte **)(itemPtr + 0x2ec);
        int endPos = *(int *)(listPtr + 0x10);

        if (endPos == 0) {
            Item_SetCursorPos(item, -1);
        } else {
            int serverIndex = *(int *)((byte *)&sharedUiInfo + 28656);
            int cursorField = *(int *)(itemPtr + 0x2dc);
            int startPos_val = *(int *)listPtr;
            int delta;
            int maxScroll;

            if (serverIndex < 0)
                return;
            if (cursorField < startPos_val)
                return;
            if (cursorField > endPos)
                return;

            delta = serverIndex - cursorField;
            ListBox_SetStartPos(listPtr, delta + startPos_val);
            ListBox_SetEndPos(listPtr, delta + endPos);
            ListBox_SetCursorPos(listPtr, delta + *(int *)(listPtr + 0x24));
            Item_SetCursorPos(item, *(int *)((byte *)&sharedUiInfo + 28656));

            maxScroll = Item_ListBox_MaxScroll(item);
            if (maxScroll < *(int *)listPtr) {
                ListBox_SetStartPos(listPtr, maxScroll);
            }
            if (*(int *)listPtr < 0) {
                ListBox_SetStartPos(listPtr, 0);
            }
        }
    }
}

/* line 1030 */
Bool UI_DrawRecordLevel(rectDef_t *rect)
{
    float voiceLevel;
    const vec_t *white;

    voiceLevel = Voice_GetVoiceLevel();

    if (voiceLevel > 0.0f) {
        float barWidth = voiceLevel * rect->w - 4.0f;
        if (barWidth > 0.0f) {
            UI_FillRect(rect->x + 2.0f, rect->y + 2.0f, barWidth, rect->h - 4.0f, 0, 0, (const vec_t *)imp_colorWhite);
        }
    }

    white = (const vec_t *)imp_colorWhite;
    /* top */
    UI_FillRect(rect->x, rect->y, rect->w, 1.0f, 0, 0, white);
    /* bottom */
    UI_FillRect(rect->x, rect->y + rect->h - 1.0f, rect->w, 1.0f, 0, 0, white);
    /* left */
    UI_FillRect(rect->x, rect->y + 1.0f, 1.0f, rect->h - 2.0f, 0, 0, white);
    /* right */
    UI_FillRect(rect->x + rect->w - 1.0f, rect->y + 1.0f, 1.0f, rect->h - 2.0f, 0, 0, white);

    return 1;
}

/* line 3786 */
MaterialHandle UI_FeederItemImage(const float feederID, int index)
{
    int numMaps, c, i, mapIndex;
    int byteOff;
    byte *base;

    if (feederID != 4.0f)
        return 0;

    numMaps = *(int *)((byte *)&sharedUiInfo + 4944);
    mapIndex = -1;

    if (numMaps > 0) {
        c = 0;
        for (i = 0; i < numMaps; i++) {
            if (*(int *)((byte *)&sharedUiInfo + 0x13f4 + i * 0xa4) != 0) {
                if (c == index) {
                    mapIndex = i;
                    break;
                }
                c++;
            }
        }
    }

    /* if no match found, default to entry 0 */
    if (mapIndex < 0)
        mapIndex = 0;

    if (numMaps <= mapIndex)
        return 0;

    byteOff = mapIndex * 0xa4;

    /* check if material handle is cached */
    if (*(int *)((byte *)&sharedUiInfo + 5104 + byteOff) == 0) {
        /* register the material from the name string */
        const char *name = *(const char **)((byte *)&sharedUiInfo + 4956 + byteOff);
        *(int *)((byte *)&sharedUiInfo + 5104 + byteOff) = CL_RegisterMaterialNoMip(name, 3);
    }

    return *(MaterialHandle *)((byte *)&sharedUiInfo + 5104 + byteOff);
}

/* line 393 */
__attribute__((naked))
void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 393 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        /* DIAG: trace UI_DrawText */
        "movl 0x24(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll diag_drawtext\n"
        "movl 0x10(%ebp), %esi\n" /* font */
        /* { scope 1 */
        "movl 0x24(%ebp), %eax\n" /* line 398 | scale */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* font */
        "calll CL_NormalizedTextScale\n"
        "fsts -0xc(%ebp)\n" /* xScale */
        "fstps -0x10(%ebp)\n" /* line 399 | yScale */
        "leal 0x18(%ebp), %ebx\n" /* line 401 | y */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* font */
        "calll CalcSplitScreenTextOffset\n"
        "movl 0x20(%ebp), %eax\n" /* line 402 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* yScale */
        "movl %eax, 0xc(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* xScale */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x14(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss lit4_002ed5d8, %xmm1\n" /* line 428 | 0.5f */
        "movss 0x14(%ebp), %xmm0\n" /* x */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x38(%ebp)\n"
        "calll floorf\n"
        "fstps -0x1c(%ebp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm0, 0x14(%ebp)\n" /* line 404 | x */
        "movss -0x38(%ebp), %xmm1\n" /* line 428 */
        "addss 0x18(%ebp), %xmm1\n" /* y */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x20(%ebp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x18(%ebp)\n" /* line 405 | y */
        "movl 0x2c(%ebp), %eax\n" /* line 407 | style */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x10(%ebp), %eax\n" /* yScale */
        "movl %eax, 0x18(%esp)\n"
        "movl -0xc(%ebp), %eax\n" /* xScale */
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %esi, 8(%esp)\n" /* font */
        "movl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll CL_DrawTextPhysical\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 408 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 411 */
__attribute__((naked))
void UI_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style, int cursorPos, int cursor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 411 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* font */
        "movsbl 0x34(%ebp), %esi\n" /* cursor */
        /* { scope 1 */
        "movl 0x24(%ebp), %eax\n" /* line 416 | scale */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* font */
        "calll CL_NormalizedTextScale\n"
        "fsts -0x1c(%ebp)\n" /* xScale */
        "fstps -0x20(%ebp)\n" /* line 417 | yScale */
        "leal 0x18(%ebp), %ebx\n" /* line 419 | y */
        "movl %ebx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* font */
        "calll CalcSplitScreenTextOffset\n"
        "movl 0x20(%ebp), %eax\n" /* line 420 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* yScale */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* xScale */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal 0x14(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss lit4_002ed5d8, %xmm1\n" /* line 428 | 0.5f */
        "movss 0x14(%ebp), %xmm0\n" /* x */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll floorf\n"
        "fstps -0x2c(%ebp)\n"
        "cvttss2si -0x2c(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm0, 0x14(%ebp)\n" /* line 422 | x */
        "movss -0x48(%ebp), %xmm1\n" /* line 428 */
        "addss 0x18(%ebp), %xmm1\n" /* y */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x30(%ebp)\n"
        "cvttss2si -0x30(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 0x18(%ebp)\n" /* line 423 | y */
        "movl %esi, 0x28(%esp)\n" /* line 425 | cursor */
        "movl 0x30(%ebp), %eax\n" /* cursorPos */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* style */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* yScale */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* xScale */
        "movl %eax, 0x14(%esp)\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll CL_DrawTextPhysicalWithCursor\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 426 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5086 */
static __attribute__((naked))
void UI_StartServerRefresh(qboolean full)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5086 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl %eax, -0x60(%ebp)\n"
        /* { scope 1 */
        "leal -0x54(%ebp), %eax\n" /* line 5096 | q */
        "movl %eax, (%esp)\n"
        "calll Com_RealTime\n"
        "movl ui_netSource, %eax\n" /* line 5097 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002aa7b0, 8(%esp)\n" /* "ui_lastServerRefresh_%i" */
        "movl $0x18, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll snprintf\n"
        "movl -0x50(%ebp), %ebx\n" /* line 5098 */
        "movl -0x4c(%ebp), %esi\n"
        "movl -0x40(%ebp), %edi\n"
        "addl $0x76c, %edi\n"
        "movl -0x48(%ebp), %edx\n"
        "movl %edx, -0x5c(%ebp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl MonthAbbrev(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa7c8, (%esp)\n" /* "%s %i, %i   %i:%02i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* dvarName */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetStringByName\n"
        "movl -0x60(%ebp), %edx\n" /* line 5100 */
        "testl %edx, %edx\n"
        "jne .Lf151b4a_00151c1c\n"
        "movl ui_netSource, %eax\n" /* line 3561 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_ResetPings\n"
        "movl $1, sharedUiInfo+28652\n" /* line 3562 */
        "movl uiInfo, %eax\n" /* line 3563 */
        "movl 4(%eax), %eax\n"
        "addl $0x3e8, %eax\n"
        "movl %eax, sharedUiInfo+28632\n"
        /* } scope */
        ".Lf151b4a_00151c14:\n"
        "addl $0x7c, %esp\n" /* line 5138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf151b4a_00151c1c:\n"
        "movl $1, sharedUiInfo+28652\n" /* line 5106 */
        "movl uiInfo, %eax\n" /* line 5107 */
        "movl 4(%eax), %eax\n"
        "addl $0x3e8, %eax\n"
        "movl %eax, sharedUiInfo+108672\n"
        "movl $0, sharedUiInfo+108660\n" /* line 2825 */
        "movl $0, sharedUiInfo+108668\n" /* line 2826 */
        "movl ui_netSource, %eax\n" /* line 2827 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "movl %eax, sharedUiInfo+108664\n"
        "movl $1, 8(%esp)\n" /* line 5110 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_MarkServerDirty\n"
        "movl ui_netSource, %eax\n" /* line 5112 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_ResetPings\n"
        "movl ui_netSource, %edx\n" /* line 5114 */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf151b4a_00151cfc\n"
        "movl uiInfo, %eax\n" /* line 5121 */
        "movl 4(%eax), %eax\n"
        "addl $0x1388, %eax\n"
        "movl %eax, sharedUiInfo+28632\n"
        "cmpl $1, 8(%edx)\n" /* line 5123 */
        "jne .Lf151b4a_00151c14\n"
        "movl $str_002aa7ec, (%esp)\n" /* line 5127 */
        "calll Dvar_GetVariantString\n"
        "cmpb $0, (%eax)\n" /* line 5128 */
        "jne .Lf151b4a_00151d2a\n"
        "movl $0x73, 8(%esp)\n" /* line 5134 */
        "movl $0, 4(%esp)\n"
        "movl $str_002aa81c, (%esp)\n" /* "globalservers %d %d full empty
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf151b4a_00151c14\n"
        ".Lf151b4a_00151cfc:\n"
        "movl $str_002aa7dc, 4(%esp)\n" /* line 5116 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl uiInfo, %eax\n" /* line 5117 */
        "movl 4(%eax), %eax\n"
        "addl $0x3e8, %eax\n"
        "movl %eax, sharedUiInfo+28632\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 5138 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf151b4a_00151d2a:\n"
        "movl %eax, 8(%esp)\n" /* line 5130 */
        "movl $0, 4(%esp)\n"
        "movl $str_002aa7fc, (%esp)\n" /* "globalservers %d %s full empty
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf151b4a_00151c14\n"
    );
}

/* Helper: insert server index into sorted display list at given position */
static void UI_InsertServerAtPosition(int serverIndex, int position)
{
    int numServers = *(int *)((byte *)&sharedUiInfo + 108660);
    int *displayServers = (int *)((byte *)&sharedUiInfo + 28660);
    int *selectedServer = (int *)((byte *)&sharedUiInfo + 28656);
    int j;

    if (position < 0 || numServers < position)
        return;

    if (*selectedServer >= position && numServers != 0)
        *selectedServer += 1;

    numServers++;
    *(int *)((byte *)&sharedUiInfo + 108660) = numServers;

    for (j = numServers - 1; j > position; j--)
        displayServers[j] = displayServers[j - 1];

    displayServers[position] = serverIndex;
}

/* Helper: remove duplicate server from favorites list */
static void UI_RemoveDuplicateFromFavorites(int serverIndex)
{
    int numServers = *(int *)((byte *)&sharedUiInfo + 108660);
    int *displayServers = (int *)((byte *)&sharedUiInfo + 28660);
    int i, j;

    if (numServers <= 0)
        return;

    for (i = 0; i < numServers; i++) {
        if (displayServers[i] == serverIndex)
            break;
    }
    if (i >= numServers)
        return;

    numServers--;
    *(int *)((byte *)&sharedUiInfo + 108660) = numServers;

    for (j = i; j < numServers; j++)
        displayServers[j] = displayServers[j + 1];
}

/* Helper: binary search insert into sorted server display list */
static void UI_BinaryInsertServer(int serverIndex)
{
    int numDisplay = *(int *)((byte *)&sharedUiInfo + 108660);
    int *displayServers = (int *)((byte *)&sharedUiInfo + 28660);
    int lo, hi, mid, testIdx, cmp, position, lastCmp;
    int source = *(int *)((byte *)ui_netSource + 8);
    int sortKey = *(int *)((byte *)&sharedUiInfo + 28640);
    int sortDir = *(int *)((byte *)&sharedUiInfo + 28644);

    lo = 0;
    hi = numDisplay;
    position = 0;
    lastCmp = 0;

    while (hi > 0) {
        mid = hi / 2;
        testIdx = lo + mid;

        cmp = LAN_CompareServers(source, sortKey, sortDir, serverIndex, displayServers[testIdx]);
        lastCmp = cmp;

        if (cmp == 0) {
            UI_InsertServerAtPosition(serverIndex, testIdx);
            return;
        } else if (cmp > 0) {
            hi -= mid;
            position = testIdx + 1;
            lo = position;
            hi--;
        } else {
            hi -= mid;
        }
    }

    /* adjust final position based on last comparison */
    if (lastCmp >= 0)
        position = lo + 1;
    else
        position = lo;

    UI_InsertServerAtPosition(serverIndex, position);
}

/* line 2836 */
static void UI_BuildServerDisplayList(qboolean force)
{
    char info_buf[0x400];
    int count, i, clients, ping;
    int netSource;

    /* check if we should update */
    if (!force) {
        if (*(int *)((byte *)uiInfo + 4) <= *(int *)((byte *)&sharedUiInfo + 108672))
            return;
    } else if (force == 2) {
        /* force == 2 treated same as force */
    }

    clients = 0;

    /* get MOTD string */
    {
        const char *motdString = Dvar_GetString("cl_motdString");
        int motdLen;
        I_strncpyz((char *)((byte *)&sharedUiInfo + 108712), motdString, 0x400);
        motdLen = strlen((const char *)((byte *)&sharedUiInfo + 108712));

        if (motdLen == 0) {
            const char *translated = UI_SafeTranslateString("EXE_COD_MULTIPLAYER");
            strcpy((char *)((byte *)&sharedUiInfo + 108712), va("%s - %s", translated, "1.3"));
            motdLen = strlen((const char *)((byte *)&sharedUiInfo + 108712));
        }

        if (motdLen != *(int *)((byte *)&sharedUiInfo + 108688)) {
            *(int *)((byte *)&sharedUiInfo + 108688) = motdLen;
            *(int *)((byte *)&sharedUiInfo + 108692) = -1;
        }
    }

    if (force) {
        numclean = 0;
        *(int *)((byte *)&sharedUiInfo + 108660) = 0;
        *(int *)((byte *)&sharedUiInfo + 108668) = 0;
        netSource = *(int *)((byte *)ui_netSource + 8);
        *(int *)((byte *)&sharedUiInfo + 108664) = LAN_GetServerCount(netSource);

        if (*(int *)((byte *)&sharedUiInfo + 28656) >= 0) {
            Menu_SetFeederSelection(uiInfo, 0, 2, 0, 0);
        }

        LAN_MarkServerDirty(*(int *)((byte *)ui_netSource + 8), -1, 1);
    }

    netSource = *(int *)((byte *)ui_netSource + 8);
    count = LAN_GetServerCount(netSource);

    if (LAN_WaitServerResponse(netSource) || (netSource == 0 && count == 0)) {
        *(int *)((byte *)&sharedUiInfo + 108660) = 0;
        *(int *)((byte *)&sharedUiInfo + 108668) = 0;
        *(int *)((byte *)&sharedUiInfo + 108664) = LAN_GetServerCount(*(int *)((byte *)ui_netSource + 8));
        *(int *)((byte *)&sharedUiInfo + 108672) = *(int *)((byte *)uiInfo + 4) + 500;
        return;
    }

    /* sort */
    qsort((byte *)&sharedUiInfo + 28660, *(int *)((byte *)&sharedUiInfo + 108660), 4, UI_ServersQsortCompare);

    for (i = 0; i < count; i++) {
        if (!LAN_ServerIsDirty(*(int *)((byte *)ui_netSource + 8), i))
            continue;

        ping = LAN_GetServerPing(*(int *)((byte *)ui_netSource + 8), i);

        if (ping <= 0 && *(int *)((byte *)ui_netSource + 8) != 2)
            continue;

        LAN_GetServerInfo(*(int *)((byte *)ui_netSource + 8), i, info_buf, 0x400);

        clients = atoi(Info_ValueForKey(info_buf, "clients"));
        *(int *)((byte *)&sharedUiInfo + 108668) += clients;

        /* address filter */
        if (I_strnicmp(Info_ValueForKey(info_buf, "addr"), "000.000.000.000", 15) == 0)
            goto reject;

        /* show empty filter */
        if (!*(byte *)((byte *)ui_browserShowEmpty + 8) && clients == 0)
            goto reject;

        /* show full filter */
        if (!*(byte *)((byte *)ui_browserShowFull + 8)) {
            if (clients == atoi(Info_ValueForKey(info_buf, "sv_maxclients")))
                goto reject;
        }

        /* show password filter */
        if (!*(byte *)((byte *)ui_browserShowPassword + 8)) {
            if (atoi(Info_ValueForKey(info_buf, "pswrd")) != 0)
                goto reject;
        }

        /* show no password filter */
        if (!*(byte *)((byte *)ui_browserShowNoPassword + 8)) {
            if (atoi(Info_ValueForKey(info_buf, "pswrd")) == 0)
                goto reject;
        }

        /* show pure filter */
        if (*(byte *)((byte *)ui_browserShowPure + 8)) {
            if (atoi(Info_ValueForKey(info_buf, "pure")) == 0)
                goto reject;
        }

        /* show dedicated filter */
        if (*(byte *)((byte *)ui_browserShowDedicated + 8)) {
            if ((unsigned)(atoi(Info_ValueForKey(info_buf, "hw")) - 1) > 2)
                goto reject;
        }

        /* mod filter */
        if (*(int *)((byte *)ui_browserMod + 8) >= 0) {
            if (atoi(Info_ValueForKey(info_buf, "mod")) != *(int *)((byte *)ui_browserMod + 8))
                goto reject;
        }

        /* friendly fire filter */
        if (*(int *)((byte *)ui_browserFriendlyfire + 8) >= 0) {
            if (atoi(Info_ValueForKey(info_buf, "ff")) != *(int *)((byte *)ui_browserFriendlyfire + 8))
                goto reject;
        }

        /* killcam filter */
        if (*(int *)((byte *)ui_browserKillcam + 8) >= 0) {
            if (atoi(Info_ValueForKey(info_buf, "kc")) != *(int *)((byte *)ui_browserKillcam + 8))
                goto reject;
        }

        /* game type filter */
        {
            int joinGTIdx = *(int *)((byte *)ui_joinGameType + 8);
            const char *joinGTName = *(const char **)((byte *)&sharedUiInfo + 4692 + joinGTIdx * 8);
            if (joinGTName[0] != '\0') {
                const char *joinGTShort = *(const char **)((byte *)&sharedUiInfo + 4688 + joinGTIdx * 8);
                if (I_stricmp(Info_ValueForKey(info_buf, "gametype"), joinGTShort) != 0)
                    goto reject;
            }
        }

        /* server filter type */
        if (ui_serverFilterType > 0) {
            const char *filterBaseName = *(const char **)((byte *)serverFilters + ui_serverFilterType * 8 + 4);
            if (I_stricmp(Info_ValueForKey(info_buf, "game"), filterBaseName) != 0)
                goto reject;
        }

        /* favorites: remove duplicate */
        if (*(int *)((byte *)ui_netSource + 8) == 2) {
            UI_RemoveDuplicateFromFavorites(i);
        }

        /* binary insert into sorted position */
        UI_BinaryInsertServer(i);

        /* mark clean if ping > 0 */
        if (ping > 0) {
            LAN_MarkServerDirty(*(int *)((byte *)ui_netSource + 8), i, 0);
            numclean++;
        }
        continue;

reject:
        LAN_MarkServerDirty(*(int *)((byte *)ui_netSource + 8), i, 0);
    }

    *(int *)((byte *)&sharedUiInfo + 28632) = *(int *)((byte *)uiInfo + 4);
}


/* Helper: check if key is an action key (mouse1/mouse2/enter/0xBF) */
static int UI_IsActionKey(int key)
{
    return (key == 0xc8 || key == 0xc9 || key == 0xd || key == 0xbf);
}

/* Helper: update map visibility flags based on game type index */
static int UI_UpdateMapVisibility(int listIndex)
{
    int numMaps = *(int *)((byte *)&sharedUiInfo + 4944);
    int i, visCount = 0;
    byte *p = (byte *)&sharedUiInfo;

    for (i = 0; i < numMaps; i++) {
        *(int *)(p + 0x13f4 + i * 0xa4) = 0;
        if ((*(int *)(p + 0x1368 + i * 0xa4) >> listIndex) & 1) {
            visCount++;
            *(int *)(p + 0x13f4 + i * 0xa4) = 1;
        }
    }
    return visCount;
}

/* Helper: find first visible map and select it */
static void UI_SelectFirstVisibleMap(int currentMapIdx)
{
    int numMaps = *(int *)((byte *)&sharedUiInfo + 4944);
    int i, firstVisible = -1;
    byte *p = (byte *)&sharedUiInfo;

    /* check if current map is still visible */
    if (currentMapIdx >= 0 && currentMapIdx < numMaps) {
        int off = currentMapIdx * 0xa4;
        if (*(int *)(p + 5108 + off) != 0) {
            /* map is still visible - find its list index */
            int listIdx = 0;
            for (i = 0; i < numMaps; i++) {
                if (*(int *)(p + 0x13f4 + i * 0xa4) != 0) {
                    if (i == currentMapIdx)
                        break;
                    listIdx++;
                }
            }
            if (i >= numMaps)
                listIdx = 0;

            Menu_SetFeederSelection(uiInfo, 0, 4, listIdx, "createserver_maps");
            UI_SelectCurrentMap();
            return;
        }
    }

    /* find first visible map */
    if (numMaps > 0) {
        if (*(int *)(p + 5108) != 0) {
            firstVisible = 0;
        } else {
            for (i = 1; i < numMaps; i++) {
                if (*(int *)(p + 0x1498 + (i - 1) * 0xa4) != 0) {
                    firstVisible = i;
                    break;
                }
            }
        }
    }

    if (firstVisible >= 0) {
        Menu_SetFeederSelection(uiInfo, 0, 4, 0, "createserver_maps");
        Dvar_SetInt(ui_currentNetMap, firstVisible);
    }

    UI_SelectCurrentMap();
}

/* line 1475 */
qboolean UI_OwnerDrawHandleKey(int ownerDraw, int flags, float *special, int key)
{
    int idx;

    idx = ownerDraw - 0xcd;
    if ((unsigned)idx > 0x30)
        return 0;

    switch (ownerDraw) {
    case 0xcd: /* 205: map preview */
        if (!UI_IsActionKey(key))
            return 0;
        {
            int listIndex = *(int *)((byte *)ui_netGameType + 8);
            int oldVisCount = UI_UpdateMapVisibility(listIndex);
            int newGT, newVisCount;

            if (key == 0xc9) {
                /* prev game type */
                newGT = *(int *)((byte *)ui_gametype + 8) - 1;
                if (newGT == 2) newGT = 1;
                else if (newGT <= 1) newGT = *(int *)((byte *)&sharedUiInfo + 4424) - 1;
            } else {
                /* next game type */
                newGT = *(int *)((byte *)ui_gametype + 8) + 1;
                if (newGT >= *(int *)((byte *)&sharedUiInfo + 4424)) newGT = 1;
                else if (newGT == 2) newGT = 3;
            }

            Dvar_SetInt(ui_gametype, newGT);
            listIndex = *(int *)((byte *)ui_netGameType + 8);
            newVisCount = UI_UpdateMapVisibility(listIndex);

            if (newVisCount != oldVisCount) {
                Dvar_SetInt(ui_currentMap, 0);
            }
        }
        return 1;

    case 0xdc: /* 220: net source */
        if (!UI_IsActionKey(key))
            return 0;
        {
            int nextNetSource;
            if (key == 0xc9) {
                /* prev */
                int cur = *(int *)((byte *)ui_netSource + 8);
                nextNetSource = (cur == 0) ? 2 : cur - 1;
            } else {
                /* next */
                nextNetSource = *(int *)((byte *)ui_netSource + 8) + 1;
                if (nextNetSource == 3) nextNetSource = 0;
            }

            UI_BuildServerDisplayList(1);
            Dvar_SetInt(ui_netSource, nextNetSource);
            if (*(int *)((byte *)ui_netSource + 8) != 1) {
                __asm__ __volatile__ (
                    "movl $1, %%eax\n"
                    "calll UI_StartServerRefresh\n"
                    :
                    :
                    : "eax", "ecx", "edx", "memory"
                );
                UI_BuildServerDisplayList(1);
            }
        }
        return 0;

    case 0xde: /* 222: server filter */
        if (!UI_IsActionKey(key))
            return 0;
        {
            int filterType;
            if (key == 0xc9)
                filterType = ui_serverFilterType - 1;
            else
                filterType = ui_serverFilterType + 1;

            ui_serverFilterType = filterType;

            if (filterType > 0 || filterType < 0)
                ui_serverFilterType = 0;

            UI_BuildServerDisplayList(1);
        }
        return 0;

    case 0xf4: /* 244: net game type */
        if (!UI_IsActionKey(key))
            return 0;
        {
            int newVal;
            if (key == 0xc9) {
                /* prev */
                int cur = *(int *)((byte *)ui_netGameType + 8);
                newVal = (cur == 0) ? *(int *)((byte *)&sharedUiInfo + 4424) : cur;
                newVal--;
            } else {
                /* next */
                newVal = *(int *)((byte *)ui_netGameType + 8) + 1;
                if (newVal == *(int *)((byte *)&sharedUiInfo + 4424)) newVal = 0;
            }

            Dvar_SetInt(ui_netGameType, newVal);
            Dvar_SetString(ui_netGameTypeName, *(const char **)((byte *)&sharedUiInfo + 4428 + *(int *)((byte *)ui_netGameType + 8) * 8));

            UI_UpdateMapVisibility(*(int *)((byte *)ui_netGameType + 8));
            UI_SelectFirstVisibleMap(*(int *)((byte *)ui_currentNetMap + 8));
        }
        return 1;

    case 0xfd: /* 253: join game type */
        if (!UI_IsActionKey(key))
            return 0;
        {
            int newVal;
            if (key == 0xc9) {
                /* prev */
                int cur = *(int *)((byte *)ui_joinGameType + 8);
                newVal = (cur == 0) ? *(int *)((byte *)&sharedUiInfo + 4684) : cur;
                newVal--;
            } else {
                /* next */
                newVal = *(int *)((byte *)ui_joinGameType + 8) + 1;
                if (newVal == *(int *)((byte *)&sharedUiInfo + 4684)) newVal = 0;
            }

            Dvar_SetInt(ui_joinGameType, newVal);
            UI_BuildServerDisplayList(1);
        }
        return 1;

    default:
        return 0;
    }
}


/* line 3567 */
__attribute__((naked))
const char * UI_FeederItemText(float feederID, int index, int column, MaterialHandle *handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3567 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* feederID */
        "movss %xmm0, -0x1c(%ebp)\n" /* feederID */
        "movl 0xc(%ebp), %esi\n" /* index */
        "movl 0x10(%ebp), %ebx\n" /* column */
        "movl 0x14(%ebp), %edi\n" /* handle */
        /* { scope 1 */
        "movl $0, (%edi)\n" /* line 3579 | handle */
        "ucomiss lit4_002ed608, %xmm0\n" /* line 3581 | 4.0f */
        "jp .Lf152ab0_00152b20\n"
        "jne .Lf152ab0_00152b20\n"
        /* { scope 2 */
        "movl sharedUiInfo+4944, %ebx\n" /* line 3511 */
        "testl %ebx, %ebx\n"
        "jle .Lf152ab0_00152b11\n"
        /* } scope */
        "xorl %ecx, %ecx\n" /* line 3581 */
        "xorl %edx, %edx\n"
        "movl $sharedUiInfo, %eax\n"
        /* { scope 2 */
        ".Lf152ab0_00152af0:\n"
        "movl 0x13f4(%eax), %edi\n" /* line 3513 | i */
        "testl %edi, %edi\n" /* i */
        "je .Lf152ab0_00152b05\n"
        "cmpl %esi, %ecx\n" /* line 3515 */
        "je .Lf152ab0_00152f30\n"
        "addl $1, %ecx\n" /* line 3522 */
        ".Lf152ab0_00152b05:\n"
        "addl $1, %edx\n" /* line 3511 */
        "addl $0xa4, %eax\n"
        "cmpl %edx, %ebx\n"
        "jne .Lf152ab0_00152af0\n"
        /* } scope */
        ".Lf152ab0_00152b11:\n"
        "movl $str_002157b8, %ebx\n" /* line 3778 | pszMap */
        /* } scope */
        ".Lf152ab0_00152b16:\n"
        "movl %ebx, %eax\n" /* line 3783 | pszMap */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf152ab0_00152b20:\n"
        "movss -0x1c(%ebp), %xmm0\n" /* line 3588 | feederID */
        "ucomiss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "je .Lf152ab0_00152b8e\n"
        ".Lf152ab0_00152b2e:\n"
        "ucomiss lit4_002ed8c0, %xmm0\n" /* line 3675 | 13.0f */
        "je .Lf152ab0_00152b61\n"
        ".Lf152ab0_00152b37:\n"
        "ucomiss lit4_002ed7fc, %xmm0\n" /* line 3688 | 7.0f */
        "jne .Lf152ab0_00152c82\n"
        "jp .Lf152ab0_00152c82\n"
        "testl %esi, %esi\n" /* line 3690 | index */
        "js .Lf152ab0_00152b11\n"
        "cmpl sharedUiInfo+68, %esi\n" /* index */
        "jge .Lf152ab0_00152b11\n"
        ".Lf152ab0_00152b56:\n"
        "shll $5, %esi\n" /* line 3767 | index */
        "leal sharedUiInfo+72(%esi), %ebx\n" /* index, pszMap */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152b61:\n"
        "jp .Lf152ab0_00152b37\n" /* line 3675 */
        "testl %esi, %esi\n" /* line 3677 | index */
        "js .Lf152ab0_00152b11\n"
        "cmpl sharedUiInfo+113128, %esi\n" /* index */
        "jge .Lf152ab0_00152b11\n"
        "cmpl $3, %ebx\n" /* line 3679 | pszMap */
        "ja .Lf152ab0_00152b11\n"
        "leal (%ebx, %esi, 4), %eax\n" /* line 3681 | pszMap */
        "movl sharedUiInfo+109864(, %eax, 4), %ebx\n" /* pszMap */
        "cmpb $0x40, (%ebx)\n" /* pszMap */
        "jne .Lf152ab0_00152b16\n"
        "leal 1(%ebx), %eax\n" /* line 3682 | pszMap */
        "movl %eax, 8(%ebp)\n" /* feederID */
        "jmp .Lf152ab0_00152cd1\n"
        ".Lf152ab0_00152b8e:\n"
        "jp .Lf152ab0_00152b2e\n" /* line 3588 */
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf152ab0_00152bba\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "jne .Lf152ab0_00152f42\n"
        ".Lf152ab0_00152bba:\n"
        "testl %esi, %esi\n" /* line 3591 | index */
        "js .Lf152ab0_00152b11\n"
        "cmpl sharedUiInfo+108660, %esi\n" /* index */
        "jge .Lf152ab0_00152b11\n"
        /* { scope 2 */
        "cmpl lastColumn, %ebx\n" /* line 3598 | column */
        "je .Lf152ab0_00152d1a\n"
        ".Lf152ab0_00152bda:\n"
        "movl $0x400, 0xc(%esp)\n" /* line 3600 */
        "movl $info, 8(%esp)\n"
        "movl sharedUiInfo+28660(, %esi, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerInfo\n"
        "movl %ebx, lastColumn\n" /* line 3601 | column */
        "movl uiInfo, %eax\n" /* line 3602 */
        "movl 4(%eax), %eax\n"
        "movl %eax, lastTime\n"
        ".Lf152ab0_00152c18:\n"
        "movl $str_002a90f4, 4(%esp)\n" /* line 3604 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "cmpl $9, %ebx\n" /* line 3610 | column */
        "jbe .Lf152ab0_00152cdd\n"
        "movss -0x1c(%ebp), %xmm0\n" /* feederID */
        /* } scope */
        ".Lf152ab0_00152c42:\n"
        "ucomiss lit4_002ed8b8, %xmm0\n" /* line 3775 | 24.0f */
        "jne .Lf152ab0_00152b11\n"
        "jp .Lf152ab0_00152b11\n"
        "testl %esi, %esi\n" /* line 3777 | index */
        "js .Lf152ab0_00152b11\n"
        "movl uiInfo, %edx\n"
        "cmpl 0x280(%edx), %esi\n" /* index */
        "jge .Lf152ab0_00152b11\n"
        "movl 0x388(%edx, %esi, 4), %eax\n" /* line 3778 */
        "movl 0x284(%edx, %eax, 4), %ebx\n" /* pszMap */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152c82:\n"
        "ucomiss lit4_002ed728, %xmm0\n" /* line 3696 | 9.0f */
        "je .Lf152ab0_00152ce4\n"
        ".Lf152ab0_00152c8b:\n"
        "ucomiss lit4_002ed694, %xmm0\n" /* line 3762 | 20.0f */
        "jne .Lf152ab0_00152c42\n"
        "jp .Lf152ab0_00152c42\n"
        "testl %esi, %esi\n" /* line 3764 | index */
        "js .Lf152ab0_00152b11\n"
        "cmpl sharedUiInfo+68, %esi\n" /* index */
        "jge .Lf152ab0_00152b11\n"
        "subl $1, %ebx\n" /* line 3766 | pszMap */
        "je .Lf152ab0_00152b56\n"
        "movl sharedUiInfo+4168(, %esi, 4), %eax\n" /* line 3768 */
        "movl %eax, (%esp)\n"
        "calll CL_IsPlayerMuted\n"
        "testb %al, %al\n"
        "je .Lf152ab0_00152b11\n"
        "movl $str_002aa8b0, 8(%ebp)\n" /* line 3769 | feederID */
        /* } scope */
        ".Lf152ab0_00152cd1:\n"
        "addl $0x3c, %esp\n" /* line 3783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp UI_SafeTranslateString\n" /* line 3769 */
        /* { scope 2 */
        ".Lf152ab0_00152cdd:\n"
        "jmpl *.Ljt_152ab0_0(, %ebx, 4)\n" /* line 3610 */
        /* } scope */
        ".Lf152ab0_00152ce4:\n"
        "jp .Lf152ab0_00152c8b\n" /* line 3696 */
        "testl %esi, %esi\n" /* line 3698 | index */
        "js .Lf152ab0_00152b11\n"
        "cmpl sharedUiInfo+26484, %esi\n" /* index */
        "jge .Lf152ab0_00152b11\n"
        "movl sharedUiInfo+25976(, %esi, 8), %ebx\n" /* line 3700 | pszMap */
        "testl %ebx, %ebx\n" /* pszMap */
        "je .Lf152ab0_00152d0e\n"
        "cmpb $0, (%ebx)\n" /* pszMap */
        "jne .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152d0e:\n"
        "movl sharedUiInfo+25972(, %esi, 8), %ebx\n" /* line 3706 | pszMap */
        "jmp .Lf152ab0_00152b16\n"
        /* { scope 2 */
        ".Lf152ab0_00152d1a:\n"
        "movl uiInfo, %eax\n" /* line 3598 */
        "movl 4(%eax), %eax\n"
        "addl $0x1388, %eax\n"
        "cmpl lastTime, %eax\n"
        "jge .Lf152ab0_00152c18\n"
        "jmp .Lf152ab0_00152bda\n"
        ".Lf152ab0_00152d38:\n"
        "movl $str_002a9cf4, 4(%esp)\n" /* line 3631 */
        ".Lf152ab0_00152d40:\n"
        "movl $info, (%esp)\n" /* line 3626 */
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl $str_002aa898, %ebx\n" /* column */
        "testl %eax, %eax\n"
        "movl $str_002157b8, %eax\n"
        "cmovel %eax, %ebx\n" /* column */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152d68:\n"
        "testl %eax, %eax\n" /* line 3664 */
        "jle .Lf152ab0_00152f5d\n"
        "movl $str_002a90f4, 0xc(%ebp)\n" /* line 3670 | index */
        ".Lf152ab0_00152d77:\n"
        "movl $info, 8(%ebp)\n" /* line 3660 | feederID */
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3783 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp Info_ValueForKey\n" /* line 3660 */
        ".Lf152ab0_00152d8a:\n"
        "movl $str_002a9af0, 4(%esp)\n" /* line 3614 */
        "jmp .Lf152ab0_00152d40\n"
        ".Lf152ab0_00152d94:\n"
        "movl $str_002a70dc, 4(%esp)\n" /* line 3656 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, %ebx\n" /* pszMap */
        "movl $str_002a8a54, 4(%esp)\n" /* "clients" */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %ebx, 0x10(%esp)\n" /* pszMap */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002aa8a8, 8(%esp)\n" /* "%s (%s)" */
        "movl $0x20, 4(%esp)\n"
        "movl $clientBuff, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $clientBuff, %ebx\n" /* pszMap */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152dec:\n"
        "movl $str_002aa884, 4(%esp)\n" /* line 3659 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "testl %eax, %eax\n"
        "je .Lf152ab0_00152e21\n"
        "movl $str_002aa884, 4(%esp)\n" /* "gametype" */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf152ab0_00152f24\n"
        /* } scope */
        ".Lf152ab0_00152e21:\n"
        "movl $str_0022292c, %ebx\n" /* line 3778 | pszMap */
        "jmp .Lf152ab0_00152b16\n"
        /* { scope 2 */
        ".Lf152ab0_00152e2b:\n"
        "movl $str_0021ec00, 4(%esp)\n" /* line 3637 */
        "jmp .Lf152ab0_00152d40\n"
        ".Lf152ab0_00152e38:\n"
        "movl $str_002aa870, 4(%esp)\n" /* line 3626 */
        "jmp .Lf152ab0_00152d40\n"
        ".Lf152ab0_00152e45:\n"
        "testl %eax, %eax\n" /* line 3644 */
        "jle .Lf152ab0_00152f67\n"
        "movl $str_002aa89c, 4(%esp)\n" /* line 3650 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x14, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $clientBuff, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $clientBuff, %ebx\n" /* column */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152e83:\n"
        "movl $str_002a7124, 4(%esp)\n" /* line 3654 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, %ebx\n" /* pszMap */
        /* { scope 3 */
        /* { scope 4 */
        "movl sharedUiInfo+4944, %eax\n" /* line 791 */
        "testl %eax, %eax\n"
        "jle .Lf152ab0_00152b16\n"
        "xorl %edi, %edi\n" /* i */
        "movl $sharedUiInfo, %esi\n"
        "jmp .Lf152ab0_00152ec4\n"
        ".Lf152ab0_00152eaf:\n"
        "addl $1, %edi\n" /* i */
        "addl $0xa4, %esi\n"
        "cmpl sharedUiInfo+4944, %edi\n" /* i */
        "jge .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152ec4:\n"
        "movl 0x1358(%esi), %eax\n" /* line 793 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf152ab0_00152eaf\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 794 | i */
        "leal (%edi, %eax, 8), %eax\n" /* i */
        "movl sharedUiInfo+4948(, %eax, 4), %ebx\n"
        "jmp .Lf152ab0_00152b16\n"
        /* } scope */
        /* } scope */
        ".Lf152ab0_00152eec:\n"
        "movl $str_002aa878, 4(%esp)\n" /* line 3619 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "cmpl $7, %eax\n" /* line 3620 */
        "ja .Lf152ab0_00152b11\n"
        "movl sharedUiInfo+25940(, %eax, 4), %eax\n" /* line 3622 */
        "movl %eax, (%edi)\n" /* handle */
        "movl $str_002157b8, %ebx\n" /* column */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152f24:\n"
        "movl $str_002aa884, 0xc(%ebp)\n" /* line 3660 | index */
        "jmp .Lf152ab0_00152d77\n"
        /* } scope */
        /* { scope 2 */
        ".Lf152ab0_00152f30:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 3518 */
        "leal (%edx, %eax, 8), %eax\n"
        "movl sharedUiInfo+4948(, %eax, 4), %ebx\n"
        "jmp .Lf152ab0_00152b16\n"
        /* } scope */
        ".Lf152ab0_00152f42:\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf152ab0_00152bba\n"
        /* { scope 2 */
        ".Lf152ab0_00152f5d:\n"
        "movl $str_002228e0, %ebx\n" /* line 3664 | pszMap */
        "jmp .Lf152ab0_00152b16\n"
        ".Lf152ab0_00152f67:\n"
        "movl $str_002aa858, 0xc(%ebp)\n" /* line 3646 | index */
        "jmp .Lf152ab0_00152d77\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_152ab0_0:\n"
        ".long .Lf152ab0_00152d8a\n"
        ".long .Lf152ab0_00152eec\n"
        ".long .Lf152ab0_00152e45\n"
        ".long .Lf152ab0_00152e83\n"
        ".long .Lf152ab0_00152d94\n"
        ".long .Lf152ab0_00152dec\n"
        ".long .Lf152ab0_00152e2b\n"
        ".long .Lf152ab0_00152e38\n"
        ".long .Lf152ab0_00152d38\n"
        ".long .Lf152ab0_00152d68\n"
        ".text\n"
    );
}

/* line 368 */
__attribute__((naked))
void UI_DrawRect(float x, float y, float width, float height, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 368 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x1c(%ebp), %edi\n" /* vertAlign */
        "movl 0x24(%ebp), %esi\n" /* color */
        "movl sharedUiInfo+32, %eax\n" /* line 356 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* width */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movl sharedUiInfo+32, %eax\n" /* line 357 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* width */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "addss 0x14(%ebp), %xmm0\n" /* height */
        "subss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movl sharedUiInfo+32, %eax\n" /* line 349 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* height */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "movl sharedUiInfo+32, %eax\n" /* line 350 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm0\n" /* height */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "addss 0x10(%ebp), %xmm0\n" /* width */
        "movss %xmm0, 8(%ebp)\n" /* x */
        "subss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "addl $0x3c, %esp\n" /* line 372 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 829 */
int UI_OwnerDrawWidth(int ownerDraw, FontHandle font, float scale)
{
    const char *s = NULL;

    switch (ownerDraw) {
    case 0x27: /* 39: game type */
        s = CG_GameTypeString();
        break;
    case 0x32: /* 50: killer text */
        s = CG_GetKillerText();
        break;
    case 0xcd: /* 205: game type name */
        s = *(const char **)((byte *)&sharedUiInfo + 4432 + *(int *)((byte *)ui_gametype + 8) * 8);
        break;
    case 0xdc: { /* 220: net source */
        int netSrcVal = *(int *)((byte *)ui_netSource + 8);
        if (netSrcVal > *(int *)((byte *)&sharedUiInfo + 4684)) {
            Dvar_SetInt(ui_netSource, 0);
            netSrcVal = *(int *)((byte *)ui_netSource + 8);
        }
        s = SEH_LocalizeTextMessage(va("EXE_NETSOURCE\x14%s", netSources[netSrcVal]), "net source", 0);
        break;
    }
    case 0xde: { /* 222: server filter */
        int filterType = 0;
        if ((unsigned int)ui_serverFilterType < 2)
            filterType = ui_serverFilterType;
        ui_serverFilterType = filterType;
        s = SEH_LocalizeTextMessage(va("EXE_SERVERFILTER\x14%s", serverFilters[filterType].description), "server filter", 0);
        break;
    }
    case 0xf7: /* 247: last server refresh */
        s = Dvar_GetVariantString(va("ui_lastServerRefresh_%i", *(int *)((byte *)ui_netSource + 8)));
        break;
    case 0xfa: /* 250: key bind pending */
        if (Display_KeyBindPending())
            s = UI_SafeTranslateString("EXE_KEYWAIT");
        else
            s = UI_SafeTranslateString("EXE_KEYCHANGE");
        break;
    default:
        return 0;
    }

    if (!s)
        return 0;

    {
        float actualScale = CL_NormalizedTextScale(font, scale);
        return (int)((float)CL_TextWidth(s, 0, font) * actualScale);
    }
}

/* line 1190 */
__attribute__((naked))
void UI_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, float special, FontHandle font, float scale, vec_t *color, MaterialHandle material, int textStyle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1190 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x13c, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss 0xc(%ebp), %xmm1\n" /* y */
        "movl 0x10(%ebp), %edi\n" /* w */
        "movl 0x1c(%ebp), %esi\n" /* vertAlign */
        "movl 0x28(%ebp), %ebx\n" /* ownerDraw */
        /* { scope 1 */
        "movl imp_cl, %eax\n" /* line 1194 */
        "movl (%eax), %eax\n"
        "cmpb $0, 9(%eax)\n"
        "jne .Lf1532d0_001533b7\n"
        ".Lf1532d0_00153300:\n"
        "addss 0x20(%ebp), %xmm0\n" /* line 1197 | text_x */
        "movss %xmm0, -0x50(%ebp)\n" /* rect */
        "addss 0x24(%ebp), %xmm1\n" /* line 1198 | text_y */
        "movss %xmm1, -0x4c(%ebp)\n"
        "movl %edi, -0x48(%ebp)\n" /* line 1199 | w */
        "movss 0x14(%ebp), %xmm0\n" /* line 1200 | h */
        "movss %xmm0, -0x44(%ebp)\n"
        "movl 0x18(%ebp), %eax\n" /* line 1201 | horzAlign */
        "movl %eax, -0x40(%ebp)\n"
        "movl %esi, -0x3c(%ebp)\n" /* line 1202 | vertAlign */
        "leal -0xcd(%ebx), %eax\n" /* line 1204 | ownerDraw */
        "cmpl $0x41, %eax\n"
        "ja .Lf1532d0_001533ac\n"
        "jmpl *.Ljt_1532d0_0(, %eax, 4)\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_0015333c:\n"
        "movl imp_sv_voice, %eax\n" /* line 1058 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1532d0_001533ac\n"
        "movl imp_cl_voice, %eax\n"
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf1532d0_001533ac\n"
        "calll IsTalking\n"
        "testb %al, %al\n"
        "je .Lf1532d0_001533ac\n"
        "movl $7, 4(%esp)\n" /* line 1061 */
        "movl $str_002aa96c, (%esp)\n" /* "voice_on" */
        "calll CL_RegisterMaterialNoMip\n"
        ".Lf1532d0_00153373:\n"
        "movl %eax, 0x1c(%esp)\n" /* line 1063 */
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x18(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        ".Lf1532d0_00153385:\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        /* } scope */
        ".Lf1532d0_001533ac:\n"
        "addl $0x13c, %esp\n" /* line 1272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1532d0_001533b7:\n"
        "movl 0x48(%ebp), %eax\n" /* line 1195 | textStyle */
        "movl %eax, 0x40(%esp)\n"
        "movl 0x44(%ebp), %edx\n" /* material */
        "movl %edx, 0x3c(%esp)\n"
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, 0x38(%esp)\n"
        "movss 0x3c(%ebp), %xmm2\n" /* scale */
        "movss %xmm2, 0x34(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 0x30(%esp)\n"
        "movss 0x34(%ebp), %xmm2\n" /* special */
        "movss %xmm2, 0x2c(%esp)\n"
        "movl 0x30(%ebp), %eax\n" /* align */
        "movl %eax, 0x28(%esp)\n"
        "movl 0x2c(%ebp), %edx\n" /* ownerDrawFlags */
        "movl %edx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n" /* ownerDraw */
        "movss 0x24(%ebp), %xmm2\n" /* text_y */
        "movss %xmm2, 0x1c(%esp)\n"
        "movss 0x20(%ebp), %xmm2\n" /* text_x */
        "movss %xmm2, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n" /* vertAlign */
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm2\n" /* h */
        "movss %xmm2, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* w */
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm0, -0xd8(%ebp)\n"
        "movss %xmm1, -0xe8(%ebp)\n"
        "calll CG_OwnerDraw\n"
        "movss -0xe8(%ebp), %xmm1\n"
        "movss -0xd8(%ebp), %xmm0\n"
        "jmp .Lf1532d0_00153300\n"
        ".Lf1532d0_00153460:\n"
        "leal -0x50(%ebp), %eax\n" /* line 727 | rect */
        "movl $1, %ecx\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "calll UI_DrawMapPreview\n"
        "jmp .Lf1532d0_001533ac\n"
        ".Lf1532d0_0015347a:\n"
        "cmpl $-2, sharedUiInfo+27524\n" /* line 683 */
        "jle .Lf1532d0_001533ac\n"
        "movl $0xa, 0x14(%esp)\n" /* line 685 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl sharedUiInfo+27520, %eax\n"
        "movl sharedUiInfo+26492(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CIN_PlayCinematic\n"
        "movl %eax, sharedUiInfo+27524\n"
        "testl %eax, %eax\n" /* line 686 */
        "js .Lf1532d0_00153c21\n"
        "movl %eax, (%esp)\n" /* line 688 */
        "calll CIN_RunCinematic\n"
        "cvttss2si -0x44(%ebp), %eax\n" /* line 689 */
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvttss2si -0x50(%ebp), %eax\n" /* rect */
        "movl %eax, 4(%esp)\n"
        "movl sharedUiInfo+27524, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CIN_SetExtents\n"
        "movl sharedUiInfo+27524, %eax\n" /* line 690 */
        "movl %eax, (%esp)\n"
        "calll CIN_DrawCinematic\n"
        "jmp .Lf1532d0_001533ac\n"
        ".Lf1532d0_0015351b:\n"
        "leal -0x50(%ebp), %eax\n" /* line 1253 | rect */
        "movl %eax, (%esp)\n"
        "calll UI_DrawRecordLevel\n"
        "jmp .Lf1532d0_001533ac\n"
        ".Lf1532d0_0015352b:\n"
        "leal -0x10b(%ebx), %edi\n" /* line 1263 | ownerDraw, w */
        "xorl %esi, %esi\n" /* vertAlign */
        "xorl %ebx, %ebx\n" /* ownerDraw */
        "jmp .Lf1532d0_00153546\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        /* { scope 3 */
        /* { scope 4: convArgs, tempString */
        ".Lf1532d0_00153537:\n"
        "addl $1, %esi\n" /* line 1082 | talker */
        ".Lf1532d0_0015353a:\n"
        "addl $1, %ebx\n" /* line 1076 | replaceInt */
        "cmpl $0x40, %ebx\n" /* replaceInt */
        "je .Lf1532d0_001533ac\n"
        ".Lf1532d0_00153546:\n"
        "movl %ebx, (%esp)\n" /* line 1078 | replaceInt */
        "calll CL_IsPlayerTalking\n"
        "testb %al, %al\n"
        "je .Lf1532d0_0015353a\n"
        "cmpl %esi, %edi\n" /* line 1080 | talker */
        "jne .Lf1532d0_00153537\n"
        /* } scope */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1125 | material */
        "js .Lf1532d0_001533ac\n"
        "calll UI_BuildPlayerList\n" /* line 1129 */
        "xorl %edi, %edi\n" /* num */
        "movl $sharedUiInfo, %eax\n"
        "jmp .Lf1532d0_0015357b\n"
        /* { scope 3 */
        ".Lf1532d0_0015356c:\n"
        "addl $1, %edi\n" /* line 1093 */
        "addl $4, %eax\n"
        "cmpl $0x40, %edi\n"
        "je .Lf1532d0_00153c30\n"
        ".Lf1532d0_0015357b:\n"
        "cmpl %ebx, 0x1048(%eax)\n" /* line 1095 | replaceInt */
        "jne .Lf1532d0_0015356c\n"
        /* } scope */
        ".Lf1532d0_00153583:\n"
        "movl $7, 4(%esp)\n" /* line 1133 */
        "movl $str_002aa96c, (%esp)\n" /* "voice_on" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, %ebx\n" /* clientNum */
        /* { scope 3 */
        "movss 0x3c(%ebp), %xmm0\n" /* line 388 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0xbc(%ebp)\n" /* actualScale */
        "movl 0x38(%ebp), %edx\n" /* line 389 | font */
        "movl %edx, (%esp)\n"
        "calll CL_TextHeight\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl %ebx, 0x1c(%esp)\n" /* line 1136 | clientNum */
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 1137 | talker */
        "mulss -0xbc(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movl 0x48(%ebp), %edx\n" /* textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movaps %xmm2, %xmm1\n"
        "addss -0x4c(%ebp), %xmm1\n"
        "movss -0x44(%ebp), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0x50(%ebp), %xmm0\n" /* rect */
        "addss -0x48(%ebp), %xmm0\n"
        "addss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "shll $5, %edi\n" /* num */
        "leal sharedUiInfo+72(%edi), %eax\n" /* num */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf1532d0_001533ac\n"
        /* } scope */
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_00153696:\n"
        "movl ui_gametype, %eax\n" /* line 636 */
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4432(, %eax, 8), %eax\n"
        "cmpb $0, (%eax)\n"
        "movl $str_002a9d60, %edx\n" /* "EXE_ALL" */
        "cmovel %edx, %eax\n"
        "movl %eax, (%esp)\n" /* line 640 */
        "calll UI_SafeTranslateString\n"
        "movl 0x48(%ebp), %edx\n" /* line 641 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edi\n" /* color */
        "movl %edi, 0x20(%esp)\n"
        /* } scope */
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_001536c6:\n"
        "movss 0x3c(%ebp), %xmm0\n" /* line 661 | scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x50(%ebp), %edx\n" /* rect */
        "movl %edx, 0xc(%esp)\n"
        ".Lf1532d0_001536ed:\n"
        "movl 0x38(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        /* } scope */
        "addl $0x13c, %esp\n" /* line 1272 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_0015370f:\n"
        "movl ui_netSource, %eax\n" /* line 780 */
        "movl 8(%eax), %eax\n"
        "movl netSources(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa8bc, (%esp)\n" /* "EXE_NETSOURCE%s" */
        "calll va\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002aa8d0, 4(%esp)\n" /* "net source" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl 0x48(%ebp), %edi\n" /* line 781 | textStyle */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "jmp .Lf1532d0_001536c6\n"
        /* } scope */
        ".Lf1532d0_00153759:\n"
        "movl sharedUiInfo+108680, %eax\n" /* line 734 */
        "testl %eax, %eax\n"
        "je .Lf1532d0_00153bf6\n"
        "movl %eax, 0x1c(%esp)\n" /* line 736 */
        "movl 0x40(%ebp), %edi\n" /* color */
        "movl %edi, 0x18(%esp)\n"
        "movl %esi, 0x14(%esp)\n"
        "jmp .Lf1532d0_00153385\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_0015377a:\n"
        "xorl %eax, %eax\n" /* line 769 */
        "cmpl $2, ui_serverFilterType\n"
        "cmovbl ui_serverFilterType, %eax\n"
        "movl %eax, ui_serverFilterType\n"
        "movl serverFilters(, %eax, 8), %eax\n" /* line 771 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa8dc, (%esp)\n" /* "EXE_SERVERFILTER%s" */
        "calll va\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002aa8f0, 4(%esp)\n" /* "server filter" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl 0x48(%ebp), %edx\n" /* line 772 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edi\n" /* color */
        "movl %edi, 0x20(%esp)\n"
        "jmp .Lf1532d0_001536c6\n"
        /* } scope */
        ".Lf1532d0_001537d1:\n"
        "leal -0x50(%ebp), %eax\n" /* line 727 | rect */
        "xorl %ecx, %ecx\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "calll UI_DrawMapPreview\n"
        "jmp .Lf1532d0_001533ac\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_001537e8:\n"
        "movl ui_netGameType, %edx\n" /* line 650 */
        "movl 8(%edx), %eax\n"
        "cmpl sharedUiInfo+4424, %eax\n"
        "jg .Lf1532d0_00153b91\n"
        ".Lf1532d0_001537fd:\n"
        "movl sharedUiInfo+4432(, %eax, 8), %eax\n" /* line 656 */
        ".Lf1532d0_00153804:\n"
        "cmpb $0, (%eax)\n"
        "movl $str_002a9d60, %edx\n" /* "EXE_ALL" */
        "cmovel %edx, %eax\n"
        "movl %eax, (%esp)\n" /* line 660 */
        "calll UI_SafeTranslateString\n"
        "movl 0x48(%ebp), %edi\n" /* line 661 | textStyle */
        "movl %edi, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "jmp .Lf1532d0_001536c6\n"
        /* } scope */
        ".Lf1532d0_0015382a:\n"
        "movl ui_currentNetMap, %edx\n" /* line 747 */
        "movl 8(%edx), %eax\n"
        "cmpl sharedUiInfo+4944, %eax\n"
        "jge .Lf1532d0_00153b7c\n"
        ".Lf1532d0_0015383f:\n"
        "movl sharedUiInfo+108684, %eax\n" /* line 750 */
        "testl %eax, %eax\n"
        "js .Lf1532d0_00153b44\n"
        "movl %eax, (%esp)\n" /* line 752 */
        "calll CIN_RunCinematic\n"
        "cvttss2si -0x44(%ebp), %eax\n" /* line 753 */
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si -0x48(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvttss2si -0x50(%ebp), %eax\n" /* rect */
        "movl %eax, 4(%esp)\n"
        "movl sharedUiInfo+108684, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CIN_SetExtents\n"
        "movl sharedUiInfo+108684, %eax\n" /* line 754 */
        "movl %eax, (%esp)\n"
        "calll CIN_DrawCinematic\n"
        "jmp .Lf1532d0_001533ac\n"
        ".Lf1532d0_00153897:\n"
        "calll Display_KeyBindPending\n" /* line 963 */
        "movl $str_002aa900, %edx\n" /* "EXE_KEYWAIT" */
        "testl %eax, %eax\n"
        "movl $str_002aa90c, %eax\n" /* "EXE_KEYCHANGE" */
        "cmovel %eax, %edx\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 964 | replaceInt */
        "movl -0x40(%ebp), %esi\n" /* sourceString */
        "movl -0x4c(%ebp), %edi\n"
        "movss -0x50(%ebp), %xmm0\n" /* rect */
        "movss %xmm0, -0xc0(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl 0x48(%ebp), %edx\n" /* textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n" /* replaceInt */
        "movl %esi, 0x14(%esp)\n" /* sourceString */
        "movl %edi, 0x10(%esp)\n"
        "movss -0xc0(%ebp), %xmm2\n"
        "movss %xmm2, 0xc(%esp)\n"
        "jmp .Lf1532d0_001536ed\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_00153901:\n"
        "movl ui_joinGameType, %edx\n" /* line 670 */
        "movl 8(%edx), %eax\n"
        "cmpl sharedUiInfo+4684, %eax\n"
        "jg .Lf1532d0_00153bc5\n"
        ".Lf1532d0_00153916:\n"
        "movl sharedUiInfo+4692(, %eax, 8), %eax\n" /* line 672 */
        "jmp .Lf1532d0_00153804\n"
        /* } scope */
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_00153922:\n"
        "movl sharedUiInfo+28652, %eax\n" /* line 925 */
        "testl %eax, %eax\n"
        "je .Lf1532d0_00153ac1\n"
        /* { scope 3 */
        "movl 0x40(%ebp), %edi\n" /* line 929 | color */
        "cvtss2sd (%edi), %xmm0\n"
        "movsd lit8_00307d58, %xmm1\n" /* 0.8 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* lowLight */
        "cvtss2sd 4(%edi), %xmm0\n" /* line 930 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "cvtss2sd 8(%edi), %xmm0\n" /* line 931 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "cvtss2sd 0xc(%edi), %xmm0\n" /* line 932 */
        "mulsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl uiInfo, %eax\n" /* line 933 */
        "movl 4(%eax), %ecx\n"
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll sin\n"
        "fstpl -0xf0(%ebp)\n"
        "movsd -0xf0(%ebp), %xmm0\n"
        "movsd lit8_00307ce0, %xmm1\n" /* 0.5 */
        "mulsd %xmm1, %xmm0\n"
        "addsd %xmm1, %xmm0\n"
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* newColor */
        "movl %edx, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* lowLight */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll LerpColor\n"
        "movl ui_netSource, %eax\n" /* line 934 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_WaitServerResponse\n"
        "movl %eax, -0xc4(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lf1532d0_00153be3\n"
        "movl ui_netSource, %eax\n" /* line 936 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "movl %eax, %ebx\n"
        "movl $str_002aa91c, (%esp)\n" /* line 937 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %esi\n"
        /* { scope 4: convArgs, tempString */
        /* { scope 5 */
        "cld\n" /* line 5218 */
        "movl $0xa, %ecx\n"
        "leal -0x78(%ebp), %edi\n" /* convArgs, w */
        "movl -0xc4(%ebp), %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* w */
        "movl %ebx, 8(%esp)\n" /* line 5219 | ownerDraw */
        "movl $str_00215a64, 4(%esp)\n" /* "%d" */
        "leal -0xb8(%ebp), %ebx\n" /* tempString, ownerDraw */
        "movl %ebx, (%esp)\n" /* ownerDraw */
        "calll sprintf\n"
        "movl $1, -0x78(%ebp)\n" /* line 5220 | convArgs */
        "movl %ebx, -0x74(%ebp)\n" /* line 5221 | ownerDraw */
        "leal -0x78(%ebp), %eax\n" /* line 5222 | convArgs */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* vertAlign */
        "calll UI_ReplaceConversions\n"
        "movl %eax, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf1532d0_00153a70:\n"
        "movl 0x48(%ebp), %edi\n" /* line 944 | textStyle */
        "movl %edi, 0x24(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* newColor */
        "movl %eax, 0x20(%esp)\n"
        "movss 0x3c(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x50(%ebp), %eax\n" /* rect */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x38(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf1532d0_001533ac\n"
        /* } scope */
        /* { scope 3 */
        ".Lf1532d0_00153ac1:\n"
        "movl ui_netSource, %eax\n" /* line 950 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa7b0, (%esp)\n" /* "ui_lastServerRefresh_%i" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0xb8(%ebp), %ebx\n" /* tempString, replaceInt */
        "movl %ebx, (%esp)\n" /* replaceInt */
        "calll I_strncpyz\n"
        "movl $str_002aa95c, (%esp)\n" /* line 952 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %esi\n" /* sourceString */
        /* { scope 4: convArgs, tempString */
        /* { scope 5 */
        "cld\n" /* line 5206 */
        "movl $0xa, %ecx\n"
        "xorl %edx, %edx\n"
        "leal -0x78(%ebp), %edi\n" /* convArgs, w */
        "movl %edx, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* w */
        "movl $1, -0x78(%ebp)\n" /* line 5207 | convArgs */
        "movl %ebx, -0x74(%ebp)\n" /* line 5208 | ownerDraw */
        "leal -0x78(%ebp), %eax\n" /* line 5209 | convArgs */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* vertAlign */
        "calll UI_ReplaceConversions\n"
        /* } scope */
        /* } scope */
        "movl 0x48(%ebp), %edx\n" /* line 954 | textStyle */
        "movl %edx, 0x24(%esp)\n"
        "movl 0x40(%ebp), %edi\n" /* color */
        "movl %edi, 0x20(%esp)\n"
        "jmp .Lf1532d0_001536c6\n"
        /* } scope */
        /* } scope */
        ".Lf1532d0_00153b44:\n"
        "movl sharedUiInfo+108680, %eax\n" /* line 734 */
        "testl %eax, %eax\n"
        "jne .Lf1532d0_00153373\n"
        "movl $3, 4(%esp)\n" /* line 740 */
        "movl $str_002aa05c, (%esp)\n" /* "menu/art/unknownmap" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x40(%ebp), %edi\n" /* color */
        "movl %edi, 0x18(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "jmp .Lf1532d0_00153385\n"
        ".Lf1532d0_00153b7c:\n"
        "movl $0, 4(%esp)\n" /* line 748 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "jmp .Lf1532d0_0015383f\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_00153b91:\n"
        "movl $0, 4(%esp)\n" /* line 652 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl sharedUiInfo+4428, %eax\n" /* line 653 */
        "movl %eax, 4(%esp)\n"
        "movl ui_netGameTypeName, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl ui_netGameType, %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf1532d0_001537fd\n"
        /* } scope */
        /* { scope 2: actualScale, lowLight, newColor, buff */
        ".Lf1532d0_00153bc5:\n"
        "movl $0, 4(%esp)\n" /* line 671 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl ui_joinGameType, %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf1532d0_00153916\n"
        /* } scope */
        /* { scope 2: actualScale, lowLight, newColor, buff */
        /* { scope 3 */
        ".Lf1532d0_00153be3:\n"
        "movl $str_002aa938, (%esp)\n" /* line 942 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %edx\n"
        "jmp .Lf1532d0_00153a70\n"
        /* } scope */
        /* } scope */
        ".Lf1532d0_00153bf6:\n"
        "movl $3, 4(%esp)\n" /* line 740 */
        "movl $str_002aa05c, (%esp)\n" /* "menu/art/unknownmap" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x40(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "jmp .Lf1532d0_00153385\n"
        ".Lf1532d0_00153c21:\n"
        "movl $0xfffffffe, sharedUiInfo+27524\n" /* line 694 */
        "jmp .Lf1532d0_001533ac\n"
        /* { scope 2: actualScale, lowLight, newColor, buff */
        /* { scope 3 */
        ".Lf1532d0_00153c30:\n"
        "movl $0xffffffff, %edi\n" /* line 1093 */
        "jmp .Lf1532d0_00153583\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_1532d0_0:\n"
        ".long .Lf1532d0_00153696\n"
        ".long .Lf1532d0_00153460\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_0015370f\n"
        ".long .Lf1532d0_00153759\n"
        ".long .Lf1532d0_0015377a\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001537d1\n"
        ".long .Lf1532d0_001537e8\n"
        ".long .Lf1532d0_0015382a\n"
        ".long .Lf1532d0_00153922\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_00153897\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_00153901\n"
        ".long .Lf1532d0_0015347a\n"
        ".long .Lf1532d0_00153460\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_001533ac\n"
        ".long .Lf1532d0_0015351b\n"
        ".long .Lf1532d0_0015333c\n"
        ".long .Lf1532d0_0015352b\n"
        ".long .Lf1532d0_0015352b\n"
        ".long .Lf1532d0_0015352b\n"
        ".long .Lf1532d0_0015352b\n"
        ".text\n"
    );
}

/* Case-insensitive substring search: returns 1 if charset found in str */
static int UI_StrContains(const char *str, const char *charset)
{
    const char *s;
    int ci, si, k;

    if (!charset[0])
        return str ? 1 : 0;

    for (s = str; *s; s++) {
        for (k = 0; charset[k]; k++) {
            if (s[k] == '\0')
                return 0;
            if (___toupper((signed char)charset[k]) != ___toupper((signed char)s[k]))
                break;
        }
        if (!charset[k])
            return 1; /* full match */
    }
    return 0;
}

/* Inline server count update (shared code pattern) */
static void UI_UpdateServerCount(void)
{
    int serverCount = LAN_GetServerCount(*(int *)((byte *)ui_netSource + 8));
    if (serverCount != *(int *)((byte *)&sharedUiInfo + 108664)) {
        *(int *)((byte *)&sharedUiInfo + 108664) = serverCount;
        if (*(int *)((byte *)&sharedUiInfo + 108660) != 0) {
            *(int *)((byte *)&sharedUiInfo + 28656) = -1;
            UI_BuildServerDisplayList(1);
        }
    }
}

/* line 3271 */
static void UI_BuildFindPlayerList(void)
{
    serverStatusInfo_t info;
    char infoString[0x400];
    char name[0x22];
    int i, j, statusResult;
    int *pendingFlag;
    byte *serverAddr;
    byte *hostName;
    byte *hostName2;
    byte *slotBase;
    int nextRefresh;
    const char *charset;
    int numResults;

    nextRefresh = *(int *)((byte *)uiInfo + 0x10a4);
    if (!nextRefresh)
        return;
    if (nextRefresh > *(int *)((byte *)uiInfo + 4))
        return;

    /* inline server count update */
    UI_UpdateServerCount();

    for (i = 0; i < 16; i++) {
        slotBase = (byte *)&sharedUiInfo + i * 0x8c;
        serverAddr = (byte *)&sharedUiInfo + 113140 + i * 0x8c;
        hostName = (byte *)&sharedUiInfo + 113204 + i * 0x8c;
        hostName2 = (byte *)&sharedUiInfo + 113204 + i * 0x8c;
        pendingFlag = (int *)((byte *)&sharedUiInfo + 0x1ba7c + i * 0x8c);

        if (!*pendingFlag) {
            /* not pending: clear and update */
            __asm__ __volatile__ (
                "xorl %%edx, %%edx\n"
                "movl %0, %%eax\n"
                "calll UI_GetServerStatusInfo\n"
                :
                : "r"(serverAddr)
                : "eax", "ecx", "edx", "memory"
            );
            *pendingFlag = 0;

            /* inline server count update */
            UI_UpdateServerCount();

            if (*(int *)((byte *)&sharedUiInfo + 113136) < *(int *)((byte *)&sharedUiInfo + 108660)) {
                /* need to fetch next server */
                int curServer = *(int *)((byte *)&sharedUiInfo + 113136);
                int dispServer;

                /* set timestamp */
                *(int *)((byte *)&sharedUiInfo + 0x1ba74 + i * 0x8c) = *(int *)((byte *)uiInfo + 4);

                /* get server address string */
                dispServer = *(int *)((byte *)&sharedUiInfo + 28660 + curServer * 4);
                LAN_GetServerAddressString(*(int *)((byte *)ui_netSource + 8), dispServer, (char *)serverAddr, 0x40);

                /* get server info */
                LAN_GetServerInfo(*(int *)((byte *)ui_netSource + 8), dispServer, infoString, 0x400);

                /* extract hostname */
                I_strncpyz((char *)hostName, Info_ValueForKey(infoString, "hostname"), 0x40);

                /* mark as pending */
                *pendingFlag = 1;

                /* advance to next server */
                curServer++;
                *(int *)((byte *)&sharedUiInfo + 113136) = curServer;

                /* update status string */
                numResults = *(int *)((byte *)uiInfo + 0x10a0);
                Com_sprintf((char *)((byte *)uiInfo + 0xc60 + numResults * 64), 0x40, "searching %d/%d...", curServer, numFound);
            }
            continue;
        }

        /* slot is pending: try to get server status */
        __asm__ __volatile__ (
            "movl %1, %%edx\n"
            "movl %2, %%eax\n"
            "calll UI_GetServerStatusInfo\n"
            "movl %%eax, %0\n"
            : "=r"(statusResult)
            : "r"(&info), "r"(serverAddr)
            : "eax", "ecx", "edx", "memory"
        );

        if (!statusResult) {
            /* check if pending flag is still set and not timed out */
            if (!*pendingFlag)
                continue; /* retry */

            {
                int timeoutVal = *(int *)((byte *)uiInfo + 4) - *(int *)((byte *)ui_serverStatusTimeOut + 8);
                if (*(int *)((byte *)&sharedUiInfo + 0x1ba74 + i * 0x8c) >= timeoutVal)
                    continue; /* still within timeout */
            }
            numTimeOuts++;
            continue; /* retry */
        }

        /* got server status - search for player */
        numFound++;

        if (info.numLines > 0) {
            for (j = 0; j < info.numLines; j++) {
                if (!info.lines[j][2] || info.lines[j][2][0] == '\0')
                    continue;

                I_strncpyz(name, info.lines[j][3], 0x22);
                I_CleanStr(name);

                charset = (const char *)((byte *)uiInfo + 0x4a0);

                if (name[0] == '\0')
                    continue;

                if (UI_StrContains(name, charset)) {
                    /* found a match */
                    numResults = *(int *)((byte *)uiInfo + 0x10a0);
                    if (numResults > 14) {
                        /* too many results, set num to max */
                        *(int *)((byte *)&sharedUiInfo + 113136) = *(int *)((byte *)&sharedUiInfo + 108660);
                        continue;
                    }

                    /* store result: server address and host name */
                    I_strncpyz((char *)((byte *)uiInfo + 0x860 + numResults * 64), (const char *)serverAddr, 0x40);
                    I_strncpyz((char *)((byte *)uiInfo + 0xc60 + numResults * 64), (const char *)hostName2, 0x40);
                    *(int *)((byte *)uiInfo + 0x10a0) += 1;
                    continue;
                }
            }
        }

        /* update searching status */
        Com_sprintf((char *)((byte *)uiInfo + 0xc60 + *(int *)((byte *)uiInfo + 0x10a0) * 64), 0x40, "searching %d/%d...", *(int *)((byte *)&sharedUiInfo + 113136), numFound);
        *pendingFlag = 0;

        /* check if still pending and not timed out */
        if (!*pendingFlag)
            continue; /* retry - slot cleared */

        {
            int timeoutVal = *(int *)((byte *)uiInfo + 4) - *(int *)((byte *)ui_serverStatusTimeOut + 8);
            if (*(int *)((byte *)&sharedUiInfo + 0x1ba74 + i * 0x8c) >= timeoutVal)
                continue;
        }
        numTimeOuts++;
        /* retry */
    }

    /* all 16 slots processed: check if any still pending */
    for (i = 0; i < 16; i++) {
        if (*(int *)((byte *)&sharedUiInfo + 0x1ba7c + i * 0x8c) != 0) {
            /* still pending - schedule next check */
            *(int *)((byte *)uiInfo + 0x10a4) = *(int *)((byte *)uiInfo + 4) + 25;
            return;
        }
    }

    /* all done */
    numResults = *(int *)((byte *)uiInfo + 0x10a0);
    if (numResults == 0) {
        Com_sprintf((char *)((byte *)uiInfo + 0xc60), 0x40, "no servers found");
    } else {
        const char *plural = (numResults == 2) ? str_002157b8 : "s";
        Com_sprintf((char *)((byte *)uiInfo + 0xca0 + (numResults - 1) * 64), 0x40, "%d server%s found with player %s", numResults - 1, plural, (const char *)((byte *)uiInfo + 0x4a0));
    }
    *(int *)((byte *)uiInfo + 0x10a4) = 0;
}

/* line 3388 */
static void UI_BuildServerStatus_impl(int force)
{
    int serverStatusVisible = *(int *)((byte *)uiInfo + 0x10a4);

    if (serverStatusVisible)
        return;

    if (force) {
        /* force: reset feeder selection and clear server status */
        Menu_SetFeederSelection(uiInfo, 0, 0xd, 0, 0);
        *(int *)((byte *)&sharedUiInfo + 113128) = 0;
        LAN_GetServerStatus(0, 0, 0);
    } else {
        int nextRefresh = *(int *)((byte *)&sharedUiInfo + 113132);
        if (nextRefresh == 0)
            return;
        if (nextRefresh > *(int *)((byte *)uiInfo + 4))
            return;
    }

    /* inline server count update (shared with UI_FeederCount) */
    {
        int serverCount = LAN_GetServerCount(*(int *)((byte *)ui_netSource + 8));
        if (serverCount != *(int *)((byte *)&sharedUiInfo + 108664)) {
            *(int *)((byte *)&sharedUiInfo + 108664) = serverCount;
            if (*(int *)((byte *)&sharedUiInfo + 108660) != 0) {
                *(int *)((byte *)&sharedUiInfo + 28656) = -1;
                UI_BuildServerDisplayList(1);
            }
        }
    }

    {
        int selectedServer = *(int *)((byte *)&sharedUiInfo + 28656);
        int numServers = *(int *)((byte *)&sharedUiInfo + 108660);

        if (selectedServer < 0)
            return;
        if (selectedServer > numServers)
            return;
        if (numServers == 0)
            return;

        /* call UI_GetServerStatusInfo with register args: eax=serverAddress, edx=info */
        {
            int result;
            byte *serverAddress = (byte *)&sharedUiInfo + 109736;
            byte *statusInfo = (byte *)&sharedUiInfo + 109800;
            __asm__ __volatile__ (
                "movl %1, %%edx\n"
                "movl %2, %%eax\n"
                "calll UI_GetServerStatusInfo\n"
                "movl %%eax, %0\n"
                : "=r"(result)
                : "r"(statusInfo), "r"(serverAddress)
                : "eax", "ecx", "edx", "memory"
            );
            if (result) {
                /* success: clear refresh timer and display info */
                *(int *)((byte *)&sharedUiInfo + 113132) = 0;
                __asm__ __volatile__ (
                    "xorl %%edx, %%edx\n"
                    "movl %0, %%eax\n"
                    "calll UI_GetServerStatusInfo\n"
                    :
                    : "r"(serverAddress)
                    : "eax", "ecx", "edx", "memory"
                );
            } else {
                /* failed: set retry timer */
                *(int *)((byte *)&sharedUiInfo + 113132) = *(int *)((byte *)uiInfo + 4) + 500;
            }
        }
    }
}

static __attribute__((naked))
void UI_BuildServerStatus(void)
{
    /* trampoline: eax = force parameter */
    __asm__ __volatile__ (
        "pushl %eax\n"
        "calll UI_BuildServerStatus_impl\n"
        "addl $4, %esp\n"
        "retl\n"
    );
}

/* line 513 */
__attribute__((naked))
void UI_Refresh(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 513 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl uiInfo, %eax\n" /* line 515 */
        "movl %eax, (%esp)\n"
        "calll Menu_Count\n"
        "testl %eax, %eax\n"
        "jle .Lf154328_001543ba\n"
        "movl uiInfo, %eax\n" /* line 518 */
        "movl %eax, (%esp)\n"
        "calll Menu_PaintAll\n"
        "movl sharedUiInfo+28652, %eax\n" /* line 5027 */
        "testl %eax, %eax\n"
        "jne .Lf154328_001543c0\n"
        ".Lf154328_00154356:\n"
        "xorl %eax, %eax\n" /* line 522 */
        "calll UI_BuildServerStatus\n"
        "calll UI_BuildFindPlayerList\n" /* line 526 */
        "movl uiInfo, %edx\n" /* line 531 */
        "movl sharedUiInfo+36, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $4, 0x14(%esp)\n"
        "movl $4, 0x10(%esp)\n"
        "movl $0x42000000, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "subl $0x10, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl 0xc(%edx), %eax\n"
        "subl $0x10, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        ".Lf154328_001543ba:\n"
        "addl $0x24, %esp\n" /* line 534 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf154328_001543c0:\n"
        "movl ui_netSource, %eax\n" /* line 5031 */
        "movl 8(%eax), %eax\n"
        "cmpl $2, %eax\n"
        "je .Lf154328_001543e5\n"
        "testl %eax, %eax\n" /* line 5033 */
        "je .Lf154328_00154472\n"
        "movl %eax, (%esp)\n" /* line 5042 */
        "calll LAN_WaitServerResponse\n"
        "testl %eax, %eax\n"
        "jne .Lf154328_00154486\n"
        ".Lf154328_001543e5:\n"
        "xorl %ebx, %ebx\n"
        ".Lf154328_001543e7:\n"
        "movl uiInfo, %eax\n" /* line 5049 */
        "movl 4(%eax), %eax\n"
        "cmpl sharedUiInfo+28632, %eax\n"
        "jge .Lf154328_001543ff\n"
        "testl %ebx, %ebx\n" /* line 5051 */
        "jne .Lf154328_00154356\n"
        ".Lf154328_001543ff:\n"
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf154328_0015443b\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "je .Lf154328_0015443b\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        ".Lf154328_0015443b:\n"
        "movl ui_netSource, %eax\n" /* line 5061 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_UpdateDirtyPings\n"
        "testl %eax, %eax\n"
        "je .Lf154328_00154490\n"
        "movl uiInfo, %eax\n" /* line 5063 */
        "movl 4(%eax), %eax\n"
        "addl $0x3e8, %eax\n"
        "movl %eax, sharedUiInfo+28632\n"
        ".Lf154328_00154461:\n"
        "movl $0, (%esp)\n" /* line 5077 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf154328_00154356\n"
        ".Lf154328_00154472:\n"
        "movl $0, (%esp)\n" /* line 5035 */
        "calll LAN_GetServerCount\n"
        "testl %eax, %eax\n"
        "jne .Lf154328_001543e5\n"
        ".Lf154328_00154486:\n"
        "movl $1, %ebx\n" /* line 5042 */
        "jmp .Lf154328_001543e7\n"
        ".Lf154328_00154490:\n"
        "testl %ebx, %ebx\n" /* line 5068 */
        "jne .Lf154328_00154461\n"
        "movl $2, (%esp)\n" /* line 5071 */
        "calll UI_BuildServerDisplayList\n"
        "movl sharedUiInfo+28652, %ebx\n" /* line 5002 */
        "testl %ebx, %ebx\n"
        "je .Lf154328_00154461\n"
        "movl $0, sharedUiInfo+28652\n" /* line 5007 */
        "movl sharedUiInfo+108668, %eax\n" /* line 5008 */
        "movl %eax, 8(%esp)\n"
        "movl sharedUiInfo+108660, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa9c8, (%esp)\n" /* "%d servers listed in browser with %d players.
" */
        "calll Com_Printf\n"
        "movl ui_netSource, %eax\n" /* line 5009 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "subl sharedUiInfo+108660, %eax\n" /* line 5010 */
        "testl %eax, %eax\n"
        "jle .Lf154328_00154461\n"
        "movl %eax, 4(%esp)\n" /* line 5012 */
        "movl $str_002aa9f8, (%esp)\n" /* "%d servers not listed (filtered out by game browser settings" */
        "calll Com_Printf\n"
        "jmp .Lf154328_00154461\n"
    );
}

/* line 2141 */
__attribute__((naked))
void UI_RunMenuScript(const char * *args)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2141 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c7c, %esp\n"
        "movl 8(%ebp), %esi\n" /* args */
        /* { scope 1: out, sortColumn, addr */
        "movl $0x400, 8(%esp)\n" /* line 2154 */
        "leal -0x83c(%ebp), %ebx\n" /* name, menuIndex */
        "movl %ebx, 4(%esp)\n" /* menuIndex */
        "movl %esi, (%esp)\n" /* args */
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015453e\n"
        /* } scope */
        ".Lf154506_00154533:\n"
        "addl $0x2c7c, %esp\n" /* line 2558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: out, sortColumn, addr */
        ".Lf154506_0015453e:\n"
        "movl $str_002aaa38, 4(%esp)\n" /* line 2156 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001545f9\n"
        "movl $0, 4(%esp)\n" /* line 2158 */
        "movl $str_002a83e4, (%esp)\n" /* "cg_thirdPerson" */
        "calll Dvar_SetBoolByName\n"
        "movl ui_dedicated, %eax\n" /* line 2161 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl $1, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_SetFromStringByNameFromSource\n"
        "movl ui_netGameType, %eax\n" /* line 2162 */
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4428(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002a7100, (%esp)\n" /* "g_gametype" */
        "calll Dvar_SetStringByName\n"
        "movl ui_currentNetMap, %eax\n" /* line 2170 */
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl sharedUiInfo+4952(, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aaa44, (%esp)\n" /* "wait ; wait ; map %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "addl $0x2c7c, %esp\n" /* line 2558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: out, sortColumn, addr */
        ".Lf154506_001545f9:\n"
        "movl $str_002aaa5c, 4(%esp)\n" /* line 2172 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_0015470b\n"
        "movl $str_002aaa9c, 4(%esp)\n" /* line 2186 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001547a7\n"
        /* { scope 2 */
        "movl $5, 0xc(%esp)\n" /* line 2190 */
        "leal -0x103c(%ebp), %esi\n" /* buff2, args */
        "movl %esi, 8(%esp)\n" /* args */
        "movl $0x11, 4(%esp)\n"
        "leal -0x43c(%ebp), %ebx\n" /* buff, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll CLUI_GetCDKey\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 2191 */
        "movl $str_002aaaa8, (%esp)\n" /* "cdkey1" */
        "calll Dvar_SetStringByName\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 2192 */
        "movl $str_002aaab0, (%esp)\n" /* "cdkey2" */
        "calll Dvar_SetStringByName\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 2193 */
        "movl $str_002aaab8, (%esp)\n" /* "cdkey3" */
        "calll Dvar_SetStringByName\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 2194 */
        "movl $str_002aaac0, (%esp)\n" /* "cdkey4" */
        "calll Dvar_SetStringByName\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 2195 */
        "movl $str_002aaac8, (%esp)\n" /* "cdkey5" */
        "calll Dvar_SetStringByName\n"
        "cld\n" /* line 2196 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* menuIndex */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "cmpl $-0x12, %ecx\n"
        "je .Lf154506_00154974\n"
        ".Lf154506_001546ca:\n"
        "cld\n" /* line 2207 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* args */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "cmpl $-6, %ecx\n"
        "jne .Lf154506_00154533\n"
        "movl $5, 8(%esp)\n" /* line 2209 */
        "movl %esi, 4(%esp)\n" /* args */
        "leal -0x3c(%ebp), %ebx\n" /* out, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "movl %ebx, 4(%esp)\n" /* line 2210 | menuIndex */
        "movl $str_002aaac8, (%esp)\n" /* "cdkey5" */
        "calll Dvar_SetStringByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_0015470b:\n"
        "movl $str_002aaa6c, 4(%esp)\n" /* line 2174 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $str_002166a4, 4(%esp)\n" /* line 2175 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $str_002166bc, 4(%esp)\n" /* line 2176 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $str_002aaa7c, 4(%esp)\n" /* line 2177 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "calll Controls_SetDefaults\n" /* line 2178 */
        "movl $1, 4(%esp)\n" /* line 2179 */
        "movl $str_00216870, (%esp)\n" /* "com_introPlayed" */
        "calll Dvar_SetBoolByName\n"
        "movl $1, 4(%esp)\n" /* line 2180 */
        "movl $str_00216890, (%esp)\n" /* "com_recommendedSet" */
        "calll Dvar_SetBoolByName\n"
        "movl $str_002aaa8c, 4(%esp)\n" /* line 2182 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "addl $0x2c7c, %esp\n" /* line 2558 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: out, sortColumn, addr */
        ".Lf154506_001547a7:\n"
        "movl $str_002aaad0, 4(%esp)\n" /* line 2214 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00154879\n"
        "movl $str_002aab10, 4(%esp)\n" /* line 2235 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154a1e\n"
        "calll UI_LoadArenas\n" /* line 2237 */
        "movl $str_002a7100, (%esp)\n" /* line 2574 */
        "calll Dvar_GetString\n"
        "movl %eax, %edi\n"
        "movl sharedUiInfo+4424, %eax\n" /* line 2576 */
        "testl %eax, %eax\n"
        "jg .Lf154506_00154b6f\n"
        ".Lf154506_001547f7:\n"
        "movl ui_netGameType, %eax\n" /* line 2634 */
        "movl 8(%eax), %ebx\n" /* menuIndex */
        "movl sharedUiInfo+4944, %eax\n" /* line 2636 */
        "testl %eax, %eax\n"
        "jle .Lf154506_00154842\n"
        "xorl %esi, %esi\n" /* args */
        "movl $sharedUiInfo, %edx\n"
        ".Lf154506_0015480f:\n"
        "movl $0, 0x13f4(%edx)\n" /* line 2638 */
        "movl 0x1368(%edx), %eax\n" /* line 2639 */
        "movl %ebx, %ecx\n" /* menuIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf154506_00154831\n"
        "movl $1, 0x13f4(%edx)\n" /* line 2642 */
        ".Lf154506_00154831:\n"
        "addl $1, %esi\n" /* line 2636 | args */
        "addl $0xa4, %edx\n"
        "cmpl %esi, sharedUiInfo+4944\n" /* args */
        "jg .Lf154506_0015480f\n"
        ".Lf154506_00154842:\n"
        "movl $str_002aa094, 0x10(%esp)\n" /* line 2240 */
        "movl $0, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "calll UI_SelectCurrentMap\n" /* line 2241 */
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154879:\n"
        "movb $0, -0x43c(%ebp)\n" /* line 2216 | buff */
        "movl $str_002aaaa8, (%esp)\n" /* line 2217 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x43c(%ebp), %esi\n" /* buff, args */
        "movl %esi, (%esp)\n" /* args */
        "calll I_strncat\n"
        "movl $str_002aaab0, (%esp)\n" /* line 2218 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* args */
        "calll I_strncat\n"
        "movl $str_002aaab8, (%esp)\n" /* line 2219 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* args */
        "calll I_strncat\n"
        "movl $str_002aaac0, (%esp)\n" /* line 2220 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* args */
        "calll I_strncat\n"
        "movb $0, -0x103c(%ebp)\n" /* line 2221 | buff2 */
        "movl $str_002aaac8, (%esp)\n" /* line 2222 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x400, 4(%esp)\n"
        "leal -0x103c(%ebp), %ebx\n" /* buff2, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncat\n"
        "movl %ebx, 4(%esp)\n" /* line 2223 | menuIndex */
        "movl %esi, (%esp)\n" /* args */
        "calll CL_CDKeyValidate\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00154a3c\n"
        "movl $str_002aaadc, (%esp)\n" /* line 2225 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aaaec, (%esp)\n" /* "ui_cdkeyvalid" */
        "calll Dvar_SetStringByName\n"
        "movl %ebx, 4(%esp)\n" /* line 2226 | menuIndex */
        "movl %esi, (%esp)\n" /* args */
        "calll CLUI_SetCDKey\n"
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        ".Lf154506_00154974:\n"
        "movl $5, 8(%esp)\n" /* line 2198 */
        "movl %ebx, 4(%esp)\n" /* menuIndex */
        "leal -0x3c(%ebp), %ebx\n" /* out, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "movl %ebx, 4(%esp)\n" /* line 2199 | menuIndex */
        "movl $str_002aaaa8, (%esp)\n" /* "cdkey1" */
        "calll Dvar_SetStringByName\n"
        "movl $5, 8(%esp)\n" /* line 2200 */
        "leal -0x438(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "movl %ebx, 4(%esp)\n" /* line 2201 | menuIndex */
        "movl $str_002aaab0, (%esp)\n" /* "cdkey2" */
        "calll Dvar_SetStringByName\n"
        "movl $5, 8(%esp)\n" /* line 2202 */
        "leal -0x434(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "movl %ebx, 4(%esp)\n" /* line 2203 | menuIndex */
        "movl $str_002aaab8, (%esp)\n" /* "cdkey3" */
        "calll Dvar_SetStringByName\n"
        "movl $5, 8(%esp)\n" /* line 2204 */
        "leal -0x430(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "movl %ebx, 4(%esp)\n" /* line 2205 | menuIndex */
        "movl $str_002aaac0, (%esp)\n" /* "cdkey4" */
        "calll Dvar_SetStringByName\n"
        "jmp .Lf154506_001546ca\n"
        /* } scope */
        ".Lf154506_00154a1e:\n"
        "movl $str_002aab1c, 4(%esp)\n" /* line 2243 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154a5d\n"
        "calll UI_GetGameTypesList\n" /* line 2245 */
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154a3c:\n"
        "movl $str_002aaafc, (%esp)\n" /* line 2230 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aaaec, (%esp)\n" /* "ui_cdkeyvalid" */
        "calll Dvar_SetStringByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154a5d:\n"
        "movl $str_002aab2c, 4(%esp)\n" /* line 2247 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154bce\n"
        "movl $0, sharedUiInfo+26484\n" /* line 1549 */
        "movl $0x800, 0x10(%esp)\n" /* line 1550 */
        "leal -0x2c3c(%ebp), %edi\n" /* addr */
        "movl %edi, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_00216f5c, (%esp)\n" /* "$modlist" */
        "calll FS_GetFileList\n"
        "movl %eax, -0x2c60(%ebp)\n"
        "testl %eax, %eax\n" /* line 1552 */
        "jle .Lf154506_00154533\n"
        "movl %edi, -0x2c5c(%ebp)\n"
        "movl $0, -0x2c58(%ebp)\n"
        "movl sharedUiInfo+26484, %esi\n"
        "jmp .Lf154506_00154ad9\n"
        ".Lf154506_00154ad3:\n"
        "movl -0x2c5c(%ebp), %edi\n"
        ".Lf154506_00154ad9:\n"
        "cld\n" /* line 1554 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "movl -0x2c5c(%ebp), %edi\n" /* line 1555 */
        "addl %ebx, %edi\n"
        "movl -0x2c5c(%ebp), %eax\n" /* line 1556 */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, sharedUiInfo+25972(, %esi, 8)\n"
        "movl sharedUiInfo+26484, %esi\n" /* line 1557 */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, sharedUiInfo+25976(, %esi, 8)\n"
        "cld\n" /* line 1558 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx, %ebx), %ecx\n"
        "movl -0x2c5c(%ebp), %edx\n"
        "leal 1(%edx, %ecx), %ecx\n"
        "movl %ecx, -0x2c5c(%ebp)\n"
        "movl sharedUiInfo+26484, %eax\n" /* line 1559 */
        "addl $1, %eax\n"
        "movl %eax, %esi\n"
        "movl %eax, sharedUiInfo+26484\n"
        "cmpl $0x3f, %eax\n" /* line 1560 */
        "jg .Lf154506_00154533\n"
        "addl $1, -0x2c58(%ebp)\n" /* line 1552 */
        "movl -0x2c58(%ebp), %ecx\n"
        "cmpl %ecx, -0x2c60(%ebp)\n"
        "jne .Lf154506_00154ad3\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154b6f:\n"
        "xorl %esi, %esi\n" /* line 2576 | args */
        "movl $sharedUiInfo, %ebx\n" /* menuIndex */
        "jmp .Lf154506_00154b8a\n"
        ".Lf154506_00154b78:\n"
        "addl $1, %esi\n" /* args */
        "addl $8, %ebx\n" /* menuIndex */
        "cmpl %esi, sharedUiInfo+4424\n" /* args */
        "jle .Lf154506_001547f7\n"
        ".Lf154506_00154b8a:\n"
        "movl 0x114c(%ebx), %eax\n" /* line 2578 | menuIndex */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154b78\n"
        "movl %esi, 4(%esp)\n" /* line 2580 | args */
        "movl ui_netGameType, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl sharedUiInfo+4428(, %esi, 8), %eax\n" /* line 2581 */
        "movl %eax, 4(%esp)\n"
        "movl ui_netGameTypeName, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf154506_001547f7\n"
        ".Lf154506_00154bce:\n"
        "movl $str_002aab38, 4(%esp)\n" /* line 2251 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154c2f\n"
        "movl ui_currentNetMap, %eax\n" /* line 2253 */
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %edx\n"
        "leal (%eax, %edx, 8), %edx\n"
        "movl sharedUiInfo+4952(, %edx, 4), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl ui_netGameType, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4428(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aab44, (%esp)\n" /* "callvote typemap %s %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154c2f:\n"
        "movl $str_002aab5c, 4(%esp)\n" /* line 2255 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154c91\n"
        "movl ui_currentNetMap, %eax\n" /* line 2257 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+4944, %edx\n"
        "jge .Lf154506_00154533\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 2259 */
        "leal (%edx, %eax, 8), %eax\n"
        "movl sharedUiInfo+4952(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aab64, (%esp)\n" /* "callvote map %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154c91:\n"
        "movl $str_002aab78, 4(%esp)\n" /* line 2262 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154cd9\n"
        "movl ui_netGameType, %eax\n" /* line 2264 */
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4428(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aab84, (%esp)\n" /* "callvote g_gametype %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154cd9:\n"
        "movl $str_002aab9c, 4(%esp)\n" /* line 2267 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154cfe\n"
        "movl $1, (%esp)\n" /* line 2269 */
        "calll Controls_SetConfig\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154cfe:\n"
        "movl $str_002aabac, 4(%esp)\n" /* line 2271 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154d1c\n"
        "calll Controls_GetConfig\n" /* line 2273 */
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154d1c:\n"
        "movl $str_002aabbc, 4(%esp)\n" /* line 2275 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154d5d\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 2277 */
        "movl $str_0021605c, (%esp)\n" /* "com_errorMessage" */
        "calll Dvar_SetStringByName\n"
        "movl $0, 4(%esp)\n" /* line 2278 */
        "movl $str_002aabc8, (%esp)\n" /* "com_isNotice" */
        "calll Dvar_SetBoolByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154d5d:\n"
        "movl $str_002aabd8, 4(%esp)\n" /* line 2280 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154d89\n"
        "movb $1, %al\n" /* line 2282 */
        "calll UI_StartServerRefresh\n"
        "movl $1, (%esp)\n" /* line 2283 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154d89:\n"
        "movl $str_002aabe8, 4(%esp)\n" /* line 2285 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154db3\n"
        "calll UI_StartServerRefresh\n" /* line 2287 */
        "movl $1, (%esp)\n" /* line 2288 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154db3:\n"
        "movl $str_002aabf8, 4(%esp)\n" /* line 2291 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154e6d\n"
        "movl uiInfo, %eax\n" /* line 1647 */
        "movl $0, 0x280(%eax)\n"
        "movl uiInfo, %eax\n" /* line 1648 */
        "movl $1, 0x384(%eax)\n"
        "movl $3, 0x10(%esp)\n" /* line 1651 */
        "leal -0x1c(%ebp), %eax\n" /* sortColumn */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $str_00216f38, 4(%esp)\n" /* "/" */
        "movl $str_00228e74, (%esp)\n" /* "players" */
        "calll FS_ListFiles\n"
        "movl %eax, -0x2c54(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1653 | sortColumn */
        "testl %eax, %eax\n"
        "jg .Lf154506_00154ffb\n"
        ".Lf154506_00154e25:\n"
        "movl $3, 4(%esp)\n" /* line 1659 */
        "movl -0x2c54(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll FS_FreeFileList\n"
        "movl uiInfo, %edx\n" /* line 1630 */
        "movl %edx, %ecx\n"
        "movl 0x280(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154f53\n"
        ".Lf154506_00154e51:\n"
        "movl 0x280(%edx), %eax\n" /* line 1662 */
        "movl %eax, 4(%esp)\n"
        "movl ui_playerProfileCount, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00154e6d:\n"
        "movl $str_002aac0c, 4(%esp)\n" /* line 2295 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015503a\n"
        "movl uiInfo, %edx\n" /* line 2298 */
        "xorl %eax, %eax\n"
        "cmpl $0, 0x384(%edx)\n"
        "sete %al\n"
        "movl %eax, 0x384(%edx)\n"
        /* { scope 2 */
        "movl uiInfo, %edx\n" /* line 1630 */
        "cmpl $0, 0x280(%edx)\n"
        "je .Lf154506_00154533\n"
        "jle .Lf154506_00154ecc\n" /* line 1633 */
        "xorl %eax, %eax\n"
        ".Lf154506_00154eb4:\n"
        "movl %eax, 0x388(%edx, %eax, 4)\n" /* line 1634 */
        "addl $1, %eax\n" /* line 1633 */
        "movl uiInfo, %edx\n"
        "cmpl %eax, 0x280(%edx)\n"
        "jg .Lf154506_00154eb4\n"
        ".Lf154506_00154ecc:\n"
        "movl $UI_PlayerProfilesQsortCompare, 0xc(%esp)\n" /* line 1635 */
        "movl $4, 8(%esp)\n"
        "movl 0x280(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x388(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        /* { scope 3 */
        "movl uiInfo, %edx\n" /* line 1618 */
        "movl 0x270(%edx), %esi\n"
        "subl $1, %esi\n"
        "js .Lf154506_00154533\n"
        "movl %esi, %ebx\n" /* menuIndex */
        ".Lf154506_00154f0b:\n"
        "movl 0x230(%edx, %ebx, 4), %eax\n" /* line 1620 */
        "testb $4, 0xe8(%eax)\n"
        "je .Lf154506_00154f3f\n"
        "movl $0, 0x10(%esp)\n" /* line 1621 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        ".Lf154506_00154f3f:\n"
        "subl $1, %ebx\n" /* line 1618 | menuIndex */
        "cmpl $-1, %ebx\n" /* menuIndex */
        "je .Lf154506_00154533\n"
        "movl uiInfo, %edx\n"
        "jmp .Lf154506_00154f0b\n"
        /* } scope */
        /* } scope */
        ".Lf154506_00154f53:\n"
        "testl %eax, %eax\n" /* line 1633 */
        "jle .Lf154506_00154f71\n"
        "xorl %eax, %eax\n"
        ".Lf154506_00154f59:\n"
        "movl %eax, 0x388(%ecx, %eax, 4)\n" /* line 1634 */
        "addl $1, %eax\n" /* line 1633 */
        "movl uiInfo, %ecx\n"
        "cmpl %eax, 0x280(%ecx)\n"
        "jg .Lf154506_00154f59\n"
        ".Lf154506_00154f71:\n"
        "movl $UI_PlayerProfilesQsortCompare, 0xc(%esp)\n" /* line 1635 */
        "movl $4, 8(%esp)\n"
        "movl 0x280(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x388(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl uiInfo, %edx\n" /* line 1618 */
        "movl 0x270(%edx), %eax\n"
        "subl $1, %eax\n"
        "js .Lf154506_00154e51\n"
        "movl %eax, %ebx\n" /* menuIndex */
        "movl $0xffffffff, %esi\n"
        ".Lf154506_00154fb5:\n"
        "movl 0x230(%edx, %ebx, 4), %eax\n" /* line 1620 */
        "testb $4, 0xe8(%eax)\n"
        "je .Lf154506_00154fef\n"
        "movl $0, 0x10(%esp)\n" /* line 1621 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "movl uiInfo, %edx\n"
        ".Lf154506_00154fef:\n"
        "subl $1, %ebx\n" /* line 1618 | menuIndex */
        "cmpl %ebx, %esi\n" /* menuIndex */
        "jne .Lf154506_00154fb5\n"
        "jmp .Lf154506_00154e51\n"
        ".Lf154506_00154ffb:\n"
        "xorl %edi, %edi\n" /* line 1653 */
        ".Lf154506_00154ffd:\n"
        "movl uiInfo, %ebx\n" /* line 1655 | menuIndex */
        "movl 0x280(%ebx), %esi\n" /* menuIndex */
        "movl -0x2c54(%ebp), %edx\n"
        "movl (%edx, %edi, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x284(%ebx, %esi, 4)\n" /* menuIndex */
        "movl uiInfo, %eax\n" /* line 1656 */
        "addl $1, 0x280(%eax)\n"
        "addl $1, %edi\n" /* line 1653 */
        "cmpl %edi, -0x1c(%ebp)\n" /* sortColumn */
        "jg .Lf154506_00154ffd\n"
        "jmp .Lf154506_00154e25\n"
        ".Lf154506_0015503a:\n"
        "movl $str_002aac20, 4(%esp)\n" /* line 2301 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001550a6\n"
        "movl imp_com_playerProfile, %eax\n" /* line 1670 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* menuIndex */
        "movl uiInfo, %edx\n" /* line 1580 */
        "movl 0x280(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf154506_00154533\n"
        "xorl %esi, %esi\n"
        ".Lf154506_0015506e:\n"
        "movl 0x388(%edx, %esi, 4), %eax\n" /* line 1584 */
        "movl 0x284(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_0015516a\n"
        "addl $1, %esi\n" /* line 1580 */
        "movl uiInfo, %edx\n"
        "cmpl %esi, 0x280(%edx)\n"
        "jg .Lf154506_0015506e\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_001550a6:\n"
        "movl $str_002aac3c, 4(%esp)\n" /* line 2305 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155208\n"
        "movl ui_playerProfileNameNew, %eax\n" /* line 1682 */
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf154506_00154533\n"
        "movl $0x20, 8(%esp)\n" /* line 1685 */
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %edi\n" /* out */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1686 */
        "movl ui_playerProfileNameNew, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl uiInfo, %eax\n" /* line 1688 */
        "movl 0x280(%eax), %edx\n"
        "cmpl $0x40, %edx\n"
        "je .Lf154506_001551f3\n"
        "testl %edx, %edx\n" /* line 1696 */
        "jle .Lf154506_00155140\n"
        "xorl %ebx, %ebx\n" /* menuIndex */
        ".Lf154506_00155115:\n"
        "movl 0x284(%eax, %ebx, 4), %eax\n" /* line 1698 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_001551d9\n"
        "addl $1, %ebx\n" /* line 1696 | menuIndex */
        "movl uiInfo, %eax\n"
        "cmpl %ebx, 0x280(%eax)\n" /* menuIndex */
        "jg .Lf154506_00155115\n"
        ".Lf154506_00155140:\n"
        "movl %edi, (%esp)\n" /* line 1705 */
        "calll Com_NewPlayerProfile\n"
        "testb %al, %al\n"
        "jne .Lf154506_001552d6\n"
        "movl $str_002aac88, 4(%esp)\n" /* line 1707 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_0015516a:\n"
        "testl %esi, %esi\n" /* line 1671 */
        "js .Lf154506_00154533\n"
        "movl uiInfo, %edx\n"
        "cmpl %esi, 0x280(%edx)\n"
        "jle .Lf154506_00154533\n"
        "movl 0x270(%edx), %edi\n" /* line 1618 */
        "subl $1, %edi\n"
        "js .Lf154506_00154533\n"
        "movl %edi, %ebx\n" /* menuIndex */
        ".Lf154506_00155195:\n"
        "movl 0x230(%edx, %ebx, 4), %eax\n" /* line 1620 */
        "testb $4, 0xe8(%eax)\n"
        "je .Lf154506_001551c5\n"
        "movl $0, 0x10(%esp)\n" /* line 1621 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        ".Lf154506_001551c5:\n"
        "subl $1, %ebx\n" /* line 1618 | menuIndex */
        "cmpl $-1, %ebx\n" /* menuIndex */
        "je .Lf154506_00154533\n"
        "movl uiInfo, %edx\n"
        "jmp .Lf154506_00155195\n"
        ".Lf154506_001551d9:\n"
        "movl $str_002aac70, 4(%esp)\n" /* line 1700 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_001551f3:\n"
        "movl $str_002aac50, 4(%esp)\n" /* line 1690 */
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155208:\n"
        "movl $str_002aaca4, 4(%esp)\n" /* line 2309 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155595\n"
        "movl uiInfo, %eax\n" /* line 1729 */
        "movl 0x280(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf154506_00154533\n"
        "movl ui_playerProfileSelected, %eax\n" /* line 1733 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_DeletePlayerProfile\n"
        "testb %al, %al\n"
        "je .Lf154506_0015557b\n"
        "movl ui_playerProfileSelected, %eax\n" /* line 1739 */
        "movl 8(%eax), %ebx\n" /* menuIndex */
        "movl uiInfo, %edx\n" /* line 1580 */
        "movl 0x280(%edx), %esi\n"
        "testl %esi, %esi\n"
        "jg .Lf154506_00155545\n"
        ".Lf154506_00155267:\n"
        "movl $0xffffffff, %esi\n"
        ".Lf154506_0015526c:\n"
        "movl 0x388(%edx, %esi, 4), %ecx\n" /* line 1742 */
        "subl $1, 0x280(%edx)\n" /* line 1746 */
        "movl uiInfo, %edx\n" /* line 1747 */
        "movl 0x280(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00155525\n"
        "movl 0x284(%edx, %eax, 4), %eax\n" /* line 1753 */
        "movl %eax, 0x284(%edx, %ecx, 4)\n"
        "movl uiInfo, %edx\n" /* line 1754 */
        "movl %edx, %ebx\n" /* menuIndex */
        "movl 0x280(%edx), %ecx\n"
        "leal -1(%ecx), %eax\n" /* line 1755 */
        "cmpl %ecx, %esi\n"
        "cmovel %eax, %esi\n"
        "testl %ecx, %ecx\n" /* line 1630 */
        "jne .Lf154506_00155476\n"
        ".Lf154506_001552ba:\n"
        "movl 0x280(%edx), %eax\n" /* line 1758 */
        "movl %eax, 4(%esp)\n"
        "movl ui_playerProfileCount, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_001552d6:\n"
        "movl uiInfo, %ebx\n" /* line 1711 | menuIndex */
        "movl 0x280(%ebx), %esi\n" /* menuIndex */
        "movl %edi, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x284(%ebx, %esi, 4)\n" /* menuIndex */
        "movl uiInfo, %eax\n" /* line 1712 */
        "addl $1, 0x280(%eax)\n"
        "movl uiInfo, %edx\n" /* line 1630 */
        "movl %edx, %ecx\n"
        "movl 0x280(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001553ce\n"
        ".Lf154506_00155313:\n"
        "movl 0x280(%edx), %eax\n" /* line 1715 */
        "movl %eax, 4(%esp)\n"
        "movl ui_playerProfileCount, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl uiInfo, %edx\n" /* line 1580 */
        "movl 0x280(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf154506_00155394\n"
        ".Lf154506_0015533a:\n"
        "movl $0xffffffff, %esi\n"
        ".Lf154506_0015533f:\n"
        "movl 0x270(%edx), %edi\n" /* line 1618 */
        "subl $1, %edi\n"
        "js .Lf154506_00154533\n"
        "movl %edi, %ebx\n" /* menuIndex */
        ".Lf154506_00155350:\n"
        "movl 0x230(%edx, %ebx, 4), %eax\n" /* line 1620 */
        "testb $4, 0xe8(%eax)\n"
        "je .Lf154506_00155380\n"
        "movl $0, 0x10(%esp)\n" /* line 1621 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        ".Lf154506_00155380:\n"
        "subl $1, %ebx\n" /* line 1618 | menuIndex */
        "cmpl $-1, %ebx\n" /* menuIndex */
        "je .Lf154506_00154533\n"
        "movl uiInfo, %edx\n"
        "jmp .Lf154506_00155350\n"
        ".Lf154506_00155394:\n"
        "xorl %esi, %esi\n" /* line 1580 */
        ".Lf154506_00155396:\n"
        "movl 0x388(%edx, %esi, 4), %eax\n" /* line 1584 */
        "movl 0x284(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_0015551a\n"
        "addl $1, %esi\n" /* line 1580 */
        "movl uiInfo, %edx\n"
        "cmpl %esi, 0x280(%edx)\n"
        "jg .Lf154506_00155396\n"
        "jmp .Lf154506_0015533a\n"
        ".Lf154506_001553ce:\n"
        "testl %eax, %eax\n" /* line 1633 */
        "jle .Lf154506_001553ec\n"
        "xorl %eax, %eax\n"
        ".Lf154506_001553d4:\n"
        "movl %eax, 0x388(%ecx, %eax, 4)\n" /* line 1634 */
        "addl $1, %eax\n" /* line 1633 */
        "movl uiInfo, %ecx\n"
        "cmpl %eax, 0x280(%ecx)\n"
        "jg .Lf154506_001553d4\n"
        ".Lf154506_001553ec:\n"
        "movl $UI_PlayerProfilesQsortCompare, 0xc(%esp)\n" /* line 1635 */
        "movl $4, 8(%esp)\n"
        "movl 0x280(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal 0x388(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl uiInfo, %edx\n" /* line 1618 */
        "movl 0x270(%edx), %eax\n"
        "subl $1, %eax\n"
        "js .Lf154506_00155313\n"
        "movl %eax, %ebx\n" /* menuIndex */
        "movl $0xffffffff, %esi\n"
        ".Lf154506_00155430:\n"
        "movl 0x230(%edx, %ebx, 4), %eax\n" /* line 1620 */
        "testb $4, 0xe8(%eax)\n"
        "je .Lf154506_0015546a\n"
        "movl $0, 0x10(%esp)\n" /* line 1621 */
        "movl $0, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "movl uiInfo, %edx\n"
        ".Lf154506_0015546a:\n"
        "subl $1, %ebx\n" /* line 1618 | menuIndex */
        "cmpl %ebx, %esi\n" /* menuIndex */
        "jne .Lf154506_00155430\n"
        "jmp .Lf154506_00155313\n"
        ".Lf154506_00155476:\n"
        "testl %ecx, %ecx\n" /* line 1633 */
        "jle .Lf154506_00155494\n"
        "xorl %eax, %eax\n"
        ".Lf154506_0015547c:\n"
        "movl %eax, 0x388(%ebx, %eax, 4)\n" /* line 1634 | menuIndex */
        "addl $1, %eax\n" /* line 1633 */
        "movl uiInfo, %ebx\n" /* menuIndex */
        "cmpl %eax, 0x280(%ebx)\n" /* menuIndex */
        "jg .Lf154506_0015547c\n"
        ".Lf154506_00155494:\n"
        "movl $UI_PlayerProfilesQsortCompare, 0xc(%esp)\n" /* line 1635 */
        "movl $4, 8(%esp)\n"
        "movl 0x280(%ebx), %eax\n" /* menuIndex */
        "movl %eax, 4(%esp)\n"
        "leal 0x388(%ebx), %eax\n" /* menuIndex */
        "movl %eax, (%esp)\n"
        "calll qsort\n"
        "movl uiInfo, %edx\n" /* line 1618 */
        "movl 0x270(%edx), %eax\n"
        "subl $1, %eax\n"
        "js .Lf154506_001552ba\n"
        "movl %eax, %ebx\n" /* menuIndex */
        "movl $0xffffffff, %edi\n"
        ".Lf154506_001554d8:\n"
        "movl 0x230(%edx, %ebx, 4), %eax\n" /* line 1620 */
        "testb $4, 0xe8(%eax)\n"
        "je .Lf154506_0015550e\n"
        "movl $0, 0x10(%esp)\n" /* line 1621 */
        "movl %esi, 0xc(%esp)\n"
        "movl $0x18, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "movl uiInfo, %edx\n"
        ".Lf154506_0015550e:\n"
        "subl $1, %ebx\n" /* line 1618 | menuIndex */
        "cmpl %ebx, %edi\n" /* menuIndex */
        "jne .Lf154506_001554d8\n"
        "jmp .Lf154506_001552ba\n"
        ".Lf154506_0015551a:\n"
        "movl uiInfo, %edx\n"
        "jmp .Lf154506_0015533f\n"
        ".Lf154506_00155525:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 1749 */
        "movl ui_playerProfileSelected, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl uiInfo, %edx\n"
        "jmp .Lf154506_001552ba\n"
        ".Lf154506_00155545:\n"
        "xorl %esi, %esi\n" /* line 1580 */
        ".Lf154506_00155547:\n"
        "movl 0x388(%edx, %esi, 4), %eax\n" /* line 1584 */
        "movl 0x284(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_001555c7\n"
        "addl $1, %esi\n" /* line 1580 */
        "movl uiInfo, %edx\n"
        "cmpl 0x280(%edx), %esi\n"
        "jl .Lf154506_00155547\n"
        "jmp .Lf154506_00155267\n"
        ".Lf154506_0015557b:\n"
        "movl $str_002aacb8, 4(%esp)\n" /* line 1735 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155595:\n"
        "movl $str_002aacd4, 4(%esp)\n" /* line 2313 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001555d2\n"
        "movl ui_playerProfileSelected, %eax\n" /* line 1765 */
        "movl 8(%eax), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf154506_00154533\n"
        "movl %eax, (%esp)\n" /* line 1766 */
        "calll Com_ChangePlayerProfile\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_001555c7:\n"
        "movl uiInfo, %edx\n"
        "jmp .Lf154506_0015526c\n"
        ".Lf154506_001555d2:\n"
        "movl $str_002aace8, 4(%esp)\n" /* line 2319 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001556c7\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 1785 */
        "leal -0x2c3c(%ebp), %edi\n" /* addr */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00216ce4, 4(%esp)\n" /* "roq" */
        "movl $str_002a90b0, (%esp)\n" /* "video" */
        "calll FS_GetFileList\n"
        "movl %eax, %edx\n"
        "movl %eax, sharedUiInfo+27516\n"
        "testl %eax, %eax\n" /* line 1787 */
        "je .Lf154506_00154533\n"
        "movl $0x100, %eax\n" /* line 1791 */
        "cmpl $0x101, %edx\n"
        "cmovll %edx, %eax\n"
        "movl %eax, sharedUiInfo+27516\n"
        "testl %eax, %eax\n" /* line 1794 */
        "jle .Lf154506_00154533\n"
        "movl %edi, %esi\n"
        "movl $0, -0x2c50(%ebp)\n"
        "movl $sharedUiInfo, -0x2c4c(%ebp)\n"
        ".Lf154506_00155658:\n"
        "cld\n" /* line 1796 */
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl $str_002aacf4, 4(%esp)\n" /* line 1797 */
        "leal -1(%ecx, %esi), %ebx\n" /* menuIndex */
        "leal -4(%ebx), %eax\n" /* menuIndex */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155685\n"
        "movb $0, -4(%ebx)\n" /* line 1799 | menuIndex */
        ".Lf154506_00155685:\n"
        "movl %esi, (%esp)\n" /* line 1801 */
        "calll I_strupr\n"
        "movl %esi, (%esp)\n" /* line 1802 */
        "calll String_Alloc\n"
        "movl -0x2c4c(%ebp), %edx\n"
        "movl %eax, 0x677c(%edx)\n"
        "leal 1(%ebx), %esi\n" /* line 1803 | menuIndex */
        "addl $1, -0x2c50(%ebp)\n" /* line 1794 */
        "addl $4, %edx\n"
        "movl %edx, -0x2c4c(%ebp)\n"
        "movl -0x2c50(%ebp), %ecx\n"
        "cmpl sharedUiInfo+27516, %ecx\n"
        "jl .Lf154506_00155658\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_001556c7:\n"
        "movl $str_002aacfc, 4(%esp)\n" /* line 2324 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015571d\n"
        "movl sharedUiInfo+27524, %eax\n" /* line 2326 */
        "testl %eax, %eax\n"
        "js .Lf154506_001556ec\n"
        "movl %eax, (%esp)\n" /* line 2328 */
        "calll CIN_StopCinematic\n"
        ".Lf154506_001556ec:\n"
        "movl sharedUiInfo+27520, %eax\n" /* line 2330 */
        "movl sharedUiInfo+26492(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aad08, (%esp)\n" /* "cinematic %s 2
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_0015571d:\n"
        "movl $str_002aad18, 4(%esp)\n" /* line 2333 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155766\n"
        "movl sharedUiInfo+26488, %eax\n" /* line 2336 */
        "movl sharedUiInfo+25972(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216d64, (%esp)\n" /* "fs_game" */
        "calll Dvar_SetStringByName\n"
        "movl $str_002aad20, 4(%esp)\n" /* line 2338 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155766:\n"
        "movl $str_002aad30, 4(%esp)\n" /* line 2342 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155841\n"
        "movl sharedUiInfo+28652, %ebx\n" /* line 2344 | menuIndex */
        "testl %ebx, %ebx\n" /* menuIndex */
        "je .Lf154506_00155812\n"
        "movl $0, sharedUiInfo+28652\n" /* line 5007 */
        "movl sharedUiInfo+108668, %eax\n" /* line 5008 */
        "movl %eax, 8(%esp)\n"
        "movl sharedUiInfo+108660, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa9c8, (%esp)\n" /* "%d servers listed in browser with %d players.
" */
        "calll Com_Printf\n"
        "movl ui_netSource, %eax\n" /* line 5009 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "subl sharedUiInfo+108660, %eax\n" /* line 5010 */
        "testl %eax, %eax\n"
        "jle .Lf154506_001557de\n"
        "movl %eax, 4(%esp)\n" /* line 5012 */
        "movl $str_002aa9f8, (%esp)\n" /* "%d servers not listed (filtered out by game browser settings" */
        "calll Com_Printf\n"
        ".Lf154506_001557de:\n"
        "movl $0, sharedUiInfo+108672\n" /* line 2347 */
        "movl $0, sharedUiInfo+113132\n" /* line 2348 */
        "movl uiInfo, %eax\n" /* line 2349 */
        "movl $0, 0x10a4(%eax)\n"
        "movl $1, (%esp)\n" /* line 2350 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155812:\n"
        "movl $str_002aad3c, 4(%esp)\n" /* line 2354 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_CloseByName\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 2355 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155841:\n"
        "movl $str_002aad48, 4(%esp)\n" /* line 2358 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015588b\n"
        "movl sharedUiInfo+28652, %ecx\n" /* line 5002 */
        "testl %ecx, %ecx\n"
        "jne .Lf154506_00155a82\n"
        ".Lf154506_00155863:\n"
        "movl $0, sharedUiInfo+108672\n" /* line 2361 */
        "movl $0, sharedUiInfo+113132\n" /* line 2362 */
        "movl uiInfo, %eax\n" /* line 2363 */
        "movl $0, 0x10a4(%eax)\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_0015588b:\n"
        "movl $str_002aad54, 4(%esp)\n" /* line 2365 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155933\n"
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf154506_001558e0\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %edx\n" /* line 2020 */
        "testl %edx, %edx\n"
        "je .Lf154506_001558e0\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        ".Lf154506_001558e0:\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2368 */
        "testl %eax, %eax\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+108660, %eax\n"
        "jge .Lf154506_00154533\n"
        "movl $0x40, 0xc(%esp)\n" /* line 2370 */
        "movl $sharedUiInfo+109736, 8(%esp)\n"
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerAddressString\n"
        "movl $1, %eax\n" /* line 2371 */
        "calll UI_BuildServerStatus\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155933:\n"
        "movl $str_002aad64, 4(%esp)\n" /* line 2375 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155982\n"
        "movl ui_netSource, %eax\n" /* line 2377 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015595d\n"
        "movl $1, %eax\n" /* line 2379 */
        "calll UI_StartServerRefresh\n"
        ".Lf154506_0015595d:\n"
        "movl $1, (%esp)\n" /* line 2381 */
        "calll UI_BuildServerDisplayList\n"
        "movl $0, 4(%esp)\n" /* line 2382 */
        "movl $0x40000000, (%esp)\n"
        "calll UI_FeederSelection\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155982:\n"
        "movl $str_002aad74, 4(%esp)\n" /* line 2384 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155a55\n"
        "movl $0, 4(%esp)\n" /* line 2386 */
        "movl $str_002a83e4, (%esp)\n" /* "cg_thirdPerson" */
        "calll Dvar_SetBoolByName\n"
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf154506_001559ea\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "je .Lf154506_001559ea\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        ".Lf154506_001559ea:\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2388 */
        "testl %eax, %eax\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+108660, %eax\n"
        "jge .Lf154506_00154533\n"
        "movl $0x400, 0xc(%esp)\n" /* line 2390 */
        "leal -0x43c(%ebp), %ebx\n" /* buff, menuIndex */
        "movl %ebx, 8(%esp)\n" /* menuIndex */
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerAddressString\n"
        "movl %ebx, 4(%esp)\n" /* line 2391 | menuIndex */
        "movl $str_002a8ae4, (%esp)\n" /* "connect %s
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155a55:\n"
        "movl $str_002aad80, 4(%esp)\n" /* line 2394 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155add\n"
        "movl $str_002168bc, 4(%esp)\n" /* line 2396 */
        "movl $0, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155a82:\n"
        "movl $0, sharedUiInfo+28652\n" /* line 5007 */
        "movl sharedUiInfo+108668, %eax\n" /* line 5008 */
        "movl %eax, 8(%esp)\n"
        "movl sharedUiInfo+108660, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa9c8, (%esp)\n" /* "%d servers listed in browser with %d players.
" */
        "calll Com_Printf\n"
        "movl ui_netSource, %eax\n" /* line 5009 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "subl sharedUiInfo+108660, %eax\n" /* line 5010 */
        "testl %eax, %eax\n"
        "jle .Lf154506_00155863\n"
        "movl %eax, 4(%esp)\n" /* line 5012 */
        "movl $str_002aa9f8, (%esp)\n" /* "%d servers not listed (filtered out by game browser settings" */
        "calll Com_Printf\n"
        "jmp .Lf154506_00155863\n"
        ".Lf154506_00155add:\n"
        "movl $str_002aad88, 4(%esp)\n" /* line 2398 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155b38\n"
        "movl $1, 4(%esp)\n" /* line 2400 */
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "movl $8, (%esp)\n" /* line 2401 */
        "calll Key_SetCatcher\n"
        "movl uiInfo, %eax\n" /* line 2402 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl $str_002aad94, 4(%esp)\n" /* line 2403 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155b38:\n"
        "movl $str_002aada0, 4(%esp)\n" /* line 2405 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155b93\n"
        "movl $str_002aada8, 4(%esp)\n" /* line 2407 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "movl $8, (%esp)\n" /* line 2408 */
        "calll Key_SetCatcher\n"
        "movl uiInfo, %eax\n" /* line 2409 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 2410 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155b93:\n"
        "movl $str_002aadb4, 4(%esp)\n" /* line 2412 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155c0b\n"
        /* { scope 2 */
        "leal -0x1c(%ebp), %eax\n" /* line 2416 | sortColumn */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* args */
        "calll Int_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00154533\n"
        "movl sharedUiInfo+28640, %eax\n" /* line 2419 */
        "cmpl -0x1c(%ebp), %eax\n" /* sortColumn */
        "jne .Lf154506_00155bd9\n"
        "xorl %eax, %eax\n" /* line 2421 */
        "cmpl $0, sharedUiInfo+28644\n"
        "sete %al\n"
        "movl %eax, sharedUiInfo+28644\n"
        ".Lf154506_00155bd9:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1528 | sortColumn */
        "movl %eax, sharedUiInfo+28640\n"
        "movl $UI_ServersQsortCompare, 0xc(%esp)\n" /* line 1529 */
        "movl $4, 8(%esp)\n"
        "movl sharedUiInfo+108660, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $sharedUiInfo+28660, (%esp)\n"
        "calll qsort\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_00155c0b:\n"
        "movl $str_002aadc0, 4(%esp)\n" /* line 2427 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00154533\n"
        "movl $str_002aadd0, 4(%esp)\n" /* line 2431 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00154533\n"
        "movl $str_002aade0, 4(%esp)\n" /* line 2435 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155c8a\n"
        "calll Key_GetCatcher\n" /* line 2437 */
        "andl $0xfffffff7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetCatcher\n"
        "calll Key_ClearStates\n" /* line 2438 */
        "movl $0, 4(%esp)\n" /* line 2439 */
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "movl uiInfo, %eax\n" /* line 2440 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155c8a:\n"
        "movl $str_002aadec, 4(%esp)\n" /* line 2442 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155cea\n"
        "movl uiInfo, %eax\n" /* line 2444 */
        "movl 0x27c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+68, %eax\n"
        "jge .Lf154506_00154533\n"
        "shll $5, %eax\n" /* line 2446 */
        "addl $sharedUiInfo+72, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aadf8, (%esp)\n" /* "callvote kick "%s"
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155cea:\n"
        "movl $str_002aae0c, 4(%esp)\n" /* line 2449 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155d4a\n"
        "movl uiInfo, %eax\n" /* line 2451 */
        "movl 0x27c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+68, %eax\n"
        "jge .Lf154506_00154533\n"
        "shll $5, %eax\n" /* line 2453 */
        "addl $sharedUiInfo+72, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aae18, (%esp)\n" /* "callvote tempBanUser "%s"
" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00155d4a:\n"
        "movl $str_002aae34, 4(%esp)\n" /* line 2457 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155ddb\n"
        "movl ui_netSource, %eax\n" /* line 2459 */
        "cmpl $2, 8(%eax)\n"
        "je .Lf154506_00154533\n"
        /* { scope 2 */
        "movb $0, -0x2c3c(%ebp)\n" /* line 2464 | addr */
        "movb $0, -0x3c(%ebp)\n" /* out */
        "movl 8(%eax), %eax\n" /* line 2016 */
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf154506_00155daf\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "je .Lf154506_00155daf\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        ".Lf154506_00155daf:\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2466 */
        "testl %eax, %eax\n"
        "js .Lf154506_00155dc4\n"
        "cmpl sharedUiInfo+108660, %eax\n"
        "jl .Lf154506_00155f61\n"
        ".Lf154506_00155dc4:\n"
        "leal -0x3c(%ebp), %edi\n" /* out */
        "leal -0x2c3c(%ebp), %ebx\n" /* addr, menuIndex */
        ".Lf154506_00155dcd:\n"
        "movl %ebx, %edx\n" /* line 2472 | menuIndex */
        "movl %edi, %eax\n"
        "calll UI_AddServerToFavoritesList\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_00155ddb:\n"
        "movl $str_002aae40, 4(%esp)\n" /* line 2475 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155ed8\n"
        "movl ui_netSource, %eax\n" /* line 2477 */
        "cmpl $2, 8(%eax)\n"
        "jne .Lf154506_00154533\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2479 */
        "testl %eax, %eax\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+108660, %eax\n"
        "jge .Lf154506_00154533\n"
        /* { scope 2 */
        "movl $2, (%esp)\n" /* line 2016 */
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf154506_00155e53\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "je .Lf154506_00155e53\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        ".Lf154506_00155e53:\n"
        "movl $0x400, 0xc(%esp)\n" /* line 2484 */
        "leal -0x43c(%ebp), %ebx\n" /* buff, menuIndex */
        "movl %ebx, 8(%esp)\n" /* menuIndex */
        "movl sharedUiInfo+28656, %eax\n"
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerInfo\n"
        "movb $0, -0x2c3c(%ebp)\n" /* line 2485 | addr */
        "movl $str_002aa858, 4(%esp)\n" /* line 2486 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c3c(%ebp), %ebx\n" /* addr, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "cmpb $0, -0x2c3c(%ebp)\n" /* line 2487 | addr */
        "je .Lf154506_00154533\n"
        "movl %ebx, 4(%esp)\n" /* line 2489 | menuIndex */
        "movl $2, (%esp)\n"
        "calll LAN_RemoveServer\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_00155ed8:\n"
        "movl $str_002aae50, 4(%esp)\n" /* line 2494 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00155fe4\n"
        "movl ui_netSource, %eax\n" /* line 2496 */
        "cmpl $2, 8(%eax)\n"
        "jne .Lf154506_00154533\n"
        /* { scope 2 */
        "movb $0, -0x3c(%ebp)\n" /* line 2501 | out */
        "movb $0, -0x2c3c(%ebp)\n" /* addr */
        "movl $str_002aae60, (%esp)\n" /* line 2502 */
        "calll Dvar_GetVariantString\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c3c(%ebp), %esi\n" /* addr, args */
        "movl %esi, (%esp)\n" /* args */
        "calll I_strncpyz\n"
        "movl $str_002aae70, (%esp)\n" /* line 2503 */
        "calll Dvar_GetVariantString\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %ebx\n" /* out, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "movl %ebx, %edx\n" /* line 2504 | menuIndex */
        "movl %esi, %eax\n" /* args */
        "calll UI_AddServerToFavoritesList\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        /* { scope 2 */
        ".Lf154506_00155f61:\n"
        "movl $0x400, 0xc(%esp)\n" /* line 2468 */
        "leal -0x43c(%ebp), %ebx\n" /* buff, menuIndex */
        "movl %ebx, 8(%esp)\n" /* menuIndex */
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerInfo\n"
        "movl $str_002aa89c, 4(%esp)\n" /* line 2469 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3c(%ebp), %edi\n" /* out */
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $str_002aa858, 4(%esp)\n" /* line 2470 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll Info_ValueForKey\n"
        "movl $0x20, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x2c3c(%ebp), %ebx\n" /* addr, menuIndex */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_strncpyz\n"
        "jmp .Lf154506_00155dcd\n"
        /* } scope */
        ".Lf154506_00155fe4:\n"
        "movl $str_002aae84, 4(%esp)\n" /* line 2508 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015604f\n"
        "movl $0x400, 8(%esp)\n" /* line 2510 */
        "leal -0x143c(%ebp), %ebx\n" /* name2, menuIndex */
        "movl %ebx, 4(%esp)\n" /* menuIndex */
        "movl %esi, (%esp)\n" /* args */
        "calll String_Parse\n"
        "testl %eax, %eax\n"
        "je .Lf154506_00154533\n"
        /* { scope 2 */
        "movl $str_002aae8c, 4(%esp)\n" /* line 1883 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015607c\n"
        "movl $str_002aae98, (%esp)\n" /* line 1885 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002194b4, (%esp)\n" /* "name" */
        "calll Dvar_SetStringByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_0015604f:\n"
        "movl $str_002a916c, 4(%esp)\n" /* line 2513 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001560b1\n"
        "movl $str_002aaeb8, 4(%esp)\n" /* line 2515 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        ".Lf154506_0015607c:\n"
        "movl $str_002aaea0, 4(%esp)\n" /* line 1887 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001560ef\n"
        "movl $str_002194b4, (%esp)\n" /* line 1889 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aae98, (%esp)\n" /* "ui_Name" */
        "calll Dvar_SetStringByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_001560b1:\n"
        "movl $str_002aaecc, 4(%esp)\n" /* line 2517 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_0015615a\n"
        "movl $str_00216a14, (%esp)\n" /* line 2519 */
        "calll Dvar_GetInt\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa0a8, (%esp)\n" /* "ui_language" */
        "calll Dvar_SetIntByName\n"
        "calll UI_VerifyLanguage\n" /* line 2520 */
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        ".Lf154506_001560ef:\n"
        "movl $str_002aaeac, 4(%esp)\n" /* line 1891 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00156224\n"
        "movl $str_002a8c54, (%esp)\n" /* line 1893 */
        "calll Dvar_GetInt\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss lit4_002ed8c4, %xmm0\n" /* line 1895 | 5000.0f */
        "jae .Lf154506_001561f7\n"
        "ucomiss lit4_002ed8c8, %xmm0\n" /* line 1900 | 4000.0f */
        "jb .Lf154506_00156178\n"
        "movl $0xf, 4(%esp)\n" /* line 1902 */
        "movl $str_002a8e48, (%esp)\n" /* "cl_maxpackets" */
        "calll Dvar_SetIntByName\n"
        "movl $2, 4(%esp)\n" /* line 1903 */
        "movl $str_002a8e58, (%esp)\n" /* "cl_packetdup" */
        "calll Dvar_SetIntByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_0015615a:\n"
        "movl $str_002aaed8, 4(%esp)\n" /* line 2522 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001561a5\n"
        "calll UI_VerifyLanguage\n" /* line 2524 */
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        ".Lf154506_00156178:\n"
        "movl $0xf, 4(%esp)\n" /* line 1907 */
        "movl $str_002a8e48, (%esp)\n" /* "cl_maxpackets" */
        "calll Dvar_SetIntByName\n"
        "movl $1, 4(%esp)\n" /* line 1908 */
        "movl $str_002a8e58, (%esp)\n" /* "cl_packetdup" */
        "calll Dvar_SetIntByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_001561a5:\n"
        "movl $str_002aaee8, 4(%esp)\n" /* line 2527 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00156261\n"
        "movl $str_002aa0a8, (%esp)\n" /* line 2529 */
        "calll Dvar_GetInt\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_00216a14, (%esp)\n" /* "loc_language" */
        "calll Dvar_SetIntByName\n"
        "calll UI_VerifyLanguage\n" /* line 2530 */
        "movl $str_002aaa8c, 4(%esp)\n" /* line 2531 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        ".Lf154506_001561f7:\n"
        "movl $0x1e, 4(%esp)\n" /* line 1897 */
        "movl $str_002a8e48, (%esp)\n" /* "cl_maxpackets" */
        "calll Dvar_SetIntByName\n"
        "movl $1, 4(%esp)\n" /* line 1898 */
        "movl $str_002a8e58, (%esp)\n" /* "cl_packetdup" */
        "calll Dvar_SetIntByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00156224:\n"
        "movl $str_002aa6f8, 4(%esp)\n" /* line 1911 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00154533\n"
        "movl %ebx, (%esp)\n" /* line 1913 | menuIndex */
        "calll Dvar_GetBool\n"
        "testb %al, %al\n"
        "jne .Lf154506_001562a8\n"
        "movl $0x3cb43958, 4(%esp)\n" /* line 1914 */
        "movl $str_002a8f04, (%esp)\n" /* "m_pitch" */
        "calll Dvar_SetFloatByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_00156261:\n"
        "movl $str_002aaef8, 4(%esp)\n" /* line 2535 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_001562c1\n"
        "movl uiInfo, %eax\n" /* line 2537 */
        "movl 0x27c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf154506_00154533\n"
        "cmpl sharedUiInfo+68, %eax\n"
        "jge .Lf154506_00154533\n"
        "movl sharedUiInfo+4168(, %eax, 4), %eax\n" /* line 2539 */
        "movl %eax, (%esp)\n"
        "calll CL_MutePlayer\n"
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        ".Lf154506_001562a8:\n"
        "movl $0xbcb43958, 4(%esp)\n" /* line 1916 */
        "movl $str_002a8f04, (%esp)\n" /* "m_pitch" */
        "calll Dvar_SetFloatByName\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        ".Lf154506_001562c1:\n"
        "movl $str_002aaf04, 4(%esp)\n" /* line 2543 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_001562ed\n"
        "movl $str_002aaf14, 4(%esp)\n" /* "openMenuOnDvarNot" */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00156385\n"
        ".Lf154506_001562ed:\n"
        "leal -0x1c3c(%ebp), %edi\n" /* line 2545 | dvarName */
        "leal -0x183c(%ebp), %eax\n" /* menuName */
        "movl %eax, 4(%esp)\n"
        "leal -0xc3c(%ebp), %edx\n" /* testValue */
        "movl %edx, (%esp)\n"
        "movl %edi, %ecx\n"
        "movl %ebx, %edx\n" /* menuIndex */
        "movl %esi, %eax\n" /* args */
        "calll UI_GetOpenOrCloseMenuOnDvarArgs\n"
        "testb %al, %al\n"
        "je .Lf154506_00154533\n"
        "movl $str_002aaf04, 4(%esp)\n" /* line 2116 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "sete %cl\n"
        "movl %ecx, %esi\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl %edi, (%esp)\n" /* line 2095 */
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 2096 */
        "je .Lf154506_00156431\n"
        "movl %edi, (%esp)\n" /* line 2102 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 4(%esp)\n" /* line 2103 */
        "leal -0xc3c(%ebp), %eax\n" /* testValue */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        /* } scope */
        /* } scope */
        "movl %esi, %edx\n" /* line 2117 | wantMatch */
        "cmpb %al, %dl\n"
        "jne .Lf154506_00154533\n"
        "leal -0x183c(%ebp), %ecx\n" /* line 2118 | menuName */
        "movl %ecx, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf154506_00154533\n"
        ".Lf154506_00156385:\n"
        "movl $str_002aaf58, 4(%esp)\n" /* line 2548 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf154506_00156463\n"
        ".Lf154506_0015639d:\n"
        "leal -0x1c3c(%ebp), %edi\n" /* line 2550 | dvarName */
        "leal -0x183c(%ebp), %eax\n" /* menuName */
        "movl %eax, 4(%esp)\n"
        "leal -0xc3c(%ebp), %edx\n" /* testValue */
        "movl %edx, (%esp)\n"
        "movl %edi, %ecx\n"
        "movl %ebx, %edx\n" /* menuIndex */
        "movl %esi, %eax\n" /* args */
        "calll UI_GetOpenOrCloseMenuOnDvarArgs\n"
        "testb %al, %al\n"
        "je .Lf154506_00154533\n"
        "movl $str_002aaf58, 4(%esp)\n" /* line 2130 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "sete %cl\n"
        "movl %ecx, %esi\n" /* wantMatch */
        /* { scope 2 */
        /* { scope 3 */
        "movl %edi, (%esp)\n" /* line 2095 */
        "calll Dvar_FindVar\n"
        "testl %eax, %eax\n" /* line 2096 */
        "je .Lf154506_0015644a\n"
        "movl %edi, (%esp)\n" /* line 2102 */
        "calll Dvar_GetVariantString\n"
        "movl %eax, 4(%esp)\n" /* line 2103 */
        "leal -0xc3c(%ebp), %eax\n" /* testValue */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        /* } scope */
        /* } scope */
        "movl %esi, %edx\n" /* line 2131 | wantMatch */
        "cmpb %al, %dl\n"
        "jne .Lf154506_00154533\n"
        "leal -0x183c(%ebp), %ecx\n" /* line 2132 | menuName */
        "movl %ecx, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_CloseByName\n"
        "jmp .Lf154506_00154533\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf154506_00156431:\n"
        "movl %edi, 8(%esp)\n" /* line 2098 */
        "movl %ebx, 4(%esp)\n" /* menuIndex */
        "movl $str_002aaf28, (%esp)\n" /* "%s: cannot find dvar %s
" */
        "calll Com_Printf\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf154506_0015644a:\n"
        "movl %edi, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* menuIndex */
        "movl $str_002aaf28, (%esp)\n" /* "%s: cannot find dvar %s
" */
        "calll Com_Printf\n"
        "jmp .Lf154506_00154533\n"
        /* } scope */
        /* } scope */
        ".Lf154506_00156463:\n"
        "movl $str_002aaf44, 4(%esp)\n" /* line 2548 */
        "movl %ebx, (%esp)\n" /* menuIndex */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf154506_0015639d\n"
        "movl %ebx, 4(%esp)\n" /* line 2555 | menuIndex */
        "movl $str_002aaf68, (%esp)\n" /* "unknown UI script %s
" */
        "calll Com_Printf\n"
        "jmp .Lf154506_00154533\n"
    );
}

/* line 3438 */
int UI_FeederCount(float feederID)
{
    if (feederID == 4.0f) {
        /* map list: filter by game type bitmask */
        int gameType = *(int *)((byte *)ui_netGameType + 8);
        int numMaps = *(int *)((byte *)&sharedUiInfo + 4944);
        int count = 0;
        int i;

        if (numMaps <= 0)
            return 0;

        for (i = 0; i < numMaps; i++) {
            byte *entry = (byte *)&sharedUiInfo + i * 0xa4;
            *(int *)(entry + 0x13f4) = 0;
            if ((*(int *)(entry + 0x1368) >> gameType) & 1) {
                count++;
                *(int *)(entry + 0x13f4) = 1;
            }
        }
        return count;
    } else if (feederID == 9.0f) {
        return *(int *)((byte *)&sharedUiInfo + 26484);
    } else if (feederID == 2.0f) {
        /* server list count */
        int serverCount = LAN_GetServerCount(*(int *)((byte *)ui_netSource + 8));
        if (serverCount != *(int *)((byte *)&sharedUiInfo + 108664)) {
            *(int *)((byte *)&sharedUiInfo + 108664) = serverCount;
            if (*(int *)((byte *)&sharedUiInfo + 108660) != 0) {
                *(int *)((byte *)&sharedUiInfo + 28656) = -1;
                UI_BuildServerDisplayList(1);
            }
        }
        return *(int *)((byte *)&sharedUiInfo + 108660);
    } else if (feederID == 13.0f) {
        return *(int *)((byte *)&sharedUiInfo + 113128);
    } else if (feederID == 7.0f || feederID == 20.0f) {
        /* player list count */
        int curTime = *(int *)((byte *)uiInfo + 4);
        if (curTime > *(int *)((byte *)uiInfo + 0x278)) {
            *(int *)((byte *)uiInfo + 0x278) = curTime + 3000;
            UI_BuildPlayerList();
        }
        return *(int *)((byte *)&sharedUiInfo + 68);
    } else if (feederID == 24.0f) {
        return *(int *)((byte *)uiInfo + 0x280);
    }
    return 0;
}

/* line 4714 */
static __attribute__((naked))
void UI_DisplayDownloadInfo(const char *downloadName, float centerPoint, float yStart, FontHandle font, float scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4714 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x18c, %esp\n"
        /* { scope 1: actualScale, actualScale */
        "movl imp_legacyHacks, %eax\n" /* line 4736 */
        "movl (%eax), %eax\n"
        "movl 0x10(%eax), %edi\n" /* downloadSize */
        "movl 0x14(%eax), %edx\n" /* line 4737 */
        "movl %edx, -0x144(%ebp)\n" /* downloadCount */
        "movl 0x18(%eax), %eax\n" /* line 4738 */
        "movl %eax, -0x140(%ebp)\n" /* downloadTime */
        "movl imp_colorBlack, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x3e4ccccd, -0x1c(%ebp)\n" /* line 4742 */
        "movss 0x10(%ebp), %xmm0\n" /* line 4743 | yStart */
        "addss lit4_002ed8cc, %xmm0\n" /* 184.0f */
        "movss %xmm0, -0x15c(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x42aa0000, 0xc(%esp)\n"
        "movl $0x44200000, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "xorl %esi, %esi\n" /* xferRate */
        "movl %esi, (%esp)\n" /* xferRate */
        "calll UI_FillRect\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 4744 | yStart */
        "addss lit4_002ed8d0, %xmm0\n" /* 185.0f */
        "movss %xmm0, -0x158(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x42a60000, 0xc(%esp)\n"
        "movl $0x44200000, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* xferRate */
        "calll UI_FillRect\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 4745 | yStart */
        "addss lit4_002ed8d4, %xmm0\n" /* 186.0f */
        "movss %xmm0, -0x154(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x42a20000, 0xc(%esp)\n"
        "movl $0x44200000, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* xferRate */
        "calll UI_FillRect\n"
        "testl %edi, %edi\n" /* line 4748 | downloadSize */
        "jle .Lf1565ee_00156819\n"
        /* { scope 2: actualScale, actualScale, actualScale */
        "movl imp_colorRed, %edx\n" /* line 199 */
        "movl (%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0x20(%ebp)\n"
        "movl $0x3e19999a, -0x1c(%ebp)\n" /* line 4753 */
        "cvtsi2ssl -0x144(%ebp), %xmm0\n" /* line 4755 | downloadCount */
        "cvtsi2ssl %edi, %xmm1\n" /* downloadSize */
        "divss %xmm1, %xmm0\n"
        "mulss lit4_002ed860, %xmm0\n" /* 640.0f */
        "cvttss2si %xmm0, %ebx\n" /* width */
        "leal -0x28(%ebp), %edx\n" /* line 4757 | color */
        "movl %edx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x42aa0000, 0xc(%esp)\n"
        "leal 2(%ebx), %eax\n" /* width */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x15c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* xferRate */
        "calll UI_FillRect\n"
        "leal -0x28(%ebp), %eax\n" /* line 4758 | color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x42a60000, 0xc(%esp)\n"
        "leal 1(%ebx), %eax\n" /* width */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x158(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* xferRate */
        "calll UI_FillRect\n"
        "leal -0x28(%ebp), %eax\n" /* line 4759 | color */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x42a20000, 0xc(%esp)\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* width */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x154(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* xferRate */
        "calll UI_FillRect\n"
        /* } scope */
        ".Lf1565ee_00156819:\n"
        "movss 0x10(%ebp), %xmm1\n" /* line 4762 | yStart */
        "addss lit4_002ed8d8, %xmm1\n" /* 210.0f */
        "movss %xmm1, -0x150(%ebp)\n"
        "movl $dlText, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl $3, 0x24(%esp)\n"
        "movl imp_colorLtGrey, %esi\n" /* xferRate */
        "movl %esi, 0x20(%esp)\n" /* xferRate */
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x150(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movl $0x41c00000, %ebx\n" /* width */
        "movl %ebx, 0xc(%esp)\n" /* width */
        "movl 0x14(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x40, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 4763 | yStart */
        "addss lit4_002ed8dc, %xmm0\n" /* 235.0f */
        "movss %xmm0, -0x14c(%ebp)\n"
        "movl $etaText, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl $3, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* xferRate */
        "movss 0x18(%ebp), %xmm1\n" /* scale */
        "movss %xmm1, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x14c(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* width */
        "movl 0x14(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x40, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 4764 | yStart */
        "addss lit4_002ed8e0, %xmm0\n" /* 260.0f */
        "movss %xmm0, -0x148(%ebp)\n"
        "movl $xferText, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl $3, 0x24(%esp)\n"
        "movl %esi, 0x20(%esp)\n" /* xferRate */
        "movss 0x18(%ebp), %xmm1\n" /* scale */
        "movss %xmm1, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x148(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* width */
        "movl 0x14(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x40, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "testl %edi, %edi\n" /* line 4766 | downloadSize */
        "jle .Lf1565ee_00156e7e\n"
        "movl -0x144(%ebp), %ecx\n" /* line 4767 | downloadCount */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "shll $2, %eax\n"
        "cltd\n"
        "idivl %edi\n" /* downloadSize */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %esi\n" /* downloadName, xferRate */
        "movl %esi, 4(%esp)\n" /* xferRate */
        "movl $str_002aaf80, (%esp)\n" /* "%s (%d%%)" */
        "calll va\n"
        ".Lf1565ee_001569a8:\n"
        "movl $3, 0x24(%esp)\n" /* line 4772 */
        "movl imp_colorLtGrey, %esi\n" /* xferRate */
        "movl %esi, 0x20(%esp)\n" /* xferRate */
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x150(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movl $0x43400000, 0xc(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movl -0x144(%ebp), %ecx\n" /* line 4774 | downloadCount */
        "movl $0x40, %edx\n"
        "leal -0x68(%ebp), %eax\n" /* dlSizeBuf */
        "calll UI_ReadableSize\n"
        "movl %edi, %ecx\n" /* line 4775 | downloadSize */
        "movl $0x40, %edx\n"
        "leal -0xa8(%ebp), %eax\n" /* totalSizeBuf */
        "calll UI_ReadableSize\n"
        "cmpl $0xfff, -0x144(%ebp)\n" /* line 4777 | downloadCount */
        "jle .Lf1565ee_00156a41\n"
        "movl -0x140(%ebp), %ecx\n" /* downloadTime */
        "testl %ecx, %ecx\n"
        "jne .Lf1565ee_00156bf6\n"
        ".Lf1565ee_00156a41:\n"
        "movl $str_002aaf8c, (%esp)\n" /* line 4779 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* width */
        /* { scope 2: actualScale, actualScale, actualScale */
        /* { scope 3 */
        "movss 0x18(%ebp), %xmm0\n" /* line 379 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x13c(%ebp)\n" /* actualScale */
        "movl 0x14(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl %esi, 0x20(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x14c(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x13c(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0xc(%ebp), %xmm1\n" /* centerPoint */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        "movl $str_002aaf9c, (%esp)\n" /* line 4780 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* width */
        "movl $str_002aafa8, (%esp)\n" /* "EXE_OF" */
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 0x10(%esp)\n" /* width */
        "leal -0xa8(%ebp), %edx\n" /* totalSizeBuf */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x68(%ebp), %ecx\n" /* dlSizeBuf */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002aafb0, (%esp)\n" /* "(%s %s %s %s)" */
        "calll va\n"
        "movl %eax, %ebx\n" /* width */
        /* { scope 2: actualScale, actualScale, actualScale */
        "movss 0x18(%ebp), %xmm0\n" /* line 379 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x138(%ebp)\n" /* actualScale */
        "movl 0x14(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl %esi, 0x20(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss 0x10(%ebp), %xmm1\n" /* yStart */
        "addss lit4_002ed8e4, %xmm1\n" /* 340.0f */
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x138(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0xc(%ebp), %xmm1\n" /* centerPoint */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        /* } scope */
        ".Lf1565ee_00156beb:\n"
        "addl $0x18c, %esp\n" /* line 4829 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: actualScale, actualScale */
        ".Lf1565ee_00156bf6:\n"
        "movl uiInfo, %eax\n" /* line 4785 */
        "movl 4(%eax), %ecx\n"
        "subl -0x140(%ebp), %ecx\n" /* downloadTime */
        "leal 0x3e7(%ecx), %eax\n"
        "cmpl $0x7ce, %eax\n"
        "ja .Lf1565ee_00156e86\n"
        "xorl %esi, %esi\n" /* xferRate */
        "movl %esi, %ecx\n" /* line 4790 | xferRate */
        "movl $0x40, %edx\n"
        "leal -0xe8(%ebp), %eax\n" /* xferRateBuf */
        "calll UI_ReadableSize\n"
        "testl %edi, %edi\n" /* line 4793 | downloadSize */
        "je .Lf1565ee_00156ec0\n"
        ".Lf1565ee_00156c31:\n"
        "testl %esi, %esi\n" /* xferRate */
        "je .Lf1565ee_00156ec0\n"
        /* { scope 2: actualScale, actualScale, actualScale */
        "movl %edi, %eax\n" /* line 4795 | downloadSize */
        "cltd\n"
        "idivl %esi\n" /* xferRate */
        "movl %eax, %ecx\n"
        "movl tleIndex, %ebx\n" /* line 4799 | width */
        "sarl $0xa, -0x144(%ebp)\n" /* downloadCount */
        "movl -0x144(%ebp), %eax\n" /* downloadCount */
        "imull %ecx, %eax\n"
        "movl %edi, %edx\n" /* downloadSize */
        "testl %edi, %edi\n" /* downloadSize */
        "js .Lf1565ee_001571e1\n"
        ".Lf1565ee_00156c60:\n"
        "sarl $0xa, %edx\n"
        "movl %edx, %esi\n" /* timeleft */
        "cltd\n"
        "idivl %esi\n" /* timeleft */
        "subl %eax, %ecx\n"
        "movl %ecx, tleEstimates(, %ebx, 4)\n"
        "leal 1(%ebx), %edx\n" /* line 4800 | width */
        "xorl %eax, %eax\n" /* line 4802 */
        "cmpl $0x50, %edx\n"
        "cmovll %edx, %eax\n"
        "movl %eax, tleIndex\n"
        "xorl %ecx, %ecx\n"
        "movl $tleEstimates, %eax\n"
        "movl $xferText, %edx\n"
        ".Lf1565ee_00156c8d:\n"
        "addl (%eax), %ecx\n" /* line 4805 */
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n" /* line 4804 */
        "jne .Lf1565ee_00156c8d\n"
        "movl $0x66666667, %eax\n" /* line 4807 */
        "imull %ecx\n"
        "movl %edx, %esi\n" /* timeleft */
        "sarl $5, %esi\n" /* timeleft */
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %esi\n" /* timeleft */
        "cmpl $0xe10, %esi\n" /* line 4686 */
        "jg .Lf1565ee_00157172\n"
        "cmpl $0x3c, %esi\n" /* line 4690 */
        "jle .Lf1565ee_0015713b\n"
        "movl $str_002aafe4, (%esp)\n" /* line 4692 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n"
        "movl $str_002aafc0, (%esp)\n" /* "EXE_MINUTES" */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %edi\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl $0x88888889, %edx\n"
        "movl %esi, %eax\n"
        "imull %edx\n"
        "leal (%edx, %esi), %ebx\n"
        "sarl $5, %ebx\n"
        "movl %esi, %eax\n"
        "cltd\n"
        "subl %edx, %ebx\n"
        "leal (, %ebx, 4), %edx\n"
        "movl %ebx, %ecx\n"
        "shll $6, %ecx\n"
        "subl %edx, %ecx\n"
        "movl %esi, %edx\n"
        "subl %ecx, %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        ".Lf1565ee_00156d10:\n"
        "movl $str_002aafd8, 8(%esp)\n" /* "%d %s %d %s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x128(%ebp), %ebx\n" /* dlTimeBuf */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf1565ee_00156d2e:\n"
        "movl $3, 0x24(%esp)\n" /* line 4811 */
        "movl imp_colorLtGrey, %esi\n" /* timeleft */
        "movl %esi, 0x20(%esp)\n" /* timeleft */
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x14c(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movl $0x43840000, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* width */
        "calll UI_DrawText\n"
        "movl $str_002aaf9c, (%esp)\n" /* line 4812 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* width */
        "movl $str_002aafa8, (%esp)\n" /* "EXE_OF" */
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 0x10(%esp)\n" /* width */
        "leal -0xa8(%ebp), %edx\n" /* totalSizeBuf */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x68(%ebp), %ecx\n" /* dlSizeBuf */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002aafb0, (%esp)\n" /* "(%s %s %s %s)" */
        "calll va\n"
        "movl %eax, %ebx\n" /* width */
        /* { scope 3 */
        "movss 0x18(%ebp), %xmm0\n" /* line 379 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x134(%ebp)\n" /* actualScale */
        "movl 0x14(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl %esi, 0x20(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss 0x10(%ebp), %xmm1\n" /* yStart */
        "addss lit4_002ed8e8, %xmm1\n" /* 320.0f */
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x134(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0xc(%ebp), %xmm1\n" /* centerPoint */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        "jmp .Lf1565ee_00157086\n"
        /* } scope */
        ".Lf1565ee_00156e7e:\n"
        "movl 8(%ebp), %eax\n" /* line 4766 | downloadName */
        "jmp .Lf1565ee_001569a8\n"
        ".Lf1565ee_00156e86:\n"
        "movl $0x10624dd3, %edx\n" /* line 4786 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $6, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "movl -0x144(%ebp), %eax\n" /* downloadCount */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "movl %eax, %esi\n" /* xferRate */
        "movl %esi, %ecx\n" /* line 4790 | xferRate */
        "movl $0x40, %edx\n"
        "leal -0xe8(%ebp), %eax\n" /* xferRateBuf */
        "calll UI_ReadableSize\n"
        "testl %edi, %edi\n" /* line 4793 | downloadSize */
        "jne .Lf1565ee_00156c31\n"
        ".Lf1565ee_00156ec0:\n"
        "movl $str_002aaf8c, (%esp)\n" /* line 4817 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* width */
        /* { scope 2: actualScale, actualScale, actualScale */
        /* { scope 3 */
        "movss 0x18(%ebp), %xmm0\n" /* line 379 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x130(%ebp)\n" /* actualScale */
        "movl 0x14(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl imp_colorLtGrey, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x14c(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x130(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0xc(%ebp), %xmm1\n" /* centerPoint */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        "testl %edi, %edi\n" /* line 4818 | downloadSize */
        "je .Lf1565ee_00157111\n"
        "movl $str_002aaf9c, (%esp)\n" /* line 4819 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* width */
        "movl $str_002aafa8, (%esp)\n" /* "EXE_OF" */
        "calll UI_SafeTranslateString\n"
        "movl %ebx, 0x10(%esp)\n" /* width */
        "leal -0xa8(%ebp), %edx\n" /* totalSizeBuf */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x68(%ebp), %ecx\n" /* dlSizeBuf */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002aafb0, (%esp)\n" /* "(%s %s %s %s)" */
        "calll va\n"
        "movl %eax, %ebx\n" /* width */
        /* { scope 2: actualScale, actualScale, actualScale */
        ".Lf1565ee_00156fc8:\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 379 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x12c(%ebp)\n" /* actualScale */
        "movl 0x14(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl imp_colorLtGrey, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss 0x10(%ebp), %xmm1\n" /* yStart */
        "addss lit4_002ed8e8, %xmm1\n" /* 320.0f */
        "movss %xmm1, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x12c(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss 0xc(%ebp), %xmm1\n" /* centerPoint */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        "testl %esi, %esi\n" /* line 4826 | timeleft */
        "je .Lf1565ee_00156beb\n"
        ".Lf1565ee_00157086:\n"
        "movl $str_002aafe4, (%esp)\n" /* line 4827 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 8(%esp)\n"
        "leal -0xe8(%ebp), %edx\n" /* xferRateBuf */
        "movl %edx, 4(%esp)\n"
        "movl $str_00216e18, (%esp)\n" /* "%s/%s" */
        "calll va\n"
        "movl $3, 0x24(%esp)\n"
        "movl imp_colorLtGrey, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movss 0x18(%ebp), %xmm0\n" /* scale */
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movss -0x148(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movl $0x43480000, 0xc(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x18c, %esp\n" /* line 4829 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: actualScale, actualScale */
        ".Lf1565ee_00157111:\n"
        "movl $str_002aaf9c, (%esp)\n" /* line 4821 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x68(%ebp), %eax\n" /* dlSizeBuf */
        "movl %eax, 4(%esp)\n"
        "movl $str_002aaff0, (%esp)\n" /* "(%s %s)" */
        "calll va\n"
        "movl %eax, %ebx\n" /* width */
        "jmp .Lf1565ee_00156fc8\n"
        /* { scope 2: actualScale, actualScale, actualScale */
        ".Lf1565ee_0015713b:\n"
        "movl $str_002aafe4, (%esp)\n" /* line 4696 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $str_002aa79c, 8(%esp)\n" /* "%d %s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x128(%ebp), %ebx\n" /* dlTimeBuf */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf1565ee_00156d2e\n"
        ".Lf1565ee_00157172:\n"
        "movl $str_002aafc0, (%esp)\n" /* line 4688 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n"
        "movl $str_002aafcc, (%esp)\n" /* "EXE_HOURS" */
        "calll UI_SafeTranslateString\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl $0x91a2b3c5, %edx\n"
        "movl %esi, %eax\n"
        "imull %edx\n"
        "leal (%edx, %esi), %edi\n"
        "sarl $0xb, %edi\n"
        "movl %esi, %eax\n"
        "cltd\n"
        "subl %edx, %edi\n"
        "movl %edi, %ecx\n"
        "shll $4, %ecx\n"
        "movl %edi, %edx\n"
        "shll $8, %edx\n"
        "subl %ecx, %edx\n"
        "movl %edx, %ecx\n"
        "shll $4, %ecx\n"
        "subl %edx, %ecx\n"
        "movl %esi, %ebx\n"
        "subl %ecx, %ebx\n"
        "movl $0x88888889, %edx\n"
        "movl %ebx, %eax\n"
        "imull %edx\n"
        "addl %ebx, %edx\n"
        "sarl $5, %edx\n"
        "movl %ebx, %ecx\n"
        "sarl $0x1f, %ecx\n"
        "subl %ecx, %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "jmp .Lf1565ee_00156d10\n"
        ".Lf1565ee_001571e1:\n"
        "leal 0x3ff(%edi), %edx\n" /* line 4799 | downloadSize */
        "jmp .Lf1565ee_00156c60\n"
    );
}

/* line 4845 */
__attribute__((naked))
void UI_DrawConnectScreen(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4845 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8dc, %esp\n"
        /* { scope 1: scale, actualScale, ps, yPrint, ... */
        "movl imp_legacyHacks, %eax\n" /* line 4863 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0x5c(%eax)\n"
        "jne .Lf1571ec_00157212\n"
        "cmpb $0, 0x9c(%eax)\n"
        "je .Lf1571ec_00157529\n"
        ".Lf1571ec_00157212:\n"
        "movl $1, %eax\n"
        ".Lf1571ec_00157217:\n"
        "movl %eax, (%esp)\n"
        "calll CG_DrawInformation\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        "movl $0x3f000000, (%esp)\n" /* line 449 */
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0x8a4(%ebp)\n" /* scale */
        "movl ui_smallFont, %eax\n" /* line 463 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss -0x8a4(%ebp), %xmm0\n" /* scale */
        "jb .Lf1571ec_001574f6\n"
        "movl sharedUiInfo+44, %eax\n" /* line 464 */
        "movl %eax, -0x8ac(%ebp)\n" /* font */
        /* } scope */
        ".Lf1571ec_00157253:\n"
        "leal -0x880(%ebp), %eax\n" /* line 4873 | cstate */
        "movl %eax, (%esp)\n"
        "calll GetClientState\n"
        "cmpb $0, g_mapname\n" /* line 4893 */
        "jne .Lf1571ec_001572ad\n"
        "movl $0, -0x8a8(%ebp)\n" /* bConnectInfoDisplayed */
        "cmpl $4, -0x880(%ebp)\n" /* line 4908 | cstate */
        "jle .Lf1571ec_00157443\n"
        ".Lf1571ec_00157281:\n"
        "movl -0x880(%ebp), %eax\n" /* line 4940 | cstate */
        "cmpl $4, %eax\n"
        "je .Lf1571ec_001574dc\n"
        ".Lf1571ec_00157290:\n"
        "cmpl $5, %eax\n"
        "je .Lf1571ec_00157540\n"
        "cmpl $3, %eax\n"
        "je .Lf1571ec_001575f6\n"
        /* } scope */
        ".Lf1571ec_001572a2:\n"
        "addl $0x8dc, %esp\n" /* line 4981 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: scale, actualScale, ps, yPrint, ... */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        /* { scope 3 */
        ".Lf1571ec_001572ad:\n"
        "movl sharedUiInfo+4424, %ebx\n" /* line 820 */
        "testl %ebx, %ebx\n"
        "jg .Lf1571ec_001575be\n"
        ".Lf1571ec_001572bb:\n"
        "movl $g_gametype, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1571ec_001572c0:\n"
        "movl %eax, (%esp)\n" /* line 4896 | pszGameType */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %esi\n" /* pszGameType, translation */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        "movl $0x3f000000, %ebx\n" /* line 379 */
        "movl %ebx, 4(%esp)\n"
        "movl -0x8ac(%ebp), %edi\n" /* font */
        "movl %edi, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x8a0(%ebp)\n" /* actualScale */
        "movl %edi, 8(%esp)\n" /* line 380 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x42b20000, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x8a0(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed8e8, %xmm0\n" /* 320.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        "movl sharedUiInfo+4944, %eax\n" /* line 791 */
        "testl %eax, %eax\n"
        "jg .Lf1571ec_00157583\n"
        ".Lf1571ec_00157379:\n"
        "movl $g_mapname, %esi\n" /* i */
        /* } scope */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        /* { scope 3 */
        ".Lf1571ec_0015737e:\n"
        "movl $0x3f000000, %ebx\n" /* line 379 */
        "movl %ebx, 4(%esp)\n"
        "movl -0x8ac(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x89c(%ebp)\n" /* actualScale */
        "movl -0x8ac(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x42ee0000, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x89c(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed8e8, %xmm0\n" /* 320.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x8ac(%ebp), %edi\n" /* font */
        "movl %edi, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        "movl $1, -0x8a8(%ebp)\n" /* bConnectInfoDisplayed */
        "cmpl $4, -0x880(%ebp)\n" /* line 4908 | cstate */
        "jg .Lf1571ec_00157281\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_00157443:\n"
        "leal -0x474(%ebp), %eax\n" /* line 4914 */
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %eax, -0x88c(%ebp)\n"
        "cld\n" /* line 4915 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x88c(%ebp), %edi\n" /* len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* len */
        "testl %edi, %edi\n" /* line 4917 | len */
        "jle .Lf1571ec_00157281\n"
        "xorl %edx, %edx\n"
        "movl $0x12b, -0x898(%ebp)\n" /* yPrint */
        "xorl %esi, %esi\n" /* neednewline */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf1571ec_00157484:\n"
        "movl -0x88c(%ebp), %ecx\n" /* line 4845 */
        "addl %ebx, %ecx\n"
        "movzbl (%ecx), %eax\n" /* line 4920 */
        "movb %al, -0x74(%ebp, %edx)\n"
        "cmpl $0x28, %edx\n" /* line 4922 */
        "jle .Lf1571ec_001574a2\n"
        "testl %ebx, %ebx\n" /* i */
        "movl $1, %eax\n"
        "cmovgl %eax, %esi\n" /* neednewline */
        ".Lf1571ec_001574a2:\n"
        "cmpl $0x39, %edx\n" /* line 4926 */
        "jg .Lf1571ec_00157738\n"
        "leal -1(%edi), %eax\n" /* len */
        "cmpl %eax, %ebx\n" /* i */
        "je .Lf1571ec_00157738\n"
        "testl %esi, %esi\n" /* neednewline */
        "je .Lf1571ec_001574c3\n"
        "cmpb $0x20, (%ecx)\n"
        "je .Lf1571ec_00157738\n"
        ".Lf1571ec_001574c3:\n"
        "addl $1, %edx\n"
        ".Lf1571ec_001574c6:\n"
        "addl $1, %ebx\n" /* line 4917 | i */
        "cmpl %ebx, %edi\n" /* i, len */
        "jne .Lf1571ec_00157484\n"
        /* } scope */
        "movl -0x880(%ebp), %eax\n" /* line 4940 | cstate */
        "cmpl $4, %eax\n"
        "jne .Lf1571ec_00157290\n"
        ".Lf1571ec_001574dc:\n"
        "movl -0x8a8(%ebp), %esi\n" /* line 4951 | bConnectInfoDisplayed, neednewline */
        "testl %esi, %esi\n" /* neednewline */
        "jne .Lf1571ec_001572a2\n"
        "movl $str_002ab010, (%esp)\n" /* line 4953 */
        "jmp .Lf1571ec_0015760b\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_001574f6:\n"
        "movl ui_extraBigFont, %eax\n" /* line 465 */
        "movss -0x8a4(%ebp), %xmm0\n" /* scale */
        "ucomiss 8(%eax), %xmm0\n"
        "jae .Lf1571ec_00157530\n"
        "movl ui_bigFont, %eax\n" /* line 467 */
        "ucomiss 8(%eax), %xmm0\n"
        "jae .Lf1571ec_00157728\n"
        "movl sharedUiInfo+56, %edx\n" /* line 470 */
        "movl %edx, -0x8ac(%ebp)\n" /* font */
        "jmp .Lf1571ec_00157253\n"
        /* } scope */
        ".Lf1571ec_00157529:\n"
        "xorl %eax, %eax\n" /* line 4863 */
        "jmp .Lf1571ec_00157217\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_00157530:\n"
        "movl sharedUiInfo+60, %eax\n" /* line 466 */
        "movl %eax, -0x8ac(%ebp)\n" /* font */
        "jmp .Lf1571ec_00157253\n"
        /* } scope */
        ".Lf1571ec_00157540:\n"
        "movl imp_legacyHacks, %eax\n" /* line 4961 */
        "movl (%eax), %eax\n"
        "cmpb $0, 0x1c(%eax)\n"
        "je .Lf1571ec_001572a2\n"
        "movl $0x3f000000, 0x10(%esp)\n" /* line 4963 */
        "movl -0x8ac(%ebp), %edx\n" /* font */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x42b20000, 8(%esp)\n"
        "movl $0x43a00000, 4(%esp)\n"
        "addl $0x1c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DisplayDownloadInfo\n"
        "jmp .Lf1571ec_001572a2\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_00157583:\n"
        "xorl %esi, %esi\n" /* line 791 | i */
        "movl $sharedUiInfo, %ebx\n"
        ".Lf1571ec_0015758a:\n"
        "movl 0x1358(%ebx), %eax\n" /* line 793 */
        "movl %eax, 4(%esp)\n"
        "movl $g_mapname, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1571ec_0015780a\n"
        "addl $1, %esi\n" /* line 791 | i */
        "addl $0xa4, %ebx\n"
        "cmpl %esi, sharedUiInfo+4944\n" /* i */
        "jg .Lf1571ec_0015758a\n"
        "jmp .Lf1571ec_00157379\n"
        /* } scope */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        /* { scope 3 */
        ".Lf1571ec_001575be:\n"
        "xorl %esi, %esi\n" /* line 820 | i */
        "movl $sharedUiInfo, %ebx\n"
        ".Lf1571ec_001575c5:\n"
        "movl 0x114c(%ebx), %eax\n" /* line 822 */
        "movl %eax, 4(%esp)\n"
        "movl $g_gametype, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1571ec_0015781c\n"
        "addl $1, %esi\n" /* line 820 | i */
        "addl $8, %ebx\n"
        "cmpl sharedUiInfo+4424, %esi\n" /* i */
        "jl .Lf1571ec_001575c5\n"
        "jmp .Lf1571ec_001572bb\n"
        /* } scope */
        /* } scope */
        ".Lf1571ec_001575f6:\n"
        "movl -0x8a8(%ebp), %edi\n" /* line 4943 | bConnectInfoDisplayed, len */
        "testl %edi, %edi\n" /* len */
        "jne .Lf1571ec_001572a2\n"
        "movl $str_002aaff8, (%esp)\n" /* line 4945 */
        ".Lf1571ec_0015760b:\n"
        "calll UI_SafeTranslateString\n" /* line 4953 */
        "movl %eax, %esi\n" /* neednewline */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        /* { scope 3 */
        "cld\n" /* line 5218 */
        "movl $0xa, %ecx\n"
        "leal -0x74(%ebp), %edi\n" /* ps, len */
        "movl -0x8a8(%ebp), %eax\n" /* bConnectInfoDisplayed */
        "rep stosl %eax, %es:(%edi)\n" /* len */
        "movl -0x87c(%ebp), %eax\n" /* line 5219 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00215a64, 4(%esp)\n" /* "%d" */
        "leal -0x38(%ebp), %ebx\n" /* tempString, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll sprintf\n"
        "movl $1, -0x74(%ebp)\n" /* line 5220 | ps */
        "movl %ebx, -0x70(%ebp)\n" /* line 5221 | i */
        "leal -0x74(%ebp), %eax\n" /* line 5222 | ps */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* neednewline */
        "calll UI_ReplaceConversions\n"
        "movl %eax, %esi\n" /* neednewline */
        /* } scope */
        /* } scope */
        "testl %eax, %eax\n" /* line 4977 */
        "je .Lf1571ec_001572a2\n"
        "movl $str_002a8ab8, 4(%esp)\n" /* "localhost" */
        "leal -0x874(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf1571ec_001572a2\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        "movl $0x3f000000, %ebx\n" /* line 379 */
        "movl %ebx, 4(%esp)\n"
        "movl -0x8ac(%ebp), %edi\n" /* font */
        "movl %edi, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x890(%ebp)\n" /* actualScale */
        "movl %edi, 8(%esp)\n" /* line 380 */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl imp_colorWhite, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x43110000, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x890(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed8e8, %xmm0\n" /* 320.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* text */
        "calll UI_DrawText\n"
        "jmp .Lf1571ec_001572a2\n"
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_00157728:\n"
        "movl sharedUiInfo+40, %eax\n" /* line 468 */
        "movl %eax, -0x8ac(%ebp)\n" /* font */
        "jmp .Lf1571ec_00157253\n"
        /* } scope */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_00157738:\n"
        "movb $0, -0x73(%ebp, %edx)\n" /* line 4928 */
        /* { scope 3 */
        "movl $0x3f000000, 4(%esp)\n" /* line 379 */
        "movl -0x8ac(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0x894(%ebp)\n" /* actualScale */
        "movl -0x8ac(%ebp), %edx\n" /* line 380 | font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x74(%ebp), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll CL_TextWidth\n"
        /* } scope */
        "movl $6, 0x24(%esp)\n" /* line 4707 */
        "movl imp_colorYellow, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl $0x3f000000, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "cvtsi2ssl -0x898(%ebp), %xmm0\n" /* yPrint */
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0x894(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss lit4_002ed8e8, %xmm0\n" /* 320.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x8ac(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "leal -0x74(%ebp), %eax\n" /* ps */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "addl $0x16, -0x898(%ebp)\n" /* line 4933 | yPrint */
        "xorl %esi, %esi\n" /* neednewline */
        "xorl %edx, %edx\n"
        "jmp .Lf1571ec_001574c6\n"
        /* } scope */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        ".Lf1571ec_0015780a:\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 794 | i */
        "leal (%esi, %eax, 8), %eax\n" /* i */
        "movl sharedUiInfo+4948(, %eax, 4), %esi\n" /* i */
        "jmp .Lf1571ec_0015737e\n"
        /* } scope */
        /* { scope 2: actualScale, convArgs, tempString, actualScale */
        /* { scope 3 */
        ".Lf1571ec_0015781c:\n"
        "movl sharedUiInfo+4432(, %esi, 8), %eax\n" /* line 823 */
        "jmp .Lf1571ec_001572c0\n"
    );
}
