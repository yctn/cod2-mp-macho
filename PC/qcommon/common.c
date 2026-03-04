/* ASM dump from: common.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/common.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdarg.h>

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
extern const dvar_t **com_dedicated; /* import pointer */
extern int *dvar_modifiedFlags; /* import pointer */
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
static int Com_GpuStringCompare(void);
static int Com_GetConfigureDvarNames(const char * *text);
static void Com_GetConfigureDvarValues(int dvarCount, const char * *text);
static void Com_SetConfigureDvars(int dvarCount);
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

    if (type != 4) {
        /* com_dedicated is an import-pointer-style global: the dvar_t* is stored
           at the address of the symbol, accessed via single dereference from imp_ */
        int dedicated_val;
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%eax\n"
            "movl (%%eax), %%eax\n"
            "testl %%eax, %%eax\n"
            "je 1f\n"
            "movl 8(%%eax), %%eax\n"
            "1:\n"
            : "=a"(dedicated_val) :: "memory"
        );
        if (dedicated_val == 0) {
            CL_ConsolePrint(type, msg, 0, 0);
        }
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
__attribute__((naked))
void Info_Print(const char *s)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1347 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x410, %esp\n"
        "movl 8(%ebp), %ebx\n" /* s */
        /* { scope 1 */
        "leal 1(%ebx), %eax\n" /* line 1355 | s */
        "cmpb $0x5c, (%ebx)\n" /* s */
        "cmovel %eax, %ebx\n" /* s */
        "cmpb $0, (%ebx)\n" /* line 1356 | s */
        "je .Lf2f060_0002f11f\n"
        "leal -0x208(%ebp), %esi\n" /* key */
        ".Lf2f060_0002f086:\n"
        "movzbl (%ebx), %eax\n" /* line 1359 | s */
        "cmpb $0x5c, %al\n"
        "je .Lf2f060_0002f1d0\n"
        "movb %al, -0x208(%ebp)\n" /* line 1360 | key */
        "addl $1, %ebx\n" /* s */
        "movzbl (%ebx), %eax\n" /* line 1359 | s */
        "testb %al, %al\n"
        "jne .Lf2f060_0002f155\n"
        "leal -0x207(%ebp), %edx\n"
        ".Lf2f060_0002f0ab:\n"
        "movl %edx, %ecx\n" /* line 1362 */
        "subl %esi, %ecx\n"
        "cmpl $0x13, %ecx\n" /* line 1363 */
        "jle .Lf2f060_0002f17f\n"
        ".Lf2f060_0002f0b8:\n"
        "movb $0, (%edx)\n" /* line 1369 */
        "movl %esi, 4(%esp)\n" /* line 1370 */
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "cmpb $0, (%ebx)\n" /* line 1372 | s */
        "je .Lf2f060_0002f1ba\n"
        ".Lf2f060_0002f0d4:\n"
        "addl $1, %ebx\n" /* line 1379 | s */
        "movzbl (%ebx), %eax\n" /* line 1380 | s */
        "testb %al, %al\n"
        "je .Lf2f060_0002f129\n"
        "cmpb $0x5c, %al\n"
        "je .Lf2f060_0002f129\n"
        "leal -0x408(%ebp), %ecx\n" /* value */
        "movl %ecx, %edx\n"
        ".Lf2f060_0002f0ea:\n"
        "movb %al, (%edx)\n" /* line 1381 */
        "addl $1, %edx\n"
        "addl $1, %ebx\n" /* s */
        "movzbl (%ebx), %eax\n" /* line 1380 | s */
        "testb %al, %al\n"
        "je .Lf2f060_0002f0fd\n"
        "cmpb $0x5c, %al\n"
        "jne .Lf2f060_0002f0ea\n"
        ".Lf2f060_0002f0fd:\n"
        "movb $0, (%edx)\n" /* line 1382 */
        "cmpb $1, (%ebx)\n" /* line 1385 | s */
        "sbbl $-1, %ebx\n" /* s */
        "movl %ecx, 4(%esp)\n" /* line 1386 */
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "cmpb $0, (%ebx)\n" /* line 1356 | s */
        "jne .Lf2f060_0002f086\n"
        /* } scope */
        ".Lf2f060_0002f11f:\n"
        "addl $0x410, %esp\n" /* line 1388 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f060_0002f129:\n"
        "leal -0x408(%ebp), %ecx\n" /* line 1380 | value */
        "movl %ecx, %edx\n"
        "movb $0, (%edx)\n" /* line 1382 */
        "cmpb $1, (%ebx)\n" /* line 1385 | s */
        "sbbl $-1, %ebx\n" /* s */
        "movl %ecx, 4(%esp)\n" /* line 1386 */
        "movl $str_00215bbc, (%esp)\n" /* "%s
" */
        "calll Com_Printf\n"
        "cmpb $0, (%ebx)\n" /* line 1356 | s */
        "jne .Lf2f060_0002f086\n"
        "jmp .Lf2f060_0002f11f\n"
        ".Lf2f060_0002f155:\n"
        "leal -0x207(%ebp), %edx\n" /* line 1359 */
        ".Lf2f060_0002f15b:\n"
        "cmpb $0x5c, %al\n"
        "je .Lf2f060_0002f0ab\n"
        "movb %al, (%edx)\n" /* line 1360 */
        "addl $1, %edx\n"
        "addl $1, %ebx\n" /* s */
        "movzbl (%ebx), %eax\n" /* line 1359 | s */
        "testb %al, %al\n"
        "jne .Lf2f060_0002f15b\n"
        "movl %edx, %ecx\n" /* line 1362 */
        "subl %esi, %ecx\n"
        "cmpl $0x13, %ecx\n" /* line 1363 */
        "jg .Lf2f060_0002f0b8\n"
        ".Lf2f060_0002f17f:\n"
        "movl $0x14, %eax\n" /* line 1365 */
        "subl %ecx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x20, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movb $0, -0x1f4(%ebp)\n" /* line 1366 */
        "movl %esi, 4(%esp)\n" /* line 1370 */
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "cmpb $0, (%ebx)\n" /* line 1372 | s */
        "jne .Lf2f060_0002f0d4\n"
        ".Lf2f060_0002f1ba:\n"
        "movl $str_002160ec, (%esp)\n" /* line 1374 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x410, %esp\n" /* line 1388 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f060_0002f1d0:\n"
        "movl %esi, %edx\n" /* line 1359 */
        "jmp .Lf2f060_0002f0ab\n"
    );
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
static __attribute__((naked))
int Com_GpuStringCompare(void)
{
    __asm__ __volatile__ (
        ".Lf2f302_0002f302:\n"
        "pushl %ebp\n" /* line 2067 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, %ecx\n" /* wild */
        "movl %edx, %edi\n" /* s */
        /* { scope 1 */
        "movzbl (%ecx), %ebx\n" /* line 2078 | wild, charWild */
        "leal 1(%ecx), %eax\n" /* line 2079 | wild */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpb $0x2a, %bl\n" /* line 2081 | charWild */
        "je .Lf2f302_0002f369\n"
        ".Lf2f302_0002f31d:\n"
        "cmpb $0x20, %bl\n" /* line 2088 | charWild */
        "je .Lf2f302_0002f38c\n"
        "movzbl (%edi), %eax\n" /* line 2095 | s */
        "movb %al, -0x1d(%ebp)\n" /* charRef */
        "addl $1, %edi\n" /* line 2096 | s */
        "cmpb %al, %bl\n" /* line 2097 | charWild */
        "je .Lf2f302_0002f354\n"
        "cmpb $0x3f, %bl\n" /* charWild */
        "je .Lf2f302_0002f354\n"
        "movsbl %bl, %eax\n" /* line 2099 | charWild */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "movl %eax, %esi\n"
        "movsbl -0x1d(%ebp), %eax\n" /* charRef */
        "movl %eax, (%esp)\n"
        "calll ___tolower\n"
        "subl %eax, %esi\n"
        "cmpl $0, %esi\n" /* line 2100 */
        "jne .Lf2f302_0002f3ba\n"
        ".Lf2f302_0002f354:\n"
        "testb %bl, %bl\n" /* line 2076 | charWild */
        "je .Lf2f302_0002f382\n"
        /* } scope */
        ".Lf2f302_0002f358:\n"
        "movl -0x1c(%ebp), %ecx\n" /* line 2067 | wild */
        /* { scope 1 */
        "movzbl (%ecx), %ebx\n" /* line 2078 | wild, charWild */
        "leal 1(%ecx), %eax\n" /* line 2079 | wild */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpb $0x2a, %bl\n" /* line 2081 | charWild */
        "jne .Lf2f302_0002f31d\n"
        ".Lf2f302_0002f369:\n"
        "cmpb $0, 1(%ecx)\n" /* line 2083 | wild */
        "je .Lf2f302_0002f382\n"
        "cmpb $0, (%edi)\n" /* line 2085 | s */
        "je .Lf2f302_0002f358\n"
        ".Lf2f302_0002f374:\n"
        "leal 1(%edi), %edx\n" /* line 2090 | s, _c */
        "movl %ecx, %eax\n" /* wild */
        "calll Com_GpuStringCompare\n"
        "testl %eax, %eax\n"
        "jne .Lf2f302_0002f358\n"
        ".Lf2f302_0002f382:\n"
        "xorl %eax, %eax\n" /* line 2076 */
        /* } scope */
        ".Lf2f302_0002f384:\n"
        "addl $0x2c, %esp\n" /* line 2107 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f302_0002f38c:\n"
        "movzbl (%edi), %eax\n" /* line 2090 | s */
        "testb %al, %al\n"
        "je .Lf2f302_0002f358\n"
        "movsbl %al, %edx\n" /* _c */
        /* { scope 2 */
        "cmpl $0xff, %edx\n" /* line 231 */
        "ja .Lf2f302_0002f374\n"
        "movl __DefaultRuneLocale, %eax\n"
        "testb $4, 0x35(%eax, %edx, 4)\n"
        "jne .Lf2f302_0002f358\n"
        /* } scope */
        "leal 1(%edi), %edx\n" /* line 2090 | s, _c */
        "movl %ecx, %eax\n" /* wild */
        "calll Com_GpuStringCompare\n"
        "testl %eax, %eax\n"
        "jne .Lf2f302_0002f358\n"
        "jmp .Lf2f302_0002f382\n"
        ".Lf2f302_0002f3ba:\n"
        "jl .Lf2f302_0002f3c9\n" /* line 2101 */
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2107 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f302_0002f3c9:\n"
        "movl $0xffffffff, %eax\n" /* line 2101 */
        "jmp .Lf2f302_0002f384\n"
    );
}

