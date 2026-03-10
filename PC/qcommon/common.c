/* ASM dump from: common.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/common.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdarg.h>
#include <ctype.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern void BG_ShutdownWeaponDefFiles(void);
extern void Com_ShutdownInternal(char *finalmsg);
extern void UI_SetMap(const char *a, const char *b);
extern void CL_StartHunkUsers(void);
extern void Com_ShutdownDObj(void);
extern void DObjShutdown(void);
extern void XAnimShutdown(void);
extern void CM_Shutdown(void);
extern void SND_ShutdownChannels(void);
extern void Hunk_Clear(void);
extern void Scr_Shutdown(void);
extern int Cmd_Argc(void);

extern const dvar_t *com_statmon; /* 0x0 */
extern const dvar_t *com_viewlog; /* 0x0 */
extern const dvar_t *com_developer; /* 0x0 */
extern const dvar_t *com_logfile; /* 0x0 */
extern const dvar_t *com_timescale; /* 0x0 */
extern float com_timescaleValue; /* 0x0 */
extern const dvar_t *com_sv_running; /* 0x0 */
extern const dvar_t *version; /* 0x0 */
extern const dvar_t *shortversion; /* 0x0 */
extern const dvar_t *nextmap; /* 0x0 */
extern const dvar_t *com_expectedHunkUsage; /* 0x0 */
extern const dvar_t *cl_paused; /* 0x0 */
extern const dvar_t *sv_paused; /* 0x0 */
extern int com_frameTime; /* 0x0 */
extern qboolean com_errorEntered; /* 0x0 */
extern qboolean com_fixedConsolePosition; /* 0x0 */
extern const dvar_t *com_developer_script; /* 0x0 */
extern const dvar_t *com_fixedtime; /* 0x0 */
extern const dvar_t *com_maxfps; /* 0x0 */
extern const dvar_t *com_introPlayed; /* 0x0 */
extern const dvar_t *com_recommendedSet; /* 0x0 */
extern const dvar_t *com_animCheck; /* 0x0 */
extern int com_frameNumber; /* 0x0 */
extern const dvar_t *ui_errorMessage; /* 0x0 */
extern const dvar_t *ui_errorTitle; /* 0x0 */
extern int com_numConsoleLines; /* 0x0 */
extern char * com_consoleLines[32]; /* 0x0 */
extern char cl_cdkey[34]; /* 0x0 */
extern char cl_cdkeychecksum[10]; /* 0x0 */
static qboolean opening_qconsole; /* opening_qconsole */
static int printedWarning; /* printedWarning */
static int timeClientFrame; /* timeClientFrame */
static int lastErrorTime; /* lastErrorTime */
static int errorCount; /* errorCount */
static errorParm_t errorcode; /* errorcode */
static fileHandle_t logfile; /* logfile */
static int com_lastFrameTime; /* com_lastFrameTime */
static float com_codeTimeScale; /* com_codeTimeScale */
static qboolean com_fullyInitialized; /* com_fullyInitialized */
static char com_errorMessage[4096]; /* com_errorMessage */
static int com_pushedEventsHead; /* com_pushedEventsHead */
static int com_pushedEventsTail; /* com_pushedEventsTail */
static sysEvent_t com_pushedEvents[256]; /* com_pushedEvents */
static qboolean com_safemode; /* com_safemode */
static int iWeaponInfoSource; /* iWeaponInfoSource */
static char *rd_buffer; /* rd_buffer */
static int rd_buffersize; /* rd_buffersize */
static void (*rd_flush)(); /* rd_flush */
extern char * noticeErrors[8]; /* noticeErrors */

extern char *va(const char *format, ...);
extern void *Sys_GetValue(int valueIndex);
extern void Sys_Error(const char *error, ...);
extern int setjmp(jmp_buf env);
extern void longjmp(jmp_buf env, int val);
extern dvar_t *com_dedicated;
extern int dvar_modifiedFlags;
extern int *com_fileAccessed; /* import pointer */
extern void Dvar_ClearModified(const dvar_t *dvar);
extern void SetAnimCheck(int enabled);
extern void NET_Sleep(int msec);
extern int Com_EventLoop(void);
extern void Cbuf_Execute(void);
extern void SV_Frame(int msec);
extern void CL_SwitchToLocalClient(int localClientNum);
extern void CL_RunOncePerClientFrame(int msec);
extern void CL_Shutdown(void);
extern void CL_Frame(int msec);
extern void SCR_UpdateScreenInternal(void);
extern void SCR_RunCinematic(void);
extern void SND_UpdateLoopingSounds(void);
extern void SND_Update(void);
extern void StatMon_Warning(int type, int timeout, const char *msg);
extern void Sys_ShowConsole(int visLevel, qboolean quitOnClose);
extern void Sys_NormalExit(void);
extern void SV_AddDedicatedCommands(void);
extern qboolean Com_HasPlayerProfile(void);
extern void Com_BuildPlayerProfilePath(char *buf, int bufsize, const char *suffix);

extern const dvar_t *Dvar_RegisterInt(const char *name, int value, int min, int max, int flags);
extern int Sys_Milliseconds(void);
extern float floorf(float x);
extern void UI_SetActiveMenu(int menu);
extern int stricmp(const char *s1, const char *s2);
extern void Z_FreeInternal(void *ptr);
extern void FS_FCloseFile(int f);
extern int FS_FOpenFileWrite(const char *filename);
extern void FS_Printf(int f, const char *fmt, ...);
extern void Key_WriteBindings(int f);
extern void Dvar_WriteVariables(int f);
extern int snprintf(char *str, unsigned int size, const char *format, ...);
void Com_BeginRedirect(char *buffer, int buffersize, void (*flush)());
void Com_EndRedirect(void);
void Com_Printf(const char *fmt, ...);
void Com_PrintMessage(print_msg_type_t type, const char *msg);
void Com_DPrintf(const char *fmt, ...);
static void Com_SetErrorMessage(const char *errorMessage);
void Com_Error(errorParm_t code, const char *fmt, ...);
qboolean Com_SafeMode(void);
void Com_StartupVariable(const char *match);
void Info_Print(const char *s);
void Com_ShutdownEvents(void);
static void Com_Error_f(void);
static void Com_Crash_f(void);
void Com_WriteCDKey(void);
static int Com_GpuStringCompare(const char *wild, const char *s);
static int Com_GetConfigureDvarNames(const char **text, char *dvarNames);
static void Com_GetConfigureDvarValues(int dvarCount, const char **text, char *dvarValues);
static void Com_SetConfigureDvars(int dvarCount, const char *dvarNames, const char *dvarValues);
static void Com_WriteConfigToFile(const char *filename);
void Com_WriteConfig_f(void);
float Com_GetTimescaleForSnd(void);
void Com_Close(void);
void Field_Clear(field_t *edit);
void Com_SetWeaponInfoMemory(int iSource);
void Com_FreeWeaponInfoMemory(int iSource);
int Com_AddToString(const char *add, char *msg, int len, int maxlen, qboolean mayAddQuotes);
char Com_GetDecimalDelimiter(void);
void Com_SetRecommended(qboolean restart);
void Com_CheckSetRecommended(void);
void Com_ReadCDKey(void);
void Com_LocalizedFloatToString(float f, char *buffer, unsigned int maxlen, unsigned int numDecimalPlaces);
void Com_Quit_f(void);
void Com_Restart(void);
void Com_ShutdownInternal(char *finalmsg);
static void Com_ErrorCleanup(void);
void Com_ExecStartupConfigs(const char *configFile);
int Com_EventLoop(void);
qboolean Debug_EventLoop(void);
void Com_Frame_Try_Block_Function(void);
void Com_Shutdown(char *finalmsg);
static void Com_StartHunkUsers(void);
void Com_Frame(void);
void Com_WriteDefaults_f(void);
int Com_Milliseconds(void);
void Com_PumpMessageLoop(void);
static void Com_Freeze_f(void);
void Com_Init_Try_Block_Function(char *commandLine);
void Com_Init(char *commandLine);

/* line 302 */
void Com_BeginRedirect(char *buffer, int buffersize, void (*flush)())
{
    if (!buffer || !buffersize || !flush)
        return;
    rd_buffer = buffer;
    rd_buffersize = buffersize;
    rd_flush = flush;
    *buffer = 0;
}

/* line 314 */
void Com_EndRedirect(void)
{
    if (rd_flush)
        rd_flush(rd_buffer);
    rd_buffer = 0;
    rd_buffersize = 0;
    rd_flush = 0;
}

/* line 481 */
void Com_Printf(const char *fmt, ...)
{
    char msg[4096];
    va_list argptr;

    va_start(argptr, fmt);
    vsnprintf(msg, sizeof(msg), fmt, argptr);
    va_end(argptr);

    Com_PrintMessage(0, msg);
}

