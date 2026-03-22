/* ASM dump from: ui_shared_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui_mp/ui_shared_mp.cpp */

#include "common_types.h"
#include "imports.h"

#include <stdlib.h>  /* atoi, atof */
#include <string.h>  /* memmove, memset, strchr, strncpy */
#include <math.h>    /* ceilf, sinf, cosf, fabsf */

/* Original includes (from N_BINCL debug info):
 *   #include "PC/ui/ui_utils.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

/* Extern function declarations for functions called from converted C code */
extern const char *va(const char *fmt, ...);
extern void Cbuf_ExecuteText(int exec_when, const char *text);
extern int I_stricmp(const char *s0, const char *s1);
extern int I_strncmp(const char *s0, const char *s1, int n);
extern void I_strncat(char *dest, const char *src, int destsize);
extern void Com_Error(int code, const char *fmt, ...);
extern void Com_Printf(int channel, const char *fmt, ...);
extern const char *Com_ParseOnLine(const char **p);
extern const char *SEH_StringEd_GetString(const char *key);
extern qboolean Dvar_GetBool(const char *name);
extern int Dvar_GetInt(const char *name);
extern float Dvar_GetFloat(const char *name);
extern const char *Dvar_GetString(const char *name);
extern void Dvar_SetFromStringByName(const char *dvarName, const char *string);
extern struct dvar_s *Dvar_FindVar(const char *name);
extern void UI_PlayLocalSoundAlias(int channel);
extern void UI_PlayLocalSoundAliasByName(const char *name);
extern void UI_RunMenuScript(const char *name);
extern qboolean UI_ClientIsInGame(void);
extern void UI_Pause(qboolean pause);
extern void UI_DrawHandlePic(float x, float y, float w, float h, MaterialHandle material);
extern void UI_DrawRect(float x, float y, float w, float h, int horzAlign, int vertAlign, float size, const vec_t *color);
extern void UI_FillRect(float x, float y, float w, float h, int horzAlign, int vertAlign, const vec_t *color);
extern void UI_DrawSides(float x, float y, float w, float h, float size, const vec_t *color);
extern void UI_DrawTopBottom(float x, float y, float w, float h, float size, const vec_t *color);
extern void UI_DrawLoadBar(float x, float y, float w, float h, int horzAlign, int vertAlign, float fill, const vec_t *color, MaterialHandle material);
extern int UI_TextWidth(const char *text, int maxChars, FontHandle font, float scale);
extern int UI_TextHeight(FontHandle font, float scale);
extern const char *UI_SafeTranslateString(const char *key);
extern int UI_OwnerDrawWidth(int ownerDraw, float scale);
extern qboolean UI_OwnerDrawVisible(int flags);
extern void UI_OwnerDraw(float x, float y, float w, float h, int horzAlign, int vertAlign, float text_x, float text_y, int ownerDraw, int ownerDrawFlags, float scale, const vec_t *color, MaterialHandle shader, int textStyle);
extern qboolean UI_OwnerDrawHandleKey(int ownerDraw, int flags, int *special, int key);
extern int UI_FeederCount(float feederID);
extern MaterialHandle UI_FeederItemImage(float feederID, int index);
extern const char *UI_FeederItemText(float feederID, int index, int column, MaterialHandle *handle);
extern void UI_FeederSelection(float feederID, int index);
extern void UI_OverrideCursorPos(int *x, int *y);
extern qboolean UI_OwnerDrawVisible(int flags);
extern void CalcScreenPlacement(float *x, float *w, float *y, float *h, int horzAlign, int vertAlign);
extern float CalcScreenX(float *x, int horzAlign);
extern float CalcScreenY(float *y, int vertAlign);
extern qboolean Float_Parse(const char **p, float *f);
extern qboolean Int_Parse(const char **p, int *i);
extern qboolean Rect_Parse(const char **p, rectDef_t *r);
extern MaterialHandle CL_RegisterMaterialNoMip(const char *name);
extern const char *CL_GetConfigString(int index);
extern void CIN_DrawCinematic(int handle, float x, float y, float w, float h);
extern int CIN_PlayCinematic(const char *name, int x, int y, int w, int h, int flags);
extern int CIN_RunCinematic(int handle);
extern void CIN_SetExtents(int handle, float x, float y, float w, float h);
extern void CIN_StopCinematic(int handle);
extern void Key_GetBindingBuf(int keynum, char *buf, int buflen);
extern void Key_KeynumToStringBuf(int keynum, char *buf, int buflen);
extern void Key_SetBinding(int keynum, const char *binding);
extern void Key_SetOverstrikeMode(qboolean state);
extern int Key_GetCatcher(void);
extern void Key_SetCatcher(int catcher);
extern qboolean Item_EnableShowViaDvar(itemDef_t *item, int flags);
extern float Item_GetCursorPosOffset(itemDef_t *item, const char *buff, int direction);
extern struct listBoxDef_s *Item_GetListBoxDef(itemDef_t *item);
extern struct multiDef_s *Item_GetMultiDef(itemDef_t *item);
extern void Item_SetCursorPos(itemDef_t *item, int cursorPos);
extern void Item_SetScreenCoords(itemDef_t *item);
extern void Item_SetTextRect(itemDef_t *item);
extern void Item_SetupKeywordHash(void);
extern qboolean ListBox_HasValidCursorPos(itemDef_t *item);
extern void ListBox_SetCursorPos(itemDef_t *item, int cursorPos);
extern void ListBox_SetEndPos(itemDef_t *item, int endPos);
extern void ListBox_SetStartPos(itemDef_t *item, int startPos);
extern void Menu_SetCursorItem(displayContextDef_t *dc, menuDef_t *menu, int cursorItem);
extern void Menu_SetupKeywordHash(void);
extern void Menu_UpdatePosition(displayContextDef_t *dc, menuDef_t *menu);
extern void Window_AddDynamicFlags(itemDef_t *item, int flags);
extern void Window_RemoveDynamicFlags(itemDef_t *item, int flags);
extern void Window_SetDynamicFlags(itemDef_t *item, int flags);
extern void Window_SetOffsetTime(itemDef_t *item, int time);
extern void Window_SetRect(itemDef_t *item, float x, float y, float w, float h);
extern void Window_SetRectClient(itemDef_t *item, float x, float y, float w, float h);
extern void Window_SetRectEffects0(itemDef_t *item, float x, float y, float w, float h);
extern void Window_SetRectEffects1(itemDef_t *item, float x, float y, float w, float h);
extern int I_isdigit(int c);
extern int I_isforfilename(int c);
extern int Sys_Milliseconds(void);
extern char Com_GetDecimalDelimiter(void);

void diag_item_paint_enter(void *item) {
    (void)item;
}
void diag_item_paint_skip(void *item, int reason) {
    (void)item;
    (void)reason;
}
void diag_item_paint_draw(void *item) {
    (void)item;
}

extern unsigned char updateScreenCalled[];
extern qboolean g_waitingForKey; /* 0x0 */
extern qboolean g_editingField; /* 0x0 */
extern itemDef_t *g_editItem; /* 0x0 */
extern commandDef_t commandList[28]; /* 0x0 */
extern int scriptCommandCount; /* 0x0 */
static rectDef_t rect; /* rect */
static qboolean inHandleKey; /* inHandleKey */
static scrollInfo_t scrollInfo; /* scrollInfo */
static void (*captureFunc)(); /* captureFunc */
static void *captureData; /* captureData */
static itemDef_t *itemCapture; /* itemCapture */
static itemDef_t *g_bindItem; /* g_bindItem */
static qboolean debugMode; /* debugMode */
static int lastListBoxClickTime; /* lastListBoxClickTime */
#include "ui_shared_mp_g_bindings_decls.inc"
__attribute__((used, packed, aligned(4)))
UInt32 g_bindings_storage[280] __asm__("g_bindings") = {
#include "ui_shared_mp_g_bindings.inc"
}; /* 0x3121a0 */
#define g_bindings ((bind_t *)g_bindings_storage)

