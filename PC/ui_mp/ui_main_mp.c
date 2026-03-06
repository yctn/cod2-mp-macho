/* ASM dump from: ui_main_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui_mp/ui_main_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

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
__attribute__((naked))
void UI_AssetCache(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 323 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $3, 4(%esp)\n" /* line 325 */
        "movl $str_00224184, (%esp)\n" /* "white" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+32\n"
        "movl $3, 4(%esp)\n" /* line 326 */
        "movl $str_002a9ea0, (%esp)\n" /* "ui/assets/scrollbar.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+16\n"
        "movl $3, 4(%esp)\n" /* line 327 */
        "movl $str_002a9eb8, (%esp)\n" /* "ui/assets/scrollbar_arrow_dwn_a.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+4\n"
        "movl $3, 4(%esp)\n" /* line 328 */
        "movl $str_002a9edc, (%esp)\n" /* "ui/assets/scrollbar_arrow_up_a.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo\n"
        "movl $3, 4(%esp)\n" /* line 329 */
        "movl $str_002a9f00, (%esp)\n" /* "ui/assets/scrollbar_arrow_left.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+8\n"
        "movl $3, 4(%esp)\n" /* line 330 */
        "movl $str_002a9f24, (%esp)\n" /* "ui/assets/scrollbar_arrow_right.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+12\n"
        "movl $3, 4(%esp)\n" /* line 331 */
        "movl $str_002a9f48, (%esp)\n" /* "ui/assets/scrollbar_thumb.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+20\n"
        "movl $3, 4(%esp)\n" /* line 332 */
        "movl $str_002a9f68, (%esp)\n" /* "ui/assets/slider2.tga" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+24\n"
        "movl $3, 4(%esp)\n" /* line 333 */
        "movl $str_002a9f80, (%esp)\n" /* "ui/assets/sliderbutt_1" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+28\n"
        "movl $0, 4(%esp)\n" /* line 334 */
        "movl $str_002a9f98, (%esp)\n" /* "$cursor" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+36\n"
        "movl $0, 4(%esp)\n" /* line 335 */
        "movl $str_002a9fa0, (%esp)\n" /* "$bigfont" */
        "calll CL_RegisterFont\n"
        "movl %eax, sharedUiInfo+40\n"
        "movl $0, 4(%esp)\n" /* line 336 */
        "movl $str_002a9fac, (%esp)\n" /* "$smallfont" */
        "calll CL_RegisterFont\n"
        "movl %eax, sharedUiInfo+44\n"
        "movl $0, 4(%esp)\n" /* line 337 */
        "movl $str_002a9fb8, (%esp)\n" /* "$consolefont" */
        "calll CL_RegisterFont\n"
        "movl %eax, sharedUiInfo+48\n"
        "movl $0, 4(%esp)\n" /* line 338 */
        "movl $str_002a9fc8, (%esp)\n" /* "$boldfont" */
        "calll CL_RegisterFont\n"
        "movl %eax, sharedUiInfo+52\n"
        "movl $0, 4(%esp)\n" /* line 339 */
        "movl $str_002a9fd4, (%esp)\n" /* "$font" */
        "calll CL_RegisterFont\n"
        "movl %eax, sharedUiInfo+56\n"
        "movl $0, 4(%esp)\n" /* line 340 */
        "movl $str_002a9fdc, (%esp)\n" /* "$extrabigfont" */
        "calll CL_RegisterFont\n"
        "movl %eax, sharedUiInfo+60\n"
        "movl $str_002a9fec, (%esp)\n" /* line 342 */
        "calll Com_FindSoundAlias\n"
        "movl %eax, sharedUiInfo+64\n"
        "leave\n" /* line 344 */
        "retl\n"
    );
}

/* line 347 */
__attribute__((naked))
void UI_DrawSides(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 347 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movl 0x1c(%ebp), %edi\n" /* vertAlign */
        "movl 0x24(%ebp), %esi\n" /* color */
        "movl sharedUiInfo+32, %eax\n" /* line 349 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n" /* color */
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* vertAlign */
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm1\n" /* h */
        "movss %xmm1, 0xc(%esp)\n"
        "movss 0x20(%ebp), %xmm1\n" /* size */
        "movss %xmm1, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "calll CL_DrawStretchPic\n"
        "movl sharedUiInfo+32, %eax\n" /* line 350 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n" /* color */
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* vertAlign */
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x14(%ebp), %xmm1\n" /* h */
        "movss %xmm1, 0xc(%esp)\n"
        "movss 0x20(%ebp), %xmm1\n" /* size */
        "movss %xmm1, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 4(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "addss 0x10(%ebp), %xmm0\n" /* w */
        "subss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "addl $0x4c, %esp\n" /* line 351 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 354 */
__attribute__((naked))
void UI_DrawTopBottom(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 354 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movl 0x1c(%ebp), %edi\n" /* vertAlign */
        "movl 0x24(%ebp), %esi\n" /* color */
        "movl sharedUiInfo+32, %eax\n" /* line 356 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n" /* color */
        "xorl %ebx, %ebx\n"
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* vertAlign */
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x20(%ebp), %xmm1\n" /* size */
        "movss %xmm1, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm1\n" /* w */
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm1\n" /* x */
        "movss %xmm1, (%esp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "calll CL_DrawStretchPic\n"
        "movl sharedUiInfo+32, %eax\n" /* line 357 */
        "movl %eax, 0x2c(%esp)\n"
        "movl %esi, 0x28(%esp)\n" /* color */
        "movl %ebx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl %ebx, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* vertAlign */
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "movss 0x20(%ebp), %xmm1\n" /* size */
        "movss %xmm1, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm1\n" /* w */
        "movss %xmm1, 8(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "addss 0x14(%ebp), %xmm0\n" /* h */
        "subss 0x20(%ebp), %xmm0\n" /* size */
        "movss %xmm0, 4(%esp)\n"
        "movss 8(%ebp), %xmm0\n" /* x */
        "movss %xmm0, (%esp)\n"
        "calll CL_DrawStretchPic\n"
        "addl $0x4c, %esp\n" /* line 358 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 375 */
__attribute__((naked))
int UI_TextWidth(const char *text, int maxChars, FontHandle font, float scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 375 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* font */
        /* { scope 1 */
        "movl 0x14(%ebp), %eax\n" /* line 379 | scale */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* font */
        "calll CL_NormalizedTextScale\n"
        "fstps -0xc(%ebp)\n" /* actualScale */
        "movl %ebx, 8(%esp)\n" /* line 380 | font */
        "movl 0xc(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll CL_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 381 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 384 */
__attribute__((naked))
int UI_TextHeight(FontHandle font, float scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 384 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* font */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 388 | scale */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* font */
        "calll CL_NormalizedTextScale\n"
        "fstps -0xc(%ebp)\n" /* actualScale */
        "movl %ebx, (%esp)\n" /* line 389 | font */
        "calll CL_TextHeight\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 390 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 434 */
__attribute__((naked))
FontHandle UI_GetFontHandle(int fontEnum, float scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 434 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* fontEnum */
        "cmpl $2, %ebx\n" /* line 436 | fontEnum */
        "je .Lf14eddc_0014ee64\n"
        "cmpl $3, %ebx\n" /* line 438 | fontEnum */
        "je .Lf14eddc_0014ee59\n"
        "cmpl $5, %ebx\n" /* line 440 | fontEnum */
        "je .Lf14eddc_0014ee3e\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 449 | scale */
        "movss %xmm0, (%esp)\n"
        "calll GetRealHeightFromVirtualHeight\n"
        "fstps -0xc(%ebp)\n"
        "cmpl $4, %ebx\n" /* line 451 | fontEnum */
        "je .Lf14eddc_0014ee49\n"
        "movl ui_smallFont, %eax\n" /* line 463 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss -0xc(%ebp), %xmm0\n"
        "jae .Lf14eddc_0014ee59\n"
        "movl ui_extraBigFont, %eax\n" /* line 465 */
        "movss -0xc(%ebp), %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jae .Lf14eddc_0014ee6f\n"
        "movl ui_bigFont, %eax\n" /* line 467 */
        "ucomiss 8(%eax), %xmm0\n"
        "jae .Lf14eddc_0014ee64\n"
        ".Lf14eddc_0014ee37:\n"
        "movl sharedUiInfo+56, %eax\n" /* line 470 */
        "jmp .Lf14eddc_0014ee43\n"
        ".Lf14eddc_0014ee3e:\n"
        "movl sharedUiInfo+48, %eax\n" /* line 441 */
        ".Lf14eddc_0014ee43:\n"
        "addl $0x24, %esp\n" /* line 471 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14eddc_0014ee49:\n"
        "movl ui_smallFont, %eax\n" /* line 454 */
        "movss 8(%eax), %xmm0\n"
        "ucomiss -0xc(%ebp), %xmm0\n"
        "jb .Lf14eddc_0014ee76\n"
        ".Lf14eddc_0014ee59:\n"
        "movl sharedUiInfo+44, %eax\n" /* line 464 */
        "addl $0x24, %esp\n" /* line 471 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14eddc_0014ee64:\n"
        "movl sharedUiInfo+40, %eax\n" /* line 468 */
        "addl $0x24, %esp\n" /* line 471 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14eddc_0014ee6f:\n"
        "movl sharedUiInfo+60, %eax\n" /* line 466 */
        "jmp .Lf14eddc_0014ee43\n"
        ".Lf14eddc_0014ee76:\n"
        "movl ui_bigFont, %eax\n" /* line 456 */
        "movss -0xc(%ebp), %xmm0\n"
        "ucomiss 8(%eax), %xmm0\n"
        "jb .Lf14eddc_0014ee37\n"
        "movl sharedUiInfo+52, %eax\n" /* line 457 */
        "jmp .Lf14eddc_0014ee43\n"
    );
}

/* line 479 */
__attribute__((naked))
void UI_UpdateTime(int realtime)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 479 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* realtime */
        /* { scope 1 */
        "movl uiInfo, %edx\n" /* line 486 */
        "movl %ecx, %eax\n"
        "subl 4(%edx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl uiInfo, %eax\n" /* line 487 */
        "movl %ecx, 4(%eax)\n"
        "movl uiInfo, %edx\n" /* line 489 */
        "movl 0x488(%edx), %ecx\n"
        "andl $0x80000003, %ecx\n"
        "js .Lf14ee8e_0014ef1a\n"
        ".Lf14ee8e_0014eebf:\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 0x48c(%edx, %ecx, 4)\n"
        "movl uiInfo, %eax\n" /* line 490 */
        "addl $1, 0x488(%eax)\n"
        "movl uiInfo, %ebx\n" /* line 494 */
        "cmpl $4, 0x488(%ebx)\n"
        "jle .Lf14ee8e_0014ef0d\n"
        "movl %ebx, %eax\n"
        "xorl %ecx, %ecx\n"
        "movl $4, %edx\n"
        ".Lf14ee8e_0014eeed:\n"
        "addl 0x48c(%eax), %ecx\n" /* line 499 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 498 */
        "jne .Lf14ee8e_0014eeed\n"
        "testl %ecx, %ecx\n" /* line 501 */
        "jne .Lf14ee8e_0014ef10\n"
        "movl $0xfa0, %eax\n"
        ".Lf14ee8e_0014ef04:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 503 */
        "movss %xmm0, 0x24(%ebx)\n"
        /* } scope */
        ".Lf14ee8e_0014ef0d:\n"
        "popl %ebx\n" /* line 505 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14ee8e_0014ef10:\n"
        "movl $0xfa0, %eax\n" /* line 501 */
        "cltd\n"
        "idivl %ecx\n"
        "jmp .Lf14ee8e_0014ef04\n"
        ".Lf14ee8e_0014ef1a:\n"
        "subl $1, %ecx\n" /* line 489 */
        "orl $0xfffffffc, %ecx\n"
        "addl $1, %ecx\n"
        "jmp .Lf14ee8e_0014eebf\n"
    );
}

/* line 542 */
void UI_Shutdown(void)
{
    Menus_CloseAll(uiInfo);
    *(int *)((char *)&sharedUiInfo + 32) = 0;
    LAN_SaveServersToCache();
}

/* line 551 */
__attribute__((naked))
char * GetMenuBuffer(const char *filename)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 551 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* filename */
        /* { scope 1 */
        "movl $0, 8(%esp)\n" /* line 561 */
        "leal -0xc(%ebp), %eax\n" /* f */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* filename */
        "calll FS_FOpenFileByMode\n"
        "movl %eax, %ebx\n" /* len */
        "movl -0xc(%ebp), %eax\n" /* line 562 | f */
        "testl %eax, %eax\n"
        "je .Lf14ef4a_0014efda\n"
        "cmpl $0x7fff, %ebx\n" /* line 567 | len */
        "jg .Lf14ef4a_0014efaf\n"
        "movl %eax, 8(%esp)\n" /* line 574 */
        "movl %ebx, 4(%esp)\n" /* len */
        "movl $menuBuf2, (%esp)\n"
        "calll FS_Read\n"
        "movb $0, menuBuf2(%ebx)\n" /* line 575 | len */
        "movl -0xc(%ebp), %eax\n" /* line 576 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "movl $menuBuf2, %eax\n"
        /* } scope */
        ".Lf14ef4a_0014efa8:\n"
        "addl $0x20, %esp\n" /* line 589 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14ef4a_0014efaf:\n"
        "movl $0x8000, 0xc(%esp)\n" /* line 569 */
        "movl %ebx, 8(%esp)\n" /* len */
        "movl %esi, 4(%esp)\n" /* filename */
        "movl $str_002aa028, (%esp)\n" /* "^1menu file too large: %s is %i, max allowed is %i" */
        "calll Com_Printf\n"
        "movl -0xc(%ebp), %eax\n" /* line 570 | f */
        "movl %eax, (%esp)\n"
        "calll FS_FCloseFile\n"
        "xorl %eax, %eax\n"
        "jmp .Lf14ef4a_0014efa8\n"
        ".Lf14ef4a_0014efda:\n"
        "movl %esi, 4(%esp)\n" /* line 564 | filename */
        "movl $str_002a9ffc, (%esp)\n" /* "^1menu file not found: %s, using default
" */
        "calll Com_Printf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf14ef4a_0014efa8\n"
    );
}

/* line 615 */
__attribute__((naked))
qboolean Load_ScriptMenu(const char *pszMenu, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 615 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x114, %esp\n"
        /* { scope 1: szMenuFile */
        /* { scope 2 */
        "leal -0x108(%ebp), %ebx\n" /* line 602 | szMenuFile */
        "movl $0x6d5f6975, -0x108(%ebp)\n" /* szMenuFile */
        "movl $0x63732f70, -0x104(%ebp)\n"
        "movl $0x74706972, -0x100(%ebp)\n"
        "movl $0x756e656d, -0xfc(%ebp)\n"
        "movw $0x2f73, -0xf8(%ebp)\n"
        "movb $0, -0xf6(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 603 | pszMenu */
        "movl %eax, 8(%esp)\n"
        "movl $0x100, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_002172c4, 8(%esp)\n" /* line 604 */
        "movl $0x100, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncat\n"
        "movl 0xc(%ebp), %eax\n" /* line 606 | imageTrack */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll UI_LoadMenu\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 620 */
        "je .Lf14efee_0014f08e\n"
        "movl %eax, 4(%esp)\n" /* line 623 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_AddMenuList\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf14efee_0014f08e:\n"
        "addl $0x114, %esp\n" /* line 625 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
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
__attribute__((naked))
const char * UI_GetMapDisplayName(const char *pszMap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 787 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pszMap */
        /* { scope 1 */
        "movl sharedUiInfo+4944, %eax\n" /* line 791 */
        "testl %eax, %eax\n"
        "jg .Lf14f178_0014f197\n"
        /* } scope */
        ".Lf14f178_0014f18d:\n"
        "movl %esi, %eax\n" /* line 797 | pszMap */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f178_0014f197:\n"
        "xorl %edi, %edi\n" /* line 791 | i */
        "movl $sharedUiInfo, %ebx\n"
        "movl $sharedUiInfo+4948, -0x1c(%ebp)\n"
        "jmp .Lf14f178_0014f1bf\n"
        ".Lf14f178_0014f1a7:\n"
        "addl $1, %edi\n" /* i */
        "addl $0xa4, -0x1c(%ebp)\n"
        "addl $0xa4, %ebx\n"
        "cmpl sharedUiInfo+4944, %edi\n" /* i */
        "jge .Lf14f178_0014f18d\n"
        ".Lf14f178_0014f1bf:\n"
        "movl 0x1358(%ebx), %eax\n" /* line 793 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pszMap */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14f178_0014f1a7\n"
        "movl -0x1c(%ebp), %eax\n" /* line 794 */
        "movl (%eax), %esi\n" /* pszMap */
        "jmp .Lf14f178_0014f18d\n"
    );
}

/* line 799 */
__attribute__((naked))
const char * UI_GetMapDisplayNameFromPartialLoadNameMatch(const char *pszMap, int *mapLoadNameLen)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 799 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl sharedUiInfo+4944, %edx\n" /* line 805 */
        "testl %edx, %edx\n"
        "jg .Lf14f1dc_0014f1f9\n"
        ".Lf14f1dc_0014f1ef:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf14f1dc_0014f1f1:\n"
        "addl $0x2c, %esp\n" /* line 813 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f1dc_0014f1f9:\n"
        "xorl %esi, %esi\n" /* line 805 | i */
        "movl $sharedUiInfo, %ebx\n"
        "movl $sharedUiInfo+4948, -0x1c(%ebp)\n"
        ".Lf14f1dc_0014f207:\n"
        "movl 0x1358(%ebx), %edi\n" /* line 896 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* line 807 | mapLoadNameLen */
        "movl %ecx, (%edx)\n"
        "movl %ecx, 8(%esp)\n" /* line 809 */
        "movl 0x1358(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* pszMap */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf14f1dc_0014f258\n"
        "addl $1, %esi\n" /* line 805 | i */
        "addl $0xa4, -0x1c(%ebp)\n"
        "addl $0xa4, %ebx\n"
        "cmpl sharedUiInfo+4944, %esi\n" /* i */
        "jl .Lf14f1dc_0014f207\n"
        "jmp .Lf14f1dc_0014f1ef\n"
        ".Lf14f1dc_0014f258:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 810 */
        "movl (%edx), %eax\n"
        "jmp .Lf14f1dc_0014f1f1\n"
    );
}

