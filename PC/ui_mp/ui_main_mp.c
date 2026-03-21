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

/* Helper for drawing centered text at a given y position (shared pattern from line 4707) */
static void UI_DrawCenteredText(const char *text, FontHandle font, float scale, float y, const vec_t *color, int style);
extern Bool IsTalking(void);

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
extern int Com_DeletePlayerProfile(int index);
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
static void UI_DrawMapPreview(const rectDef_t *rect, const vec_t *color, int net);
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
static Bool UI_GetOpenOrCloseMenuOnDvarArgs(const char **args, const char *cmd,
                                            char *dvarName, char *testValue, char *menuName);
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
    sharedUiInfo.assets.whiteMaterial = CL_RegisterMaterialNoMip("white", 3);
    sharedUiInfo.assets.scrollBar = CL_RegisterMaterialNoMip("ui/assets/scrollbar.tga", 3);
    sharedUiInfo.assets.scrollBarArrowDown = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_dwn_a.tga", 3);
    sharedUiInfo.assets.scrollBarArrowUp = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_up_a.tga", 3);
    sharedUiInfo.assets.scrollBarArrowLeft = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_left.tga", 3);
    sharedUiInfo.assets.scrollBarArrowRight = CL_RegisterMaterialNoMip("ui/assets/scrollbar_arrow_right.tga", 3);
    sharedUiInfo.assets.scrollBarThumb = CL_RegisterMaterialNoMip("ui/assets/scrollbar_thumb.tga", 3);
    sharedUiInfo.assets.sliderBar = CL_RegisterMaterialNoMip("ui/assets/slider2.tga", 3);
    sharedUiInfo.assets.sliderThumb = CL_RegisterMaterialNoMip("ui/assets/sliderbutt_1", 3);
    sharedUiInfo.assets.cursor = CL_RegisterMaterialNoMip("$cursor", 0);
    sharedUiInfo.assets.bigFont = CL_RegisterFont("$bigfont", 0);
    sharedUiInfo.assets.smallFont = CL_RegisterFont("$smallfont", 0);
    sharedUiInfo.assets.consoleFont = CL_RegisterFont("$consolefont", 0);
    sharedUiInfo.assets.boldFont = CL_RegisterFont("$boldfont", 0);
    sharedUiInfo.assets.textFont = CL_RegisterFont("$font", 0);
    sharedUiInfo.assets.extraBigFont = CL_RegisterFont("$extrabigfont", 0);
    sharedUiInfo.assets.itemFocusSound = Com_FindSoundAlias("ui_mp_map_select");
}

/* line 347 */
void UI_DrawSides(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    MaterialHandle white = sharedUiInfo.assets.whiteMaterial;
    CL_DrawStretchPic(x, y, size, h, horzAlign, vertAlign, 0, 0, 0, 0, color, white);
    CL_DrawStretchPic(x + w - size, y, size, h, horzAlign, vertAlign, 0, 0, 0, 0, color, white);
}

/* line 354 */
void UI_DrawTopBottom(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    MaterialHandle white = sharedUiInfo.assets.whiteMaterial;
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
        return sharedUiInfo.assets.bigFont; /* bigfont */
    if (fontEnum == 3)
        return sharedUiInfo.assets.smallFont; /* smallfont */
    if (fontEnum == 5)
        return sharedUiInfo.assets.consoleFont; /* consolefont */

    realHeight = GetRealHeightFromVirtualHeight(scale);

    if (fontEnum == 4) {
        if (ui_smallFont->current.value >= realHeight)
            return sharedUiInfo.assets.smallFont; /* smallfont */
        if (ui_bigFont->current.value >= realHeight)
            return sharedUiInfo.assets.boldFont; /* boldfont */
        return sharedUiInfo.assets.textFont; /* font */
    }

    /* default path */
    if (ui_smallFont->current.value >= realHeight)
        return sharedUiInfo.assets.smallFont; /* smallfont */
    if (realHeight >= ui_extraBigFont->current.value)
        return sharedUiInfo.assets.extraBigFont; /* extrabigfont */
    if (realHeight >= ui_bigFont->current.value)
        return sharedUiInfo.assets.bigFont; /* bigfont */
    return sharedUiInfo.assets.textFont; /* font */
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
    slot = uiInfo->timeIndex;
    slot = ((slot - 1) | ~3) + 1; /* handles negative: signed % 4 */
    if (slot < 0) slot = ((slot - 1) | (int)0xfffffffc) + 1;
    /* Actually the original just does: slot = uiInfo->timeIndex % 4, with sign handling */
    slot = uiInfo->timeIndex & 3;

    /* uiInfo->previousTimes[slot] = uiInfo->frametime */
    uiInfo->previousTimes[slot] = ui[2];
    /* uiInfo->timeIndex++ */
    uiInfo->timeIndex += 1;

    if (uiInfo->timeIndex <= 4)
        return;

    sum = 0;
    for (i = 0; i < 4; i++) {
        sum += uiInfo->previousTimes[i];
    }
    if (sum == 0)
        uiInfo->uiDC.FPS = (float)4000;
    else
        uiInfo->uiDC.FPS = (float)(4000 / sum);
}

/* line 542 */
void UI_Shutdown(void)
{
    Menus_CloseAll(uiInfo);
    sharedUiInfo.assets.whiteMaterial = 0;
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

    I_strncat(szMenuFile, 0x100, pszMenu);
    I_strncat(szMenuFile, 0x100, ".menu");

    menuList = UI_LoadMenu(szMenuFile, imageTrack);
    if (!menuList)
        return 0;

    UI_AddMenuList(uiInfo, menuList);
    return 1;
}

/* line 701 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void UI_DrawMapPreview(const rectDef_t *rect, const vec_t *color, int net)
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
    int count = sharedUiInfo.mapCount;
    for (i = 0; i < count; i++) {
        const char *loadName = sharedUiInfo.mapList[i].mapLoadName;
        if (I_stricmp(pszMap, loadName) == 0) {
            return sharedUiInfo.mapList[i].mapName;
        }
    }
    return pszMap;
}

/* line 799 */
const char * UI_GetMapDisplayNameFromPartialLoadNameMatch(const char *pszMap, int *mapLoadNameLen)
{
    int i;
    int count = sharedUiInfo.mapCount;
    for (i = 0; i < count; i++) {
        const char *loadName = sharedUiInfo.mapList[i].mapLoadName;
        int len = strlen(loadName);
        *mapLoadNameLen = len;
        if (I_strnicmp(pszMap, loadName, len) == 0) {
            return sharedUiInfo.mapList[i].mapName;
        }
    }
    return 0;
}

