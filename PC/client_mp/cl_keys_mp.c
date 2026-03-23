/* ASM dump from: cl_keys_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_keys_mp.cpp */

#include "common_types.h"
#include "imports.h"
#include <ctype.h>

extern void ReplaceStringInternal(char **dest, const char *src);
extern void Cmd_AddCommand(const char *name, void (*func)(void));
extern int Cmd_Argc(void);
extern char *Cmd_Argv(int arg);
extern void I_strncat(char *dest, int maxlen, const char *src);
extern int I_stricmp(const char *s0, const char *s1);
extern int I_strnicmp(const char *s0, const char *s1, int n);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void Com_Printf(const char *fmt, ...);
extern void FS_Printf(fileHandle_t f, const char *fmt, ...);
extern int SEH_GetCurrentLanguage(void);
extern void CL_SwitchToLocalClient(int localClientNum);
extern void Z_FreeInternal(void *ptr);
extern void UI_KeyEvent(int key, int down);

/* Externs for Field_Draw */
extern FontHandle UI_GetFontHandle(int fontEnum, float scale);
extern void CL_DrawTextWithCursor(const char *text, int maxChars, void *font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const vec_t *color, int style, int cursorPos, int cursor);
extern float GetRealWidthFromVirtualWidth(float w);
extern float GetRealHeightFromVirtualHeight(float h);
extern float GetVirtualWidthFromRealWidth(float w);
extern float GetVirtualHeightFromRealHeight(float h);
extern int SEH_PrintStrlen(const char *str);

extern PlayerKeyState playerKeys[1]; /* 0x0 */
extern field_t *chatField; /* 0x0 */
extern qboolean *chat_team; /* 0x0 */
extern qboolean *key_overstrikeMode; /* 0x0 */
extern qboolean *anykeydown; /* 0x0 */
extern qkey_t *keys; /* 0x0 */
extern field_t historyEditLines[32]; /* 0x0 */
extern field_t g_consoleField; /* 0x0 */
extern int nextHistoryLine; /* 0x0 */
extern int historyLine; /* 0x0 */
extern keyname_t keynames[99]; /* 0x0 */
extern keyname_t keynames_localized[99]; /* 0x0 */
extern char * frenchNumberKeysMap[10]; /* 0x0 */
static char tinystr[5]; /* tinystr */
static const char *completionString; /* completionString */
static Bool hasExactMatch; /* hasExactMatch */
static char shortestMatch[1024]; /* shortestMatch */
static int matchCount; /* matchCount */

qboolean Key_GetOverstrikeMode(void);
void Field_AdjustScroll(field_t *edit);
void Key_SetOverstrikeMode(qboolean state);
static void FindMatches(const char *s);
static void PrintMatches(const char *s);
static void keyConcatArgs(void);
static __attribute_regparm__(1) int Key_StringToKeynum(const char *str);
char * Key_KeynumToString(int keynum, qboolean translate);
void Key_SetBinding(int keynum, const char *binding);
char * Key_GetBinding(int keynum);
void CL_InitKeyCommands(void);
void Key_Shutdown(void);
void Field_Draw(field_t *edit, int x, int y, int horzAlign, int vertAlign, qboolean showCursor);
void Key_Unbind_f(void);
void Key_Unbindall_f(void);
void Key_Bind_f(void);
void Field_CharEvent(field_t *edit, int ch);
void CL_CharEvent(int key);
void Field_KeyDownEvent(field_t *edit, int key);
void Message_Key(int key);
void Console_Key(int key);
void Key_WriteBindings(fileHandle_t f);
void Key_Bindlist_f(void);
void CL_KeyEvent(int key, const qboolean down, const unsigned int time);
void Key_ClearStates(void);

/* line 1152 */
qboolean Key_GetOverstrikeMode(void)
{
    return *key_overstrikeMode;
}

