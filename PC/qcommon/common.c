/* ASM dump from: common.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/common.cpp */

#include "common_types.h"
#include "imports.h"

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
static qboolean opening_qconsole; /* 0x33c118 */
static int printedWarning; /* 0x33c11c */
static int timeClientFrame; /* 0x33c120 */
static int lastErrorTime; /* 0x33c128 */
static int errorCount; /* 0x33c124 */
static errorParm_t errorcode; /* 0x339808 */
static fileHandle_t logfile; /* 0x339804 */
static int com_lastFrameTime; /* 0x33a880 */
static float com_codeTimeScale; /* 0x33a884 */
static qboolean com_fullyInitialized; /* 0x33a888 */
static char com_errorMessage[4096]; /* 0x339880 */
static int com_pushedEventsHead; /* 0x33c104 */
static int com_pushedEventsTail; /* 0x33c100 */
static sysEvent_t com_pushedEvents[256]; /* 0x33a900 */
static qboolean com_safemode; /* 0x33c108 */
static int iWeaponInfoSource; /* 0x339800 */
static char *rd_buffer; /* 0x33c114 */
static int rd_buffersize; /* 0x33c110 */
static void (*rd_flush)(); /* 0x33c10c */
static char * noticeErrors[8]; /* 0x308ba0 */

void Com_BeginRedirect(char *buffer, int buffersize, void (*flush)());
void Com_EndRedirect(void);
void Com_Printf(const char *fmt);
void Com_PrintMessage(print_msg_type_t type, const char *msg);
void Com_DPrintf(const char *fmt);
static void Com_SetErrorMessage(void);
void Com_Error(errorParm_t code, const char *fmt);
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
static void Com_WriteConfigToFile(void);
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
__attribute__((naked))
void Com_BeginRedirect(char *buffer, int buffersize, void (*flush)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 302 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* buffer */
        "movl 0xc(%ebp), %edx\n" /* buffersize */
        "movl 0x10(%ebp), %ecx\n" /* flush */
        "testl %eax, %eax\n" /* line 304 */
        "je .Lf2e920_0002e94c\n"
        "testl %edx, %edx\n"
        "je .Lf2e920_0002e94c\n"
        "testl %ecx, %ecx\n"
        "je .Lf2e920_0002e94c\n"
        "movl %eax, rd_buffer\n" /* line 306 */
        "movl %edx, rd_buffersize\n" /* line 307 */
        "movl %ecx, rd_flush\n" /* line 308 */
        "movb $0, (%eax)\n" /* line 310 */
        ".Lf2e920_0002e94c:\n"
        "popl %ebp\n" /* line 311 */
        "retl\n"
    );
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
__attribute__((naked))
void Com_Printf(const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 481 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x1024, %esp\n"
        /* { scope 1 */
        "leal 0xc(%ebp), %eax\n" /* line 487 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 488 */
        "movl 8(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x100c(%ebp), %ebx\n" /* msg */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movb $0, -0xd(%ebp)\n" /* line 489 */
        "movl %ebx, 4(%esp)\n" /* line 492 */
        "movl $0, (%esp)\n"
        "calll Com_PrintMessage\n"
        /* } scope */
        "addl $0x1024, %esp\n" /* line 493 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 335 */
__attribute__((naked))
void Com_PrintMessage(print_msg_type_t type, const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 335 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* msg */
        /* { scope 1: aclock */
        "movl rd_buffer, %ebx\n" /* line 340 */
        "testl %ebx, %ebx\n"
        "je .Lf2e9d6_0002ea5b\n"
        "cmpl $4, 8(%ebp)\n" /* line 342 | type */
        "je .Lf2e9d6_0002ea34\n"
        "xorl %edx, %edx\n" /* line 349 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "movl %esi, %edi\n" /* msg */
        "movl %edx, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "movl $0xffffffff, %ecx\n"
        "movl %ebx, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x2c(%ebp), %eax\n"
        "leal -2(%ecx, %eax), %ecx\n"
        "movl rd_buffersize, %edx\n"
        "leal -1(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "ja .Lf2e9d6_0002ea3c\n"
        ".Lf2e9d6_0002ea24:\n"
        "movl %esi, 8(%esp)\n" /* line 354 | msg */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll I_strncat\n"
        /* } scope */
        ".Lf2e9d6_0002ea34:\n"
        "addl $0x3c, %esp\n" /* line 468 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: aclock */
        ".Lf2e9d6_0002ea3c:\n"
        "movl %ebx, (%esp)\n" /* line 351 */
        "calll *rd_flush\n"
        "movl rd_buffer, %eax\n" /* line 352 */
        "movb $0, (%eax)\n"
        "movl rd_buffer, %ebx\n"
        "movl rd_buffersize, %edx\n"
        "jmp .Lf2e9d6_0002ea24\n"
        ".Lf2e9d6_0002ea5b:\n"
        "cmpl $4, 8(%ebp)\n" /* line 363 | type */
        "je .Lf2e9d6_0002ea77\n"
        "movl 0x195ec98, %eax\n" /* line 383 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2e9d6_0002ea77\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf2e9d6_0002eb6b\n"
        ".Lf2e9d6_0002ea77:\n"
        "cmpb $0x5e, (%esi)\n" /* line 396 | msg */
        "je .Lf2e9d6_0002eaee\n"
        ".Lf2e9d6_0002ea7c:\n"
        "cmpl $4, 8(%ebp)\n" /* line 399 | type */
        "je .Lf2e9d6_0002ea8a\n"
        "movl %esi, (%esp)\n" /* line 402 | msg */
        "calll Sys_Print\n"
        ".Lf2e9d6_0002ea8a:\n"
        "movl com_logfile, %eax\n" /* line 407 */
        "testl %eax, %eax\n"
        "je .Lf2e9d6_0002ea34\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf2e9d6_0002ea34\n"
        "calll FS_Initialized\n" /* line 414 */
        "testl %eax, %eax\n"
        "je .Lf2e9d6_0002ea34\n"
        "movl logfile, %eax\n" /* line 419 */
        "testl %eax, %eax\n"
        "je .Lf2e9d6_0002eafa\n"
        ".Lf2e9d6_0002eaac:\n"
        "movl %eax, 8(%esp)\n" /* line 452 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* msg */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* msg */
        "calll FS_Write\n"
        "movl com_logfile, %eax\n" /* line 454 */
        "cmpl $1, 8(%eax)\n"
        "jle .Lf2e9d6_0002ea34\n"
        "movl logfile, %eax\n" /* line 458 */
        "movl %eax, (%esp)\n"
        "calll FS_Flush\n"
        "jmp .Lf2e9d6_0002ea34\n"
        ".Lf2e9d6_0002eaee:\n"
        "leal 2(%esi), %eax\n" /* line 397 | msg */
        "cmpb $0, 1(%esi)\n" /* msg */
        "cmovnel %eax, %esi\n" /* msg */
        "jmp .Lf2e9d6_0002ea7c\n"
        ".Lf2e9d6_0002eafa:\n"
        "movl opening_qconsole, %eax\n" /* line 419 */
        "testl %eax, %eax\n"
        "jne .Lf2e9d6_0002ea34\n"
        /* { scope 2 */
        "movl $1, opening_qconsole\n" /* line 424 */
        "leal -0x1c(%ebp), %ebx\n" /* line 426 | aclock, newtime */
        "movl %ebx, (%esp)\n" /* newtime */
        "calll time\n"
        "movl %ebx, (%esp)\n" /* line 427 | newtime */
        "calll localtime\n"
        "movl %eax, %ebx\n" /* newtime */
        "movl $0x216030, (%esp)\n" /* line 444 */
        "calll FS_FOpenTextFileWrite\n"
        "movl %eax, logfile\n"
        "movl %ebx, (%esp)\n" /* line 446 | newtime */
        "calll asctime\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x216040, (%esp)\n" /* "logfile opened on %s
" */
        "calll Com_Printf\n"
        "movl $0, opening_qconsole\n" /* line 447 */
        "movl logfile, %eax\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 450 */
        "jne .Lf2e9d6_0002eaac\n"
        "jmp .Lf2e9d6_0002ea34\n"
        ".Lf2e9d6_0002eb6b:\n"
        "movl $0, 0xc(%esp)\n" /* line 387 */
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* msg */
        "movl 8(%ebp), %ecx\n" /* type */
        "movl %ecx, (%esp)\n"
        "calll CL_ConsolePrint\n"
        "jmp .Lf2e9d6_0002ea77\n"
    );
}

/* line 503 */
__attribute__((naked))
void Com_DPrintf(const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 503 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x1024, %esp\n"
        /* { scope 1 */
        "movl com_developer, %eax\n" /* line 508 */
        "testl %eax, %eax\n"
        "je .Lf2eb90_0002ebaa\n"
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf2eb90_0002ebb3\n"
        /* } scope */
        ".Lf2eb90_0002ebaa:\n"
        "addl $0x1024, %esp\n" /* line 517 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2eb90_0002ebb3:\n"
        "leal 0xc(%ebp), %eax\n" /* line 511 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 512 */
        "movl 8(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x100c(%ebp), %ebx\n" /* msg */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "movb $0, -0xd(%ebp)\n" /* line 513 */
        "movl %ebx, 4(%esp)\n" /* line 516 */
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x1024, %esp\n" /* line 517 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 634 */
static __attribute__((naked))
void Com_SetErrorMessage(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 634 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %esi\n" /* errorMessage */
        /* { scope 1 */
        "movl $0x1040, 8(%esp)\n" /* line 643 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x21605c, (%esp)\n" /* "com_errorMessage" */
        "calll Dvar_RegisterString\n"
        "movl %eax, ui_errorMessage\n"
        "movl $0x1040, 8(%esp)\n" /* line 644 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x216070, (%esp)\n" /* "com_errorTitle" */
        "calll Dvar_RegisterString\n"
        "movl %eax, ui_errorTitle\n"
        "cmpl $2, errorcode\n" /* line 650 */
        "je .Lf2ebfa_0002ed0e\n"
        "movl noticeErrors, %eax\n" /* line 619 */
        "cmpb $0, (%eax)\n"
        "jne .Lf2ebfa_0002ece8\n"
        ".Lf2ebfa_0002ec61:\n"
        "movl $1, 8(%esp)\n" /* line 660 */
        "movl $0x216080, 4(%esp)\n" /* "error message" */
        "movl $0x21609c, (%esp)\n" /* "MENU_ERROR" */
        "calll SEH_LocalizeTextMessage\n"
        "testl %eax, %eax\n" /* line 661 */
        "je .Lf2ebfa_0002ed64\n"
        ".Lf2ebfa_0002ec85:\n"
        "movl %eax, 4(%esp)\n" /* line 662 */
        "movl ui_errorTitle, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        ".Lf2ebfa_0002ec96:\n"
        "movl $1, 8(%esp)\n" /* line 667 */
        "movl $0x216080, 4(%esp)\n" /* "error message" */
        "movl %esi, (%esp)\n" /* errorMessage */
        "calll SEH_LocalizeTextMessage\n"
        "movl %eax, %ebx\n" /* translation */
        "testl %eax, %eax\n" /* line 668 */
        "je .Lf2ebfa_0002ed4c\n"
        "movl %eax, 4(%esp)\n" /* line 670 */
        "movl ui_errorMessage, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 671 */
        "movl %ebx, 4(%esp)\n" /* translation */
        "movl $com_errorMessage, (%esp)\n"
        "calll I_strncpyz\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 678 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2ebfa_0002ece8:\n"
        "movl $noticeErrors, %ebx\n" /* line 619 */
        "jmp .Lf2ebfa_0002ecfe\n"
        ".Lf2ebfa_0002ecef:\n"
        "movl 4(%ebx), %eax\n"
        "addl $4, %ebx\n"
        "cmpb $0, (%eax)\n"
        "je .Lf2ebfa_0002ec61\n"
        ".Lf2ebfa_0002ecfe:\n"
        "movl %esi, 4(%esp)\n" /* line 621 */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2ebfa_0002ecef\n"
        ".Lf2ebfa_0002ed0e:\n"
        "movl $1, 8(%esp)\n" /* line 652 */
        "movl $0x216080, 4(%esp)\n" /* "error message" */
        "movl $0x216090, (%esp)\n" /* "MENU_NOTICE" */
        "calll SEH_LocalizeTextMessage\n"
        "testl %eax, %eax\n" /* line 653 */
        "jne .Lf2ebfa_0002ec85\n"
        "movl $0x216090, 4(%esp)\n" /* line 656 */
        "movl ui_errorTitle, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf2ebfa_0002ec96\n"
        ".Lf2ebfa_0002ed4c:\n"
        "movl %esi, 4(%esp)\n" /* line 675 | errorMessage */
        "movl ui_errorMessage, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 678 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2ebfa_0002ed64:\n"
        "movl $0x21609c, 4(%esp)\n" /* line 664 */
        "movl ui_errorTitle, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "jmp .Lf2ebfa_0002ec96\n"
    );
}