/* line 335 */
void Com_PrintMessage(print_msg_type_t type, const char *msg)
{
    extern void I_strncat(char *dest, int destsize, const char *src);
    extern void Sys_Print(const char *msg);
    extern int FS_Initialized(void);
    extern void FS_Write(const void *buffer, int len, int h);
    extern void FS_Flush(int f);
    extern int FS_FOpenTextFileWrite(const char *filename);
    extern void CL_ConsolePrint(int type, const char *msg, int unknown1, int unknown2);

    if (rd_buffer) {
        if (type == 4)
            return;
        if (strlen(msg) + strlen(rd_buffer) - 1 > (unsigned)(rd_buffersize - 1)) {
            rd_flush(rd_buffer);
            *rd_buffer = '\0';
        }
        I_strncat(rd_buffer, rd_buffersize, msg);
        return;
    }

    if (type != 4 && (!com_dedicated || !com_dedicated->current.integer)) {
        CL_ConsolePrint(type, msg, 0, 0);
    }

    /* strip color codes */
    if (msg[0] == '^' && msg[1] != '\0')
        msg += 2;

    if (type != 4)
        Sys_Print(msg);

    if (!com_logfile || !com_logfile->current.integer)
        return;
    if (!FS_Initialized())
        return;

    if (!logfile) {
        if (opening_qconsole)
            return;
        opening_qconsole = 1;
        {
            long aclock;
            time(&aclock);
            logfile = FS_FOpenTextFileWrite("qconsole_mp.log");
            Com_Printf("logfile opened on %s\n", asctime(localtime(&aclock)));
        }
        opening_qconsole = 0;
        if (!logfile)
            return;
    }

    FS_Write(msg, strlen(msg), logfile);
    if (com_logfile->current.integer > 1) {
        FS_Flush(logfile);
    }
}

/* line 503 */
void Com_DPrintf(const char *fmt, ...)
{
    char msg[4096];
    va_list argptr;

    if (!com_developer || !com_developer->current.integer) {
        return;
    }

    va_start(argptr, fmt);
    vsnprintf(msg, sizeof(msg), fmt, argptr);
    va_end(argptr);

    Com_Printf("%s", msg);
}

/* line 634 */
static void Com_SetErrorMessage(const char *errMsg)
{
    extern const dvar_t *Dvar_RegisterString(const char *name, const char *value, int flags);
    extern void Dvar_SetString(const dvar_t *dvar, const char *value);
    extern const char *SEH_LocalizeTextMessage(const char *msg, const char *context, int flag);
    extern void I_strncpyz(char *dest, const char *src, int destsize);
    const char *title;
    const char *translation;
    int isNotice;
    int i;

    ui_errorMessage = Dvar_RegisterString("com_errorMessage", "", 0x1040);
    ui_errorTitle = Dvar_RegisterString("com_errorTitle", "", 0x1040);

    /* Check if this is a notice error (errorcode == 2) or matches noticeErrors list */
    isNotice = (errorcode == 2);
    if (!isNotice) {
        for (i = 0; noticeErrors[i] && noticeErrors[i][0]; i++) {
            if (stricmp(noticeErrors[i], errMsg) == 0) {
                isNotice = 1;
                break;
            }
        }
    }

    if (isNotice) {
        title = SEH_LocalizeTextMessage("MENU_NOTICE", "error message", 1);
        if (!title)
            title = "MENU_NOTICE";
    } else {
        title = SEH_LocalizeTextMessage("MENU_ERROR", "error message", 1);
        if (!title)
            title = "MENU_ERROR";
    }
    Dvar_SetString(ui_errorTitle, title);

    translation = SEH_LocalizeTextMessage(errMsg, "error message", 1);
    if (translation) {
        Dvar_SetString(ui_errorMessage, translation);
        I_strncpyz(com_errorMessage, translation, sizeof(com_errorMessage));
    } else {
        Dvar_SetString(ui_errorMessage, errMsg);
    }
}

/* line 906 */
void Com_Error(errorParm_t code, const char *fmt, ...)
{
    extern void CL_ConsoleFixPosition(void);
    extern qboolean UI_AnyFullScreenMenuVisible(void);
    extern char *cls; /* import pointer - struct, offset 0x110 has uiStarted */
    va_list argptr;

    if (com_errorEntered) {
        Sys_Error("recursive error after: %s", com_errorMessage);
    }

    com_errorEntered = 1;
    va_start(argptr, fmt);
    vsnprintf(com_errorMessage, sizeof(com_errorMessage), fmt, argptr);
    va_end(argptr);
    com_errorMessage[4095] = '\0';

    if (code == 4 || code == 6) {
        /* ERR_LOCALIZED / ERR_MAPLOADEDBEFORE */
        if (!com_fixedConsolePosition) {
            com_fixedConsolePosition = 1;
            CL_ConsoleFixPosition();
        }
        {
            int uiStarted;
            __asm__ __volatile__ (
                "movl imp_cls, %%eax\n"
                "movl 0x110(%%eax), %%eax\n"
                : "=a"(uiStarted) :: "memory"
            );
            if (uiStarted) {
                if (!UI_AnyFullScreenMenuVisible()) {
                    Com_SetErrorMessage(com_errorMessage);
                    UI_SetActiveMenu(1);
                }
                __asm__ __volatile__ (
                    "movl imp_cls, %%eax\n"
                    "movl 0x110(%%eax), %%eax\n"
                    : "=a"(uiStarted) :: "memory"
                );
                if (uiStarted) {
                    com_errorEntered = 0;
                    return;
                }
            }
        }
        code = 1;
    } else if (code == 5) {
        /* ERR_SCRIPT_DROP */
        com_fixedConsolePosition = 1;
        CL_ConsoleFixPosition();
        code = 1;
    } else {
        com_fixedConsolePosition = 0;
    }

    errorcode = code;
    longjmp(*(jmp_buf *)Sys_GetValue(2), -1);
}

/* line 1249 */
qboolean Com_SafeMode(void)
{
    extern void Cmd_TokenizeString(const char *text);
    extern const char *Cmd_Argv(int arg);
    extern int I_stricmp(const char *s1, const char *s2);
    int i;

    for (i = 0; i < com_numConsoleLines; i++) {
        Cmd_TokenizeString(com_consoleLines[i]);
        if (I_stricmp(Cmd_Argv(0), "safe") == 0 ||
            I_stricmp(Cmd_Argv(0), "dvar_restart") == 0) {
            com_consoleLines[i][0] = '\0';
            return 1;
        }
    }
    return com_safemode;
}

/* line 1288 */
void Com_StartupVariable(const char *match)
{
    extern void Cmd_TokenizeString(const char *text);
    extern const char *Cmd_Argv(int arg);
    extern void Dvar_Set_f(void);
    extern void Dvar_SetA_f(void);
    int lineIndex;

    for (lineIndex = 0; lineIndex < com_numConsoleLines; lineIndex++) {
        Cmd_TokenizeString(com_consoleLines[lineIndex]);
        if (match) {
            if (strcmp(Cmd_Argv(1), match) != 0)
                continue;
            if (stricmp(Cmd_Argv(0), "set") == 0) {
                Dvar_Set_f();
            } else if (stricmp(Cmd_Argv(0), "seta") == 0) {
                Dvar_SetA_f();
            }
        } else {
            if (stricmp(Cmd_Argv(0), "set") == 0) {
                Dvar_Set_f();
            } else if (stricmp(Cmd_Argv(0), "seta") == 0) {
                Dvar_SetA_f();
            }
        }
    }
}

/* line 1347 */
void Info_Print(const char *s)
{
    char key[0x208];
    char value[0x208];
    char *keyp;
    int keylen;

    if (*s == '\\')
        s++;

    while (*s) {
        /* Read key chars, stopping at '\\' or '\0' */
        keyp = key;
        while (*s && *s != '\\') {
            *keyp++ = *s++;
        }
        keylen = (int)(keyp - key);
        if (keylen > 0x13) {
            /* Key too long: print as-is without padding */
            *keyp = '\0';
            Com_Printf("%s", key);
        } else {
            /* Pad key with spaces to 20 chars */
            memset(keyp, ' ', 0x14 - keylen);
            key[0x14] = '\0';
            Com_Printf("%s", key);
        }
        if (*s == '\0') {
            Com_Printf("MISSING VALUE\n");
            return;
        }
        s++; /* skip '\\' */

        /* Read value chars, stopping at '\\' or '\0' */
        {
            char *vp = value;
            while (*s && *s != '\\') {
                *vp++ = *s++;
            }
            *vp = '\0';
            if (*s)
                s++; /* skip '\\' separator */
            Com_Printf("%s\n", value);
        }
    }
}

/* line 1460 */
void Com_ShutdownEvents(void)
{
    while (com_pushedEventsHead > com_pushedEventsTail) {
        int idx = (unsigned char)com_pushedEventsTail;
        sysEvent_t *ev = &com_pushedEvents[idx];
        com_pushedEventsTail++;
        if (ev->evPtr) {
            Z_FreeInternal(ev->evPtr);
        }
    }
}

/* line 1837 */
static void Com_Error_f(void)
{
    if (Cmd_Argc() - 1 > 0)
        Com_Error(1, "Testing drop error");
    else
        Com_Error(0, "Testing fatal error");
}

/* line 1891 */
static void Com_Crash_f(void)
{
    *(int *)0 = 0x12345678;
}

/* line 1985 */
void Com_WriteCDKey(void)
{
    extern qboolean CL_CDKeyValidate(const char *key, const char *checksum);
    extern void MacPreferences_PutString(const char *key, const char *value);
    char regkey[20];

    if (!CL_CDKeyValidate(cl_cdkey, cl_cdkeychecksum)) {
        memset(cl_cdkey, ' ', 16);
        cl_cdkey[16] = '\0';
        return;
    }
    memcpy(regkey, cl_cdkey, 16);
    memcpy(regkey + 16, cl_cdkeychecksum, 4);
    regkey[20 - 1] = '\0';
    MacPreferences_PutString("codkey", regkey);
}