/* line 451 */
void Field_AdjustScroll(field_t *edit) {
    typedef float (*GetFontHeightFn)(FontHandle font, float scale);
    typedef int (*TextWidthFn)(const char *text, int limit, FontHandle font);
    float fontScale, lineWidth, actualScale;
    FontHandle font;
    const char *bufStart;
    int scroll;

    fontScale = edit->charHeight / 48.0f;
    lineWidth = (float)edit->widthInPixels;

    if (edit->fixedSize) {
        fontScale = GetVirtualWidthFromRealWidth(fontScale);
        lineWidth = GetVirtualHeightFromRealHeight(lineWidth);
        font = ((clientStatic_t *)imp_cls)->consoleFont;
    } else {
        font = UI_GetFontHandle(0, fontScale);
    }

    actualScale = ((refexport_t *)imp_re)->NormalizedTextScale(font, fontScale);
    bufStart = edit->buffer;

    {
        int totalWidth = ((refexport_t *)imp_re)->TextWidth(bufStart, 0, font);
        float totalWidthScaled = (float)totalWidth * actualScale;
        if (totalWidthScaled < lineWidth) {
            edit->scroll = 0;
            edit->drawWidth = SEH_PrintStrlen(bufStart);
            return;
        }
    }

    if (lineWidth <= 0.0f) {
        scroll = edit->scroll;
        goto compute_visible;
    }

    scroll = edit->scroll;
    while (scroll > 0) {
        int endWidth = ((refexport_t *)imp_re)->TextWidth(bufStart + scroll - 1, 0, font);
        float endWidthScaled = (float)endWidth * actualScale;
        if (endWidthScaled >= lineWidth)
            break;
        scroll--;
        edit->scroll = scroll;
    }

compute_visible:
    {
        int textLen, textLenFromScroll;
        float scrolledWidth, cursorWidth, diff;

        textLen = ((refexport_t *)imp_re)->TextWidth(bufStart + scroll, 0, font);
        textLenFromScroll = ((refexport_t *)imp_re)->TextWidth(bufStart + edit->cursor, 0, font);

        scrolledWidth = (float)textLen * actualScale;
        cursorWidth = (float)textLenFromScroll * actualScale;
        diff = scrolledWidth - cursorWidth;

        if (diff < 0.0f) {
            if (edit->scroll > 0) {
                edit->scroll--;
                scroll = edit->scroll;
                goto compute_visible;
            }
            if (cursorWidth < lineWidth)
                goto compute_drawWidth;
        } else if (diff >= lineWidth) {
            edit->scroll++;
            scroll = edit->scroll;
            goto compute_visible;
        }

compute_drawWidth:
        {
            int len = (int)strlen(bufStart + scroll);
            int visChars = edit->cursor - scroll;
            edit->drawWidth = visChars;

            if (lineWidth > 0.0f && visChars < len) {
                while (visChars < len) {
                    int w = ((refexport_t *)imp_re)->TextWidth(bufStart + scroll, visChars + 1, font);
                    float wScaled = (float)w * actualScale;
                    if (wScaled >= lineWidth)
                        break;
                    visChars++;
                    edit->drawWidth = visChars;
                }
            }
        }
    }
}

/* line 1158 */
void Key_SetOverstrikeMode(qboolean state)
{
    *key_overstrikeMode = state;
}

/* line 711 */
void FindMatches(const char *s)
{
    int i;
    int completionLen;

    for (completionLen = 0; completionString[completionLen]; ++completionLen) {
    }

    if (I_strnicmp(s, completionString, completionLen) != 0) {
        return;
    }

    if (++matchCount == 1) {
        I_strncpyz(shortestMatch, s, sizeof(shortestMatch));
        hasExactMatch = 1;
        return;
    }

    if (!*s) {
        hasExactMatch = 1;
        shortestMatch[0] = '\0';
        return;
    }

    for (i = 0; ; ++i) {
        if (tolower((unsigned char)shortestMatch[i]) != tolower((unsigned char)s[i])) {
            break;
        }
        if (!s[i]) {
            hasExactMatch = 1;
            shortestMatch[i] = '\0';
            return;
        }
    }

    if (!s[i] || (hasExactMatch && !shortestMatch[i])) {
        hasExactMatch = 1;
    } else {
        hasExactMatch = 0;
    }
    shortestMatch[i] = '\0';
}