/* line 2150 */
static __attribute__((naked))
int Com_GetConfigureDvarNames(const char * *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2150 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edx, %esi\n" /* dvarNames */
        "movl $0, -0x1c(%ebp)\n" /* dvarCount */
        "jmp .Lf2f3d0_0002f40b\n"
        /* { scope 1 */
        ".Lf2f3d0_0002f3e7:\n"
        "cmpl $0x3f, -0x1c(%ebp)\n" /* line 2166 | dvarCount */
        "jg .Lf2f3d0_0002f45f\n"
        ".Lf2f3d0_0002f3ed:\n"
        "movl $0x20, 8(%esp)\n" /* line 2169 */
        "movl %ebx, 4(%esp)\n" /* token */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $1, -0x1c(%ebp)\n" /* line 2170 | dvarCount */
        "addl $0x20, %esi\n"
        "movl -0x20(%ebp), %eax\n"
        ".Lf2f3d0_0002f40b:\n"
        "movl %eax, (%esp)\n" /* line 2158 */
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n" /* token */
        "movl -0x20(%ebp), %eax\n" /* line 2159 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2f3d0_0002f48b\n"
        ".Lf2f3d0_0002f41e:\n"
        "cmpb $0, (%ebx)\n" /* line 2161 | token */
        "je .Lf2f3d0_0002f480\n"
        "cld\n" /* line 2164 */
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n" /* token */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "cmpl $0x1f, %ecx\n"
        "jbe .Lf2f3d0_0002f3e7\n"
        "movl $0x1f, 0xc(%esp)\n" /* line 2165 */
        "movl %ebx, 8(%esp)\n" /* token */
        "movl $str_00216180, 4(%esp)\n" /* "configure_mp.csv: dvar name "%s" longer than %i
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "cmpl $0x3f, -0x1c(%ebp)\n" /* line 2166 | dvarCount */
        "jle .Lf2f3d0_0002f3ed\n"
        ".Lf2f3d0_0002f45f:\n"
        "movl $0x40, 8(%esp)\n" /* line 2167 */
        "movl $str_002161b4, 4(%esp)\n" /* "configure_mp.csv: more than %i dvars
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f3d0_0002f3ed\n"
        /* } scope */
        ".Lf2f3d0_0002f480:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2174 | dvarCount */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f3d0_0002f48b:\n"
        "movl $str_00216154, 4(%esp)\n" /* line 2160 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f3d0_0002f41e\n"
    );
}

/* line 2179 */
static __attribute__((naked))
void Com_GetConfigureDvarValues(int dvarCount, const char * *text)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2179 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %edx, -0x24(%ebp)\n"
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 2184 */
        "jg .Lf2f4a4_0002f4e6\n"
        "movl %edx, %eax\n"
        ".Lf2f4a4_0002f4b9:\n"
        "movl %eax, (%esp)\n" /* line 2198 */
        "calll Com_ParseOnLine\n"
        "cmpb $0, (%eax)\n" /* line 2199 */
        "je .Lf2f4a4_0002f4de\n"
        "movl %eax, 8(%esp)\n" /* line 2200 */
        "movl $str_00216264, 4(%esp)\n" /* "configure_mp.csv: extra dvar value column(s): value = %s
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf2f4a4_0002f4de:\n"
        "addl $0x3c, %esp\n" /* line 2201 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f4a4_0002f4e6:\n"
        "movl %ecx, -0x1c(%ebp)\n" /* line 2184 | dvarValues */
        "xorl %esi, %esi\n" /* dvarIndex */
        "testl %ecx, %ecx\n" /* dvarValues */
        "jne .Lf2f4a4_0002f60e\n"
        "movl -0x24(%ebp), %eax\n" /* line 2186 */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n"
        "movl -0x24(%ebp), %eax\n" /* line 2187 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf2f4a4_0002f556\n"
        ".Lf2f4a4_0002f509:\n"
        "movl $str_00216154, 4(%esp)\n" /* line 2188 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "cmpb $0, (%ebx)\n" /* line 2189 */
        "je .Lf2f4a4_0002f55b\n"
        ".Lf2f4a4_0002f522:\n"
        "cld\n" /* line 2191 */
        "movl $0xffffffff, %ecx\n" /* dvarValues */
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n" /* dvarValues */
        "leal -1(%ecx), %eax\n" /* dvarValues */
        "cmpl $0x1f, %eax\n"
        "ja .Lf2f4a4_0002f589\n"
        ".Lf2f4a4_0002f538:\n"
        "addl $1, %esi\n" /* line 2184 | dvarIndex */
        "cmpl %esi, -0x20(%ebp)\n" /* dvarIndex */
        "je .Lf2f4a4_0002f5b5\n"
        ".Lf2f4a4_0002f540:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2186 */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n"
        "movl -0x24(%ebp), %eax\n" /* line 2187 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2f4a4_0002f509\n"
        ".Lf2f4a4_0002f556:\n"
        "cmpb $0, (%ebx)\n" /* line 2189 */
        "jne .Lf2f4a4_0002f522\n"
        ".Lf2f4a4_0002f55b:\n"
        "movl %esi, 8(%esp)\n" /* line 2190 | dvarIndex */
        "movl $str_002161dc, 4(%esp)\n" /* "configure_mp.csv: missing entry in dvar value column %i
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "cld\n" /* line 2191 */
        "movl $0xffffffff, %ecx\n" /* dvarValues */
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n" /* dvarValues */
        "leal -1(%ecx), %eax\n" /* dvarValues */
        "cmpl $0x1f, %eax\n"
        "jbe .Lf2f4a4_0002f538\n"
        ".Lf2f4a4_0002f589:\n"
        "movl $0x1f, 0x10(%esp)\n" /* line 2192 */
        "movl %esi, 0xc(%esp)\n" /* dvarIndex */
        "movl %ebx, 8(%esp)\n"
        "movl $str_00216218, 4(%esp)\n" /* "configure_mp.csv: entry '%s' in dvar value column %i is lon" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "addl $1, %esi\n" /* line 2184 | dvarIndex */
        "cmpl %esi, -0x20(%ebp)\n" /* dvarIndex */
        "jne .Lf2f4a4_0002f540\n"
        ".Lf2f4a4_0002f5b5:\n"
        "movl -0x24(%ebp), %eax\n"
        "jmp .Lf2f4a4_0002f4b9\n"
        ".Lf2f4a4_0002f5bd:\n"
        "movl %esi, 8(%esp)\n" /* line 2190 | dvarIndex */
        "movl $str_002161dc, 4(%esp)\n" /* "configure_mp.csv: missing entry in dvar value column %i
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "cld\n" /* line 2191 */
        "movl $0xffffffff, %ecx\n" /* dvarValues */
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n" /* dvarValues */
        "leal -1(%ecx), %eax\n" /* dvarValues */
        "cmpl $0x1f, %eax\n"
        "ja .Lf2f4a4_0002f63f\n"
        ".Lf2f4a4_0002f5eb:\n"
        "movl $0x20, 8(%esp)\n" /* line 2195 */
        "movl %ebx, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll I_strncpyz\n"
        "addl $1, %esi\n" /* line 2184 | dvarIndex */
        "addl $0x20, -0x1c(%ebp)\n"
        "cmpl %esi, -0x20(%ebp)\n" /* dvarIndex */
        "je .Lf2f4a4_0002f5b5\n"
        ".Lf2f4a4_0002f60e:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2186 */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, %ebx\n"
        "movl -0x24(%ebp), %eax\n" /* line 2187 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2f4a4_0002f665\n"
        ".Lf2f4a4_0002f624:\n"
        "cmpb $0, (%ebx)\n" /* line 2189 */
        "je .Lf2f4a4_0002f5bd\n"
        "cld\n" /* line 2191 */
        "movl $0xffffffff, %ecx\n" /* dvarValues */
        "movl %ebx, %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n" /* dvarValues */
        "leal -1(%ecx), %eax\n" /* dvarValues */
        "cmpl $0x1f, %eax\n"
        "jbe .Lf2f4a4_0002f5eb\n"
        ".Lf2f4a4_0002f63f:\n"
        "movl $0x1f, 0x10(%esp)\n" /* line 2192 */
        "movl %esi, 0xc(%esp)\n" /* dvarIndex */
        "movl %ebx, 8(%esp)\n"
        "movl $str_00216218, 4(%esp)\n" /* "configure_mp.csv: entry '%s' in dvar value column %i is lon" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f4a4_0002f5eb\n"
        ".Lf2f4a4_0002f665:\n"
        "movl $str_00216154, 4(%esp)\n" /* line 2188 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f4a4_0002f624\n"
    );
}

/* line 2206 */
static __attribute__((naked))
void Com_SetConfigureDvars(int dvarCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2206 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl %eax, -0x24(%ebp)\n"
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 2211 */
        "jg .Lf2f67c_0002f694\n"
        /* } scope */
        ".Lf2f67c_0002f68c:\n"
        "addl $0x2c, %esp\n" /* line 2229 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f67c_0002f694:\n"
        "movl %edx, %ebx\n" /* line 2211 | dvarNames */
        "movl %ecx, -0x1c(%ebp)\n" /* dvarValues */
        "movl $0, -0x20(%ebp)\n" /* dvarIndex */
        "jmp .Lf2f67c_0002f6e5\n"
        ".Lf2f67c_0002f6a2:\n"
        "movl $1, 8(%esp)\n" /* line 2216 */
        "movl $str_002162ac, 4(%esp)\n" /* "1" */
        ".Lf2f67c_0002f6b2:\n"
        "movl %ebx, (%esp)\n" /* line 2224 */
        "calll Dvar_SetFromStringByNameFromSource\n"
        "movl %ebx, (%esp)\n" /* line 2225 */
        "calll Dvar_FindVar\n"
        "movl $1, 4(%esp)\n" /* line 2227 */
        "movl %eax, (%esp)\n"
        "calll Dvar_AddFlags\n"
        "addl $1, -0x20(%ebp)\n" /* line 2211 | dvarIndex */
        "addl $0x20, %ebx\n"
        "addl $0x20, -0x1c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n" /* dvarIndex */
        "cmpl %eax, -0x24(%ebp)\n"
        "je .Lf2f67c_0002f68c\n"
        ".Lf2f67c_0002f6e5:\n"
        "movl $0xc, %ecx\n" /* line 2214 | dvarValues */
        "cld\n"
        "movl %ebx, %esi\n"
        "movl $str_002162a0, %edi\n" /* "r_aaSamples" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf2f67c_0002f705\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n" /* dvarValues */
        "subl %ecx, %eax\n" /* dvarValues */
        ".Lf2f67c_0002f705:\n"
        "testl %eax, %eax\n"
        "je .Lf2f67c_0002f6a2\n"
        "movl $1, 8(%esp)\n" /* line 2224 */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "jmp .Lf2f67c_0002f6b2\n"
    );
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
__attribute__((naked))
int Com_AddToString(const char *add, char *msg, int len, int maxlen, qboolean mayAddQuotes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3985 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 0x10(%ebp), %eax\n" /* len */
        /* { scope 1 */
        "movl 0x18(%ebp), %ebx\n" /* line 3991 | mayAddQuotes */
        "testl %ebx, %ebx\n"
        "je .Lf2f8c8_0002f927\n"
        "movl 8(%ebp), %ecx\n" /* line 3993 | add */
        "movzbl (%ecx), %edx\n"
        "testb %dl, %dl\n"
        "jne .Lf2f8c8_0002f91e\n"
        ".Lf2f8c8_0002f8e5:\n"
        "cmpl 0x14(%ebp), %eax\n" /* line 4010 | maxlen */
        "jge .Lf2f8c8_0002f907\n"
        "movl 0xc(%ebp), %edx\n" /* line 4011 | msg */
        "movb $0x22, (%edx, %eax)\n"
        "addl $1, %eax\n"
        "movl $1, -0x10(%ebp)\n" /* addQuotes */
        "cmpl 0x14(%ebp), %eax\n" /* line 4013 | maxlen */
        "jl .Lf2f8c8_0002f933\n"
        ".Lf2f8c8_0002f900:\n"
        "movl -0x10(%ebp), %ecx\n" /* line 4016 | addQuotes */
        "testl %ecx, %ecx\n"
        "je .Lf2f8c8_0002f916\n"
        ".Lf2f8c8_0002f907:\n"
        "cmpl %eax, 0x14(%ebp)\n" /* maxlen */
        "jle .Lf2f8c8_0002f916\n"
        "movl 0xc(%ebp), %esi\n" /* line 4017 | msg */
        "movb $0x22, (%eax, %esi)\n"
        "addl $1, %eax\n"
        /* } scope */
        ".Lf2f8c8_0002f916:\n"
        "addl $8, %esp\n" /* line 4020 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f8c8_0002f91e:\n"
        "movl 0x14(%ebp), %ebx\n" /* line 3999 | maxlen */
        "subl %eax, %ebx\n"
        "testl %ebx, %ebx\n"
        "jg .Lf2f8c8_0002f96e\n"
        ".Lf2f8c8_0002f927:\n"
        "movl $0, -0x10(%ebp)\n" /* line 4011 | addQuotes */
        "cmpl 0x14(%ebp), %eax\n" /* line 4013 | maxlen */
        "jge .Lf2f8c8_0002f900\n"
        ".Lf2f8c8_0002f933:\n"
        "movl 8(%ebp), %ecx\n" /* add */
        "movzbl (%ecx), %edx\n"
        "testb %dl, %dl\n"
        "je .Lf2f8c8_0002f900\n"
        "movl $1, %ecx\n"
        "movl 0xc(%ebp), %ebx\n" /* msg */
        "leal (%ebx, %eax), %edi\n"
        "movl 0x14(%ebp), %esi\n" /* maxlen */
        "subl %eax, %esi\n"
        ".Lf2f8c8_0002f94d:\n"
        "movb %dl, -1(%edi, %ecx)\n" /* line 4014 */
        "leal (%eax, %ecx), %edx\n"
        "movl %edx, -0x14(%ebp)\n"
        "cmpl %esi, %ecx\n" /* line 4013 */
        "je .Lf2f8c8_0002f995\n"
        "movl 8(%ebp), %ebx\n" /* add */
        "movzbl (%ebx, %ecx), %edx\n"
        "addl $1, %ecx\n"
        "testb %dl, %dl\n"
        "jne .Lf2f8c8_0002f94d\n"
        "movl -0x14(%ebp), %eax\n"
        "jmp .Lf2f8c8_0002f900\n"
        ".Lf2f8c8_0002f96e:\n"
        "cmpb $0x20, %dl\n" /* line 4001 */
        "jle .Lf2f8c8_0002f8e5\n"
        "xorl %edx, %edx\n"
        ".Lf2f8c8_0002f979:\n"
        "addl $1, %edx\n" /* line 3999 */
        "cmpl %edx, %ebx\n"
        "je .Lf2f8c8_0002f927\n"
        "movl 8(%ebp), %esi\n" /* add */
        "movzbl (%edx, %esi), %ecx\n"
        "testb %cl, %cl\n"
        "je .Lf2f8c8_0002f927\n"
        "cmpb $0x20, %cl\n" /* line 4001 */
        "jg .Lf2f8c8_0002f979\n"
        "jmp .Lf2f8c8_0002f8e5\n"
        ".Lf2f8c8_0002f995:\n"
        "movl %edx, %eax\n"
        "jmp .Lf2f8c8_0002f900\n"
    );
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
__attribute__((naked))
void Com_SetRecommended(qboolean restart)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2365 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1e7c, %esp\n"
        /* { scope 1: dvarNames, dvarValues, best, cur, ... */
        "movl $str_00216378, (%esp)\n" /* line 2373 */
        "calll Com_Printf\n"
        "leal -0x230(%ebp), %eax\n" /* line 2375 | info */
        "movl %eax, (%esp)\n"
        "calll Sys_GetInfo\n"
        "movsd lit8_00307c70, %xmm0\n" /* line 2377 | 1.02 */
        "mulsd -0x230(%ebp), %xmm0\n" /* info */
        "movsd %xmm0, -0x230(%ebp)\n" /* info */
        "movl -0x228(%ebp), %eax\n" /* line 2379 */
        "cmpl $0x7f, %eax\n"
        "jg .Lf2f9ca_0002fd3e\n"
        "movl $0x80, -0x228(%ebp)\n" /* line 2380 */
        "leal -0x20(%ebp), %eax\n" /* line 2385 | csv */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216394, (%esp)\n" /* "configure_mp.csv" */
        "calll FS_ReadFile\n"
        "movl %eax, -0x1e5c(%ebp)\n" /* filesize */
        "testl %eax, %eax\n" /* line 2386 */
        "js .Lf2f9ca_0002fd68\n"
        ".Lf2f9ca_0002fa42:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2389 | csv */
        "movl %eax, -0x1c(%ebp)\n" /* text */
        "movl $str_00216394, (%esp)\n" /* line 2390 */
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 2391 */
        "calll Com_SetCSV\n"
        "xorl %esi, %esi\n" /* dvarCount */
        "movb $0, -0x1e55(%ebp)\n" /* foundMatch */
        "xorl %edi, %edi\n"
        "movsd lit8_00307c78, %xmm0\n" /* -1.0 */
        "movsd %xmm0, -0x1e48(%ebp)\n"
        /* { scope 2: find */
        ".Lf2f9ca_0002fa7b:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2251 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* token */
        "movzbl (%eax), %eax\n" /* line 2254 */
        "testb %al, %al\n"
        "je .Lf2f9ca_0002fb0e\n"
        ".Lf2f9ca_0002fa8f:\n"
        "cmpb $0x23, %al\n"
        "je .Lf2f9ca_0002fb0e\n"
        "movl $str_002163cc, 4(%esp)\n" /* line 2259 */
        "movl %ebx, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2f9ca_0002fbff\n"
        "testl %esi, %esi\n" /* line 2265 | dvarCount */
        "jne .Lf2f9ca_0002fb1e\n"
        "movl $str_002163d0, 4(%esp)\n" /* line 2267 */
        "movl %ebx, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2f9ca_0002fbe6\n"
        ".Lf2f9ca_0002fac7:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2270 | text */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl $str_00216414, 4(%esp)\n" /* line 2271 */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2f9ca_0002fbcd\n"
        ".Lf2f9ca_0002faea:\n"
        "leal -0x1630(%ebp), %edx\n" /* line 2274 | dvarNames */
        "leal -0x1c(%ebp), %eax\n" /* text */
        "calll Com_GetConfigureDvarNames\n"
        "movl %eax, %esi\n" /* dvarCount */
        "leal -0x1c(%ebp), %eax\n" /* line 2251 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* token */
        "movzbl (%eax), %eax\n" /* line 2254 */
        "testb %al, %al\n"
        "jne .Lf2f9ca_0002fa8f\n"
        ".Lf2f9ca_0002fb0e:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 2256 | text */
        "movl %edx, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "jmp .Lf2f9ca_0002fa7b\n"
        ".Lf2f9ca_0002fb1e:\n"
        "movl %ebx, (%esp)\n" /* line 2279 | token */
        "calll atof\n"
        "fstpl -0x1e40(%ebp)\n"
        "movsd -0x1e40(%ebp), %xmm0\n" /* line 2280 */
        "ucomisd lit8_00307c80, %xmm0\n" /* 0.0 */
        "jb .Lf2f9ca_0002ffe6\n"
        ".Lf2f9ca_0002fb42:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2283 | text */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl %eax, (%esp)\n" /* line 2284 */
        "calll atoi\n"
        "movl %eax, %ebx\n" /* token */
        "cmpl $0x7f, %eax\n" /* line 2285 */
        "jle .Lf2f9ca_0002fbb3\n"
        ".Lf2f9ca_0002fb5c:\n"
        "movsd -0x230(%ebp), %xmm0\n" /* line 2289 | info */
        "ucomisd -0x1e40(%ebp), %xmm0\n"
        "jb .Lf2f9ca_0002fba2\n"
        "cmpl -0x228(%ebp), %ebx\n" /* token */
        "jg .Lf2f9ca_0002fba2\n"
        "movsd -0x1e40(%ebp), %xmm0\n" /* line 2291 */
        "ucomisd -0x1e48(%ebp), %xmm0\n"
        "ja .Lf2f9ca_0002fce8\n"
        "movsd -0x1e48(%ebp), %xmm0\n"
        "ucomisd -0x1e40(%ebp), %xmm0\n"
        "je .Lf2f9ca_0002fcd2\n"
        ".Lf2f9ca_0002fba2:\n"
        "xorl %ecx, %ecx\n" /* line 2294 */
        ".Lf2f9ca_0002fba4:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 2299 | text */
        "movl %esi, %eax\n" /* dvarCount */
        "calll Com_GetConfigureDvarValues\n"
        "jmp .Lf2f9ca_0002fa7b\n"
        ".Lf2f9ca_0002fbb3:\n"
        "movl %eax, 8(%esp)\n" /* line 2286 */
        "movl $str_00216498, 4(%esp)\n" /* "configure_mp.csv: sys mb %i not allowed to be less than 128" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002fb5c\n"
        ".Lf2f9ca_0002fbcd:\n"
        "movl $str_0021641c, 4(%esp)\n" /* line 2272 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002faea\n"
        ".Lf2f9ca_0002fbe6:\n"
        "movl $str_002163d8, 4(%esp)\n" /* line 2268 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002fac7\n"
        ".Lf2f9ca_0002fbff:\n"
        "calll Com_UngetToken\n" /* line 2261 */
        "cmpb $0, -0x1e55(%ebp)\n" /* line 2302 | foundMatch */
        "jne .Lf2f9ca_0003000b\n"
        /* } scope */
        "leal -0x230(%ebp), %eax\n" /* line 2395 | info */
        "movl %eax, (%esp)\n"
        "calll Sys_GetInfo\n"
        "movl -0x228(%ebp), %eax\n" /* line 2396 */
        "movl %eax, 0x10(%esp)\n"
        "movsd -0x230(%ebp), %xmm0\n" /* info */
        "movsd %xmm0, 8(%esp)\n"
        "movl $str_0021652c, 4(%esp)\n" /* "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE %.0f GHz %i M" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* { scope 2: find */
        ".Lf2f9ca_0002fc4b:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 2325 | text */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl $str_002163cc, 4(%esp)\n" /* line 2326 */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2f9ca_0002fdf7\n"
        "calll Com_UngetToken\n" /* line 2328 */
        /* } scope */
        ".Lf2f9ca_0002fc73:\n"
        "leal -0x223(%ebp), %eax\n" /* line 2401 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002165cc, 4(%esp)\n" /* "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE "%s"
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf2f9ca_0002fc91:\n"
        "calll Com_EndParseSession\n" /* line 2404 */
        "movl -0x20(%ebp), %ebx\n" /* line 2405 | csv, token */
        /* { scope 2: find */
        "movl -0x1e5c(%ebp), %edi\n" /* line 2040 | filesize */
        "testl %edi, %edi\n"
        "jg .Lf2f9ca_0002fd81\n"
        "xorl %esi, %esi\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 2406 | token */
        "calll FS_FreeFile\n"
        "leal 1(%esi), %eax\n" /* line 2408 | dvarCount */
        "movl %eax, (%esp)\n"
        "calll Sys_ArchiveInfo\n"
        "movl 8(%ebp), %esi\n" /* line 2411 | restart, dvarCount */
        "testl %esi, %esi\n" /* dvarCount */
        "jne .Lf2f9ca_0002fdd3\n"
        /* } scope */
        ".Lf2f9ca_0002fcc7:\n"
        "addl $0x1e7c, %esp\n" /* line 2414 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dvarNames, dvarValues, best, cur, ... */
        /* { scope 2: find */
        ".Lf2f9ca_0002fcd2:\n"
        "jp .Lf2f9ca_0002fba2\n" /* line 2291 */
        "cmpl %ebx, %edi\n" /* token */
        "jge .Lf2f9ca_0002fba2\n"
        "movsd -0x1e40(%ebp), %xmm0\n"
        ".Lf2f9ca_0002fce8:\n"
        "movl %ebx, -0x628(%ebp)\n" /* line 2294 | token */
        "movsd %xmm0, -0x630(%ebp)\n" /* cur */
        "leal -0xe30(%ebp), %edx\n" /* best */
        "leal -0x630(%ebp), %eax\n" /* cur */
        "movl $0x210, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0xe28(%ebp), %edi\n"
        "movsd -0xe30(%ebp), %xmm0\n" /* best */
        "movsd %xmm0, -0x1e48(%ebp)\n"
        "leal -0x1e30(%ebp), %ecx\n" /* dvarValues */
        "movb $1, -0x1e55(%ebp)\n" /* foundMatch */
        "jmp .Lf2f9ca_0002fba4\n"
        /* } scope */
        ".Lf2f9ca_0002fd3e:\n"
        "addl $8, %eax\n" /* line 2382 */
        "movl %eax, -0x228(%ebp)\n"
        "leal -0x20(%ebp), %eax\n" /* line 2385 | csv */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216394, (%esp)\n" /* "configure_mp.csv" */
        "calll FS_ReadFile\n"
        "movl %eax, -0x1e5c(%ebp)\n" /* filesize */
        "testl %eax, %eax\n" /* line 2386 */
        "jns .Lf2f9ca_0002fa42\n"
        ".Lf2f9ca_0002fd68:\n"
        "movl $str_002163a8, 4(%esp)\n" /* line 2387 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002fa42\n"
        /* { scope 2: find */
        ".Lf2f9ca_0002fd81:\n"
        "xorl %ecx, %ecx\n" /* line 2040 */
        "xorl %edx, %edx\n"
        ".Lf2f9ca_0002fd85:\n"
        "movl %edx, %eax\n" /* line 2041 */
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movsbl (%ebx, %ecx), %edx\n"
        "leal (%eax, %edx), %edx\n"
        "addl $1, %ecx\n" /* line 2040 */
        "cmpl %ecx, -0x1e5c(%ebp)\n" /* filesize */
        "jne .Lf2f9ca_0002fd85\n"
        "movl %edx, %esi\n"
        "andl $0xfffffff, %esi\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 2406 | token */
        "calll FS_FreeFile\n"
        "leal 1(%esi), %eax\n" /* line 2408 | dvarCount */
        "movl %eax, (%esp)\n"
        "calll Sys_ArchiveInfo\n"
        "movl 8(%ebp), %esi\n" /* line 2411 | restart, dvarCount */
        "testl %esi, %esi\n" /* dvarCount */
        "je .Lf2f9ca_0002fcc7\n"
        ".Lf2f9ca_0002fdd3:\n"
        "calll Dvar_AnyLatchedValues\n"
        "testb %al, %al\n"
        "je .Lf2f9ca_0002fcc7\n"
        "movl $str_00216604, (%esp)\n" /* line 2412 */
        "calll Cbuf_AddText\n"
        /* } scope */
        "addl $0x1e7c, %esp\n" /* line 2414 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: dvarNames, dvarValues, best, cur, ... */
        /* { scope 2: find */
        ".Lf2f9ca_0002fdf7:\n"
        "leal -0x1630(%ebp), %edx\n" /* line 2331 | dvarNames */
        "leal -0x1c(%ebp), %eax\n" /* text */
        "calll Com_GetConfigureDvarNames\n"
        "movl %eax, -0x1e54(%ebp)\n" /* dvarCount */
        "movb $0, -0x1e4d(%ebp)\n" /* foundMatch */
        ".Lf2f9ca_0002fe12:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2336 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x1e4c(%ebp)\n" /* find */
        "movl -0x1c(%ebp), %edx\n" /* line 2337 | text */
        "testl %edx, %edx\n"
        "je .Lf2f9ca_0002fecb\n"
        ".Lf2f9ca_0002fe2e:\n"
        "movzbl (%eax), %eax\n" /* line 2339 */
        "testb %al, %al\n"
        "je .Lf2f9ca_0002fedd\n"
        "cmpb $0x23, %al\n"
        "je .Lf2f9ca_0002fedd\n"
        "cmpb $0, -0x1e4d(%ebp)\n" /* line 2346 | foundMatch */
        "jne .Lf2f9ca_0002fe9f\n"
        /* { scope 3: wildcardTemplate */
        /* { scope 4 */
        "movb $0x2a, -0x630(%ebp)\n" /* line 2118 | cur */
        "movl -0x1e4c(%ebp), %edx\n" /* line 2120 | find */
        "movzbl (%edx), %eax\n"
        "testb %al, %al\n"
        "jne .Lf2f9ca_0002feed\n"
        "movl $1, %esi\n" /* wildcardLen */
        "xorl %eax, %eax\n"
        ".Lf2f9ca_0002fe69:\n"
        "cmpb $0x2a, -0x630(%ebp, %eax)\n" /* line 2137 */
        "je .Lf2f9ca_0002fe7e\n"
        "movb $0x2a, -0x630(%ebp, %esi)\n" /* line 2139 */
        "addl $1, %esi\n" /* line 2140 | wildcardLen */
        ".Lf2f9ca_0002fe7e:\n"
        "movb $0, -0x630(%ebp, %esi)\n" /* line 2142 */
        "leal -0x223(%ebp), %edx\n" /* line 2144 */
        "leal -0x630(%ebp), %eax\n" /* cur */
        "calll Com_GpuStringCompare\n"
        /* } scope */
        /* } scope */
        "testl %eax, %eax\n" /* line 2346 */
        "je .Lf2f9ca_0002ff99\n"
        ".Lf2f9ca_0002fe9f:\n"
        "xorl %ecx, %ecx\n" /* line 2355 */
        "leal -0x1c(%ebp), %edx\n" /* text */
        "movl -0x1e54(%ebp), %eax\n" /* dvarCount */
        "calll Com_GetConfigureDvarValues\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2336 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x1e4c(%ebp)\n" /* find */
        "movl -0x1c(%ebp), %edx\n" /* line 2337 | text */
        "testl %edx, %edx\n"
        "jne .Lf2f9ca_0002fe2e\n"
        /* } scope */
        ".Lf2f9ca_0002fecb:\n"
        "cmpb $0, -0x1e4d(%ebp)\n" /* line 2399 | foundMatch */
        "jne .Lf2f9ca_0002fc91\n"
        "jmp .Lf2f9ca_0002fc73\n"
        /* { scope 2: find */
        ".Lf2f9ca_0002fedd:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2341 | text */
        "movl %eax, (%esp)\n"
        "calll Com_SkipRestOfLine\n"
        "jmp .Lf2f9ca_0002fe12\n"
        ".Lf2f9ca_0002feed:\n"
        "movl %edx, %ebx\n" /* token */
        "movl %edx, %edi\n"
        /* { scope 3: wildcardTemplate */
        /* { scope 4 */
        "addl $1, %ebx\n" /* line 2120 */
        "movl $1, %esi\n" /* wildcardLen */
        "jmp .Lf2f9ca_0002ff1c\n"
        ".Lf2f9ca_0002fefb:\n"
        "movzbl (%edi), %eax\n" /* line 2131 */
        "movb %al, -0x630(%ebp, %esi)\n"
        "addl $1, %esi\n" /* line 2133 | wildcardLen */
        "cmpl $0x3ff, %esi\n" /* line 2134 | wildcardLen */
        "je .Lf2f9ca_0002ff57\n"
        ".Lf2f9ca_0002ff10:\n"
        "movl %ebx, %edi\n" /* line 2135 */
        "movzbl (%ebx), %eax\n" /* line 2120 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "je .Lf2f9ca_0002ff77\n"
        ".Lf2f9ca_0002ff1c:\n"
        "movsbl %al, %edx\n" /* line 2122 | _c */
        /* { scope 5 */
        "testl $0xffffff80, %edx\n" /* line 220 */
        "jne .Lf2f9ca_0002ff7f\n"
        "movl __DefaultRuneLocale, %eax\n"
        "movl 0x34(%eax, %edx, 4), %eax\n"
        "shrl $0xe, %eax\n"
        "andl $1, %eax\n"
        /* } scope */
        ".Lf2f9ca_0002ff36:\n"
        "testl %eax, %eax\n" /* line 2122 */
        "je .Lf2f9ca_0002fefb\n"
        "cmpb $0x20, -0x631(%ebp, %esi)\n" /* line 2125 */
        "je .Lf2f9ca_0002ff10\n"
        "movb $0x20, -0x630(%ebp, %esi)\n" /* line 2127 */
        "addl $1, %esi\n" /* line 2133 | wildcardLen */
        "cmpl $0x3ff, %esi\n" /* line 2134 | wildcardLen */
        "jne .Lf2f9ca_0002ff10\n"
        ".Lf2f9ca_0002ff57:\n"
        "movl $str_0021656c, 4(%esp)\n" /* line 2135 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "movl %ebx, %edi\n"
        "movzbl (%ebx), %eax\n" /* line 2120 */
        "addl $1, %ebx\n"
        "testb %al, %al\n"
        "jne .Lf2f9ca_0002ff1c\n"
        ".Lf2f9ca_0002ff77:\n"
        "leal -1(%esi), %eax\n" /* wildcardLen */
        "jmp .Lf2f9ca_0002fe69\n"
        /* { scope 5 */
        ".Lf2f9ca_0002ff7f:\n"
        "movl $0x4000, 4(%esp)\n" /* line 220 */
        "movl %edx, (%esp)\n"
        "calll ___maskrune\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf2f9ca_0002ff36\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf2f9ca_0002ff99:\n"
        "movl -0x1e4c(%ebp), %eax\n" /* line 2348 | find */
        "movl %eax, 4(%esp)\n"
        "movl $str_0021659c, (%esp)\n" /* "configure_mp.csv: using GPU configuration "%s"
" */
        "calll Com_Printf\n"
        "leal -0xe30(%ebp), %ecx\n" /* line 2349 | best */
        "leal -0x1c(%ebp), %edx\n" /* text */
        "movl -0x1e54(%ebp), %eax\n" /* dvarCount */
        "calll Com_GetConfigureDvarValues\n"
        "leal -0xe30(%ebp), %ecx\n" /* line 2350 | best */
        "leal -0x1630(%ebp), %edx\n" /* dvarNames */
        "movl -0x1e54(%ebp), %eax\n" /* dvarCount */
        "calll Com_SetConfigureDvars\n"
        "movb $1, -0x1e4d(%ebp)\n" /* foundMatch */
        "jmp .Lf2f9ca_0002fe12\n"
        /* } scope */
        /* { scope 2: find */
        ".Lf2f9ca_0002ffe6:\n"
        "jp .Lf2f9ca_0002fb42\n" /* line 2280 */
        "movsd %xmm0, 8(%esp)\n" /* line 2281 */
        "movl $str_00216458, 4(%esp)\n" /* "configure_mp.csv: cpu ghz %g not allowed to be less than 0
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002fb42\n"
        ".Lf2f9ca_0003000b:\n"
        "movl %edi, 0xc(%esp)\n" /* line 2305 */
        "movsd -0x1e48(%ebp), %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $str_002164d8, (%esp)\n" /* "configure_mp.csv: using CPU configuration %.0f GHz %i MB
" */
        "calll Com_Printf\n"
        "movl $str_00216514, (%esp)\n" /* line 2307 */
        "calll Cbuf_AddText\n"
        "calll Cbuf_Execute\n" /* line 2308 */
        "leal -0x1e30(%ebp), %ecx\n" /* line 2310 | dvarValues */
        "leal -0x1630(%ebp), %edx\n" /* dvarNames */
        "movl %esi, %eax\n" /* dvarCount */
        "calll Com_SetConfigureDvars\n"
        "jmp .Lf2f9ca_0002fc4b\n"
    );
}