/* line 816 */
__attribute__((naked))
const char * UI_GetGameTypeDisplayName(const char *pszGameType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 816 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* pszGameType */
        /* { scope 1 */
        "movl sharedUiInfo+4424, %ecx\n" /* line 820 */
        "testl %ecx, %ecx\n"
        "jg .Lf14f260_0014f280\n"
        /* } scope */
        ".Lf14f260_0014f276:\n"
        "movl %esi, %eax\n" /* line 826 | pszGameType */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f260_0014f280:\n"
        "xorl %edi, %edi\n" /* line 820 | i */
        "movl $sharedUiInfo, %ebx\n"
        "jmp .Lf14f260_0014f297\n"
        ".Lf14f260_0014f289:\n"
        "addl $1, %edi\n" /* i */
        "addl $8, %ebx\n"
        "cmpl sharedUiInfo+4424, %edi\n" /* i */
        "jge .Lf14f260_0014f276\n"
        ".Lf14f260_0014f297:\n"
        "movl 0x114c(%ebx), %eax\n" /* line 822 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* pszGameType */
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf14f260_0014f289\n"
        "movl sharedUiInfo+4432(, %edi, 8), %esi\n" /* line 823 | pszGameType */
        "jmp .Lf14f260_0014f276\n"
    );
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

/* line 974 */
__attribute__((naked))
void UI_DrawMapLevelshot(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 974 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_mapname\n" /* line 978 */
        "je .Lf14f398_0014f3e9\n"
        "movl $str_002a90c0, 4(%esp)\n" /* line 979 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_FindByName\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 983 */
        "je .Lf14f398_0014f3e9\n"
        "movl uiInfo, %eax\n" /* line 989 */
        "movl $0, 0x28(%eax)\n"
        "movl $1, 8(%esp)\n" /* line 990 */
        "movl %edx, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_Paint\n"
        /* } scope */
        "leave\n" /* line 991 */
        "retl\n"
        /* { scope 1 */
        ".Lf14f398_0014f3e9:\n"
        "movl imp_colorBlack, %eax\n" /* line 985 */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x43f00000, 0xc(%esp)\n"
        "movl $0x44200000, 8(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_FillRect\n"
        /* } scope */
        "leave\n" /* line 991 */
        "retl\n"
    );
}

/* line 994 */
__attribute__((naked))
void UI_LoadIngameMenus(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 994 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "cmpb $0, g_ingameMenusLoaded\n" /* line 998 */
        "je .Lf14f422_0014f433\n"
        /* } scope */
        "leave\n" /* line 1004 */
        "retl\n"
        /* { scope 1 */
        ".Lf14f422_0014f433:\n"
        "movb $1, g_ingameMenusLoaded\n" /* line 1001 */
        "movl $3, 4(%esp)\n" /* line 1002 */
        "movl $str_002aa070, (%esp)\n" /* "ui_mp/ingame.txt" */
        "calll UI_LoadMenus\n"
        "movl %eax, 4(%esp)\n" /* line 1003 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_AddMenuList\n"
        /* } scope */
        "leave\n" /* line 1004 */
        "retl\n"
    );
}

/* line 1007 */
__attribute__((naked))
void UI_SetMap(const char *mapname, const char *gametype)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1007 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* gametype */
        "movl $0x40, 8(%esp)\n" /* line 1009 */
        "movl 8(%ebp), %eax\n" /* mapname */
        "movl %eax, 4(%esp)\n"
        "movl $g_mapname, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x40, 8(%esp)\n" /* line 1010 */
        "movl %ebx, 4(%esp)\n" /* gametype */
        "movl $g_gametype, (%esp)\n"
        "calll I_strncpyz\n"
        "cmpb $0, g_mapname\n" /* line 1013 */
        "jne .Lf14f462_0014f4ae\n"
        "addl $0x14, %esp\n" /* line 1016 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14f462_0014f4ae:\n"
        "movl $g_mapname, 4(%esp)\n" /* line 1014 */
        "movl $str_002aa084, (%esp)\n" /* "maps/mp/%s.csv" */
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* mapname */
        "addl $0x14, %esp\n" /* line 1016 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp UI_MapLoadInfo\n" /* line 1014 */
    );
}

/* line 1275 */
__attribute__((naked))
qboolean UI_OwnerDrawVisible(int flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1275 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* flags */
        /* { scope 1 */
        "testb $4, %cl\n" /* line 1280 */
        "je .Lf14f4d0_0014f4f1\n"
        "movl ui_netSource, %eax\n" /* line 1283 */
        "cmpl $2, 8(%eax)\n"
        "je .Lf14f4d0_0014f4f1\n"
        "xorl %edx, %edx\n"
        "andb $0x10, %ch\n" /* line 1288 */
        "jne .Lf14f4d0_0014f4fb\n"
        /* } scope */
        ".Lf14f4d0_0014f4ed:\n"
        "movl %edx, %eax\n" /* line 1299 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f4d0_0014f4f1:\n"
        "movl $1, %edx\n" /* line 1283 */
        "andb $0x10, %ch\n" /* line 1288 */
        "je .Lf14f4d0_0014f4ed\n"
        ".Lf14f4d0_0014f4fb:\n"
        "movl ui_netSource, %eax\n" /* line 1291 */
        "cmpl $2, 8(%eax)\n"
        "movl $0, %eax\n"
        "cmovel %eax, %edx\n"
        /* } scope */
        "movl %edx, %eax\n" /* line 1299 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1506 */
static __attribute__((naked))
int UI_ServersQsortCompare(const void *arg1, const void *arg2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1506 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 1508 | arg2 */
        "movl (%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n" /* arg1 */
        "movl (%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl sharedUiInfo+28644, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl sharedUiInfo+28640, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_CompareServers\n"
        "leave\n" /* line 1509 */
        "retl\n"
    );
}

/* line 1591 */
static __attribute__((naked))
int UI_PlayerProfilesQsortCompare(const void *arg1, const void *arg2)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1591 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1599 | arg1 */
        "movl (%eax), %ecx\n"
        "movl 0xc(%ebp), %eax\n" /* line 1600 | arg2 */
        "movl (%eax), %eax\n"
        "cmpl %eax, %ecx\n" /* line 1602 */
        "je .Lf14f54c_0014f59a\n"
        "movl uiInfo, %edx\n" /* line 1605 */
        "movl 0x284(%edx, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x284(%edx, %ecx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edx\n" /* line 1610 */
        "negl %edx\n"
        "movl uiInfo, %eax\n"
        "movl 0x384(%eax), %eax\n"
        "testl %eax, %eax\n"
        "cmovel %edx, %ecx\n"
        /* } scope */
        "movl %ecx, %eax\n" /* line 1611 */
        "leave\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f54c_0014f59a:\n"
        "xorl %ecx, %ecx\n" /* line 1602 */
        /* } scope */
        "movl %ecx, %eax\n" /* line 1611 */
        "leave\n"
        "retl\n"
    );
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
__attribute__((naked))
qboolean UI_CheckExecKey(int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1849 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* key */
        /* { scope 1 */
        "movl uiInfo, %eax\n" /* line 1852 */
        "movl %eax, (%esp)\n"
        "calll Menu_GetFocused\n"
        "movl %eax, %edx\n" /* menu */
        "movl imp_g_editingField, %eax\n" /* line 1854 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf14f682_0014f6c9\n"
        "cmpl $0x100, %ebx\n" /* line 1857 | key */
        "jg .Lf14f682_0014f6d4\n"
        "testl %edx, %edx\n" /* line 1860 */
        "je .Lf14f682_0014f6d4\n"
        "movl 0x250(%edx), %eax\n" /* line 1863 */
        "testl %eax, %eax\n"
        "jne .Lf14f682_0014f6c5\n"
        "jmp .Lf14f682_0014f6d4\n"
        ".Lf14f682_0014f6be:\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf14f682_0014f6d4\n"
        ".Lf14f682_0014f6c5:\n"
        "cmpl (%eax), %ebx\n" /* line 1865 | key */
        "jne .Lf14f682_0014f6be\n"
        ".Lf14f682_0014f6c9:\n"
        "movl $1, %eax\n" /* line 1863 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1871 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f682_0014f6d4:\n"
        "xorl %eax, %eax\n" /* line 1863 */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1871 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1928 */
static __attribute__((naked))
void UI_VerifyLanguage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1928 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl $str_00216a14, (%esp)\n" /* line 1934 */
        "calll Dvar_GetInt\n"
        "movl %eax, %esi\n" /* oldLanguage */
        "movl $str_002aa0a8, (%esp)\n" /* line 1935 */
        "calll Dvar_GetInt\n"
        "movl %eax, %ebx\n" /* newLanguage */
        "movl %eax, (%esp)\n" /* line 1938 */
        "calll SEH_VerifyLanguageSelection\n"
        "cmpl %eax, %ebx\n" /* line 1939 | newLanguage */
        "je .Lf14f6dc_0014f71c\n"
        "movl %eax, 4(%esp)\n" /* line 1941 */
        "movl $str_002aa0a8, (%esp)\n" /* "ui_language" */
        "calll Dvar_SetIntByName\n"
        ".Lf14f6dc_0014f71c:\n"
        "cmpl %ebx, %esi\n" /* line 1944 | newLanguage, oldLanguage */
        "je .Lf14f6dc_0014f73b\n"
        "movl $1, 4(%esp)\n" /* line 1945 */
        "movl $str_002aa0b4, (%esp)\n" /* "ui_languagechanged" */
        "calll Dvar_SetBoolByName\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1948 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f6dc_0014f73b:\n"
        "movl $0, 4(%esp)\n" /* line 1947 */
        "movl $str_002aa0b4, (%esp)\n" /* "ui_languagechanged" */
        "calll Dvar_SetBoolByName\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1948 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5151 */
__attribute__((naked))
const char * UI_SafeTranslateString(const char *reference)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5151 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* reference */
        /* { scope 1 */
        "cmpb $0x15, (%ebx)\n" /* line 5156 | reference */
        "je .Lf14f756_0014f777\n"
        "movl %ebx, (%esp)\n" /* line 5163 | reference */
        "calll SEH_StringEd_GetString\n"
        "testl %eax, %eax\n" /* line 5166 */
        "je .Lf14f756_0014f77a\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 5188 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f756_0014f777:\n"
        "addl $1, %ebx\n" /* line 5158 | reference */
        ".Lf14f756_0014f77a:\n"
        "movl imp_loc_warnings, %eax\n" /* line 5168 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14f756_0014f834\n"
        "movl imp_loc_warningsAsErrors, %eax\n" /* line 5170 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf14f756_0014f822\n"
        "movl %ebx, 8(%esp)\n" /* line 5171 | reference */
        "movl $str_002aa0c8, 4(%esp)\n" /* "Could not translate string "%s"" */
        "movl $6, (%esp)\n"
        "calll Com_Error\n"
        ".Lf14f756_0014f7b4:\n"
        "movl $0x4e55315e, errorString\n" /* line 5175 */
        "movl $0x41434f4c, errorString+4\n"
        "movl $0x455a494c, errorString+8\n"
        "movl $0x375e2844, errorString+12\n"
        "movb $0, errorString+16\n"
        "movl %ebx, 8(%esp)\n" /* line 5176 | reference */
        "movl $0x400, 4(%esp)\n"
        "movl $errorString, (%esp)\n"
        "calll I_strncat\n"
        "movl $str_00216b78, 8(%esp)\n" /* line 5177 */
        "movl $0x400, 4(%esp)\n"
        "movl $errorString, (%esp)\n"
        "calll I_strncat\n"
        "movl $errorString, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 5188 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14f756_0014f822:\n"
        "movl %ebx, 4(%esp)\n" /* line 5173 | reference */
        "movl $str_002aa0e8, (%esp)\n" /* "^3WARNING: Could not translate string "%s"
" */
        "calll Com_Printf\n"
        "jmp .Lf14f756_0014f7b4\n"
        ".Lf14f756_0014f834:\n"
        "movl %ebx, 4(%esp)\n" /* line 5181 | reference */
        "movl $errorString, (%esp)\n"
        "calll strcpy\n"
        "movl $errorString, %eax\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 5188 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
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
__attribute__((naked))
void UI_FeederSelection(float feederID, int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3884 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* feederID */
        "movl 0xc(%ebp), %esi\n" /* index */
        /* { scope 1 */
        "ucomiss lit4_002ed608, %xmm0\n" /* line 3895 | 4.0f */
        "jne .Lf14fee2_0014ff91\n"
        "jp .Lf14fee2_0014ff91\n"
        /* { scope 2 */
        "movl ui_currentNetMap, %eax\n" /* line 3899 */
        "movl 8(%eax), %eax\n"
        "leal (%eax, %eax, 4), %edx\n" /* line 3900 */
        "leal (%eax, %edx, 8), %edx\n"
        "leal (, %edx, 4), %ebx\n" /* actual */
        "movl sharedUiInfo+4972(%ebx), %eax\n" /* actual */
        "testl %eax, %eax\n"
        "js .Lf14fee2_0014ff39\n"
        "movl %eax, (%esp)\n" /* line 3902 */
        "calll CIN_StopCinematic\n"
        "movl $sharedUiInfo+4960, %eax\n" /* line 3903 */
        "movl $0xffffffff, 0xc(%ebx, %eax)\n" /* actual */
        /* { scope 3 */
        ".Lf14fee2_0014ff39:\n"
        "movl sharedUiInfo+4944, %ecx\n" /* line 3511 */
        "testl %ecx, %ecx\n"
        "jle .Lf14fee2_0014ff68\n"
        "xorl %edx, %edx\n"
        "xorl %ebx, %ebx\n"
        "movl $sharedUiInfo, %eax\n"
        ".Lf14fee2_0014ff4c:\n"
        "cmpl $0, 0x13f4(%eax)\n" /* line 3513 */
        "je .Lf14fee2_0014ff5c\n"
        "cmpl %esi, %edx\n" /* line 3515 */
        "je .Lf14fee2_0014ff6a\n"
        "addl $1, %edx\n" /* line 3522 */
        ".Lf14fee2_0014ff5c:\n"
        "addl $1, %ebx\n" /* line 3511 */
        "addl $0xa4, %eax\n"
        "cmpl %ecx, %ebx\n"
        "jne .Lf14fee2_0014ff4c\n"
        ".Lf14fee2_0014ff68:\n"
        "xorl %ebx, %ebx\n"
        /* } scope */
        ".Lf14fee2_0014ff6a:\n"
        "movl %ebx, 4(%esp)\n" /* line 3909 | actual */
        "movl ui_currentMap, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl %ebx, 0xc(%ebp)\n" /* line 3912 | actual, index */
        "movl ui_currentNetMap, %eax\n"
        "movl %eax, 8(%ebp)\n" /* feederID */
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 3983 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp Dvar_SetInt\n" /* line 3912 */
        /* } scope */
        ".Lf14fee2_0014ff91:\n"
        "ucomiss lit4_002ed62c, %xmm0\n" /* line 3916 | 2.0f */
        "jne .Lf14fee2_00150047\n"
        "jp .Lf14fee2_00150047\n"
        "cmpl $1, sharedUiInfo+108660\n" /* line 3919 */
        "movl sharedUiInfo+28656, %eax\n"
        "cmovgel %esi, %eax\n" /* name */
        "movl %eax, sharedUiInfo+28656\n"
        "movl $0x400, 0xc(%esp)\n" /* line 3920 */
        "movl $info, 8(%esp)\n"
        "movl sharedUiInfo+28660(, %esi, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerInfo\n"
        "movl $str_002a7124, 4(%esp)\n" /* line 3923 */
        "movl $info, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa2f0, (%esp)\n" /* "levelshots/%s" */
        "calll va\n"
        "movl %eax, %esi\n" /* name */
        "movzbl (%eax), %eax\n" /* line 3926 */
        "testb %al, %al\n"
        "jne .Lf14fee2_00150077\n"
        ".Lf14fee2_00150010:\n"
        "movl $3, 4(%esp)\n" /* line 3929 */
        "movl %esi, (%esp)\n" /* name */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+108680\n"
        "movl sharedUiInfo+108684, %eax\n" /* line 3930 */
        "testl %eax, %eax\n"
        "js .Lf14fee2_00150040\n"
        "movl %eax, (%esp)\n" /* line 3932 */
        "calll CIN_StopCinematic\n"
        "movl $0xffffffff, sharedUiInfo+108684\n" /* line 3933 */
        /* } scope */
        ".Lf14fee2_00150040:\n"
        "addl $0x10, %esp\n" /* line 3983 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14fee2_00150047:\n"
        "ucomiss lit4_002ed7fc, %xmm0\n" /* line 3938 | 7.0f */
        "je .Lf14fee2_00150063\n"
        ".Lf14fee2_00150050:\n"
        "ucomiss lit4_002ed728, %xmm0\n" /* line 3955 | 9.0f */
        "jne .Lf14fee2_00150095\n"
        "jp .Lf14fee2_00150095\n"
        "movl %esi, sharedUiInfo+26488\n" /* line 3957 | name */
        "jmp .Lf14fee2_00150040\n"
        ".Lf14fee2_00150063:\n"
        "jp .Lf14fee2_00150050\n" /* line 3938 */
        ".Lf14fee2_00150065:\n"
        "movl uiInfo, %eax\n" /* line 3971 */
        "movl %esi, 0x27c(%eax)\n" /* name */
        /* } scope */
        "addl $0x10, %esp\n" /* line 3983 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14fee2_00150077:\n"
        "movl %esi, %ebx\n" /* line 3926 | name, actual */
        ".Lf14fee2_00150079:\n"
        "movsbl %al, %eax\n" /* line 3927 */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movb %al, (%ebx)\n" /* actual */
        "addl $1, %ebx\n" /* line 3926 | actual */
        "movzbl (%ebx), %eax\n" /* actual */
        "testb %al, %al\n"
        "jne .Lf14fee2_00150079\n"
        "jmp .Lf14fee2_00150010\n"
        ".Lf14fee2_00150095:\n"
        "ucomiss lit4_002ed694, %xmm0\n" /* line 3969 | 20.0f */
        "jne .Lf14fee2_001500a0\n"
        "jnp .Lf14fee2_00150065\n"
        ".Lf14fee2_001500a0:\n"
        "ucomiss lit4_002ed8b8, %xmm0\n" /* line 3976 | 24.0f */
        "jne .Lf14fee2_00150040\n"
        "jp .Lf14fee2_00150040\n"
        "testl %esi, %esi\n" /* line 3978 | name */
        "js .Lf14fee2_00150040\n"
        "movl uiInfo, %edx\n"
        "cmpl 0x280(%edx), %esi\n" /* name */
        "jge .Lf14fee2_00150040\n"
        "movl 0x388(%edx, %esi, 4), %eax\n" /* line 3979 */
        "movl 0x284(%edx, %eax, 4), %eax\n"
        "movl %eax, 0xc(%ebp)\n" /* index */
        "movl ui_playerProfileSelected, %eax\n"
        "movl %eax, 8(%ebp)\n" /* feederID */
        /* } scope */
        "addl $0x10, %esp\n" /* line 3983 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Dvar_SetString\n" /* line 3979 */
    );
}