void LerpColor(vec_t *a, vec_t *b, vec_t *c, float t);
qboolean String_Parse(const char * *p, char *out, int len);
int Menu_ItemsMatchingGroup(menuDef_t *menu, const char *name);
itemDef_t * Menu_GetMatchingItemByNumber(menuDef_t *menu, int index, const char *name);
void Script_SetColor(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_SetBackground(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Menu_ShowItemByName(menuDef_t *menu, const char *p, qboolean bShow);
void Menu_FadeItemByName(menuDef_t *menu, const char *p, qboolean fadeOut);
menuDef_t * Menus_FindByName(displayContextDef_t *dc, const char *p);
void Script_Show(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_Hide(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_FadeIn(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_FadeOut(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_SetDvar(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ExecNow(displayContextDef_t *dc, itemDef_t *item, const char * *args);
static void Script_ConditionalExecHandler(int execWhen, Bool (*shouldExec)());
static void Script_ConditionalExecHandler_impl(int execWhen, Bool (*shouldExec)(const char *, const char *), const char **args);
static Bool Script_ExecIfStringsEqual(const char *dvarValue, const char *testValue);
static Bool Script_ExecIfIntsEqual(const char *dvarValue, const char *testValue);
static Bool Script_ExecIfFloatsEqual(const char *dvarValue, const char *testValue);
void Script_ExecOnDvarStringValue(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ExecOnDvarIntValue(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ExecOnDvarFloatValue(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ExecNowOnDvarStringValue(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ExecNowOnDvarIntValue(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ExecNowOnDvarFloatValue(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_Play(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_ScriptMenuResponse(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Item_RunScript(displayContextDef_t *dc, itemDef_t *item, const char *s);
void Controls_GetConfig(void);
void Controls_SetConfig(qboolean restart);
void Controls_SetDefaults(void);
void BindingFromName(const char *dvar, char *nameBind);
qboolean GetCommandHasBinding(const char *command);
int GetKeyBindings(const char *command, char (*bindings)[128]);
int GetKeyBindingLocalizedString(const char *command, char *keys);
qboolean Display_KeyBindPending(void);
int Menu_Count(displayContextDef_t *dc);
void UI_AddMenuList(displayContextDef_t *dc, MenuList *menuList);
void Item_MouseLeave(displayContextDef_t *dc, itemDef_t *item);
float Item_Slider_ThumbPosition(itemDef_t *item);
qboolean Menu_CheckOnKey(displayContextDef_t *dc, menuDef_t *menu, int key);
qboolean Menus_AnyFullScreenVisible(displayContextDef_t *dc);
menuDef_t * Menu_GetFocused(displayContextDef_t *dc);
int Item_ListBox_MaxScroll(itemDef_t *item);
int Item_ListBox_ThumbPosition(itemDef_t *item);
int Item_ListBox_ThumbDrawPosition(displayContextDef_t *dc, itemDef_t *item);
static void Scroll_Slider_SetThumbPos(void);
static void Scroll_Slider_ThumbFunc(displayContextDef_t *dc, void *p);
void Menus_Close(displayContextDef_t *dc, menuDef_t *menu);
void Menus_CloseAll(displayContextDef_t *dc);
void Item_SetTextExtents(itemDef_t *item, int *width, int *height, const char *text);
void Item_Text_AutoWrapped_Paint(itemDef_t *item, const char *textPtr, vec_t *color);
void Item_Text_Wrapped_Paint(itemDef_t *item, const char *textPtr, vec_t *color);
void Item_ListBox_Paint(displayContextDef_t *dc, itemDef_t *item);
editFieldDef_t *Item_GetEditFieldDef(itemDef_t *item);
const char *Dvar_GetVariantString(const char *dvarName);
void I_strncpyz(char *dest, const char *src, int destsize);
int Key_GetOverstrikeMode(void);
FontHandle UI_GetFontHandle(int fontEnum, float scale);
void UI_DrawText(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style);
void UI_DrawTextWithCursor(const char *text, int maxChars, FontHandle font, float x, float y, int horzAlign, int vertAlign, float scale, const vec_t *color, int style, int cursorPos, int cursor);
void Script_SetItemColor(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Window_Paint(displayContextDef_t *dc, float (*w)[4][32], float fadeAmount, float fadeInAmount, float fadeClamp, float fadeCycle);
void Menu_Setup(displayContextDef_t *dc);
void Menus_CloseByName(displayContextDef_t *dc, const char *p);
void Menu_SetFeederSelection(displayContextDef_t *dc, menuDef_t *menu, int feeder, int index, const char *name);
void Script_Exec(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Menu_TransitionItemByName(menuDef_t *menu, const char *p, rectDef_t rectFrom, rectDef_t rectTo, int time, float amt);
void Script_Transition(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Menu_OrbitItemByName(menuDef_t *menu, const char *p, float x, float y, float cx, float cy, int time);
void Script_Orbit(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_CloseForGameType(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_Close(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_InGameClose(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Item_TextColor(displayContextDef_t *dc, itemDef_t *item, vec4_t *newColor);
void Item_Text_Paint(displayContextDef_t *dc, itemDef_t *item);
void Item_TextField_Paint(displayContextDef_t *dc, itemDef_t *item);
void Item_YesNo_Paint(displayContextDef_t *dc, itemDef_t *item);
void Item_Slider_Paint(displayContextDef_t *dc, itemDef_t *item);
void Item_Bind_Paint(displayContextDef_t *dc, itemDef_t *item);
void Item_OwnerDraw_Paint(displayContextDef_t *dc, itemDef_t *item);
static void Item_List_Paint(itemDef_t *item, const char *text);
qboolean Item_Slider_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down);
qboolean Item_YesNo_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key);
qboolean Item_SetFocus(displayContextDef_t *dc, itemDef_t *item, float x, float y);
void Script_SetFocusByDvar(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_SetFocus(displayContextDef_t *dc, itemDef_t *item, const char * *args);
int Item_ListBox_OverLB(itemDef_t *item, float x, float y);
void Item_ListBox_MouseEnter(itemDef_t *item, float x, float y);
void Item_MouseEnter(displayContextDef_t *dc, itemDef_t *item, float x, float y);
qboolean Item_ListBox_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down, qboolean force);
static void Scroll_ListBox_ThumbFunc(displayContextDef_t *dc, void *p);
static void Scroll_ListBox_AutoFunc(displayContextDef_t *dc, void *p);
qboolean Item_Bind_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down);
qboolean Item_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down);
qboolean Menu_HandleMouseMove(displayContextDef_t *dc, menuDef_t *menu, float x, float y);
qboolean Display_MouseMove(displayContextDef_t *dc, void *p, int x, int y);
void Menus_Open(displayContextDef_t *dc, menuDef_t *menu);
qboolean Menus_OpenByName(displayContextDef_t *dc, const char *p);
void Script_Open(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_OpenForGameType(displayContextDef_t *dc, itemDef_t *item, const char * *args);
void Script_InGameOpen(displayContextDef_t *dc, itemDef_t *item, const char * *args);
itemDef_t * Menu_SetNextCursorItem(displayContextDef_t *dc, menuDef_t *menu);
itemDef_t * Menu_SetPrevCursorItem(displayContextDef_t *dc, menuDef_t *menu);
qboolean Item_TextField_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key);
void Menu_HandleKey(displayContextDef_t *dc, menuDef_t *menu, int key, qboolean down);
void Item_Paint(displayContextDef_t *dc, itemDef_t *item);
void Menu_Paint(displayContextDef_t *dc, menuDef_t *menu, qboolean forcePaint);
void Menu_PaintAll(displayContextDef_t *dc);
void Menus_HandleOOBClick(displayContextDef_t *dc, menuDef_t *menu, int key, qboolean down);

/* LerpColor — lerp 4-component color, clamp each to [0,1] */
void LerpColor(vec_t *a, vec_t *b, vec_t *c, float t)
{
    int i;
    for (i = 0; i < 4; i++) {
        float v = a[i] + (b[i] - a[i]) * t;
        if (v < 0.0f) v = 0.0f;
        else if (v > 1.0f) v = 1.0f;
        c[i] = v;
    }
}

/* String_Parse — parse next token from line, resolve @stringEd references */
qboolean String_Parse(const char * *p, char *out, int len)
{
    const char *token = Com_ParseOnLine(p);

    if (!*p)
        return 0;

    if (token[0] == '@') {
        const char *translated = SEH_StringEd_GetString(token + 1);
        if (translated) {
            I_strncpyz(out, translated, len);
            return 1;
        }
        if (!Dvar_GetBool("loc_warnings")) {
            /* fall through to copy raw token */
        } else if (Dvar_GetBool("loc_warningsAsErrors")) {
            Com_Error(6, "Could not translate menu string reference %s", token);
            /* fall through */
        } else {
            Com_Printf(0, "^3WARNING: Could not translate menu string reference %s\n", token);
            /* fall through */
        }
    }

    I_strncpyz(out, token, len);
    return 1;
}

/* Menu_ItemsMatchingGroup — count items with matching name or group */
int Menu_ItemsMatchingGroup(menuDef_t *menu, const char *name)
{
    int itemCount = menu->itemCount;
    const char *wc = strchr(name, '*');
    int wildcard = wc ? (int)(wc - name) : -1;
    int count = 0;
    int i;

    for (i = 0; i < itemCount; i++) {
        itemDef_t *item = menu->items[i];
        const char *itemName = item->window.name;
        const char *itemGroup = item->window.group;

        if (wildcard != -1) {
            if (itemName && I_strncmp(itemName, name, wildcard) == 0) { count++; continue; }
            if (itemGroup && I_strncmp(itemGroup, name, wildcard) == 0) { count++; continue; }
        } else {
            if (itemName && I_stricmp(itemName, name) == 0) { count++; continue; }
            if (itemGroup && I_stricmp(itemGroup, name) == 0) { count++; continue; }
        }
    }
    return count;
}

/* Menu_GetMatchingItemByNumber — return the index-th item with matching name or group */
itemDef_t * Menu_GetMatchingItemByNumber(menuDef_t *menu, int index, const char *name)
{
    int itemCount = menu->itemCount;
    const char *wc = strchr(name, '*');
    int wildcard = wc ? (int)(wc - name) : -1;
    int count = 0;
    int i;

    for (i = 0; i < itemCount; i++) {
        itemDef_t *item = menu->items[i];
        const char *itemName = item->window.name;
        const char *itemGroup = item->window.group;
        int matched = 0;

        if (wildcard != -1) {
            if ((itemName && I_strncmp(itemName, name, wildcard) == 0) ||
                (itemGroup && I_strncmp(itemGroup, name, wildcard) == 0))
                matched = 1;
        } else {
            if ((itemName && I_stricmp(itemName, name) == 0) ||
                (itemGroup && I_stricmp(itemGroup, name) == 0))
                matched = 1;
        }

        if (matched) {
            if (count == index)
                return item;
            count++;
        }
    }
    return NULL;
}

/* Script_SetColor — parse color target name and 4 floats, set item color */
void Script_SetColor(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    float *out = NULL;
    int i;
    (void)dc;

    if (!String_Parse(args, name, 0x400))
        return;

    if (I_stricmp(name, "backcolor") == 0) {
        out = item->window.backColor;
        Window_AddDynamicFlags((void *)item, 0x8000);
    } else if (I_stricmp(name, "forecolor") == 0) {
        out = item->window.foreColor;
        Window_AddDynamicFlags((void *)item, 0x10000);
    } else if (I_stricmp(name, "bordercolor") == 0) {
        out = item->window.borderColor;
    }

    if (!out)
        return;

    for (i = 0; i < 4; i++) {
        float f;
        if (!Float_Parse(args, &f))
            return;
        out[i] = f;
    }
}

/* Script_SetBackground — parse material name, register, set item background */
void Script_SetBackground(displayContextDef_t *dc, itemDef_t *item, const char **args)
{
    (void)dc;
    char name[0x400];
    if (String_Parse(args, name, 0x400)) {
        byte *it = (byte *)item;
        item->window.background = CL_RegisterMaterialNoMip(name);
    }
}

/* Menu_ShowItemByName — show/hide matching items by group name */
void Menu_ShowItemByName(menuDef_t *menu, const char *p, qboolean bShow)
{
    int count = Menu_ItemsMatchingGroup(menu, p);
    int i;
    for (i = 0; i < count; i++) {
        itemDef_t *item = Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;
        if (bShow) {
            Window_AddDynamicFlags(item, 4);
        } else {
            Window_RemoveDynamicFlags(item, 4);
            int cinHandle = item->window.cinematic;
            if (cinHandle >= 0) {
                CIN_StopCinematic(cinHandle);
                item->window.cinematic = -1;
            }
        }
    }
}

/* Menu_FadeItemByName — set fade in/out flags on matching items */
void Menu_FadeItemByName(menuDef_t *menu, const char *p, qboolean fadeOut)
{
    int count = Menu_ItemsMatchingGroup(menu, p);
    int i;
    for (i = 0; i < count; i++) {
        itemDef_t *item = Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;
        if (fadeOut) {
            Window_AddDynamicFlags(item, 0x14);  /* fade out + visible */
            Window_RemoveDynamicFlags(item, 0x20);
        } else {
            Window_AddDynamicFlags(item, 0x24);  /* fade in + visible */
            Window_RemoveDynamicFlags(item, 0x10);
        }
    }
}

/* Menus_FindByName — find menu by name (case-insensitive) */
menuDef_t * Menus_FindByName(displayContextDef_t *dc, const char *p)
{
    int count = dc->menuCount;
    int i;
    for (i = 0; i < count; i++) {
        menuDef_t *menu = dc->Menus[i];
        const char *menuName = menu->window.name;
        if (I_stricmp(menuName, p) == 0)
            return menu;
    }
    return NULL;
}

/* line 829 */
void Script_Show(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[1024];
    (void)dc;
    if (String_Parse(args, name, 1024)) {
        Menu_ShowItemByName(item->parent, name, 1);
    }
}

/* line 840 */
void Script_Hide(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[1024];
    (void)dc;
    if (String_Parse(args, name, 1024)) {
        Menu_ShowItemByName(item->parent, name, 0);
    }
}

/* line 851 */
void Script_FadeIn(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[1024];
    (void)dc;
    if (String_Parse(args, name, 1024)) {
        Menu_FadeItemByName(item->parent, name, 0);
    }
}

/* line 862 */
void Script_FadeOut(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[1024];
    (void)dc;
    if (String_Parse(args, name, 1024)) {
        Menu_FadeItemByName(item->parent, name, 1);
    }
}

/* Script_SetDvar — parse dvar name and value from args, set dvar */
extern void Dvar_SetFromStringByName(const char *name, const char *val);
void Script_SetDvar(displayContextDef_t *dc, itemDef_t *item, const char **args)
{
    (void)dc; (void)item;
    char dvarName[0x400], val[0x400];
    if (!String_Parse(args, dvarName, 0x400)) return;
    if (!String_Parse(args, val, 0x400)) return;
    Dvar_SetFromStringByName(dvarName, val);
}

/* Script_ExecNow — parse string from args, execute immediately via Cbuf_ExecuteText */
extern void Cbuf_ExecuteText(int execWhen, const char *text);
void Script_ExecNow(displayContextDef_t *dc, itemDef_t *item, const char **args)
{
    (void)dc; (void)item;
    char val[0x400];
    if (String_Parse(args, val, 0x400)) {
        Cbuf_ExecuteText(0, va("%s\n", val));
    }
}

/* line 1130 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void Script_ConditionalExecHandler(int execWhen, Bool (*shouldExec)())
{
    /* eax=execWhen, ecx=args, 8(%ebp)=shouldExec */
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl %ecx\n"        /* args */
        "pushl 8(%ebp)\n"     /* shouldExec */
        "pushl %eax\n"        /* execWhen */
        "calll Script_ConditionalExecHandler_impl\n"
        "addl $0xc, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#else
/* Register-convention trampoline: eax=execWhen, ecx=args, 8(%ebp)=shouldExec.
   In Emscripten mode, stub is never called - callers use _impl directly. */
static void Script_ConditionalExecHandler(int execWhen, Bool (*shouldExec)()) { (void)execWhen; (void)shouldExec; }
#endif

static void Script_ConditionalExecHandler_impl(int execWhen, Bool (*shouldExec)(const char *, const char *), const char **args)
{
    char dvarName[1024];
    char testValue[1024];
    char command[1024];

    if (!String_Parse(args, dvarName, 1024))
        return;
    if (!String_Parse(args, testValue, 1024))
        return;
    if (!String_Parse(args, command, 1024))
        return;

    {
        const char *dvarValue = Dvar_GetVariantString(dvarName);
        if (!shouldExec(dvarValue, testValue))
            return;
    }

    Cbuf_ExecuteText(execWhen, va("%s\n", command));
}

/* line 1146 */
static Bool Script_ExecIfStringsEqual(const char *dvarValue, const char *testValue)
{
    return I_stricmp(dvarValue, testValue) == 0;
}

/* line 1152 */
static Bool Script_ExecIfIntsEqual(const char *dvarValue, const char *testValue)
{
    return atoi(dvarValue) == atoi(testValue);
}

/* line 1158 */
static Bool Script_ExecIfFloatsEqual(const char *dvarValue, const char *testValue)
{
    float diff = (float)(atof(dvarValue) - atof(testValue));
    if (diff < 0) diff = -diff;
    return diff < 9.999999747378752e-06f;
}

/* line 1164 */
void Script_ExecOnDvarStringValue(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    (void)dc; (void)item;
    Script_ConditionalExecHandler_impl(2, Script_ExecIfStringsEqual, args);
}

/* line 1170 */
void Script_ExecOnDvarIntValue(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    (void)dc; (void)item;
    Script_ConditionalExecHandler_impl(2, Script_ExecIfIntsEqual, args);
}

/* line 1176 */
void Script_ExecOnDvarFloatValue(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    (void)dc; (void)item;
    Script_ConditionalExecHandler_impl(2, Script_ExecIfFloatsEqual, args);
}

/* line 1182 */
void Script_ExecNowOnDvarStringValue(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    (void)dc; (void)item;
    Script_ConditionalExecHandler_impl(0, Script_ExecIfStringsEqual, args);
}

/* line 1188 */
void Script_ExecNowOnDvarIntValue(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    (void)dc; (void)item;
    Script_ConditionalExecHandler_impl(0, Script_ExecIfIntsEqual, args);
}

/* line 1194 */
void Script_ExecNowOnDvarFloatValue(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    (void)dc; (void)item;
    Script_ConditionalExecHandler_impl(0, Script_ExecIfFloatsEqual, args);
}

/* line 1200 */
void Script_Play(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char val[1024];
    (void)dc; (void)item;
    if (String_Parse(args, val, 1024)) {
        UI_PlayLocalSoundAliasByName(val);
    }
}

/* Script_ScriptMenuResponse — find config string matching item's parent menu name, send mr command */
void Script_ScriptMenuResponse(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char val[0x400];
    byte *it = (byte *)item;
    int iIndex;
    (void)dc;

    if (!*(byte *)(*(byte **)imp_legacyHacks + 0x4ed)) /* TODO: unknown offset into legacyHacks */
        return;

    if (!String_Parse(args, val, 0x400))
        return;

    iIndex = -1;
    for (int i = 0; i < 0x20; i++) {
        const char *cs = CL_GetConfigString(0x4de + i);
        if (cs[0] == '\0')
            continue;
        /* item->parent->window.name */
        const char *menuName = item->parent->window.name;
        if (I_stricmp(menuName, cs) == 0) {
            iIndex = i;
            break;
        }
    }

    Cbuf_ExecuteText(2, va("cmd mr %i %i %s\n", Dvar_GetInt("sv_serverId"), iIndex, val));
}

/* Item_RunScript — parse and execute semicolon-separated script commands */
void Item_RunScript(displayContextDef_t *dc, itemDef_t *item, const char *s)
{
    char script[0x400];
    char command[0x400];
    const char *p;
    int i;

    memset(script, 0, 0x400);
    if (!item || !s || s[0] == '\0')
        return;

    I_strncat(script, 0x400, s);
    p = script;

    while (String_Parse(&p, command, 0x400)) {
        if (command[0] == ';') {
            if (command[1] == '\0')
                continue;
            /* fall through to command lookup */
        }

        /* Search registered script commands */
        for (i = 0; i < scriptCommandCount; i++) {
            if (I_stricmp(command, commandList[i].name) == 0) {
                commandList[i].handler(dc, item, &p);
                break;
            }
        }
        if (i >= scriptCommandCount)
            UI_RunMenuScript((const char *)&p);
    }
}

/* Controls_GetConfig — scan all keys for bindings matching g_bindings commands */
void Controls_GetConfig(void)
{
    int bi;
    char b[0x100];

    for (bi = 0; (byte *)&g_bindings[bi] != (byte *)updateScreenCalled; bi++) {
        const char *command = g_bindings[bi].command;
        int twokeys[2] = { -1, -1 };
        int count = 0;
        int j;

        for (j = 0; j < 0x100; j++) {
            Key_GetBindingBuf(j, b, 0x100);
            if (b[0] == '\0')
                continue;
            if (I_stricmp(b, command) != 0)
                continue;
            twokeys[count] = j;
            count++;
            if (count == 2)
                break;
        }

        g_bindings[bi].bind1 = twokeys[0];
        g_bindings[bi].bind2 = twokeys[1];
    }
}

/* Controls_SetConfig — iterate g_bindings, apply key bindings, exec bindingsave */
extern void Key_SetBinding(int key, const char *command);
extern byte szShotName[];
void Controls_SetConfig(qboolean restart)
{
    (void)restart;
    int i;
    for (i = 0; (byte *)&g_bindings[i].bind1 != szShotName + 8; i++) {
        if (g_bindings[i].bind1 != -1)
            Key_SetBinding(g_bindings[i].bind1, g_bindings[i].command);
        if (g_bindings[i].bind2 != -1)
            Key_SetBinding(g_bindings[i].bind2, g_bindings[i].command);
    }
    Cbuf_ExecuteText(2, "bindingsave\n");
}

/* line 4381 */
void Controls_SetDefaults(void)
{
    int bi;
    for (bi = 0; (byte *)&g_bindings[bi] != (byte *)updateScreenCalled; bi++) {
        g_bindings[bi].bind1 = g_bindings[bi].defaultbind1;
        g_bindings[bi].bind2 = g_bindings[bi].defaultbind2;
    }
}

/* BindingFromName — find key binding for a command name, format display string */
void BindingFromName(const char *dvar, char *nameBind)
{
    int i;
    for (i = 0; i < 0x38; i++) {
        if (I_stricmp(dvar, g_bindings[i].command) != 0)
            continue;

        int key1 = g_bindings[i].bind1;
        if (key1 == -1)
            break;

        Key_KeynumToStringBuf(key1, nameBind, 0x20);
        I_strncpyz(nameBind, UI_SafeTranslateString(nameBind), 0x80);

        int key2 = g_bindings[i].bind2;
        if (key2 == -1)
            return;

        char nameBind2[0x80];
        Key_KeynumToStringBuf(key2, nameBind2, 0x20);
        I_strncpyz(nameBind2, UI_SafeTranslateString(nameBind2), 0x80);
        I_strncat(nameBind, va(" %s ", UI_SafeTranslateString("KEY_OR")), 0x80);
        I_strncat(nameBind, nameBind2, 0x80);
        return;
    }

    I_strncpyz(nameBind, UI_SafeTranslateString("KEY_UNBOUND"), 0x80);
}

/* GetCommandHasBinding — check if command has a key binding in g_bindings[56] */
qboolean GetCommandHasBinding(const char *command)
{
    /* g_bindings: 20-byte entries, offset 0=command name, offset 12=key1, offset 16=key2 */
    int i;
    for (i = 0; i < 56; i++) {
        if (I_stricmp(command, g_bindings[i].command) == 0) {
            if (g_bindings[i].bind1 != -1)
                return 1;
        }
    }
    return 0;
}

/* GetKeyBindings — find key bindings for command, write key name strings */
int GetKeyBindings(const char *command, char (*bindings)[128])
{
    int i;
    bindings[0][0] = '\0';
    bindings[1][0] = '\0';

    for (i = 0; i < 0x38; i++) {
        if (I_stricmp(command, g_bindings[i].command) != 0)
            continue;

        int key1 = g_bindings[i].bind1;
        if (key1 == -1)
            break;

        Key_KeynumToStringBuf(key1, bindings[0], 0x80);

        int key2 = g_bindings[i].bind2;
        if (key2 == -1)
            return 1;

        Key_KeynumToStringBuf(key2, bindings[1], 0x80);
        return 2;
    }

    /* "KEY_UNBOUND" */
    *(int *)&bindings[0][0] = 0x5f59454b;
    *(int *)&bindings[0][4] = 0x4f424e55;
    *(int *)&bindings[0][8] = 0x00444e55;
    return 0;
}

/* GetKeyBindingLocalizedString — localized key binding display string */
int GetKeyBindingLocalizedString(const char *command, char *keys)
{
    char bindings[2][128];
    int bindCount = GetKeyBindings(command, bindings);

    if (bindCount == 0) {
        I_strncpyz(keys, UI_SafeTranslateString("KEY_UNBOUND"), 0x100);
        return bindCount;
    }

    const char *translated = SEH_StringEd_GetString(bindings[0]);
    if (translated)
        I_strncpyz(keys, translated, 0x100);
    else
        I_strncpyz(keys, bindings[0], 0x100);

    if (bindCount > 1) {
        I_strncat(keys, va(" %s ", UI_SafeTranslateString("KEY_OR")), 0x100);
        translated = SEH_StringEd_GetString(bindings[1]);
        if (translated)
            I_strncat(keys, translated, 0x100);
        else
            I_strncat(keys, bindings[1], 0x100);
    }

    return bindCount;
}

/* line 4722 */
qboolean Display_KeyBindPending(void)
{
    return g_waitingForKey;
}

/* line 5659 */
int Menu_Count(displayContextDef_t *dc)
{
    return dc->menuCount;
}

/* UI_AddMenuList — add all menus from a MenuList into the dc menu array */
void UI_AddMenuList(displayContextDef_t *dc, MenuList *menuList)
{
    int *menuCount = &dc->menuCount;
    int i;

    if (!menuList)
        return;
    if (menuList->menuCount <= 0)
        return;

    for (i = 0; i < menuList->menuCount; i++) {
        menuDef_t *menu = menuList->menus[i];
        if (*menuCount > 0x7f)
            Com_Error(1, "UI_AddMenu: Maximum number of menus %d exceeded.", 0x80);
        dc->Menus[*menuCount] = menu;
        *menuCount += 1;
    }
}

/* Item_MouseLeave — run mouse leave scripts, remove hover/focus dynamic flags */
void Item_MouseLeave(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    if (!item) return;
    if (((byte *)item->window.dynamicFlags)[0] & 0x40) {
        /* Has focus script — run it, remove focus flag */
        Item_RunScript(dc, item, item->mouseExitText);
        Window_RemoveDynamicFlags((void *)item, 0x40);
    }
    /* Run mouse leave script, remove hover+highlight flags */
    Item_RunScript(dc, item, item->mouseExit);
    Window_RemoveDynamicFlags((void *)item, 0x300);
}

/* Item_Slider_ThumbPosition — compute slider thumb x position from dvar value */
float Item_Slider_ThumbPosition(itemDef_t *item)
{
    byte *it = (byte *)item;
    editFieldDef_t *editDef = Item_GetEditFieldDef(item);
    float baseX, value, minVal, maxVal;

    if (!editDef)
        return 0.0f;

    if ((int)(uintptr_t)item->text)
        baseX = item->textRect[0].x + item->textRect[0].w + 8.0f;
    else
        baseX = item->window.rect[0].x;

    value = Dvar_GetFloat(item->dvar);
    minVal = editDef->minVal;
    maxVal = editDef->maxVal;

    if (value < minVal)
        value = minVal;
    else if (value > maxVal)
        value = maxVal;

    return baseX + 1.0f + 5.0f + ((value - minVal) / (maxVal - minVal)) * 84.0f;
}

/* Menu_CheckOnKey — check if key matches any menu or item onKey handler */
qboolean Menu_CheckOnKey(displayContextDef_t *dc, menuDef_t *menu, int key)
{
    byte tempItem[0x2a0];
    int i;

    /* Check menu-level onKey list at offset 0x250 */
    byte *node = (byte *)menu->onKey;
    while (node) {
        if (*(int *)node == key) {
            ((itemDef_t *)tempItem)->parent = (menuDef_t *)menu;
            Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(node + 4));
            return 1;
        }
        node = *(byte **)(node + 8);
    }

    /* Check per-item onKey lists */
    int itemCount = menu->itemCount;
    for (i = 0; i < itemCount; i++) {
        itemDef_t *item = menu->items[i];

        if (!(item->window.dynamicFlags[0] & 4))
            continue;

        if (item->dvarFlags & 0xc) {
            if (!Item_EnableShowViaDvar(item, 4))
                continue;
        }

        node = (byte *)item->onKey;
        while (node) {
            if (*(int *)node == key) {
                ((itemDef_t *)tempItem)->parent = (menuDef_t *)menu;
                Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(node + 4));
                return 1;
            }
            node = *(byte **)(node + 8);
        }
    }

    return 0;
}

/* Menus_AnyFullScreenVisible — check if any visible menu has fullscreen flag + material */
qboolean Menus_AnyFullScreenVisible(displayContextDef_t *dc)
{
    int count = dc->openMenuCount;
    int i;
    for (i = count - 1; i >= 0; i--) {
        menuDef_t *menu = dc->menuStack[i];
        if ((menu->window.dynamicFlags[0] & 4) && menu->fullScreen)
            return 1;
    }
    return 0;
}

/* Menu_GetFocused — find topmost visible+focused menu */
menuDef_t *Menu_GetFocused(displayContextDef_t *dc)
{
    int count = dc->openMenuCount;
    int i;
    for (i = count - 1; i >= 0; i--) {
        menuDef_t *menu = dc->menuStack[i];
        int flags = menu->window.dynamicFlags[0];
        if ((flags & 4) && (flags & 2))
            return menu;
    }
    return NULL;
}

/* Item_ListBox_MaxScroll — compute max scroll position based on item count and visible rows */
int Item_ListBox_MaxScroll(itemDef_t *item)
{
    listBoxDef_t *listPtr = Item_GetListBoxDef(item);
    int count = UI_FeederCount((int)item->special);
    if (!listPtr) return 0;
    int visibleRows;
    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* Horizontal */
        visibleRows = (int)(item->window.rect[0].w / listPtr->elementWidth);
    } else {
        /* Vertical */
        visibleRows = (int)(item->window.rect[0].h / listPtr->elementHeight);
    }
    int maxScroll = count - visibleRows + 1;
    return (maxScroll >= 0) ? maxScroll : 0;
}

/* Item_ListBox_ThumbPosition — compute listbox thumb position from scroll state */
int Item_ListBox_ThumbPosition(itemDef_t *item)
{
    listBoxDef_t *listPtr = Item_GetListBoxDef(item);
    int maxScroll, startPos;
    float scrollArea, ratio;

    if (!listPtr)
        return 0;

    maxScroll = Item_ListBox_MaxScroll(item);
    startPos = listPtr->startPos[0];

    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* Horizontal */
        scrollArea = item->window.rect[0].w - 32.0f - 2.0f;
        ratio = (maxScroll > 0) ? (scrollArea - 16.0f) / (float)maxScroll : 0.0f;
        return (int)(ratio * (float)startPos + item->window.rect[0].x + 1.0f + 16.0f);
    } else {
        /* Vertical */
        scrollArea = item->window.rect[0].h - 32.0f - 2.0f;
        ratio = (maxScroll > 0) ? (scrollArea - 16.0f) / (float)maxScroll : 0.0f;
        return (int)(ratio * (float)startPos + item->window.rect[0].y + 1.0f + 16.0f);
    }
}

/* Item_ListBox_ThumbDrawPosition — thumb draw position, clamped to drag cursor */
int Item_ListBox_ThumbDrawPosition(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;

    if ((itemDef_t *)item != itemCapture)
        return Item_ListBox_ThumbPosition(item);

    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* Horizontal */
        int max = (int)(item->window.rect[0].x + item->window.rect[0].w - 32.0f - 1.0f);
        int cursor = dc->cursorx;
        int minPos = (int)(item->window.rect[0].x + 16.0f + 1.0f) + 8;
        if (cursor < minPos || cursor > max + 8)
            return Item_ListBox_ThumbPosition((itemDef_t *)itemCapture);
        return cursor - 8;
    } else {
        /* Vertical */
        int max = (int)(item->window.rect[0].y + item->window.rect[0].h - 32.0f - 1.0f);
        int cursor = dc->cursory;
        int minPos = (int)(item->window.rect[0].y + 16.0f + 1.0f) + 8;
        if (cursor < minPos || cursor > max + 8)
            return Item_ListBox_ThumbPosition((itemDef_t *)itemCapture);
        return cursor - 8;
    }
}

/* line 2908 */
#ifndef __EMSCRIPTEN__
static __attribute__((naked))
void Scroll_Slider_SetThumbPos(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2908 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl %eax, %edi\n" /* dc */
        "movl %edx, %ebx\n" /* item */
        /* { scope 1 */
        "movl %edx, (%esp)\n" /* line 2921 */
        "calll Item_GetEditFieldDef\n"
        "movl %eax, %esi\n" /* editDef */
        "testl %eax, %eax\n" /* line 2923 */
        "je .Lf16520a_00165358\n"
        "movl 0x294(%ebx), %eax\n" /* line 2927 | item */
        "testl %eax, %eax\n"
        "je .Lf16520a_00165360\n"
        "movss 0x210(%ebx), %xmm1\n" /* line 2930 | item */
        "addss 0x218(%ebx), %xmm1\n" /* item */
        "addss lit4_002ed740, %xmm1\n" /* 8.0f */
        ".Lf16520a_0016524f:\n"
        "cvtsi2ssl 0xc(%edi), %xmm0\n" /* line 2937 | dc */
        "movss %xmm0, -0x1c(%ebp)\n" /* cursorx */
        "movl $4, 4(%esp)\n" /* line 2938 */
        "leal -0x1c(%ebp), %eax\n" /* cursorx */
        "movl %eax, (%esp)\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "calll CalcScreenX\n"
        "movss -0x48(%ebp), %xmm1\n" /* line 2940 */
        "addss lit4_002ed6d4, %xmm1\n" /* 5.0f */
        "addss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss %xmm1, -0x20(%ebp)\n" /* usableStart */
        "movl $0x42a80000, -0x24(%ebp)\n" /* line 2941 | usableWidth */
        "pxor %xmm4, %xmm4\n" /* line 2942 */
        "movss %xmm4, -0x28(%ebp)\n" /* yIgnored */
        "movss %xmm4, -0x2c(%ebp)\n" /* line 2943 | hIgnored */
        "movl 0x14(%ebx), %eax\n" /* line 2944 | item */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* item */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* hIgnored */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* usableWidth */
        "movl %eax, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* yIgnored */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* usableStart */
        "movl %eax, (%esp)\n"
        "movss %xmm4, -0x58(%ebp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x24(%ebp), %xmm3\n" /* line 2946 | usableWidth */
        "movss -0x1c(%ebp), %xmm0\n" /* cursorx */
        "subss -0x20(%ebp), %xmm0\n" /* usableStart */
        "movaps %xmm0, %xmm2\n" /* line 45 */
        "subss %xmm3, %xmm2\n"
        "movss -0x58(%ebp), %xmm4\n"
        "movaps %xmm3, %xmm1\n"
        "cmpnltss %xmm4, %xmm2\n"
        "andps %xmm2, %xmm1\n"
        "andnps %xmm0, %xmm2\n"
        "orps %xmm1, %xmm2\n"
        "movaps %xmm4, %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm2, %xmm0\n"
        "cmpltss %xmm4, %xmm1\n"
        "andps %xmm1, %xmm0\n"
        "andnps %xmm4, %xmm1\n"
        "orps %xmm0, %xmm1\n"
        "divss %xmm3, %xmm1\n" /* line 2947 */
        "movss (%esi), %xmm2\n" /* line 2948 | editDef */
        "movss 4(%esi), %xmm0\n" /* editDef */
        "subss %xmm2, %xmm0\n"
        "mulss %xmm0, %xmm1\n"
        "addss %xmm1, %xmm2\n" /* line 2950 */
        "cvtss2sd %xmm2, %xmm2\n"
        "movsd %xmm2, 4(%esp)\n"
        "movl $str_00217c20, (%esp)\n" /* "%g" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2c0(%ebx), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        /* } scope */
        ".Lf16520a_00165358:\n"
        "addl $0x6c, %esp\n" /* line 2951 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16520a_00165360:\n"
        "movss (%ebx), %xmm1\n" /* line 2934 | item */
        "jmp .Lf16520a_0016524f\n"
    );
}

/* Scroll_Slider_ThumbFunc — tail-call wrapper that must stay as inline ASM due to register convention */
static __attribute__((naked))
void Scroll_Slider_ThumbFunc(displayContextDef_t *dc, void *p)
{
    (void)dc; (void)p;
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n"
        "movl 0xc(%ebp), %edx\n"
        "movl 0x18(%edx), %edx\n"
        "popl %ebp\n"
        "jmp Scroll_Slider_SetThumbPos\n"
    );
}

/* Menus_Close — remove menu from open stack, run onClose script, re-focus */
void Menus_Close(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *d = (byte *)dc;
    int openCount, i, menuIndex;
    qboolean wasVisible = 0;
    byte tempItem[0x2a0];

    /* Check if menu was visible+focused before close */
    openCount = dc->openMenuCount;
    for (i = openCount - 1; i >= 0; i--) {
        if ((void *)dc->menuStack[i] == menu) {
            int flags = menu->window.dynamicFlags[0];
            if (flags & 4)
                wasVisible = (flags >> 1) & 1;
            break;
        }
    }

    /* Run onClose script if visible */
    int flags = menu->window.dynamicFlags[0];
    if ((flags & 4) && (void *)menu->onClose) {
        ((itemDef_t *)tempItem)->parent = (menuDef_t *)menu;
        Item_RunScript(dc, (itemDef_t *)tempItem, menu->onClose);
        openCount = dc->openMenuCount;
    }

    /* Remove menu from openMenus array */
    menuIndex = -1;
    for (i = openCount - 1; i >= 0; i--) {
        if ((void *)dc->menuStack[i] == menu) {
            menuIndex = i;
            break;
        }
    }
    if (menuIndex >= 0) {
        dc->openMenuCount = openCount - 1;
        /* Compact array */
        for (i = menuIndex; i < dc->openMenuCount; i++) {
            dc->menuStack[i] = dc->menuStack[i + 1];
        }
    }

    /* If the closed menu was visible+focused, re-focus the next visible menu */
    if (wasVisible && dc->openMenuCount > 0) {
        int menuNum = dc->openMenuCount - 1;
        for (i = menuNum; i >= 0; i--) {
            menuDef_t *m = dc->menuStack[i];
            if (m->window.dynamicFlags[0] & 4) {
                Window_AddDynamicFlags((itemDef_t *)m, 2);
                break;
            }
        }
    }

    /* Remove visible+focus flags from closed menu */
    Window_RemoveDynamicFlags((void *)menu, 6);
}

/* Menus_CloseAll — close every open menu */
void Menus_CloseAll(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    int count = dc->menuCount;
    int i;
    for (i = 0; i < count; i++) {
        Menus_Close(dc, (void *)dc->Menus[i]);
    }
}

/* Item_SetTextExtents — compute text width/height and position the text rect */
void Item_SetTextExtents(itemDef_t *item, int *width, int *height, const char *text)
{
    byte *it = (byte *)item;
    const char *textPtr = text;
    int originalWidth;

    /* Resolve text pointer */
    if (!textPtr) {
        textPtr = item->text;
        if (!textPtr) return;
        if (textPtr[0] == '@')
            textPtr = UI_SafeTranslateString(textPtr + 1);
    }

    /* Get initial text rect dimensions */
    *width = (int)item->textRect[0].w;
    *height = (int)item->textRect[0].h;

    /* Check if we need to compute text extents */
    if (*width != 0) {
        int itemType = item->type;
        if (itemType != 8 && !(void *)item->dvar)
            goto check_alignment;
        if (item->textalignment == 1)
            goto compute;
        check_alignment:
        if (item->textalignment == 3)
            goto compute;
        return;
    }

compute:;
    FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
    float scale = item->textscale;
    originalWidth = UI_TextWidth(textPtr, 0, font, scale);

    /* Add owner draw width for certain item types */
    int itemType = item->type;
    if (itemType == 8) {
        int alignment = item->textalignment;
        if (alignment == 1 || alignment == 2)
            originalWidth += UI_OwnerDrawWidth(item->window.ownerDraw, scale);
    } else if (itemType <= 0x12 && ((1 << itemType) & 0x70210)) {
        if (item->textalignment == 1 && (void *)item->dvar) {
            originalWidth += UI_TextWidth(Dvar_GetVariantString(item->dvar), 0, font, scale);
        }
    }

    /* Add label text width for alignment == 3 */
    if (item->textalignment == 3)
        originalWidth += UI_TextWidth(text, 0, font, scale);

    /* Compute final text extents */
    *width = UI_TextWidth(textPtr, 0, font, scale);
    *height = UI_TextHeight(font, scale);

    /* Build text rect */
    float textW = (float)*width;
    float textH = (float)*height;
    float textX = item->textalignx;
    float textY = item->textaligny;
    int horzAlign = item->window.rect[0].horzAlign;
    int vertAlign = item->window.rect[0].vertAlign;

    /* Adjust x based on text alignment */
    int alignment = item->textalignment;
    if (alignment == 2) {
        /* Right-aligned */
        textX -= (float)originalWidth;
    } else if (alignment == 1 || alignment == 3) {
        /* Center-aligned */
        textX -= (float)(originalWidth / 2);
    }

    /* Add border offset */
    if (item->window.border) {
        textX += item->window.borderSize;
        textY += item->window.borderSize;
    }

    /* Add item position */
    textX += item->window.rect[0].x;
    textY += item->window.rect[0].y;

    /* Set text rect: newRect = {textX, textY, textW, textH, horzAlign, vertAlign} */
    float newRect[6];
    newRect[0] = textX;
    newRect[1] = textY;
    newRect[2] = textW;
    newRect[3] = textH;
    *(int *)&newRect[4] = horzAlign;
    *(int *)&newRect[5] = vertAlign;
    ((void (*)(void *, void *))Item_SetTextRect)(item, newRect);
}

/* Item_Text_AutoWrapped_Paint — auto word-wrap text and paint line by line */
void Item_Text_AutoWrapped_Paint(itemDef_t *item, const char *textPtr, vec_t *color)
{
    byte *it = (byte *)item;
    char buff[0x400];
    FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
    float scale = item->textscale;
    int height = UI_TextHeight(font, scale);
    int textWidth = UI_TextWidth(textPtr, 0, font, scale);
    int style = item->textStyle;
    int horzAlign = item->window.rect[0].horzAlign;
    int vertAlign = item->window.rect[0].vertAlign;
    float *textRect = (float *)item->textRect;
    float lineHeight;
    int iTargetLineWidth;
    float y;
    int len, newLine, newLineWidth;
    const char *newLinePtr;
    const char *p;

    /* Determine target line width */
    float itemW = item->window.rect[0].w;
    if (itemW != 0.0f && (float)textWidth > itemW) {
        /* Text wider than item — compute number of lines and split evenly */
        int numLines = (int)ceilf((float)textWidth / itemW);
        iTargetLineWidth = (int)((float)textWidth / (float)numLines);
    } else {
        iTargetLineWidth = (int)itemW;
    }

    y = item->textaligny;
    buff[0] = '\0';
    lineHeight = (float)(height + 5);

    if (!textPtr) return;

    len = 0;
    newLine = 0;
    newLineWidth = 0;
    newLinePtr = NULL;
    p = textPtr;

    while (p) {
        unsigned char ch = *p;
        /* At word boundaries, save break point */
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0') {
            newLinePtr = p + 1;
            newLine = len;
            newLineWidth = textWidth;
        }

        /* Compute running text width */
        textWidth = UI_TextWidth(buff, 0, font, scale);

        /* Check if we need to break */
        int shouldBreak = 0;
        if (newLine) {
            if ((float)textWidth > item->window.rect[0].w)
                shouldBreak = 1;
        }
        if (ch == '\n' || ch == '\0')
            shouldBreak = 1;
        /* Also break on space if past target width */
        if (ch == ' ' && textWidth >= iTargetLineWidth)
            shouldBreak = 1;

        if (shouldBreak) {
            if (len > 0) {
                /* Build text rect for this line */
                float newTextRect[6];
                newTextRect[0] = *(float *)textRect;
                newTextRect[1] = *(float *)(textRect + 4);
                newTextRect[2] = *(float *)(textRect + 8);
                newTextRect[3] = ((UiRectangle *)textRect)->h;
                *(int *)&newTextRect[4] = ((UiRectangle *)textRect)->horzAlign;
                *(int *)&newTextRect[5] = ((UiRectangle *)textRect)->vertAlign;

                /* Compute x alignment */
                int alignment = item->textalignment;
                if (alignment == 1) {
                    newTextRect[0] = item->textalignx - (float)(newLineWidth / 2);
                } else if (alignment == 2) {
                    newTextRect[0] = item->textalignx + *(float *)(textRect + 8) - (float)newLineWidth;
                } else {
                    newTextRect[0] = item->textalignx;
                }
                newTextRect[1] = y;

                /* Add border offset */
                if (item->window.border) {
                    newTextRect[0] += item->window.borderSize;
                    newTextRect[1] += item->window.borderSize;
                }
                newTextRect[0] += item->window.rect[0].x;
                newTextRect[1] += item->window.rect[0].y;

                ((void (*)(void *, void *))Item_SetTextRect)(item, newTextRect);

                buff[newLine] = '\0';
                UI_DrawText(buff, 0x7fffffff, font,
                    *(float *)textRect, *(float *)(textRect + 4),
                    horzAlign, vertAlign, scale, color, style);
            }

            if (*p == '\0') break;

            y += lineHeight;
            p = newLinePtr;
            len = 0;
            newLine = 0;
            newLineWidth = 0;
            if (!p) break;
            continue;
        }

        /* Append character to buffer */
        buff[len] = ch;
        len++;
        p++;
        /* Replace \r with space */
        if (len > 0 && buff[len - 1] == '\r')
            buff[len - 1] = ' ';
        buff[len] = '\0';
    }
}

/* Item_Text_Wrapped_Paint — paint text with \r line breaks, per-line alignment */
void Item_Text_Wrapped_Paint(itemDef_t *item, const char *textPtr, vec_t *color)
{
    byte *it = (byte *)item;
    char buff[0x400];
    FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
    int height = UI_TextHeight(font, item->textscale);
    float scale = item->textscale;
    int style = item->textStyle;
    int horzAlign = item->window.rect[0].horzAlign;
    int vertAlign = item->window.rect[0].vertAlign;
    float *textRect = (float *)item->textRect;
    float y = *(float *)(textRect + 4);
    float lineHeight = (float)(height + 5);

    const char *p = strchr(textPtr, 0x0d);
    if (!p || p[0] == '\0') {
        /* No line breaks — draw entire text with alignment */
        float x;
        int alignment = item->textalignment;
        if (alignment == 1) {
            int tw = UI_TextWidth(textPtr, 0, font, scale);
            x = *(float *)textRect + (*(float *)(textRect + 8) - (float)tw) * 0.5f;
        } else if (alignment == 2) {
            int tw = UI_TextWidth(textPtr, 0, font, scale);
            x = *(float *)textRect + *(float *)(textRect + 8) - (float)tw;
        } else {
            x = *(float *)textRect;
        }
        UI_DrawText(textPtr, 0x7fffffff, font, x, y, horzAlign, vertAlign, scale, color, style);
        return;
    }

    /* Multi-line: split on \r and draw each line */
    const char *lineStart = textPtr;
    while (p && p[0] != '\0') {
        int lineLen = (int)(p - lineStart);
        strncpy(buff, lineStart, lineLen + 1);
        buff[lineLen] = '\0';

        /* Compute x based on alignment */
        float x;
        int alignment = item->textalignment;
        if (alignment == 1) {
            int tw = UI_TextWidth(buff, 0, font, scale);
            x = *(float *)textRect + (*(float *)(textRect + 8) - (float)tw) * 0.5f;
        } else if (alignment == 2) {
            int tw = UI_TextWidth(buff, 0, font, scale);
            x = *(float *)textRect + *(float *)(textRect + 8) - (float)tw;
        } else {
            x = *(float *)textRect;
        }

        UI_DrawText(buff, 0x7fffffff, font, x, y, horzAlign, vertAlign, scale, color, style);
        y += lineHeight;
        lineStart = p + 1 + lineLen + 1 - (lineLen + 1); /* Actually: lineStart = p + 1 */
        lineStart = p + 1;

        p = strchr(lineStart, 0x0d);
        if (!p || p[0] == '\0')
            break;
    }

    /* Draw remaining text after last \r */
    float x;
    int alignment = item->textalignment;
    if (alignment == 1) {
        int tw = UI_TextWidth(lineStart, 0, font, scale);
        x = *(float *)textRect + (*(float *)(textRect + 8) - (float)tw) * 0.5f;
    } else if (alignment == 2) {
        int tw = UI_TextWidth(lineStart, 0, font, scale);
        x = *(float *)textRect + *(float *)(textRect + 8) - (float)tw;
    } else {
        x = *(float *)textRect;
    }
    UI_DrawText(lineStart, 0x7fffffff, font, x, y, horzAlign, vertAlign, scale, color, style);
}

/* line 4837 */
void Item_ListBox_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    listBoxDef_t *listPtr;
    int count;
    float sizeH;
    int startPos;
    int i, j;
    int numColumns;
    MaterialHandle optionalImage;
    const char *text;
    float x, y;
    int horzAlign, vertAlign;

    listPtr = Item_GetListBoxDef(item);
    if (!listPtr)
        return;

    count = UI_FeederCount(item->special);

    horzAlign = item->window.rect[0].horzAlign;
    vertAlign = item->window.rect[0].vertAlign;

    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* ============ HORIZONTAL PATH ============ */
        float hx = item->window.rect[0].x + 1.0f;
        float hy_bottom = item->window.rect[0].y;
        hy_bottom = hy_bottom + item->window.rect[0].h - 16.0f - 1.0f;

        sharedUiInfo_t *sharedInfo = (sharedUiInfo_t *)imp_sharedUiInfo;

        /* Left arrow */
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            hx, hy_bottom, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBarArrowLeft);

        float trackX = hx + 15.0f;

        /* Horizontal track */
        float trackW = item->window.rect[0].w - 32.0f;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            trackX, hy_bottom, trackW + 1.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBar);

        /* Right arrow */
        float rightArrowX = trackW - 1.0f + trackX;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            rightArrowX, hy_bottom, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBarArrowRight);

        /* Thumb */
        int thumbPos = Item_ListBox_ThumbDrawPosition(dc, item);
        float thumbX = (float)thumbPos;
        float thumbMax = rightArrowX - 16.0f - 1.0f;
        if (thumbMax < thumbX)
            thumbX = thumbMax;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            thumbX, hy_bottom, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBarThumb);

        /* ListBox_SetEndPos */
        ListBox_SetEndPos((void *)listPtr, listPtr->startPos[0]);

        float size = item->window.rect[0].w - 2.0f;

        if (listPtr->elementStyle != 1)
            return;

        /* Horizontal items rendering */
        x = item->window.rect[0].x + 1.0f;
        y = item->window.rect[0].y + 1.0f;
        startPos = listPtr->startPos[0];
        i = startPos;

        while (i < count) {
            /* Get item image */
            MaterialHandle img = UI_FeederItemImage(item->special, i);
            if (img) {
                ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                    x + 1.0f, y + 1.0f,
                    listPtr->elementWidth - 2.0f,
                    listPtr->elementHeight - 2.0f,
                    horzAlign, vertAlign, 0, (int)(uintptr_t)img);
            }

            /* Selection highlight */
            if (i == item->cursorPos[0]) {
                UI_DrawRect(x, y,
                    listPtr->elementWidth - 1.0f,
                    listPtr->elementHeight - 1.0f,
                    horzAlign, vertAlign,
                    item->window.borderSize,
                    item->window.borderColor);
            }

            /* Check remaining size */
            size -= listPtr->elementWidth;
            if (listPtr->elementWidth > size) {
                listPtr->drawPadding = (int)size;
                return;
            }

            x += listPtr->elementWidth;
            ListBox_SetEndPos((void *)listPtr, listPtr->endPos[0] + 1);
            i++;
        }
        return;
    }

    /* ============ VERTICAL PATH ============ */
    ((void (*)(void *))UI_OverrideCursorPos)(item);

    numColumns = listPtr->numColumns;

    if (numColumns == 0) {
        /* --- No columns: draw vertical scrollbar on right side --- */
        float scrollX = item->window.rect[0].x;
        scrollX = scrollX + item->window.rect[0].w - 16.0f - 1.0f;

        float scrollY = item->window.rect[0].y + 1.0f;

        sharedUiInfo_t *sharedInfo = (sharedUiInfo_t *)imp_sharedUiInfo;

        /* Up arrow */
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, scrollY, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBarArrowUp);

        float trackY = scrollY + 15.0f;

        /* ListBox_SetEndPos */
        ListBox_SetEndPos((void *)listPtr, listPtr->startPos[0]);

        /* Vertical track */
        float trackH = item->window.rect[0].h - 32.0f;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, trackY, 16.0f, trackH + 1.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBar);

        /* Down arrow */
        float downArrowY = trackH - 1.0f + trackY;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, downArrowY, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBarArrowDown);

        /* Thumb */
        int thumbPos2 = Item_ListBox_ThumbDrawPosition(dc, item);
        float thumbY = (float)thumbPos2;
        float thumbMax2 = downArrowY - 16.0f - 1.0f;
        if (thumbMax2 < thumbY)
            thumbY = thumbMax2;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, thumbY, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, (int)sharedInfo->assets.scrollBarThumb);
    }

    /* --- Item rendering (both with and without columns) --- */
    sizeH = item->window.rect[0].h - 2.0f;

    if (listPtr->elementStyle == 1) {
        /* ===== drawPadding == 1: single item/image per row ===== */
        float ix = item->window.rect[0].x + 1.0f;
        float iy = item->window.rect[0].y + 1.0f;
        startPos = listPtr->startPos[0];

        if (count <= startPos)
            return;

        float ix2 = ix + 1.0f;
        i = startPos;

        while (i < count) {
            /* Get item image */
            MaterialHandle img2 = UI_FeederItemImage(item->special, i);
            if (img2) {
                ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                    ix2, iy + 1.0f,
                    listPtr->elementWidth - 2.0f,
                    listPtr->elementHeight - 2.0f,
                    horzAlign, vertAlign, 0, (int)(uintptr_t)img2);
            }

            /* Selection highlight */
            if (i == item->cursorPos[0]) {
                UI_DrawRect(ix, iy,
                    listPtr->elementWidth - 1.0f,
                    listPtr->elementHeight - 1.0f,
                    horzAlign, vertAlign,
                    item->window.borderSize,
                    item->window.borderColor);
            }

            /* Advance and check bounds */
            ListBox_SetEndPos((void *)listPtr, listPtr->endPos[0] + 1);
            sizeH -= listPtr->elementWidth;
            if (listPtr->elementHeight > sizeH) {
                listPtr->drawPadding = (int)(listPtr->elementHeight - sizeH);
                return;
            }
            iy += listPtr->elementHeight;
            i++;
        }
        return;
    }

    /* ===== drawPadding != 1: multi-column text rendering ===== */
    {
        float baseX = item->window.rect[0].x + 1.0f;
        y = item->window.rect[0].y + 1.0f;
        startPos = listPtr->startPos[0];

        if (count <= startPos)
            return;

        i = startPos;
        float preX4 = baseX + 4.0f;
        float preX2a = baseX + 2.0f;
        float preX2b = baseX + 2.0f;

        while (1) {
            int colCount = listPtr->numColumns;

            if (colCount > 0) {
                /* With columns */
                j = 0;
                while (j < listPtr->numColumns) {
                    /* Get text and optional image for this column */
                    text = UI_FeederItemText(item->special, i, j, &optionalImage);

                    if (optionalImage) {
                        /* Draw optional image */
                        float imgSize = (float)listPtr->columnInfo[j].width;
                        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                            (float)listPtr->columnInfo[j].pos + preX2b,
                            y + 3.0f,
                            imgSize, imgSize,
                            horzAlign, vertAlign, 0, (int)(uintptr_t)optionalImage);
                    } else if (text) {
                        /* Draw text */
                        float textScale = item->textscale;
                        FontHandle font = UI_GetFontHandle(item->fontEnum, textScale);
                        float drawX = (float)listPtr->columnInfo[j].pos + preX4 + item->textalignx;
                        float drawY = y + listPtr->elementHeight + item->textaligny;
                        UI_DrawText(text, listPtr->columnInfo[j].maxChars, font,
                            drawX, drawY,
                            horzAlign, vertAlign,
                            textScale,
                            item->window.foreColor,
                            item->textStyle);
                    }
                    j++;
                }
            } else {
                /* No columns — single text item */
                text = UI_FeederItemText(item->special, i, 0, &optionalImage);

                if (optionalImage) {
                    /* Draw optional image */
                    ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                        preX2a,
                        y + 2.0f,
                        listPtr->elementWidth - 4.0f,
                        listPtr->elementHeight - 4.0f,
                        horzAlign, vertAlign, 0, (int)(uintptr_t)optionalImage);
                } else if (text) {
                    /* Draw text */
                    float textScale2 = item->textscale;
                    FontHandle font2 = UI_GetFontHandle(item->fontEnum, textScale2);
                    float drawX2 = preX4;
                    float drawY2 = y + listPtr->elementHeight;
                    UI_DrawText(text, 0x7fffffff, font2,
                        drawX2, drawY2,
                        horzAlign, vertAlign,
                        textScale2,
                        item->window.foreColor,
                        item->textStyle);
                }
            }

            /* Selection highlight */
            if (i == item->cursorPos[0]) {
                UI_FillRect(preX2a, y + 2.0f,
                    item->window.rect[0].w - 16.0f - 4.0f,
                    listPtr->elementHeight,
                    horzAlign, vertAlign,
                    item->window.outlineColor);
            }

            /* Advance row */
            sizeH -= listPtr->elementHeight;
            if (listPtr->elementHeight > sizeH) {
                listPtr->drawPadding = (int)(listPtr->elementHeight - sizeH);
                return;
            }

            ListBox_SetEndPos((void *)listPtr, listPtr->endPos[0] + 1);
            y += listPtr->elementHeight;

            i++;
            if (i == count)
                return;
        }
    }
}