/* line 2417 */
__attribute__((naked))
void Com_CheckSetRecommended(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2417 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl com_recommendedSet, %eax\n" /* line 2419 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf30052_000300d4\n"
        "leal -0xc(%ebp), %eax\n" /* line 2055 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00216394, (%esp)\n" /* "configure_mp.csv" */
        "calll FS_ReadFile\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 2056 */
        "js .Lf30052_0003012c\n"
        ".Lf30052_00030082:\n"
        "movl -0xc(%ebp), %esi\n" /* line 2058 */
        "testl %ebx, %ebx\n" /* line 2040 */
        "jle .Lf30052_00030111\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        ".Lf30052_00030091:\n"
        "movl %edx, %eax\n" /* line 2041 */
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "movsbl (%esi, %ecx), %edx\n"
        "leal (%eax, %edx), %edx\n"
        "addl $1, %ecx\n" /* line 2040 */
        "cmpl %ecx, %ebx\n"
        "jne .Lf30052_00030091\n"
        "movl %edx, %ebx\n"
        "andl $0xfffffff, %ebx\n"
        "movl %esi, (%esp)\n" /* line 2059 */
        "calll FS_FreeFile\n"
        "leal 1(%ebx), %eax\n" /* line 2061 */
        "movl %eax, (%esp)\n"
        "calll Sys_HasConfigureChecksumChanged\n"
        "testb %al, %al\n" /* line 2419 */
        "je .Lf30052_000300f5\n"
        ".Lf30052_000300d4:\n"
        "movl $0, (%esp)\n" /* line 2421 */
        "calll Com_SetRecommended\n"
        "movl $1, 4(%esp)\n" /* line 2422 */
        "movl com_recommendedSet, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        ".Lf30052_000300f5:\n"
        "calll Sys_HasInfoChanged\n" /* line 2425 */
        "testb %al, %al\n"
        "je .Lf30052_0003010a\n"
        "movl $0, (%esp)\n" /* line 2426 */
        "calll Com_SetRecommended\n"
        ".Lf30052_0003010a:\n"
        "addl $0x20, %esp\n" /* line 2427 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf30052_00030111:\n"
        "xorl %ebx, %ebx\n" /* line 2040 */
        "movl %esi, (%esp)\n" /* line 2059 */
        "calll FS_FreeFile\n"
        "leal 1(%ebx), %eax\n" /* line 2061 */
        "movl %eax, (%esp)\n"
        "calll Sys_HasConfigureChecksumChanged\n"
        "testb %al, %al\n" /* line 2419 */
        "je .Lf30052_000300f5\n"
        "jmp .Lf30052_000300d4\n"
        ".Lf30052_0003012c:\n"
        "movl $str_002163a8, 4(%esp)\n" /* line 2057 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf30052_00030082\n"
    );
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
static __attribute__((naked))
void Com_ErrorCleanup(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 691 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x1014, %esp\n"
        /* { scope 1 */
        "calll LargeLocalReset\n" /* line 700 */
        "movl imp_re, %eax\n" /* line 706 */
        "movl 0x14c(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf303e6_00030406\n"
        "calll *%eax\n" /* line 707 */
        ".Lf303e6_00030406:\n"
        "movl $0, (%esp)\n" /* line 710 */
        "calll Dvar_SetInAutoExec\n"
        "calll Hunk_ClearTempMemory\n" /* line 582 */
        "calll Hunk_ClearTempMemoryHigh\n" /* line 583 */
        "calll Com_IsMapProfilerActive\n" /* line 718 */
        "movl $0, 4(%esp)\n" /* line 725 */
        "movl $str_0021663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "movl $str_002157b8, 4(%esp)\n" /* line 733 */
        "movl $str_002157b8, (%esp)\n"
        "calll FS_PureServerSetLoadedIwds\n"
        "calll SEH_UpdateLanguageInfo\n" /* line 739 */
        "movl $com_errorMessage, 4(%esp)\n" /* line 744 */
        "leal -0x1008(%ebp), %ebx\n" /* szUnlocedMsg */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cmpl $3, errorcode\n" /* line 746 */
        "je .Lf303e6_0003061d\n"
        "movl imp_cls, %eax\n" /* line 753 */
        "movl 0x110(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf303e6_0003060c\n"
        ".Lf303e6_00030484:\n"
        "movl $com_errorMessage, (%esp)\n" /* line 756 */
        "calll Com_SetErrorMessage\n"
        ".Lf303e6_0003048e:\n"
        "cmpl $3, errorcode\n" /* line 776 */
        "je .Lf303e6_0003049c\n"
        "calll Scr_Abort\n" /* line 777 */
        ".Lf303e6_0003049c:\n"
        "calll SND_ErrorCleanup\n" /* line 780 */
        "calll Com_CleanupBsp\n" /* line 784 */
        "calll CM_Cleanup\n" /* line 785 */
        "calll Com_ResetParseSessions\n" /* line 789 */
        "movl $1, (%esp)\n" /* line 792 */
        "calll CL_FlushDebugData\n"
        "movl imp_re, %eax\n" /* line 795 */
        "movl 0xe4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf303e6_000304cd\n"
        "calll *%eax\n" /* line 796 */
        ".Lf303e6_000304cd:\n"
        "calll FS_ResetFiles\n" /* line 803 */
        "cmpl $1, errorcode\n" /* line 805 */
        "je .Lf303e6_000306ac\n"
        ".Lf303e6_000304df:\n"
        "calll Sys_Milliseconds\n" /* line 809 */
        "movl %eax, %edx\n"
        "subl lastErrorTime, %eax\n" /* line 810 */
        "cmpl $0x63, %eax\n"
        "jg .Lf303e6_0003058a\n"
        "movl errorCount, %eax\n" /* line 812 */
        "addl $1, %eax\n"
        "movl %eax, errorCount\n"
        "cmpl $3, %eax\n"
        "jg .Lf303e6_000305fd\n"
        ".Lf303e6_0003050b:\n"
        "movl %edx, lastErrorTime\n" /* line 821 */
        "movl errorcode, %eax\n" /* line 823 */
        "subl $1, %eax\n"
        "cmpl $2, %eax\n"
        "ja .Lf303e6_000305ab\n"
        ".Lf303e6_00030522:\n"
        "movl imp_updateScreenCalled, %eax\n" /* line 828 */
        "movb $0, (%eax)\n"
        "cmpl $2, errorcode\n" /* line 832 */
        "je .Lf303e6_000305d4\n"
        ".Lf303e6_00030537:\n"
        "movl $com_errorMessage, 4(%esp)\n" /* line 840 */
        "movl $str_0021666c, (%esp)\n" /* "********************
ERROR: %s
********************
" */
        "calll Com_Printf\n"
        "cmpl $1, errorcode\n" /* line 843 */
        "je .Lf303e6_0003066b\n"
        ".Lf303e6_00030558:\n"
        "movl %ebx, (%esp)\n" /* line 850 */
        "calll Com_ShutdownInternal\n"
        "cmpl $1, errorcode\n" /* line 852 */
        "je .Lf303e6_00030695\n"
        ".Lf303e6_0003056d:\n"
        "movl $0, com_fixedConsolePosition\n" /* line 870 */
        "movl $0, com_errorEntered\n" /* line 876 */
        /* } scope */
        "addl $0x1014, %esp\n" /* line 877 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf303e6_0003058a:\n"
        "movl $0, errorCount\n" /* line 819 */
        "movl %edx, lastErrorTime\n" /* line 821 */
        "movl errorcode, %eax\n" /* line 823 */
        "subl $1, %eax\n"
        "cmpl $2, %eax\n"
        "jbe .Lf303e6_00030522\n"
        ".Lf303e6_000305ab:\n"
        "movl $com_errorMessage, 4(%esp)\n" /* line 824 */
        "movl $str_00216058, (%esp)\n" /* "%s" */
        "calll Sys_Error\n"
        "movl imp_updateScreenCalled, %eax\n" /* line 828 */
        "movb $0, (%eax)\n"
        "cmpl $2, errorcode\n" /* line 832 */
        "jne .Lf303e6_00030537\n"
        ".Lf303e6_000305d4:\n"
        "movl $str_00216648, (%esp)\n" /* line 834 */
        "calll Com_ShutdownInternal\n"
        "movl $0, com_fixedConsolePosition\n" /* line 870 */
        "movl $0, com_errorEntered\n" /* line 876 */
        /* } scope */
        "addl $0x1014, %esp\n" /* line 877 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf303e6_000305fd:\n"
        "movl $0, errorcode\n" /* line 814 */
        "jmp .Lf303e6_0003050b\n"
        ".Lf303e6_0003060c:\n"
        "movl $0, (%esp)\n" /* line 754 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lf303e6_00030484\n"
        ".Lf303e6_0003061d:\n"
        "cmpb $0, com_errorMessage\n" /* line 759 */
        "je .Lf303e6_0003048e\n"
        /* { scope 2 */
        "movl $1, 8(%esp)\n" /* line 763 */
        "movl $str_00216080, 4(%esp)\n" /* "error message" */
        "movl $com_errorMessage, (%esp)\n"
        "calll SEH_LocalizeTextMessage\n"
        "testl %eax, %eax\n" /* line 764 */
        "je .Lf303e6_0003048e\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 765 */
        "movl %eax, 4(%esp)\n"
        "movl $com_errorMessage, (%esp)\n"
        "calll I_strncpyz\n"
        "jmp .Lf303e6_0003048e\n"
        /* } scope */
        ".Lf303e6_0003066b:\n"
        "movl imp_cls, %eax\n" /* line 845 */
        "movl 0x110(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf303e6_00030558\n"
        "movl com_fixedConsolePosition, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf303e6_00030558\n"
        "calll CL_ConsoleFixPosition\n" /* line 846 */
        "jmp .Lf303e6_00030558\n"
        ".Lf303e6_00030695:\n"
        "calll QuitOnError\n" /* line 854 */
        "testb %al, %al\n"
        "je .Lf303e6_0003056d\n"
        "calll Com_Quit_f\n" /* line 855 */
        "jmp .Lf303e6_0003056d\n"
        ".Lf303e6_000306ac:\n"
        "calll Cbuf_Init\n" /* line 806 */
        "jmp .Lf303e6_000304df\n"
    );
}

