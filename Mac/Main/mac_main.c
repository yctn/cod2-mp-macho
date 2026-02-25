/* ASM dump from: mac_main.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_main.cpp */

#include "common_types.h"
#include "imports.h"

extern struct WinVars_t g_wv; /* 0x0 */
extern byte sys_packetReceived[16384]; /* 0x0 */
static SysInfo sys_info; /* 0x7efc80 */
static const dvar_t *sys_cpuGHz; /* 0x7f16b4 */
static const dvar_t *sys_sysMB; /* 0x7f16b0 */
static const dvar_t *sys_gpu; /* 0x7f16ac */
static const dvar_t *sys_configSum; /* 0x7f16a8 */
static sysEvent_t eventQue[256]; /* 0x7efea0 */
static int eventHead; /* 0x7f16a4 */
static int eventTail; /* 0x7f16a0 */

void Sys_GetInfo(SysInfo *info);
void Sys_ArchiveInfo(int checksum);
void Sys_DirectXFatalError(void);
void Sys_OutOfMemErrorInternal(const char *filename, int line);
void Sys_StartProcess(const char *exeName, qboolean doexit);
void Sys_Error(const char *error);
void Sys_NormalExit(void);
void Sys_Print(const char *msg);
char * Sys_GetClipboardData(void);
void Sys_QueEvent(int time, sysEventType_t type, int value, int value2, int ptrLength, void *ptr);
static void Sys_In_Restart_f(void);
static void Sys_Net_Restart_f(void);
void Sys_Init(void);
void Sys_LoadingKeepAlive(void);
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
void Sys_Quit(void);
sysEvent_t Sys_GetEvent(void);
static Bool Sys_ShouldUpdateForInfoChange(void);
Bool Sys_HasConfigureChecksumChanged(int checksum);
Bool Sys_HasInfoChanged(void);

/* line 88 */
__attribute__((naked))
void Sys_GetInfo(SysInfo *info)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x210, 8(%esp)\n" /* line 90 */
        "movl $sys_info, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* info */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leave\n" /* line 91 */
        "retl\n"
    );
}

/* line 177 */
__attribute__((naked))
void Sys_ArchiveInfo(int checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 177 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 107 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222aa8, (%esp)\n" /* "sys_cpuGHz" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, sys_cpuGHz\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 108 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ab4, (%esp)\n" /* "sys_sysMB" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_sysMB\n"
        "movl $0x1011, 8(%esp)\n" /* line 109 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x222ac0, (%esp)\n" /* "sys_gpu" */
        "calll Dvar_RegisterString\n"
        "movl %eax, sys_gpu\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 110 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ac8, (%esp)\n" /* "sys_configSum" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_configSum\n"
        "cvtsd2ss sys_info, %xmm0\n" /* line 181 */
        "movss %xmm0, 4(%esp)\n"
        "movl sys_cpuGHz, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFloat\n"
        "movl 0x7efc88, %eax\n" /* line 182 */
        "movl %eax, 4(%esp)\n"
        "movl sys_sysMB, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl $0x7efc8d, 4(%esp)\n" /* line 183 */
        "movl sys_gpu, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl 8(%ebp), %eax\n" /* line 184 | checksum */
        "movl %eax, 4(%esp)\n"
        "movl sys_configSum, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "leave\n" /* line 185 */
        "retl\n"
    );
}

/* line 207 */
__attribute__((naked))
void Sys_DirectXFatalError(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 207 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl $0x222ad8, (%esp)\n" /* line 209 */
        "calll Win_LocalizeRef\n"
        "movl %eax, %ebx\n"
        "movl $0x222af0, (%esp)\n" /* "WIN_DIRECTX_INIT_BODY" */
        "calll Win_LocalizeRef\n"
        "movl $0x10, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll MessageBoxA\n"
        "movl $0xffffffff, (%esp)\n" /* line 211 */
        "calll exit\n"
    );
}

/* line 216 */
__attribute__((naked))
void Sys_OutOfMemErrorInternal(const char *filename, int line)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 216 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 218 | line */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "movl $0x222b08, (%esp)\n" /* "Out of memory: filename '%s', line %d
" */
        "calll Com_Printf\n"
        "movl $0x222b30, (%esp)\n" /* line 219 */
        "calll Win_LocalizeRef\n"
        "movl %eax, %ebx\n"
        "movl $0x222b48, (%esp)\n" /* "WIN_OUT_OF_MEM_BODY" */
        "calll Win_LocalizeRef\n"
        "movl $0x10, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll MessageBoxA\n"
        "movl $0xffffffff, (%esp)\n" /* line 220 */
        "calll exit\n"
    );
}