/* line 4003 */
static __attribute__((naked))
void UI_GetGameTypesList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4003 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x104c, %esp\n"
        /* { scope 1 */
        "movl $0, sharedUiInfo+4424\n" /* line 4017 */
        "movl $0, sharedUiInfo+4684\n" /* line 4018 */
        "movl $str_002aa300, (%esp)\n" /* line 4021 */
        "calll String_Alloc\n"
        "movl %eax, sharedUiInfo+4688\n"
        "movl sharedUiInfo+4684, %eax\n" /* line 4022 */
        "movl $str_002157b8, sharedUiInfo+4692(, %eax, 8)\n"
        "addl $1, sharedUiInfo+4684\n" /* line 4023 */
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 4026 */
        "leal -0x101c(%ebp), %edi\n" /* szGameTypeList */
        "movl %edi, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002aa304, 4(%esp)\n" /* "gsc" */
        "movl $str_002aa308, (%esp)\n" /* "maps/mp/gametypes" */
        "calll FS_GetFileList\n"
        "movl %eax, -0x1030(%ebp)\n" /* iNumGameTypeScripts */
        "testl %eax, %eax\n" /* line 4034 */
        "jg .Lf1500e2_0015018a\n"
        ".Lf1500e2_00150162:\n"
        "movl sharedUiInfo+4424, %eax\n" /* line 4093 */
        "testl %eax, %eax\n"
        "jne .Lf1500e2_0015017f\n"
        "movl $str_002aa380, 4(%esp)\n" /* line 4095 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf1500e2_0015017f:\n"
        "addl $0x104c, %esp\n" /* line 4098 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1500e2_0015018a:\n"
        "movl %edi, %esi\n" /* line 4034 | pszFileName */
        "movl $0, -0x102c(%ebp)\n" /* i */
        "jmp .Lf1500e2_001501b1\n"
        ".Lf1500e2_00150198:\n"
        "leal 1(%esi, %ebx), %esi\n" /* line 4043 | pszFileName */
        ".Lf1500e2_0015019c:\n"
        "addl $1, -0x102c(%ebp)\n" /* line 4034 | i */
        "movl -0x102c(%ebp), %eax\n" /* i */
        "cmpl %eax, -0x1030(%ebp)\n" /* iNumGameTypeScripts */
        "je .Lf1500e2_00150162\n"
        ".Lf1500e2_001501b1:\n"
        "cld\n" /* line 4037 */
        "xorl %eax, %eax\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* pszFileName */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "leal -1(%ecx), %ebx\n" /* iLen */
        "cmpb $0x5f, (%esi)\n" /* line 4040 | pszFileName */
        "je .Lf1500e2_00150198\n"
        "movl $str_002aa31c, 4(%esp)\n" /* line 4048 */
        "leal (%esi, %ebx), %eax\n" /* pszFileName */
        "movl %eax, -0x1034(%ebp)\n"
        "subl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1500e2_001501ec\n"
        "movb $0, -4(%esi, %ebx)\n" /* line 4049 | pszFileName */
        ".Lf1500e2_001501ec:\n"
        "movl sharedUiInfo+4424, %ebx\n" /* line 4057 | iLen */
        "cmpl $0x20, %ebx\n" /* iLen */
        "je .Lf1500e2_001502cf\n"
        "cmpl $0x20, sharedUiInfo+4684\n"
        "je .Lf1500e2_001502cf\n"
        "movl %esi, (%esp)\n" /* line 4064 | pszFileName */
        "calll String_Alloc\n"
        "movl $sharedUiInfo+4416, %edi\n"
        "movl %eax, 0xc(%edi, %ebx, 8)\n"
        "movl sharedUiInfo+4424, %eax\n" /* line 4065 */
        "movl sharedUiInfo+4428(, %eax, 8), %edx\n"
        "movl sharedUiInfo+4684, %eax\n"
        "movl %edx, sharedUiInfo+4688(, %eax, 8)\n"
        "movl %esi, 4(%esp)\n" /* line 4068 | pszFileName */
        "movl $str_002aa364, (%esp)\n" /* "maps/mp/gametypes/%s.txt" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll GetMenuBuffer\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 4069 | pBuffParse */
        "testl %eax, %eax\n" /* line 4070 */
        "je .Lf1500e2_001502a4\n"
        "leal -0x1c(%ebp), %eax\n" /* line 4077 | pBuffParse */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl sharedUiInfo+4424, %ebx\n" /* line 4079 | iLen */
        "movl %eax, (%esp)\n"
        "calll String_Alloc\n"
        "movl %eax, 0x10(%edi, %ebx, 8)\n"
        "movl sharedUiInfo+4424, %eax\n" /* line 4080 */
        "movl sharedUiInfo+4432(, %eax, 8), %ecx\n"
        "movl sharedUiInfo+4684, %edx\n"
        "movl $sharedUiInfo+4688, %eax\n"
        "movl %ecx, 4(%eax, %edx, 8)\n"
        ".Lf1500e2_00150288:\n"
        "addl $1, sharedUiInfo+4424\n" /* line 4083 */
        "addl $1, sharedUiInfo+4684\n" /* line 4084 */
        "movl -0x1034(%ebp), %esi\n" /* line 4088 | pszFileName */
        "addl $1, %esi\n" /* pszFileName */
        "jmp .Lf1500e2_0015019c\n"
        ".Lf1500e2_001502a4:\n"
        "movl sharedUiInfo+4424, %edx\n" /* line 4072 */
        "movl sharedUiInfo+4428(, %edx, 8), %eax\n"
        "movl %eax, 0x10(%edi, %edx, 8)\n"
        "movl sharedUiInfo+4424, %eax\n" /* line 4073 */
        "movl sharedUiInfo+4432(, %eax, 8), %edx\n"
        "movl sharedUiInfo+4684, %eax\n"
        "movl %edx, sharedUiInfo+4692(, %eax, 8)\n"
        "jmp .Lf1500e2_00150288\n"
        ".Lf1500e2_001502cf:\n"
        "movl $0x1f, 4(%esp)\n" /* line 4059 */
        "movl $str_002aa324, (%esp)\n" /* "Too many game type scripts found! Only loading the first %i
" */
        "calll Com_Printf\n"
        "jmp .Lf1500e2_00150162\n"
    );
}

/* line 4101 */
__attribute__((naked))
void UI_Pause(qboolean b)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4101 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* line 4103 | b */
        "testl %edx, %edx\n"
        "je .Lf1502e8_00150316\n"
        "movl $1, 4(%esp)\n" /* line 4106 */
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "movl $8, 8(%ebp)\n" /* line 4107 | b */
        "leave\n" /* line 4116 */
        "jmp Key_SetCatcher\n" /* line 4107 */
        ".Lf1502e8_00150316:\n"
        "calll Key_GetCatcher\n" /* line 4112 */
        "andl $0xfffffff7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetCatcher\n"
        "calll Key_ClearStates\n" /* line 4113 */
        "movl $0, 4(%esp)\n" /* line 4114 */
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "leave\n" /* line 4116 */
        "retl\n"
    );
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
__attribute__((naked))
void UI_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4148 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl uiInfo, %eax\n" /* line 4154 */
        "movl $0, (%eax)\n"
        "movb $0, g_ingameMenusLoaded\n" /* line 4155 */
        "calll UI_LoadSoundAliases\n" /* line 4162 */
        "movl $0x1001, 8(%esp)\n" /* line 197 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa3b8, (%esp)\n" /* "g_allowvote" */
        "calll Dvar_RegisterBool\n"
        "movl $0x1001, 8(%esp)\n" /* line 199 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a81f4, (%esp)\n" /* "cg_brass" */
        "calll Dvar_RegisterBool\n"
        "movl $0x1001, 8(%esp)\n" /* line 200 */
        "movl $1, 4(%esp)\n"
        "movl $str_002a8200, (%esp)\n" /* "cg_marks" */
        "calll Dvar_RegisterBool\n"
        "movl $0x1001, 8(%esp)\n" /* line 202 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3c4, (%esp)\n" /* "server1" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 203 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3cc, (%esp)\n" /* "server2" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 204 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3d4, (%esp)\n" /* "server3" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 205 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3dc, (%esp)\n" /* "server4" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 206 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3e4, (%esp)\n" /* "server5" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 207 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3ec, (%esp)\n" /* "server6" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 208 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3f4, (%esp)\n" /* "server7" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 209 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa3fc, (%esp)\n" /* "server8" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 210 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa404, (%esp)\n" /* "server9" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 211 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa40c, (%esp)\n" /* "server10" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 212 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa418, (%esp)\n" /* "server11" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 213 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa424, (%esp)\n" /* "server12" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 214 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa430, (%esp)\n" /* "server13" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 215 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa43c, (%esp)\n" /* "server14" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 216 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa448, (%esp)\n" /* "server15" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 8(%esp)\n" /* line 217 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa454, (%esp)\n" /* "server16" */
        "calll Dvar_RegisterString\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 219 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa460, (%esp)\n" /* "ui_netSource" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_netSource\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 220 */
        "movl $0x3f800000, %ebx\n"
        "movl %ebx, 0xc(%esp)\n"
        "xorl %edi, %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3e800000, 4(%esp)\n"
        "movl $str_002aa470, (%esp)\n" /* "ui_smallFont" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, ui_smallFont\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 221 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3ecccccd, 4(%esp)\n"
        "movl $str_002aa480, (%esp)\n" /* "ui_bigFont" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, ui_bigFont\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 222 */
        "movl %ebx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x3f0ccccd, 4(%esp)\n"
        "movl $str_002aa48c, (%esp)\n" /* "ui_extraBigFont" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, ui_extraBigFont\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 225 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa49c, (%esp)\n" /* "ui_currentMap" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_currentMap\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 235 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $3, 4(%esp)\n"
        "movl $str_002aa4ac, (%esp)\n" /* "ui_gametype" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_gametype\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 237 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa4b8, (%esp)\n" /* "ui_joinGametype" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_joinGameType\n"
        "movl $0x1001, 8(%esp)\n" /* line 238 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa4c8, (%esp)\n" /* "ui_netGametypeName" */
        "calll Dvar_RegisterString\n"
        "movl %eax, ui_netGameTypeName\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 240 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa4dc, (%esp)\n" /* "ui_dedicated" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_dedicated\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 242 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa4ec, (%esp)\n" /* "ui_currentNetMap" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_currentNetMap\n"
        "movl $0x1001, 8(%esp)\n" /* line 244 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa500, (%esp)\n" /* "ui_browserShowFull" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, ui_browserShowFull\n"
        "movl $0x1001, 8(%esp)\n" /* line 245 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa514, (%esp)\n" /* "ui_browserShowEmpty" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, ui_browserShowEmpty\n"
        "movl $0x1001, 8(%esp)\n" /* line 246 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa528, (%esp)\n" /* "ui_browserShowPassword" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, ui_browserShowPassword\n"
        "movl $0x1001, 8(%esp)\n" /* line 247 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa540, (%esp)\n" /* "ui_browserShowNoPassword" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, ui_browserShowNoPassword\n"
        "movl $0x1001, 8(%esp)\n" /* line 248 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa55c, (%esp)\n" /* "ui_browserShowPure" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, ui_browserShowPure\n"
        "movl $0x1001, 8(%esp)\n" /* line 249 */
        "movl $0, 4(%esp)\n"
        "movl $str_002aa570, (%esp)\n" /* "ui_browserShowDedicated" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, ui_browserShowDedicated\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 250 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0xffffffff, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl $str_002aa588, (%esp)\n" /* "ui_browserMod" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_browserMod\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 252 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl $str_002aa598, (%esp)\n" /* "ui_browserFriendlyfire" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_browserFriendlyfire\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 253 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl $str_002aa5b0, (%esp)\n" /* "ui_browserKillcam" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_browserKillcam\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 260 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x1b58, 4(%esp)\n"
        "movl $str_002aa5c4, (%esp)\n" /* "ui_serverStatusTimeOut" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_serverStatusTimeOut\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 264 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa5dc, (%esp)\n" /* "ui_playerProfileCount" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_playerProfileCount\n"
        "movl $0x1040, 8(%esp)\n" /* line 265 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa5f4, (%esp)\n" /* "ui_playerProfileSelected" */
        "calll Dvar_RegisterString\n"
        "movl %eax, ui_playerProfileSelected\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 266 */
        "movl $str_002157b8, 4(%esp)\n"
        "movl $str_002aa610, (%esp)\n" /* "ui_playerProfileNameNew" */
        "calll Dvar_RegisterString\n"
        "movl %eax, ui_playerProfileNameNew\n"
        "movl imp_legacyHacksArray, %eax\n" /* line 4169 */
        "movb $0, 0x2e4(%eax)\n"
        "movl $0xffffffff, 0x3e4(%eax)\n" /* line 4170 */
        "movb $0, 0x1de(%eax)\n" /* line 4171 */
        "movl $0xffffffff, 0x2e0(%eax)\n" /* line 4172 */
        "movb $1, 0x4ed(%eax)\n" /* line 4173 */
        "movb $0, 0x3e8(%eax)\n" /* line 4174 */
        "movl $0xffffffff, 0x4e8(%eax)\n" /* line 4175 */
        "movb $0, 0x4ec(%eax)\n" /* line 4176 */
        "calll String_Init\n" /* line 4179 */
        "movl uiInfo, %eax\n" /* line 4180 */
        "movl %eax, (%esp)\n"
        "calll Menu_Setup\n"
        "movl uiInfo, %eax\n" /* line 4183 */
        "leal 0x20(%eax), %edx\n"
        "movl %edx, 8(%esp)\n"
        "leal 0x1c(%eax), %edx\n"
        "movl %edx, 4(%esp)\n"
        "addl $0x18, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_GetScreenDimensions\n"
        "movl uiInfo, %esi\n" /* line 4186 */
        "movl 0x18(%esi), %ebx\n"
        "movl 0x1c(%esi), %ecx\n"
        "movl %ebx, %eax\n"
        "shll $5, %eax\n"
        "movl %ebx, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "shll $7, %eax\n"
        "cmpl %eax, %edx\n"
        "jle .Lf15038e_00150c27\n"
        "cvtsi2ssl %ebx, %xmm1\n" /* line 4189 */
        "cvtsi2ssl %ecx, %xmm0\n"
        "mulss lit4_002ed8bc, %xmm0\n" /* -1.3333333730697632f */
        "addss %xmm0, %xmm1\n"
        "mulss lit4_002ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esi)\n"
        ".Lf15038e_00150a44:\n"
        "calll Sys_Milliseconds\n" /* line 4197 */
        "calll UI_GetGameTypesList\n" /* line 4199 */
        "movl $0x1001, 0x10(%esp)\n" /* line 4203 */
        "movl sharedUiInfo+4424, %eax\n"
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $str_002aa628, (%esp)\n" /* "ui_netGametype" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, ui_netGameType\n"
        "calll UI_LoadArenas\n" /* line 4206 */
        "movl $3, 4(%esp)\n" /* line 4217 */
        "movl $str_002aa638, (%esp)\n" /* "ui_mp/menus.txt" */
        "calll UI_LoadMenus\n"
        "movl %eax, 4(%esp)\n" /* line 4218 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_AddMenuList\n"
        "cmpb $0, g_mapname\n" /* line 4222 */
        "jne .Lf15038e_00150c2e\n"
        ".Lf15038e_00150aba:\n"
        "calll UI_AssetCache\n" /* line 4226 */
        "movl uiInfo, %eax\n" /* line 4228 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl $3, 4(%esp)\n" /* line 4231 */
        "movl $str_002aa648, (%esp)\n" /* "server_hardware_unknown" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+25940\n"
        "movl $3, 4(%esp)\n" /* line 4232 */
        "movl $str_002aa660, (%esp)\n" /* "server_hardware_linux_dedicated" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+25944\n"
        "movl $3, 4(%esp)\n" /* line 4233 */
        "movl $str_002aa680, (%esp)\n" /* "server_hardware_win_dedicated" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+25948\n"
        "movl $3, 4(%esp)\n" /* line 4234 */
        "movl $str_002aa6a0, (%esp)\n" /* "server_hardware_mac_dedicated" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+25952\n"
        "movl $3, 4(%esp)\n" /* line 4236 */
        "movl $str_002aa6c0, (%esp)\n" /* "server_hardware_win_listen" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+25960\n"
        "movl $3, 4(%esp)\n" /* line 4237 */
        "movl $str_002aa6dc, (%esp)\n" /* "server_hardware_mac_listen" */
        "calll CL_RegisterMaterialNoMip\n"
        "movl %eax, sharedUiInfo+25964\n"
        "calll LAN_LoadCachedServers\n" /* line 4247 */
        "cmpl $9, sharedUiInfo+28640\n" /* line 1522 */
        "je .Lf15038e_00150b9f\n"
        "movl $9, sharedUiInfo+28640\n" /* line 1528 */
        "movl $UI_ServersQsortCompare, 0xc(%esp)\n" /* line 1529 */
        "movl $4, 8(%esp)\n"
        "movl sharedUiInfo+108660, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $sharedUiInfo+28660, (%esp)\n"
        "calll qsort\n"
        ".Lf15038e_00150b9f:\n"
        "movl $str_002a8f04, (%esp)\n" /* line 4251 */
        "calll Dvar_GetFloat\n"
        "fstps -0x1c(%ebp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "xorl %eax, %eax\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "setb %al\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa6f8, (%esp)\n" /* "ui_mousePitch" */
        "calll Dvar_SetBoolByName\n"
        "movl $0xffffffff, sharedUiInfo+108684\n" /* line 4253 */
        "movl $0xffffffff, sharedUiInfo+27524\n" /* line 4254 */
        "movl ui_netGameType, %eax\n" /* line 4262 */
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4428(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netGameTypeName, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x1040, 8(%esp)\n" /* line 4265 */
        "movl $1, 4(%esp)\n"
        "movl $str_002aa708, (%esp)\n" /* "ui_multiplayer" */
        "calll Dvar_RegisterBool\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 4266 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15038e_00150c27:\n"
        "movl %edi, (%esi)\n" /* line 4194 */
        "jmp .Lf15038e_00150a44\n"
        ".Lf15038e_00150c2e:\n"
        "movl $g_mapname, 4(%esp)\n" /* line 4223 */
        "movl $str_002aa084, (%esp)\n" /* "maps/mp/%s.csv" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll UI_MapLoadInfo\n"
        "jmp .Lf15038e_00150aba\n"
    );
}

/* line 4274 */
__attribute__((naked))
void UI_KeyEvent_impl(int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* key */
        "movl 0xc(%ebp), %edi\n" /* down */
        /* { scope 1 */
        "movl uiInfo, %eax\n" /* line 4280 */
        "movl %eax, (%esp)\n"
        "calll Menu_Count\n"
        "testl %eax, %eax\n"
        "jle .Lf150c50_00150cd6\n"
        /* { scope 2 */
        "movl uiInfo, %eax\n" /* line 4282 */
        "movl %eax, (%esp)\n"
        "calll Menu_GetFocused\n"
        "movl %eax, %ebx\n" /* menu */
        "testl %eax, %eax\n" /* line 4284 */
        "je .Lf150c50_00150d0c\n"
        "movl $str_002a8ef0, (%esp)\n" /* line 4287 */
        "calll Dvar_GetBool\n"
        "movl $1, %edx\n" /* line 4288 */
        "testb %al, %al\n"
        "cmovel bypassKeyClear, %edx\n"
        "movl %edx, bypassKeyClear\n"
        "cmpl $0x1b, %esi\n" /* line 4295 | key */
        "je .Lf150c50_00150cde\n"
        ".Lf150c50_00150cac:\n"
        "movl %edi, 0xc(%esp)\n" /* line 4309 | down */
        "movl %esi, 8(%esp)\n" /* key */
        "movl %ebx, 4(%esp)\n" /* menu */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_HandleKey\n"
        ".Lf150c50_00150cc5:\n"
        "movl uiInfo, %eax\n" /* line 4312 */
        "movl %eax, (%esp)\n"
        "calll Menu_GetFocused\n"
        "testl %eax, %eax\n" /* line 4313 */
        "je .Lf150c50_00150d0c\n"
        /* } scope */
        /* } scope */
        ".Lf150c50_00150cd6:\n"
        "addl $0x1c, %esp\n" /* line 4332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf150c50_00150cde:\n"
        "testl %edi, %edi\n" /* line 4295 | down */
        "je .Lf150c50_00150cac\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_AnyFullScreenVisible\n"
        "testl %eax, %eax\n"
        "jne .Lf150c50_00150cac\n"
        "movl 0x24c(%ebx), %eax\n" /* menu */
        "testl %eax, %eax\n"
        "jne .Lf150c50_00150cac\n"
        "movl uiInfo, %eax\n" /* line 4305 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "jmp .Lf150c50_00150cc5\n"
        ".Lf150c50_00150d0c:\n"
        "calll Key_GetCatcher\n" /* line 4317 */
        "testb $8, %al\n"
        "je .Lf150c50_00150cd6\n"
        "calll Key_GetCatcher\n" /* line 4319 */
        "andl $0xfffffff7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetCatcher\n"
        "movl bypassKeyClear, %ecx\n" /* line 4323 */
        "testl %ecx, %ecx\n"
        "je .Lf150c50_00150d53\n"
        ".Lf150c50_00150d2f:\n"
        "movl $0, bypassKeyClear\n" /* line 4326 */
        "movl $0, 0xc(%ebp)\n" /* line 4329 | down */
        "movl $str_0021663c, 8(%ebp)\n" /* key */
        /* } scope */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 4332 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp Dvar_SetIntByName\n" /* line 4329 */
        ".Lf150c50_00150d53:\n"
        "calll Key_ClearStates\n" /* line 4324 */
        "jmp .Lf150c50_00150d2f\n"
    );
}