/* line 2067 */
static int Com_GpuStringCompare(const char *wild, const char *s)
{
    for (;;) {
        char charWild = *wild;

        if (charWild == '\0')
            return *s == '\0' ? 0 : 1;

        if (charWild == '*') {
            wild++;
            if (*wild == '\0')
                return 0;
            do {
                if (Com_GpuStringCompare(wild, s) == 0)
                    return 0;
            } while (*s++ != '\0');
            return 1;
        }

        if (charWild == ' ') {
            wild++;
            if (Com_GpuStringCompare(wild, s) == 0)
                return 0;
            while (*s && !isdigit((unsigned char)*s)) {
                s++;
                if (Com_GpuStringCompare(wild, s) == 0)
                    return 0;
            }
            return 1;
        }

        if (*s == '\0')
            return 1;

        if (charWild != '?' && tolower((unsigned char)charWild) != tolower((unsigned char)*s))
            return 1;

        wild++;
        s++;
    }
}

/* line 2150 */
static int Com_GetConfigureDvarNames(const char **text, char *dvarNames)
{
    extern const char *Com_ParseOnLine(const char **text);
    extern void I_strncpyz(char *dest, const char *src, int destsize);
    int dvarCount = 0;

    for (;;) {
        const char *token = Com_ParseOnLine(text);
        if (!*text)
            Com_Error(0, "configure_mp.csv: unexpected EOF");
        if (!*token)
            return dvarCount;
        {
            int len = (int)strlen(token);
            if (len > 0x1f)
                Com_Error(0, "configure_mp.csv: dvar name \"%s\" longer than %i\n", token, 0x1f);
            if (dvarCount > 0x3f)
                Com_Error(0, "configure_mp.csv: more than %i dvars\n", 0x40);
            I_strncpyz(dvarNames + dvarCount * 0x20, token, 0x20);
            dvarCount++;
        }
    }
}

/* line 2179 */
static void Com_GetConfigureDvarValues(int dvarCount, const char **text, char *dvarValues)
{
    extern const char *Com_ParseOnLine(const char **text);
    extern void I_strncpyz(char *dest, const char *src, int destsize);
    int dvarIndex;
    char *curValues;

    if (dvarCount <= 0) {
        /* No dvar values to read - just drain remaining columns, error on extras */
        const char *token = Com_ParseOnLine(text);
        if (*token)
            Com_Error(0, "configure_mp.csv: extra dvar value column(s): value = %s\n", token);
        return;
    }

    /* dvarCount > 0 */
    if (!dvarValues) {
        /* dvarValues is NULL: drain all dvarCount columns (error on missing or extra) */
        for (dvarIndex = 0; dvarIndex < dvarCount; dvarIndex++) {
            const char *token = Com_ParseOnLine(text);
            if (!*text)
                Com_Error(0, "configure_mp.csv: unexpected EOF");
            if (!*token)
                Com_Error(0, "configure_mp.csv: missing entry in dvar value column %i\n", dvarIndex);
            {
                int len = (int)strlen(token);
                if (len > 0x1f)
                    Com_Error(0, "configure_mp.csv: entry '%s' in dvar value column %i is longer than %i\n", token, dvarIndex, 0x1f);
            }
        }
        /* drain extras */
        {
            const char *token = Com_ParseOnLine(text);
            if (*token)
                Com_Error(0, "configure_mp.csv: extra dvar value column(s): value = %s\n", token);
        }
        return;
    }

    /* dvarValues is non-NULL: read dvarCount values into 32-byte slots */
    curValues = dvarValues;
    for (dvarIndex = 0; dvarIndex < dvarCount; dvarIndex++) {
        const char *token = Com_ParseOnLine(text);
        if (!*text)
            Com_Error(0, "configure_mp.csv: unexpected EOF");
        if (!*token)
            Com_Error(0, "configure_mp.csv: missing entry in dvar value column %i\n", dvarIndex);
        {
            int len = (int)strlen(token);
            if (len > 0x1f)
                Com_Error(0, "configure_mp.csv: entry '%s' in dvar value column %i is longer than %i\n", token, dvarIndex, 0x1f);
            I_strncpyz(curValues, token, 0x20);
            curValues += 0x20;
        }
    }
    /* drain extras */
    {
        const char *token = Com_ParseOnLine(text);
        if (*token)
            Com_Error(0, "configure_mp.csv: extra dvar value column(s): value = %s\n", token);
    }
}

/* line 2206 */
/* line 2206 */
static void Com_SetConfigureDvars(int dvarCount, const char *dvarNames, const char *dvarValues)
{
    extern void Dvar_SetFromStringByNameFromSource(const char *name, const char *value, int source);
    extern const dvar_t *Dvar_FindVar(const char *name);
    extern void Dvar_AddFlags(const dvar_t *dvar, int flags);
    int dvarIndex;

    if (dvarCount <= 0)
        return;

    for (dvarIndex = 0; dvarIndex < dvarCount; dvarIndex++) {
        const char *name = dvarNames + dvarIndex * 0x20;
        const char *value = dvarValues + dvarIndex * 0x20;
        if (strncmp(name, "r_aaSamples", 12) == 0)
            Dvar_SetFromStringByNameFromSource(name, "1", 1);
        else
            Dvar_SetFromStringByNameFromSource(name, value, 1);
        {
            const dvar_t *dvar = Dvar_FindVar(name);
            Dvar_AddFlags(dvar, 1);
        }
    }
}

static void Com_SkipConfigureBlankLines(const char **text)
{
    extern void Com_SkipRestOfLine(const char **text);

    while (*text && **text && (**text == '\r' || **text == '\n'))
        Com_SkipRestOfLine(text);
}

/* line 2931 */
static void Com_WriteConfigToFile(const char *filename)
{
    int f;

    f = FS_FOpenFileWrite(filename);
    if (!f) {
        Com_Printf("Couldn't write %s.\n", filename);
        return;
    }
    FS_Printf(f, "// generated by Call of Duty, do not modify\n");
    FS_Printf(f, "unbindall\n");
    Key_WriteBindings(f);
    Dvar_WriteVariables(f);
    FS_FCloseFile(f);
}

/* line 3036 */
void Com_WriteConfig_f(void)
{
    extern void I_strncpyz(char *dest, const char *src, int destsize);
    extern void Com_DefaultExtension(char *path, int maxSize, const char *extension);
    extern const char *Cmd_Argv(int arg);
    char filename[64];

    if (Cmd_Argc() != 2) {
        Com_Printf("Usage: writeconfig <filename>\n");
        return;
    }
    I_strncpyz(filename, Cmd_Argv(1), 0x40);
    Com_DefaultExtension(filename, 0x40, ".cfg");
    Com_Printf("Writing %s.\n", filename);
    Com_WriteConfigToFile(filename);
}

/* line 3082 */
float Com_GetTimescaleForSnd(void)
{
    int fixedtime = *(int *)((byte *)com_fixedtime + 8);
    if (fixedtime)
        return (float)fixedtime;
    return *(float *)((byte *)com_timescale + 8);
}

/* line 3779 */
void Com_Close(void)
{
    Com_ShutdownDObj();
    DObjShutdown();
    XAnimShutdown();
    CM_Shutdown();
    SND_ShutdownChannels();
    Hunk_Clear();
    Scr_Shutdown();
}

/* line 3821 */
void Field_Clear(field_t *edit)
{
    memset((byte *)edit + 0x18, 0, 0x100);
    *(int *)edit = 0;
    *(int *)((byte *)edit + 4) = 0;
    *(int *)((byte *)edit + 8) = 0x100;
}

/* line 3953 */
void Com_SetWeaponInfoMemory(int iSource)
{
    iWeaponInfoSource = iSource;
}

/* line 3967 */
void Com_FreeWeaponInfoMemory(int iSource)
{
    if (iWeaponInfoSource != iSource)
        return;
    iWeaponInfoSource = 0;
    BG_ShutdownWeaponDefFiles();
}

/* line 3985 */
/* line 3985 */
int Com_AddToString(const char *add, char *msg, int len, int maxlen, qboolean mayAddQuotes)
{
    int addQuotes = 0;

    if (mayAddQuotes) {
        if (*add) {
            if ((unsigned char)*add > ' ') {
                /* Scan to see if string needs quoting (has spaces/controls or nothing after) */
                int remaining = maxlen - len;
                if (remaining > 0) {
                    const char *p;
                    int needsQuote = 0;
                    for (p = add + 1; (int)(p - add) < remaining; p++) {
                        if (!*p) { break; }
                        if ((unsigned char)*p <= ' ') { needsQuote = 1; break; }
                    }
                    if (needsQuote) {
                        /* Add opening quote */
                        if (len < maxlen) {
                            msg[len] = '"';
                            len++;
                            addQuotes = 1;
                        }
                    }
                } else {
                    /* no room */
                    addQuotes = 0;
                }
            } else {
                /* first char <= space: add quotes */
                if (len < maxlen) {
                    msg[len] = '"';
                    len++;
                    addQuotes = 1;
                }
            }
        } else {
            /* empty string: add quotes */
            if (len < maxlen) {
                msg[len] = '"';
                len++;
                addQuotes = 1;
            }
        }
    }

    /* Copy chars from add until maxlen */
    if (len < maxlen) {
        int i;
        int room = maxlen - len;
        for (i = 0; add[i] && i < room; i++) {
            msg[len + i] = add[i];
        }
        len += i;
    }

    /* Add closing quote if needed */
    if (addQuotes) {
        if (len < maxlen) {
            msg[len] = '"';
            len++;
        }
    }

    return len;
}

