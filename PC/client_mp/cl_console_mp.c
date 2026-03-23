/* ASM dump from: cl_console_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_console_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/q_shared.h"
 */

extern void Field_Clear(void *field);
extern Bool Dvar_GetBool(const char *dvarName);
extern int g_console_field_width; /* 0x0 */
extern float g_console_char_height; /* 0x0 */
extern const dvar_t *con_gamemessagetime; /* 0x0 */
extern const dvar_t *con_boldgamemessagetime; /* 0x0 */
extern const dvar_t *con_minicontime; /* 0x0 */
extern const dvar_t *con_miniconlines; /* 0x0 */
extern const dvar_t *con_restricted; /* 0x0 */

/* Forward declarations for C conversions */
extern char *CopyStringInternal(const char *in);
extern void Z_FreeInternal(void *ptr);
extern int ColorIndex(int c);
extern int Cmd_Argc(void);
extern const char *Cmd_Argv(int arg);
extern void Com_Printf(const char *fmt, ...);
extern int FS_FOpenFileWrite(const char *filename);
extern int FS_Write(const void *buffer, int len, int h);
extern void FS_FCloseFile(int h);
extern void I_strncat(char *dest, const char *src, int destsize);
extern int I_strnicmp(const char *s1, const char *s2, int n);
extern void I_strncpyz(char *dest, const char *src, int destsize);
extern void Cmd_TokenizeString(const char *text);
extern void Dvar_ForEach(void (*callback)(const char *));
extern void Cmd_ForEach(void (*callback)(const char *));
extern void Cmd_AddCommand(const char *name, void (*function)(void));
extern const dvar_t *Dvar_RegisterVec4(const char *name, float x, float y, float z, float w, float min, float max, unsigned int flags);
extern const dvar_t *Dvar_RegisterFloat(const char *name, float value, float min, float max, unsigned int flags);
extern const dvar_t *Dvar_RegisterInt(const char *name, int value, int min, int max, unsigned int flags);
extern const dvar_t *Dvar_RegisterBool_mac(const char *name, int value, unsigned int flags);
extern const dvar_t *Dvar_FindVar(const char *dvarName);
extern int Dvar_HasLatchedValue(const dvar_t *dvar);
extern const char *Dvar_DisplayableValue(const dvar_t *dvar);
extern const char *Dvar_DisplayableLatchedValue(const dvar_t *dvar);
extern const char *Dvar_DisplayableResetValue(const dvar_t *dvar);
extern const char *Dvar_GetVariantString(const char *dvarName);
extern void Dvar_DomainToString_GetLines(int type, int v0, int v1, char *outBuf, int outBufSize, int *outLineCount);
extern void CalcScreenPlacement(float *xAdj, float *yAdj, float *xScale, float *yScale, int horzAlign, int vertAlign);
extern void CalcScreenX(float *x, int align);
extern void CalcScreenY(float *y, int align);
extern void *UI_GetFontHandle(int fontType, float scale);
extern const char *SEH_SafeTranslateString(const char *str);
extern const char *va(const char *fmt, ...);
extern void CL_DrawText(const char *text, int maxChars, void *font, float x, float y, int horzAlign, int vertAlign, float xScale, float yScale, const float *color, int style);
extern void Field_Draw(void *field, int x, int y, int width, int horzAlign, int vertAlign);
extern void CL_LookupColor(int colorIndex, float *color);
extern void SCR_DrawSmallStringExt(int x, int y, const char *str, const float *color);
extern void SCR_DrawConsoleString(int x, int y, const short int *text, int len, const float *color);
extern int SEH_PrintStrlen(const char *str);
extern const char *getBuildNumber(void);
extern int Sys_IsMainThread(void);
extern int Sys_Milliseconds(void);
extern void Com_StripExtension(const char *in, char *out);
extern void qsort(void *base, int nmemb, int size, int (*compar)(const void *, const void *));
extern const char **Cmd_GetAutoCompleteFileList(const char *cmd, int *fileCount, int maxCount);
extern void FS_FreeFileList(const char **list, int count);
extern void LargeLocal_LargeLocal(void *ll, int size);
extern void *LargeLocal_GetBuf(void *ll);
extern void ZN10LargeLocalD1Ev(void *ll);
extern int ___maskrune(int c, unsigned long flags);
extern int strnicmp(const char *s1, const char *s2, int n);
extern void *__DefaultRuneLocale;

