/* Converted to C from ASM: ui_utils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/ui/ui_utils.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>
#include <stdlib.h>

extern int ___tolower(int c);
extern const char * Dvar_GetVariantString(const char *dvarName);
extern void I_strncat(char *dest, int destSize, const char *src);
extern int I_stricmp(const char *s1, const char *s2);
extern qboolean String_Parse(const char **p, char *out, int outSize);
extern const char * Com_ParseOnLine(const char **p);
extern void * Hunk_AllocAlignInternal(int size, int alignment);
extern void Com_Printf(const char *fmt, ...);

static const char *staticNULL; /* staticNULL */
static stringDef_t * g_strHandle[2048]; /* g_strHandle */

void Window_SetStaticFlags(Window *w, const int flags);
qboolean Item_EnableShowViaDvar(const itemDef_t *item, int flag);
qboolean Item_IsEditFieldDef(itemDef_t *item);
listBoxDef_t * Item_GetListBoxDef(itemDef_t *item);
multiDef_t * Item_GetMultiDef(itemDef_t *item);
void * UI_Alloc(int size, int alignment);
void String_Init(void);
qboolean Int_Parse(const char * *p, int *i);
qboolean Float_Parse(const char * *p, float *f);
void Window_SetOffsetTime(Window *w, int offsetTime);
void Window_SetRect(Window *w, const UiRectangle *rect);
void Window_SetRectClient(Window *w, const UiRectangle *rectClient);
void Window_SetRectEffects0(Window *w, const UiRectangle *rectEffects0);
void Window_SetRectEffects1(Window *w, const UiRectangle *rectEffects1);
void Window_SetDynamicFlags(Window *w, const int flags);
void Menu_SetCursorItem(menuDef_t *menu, int cursorItem);
void Item_SetTextRect(itemDef_t *item, const rectDef_t *textRect);
void Item_SetCursorPos(itemDef_t *item, int cursorPos);
int Item_GetCursorPosOffset(const itemDef_t *item, const char *text, int delta);
void ListBox_SetCursorPos(listBoxDef_t *listBox, int cursorPos);
void ListBox_SetStartPos(listBoxDef_t *listBox, int startPos);
void ListBox_SetEndPos(listBoxDef_t *listBox, int endPos);
Bool ListBox_HasValidCursorPos(const listBoxDef_t *listBox);
void Window_AddDynamicFlags(Window *w, const int newFlags);
void Window_RemoveDynamicFlags(Window *w, const int newFlags);
editFieldDef_t * Item_GetEditFieldDef(itemDef_t *item);
const char * String_Alloc(const char *p);
void Item_SetScreenCoords(itemDef_t *item, float x, float y, int horzAlign, int vertAlign);
void Menu_UpdatePosition(menuDef_t *menu);
qboolean Rect_Parse(const char * *p, rectDef_t *r);

/* line 155 */
void Window_SetStaticFlags(Window *w, const int flags)
{
    byte *wb = (byte *)w;
    *(int *)(wb + 0xe4) = flags;
}

/* line 260 */
qboolean Item_EnableShowViaDvar(const itemDef_t *item, int flag)
{
    byte *ib = (byte *)item;
    char script[1024];
    char val[1024];
    const char *testValue;
    const char *p;

    memset(script, 0, 1024);

    if (!item)
        return 1;
    if (*(char **)(ib + 0x2cc) == NULL)
        return 1;
    if (**(char **)(ib + 0x2cc) == '\0')
        return 1;
    if (*(char **)(ib + 0x2c4) == NULL)
        return 1;
    if (**(char **)(ib + 0x2c4) == '\0')
        return 1;

    testValue = Dvar_GetVariantString(*(char **)(ib + 0x2c4));

    I_strncat(script, 1024, *(char **)(ib + 0x2cc));
    p = script;

    for (;;) {
        if (!String_Parse(&p, val, 1024)) {
            /* Ran out of values to parse */
            if (*(int *)(ib + 0x2d0) & flag)
                return 1;
            return 0;
        }

        /* Skip semicolons (single ';' char) */
        if (val[0] == ';' && val[1] == '\0') {
            if (!String_Parse(&p, val, 1024)) {
                if (*(int *)(ib + 0x2d0) & flag)
                    return 1;
                return 0;
            }
        }

        if (*(int *)(ib + 0x2d0) & flag) {
            /* Flag set: match means show (return 1) */
            if (I_stricmp(testValue, val) == 0)
                return 1;
        } else {
            /* Flag not set: match means hide (return 0) */
            if (I_stricmp(testValue, val) == 0)
                return 0;
        }
    }
}

