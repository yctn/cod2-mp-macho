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

/* Menus_Close — remove menu from open stack, run onClose script, re-focus */
void Menus_Close(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *d = (byte *)dc;
    int openCount, i, menuIndex;
    qboolean wasVisible = 0;
    byte tempItem[0x2a0];

    /* Check if menu was visible+focused before close */
    openCount = *(int *)(d + 0x270);
    for (i = openCount - 1; i >= 0; i--) {
        if (*(void **)(d + 0x230 + i * 4) == menu) {
            int flags = *(int *)((byte *)menu + 0xe8);
            if (flags & 4)
                wasVisible = (flags >> 1) & 1;
            break;
        }
    }

    /* Run onClose script if visible */
    int flags = *(int *)((byte *)menu + 0xe8);
    if ((flags & 4) && *(void **)((byte *)menu + 0x248)) {
        *(void **)&tempItem[0x29c] = menu;
        Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)((byte *)menu + 0x248));
        openCount = *(int *)(d + 0x270);
    }

    /* Remove menu from openMenus array */
    menuIndex = -1;
    for (i = openCount - 1; i >= 0; i--) {
        if (*(void **)(d + 0x230 + i * 4) == menu) {
            menuIndex = i;
            break;
        }
    }
    if (menuIndex >= 0) {
        *(int *)(d + 0x270) = openCount - 1;
        /* Compact array */
        for (i = menuIndex; i < *(int *)(d + 0x270); i++) {
            *(void **)(d + 0x230 + i * 4) = *(void **)(d + 0x230 + (i + 1) * 4);
        }
    }

    /* If the closed menu was visible+focused, re-focus the next visible menu */
    if (wasVisible && *(int *)(d + 0x270) > 0) {
        int menuNum = *(int *)(d + 0x270) - 1;
        for (i = menuNum; i >= 0; i--) {
            byte *m = *(byte **)(d + 0x230 + i * 4);
            if (*(byte *)(m + 0xe8) & 4) {
                Window_AddDynamicFlags((void *)m, 2);
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
    int count = *(int *)(d + 0x22c);
    int i;
    for (i = 0; i < count; i++) {
        Menus_Close(dc, *(void **)(d + 0x2c + i * 4));
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
        textPtr = *(const char **)(it + 0x294);
        if (!textPtr) return;
        if (textPtr[0] == '@')
            textPtr = UI_SafeTranslateString(textPtr + 1);
    }

    /* Get initial text rect dimensions */
    *width = (int)*(float *)(it + 0x218);
    *height = (int)*(float *)(it + 0x21c);

    /* Check if we need to compute text extents */
    if (*width != 0) {
        int itemType = *(int *)(it + 0x270);
        if (itemType != 8 && !*(void **)(it + 0x2c0))
            goto check_alignment;
        if (*(int *)(it + 0x280) == 1)
            goto compute;
        check_alignment:
        if (*(int *)(it + 0x280) == 3)
            goto compute;
        return;
    }

compute:;
    FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
    float scale = *(float *)(it + 0x28c);
    originalWidth = UI_TextWidth(textPtr, 0, font, scale);

    /* Add owner draw width for certain item types */
    int itemType = *(int *)(it + 0x270);
    if (itemType == 8) {
        int alignment = *(int *)(it + 0x280);
        if (alignment == 1 || alignment == 2)
            originalWidth += UI_OwnerDrawWidth(*(int *)(it + 0xd8), scale);
    } else if (itemType <= 0x12 && ((1 << itemType) & 0x70210)) {
        if (*(int *)(it + 0x280) == 1 && *(void **)(it + 0x2c0)) {
            originalWidth += UI_TextWidth(Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0, font, scale);
        }
    }

    /* Add label text width for alignment == 3 */
    if (*(int *)(it + 0x280) == 3)
        originalWidth += UI_TextWidth(text, 0, font, scale);

    /* Compute final text extents */
    *width = UI_TextWidth(textPtr, 0, font, scale);
    *height = UI_TextHeight(font, scale);

    /* Build text rect */
    float textW = (float)*width;
    float textH = (float)*height;
    float textX = *(float *)(it + 0x284);
    float textY = *(float *)(it + 0x288);
    int horzAlign = *(int *)(it + 0x10);
    int vertAlign = *(int *)(it + 0x14);

    /* Adjust x based on text alignment */
    int alignment = *(int *)(it + 0x280);
    if (alignment == 2) {
        /* Right-aligned */
        textX -= (float)originalWidth;
    } else if (alignment == 1 || alignment == 3) {
        /* Center-aligned */
        textX -= (float)(originalWidth / 2);
    }

    /* Add border offset */
    if (*(int *)(it + 0xd4)) {
        textX += *(float *)(it + 0xe0);
        textY += *(float *)(it + 0xe0);
    }

    /* Add item position */
    textX += *(float *)it;
    textY += *(float *)(it + 4);

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
    FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
    float scale = *(float *)(it + 0x28c);
    int height = UI_TextHeight(font, scale);
    int textWidth = UI_TextWidth(textPtr, 0, font, scale);
    int style = *(int *)(it + 0x290);
    int horzAlign = *(int *)(it + 0x10);
    int vertAlign = *(int *)(it + 0x14);
    byte *textRect = it + 0x210;
    float lineHeight;
    int iTargetLineWidth;
    float y;
    int len, newLine, newLineWidth;
    const char *newLinePtr;
    const char *p;

    /* Determine target line width */
    float itemW = *(float *)(it + 8);
    if (itemW != 0.0f && (float)textWidth > itemW) {
        /* Text wider than item — compute number of lines and split evenly */
        int numLines = (int)ceilf((float)textWidth / itemW);
        iTargetLineWidth = (int)((float)textWidth / (float)numLines);
    } else {
        iTargetLineWidth = (int)itemW;
    }

    y = *(float *)(it + 0x288);
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
            if ((float)textWidth > *(float *)(it + 8))
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
                newTextRect[3] = *(float *)(textRect + 0xc);
                *(int *)&newTextRect[4] = *(int *)(textRect + 0x10);
                *(int *)&newTextRect[5] = *(int *)(textRect + 0x14);

                /* Compute x alignment */
                int alignment = *(int *)(it + 0x280);
                if (alignment == 1) {
                    newTextRect[0] = *(float *)(it + 0x284) - (float)(newLineWidth / 2);
                } else if (alignment == 2) {
                    newTextRect[0] = *(float *)(it + 0x284) + *(float *)(textRect + 8) - (float)newLineWidth;
                } else {
                    newTextRect[0] = *(float *)(it + 0x284);
                }
                newTextRect[1] = y;

                /* Add border offset */
                if (*(int *)(it + 0xd4)) {
                    newTextRect[0] += *(float *)(it + 0xe0);
                    newTextRect[1] += *(float *)(it + 0xe0);
                }
                newTextRect[0] += *(float *)it;
                newTextRect[1] += *(float *)(it + 4);

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
    FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
    int height = UI_TextHeight(font, *(float *)(it + 0x28c));
    float scale = *(float *)(it + 0x28c);
    int style = *(int *)(it + 0x290);
    int horzAlign = *(int *)(it + 0x10);
    int vertAlign = *(int *)(it + 0x14);
    byte *textRect = it + 0x210;
    float y = *(float *)(textRect + 4);
    float lineHeight = (float)(height + 5);

    const char *p = strchr(textPtr, 0x0d);
    if (!p || p[0] == '\0') {
        /* No line breaks — draw entire text with alignment */
        float x;
        int alignment = *(int *)(it + 0x280);
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
        int alignment = *(int *)(it + 0x280);
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
    int alignment = *(int *)(it + 0x280);
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
    byte *listPtr;
    int count;
    float sizeH;
    int startPos;
    int i, j;
    int numColumns;
    MaterialHandle optionalImage;
    const char *text;
    float x, y;
    byte *uiInfo;
    int horzAlign, vertAlign;

    listPtr = (byte *)Item_GetListBoxDef(item);
    if (!listPtr)
        return;

    count = UI_FeederCount(*(float *)(it + 0x2d8));

    horzAlign = *(int *)(it + 0x10);
    vertAlign = *(int *)(it + 0x14);

    if (*(byte *)(it + 0xe6) & 0x20) {
        /* ============ HORIZONTAL PATH ============ */
        float hx = *(float *)it + 1.0f;
        float hy_bottom = *(float *)(it + 4);
        hy_bottom = hy_bottom + *(float *)(it + 0xc) - 16.0f - 1.0f;

        uiInfo = (byte *)imp_sharedUiInfo;

        /* Left arrow */
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            hx, hy_bottom, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 8));

        float trackX = hx + 15.0f;

        /* Horizontal track */
        float trackW = *(float *)(it + 8) - 32.0f;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            trackX, hy_bottom, trackW + 1.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 0x10));

        /* Right arrow */
        float rightArrowX = trackW - 1.0f + trackX;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            rightArrowX, hy_bottom, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 0x0c));

        /* Thumb */
        int thumbPos = Item_ListBox_ThumbDrawPosition(dc, item);
        float thumbX = (float)thumbPos;
        float thumbMax = rightArrowX - 16.0f - 1.0f;
        if (thumbMax < thumbX)
            thumbX = thumbMax;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            thumbX, hy_bottom, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 0x14));

        /* ListBox_SetEndPos */
        ListBox_SetEndPos((void *)listPtr, *(int *)listPtr);

        float size = *(float *)(it + 8) - 2.0f;

        if (*(int *)(listPtr + 0x3c) != 1)
            return;

        /* Horizontal items rendering */
        x = *(float *)it + 1.0f;
        y = *(float *)(it + 4) + 1.0f;
        startPos = *(int *)listPtr;
        i = startPos;

        while (i < count) {
            /* Get item image */
            MaterialHandle img = UI_FeederItemImage(*(float *)(it + 0x2d8), i);
            if (img) {
                ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                    x + 1.0f, y + 1.0f,
                    *(float *)(listPtr + 0x34) - 2.0f,
                    *(float *)(listPtr + 0x38) - 2.0f,
                    horzAlign, vertAlign, 0, (int)(uintptr_t)img);
            }

            /* Selection highlight */
            if (i == *(int *)(it + 0x2dc)) {
                UI_DrawRect(x, y,
                    *(float *)(listPtr + 0x34) - 1.0f,
                    *(float *)(listPtr + 0x38) - 1.0f,
                    horzAlign, vertAlign,
                    *(float *)(it + 0xe0),
                    (float *)(it + 0x1ec));
            }

            /* Check remaining size */
            size -= *(float *)(listPtr + 0x34);
            if (*(float *)(listPtr + 0x34) > size) {
                *(int *)(listPtr + 0x20) = (int)size;
                return;
            }

            x += *(float *)(listPtr + 0x34);
            ListBox_SetEndPos((void *)listPtr, *(int *)(listPtr + 0x10) + 1);
            i++;
        }
        return;
    }

    /* ============ VERTICAL PATH ============ */
    ((void (*)(void *))UI_OverrideCursorPos)(item);

    numColumns = *(int *)(listPtr + 0x10c);

    if (numColumns == 0) {
        /* --- No columns: draw vertical scrollbar on right side --- */
        float scrollX = *(float *)it;
        scrollX = scrollX + *(float *)(it + 8) - 16.0f - 1.0f;

        float scrollY = *(float *)(it + 4) + 1.0f;

        uiInfo = (byte *)imp_sharedUiInfo;

        /* Up arrow */
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, scrollY, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)uiInfo);

        float trackY = scrollY + 15.0f;

        /* ListBox_SetEndPos */
        ListBox_SetEndPos((void *)listPtr, *(int *)listPtr);

        /* Vertical track */
        float trackH = *(float *)(it + 0xc) - 32.0f;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, trackY, 16.0f, trackH + 1.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 0x10));

        /* Down arrow */
        float downArrowY = trackH - 1.0f + trackY;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, downArrowY, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 4));

        /* Thumb */
        int thumbPos2 = Item_ListBox_ThumbDrawPosition(dc, item);
        float thumbY = (float)thumbPos2;
        float thumbMax2 = downArrowY - 16.0f - 1.0f;
        if (thumbMax2 < thumbY)
            thumbY = thumbMax2;
        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
            scrollX, thumbY, 16.0f, 16.0f,
            horzAlign, vertAlign, 0, *(int *)(uiInfo + 0x14));
    }

    /* --- Item rendering (both with and without columns) --- */
    sizeH = *(float *)(it + 0xc) - 2.0f;

    if (*(int *)(listPtr + 0x3c) == 1) {
        /* ===== drawPadding == 1: single item/image per row ===== */
        float ix = *(float *)it + 1.0f;
        float iy = *(float *)(it + 4) + 1.0f;
        startPos = *(int *)listPtr;

        if (count <= startPos)
            return;

        float ix2 = ix + 1.0f;
        i = startPos;

        while (i < count) {
            /* Get item image */
            MaterialHandle img2 = UI_FeederItemImage(*(float *)(it + 0x2d8), i);
            if (img2) {
                ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                    ix2, iy + 1.0f,
                    *(float *)(listPtr + 0x34) - 2.0f,
                    *(float *)(listPtr + 0x38) - 2.0f,
                    horzAlign, vertAlign, 0, (int)(uintptr_t)img2);
            }

            /* Selection highlight */
            if (i == *(int *)(it + 0x2dc)) {
                UI_DrawRect(ix, iy,
                    *(float *)(listPtr + 0x34) - 1.0f,
                    *(float *)(listPtr + 0x38) - 1.0f,
                    horzAlign, vertAlign,
                    *(float *)(it + 0xe0),
                    (float *)(it + 0x1ec));
            }

            /* Advance and check bounds */
            ListBox_SetEndPos((void *)listPtr, *(int *)(listPtr + 0x10) + 1);
            sizeH -= *(float *)(listPtr + 0x34);
            if (*(float *)(listPtr + 0x38) > sizeH) {
                *(int *)(listPtr + 0x20) = (int)(*(float *)(listPtr + 0x38) - sizeH);
                return;
            }
            iy += *(float *)(listPtr + 0x38);
            i++;
        }
        return;
    }

    /* ===== drawPadding != 1: multi-column text rendering ===== */
    {
        float baseX = *(float *)it + 1.0f;
        y = *(float *)(it + 4) + 1.0f;
        startPos = *(int *)(listPtr);

        if (count <= startPos)
            return;

        i = startPos;
        float preX4 = baseX + 4.0f;
        float preX2a = baseX + 2.0f;
        float preX2b = baseX + 2.0f;

        while (1) {
            int colCount = *(int *)(listPtr + 0x40);

            if (colCount > 0) {
                /* With columns */
                byte *col = listPtr;
                j = 0;
                while (j < *(int *)(listPtr + 0x40)) {
                    /* Get text and optional image for this column */
                    text = UI_FeederItemText(*(float *)(it + 0x2d8), i, j, &optionalImage);

                    if (optionalImage) {
                        /* Draw optional image */
                        float imgSize = (float)(*(int *)(col + 0x48));
                        ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                            (float)(*(int *)(col + 0x44)) + preX2b,
                            y + 3.0f,
                            imgSize, imgSize,
                            horzAlign, vertAlign, 0, (int)(uintptr_t)optionalImage);
                    } else if (text) {
                        /* Draw text */
                        float textScale = *(float *)(it + 0x28c);
                        FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), textScale);
                        float drawX = (float)(*(int *)(col + 0x44)) + preX4 + *(float *)(it + 0x284);
                        float drawY = y + *(float *)(listPtr + 0x38) + *(float *)(it + 0x288);
                        UI_DrawText(text, *(int *)(col + 0x4c), font,
                            drawX, drawY,
                            horzAlign, vertAlign,
                            textScale,
                            (float *)(it + 0x1cc),
                            *(int *)(it + 0x290));
                    }
                    j++;
                    col += 0xc;
                }
            } else {
                /* No columns — single text item */
                text = UI_FeederItemText(*(float *)(it + 0x2d8), i, 0, &optionalImage);

                if (optionalImage) {
                    /* Draw optional image */
                    ((void (*)(float, float, float, float, int, int, int, int))UI_DrawHandlePic)(
                        preX2a,
                        y + 2.0f,
                        *(float *)(listPtr + 0x34) - 4.0f,
                        *(float *)(listPtr + 0x38) - 4.0f,
                        horzAlign, vertAlign, 0, (int)(uintptr_t)optionalImage);
                } else if (text) {
                    /* Draw text */
                    float textScale2 = *(float *)(it + 0x28c);
                    FontHandle font2 = UI_GetFontHandle(*(int *)(it + 0x27c), textScale2);
                    float drawX2 = preX4;
                    float drawY2 = y + *(float *)(listPtr + 0x38);
                    UI_DrawText(text, 0x7fffffff, font2,
                        drawX2, drawY2,
                        horzAlign, vertAlign,
                        textScale2,
                        (float *)(it + 0x1cc),
                        *(int *)(it + 0x290));
                }
            }

            /* Selection highlight */
            if (i == *(int *)(it + 0x2dc)) {
                UI_FillRect(preX2a, y + 2.0f,
                    *(float *)(it + 8) - 16.0f - 4.0f,
                    *(float *)(listPtr + 0x38),
                    horzAlign, vertAlign,
                    (float *)(it + 0x1fc));
            }

            /* Advance row */
            sizeH -= *(float *)(listPtr + 0x38);
            if (*(float *)(listPtr + 0x38) > sizeH) {
                *(int *)(listPtr + 0x20) = (int)(*(float *)(listPtr + 0x38) - sizeH);
                return;
            }

            ListBox_SetEndPos((void *)listPtr, *(int *)(listPtr + 0x10) + 1);
            y += *(float *)(listPtr + 0x38);

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