/* line 742 */
static
void PrintMatches(const char *s)
{
    int shortestLen;

    for (shortestLen = 0; shortestMatch[shortestLen]; ++shortestLen) {
    }

    if (I_strnicmp(s, shortestMatch, shortestLen) == 0) {
        Com_Printf("    %s\n", s);
    }
}

/* line 749 */
static
void keyConcatArgs(void)
{
    int i;

    for (i = 1; i < Cmd_Argc(); ++i) {
        const char *arg;
        const char *scan;

        I_strncat(g_consoleField.buffer, 0x100, " ");
        arg = Cmd_Argv(i);
        scan = arg;
        while (*scan && *scan != ' ') {
            ++scan;
        }

        if (*scan == ' ') {
            I_strncat(g_consoleField.buffer, 0x100, "\"");
        }

        I_strncat(g_consoleField.buffer, 0x100, arg);

        if (*scan == ' ') {
            I_strncat(g_consoleField.buffer, 0x100, "\"");
        }
    }
}

static int Key_HexCharValue(char ch)
{
    if (isdigit((unsigned char)ch)) {
        return ch - '0';
    }

    if (ch >= 'a' && ch <= 'f') {
        return ch - 'a' + 10;
    }

    return -1;
}

/* line 1193 */
static __attribute_regparm__(1)
int Key_StringToKeynum(const char *str)
{
    keyname_t *name;
    int highNibble;
    int lowNibble;

    if (str == NULL || *str == '\0') {
        return -1;
    }

    if (str[1] == '\0') {
        return (signed char)str[0];
    }

    if (str[0] == '0' && str[1] == 'x' && str[4] == '\0') {
        highNibble = Key_HexCharValue(str[2]);
        lowNibble = Key_HexCharValue(str[3]);
        if (highNibble >= 0 && lowNibble >= 0) {
            return (highNibble << 4) + lowNibble;
        }
    }

    for (name = keynames; name->name; ++name) {
        if (I_stricmp(str, name->name) == 0) {
            return name->keynum;
        }
    }

    return -1;
}

/* line 1268 */
char * Key_KeynumToString(int keynum, qboolean translate)
{
    keyname_t *name;
    int upperNibble;
    int lowerNibble;

    if (keynum == -1) {
        return "<KEY NOT FOUND>";
    }

    if ((unsigned int)keynum > 0xff) {
        return "<OUT OF RANGE>";
    }

    if (translate && SEH_GetCurrentLanguage() == 1 && keynum >= '0' && keynum <= '9') {
        return frenchNumberKeysMap[keynum - '0'];
    }

    if ((unsigned int)(keynum - 0x21) <= 0x5d && keynum != '"' && (translate || keynum != ';')) {
        tinystr[0] = toupper((unsigned char)keynum);
        tinystr[1] = '\0';
        return tinystr;
    }

    name = translate ? keynames_localized : keynames;
    while (name->name) {
        if (name->keynum == keynum) {
            return name->name;
        }
        ++name;
    }

    upperNibble = (keynum >> 4) & 0xf;
    lowerNibble = keynum & 0xf;
    tinystr[0] = '0';
    tinystr[1] = 'x';
    tinystr[2] = upperNibble > 9 ? (char)(upperNibble + 'a' - 10) : (char)(upperNibble + '0');
    tinystr[3] = lowerNibble > 9 ? (char)(lowerNibble + 'a' - 10) : (char)(lowerNibble + '0');
    tinystr[4] = '\0';
    return tinystr;
}

/* line 1345 */
void Key_SetBinding(int keynum, const char *binding)
{
    if (keynum == -1)
        return;
    ReplaceStringInternal((char **)((byte *)keys + keynum * 12 + 8), binding);
    *(int *)imp_dvar_modifiedFlags |= 1;
}

/* line 1366 */
char * Key_GetBinding(int keynum)
{
    if (keynum == -1)
        return "";
    return *(char **)((byte *)keys + keynum * 12 + 8);
}

/* line 1611 */
void CL_InitKeyCommands(void)
{
    Cmd_AddCommand("bind", Key_Bind_f);
    Cmd_AddCommand("unbind", Key_Unbind_f);
    Cmd_AddCommand("unbindall", Key_Unbindall_f);
    Cmd_AddCommand("bindlist", Key_Bindlist_f);
}