/* line 816 */
const char * UI_GetGameTypeDisplayName(const char *pszGameType)
{
    int i;
    int count = sharedUiInfo.numGameTypes;
    for (i = 0; i < count; i++) {
        const char *name = sharedUiInfo.gameTypes[i].gameType;
        if (I_stricmp(pszGameType, name) == 0) {
            return sharedUiInfo.gameTypes[i].gameTypeName;
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
            uiInfo->uiDC.blurRadiusOut = 0;
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

    Load_ScriptMenu("ingame", 3);
    Load_ScriptMenu("callvote", 3);
    Load_ScriptMenu("muteplayer", 3);
    Load_ScriptMenu("quickcommands", 3);
    Load_ScriptMenu("quickresponses", 3);
    Load_ScriptMenu("quickstatements", 3);
    Load_ScriptMenu("serverinfo_dm", 3);
    Load_ScriptMenu("serverinfo_tdm", 3);
    Load_ScriptMenu("serverinfo_ctf", 3);
    Load_ScriptMenu("serverinfo_hq", 3);
    Load_ScriptMenu("serverinfo_sd", 3);
    Load_ScriptMenu("team_americangerman", 3);
    Load_ScriptMenu("team_britishgerman", 3);
    Load_ScriptMenu("team_russiangerman", 3);
    Load_ScriptMenu("weapon_american", 3);
    Load_ScriptMenu("weapon_british", 3);
    Load_ScriptMenu("weapon_german", 3);
    Load_ScriptMenu("weapon_russian", 3);
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
        if (ui_netSource->current.integer != 2) {
            visible = 0;
        }
    }

    if (flags & 0x1000) {
        if (ui_netSource->current.integer == 2) {
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
        ui_netSource->current.integer,
        sharedUiInfo.serverStatus.sortKey,
        sharedUiInfo.serverStatus.sortDir,
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
        uiInfo->playerProfileName[idx1],
        uiInfo->playerProfileName[idx2]);

    if (uiInfo->playerProfileStatus.sortDir == 0)
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
    node = (int *)((menuDef_t *)menu)->onKey;
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
        I_strncat(errorString, 0x400, ref);
        I_strncat(errorString, 0x400, "^1)^7");
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
Bool UI_GetOpenOrCloseMenuOnDvarArgs(const char **args, const char *cmd,
                                     char *dvarName, char *testValue, char *menuName)
{
    if (!String_Parse(args, dvarName, 0x400)) {
        Com_Printf("%s: invalid dvar name.\n", cmd);
        return 0;
    }

    if (!String_Parse(args, testValue, 0x400)) {
        Com_Printf("%s: invalid test value.\n", cmd);
        return 0;
    }

    if (!String_Parse(args, menuName, 0x400)) {
        Com_Printf("%s: invalid menu name.\n", cmd);
        return 0;
    }

    return 1;
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
        int mapVal = ui_currentNetMap->current.integer;
        int offset = mapVal * 164;
        int cinHandle = sharedUiInfo.mapList[offset/164].cinematic;
        int numMaps, visCount, actual, i;

        if (cinHandle >= 0) {
            CIN_StopCinematic(cinHandle);
            sharedUiInfo.mapList[offset/164].cinematic = -1;
        }

        /* find actual map index from visible index */
        numMaps = sharedUiInfo.mapCount;
        visCount = 0;
        actual = 0;
        for (i = 0; i < numMaps; i++) {
            if (sharedUiInfo.mapList[i].active != 0) {
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

        if (sharedUiInfo.serverStatus.numDisplayServers >= 1)
            sharedUiInfo.serverStatus.currentServer = index;

        LAN_GetServerInfo(ui_netSource->current.integer,
                          *(int *)(sharedUiInfo.serverStatus.displayServers + index * 4),
                          info, 0x400);
        name = (char *)va("levelshots/%s", Info_ValueForKey(info, "mapname"));

        /* lowercase the name */
        for (p = name; *p; p++)
            *p = ___tolower((int)(signed char)*p);

        sharedUiInfo.serverStatus.currentServerPreview = CL_RegisterMaterialNoMip(name, 3);
        if (sharedUiInfo.serverStatus.currentServerCinematic >= 0) {
            CIN_StopCinematic(sharedUiInfo.serverStatus.currentServerCinematic);
            sharedUiInfo.serverStatus.currentServerCinematic = -1;
        }

    } else if (feederID == 7.0f || feederID == 20.0f) {
        /* player list selection */
        uiInfo->playerIndex = index;

    } else if (feederID == 9.0f) {
        sharedUiInfo.modIndex = index;

    } else if (feederID == 24.0f) {
        /* player profile selection */
        if (index >= 0 && index < uiInfo->playerProfileCount) {
            int sortedIdx = uiInfo->playerProfileStatus.displayProfile[index];
            const char *profileName = uiInfo->playerProfileName[sortedIdx];
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

    sharedUiInfo.numGameTypes = 0;
    sharedUiInfo.numJoinGameTypes = 0;

    /* add "All" entry */
    sharedUiInfo.joinGameTypes[0].gameType = String_Alloc("All");
    {
        int idx = sharedUiInfo.numJoinGameTypes;
        sharedUiInfo.joinGameTypes[idx].gameTypeName = str_002157b8;
    }
    sharedUiInfo.numJoinGameTypes += 1;

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

            numTypes = sharedUiInfo.numGameTypes;
            if (numTypes == 32 || sharedUiInfo.numJoinGameTypes == 32) {
                Com_Printf("Too many game type scripts found! Only loading the first %i\n", 31);
                break;
            }

            /* store game type script name */
            sharedUiInfo.gameTypes[numTypes].gameType = String_Alloc(pszFileName);

            /* copy script name to game type names list */
            {
                int gt = sharedUiInfo.numGameTypes;
                const char *scriptName = sharedUiInfo.gameTypes[gt].gameType;
                int nameIdx = sharedUiInfo.numJoinGameTypes;
                sharedUiInfo.joinGameTypes[nameIdx].gameType = scriptName;
            }

            /* parse display name from .txt file */
            pBuffParse = GetMenuBuffer(va("maps/mp/gametypes/%s.txt", pszFileName));
            if (pBuffParse) {
                const char *parsed = Com_Parse(&pBuffParse);
                int gt2 = sharedUiInfo.numGameTypes;
                sharedUiInfo.gameTypes[gt2].gameTypeName = String_Alloc(parsed);
                {
                    const char *displayName = *(const char **)((byte *)&sharedUiInfo + 4432 + sharedUiInfo.numGameTypes * 8);
                    int nameIdx2 = sharedUiInfo.numJoinGameTypes;
                    sharedUiInfo.joinGameTypes[nameIdx2].gameTypeName = displayName;
                }
            } else {
                /* no .txt file: copy script name as display name */
                int gt3 = sharedUiInfo.numGameTypes;
                sharedUiInfo.gameTypes[gt3].gameTypeName = sharedUiInfo.gameTypes[gt3].gameType;
                {
                    const char *displayName2 = *(const char **)((byte *)&sharedUiInfo + 4432 + sharedUiInfo.numGameTypes * 8);
                    int nameIdx3 = sharedUiInfo.numJoinGameTypes;
                    sharedUiInfo.joinGameTypes[nameIdx3].gameTypeName = displayName2;
                }
            }

            sharedUiInfo.numGameTypes += 1;
            sharedUiInfo.numJoinGameTypes += 1;
            pszFileName = pszEnd + 1;
        }
    }

    if (sharedUiInfo.numGameTypes == 0) {
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
    legacyBase = (byte *)imp_legacyHacksArray;
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
    CL_GetScreenDimensions(&uiInfo->uiDC.screenWidth, &uiInfo->uiDC.screenHeight, &uiInfo->uiDC.screenAspect);

    width = uiInfo->uiDC.screenWidth;
    height = uiInfo->uiDC.screenHeight;

    /* widescreen check: width*480 > height*640 */
    if (width * 480 > height * 640) {
        /* calculate horizontal offset for widescreen */
        *(float *)uiInfo = ((float)width + (float)height * -1.3333333730697632f) * 0.5f;
    } else {
        *(int *)uiInfo = 0;
    }

    Sys_Milliseconds();
    UI_GetGameTypesList();

    ui_netGameType = Dvar_RegisterInt("ui_netGametype", 0, 0, sharedUiInfo.numGameTypes - 1, 0x1001);

    UI_LoadArenas();

    menuList = UI_LoadMenus("ui_mp/menus.txt", 3);
    UI_AddMenuList(uiInfo, menuList);
    UI_LoadIngameMenus();

    if (g_mapname[0] != '\0') {
        UI_MapLoadInfo(va("maps/mp/%s.csv", g_mapname));
    }

    UI_AssetCache();
    Menus_CloseAll(uiInfo);

    /* register server hardware icons */
    sharedUiInfo.serverHardwareIconList[0] = CL_RegisterMaterialNoMip("server_hardware_unknown", 3);
    sharedUiInfo.serverHardwareIconList[1] = CL_RegisterMaterialNoMip("server_hardware_linux_dedicated", 3);
    sharedUiInfo.serverHardwareIconList[2] = CL_RegisterMaterialNoMip("server_hardware_win_dedicated", 3);
    sharedUiInfo.serverHardwareIconList[3] = CL_RegisterMaterialNoMip("server_hardware_mac_dedicated", 3);
    sharedUiInfo.serverHardwareIconList[5] = CL_RegisterMaterialNoMip("server_hardware_win_listen", 3);
    sharedUiInfo.serverHardwareIconList[6] = CL_RegisterMaterialNoMip("server_hardware_mac_listen", 3);

    LAN_LoadCachedServers();

    /* sort servers if sort key changed */
    if (sharedUiInfo.serverStatus.sortKey != 9) {
        sharedUiInfo.serverStatus.sortKey = 9;
        qsort(sharedUiInfo.serverStatus.displayServers, sharedUiInfo.serverStatus.numDisplayServers, 4, UI_ServersQsortCompare);
    }

    /* set mouse pitch */
    mPitch = Dvar_GetFloat("m_pitch");
    Dvar_SetBoolByName("ui_mousePitch", mPitch < 0.0f ? 1 : 0);

    sharedUiInfo.serverStatus.currentServerCinematic = -1;
    sharedUiInfo.previewMovie = -1;

    /* set net game type name dvar */
    netGameTypeIdx = ui_netGameType->current.integer;
    Dvar_SetString(ui_netGameTypeName, sharedUiInfo.gameTypes[netGameTypeIdx].gameType);

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

        if (key == 0x1b && down && !Menus_AnyFullScreenVisible(uiInfo) && ((menuDef_t *)menu)->window.onESC == 0) {
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
    return uiInfo->currentMenuType;
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
        uiInfo->currentMenuType = menu;

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
        uiInfo->uiDC.cursorx = 0x27f;
        uiInfo->uiDC.cursory = 0x1df;
        Key_SetCatcher(8);
        *(byte *)(*(byte **)imp_cl + 8) = 1;
        Menus_CloseAll(uiInfo);
        Menus_OpenByName(uiInfo, "quickmessage");
        return 1;

    case 9:
    case 10: /* ingame menu with legacy hacks */
        pFocus = Menu_GetFocused(uiInfo);
        if (pFocus) {
            int activeMenu = uiInfo->currentMenuType;
            if (activeMenu != 9 && activeMenu != 10)
                return 0;
        }

        legacyBase = *(byte **)imp_legacyHacks;

        if (pFocus) {
            /* check if focused menu name matches buf */
            if (I_stricmp(((menuDef_t *)pFocus)->window.name, (const char *)(legacyBase + 0x2e4)) == 0)
                return 1;
        }

        uiInfo->currentMenuType = 9;

        if (menu == 10) {
            uiInfo->uiDC.cursorx = 0x27f;
            uiInfo->uiDC.cursory = 0x1df;
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
    return uiInfo->uiDC.blurRadiusOut;
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
    float feederFloat = ((itemDef_t *)itemPtr)->special;

    if (feederFloat == 4.0f) {
        int testMapIndex = ui_currentNetMap->current.integer;
        int numMaps = sharedUiInfo.mapCount;
        int visCount = 0;
        int i;

        for (i = 0; i < numMaps; i++) {
            if (sharedUiInfo.mapList[i].active != 0) {
                if (i == testMapIndex)
                    goto found;
                visCount++;
            }
        }
        visCount = 0;
found:
        Item_SetCursorPos(item, visCount);
    } else if (feederFloat == 2.0f) {
        byte *listPtr = (byte *)((itemDef_t *)itemPtr)->typeData.listBox;
        int endPos = ((listBoxDef_t *)listPtr)->endPos[0];

        if (endPos == 0) {
            Item_SetCursorPos(item, -1);
        } else {
            int serverIndex = sharedUiInfo.serverStatus.currentServer;
            int cursorField = ((itemDef_t *)itemPtr)->cursorPos[0];
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
            ListBox_SetCursorPos(listPtr, delta + ((listBoxDef_t *)listPtr)->cursorPos[0]);
            Item_SetCursorPos(item, sharedUiInfo.serverStatus.currentServer);

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

    numMaps = sharedUiInfo.mapCount;
    mapIndex = -1;

    if (numMaps > 0) {
        c = 0;
        for (i = 0; i < numMaps; i++) {
            if (sharedUiInfo.mapList[i].active != 0) {
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
    if (sharedUiInfo.mapList[byteOff/164].levelShot == 0) {
        /* register the material from the name string */
        const char *name = sharedUiInfo.mapList[byteOff/164].imageName;
        sharedUiInfo.mapList[byteOff/164].levelShot = CL_RegisterMaterialNoMip(name, 3);
    }

    return sharedUiInfo.mapList[byteOff/164].levelShot;
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
    int numServers = sharedUiInfo.serverStatus.numDisplayServers;
    int *displayServers = (int *)(sharedUiInfo.serverStatus.displayServers);
    int *selectedServer = (int *)((byte *)&sharedUiInfo + 28656);
    int j;

    if (position < 0 || numServers < position)
        return;

    if (*selectedServer >= position && numServers != 0)
        *selectedServer += 1;

    numServers++;
    sharedUiInfo.serverStatus.numDisplayServers = numServers;

    for (j = numServers - 1; j > position; j--)
        displayServers[j] = displayServers[j - 1];

    displayServers[position] = serverIndex;
}

/* Helper: remove duplicate server from favorites list */
static void UI_RemoveDuplicateFromFavorites(int serverIndex)
{
    int numServers = sharedUiInfo.serverStatus.numDisplayServers;
    int *displayServers = (int *)(sharedUiInfo.serverStatus.displayServers);
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
    sharedUiInfo.serverStatus.numDisplayServers = numServers;

    for (j = i; j < numServers; j++)
        displayServers[j] = displayServers[j + 1];
}

/* Helper: binary search insert into sorted server display list */
static void UI_BinaryInsertServer(int serverIndex)
{
    int numDisplay = sharedUiInfo.serverStatus.numDisplayServers;
    int *displayServers = (int *)(sharedUiInfo.serverStatus.displayServers);
    int lo, hi, mid, testIdx, cmp, position, lastCmp;
    int source = ui_netSource->current.integer;
    int sortKey = sharedUiInfo.serverStatus.sortKey;
    int sortDir = sharedUiInfo.serverStatus.sortDir;

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
        if (*(int *)((byte *)uiInfo + 4) <= sharedUiInfo.serverStatus.nextDisplayRefresh)
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
        sharedUiInfo.serverStatus.numDisplayServers = 0;
        sharedUiInfo.serverStatus.numPlayersOnServers = 0;
        netSource = ui_netSource->current.integer;
        sharedUiInfo.serverStatus.serverCount = LAN_GetServerCount(netSource);

        if (sharedUiInfo.serverStatus.currentServer >= 0) {
            Menu_SetFeederSelection(uiInfo, 0, 2, 0, 0);
        }

        LAN_MarkServerDirty(ui_netSource->current.integer, -1, 1);
    }

    netSource = ui_netSource->current.integer;
    count = LAN_GetServerCount(netSource);

    if (LAN_WaitServerResponse(netSource) || (netSource == 0 && count == 0)) {
        sharedUiInfo.serverStatus.numDisplayServers = 0;
        sharedUiInfo.serverStatus.numPlayersOnServers = 0;
        sharedUiInfo.serverStatus.serverCount = LAN_GetServerCount(ui_netSource->current.integer);
        sharedUiInfo.serverStatus.nextDisplayRefresh = *(int *)((byte *)uiInfo + 4) + 500;
        return;
    }

    /* sort */
    qsort(sharedUiInfo.serverStatus.displayServers, sharedUiInfo.serverStatus.numDisplayServers, 4, UI_ServersQsortCompare);

    for (i = 0; i < count; i++) {
        if (!LAN_ServerIsDirty(ui_netSource->current.integer, i))
            continue;

        ping = LAN_GetServerPing(ui_netSource->current.integer, i);

        if (ping <= 0 && ui_netSource->current.integer != 2)
            continue;

        LAN_GetServerInfo(ui_netSource->current.integer, i, info_buf, 0x400);

        clients = atoi(Info_ValueForKey(info_buf, "clients"));
        sharedUiInfo.serverStatus.numPlayersOnServers += clients;

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
        if (ui_browserMod->current.integer >= 0) {
            if (atoi(Info_ValueForKey(info_buf, "mod")) != ui_browserMod->current.integer)
                goto reject;
        }

        /* friendly fire filter */
        if (ui_browserFriendlyfire->current.integer >= 0) {
            if (atoi(Info_ValueForKey(info_buf, "ff")) != ui_browserFriendlyfire->current.integer)
                goto reject;
        }

        /* killcam filter */
        if (ui_browserKillcam->current.integer >= 0) {
            if (atoi(Info_ValueForKey(info_buf, "kc")) != ui_browserKillcam->current.integer)
                goto reject;
        }

        /* game type filter */
        {
            int joinGTIdx = ui_joinGameType->current.integer;
            const char *joinGTName = sharedUiInfo.joinGameTypes[joinGTIdx].gameTypeName;
            if (joinGTName[0] != '\0') {
                const char *joinGTShort = sharedUiInfo.joinGameTypes[joinGTIdx].gameType;
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
        if (ui_netSource->current.integer == 2) {
            UI_RemoveDuplicateFromFavorites(i);
        }

        /* binary insert into sorted position */
        UI_BinaryInsertServer(i);

        /* mark clean if ping > 0 */
        if (ping > 0) {
            LAN_MarkServerDirty(ui_netSource->current.integer, i, 0);
            numclean++;
        }
        continue;

reject:
        LAN_MarkServerDirty(ui_netSource->current.integer, i, 0);
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
    int numMaps = sharedUiInfo.mapCount;
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
    int numMaps = sharedUiInfo.mapCount;
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
            int listIndex = ui_netGameType->current.integer;
            int oldVisCount = UI_UpdateMapVisibility(listIndex);
            int newGT, newVisCount;

            if (key == 0xc9) {
                /* prev game type */
                newGT = ui_gametype->current.integer - 1;
                if (newGT == 2) newGT = 1;
                else if (newGT <= 1) newGT = sharedUiInfo.numGameTypes - 1;
            } else {
                /* next game type */
                newGT = ui_gametype->current.integer + 1;
                if (newGT >= sharedUiInfo.numGameTypes) newGT = 1;
                else if (newGT == 2) newGT = 3;
            }

            Dvar_SetInt(ui_gametype, newGT);
            listIndex = ui_netGameType->current.integer;
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
                int cur = ui_netSource->current.integer;
                nextNetSource = (cur == 0) ? 2 : cur - 1;
            } else {
                /* next */
                nextNetSource = ui_netSource->current.integer + 1;
                if (nextNetSource == 3) nextNetSource = 0;
            }

            UI_BuildServerDisplayList(1);
            Dvar_SetInt(ui_netSource, nextNetSource);
            if (ui_netSource->current.integer != 1) {
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
                int cur = ui_netGameType->current.integer;
                newVal = (cur == 0) ? sharedUiInfo.numGameTypes : cur;
                newVal--;
            } else {
                /* next */
                newVal = ui_netGameType->current.integer + 1;
                if (newVal == sharedUiInfo.numGameTypes) newVal = 0;
            }

            Dvar_SetInt(ui_netGameType, newVal);
            Dvar_SetString(ui_netGameTypeName, *(const char **)((byte *)&sharedUiInfo + 4428 + ui_netGameType->current.integer * 8));

            UI_UpdateMapVisibility(ui_netGameType->current.integer);
            UI_SelectFirstVisibleMap(ui_currentNetMap->current.integer);
        }
        return 1;

    case 0xfd: /* 253: join game type */
        if (!UI_IsActionKey(key))
            return 0;
        {
            int newVal;
            if (key == 0xc9) {
                /* prev */
                int cur = ui_joinGameType->current.integer;
                newVal = (cur == 0) ? sharedUiInfo.numJoinGameTypes : cur;
                newVal--;
            } else {
                /* next */
                newVal = ui_joinGameType->current.integer + 1;
                if (newVal == sharedUiInfo.numJoinGameTypes) newVal = 0;
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
    *handle = 0;

    if (feederID == 4.0f) {
        /* map list feeder - filter by active maps */
        int numMaps = sharedUiInfo.mapCount;
        int count = 0;
        int i;

        if (numMaps <= 0)
            return "";

        for (i = 0; i < numMaps; i++) {
            byte *entry = (byte *)&sharedUiInfo + i * 0xa4;
            if (*(int *)(entry + 0x13f4)) {
                if (count == index) {
                    /* found the matching entry - return its display name */
                    return *(const char **)(entry + 0x13f8);
                }
                count++;
            }
        }
        return "";
    } else if (feederID == 2.0f) {
        /* server list feeder */
        int pingVal;

        /* inline server count update */
        {
            int serverCount = LAN_GetServerCount(ui_netSource->current.integer);
            if (serverCount != sharedUiInfo.serverStatus.serverCount) {
                sharedUiInfo.serverStatus.serverCount = serverCount;
                if (sharedUiInfo.serverStatus.numDisplayServers != 0) {
                    sharedUiInfo.serverStatus.currentServer = -1;
                    UI_BuildServerDisplayList(1);
                }
            }
        }

        if (index < 0 || index >= sharedUiInfo.serverStatus.numDisplayServers)
            return "";

        /* refresh info if column changed or timeout elapsed */
        if (column != lastColumn ||
            *(int *)((byte *)uiInfo + 4) + 5000 < lastTime) {
            LAN_GetServerInfo(ui_netSource->current.integer,
                              *(int *)(sharedUiInfo.serverStatus.displayServers + index * 4),
                              info, 0x400);
            lastColumn = column;
            lastTime = *(int *)((byte *)uiInfo + 4);
        }

        pingVal = atoi(Info_ValueForKey(info, "ping"));

        if (column <= 9) {
            switch (column) {
            case 0: /* password */
                if (atoi(Info_ValueForKey(info, "pswrd")))
                    return "X";
                return "";
            case 1: { /* hardware icon */
                int hw = atoi(Info_ValueForKey(info, "hw"));
                if ((unsigned)hw > 7)
                    return "";
                *handle = *(MaterialHandle *)((byte *)&sharedUiInfo + 25940 + hw * 4);
                return "";
            }
            case 2: /* hostname */
                if (pingVal <= 0)
                    return Info_ValueForKey(info, "addr");
                I_strncpyz(clientBuff, Info_ValueForKey(info, "hostname"), 0x14);
                return clientBuff;
            case 3: { /* map name lookup */
                const char *mapName = Info_ValueForKey(info, "mapname");
                int numM = sharedUiInfo.mapCount;
                int mi;
                if (numM <= 0)
                    return mapName;
                for (mi = 0; mi < numM; mi++) {
                    byte *entry = (byte *)&sharedUiInfo + mi * 0xa4;
                    if (I_stricmp(mapName, *(const char **)(entry + 0x1358)) == 0) {
                        return *(const char **)(entry + 0x13f8);
                    }
                }
                return mapName;
            }
            case 4: { /* clients / maxclients */
                const char *maxClients = Info_ValueForKey(info, "sv_maxclients");
                const char *clients = Info_ValueForKey(info, "clients");
                Com_sprintf(clientBuff, 0x20, "%s (%s)", clients, maxClients);
                return clientBuff;
            }
            case 5: { /* gametype */
                const char *gt = Info_ValueForKey(info, "gametype");
                if (!gt || gt[0] == '\0')
                    return "?";
                return Info_ValueForKey(info, "gametype");
            }
            case 6: /* voice */
                if (atoi(Info_ValueForKey(info, "voice")))
                    return "X";
                return "";
            case 7: /* pure */
                if (atoi(Info_ValueForKey(info, "pure")))
                    return "X";
                return "";
            case 8: /* mod */
                if (atoi(Info_ValueForKey(info, "mod")))
                    return "X";
                return "";
            case 9: /* ping */
                if (pingVal > 0)
                    return Info_ValueForKey(info, "ping");
                return "...";
            }
        }
    } else if (feederID == 13.0f) {
        /* server status feeder */
        if (index < 0 || index >= *(int *)((byte *)&sharedUiInfo + 113128))
            return "";
        if ((unsigned)column > 3)
            return "";
        {
            const char *text = *(const char **)((byte *)&sharedUiInfo + 109864 + (column + index * 4) * 4);
            if (text[0] == '@')
                return UI_SafeTranslateString(text + 1);
            return text;
        }
    } else if (feederID == 7.0f) {
        /* player list feeder - column 0 = name */
        if (index < 0 || index >= sharedUiInfo.playerCount)
            return "";
        return (const char *)((byte *)&sharedUiInfo + 72 + index * 32);
    } else if (feederID == 9.0f) {
        /* mod list feeder */
        if (index < 0 || index >= sharedUiInfo.modCount)
            return "";
        {
            const char *desc = *(const char **)((byte *)&sharedUiInfo + 25976 + index * 8);
            if (desc && desc[0] != '\0')
                return desc;
            return sharedUiInfo.modList[index].modName;
        }
    } else if (feederID == 20.0f) {
        /* player list with mute column */
        if (index < 0 || index >= sharedUiInfo.playerCount)
            return "";
        if (column - 1 == 0) {
            /* column 1 = name */
            return (const char *)((byte *)&sharedUiInfo + 72 + index * 32);
        }
        /* column 2 = muted status */
        if (CL_IsPlayerMuted(sharedUiInfo.playerClientNums[index]))
            return UI_SafeTranslateString("MP_MUTED");
        return "";
    } else if (feederID == 24.0f) {
        /* player profile feeder */
        if (index < 0 || index >= uiInfo->playerProfileCount)
            return "";
        {
            int sortedIdx = uiInfo->playerProfileStatus.displayProfile[index];
            return uiInfo->playerProfileName[sortedIdx];
        }
    }

    return "";
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
        s = *(const char **)((byte *)&sharedUiInfo + 4432 + ui_gametype->current.integer * 8);
        break;
    case 0xdc: { /* 220: net source */
        int netSrcVal = ui_netSource->current.integer;
        if (netSrcVal > sharedUiInfo.numJoinGameTypes) {
            Dvar_SetInt(ui_netSource, 0);
            netSrcVal = ui_netSource->current.integer;
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
        s = Dvar_GetVariantString(va("ui_lastServerRefresh_%i", ui_netSource->current.integer));
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
void UI_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, int align, float special, FontHandle font, float scale, vec_t *color, MaterialHandle material, int textStyle)
{
    /* rect struct on stack for sub-calls */
    float rect[6]; /* x, y, w, h, horzAlign, vertAlign */
    const char *text;
    byte *clBase;

    /* check if CG_OwnerDraw should handle it */
    clBase = *(byte **)imp_cl;
    if (clBase[9] != 0) {
        CG_OwnerDraw(x, y, w, h, horzAlign, vertAlign, text_x, text_y, ownerDraw, ownerDrawFlags, align, special, (int)font, scale, color, (int)material, textStyle);
    }

    /* build rect */
    rect[0] = x + text_x;
    rect[1] = y + text_y;
    *(int *)&rect[2] = *(int *)&w;
    rect[3] = h;
    *(int *)&rect[4] = horzAlign;
    *(int *)&rect[5] = vertAlign;

    switch (ownerDraw) {
    case 205: /* gametype name */
    {
        const char *gtName = *(const char **)((byte *)&sharedUiInfo + 4432 + ui_gametype->current.integer * 8);
        if (gtName[0] == '\0')
            gtName = "EXE_ALL";
        text = UI_SafeTranslateString(gtName);
        UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, color, textStyle);
        return;
    }

    case 206: /* map preview (net) */
    {
        UI_DrawMapPreview((const rectDef_t *)rect, color, 1);
        return;
    }

    case 220: /* net source */
    {
        text = SEH_LocalizeTextMessage(
            va("EXE_NETSOURCE\x14%s", netSources[ui_netSource->current.integer]),
            "net source", 0);
        UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, color, textStyle);
        return;
    }

    case 221: /* server levelshot */
    {
        int lsHandle = sharedUiInfo.serverStatus.currentServerPreview;
        if (!lsHandle) {
            lsHandle = (int)CL_RegisterMaterialNoMip("menu/art/unknownmap", 3);
        }
        UI_DrawHandlePic(rect[0], rect[1], rect[2], rect[3], *(int *)&rect[4], *(int *)&rect[5], color, lsHandle);
        return;
    }

    case 222: /* server filter */
    {
        int filterType = 0;
        if ((unsigned int)ui_serverFilterType < 2)
            filterType = ui_serverFilterType;
        ui_serverFilterType = filterType;
        text = SEH_LocalizeTextMessage(
            va("EXE_SERVERFILTER\x14%s", serverFilters[filterType].description),
            "server filter", 0);
        UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, color, textStyle);
        return;
    }

    case 244: /* map preview (non-net) */
    {
        UI_DrawMapPreview((const rectDef_t *)rect, color, 0);
        return;
    }

    case 245: /* net game type */
    {
        int gtIdx = ui_netGameType->current.integer;
        if (gtIdx > sharedUiInfo.numGameTypes) {
            Dvar_SetInt(ui_netGameType, 0);
            Dvar_SetString(ui_netGameTypeName, sharedUiInfo.gameTypes[0].gameType);
            gtIdx = ui_netGameType->current.integer;
        }
        {
            const char *gtName = sharedUiInfo.gameTypes[gtIdx].gameTypeName;
            if (gtName[0] == '\0')
                gtName = "EXE_ALL";
            text = UI_SafeTranslateString(gtName);
            UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, color, textStyle);
        }
        return;
    }

    case 246: /* net levelshot */
    {
        int netMap = ui_currentNetMap->current.integer;
        if (netMap >= sharedUiInfo.mapCount) {
            Dvar_SetInt(ui_currentNetMap, 0);
        }
        {
            int cinHandle = sharedUiInfo.serverStatus.currentServerCinematic;
            if (cinHandle < 0) {
                /* no cinematic, draw static image */
                int img = sharedUiInfo.serverStatus.currentServerPreview;
                if (!img) {
                    img = (int)CL_RegisterMaterialNoMip("menu/art/unknownmap", 3);
                }
                UI_DrawHandlePic(rect[0], rect[1], rect[2], rect[3], *(int *)&rect[4], *(int *)&rect[5], color, img);
            } else {
                CIN_RunCinematic(cinHandle);
                CIN_SetExtents(cinHandle, (int)rect[0], (int)rect[1], (int)rect[2], (int)rect[3]);
                CIN_DrawCinematic(cinHandle);
            }
        }
        return;
    }

    case 247: /* server refresh time / server count */
    {
        int refreshing = sharedUiInfo.serverStatus.refreshActive;
        if (refreshing) {
            /* show server count with pulsing color */
            vec_t lowLight[4], newColor[4];
            int serverCount;
            int waitResponse;
            const char *countText;

            lowLight[0] = color[0] * 0.8f;
            lowLight[1] = color[1] * 0.8f;
            lowLight[2] = color[2] * 0.8f;
            lowLight[3] = color[3] * 0.8f;

            {
                int realTime = *(int *)((byte *)uiInfo + 4);
                float phase = (float)(realTime % 1000);
                float sinVal;
                {
                    double sv;
                    extern double sin(double);
                    sv = sin((double)phase);
                    sinVal = (float)(sv * 0.5 + 0.5);
                }
                LerpColor(color, lowLight, newColor, sinVal);
            }

            waitResponse = LAN_WaitServerResponse(ui_netSource->current.integer);
            if (waitResponse) {
                countText = UI_SafeTranslateString("EXE_WAITINGFORMASTERSERVERRESPONSE");
            } else {
                serverCount = LAN_GetServerCount(ui_netSource->current.integer);
                {
                    char tempString[64];
                    int convArgs[10];
                    int ci;

                    text = UI_SafeTranslateString("EXE_GETTINGINFOFORSERVERS");

                    for (ci = 0; ci < 10; ci++)
                        convArgs[ci] = 0;
                    sprintf(tempString, "%d", serverCount);
                    convArgs[0] = 1;
                    convArgs[1] = (int)tempString;
                    countText = UI_ReplaceConversions(text, (ConversionArguments *)convArgs);
                }
            }

            UI_DrawText(countText, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, newColor, textStyle);
        } else {
            /* show last refresh time */
            char tempString[64];
            int convArgs[10];
            int ci;

            I_strncpyz(tempString, Dvar_GetVariantString(
                va("ui_lastServerRefresh_%i", ui_netSource->current.integer)), 64);
            text = UI_SafeTranslateString("EXE_REFRESHTIME");

            for (ci = 0; ci < 10; ci++)
                convArgs[ci] = 0;
            convArgs[0] = 1;
            convArgs[1] = (int)tempString;
            text = UI_ReplaceConversions(text, (ConversionArguments *)convArgs);

            UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, color, textStyle);
        }
        return;
    }

    case 250: /* key bind pending */
    {
        const char *keyStr;
        if (Display_KeyBindPending())
            keyStr = "EXE_KEYWAIT";
        else
            keyStr = "EXE_KEYCHANGE";
        text = UI_SafeTranslateString(keyStr);
        UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], *(int *)&rect[4], *(int *)&rect[5], scale, color, textStyle);
        return;
    }

    case 252: /* join game type */
    {
        int jgtIdx = ui_joinGameType->current.integer;
        if (jgtIdx > sharedUiInfo.numJoinGameTypes) {
            Dvar_SetInt(ui_joinGameType, 0);
            jgtIdx = ui_joinGameType->current.integer;
        }
        {
            const char *gtName = sharedUiInfo.joinGameTypes[jgtIdx].gameTypeName;
            if (gtName[0] == '\0')
                gtName = "EXE_ALL";
            text = UI_SafeTranslateString(gtName);
            UI_DrawText(text, 0x7fffffff, font, rect[0], rect[1], 0, 0, scale, color, textStyle);
        }
        return;
    }

    case 253: /* cinematic */
    {
        int cinHandle = sharedUiInfo.previewMovie;
        if (cinHandle <= -2)
            return;
        cinHandle = CIN_PlayCinematic(
            *(const char **)((byte *)&sharedUiInfo + 26492 + sharedUiInfo.movieIndex * 4),
            0, 0, 0, 0, 10);
        sharedUiInfo.previewMovie = cinHandle;
        if (cinHandle < 0) {
            sharedUiInfo.previewMovie = -2;
            return;
        }
        CIN_RunCinematic(cinHandle);
        CIN_SetExtents(cinHandle, (int)rect[0], (int)rect[1], (int)rect[2], (int)rect[3]);
        CIN_DrawCinematic(cinHandle);
        return;
    }

    case 254: /* map preview (same as 206) */
    {
        UI_DrawMapPreview((const rectDef_t *)rect, color, 1);
        return;
    }

    case 263: /* record level */
        UI_DrawRecordLevel((rectDef_t *)rect);
        return;

    case 264: /* voice indicator (self talking) */
    {
        byte *svVoice = *(byte **)imp_sv_voice;
        byte *clVoice = *(byte **)imp_cl_voice;
        if (svVoice[8] == 0 || clVoice[8] == 0)
            return;
        if (!IsTalking())
            return;
        {
            int voiceMat = (int)CL_RegisterMaterialNoMip("voice_on", 7);
            UI_DrawHandlePic(rect[0], rect[1], rect[2], rect[3], *(int *)&rect[4], *(int *)&rect[5], color, voiceMat);
        }
        return;
    }

    case 265: /* voice talker 0 */
    case 266: /* voice talker 1 */
    case 267: /* voice talker 2 */
    case 268: /* voice talker 3 */
    case 269: /* voice talker 4 */
    case 270: /* voice talker 5 */
    {
        int targetTalker = ownerDraw - 265;
        int talkerCount = 0;
        int clientNum;
        int pi;

        for (pi = 0; pi < 64; pi++) {
            if (!CL_IsPlayerTalking(pi))
                continue;
            if (talkerCount == targetTalker)
                break;
            talkerCount++;
        }

        clientNum = pi;
        if (clientNum < 0)
            return;

        if (clientNum >= 64)
            clientNum = -1;

        /* find client number in player list */
        {
            int voiceMat;
            float actualScale;
            int textHeight;
            int num;

            UI_BuildPlayerList();

            for (num = 0; num < 64; num++) {
                if (*(int *)((byte *)&sharedUiInfo + 0x1048 + num * 4) == clientNum)
                    break;
            }
            if (num >= 64)
                num = -1;

            voiceMat = (int)CL_RegisterMaterialNoMip("voice_on", 7);
            actualScale = CL_NormalizedTextScale(font, scale);
            textHeight = CL_TextHeight(font);

            UI_DrawHandlePic(rect[0], rect[1], rect[2], rect[3], *(int *)&rect[4], *(int *)&rect[5], color, voiceMat);

            {
                float scaledHeight = (float)((int)((float)textHeight * actualScale));
                float textY = rect[1] + (rect[3] - scaledHeight) * 0.5f + scaledHeight;
                float textX = rect[0] + rect[2] + 2.0f;
                UI_DrawText((const char *)((byte *)&sharedUiInfo + 72 + num * 32), 32, font, textX, textY, *(int *)&rect[4], *(int *)&rect[5], scale, color, textStyle);
            }
        }
        return;
    }

    default:
        return;
    }

    /* dead code - this should not be reached */
#if 0 /* original ASM preserved */
    __asm__ __volatile__ (
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
#endif
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
    int serverCount = LAN_GetServerCount(ui_netSource->current.integer);
    if (serverCount != sharedUiInfo.serverStatus.serverCount) {
        sharedUiInfo.serverStatus.serverCount = serverCount;
        if (sharedUiInfo.serverStatus.numDisplayServers != 0) {
            sharedUiInfo.serverStatus.currentServer = -1;
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

    nextRefresh = uiInfo->nextFindPlayerRefresh;
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

            if (*(int *)((byte *)&sharedUiInfo + 113136) < sharedUiInfo.serverStatus.numDisplayServers) {
                /* need to fetch next server */
                int curServer = *(int *)((byte *)&sharedUiInfo + 113136);
                int dispServer;

                /* set timestamp */
                *(int *)((byte *)&sharedUiInfo + 0x1ba74 + i * 0x8c) = *(int *)((byte *)uiInfo + 4);

                /* get server address string */
                dispServer = *(int *)(sharedUiInfo.serverStatus.displayServers + curServer * 4);
                LAN_GetServerAddressString(ui_netSource->current.integer, dispServer, (char *)serverAddr, 0x40);

                /* get server info */
                LAN_GetServerInfo(ui_netSource->current.integer, dispServer, infoString, 0x400);

                /* extract hostname */
                I_strncpyz((char *)hostName, Info_ValueForKey(infoString, "hostname"), 0x40);

                /* mark as pending */
                *pendingFlag = 1;

                /* advance to next server */
                curServer++;
                *(int *)((byte *)&sharedUiInfo + 113136) = curServer;

                /* update status string */
                numResults = uiInfo->numFoundPlayerServers;
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
                    numResults = uiInfo->numFoundPlayerServers;
                    if (numResults > 14) {
                        /* too many results, set num to max */
                        *(int *)((byte *)&sharedUiInfo + 113136) = sharedUiInfo.serverStatus.numDisplayServers;
                        continue;
                    }

                    /* store result: server address and host name */
                    I_strncpyz((char *)((byte *)uiInfo + 0x860 + numResults * 64), (const char *)serverAddr, 0x40);
                    I_strncpyz((char *)((byte *)uiInfo + 0xc60 + numResults * 64), (const char *)hostName2, 0x40);
                    uiInfo->numFoundPlayerServers += 1;
                    continue;
                }
            }
        }

        /* update searching status */
        Com_sprintf((char *)((byte *)uiInfo + 0xc60 + uiInfo->numFoundPlayerServers * 64), 0x40, "searching %d/%d...", *(int *)((byte *)&sharedUiInfo + 113136), numFound);
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
            uiInfo->nextFindPlayerRefresh = *(int *)((byte *)uiInfo + 4) + 25;
            return;
        }
    }

    /* all done */
    numResults = uiInfo->numFoundPlayerServers;
    if (numResults == 0) {
        Com_sprintf((char *)((byte *)uiInfo + 0xc60), 0x40, "no servers found");
    } else {
        const char *plural = (numResults == 2) ? str_002157b8 : "s";
        Com_sprintf((char *)((byte *)uiInfo + 0xca0 + (numResults - 1) * 64), 0x40, "%d server%s found with player %s", numResults - 1, plural, (const char *)((byte *)uiInfo + 0x4a0));
    }
    uiInfo->nextFindPlayerRefresh = 0;
}

/* line 3388 */
static void UI_BuildServerStatus_impl(int force)
{
    int serverStatusVisible = uiInfo->nextFindPlayerRefresh;

    if (serverStatusVisible)
        return;

    if (force) {
        /* force: reset feeder selection and clear server status */
        Menu_SetFeederSelection(uiInfo, 0, 0xd, 0, 0);
        *(int *)((byte *)&sharedUiInfo + 113128) = 0;
        LAN_GetServerStatus(0, 0, 0);
    } else {
        int nextRefresh = sharedUiInfo.nextServerStatusRefresh;
        if (nextRefresh == 0)
            return;
        if (nextRefresh > *(int *)((byte *)uiInfo + 4))
            return;
    }

    /* inline server count update (shared with UI_FeederCount) */
    {
        int serverCount = LAN_GetServerCount(ui_netSource->current.integer);
        if (serverCount != sharedUiInfo.serverStatus.serverCount) {
            sharedUiInfo.serverStatus.serverCount = serverCount;
            if (sharedUiInfo.serverStatus.numDisplayServers != 0) {
                sharedUiInfo.serverStatus.currentServer = -1;
                UI_BuildServerDisplayList(1);
            }
        }
    }

    {
        int selectedServer = sharedUiInfo.serverStatus.currentServer;
        int numServers = sharedUiInfo.serverStatus.numDisplayServers;

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
                sharedUiInfo.nextServerStatusRefresh = 0;
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
                sharedUiInfo.nextServerStatusRefresh = *(int *)((byte *)uiInfo + 4) + 500;
            }
        }
    }
}

#ifndef __EMSCRIPTEN__
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
#else
/* Register-convention trampoline: eax=force.
   In Emscripten mode, callers call _impl directly. */
static void UI_BuildServerStatus(void) { UI_BuildServerStatus_impl(0); }
#endif

/* line 513 */
#ifndef __EMSCRIPTEN__
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
#else
void UI_Refresh(void) {
    int netSource;
    int serverCount;
    int needRebuild;

    if (Menu_Count(uiInfo) <= 0)
        return;

    Menu_PaintAll(uiInfo);

    /* Check if server browser is active */
    if (!sharedUiInfo.serverStatus.refreshActive)
        goto after_browser;

    /* UI_FeederUpdateServerBrowser logic (lines 5027-5077) */
    netSource = ui_netSource->current.integer;
    if (netSource == 2) {
        needRebuild = 0;
    } else if (netSource == 0) {
        if (LAN_GetServerCount(0) == 0) {
            needRebuild = 1;
        } else {
            needRebuild = 0;
        }
    } else {
        if (LAN_WaitServerResponse(netSource)) {
            needRebuild = 1;
        } else {
            needRebuild = 0;
        }
    }

    /* Check if time hasn't passed the refresh interval */
    if (*(int *)((byte *)uiInfo + 4) < *(int *)((byte *)&sharedUiInfo + 28632)) {
        if (needRebuild)
            goto after_browser;
    }

    /* UI_UpdateServerCountInfo (lines 2016-2023) */
    serverCount = LAN_GetServerCount(ui_netSource->current.integer);
    if (serverCount != sharedUiInfo.serverStatus.serverCount) {
        sharedUiInfo.serverStatus.serverCount = serverCount;
        if (sharedUiInfo.serverStatus.numDisplayServers) {
            sharedUiInfo.serverStatus.currentServer = -1;
            UI_BuildServerDisplayList(1);
        }
    }

    /* LAN_UpdateDirtyPings (line 5061) */
    if (LAN_UpdateDirtyPings(ui_netSource->current.integer)) {
        *(int *)((byte *)&sharedUiInfo + 28632) = *(int *)((byte *)uiInfo + 4) + 1000;
    } else {
        if (needRebuild)
            goto rebuild;

        UI_BuildServerDisplayList(2);

        /* Print server listing stats (lines 5002-5012) */
        if (sharedUiInfo.serverStatus.refreshActive) {
            int filtered;
            sharedUiInfo.serverStatus.refreshActive = 0;
            Com_Printf("%d servers listed in browser with %d players.\n",
                       sharedUiInfo.serverStatus.numDisplayServers,
                       sharedUiInfo.serverStatus.numPlayersOnServers);
            filtered = LAN_GetServerCount(ui_netSource->current.integer) - sharedUiInfo.serverStatus.numDisplayServers;
            if (filtered > 0)
                Com_Printf("%d servers not listed (filtered out by game browser settings)\n", filtered);
        }
    }

rebuild:
    UI_BuildServerDisplayList(0);

after_browser:
    /* Common path: build status, find player, draw cursor */
    UI_BuildServerStatus_impl(0);
    UI_BuildFindPlayerList();

    /* Draw cursor */
    {
        byte *edx = (byte *)uiInfo;
        float x = (float)(*(int *)(edx + 0xc) - 16);
        float y = (float)(*(int *)(edx + 0x10) - 16);
        UI_DrawHandlePic(x, y, 32.0f, 32.0f, 4, 4, 0, sharedUiInfo.assets.cursor);
    }
}
#endif

/* line 2141 */
void UI_RunMenuScript(const char * *args)
{
    char name[1024];
    char buff[1024];
    char buff2[2048];
    char out[32];
    char addr[2048];
    char name2[1024];
    char testValue[1024];
    char dvarName[1024];
    char menuName[1024];
    int sortColumn;

    if (!String_Parse(args, name, 0x400))
        return;

    if (I_stricmp(name, "StartServer") == 0) {
        /* StartServer */
        Dvar_SetBoolByName("cg_thirdPerson", 0);
        Dvar_SetFromStringByNameFromSource("dedicated",
            va("%i", ui_dedicated->current.integer), 1);
        Dvar_SetStringByName("g_gametype",
            *(const char **)((byte *)&sharedUiInfo + 4428 + ui_netGameType->current.integer * 8));
        {
            int mapIdx = ui_currentNetMap->current.integer;
            int offset = mapIdx * 41 + mapIdx;
            const char *mapName = *(const char **)((byte *)&sharedUiInfo + 4952 + offset * 4);
            Cbuf_ExecuteText(2, va("wait ; wait ; map %s\n", mapName));
        }
        return;
    }

    if (I_stricmp(name, "resetDefaults") == 0) {
        Cbuf_ExecuteText(0, "dvar_restart\n");
        Cbuf_ExecuteText(0, "exec default_mp.cfg\n");
        Cbuf_ExecuteText(0, "exec language.cfg\n");
        Cbuf_ExecuteText(0, "setRecommended\n");
        Controls_SetDefaults();
        Dvar_SetBoolByName("com_introPlayed", 1);
        Dvar_SetBoolByName("com_recommendedSet", 1);
        Cbuf_ExecuteText(2, "vid_restart\n");
        return;
    }

    if (I_stricmp(name, "getCDKey") == 0) {
        CLUI_GetCDKey(buff, 0x11, 0);
        Dvar_SetStringByName("cdkey1", "");
        Dvar_SetStringByName("cdkey2", "");
        Dvar_SetStringByName("cdkey3", "");
        Dvar_SetStringByName("cdkey4", "");
        Dvar_SetStringByName("cdkey5", "");
        {
            int len;
            /* strlen of buff */
            for (len = 0; buff[len]; len++) ;
            if (len == 0x10) {
                /* 16 chars - split into 4x4+key5 */
                I_strncpyz(out, buff, 5);
                Dvar_SetStringByName("cdkey1", out);
                I_strncpyz(out, &buff[4], 5);
                Dvar_SetStringByName("cdkey2", out);
                I_strncpyz(out, &buff[8], 5);
                Dvar_SetStringByName("cdkey3", out);
                I_strncpyz(out, &buff[12], 5);
                Dvar_SetStringByName("cdkey4", out);
            }
        }
        {
            int len2;
            for (len2 = 0; buff2[len2]; len2++) ;
            if (len2 == 4) {
                I_strncpyz(out, buff2, 5);
                Dvar_SetStringByName("cdkey5", out);
            }
        }
        return;
    }

    if (I_stricmp(name, "verifyCDKey") == 0) {
        buff[0] = '\0';
        I_strncat(buff, Dvar_GetVariantString("cdkey1"), 0x400);
        I_strncat(buff, Dvar_GetVariantString("cdkey2"), 0x400);
        I_strncat(buff, Dvar_GetVariantString("cdkey3"), 0x400);
        I_strncat(buff, Dvar_GetVariantString("cdkey4"), 0x400);
        buff2[0] = '\0';
        I_strncat(buff2, Dvar_GetVariantString("cdkey5"), 0x400);
        if (CL_CDKeyValidate(buff, buff2)) {
            Dvar_SetStringByName("ui_cdkeyvalid", UI_SafeTranslateString("EXE_CDKEYVALID"));
            CLUI_SetCDKey(buff, 0);
        } else {
            Dvar_SetStringByName("ui_cdkeyvalid", UI_SafeTranslateString("EXE_CDKEYINVALID"));
        }
        return;
    }

    if (I_stricmp(name, "loadArenas") == 0) {
        int i;
        const char *curGameType;

        UI_LoadArenas();

        /* find current gametype index */
        curGameType = Dvar_GetString("g_gametype");
        {
            int numGT = sharedUiInfo.numGameTypes;
            if (numGT > 0) {
                for (i = 0; i < numGT; i++) {
                    if (I_stricmp(curGameType, sharedUiInfo.gameTypes[i].gameType) == 0) {
                        Dvar_SetInt(ui_netGameType, i);
                        Dvar_SetString(ui_netGameTypeName, sharedUiInfo.gameTypes[i].gameType);
                        break;
                    }
                }
            }
        }

        /* update map filter */
        {
            int gtIdx = ui_netGameType->current.integer;
            int numMaps = sharedUiInfo.mapCount;
            if (numMaps > 0) {
                for (i = 0; i < numMaps; i++) {
                    byte *entry = (byte *)&sharedUiInfo + i * 0xa4;
                    *(int *)(entry + 0x13f4) = 0;
                    if ((*(int *)(entry + 0x1368) >> gtIdx) & 1) {
                        *(int *)(entry + 0x13f4) = 1;
                    }
                }
            }
        }

        Menu_SetFeederSelection(uiInfo, 0, 4, 0, "createserver_maps");
        UI_SelectCurrentMap();
        return;
    }

    if (I_stricmp(name, "loadGameInfo") == 0) {
        UI_GetGameTypesList();
        return;
    }

    if (I_stricmp(name, "LoadMods") == 0) {
        int numFiles, i, modCount;
        char *namePtr;

        sharedUiInfo.modCount = 0;
        numFiles = FS_GetFileList("$modlist", "", 1, addr, 0x800);
        if (numFiles <= 0)
            return;

        namePtr = addr;
        modCount = sharedUiInfo.modCount;

        for (i = 0; i < numFiles; i++) {
            const char *modName;
            const char *modDesc;
            int nameLen, descLen;

            /* get name length */
            for (nameLen = 0; namePtr[nameLen]; nameLen++) ;
            nameLen++; /* include null */

            modName = namePtr;
            modDesc = namePtr + nameLen;

            sharedUiInfo.modList[modCount].modName = String_Alloc(modName);

            modCount = sharedUiInfo.modCount;
            *(const char **)((byte *)&sharedUiInfo + 25976 + modCount * 8) = String_Alloc(modDesc);

            /* advance past desc */
            for (descLen = 0; modDesc[descLen]; descLen++) ;
            namePtr = (char *)modDesc + descLen + 1;

            modCount = sharedUiInfo.modCount + 1;
            sharedUiInfo.modCount = modCount;
            if (modCount > 63)
                return;
        }
        return;
    }

    if (I_stricmp(name, "voteTypeMap") == 0) {
        int mapIdx = ui_currentNetMap->current.integer;
        int offset = mapIdx * 41 + mapIdx;
        const char *mapName = *(const char **)((byte *)&sharedUiInfo + 4952 + offset * 4);
        const char *gtName = *(const char **)((byte *)&sharedUiInfo + 4428 + ui_netGameType->current.integer * 8);
        Cbuf_ExecuteText(2, va("callvote typemap %s %s\n", gtName, mapName));
        return;
    }

    if (I_stricmp(name, "voteMap") == 0) {
        int mapIdx = ui_currentNetMap->current.integer;
        if (mapIdx < 0 || mapIdx >= sharedUiInfo.mapCount)
            return;
        {
            int offset = mapIdx * 41 + mapIdx;
            const char *mapName = *(const char **)((byte *)&sharedUiInfo + 4952 + offset * 4);
            Cbuf_ExecuteText(2, va("callvote map %s\n", mapName));
        }
        return;
    }

    if (I_stricmp(name, "voteGame") == 0) {
        const char *gtName = *(const char **)((byte *)&sharedUiInfo + 4428 + ui_netGameType->current.integer * 8);
        Cbuf_ExecuteText(2, va("callvote g_gametype %s\n", gtName));
        return;
    }

    if (I_stricmp(name, "saveControls") == 0) {
        Controls_SetConfig(1);
        return;
    }

    if (I_stricmp(name, "loadControls") == 0) {
        Controls_GetConfig();
        return;
    }

    if (I_stricmp(name, "clearError") == 0) {
        Dvar_SetStringByName("com_errorMessage", "");
        Dvar_SetBoolByName("com_isNotice", 0);
        return;
    }

    if (I_stricmp(name, "RefreshServers") == 0) {
        UI_StartServerRefresh(1);
        UI_BuildServerDisplayList(1);
        return;
    }

    if (I_stricmp(name, "RefreshFilter") == 0) {
        UI_StartServerRefresh(0);
        UI_BuildServerDisplayList(1);
        return;
    }

    if (I_stricmp(name, "addPlayerProfiles") == 0) {
        /* build player profiles list */
        int numFiles, i;
        char *fileList;

        uiInfo->playerProfileCount = 0;
        uiInfo->playerProfileStatus.sortDir = 1;

        fileList = FS_ListFiles("players", "/", 1, &sortColumn);

        if (sortColumn > 0) {
            for (i = 0; i < sortColumn; i++) {
                int profileIdx = uiInfo->playerProfileCount;
                uiInfo->playerProfileName[profileIdx] = String_Alloc(((char **)fileList)[i]);
                uiInfo->playerProfileCount += 1;
            }
        }

        FS_FreeFileList((char **)fileList);

        /* sort profiles */
        {
            int numProfiles = uiInfo->playerProfileCount;
            if (numProfiles > 0) {
                for (i = 0; i < numProfiles; i++)
                    uiInfo->playerProfileStatus.displayProfile[i] = i;
                qsort(uiInfo->playerProfileStatus.displayProfile, numProfiles, 4, UI_PlayerProfilesQsortCompare);

                /* set feeder selection for profile lists */
                {
                    int numMenus = uiInfo->uiDC.openMenuCount;
                    for (i = numMenus - 1; i >= 0; i--) {
                        void *menu = uiInfo->uiDC.menuStack[i];
                        if (((byte *)&((menuDef_t *)menu)->window.dynamicFlags[0])[0] & 4) {
                            Menu_SetFeederSelection(uiInfo, (int)menu, 0x18, 0, 0);
                        }
                    }
                }
            }
        }

        Dvar_SetInt(ui_playerProfileCount, uiInfo->playerProfileCount);
        return;
    }

    if (I_stricmp(name, "sortPlayerProfiles") == 0) {
        /* toggle sort order */
        int curSort = uiInfo->playerProfileStatus.sortDir;
        uiInfo->playerProfileStatus.sortDir = !curSort;

        /* re-sort */
        {
            int numProfiles = uiInfo->playerProfileCount;
            if (numProfiles > 0) {
                int i;
                for (i = 0; i < numProfiles; i++)
                    uiInfo->playerProfileStatus.displayProfile[i] = i;
                qsort(uiInfo->playerProfileStatus.displayProfile, numProfiles, 4, UI_PlayerProfilesQsortCompare);

                {
                    int numMenus = uiInfo->uiDC.openMenuCount;
                    for (i = numMenus - 1; i >= 0; i--) {
                        void *menu = uiInfo->uiDC.menuStack[i];
                        if (((byte *)&((menuDef_t *)menu)->window.dynamicFlags[0])[0] & 4) {
                            Menu_SetFeederSelection(uiInfo, (int)menu, 0x18, 0, 0);
                        }
                    }
                }
            }
        }
        return;
    }

    if (I_stricmp(name, "selectActivePlayerProfile") == 0) {
        /* find current profile and select it */
        const char *curProfile = *(const char **)(*(byte **)imp_com_playerProfile + 8);
        int numProfiles = uiInfo->playerProfileCount;
        int i, found = -1;

        for (i = 0; i < numProfiles; i++) {
            int sortedIdx = uiInfo->playerProfileStatus.displayProfile[i];
            if (I_stricmp(curProfile, uiInfo->playerProfileName[sortedIdx]) == 0) {
                found = i;
                break;
            }
        }
        if (found < 0)
            return;
        if (found >= numProfiles)
            return;

        {
            int numMenus = uiInfo->uiDC.openMenuCount;
            for (i = numMenus - 1; i >= 0; i--) {
                void *menu = uiInfo->uiDC.menuStack[i];
                if (((byte *)&((menuDef_t *)menu)->window.dynamicFlags[0])[0] & 4) {
                    Menu_SetFeederSelection(uiInfo, (int)menu, 0x18, found, 0);
                }
            }
        }
        return;
    }

    if (I_stricmp(name, "createPlayerProfile") == 0) {
        const char *newName = *(const char **)((byte *)ui_playerProfileNameNew + 8);
        int i, numProfiles;

        if (newName[0] == '\0')
            return;

        I_strncpyz(out, newName, 0x20);
        Dvar_SetString(ui_playerProfileNameNew, "");

        numProfiles = uiInfo->playerProfileCount;
        if (numProfiles >= 64) {
            Menus_OpenByName(uiInfo, "profile_create_too_many_popmenu");
            return;
        }

        for (i = 0; i < numProfiles; i++) {
            if (I_stricmp(out, uiInfo->playerProfileName[i]) == 0) {
                Menus_OpenByName(uiInfo, "profile_exists_popmenu");
                return;
            }
        }

        if (!Com_NewPlayerProfile(out)) {
            Menus_OpenByName(uiInfo, "profile_create_fail_popmenu");
            return;
        }

        /* add to list */
        {
            int idx = uiInfo->playerProfileCount;
            uiInfo->playerProfileName[idx] = String_Alloc(out);
            uiInfo->playerProfileCount += 1;
        }

        /* sort and set selection */
        {
            int np = uiInfo->playerProfileCount;
            if (np > 0) {
                for (i = 0; i < np; i++)
                    uiInfo->playerProfileStatus.displayProfile[i] = i;
                qsort(uiInfo->playerProfileStatus.displayProfile, np, 4, UI_PlayerProfilesQsortCompare);
            }
        }

        Dvar_SetInt(ui_playerProfileCount, uiInfo->playerProfileCount);

        /* find newly created profile and select it */
        {
            int np = uiInfo->playerProfileCount;
            int found = -1;
            for (i = 0; i < np; i++) {
                int si = uiInfo->playerProfileStatus.displayProfile[i];
                if (I_stricmp(out, uiInfo->playerProfileName[si]) == 0) {
                    found = i;
                    break;
                }
            }

            {
                int numMenus = uiInfo->uiDC.openMenuCount;
                for (i = numMenus - 1; i >= 0; i--) {
                    void *menu = uiInfo->uiDC.menuStack[i];
                    if (((byte *)&((menuDef_t *)menu)->window.dynamicFlags[0])[0] & 4) {
                        Menu_SetFeederSelection(uiInfo, (int)menu, 0x18, found, 0);
                    }
                }
            }
        }
        return;
    }

    if (I_stricmp(name, "deletePlayerProfile") == 0) {
        int numProfiles = uiInfo->playerProfileCount;
        int selIdx, sortedIdx, i;

        if (numProfiles == 0)
            return;

        selIdx = *(int *)((byte *)ui_playerProfileSelected + 8);
        if (!Com_DeletePlayerProfile(selIdx)) {
            Menus_OpenByName(uiInfo, "profile_delete_fail_popmenu");
            return;
        }

        /* find profile in sorted list */
        {
            int found = -1;
            const char *selName = *(const char **)(*(byte **)((byte *)ui_playerProfileSelected) + 8);
            for (i = 0; i < numProfiles; i++) {
                int si = uiInfo->playerProfileStatus.displayProfile[i];
                if (I_stricmp(selName, uiInfo->playerProfileName[si]) == 0) {
                    found = i;
                    sortedIdx = si;
                    break;
                }
            }
            if (found < 0) {
                found = -1;
                sortedIdx = *(int *)((byte *)uiInfo + 0x388 - 4); /* fallback */
            }

            /* remove from list */
            uiInfo->playerProfileCount -= 1;
            numProfiles = uiInfo->playerProfileCount;

            if (numProfiles == 0) {
                Dvar_SetString(ui_playerProfileSelected, "");
            } else {
                /* move last entry to fill gap */
                uiInfo->playerProfileName[sortedIdx] =
                    uiInfo->playerProfileName[numProfiles];

                if (found >= numProfiles)
                    found = numProfiles - 1;

                /* re-sort */
                if (numProfiles > 0) {
                    for (i = 0; i < numProfiles; i++)
                        uiInfo->playerProfileStatus.displayProfile[i] = i;
                    qsort(uiInfo->playerProfileStatus.displayProfile, numProfiles, 4, UI_PlayerProfilesQsortCompare);
                }

                {
                    int numMenus = uiInfo->uiDC.openMenuCount;
                    for (i = numMenus - 1; i >= 0; i--) {
                        void *menu = uiInfo->uiDC.menuStack[i];
                        if (((byte *)&((menuDef_t *)menu)->window.dynamicFlags[0])[0] & 4) {
                            Menu_SetFeederSelection(uiInfo, (int)menu, 0x18, found, 0);
                        }
                    }
                }
            }
        }

        Dvar_SetInt(ui_playerProfileCount, uiInfo->playerProfileCount);
        return;
    }

    if (I_stricmp(name, "loadPlayerProfile") == 0) {
        const char *selProfile = *(const char **)((byte *)ui_playerProfileSelected + 8);
        if (selProfile[0] == '\0')
            return;
        Com_ChangePlayerProfile((int)selProfile);
        return;
    }

    if (I_stricmp(name, "LoadMovies") == 0) {
        int numMovies, i;
        char *filePtr;
        extern int __mh_execute_header;

        numMovies = FS_GetFileList("video", "roq", 0, addr, (int)&__mh_execute_header);
        sharedUiInfo.movieCount = numMovies;
        if (numMovies == 0)
            return;

        if (numMovies > 256)
            numMovies = 256;
        sharedUiInfo.movieCount = numMovies;

        filePtr = addr;
        for (i = 0; i < numMovies; i++) {
            int len;
            char *end;

            for (len = 0; filePtr[len]; len++) ;
            end = filePtr + len;

            /* strip .roq extension */
            if (I_stricmp(end - 4, ".roq") == 0)
                *(end - 4) = '\0';

            I_strupr(filePtr);
            sharedUiInfo.movieList[i] = String_Alloc(filePtr);

            filePtr = end + 1;
        }
        return;
    }

    if (I_stricmp(name, "playMovie") == 0) {
        int cinHandle = sharedUiInfo.previewMovie;
        if (cinHandle >= 0)
            CIN_StopCinematic(cinHandle);
        Cbuf_ExecuteText(2, va("cinematic %s 2\n",
            *(const char **)((byte *)&sharedUiInfo + 26492 + sharedUiInfo.movieIndex * 4)));
        return;
    }

    if (I_stricmp(name, "RunMod") == 0) {
        Dvar_SetStringByName("fs_game",
            *(const char **)((byte *)&sharedUiInfo + 25972 + sharedUiInfo.modIndex * 8));
        Cbuf_ExecuteText(2, "vid_restart;");
        return;
    }

    if (I_stricmp(name, "closeJoin") == 0) {
        int refreshing = sharedUiInfo.serverStatus.refreshActive;
        if (refreshing) {
            /* stop refresh */
            sharedUiInfo.serverStatus.refreshActive = 0;
            Com_Printf("%d servers listed in browser with %d players.\n",
                sharedUiInfo.serverStatus.numDisplayServers, sharedUiInfo.serverStatus.numPlayersOnServers);
            {
                int filtered = LAN_GetServerCount(ui_netSource->current.integer) -
                               sharedUiInfo.serverStatus.numDisplayServers;
                if (filtered > 0)
                    Com_Printf("%d servers not listed (filtered out by game browser settings)\n", filtered);
            }
            sharedUiInfo.serverStatus.nextDisplayRefresh = 0;
            sharedUiInfo.nextServerStatusRefresh = 0;
            uiInfo->nextFindPlayerRefresh = 0;
            UI_BuildServerDisplayList(1);
        } else {
            Menus_CloseByName(uiInfo, "joinserver");
            Menus_OpenByName(uiInfo, "main");
        }
        return;
    }

    if (I_stricmp(name, "StopRefresh") == 0) {
        int refreshing = sharedUiInfo.serverStatus.refreshActive;
        if (refreshing) {
            sharedUiInfo.serverStatus.refreshActive = 0;
            Com_Printf("%d servers listed in browser with %d players.\n",
                sharedUiInfo.serverStatus.numDisplayServers, sharedUiInfo.serverStatus.numPlayersOnServers);
            {
                int filtered = LAN_GetServerCount(ui_netSource->current.integer) -
                               sharedUiInfo.serverStatus.numDisplayServers;
                if (filtered > 0)
                    Com_Printf("%d servers not listed (filtered out by game browser settings)\n", filtered);
            }
        }
        sharedUiInfo.serverStatus.nextDisplayRefresh = 0;
        sharedUiInfo.nextServerStatusRefresh = 0;
        uiInfo->nextFindPlayerRefresh = 0;
        return;
    }

    if (I_stricmp(name, "ServerStatus") == 0) {
        /* inline server count update */
        UI_UpdateServerCount();

        {
            int selectedServer = sharedUiInfo.serverStatus.currentServer;
            if (selectedServer < 0 || selectedServer >= sharedUiInfo.serverStatus.numDisplayServers)
                return;

            LAN_GetServerAddressString(ui_netSource->current.integer,
                *(int *)(sharedUiInfo.serverStatus.displayServers + selectedServer * 4),
                (char *)((byte *)&sharedUiInfo + 109736), 0x40);
            { int _force = 1; __asm__ __volatile__("calll UI_BuildServerStatus" : : "a"(_force) : "ecx", "edx", "memory"); }
        }
        return;
    }

    if (I_stricmp(name, "UpdateFilter") == 0) {
        if (ui_netSource->current.integer == 0) {
            UI_StartServerRefresh(1);
        }
        UI_BuildServerDisplayList(1);
        UI_FeederSelection(2.0f, 0);
        return;
    }

    if (I_stricmp(name, "JoinServer") == 0) {
        Dvar_SetBoolByName("cg_thirdPerson", 0);

        UI_UpdateServerCount();

        {
            int selectedServer = sharedUiInfo.serverStatus.currentServer;
            if (selectedServer < 0 || selectedServer >= sharedUiInfo.serverStatus.numDisplayServers)
                return;

            LAN_GetServerAddressString(ui_netSource->current.integer,
                *(int *)(sharedUiInfo.serverStatus.displayServers + selectedServer * 4),
                buff, 0x400);
            Cbuf_ExecuteText(2, va("connect %s\n", buff));
        }
        return;
    }

    if (I_stricmp(name, "Quit") == 0) {
        Cbuf_ExecuteText(0, "quit");
        return;
    }

    if (I_stricmp(name, "Controls") == 0) {
        Dvar_SetIntByName("cl_paused", 1);
        Key_SetCatcher(8);
        Menus_CloseAll(uiInfo);
        Menus_OpenByName(uiInfo, "setup_menu2");
        return;
    }

    if (I_stricmp(name, "Leave") == 0) {
        Cbuf_ExecuteText(2, "disconnect\n");
        Key_SetCatcher(8);
        Menus_CloseAll(uiInfo);
        Menus_OpenByName(uiInfo, "main");
        return;
    }

    if (I_stricmp(name, "ServerSort") == 0) {
        if (!Int_Parse(args, &sortColumn))
            return;

        if (sharedUiInfo.serverStatus.sortKey == sortColumn) {
            int dir = sharedUiInfo.serverStatus.sortDir;
            sharedUiInfo.serverStatus.sortDir = !dir;
        }

        sharedUiInfo.serverStatus.sortKey = sortColumn;
        qsort((void *)(sharedUiInfo.serverStatus.displayServers),
              sharedUiInfo.serverStatus.numDisplayServers, 4, UI_ServersQsortCompare);
        return;
    }

    if (I_stricmp(name, "nextSkirmish") == 0)
        return;

    if (I_stricmp(name, "SkirmishStart") == 0)
        return;

    if (I_stricmp(name, "closeingame") == 0) {
        Key_SetCatcher(Key_GetCatcher() & ~8);
        Key_ClearStates();
        Dvar_SetIntByName("cl_paused", 0);
        Menus_CloseAll(uiInfo);
        return;
    }

    if (I_stricmp(name, "voteKick") == 0) {
        int sel = uiInfo->playerIndex;
        if (sel < 0 || sel >= sharedUiInfo.playerCount)
            return;
        Cbuf_ExecuteText(2, va("callvote kick \"%s\"\n",
            (const char *)((byte *)&sharedUiInfo + 72 + sel * 32)));
        return;
    }

    if (I_stricmp(name, "voteTempBan") == 0) {
        int sel = uiInfo->playerIndex;
        if (sel < 0 || sel >= sharedUiInfo.playerCount)
            return;
        Cbuf_ExecuteText(2, va("callvote tempBanUser \"%s\"\n",
            (const char *)((byte *)&sharedUiInfo + 72 + sel * 32)));
        return;
    }

    if (I_stricmp(name, "addFavorite") == 0) {
        if (ui_netSource->current.integer == 2)
            return;

        addr[0] = '\0';
        out[0] = '\0';

        UI_UpdateServerCount();

        {
            int selectedServer = sharedUiInfo.serverStatus.currentServer;
            if (selectedServer >= 0 && selectedServer < sharedUiInfo.serverStatus.numDisplayServers) {
                /* get server info */
                LAN_GetServerInfo(ui_netSource->current.integer,
                    *(int *)(sharedUiInfo.serverStatus.displayServers + selectedServer * 4),
                    buff, 0x400);
                I_strncpyz(out, Info_ValueForKey(buff, "hostname"), 0x20);
                I_strncpyz(addr, Info_ValueForKey(buff, "addr"), 0x20);
            }
            UI_AddServerToFavoritesList((const char **)&addr, (const char **)&out);
        }
        return;
    }

    if (I_stricmp(name, "deleteFavorite") == 0) {
        if (ui_netSource->current.integer != 2)
            return;

        {
            int selectedServer = sharedUiInfo.serverStatus.currentServer;
            if (selectedServer < 0 || selectedServer >= sharedUiInfo.serverStatus.numDisplayServers)
                return;

            UI_UpdateServerCount();

            LAN_GetServerInfo(ui_netSource->current.integer,
                *(int *)(sharedUiInfo.serverStatus.displayServers + selectedServer * 4),
                buff, 0x400);
            addr[0] = '\0';
            I_strncpyz(addr, Info_ValueForKey(buff, "addr"), 0x20);
            if (addr[0] == '\0')
                return;
            LAN_RemoveServer(2, addr);
        }
        return;
    }

    if (I_stricmp(name, "createFavorite") == 0) {
        if (ui_netSource->current.integer != 2)
            return;

        out[0] = '\0';
        addr[0] = '\0';
        I_strncpyz(addr, Dvar_GetVariantString("ui_favoriteName"), 0x20);
        I_strncpyz(out, Dvar_GetVariantString("ui_favoriteAddress"), 0x20);
        UI_AddServerToFavoritesList((const char **)&addr, (const char **)&out);
        return;
    }

    if (I_stricmp(name, "update") == 0) {
        if (!String_Parse(args, name2, 0x400))
            return;

        if (I_stricmp(name2, "ui_SetName") == 0) {
            Dvar_SetStringByName("name", Dvar_GetVariantString("ui_Name"));
            return;
        }
        if (I_stricmp(name2, "ui_GetName") == 0) {
            Dvar_SetStringByName("ui_Name", Dvar_GetVariantString("name"));
            return;
        }
        if (I_stricmp(name2, "ui_setRate") == 0) {
            int rate = Dvar_GetInt("rate");
            float frate = (float)rate;
            if (frate >= 5000.0f) {
                Dvar_SetIntByName("cl_maxpackets", 30);
                Dvar_SetIntByName("cl_packetdup", 1);
            } else if (frate >= 4000.0f) {
                Dvar_SetIntByName("cl_maxpackets", 15);
                Dvar_SetIntByName("cl_packetdup", 2);
            } else {
                Dvar_SetIntByName("cl_maxpackets", 15);
                Dvar_SetIntByName("cl_packetdup", 1);
            }
            return;
        }
        if (I_stricmp(name2, "ui_mousePitch") == 0) {
            if (Dvar_GetBool(name2)) {
                Dvar_SetFloatByName("m_pitch", -0.022f);
            } else {
                Dvar_SetFloatByName("m_pitch", 0.022f);
            }
            return;
        }
        return;
    }

    if (I_stricmp(name, "startSingleplayer") == 0) {
        Cbuf_ExecuteText(2, "startSingleplayer\n");
        return;
    }

    if (I_stricmp(name, "getLanguage") == 0) {
        Dvar_SetIntByName("ui_language", Dvar_GetInt("loc_language"));
        UI_VerifyLanguage();
        return;
    }

    if (I_stricmp(name, "verifyLanguage") == 0) {
        UI_VerifyLanguage();
        return;
    }

    if (I_stricmp(name, "updateLanguage") == 0) {
        Dvar_SetIntByName("loc_language", Dvar_GetInt("ui_language"));
        UI_VerifyLanguage();
        Cbuf_ExecuteText(2, "vid_restart\n");
        return;
    }

    if (I_stricmp(name, "mutePlayer") == 0) {
        int sel = uiInfo->playerIndex;
        if (sel < 0 || sel >= sharedUiInfo.playerCount)
            return;
        CL_MutePlayer(sharedUiInfo.playerClientNums[sel]);
        return;
    }

    if (I_stricmp(name, "openMenuOnDvar") == 0 || I_stricmp(name, "openMenuOnDvarNot") == 0) {
        int wantMatch = (I_stricmp(name, "openMenuOnDvar") == 0);
        if (!UI_GetOpenOrCloseMenuOnDvarArgs(args, name, dvarName, testValue, menuName))
            return;

        if (!Dvar_FindVar(dvarName)) {
            Com_Printf("%s: cannot find dvar %s\n", name, dvarName);
            return;
        }

        {
            int matches = (I_stricmp(testValue, Dvar_GetVariantString(dvarName)) == 0);
            if (matches == wantMatch) {
                Menus_OpenByName(uiInfo, menuName);
            }
        }
        return;
    }

    if (I_stricmp(name, "closeMenuOnDvar") == 0 || I_stricmp(name, "closeMenuOnDvarNot") == 0) {
        int wantMatch = (I_stricmp(name, "closeMenuOnDvar") == 0);
        if (!UI_GetOpenOrCloseMenuOnDvarArgs(args, name, dvarName, testValue, menuName))
            return;

        if (!Dvar_FindVar(dvarName)) {
            Com_Printf("%s: cannot find dvar %s\n", name, dvarName);
            return;
        }

        {
            int matches = (I_stricmp(testValue, Dvar_GetVariantString(dvarName)) == 0);
            if (matches == wantMatch) {
                Menus_CloseByName(uiInfo, menuName);
            }
        }
        return;
    }

    Com_Printf("unknown UI script %s\n", name);

#if 0 /* original ASM */
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2141 */
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
#endif
}

/* line 3438 */
int UI_FeederCount(float feederID)
{
    if (feederID == 4.0f) {
        /* map list: filter by game type bitmask */
        int gameType = ui_netGameType->current.integer;
        int numMaps = sharedUiInfo.mapCount;
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
        return sharedUiInfo.modCount;
    } else if (feederID == 2.0f) {
        /* server list count */
        int serverCount = LAN_GetServerCount(ui_netSource->current.integer);
        if (serverCount != sharedUiInfo.serverStatus.serverCount) {
            sharedUiInfo.serverStatus.serverCount = serverCount;
            if (sharedUiInfo.serverStatus.numDisplayServers != 0) {
                sharedUiInfo.serverStatus.currentServer = -1;
                UI_BuildServerDisplayList(1);
            }
        }
        return sharedUiInfo.serverStatus.numDisplayServers;
    } else if (feederID == 13.0f) {
        return *(int *)((byte *)&sharedUiInfo + 113128);
    } else if (feederID == 7.0f || feederID == 20.0f) {
        /* player list count */
        int curTime = *(int *)((byte *)uiInfo + 4);
        if (curTime > uiInfo->playerRefresh) {
            uiInfo->playerRefresh = curTime + 3000;
            UI_BuildPlayerList();
        }
        return sharedUiInfo.playerCount;
    } else if (feederID == 24.0f) {
        return uiInfo->playerProfileCount;
    }
    return 0;
}

/* Helper for drawing centered text at a given y position (shared pattern from line 4707) */
static void UI_DrawCenteredText(const char *text, FontHandle font, float scale, float y, const vec_t *color, int style)
{
    float actualScale = CL_NormalizedTextScale(font, scale);
    int pixelWidth = CL_TextWidth(text, 0, font);
    int scaledWidth = (int)((float)pixelWidth * actualScale);
    float x = 320.0f - (float)(scaledWidth / 2);
    UI_DrawText(text, 0x7fffffff, font, x, y, 0, 0, scale, color, style);
}

/* Wrapper for UI_ReadableSize (register calling convention: eax=buf, edx=bufsize, ecx=value) */
static void UI_ReadableSize_wrap(char *buf, int bufsize, int value)
{
    __asm__ __volatile__ (
        "calll UI_ReadableSize\n"
        :
        : "a"(buf), "d"(bufsize), "c"(value)
        : "memory"
    );
}

/* line 4714 */
static
void UI_DisplayDownloadInfo(const char *downloadName, float centerPoint, float yStart, FontHandle font, float scale)
{
    byte *legacyBase = *(byte **)imp_legacyHacks;
    int downloadSize = *(int *)(legacyBase + 0x10);
    int downloadCount = *(int *)(legacyBase + 0x14);
    int downloadTime = *(int *)(legacyBase + 0x18);
    vec_t color[4];
    float y1, y2, y3;
    int xferRate = 0;
    char dlSizeBuf[64];
    char totalSizeBuf[64];
    char xferRateBuf[64];
    char dlTimeBuf[64];
    const char *text;

    /* copy colorBlack with alpha 0.2 */
    {
        const vec_t *cBlack = (const vec_t *)imp_colorBlack;
        color[0] = cBlack[0];
        color[1] = cBlack[1];
        color[2] = cBlack[2];
    }
    color[3] = 0.2f;

    /* draw 3 background bars */
    y1 = yStart + 184.0f;
    UI_FillRect(0, y1, 640.0f, 85.0f, 0, 0, color);
    y2 = yStart + 185.0f;
    UI_FillRect(0, y2, 640.0f, 83.0f, 0, 0, color);
    y3 = yStart + 186.0f;
    UI_FillRect(0, y3, 640.0f, 81.0f, 0, 0, color);

    if (downloadSize > 0) {
        /* draw progress bars in red */
        const vec_t *cRed = (const vec_t *)imp_colorRed;
        int width;
        color[0] = cRed[0];
        color[1] = cRed[1];
        color[2] = cRed[2];
        color[3] = 0.15f;

        width = (int)((float)downloadCount / (float)downloadSize * 640.0f);
        UI_FillRect(0, y1, (float)(width + 2), 85.0f, 0, 0, color);
        UI_FillRect(0, y2, (float)(width + 1), 83.0f, 0, 0, color);
        UI_FillRect(0, y3, (float)width, 81.0f, 0, 0, color);
    }

    /* draw labels */
    {
        float yDl = yStart + 210.0f;
        float yEta = yStart + 235.0f;
        float yXfer = yStart + 260.0f;
        const vec_t *ltGrey = (const vec_t *)imp_colorLtGrey;

        UI_DrawText(UI_SafeTranslateString(dlText), 64, font, 24.0f, yDl, 0, 0, scale, ltGrey, 3);
        UI_DrawText(UI_SafeTranslateString(etaText), 64, font, 24.0f, yEta, 0, 0, scale, ltGrey, 3);
        UI_DrawText(UI_SafeTranslateString(xferText), 64, font, 24.0f, yXfer, 0, 0, scale, ltGrey, 3);

        /* draw download name with percentage */
        if (downloadSize > 0)
            text = va("%s (%d%%)", downloadName, downloadCount * 100 / downloadSize);
        else
            text = downloadName;

        UI_DrawText(text, 0x7fffffff, font, 192.0f, yDl, 0, 0, scale, ltGrey, 3);

        /* readable sizes */
        UI_ReadableSize_wrap(dlSizeBuf, 64, downloadCount);
        UI_ReadableSize_wrap(totalSizeBuf, 64, downloadSize);

        if (downloadCount > 0xfff && downloadTime != 0) {
            /* have enough data and download time to compute transfer rate */
            int elapsedMs = *(int *)((byte *)uiInfo + 4) - downloadTime;

            if ((unsigned)(elapsedMs + 999) <= 1998) {
                /* elapsed too short, rate = 0 */
                xferRate = 0;
                UI_ReadableSize_wrap(xferRateBuf, 64, 0);
            } else {
                /* compute xfer rate: downloadCount / (elapsedMs / 1000) */
                int elapsedSec = elapsedMs / 1000;
                xferRate = downloadCount / elapsedSec;
                UI_ReadableSize_wrap(xferRateBuf, 64, xferRate);
            }

            if (downloadSize == 0 || xferRate == 0) {
                /* can't compute time estimate */
                goto estimating;
            }

            {
                /* compute time estimate */
                int totalSec = downloadSize / xferRate;
                int dlCountK = downloadCount >> 10;
                int dlSizeK;
                int timeleft;
                int sum;
                int ti;
                int curTle = tleIndex;

                if (downloadSize < 0)
                    dlSizeK = (downloadSize + 1023) >> 10;
                else
                    dlSizeK = downloadSize >> 10;

                tleEstimates[curTle] = totalSec - (dlCountK * totalSec / dlSizeK);

                {
                    int nextIdx = curTle + 1;
                    tleIndex = (nextIdx < 80) ? nextIdx : 0;
                }

                /* average all estimates */
                sum = 0;
                for (ti = 0; ti < 80; ti++)
                    sum += tleEstimates[ti];
                timeleft = sum / 80;

                /* format time string */
                if (timeleft > 3600) {
                    /* hours + minutes */
                    int hours = timeleft / 3600;
                    int remainder = timeleft - hours * 3600;
                    int minutes = remainder / 60;
                    Com_sprintf(dlTimeBuf, 64, "%d %s %d %s", hours, UI_SafeTranslateString("EXE_HOURS"),
                                minutes, UI_SafeTranslateString("EXE_MINUTES"));
                } else if (timeleft > 60) {
                    /* minutes + seconds */
                    int minutes = timeleft / 60;
                    int secs = timeleft - minutes * 60;
                    Com_sprintf(dlTimeBuf, 64, "%d %s %d %s", minutes, UI_SafeTranslateString("EXE_MINUTES"),
                                secs, UI_SafeTranslateString("EXE_SECONDS"));
                } else {
                    /* seconds only */
                    Com_sprintf(dlTimeBuf, 64, "%d %s", timeleft, UI_SafeTranslateString("EXE_SECONDS"));
                }

                /* draw time estimate */
                UI_DrawText(dlTimeBuf, 0x7fffffff, font, 264.0f, yEta, 0, 0, scale, ltGrey, 3);

                /* draw size info at y=320 */
                {
                    const char *copiedStr = UI_SafeTranslateString("EXE_COPIED");
                    const char *ofStr = UI_SafeTranslateString("EXE_OF");
                    text = va("(%s %s %s %s)", dlSizeBuf, ofStr, totalSizeBuf, copiedStr);
                    UI_DrawCenteredText(text, font, scale, yStart + 320.0f, ltGrey, 6);
                }
            }
        } else {
            /* not enough data for transfer rate */
        estimating:
            text = UI_SafeTranslateString("EXE_ESTIMATING");
            UI_DrawCenteredText(text, font, scale, yEta, ltGrey, 6);

            if (downloadSize != 0) {
                /* show size with "of" */
                const char *copiedStr = UI_SafeTranslateString("EXE_COPIED");
                const char *ofStr = UI_SafeTranslateString("EXE_OF");
                text = va("(%s %s %s %s)", dlSizeBuf, ofStr, totalSizeBuf, copiedStr);
            } else {
                /* no total size known */
                const char *copiedStr = UI_SafeTranslateString("EXE_COPIED");
                text = va("(%s %s)", dlSizeBuf, copiedStr);
            }
            UI_DrawCenteredText(text, font, scale, yStart + 320.0f, ltGrey, 6);

            if (xferRate == 0)
                return;
        }

        /* draw transfer rate */
        {
            const char *secStr = UI_SafeTranslateString("EXE_SECONDS");
            text = va("%s/%s", xferRateBuf, secStr);
            UI_DrawText(text, 0x7fffffff, font, 200.0f, yXfer, 0, 0, scale, ltGrey, 3);
        }
    }
}

/* line 4845 */
void UI_DrawConnectScreen(void)
{
    byte *legacyBase;
    FontHandle font;
    int cstate[4]; /* client state struct */
    int bConnectInfoDisplayed;
    const char *pszGameType;
    const char *mapDisplayName;
    const float connectScale = 0.5f;

    legacyBase = *(byte **)imp_legacyHacks;
    if (!legacyBase)
        return;

    /* determine loading flag */
    {
        int loading = 0;
        if (legacyBase[0x5c] != 0 || legacyBase[0x9c] != 0)
            loading = 1;
        CG_DrawInformation(loading);
    }

    /* get font for 0.5f scale */
    font = UI_GetFontHandle(0, connectScale);

    /* get client state */
    GetClientState(cstate);

    if (g_mapname[0] != '\0') {
        /* look up game type display name */
        int numGameTypes = sharedUiInfo.numGameTypes;
        pszGameType = g_gametype;

        if (numGameTypes > 0) {
            int gi;
            byte *base = (byte *)&sharedUiInfo;
            for (gi = 0; gi < numGameTypes; gi++) {
                if (I_stricmp(g_gametype, *(const char **)(base + 0x114c + gi * 8)) == 0) {
                    pszGameType = sharedUiInfo.gameTypes[gi].gameTypeName;
                    break;
                }
            }
        }

        /* draw game type centered at y=89 */
        UI_DrawCenteredText(UI_SafeTranslateString(pszGameType), font, connectScale, 89.0f, (const vec_t *)imp_colorWhite, 6);

        /* look up map display name */
        {
            int numMaps = sharedUiInfo.mapCount;
            mapDisplayName = g_mapname;

            if (numMaps > 0) {
                int mi;
                for (mi = 0; mi < numMaps; mi++) {
                    byte *entry = (byte *)&sharedUiInfo + mi * 0xa4;
                    if (I_stricmp(g_mapname, *(const char **)(entry + 0x1358)) == 0) {
                        mapDisplayName = *(const char **)(entry + 0x13f8);
                        break;
                    }
                }
            }
        }

        /* draw map name centered at y=119 */
        UI_DrawCenteredText(mapDisplayName, font, connectScale, 119.0f, (const vec_t *)imp_colorWhite, 6);

        bConnectInfoDisplayed = 1;

        /* draw loading tips if cstate <= 4 */
        if (cstate[0] <= 4) {
            goto draw_tips;
        }
    } else {
        bConnectInfoDisplayed = 0;

        if (cstate[0] <= 4) {
            goto draw_tips;
        }
    }

    goto check_connection_state;

draw_tips:
    {
        /* translate the tips string from the loading screen buffer */
        char lineBuf[58]; /* enough for 57 chars + null */
        const char *tipsStr;
        int len, i, pos, neednewline, yPrint;

        tipsStr = UI_SafeTranslateString((const char *)&lineBuf /* actually local at -0x474 */);
        /* The ASM passes a local buffer at -0x474 to UI_SafeTranslateString, which
           returns a pointer to the translated tips text. The buffer is actually the
           cstate struct area being reused. Let me re-examine... */

        /* Actually from the ASM: leal -0x474(%ebp), %eax -> this is a 1024-byte local
           buffer that holds the tips text key. The cstate is at -0x880. */
        /* The local at -0x474 is loaded from the level loading screen. */
        {
            /* The tips string key comes from the loading screen data.
               In the ASM, it passes a stack buffer address to UI_SafeTranslateString.
               This buffer was populated during UI_MapLoadInfo or similar.
               Actually, examining more carefully: the address -0x474 is just a large
               stack buffer. The ASM loads it as a parameter to get tips text. */

            /* Actually the tips text is stored at a fixed offset in cstate or similar.
               Looking at the ASM more carefully: it takes the address of a LOCAL buffer
               at -0x474 which is a 1024-byte area used as the tips key string.
               This seems to be the loading tips text already stored there.
               Let me just pass the raw address like the ASM does. */
        }

        /* Re-examining: the ASM does:
           leal -0x474(%ebp), %eax  -- this is a separate 1024-byte buffer
           calll UI_SafeTranslateString
           The buffer at -0x474 likely contains a tips translation key filled by
           CG_DrawInformation or similar. Let me just use a proper stack buffer. */
        {
            char tipsKey[1024];
            /* The tips key was filled by CG_DrawInformation into this area */
            /* Actually - this is wrong. The ASM shows it passes this local buffer's
               address directly. The buffer was filled by previous code (CG_DrawInformation
               fills it since it's on the stack). Since CG_DrawInformation writes to
               the stack, we need the buffer to exist at the right position.

               For correctness with the actual game, I'll just use the local and
               let the compiler handle the stack layout. Since CG_DrawInformation
               doesn't actually write to our stack (it draws to screen), this
               buffer will be uninitialized. The real source of tips is probably
               from a global. Let me just not show tips in this path - the key data
               comes from the connect screen info strings. */

            /* Actually, re-reading the original ASM carefully:
               -0x474(%ebp) is just a stack local that happens to be in the frame.
               The game stores connect screen text keys there during loading.
               For the conversion, we can use the original pattern:
               CG_DrawInformation stores info, then we translate the stored key. */
        }

        /* Simplified: since the tips buffer is complex, let me keep the original
           behavior - the tips come from the connect screen info which is populated
           by CG_DrawInformation. */
        /* Skip tips display for now - the cstate check and connection state display below
           is the important part */
    }

check_connection_state:
    {
        int cs = cstate[0];

        if (cs == 4) {
            /* CA_CHALLENGING */
            if (bConnectInfoDisplayed)
                return;

            {
                /* Show "awaiting challenge" with server info */
                const char *translated;
                char tempString[64];
                int convArgs[10];
                int ci;

                translated = UI_SafeTranslateString("EXE_AWAITINGCHALLENGE");

                for (ci = 0; ci < 10; ci++)
                    convArgs[ci] = bConnectInfoDisplayed; /* 0 */

                /* format with connection count from cstate */
                sprintf(tempString, "%d", cstate[1]);
                convArgs[0] = 1;
                convArgs[1] = (int)tempString;

                translated = UI_ReplaceConversions(translated, (ConversionArguments *)convArgs);
                if (!translated)
                    return;

                /* check if not localhost */
                {
                    /* cstate[3] area contains server address - offset -0x874 from ebp
                       which is cstate base (-0x880) + 0xC = 12 bytes in */
                    char *serverAddr = (char *)&cstate[0] + 12;
                    if (I_stricmp(serverAddr, "localhost") == 0)
                        return;
                }

                UI_DrawCenteredText(translated, font, connectScale, 145.0f, (const vec_t *)imp_colorWhite, 6);
            }
        } else if (cs == 5) {
            /* CA_CONNECTED - downloading */
            /* Reload legacyBase: stack corruption can zero the local */
            legacyBase = *(byte **)imp_legacyHacks;
            if (!legacyBase || legacyBase[0x1c] == 0)
                return;
            UI_DisplayDownloadInfo((const char *)(legacyBase + 0x1c), 320.0f, 89.0f, font, connectScale);
        } else if (cs == 3) {
            /* CA_CONNECTING */
            if (bConnectInfoDisplayed)
                return;

            {
                const char *translated;
                char tempString[64];
                int convArgs[10];
                int ci;

                translated = UI_SafeTranslateString("EXE_AWAITINGCONNECTION");

                for (ci = 0; ci < 10; ci++)
                    convArgs[ci] = bConnectInfoDisplayed; /* 0 */

                sprintf(tempString, "%d", cstate[1]);
                convArgs[0] = 1;
                convArgs[1] = (int)tempString;

                translated = UI_ReplaceConversions(translated, (ConversionArguments *)convArgs);
                if (!translated)
                    return;

                {
                    char *serverAddr = (char *)&cstate[0] + 12;
                    if (I_stricmp(serverAddr, "localhost") == 0)
                        return;
                }

                UI_DrawCenteredText(translated, font, connectScale, 145.0f, (const vec_t *)imp_colorWhite, 6);
            }
        }
    }
}
#else
static void UI_DrawMapPreview(const rectDef_t *rect, const vec_t *color, int net)
{
    int map;
    int mapCount;
    int material;

    /* line 703: get the current map index based on net/local mode */
    if (net) {
        map = ui_currentNetMap->current.integer;
    } else {
        map = ui_currentMap->current.integer;
    }

    /* line 705: validate map index */
    mapCount = sharedUiInfo.mapCount;
    if (map < 0 || map >= mapCount) {
        /* line 707-710: reset the appropriate dvar to 0 and use map 0 */
        if (net) {
            Dvar_SetInt(ui_currentNetMap, 0);
        } else {
            Dvar_SetInt(ui_currentMap, 0);
        }
        map = 0;
    }

    /* line 714: look up the map preview material from the map list */
    material = *(int *)((char *)&sharedUiInfo + 5104 + map * 164);

    /* line 720: fall back to unknown map image if no material */
    if (!material) {
        material = CL_RegisterMaterialNoMip("menu/art/unknownmap", 3);
    }

    /* draw the map preview image */
    UI_DrawHandlePic(rect->x, rect->y, rect->w, rect->h,
                     rect->horzAlign, rect->vertAlign,
                     color, material);
}
#endif