/* Window_Paint — draw window background, border, cinematic, and fade handling */
void Window_Paint(displayContextDef_t *dc, float (*w_param)[4][32], float fadeAmount, float fadeInAmount, float fadeClamp, float fadeCycle)
{
    byte *w = (byte *)w_param;
    float x, y, ww, hh;
    float color[4];
    int borderStyle, borderSizeFlag;
    int handle;

    /* Load rect from window struct */
    hh = *(float *)(w + 0x0c);
    ww = *(float *)(w + 0x08);
    y  = *(float *)(w + 0x04);
    x  = *(float *)(w + 0x00);

    /* Debug mode: draw white outline */
    if (debugMode) {
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[2] = 1.0f;
        color[3] = 1.0f;
        UI_DrawRect(x, y, ww, hh,
            *(int *)(w + 0x10), *(int *)(w + 0x14),
            1.0f, color);
    }

    if (!w)
        return;

    borderStyle = *(int *)(w + 0xd0);
    borderSizeFlag = *(int *)(w + 0xd4);

    /* Determine whether to adjust rect by border size */
    if (borderStyle == 0 && borderSizeFlag == 0)
        return;

    if (borderSizeFlag != 0) {
        /* Adjust rect inward by border size */
        float bs = *(float *)(w + 0xe0);
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
            int background = *(int *)(w + 0x20c);
            if (background == 0) {
                /* No background: fill rect with foreColor */
                UI_FillRect(x, y, ww, hh,
                    *(int *)(w + 0x10), *(int *)(w + 0x14),
                    (const vec_t *)(w + 0x1dc));
                break;
            }

            /* Fade logic */
            {
                int dynFlags = *(int *)(w + 0xe8);
                int offsetTime = (int)fadeCycle;

                if (dynFlags & 0x30) {
                    int realtime = *(int *)((byte *)dc + 4);
                    if (realtime > *(int *)(w + 0x1c8)) {
                        *(int *)(w + 0x1c8) = realtime + offsetTime;
                        if (dynFlags & 0x10) {
                            /* Fading out */
                            float fadeAlpha = *(float *)(w + 0x1e8) - fadeAmount;
                            *(float *)(w + 0x1e8) = fadeAlpha;
                            if (!(fadeAlpha > 0.0f)) {
                                dynFlags &= 0xffffffeb; /* clear bits 0x10 and 0x04 */
                            }
                        } else {
                            /* Fading in */
                            float fadeAlpha = *(float *)(w + 0x1e8) + fadeInAmount;
                            *(float *)(w + 0x1e8) = fadeAlpha;
                            if (!(fadeAlpha < fadeClamp)) {
                                *(float *)(w + 0x1e8) = fadeClamp;
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
                *(int *)(w + 0x10), *(int *)(w + 0x14),
                (float *)(w + 0x1dc), *(int *)(w + 0x20c));
            break;
        }

        case 3: {
            /* Draw with tiled flag check */
            float *fillColor = NULL;
            if (*(byte *)(w + 0xea) & 1)
                fillColor = (float *)(w + 0x1cc);
            ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
                x, y, ww, hh,
                *(int *)(w + 0x10), *(int *)(w + 0x14),
                fillColor, *(int *)(w + 0x20c));
            break;
        }

        case 5: {
            /* Cinematic */
            handle = *(int *)(w + 0xcc);
            if (handle == -1) {
                /* Start cinematic */
                int result = CIN_PlayCinematic(
                    *(const char **)(w + 0xc8),
                    (int)x, (int)y, (int)ww, (int)hh, 0x0a);
                if (result != -1)
                    handle = result;
                else
                    handle = -2;
                *(int *)(w + 0xcc) = handle;
            }
            if (handle < 0)
                break;
            CIN_RunCinematic(handle);
            ((void (*)(int, int, int, int, int))CIN_SetExtents)(
                *(int *)(w + 0xcc), (int)x, (int)y, (int)ww, (int)hh);
            ((void (*)(int, int, int, int, int))CIN_DrawCinematic)(
                *(int *)(w + 0xcc), (int)x, (int)y, (int)ww, (int)hh);
            break;
        }

        case 6: {
            /* Background pic (no fade) */
            int background = *(int *)(w + 0x20c);
            if (background == 0)
                break;
            {
                float *fillColor = NULL;
                if (*(byte *)(w + 0xea) & 1)
                    fillColor = (float *)(w + 0x1cc);
                ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
                    x, y, ww, hh,
                    *(int *)(w + 0x10), *(int *)(w + 0x14),
                    fillColor, background);
            }
            break;
        }

        case 7: {
            /* Load bar */
            float *fillColor = NULL;
            if (*(byte *)(w + 0xea) & 1)
                fillColor = (float *)(w + 0x1cc);
            ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawLoadBar)(
                x, y, ww, hh,
                *(int *)(w + 0x10), *(int *)(w + 0x14),
                fillColor, *(int *)(w + 0x20c));
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
    borderSizeFlag = *(int *)(w + 0xd4);
    if (borderSizeFlag == 1) {
        /* UI_DrawRect border */
        float *borderColor;
        if (*(int *)(w + 0xd0) == 4) {
            /* Shadow style: check borderColor[0] alpha for color selection */
            if (*(float *)(w + 0x1ec) > 0.0f) {
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
            borderColor = (float *)(w + 0x1ec);
        }
        UI_DrawRect(
            *(float *)(w + 0x00), *(float *)(w + 0x04),
            *(float *)(w + 0x08), *(float *)(w + 0x0c),
            *(int *)(w + 0x10), *(int *)(w + 0x14),
            *(float *)(w + 0xe0), borderColor);
    } else if (borderSizeFlag == 2) {
        /* UI_DrawTopBottom */
        ((void (*)(float, float, float, float, int, int, float, const vec_t *))UI_DrawTopBottom)(
            *(float *)(w + 0x00), *(float *)(w + 0x04),
            *(float *)(w + 0x08), *(float *)(w + 0x0c),
            *(int *)(w + 0x10), *(int *)(w + 0x14),
            *(float *)(w + 0xe0), (const vec_t *)(w + 0x1ec));
        return;
    } else if (borderSizeFlag == 3) {
        /* UI_DrawSides */
        ((void (*)(float, float, float, float, int, int, float, const vec_t *))UI_DrawSides)(
            *(float *)(w + 0x00), *(float *)(w + 0x04),
            *(float *)(w + 0x08), *(float *)(w + 0x0c),
            *(int *)(w + 0x10), *(int *)(w + 0x14),
            *(float *)(w + 0xe0), (const vec_t *)(w + 0x1ec));
        return;
    }
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

/* Menus_Open — add menu to open stack, run onOpen script, stop cinematics, dispatch mouse */
void Menus_Open(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *d = (byte *)dc;
    byte *m = (byte *)menu;
    int openCount, i, j;
    byte tempItem[0x2a0];

    /* Remove focus flag from all currently open menus */
    openCount = *(int *)(d + 0x270);
    for (i = openCount - 1; i >= 0; i--)
        Window_RemoveDynamicFlags(*(void **)(d + 0x230 + i * 4), 2);
    openCount = *(int *)(d + 0x270);

    /* If menu is already in the open list, remove it first */
    int removeIdx = -1;
    for (i = openCount - 1; i >= 0; i--) {
        if (*(void **)(d + 0x230 + i * 4) == menu) { removeIdx = i; break; }
    }
    if (removeIdx >= 0) {
        *(int *)(d + 0x270) = openCount - 1;
        for (i = removeIdx; i < *(int *)(d + 0x270); i++)
            *(void **)(d + 0x230 + i * 4) = *(void **)(d + 0x230 + (i + 1) * 4);
    }
    if (*(int *)(d + 0x270) == 0x10)
        Com_Error(1, "\x15Too many menus opened");
    int idx = *(int *)(d + 0x270);
    *(void **)(d + 0x230 + idx * 4) = menu;
    *(int *)(d + 0x270) = idx + 1;
    Window_AddDynamicFlags((void *)menu, 6);
    if (*(void **)(m + 0x244)) {
        *(void **)&tempItem[0x29c] = menu;
        Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(m + 0x244));
    }
    if (*(void **)(m + 0x254))
        UI_PlayLocalSoundAliasByName(*(const char **)(m + 0x254));
    openCount = *(int *)(d + 0x270);
    for (i = openCount - 1; i >= 0; i--) {
        byte *om = *(byte **)(d + 0x230 + i * 4);
        if (!om) continue;
        if (*(int *)(om + 0xd0) == 5) {
            int ch = *(int *)(om + 0xcc);
            if (ch >= 0) { CIN_StopCinematic(ch); *(int *)(om + 0xcc) = -1; }
        }
        for (j = 0; j < *(int *)(om + 0x218); j++) {
            byte *it = *(byte **)(*(byte **)(om + 0x27c) + j * 4);
            if (*(int *)(it + 0xd0) == 5) {
                int ch = *(int *)(it + 0xcc);
                if (ch >= 0) { CIN_StopCinematic(ch); *(int *)(it + 0xcc) = -1; }
                it = *(byte **)(*(byte **)(om + 0x27c) + j * 4);
            }
            if (*(int *)(it + 0x270) == 8)
                CIN_StopCinematic(-*(int *)(it + 0xd8));
        }
    }
    Display_MouseMove(dc, NULL, *(int *)(d + 0xc), *(int *)(d + 0x10));
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
    const char *p = va(name, Dvar_GetString(*(const char **)((byte *)item + 0x2c0)));
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
        byte *menu = (byte *)p;
        rectDef_t newRect = *(rectDef_t *)menu;
        newRect.x += (float)x; newRect.y += (float)y;
        ((void (*)(void *, void *))Window_SetRect)(p, &newRect);
        ((void (*)(void *))Menu_UpdatePosition)(p);
        return 1;
    }
    int openCount = *(int *)(d + 0x270);
    int i = openCount - 1;
    if (i < 0) return 1;
    int startIdx = i;
    for (; i >= 0; i--) {
        byte *menu = *(byte **)(d + 0x230 + i * 4);
        int flags = *(int *)(menu + 0xe8);
        if ((flags & 4) && (flags & 2)) {
            if (*(byte *)(menu + 0xe7) & 1) {
                Menu_HandleMouseMove(dc, (menuDef_t *)menu, (float)x, (float)y);
                return 1;
            }
            startIdx = i; break;
        }
    }
    for (i = 0; i <= startIdx; i++) {
        byte *menu = *(byte **)(d + 0x230 + (startIdx - i) * 4);
        if (Menu_HandleMouseMove(dc, (menuDef_t *)menu, (float)x, (float)y)) return 1;
    }
    return 1;
}

/* Menu_SetNextCursorItem — advance cursor to next focusable item, wrapping */
itemDef_t * Menu_SetNextCursorItem(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *m = (byte *)menu; byte *d = (byte *)dc;
    int oldCursor = *(int *)(m + 0x220); int wrapped = 0; int cursor;
    if (oldCursor == -1) { ((void (*)(void *, int))Menu_SetCursorItem)(menu, 0); wrapped = 1; }
    for (;;) {
        cursor = *(int *)(m + 0x220);
        if (cursor >= *(int *)(m + 0x218)) {
            if (wrapped) return *(itemDef_t **)(*(byte **)(m + 0x27c) + oldCursor * 4);
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, 0); wrapped = 1; cursor = *(int *)(m + 0x220);
        } else {
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, cursor + 1); cursor = *(int *)(m + 0x220);
            if (cursor >= *(int *)(m + 0x218)) {
                if (wrapped) return *(itemDef_t **)(*(byte **)(m + 0x27c) + oldCursor * 4);
                ((void (*)(void *, int))Menu_SetCursorItem)(menu, 0); wrapped = 1; cursor = *(int *)(m + 0x220);
            }
        }
        itemDef_t *item = *(itemDef_t **)(*(byte **)(m + 0x27c) + cursor * 4);
        if (Item_SetFocus(dc, item, (float)*(int *)(d + 0xc), (float)*(int *)(d + 0x10))) {
            cursor = *(int *)(m + 0x220);
            item = *(itemDef_t **)(*(byte **)(m + 0x27c) + cursor * 4);
            Menu_HandleMouseMove(dc, menu, *(float *)item + 1.0f, *((float *)item + 1) + 1.0f);
            cursor = *(int *)(m + 0x220);
            return *(itemDef_t **)(*(byte **)(m + 0x27c) + cursor * 4);
        }
    }
    ((void (*)(void *, int))Menu_SetCursorItem)(menu, oldCursor); return NULL;
}