/* line 225 */
__attribute__((naked))
void Sys_StartProcess(const char *exeName, qboolean doexit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 225 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x64, %esp\n"
        "movl 8(%ebp), %ebx\n" /* exeName */
        /* { scope 1 */
        "movl $0x222b5c, 4(%esp)\n" /* line 229 */
        "movl %ebx, (%esp)\n" /* exeName */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lfc3da8_000c3e18\n"
        "leal -0x58(%ebp), %ebx\n" /* line 231 | ref, exeName */
        "movl %ebx, 4(%esp)\n" /* exeName */
        "movl $0x222b64, (%esp)\n" /* "Call of Duty 2.app" */
        "calll MacFolders_GetApplicationFolderItemRef\n"
        ".Lfc3da8_000c3dd9:\n"
        "testl %eax, %eax\n" /* line 243 */
        "je .Lfc3da8_000c3de3\n"
        /* } scope */
        ".Lfc3da8_000c3ddd:\n"
        "addl $0x64, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc3da8_000c3de3:\n"
        "movl $0, 4(%esp)\n" /* line 257 */
        "movl %ebx, (%esp)\n" /* exeName */
        "calll LSOpenFSRef\n"
        "testl %eax, %eax\n" /* line 259 */
        "jne .Lfc3da8_000c3ddd\n"
        "movl 0xc(%ebp), %eax\n" /* line 261 | doexit */
        "testl %eax, %eax\n"
        "je .Lfc3da8_000c3ddd\n"
        "movl $0x222bc4, 4(%esp)\n" /* line 263 */
        "movl $2, (%esp)\n"
        "calll Cbuf_ExecuteText\n"
        /* } scope */
        "addl $0x64, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc3da8_000c3e18:\n"
        "movl $0x222b78, 4(%esp)\n" /* line 233 */
        "movl %ebx, (%esp)\n" /* exeName */
        "calll strstr\n"
        "testl %eax, %eax\n"
        "je .Lfc3da8_000c3e41\n"
        "leal -0x58(%ebp), %ebx\n" /* line 235 | ref, exeName */
        "movl %ebx, 4(%esp)\n" /* exeName */
        "movl $0x222b80, (%esp)\n" /* "Call of Duty 2 Multiplayer.app" */
        "calll MacFolders_GetApplicationFolderItemRef\n"
        "jmp .Lfc3da8_000c3dd9\n"
        ".Lfc3da8_000c3e41:\n"
        "movl %ebx, 4(%esp)\n" /* line 239 | exeName */
        "movl $0x222ba0, (%esp)\n" /* "Trying to start unknown process: %s" */
        "calll game_dprintf\n"
        "jmp .Lfc3da8_000c3ddd\n"
    );
}

/* line 338 */
__attribute__((naked))
void Sys_Error(const char *error)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 338 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x1024, %esp\n"
        /* { scope 1 */
        "movl 0x195eea4, %eax\n" /* line 352 */
        "movl $1, (%eax)\n"
        "leal 0xc(%ebp), %eax\n" /* line 354 */
        "movl %eax, -0xc(%ebp)\n" /* argptr */
        "movl %eax, 0xc(%esp)\n" /* line 355 */
        "movl 8(%ebp), %eax\n" /* error */
        "movl %eax, 8(%esp)\n"
        "movl $__mh_execute_header, 4(%esp)\n"
        "leal -0x100c(%ebp), %ebx\n" /* text */
        "movl %ebx, (%esp)\n"
        "calll vsnprintf\n"
        "calll Sys_DestroySplashWindow\n" /* line 192 */
        "movl $1, (%esp)\n" /* line 195 */
        "calll timeEndPeriod\n"
        "calll IN_Shutdown\n" /* line 198 */
        "calll CL_ShutdownHunkUsers\n" /* line 200 */
        "calll CL_ShutdownRef\n" /* line 201 */
        "movl %ebx, (%esp)\n" /* line 362 */
        "calll Conbuf_AppendText\n"
        "movl $0x2160e8, (%esp)\n" /* line 363 */
        "calll Conbuf_AppendText\n"
        "movl %ebx, (%esp)\n" /* line 364 */
        "calll Sys_SetErrorText\n"
        "movl $1, 4(%esp)\n" /* line 365 */
        "movl $1, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "movl 0x195eea0, %ebx\n"
        ".Lfc3e54_000c3ee6:\n"
        "calll CMacGameEngine_ProcessAllEvents\n" /* line 373 */
        "testb %al, %al\n"
        "jne .Lfc3e54_000c3ef4\n"
        "cmpb $0, (%ebx)\n"
        "jne .Lfc3e54_000c3ee6\n"
        ".Lfc3e54_000c3ef4:\n"
        "calll Com_Quit_f\n" /* line 374 */
        "jmp .Lfc3e54_000c3ee6\n"
    );
}