/* line 2608 */
__attribute__((naked))
void Com_ExecStartupConfigs(const char *configFile)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2608 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* configFile */
        "movl $str_002166a4, (%esp)\n" /* line 2610 */
        "calll Cbuf_AddText\n"
        "movl $str_002166bc, (%esp)\n" /* line 2611 */
        "calll Cbuf_AddText\n"
        "testl %ebx, %ebx\n" /* line 2612 | configFile */
        "je .Lf306b6_000306f4\n"
        "movl %ebx, 4(%esp)\n" /* line 2613 | configFile */
        "movl $str_002166d0, (%esp)\n" /* "exec %s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        ".Lf306b6_000306f4:\n"
        "calll Cbuf_Execute\n" /* line 2614 */
        "movl $1, (%esp)\n" /* line 2593 */
        "calll Dvar_SetInAutoExec\n"
        "calll Cbuf_Execute\n" /* line 2603 */
        "movl $0, (%esp)\n" /* line 2604 */
        "calll Dvar_SetInAutoExec\n"
        "calll Com_SafeMode\n" /* line 2618 */
        "testl %eax, %eax\n"
        "je .Lf306b6_0003072b\n"
        "movl $str_002166dc, (%esp)\n" /* line 2619 */
        "calll Cbuf_AddText\n"
        ".Lf306b6_0003072b:\n"
        "addl $0x14, %esp\n" /* line 2622 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp Cbuf_Execute\n" /* line 2621 */
    );
}