/* Menu_SetPrevCursorItem — move cursor to previous focusable item, wrapping */
itemDef_t * Menu_SetPrevCursorItem(displayContextDef_t *dc, menuDef_t *menu)
{
    byte *m = (byte *)menu; byte *d = (byte *)dc;
    int oldCursor = *(int *)(m + 0x220); int wrapped = 0; int cursor;
    if (oldCursor < 0) { ((void (*)(void *, int))Menu_SetCursorItem)(menu, *(int *)(m + 0x218) - 1); wrapped = 1; }
    for (;;) {
        cursor = *(int *)(m + 0x220);
        if (cursor <= -1) {
            if (wrapped) goto fail;
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, *(int *)(m + 0x218) - 1); wrapped = 1;
            cursor = *(int *)(m + 0x220); if (cursor < 0) goto fail;
        } else {
            ((void (*)(void *, int))Menu_SetCursorItem)(menu, cursor - 1); cursor = *(int *)(m + 0x220);
            if (cursor < 0) {
                if (wrapped) goto try_focus;
                ((void (*)(void *, int))Menu_SetCursorItem)(menu, *(int *)(m + 0x218) - 1); wrapped = 1;
                cursor = *(int *)(m + 0x220); if (cursor < 0) goto fail;
            }
        }
try_focus:;
        itemDef_t *item = *(itemDef_t **)(*(byte **)(m + 0x27c) + cursor * 4);
        if (Item_SetFocus(dc, item, (float)*(int *)(d + 0xc), (float)*(int *)(d + 0x10))) {
            cursor = *(int *)(m + 0x220);
            item = *(itemDef_t **)(*(byte **)(m + 0x27c) + cursor * 4);
            Menu_HandleMouseMove(dc, menu, *(float *)item + 1.0f, *((float *)item + 1) + 1.0f);
            cursor = *(int *)(m + 0x220);
            return *(itemDef_t **)(*(byte **)(m + 0x27c) + cursor * 4);
        }
    }
fail: ((void (*)(void *, int))Menu_SetCursorItem)(menu, oldCursor); return NULL;
}

/* Item_TextColor — compute text color for an item: fade/pulse/focus/disable logic */
void Item_TextColor(displayContextDef_t *dc, itemDef_t *item, vec4_t *newColor)
{
    byte *it = (byte *)item;
    byte *parent = *(byte **)(it + 0x29c);
    float *out = (float *)newColor;
    int flags = *(int *)(it + 0xe8);
    int curTime = *(int *)((byte *)dc + 4);
    int i;

    /* Handle fade in/out timing */
    if (flags & 0x30) {
        int offsetTime = *(int *)(parent + 0x230);
        float fadeAmount = *(float *)(parent + 0x238);
        float fadeInAmount = *(float *)(parent + 0x23c);
        float clamp = *(float *)(parent + 0x234);

        if (curTime > *(int *)(it + 0x1c8)) {
            *(int *)(it + 0x1c8) = curTime + offsetTime;
            if (flags & 0x10) {
                /* Fade out */
                float alpha = *(float *)(it + 0x1d8);
                alpha -= fadeAmount;
                *(float *)(it + 0x1d8) = alpha;
                if (alpha <= 0.0f) {
                    flags &= ~0x14; /* clear fade out + visible */
                }
            } else {
                /* Fade in */
                float alpha = *(float *)(it + 0x1d8);
                alpha += fadeInAmount;
                *(float *)(it + 0x1d8) = alpha;
                if (alpha >= clamp) {
                    *(float *)(it + 0x1d8) = clamp;
                    flags &= ~0x20; /* clear fade in */
                }
            }
        }
    }

    Window_SetDynamicFlags(item, flags);

    /* Determine which color to use */
    int visFlags = *(int *)(it + 0xe8);
    if ((visFlags & 4) && (visFlags & 2)) {
        /* Item is visible + focused — pulse between focusColor and lowLight */
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = *(float *)(parent + 0x25c + i * 4) * 0.8f;

        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = *(float *)(parent + 0x25c + i * 4);
            float lo = lowLight[i];
            out[i] = hi + (lo - hi) * t;
            if (out[i] < 0.0f) out[i] = 0.0f;
            else if (out[i] > 1.0f) out[i] = 1.0f;
        }
    } else if (*(int *)(it + 0x290) == 1) {
        /* Style 1 — pulse forecolor */
        int pulseTime = curTime;
        if (pulseTime < 0) pulseTime += 255;
        if (!(pulseTime & 0x100)) {
            /* Copy forecolor directly */
            for (i = 0; i < 4; i++)
                out[i] = *(float *)(it + 0x1cc + i * 4);
        } else {
            float lowLight[4];
            for (i = 0; i < 4; i++)
                lowLight[i] = *(float *)(it + 0x1cc + i * 4) * 0.8f;

            float t = sinf((float)(curTime / 22));
            t = t * 0.5f + 0.5f;

            for (i = 0; i < 4; i++) {
                float hi = *(float *)(it + 0x1cc + i * 4);
                float lo = lowLight[i];
                out[i] = hi + (lo - hi) * t;
                if (out[i] < 0.0f) out[i] = 0.0f;
                else if (out[i] > 1.0f) out[i] = 1.0f;
            }
        }
    } else {
        /* Default — copy forecolor */
        for (i = 0; i < 4; i++)
            out[i] = *(float *)(it + 0x1cc + i * 4);
    }

    /* Check dvar disable color override */
    const char *dvarTest = *(const char **)(it + 0x2cc);
    const char *dvarName = *(const char **)(it + 0x2c4);
    if (dvarTest && dvarTest[0] && dvarName && dvarName[0]) {
        if (*(byte *)(it + 0x2d0) & 3) {
            if (!Item_EnableShowViaDvar(item, 1)) {
                /* Disabled — use parent disableColor */
                for (i = 0; i < 4; i++)
                    out[i] = *(float *)(parent + 0x26c + i * 4);
            }
        }
    }
}

/* Item_Text_Paint — paint text item with color, wrapping support */
void Item_Text_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    const char *textPtr = *(const char **)(it + 0x294);
    char text[0x400];
    float color[4];
    int width, height;

    /* Resolve text */
    if (!textPtr) {
        if (!*(void **)(it + 0x2c0))
            return;
        I_strncpyz(text, Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0x400);
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
    int staticFlags = *(int *)(it + 0xe4);
    if (staticFlags & 0x400000) {
        Item_Text_Wrapped_Paint(item, textPtr, color);
        return;
    }
    if (staticFlags & 0x800000) {
        Item_Text_AutoWrapped_Paint(item, textPtr, color);
        return;
    }

    /* Normal text draw */
    FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
    UI_DrawText(textPtr, 0x7fffffff, font,
        *(float *)(it + 0x210), *(float *)(it + 0x214),
        *(int *)(it + 0x10), *(int *)(it + 0x14),
        *(float *)(it + 0x28c), color, *(int *)(it + 0x290));
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
    byte *parent = *(byte **)(it + 0x29c);
    float newColor[4];
    float value = 0.0f;
    int i;

    /* Get dvar value */
    if (*(void **)(it + 0x2c0)) {
        value = (float)atof(Dvar_GetVariantString(*(const char **)(it + 0x2c0)));
    }

    /* Compute color: focused items pulse, unfocused use forecolor */
    int flags = *(int *)(it + 0xe8);
    if ((flags & 4) && (flags & 2)) {
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = *(float *)(parent + 0x25c + i * 4) * 0.8f;

        int curTime = *(int *)((byte *)dc + 4);
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = *(float *)(parent + 0x25c + i * 4);
            float lo = lowLight[i];
            newColor[i] = hi + (lo - hi) * t;
            if (newColor[i] < 0.0f) newColor[i] = 0.0f;
            else if (newColor[i] > 1.0f) newColor[i] = 1.0f;
        }
    } else {
        for (i = 0; i < 4; i++)
            newColor[i] = *(float *)(it + 0x1cc + i * 4);
    }

    /* Choose yes/no text */
    const char *yesNoStr;
    if (value != 0.0f)
        yesNoStr = UI_SafeTranslateString("EXE_YES");
    else
        yesNoStr = UI_SafeTranslateString("EXE_NO");

    /* Draw the text */
    byte *textRect = it + 0x210;
    FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
    float textX, textY;

    if (*(int *)(it + 0x294)) {
        /* Has label text — paint it first */
        Item_Text_Paint(dc, item);
        textX = *(float *)(it + 0x210) + *(float *)(it + 0x218) + 8.0f;
        textY = *(float *)(textRect + 4);
    } else {
        textX = *(float *)(it + 0x210);
        textY = *(float *)(textRect + 4);
    }

    UI_DrawText(yesNoStr, 0x7fffffff, font, textX, textY,
        *(int *)(it + 0x10), *(int *)(it + 0x14),
        *(float *)(it + 0x28c), newColor, *(int *)(it + 0x290));
}

/* Item_Slider_Paint — paint slider bar and thumb */
extern void *imp_sharedUiInfo;
void Item_Slider_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent = *(byte **)(it + 0x29c);
    float newColor[4];
    float y;
    float x;
    int i;

    /* Get dvar value (unused but called for side effects) */
    if (*(void **)(it + 0x2c0)) {
        Dvar_GetVariantString(*(const char **)(it + 0x2c0));
        atof(Dvar_GetVariantString(*(const char **)(it + 0x2c0)));
    }

    /* Compute color: focused items pulse, others use forecolor */
    int flags = *(int *)(it + 0xe8);
    if ((flags & 4) && (flags & 2)) {
        /* Focused — compute pulsing color */
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = *(float *)(parent + 0x25c + i * 4) * 0.8f;

        /* sin-based pulse: time / 22 (magic constant 0x1b4e81b5 = divide by 22) */
        int curTime = *(int *)((byte *)dc + 4);
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = *(float *)(parent + 0x25c + i * 4);
            float lo = lowLight[i];
            newColor[i] = hi + (lo - hi) * t;
            if (newColor[i] < 0.0f) newColor[i] = 0.0f;
            else if (newColor[i] > 1.0f) newColor[i] = 1.0f;
        }
    } else {
        /* Not focused — use forecolor */
        for (i = 0; i < 4; i++)
            newColor[i] = *(float *)(it + 0x1cc + i * 4);
    }

    y = *(float *)(it + 4);

    if (*(int *)(it + 0x294)) {
        /* Has text — paint text first, then slider starts after text rect */
        Item_Text_Paint(dc, item);
        x = *(float *)(it + 0x210) + *(float *)(it + 0x218) + 8.0f;
    } else {
        x = *(float *)it;
    }

    /* Draw slider bar — real signature: (x, y, w, h, horzAlign, vertAlign, color, material) */
    byte *uiInfo = (byte *)imp_sharedUiInfo;
    ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
        x, y, 96.0f, 16.0f,
        *(int *)(it + 0x10), *(int *)(it + 0x14), newColor,
        *(int *)(uiInfo + 0x18));

    /* Draw slider thumb */
    float thumbX = Item_Slider_ThumbPosition(item);
    ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
        thumbX - 5.0f, y - 2.0f, 10.0f, 20.0f,
        *(int *)(it + 0x10), *(int *)(it + 0x14), newColor,
        *(int *)(uiInfo + 0x1c));
}