/* line 515 */
qboolean Item_IsEditFieldDef(itemDef_t *item)
{
    byte *ib = (byte *)item;
    int type = *(int *)(ib + 0x274);

    if (type > 0x12)
        return 0;
    if ((1 << type) & 0x74e11)
        return 1;
    return 0;
}

/* line 536 */
listBoxDef_t * Item_GetListBoxDef(itemDef_t *item)
{
    byte *ib = (byte *)item;

    if (*(int *)(ib + 0x274) != 6) {
        Com_Printf("^1Menu Error: Expecting type: ITEM_TYPE_LISTBOX\n");
        return NULL;
    }
    return *(listBoxDef_t **)(ib + 0x2ec);
}

/* line 554 */
multiDef_t * Item_GetMultiDef(itemDef_t *item)
{
    byte *ib = (byte *)item;
    return *(multiDef_t **)(ib + 0x2ec);
}

/* line 591 */
void * UI_Alloc(int size, int alignment)
{
    return Hunk_AllocAlignInternal(size, alignment);
}

/* line 602 */
void String_Init(void)
{
    memset(g_strHandle, 0, 0x2000);
}

/* line 674 */
qboolean Int_Parse(const char * *p, int *i)
{
    const char *token;

    token = Com_ParseOnLine(p);
    if (!token || *token == '\0')
        return 0;

    *i = atoi(token);
    return 1;
}

/* line 695 */
qboolean Float_Parse(const char * *p, float *f)
{
    const char *token;

    token = Com_ParseOnLine(p);
    if (!token || *token == '\0')
        return 0;

    *f = (float)atof(token);
    return 1;
}

/* line 41 */
void Window_SetOffsetTime(Window *w, int offsetTime)
{
    byte *wb = (byte *)w;
    *(int *)(wb + 0x1b8) = offsetTime;
}

/* Helper: copy 6 ints (UiRectangle) from src to dst */
static void CopyRect(byte *dst, const byte *src)
{
    *(int *)(dst)      = *(int *)(src);
    *(int *)(dst + 4)  = *(int *)(src + 4);
    *(int *)(dst + 8)  = *(int *)(src + 8);
    *(int *)(dst + 12) = *(int *)(src + 12);
    *(int *)(dst + 16) = *(int *)(src + 16);
    *(int *)(dst + 20) = *(int *)(src + 20);
}

/* line 53 */
void Window_SetRect(Window *w, const UiRectangle *rect)
{
    CopyRect((byte *)w, (const byte *)rect);
}

/* line 69 */
void Window_SetRectClient(Window *w, const UiRectangle *rectClient)
{
    byte *wb = (byte *)w;
    CopyRect(wb + 0x60, (const byte *)rectClient);
}

/* line 85 */
void Window_SetRectEffects0(Window *w, const UiRectangle *rectEffects0)
{
    byte *wb = (byte *)w;
    CopyRect(wb + 0xf8, (const byte *)rectEffects0);
}

/* line 101 */
void Window_SetRectEffects1(Window *w, const UiRectangle *rectEffects1)
{
    byte *wb = (byte *)w;
    CopyRect(wb + 0x158, (const byte *)rectEffects1);
}

/* line 117 */
void Window_SetDynamicFlags(Window *w, const int flags)
{
    byte *wb = (byte *)w;
    *(int *)(wb + 0xe8) = flags;
}

/* line 163 */
void Menu_SetCursorItem(menuDef_t *menu, int cursorItem)
{
    byte *mb = (byte *)menu;
    *(int *)(mb + 0x220) = cursorItem;
}

/* line 312 */
void Item_SetTextRect(itemDef_t *item, const rectDef_t *textRect)
{
    byte *ib = (byte *)item;
    CopyRect(ib + 0x210, (const byte *)textRect);
}

/* line 328 */
void Item_SetCursorPos(itemDef_t *item, int cursorPos)
{
    byte *ib = (byte *)item;
    *(int *)(ib + 0x2dc) = cursorPos;
}