extern void Com_Printf(const char *fmt, ...);
void UI_KeyEvent(int key, qboolean down)
{
    if (key >= 0xc8 && key <= 0xce) {
        Com_Printf("UI_KeyEvent: key=0x%x down=%d\n", key, down);
    }
    UI_KeyEvent_impl(key, down);
}

/* line 4340 */
__attribute__((naked))
void UI_MouseEvent(int dx, int dy)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4340 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl uiInfo, %edx\n" /* line 4343 */
        "movl 8(%ebp), %eax\n" /* dx */
        "addl %eax, 0xc(%edx)\n"
        "movl uiInfo, %edx\n" /* line 4344 */
        "movl 0xc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf150d5a_00150e0d\n"
        "cmpl $0x280, %eax\n" /* line 4346 */
        "jg .Lf150d5a_00150dde\n"
        ".Lf150d5a_00150d84:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4349 | dy */
        "addl %eax, 0x10(%edx)\n"
        "movl uiInfo, %edx\n" /* line 4350 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf150d5a_00150dfe\n"
        ".Lf150d5a_00150d97:\n"
        "cmpl $0x1e0, %eax\n" /* line 4352 */
        "jg .Lf150d5a_00150dcf\n"
        ".Lf150d5a_00150d9e:\n"
        "movl %edx, (%esp)\n" /* line 4356 */
        "calll Menu_Count\n"
        "testl %eax, %eax\n"
        "jle .Lf150d5a_00150dcd\n"
        "movl uiInfo, %eax\n" /* line 4358 */
        "movl 0x10(%eax), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Display_MouseMove\n"
        ".Lf150d5a_00150dcd:\n"
        "leave\n" /* line 4361 */
        "retl\n"
        ".Lf150d5a_00150dcf:\n"
        "movl $0x1e0, 0x10(%edx)\n" /* line 4353 */
        "movl uiInfo, %edx\n"
        "jmp .Lf150d5a_00150d9e\n"
        ".Lf150d5a_00150dde:\n"
        "movl $0x280, 0xc(%edx)\n" /* line 4347 */
        "movl uiInfo, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* line 4349 | dy */
        "addl %eax, 0x10(%edx)\n"
        "movl uiInfo, %edx\n" /* line 4350 */
        "movl 0x10(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jns .Lf150d5a_00150d97\n"
        ".Lf150d5a_00150dfe:\n"
        "movl $0, 0x10(%edx)\n" /* line 4351 */
        "movl uiInfo, %edx\n"
        "jmp .Lf150d5a_00150d9e\n"
        ".Lf150d5a_00150e0d:\n"
        "movl $0, 0xc(%edx)\n" /* line 4345 */
        "movl uiInfo, %edx\n"
        "jmp .Lf150d5a_00150d84\n"
    );
}

/* line 4364 */
uiMenuCommand_t UI_GetActiveMenu(void)
{
    return *(uiMenuCommand_t *)((byte *)uiInfo + 0x49c);
}

/* line 4386 */
__attribute__((naked))
qboolean UI_SetActiveMenu(int menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4386 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* menu */
        /* { scope 1 */
        "movl uiInfo, %eax\n" /* line 4396 */
        "movl %eax, (%esp)\n"
        "calll Menu_Count\n"
        "testl %eax, %eax\n"
        "jle .Lf150e32_00150e67\n"
        "leal -9(%ebx), %eax\n" /* line 4403 | menu */
        "cmpl $1, %eax\n"
        "jbe .Lf150e32_00150e62\n"
        "movl uiInfo, %eax\n" /* line 4404 */
        "movl %ebx, 0x49c(%eax)\n" /* menu */
        ".Lf150e32_00150e62:\n"
        "cmpl $0xb, %ebx\n" /* line 4406 | menu */
        "jbe .Lf150e32_00150e71\n"
        ".Lf150e32_00150e67:\n"
        "xorl %eax, %eax\n" /* line 4634 */
        /* } scope */
        ".Lf150e32_00150e69:\n"
        "addl $0x1c, %esp\n" /* line 4643 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf150e32_00150e71:\n"
        "jmpl *.Ljt_150e32_0(, %ebx, 4)\n" /* line 4406 */
        ".Lf150e32_00150e78:\n"
        "calll Key_GetCatcher\n" /* line 4409 */
        "andl $0xfffffff7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetCatcher\n"
        "movl $0, 4(%esp)\n" /* line 4410 */
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "movl uiInfo, %eax\n" /* line 4411 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        ".Lf150e32_00150eb0:\n"
        "movl $8, (%esp)\n" /* line 4629 */
        "calll Key_SetCatcher\n"
        "movl $str_002aa750, 4(%esp)\n" /* line 4630 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        ".Lf150e32_00150ed1:\n"
        "movl $0x3e8, 4(%esp)\n" /* line 4633 */
        "movl $0x3f800000, (%esp)\n"
        "calll SND_FadeAllSounds\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        /* { scope 2 */
        ".Lf150e32_00150eef:\n"
        "movl uiInfo, %eax\n" /* line 4474 */
        "movl %eax, (%esp)\n"
        "calll Menu_GetFocused\n"
        "movl %eax, %edx\n" /* pFocus */
        "testl %eax, %eax\n" /* line 4477 */
        "je .Lf150e32_00150f1b\n"
        "movl uiInfo, %eax\n"
        "movl 0x49c(%eax), %eax\n"
        "cmpl $9, %eax\n"
        "je .Lf150e32_00150f1b\n"
        "cmpl $0xa, %eax\n"
        "jne .Lf150e32_00150e67\n"
        ".Lf150e32_00150f1b:\n"
        "movl imp_legacyHacks, %esi\n" /* line 4481 */
        "movl (%esi), %edi\n" /* buf */
        "addl $0x2e4, %edi\n" /* buf */
        "testl %edx, %edx\n" /* line 4482 */
        "je .Lf150e32_00150f47\n"
        "movl %edi, 4(%esp)\n" /* buf */
        "movl 0xc0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf150e32_001510e6\n"
        ".Lf150e32_00150f47:\n"
        "movl uiInfo, %eax\n" /* line 4485 */
        "movl $9, 0x49c(%eax)\n"
        "cmpl $0xa, %ebx\n" /* line 4487 | menu */
        "je .Lf150e32_00151177\n"
        ".Lf150e32_00150f5f:\n"
        "movl $8, (%esp)\n" /* line 4498 */
        "calll Key_SetCatcher\n"
        "movl uiInfo, %eax\n" /* line 4499 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl %edi, 4(%esp)\n" /* line 4502 | buf */
        "movl (%esi), %eax\n"
        "addl $0x1de, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl (%esi), %edx\n" /* line 4503 */
        "movl 0x3e4(%edx), %eax\n"
        "movl %eax, 0x2e0(%edx)\n"
        "movl (%esi), %eax\n" /* line 4504 */
        "movb $0, 0x2e4(%eax)\n"
        "movl (%esi), %eax\n" /* line 4505 */
        "movl $0xffffffff, 0x3e4(%eax)\n"
        "movl (%esi), %eax\n" /* line 4507 */
        "addl $0x1de, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        /* } scope */
        ".Lf150e32_00150fd0:\n"
        "movl uiInfo, %eax\n" /* line 4456 */
        "movl $0x27f, 0xc(%eax)\n"
        "movl uiInfo, %eax\n" /* line 4457 */
        "movl $0x1df, 0x10(%eax)\n"
        "movl $8, (%esp)\n" /* line 4458 */
        "calll Key_SetCatcher\n"
        "movl imp_cl, %eax\n" /* line 4459 */
        "movl (%eax), %eax\n"
        "movb $1, 8(%eax)\n"
        "movl uiInfo, %eax\n" /* line 4460 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl $str_002aa740, 4(%esp)\n" /* line 4461 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        ".Lf150e32_0015102b:\n"
        "movl $8, (%esp)\n" /* line 4431 */
        "calll Key_SetCatcher\n"
        "movl $str_002aa728, 4(%esp)\n" /* line 4432 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        ".Lf150e32_00151056:\n"
        "movl $8, (%esp)\n" /* line 4442 */
        "calll Key_SetCatcher\n"
        "movl $str_002aa738, 4(%esp)\n" /* line 4443 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        ".Lf150e32_00151081:\n"
        "movl $8, (%esp)\n" /* line 4437 */
        "calll Key_SetCatcher\n"
        "movl $str_002aa730, 4(%esp)\n" /* line 4438 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        ".Lf150e32_001510ac:\n"
        "movl $8, (%esp)\n" /* line 4448 */
        "calll Key_SetCatcher\n"
        "movl uiInfo, %eax\n" /* line 4449 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        "movl imp_cg, %eax\n" /* line 4450 */
        "movl (%eax), %eax\n"
        "addl $0x2adfc, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "testl %eax, %eax\n"
        "je .Lf150e32_00151158\n"
        ".Lf150e32_001510e6:\n"
        "movl $1, %eax\n" /* line 4634 */
        "jmp .Lf150e32_00150e69\n"
        ".Lf150e32_001510f0:\n"
        "movl $8, (%esp)\n" /* line 4415 */
        "calll Key_SetCatcher\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 4416 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $str_0021605c, (%esp)\n" /* line 4417 */
        "calll Dvar_GetString\n"
        "cmpb $0, (%eax)\n" /* line 4419 */
        "je .Lf150e32_00150ed1\n"
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf150e32_00150ed1\n"
        "movl $str_002aa718, 4(%esp)\n" /* line 4420 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "jmp .Lf150e32_00150ed1\n"
        ".Lf150e32_00151158:\n"
        "movl $str_00216f3c, 4(%esp)\n" /* line 4451 */
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menus_OpenByName\n"
        "movl $1, %eax\n"
        "jmp .Lf150e32_00150e69\n"
        /* { scope 2 */
        ".Lf150e32_00151177:\n"
        "movl uiInfo, %eax\n" /* line 4490 */
        "movl $0x27f, 0xc(%eax)\n"
        "movl uiInfo, %eax\n" /* line 4491 */
        "movl $0x1df, 0x10(%eax)\n"
        "jmp .Lf150e32_00150f5f\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_150e32_0:\n"
        ".long .Lf150e32_00150e78\n"
        ".long .Lf150e32_001510f0\n"
        ".long .Lf150e32_001510ac\n"
        ".long .Lf150e32_00151081\n"
        ".long .Lf150e32_00151056\n"
        ".long .Lf150e32_0015102b\n"
        ".long .Lf150e32_00150e67\n"
        ".long .Lf150e32_00150e67\n"
        ".long .Lf150e32_00150fd0\n"
        ".long .Lf150e32_00150eef\n"
        ".long .Lf150e32_00150eef\n"
        ".long .Lf150e32_00150eb0\n"
        ".text\n"
    );
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
__attribute__((naked))
const char * UI_ReplaceConversions(const char *sourceString, ConversionArguments *arguments)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5232 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x42c, %esp\n"
        /* { scope 1 */
        "movl $str_00216c3c, 4(%esp)\n" /* line 5244 */
        "movl 8(%ebp), %eax\n" /* sourceString */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lf151340_001514f6\n"
        "cld\n" /* line 5250 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* sourceString */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x428(%ebp)\n" /* sourceStringLength */
        "movl $0x400, 8(%esp)\n" /* line 5254 */
        "movl $0, 4(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* outputString */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl -0x428(%ebp), %eax\n" /* line 5258 | sourceStringLength */
        "testl %eax, %eax\n"
        "jg .Lf151340_001513c3\n"
        ".Lf151340_001513a7:\n"
        "leal -0x418(%ebp), %ecx\n" /* line 5289 | outputString */
        "movl %ecx, (%esp)\n"
        "calll va\n"
        "movl %eax, 8(%ebp)\n" /* sourceString */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 5290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf151340_001513c3:\n"
        "movl $0, -0x420(%ebp)\n" /* line 5258 | outputStringCounter */
        "movl $0, -0x424(%ebp)\n" /* index */
        "movl 8(%ebp), %ebx\n" /* line 5260 | sourceString, argStringIndex */
        "addl -0x424(%ebp), %ebx\n" /* index, argStringIndex */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* argStringIndex */
        "movl $str_00216c3c, %edi\n" /* "&&" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf151340_00151400\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf151340_00151400:\n"
        "testl %eax, %eax\n"
        "jne .Lf151340_001514d4\n"
        ".Lf151340_00151408:\n"
        "movl 8(%ebp), %ecx\n" /* sourceString */
        "movl -0x424(%ebp), %edi\n" /* index */
        "movsbl 2(%ecx, %edi), %edx\n" /* _c */
        /* { scope 2 */
        "cmpl $0xff, %edx\n" /* line 231 */
        "ja .Lf151340_001514d4\n"
        "movl __DefaultRuneLocale, %eax\n"
        "testb $4, 0x35(%eax, %edx, 4)\n"
        "je .Lf151340_001514d4\n"
        /* } scope */
        "subl $0x31, %edx\n" /* line 5264 */
        "movl %edx, -0x41c(%ebp)\n" /* argIndex */
        "movl 0xc(%ebp), %eax\n" /* line 5272 | arguments */
        "movl 4(%eax, %edx, 4), %esi\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "testl %ecx, %ecx\n" /* line 5273 */
        "jle .Lf151340_0015148a\n"
        "leal -0x418(%ebp), %edx\n" /* outputString */
        "addl -0x420(%ebp), %edx\n" /* outputStringCounter */
        "xorl %ebx, %ebx\n" /* argStringIndex */
        "jmp .Lf151340_00151473\n"
        ".Lf151340_00151466:\n"
        "movl -0x41c(%ebp), %edi\n" /* argIndex */
        "movl 0xc(%ebp), %eax\n" /* arguments */
        "movl 4(%eax, %edi, 4), %esi\n"
        ".Lf151340_00151473:\n"
        "movzbl (%ebx, %esi), %eax\n" /* line 5275 | argStringIndex */
        "movb %al, (%edx)\n"
        "addl $1, -0x420(%ebp)\n" /* line 5276 | outputStringCounter */
        "addl $1, %ebx\n" /* line 5273 | argStringIndex */
        "addl $1, %edx\n"
        "cmpl %ebx, %ecx\n" /* argStringIndex */
        "jne .Lf151340_00151466\n"
        ".Lf151340_0015148a:\n"
        "addl $3, -0x424(%ebp)\n" /* line 5279 | index */
        ".Lf151340_00151491:\n"
        "movl -0x424(%ebp), %edx\n" /* line 5258 | index */
        "cmpl %edx, -0x428(%ebp)\n" /* sourceStringLength */
        "jle .Lf151340_001513a7\n"
        "movl 8(%ebp), %ebx\n" /* line 5260 | sourceString, argStringIndex */
        "addl -0x424(%ebp), %ebx\n" /* index, argStringIndex */
        "movl $2, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* argStringIndex */
        "movl $str_00216c3c, %edi\n" /* "&&" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf151340_001514cc\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf151340_001514cc:\n"
        "testl %eax, %eax\n"
        "je .Lf151340_00151408\n"
        ".Lf151340_001514d4:\n"
        "movzbl (%ebx), %eax\n" /* line 5283 | argStringIndex */
        "movl -0x420(%ebp), %edi\n" /* outputStringCounter */
        "movb %al, -0x418(%ebp, %edi)\n"
        "addl $1, %edi\n" /* line 5284 */
        "movl %edi, -0x420(%ebp)\n" /* outputStringCounter */
        "addl $1, -0x424(%ebp)\n" /* line 5285 | index */
        "jmp .Lf151340_00151491\n"
        ".Lf151340_001514f6:\n"
        "movl 8(%ebp), %eax\n" /* sourceString */
        /* } scope */
        "addl $0x42c, %esp\n" /* line 5290 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5202 */
__attribute__((naked))
const char * UI_ReplaceConversionString(const char *sourceString, const char *replaceString)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5202 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "subl $0x44, %esp\n"
        /* { scope 1 */
        "leal -0x30(%ebp), %edx\n" /* line 5206 | convArgs */
        "cld\n"
        "movl $0xa, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl $1, -0x30(%ebp)\n" /* line 5207 | convArgs */
        "movl 0xc(%ebp), %eax\n" /* line 5208 | replaceString */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %edx, 4(%esp)\n" /* line 5209 */
        "movl 8(%ebp), %eax\n" /* sourceString */
        "movl %eax, (%esp)\n"
        "calll UI_ReplaceConversions\n"
        /* } scope */
        "addl $0x44, %esp\n" /* line 5210 */
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5293 */
void UI_CloseAll(void)
{
    Menus_CloseAll(uiInfo);
}