/* Item_Bind_Paint — paint key binding item with pulsing focus color */
void Item_Bind_Paint(displayContextDef_t *dc, itemDef_t *item)
{
    byte *it = (byte *)item;
    byte *parent = *(byte **)(it + 0x29c);
    float newColor[4];
    int maxChars;
    int i;

    /* Get editFieldDef for maxChars */
    editFieldDef_t *editPtr = Item_GetEditFieldDef(item);
    if (!editPtr || !*(int *)((byte *)editPtr + 0x18))
        return;
    maxChars = *(int *)((byte *)editPtr + 0x18);

    /* Get dvar value (for side effects) */
    if (*(void **)(it + 0x2c0)) {
        atof(Dvar_GetVariantString(*(const char **)(it + 0x2c0)));
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
    int flags = *(int *)(it + 0xe8);
    if ((flags & 4) && (flags & 2)) {
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = *(float *)(parent + 0x25c + i * 4) * 0.8f;

        int curTime = *(int *)((byte *)dc + 4);
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;

        for (i = 0; i < 4; i++) {
            float hi = *(float *)(parent + 0x25c + i * 4);
            float lo = lowLight[i];
            newColor[i] = hi + (lo - hi) * t;
            if (newColor[i] < 0.0f) newColor[i] = 0.0f;
            else if (newColor[i] > 1.0f) newColor[i] = 1.0f;
        }
    } else {
        for (i = 0; i < 4; i++)
            newColor[i] = *(float *)(it + 0x1cc + i * 4);
    }

draw:;
    /* Paint text label first if present */
    byte *textRect = it + 0x210;
    if (*(int *)(it + 0x294)) {
        Item_Text_Paint(dc, item);
        /* Draw bind text after label */
        float textX = *(float *)(it + 0x210) + *(float *)(it + 0x218) + 8.0f;
        float textY = *(float *)(textRect + 4);
        FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
        UI_DrawText("FIXME", maxChars, font, textX, textY,
            *(int *)(it + 0x10), *(int *)(it + 0x14),
            *(float *)(it + 0x28c), newColor, *(int *)(it + 0x290));
    } else {
        float textX = *(float *)(it + 0x210);
        float textY = *(float *)(textRect + 4);
        FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), *(float *)(it + 0x28c));
        UI_DrawText("FIXME", maxChars, font, textX, textY,
            *(int *)(it + 0x10), *(int *)(it + 0x14),
            *(float *)(it + 0x28c), newColor, *(int *)(it + 0x290));
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

    parent = *(byte **)(it + 0x29c);
    flags = *(int *)(it + 0xe8);

    /* Fade handling */
    float fadeInAmount = *(float *)(parent + 0x23c);
    float fadeAmount = *(float *)(parent + 0x238);
    int offsetTime = *(int *)(parent + 0x230);
    float clamp = *(float *)(parent + 0x234);
    int curTime = *(int *)((byte *)dc + 4);

    if (flags & 0x30) {
        if (curTime > *(int *)(it + 0x1c8)) {
            *(int *)(it + 0x1c8) = curTime + offsetTime;
            if (flags & 0x10) {
                float alpha = *(float *)(it + 0x1d8) - fadeAmount;
                *(float *)(it + 0x1d8) = alpha;
                if (alpha <= 0.0f)
                    flags &= ~0x14;
            } else {
                float alpha = *(float *)(it + 0x1d8) + fadeInAmount;
                *(float *)(it + 0x1d8) = alpha;
                if (alpha >= clamp) {
                    *(float *)(it + 0x1d8) = clamp;
                    flags &= ~0x20;
                }
            }
        }
    }

    Window_SetDynamicFlags(item, flags);

    /* Start with forecolor */
    for (i = 0; i < 4; i++)
        color[i] = *(float *)(it + 0x1cc + i * 4);

    /* Check for focus/pulse color */
    int visFlags = *(int *)(it + 0xe8);
    if ((visFlags & 4) && (visFlags & 2)) {
        /* Focused — pulse between focusColor and lowLight */
        float lowLight[4];
        for (i = 0; i < 4; i++)
            lowLight[i] = *(float *)(parent + 0x25c + i * 4) * 0.8f;
        float t = sinf((float)(curTime / 22));
        t = t * 0.5f + 0.5f;
        for (i = 0; i < 4; i++) {
            float hi = *(float *)(parent + 0x25c + i * 4);
            color[i] = hi + (lowLight[i] - hi) * t;
            if (color[i] < 0.0f) color[i] = 0.0f;
            else if (color[i] > 1.0f) color[i] = 1.0f;
        }
    } else if (*(int *)(it + 0x290) == 1) {
        /* Style 1 — pulse forecolor */
        int pt = curTime;
        if (pt < 0) pt += 255;
        if (pt & 0x100) {
            float lowLight[4];
            for (i = 0; i < 4; i++)
                lowLight[i] = *(float *)(it + 0x1cc + i * 4) * 0.8f;
            float t = sinf((float)(curTime / 22));
            t = t * 0.5f + 0.5f;
            for (i = 0; i < 4; i++) {
                float hi = *(float *)(it + 0x1cc + i * 4);
                color[i] = hi + (lowLight[i] - hi) * t;
                if (color[i] < 0.0f) color[i] = 0.0f;
                else if (color[i] > 1.0f) color[i] = 1.0f;
            }
        }
    }

    /* Dvar disable color check */
    if (*(byte *)(it + 0x2d0) & 3) {
        if (!Item_EnableShowViaDvar(item, 1)) {
            for (i = 0; i < 4; i++)
                color[i] = *(float *)(parent + 0x26c + i * 4);
        }
    }

    /* Draw */
    float scale = *(float *)(it + 0x28c);
    int style = *(int *)(it + 0x290);
    int ownerDraw = *(int *)(it + 0xd8);
    int ownerDrawFlags = *(int *)(it + 0xdc);
    int cursor = *(int *)(it + 0x278);
    float feederFloat = *(float *)(it + 0x2d8);
    int material = *(int *)(it + 0x20c);
    FontHandle font = UI_GetFontHandle(*(int *)(it + 0x27c), scale);

    if (*(int *)(it + 0x294) && ((const char *)*(int *)(it + 0x294))[0]) {
        /* Has text label — paint text first */
        Item_Text_Paint(dc, item);
        byte *textRect = it + 0x210;
        float ownerX = *(float *)(it + 0x210) + *(float *)(textRect + 8) + 8.0f;
        UI_OwnerDraw(ownerX, *(float *)(it + 4), *(float *)(it + 8), *(float *)(it + 0xc),
            *(int *)(it + 0x10), *(int *)(it + 0x14), 0.0f, *(float *)(it + 0x288),
            ownerDraw, ownerDrawFlags, scale, color, (MaterialHandle)(intptr_t)material, style);
    } else if (*(int *)(it + 0x294)) {
        /* Has text pointer but empty — use textRect x + w offset */
        byte *textRect = it + 0x210;
        float ownerX = *(float *)(it + 0x210) + *(float *)(textRect + 8);
        UI_OwnerDraw(ownerX, *(float *)(it + 4), *(float *)(it + 8), *(float *)(it + 0xc),
            *(int *)(it + 0x10), *(int *)(it + 0x14), 0.0f, *(float *)(it + 0x288),
            ownerDraw, ownerDrawFlags, scale, color, (MaterialHandle)(intptr_t)material, style);
    } else {
        /* No text — use item position directly */
        UI_OwnerDraw(*(float *)it, *(float *)(it + 4), *(float *)(it + 8), *(float *)(it + 0xc),
            *(int *)(it + 0x10), *(int *)(it + 0x14), *(float *)(it + 0x284), *(float *)(it + 0x288),
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
    if (!*(void **)(it + 0x2c0))
        return 0;
    if (!(*(byte *)(it + 0xe8) & 4) || !(*(byte *)(it + 0xe8) & 2))
        return 0;

    /* Mouse click (keys 0xc8-0xca) — check if within item bounds */
    if (key >= 0xc8 && key <= 0xca) {
        float cx = (float)*(int *)(d + 0xc);
        float cy = (float)*(int *)(d + 0x10);
        /* Rect-in-rect test with screen placement */
        float rx = *(float *)it, ry = *(float *)(it + 4);
        float rw = *(float *)(it + 8), rh = *(float *)(it + 0xc);
        CalcScreenX(&cx, 4);
        CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(it + 0x10), *(int *)(it + 0x14));
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

    float maxVal = *((float *)editDef + 1);
    float minVal = *(float *)editDef;
    float step = (maxVal - minVal) * 0.05f;

    const char *valStr = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
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

    Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), va("%g", (double)value));
    return 1;
}

/* Item_YesNo_HandleKey — toggle yes/no dvar on click or key press */
qboolean Item_YesNo_HandleKey(displayContextDef_t *dc, itemDef_t *item, int key)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;
    char dvarString[0x19];

    if (!*(void **)(it + 0x2c0))
        return 0;
    if (!(*(byte *)(it + 0xe8) & 4) || !(*(byte *)(it + 0xe8) & 2))
        return 0;

    /* Mouse click — check if within item rect */
    if (key >= 0xc8 && key <= 0xca) {
        float cx = (float)*(int *)(d + 0xc);
        float cy = (float)*(int *)(d + 0x10);
        float rx = *(float *)it, ry = *(float *)(it + 4);
        float rw = *(float *)(it + 8), rh = *(float *)(it + 0xc);
        CalcScreenX(&cx, 4);
        CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(it + 0x10), *(int *)(it + 0x14));
        if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh)
            return 0;
        /* Fall through to toggle */
    } else if (key != 0xd && key != 0x9c && key != 0x9d && key != 0xa4 && key != 0xa3 &&
               key != 0xc8 && key != 0xc9 && key != 0xca) {
        return 0;
    }

    /* Toggle the dvar value */
    I_strncpyz(dvarString, Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0x19);
    int val = atoi(dvarString);
    Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), va("%i", !val));
    return 1;
}

/* Item_SetFocus — set focus to an item: unfocus all siblings, run scripts, play sound */
extern void UI_PlayLocalSoundAlias(int sound);
qboolean Item_SetFocus(displayContextDef_t *dc, itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    byte *d = (byte *)dc;
    int i;

    int defaultSound = *(int *)(*(byte *)imp_sharedUiInfo + 0x40);

    /* Validation */
    if (!item) return 0;
    if (*(byte *)(it + 0xe6) & 0x10) return 0; /* disabled */
    int flags = *(int *)(it + 0xe8);
    if (!(flags & 4)) return 0; /* not visible */
    if (flags & 2) return 1; /* already focused */

    /* Get parent menu */
    byte *parent = *(byte **)(it + 0x29c);

    /* If parent exists but is not visible+focused, find the focused menu */
    if (parent) {
        int pflags = *(int *)(parent + 0xe8);
        if (!(pflags & 4) || !(pflags & 2)) {
            /* Find focused menu from open menus */
            byte *focusedMenu = NULL;
            int openCount = *(int *)(d + 0x270);
            for (i = openCount - 1; i >= 0; i--) {
                byte *om = *(byte **)(d + 0x230 + i * 4);
                int omf = *(int *)(om + 0xe8);
                if ((omf & 4) && (omf & 2)) { focusedMenu = om; break; }
            }
            if (!focusedMenu) goto check_dvar;

            /* Hit test cursor against focused menu rect */
            float rx = *(float *)focusedMenu, ry = *(float *)(focusedMenu + 4);
            float rw = *(float *)(focusedMenu + 8), rh = *(float *)(focusedMenu + 0xc);
            float cx = x, cy = y;
            CalcScreenX(&cx, 4);
            CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(focusedMenu + 0x10), *(int *)(focusedMenu + 0x14));
            if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh)
                goto check_dvar;

            /* Also hit test parent rect */
            float prx = *(float *)parent, pry = *(float *)(parent + 4);
            float prw = *(float *)(parent + 8), prh = *(float *)(parent + 0xc);
            float pcx = x, pcy = y;
            CalcScreenX(&pcy, 4);
            CalcScreenY(&pcx, 4);
            CalcScreenPlacement(&prx, &prw, &pry, &prh, *(int *)(parent + 0x10), *(int *)(parent + 0x14));
            if (pcx < prx || pcx > prx + prw || pcy < pry || pcy > pry + prh)
                goto check_dvar;
        }
    }