/* Script_SetItemColor — parse item group name, color target, 4 floats, apply to matching items */
void Script_SetItemColor(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char itemname[0x400];
    char name[0x400];
    float color[4];
    float f;
    int count, i, j;
    (void)dc;

    if (!String_Parse(args, itemname, 0x400))
        return;
    if (!String_Parse(args, name, 0x400))
        return;

    menuDef_t *parent = item->parent;
    count = Menu_ItemsMatchingGroup(parent, itemname);

    for (j = 0; j < 4; j++) {
        if (!Float_Parse(args, &f))
            return;
        color[j] = f;
    }

    for (i = 0; i < count; i++) {
        byte *item2 = (byte *)Menu_GetMatchingItemByNumber(parent, i, itemname);
        if (!item2) continue;

        float *out = NULL;
        if (I_stricmp(name, "backcolor") == 0) {
            out = ((itemDef_t *)item2)->window.backColor;
        } else if (I_stricmp(name, "forecolor") == 0) {
            out = ((itemDef_t *)item2)->window.foreColor;
            Window_AddDynamicFlags((void *)item2, 0x10000);
        } else if (I_stricmp(name, "bordercolor") == 0) {
            out = ((itemDef_t *)item2)->window.borderColor;
        }

        if (out) {
            out[0] = color[0];
            out[1] = color[1];
            out[2] = color[2];
            out[3] = color[3];
        }
    }
}

/* Window_Paint — draw window background, border, cinematic, and fade handling */
void Window_Paint(displayContextDef_t *dc, float (*w_param)[4][32], float fadeAmount, float fadeInAmount, float fadeClamp, float fadeCycle)
{
    byte *w = (byte *)w_param;
    float x, y, ww, hh;
    float color[4];
    int borderStyle, borderSizeFlag;
    int handle;

    /* Load rect from window struct */
    hh = ((Window *)w)->rect[0].h;
    ww = ((Window *)w)->rect[0].w;
    y  = ((Window *)w)->rect[0].y;
    x  = ((Window *)w)->rect[0].x;

    /* Debug mode: draw white outline */
    if (debugMode) {
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        UI_DrawRect(x, y, ww, hh,
            ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
            1.0f, color);
    }

    if (!w)
        return;

    borderStyle = ((Window *)w)->style;
    borderSizeFlag = ((Window *)w)->border;

    /* Determine whether to adjust rect by border size */
    if (borderStyle == 0 && borderSizeFlag == 0)
        return;

    if (borderSizeFlag != 0) {
        /* Adjust rect inward by border size */
        float bs = ((Window *)w)->borderSize;
        x += bs;
        y += bs;
        ww -= (bs + 1.0f);
        hh -= (bs + 1.0f);
    }

    /* Content drawing based on borderStyle (jump table) */
    if (borderStyle <= 7) {
        switch (borderStyle) {
        case 1: {
            /* Fade handling + background draw */
            int background = ((Window *)w)->background;
            if (background == 0) {
                /* No background: fill rect with foreColor */
                UI_FillRect(x, y, ww, hh,
                    ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
                    ((Window *)w)->backColor);
                break;
            }

            /* Fade logic */
            {
                int dynFlags = ((Window *)w)->dynamicFlags[0];
                int offsetTime = (int)fadeCycle;

                if (dynFlags & 0x30) {
                    int realtime = dc->realTime;
                    if (realtime > ((Window *)w)->nextTime) {
                        ((Window *)w)->nextTime = realtime + offsetTime;
                        if (dynFlags & 0x10) {
                            /* Fading out */
                            float fadeAlpha = ((Window *)w)->backColor[3] - fadeAmount;
                            ((Window *)w)->backColor[3] = fadeAlpha;
                            if (!(fadeAlpha > 0.0f)) {
                                dynFlags &= 0xffffffeb; /* clear bits 0x10 and 0x04 */
                            }
                        } else {
                            /* Fading in */
                            float fadeAlpha = ((Window *)w)->backColor[3] + fadeInAmount;
                            ((Window *)w)->backColor[3] = fadeAlpha;
                            if (!(fadeAlpha < fadeClamp)) {
                                ((Window *)w)->backColor[3] = fadeClamp;
                                dynFlags &= ~0x20; /* clear fade-in bit */
                            }
                        }
                    }
                }

                Window_SetDynamicFlags((itemDef_t *)w, dynFlags);
            }

            /* Draw background with foreColor */
            ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
                x, y, ww, hh,
                ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
                ((Window *)w)->backColor, ((Window *)w)->background);
            break;
        }

        case 3: {
            /* Draw with tiled flag check */
            float *fillColor = NULL;
            if (((byte *)&((Window*)w)->dynamicFlags)[2] & 1)
                fillColor = ((Window *)w)->foreColor;
            ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
                x, y, ww, hh,
                ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
                fillColor, ((Window *)w)->background);
            break;
        }

        case 5: {
            /* Cinematic */
            handle = ((Window *)w)->cinematic;
            if (handle == -1) {
                /* Start cinematic */
                int result = CIN_PlayCinematic(
                    (const char *)((Window *)w)->cinematicName,
                    (int)x, (int)y, (int)ww, (int)hh, 0x0a);
                if (result != -1)
                    handle = result;
                else
                    handle = -2;
                ((Window *)w)->cinematic = handle;
            }
            if (handle < 0)
                break;
            CIN_RunCinematic(handle);
            ((void (*)(int, int, int, int, int))CIN_SetExtents)(
                ((Window *)w)->cinematic, (int)x, (int)y, (int)ww, (int)hh);
            ((void (*)(int, int, int, int, int))CIN_DrawCinematic)(
                ((Window *)w)->cinematic, (int)x, (int)y, (int)ww, (int)hh);
            break;
        }

        case 6: {
            /* Background pic (no fade) */
            int background = ((Window *)w)->background;
            if (background == 0)
                break;
            {
                float *fillColor = NULL;
                if (((byte *)&((Window*)w)->dynamicFlags)[2] & 1)
                    fillColor = ((Window *)w)->foreColor;
                ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
                    x, y, ww, hh,
                    ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
                    fillColor, background);
            }
            break;
        }

        case 7: {
            /* Load bar */
            float *fillColor = NULL;
            if (((byte *)&((Window*)w)->dynamicFlags)[2] & 1)
                fillColor = ((Window *)w)->foreColor;
            ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawLoadBar)(
                x, y, ww, hh,
                ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
                fillColor, ((Window *)w)->background);
            break;
        }

        case 0:
        case 2:
        case 4:
        default:
            break;
        }
    }

    /* Border drawing based on borderSize */
    borderSizeFlag = ((Window *)w)->border;
    if (borderSizeFlag == 1) {
        /* UI_DrawRect border */
        float *borderColor;
        if (((Window *)w)->style == 4) {
            /* Shadow style: check borderColor[0] alpha for color selection */
            if (((Window *)w)->borderColor[0] > 0.0f) {
                /* Bright shadow */
                color[0] = 1.0f;
                color[1] = 0.5f;
                color[2] = 0.5f;
            } else {
                /* Dark shadow */
                color[0] = 0.5f;
                color[1] = 0.5f;
                color[2] = 1.0f;
            }
            color[3] = 1.0f;
            borderColor = color;
        } else {
            borderColor = ((Window *)w)->borderColor;
        }
        UI_DrawRect(
            ((Window *)w)->rect[0].x, ((Window *)w)->rect[0].y,
            ((Window *)w)->rect[0].w, ((Window *)w)->rect[0].h,
            ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
            ((Window *)w)->borderSize, borderColor);
    } else if (borderSizeFlag == 2) {
        /* UI_DrawTopBottom */
        ((void (*)(float, float, float, float, int, int, float, const vec_t *))UI_DrawTopBottom)(
            ((Window *)w)->rect[0].x, ((Window *)w)->rect[0].y,
            ((Window *)w)->rect[0].w, ((Window *)w)->rect[0].h,
            ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
            ((Window *)w)->borderSize, ((Window *)w)->borderColor);
        return;
    } else if (borderSizeFlag == 3) {
        /* UI_DrawSides */
        ((void (*)(float, float, float, float, int, int, float, const vec_t *))UI_DrawSides)(
            ((Window *)w)->rect[0].x, ((Window *)w)->rect[0].y,
            ((Window *)w)->rect[0].w, ((Window *)w)->rect[0].h,
            ((Window *)w)->rect[0].horzAlign, ((Window *)w)->rect[0].vertAlign,
            ((Window *)w)->borderSize, ((Window *)w)->borderColor);
        return;
    }
}

/* Menu_Setup — initialize menu system: clear menus, setup keyword hashes, load key bindings */
void Menu_Setup(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    dc->menuCount = 0;  /* menuCount = 0 */
    dc->openMenuCount = 0;  /* openMenuCount = 0 */
    Item_SetupKeywordHash();
    Menu_SetupKeywordHash();
    Controls_GetConfig();
}

/* Menus_CloseByName — find menu by name and close it */
void Menus_CloseByName(displayContextDef_t *dc, const char *p)
{
    menuDef_t *menu = Menus_FindByName(dc, p);
    if (menu)
        Menus_Close(dc, menu);
}

/* Menu_SetFeederSelection — set cursor/start position for items matching a feeder ID */
void Menu_SetFeederSelection(displayContextDef_t *dc, menuDef_t *menu, int feeder, int index, const char *name)
{
    byte *m;
    float feederFloat;
    int i, itemCount;

    if (!menu) {
        /* Resolve menu from name or focused menu */
        if (name) {
            menu = Menus_FindByName(dc, name);
        } else {
            menu = Menu_GetFocused(dc);
        }
        if (!menu)
            return;
    }

    m = (byte *)menu;
    itemCount = menu->itemCount;
    if (itemCount <= 0)
        return;

    feederFloat = (float)feeder;

    for (i = 0; i < itemCount; i++) {
        itemDef_t *item = menu->items[i];
        listBoxDef_t *listPtr;

        if (item->special != feederFloat)
            continue;

        listPtr = Item_GetListBoxDef(item);
        Item_SetCursorPos(item, index);
        UI_FeederSelection(item->special, item->cursorPos[0]);

        if (!listPtr)
            continue;

        if (index == 0) {
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        } else if (index < listPtr->startPos[0]) {
            ListBox_SetStartPos((itemDef_t *)listPtr, index);
        }
    }
}

/* Script_Exec — parse string, queue for execution via Cbuf_ExecuteText(2=EXEC_APPEND) */
void Script_Exec(displayContextDef_t *dc, itemDef_t *item, const char **args)
{
    (void)dc; (void)item;
    char val[0x400];
    if (String_Parse(args, val, 0x400)) {
        Cbuf_ExecuteText(2, va("%s\n", val));
    }
}