/* line 1497 */
__attribute__((naked))
int Com_EventLoop(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1497 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        /* { scope 1 */
        "movl $0x4000, 4(%esp)\n" /* line 1508 */
        "leal -0x1c(%ebp), %eax\n" /* bufData_large_local */
        "movl %eax, (%esp)\n"
        "calll LargeLocal_LargeLocal\n"
        "leal -0x1c(%ebp), %edx\n" /* bufData_large_local */
        "movl %edx, (%esp)\n"
        "calll LargeLocal_GetBuf\n"
        "movl $0x4000, 8(%esp)\n" /* line 1510 */
        "movl %eax, 4(%esp)\n"
        "leal -0x88(%ebp), %ecx\n" /* buf */
        "movl %ecx, (%esp)\n"
        "calll MSG_Init\n"
        ".Lf30736_0003077a:\n"
        "movl com_pushedEventsTail, %edx\n" /* line 1481 */
        "cmpl %edx, com_pushedEventsHead\n"
        "jle .Lf30736_000308b3\n"
        ".Lf30736_0003078c:\n"
        "leal 1(%edx), %eax\n" /* line 1483 */
        "movl %eax, com_pushedEventsTail\n"
        "movzbl %dl, %eax\n" /* line 1484 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl com_pushedEvents+20(%eax), %ebx\n"
        "movl %ebx, -0xac(%ebp)\n"
        "movl com_pushedEvents+16(%eax), %edx\n"
        "movl com_pushedEvents+12(%eax), %ecx\n"
        "movl com_pushedEvents+8(%eax), %ebx\n"
        "movl com_pushedEvents+4(%eax), %esi\n"
        "movl com_pushedEvents(%eax), %edi\n"
        "cmpl $5, %esi\n" /* line 1516 */
        "ja .Lf30736_00030909\n"
        ".Lf30736_000307d0:\n"
        "jmpl *.Ljt_30736_0(, %esi, 4)\n"
        ".Lf30736_000307d7:\n"
        "leal -0x58(%ebp), %ebx\n" /* evFrom */
        "jmp .Lf30736_0003080c\n"
        ".Lf30736_000307dc:\n"
        "movl -0x58(%ebp), %ecx\n" /* line 1539 | evFrom */
        "movl %ecx, -0x40(%ebp)\n"
        "movl -0x54(%ebp), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %edi, 0x10(%esp)\n"
        "leal -0x88(%ebp), %esi\n" /* buf */
        "movl %esi, 0xc(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_PacketEvent\n"
        ".Lf30736_0003080c:\n"
        "leal -0x88(%ebp), %eax\n" /* line 1538 | buf */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll NET_GetLoopPacket\n"
        "testl %eax, %eax\n"
        "jne .Lf30736_000307dc\n"
        ".Lf30736_0003082a:\n"
        "leal -0x88(%ebp), %eax\n" /* line 1549 | buf */
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll NET_GetLoopPacket\n"
        "testl %eax, %eax\n"
        "je .Lf30736_000309a7\n"
        "movl $0, (%esp)\n" /* line 1551 */
        "calll CL_SwitchToLocalClient\n"
        "movl com_sv_running, %eax\n" /* line 1554 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf30736_0003082a\n"
        "movl -0x58(%ebp), %ecx\n" /* line 1555 | evFrom */
        "movl %ecx, -0x34(%ebp)\n"
        "movl -0x54(%ebp), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "leal -0x88(%ebp), %esi\n" /* buf */
        "movl %esi, 0xc(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll SV_PacketEvent\n"
        "jmp .Lf30736_0003082a\n"
        ".Lf30736_00030891:\n"
        "movl %edi, 8(%esp)\n" /* line 1594 */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_KeyEvent\n"
        "movl com_pushedEventsTail, %edx\n" /* line 1481 */
        "cmpl %edx, com_pushedEventsHead\n"
        "jg .Lf30736_0003078c\n"
        ".Lf30736_000308b3:\n"
        "leal -0xa8(%ebp), %eax\n" /* line 1486 */
        "movl %eax, (%esp)\n"
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0xa8(%ebp), %edi\n"
        "movl %edi, -0x70(%ebp)\n"
        "movl -0xa4(%ebp), %esi\n"
        "movl %esi, -0x6c(%ebp)\n"
        "movl -0xa0(%ebp), %ebx\n"
        "movl %ebx, -0x68(%ebp)\n"
        "movl -0x9c(%ebp), %ecx\n"
        "movl %ecx, -0x64(%ebp)\n"
        "movl -0x98(%ebp), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, -0xac(%ebp)\n"
        "cmpl $5, %esi\n" /* line 1516 */
        "jbe .Lf30736_000307d0\n"
        ".Lf30736_00030909:\n"
        "movl %esi, 8(%esp)\n" /* line 1520 */
        "movl $str_002166f4, 4(%esp)\n" /* "Com_EventLoop: bad event type %i" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf30736_0003077a\n"
        ".Lf30736_00030926:\n"
        "movl %ebx, (%esp)\n" /* line 1606 */
        "calll CL_CharEvent\n"
        "jmp .Lf30736_0003077a\n"
        ".Lf30736_00030933:\n"
        "movl $0, (%esp)\n" /* line 1641 */
        "calll CL_SwitchToLocalClient\n"
        "movl -0xac(%ebp), %edx\n" /* line 1644 */
        "movl %edx, (%esp)\n"
        "calll Cbuf_AddText\n"
        "movl -0xac(%ebp), %ecx\n" /* line 1645 */
        "movl %ecx, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $str_002160e8, (%esp)\n" /* line 1646 */
        "calll Cbuf_AddText\n"
        "jmp .Lf30736_0003077a\n"
        ".Lf30736_0003096c:\n"
        "movl -0xac(%ebp), %ebx\n" /* line 1652 */
        "movl (%ebx), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* evFrom */
        "movl 4(%ebx), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "subl $0xc, %edx\n" /* line 1653 */
        "movl %edx, -0x7c(%ebp)\n"
        "cmpl -0x80(%ebp), %edx\n" /* line 1659 */
        "jbe .Lf30736_000309bc\n"
        "movl %ebx, (%esp)\n" /* line 1661 */
        "calll Z_FreeInternal\n"
        "movl $str_00216718, (%esp)\n" /* line 1662 */
        "calll Com_Printf\n"
        "jmp .Lf30736_0003077a\n"
        ".Lf30736_000309a7:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1705 | bufData_large_local */
        "movl %edx, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 1706 */
        "leal -0xc(%ebp), %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf30736_000309bc:\n"
        "movl %ebx, %eax\n"
        /* { scope 1 */
        "addl $0xc, %eax\n" /* line 1666 */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0xac(%ebp), %esi\n" /* line 1667 */
        "movl %esi, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl com_sv_running, %eax\n" /* line 1668 */
        "cmpb $0, 8(%eax)\n"
        "jne .Lf30736_00030a31\n"
        "movl $0, (%esp)\n" /* line 1696 */
        "calll CL_SwitchToLocalClient\n"
        "movl -0x58(%ebp), %ecx\n" /* line 1697 | evFrom */
        "movl %ecx, -0x4c(%ebp)\n"
        "movl -0x54(%ebp), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl %edi, 0x10(%esp)\n"
        "leal -0x88(%ebp), %esi\n" /* buf */
        "movl %esi, 0xc(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll CL_PacketEvent\n"
        "jmp .Lf30736_0003077a\n"
        ".Lf30736_00030a31:\n"
        "movl $0, (%esp)\n" /* line 1670 */
        "calll CL_SwitchToLocalClient\n"
        "movl -0x58(%ebp), %ecx\n" /* line 1672 | evFrom */
        "movl %ecx, -0x28(%ebp)\n"
        "movl -0x54(%ebp), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "leal -0x88(%ebp), %ebx\n" /* buf */
        "movl %ebx, 0xc(%esp)\n"
        "movl %ecx, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "calll SV_PacketEvent\n"
        "jmp .Lf30736_0003077a\n"
        "movl %eax, %ebx\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1705 | bufData_large_local */
        "movl %eax, (%esp)\n"
        "calll ZN10LargeLocalD1Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_30736_0:\n"
        ".long .Lf30736_000307d7\n"
        ".long .Lf30736_00030891\n"
        ".long .Lf30736_00030926\n"
        ".long .Lf30736_0003077a\n"
        ".long .Lf30736_00030933\n"
        ".long .Lf30736_0003096c\n"
        ".text\n"
    );
}