check_dvar:;
    /* Dvar show checks */
    int dvarFlags = *(int *)(it + 0x2d0);
    if (dvarFlags & 3) {
        if (!Item_EnableShowViaDvar(item, 1))
            return 0;
        dvarFlags = *(int *)(it + 0x2d0);
    }
    if (dvarFlags & 0xc) {
        if (!Item_EnableShowViaDvar(item, 4))
            return 0;
    }

    /* Get parent menu for item iteration */
    byte *menu = *(byte **)(it + 0x29c);

    /* Remove focus from all items in menu, track old focus */
    void *oldFocus = NULL;
    if (menu && *(int *)(menu + 0x218) > 0) {
        int itemCount = *(int *)(menu + 0x218);
        for (i = 0; i < itemCount; i++) {
            byte *sibling = *(byte **)(*(byte **)(menu + 0x27c) + i * 4);
            int sf = *(int *)(sibling + 0xe8);
            if ((sf & 4) && (sf & 2))
                oldFocus = sibling;
            Window_RemoveDynamicFlags((void *)sibling, 2);
            /* Run lostFocus script */
            byte *reloaded = *(byte **)(*(byte **)(menu + 0x27c) + i * 4);
            if (*(void **)(reloaded + 0x2bc))
                Item_RunScript(dc, (itemDef_t *)reloaded, *(const char **)(reloaded + 0x2bc));
        }
    } else {
        oldFocus = NULL;
    }

    /* Check item type for focusability */
    int itemType = *(int *)(it + 0x270);
    if (itemType == 0) {
        /* Type 0: hit-test text rect */
        byte *textRect = it + 0x210;
        float tw = *(float *)(textRect + 8);
        float th = *(float *)(textRect + 0xc);
        float tx = *(float *)(it + 0x210);
        float ty = *(float *)(textRect + 4) - th;
        float tcx = x, tcy = y;
        CalcScreenX(&tcx, 4);
        CalcScreenY(&tcy, 4);
        CalcScreenPlacement(&tx, &tw, &ty, &th, *(int *)(textRect + 0x10), *(int *)(textRect + 0x14));
        if (tcx < tx || tcx > tx + tw) goto fail;
        if (tcy < ty || tcy > ty + th) goto fail;

        /* Focus the item */
        Window_AddDynamicFlags((void *)it, 2);
        int itemSound = *(int *)(it + 0x2d4);
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
    if (*(void **)(it + 0x2b8))
        Item_RunScript(dc, item, *(const char **)(it + 0x2b8));

    /* Play sound */
    int itemSound = *(int *)(it + 0x2d4);
    if (itemSound) {
        UI_PlayLocalSoundAlias(itemSound);
    } else if (defaultSound) {
        UI_PlayLocalSoundAlias(defaultSound);
    }

set_cursor:;
    /* Find item index and set cursor */
    if (menu) {
        int itemCount = *(int *)(menu + 0x218);
        byte *items = *(byte **)(menu + 0x27c);
        for (i = 0; i < itemCount; i++) {
            if (*(void **)(items + i * 4) == item) {
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
        if (*(void **)((byte *)oldFocus + 0x2b8))
            Item_RunScript(dc, (itemDef_t *)oldFocus, *(const char **)((byte *)oldFocus + 0x2b8));
    }
    /* Find item index and set cursor anyway */
    if (menu) {
        int itemCount = *(int *)(menu + 0x218);
        byte *items = *(byte **)(menu + 0x27c);
        for (i = 0; i < itemCount; i++) {
            if (*(void **)(items + i * 4) == item) {
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

/* Item_ListBox_OverLB — determine which scrollbar region the cursor is over */
int Item_ListBox_OverLB(itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    int horzAlign = *(int *)(it + 0x10);
    int vertAlign = *(int *)(it + 0x14);

    UI_FeederCount(*(int *)(it + 0x2d8));
    if (!Item_GetListBoxDef(item)) return 0;

    if (*(byte *)(it + 0xe6) & 0x20) {
        /* Horizontal listbox — scrollbar is on the right side */
        float scrollX = *(float *)it + *(float *)(it + 8) - 16.0f;
        float itemY = *(float *)(it + 4);

        /* Down scroll button (bottom-right) */
        float rx = scrollX, ry = itemY, rw = 16.0f, rh = 16.0f;
        float cx = x, cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x200;

        /* Up scroll button (top-right) */
        float endY = itemY + *(float *)(it + 0xc) - 16.0f;
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
        float scrollX = *(float *)it + *(float *)(it + 8) - 16.0f;
        float itemY = *(float *)(it + 4);

        /* Up scroll button (top-right) */
        float rx = scrollX, ry = itemY, rw = 16.0f, rh = 16.0f;
        float cx = x, cy = y;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh)
            return 0x100;

        /* Down scroll button (bottom-right) */
        float endY = itemY + *(float *)(it + 0xc) - 16.0f;
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
    byte *listPtr;
    int count, max, viewmax, flags;
    int inRect;

    listPtr = (byte *)Item_GetListBoxDef(item);
    if (!listPtr)
        return 0;

    count = UI_FeederCount(*(int *)(it + 0x2d8));

    /* Rect hit test */
    {
        float compareX, compareY;
        float compareRect_x, compareRect_y, compareRect_w, compareRect_h;

        compareX = (float)*(int *)(d + 0xc);
        compareY = (float)*(int *)(d + 0x10);

        compareRect_x = *(float *)it;
        compareRect_y = *(float *)(it + 4);
        compareRect_w = *(float *)(it + 8);
        compareRect_h = *(float *)(it + 0xc);

        CalcScreenX(&compareX, 4);
        CalcScreenY(&compareY, 4);
        CalcScreenPlacement(&compareRect_x, &compareRect_w, &compareRect_y, &compareRect_h,
                            *(int *)(it + 0x10), *(int *)(it + 0x14));

        if (compareX >= compareRect_x &&
            compareX <= compareRect_x + compareRect_w &&
            compareY >= compareRect_y &&
            compareY <= compareRect_y + compareRect_h)
            inRect = 1;
        else
            inRect = 0;
    }

    flags = *(int *)(it + 0xe8);

    if (!force) {
        if (!inRect || !(flags & 2))
            return 0;
    }

    ((void (*)(void *))UI_OverrideCursorPos)(item);
    max = Item_ListBox_MaxScroll(item);

    if (*(byte *)(it + 0xe6) & 0x20) {
        /* ========== HORIZONTAL ========== */
        viewmax = (int)(*(float *)(it + 8) / *(float *)(listPtr + 0x34));

        if (key == 0x9c) {
            /* UP in horizontal mode */
            if (*(int *)(listPtr + 0x108)) {
                /* notselectable: scroll start - 1 */
                goto scroll_start_dec;
            }
            ListBox_SetCursorPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) - 1);
            if (*(int *)(listPtr + 0x24) < 0)
                ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
            if (*(int *)(listPtr + 0x24) < *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24));
            if (*(int *)(listPtr + 0x24) >= viewmax + *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) - viewmax + 1);
            Item_SetCursorPos(item, *(int *)(listPtr + 0x24));
            goto do_feeder_selection;
        }

        if (key == 0x9d) {
            /* DOWN in horizontal mode */
            if (*(int *)(listPtr + 0x108)) {
                /* notselectable: scroll start + 1 */
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)listPtr + 1);
                if (count > *(int *)listPtr)
                    return 1;
                ListBox_SetStartPos((itemDef_t *)listPtr, count - 1);
                return 1;
            }
            ListBox_SetCursorPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) + 1);
            if (*(int *)(listPtr + 0x24) < *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24));
            if (count <= *(int *)(listPtr + 0x24))
                ListBox_SetCursorPos((itemDef_t *)listPtr, count - 1);
            if (*(int *)(listPtr + 0x24) >= viewmax + *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) - viewmax + 1);
            Item_SetCursorPos(item, *(int *)(listPtr + 0x24));
            goto do_feeder_selection;
        }
        /* Fall through to common key handling */
    } else {
        /* ========== VERTICAL ========== */
        viewmax = (int)(*(float *)(it + 0xc) / *(float *)(listPtr + 0x38));

        if (key == 0x9a || key == 0xce) {
            /* LEFT/previous in vertical mode */
            if (*(int *)(listPtr + 0x108)) {
                /* notselectable: scroll start - 1 */
                goto scroll_start_dec;
            }
            Item_SetCursorPos(item, *(int *)(it + 0x2dc) - 1);
            if (*(int *)(it + 0x2dc) < 0)
                Item_SetCursorPos(item, 0);
            if (*(int *)(it + 0x2dc) < *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(it + 0x2dc));
            if (*(int *)(it + 0x2dc) >= viewmax + *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(it + 0x2dc) - viewmax + 1);
            UI_FeederSelection(*(float *)(it + 0x2d8), *(int *)(it + 0x2dc));
            return 1;
        }

        if (key == 0x9b || key == 0xcd) {
            /* RIGHT/next in vertical mode */
            if (*(int *)(listPtr + 0x108)) {
                /* notselectable: scroll start + 1 */
                goto scroll_start_inc;
            }
            Item_SetCursorPos(item, *(int *)(it + 0x2dc) + 1);
            if (*(int *)(it + 0x2dc) < *(int *)listPtr)
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(it + 0x2dc));
            if (count <= *(int *)(it + 0x2dc))
                Item_SetCursorPos(item, count - 1);
            if (*(int *)(it + 0x2dc) < 0)
                Item_SetCursorPos(item, 0);
            if (*(int *)(it + 0x2dc) >= viewmax + *(int *)listPtr) {
                ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(it + 0x2dc) - viewmax + 1);
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
        if (*(float *)(it + 0x2d8) == 18.0f) {
            ((void (*)(void *))UI_OverrideCursorPos)(item);
            UI_FeederSelection(*(float *)(it + 0x2d8), *(int *)(it + 0x2dc));
        }

        /* Double-click check */
        {
            int curTime = *(int *)(d + 4);
            if (curTime < lastListBoxClickTime &&
                *(const char **)(listPtr + 0x104) != NULL &&
                *(int *)(it + 0x2dc) == *(int *)(listPtr + 0x24)) {
                if (ListBox_HasValidCursorPos((itemDef_t *)listPtr)) {
                    Item_RunScript(dc, item, *(const char **)(listPtr + 0x104));
                    curTime = *(int *)(d + 4);
                }
            }

            lastListBoxClickTime = curTime + 0x12c;

            if (*(int *)(it + 0x2dc) == *(int *)(listPtr + 0x24))
                return 1;

            if (*(int *)(it + 0x2dc) < 0)
                Item_SetCursorPos(item, *(int *)(listPtr + 0x24));

            {
                int oldCursorPos = *(int *)(listPtr + 0x24);
                if (oldCursorPos < UI_FeederCount(*(int *)(it + 0x2d8)))
                    Item_SetCursorPos(item, *(int *)(listPtr + 0x24));
            }
            goto do_feeder_selection;
        }
    }

    if (key == 0xa5) {
        /* HOME */
        if (*(int *)(listPtr + 0x108)) {
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
        if (*(int *)(listPtr + 0x108)) {
            /* notselectable */
            ListBox_SetStartPos((itemDef_t *)listPtr, max);
            return 1;
        }
        Item_SetCursorPos(item, count - 1);
        ListBox_SetCursorPos((itemDef_t *)listPtr, count - 1);
        if (*(int *)(it + 0x2dc) >= viewmax + *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(it + 0x2dc) - viewmax + 1);
        if (*(int *)(it + 0x2dc) < 0) {
            Item_SetCursorPos(item, 0);
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        }
        goto do_feeder_selection;
    }

    if (key == 0xa4) {
        /* PAGE UP */
        if (*(int *)(listPtr + 0x108)) {
            goto scroll_start_pgup;
        }
        ListBox_SetCursorPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) - viewmax);
        if (*(int *)(listPtr + 0x24) < 0)
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        if (*(int *)(listPtr + 0x24) < *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24));
        if (*(int *)(listPtr + 0x24) >= viewmax + *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) - viewmax + 1);
        Item_SetCursorPos(item, *(int *)(listPtr + 0x24));
        goto do_feeder_selection;
    }

    if (key == 0xa3) {
        /* PAGE DOWN */
        if (*(int *)(listPtr + 0x108)) {
            goto scroll_start_pgdn;
        }
        ListBox_SetCursorPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) + viewmax);
        if (*(int *)(listPtr + 0x24) < *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24));
        if (count <= *(int *)(listPtr + 0x24))
            ListBox_SetCursorPos((itemDef_t *)listPtr, count - 1);
        if (*(int *)(listPtr + 0x24) < 0)
            ListBox_SetCursorPos((itemDef_t *)listPtr, 0);
        if (*(int *)(listPtr + 0x24) >= viewmax + *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x24) - viewmax + 1);
        Item_SetCursorPos(item, *(int *)(listPtr + 0x24));
        goto do_feeder_selection;
    }

    return 0;

scroll_start_dec:
    {
        int newStart = *(int *)listPtr - 1;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (*(int *)listPtr < 0)
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        return 1;
    }

scroll_start_inc:
    {
        int newStart = *(int *)listPtr + 1;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (max < *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, max);
        return 1;
    }

scroll_start_pgup:
    {
        int newStart = *(int *)listPtr - viewmax;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (*(int *)listPtr < 0)
            ListBox_SetStartPos((itemDef_t *)listPtr, 0);
        return 1;
    }

scroll_start_pgdn:
    {
        int newStart = *(int *)listPtr + viewmax;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        if (max < *(int *)listPtr)
            ListBox_SetStartPos((itemDef_t *)listPtr, max);
        return 1;
    }

do_feeder_selection:
    UI_FeederSelection(*(float *)(it + 0x2d8), *(int *)(it + 0x2dc));
    return 1;
}


/* Scroll_ListBox_ThumbFunc — drag-thumb scroll for listbox */
static void Scroll_ListBox_ThumbFunc(displayContextDef_t *dc, void *p)
{
    byte *d = (byte *)dc;
    byte *scroll = (byte *)p;
    itemDef_t *scrollItem = *(itemDef_t **)(scroll + 0x18);
    byte *it = (byte *)scrollItem;
    byte *listPtr = (byte *)Item_GetListBoxDef(scrollItem);

    if (!listPtr) return;

    if (*(byte *)(it + 0xe6) & 0x20) {
        /* Horizontal */
        float cursorX = (float)*(int *)(d + 0xc);
        if (cursorX == *(float *)(scroll + 0x10))
            goto check_auto;
        /* Compute new start pos from cursor position */
        float startX = *(float *)it + 16.0f + 1.0f;
        float scrollArea = *(float *)(it + 8) - 32.0f - 2.0f;
        int maxScroll = Item_ListBox_MaxScroll(scrollItem);
        float thumbPos = (cursorX - startX - 8.0f) * (float)maxScroll / (scrollArea - 16.0f);
        int newStart = (int)thumbPos;
        if (newStart < 0) newStart = 0;
        else if (newStart > maxScroll) newStart = maxScroll;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        *(float *)(scroll + 0x10) = cursorX;
    } else {
        /* Vertical */
        float cursorY = (float)*(int *)(d + 0x10);
        if (cursorY == *(float *)(scroll + 0x14))
            goto check_auto;
        /* Compute new start pos from cursor position */
        float startY = *(float *)(it + 4) + 16.0f + 1.0f;
        float scrollArea = *(float *)(it + 0xc) - 32.0f - 2.0f;
        int maxScroll = Item_ListBox_MaxScroll(scrollItem);
        float thumbPos = (cursorY - startY - 8.0f) * (float)maxScroll / (scrollArea - 16.0f);
        int newStart = (int)thumbPos;
        if (newStart < 0) newStart = 0;
        else if (newStart > maxScroll) newStart = maxScroll;
        ListBox_SetStartPos((itemDef_t *)listPtr, newStart);
        *(float *)(scroll + 0x14) = cursorY;
    }

check_auto:;
    /* Auto-scroll: if past hold time, trigger key repeat */
    int curTime = *(int *)(d + 4);
    while (curTime > *(int *)scroll) {
        Item_ListBox_HandleKey(dc, *(void **)(scroll + 0x18), *(int *)(scroll + 0xc), 1, 0);
        *(int *)scroll = curTime + *(int *)(scroll + 8);
    }

    if (curTime > *(int *)(scroll + 4)) {
        *(int *)(scroll + 4) = curTime + 150;
        if (*(int *)(scroll + 8) > 20)
            *(int *)(scroll + 8) -= 40;
    }
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
            float cx = (float)*(int *)(d + 0xc);
            float cy = (float)*(int *)(d + 0x10);
            float rx = *(float *)it, ry = *(float *)(it + 4);
            float rw = *(float *)(it + 8), rh = *(float *)(it + 0xc);
            CalcScreenX(&cx, 4);
            CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(it + 0x10), *(int *)(it + 0x14));
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
        const char *dvarName = *(const char **)(it + 0x2c0);
        /* Find binding index */
        for (i = 0; i < 0x38; i++) {
            if (I_stricmp(dvarName, *(const char **)((byte *)g_bindings + i * 0x14)) == 0)
                break;
        }
        if (i < 0x38) {
            /* Unbind both keys */
            int idx = i * 0x14;
            int key1 = *(int *)((byte *)g_bindings + idx + 12);
            if (key1 != -1) {
                Key_SetBinding(key1, str_002157b8);
                *(int *)((byte *)g_bindings + idx + 12) = -1;
            }
            int key2 = *(int *)((byte *)g_bindings + idx + 16);
            if (key2 != -1) {
                Key_SetBinding(key2, str_002157b8);
                *(int *)((byte *)g_bindings + idx + 16) = -1;
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
        byte *entry = (byte *)g_bindings;
        while (entry != (byte *)updateScreenCalled) {
            if (*(int *)(entry + 0x10) == key) {
                *(int *)(entry + 0x10) = -1;
            }
            if (*(int *)(entry + 0xc) == key) {
                /* Shift key2 to key1, clear key2 */
                *(int *)(entry + 0xc) = *(int *)(entry + 0x10);
                *(int *)(entry + 0x10) = -1;
            }
            entry += 0x14;
        }
    }

    /* Find binding entry for this item's dvar */
    const char *bindName = *(const char **)(it + 0x2c0);
    int bindIdx = -1;
    for (i = 0; i < 0x38; i++) {
        if (I_stricmp(bindName, *(const char **)((byte *)g_bindings + i * 0x14)) == 0) {
            bindIdx = i;
            break;
        }
    }

    if (bindIdx >= 0 && key != -1) {
        int offset = bindIdx * 0x14;
        if (*(int *)((byte *)g_bindings + offset + 12) == -1) {
            *(int *)((byte *)g_bindings + offset + 12) = key;
        } else {
            *(int *)((byte *)g_bindings + offset + 16) = key;
        }
    }

    Controls_SetConfig(0);
    g_waitingForKey = 0;
    g_bindItem = NULL;
    return 1;
}