/* Menu_TransitionItemByName — set transition animation on matching items */
void Menu_TransitionItemByName(menuDef_t *menu, const char *p, rectDef_t rectFrom, rectDef_t rectTo, int time, float amt)
{
    int count = Menu_ItemsMatchingGroup(menu, p);
    int i;

    for (i = 0; i < count; i++) {
        itemDef_t *item = Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;

        Window_AddDynamicFlags(item, 0x84);
        Window_SetOffsetTime(item, time);
        ((void (*)(void *, void *))Window_SetRectClient)(item, &rectFrom);
        ((void (*)(void *, void *))Window_SetRectEffects0)(item, &rectTo);

        /* Compute step rect: copy item rect at 0x158, override first 4 floats with step values */
        rectDef_t newRect = item->window.rectEffects1[0];
        int dx = (int)(rectTo.x - rectFrom.x);
        newRect.x = (float)(dx < 0 ? -dx : dx) / amt;
        int dy = (int)(rectTo.y - rectFrom.y);
        newRect.y = (float)(dy < 0 ? -dy : dy) / amt;
        int dw = (int)(rectTo.w - rectFrom.w);
        newRect.w = (float)(dw < 0 ? -dw : dw) / amt;
        int dh = (int)(rectTo.h - rectFrom.h);
        newRect.h = (float)(dh < 0 ? -dh : dh) / amt;

        ((void (*)(void *, void *))Window_SetRectEffects1)(item, &newRect);

        /* Update screen coords from parent */
        menuDef_t *parent = item->parent;
        if (parent) {
            float px = parent->window.rect[0].x;
            float py = parent->window.rect[0].y;
            if (parent->window.border) {
                float borderSize = parent->window.borderSize;
                px += borderSize;
                py += borderSize;
            }
            ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                item, px, py, parent->window.rect[0].horzAlign, parent->window.rect[0].vertAlign);
        }
    }
}

/* Script_Transition — parse transition params and apply to item's parent menu */
void Script_Transition(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    rectDef_t rectFrom, rectTo;
    int time;
    float amt;
    (void)dc;

    if (!String_Parse(args, name, 0x400)) return;
    if (!Rect_Parse(args, &rectFrom)) return;
    if (!Rect_Parse(args, &rectTo)) return;
    if (!Int_Parse(args, &time)) return;
    if (!Float_Parse(args, &amt)) return;

    Menu_TransitionItemByName(item->parent, name, rectFrom, rectTo, time, amt);
}

/* Menu_OrbitItemByName — set orbit animation on matching items */
void Menu_OrbitItemByName(menuDef_t *menu, const char *p, float x, float y, float cx, float cy, int time)
{
    int count = Menu_ItemsMatchingGroup(menu, p);
    int i;

    for (i = 0; i < count; i++) {
        itemDef_t *item = Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;

        Window_AddDynamicFlags(item, 0x2004);
        Window_SetOffsetTime(item, time);

        /* Set effects0 rect: copy item rect at 0xf8 but override x/y with cx/cy */
        rectDef_t newRect;
        newRect = item->window.rectEffects0[0];
        newRect.x = cx;
        newRect.y = cy;
        /* Window_SetRectEffects0 takes (item, rectDef_t*) in the binary */
        ((void (*)(void *, void *))Window_SetRectEffects0)(item, &newRect);

        /* Set client rect: copy item rect at 0x60 but override x/y with x/y args */
        newRect = item->window.rectClient[0];
        newRect.x = x;
        newRect.y = y;
        ((void (*)(void *, void *))Window_SetRectClient)(item, &newRect);

        /* Update screen coords from parent */
        menuDef_t *parent = item->parent;
        if (parent) {
            float px = parent->window.rect[0].x;
            float py = parent->window.rect[0].y;
            if (parent->window.border)  {
                float borderSize = parent->window.borderSize;
                px += borderSize;
                py += borderSize;
            }
            ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                item, px, py, parent->window.rect[0].horzAlign, parent->window.rect[0].vertAlign);
        }
    }
}

/* Script_Orbit — parse orbit params and apply to item's parent menu */
void Script_Orbit(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    float x, y, cx, cy;
    int time;
    (void)dc;

    if (!String_Parse(args, name, 0x400)) return;
    if (!Float_Parse(args, &x)) return;
    if (!Float_Parse(args, &y)) return;
    if (!Float_Parse(args, &cx)) return;
    if (!Float_Parse(args, &cy)) return;
    if (!Int_Parse(args, &time)) return;

    Menu_OrbitItemByName(item->parent, name, x, y, cx, cy, time);
}

/* Script_CloseForGameType — close menu named with gametype dvar substitution */
void Script_CloseForGameType(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    (void)item;
    if (!String_Parse(args, name, 0x400))
        return;
    const char *p = va(name, Dvar_GetString(item->dvar));
    Menus_CloseByName(dc, p);
}

/* Script_Close — parse menu name, find and close it */
void Script_Close(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    (void)item;
    if (!String_Parse(args, name, 0x400))
        return;
    Menus_CloseByName(dc, name);
}

/* Script_InGameClose — close menu by name only if in-game */
void Script_InGameClose(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    (void)item;
    if (!String_Parse(args, name, 0x400))
        return;
    if (!UI_ClientIsInGame())
        return;
    Menus_CloseByName(dc, name);
}

/* Menus_Open — add menu to open stack, run onOpen script, stop cinematics, dispatch mouse */
void Menus_Open(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *d = (byte *)dc;
    byte *m = (byte *)menu;
    int openCount, i, j;
    byte tempItem[0x2a0];

    /* Remove focus flag from all currently open menus */
    openCount = dc->openMenuCount;
    for (i = openCount - 1; i >= 0; i--)
        Window_RemoveDynamicFlags((void *)dc->menuStack[i], 2);
    openCount = dc->openMenuCount;

    /* If menu is already in the open list, remove it first */
    int removeIdx = -1;
    for (i = openCount - 1; i >= 0; i--) {
        if ((void *)dc->menuStack[i] == menu) { removeIdx = i; break; }
    }
    if (removeIdx >= 0) {
        dc->openMenuCount = openCount - 1;
        for (i = removeIdx; i < dc->openMenuCount; i++)
            dc->menuStack[i] = dc->menuStack[i + 1];
    }
    if (dc->openMenuCount == 0x10)
        Com_Error(1, "\x15Too many menus opened");
    int idx = dc->openMenuCount;
    dc->menuStack[idx] = menu;
    dc->openMenuCount = idx + 1;
    Window_AddDynamicFlags((void *)menu, 6);
    if ((void *)menu->onOpen) {
        ((itemDef_t *)tempItem)->parent = (menuDef_t *)menu;
        Item_RunScript(dc, (itemDef_t *)tempItem, menu->onOpen);
    }
    if ((void *)menu->soundName)
        UI_PlayLocalSoundAliasByName(menu->soundName);
    openCount = dc->openMenuCount;
    for (i = openCount - 1; i >= 0; i--) {
        menuDef_t *om = dc->menuStack[i];
        if (!om) continue;
        if (om->window.style == 5) {
            int ch = om->window.cinematic;
            if (ch >= 0) { CIN_StopCinematic(ch); om->window.cinematic = -1; }
        }
        for (j = 0; j < om->itemCount; j++) {
            itemDef_t *it = om->items[j];
            if (it->window.style == 5) {
                int ch = it->window.cinematic;
                if (ch >= 0) { CIN_StopCinematic(ch); it->window.cinematic = -1; }
            }
            if (it->type == 8)
                CIN_StopCinematic(-it->window.ownerDraw);
        }
    }
    Display_MouseMove(dc, NULL, dc->cursorx, dc->cursory);
}

/* Menus_OpenByName — find menu by name and open it */
qboolean Menus_OpenByName(displayContextDef_t *dc, const char *p)
{
    menuDef_t *menu = Menus_FindByName(dc, p);
    if (menu) { Menus_Open(dc, menu); return 1; }
    return 0;
}

/* Script_Open — parse menu name, find and open it */
void Script_Open(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400]; (void)item;
    if (!String_Parse(args, name, 0x400)) return;
    Menus_OpenByName(dc, name);
}

/* Script_OpenForGameType — open menu named with gametype dvar substitution */
void Script_OpenForGameType(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    if (!String_Parse(args, name, 0x400)) return;
    const char *p = va(name, Dvar_GetString(item->dvar));
    Menus_OpenByName(dc, p);
}

/* Script_InGameOpen — open menu by name only if in-game */
void Script_InGameOpen(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400]; (void)item;
    if (!String_Parse(args, name, 0x400)) return;
    if (!UI_ClientIsInGame()) return;
    Menus_OpenByName(dc, name);
}

/* Display_MouseMove — handle mouse movement: reposition menu or dispatch to open menus */
qboolean Display_MouseMove(displayContextDef_t *dc, void *p, int x, int y)
{
    byte *d = (byte *)dc;
    if (p) {
        menuDef_t *menu = p;
        rectDef_t newRect = menu->window.rect[0];
        newRect.x += (float)x; newRect.y += (float)y;
        ((void (*)(void *, void *))Window_SetRect)(p, &newRect);
        ((void (*)(void *))Menu_UpdatePosition)(p);
        return 1;
    }
    int openCount = dc->openMenuCount;
    int i = openCount - 1;
    if (i < 0) return 1;
    int startIdx = i;
    for (; i >= 0; i--) {
        menuDef_t *menu = dc->menuStack[i];
        int flags = menu->window.dynamicFlags[0];
        if ((flags & 4) && (flags & 2)) {
            if (((byte *)&menu->window.staticFlags)[3] & 1) {
                Menu_HandleMouseMove(dc, menu, (float)x, (float)y);
                return 1;
            }
            startIdx = i; break;
        }
    }
    for (i = 0; i <= startIdx; i++) {
        menuDef_t *menu = dc->menuStack[startIdx - i];
        if (Menu_HandleMouseMove(dc, menu, (float)x, (float)y)) return 1;
    }
    return 1;
}

/* Menu_SetNextCursorItem — advance cursor to next focusable item, wrapping */
itemDef_t * Menu_SetNextCursorItem(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *m = (byte *)menu; byte *d = (byte *)dc;
    int oldCursor = menu->cursorItem[0]; int wrapped = 0; int cursor;
    if (oldCursor == -1) { ((void (*)(void *, int))Menu_SetCursorItem)(menu, 0); wrapped = 1; }
    for (;;) {
        cursor = menu->cursorItem[0];
        if (cursor >= menu->itemCount) {
            if (wrapped) return *(itemDef_t **)(menu->items + oldCursor * 4);
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, 0); wrapped = 1; cursor = menu->cursorItem[0];
        } else {
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, cursor + 1); cursor = menu->cursorItem[0];
            if (cursor >= menu->itemCount) {
                if (wrapped) return *(itemDef_t **)(menu->items + oldCursor * 4);
                ((void (*)(void *, int))Menu_SetCursorItem)(menu, 0); wrapped = 1; cursor = menu->cursorItem[0];
            }
        }
        itemDef_t *item = *(itemDef_t **)(menu->items + cursor * 4);
        if (Item_SetFocus(dc, item, (float)dc->cursorx, (float)dc->cursory)) {
            cursor = menu->cursorItem[0];
            item = *(itemDef_t **)(menu->items + cursor * 4);
            Menu_HandleMouseMove(dc, menu, item->window.rect[0].x + 1.0f, item->window.rect[0].y + 1.0f);
            cursor = menu->cursorItem[0];
            return *(itemDef_t **)(menu->items + cursor * 4);
        }
    }
    ((void (*)(void *, int))Menu_SetCursorItem)(menu, oldCursor); return NULL;
}

/* Menu_SetPrevCursorItem — move cursor to previous focusable item, wrapping */
itemDef_t * Menu_SetPrevCursorItem(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *m = (byte *)menu; byte *d = (byte *)dc;
    int oldCursor = menu->cursorItem[0]; int wrapped = 0; int cursor;
    if (oldCursor < 0) { ((void (*)(void *, int))Menu_SetCursorItem)(menu, menu->itemCount - 1); wrapped = 1; }
    for (;;) {
        cursor = menu->cursorItem[0];
        if (cursor <= -1) {
            if (wrapped) goto fail;
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, menu->itemCount - 1); wrapped = 1;
            cursor = menu->cursorItem[0]; if (cursor < 0) goto fail;
        } else {
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, cursor - 1); cursor = menu->cursorItem[0];
            if (cursor < 0) {
                if (wrapped) goto try_focus;
                ((void (*)(void *, int))Menu_SetCursorItem)(menu, menu->itemCount - 1); wrapped = 1;
                cursor = menu->cursorItem[0]; if (cursor < 0) goto fail;
            }
        }
try_focus:;
        itemDef_t *item = *(itemDef_t **)(menu->items + cursor * 4);
        if (Item_SetFocus(dc, item, (float)dc->cursorx, (float)dc->cursory)) {
            cursor = menu->cursorItem[0];
            item = *(itemDef_t **)(menu->items + cursor * 4);
            Menu_HandleMouseMove(dc, menu, item->window.rect[0].x + 1.0f, item->window.rect[0].y + 1.0f);
            cursor = menu->cursorItem[0];
            return *(itemDef_t **)(menu->items + cursor * 4);
        }
    }
fail: ((void (*)(void *, int))Menu_SetCursorItem)(menu, oldCursor); return NULL;
}

/* Item_TextColor — compute text color for an item: fade/pulse/focus/disable logic */
void Item_TextColor(displayContextDef_t *dc, itemDef_t *item, vec4_t *newColor)
{
    byte *it = (byte *)item;
    byte *parent = (byte *)item->parent;
    float *out = (float *)newColor;
    int flags = item->window.dynamicFlags[0];
    int curTime = dc->realTime;
    int i;

    /* Handle fade in/out timing */
    if (flags & 0x30) {
        int offsetTime = ((menuDef_t *)parent)->fadeCycle;
        float fadeAmount = ((menuDef_t *)parent)->fadeAmount;
        float fadeInAmount = ((menuDef_t *)parent)->fadeInAmount;
        float clamp = ((menuDef_t *)parent)->fadeClamp;

        if (curTime > item->window.nextTime) {
            item->window.nextTime = curTime + offsetTime;
            if (flags & 0x10) {
                /* Fade out */
                float alpha = item->window.foreColor[3];
                alpha -= fadeAmount;
                item->window.foreColor[3] = alpha;
                if (alpha <= 0.0f) {
                    flags &= ~0x14; /* clear fade out + visible */
                }
            } else {
                /* Fade in */
                float alpha = item->window.foreColor[3];
                alpha += fadeInAmount;
                item->window.foreColor[3] = alpha;
                if (alpha >= clamp) {
                    item->window.foreColor[3] = clamp;
                    flags &= ~0x20; /* clear fade in */
                }
            }
        }
    }

    Window_SetDynamicFlags(item, flags);

    /* Determine which color to use */
    int visFlags = item->window.dynamicFlags[0];
    if ((visFlags & 4) && (visFlags & 2)) {
        /* Item is visible + focused — pulse between focusColor and lowLight */
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = ((menuDef_t *)parent)->focusColor[i] * 0.8f;

        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = ((menuDef_t *)parent)->focusColor[i];
            float lo = lowLight[i];
            out[i] = hi + (lo - hi) * t;
            if (out[i] < 0.0f) out[i] = 0.0f;
            else if (out[i] > 1.0f) out[i] = 1.0f;
        }
    } else if (item->textStyle == 1) {
        /* Style 1 — pulse forecolor */
        int pulseTime = curTime;
        if (pulseTime < 0) pulseTime += 255;
        if (!(pulseTime & 0x100)) {
            /* Copy forecolor directly */
            for (i = 0; i < 4; i++)
                out[i] = item->window.foreColor[i];
        } else {
            float lowLight[4];
            for (i = 0; i < 4; i++)
                lowLight[i] = item->window.foreColor[i] * 0.8f;

            float t = sinf((float)(curTime / 22));
            t = t * 0.5f + 0.5f;

            for (i = 0; i < 4; i++) {
                float hi = item->window.foreColor[i];
                float lo = lowLight[i];
                out[i] = hi + (lo - hi) * t;
                if (out[i] < 0.0f) out[i] = 0.0f;
                else if (out[i] > 1.0f) out[i] = 1.0f;
            }
        }
    } else {
        /* Default — copy forecolor */
        for (i = 0; i < 4; i++)
            out[i] = item->window.foreColor[i];
    }

    /* Check dvar disable color override */
    const char *dvarTest = item->enableDvar;
    const char *dvarName = item->dvarTest;
    if (dvarTest && dvarTest[0] && dvarName && dvarName[0]) {
        if (((byte *)&item->dvarFlags)[0] & 3) {
            if (!Item_EnableShowViaDvar(item, 1)) {
                /* Disabled — use parent disableColor */
                for (i = 0; i < 4; i++)
                    out[i] = ((menuDef_t *)parent)->disableColor[i];
            }
        }
    }
}

/* Item_Text_Paint — paint text item with color, wrapping support */
void Item_Text_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    const char *textPtr = item->text;
    char text[0x400];
    float color[4];
    int width, height;

    /* Resolve text */
    if (!textPtr) {
        if (!(void *)item->dvar)
            return;
        I_strncpyz(text, Dvar_GetVariantString(item->dvar), 0x400);
        textPtr = text;
    }

    /* Handle @stringEd references */
    if (textPtr[0] == '@')
        textPtr = UI_SafeTranslateString(textPtr + 1);

    if (textPtr[0] == '\0')
        return;

    /* Compute color and text extents */
    Item_TextColor(dc, item, (vec4_t *)color);
    Item_SetTextExtents(item, &width, &height, textPtr);

    /* Check for wrapped text modes */
    int staticFlags = item->window.staticFlags;
    if (staticFlags & 0x400000) {
        Item_Text_Wrapped_Paint(item, textPtr, color);
        return;
    }
    if (staticFlags & 0x800000) {
        Item_Text_AutoWrapped_Paint(item, textPtr, color);
        return;
    }

    /* Normal text draw */
    FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
    UI_DrawText(textPtr, 0x7fffffff, font,
        item->textRect[0].x, item->textRect[0].y,
        item->window.rect[0].horzAlign, item->window.rect[0].vertAlign,
        item->textscale, color, item->textStyle);
}

/* line 4016 */
void Item_TextField_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    editFieldDef_t *editPtr;
    char buff[1024];
    vec4_t newColor;
    FontHandle font;
    const char *value;
    const char *text;
    int width;
    int height;
    int textLen;
    int paintOffset;
    int maxChars;
    int cursorPos;
    int cursorChar;
    float x;

    editPtr = Item_GetEditFieldDef(item);
    if (!editPtr) {
        return;
    }

    Item_Text_Paint(dc, item);

    buff[0] = '\0';
    if (item->dvar) {
        value = Dvar_GetVariantString(item->dvar);
        if (value) {
            I_strncpyz(buff, value, sizeof(buff));
        }
    }

    Item_SetTextExtents(item, &width, &height, buff);
    Item_TextColor(dc, item, &newColor);

    textLen = 0;
    while (textLen < (int)sizeof(buff) - 1 && buff[textLen] != '\0') {
        textLen++;
    }

    paintOffset = editPtr->paintOffset;
    if (paintOffset < 0) {
        paintOffset = 0;
    } else if (paintOffset > textLen) {
        paintOffset = textLen;
    }

    maxChars = editPtr->maxPaintChars;
    if (maxChars <= 0) {
        maxChars = 0x7fffffff;
    } else if (maxChars > (int)sizeof(buff) - 1 - paintOffset) {
        maxChars = (int)sizeof(buff) - 1 - paintOffset;
    }

    x = item->textRect[0].x + item->textRect[0].w;
    if (item->text && item->text[0]) {
        x += 8.0f;
    }

    text = buff + paintOffset;
    font = UI_GetFontHandle(item->fontEnum, item->textscale);
    if (!font) {
        return;
    }

    if (g_editingField && (item->window.staticFlags & 6) == 6) {
        cursorChar = Key_GetOverstrikeMode() == 1 ? '_' : '|';
        cursorPos = item->cursorPos[0] - paintOffset;
        if (cursorPos < -1) {
            cursorPos = -1;
        } else if (cursorPos > textLen - paintOffset) {
            cursorPos = textLen - paintOffset;
        }

        UI_DrawTextWithCursor(
            text,
            maxChars,
            font,
            x,
            item->textRect[0].y,
            item->window.rect[0].horzAlign,
            item->window.rect[0].vertAlign,
            item->textscale,
            newColor,
            item->textStyle,
            cursorPos,
            cursorChar);
        return;
    }

    UI_DrawText(
        text,
        maxChars,
        font,
        x,
        item->textRect[0].y,
        item->window.rect[0].horzAlign,
        item->window.rect[0].vertAlign,
        item->textscale,
        newColor,
        item->textStyle);
}

/* Item_YesNo_Paint — paint yes/no item with pulse color and translated text */
void Item_YesNo_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent = (byte *)item->parent;
    float newColor[4];
    float value = 0.0f;
    int i;

    /* Get dvar value */
    if ((void *)item->dvar) {
        value = (float)atof(Dvar_GetVariantString(item->dvar));
    }

    /* Compute color: focused items pulse, unfocused use forecolor */
    int flags = item->window.dynamicFlags[0];
    if ((flags & 4) && (flags & 2)) {
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = ((menuDef_t *)parent)->focusColor[i] * 0.8f;

        int curTime = dc->realTime;
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = ((menuDef_t *)parent)->focusColor[i];
            float lo = lowLight[i];
            newColor[i] = hi + (lo - hi) * t;
            if (newColor[i] < 0.0f) newColor[i] = 0.0f;
            else if (newColor[i] > 1.0f) newColor[i] = 1.0f;
        }
    } else {
        for (i = 0; i < 4; i++)
            newColor[i] = item->window.foreColor[i];
    }

    /* Choose yes/no text */
    const char *yesNoStr;
    if (value != 0.0f)
        yesNoStr = UI_SafeTranslateString("EXE_YES");
    else
        yesNoStr = UI_SafeTranslateString("EXE_NO");

    /* Draw the text */
    float *textRect = (float *)item->textRect;
    FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
    float textX, textY;

    if ((int)(uintptr_t)item->text) {
        /* Has label text — paint it first */
        Item_Text_Paint(dc, item);
        textX = item->textRect[0].x + item->textRect[0].w + 8.0f;
        textY = *(float *)(textRect + 4);
    } else {
        textX = item->textRect[0].x;
        textY = *(float *)(textRect + 4);
    }

    UI_DrawText(yesNoStr, 0x7fffffff, font, textX, textY,
        item->window.rect[0].horzAlign, item->window.rect[0].vertAlign,
        item->textscale, newColor, item->textStyle);
}

/* Item_Slider_Paint — paint slider bar and thumb */
extern void *imp_sharedUiInfo;
void Item_Slider_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent = (byte *)item->parent;
    float newColor[4];
    float y;
    float x;
    int i;

    /* Get dvar value (unused but called for side effects) */
    if ((void *)item->dvar) {
        Dvar_GetVariantString(item->dvar);
        atof(Dvar_GetVariantString(item->dvar));
    }

    /* Compute color: focused items pulse, others use forecolor */
    int flags = item->window.dynamicFlags[0];
    if ((flags & 4) && (flags & 2)) {
        /* Focused — compute pulsing color */
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = ((menuDef_t *)parent)->focusColor[i] * 0.8f;

        /* sin-based pulse: time / 22 (magic constant 0x1b4e81b5 = divide by 22) */
        int curTime = dc->realTime;
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = ((menuDef_t *)parent)->focusColor[i];
            float lo = lowLight[i];
            newColor[i] = hi + (lo - hi) * t;
            if (newColor[i] < 0.0f) newColor[i] = 0.0f;
            else if (newColor[i] > 1.0f) newColor[i] = 1.0f;
        }
    } else {
        /* Not focused — use forecolor */
        for (i = 0; i < 4; i++)
            newColor[i] = item->window.foreColor[i];
    }

    y = item->window.rect[0].y;

    if ((int)(uintptr_t)item->text) {
        /* Has text — paint text first, then slider starts after text rect */
        Item_Text_Paint(dc, item);
        x = item->textRect[0].x + item->textRect[0].w + 8.0f;
    } else {
        x = item->window.rect[0].x;
    }

    /* Draw slider bar — real signature: (x, y, w, h, horzAlign, vertAlign, color, material) */
    sharedUiInfo_t *sharedInfo = (sharedUiInfo_t *)imp_sharedUiInfo;
    ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
        x, y, 96.0f, 16.0f,
        item->window.rect[0].horzAlign, item->window.rect[0].vertAlign, newColor,
        (int)sharedInfo->assets.sliderBar);

    /* Draw slider thumb */
    float thumbX = Item_Slider_ThumbPosition(item);
    ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
        thumbX - 5.0f, y - 2.0f, 10.0f, 20.0f,
        item->window.rect[0].horzAlign, item->window.rect[0].vertAlign, newColor,
        (int)sharedInfo->assets.sliderThumb);
}

/* Item_Bind_Paint — paint key binding item with pulsing focus color */
void Item_Bind_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent = (byte *)item->parent;
    float newColor[4];
    int maxChars;
    int i;

    /* Get editFieldDef for maxChars */
    editFieldDef_t *editPtr = Item_GetEditFieldDef(item);
    if (!editPtr || !editPtr->maxPaintChars)
        return;
    maxChars = editPtr->maxPaintChars;

    /* Get dvar value (for side effects) */
    if ((void *)item->dvar) {
        atof(Dvar_GetVariantString(item->dvar));
    } else {
        /* waitingForKey mode: use special colors */
        if (g_waitingForKey) {
            newColor[0] = 0.8f;
            newColor[1] = 0.0f;
            newColor[2] = 0.0f;
            newColor[3] = 0.8f;
            goto draw;
        }
    }

    /* Compute color */
    int flags = item->window.dynamicFlags[0];
    if ((flags & 4) && (flags & 2)) {
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = ((menuDef_t *)parent)->focusColor[i] * 0.8f;

        int curTime = dc->realTime;
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = ((menuDef_t *)parent)->focusColor[i];
            float lo = lowLight[i];
            newColor[i] = hi + (lo - hi) * t;
            if (newColor[i] < 0.0f) newColor[i] = 0.0f;
            else if (newColor[i] > 1.0f) newColor[i] = 1.0f;
        }
    } else {
        for (i = 0; i < 4; i++)
            newColor[i] = item->window.foreColor[i];
    }