/* line 4023 */
char Com_GetDecimalDelimiter(void)
{
    extern const dvar_t **loc_language;
    int lang = (*loc_language)->current.integer;
    switch (lang) {
        case 1: case 2: case 3: case 4: case 6: case 7:
            return ',';
        default:
            return '.';
    }
}

/* line 2365 */
void Com_SetRecommended(qboolean restart)
{
    extern void Com_Printf(const char *fmt, ...);
    extern void Sys_GetInfo(void *info);
    extern int FS_ReadFile(const char *path, void **buffer);
    extern void FS_FreeFile(void *buffer);
    extern void Com_BeginParseSession(const char *name);
    extern void Com_SetCSV(int csv);
    extern const char *Com_ParseOnLine(const char **text);
    extern void Com_SkipRestOfLine(const char **text);
    extern void Com_EndParseSession(void);
    extern void Sys_ArchiveInfo(int checksum);
    extern int stricmp(const char *s1, const char *s2);
    extern double atof(const char *s);
    extern int atoi(const char *s);
    extern void Cbuf_AddText(const char *text);
    extern void Cbuf_Execute(void);
    extern qboolean Dvar_AnyLatchedValues(void);

    SysInfo info;
    void *csv = 0;
    int filesize;
    const char *text;

    /* char dvarNames[0x40][0x20] */
    char dvarNames[0x40 * 0x20];
    int dvarCount;

    /* best CPU match */
    struct {
        double MHz;
        int MB;
        char dvarValues[0x40 * 0x20];
    } best;
    double bestMHz;
    int bestMB;
    qboolean foundCpuMatch;

    /* GPU match */
    int gpuDvarCount;
    char gpuDvarNames[0x40 * 0x20];
    qboolean foundGpuSection;
    qboolean foundGpuMatch;

    Com_Printf("========= autoconfigure\n");
    Sys_GetInfo(&info);
    /* Startup code can leave MMX state live, which breaks the first x87 double op. */
    __builtin_ia32_emms();
    info.cpuGHz *= 1.02;
    if (info.sysMB <= 0x7f)
        info.sysMB = 0x80;

    filesize = FS_ReadFile("configure_mp.csv", &csv);
    if (filesize < 0)
        Com_Error(0, "EXE_ERR_NOT_FOUND\x15configure_mp.csv");

    text = (const char *)csv;
    Com_BeginParseSession("configure_mp.csv");
    Com_SetCSV(1);

    dvarCount = 0;
    foundCpuMatch = 0;
    bestMHz = -1.0;
    bestMB = 0;
    memset(&best, 0, sizeof(best));
    gpuDvarCount = 0;
    foundGpuSection = 0;
    foundGpuMatch = 0;

    for (;;) {
        const char *token;
        double rowGHz;
        int rowMB;

        Com_SkipConfigureBlankLines(&text);
        if (!text || !*text)
            break;

        token = Com_ParseOnLine(&text);
        if (!*token || *token == '#') {
            Com_SkipRestOfLine(&text);
            continue;
        }

        if (!dvarCount) {
            const char *col2;

            if (stricmp(token, "cpu ghz") != 0)
                Com_Error(0, "\x15configure_mp.csv: \"cpu ghz\" should be the first column\n");

            col2 = Com_ParseOnLine(&text);
            if (stricmp(col2, "sys mb") != 0)
                Com_Error(0, "\x15configure_mp.csv: \"sys mb\" should be the second column\n");

            dvarCount = Com_GetConfigureDvarNames(&text, dvarNames);
            Com_SkipRestOfLine(&text);
            continue;
        }

        if (stricmp(token, "gpu") == 0) {
            gpuDvarCount = Com_GetConfigureDvarNames(&text, gpuDvarNames);
            Com_SkipRestOfLine(&text);
            foundGpuSection = 1;
            break;
        }

        rowGHz = atof(token);
        if (rowGHz < 0.0)
            Com_Error(0, "configure_mp.csv: cpu ghz %g not allowed to be less than 0\n", rowGHz);

        token = Com_ParseOnLine(&text);
        rowMB = atoi(token);
        if (rowMB <= 0x7f)
            Com_Error(0, "configure_mp.csv: sys mb %i not allowed to be less than 128", rowMB);

        if (info.cpuGHz >= rowGHz && rowMB <= info.sysMB) {
            if (rowGHz > bestMHz || (rowGHz == bestMHz && rowMB > bestMB)) {
                best.MHz = rowGHz;
                best.MB = rowMB;
                bestMHz = rowGHz;
                bestMB = rowMB;
                Com_GetConfigureDvarValues(dvarCount, &text, best.dvarValues);
                foundCpuMatch = 1;
            } else {
                Com_GetConfigureDvarValues(dvarCount, &text, 0);
            }
        } else {
            Com_GetConfigureDvarValues(dvarCount, &text, 0);
        }

        Com_SkipRestOfLine(&text);
    }

    if (!foundCpuMatch) {
        Sys_GetInfo(&info);
        Com_Error(0, "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE %.0f GHz %i MB", info.cpuGHz, info.sysMB);
    }

    Com_Printf("configure_mp.csv: using CPU configuration %.0f GHz %i MB\n", bestMHz, bestMB);
    Cbuf_AddText("exec configure_mp.cfg");
    Cbuf_Execute();
    Com_SetConfigureDvars(dvarCount, dvarNames, best.dvarValues);

    if (!foundGpuSection)
        Com_Error(0, "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE \"%s\"\n", info.gpuDescription);

    for (;;) {
        const char *find;

        Com_SkipConfigureBlankLines(&text);
        if (!text || !*text)
            break;

        find = Com_ParseOnLine(&text);
        if (!*find || *find == '#') {
            Com_SkipRestOfLine(&text);
            continue;
        }

        if (!foundGpuMatch) {
            char wildcardTemplate[0x400];
            int wildcardLen = 1;
            wildcardTemplate[0] = '*';
            if (*find) {
                const char *p = find;
                char c;
                while ((c = *p++) != '\0') {
                    signed char sc = (signed char)c;
                    /* Check if char is upper (isalpha+isupper equivalent) */
                    int isUpper = (sc >= 'A' && sc <= 'Z');
                    if (!isUpper) {
                        wildcardTemplate[wildcardLen] = c;
                        wildcardLen++;
                        if (wildcardLen >= 0x3ff)
                            Com_Error(0, "configure_mp.csv: gpu template too long");
                    } else {
                        if (wildcardLen > 0 && wildcardTemplate[wildcardLen-1] != ' ') {
                            wildcardTemplate[wildcardLen] = ' ';
                            wildcardLen++;
                            if (wildcardLen >= 0x3ff)
                                Com_Error(0, "configure_mp.csv: gpu template too long");
                        }
                    }
                }
            }
            if (wildcardTemplate[wildcardLen - 1] == '*')
                wildcardLen--;
            wildcardTemplate[wildcardLen] = '*';
            wildcardTemplate[wildcardLen + 1] = '\0';

            if (Com_GpuStringCompare(wildcardTemplate, info.gpuDescription) == 0) {
                Com_Printf("configure_mp.csv: using GPU configuration \"%s\"\n", find);
                {
                    char gpuDvarValues[0x40 * 0x20];
                    Com_GetConfigureDvarValues(gpuDvarCount, &text, gpuDvarValues);
                    Com_SetConfigureDvars(gpuDvarCount, gpuDvarNames, gpuDvarValues);
                }
                foundGpuMatch = 1;
            } else {
                Com_GetConfigureDvarValues(gpuDvarCount, &text, 0);
            }
        } else {
            Com_GetConfigureDvarValues(gpuDvarCount, &text, 0);
        }

        Com_SkipRestOfLine(&text);
    }

    if (!foundGpuMatch)
        Com_Error(0, "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE \"%s\"\n", info.gpuDescription);

    Com_EndParseSession();

    {
        int checksum = 0;
        int i;

        for (i = 0; i < filesize; i++)
            checksum = (int)((char *)csv)[i] + checksum * 1000000007;

        checksum &= 0xfffffff;
        FS_FreeFile(csv);
        Sys_ArchiveInfo(checksum + 1);
    }

    if (restart && Dvar_AnyLatchedValues())
        Cbuf_AddText("snd_restart\n");
}

/* line 2417 */
/* line 2417 */
void Com_CheckSetRecommended(void)
{
    extern int FS_ReadFile(const char *path, void **buffer);
    extern void FS_FreeFile(void *buffer);
    extern qboolean Sys_HasConfigureChecksumChanged(int checksum);
    extern qboolean Sys_HasInfoChanged(void);
    extern void Dvar_SetBool(const dvar_t *dvar, int value);

    if (!com_recommendedSet->current.enabled) {
        Com_SetRecommended(0);
        Dvar_SetBool(com_recommendedSet, 1);
    }

    if (com_recommendedSet->current.enabled) {
        void *csv;
        int filesize = FS_ReadFile("configure_mp.csv", &csv);
        if (filesize < 0)
            Com_Error(0, "EXE_ERR_NOT_FOUND\x15configure_mp.csv");
        {
            int checksum = 0;
            if (filesize > 0) {
                int i;
                for (i = 0; i < filesize; i++) {
                    checksum = (int)((char *)csv)[i] + checksum * 1000000007;
                }
                checksum &= 0xfffffff;
            }
            FS_FreeFile(csv);
            if (Sys_HasConfigureChecksumChanged(checksum + 1)) {
                Com_SetRecommended(0);
                Dvar_SetBool(com_recommendedSet, 1);
            }
        }
    }

    if (Sys_HasInfoChanged()) {
        Com_SetRecommended(0);
    }
}

