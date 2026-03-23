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
/* Register-convention trampoline: eax=execWhen, ecx=args, 8(%ebp)=shouldExec.
   In Emscripten mode, stub is never called - callers use _impl directly. */
static void Script_ConditionalExecHandler(int execWhen, Bool (*shouldExec)()) { (void)execWhen; (void)shouldExec; }

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

    if (!(*(LegacyHacks **)imp_legacyHacks)->ui_scriptMenuAllowResponse)
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