draw:;
    /* Paint text label first if present */
    float *textRect = (float *)item->textRect;
    if ((int)(uintptr_t)item->text) {
        Item_Text_Paint(dc, item);
        /* Draw bind text after label */
        float textX = item->textRect[0].x + item->textRect[0].w + 8.0f;
        float textY = *(float *)(textRect + 4);
        FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
        UI_DrawText("FIXME", maxChars, font, textX, textY,
            item->window.rect[0].horzAlign, item->window.rect[0].vertAlign,
            item->textscale, newColor, item->textStyle);
    } else {
        float textX = item->textRect[0].x;
        float textY = *(float *)(textRect + 4);
        FontHandle font = UI_GetFontHandle(item->fontEnum, item->textscale);
        UI_DrawText("FIXME", maxChars, font, textX, textY,
            item->window.rect[0].horzAlign, item->window.rect[0].vertAlign,
            item->textscale, newColor, item->textStyle);
    }
}

/* Item_OwnerDraw_Paint — paint owner-draw item with fade, color, and UI_OwnerDraw dispatch */
void Item_OwnerDraw_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent;
    float color[4];
    int flags, i;

    if (!item) return;

    parent = (byte *)item->parent;
    flags = item->window.dynamicFlags[0];

    /* Fade handling */
    float fadeInAmount = ((menuDef_t *)parent)->fadeInAmount;
    float fadeAmount = ((menuDef_t *)parent)->fadeAmount;
    int offsetTime = ((menuDef_t *)parent)->fadeCycle;
    float clamp = ((menuDef_t *)parent)->fadeClamp;
    int curTime = dc->realTime;

    if (flags & 0x30) {
        if (curTime > item->window.nextTime) {
            item->window.nextTime = curTime + offsetTime;
            if (flags & 0x10) {
                float alpha = item->window.foreColor[3] - fadeAmount;
                item->window.foreColor[3] = alpha;
                if (alpha <= 0.0f)
                    flags &= ~0x14;
            } else {
                float alpha = item->window.foreColor[3] + fadeInAmount;
                item->window.foreColor[3] = alpha;
                if (alpha >= clamp) {
                    item->window.foreColor[3] = clamp;
                    flags &= ~0x20;
                }
            }
        }
    }

    Window_SetDynamicFlags(item, flags);

    /* Start with forecolor */
    for (i = 0; i < 4; i++)
        color[i] = item->window.foreColor[i];

    /* Check for focus/pulse color */
    int visFlags = item->window.dynamicFlags[0];
    if ((visFlags & 4) && (visFlags & 2)) {
        /* Focused — pulse between focusColor and lowLight */
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = ((menuDef_t *)parent)->focusColor[i] * 0.8f;
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;
        for (i = 0; i < 4; i++) {
            float hi = ((menuDef_t *)parent)->focusColor[i];
            color[i] = hi + (lowLight[i] - hi) * t;
            if (color[i] < 0.0f) color[i] = 0.0f;
            else if (color[i] > 1.0f) color[i] = 1.0f;
        }
    } else if (item->textStyle == 1) {
        /* Style 1 — pulse forecolor */
        int pt = curTime;
        if (pt < 0) pt += 255;
        if (pt & 0x100) {
            float lowLight[4];
            for (i = 0; i < 4; i++)
                lowLight[i] = item->window.foreColor[i] * 0.8f;
            float t = sinf((float)(curTime / 22));
            t = t * 0.5f + 0.5f;
            for (i = 0; i < 4; i++) {
                float hi = item->window.foreColor[i];
                color[i] = hi + (lowLight[i] - hi) * t;
                if (color[i] < 0.0f) color[i] = 0.0f;
                else if (color[i] > 1.0f) color[i] = 1.0f;
            }
        }
    }

    /* Dvar disable color check */
    if (((byte *)&item->dvarFlags)[0] & 3) {
        if (!Item_EnableShowViaDvar(item, 1)) {
            for (i = 0; i < 4; i++)
                color[i] = ((menuDef_t *)parent)->disableColor[i];
        }
    }

    /* Draw */
    float scale = item->textscale;
    int style = item->textStyle;
    int ownerDraw = item->window.ownerDraw;
    int ownerDrawFlags = item->window.ownerDrawFlags;
    int cursor = item->alignment;
    float feederFloat = item->special;
    int material = item->window.background;
    FontHandle font = UI_GetFontHandle(item->fontEnum, scale);

    if ((int)(uintptr_t)item->text && ((const char *)(int)(uintptr_t)item->text)[0]) {
        /* Has text label — paint text first */
        Item_Text_Paint(dc, item);
        float *textRect = (float *)item->textRect;
        float ownerX = item->textRect[0].x + *(float *)(textRect + 8) + 8.0f;
        UI_OwnerDraw(ownerX, item->window.rect[0].y, item->window.rect[0].w, item->window.rect[0].h,
            item->window.rect[0].horzAlign, item->window.rect[0].vertAlign, 0.0f, item->textaligny,
            ownerDraw, ownerDrawFlags, scale, color, (MaterialHandle)(intptr_t)material, style);
    } else if ((int)(uintptr_t)item->text) {
        /* Has text pointer but empty — use textRect x + w offset */
        float *textRect = (float *)item->textRect;
        float ownerX = item->textRect[0].x + *(float *)(textRect + 8);
        UI_OwnerDraw(ownerX, item->window.rect[0].y, item->window.rect[0].w, item->window.rect[0].h,
            item->window.rect[0].horzAlign, item->window.rect[0].vertAlign, 0.0f, item->textaligny,
            ownerDraw, ownerDrawFlags, scale, color, (MaterialHandle)(intptr_t)material, style);
    } else {
        /* No text — use item position directly */
        UI_OwnerDraw(item->window.rect[0].x, item->window.rect[0].y, item->window.rect[0].w, item->window.rect[0].h,
            item->window.rect[0].horzAlign, item->window.rect[0].vertAlign, item->textalignx, item->textaligny,
            ownerDraw, ownerDrawFlags, scale, color, (MaterialHandle)(intptr_t)material, style);
    }
}

/* line 4133 */
static __attribute__((naked))
void Item_List_Paint(itemDef_t *item, const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4133 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        "movl %eax, %esi\n" /* dc */
        "movl %edx, -0x58(%ebp)\n"
        "movl %ecx, -0x5c(%ebp)\n"
        /* { scope 1 */
        "movl 0xe8(%edx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf169674_00169785\n"
        "testb $2, %al\n" /* line 4140 */
        "je .Lf169674_00169782\n"
        "movl 0x29c(%edx), %eax\n" /* line 4143 */
        "leal 0x25c(%eax), %ebx\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 519 | 0.800000011920929f */
        "movss 0x25c(%eax), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* lowLight */
        "movss 4(%ebx), %xmm1\n" /* line 520 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss 8(%ebx), %xmm1\n" /* line 521 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 0xc(%ebx), %xmm0\n" /* line 522 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 4(%esi), %ecx\n" /* line 4144 | dc */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x7c(%ebp)\n"
        "movss -0x7c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "movl $1, %edx\n"
        "leal -0x38(%ebp), %ecx\n" /* lowLight */
        "pxor %xmm3, %xmm3\n"
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        /* { scope 2 */
        ".Lf169674_00169739:\n"
        "movss -4(%ebx, %edx, 4), %xmm0\n" /* line 94 */
        "leal (, %edx, 4), %eax\n"
        "movss -4(%ecx, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal -0x28(%ebp), %edi\n" /* line 4133 | newColor */
        "leal (%edi, %eax), %eax\n"
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm3\n" /* line 95 */
        "ja .Lf169674_00169881\n"
        "ucomiss %xmm4, %xmm1\n" /* line 97 */
        "jbe .Lf169674_00169778\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf169674_00169778:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf169674_00169739\n"
        "jmp .Lf169674_001697a9\n"
        ".Lf169674_00169782:\n"
        "movl -0x58(%ebp), %edx\n"
        /* } scope */
        ".Lf169674_00169785:\n"
        "addl $0x1cc, %edx\n" /* line 4148 */
        "movl -0x58(%ebp), %ecx\n"
        "movl 0x1cc(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* newColor */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf169674_001697a9:\n"
        "movl -0x5c(%ebp), %edi\n" /* line 4151 | textRect */
        "cmpb $0x40, (%edi)\n" /* textRect */
        "je .Lf169674_00169925\n"
        ".Lf169674_001697b5:\n"
        "movl -0x58(%ebp), %edi\n" /* line 99 */
        "addl $0x210, %edi\n"
        "movl -0x58(%ebp), %eax\n" /* line 4156 */
        "movl 0x294(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf169674_0016988d\n"
        "movl %eax, 4(%esp)\n" /* line 4158 */
        "movl %esi, (%esp)\n" /* dc */
        "calll Item_Text_Paint\n"
        "movl -0x58(%ebp), %edx\n" /* line 4159 */
        "movl 0x290(%edx), %esi\n" /* dc */
        "movl 0x28c(%edx), %ebx\n"
        "movl 0x14(%edx), %ecx\n"
        "movl %ecx, -0x3c(%ebp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movss 4(%edi), %xmm0\n" /* textRect */
        "movss %xmm0, -0x44(%ebp)\n"
        "movss 0x210(%edx), %xmm0\n"
        "addss 8(%edi), %xmm0\n" /* textRect */
        "addss lit4_002ed740, %xmm0\n" /* 8.0f */
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0x78(%ebp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x24(%esp)\n" /* line 4159 | dc */
        "leal -0x28(%ebp), %edx\n" /* newColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, 0x18(%esp)\n"
        "movl -0x40(%ebp), %edi\n" /* textRect */
        "movl %edi, 0x14(%esp)\n" /* textRect */
        "movss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0x78(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n" /* line 4163 */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 4165 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf169674_00169881:\n"
        "movl $0, -4(%eax)\n" /* line 96 */
        "jmp .Lf169674_00169778\n"
        ".Lf169674_0016988d:\n"
        "movl %eax, %edx\n"
        /* } scope */
        "movl 0x290(%eax), %esi\n" /* line 4163 | dc */
        "movl 0x28c(%eax), %ebx\n"
        "movl 0x14(%eax), %ecx\n"
        "movl %ecx, -0x54(%ebp)\n"
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movss 4(%edi), %xmm0\n" /* textRect */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movss 0x210(%edx), %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x24(%esp)\n" /* line 4163 | dc */
        "leal -0x28(%ebp), %edx\n" /* newColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl -0x54(%ebp), %ecx\n"
        "movl %ecx, 0x18(%esp)\n"
        "movl -0x50(%ebp), %edi\n" /* textRect */
        "movl %edi, 0x14(%esp)\n" /* textRect */
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x48(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0xac, %esp\n" /* line 4165 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf169674_00169925:\n"
        "movl %edi, %eax\n" /* line 4152 | textRect */
        "addl $1, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %eax, -0x5c(%ebp)\n"
        "jmp .Lf169674_001697b5\n"
    );
}

/* Item_Slider_HandleKey — handle mouse click/arrow keys for slider items */
extern const char *Dvar_GetVariantString(const char *dvarName);
qboolean Item_Slider_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;

    /* Basic checks: must have dvar, be visible+focused */
    if (!(void *)item->dvar)
        return 0;
    if (!(((byte *)item->window.dynamicFlags)[0] & 4) || !(((byte *)item->window.dynamicFlags)[0] & 2))
        return 0;

    /* Mouse click (keys 0xc8-0xca) — check if within item bounds */
    if (key >= 0xc8 && key <= 0xca) {
        float cx = (float)dc->cursorx;
        float cy = (float)dc->cursory;
        /* Rect-in-rect test with screen placement */
        float rx = item->window.rect[0].x, ry = item->window.rect[0].y;
        float rw = item->window.rect[0].w, rh = item->window.rect[0].h;
        CalcScreenX(&cx, 4);
        CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
        if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh)
            return 0;
        /* Fall through to handle as slider drag */
    }

    /* Mouse drag — set thumb position */
    if (key >= 0xc8 && key <= 0xca) {
        __asm__ __volatile__ (
            "movl %0, %%edx\n"
            "movl %1, %%eax\n"
            "calll Scroll_Slider_SetThumbPos\n"
            : : "r"(item), "r"(dc) : "eax", "ecx", "edx", "memory"
        );
        return 1;
    }

    /* Arrow keys — adjust value by step */
    editFieldDef_t *editDef = Item_GetEditFieldDef(item);
    if (!editDef)
        return 0;

    float maxVal = editDef->maxVal;
    float minVal = editDef->minVal;
    float step = (maxVal - minVal) * 0.05f;

    const char *valStr = Dvar_GetVariantString(item->dvar);
    float value = (float)atof(valStr);

    if (key == 0x9c || key == 0xa4) {
        /* Left arrow — decrease */
        value -= step;
        if (value < minVal) value = minVal;
    } else if (key == 0x9d || key == 0xa3) {
        /* Right arrow — increase */
        value += step;
        if (value > maxVal) value = maxVal;
    } else {
        return 0;
    }

    Dvar_SetFromStringByName(item->dvar, va("%g", (double)value));
    return 1;
}

/* Item_YesNo_HandleKey — toggle yes/no dvar on click or key press */
qboolean Item_YesNo_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;
    char dvarString[0x19];

    if (!(void *)item->dvar)
        return 0;
    if (!(((byte *)item->window.dynamicFlags)[0] & 4) || !(((byte *)item->window.dynamicFlags)[0] & 2))
        return 0;

    /* Mouse click — check if within item rect */
    if (key >= 0xc8 && key <= 0xca) {
        float cx = (float)dc->cursorx;
        float cy = (float)dc->cursory;
        float rx = item->window.rect[0].x, ry = item->window.rect[0].y;
        float rw = item->window.rect[0].w, rh = item->window.rect[0].h;
        CalcScreenX(&cx, 4);
        CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
        if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh)
            return 0;
        /* Fall through to toggle */
    } else if (key != 0xd && key != 0x9c && key != 0x9d && key != 0xa4 && key != 0xa3 &&
               key != 0xc8 && key != 0xc9 && key != 0xca) {
        return 0;
    }

    /* Toggle the dvar value */
    I_strncpyz(dvarString, Dvar_GetVariantString(item->dvar), 0x19);
    int val = atoi(dvarString);
    Dvar_SetFromStringByName(item->dvar, va("%i", !val));
    return 1;
}

/* Item_SetFocus — set focus to an item: unfocus all siblings, run scripts, play sound */
extern void UI_PlayLocalSoundAlias(int sound);
qboolean Item_SetFocus(displayContextDef_t *dc, itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;
    int i;

    int defaultSound = (int)((sharedUiInfo_t *)imp_sharedUiInfo)->assets.itemFocusSound;

    /* Validation */
    if (!item) return 0;
    if (((byte *)&item->window.staticFlags)[2] & 0x10) return 0; /* disabled */
    int flags = item->window.dynamicFlags[0];
    if (!(flags & 4)) return 0; /* not visible */
    if (flags & 2) return 1; /* already focused */

    /* Get parent menu */
    byte *parent = (byte *)item->parent;

    /* If parent exists but is not visible+focused, find the focused menu */
    if (parent) {
        int pflags = ((menuDef_t *)parent)->window.dynamicFlags[0];
        if (!(pflags & 4) || !(pflags & 2)) {
            /* Find focused menu from open menus */
            byte *focusedMenu = NULL;
            int openCount = dc->openMenuCount;
            for (i = openCount - 1; i >= 0; i--) {
                byte *om = (byte *)dc->menuStack[i];
                int omf = ((menuDef_t *)om)->window.dynamicFlags[0];
                if ((omf & 4) && (omf & 2)) { focusedMenu = om; break; }
            }
            if (!focusedMenu) goto check_dvar;

            /* Hit test cursor against focused menu rect */
            float rx = ((menuDef_t *)focusedMenu)->window.rect[0].x, ry = ((menuDef_t *)focusedMenu)->window.rect[0].y;
            float rw = ((menuDef_t *)focusedMenu)->window.rect[0].w, rh = ((menuDef_t *)focusedMenu)->window.rect[0].h;
            float cx = x, cy = y;
            CalcScreenX(&cx, 4);
            CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, ((menuDef_t *)focusedMenu)->window.rect[0].horzAlign, ((menuDef_t *)focusedMenu)->window.rect[0].vertAlign);
            if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh)
                goto check_dvar;

            /* Also hit test parent rect */
            float prx = ((menuDef_t *)parent)->window.rect[0].x, pry = ((menuDef_t *)parent)->window.rect[0].y;
            float prw = ((menuDef_t *)parent)->window.rect[0].w, prh = ((menuDef_t *)parent)->window.rect[0].h;
            float pcx = x, pcy = y;
            CalcScreenX(&pcy, 4);
            CalcScreenY(&pcx, 4);
            CalcScreenPlacement(&prx, &prw, &pry, &prh, ((menuDef_t *)parent)->window.rect[0].horzAlign, ((menuDef_t *)parent)->window.rect[0].vertAlign);
            if (pcx < prx || pcx > prx + prw || pcy < pry || pcy > pry + prh)
                goto check_dvar;
        }
    }

check_dvar:;
    /* Dvar show checks */
    int dvarFlags = item->dvarFlags;
    if (dvarFlags & 3) {
        if (!Item_EnableShowViaDvar(item, 1))
            return 0;
        dvarFlags = item->dvarFlags;
    }
    if (dvarFlags & 0xc) {
        if (!Item_EnableShowViaDvar(item, 4))
            return 0;
    }

    /* Get parent menu for item iteration */
    menuDef_t *menu = item->parent;

    /* Remove focus from all items in menu, track old focus */
    itemDef_t *oldFocus = NULL;
    if (menu && menu->itemCount > 0) {
        int itemCount = menu->itemCount;
        for (i = 0; i < itemCount; i++) {
            itemDef_t *sibling = menu->items[i];
            int sf = sibling->window.dynamicFlags[0];
            if ((sf & 4) && (sf & 2))
                oldFocus = sibling;
            Window_RemoveDynamicFlags(sibling, 2);
            /* Run lostFocus script */
            if (sibling->leaveFocus)
                Item_RunScript(dc, sibling, sibling->leaveFocus);
        }
    } else {
        oldFocus = NULL;
    }

    /* Check item type for focusability */
    int itemType = item->type;
    if (itemType == 0) {
        /* Type 0: hit-test text rect */
        float *textRect = (float *)item->textRect;
        float tw = *(float *)(textRect + 8);
        float th = ((UiRectangle *)textRect)->h;
        float tx = item->textRect[0].x;
        float ty = *(float *)(textRect + 4) - th;
        float tcx = x, tcy = y;
        CalcScreenX(&tcx, 4);
        CalcScreenY(&tcy, 4);
        CalcScreenPlacement(&tx, &tw, &ty, &th, ((UiRectangle *)textRect)->horzAlign, ((UiRectangle *)textRect)->vertAlign);
        if (tcx < tx || tcx > tx + tw) goto fail;
        if (tcy < ty || tcy > ty + th) goto fail;

        /* Focus the item */
        Window_AddDynamicFlags((void *)it, 2);
        int itemSound = (int)(uintptr_t)item->focusSound;
        if (itemSound) {
            UI_PlayLocalSoundAlias(itemSound);
        } else if (defaultSound) {
            UI_PlayLocalSoundAlias(defaultSound);
        }
        goto set_cursor;
    }

    /* Add focus */
    Window_AddDynamicFlags((void *)it, 2);

    /* Run onFocus script */
    if ((void *)item->onFocus)
        Item_RunScript(dc, item, item->onFocus);

    /* Play sound */
    int itemSound = (int)(uintptr_t)item->focusSound;
    if (itemSound) {
        UI_PlayLocalSoundAlias(itemSound);
    } else if (defaultSound) {
        UI_PlayLocalSoundAlias(defaultSound);
    }

set_cursor:;
    /* Find item index and set cursor */
    if (menu) {
        int itemCount = menu->itemCount;
        for (i = 0; i < itemCount; i++) {
            if (menu->items[i] == item) {
                ((void (*)(void *, int))Menu_SetCursorItem)(menu, i);
                return 1;
            }
        }
    }
    return 1;

fail:
    /* Restore old focus if present */
    if (oldFocus) {
        Window_AddDynamicFlags(oldFocus, 2);
        if (oldFocus->onFocus)
            Item_RunScript(dc, oldFocus, oldFocus->onFocus);
    }
    /* Find item index and set cursor anyway */
    if (menu) {
        int itemCount = menu->itemCount;
        for (i = 0; i < itemCount; i++) {
            if (menu->items[i] == item) {
                ((void (*)(void *, int))Menu_SetCursorItem)(menu, i);
                return 1;
            }
        }
    }
    return 1;
}

/* Script_SetFocusByDvar — find item with matching dvarTest and set focus */
void Script_SetFocusByDvar(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char dvarName[0x400];
    byte *parent;
    int i;

    if (!String_Parse(args, dvarName, 0x400))
        return;

    parent = (byte *)item->parent;
    if (!parent)
        return;

    int itemCount = ((menuDef_t *)parent)->itemCount;
    for (i = 0; i < itemCount; i++) {
        byte *focusItem = (byte *)((menuDef_t *)parent)->items[i];

        if (!(((byte *)&((itemDef_t *)focusItem)->dvarFlags)[0] & 0x10))
            continue;

        const char *dvarTest = ((itemDef_t *)focusItem)->dvarTest;
        if (!dvarTest)
            Com_Error(1, "\x15Script_SetFocusByDvar: Item's dvarTest field is empty.");

        if (I_stricmp(dvarTest, dvarName) != 0)
            continue;

        if (!Item_EnableShowViaDvar((itemDef_t *)focusItem, 0x10))
            continue;

        if (Item_SetFocus(dc, (itemDef_t *)focusItem, ((itemDef_t *)focusItem)->window.rect[0].x, ((itemDef_t *)focusItem)->window.rect[0].y))
            return;
    }
}

/* Script_SetFocus — find item by name in parent menu, set focus and optional edit mode */
void Script_SetFocus(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    menuDef_t *menu;
    itemDef_t *focusItem = NULL;
    int i;

    if (!String_Parse(args, name, 0x400))
        return;

    menu = item->parent;

    /* Find item by window.name */
    if (menu && menu->itemCount > 0) {
        for (i = 0; i < menu->itemCount; i++) {
            itemDef_t *it = menu->items[i];
            const char *itemName = it->window.name;
            if (itemName && I_stricmp(name, itemName) == 0) {
                focusItem = it;
                break;
            }
        }
    }

    if (!focusItem) {
        Com_Printf(0, "setFocus: could not find widget named '%s'\n", name);
        return;
    }

    if (!Item_SetFocus(dc, focusItem, focusItem->window.rect[0].x, focusItem->window.rect[0].y)) {
        Com_Printf(0, "setFocus: error focusing widget '%s' (widget was found but could not accept focus)\n", name);
        return;
    }

    /* Check if this is an editable item type (check type against bitmask 0x70210) */
    int itemType = focusItem->type;
    if (itemType <= 0x12 && ((1 << itemType) & 0x70210)) {
        editFieldDef_t *editPtr = Item_GetEditFieldDef(focusItem);
        if (editPtr)
            editPtr->paintOffset = 0;
        Item_SetCursorPos(focusItem, 0);
        g_editingField = 1;
        g_editItem = focusItem;
        Key_SetOverstrikeMode(1);
    }
}

/* Item_ListBox_OverLB — determine which scrollbar region the cursor is over */
int Item_ListBox_OverLB(itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    int horzAlign = item->window.rect[0].horzAlign;
    int vertAlign = item->window.rect[0].vertAlign;

    UI_FeederCount((int)item->special);
    if (!Item_GetListBoxDef(item)) return 0;

    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* Horizontal listbox — scrollbar is on the right side */
        float scrollX = item->window.rect[0].x + item->window.rect[0].w - 16.0f;
        float itemY = item->window.rect[0].y;

        /* Down scroll button (bottom-right) */
        float rx = scrollX, ry = itemY, rw = 16.0f, rh = 16.0f;
        float cx = x, cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x200;

        /* Up scroll button (top-right) */
        float endY = itemY + item->window.rect[0].h - 16.0f;
        rx = scrollX; ry = endY; rw = 16.0f; rh = 16.0f;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x100;

        /* Thumb position */
        int thumbPos = Item_ListBox_ThumbPosition(item);
        /* Thumb rect */
        rx = scrollX; ry = (float)thumbPos; rw = 16.0f; rh = 16.0f;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x800;

        /* Page down area (between down button and thumb) */
        rx = scrollX; ry = itemY + 16.0f + 1.0f;
        rw = 16.0f; rh = (float)thumbPos - ry;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x400;

        /* Page up area (between thumb and up button) */
        float thumbEnd = (float)thumbPos + 16.0f + 1.0f;
        rx = scrollX; ry = thumbEnd;
        rw = 16.0f; rh = endY - thumbEnd;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x400;
    } else {
        /* Vertical listbox — scrollbar is on the right side */
        float scrollX = item->window.rect[0].x + item->window.rect[0].w - 16.0f;
        float itemY = item->window.rect[0].y;

        /* Up scroll button (top-right) */
        float rx = scrollX, ry = itemY, rw = 16.0f, rh = 16.0f;
        float cx = x, cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x100;

        /* Down scroll button (bottom-right) */
        float endY = itemY + item->window.rect[0].h - 16.0f;
        rx = scrollX; ry = endY; rw = 16.0f; rh = 16.0f;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x200;

        /* Thumb */
        int thumbPos = Item_ListBox_ThumbPosition(item);
        rx = scrollX; ry = (float)thumbPos; rw = 16.0f; rh = 16.0f;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x800;

        /* Page up area */
        rx = scrollX; ry = itemY + 16.0f + 1.0f;
        rw = 16.0f; rh = (float)thumbPos - ry;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x400;

        /* Page down area */
        float thumbEnd = (float)thumbPos + 16.0f + 1.0f;
        rx = scrollX; ry = thumbEnd;
        rw = 16.0f; rh = endY - thumbEnd;
        cx = x; cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x400;
    }

    return 0;
}

