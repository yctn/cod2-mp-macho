/* ASM dump from: ui_shared_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_shared_obj.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdint.h>
#include <string.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/ui/ui_utils.h"
 */

extern keywordHash_t * itemParseKeywordHash[512]; /* 0x0 */
extern keywordHash_t menuParseKeywords[33]; /* 0x0 */
extern keywordHash_t itemParseKeywords[66]; /* 0x0 */
static char string_00f3b9c0[4096]; /* string */
static unsigned char g_load[0x640]; /* g_load */
static char menuBuf[32768]; /* menuBuf */
static keywordHash_t * menuParseKeywordHash[512]; /* menuParseKeywordHash */
static char menuBuf1[4096]; /* menuBuf1 */
void UI_MapLoadInfo(const char *filename);
void PC_SourceError(int handle, char *format, ...);
qboolean PC_Script_Parse(int handle, const char * *out);
void Window_SetStaticFlags(void *item, int flags);
qboolean PC_ReadTokenHandle(int handle, void *token);
const char *String_Alloc(const char *str);
void I_strncpyz(char *dest, const char *src, int destsize);
void I_strlwr(char *str);
void *CL_RegisterMaterialNoMip(const char *name, int imageTrack);
void *UI_Alloc(int size, int align);
extern int FS_ReadFile(const char *filename, void **buffer);
extern void FS_FreeFile(void *buffer);
extern void Com_SetCSV(int csv);
extern const char *Com_ParseOnLine(const char **data_p);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern void CL_Material_Duplicate(int material, const char *name);
void Window_SetRect(menuDef_t *menu, rectDef_t *rect);
void Menu_UpdatePosition(menuDef_t *menu);
void Item_InitControls(const char (*item)[4]);
qboolean MenuParse_onOpen(const char (*item)[4], int handle);
qboolean MenuParse_onClose(const char (*item)[4], int handle);
qboolean MenuParse_onESC(const char (*item)[4], int handle);
qboolean MenuParse_soundLoop(const char (*item)[4], int handle);
void __attribute_regparm__(2) Item_ValidateTypeData(itemDef_t *item, int handle);
qboolean Item_IsEditFieldDef(itemDef_t *item);
editFieldDef_t *Item_GetEditFieldDef(itemDef_t *item);
qboolean ItemParse_textsavegame(const char (*item)[4], int handle);
qboolean ItemParse_notselectable(const char (*item)[4], int handle);
qboolean ItemParse_noScrollBars(const char (*item)[4], int handle);
qboolean ItemParse_horizontalscroll(const char (*item)[4], int handle);
qboolean ItemParse_doubleClick(const char (*item)[4], int handle);
qboolean ItemParse_onFocus(const char (*item)[4], int handle);
qboolean ItemParse_leaveFocus(const char (*item)[4], int handle);
qboolean ItemParse_mouseEnter(const char (*item)[4], int handle);
qboolean ItemParse_mouseExit(const char (*item)[4], int handle);
qboolean ItemParse_mouseEnterText(const char (*item)[4], int handle);
qboolean ItemParse_mouseExitText(const char (*item)[4], int handle);
qboolean ItemParse_action(const char (*item)[4], int handle);
qboolean ItemParse_accept(const char (*item)[4], int handle);
qboolean Item_Parse_maxCharsGotoNext(const char (*item)[4], int handle);
qboolean ItemParse_dvarStrList(const char (*item)[4], int handle);
qboolean ItemParse_enableDvar(const char (*item)[4], int handle);
qboolean ItemParse_disableDvar(const char (*item)[4], int handle);
qboolean ItemParse_showDvar(const char (*item)[4], int handle);
qboolean ItemParse_hideDvar(const char (*item)[4], int handle);
qboolean ItemParse_focusDvar(const char (*item)[4], int handle);
void Menu_PostParse(menuDef_t *menu);
qboolean MenuParse_popup(const char (*item)[4], int handle);
qboolean MenuParse_outOfBounds(const char (*item)[4], int handle);
qboolean MenuParse_legacySplitScreenScale(const char (*item)[4], int handle);
qboolean ItemParse_decoration(const char (*item)[4], int handle);
qboolean ItemParse_wrapped(const char (*item)[4], int handle);
qboolean ItemParse_autowrapped(const char (*item)[4], int handle);
qboolean MenuParse_execKey(const char (*item)[4], int handle);
qboolean ItemParse_execKey(const char (*item)[4], int handle);
qboolean ItemParse_textfile(const char (*item)[4], int handle);
int FS_FOpenFileByMode(const char *qpath, fileHandle_t *f, fsMode_t mode);
int FS_Read(void *buffer, int len, fileHandle_t h);
void FS_FCloseFile(fileHandle_t h);
int Com_Compress(char *data_p);
void Com_BeginParseSession(const char *filename);
void Com_EndParseSession(void);
const char *Com_Parse(const char **data_p);
int I_stricmp(const char *s1, const char *s2);
Bool I_isupper(int c);
void Com_Printf(const char *fmt, ...);
void Com_Error(errorParm_t code, const char *fmt, ...);
void Menu_SetCursorItem(menuDef_t *menu, int cursorItem);
static Bool __attribute_regparm__(2) Menu_New(int handle, int imageTrack);
qboolean Item_Parse(int handle, const char (*item)[4]);
qboolean MenuParse_itemDef(const char (*item)[4], int handle);
void Item_SetupKeywordHash(void);
void Menu_SetupKeywordHash(void);
qboolean MenuParse_name(const char (*item)[4], int handle);
qboolean MenuParse_background(const char (*item)[4], int handle);
qboolean MenuParse_cinematic(const char (*item)[4], int handle);
qboolean ItemParse_name(const char (*item)[4], int handle);
qboolean ItemParse_focusSound(const char (*item)[4], int handle);
qboolean ItemParse_text(const char (*item)[4], int handle);
qboolean ItemParse_group(const char (*item)[4], int handle);
qboolean ItemParse_background(const char (*item)[4], int handle);
qboolean ItemParse_cinematic(const char (*item)[4], int handle);
qboolean ItemParse_dvarTest(const char (*item)[4], int handle);
qboolean ItemParse_dvar(const char (*item)[4], int handle);
qboolean ItemParse_dvarEnumList(const char (*item)[4], int handle);
qboolean ItemParse_outlinecolor(const char (*item)[4], int handle);
qboolean MenuParse_outlinecolor(const char (*item)[4], int handle);
qboolean PC_Rect_Parse(int handle, rectDef_t *r);
qboolean ItemParse_rect(const char (*item)[4], int handle);
qboolean MenuParse_rect(const char (*item)[4], int handle);
qboolean MenuParse_borderSize(const char (*item)[4], int handle);
qboolean MenuParse_backcolor(const char (*item)[4], int handle);
qboolean MenuParse_forecolor(const char (*item)[4], int handle);
qboolean MenuParse_bordercolor(const char (*item)[4], int handle);
qboolean MenuParse_focuscolor(const char (*item)[4], int handle);
qboolean MenuParse_disablecolor(const char (*item)[4], int handle);
qboolean MenuParse_fadeClamp(const char (*item)[4], int handle);
qboolean MenuParse_fadeAmount(const char (*item)[4], int handle);
qboolean MenuParse_fadeInAmount(const char (*item)[4], int handle);
qboolean MenuParse_blurWorld(const char (*item)[4], int handle);
qboolean ItemParse_elementwidth(const char (*item)[4], int handle);
qboolean ItemParse_elementheight(const char (*item)[4], int handle);
qboolean ItemParse_feeder(const char (*item)[4], int handle);
qboolean ItemParse_bordersize(const char (*item)[4], int handle);
qboolean ItemParse_textalignx(const char (*item)[4], int handle);
qboolean ItemParse_textaligny(const char (*item)[4], int handle);
qboolean ItemParse_textscale(const char (*item)[4], int handle);
qboolean ItemParse_backcolor(const char (*item)[4], int handle);
qboolean ItemParse_forecolor(const char (*item)[4], int handle);
qboolean ItemParse_bordercolor(const char (*item)[4], int handle);
qboolean ItemParse_special(const char (*item)[4], int handle);
qboolean ItemParse_dvarFloat(const char (*item)[4], int handle);
qboolean ItemParse_dvarFloatList(const char (*item)[4], int handle);
qboolean MenuParse_fullscreen(const char (*item)[4], int handle);
qboolean MenuParse_style(const char (*item)[4], int handle);
qboolean MenuParse_visible(const char (*item)[4], int handle);
qboolean MenuParse_border(const char (*item)[4], int handle);
qboolean MenuParse_ownerdrawFlag(const char (*item)[4], int handle);
qboolean MenuParse_ownerdraw(const char (*item)[4], int handle);
qboolean MenuParse_fadeCycle(const char (*item)[4], int handle);
qboolean MenuParse_execKeyInt(const char (*item)[4], int handle);
qboolean ItemParse_origin(const char (*item)[4], int handle);
qboolean ItemParse_style(const char (*item)[4], int handle);
qboolean ItemParse_type(const char (*item)[4], int handle);
qboolean ItemParse_elementtype(const char (*item)[4], int handle);
qboolean ItemParse_columns(const char (*item)[4], int handle);
qboolean ItemParse_border(const char (*item)[4], int handle);
qboolean ItemParse_visible(const char (*item)[4], int handle);
qboolean ItemParse_ownerdraw(const char (*item)[4], int handle);
qboolean ItemParse_align(const char (*item)[4], int handle);
qboolean ItemParse_textalign(const char (*item)[4], int handle);
qboolean ItemParse_textstyle(const char (*item)[4], int handle);
qboolean ItemParse_textfont(const char (*item)[4], int handle);
qboolean ItemParse_maxChars(const char (*item)[4], int handle);
qboolean ItemParse_maxPaintChars(const char (*item)[4], int handle);
qboolean ItemParse_ownerdrawFlag(const char (*item)[4], int handle);
qboolean ItemParse_execKeyInt(const char (*item)[4], int handle);
static Bool __attribute_regparm__(2) UI_ParseMenuInternal(const char *menuFile, int imageTrack);
MenuList * UI_LoadMenus(const char *menuFile, int imageTrack);
MenuList * UI_LoadMenu(const char *menuFile, int imageTrack);