/* line 1919 */
void Com_ReadCDKey(void)
{
    extern qboolean MacPreferences_GetString(const char *key, char *buf, int bufsize, int defaultVal);
    extern qboolean CL_CDKeyValidate(const char *key, const char *checksum);
    char regkey[21];

    if (MacPreferences_GetString("codkey", regkey, 0x15, 0)) {
        memcpy(cl_cdkey, regkey, 16);
        cl_cdkey[16] = '\0';
        memcpy(cl_cdkeychecksum, regkey + 16, 4);
        cl_cdkeychecksum[4] = '\0';
        if (CL_CDKeyValidate(cl_cdkey, cl_cdkeychecksum))
            return;
    }
    memset(cl_cdkey, ' ', 16);
    cl_cdkey[16] = '\0';
}

/* line 4038 */
void Com_LocalizedFloatToString(float f, char *buffer, unsigned int maxlen, unsigned int numDecimalPlaces)
{
    unsigned int i;
    char delimiter;

    snprintf(buffer, maxlen - 1, "%.*f", numDecimalPlaces, (double)f);
    buffer[maxlen - 1] = '\0';

    delimiter = Com_GetDecimalDelimiter();
    if (delimiter == '.')
        return;

    for (i = 0; i < maxlen; i++) {
        if (buffer[i] == '.') {
            buffer[i] = delimiter;
            return;
        }
    }
}

/* line 1045 */
void Com_Quit_f(void)
{
    extern void Hunk_ClearTempMemory(void);
    extern void Hunk_ClearTempMemoryHigh(void);
    extern void Sys_DestroySplashWindow(void);
    extern void SV_Shutdown(const char *finalmsg);
    extern void FS_Shutdown(int closemfp);
    extern void FS_ShutdownServerIwdNames(void);
    extern void FS_ShutdownServerReferencedIwds(void);
    extern void Sys_Quit(void);

    Com_Printf("quitting...\n");
    if (com_errorEntered) {
        Sys_Quit();
        return;
    }
    Hunk_ClearTempMemory();
    Hunk_ClearTempMemoryHigh();
    Sys_DestroySplashWindow();
    CL_SwitchToLocalClient(0);
    CL_Shutdown();
    CL_SwitchToLocalClient(0);
    SV_Shutdown("EXE_SERVERQUIT");
    Com_Close();
    if (logfile) {
        FS_FCloseFile(logfile);
        logfile = 0;
    }
    FS_Shutdown(1);
    FS_ShutdownServerIwdNames();
    FS_ShutdownServerReferencedIwds();
    Sys_Quit();
}

/* line 3839 */
void Com_Restart(void)
{
    extern void CL_ShutdownHunkUsers(void);
    extern void SV_ShutdownGameProgs(void);
    extern void CIN_CloseAllVideos(void);
    extern void Hunk_Clear(void);
    extern void Scr_Init(void);
    extern void Scr_Settings(int enabled, int developer_script, int developer);
    extern void XAnimInit(void);
    extern void DObjInit(void);
    extern void Com_InitDObj(void);

    CL_ShutdownHunkUsers();
    SV_ShutdownGameProgs();
    CIN_CloseAllVideos();
    Com_ShutdownDObj();
    DObjShutdown();
    XAnimShutdown();
    CM_Shutdown();
    SND_ShutdownChannels();
    Hunk_Clear();
    Scr_Init();
    {
        int dev = com_developer->current.integer;
        int enabled = (dev || com_logfile->current.integer) ? 1 : 0;
        int dev_script = com_developer_script->current.enabled;
        Scr_Settings(enabled, dev_script, dev);
    }
    com_fixedConsolePosition = 0;
    XAnimInit();
    DObjInit();
    Com_InitDObj();
}

/* line 526 */
void Com_ShutdownInternal(char *finalmsg)
{
    extern void CL_Disconnect(void);
    extern void CL_ShutdownAll(void);
    extern void CL_ShutdownDemo(void);
    extern void SV_Shutdown(const char *msg);

    CL_SwitchToLocalClient(0);
    CL_Disconnect();
    CL_SwitchToLocalClient(0);
    CL_ShutdownAll();
    CL_ShutdownDemo();
    SV_Shutdown(finalmsg);
    Com_Restart();
}

/* line 691 */
/* line 691 */
static void Com_ErrorCleanup(void)
{
    extern void LargeLocalReset(void);
    extern void Hunk_ClearTempMemory(void);
    extern void Hunk_ClearTempMemoryHigh(void);
    extern void Com_IsMapProfilerActive(void);
    extern void Dvar_SetIntByName(const char *name, int value);
    extern void Dvar_SetInAutoExec(int enabled);
    extern void FS_PureServerSetLoadedIwds(const char *a, const char *b);
    extern void SEH_UpdateLanguageInfo(void);
    extern void Scr_Abort(void);
    extern void SND_ErrorCleanup(void);
    extern void Com_CleanupBsp(void);
    extern void CM_Cleanup(void);
    extern void Com_ResetParseSessions(void);
    extern void CL_FlushDebugData(int flag);
    extern void FS_ResetFiles(void);
    extern void Cbuf_Init(void);
    extern void UI_SetActiveMenu(int menu);
    extern void CL_ConsoleFixPosition(void);
    extern qboolean QuitOnError(void);
    extern void I_strncpyz(char *dest, const char *src, int destsize);
    extern const char *SEH_LocalizeTextMessage(const char *msg, const char *context, int flag);

    char szUnlocedMsg[0x1008];
    int now, rendererStarted;

    LargeLocalReset();

    /* Call re->Shutdown (offset 0x14c) if available */
    {
        void *re;
        __asm__ __volatile__ ("movl imp_re, %%eax" : "=a"(re) :: "memory");
        {
            void (*fn)(void) = *(void(**)(void))((char*)re + 0x14c);
            if (fn) fn();
        }
    }

    Dvar_SetInAutoExec(0);
    Hunk_ClearTempMemory();
    Hunk_ClearTempMemoryHigh();
    Com_IsMapProfilerActive();
    Dvar_SetIntByName("cl_paused", 0);
    FS_PureServerSetLoadedIwds("", "");
    SEH_UpdateLanguageInfo();
    strcpy(szUnlocedMsg, com_errorMessage);

    if (errorcode == 3) {
        if (com_errorMessage[0]) {
            const char *localized = SEH_LocalizeTextMessage(com_errorMessage, "error message", 1);
            if (localized)
                I_strncpyz(com_errorMessage, localized, sizeof(com_errorMessage));
        }
    } else {
        __asm__ __volatile__ (
            "movl imp_cls, %%eax\n"
            "movl 0x110(%%eax), %%eax\n"
            : "=a"(rendererStarted) :: "memory"
        );
        if (rendererStarted)
            UI_SetActiveMenu(0);
    }

    Com_SetErrorMessage(com_errorMessage);
    if (errorcode != 3)
        Scr_Abort();
    SND_ErrorCleanup();
    Com_CleanupBsp();
    CM_Cleanup();
    Com_ResetParseSessions();
    CL_FlushDebugData(1);

    /* Call re->SyncRender (offset 0xe4) if available */
    {
        void *re;
        __asm__ __volatile__ ("movl imp_re, %%eax" : "=a"(re) :: "memory");
        {
            void (*fn)(void) = *(void(**)(void))((char*)re + 0xe4);
            if (fn) fn();
        }
    }

    FS_ResetFiles();
    if (errorcode == 1)
        Cbuf_Init();

    now = Sys_Milliseconds();
    if (now - lastErrorTime <= 99) {
        errorCount++;
        if (errorCount > 3)
            errorcode = 0;
    } else {
        errorCount = 0;
    }
    lastErrorTime = now;

    if ((unsigned int)(errorcode - 1) > 2) {
        /* errorcode not 1, 2, or 3: fatal */
        Sys_Error("%s", com_errorMessage);
    }

    /* Clear updateScreenCalled */
    __asm__ __volatile__ (
        "movl imp_updateScreenCalled, %%eax\n"
        "movb $0, (%%eax)\n"
        ::: "eax", "memory"
    );

    if (errorcode == 2) {
        Com_ShutdownInternal("Server fatal crashed: %s\n");
        com_fixedConsolePosition = 0;
        com_errorEntered = 0;
        return;
    }

    /* errorcode == 1 or 3 */
    Com_Printf("********************\nERROR: %s\n********************\n", com_errorMessage);
    if (errorcode == 1) {
        __asm__ __volatile__ (
            "movl imp_cls, %%eax\n"
            "movl 0x110(%%eax), %%eax\n"
            : "=a"(rendererStarted) :: "memory"
        );
        if (rendererStarted && !com_fixedConsolePosition)
            CL_ConsoleFixPosition();
    }
    Com_ShutdownInternal(szUnlocedMsg);
    if (errorcode == 1) {
        if (QuitOnError())
            Com_Quit_f();
    }
    com_fixedConsolePosition = 0;
    com_errorEntered = 0;
}