/* Item_ListBox_HandleKey — handle keyboard/mouse input for listbox items */
qboolean Item_ListBox_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down, qboolean force)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;
    listBoxDef_t *listPtr;
    int count, max, viewmax, flags;
    int inRect;

    listPtr = Item_GetListBoxDef(item);
    if (!listPtr)
        return 0;

    count = UI_FeederCount((int)item->special);

    /* Rect hit test */
    {
        float compareX, compareY;
        float compareRect_x, compareRect_y, compareRect_w, compareRect_h;

        compareX = (float)dc->cursorx;
        compareY = (float)dc->cursory;

        compareRect_x = item->window.rect[0].x;
        compareRect_y = item->window.rect[0].y;
        compareRect_w = item->window.rect[0].w;
        compareRect_h = item->window.rect[0].h;

        CalcScreenX(&compareX, 4);
        CalcScreenY(&compareY, 4);
        CalcScreenPlacement(&compareRect_x, &compareRect_w, &compareRect_y, &compareRect_h,
                            item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);

        if (compareX >= compareRect_x &&
            compareX <= compareRect_x + compareRect_w &&
            compareY >= compareRect_y &&
            compareY <= compareRect_y + compareRect_h)
            inRect = 1;
        else
            inRect = 0;
    }

    flags = item->window.dynamicFlags[0];

    if (!force) {
        if (!inRect || !(flags & 2))
            return 0;
    }

    ((void (*)(void *))UI_OverrideCursorPos)(item);
    max = Item_ListBox_MaxScroll(item);

    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* ========== HORIZONTAL ========== */
        viewmax = (int)(item->window.rect[0].w / listPtr->elementWidth);

        if (key == 0x9c) {
            /* UP in horizontal mode */
            if (listPtr->notselectable) {
                /* notselectable: scroll start - 1 */
                goto scroll_start_dec;
            }
            ListBox_SetCursorPos((itemDef_t *)listPtr, listPtr->cursorPos[0] - 1);
            if (listPtr->cursorPos[0] < 0)
                ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
            if (listPtr->cursorPos[0] < listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0]);
            if (listPtr->cursorPos[0] >= viewmax + listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0] - viewmax + 1);
            Item_SetCursorPos(item, listPtr->cursorPos[0]);
            goto do_feeder_selection;
        }

        if (key == 0x9d) {
            /* DOWN in horizontal mode */
            if (listPtr->notselectable) {
                /* notselectable: scroll start + 1 */
                ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->startPos[0] + 1);
                if (count > listPtr->startPos[0])
                    return 1;
                ListBox_SetStartPos((itemDef_t *)listPtr, count - 1);
                return 1;
            }
            ListBox_SetCursorPos((itemDef_t *)listPtr, listPtr->cursorPos[0] + 1);
            if (listPtr->cursorPos[0] < listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0]);
            if (count <= listPtr->cursorPos[0])
                ListBox_SetCursorPos((itemDef_t *)listPtr, count - 1);
            if (listPtr->cursorPos[0] >= viewmax + listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0] - viewmax + 1);
            Item_SetCursorPos(item, listPtr->cursorPos[0]);
            goto do_feeder_selection;
        }
        /* Fall through to common key handling */
    } else {
        /* ========== VERTICAL ========== */
        viewmax = (int)(item->window.rect[0].h / listPtr->elementHeight);

        if (key == 0x9a || key == 0xce) {
            /* LEFT/previous in vertical mode */
            if (listPtr->notselectable) {
                /* notselectable: scroll start - 1 */
                goto scroll_start_dec;
            }
            Item_SetCursorPos(item, item->cursorPos[0] - 1);
            if (item->cursorPos[0] < 0)
                Item_SetCursorPos(item, 0);
            if (item->cursorPos[0] < listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, item->cursorPos[0]);
            if (item->cursorPos[0] >= viewmax + listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, item->cursorPos[0] - viewmax + 1);
            UI_FeederSelection(item->special, item->cursorPos[0]);
            return 1;
        }

        if (key == 0x9b || key == 0xcd) {
            /* RIGHT/next in vertical mode */
            if (listPtr->notselectable) {
                /* notselectable: scroll start + 1 */
                goto scroll_start_inc;
            }
            Item_SetCursorPos(item, item->cursorPos[0] + 1);
            if (item->cursorPos[0] < listPtr->startPos[0])
                ListBox_SetStartPos((itemDef_t *)listPtr, item->cursorPos[0]);
            if (count <= item->cursorPos[0])
                Item_SetCursorPos(item, count - 1);
            if (item->cursorPos[0] < 0)
                Item_SetCursorPos(item, 0);
            if (item->cursorPos[0] >= viewmax + listPtr->startPos[0]) {
                ListBox_SetStartPos((itemDef_t *)listPtr, item->cursorPos[0] - viewmax + 1);
            }
            goto do_feeder_selection;
        }
        /* Fall through to common key handling */
    }

    /* ========== COMMON KEY HANDLING ========== */

    if (key == 0xc8 || key == 0xc9) {
        /* Mouse click */
        if (flags & 0x100) {
            /* Scroll up by one */
            goto scroll_start_dec;
        }
        if (flags & 0x200) {
            /* Scroll down by one */
            goto scroll_start_inc;
        }
        if (flags & 0x800) {
            /* Page up (notselectable) */
            goto scroll_start_pgup;
        }
        if (flags & 0x1000) {
            /* Page down (notselectable) */
            goto scroll_start_pgdn;
        }
        if (flags & 0x400) {
            /* Thumb area — just return 1 */
            return 1;
        }

        /* Regular listbox click */
        if (item->special == 18.0f) {
            ((void (*)(void *))UI_OverrideCursorPos)(item);
            UI_FeederSelection(item->special, item->cursorPos[0]);
        }

        /* Double-click check */
        {
            int curTime = dc->realTime;
            if (curTime < lastListBoxClickTime &&
                listPtr->doubleClick != NULL &&
                item->cursorPos[0] == listPtr->cursorPos[0]) {
                if (ListBox_HasValidCursorPos((itemDef_t *)listPtr)) {
                    Item_RunScript(dc, item, listPtr->doubleClick);
                    curTime = dc->realTime;
                }
            }

            lastListBoxClickTime = curTime + 0x12c;

            if (item->cursorPos[0] == listPtr->cursorPos[0])
                return 1;

            if (item->cursorPos[0] < 0)
                Item_SetCursorPos(item, listPtr->cursorPos[0]);

            {
                int oldCursorPos = listPtr->cursorPos[0];
                if (oldCursorPos < UI_FeederCount((int)item->special))
                    Item_SetCursorPos(item, listPtr->cursorPos[0]);
            }
            goto do_feeder_selection;
        }
    }

    if (key == 0xa5) {
        /* HOME */
        if (listPtr->notselectable) {
            /* notselectable */
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
            return 1;
        }
        Item_SetCursorPos(item, 0);
        ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        goto do_feeder_selection;
    }

    if (key == 0xa6) {
        /* END */
        if (listPtr->notselectable) {
            /* notselectable */
            ListBox_SetStartPos((itemDef_t *)listPtr, max);
            return 1;
        }
        Item_SetCursorPos(item, count - 1);
        ListBox_SetCursorPos((itemDef_t *)listPtr, count - 1);
        if (item->cursorPos[0] >= viewmax + listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, item->cursorPos[0] - viewmax + 1);
        if (item->cursorPos[0] < 0) {
            Item_SetCursorPos(item, 0);
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        }
        goto do_feeder_selection;
    }

    if (key == 0xa4) {
        /* PAGE UP */
        if (listPtr->notselectable) {
            goto scroll_start_pgup;
        }
        ListBox_SetCursorPos((itemDef_t *)listPtr, listPtr->cursorPos[0] - viewmax);
        if (listPtr->cursorPos[0] < 0)
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        if (listPtr->cursorPos[0] < listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0]);
        if (listPtr->cursorPos[0] >= viewmax + listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0] - viewmax + 1);
        Item_SetCursorPos(item, listPtr->cursorPos[0]);
        goto do_feeder_selection;
    }

    if (key == 0xa3) {
        /* PAGE DOWN */
        if (listPtr->notselectable) {
            goto scroll_start_pgdn;
        }
        ListBox_SetCursorPos((itemDef_t *)listPtr, listPtr->cursorPos[0] + viewmax);
        if (listPtr->cursorPos[0] < listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0]);
        if (count <= listPtr->cursorPos[0])
            ListBox_SetCursorPos((itemDef_t *)listPtr, count - 1);
        if (listPtr->cursorPos[0] < 0)
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        if (listPtr->cursorPos[0] >= viewmax + listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, listPtr->cursorPos[0] - viewmax + 1);
        Item_SetCursorPos(item, listPtr->cursorPos[0]);
        goto do_feeder_selection;
    }

    return 0;

scroll_start_dec:
    {
        int newStart = listPtr->startPos[0] - 1;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (listPtr->startPos[0] < 0)
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        return 1;
    }

scroll_start_inc:
    {
        int newStart = listPtr->startPos[0] + 1;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (max < listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, max);
        return 1;
    }

scroll_start_pgup:
    {
        int newStart = listPtr->startPos[0] - viewmax;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (listPtr->startPos[0] < 0)
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        return 1;
    }

scroll_start_pgdn:
    {
        int newStart = listPtr->startPos[0] + viewmax;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (max < listPtr->startPos[0])
            ListBox_SetStartPos((itemDef_t *)listPtr, max);
        return 1;
    }

do_feeder_selection:
    UI_FeederSelection(item->special, item->cursorPos[0]);
    return 1;
}


/* Scroll_ListBox_ThumbFunc — drag-thumb scroll for listbox */
static void Scroll_ListBox_ThumbFunc(displayContextDef_t *dc, void *p)
{
    byte *d = (byte *)dc;
    byte *scroll = (byte *)p;
    itemDef_t *scrollItem = ((scrollInfo_t *)scroll)->item;
    itemDef_t *item = scrollItem;
    listBoxDef_t *listPtr = Item_GetListBoxDef(scrollItem);

    if (!listPtr) return;

    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        /* Horizontal */
        float cursorX = (float)dc->cursorx;
        if (cursorX == ((scrollInfo_t *)scroll)->xStart)
            goto check_auto;
        /* Compute new start pos from cursor position */
        float startX = item->window.rect[0].x + 16.0f + 1.0f;
        float scrollArea = item->window.rect[0].w - 32.0f - 2.0f;
        int maxScroll = Item_ListBox_MaxScroll(scrollItem);
        float thumbPos = (cursorX - startX - 8.0f) * (float)maxScroll / (scrollArea - 16.0f);
        int newStart = (int)thumbPos;
        if (newStart < 0) newStart = 0;
        else if (newStart > maxScroll) newStart = maxScroll;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        ((scrollInfo_t *)scroll)->xStart = cursorX;
    } else {
        /* Vertical */
        float cursorY = (float)dc->cursory;
        if (cursorY == ((scrollInfo_t *)scroll)->yStart)
            goto check_auto;
        /* Compute new start pos from cursor position */
        float startY = item->window.rect[0].y + 16.0f + 1.0f;
        float scrollArea = item->window.rect[0].h - 32.0f - 2.0f;
        int maxScroll = Item_ListBox_MaxScroll(scrollItem);
        float thumbPos = (cursorY - startY - 8.0f) * (float)maxScroll / (scrollArea - 16.0f);
        int newStart = (int)thumbPos;
        if (newStart < 0) newStart = 0;
        else if (newStart > maxScroll) newStart = maxScroll;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        ((scrollInfo_t *)scroll)->yStart = cursorY;
    }

check_auto:;
    /* Auto-scroll: if past hold time, trigger key repeat */
    int curTime = dc->realTime;
    while (curTime > ((scrollInfo_t *)scroll)->nextScrollTime) {
        Item_ListBox_HandleKey(dc, ((scrollInfo_t *)scroll)->item, ((scrollInfo_t *)scroll)->scrollKey, 1, 0);
        ((scrollInfo_t *)scroll)->nextScrollTime = curTime + ((scrollInfo_t *)scroll)->adjustValue;
    }

    if (curTime > ((scrollInfo_t *)scroll)->nextAdjustTime) {
        ((scrollInfo_t *)scroll)->nextAdjustTime = curTime + 150;
        if (((scrollInfo_t *)scroll)->adjustValue > 20)
            ((scrollInfo_t *)scroll)->adjustValue -= 40;
    }
}

/* Scroll_ListBox_AutoFunc — auto-scroll list box: handle key repeat, adjust timing */
static void Scroll_ListBox_AutoFunc(displayContextDef_t *dc, void *p)
{
    (void)dc;
    scrollInfo_t *scroll = (scrollInfo_t *)p;
    int curTime = dc->realTime;

    /* If past next scroll time, handle key and advance */
    while (curTime > scroll->nextScrollTime) {
        Item_ListBox_HandleKey(dc, scroll->item, scroll->scrollKey, 1, 0);
        scroll->nextScrollTime = curTime + scroll->adjustValue;
    }

    /* Adjust next scroll time if past hold time */
    if (curTime > scroll->nextAdjustTime) {
        scroll->nextAdjustTime = curTime + 150;
        if (scroll->adjustValue > 20)
            scroll->adjustValue -= 40;
    }
}

/* Item_Bind_HandleKey — handle key binding: enter bind mode, assign/clear keys */
extern const char str_002157b8[]; /* empty string */
qboolean Item_Bind_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down)
{
    byte *it = (byte *)item;
    int i;

    if (!g_waitingForKey) {
        /* Not waiting for key — check if we should enter bind mode */
        if (!down) return 0;
        if (key == 0xd) goto enter_bind; /* Enter key */
        if (key == 0xc8) {
            /* Mouse click — check if within item rect */
            byte *d = (byte *)dc;
            float cx = (float)dc->cursorx;
            float cy = (float)dc->cursory;
            float rx = item->window.rect[0].x, ry = item->window.rect[0].y;
            float rw = item->window.rect[0].w, rh = item->window.rect[0].h;
            CalcScreenX(&cx, 4);
            CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
            if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh)
                return 0;
enter_bind:
            g_waitingForKey = 1;
            g_bindItem = item;
            return 1;
        }
        return 0;
    }

    /* Waiting for key — process the incoming key */
    if (!g_bindItem) return 0;

    /* Modifier keys or backtick — consume but don't bind */
    if ((key & 0x400) || key == 0x60)
        return 1;

    /* Delete key — unbind the command */
    if (key == 0x7f) {
        const char *dvarName = item->dvar;
        /* Find binding index */
        for (i = 0; i < 0x38; i++) {
            if (I_stricmp(dvarName, g_bindings[i].command) == 0)
                break;
        }
        if (i < 0x38) {
            /* Unbind both keys */
            int key1 = g_bindings[i].bind1;
            if (key1 != -1) {
                Key_SetBinding(key1, str_002157b8);
                g_bindings[i].bind1 = -1;
            }
            int key2 = g_bindings[i].bind2;
            if (key2 != -1) {
                Key_SetBinding(key2, str_002157b8);
                g_bindings[i].bind2 = -1;
            }
        }
        Controls_SetConfig(0);
        g_waitingForKey = 0;
        g_bindItem = NULL;
        return 1;
    }

    /* Escape — cancel bind */
    if (key == 0x1b) {
        g_waitingForKey = 0;
        g_bindItem = NULL;
        return 1;
    }

    /* Regular key — unbind old instances and assign new binding */
    if (key != -1) {
        /* Walk g_bindings and remove this key from any existing bindings */
        int bi;
        for (bi = 0; (byte *)&g_bindings[bi] != (byte *)updateScreenCalled; bi++) {
            if (g_bindings[bi].bind2 == key) {
                g_bindings[bi].bind2 = -1;
            }
            if (g_bindings[bi].bind1 == key) {
                /* Shift bind2 to bind1, clear bind2 */
                g_bindings[bi].bind1 = g_bindings[bi].bind2;
                g_bindings[bi].bind2 = -1;
            }
        }
    }

    /* Find binding entry for this item's dvar */
    const char *bindName = item->dvar;
    int bindIdx = -1;
    for (i = 0; i < 0x38; i++) {
        if (I_stricmp(bindName, g_bindings[i].command) == 0) {
            bindIdx = i;
            break;
        }
    }

    if (bindIdx >= 0 && key != -1) {
        if (g_bindings[bindIdx].bind1 == -1) {
            g_bindings[bindIdx].bind1 = key;
        } else {
            g_bindings[bindIdx].bind2 = key;
        }
    }

    Controls_SetConfig(0);
    g_waitingForKey = 0;
    g_bindItem = NULL;
    return 1;
}

/* Item_HandleKey — dispatch key input to item-type-specific handlers */
/* Handles mouse click capture setup for listbox/slider, type-based dispatch via switch */
static int Item_HandleKey_RectContainsPoint(itemDef_t *item, float cx, float cy)
{
    float rx = item->window.rect[0].x, ry = item->window.rect[0].y;
    float rw = item->window.rect[0].w, rh = item->window.rect[0].h;
    CalcScreenX(&cx, 4);
    CalcScreenY(&cy, 4);
    CalcScreenPlacement(&rx, &rw, &ry, &rh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
    if (cx >= rx && rx + rw >= cx && cy >= ry && ry + rh >= cy)
        return 1;
    return 0;
}

qboolean Item_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;

    /* If there's an active capture, release it */
    if (itemCapture) {
        itemCapture = NULL;
        captureFunc = NULL;
        captureData = NULL;
    } else {
        /* No active capture — handle mouse click setup */
        if (!down)
            return 0;
        if (key >= 0xc8 && key <= 0xca) {
            int itemType = item->type;
            if (itemType == 6) {
                /* Listbox — check scrollbar region */
                float lbx = (float)dc->cursorx;
                float lby = (float)dc->cursory;
                int overLB = Item_ListBox_OverLB(item, lbx, lby);
                if (overLB & 0x300) {
                    /* Up/down arrow region — auto-scroll */
                    scrollInfo.nextScrollTime = dc->realTime + 500;
                    scrollInfo.nextAdjustTime = dc->realTime + 150;
                    scrollInfo.adjustValue = 500;
                    scrollInfo.scrollKey = key;
                    scrollInfo.scrollDir = (overLB >> 8) & 1;
                    scrollInfo.item = item;
                    captureData = &scrollInfo;
                    captureFunc = Scroll_ListBox_AutoFunc;
                    itemCapture = item;
                } else if (overLB & 0x400) {
                    /* Thumb region — drag scroll */
                    scrollInfo.scrollKey = key;
                    scrollInfo.item = item;
                    scrollInfo.xStart = (float)dc->cursorx;
                    scrollInfo.yStart = (float)dc->cursory;
                    captureData = &scrollInfo;
                    captureFunc = Scroll_ListBox_ThumbFunc;
                    itemCapture = item;
                }
                /* Fall through to type switch */
            } else if (itemType == 0xa) {
                /* Slider — check thumb hit test */
                float sy = (float)dc->cursory;
                float sx = (float)dc->cursorx;
                float thumbX = Item_Slider_ThumbPosition(item);
                float itemY = item->window.rect[0].y - 2.0f;
                int horzAlign = item->window.rect[0].horzAlign;
                int vertAlign = item->window.rect[0].vertAlign;

                float rx = thumbX - 5.0f, ry = itemY;
                float rw = 10.0f, rh = 20.0f;
                float cx = sx, cy = sy;
                CalcScreenX(&cx, 4);
                CalcScreenY(&cy, 4);
                CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
                int hit = (cx >= rx && rx + rw >= cx && cy >= ry && ry + rh >= cy) ? 0x400 : 0;

                if (hit) {
                    scrollInfo.scrollKey = key;
                    scrollInfo.item = item;
                    scrollInfo.xStart = (float)dc->cursorx;
                    scrollInfo.yStart = (float)dc->cursory;
                    captureData = &scrollInfo;
                    captureFunc = Scroll_Slider_ThumbFunc;
                    itemCapture = item;
                }
                /* Fall through to type switch */
            }
        }
    }

    /* Dispatch based on item type */
    if (!down)
        return 0;

    switch (item->type) {
    case 6: /* ITEM_TYPE_LISTBOX */
        return Item_ListBox_HandleKey(dc, item, key, down, 0);

    case 8: /* ITEM_TYPE_OWNERDRAW */
        return UI_OwnerDrawHandleKey(item->window.ownerDraw, item->window.ownerDrawFlags,
                                     (int *)&item->special, key);

    case 0xa: /* ITEM_TYPE_SLIDER */
        return Item_Slider_HandleKey(dc, item, key, down);

    case 0xb: /* ITEM_TYPE_YESNO */
        return Item_YesNo_HandleKey(dc, item, key);

    case 0xc: { /* ITEM_TYPE_MULTI */
        byte *multiPtr = (byte *)Item_GetMultiDef(item);
        if (!multiPtr)
            return 0;
        if (!(((byte *)item->window.dynamicFlags)[0] & 4))
            return 0;
        if (!(((byte *)item->window.dynamicFlags)[0] & 2))
            return 0;

        /* Mouse click — check item rect bounds */
        if (key >= 0xc8 && key <= 0xca) {
            if (!Item_HandleKey_RectContainsPoint(it, (float)dc->cursorx, (float)dc->cursory))
                return 0;
        }

        /* Get multiDef and find current index */
        byte *mDef = (byte *)Item_GetMultiDef(item);
        int current = 0;
        if (mDef) {
            int strDef = ((multiDef_t *)mDef)->strDef;
            if (!strDef) {
                /* Float-based multi */
                const char *valStr = Dvar_GetVariantString(item->dvar);
                float curVal = (float)atof(valStr);
                int count = ((multiDef_t *)mDef)->count;
                if (count > 0) {
                    /* Check if first value matches */
                    if (curVal != ((multiDef_t *)mDef)->dvarValue[0]) {
                        int i;
                        for (i = 1; i < count; i++) {
                            if (((multiDef_t *)mDef)->dvarValue[i] == curVal) {
                                current = i;
                                break;
                            }
                        }
                        /* If no match, current stays 0 */
                    }
                }
            } else {
                /* String-based multi */
                const char *string = Dvar_GetVariantString(item->dvar);
                int count = ((multiDef_t *)mDef)->count;
                if (count > 0) {
                    int i;
                    for (i = 0; i < count; i++) {
                        if (I_stricmp(string, ((multiDef_t *)mDef)->dvarStr[i]) == 0) {
                            current = i;
                            break;
                        }
                    }
                }
            }
        }

        /* Determine new index based on key direction */
        byte *mDef2 = (byte *)Item_GetMultiDef(item);
        int totalCount;
        if (!mDef2)
            totalCount = 0;
        else
            totalCount = ((multiDef_t *)mDef2)->count;

        int newIndex;
        if (!totalCount) {
            newIndex = 0;
        } else if (key == 0xc8 || key == 0xd || key == 0xca || key == 0xa3 || key == 0x9d) {
            /* Forward/right: increment with wrap */
            newIndex = (current + 1) % totalCount;
        } else if (key == 0xc9 || key == 0xa4 || key == 0x9c) {
            /* Back/left: decrement with wrap */
            newIndex = (current - 1 + totalCount) % totalCount;
        } else {
            return 0;
        }

        if (newIndex == current)
            return 0;

        /* Set the new dvar value */
        const char *newVal;
        if (((multiDef_t *)multiPtr)->strDef) {
            /* String-based */
            newVal = ((multiDef_t *)multiPtr)->dvarStr[newIndex];
        } else {
            /* Float-based */
            newVal = va("%g", (double)((multiDef_t *)multiPtr)->dvarValue[newIndex]);
        }
        Dvar_SetFromStringByName(item->dvar, newVal);
        return 1;
    }

    case 0xd: { /* ITEM_TYPE_ENUM_DVAR */
        if (!(((byte *)item->window.dynamicFlags)[0] & 4))
            return 0;
        if (!(((byte *)item->window.dynamicFlags)[0] & 2))
            return 0;

        /* Mouse click — check item rect bounds */
        if (key >= 0xc8 && key <= 0xca) {
            if (!Item_HandleKey_RectContainsPoint(it, (float)dc->cursorx, (float)dc->cursory))
                return 0;
        }

        /* Get current enum index */
        struct dvar_s *enumDvar = Dvar_FindVar(item->typeData.enumDvarName);
        int current = 0;
        if (((dvar_t *)enumDvar)->type == 6) {
            /* Enum dvar type — resolve current index */
            const char *enumString = Dvar_GetVariantString(item->dvar);
            current = atoi(enumString);
            if (current < 0 || current >= enumDvar->domain.enumeration.stringCount) {
                /* Invalid numeric index — search by string */
                int numStrings = enumDvar->domain.enumeration.stringCount;
                current = 0;
                if (numStrings > 0) {
                    const char **strings = enumDvar->domain.enumeration.strings;
                    int i;
                    for (i = 0; i < numStrings; i++) {
                        if (I_stricmp(enumString, strings[i]) == 0) {
                            current = i;
                            break;
                        }
                    }
                }
            }
        }

        /* Get total count */
        struct dvar_s *dv = Dvar_FindVar(item->typeData.enumDvarName);
        int totalCount;
        if (dv->type == 6)
            totalCount = dv->domain.enumeration.stringCount;
        else
            totalCount = 0;

        /* Determine new index based on key direction */
        int newIndex;
        if (!totalCount) {
            newIndex = 0;
        } else if (key == 0xc8 || key == 0xd || key == 0xca || key == 0xa3 || key == 0x9d) {
            /* Forward/right: increment with wrap */
            newIndex = (current + 1) % totalCount;
        } else if (key == 0xc9 || key == 0xa4 || key == 0x9c) {
            /* Back/left: decrement with wrap */
            newIndex = (current - 1 + totalCount) % totalCount;
        } else {
            return 0;
        }

        if (newIndex == current)
            return 0;

        Dvar_SetFromStringByName(item->dvar, va("%i", newIndex));
        return 1;
    }

    case 0xe: /* ITEM_TYPE_BIND */
        return Item_Bind_HandleKey(dc, item, key, down);

    default:
        return 0;
    }
}