/* line 5299 */
__attribute__((naked))
void UI_CloseFocusedMenu(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5299 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl uiInfo, %eax\n" /* line 5303 */
        "movl %eax, (%esp)\n"
        "calll Menu_Count\n"
        "testl %eax, %eax\n"
        "jle .Lf151552_0015158b\n"
        "movl uiInfo, %eax\n" /* line 5305 */
        "movl %eax, (%esp)\n"
        "calll Menu_GetFocused\n"
        "testl %eax, %eax\n" /* line 5306 */
        "je .Lf151552_0015159c\n"
        "movl uiInfo, %eax\n" /* line 5314 */
        "movl %eax, (%esp)\n"
        "calll Menus_AnyFullScreenVisible\n"
        "testl %eax, %eax\n"
        "je .Lf151552_0015158d\n"
        /* } scope */
        ".Lf151552_0015158b:\n"
        "leave\n" /* line 5319 */
        "retl\n"
        /* { scope 1 */
        ".Lf151552_0015158d:\n"
        "movl uiInfo, %eax\n" /* line 5317 */
        "movl %eax, (%esp)\n"
        "calll Menus_CloseAll\n"
        /* } scope */
        "leave\n" /* line 5319 */
        "retl\n"
        /* { scope 1 */
        ".Lf151552_0015159c:\n"
        "calll Key_GetCatcher\n" /* line 5308 */
        "testb $8, %al\n"
        "je .Lf151552_0015158b\n"
        "calll Key_GetCatcher\n" /* line 5309 */
        "andl $0xfffffff7, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetCatcher\n"
        /* } scope */
        "leave\n" /* line 5319 */
        "retl\n"
    );
}

/* line 3812 */
__attribute__((naked))
void UI_OverrideCursorPos(rectDef_t (*item)[16])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3812 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* item */
        "movss 0x2d8(%edi), %xmm0\n" /* line 3815 | item */
        "ucomiss lit4_002ed608, %xmm0\n" /* 4.0f */
        "jne .Lf1515b8_00151625\n"
        "jp .Lf1515b8_00151625\n"
        /* { scope 1 */
        "movl ui_currentNetMap, %eax\n" /* line 3819 */
        "movl 8(%eax), %esi\n" /* testMapIndex */
        /* { scope 2 */
        /* { scope 3 */
        "movl sharedUiInfo+4944, %ebx\n" /* line 3536 */
        "testl %ebx, %ebx\n"
        "jle .Lf1515b8_0015160f\n"
        "xorl %ecx, %ecx\n"
        "xorl %eax, %eax\n"
        "movl $sharedUiInfo, %edx\n"
        ".Lf1515b8_001515f2:\n"
        "cmpl $0, 0x13f4(%edx)\n" /* line 3538 */
        "je .Lf1515b8_00151602\n"
        "cmpl %esi, %eax\n" /* line 3540 */
        "je .Lf1515b8_00151611\n"
        "addl $1, %ecx\n" /* line 3546 */
        ".Lf1515b8_00151602:\n"
        "addl $1, %eax\n" /* line 3536 */
        "addl $0xa4, %edx\n"
        "cmpl %eax, %ebx\n"
        "jne .Lf1515b8_001515f2\n"
        ".Lf1515b8_0015160f:\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf1515b8_00151611:\n"
        "movl %ecx, 4(%esp)\n" /* line 3821 */
        "movl %edi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        /* } scope */
        ".Lf1515b8_0015161d:\n"
        "addl $0x1c, %esp\n" /* line 3881 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1515b8_00151625:\n"
        "ucomiss lit4_002ed62c, %xmm0\n" /* line 3840 | 2.0f */
        "jne .Lf1515b8_0015161d\n"
        "jp .Lf1515b8_0015161d\n"
        /* { scope 1 */
        "movl 0x2ec(%edi), %esi\n" /* line 3846 | item, listPtr */
        "movl 0x10(%esi), %eax\n" /* line 3848 | listPtr */
        "testl %eax, %eax\n"
        "je .Lf1515b8_001516ca\n"
        "movl sharedUiInfo+28656, %edx\n" /* line 3863 */
        "testl %edx, %edx\n"
        "js .Lf1515b8_0015161d\n"
        "movl 0x2dc(%edi), %eax\n" /* line 3866 | item */
        "cmpl (%esi), %eax\n" /* listPtr */
        "jl .Lf1515b8_0015161d\n"
        "cmpl 0x10(%esi), %eax\n" /* listPtr */
        "jg .Lf1515b8_0015161d\n"
        "movl %edx, %ebx\n" /* line 3869 | delta */
        "subl %eax, %ebx\n" /* delta */
        "movl %ebx, %eax\n" /* line 3870 | delta */
        "addl (%esi), %eax\n" /* listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl %ebx, %eax\n" /* line 3871 | delta */
        "addl 0x10(%esi), %eax\n" /* listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetEndPos\n"
        "addl 0x24(%esi), %ebx\n" /* line 3872 | listPtr, delta */
        "movl %ebx, 4(%esp)\n" /* delta */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 3873 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "movl %edi, (%esp)\n" /* line 3875 | item */
        "calll Item_ListBox_MaxScroll\n"
        "cmpl (%esi), %eax\n" /* line 3876 | listPtr */
        "jl .Lf1515b8_001516e2\n"
        ".Lf1515b8_001516ab:\n"
        "movl (%esi), %eax\n" /* line 3878 | listPtr */
        "testl %eax, %eax\n"
        "jns .Lf1515b8_0015161d\n"
        "movl $0, 4(%esp)\n" /* line 3879 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf1515b8_0015161d\n"
        ".Lf1515b8_001516ca:\n"
        "movl $0xffffffff, 4(%esp)\n" /* line 3850 */
        "movl %edi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 3881 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1515b8_001516e2:\n"
        "movl %eax, 4(%esp)\n" /* line 3877 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf1515b8_001516ab\n"
    );
}

/* line 1030 */
__attribute__((naked))
Bool UI_DrawRecordLevel(rectDef_t *rect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1030 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* rect */
        /* { scope 1 */
        "calll Voice_GetVoiceLevel\n" /* line 1036 */
        "fstps -0xc(%ebp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "pxor %xmm2, %xmm2\n" /* line 1037 */
        "ucomiss %xmm2, %xmm0\n"
        "jbe .Lf1516f0_0015177d\n"
        "movaps %xmm0, %xmm1\n" /* line 1039 */
        "mulss 8(%esi), %xmm1\n" /* rect */
        "movss lit4_002ed608, %xmm3\n" /* 4.0f */
        "subss %xmm3, %xmm1\n"
        "ucomiss %xmm2, %xmm1\n" /* line 1041 */
        "jbe .Lf1516f0_0015177d\n"
        "movl imp_colorWhite, %eax\n" /* line 1042 */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss 0xc(%esi), %xmm0\n" /* rect */
        "subss %xmm3, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss 4(%esi), %xmm1\n" /* rect */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "addss (%esi), %xmm0\n" /* rect */
        "movss %xmm0, (%esp)\n"
        "calll UI_FillRect\n"
        ".Lf1516f0_0015177d:\n"
        "movl imp_colorWhite, %ebx\n" /* line 1046 */
        "movl %ebx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl 8(%esi), %eax\n" /* rect */
        "movl %eax, 8(%esp)\n"
        "movl 4(%esi), %eax\n" /* rect */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_FillRect\n"
        "movl %ebx, 0x18(%esp)\n" /* line 1047 */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x3f800000, 0xc(%esp)\n"
        "movl 8(%esi), %eax\n" /* rect */
        "movl %eax, 8(%esp)\n"
        "movss 4(%esi), %xmm0\n" /* rect */
        "addss 0xc(%esi), %xmm0\n" /* rect */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 4(%esp)\n"
        "movl (%esi), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_FillRect\n"
        "movl %ebx, 0x18(%esp)\n" /* line 1048 */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss 0xc(%esi), %xmm0\n" /* rect */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movss 4(%esi), %xmm0\n" /* rect */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 4(%esp)\n"
        "movl (%esi), %eax\n" /* rect */
        "movl %eax, (%esp)\n"
        "calll UI_FillRect\n"
        "movl %ebx, 0x18(%esp)\n" /* line 1049 */
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movss 0xc(%esi), %xmm0\n" /* rect */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x3f800000, 8(%esp)\n"
        "movss 4(%esi), %xmm0\n" /* rect */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 4(%esp)\n"
        "movss (%esi), %xmm0\n" /* rect */
        "addss 8(%esi), %xmm0\n" /* rect */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, (%esp)\n"
        "calll UI_FillRect\n"
        /* } scope */
        "movl $1, %eax\n" /* line 1051 */
        "addl $0x30, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3786 */
__attribute__((naked))
MaterialHandle UI_FeederItemImage(const float feederID, int index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3786 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* line 3789 | feederID */
        "ucomiss lit4_002ed608, %xmm0\n" /* 4.0f */
        "je .Lf1518b2_001518cf\n"
        /* { scope 1 */
        ".Lf1518b2_001518c7:\n"
        "xorl %eax, %eax\n" /* line 3801 */
        /* } scope */
        ".Lf1518b2_001518c9:\n"
        "addl $0x14, %esp\n" /* line 3807 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1518b2_001518cf:\n"
        "jp .Lf1518b2_001518c7\n" /* line 3789 */
        /* { scope 1 */
        /* { scope 2 */
        "movl sharedUiInfo+4944, %ecx\n" /* line 3511 */
        "testl %ecx, %ecx\n"
        "jle .Lf1518b2_00151901\n"
        /* } scope */
        /* } scope */
        "xorl %ebx, %ebx\n" /* line 3789 | c */
        "xorl %edx, %edx\n"
        "movl $sharedUiInfo, %eax\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1518b2_001518e4:\n"
        "cmpl $0, 0x13f4(%eax)\n" /* line 3513 */
        "je .Lf1518b2_001518f5\n"
        "cmpl 0xc(%ebp), %ebx\n" /* line 3515 | index, c */
        "je .Lf1518b2_00151926\n"
        "addl $1, %ebx\n" /* line 3522 | c */
        ".Lf1518b2_001518f5:\n"
        "addl $1, %edx\n" /* line 3511 */
        "addl $0xa4, %eax\n"
        "cmpl %edx, %ecx\n"
        "jne .Lf1518b2_001518e4\n"
        /* } scope */
        ".Lf1518b2_00151901:\n"
        "xorl %edx, %edx\n" /* line 3795 */
        ".Lf1518b2_00151903:\n"
        "cmpl %edx, %ecx\n"
        "jle .Lf1518b2_001518c7\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 3797 */
        "leal (%edx, %eax, 8), %eax\n"
        "leal (, %eax, 4), %ebx\n" /* c */
        "movl sharedUiInfo+5104(%ebx), %eax\n" /* c */
        "testl %eax, %eax\n"
        "je .Lf1518b2_0015192c\n"
        ".Lf1518b2_0015191e:\n"
        "movl sharedUiInfo+5104(%ebx), %eax\n" /* line 3801 | c */
        "jmp .Lf1518b2_001518c9\n"
        ".Lf1518b2_00151926:\n"
        "testl %edx, %edx\n" /* line 3795 */
        "js .Lf1518b2_001518c7\n"
        "jmp .Lf1518b2_00151903\n"
        ".Lf1518b2_0015192c:\n"
        "movl $3, 4(%esp)\n" /* line 3799 */
        "movl sharedUiInfo+4956(%ebx), %eax\n" /* c */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl $sharedUiInfo+5088, %edx\n"
        "movl %eax, 0x10(%ebx, %edx)\n" /* c */
        "jmp .Lf1518b2_0015191e\n"
    );
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

/* line 2836 */
static __attribute__((naked))
void UI_BuildServerDisplayList(qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2836 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* force */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 2846 | clients */
        "jne .Lf151d58_00151e72\n"
        "movl uiInfo, %eax\n"
        "movl 4(%eax), %eax\n"
        "cmpl sharedUiInfo+108672, %eax\n"
        "jle .Lf151d58_00151e67\n"
        ".Lf151d58_00151d83:\n"
        "xorl %ebx, %ebx\n" /* line 2850 | clients */
        ".Lf151d58_00151d85:\n"
        "movl $str_002a8f60, (%esp)\n" /* line 2854 */
        "calll Dvar_GetString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $sharedUiInfo+108712, (%esp)\n"
        "calll I_strncpyz\n"
        "xorl %esi, %esi\n" /* line 2855 | i */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl $sharedUiInfo+108712, %edi\n" /* len */
        "movl %esi, %eax\n" /* i */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "movl %ecx, %eax\n" /* line 2856 */
        "subl $1, %eax\n"
        "je .Lf151d58_00151ec7\n"
        ".Lf151d58_00151dc7:\n"
        "cmpl sharedUiInfo+108688, %eax\n" /* line 2861 */
        "je .Lf151d58_00151dde\n"
        "movl %eax, sharedUiInfo+108688\n" /* line 2863 */
        "movl $0xffffffff, sharedUiInfo+108692\n" /* line 2864 */
        ".Lf151d58_00151dde:\n"
        "testl %ebx, %ebx\n" /* line 2867 | clients */
        "jne .Lf151d58_00151f14\n"
        ".Lf151d58_00151de6:\n"
        "movl ui_netSource, %eax\n" /* line 2879 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "movl %eax, -0x428(%ebp)\n" /* count */
        "movl ui_netSource, %eax\n" /* line 2880 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_WaitServerResponse\n"
        "testl %eax, %eax\n"
        "jne .Lf151d58_00151e80\n"
        "movl ui_netSource, %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf151d58_00151e27\n"
        "movl -0x428(%ebp), %eax\n" /* count */
        "testl %eax, %eax\n"
        "je .Lf151d58_00151e86\n"
        ".Lf151d58_00151e27:\n"
        "movl $UI_ServersQsortCompare, 0xc(%esp)\n" /* line 1529 */
        "movl $4, 8(%esp)\n"
        "movl sharedUiInfo+108660, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $sharedUiInfo+28660, (%esp)\n"
        "calll qsort\n"
        "movl -0x428(%ebp), %ecx\n" /* line 2894 | count */
        "testl %ecx, %ecx\n"
        "jg .Lf151d58_00151fa2\n"
        ".Lf151d58_00151e5a:\n"
        "movl uiInfo, %eax\n" /* line 3037 */
        "movl 4(%eax), %eax\n"
        "movl %eax, sharedUiInfo+28632\n"
        /* } scope */
        ".Lf151d58_00151e67:\n"
        "addl $0x43c, %esp\n" /* line 3038 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf151d58_00151e72:\n"
        "cmpl $2, %ebx\n" /* line 2850 | clients */
        "jne .Lf151d58_00151d85\n"
        "jmp .Lf151d58_00151d83\n"
        ".Lf151d58_00151e80:\n"
        "movl ui_netSource, %edx\n"
        ".Lf151d58_00151e86:\n"
        "movl $0, sharedUiInfo+108660\n" /* line 2825 */
        "movl $0, sharedUiInfo+108668\n" /* line 2826 */
        "movl 8(%edx), %eax\n" /* line 2827 */
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "movl %eax, sharedUiInfo+108664\n"
        "movl uiInfo, %eax\n" /* line 2884 */
        "movl 4(%eax), %eax\n"
        "addl $0x1f4, %eax\n"
        "movl %eax, sharedUiInfo+108672\n"
        /* } scope */
        "addl $0x43c, %esp\n" /* line 3038 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf151d58_00151ec7:\n"
        "movl $str_002aa83c, (%esp)\n" /* line 2858 */
        "calll UI_SafeTranslateString\n"
        "movl $str_002167d8, 8(%esp)\n" /* "1.0" */
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa850, (%esp)\n" /* "%s - %s" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $sharedUiInfo+108712, (%esp)\n"
        "calll strcpy\n"
        "cld\n" /* line 2859 */
        "movl $0xffffffff, %ecx\n"
        "movl $sharedUiInfo+108712, %edi\n" /* len */
        "movl %esi, %eax\n" /* i */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %eax\n"
        "jmp .Lf151d58_00151dc7\n"
        ".Lf151d58_00151f14:\n"
        "movl $0, numclean\n" /* line 2869 */
        "movl $0, sharedUiInfo+108660\n" /* line 2825 */
        "movl $0, sharedUiInfo+108668\n" /* line 2826 */
        "movl ui_netSource, %eax\n" /* line 2827 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "movl %eax, sharedUiInfo+108664\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2872 */
        "testl %eax, %eax\n"
        "js .Lf151d58_00151f7d\n"
        "movl $0, 0x10(%esp)\n" /* line 2873 */
        "movl $0, 0xc(%esp)\n"
        "movl $2, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        ".Lf151d58_00151f7d:\n"
        "movl $1, 8(%esp)\n" /* line 2875 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_MarkServerDirty\n"
        "jmp .Lf151d58_00151de6\n"
        ".Lf151d58_00151fa2:\n"
        "xorl %esi, %esi\n" /* line 2885 | i */
        "jmp .Lf151d58_00151fb5\n"
        ".Lf151d58_00151fa6:\n"
        "addl $1, %esi\n" /* line 2894 | i */
        "cmpl %esi, -0x428(%ebp)\n" /* i, count */
        "je .Lf151d58_00151e5a\n"
        ".Lf151d58_00151fb5:\n"
        "movl %esi, 4(%esp)\n" /* line 2897 | i */
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_ServerIsDirty\n"
        "testl %eax, %eax\n"
        "je .Lf151d58_00151fa6\n"
        "movl %esi, 4(%esp)\n" /* line 2902 | i */
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerPing\n"
        "movl %eax, -0x424(%ebp)\n" /* ping */
        "testl %eax, %eax\n" /* line 2903 */
        "jle .Lf151d58_0015227d\n"
        "movl ui_netSource, %edx\n"
        ".Lf151d58_00151ff5:\n"
        "movl $0x400, 0xc(%esp)\n" /* line 2905 */
        "leal -0x418(%ebp), %ecx\n" /* info */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* i */
        "movl 8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerInfo\n"
        "movl $str_002a8a54, 4(%esp)\n" /* line 2907 */
        "leal -0x418(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl %eax, %ebx\n" /* clients */
        "addl %eax, sharedUiInfo+108668\n" /* line 2908 */
        "movl $str_002aa858, 4(%esp)\n" /* line 2911 */
        "leal -0x418(%ebp), %edx\n" /* info */
        "movl %edx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0xf, 8(%esp)\n"
        "movl $str_002aa860, 4(%esp)\n" /* "000.000.000.000" */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "testl %eax, %eax\n"
        "je .Lf151d58_00152105\n"
        "movl ui_browserShowEmpty, %eax\n" /* line 2918 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf151d58_00152085\n"
        "testl %ebx, %ebx\n" /* line 2920 | clients */
        "je .Lf151d58_00152105\n"
        ".Lf151d58_00152085:\n"
        "movl ui_browserShowFull, %eax\n" /* line 2927 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf151d58_00152292\n"
        ".Lf151d58_00152094:\n"
        "movl ui_browserShowPassword, %eax\n" /* line 2937 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf151d58_001522bd\n"
        ".Lf151d58_001520a3:\n"
        "movl ui_browserShowNoPassword, %eax\n" /* line 2946 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf151d58_001522e8\n"
        ".Lf151d58_001520b2:\n"
        "movl ui_browserShowPure, %eax\n" /* line 2955 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf151d58_00152313\n"
        ".Lf151d58_001520c1:\n"
        "movl ui_browserShowDedicated, %eax\n" /* line 2964 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf151d58_0015233e\n"
        ".Lf151d58_001520d0:\n"
        "movl ui_browserMod, %eax\n" /* line 2974 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf151d58_00152126\n"
        "movl $str_002a9cf4, 4(%esp)\n" /* line 2976 */
        "leal -0x418(%ebp), %edx\n" /* info */
        "movl %edx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl ui_browserMod, %edx\n"
        "cmpl 8(%edx), %eax\n"
        "je .Lf151d58_00152126\n"
        ".Lf151d58_00152105:\n"
        "movl $0, 8(%esp)\n" /* line 3014 */
        "movl %esi, 4(%esp)\n" /* i */
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_MarkServerDirty\n"
        "jmp .Lf151d58_00151fa6\n"
        ".Lf151d58_00152126:\n"
        "movl ui_browserFriendlyfire, %eax\n" /* line 2983 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf151d58_0015215b\n"
        "movl $str_002aa87c, 4(%esp)\n" /* line 2985 */
        "leal -0x418(%ebp), %ecx\n" /* info */
        "movl %ecx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl ui_browserFriendlyfire, %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jne .Lf151d58_00152105\n"
        ".Lf151d58_0015215b:\n"
        "movl ui_browserKillcam, %eax\n" /* line 2992 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "js .Lf151d58_00152194\n"
        "movl $str_002aa880, 4(%esp)\n" /* line 2994 */
        "leal -0x418(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "movl ui_browserKillcam, %edx\n"
        "cmpl 8(%edx), %eax\n"
        "jne .Lf151d58_00152105\n"
        ".Lf151d58_00152194:\n"
        "movl ui_joinGameType, %eax\n" /* line 3001 */
        "movl 8(%eax), %edx\n"
        "movl sharedUiInfo+4692(, %edx, 8), %eax\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf151d58_0015242e\n"
        ".Lf151d58_001521ac:\n"
        "movl ui_serverFilterType, %eax\n" /* line 3010 */
        "testl %eax, %eax\n"
        "jle .Lf151d58_001521e6\n"
        "movl serverFilters+4(, %eax, 8), %ebx\n" /* line 3012 | clients */
        "movl $str_002aa890, 4(%esp)\n" /* "game" */
        "leal -0x418(%ebp), %ecx\n" /* info */
        "movl %ecx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %ebx, 4(%esp)\n" /* clients */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf151d58_00152105\n"
        ".Lf151d58_001521e6:\n"
        "movl ui_netSource, %edx\n" /* line 3022 */
        "cmpl $2, 8(%edx)\n"
        "je .Lf151d58_00152473\n"
        ".Lf151d58_001521f6:\n"
        "movl sharedUiInfo+108660, %ebx\n" /* clients */
        /* { scope 2: position */
        ".Lf151d58_001521fc:\n"
        "movl %ebx, %edi\n" /* line 2780 | j, len */
        "testl %ebx, %ebx\n" /* line 2784 | j */
        "jle .Lf151d58_00152464\n"
        "movl $0, -0x420(%ebp)\n" /* position */
        "jmp .Lf151d58_0015222e\n"
        ".Lf151d58_00152212:\n"
        "subl %ebx, %edi\n" /* line 2802 | j, len */
        "movl -0x41c(%ebp), %ecx\n"
        "movl %ecx, -0x420(%ebp)\n" /* position */
        ".Lf151d58_00152220:\n"
        "testl %ebx, %ebx\n" /* line 2784 | j */
        "jle .Lf151d58_0015236d\n"
        "movl ui_netSource, %edx\n"
        ".Lf151d58_0015222e:\n"
        "movl %edi, %ebx\n" /* line 2786 | len, j */
        "sarl $1, %ebx\n" /* j */
        "movl -0x420(%ebp), %eax\n" /* line 2788 | position */
        "addl %ebx, %eax\n" /* j */
        "movl %eax, -0x41c(%ebp)\n"
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl sharedUiInfo+28644, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl sharedUiInfo+28640, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_CompareServers\n"
        "movl %eax, %edx\n"
        "cmpl $0, %eax\n" /* line 2793 */
        "je .Lf151d58_001524ec\n"
        "jg .Lf151d58_00152212\n" /* line 2799 */
        "subl %ebx, %edi\n" /* line 2807 | j, len */
        "jmp .Lf151d58_00152220\n"
        /* } scope */
        ".Lf151d58_0015227d:\n"
        "movl ui_netSource, %edx\n" /* line 2903 */
        "cmpl $2, 8(%edx)\n"
        "jne .Lf151d58_00151fa6\n"
        "jmp .Lf151d58_00151ff5\n"
        ".Lf151d58_00152292:\n"
        "movl $str_002a70dc, 4(%esp)\n" /* line 2929 */
        "leal -0x418(%ebp), %ecx\n" /* info */
        "movl %ecx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "cmpl %eax, %ebx\n" /* line 2930 | clients */
        "jne .Lf151d58_00152094\n"
        "jmp .Lf151d58_00152105\n"
        ".Lf151d58_001522bd:\n"
        "movl $str_002a9af0, 4(%esp)\n" /* line 2939 */
        "leal -0x418(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n"
        "je .Lf151d58_001520a3\n"
        "jmp .Lf151d58_00152105\n"
        ".Lf151d58_001522e8:\n"
        "movl $str_002a9af0, 4(%esp)\n" /* line 2948 */
        "leal -0x418(%ebp), %edx\n" /* info */
        "movl %edx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n"
        "jne .Lf151d58_001520b2\n"
        "jmp .Lf151d58_00152105\n"
        ".Lf151d58_00152313:\n"
        "movl $str_002aa870, 4(%esp)\n" /* line 2957 */
        "leal -0x418(%ebp), %ecx\n" /* info */
        "movl %ecx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "testl %eax, %eax\n"
        "jne .Lf151d58_001520c1\n"
        "jmp .Lf151d58_00152105\n"
        ".Lf151d58_0015233e:\n"
        "movl $str_002aa878, 4(%esp)\n" /* line 2966 */
        "leal -0x418(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %eax, (%esp)\n"
        "calll atoi\n"
        "subl $1, %eax\n" /* line 2967 */
        "cmpl $2, %eax\n"
        "jbe .Lf151d58_001520d0\n"
        "jmp .Lf151d58_00152105\n"
        /* { scope 2: position */
        ".Lf151d58_0015236d:\n"
        "movl -0x420(%ebp), %eax\n" /* line 2812 | position */
        "addl $1, %eax\n"
        "subl $1, %edx\n"
        "cmovll -0x420(%ebp), %eax\n" /* position */
        "movl %eax, -0x420(%ebp)\n" /* position */
        /* { scope 3 */
        /* { scope 4 */
        "testl %eax, %eax\n" /* line 2724 */
        "js .Lf151d58_001523f8\n"
        "movl sharedUiInfo+108660, %ebx\n"
        ".Lf151d58_00152390:\n"
        "cmpl -0x420(%ebp), %ebx\n" /* position */
        "jl .Lf151d58_001523f8\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2729 */
        "cmpl -0x420(%ebp), %eax\n" /* position */
        "jl .Lf151d58_001523b1\n"
        "testl %ebx, %ebx\n"
        "je .Lf151d58_001523b1\n"
        "addl $1, %eax\n" /* line 2730 */
        "movl %eax, sharedUiInfo+28656\n"
        ".Lf151d58_001523b1:\n"
        "leal 1(%ebx), %ecx\n" /* line 2732 */
        "movl %ecx, sharedUiInfo+108660\n"
        "cmpl -0x420(%ebp), %ecx\n" /* line 2734 | position */
        "jle .Lf151d58_001523eb\n"
        "leal 0x6fe0(, %ebx, 4), %eax\n" /* line 2836 */
        "leal sharedUiInfo+20(%eax), %edx\n"
        "leal sharedUiInfo+28660(, %ecx, 4), %ebx\n" /* force */
        "subl %edx, %ebx\n" /* force */
        ".Lf151d58_001523d8:\n"
        "subl $1, %ecx\n" /* line 2736 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx, %edx)\n"
        "subl $4, %edx\n"
        "cmpl -0x420(%ebp), %ecx\n" /* line 2734 | position */
        "jg .Lf151d58_001523d8\n"
        ".Lf151d58_001523eb:\n"
        "movl -0x420(%ebp), %eax\n" /* line 2738 | position */
        "movl %esi, sharedUiInfo+28660(, %eax, 4)\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf151d58_001523f8:\n"
        "movl -0x424(%ebp), %ebx\n" /* line 3029 | ping, clients */
        "testl %ebx, %ebx\n" /* clients */
        "jle .Lf151d58_00151fa6\n"
        "movl $0, 8(%esp)\n" /* line 3031 */
        "movl %esi, 4(%esp)\n" /* i */
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_MarkServerDirty\n"
        "addl $1, numclean\n" /* line 3032 */
        "jmp .Lf151d58_00151fa6\n"
        ".Lf151d58_0015242e:\n"
        "movl sharedUiInfo+4688(, %edx, 8), %ebx\n" /* line 3003 | clients */
        "movl $str_002aa884, 4(%esp)\n" /* "gametype" */
        "leal -0x418(%ebp), %edx\n" /* info */
        "movl %edx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl %ebx, 4(%esp)\n" /* clients */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf151d58_001521ac\n"
        "jmp .Lf151d58_00152105\n"
        /* { scope 2: position */
        ".Lf151d58_00152464:\n"
        "movl $0, -0x420(%ebp)\n" /* line 2784 | position */
        "jmp .Lf151d58_00152390\n"
        /* } scope */
        /* { scope 2: position */
        ".Lf151d58_00152473:\n"
        "movl sharedUiInfo+108660, %ebx\n" /* line 2753 | j */
        "testl %ebx, %ebx\n" /* j */
        "jle .Lf151d58_001521fc\n"
        "cmpl %esi, sharedUiInfo+28660\n" /* line 2755 */
        "je .Lf151d58_0015257a\n"
        "xorl %edi, %edi\n" /* line 2758 */
        "movl $sharedUiInfo, %ecx\n"
        ".Lf151d58_00152494:\n"
        "addl $1, %edi\n" /* line 2753 */
        "cmpl %edi, %ebx\n" /* j */
        "je .Lf151d58_001521fc\n"
        "movl 0x6ff8(%ecx), %eax\n" /* line 2755 */
        "addl $4, %ecx\n"
        "cmpl %eax, %esi\n"
        "jne .Lf151d58_00152494\n"
        ".Lf151d58_001524ac:\n"
        "leal -1(%ebx), %eax\n" /* line 2757 | j */
        "movl %eax, sharedUiInfo+108660\n"
        "cmpl %eax, %edi\n" /* line 2758 */
        "jge .Lf151d58_00152573\n"
        "leal 0x6fe4(, %edi, 4), %eax\n" /* line 2836 */
        "leal sharedUiInfo+20(%eax), %ecx\n"
        "movl %edi, %ebx\n" /* len, force */
        "leal sharedUiInfo+28660(, %edi, 4), %edi\n" /* len */
        "subl %ecx, %edi\n" /* len */
        ".Lf151d58_001524d4:\n"
        "addl $1, %ebx\n" /* line 2760 | j */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edi, %ecx)\n"
        "addl $4, %ecx\n"
        "cmpl %ebx, sharedUiInfo+108660\n" /* line 2758 | j */
        "jg .Lf151d58_001524d4\n"
        "jmp .Lf151d58_001521f6\n"
        /* } scope */
        /* { scope 2: position */
        /* { scope 3 */
        ".Lf151d58_001524ec:\n"
        "movl -0x41c(%ebp), %edi\n" /* line 2724 */
        "testl %edi, %edi\n"
        "js .Lf151d58_001523f8\n"
        "movl sharedUiInfo+108660, %ebx\n"
        "cmpl -0x41c(%ebp), %ebx\n"
        "jl .Lf151d58_001523f8\n"
        "movl sharedUiInfo+28656, %eax\n" /* line 2729 */
        "cmpl -0x41c(%ebp), %eax\n"
        "jl .Lf151d58_00152525\n"
        "testl %ebx, %ebx\n"
        "je .Lf151d58_00152525\n"
        "addl $1, %eax\n" /* line 2730 */
        "movl %eax, sharedUiInfo+28656\n"
        ".Lf151d58_00152525:\n"
        "leal 1(%ebx), %ecx\n" /* line 2732 */
        "movl %ecx, sharedUiInfo+108660\n"
        "cmpl -0x41c(%ebp), %ecx\n" /* line 2734 */
        "jle .Lf151d58_0015255f\n"
        "leal 0x6fe0(, %ebx, 4), %eax\n" /* line 2836 */
        "leal sharedUiInfo+20(%eax), %edx\n"
        "leal sharedUiInfo+28660(, %ecx, 4), %ebx\n" /* force */
        "subl %edx, %ebx\n" /* force */
        ".Lf151d58_0015254c:\n"
        "subl $1, %ecx\n" /* line 2736 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx, %edx)\n"
        "subl $4, %edx\n"
        "cmpl -0x41c(%ebp), %ecx\n" /* line 2734 */
        "jg .Lf151d58_0015254c\n"
        ".Lf151d58_0015255f:\n"
        "movl $sharedUiInfo+28640, %eax\n" /* line 2738 */
        "movl -0x41c(%ebp), %edx\n"
        "movl %esi, 0x14(%eax, %edx, 4)\n"
        "jmp .Lf151d58_001523f8\n"
        ".Lf151d58_00152573:\n"
        "movl %eax, %ebx\n"
        "jmp .Lf151d58_001521fc\n"
        /* } scope */
        /* } scope */
        /* { scope 2: position */
        ".Lf151d58_0015257a:\n"
        "xorl %edi, %edi\n" /* line 2755 */
        "jmp .Lf151d58_001524ac\n"
    );
}