/* line 677 */
__attribute__((naked))
void Sys_NormalExit(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 677 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 682 */
        "retl\n"
    );
}

/* line 428 */
__attribute__((naked))
void Sys_Print(const char *msg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 428 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 431 */
        "jmp Conbuf_AppendText\n" /* line 430 */
    );
}

/* line 435 */
__attribute__((naked))
char * Sys_GetClipboardData(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 435 */
        "movl %esp, %ebp\n"
        "movl $0x2157b8, %eax\n" /* line 439 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 451 */
__attribute__((naked))
void Sys_QueEvent(int time, sysEventType_t type, int value, int value2, int ptrLength, void *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 451 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* time */
        /* { scope 1 */
        "movl eventHead, %edx\n" /* line 455 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal eventQue(, %eax, 8), %ebx\n" /* ev */
        "movl %edx, %eax\n" /* line 456 */
        "subl eventTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lfc3f18_000c3f7f\n"
        ".Lfc3f18_000c3f45:\n"
        "leal 1(%edx), %eax\n" /* line 467 */
        "movl %eax, eventHead\n"
        "testl %esi, %esi\n" /* line 469 | time */
        "jne .Lfc3f18_000c3f58\n"
        "calll Sys_Milliseconds\n" /* line 471 */
        "movl %eax, %esi\n" /* time */
        ".Lfc3f18_000c3f58:\n"
        "movl %esi, (%ebx)\n" /* line 474 | time, ev */
        "movl 0xc(%ebp), %eax\n" /* line 475 | type */
        "movl %eax, 4(%ebx)\n" /* ev */
        "movl 0x10(%ebp), %eax\n" /* line 476 | value */
        "movl %eax, 8(%ebx)\n" /* ev */
        "movl 0x14(%ebp), %eax\n" /* line 477 | value2 */
        "movl %eax, 0xc(%ebx)\n" /* ev */
        "movl 0x18(%ebp), %eax\n" /* line 478 | ptrLength */
        "movl %eax, 0x10(%ebx)\n" /* ev */
        "movl 0x1c(%ebp), %eax\n" /* line 479 | ptr */
        "movl %eax, 0x14(%ebx)\n" /* ev */
        /* } scope */
        "addl $0x10, %esp\n" /* line 480 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfc3f18_000c3f7f:\n"
        "movl $0x222bcc, (%esp)\n" /* line 458 */
        "calll Com_Printf\n"
        "movl 0x14(%ebx), %eax\n" /* line 460 | ev */
        "testl %eax, %eax\n"
        "je .Lfc3f18_000c3f9a\n"
        "movl %eax, (%esp)\n" /* line 462 */
        "calll Z_FreeInternal\n"
        ".Lfc3f18_000c3f9a:\n"
        "addl $1, eventTail\n" /* line 464 */
        "movl eventHead, %edx\n"
        "jmp .Lfc3f18_000c3f45\n"
    );
}

/* line 600 */
static __attribute__((naked))
void Sys_In_Restart_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 600 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll IN_Shutdown\n" /* line 602 */
        "leave\n" /* line 604 */
        "jmp IN_Init\n" /* line 603 */
    );
}

/* line 610 */
static __attribute__((naked))
void Sys_Net_Restart_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 610 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 613 */
        "jmp NET_Restart\n" /* line 612 */
    );
}