/* Item_HandleKey — dispatch key input to item-type-specific handlers */
/* Handles mouse click capture setup for listbox/slider, type-based dispatch via switch */
static int Item_HandleKey_RectContainsPoint(byte *it, float cx, float cy)
{
    float rx = *(float *)it, ry = *(float *)(it + 4);
    float rw = *(float *)(it + 8), rh = *(float *)(it + 0xc);
    CalcScreenX(&cx, 4);
    CalcScreenY(&cy, 4);
    CalcScreenPlacement(&rx, &ry, &rw, &rh, *(int *)(it + 0x10), *(int *)(it + 0x14));
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
            int itemType = *(int *)(it + 0x270);
            if (itemType == 6) {
                /* Listbox — check scrollbar region */
                float lbx = (float)*(int *)(d + 0xc);
                float lby = (float)*(int *)(d + 0x10);
                int overLB = Item_ListBox_OverLB(item, lbx, lby);
                if (overLB & 0x300) {
                    /* Up/down arrow region — auto-scroll */
                    scrollInfo.nextScrollTime = *(int *)(d + 4) + 500;
                    scrollInfo.nextAdjustTime = *(int *)(d + 4) + 150;
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
                    scrollInfo.xStart = (float)*(int *)(d + 0xc);
                    scrollInfo.yStart = (float)*(int *)(d + 0x10);
                    captureData = &scrollInfo;
                    captureFunc = Scroll_ListBox_ThumbFunc;
                    itemCapture = item;
                }
                /* Fall through to type switch */
            } else if (itemType == 0xa) {
                /* Slider — check thumb hit test */
                float sy = (float)*(int *)(d + 0x10);
                float sx = (float)*(int *)(d + 0xc);
                float thumbX = Item_Slider_ThumbPosition(item);
                float itemY = *(float *)(it + 4) - 2.0f;
                int horzAlign = *(int *)(it + 0x10);
                int vertAlign = *(int *)(it + 0x14);

                float rx = thumbX - 5.0f, ry = itemY;
                float rw = 10.0f, rh = 20.0f;
                float cx = sx, cy = sy;
                CalcScreenX(&cx, 4);
                CalcScreenY(&cy, 4);
                CalcScreenPlacement(&rx, &ry, &rw, &rh, horzAlign, vertAlign);
                int hit = (cx >= rx && rx + rw >= cx && cy >= ry && ry + rh >= cy) ? 0x400 : 0;

                if (hit) {
                    scrollInfo.scrollKey = key;
                    scrollInfo.item = item;
                    scrollInfo.xStart = (float)*(int *)(d + 0xc);
                    scrollInfo.yStart = (float)*(int *)(d + 0x10);
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

    switch (*(int *)(it + 0x270)) {
    case 6: /* ITEM_TYPE_LISTBOX */
        return Item_ListBox_HandleKey(dc, item, key, down, 0);

    case 8: /* ITEM_TYPE_OWNERDRAW */
        return UI_OwnerDrawHandleKey(*(int *)(it + 0xd8), *(int *)(it + 0xdc),
                                     (int *)(it + 0x2d8), key);

    case 0xa: /* ITEM_TYPE_SLIDER */
        return Item_Slider_HandleKey(dc, item, key, down);

    case 0xb: /* ITEM_TYPE_YESNO */
        return Item_YesNo_HandleKey(dc, item, key);

    case 0xc: { /* ITEM_TYPE_MULTI */
        byte *multiPtr = (byte *)Item_GetMultiDef(item);
        if (!multiPtr)
            return 0;
        if (!(*(byte *)(it + 0xe8) & 4))
            return 0;
        if (!(*(byte *)(it + 0xe8) & 2))
            return 0;

        /* Mouse click — check item rect bounds */
        if (key >= 0xc8 && key <= 0xca) {
            if (!Item_HandleKey_RectContainsPoint(it, (float)*(int *)(d + 0xc), (float)*(int *)(d + 0x10)))
                return 0;
        }

        /* Get multiDef and find current index */
        byte *mDef = (byte *)Item_GetMultiDef(item);
        int current = 0;
        if (mDef) {
            int strDef = *(int *)(mDef + 0x184);
            if (!strDef) {
                /* Float-based multi */
                const char *valStr = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
                float curVal = (float)atof(valStr);
                int count = *(int *)(mDef + 0x180);
                if (count > 0) {
                    /* Check if first value matches */
                    if (curVal != *(float *)(mDef + 0x100)) {
                        int i;
                        for (i = 1; i < count; i++) {
                            if (*(float *)(mDef + 0x100 + i * 4) == curVal) {
                                current = i;
                                break;
                            }
                        }
                        /* If no match, current stays 0 */
                    }
                }
            } else {
                /* String-based multi */
                const char *string = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
                int count = *(int *)(mDef + 0x180);
                if (count > 0) {
                    int i;
                    for (i = 0; i < count; i++) {
                        if (I_stricmp(string, *(const char **)(mDef + 0x80 + i * 4)) == 0) {
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
            totalCount = *(int *)(mDef2 + 0x180);

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
        if (*(int *)(multiPtr + 0x184)) {
            /* String-based */
            newVal = *(const char **)(multiPtr + 0x80 + newIndex * 4);
        } else {
            /* Float-based */
            newVal = va("%g", (double)*(float *)(multiPtr + 0x100 + newIndex * 4));
        }
        Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), newVal);
        return 1;
    }

    case 0xd: { /* ITEM_TYPE_ENUM_DVAR */
        if (!(*(byte *)(it + 0xe8) & 4))
            return 0;
        if (!(*(byte *)(it + 0xe8) & 2))
            return 0;

        /* Mouse click — check item rect bounds */
        if (key >= 0xc8 && key <= 0xca) {
            if (!Item_HandleKey_RectContainsPoint(it, (float)*(int *)(d + 0xc), (float)*(int *)(d + 0x10)))
                return 0;
        }

        /* Get current enum index */
        struct dvar_s *enumDvar = Dvar_FindVar(*(const char **)(it + 0x2ec));
        int current = 0;
        if (*(byte *)((byte *)enumDvar + 6) == 6) {
            /* Enum dvar type — resolve current index */
            const char *enumString = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
            current = atoi(enumString);
            if (current < 0 || current >= *(int *)((byte *)enumDvar + 0x14)) {
                /* Invalid numeric index — search by string */
                int numStrings = *(int *)((byte *)enumDvar + 0x14);
                current = 0;
                if (numStrings > 0) {
                    const char **strings = *(const char ***)((byte *)enumDvar + 0x18);
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
        struct dvar_s *dv = Dvar_FindVar(*(const char **)(it + 0x2ec));
        int totalCount;
        if (*(byte *)((byte *)dv + 6) == 6)
            totalCount = *(int *)((byte *)dv + 0x14);
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

        Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), va("%i", newIndex));
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
    byte *listPtr = (byte *)Item_GetListBoxDef(item);
    if (!listPtr) return;
    Window_RemoveDynamicFlags((void *)it, 0x1f00);
    int overLB = Item_ListBox_OverLB(item, x, y);
    Window_AddDynamicFlags((void *)it, overLB);
    int horzAlign = *(int *)(it + 0x10);
    int vertAlign = *(int *)(it + 0x14);
    if (*(byte *)(it + 0xe6) & 0x20) {
        if (*(int *)(it + 0xe8) & 0x1f00) return;
        if (*(int *)(listPtr + 0x3c) == 1) {
            float itemX = *(float *)it, itemY = *(float *)(it + 4);
            float rectW = *(float *)(it + 0xc) - 16.0f;
            int headerH = *(int *)(listPtr + 0x20);
            float rectH = *(float *)(it + 8) - (float)headerH;
            float cx = x, cy = y;
            float rx = itemX, ry = itemY, rw = rectH, rh = rectW;
            CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
            if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh) return;
            int cursorPos = (int)((x - itemX) / *(float *)(listPtr + 0x34)) + *(int *)listPtr;
            ListBox_SetCursorPos((itemDef_t *)listPtr, cursorPos);
            if (*(int *)(listPtr + 0x24) >= *(int *)(listPtr + 0x10))
                ListBox_SetCursorPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x10));
        }
    } else {
        if (*(int *)(it + 0xe8) & 0x1f00) return;
        float itemY = *(float *)(it + 4);
        float rectW = *(float *)(it + 8) - 16.0f;
        int headerH = *(int *)(listPtr + 0x20);
        float rectH = *(float *)(it + 0xc) - (float)headerH;
        float cx = x, cy = y;
        float rx = *(float *)it, ry = itemY, rw = rectW, rh = rectH;
        CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, horzAlign, vertAlign);
        if (cx < rx || cx > rx + rw || cy < ry || cy > ry + rh) return;
        int cursorPos = (int)((y - 2.0f - itemY) / *(float *)(listPtr + 0x38)) + *(int *)listPtr;
        ListBox_SetCursorPos((itemDef_t *)listPtr, cursorPos);
        if (*(int *)(listPtr + 0x24) > *(int *)(listPtr + 0x10))
            ListBox_SetCursorPos((itemDef_t *)listPtr, *(int *)(listPtr + 0x10));
    }
}

/* Item_MouseEnter — handle mouse enter/exit for an item with rect hit test */
void Item_MouseEnter(displayContextDef_t *dc, itemDef_t *item, float x, float y)
{
    byte *it = (byte *)item;
    if (!item) return;
    byte *parent = *(byte **)(it + 0x29c);
    if (!parent) return;
    int dvarFlags = *(int *)(it + 0x2d0);
    if (dvarFlags & 3) {
        if (!Item_EnableShowViaDvar((itemDef_t *)it, 1)) return;
        dvarFlags = *(int *)(it + 0x2d0);
    }
    if (dvarFlags & 0xc) {
        if (!Item_EnableShowViaDvar((itemDef_t *)it, 4)) return;
    }
    int flags = *(int *)(it + 0xe8);
    float rx = *(float *)it, ry = *(float *)(it + 4);
    float rw = *(float *)(it + 8), rh = *(float *)(it + 0xc);
    float cx = x, cy = y;
    CalcScreenX(&cx, 4); CalcScreenY(&cy, 4);
    CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(it + 0x10), *(int *)(it + 0x14));
    qboolean inside = (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh);
    if (inside) {
        if (!(flags & 0x40)) {
            Item_RunScript(dc, item, *(const char **)(it + 0x2a0));
            Window_AddDynamicFlags((void *)it, 0x40);
        }
        if (!(flags & 1)) {
            Item_RunScript(dc, item, *(const char **)(it + 0x2a8));
            Window_AddDynamicFlags((void *)it, 1);
        }
    } else {
        if (flags & 0x40) {
            Item_RunScript(dc, item, *(const char **)(it + 0x2a4));
            Window_RemoveDynamicFlags((void *)it, 0x40);
        }
        if (!(flags & 1)) {
            Item_RunScript(dc, item, *(const char **)(it + 0x2a8));
            Window_AddDynamicFlags((void *)it, 1);
        }
    }
    if (*(int *)(it + 0x270) == 6)
        Item_ListBox_MouseEnter(item, x, y);
}

/* Menu_HandleMouseMove — handle mouse movement over menu items: hit test, focus, enter/leave */
static qboolean Rect_ContainsPoint(byte *item, float x, float y)
{
    float rx = *(float *)item, ry = *(float *)(item + 4);
    float rw = *(float *)(item + 8), rh = *(float *)(item + 0xc);
    float cx = x, cy = y;
    CalcScreenX(&cx, 4);
    CalcScreenY(&cy, 4);
    CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(item + 0x10), *(int *)(item + 0x14));
    return (cx >= rx && cx <= rx + rw && cy >= ry && cy <= ry + rh);
}

qboolean Menu_HandleMouseMove(displayContextDef_t *dc, menuDef_t *menu, float x, float y)
{
    byte *m = (byte *)menu;
    int i, pass;
    qboolean focusSet = 0;
    void *focusItem = NULL;

    if (!menu) return 0;
    if ((*(int *)(m + 0xe8) & 0x4004) == 0) return 0;
    if (itemCapture) return 0;
    if (g_waitingForKey || g_editingField) return 0;

    /* Two-pass item scan: pass 0 = basic rect, pass 1 = text rect */
    for (pass = 0; pass < 2; pass++) {
        int itemCount = *(int *)(m + 0x218);
        for (i = itemCount - 1; i >= 0; i--) {
            byte *it = *(byte **)(*(byte **)(m + 0x27c) + i * 4);

            if ((*(int *)(it + 0xe8) & 0x4004) == 0) goto next_item;

            /* Dvar show checks */
            if (*(byte *)(it + 0x2d0) & 3) {
                if (!Item_EnableShowViaDvar((itemDef_t *)it, 1)) goto next_item;
                it = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
            }
            if (*(byte *)(it + 0x2d0) & 0xc) {
                if (!Item_EnableShowViaDvar((itemDef_t *)it, 4)) goto next_item;
                it = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
            }

            byte *overItem = it;
            int flags = *(int *)(overItem + 0xe8);
            if ((flags & 4) && (flags & 2) && !focusItem)
                focusItem = overItem;

            /* Hit test item rect */
            if (!Rect_ContainsPoint(overItem, x, y)) {
                byte *orig = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
                if (*(byte *)(orig + 0xe8) & 1) {
                    Item_MouseLeave(dc, (itemDef_t *)orig);
                    orig = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
                    if (orig) Window_RemoveDynamicFlags((void *)orig, 1);
                }
                goto next_item;
            }

            if (pass == 1) {
                overItem = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
                int itemType = *(int *)(overItem + 0x270);
                if (itemType == 0 && *(int *)(overItem + 0x294)) {
                    int textBuf[6];
                    memset(textBuf, 0, 24);
                    textBuf[0] = *(int *)(overItem + 0x210);
                    textBuf[1] = *(int *)(overItem + 0x214);
                    textBuf[2] = *(int *)(overItem + 0x218);
                    textBuf[3] = *(int *)(overItem + 0x21c);
                    textBuf[4] = *(int *)(overItem + 0x220);
                    textBuf[5] = *(int *)(overItem + 0x224);
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

                if (!(*(byte *)(overItem + 0xe8) & 4)) goto next_item;
                if (*(byte *)(overItem + 0xe8) & 0x10) goto next_item;

                Item_MouseEnter(dc, (itemDef_t *)overItem, x, y);
                if (!focusSet) {
                    if (Item_SetFocus(dc, (itemDef_t *)overItem, x, y)) {
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
        if (!Rect_ContainsPoint((byte *)focusItem, x, y)) {
            int itemCount = *(int *)(m + 0x218);
            for (i = 0; i < itemCount; i++) {
                byte *it = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
                Window_RemoveDynamicFlags((void *)it, 2);
                if (*(void **)(it + 0x2bc))
                    Item_RunScript(dc, (itemDef_t *)it, *(const char **)(it + 0x2bc));
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
    if (!*(void **)(it + 0x2c0)) return 0;

    /* Load current dvar value into buff */
    memset(buff, 0, 0x400);
    I_strncpyz(buff, Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0x400);

    /* Compute string length (repne scasb equivalent) */
    len = 0;
    while (buff[len]) len++;

    /* Truncate to maxChars if set */
    int maxChars = *(int *)((byte *)editPtr + 0x10);
    if (maxChars && len > maxChars) {
        buff[maxChars] = '\0';
        len = maxChars;
    }

    /* Check for ctrl+key (key & 0x400) */
    if (key & 0x400) {
        key &= ~0x400;

        /* Ctrl+Backspace (8) — delete char before cursor */
        if (key == 8) {
            int cursorPos = *(int *)(it + 0x2dc);
            if (cursorPos > 0) {
                memmove(buff + cursorPos - 1, buff + cursorPos, len - cursorPos + 1);
            }
            I_strncpyz(buff, buff, 0x400); /* normalize */
            Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), buff);
            I_strncpyz(buff, Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0x400);
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
            goto update_scroll;
        }

        /* Ctrl+key: check item type for filtering */
        if (*(int *)(it + 0x270) == 0x10) goto done; /* password field — block ctrl */

        if (key <= 0x1f) return 1;
        if (!*(void **)(it + 0x2c0)) return 1;

        /* Type-specific character filtering */
        int itemType = *(int *)(it + 0x270);
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

        if (*(int *)(it + 0x270) == 0x11) {
            /* Uppercase */
            key = ___toupper(key);
        }

        if (*(int *)(it + 0x270) == 0x12) {
            /* Numeric only */
            if (!I_isdigit(key)) return 1;
            goto insert_char;
        }

        /* Check valid filename char */
        if (*(int *)(it + 0x270) != 0x12) {
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
            int cursorPos = *(int *)(it + 0x2dc);
            memmove(buff + cursorPos + 1, buff + cursorPos, len - cursorPos + 1);
        }

        /* Write character */
        buff[*(int *)(it + 0x2dc)] = (char)key;
        Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), buff);

        /* Reload and reposition cursor */
        I_strncpyz(buff, Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0x400);
        Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, 1));

update_scroll:;
        /* Update scroll position */
        editPtr = Item_GetEditFieldDef(item);
        int curPos = *(int *)(it + 0x2dc);
        if (curPos < *(int *)((byte *)editPtr + 0x1c)) {
            *(int *)((byte *)editPtr + 0x1c) = curPos;
            return 1;
        }
        int maxPaint = *(int *)((byte *)editPtr + 0x18);
        if (!maxPaint) return 1;
        int offset = (int)Item_GetCursorPosOffset(item, buff, -maxPaint);
        if (offset > *(int *)((byte *)editPtr + 0x1c))
            *(int *)((byte *)editPtr + 0x1c) = offset;

        /* Check if cursor exceeds max and should advance to next item */
        if (maxChars && *(int *)(it + 0x2dc) >= maxChars) {
            int nextMaxPaint = *(int *)((byte *)editPtr + 0x14);
            if (!nextMaxPaint) return 1;
            itemDef_t *nextItem = Menu_SetNextCursorItem(dc, *(menuDef_t **)(it + 0x29c));
            Item_SetCursorPos(nextItem, 0);
            if (nextItem && *(int *)((byte *)nextItem + 0x270) <= 0x12 &&
                ((1 << *(int *)((byte *)nextItem + 0x270)) & 0x70210))
                g_editItem = nextItem;
        }
        return 1;
    }

    /* Non-ctrl key dispatch */
    /* Delete key (0xa2) */
    if (key == 0xa2) {
        int curPos = *(int *)(it + 0x2dc);
        if (curPos < len) {
            memmove(buff + curPos, buff + curPos + 1, len - curPos);
            Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), buff);
        }
        return 1;
    }

    /* Right arrow (0x9d) */
    if (key == 0x9d) {
        int curPos = *(int *)(it + 0x2dc);
        if (curPos < len) {
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, 1));
            editPtr = Item_GetEditFieldDef(item);
            int cp = *(int *)(it + 0x2dc);
            if (cp >= *(int *)((byte *)editPtr + 0x1c)) {
                int mp = *(int *)((byte *)editPtr + 0x18);
                if (mp) {
                    int off = (int)Item_GetCursorPosOffset(item, buff, -mp);
                    if (off > *(int *)((byte *)editPtr + 0x1c))
                        *(int *)((byte *)editPtr + 0x1c) = off;
                }
            } else {
                *(int *)((byte *)editPtr + 0x1c) = cp;
            }
        }
        return 1;
    }

    /* Left arrow (0x9c) */
    if (key == 0x9c) {
        if (*(int *)(it + 0x2dc) > 0) {
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
            editPtr = Item_GetEditFieldDef(item);
            int cp = *(int *)(it + 0x2dc);
            if (cp < *(int *)((byte *)editPtr + 0x1c))
                *(int *)((byte *)editPtr + 0x1c) = cp;
        }
        return 1;
    }

    /* Home (0xa5) */
    if (key == 0xa5) {
        Item_SetCursorPos(item, 0);
        editPtr = Item_GetEditFieldDef(item);
        *(int *)((byte *)editPtr + 0x1c) = 0;
        return 1;
    }

    /* End (0xa6) */
    if (key == 0xa6) {
        Item_SetCursorPos(item, len);
        editPtr = Item_GetEditFieldDef(item);
        int cp = *(int *)(it + 0x2dc);
        int mp = *(int *)((byte *)editPtr + 0x18);
        if (mp) {
            int off = (int)Item_GetCursorPosOffset(item, buff, -mp);
            if (off > *(int *)((byte *)editPtr + 0x1c))
                *(int *)((byte *)editPtr + 0x1c) = off;
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
        itemDef_t *newItem = Menu_SetPrevCursorItem(dc, *(menuDef_t **)(it + 0x29c));
        Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
        editPtr = Item_GetEditFieldDef(item);
        int cp = *(int *)(it + 0x2dc);
        if (cp < *(int *)((byte *)editPtr + 0x1c))
            *(int *)((byte *)editPtr + 0x1c) = cp;
        return 1;
    }

    /* Backspace (0x9a) — not ctrl+backspace */
    if (key == 0x9a) {
        int curPos = *(int *)(it + 0x2dc);
        if (curPos > 0) {
            memmove(buff + curPos - 1, buff + curPos, len - curPos + 1);
            Dvar_SetFromStringByName(*(const char **)(it + 0x2c0), buff);
            I_strncpyz(buff, Dvar_GetVariantString(*(const char **)(it + 0x2c0)), 0x400);
            Item_SetCursorPos(item, (int)Item_GetCursorPosOffset(item, buff, -1));
            editPtr = Item_GetEditFieldDef(item);
            int cp2 = *(int *)(it + 0x2dc);
            if (cp2 < *(int *)((byte *)editPtr + 0x1c))
                *(int *)((byte *)editPtr + 0x1c) = cp2;
        }
        return 1;
    }

    /* Enter (0xd) or numpad enter (0xbf) */
    if (key == 0xd || key == 0xbf) {
        /* Run onAccept script */
        if (*(void **)(it + 0x2b4)) {
            byte tempItem[0x2a0];
            *(void **)&tempItem[0x29c] = *(void **)(it + 0x29c);
            Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(it + 0x2b4));
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
                    Display_MouseMove(dc, NULL, *(int *)(d + 0xc), *(int *)(d + 0x10));
                }
            }
            goto done;
        }
    }

    /* No menu — nothing to handle */
    if (!menu) return;

    /* Down event + not sticky + not fullscreen: OOB check */
    if (down) {
        if (!(*(byte *)(m + 0xe7) & 1) && !*(int *)(m + 0x214)) {
            /* Hit test cursor against menu rect */
            float cx = (float)*(int *)(d + 0xc), cy = (float)*(int *)(d + 0x10);
            float rx = *(float *)m, ry = *(float *)(m + 4);
            float rw = *(float *)(m + 8), rh = *(float *)(m + 0xc);
            CalcScreenX(&cx, 4);
            CalcScreenY(&cy, 4);
            CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(m + 0x10), *(int *)(m + 0x14));
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
    int itemCount = *(int *)(m + 0x218);
    focusedItem = NULL;
    for (i = 0; i < itemCount; i++) {
        byte *it = *(byte **)(*(byte **)(m + 0x27c) + i * 4);
        int flags = *(int *)(it + 0xe8);
        if ((flags & 4) && (flags & 2))
            focusedItem = it;
    }

    /* Mouse wheel up/down (0xcd/0xce) — only for listbox items */
    if (key == 0xcd || key == 0xce) {
        if (focusedItem && *(int *)((byte *)focusedItem + 0x270) == 6) {
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
                if (*(void **)(fi + 0x2b0))
                    Item_RunScript(dc, (itemDef_t *)focusedItem, *(const char **)(fi + 0x2b0));
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
        if (!g_waitingForKey && *(void **)(m + 0x24c)) {
            byte tempItem[0x2a0];
            *(void **)&tempItem[0x29c] = menu;
            Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(m + 0x24c));
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
        int itemType = *(int *)((byte *)focusedItem + 0x270);
        if (itemType == 0) {
            /* Build text rect and hit test */
            byte *fi = (byte *)focusedItem;
            int textBuf[6];
            memset(textBuf, 0, 24);
            textBuf[0] = *(int *)(fi + 0x210);
            textBuf[1] = *(int *)(fi + 0x214);
            textBuf[2] = *(int *)(fi + 0x218);
            textBuf[3] = *(int *)(fi + 0x21c);
            textBuf[4] = *(int *)(fi + 0x220);
            textBuf[5] = *(int *)(fi + 0x224);
            float tw = *(float *)&textBuf[2];
            float ty = *(float *)&textBuf[1];
            if (tw != 0.0f)
                ty -= *(float *)&textBuf[3];
            float trx = *(float *)&textBuf[0], trw = *(float *)&textBuf[2];
            float try_ = ty, trh = *(float *)&textBuf[3];
            float tcx = (float)*(int *)(d + 0xc), tcy = (float)*(int *)(d + 0x10);
            CalcScreenX(&tcx, 4);
            CalcScreenY(&tcy, 4);
            CalcScreenPlacement(&trx, &trw, &try_, &trh, textBuf[4], textBuf[5]);
            if (tcx < trx || tcx > trx + trw || tcy < try_ || tcy > try_ + trh)
                return;
        } else {
            /* Non-type-0: hit test item rect */
            byte *fi = (byte *)focusedItem;
            float irx = *(float *)fi, iry = *(float *)(fi + 4);
            float irw = *(float *)(fi + 8), irh = *(float *)(fi + 0xc);
            float icx = (float)*(int *)(d + 0xc), icy = (float)*(int *)(d + 0x10);
            CalcScreenX(&icx, 4);
            CalcScreenY(&icy, 4);
            CalcScreenPlacement(&irx, &irw, &iry, &irh, *(int *)(fi + 0x10), *(int *)(fi + 0x14));
            if (icx < irx || icx > irx + irw || icy < iry || icy > iry + irh)
                return;

            /* Check if editable type */
            if (itemType <= 0x12 && ((1 << itemType) & 0x70210)) {
                editFieldDef_t *ep = Item_GetEditFieldDef((itemDef_t *)focusedItem);
                if (ep)
                    *(int *)((byte *)ep + 0x1c) = 0;
                Item_SetCursorPos((itemDef_t *)focusedItem, 0);
                g_editingField = 1;
                g_editItem = (itemDef_t *)focusedItem;
                Key_SetOverstrikeMode(1);
                return;
            }
        }

        /* Run action script on the focused item */
        if (*(void **)((byte *)focusedItem + 0x2b0))
            Item_RunScript(dc, (itemDef_t *)focusedItem, *(const char **)((byte *)focusedItem + 0x2b0));
        return;
    }

    /* Enter (0xd), numpad enter (0xbf), mouse3 (0xca) */
    if (key == 0xd || key == 0xbf || key == 0xca) {
        if (!focusedItem) return;
        /* Check for editable type */
        int ftype = *(int *)((byte *)focusedItem + 0x270);
        if (ftype <= 0x12 && ((1 << ftype) & 0x70210)) {
            Item_SetCursorPos((itemDef_t *)focusedItem, 0);
            g_editingField = 1;
            g_editItem = (itemDef_t *)focusedItem;
            Key_SetOverstrikeMode(1);
        } else if (focusedItem) {
            if (*(void **)((byte *)focusedItem + 0x2b0))
                Item_RunScript(dc, (itemDef_t *)focusedItem, *(const char **)((byte *)focusedItem + 0x2b0));
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
    byte *parent = *(byte **)(it + 0x29c);
    int flags;
    rectDef_t newRect;

    diag_item_paint_enter(item);

    flags = *(int *)(it + 0xe8);

    /* Orbit animation (flag 0x2000) */
    if (flags & 0x2000) {
        int dcTime = *(int *)((byte *)dc + 4);
        if (dcTime > *(int *)(it + 0x1c8)) {
            /* Update next trigger time */
            *(int *)(it + 0x1c8) = dcTime + *(int *)(it + 0x1b8);

            /* Compute half-width/half-height */
            float w = *(float *)(it + 0x68) * 0.5f;
            float h = *(float *)(it + 0x6c) * 0.5f;

            /* Relative position from rectClient center to rect center */
            float rx = *(float *)(it + 0x60) + w - *(float *)(it + 0xf8);
            float ry = *(float *)(it + 0x64) + h - *(float *)(it + 0xfc);

            /* 3-degree rotation */
            float angle;
            *(int *)&angle = 0x3d567750; /* ~3 degrees in radians */
            float sin_a = sinf(angle);
            float cos_a = cosf(angle);

            /* Copy w/h/align from rect */
            newRect.w = *(float *)(it + 0x68);
            newRect.h = *(float *)(it + 0x6c);
            newRect.horzAlign = *(int *)(it + 0x70);
            newRect.vertAlign = *(int *)(it + 0x74);

            /* Rotate and offset: newRect.x = rx*cos - ry*sin + rectClient.x - w */
            newRect.x = rx * cos_a - ry * sin_a + *(float *)(it + 0xf8) - w;
            /* newRect.y = rx*sin + ry*cos + rectClient.y - h */
            newRect.y = rx * sin_a + ry * cos_a + *(float *)(it + 0xfc) - h;

            /* Apply new client rect */
            ((void (*)(void *, void *))Window_SetRectClient)(item, &newRect);

            /* Update screen coords from parent */
            byte *p = *(byte **)(it + 0x29c);
            if (p) {
                float px = *(float *)p;
                float py = *(float *)(p + 4);
                if (*(int *)(p + 0xd4)) {
                    float borderSize = *(float *)(p + 0xe0);
                    px += borderSize;
                    py += borderSize;
                }
                ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                    item, px, py, *(int *)(p + 0x10), *(int *)(p + 0x14));
            }

            /* Re-read flags and re-check */
            flags = *(int *)(it + 0xe8);
        }
    }

    /* Slide animation (flag 0x80) */
    if (flags & 0x80) {
        int dcTime = *(int *)((byte *)dc + 4);
        if (dcTime > *(int *)(it + 0x1c8)) {
            /* Update next trigger time */
            *(int *)(it + 0x1c8) = dcTime + *(int *)(it + 0x1b8);

            /* Target = effects0 rect at 0xf8, step = effects1 rect at 0x158 */
            float *target = (float *)(it + 0xf8);
            float *step = (float *)(it + 0x158);
            int done = 0;

            /* Copy current rect to newRect */
            newRect = *(rectDef_t *)(it + 0x60);

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
            byte *p = *(byte **)(it + 0x29c);
            if (p) {
                float px = *(float *)p;
                float py = *(float *)(p + 4);
                if (*(int *)(p + 0xd4)) {
                    float borderSize = *(float *)(p + 0xe0);
                    px += borderSize;
                    py += borderSize;
                }
                ((void (*)(void *, float, float, int, int))Item_SetScreenCoords)(
                    item, px, py, *(int *)(p + 0x10), *(int *)(p + 0x14));
            }

            /* If all 4 coords reached target, remove slide flag */
            if (done == 4) {
                Window_RemoveDynamicFlags(item, 0x80);
            }
        }
    }

    /* Owner draw visibility check */
    {
        int ownerDraw = *(int *)(it + 0xdc);
        if (ownerDraw) {
            if (!UI_OwnerDrawVisible(ownerDraw)) {
                Window_RemoveDynamicFlags(item, 4);
            } else {
                Window_AddDynamicFlags(item, 4);
            }
        }
    }

    /* Dvar show/hide check */
    if (*(byte *)(it + 0x2d0) & 0xc) {
        if (!Item_EnableShowViaDvar(item, 4)) {
            /* Check for auto-action: visible + focused → simulate enter key */
            flags = *(int *)(it + 0xe8);
            if ((flags & 4) && (flags & 2)) {
                Menu_HandleKey(dc, (menuDef_t *)parent, 0x9b, 1);
                Menu_HandleKey(dc, (menuDef_t *)parent, 0x9b, 0);
            }
            diag_item_paint_skip(item, 0);
            return;
        }
    }

    /* Check visible flag */
    if (!(*(byte *)(it + 0xe8) & 4)) {
        diag_item_paint_skip(item, 0);
        return;
    }

    /* BorderStyle 6: update material from dvar */
    if (*(int *)(it + 0xd0) == 6) {
        const char *dvarStr = Dvar_GetString(*(const char **)(it + 0x2c0));
        *(int *)(it + 0x20c) = (int)CL_RegisterMaterialNoMip(dvarStr);
    }

    /* Main paint */
    diag_item_paint_draw(item);

    Window_Paint(dc, (void *)item,
        *(float *)(parent + 0x238), *(float *)(parent + 0x23c),
        *(float *)(parent + 0x234), (float)*(int *)(parent + 0x230));

    /* Debug mode: draw textRect outline */
    if (debugMode) {
        float adjusted_y;
        memset(&rect, 0, sizeof(rect));
        rect.x = *(float *)(it + 0x210);
        rect.y = *(float *)(it + 0x214);
        rect.w = *(float *)(it + 0x218);
        rect.h = *(float *)(it + 0x21c);
        rect.horzAlign = *(int *)(it + 0x220);
        rect.vertAlign = *(int *)(it + 0x224);

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
    if (*(int *)(it + 0xd0) == 6) {
        diag_item_paint_skip(item, 0);
        return;
    }

    /* Type dispatch */
    {
        int itemType = *(int *)(it + 0x270);
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
                const char *value = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
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
                const char *value = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
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
            const char *enumDvarName = *(const char **)(it + 0x2ec);
            if (!enumDvarName) {
                text = str_002ac3b0; /* "<dvarEnumList not set>" */
            } else {
                struct dvar_s *dvar = Dvar_FindVar(enumDvarName);
                if (*(byte *)((byte *)dvar + 6) != 6) {
                    /* Not an enum dvar */
                    text = str_002ac3c8; /* "<not an enum dvar>" */
                } else if (*(int *)((byte *)dvar + 0x14) == 0) {
                    /* No enum entries */
                    text = str_002157b8; /* empty string */
                } else {
                    /* Try to match by integer index first */
                    struct dvar_s *dvar2 = Dvar_FindVar(*(const char **)(it + 0x2ec));
                    if (*(byte *)((byte *)dvar2 + 6) != 6) {
                        goto enum_not_found;
                    }
                    {
                        const char *enumString = Dvar_GetVariantString(*(const char **)(it + 0x2c0));
                        int idx = atoi(enumString);
                        int enumCount = *(int *)((byte *)dvar2 + 0x14);
                        if (idx >= 0 && idx < enumCount) {
                            const char **strings = *(const char ***)((byte *)dvar + 0x18);
                            text = strings[idx];
                        } else {
                            /* Try string match */
                            int j;
                            text = str_002157b8;
                            for (j = 0; j < enumCount; j++) {
                                const char **strings = *(const char ***)((byte *)dvar + 0x18);
                                if (I_stricmp(enumString, strings[j]) == 0) {
                                    text = strings[j];
                                    goto enum_found;
                                }
                            }
                            enum_not_found:
                            idx = 0;
                            {
                                const char **strings = *(const char ***)((byte *)dvar + 0x18);
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
    if (!(*(byte *)(m + 0xe8) & 4)) {
        if (!forcePaint) return;
    }

    /* Owner draw visibility check */
    int ownerDrawFlags = *(int *)(m + 0xdc);
    if (ownerDrawFlags) {
        if (!UI_OwnerDrawVisible(ownerDrawFlags))
            return;
    }

    /* Play sound */
    if (*(void **)(m + 0x254))
        UI_PlayLocalSoundAliasByName(*(const char **)(m + 0x254));

    /* Handle fade amount / cursor distance */
    float fadeAmount = *(float *)(m + 0x240);
    if (fadeAmount != 0.0f) {
        float cursorDist = *(float *)((byte *)dc + 0x28);
        float dist = sqrtf(fadeAmount * fadeAmount + cursorDist * cursorDist);
        *(float *)((byte *)dc + 0x28) = dist;
        if (!forcePaint)
            goto paint_content;
    } else if (!forcePaint) {
        goto paint_content;
    }

    /* forcePaint path — remove from openMenus + re-add (bring to front) */
    Window_AddDynamicFlags((void *)m, 0x4000);

    /* Remove menu from openMenus */
    byte *d = (byte *)dc;
    int openCount = *(int *)(d + 0x270);
    int removeIdx = -1;
    for (i = openCount - 1; i >= 0; i--) {
        if (*(void **)(d + 0x230 + i * 4) == menu) {
            removeIdx = i;
            break;
        }
    }
    if (removeIdx >= 0) {
        *(int *)(d + 0x270) = openCount - 1;
        for (i = removeIdx; i < *(int *)(d + 0x270); i++)
            *(void **)(d + 0x230 + i * 4) = *(void **)(d + 0x230 + (i + 1) * 4);
    }

    /* Re-add to end */
    if (*(int *)(d + 0x270) == 0x10)
        Com_Error(1, "\x15Too many menus opened");
    int idx = *(int *)(d + 0x270);
    *(void **)(d + 0x230 + idx * 4) = menu;
    *(int *)(d + 0x270) = idx + 1;

paint_content:
    /* Draw fullscreen background if present */
    if (*(int *)(m + 0x214) && *(int *)(m + 0x20c)) {
        ((void (*)(float, float, float, float, int, int, float *, int))UI_DrawHandlePic)(
            0.0f, 0.0f, 640.0f, 480.0f,
            *(int *)(m + 0x10), *(int *)(m + 0x14), NULL,
            *(int *)(m + 0x20c));
    }

    /* Paint the window */
    Window_Paint(dc, (void *)m,
        *(float *)(m + 0x238), *(float *)(m + 0x23c),
        *(float *)(m + 0x234), (float)*(int *)(m + 0x230));

    /* Paint items */
    int itemCount = *(int *)(m + 0x218);
    if (itemCount > 0) {
        for (i = 0; i < itemCount; i++) {
            itemDef_t *item = *(itemDef_t **)(*(byte **)(m + 0x27c) + i * 4);
            Item_Paint(dc, item);
        }
    }

    /* Debug mode: draw rect outline */
    if (debugMode) {
        float color[4] = {1.0f, 1.0f, 0.0f, 1.0f};
        UI_DrawRect(*(float *)m, *(float *)(m + 4), *(float *)(m + 8), *(float *)(m + 0xc),
            *(int *)(m + 0x10), *(int *)(m + 0x14), 1.0f, color);
    }
}

/* Menu_PaintAll — paint all menus: non-open first, then open from fullscreen, debug FPS */
void Menu_PaintAll(displayContextDef_t *dc)
{
    byte *d = (byte *)dc;
    int i, j;

    /* Clear cursor distance */
    *(float *)(d + 0x28) = 0.0f;

    /* Call capture function if active */
    if (captureFunc)
        captureFunc(dc, captureData);

    int menuCount = *(int *)(d + 0x22c);
    int openCount = *(int *)(d + 0x270);

    /* Paint non-open menus */
    for (i = 0; i < menuCount; i++) {
        void *menu = *(void **)(d + 0x2c + i * 4);
        /* Check if this menu is in the openMenus list */
        int isOpen = 0;
        for (j = openCount - 1; j >= 0; j--) {
            if (*(void **)(d + 0x230 + j * 4) == menu) {
                isOpen = 1;
                break;
            }
        }
        if (!isOpen)
            Menu_Paint(dc, (menuDef_t *)menu, 0);
        openCount = *(int *)(d + 0x270);
    }

    /* Find first fullscreen menu in open stack (from end) */
    openCount = *(int *)(d + 0x270);
    int fullscreenStart = 0;
    for (i = openCount - 1; i >= 0; i--) {
        byte *menu = *(byte **)(d + 0x230 + i * 4);
        if (*(int *)(menu + 0x214)) {
            fullscreenStart = i;
            break;
        }
    }

    /* Paint open menus from fullscreen start to end */
    if (fullscreenStart < openCount) {
        for (i = fullscreenStart; i < *(int *)(d + 0x270); i++) {
            void *menu = *(void **)(d + 0x230 + i * 4);
            Menu_Paint(dc, (menuDef_t *)menu, 0);
        }
    }

    /* Debug mode: draw FPS */
    if (debugMode) {
        float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        float scale = 0.5f;
        FontHandle font = UI_GetFontHandle(0, scale);
        const char *fpsText = va("fps: %f", (double)*(float *)(d + 0x24));
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
        if (*(byte *)(m + 0xe7) & 2) {
            /* Run onClose script if visible */
            if ((*(byte *)(m + 0xe8) & 4) && *(void **)(m + 0x248)) {
                byte tempItem[0x2a0];
                *(void **)&tempItem[0x29c] = menu;
                Item_RunScript(dc, (itemDef_t *)tempItem, *(const char **)(m + 0x248));
            }
            Window_RemoveDynamicFlags((void *)menu, 6);
        }
        /* Fall through to check_open_menus */
    }

    /* Iterate open menus from end to find which one cursor is in */
    int openCount = *(int *)(d + 0x270);
    float cx = (float)*(int *)(d + 0xc);
    float cy = (float)*(int *)(d + 0x10);
    int targetIdx = -1;

    for (i = openCount - 1; i >= 0; i--) {
        byte *openMenu = *(byte **)(d + 0x230 + i * 4);
        if (!openMenu) continue;
        if ((*(int *)(openMenu + 0xe8) & 0x4004) == 0) continue;

        /* Hit-test menu rect */
        float rx = *(float *)openMenu, ry = *(float *)(openMenu + 4);
        float rw = *(float *)(openMenu + 8), rh = *(float *)(openMenu + 0xc);
        float testX = cx, testY = cy;
        CalcScreenX(&testX, 4);
        CalcScreenY(&testY, 4);
        CalcScreenPlacement(&rx, &rw, &ry, &rh, *(int *)(openMenu + 0x10), *(int *)(openMenu + 0x14));
        if (testX < rx || testX > rx + rw || testY < ry || testY > ry + rh)
            continue;

        /* Cursor is inside this menu — check items */
        int itemCount = *(int *)(openMenu + 0x218);
        if (itemCount <= 0) continue;

        for (j = 0; j < itemCount; j++) {
            byte *item = *(byte **)(*(byte **)(openMenu + 0x27c) + j * 4);
            if ((*(int *)(item + 0xe8) & 0x4004) == 0) continue;
            if (*(int *)(item + 0xe4) & 0x100000) continue;

            /* Hit-test item rect */
            float irx = *(float *)item, iry = *(float *)(item + 4);
            float irw = *(float *)(item + 8), irh = *(float *)(item + 0xc);
            float itx = cx, ity = cy;
            CalcScreenX(&itx, 4);
            CalcScreenY(&ity, 4);
            CalcScreenPlacement(&irx, &irw, &iry, &irh, *(int *)(item + 0x10), *(int *)(item + 0x14));
            if (itx < irx || itx > irx + irw || ity < iry || ity > iry + irh)
                continue;

            /* Check text rect if item has type and text */
            int itemType = *(int *)(item + 0x270);
            if (itemType != 0 && *(int *)(item + 0x294)) {
                /* Build text rect and hit-test */
                int textBuf[6];
                memset(textBuf, 0, 24);
                *(float *)&textBuf[0] = *(float *)(item + 0x210);
                *(float *)&textBuf[1] = *(float *)(item + 0x214);
                *(float *)&textBuf[2] = *(float *)(item + 0x218);
                *(float *)&textBuf[3] = *(float *)(item + 0x21c);
                textBuf[4] = *(int *)(item + 0x220);
                textBuf[5] = *(int *)(item + 0x224);
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
    openCount = *(int *)(d + 0x270);
    for (i = openCount - 1; i >= 0; i--)
        Window_RemoveDynamicFlags(*(void **)(d + 0x230 + i * 4), 2);

    Window_AddDynamicFlags(*(void **)(d + 0x230 + targetIdx * 4), 6);
    Display_MouseMove(dc, NULL, *(int *)(d + 0xc), *(int *)(d + 0x10));
    Menu_HandleMouseMove(dc, *(menuDef_t **)(d + 0x230 + targetIdx * 4), (float)*(int *)(d + 0xc), (float)*(int *)(d + 0x10));
    Menu_HandleKey(dc, *(menuDef_t **)(d + 0x230 + targetIdx * 4), key, down);

count_visible:;
    /* Count visible menus */
    int menuCount = *(int *)(d + 0x22c);
    int visCount = 0;
    for (i = 0; i < menuCount; i++) {
        byte *cm = *(byte **)(d + 0x2c + i * 4);
        if ((*(int *)(cm + 0xe8) & 0x4004) != 0)
            visCount++;
    }

    if (visCount > 0) {
        UI_Pause(0);
        /* Stop all cinematics in open menus */
        openCount = *(int *)(d + 0x270);
        for (i = openCount - 1; i >= 0; i--) {
            byte *openMenu = *(byte **)(d + 0x230 + i * 4);
            if (!openMenu) continue;
            /* Stop cinematic on menu if borderStyle == 5 */
            if (*(int *)(openMenu + 0xd0) == 5) {
                int cinHandle = *(int *)(openMenu + 0xcc);
                if (cinHandle >= 0) {
                    CIN_StopCinematic(cinHandle);
                    *(int *)(openMenu + 0xcc) = -1;
                }
            }
            /* Stop cinematics on items */
            int ic = *(int *)(openMenu + 0x218);
            for (j = 0; j < ic; j++) {
                byte *item = *(byte **)(*(byte **)(openMenu + 0x27c) + j * 4);
                if (*(int *)(item + 0xd0) == 5) {
                    int ch = *(int *)(item + 0xcc);
                    if (ch >= 0) {
                        CIN_StopCinematic(ch);
                        *(int *)(item + 0xcc) = -1;
                    }
                    item = *(byte **)(*(byte **)(openMenu + 0x27c) + j * 4);
                }
                if (*(int *)(item + 0x270) == 8)
                    CIN_StopCinematic(-*(int *)(item + 0xd8));
            }
        }
    } else {
        UI_Pause(0);
    }
}