/* line 1475 */
__attribute__((naked))
qboolean UI_OwnerDrawHandleKey(int ownerDraw, int flags, float *special, int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1475 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 1478 | ownerDraw */
        "subl $0xcd, %eax\n"
        "cmpl $0x30, %eax\n"
        "ja .Lf152582_001525c7\n"
        "jmpl *.Ljt_152582_0(, %eax, 4)\n"
        /* { scope 1 */
        ".Lf152582_0015259f:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1307 | key */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf152582_0015287d\n"
        "cmpl $0xd, 0x14(%ebp)\n" /* key */
        "je .Lf152582_0015287d\n"
        "cmpl $0xbf, 0x14(%ebp)\n" /* key */
        "je .Lf152582_0015287d\n"
        /* } scope */
        ".Lf152582_001525c7:\n"
        "xorl %eax, %eax\n" /* line 1467 */
        ".Lf152582_001525c9:\n"
        "addl $0x3c, %esp\n" /* line 1498 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf152582_001525d1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1392 | key */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf152582_001525ed\n"
        "cmpl $0xd, 0x14(%ebp)\n" /* key */
        "je .Lf152582_001525ed\n"
        "cmpl $0xbf, 0x14(%ebp)\n" /* key */
        "jne .Lf152582_001525c7\n"
        ".Lf152582_001525ed:\n"
        "cmpl $0xc9, 0x14(%ebp)\n" /* line 1394 | key */
        "je .Lf152582_001529a8\n"
        "movl ui_joinGameType, %ecx\n" /* line 1401 */
        "movl 8(%ecx), %edx\n"
        "addl $1, %edx\n"
        "cmpl sharedUiInfo+4684, %edx\n" /* line 1402 */
        "movl $0, %eax\n"
        "cmovel %eax, %edx\n"
        ".Lf152582_00152614:\n"
        "movl %edx, 4(%esp)\n" /* line 1406 */
        "movl %ecx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl $1, (%esp)\n" /* line 1407 */
        "calll UI_BuildServerDisplayList\n"
        "movl $1, %eax\n"
        "jmp .Lf152582_001525c9\n"
        /* } scope */
        ".Lf152582_00152633:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1447 | key */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf152582_00152653\n"
        "cmpl $0xd, 0x14(%ebp)\n" /* key */
        "je .Lf152582_00152653\n"
        "cmpl $0xbf, 0x14(%ebp)\n" /* key */
        "jne .Lf152582_001525c7\n"
        ".Lf152582_00152653:\n"
        "cmpl $0xc9, 0x14(%ebp)\n" /* line 1450 | key */
        "je .Lf152582_00152996\n"
        "movl ui_serverFilterType, %eax\n" /* line 1456 */
        "addl $1, %eax\n"
        "movl %eax, ui_serverFilterType\n"
        ".Lf152582_0015266d:\n"
        "cmpl $0, %eax\n" /* line 1459 */
        "jle .Lf152582_00152a8e\n"
        ".Lf152582_00152676:\n"
        "movl $0, ui_serverFilterType\n" /* line 1465 */
        ".Lf152582_00152680:\n"
        "movl $1, (%esp)\n" /* line 1467 */
        "calll UI_BuildServerDisplayList\n"
        "xorl %eax, %eax\n"
        "jmp .Lf152582_001525c9\n"
        /* { scope 1 */
        ".Lf152582_00152693:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1352 | key */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf152582_001526b3\n"
        "cmpl $0xd, 0x14(%ebp)\n" /* key */
        "je .Lf152582_001526b3\n"
        "cmpl $0xbf, 0x14(%ebp)\n" /* key */
        "jne .Lf152582_001525c7\n"
        ".Lf152582_001526b3:\n"
        "cmpl $0xc9, 0x14(%ebp)\n" /* line 1355 | key */
        "je .Lf152582_001529c2\n"
        "movl ui_netGameType, %ecx\n" /* line 1362 */
        "movl 8(%ecx), %edx\n"
        "addl $1, %edx\n"
        "cmpl sharedUiInfo+4424, %edx\n" /* line 1363 */
        "movl $0, %eax\n"
        "cmovel %eax, %edx\n"
        ".Lf152582_001526da:\n"
        "movl %edx, 4(%esp)\n" /* line 1367 */
        "movl %ecx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl ui_netGameType, %eax\n" /* line 1368 */
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4428(, %eax, 8), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netGameTypeName, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl ui_netGameType, %eax\n" /* line 2634 */
        "movl 8(%eax), %esi\n" /* listIndex */
        "movl sharedUiInfo+4944, %ecx\n" /* line 2636 */
        "testl %ecx, %ecx\n"
        "jle .Lf152582_00152754\n"
        "xorl %ebx, %ebx\n" /* nextNetSource */
        "movl $sharedUiInfo, %edx\n"
        ".Lf152582_0015271f:\n"
        "movl $0, 0x13f4(%edx)\n" /* line 2638 */
        "movl 0x1368(%edx), %eax\n" /* line 2639 */
        "movl %esi, %ecx\n" /* listIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf152582_00152741\n"
        "movl $1, 0x13f4(%edx)\n" /* line 2642 */
        ".Lf152582_00152741:\n"
        "addl $1, %ebx\n" /* line 2636 | nextNetSource */
        "movl sharedUiInfo+4944, %ecx\n"
        "addl $0xa4, %edx\n"
        "cmpl %ecx, %ebx\n" /* nextNetSource */
        "jl .Lf152582_0015271f\n"
        ".Lf152582_00152754:\n"
        "movl ui_currentNetMap, %eax\n" /* line 1371 */
        "movl 8(%eax), %ebx\n"
        "leal (%ebx, %ebx, 4), %eax\n"
        "leal (%ebx, %eax, 8), %eax\n"
        "movl sharedUiInfo+5108(, %eax, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf152582_001529f6\n"
        "testl %ecx, %ecx\n" /* line 2599 */
        "jle .Lf152582_001527df\n"
        "movl sharedUiInfo+5108, %edx\n" /* line 2601 */
        "testl %edx, %edx\n"
        "jne .Lf152582_00152aa8\n"
        "xorl %ebx, %ebx\n" /* line 2604 | nextNetSource */
        "movl $sharedUiInfo, %edx\n"
        ".Lf152582_0015278a:\n"
        "addl $1, %ebx\n" /* line 2599 | nextNetSource */
        "cmpl %ebx, %ecx\n" /* nextNetSource */
        "je .Lf152582_001527df\n"
        "movl 0x1498(%edx), %eax\n" /* line 2601 */
        "addl $0xa4, %edx\n"
        "testl %eax, %eax\n"
        "je .Lf152582_0015278a\n"
        ".Lf152582_001527a1:\n"
        "movl $str_002aa094, 0x10(%esp)\n" /* line 2603 */
        "movl $0, 0xc(%esp)\n"
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "movl %ebx, 4(%esp)\n" /* line 2604 | nextNetSource */
        "movl ui_currentNetMap, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        ".Lf152582_001527df:\n"
        "calll UI_SelectCurrentMap\n" /* line 1380 */
        ".Lf152582_001527e4:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf152582_001527e9:\n"
        "addl $0x3c, %esp\n" /* line 1498 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf152582_001527f1:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1418 | key */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf152582_00152811\n"
        "cmpl $0xd, 0x14(%ebp)\n" /* key */
        "je .Lf152582_00152811\n"
        "cmpl $0xbf, 0x14(%ebp)\n" /* key */
        "jne .Lf152582_001525c7\n"
        ".Lf152582_00152811:\n"
        "cmpl $0xc9, 0x14(%ebp)\n" /* line 1420 | key */
        "je .Lf152582_001529dc\n"
        "movl ui_netSource, %eax\n" /* line 1427 */
        "movl 8(%eax), %ebx\n" /* nextNetSource */
        "addl $1, %ebx\n" /* nextNetSource */
        "cmpl $3, %ebx\n" /* line 1428 | nextNetSource */
        "movl $0, %eax\n"
        "cmovel %eax, %ebx\n" /* nextNetSource */
        ".Lf152582_00152834:\n"
        "movl $1, (%esp)\n" /* line 1432 */
        "calll UI_BuildServerDisplayList\n"
        "movl %ebx, 4(%esp)\n" /* line 1433 | nextNetSource */
        "movl ui_netSource, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl ui_netSource, %eax\n" /* line 1434 */
        "cmpl $1, 8(%eax)\n"
        "je .Lf152582_001525c7\n"
        "movl $1, %eax\n" /* line 1436 */
        "calll UI_StartServerRefresh\n"
        "movl $1, (%esp)\n" /* line 1437 */
        "calll UI_BuildServerDisplayList\n"
        "xorl %eax, %eax\n"
        "jmp .Lf152582_001525c9\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_0015287d:\n"
        "movl ui_netGameType, %eax\n" /* line 2634 */
        "movl 8(%eax), %esi\n" /* listIndex */
        "movl sharedUiInfo+4944, %eax\n" /* line 2636 */
        "testl %eax, %eax\n"
        "jle .Lf152582_0015298f\n"
        "xorl %ebx, %ebx\n" /* nextNetSource */
        "xorl %edi, %edi\n"
        "movl $sharedUiInfo, %edx\n"
        ".Lf152582_0015289b:\n"
        "movl $0, 0x13f4(%edx)\n" /* line 2638 */
        "movl 0x1368(%edx), %eax\n" /* line 2639 */
        "movl %esi, %ecx\n" /* listIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf152582_001528c0\n"
        "addl $1, %edi\n" /* line 2641 */
        "movl $1, 0x13f4(%edx)\n" /* line 2642 */
        ".Lf152582_001528c0:\n"
        "addl $1, %ebx\n" /* line 2636 | nextNetSource */
        "addl $0xa4, %edx\n"
        "cmpl %ebx, sharedUiInfo+4944\n" /* nextNetSource */
        "jg .Lf152582_0015289b\n"
        ".Lf152582_001528d1:\n"
        "cmpl $0xc9, 0x14(%ebp)\n" /* line 1312 | key */
        "je .Lf152582_00152a67\n"
        "movl ui_gametype, %edx\n" /* line 1326 */
        "movl 8(%edx), %eax\n"
        "addl $1, %eax\n"
        "cmpl sharedUiInfo+4424, %eax\n" /* line 1327 */
        "jge .Lf152582_00152a5d\n"
        "cmpl $2, %eax\n" /* line 1331 */
        "je .Lf152582_00152aa1\n"
        ".Lf152582_001528ff:\n"
        "movl %eax, 4(%esp)\n" /* line 1337 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl ui_netGameType, %eax\n" /* line 2634 */
        "movl 8(%eax), %esi\n" /* listIndex */
        "movl sharedUiInfo+4944, %eax\n" /* line 2636 */
        "testl %eax, %eax\n"
        "jle .Lf152582_00152a56\n"
        "movl $0, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n" /* nextNetSource */
        "movl $sharedUiInfo, %edx\n"
        ".Lf152582_0015292e:\n"
        "movl $0, 0x13f4(%edx)\n" /* line 2638 */
        "movl 0x1368(%edx), %eax\n" /* line 2639 */
        "movl %esi, %ecx\n" /* listIndex */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf152582_00152953\n"
        "addl $1, %ebx\n" /* line 2641 | nextNetSource */
        "movl $1, 0x13f4(%edx)\n" /* line 2642 */
        ".Lf152582_00152953:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 2636 */
        "addl $0xa4, %edx\n"
        "movl -0x1c(%ebp), %eax\n"
        "cmpl %eax, sharedUiInfo+4944\n"
        "jg .Lf152582_0015292e\n"
        ".Lf152582_00152968:\n"
        "cmpl %ebx, %edi\n" /* line 1338 */
        "je .Lf152582_001527e4\n"
        "movl $0, 4(%esp)\n" /* line 1340 */
        "movl ui_currentMap, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        /* } scope */
        /* { scope 1 */
        "movl $1, %eax\n" /* line 1380 */
        "jmp .Lf152582_001527e9\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_0015298f:\n"
        "xorl %edi, %edi\n" /* line 2636 */
        "jmp .Lf152582_001528d1\n"
        /* } scope */
        ".Lf152582_00152996:\n"
        "movl ui_serverFilterType, %eax\n" /* line 1452 */
        "subl $1, %eax\n"
        "movl %eax, ui_serverFilterType\n"
        "jmp .Lf152582_0015266d\n"
        /* { scope 1 */
        ".Lf152582_001529a8:\n"
        "movl ui_joinGameType, %ecx\n" /* line 1396 */
        "movl 8(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "cmovel sharedUiInfo+4684, %eax\n"
        "leal -1(%eax), %edx\n" /* line 1397 */
        "jmp .Lf152582_00152614\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_001529c2:\n"
        "movl ui_netGameType, %ecx\n" /* line 1357 */
        "movl 8(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "cmovel sharedUiInfo+4424, %eax\n"
        "leal -1(%eax), %edx\n" /* line 1358 */
        "jmp .Lf152582_001526da\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_001529dc:\n"
        "movl ui_netSource, %eax\n" /* line 1422 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf152582_00152a99\n"
        "movl $2, %ebx\n" /* nextNetSource */
        "jmp .Lf152582_00152834\n"
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf152582_001529f6:\n"
        "testl %ecx, %ecx\n" /* line 3536 */
        "jle .Lf152582_00152a21\n"
        /* } scope */
        /* } scope */
        "xorl %esi, %esi\n" /* line 2599 */
        "xorl %eax, %eax\n"
        "movl $sharedUiInfo, %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf152582_00152a03:\n"
        "movl 0x13f4(%edx), %edi\n" /* line 3538 */
        "testl %edi, %edi\n"
        "je .Lf152582_00152a14\n"
        "cmpl %ebx, %eax\n" /* line 3540 | nextNetSource */
        "je .Lf152582_00152a23\n"
        "addl $1, %esi\n" /* line 3546 | listIndex */
        ".Lf152582_00152a14:\n"
        "addl $1, %eax\n" /* line 3536 */
        "addl $0xa4, %edx\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf152582_00152a03\n"
        ".Lf152582_00152a21:\n"
        "xorl %esi, %esi\n" /* listIndex */
        /* } scope */
        ".Lf152582_00152a23:\n"
        "movl $str_002aa094, 0x10(%esp)\n" /* line 2617 */
        "movl %esi, 0xc(%esp)\n" /* listIndex */
        "movl $4, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl uiInfo, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        /* } scope */
        "calll UI_SelectCurrentMap\n" /* line 1380 */
        "jmp .Lf152582_001527e4\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_00152a56:\n"
        "xorl %ebx, %ebx\n" /* line 2636 | nextNetSource */
        "jmp .Lf152582_00152968\n"
        ".Lf152582_00152a5d:\n"
        "movl $1, %eax\n" /* line 1331 */
        "jmp .Lf152582_001528ff\n"
        ".Lf152582_00152a67:\n"
        "movl ui_gametype, %edx\n" /* line 1314 */
        "movl 8(%edx), %eax\n"
        "subl $1, %eax\n"
        "cmpl $2, %eax\n" /* line 1315 */
        "je .Lf152582_00152a5d\n"
        "cmpl $1, %eax\n" /* line 1319 */
        "jg .Lf152582_001528ff\n"
        "movl sharedUiInfo+4424, %eax\n" /* line 1321 */
        "subl $1, %eax\n"
        "jmp .Lf152582_001528ff\n"
        /* } scope */
        ".Lf152582_00152a8e:\n"
        "jge .Lf152582_00152680\n" /* line 1463 */
        "jmp .Lf152582_00152676\n"
        /* { scope 1 */
        ".Lf152582_00152a99:\n"
        "leal -1(%eax), %ebx\n" /* line 1422 | nextNetSource */
        "jmp .Lf152582_00152834\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_00152aa1:\n"
        "movb $3, %al\n" /* line 1331 */
        "jmp .Lf152582_001528ff\n"
        /* } scope */
        /* { scope 1 */
        ".Lf152582_00152aa8:\n"
        "xorl %ebx, %ebx\n" /* line 2601 | nextNetSource */
        "jmp .Lf152582_001527a1\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_152582_0:\n"
        ".long .Lf152582_0015259f\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001527f1\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_00152633\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_00152693\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525c7\n"
        ".long .Lf152582_001525d1\n"
        ".text\n"
    );
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
__attribute__((naked))
int UI_OwnerDrawWidth(int ownerDraw, FontHandle font, float scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 829 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %eax\n" /* ownerDraw */
        "movl 0xc(%ebp), %esi\n" /* font */
        /* { scope 1: actualScale */
        "cmpl $0xdc, %eax\n" /* line 833 */
        "je .Lf153106_001531b0\n"
        "jle .Lf153106_0015318a\n"
        "cmpl $0xf7, %eax\n"
        "je .Lf153106_0015326b\n"
        "cmpl $0xfa, %eax\n"
        "je .Lf153106_00153252\n"
        "cmpl $0xde, %eax\n"
        "jne .Lf153106_00153238\n"
        "xorl %eax, %eax\n" /* line 857 */
        "cmpl $2, ui_serverFilterType\n"
        "cmovbl ui_serverFilterType, %eax\n"
        "movl %eax, ui_serverFilterType\n"
        "movl serverFilters(, %eax, 8), %eax\n" /* line 859 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa8dc, (%esp)\n" /* "EXE_SERVERFILTER%s" */
        "calll va\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002aa8f0, 4(%esp)\n" /* "server filter" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
        ".Lf153106_0015318a:\n"
        "cmpl $0x32, %eax\n" /* line 833 */
        "je .Lf153106_00153292\n"
        "cmpl $0xcd, %eax\n"
        "je .Lf153106_00153241\n"
        "cmpl $0x27, %eax\n"
        "jne .Lf153106_00153238\n"
        "calll CG_GameTypeString\n" /* line 836 */
        "movl %eax, %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
        ".Lf153106_001531b0:\n"
        "movl ui_netSource, %edx\n" /* line 849 */
        "movl 8(%edx), %eax\n"
        "cmpl sharedUiInfo+4684, %eax\n"
        "jg .Lf153106_0015329e\n"
        ".Lf153106_001531c5:\n"
        "movl netSources(, %eax, 4), %eax\n" /* line 851 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa8bc, (%esp)\n" /* "EXE_NETSOURCE%s" */
        "calll va\n"
        "movl $0, 8(%esp)\n"
        "movl $str_002aa8d0, 4(%esp)\n" /* "net source" */
        "movl %eax, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %ebx\n" /* s */
        ".Lf153106_001531f6:\n"
        "testl %ebx, %ebx\n" /* line 879 | s */
        "je .Lf153106_00153238\n"
        /* { scope 2 */
        "movss 0x10(%ebp), %xmm0\n" /* line 379 | scale */
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CL_NormalizedTextScale\n"
        "fstps -0xc(%ebp)\n" /* actualScale */
        "movl %esi, 8(%esp)\n" /* line 380 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "mulss -0xc(%ebp), %xmm0\n" /* actualScale */
        "cvttss2si %xmm0, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x20, %esp\n" /* line 884 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: actualScale */
        ".Lf153106_00153238:\n"
        "xorl %eax, %eax\n" /* line 879 */
        /* } scope */
        "addl $0x20, %esp\n" /* line 884 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: actualScale */
        ".Lf153106_00153241:\n"
        "movl ui_gametype, %eax\n" /* line 845 */
        "movl 8(%eax), %eax\n"
        "movl sharedUiInfo+4432(, %eax, 8), %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
        ".Lf153106_00153252:\n"
        "calll Display_KeyBindPending\n" /* line 864 */
        "testl %eax, %eax\n"
        "jne .Lf153106_001532bc\n"
        "movl $str_002aa90c, (%esp)\n" /* line 870 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
        ".Lf153106_0015326b:\n"
        "movl ui_netSource, %eax\n" /* line 875 */
        "movl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002aa7b0, (%esp)\n" /* "ui_lastServerRefresh_%i" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
        ".Lf153106_00153292:\n"
        "calll CG_GetKillerText\n" /* line 840 */
        "movl %eax, %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
        ".Lf153106_0015329e:\n"
        "movl $0, 4(%esp)\n" /* line 850 */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl ui_netSource, %edx\n"
        "movl 8(%edx), %eax\n"
        "jmp .Lf153106_001531c5\n"
        ".Lf153106_001532bc:\n"
        "movl $str_002aa900, (%esp)\n" /* line 866 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, %ebx\n" /* s */
        "jmp .Lf153106_001531f6\n"
    );
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

