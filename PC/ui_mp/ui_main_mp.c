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
__attribute__((used)) int lastColumn = -1; /* 0x311ebc */
static int lastTime; /* lastTime */
static char info_00ecf960[1024]; /* info */
static char info_00ecf960[1024]; /* info */
static char info_00ecf960[1024]; /* info */
static int numFound; /* numFound */
static int numTimeOuts; /* numTimeOuts */
__attribute__((used, aligned(1))) char dlText[31] = "EXE_DOWNLOADING"; /* 0x312021 */
__attribute__((used, aligned(1))) char etaText[18] = "EXE_EST_TIME_LEFT"; /* 0x31200f */
__attribute__((used, aligned(1))) char xferText[15] = "EXE_TRANS_RATE"; /* 0x312000 */
__attribute__((used)) int tleEstimates[80] = { [0 ... 79] = 60 }; /* 0x311ec0 */
static int tleIndex; /* tleIndex */
static char g_mapname[64]; /* g_mapname */
static char g_gametype[64]; /* g_gametype */
static Bool g_ingameMenusLoaded; /* g_ingameMenusLoaded */
extern const char str_002a9d68[];
extern const char str_002a9d80[];
extern const char str_002a9d98[];
extern const char str_002a9dac[];
extern const char str_002a9dc0[];
extern const char str_002a9dd4[];
extern const char str_002a9de8[];
extern const char str_002a9dfc[];
extern const char str_002a9e14[];
extern const char str_002a9e2c[];
extern const char str_002a9e44[];
extern const char str_002a9e5c[];
extern const char str_002a9e74[];
extern const char str_002a9e80[];
extern const char str_002a9e90[];

__attribute__((used, packed, aligned(4)))
UInt32 MonthAbbrev_storage[12] __asm__("MonthAbbrev") = {
    (UInt32)str_002a9d68,
    (UInt32)str_002a9d80,
    (UInt32)str_002a9d98,
    (UInt32)str_002a9dac,
    (UInt32)str_002a9dc0,
    (UInt32)str_002a9dd4,
    (UInt32)str_002a9de8,
    (UInt32)str_002a9dfc,
    (UInt32)str_002a9e14,
    (UInt32)str_002a9e2c,
    (UInt32)str_002a9e44,
    (UInt32)str_002a9e5c,
}; /* 0x311e80 */
__attribute__((used, packed, aligned(4)))
UInt32 netSources_storage[3] __asm__("netSources") = {
    (UInt32)str_002a9e74,
    (UInt32)str_002a9e80,
    (UInt32)str_002a9e90,
}; /* 0x311eb0 */

#define MonthAbbrev ((const char * const *)MonthAbbrev_storage)
#define netSources ((const char * const *)netSources_storage)
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