/* line 906 */
__attribute__((naked))
void Com_Error(errorParm_t code, const char *fmt)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 906 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %ebx\n" /* code */
        /* { scope 1 */
        "movl com_errorEntered, %eax\n" /* line 921 */
        "testl %eax, %eax\n"
        "jne .Lf2ed7e_0002ee2a\n"
        ".Lf2ed7e_0002ed95:\n"
        "movl $1, com_errorEntered\n" /* line 923 */
        "leal 0x10(%ebp), %eax\n" /* line 925 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 926 */
        "movl 0xc(%ebp), %eax\n" /* fmt */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "movl $com_errorMessage, (%esp)\n"
        "calll vsnprintf\n"
        "movb $0, 0x33a87f\n" /* line 927 */
        "cmpl $4, %ebx\n" /* line 932 | code */
        "je .Lf2ed7e_0002ee0a\n"
        "cmpl $6, %ebx\n" /* code */
        "je .Lf2ed7e_0002ee0a\n"
        "cmpl $5, %ebx\n" /* line 981 | code */
        "je .Lf2ed7e_0002ee66\n"
        "movl $0, com_fixedConsolePosition\n" /* line 996 */
        ".Lf2ed7e_0002ede8:\n"
        "movl %ebx, errorcode\n" /* line 1000 | code */
        "movl $2, (%esp)\n" /* line 1006 */
        "calll Sys_GetValue\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll longjmp\n"
        ".Lf2ed7e_0002ee0a:\n"
        "movl com_fixedConsolePosition, %eax\n" /* line 935 */
        "testl %eax, %eax\n"
        "je .Lf2ed7e_0002ee7c\n"
        ".Lf2ed7e_0002ee13:\n"
        "movl 0x195ecac, %ebx\n" /* line 946 | code */
        "movl 0x110(%ebx), %eax\n" /* code */
        "testl %eax, %eax\n"
        "jne .Lf2ed7e_0002ee43\n"
        ".Lf2ed7e_0002ee23:\n"
        "movl $1, %ebx\n" /* line 996 | code */
        "jmp .Lf2ed7e_0002ede8\n"
        ".Lf2ed7e_0002ee2a:\n"
        "movl $com_errorMessage, 4(%esp)\n" /* line 922 */
        "movl $0x2160a8, (%esp)\n" /* "recursive error after: %s" */
        "calll Sys_Error\n"
        "jmp .Lf2ed7e_0002ed95\n"
        ".Lf2ed7e_0002ee43:\n"
        "calll UI_AnyFullScreenMenuVisible\n" /* line 946 */
        "testl %eax, %eax\n"
        "je .Lf2ed7e_0002ee8d\n"
        ".Lf2ed7e_0002ee4c:\n"
        "movl 0x110(%ebx), %eax\n" /* line 956 | code */
        "testl %eax, %eax\n"
        "je .Lf2ed7e_0002ee23\n"
        "movl $0, com_errorEntered\n" /* line 958 */
        /* } scope */
        "addl $0x24, %esp\n" /* line 1007 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2ed7e_0002ee66:\n"
        "movl $1, com_fixedConsolePosition\n" /* line 984 */
        "calll CL_ConsoleFixPosition\n" /* line 985 */
        "movb $1, %bl\n" /* code */
        "jmp .Lf2ed7e_0002ede8\n"
        ".Lf2ed7e_0002ee7c:\n"
        "movl $1, com_fixedConsolePosition\n" /* line 937 */
        "calll CL_ConsoleFixPosition\n" /* line 938 */
        "jmp .Lf2ed7e_0002ee13\n"
        ".Lf2ed7e_0002ee8d:\n"
        "movl $com_errorMessage, %eax\n" /* line 948 */
        "calll Com_SetErrorMessage\n"
        "movl $1, (%esp)\n" /* line 952 */
        "calll UI_SetActiveMenu\n"
        "jmp .Lf2ed7e_0002ee4c\n"
    );
}

/* line 1249 */
__attribute__((naked))
qboolean Com_SafeMode(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1249 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl com_numConsoleLines, %eax\n" /* line 1253 */
        "testl %eax, %eax\n"
        "jg .Lf2eea8_0002eec5\n"
        ".Lf2eea8_0002eeb9:\n"
        "movl com_safemode, %eax\n" /* line 1262 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 1263 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2eea8_0002eec5:\n"
        "xorl %esi, %esi\n" /* line 1253 | i */
        "movl $com_consoleLines, %ebx\n"
        "jmp .Lf2eea8_0002eefc\n"
        ".Lf2eea8_0002eece:\n"
        "movl $0, (%esp)\n" /* line 1256 */
        "calll Cmd_Argv\n"
        "movl $0x2160cc, 4(%esp)\n" /* "dvar_restart" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2eea8_0002ef26\n"
        "addl $1, %esi\n" /* line 1253 | i */
        "addl $4, %ebx\n"
        "cmpl com_numConsoleLines, %esi\n" /* i */
        "jge .Lf2eea8_0002eeb9\n"
        ".Lf2eea8_0002eefc:\n"
        "movl (%ebx), %eax\n" /* line 1255 */
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 1256 */
        "calll Cmd_Argv\n"
        "movl $0x2160c4, 4(%esp)\n" /* "safe" */
        "movl %eax, (%esp)\n"
        "calll I_stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2eea8_0002eece\n"
        ".Lf2eea8_0002ef26:\n"
        "movl com_consoleLines(, %esi, 4), %eax\n" /* line 1258 */
        "movb $0, (%eax)\n"
        "movl $1, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1263 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1288 */
__attribute__((naked))
void Com_StartupVariable(const char *match)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1288 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl com_numConsoleLines, %ecx\n" /* line 1292 */
        "testl %ecx, %ecx\n"
        "jg .Lf2ef3c_0002ef55\n"
        /* } scope */
        ".Lf2ef3c_0002ef4e:\n"
        "addl $0x10, %esp\n" /* line 1303 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2ef3c_0002ef55:\n"
        "xorl %esi, %esi\n" /* line 1292 | lineIndex */
        "movl $com_consoleLines, %ebx\n"
        "movl 8(%ebp), %edx\n" /* match */
        "testl %edx, %edx\n"
        "jne .Lf2ef3c_0002ef76\n"
        "jmp .Lf2ef3c_0002f004\n"
        ".Lf2ef3c_0002ef68:\n"
        "addl $1, %esi\n" /* lineIndex */
        "addl $4, %ebx\n"
        "cmpl com_numConsoleLines, %esi\n" /* lineIndex */
        "jge .Lf2ef3c_0002ef4e\n"
        ".Lf2ef3c_0002ef76:\n"
        "movl (%ebx), %eax\n" /* line 1294 */
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "movl $1, (%esp)\n" /* line 1295 */
        "calll Cmd_Argv\n"
        "movl 8(%ebp), %edx\n" /* match */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2ef3c_0002ef68\n"
        "movl $0, (%esp)\n" /* line 1298 */
        "calll Cmd_Argv\n"
        "movl $0x2160dc, 4(%esp)\n" /* "set" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2ef3c_0002f055\n"
        "movl $0, (%esp)\n" /* line 1300 */
        "calll Cmd_Argv\n"
        "movl $0x2160e0, 4(%esp)\n" /* "seta" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2ef3c_0002ef68\n"
        "calll Dvar_SetA_f\n" /* line 1301 */
        "jmp .Lf2ef3c_0002ef68\n"
        ".Lf2ef3c_0002efed:\n"
        "calll Dvar_Set_f\n" /* line 1299 */
        ".Lf2ef3c_0002eff2:\n"
        "addl $1, %esi\n" /* line 1292 | lineIndex */
        "addl $4, %ebx\n"
        "cmpl com_numConsoleLines, %esi\n" /* lineIndex */
        "jge .Lf2ef3c_0002ef4e\n"
        ".Lf2ef3c_0002f004:\n"
        "movl (%ebx), %eax\n" /* line 1294 */
        "movl %eax, (%esp)\n"
        "calll Cmd_TokenizeString\n"
        "movl $0, (%esp)\n" /* line 1298 */
        "calll Cmd_Argv\n"
        "movl $0x2160dc, 4(%esp)\n" /* "set" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2ef3c_0002efed\n"
        "movl $0, (%esp)\n" /* line 1300 */
        "calll Cmd_Argv\n"
        "movl $0x2160e0, 4(%esp)\n" /* "seta" */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2ef3c_0002eff2\n"
        "calll Dvar_SetA_f\n" /* line 1301 */
        "jmp .Lf2ef3c_0002eff2\n"
        ".Lf2ef3c_0002f055:\n"
        "calll Dvar_Set_f\n" /* line 1299 */
        "jmp .Lf2ef3c_0002ef68\n"
    );
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
        "movl $0x216058, (%esp)\n" /* "%s" */
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
        "movl $0x215bbc, (%esp)\n" /* "%s
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
        "movl $0x215bbc, (%esp)\n" /* "%s
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
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll Com_Printf\n"
        "cmpb $0, (%ebx)\n" /* line 1372 | s */
        "jne .Lf2f060_0002f0d4\n"
        ".Lf2f060_0002f1ba:\n"
        "movl $0x2160ec, (%esp)\n" /* line 1374 */
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
__attribute__((naked))
void Com_ShutdownEvents(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1460 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl com_pushedEventsTail, %edx\n"
        ".Lf2f1da_0002f1e6:\n"
        "cmpl %edx, com_pushedEventsHead\n" /* line 1464 */
        "jle .Lf2f1da_0002f21d\n"
        ".Lf2f1da_0002f1ee:\n"
        "movzbl %dl, %eax\n" /* line 1466 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x33a914(, %eax, 8), %ecx\n"
        "leal 1(%edx), %eax\n" /* line 1467 */
        "movl %eax, com_pushedEventsTail\n"
        "testl %ecx, %ecx\n" /* line 1468 */
        "je .Lf2f1da_0002f21f\n"
        "movl %ecx, (%esp)\n" /* line 1469 */
        "calll Z_FreeInternal\n"
        "movl com_pushedEventsTail, %edx\n"
        "cmpl %edx, com_pushedEventsHead\n" /* line 1464 */
        "jg .Lf2f1da_0002f1ee\n"
        ".Lf2f1da_0002f21d:\n"
        "leave\n" /* line 1471 */
        "retl\n"
        ".Lf2f1da_0002f21f:\n"
        "movl %eax, %edx\n"
        "jmp .Lf2f1da_0002f1e6\n"
    );
}