/* Item_ListBox_MouseEnter — handle mouse enter for listbox: update cursor from mouse position */
void Item_ListBox_MouseEnter(itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    listBoxDef_t *listPtr = Item_GetListBoxDef(item);
    if (!listPtr) return;
    Window_RemoveDynamicFlags((void *)it, 0x1f00);
    int overLB = Item_ListBox_OverLB(item, x, y);
    Window_AddDynamicFlags((void *)it, overLB);
    int horzAlign = item->window.rect[0].horzAlign;
    int vertAlign = item->window.rect[0].vertAlign;
    if (((byte *)&item->window.staticFlags)[2] & 0x20) {
        if (item->window.dynamicFlags[0] & 0x1f00) return;
        if (listPtr->elementStyle == 1) {
            float itemX = item->window.rect[0].x, itemY = item->window.rect[0].y;
            float rectW = item->window.rect[0].h - 16.0f;
            int headerH = listPtr->drawPadding;
            float rectH = item->window.rect[0].w - (float)headerH;
            float cx = x, cy = y;
            float rx = itemX, ry = itemY, rw = rectH, rh = rectW;
            CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
            if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh) return;
            int cursorPos = (int)((x - itemX) / listPtr->elementWidth) + listPtr->startPos[0];
            ListBox_SetCursorPos((itemDef_t *)listPtr, cursorPos);
            if (listPtr->cursorPos[0] >= listPtr->endPos[0])
                ListBox_SetCursorPos((itemDef_t *)listPtr, listPtr->endPos[0]);
        }
    } else {
        if (item->window.dynamicFlags[0] & 0x1f00) return;
        float itemY = item->window.rect[0].y;
        float rectW = item->window.rect[0].w - 16.0f;
        int headerH = listPtr->drawPadding;
        float rectH = item->window.rect[0].h - (float)headerH;
        float cx = x, cy = y;
        float rx = item->window.rect[0].x, ry = itemY, rw = rectW, rh = rectH;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh) return;
        int cursorPos = (int)((y - 2.0f - itemY) / listPtr->elementHeight) + listPtr->startPos[0];
        ListBox_SetCursorPos((itemDef_t *)listPtr, cursorPos);
        if (listPtr->cursorPos[0] > listPtr->endPos[0])
            ListBox_SetCursorPos((itemDef_t *)listPtr, listPtr->endPos[0]);
    }
}

/* Item_MouseEnter — handle mouse enter/exit for an item with rect hit test */
void Item_MouseEnter(displayContextDef_t *dc, itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    if (!item) return;
    byte *parent = (byte *)item->parent;
    if (!parent) return;
    int dvarFlags = item->dvarFlags;
    if (dvarFlags & 3) {
        if (!Item_EnableShowViaDvar((itemDef_t *)it, 1)) return;
        dvarFlags = item->dvarFlags;
    }
    if (dvarFlags & 0xc) {
        if (!Item_EnableShowViaDvar((itemDef_t *)it, 4)) return;
    }
    int flags = item->window.dynamicFlags[0];
    float rx = item->window.rect[0].x, ry = item->window.rect[0].y;
    float rw = item->window.rect[0].w, rh = item->window.rect[0].h;
    float cx = x, cy = y;
    CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
    CalcScreenPlacement(&rx, &rw, &ry, &rh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
    qboolean inside = (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh);
    if (inside) {
        if (!(flags & 0x40)) {
            Item_RunScript(dc, item, item->mouseEnterText);
            Window_AddDynamicFlags((void *)it, 0x40);
        }
        if (!(flags & 1)) {
            Item_RunScript(dc, item, item->mouseEnter);
            Window_AddDynamicFlags((void *)it, 1);
        }
    } else {
        if (flags & 0x40) {
            Item_RunScript(dc, item, item->mouseExitText);
            Window_RemoveDynamicFlags((void *)it, 0x40);
        }
        if (!(flags & 1)) {
            Item_RunScript(dc, item, item->mouseEnter);
            Window_AddDynamicFlags((void *)it, 1);
        }
    }
    if (item->type == 6)
        Item_ListBox_MouseEnter(item, x, y);
}

/* Menu_HandleMouseMove — handle mouse movement over menu items: hit test, focus, enter/leave */
static qboolean Rect_ContainsPoint(itemDef_t *item, float x, float y)
{
    float rx = item->window.rect[0].x, ry = item->window.rect[0].y;
    float rw = item->window.rect[0].w, rh = item->window.rect[0].h;
    float cx = x, cy = y;
    CalcScreenX(&cx, 4);
    CalcScreenY(&cy, 4);
    CalcScreenPlacement(&rx, &rw, &ry, &rh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
    return (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh);
}

qboolean Menu_HandleMouseMove(displayContextDef_t *dc, menuDef_t *menu, float x, float y)
{
    int i, pass;
    qboolean focusSet = 0;
    itemDef_t *focusItem = NULL;

    if (!menu) return 0;
    if ((menu->window.dynamicFlags[0] & 0x4004) == 0) return 0;
    if (itemCapture) return 0;
    if (g_waitingForKey || g_editingField) return 0;

    /* Two-pass item scan: pass 0 = basic rect, pass 1 = text rect */
    for (pass = 0; pass < 2; pass++) {
        int itemCount = menu->itemCount;
        for (i = itemCount - 1; i >= 0; i--) {
            itemDef_t *item = menu->items[i];

            if ((item->window.dynamicFlags[0] & 0x4004) == 0) goto next_item;

            /* Dvar show checks */
            if (((byte *)&item->dvarFlags)[0] & 3) {
                if (!Item_EnableShowViaDvar(item, 1)) goto next_item;
                item = menu->items[i];
            }
            if (((byte *)&item->dvarFlags)[0] & 0xc) {
                if (!Item_EnableShowViaDvar(item, 4)) goto next_item;
                item = menu->items[i];
            }

            itemDef_t *overItem = item;
            int flags = overItem->window.dynamicFlags[0];
            if ((flags & 4) && (flags & 2) && !focusItem)
                focusItem = overItem;

            /* Hit test item rect */
            if (!Rect_ContainsPoint(overItem, x, y)) {
                itemDef_t *orig = menu->items[i];
                if (orig->window.dynamicFlags[0] & 1) {
                    Item_MouseLeave(dc, orig);
                    orig = menu->items[i];
                    if (orig) Window_RemoveDynamicFlags(orig, 1);
                }
                goto next_item;
            }

            if (pass == 1) {
                overItem = menu->items[i];
                int itemType = overItem->type;
                if (itemType == 0 && (int)(uintptr_t)overItem->text) {
                    int textBuf[6];
                    memset(textBuf, 0, 24);
                    textBuf[0] = (int)overItem->textRect[0].x;
                    textBuf[1] = (int)overItem->textRect[0].y;
                    textBuf[2] = (int)overItem->textRect[0].w;
                    textBuf[3] = (int)overItem->textRect[0].h;
                    textBuf[4] = overItem->textRect[0].horzAlign;
                    textBuf[5] = overItem->textRect[0].vertAlign;
                    if (*(float *)&textBuf[2] != 0.0f)
                        *(float *)&textBuf[1] -= *(float *)&textBuf[3];
                    float trx = *(float *)&textBuf[0], try_ = *(float *)&textBuf[1];
                    float trw = *(float *)&textBuf[2], trh = *(float *)&textBuf[3];
                    float tcx = x, tcy = y;
                    CalcScreenX(&tcx, 4);
                    CalcScreenY(&tcy, 4);
                    CalcScreenPlacement(&trx, &trw, &try_, &trh, textBuf[4], textBuf[5]);
                    if (tcx < trx || tcx > trx + trw || tcy < try_ || tcy > try_ + trh)
                        goto next_item;
                }

                if (!(overItem->window.dynamicFlags[0] & 4)) goto next_item;
                if (overItem->window.dynamicFlags[0] & 0x10) goto next_item;

                Item_MouseEnter(dc, overItem, x, y);
                if (!focusSet) {
                    if (Item_SetFocus(dc, overItem, x, y)) {
                        focusSet = 1;
                        focusItem = overItem;
                    }
                }
            }
next_item:;
        }
    }

    if (focusSet) return 1;

    if (focusItem) {
        if (!Rect_ContainsPoint(focusItem, x, y)) {
            int itemCount = menu->itemCount;
            for (i = 0; i < itemCount; i++) {
                itemDef_t *item = menu->items[i];
                Window_RemoveDynamicFlags(item, 2);
                if (item->leaveFocus)
                    Item_RunScript(dc, item, item->leaveFocus);
            }
        }
    }

    return 0;
}

/* Item_TextField_HandleKey — full text field editor: char input, delete, cursor, tab */
extern int ___toupper(int c);
qboolean Item_TextField_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key)
{
    byte *it = (byte *)item;
    char buff[0x400];
    int len;

    editFieldDef_t *editPtr = Item_GetEditFieldDef(item);
    if (!editPtr) return 0;
    if (!(void *)item->dvar) return 0;

    /* Load current dvar value into buff */
    memset(buff, 0, 0x400);
    I_strncpyz(buff, Dvar_GetVariantString(item->dvar), 0x400);

    /* Compute string length (repne scasb equivalent) */
    len = 0;
    while (buff[len]) len++;

    /* Truncate to maxChars if set */
    int maxChars = editPtr->maxChars;
    if (maxChars && len > maxChars) {
        buff[maxChars] = '\0';
        len = maxChars;
    }

    /* Check for ctrl+key (key & 0x400) */
    if (key & 0x400) {
        key &= ~0x400;

        /* Ctrl+Backspace (8) — delete char before cursor */
        if (key == 8) {
            int cursorPos = item->cursorPos[0];
            if (cursorPos > 0) {
                memmove(buff + cursorPos - 1, buff + cursorPos, len - cursorPos + 1);
            }
            I_strncpyz(buff, buff, 0x400); /* normalize */
            Dvar_SetFromStringByName(item->dvar, buff);
            I_strncpyz(buff, Dvar_GetVariantString(item->dvar), 0x400);
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
            goto update_scroll;
        }

        /* Ctrl+key: check item type for filtering */
        if (item->type == 0x10) goto done; /* password field — block ctrl */

        if (key <= 0x1f) return 1;
        if (!(void *)item->dvar) return 1;

        /* Type-specific character filtering */
        int itemType = item->type;
        if (itemType == 9) {
            /* Numeric — check for decimal delimiter */
            if (key != (int)(unsigned char)Com_GetDecimalDelimiter()) {
                if (key != (int)(unsigned char)Com_GetDecimalDelimiter())
                    goto check_numeric;
            }
            goto insert_char;
check_numeric:;
            /* Check if it's not a digit */
        }

        if (item->type == 0x11) {
            /* Uppercase */
            key = ___toupper(key);
        }

        if (item->type == 0x12) {
            /* Numeric only */
            if (!I_isdigit(key)) return 1;
            goto insert_char;
        }

        /* Check valid filename char */
        if (item->type != 0x12) {
            if (!I_isforfilename(key)) return 1;
        }

insert_char:
        /* Insert or overstrike character */
        if (Key_GetOverstrikeMode()) {
            /* Overstrike: replace char at cursor */
            if (len >= 0xff) return 1;
            if (maxChars && len >= maxChars) return 1;
        } else {
            /* Insert mode */
            if (len >= 0xff) return 1;
            if (maxChars && len >= maxChars) return 1;
            /* Shift chars right to make room */
            int cursorPos = item->cursorPos[0];
            memmove(buff + cursorPos + 1, buff + cursorPos, len - cursorPos + 1);
        }

        /* Write character */
        buff[item->cursorPos[0]] = (char)key;
        Dvar_SetFromStringByName(item->dvar, buff);

        /* Reload and reposition cursor */
        I_strncpyz(buff, Dvar_GetVariantString(item->dvar), 0x400);
        Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, 1));

update_scroll:;
        /* Update scroll position */
        editPtr = Item_GetEditFieldDef(item);
        int curPos = item->cursorPos[0];
        if (curPos < editPtr->paintOffset) {
            editPtr->paintOffset = curPos;
            return 1;
        }
        int maxPaint = editPtr->maxPaintChars;
        if (!maxPaint) return 1;
        int offset = (int)Item_GetCursorPosOffset(item, buff, -maxPaint);
        if (offset > editPtr->paintOffset)
            editPtr->paintOffset = offset;

        /* Check if cursor exceeds max and should advance to next item */
        if (maxChars && item->cursorPos[0] >= maxChars) {
            int nextMaxPaint = editPtr->maxCharsGotoNext;
            if (!nextMaxPaint) return 1;
            itemDef_t *nextItem = Menu_SetNextCursorItem(dc, item->parent);
            Item_SetCursorPos(nextItem, 0);
            if (nextItem && nextItem->type <= 0x12 &&
                ((1 << nextItem->type) & 0x70210))
                g_editItem = nextItem;
        }
        return 1;
    }

    /* Non-ctrl key dispatch */
    /* Delete key (0xa2) */
    if (key == 0xa2) {
        int curPos = item->cursorPos[0];
        if (curPos < len) {
            memmove(buff + curPos, buff + curPos + 1, len - curPos);
            Dvar_SetFromStringByName(item->dvar, buff);
        }
        return 1;
    }

    /* Right arrow (0x9d) */
    if (key == 0x9d) {
        int curPos = item->cursorPos[0];
        if (curPos < len) {
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, 1));
            editPtr = Item_GetEditFieldDef(item);
            int cp = item->cursorPos[0];
            if (cp >= editPtr->paintOffset) {
                int mp = editPtr->maxPaintChars;
                if (mp) {
                    int off = (int)Item_GetCursorPosOffset(item, buff, -mp);
                    if (off > editPtr->paintOffset)
                        editPtr->paintOffset = off;
                }
            } else {
                editPtr->paintOffset = cp;
            }
        }
        return 1;
    }

    /* Left arrow (0x9c) */
    if (key == 0x9c) {
        if (item->cursorPos[0] > 0) {
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
            editPtr = Item_GetEditFieldDef(item);
            int cp = item->cursorPos[0];
            if (cp < editPtr->paintOffset)
                editPtr->paintOffset = cp;
        }
        return 1;
    }

    /* Home (0xa5) */
    if (key == 0xa5) {
        Item_SetCursorPos(item, 0);
        editPtr = Item_GetEditFieldDef(item);
        editPtr->paintOffset = 0;
        return 1;
    }

    /* End (0xa6) */
    if (key == 0xa6) {
        Item_SetCursorPos(item, len);
        editPtr = Item_GetEditFieldDef(item);
        int cp = item->cursorPos[0];
        int mp = editPtr->maxPaintChars;
        if (mp) {
            int off = (int)Item_GetCursorPosOffset(item, buff, -mp);
            if (off > editPtr->paintOffset)
                editPtr->paintOffset = off;
        }
        return 1;
    }

    /* Insert (0xa1) — toggle overstrike */
    if (key == 0xa1) {
        Key_SetOverstrikeMode(!Key_GetOverstrikeMode());
        return 1;
    }

    /* Tab (9) or Shift+Tab (0x9b) — advance to next/prev item */
    if (key == 9 || key == 0x9b) {
        /* Move to prev item */
        itemDef_t *newItem = Menu_SetPrevCursorItem(dc, item->parent);
        Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
        editPtr = Item_GetEditFieldDef(item);
        int cp = item->cursorPos[0];
        if (cp < editPtr->paintOffset)
            editPtr->paintOffset = cp;
        return 1;
    }

    /* Backspace (0x9a) — not ctrl+backspace */
    if (key == 0x9a) {
        int curPos = item->cursorPos[0];
        if (curPos > 0) {
            memmove(buff + curPos - 1, buff + curPos, len - curPos + 1);
            Dvar_SetFromStringByName(item->dvar, buff);
            I_strncpyz(buff, Dvar_GetVariantString(item->dvar), 0x400);
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
            editPtr = Item_GetEditFieldDef(item);
            int cp2 = item->cursorPos[0];
            if (cp2 < editPtr->paintOffset)
                editPtr->paintOffset = cp2;
        }
        return 1;
    }

    /* Enter (0xd) or numpad enter (0xbf) */
    if (key == 0xd || key == 0xbf) {
        /* Run onAccept script */
        if ((void *)item->onAccept) {
            byte tempItem[0x2a0];
            ((itemDef_t *)tempItem)->parent = item->parent;
            Item_RunScript(dc, (itemDef_t *)tempItem, item->onAccept);
        }
        return 1;
    }

    /* Escape (0x1b) */
    if (key == 0x1b) return 0;

done:
    return 1;
}

/* Menu_HandleKey — main menu key dispatcher: bind mode, edit mode, item dispatch, navigation */
extern int inHandleKey;
extern const char str_002167f8[]; /* "developer" */
extern const char str_002ac37c[]; /* "screenshot" */
void Menu_HandleKey(displayContextDef_t *dc, menuDef_t *menu, int key, qboolean down)
{
    byte *m = (byte *)menu;
    byte *d = (byte *)dc;
    void *focusedItem = NULL;
    int i;

    /* Waiting for key bind — dispatch to bind handler */
    if (g_waitingForKey) {
        if (down) {
            Item_Bind_HandleKey(dc, g_bindItem, key, down);
            return;
        }
    }

    /* Editing a field — dispatch to text field handler */
    if (g_editingField) {
        if (down) {
            if (!Item_TextField_HandleKey(dc, g_editItem, key)) {
                g_editingField = 0;
                g_editItem = NULL;
            } else {
                /* Mouse click while editing — check if click is inside edit item */
                if (key >= 0xc8 && key <= 0xca) {
                    g_editingField = 0;
                    g_editItem = NULL;
                    Display_MouseMove(dc, NULL, dc->cursorx, dc->cursory);
                }
            }
            goto done;
        }
    }

    /* No menu — nothing to handle */
    if (!menu) return;

    /* Down event + not sticky + not fullscreen: OOB check */
    if (down) {
        if (!(((byte *)&menu->window.staticFlags)[3] & 1) && !menu->fullScreen) {
            /* Hit test cursor against menu rect */
            float cx = (float)dc->cursorx, cy = (float)dc->cursory;
            float rx = menu->window.rect[0].x, ry = menu->window.rect[0].y;
            float rw = menu->window.rect[0].w, rh = menu->window.rect[0].h;
            CalcScreenX(&cx, 4);
            CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, menu->window.rect[0].horzAlign, menu->window.rect[0].vertAlign);
            int inside = (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh);
            if (!inside) {
                /* Cursor outside menu — handle OOB */
                if (!inHandleKey && key >= 0xc8 && key <= 0xca) {
                    inHandleKey = 1;
                    Menus_HandleOOBClick(dc, menu, key, down);
                    inHandleKey = 0;
                    return;
                }
            }
        }
    }

    /* Find focused item */
    int itemCount = menu->itemCount;
    focusedItem = NULL;
    for (i = 0; i < itemCount; i++) {
        itemDef_t *it = menu->items[i];
        int flags = it->window.dynamicFlags[0];
        if ((flags & 4) && (flags & 2))
            focusedItem = it;
    }

    /* Mouse wheel up/down (0xcd/0xce) — only for listbox items */
    if (key == 0xcd || key == 0xce) {
        if (focusedItem && ((itemDef_t *)focusedItem)->type == 6) {
            goto dispatch_item;
        }
        return;
    }

    /* Try to dispatch key to focused item */
    if (focusedItem) {
dispatch_item:
        if (Item_HandleKey(dc, (itemDef_t *)focusedItem, key, down)) {
            /* Item handled it — run action script */
            if (focusedItem) {
                byte *fi = (byte *)focusedItem;
                if ((void *)((itemDef_t *)fi)->action)
                    Item_RunScript(dc, (itemDef_t *)focusedItem, ((itemDef_t *)fi)->action);
            }
            return;
        }
    }

    /* Item didn't handle — process menu-level keys */
    if (!down) return;

    /* Try menu onKey handlers (keys 1-255) */
    if (key >= 1 && key <= 0xff) {
        if (Menu_CheckOnKey(dc, menu, key))
            return;
    }

    /* F11 (0xb1) — toggle debug mode */
    if (key == 0xb1) {
        if (Dvar_GetInt("developer"))
            debugMode ^= 1;
        return;
    }

    /* F12 (0xb2) — screenshot */
    if (key == 0xb2) {
        if (Dvar_GetInt("developer"))
            Cbuf_ExecuteText(2, "screenshot\n");
        return;
    }

    /* Escape (0x1b) — run onESC script */
    if (key == 0x1b) {
        if (!g_waitingForKey && (void *)menu->onESC) {
            byte tempItem[0x2a0];
            ((itemDef_t *)tempItem)->parent = (menuDef_t *)menu;
            Item_RunScript(dc, (itemDef_t *)tempItem, menu->onESC);
        }
        return;
    }

    /* Tab (9), Shift+Tab (0x9b), left/right arrows */
    if (key == 9 || key == 0x9b || key == 0x9d || key == 0x9c) {
        Menu_SetNextCursorItem(dc, menu);
        return;
    }

    /* Backtab (0x9a) */
    if (key == 0x9a) {
        Menu_SetPrevCursorItem(dc, menu);
        return;
    }

    /* Mouse buttons (0xc8-0xc9) — check focused item for click handling */
    if (key >= 0xc8 && key <= 0xc9) {
        if (!focusedItem) return;

        /* Type 0 items: hit test text rect */
        int itemType = ((itemDef_t *)focusedItem)->type;
        if (itemType == 0) {
            /* Build text rect and hit test */
            byte *fi = (byte *)focusedItem;
            int textBuf[6];
            memset(textBuf, 0, 24);
            textBuf[0] = (int)((itemDef_t *)fi)->textRect[0].x;
            textBuf[1] = (int)((itemDef_t *)fi)->textRect[0].y;
            textBuf[2] = (int)((itemDef_t *)fi)->textRect[0].w;
            textBuf[3] = (int)((itemDef_t *)fi)->textRect[0].h;
            textBuf[4] = ((itemDef_t *)fi)->textRect[0].horzAlign;
            textBuf[5] = ((itemDef_t *)fi)->textRect[0].vertAlign;
            float tw = *(float *)&textBuf[2];
            float ty = *(float *)&textBuf[1];
            if (tw != 0.0f)
                ty -= *(float *)&textBuf[3];
            float trx = *(float *)&textBuf[0], trw = *(float *)&textBuf[2];
            float try_ = ty, trh = *(float *)&textBuf[3];
            float tcx = (float)dc->cursorx, tcy = (float)dc->cursory;
            CalcScreenX(&tcx, 4);
            CalcScreenY(&tcy, 4);
            CalcScreenPlacement(&trx, &trw, &try_, &trh, textBuf[4], textBuf[5]);
            if (tcx < trx || tcx > trx + trw || tcy < try_ || tcy > try_ + trh)
                return;
        } else {
            /* Non-type-0: hit test item rect */
            byte *fi = (byte *)focusedItem;
            float irx = ((itemDef_t *)fi)->window.rect[0].x, iry = ((itemDef_t *)fi)->window.rect[0].y;
            float irw = ((itemDef_t *)fi)->window.rect[0].w, irh = ((itemDef_t *)fi)->window.rect[0].h;
            float icx = (float)dc->cursorx, icy = (float)dc->cursory;
            CalcScreenX(&icx, 4);
            CalcScreenY(&icy, 4);
            CalcScreenPlacement(&irx, &irw, &iry, &irh, ((itemDef_t *)fi)->window.rect[0].horzAlign, ((itemDef_t *)fi)->window.rect[0].vertAlign);
            if (icx < irx || icx > irx + irw || icy < iry || icy > iry + irh)
                return;

            /* Check if editable type */
            if (itemType <= 0x12 && ((1 << itemType) & 0x70210)) {
                editFieldDef_t *ep = Item_GetEditFieldDef((itemDef_t *)focusedItem);
                if (ep)
                    ep->paintOffset = 0;
                Item_SetCursorPos((itemDef_t *)focusedItem, 0);
                g_editingField = 1;
                g_editItem = (itemDef_t *)focusedItem;
                Key_SetOverstrikeMode(1);
                return;
            }
        }

        /* Run action script on the focused item */
        if ((void *)((itemDef_t *)focusedItem)->action)
            Item_RunScript(dc, (itemDef_t *)focusedItem, ((itemDef_t *)focusedItem)->action);
        return;
    }

    /* Enter (0xd), numpad enter (0xbf), mouse3 (0xca) */
    if (key == 0xd || key == 0xbf || key == 0xca) {
        if (!focusedItem) return;
        /* Check for editable type */
        int ftype = ((itemDef_t *)focusedItem)->type;
        if (ftype <= 0x12 && ((1 << ftype) & 0x70210)) {
            Item_SetCursorPos((itemDef_t *)focusedItem, 0);
            g_editingField = 1;
            g_editItem = (itemDef_t *)focusedItem;
            Key_SetOverstrikeMode(1);
        } else if (focusedItem) {
            if ((void *)((itemDef_t *)focusedItem)->action)
                Item_RunScript(dc, (itemDef_t *)focusedItem, ((itemDef_t *)focusedItem)->action);
        }
        return;
    }

done:
    return;
}