/* line 3271 */
static __attribute__((naked))
void UI_BuildFindPlayerList(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3271 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x118c, %esp\n"
        /* { scope 1: charset, str */
        "movl uiInfo, %edx\n" /* line 3279 */
        "movl 0x10a4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf153c3a_00153c5b\n"
        "cmpl 4(%edx), %eax\n"
        "jle .Lf153c3a_00153c66\n"
        /* } scope */
        ".Lf153c3a_00153c5b:\n"
        "addl $0x118c, %esp\n" /* line 3379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: charset, str */
        ".Lf153c3a_00153c66:\n"
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf153c3a_00153c91\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %ebx\n" /* line 2020 */
        "testl %ebx, %ebx\n"
        "jne .Lf153c3a_00154150\n"
        ".Lf153c3a_00153c91:\n"
        "movl $0, -0x1168(%ebp)\n" /* line 2023 | i */
        "movl $sharedUiInfo, -0x1150(%ebp)\n"
        "movl $sharedUiInfo+113204, -0x116c(%ebp)\n"
        "movl $sharedUiInfo+113140, -0x1170(%ebp)\n"
        "movl $sharedUiInfo+113204, -0x1174(%ebp)\n"
        "jmp .Lf153c3a_00153d59\n"
        ".Lf153c3a_00153cc8:\n"
        "xorl %edx, %edx\n" /* line 3336 */
        "movl -0x1170(%ebp), %eax\n"
        "calll UI_GetServerStatusInfo\n"
        "movl -0x114c(%ebp), %ecx\n" /* line 3338 */
        "movl $0, (%ecx)\n"
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf153c3a_00153d0c\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %ebx\n" /* line 2020 */
        "testl %ebx, %ebx\n"
        "jne .Lf153c3a_00154071\n"
        ".Lf153c3a_00153d0c:\n"
        "movl sharedUiInfo+113136, %eax\n" /* line 3342 */
        "cmpl sharedUiInfo+108660, %eax\n"
        "jl .Lf153c3a_00153f74\n"
        ".Lf153c3a_00153d1d:\n"
        "addl $1, -0x1168(%ebp)\n" /* line 3284 | i */
        "addl $0x8c, -0x1174(%ebp)\n"
        "addl $0x8c, -0x1170(%ebp)\n"
        "addl $0x8c, -0x116c(%ebp)\n"
        "addl $0x8c, -0x1150(%ebp)\n"
        "cmpl $0x10, -0x1168(%ebp)\n" /* i */
        "je .Lf153c3a_0015408c\n"
        ".Lf153c3a_00153d59:\n"
        "movl -0x1150(%ebp), %eax\n" /* line 3271 */
        "addl $0x1ba7c, %eax\n"
        "movl %eax, -0x114c(%ebp)\n"
        "movl -0x1150(%ebp), %edx\n" /* line 3287 */
        "movl 0x1ba7c(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf153c3a_00153cc8\n"
        "leal -0x1140(%ebp), %edx\n" /* line 3290 | info */
        "movl -0x1170(%ebp), %eax\n"
        "calll UI_GetServerStatusInfo\n"
        "testl %eax, %eax\n"
        "je .Lf153c3a_00153f35\n"
        "movl numFound, %eax\n" /* line 3293 */
        "addl $1, %eax\n"
        "movl %eax, numFound\n"
        "movl -0x440(%ebp), %edx\n" /* line 3295 */
        "testl %edx, %edx\n"
        "jle .Lf153c3a_00153eee\n"
        "movl $0, -0x1164(%ebp)\n" /* j */
        "leal -0x1140(%ebp), %ecx\n" /* info */
        "movl %ecx, -0x1154(%ebp)\n"
        "movl %ecx, %edx\n"
        "jmp .Lf153c3a_00153df2\n"
        ".Lf153c3a_00153dcc:\n"
        "addl $1, -0x1164(%ebp)\n" /* j */
        "addl $0x10, -0x1154(%ebp)\n"
        "movl -0x1164(%ebp), %edx\n" /* j */
        "cmpl -0x440(%ebp), %edx\n"
        "jge .Lf153c3a_00153ee9\n"
        "movl -0x1154(%ebp), %edx\n"
        ".Lf153c3a_00153df2:\n"
        "movl 0x48(%edx), %eax\n" /* line 3298 */
        "testl %eax, %eax\n"
        "je .Lf153c3a_00153dcc\n"
        "cmpb $0, (%eax)\n"
        "je .Lf153c3a_00153dcc\n"
        "movl $0x22, 8(%esp)\n" /* line 3303 */
        "movl 0x4c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x3a(%ebp), %ecx\n" /* name */
        "movl %ecx, (%esp)\n"
        "calll I_strncpyz\n"
        "leal -0x3a(%ebp), %eax\n" /* line 3304 | name */
        "movl %eax, (%esp)\n"
        "calll I_CleanStr\n"
        "movl uiInfo, %edx\n" /* line 3306 */
        "addl $0x4a0, %edx\n"
        "movl %edx, -0x1160(%ebp)\n" /* charset */
        /* { scope 2: i */
        /* { scope 3 */
        "cmpb $0, -0x3a(%ebp)\n" /* line 3251 | name */
        "je .Lf153c3a_00153dcc\n"
        "leal -0x3a(%ebp), %ecx\n" /* name */
        "movl %ecx, -0x115c(%ebp)\n" /* str */
        "jmp .Lf153c3a_00153e6e\n"
        ".Lf153c3a_00153e46:\n"
        "xorl %eax, %eax\n" /* line 3253 */
        ".Lf153c3a_00153e48:\n"
        "movl -0x1160(%ebp), %ecx\n" /* line 3258 | charset */
        "cmpb $0, (%ecx, %eax)\n"
        "je .Lf153c3a_00154130\n"
        ".Lf153c3a_00153e58:\n"
        "addl $1, -0x115c(%ebp)\n" /* line 3260 | str */
        "movl -0x115c(%ebp), %eax\n" /* line 3251 | str */
        "cmpb $0, (%eax)\n"
        "je .Lf153c3a_00153dcc\n"
        ".Lf153c3a_00153e6e:\n"
        "movl -0x1160(%ebp), %edx\n" /* line 3253 | charset */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "je .Lf153c3a_00154122\n"
        "movl -0x115c(%ebp), %ecx\n" /* str */
        "cmpb $0, (%ecx)\n"
        "je .Lf153c3a_00153e46\n"
        "movl %ecx, %esi\n"
        "movl $0, -0x1158(%ebp)\n" /* i */
        "xorl %edi, %edi\n"
        "jmp .Lf153c3a_00153ec6\n"
        ".Lf153c3a_00153e9a:\n"
        "addl $1, -0x1158(%ebp)\n" /* i */
        "movl -0x1158(%ebp), %edi\n" /* i */
        "movl -0x1160(%ebp), %edx\n" /* charset */
        "movzbl (%edx, %edi), %eax\n"
        "testb %al, %al\n"
        "je .Lf153c3a_00154130\n"
        "movl -0x115c(%ebp), %esi\n" /* str */
        "addl %edi, %esi\n"
        "cmpb $0, (%esi)\n"
        "je .Lf153c3a_00153e58\n"
        ".Lf153c3a_00153ec6:\n"
        "movsbl %al, %eax\n" /* line 3255 */
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "movl %eax, %ebx\n"
        "movsbl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll ___toupper\n"
        "cmpl %eax, %ebx\n"
        "je .Lf153c3a_00153e9a\n"
        "movl %edi, %eax\n" /* line 3253 */
        "jmp .Lf153c3a_00153e48\n"
        ".Lf153c3a_00153ee9:\n"
        "movl numFound, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf153c3a_00153eee:\n"
        "movl uiInfo, %edx\n" /* line 3323 */
        "movl %eax, 0x10(%esp)\n"
        "movl sharedUiInfo+113136, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002aa978, 8(%esp)\n" /* "searching %d/%d..." */
        "movl $0x40, 4(%esp)\n"
        "movl 0x10a0(%edx), %eax\n"
        "shll $6, %eax\n"
        "leal 0xc60(%eax, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl -0x114c(%ebp), %ecx\n" /* line 3325 */
        "movl $0, (%ecx)\n"
        ".Lf153c3a_00153f35:\n"
        "movl -0x114c(%ebp), %eax\n" /* line 3329 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf153c3a_00153cc8\n"
        "movl uiInfo, %eax\n"
        "movl 4(%eax), %eax\n"
        "movl ui_serverStatusTimeOut, %edx\n"
        "subl 8(%edx), %eax\n"
        "movl -0x1150(%ebp), %edx\n"
        "cmpl %eax, 0x1ba74(%edx)\n"
        "jge .Lf153c3a_00153d1d\n"
        "addl $1, numTimeOuts\n" /* line 3333 */
        "jmp .Lf153c3a_00153cc8\n"
        ".Lf153c3a_00153f74:\n"
        "movl uiInfo, %eax\n" /* line 3344 */
        "movl 4(%eax), %eax\n"
        "movl -0x1150(%ebp), %edx\n"
        "movl %eax, 0x1ba74(%edx)\n"
        "movl $0x40, 0xc(%esp)\n" /* line 3345 */
        "movl -0x1170(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl sharedUiInfo+113136, %eax\n"
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerAddressString\n"
        "movl $0x400, 0xc(%esp)\n" /* line 3346 */
        "leal -0x43a(%ebp), %ebx\n" /* infoString */
        "movl %ebx, 8(%esp)\n"
        "movl sharedUiInfo+113136, %eax\n"
        "movl sharedUiInfo+28660(, %eax, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl ui_netSource, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerInfo\n"
        "movl $str_002aa89c, 4(%esp)\n" /* line 3347 */
        "movl %ebx, (%esp)\n"
        "calll Info_ValueForKey\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x116c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl -0x114c(%ebp), %edx\n" /* line 3348 */
        "movl $1, (%edx)\n"
        "movl sharedUiInfo+113136, %edx\n" /* line 3349 */
        "addl $1, %edx\n"
        "movl %edx, sharedUiInfo+113136\n"
        "movl uiInfo, %ecx\n" /* line 3350 */
        "movl numFound, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002aa978, 8(%esp)\n" /* "searching %d/%d..." */
        "movl $0x40, 4(%esp)\n"
        "movl 0x10a0(%ecx), %eax\n"
        "shll $6, %eax\n"
        "leal 0xc60(%eax, %ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf153c3a_00153d1d\n"
        ".Lf153c3a_00154071:\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf153c3a_00153d0c\n"
        ".Lf153c3a_0015408c:\n"
        "movl $sharedUiInfo, %eax\n" /* line 3284 */
        "movl $sharedUiInfo+2240, %edx\n"
        ".Lf153c3a_00154096:\n"
        "movl 0x1ba7c(%eax), %ecx\n" /* line 3356 */
        "testl %ecx, %ecx\n"
        "jne .Lf153c3a_001541d0\n"
        "addl $0x8c, %eax\n" /* line 3358 */
        "cmpl %eax, %edx\n" /* line 3354 */
        "jne .Lf153c3a_00154096\n"
        "movl uiInfo, %esi\n" /* line 3369 */
        "movl 0x10a0(%esi), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf153c3a_001541ed\n"
        "leal 0x4a0(%esi), %ecx\n" /* line 3375 */
        "movl $str_002157b8, %edx\n"
        "cmpl $2, %ebx\n"
        "movl $str_002aa9a0, %eax\n" /* "s" */
        "cmovnel %eax, %edx\n"
        "leal -1(%ebx), %eax\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002aa9a4, 8(%esp)\n" /* "%d server%s found with player %s" */
        "movl $0x40, 4(%esp)\n"
        "shll $6, %eax\n"
        "leal 0xca0(%eax, %esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        ".Lf153c3a_00154108:\n"
        "movl uiInfo, %eax\n" /* line 3377 */
        "movl $0, 0x10a4(%eax)\n"
        /* } scope */
        "addl $0x118c, %esp\n" /* line 3379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: charset, str */
        ".Lf153c3a_00154122:\n"
        "movl -0x115c(%ebp), %edi\n" /* line 3306 | str */
        "testl %edi, %edi\n"
        "je .Lf153c3a_00153dcc\n"
        ".Lf153c3a_00154130:\n"
        "movl uiInfo, %edx\n" /* line 3309 */
        "movl 0x10a0(%edx), %eax\n"
        "cmpl $0xe, %eax\n"
        "jle .Lf153c3a_0015416b\n"
        "movl sharedUiInfo+108660, %eax\n" /* line 3319 */
        "movl %eax, sharedUiInfo+113136\n"
        "jmp .Lf153c3a_00153dcc\n"
        ".Lf153c3a_00154150:\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf153c3a_00153c91\n"
        ".Lf153c3a_0015416b:\n"
        "movl $0x40, 8(%esp)\n" /* line 3312 */
        "movl -0x1170(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "shll $6, %eax\n"
        "leal 0x860(%eax, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl uiInfo, %edx\n" /* line 3313 */
        "movl $0x40, 8(%esp)\n"
        "movl -0x1174(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10a0(%edx), %eax\n"
        "shll $6, %eax\n"
        "leal 0xc60(%eax, %edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl uiInfo, %eax\n" /* line 3314 */
        "addl $1, 0x10a0(%eax)\n"
        "jmp .Lf153c3a_00153dcc\n"
        ".Lf153c3a_001541d0:\n"
        "movl uiInfo, %edx\n" /* line 3364 */
        "movl 4(%edx), %eax\n"
        "addl $0x19, %eax\n"
        "movl %eax, 0x10a4(%edx)\n"
        /* } scope */
        "addl $0x118c, %esp\n" /* line 3379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: charset, str */
        ".Lf153c3a_001541ed:\n"
        "movl $str_002aa98c, 8(%esp)\n" /* line 3371 */
        "movl $0x40, 4(%esp)\n"
        "leal 0xc60(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "jmp .Lf153c3a_00154108\n"
    );
}