/* line 1837 */
static __attribute__((naked))
void Com_Error_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1837 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll Cmd_Argc\n" /* line 1839 */
        "subl $1, %eax\n"
        "jle .Lf2f226_0002f24c\n"
        "movl $0x216120, 4(%esp)\n" /* line 1841 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "leave\n" /* line 1847 */
        "retl\n"
        ".Lf2f226_0002f24c:\n"
        "movl $0x216134, 4(%esp)\n" /* line 1845 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "leave\n" /* line 1847 */
        "retl\n"
    );
}

/* line 1891 */
static void Com_Crash_f(void)
{
    *(int *)0 = 0x12345678;
}

/* line 1985 */
__attribute__((naked))
void Com_WriteCDKey(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1985 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "movl $cl_cdkeychecksum, 4(%esp)\n" /* line 1994 */
        "movl $cl_cdkey, (%esp)\n"
        "calll CL_CDKeyValidate\n"
        "testl %eax, %eax\n"
        "jne .Lf2f272_0002f2c1\n"
        "movl $0x20202020, cl_cdkey\n" /* line 1910 */
        "movl $0x20202020, 0x308b70\n"
        "movl $0x20202020, 0x308b74\n"
        "movl $0x20202020, 0x308b78\n"
        "movb $0, 0x308b7c\n"
        /* } scope */
        "leave\n" /* line 2029 */
        "retl\n"
        /* { scope 1 */
        ".Lf2f272_0002f2c1:\n"
        "leal -0x1d(%ebp), %edx\n" /* line 2002 | regkey */
        "movl cl_cdkey, %eax\n"
        "movl %eax, -0x1d(%ebp)\n" /* regkey */
        "movl 0x308b70, %eax\n"
        "movl %eax, -0x19(%ebp)\n"
        "movl 0x308b74, %eax\n"
        "movl %eax, -0x15(%ebp)\n"
        "movl 0x308b78, %eax\n"
        "movl %eax, -0x11(%ebp)\n"
        "movl cl_cdkeychecksum, %eax\n" /* line 2003 */
        "movl %eax, -0xd(%ebp)\n"
        "movb $0, -9(%ebp)\n" /* line 2004 */
        "movl %edx, 4(%esp)\n" /* line 2005 */
        "movl $0x21614c, (%esp)\n" /* "codkey" */
        "calll MacPreferences_PutString\n"
        /* } scope */
        "leave\n" /* line 2029 */
        "retl\n"
    );
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
        "movl $0x216180, 4(%esp)\n" /* "configure_mp.csv: dvar name "%s" longer than %i
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "cmpl $0x3f, -0x1c(%ebp)\n" /* line 2166 | dvarCount */
        "jle .Lf2f3d0_0002f3ed\n"
        ".Lf2f3d0_0002f45f:\n"
        "movl $0x40, 8(%esp)\n" /* line 2167 */
        "movl $0x2161b4, 4(%esp)\n" /* "configure_mp.csv: more than %i dvars
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
        "movl $0x216154, 4(%esp)\n" /* line 2160 */
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
        "movl $0x216264, 4(%esp)\n" /* "configure_mp.csv: extra dvar value column(s): value = %s
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
        "movl $0x216154, 4(%esp)\n" /* line 2188 */
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
        "movl $0x2161dc, 4(%esp)\n" /* "configure_mp.csv: missing entry in dvar value column %i
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
        "movl $0x216218, 4(%esp)\n" /* "configure_mp.csv: entry '%s' in dvar value column %i is lon" */
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
        "movl $0x2161dc, 4(%esp)\n" /* "configure_mp.csv: missing entry in dvar value column %i
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
        "movl $0x216218, 4(%esp)\n" /* "configure_mp.csv: entry '%s' in dvar value column %i is lon" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f4a4_0002f5eb\n"
        ".Lf2f4a4_0002f665:\n"
        "movl $0x216154, 4(%esp)\n" /* line 2188 */
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
        "movl $0x2162ac, 4(%esp)\n" /* "1" */
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
        "movl $0x2162a0, %edi\n" /* "r_aaSamples" */
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
static __attribute__((naked))
void Com_WriteConfigToFile(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2931 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl %eax, %esi\n" /* filename */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 2944 */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, %ebx\n" /* f */
        "testl %eax, %eax\n" /* line 2945 */
        "jne .Lf2f71a_0002f749\n"
        "movl %esi, 4(%esp)\n" /* line 2947 | filename */
        "movl $0x2162b0, (%esp)\n" /* "Couldn't write %s.
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 2961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f71a_0002f749:\n"
        "movl $0x2162c4, 4(%esp)\n" /* line 2951 */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movl $0x2162f4, 4(%esp)\n" /* line 2953 */
        "movl %ebx, (%esp)\n" /* f */
        "calll FS_Printf\n"
        "movl %ebx, (%esp)\n" /* line 2954 | f */
        "calll Key_WriteBindings\n"
        "movl %ebx, (%esp)\n" /* line 2959 | f */
        "calll Dvar_WriteVariables\n"
        "movl %ebx, (%esp)\n" /* line 2960 | f */
        "calll FS_FCloseFile\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 2961 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3036 */
__attribute__((naked))
void Com_WriteConfig_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3036 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 3040 */
        "cmpl $2, %eax\n"
        "je .Lf2f78a_0002f7ad\n"
        "movl $0x216310, (%esp)\n" /* line 3042 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 3050 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2f78a_0002f7ad:\n"
        "movl $1, (%esp)\n" /* line 3046 */
        "calll Cmd_Argv\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* filename */
        "movl %ebx, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x216330, 8(%esp)\n" /* line 3047 */
        "movl $0x40, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_DefaultExtension\n"
        "movl %ebx, 4(%esp)\n" /* line 3048 */
        "movl $0x216338, (%esp)\n" /* "Writing %s.
" */
        "calll Com_Printf\n"
        "movl %ebx, %eax\n" /* line 3049 */
        "calll Com_WriteConfigToFile\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 3050 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3082 */
__attribute__((naked))
float Com_GetTimescaleForSnd(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3082 */
        "movl %esp, %ebp\n"
        "subl $4, %esp\n"
        "movl com_fixedtime, %eax\n" /* line 3084 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf2f806_0002f826\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 3085 */
        "movss %xmm0, -4(%ebp)\n"
        "flds -4(%ebp)\n"
        "leave\n" /* line 3088 */
        "retl\n"
        ".Lf2f806_0002f826:\n"
        "movl com_timescale, %eax\n" /* line 3087 */
        "flds 8(%eax)\n"
        "leave\n" /* line 3088 */
        "retl\n"
    );
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
__attribute__((naked))
char Com_GetDecimalDelimiter(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4023 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 0x195ecb0, %eax\n" /* line 4028 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "leal -1(%edx), %eax\n" /* line 4030 */
        "cmpl $3, %eax\n"
        "jbe .Lf2f99c_0002f9c2\n"
        "cmpl $6, %edx\n"
        "je .Lf2f99c_0002f9c2\n"
        "cmpl $7, %edx\n"
        "je .Lf2f99c_0002f9c2\n"
        "movl $0x2e, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 4035 */
        "retl\n"
        /* { scope 1 */
        ".Lf2f99c_0002f9c2:\n"
        "movl $0x2c, %eax\n" /* line 4030 */
        /* } scope */
        "popl %ebp\n" /* line 4035 */
        "retl\n"
    );
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
        "movl $0x216378, (%esp)\n" /* line 2373 */
        "calll Com_Printf\n"
        "leal -0x230(%ebp), %eax\n" /* line 2375 | info */
        "movl %eax, (%esp)\n"
        "calll Sys_GetInfo\n"
        "movsd 0x307c70, %xmm0\n" /* line 2377 | 1.02 */
        "mulsd -0x230(%ebp), %xmm0\n" /* info */
        "movsd %xmm0, -0x230(%ebp)\n" /* info */
        "movl -0x228(%ebp), %eax\n" /* line 2379 */
        "cmpl $0x7f, %eax\n"
        "jg .Lf2f9ca_0002fd3e\n"
        "movl $0x80, -0x228(%ebp)\n" /* line 2380 */
        "leal -0x20(%ebp), %eax\n" /* line 2385 | csv */
        "movl %eax, 4(%esp)\n"
        "movl $0x216394, (%esp)\n" /* "configure_mp.csv" */
        "calll FS_ReadFile\n"
        "movl %eax, -0x1e5c(%ebp)\n" /* filesize */
        "testl %eax, %eax\n" /* line 2386 */
        "js .Lf2f9ca_0002fd68\n"
        ".Lf2f9ca_0002fa42:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2389 | csv */
        "movl %eax, -0x1c(%ebp)\n" /* text */
        "movl $0x216394, (%esp)\n" /* line 2390 */
        "calll Com_BeginParseSession\n"
        "movl $1, (%esp)\n" /* line 2391 */
        "calll Com_SetCSV\n"
        "xorl %esi, %esi\n" /* dvarCount */
        "movb $0, -0x1e55(%ebp)\n" /* foundMatch */
        "xorl %edi, %edi\n"
        "movsd 0x307c78, %xmm0\n" /* -1.0 */
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
        "movl $0x2163cc, 4(%esp)\n" /* line 2259 */
        "movl %ebx, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2f9ca_0002fbff\n"
        "testl %esi, %esi\n" /* line 2265 | dvarCount */
        "jne .Lf2f9ca_0002fb1e\n"
        "movl $0x2163d0, 4(%esp)\n" /* line 2267 */
        "movl %ebx, (%esp)\n" /* token */
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf2f9ca_0002fbe6\n"
        ".Lf2f9ca_0002fac7:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 2270 | text */
        "movl %eax, (%esp)\n"
        "calll Com_ParseOnLine\n"
        "movl $0x216414, 4(%esp)\n" /* line 2271 */
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
        "ucomisd 0x307c80, %xmm0\n" /* 0.0 */
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
        "movl $0x216498, 4(%esp)\n" /* "configure_mp.csv: sys mb %i not allowed to be less than 128" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002fb5c\n"
        ".Lf2f9ca_0002fbcd:\n"
        "movl $0x21641c, 4(%esp)\n" /* line 2272 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002faea\n"
        ".Lf2f9ca_0002fbe6:\n"
        "movl $0x2163d8, 4(%esp)\n" /* line 2268 */
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
        "movl $0x21652c, 4(%esp)\n" /* "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE %.0f GHz %i M" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* { scope 2: find */
        ".Lf2f9ca_0002fc4b:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 2325 | text */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl $0x2163cc, 4(%esp)\n" /* line 2326 */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf2f9ca_0002fdf7\n"
        "calll Com_UngetToken\n" /* line 2328 */
        /* } scope */
        ".Lf2f9ca_0002fc73:\n"
        "leal -0x223(%ebp), %eax\n" /* line 2401 */
        "movl %eax, 8(%esp)\n"
        "movl $0x2165cc, 4(%esp)\n" /* "configure_mp.csv: EXE_ERR_COULDNT_CONFIGURE "%s"
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
        "movl $0x216394, (%esp)\n" /* "configure_mp.csv" */
        "calll FS_ReadFile\n"
        "movl %eax, -0x1e5c(%ebp)\n" /* filesize */
        "testl %eax, %eax\n" /* line 2386 */
        "jns .Lf2f9ca_0002fa42\n"
        ".Lf2f9ca_0002fd68:\n"
        "movl $0x2163a8, 4(%esp)\n" /* line 2387 */
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
        "movl $0x216604, (%esp)\n" /* line 2412 */
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
        "movl $0x21656c, 4(%esp)\n" /* line 2135 */
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
        "movl $0x21659c, (%esp)\n" /* "configure_mp.csv: using GPU configuration "%s"
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
        "movl $0x216458, 4(%esp)\n" /* "configure_mp.csv: cpu ghz %g not allowed to be less than 0
" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf2f9ca_0002fb42\n"
        ".Lf2f9ca_0003000b:\n"
        "movl %edi, 0xc(%esp)\n" /* line 2305 */
        "movsd -0x1e48(%ebp), %xmm0\n"
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x2164d8, (%esp)\n" /* "configure_mp.csv: using CPU configuration %.0f GHz %i MB
" */
        "calll Com_Printf\n"
        "movl $0x216514, (%esp)\n" /* line 2307 */
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
        "movl $0x216394, (%esp)\n" /* "configure_mp.csv" */
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
        "movl $0x2163a8, 4(%esp)\n" /* line 2057 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf30052_00030082\n"
    );
}

/* line 1919 */
__attribute__((naked))
void Com_ReadCDKey(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1919 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "movl $0, 0xc(%esp)\n" /* line 1925 */
        "movl $0x15, 8(%esp)\n"
        "leal -0x1d(%ebp), %eax\n" /* regkey */
        "movl %eax, 4(%esp)\n"
        "movl $0x21614c, (%esp)\n" /* "codkey" */
        "calll MacPreferences_GetString\n"
        "testb %al, %al\n"
        "je .Lf30146_000301c3\n"
        "movl -0x1d(%ebp), %eax\n" /* line 1973 | regkey */
        "movl %eax, cl_cdkey\n"
        "movl -0x19(%ebp), %eax\n"
        "movl %eax, 0x308b70\n"
        "movl -0x15(%ebp), %eax\n"
        "movl %eax, 0x308b74\n"
        "movl -0x11(%ebp), %eax\n"
        "movl %eax, 0x308b78\n"
        "movb $0, 0x308b7c\n" /* line 1974 */
        "movl -0xd(%ebp), %eax\n" /* line 1975 */
        "movl %eax, cl_cdkeychecksum\n"
        "movb $0, 0x308b64\n" /* line 1976 */
        "movl $cl_cdkeychecksum, 4(%esp)\n" /* line 1977 */
        "movl $cl_cdkey, (%esp)\n"
        "calll CL_CDKeyValidate\n"
        "testl %eax, %eax\n"
        "je .Lf30146_000301c3\n"
        /* } scope */
        "leave\n" /* line 1982 */
        "retl\n"
        /* { scope 1 */
        ".Lf30146_000301c3:\n"
        "movl $0x20202020, cl_cdkey\n" /* line 1910 */
        "movl $0x20202020, 0x308b70\n"
        "movl $0x20202020, 0x308b74\n"
        "movl $0x20202020, 0x308b78\n"
        "movb $0, 0x308b7c\n"
        /* } scope */
        "leave\n" /* line 1982 */
        "retl\n"
    );
}