/* line 618 */
__attribute__((naked))
void Sys_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 618 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, (%esp)\n" /* line 624 */
        "calll timeBeginPeriod\n"
        "movl $Sys_In_Restart_f, 4(%esp)\n" /* line 627 */
        "movl $0x222be4, (%esp)\n" /* "in_restart" */
        "calll Cmd_AddCommand\n"
        "movl $Sys_Net_Restart_f, 4(%esp)\n" /* line 630 */
        "movl $0x222bf0, (%esp)\n" /* "net_restart" */
        "calll Cmd_AddCommand\n"
        "movsd sys_info, %xmm0\n" /* line 662 */
        "movsd %xmm0, 4(%esp)\n"
        "movl $0x222bfc, (%esp)\n" /* "Measured CPU speed is %.2lf GHz
" */
        "calll Com_Printf\n"
        "movl 0x7efc88, %eax\n" /* line 663 */
        "movl %eax, 4(%esp)\n"
        "movl $0x222c20, (%esp)\n" /* "System memory is %i MB (capped at 1 GB)
" */
        "calll Com_Printf\n"
        "movl $0x7efc8d, 4(%esp)\n" /* line 664 */
        "movl $0x222c4c, (%esp)\n" /* "Video card is "%s"
" */
        "calll Com_Printf\n"
        "movl $0x2157b8, %eax\n" /* line 666 */
        "cmpb $0, 0x7efc8c\n"
        "movl $0x222c60, %edx\n" /* "not " */
        "cmovel %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x222c68, (%esp)\n" /* "Streaming SIMD Extensions (SSE) %ssupported
" */
        "calll Com_Printf\n"
        "movl $0x2160e8, (%esp)\n" /* line 668 */
        "calll Com_Printf\n"
        "leave\n" /* line 673 */
        "jmp IN_Init\n" /* line 671 */
    );
}

/* line 499 */
__attribute__((naked))
void Sys_LoadingKeepAlive(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0, (%esp)\n" /* line 501 */
        "calll UpdateSystemActivity\n"
        "leave\n" /* line 503 */
        "retl\n"
    );
}

/* line 698 */
__attribute__((naked))
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 698 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x114, %esp\n"
        "movl 8(%ebp), %ebx\n" /* hInstance */
        "calll Sys_InitMainThread\n" /* line 706 */
        "calll Win_InitLocalization\n" /* line 712 */
        "calll Dvar_Init\n" /* line 741 */
        "calll Sys_CpuGHz\n" /* line 135 */
        "fstpl sys_info\n"
        "calll Sys_SystemMemoryMB\n" /* line 136 */
        "movl %eax, 0x7efc88\n"
        "movl $0x7efc8d, 4(%esp)\n" /* line 137 */
        "movl $0x200, (%esp)\n"
        "calll Sys_DetectVideoCard\n"
        "calll Sys_SupportsSSE\n" /* line 138 */
        "movb %al, 0x7efc8c\n"
        "movl $__mh_execute_header, 8(%esp)\n" /* line 141 */
        "movl $0, 4(%esp)\n"
        "movl $0x222c98, (%esp)\n" /* "sys_SSE" */
        "calll Dvar_RegisterBool\n"
        "movzbl 0x7efc8c, %edx\n" /* line 142 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetBool\n"
        "movl %ebx, 0x1150f8c\n" /* line 746 | hInstance */
        "movl %ebx, (%esp)\n" /* line 751 | hInstance */
        "calll Sys_CreateConsole\n"
        "calll Sys_CreateSplashWindow\n" /* line 756 */
        "calll Sys_ShowSplashWindow\n" /* line 757 */
        "calll Sys_Milliseconds\n" /* line 765 */
        "calll Sys_InitStreamThread\n" /* line 774 */
        "movl 0x10(%ebp), %eax\n" /* line 777 | lpCmdLine */
        "movl %eax, (%esp)\n"
        "calll Com_Init\n"
        "movl $0x100, 4(%esp)\n" /* line 690 */
        "leal -0x108(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll getcwd\n"
        "movl %ebx, 4(%esp)\n" /* line 691 */
        "movl $0x222ca0, (%esp)\n" /* "Working directory: %s
" */
        "calll Com_Printf\n"
        "movl 0x195ec98, %ebx\n" /* line 784 | hInstance */
        "movl (%ebx), %eax\n" /* hInstance */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfc408e_000c417f\n"
        "movl 0x195eea8, %eax\n" /* line 787 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfc408e_000c41a7\n"
        "movl (%ebx), %eax\n" /* hInstance */
        ".Lfc408e_000c417f:\n"
        "testl %eax, %eax\n" /* line 802 */
        "je .Lfc408e_000c418a\n"
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lfc408e_000c4199\n"
        ".Lfc408e_000c418a:\n"
        "calll Com_Frame\n" /* line 822 */
        "movl 0x195ec98, %ebx\n" /* hInstance */
        "movl (%ebx), %eax\n" /* hInstance */
        "jmp .Lfc408e_000c417f\n"
        ".Lfc408e_000c4199:\n"
        "movl $5, (%esp)\n" /* line 804 */
        "calll WinSleep\n"
        "jmp .Lfc408e_000c418a\n"
        ".Lfc408e_000c41a7:\n"
        "movl $0, 4(%esp)\n" /* line 789 */
        "movl $0, (%esp)\n"
        "calll Sys_ShowConsole\n"
        "movl (%ebx), %eax\n" /* hInstance */
        "jmp .Lfc408e_000c417f\n"
    );
}