static struct ConDrawInputGlob conDrawInputGlob; /* conDrawInputGlob */
static struct Console con; /* con */
static const dvar_t *con_inputBoxColor; /* con_inputBoxColor */
static const dvar_t *con_inputHintBoxColor; /* con_inputHintBoxColor */
static const dvar_t *con_outputBarColor; /* con_outputBarColor */
static const dvar_t *con_outputSliderColor; /* con_outputSliderColor */
static const dvar_t *con_outputWindowColor; /* con_outputWindowColor */
extern int I_stricmp(const char *s1, const char *s2);

extern const vec4_t con_versionColor; /* con_versionColor - rodata.c */
extern const vec4_t con_inputCommandMatchColor; /* con_inputCommandMatchColor - rodata.c */
extern const vec4_t con_inputDvarMatchColor; /* con_inputDvarMatchColor - rodata.c */
extern const vec4_t con_inputDvarValueColor; /* con_inputDvarValueColor - rodata.c */
extern const vec4_t con_inputDvarInactiveValueColor; /* con_inputDvarInactiveValueColor - rodata.c */
extern const vec4_t con_inputDvarInfoColor; /* con_inputDvarInfoColor - rodata.c */
static int registeredIconMaterialCount; /* registeredIconMaterialCount */
static const char * hudMsgIconMaterials[256]; /* hudMsgIconMaterials */

/* Helper: inline MsgWnd_Clear */
static inline void MsgWnd_Clear(MessageWindow *wnd) {
    /* count * sizeof(MessageLine) = count * 164 */
    int byteSize = wnd->count * 164;
    memset(wnd->lines, 0, byteSize);
    wnd->current_line = 0;
}

/* Helper: write a character to the console text buffer */
static inline void Con_WriteChar(int colorIdx, int ch) {
    int row = con.currentLine % con.totallines;
    int offset = row * con.linewidth + con.lineOffset;
    con.textBuffer[offset] = (short)((colorIdx << 8) | ch);
    con.lineOffset++;
}

/* Helper: Clear all message windows */
static inline void Con_ClearAllMessageWindows(void) {
    MessageWindow *gamemsg = (MessageWindow *)con.messageBuffer;
    MsgWnd_Clear(gamemsg);
    MessageWindow *boldmsg = (MessageWindow *)((char *)con.messageBuffer + 0x53c);
    MsgWnd_Clear(boldmsg);
    MessageWindow *minicon = (MessageWindow *)((char *)con.messageBuffer + 0xfb4);
    MsgWnd_Clear(minicon);
    MessageWindow *subtitle = (MessageWindow *)((char *)con.messageBuffer + 0xa78);
    MsgWnd_Clear(subtitle);
}

void CL_RegisterHudMsgIconMaterial(const char *name);
const char * CL_GetHudMsgIconMaterialName(int index);
void Con_ToggleConsole_f(void);
static void Con_ChatModePublic_f(void);
static void Con_ChatModeTeam_f(void);
void Con_Bottom(void);
static void Con_Dump_f(void);
void Con_Shutdown(void);
static void Con_UpdateMessageWindowLine(qboolean linefeed);
static void Con_UpdateMessageWindowLine_impl(MessageWindow *msgwnd, qboolean linefeed, int duration);
static void Con_Linefeed(void);
void Con_AutoCompleteFromList(const char * *strings, int stringCount, const char *prefix, char *completed, int sizeofCompleted);
static void ConDraw_Box(float x, float y, float w, float h);
static int ConDrawInput_CompareStrings(const void *e0, const void *e1);
static void Con_DrawStringOnHUD(int y, int horzAlign, int vertAlign, const short int *string, int length, float msgwndScale, qboolean centerText);
void Con_DrawSay(int y);
void Con_ToggleConsoleOutput(void);
static void Con_DrawOuputWindow(void);
void Con_PageUp(void);
void Con_PageDown(void);
void Con_Top(void);
Bool Con_IsActive(void);
static void Con_Clear_f(void);
static void CL_AddConsoleInfoColor(void);
static void Con_DrawMessageWindow(int x, int y, int charHeight, int horzAlign, int vertAlign, float alpha, float msgwndScale, msgwnd_mode_t mode);
void Con_DrawSubtitles(int xPos, int yPos, int charHeight, float alpha, msgwnd_mode_t mode);
void Con_DrawMiniConsole(int xPos, int yPos, float alpha);
void Con_DrawBoldMessages(int xPos, int yPos, float alpha, msgwnd_mode_t mode);
void Con_DrawNotify(int xPos, int yPos, float alpha, msgwnd_mode_t mode);
static void ConDrawInput_IncrMatchCounter(const char *str);
void Con_ClearNotify(void);
void Con_ClearSubtitles(void);
static void ConDrawInput_DvarMatch(const char *str);
const char * Con_TokenizeInput(void);
Bool Con_AnySpaceAfterCommand(void);
static void Con_CheckResize(void);
static void Con_OneTimeInit(void);
void Con_Close(void);
static void ConDrawInput_AutoCompleteArg(int stringCount);
static void ConDrawInput_CmdMatch(const char *str);
static int CL_ConsolePrint_AddLine(print_msg_type_t type, int duration, int linewidth, int color);
void CL_ConsolePrint(print_msg_type_t type, const char *txt, int duration, int linewidth);
void CL_ConsoleFixPosition(void);
static void ConDrawInput_DetailedDvarMatch(const char *str);
static void ConDrawInput_DetailedCmdMatch(const char *str);
static void Con_DrawInput(void);
void Con_DrawConsole(void);
void Con_Init(void);
void CL_DeathMessagePrint(const char *attackerName, const vec_t *attackerColor, const char *victimName, const vec_t *victimColor, const char *iconShader, float iconWidth, float iconHeight, const vec_t *iconColor, int horzFlipIcon);