/* line 4038 */
__attribute__((naked))
void Com_LocalizedFloatToString(float f, char *buffer, unsigned int maxlen, unsigned int numDecimalPlaces)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4038 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* buffer */
        "movl 0x10(%ebp), %ebx\n" /* maxlen */
        /* { scope 1 */
        "cvtss2sd 8(%ebp), %xmm0\n" /* line 4043 | f */
        "movsd %xmm0, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* numDecimalPlaces */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x216614, 8(%esp)\n" /* "%.*f" */
        "leal -1(%ebx), %eax\n" /* maxlen */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* buffer */
        "calll snprintf\n"
        "movb $0, -1(%esi, %ebx)\n" /* line 4046 | buffer */
        "movl 0x195ecb0, %eax\n" /* line 4028 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        "leal -1(%edx), %eax\n" /* line 4030 */
        "cmpl $3, %eax\n"
        "jbe .Lf301f4_00030253\n"
        "cmpl $6, %edx\n"
        "je .Lf301f4_00030253\n"
        "cmpl $7, %edx\n"
        "je .Lf301f4_00030253\n"
        /* } scope */
        ".Lf301f4_0003024c:\n"
        "addl $0x20, %esp\n" /* line 4064 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf301f4_00030253:\n"
        "testl %ebx, %ebx\n" /* line 4055 | maxlen */
        "je .Lf301f4_0003024c\n"
        "cmpb $0x2e, (%esi)\n" /* line 4057 | buffer */
        "je .Lf301f4_00030277\n"
        "xorl %edx, %edx\n" /* line 4060 */
        ".Lf301f4_0003025e:\n"
        "addl $1, %edx\n" /* line 4055 */
        "cmpl %edx, %ebx\n" /* maxlen */
        "je .Lf301f4_0003024c\n"
        "leal (%esi, %edx), %eax\n" /* line 4053 | buffer */
        "cmpb $0x2e, (%eax)\n" /* line 4057 */
        "jne .Lf301f4_0003025e\n"
        "movb $0x2c, (%eax)\n" /* line 4059 */
        /* } scope */
        ".Lf301f4_00030270:\n"
        "addl $0x20, %esp\n" /* line 4064 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf301f4_00030277:\n"
        "movl %esi, %eax\n" /* line 4057 | buffer */
        "movb $0x2c, (%eax)\n" /* line 4059 */
        "jmp .Lf301f4_00030270\n"
    );
}

/* line 1045 */
__attribute__((naked))
void Com_Quit_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1045 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x21661c, (%esp)\n" /* line 1049 */
        "calll Com_Printf\n"
        "movl com_errorEntered, %ecx\n" /* line 1060 */
        "testl %ecx, %ecx\n"
        "je .Lf3027e_000302a0\n"
        "leave\n" /* line 1094 */
        "jmp Sys_Quit\n" /* line 1093 */
        ".Lf3027e_000302a0:\n"
        "calll Hunk_ClearTempMemory\n" /* line 582 */
        "calll Hunk_ClearTempMemoryHigh\n" /* line 583 */
        "calll Sys_DestroySplashWindow\n" /* line 1065 */
        "movl $0, (%esp)\n" /* line 1069 */
        "calll CL_SwitchToLocalClient\n"
        "calll CL_Shutdown\n" /* line 1070 */
        "movl $0, (%esp)\n" /* line 1072 */
        "calll CL_SwitchToLocalClient\n"
        "movl $0x21662c, (%esp)\n" /* line 1079 */
        "calll SV_Shutdown\n"
        "calll Com_Close\n" /* line 1083 */
        "movl logfile, %eax\n" /* line 3766 */
        "testl %eax, %eax\n"
        "jne .Lf3027e_00030302\n"
        ".Lf3027e_000302e6:\n"
        "movl $1, (%esp)\n" /* line 1086 */
        "calll FS_Shutdown\n"
        "calll FS_ShutdownServerIwdNames\n" /* line 1089 */
        "calll FS_ShutdownServerReferencedIwds\n" /* line 1090 */
        "leave\n" /* line 1094 */
        "jmp Sys_Quit\n" /* line 1093 */
        ".Lf3027e_00030302:\n"
        "movl %eax, (%esp)\n" /* line 3768 */
        "calll FS_FCloseFile\n"
        "movl $0, logfile\n" /* line 3769 */
        "jmp .Lf3027e_000302e6\n"
    );
}

/* line 3839 */
__attribute__((naked))
void Com_Restart(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3839 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll CL_ShutdownHunkUsers\n" /* line 3842 */
        "calll SV_ShutdownGameProgs\n" /* line 3846 */
        "calll CIN_CloseAllVideos\n" /* line 3850 */
        "calll Com_ShutdownDObj\n" /* line 3853 */
        "calll DObjShutdown\n" /* line 3854 */
        "calll XAnimShutdown\n" /* line 3855 */
        "calll CM_Shutdown\n" /* line 3857 */
        "calll SND_ShutdownChannels\n" /* line 3858 */
        "calll Hunk_Clear\n" /* line 3860 */
        "calll Scr_Init\n" /* line 3883 */
        "movl com_developer, %eax\n" /* line 2441 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf30316_00030366\n"
        "movl com_logfile, %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf30316_0003039e\n"
        ".Lf30316_00030366:\n"
        "movl $1, %ecx\n"
        ".Lf30316_0003036b:\n"
        "movl %edx, 8(%esp)\n" /* line 2443 */
        "movl com_developer_script, %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Scr_Settings\n"
        "movl $0, com_fixedConsolePosition\n" /* line 3886 */
        "calll XAnimInit\n" /* line 3899 */
        "calll DObjInit\n" /* line 3900 */
        "leave\n" /* line 3902 */
        "jmp Com_InitDObj\n" /* line 3901 */
        ".Lf30316_0003039e:\n"
        "xorl %ecx, %ecx\n" /* line 2441 */
        "jmp .Lf30316_0003036b\n"
    );
}