/* line 390 */
__attribute__((naked))
void Sys_Quit(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 390 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $1, (%esp)\n" /* line 396 */
        "calll timeEndPeriod\n"
        "calll IN_Shutdown\n" /* line 399 */
        "calll Key_Shutdown\n" /* line 400 */
        "calll Sys_DestroyConsole\n" /* line 403 */
        "calll Win_ShutdownLocalization\n" /* line 406 */
        "calll RefreshQuitOnErrorCondition\n" /* line 408 */
        "calll Dvar_Shutdown\n" /* line 409 */
        "calll Cmd_Shutdown\n" /* line 410 */
        "calll Con_Shutdown\n" /* line 411 */
        "calll Com_ShutdownEvents\n" /* line 413 */
        ".Lfc41c0_000c41ff:\n"
        "movl eventTail, %edx\n" /* line 488 */
        "cmpl %edx, eventHead\n"
        "jle .Lfc41c0_000c423c\n"
        ".Lfc41c0_000c420d:\n"
        "leal 1(%edx), %eax\n" /* line 491 */
        "movl %eax, eventTail\n"
        "movzbl %dl, %eax\n" /* line 492 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl 0x7efeb4(, %eax, 8), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc41c0_000c41ff\n"
        "movl %eax, (%esp)\n" /* line 493 */
        "calll Z_FreeInternal\n"
        "movl eventTail, %edx\n" /* line 488 */
        "cmpl %edx, eventHead\n"
        "jg .Lfc41c0_000c420d\n"
        ".Lfc41c0_000c423c:\n"
        "calll MacPreferences_Synchronize\n" /* line 421 */
        "movl $0, (%esp)\n" /* line 423 */
        "calll exit\n"
    );
}