/* Item_Paint — paint an item: visibility checks, fade/slide/orbit animation, type dispatch */
void Item_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent = (byte *)item->parent;
    int flags;
    rectDef_t newRect;

    diag_item_paint_enter(item);

    flags = item->window.dynamicFlags[0];

    /* Orbit animation (flag 0x2000) */
    if (flags & 0x2000) {
        int dcTime = dc->realTime;
        if (dcTime > item->window.nextTime) {
            /* Update next trigger time */
            item->window.nextTime = dcTime + item->window.offsetTime[0];

            /* Compute half-width/half-height */
            float w = item->window.rectClient[0].w * 0.5f;
            float h = item->window.rectClient[0].h * 0.5f;

            /* Relative position from rectClient center to rect center */
            float rx = item->window.rectClient[0].x + w - item->window.rectEffects0[0].x;
            float ry = item->window.rectClient[0].y + h - item->window.rectEffects0[0].y;

            /* 3-degree rotation */
            float angle;
            *(int *)&angle = 0x3d567750; /* ~3 degrees in radians */
            float sin_a = sinf(angle);
            float cos_a = cosf(angle);

            /* Copy w/h/align from rect */
            newRect.w = item->window.rectClient[0].w;
            newRect.h = item->window.rectClient[0].h;
            newRect.horzAlign = item->window.rectClient[0].horzAlign;
            newRect.vertAlign = item->window.rectClient[0].vertAlign;

            /* Rotate and offset: newRect.x = rx*cos - ry*sin + rectClient.x - w */
            newRect.x = rx * cos_a - ry * sin_a + item->window.rectEffects0[0].x - w;
            /* newRect.y = rx*sin + ry*cos + rectClient.y - h */
            newRect.y = rx * sin_a + ry * cos_a + item->window.rectEffects0[0].y - h;

            /* Apply new client rect */
            ((void (*)(void *, void *))Window_SetRectClient)(item, &newRect);

            /* Update screen coords from parent */
            byte *p = (byte *)item->parent;
            if (p) {
                float px = ((menuDef_t *)p)->window.rect[0].x;
                float py = ((menuDef_t *)p)->window.rect[0].y;
                if (((menuDef_t *)p)->window.border) {
                    float borderSize = ((menuDef_t *)p)->window.borderSize;
                    px += borderSize;
                    py += borderSize;
                }
                ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                    item, px, py, ((menuDef_t *)p)->window.rect[0].horzAlign, ((menuDef_t *)p)->window.rect[0].vertAlign);
            }

            /* Re-read flags and re-check */
            flags = item->window.dynamicFlags[0];
        }
    }

    /* Slide animation (flag 0x80) */
    if (flags & 0x80) {
        int dcTime = dc->realTime;
        if (dcTime > item->window.nextTime) {
            /* Update next trigger time */
            item->window.nextTime = dcTime + item->window.offsetTime[0];

            /* Target = effects0 rect at 0xf8, step = effects1 rect at 0x158 */
            float *target = (float *)item->window.rectEffects0;
            float *step = (float *)item->window.rectEffects1;
            int done = 0;

            /* Copy current rect to newRect */
            newRect = item->window.rectClient[0];

            /* Slide x toward target */
            if (newRect.x == target[0]) {
                done++;
            } else if (target[0] > newRect.x) {
                newRect.x += step[0];
                if (newRect.x > target[0]) {
                    newRect.x = target[0];
                    done++;
                }
            } else {
                newRect.x -= step[0];
                if (newRect.x < target[0]) {
                    newRect.x = target[0];
                    done++;
                }
            }

            /* Slide y toward target */
            if (newRect.y == target[1]) {
                done++;
            } else if (target[1] > newRect.y) {
                newRect.y += step[1];
                if (newRect.y > target[1]) {
                    newRect.y = target[1];
                    done++;
                }
            } else {
                newRect.y -= step[1];
                if (newRect.y < target[1]) {
                    newRect.y = target[1];
                    done++;
                }
            }

            /* Slide w toward target */
            if (newRect.w == target[2]) {
                done++;
            } else if (target[2] > newRect.w) {
                newRect.w += step[2];
                if (newRect.w > target[2]) {
                    newRect.w = target[2];
                    done++;
                }
            } else {
                newRect.w -= step[2];
                if (newRect.w < target[2]) {
                    newRect.w = target[2];
                    done++;
                }
            }

            /* Slide h toward target */
            if (newRect.h == target[3]) {
                done++;
            } else if (target[3] > newRect.h) {
                newRect.h += step[3];
                if (newRect.h > target[3]) {
                    newRect.h = target[3];
                    done++;
                }
            } else {
                newRect.h -= step[3];
                if (newRect.h < target[3]) {
                    newRect.h = target[3];
                    done++;
                }
            }

            /* Apply new client rect */
            ((void (*)(void *, void *))Window_SetRectClient)(item, &newRect);

            /* Update screen coords from parent */
            byte *p = (byte *)item->parent;
            if (p) {
                float px = ((menuDef_t *)p)->window.rect[0].x;
                float py = ((menuDef_t *)p)->window.rect[0].y;
                if (((menuDef_t *)p)->window.border) {
                    float borderSize = ((menuDef_t *)p)->window.borderSize;
                    px += borderSize;
                    py += borderSize;
                }
                ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                    item, px, py, ((menuDef_t *)p)->window.rect[0].horzAlign, ((menuDef_t *)p)->window.rect[0].vertAlign);
            }

            /* If all 4 coords reached target, remove slide flag */
            if (done == 4) {
                Window_RemoveDynamicFlags(item, 0x80);
            }
        }
    }

    /* Owner draw visibility check */
    {
        int ownerDraw = item->window.ownerDrawFlags;
        if (ownerDraw) {
            if (!UI_OwnerDrawVisible(ownerDraw)) {
                Window_RemoveDynamicFlags(item, 4);
            } else {
                Window_AddDynamicFlags(item, 4);
            }
        }
    }

    /* Dvar show/hide check */
    if (((byte *)&item->dvarFlags)[0] & 0xc) {
        if (!Item_EnableShowViaDvar(item, 4)) {
            /* Check for auto-action: visible + focused → simulate enter key */
            flags = item->window.dynamicFlags[0];
            if ((flags & 4) && (flags & 2)) {
                Menu_HandleKey(dc, (menuDef_t *)parent, 0x9b, 1);
                Menu_HandleKey(dc, (menuDef_t *)parent, 0x9b, 0);
            }
            diag_item_paint_skip(item, 0);
            return;
        }
    }

    /* Check visible flag */
    if (!(((byte *)item->window.dynamicFlags)[0] & 4)) {
        diag_item_paint_skip(item, 0);
        return;
    }

    /* BorderStyle 6: update material from dvar */
    if (item->window.style == 6) {
        const char *dvarStr = Dvar_GetString(item->dvar);
        item->window.background = (int)CL_RegisterMaterialNoMip(dvarStr);
    }

    /* Main paint */
    diag_item_paint_draw(item);

    Window_Paint(dc, (void *)item,
        ((menuDef_t *)parent)->fadeAmount, ((menuDef_t *)parent)->fadeInAmount,
        ((menuDef_t *)parent)->fadeClamp, (float)((menuDef_t *)parent)->fadeCycle);

    /* Debug mode: draw textRect outline */
    if (debugMode) {
        float adjusted_y;
        memset(&rect, 0, sizeof(rect));
        rect.x = item->textRect[0].x;
        rect.y = item->textRect[0].y;
        rect.w = item->textRect[0].w;
        rect.h = item->textRect[0].h;
        rect.horzAlign = item->textRect[0].horzAlign;
        rect.vertAlign = item->textRect[0].vertAlign;

        if (rect.w != 0.0f) {
            adjusted_y = rect.y - rect.h;
        } else {
            adjusted_y = rect.y;
        }

        {
            float color[4] = {0.0f, 1.0f, 0.0f, 1.0f};
            UI_DrawRect(rect.x, adjusted_y, rect.w, rect.h, rect.horzAlign, rect.vertAlign, 1.0f, color);
        }
    }

    /* Skip type dispatch for borderStyle 6 */
    if (item->window.style == 6) {
        diag_item_paint_skip(item, 0);
        return;
    }

    /* Type dispatch */
    {
        int itemType = item->type;
        switch (itemType) {
        case 0: /* text */
        case 1:
            Item_Text_Paint(dc, item);
            break;
        case 4: /* text field */
        case 9:
        case 0x10:
        case 0x11:
        case 0x12:
            Item_TextField_Paint(dc, item);
            break;
        case 6: /* list box */
            Item_ListBox_Paint(dc, item);
            break;
        case 8: /* owner draw */
            Item_OwnerDraw_Paint(dc, item);
            break;
        case 0xa: /* slider */
            Item_Slider_Paint(dc, item);
            break;
        case 0xb: /* yes/no */
            Item_YesNo_Paint(dc, item);
            break;
        case 0x0c: /* multi */ {
            const char *text;
            multiDef_t *multiDef = Item_GetMultiDef(item);
            if (!multiDef) {
                text = str_002ac388; /* "<dvarStrList or dvarFloatList not set>" */
            } else if (multiDef->strDef) {
                /* String-based multi: match dvar string value to dvarStr entries */
                const char *value = Dvar_GetVariantString(item->dvar);
                int j;
                text = str_002157b8; /* empty string */
                for (j = 0; j < multiDef->count; j++) {
                    if (I_stricmp(value, multiDef->dvarStr[j]) == 0) {
                        text = multiDef->dvarList[j];
                        break;
                    }
                }
            } else {
                /* Float-based multi: match dvar float value to dvarValue entries */
                const char *value = Dvar_GetVariantString(item->dvar);
                float fval = (float)atof(value);
                int j;
                text = str_002157b8; /* empty string */
                for (j = 0; j < multiDef->count; j++) {
                    if (fval == multiDef->dvarValue[j]) {
                        text = multiDef->dvarList[j];
                        break;
                    }
                }
            }
            /* Item_List_Paint uses register calling convention: eax=dc, edx=item, ecx=text */
            __asm__ __volatile__ (
                "calll Item_List_Paint\n"
                :
                : "a"(dc), "d"(item), "c"(text)
                : "memory", "xmm0", "xmm1", "xmm2", "xmm3"
            );
            break;
        }
        case 0x0d: /* enum dvar */ {
            const char *text;
            const char *enumDvarName = item->typeData.enumDvarName;
            if (!enumDvarName) {
                text = str_002ac3b0; /* "<dvarEnumList not set>" */
            } else {
                struct dvar_s *dvar = Dvar_FindVar(enumDvarName);
                if (dvar->type != 6) {
                    /* Not an enum dvar */
                    text = str_002ac3c8; /* "<not an enum dvar>" */
                } else if (dvar->domain.enumeration.stringCount == 0) {
                    /* No enum entries */
                    text = str_002157b8; /* empty string */
                } else {
                    /* Try to match by integer index first */
                    struct dvar_s *dvar2 = Dvar_FindVar(item->typeData.enumDvarName);
                    if (dvar2->type != 6) {
                        goto enum_not_found;
                    }
                    {
                        const char *enumString = Dvar_GetVariantString(item->dvar);
                        int idx = atoi(enumString);
                        int enumCount = dvar2->domain.enumeration.stringCount;
                        if (idx >= 0 && idx < enumCount) {
                            const char **strings = dvar->domain.enumeration.strings;
                            text = strings[idx];
                        } else {
                            /* Try string match */
                            int j;
                            text = str_002157b8;
                            for (j = 0; j < enumCount; j++) {
                                const char **strings = dvar->domain.enumeration.strings;
                                if (I_stricmp(enumString, strings[j]) == 0) {
                                    text = strings[j];
                                    goto enum_found;
                                }
                            }
                            enum_not_found:
                            idx = 0;
                            {
                                const char **strings = dvar->domain.enumeration.strings;
                                text = strings[idx];
                            }
                        }
                    }
                    enum_found:;
                }
            }
            /* Item_List_Paint uses register calling convention: eax=dc, edx=item, ecx=text */
            __asm__ __volatile__ (
                "calll Item_List_Paint\n"
                :
                : "a"(dc), "d"(item), "c"(text)
                : "memory", "xmm0", "xmm1", "xmm2", "xmm3"
            );
            break;
        }
        case 0x0e: /* bind */
            Item_Bind_Paint(dc, item);
            break;
        default:
            break;
        }
    }

    diag_item_paint_skip(item, 0);
}

/* Menu_Paint — paint a menu: background, window, items, debug rect */
void Menu_Paint(displayContextDef_t *dc, menuDef_t *menu, qboolean forcePaint)
{
    byte *m = (byte *)menu;
    int i;

    if (!menu) return;

    /* Check visibility */
    if (!(((byte *)&menu->window.dynamicFlags[0])[0] & 4)) {
        if (!forcePaint) return;
    }

    /* Owner draw visibility check */
    int ownerDrawFlags = menu->window.ownerDrawFlags;
    if (ownerDrawFlags) {
        if (!UI_OwnerDrawVisible(ownerDrawFlags))
            return;
    }

    /* Play sound */
    if ((void *)menu->soundName)
        UI_PlayLocalSoundAliasByName(menu->soundName);

    /* Handle fade amount / cursor distance */
    float fadeAmount = menu->blurRadius;
    if (fadeAmount != 0.0f) {
        float cursorDist = dc->blurRadiusOut;
        float dist = sqrtf(fadeAmount * fadeAmount + cursorDist * cursorDist);
        dc->blurRadiusOut = dist;
        if (!forcePaint)
            goto paint_content;
    } else if (!forcePaint) {
        goto paint_content;
    }

    /* forcePaint path — remove from openMenus + re-add (bring to front) */
    Window_AddDynamicFlags((void *)m, 0x4000);

    /* Remove menu from openMenus */
    byte *d = (byte *)dc;
    int openCount = dc->openMenuCount;
    int removeIdx = -1;
    for (i = openCount - 1; i >= 0; i--) {
        if ((void *)dc->menuStack[i] == menu) {
            removeIdx = i;
            break;
        }
    }
    if (removeIdx >= 0) {
        dc->openMenuCount = openCount - 1;
        for (i = removeIdx; i < dc->openMenuCount; i++)
            dc->menuStack[i] = dc->menuStack[i + 1];
    }

    /* Re-add to end */
    if (dc->openMenuCount == 0x10)
        Com_Error(1, "\x15Too many menus opened");
    int idx = dc->openMenuCount;
    dc->menuStack[idx] = menu;
    dc->openMenuCount = idx + 1;

paint_content:
    /* Draw fullscreen background if present */
    if (menu->fullScreen && menu->window.background) {
        ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
            0.0f, 0.0f, 640.0f, 480.0f,
            menu->window.rect[0].horzAlign, menu->window.rect[0].vertAlign, NULL,
            menu->window.background);
    }

    /* Paint the window */
    Window_Paint(dc, (void *)m,
        menu->fadeAmount, menu->fadeInAmount,
        menu->fadeClamp, (float)menu->fadeCycle);

    /* Paint items */
    int itemCount = menu->itemCount;
    if (itemCount > 0) {
        for (i = 0; i < itemCount; i++) {
            itemDef_t *item = *(itemDef_t **)(menu->items + i * 4);
            Item_Paint(dc, item);
        }
    }

    /* Debug mode: draw rect outline */
    if (debugMode) {
        float color[4] = {1.0f, 1.0f, 0.0f, 1.0f};
        UI_DrawRect(menu->window.rect[0].x, menu->window.rect[0].y, menu->window.rect[0].w, menu->window.rect[0].h,
            menu->window.rect[0].horzAlign, menu->window.rect[0].vertAlign, 1.0f, color);
    }
}

/* Menu_PaintAll — paint all menus: non-open first, then open from fullscreen, debug FPS */
void Menu_PaintAll(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    int i, j;

    /* Clear cursor distance */
    dc->blurRadiusOut = 0.0f;

    /* Call capture function if active */
    if (captureFunc)
        captureFunc(dc, captureData);

    int menuCount = dc->menuCount;
    int openCount = dc->openMenuCount;

    /* Paint non-open menus */
    for (i = 0; i < menuCount; i++) {
        void *menu = (void *)dc->Menus[i];
        /* Check if this menu is in the openMenus list */
        int isOpen = 0;
        for (j = openCount - 1; j >= 0; j--) {
            if (dc->menuStack[j] == menu) {
                isOpen = 1;
                break;
            }
        }
        if (!isOpen)
            Menu_Paint(dc, (menuDef_t *)menu, 0);
        openCount = dc->openMenuCount;
    }

    /* Find first fullscreen menu in open stack (from end) */
    openCount = dc->openMenuCount;
    int fullscreenStart = 0;
    for (i = openCount - 1; i >= 0; i--) {
        menuDef_t *menu = dc->menuStack[i];
        if (menu->fullScreen) {
            fullscreenStart = i;
            break;
        }
    }

    /* Paint open menus from fullscreen start to end */
    if (fullscreenStart < openCount) {
        for (i = fullscreenStart; i < dc->openMenuCount; i++) {
            void *menu = (void *)dc->menuStack[i];
            Menu_Paint(dc, (menuDef_t *)menu, 0);
        }
    }

    /* Debug mode: draw FPS */
    if (debugMode) {
        float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        float scale = 0.5f;
        FontHandle font = UI_GetFontHandle(0, scale);
        const char *fpsText = va("fps: %f", (double)dc->FPS);
        UI_DrawText(fpsText, 0x7fffffff, font, 5.0f, 25.0f, 0, 0, scale, color, 0);
    }
}

/* Menus_HandleOOBClick — handle click outside focused menu: find target menu, re-focus, dispatch */
void Menus_HandleOOBClick(displayContextDef_t *dc, menuDef_t *menu, int key, qboolean down)
{
    byte *d = (byte *)dc;
    byte *m = (byte *)menu;
    int i, j, k;

    if (!menu) return;

    /* If down and menu has closeOnOOB flag, close it first */
    if (down) {
        if (((byte *)&menu->window.staticFlags)[3] & 2) {
            /* Run onClose script if visible */
            if ((((byte *)&menu->window.dynamicFlags[0])[0] & 4) && (void *)menu->onClose) {
                byte tempItem[0x2a0];
                ((itemDef_t *)tempItem)->parent = (menuDef_t *)menu;
                Item_RunScript(dc, (itemDef_t *)tempItem, menu->onClose);
            }
            Window_RemoveDynamicFlags((void *)menu, 6);
        }
        /* Fall through to check_open_menus */
    }

    /* Iterate open menus from end to find which one cursor is in */
    int openCount = dc->openMenuCount;
    float cx = (float)dc->cursorx;
    float cy = (float)dc->cursory;
    int targetIdx = -1;

    for (i = openCount - 1; i >= 0; i--) {
        byte *openMenu = (byte *)dc->menuStack[i];
        if (!openMenu) continue;
        if ((((menuDef_t *)openMenu)->window.dynamicFlags[0] & 0x4004) == 0) continue;

        /* Hit-test menu rect */
        float rx = ((menuDef_t *)openMenu)->window.rect[0].x, ry = ((menuDef_t *)openMenu)->window.rect[0].y;
        float rw = ((menuDef_t *)openMenu)->window.rect[0].w, rh = ((menuDef_t *)openMenu)->window.rect[0].h;
        float testX = cx, testY = cy;
        CalcScreenX(&testX, 4);
        CalcScreenY(&testY, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, ((menuDef_t *)openMenu)->window.rect[0].horzAlign, ((menuDef_t *)openMenu)->window.rect[0].vertAlign);
        if (testX < rx || testX > rx + rw || testY < ry || testY > ry + rh)
            continue;

        /* Cursor is inside this menu — check items */
        int itemCount = ((menuDef_t *)openMenu)->itemCount;
        if (itemCount <= 0) continue;

        for (j = 0; j < itemCount; j++) {
            itemDef_t *item = ((menuDef_t *)openMenu)->items[j];
            if ((item->window.dynamicFlags[0] & 0x4004) == 0) continue;
            if (item->window.staticFlags & 0x100000) continue;

            /* Hit-test item rect */
            float irx = item->window.rect[0].x, iry = item->window.rect[0].y;
            float irw = item->window.rect[0].w, irh = item->window.rect[0].h;
            float itx = cx, ity = cy;
            CalcScreenX(&itx, 4);
            CalcScreenY(&ity, 4);
            CalcScreenPlacement(&irx, &irw, &iry, &irh, item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);
            if (itx < irx || itx > irx + irw || ity < iry || ity > iry + irh)
                continue;

            /* Check text rect if item has type and text */
            int itemType = item->type;
            if (itemType != 0 && (int)(uintptr_t)item->text) {
                /* Build text rect and hit-test */
                int textBuf[6];
                memset(textBuf, 0, 24);
                *(float *)&textBuf[0] = item->textRect[0].x;
                *(float *)&textBuf[1] = item->textRect[0].y;
                *(float *)&textBuf[2] = item->textRect[0].w;
                *(float *)&textBuf[3] = item->textRect[0].h;
                textBuf[4] = item->textRect[0].horzAlign;
                textBuf[5] = item->textRect[0].vertAlign;
                float trY = *(float *)&textBuf[1];
                if (*(float *)&textBuf[2] != 0.0f)
                    trY -= *(float *)&textBuf[3];
                float trx2 = *(float *)&textBuf[0], trw2 = *(float *)&textBuf[2];
                float try2 = trY, trh2 = *(float *)&textBuf[3];
                float ttx = cx, tty = cy;
                CalcScreenX(&ttx, 4);
                CalcScreenY(&tty, 4);
                CalcScreenPlacement(&trx2, &trw2, &try2, &trh2, textBuf[4], textBuf[5]);
                if (ttx < trx2 || ttx > trx2 + trw2 || tty < try2 || tty > try2 + trh2)
                    continue;
            }

            targetIdx = i;
            goto found;
        }
    }

    /* No target found */
    goto count_visible;

found:;
    /* Re-focus the target menu */
    openCount = dc->openMenuCount;
    for (i = openCount - 1; i >= 0; i--)
        Window_RemoveDynamicFlags((void *)dc->menuStack[i], 2);

    Window_AddDynamicFlags((void *)dc->menuStack[targetIdx], 6);
    Display_MouseMove(dc, NULL, dc->cursorx, dc->cursory);
    Menu_HandleMouseMove(dc, (menuDef_t *)dc->menuStack[targetIdx], (float)dc->cursorx, (float)dc->cursory);
    Menu_HandleKey(dc, (menuDef_t *)dc->menuStack[targetIdx], key, down);

count_visible:;
    /* Count visible menus */
    int menuCount = dc->menuCount;
    int visCount = 0;
    for (i = 0; i < menuCount; i++) {
        byte *cm = (byte *)dc->Menus[i];
        if ((((menuDef_t *)cm)->window.dynamicFlags[0] & 0x4004) != 0)
            visCount++;
    }

    if (visCount > 0) {
        UI_Pause(0);
        /* Stop all cinematics in open menus */
        openCount = dc->openMenuCount;
        for (i = openCount - 1; i >= 0; i--) {
            byte *openMenu = (byte *)dc->menuStack[i];
            if (!openMenu) continue;
            /* Stop cinematic on menu if borderStyle == 5 */
            if (((menuDef_t *)openMenu)->window.style == 5) {
                int cinHandle = ((menuDef_t *)openMenu)->window.cinematic;
                if (cinHandle >= 0) {
                    CIN_StopCinematic(cinHandle);
                    ((menuDef_t *)openMenu)->window.cinematic = -1;
                }
            }
            /* Stop cinematics on items */
            int ic = ((menuDef_t *)openMenu)->itemCount;
            for (j = 0; j < ic; j++) {
                itemDef_t *item = ((menuDef_t *)openMenu)->items[j];
                if (item->window.style == 5) {
                    int ch = item->window.cinematic;
                    if (ch >= 0) {
                        CIN_StopCinematic(ch);
                        item->window.cinematic = -1;
                    }
                }
                if (item->type == 8)
                    CIN_StopCinematic(-item->window.ownerDraw);
            }
        }
    } else {
        UI_Pause(0);
    }
}
#else
/* Register-convention: eax=dc, edx=item. In Emscripten, callers use wrapper. */
static void Scroll_Slider_SetThumbPos_impl(displayContextDef_t *dc, itemDef_t *item)
{
    editFieldDef_t *editDef;
    float rightEdge;
    float cursorx;
    float usableStart, usableWidth;
    float yIgnored, hIgnored;
    float thumbPos, thumbFrac;
    float minVal, maxVal;

    editDef = Item_GetEditFieldDef(item);
    if (!editDef)
        return;

    /* Compute right edge of slider */
    if ((int)(uintptr_t)item->text) {
        /* item has rect offset: item->rect.x + item->rect.w + 8.0f */
        rightEdge = item->textRect[0].x + item->textRect[0].w + 8.0f;
    } else {
        /* item->rect.x */
        rightEdge = item->window.rect[0].x;
    }

    /* Get cursor screen position */
    cursorx = (float)dc->cursorx;
    CalcScreenX(&cursorx, 4);

    /* Compute usable slider area */
    usableStart = rightEdge + 5.0f + 1.0f;
    usableWidth = 84.0f; /* 0x42a80000 */
    yIgnored = 0.0f;
    hIgnored = 0.0f;

    CalcScreenPlacement(&usableStart, &usableWidth, &yIgnored, &hIgnored,
                        item->window.rect[0].horzAlign, item->window.rect[0].vertAlign);

    /* Clamp cursor position to usable range */
    thumbPos = cursorx - usableStart;
    if (thumbPos < 0.0f)
        thumbPos = 0.0f;
    else if (thumbPos > usableWidth)
        thumbPos = usableWidth;

    thumbFrac = thumbPos / usableWidth;

    /* Compute value from fraction */
    minVal = editDef->minVal;
    maxVal = editDef->maxVal;
    {
        float value = minVal + (maxVal - minVal) * thumbFrac;
        const char *valStr = va("%g", (double)value);
        Dvar_SetFromStringByName(item->dvar, valStr);
    }
}
#endif
