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
extern float Item_GetCursorPosOffset(itemDef_t *item);
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
extern bind_t g_bindings[56]; /* g_bindings */

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
    byte *m = (byte *)menu;
    int itemCount = *(int *)(m + 0x218);
    const char *wc = strchr(name, '*');
    int wildcard = wc ? (int)(wc - name) : -1;
    int count = 0;
    int i;

    for (i = 0; i < itemCount; i++) {
        byte *item = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
        const char *itemName = *(const char **)(item + 0xc0);
        const char *itemGroup = *(const char **)(item + 0xc4);

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
    byte *m = (byte *)menu;
    int itemCount = *(int *)(m + 0x218);
    const char *wc = strchr(name, '*');
    int wildcard = wc ? (int)(wc - name) : -1;
    int count = 0;
    int i;

    for (i = 0; i < itemCount; i++) {
        byte *item = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
        const char *itemName = *(const char **)(item + 0xc0);
        const char *itemGroup = *(const char **)(item + 0xc4);
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
                return (itemDef_t *)item;
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
        out = (float *)((byte *)item + 0x1dc);
        Window_AddDynamicFlags((void *)item, 0x8000);
    } else if (I_stricmp(name, "forecolor") == 0) {
        out = (float *)((byte *)item + 0x1cc);
        Window_AddDynamicFlags((void *)item, 0x10000);
    } else if (I_stricmp(name, "bordercolor") == 0) {
        out = (float *)((byte *)item + 0x1ec);
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
        *(MaterialHandle *)(it + 0x20c) = CL_RegisterMaterialNoMip(name);
    }
}

/* Menu_ShowItemByName — show/hide matching items by group name */
void Menu_ShowItemByName(menuDef_t *menu, const char *p, qboolean bShow)
{
    int count = Menu_ItemsMatchingGroup(menu, p);
    int i;
    for (i = 0; i < count; i++) {
        byte *item = (byte *)Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;
        if (bShow) {
            Window_AddDynamicFlags((void *)item, 4);
        } else {
            Window_RemoveDynamicFlags((void *)item, 4);
            int cinHandle = *(int *)(item + 0xcc);
            if (cinHandle >= 0) {
                CIN_StopCinematic(cinHandle);
                *(int *)(item + 0xcc) = -1;
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
        byte *item = (byte *)Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;
        if (fadeOut) {
            Window_AddDynamicFlags((void *)item, 0x14);  /* fade out + visible */
            Window_RemoveDynamicFlags((void *)item, 0x20);
        } else {
            Window_AddDynamicFlags((void *)item, 0x24);  /* fade in + visible */
            Window_RemoveDynamicFlags((void *)item, 0x10);
        }
    }
}

/* Menus_FindByName — find menu by name (case-insensitive) */
menuDef_t * Menus_FindByName(displayContextDef_t *dc, const char *p)
{
    byte *d = (byte *)dc;
    int count = *(int *)(d + 0x22c);
    int i;
    for (i = 0; i < count; i++) {
        byte *menu = *(byte **)(d + 0x2c + i * 4);
        const char *menuName = *(const char **)(menu + 0xc0);
        if (I_stricmp(menuName, p) == 0)
            return (menuDef_t *)menu;
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

    if (!*(byte *)(*(byte **)imp_legacyHacks + 0x4ed))
        return;

    if (!String_Parse(args, val, 0x400))
        return;

    iIndex = -1;
    for (int i = 0; i < 0x20; i++) {
        const char *cs = CL_GetConfigString(0x4de + i);
        if (cs[0] == '\0')
            continue;
        /* item->parent->window.name */
        const char *menuName = *(const char **)(*(byte **)(it + 0x29c) + 0xc0);
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

    I_strncat(script, s, 0x400);
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
    byte *entry = (byte *)g_bindings;
    char b[0x100];

    while (entry != (byte *)updateScreenCalled) {
        const char *command = *(const char **)entry;
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

        *(int *)(entry + 0xc) = twokeys[0];
        *(int *)(entry + 0x10) = twokeys[1];
        entry += 0x14;
    }
}

/* Controls_SetConfig — iterate g_bindings, apply key bindings, exec bindingsave */
extern void Key_SetBinding(int key, const char *command);
extern byte szShotName[];
void Controls_SetConfig(qboolean restart)
{
    (void)restart;
    /* g_bindings: 20-byte entries {name, ?, ?, key1, key2}. offset 12 = key1, 16 = key2, 0 = command */
    byte *entry = (byte *)g_bindings + 12;
    byte *endPtr = szShotName + 8;
    while (entry != endPtr) {
        int key1 = *(int *)entry;
        if (key1 != -1)
            Key_SetBinding(key1, *(const char **)(entry - 12));
        int key2 = *(int *)(entry + 4);
        if (key2 != -1)
            Key_SetBinding(key2, *(const char **)(entry - 12));
        entry += 20;
    }
    Cbuf_ExecuteText(2, "bindingsave\n");
}

/* line 4381 */
void Controls_SetDefaults(void)
{
    byte *p = (byte *)g_bindings;
    do {
        *(int *)(p + 0xc) = *(int *)(p + 4);
        *(int *)(p + 0x10) = *(int *)(p + 8);
        p += 0x14;
    } while (p != (byte *)updateScreenCalled);
}

/* BindingFromName — find key binding for a command name, format display string */
void BindingFromName(const char *dvar, char *nameBind)
{
    int i;
    for (i = 0; i < 0x38; i++) {
        byte *entry = (byte *)g_bindings + i * 0x14;
        if (I_stricmp(dvar, *(const char **)entry) != 0)
            continue;

        int key1 = *(int *)(entry + 12);
        if (key1 == -1)
            break;

        Key_KeynumToStringBuf(key1, nameBind, 0x20);
        I_strncpyz(nameBind, UI_SafeTranslateString(nameBind), 0x80);

        int key2 = *(int *)(entry + 16);
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
        byte *entry = (byte *)g_bindings + i * 20;
        if (I_stricmp(command, *(const char **)entry) == 0) {
            if (*(int *)(entry + 12) != -1)
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
        byte *entry = (byte *)g_bindings + i * 0x14;
        if (I_stricmp(command, *(const char **)entry) != 0)
            continue;

        int key1 = *(int *)(entry + 12);
        if (key1 == -1)
            break;

        Key_KeynumToStringBuf(key1, bindings[0], 0x80);

        int key2 = *(int *)(entry + 16);
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
    return *(int *)((byte *)dc + 0x22c);
}

/* UI_AddMenuList — add all menus from a MenuList into the dc menu array */
void UI_AddMenuList(displayContextDef_t *dc, MenuList *menuList)
{
    byte *d = (byte *)dc;
    int *menuCount = (int *)(d + 0x22c);
    int i;

    if (!menuList)
        return;
    if (*(int *)menuList <= 0)
        return;

    for (i = 0; i < *(int *)menuList; i++) {
        void *menu = ((void **)*(int *)((byte *)menuList + 4))[i];
        if (*menuCount > 0x7f)
            Com_Error(1, "UI_AddMenu: Maximum number of menus %d exceeded.", 0x80);
        *(void **)(d + 0x2c + *menuCount * 4) = menu;
        *menuCount += 1;
    }
}

/* Item_MouseLeave — run mouse leave scripts, remove hover/focus dynamic flags */
void Item_MouseLeave(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    if (!item) return;
    if (*(byte *)(it + 0xe8) & 0x40) {
        /* Has focus script — run it, remove focus flag */
        Item_RunScript(dc, item, *(const char **)(it + 0x2a4));
        Window_RemoveDynamicFlags((void *)item, 0x40);
    }
    /* Run mouse leave script, remove hover+highlight flags */
    Item_RunScript(dc, item, *(const char **)(it + 0x2ac));
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

    if (*(int *)(it + 0x294))
        baseX = *(float *)(it + 0x210) + *(float *)(it + 0x218) + 8.0f;
    else
        baseX = *(float *)it;

    value = Dvar_GetFloat(*(const char **)(it + 0x2c0));
    minVal = *(float *)editDef;
    maxVal = *((float *)editDef + 1);

    if (value < minVal)
        value = minVal;
    else if (value > maxVal)
        value = maxVal;

    return baseX + 1.0f + 5.0f + ((value - minVal) / (maxVal - minVal)) * 84.0f;
}

/* Menu_CheckOnKey — check if key matches any menu or item onKey handler */
qboolean Menu_CheckOnKey(displayContextDef_t *dc, menuDef_t *menu, int key)
{
    byte *m = (byte *)menu;
    byte tempItem[0x2a0];
    int i;

    /* Check menu-level onKey list at offset 0x250 */
    byte *node = *(byte **)(m + 0x250);
    while (node) {
        if (*(int *)node == key) {
            *(void **)&tempItem[0x29c] = menu;
            Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(node + 4));
            return 1;
        }
        node = *(byte **)(node + 8);
    }

    /* Check per-item onKey lists */
    int itemCount = *(int *)(m + 0x218);
    for (i = 0; i < itemCount; i++) {
        byte *item = *(byte **)(*(byte **)(m + 0x27c) + i * 4);

        if (!(*(byte *)(item + 0xe8) & 4))
            continue;

        if (*(byte *)(item + 0x2d0) & 0xc) {
            if (!Item_EnableShowViaDvar((itemDef_t *)item, 4))
                continue;
        }

        node = *(byte **)(item + 0x2c8);
        while (node) {
            if (*(int *)node == key) {
                *(void **)&tempItem[0x29c] = menu;
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
    byte *d = (byte *)dc;
    int count = *(int *)(d + 0x270);
    int i;
    for (i = count - 1; i >= 0; i--) {
        byte *menu = *(byte **)(d + 0x230 + i * 4);
        if ((*(byte *)(menu + 0xe8) & 4) && *(int *)(menu + 0x214))
            return 1;
    }
    return 0;
}

/* Menu_GetFocused — find topmost visible+focused menu */
menuDef_t *Menu_GetFocused(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    int count = *(int *)(d + 0x270);
    int i;
    for (i = count - 1; i >= 0; i--) {
        byte *menu = *(byte **)(d + 0x230 + i * 4);
        int flags = *(int *)(menu + 0xe8);
        if ((flags & 4) && (flags & 2))
            return (menuDef_t *)menu;
    }
    return NULL;
}

/* Item_ListBox_MaxScroll — compute max scroll position based on item count and visible rows */
int Item_ListBox_MaxScroll(itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *listPtr = (byte *)Item_GetListBoxDef(item);
    int count = UI_FeederCount(*(int *)(it + 0x2d8));
    if (!listPtr) return 0;
    int visibleRows;
    if (*(byte *)(it + 0xe6) & 0x20) {
        /* Horizontal */
        visibleRows = (int)(*(float *)(it + 8) / *(float *)(listPtr + 0x34));
    } else {
        /* Vertical */
        visibleRows = (int)(*(float *)(it + 0xc) / *(float *)(listPtr + 0x38));
    }
    int maxScroll = count - visibleRows + 1;
    return (maxScroll >= 0) ? maxScroll : 0;
}

/* Item_ListBox_ThumbPosition — compute listbox thumb position from scroll state */
int Item_ListBox_ThumbPosition(itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *listPtr = (byte *)Item_GetListBoxDef(item);
    int maxScroll, startPos;
    float scrollArea, ratio;

    if (!listPtr)
        return 0;

    maxScroll = Item_ListBox_MaxScroll(item);
    startPos = *(int *)listPtr;

    if (*(byte *)(it + 0xe6) & 0x20) {
        /* Horizontal */
        scrollArea = *(float *)(it + 8) - 32.0f - 2.0f;
        ratio = (maxScroll > 0) ? (scrollArea - 16.0f) / (float)maxScroll : 0.0f;
        return (int)(ratio * (float)startPos + *(float *)it + 1.0f + 16.0f);
    } else {
        /* Vertical */
        scrollArea = *(float *)(it + 0xc) - 32.0f - 2.0f;
        ratio = (maxScroll > 0) ? (scrollArea - 16.0f) / (float)maxScroll : 0.0f;
        return (int)(ratio * (float)startPos + *(float *)(it + 4) + 1.0f + 16.0f);
    }
}

/* Item_ListBox_ThumbDrawPosition — thumb draw position, clamped to drag cursor */
int Item_ListBox_ThumbDrawPosition(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;

    if ((itemDef_t *)item != itemCapture)
        return Item_ListBox_ThumbPosition(item);

    if (*(byte *)(it + 0xe6) & 0x20) {
        /* Horizontal */
        int max = (int)(*(float *)it + *(float *)(it + 8) - 32.0f - 1.0f);
        int cursor = *(int *)(d + 0xc);
        int minPos = (int)(*(float *)it + 16.0f + 1.0f) + 8;
        if (cursor < minPos || cursor > max + 8)
            return Item_ListBox_ThumbPosition((itemDef_t *)itemCapture);
        return cursor - 8;
    } else {
        /* Vertical */
        int max = (int)(*(float *)(it + 4) + *(float *)(it + 0xc) - 32.0f - 1.0f);
        int cursor = *(int *)(d + 0x10);
        int minPos = (int)(*(float *)(it + 4) + 16.0f + 1.0f) + 8;
        if (cursor < minPos || cursor > max + 8)
            return Item_ListBox_ThumbPosition((itemDef_t *)itemCapture);
        return cursor - 8;
    }
}

/* line 2908 */
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

/* line 779 */
__attribute__((naked))
void Menus_Close(displayContextDef_t *dc, menuDef_t *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 779 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x32c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dc */
        /* { scope 1: item */
        /* { scope 2 */
        "movl 0x270(%edi), %esi\n" /* line 695 */
        "movl %esi, %ebx\n" /* menuIndex */
        "subl $1, %ebx\n" /* menuIndex */
        "js .Lf16537c_001654c9\n"
        "movl 0xc(%ebp), %edx\n" /* line 697 | menu */
        "cmpl 0x230(%edi, %ebx, 4), %edx\n"
        "je .Lf16537c_00165526\n"
        "leal 0x230(%edi, %ebx, 4), %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf16537c_001653b5:\n"
        "cmpl %edx, %ebx\n" /* line 695 | menuIndex */
        "je .Lf16537c_001654c9\n"
        "movl -4(%ecx), %eax\n" /* line 697 */
        "addl $1, %edx\n"
        "subl $4, %ecx\n"
        "cmpl 0xc(%ebp), %eax\n" /* menu */
        "jne .Lf16537c_001653b5\n"
        "movl 0xc(%ebp), %eax\n" /* menu */
        /* } scope */
        ".Lf16537c_001653ce:\n"
        "movl 0xe8(%eax), %edx\n" /* line 143 */
        "testb $4, %dl\n" /* line 155 */
        "jne .Lf16537c_001654e7\n"
        "movb $0, -0x319(%ebp)\n"
        ".Lf16537c_001653e4:\n"
        "andb $4, %dl\n" /* line 769 */
        "je .Lf16537c_0016541b\n"
        "movl 0xc(%ebp), %edx\n" /* menu */
        "movl 0x248(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16537c_0016541b\n"
        /* { scope 2 */
        "movl %edx, -0x70(%ebp)\n" /* line 773 */
        "movl 0x248(%edx), %eax\n" /* line 774 */
        "movl %eax, 8(%esp)\n"
        "leal -0x30c(%ebp), %eax\n" /* item */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll Item_RunScript\n"
        "movl 0x270(%edi), %esi\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16537c_0016541b:\n"
        "movl %esi, %ebx\n" /* line 710 | menuIndex */
        "subl $1, %ebx\n" /* menuIndex */
        "js .Lf16537c_00165460\n"
        "movl 0xc(%ebp), %eax\n" /* line 712 | menu */
        "cmpl 0x230(%edi, %ebx, 4), %eax\n"
        "je .Lf16537c_0016552d\n"
        "leal 0x230(%edi, %ebx, 4), %ecx\n"
        "movl %ebx, %esi\n" /* menuIndex */
        "xorl %edx, %edx\n"
        ".Lf16537c_0016543d:\n"
        "subl $1, %esi\n" /* line 710 */
        "cmpl %edx, %ebx\n" /* menuIndex */
        "je .Lf16537c_00165460\n"
        "movl -4(%ecx), %eax\n" /* line 712 */
        "addl $1, %edx\n"
        "subl $4, %ecx\n"
        "cmpl %eax, 0xc(%ebp)\n" /* menu */
        "jne .Lf16537c_0016543d\n"
        ".Lf16537c_00165452:\n"
        "movl %ebx, 0x270(%edi)\n" /* line 714 | menuIndex */
        "cmpl %esi, %ebx\n" /* line 715 | menuIndex */
        "jg .Lf16537c_001654f8\n"
        /* } scope */
        ".Lf16537c_00165460:\n"
        "cmpb $0, -0x319(%ebp)\n" /* line 792 */
        "je .Lf16537c_001654c9\n"
        "movl 0x270(%edi), %eax\n" /* dc */
        "testl %eax, %eax\n"
        "je .Lf16537c_001654c9\n"
        "movl %eax, %esi\n" /* line 794 | menuNum */
        "subl $1, %esi\n" /* menuNum */
        "js .Lf16537c_001654c9\n"
        "movl 0x230(%edi, %esi, 4), %eax\n" /* line 796 | dc */
        "testb $4, 0xe8(%eax)\n"
        "jne .Lf16537c_00165522\n"
        "leal 0x230(%edi, %esi, 4), %ecx\n" /* dc */
        "movl %esi, %ebx\n" /* menuNum, menuIndex */
        "xorl %edx, %edx\n"
        ".Lf16537c_00165499:\n"
        "subl $1, %ebx\n" /* line 794 | menuIndex */
        "cmpl %edx, %esi\n" /* menuNum */
        "je .Lf16537c_001654c9\n"
        "movl -4(%ecx), %eax\n" /* line 796 */
        "addl $1, %edx\n"
        "subl $4, %ecx\n"
        "testb $4, 0xe8(%eax)\n"
        "je .Lf16537c_00165499\n"
        ".Lf16537c_001654b2:\n"
        "movl $2, 4(%esp)\n" /* line 798 */
        "movl 0x230(%edi, %ebx, 4), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        ".Lf16537c_001654c9:\n"
        "movl $6, 4(%esp)\n" /* line 807 */
        "movl 0xc(%ebp), %eax\n" /* menu */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        /* } scope */
        "addl $0x32c, %esp\n" /* line 808 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: item */
        ".Lf16537c_001654e7:\n"
        "movl %edx, %eax\n" /* line 155 */
        "shrl $1, %eax\n"
        "andb $1, %al\n"
        "movb %al, -0x319(%ebp)\n"
        "jmp .Lf16537c_001653e4\n"
        /* { scope 2 */
        ".Lf16537c_001654f8:\n"
        "leal 0x234(%edi, %esi, 4), %edx\n" /* line 779 | dc */
        "movl %esi, %ecx\n"
        "leal 0x230(%edi, %esi, 4), %ebx\n" /* dc, menuIndex */
        "subl %edx, %ebx\n" /* menuIndex */
        ".Lf16537c_0016550a:\n"
        "addl $1, %ecx\n" /* line 716 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx, %edx)\n" /* menuIndex */
        "addl $4, %edx\n"
        "cmpl %ecx, 0x270(%edi)\n" /* line 715 */
        "jg .Lf16537c_0016550a\n"
        "jmp .Lf16537c_00165460\n"
        /* } scope */
        ".Lf16537c_00165522:\n"
        "movl %esi, %ebx\n" /* line 796 | menuNum, menuIndex */
        "jmp .Lf16537c_001654b2\n"
        ".Lf16537c_00165526:\n"
        "movl %edx, %eax\n"
        "jmp .Lf16537c_001653ce\n"
        /* { scope 2 */
        ".Lf16537c_0016552d:\n"
        "movl %ebx, %esi\n" /* line 712 | menuIndex */
        "jmp .Lf16537c_00165452\n"
    );
}

/* Menus_CloseAll — close every open menu */
void Menus_CloseAll(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    int count = *(int *)(d + 0x22c);
    int i;
    for (i = 0; i < count; i++) {
        Menus_Close(dc, *(void **)(d + 0x2c + i * 4));
    }
}

/* line 3715 */
__attribute__((naked))
void Item_SetTextExtents(itemDef_t *item, int *width, int *height, const char *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3715 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        /* { scope 1 */
        "movl 0x14(%ebp), %esi\n" /* line 3724 | text, textPtr */
        "testl %esi, %esi\n" /* textPtr */
        "je .Lf16557c_001657b5\n"
        "movl 0x14(%ebp), %esi\n" /* text, textPtr */
        ".Lf16557c_00165596:\n"
        "leal 0x210(%ebx), %eax\n" /* line 99 */
        "cvttss2si 8(%eax), %edx\n" /* line 3740 */
        "movl 0xc(%ebp), %ecx\n" /* width */
        "movl %edx, (%ecx)\n"
        "cvttss2si 0xc(%eax), %eax\n" /* line 3741 */
        "movl 0x10(%ebp), %edx\n" /* height */
        "movl %eax, (%edx)\n"
        "movl (%ecx), %ecx\n" /* line 3744 */
        "testl %ecx, %ecx\n"
        "je .Lf16557c_001655e3\n"
        "cmpl $8, 0x270(%ebx)\n" /* item */
        "je .Lf16557c_001655c9\n"
        "movl 0x2c0(%ebx), %edx\n" /* item */
        "testl %edx, %edx\n"
        "je .Lf16557c_001655d2\n"
        ".Lf16557c_001655c9:\n"
        "cmpl $1, 0x280(%ebx)\n" /* item */
        "je .Lf16557c_001655e3\n"
        ".Lf16557c_001655d2:\n"
        "cmpl $3, 0x280(%ebx)\n" /* item */
        "je .Lf16557c_001655e3\n"
        /* } scope */
        ".Lf16557c_001655db:\n"
        "addl $0x4c, %esp\n" /* line 3782 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16557c_001655e3:\n"
        "movl 0x28c(%ebx), %eax\n" /* line 3711 */
        "movl %eax, 4(%esp)\n"
        "movl 0x27c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %edi\n"
        "movl 0x28c(%ebx), %eax\n" /* line 3747 | item */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* textPtr */
        "calll UI_TextWidth\n"
        "movl %eax, -0x3c(%ebp)\n" /* originalWidth */
        "movl 0x270(%ebx), %ecx\n" /* line 3749 | item */
        "cmpl $8, %ecx\n"
        "je .Lf16557c_00165743\n"
        "cmpl $0x12, %ecx\n" /* line 2525 */
        "ja .Lf16557c_00165644\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x70210, %eax\n"
        "jne .Lf16557c_00165807\n"
        ".Lf16557c_00165644:\n"
        "cmpl $3, 0x280(%ebx)\n" /* line 3758 | item */
        "je .Lf16557c_001657de\n"
        ".Lf16557c_00165651:\n"
        "movl 0x28c(%ebx), %eax\n" /* line 3764 | item */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* textPtr */
        "calll UI_TextWidth\n"
        "movl 0xc(%ebp), %edx\n" /* width */
        "movl %eax, (%edx)\n"
        "movl 0x28c(%ebx), %eax\n" /* line 3765 | item */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* font */
        "calll UI_TextHeight\n"
        "movl 0x10(%ebp), %ecx\n" /* height */
        "movl %eax, (%ecx)\n"
        "movl 0xc(%ebp), %eax\n" /* line 3768 | width */
        "cvtsi2ssl (%eax), %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "cvtsi2ssl (%ecx), %xmm0\n" /* line 3769 */
        "movss %xmm0, -0x24(%ebp)\n"
        "movss 0x284(%ebx), %xmm1\n" /* line 3770 | item */
        "movss %xmm1, -0x30(%ebp)\n" /* newRect */
        "movss 0x288(%ebx), %xmm0\n" /* line 3771 | item */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* line 3772 | item */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* line 3773 | item */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x280(%ebx), %eax\n" /* line 3774 | item */
        "cmpl $2, %eax\n"
        "je .Lf16557c_001657a2\n"
        "cmpl $1, %eax\n" /* line 3776 */
        "je .Lf16557c_00165785\n"
        "cmpl $3, %eax\n"
        "je .Lf16557c_00165785\n"
        ".Lf16557c_001656e7:\n"
        "movl 0xd4(%ebx), %eax\n" /* line 3698 */
        "testl %eax, %eax\n"
        "je .Lf16557c_00165779\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 3700 | newRect */
        "addss 0xe0(%ebx), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* newRect */
        "movss -0x2c(%ebp), %xmm0\n" /* line 3701 */
        "addss 0xe0(%ebx), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        ".Lf16557c_00165719:\n"
        "addss (%ebx), %xmm1\n" /* line 3704 */
        "movss %xmm1, -0x30(%ebp)\n" /* newRect */
        "addss 4(%ebx), %xmm0\n" /* line 3705 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 3780 | newRect */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_SetTextRect\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 3782 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16557c_00165743:\n"
        "movl 0x280(%ebx), %eax\n" /* line 3749 | item */
        "subl $1, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf16557c_00165644\n"
        "movl 0x28c(%ebx), %eax\n" /* line 3751 | item */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* font */
        "movl 0xd8(%ebx), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll UI_OwnerDrawWidth\n"
        "addl %eax, -0x3c(%ebp)\n" /* originalWidth */
        "jmp .Lf16557c_00165651\n"
        ".Lf16557c_00165779:\n"
        "movss -0x30(%ebp), %xmm1\n" /* newRect */
        "movss -0x2c(%ebp), %xmm0\n"
        "jmp .Lf16557c_00165719\n"
        ".Lf16557c_00165785:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 3777 | originalWidth */
        "shrl $0x1f, %eax\n"
        "addl -0x3c(%ebp), %eax\n" /* originalWidth */
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* newRect */
        "jmp .Lf16557c_001656e7\n"
        ".Lf16557c_001657a2:\n"
        "cvtsi2ssl -0x3c(%ebp), %xmm0\n" /* line 3775 | originalWidth */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* newRect */
        "jmp .Lf16557c_001656e7\n"
        ".Lf16557c_001657b5:\n"
        "movl 0x294(%ebx), %esi\n" /* line 3730 | item, textPtr */
        "testl %esi, %esi\n" /* line 3731 | textPtr */
        "je .Lf16557c_001655db\n"
        "cmpb $0x40, (%esi)\n" /* line 3735 | textPtr */
        "jne .Lf16557c_00165596\n"
        "leal 1(%esi), %eax\n" /* line 3736 | textPtr */
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %eax, %esi\n" /* textPtr */
        "jmp .Lf16557c_00165596\n"
        ".Lf16557c_001657de:\n"
        "movl 0x28c(%ebx), %eax\n" /* line 3761 | item */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl 0x14(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll UI_TextWidth\n"
        "addl %eax, -0x3c(%ebp)\n" /* originalWidth */
        "jmp .Lf16557c_00165651\n"
        ".Lf16557c_00165807:\n"
        "cmpl $1, 0x280(%ebx)\n" /* line 3753 | item */
        "jne .Lf16557c_00165644\n"
        "movl 0x2c0(%ebx), %eax\n" /* item */
        "testl %eax, %eax\n"
        "je .Lf16557c_00165644\n"
        "movl %eax, (%esp)\n" /* line 3755 */
        "calll Dvar_GetVariantString\n"
        "movl 0x28c(%ebx), %edx\n" /* line 3756 | item */
        "movl %edx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* font */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "addl %eax, -0x3c(%ebp)\n" /* originalWidth */
        "jmp .Lf16557c_00165651\n"
    );
}

/* line 3827 */
__attribute__((naked))
void Item_Text_AutoWrapped_Paint(itemDef_t *item, const char *textPtr, vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3827 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x49c, %esp\n"
        "movl 8(%ebp), %esi\n" /* item */
        "movl 0xc(%ebp), %ebx\n" /* textPtr */
        /* { scope 1 */
        "movl 0x28c(%esi), %eax\n" /* line 3711 */
        "movl %eax, 4(%esp)\n"
        "movl 0x27c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x43c(%ebp)\n" /* font */
        "movl 0x28c(%esi), %eax\n" /* line 3843 | item */
        "movl %eax, 4(%esp)\n"
        "movl -0x43c(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "movl %eax, -0x458(%ebp)\n" /* height */
        "movl 0x28c(%esi), %eax\n" /* line 3845 | item */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x43c(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* p */
        "calll UI_TextWidth\n"
        "movl %eax, -0x450(%ebp)\n" /* textWidth */
        "movss 8(%esi), %xmm0\n" /* line 3847 | item */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jp .Lf165850_001658d8\n"
        "je .Lf165850_001658e5\n"
        ".Lf165850_001658d8:\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "ucomiss %xmm0, %xmm1\n"
        "ja .Lf165850_00165c10\n"
        ".Lf165850_001658e5:\n"
        "cvttss2si %xmm0, %edx\n" /* line 3859 */
        "movl %edx, -0x444(%ebp)\n" /* iTargetLineWidth */
        ".Lf165850_001658ef:\n"
        "movss 0x288(%esi), %xmm0\n" /* line 3862 | item */
        "movss %xmm0, -0x440(%ebp)\n" /* y */
        "movb $0, -0x430(%ebp)\n" /* line 3864 | buff */
        "testl %ebx, %ebx\n" /* line 3868 | p */
        "je .Lf165850_00165b83\n"
        "movl $0, -0x45c(%ebp)\n" /* newLinePtr */
        "movl $0, -0x454(%ebp)\n" /* len */
        "movl $0, -0x44c(%ebp)\n" /* newLine */
        "movl $0, -0x448(%ebp)\n" /* newLineWidth */
        "leal 0x210(%esi), %edi\n" /* item */
        "movl -0x458(%ebp), %eax\n" /* height */
        "addl $5, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "movss %xmm2, -0x464(%ebp)\n"
        "jmp .Lf165850_00165999\n"
        ".Lf165850_00165953:\n"
        "cmpb $0x20, %al\n" /* line 3877 */
        "je .Lf165850_00165be6\n"
        ".Lf165850_0016595b:\n"
        "movl -0x454(%ebp), %edx\n" /* line 3907 | len */
        "movb %al, -0x430(%ebp, %edx)\n"
        "addl $1, %edx\n"
        "movl %edx, -0x454(%ebp)\n" /* len */
        "addl $1, %ebx\n" /* p */
        "movl %edx, %eax\n" /* line 3909 */
        "subl $1, %eax\n"
        "cmpb $0xd, -0x430(%ebp, %eax)\n"
        "je .Lf165850_00165bfd\n"
        "movl %edx, %eax\n"
        ".Lf165850_00165989:\n"
        "movb $0, -0x430(%ebp, %eax)\n" /* line 3912 */
        "testl %ebx, %ebx\n" /* line 3868 | p */
        "je .Lf165850_00165b83\n"
        ".Lf165850_00165999:\n"
        "movzbl (%ebx), %eax\n" /* line 3870 | p */
        "cmpb $0x20, %al\n"
        "je .Lf165850_001659ac\n"
        "cmpb $9, %al\n"
        "je .Lf165850_001659ac\n"
        "cmpb $0xa, %al\n"
        "je .Lf165850_001659ac\n"
        "testb %al, %al\n"
        "jne .Lf165850_001659cd\n"
        ".Lf165850_001659ac:\n"
        "leal 1(%ebx), %eax\n" /* line 3873 | p */
        "movl %eax, -0x45c(%ebp)\n" /* newLinePtr */
        "movl -0x454(%ebp), %edx\n" /* len */
        "movl %edx, -0x44c(%ebp)\n" /* newLine */
        "movl -0x450(%ebp), %eax\n" /* textWidth */
        "movl %eax, -0x448(%ebp)\n" /* newLineWidth */
        ".Lf165850_001659cd:\n"
        "movl 0x28c(%esi), %eax\n" /* line 3876 | item */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x43c(%ebp), %edx\n" /* font */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x430(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "movl %eax, -0x450(%ebp)\n" /* textWidth */
        "movl -0x44c(%ebp), %edx\n" /* line 3877 | newLine */
        "testl %edx, %edx\n"
        "je .Lf165850_00165a11\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "ucomiss 8(%esi), %xmm0\n" /* item */
        "ja .Lf165850_00165a20\n"
        ".Lf165850_00165a11:\n"
        "movzbl (%ebx), %eax\n" /* p */
        "cmpb $0xa, %al\n"
        "je .Lf165850_00165a20\n"
        "testb %al, %al\n"
        "jne .Lf165850_00165953\n"
        ".Lf165850_00165a20:\n"
        "movl -0x454(%ebp), %eax\n" /* line 3879 | len */
        "testl %eax, %eax\n"
        "je .Lf165850_00165b3a\n"
        "movl 0x210(%esi), %eax\n" /* line 3882 | item */
        "movl %eax, -0x30(%ebp)\n" /* newTextRect */
        "movl 4(%edi), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0xc(%edi), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x10(%edi), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x14(%edi), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x280(%esi), %eax\n" /* line 3883 | item */
        "cmpl $1, %eax\n"
        "je .Lf165850_00165b9d\n"
        "cmpl $2, %eax\n" /* line 3885 */
        "je .Lf165850_00165bc8\n"
        "movss 0x284(%esi), %xmm1\n" /* line 3888 | item */
        "movss %xmm1, -0x30(%ebp)\n" /* newTextRect */
        ".Lf165850_00165a7a:\n"
        "movss -0x440(%ebp), %xmm0\n" /* line 3890 | y */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 0xd4(%esi), %eax\n" /* line 3698 */
        "testl %eax, %eax\n"
        "je .Lf165850_00165b8e\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 3700 | newTextRect */
        "addss 0xe0(%esi), %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n" /* newTextRect */
        "addss 0xe0(%esi), %xmm0\n" /* line 3701 */
        "movss %xmm0, -0x2c(%ebp)\n"
        ".Lf165850_00165ab4:\n"
        "addss (%esi), %xmm1\n" /* line 3704 */
        "movss %xmm1, -0x30(%ebp)\n" /* newTextRect */
        "addss 4(%esi), %xmm0\n" /* line 3705 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 3892 | newTextRect */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetTextRect\n"
        "movl -0x44c(%ebp), %eax\n" /* line 3894 | newLine */
        "movb $0, -0x430(%ebp, %eax)\n"
        "movl 0x290(%esi), %eax\n" /* line 3895 | item */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movl 0x28c(%esi), %eax\n" /* item */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* item */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* item */
        "movl %eax, 0x14(%esp)\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x43c(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "leal -0x430(%ebp), %edx\n" /* buff */
        "movl %edx, (%esp)\n"
        "calll UI_DrawText\n"
        ".Lf165850_00165b3a:\n"
        "cmpb $0, (%ebx)\n" /* line 3897 | p */
        "je .Lf165850_00165b83\n"
        "movss -0x440(%ebp), %xmm0\n" /* line 3900 | y */
        "addss -0x464(%ebp), %xmm0\n"
        "movss %xmm0, -0x440(%ebp)\n" /* y */
        "movl -0x45c(%ebp), %ebx\n" /* newLinePtr, p */
        "movl $0, -0x454(%ebp)\n" /* len */
        "movl $0, -0x44c(%ebp)\n" /* newLine */
        "movl $0, -0x448(%ebp)\n" /* newLineWidth */
        "testl %ebx, %ebx\n" /* line 3868 | p */
        "jne .Lf165850_00165999\n"
        /* } scope */
        ".Lf165850_00165b83:\n"
        "addl $0x49c, %esp\n" /* line 3914 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf165850_00165b8e:\n"
        "movss -0x30(%ebp), %xmm1\n" /* newTextRect */
        "movss -0x2c(%ebp), %xmm0\n"
        "jmp .Lf165850_00165ab4\n"
        /* { scope 1 */
        ".Lf165850_00165b9d:\n"
        "movl -0x448(%ebp), %eax\n" /* line 3884 | newLineWidth */
        "shrl $0x1f, %eax\n"
        "addl -0x448(%ebp), %eax\n" /* newLineWidth */
        "sarl $1, %eax\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "movss 0x284(%esi), %xmm0\n" /* item */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* newTextRect */
        "jmp .Lf165850_00165a7a\n"
        ".Lf165850_00165bc8:\n"
        "cvtsi2ssl -0x448(%ebp), %xmm1\n" /* line 3886 | newLineWidth */
        "movss 0x284(%esi), %xmm0\n" /* item */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* newTextRect */
        "jmp .Lf165850_00165a7a\n"
        ".Lf165850_00165be6:\n"
        "movl -0x450(%ebp), %edx\n" /* line 3877 | textWidth */
        "cmpl %edx, -0x444(%ebp)\n" /* iTargetLineWidth */
        "jge .Lf165850_0016595b\n"
        "jmp .Lf165850_00165a20\n"
        ".Lf165850_00165bfd:\n"
        "movb $0x20, -0x430(%ebp, %eax)\n" /* line 3910 */
        "movl -0x454(%ebp), %eax\n" /* len */
        "jmp .Lf165850_00165989\n"
        ".Lf165850_00165c10:\n"
        "movaps %xmm1, %xmm2\n" /* line 3852 */
        "divss %xmm0, %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "movss %xmm1, -0x478(%ebp)\n"
        "calll ceilf\n"
        "fstps -0x460(%ebp)\n"
        "cvttss2si -0x460(%ebp), %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x478(%ebp), %xmm1\n"
        "divss %xmm0, %xmm1\n"
        "cvttss2si %xmm1, %eax\n"
        "movl %eax, -0x444(%ebp)\n" /* iTargetLineWidth */
        "jmp .Lf165850_001658ef\n"
    );
}

/* line 3917 */
__attribute__((naked))
void Item_Text_Wrapped_Paint(itemDef_t *item, const char *textPtr, vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3917 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x46c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        "movl 0xc(%ebp), %esi\n" /* textPtr */
        /* { scope 1 */
        "movl 0x28c(%ebx), %eax\n" /* line 3711 */
        "movl %eax, 4(%esp)\n"
        "movl 0x27c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, -0x438(%ebp)\n" /* font */
        "movl 0x28c(%ebx), %eax\n" /* line 3928 | item */
        "movl %eax, 4(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, (%esp)\n"
        "calll UI_TextHeight\n"
        "movl %eax, %edi\n" /* height */
        "leal 0x210(%ebx), %eax\n" /* line 99 */
        "movl %eax, -0x434(%ebp)\n" /* textRect */
        "movss 4(%eax), %xmm0\n" /* line 3932 */
        "movss %xmm0, -0x43c(%ebp)\n" /* y */
        "movl $0xd, 4(%esp)\n" /* line 3934 */
        "movl %esi, (%esp)\n" /* textPtr */
        "calll strchr\n"
        "movl %eax, -0x440(%ebp)\n" /* p */
        "testl %eax, %eax\n" /* line 3935 */
        "je .Lf165c56_00165cdc\n"
        "cmpb $0, (%eax)\n"
        "jne .Lf165c56_00165d62\n"
        ".Lf165c56_00165cdc:\n"
        "movl %esi, %edi\n" /* textPtr, height */
        ".Lf165c56_00165cde:\n"
        "movl 0x280(%ebx), %eax\n" /* line 3953 | item */
        "cmpl $1, %eax\n"
        "je .Lf165c56_00165f3e\n"
        "cmpl $2, %eax\n" /* line 3955 */
        "je .Lf165c56_00165fa9\n"
        "movl -0x434(%ebp), %eax\n" /* line 3958 | textRect */
        "movss (%eax), %xmm0\n"
        ".Lf165c56_00165d00:\n"
        "movl 0x290(%ebx), %eax\n" /* line 3959 | item */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x28c(%ebx), %eax\n" /* item */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* item */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* item */
        "movl %eax, 0x14(%esp)\n"
        "movss -0x43c(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* height */
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x46c, %esp\n" /* line 3960 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf165c56_00165d62:\n"
        "leal 5(%edi), %eax\n" /* line 3935 | height */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x430(%ebp)\n"
        "movl %esi, %edi\n" /* textPtr, height */
        "jmp .Lf165c56_00165e34\n"
        ".Lf165c56_00165d78:\n"
        "cmpl $2, %eax\n" /* line 3942 */
        "je .Lf165c56_00165edd\n"
        "movl -0x434(%ebp), %eax\n" /* line 3945 | textRect */
        "movss (%eax), %xmm0\n"
        ".Lf165c56_00165d8b:\n"
        "movl 0x290(%ebx), %eax\n" /* line 3947 | item */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* color */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x28c(%ebx), %eax\n" /* item */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* item */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* item */
        "movl %eax, 0x14(%esp)\n"
        "movss -0x43c(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "movss -0x43c(%ebp), %xmm0\n" /* line 3948 | y */
        "addss -0x430(%ebp), %xmm0\n"
        "movss %xmm0, -0x43c(%ebp)\n" /* y */
        "leal 1(%edi, %esi), %edi\n" /* line 3949 | height */
        "movl -0x440(%ebp), %eax\n" /* line 3950 | p */
        "addl $1, %eax\n"
        "movl $0xd, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strchr\n"
        "movl %eax, -0x440(%ebp)\n" /* p */
        "testl %eax, %eax\n" /* line 3935 */
        "je .Lf165c56_00165cde\n"
        "cmpb $0, (%eax)\n"
        "je .Lf165c56_00165cde\n"
        ".Lf165c56_00165e34:\n"
        "movl -0x440(%ebp), %esi\n" /* line 3937 | p, textPtr */
        "subl %edi, %esi\n" /* height, textPtr */
        "leal 1(%esi), %eax\n" /* textPtr */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* height */
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movb $0, -0x418(%ebp, %esi)\n" /* line 3938 */
        "movl 0x280(%ebx), %eax\n" /* line 3940 | item */
        "cmpl $1, %eax\n"
        "jne .Lf165c56_00165d78\n"
        "movl -0x434(%ebp), %eax\n" /* line 3941 | textRect */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x420(%ebp)\n"
        "movss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x428(%ebp)\n"
        "movl 0x28c(%ebx), %eax\n" /* item */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x428(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x420(%ebp), %xmm0\n"
        "jmp .Lf165c56_00165d8b\n"
        ".Lf165c56_00165edd:\n"
        "movl -0x434(%ebp), %eax\n" /* line 3943 | textRect */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x41c(%ebp)\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x41c(%ebp)\n"
        "movl 0x28c(%ebx), %eax\n" /* item */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x41c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf165c56_00165d8b\n"
        ".Lf165c56_00165f3e:\n"
        "movl -0x434(%ebp), %eax\n" /* line 3954 | textRect */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x424(%ebp)\n"
        "movss 8(%eax), %xmm1\n"
        "movss %xmm1, -0x42c(%ebp)\n"
        "movl 0x28c(%ebx), %eax\n" /* item */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* height */
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x42c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "addss -0x424(%ebp), %xmm0\n"
        "jmp .Lf165c56_00165d00\n"
        ".Lf165c56_00165fa9:\n"
        "movl -0x434(%ebp), %eax\n" /* line 3956 | textRect */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x444(%ebp)\n"
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x444(%ebp)\n"
        "movl 0x28c(%ebx), %eax\n" /* item */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x438(%ebp), %eax\n" /* font */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* height */
        "calll UI_TextWidth\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0x444(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movaps %xmm1, %xmm0\n"
        "jmp .Lf165c56_00165d00\n"
    );
}

/* line 4837 */
__attribute__((naked))
void Item_ListBox_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4837 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        /* { scope 1: text */
        "movl 0xc(%ebp), %eax\n" /* line 4845 | item */
        "movl %eax, (%esp)\n"
        "calll Item_GetListBoxDef\n"
        "movl %eax, -0x78(%ebp)\n" /* listPtr */
        "testl %eax, %eax\n" /* line 4847 */
        "je .Lf166004_00166302\n"
        "movl 0xc(%ebp), %edx\n" /* line 4856 | item */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_FeederCount\n"
        "movl %eax, -0x7c(%ebp)\n" /* count */
        "movl 0xc(%ebp), %eax\n" /* line 4859 | item */
        "testb $0x20, 0xe6(%eax)\n"
        "jne .Lf166004_0016630d\n"
        "movl %eax, (%esp)\n" /* line 4921 */
        "calll UI_OverrideCursorPos\n"
        "movl -0x78(%ebp), %edx\n" /* line 4923 | listPtr */
        "movl 0x10c(%edx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf166004_001667c0\n"
        "movl 0xc(%ebp), %eax\n" /* line 4946 | item */
        "movss 0xc(%eax), %xmm0\n"
        "movss lit4_002ed62c, %xmm2\n" /* 2.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl -0x78(%ebp), %eax\n" /* line 4947 | listPtr */
        "cmpl $1, 0x3c(%eax)\n"
        "je .Lf166004_001669ca\n"
        ".Lf166004_00166089:\n"
        "movl %eax, %edx\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 4980 | 1.0f */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movss (%eax), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm0, -0x58(%ebp)\n" /* line 4981 */
        "addss 4(%eax), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl (%edx), %edx\n" /* line 120 */
        "movl %edx, -0x5c(%ebp)\n"
        "cmpl %edx, -0x7c(%ebp)\n" /* line 4982 | count */
        "jle .Lf166004_00166302\n"
        "movl %edx, -0x60(%ebp)\n"
        "movaps %xmm1, %xmm0\n"
        "addss lit4_002ed608, %xmm0\n" /* 4.0f */
        "movss %xmm0, -0xa0(%ebp)\n"
        "movss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -0xa4(%ebp)\n"
        "addss lit4_002ed62c, %xmm1\n" /* 2.0f */
        "movss %xmm1, -0xa8(%ebp)\n"
        /* { scope 2 */
        ".Lf166004_001660f5:\n"
        "movl -0x78(%ebp), %eax\n" /* line 4989 | listPtr */
        "movl 0x40(%eax), %ebx\n" /* i */
        "testl %ebx, %ebx\n" /* i */
        "jle .Lf166004_0016671b\n"
        "movl %eax, %edi\n"
        "xorl %esi, %esi\n"
        "jmp .Lf166004_00166173\n"
        /* { scope 3 */
        ".Lf166004_00166109:\n"
        "cvtsi2ssl 0x48(%edi), %xmm0\n" /* line 5000 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "addss lit4_002ed720, %xmm0\n" /* 3.0f */
        "movss %xmm0, 4(%esp)\n"
        "cvtsi2ssl 0x44(%edi), %xmm0\n"
        "addss -0xa8(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        ".Lf166004_00166161:\n"
        "addl $1, %esi\n" /* line 4993 | j */
        "addl $0xc, %edi\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "cmpl %esi, 0x40(%eax)\n" /* j */
        "jle .Lf166004_0016629b\n"
        ".Lf166004_00166173:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 4995 | optionalImage */
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* j */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_FeederItemText\n"
        "movl %eax, %ebx\n" /* i */
        "movl -0x1c(%ebp), %eax\n" /* line 4996 | optionalImage */
        "testl %eax, %eax\n"
        "jne .Lf166004_00166109\n"
        "testl %ebx, %ebx\n" /* line 5002 | i */
        "je .Lf166004_00166161\n"
        "movl 0xc(%ebp), %eax\n" /* line 5004 | item */
        "movl 0x290(%eax), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movss 0x28c(%edx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x10(%edx), %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "addss 0x38(%eax), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "addss 0x288(%eax), %xmm0\n"
        "movss %xmm0, -0x8c(%ebp)\n"
        "cvtsi2ssl 0x44(%edi), %xmm0\n"
        "addss -0xa0(%ebp), %xmm0\n"
        "addss 0x284(%eax), %xmm0\n"
        "movss -0x30(%ebp), %xmm1\n" /* line 3711 */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x27c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0xb8(%ebp)\n"
        "calll UI_GetFontHandle\n"
        "movl -0x2c(%ebp), %edx\n" /* line 5004 */
        "movl %edx, 0x24(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "addl $0x1cc, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movss -0x30(%ebp), %xmm1\n"
        "movss %xmm1, 0x1c(%esp)\n"
        "movl -0x64(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movss -0x8c(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0xb8(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x4c(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll UI_DrawText\n"
        "addl $1, %esi\n" /* line 4993 | j */
        "addl $0xc, %edi\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "cmpl %esi, 0x40(%eax)\n" /* j */
        "jg .Lf166004_00166173\n"
        /* } scope */
        ".Lf166004_0016629b:\n"
        "movl -0x60(%ebp), %eax\n" /* line 5023 */
        "movl 0xc(%ebp), %edx\n" /* item */
        "cmpl 0x2dc(%edx), %eax\n"
        "je .Lf166004_001666b0\n"
        ".Lf166004_001662ad:\n"
        "movl -0x78(%ebp), %eax\n" /* line 5028 | listPtr */
        "movss 0x38(%eax), %xmm0\n"
        "movss -0x34(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "ucomiss %xmm1, %xmm0\n" /* line 5029 */
        "ja .Lf166004_00166b67\n"
        "movl %eax, %edx\n" /* line 5034 */
        "movl 0x10(%eax), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ListBox_SetEndPos\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 5035 */
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "addss 0x38(%eax), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        /* } scope */
        "addl $1, -0x60(%ebp)\n" /* line 4982 */
        "movl -0x7c(%ebp), %eax\n" /* count */
        "cmpl %eax, -0x60(%ebp)\n"
        "jne .Lf166004_001660f5\n"
        /* } scope */
        ".Lf166004_00166302:\n"
        "addl $0xec, %esp\n" /* line 5040 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf166004_0016630d:\n"
        "movl %eax, %edx\n"
        /* { scope 1: text */
        "movss lit4_002ed5d0, %xmm0\n" /* line 4863 | 1.0f */
        "addss (%eax), %xmm0\n"
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss 4(%eax), %xmm1\n" /* line 4864 */
        "movss %xmm1, -0x4c(%ebp)\n"
        "addss 0xc(%eax), %xmm1\n"
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "movss %xmm1, -0x4c(%ebp)\n"
        "movl imp_sharedUiInfo, %esi\n" /* line 4865 */
        "movl 8(%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 4866 */
        "addss lit4_002ed908, %xmm0\n" /* 15.0f */
        "movss %xmm0, -0x38(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* line 4867 | item */
        "movss 8(%eax), %xmm1\n"
        "subss lit4_002ed830, %xmm1\n" /* 32.0f */
        "movl 0x10(%esi), %eax\n" /* line 4868 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movaps %xmm1, %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x38(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0xc8(%ebp)\n"
        "calll UI_DrawHandlePic\n"
        "movss -0xc8(%ebp), %xmm1\n" /* line 4869 */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "addss -0x38(%ebp), %xmm1\n"
        "movl 0xc(%esi), %eax\n" /* line 4870 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "movss %xmm1, -0xc8(%ebp)\n"
        "calll UI_DrawHandlePic\n"
        "movl 0xc(%ebp), %eax\n" /* line 4872 | item */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_ListBox_ThumbDrawPosition\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0xc8(%ebp), %xmm1\n" /* line 4873 */
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "minss %xmm0, %xmm1\n"
        "movl 0x14(%esi), %eax\n" /* line 4877 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl -0x78(%ebp), %edx\n" /* line 4879 | listPtr */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ListBox_SetEndPos\n"
        "movl 0xc(%ebp), %eax\n" /* line 4880 | item */
        "movss 8(%eax), %xmm0\n"
        "movss %xmm0, -0x80(%ebp)\n" /* size */
        "movss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss -0x80(%ebp), %xmm1\n" /* size */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x80(%ebp)\n" /* size */
        "movl -0x78(%ebp), %eax\n" /* line 4883 | listPtr */
        "cmpl $1, 0x3c(%eax)\n"
        "jne .Lf166004_00166302\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 4886 | 1.0f */
        "movl 0xc(%ebp), %edx\n" /* item */
        "addss (%edx), %xmm1\n"
        "movss %xmm1, -0x88(%ebp)\n" /* x */
        "movss lit4_002ed5d0, %xmm1\n" /* line 4887 | 1.0f */
        "addss 4(%edx), %xmm1\n"
        "movss %xmm1, -0x48(%ebp)\n"
        "movl (%eax), %eax\n" /* line 120 */
        "cmpl %eax, -0x7c(%ebp)\n" /* line 4888 | count */
        "jle .Lf166004_00166302\n"
        "movl %eax, %ebx\n" /* i */
        "movl -0x7c(%ebp), %esi\n" /* count */
        "jmp .Lf166004_001665a7\n"
        ".Lf166004_00166559:\n"
        "movl -0x78(%ebp), %eax\n" /* line 4903 | listPtr */
        "movss 0x34(%eax), %xmm0\n"
        "movss -0x80(%ebp), %xmm1\n" /* size */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x80(%ebp)\n" /* size */
        "ucomiss %xmm1, %xmm0\n" /* line 4904 */
        "ja .Lf166004_00166c52\n"
        "addss -0x88(%ebp), %xmm0\n" /* line 4909 | x */
        "movss %xmm0, -0x88(%ebp)\n" /* x */
        "movl %eax, %edx\n" /* line 4910 */
        "movl 0x10(%eax), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ListBox_SetEndPos\n"
        "addl $1, %ebx\n" /* line 4888 | i */
        "cmpl %ebx, %esi\n" /* i */
        "je .Lf166004_00166302\n"
        ".Lf166004_001665a7:\n"
        "movl %ebx, 4(%esp)\n" /* line 4892 | i */
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_FeederItemImage\n"
        "testl %eax, %eax\n" /* line 4893 */
        "je .Lf166004_00166633\n"
        "movl %eax, 0x1c(%esp)\n" /* line 4895 */
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "movss 0x38(%eax), %xmm0\n"
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x34(%eax), %xmm0\n"
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x88(%ebp), %xmm0\n" /* x */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        ".Lf166004_00166633:\n"
        "movl 0xc(%ebp), %edx\n" /* line 4898 | item */
        "cmpl 0x2dc(%edx), %ebx\n" /* i */
        "jne .Lf166004_00166559\n"
        "movl %edx, %eax\n" /* line 4900 */
        "addl $0x1ec, %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xe0(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "movss 0x38(%eax), %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x34(%eax), %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x48(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x88(%ebp), %xmm1\n" /* x */
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawRect\n"
        "jmp .Lf166004_00166559\n"
        /* { scope 2 */
        ".Lf166004_001666b0:\n"
        "movl %edx, %eax\n" /* line 5025 */
        "addl $0x1fc, %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %edx\n" /* listPtr */
        "movl 0x38(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movss 8(%eax), %xmm0\n"
        "subss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "subss lit4_002ed608, %xmm0\n" /* 4.0f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "addss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 4(%esp)\n"
        "movss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_FillRect\n"
        "jmp .Lf166004_001662ad\n"
        ".Lf166004_0016671b:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 5010 | optionalImage */
        "movl %edx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_FeederItemText\n"
        "movl %eax, -0x74(%ebp)\n" /* text */
        "movl -0x1c(%ebp), %eax\n" /* line 5011 | optionalImage */
        "testl %eax, %eax\n"
        "je .Lf166004_00166b7a\n"
        "movl %eax, 0x1c(%esp)\n" /* line 5015 */
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "movss 0x38(%eax), %xmm0\n"
        "movss lit4_002ed608, %xmm1\n" /* 4.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x34(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "addss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 4(%esp)\n"
        "movss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf166004_0016629b\n"
        /* } scope */
        ".Lf166004_001667c0:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4926 | item */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "addss 8(%eax), %xmm0\n"
        "subss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x40(%ebp)\n"
        "movss lit4_002ed5d0, %xmm1\n" /* line 4927 | 1.0f */
        "addss 4(%eax), %xmm1\n"
        "movss %xmm1, -0x54(%ebp)\n"
        "movl imp_sharedUiInfo, %esi\n" /* line 4928 */
        "movl (%esi), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movss -0x54(%ebp), %xmm0\n" /* line 4929 */
        "addss lit4_002ed908, %xmm0\n" /* 15.0f */
        "movss %xmm0, -0x50(%ebp)\n"
        "movl -0x78(%ebp), %edx\n" /* line 4931 | listPtr */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ListBox_SetEndPos\n"
        "movl 0xc(%ebp), %eax\n" /* line 4932 | item */
        "movss 0xc(%eax), %xmm1\n"
        "subss lit4_002ed830, %xmm1\n" /* 32.0f */
        "movl 0x10(%esi), %eax\n" /* line 4933 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movaps %xmm1, %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss -0x50(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0xc8(%ebp)\n"
        "calll UI_DrawHandlePic\n"
        "movss -0xc8(%ebp), %xmm1\n" /* line 4934 */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "addss -0x50(%ebp), %xmm1\n"
        "movl 4(%esi), %eax\n" /* line 4935 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm1, -0xc8(%ebp)\n"
        "calll UI_DrawHandlePic\n"
        "movl 0xc(%ebp), %eax\n" /* line 4937 | item */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_ListBox_ThumbDrawPosition\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss -0xc8(%ebp), %xmm1\n" /* line 4938 */
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "minss %xmm0, %xmm1\n"
        "movl 0x14(%esi), %eax\n" /* line 4942 */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x41800000, 8(%esp)\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x40(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl 0xc(%ebp), %eax\n" /* line 4946 | item */
        "movss 0xc(%eax), %xmm0\n"
        "movss lit4_002ed62c, %xmm2\n" /* 2.0f */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movl -0x78(%ebp), %eax\n" /* line 4947 | listPtr */
        "cmpl $1, 0x3c(%eax)\n"
        "jne .Lf166004_00166089\n"
        ".Lf166004_001669ca:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 4950 | 1.0f */
        "movl 0xc(%ebp), %edx\n" /* item */
        "movss (%edx), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movss 4(%edx), %xmm1\n" /* line 4951 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x84(%ebp)\n" /* y */
        "movl (%eax), %eax\n" /* line 120 */
        "cmpl %eax, -0x7c(%ebp)\n" /* line 4952 | count */
        "jle .Lf166004_00166302\n"
        "movl %eax, %ebx\n" /* i */
        "addss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, -0x9c(%ebp)\n"
        "movl -0x7c(%ebp), %esi\n" /* count */
        "jmp .Lf166004_00166a63\n"
        ".Lf166004_00166a12:\n"
        "movl -0x78(%ebp), %edx\n" /* line 4967 | listPtr */
        "movl 0x10(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ListBox_SetEndPos\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 4968 */
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "subss 0x34(%eax), %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n"
        "movss 0x38(%eax), %xmm0\n" /* line 4969 */
        "ucomiss -0x34(%ebp), %xmm0\n"
        "ja .Lf166004_00166b67\n"
        "addss -0x84(%ebp), %xmm0\n" /* line 4974 | y */
        "movss %xmm0, -0x84(%ebp)\n" /* y */
        "addl $1, %ebx\n" /* line 4952 | i */
        "cmpl %ebx, %esi\n" /* i */
        "je .Lf166004_00166302\n"
        ".Lf166004_00166a63:\n"
        "movl %ebx, 4(%esp)\n" /* line 4956 | i */
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_FeederItemImage\n"
        "testl %eax, %eax\n" /* line 4957 */
        "je .Lf166004_00166aea\n"
        "movl %eax, 0x1c(%esp)\n" /* line 4959 */
        "movl $0, 0x18(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "movss 0x38(%eax), %xmm0\n"
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x34(%eax), %xmm0\n"
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x84(%ebp), %xmm0\n" /* y */
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x9c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        ".Lf166004_00166aea:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4962 | item */
        "cmpl 0x2dc(%eax), %ebx\n" /* i */
        "jne .Lf166004_00166a12\n"
        "movl %eax, %edx\n"
        "addl $0x1ec, %eax\n" /* line 4964 */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xe0(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "movss 0x38(%eax), %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x34(%eax), %xmm0\n"
        "subss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, 8(%esp)\n"
        "movss -0x84(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawRect\n"
        "jmp .Lf166004_00166a12\n"
        ".Lf166004_00166b67:\n"
        "movl %eax, %edx\n"
        /* { scope 2 */
        "subss -0x34(%ebp), %xmm0\n" /* line 5031 */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "jmp .Lf166004_00166302\n"
        ".Lf166004_00166b7a:\n"
        "movl -0x74(%ebp), %ecx\n" /* line 5017 | text */
        "testl %ecx, %ecx\n"
        "je .Lf166004_0016629b\n"
        "movl 0xc(%ebp), %eax\n" /* line 5019 | item */
        "movl 0x290(%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movss 0x28c(%edx), %xmm0\n"
        "movss %xmm0, -0x94(%ebp)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x10(%edx), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movss -0x58(%ebp), %xmm0\n"
        "movl -0x78(%ebp), %eax\n" /* listPtr */
        "addss 0x38(%eax), %xmm0\n"
        "movss %xmm0, -0x90(%ebp)\n"
        "movss -0x94(%ebp), %xmm1\n" /* line 3711 */
        "movss %xmm1, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x27c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl -0x98(%ebp), %edx\n" /* line 5019 */
        "movl %edx, 0x24(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "addl $0x1cc, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movss -0x94(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movss -0x90(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0xa0(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x74(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        "jmp .Lf166004_0016629b\n"
        ".Lf166004_00166c52:\n"
        "movl %eax, %edx\n"
        /* } scope */
        "cvttss2si -0x80(%ebp), %eax\n" /* line 4906 | size */
        "movl %eax, 0x20(%edx)\n"
        "jmp .Lf166004_00166302\n"
    );
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

    menuDef_t *parent = *(menuDef_t **)((byte *)item + 0x29c);
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
            out = (float *)(item2 + 0x1dc);
        } else if (I_stricmp(name, "forecolor") == 0) {
            out = (float *)(item2 + 0x1cc);
            Window_AddDynamicFlags((void *)item2, 0x10000);
        } else if (I_stricmp(name, "bordercolor") == 0) {
            out = (float *)(item2 + 0x1ec);
        }

        if (out) {
            out[0] = color[0];
            out[1] = color[1];
            out[2] = color[2];
            out[3] = color[3];
        }
    }
}

/* line 209 */
__attribute__((naked))
void Window_Paint(displayContextDef_t *dc, float (*w)[4][32], float fadeAmount, float fadeInAmount, float fadeClamp, float fadeCycle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 209 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* w */
        /* { scope 1 */
        "movss 0xc(%ebx), %xmm0\n" /* line 219 | w */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss 8(%ebx), %xmm1\n" /* w */
        "movss %xmm1, -0x24(%ebp)\n"
        "movss 4(%ebx), %xmm0\n" /* w */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss (%ebx), %xmm1\n" /* w */
        "movss %xmm1, -0x1c(%ebp)\n"
        "movl debugMode, %esi\n" /* line 221 */
        "testl %esi, %esi\n"
        "jne .Lf166dd2_00166f53\n"
        ".Lf166dd2_00166e12:\n"
        "testl %ebx, %ebx\n" /* line 227 | w */
        "je .Lf166dd2_00166ed8\n"
        "movl 0xd0(%ebx), %eax\n" /* w */
        "testl %eax, %eax\n"
        "jne .Lf166dd2_00166edf\n"
        "movl 0xd4(%ebx), %ecx\n" /* w */
        "testl %ecx, %ecx\n"
        "je .Lf166dd2_00166ed8\n"
        ".Lf166dd2_00166e36:\n"
        "movss 0xe0(%ebx), %xmm0\n" /* line 234 | w */
        "movss -0x1c(%ebp), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x1c(%ebp)\n"
        "movss -0x20(%ebp), %xmm1\n" /* line 235 */
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "addss lit4_002ed5d0, %xmm0\n" /* line 236 | 1.0f */
        "movss -0x24(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss -0x28(%ebp), %xmm1\n" /* line 237 */
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n"
        "cmpl $7, %eax\n" /* line 240 */
        "ja .Lf166dd2_00166ef2\n"
        ".Lf166dd2_00166e83:\n"
        "jmpl *.Ljt_166dd2_0(, %eax, 4)\n"
        ".Lf166dd2_00166e8a:\n"
        "cmpl $4, 0xd0(%ebx)\n" /* line 303 | w */
        "je .Lf166dd2_00166fb2\n"
        "leal 0x1ec(%ebx), %eax\n" /* line 322 | w */
        ".Lf166dd2_00166e9d:\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xe0(%ebx), %eax\n" /* w */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* w */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl 4(%ebx), %eax\n" /* w */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* w */
        "movl %eax, (%esp)\n"
        "calll UI_DrawRect\n"
        /* } scope */
        ".Lf166dd2_00166ed8:\n"
        "addl $0x40, %esp\n" /* line 345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf166dd2_00166edf:\n"
        "movl 0xd4(%ebx), %edx\n" /* line 232 | w */
        "testl %edx, %edx\n"
        "jne .Lf166dd2_00166e36\n"
        "cmpl $7, %eax\n" /* line 240 */
        "jbe .Lf166dd2_00166e83\n"
        ".Lf166dd2_00166ef2:\n"
        "movl 0xd4(%ebx), %eax\n" /* line 299 | w */
        "cmpl $1, %eax\n"
        "je .Lf166dd2_00166e8a\n"
        "cmpl $2, %eax\n" /* line 325 */
        "je .Lf166dd2_001671bd\n"
        "cmpl $3, %eax\n" /* line 330 */
        "jne .Lf166dd2_00166ed8\n"
        "leal 0x1ec(%ebx), %eax\n" /* line 333 | w */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xe0(%ebx), %eax\n" /* w */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* w */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl 4(%ebx), %eax\n" /* w */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* w */
        "movl %eax, (%esp)\n"
        "calll UI_DrawSides\n"
        /* } scope */
        "addl $0x40, %esp\n" /* line 345 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf166dd2_00166f53:\n"
        "movl $0x3f800000, %edx\n" /* line 223 */
        "movl %edx, -0xc(%ebp)\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl %edx, -0x14(%ebp)\n"
        "movl %edx, -0x18(%ebp)\n" /* color */
        "leal -0x18(%ebp), %eax\n" /* line 224 | color */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x24(%ebp), %xmm1\n"
        "movss %xmm1, 8(%esp)\n"
        "movss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x1c(%ebp), %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "calll UI_DrawRect\n"
        "jmp .Lf166dd2_00166e12\n"
        ".Lf166dd2_00166fb2:\n"
        "movss 0x1ec(%ebx), %xmm0\n" /* line 305 | w */
        "ucomiss lit4_002ed5e8, %xmm0\n" /* 0.0f */
        "jbe .Lf166dd2_00167224\n"
        "movl $0x3f800000, -0x18(%ebp)\n" /* line 308 | color */
        "movl $0x3f000000, %eax\n" /* line 309 */
        "movl %eax, -0x10(%ebp)\n"
        "movl %eax, -0x14(%ebp)\n"
        ".Lf166dd2_00166fd9:\n"
        "movl $0x3f800000, -0xc(%ebp)\n" /* line 317 */
        "leal -0x18(%ebp), %eax\n" /* line 318 | color */
        "jmp .Lf166dd2_00166e9d\n"
        ".Lf166dd2_00166fe8:\n"
        "movl 0x20c(%ebx), %eax\n" /* line 291 | w */
        "testl %eax, %eax\n"
        "je .Lf166dd2_00166ef2\n"
        "testb $1, 0xea(%ebx)\n" /* line 293 | w */
        "jne .Lf166dd2_00167219\n"
        "xorl %edx, %edx\n"
        ".Lf166dd2_00167005:\n"
        "movl %eax, 0x1c(%esp)\n" /* line 294 */
        "movl %edx, 0x18(%esp)\n"
        "jmp .Lf166dd2_001670f3\n"
        ".Lf166dd2_00167012:\n"
        "testb $1, 0xea(%ebx)\n" /* line 268 | w */
        "jne .Lf166dd2_0016720e\n"
        "xorl %edx, %edx\n"
        ".Lf166dd2_00167021:\n"
        "movl 0x20c(%ebx), %eax\n" /* line 269 | w */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawLoadBar\n"
        "jmp .Lf166dd2_00166ef2\n"
        ".Lf166dd2_00167072:\n"
        "movl 0x20c(%ebx), %eax\n" /* line 244 | w */
        "testl %eax, %eax\n"
        "je .Lf166dd2_001672c1\n"
        "movl 0xe8(%ebx), %edx\n" /* line 80 */
        "cvttss2si 0x1c(%ebp), %ecx\n" /* line 247 | fadeCycle, offsetTime */
        /* { scope 2 */
        "testb $0x30, %dl\n" /* line 179 */
        "je .Lf166dd2_001670d3\n"
        "movl 8(%ebp), %esi\n" /* line 181 | dc */
        "movl 4(%esi), %eax\n"
        "cmpl 0x1c8(%ebx), %eax\n"
        "jle .Lf166dd2_001670d3\n"
        "leal (%ecx, %eax), %eax\n" /* line 183 */
        "movl %eax, 0x1c8(%ebx)\n"
        "testb $0x10, %dl\n" /* line 184 */
        "je .Lf166dd2_0016728d\n"
        "movss 0x1e8(%ebx), %xmm0\n" /* line 186 */
        "subss 0x10(%ebp), %xmm0\n" /* fadeAmount */
        "movss %xmm0, 0x1e8(%ebx)\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 187 | 0.0f */
        "ja .Lf166dd2_001670d3\n"
        "jp .Lf166dd2_001670d3\n"
        "andl $0xffffffeb, %edx\n" /* line 189 */
        /* } scope */
        ".Lf166dd2_001670d3:\n"
        "movl %edx, 4(%esp)\n" /* line 248 */
        "movl %ebx, (%esp)\n" /* w */
        "calll Window_SetDynamicFlags\n"
        "movl 0x20c(%ebx), %eax\n" /* line 250 | w */
        "movl %eax, 0x1c(%esp)\n"
        "leal 0x1dc(%ebx), %eax\n" /* w */
        "movl %eax, 0x18(%esp)\n"
        ".Lf166dd2_001670f3:\n"
        "movl 0x14(%ebx), %eax\n" /* line 294 | w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "jmp .Lf166dd2_00166ef2\n"
        ".Lf166dd2_00167136:\n"
        "testb $1, 0xea(%ebx)\n" /* line 263 | w */
        "jne .Lf166dd2_00167203\n"
        "xorl %edx, %edx\n"
        ".Lf166dd2_00167145:\n"
        "movl 0x20c(%ebx), %eax\n" /* line 264 | w */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "jmp .Lf166dd2_001670f3\n"
        ".Lf166dd2_00167155:\n"
        "cmpl $-1, 0xcc(%ebx)\n" /* line 273 | w */
        "je .Lf166dd2_0016723b\n"
        "movl 0xcc(%ebx), %eax\n" /* w */
        ".Lf166dd2_00167168:\n"
        "testl %eax, %eax\n" /* line 281 */
        "js .Lf166dd2_00166ef2\n"
        "movl %eax, (%esp)\n" /* line 283 */
        "calll CIN_RunCinematic\n"
        "cvttss2si -0x28(%ebp), %eax\n" /* line 284 */
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xcc(%ebx), %eax\n" /* w */
        "movl %eax, (%esp)\n"
        "calll CIN_SetExtents\n"
        "movl 0xcc(%ebx), %eax\n" /* line 285 | w */
        "movl %eax, (%esp)\n"
        "calll CIN_DrawCinematic\n"
        "jmp .Lf166dd2_00166ef2\n"
        ".Lf166dd2_001671bd:\n"
        "leal 0x1ec(%ebx), %eax\n" /* line 328 | w */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xe0(%ebx), %eax\n" /* w */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* w */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n" /* w */
        "movl %eax, 8(%esp)\n"
        "movl 4(%ebx), %eax\n" /* w */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* w */
        "movl %eax, (%esp)\n"
        "calll UI_DrawTopBottom\n"
        "jmp .Lf166dd2_00166ed8\n"
        ".Lf166dd2_00167203:\n"
        "leal 0x1cc(%ebx), %edx\n" /* line 263 | w */
        "jmp .Lf166dd2_00167145\n"
        ".Lf166dd2_0016720e:\n"
        "leal 0x1cc(%ebx), %edx\n" /* line 268 | w */
        "jmp .Lf166dd2_00167021\n"
        ".Lf166dd2_00167219:\n"
        "leal 0x1cc(%ebx), %edx\n" /* line 293 | w */
        "jmp .Lf166dd2_00167005\n"
        ".Lf166dd2_00167224:\n"
        "movl $0x3f800000, -0x10(%ebp)\n" /* line 314 */
        "movl $0x3f000000, %eax\n" /* line 315 */
        "movl %eax, -0x14(%ebp)\n"
        "movl %eax, -0x18(%ebp)\n" /* color */
        "jmp .Lf166dd2_00166fd9\n"
        ".Lf166dd2_0016723b:\n"
        "movl $0xa, 0x14(%esp)\n" /* line 275 */
        "cvttss2si -0x28(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "cvttss2si -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "cvttss2si -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "cvttss2si -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc8(%ebx), %eax\n" /* w */
        "movl %eax, (%esp)\n"
        "calll CIN_PlayCinematic\n"
        "movl $0xfffffffe, %edx\n" /* line 278 */
        "cmpl $-1, %eax\n"
        "cmovnel %eax, %edx\n"
        "movl %edx, 0xcc(%ebx)\n" /* w */
        "movl %edx, %eax\n"
        "jmp .Lf166dd2_00167168\n"
        /* { scope 2 */
        ".Lf166dd2_0016728d:\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 194 | fadeInAmount */
        "addss 0x1e8(%ebx), %xmm0\n"
        "movss %xmm0, 0x1e8(%ebx)\n"
        "ucomiss 0x18(%ebp), %xmm0\n" /* line 195 | fadeClamp */
        "jb .Lf166dd2_001670d3\n"
        "movss 0x18(%ebp), %xmm0\n" /* line 197 | fadeClamp */
        "movss %xmm0, 0x1e8(%ebx)\n"
        "andl $0xffffffdf, %edx\n" /* line 200 */
        "jmp .Lf166dd2_001670d3\n"
        /* } scope */
        ".Lf166dd2_001672c1:\n"
        "leal 0x1dc(%ebx), %eax\n" /* line 254 | w */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* w */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* w */
        "movl %eax, 0x10(%esp)\n"
        "movss -0x28(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movss -0x20(%ebp), %xmm1\n"
        "movss %xmm1, 4(%esp)\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_FillRect\n"
        "jmp .Lf166dd2_00166ef2\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_166dd2_0:\n"
        ".long .Lf166dd2_00166ef2\n"
        ".long .Lf166dd2_00167072\n"
        ".long .Lf166dd2_00166ef2\n"
        ".long .Lf166dd2_00167136\n"
        ".long .Lf166dd2_00166ef2\n"
        ".long .Lf166dd2_00167155\n"
        ".long .Lf166dd2_00166fe8\n"
        ".long .Lf166dd2_00167012\n"
        ".text\n"
    );
}

/* Menu_Setup — initialize menu system: clear menus, setup keyword hashes, load key bindings */
void Menu_Setup(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    *(int *)(d + 0x22c) = 0;  /* menuCount = 0 */
    *(int *)(d + 0x270) = 0;  /* openMenuCount = 0 */
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
    itemCount = *(int *)(m + 0x218);
    if (itemCount <= 0)
        return;

    feederFloat = (float)feeder;

    for (i = 0; i < itemCount; i++) {
        byte *item = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
        byte *listPtr;

        if (*(float *)(item + 0x2d8) != feederFloat)
            continue;

        listPtr = (byte *)Item_GetListBoxDef((itemDef_t *)item);
        Item_SetCursorPos((itemDef_t *)item, index);
        UI_FeederSelection(*(float *)(item + 0x2d8), *(int *)(item + 0x2dc));

        if (!listPtr)
            continue;

        if (index == 0) {
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        } else if (index < *(int *)listPtr) {
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
        byte *item = (byte *)Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;

        Window_AddDynamicFlags((void *)item, 0x84);
        Window_SetOffsetTime((itemDef_t *)item, time);
        ((void (*)(void *, void *))Window_SetRectClient)(item, &rectFrom);
        ((void (*)(void *, void *))Window_SetRectEffects0)(item, &rectTo);

        /* Compute step rect: copy item rect at 0x158, override first 4 floats with step values */
        rectDef_t newRect = *(rectDef_t *)(item + 0x158);
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
        byte *parent = *(byte **)(item + 0x29c);
        if (parent) {
            float px = *(float *)parent;
            float py = *(float *)(parent + 4);
            if (*(int *)(parent + 0xd4)) {
                float borderSize = *(float *)(parent + 0xe0);
                px += borderSize;
                py += borderSize;
            }
            ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                item, px, py, *(int *)(parent + 0x10), *(int *)(parent + 0x14));
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

    Menu_TransitionItemByName(*(menuDef_t **)((byte *)item + 0x29c), name, rectFrom, rectTo, time, amt);
}

/* Menu_OrbitItemByName — set orbit animation on matching items */
void Menu_OrbitItemByName(menuDef_t *menu, const char *p, float x, float y, float cx, float cy, int time)
{
    int count = Menu_ItemsMatchingGroup(menu, p);
    int i;

    for (i = 0; i < count; i++) {
        byte *item = (byte *)Menu_GetMatchingItemByNumber(menu, i, p);
        if (!item) continue;

        Window_AddDynamicFlags((void *)item, 0x2004);
        Window_SetOffsetTime((itemDef_t *)item, time);

        /* Set effects0 rect: copy item rect at 0xf8 but override x/y with cx/cy */
        rectDef_t newRect;
        newRect = *(rectDef_t *)(item + 0xf8);
        newRect.x = cx;
        newRect.y = cy;
        /* Window_SetRectEffects0 takes (item, rectDef_t*) in the binary */
        ((void (*)(void *, void *))Window_SetRectEffects0)(item, &newRect);

        /* Set client rect: copy item rect at 0x60 but override x/y with x/y args */
        newRect = *(rectDef_t *)(item + 0x60);
        newRect.x = x;
        newRect.y = y;
        ((void (*)(void *, void *))Window_SetRectClient)(item, &newRect);

        /* Update screen coords from parent */
        byte *parent = *(byte **)(item + 0x29c);
        if (parent) {
            float px = *(float *)parent;
            float py = *(float *)(parent + 4);
            if (*(int *)(parent + 0xd4))  {
                float borderSize = *(float *)(parent + 0xe0);
                px += borderSize;
                py += borderSize;
            }
            ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                item, px, py, *(int *)(parent + 0x10), *(int *)(parent + 0x14));
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

    Menu_OrbitItemByName(*(menuDef_t **)((byte *)item + 0x29c), name, x, y, cx, cy, time);
}

/* Script_CloseForGameType — close menu named with gametype dvar substitution */
void Script_CloseForGameType(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    (void)item;
    if (!String_Parse(args, name, 0x400))
        return;
    const char *p = va(name, Dvar_GetString(*(const char **)((byte *)item + 0x2c0)));
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

/* line 3785 */
__attribute__((naked))
void Item_TextColor(displayContextDef_t *dc, itemDef_t *item, vec4_t *newColor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3785 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* item */
        "movl 0x10(%ebp), %edi\n" /* newColor */
        /* { scope 1 */
        "movl 0x29c(%ebx), %esi\n" /* line 3788 | item, parent */
        "movl 0xe8(%ebx), %edx\n" /* line 80 */
        "movss 0x23c(%esi), %xmm0\n" /* line 3792 | parent, fadeInAmount */
        "movss 0x238(%esi), %xmm1\n" /* parent, fadeAmount */
        "movl 0x230(%esi), %ecx\n" /* parent, offsetTime */
        "movss 0x234(%esi), %xmm2\n" /* parent, clamp */
        /* { scope 2 */
        "testb $0x30, %dl\n" /* line 179 */
        "je .Lf167d76_00167dc9\n"
        "movl 8(%ebp), %eax\n" /* line 181 | dc */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "cmpl 0x1c8(%ebx), %eax\n"
        "jg .Lf167d76_00167f39\n"
        /* } scope */
        ".Lf167d76_00167dc9:\n"
        "movl %edx, 4(%esp)\n" /* line 3793 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_SetDynamicFlags\n"
        "movl 0xe8(%ebx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf167d76_00167de7\n"
        "testb $2, %al\n" /* line 3795 */
        "jne .Lf167d76_00167fb0\n"
        ".Lf167d76_00167de7:\n"
        "cmpl $1, 0x290(%ebx)\n" /* line 3803 | item */
        "je .Lf167d76_00167e43\n"
        ".Lf167d76_00167df0:\n"
        "leal 0x1cc(%ebx), %edx\n" /* line 3813 | item */
        "movl 0x1cc(%ebx), %eax\n" /* item */
        "movl %eax, (%edi)\n" /* newColor */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%edi)\n" /* newColor */
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%edi)\n" /* newColor */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%edi)\n" /* newColor */
        ".Lf167d76_00167e10:\n"
        "movl 0x2cc(%ebx), %eax\n" /* line 3817 | item */
        "testl %eax, %eax\n"
        "je .Lf167d76_00167e3b\n"
        "cmpb $0, (%eax)\n"
        "je .Lf167d76_00167e3b\n"
        "movl 0x2c4(%ebx), %eax\n" /* item */
        "testl %eax, %eax\n"
        "je .Lf167d76_00167e3b\n"
        "cmpb $0, (%eax)\n"
        "je .Lf167d76_00167e3b\n"
        "testb $3, 0x2d0(%ebx)\n" /* line 3819 | item */
        "jne .Lf167d76_00167f73\n"
        /* } scope */
        ".Lf167d76_00167e3b:\n"
        "addl $0x3c, %esp\n" /* line 3824 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf167d76_00167e43:\n"
        "movl 8(%ebp), %edx\n" /* line 3803 | dc */
        "movl 4(%edx), %ecx\n"
        "movl %ecx, %edx\n"
        "testl %ecx, %ecx\n"
        "js .Lf167d76_001680d6\n"
        ".Lf167d76_00167e53:\n"
        "andb $1, %dh\n"
        "jne .Lf167d76_00167df0\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 3805 | 0.800000011920929f */
        "movss 0x1cc(%ebx), %xmm1\n" /* item */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* lowLight */
        "movss 0x1d0(%ebx), %xmm1\n" /* line 3806 | item */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss 0x1d4(%ebx), %xmm1\n" /* line 3807 | item */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss 0x1d8(%ebx), %xmm0\n" /* line 3808 | item */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl $0x1b4e81b5, %edx\n" /* line 3809 */
        "movl %ecx, %eax\n" /* a */
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "leal 0x1cc(%ebx), %ecx\n" /* item, a */
        "movl $1, %edx\n"
        "pxor %xmm4, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        ".Lf167d76_00167ef0:\n"
        "leal (, %edx, 4), %eax\n" /* line 3785 */
        /* { scope 2 */
        "movss -4(%ecx, %eax), %xmm0\n" /* line 94 */
        "movss -0x2c(%ebp, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal (%edi, %eax), %eax\n" /* line 3785 | newColor */
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm4\n" /* line 95 */
        "ja .Lf167d76_001680c1\n"
        "ucomiss %xmm3, %xmm1\n" /* line 97 */
        "jbe .Lf167d76_00167f2c\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf167d76_00167f2c:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf167d76_00167ef0\n"
        "jmp .Lf167d76_00167e10\n"
        /* } scope */
        /* { scope 2 */
        ".Lf167d76_00167f39:\n"
        "addl %eax, %ecx\n" /* line 183 */
        "movl %ecx, 0x1c8(%ebx)\n"
        "testb $0x10, %dl\n" /* line 184 */
        "jne .Lf167d76_00168092\n"
        "addss 0x1d8(%ebx), %xmm0\n" /* line 194 */
        "movss %xmm0, 0x1d8(%ebx)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 195 */
        "jb .Lf167d76_00167dc9\n"
        "movss %xmm2, 0x1d8(%ebx)\n" /* line 197 */
        "andl $0xffffffdf, %edx\n" /* line 200 */
        "jmp .Lf167d76_00167dc9\n"
        /* } scope */
        ".Lf167d76_00167f73:\n"
        "movl $1, 4(%esp)\n" /* line 3819 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "jne .Lf167d76_00167e3b\n"
        "leal 0x26c(%esi), %edx\n" /* line 3821 | parent */
        "movl 0x26c(%esi), %eax\n" /* parent */
        "movl %eax, (%edi)\n" /* newColor */
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%edi)\n" /* newColor */
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%edi)\n" /* newColor */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%edi)\n" /* newColor */
        "jmp .Lf167d76_00167e3b\n"
        ".Lf167d76_00167fb0:\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 3797 | 0.800000011920929f */
        "movss 0x25c(%esi), %xmm1\n" /* parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x28(%ebp)\n" /* lowLight */
        "movss 0x260(%esi), %xmm1\n" /* line 3798 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x24(%ebp)\n"
        "movss 0x264(%esi), %xmm1\n" /* line 3799 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x20(%ebp)\n"
        "mulss 0x268(%esi), %xmm0\n" /* line 3800 | parent */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 3801 | dc */
        "movl 4(%edx), %ecx\n" /* a */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "leal 0x25c(%esi), %ecx\n" /* parent, a */
        "movl $1, %edx\n"
        "pxor %xmm4, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        ".Lf167d76_0016804e:\n"
        "leal (, %edx, 4), %eax\n" /* line 3785 */
        /* { scope 2 */
        "movss -4(%eax, %ecx), %xmm0\n" /* line 94 */
        "movss -0x2c(%ebp, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "addl %edi, %eax\n" /* line 3785 | newColor */
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm4\n" /* line 95 */
        "ja .Lf167d76_001680cd\n"
        "ucomiss %xmm3, %xmm1\n" /* line 97 */
        "jbe .Lf167d76_00168085\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf167d76_00168085:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf167d76_0016804e\n"
        "jmp .Lf167d76_00167e10\n"
        /* } scope */
        /* { scope 2 */
        ".Lf167d76_00168092:\n"
        "movss 0x1d8(%ebx), %xmm0\n" /* line 186 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x1d8(%ebx)\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 187 | 0.0f */
        "ja .Lf167d76_00167dc9\n"
        "jp .Lf167d76_00167dc9\n"
        "andl $0xffffffeb, %edx\n" /* line 189 */
        "jmp .Lf167d76_00167dc9\n"
        /* } scope */
        /* { scope 2 */
        ".Lf167d76_001680c1:\n"
        "movl $0, -4(%eax)\n" /* line 96 */
        "jmp .Lf167d76_00167f2c\n"
        /* } scope */
        /* { scope 2 */
        ".Lf167d76_001680cd:\n"
        "movl $0, -4(%eax)\n"
        "jmp .Lf167d76_00168085\n"
        /* } scope */
        ".Lf167d76_001680d6:\n"
        "leal 0xff(%ecx), %edx\n" /* line 3803 */
        "jmp .Lf167d76_00167e53\n"
    );
}

/* line 3963 */
__attribute__((naked))
void Item_Text_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3963 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x47c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* item */
        /* { scope 1 */
        "movl 0x294(%esi), %edi\n" /* line 3973 | item, textPtr */
        "testl %edi, %edi\n" /* textPtr */
        "je .Lf1680e2_0016823c\n"
        "cmpb $0x40, (%edi)\n" /* line 3987 | textPtr */
        "je .Lf1680e2_00168277\n"
        ".Lf1680e2_00168108:\n"
        "cmpb $0, (%edi)\n" /* line 3990 | textPtr */
        "jne .Lf1680e2_00168118\n"
        /* } scope */
        ".Lf1680e2_0016810d:\n"
        "addl $0x47c, %esp\n" /* line 4013 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1680e2_00168118:\n"
        "leal -0x30(%ebp), %eax\n" /* line 3993 | color */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* item */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_TextColor\n"
        "movl %edi, 0xc(%esp)\n" /* line 3996 | textPtr */
        "leal -0x1c(%ebp), %eax\n" /* height */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* width */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetTextExtents\n"
        "movl 0xe4(%esi), %eax\n" /* line 3999 | item */
        "testl $0x00400000, %eax\n"
        "jne .Lf1680e2_00168289\n"
        "testl $0x00800000, %eax\n" /* line 4003 */
        "jne .Lf1680e2_0016821e\n"
        "movl 0x290(%esi), %eax\n" /* line 4011 | item */
        "movl %eax, -0x44c(%ebp)\n"
        "movl 0x28c(%esi), %ebx\n" /* item */
        "movl 0x14(%esi), %edx\n" /* item */
        "movl %edx, -0x448(%ebp)\n"
        "movl 0x10(%esi), %eax\n" /* item */
        "movl %eax, -0x444(%ebp)\n"
        "movss 0x214(%esi), %xmm0\n" /* item */
        "movss %xmm0, -0x440(%ebp)\n"
        "movss 0x210(%esi), %xmm0\n" /* item */
        "movss %xmm0, -0x43c(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl -0x44c(%ebp), %edx\n" /* line 4011 */
        "movl %edx, 0x24(%esp)\n"
        "leal -0x30(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n"
        "movl -0x448(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0x444(%ebp), %edx\n"
        "movl %edx, 0x14(%esp)\n"
        "movss -0x440(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x43c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* textPtr */
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 4013 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1680e2_0016821e:\n"
        "leal -0x30(%ebp), %edx\n" /* line 4005 | color */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* textPtr */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_Text_AutoWrapped_Paint\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 4013 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1680e2_0016823c:\n"
        "movl 0x2c0(%esi), %eax\n" /* line 3975 | item */
        "testl %eax, %eax\n"
        "je .Lf1680e2_0016810d\n"
        "movl %eax, (%esp)\n" /* line 3978 */
        "calll Dvar_GetVariantString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x430(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, %edi\n" /* textPtr */
        "cmpb $0x40, (%edi)\n" /* line 3987 | textPtr */
        "jne .Lf1680e2_00168108\n"
        ".Lf1680e2_00168277:\n"
        "leal 1(%edi), %eax\n" /* line 3988 | textPtr */
        "movl %eax, (%esp)\n"
        "calll UI_SafeTranslateString\n"
        "movl %eax, %edi\n" /* textPtr */
        "jmp .Lf1680e2_00168108\n"
        ".Lf1680e2_00168289:\n"
        "leal -0x30(%ebp), %eax\n" /* line 4001 | color */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* textPtr */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_Text_Wrapped_Paint\n"
        /* } scope */
        "addl $0x47c, %esp\n" /* line 4013 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
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

/* line 4090 */
__attribute__((naked))
void Item_YesNo_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4090 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        "movl 8(%ebp), %esi\n" /* dc */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 4094 | item */
        "movl 0x29c(%eax), %ebx\n" /* parent */
        "movl 0x2c0(%eax), %eax\n" /* line 4099 */
        "testl %eax, %eax\n"
        "je .Lf16870e_00168a3a\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x68(%ebp)\n"
        "cvtsd2ss -0x68(%ebp), %xmm0\n"
        "movss %xmm0, -0x4c(%ebp)\n" /* value */
        "pxor %xmm4, %xmm4\n"
        ".Lf16870e_00168755:\n"
        "movl 0xc(%ebp), %edx\n" /* line 143 | item */
        "movl 0xe8(%edx), %eax\n"
        "testb $4, %al\n" /* line 155 */
        "je .Lf16870e_0016886a\n"
        "testb $2, %al\n" /* line 4101 */
        "je .Lf16870e_00168867\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 4103 | 0.800000011920929f */
        "movss 0x25c(%ebx), %xmm1\n" /* parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* lowLight */
        "movss 0x260(%ebx), %xmm1\n" /* line 4104 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss 0x264(%ebx), %xmm1\n" /* line 4105 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 0x268(%ebx), %xmm0\n" /* line 4106 | parent */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 4(%esi), %ecx\n" /* line 4107 | dc, a */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm4, -0x88(%ebp)\n"
        "calll sinf\n"
        "fstps -0x8c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "leal 0x25c(%ebx), %ecx\n" /* parent, a */
        "movl $1, %edx\n"
        "leal -0x38(%ebp), %ebx\n" /* lowLight, parent */
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss -0x88(%ebp), %xmm4\n"
        /* { scope 2 */
        ".Lf16870e_0016881e:\n"
        "movss -4(%ecx, %edx, 4), %xmm0\n" /* line 94 */
        "leal (, %edx, 4), %eax\n"
        "movss -4(%ebx, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal -0x28(%ebp), %edi\n" /* line 4090 | newColor */
        "leal (%edi, %eax), %eax\n"
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm4\n" /* line 95 */
        "ja .Lf16870e_00168a48\n"
        "ucomiss %xmm3, %xmm1\n" /* line 97 */
        "jbe .Lf16870e_0016885d\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf16870e_0016885d:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf16870e_0016881e\n"
        "jmp .Lf16870e_0016888e\n"
        ".Lf16870e_00168867:\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        /* } scope */
        ".Lf16870e_0016886a:\n"
        "addl $0x1cc, %edx\n" /* line 4111 */
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0x1cc(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* newColor */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        ".Lf16870e_0016888e:\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 4114 | value */
        "ucomiss %xmm4, %xmm0\n"
        "jp .Lf16870e_0016889e\n"
        "je .Lf16870e_00168979\n"
        ".Lf16870e_0016889e:\n"
        "movl $str_002ac294, (%esp)\n" /* line 4115 */
        "calll UI_SafeTranslateString\n"
        "movl %eax, -0x48(%ebp)\n" /* yesNoStr */
        "movl 0xc(%ebp), %edi\n" /* line 99 | item */
        "addl $0x210, %edi\n"
        "movl 0xc(%ebp), %eax\n" /* line 4121 | item */
        "movl 0x294(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf16870e_001689a2\n"
        ".Lf16870e_001688c7:\n"
        "movl %eax, 4(%esp)\n" /* line 4123 */
        "movl %esi, (%esp)\n" /* dc */
        "calll Item_Text_Paint\n"
        "movl 0xc(%ebp), %edx\n" /* line 4124 | item */
        "movl 0x290(%edx), %esi\n" /* dc */
        "movl 0x28c(%edx), %ebx\n" /* parent */
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
        "movl %esi, 0x24(%esp)\n" /* line 4124 | dc */
        "leal -0x28(%ebp), %edx\n" /* newColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* parent */
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, 0x18(%esp)\n"
        "movl -0x40(%ebp), %edi\n" /* textRect */
        "movl %edi, 0x14(%esp)\n" /* textRect */
        "movss -0x44(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0x78(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n" /* line 4128 */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* yesNoStr */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 4130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16870e_00168979:\n"
        "movl $str_002ac29c, (%esp)\n" /* line 4117 */
        "calll UI_SafeTranslateString\n" /* line 4115 */
        "movl %eax, -0x48(%ebp)\n" /* yesNoStr */
        "movl 0xc(%ebp), %edi\n" /* line 99 | item */
        "addl $0x210, %edi\n"
        "movl 0xc(%ebp), %eax\n" /* line 4121 | item */
        "movl 0x294(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf16870e_001688c7\n"
        ".Lf16870e_001689a2:\n"
        "movl %eax, %edx\n"
        "movl 0x290(%eax), %esi\n" /* line 4128 | dc */
        "movl 0x28c(%eax), %ebx\n" /* parent */
        "movl 0x14(%eax), %ecx\n"
        "movl %ecx, -0x5c(%ebp)\n"
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movss 4(%edi), %xmm0\n" /* textRect */
        "movss %xmm0, -0x54(%ebp)\n"
        "movss 0x210(%edx), %xmm1\n"
        "movss %xmm1, -0x50(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x24(%esp)\n" /* line 4128 | dc */
        "leal -0x28(%ebp), %edx\n" /* newColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* parent */
        "movl -0x5c(%ebp), %ecx\n"
        "movl %ecx, 0x18(%esp)\n"
        "movl -0x58(%ebp), %edi\n" /* textRect */
        "movl %edi, 0x14(%esp)\n" /* textRect */
        "movss -0x54(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0x50(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* yesNoStr */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 4130 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16870e_00168a3a:\n"
        "pxor %xmm4, %xmm4\n" /* line 4099 */
        "movss %xmm4, -0x4c(%ebp)\n" /* value */
        "jmp .Lf16870e_00168755\n"
        /* { scope 2 */
        ".Lf16870e_00168a48:\n"
        "movl $0, -4(%eax)\n" /* line 96 */
        "jmp .Lf16870e_0016885d\n"
    );
}

/* line 4624 */
__attribute__((naked))
void Item_Slider_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4624 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* item */
        /* { scope 1 */
        "movl 0x29c(%esi), %ebx\n" /* line 4628 | item, parent */
        "movl 0x2c0(%esi), %eax\n" /* line 4632 | item */
        "testl %eax, %eax\n"
        "je .Lf168a54_00168a82\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstp %st(0)\n"
        ".Lf168a54_00168a82:\n"
        "movl 0xe8(%esi), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf168a54_00168b82\n"
        "testb $2, %al\n" /* line 4634 */
        "je .Lf168a54_00168b82\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 4636 | 0.800000011920929f */
        "movss 0x25c(%ebx), %xmm1\n" /* parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* lowLight */
        "movss 0x260(%ebx), %xmm1\n" /* line 4637 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss 0x264(%ebx), %xmm1\n" /* line 4638 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 0x268(%ebx), %xmm0\n" /* line 4639 | parent */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 4640 | dc */
        "movl 4(%eax), %ecx\n" /* a */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "leal 0x25c(%ebx), %ecx\n" /* parent, a */
        "movl $1, %edx\n"
        "leal -0x38(%ebp), %ebx\n" /* lowLight, parent */
        "leal -0x28(%ebp), %edi\n" /* newColor */
        "pxor %xmm3, %xmm3\n"
        "movss lit4_002ed5d0, %xmm4\n" /* 1.0f */
        /* { scope 2 */
        ".Lf168a54_00168b3c:\n"
        "movss -4(%ecx, %edx, 4), %xmm0\n" /* line 94 */
        "leal (, %edx, 4), %eax\n"
        "movss -4(%ebx, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal (%edi, %eax), %eax\n" /* line 4624 */
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm3\n" /* line 95 */
        "ja .Lf168a54_00168c98\n"
        "ucomiss %xmm4, %xmm1\n" /* line 97 */
        "jbe .Lf168a54_00168b78\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf168a54_00168b78:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf168a54_00168b3c\n"
        "jmp .Lf168a54_00168ba6\n"
        /* } scope */
        ".Lf168a54_00168b82:\n"
        "leal 0x1cc(%esi), %edx\n" /* line 4644 | item */
        "movl 0x1cc(%esi), %eax\n" /* item */
        "movl %eax, -0x28(%ebp)\n" /* newColor */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x28(%ebp), %edi\n" /* newColor */
        ".Lf168a54_00168ba6:\n"
        "movss 4(%esi), %xmm0\n" /* line 4648 | item */
        "movss %xmm0, -0x3c(%ebp)\n" /* y */
        "movl 0x294(%esi), %ecx\n" /* line 4649 | item */
        "testl %ecx, %ecx\n"
        "je .Lf168a54_00168c8f\n"
        "movl %esi, 4(%esp)\n" /* line 4651 | item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_Text_Paint\n"
        "movss 0x210(%esi), %xmm0\n" /* line 4653 | item */
        "addss 0x218(%esi), %xmm0\n" /* item */
        "addss lit4_002ed740, %xmm0\n" /* 8.0f */
        ".Lf168a54_00168be5:\n"
        "movl imp_sharedUiInfo, %ebx\n" /* line 4659 | parent */
        "movl 0x18(%ebx), %eax\n" /* parent */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* item */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* item */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41800000, 0xc(%esp)\n"
        "movl $0x42c00000, 8(%esp)\n"
        "movss -0x3c(%ebp), %xmm1\n" /* y */
        "movss %xmm1, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        "movl %esi, (%esp)\n" /* line 4661 | item */
        "calll Item_Slider_ThumbPosition\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n"
        "movl 0x1c(%ebx), %eax\n" /* line 4662 | parent */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* item */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* item */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x41a00000, 0xc(%esp)\n"
        "movl $0x41200000, 8(%esp)\n"
        "movss -0x3c(%ebp), %xmm1\n" /* y */
        "subss lit4_002ed62c, %xmm1\n" /* 2.0f */
        "movss %xmm1, 4(%esp)\n"
        "subss lit4_002ed6d4, %xmm0\n" /* 5.0f */
        "movss %xmm0, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 4663 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf168a54_00168c8f:\n"
        "movss (%esi), %xmm0\n" /* line 4657 | item */
        "jmp .Lf168a54_00168be5\n"
        /* { scope 2 */
        ".Lf168a54_00168c98:\n"
        "movl $0, -4(%eax)\n" /* line 96 */
        "jmp .Lf168a54_00168b78\n"
    );
}

/* line 4666 */
__attribute__((naked))
void Item_Bind_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4666 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12c, %esp\n"
        "movl 8(%ebp), %esi\n" /* dc */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 4673 | item */
        "movl 0x29c(%eax), %ebx\n" /* parent */
        "movl %eax, (%esp)\n" /* line 4674 | editPtr */
        "calll Item_GetEditFieldDef\n"
        "testl %eax, %eax\n" /* line 4678 */
        "je .Lf168ca4_00168e3b\n"
        "movl 0x18(%eax), %eax\n"
        "movl %eax, -0xc8(%ebp)\n" /* maxChars */
        "testl %eax, %eax\n"
        "je .Lf168ca4_00168e3b\n"
        "movl 0xc(%ebp), %edx\n" /* line 4681 | item */
        "movl 0x2c0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf168ca4_00168e56\n"
        ".Lf168ca4_00168cee:\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstp %st(0)\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0xe8(%ecx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "jne .Lf168ca4_00168e66\n"
        ".Lf168ca4_00168d11:\n"
        "movl %ecx, %edx\n"
        ".Lf168ca4_00168d13:\n"
        "addl $0x1cc, %edx\n" /* line 4703 */
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0x1cc(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* newColor */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ecx, %edi\n"
        "movl %ecx, %eax\n"
        "addl $0x210, %edi\n" /* line 99 */
        "movl %edi, -0xc4(%ebp)\n" /* textRect */
        "movl 0x294(%eax), %ebx\n" /* line 4709 | parent */
        "testl %ebx, %ebx\n" /* parent */
        "je .Lf168ca4_00168f95\n"
        ".Lf168ca4_00168d55:\n"
        "movl %eax, 4(%esp)\n" /* line 4711 */
        "movl %esi, (%esp)\n" /* dc */
        "calll Item_Text_Paint\n"
        "leal -0xb8(%ebp), %edx\n" /* line 4712 | nameBind */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0x2c0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll BindingFromName\n"
        "movl 0xc(%ebp), %edi\n" /* line 4713 | item */
        "movl 0x290(%edi), %esi\n" /* dc */
        "movl 0x28c(%edi), %ebx\n" /* parent */
        "movl %edi, %eax\n"
        "movl 0x14(%edi), %edi\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0xbc(%ebp)\n"
        "movl -0xc4(%ebp), %ecx\n" /* textRect */
        "movss 4(%ecx), %xmm0\n"
        "movss %xmm0, -0xc0(%ebp)\n"
        "movss 0x210(%eax), %xmm0\n"
        "addss 8(%ecx), %xmm0\n"
        "addss lit4_002ed740, %xmm0\n" /* 8.0f */
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "movss %xmm0, -0xe8(%ebp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x24(%esp)\n" /* line 4713 | dc */
        "leal -0x28(%ebp), %ecx\n" /* newColor */
        "movl %ecx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* parent */
        "movl %edi, 0x18(%esp)\n"
        "movl -0xbc(%ebp), %edi\n"
        "movl %edi, 0x14(%esp)\n"
        "movss -0xc0(%ebp), %xmm1\n"
        "movss %xmm1, 0x10(%esp)\n"
        "movss -0xe8(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "leal -0xb8(%ebp), %edx\n" /* nameBind */
        "movl %edx, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x12c, %esp\n" /* line 4719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf168ca4_00168e3b:\n"
        "movl $0x7fffffff, -0xc8(%ebp)\n" /* line 4678 | maxChars */
        "movl 0xc(%ebp), %edx\n" /* line 4681 | item */
        "movl 0x2c0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf168ca4_00168cee\n"
        ".Lf168ca4_00168e56:\n"
        "movl %edx, %ecx\n"
        "movl 0xe8(%ecx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf168ca4_00168d11\n"
        ".Lf168ca4_00168e66:\n"
        "testb $2, %al\n" /* line 4683 */
        "je .Lf168ca4_0016904a\n"
        "cmpl g_bindItem, %ecx\n" /* line 4685 */
        "je .Lf168ca4_00169052\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 4694 | 0.800000011920929f */
        "movss 0x25c(%ebx), %xmm1\n" /* parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* lowLight */
        "movss 0x260(%ebx), %xmm1\n" /* line 4695 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss 0x264(%ebx), %xmm1\n" /* line 4696 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 0x268(%ebx), %xmm0\n" /* line 4697 | parent */
        "movss %xmm0, -0x2c(%ebp)\n"
        "pxor %xmm4, %xmm4\n"
        ".Lf168ca4_00168ec6:\n"
        "movl 4(%esi), %ecx\n" /* line 4699 | dc, a */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm4, -0xf8(%ebp)\n"
        "calll sinf\n"
        "fstps -0xfc(%ebp)\n"
        "movss -0xfc(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "leal 0x25c(%ebx), %ecx\n" /* parent, a */
        "movl $1, %edx\n"
        "leal -0x38(%ebp), %ebx\n" /* lowLight, parent */
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss -0xf8(%ebp), %xmm4\n"
        /* { scope 2 */
        ".Lf168ca4_00168f2e:\n"
        "movss -4(%ecx, %edx, 4), %xmm0\n" /* line 94 */
        "leal (, %edx, 4), %eax\n"
        "movss -4(%ebx, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal -0x28(%ebp), %edi\n" /* line 4666 | newColor */
        "leal (%edi, %eax), %eax\n"
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm4\n" /* line 95 */
        "ja .Lf168ca4_0016903e\n"
        "ucomiss %xmm3, %xmm1\n" /* line 97 */
        "jbe .Lf168ca4_00168f6d\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf168ca4_00168f6d:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf168ca4_00168f2e\n"
        "movl 0xc(%ebp), %edi\n" /* item */
        "movl 0xc(%ebp), %eax\n" /* item */
        /* } scope */
        "addl $0x210, %edi\n" /* line 99 */
        "movl %edi, -0xc4(%ebp)\n" /* textRect */
        "movl 0x294(%eax), %ebx\n" /* line 4709 | parent */
        "testl %ebx, %ebx\n" /* parent */
        "jne .Lf168ca4_00168d55\n"
        ".Lf168ca4_00168f95:\n"
        "movl %eax, %ecx\n"
        "movl %edi, %edx\n"
        "movl 0x290(%eax), %esi\n" /* line 4717 | dc */
        "movl 0x28c(%eax), %ebx\n" /* parent */
        "movl 0x14(%eax), %edi\n"
        "movl 0x10(%eax), %eax\n"
        "movl %eax, -0xd4(%ebp)\n"
        "movss 4(%edx), %xmm0\n"
        "movss %xmm0, -0xd0(%ebp)\n"
        "movss 0x210(%ecx), %xmm1\n"
        "movss %xmm1, -0xcc(%ebp)\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x24(%esp)\n" /* line 4717 | dc */
        "leal -0x28(%ebp), %edx\n" /* newColor */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* parent */
        "movl %edi, 0x18(%esp)\n"
        "movl -0xd4(%ebp), %ecx\n"
        "movl %ecx, 0x14(%esp)\n"
        "movss -0xd0(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movss -0xcc(%ebp), %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0xc8(%ebp), %eax\n" /* maxChars */
        "movl %eax, 4(%esp)\n"
        "movl $str_002ac2a4, (%esp)\n" /* "FIXME" */
        "calll UI_DrawText\n" /* line 4713 */
        /* } scope */
        "addl $0x12c, %esp\n" /* line 4719 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf168ca4_0016903e:\n"
        "movl $0, -4(%eax)\n" /* line 96 */
        "jmp .Lf168ca4_00168f6d\n"
        ".Lf168ca4_0016904a:\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "jmp .Lf168ca4_00168d13\n"
        /* } scope */
        ".Lf168ca4_00169052:\n"
        "movl $0x3f4ccccd, %eax\n" /* line 4687 */
        "movl %eax, -0x38(%ebp)\n" /* lowLight */
        "pxor %xmm4, %xmm4\n" /* line 4688 */
        "movss %xmm4, -0x34(%ebp)\n"
        "movss %xmm4, -0x30(%ebp)\n" /* line 4689 */
        "movl %eax, -0x2c(%ebp)\n" /* line 4690 */
        "jmp .Lf168ca4_00168ec6\n"
    );
}

/* line 5043 */
__attribute__((naked))
void Item_OwnerDraw_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5043 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dc */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 5052 | item */
        "testl %eax, %eax\n"
        "je .Lf169070_00169258\n"
        "movl 0xc(%ebp), %eax\n" /* line 5057 | item */
        "movl 0x29c(%eax), %esi\n" /* parent */
        "movl 0xe8(%eax), %edx\n" /* line 80 */
        "movss 0x23c(%esi), %xmm0\n" /* line 5059 | parent, fadeInAmount */
        "movss 0x238(%esi), %xmm1\n" /* parent, fadeAmount */
        "movl 0x230(%esi), %ecx\n" /* parent, offsetTime */
        "movss 0x234(%esi), %xmm2\n" /* parent, clamp */
        /* { scope 2 */
        "testb $0x30, %dl\n" /* line 179 */
        "je .Lf169070_001690fe\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %eax\n" /* line 181 */
        "cmpl 0x1c8(%ebx), %eax\n"
        "jle .Lf169070_001690fe\n"
        "leal (%ecx, %eax), %eax\n" /* line 183 */
        "movl %eax, 0x1c8(%ebx)\n"
        "testb $0x10, %dl\n" /* line 184 */
        "jne .Lf169070_00169518\n"
        "movl 0xc(%ebp), %eax\n" /* line 194 | item */
        "addss 0x1d8(%eax), %xmm0\n"
        "movss %xmm0, 0x1d8(%eax)\n"
        "ucomiss %xmm2, %xmm0\n" /* line 195 */
        "jb .Lf169070_001690fe\n"
        "movss %xmm2, 0x1d8(%eax)\n" /* line 197 */
        "andl $0xffffffdf, %edx\n" /* line 200 */
        /* } scope */
        ".Lf169070_001690fe:\n"
        "movl %edx, 4(%esp)\n" /* line 5060 */
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Window_SetDynamicFlags\n"
        "movl 0xc(%ebp), %ebx\n" /* line 5061 | item */
        "addl $0x1cc, %ebx\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0x1cc(%ecx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%ebx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0xe8(%ecx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "jne .Lf169070_00169263\n"
        "movl %ecx, %eax\n"
        "cmpl $1, 0x290(%eax)\n" /* line 5071 */
        "je .Lf169070_0016927b\n"
        ".Lf169070_00169151:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 5080 | item */
        "testb $3, 0x2d0(%ebx)\n"
        "jne .Lf169070_0016937d\n"
        ".Lf169070_00169161:\n"
        "movl %ebx, %eax\n"
        ".Lf169070_00169163:\n"
        "movl 0x294(%eax), %esi\n" /* line 5086 | parent */
        "testl %esi, %esi\n" /* parent */
        "je .Lf169070_001693a6\n"
        ".Lf169070_00169171:\n"
        "movl %eax, 4(%esp)\n" /* line 5088 */
        "movl %edi, (%esp)\n" /* dc */
        "calll Item_Text_Paint\n"
        "movl 0xc(%ebp), %edx\n" /* line 99 | item */
        "addl $0x210, %edx\n"
        "movl %edx, -0x3c(%ebp)\n" /* textRect */
        "movl 0xc(%ebp), %ecx\n" /* line 5090 | item */
        "movl 0x294(%ecx), %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf169070_00169458\n"
        "movl 0x290(%ecx), %esi\n" /* line 5093 | parent */
        "movl 0x20c(%ecx), %edi\n" /* dc */
        "movl 0x28c(%ecx), %ebx\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x40(%esp)\n" /* line 5093 | parent */
        "movl %edi, 0x3c(%esp)\n" /* dc */
        "leal -0x28(%ebp), %edx\n" /* color */
        "movl %edx, 0x38(%esp)\n"
        "movl %ebx, 0x34(%esp)\n"
        "movl %eax, 0x30(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0x2d8(%ecx), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x278(%ecx), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl 0xdc(%ecx), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl 0xd8(%ecx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x288(%ecx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss 0x210(%ecx), %xmm0\n"
        "movl -0x3c(%ebp), %ebx\n" /* textRect */
        "addss 8(%ebx), %xmm0\n"
        "addss lit4_002ed740, %xmm0\n" /* 8.0f */
        "movss %xmm0, (%esp)\n"
        "calll UI_OwnerDraw\n"
        /* } scope */
        ".Lf169070_00169258:\n"
        "addl $0x9c, %esp\n" /* line 5104 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf169070_00169263:\n"
        "testb $2, %al\n" /* line 5063 */
        "jne .Lf169070_00169570\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "cmpl $1, 0x290(%eax)\n" /* line 5071 */
        "jne .Lf169070_00169151\n"
        ".Lf169070_0016927b:\n"
        "movl 4(%edi), %ecx\n" /* dc */
        "movl %ecx, %edx\n"
        "testl %ecx, %ecx\n"
        "js .Lf169070_00169668\n"
        ".Lf169070_00169288:\n"
        "andb $1, %dh\n"
        "jne .Lf169070_00169151\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 5073 | 0.800000011920929f */
        "movl 0xc(%ebp), %edx\n" /* item */
        "movss 0x1cc(%edx), %xmm1\n"
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* lowLight */
        "movss 0x1d0(%edx), %xmm1\n" /* line 5074 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss 0x1d4(%edx), %xmm1\n" /* line 5075 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 0x1d8(%edx), %xmm0\n" /* line 5076 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl $0x1b4e81b5, %edx\n" /* line 5077 */
        "movl %ecx, %eax\n"
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n"
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "movl $1, %edx\n"
        "pxor %xmm4, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        /* { scope 2 */
        ".Lf169070_00169326:\n"
        "movss -4(%ebx, %edx, 4), %xmm0\n" /* line 94 */
        "leal (, %edx, 4), %eax\n"
        "movss -0x3c(%ebp, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal -0x28(%ebp), %ecx\n" /* line 5043 | color */
        "leal (%ecx, %eax), %eax\n"
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm4\n" /* line 95 */
        "ja .Lf169070_0016965c\n"
        "ucomiss %xmm3, %xmm1\n" /* line 97 */
        "jbe .Lf169070_00169365\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf169070_00169365:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf169070_00169326\n"
        /* } scope */
        "movl 0xc(%ebp), %ebx\n" /* line 5080 | item */
        "testb $3, 0x2d0(%ebx)\n"
        "je .Lf169070_00169161\n"
        ".Lf169070_0016937d:\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "je .Lf169070_00169547\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl 0x294(%eax), %esi\n" /* line 5086 | parent */
        "testl %esi, %esi\n" /* parent */
        "jne .Lf169070_00169171\n"
        ".Lf169070_001693a6:\n"
        "movl 0x290(%eax), %esi\n" /* line 5102 | parent */
        "movl 0x20c(%eax), %edi\n" /* dc */
        "movl 0x28c(%eax), %ebx\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x40(%esp)\n" /* line 5102 | parent */
        "movl %edi, 0x3c(%esp)\n" /* dc */
        "leal -0x28(%ebp), %ecx\n" /* color */
        "movl %ecx, 0x38(%esp)\n"
        "movl %ebx, 0x34(%esp)\n"
        "movl %eax, 0x30(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* item */
        "movl 0x2d8(%ebx), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x278(%ebx), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl 0xdc(%ebx), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl 0xd8(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x288(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x284(%ebx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_OwnerDraw\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 5104 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf169070_00169458:\n"
        "movl 0x290(%ecx), %esi\n" /* line 5097 | parent */
        "movl 0x20c(%ecx), %edi\n" /* dc */
        "movl 0x28c(%ecx), %ebx\n"
        "movl %ebx, 4(%esp)\n" /* line 3711 */
        "movl 0x27c(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %esi, 0x40(%esp)\n" /* line 5097 | parent */
        "movl %edi, 0x3c(%esp)\n" /* dc */
        "leal -0x28(%ebp), %ecx\n" /* color */
        "movl %ecx, 0x38(%esp)\n"
        "movl %ebx, 0x34(%esp)\n"
        "movl %eax, 0x30(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* item */
        "movl 0x2d8(%ebx), %eax\n"
        "movl %eax, 0x2c(%esp)\n"
        "movl 0x278(%ebx), %eax\n"
        "movl %eax, 0x28(%esp)\n"
        "movl 0xdc(%ebx), %eax\n"
        "movl %eax, 0x24(%esp)\n"
        "movl 0xd8(%ebx), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x288(%ebx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movss 0x210(%ebx), %xmm0\n"
        "movl -0x3c(%ebp), %eax\n" /* textRect */
        "addss 8(%eax), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll UI_OwnerDraw\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 5104 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf169070_00169518:\n"
        "movss 0x1d8(%ebx), %xmm0\n" /* line 186 */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x1d8(%ebx)\n"
        "ucomiss lit4_002ed5e8, %xmm0\n" /* line 187 | 0.0f */
        "ja .Lf169070_001690fe\n"
        "jp .Lf169070_001690fe\n"
        "andl $0xffffffeb, %edx\n" /* line 189 */
        "jmp .Lf169070_001690fe\n"
        /* } scope */
        ".Lf169070_00169547:\n"
        "leal 0x26c(%esi), %edx\n" /* line 5082 | parent */
        "movl 0x26c(%esi), %eax\n" /* parent */
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl 4(%edx), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "jmp .Lf169070_00169163\n"
        ".Lf169070_00169570:\n"
        "movss lit4_002ed7f0, %xmm0\n" /* line 5065 | 0.800000011920929f */
        "movss 0x25c(%esi), %xmm1\n" /* parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x38(%ebp)\n" /* lowLight */
        "movss 0x260(%esi), %xmm1\n" /* line 5066 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x34(%ebp)\n"
        "movss 0x264(%esi), %xmm1\n" /* line 5067 | parent */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x30(%ebp)\n"
        "mulss 0x268(%esi), %xmm0\n" /* line 5068 | parent */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl 4(%edi), %ecx\n" /* line 5069 | dc, a */
        "movl $0x1b4e81b5, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "imull %edx\n"
        "sarl $3, %edx\n"
        "movl %ecx, %eax\n" /* a */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll sinf\n"
        "fstps -0x4c(%ebp)\n"
        "movss -0x4c(%ebp), %xmm2\n" /* t */
        "movss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "mulss %xmm0, %xmm2\n" /* t */
        "addss %xmm0, %xmm2\n" /* t */
        "leal 0x25c(%esi), %ecx\n" /* parent, a */
        "movl $1, %edx\n"
        "pxor %xmm4, %xmm4\n"
        "movss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        /* { scope 2 */
        ".Lf169070_0016960b:\n"
        "movss -4(%ecx, %edx, 4), %xmm0\n" /* line 94 */
        "leal (, %edx, 4), %eax\n"
        "movss -0x3c(%ebp, %eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "leal -0x28(%ebp), %ebx\n" /* line 5043 | color */
        "leal (%ebx, %eax), %eax\n"
        "movss %xmm1, -4(%eax)\n" /* line 94 */
        "ucomiss %xmm1, %xmm4\n" /* line 95 */
        "ja .Lf169070_00169653\n"
        "ucomiss %xmm3, %xmm1\n" /* line 97 */
        "jbe .Lf169070_00169646\n"
        "movl $0x3f800000, -4(%eax)\n" /* line 98 */
        ".Lf169070_00169646:\n"
        "addl $1, %edx\n"
        "cmpl $5, %edx\n" /* line 92 */
        "jne .Lf169070_0016960b\n"
        "jmp .Lf169070_00169151\n"
        ".Lf169070_00169653:\n"
        "movl $0, -4(%eax)\n" /* line 96 */
        "jmp .Lf169070_00169646\n"
        /* } scope */
        /* { scope 2 */
        ".Lf169070_0016965c:\n"
        "movl $0, -4(%eax)\n"
        "jmp .Lf169070_00169365\n"
        /* } scope */
        ".Lf169070_00169668:\n"
        "leal 0xff(%ecx), %edx\n" /* line 5071 */
        "jmp .Lf169070_00169288\n"
    );
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

/* line 3027 */
__attribute__((naked))
qboolean Item_Slider_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3027 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* item */
        /* { scope 1 */
        "movl 0x2c0(%ebx), %ecx\n" /* line 3033 | item */
        "testl %ecx, %ecx\n"
        "je .Lf16993a_00169a53\n"
        "movl 0xe8(%ebx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf16993a_00169a53\n"
        "testb $2, %al\n" /* line 2280 */
        "je .Lf16993a_00169a53\n"
        "movl 0x10(%ebp), %eax\n" /* line 2283 | key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "jbe .Lf16993a_0016999b\n"
        ".Lf16993a_00169976:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3039 | key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf16993a_00169a5c\n"
        "movl %ebx, %edx\n" /* line 3041 | item */
        "movl 8(%ebp), %eax\n" /* dc */
        "calll Scroll_Slider_SetThumbPos\n"
        "movl $1, %eax\n"
        "jmp .Lf16993a_00169a55\n"
        ".Lf16993a_0016999b:\n"
        "movl 8(%ebp), %eax\n" /* line 2274 | dc */
        "cvtsi2ssl 0x10(%eax), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%eax), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 417 */
        "movl %eax, -0x28(%ebp)\n" /* compareRect */
        "movl 4(%ebx), %eax\n" /* line 418 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 419 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 420 */
        "movl %eax, -0x1c(%ebp)\n"
        "movss %xmm0, -0xc(%ebp)\n" /* line 422 | compareX */
        "movss %xmm1, -0x10(%ebp)\n" /* line 423 | compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0xc(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x10(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%ebx), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* compareRect */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0xc(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16993a_00169a53\n"
        "addss -0x20(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16993a_00169a53\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss -0x10(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16993a_00169a53\n"
        "addss -0x1c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf16993a_00169976\n"
        /* } scope */
        /* } scope */
        ".Lf16993a_00169a53:\n"
        "xorl %eax, %eax\n" /* line 3062 */
        /* } scope */
        ".Lf16993a_00169a55:\n"
        "addl $0x50, %esp\n" /* line 3066 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16993a_00169a5c:\n"
        "movl %ebx, (%esp)\n" /* line 3045 | item */
        "calll Item_GetEditFieldDef\n"
        "movl %eax, %esi\n" /* editDef */
        "testl %eax, %eax\n" /* line 3046 */
        "je .Lf16993a_00169a53\n"
        "movss 4(%eax), %xmm0\n" /* line 3048 */
        "movss %xmm0, -0x2c(%ebp)\n" /* step */
        "subss (%eax), %xmm0\n"
        "mulss lit4_002ed72c, %xmm0\n" /* 0.05000000074505806f */
        "movss %xmm0, -0x2c(%ebp)\n" /* step */
        "movl 0x2c0(%ebx), %eax\n" /* line 3049 | item */
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x38(%ebp)\n"
        "cvtsd2ss -0x38(%ebp), %xmm0\n"
        "cmpl $0x9c, 0x10(%ebp)\n" /* line 3051 | key */
        "je .Lf16993a_00169b07\n"
        "cmpl $0xa4, 0x10(%ebp)\n" /* key */
        "je .Lf16993a_00169b07\n"
        "cmpl $0x9d, 0x10(%ebp)\n" /* line 3058 | key */
        "je .Lf16993a_00169ac7\n"
        "cmpl $0xa3, 0x10(%ebp)\n" /* key */
        "jne .Lf16993a_00169a53\n"
        ".Lf16993a_00169ac7:\n"
        "addss -0x2c(%ebp), %xmm0\n" /* line 3060 | step */
        "movss 4(%esi), %xmm1\n" /* editDef */
        "minss %xmm1, %xmm0\n"
        ".Lf16993a_00169ad5:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 3061 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00217c20, (%esp)\n" /* "%g" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2c0(%ebx), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "movl $1, %eax\n"
        "jmp .Lf16993a_00169a55\n"
        ".Lf16993a_00169b07:\n"
        "subss -0x2c(%ebp), %xmm0\n" /* line 3053 | step */
        "movss (%esi), %xmm1\n" /* editDef */
        "maxss %xmm1, %xmm0\n"
        "jmp .Lf16993a_00169ad5\n"
    );
}

/* line 2290 */
__attribute__((naked))
qboolean Item_YesNo_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2290 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x60, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* item */
        /* { scope 1 */
        "movl 0x2c0(%esi), %ebx\n" /* line 2294 | item */
        "testl %ebx, %ebx\n"
        "je .Lf169b16_00169baf\n"
        "movl 0xe8(%esi), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf169b16_00169baf\n"
        "testb $2, %al\n" /* line 2280 */
        "je .Lf169b16_00169baf\n"
        "movl 0x10(%ebp), %eax\n" /* line 2283 | key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "jbe .Lf169b16_00169bb8\n"
        ".Lf169b16_00169b4a:\n"
        "cmpl $0xd, 0x10(%ebp)\n" /* line 2300 | key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0x9c, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0x9d, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0xa4, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0xa3, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0xc8, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0xc9, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        "cmpl $0xca, 0x10(%ebp)\n" /* key */
        "je .Lf169b16_00169c81\n"
        ".Lf169b16_00169baf:\n"
        "xorl %eax, %eax\n" /* line 2304 */
        /* } scope */
        "addl $0x60, %esp\n" /* line 2309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf169b16_00169bb8:\n"
        "movl 8(%ebp), %eax\n" /* line 2274 | dc */
        "cvtsi2ssl 0x10(%eax), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%eax), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 417 */
        "movl %eax, -0x28(%ebp)\n" /* compareRect */
        "movl 4(%esi), %eax\n" /* line 418 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 419 */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* line 420 */
        "movl %eax, -0x1c(%ebp)\n"
        "movss %xmm0, -0xc(%ebp)\n" /* line 422 | compareX */
        "movss %xmm1, -0x10(%ebp)\n" /* line 423 | compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0xc(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x10(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%esi), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* compareRect */
        "leal -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x28(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0xc(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169b16_00169baf\n"
        "addss -0x20(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169b16_00169baf\n"
        "movss -0x24(%ebp), %xmm0\n"
        "movss -0x10(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169b16_00169baf\n"
        "addss -0x1c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169b16_00169baf\n"
        "jmp .Lf169b16_00169b4a\n"
        /* } scope */
        /* } scope */
        ".Lf169b16_00169c81:\n"
        "movl 0x2c0(%esi), %eax\n" /* line 2302 | item */
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl $0x19, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x41(%ebp), %ebx\n" /* dvarString */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl %ebx, (%esp)\n" /* line 2303 */
        "calll atoi\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2c0(%esi), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x60, %esp\n" /* line 2309 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1357 */
__attribute__((naked))
qboolean Item_SetFocus(displayContextDef_t *dc, itemDef_t *item, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1357 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: compareRect, compareX, compareY */
        "movl imp_sharedUiInfo, %eax\n" /* line 1362 */
        "movl 0x40(%eax), %eax\n"
        "movl %eax, -0x40(%ebp)\n" /* sound */
        "movl 0xc(%ebp), %eax\n" /* line 1370 | item */
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a014\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "testb $0x10, 0xe6(%eax)\n"
        "jne .Lf169ce4_0016a014\n"
        "movl %eax, %edx\n"
        "movl 0xe8(%eax), %eax\n"
        "testb $4, %al\n"
        "je .Lf169ce4_0016a014\n"
        "testb $2, %al\n" /* line 1374 */
        "jne .Lf169ce4_0016a01e\n"
        "movl 0x29c(%edx), %ecx\n" /* line 1386 */
        "movl %ecx, -0x3c(%ebp)\n" /* parent */
        "testl %ecx, %ecx\n" /* line 1388 */
        "je .Lf169ce4_00169d4e\n"
        "movl 0xe8(%ecx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf169ce4_00169e5a\n"
        "testb $2, %al\n" /* line 1388 */
        "je .Lf169ce4_00169e5a\n"
        ".Lf169ce4_00169d4e:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1399 | item */
        "movl 0x2d0(%edx), %eax\n"
        "testb $3, %al\n"
        "jne .Lf169ce4_0016a1a7\n"
        ".Lf169ce4_00169d5f:\n"
        "testb $0xc, %al\n" /* line 1404 */
        "jne .Lf169ce4_0016a1cd\n"
        ".Lf169ce4_00169d67:\n"
        "movl 0xc(%ebp), %eax\n" /* line 1409 | item */
        "movl 0x29c(%eax), %esi\n" /* menu */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "testl %esi, %esi\n" /* line 381 */
        "je .Lf169ce4_0016a02b\n"
        "movl 0x218(%esi), %edi\n" /* line 386 */
        "testl %edi, %edi\n"
        "jle .Lf169ce4_0016a02b\n"
        "movl $0, -0x44(%ebp)\n" /* oldFocus */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf169ce4_00169d8f:\n"
        "leal (, %ebx, 4), %edi\n" /* line 381 */
        "movl 0x27c(%esi), %eax\n" /* line 388 */
        "movl (%edi, %eax), %eax\n"
        "movl 0xe8(%eax), %edx\n" /* line 143 */
        "testb $4, %dl\n" /* line 155 */
        "je .Lf169ce4_00169db6\n"
        "andb $2, %dl\n" /* line 388 */
        "movl -0x44(%ebp), %edx\n" /* oldFocus */
        "cmovnel %eax, %edx\n"
        "movl %edx, -0x44(%ebp)\n" /* oldFocus */
        ".Lf169ce4_00169db6:\n"
        "movl $2, 4(%esp)\n" /* line 392 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        "movl 0x27c(%esi), %eax\n" /* line 393 */
        "movl (%edi, %eax), %edx\n"
        "movl 0x2bc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf169ce4_00169dec\n"
        "movl %eax, 8(%esp)\n" /* line 395 */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl %ecx, (%esp)\n"
        "calll Item_RunScript\n"
        ".Lf169ce4_00169dec:\n"
        "addl $1, %ebx\n" /* line 386 | i */
        "cmpl 0x218(%esi), %ebx\n" /* i */
        "jl .Lf169ce4_00169d8f\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %ebx\n" /* line 1411 | item, i */
        "movl 0x270(%ebx), %eax\n" /* i */
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a043\n"
        ".Lf169ce4_00169e08:\n"
        "movl $2, 4(%esp)\n" /* line 1451 */
        "movl %ebx, (%esp)\n" /* i */
        "calll Window_AddDynamicFlags\n"
        "movl 0xc(%ebp), %ecx\n" /* line 1452 | item */
        "movl 0x2b8(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a245\n"
        "movl %eax, 8(%esp)\n" /* line 1454 */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %ebx\n" /* dc, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll Item_RunScript\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        ".Lf169ce4_00169e3f:\n"
        "movl 0x2d4(%edx), %eax\n" /* line 1457 */
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a232\n"
        ".Lf169ce4_00169e4d:\n"
        "movl %eax, (%esp)\n" /* line 1468 */
        "calll UI_PlayLocalSoundAlias\n"
        "jmp .Lf169ce4_0016a132\n"
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf169ce4_00169e5a:\n"
        "movl 8(%ebp), %ebx\n" /* line 5400 | dc, i */
        "movl 0x270(%ebx), %esi\n" /* i */
        "subl $1, %esi\n" /* i */
        "js .Lf169ce4_00169d4e\n"
        "leal 0x230(%ebx, %esi, 4), %edx\n" /* i */
        "xorl %ecx, %ecx\n"
        ".Lf169ce4_00169e75:\n"
        "movl (%edx), %ebx\n" /* line 5402 | i */
        "movl 0xe8(%ebx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf169ce4_0016a185\n"
        "testb $2, %al\n" /* line 5402 */
        "je .Lf169ce4_0016a185\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1391 | i */
        "je .Lf169ce4_00169d4e\n"
        /* { scope 2: compareRect, compareX, compareY */
        "movl (%ebx), %eax\n" /* line 417 | i */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%ebx), %eax\n" /* line 418 | i */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 419 | i */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 420 | i */
        "movl %eax, -0x2c(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %esi\n" /* compareY */
        "movl %esi, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%ebx), %eax\n" /* line 428 | i */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* i */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "leal -0x30(%ebp), %ebx\n" /* i */
        "movl %ebx, 8(%esp)\n" /* i */
        "leal -0x34(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "leal -0x38(%ebp), %ecx\n" /* compareRect */
        "movl %ecx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169ce4_00169d4e\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169ce4_00169d4e\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169ce4_00169d4e\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169ce4_00169d4e\n"
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        "movl -0x3c(%ebp), %edx\n" /* line 417 | parent */
        "movl (%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%edx), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "movl %esi, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl -0x3c(%ebp), %edx\n" /* line 428 | parent */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* i */
        "movl %edi, 4(%esp)\n"
        "leal -0x38(%ebp), %ebx\n" /* compareRect, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169ce4_00169d4e\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169ce4_00169d4e\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169ce4_00169d4e\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169ce4_00169d4e\n"
        /* } scope */
        ".Lf169ce4_0016a014:\n"
        "xorl %eax, %eax\n" /* line 1472 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1482 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf169ce4_0016a01e:\n"
        "movl $1, %eax\n" /* line 1472 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1482 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        ".Lf169ce4_0016a02b:\n"
        "movl $0, -0x44(%ebp)\n" /* line 386 | oldFocus */
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %ebx\n" /* line 1411 | item, i */
        "movl 0x270(%ebx), %eax\n" /* i */
        "testl %eax, %eax\n"
        "jne .Lf169ce4_00169e08\n"
        ".Lf169ce4_0016a043:\n"
        "movl %ebx, %ecx\n" /* i */
        /* { scope 2: compareRect, compareX, compareY */
        "movl %ebx, %eax\n" /* line 99 */
        "addl $0x210, %eax\n"
        "movl 8(%eax), %edx\n" /* line 1418 */
        "movl 0x14(%eax), %ebx\n" /* i */
        "movl 0x10(%eax), %esi\n" /* menu */
        "movss 0xc(%eax), %xmm1\n"
        "movss 4(%eax), %xmm0\n"
        /* { scope 3 */
        "movl 0x210(%ecx), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "subss %xmm1, %xmm0\n" /* line 418 */
        "movss %xmm0, -0x34(%ebp)\n"
        "movl %edx, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 420 */
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %ebx, 0x14(%esp)\n" /* line 428 | i */
        "movl %esi, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169ce4_0016a0f8\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf169ce4_0016a1ed\n"
        /* } scope */
        ".Lf169ce4_0016a0f8:\n"
        "movl -0x44(%ebp), %esi\n" /* line 1438 | oldFocus, menu */
        "testl %esi, %esi\n" /* menu */
        "je .Lf169ce4_0016a132\n"
        "movl $2, 4(%esp)\n" /* line 1440 */
        "movl -0x44(%ebp), %ecx\n" /* oldFocus */
        "movl %ecx, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        "movl -0x44(%ebp), %ebx\n" /* line 1441 | oldFocus, i */
        "movl 0x2b8(%ebx), %eax\n" /* i */
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a132\n"
        "movl %eax, 8(%esp)\n" /* line 1443 */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        /* } scope */
        ".Lf169ce4_0016a132:\n"
        "movl -0x3c(%ebp), %ebx\n" /* line 1472 | parent, i */
        "movl 0x218(%ebx), %ecx\n" /* i */
        "testl %ecx, %ecx\n"
        "jle .Lf169ce4_0016a01e\n"
        "movl 0x27c(%ebx), %edx\n" /* line 1474 | i */
        "movl 0xc(%ebp), %eax\n" /* item */
        "cmpl (%edx), %eax\n"
        "je .Lf169ce4_0016a24c\n"
        "xorl %eax, %eax\n" /* line 1477 */
        ".Lf169ce4_0016a156:\n"
        "addl $1, %eax\n" /* line 1472 */
        "cmpl %eax, %ecx\n"
        "je .Lf169ce4_0016a01e\n"
        "movl 0xc(%ebp), %ebx\n" /* line 1474 | item, i */
        "cmpl (%edx, %eax, 4), %ebx\n" /* i */
        "jne .Lf169ce4_0016a156\n"
        ".Lf169ce4_0016a169:\n"
        "movl %eax, 4(%esp)\n" /* line 1476 */
        "movl -0x3c(%ebp), %eax\n" /* parent */
        "movl %eax, (%esp)\n"
        "calll Menu_SetCursorItem\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 1482 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf169ce4_0016a185:\n"
        "addl $1, %ecx\n" /* line 155 */
        "subl $4, %edx\n"
        /* { scope 2: compareRect, compareX, compareY */
        "leal 1(%esi), %eax\n" /* line 5400 | i */
        "cmpl %eax, %ecx\n"
        "jne .Lf169ce4_00169e75\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 1399 | item */
        "movl 0x2d0(%edx), %eax\n"
        "testb $3, %al\n"
        "je .Lf169ce4_00169d5f\n"
        ".Lf169ce4_0016a1a7:\n"
        "movl $1, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a014\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl 0x2d0(%ecx), %eax\n"
        "jmp .Lf169ce4_00169d5f\n"
        ".Lf169ce4_0016a1cd:\n"
        "movl $4, 4(%esp)\n" /* line 1404 */
        "movl 0xc(%ebp), %ebx\n" /* item, i */
        "movl %ebx, (%esp)\n" /* i */
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "jne .Lf169ce4_00169d67\n"
        "jmp .Lf169ce4_0016a014\n"
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        ".Lf169ce4_0016a1ed:\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 430 */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf169ce4_0016a0f8\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf169ce4_0016a0f8\n"
        /* } scope */
        "movl $2, 4(%esp)\n" /* line 1426 */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        "movl 0xc(%ebp), %edx\n" /* line 1428 | item */
        "movl 0x2d4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf169ce4_00169e4d\n"
        /* } scope */
        ".Lf169ce4_0016a232:\n"
        "movl -0x40(%ebp), %eax\n" /* line 1466 | sound */
        "testl %eax, %eax\n"
        "je .Lf169ce4_0016a132\n"
        "movl -0x40(%ebp), %eax\n" /* line 1457 | sound */
        "jmp .Lf169ce4_00169e4d\n"
        ".Lf169ce4_0016a245:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf169ce4_00169e3f\n"
        ".Lf169ce4_0016a24c:\n"
        "xorl %eax, %eax\n" /* line 1474 */
        "jmp .Lf169ce4_0016a169\n"
    );
}

/* Script_SetFocusByDvar — find item with matching dvarTest and set focus */
void Script_SetFocusByDvar(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char dvarName[0x400];
    byte *parent;
    int i;

    if (!String_Parse(args, dvarName, 0x400))
        return;

    parent = *(byte **)((byte *)item + 0x29c);
    if (!parent)
        return;

    int itemCount = *(int *)(parent + 0x218);
    for (i = 0; i < itemCount; i++) {
        byte *focusItem = *(byte **)(*(byte **)(parent + 0x27c) + i * 4);

        if (!(*(byte *)(focusItem + 0x2d0) & 0x10))
            continue;

        const char *dvarTest = *(const char **)(focusItem + 0x2c4);
        if (!dvarTest)
            Com_Error(1, "\x15Script_SetFocusByDvar: Item's dvarTest field is empty.");

        if (I_stricmp(dvarTest, dvarName) != 0)
            continue;

        if (!Item_EnableShowViaDvar((itemDef_t *)focusItem, 0x10))
            continue;

        if (Item_SetFocus(dc, (itemDef_t *)focusItem, *(float *)focusItem, *(float *)(focusItem + 4)))
            return;
    }
}

/* Script_SetFocus — find item by name in parent menu, set focus and optional edit mode */
void Script_SetFocus(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    byte *menu;
    byte *focusItem = NULL;
    int i;

    if (!String_Parse(args, name, 0x400))
        return;

    menu = *(byte **)((byte *)item + 0x29c);

    /* Find item by window.name */
    if (menu && *(int *)(menu + 0x218) > 0) {
        for (i = 0; i < *(int *)(menu + 0x218); i++) {
            byte *it = *(byte **)(*(byte **)(menu + 0x27c) + i * 4);
            const char *itemName = *(const char **)(it + 0xc0);
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

    if (!Item_SetFocus(dc, (itemDef_t *)focusItem, *(float *)focusItem, *(float *)(focusItem + 4))) {
        Com_Printf(0, "setFocus: error focusing widget '%s' (widget was found but could not accept focus)\n", name);
        return;
    }

    /* Check if this is an editable item type (check type against bitmask 0x70210) */
    int itemType = *(int *)(focusItem + 0x270);
    if (itemType <= 0x12 && ((1 << itemType) & 0x70210)) {
        editFieldDef_t *editPtr = Item_GetEditFieldDef((itemDef_t *)focusItem);
        if (editPtr)
            *(int *)((byte *)editPtr + 0x1c) = 0;
        Item_SetCursorPos((itemDef_t *)focusItem, 0);
        g_editingField = 1;
        g_editItem = (itemDef_t *)focusItem;
        Key_SetOverstrikeMode(1);
    }
}

/* line 1659 */
__attribute__((naked))
int Item_ListBox_OverLB(itemDef_t *item, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1659 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        /* { scope 1: compareRect, compareX, compareY */
        "movl 0x2d8(%ebx), %eax\n" /* line 1668 | item */
        "movl %eax, (%esp)\n"
        "calll UI_FeederCount\n"
        "movl %ebx, (%esp)\n" /* line 1669 | item */
        "calll Item_GetListBoxDef\n"
        "testl %eax, %eax\n" /* line 1670 */
        "je .Lf16a482_0016a838\n"
        "movl 0x10(%ebx), %edi\n" /* line 1674 | item */
        "movl 0x14(%ebx), %esi\n" /* line 1675 | item */
        "testb $0x20, 0xe6(%ebx)\n" /* line 1676 | item */
        "jne .Lf16a482_0016a842\n"
        "movss (%ebx), %xmm0\n" /* line 1714 | item */
        "movss %xmm0, -0x44(%ebp)\n"
        "addss 8(%ebx), %xmm0\n" /* item */
        "movss %xmm0, -0x44(%ebp)\n"
        "movss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "movss -0x44(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x44(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* line 1715 | item */
        /* { scope 2 */
        "movss %xmm1, -0x38(%ebp)\n" /* line 417 | compareRect */
        "movl %eax, -0x34(%ebp)\n" /* line 418 */
        "movss %xmm0, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm2\n" /* line 422 | x */
        "movss %xmm2, -0x20(%ebp)\n" /* compareX */
        "movss 0x10(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a57c\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf16a482_0016ac1e\n"
        /* } scope */
        ".Lf16a482_0016a57c:\n"
        "movss 4(%ebx), %xmm0\n" /* line 1721 | item */
        "addss 0xc(%ebx), %xmm0\n" /* item */
        "movss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "subss %xmm1, %xmm0\n"
        /* { scope 2 */
        "movss -0x44(%ebp), %xmm2\n" /* line 417 */
        "movss %xmm2, -0x38(%ebp)\n" /* compareRect */
        "movss %xmm0, -0x34(%ebp)\n" /* line 418 */
        "movss %xmm1, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm1\n" /* line 423 | y */
        "movss %xmm1, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16a482_0016ab81\n"
        /* } scope */
        ".Lf16a482_0016a620:\n"
        "movl %ebx, (%esp)\n" /* line 1726 | item */
        "calll Item_ListBox_ThumbPosition\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x48(%ebp)\n" /* thumbstart */
        /* { scope 2 */
        "movss -0x44(%ebp), %xmm1\n" /* line 417 */
        "movss %xmm1, -0x38(%ebp)\n" /* compareRect */
        "movss %xmm0, -0x34(%ebp)\n" /* line 418 */
        "movl $0x41800000, %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl %eax, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm2\n" /* line 422 | x */
        "movss %xmm2, -0x1c(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a6d9\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a6d9\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16a482_0016ac74\n"
        /* } scope */
        ".Lf16a482_0016a6d9:\n"
        "movss lit4_002ed6a8, %xmm0\n" /* line 1732 | 16.0f */
        "movss 4(%ebx), %xmm1\n" /* item */
        "addss %xmm0, %xmm1\n"
        /* { scope 2 */
        "movss -0x44(%ebp), %xmm2\n" /* line 417 */
        "movss %xmm2, -0x38(%ebp)\n" /* compareRect */
        "movss %xmm1, -0x34(%ebp)\n" /* line 418 */
        "movss %xmm0, -0x30(%ebp)\n" /* line 419 */
        "movss -0x48(%ebp), %xmm0\n" /* line 420 | thumbstart */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movss 0x10(%ebp), %xmm1\n" /* line 423 | y */
        "movss %xmm1, -0x1c(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16a482_0016abba\n"
        /* } scope */
        ".Lf16a482_0016a781:\n"
        "movss 4(%ebx), %xmm1\n" /* line 1739 | item */
        "addss 0xc(%ebx), %xmm1\n" /* item */
        "movss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "subss %xmm0, %xmm1\n"
        /* { scope 2 */
        "movss -0x44(%ebp), %xmm2\n" /* line 417 */
        "movss %xmm2, -0x38(%ebp)\n" /* compareRect */
        "movss -0x48(%ebp), %xmm2\n" /* line 418 | thumbstart */
        "addss %xmm0, %xmm2\n"
        ".Lf16a482_0016a7aa:\n"
        "movss %xmm2, -0x34(%ebp)\n"
        "movss %xmm0, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm1\n" /* line 423 | y */
        "movss %xmm1, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a838\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf16a482_0016abf3\n"
        ".Lf16a482_0016a838:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf16a482_0016a83a:\n"
        "addl $0x5c, %esp\n" /* line 1746 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf16a482_0016a842:\n"
        "movss 4(%ebx), %xmm0\n" /* line 1680 | item */
        "movss %xmm0, -0x3c(%ebp)\n"
        "addss 0xc(%ebx), %xmm0\n" /* item */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "movss -0x3c(%ebp), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, -0x3c(%ebp)\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movss %xmm1, -0x34(%ebp)\n" /* line 418 */
        "movss %xmm0, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm2\n" /* line 422 | x */
        "movss %xmm2, -0x1c(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a8ff\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf16a482_0016ac49\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016a8ff:\n"
        "movss (%ebx), %xmm0\n" /* line 417 */
        "addss 8(%ebx), %xmm0\n"
        "movss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -0x38(%ebp)\n" /* compareRect */
        "movss -0x3c(%ebp), %xmm0\n" /* line 418 */
        "movss %xmm0, -0x34(%ebp)\n"
        "movss %xmm1, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm1\n" /* line 422 | x */
        "movss %xmm1, -0x1c(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm2\n" /* line 423 | y */
        "movss %xmm2, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16a482_0016ab48\n"
        /* } scope */
        ".Lf16a482_0016a9a2:\n"
        "movl %ebx, (%esp)\n" /* line 1693 | item */
        "calll Item_ListBox_ThumbPosition\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        /* { scope 2 */
        "movss %xmm0, -0x38(%ebp)\n" /* line 417 | compareRect */
        "movss -0x3c(%ebp), %xmm1\n" /* line 418 */
        "movss %xmm1, -0x34(%ebp)\n"
        "movl $0x41800000, %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl %eax, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm2\n" /* line 422 | x */
        "movss %xmm2, -0x1c(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016aa5b\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016aa5b\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16a482_0016ac8c\n"
        /* } scope */
        ".Lf16a482_0016aa5b:\n"
        "movss lit4_002ed6a8, %xmm1\n" /* line 1699 | 16.0f */
        "movss (%ebx), %xmm0\n" /* item */
        "addss %xmm1, %xmm0\n"
        /* { scope 2 */
        "movss %xmm0, -0x38(%ebp)\n" /* line 417 | compareRect */
        "movss -0x3c(%ebp), %xmm2\n" /* line 418 */
        "movss %xmm2, -0x34(%ebp)\n"
        "movss -0x40(%ebp), %xmm2\n" /* line 419 */
        "subss %xmm0, %xmm2\n"
        "movss %xmm2, -0x30(%ebp)\n"
        "movss %xmm1, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movss 0x10(%ebp), %xmm1\n" /* line 423 | y */
        "movss %xmm1, -0x1c(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %esi, 0x14(%esp)\n" /* line 428 */
        "movl %edi, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* compareRect */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016ab1b\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016ab1b\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16a482_0016aca4\n"
        /* } scope */
        ".Lf16a482_0016ab1b:\n"
        "movss (%ebx), %xmm0\n" /* line 1706 | item */
        "addss 8(%ebx), %xmm0\n" /* item */
        "movss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "subss %xmm1, %xmm0\n"
        /* { scope 2 */
        "movss -0x40(%ebp), %xmm2\n" /* line 417 */
        "addss %xmm1, %xmm2\n"
        "movss %xmm2, -0x38(%ebp)\n" /* compareRect */
        "movss -0x3c(%ebp), %xmm2\n" /* line 418 */
        "jmp .Lf16a482_0016a7aa\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016ab48:\n"
        "addss -0x30(%ebp), %xmm0\n" /* line 430 */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a9a2\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a9a2\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a9a2\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x200, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016ab81:\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a620\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a620\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a620\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x200, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016abba:\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a781\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a781\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a781\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x800, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        ".Lf16a482_0016abf3:\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a838\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a838\n"
        "movl $__mh_execute_header, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016ac1e:\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a57c\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a57c\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x100, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016ac49:\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16a482_0016a8ff\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a8ff\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x100, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016ac74:\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016a6d9\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x400, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016ac8c:\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016aa5b\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x400, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16a482_0016aca4:\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16a482_0016ab1b\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x800, %eax\n"
        "jmp .Lf16a482_0016a83a\n"
    );
}

/* line 1749 */
__attribute__((naked))
void Item_ListBox_MouseEnter(itemDef_t *item, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1749 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* item */
        /* { scope 1: compareRect, compareX, compareY */
        "movl %ebx, (%esp)\n" /* line 1753 | item */
        "calll Item_GetListBoxDef\n"
        "movl %eax, %esi\n" /* listPtr */
        "testl %eax, %eax\n" /* line 1755 */
        "je .Lf16acbc_0016ad38\n"
        "movl $0x1f00, 4(%esp)\n" /* line 1758 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_RemoveDynamicFlags\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 1759 | y */
        "movss %xmm0, 8(%esp)\n"
        "movss 0xc(%ebp), %xmm2\n" /* x */
        "movss %xmm2, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_ListBox_OverLB\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_AddDynamicFlags\n"
        "movl 0x10(%ebx), %eax\n" /* line 1762 | item */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x14(%ebx), %edi\n" /* line 1763 | item */
        "testb $0x20, 0xe6(%ebx)\n" /* line 1764 | item */
        "je .Lf16acbc_0016ad40\n"
        "testl $0x1f00, 0xe8(%ebx)\n" /* line 1766 | item */
        "jne .Lf16acbc_0016ad38\n"
        "cmpl $1, 0x3c(%esi)\n" /* line 1769 | listPtr */
        "je .Lf16acbc_0016ae7f\n"
        /* } scope */
        ".Lf16acbc_0016ad38:\n"
        "addl $0x5c, %esp\n" /* line 1805 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf16acbc_0016ad40:\n"
        "testl $0x1f00, 0xe8(%ebx)\n" /* line 1790 | item */
        "jne .Lf16acbc_0016ad38\n"
        "movss 4(%ebx), %xmm2\n" /* line 1793 | item */
        "movss %xmm2, -0x44(%ebp)\n"
        "movss 8(%ebx), %xmm1\n" /* line 1794 | item */
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "cvtsi2ssl 0x20(%esi), %xmm2\n" /* line 1795 | listPtr */
        "movss 0xc(%ebx), %xmm0\n" /* item */
        "subss %xmm2, %xmm0\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movss -0x44(%ebp), %xmm2\n" /* line 418 */
        "movss %xmm2, -0x34(%ebp)\n"
        "movss %xmm1, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm0, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movss 0x10(%ebp), %xmm2\n" /* line 423 | y */
        "movss %xmm2, -0x20(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %edi, 0x14(%esp)\n" /* line 428 */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16acbc_0016ad38\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16acbc_0016ad38\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16acbc_0016ad38\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16acbc_0016ad38\n"
        /* } scope */
        "movss 0x10(%ebp), %xmm0\n" /* line 1798 | y */
        "subss lit4_002ed62c, %xmm0\n" /* 2.0f */
        "subss -0x44(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%ebp)\n" /* y */
        "divss 0x38(%esi), %xmm0\n" /* listPtr */
        "cvttss2si %xmm0, %eax\n"
        "addl (%esi), %eax\n" /* listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl 0x24(%esi), %eax\n" /* line 1799 | listPtr */
        "cmpl 0x10(%esi), %eax\n" /* listPtr */
        "jle .Lf16acbc_0016ad38\n"
        ".Lf16acbc_0016ae6b:\n"
        "movl 0x10(%esi), %eax\n" /* line 1801 | listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16acbc_0016ad38\n"
        ".Lf16acbc_0016ae7f:\n"
        "movss (%ebx), %xmm0\n" /* line 1771 | item */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl 4(%ebx), %eax\n" /* line 1772 | item */
        "movss 0xc(%ebx), %xmm1\n" /* line 1773 | item */
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "cvtsi2ssl 0x20(%esi), %xmm2\n" /* line 1774 | listPtr */
        "movss 8(%ebx), %xmm0\n" /* item */
        "subss %xmm2, %xmm0\n"
        /* { scope 2 */
        "movss -0x3c(%ebp), %xmm2\n" /* line 417 */
        "movss %xmm2, -0x38(%ebp)\n" /* compareRect */
        "movl %eax, -0x34(%ebp)\n" /* line 418 */
        "movss %xmm0, -0x30(%ebp)\n" /* line 419 */
        "movss %xmm1, -0x2c(%ebp)\n" /* line 420 */
        "movss 0xc(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movss 0x10(%ebp), %xmm2\n" /* line 423 | y */
        "movss %xmm2, -0x1c(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %edi, 0x14(%esp)\n" /* line 428 */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16acbc_0016ad38\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16acbc_0016ad38\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16acbc_0016ad38\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16acbc_0016ad38\n"
        /* } scope */
        "movss 0xc(%ebp), %xmm0\n" /* line 1777 | x */
        "subss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 0xc(%ebp)\n" /* x */
        "divss 0x34(%esi), %xmm0\n" /* listPtr */
        "cvttss2si %xmm0, %eax\n"
        "addl (%esi), %eax\n" /* listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl 0x24(%esi), %eax\n" /* line 1778 | listPtr */
        "cmpl 0x10(%esi), %eax\n" /* listPtr */
        "jl .Lf16acbc_0016ad38\n"
        "jmp .Lf16acbc_0016ae6b\n"
    );
}

/* line 1808 */
__attribute__((naked))
void Item_MouseEnter(displayContextDef_t *dc, itemDef_t *item, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1808 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* item */
        /* { scope 1: compareRect, compareX, compareY */
        "testl %ebx, %ebx\n" /* line 1814 | item */
        "je .Lf16af9c_0016b0c1\n"
        "leal 0x210(%ebx), %eax\n" /* line 99 */
        "movss 8(%eax), %xmm0\n" /* line 1817 */
        "movss %xmm0, -0x4c(%ebp)\n"
        "movl 0x210(%ebx), %edi\n" /* item */
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movss 0xc(%eax), %xmm0\n"
        "movss %xmm0, -0x40(%ebp)\n"
        "movss 4(%eax), %xmm0\n"
        "subss -0x40(%ebp), %xmm0\n" /* line 1818 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl 0x2d0(%ebx), %eax\n" /* line 1824 | item */
        "testb $3, %al\n"
        "jne .Lf16af9c_0016b145\n"
        ".Lf16af9c_0016aff9:\n"
        "testb $0xc, %al\n" /* line 1829 */
        "jne .Lf16af9c_0016b0c9\n"
        ".Lf16af9c_0016b001:\n"
        "movl 0xe8(%ebx), %esi\n" /* line 80 */
        /* { scope 2 */
        "movl %edi, -0x38(%ebp)\n" /* line 417 | compareRect */
        "movss -0x3c(%ebp), %xmm0\n" /* line 418 */
        "movss %xmm0, -0x34(%ebp)\n"
        "movss -0x4c(%ebp), %xmm0\n" /* line 419 */
        "movss %xmm0, -0x30(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 420 */
        "movss %xmm0, -0x2c(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl -0x48(%ebp), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16af9c_0016b0e3\n"
        /* } scope */
        ".Lf16af9c_0016b09f:\n"
        "testl $0x40, %esi\n" /* line 1852 | flags */
        "jne .Lf16af9c_0016b168\n"
        "andl $1, %esi\n" /* line 1858 | flags */
        "je .Lf16af9c_0016b19a\n"
        ".Lf16af9c_0016b0b4:\n"
        "cmpl $6, 0x270(%ebx)\n" /* line 1864 | item */
        "je .Lf16af9c_0016b1d0\n"
        /* } scope */
        ".Lf16af9c_0016b0c1:\n"
        "addl $0x6c, %esp\n" /* line 1870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf16af9c_0016b0c9:\n"
        "movl $4, 4(%esp)\n" /* line 1829 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "jne .Lf16af9c_0016b001\n"
        "jmp .Lf16af9c_0016b0c1\n"
        /* { scope 2 */
        ".Lf16af9c_0016b0e3:\n"
        "addss -0x30(%ebp), %xmm0\n" /* line 430 */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16af9c_0016b09f\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16af9c_0016b09f\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16af9c_0016b09f\n"
        /* } scope */
        "testl $0x40, %esi\n" /* line 1837 | flags */
        "je .Lf16af9c_0016b1f6\n"
        ".Lf16af9c_0016b112:\n"
        "andl $1, %esi\n" /* line 1842 | flags */
        "jne .Lf16af9c_0016b0c1\n"
        "movl 0x2a8(%ebx), %eax\n" /* line 1844 | item */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* item */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_RunScript\n"
        "movl $1, 4(%esp)\n" /* line 1845 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_AddDynamicFlags\n"
        "jmp .Lf16af9c_0016b0c1\n"
        ".Lf16af9c_0016b145:\n"
        "movl $1, 4(%esp)\n" /* line 1824 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "je .Lf16af9c_0016b0c1\n"
        "movl 0x2d0(%ebx), %eax\n" /* item */
        "jmp .Lf16af9c_0016aff9\n"
        ".Lf16af9c_0016b168:\n"
        "movl 0x2a4(%ebx), %eax\n" /* line 1855 | item */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        "movl $0x40, 4(%esp)\n" /* line 1856 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_RemoveDynamicFlags\n"
        "andl $1, %esi\n" /* line 1858 | flags */
        "jne .Lf16af9c_0016b0b4\n"
        ".Lf16af9c_0016b19a:\n"
        "movl 0x2a8(%ebx), %eax\n" /* line 1860 | item */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* item */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_RunScript\n"
        "movl $1, 4(%esp)\n" /* line 1861 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_AddDynamicFlags\n"
        "cmpl $6, 0x270(%ebx)\n" /* line 1864 | item */
        "jne .Lf16af9c_0016b0c1\n"
        ".Lf16af9c_0016b1d0:\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 1866 | y */
        "movss %xmm0, 8(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* item */
        "calll Item_ListBox_MouseEnter\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 1870 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf16af9c_0016b1f6:\n"
        "movl 0x2a0(%ebx), %eax\n" /* line 1839 | item */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        "movl $0x40, 4(%esp)\n" /* line 1840 */
        "movl %ebx, (%esp)\n" /* item */
        "calll Window_AddDynamicFlags\n"
        "jmp .Lf16af9c_0016b112\n"
    );
}

/* line 1928 */
__attribute__((naked))
qboolean Item_ListBox_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down, qboolean force)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1928 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* item */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 1938 | item */
        "calll Item_GetListBoxDef\n"
        "movl %eax, %edi\n" /* listPtr */
        "testl %eax, %eax\n" /* line 1940 */
        "je .Lf16b224_0016b456\n"
        "movl 0x2d8(%esi), %eax\n" /* line 1943 | item */
        "movl %eax, (%esp)\n"
        "calll UI_FeederCount\n"
        "movl %eax, -0x44(%ebp)\n" /* count */
        "movl 8(%ebp), %eax\n" /* line 1948 | dc */
        "cvtsi2ssl 0x10(%eax), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%eax), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%esi), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* line 422 | compareX */
        "movss %xmm1, -0x20(%ebp)\n" /* line 423 | compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%esi), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16b224_0016b460\n"
        ".Lf16b224_0016b2e8:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf16b224_0016b2ea:\n"
        "movl 0xe8(%esi), %ebx\n" /* line 80 */
        "movl 0x18(%ebp), %edx\n" /* line 1954 | force */
        "testl %edx, %edx\n"
        "jne .Lf16b224_0016b308\n"
        "testl %eax, %eax\n"
        "je .Lf16b224_0016b456\n"
        "testb $2, %bl\n" /* flags */
        "je .Lf16b224_0016b456\n"
        ".Lf16b224_0016b308:\n"
        "movl %esi, (%esp)\n" /* line 1956 | item */
        "calll UI_OverrideCursorPos\n"
        "movl %esi, (%esp)\n" /* line 1958 | item */
        "calll Item_ListBox_MaxScroll\n"
        "movl %eax, -0x40(%ebp)\n" /* max */
        "testb $0x20, 0xe6(%esi)\n" /* line 1959 | item */
        "je .Lf16b224_0016b3cc\n"
        "movss 8(%esi), %xmm0\n" /* line 1961 | item */
        "divss 0x34(%edi), %xmm0\n" /* listPtr */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* viewmax */
        "cmpl $0x9c, 0x10(%ebp)\n" /* line 1965 | key */
        "je .Lf16b224_0016b505\n"
        "cmpl $0x9d, 0x10(%ebp)\n" /* line 1997 | key */
        "jne .Lf16b224_0016b411\n"
        "movl 0x108(%edi), %eax\n" /* line 2000 | listPtr */
        "testl %eax, %eax\n"
        "jne .Lf16b224_0016b84a\n"
        "movl 0x24(%edi), %eax\n" /* line 2002 | listPtr */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl 0x24(%edi), %eax\n" /* line 2003 | listPtr */
        "cmpl (%edi), %eax\n" /* listPtr */
        "jl .Lf16b224_0016b967\n"
        ".Lf16b224_0016b37e:\n"
        "movl -0x44(%ebp), %eax\n" /* line 2007 | count */
        "cmpl 0x24(%edi), %eax\n" /* listPtr */
        "jle .Lf16b224_0016b953\n"
        ".Lf16b224_0016b38a:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2250 | viewmax */
        "addl (%edi), %eax\n" /* listPtr */
        "cmpl %eax, 0x24(%edi)\n" /* listPtr */
        "jge .Lf16b224_0016b900\n"
        ".Lf16b224_0016b398:\n"
        "movl 0x24(%edi), %eax\n" /* line 2015 | listPtr */
        "movl %eax, 4(%esp)\n"
        ".Lf16b224_0016b39f:\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        ".Lf16b224_0016b3a7:\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2016 | item */
        "movl %eax, 4(%esp)\n"
        "movl 0x2d8(%esi), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll UI_FeederSelection\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16b224_0016b3cc:\n"
        "movss 0xc(%esi), %xmm0\n" /* line 2029 | item */
        "divss 0x38(%edi), %xmm0\n" /* listPtr */
        "cvttss2si %xmm0, %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* viewmax */
        "cmpl $0x9a, 0x10(%ebp)\n" /* line 2033 | key */
        "je .Lf16b224_0016b499\n"
        "cmpl $0xce, 0x10(%ebp)\n" /* key */
        "je .Lf16b224_0016b499\n"
        "cmpl $0x9b, 0x10(%ebp)\n" /* line 2058 | key */
        "je .Lf16b224_0016b576\n"
        "cmpl $0xcd, 0x10(%ebp)\n" /* key */
        "je .Lf16b224_0016b576\n"
        ".Lf16b224_0016b411:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2087 | key */
        "subl $0xc8, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf16b224_0016b722\n"
        "cmpl $0xa5, 0x10(%ebp)\n" /* line 2167 | key */
        "je .Lf16b224_0016b6e3\n"
        "cmpl $0xa6, 0x10(%ebp)\n" /* line 2181 | key */
        "je .Lf16b224_0016b7da\n"
        "cmpl $0xa4, 0x10(%ebp)\n" /* line 2201 | key */
        "je .Lf16b224_0016b87f\n"
        "cmpl $0xa3, 0x10(%ebp)\n" /* line 2232 | key */
        "je .Lf16b224_0016b620\n"
        ".Lf16b224_0016b456:\n"
        "xorl %eax, %eax\n" /* line 2262 */
        /* } scope */
        ".Lf16b224_0016b458:\n"
        "addl $0x5c, %esp\n" /* line 2269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        ".Lf16b224_0016b460:\n"
        "addss -0x30(%ebp), %xmm0\n" /* line 430 */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16b224_0016b2e8\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16b224_0016b2e8\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16b224_0016b2e8\n"
        "movl $1, %eax\n"
        "jmp .Lf16b224_0016b2ea\n"
        /* } scope */
        /* } scope */
        ".Lf16b224_0016b499:\n"
        "movl 0x108(%edi), %eax\n" /* line 2036 | listPtr */
        "testl %eax, %eax\n"
        "jne .Lf16b224_0016b54e\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2038 | item */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "movl 0x2dc(%esi), %ebx\n" /* line 2039 | item, flags */
        "testl %ebx, %ebx\n" /* flags */
        "js .Lf16b224_0016b978\n"
        ".Lf16b224_0016b4ca:\n"
        "movl 0x2dc(%esi), %edx\n" /* line 2041 | item */
        "cmpl (%edi), %edx\n" /* listPtr */
        "jl .Lf16b224_0016b691\n"
        ".Lf16b224_0016b4d8:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2043 | viewmax */
        "addl (%edi), %eax\n" /* listPtr */
        "cmpl %eax, 0x2dc(%esi)\n" /* item */
        "jge .Lf16b224_0016b6a8\n"
        ".Lf16b224_0016b4e9:\n"
        "movl %edx, 4(%esp)\n" /* line 2045 */
        "movl 0x2d8(%esi), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll UI_FeederSelection\n"
        "movl $1, %eax\n"
        "jmp .Lf16b224_0016b458\n"
        ".Lf16b224_0016b505:\n"
        "movl 0x108(%edi), %eax\n" /* line 1968 | listPtr */
        "testl %eax, %eax\n"
        "jne .Lf16b224_0016b54e\n"
        "movl 0x24(%edi), %eax\n" /* line 1970 | listPtr */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl 0x24(%edi), %eax\n" /* line 1971 | listPtr */
        "testl %eax, %eax\n"
        "js .Lf16b224_0016b9aa\n"
        ".Lf16b224_0016b52c:\n"
        "movl 0x24(%edi), %edx\n" /* line 1975 | listPtr */
        "cmpl (%edi), %edx\n" /* listPtr */
        "jl .Lf16b224_0016b91a\n"
        ".Lf16b224_0016b537:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1979 | viewmax */
        "addl (%edi), %eax\n" /* listPtr */
        "cmpl %eax, 0x24(%edi)\n" /* listPtr */
        "jge .Lf16b224_0016b6c5\n"
        "movl %edx, 4(%esp)\n" /* line 1983 */
        "jmp .Lf16b224_0016b39f\n"
        ".Lf16b224_0016b54e:\n"
        "movl (%edi), %eax\n" /* line 2092 | listPtr */
        "subl $1, %eax\n"
        ".Lf16b224_0016b553:\n"
        "movl %eax, 4(%esp)\n" /* line 2224 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl (%edi), %esi\n" /* line 2225 | listPtr, item */
        "testl %esi, %esi\n" /* item */
        "js .Lf16b224_0016b677\n"
        ".Lf16b224_0016b569:\n"
        "movl $1, %eax\n" /* line 2262 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 2269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16b224_0016b576:\n"
        "movl 0x108(%edi), %ecx\n" /* line 2061 | listPtr */
        "testl %ecx, %ecx\n"
        "jne .Lf16b224_0016b5ee\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2063 | item */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2064 | item */
        "cmpl (%edi), %eax\n" /* listPtr */
        "jl .Lf16b224_0016b942\n"
        ".Lf16b224_0016b5a3:\n"
        "movl -0x44(%ebp), %eax\n" /* line 2066 | count */
        "cmpl 0x2dc(%esi), %eax\n" /* item */
        "jle .Lf16b224_0016b92e\n"
        ".Lf16b224_0016b5b2:\n"
        "movl 0x2dc(%esi), %edx\n" /* line 2068 | item */
        "testl %edx, %edx\n"
        "js .Lf16b224_0016ba12\n"
        ".Lf16b224_0016b5c0:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2070 | viewmax */
        "addl (%edi), %eax\n" /* listPtr */
        "cmpl %eax, 0x2dc(%esi)\n" /* item */
        "jl .Lf16b224_0016b3a7\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2071 | item */
        "subl -0x3c(%ebp), %eax\n" /* viewmax */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b3a7\n"
        ".Lf16b224_0016b5ee:\n"
        "movl (%edi), %eax\n" /* line 2101 | listPtr */
        "addl $1, %eax\n"
        ".Lf16b224_0016b5f3:\n"
        "movl %eax, 4(%esp)\n" /* line 2259 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl -0x40(%ebp), %eax\n" /* line 2260 | max */
        "cmpl (%edi), %eax\n" /* listPtr */
        "jge .Lf16b224_0016b569\n"
        "movl %eax, 4(%esp)\n" /* line 2262 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl $1, %eax\n"
        "jmp .Lf16b224_0016b458\n"
        ".Lf16b224_0016b620:\n"
        "movl 0x108(%edi), %ebx\n" /* line 2235 | listPtr, flags */
        "testl %ebx, %ebx\n" /* flags */
        "jne .Lf16b224_0016b8da\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2237 | viewmax */
        "addl 0x24(%edi), %eax\n" /* listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl 0x24(%edi), %eax\n" /* line 2238 | listPtr */
        "cmpl (%edi), %eax\n" /* listPtr */
        "jl .Lf16b224_0016b9d3\n"
        ".Lf16b224_0016b64b:\n"
        "movl -0x44(%ebp), %eax\n" /* line 2242 | count */
        "cmpl 0x24(%edi), %eax\n" /* listPtr */
        "jle .Lf16b224_0016b9bf\n"
        ".Lf16b224_0016b657:\n"
        "movl 0x24(%edi), %ecx\n" /* line 2246 | listPtr */
        "testl %ecx, %ecx\n"
        "jns .Lf16b224_0016b38a\n"
        "movl $0, 4(%esp)\n" /* line 2248 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16b224_0016b38a\n"
        ".Lf16b224_0016b677:\n"
        "movl $0, 4(%esp)\n" /* line 2227 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl $1, %eax\n"
        "jmp .Lf16b224_0016b458\n"
        ".Lf16b224_0016b691:\n"
        "movl %edx, 4(%esp)\n" /* line 2042 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl 0x2dc(%esi), %edx\n" /* item */
        "jmp .Lf16b224_0016b4d8\n"
        ".Lf16b224_0016b6a8:\n"
        "subl -0x3c(%ebp), %edx\n" /* line 2044 | viewmax */
        "leal 1(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl 0x2dc(%esi), %edx\n" /* item */
        "jmp .Lf16b224_0016b4e9\n"
        ".Lf16b224_0016b6c5:\n"
        "subl -0x3c(%ebp), %edx\n" /* line 1981 | viewmax */
        "leal 1(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl 0x24(%edi), %edx\n" /* listPtr */
        "movl %edx, 4(%esp)\n" /* line 1983 */
        "jmp .Lf16b224_0016b39f\n"
        ".Lf16b224_0016b6e3:\n"
        "movl 0x108(%edi), %eax\n" /* line 2170 | listPtr */
        "testl %eax, %eax\n"
        "jne .Lf16b224_0016b677\n"
        "movl $0, 4(%esp)\n" /* line 2172 */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "movl $0, 4(%esp)\n" /* line 2173 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl $0, 4(%esp)\n" /* line 2174 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b3a7\n"
        ".Lf16b224_0016b722:\n"
        "testb $1, %bh\n" /* line 2090 | flags */
        "jne .Lf16b224_0016b54e\n"
        "testb $2, %bh\n" /* line 2098 | flags */
        "jne .Lf16b224_0016b5ee\n"
        "testb $8, %bh\n" /* line 2107 | flags */
        "jne .Lf16b224_0016b8d0\n"
        "testb $0x10, %bh\n" /* line 2116 | flags */
        "jne .Lf16b224_0016b8da\n"
        "andb $4, %bh\n" /* line 2125 | flags */
        "jne .Lf16b224_0016b569\n"
        "movss 0x2d8(%esi), %xmm0\n" /* line 2136 | item */
        "ucomiss lit4_002ed6c8, %xmm0\n" /* 18.0f */
        "je .Lf16b224_0016ba27\n"
        ".Lf16b224_0016b764:\n"
        "movl 8(%ebp), %eax\n" /* line 2148 | dc */
        "movl 4(%eax), %edx\n"
        "cmpl lastListBoxClickTime, %edx\n"
        "jge .Lf16b224_0016b78b\n"
        "movl 0x104(%edi), %eax\n" /* listPtr */
        "testl %eax, %eax\n"
        "je .Lf16b224_0016b78b\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2151 | item */
        "cmpl 0x24(%edi), %eax\n" /* listPtr */
        "je .Lf16b224_0016ba7b\n"
        ".Lf16b224_0016b78b:\n"
        "leal 0x12c(%edx), %eax\n" /* line 2154 */
        "movl %eax, lastListBoxClickTime\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2155 | item */
        "cmpl 0x24(%edi), %eax\n" /* listPtr */
        "je .Lf16b224_0016b569\n"
        "testl %eax, %eax\n" /* line 2157 */
        "js .Lf16b224_0016ba67\n"
        ".Lf16b224_0016b7ad:\n"
        "movl 0x24(%edi), %ebx\n" /* line 113 */
        "movl 0x2d8(%esi), %eax\n" /* line 2159 | item */
        "movl %eax, (%esp)\n"
        "calll UI_FeederCount\n"
        "cmpl %eax, %ebx\n" /* flags */
        "jge .Lf16b224_0016b3a7\n"
        "movl 0x24(%edi), %eax\n" /* line 2160 | listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "jmp .Lf16b224_0016b3a7\n"
        ".Lf16b224_0016b7da:\n"
        "movl 0x108(%edi), %eax\n" /* line 2184 | listPtr */
        "testl %eax, %eax\n"
        "jne .Lf16b224_0016b8e7\n"
        "movl -0x44(%ebp), %ebx\n" /* line 2186 | count, flags */
        "subl $1, %ebx\n" /* flags */
        "movl %ebx, 4(%esp)\n" /* flags */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "movl %ebx, 4(%esp)\n" /* line 2187 | flags */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2188 | viewmax */
        "addl (%edi), %eax\n" /* listPtr */
        "cmpl %eax, 0x2dc(%esi)\n" /* item */
        "jge .Lf16b224_0016b98d\n"
        ".Lf16b224_0016b817:\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2190 | item */
        "testl %eax, %eax\n"
        "jns .Lf16b224_0016b3a7\n"
        "movl $0, 4(%esp)\n" /* line 2192 */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "movl $0, 4(%esp)\n" /* line 2193 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16b224_0016b3a7\n"
        ".Lf16b224_0016b84a:\n"
        "movl (%edi), %eax\n" /* line 2020 | listPtr */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl -0x44(%ebp), %eax\n" /* line 2021 | count */
        "cmpl (%edi), %eax\n" /* listPtr */
        "jg .Lf16b224_0016b569\n"
        "subl $1, %eax\n" /* line 2022 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl $1, %eax\n"
        "jmp .Lf16b224_0016b458\n"
        ".Lf16b224_0016b87f:\n"
        "movl 0x108(%edi), %eax\n" /* line 2204 | listPtr */
        "testl %eax, %eax\n"
        "jne .Lf16b224_0016b8d0\n"
        "movl 0x24(%edi), %eax\n" /* line 2206 | listPtr */
        "subl -0x3c(%ebp), %eax\n" /* viewmax */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "movl 0x24(%edi), %eax\n" /* line 2207 | listPtr */
        "testl %eax, %eax\n"
        "js .Lf16b224_0016ba52\n"
        ".Lf16b224_0016b8a6:\n"
        "movl 0x24(%edi), %edx\n" /* line 2211 | listPtr */
        "cmpl (%edi), %edx\n" /* listPtr */
        "jl .Lf16b224_0016b9fe\n"
        ".Lf16b224_0016b8b1:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2215 | viewmax */
        "addl (%edi), %eax\n" /* listPtr */
        "cmpl %eax, 0x24(%edi)\n" /* listPtr */
        "jge .Lf16b224_0016b9e4\n"
        ".Lf16b224_0016b8bf:\n"
        "movl %edx, 4(%esp)\n" /* line 2219 */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "jmp .Lf16b224_0016b3a7\n"
        ".Lf16b224_0016b8d0:\n"
        "movl (%edi), %eax\n" /* line 2224 | listPtr */
        "subl -0x3c(%ebp), %eax\n" /* viewmax */
        "jmp .Lf16b224_0016b553\n"
        ".Lf16b224_0016b8da:\n"
        "movl (%edi), %eax\n" /* line 2259 | listPtr */
        "addl %eax, -0x3c(%ebp)\n" /* viewmax */
        "movl -0x3c(%ebp), %eax\n" /* viewmax */
        "jmp .Lf16b224_0016b5f3\n"
        ".Lf16b224_0016b8e7:\n"
        "movl -0x40(%ebp), %eax\n" /* line 2198 | max */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl $1, %eax\n"
        "jmp .Lf16b224_0016b458\n"
        ".Lf16b224_0016b900:\n"
        "movl 0x24(%edi), %eax\n" /* line 2013 | listPtr */
        "subl -0x3c(%ebp), %eax\n" /* viewmax */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b398\n"
        ".Lf16b224_0016b91a:\n"
        "movl %edx, 4(%esp)\n" /* line 1977 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl 0x24(%edi), %edx\n" /* listPtr */
        "jmp .Lf16b224_0016b537\n"
        ".Lf16b224_0016b92e:\n"
        "subl $1, %eax\n" /* line 2067 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "jmp .Lf16b224_0016b5b2\n"
        ".Lf16b224_0016b942:\n"
        "movl %eax, 4(%esp)\n" /* line 2065 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b5a3\n"
        ".Lf16b224_0016b953:\n"
        "subl $1, %eax\n" /* line 2009 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16b224_0016b38a\n"
        ".Lf16b224_0016b967:\n"
        "movl %eax, 4(%esp)\n" /* line 2005 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b37e\n"
        ".Lf16b224_0016b978:\n"
        "movl $0, 4(%esp)\n" /* line 2040 */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "jmp .Lf16b224_0016b4ca\n"
        ".Lf16b224_0016b98d:\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2189 | item */
        "subl -0x3c(%ebp), %eax\n" /* viewmax */
        "addl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b817\n"
        ".Lf16b224_0016b9aa:\n"
        "movl $0, 4(%esp)\n" /* line 1973 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16b224_0016b52c\n"
        ".Lf16b224_0016b9bf:\n"
        "subl $1, %eax\n" /* line 2244 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16b224_0016b657\n"
        ".Lf16b224_0016b9d3:\n"
        "movl %eax, 4(%esp)\n" /* line 2240 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "jmp .Lf16b224_0016b64b\n"
        ".Lf16b224_0016b9e4:\n"
        "subl -0x3c(%ebp), %edx\n" /* line 2217 | viewmax */
        "leal 1(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl 0x24(%edi), %edx\n" /* listPtr */
        "jmp .Lf16b224_0016b8bf\n"
        ".Lf16b224_0016b9fe:\n"
        "movl %edx, 4(%esp)\n" /* line 2213 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "movl 0x24(%edi), %edx\n" /* listPtr */
        "jmp .Lf16b224_0016b8b1\n"
        ".Lf16b224_0016ba12:\n"
        "movl $0, 4(%esp)\n" /* line 2069 */
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "jmp .Lf16b224_0016b5c0\n"
        ".Lf16b224_0016ba27:\n"
        "jp .Lf16b224_0016b764\n" /* line 2136 */
        "movl %esi, (%esp)\n" /* line 2138 | item */
        "calll UI_OverrideCursorPos\n"
        "movl 0x2dc(%esi), %eax\n" /* line 2139 | item */
        "movl %eax, 4(%esp)\n"
        "movl 0x2d8(%esi), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll UI_FeederSelection\n"
        "jmp .Lf16b224_0016b764\n"
        ".Lf16b224_0016ba52:\n"
        "movl $0, 4(%esp)\n" /* line 2209 */
        "movl %edi, (%esp)\n" /* listPtr */
        "calll ListBox_SetCursorPos\n"
        "jmp .Lf16b224_0016b8a6\n"
        ".Lf16b224_0016ba67:\n"
        "movl 0x24(%edi), %eax\n" /* line 2158 | listPtr */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* item */
        "calll Item_SetCursorPos\n"
        "jmp .Lf16b224_0016b7ad\n"
        ".Lf16b224_0016ba7b:\n"
        "movl %edi, (%esp)\n" /* line 2151 | listPtr */
        "calll ListBox_HasValidCursorPos\n"
        "testb %al, %al\n"
        "jne .Lf16b224_0016ba92\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl 4(%eax), %edx\n"
        "jmp .Lf16b224_0016b78b\n"
        ".Lf16b224_0016ba92:\n"
        "movl 0x104(%edi), %eax\n" /* line 2152 | listPtr */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl 4(%eax), %edx\n"
        "jmp .Lf16b224_0016b78b\n"
    );
}

/* line 2826 */
static __attribute__((naked))
void Scroll_ListBox_ThumbFunc(displayContextDef_t *dc, void *p)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2826 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* dc */
        "movl 0xc(%ebp), %ebx\n" /* p */
        /* { scope 1 */
        "movl 0x18(%ebx), %eax\n" /* line 2836 | p */
        "movl %eax, (%esp)\n"
        "calll Item_GetListBoxDef\n"
        "movl %eax, %esi\n" /* listPtr */
        "testl %eax, %eax\n" /* line 2838 */
        "je .Lf16bab8_0016bb1f\n"
        "movl 0x18(%ebx), %eax\n" /* line 2841 | p */
        "testb $0x20, 0xe6(%eax)\n"
        "jne .Lf16bab8_0016bb27\n"
        "cvtsi2ssl 0x10(%edi), %xmm0\n" /* line 2866 | dc */
        "ucomiss 0x14(%ebx), %xmm0\n" /* p */
        "jp .Lf16bab8_0016bc02\n"
        "jne .Lf16bab8_0016bc02\n"
        ".Lf16bab8_0016baf9:\n"
        "movl 4(%edi), %eax\n" /* line 2888 | dc */
        "cmpl (%ebx), %eax\n" /* p */
        "jg .Lf16bab8_0016bbcc\n"
        ".Lf16bab8_0016bb04:\n"
        "cmpl 4(%ebx), %eax\n" /* line 2897 | p */
        "jle .Lf16bab8_0016bb1f\n"
        "addl $0x96, %eax\n" /* line 2899 */
        "movl %eax, 4(%ebx)\n" /* p */
        "movl 8(%ebx), %eax\n" /* line 2900 | p */
        "cmpl $0x14, %eax\n"
        "jle .Lf16bab8_0016bb1f\n"
        "subl $0x28, %eax\n" /* line 2902 */
        "movl %eax, 8(%ebx)\n" /* p */
        /* } scope */
        ".Lf16bab8_0016bb1f:\n"
        "addl $0x4c, %esp\n" /* line 2905 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16bab8_0016bb27:\n"
        "cvtsi2ssl 0xc(%edi), %xmm0\n" /* line 2843 | dc */
        "ucomiss 0x10(%ebx), %xmm0\n" /* p */
        "jp .Lf16bab8_0016bb34\n"
        "je .Lf16bab8_0016bb1f\n"
        ".Lf16bab8_0016bb34:\n"
        "movss lit4_002ed6a8, %xmm0\n" /* line 2848 | 16.0f */
        "addss (%eax), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x1c(%ebp)\n"
        "movss 8(%eax), %xmm1\n" /* line 2851 */
        "subss lit4_002ed830, %xmm1\n" /* 32.0f */
        "subss lit4_002ed62c, %xmm1\n" /* 2.0f */
        "movl %eax, (%esp)\n" /* line 2852 */
        "movss %xmm1, -0x38(%ebp)\n"
        "calll Item_ListBox_MaxScroll\n"
        "cvtsi2ssl 0xc(%edi), %xmm0\n" /* line 2854 | dc */
        "subss -0x1c(%ebp), %xmm0\n"
        "subss lit4_002ed740, %xmm0\n" /* 8.0f */
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "movss -0x38(%ebp), %xmm1\n"
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "divss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "testl %edx, %edx\n" /* line 2855 */
        "js .Lf16bab8_0016bc91\n"
        "cmpl %edx, %eax\n" /* line 2859 */
        "cmovll %eax, %edx\n"
        ".Lf16bab8_0016bbab:\n"
        "movl %edx, 4(%esp)\n" /* line 2863 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "cvtsi2ssl 0xc(%edi), %xmm0\n" /* line 2864 | dc */
        "movss %xmm0, 0x10(%ebx)\n" /* p */
        "movl 4(%edi), %eax\n" /* line 2888 | dc */
        "cmpl (%ebx), %eax\n" /* p */
        "jle .Lf16bab8_0016bb04\n"
        ".Lf16bab8_0016bbcc:\n"
        "movl $0, 0x10(%esp)\n" /* line 2893 */
        "movl $1, 0xc(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* p */
        "movl %eax, 8(%esp)\n"
        "movl 0x18(%ebx), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* dc */
        "calll Item_ListBox_HandleKey\n"
        "movl 4(%edi), %eax\n" /* line 2894 | dc */
        "addl 8(%ebx), %eax\n" /* p */
        "movl %eax, (%ebx)\n" /* p */
        "movl 4(%edi), %eax\n" /* dc */
        "jmp .Lf16bab8_0016bb04\n"
        ".Lf16bab8_0016bc02:\n"
        "movss lit4_002ed6a8, %xmm0\n" /* line 2870 | 16.0f */
        "addss 4(%eax), %xmm0\n"
        "addss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 0xc(%eax), %xmm1\n" /* line 2871 */
        "subss lit4_002ed830, %xmm1\n" /* 32.0f */
        "subss lit4_002ed62c, %xmm1\n" /* 2.0f */
        "movl %eax, (%esp)\n" /* line 2873 */
        "movss %xmm1, -0x38(%ebp)\n"
        "calll Item_ListBox_MaxScroll\n"
        "cvtsi2ssl 0x10(%edi), %xmm0\n" /* line 2875 | dc */
        "subss -0x20(%ebp), %xmm0\n"
        "subss lit4_002ed740, %xmm0\n" /* 8.0f */
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss %xmm2, %xmm0\n"
        "movss -0x38(%ebp), %xmm1\n"
        "subss lit4_002ed6a8, %xmm1\n" /* 16.0f */
        "divss %xmm1, %xmm0\n"
        "cvttss2si %xmm0, %edx\n"
        "testl %edx, %edx\n" /* line 2876 */
        "js .Lf16bab8_0016bc98\n"
        "cmpl %edx, %eax\n" /* line 2880 */
        "cmovll %eax, %edx\n"
        ".Lf16bab8_0016bc76:\n"
        "movl %edx, 4(%esp)\n" /* line 2884 */
        "movl %esi, (%esp)\n" /* listPtr */
        "calll ListBox_SetStartPos\n"
        "cvtsi2ssl 0x10(%edi), %xmm0\n" /* line 2885 | dc */
        "movss %xmm0, 0x14(%ebx)\n" /* p */
        "jmp .Lf16bab8_0016baf9\n"
        ".Lf16bab8_0016bc91:\n"
        "xorl %edx, %edx\n" /* line 2855 */
        "jmp .Lf16bab8_0016bbab\n"
        ".Lf16bab8_0016bc98:\n"
        "xorl %edx, %edx\n" /* line 2876 */
        "jmp .Lf16bab8_0016bc76\n"
    );
}

/* Scroll_ListBox_AutoFunc — auto-scroll list box: handle key repeat, adjust timing */
static void Scroll_ListBox_AutoFunc(displayContextDef_t *dc, void *p)
{
    byte *d = (byte *)dc;
    byte *scroll = (byte *)p;
    int curTime = *(int *)(d + 4);

    /* If past next scroll time, handle key and advance */
    while (curTime > *(int *)scroll) {
        Item_ListBox_HandleKey(dc, *(void **)(scroll + 0x18), *(int *)(scroll + 0xc), 1, 0);
        *(int *)scroll = curTime + *(int *)(scroll + 8);
    }

    /* Adjust next scroll time if past hold time */
    if (curTime > *(int *)(scroll + 4)) {
        *(int *)(scroll + 4) = curTime + 150;
        if (*(int *)(scroll + 8) > 20)
            *(int *)(scroll + 8) -= 40;
    }
}

/* line 4728 */
__attribute__((naked))
qboolean Item_Bind_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4728 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x10(%ebp), %esi\n" /* key */
        /* { scope 1: name */
        "movl g_waitingForKey, %edi\n" /* line 4733 | id */
        "testl %edi, %edi\n" /* id */
        "jne .Lf16bd06_0016bd42\n"
        "movl 0x14(%ebp), %ebx\n" /* line 4735 | down */
        "testl %ebx, %ebx\n"
        "je .Lf16bd06_0016bd38\n"
        "cmpl $0xd, %esi\n" /* key */
        "je .Lf16bd06_0016bfa3\n"
        "cmpl $0xc8, %esi\n" /* key */
        "je .Lf16bd06_0016bed9\n"
        ".Lf16bd06_0016bd38:\n"
        "xorl %eax, %eax\n" /* line 4833 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 4834 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf16bd06_0016bd42:\n"
        "movl g_bindItem, %ecx\n" /* line 4744 */
        "testl %ecx, %ecx\n"
        "je .Lf16bd06_0016bd38\n"
        "testl $0x400, %esi\n" /* line 4747 | key */
        "jne .Lf16bd06_0016becc\n"
        "cmpl $0x60, %esi\n" /* line 4750 | key */
        "je .Lf16bd06_0016becc\n"
        "cmpl $0x7f, %esi\n" /* key */
        "je .Lf16bd06_0016bfc2\n"
        "cmpl $0x1b, %esi\n" /* key */
        "je .Lf16bd06_0016beb5\n"
        "cmpl $-1, %esi\n" /* line 4778 | key */
        "je .Lf16bd06_0016bdb8\n"
        ".Lf16bd06_0016bd78:\n"
        "movl $g_bindings, %edx\n"
        "jmp .Lf16bd06_0016bd8f\n"
        ".Lf16bd06_0016bd7f:\n"
        "cmpl %esi, 0xc(%edx)\n" /* line 4785 | key */
        "je .Lf16bd06_0016bda0\n"
        ".Lf16bd06_0016bd84:\n"
        "addl $0x14, %edx\n" /* line 4788 */
        "cmpl $updateScreenCalled, %edx\n" /* line 4780 */
        "je .Lf16bd06_0016bdb8\n"
        ".Lf16bd06_0016bd8f:\n"
        "cmpl %esi, 0x10(%edx)\n" /* line 4782 | key */
        "jne .Lf16bd06_0016bd7f\n"
        "movl $0xffffffff, 0x10(%edx)\n" /* line 4783 */
        "cmpl %esi, 0xc(%edx)\n" /* line 4785 | key */
        "jne .Lf16bd06_0016bd84\n"
        ".Lf16bd06_0016bda0:\n"
        "movl 0x10(%edx), %eax\n" /* line 4787 */
        "movl %eax, 0xc(%edx)\n"
        "movl $0xffffffff, 0x10(%edx)\n" /* line 4788 */
        "addl $0x14, %edx\n"
        "cmpl $updateScreenCalled, %edx\n" /* line 4780 */
        "jne .Lf16bd06_0016bd8f\n"
        ".Lf16bd06_0016bdb8:\n"
        "movl 0xc(%ebp), %eax\n" /* line 4793 | item */
        "movl 0x2c0(%eax), %eax\n"
        "movl %eax, -0x3c(%ebp)\n" /* name */
        "xorl %edi, %edi\n" /* name */
        "movl $g_bindings, %ebx\n"
        "movl %eax, %edx\n"
        "jmp .Lf16bd06_0016bde1\n"
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16bd06_0016bdcf:\n"
        "addl $1, %edi\n" /* line 4406 */
        "addl $0x14, %ebx\n"
        "cmpl $0x38, %edi\n"
        "je .Lf16bd06_0016be63\n"
        "movl -0x3c(%ebp), %edx\n" /* name */
        ".Lf16bd06_0016bde1:\n"
        "movl (%ebx), %eax\n" /* line 4408 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf16bd06_0016bdcf\n"
        /* } scope */
        "cmpl $-1, %edi\n" /* line 4795 | name */
        "je .Lf16bd06_0016be63\n"
        "cmpl $-1, %esi\n" /* line 4797 | key */
        "je .Lf16bd06_0016c015\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 4810 | name */
        "shll $2, %eax\n"
        "movl g_bindings+12(%eax), %edx\n"
        "cmpl $-1, %edx\n"
        "je .Lf16bd06_0016c000\n"
        "cmpl %esi, %edx\n" /* line 4814 | key */
        "je .Lf16bd06_0016be27\n"
        "cmpl $-1, g_bindings+16(%eax)\n"
        "je .Lf16bd06_0016c072\n"
        ".Lf16bd06_0016be27:\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 4820 */
        "movl %edx, (%esp)\n"
        "calll Key_SetBinding\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 4821 */
        "leal (%edi, %edi, 4), %ebx\n" /* name */
        "shll $2, %ebx\n"
        "movl g_bindings+16(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetBinding\n"
        "movl %esi, g_bindings+12(%ebx)\n" /* line 4822 | key */
        "movl $0xffffffff, g_bindings+16(%ebx)\n" /* line 4823 */
        ".Lf16bd06_0016be63:\n"
        "movl $g_bindings+12, %ebx\n"
        "movl $szShotName+8, %esi\n" /* key */
        ".Lf16bd06_0016be6d:\n"
        "movl (%ebx), %edx\n" /* line 4357 */
        "cmpl $-1, %edx\n"
        "je .Lf16bd06_0016be9a\n"
        "movl -0xc(%ebx), %eax\n" /* line 4359 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Key_SetBinding\n"
        "movl 4(%ebx), %edx\n" /* line 4361 */
        "cmpl $-1, %edx\n"
        "je .Lf16bd06_0016be9a\n"
        "movl -0xc(%ebx), %eax\n" /* line 4362 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Key_SetBinding\n"
        ".Lf16bd06_0016be9a:\n"
        "addl $0x14, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 4355 */
        "jne .Lf16bd06_0016be6d\n"
        "movl $str_002ac244, 4(%esp)\n" /* line 4371 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        ".Lf16bd06_0016beb5:\n"
        "movl $0, g_waitingForKey\n" /* line 4832 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 4834 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf16bd06_0016becc:\n"
        "movl $1, %eax\n" /* line 4833 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 4834 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf16bd06_0016bed9:\n"
        "movl 8(%ebp), %eax\n" /* line 2274 | dc */
        "cvtsi2ssl 0x10(%eax), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%eax), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl 0xc(%ebp), %edx\n" /* line 417 | item */
        "movl (%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%edx), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* line 422 | compareX */
        "movss %xmm1, -0x20(%ebp)\n" /* line 423 | compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0xc(%ebp), %edx\n" /* line 428 | item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16bd06_0016bd38\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16bd06_0016bd38\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16bd06_0016bd38\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16bd06_0016bd38\n"
        /* } scope */
        /* } scope */
        ".Lf16bd06_0016bfa3:\n"
        "movl $1, g_waitingForKey\n" /* line 4737 */
        "movl 0xc(%ebp), %eax\n" /* line 4738 | item */
        "movl %eax, g_bindItem\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 4834 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: name */
        ".Lf16bd06_0016bfc2:\n"
        "movl 0xc(%ebp), %edx\n" /* line 4757 | item */
        "movl 0x2c0(%edx), %edi\n" /* name */
        "xorl %esi, %esi\n" /* key */
        "movl $g_bindings, %ebx\n"
        "jmp .Lf16bd06_0016bfdf\n"
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16bd06_0016bfd4:\n"
        "addl $1, %esi\n" /* line 4406 */
        "addl $0x14, %ebx\n"
        "cmpl $0x38, %esi\n"
        "je .Lf16bd06_0016c00b\n"
        ".Lf16bd06_0016bfdf:\n"
        "movl (%ebx), %eax\n" /* line 4408 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf16bd06_0016bfd4\n"
        /* } scope */
        "addl $1, %esi\n" /* line 4758 | key */
        "je .Lf16bd06_0016c00b\n"
        "movl $0xffffffff, %esi\n" /* key */
        "jmp .Lf16bd06_0016bdb8\n"
        ".Lf16bd06_0016c000:\n"
        "movl %esi, g_bindings+12(%eax)\n" /* line 4812 | key */
        "jmp .Lf16bd06_0016be63\n"
        ".Lf16bd06_0016c00b:\n"
        "movl $0x7f, %esi\n" /* line 4778 | key */
        "jmp .Lf16bd06_0016bd78\n"
        ".Lf16bd06_0016c015:\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 4799 | name */
        "leal (, %eax, 4), %ebx\n"
        "movl g_bindings+12(%ebx), %eax\n"
        "cmpl $-1, %eax\n"
        "je .Lf16bd06_0016c044\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 4801 */
        "movl %eax, (%esp)\n"
        "calll Key_SetBinding\n"
        "movl $0xffffffff, g_bindings+12(%ebx)\n" /* line 4802 */
        ".Lf16bd06_0016c044:\n"
        "movl g_bindings+16(%ebx), %eax\n" /* line 4804 */
        "cmpl $-1, %eax\n"
        "je .Lf16bd06_0016be63\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 4806 */
        "movl %eax, (%esp)\n"
        "calll Key_SetBinding\n"
        "movl $0xffffffff, g_bindings+16(%ebx)\n" /* line 4807 */
        "jmp .Lf16bd06_0016be63\n"
        ".Lf16bd06_0016c072:\n"
        "movl %esi, g_bindings+16(%eax)\n" /* line 4816 | key */
        "jmp .Lf16bd06_0016be63\n"
    );
}

/* line 3069 */
__attribute__((naked))
qboolean Item_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3069 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* item */
        "movl 0x14(%ebp), %edi\n" /* down */
        "movl itemCapture, %eax\n" /* line 3071 */
        "testl %eax, %eax\n"
        "je .Lf16c07e_0016c0dd\n"
        "movl $0, itemCapture\n" /* line 3074 */
        "movl $0, captureFunc\n" /* line 3075 */
        "movl $0, captureData\n" /* line 3076 */
        ".Lf16c07e_0016c0b7:\n"
        "testl %edi, %edi\n" /* line 3084 | down */
        "je .Lf16c07e_0016c0c9\n"
        ".Lf16c07e_0016c0bb:\n"
        "movl 0x270(%esi), %eax\n" /* line 3087 | item */
        "subl $6, %eax\n"
        "cmpl $8, %eax\n"
        "jbe .Lf16c07e_0016c0d6\n"
        ".Lf16c07e_0016c0c9:\n"
        "xorl %eax, %eax\n" /* line 3116 */
        ".Lf16c07e_0016c0cb:\n"
        "addl $0x8c, %esp\n" /* line 3120 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf16c07e_0016c0d6:\n"
        "jmpl *.Ljt_16c07e_0(, %eax, 4)\n" /* line 3087 */
        ".Lf16c07e_0016c0dd:\n"
        "testl %edi, %edi\n" /* line 3080 | down */
        "je .Lf16c07e_0016c0c9\n"
        "movl 0x10(%ebp), %eax\n" /* key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf16c07e_0016c0bb\n"
        /* { scope 1: y, x, enumString, string */
        "movl 0x270(%esi), %eax\n" /* line 2967 */
        "cmpl $6, %eax\n"
        "je .Lf16c07e_0016c4c6\n"
        "cmpl $0xa, %eax\n"
        "jne .Lf16c07e_0016c0b7\n"
        "movl 8(%ebp), %ecx\n" /* line 3004 | dc */
        "cvtsi2ssl 0x10(%ecx), %xmm0\n"
        "movss %xmm0, -0x5c(%ebp)\n" /* y */
        "cvtsi2ssl 0xc(%ecx), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n" /* x */
        "movl %esi, (%esp)\n" /* line 1644 */
        "calll Item_Slider_ThumbPosition\n"
        "fstps -0x6c(%ebp)\n"
        "movss -0x6c(%ebp), %xmm0\n"
        "movss 4(%esi), %xmm1\n" /* line 1645 */
        "subss lit4_002ed62c, %xmm1\n" /* 2.0f */
        "movl 0x10(%esi), %eax\n" /* line 1648 */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x14(%esi), %ebx\n" /* line 1649 */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "subss lit4_002ed6d4, %xmm0\n" /* line 417 | 5.0f */
        "movss %xmm0, -0x38(%ebp)\n" /* compareRect */
        "movss %xmm1, -0x34(%ebp)\n" /* line 418 */
        "movl $0x41200000, -0x30(%ebp)\n" /* line 419 */
        "movl $0x41a00000, -0x2c(%ebp)\n" /* line 420 */
        "movss -0x58(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movss -0x5c(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl %ebx, 0x14(%esp)\n" /* line 428 */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c07e_0016c627\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c07e_0016c627\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c07e_0016c627\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c07e_0016c627\n"
        "movl $0x400, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf16c07e_0016c20b:\n"
        "testl %eax, %eax\n" /* line 3005 */
        "je .Lf16c07e_0016c0bb\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3007 | key */
        "movl %ecx, scrollInfo+12\n"
        "movl %esi, scrollInfo+24\n" /* line 3008 */
        "movl 8(%ebp), %eax\n" /* line 3009 | dc */
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "movss %xmm0, scrollInfo+16\n"
        "cvtsi2ssl 0x10(%eax), %xmm0\n" /* line 3010 */
        "movss %xmm0, scrollInfo+20\n"
        "movl $scrollInfo, captureData\n" /* line 3011 */
        "movl $Scroll_Slider_ThumbFunc, captureFunc\n" /* line 3012 */
        "movl %esi, itemCapture\n" /* line 3013 */
        "jmp .Lf16c07e_0016c0bb\n"
        /* } scope */
        ".Lf16c07e_0016c25e:\n"
        "movl %edi, 0xc(%esp)\n" /* line 3114 | down */
        "movl 0x10(%ebp), %ecx\n" /* key */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_Bind_HandleKey\n"
        "jmp .Lf16c07e_0016c0cb\n"
        ".Lf16c07e_0016c27d:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3106 | key */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_YesNo_HandleKey\n"
        "jmp .Lf16c07e_0016c0cb\n"
        ".Lf16c07e_0016c298:\n"
        "movl %edi, 0xc(%esp)\n" /* line 3116 | down */
        "movl 0x10(%ebp), %ecx\n" /* key */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_Slider_HandleKey\n"
        "jmp .Lf16c07e_0016c0cb\n"
        ".Lf16c07e_0016c2b7:\n"
        "movl 0x10(%ebp), %eax\n" /* line 1924 | key */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x2d8(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xdc(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xd8(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_OwnerDrawHandleKey\n"
        "jmp .Lf16c07e_0016c0cb\n"
        ".Lf16c07e_0016c2e5:\n"
        "movl $0, 0x10(%esp)\n" /* line 3104 */
        "movl %edi, 0xc(%esp)\n" /* down */
        "movl 0x10(%ebp), %ecx\n" /* key */
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* item */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_ListBox_HandleKey\n"
        "jmp .Lf16c07e_0016c0cb\n"
        /* { scope 1: y, x, enumString, string */
        ".Lf16c07e_0016c30c:\n"
        "movl 0xe8(%esi), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf16c07e_0016c0c9\n"
        "testb $2, %al\n" /* line 2280 */
        "je .Lf16c07e_0016c0c9\n"
        "movl 0x10(%ebp), %eax\n" /* line 2283 | key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "jbe .Lf16c07e_0016c682\n"
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c333:\n"
        "movl 0x2ec(%esi), %eax\n" /* line 2410 */
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "movl %eax, %edi\n" /* enumDvar */
        "cmpb $6, 6(%eax)\n" /* line 2411 */
        "je .Lf16c07e_0016c5c8\n"
        ".Lf16c07e_0016c34d:\n"
        "xorl %ebx, %ebx\n" /* line 2419 */
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c34f:\n"
        "movl 0x2ec(%esi), %eax\n" /* line 2331 */
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "cmpb $6, 6(%eax)\n" /* line 2332 */
        "je .Lf16c07e_0016c552\n"
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c367:\n"
        "xorl %edx, %edx\n" /* line 2462 */
        /* } scope */
        ".Lf16c07e_0016c369:\n"
        "cmpl %edx, %ebx\n" /* line 2515 */
        "je .Lf16c07e_0016c0c9\n"
        "movl %edx, 4(%esp)\n" /* line 2518 */
        "movl $str_0021785c, (%esp)\n" /* "%i" */
        "calll va\n"
        "jmp .Lf16c07e_0016c4aa\n"
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        ".Lf16c07e_0016c386:\n"
        "movl %esi, (%esp)\n" /* line 2478 */
        "calll Item_GetMultiDef\n"
        "movl %eax, -0x54(%ebp)\n" /* multiPtr */
        "testl %eax, %eax\n" /* line 2479 */
        "je .Lf16c07e_0016c0c9\n"
        "movl 0xe8(%esi), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf16c07e_0016c0c9\n"
        "testb $2, %al\n" /* line 2280 */
        "je .Lf16c07e_0016c0c9\n"
        "movl 0x10(%ebp), %eax\n" /* line 2283 | key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "jbe .Lf16c07e_0016c762\n"
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c3c0:\n"
        "movl %esi, (%esp)\n" /* line 2345 */
        "calll Item_GetMultiDef\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 2346 */
        "je .Lf16c07e_0016c3fb\n"
        "movl 0x184(%eax), %eax\n" /* line 2349 */
        "testl %eax, %eax\n"
        "je .Lf16c07e_0016c84b\n"
        "movl 0x2c0(%esi), %eax\n" /* line 2351 */
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, -0x48(%ebp)\n" /* string */
        "movl 0x180(%ebx), %edi\n" /* line 2352 */
        "testl %edi, %edi\n"
        "jg .Lf16c07e_0016c8c0\n"
        ".Lf16c07e_0016c3fb:\n"
        "movl $0, -0x3c(%ebp)\n" /* line 2361 */
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c402:\n"
        "movl %esi, (%esp)\n" /* line 2316 */
        "calll Item_GetMultiDef\n"
        "testl %eax, %eax\n" /* line 2317 */
        "je .Lf16c07e_0016c75b\n"
        "movl 0x180(%eax), %edx\n" /* line 2319 */
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        "testl %edx, %edx\n" /* line 2457 */
        "je .Lf16c07e_0016c75b\n"
        "cmpl $0xc8, 0x10(%ebp)\n" /* line 2459 | key */
        "je .Lf16c07e_0016c74b\n"
        "cmpl $0xd, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c74b\n"
        "cmpl $0xca, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c74b\n"
        "cmpl $0xa3, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c74b\n"
        "cmpl $0x9d, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c74b\n"
        "cmpl $0xc9, 0x10(%ebp)\n" /* line 2461 | key */
        "je .Lf16c07e_0016c47d\n"
        "cmpl $0xa4, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c47d\n"
        "cmpl $0x9c, 0x10(%ebp)\n" /* key */
        "jne .Lf16c07e_0016c0c9\n"
        ".Lf16c07e_0016c47d:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 2462 */
        "leal -1(%ecx, %edx), %eax\n"
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        /* } scope */
        ".Lf16c07e_0016c489:\n"
        "cmpl %edx, -0x3c(%ebp)\n" /* line 2488 */
        "je .Lf16c07e_0016c0c9\n"
        "movl -0x54(%ebp), %eax\n" /* line 2491 | multiPtr */
        "movl 0x184(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf16c07e_0016c82b\n"
        "movl 0x80(%eax, %edx, 4), %eax\n" /* line 2492 */
        ".Lf16c07e_0016c4aa:\n"
        "movl %eax, 4(%esp)\n" /* line 2494 */
        "movl 0x2c0(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "movl $1, %eax\n"
        "jmp .Lf16c07e_0016c0cb\n"
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        ".Lf16c07e_0016c4c6:\n"
        "movl 8(%ebp), %eax\n" /* line 2977 | dc */
        "cvtsi2ssl 0x10(%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Item_ListBox_OverLB\n"
        "movl %eax, %edx\n"
        "testb $3, %ah\n" /* line 2978 */
        "je .Lf16c07e_0016c62e\n"
        "movl 8(%ebp), %ecx\n" /* line 2980 | dc */
        "movl 4(%ecx), %eax\n"
        "addl $0x1f4, %eax\n"
        "movl %eax, scrollInfo\n"
        "movl 4(%ecx), %eax\n" /* line 2981 */
        "addl $0x96, %eax\n"
        "movl %eax, scrollInfo+4\n"
        "movl $0x1f4, scrollInfo+8\n" /* line 2982 */
        "movl 0x10(%ebp), %eax\n" /* line 2983 | key */
        "movl %eax, scrollInfo+12\n"
        "shrl $8, %edx\n" /* line 2984 */
        "andl $1, %edx\n"
        "movl %edx, scrollInfo+28\n"
        "movl %esi, scrollInfo+24\n" /* line 2985 */
        "movl $scrollInfo, captureData\n" /* line 2986 */
        "movl $Scroll_ListBox_AutoFunc, captureFunc\n" /* line 2987 */
        "movl %esi, itemCapture\n" /* line 2988 */
        "jmp .Lf16c07e_0016c0bb\n"
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c552:\n"
        "movl 0x14(%eax), %edx\n" /* line 2334 */
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        "testl %edx, %edx\n" /* line 2457 */
        "je .Lf16c07e_0016c367\n"
        "cmpl $0xc8, 0x10(%ebp)\n" /* line 2459 | key */
        "je .Lf16c07e_0016c8b3\n"
        "cmpl $0xd, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c8b3\n"
        "cmpl $0xca, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c8b3\n"
        "cmpl $0xa3, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c8b3\n"
        "cmpl $0x9d, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c8b3\n"
        "cmpl $0xc9, 0x10(%ebp)\n" /* line 2461 | key */
        "je .Lf16c07e_0016c5ba\n"
        "cmpl $0xa4, 0x10(%ebp)\n" /* key */
        "je .Lf16c07e_0016c5ba\n"
        "cmpl $0x9c, 0x10(%ebp)\n" /* key */
        "jne .Lf16c07e_0016c0c9\n"
        ".Lf16c07e_0016c5ba:\n"
        "leal -1(%ebx, %edx), %eax\n" /* line 2462 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "jmp .Lf16c07e_0016c369\n"
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c5c8:\n"
        "movl 0x2c0(%esi), %eax\n" /* line 2414 */
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, -0x44(%ebp)\n" /* enumString */
        "movl %eax, (%esp)\n" /* line 2415 */
        "calll atoi\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 2416 */
        "js .Lf16c07e_0016c5f0\n"
        "cmpl 0x14(%edi), %eax\n" /* enumDvar */
        "jl .Lf16c07e_0016c34f\n"
        ".Lf16c07e_0016c5f0:\n"
        "movl 0x14(%edi), %eax\n" /* line 2419 | enumDvar */
        "testl %eax, %eax\n"
        "jle .Lf16c07e_0016c34d\n"
        "xorl %ebx, %ebx\n"
        ".Lf16c07e_0016c5fd:\n"
        "movl 0x18(%edi), %eax\n" /* line 2421 | enumDvar */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x44(%ebp), %eax\n" /* enumString */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf16c07e_0016c34f\n"
        "addl $1, %ebx\n" /* line 2419 */
        "cmpl 0x14(%edi), %ebx\n" /* enumDvar */
        "jl .Lf16c07e_0016c5fd\n"
        "jmp .Lf16c07e_0016c34d\n"
        /* } scope */
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        ".Lf16c07e_0016c627:\n"
        "xorl %eax, %eax\n" /* line 430 */
        "jmp .Lf16c07e_0016c20b\n"
        /* } scope */
        /* } scope */
        ".Lf16c07e_0016c62e:\n"
        "andb $4, %dh\n" /* line 2990 */
        "je .Lf16c07e_0016c0bb\n"
        "movl 0x10(%ebp), %ecx\n" /* line 2992 | key */
        "movl %ecx, scrollInfo+12\n"
        "movl %esi, scrollInfo+24\n" /* line 2993 */
        "movl 8(%ebp), %eax\n" /* line 2994 | dc */
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "movss %xmm0, scrollInfo+16\n"
        "cvtsi2ssl 0x10(%eax), %xmm0\n" /* line 2995 */
        "movss %xmm0, scrollInfo+20\n"
        "movl $scrollInfo, captureData\n" /* line 2996 */
        "movl $Scroll_ListBox_ThumbFunc, captureFunc\n" /* line 2997 */
        "movl %esi, itemCapture\n" /* line 2998 */
        "jmp .Lf16c07e_0016c0bb\n"
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        ".Lf16c07e_0016c682:\n"
        "movl 8(%ebp), %ecx\n" /* line 2274 | dc */
        "cvtsi2ssl 0x10(%ecx), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%ecx), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%esi), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 422 | compareY */
        "movss %xmm1, -0x1c(%ebp)\n" /* line 423 | compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%esi), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c07e_0016c0c9\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c07e_0016c0c9\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c07e_0016c0c9\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c07e_0016c0c9\n"
        "jmp .Lf16c07e_0016c333\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c74b:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2460 */
        "addl $1, %eax\n"
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "jmp .Lf16c07e_0016c489\n"
        ".Lf16c07e_0016c75b:\n"
        "xorl %edx, %edx\n" /* line 2462 */
        "jmp .Lf16c07e_0016c489\n"
        /* } scope */
        ".Lf16c07e_0016c762:\n"
        "movl 8(%ebp), %ecx\n" /* line 2274 | dc */
        "cvtsi2ssl 0x10(%ecx), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%ecx), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%esi), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 422 | compareY */
        "movss %xmm1, -0x1c(%ebp)\n" /* line 423 | compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%esi), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c07e_0016c0c9\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c07e_0016c0c9\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c07e_0016c0c9\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c07e_0016c0c9\n"
        "jmp .Lf16c07e_0016c3c0\n"
        /* } scope */
        /* } scope */
        ".Lf16c07e_0016c82b:\n"
        "cvtss2sd 0x100(%eax, %edx, 4), %xmm0\n" /* line 2494 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_00217c20, (%esp)\n" /* "%g" */
        "calll va\n"
        "jmp .Lf16c07e_0016c4aa\n"
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c84b:\n"
        "movl 0x2c0(%esi), %eax\n" /* line 2360 */
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x50(%ebp)\n"
        "cvtsd2ss -0x50(%ebp), %xmm1\n"
        "movl 0x180(%ebx), %edx\n" /* line 2361 */
        "testl %edx, %edx\n"
        "jle .Lf16c07e_0016c3fb\n"
        "ucomiss 0x100(%ebx), %xmm1\n" /* line 2363 */
        "jp .Lf16c07e_0016c886\n"
        "je .Lf16c07e_0016c3fb\n"
        ".Lf16c07e_0016c886:\n"
        "movl %ebx, %eax\n"
        "movl $0, -0x3c(%ebp)\n"
        ".Lf16c07e_0016c88f:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 2361 */
        "cmpl -0x3c(%ebp), %edx\n"
        "je .Lf16c07e_0016c3fb\n"
        "movss 0x104(%eax), %xmm0\n" /* line 2363 */
        "addl $4, %eax\n"
        "ucomiss %xmm0, %xmm1\n"
        "jp .Lf16c07e_0016c88f\n"
        "jne .Lf16c07e_0016c88f\n"
        "jmp .Lf16c07e_0016c402\n"
        /* } scope */
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c8b3:\n"
        "leal 1(%ebx), %eax\n" /* line 2460 */
        "movl %edx, %ecx\n"
        "cltd\n"
        "idivl %ecx\n"
        "jmp .Lf16c07e_0016c369\n"
        /* } scope */
        /* } scope */
        /* { scope 1: y, x, enumString, string */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16c07e_0016c8c0:\n"
        "movl %ebx, %edi\n" /* line 2352 */
        "movl $0, -0x3c(%ebp)\n"
        ".Lf16c07e_0016c8c9:\n"
        "movl 0x80(%edi), %eax\n" /* line 2354 */
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf16c07e_0016c402\n"
        "addl $1, -0x3c(%ebp)\n" /* line 2352 */
        "addl $4, %edi\n"
        "movl -0x3c(%ebp), %ecx\n"
        "cmpl %ecx, 0x180(%ebx)\n"
        "jg .Lf16c07e_0016c8c9\n"
        "jmp .Lf16c07e_0016c3fb\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_16c07e_0:\n"
        ".long .Lf16c07e_0016c2e5\n"
        ".long .Lf16c07e_0016c0c9\n"
        ".long .Lf16c07e_0016c2b7\n"
        ".long .Lf16c07e_0016c0c9\n"
        ".long .Lf16c07e_0016c298\n"
        ".long .Lf16c07e_0016c27d\n"
        ".long .Lf16c07e_0016c386\n"
        ".long .Lf16c07e_0016c30c\n"
        ".long .Lf16c07e_0016c25e\n"
        ".text\n"
    );
}

/* line 5487 */
__attribute__((naked))
qboolean Menu_HandleMouseMove(displayContextDef_t *dc, menuDef_t *menu, float x, float y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5487 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1: compareRect, compareX, compareY */
        "movl 0xc(%ebp), %eax\n" /* line 5494 | menu */
        "testl %eax, %eax\n"
        "je .Lf16c8fe_0016c926\n"
        "movl 0xc(%ebp), %eax\n" /* line 5497 | menu */
        "testl $0x4004, 0xe8(%eax)\n"
        "je .Lf16c8fe_0016c926\n"
        "movl itemCapture, %eax\n" /* line 5500 */
        "testl %eax, %eax\n"
        "je .Lf16c8fe_0016c930\n"
        /* { scope 2 */
        ".Lf16c8fe_0016c926:\n"
        "xorl %eax, %eax\n" /* line 386 */
        /* } scope */
        /* } scope */
        ".Lf16c8fe_0016c928:\n"
        "addl $0x6c, %esp\n" /* line 5576 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: compareRect, compareX, compareY */
        ".Lf16c8fe_0016c930:\n"
        "movl g_waitingForKey, %eax\n" /* line 5503 */
        "testl %eax, %eax\n"
        "jne .Lf16c8fe_0016c926\n"
        "movl g_editingField, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf16c8fe_0016c926\n"
        "movl $0, -0x44(%ebp)\n" /* focusSet */
        "movl $0, -0x40(%ebp)\n" /* focusItem */
        "movl $0, -0x48(%ebp)\n" /* pass */
        ".Lf16c8fe_0016c957:\n"
        "movl 0xc(%ebp), %edx\n" /* line 5510 | menu */
        "movl 0x218(%edx), %edx\n"
        "movl %edx, -0x4c(%ebp)\n"
        "movl %edx, %eax\n"
        "subl $1, %eax\n"
        "js .Lf16c8fe_0016cca6\n"
        "leal (, %eax, 4), %esi\n" /* line 5487 | i */
        "movl $0, -0x3c(%ebp)\n"
        ".Lf16c8fe_0016c97c:\n"
        "movl 0xc(%ebp), %edi\n" /* line 5515 | menu */
        "movl 0x27c(%edi), %eax\n"
        "movl (%esi, %eax), %edx\n" /* i */
        "testl $0x4004, 0xe8(%edx)\n"
        "je .Lf16c8fe_0016cc93\n"
        "testb $3, 0x2d0(%edx)\n" /* line 5519 */
        "jne .Lf16c8fe_0016cdf8\n"
        ".Lf16c8fe_0016c9a5:\n"
        "movl (%esi, %eax), %edx\n" /* line 5522 | i */
        "testb $0xc, 0x2d0(%edx)\n"
        "jne .Lf16c8fe_0016ce1b\n"
        "movl %edx, %ebx\n" /* overItem */
        ".Lf16c8fe_0016c9b7:\n"
        "movl 0xe8(%ebx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf16c8fe_0016c9d3\n"
        "testb $2, %al\n" /* line 5525 */
        "je .Lf16c8fe_0016c9d3\n"
        "movl -0x40(%ebp), %edi\n" /* focusItem */
        "testl %edi, %edi\n"
        "movl -0x40(%ebp), %eax\n" /* focusItem */
        "cmovel %ebx, %eax\n" /* overItem */
        "movl %eax, -0x40(%ebp)\n" /* focusItem */
        /* { scope 2 */
        ".Lf16c8fe_0016c9d3:\n"
        "movl (%ebx), %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%ebx), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %edx\n" /* compareY */
        "movl %edx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%ebx), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x38(%ebp), %edi\n" /* compareRect */
        "movl %edi, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c8fe_0016cc7a\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c8fe_0016cc7a\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c8fe_0016cc7a\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c8fe_0016cc7a\n"
        /* } scope */
        "cmpl $1, -0x48(%ebp)\n" /* line 5530 | pass */
        "jne .Lf16c8fe_0016cc93\n"
        "movl 0xc(%ebp), %edx\n" /* line 5532 | menu */
        "movl 0x27c(%edx), %eax\n"
        "movl (%esi, %eax), %ebx\n" /* i, overItem */
        "movl 0x270(%ebx), %ecx\n" /* line 5533 | overItem */
        "testl %ecx, %ecx\n"
        "jne .Lf16c8fe_0016cc0f\n"
        "movl 0x294(%ebx), %edx\n" /* overItem */
        "testl %edx, %edx\n"
        "je .Lf16c8fe_0016cc0f\n"
        "movl $rect, %edx\n" /* line 3383 */
        "cld\n"
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %edx, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl 0x210(%ebx), %eax\n" /* line 3387 */
        "movl %eax, rect\n"
        "movl 0x214(%ebx), %eax\n"
        "movl %eax, rect+4\n"
        "movl 0x218(%ebx), %eax\n"
        "movl %eax, rect+8\n"
        "movl 0x21c(%ebx), %eax\n"
        "movl %eax, rect+12\n"
        "movl 0x220(%ebx), %eax\n"
        "movl %eax, rect+16\n"
        "movl 0x224(%ebx), %eax\n"
        "movl %eax, rect+20\n"
        "pxor %xmm0, %xmm0\n" /* line 3388 */
        "ucomiss rect+8, %xmm0\n"
        "jp .Lf16c8fe_0016cb2c\n"
        "je .Lf16c8fe_0016ce86\n"
        ".Lf16c8fe_0016cb2c:\n"
        "movss rect+4, %xmm0\n" /* line 3390 */
        "subss rect+12, %xmm0\n"
        "movss %xmm0, rect+4\n"
        /* { scope 2 */
        ".Lf16c8fe_0016cb44:\n"
        "movl rect, %eax\n" /* line 417 */
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movss %xmm0, -0x34(%ebp)\n" /* line 418 */
        "movl rect+8, %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl rect+12, %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %edx\n" /* compareX */
        "movl %edx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl rect+20, %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl rect+16, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x2c(%ebp), %edi\n"
        "movl %edi, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x38(%ebp), %edi\n" /* compareRect */
        "movl %edi, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c8fe_0016cc93\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c8fe_0016cc93\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c8fe_0016cc93\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c8fe_0016cc93\n"
        /* } scope */
        ".Lf16c8fe_0016cc0f:\n"
        "movl 0xe8(%ebx), %eax\n" /* line 405 */
        "testb $4, %al\n"
        "je .Lf16c8fe_0016cc93\n"
        "testb $0x10, %al\n"
        "jne .Lf16c8fe_0016cc93\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 5543 | y */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* overItem */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_MouseEnter\n"
        "movl -0x44(%ebp), %eax\n" /* line 5547 | focusSet */
        "testl %eax, %eax\n"
        "jne .Lf16c8fe_0016cc93\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 5549 | y */
        "movss %xmm0, 0xc(%esp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* overItem */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_SetFocus\n"
        "movl %eax, -0x44(%ebp)\n" /* focusSet */
        "testl %eax, %eax\n" /* line 5551 */
        "je .Lf16c8fe_0016cc93\n"
        "movl %ebx, -0x40(%ebp)\n" /* overItem, focusItem */
        "jmp .Lf16c8fe_0016cc93\n"
        ".Lf16c8fe_0016cc7a:\n"
        "movl 0xc(%ebp), %edi\n" /* line 5557 | menu */
        "movl 0x27c(%edi), %eax\n"
        "movl (%esi, %eax), %eax\n" /* i */
        "testb $1, 0xe8(%eax)\n"
        "jne .Lf16c8fe_0016ce44\n"
        /* { scope 2 */
        ".Lf16c8fe_0016cc93:\n"
        "addl $1, -0x3c(%ebp)\n" /* line 1916 */
        "subl $4, %esi\n" /* i */
        /* } scope */
        "movl -0x4c(%ebp), %eax\n" /* line 5510 */
        "cmpl %eax, -0x3c(%ebp)\n"
        "jne .Lf16c8fe_0016c97c\n"
        ".Lf16c8fe_0016cca6:\n"
        "addl $1, -0x48(%ebp)\n" /* line 5508 | pass */
        "cmpl $2, -0x48(%ebp)\n" /* pass */
        "jne .Lf16c8fe_0016c957\n"
        "movl -0x44(%ebp), %eax\n" /* line 5566 | focusSet */
        "testl %eax, %eax\n"
        "jne .Lf16c8fe_0016ce7c\n"
        "movl -0x40(%ebp), %eax\n" /* focusItem */
        "testl %eax, %eax\n"
        "je .Lf16c8fe_0016c926\n"
        /* { scope 2 */
        "movl -0x40(%ebp), %edx\n" /* line 417 | focusItem */
        "movl (%edx), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* compareRect */
        "movl 4(%edx), %eax\n" /* line 418 */
        "movl %eax, -0x34(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 419 */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 420 */
        "movl %eax, -0x2c(%ebp)\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareY */
        "movss 0x14(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl -0x40(%ebp), %edx\n" /* line 428 | focusItem */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* compareRect */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c8fe_0016cd85\n"
        "addss -0x30(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16c8fe_0016cd85\n"
        "movss -0x34(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16c8fe_0016cd85\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf16c8fe_0016c926\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16c8fe_0016cd85:\n"
        "movl 0xc(%ebp), %edi\n" /* line 386 | menu */
        "movl 0x218(%edi), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf16c8fe_0016c926\n"
        "xorl %esi, %esi\n" /* i */
        "movl 0xc(%ebp), %edi\n" /* menu */
        "jmp .Lf16c8fe_0016cd9f\n"
        ".Lf16c8fe_0016cd9d:\n"
        "movl %edx, %edi\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16c8fe_0016cd9f:\n"
        "leal (, %esi, 4), %ebx\n" /* line 430 */
        /* } scope */
        /* { scope 2 */
        "movl $2, 4(%esp)\n" /* line 392 */
        "movl 0x27c(%edi), %eax\n"
        "movl (%ebx, %eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        "movl 0x27c(%edi), %eax\n" /* line 393 */
        "movl (%ebx, %eax), %edx\n"
        "movl 0x2bc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16c8fe_0016cde5\n"
        "movl %eax, 8(%esp)\n" /* line 395 */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        ".Lf16c8fe_0016cde5:\n"
        "addl $1, %esi\n" /* line 386 | i */
        "movl 0xc(%ebp), %edx\n" /* menu */
        "cmpl 0x218(%edx), %esi\n" /* i */
        "jl .Lf16c8fe_0016cd9d\n"
        "jmp .Lf16c8fe_0016c926\n"
        /* } scope */
        ".Lf16c8fe_0016cdf8:\n"
        "movl $1, 4(%esp)\n" /* line 5519 */
        "movl %edx, (%esp)\n"
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "je .Lf16c8fe_0016cc93\n"
        "movl 0x27c(%edi), %eax\n"
        "jmp .Lf16c8fe_0016c9a5\n"
        ".Lf16c8fe_0016ce1b:\n"
        "movl $4, 4(%esp)\n" /* line 5522 */
        "movl %edx, (%esp)\n"
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "je .Lf16c8fe_0016cc93\n"
        "movl 0xc(%ebp), %edx\n" /* menu */
        "movl 0x27c(%edx), %eax\n"
        "movl (%esi, %eax), %ebx\n" /* i, overItem */
        "jmp .Lf16c8fe_0016c9b7\n"
        ".Lf16c8fe_0016ce44:\n"
        "movl %eax, 4(%esp)\n" /* line 5559 */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_MouseLeave\n"
        "movl 0xc(%ebp), %edi\n" /* line 5560 | menu */
        "movl 0x27c(%edi), %eax\n" /* item */
        "movl (%esi, %eax), %eax\n" /* i, item */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 1908 */
        "je .Lf16c8fe_0016cc93\n"
        "movl $1, 4(%esp)\n" /* line 1916 */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        "jmp .Lf16c8fe_0016cc93\n"
        /* } scope */
        ".Lf16c8fe_0016ce7c:\n"
        "movl $1, %eax\n" /* line 5566 */
        "jmp .Lf16c8fe_0016c928\n"
        ".Lf16c8fe_0016ce86:\n"
        "movss rect+4, %xmm0\n"
        "jmp .Lf16c8fe_0016cb44\n"
    );
}

/* line 5710 */
__attribute__((naked))
qboolean Display_MouseMove(displayContextDef_t *dc, void *p, int x, int y)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5710 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* p */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 5717 | p */
        "je .Lf16ce94_0016cf09\n"
        "movl (%ebx), %eax\n" /* line 5738 | p */
        "movl %eax, -0x30(%ebp)\n" /* newRect */
        "movl 4(%ebx), %eax\n" /* p */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* p */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* p */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* p */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* p */
        "movl %eax, -0x1c(%ebp)\n"
        "cvtsi2ssl 0x10(%ebp), %xmm0\n" /* line 5739 | x */
        "addss -0x30(%ebp), %xmm0\n" /* newRect */
        "movss %xmm0, -0x30(%ebp)\n" /* newRect */
        "cvtsi2ssl 0x14(%ebp), %xmm0\n" /* line 5740 | y */
        "addss -0x2c(%ebp), %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "leal -0x30(%ebp), %eax\n" /* line 5741 | newRect */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* p */
        "calll Window_SetRect\n"
        "movl %ebx, (%esp)\n" /* line 5742 | p */
        "calll Menu_UpdatePosition\n"
        /* } scope */
        ".Lf16ce94_0016cefc:\n"
        "movl $1, %eax\n" /* line 5745 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16ce94_0016cf09:\n"
        "movl 8(%ebp), %eax\n" /* line 5400 | dc */
        "movl 0x270(%eax), %edi\n"
        "subl $1, %edi\n"
        "js .Lf16ce94_0016cefc\n"
        "leal 0x230(%eax, %edi, 4), %edx\n"
        ".Lf16ce94_0016cf1e:\n"
        "movl (%edx), %ecx\n" /* line 5402 */
        "movl 0xe8(%ecx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf16ce94_0016cfa4\n"
        "testb $2, %al\n" /* line 5402 */
        "je .Lf16ce94_0016cfa4\n"
        "testl %ecx, %ecx\n" /* line 5720 */
        "je .Lf16ce94_0016cf3b\n"
        "testb $1, 0xe7(%ecx)\n" /* line 5722 */
        "jne .Lf16ce94_0016cfb7\n"
        ".Lf16ce94_0016cf3b:\n"
        "cvtsi2ssl 0x14(%ebp), %xmm0\n" /* line 5725 | y */
        "movss %xmm0, -0x40(%ebp)\n"
        "cvtsi2ssl 0x10(%ebp), %xmm0\n" /* x */
        "movss %xmm0, -0x3c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "leal 0x230(%eax, %edi, 4), %ebx\n" /* p */
        "xorl %esi, %esi\n"
        "addl $1, %edi\n" /* i */
        ".Lf16ce94_0016cf5e:\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 5731 */
        "movss %xmm0, 0xc(%esp)\n"
        "movss -0x3c(%ebp), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl (%ebx), %eax\n" /* p */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_HandleMouseMove\n"
        "testl %eax, %eax\n"
        "jne .Lf16ce94_0016cefc\n"
        "addl $1, %esi\n" /* line 5732 */
        "subl $4, %ebx\n" /* p */
        "cmpl %edi, %esi\n" /* line 5729 | i */
        "jne .Lf16ce94_0016cf5e\n"
        /* } scope */
        "movl $1, %eax\n" /* line 5745 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16ce94_0016cfa4:\n"
        "addl $1, %ebx\n" /* line 5742 | p */
        "subl $4, %edx\n"
        "leal 1(%edi), %eax\n" /* line 5400 */
        "cmpl %eax, %ebx\n"
        "jne .Lf16ce94_0016cf1e\n"
        "jmp .Lf16ce94_0016cf3b\n"
        ".Lf16ce94_0016cfb7:\n"
        "cvtsi2ssl 0x14(%ebp), %xmm0\n" /* line 5724 | y */
        "movss %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl 0x10(%ebp), %xmm0\n" /* x */
        "movss %xmm0, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_HandleMouseMove\n"
        "jmp .Lf16ce94_0016cefc\n"
    );
}

/* line 3263 */
__attribute__((naked))
void Menus_Open(displayContextDef_t *dc, menuDef_t *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3263 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x32c, %esp\n"
        /* { scope 1: item */
        "movl 8(%ebp), %eax\n" /* line 3267 | dc */
        "movl 0x270(%eax), %edi\n"
        "movl %edi, %eax\n"
        "subl $1, %eax\n"
        "js .Lf16cfe2_0016d02f\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "leal 0x230(%edx, %eax, 4), %ebx\n" /* window */
        "xorl %esi, %esi\n" /* menu */
        ".Lf16cfe2_0016d00a:\n"
        "movl $2, 4(%esp)\n" /* line 3268 */
        "movl (%ebx), %eax\n" /* window */
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        "addl $1, %esi\n" /* menu */
        "subl $4, %ebx\n" /* window */
        "cmpl %edi, %esi\n" /* line 3267 | menu */
        "jne .Lf16cfe2_0016d00a\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl 0x270(%ecx), %edi\n"
        /* { scope 2 */
        ".Lf16cfe2_0016d02f:\n"
        "movl %edi, %ebx\n" /* line 710 */
        "subl $1, %ebx\n"
        "js .Lf16cfe2_0016d07a\n"
        "movl 0xc(%ebp), %edx\n" /* line 712 | menu */
        "movl 8(%ebp), %eax\n" /* dc */
        "cmpl 0x230(%eax, %ebx, 4), %edx\n"
        "je .Lf16cfe2_0016d2ce\n"
        "leal 0x230(%eax, %ebx, 4), %ecx\n"
        "movl %ebx, %esi\n"
        "xorl %edx, %edx\n"
        ".Lf16cfe2_0016d054:\n"
        "subl $1, %esi\n" /* line 710 */
        "cmpl %ebx, %edx\n"
        "je .Lf16cfe2_0016d07a\n"
        "movl -4(%ecx), %eax\n" /* line 712 */
        "addl $1, %edx\n"
        "subl $4, %ecx\n"
        "cmpl %eax, 0xc(%ebp)\n" /* menu */
        "jne .Lf16cfe2_0016d054\n"
        "movl 8(%ebp), %eax\n" /* line 714 | dc */
        "movl %ebx, 0x270(%eax)\n"
        "cmpl %esi, %ebx\n" /* line 715 */
        "jg .Lf16cfe2_0016d274\n"
        ".Lf16cfe2_0016d07a:\n"
        "movl 8(%ebp), %edx\n" /* dc */
        /* } scope */
        "cmpl $0x10, 0x270(%edx)\n" /* line 730 */
        "je .Lf16cfe2_0016d2ab\n"
        ".Lf16cfe2_0016d08a:\n"
        "movl %edx, %ecx\n"
        ".Lf16cfe2_0016d08c:\n"
        "movl 0x270(%ecx), %eax\n" /* line 733 */
        "movl 0xc(%ebp), %edx\n" /* menu */
        "movl %edx, 0x230(%ecx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 734 */
        "movl %eax, 0x270(%ecx)\n"
        "movl $6, 4(%esp)\n" /* line 3276 */
        "movl %edx, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        "movl 0xc(%ebp), %ecx\n" /* line 3283 | menu */
        "movl 0x244(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16cfe2_0016d2c7\n"
        /* { scope 2 */
        "movl %ecx, -0x70(%ebp)\n" /* line 3287 */
        "movl 0x244(%ecx), %eax\n" /* line 3288 */
        "movl %eax, 8(%esp)\n"
        "leal -0x30c(%ebp), %eax\n" /* item */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        "movl 0xc(%ebp), %edx\n" /* menu */
        /* } scope */
        ".Lf16cfe2_0016d0eb:\n"
        "movl 0x254(%edx), %eax\n" /* line 3291 */
        "testl %eax, %eax\n"
        "je .Lf16cfe2_0016d0fd\n"
        "movl %eax, (%esp)\n" /* line 3292 */
        "calll UI_PlayLocalSoundAliasByName\n"
        /* { scope 2 */
        ".Lf16cfe2_0016d0fd:\n"
        "movl 8(%ebp), %ecx\n" /* line 3258 | dc */
        "movl 0x270(%ecx), %ecx\n"
        "movl %ecx, -0x328(%ebp)\n"
        "movl %ecx, %eax\n"
        "subl $1, %eax\n"
        "js .Lf16cfe2_0016d248\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "leal 0x230(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x31c(%ebp)\n"
        "movl $0, -0x320(%ebp)\n"
        "movl %eax, %ecx\n"
        ".Lf16cfe2_0016d133:\n"
        "movl (%ecx), %esi\n" /* line 3259 | menu */
        /* { scope 3: i */
        "testl %esi, %esi\n" /* line 3237 */
        "je .Lf16cfe2_0016d1f4\n"
        /* { scope 4 */
        "cmpl $5, 0xd0(%esi)\n" /* line 3227 */
        "je .Lf16cfe2_0016d223\n"
        ".Lf16cfe2_0016d14a:\n"
        "movl 0x218(%esi), %eax\n" /* line 3242 */
        "testl %eax, %eax\n"
        "jle .Lf16cfe2_0016d1f4\n"
        "movl $0, -0x324(%ebp)\n" /* i */
        "movl -0x324(%ebp), %edi\n" /* i */
        "jmp .Lf16cfe2_0016d18c\n"
        ".Lf16cfe2_0016d16a:\n"
        "movl %ebx, %eax\n"
        ".Lf16cfe2_0016d16c:\n"
        "cmpl $8, 0x270(%eax)\n" /* line 3245 */
        "je .Lf16cfe2_0016d1cf\n"
        ".Lf16cfe2_0016d175:\n"
        "addl $1, -0x324(%ebp)\n" /* line 3242 | i */
        "movl -0x324(%ebp), %eax\n" /* i */
        "cmpl 0x218(%esi), %eax\n"
        "jge .Lf16cfe2_0016d1f4\n"
        ".Lf16cfe2_0016d18a:\n"
        "movl %eax, %edi\n"
        ".Lf16cfe2_0016d18c:\n"
        "shll $2, %edi\n"
        "movl 0x27c(%esi), %eax\n" /* line 3244 */
        "movl (%eax, %edi), %ebx\n" /* window */
        /* { scope 5 */
        "cmpl $5, 0xd0(%ebx)\n" /* line 3227 */
        "jne .Lf16cfe2_0016d16a\n"
        "movl 0xcc(%ebx), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf16cfe2_0016d21b\n"
        "movl %edx, (%esp)\n" /* line 3229 */
        "calll CIN_StopCinematic\n"
        "movl $0xffffffff, 0xcc(%ebx)\n" /* line 3230 */
        "movl 0x27c(%esi), %eax\n"
        "movl (%eax, %edi), %eax\n"
        /* } scope */
        "cmpl $8, 0x270(%eax)\n" /* line 3245 */
        "jne .Lf16cfe2_0016d175\n"
        ".Lf16cfe2_0016d1cf:\n"
        "movl 0xd8(%eax), %eax\n" /* line 3247 */
        "negl %eax\n"
        "movl %eax, (%esp)\n"
        "calll CIN_StopCinematic\n"
        "addl $1, -0x324(%ebp)\n" /* line 3242 | i */
        "movl -0x324(%ebp), %eax\n" /* i */
        "cmpl 0x218(%esi), %eax\n"
        "jl .Lf16cfe2_0016d18a\n"
        ".Lf16cfe2_0016d1f4:\n"
        "addl $1, -0x320(%ebp)\n"
        "subl $4, -0x31c(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl -0x328(%ebp), %edx\n" /* line 3258 */
        "cmpl %edx, -0x320(%ebp)\n"
        "je .Lf16cfe2_0016d248\n"
        "movl -0x31c(%ebp), %ecx\n"
        "jmp .Lf16cfe2_0016d133\n"
        ".Lf16cfe2_0016d21b:\n"
        "movl (%eax, %edi), %eax\n"
        "jmp .Lf16cfe2_0016d16c\n"
        /* { scope 3: i */
        /* { scope 4 */
        ".Lf16cfe2_0016d223:\n"
        "movl 0xcc(%esi), %eax\n" /* line 3227 */
        "testl %eax, %eax\n"
        "js .Lf16cfe2_0016d14a\n"
        "movl %eax, (%esp)\n" /* line 3229 */
        "calll CIN_StopCinematic\n"
        "movl $0xffffffff, 0xcc(%esi)\n" /* line 3230 */
        "jmp .Lf16cfe2_0016d14a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf16cfe2_0016d248:\n"
        "movl 8(%ebp), %ecx\n" /* line 3298 | dc */
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Display_MouseMove\n"
        /* } scope */
        "addl $0x32c, %esp\n" /* line 3300 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: item */
        /* { scope 2 */
        ".Lf16cfe2_0016d274:\n"
        "leal 0x234(%eax, %esi, 4), %edx\n" /* line 3263 */
        "movl %esi, %ecx\n" /* menu */
        "leal 0x230(%eax, %esi, 4), %ebx\n" /* window */
        "subl %edx, %ebx\n" /* window */
        ".Lf16cfe2_0016d286:\n"
        "addl $1, %ecx\n" /* line 716 */
        "movl (%edx), %eax\n"
        "movl %eax, (%edx, %ebx)\n"
        "addl $4, %edx\n"
        "movl 8(%ebp), %eax\n" /* line 715 | dc */
        "cmpl %ecx, 0x270(%eax)\n"
        "jg .Lf16cfe2_0016d286\n"
        "movl %eax, %edx\n"
        /* } scope */
        "cmpl $0x10, 0x270(%edx)\n" /* line 730 */
        "jne .Lf16cfe2_0016d08a\n"
        ".Lf16cfe2_0016d2ab:\n"
        "movl $str_002ac364, 4(%esp)\n" /* line 731 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "jmp .Lf16cfe2_0016d08c\n"
        ".Lf16cfe2_0016d2c7:\n"
        "movl %ecx, %edx\n"
        "jmp .Lf16cfe2_0016d0eb\n"
        /* { scope 2 */
        ".Lf16cfe2_0016d2ce:\n"
        "movl %ebx, %esi\n" /* line 712 */
        "movl 8(%ebp), %eax\n" /* line 714 | dc */
        "movl %ebx, 0x270(%eax)\n"
        "cmpl %esi, %ebx\n" /* line 715 */
        "jle .Lf16cfe2_0016d07a\n"
        "jmp .Lf16cfe2_0016d274\n"
    );
}

/* Menus_OpenByName — find menu by name and open it */
qboolean Menus_OpenByName(displayContextDef_t *dc, const char *p)
{
    menuDef_t *menu = Menus_FindByName(dc, p);
    if (menu) {
        Menus_Open(dc, menu);
        return 1;
    }
    return 0;
}

/* Script_Open — parse menu name, find and open it */
void Script_Open(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    (void)item;
    if (!String_Parse(args, name, 0x400))
        return;
    Menus_OpenByName(dc, name);
}

/* Script_OpenForGameType — open menu named with gametype dvar substitution */
void Script_OpenForGameType(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    if (!String_Parse(args, name, 0x400))
        return;
    const char *p = va(name, Dvar_GetString(*(const char **)((byte *)item + 0x2c0)));
    Menus_OpenByName(dc, p);
}

/* Script_InGameOpen — open menu by name only if in-game */
void Script_InGameOpen(displayContextDef_t *dc, itemDef_t *item, const char * *args)
{
    char name[0x400];
    (void)item;
    if (!String_Parse(args, name, 0x400))
        return;
    if (!UI_ClientIsInGame())
        return;
    Menus_OpenByName(dc, name);
}

/* line 3178 */
__attribute__((naked))
itemDef_t * Menu_SetNextCursorItem(displayContextDef_t *dc, menuDef_t *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3178 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* dc */
        "movl 0xc(%ebp), %ebx\n" /* menu */
        /* { scope 1 */
        "movl 0x220(%ebx), %eax\n" /* line 92 */
        "movl %eax, -0x1c(%ebp)\n" /* oldCursor */
        "movl %eax, %edx\n"
        "addl $1, %eax\n" /* line 3189 */
        "je .Lf16d52e_0016d641\n"
        "xorl %edi, %edi\n" /* line 3217 | wrapped */
        "jmp .Lf16d52e_0016d55b\n"
        ".Lf16d52e_0016d555:\n"
        "movl 0x220(%ebx), %edx\n" /* menu */
        ".Lf16d52e_0016d55b:\n"
        "cmpl 0x218(%ebx), %edx\n" /* line 3195 | menu */
        "jge .Lf16d52e_0016d628\n"
        "leal 1(%edx), %eax\n" /* line 3197 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "movl 0x220(%ebx), %edx\n" /* line 3198 | menu */
        "cmpl 0x218(%ebx), %edx\n" /* menu */
        "jl .Lf16d52e_0016d5a6\n"
        "testl %edi, %edi\n" /* line 3200 | wrapped */
        "jne .Lf16d52e_0016d661\n"
        "movl $0, 4(%esp)\n" /* line 3203 */
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "movw $1, %di\n" /* wrapped */
        "movl 0x220(%ebx), %edx\n" /* menu */
        ".Lf16d52e_0016d5a6:\n"
        "cvtsi2ssl 0x10(%esi), %xmm0\n" /* line 3211 | dc */
        "movss %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl 0xc(%esi), %xmm0\n" /* dc */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x27c(%ebx), %eax\n" /* menu */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* dc */
        "calll Item_SetFocus\n"
        "testl %eax, %eax\n"
        "je .Lf16d52e_0016d555\n"
        "movl 0x220(%ebx), %edx\n" /* line 53 */
        "movl 0x27c(%ebx), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3215 | 1.0f */
        "movss 4(%eax), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* menu */
        "movl %esi, (%esp)\n" /* dc */
        "calll Menu_HandleMouseMove\n"
        "movl 0x220(%ebx), %edx\n" /* line 3217 | menu */
        "movl 0x27c(%ebx), %eax\n" /* menu */
        "movl (%eax, %edx, 4), %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d52e_0016d628:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3220 | oldCursor */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d52e_0016d641:\n"
        "movl $0, 4(%esp)\n" /* line 3191 */
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "movl $1, %edi\n" /* wrapped */
        "movl 0x220(%ebx), %edx\n" /* menu */
        "jmp .Lf16d52e_0016d55b\n"
        ".Lf16d52e_0016d661:\n"
        "movl 0x27c(%ebx), %eax\n" /* line 3207 | menu */
        "movl -0x1c(%ebp), %edx\n" /* oldCursor */
        "movl (%eax, %edx, 4), %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3130 */
__attribute__((naked))
itemDef_t * Menu_SetPrevCursorItem(displayContextDef_t *dc, menuDef_t *menu)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3130 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* dc */
        "movl 0xc(%ebp), %ebx\n" /* menu */
        /* { scope 1 */
        "movl 0x220(%ebx), %edi\n" /* line 92 */
        "movl %edi, %eax\n"
        "testl %edi, %edi\n" /* line 3141 | oldCursor */
        "js .Lf16d676_0016d795\n"
        "movl $0, -0x1c(%ebp)\n" /* line 3169 | wrapped */
        "jmp .Lf16d676_0016d6e1\n"
        ".Lf16d676_0016d69e:\n"
        "movl 0x220(%ebx), %edx\n" /* line 92 */
        "testl %edx, %edx\n" /* line 3156 */
        "js .Lf16d676_0016d72c\n"
        ".Lf16d676_0016d6ac:\n"
        "cvtsi2ssl 0x10(%esi), %xmm0\n" /* line 3163 | dc */
        "movss %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl 0xc(%esi), %xmm0\n" /* dc */
        "movss %xmm0, 8(%esp)\n"
        "movl 0x27c(%ebx), %eax\n" /* menu */
        "movl (%eax, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* dc */
        "calll Item_SetFocus\n"
        "testl %eax, %eax\n"
        "jne .Lf16d676_0016d742\n"
        "movl 0x220(%ebx), %eax\n" /* menu */
        ".Lf16d676_0016d6e1:\n"
        "cmpl $-1, %eax\n" /* line 3147 */
        "jle .Lf16d676_0016d72c\n"
        "subl $1, %eax\n" /* line 3149 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "movl 0x220(%ebx), %eax\n" /* line 3150 | menu */
        "testl %eax, %eax\n"
        "jns .Lf16d676_0016d69e\n"
        "movl -0x1c(%ebp), %eax\n" /* wrapped */
        "testl %eax, %eax\n"
        "jne .Lf16d676_0016d69e\n"
        "movl 0x218(%ebx), %eax\n" /* line 3153 | menu */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "movl $1, -0x1c(%ebp)\n" /* wrapped */
        "movl 0x220(%ebx), %edx\n" /* line 92 */
        "testl %edx, %edx\n" /* line 3156 */
        "jns .Lf16d676_0016d6ac\n"
        ".Lf16d676_0016d72c:\n"
        "movl %edi, 4(%esp)\n" /* line 3172 | oldCursor */
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d676_0016d742:\n"
        "movl 0x220(%ebx), %edx\n" /* line 53 */
        "movl 0x27c(%ebx), %eax\n"
        "movl (%eax, %edx, 4), %eax\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 3167 | 1.0f */
        "movss 4(%eax), %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0xc(%esp)\n"
        "addss (%eax), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* menu */
        "movl %esi, (%esp)\n" /* dc */
        "calll Menu_HandleMouseMove\n"
        "movl 0x220(%ebx), %edx\n" /* line 3169 | menu */
        "movl 0x27c(%ebx), %eax\n" /* menu */
        "movl (%eax, %edx, 4), %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 3175 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d676_0016d795:\n"
        "movl 0x218(%ebx), %eax\n" /* line 3143 | menu */
        "subl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* menu */
        "calll Menu_SetCursorItem\n"
        "movl $1, -0x1c(%ebp)\n" /* wrapped */
        "movl 0x220(%ebx), %eax\n" /* menu */
        "jmp .Lf16d676_0016d6e1\n"
    );
}

/* line 2583 */
__attribute__((naked))
qboolean Item_TextField_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2583 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x41c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* key */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 2590 | item */
        "movl %eax, (%esp)\n"
        "calll Item_GetEditFieldDef\n"
        "movl %eax, %esi\n" /* editPtr */
        "testl %eax, %eax\n" /* line 2592 */
        "je .Lf16d7bc_0016db02\n"
        "movl 0xc(%ebp), %edx\n" /* line 2595 | item */
        "movl 0x2c0(%edx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf16d7bc_0016db02\n"
        "movl $0x400, 8(%esp)\n" /* line 2597 */
        "movl $0, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0xc(%ebp), %edx\n" /* line 2598 | item */
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "cld\n" /* line 2599 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x418(%ebp), %edi\n" /* buff, len */
        "repne scasb %es:(%edi), %al\n" /* len */
        "notl %ecx\n"
        "leal -1(%ecx), %edi\n" /* len */
        "movl 0x10(%esi), %eax\n" /* line 2600 | editPtr */
        "testl %eax, %eax\n"
        "jne .Lf16d7bc_0016dad2\n"
        ".Lf16d7bc_0016d85a:\n"
        "testb $4, %bh\n" /* line 2605 | key */
        "jne .Lf16d7bc_0016d8fa\n"
        ".Lf16d7bc_0016d863:\n"
        "cmpl $0xa2, %ebx\n" /* line 2717 | key */
        "je .Lf16d7bc_0016db0f\n"
        "cmpl $0x9d, %ebx\n" /* line 2729 | key */
        "je .Lf16d7bc_0016dddb\n"
        "cmpl $0x9c, %ebx\n" /* line 2736 | key */
        "je .Lf16d7bc_0016dd78\n"
        "cmpl $0xa5, %ebx\n" /* line 2743 | key */
        "je .Lf16d7bc_0016de21\n"
        "cmpl $0xa6, %ebx\n" /* line 2750 | key */
        "je .Lf16d7bc_0016de45\n"
        "cmpl $0xa1, %ebx\n" /* line 2757 | key */
        "je .Lf16d7bc_0016de8f\n"
        ".Lf16d7bc_0016d8ab:\n"
        "cmpl $9, %ebx\n" /* line 2764 | key */
        "je .Lf16d7bc_0016dca9\n"
        "cmpl $0x9b, %ebx\n" /* key */
        "je .Lf16d7bc_0016dca9\n"
        ".Lf16d7bc_0016d8c0:\n"
        "cmpl $0x9a, %ebx\n" /* line 2773 | key */
        "je .Lf16d7bc_0016ddfa\n"
        "cmpl $0xd, %ebx\n" /* line 2783 | key */
        "je .Lf16d7bc_0016dc6d\n"
        "cmpl $0xbf, %ebx\n" /* key */
        "je .Lf16d7bc_0016dc6d\n"
        ".Lf16d7bc_0016d8e1:\n"
        "cmpl $0x1b, %ebx\n" /* line 2790 | key */
        "je .Lf16d7bc_0016db02\n"
        ".Lf16d7bc_0016d8ea:\n"
        "movl $1, %eax\n"
        /* } scope */
        ".Lf16d7bc_0016d8ef:\n"
        "addl $0x41c, %esp\n" /* line 2799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d7bc_0016d8fa:\n"
        "andb $0xfb, %bh\n" /* line 2607 | key */
        "cmpl $8, %ebx\n" /* line 2609 | key */
        "je .Lf16d7bc_0016db67\n"
        "movl 0xc(%ebp), %eax\n" /* line 2629 | item */
        "cmpl $0x10, 0x270(%eax)\n"
        "je .Lf16d7bc_0016dde5\n"
        ".Lf16d7bc_0016d916:\n"
        "cmpl $0x1f, %ebx\n" /* line 2638 | key */
        "jle .Lf16d7bc_0016d8ea\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x2c0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016d8ea\n"
        "cmpl $9, 0x270(%edx)\n" /* line 2643 */
        "je .Lf16d7bc_0016de4e\n"
        ".Lf16d7bc_0016d935:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2649 | item */
        "cmpl $0x11, 0x270(%eax)\n"
        "je .Lf16d7bc_0016de65\n"
        "movl %eax, %edx\n"
        ".Lf16d7bc_0016d947:\n"
        "cmpl $0x12, 0x270(%edx)\n" /* line 2661 */
        "je .Lf16d7bc_0016deae\n"
        ".Lf16d7bc_0016d954:\n"
        "calll Key_GetOverstrikeMode\n" /* line 2664 */
        "testl %eax, %eax\n"
        "jne .Lf16d7bc_0016dcfb\n"
        "cmpl $0xff, %edi\n" /* line 2666 | len */
        "je .Lf16d7bc_0016d8ea\n"
        "movl 0x10(%esi), %eax\n" /* editPtr */
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016d978\n"
        "cmpl %eax, %edi\n" /* len */
        "jge .Lf16d7bc_0016d8ea\n"
        ".Lf16d7bc_0016d978:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2673 | item */
        "movl 0x2dc(%edx), %eax\n"
        "subl %eax, %edi\n" /* len */
        "leal 1(%edi), %edx\n" /* len */
        "movl %edx, 8(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* buff */
        "addl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x417(%eax, %ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        ".Lf16d7bc_0016d9a8:\n"
        "movl 0x2dc(%edx), %eax\n" /* line 2690 */
        "movb %bl, -0x418(%ebp, %eax)\n" /* key */
        "leal -0x418(%ebp), %eax\n" /* line 2692 | buff */
        "movl %eax, 4(%esp)\n"
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "movl 0xc(%ebp), %edx\n" /* line 2696 | item */
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $1, 8(%esp)\n" /* line 2699 */
        "leal -0x418(%ebp), %edx\n" /* buff */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Item_GetCursorPosOffset\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Item_SetCursorPos\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 2562 | item */
        "movl %eax, (%esp)\n"
        "calll Item_GetEditFieldDef\n"
        "movl %eax, %edi\n" /* editPtr */
        "movl 0xc(%ebp), %edx\n" /* line 106 | item */
        "movl 0x2dc(%edx), %eax\n"
        "cmpl 0x1c(%edi), %eax\n" /* line 2565 | editPtr */
        "jl .Lf16d7bc_0016ddd3\n"
        "movl 0x18(%edi), %eax\n" /* line 2571 | editPtr */
        "testl %eax, %eax\n"
        "jne .Lf16d7bc_0016ddaf\n"
        /* } scope */
        ".Lf16d7bc_0016da4e:\n"
        "movl 0x10(%esi), %eax\n" /* line 2702 | editPtr */
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016d8ab\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "cmpl 0x2dc(%edx), %eax\n"
        "jg .Lf16d7bc_0016d8ab\n"
        "movl 0x14(%esi), %eax\n" /* line 2704 | editPtr */
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016d8ab\n"
        "movl 0x29c(%edx), %eax\n" /* line 2706 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_SetNextCursorItem\n"
        "movl %eax, %esi\n" /* editPtr */
        "movl $0, 4(%esp)\n" /* line 2707 */
        "movl %eax, (%esp)\n"
        "calll Item_SetCursorPos\n"
        "testl %esi, %esi\n" /* line 2708 | editPtr */
        "je .Lf16d7bc_0016d8ab\n"
        "cmpl $0x12, 0x270(%esi)\n" /* line 2525 */
        "ja .Lf16d7bc_0016d8ab\n"
        "movl 0x270(%esi), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x70210, %eax\n"
        "je .Lf16d7bc_0016d8ab\n"
        "movl %esi, g_editItem\n" /* line 2709 | editPtr */
        "jmp .Lf16d7bc_0016d8ab\n"
        ".Lf16d7bc_0016dad2:\n"
        "cmpl %eax, %edi\n" /* line 2600 | len */
        "jle .Lf16d7bc_0016d85a\n"
        "movb $0, -0x418(%ebp, %eax)\n" /* line 2603 */
        "movl %eax, %edi\n" /* len */
        "testb $4, %bh\n" /* line 2605 | key */
        "je .Lf16d7bc_0016d863\n"
        "jmp .Lf16d7bc_0016d8fa\n"
        ".Lf16d7bc_0016daf2:\n"
        "calll Com_GetDecimalDelimiter\n" /* line 2651 */
        "movsbl %al, %eax\n"
        "cmpl %eax, %ebx\n" /* key */
        "je .Lf16d7bc_0016de75\n"
        ".Lf16d7bc_0016db02:\n"
        "xorl %eax, %eax\n" /* line 2790 */
        /* } scope */
        ".Lf16d7bc_0016db04:\n"
        "addl $0x41c, %esp\n" /* line 2799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d7bc_0016db0f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2719 | item */
        "cmpl 0x2dc(%edx), %edi\n" /* len */
        "jle .Lf16d7bc_0016d8ea\n"
        "movl 0x2dc(%edx), %eax\n" /* line 2723 */
        "subl %eax, %edi\n" /* len */
        "movl %edi, 8(%esp)\n" /* len */
        "leal -0x418(%ebp), %edx\n" /* buff */
        "leal (%edx, %eax), %eax\n"
        "leal 1(%eax), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        "leal -0x418(%ebp), %eax\n" /* line 2724 | buff */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "movl $1, %eax\n"
        "jmp .Lf16d7bc_0016d8ef\n"
        ".Lf16d7bc_0016db67:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2611 | item */
        "movl 0x2dc(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf16d7bc_0016dba1\n"
        "movl 0x2dc(%edx), %eax\n" /* line 2615 */
        "subl %eax, %edi\n" /* len */
        "leal 1(%edi), %edx\n" /* len */
        "movl %edx, 8(%esp)\n"
        "leal -0x418(%ebp), %edx\n" /* buff */
        "addl %eax, %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x419(%eax, %ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        ".Lf16d7bc_0016dba1:\n"
        "leal -0x418(%ebp), %eax\n" /* line 2617 | buff */
        "movl %eax, 4(%esp)\n"
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFromStringByName\n"
        "movl 0xc(%ebp), %edx\n" /* line 2621 | item */
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl $0x400, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0xffffffff, 8(%esp)\n" /* line 2623 */
        "leal -0x418(%ebp), %edx\n" /* buff */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Item_GetCursorPosOffset\n"
        "movl %eax, 4(%esp)\n"
        ".Lf16d7bc_0016dc05:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2752 | item */
        "movl %edx, (%esp)\n"
        "calll Item_SetCursorPos\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 2562 | item */
        "movl %eax, (%esp)\n"
        ".Lf16d7bc_0016dc16:\n"
        "calll Item_GetEditFieldDef\n"
        "movl %eax, %ebx\n" /* editPtr */
        "movl 0xc(%ebp), %edx\n" /* line 106 | item */
        "movl 0x2dc(%edx), %eax\n"
        "cmpl 0x1c(%ebx), %eax\n" /* line 2565 | editPtr */
        "jl .Lf16d7bc_0016dc5a\n"
        "movl 0x18(%ebx), %eax\n" /* line 2571 | editPtr */
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016d8ea\n"
        "negl %eax\n" /* line 2573 */
        "movl %eax, 8(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Item_GetCursorPosOffset\n"
        "cmpl 0x1c(%ebx), %eax\n" /* line 2574 | editPtr */
        "jle .Lf16d7bc_0016d8ea\n"
        ".Lf16d7bc_0016dc5a:\n"
        "movl %eax, 0x1c(%ebx)\n" /* line 2576 | editPtr */
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x41c, %esp\n" /* line 2799 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16d7bc_0016dc6d:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2785 | item */
        "movl 0x2b4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016dc8d\n"
        "movl %eax, 8(%esp)\n" /* line 2786 */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        ".Lf16d7bc_0016dc8d:\n"
        "cmpl $0xd, %ebx\n" /* line 2790 | key */
        "je .Lf16d7bc_0016db02\n"
        "cmpl $0xbf, %ebx\n" /* key */
        "jne .Lf16d7bc_0016d8e1\n"
        "xorl %eax, %eax\n"
        "jmp .Lf16d7bc_0016db04\n"
        ".Lf16d7bc_0016dca9:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2766 | item */
        "movl 0x29c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_SetNextCursorItem\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2767 */
        "je .Lf16d7bc_0016d8c0\n"
        "cmpl $0x12, 0x270(%eax)\n" /* line 2525 */
        "ja .Lf16d7bc_0016d8c0\n"
        "movl 0x270(%eax), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x70210, %eax\n"
        "je .Lf16d7bc_0016d8c0\n"
        "movl %edx, g_editItem\n" /* line 2769 */
        "jmp .Lf16d7bc_0016d8c0\n"
        ".Lf16d7bc_0016dcfb:\n"
        "movl 0x10(%esi), %eax\n" /* line 2677 | editPtr */
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016dd70\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "cmpl 0x2dc(%edx), %eax\n"
        "jg .Lf16d7bc_0016d9a8\n"
        "movl 0x14(%esi), %eax\n" /* line 2679 | editPtr */
        "testl %eax, %eax\n"
        "je .Lf16d7bc_0016d8ea\n"
        "movl 0x29c(%edx), %eax\n" /* line 2681 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_SetNextCursorItem\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2682 */
        "je .Lf16d7bc_0016d8ea\n"
        ".Lf16d7bc_0016dd3b:\n"
        "cmpl $0x12, 0x270(%edx)\n" /* line 2525 */
        "ja .Lf16d7bc_0016d8ea\n"
        "movl 0x270(%edx), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x70210, %eax\n"
        "je .Lf16d7bc_0016d8ea\n"
        "movl %edx, g_editItem\n" /* line 2778 */
        "movl $1, %eax\n"
        "jmp .Lf16d7bc_0016d8ef\n"
        ".Lf16d7bc_0016dd70:\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "jmp .Lf16d7bc_0016d9a8\n"
        ".Lf16d7bc_0016dd78:\n"
        "movl $0xffffffff, 8(%esp)\n" /* line 2738 */
        ".Lf16d7bc_0016dd80:\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Item_GetCursorPosOffset\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Item_SetCursorPos\n"
        /* { scope 2 */
        "movl 0xc(%ebp), %edx\n" /* line 2562 | item */
        "movl %edx, (%esp)\n"
        "jmp .Lf16d7bc_0016dc16\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16d7bc_0016ddaf:\n"
        "negl %eax\n" /* line 2573 */
        "movl %eax, 8(%esp)\n"
        "leal -0x418(%ebp), %eax\n" /* buff */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Item_GetCursorPosOffset\n"
        "cmpl 0x1c(%edi), %eax\n" /* line 2574 | editPtr */
        "jle .Lf16d7bc_0016da4e\n"
        ".Lf16d7bc_0016ddd3:\n"
        "movl %eax, 0x1c(%edi)\n" /* line 2576 | editPtr */
        "jmp .Lf16d7bc_0016da4e\n"
        /* } scope */
        ".Lf16d7bc_0016dddb:\n"
        "movl $1, 8(%esp)\n" /* line 2731 */
        "jmp .Lf16d7bc_0016dd80\n"
        ".Lf16d7bc_0016dde5:\n"
        "movl %ebx, (%esp)\n" /* line 2631 | key */
        "calll I_isforfilename\n"
        "testb %al, %al\n"
        "jne .Lf16d7bc_0016d916\n"
        "jmp .Lf16d7bc_0016d8ea\n"
        ".Lf16d7bc_0016ddfa:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2775 | item */
        "movl 0x29c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_SetPrevCursorItem\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2776 */
        "jne .Lf16d7bc_0016dd3b\n"
        "jmp .Lf16d7bc_0016d8ea\n"
        ".Lf16d7bc_0016de21:\n"
        "movl $0, 4(%esp)\n" /* line 2745 */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Item_SetCursorPos\n"
        "movl $0, 0x1c(%esi)\n" /* line 2746 | editPtr */
        "movl $1, %eax\n"
        "jmp .Lf16d7bc_0016d8ef\n"
        ".Lf16d7bc_0016de45:\n"
        "movl %edi, 4(%esp)\n" /* line 2752 | len */
        "jmp .Lf16d7bc_0016dc05\n"
        ".Lf16d7bc_0016de4e:\n"
        "movl %ebx, (%esp)\n" /* line 2645 | key */
        "calll I_isdigit\n"
        "testb %al, %al\n"
        "jne .Lf16d7bc_0016d935\n"
        "xorl %eax, %eax\n" /* line 2790 */
        "jmp .Lf16d7bc_0016db04\n"
        ".Lf16d7bc_0016de65:\n"
        "movl %ebx, (%esp)\n" /* line 2651 | key */
        "calll I_isdigit\n"
        "testb %al, %al\n"
        "je .Lf16d7bc_0016daf2\n"
        ".Lf16d7bc_0016de75:\n"
        "calll Com_GetDecimalDelimiter\n" /* line 2657 */
        "movsbl %al, %eax\n"
        "cmpl %eax, %ebx\n" /* key */
        "movl $0x2e, %eax\n"
        "cmovel %eax, %ebx\n" /* key */
        "movl 0xc(%ebp), %edx\n" /* item */
        "jmp .Lf16d7bc_0016d947\n"
        ".Lf16d7bc_0016de8f:\n"
        "calll Key_GetOverstrikeMode\n" /* line 2759 */
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Key_SetOverstrikeMode\n"
        "movl $1, %eax\n"
        "jmp .Lf16d7bc_0016d8ef\n"
        ".Lf16d7bc_0016deae:\n"
        "movl %ebx, (%esp)\n" /* line 2662 | key */
        "calll ___toupper\n"
        "movl %eax, %ebx\n" /* key */
        "jmp .Lf16d7bc_0016d954\n"
    );
}

/* line 3444 */
__attribute__((naked))
void Menu_HandleKey(displayContextDef_t *dc, menuDef_t *menu, int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3444 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x33c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* menu */
        /* { scope 1: it */
        "movl g_waitingForKey, %eax\n" /* line 3464 */
        "testl %eax, %eax\n"
        "je .Lf16debe_0016dee1\n"
        "movl 0x14(%ebp), %eax\n" /* down */
        "testl %eax, %eax\n"
        "jne .Lf16debe_0016e1db\n"
        ".Lf16debe_0016dee1:\n"
        "movl g_editingField, %edi\n" /* line 3471 */
        "testl %edi, %edi\n"
        "jne .Lf16debe_0016dfc3\n"
        ".Lf16debe_0016deef:\n"
        "testl %esi, %esi\n" /* line 3494 | menu */
        "je .Lf16debe_0016dfb8\n"
        "movl 0x14(%ebp), %ecx\n" /* line 3502 | down */
        "testl %ecx, %ecx\n"
        "jne .Lf16debe_0016e007\n"
        ".Lf16debe_0016df02:\n"
        "movl 0x218(%esi), %edi\n" /* line 3521 | menu */
        "testl %edi, %edi\n"
        "jle .Lf16debe_0016e126\n"
        "movl 0x27c(%esi), %ebx\n" /* line 3523 | menu */
        "movl $0, -0x31c(%ebp)\n" /* item */
        "xorl %ecx, %ecx\n"
        ".Lf16debe_0016df22:\n"
        "movl (%ebx, %ecx, 4), %edx\n"
        "movl 0xe8(%edx), %eax\n" /* line 143 */
        "testb $4, %al\n" /* line 155 */
        "je .Lf16debe_0016df3e\n"
        "testb $2, %al\n" /* line 3523 */
        "cmovel -0x31c(%ebp), %edx\n" /* item */
        "movl %edx, -0x31c(%ebp)\n" /* item */
        ".Lf16debe_0016df3e:\n"
        "addl $1, %ecx\n" /* line 3521 */
        "cmpl %ecx, %edi\n"
        "jne .Lf16debe_0016df22\n"
        "movl 0x10(%ebp), %eax\n" /* line 3531 | key */
        "subl $0xcd, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf16debe_0016e141\n"
        ".Lf16debe_0016df56:\n"
        "movl -0x31c(%ebp), %eax\n" /* line 3535 | item */
        "testl %eax, %eax\n"
        "je .Lf16debe_0016e167\n"
        ".Lf16debe_0016df64:\n"
        "movl 0x14(%ebp), %edx\n" /* line 3537 | down */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* key */
        "movl %eax, 8(%esp)\n"
        "movl -0x31c(%ebp), %edx\n" /* item */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_HandleKey\n"
        "testl %eax, %eax\n"
        "je .Lf16debe_0016e167\n"
        "movl -0x31c(%ebp), %eax\n" /* line 3125 | item */
        "testl %eax, %eax\n"
        "je .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016df99:\n"
        "movl -0x31c(%ebp), %edx\n" /* item */
        ".Lf16debe_0016df9f:\n"
        "movl 0x2b0(%edx), %eax\n" /* line 3126 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        /* } scope */
        ".Lf16debe_0016dfb8:\n"
        "addl $0x33c, %esp\n" /* line 3691 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: it */
        ".Lf16debe_0016dfc3:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 3471 | down */
        "testl %ebx, %ebx\n"
        "je .Lf16debe_0016deef\n"
        "movl 0x10(%ebp), %edx\n" /* line 3473 | key */
        "movl %edx, 8(%esp)\n"
        "movl g_editItem, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_TextField_HandleKey\n"
        "testl %eax, %eax\n"
        "jne .Lf16debe_0016e2f4\n"
        "movl $0, g_editingField\n" /* line 3475 */
        "movl $0, g_editItem\n" /* line 3476 */
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e007:\n"
        "testb $1, 0xe7(%esi)\n" /* line 3502 | menu */
        "jne .Lf16debe_0016df02\n"
        "movl 0x214(%esi), %edx\n" /* line 3504 | menu */
        "testl %edx, %edx\n"
        "jne .Lf16debe_0016df02\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "cvtsi2ssl 0x10(%eax), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%eax), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 417 */
        "movl %eax, -0x314(%ebp)\n" /* compareRect */
        "movl 4(%esi), %eax\n" /* line 418 */
        "movl %eax, -0x310(%ebp)\n"
        "movl 8(%esi), %eax\n" /* line 419 */
        "movl %eax, -0x30c(%ebp)\n"
        "movl 0xc(%esi), %eax\n" /* line 420 */
        "movl %eax, -0x308(%ebp)\n"
        "movss %xmm0, -0x1c(%ebp)\n" /* line 422 | compareX */
        "movss %xmm1, -0x20(%ebp)\n" /* line 423 | compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%esi), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x314(%ebp), %edx\n" /* compareRect */
        "leal -0x308(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x310(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x314(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jae .Lf16debe_0016e388\n"
        /* } scope */
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY */
        ".Lf16debe_0016e0d2:\n"
        "movl inHandleKey, %eax\n" /* line 3508 */
        "testl %eax, %eax\n"
        "jne .Lf16debe_0016df02\n"
        "movl 0x10(%ebp), %eax\n" /* key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf16debe_0016df02\n"
        "movl $1, inHandleKey\n" /* line 3510 */
        "movl 0x14(%ebp), %edx\n" /* line 3511 | down */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* key */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* menu */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Menus_HandleOOBClick\n"
        "movl $0, inHandleKey\n" /* line 3512 */
        "jmp .Lf16debe_0016dfb8\n"
        /* } scope */
        ".Lf16debe_0016e126:\n"
        "movl $0, -0x31c(%ebp)\n" /* line 3521 | item */
        "movl 0x10(%ebp), %eax\n" /* line 3531 | key */
        "subl $0xcd, %eax\n"
        "cmpl $1, %eax\n"
        "ja .Lf16debe_0016df56\n"
        ".Lf16debe_0016e141:\n"
        "movl -0x31c(%ebp), %eax\n" /* item */
        "testl %eax, %eax\n"
        "je .Lf16debe_0016dfb8\n"
        "movl -0x31c(%ebp), %eax\n" /* item */
        "cmpl $6, 0x270(%eax)\n"
        "jne .Lf16debe_0016dfb8\n"
        "jmp .Lf16debe_0016df64\n"
        ".Lf16debe_0016e167:\n"
        "movl 0x14(%ebp), %eax\n" /* line 3545 | down */
        "testl %eax, %eax\n"
        "je .Lf16debe_0016dfb8\n"
        "movl 0x10(%ebp), %eax\n" /* line 3552 | key */
        "subl $1, %eax\n"
        "cmpl $0xfe, %eax\n"
        "jbe .Lf16debe_0016e208\n"
        ".Lf16debe_0016e183:\n"
        "cmpl $0xb1, 0x10(%ebp)\n" /* line 3561 | key */
        "je .Lf16debe_0016e22b\n"
        "jg .Lf16debe_0016e24b\n"
        "cmpl $0x9a, 0x10(%ebp)\n" /* key */
        "je .Lf16debe_0016e3c5\n"
        "jg .Lf16debe_0016e367\n"
        "cmpl $0xd, 0x10(%ebp)\n" /* key */
        "je .Lf16debe_0016e27f\n"
        "cmpl $0x1b, 0x10(%ebp)\n" /* key */
        "je .Lf16debe_0016e6f0\n"
        "cmpl $9, 0x10(%ebp)\n" /* key */
        "jne .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e1c7:\n"
        "movl %esi, 4(%esp)\n" /* line 3612 | menu */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Menu_SetNextCursorItem\n"
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e1db:\n"
        "movl 0x14(%ebp), %eax\n" /* line 3466 | down */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* key */
        "movl %edx, 8(%esp)\n"
        "movl g_bindItem, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_Bind_HandleKey\n"
        /* } scope */
        "addl $0x33c, %esp\n" /* line 3691 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: it */
        ".Lf16debe_0016e208:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3554 | key */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* menu */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_CheckOnKey\n"
        "testl %eax, %eax\n"
        "je .Lf16debe_0016e183\n"
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e22b:\n"
        "movl $str_002167f8, (%esp)\n" /* line 3565 */
        "calll Dvar_GetInt\n"
        "testl %eax, %eax\n"
        "je .Lf16debe_0016dfb8\n"
        "xorl $1, debugMode\n" /* line 3566 */
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e24b:\n"
        "cmpl $0xc9, 0x10(%ebp)\n" /* line 3561 | key */
        "jg .Lf16debe_0016e33f\n"
        "cmpl $0xc8, 0x10(%ebp)\n" /* key */
        "jge .Lf16debe_0016e3d9\n"
        "cmpl $0xb2, 0x10(%ebp)\n" /* key */
        "je .Lf16debe_0016e732\n"
        "cmpl $0xbf, 0x10(%ebp)\n" /* key */
        "jne .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e27f:\n"
        "movl -0x31c(%ebp), %ecx\n" /* line 3674 | item */
        "testl %ecx, %ecx\n"
        "je .Lf16debe_0016dfb8\n"
        "movl -0x31c(%ebp), %eax\n" /* line 2525 | item */
        "cmpl $0x12, 0x270(%eax)\n"
        "ja .Lf16debe_0016e6e9\n"
        "movl 0x270(%eax), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x70210, %eax\n"
        "je .Lf16debe_0016df99\n"
        "movl $0, 4(%esp)\n" /* line 3678 */
        "movl -0x31c(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Item_SetCursorPos\n"
        "movl $1, g_editingField\n" /* line 3679 */
        "movl -0x31c(%ebp), %eax\n" /* line 3680 | item */
        "movl %eax, g_editItem\n"
        "movl $1, (%esp)\n" /* line 3681 */
        "calll Key_SetOverstrikeMode\n"
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e2f4:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3480 | key */
        "subl $0xc8, %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf16debe_0016dfb8\n"
        "movl $0, g_editingField\n" /* line 3482 */
        "movl $0, g_editItem\n" /* line 3483 */
        "movl 8(%ebp), %edx\n" /* line 3485 | dc */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Display_MouseMove\n"
        "jmp .Lf16debe_0016deef\n"
        ".Lf16debe_0016e33f:\n"
        "cmpl $0xcd, 0x10(%ebp)\n" /* line 3561 | key */
        "je .Lf16debe_0016e1c7\n"
        "cmpl $0xce, 0x10(%ebp)\n" /* key */
        "je .Lf16debe_0016e3c5\n"
        "cmpl $0xca, 0x10(%ebp)\n" /* key */
        "jne .Lf16debe_0016dfb8\n"
        "jmp .Lf16debe_0016e27f\n"
        ".Lf16debe_0016e367:\n"
        "cmpl $0x9c, 0x10(%ebp)\n" /* key */
        "je .Lf16debe_0016e3c5\n"
        "jl .Lf16debe_0016e1c7\n"
        "cmpl $0x9d, 0x10(%ebp)\n" /* key */
        "jne .Lf16debe_0016dfb8\n"
        "jmp .Lf16debe_0016e1c7\n"
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        ".Lf16debe_0016e388:\n"
        "addss -0x30c(%ebp), %xmm0\n" /* line 430 */
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16debe_0016e0d2\n"
        "movss -0x310(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16debe_0016e0d2\n"
        "addss -0x308(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jae .Lf16debe_0016df02\n"
        "jmp .Lf16debe_0016e0d2\n"
        /* } scope */
        /* } scope */
        ".Lf16debe_0016e3c5:\n"
        "movl %esi, 4(%esp)\n" /* line 3577 | menu */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Menu_SetPrevCursorItem\n"
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e3d9:\n"
        "movl -0x31c(%ebp), %esi\n" /* line 3630 | item, menu */
        "testl %esi, %esi\n" /* menu */
        "je .Lf16debe_0016dfb8\n"
        "movl -0x31c(%ebp), %eax\n" /* line 3632 | item */
        "movl 0x270(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf16debe_0016e574\n"
        "movl 8(%ebp), %edx\n" /* line 3634 | dc */
        "cvtsi2ssl 0x10(%edx), %xmm2\n" /* y */
        "cvtsi2ssl 0xc(%edx), %xmm1\n" /* x */
        "movl $rect, %edi\n" /* line 3383 */
        "cld\n"
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x31c(%ebp), %edx\n" /* line 3387 | item */
        "movl 0x210(%edx), %eax\n"
        "movl %eax, rect\n"
        "movl 0x214(%edx), %eax\n"
        "movl %eax, rect+4\n"
        "movl 0x218(%edx), %eax\n"
        "movl %eax, rect+8\n"
        "movl 0x21c(%edx), %eax\n"
        "movl %eax, rect+12\n"
        "movl 0x220(%edx), %eax\n"
        "movl %eax, rect+16\n"
        "movl 0x224(%edx), %eax\n"
        "movl %eax, rect+20\n"
        "pxor %xmm0, %xmm0\n" /* line 3388 */
        "ucomiss rect+8, %xmm0\n"
        "jp .Lf16debe_0016e472\n"
        "je .Lf16debe_0016e75f\n"
        ".Lf16debe_0016e472:\n"
        "movss rect+4, %xmm0\n" /* line 3390 */
        "subss rect+12, %xmm0\n"
        "movss %xmm0, rect+4\n"
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        ".Lf16debe_0016e48a:\n"
        "movl rect, %eax\n" /* line 417 */
        "movl %eax, -0x314(%ebp)\n" /* compareRect */
        "movss %xmm0, -0x310(%ebp)\n" /* line 418 */
        "movl rect+8, %eax\n" /* line 419 */
        "movl %eax, -0x30c(%ebp)\n"
        "movl rect+12, %eax\n" /* line 420 */
        "movl %eax, -0x308(%ebp)\n"
        "movss %xmm1, -0x20(%ebp)\n" /* line 422 | compareY */
        "movss %xmm2, -0x1c(%ebp)\n" /* line 423 | compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl rect+20, %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl rect+16, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x314(%ebp), %edx\n" /* compareRect */
        "leal -0x308(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x310(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x314(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16debe_0016dfb8\n"
        "addss -0x30c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16debe_0016dfb8\n"
        "movss -0x310(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16debe_0016dfb8\n"
        "addss -0x308(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16debe_0016dfb8\n"
        "jmp .Lf16debe_0016df99\n"
        /* } scope */
        /* } scope */
        ".Lf16debe_0016e574:\n"
        "movl 8(%ebp), %edx\n" /* line 3639 | dc */
        "cvtsi2ssl 0x10(%edx), %xmm1\n" /* y */
        "cvtsi2ssl 0xc(%edx), %xmm0\n" /* x */
        /* { scope 2: compareRect, compareX, compareY */
        /* { scope 3 */
        "movl -0x31c(%ebp), %edx\n" /* line 417 | item */
        "movl (%edx), %eax\n"
        "movl %eax, -0x314(%ebp)\n" /* compareRect */
        "movl 4(%edx), %eax\n" /* line 418 */
        "movl %eax, -0x310(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 419 */
        "movl %eax, -0x30c(%ebp)\n"
        "movl 0xc(%edx), %eax\n" /* line 420 */
        "movl %eax, -0x308(%ebp)\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 422 | compareY */
        "movss %xmm1, -0x1c(%ebp)\n" /* line 423 | compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenY\n"
        "movl -0x31c(%ebp), %edx\n" /* line 428 | item */
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x314(%ebp), %edx\n" /* compareRect */
        "leal -0x308(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal -0x30c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x310(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x314(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16debe_0016dfb8\n"
        "addss -0x30c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16debe_0016dfb8\n"
        "movss -0x310(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16debe_0016dfb8\n"
        "addss -0x308(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16debe_0016dfb8\n"
        /* } scope */
        /* } scope */
        "movl -0x31c(%ebp), %eax\n" /* line 2525 | item */
        "cmpl $0x12, 0x270(%eax)\n"
        "ja .Lf16debe_0016df99\n"
        "movl 0x270(%eax), %ecx\n"
        "movl $1, %eax\n"
        "shll %cl, %eax\n"
        "testl $0x70210, %eax\n"
        "je .Lf16debe_0016df99\n"
        /* { scope 2: compareRect, compareX, compareY */
        "movl -0x31c(%ebp), %edx\n" /* line 2544 | item */
        "movl %edx, (%esp)\n"
        "calll Item_GetEditFieldDef\n"
        "testl %eax, %eax\n" /* line 2545 */
        "je .Lf16debe_0016e6ac\n"
        "movl $0, 0x1c(%eax)\n" /* line 2546 */
        ".Lf16debe_0016e6ac:\n"
        "movl $0, 4(%esp)\n" /* line 2548 */
        "movl -0x31c(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Item_SetCursorPos\n"
        "movl $1, g_editingField\n" /* line 2549 */
        "movl -0x31c(%ebp), %edx\n" /* line 2550 | item */
        "movl %edx, g_editItem\n"
        "movl $1, (%esp)\n" /* line 2552 */
        "calll Key_SetOverstrikeMode\n"
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e6e9:\n"
        "movl %eax, %edx\n"
        "jmp .Lf16debe_0016df9f\n"
        /* } scope */
        ".Lf16debe_0016e6f0:\n"
        "movl g_waitingForKey, %eax\n" /* line 3598 */
        "testl %eax, %eax\n"
        "jne .Lf16debe_0016dfb8\n"
        "movl 0x24c(%esi), %edi\n" /* menu */
        "testl %edi, %edi\n"
        "je .Lf16debe_0016dfb8\n"
        /* { scope 2: compareRect, compareX, compareY */
        "movl %esi, -0x78(%ebp)\n" /* line 3602 | menu */
        "movl 0x24c(%esi), %eax\n" /* line 3603 | menu */
        "movl %eax, 8(%esp)\n"
        "leal -0x314(%ebp), %eax\n" /* compareRect */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        "jmp .Lf16debe_0016dfb8\n"
        /* } scope */
        ".Lf16debe_0016e732:\n"
        "movl $str_002167f8, (%esp)\n" /* line 3570 */
        "calll Dvar_GetInt\n"
        "testl %eax, %eax\n"
        "je .Lf16debe_0016dfb8\n"
        "movl $str_002ac37c, 4(%esp)\n" /* line 3571 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        "jmp .Lf16debe_0016dfb8\n"
        ".Lf16debe_0016e75f:\n"
        "movss rect+4, %xmm0\n"
        "jmp .Lf16debe_0016e48a\n"
    );
}

/* line 5107 */
__attribute__((naked))
void Item_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5107 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xac, %esp\n"
        /* DIAG: trace entry */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll diag_item_paint_enter\n"
        /* { scope 1: color, ry, w, h, ... */
        "movl 0xc(%ebp), %eax\n" /* line 5118 | item */
        "movl 0x29c(%eax), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* parent */
        "movl 0xc(%ebp), %edx\n" /* line 5124 | item */
        "movl 0xe8(%edx), %eax\n"
        "testb $0x20, %ah\n"
        "je .Lf16e76c_0016e7a6\n"
        "movl %edx, %ebx\n" /* enumDvar */
        "movl 8(%ebp), %ecx\n" /* line 5126 | dc */
        "movl 4(%ecx), %edx\n"
        "cmpl 0x1c8(%ebx), %edx\n" /* enumDvar */
        "jg .Lf16e76c_0016eb19\n"
        ".Lf16e76c_0016e7a6:\n"
        "testb %al, %al\n" /* line 5150 */
        "jns .Lf16e76c_0016e8d4\n"
        "movl 8(%ebp), %ecx\n" /* line 5152 | dc */
        "movl 4(%ecx), %eax\n"
        "movl 0xc(%ebp), %ebx\n" /* item, enumDvar */
        "cmpl 0x1c8(%ebx), %eax\n" /* enumDvar */
        "jg .Lf16e76c_0016e98b\n"
        "movl %ebx, %ecx\n" /* enumDvar */
        "movl 0xdc(%ecx), %eax\n" /* line 5278 */
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016e8e5\n"
        ".Lf16e76c_0016e7d3:\n"
        "movl %eax, (%esp)\n" /* line 5280 */
        "calll UI_OwnerDrawVisible\n"
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016eafe\n"
        "movl $4, 4(%esp)\n" /* line 5286 */
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "testb $0xc, 0x2d0(%edx)\n" /* line 5290 */
        "je .Lf16e76c_0016e8f4\n"
        ".Lf16e76c_0016e806:\n"
        "movl $4, 4(%esp)\n" /* line 5292 */
        "movl %edx, (%esp)\n"
        "calll Item_EnableShowViaDvar\n"
        "testl %eax, %eax\n"
        "jne .Lf16e76c_0016eaf6\n"
        "movl 0xc(%ebp), %ecx\n" /* line 143 | item */
        "movl 0xe8(%ecx), %eax\n"
        "testb $4, %al\n" /* line 155 */
        "je .Lf16e76c_0016e833\n"
        "testb $2, %al\n" /* line 5295 */
        "jne .Lf16e76c_0016eded\n"
        /* } scope */
        ".Lf16e76c_0016e833:\n"
        /* DIAG: item skipped/returned */
        "movl 0xc(%ebp), %eax\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll diag_item_paint_skip\n"
        "addl $0xac, %esp\n" /* line 5375 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: color, ry, w, h, ... */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016e83e:\n"
        "subss 0xc(%ecx), %xmm0\n" /* line 5258 */
        "movss %xmm0, -0x34(%ebp)\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5259 */
        "jbe .Lf16e76c_0016e855\n"
        "movss %xmm1, -0x34(%ebp)\n" /* line 5261 */
        ".Lf16e76c_0016e852:\n"
        "addl $1, %ebx\n" /* line 5262 | done */
        ".Lf16e76c_0016e855:\n"
        "leal -0x40(%ebp), %eax\n" /* line 5267 | newRect */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Window_SetRectClient\n"
        /* { scope 3 */
        "movl 0xc(%ebp), %ecx\n" /* line 355 | item */
        "movl 0x29c(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf16e76c_0016e8bc\n"
        "movss (%edx), %xmm2\n" /* line 363 */
        "movss 4(%edx), %xmm1\n" /* line 364 */
        "movl 0xd4(%edx), %ecx\n" /* line 366 */
        "testl %ecx, %ecx\n"
        "je .Lf16e76c_0016e897\n"
        "movss 0xe0(%edx), %xmm0\n" /* line 368 */
        "addss %xmm0, %xmm2\n"
        "addss %xmm0, %xmm1\n" /* line 369 */
        ".Lf16e76c_0016e897:\n"
        "movl 0x14(%edx), %eax\n" /* line 372 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm2, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll Item_SetScreenCoords\n"
        /* } scope */
        ".Lf16e76c_0016e8bc:\n"
        "cmpl $4, %ebx\n" /* line 5270 | done */
        "jne .Lf16e76c_0016e8d4\n"
        "movl $0x80, 4(%esp)\n" /* line 5272 */
        "movl 0xc(%ebp), %edx\n" /* item */
        "movl %edx, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        ".Lf16e76c_0016e8d4:\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        /* } scope */
        "movl 0xdc(%ecx), %eax\n" /* line 5278 */
        "testl %eax, %eax\n"
        "jne .Lf16e76c_0016e7d3\n"
        ".Lf16e76c_0016e8e5:\n"
        "movl %ecx, %edx\n"
        ".Lf16e76c_0016e8e7:\n"
        "testb $0xc, 0x2d0(%edx)\n" /* line 5290 */
        "jne .Lf16e76c_0016e806\n"
        ".Lf16e76c_0016e8f4:\n"
        "movl %edx, %ecx\n"
        ".Lf16e76c_0016e8f6:\n"
        "testb $4, 0xe8(%ecx)\n" /* line 5304 */
        "je .Lf16e76c_0016e833\n"
        "cmpl $6, 0xd0(%ecx)\n" /* line 5310 */
        "je .Lf16e76c_0016ed0e\n"
        ".Lf16e76c_0016e910:\n"
        /* DIAG: item will be drawn */
        "movl 0xc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll diag_item_paint_draw\n"
        "movl -0x70(%ebp), %eax\n" /* line 5316 | parent */
        "cvtsi2ssl 0x230(%eax), %xmm0\n"
        "movss %xmm0, 0x14(%esp)\n"
        "movl %eax, %edx\n"
        "movl 0x234(%eax), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x23c(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x238(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "movl %ecx, 4(%esp)\n"
        "movl 8(%ebp), %ebx\n" /* dc, done */
        "movl %ebx, (%esp)\n" /* done */
        "calll Window_Paint\n"
        "movl debugMode, %edx\n" /* line 5318 */
        "testl %edx, %edx\n"
        "jne .Lf16e76c_0016ea07\n"
        "movl 0xc(%ebp), %ecx\n" /* line 5329 | item */
        "cmpl $6, 0xd0(%ecx)\n"
        "je .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016e971:\n"
        "cmpl $0x12, 0x270(%ecx)\n" /* line 5332 */
        "ja .Lf16e76c_0016e833\n"
        "movl 0x270(%ecx), %eax\n"
        "jmpl *.Ljt_16e76c_0(, %eax, 4)\n"
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016e98b:\n"
        "addl 0x1b8(%ebx), %eax\n" /* line 5156 | done */
        "movl %eax, 0x1c8(%ebx)\n" /* done */
        "movl %ebx, %edx\n" /* line 67 */
        "addl $0xf8, %edx\n"
        "movl %ebx, %ecx\n" /* line 74 */
        "addl $0x158, %ecx\n"
        "movl 0x60(%ebx), %eax\n" /* line 5162 | done */
        "movl %eax, -0x40(%ebp)\n" /* newRect */
        "movl 0x64(%ebx), %eax\n" /* done */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 0x68(%ebx), %eax\n" /* done */
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x6c(%ebx), %eax\n" /* done */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x70(%ebx), %eax\n" /* done */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x74(%ebx), %eax\n" /* done */
        "movl %eax, -0x2c(%ebp)\n"
        "movss -0x40(%ebp), %xmm0\n" /* line 5166 | newRect */
        "movss 0xf8(%ebx), %xmm1\n" /* done */
        "ucomiss %xmm1, %xmm0\n"
        "je .Lf16e76c_0016ec8d\n"
        ".Lf16e76c_0016e9e1:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5172 */
        "jbe .Lf16e76c_0016ed3c\n"
        "addss (%ecx), %xmm0\n" /* line 5174 */
        "movss %xmm0, -0x40(%ebp)\n" /* newRect */
        "movss (%edx), %xmm1\n" /* line 5175 */
        "ucomiss %xmm1, %xmm0\n"
        "ja .Lf16e76c_0016ed52\n"
        ".Lf16e76c_0016ea00:\n"
        "xorl %ebx, %ebx\n" /* line 5186 | done */
        "jmp .Lf16e76c_0016ec98\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016ea07:\n"
        "movl $rect, %edi\n" /* line 3383 */
        "cld\n"
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl 0xc(%ebp), %edx\n" /* line 3387 | item */
        "movl 0x210(%edx), %eax\n"
        "movl %eax, rect\n"
        "movl 0x214(%edx), %eax\n"
        "movl %eax, rect+4\n"
        "movl 0x218(%edx), %eax\n"
        "movl %eax, rect+8\n"
        "movl 0x21c(%edx), %eax\n"
        "movl %eax, rect+12\n"
        "movl 0x220(%edx), %eax\n"
        "movl %eax, rect+16\n"
        "movl 0x224(%edx), %eax\n"
        "movl %eax, rect+20\n"
        "pxor %xmm0, %xmm0\n" /* line 3388 */
        "ucomiss rect+8, %xmm0\n"
        "jp .Lf16e76c_0016ea6e\n"
        "je .Lf16e76c_0016eda6\n"
        ".Lf16e76c_0016ea6e:\n"
        "movss rect+4, %xmm0\n" /* line 3390 */
        "subss rect+12, %xmm0\n"
        "movss %xmm0, rect+4\n"
        ".Lf16e76c_0016ea86:\n"
        "movl $0x3f800000, %edx\n" /* line 5323 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl $0, -0x20(%ebp)\n" /* line 5324 */
        "movl $0, -0x28(%ebp)\n" /* color */
        "leal -0x28(%ebp), %eax\n" /* line 5325 | color */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl rect+20, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl rect+16, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl rect+12, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl rect+8, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movl rect, %eax\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawRect\n"
        /* } scope */
        "movl 0xc(%ebp), %ecx\n" /* line 5329 | item */
        "cmpl $6, 0xd0(%ecx)\n"
        "jne .Lf16e76c_0016e971\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016eaf6:\n"
        "movl 0xc(%ebp), %ecx\n" /* item */
        "jmp .Lf16e76c_0016e8f6\n"
        ".Lf16e76c_0016eafe:\n"
        "movl $4, 4(%esp)\n" /* line 5282 */
        "movl 0xc(%ebp), %ebx\n" /* item, done */
        "movl %ebx, (%esp)\n" /* done */
        "calll Window_RemoveDynamicFlags\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "jmp .Lf16e76c_0016e8e7\n"
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016eb19:\n"
        "addl 0x1b8(%ebx), %edx\n" /* line 5130 | enumDvar */
        "movl %edx, 0x1c8(%ebx)\n" /* enumDvar */
        "movl 0xc(%ebp), %ebx\n" /* line 60 | item */
        "addl $0x60, %ebx\n"
        "movl 0xc(%ebp), %edi\n" /* line 67 | item */
        "addl $0xf8, %edi\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 5136 | 0.5f */
        "movss 8(%ebx), %xmm1\n" /* enumDvar */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x68(%ebp)\n" /* w */
        "movss %xmm0, -0x64(%ebp)\n" /* line 5137 | h */
        "mulss 0xc(%ebx), %xmm0\n" /* enumDvar */
        "movss %xmm0, -0x64(%ebp)\n" /* h */
        "movaps %xmm1, %xmm2\n" /* line 5138 */
        "movl 0xc(%ebp), %eax\n" /* item */
        "addss 0x60(%eax), %xmm2\n"
        "subss 0xf8(%eax), %xmm2\n"
        "addss 4(%ebx), %xmm0\n" /* line 5139 | enumDvar */
        "movss %xmm0, -0x6c(%ebp)\n" /* ry */
        "subss 4(%edi), %xmm0\n"
        "movss %xmm0, -0x6c(%ebp)\n" /* ry */
        "movl $0x3d567750, %esi\n" /* line 485 */
        "movl %esi, (%esp)\n"
        "movss %xmm2, -0x88(%ebp)\n"
        "calll sinf\n"
        "fstps -0x74(%ebp)\n"
        "movl %esi, (%esp)\n" /* line 486 */
        "calll cosf\n"
        "fstps -0x8c(%ebp)\n"
        "movss -0x8c(%ebp), %xmm3\n"
        "movl 8(%ebx), %eax\n" /* line 5142 | enumDvar */
        "movl %eax, -0x38(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* enumDvar */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* enumDvar */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* enumDvar */
        "movl %eax, -0x2c(%ebp)\n"
        "movss -0x88(%ebp), %xmm2\n" /* line 5143 */
        "movaps %xmm2, %xmm0\n"
        "mulss %xmm3, %xmm0\n"
        "movss -0x6c(%ebp), %xmm1\n" /* ry */
        "mulss -0x74(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movl 0xc(%ebp), %edx\n" /* item */
        "addss 0xf8(%edx), %xmm0\n"
        "subss -0x68(%ebp), %xmm0\n" /* w */
        "movss %xmm0, -0x40(%ebp)\n" /* newRect */
        "mulss -0x74(%ebp), %xmm2\n" /* line 5144 */
        "mulss -0x6c(%ebp), %xmm3\n" /* ry */
        "movss %xmm3, -0x6c(%ebp)\n" /* ry */
        "addss %xmm3, %xmm2\n"
        "addss 4(%edi), %xmm2\n"
        "subss -0x64(%ebp), %xmm2\n" /* h */
        "movss %xmm2, -0x3c(%ebp)\n"
        "leal -0x40(%ebp), %eax\n" /* line 5145 | newRect */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Window_SetRectClient\n"
        /* { scope 3 */
        "movl 0xc(%ebp), %ecx\n" /* line 355 | item */
        "movl 0x29c(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf16e76c_0016ef8f\n"
        "movss (%edx), %xmm2\n" /* line 363 */
        "movss 4(%edx), %xmm1\n" /* line 364 */
        "movl 0xd4(%edx), %ebx\n" /* line 366 */
        "testl %ebx, %ebx\n"
        "je .Lf16e76c_0016ec5d\n"
        "movss 0xe0(%edx), %xmm0\n" /* line 368 */
        "addss %xmm0, %xmm2\n"
        "addss %xmm0, %xmm1\n" /* line 369 */
        ".Lf16e76c_0016ec5d:\n"
        "movl 0x14(%edx), %eax\n" /* line 372 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movss %xmm1, 8(%esp)\n"
        "movss %xmm2, 4(%esp)\n"
        "movl 0xc(%ebp), %ebx\n" /* item */
        "movl %ebx, (%esp)\n"
        "calll Item_SetScreenCoords\n"
        "movl 0xe8(%ebx), %eax\n"
        "jmp .Lf16e76c_0016e7a6\n"
        /* } scope */
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016ec8d:\n"
        "jp .Lf16e76c_0016e9e1\n" /* line 5166 */
        ".Lf16e76c_0016ec93:\n"
        "movl $1, %ebx\n" /* line 5186 | done */
        ".Lf16e76c_0016ec98:\n"
        "movss -0x3c(%ebp), %xmm0\n" /* line 5191 */
        "movss 4(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf16e76c_0016ed81\n"
        "jp .Lf16e76c_0016ed81\n"
        ".Lf16e76c_0016ecb1:\n"
        "addl $1, %ebx\n" /* line 5212 | done */
        ".Lf16e76c_0016ecb4:\n"
        "movss -0x38(%ebp), %xmm0\n" /* line 5216 */
        "movss 8(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf16e76c_0016ed5c\n"
        "jp .Lf16e76c_0016ed5c\n"
        ".Lf16e76c_0016eccd:\n"
        "addl $1, %ebx\n" /* line 5237 | done */
        ".Lf16e76c_0016ecd0:\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 5241 */
        "movss 0xc(%edx), %xmm1\n"
        "ucomiss %xmm1, %xmm0\n"
        "jne .Lf16e76c_0016ece5\n"
        "jnp .Lf16e76c_0016e852\n"
        ".Lf16e76c_0016ece5:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5247 */
        "jbe .Lf16e76c_0016e83e\n"
        "addss 0xc(%ecx), %xmm0\n" /* line 5249 */
        "movss %xmm0, -0x34(%ebp)\n"
        "ucomiss %xmm1, %xmm0\n" /* line 5250 */
        "jbe .Lf16e76c_0016e855\n"
        "movss %xmm1, -0x34(%ebp)\n" /* line 5252 */
        "addl $1, %ebx\n" /* line 5253 | done */
        "jmp .Lf16e76c_0016e855\n"
        /* } scope */
        ".Lf16e76c_0016ed0e:\n"
        "movl 0x2f0(%ecx), %ebx\n" /* line 5312 | done */
        "movl 0x2c0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetString\n"
        "movl %ebx, 4(%esp)\n" /* done */
        "movl %eax, (%esp)\n"
        "calll CL_RegisterMaterialNoMip\n"
        "movl 0xc(%ebp), %ebx\n" /* item, done */
        "movl %eax, 0x20c(%ebx)\n" /* done */
        "jmp .Lf16e76c_0016e910\n"
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016ed3c:\n"
        "subss (%ecx), %xmm0\n" /* line 5183 */
        "movss %xmm0, -0x40(%ebp)\n" /* newRect */
        "movss (%edx), %xmm1\n" /* line 5184 */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf16e76c_0016ea00\n"
        ".Lf16e76c_0016ed52:\n"
        "movss %xmm1, -0x40(%ebp)\n" /* line 5186 | newRect */
        "jmp .Lf16e76c_0016ec93\n"
        ".Lf16e76c_0016ed5c:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5222 */
        "jbe .Lf16e76c_0016edb3\n"
        "addss 8(%ecx), %xmm0\n" /* line 5224 */
        "movss %xmm0, -0x38(%ebp)\n"
        "ucomiss %xmm1, %xmm0\n" /* line 5225 */
        "jbe .Lf16e76c_0016ecd0\n"
        "movss %xmm1, -0x38(%ebp)\n" /* line 5227 */
        "addl $1, %ebx\n" /* line 5228 | done */
        "jmp .Lf16e76c_0016ecd0\n"
        ".Lf16e76c_0016ed81:\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5197 */
        "jbe .Lf16e76c_0016edd0\n"
        "addss 4(%ecx), %xmm0\n" /* line 5199 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "ucomiss %xmm1, %xmm0\n" /* line 5200 */
        "jbe .Lf16e76c_0016ecb4\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* line 5202 */
        "addl $1, %ebx\n" /* line 5203 | done */
        "jmp .Lf16e76c_0016ecb4\n"
        ".Lf16e76c_0016eda6:\n"
        "movss rect+4, %xmm0\n"
        "jmp .Lf16e76c_0016ea86\n"
        ".Lf16e76c_0016edb3:\n"
        "subss 8(%ecx), %xmm0\n" /* line 5233 */
        "movss %xmm0, -0x38(%ebp)\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5234 */
        "jbe .Lf16e76c_0016ecd0\n"
        "movss %xmm1, -0x38(%ebp)\n" /* line 5236 */
        "jmp .Lf16e76c_0016eccd\n"
        ".Lf16e76c_0016edd0:\n"
        "subss 4(%ecx), %xmm0\n" /* line 5208 */
        "movss %xmm0, -0x3c(%ebp)\n"
        "ucomiss %xmm0, %xmm1\n" /* line 5209 */
        "jbe .Lf16e76c_0016ecb4\n"
        "movss %xmm1, -0x3c(%ebp)\n" /* line 5211 */
        "jmp .Lf16e76c_0016ecb1\n"
        /* } scope */
        ".Lf16e76c_0016eded:\n"
        "movl $1, 0xc(%esp)\n" /* line 5297 */
        "movl $0x9b, 8(%esp)\n"
        "movl -0x70(%ebp), %ebx\n" /* parent, done */
        "movl %ebx, 4(%esp)\n" /* done */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_HandleKey\n"
        "movl $0, 0xc(%esp)\n" /* line 5298 */
        "movl $0x9b, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* done */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Menu_HandleKey\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016ee33:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 5350 | item, done */
        "movl %ebx, 4(%esp)\n" /* done */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_TextField_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016ee4a:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 5367 | item, done */
        "movl %ebx, 4(%esp)\n" /* done */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_Bind_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016ee61:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 5335 | item, done */
        "movl %ebx, 4(%esp)\n" /* done */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_OwnerDraw_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016ee78:\n"
        "movl 0xc(%ebp), %edx\n" /* line 5355 | item */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl %ecx, (%esp)\n"
        "calll Item_ListBox_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016ee8f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 5339 | item */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl %ecx, (%esp)\n"
        "calll Item_Text_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016eea6:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2436 | item */
        "movl 0x2ec(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016efe6\n"
        "movl %eax, (%esp)\n" /* line 2439 */
        "calll Dvar_FindVar\n"
        "movl %eax, %ebx\n" /* enumDvar */
        "cmpb $6, 6(%eax)\n" /* line 2440 */
        "je .Lf16e76c_0016effa\n"
        "movl $str_002ac3c8, %ecx\n" /* "<not an enum dvar>" */
        /* } scope */
        ".Lf16e76c_0016eed0:\n"
        "movl 0xc(%ebp), %edx\n" /* line 4176 | item */
        "movl 8(%ebp), %eax\n" /* dc */
        "calll Item_List_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016eee0:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2378 | item */
        "movl %edx, (%esp)\n"
        "calll Item_GetMultiDef\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 2379 */
        "je .Lf16e76c_0016eff0\n"
        "movl 0x184(%eax), %eax\n" /* line 2382 */
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016ef9a\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2384 | item */
        "movl 0x2c0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, -0x58(%ebp)\n" /* string */
        "movl 0x180(%esi), %eax\n" /* line 2385 */
        "testl %eax, %eax\n"
        "jg .Lf16e76c_0016ef56\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016ef21:\n"
        "movl $str_002157b8, %ecx\n" /* line 2443 */
        "jmp .Lf16e76c_0016eed0\n"
        /* } scope */
        ".Lf16e76c_0016ef28:\n"
        "movl 0xc(%ebp), %ebx\n" /* line 5358 | item, done */
        "movl %ebx, 4(%esp)\n" /* done */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_YesNo_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        ".Lf16e76c_0016ef3f:\n"
        "movl 0xc(%ebp), %edx\n" /* line 5370 | item */
        "movl %edx, 4(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl %ecx, (%esp)\n"
        "calll Item_Slider_Paint\n"
        "jmp .Lf16e76c_0016e833\n"
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016ef56:\n"
        "movl %esi, %ebx\n" /* line 2385 */
        "xorl %edi, %edi\n"
        ".Lf16e76c_0016ef5a:\n"
        "movl 0x80(%ebx), %eax\n" /* line 2387 */
        "movl %eax, 4(%esp)\n"
        "movl -0x58(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016f086\n"
        "addl $1, %edi\n" /* line 2385 */
        "addl $4, %ebx\n"
        "cmpl 0x180(%esi), %edi\n"
        "jl .Lf16e76c_0016ef5a\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        "movl $str_002157b8, %ecx\n" /* line 2443 */
        "jmp .Lf16e76c_0016eed0\n"
        ".Lf16e76c_0016ef8f:\n"
        "movl 0xe8(%ecx), %eax\n"
        "jmp .Lf16e76c_0016e7a6\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016ef9a:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2393 | item */
        "movl 0x2c0(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x60(%ebp)\n"
        "cvtsd2ss -0x60(%ebp), %xmm1\n"
        "movl 0x180(%esi), %ecx\n" /* line 2394 */
        "testl %ecx, %ecx\n"
        "jle .Lf16e76c_0016ef21\n"
        "ucomiss 0x100(%esi), %xmm1\n" /* line 2396 */
        "jne .Lf16e76c_0016f05d\n"
        "jp .Lf16e76c_0016f05d\n"
        "xorl %eax, %eax\n"
        "movl (%esi, %eax, 4), %ecx\n" /* line 2397 */
        "jmp .Lf16e76c_0016eed0\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016efe6:\n"
        "movl $str_002ac3b0, %ecx\n" /* line 2436 */
        "jmp .Lf16e76c_0016eed0\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016eff0:\n"
        "movl $str_002ac388, %ecx\n" /* line 2379 */
        "jmp .Lf16e76c_0016eed0\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016effa:\n"
        "movl 0x14(%eax), %eax\n" /* line 2443 */
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016ef21\n"
        /* { scope 3 */
        "movl 0xc(%ebp), %edx\n" /* line 2410 | item */
        "movl 0x2ec(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_FindVar\n"
        "movl %eax, -0x54(%ebp)\n" /* enumDvar */
        "cmpb $6, 6(%eax)\n" /* line 2411 */
        "je .Lf16e76c_0016f02c\n"
        ".Lf16e76c_0016f01f:\n"
        "xorl %edi, %edi\n" /* line 2419 */
        /* } scope */
        ".Lf16e76c_0016f021:\n"
        "movl 0x18(%ebx), %eax\n" /* line 2448 | enumDvar */
        "movl (%eax, %edi), %ecx\n"
        "jmp .Lf16e76c_0016eed0\n"
        /* { scope 3 */
        ".Lf16e76c_0016f02c:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2414 | item */
        "movl 0x2c0(%ecx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_GetVariantString\n"
        "movl %eax, -0x50(%ebp)\n" /* enumString */
        "movl %eax, (%esp)\n" /* line 2415 */
        "calll atoi\n"
        "testl %eax, %eax\n" /* line 2416 */
        "js .Lf16e76c_0016f08e\n"
        "movl -0x54(%ebp), %edx\n" /* enumDvar */
        "cmpl 0x14(%edx), %eax\n"
        "jge .Lf16e76c_0016f08e\n"
        "leal (, %eax, 4), %edi\n"
        "jmp .Lf16e76c_0016f021\n"
        /* } scope */
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        ".Lf16e76c_0016f05d:\n"
        "movl %esi, %edx\n" /* line 2396 */
        "xorl %eax, %eax\n"
        ".Lf16e76c_0016f061:\n"
        "addl $1, %eax\n" /* line 2394 */
        "cmpl %ecx, %eax\n"
        "je .Lf16e76c_0016ef21\n"
        "movss 0x104(%edx), %xmm0\n" /* line 2396 */
        "addl $4, %edx\n"
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf16e76c_0016f061\n"
        "jp .Lf16e76c_0016f061\n"
        "movl (%esi, %eax, 4), %ecx\n" /* line 2397 */
        "jmp .Lf16e76c_0016eed0\n"
        ".Lf16e76c_0016f086:\n"
        "movl (%esi, %edi, 4), %ecx\n" /* line 2388 */
        "jmp .Lf16e76c_0016eed0\n"
        /* } scope */
        /* { scope 2: enumDvar, enumString */
        /* { scope 3 */
        ".Lf16e76c_0016f08e:\n"
        "movl -0x54(%ebp), %eax\n" /* line 2419 | enumDvar */
        "movl 0x14(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf16e76c_0016f01f\n"
        "movl $0, -0x4c(%ebp)\n"
        "xorl %esi, %esi\n"
        ".Lf16e76c_0016f0a1:\n"
        "movl %esi, %edi\n" /* line 2416 */
        "movl -0x54(%ebp), %ecx\n" /* line 2421 | enumDvar */
        "movl 0x18(%ecx), %eax\n"
        "movl (%eax, %esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x50(%ebp), %eax\n" /* enumString */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf16e76c_0016f021\n"
        "addl $1, -0x4c(%ebp)\n" /* line 2419 */
        "addl $4, %esi\n"
        "movl -0x4c(%ebp), %ecx\n"
        "movl -0x54(%ebp), %edx\n" /* enumDvar */
        "cmpl %ecx, 0x14(%edx)\n"
        "jg .Lf16e76c_0016f0a1\n"
        "jmp .Lf16e76c_0016f01f\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_16e76c_0:\n"
        ".long .Lf16e76c_0016ee8f\n"
        ".long .Lf16e76c_0016ee8f\n"
        ".long .Lf16e76c_0016e833\n"
        ".long .Lf16e76c_0016e833\n"
        ".long .Lf16e76c_0016ee33\n"
        ".long .Lf16e76c_0016e833\n"
        ".long .Lf16e76c_0016ee78\n"
        ".long .Lf16e76c_0016e833\n"
        ".long .Lf16e76c_0016ee61\n"
        ".long .Lf16e76c_0016ee33\n"
        ".long .Lf16e76c_0016ef3f\n"
        ".long .Lf16e76c_0016ef28\n"
        ".long .Lf16e76c_0016eee0\n"
        ".long .Lf16e76c_0016eea6\n"
        ".long .Lf16e76c_0016ee4a\n"
        ".long .Lf16e76c_0016e833\n"
        ".long .Lf16e76c_0016ee33\n"
        ".long .Lf16e76c_0016ee33\n"
        ".long .Lf16e76c_0016ee33\n"
        ".text\n"
    );
}

/* line 5580 */
__attribute__((naked))
void Menu_Paint(displayContextDef_t *dc, menuDef_t *menu, qboolean forcePaint)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5580 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* menu */
        "movl 0x10(%ebp), %ebx\n" /* forcePaint */
        /* { scope 1: color */
        "testl %esi, %esi\n" /* line 5592 | menu */
        "je .Lf16f0da_0016f1e0\n"
        "testb $4, 0xe8(%esi)\n" /* line 5597 | menu */
        "je .Lf16f0da_0016f1e8\n"
        "movl 0xdc(%esi), %eax\n" /* line 5602 | menu */
        "testl %eax, %eax\n"
        "jne .Lf16f0da_0016f1fa\n"
        ".Lf16f0da_0016f10c:\n"
        "movl 0x254(%esi), %eax\n" /* line 5607 | menu */
        "testl %eax, %eax\n"
        "je .Lf16f0da_0016f11e\n"
        "movl %eax, (%esp)\n" /* line 5608 */
        "calll UI_PlayLocalSoundAliasByName\n"
        ".Lf16f0da_0016f11e:\n"
        "movss 0x240(%esi), %xmm1\n" /* line 5610 | menu */
        "ucomiss lit4_002ed5e8, %xmm1\n" /* 0.0f */
        "jp .Lf16f0da_0016f358\n"
        "jne .Lf16f0da_0016f358\n"
        "testl %ebx, %ebx\n" /* line 5613 | i */
        "jne .Lf16f0da_0016f299\n"
        ".Lf16f0da_0016f141:\n"
        "movl 0x214(%esi), %eax\n" /* line 5628 | menu */
        "testl %eax, %eax\n"
        "je .Lf16f0da_0016f18d\n"
        ".Lf16f0da_0016f14b:\n"
        "movl 0x20c(%esi), %eax\n" /* menu */
        "testl %eax, %eax\n"
        "je .Lf16f0da_0016f18d\n"
        "movl %eax, 0x1c(%esp)\n" /* line 5631 */
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* menu */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* menu */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x43f00000, 0xc(%esp)\n"
        "movl $0x44200000, 8(%esp)\n"
        "xorl %eax, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawHandlePic\n"
        ".Lf16f0da_0016f18d:\n"
        "cvtsi2ssl 0x230(%esi), %xmm0\n" /* line 5635 | menu */
        "movss %xmm0, 0x14(%esp)\n"
        "movl 0x234(%esi), %eax\n" /* menu */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x23c(%esi), %eax\n" /* menu */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x238(%esi), %eax\n" /* menu */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* menu */
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Window_Paint\n"
        "movl 0x218(%esi), %eax\n" /* line 5637 | menu */
        "testl %eax, %eax\n"
        "jg .Lf16f0da_0016f261\n"
        "movl debugMode, %edi\n" /* line 5642 */
        "testl %edi, %edi\n"
        "jne .Lf16f0da_0016f20c\n"
        /* } scope */
        ".Lf16f0da_0016f1e0:\n"
        "addl $0x3c, %esp\n" /* line 5656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: color */
        ".Lf16f0da_0016f1e8:\n"
        "testl %ebx, %ebx\n" /* line 5597 | i */
        "je .Lf16f0da_0016f1e0\n"
        "movl 0xdc(%esi), %eax\n" /* line 5602 | menu */
        "testl %eax, %eax\n"
        "je .Lf16f0da_0016f10c\n"
        ".Lf16f0da_0016f1fa:\n"
        "movl %eax, (%esp)\n"
        "calll UI_OwnerDrawVisible\n"
        "testl %eax, %eax\n"
        "jne .Lf16f0da_0016f10c\n"
        "jmp .Lf16f0da_0016f1e0\n"
        /* { scope 2 */
        ".Lf16f0da_0016f20c:\n"
        "movl $0x3f800000, %edx\n" /* line 5647 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl %edx, -0x28(%ebp)\n" /* color */
        "movl $0, -0x24(%ebp)\n" /* line 5648 */
        "leal -0x28(%ebp), %eax\n" /* line 5649 | color */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl 0x14(%esi), %eax\n" /* menu */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%esi), %eax\n" /* menu */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%esi), %eax\n" /* menu */
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%esi), %eax\n" /* menu */
        "movl %eax, 8(%esp)\n"
        "movl 4(%esi), %eax\n" /* menu */
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n" /* menu */
        "movl %eax, (%esp)\n"
        "calll UI_DrawRect\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 5656 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: color */
        ".Lf16f0da_0016f261:\n"
        "xorl %ebx, %ebx\n" /* line 5637 | i */
        ".Lf16f0da_0016f263:\n"
        "movl 0x27c(%esi), %eax\n" /* line 5639 | menu */
        "movl (%eax, %ebx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Item_Paint\n"
        "addl $1, %ebx\n" /* line 5637 | i */
        "cmpl 0x218(%esi), %ebx\n" /* menu, i */
        "jl .Lf16f0da_0016f263\n"
        "movl debugMode, %edi\n" /* line 5642 */
        "testl %edi, %edi\n"
        "je .Lf16f0da_0016f1e0\n"
        "jmp .Lf16f0da_0016f20c\n"
        ".Lf16f0da_0016f299:\n"
        "movl $0x4000, 4(%esp)\n" /* line 5615 */
        "movl %esi, (%esp)\n" /* menu */
        "calll Window_AddDynamicFlags\n"
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 710 | dc */
        "movl 0x270(%edx), %ebx\n"
        "subl $1, %ebx\n"
        "js .Lf16f0da_0016f382\n"
        "cmpl 0x230(%edx, %ebx, 4), %esi\n" /* line 712 */
        "je .Lf16f0da_0016f387\n"
        "leal 0x230(%edx, %ebx, 4), %ecx\n"
        "movl %ebx, %edi\n"
        "xorl %edx, %edx\n"
        ".Lf16f0da_0016f2d3:\n"
        "subl $1, %edi\n" /* line 710 */
        "cmpl %ebx, %edx\n"
        "je .Lf16f0da_0016f382\n"
        "movl -4(%ecx), %eax\n" /* line 712 */
        "addl $1, %edx\n"
        "subl $4, %ecx\n"
        "cmpl %eax, %esi\n"
        "jne .Lf16f0da_0016f2d3\n"
        ".Lf16f0da_0016f2eb:\n"
        "movl 8(%ebp), %eax\n" /* line 714 | dc */
        "movl %ebx, 0x270(%eax)\n"
        "cmpl %ebx, %edi\n" /* line 715 */
        "jge .Lf16f0da_0016f382\n"
        "leal 0x234(%eax, %edi, 4), %edx\n" /* line 5580 */
        "movl %edi, %ecx\n"
        "leal 0x230(%eax, %edi, 4), %ebx\n" /* forcePaint */
        "subl %edx, %ebx\n" /* forcePaint */
        ".Lf16f0da_0016f30e:\n"
        "addl $1, %ecx\n" /* line 716 */
        "movl (%edx), %eax\n"
        "movl %eax, (%ebx, %edx)\n"
        "addl $4, %edx\n"
        "movl 8(%ebp), %eax\n" /* line 715 | dc */
        "cmpl %ecx, 0x270(%eax)\n"
        "jg .Lf16f0da_0016f30e\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf16f0da_0016f326:\n"
        "cmpl $0x10, 0x270(%edx)\n" /* line 730 */
        "je .Lf16f0da_0016f38e\n"
        ".Lf16f0da_0016f32f:\n"
        "movl 0x270(%edx), %eax\n" /* line 733 */
        "movl %esi, 0x230(%edx, %eax, 4)\n"
        "addl $1, %eax\n" /* line 734 */
        "movl %eax, 0x270(%edx)\n"
        "movl 0x214(%esi), %eax\n" /* line 5628 | menu */
        "testl %eax, %eax\n"
        "je .Lf16f0da_0016f18d\n"
        "jmp .Lf16f0da_0016f14b\n"
        ".Lf16f0da_0016f358:\n"
        "movl 8(%ebp), %eax\n" /* line 5611 | dc */
        "movss 0x28(%eax), %xmm0\n"
        "mulss %xmm1, %xmm1\n"
        "mulss %xmm0, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "sqrtss %xmm1, %xmm0\n"
        "movss %xmm0, 0x28(%eax)\n"
        "testl %ebx, %ebx\n" /* line 5613 | i */
        "je .Lf16f0da_0016f141\n"
        "jmp .Lf16f0da_0016f299\n"
        ".Lf16f0da_0016f382:\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "jmp .Lf16f0da_0016f326\n"
        /* { scope 2 */
        ".Lf16f0da_0016f387:\n"
        "movl %ebx, %edi\n" /* line 712 */
        "jmp .Lf16f0da_0016f2eb\n"
        /* } scope */
        ".Lf16f0da_0016f38e:\n"
        "movl $str_002ac364, 4(%esp)\n" /* line 731 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "jmp .Lf16f0da_0016f32f\n"
    );
}

/* line 5665 */
__attribute__((naked))
void Menu_PaintAll(displayContextDef_t *dc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5665 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: color */
        "movl 8(%ebp), %eax\n" /* line 5671 | dc */
        "movl $0, 0x28(%eax)\n"
        "movl captureFunc, %edx\n" /* line 5673 */
        "testl %edx, %edx\n"
        "je .Lf16f3a8_0016f3d6\n"
        "movl captureData, %eax\n" /* line 5674 */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        ".Lf16f3a8_0016f3d6:\n"
        "movl 8(%ebp), %edx\n" /* line 5677 | dc */
        "movl 0x22c(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lf16f3a8_0016f54c\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl $0, -0x30(%ebp)\n" /* i */
        "movl 0x270(%edx), %edi\n"
        "movl %edx, %eax\n"
        "movl 0x2c(%eax), %esi\n" /* line 5679 | menu */
        /* { scope 2 */
        "movl %edi, %ebx\n" /* line 742 | i */
        "subl $1, %ebx\n" /* i */
        "js .Lf16f3a8_0016f44c\n"
        ".Lf16f3a8_0016f403:\n"
        "movl 8(%ebp), %edx\n" /* line 744 | dc */
        "cmpl 0x230(%edx, %ebx, 4), %esi\n"
        "je .Lf16f3a8_0016f42c\n"
        "leal 0x230(%edx, %ebx, 4), %edx\n"
        "xorl %ecx, %ecx\n"
        ".Lf16f3a8_0016f418:\n"
        "cmpl %ecx, %ebx\n" /* line 742 | i */
        "je .Lf16f3a8_0016f44c\n"
        "movl -4(%edx), %eax\n" /* line 744 */
        "addl $1, %ecx\n"
        "subl $4, %edx\n"
        "cmpl %eax, %esi\n"
        "jne .Lf16f3a8_0016f418\n"
        "movl 8(%ebp), %edx\n" /* dc */
        /* } scope */
        ".Lf16f3a8_0016f42c:\n"
        "addl $1, -0x30(%ebp)\n" /* line 5677 | i */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* i */
        "cmpl 0x22c(%edx), %eax\n"
        "jge .Lf16f3a8_0016f481\n"
        ".Lf16f3a8_0016f43f:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl 0x2c(%eax), %esi\n" /* line 5679 | menu */
        /* { scope 2 */
        "movl %edi, %ebx\n" /* line 742 | i */
        "subl $1, %ebx\n" /* i */
        "jns .Lf16f3a8_0016f403\n"
        /* } scope */
        ".Lf16f3a8_0016f44c:\n"
        "movl $0, 8(%esp)\n" /* line 5681 */
        "movl %esi, 4(%esp)\n" /* menu */
        "movl 8(%ebp), %edx\n" /* dc */
        "movl %edx, (%esp)\n"
        "calll Menu_Paint\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl 0x270(%eax), %edi\n"
        "movl %eax, %edx\n"
        "addl $1, -0x30(%ebp)\n" /* line 5677 | i */
        "addl $4, -0x2c(%ebp)\n"
        "movl -0x30(%ebp), %eax\n" /* i */
        "cmpl 0x22c(%edx), %eax\n"
        "jl .Lf16f3a8_0016f43f\n"
        ".Lf16f3a8_0016f481:\n"
        "movl %edi, %esi\n" /* line 5686 | menu */
        "subl $1, %esi\n" /* menu */
        "js .Lf16f3a8_0016f55d\n"
        ".Lf16f3a8_0016f48c:\n"
        "movl 8(%ebp), %edx\n" /* line 5688 | dc */
        "movl 0x230(%edx, %esi, 4), %eax\n"
        "movl 0x214(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16f3a8_0016f5a2\n"
        "movl %esi, %eax\n" /* menu */
        ".Lf16f3a8_0016f4a6:\n"
        "cmpl %edi, %eax\n" /* line 5694 */
        "jl .Lf16f3a8_0016f567\n"
        ".Lf16f3a8_0016f4ae:\n"
        "movl debugMode, %eax\n" /* line 5697 */
        "testl %eax, %eax\n"
        "je .Lf16f3a8_0016f544\n"
        /* { scope 2 */
        "movl $0x3f800000, %eax\n" /* line 447 */
        "movl %eax, -0x28(%ebp)\n" /* color */
        "movl %eax, -0x24(%ebp)\n" /* line 448 */
        "movl %eax, -0x20(%ebp)\n" /* line 449 */
        "movl %eax, -0x1c(%ebp)\n" /* line 450 */
        "movl $0x3f000000, %ebx\n" /* line 5703 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl $0, (%esp)\n"
        "calll UI_GetFontHandle\n"
        "movl %eax, %esi\n" /* font */
        "movl 8(%ebp), %eax\n" /* line 5704 | dc */
        "cvtss2sd 0x24(%eax), %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002ac3dc, (%esp)\n" /* "fps: %f" */
        "calll va\n"
        "movl $0, 0x24(%esp)\n"
        "leal -0x28(%ebp), %edx\n" /* color */
        "movl %edx, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* i */
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0x41c80000, 0x10(%esp)\n"
        "movl $0x40a00000, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        /* } scope */
        ".Lf16f3a8_0016f544:\n"
        "addl $0x5c, %esp\n" /* line 5706 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf16f3a8_0016f54c:\n"
        "movl 0x270(%edx), %edi\n"
        /* { scope 1: color */
        "movl %edi, %esi\n" /* line 5686 | menu */
        "subl $1, %esi\n" /* menu */
        "jns .Lf16f3a8_0016f48c\n"
        ".Lf16f3a8_0016f55d:\n"
        "xorl %eax, %eax\n"
        "cmpl %edi, %eax\n" /* line 5694 */
        "jge .Lf16f3a8_0016f4ae\n"
        ".Lf16f3a8_0016f567:\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "leal 0x230(%edx, %eax, 4), %esi\n" /* menu */
        "movl %eax, %ebx\n" /* i */
        ".Lf16f3a8_0016f573:\n"
        "movl $0, 8(%esp)\n" /* line 5695 */
        "movl (%esi), %eax\n" /* menu */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Menu_Paint\n"
        "addl $1, %ebx\n" /* line 5694 | i */
        "addl $4, %esi\n" /* menu */
        "movl 8(%ebp), %edx\n" /* dc */
        "cmpl 0x270(%edx), %ebx\n" /* i */
        "jl .Lf16f3a8_0016f573\n"
        "jmp .Lf16f3a8_0016f4ae\n"
        ".Lf16f3a8_0016f5a2:\n"
        "leal 0x230(%edx, %esi, 4), %ecx\n" /* line 5688 */
        "movl %esi, %ebx\n" /* menu, i */
        "xorl %edx, %edx\n"
        ".Lf16f3a8_0016f5ad:\n"
        "subl $1, %ebx\n" /* line 5686 | i */
        "cmpl %esi, %edx\n" /* menu */
        "je .Lf16f3a8_0016f55d\n"
        "movl -4(%ecx), %eax\n" /* line 5688 */
        "addl $1, %edx\n"
        "subl $4, %ecx\n"
        "movl 0x214(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16f3a8_0016f5ad\n"
        "movl %ebx, %eax\n" /* i */
        "jmp .Lf16f3a8_0016f4a6\n"
    );
}

/* line 3336 */
__attribute__((naked))
void Menus_HandleOOBClick(displayContextDef_t *dc, menuDef_t *menu, int key, qboolean down)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3336 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x35c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* menu */
        /* { scope 1: item */
        "testl %ebx, %ebx\n" /* line 3342 | menu */
        "je .Lf16f5ce_0016fb16\n"
        "movl 0x14(%ebp), %eax\n" /* line 3348 | down */
        "testl %eax, %eax\n"
        "jne .Lf16f5ce_0016fcb8\n"
        ".Lf16f5ce_0016f5f0:\n"
        "movl 8(%ebp), %edx\n" /* line 3354 | dc */
        "movl 0x270(%edx), %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x33c(%ebp)\n" /* i */
        "js .Lf16f5ce_0016fd22\n"
        ".Lf16f5ce_0016f608:\n"
        "leal 0x230(%edx, %ecx, 4), %esi\n"
        "movl %ecx, -0x31c(%ebp)\n"
        "jmp .Lf16f5ce_0016f62e\n"
        ".Lf16f5ce_0016f617:\n"
        "subl $1, -0x31c(%ebp)\n"
        "subl $4, %esi\n"
        "cmpl $-1, -0x31c(%ebp)\n"
        "je .Lf16f5ce_0016fb21\n"
        ".Lf16f5ce_0016f62e:\n"
        "movl 8(%ebp), %eax\n" /* line 3356 | dc */
        "cvtsi2ssl 0x10(%eax), %xmm0\n"
        "movss %xmm0, -0x330(%ebp)\n" /* y */
        "cvtsi2ssl 0xc(%eax), %xmm0\n"
        "movss %xmm0, -0x32c(%ebp)\n" /* x */
        "movl (%esi), %ebx\n" /* menu */
        /* { scope 2: compareRect, compareX, compareY, i */
        "testl %ebx, %ebx\n" /* line 5753 | menu */
        "je .Lf16f5ce_0016f617\n"
        "testl $0x4004, 0xe8(%ebx)\n" /* menu */
        "je .Lf16f5ce_0016f617\n"
        /* { scope 3: compareRect, compareX, compareY, y, ... */
        "movl (%ebx), %eax\n" /* line 417 */
        "movl %eax, -0x314(%ebp)\n" /* compareRect */
        "movl 4(%ebx), %eax\n" /* line 418 */
        "movl %eax, -0x310(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 419 */
        "movl %eax, -0x30c(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 420 */
        "movl %eax, -0x308(%ebp)\n"
        "movss %xmm0, -0x20(%ebp)\n" /* line 422 | compareX */
        "movss -0x330(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %edx\n" /* compareY */
        "movl %edx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%ebx), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x308(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x30c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x310(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x314(%ebp), %ecx\n" /* compareRect */
        "movl %ecx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x314(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16f5ce_0016f617\n"
        "addss -0x30c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16f5ce_0016f617\n"
        "movss -0x310(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16f5ce_0016f617\n"
        "addss -0x308(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16f5ce_0016f617\n"
        /* } scope */
        /* { scope 3: compareRect, compareX, compareY, y, ... */
        "movl 0x218(%ebx), %eax\n" /* line 5759 | menu */
        "testl %eax, %eax\n"
        "jle .Lf16f5ce_0016f617\n"
        "movl $0, -0x334(%ebp)\n" /* i */
        "jmp .Lf16f5ce_0016f773\n"
        ".Lf16f5ce_0016f75a:\n"
        "addl $1, -0x334(%ebp)\n" /* i */
        "movl -0x334(%ebp), %eax\n" /* i */
        "cmpl %eax, 0x218(%ebx)\n" /* menu */
        "jle .Lf16f5ce_0016f617\n"
        /* } scope */
        /* { scope 3: compareRect, compareX, compareY, y, ... */
        ".Lf16f5ce_0016f773:\n"
        "movl -0x334(%ebp), %eax\n" /* line 430 | i */
        "shll $2, %eax\n"
        "movl %eax, -0x338(%ebp)\n"
        /* } scope */
        /* { scope 3: compareRect, compareX, compareY, y, ... */
        "movl 0x27c(%ebx), %eax\n" /* line 5764 | menu */
        "movl -0x338(%ebp), %edx\n"
        "movl (%edx, %eax), %edi\n" /* window */
        "testl $0x4004, 0xe8(%edi)\n" /* line 5765 | window */
        "je .Lf16f5ce_0016f75a\n"
        "movl 0xe4(%edi), %ecx\n" /* line 5770 | window */
        "andl $0x100000, %ecx\n"
        "movl %ecx, -0x340(%ebp)\n"
        "jne .Lf16f5ce_0016f75a\n"
        /* { scope 4: compareRect, compareX, compareY */
        "movl (%edi), %eax\n" /* line 417 */
        "movl %eax, -0x314(%ebp)\n" /* compareRect */
        "movl 4(%edi), %eax\n" /* line 418 */
        "movl %eax, -0x310(%ebp)\n"
        "movl 8(%edi), %eax\n" /* line 419 */
        "movl %eax, -0x30c(%ebp)\n"
        "movl 0xc(%edi), %eax\n" /* line 420 */
        "movl %eax, -0x308(%ebp)\n"
        "movss -0x32c(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareY */
        "movss -0x330(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x1c(%ebp), %eax\n" /* compareY */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x20(%ebp), %edx\n" /* compareX */
        "movl %edx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl 0x14(%edi), %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x308(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x30c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x310(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x314(%ebp), %ecx\n" /* compareRect */
        "movl %ecx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x314(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16f5ce_0016f75a\n"
        "addss -0x30c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16f5ce_0016f75a\n"
        "movss -0x310(%ebp), %xmm0\n"
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16f5ce_0016f75a\n"
        "addss -0x308(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16f5ce_0016f75a\n"
        /* } scope */
        "movl 0x27c(%ebx), %eax\n" /* line 5777 | menu */
        "movl -0x338(%ebp), %ecx\n"
        "movl (%ecx, %eax), %edx\n"
        "movl 0x270(%edx), %edi\n" /* line 5779 | window */
        "testl %edi, %edi\n" /* window */
        "jne .Lf16f5ce_0016fa3c\n"
        "movl 0x294(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf16f5ce_0016fa3c\n"
        /* { scope 4: compareRect, compareX, compareY */
        "movl $rect, %edi\n" /* line 3383 | window */
        "cld\n"
        "movl $6, %ecx\n"
        "movl -0x340(%ebp), %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* window */
        "movl 0x210(%edx), %eax\n" /* line 3387 */
        "movl %eax, rect\n"
        "movl 0x214(%edx), %eax\n"
        "movl %eax, rect+4\n"
        "movl 0x218(%edx), %eax\n"
        "movl %eax, rect+8\n"
        "movl 0x21c(%edx), %eax\n"
        "movl %eax, rect+12\n"
        "movl 0x220(%edx), %eax\n"
        "movl %eax, rect+16\n"
        "movl 0x224(%edx), %eax\n"
        "movl %eax, rect+20\n"
        "pxor %xmm0, %xmm0\n" /* line 3388 */
        "ucomiss rect+8, %xmm0\n"
        "jp .Lf16f5ce_0016f92f\n"
        "je .Lf16f5ce_0016fd29\n"
        ".Lf16f5ce_0016f92f:\n"
        "movss rect+4, %xmm0\n" /* line 3390 */
        "subss rect+12, %xmm0\n"
        "movss %xmm0, rect+4\n"
        /* } scope */
        /* { scope 4: compareRect, compareX, compareY */
        /* { scope 5 */
        ".Lf16f5ce_0016f947:\n"
        "movl rect, %eax\n" /* line 417 */
        "movl %eax, -0x314(%ebp)\n" /* compareRect */
        "movss %xmm0, -0x310(%ebp)\n" /* line 418 */
        "movl rect+8, %eax\n" /* line 419 */
        "movl %eax, -0x30c(%ebp)\n"
        "movl rect+12, %eax\n" /* line 420 */
        "movl %eax, -0x308(%ebp)\n"
        "movss -0x32c(%ebp), %xmm0\n" /* line 422 | x */
        "movss %xmm0, -0x20(%ebp)\n" /* compareX */
        "movss -0x330(%ebp), %xmm0\n" /* line 423 | y */
        "movss %xmm0, -0x1c(%ebp)\n" /* compareY */
        "movl $4, 4(%esp)\n" /* line 426 */
        "leal -0x20(%ebp), %eax\n" /* compareX */
        "movl %eax, (%esp)\n"
        "calll CalcScreenX\n"
        "movl $4, 4(%esp)\n" /* line 427 */
        "leal -0x1c(%ebp), %edx\n" /* compareY */
        "movl %edx, (%esp)\n"
        "calll CalcScreenY\n"
        "movl rect+20, %eax\n" /* line 428 */
        "movl %eax, 0x14(%esp)\n"
        "movl rect+16, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal -0x308(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x30c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x310(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "leal -0x314(%ebp), %ecx\n" /* compareRect */
        "movl %ecx, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movss -0x314(%ebp), %xmm0\n" /* line 430 | compareRect */
        "movss -0x20(%ebp), %xmm1\n" /* compareX */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16f5ce_0016f75a\n"
        "addss -0x30c(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16f5ce_0016f75a\n"
        "movss -0x310(%ebp), %xmm0\n"
        "movss -0x1c(%ebp), %xmm1\n" /* compareY */
        "ucomiss %xmm0, %xmm1\n"
        "jb .Lf16f5ce_0016f75a\n"
        "addss -0x308(%ebp), %xmm0\n"
        "ucomiss %xmm1, %xmm0\n"
        "jb .Lf16f5ce_0016f75a\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf16f5ce_0016fa3c:\n"
        "movl 8(%ebp), %eax\n" /* line 3358 | dc */
        "movl 0x270(%eax), %edi\n" /* window */
        "movl %edi, %eax\n" /* window */
        "subl $1, %eax\n"
        "js .Lf16f5ce_0016fa74\n"
        "movl 8(%ebp), %edx\n" /* dc */
        "leal 0x230(%edx, %eax, 4), %esi\n"
        "xorl %ebx, %ebx\n" /* menu */
        ".Lf16f5ce_0016fa58:\n"
        "movl $2, 4(%esp)\n" /* line 3359 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Window_RemoveDynamicFlags\n"
        "addl $1, %ebx\n" /* menu */
        "subl $4, %esi\n"
        "cmpl %ebx, %edi\n" /* line 3358 | menu, window */
        "jne .Lf16f5ce_0016fa58\n"
        ".Lf16f5ce_0016fa74:\n"
        "movl $6, 4(%esp)\n" /* line 3360 */
        "movl -0x31c(%ebp), %edx\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl 0x230(%ecx, %edx, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Window_AddDynamicFlags\n"
        "movl 8(%ebp), %edx\n" /* line 3362 | dc */
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Display_MouseMove\n"
        "movl 8(%ebp), %ecx\n" /* line 3363 | dc */
        "cvtsi2ssl 0x10(%ecx), %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "cvtsi2ssl 0xc(%ecx), %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl -0x31c(%ebp), %edx\n"
        "movl 0x230(%ecx, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Menu_HandleMouseMove\n"
        "movl 0x14(%ebp), %ecx\n" /* line 3365 | down */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* key */
        "movl %eax, 8(%esp)\n"
        "movl -0x31c(%ebp), %edx\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "movl 0x230(%ecx, %edx, 4), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Menu_HandleKey\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "jmp .Lf16f5ce_0016fb24\n"
        /* } scope */
        ".Lf16f5ce_0016fb16:\n"
        "addl $0x35c, %esp\n" /* line 3374 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf16f5ce_0016fb21:\n"
        "movl 8(%ebp), %eax\n" /* dc */
        /* { scope 1: item */
        /* { scope 2: compareRect, compareX, compareY, i */
        ".Lf16f5ce_0016fb24:\n"
        "movl 0x22c(%eax), %esi\n" /* line 3324 */
        "testl %esi, %esi\n"
        "jg .Lf16f5ce_0016fc87\n"
        /* } scope */
        ".Lf16f5ce_0016fb32:\n"
        "movl $0, (%esp)\n" /* line 3371 */
        "calll UI_Pause\n"
        /* { scope 2: compareRect, compareX, compareY, i */
        ".Lf16f5ce_0016fb3e:\n"
        "movl 8(%ebp), %edx\n" /* line 3258 | dc */
        "movl 0x270(%edx), %edx\n"
        "movl %edx, -0x344(%ebp)\n"
        "movl %edx, %eax\n"
        "subl $1, %eax\n"
        "js .Lf16f5ce_0016fb16\n"
        "movl 8(%ebp), %ecx\n" /* dc */
        "leal 0x230(%ecx, %eax, 4), %eax\n"
        "movl %eax, -0x320(%ebp)\n"
        "movl $0, -0x324(%ebp)\n"
        ".Lf16f5ce_0016fb6e:\n"
        "movl (%eax), %ebx\n" /* line 3259 | menu */
        /* { scope 3: compareRect, compareX, compareY, y, ... */
        "testl %ebx, %ebx\n" /* line 3237 */
        "je .Lf16f5ce_0016fc2f\n"
        /* { scope 4: compareRect, compareX, compareY */
        "cmpl $5, 0xd0(%ebx)\n" /* line 3227 */
        "je .Lf16f5ce_0016fc62\n"
        ".Lf16f5ce_0016fb85:\n"
        "movl 0x218(%ebx), %edx\n" /* line 3242 */
        "testl %edx, %edx\n"
        "jle .Lf16f5ce_0016fc2f\n"
        "movl $0, -0x328(%ebp)\n" /* i */
        "movl -0x328(%ebp), %esi\n" /* i */
        "jmp .Lf16f5ce_0016fbc7\n"
        ".Lf16f5ce_0016fba5:\n"
        "movl %edi, %eax\n"
        ".Lf16f5ce_0016fba7:\n"
        "cmpl $8, 0x270(%eax)\n" /* line 3245 */
        "je .Lf16f5ce_0016fc0a\n"
        ".Lf16f5ce_0016fbb0:\n"
        "addl $1, -0x328(%ebp)\n" /* line 3242 | i */
        "movl -0x328(%ebp), %edx\n" /* i */
        "cmpl 0x218(%ebx), %edx\n"
        "jge .Lf16f5ce_0016fc2f\n"
        ".Lf16f5ce_0016fbc5:\n"
        "movl %edx, %esi\n"
        ".Lf16f5ce_0016fbc7:\n"
        "shll $2, %esi\n"
        "movl 0x27c(%ebx), %eax\n" /* line 3244 */
        "movl (%eax, %esi), %edi\n" /* window */
        /* { scope 5 */
        "cmpl $5, 0xd0(%edi)\n" /* line 3227 */
        "jne .Lf16f5ce_0016fba5\n"
        "movl 0xcc(%edi), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf16f5ce_0016fc5a\n"
        "movl %edx, (%esp)\n" /* line 3229 */
        "calll CIN_StopCinematic\n"
        "movl $0xffffffff, 0xcc(%edi)\n" /* line 3230 */
        "movl 0x27c(%ebx), %eax\n"
        "movl (%eax, %esi), %eax\n"
        /* } scope */
        "cmpl $8, 0x270(%eax)\n" /* line 3245 */
        "jne .Lf16f5ce_0016fbb0\n"
        ".Lf16f5ce_0016fc0a:\n"
        "movl 0xd8(%eax), %eax\n" /* line 3247 */
        "negl %eax\n"
        "movl %eax, (%esp)\n"
        "calll CIN_StopCinematic\n"
        "addl $1, -0x328(%ebp)\n" /* line 3242 | i */
        "movl -0x328(%ebp), %edx\n" /* i */
        "cmpl 0x218(%ebx), %edx\n"
        "jl .Lf16f5ce_0016fbc5\n"
        ".Lf16f5ce_0016fc2f:\n"
        "addl $1, -0x324(%ebp)\n"
        "subl $4, -0x320(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl -0x344(%ebp), %ecx\n" /* line 3258 */
        "cmpl %ecx, -0x324(%ebp)\n"
        "je .Lf16f5ce_0016fb16\n"
        "movl -0x320(%ebp), %eax\n"
        "jmp .Lf16f5ce_0016fb6e\n"
        ".Lf16f5ce_0016fc5a:\n"
        "movl (%eax, %esi), %eax\n"
        "jmp .Lf16f5ce_0016fba7\n"
        /* { scope 3: compareRect, compareX, compareY, y, ... */
        /* { scope 4: compareRect, compareX, compareY */
        ".Lf16f5ce_0016fc62:\n"
        "movl 0xcc(%ebx), %eax\n" /* line 3227 */
        "testl %eax, %eax\n"
        "js .Lf16f5ce_0016fb85\n"
        "movl %eax, (%esp)\n" /* line 3229 */
        "calll CIN_StopCinematic\n"
        "movl $0xffffffff, 0xcc(%ebx)\n" /* line 3230 */
        "jmp .Lf16f5ce_0016fb85\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: compareRect, compareX, compareY, i */
        ".Lf16f5ce_0016fc87:\n"
        "movl %eax, %edx\n" /* line 3324 */
        "xorl %ebx, %ebx\n" /* count */
        "xorl %ecx, %ecx\n"
        ".Lf16f5ce_0016fc8d:\n"
        "movl 0x2c(%edx), %eax\n" /* line 3326 */
        "movl 0xe8(%eax), %eax\n"
        "andl $0x4004, %eax\n"
        "cmpl $1, %eax\n" /* line 3328 */
        "sbbl $-1, %ebx\n" /* count */
        "addl $1, %ecx\n" /* line 3324 */
        "addl $4, %edx\n"
        "cmpl %ecx, %esi\n"
        "jne .Lf16f5ce_0016fc8d\n"
        /* } scope */
        "testl %ebx, %ebx\n" /* line 3370 | menu */
        "jne .Lf16f5ce_0016fb3e\n"
        "jmp .Lf16f5ce_0016fb32\n"
        ".Lf16f5ce_0016fcb8:\n"
        "testb $2, 0xe7(%ebx)\n" /* line 3348 | menu */
        "je .Lf16f5ce_0016f5f0\n"
        "testb $4, 0xe8(%ebx)\n" /* line 769 */
        "je .Lf16f5ce_0016fcfa\n"
        "movl 0x248(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf16f5ce_0016fcfa\n"
        /* { scope 2: compareRect, compareX, compareY, i */
        "movl %ebx, -0x78(%ebp)\n" /* line 773 */
        "movl 0x248(%ebx), %eax\n" /* line 774 */
        "movl %eax, 8(%esp)\n"
        "leal -0x314(%ebp), %eax\n" /* compareRect */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dc */
        "movl %eax, (%esp)\n"
        "calll Item_RunScript\n"
        /* } scope */
        ".Lf16f5ce_0016fcfa:\n"
        "movl $6, 4(%esp)\n" /* line 3351 */
        "movl %ebx, (%esp)\n" /* menu */
        "calll Window_RemoveDynamicFlags\n"
        "movl 8(%ebp), %edx\n" /* line 3354 | dc */
        "movl 0x270(%edx), %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x33c(%ebp)\n" /* i */
        "jns .Lf16f5ce_0016f608\n"
        ".Lf16f5ce_0016fd22:\n"
        "movl %edx, %eax\n"
        "jmp .Lf16f5ce_0016fb24\n"
        ".Lf16f5ce_0016fd29:\n"
        "movss rect+4, %xmm0\n"
        "jmp .Lf16f5ce_0016f947\n"
    );
}