/* line 507 */
__attribute__((naked))
sysEvent_t Sys_GetEvent(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 507 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        "movl 8(%ebp), %esi\n"
        /* { scope 1: len */
        "movl eventTail, %edx\n" /* line 519 */
        "cmpl %edx, eventHead\n"
        "jle .Lfc424e_000c42ba\n"
        ".Lfc424e_000c4268:\n"
        "leal 1(%edx), %eax\n" /* line 585 */
        "movl %eax, eventTail\n"
        "movzbl %dl, %eax\n" /* line 586 */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $3, %eax\n"
        "movl eventQue(%eax), %edx\n"
        "movl %edx, (%esi)\n"
        "movl 0x7efea4(%eax), %edx\n"
        "movl %edx, 4(%esi)\n"
        "movl 0x7efea8(%eax), %edx\n"
        "movl %edx, 8(%esi)\n"
        "movl 0x7efeac(%eax), %edx\n"
        "movl %edx, 0xc(%esi)\n"
        "movl 0x7efeb0(%eax), %edx\n"
        "movl %edx, 0x10(%esi)\n"
        "movl 0x7efeb4(%eax), %eax\n"
        "movl %eax, 0x14(%esi)\n"
        /* } scope */
        ".Lfc424e_000c42ae:\n"
        "movl %esi, %eax\n" /* line 595 */
        "addl $0x6c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl $4\n"
        /* { scope 1: len */
        ".Lfc424e_000c42ba:\n"
        "calll CMacGameEngine_ProcessAllEvents\n" /* line 526 */
        "testb %al, %al\n"
        "jne .Lfc424e_000c43dc\n"
        ".Lfc424e_000c42c7:\n"
        "calll Sys_ConsoleInput\n" /* line 552 */
        "movl %eax, -0x60(%ebp)\n" /* s */
        "testl %eax, %eax\n" /* line 553 */
        "je .Lfc424e_000c4362\n"
        "movl %eax, %edi\n"
        "cld\n" /* line 558 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, -0x64(%ebp)\n"
        "notl -0x64(%ebp)\n"
        "movl -0x64(%ebp), %ebx\n" /* ev */
        "subl $1, %ebx\n" /* ev */
        "movl -0x64(%ebp), %eax\n" /* line 559 */
        "movl %eax, (%esp)\n"
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n"
        "movl %ebx, 8(%esp)\n" /* line 560 | ev */
        "movl -0x60(%ebp), %eax\n" /* s */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll I_strncpyz\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl eventHead, %edx\n" /* line 455 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal eventQue(, %eax, 8), %ebx\n" /* ev */
        "movl %edx, %eax\n" /* line 456 */
        "subl eventTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lfc424e_000c447f\n"
        ".Lfc424e_000c4335:\n"
        "leal 1(%edx), %eax\n" /* line 467 */
        "movl %eax, eventHead\n"
        "calll Sys_Milliseconds\n" /* line 471 */
        "movl %eax, (%ebx)\n" /* line 474 | ev */
        "movl $4, 4(%ebx)\n" /* line 475 | ev */
        "movl $0, 8(%ebx)\n" /* line 476 | ev */
        "movl $0, 0xc(%ebx)\n" /* line 477 | ev */
        "movl -0x64(%ebp), %eax\n" /* line 478 */
        "movl %eax, 0x10(%ebx)\n" /* ev */
        "movl %edi, 0x14(%ebx)\n" /* line 479 | ev */
        /* } scope */
        /* } scope */
        ".Lfc424e_000c4362:\n"
        "movl $0x4000, 8(%esp)\n" /* line 566 */
        "movl $sys_packetReceived, 4(%esp)\n"
        "leal -0x54(%ebp), %ebx\n" /* netmsg, ev */
        "movl %ebx, (%esp)\n" /* ev */
        "calll MSG_Init\n"
        "movl %ebx, 4(%esp)\n" /* line 567 | ev */
        "leal -0x24(%ebp), %eax\n" /* adr */
        "movl %eax, (%esp)\n"
        "calll NET_GetPacket\n"
        "testl %eax, %eax\n"
        "jne .Lfc424e_000c43e6\n"
        ".Lfc424e_000c4390:\n"
        "movl eventTail, %edx\n" /* line 583 */
        "cmpl %edx, eventHead\n"
        "jg .Lfc424e_000c4268\n"
        "leal -0x3c(%ebp), %edi\n" /* line 591 | ev */
        "cld\n"
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n"
        "calll Sys_Milliseconds\n" /* line 592 */
        "movl %eax, -0x3c(%ebp)\n" /* ev */
        "movl %eax, (%esi)\n" /* line 594 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x10(%esi)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x14(%esi)\n"
        "jmp .Lfc424e_000c42ae\n"
        ".Lfc424e_000c43dc:\n"
        "calll Com_Quit_f\n" /* line 528 */
        "jmp .Lfc424e_000c42c7\n"
        /* { scope 2 */
        ".Lfc424e_000c43e6:\n"
        "movl -0x48(%ebp), %eax\n" /* line 574 */
        "subl -0x44(%ebp), %eax\n"
        "addl $0xc, %eax\n"
        "movl %eax, -0x5c(%ebp)\n" /* len */
        "movl %eax, (%esp)\n" /* line 575 */
        "calll Z_MallocInternal\n"
        "movl %eax, %edi\n"
        "movl -0x24(%ebp), %eax\n" /* line 576 | adr */
        "movl %eax, (%edi)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl -0x44(%ebp), %edx\n" /* line 577 */
        "leal 0xc(%edi), %ecx\n"
        "movl -0x48(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "addl -0x50(%ebp), %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl eventHead, %edx\n" /* line 455 */
        "movzbl %dl, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal eventQue(, %eax, 8), %ebx\n" /* ev */
        "movl %edx, %eax\n" /* line 456 */
        "subl eventTail, %eax\n"
        "cmpl $0xff, %eax\n"
        "jg .Lfc424e_000c44ac\n"
        ".Lfc424e_000c444d:\n"
        "leal 1(%edx), %eax\n" /* line 467 */
        "movl %eax, eventHead\n"
        "calll Sys_Milliseconds\n" /* line 471 */
        "movl %eax, (%ebx)\n" /* line 474 | ev */
        "movl $5, 4(%ebx)\n" /* line 475 | ev */
        "movl $0, 8(%ebx)\n" /* line 476 | ev */
        "movl $0, 0xc(%ebx)\n" /* line 477 | ev */
        "movl -0x5c(%ebp), %eax\n" /* line 478 | len */
        "movl %eax, 0x10(%ebx)\n" /* ev */
        "movl %edi, 0x14(%ebx)\n" /* line 479 | ev */
        "jmp .Lfc424e_000c4390\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lfc424e_000c447f:\n"
        "movl $0x222bcc, (%esp)\n" /* line 458 */
        "calll Com_Printf\n"
        "movl 0x14(%ebx), %eax\n" /* line 460 | ev */
        "testl %eax, %eax\n"
        "je .Lfc424e_000c449a\n"
        "movl %eax, (%esp)\n" /* line 462 */
        "calll Z_FreeInternal\n"
        ".Lfc424e_000c449a:\n"
        "addl $1, eventTail\n" /* line 464 */
        "movl eventHead, %edx\n"
        "jmp .Lfc424e_000c4335\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfc424e_000c44ac:\n"
        "movl $0x222bcc, (%esp)\n" /* line 458 */
        "calll Com_Printf\n"
        "movl 0x14(%ebx), %eax\n" /* line 460 | ev */
        "testl %eax, %eax\n"
        "je .Lfc424e_000c44c7\n"
        "movl %eax, (%esp)\n" /* line 462 */
        "calll Z_FreeInternal\n"
        ".Lfc424e_000c44c7:\n"
        "addl $1, eventTail\n" /* line 464 */
        "movl eventHead, %edx\n"
        "jmp .Lfc424e_000c444d\n"
    );
}