/* line 526 */
__attribute__((naked))
void Com_ShutdownInternal(char *finalmsg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 526 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* finalmsg */
        "movl $0, (%esp)\n" /* line 533 */
        "calll CL_SwitchToLocalClient\n"
        "calll CL_Disconnect\n" /* line 534 */
        "movl $0, (%esp)\n" /* line 536 */
        "calll CL_SwitchToLocalClient\n"
        "calll CL_ShutdownAll\n" /* line 538 */
        "calll CL_ShutdownDemo\n" /* line 540 */
        "movl %ebx, (%esp)\n" /* line 547 | finalmsg */
        "calll SV_Shutdown\n"
        "addl $0x14, %esp\n" /* line 549 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp Com_Restart\n" /* line 548 */
    );
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
        "movl 0x195eca8, %eax\n" /* line 706 */
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
        "movl $0x21663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_SetIntByName\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 733 */
        "movl $0x2157b8, (%esp)\n"
        "calll FS_PureServerSetLoadedIwds\n"
        "calll SEH_UpdateLanguageInfo\n" /* line 739 */
        "movl $com_errorMessage, 4(%esp)\n" /* line 744 */
        "leal -0x1008(%ebp), %ebx\n" /* szUnlocedMsg */
        "movl %ebx, (%esp)\n"
        "calll strcpy\n"
        "cmpl $3, errorcode\n" /* line 746 */
        "je .Lf303e6_0003061d\n"
        "movl 0x195ecac, %eax\n" /* line 753 */
        "movl 0x110(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf303e6_0003060c\n"
        ".Lf303e6_00030484:\n"
        "movl $com_errorMessage, %eax\n" /* line 756 */
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
        "movl 0x195eca8, %eax\n" /* line 795 */
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
        "movl 0x195ec94, %eax\n" /* line 828 */
        "movb $0, (%eax)\n"
        "cmpl $2, errorcode\n" /* line 832 */
        "je .Lf303e6_000305d4\n"
        ".Lf303e6_00030537:\n"
        "movl $com_errorMessage, 4(%esp)\n" /* line 840 */
        "movl $0x21666c, (%esp)\n" /* "********************
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
        "movl $0x216058, (%esp)\n" /* "%s" */
        "calll Sys_Error\n"
        "movl 0x195ec94, %eax\n" /* line 828 */
        "movb $0, (%eax)\n"
        "cmpl $2, errorcode\n" /* line 832 */
        "jne .Lf303e6_00030537\n"
        ".Lf303e6_000305d4:\n"
        "movl $0x216648, (%esp)\n" /* line 834 */
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
        "movl $0x216080, 4(%esp)\n" /* "error message" */
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
        "movl 0x195ecac, %eax\n" /* line 845 */
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
        "movl $0x2166a4, (%esp)\n" /* line 2610 */
        "calll Cbuf_AddText\n"
        "movl $0x2166bc, (%esp)\n" /* line 2611 */
        "calll Cbuf_AddText\n"
        "testl %ebx, %ebx\n" /* line 2612 | configFile */
        "je .Lf306b6_000306f4\n"
        "movl %ebx, 4(%esp)\n" /* line 2613 | configFile */
        "movl $0x2166d0, (%esp)\n" /* "exec %s
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
        "movl $0x2166dc, (%esp)\n" /* line 2619 */
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
        "movl 0x33a914(%eax), %ebx\n"
        "movl %ebx, -0xac(%ebp)\n"
        "movl 0x33a910(%eax), %edx\n"
        "movl 0x33a90c(%eax), %ecx\n"
        "movl 0x33a908(%eax), %ebx\n"
        "movl 0x33a904(%eax), %esi\n"
        "movl com_pushedEvents(%eax), %edi\n"
        "cmpl $5, %esi\n" /* line 1516 */
        "ja .Lf30736_00030909\n"
        ".Lf30736_000307d0:\n"
        "jmpl *0x2efd80(, %esi, 4)\n"
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
        "movl $0x2166f4, 4(%esp)\n" /* "Com_EventLoop: bad event type %i" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf30736_0003077a\n"
        "movl %ebx, (%esp)\n" /* line 1606 */
        "calll CL_CharEvent\n"
        "jmp .Lf30736_0003077a\n"
        "movl $0, (%esp)\n" /* line 1641 */
        "calll CL_SwitchToLocalClient\n"
        "movl -0xac(%ebp), %edx\n" /* line 1644 */
        "movl %edx, (%esp)\n"
        "calll Cbuf_AddText\n"
        "movl -0xac(%ebp), %ecx\n" /* line 1645 */
        "movl %ecx, (%esp)\n"
        "calll Z_FreeInternal\n"
        "movl $0x2160e8, (%esp)\n" /* line 1646 */
        "calll Cbuf_AddText\n"
        "jmp .Lf30736_0003077a\n"
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
        "movl $0x216718, (%esp)\n" /* line 1662 */
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
        "movl 0x33a914(%eax), %edi\n"
        "movl 0x33a90c(%eax), %edx\n"
        "movl 0x33a908(%eax), %ecx\n"
        "movl 0x33a904(%eax), %ebx\n"
        "movl com_pushedEvents(%eax), %eax\n"
        "cmpl $5, %ebx\n" /* line 1727 */
        "ja .Lf30a84_00030b49\n"
        ".Lf30a84_00030ad6:\n"
        "jmpl *0x2efd98(, %ebx, 4)\n"
        "movl %edi, (%esp)\n" /* line 1764 */
        "calll Cbuf_AddText\n"
        "movl %edi, (%esp)\n" /* line 1765 */
        "calll Z_FreeInternal\n"
        "movl $0x2160e8, (%esp)\n" /* line 1766 */
        "calll Cbuf_AddText\n"
        /* } scope */
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
        "movl $0x2166f4, 4(%esp)\n" /* "Com_EventLoop: bad event type %i" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 1772 */
        "calll Z_FreeInternal\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        "movl -0x5c(%ebp), %eax\n" /* line 1779 | newEvent */
        "leal -0xc(%ebp), %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl %eax, 8(%esp)\n" /* line 1744 */
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll CL_KeyEvent\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
        /* { scope 1 */
        "movl %ecx, (%esp)\n" /* line 1750 */
        "calll CL_CharEvent\n"
        /* } scope */
        "movl $1, -0x5c(%ebp)\n" /* line 1716 | newEvent */
        "jmp .Lf30a84_00030b00\n"
    );
}

/* line 3321 */
__attribute__((naked))
void Com_Frame_Try_Block_Function(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3321 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: useTimescale */
        "movl com_fullyInitialized, %edi\n" /* line 3002 */
        "testl %edi, %edi\n"
        "je .Lf30bb6_00030bd9\n"
        "movl 0x195ec9c, %edx\n" /* line 3005 */
        "movl (%edx), %eax\n"
        "testb $1, %al\n"
        "jne .Lf30bb6_00030f6d\n"
        ".Lf30bb6_00030bd9:\n"
        "movl com_viewlog, %edx\n" /* line 3286 */
        "cmpb $0, 7(%edx)\n"
        "je .Lf30bb6_00030bff\n"
        "movl 0x195ec98, %eax\n" /* line 3290 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf30bb6_00030fa6\n"
        ".Lf30bb6_00030bf7:\n"
        "movl %edx, (%esp)\n" /* line 3295 */
        "calll Dvar_ClearModified\n"
        ".Lf30bb6_00030bff:\n"
        "movl com_animCheck, %eax\n" /* line 3341 */
        "movzbl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll SetAnimCheck\n"
        "movl com_maxfps, %eax\n" /* line 3345 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf30bb6_00030c2e\n"
        "movl 0x195ec98, %eax\n" /* line 3348 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* minMsec */
        "testl %ebx, %ebx\n" /* minMsec */
        "je .Lf30bb6_00030f27\n"
        ".Lf30bb6_00030c2e:\n"
        "movl $1, %ebx\n" /* line 3353 | minMsec */
        "jmp .Lf30bb6_00030c41\n"
        ".Lf30bb6_00030c35:\n"
        "movl $0, (%esp)\n" /* line 3381 */
        "calll NET_Sleep\n"
        ".Lf30bb6_00030c41:\n"
        "calll Com_EventLoop\n" /* line 3374 */
        "movl %eax, com_frameTime\n"
        "cmpl com_lastFrameTime, %eax\n" /* line 3377 */
        "movl com_lastFrameTime, %edx\n"
        "cmovll %eax, %edx\n"
        "movl %edx, com_lastFrameTime\n"
        "movl %eax, %esi\n" /* line 3378 */
        "subl %edx, %esi\n"
        "cmpl %ebx, %esi\n" /* line 3379 | minMsec */
        "jl .Lf30bb6_00030c35\n"
        "calll Cbuf_Execute\n" /* line 3383 */
        "movl com_frameTime, %eax\n" /* line 3385 */
        "movl %eax, com_lastFrameTime\n"
        /* { scope 2 */
        "movl com_fixedtime, %eax\n" /* line 3107 */
        "movl 8(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf30bb6_00030dfb\n"
        "movl com_timescale, %eax\n" /* line 3112 */
        "movss 8(%eax), %xmm1\n"
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jne .Lf30bb6_00030dd1\n"
        "jp .Lf30bb6_00030dd1\n"
        "ucomiss com_codeTimeScale, %xmm0\n"
        "jne .Lf30bb6_00030dd1\n"
        "jp .Lf30bb6_00030dd1\n"
        "movl %esi, %ebx\n"
        "movb $0, -0x59(%ebp)\n" /* useTimescale */
        "testl %ebx, %ebx\n" /* line 3123 */
        "movl $1, %eax\n"
        "cmovlel %eax, %ebx\n"
        "movl 0x195ec98, %eax\n" /* line 3127 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf30bb6_00030e1b\n"
        ".Lf30bb6_00030cdd:\n"
        "leal -0x1f5(%ebx), %eax\n" /* line 3132 */
        "cmpl $0x79f2a, %eax\n"
        "jbe .Lf30bb6_00030f53\n"
        ".Lf30bb6_00030cee:\n"
        "movl $0x1388, %edi\n" /* line 3141 */
        ".Lf30bb6_00030cf3:\n"
        "cmpl %edi, %ebx\n" /* line 3156 */
        "cmovlel %ebx, %edi\n"
        "cmpb $0, -0x59(%ebp)\n" /* line 3159 | useTimescale */
        "je .Lf30bb6_00030d06\n"
        "testl %esi, %esi\n"
        "jne .Lf30bb6_00030f42\n"
        ".Lf30bb6_00030d06:\n"
        "movss 0x2ed5d0, %xmm1\n" /* 1.0f */
        ".Lf30bb6_00030d0e:\n"
        "movss %xmm1, com_timescaleValue\n"
        /* } scope */
        "movl $0, (%esp)\n" /* line 3395 */
        "calll CL_SwitchToLocalClient\n"
        "movl %edi, (%esp)\n" /* line 3400 */
        "calll SV_Frame\n"
        "movl 0x195ec98, %ebx\n" /* line 3180 */
        "movl (%ebx), %edx\n"
        "testb $0x40, 4(%edx)\n"
        "jne .Lf30bb6_00030e34\n"
        "movl 0xc(%edx), %eax\n" /* line 3184 */
        "cmpl 8(%edx), %eax\n"
        "je .Lf30bb6_00030dc0\n"
        "movl $0x1020, 0x10(%esp)\n" /* line 3187 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, (%ebx)\n"
        "movl 8(%eax), %edx\n" /* line 3188 */
        "testl %edx, %edx\n"
        "jne .Lf30bb6_00030fc4\n"
        ".Lf30bb6_00030d7d:\n"
        "movl %eax, (%esp)\n" /* line 3193 */
        "calll Dvar_ClearModified\n"
        "movl $0, (%esp)\n" /* line 3197 */
        "calll CL_SwitchToLocalClient\n"
        "calll CL_Shutdown\n" /* line 3198 */
        "movl $0, (%esp)\n" /* line 3200 */
        "calll CL_SwitchToLocalClient\n"
        "movl $1, 4(%esp)\n" /* line 3203 */
        "movl $1, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "calll Sys_NormalExit\n" /* line 3207 */
        "calll SV_AddDedicatedCommands\n" /* line 3209 */
        ".Lf30bb6_00030dc0:\n"
        "movl (%ebx), %eax\n"
        "movl 8(%eax), %eax\n" /* line 3412 */
        "testl %eax, %eax\n"
        "je .Lf30bb6_00030e3d\n"
        /* } scope */
        ".Lf30bb6_00030dc9:\n"
        "addl $0x7c, %esp\n" /* line 3473 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: useTimescale */
        /* { scope 2 */
        ".Lf30bb6_00030dd1:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* line 428 */
        "mulss %xmm0, %xmm1\n"
        "mulss com_codeTimeScale, %xmm1\n"
        "addss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "movss %xmm1, (%esp)\n"
        "calll floorf\n"
        "fstps -0x60(%ebp)\n"
        "cvttss2si -0x60(%ebp), %ebx\n"
        ".Lf30bb6_00030dfb:\n"
        "movb $1, -0x59(%ebp)\n" /* useTimescale */
        "testl %ebx, %ebx\n" /* line 3123 */
        "movl $1, %eax\n"
        "cmovlel %eax, %ebx\n"
        "movl 0x195ec98, %eax\n" /* line 3127 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf30bb6_00030cdd\n"
        ".Lf30bb6_00030e1b:\n"
        "movl com_sv_running, %eax\n" /* line 3141 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf30bb6_00030cee\n"
        "movl $0xc8, %edi\n"
        "jmp .Lf30bb6_00030cf3\n"
        ".Lf30bb6_00030e34:\n"
        "movl %edx, %eax\n"
        /* } scope */
        "movl 8(%eax), %eax\n" /* line 3412 */
        "testl %eax, %eax\n"
        "jne .Lf30bb6_00030dc9\n"
        ".Lf30bb6_00030e3d:\n"
        "movl $0, (%esp)\n" /* line 3424 */
        "calll CL_SwitchToLocalClient\n"
        "movl %edi, (%esp)\n" /* line 3425 */
        "calll CL_RunOncePerClientFrame\n"
        "movl $0, (%esp)\n" /* line 3427 */
        "calll CL_SwitchToLocalClient\n"
        "calll Com_EventLoop\n" /* line 3428 */
        "movl $0, (%esp)\n" /* line 3432 */
        "calll CL_SwitchToLocalClient\n"
        "calll Cbuf_Execute\n" /* line 3433 */
        "movl $0, (%esp)\n" /* line 3436 */
        "calll CL_SwitchToLocalClient\n"
        "calll SND_UpdateLoopingSounds\n" /* line 3439 */
        "calll SND_Update\n" /* line 3440 */
        "movl $0, (%esp)\n" /* line 3452 */
        "calll CL_SwitchToLocalClient\n"
        "movl %edi, (%esp)\n" /* line 3453 */
        "calll CL_Frame\n"
        "movl $0, (%esp)\n" /* line 3456 */
        "calll CL_SwitchToLocalClient\n"
        "calll SCR_UpdateScreenInternal\n" /* line 3458 */
        "calll SCR_RunCinematic\n" /* line 3460 */
        "movl com_statmon, %eax\n" /* line 3259 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf30bb6_00030dc9\n"
        "movl 0x195eca0, %ebx\n" /* line 3262 */
        "movl (%ebx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf30bb6_00030ff7\n"
        ".Lf30bb6_00030ed2:\n"
        "movl timeClientFrame, %ebx\n" /* line 3268 */
        "calll Sys_Milliseconds\n" /* line 3269 */
        "movl %eax, %edx\n"
        "movl %eax, timeClientFrame\n"
        "movl com_statmon, %eax\n" /* line 3270 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf30bb6_00030dc9\n"
        "subl %ebx, %edx\n"
        "cmpl $0x21, %edx\n"
        "jle .Lf30bb6_00030dc9\n"
        "testl %ebx, %ebx\n"
        "je .Lf30bb6_00030dc9\n"
        "movl $0x216360, 8(%esp)\n" /* line 3271 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll StatMon_Warning\n"
        "jmp .Lf30bb6_00030dc9\n"
        ".Lf30bb6_00030f27:\n"
        "movl $0x3e8, %ecx\n" /* line 3351 */
        "movl %ecx, %eax\n"
        "movl %edx, %esi\n"
        "cltd\n"
        "idivl %esi\n"
        "movl %eax, %ebx\n" /* minMsec */
        "testl %eax, %eax\n" /* line 3353 */
        "jne .Lf30bb6_00030c41\n"
        "jmp .Lf30bb6_00030c2e\n"
        /* { scope 2 */
        ".Lf30bb6_00030f42:\n"
        "cvtsi2ssl %edi, %xmm1\n" /* line 3159 */
        "cvtsi2ssl %esi, %xmm0\n"
        "divss %xmm0, %xmm1\n"
        "jmp .Lf30bb6_00030d0e\n"
        ".Lf30bb6_00030f53:\n"
        "movl %ebx, 4(%esp)\n" /* line 3134 */
        "movl $0x216738, (%esp)\n" /* "Hitch warning: %i msec frame time
" */
        "calll Com_Printf\n"
        "movl $0x1388, %edi\n"
        "jmp .Lf30bb6_00030cf3\n"
        /* } scope */
        ".Lf30bb6_00030f6d:\n"
        "andl $0xfffffffe, %eax\n" /* line 3007 */
        "movl %eax, (%edx)\n"
        "calll Com_HasPlayerProfile\n" /* line 3010 */
        "testb %al, %al\n"
        "je .Lf30bb6_00030bd9\n"
        "movl $0x216300, 8(%esp)\n" /* line 3012 */
        "movl $0x40, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll Com_BuildPlayerProfilePath\n"
        "movl %ebx, %eax\n" /* line 3025 */
        "calll Com_WriteConfigToFile\n"
        "jmp .Lf30bb6_00030bd9\n"
        ".Lf30bb6_00030fa6:\n"
        "movl $0, 4(%esp)\n" /* line 3293 */
        "movl 8(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "movl com_viewlog, %edx\n"
        "jmp .Lf30bb6_00030bf7\n"
        ".Lf30bb6_00030fc4:\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 3189 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "movl (%ebx), %eax\n"
        "jmp .Lf30bb6_00030d7d\n"
        ".Lf30bb6_00030ff7:\n"
        "movl $0x216348, 8(%esp)\n" /* line 3264 */
        "movl $0xbb8, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll StatMon_Warning\n"
        "movl $0, (%ebx)\n" /* line 3265 */
        "jmp .Lf30bb6_00030ed2\n"
    );
}