/* line 2046 */
void Key_Shutdown(void)
{
    int keyIndex;

    CL_SwitchToLocalClient(0);

    for (keyIndex = 0; keyIndex < 256; ++keyIndex) {
        if (keys[keyIndex].binding != NULL) {
            Z_FreeInternal(keys[keyIndex].binding);
            keys[keyIndex].binding = NULL;
        }
    }
}

/* line 384 */
void Field_Draw(field_t *edit, int x, int y, int horzAlign, int vertAlign, qboolean showCursor)
{
    vec4_t vColor;
    char str[0x400];
    int cursorPos;
    void *font;
    int fontStyle;
    float xScale;
    float yScale;
    float xAdj;
    float yAdj;
    int cursorChar;
    int drawWidth;
    float rawScale;

    /* line 396 */
    vColor[0] = 1.0f;
    vColor[1] = 1.0f;
    vColor[2] = 1.0f;
    vColor[3] = 1.0f;

    /* line 398: copy visible portion of edit buffer */
    I_strncpyz(str, edit->buffer + edit->scroll, 0x100 - edit->scroll);

    /* line 400 */
    cursorPos = edit->cursor - edit->scroll;

    /* line 402: check if the field has a font scale set */
    if (edit->fixedSize != 0) {
        /* line 404: use cls font */
        font = (void *)(*(clientStatic_t **)imp_cls)->consoleFont;

        /* line 409: overstrike mode */
        if (*(int *)*key_overstrikeMode) {
            fontStyle = 0;
            xScale = 1.0f;
            yScale = 1.0f;
            cursorChar = 0x5f; /* '_' */
        } else {
            fontStyle = 0;
            xScale = 1.0f;
            yScale = 1.0f;
            cursorChar = 0x7c; /* '|' */
        }
    } else {
        /* line 416: compute scale from edit->pixelWidth */
        rawScale = edit->charHeight / 48.0f;

        /* line 417 */
        font = (void *)UI_GetFontHandle(0, rawScale);

        /* line 418: re.GetFontYSize */
        {
            typedef float (*GetFontYSizeFn)(void *font, float scale);
            float fontYSize;
            GetFontYSizeFn fn = (GetFontYSizeFn)(*(refexport_t **)imp_re)->NormalizedTextScale;
            fontYSize = fn(font, rawScale);
            (void)fontYSize; /* used below */

            /* line 419: check if vertAlign == 5 */
            if (vertAlign == 5) {
                /* line 420: convert virtual to real width/height */
                typedef float (*ConvertFn)(float val);
                ConvertFn getRealW = (ConvertFn)GetRealWidthFromVirtualWidth;
                ConvertFn getRealH = (ConvertFn)GetRealHeightFromVirtualHeight;
                xScale = getRealW(fontYSize);
                yScale = getRealH(fontYSize);
            } else {
                xScale = fontYSize;
                yScale = fontYSize;
            }
        }

        /* line 429: overstrike mode for UI path */
        if (*(int *)*key_overstrikeMode) {
            fontStyle = 3;
            cursorChar = 0x5f; /* '_' */
        } else {
            fontStyle = 3;
            cursorChar = 0x7c; /* '|' */
        }
    }

    /* line 435 */
    xAdj = (float)x;

    /* line 436: re.R_GetFontHeight */
    {
        typedef int (*GetFontHeightFn)(void *font);
        GetFontHeightFn fn = (GetFontHeightFn)(*(refexport_t **)imp_re)->TextHeight;
        int fontHeight = fn(font);
        yAdj = (float)y + (float)fontHeight * yScale;
    }

    /* line 438 */
    drawWidth = edit->drawWidth;
    if (drawWidth == 0)
        edit->drawWidth = 0x100;

    /* line 442: draw text with cursor */
    CL_DrawTextWithCursor(str, edit->drawWidth, font,
                          xAdj, yAdj, horzAlign, vertAlign,
                          xScale, yScale,
                          vColor, fontStyle, cursorPos, cursorChar);
}