/* line 211 */
void CL_RegisterHudMsgIconMaterial(const char *name)
{
    int index;
    int count = registeredIconMaterialCount;

    for (index = 0; index < count; index++) {
        if (strcmp(hudMsgIconMaterials[index], name) == 0)
            return;
    }

    hudMsgIconMaterials[count] = CopyStringInternal(name);
    registeredIconMaterialCount++;
}

/* line 229 */
const char * CL_GetHudMsgIconMaterialName(int index)
{
    return hudMsgIconMaterials[(unsigned char)index];
}

/* line 265 */
void Con_ToggleConsole_f(void)
{
    char *field;
    /* Decompiler had inverted logic: `!con_restricted` blocked console when NOT restricted.
       Fixed: only restrict when con_restricted IS set. */
    if (Dvar_GetBool("con_restricted")) {
        if (((PlayerKeyState *)*(void **)imp_keys)->keys[135].binding) /* keys[135].binding - console key binding check */
            goto toggle;
        if (!((*(clientActive_t **)imp_cl)->keyCatchers & 1))
            return;
    }
toggle:
    field = (char *)imp_g_consoleField;
    Field_Clear(field);
    ((field_t *)field)->widthInPixels = g_console_field_width;
    ((field_t *)field)->charHeight = g_console_char_height;
    ((field_t *)field)->fixedSize = 1;
    con.outputVisible = 0;
    ((clientActive_t *)imp_clients)->keyCatchers ^= 1;
}

/* line 319 */
static void Con_ChatModePublic_f(void)
{
    char *field;
    **(int **)imp_chat_team = 0;
    field = *(char **)*(int **)imp_chatField;
    Field_Clear(field);
    ((field_t *)field)->widthInPixels = 0x24c;
    *(int *)&((field_t *)field)->charHeight = 0x41200000;
    ((field_t *)field)->fixedSize = 0;
    (*(clientActive_t **)imp_cl)->keyCatchers ^= 0x10;
}

/* line 331 */
static void Con_ChatModeTeam_f(void)
{
    char *field;
    **(int **)imp_chat_team = 1;
    field = *(char **)*(int **)imp_chatField;
    Field_Clear(field);
    ((field_t *)field)->widthInPixels = 0x21f;
    *(int *)&((field_t *)field)->charHeight = 0x41200000;
    ((field_t *)field)->fixedSize = 0;
    (*(clientActive_t **)imp_cl)->keyCatchers ^= 0x10;
}

/* line 2032 */
void Con_Bottom(void)
{
    con.display = con.currentLine;
}

/* line 354 */
static void Con_Dump_f(void)
{
    int f;
    char buffer[0x400];
    int lineIndex, linewidth, i, trimLen;
    short *linePtr;

    if (Cmd_Argc() != 2) {
        Com_Printf(str_002ab710); /* "usage: condump <filename>\n" */
        return;
    }

    Com_Printf(str_002ab72c, Cmd_Argv(1)); /* "Dumped console text to %s.\n" */

    f = FS_FOpenFileWrite(Cmd_Argv(1));
    if (!f) {
        Com_Printf(str_002a9268); /* "Couldn't open.\n" */
        return;
    }

    linewidth = con.linewidth;
    for (lineIndex = con.currentLine - con.totallines + 1; lineIndex <= con.currentLine; lineIndex++) {
        /* Get pointer to line's text in the circular buffer */
        linePtr = &con.textBuffer[(lineIndex % con.totallines) * linewidth];

        /* Check if line is all spaces */
        if (linewidth <= 0) {
            if (linewidth == 0)
                continue;
        } else {
            int allSpaces = 1;
            for (i = 0; i < linewidth; i++) {
                if ((linePtr[i] & 0xFF) != 0x20) {
                    allSpaces = 0;
                    break;
                }
            }
            if (allSpaces)
                continue;
        }

        /* Copy wide chars to narrow buffer (low byte only) */
        for (i = 0; i < linewidth; i++) {
            buffer[i] = (char)(linePtr[i] & 0xFF);
        }

        /* Trim trailing spaces */
        trimLen = linewidth - 1;
        while (trimLen >= 0 && buffer[trimLen] == ' ')
            trimLen--;
        buffer[trimLen + 1] = '\0';

        /* Append newline and write */
        I_strncat(buffer, str_002160e8, 0x400); /* "\n" */
        FS_Write(buffer, strlen(buffer), f);
    }

    FS_FCloseFile(f);
}