/* line 558 */
void Com_Shutdown(char *finalmsg)
{
    Com_ShutdownInternal(finalmsg);
    UI_SetMap("", "");
    CL_StartHunkUsers();
}

/* line 3505 */
static __attribute__((naked))
void Com_StartHunkUsers(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3505 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, (%esp)\n" /* line 3507 */
        "calll Sys_GetValue\n"
        "movl %eax, (%esp)\n"
        "calll setjmp\n"
        "testl %eax, %eax\n"
        "jne .Lf3104a_000310a6\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 3487 */
        "movl $0x2157b8, (%esp)\n"
        "calll UI_SetMap\n"
        "calll CL_StartHunkUsers\n" /* line 3490 */
        "calll Com_EventLoop\n" /* line 3513 */
        "movl 0x195ec98, %eax\n" /* line 3530 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf3104a_000310a4\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf3104a_000310a4\n"
        "movl $1, (%esp)\n" /* line 3533 */
        "calll UI_SetActiveMenu\n"
        ".Lf3104a_000310a4:\n"
        "leave\n" /* line 3539 */
        "retl\n"
        ".Lf3104a_000310a6:\n"
        "movl $0x216768, (%esp)\n" /* line 3537 */
        "calll Sys_Error\n"
        "leave\n" /* line 3539 */
        "retl\n"
    );
}

/* line 3618 */
__attribute__((naked))
void Com_Frame(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3618 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, (%esp)\n" /* line 3632 */
        "calll Sys_GetValue\n"
        "movl %eax, (%esp)\n"
        "calll setjmp\n"
        "testl %eax, %eax\n"
        "je .Lf310b4_000310e9\n"
        ".Lf310b4_000310d2:\n"
        "movl com_errorEntered, %eax\n" /* line 3652 */
        "testl %eax, %eax\n"
        "jne .Lf310b4_000310dd\n"
        "leave\n" /* line 3669 */
        "retl\n"
        ".Lf310b4_000310dd:\n"
        "calll Com_ErrorCleanup\n" /* line 3660 */
        "calll Com_StartHunkUsers\n" /* line 3667 */
        "leave\n" /* line 3669 */
        "retl\n"
        ".Lf310b4_000310e9:\n"
        "calll Com_Frame_Try_Block_Function\n" /* line 3637 */
        "addl $1, com_frameNumber\n" /* line 3640 */
        "jmp .Lf310b4_000310d2\n"
    );
}

/* line 3060 */
__attribute__((naked))
void Com_WriteDefaults_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3060 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        /* { scope 1 */
        "calll Cmd_Argc\n" /* line 3064 */
        "cmpl $2, %eax\n"
        "je .Lf310f8_0003111d\n"
        "movl $0x216784, (%esp)\n" /* line 3066 */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 3074 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf310f8_0003111d:\n"
        "movl $1, (%esp)\n" /* line 3070 */
        "calll Cmd_Argv\n"
        "movl $0x40, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x48(%ebp), %esi\n" /* filename */
        "movl %esi, (%esp)\n"
        "calll I_strncpyz\n"
        "movl $0x216330, 8(%esp)\n" /* line 3071 */
        "movl $0x40, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll Com_DefaultExtension\n"
        "movl %esi, 4(%esp)\n" /* line 3072 */
        "movl $0x216338, (%esp)\n" /* "Writing %s.
" */
        "calll Com_Printf\n"
        /* { scope 2 */
        "movl %esi, (%esp)\n" /* line 2976 */
        "calll FS_FOpenFileWrite\n"
        "movl %eax, %ebx\n" /* f */
        "testl %eax, %eax\n" /* line 2977 */
        "je .Lf310f8_0003119d\n"
        "movl $0x2162c4, 4(%esp)\n" /* line 2983 */
        "movl %eax, (%esp)\n"
        "calll FS_Printf\n"
        "movl %ebx, (%esp)\n" /* line 2984 | f */
        "calll Dvar_WriteDefaults\n"
        "movl %ebx, (%esp)\n" /* line 2985 | f */
        "calll FS_FCloseFile\n"
        /* } scope */
        /* } scope */
        "addl $0x50, %esp\n" /* line 3074 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf310f8_0003119d:\n"
        "movl %esi, 4(%esp)\n" /* line 2979 */
        "movl $0x2162b0, (%esp)\n" /* "Couldn't write %s.
" */
        "calll Com_Printf\n"
        /* } scope */
        /* } scope */
        "addl $0x50, %esp\n" /* line 3074 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1789 */
__attribute__((naked))
int Com_Milliseconds(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1789 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "jmp .Lf311b4_00031213\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf311b4_000311bf:\n"
        "movl printedWarning, %eax\n" /* line 1433 */
        "testl %eax, %eax\n"
        "je .Lf311b4_0003127e\n"
        ".Lf311b4_000311cc:\n"
        "movl 0x14(%ebx), %eax\n" /* line 1439 | ev */
        "testl %eax, %eax\n"
        "je .Lf311b4_000311db\n"
        "movl %eax, (%esp)\n" /* line 1441 */
        "calll Z_FreeInternal\n"
        ".Lf311b4_000311db:\n"
        "addl $1, com_pushedEventsTail\n" /* line 1443 */
        "movl com_pushedEventsHead, %edx\n"
        ".Lf311b4_000311e8:\n"
        "movl %edi, -0x30(%ebp)\n" /* line 1450 | ev */
        "movl %esi, -0x2c(%ebp)\n"
        "movl %edi, (%ebx)\n" /* ev */
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
        ".Lf311b4_00031213:\n"
        "leal -0x58(%ebp), %eax\n" /* line 1797 */
        "movl %eax, (%esp)\n"
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x58(%ebp), %edi\n"
        "movl %edi, -0x30(%ebp)\n" /* ev */
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
        "je .Lf311b4_00031299\n"
        /* { scope 2 */
        "movl com_pushedEventsHead, %edx\n" /* line 1427 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal com_pushedEvents(, %eax, 8), %ebx\n" /* ev */
        "movl %edx, %eax\n" /* line 1429 */
        "subl com_pushedEventsTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lf311b4_000311bf\n"
        "movl $0, printedWarning\n" /* line 1447 */
        "jmp .Lf311b4_000311e8\n"
        ".Lf311b4_0003127e:\n"
        "movl $1, printedWarning\n" /* line 1435 */
        "movl $0x2160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf311b4_000311cc\n"
        /* } scope */
        /* } scope */
        ".Lf311b4_00031299:\n"
        "movl %edi, %eax\n" /* line 1803 */
        "leal -0xc(%ebp), %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
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
        "movl $0x2160fc, (%esp)\n" /* line 1436 */
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
        "movl $0x2167a8, (%esp)\n" /* line 1865 */
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
        "movl $0x2160fc, (%esp)\n" /* line 1436 */
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
        "mulsd 0x307c88, %xmm0\n" /* 0.001 */
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
        "movl $0x2160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf31392_0003153b\n"
    );
}