/* line 342 */
int Item_GetCursorPosOffset(const itemDef_t *item, const char *text, int delta)
{
    byte *ib = (byte *)item;
    int pos;
    unsigned char c;

    pos = *(int *)(ib + 0x2dc);

    if (delta > 0) {
        /* Moving forward */
        while (1) {
            const char *cp = text + pos;
            /* Skip color codes: ^[0-9] */
            if (cp != NULL && *cp == '^') {
                c = *(unsigned char *)(cp + 1);
                if (c != '\0' && c != '^' && c > '/' && c <= '9') {
                    pos += 2;
                    continue;
                }
            }
            if (*cp == '\0')
                break;
            if (delta == 0)
                break;
            pos += 1;
            delta -= 1;
        }
    } else {
        /* Moving backward */
        while (pos != 0) {
            if (delta == 0)
                break;
            /* Check if previous two chars are a color code */
            if (pos > 1) {
                const char *cp = text + pos;
                if (cp != (const char *)2 && *(cp - 2) == '^') {
                    c = *(unsigned char *)(cp - 1);
                    if (c != '\0' && c != '^' && c > '/' && c <= '9') {
                        pos -= 2;
                        continue;
                    }
                }
            }
            pos -= 1;
            delta += 1;
        }
    }

    return pos;
}

/* line 380 */
void ListBox_SetCursorPos(listBoxDef_t *listBox, int cursorPos)
{
    byte *lb = (byte *)listBox;
    *(int *)(lb + 0x24) = cursorPos;
}

/* line 393 */
void ListBox_SetStartPos(listBoxDef_t *listBox, int startPos)
{
    byte *lb = (byte *)listBox;
    *(int *)(lb) = startPos;
}

/* line 406 */
void ListBox_SetEndPos(listBoxDef_t *listBox, int endPos)
{
    byte *lb = (byte *)listBox;
    *(int *)(lb + 0x10) = endPos;
}

/* line 419 */
Bool ListBox_HasValidCursorPos(const listBoxDef_t *listBox)
{
    byte *lb = (byte *)listBox;
    int cursor = *(int *)(lb + 0x24);

    if (cursor >= *(int *)(lb + 0x10))
        return 0;
    if (cursor >= *(int *)(lb))
        return 1;
    return 0;
}

/* line 131 */
void Window_AddDynamicFlags(Window *w, const int newFlags)
{
    byte *wb = (byte *)w;
    *(int *)(wb + 0xe8) |= newFlags;
}

/* line 140 */
void Window_RemoveDynamicFlags(Window *w, const int newFlags)
{
    byte *wb = (byte *)w;
    int flags = *(int *)(wb + 0xe8);
    int mask = newFlags;

    if (mask & 4)
        mask |= 2;

    flags &= ~mask;
    *(int *)(wb + 0xe8) = flags;
}

/* line 545 */
editFieldDef_t * Item_GetEditFieldDef(itemDef_t *item)
{
    byte *ib = (byte *)item;

    if (Item_IsEditFieldDef(item)) {
        return *(editFieldDef_t **)(ib + 0x2ec);
    }

    Com_Printf("^1Menu Error: Expecting type: ITEM_TYPE_EDITFIELD, ITEM_TYPE_NUMERICFIELD, ITEM_TYPE_DECIMALFIELD, ITEM_TYPE_VALIDFILEFIELD, ITEM_TYPE_UPREDITFIELD, ITEM_TYPE_YESNO, ITEM_TYPE_BIND, ITEM_TYPE_SLIDER, or ITEM_TYPE_TEXT\n");
    return NULL;
}

/* line 608 */
const char * String_Alloc(const char *p)
{
    int hash;
    int i;
    char *str;
    stringDef_t *s;
    stringDef_t *last;
    stringDef_t *newDef;

    if (p == NULL)
        return NULL;

    if (*p == '\0')
        return staticNULL;

    /* Compute hash */
    hash = 0;
    i = 0x77;
    while (p[i - 0x77] != '\0') {
        hash += ___tolower((unsigned char)p[i - 0x77]) * i;
        i++;
    }
    hash &= 0x7ff;

    /* Search existing strings */
    s = g_strHandle[hash];
    while (s != NULL) {
        if (strcmp(p, *(char **)((byte *)s + 4)) == 0) {
            return *(char **)((byte *)s + 4);
        }
        s = *(stringDef_t **)s;
    }

    /* Allocate new string copy */
    str = (char *)Hunk_AllocAlignInternal(strlen(p) + 1, 1);
    strcpy(str, p);

    /* Find end of linked list */
    last = g_strHandle[hash];
    if (last != NULL) {
        stringDef_t *next = *(stringDef_t **)last;
        while (next != NULL) {
            last = next;
            next = *(stringDef_t **)next;
        }
    }

    /* Allocate new stringDef_t node */
    newDef = (stringDef_t *)Hunk_AllocAlignInternal(8, 4);
    *(int *)newDef = 0;                       /* next = NULL */
    *(char **)((byte *)newDef + 4) = str;     /* str pointer */

    if (last != NULL) {
        *(stringDef_t **)last = newDef;       /* append to list */
    } else {
        g_strHandle[hash] = newDef;           /* new head */
    }

    return str;
}