/* line 2608 */
/* line 2608 */
void Com_ExecStartupConfigs(const char *configFile)
{
    extern void Cbuf_AddText(const char *text);
    extern void Dvar_SetInAutoExec(int enabled);

    Cbuf_AddText("exec default_mp.cfg\n");
    Cbuf_AddText("exec language.cfg\n");
    if (configFile)
        Cbuf_AddText(va("exec %s\n", configFile));
    Cbuf_Execute();
    Dvar_SetInAutoExec(1);
    Cbuf_Execute();
    Dvar_SetInAutoExec(0);
    if (Com_SafeMode())
        Cbuf_AddText("exec safemode_mp.cfg\n");
    Cbuf_Execute();
}

/* line 1497 */
int Com_EventLoop(void)
{
    extern void CL_KeyEvent(int key, int down, int time);
    extern void CL_CharEvent(int ch);
    extern void CL_PacketEvent(netadr_t from, msg_t *msg, int time);
    extern void SV_PacketEvent(netadr_t from, msg_t *msg);
    extern void Cbuf_AddText(const char *text);
    extern void LargeLocal_LargeLocal(LargeLocal *ll, int size);
    extern void *LargeLocal_GetBuf(LargeLocal *ll);
    extern void ZN10LargeLocalD1Ev(LargeLocal *ll);
    extern sysEvent_t Sys_GetEvent(void);
    extern qboolean NET_GetLoopPacket(int sock, netadr_t *net_from, msg_t *msg);
    extern void MSG_Init(msg_t *buf, byte *data, int length);

    LargeLocal bufData_ll;
    byte *data;
    msg_t buf;
    netadr_t evFrom;
    int evTime = 0;

    LargeLocal_LargeLocal(&bufData_ll, 0x4000);
    data = (byte *)LargeLocal_GetBuf(&bufData_ll);
    MSG_Init(&buf, data, 0x4000);

    for (;;) {
        int evType, evValue, evValue2, evPtrLength;
        void *evPtr;

        if (com_pushedEventsTail < com_pushedEventsHead) {
            int tail = com_pushedEventsTail++;
            sysEvent_t *q = &com_pushedEvents[(unsigned char)tail];
            evTime = q->evTime; evType = q->evType; evValue = q->evValue;
            evValue2 = q->evValue2; evPtrLength = q->evPtrLength; evPtr = q->evPtr;
        } else {
            sysEvent_t ev;
            ev = Sys_GetEvent();
            evTime = ev.evTime; evType = ev.evType; evValue = ev.evValue;
            evValue2 = ev.evValue2; evPtrLength = ev.evPtrLength; evPtr = ev.evPtr;
        }

        if (evType > 5) {
            Com_Error(0, "Com_EventLoop: bad event type %i", evType);
            continue;
        }

        switch (evType) {
        case 0: /* SE_NONE */
            while (NET_GetLoopPacket(0, &evFrom, &buf)) {
                {
                    static int _lpk0_cnt = 0;
                    if (_lpk0_cnt < 100) {
                        extern int clientConnections;
                        int _first4 = (buf.cursize >= 4) ? *(int *)buf.data : 0;
                        Com_Printf("[LOOP0] pkt#%d type=%d sz=%d cs=%d first4=0x%08x\n",
                            _lpk0_cnt, *(int *)&evFrom, buf.cursize, *(int *)&clientConnections, _first4);
                        _lpk0_cnt++;
                    }
                }
                CL_PacketEvent(evFrom, &buf, evTime);
            }
            while (NET_GetLoopPacket(1, &evFrom, &buf)) {
                static int _svpkt_cnt = 0;
                _svpkt_cnt++;
                CL_SwitchToLocalClient(0);
                if (com_sv_running->current.enabled) {
                    if (_svpkt_cnt <= 30)
                        fprintf(stderr, "[SV_Loop#%d] sz=%d port=%d first4=0x%08x\n",
                            _svpkt_cnt, buf.cursize, evFrom.port,
                            (buf.cursize >= 4) ? *(int *)buf.data : 0);
                    SV_PacketEvent(evFrom, &buf);
                } else {
                    if (_svpkt_cnt <= 30)
                        fprintf(stderr, "[SV_Loop#%d] sv_running=0, routing to CL\n", _svpkt_cnt);
                    CL_PacketEvent(evFrom, &buf, evTime);
                }
            }
            ZN10LargeLocalD1Ev(&bufData_ll);
            return evTime;
        case 1: /* SE_KEY */
            if (evValue < 0 || evValue > 255) {
                Com_Printf("BAD KEY: evValue=%d evValue2=%d\n", evValue, evValue2);
                break;
            }
            CL_KeyEvent(evValue, evValue2, evTime);
            break;
        case 2: /* SE_CHAR */
            CL_CharEvent(evValue);
            break;
        case 3: /* SE_MOUSE - ignored */
            break;
        case 4: /* SE_CONSOLE */
            CL_SwitchToLocalClient(0);
            Cbuf_AddText((char *)evPtr);
            Z_FreeInternal(evPtr);
            Cbuf_AddText("\n");
            break;
        case 5: /* SE_PACKET */
            {
                netadr_t *from = (netadr_t *)evPtr;
                int dataLen = evPtrLength - 12;
                if (dataLen > buf.maxsize) {
                    Z_FreeInternal(evPtr);
                    Com_Printf("Com_EventLoop: oversize packet\n");
                    break;
                }
                memcpy(&evFrom, from, sizeof(netadr_t));
                buf.cursize = dataLen;
                memcpy(buf.data, (char *)evPtr + 12, dataLen);
                Z_FreeInternal(evPtr);
                CL_SwitchToLocalClient(0);
                if (com_sv_running->current.enabled)
                    SV_PacketEvent(evFrom, &buf);
                else
                    CL_PacketEvent(evFrom, &buf, evTime);
                break;
            }
        }
    }
}

/* line 1716 */
qboolean Debug_EventLoop(void)
{
    extern void CL_KeyEvent(int key, int down, int time);
    extern void CL_CharEvent(int ch);
    extern void Cbuf_AddText(const char *text);
    extern sysEvent_t Sys_GetEvent(void);

    qboolean newEvent = 0;

    for (;;) {
        int evType, evValue, evValue2, evTime;
        void *evPtr;

        if (com_pushedEventsTail < com_pushedEventsHead) {
            int tail = com_pushedEventsTail++;
            sysEvent_t *q = &com_pushedEvents[(unsigned char)tail];
            evTime = q->evTime; evType = q->evType; evValue = q->evValue;
            evValue2 = q->evValue2; evPtr = q->evPtr;
        } else {
            sysEvent_t ev;
            ev = Sys_GetEvent();
            evTime = ev.evTime; evType = ev.evType; evValue = ev.evValue;
            evValue2 = ev.evValue2; evPtr = ev.evPtr;
        }

        if (evType > 5)
            Com_Error(0, "Com_EventLoop: bad event type %i", evType);

        switch (evType) {
        case 0: /* SE_NONE */
            return newEvent;
        case 1: /* SE_KEY */
            CL_KeyEvent(evValue, evValue2, evTime);
            break;
        case 2: /* SE_CHAR */
            CL_CharEvent(evValue);
            break;
        case 3:
            break;
        case 4: /* SE_CONSOLE */
            Cbuf_AddText((char *)evPtr);
            Z_FreeInternal(evPtr);
            Cbuf_AddText("\n");
            break;
        case 5: /* SE_PACKET */
            Z_FreeInternal(evPtr);
            break;
        }
        newEvent = 1;
    }
}