static loadAssets_t *UI_LoadAssets(void)
{
    return (loadAssets_t *)g_load;
}

static MenuList *UI_MenuList(void)
{
    return (MenuList *)(g_load + sizeof(loadAssets_t));
}

static itemDef_t **UI_MenuItemStorage(void)
{
    return (itemDef_t **)(g_load + 64);
}

static menuDef_t **UI_MenuStorage(void)
{
    return (menuDef_t **)(g_load + 1088);
}

static keywordHash_t *UI_KeywordHashNext(keywordHash_t *hash)
{
    return (keywordHash_t *)(uintptr_t)hash->next;
}

static unsigned int UI_KeywordHashKey(const char *keyword)
{
    int hash;
    int weight;
    unsigned char c;

    hash = 0;
    weight = 0x77;
    c = (unsigned char)*keyword;

    while (c != '\0') {
        int ch = (char)c;

        if (I_isupper(ch))
            ch += 0x20;

        hash += ch * weight;
        weight += 1;
        c = (unsigned char)*++keyword;
    }

    return (unsigned int)((hash ^ (hash >> 10) ^ (hash >> 20)) & 0x1ff);
}

/* line 103 */
void UI_MapLoadInfo(const char *filename) {
    void *loadfile;
    const char *parse;
    const char *token;
    char key[256];
    char name[64];
    int tokenLen;
    int material;
    const char *value;

    if (!filename[0])
        return;

    if (FS_ReadFile(filename, &loadfile) < 0) {
        Com_Printf((const char *)str_002b4034, filename);
        return;
    }

    parse = (const char *)loadfile;
    Com_BeginParseSession(filename);
    Com_SetCSV(1);

    for (;;) {
        token = Com_Parse(&parse);
        if (!token[0])
            break;

        tokenLen = strlen(token);
        if (tokenLen + 1 > 255) {
            Com_EndParseSession();
            Com_Error(1, (const char *)str_002b4058, key, tokenLen, 255);
        }

        memcpy(key, token, tokenLen + 1);

        value = Com_ParseOnLine(&parse);
        if (!value[0]) {
            Com_EndParseSession();
            Com_Error(1, (const char *)str_002b407c, key, filename);
        }

        material = (int)CL_RegisterMaterialNoMip(value, 3);
        Com_sprintf(name, 64, (const char *)str_002b409c, key);
        I_strlwr(name);
        CL_Material_Duplicate(material, name);
    }

    Com_EndParseSession();
    FS_FreeFile(loadfile);
}