/* line 2648 */
__attribute__((naked))
void Com_Init_Try_Block_Function(char *commandLine)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2648 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* commandLine */
        /* { scope 1 */
        "movl $0x2167bc, 0x10(%esp)\n" /* line 2663 */
        "movl $0x2167c8, 0xc(%esp)\n" /* "MacOSXS-i386" */
        "movl $0x2167d8, 8(%esp)\n" /* "1.0" */
        "movl $0x2167dc, 4(%esp)\n" /* "CoD2 MP" */
        "movl $0x2167e4, (%esp)\n" /* "%s %s build %s %s
" */
        "calll Com_Printf\n"
        "movl $0x1800, 8(%esp)\n" /* line 1409 */
        "movl $0, 4(%esp)\n"
        "movl $com_pushedEvents, (%esp)\n"
        "calll memset\n"
        "movl $0, com_pushedEventsHead\n" /* line 1412 */
        "movl $0, com_pushedEventsTail\n" /* line 1413 */
        "movl %ebx, com_consoleLines\n" /* line 1219 */
        "movl $1, com_numConsoleLines\n" /* line 1220 */
        ".Lf315d6_00031651:\n"
        "movzbl (%ebx), %eax\n" /* line 1222 */
        "testb %al, %al\n"
        "je .Lf315d6_00031672\n"
        ".Lf315d6_00031658:\n"
        "cmpb $0x2b, %al\n" /* line 1226 */
        "je .Lf315d6_00031b68\n"
        "cmpb $0xa, %al\n"
        "je .Lf315d6_00031b68\n"
        "addl $1, %ebx\n"
        "movzbl (%ebx), %eax\n" /* line 1222 */
        "testb %al, %al\n"
        "jne .Lf315d6_00031658\n"
        ".Lf315d6_00031672:\n"
        "calll Swap_Init\n" /* line 2672 */
        "calll Cbuf_Init\n" /* line 2673 */
        "calll Cmd_Init\n" /* line 2675 */
        "movl $0, (%esp)\n" /* line 2678 */
        "calll Com_StartupVariable\n"
        "movl $0x2167f8, (%esp)\n" /* line 2681 */
        "calll Com_StartupVariable\n"
        "calll CL_InitKeyCommands\n" /* line 2685 */
        "calll FS_InitFilesystem\n" /* line 2691 */
        "movl $0x1020, 0x10(%esp)\n" /* line 2535 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "movl 0x195ec98, %ebx\n"
        "movl %eax, (%ebx)\n"
        "movl 8(%eax), %esi\n" /* line 2536 */
        "testl %esi, %esi\n"
        "jne .Lf315d6_00031e7a\n"
        ".Lf315d6_000316e2:\n"
        "movl $0x1001, 0x10(%esp)\n" /* line 2541 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0x55, 4(%esp)\n"
        "movl $0x216804, (%esp)\n" /* "com_maxfps" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, com_maxfps\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 2556 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x2167f8, (%esp)\n" /* "developer" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, com_developer\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 2557 */
        "movl $0, 4(%esp)\n"
        "movl $0x216810, (%esp)\n" /* "developer_script" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, com_developer_script\n"
        "movl $__mh_execute_header, 0x10(%esp)\n" /* line 2558 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x216824, (%esp)\n" /* "logfile" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, com_logfile\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 2559 */
        "movl $0, 4(%esp)\n"
        "movl $0x21682c, (%esp)\n" /* "com_statmon" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, com_statmon\n"
        "movl $0x1088, 0x10(%esp)\n" /* line 2561 */
        "movl $0x447a0000, 0xc(%esp)\n"
        "movl $0x3a83126f, 8(%esp)\n"
        "movl $0x3f800000, 4(%esp)\n"
        "movl $0x216838, (%esp)\n" /* "timescale" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, com_timescale\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 2562 */
        "movl $0x3e8, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x216844, (%esp)\n" /* "fixedtime" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, com_fixedtime\n"
        "movl $0x1080, 0x10(%esp)\n" /* line 2563 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x216850, (%esp)\n" /* "viewlog" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, com_viewlog\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 2565 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x216858, (%esp)\n" /* "sv_paused" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sv_paused\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 2566 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21663c, (%esp)\n" /* "cl_paused" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, cl_paused\n"
        "movl $0x1040, 8(%esp)\n" /* line 2570 */
        "movl $0, 4(%esp)\n"
        "movl $0x216864, (%esp)\n" /* "sv_running" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, com_sv_running\n"
        "movl 0x195ecb4, %eax\n" /* line 2571 */
        "movl (%eax), %eax\n"
        "movl $0, 4(%eax)\n"
        "movl $0x1001, 8(%esp)\n" /* line 2573 */
        "movl $0, 4(%esp)\n"
        "movl $0x216870, (%esp)\n" /* "com_introPlayed" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, com_introPlayed\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 2575 */
        "movl $0, 4(%esp)\n"
        "movl $0x216880, (%esp)\n" /* "com_animCheck" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, com_animCheck\n"
        "movl (%ebx), %eax\n" /* line 2578 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf315d6_00031936\n"
        "movl com_viewlog, %eax\n" /* line 2580 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf315d6_00031f0f\n"
        ".Lf315d6_00031936:\n"
        "movl $0, (%esp)\n" /* line 2708 */
        "calll CL_SwitchToLocalClient\n"
        "calll Com_InitPlayerProfiles\n" /* line 2633 */
        "movl $0, (%esp)\n" /* line 2711 */
        "calll CL_SwitchToLocalClient\n"
        "calll Cbuf_Execute\n" /* line 2714 */
        "movl $0x1001, 8(%esp)\n" /* line 2717 */
        "movl $0, 4(%esp)\n"
        "movl $0x216890, (%esp)\n" /* "com_recommendedSet" */
        "calll Dvar_RegisterBool\n"
        "movl %eax, com_recommendedSet\n"
        "calll Com_CheckSetRecommended\n" /* line 2718 */
        "movl $0, (%esp)\n" /* line 2724 */
        "calll Com_StartupVariable\n"
        "calll SEH_UpdateLanguageInfo\n" /* line 2729 */
        "movl 0x195ec98, %eax\n" /* line 2735 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf315d6_00031eec\n"
        ".Lf315d6_000319a1:\n"
        "calll Com_InitHunkMemory\n" /* line 2753 */
        "movl 0x195ec9c, %eax\n" /* line 2757 */
        "andl $0xfffffffe, (%eax)\n"
        "movl $0x3f800000, com_codeTimeScale\n" /* line 2758 */
        "movl com_developer, %eax\n" /* line 2770 */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf315d6_00031eab\n"
        ".Lf315d6_000319c8:\n"
        "movl $Com_Quit_f, 4(%esp)\n" /* line 2776 */
        "movl $0x2168bc, (%esp)\n" /* "quit" */
        "calll Cmd_AddCommand\n"
        "movl $Com_WriteConfig_f, 4(%esp)\n" /* line 2778 */
        "movl $0x2168c4, (%esp)\n" /* "writeconfig" */
        "calll Cmd_AddCommand\n"
        "movl $Com_WriteDefaults_f, 4(%esp)\n" /* line 2779 */
        "movl $0x2168d0, (%esp)\n" /* "writedefaults" */
        "calll Cmd_AddCommand\n"
        "calll getBuildNumber\n" /* line 2781 */
        "movl $0x2167c8, 0x10(%esp)\n" /* "MacOSXS-i386" */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2167d8, 8(%esp)\n" /* "1.0" */
        "movl $0x2167dc, 4(%esp)\n" /* "CoD2 MP" */
        "movl $0x2168e0, (%esp)\n" /* "%s %s build %s %s" */
        "calll va\n"
        "movl %eax, %ebx\n" /* s */
        "movl $0x1040, 8(%esp)\n" /* line 2782 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x2168f4, (%esp)\n" /* "version" */
        "calll Dvar_RegisterString\n"
        "movl %eax, version\n"
        "movl %ebx, 4(%esp)\n" /* line 2783 | s */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0x1044, 8(%esp)\n" /* line 2785 */
        "movl $0x2167d8, 4(%esp)\n" /* "1.0" */
        "movl $0x2168fc, (%esp)\n" /* "shortversion" */
        "calll Dvar_RegisterString\n"
        "movl %eax, shortversion\n"
        "calll FxMem_Init\n" /* line 2795 */
        "calll Sys_Init\n" /* line 2797 */
        "jmp .Lf315d6_00031ae2\n"
        ".Lf315d6_00031a8d:\n"
        "movl printedWarning, %eax\n" /* line 1433 */
        "testl %eax, %eax\n"
        "je .Lf315d6_00031b4d\n"
        ".Lf315d6_00031a9a:\n"
        "movl 0x14(%ebx), %eax\n" /* line 1439 */
        "testl %eax, %eax\n"
        "je .Lf315d6_00031aa9\n"
        "movl %eax, (%esp)\n" /* line 1441 */
        "calll Z_FreeInternal\n"
        ".Lf315d6_00031aa9:\n"
        "addl $1, com_pushedEventsTail\n" /* line 1443 */
        "movl com_pushedEventsHead, %edx\n"
        ".Lf315d6_00031ab6:\n"
        "movl %edi, -0x30(%ebp)\n" /* line 1450 */
        "movl %esi, -0x2c(%ebp)\n"
        "movl %edi, (%ebx)\n"
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
        ".Lf315d6_00031ae2:\n"
        "leal -0x58(%ebp), %eax\n" /* line 1797 */
        "movl %eax, (%esp)\n"
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x58(%ebp), %edi\n"
        "movl %edi, -0x30(%ebp)\n"
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
        "je .Lf315d6_00031b92\n"
        "movl com_pushedEventsHead, %edx\n" /* line 1427 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal com_pushedEvents(, %eax, 8), %ebx\n"
        "movl %edx, %eax\n" /* line 1429 */
        "subl com_pushedEventsTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lf315d6_00031a8d\n"
        "movl $0, printedWarning\n" /* line 1447 */
        "jmp .Lf315d6_00031ab6\n"
        ".Lf315d6_00031b4d:\n"
        "movl $1, printedWarning\n" /* line 1435 */
        "movl $0x2160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf315d6_00031a9a\n"
        ".Lf315d6_00031b68:\n"
        "movl com_numConsoleLines, %eax\n" /* line 1228 */
        "cmpl $0x20, %eax\n"
        "je .Lf315d6_00031672\n"
        "leal 1(%ebx), %edx\n" /* line 1232 */
        "movl %edx, com_consoleLines(, %eax, 4)\n"
        "addl $1, %eax\n" /* line 1233 */
        "movl %eax, com_numConsoleLines\n"
        "movb $0, (%ebx)\n" /* line 1234 */
        "movl %edx, %ebx\n"
        "jmp .Lf315d6_00031651\n"
        ".Lf315d6_00031b92:\n"
        "movl %edi, %eax\n" /* line 2800 */
        "andl $0xffff, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Netchan_Init\n"
        "calll Scr_Init\n" /* line 2803 */
        "movl com_developer, %eax\n" /* line 2441 */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf315d6_00031bc2\n"
        "movl com_logfile, %eax\n"
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf315d6_00031dbf\n"
        ".Lf315d6_00031bc2:\n"
        "movl $1, %ecx\n"
        ".Lf315d6_00031bc7:\n"
        "movl %edx, 8(%esp)\n" /* line 2443 */
        "movl com_developer_script, %eax\n"
        "movzbl 8(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll Scr_Settings\n"
        "calll XAnimInit\n" /* line 2807 */
        "calll DObjInit\n" /* line 2809 */
        "calll SV_Init\n" /* line 2811 */
        "calll NET_Init\n" /* line 2813 */
        "movl 0x195ec98, %ebx\n" /* line 2817 | s */
        "movl (%ebx), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll Dvar_ClearModified\n"
        "movl (%ebx), %eax\n" /* line 2818 | s */
        "movl 8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf315d6_00031c66\n"
        "jmp .Lf315d6_00031e3b\n"
        ".Lf315d6_00031c12:\n"
        "movl printedWarning, %eax\n" /* line 1433 */
        "testl %eax, %eax\n"
        "je .Lf315d6_00031cd1\n"
        ".Lf315d6_00031c1f:\n"
        "movl 0x14(%ebx), %eax\n" /* line 1439 */
        "testl %eax, %eax\n"
        "je .Lf315d6_00031c2e\n"
        "movl %eax, (%esp)\n" /* line 1441 */
        "calll Z_FreeInternal\n"
        ".Lf315d6_00031c2e:\n"
        "addl $1, com_pushedEventsTail\n" /* line 1443 */
        "movl com_pushedEventsHead, %edx\n"
        ".Lf315d6_00031c3b:\n"
        "movl %edi, -0x30(%ebp)\n" /* line 1450 */
        "movl %esi, -0x2c(%ebp)\n"
        "movl %edi, (%ebx)\n"
        "movl %esi, 4(%ebx)\n"
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
        ".Lf315d6_00031c66:\n"
        "leal -0x78(%ebp), %eax\n" /* line 1797 */
        "movl %eax, (%esp)\n"
        "calll Sys_GetEvent\n"
        "subl $4, %esp\n"
        "movl -0x78(%ebp), %edi\n"
        "movl %edi, -0x30(%ebp)\n"
        "movl -0x74(%ebp), %esi\n"
        "movl %esi, -0x2c(%ebp)\n"
        "movl -0x70(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %esi, %esi\n" /* line 1798 */
        "je .Lf315d6_00031cec\n"
        "movl com_pushedEventsHead, %edx\n" /* line 1427 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal com_pushedEvents(, %eax, 8), %ebx\n"
        "movl %edx, %eax\n" /* line 1429 */
        "subl com_pushedEventsTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lf315d6_00031c12\n"
        "movl $0, printedWarning\n" /* line 1447 */
        "jmp .Lf315d6_00031c3b\n"
        ".Lf315d6_00031cd1:\n"
        "movl $1, printedWarning\n" /* line 1435 */
        "movl $0x2160fc, (%esp)\n" /* line 1436 */
        "calll Com_Printf\n"
        "jmp .Lf315d6_00031c1f\n"
        ".Lf315d6_00031cec:\n"
        "movl %edi, com_frameTime\n" /* line 2842 */
        "movl com_numConsoleLines, %esi\n" /* line 1325 */
        "testl %esi, %esi\n"
        "jle .Lf315d6_00031d5a\n"
        "xorl %esi, %esi\n"
        "movl $com_consoleLines, %ebx\n"
        "jmp .Lf315d6_00031d13\n"
        ".Lf315d6_00031d05:\n"
        "addl $1, %esi\n"
        "addl $4, %ebx\n"
        "cmpl com_numConsoleLines, %esi\n"
        "jge .Lf315d6_00031d5a\n"
        ".Lf315d6_00031d13:\n"
        "movl (%ebx), %eax\n" /* line 1327 */
        "testl %eax, %eax\n"
        "je .Lf315d6_00031d05\n"
        "cmpb $0, (%eax)\n"
        "je .Lf315d6_00031d05\n"
        "movl $3, 8(%esp)\n" /* line 1333 */
        "movl $0x2160dc, 4(%esp)\n" /* "set" */
        "movl %eax, (%esp)\n"
        "calll I_strnicmp\n"
        "movl (%ebx), %eax\n" /* line 1337 */
        "movl %eax, (%esp)\n"
        "calll Cbuf_AddText\n"
        "movl $0x2160e8, (%esp)\n" /* line 1338 */
        "calll Cbuf_AddText\n"
        "addl $1, %esi\n" /* line 1325 */
        "addl $4, %ebx\n"
        "cmpl com_numConsoleLines, %esi\n"
        "jl .Lf315d6_00031d13\n"
        ".Lf315d6_00031d5a:\n"
        "movl 0x195ec98, %esi\n" /* line 2856 */
        "movl (%esi), %eax\n"
        "movl 8(%eax), %ebx\n" /* s */
        "testl %ebx, %ebx\n" /* s */
        "je .Lf315d6_00031de6\n"
        "calll Sys_LoadingKeepAlive\n" /* line 2867 */
        "movl (%esi), %eax\n" /* line 2872 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf315d6_00031e1c\n"
        ".Lf315d6_00031d7b:\n"
        "movl 8(%eax), %edx\n" /* line 2475 */
        "testl %edx, %edx\n"
        "jne .Lf315d6_00031d91\n"
        "movl com_introPlayed, %eax\n" /* line 2479 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf315d6_00031f24\n"
        ".Lf315d6_00031d91:\n"
        "movl $1, com_fullyInitialized\n" /* line 2896 */
        "movl $0x216950, (%esp)\n" /* line 2897 */
        "calll Com_Printf\n"
        "calll Cbuf_Execute\n" /* line 2904 */
        "movl com_sv_running, %eax\n" /* line 2906 */
        "cmpb $0, 8(%eax)\n"
        "je .Lf315d6_00031dc6\n"
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 2908 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf315d6_00031dbf:\n"
        "xorl %ecx, %ecx\n" /* line 2441 */
        "jmp .Lf315d6_00031bc7\n"
        ".Lf315d6_00031dc6:\n"
        "movl $0x2157b8, 4(%esp)\n" /* line 3487 */
        "movl $0x2157b8, (%esp)\n"
        "calll UI_SetMap\n"
        /* } scope */
        "leal -0xc(%ebp), %esp\n" /* line 2908 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp CL_StartHunkUsers\n" /* line 3490 */
        ".Lf315d6_00031de6:\n"
        "movl 0x195ecac, %ebx\n" /* line 2860 | s */
        "movl $1, 0x108(%ebx)\n" /* s */
        "calll CL_InitRenderer\n" /* line 2861 */
        "movl $1, 0x10c(%ebx)\n" /* line 2864 | s */
        "calll SND_Init\n" /* line 2865 */
        "calll Sys_LoadingKeepAlive\n" /* line 2867 */
        "movl (%esi), %eax\n" /* line 2872 */
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lf315d6_00031d7b\n"
        ".Lf315d6_00031e1c:\n"
        "movl $0, 4(%esp)\n" /* line 2875 */
        "movl com_viewlog, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "movl (%esi), %eax\n"
        "jmp .Lf315d6_00031d7b\n"
        ".Lf315d6_00031e3b:\n"
        "calll CL_InitOnceForAllClients\n" /* line 2825 */
        "movl $0, (%esp)\n" /* line 2829 */
        "calll CL_SwitchToLocalClient\n"
        "calll CL_Init\n" /* line 2830 */
        "movl $0, (%esp)\n" /* line 2832 */
        "calll CL_SwitchToLocalClient\n"
        "movl $0, 4(%esp)\n" /* line 2834 */
        "movl com_viewlog, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "jmp .Lf315d6_00031c66\n"
        ".Lf315d6_00031e7a:\n"
        "movl $0x1040, 0x10(%esp)\n" /* line 2537 */
        "movl $2, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x21675c, (%esp)\n" /* "dedicated" */
        "calll Dvar_RegisterInt\n"
        "jmp .Lf315d6_000316e2\n"
        ".Lf315d6_00031eab:\n"
        "movl $Com_Error_f, 4(%esp)\n" /* line 2772 */
        "movl $0x2168a4, (%esp)\n" /* "error" */
        "calll Cmd_AddCommand\n"
        "movl $Com_Crash_f, 4(%esp)\n" /* line 2773 */
        "movl $0x2168ac, (%esp)\n" /* "crash" */
        "calll Cmd_AddCommand\n"
        "movl $Com_Freeze_f, 4(%esp)\n" /* line 2774 */
        "movl $0x2168b4, (%esp)\n" /* "freeze" */
        "calll Cmd_AddCommand\n"
        "jmp .Lf315d6_000319c8\n"
        ".Lf315d6_00031eec:\n"
        "calll Sys_HideSplashWindow\n" /* line 2738 */
        "movl $1, 4(%esp)\n" /* line 2742 */
        "movl $1, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "calll Sys_NormalExit\n" /* line 2746 */
        "jmp .Lf315d6_000319a1\n"
        ".Lf315d6_00031f0f:\n"
        "movl $1, 4(%esp)\n" /* line 2581 */
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "jmp .Lf315d6_00031936\n"
        ".Lf315d6_00031f24:\n"
        "movl $0x21690c, (%esp)\n" /* line 2487 */
        "calll Cbuf_AddText\n"
        "movl $0x21691c, 4(%esp)\n" /* line 2488 */
        "movl nextmap, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $1, 4(%esp)\n" /* line 2491 */
        "movl com_introPlayed, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "jmp .Lf315d6_00031d91\n"
    );
}

/* line 2916 */
__attribute__((naked))
void Com_Init(char *commandLine)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2916 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $2, (%esp)\n" /* line 2918 */
        "calll Sys_GetValue\n"
        "movl %eax, (%esp)\n"
        "calll setjmp\n"
        "testl %eax, %eax\n"
        "jne .Lf31f60_00031f8b\n"
        "movl 8(%ebp), %eax\n" /* line 2920 | commandLine */
        "movl %eax, (%esp)\n"
        "calll Com_Init_Try_Block_Function\n"
        "leave\n" /* line 2926 */
        "retl\n"
        ".Lf31f60_00031f8b:\n"
        "movl $com_errorMessage, 4(%esp)\n" /* line 2924 */
        "movl $0x216978, (%esp)\n" /* "Error during initialization:
%s
" */
        "calll va\n"
        "movl %eax, (%esp)\n"
        "calll Sys_Error\n"
        "leave\n" /* line 2926 */
        "retl\n"
    );
}