void Com_Frame_Try_Block_Function(void)
{
    int msec, rawMsec, minMsec, maxMsec;
    qboolean useTimescale;

    /* Write player profile if dvar flags changed */
    if (com_fullyInitialized && (dvar_modifiedFlags & 1)) {
        dvar_modifiedFlags &= ~1;
        if (Com_HasPlayerProfile()) {
            char path[64];
            Com_BuildPlayerProfilePath(path, 64, "");
            Com_WriteConfigToFile(path);
        }
    }

    /* Handle viewlog changes */
    if (com_viewlog->modified) {
        if (!com_dedicated->current.integer) {
            Sys_ShowConsole(com_viewlog->current.integer, 0);
        }
        Dvar_ClearModified(com_viewlog);
    }

    SetAnimCheck(com_animCheck->current.enabled);

    /* Calculate minimum frame time from maxfps */
    if (com_maxfps->current.integer > 0 && !com_dedicated->current.integer) {
        minMsec = 1000 / com_maxfps->current.integer;
        if (minMsec == 0)
            minMsec = 1;
    } else {
        minMsec = 1;
    }

    /* Event pump loop — wait until enough time has elapsed */
    do {
        com_frameTime = Com_EventLoop();
        if (com_frameTime < com_lastFrameTime)
            com_lastFrameTime = com_frameTime;
        rawMsec = com_frameTime - com_lastFrameTime;
        if (rawMsec < minMsec)
            NET_Sleep(0);
    } while (rawMsec < minMsec);

    Cbuf_Execute();
    com_lastFrameTime = com_frameTime;

    /* Compute msec with timescale */
    if (com_fixedtime->current.integer) {
        msec = com_fixedtime->current.integer;
        useTimescale = 1;
    } else {
        float ts = com_timescale->current.value;
        if (ts == 1.0f && com_codeTimeScale == 1.0f) {
            msec = rawMsec;
            useTimescale = 0;
        } else {
            msec = (int)floorf((float)rawMsec * ts * com_codeTimeScale + 0.5f);
            useTimescale = 1;
        }
    }

    if (msec <= 0)
        msec = 1;

    /* Determine max frame msec */
    if (com_dedicated->current.integer) {
        /* Dedicated: hitch warning for 501+ ms frames */
        if (msec >= 501 && msec <= 499999) {
            Com_Printf("Hitch warning: %i msec frame time\n", msec);
        }
        maxMsec = 5000;
    } else {
        if (com_sv_running->current.enabled)
            maxMsec = 200;
        else
            maxMsec = 5000;
    }

    /* Clamp msec to max */
    if (msec < maxMsec)
        maxMsec = msec;

    /* Compute timescale value */
    if (useTimescale && rawMsec != 0)
        com_timescaleValue = (float)maxMsec / (float)rawMsec;
    else
        com_timescaleValue = 1.0f;

    /* Server frame */
    CL_SwitchToLocalClient(0);
    SV_Frame(maxMsec);

    /* Handle dedicated mode switch */
    if (!(com_dedicated->flags & 0x40)) {
        if (com_dedicated->latched.integer != com_dedicated->current.integer) {
            com_dedicated = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1020);
            if (com_dedicated->current.integer) {
                com_dedicated = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1040);
            }
            Dvar_ClearModified(com_dedicated);
            CL_SwitchToLocalClient(0);
            CL_Shutdown();
            CL_SwitchToLocalClient(0);
            Sys_ShowConsole(1, 1);
            Sys_NormalExit();
            SV_AddDedicatedCommands();
        }
    }

    /* If dedicated, skip client frame */
    if (com_dedicated->current.integer)
        return;

    /* Client frame */
    CL_SwitchToLocalClient(0);
    CL_RunOncePerClientFrame(maxMsec);
    CL_SwitchToLocalClient(0);
    Com_EventLoop();
    CL_SwitchToLocalClient(0);
    Cbuf_Execute();
    CL_SwitchToLocalClient(0);
    SND_UpdateLoopingSounds();
    SND_Update();
    CL_SwitchToLocalClient(0);
    CL_Frame(maxMsec);
    CL_SwitchToLocalClient(0);
    SCR_UpdateScreenInternal();
    SCR_RunCinematic();

    /* StatMon checks */
    if (com_statmon->current.enabled) {
        if (*com_fileAccessed) {
            StatMon_Warning(1, 3000, "File Accessed");
            *com_fileAccessed = 0;
        }
        {
            int prevTime = timeClientFrame;
            int now = Sys_Milliseconds();
            timeClientFrame = now;
            if (com_statmon->current.enabled && (now - prevTime) > 33 && prevTime != 0) {
                StatMon_Warning(0, 3000, "33 msec frame hit");
            }
        }
    }
}

/* line 558 */
void Com_Shutdown(char *finalmsg)
{
    Com_ShutdownInternal(finalmsg);
    UI_SetMap("", "");
    CL_StartHunkUsers();
}

static void Com_StartHunkUsers(void)
{
    jmp_buf *abortframe = (jmp_buf *)Sys_GetValue(2);

    if (setjmp(*abortframe)) {
        Sys_Error("Error during initialization of hunk users");
        return;
    }

    UI_SetMap("", "");
    CL_StartHunkUsers();
    Com_EventLoop();

    if (com_dedicated && !com_dedicated->current.integer) {
        UI_SetActiveMenu(1);
    }
}

/* line 3618 */
void Com_Frame(void)
{
    jmp_buf *abortframe = (jmp_buf *)Sys_GetValue(2);

    if (setjmp(*abortframe)) {
        if (com_errorEntered) {
            Com_ErrorCleanup();
            Com_StartHunkUsers();
        }
        return;
    }

    Com_Frame_Try_Block_Function();
    com_frameNumber++;
}

/* line 3060 */
void Com_WriteDefaults_f(void)
{
    extern const char *Cmd_Argv(int arg);
    extern void I_strncpyz(char *dest, const char *src, int destsize);
    extern void Com_DefaultExtension(char *path, int maxSize, const char *extension);
    extern void Dvar_WriteDefaults(int f);
    char filename[64];
    int f;

    if (Cmd_Argc() != 2) {
        Com_Printf("Usage: writedefaults <filename>\n");
        return;
    }
    I_strncpyz(filename, Cmd_Argv(1), 0x40);
    Com_DefaultExtension(filename, 0x40, ".cfg");
    Com_Printf("Writing %s.\n", filename);
    f = FS_FOpenFileWrite(filename);
    if (!f) {
        Com_Printf("Couldn't write %s.\n", filename);
        return;
    }
    FS_Printf(f, "// generated by Call of Duty, do not modify\n");
    Dvar_WriteDefaults(f);
    FS_FCloseFile(f);
}

/* line 1789 */
int Com_Milliseconds(void)
{
    extern sysEvent_t Sys_GetEvent(void);
    sysEvent_t ev;

    for (;;) {
        ev = Sys_GetEvent();
        if (ev.evType == 0)
            break;

        /* Inline Com_PushEvent */
        {
            int head = com_pushedEventsHead;
            int idx = (unsigned char)head;
            sysEvent_t *pushed = &com_pushedEvents[idx];

            if (head - com_pushedEventsTail > 255) {
                if (!printedWarning) {
                    printedWarning = 1;
                    Com_Printf("WARNING: Com_PushEvent overflow\n");
                }
                if (pushed->evPtr)
                    Z_FreeInternal(pushed->evPtr);
                com_pushedEventsTail++;
            } else {
                printedWarning = 0;
            }

            *pushed = ev;
            com_pushedEventsHead++;
        }
    }

    return ev.evTime;
}

/* line 1812 */
void Com_PumpMessageLoop(void)
{
    extern sysEvent_t Sys_GetEvent(void);
    sysEvent_t ev;

    for (;;) {
        ev = Sys_GetEvent();
        if (!ev.evType)
            return;
        /* Com_PushEvent inline */
        {
            int head = com_pushedEventsHead;
            sysEvent_t *slot = &com_pushedEvents[(unsigned char)head];
            if (head - com_pushedEventsTail > 0xff) {
                if (!printedWarning) {
                    printedWarning = 1;
                    Com_Printf("WARNING: Com_PushEvent overflow\n");
                }
                if (slot->evPtr)
                    Z_FreeInternal(slot->evPtr);
                com_pushedEventsTail++;
            } else {
                printedWarning = 0;
            }
            *slot = ev;
            com_pushedEventsHead++;
        }
    }
}

/* line 1858 */
static void Com_Freeze_f(void)
{
    extern const char *Cmd_Argv(int arg);
    extern sysEvent_t Sys_GetEvent(void);
    extern double atof(const char *s);
    sysEvent_t ev;
    float s;
    int startTime;

    if (Cmd_Argc() != 2) {
        Com_Printf("Usage: freeze <seconds>\n");
        return;
    }
    s = (float)atof(Cmd_Argv(1));

    /* First pump: drain all pending events */
    for (;;) {
        ev = Sys_GetEvent();
        if (!ev.evType)
            break;
        {
            int head = com_pushedEventsHead;
            sysEvent_t *slot = &com_pushedEvents[(unsigned char)head];
            if (head - com_pushedEventsTail > 0xff) {
                if (!printedWarning) {
                    printedWarning = 1;
                    Com_Printf("WARNING: Com_PushEvent overflow\n");
                }
                if (slot->evPtr)
                    Z_FreeInternal(slot->evPtr);
                com_pushedEventsTail++;
            } else {
                printedWarning = 0;
            }
            *slot = ev;
            com_pushedEventsHead++;
        }
    }
    startTime = ev.evTime;

    /* Second pump: keep looping until elapsed time >= s */
    for (;;) {
        ev = Sys_GetEvent();
        if (!ev.evType) {
            if ((ev.evTime - startTime) * 0.001 >= (double)s)
                return;
            continue;
        }
        {
            int head = com_pushedEventsHead;
            sysEvent_t *slot = &com_pushedEvents[(unsigned char)head];
            if (head - com_pushedEventsTail > 0xff) {
                if (!printedWarning) {
                    printedWarning = 1;
                    Com_Printf("WARNING: Com_PushEvent overflow\n");
                }
                if (slot->evPtr)
                    Z_FreeInternal(slot->evPtr);
                com_pushedEventsTail++;
            } else {
                printedWarning = 0;
            }
            *slot = ev;
            com_pushedEventsHead++;
        }
    }
}