/* line 1716 */
__attribute__((naked))
qboolean Debug_EventLoop(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1716 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl $0, -0x5c(%ebp)\n" /* newEvent */
        /* { scope 1 */
        "movl com_pushedEventsTail, %edx\n" /* line 1481 */
        "cmpl %edx, com_pushedEventsHead\n"
        "jle .Lf30a84_00030b0e\n"
        ".Lf30a84_00030aa2:\n"
        "leal 1(%edx), %eax\n" /* line 1483 */
        "movl %eax, com_pushedEventsTail\n"
        "movzbl %dl, %eax\n" /* line 1484 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl com_pushedEvents+20(%eax), %edi\n"
        "movl com_pushedEvents+12(%eax), %edx\n"
        "movl com_pushedEvents+8(%eax), %ecx\n"
        "movl com_pushedEvents+4(%eax), %ebx\n"
        "movl com_pushedEvents(%eax), %eax\n"
        "cmpl $5, %ebx\n" /* line 1727 */
        "ja .Lf30a84_00030b49\n"
        ".Lf30a84_00030ad6:\n"
        "jmpl *.Ljt_30a84_0(, %ebx, 4)\n"
        ".Lf30a84_00030add:\n"
        "movl %edi, (%esp)\n" /* line 1764 */
        "calll Cbuf_AddText\n"
        "movl %edi, (%esp)\n" /* line 1765 */
        "calll Z_FreeInternal\n"
        "movl $str_002160e8, (%esp)\n" /* line 1766 */
        "calll Cbuf_AddText\n"
        /* } scope */
        ".Lf30a84_00030af9:\n"
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        /* { scope 1 */
        ".Lf30a84_00030b00:\n"
        "movl com_pushedEventsTail, %edx\n" /* line 1481 */
        "cmpl %edx, com_pushedEventsHead\n"
        "jg .Lf30a84_00030aa2\n"
        ".Lf30a84_00030b0e:\n"
        "leal -0x58(%ebp), %eax\n" /* line 1486 */
        "movl %eax, (%esp)\n"
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x58(%ebp), %esi\n"
        "movl %esi, -0x30(%ebp)\n"
        "movl -0x54(%ebp), %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n"
        "movl -0x50(%ebp), %ecx\n"
        "movl %ecx, -0x28(%ebp)\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %edi\n"
        "movl %esi, %eax\n"
        "cmpl $5, %ebx\n" /* line 1727 */
        "jbe .Lf30a84_00030ad6\n"
        ".Lf30a84_00030b49:\n"
        "movl %ebx, 8(%esp)\n" /* line 1731 */
        "movl $str_002166f4, 4(%esp)\n" /* "Com_EventLoop: bad event type %i" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        /* { scope 1 */
        ".Lf30a84_00030b6a:\n"
        "movl %edi, (%esp)\n" /* line 1772 */
        "calll Z_FreeInternal\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        ".Lf30a84_00030b7b:\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1779 | newEvent */
        "leal -0xc(%ebp), %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf30a84_00030b86:\n"
        "movl %eax, 8(%esp)\n" /* line 1744 */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll CL_KeyEvent\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        /* { scope 1 */
        ".Lf30a84_00030ba2:\n"
        "movl %ecx, (%esp)\n" /* line 1750 */
        "calll CL_CharEvent\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        ".section .rodata\n"
        ".balign 4\n"
        ".Ljt_30a84_0:\n"
        ".long .Lf30a84_00030b7b\n"
        ".long .Lf30a84_00030b86\n"
        ".long .Lf30a84_00030ba2\n"
        ".long .Lf30a84_00030af9\n"
        ".long .Lf30a84_00030add\n"
        ".long .Lf30a84_00030b6a\n"
        ".text\n"
    );
}