/* line 149 */
static __attribute__((naked))
Bool Sys_ShouldUpdateForInfoChange(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 149 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 107 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222aa8, (%esp)\n" /* "sys_cpuGHz" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, sys_cpuGHz\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 108 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ab4, (%esp)\n" /* "sys_sysMB" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_sysMB\n"
        "movl $0x1011, 8(%esp)\n" /* line 109 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x222ac0, (%esp)\n" /* "sys_gpu" */
        "calll Dvar_RegisterString\n"
        "movl %eax, sys_gpu\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 110 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ac8, (%esp)\n" /* "sys_configSum" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_configSum\n"
        "cvtsd2ss sys_info, %xmm0\n" /* line 181 */
        "movss %xmm0, 4(%esp)\n"
        "movl sys_cpuGHz, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetFloat\n"
        "movl 0x7efc88, %eax\n" /* line 182 */
        "movl %eax, 4(%esp)\n"
        "movl sys_sysMB, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl $0x7efc8d, 4(%esp)\n" /* line 183 */
        "movl sys_gpu, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetString\n"
        "movl $0, 4(%esp)\n" /* line 184 */
        "movl sys_configSum, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Dvar_SetInt\n"
        "movl $0x222cb8, (%esp)\n" /* line 154 */
        "calll Win_LocalizeRef\n"
        "movl %eax, %ebx\n"
        "movl $0x222cd4, (%esp)\n" /* "WIN_COMPUTER_CHANGE_BODY" */
        "calll Win_LocalizeRef\n"
        "movl $0x44, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll MessageBoxA\n"
        "cmpl $6, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        "addl $0x24, %esp\n" /* line 158 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 115 */
__attribute__((naked))
Bool Sys_HasConfigureChecksumChanged(int checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* checksum */
        "movl $0x1011, 0x10(%esp)\n" /* line 107 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222aa8, (%esp)\n" /* "sys_cpuGHz" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, sys_cpuGHz\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 108 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ab4, (%esp)\n" /* "sys_sysMB" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_sysMB\n"
        "movl $0x1011, 8(%esp)\n" /* line 109 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x222ac0, (%esp)\n" /* "sys_gpu" */
        "calll Dvar_RegisterString\n"
        "movl %eax, sys_gpu\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 110 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ac8, (%esp)\n" /* "sys_configSum" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_configSum\n"
        "movl 8(%eax), %eax\n" /* line 122 */
        "testl %eax, %eax\n"
        "je .Lfc4636_000c4743\n"
        "cmpl %esi, %eax\n" /* checksum */
        "je .Lfc4636_000c4743\n"
        "movl $0x222cf0, (%esp)\n" /* line 97 */
        "calll Win_LocalizeRef\n"
        "movl %eax, %ebx\n"
        "movl $0x222d0c, (%esp)\n" /* "WIN_CONFIGURE_UPDATED_BODY" */
        "calll Win_LocalizeRef\n"
        "movl $0x44, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll MessageBoxA\n"
        "cmpl $6, %eax\n"
        "sete %al\n"
        "movl %eax, %ebx\n"
        "andl $1, %ebx\n"
        "jmp .Lfc4636_000c4745\n"
        ".Lfc4636_000c4743:\n"
        "xorl %ebx, %ebx\n"
        ".Lfc4636_000c4745:\n"
        "movl sys_configSum, %edx\n" /* line 124 */
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfc4636_000c4756\n"
        "cmpl %esi, %eax\n" /* checksum */
        "je .Lfc4636_000c4762\n"
        ".Lfc4636_000c4756:\n"
        "movl %esi, 4(%esp)\n" /* line 125 | checksum */
        "movl %edx, (%esp)\n"
        "calll Dvar_SetInt\n"
        ".Lfc4636_000c4762:\n"
        "movl %ebx, %eax\n" /* line 127 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 162 */
__attribute__((naked))
Bool Sys_HasInfoChanged(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 162 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 107 */
        "movl $0x7f7fffff, 0xc(%esp)\n"
        "movl $0xff7fffff, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222aa8, (%esp)\n" /* "sys_cpuGHz" */
        "calll Dvar_RegisterFloat\n"
        "movl %eax, sys_cpuGHz\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 108 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ab4, (%esp)\n" /* "sys_sysMB" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_sysMB\n"
        "movl $0x1011, 8(%esp)\n" /* line 109 */
        "movl $0x2157b8, 4(%esp)\n"
        "movl $0x222ac0, (%esp)\n" /* "sys_gpu" */
        "calll Dvar_RegisterString\n"
        "movl %eax, sys_gpu\n"
        "movl $0x1011, 0x10(%esp)\n" /* line 110 */
        "movl $0x7fffffff, 0xc(%esp)\n"
        "movl $0x80000000, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0x222ac8, (%esp)\n" /* "sys_configSum" */
        "calll Dvar_RegisterInt\n"
        "movl %eax, sys_configSum\n"
        "movl sys_cpuGHz, %eax\n" /* line 166 */
        "cvtss2sd 8(%eax), %xmm2\n"
        "movsd sys_info, %xmm1\n"
        "movapd %xmm1, %xmm0\n"
        "mulsd 0x307cc8, %xmm0\n" /* 1.100000023841858 */
        "ucomisd %xmm0, %xmm2\n"
        "ja .Lfc476c_000c4874\n"
        "mulsd 0x307cd0, %xmm1\n" /* 0.8999999761581421 */
        "ucomisd %xmm2, %xmm1\n"
        "ja .Lfc476c_000c4874\n"
        "movl sys_sysMB, %eax\n" /* line 168 */
        "movl 8(%eax), %ecx\n"
        "movl 0x7efc88, %edx\n"
        "leal 0x20(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jg .Lfc476c_000c4874\n"
        "leal -0x20(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jge .Lfc476c_000c487e\n"
        ".Lfc476c_000c4874:\n"
        "calll Sys_ShouldUpdateForInfoChange\n" /* line 171 */
        "movzbl %al, %eax\n"
        "leave\n" /* line 173 */
        "retl\n"
        ".Lfc476c_000c487e:\n"
        "movl $0x7efc8d, 4(%esp)\n" /* line 170 */
        "movl sys_gpu, %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lfc476c_000c4874\n"
        "leave\n" /* line 173 */
        "retl\n"
    );
}