/* line 2648 */
void Com_Init_Try_Block_Function(char *commandLine)
{
    extern void Swap_Init(void);
    extern void Cbuf_Init(void);
    extern void Cmd_Init(void);
    extern void CL_InitKeyCommands(void);
    extern void FS_InitFilesystem(void);
    extern const dvar_t *Dvar_RegisterBool(const char *name, int value, int flags);
    extern const dvar_t *Dvar_RegisterFloat(const char *name, float value, float min, float max, int flags);
    extern const dvar_t *Dvar_RegisterString(const char *name, const char *value, int flags);
    extern void Dvar_SetString(const dvar_t *dvar, const char *value);
    extern void Dvar_SetInt(const dvar_t *dvar, int value);
    extern void Dvar_SetBool(const dvar_t *dvar, int value);
    extern void Com_InitPlayerProfiles(void);
    extern void SEH_UpdateLanguageInfo(void);
    extern void Com_InitHunkMemory(void);
    extern void Cmd_AddCommand(const char *name, void (*function)(void));
    extern char *getBuildNumber(void);
    extern void FxMem_Init(void);
    extern void Sys_Init(void);
    extern void Netchan_Init(int port);
    extern void Scr_Init(void);
    extern void Scr_Settings(int enabled, int developer_script, int developer);
    extern void XAnimInit(void);
    extern void DObjInit(void);
    extern void SV_Init(void);
    extern void NET_Init(void);
    extern void CL_InitOnceForAllClients(void);
    extern void CL_Init(void);
    extern void CL_InitRenderer(void);
    extern void SND_Init(void);
    extern void Sys_HideSplashWindow(void);
    extern void Sys_LoadingKeepAlive(void);
    extern void Cbuf_AddText(const char *text);
    extern int I_strnicmp(const char *s1, const char *s2, int count);
    char *p;
    int i;

    /* Print version string */
    Com_Printf("%s %s build %s %s\n", "CoD2 MP", "1.0", "MacOSXS-i386", "Apr 18 2006");

    /* Clear pushed events */
    memset(com_pushedEvents, 0, sizeof(com_pushedEvents));
    com_pushedEventsHead = 0;
    com_pushedEventsTail = 0;

    /* Parse command line into console lines */
    com_consoleLines[0] = commandLine;
    com_numConsoleLines = 1;
    p = commandLine;
    while (*p) {
        if (*p == '+' || *p == '\n') {
            if (com_numConsoleLines == 32)
                break;
            com_consoleLines[com_numConsoleLines] = p + 1;
            com_numConsoleLines++;
            *p = '\0';
            p++;
            continue;
        }
        p++;
    }

    /* Initialize subsystems */
    Swap_Init();
    Cbuf_Init();
    Cmd_Init();
    Com_StartupVariable(NULL);
    Com_StartupVariable("developer");
    CL_InitKeyCommands();
    FS_InitFilesystem();

    /* Register dedicated dvar */
    {
        int dedicated_val;
        com_dedicated = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1020);
        dedicated_val = com_dedicated->current.integer;
        if (dedicated_val) {
            Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1040);
        }
    }

    /* Register core dvars */
    com_maxfps = Dvar_RegisterInt("com_maxfps", 85, 0, 1000, 0x1001);
    com_developer = Dvar_RegisterInt("developer", 0, 0, 2, 0x1000);
    com_developer_script = Dvar_RegisterBool("developer_script", 0, 0x1000);
    com_logfile = Dvar_RegisterInt("logfile", 0, 0, 2, 0x1000);
    com_statmon = Dvar_RegisterBool("com_statmon", 0, 0x1000);
    com_timescale = Dvar_RegisterFloat("timescale", 1.0f, 0.001f, 1000.0f, 0x1088);
    com_fixedtime = Dvar_RegisterInt("fixedtime", 0, 0, 1000, 0x1080);
    com_viewlog = Dvar_RegisterInt("viewlog", 0, 0, 2, 0x1080);
    sv_paused = Dvar_RegisterInt("sv_paused", 0, 0, 2, 0x1040);
    cl_paused = Dvar_RegisterInt("cl_paused", 0, 0, 2, 0x1040);
    com_sv_running = Dvar_RegisterBool("sv_running", 0, 0x1040);

    /* Clear legacyHacks field */
    __asm__ __volatile__ (
        "movl imp_legacyHacks, %%eax\n"
        "movl (%%eax), %%eax\n"
        "movl $0, 4(%%eax)\n"
        ::: "eax", "memory"
    );

    com_introPlayed = Dvar_RegisterBool("com_introPlayed", 0, 0x1001);
    com_animCheck = Dvar_RegisterBool("com_animCheck", 0, 0x1000);

    /* If dedicated and viewlog == 0, force viewlog to 1 */
    {
        if (com_dedicated->current.integer) {
            if (com_viewlog->current.integer == 0) {
                Dvar_SetInt(com_viewlog, 1);
            }
        }
    }

    /* Player profiles & startup */
    CL_SwitchToLocalClient(0);
    Com_InitPlayerProfiles();
    CL_SwitchToLocalClient(0);
    Cbuf_Execute();

    com_recommendedSet = Dvar_RegisterBool("com_recommendedSet", 0, 0x1001);
    Com_CheckSetRecommended();
    Com_StartupVariable(NULL);
    SEH_UpdateLanguageInfo();

    /* If dedicated, show console and exit splash */
    {
        if (com_dedicated->current.integer) {
            Sys_HideSplashWindow();
            Sys_ShowConsole(1, 1);
            Sys_NormalExit();
        }
    }

    Com_InitHunkMemory();

    /* Clear dvar modified flags bit 0 */
    __asm__ __volatile__ (
        "movl imp_dvar_modifiedFlags, %%eax\n"
        "andl $0xfffffffe, (%%eax)\n"
        ::: "eax", "memory"
    );
    com_codeTimeScale = 1.0f;

    /* Developer commands */
    if (com_developer->current.integer) {
        Cmd_AddCommand("error", Com_Error_f);
        Cmd_AddCommand("crash", Com_Crash_f);
        Cmd_AddCommand("freeze", Com_Freeze_f);
    }

    Cmd_AddCommand("quit", Com_Quit_f);
    Cmd_AddCommand("writeconfig", Com_WriteConfig_f);
    Cmd_AddCommand("writedefaults", Com_WriteDefaults_f);

    /* Register version dvars */
    {
        char *s = va("%s %s build %s %s", "CoD2 MP", "1.0", getBuildNumber(), "MacOSXS-i386");
        version = Dvar_RegisterString("version", "", 0x1040);
        Dvar_SetString(version, s);
    }
    shortversion = Dvar_RegisterString("shortversion", "1.0", 0x1044);

    FxMem_Init();
    Sys_Init();

    /* Pump events to get current time for Netchan_Init */
    Netchan_Init(Com_Milliseconds() & 0xffff);

    Scr_Init();
    /* DBG: count free script variables after Scr_Init */
    {
        extern unsigned char scrVarGlob[];
        int freeCount = 0;
        unsigned short idx = *(unsigned short *)(scrVarGlob + 4);
        while (idx != 0 && freeCount < 70000) {
            freeCount++;
            idx = *(unsigned short *)(scrVarGlob + (unsigned int)idx * 16 + 4);
        }
        Com_Printf("DBG after Scr_Init: %d free script variables\n", freeCount);
    }
    {
        int dev = com_developer->current.integer;
        int enabled = (dev || com_logfile->current.integer) ? 1 : 0;
        Scr_Settings(enabled, com_developer_script->current.enabled, dev);
    }

    XAnimInit();
    DObjInit();
    SV_Init();
    NET_Init();

    {
        const dvar_t *ded;
        int dedicated_val;
        ded = com_dedicated;
        Dvar_ClearModified(ded);
        dedicated_val = ded->current.integer;
        if (!dedicated_val) {
            CL_InitOnceForAllClients();
            CL_SwitchToLocalClient(0);
            CL_Init();
            CL_SwitchToLocalClient(0);
            Sys_ShowConsole(com_viewlog->current.integer, 0);
        }
    }

    /* Second event pump */
    com_frameTime = Com_Milliseconds();

    /* Execute console lines */
    for (i = 0; i < com_numConsoleLines; i++) {
        if (!com_consoleLines[i] || com_consoleLines[i][0] == '\0')
            continue;
        I_strnicmp(com_consoleLines[i], "set", 3);
        Cbuf_AddText(com_consoleLines[i]);
        Cbuf_AddText("\n");
    }

    {
        int dedicated_val;
        dedicated_val = com_dedicated->current.integer;
        if (dedicated_val) {
            /* Dedicated server */
            Sys_LoadingKeepAlive();
        } else {
            /* Client renderer & sound init */
            {
                char *cls_ptr;
                __asm__ __volatile__ ("movl imp_cls, %%eax\n" : "=a"(cls_ptr) :: "memory");
                *(int *)(cls_ptr + 0x108) = 1; /* rendererStarted */
                CL_InitRenderer();
                *(int *)(cls_ptr + 0x10c) = 1; /* soundStarted */
            }
            SND_Init();
            Sys_LoadingKeepAlive();

            dedicated_val = com_dedicated->current.integer;
            if (!dedicated_val) {
                Sys_ShowConsole(com_viewlog->current.integer, 0);
            }
        }

        /* Intro cinematic (non-dedicated only) */
        dedicated_val = com_dedicated->current.integer;
        if (!dedicated_val) {
            if (!com_introPlayed->current.enabled) {
                Cbuf_AddText("cinematic atvi\n");
                Dvar_SetString(nextmap, "cinematic IW_logo; set nextmap cinematic cod_intro");
                Dvar_SetBool(com_introPlayed, 1);
            }
        }
    }

    /* Finalize initialization */
    com_fullyInitialized = 1;
    Com_Printf("--- Common Initialization Complete ---\n");
    Cbuf_Execute();

    if (!com_sv_running->current.enabled) {
        UI_SetMap("", "");
        CL_StartHunkUsers();
    }
}

/* line 2916 */
void Com_Init(char *commandLine)
{
    jmp_buf *abortframe = (jmp_buf *)Sys_GetValue(2);

    if (setjmp(*abortframe)) {
        Sys_Error(va("Error during initialization:\n%s\n", com_errorMessage));
        return;
    }

    Com_Init_Try_Block_Function(commandLine);
}