/* line 3388 */
static __attribute__((naked))
void UI_BuildServerStatus(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3388 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl uiInfo, %edx\n" /* line 3391 */
        "movl 0x10a4(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf154210_00154279\n"
        "testl %eax, %eax\n" /* line 3396 | force */
        "jne .Lf154210_0015427b\n"
        "movl sharedUiInfo+113132, %eax\n" /* line 3398 | force */
        "testl %eax, %eax\n" /* force */
        "je .Lf154210_00154279\n"
        "cmpl 4(%edx), %eax\n" /* force */
        "jg .Lf154210_00154279\n"
        ".Lf154210_00154238:\n"
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf154210_00154262\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "jne .Lf154210_001542f5\n"
        ".Lf154210_00154262:\n"
        "movl sharedUiInfo+28656, %edx\n" /* line 3415 */
        "testl %edx, %edx\n"
        "js .Lf154210_00154279\n"
        "movl sharedUiInfo+108660, %eax\n" /* force */
        "cmpl %eax, %edx\n" /* force */
        "jg .Lf154210_00154279\n"
        "testl %eax, %eax\n" /* force */
        "jne .Lf154210_001542ce\n"
        ".Lf154210_00154279:\n"
        "leave\n" /* line 3430 */
        "retl\n"
        ".Lf154210_0015427b:\n"
        "movl $0, 0x10(%esp)\n" /* line 3405 */
        "movl $0, 0xc(%esp)\n"
        "movl $0xd, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Menu_SetFeederSelection\n"
        "movl $0, sharedUiInfo+113128\n" /* line 3406 */
        "movl $0, 8(%esp)\n" /* line 3409 */
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll LAN_GetServerStatus\n"
        "jmp .Lf154210_00154238\n"
        ".Lf154210_001542ce:\n"
        "movl $sharedUiInfo+109800, %edx\n" /* line 3420 */
        "movl $sharedUiInfo+109736, %eax\n" /* force */
        "calll UI_GetServerStatusInfo\n"
        "testl %eax, %eax\n" /* force */
        "jne .Lf154210_00154310\n"
        "movl uiInfo, %eax\n" /* line 3428 | force */
        "movl 4(%eax), %eax\n" /* force */
        "addl $0x1f4, %eax\n" /* force */
        "movl %eax, sharedUiInfo+113132\n" /* force */
        "leave\n" /* line 3430 */
        "retl\n"
        ".Lf154210_001542f5:\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf154210_00154262\n"
        ".Lf154210_00154310:\n"
        "movl $0, sharedUiInfo+113132\n" /* line 3422 */
        "xorl %edx, %edx\n" /* line 3423 */
        "movl $sharedUiInfo+109736, %eax\n" /* force */
        "calll UI_GetServerStatusInfo\n"
        "leave\n" /* line 3430 */
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
__attribute__((naked))
int UI_FeederCount(float feederID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3438 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movss 8(%ebp), %xmm0\n" /* feederID */
        "ucomiss lit4_002ed608, %xmm0\n" /* line 3441 | 4.0f */
        "jne .Lf156490_00156504\n"
        "jp .Lf156490_00156504\n"
        "movl ui_netGameType, %eax\n" /* line 2634 */
        "movl 8(%eax), %esi\n"
        "movl sharedUiInfo+4944, %edx\n" /* line 2636 */
        "testl %edx, %edx\n"
        "jle .Lf156490_0015651f\n"
        "xorl %edi, %edi\n"
        "xorl %ebx, %ebx\n"
        "movl $sharedUiInfo, %edx\n"
        ".Lf156490_001564c4:\n"
        "movl $0, 0x13f4(%edx)\n" /* line 2638 */
        "movl 0x1368(%edx), %eax\n" /* line 2639 */
        "movl %esi, %ecx\n"
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lf156490_001564e9\n"
        "addl $1, %ebx\n" /* line 2641 */
        "movl $1, 0x13f4(%edx)\n" /* line 2642 */
        ".Lf156490_001564e9:\n"
        "addl $1, %edi\n" /* line 2636 */
        "addl $0xa4, %edx\n"
        "cmpl %edi, sharedUiInfo+4944\n"
        "jg .Lf156490_001564c4\n"
        "movl %ebx, %eax\n" /* line 3501 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf156490_00156504:\n"
        "ucomiss lit4_002ed728, %xmm0\n" /* line 3443 | 9.0f */
        "jne .Lf156490_0015652b\n"
        "jp .Lf156490_0015652b\n"
        "movl sharedUiInfo+26484, %ebx\n" /* line 3444 */
        "movl %ebx, %eax\n" /* line 3501 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf156490_0015651f:\n"
        "xorl %ebx, %ebx\n" /* line 3497 */
        ".Lf156490_00156521:\n"
        "movl %ebx, %eax\n" /* line 3501 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf156490_0015652b:\n"
        "ucomiss lit4_002ed62c, %xmm0\n" /* line 3446 | 2.0f */
        "je .Lf156490_00156547\n"
        ".Lf156490_00156534:\n"
        "ucomiss lit4_002ed8c0, %xmm0\n" /* line 3452 | 13.0f */
        "jne .Lf156490_00156577\n"
        "jp .Lf156490_00156577\n"
        "movl sharedUiInfo+113128, %ebx\n" /* line 3453 */
        "jmp .Lf156490_00156521\n"
        ".Lf156490_00156547:\n"
        "jp .Lf156490_00156534\n" /* line 3446 */
        "movl ui_netSource, %eax\n" /* line 2016 */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll LAN_GetServerCount\n"
        "cmpl sharedUiInfo+108664, %eax\n" /* line 2017 */
        "je .Lf156490_0015656f\n"
        "movl %eax, sharedUiInfo+108664\n" /* line 2019 */
        "movl sharedUiInfo+108660, %eax\n" /* line 2020 */
        "testl %eax, %eax\n"
        "jne .Lf156490_001565c4\n"
        ".Lf156490_0015656f:\n"
        "movl sharedUiInfo+108660, %ebx\n" /* line 3449 */
        "jmp .Lf156490_00156521\n"
        ".Lf156490_00156577:\n"
        "ucomiss lit4_002ed7fc, %xmm0\n" /* line 3455 | 7.0f */
        "je .Lf156490_001565a6\n"
        ".Lf156490_00156580:\n"
        "ucomiss lit4_002ed694, %xmm0\n" /* line 3486 | 20.0f */
        "jne .Lf156490_0015658b\n"
        "jnp .Lf156490_001565a8\n"
        ".Lf156490_0015658b:\n"
        "ucomiss lit4_002ed8b8, %xmm0\n" /* line 3497 | 24.0f */
        "jp .Lf156490_0015651f\n"
        "jne .Lf156490_0015651f\n"
        "movl uiInfo, %eax\n" /* line 3498 */
        "movl 0x280(%eax), %ebx\n"
        "jmp .Lf156490_00156521\n"
        ".Lf156490_001565a6:\n"
        "jp .Lf156490_00156580\n" /* line 3455 */
        ".Lf156490_001565a8:\n"
        "movl uiInfo, %edx\n" /* line 3488 */
        "movl 4(%edx), %eax\n"
        "cmpl 0x278(%edx), %eax\n"
        "jg .Lf156490_001565dc\n"
        ".Lf156490_001565b9:\n"
        "movl sharedUiInfo+68, %ebx\n" /* line 3493 */
        "jmp .Lf156490_00156521\n"
        ".Lf156490_001565c4:\n"
        "movl $0xffffffff, sharedUiInfo+28656\n" /* line 2022 */
        "movl $1, (%esp)\n" /* line 2023 */
        "calll UI_BuildServerDisplayList\n"
        "jmp .Lf156490_0015656f\n"
        ".Lf156490_001565dc:\n"
        "addl $0xbb8, %eax\n" /* line 3490 */
        "movl %eax, 0x278(%edx)\n"
        "calll UI_BuildPlayerList\n" /* line 3491 */
        "jmp .Lf156490_001565b9\n"
    );
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