/* line 440 */
void Item_SetScreenCoords(itemDef_t *item, float x, float y, int horzAlign, int vertAlign)
{
    byte *ib = (byte *)item;
    int newRect[6];

    if (item == NULL)
        return;

    /* Check parent offset */
    if (*(int *)(ib + 0xd4) != 0) {
        float offset = *(float *)(ib + 0xe0);
        x += offset;
        y += offset;
    }

    /* Compute new rect from client rect */
    newRect[0] = *(int *)(ib + 0x60);  /* rectClient.x */
    newRect[1] = *(int *)(ib + 0x64);  /* rectClient.y */
    *(float *)&newRect[0] += x;
    *(float *)&newRect[1] += y;
    newRect[2] = *(int *)(ib + 0x68);  /* rectClient.w */
    newRect[3] = *(int *)(ib + 0x6c);  /* rectClient.h */

    /* horzAlign/vertAlign from rectClient or params */
    if (*(int *)(ib + 0x70) != 0 || *(int *)(ib + 0x74) != 0) {
        newRect[4] = *(int *)(ib + 0x70);
        newRect[5] = *(int *)(ib + 0x74);
    } else {
        newRect[4] = horzAlign;
        newRect[5] = vertAlign;
    }

    /* Window_SetRect inline: copy 6 ints to item base */
    *(int *)(ib)      = newRect[0];
    *(int *)(ib + 4)  = newRect[1];
    *(int *)(ib + 8)  = newRect[2];
    *(int *)(ib + 12) = newRect[3];
    *(int *)(ib + 16) = newRect[4];
    *(int *)(ib + 20) = newRect[5];

    /* Update textRect: keep x, y, horzAlign, vertAlign; zero w, h */
    newRect[0] = *(int *)(ib + 0x210);
    newRect[1] = *(int *)(ib + 0x214);
    newRect[4] = *(int *)(ib + 0x220);
    newRect[5] = *(int *)(ib + 0x224);
    newRect[2] = 0;
    newRect[3] = 0;

    /* Item_SetTextRect inline */
    *(int *)(ib + 0x210) = newRect[0];
    *(int *)(ib + 0x214) = newRect[1];
    *(int *)(ib + 0x218) = newRect[2];
    *(int *)(ib + 0x21c) = newRect[3];
    *(int *)(ib + 0x220) = newRect[4];
    *(int *)(ib + 0x224) = newRect[5];
}

/* line 488 */
void Menu_UpdatePosition(menuDef_t *menu)
{
    byte *mb = (byte *)menu;
    float x, y;
    int i;
    int itemCount;

    if (menu == NULL)
        return;

    x = *(float *)(mb);
    y = *(float *)(mb + 4);

    if (*(int *)(mb + 0xd4) != 0) {
        float offset = *(float *)(mb + 0xe0);
        x += offset;
        y += offset;
    }

    itemCount = *(int *)(mb + 0x218);
    if (itemCount <= 0)
        return;

    for (i = 0; i < itemCount; i++) {
        int **itemArray = *(int ***)(mb + 0x27c);
        Item_SetScreenCoords((itemDef_t *)itemArray[i], x, y,
                             *(int *)(mb + 0x10), *(int *)(mb + 0x14));
    }
}

/* line 715 */
qboolean Rect_Parse(const char * *p, rectDef_t *r)
{
    byte *rb = (byte *)r;
    const char *token;

    token = Com_ParseOnLine(p);
    if (!token || *token == '\0')
        return 0;
    *(float *)(rb) = (float)atof(token);

    token = Com_ParseOnLine(p);
    if (!token || *token == '\0')
        return 0;
    *(float *)(rb + 4) = (float)atof(token);

    token = Com_ParseOnLine(p);
    if (!token || *token == '\0')
        return 0;
    *(float *)(rb + 8) = (float)atof(token);

    token = Com_ParseOnLine(p);
    if (!token || *token == '\0')
        return 0;
    *(float *)(rb + 12) = (float)atof(token);

    return 1;
}