void Com_Frame_Try_Block_Function(void)
{
    int msec, rawMsec, minMsec, maxMsec;
    qboolean useTimescale;

    /* Write player profile if dvar flags changed */
    if (com_fullyInitialized && (*dvar_modifiedFlags & 1)) {
        *dvar_modifiedFlags &= ~1;
        if (Com_HasPlayerProfile()) {
            char path[64];
            Com_BuildPlayerProfilePath(path, 64, "");
            Com_WriteConfigToFile(path);
        }
    }

    /* Handle viewlog changes */
    if (com_viewlog->modified) {
        if (!(*com_dedicated)->current.integer) {
            Sys_ShowConsole(com_viewlog->current.integer, 0);
        }
        Dvar_ClearModified(com_viewlog);
    }

    SetAnimCheck(com_animCheck->current.enabled);

    /* Calculate minimum frame time from maxfps */
    if (com_maxfps->current.integer > 0 && !(*com_dedicated)->current.integer) {
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
    if ((*com_dedicated)->current.integer) {
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
    if (!((*com_dedicated)->flags & 0x40)) {
        if ((*com_dedicated)->latched.integer != (*com_dedicated)->current.integer) {
            *com_dedicated = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1020);
            if ((*com_dedicated)->current.integer) {
                *com_dedicated = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1040);
            }
            Dvar_ClearModified(*com_dedicated);
            CL_SwitchToLocalClient(0);
            CL_Shutdown();
            CL_SwitchToLocalClient(0);
            Sys_ShowConsole(1, 1);
            Sys_NormalExit();
            SV_AddDedicatedCommands();
        }
    }

    /* If dedicated, skip client frame */
    if ((*com_dedicated)->current.integer)
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

    if (*com_dedicated && !(*com_dedicated)->current.integer) {
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
__attribute__((naked))
void Com_PumpMessageLoop(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1812 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "leal -0x58(%ebp), %edi\n"
        "jmp .Lf312a4_00031306\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf312a4_000312b2:\n"
        "movl printedWarning, %eax\n" /* line 1433 */
        "testl %eax, %eax\n"
        "je .Lf312a4_0003136e\n"
        ".Lf312a4_000312bf:\n"
        "movl 0x14(%ebx), %eax\n" /* line 1439 | ev */
        "testl %eax, %eax\n"
        "je .Lf312a4_000312ce\n"
        "movl %eax, (%esp)\n" /* line 1441 */
        "calll Z_FreeInternal\n"
        ".Lf312a4_000312ce:\n"
        "addl $1, com_pushedEventsTail\n" /* line 1443 */
        "movl com_pushedEventsHead, %edx\n"
        ".Lf312a4_000312db:\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 1450 */
        "movl -0x30(%ebp), %eax\n" /* ev */
        "movl %eax, (%ebx)\n" /* ev */
        "movl %esi, 4(%ebx)\n" /* ev */
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n" /* ev */
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* ev */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n" /* ev */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n" /* ev */
        "leal 1(%edx), %eax\n" /* line 1451 */
        "movl %eax, com_pushedEventsHead\n"
        /* } scope */
        ".Lf312a4_00031306:\n"
        "movl %edi, (%esp)\n" /* line 1819 */
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n" /* ev */
        "movl -0x54(%ebp), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %esi, %esi\n" /* line 1820 */
        "je .Lf312a4_00031389\n"
        /* { scope 2 */
        "movl com_pushedEventsHead, %edx\n" /* line 1427 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal com_pushedEvents(, %eax, 8), %ebx\n" /* ev */
        "movl %edx, %eax\n" /* line 1429 */
        "subl com_pushedEventsTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lf312a4_000312b2\n"
        "movl $0, printedWarning\n" /* line 1447 */
        "jmp .Lf312a4_000312db\n"
        ".Lf312a4_0003136e:\n"
        "movl $1, printedWarning\n" /* line 1435 */
        "movl $str_002160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf312a4_000312bf\n"
        /* } scope */
        /* } scope */
        ".Lf312a4_00031389:\n"
        "leal -0xc(%ebp), %esp\n" /* line 1824 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1858 */
static __attribute__((naked))
void Com_Freeze_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1858 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 1863 */
        "cmpl $2, %eax\n"
        "je .Lf31392_000313bc\n"
        "movl $str_002167a8, (%esp)\n" /* line 1865 */
        "calll Com_Printf\n"
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 1880 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf31392_000313bc:\n"
        "movl $1, (%esp)\n" /* line 1868 */
        "calll Cmd_Argv\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x88(%ebp)\n"
        "cvtsd2ss -0x88(%ebp), %xmm0\n"
        "movss %xmm0, -0x7c(%ebp)\n" /* s */
        "leal -0x58(%ebp), %edi\n"
        "jmp .Lf31392_00031424\n"
        ".Lf31392_000313e8:\n"
        "movl $0, printedWarning\n" /* line 1447 */
        ".Lf31392_000313f2:\n"
        "movl -0x8c(%ebp), %eax\n" /* line 1450 */
        "movl %eax, -0x30(%ebp)\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl %eax, (%ebx)\n"
        "movl %esi, 4(%ebx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "addl $1, %edx\n" /* line 1451 */
        "movl %edx, com_pushedEventsHead\n"
        ".Lf31392_00031424:\n"
        "movl %edi, (%esp)\n" /* line 1797 */
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, -0x8c(%ebp)\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x54(%ebp), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %esi, %esi\n" /* line 1798 */
        "je .Lf31392_000314c5\n"
        "movl com_pushedEventsHead, %edx\n" /* line 1427 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal com_pushedEvents(, %eax, 8), %ebx\n"
        "movl %edx, %eax\n" /* line 1429 */
        "subl com_pushedEventsTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jle .Lf31392_000313e8\n"
        "movl printedWarning, %eax\n" /* line 1433 */
        "testl %eax, %eax\n"
        "je .Lf31392_000314ad\n"
        ".Lf31392_0003148c:\n"
        "movl 0x14(%ebx), %eax\n" /* line 1439 */
        "testl %eax, %eax\n"
        "je .Lf31392_0003149b\n"
        "movl %eax, (%esp)\n" /* line 1441 */
        "calll Z_FreeInternal\n"
        ".Lf31392_0003149b:\n"
        "addl $1, com_pushedEventsTail\n" /* line 1443 */
        "movl com_pushedEventsHead, %edx\n"
        "jmp .Lf31392_000313f2\n"
        ".Lf31392_000314ad:\n"
        "movl $1, printedWarning\n" /* line 1435 */
        "movl $str_002160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf31392_0003148c\n"
        ".Lf31392_000314c5:\n"
        "cvtss2sd -0x7c(%ebp), %xmm0\n" /* s */
        "movsd %xmm0, -0x98(%ebp)\n"
        ".Lf31392_000314d2:\n"
        "leal -0x78(%ebp), %eax\n" /* line 1797 */
        "movl %eax, (%esp)\n"
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x78(%ebp), %esi\n"
        "movl %esi, -0x30(%ebp)\n"
        "movl -0x74(%ebp), %edi\n"
        "movl %edi, -0x2c(%ebp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %edi, %edi\n" /* line 1798 */
        "je .Lf31392_00031587\n"
        "movl com_pushedEventsHead, %edx\n" /* line 1427 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal com_pushedEvents(, %eax, 8), %ebx\n"
        "movl %edx, %eax\n" /* line 1429 */
        "subl com_pushedEventsTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jle .Lf31392_000315af\n"
        "movl printedWarning, %eax\n" /* line 1433 */
        "testl %eax, %eax\n"
        "je .Lf31392_000315bb\n"
        ".Lf31392_0003153b:\n"
        "movl 0x14(%ebx), %eax\n" /* line 1439 */
        "testl %eax, %eax\n"
        "je .Lf31392_0003154a\n"
        "movl %eax, (%esp)\n" /* line 1441 */
        "calll Z_FreeInternal\n"
        ".Lf31392_0003154a:\n"
        "addl $1, com_pushedEventsTail\n" /* line 1443 */
        "movl com_pushedEventsHead, %edx\n"
        ".Lf31392_00031557:\n"
        "movl %esi, -0x30(%ebp)\n" /* line 1450 */
        "movl %edi, -0x2c(%ebp)\n"
        "movl %esi, (%ebx)\n"
        "movl %edi, 4(%ebx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        "leal 1(%edx), %eax\n" /* line 1451 */
        "movl %eax, com_pushedEventsHead\n"
        "jmp .Lf31392_000314d2\n"
        ".Lf31392_00031587:\n"
        "subl -0x8c(%ebp), %esi\n" /* line 1875 */
        "cvtsi2sdl %esi, %xmm0\n"
        "mulsd lit8_00307c88, %xmm0\n" /* 0.001 */
        "ucomisd -0x98(%ebp), %xmm0\n"
        "jbe .Lf31392_000314d2\n"
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 1880 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf31392_000315af:\n"
        "movl $0, printedWarning\n" /* line 1447 */
        "jmp .Lf31392_00031557\n"
        ".Lf31392_000315bb:\n"
        "movl $1, printedWarning\n" /* line 1435 */
        "movl $str_002160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf31392_0003153b\n"
    );
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
        const dvar_t *ded = Dvar_RegisterInt("dedicated", 0, 0, 2, 0x1020);
        int dedicated_val;
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%ecx\n"
            "movl %1, (%%ecx)\n"
            "movl 8(%1), %%eax\n"
            : "=a"(dedicated_val) : "r"(ded) : "ecx", "memory"
        );
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
        int dedicated_val;
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%eax\n"
            "movl (%%eax), %%eax\n"
            "movl 8(%%eax), %%eax\n"
            : "=a"(dedicated_val) :: "memory"
        );
        if (dedicated_val) {
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
        int dedicated_val;
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%eax\n"
            "movl (%%eax), %%eax\n"
            "movl 8(%%eax), %%eax\n"
            : "=a"(dedicated_val) :: "memory"
        );
        if (dedicated_val) {
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
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%eax\n"
            "movl (%%eax), %%eax\n"
            : "=a"(ded) :: "memory"
        );
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
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%eax\n"
            "movl (%%eax), %%eax\n"
            "movl 8(%%eax), %%eax\n"
            : "=a"(dedicated_val) :: "memory"
        );
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

            __asm__ __volatile__ (
                "movl imp_com_dedicated, %%eax\n"
                "movl (%%eax), %%eax\n"
                "movl 8(%%eax), %%eax\n"
                : "=a"(dedicated_val) :: "memory"
            );
            if (!dedicated_val) {
                Sys_ShowConsole(com_viewlog->current.integer, 0);
            }
        }

        /* Intro cinematic (non-dedicated only) */
        __asm__ __volatile__ (
            "movl imp_com_dedicated, %%eax\n"
            "movl (%%eax), %%eax\n"
            "movl 8(%%eax), %%eax\n"
            : "=a"(dedicated_val) :: "memory"
        );
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