/* line 583 */
void Con_Shutdown(void)
{
    while (registeredIconMaterialCount > 0) {
        registeredIconMaterialCount--;
        Z_FreeInternal((void *)hudMsgIconMaterials[registeredIconMaterialCount]);
    }
}

/* line 620 */
/* _impl: register-convention args (eax=msgwnd, edx=linefeed, ecx=duration) → normal C */
static void Con_UpdateMessageWindowLine_impl(MessageWindow *msgwnd, qboolean linefeed, int duration)
{
    MessageLine *line;
    int serverTime;
    int origLinewidth;
    int copyCount;
    int textOffset;
    int charIndex;
    int i;

    /* line 630: get pointer to current message line */
    line = &msgwnd->lines[msgwnd->current_line];

    /* line 632: set start time to current server time */
    serverTime = (*(clientActive_t **)imp_cl)->serverTime;
    line->startTime = serverTime;

    /* line 633: set end time = start time + duration */
    line->endTime = duration + serverTime;

    /* { inlined scope ~line 600: copy console text buffer line into message line } */
    {
        origLinewidth = con.linewidth;
        copyCount = origLinewidth;

        /* clamp copy count to max 78 chars (textBuffer size) */
        if (origLinewidth >= 79)
            copyCount = 78;

        /* line 601: compute offset into console text buffer */
        textOffset = origLinewidth * (con.currentLine % con.totallines);

        /* line 603: copy characters from console text buffer to message line */
        if (copyCount > 0) {
            for (charIndex = 0; charIndex < copyCount; charIndex++) {
                line->textBuffer[charIndex] = con.textBuffer[textOffset + charIndex];
            }
        }

        /* line 610-615: pad remaining chars with colored spaces if needed */
        if (copyCount <= 77) {
            short fillChar = (short)((ColorIndex(0x37) << 8) | 0x20);
            while (copyCount < 78) {
                line->textBuffer[copyCount] = fillChar;
                copyCount++;
            }
        }
    }

    /* line 637: handle line feed */
    if (!linefeed)
        return;
    if (msgwnd->count <= 0)
        return;

    /* line 639: advance current line index with wrap-around */
    msgwnd->current_line = (msgwnd->current_line + 1) % msgwnd->count;

    /* line 642: adjust timing of padding lines so they start fading */
    if (msgwnd->padding <= 0)
        return;

    for (i = 0; i < msgwnd->padding; i++) {
        int lineIdx;
        MessageLine *otherLine;
        int endTime;
        int fadeout;
        char *cl_ptr;
        int curTime;

        lineIdx = (i + msgwnd->current_line) % msgwnd->count;
        otherLine = &msgwnd->lines[lineIdx];

        /* line 648: check if this line's fade period hasn't started yet */
        endTime = otherLine->endTime;
        fadeout = msgwnd->fadeout;
        cl_ptr = (char *)*(void **)imp_cl;
        curTime = ((clientActive_t *)cl_ptr)->serverTime;

        if (endTime - fadeout > curTime) {
            /* line 652: compress timing so fade starts now */
            int lineDuration = endTime - otherLine->startTime;
            otherLine->startTime = fadeout + (curTime - lineDuration);

            /* line 653: set end time to now + fadeout */
            otherLine->endTime = (*(clientActive_t **)imp_cl)->serverTime + msgwnd->fadeout;
        }
    }
}

/* Clean C version for WASM — callers should use Con_UpdateMessageWindowLine_impl directly.
 * This wrapper exists to satisfy the forward declaration; the naked callers
 * (Con_Linefeed, CL_ConsolePrint) pass (msgwnd, linefeed, duration) via registers. */
static void Con_UpdateMessageWindowLine(qboolean linefeed)
{
    (void)linefeed;
    /* No-op: register-convention callers should call Con_UpdateMessageWindowLine_impl() */
}
