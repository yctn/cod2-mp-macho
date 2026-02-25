/* ASM dump from: MacWin32.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacWin32.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacMemory.h"
 */

MMRESULT timeBeginPeriod(void);
MMRESULT timeEndPeriod(void);
BOOL QueryPerformanceFrequency(void *lpFrequency);
int MessageBoxA(LPCSTR lpText, LPCSTR lpCaption, UINT uType);
BOOL SetFileAttributesA(LPCSTR lpFileName, DWORD dwFileAttributes);
DWORD GetFileAttributesA(LPCSTR lpFileName);
BOOL SetThreadPriority(HANDLE hThread, int nPriority);
DWORD GetCurrentThreadId(void);
jpeg_alloc WinSleep(DWORD dwMilliseconds);
LONG InterlockedExchangeAdd(volatile LONG *Addend, LONG Value);
LONG InterlockedCompareExchange(volatile LONG *Destination, LONG Exchange, LONG Comperand);
UINT MapVirtualKeyA(UINT uCode, UINT uMapType);
LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType);
int GetSystemMetrics(int nIndex);
BOOL FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData);
DWORD timeGetTime(void);
BOOL QueryPerformanceCounter(void *lpPerformanceCount);
LONG InterlockedExchange(volatile LONG *Target, LONG Value);
HANDLE FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData);
void ZNSt6vectorI6FFItemSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void); /* std_vector<FFItem, std_allocator<FFItem> >__M_insert_aux */

/* line 232 */
__attribute__((naked))
MMRESULT timeBeginPeriod(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 232 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 235 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 241 */
__attribute__((naked))
MMRESULT timeEndPeriod(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 241 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 244 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 321 */
__attribute__((naked))
BOOL QueryPerformanceFrequency(void *lpFrequency)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 321 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 323 | lpFrequency */
        "movl $0xf4240, (%eax)\n"
        "movl $0, 4(%eax)\n"
        "movl $1, %eax\n" /* line 326 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 473 */
__attribute__((naked))
int MessageBoxA(LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 473 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* lpCaption */
        "movl 0x14(%ebp), %eax\n" /* uType */
        /* { scope 1 */
        "movl %eax, %esi\n" /* line 476 | messageType */
        "andl $0xf, %esi\n" /* messageType */
        "andl $0xf0, %eax\n" /* line 477 */
        "movl %eax, -0x42c(%ebp)\n" /* messageIcon */
        "movl $0x215b7c, (%esp)\n" /* line 488 */
        "calll game_dprintf\n"
        "testl %ebx, %ebx\n" /* line 496 | message2Ptr */
        "je .Lfb770_0000b7a7\n"
        "cmpb $0, (%ebx)\n" /* message2Ptr */
        "jne .Lfb770_0000b821\n"
        ".Lfb770_0000b7a7:\n"
        "movl $0x200, 8(%esp)\n" /* line 506 */
        "leal -0x219(%ebp), %eax\n" /* message1Buff */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* lpText */
        "movl %eax, (%esp)\n"
        "calll MacStrings_CopyAndClean\n"
        "xorl %ebx, %ebx\n" /* message2Ptr */
        ".Lfb770_0000b7c6:\n"
        "leal -0x19(%ebp), %edi\n" /* line 514 | showCursor */
        "movl %edi, (%esp)\n"
        "calll StShowCursor_StShowCursor\n"
        "testl %esi, %esi\n" /* line 519 | messageType */
        "je .Lfb770_0000b7fd\n"
        "cmpl $1, %esi\n" /* line 523 | messageType */
        "je .Lfb770_0000b88d\n"
        "cmpl $4, %esi\n" /* line 534 | messageType */
        "je .Lfb770_0000b85d\n"
        ".Lfb770_0000b7e3:\n"
        "movl $1, %ebx\n" /* line 536 | result */
        ".Lfb770_0000b7e8:\n"
        "movl %edi, (%esp)\n" /* line 550 */
        "calll ZN12StShowCursorD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 551 | result */
        "addl $0x43c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb770_0000b7fd:\n"
        "xorl %eax, %eax\n" /* line 521 */
        "cmpl $0x10, -0x42c(%ebp)\n" /* messageIcon */
        "sete %al\n"
        "movl %eax, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* result */
        "leal -0x219(%ebp), %eax\n" /* message1Buff */
        "movl %eax, (%esp)\n"
        "calll MacTools_MessageAlert\n"
        "jmp .Lfb770_0000b7e3\n"
        ".Lfb770_0000b821:\n"
        "movl $0x200, 8(%esp)\n" /* line 498 */
        "leal -0x219(%ebp), %eax\n" /* message1Buff */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* message2Ptr */
        "calll MacStrings_CopyAndClean\n"
        "movl $0x200, 8(%esp)\n" /* line 499 */
        "leal -0x419(%ebp), %ebx\n" /* message2Buff, message2Ptr */
        "movl %ebx, 4(%esp)\n" /* message2Ptr */
        "movl 0xc(%ebp), %eax\n" /* lpText */
        "movl %eax, (%esp)\n"
        "calll MacStrings_CopyAndClean\n"
        "jmp .Lfb770_0000b7c6\n"
        ".Lfb770_0000b85d:\n"
        "movl %ebx, 4(%esp)\n" /* line 536 | result */
        "leal -0x219(%ebp), %eax\n" /* message1Buff */
        "movl %eax, (%esp)\n"
        "calll MacTools_QuestionAlert\n"
        "cmpb $1, %al\n"
        "sbbl %ebx, %ebx\n" /* result */
        "notl %ebx\n" /* result */
        "addl $7, %ebx\n" /* result */
        "movl %edi, (%esp)\n" /* line 550 */
        "calll ZN12StShowCursorD1Ev\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 551 | result */
        "addl $0x43c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb770_0000b88d:\n"
        "movl %ebx, 4(%esp)\n" /* line 525 | result */
        "leal -0x219(%ebp), %eax\n" /* message1Buff */
        "movl %eax, (%esp)\n"
        "calll MacTools_QuestionAlert\n"
        "testb %al, %al\n"
        "jne .Lfb770_0000b7e3\n"
        "movl $2, %ebx\n" /* result */
        "jmp .Lfb770_0000b7e8\n"
        "movl %eax, %ebx\n" /* result */
        "movl %edi, (%esp)\n" /* line 550 */
        "calll ZN12StShowCursorD1Ev\n"
        "movl %ebx, (%esp)\n" /* result */
        "calll __Unwind_Resume\n"
    );
}

/* line 655 */
__attribute__((naked))
BOOL SetFileAttributesA(LPCSTR lpFileName, DWORD dwFileAttributes)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 655 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 659 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 667 */
__attribute__((naked))
DWORD GetFileAttributesA(LPCSTR lpFileName)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 667 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $4, 4(%esp)\n" /* line 669 */
        "movl 8(%ebp), %eax\n" /* lpFileName, error */
        "movl %eax, (%esp)\n" /* error */
        "calll MacFiles_access\n"
        "addl $1, %eax\n" /* line 671 */
        "setne %al\n"
        "movzbl %al, %eax\n"
        "leal -1(%eax, %eax), %eax\n"
        /* } scope */
        "leave\n" /* line 680 */
        "retl\n"
    );
}

/* line 967 */
__attribute__((naked))
BOOL SetThreadPriority(HANDLE hThread, int nPriority)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 967 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* hThread */
        /* { scope 1 */
        "leal -0x14(%ebp), %ebx\n" /* line 974 | param */
        "movl %ebx, 8(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* policy, error */
        "movl %eax, 4(%esp)\n" /* error */
        "movl %esi, (%esp)\n" /* hThread */
        "calll pthread_getschedparam\n"
        "testl %eax, %eax\n" /* line 975 */
        "jne .Lfb8f8_0000b93b\n"
        "movl 0xc(%ebp), %eax\n" /* line 979 | nPriority */
        "addl $0xf, %eax\n"
        "cmpl $0x1e, %eax\n"
        "jbe .Lfb8f8_0000b94a\n"
        ".Lfb8f8_0000b928:\n"
        "movl %ebx, 8(%esp)\n" /* line 1008 */
        "movl -0xc(%ebp), %eax\n" /* policy */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* hThread */
        "calll pthread_setschedparam\n"
        ".Lfb8f8_0000b93b:\n"
        "testl %eax, %eax\n"
        "sete %al\n"
        "movzbl %al, %eax\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 1012 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfb8f8_0000b94a:\n"
        "jmpl *0x2edc90(, %eax, 4)\n" /* line 979 */
        "movl -0xc(%ebp), %eax\n" /* line 983 | policy */
        "movl %eax, (%esp)\n"
        "calll sched_get_priority_min\n"
        "movl %eax, -0x14(%ebp)\n" /* param */
        "jmp .Lfb8f8_0000b928\n"
        "movl -0xc(%ebp), %eax\n" /* line 987 | policy */
        "movl %eax, (%esp)\n"
        "calll sched_get_priority_min\n"
        ".Lfb8f8_0000b96c:\n"
        "addl $0x1f, %eax\n" /* line 996 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "movl %edx, -0x14(%ebp)\n" /* param */
        "jmp .Lfb8f8_0000b928\n"
        "movl $0x1f, -0x14(%ebp)\n" /* line 991 | param */
        "jmp .Lfb8f8_0000b928\n"
        "movl -0xc(%ebp), %eax\n" /* line 1000 | policy */
        "movl %eax, (%esp)\n"
        "calll sched_get_priority_max\n"
        "movl %eax, -0x14(%ebp)\n" /* param */
        "jmp .Lfb8f8_0000b928\n"
        "movl -0xc(%ebp), %eax\n" /* line 996 | policy */
        "movl %eax, (%esp)\n"
        "calll sched_get_priority_max\n"
        "jmp .Lfb8f8_0000b96c\n"
    );
}

/* line 1020 */
__attribute__((naked))
DWORD GetCurrentThreadId(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1020 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1024 */
        "jmp pthread_main_np\n" /* line 1023 */
    );
}

/* line 1118 */
__attribute__((naked))
jpeg_alloc WinSleep(DWORD dwMilliseconds)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1118 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "calll UpTime\n" /* line 1120 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* dwMilliseconds */
        "movl %eax, (%esp)\n"
        "calll AddDurationToAbsolute\n"
        "movl %eax, -0x10(%ebp)\n" /* expirationTime */
        "movl %edx, -0xc(%ebp)\n"
        "leal -0x10(%ebp), %eax\n" /* line 1121 | expirationTime */
        "movl %eax, (%esp)\n"
        "calll MPDelayUntil\n"
        /* } scope */
        "leave\n" /* line 1122 */
        "retl\n"
    );
}

/* line 1202 */
__attribute__((naked))
LONG InterlockedExchangeAdd(volatile LONG *Addend, LONG Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1202 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* Value */
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1204 | Addend, result */
        "movl %eax, 4(%esp)\n" /* result */
        "movl %ebx, (%esp)\n" /* Value */
        "calll OTAtomicAdd32\n"
        "subl %ebx, %eax\n" /* Value, result */
        /* } scope */
        "addl $0x14, %esp\n" /* line 1206 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1216 */
__attribute__((naked))
LONG InterlockedCompareExchange(volatile LONG *Destination, LONG Exchange, LONG Comperand)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1216 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Exchange */
        "movl 0x10(%ebp), %ebx\n" /* Comperand */
        "movl 8(%ebp), %eax\n" /* line 1222 | Destination */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* Exchange */
        "movl %ebx, (%esp)\n" /* Comperand */
        "calll OTCompareAndSwap32\n"
        "testb %al, %al\n"
        "cmovel %esi, %ebx\n" /* Exchange, Comperand */
        "movl %ebx, %eax\n" /* line 1230 | Comperand */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1238 */
__attribute__((naked))
UINT MapVirtualKeyA(UINT uCode, UINT uMapType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1238 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1245 | uCode */
        "subl $0x92, %eax\n"
        "cmpl $0x4c, %eax\n"
        "ja .Lfba34_0000ba4b\n"
        "jmpl *0x2edd0c(, %eax, 4)\n"
        ".Lfba34_0000ba4b:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x3b, %eax\n" /* line 1245 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x3d, %eax\n" /* line 1289 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x2c, %eax\n" /* line 1253 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x2d, %eax\n" /* line 1261 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x2e, %eax\n" /* line 1265 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x2f, %eax\n" /* line 1269 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x60, %eax\n" /* line 1273 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x5b, %eax\n" /* line 1277 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x5c, %eax\n" /* line 1281 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x5d, %eax\n" /* line 1285 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
        /* { scope 1 */
        "movl $0x27, %eax\n" /* line 1245 */
        /* } scope */
        "popl %ebp\n" /* line 1297 */
        "retl\n"
    );
}

/* line 1798 */
__attribute__((naked))
LPVOID VirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1798 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* lpAddress */
        "testl %eax, %eax\n" /* line 1800 */
        "je .Lfba9e_0000baaa\n"
        "popl %ebp\n" /* line 1812 */
        "retl\n"
        ".Lfba9e_0000baaa:\n"
        "movl $1, 8(%ebp)\n" /* line 1805 | lpAddress */
        "popl %ebp\n" /* line 1812 */
        "jmp calloc\n" /* line 1805 */
    );
}

/* line 1822 */
__attribute__((naked))
BOOL VirtualFree(LPVOID lpAddress, SIZE_T dwSize, DWORD dwFreeType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1822 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* lpAddress */
        "testl %eax, %eax\n" /* line 1824 */
        "je .Lfbab8_0000bace\n"
        "cmpl $0x8000, 0x10(%ebp)\n" /* dwFreeType */
        "je .Lfbab8_0000bad5\n"
        ".Lfbab8_0000bace:\n"
        "movl $1, %eax\n" /* line 1835 */
        "leave\n"
        "retl\n"
        ".Lfbab8_0000bad5:\n"
        "movl %eax, (%esp)\n" /* line 1827 */
        "calll free\n"
        "movl $1, %eax\n" /* line 1835 */
        "leave\n"
        "retl\n"
    );
}

/* line 2113 */
__attribute__((naked))
int GetSystemMetrics(int nIndex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2113 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* nIndex */
        /* { scope 1: width, height */
        "testl %eax, %eax\n" /* line 2117 */
        "je .Lfbae4_0000bafa\n"
        "subl $1, %eax\n"
        "je .Lfbae4_0000bb11\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 2141 */
        "retl\n"
        /* { scope 1: width, height */
        /* { scope 2 */
        ".Lfbae4_0000bafa:\n"
        "leal -0xc(%ebp), %eax\n" /* line 2122 | height */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* width */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetCurrentDimensions\n"
        "movl -0x10(%ebp), %eax\n" /* line 2123 | width */
        /* } scope */
        /* } scope */
        "leave\n" /* line 2141 */
        "retl\n"
        /* { scope 1: width, height */
        /* { scope 2 */
        ".Lfbae4_0000bb11:\n"
        "leal -0x10(%ebp), %eax\n" /* line 2130 | width */
        "movl %eax, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* height */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetCurrentDimensions\n"
        "movl -0x10(%ebp), %eax\n" /* line 2131 | width */
        /* } scope */
        /* } scope */
        "leave\n" /* line 2141 */
        "retl\n"
    );
}

/* line 2510 */
__attribute__((naked))
BOOL FindNextFileA(HANDLE hFindFile, LPWIN32_FIND_DATAA lpFindFileData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2510 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* hFindFile */
        "leal -1(%ebx), %eax\n" /* line 2513 | hFindFile */
        "cmpl $-3, %eax\n"
        "ja .Lfbb28_0000bb82\n"
        "movl 0xc(%ebp), %eax\n" /* lpFindFileData */
        "testl %eax, %eax\n"
        "je .Lfbb28_0000bb82\n"
        "movl (%ebx), %edi\n" /* line 2521 | hFindFile */
        "testl %edi, %edi\n"
        "je .Lfbb28_0000bb82\n"
        "leal 0x28(%ebx), %eax\n" /* hFindFile */
        "movl %eax, -0x28(%ebp)\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "addl $0x2c, %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        ".Lfbb28_0000bb58:\n"
        "cmpb $0, 0x2c(%ebx)\n" /* line 2530 | hFindFile */
        "jne .Lfbb28_0000bb8c\n"
        "movl 0x24(%ebx), %edx\n" /* line 334 */
        "movl (%edx), %eax\n"
        "movl %eax, 0x28(%ebx)\n" /* line 2532 | hFindFile */
        "movb $1, 0x2c(%ebx)\n" /* line 2533 | hFindFile */
        ".Lfbb28_0000bb6a:\n"
        "movl 4(%edx), %eax\n" /* line 352 */
        "cmpl %eax, 0x28(%ebx)\n" /* line 2539 | hFindFile */
        "je .Lfbb28_0000bb82\n"
        "movl (%ebx), %eax\n" /* line 2547 | hFindFile */
        "cmpl $1, %eax\n"
        "je .Lfbb28_0000bc50\n"
        "cmpl $2, %eax\n"
        "je .Lfbb28_0000bb98\n"
        ".Lfbb28_0000bb82:\n"
        "xorl %eax, %eax\n" /* line 2599 */
        ".Lfbb28_0000bb84:\n"
        "addl $0x2c, %esp\n" /* line 2612 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbb28_0000bb8c:\n"
        "addl $0x15e, 0x28(%ebx)\n" /* line 629 */
        "movl 0x24(%ebx), %edx\n"
        "jmp .Lfbb28_0000bb6a\n"
        ".Lfbb28_0000bb98:\n"
        "movl 0x28(%ebx), %eax\n" /* line 2566 | hFindFile */
        "movl %eax, -0x24(%ebp)\n"
        "testb $0x10, 0x15c(%eax)\n"
        "jne .Lfbb28_0000bcb3\n"
        /* { scope 1 */
        "leal 4(%ebx), %eax\n" /* line 2568 | hFindFile */
        "movl $0x2e, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strrchr\n"
        "movl %eax, %esi\n"
        "testl %eax, %eax\n" /* line 2570 */
        "je .Lfbb28_0000bb82\n"
        "movl %eax, %edi\n" /* line 2575 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, -0x1c(%ebp)\n" /* len */
        "movl -0x24(%ebp), %eax\n" /* line 2580 */
        "addl $0x50, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2583 | len */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "cld\n" /* line 2581 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x20(%ebp), %edi\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "movl -0x20(%ebp), %edx\n"
        "leal -1(%ecx, %edx), %ecx\n"
        "subl -0x1c(%ebp), %ecx\n" /* len */
        "movl %ecx, (%esp)\n"
        "calll strnicmp\n"
        "testl %eax, %eax\n" /* line 2583 */
        "jne .Lfbb28_0000bb58\n"
        "movl 0xc(%ebp), %eax\n" /* line 2585 | lpFindFileData */
        "movl $0, (%eax)\n"
        /* } scope */
        ".Lfbb28_0000bc2a:\n"
        "movl 0x28(%ebx), %eax\n" /* line 2596 | hFindFile */
        "movl 0x156(%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x28(%ebx), %eax\n" /* line 2597 | hFindFile */
        "movzwl 0x154(%eax), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lfbb28_0000bb84\n"
        ".Lfbb28_0000bc50:\n"
        "movl 0x28(%ebx), %eax\n" /* line 2553 | hFindFile */
        "movzwl 0x15c(%eax), %eax\n"
        "andl $0x10, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $0x10, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "movl %eax, (%edx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 2554 */
        "movl (%edx), %eax\n"
        "addl $0x50, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "movl -0x28(%ebp), %edx\n" /* line 2555 */
        "movl (%edx), %eax\n"
        "movl 0x156(%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "movl %eax, 0x14(%edx)\n"
        "movl -0x28(%ebp), %edx\n" /* line 2556 */
        "movl (%edx), %eax\n"
        "movzwl 0x154(%eax), %eax\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "movl %eax, 0x18(%edx)\n"
        "movl $1, %eax\n"
        "addl $0x2c, %esp\n" /* line 2612 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfbb28_0000bcb3:\n"
        "movl 0xc(%ebp), %eax\n" /* line 2594 | lpFindFileData */
        "movl $0x10, (%eax)\n"
        "movl 0x28(%ebx), %eax\n" /* line 2595 | hFindFile */
        "addl $0x50, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* lpFindFileData */
        "addl $0x2c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "jmp .Lfbb28_0000bc2a\n"
    );
}

/* line 220 */
__attribute__((naked))
DWORD timeGetTime(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "leal -0x10(%ebp), %eax\n" /* line 223 | currTime */
        "movl %eax, (%esp)\n"
        "calll Microseconds\n"
        "movl -0x10(%ebp), %ecx\n" /* currTime */
        "movl -0xc(%ebp), %ebx\n"
        "movl %ebx, %edx\n"
        "movl $0, %eax\n"
        "orl %ecx, %eax\n"
        "addl $0x1f4, %eax\n"
        "adcl $0, %edx\n"
        "movl $0x3e8, 8(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl %eax, (%esp)\n"
        "movl %edx, 4(%esp)\n"
        "calll ___udivdi3\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 226 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 303 */
__attribute__((naked))
BOOL QueryPerformanceCounter(void *lpPerformanceCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 303 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "leal -0x10(%ebp), %eax\n" /* line 306 | wideTicks */
        "movl %eax, (%esp)\n"
        "calll Microseconds\n"
        "movl -0x10(%ebp), %ecx\n" /* wideTicks */
        "movl -0xc(%ebp), %ebx\n"
        "movl $0, %eax\n" /* line 310 */
        "orl %ecx, %eax\n"
        "movl 8(%ebp), %ecx\n" /* lpPerformanceCount */
        "movl %eax, (%ecx)\n"
        "movl %ebx, 4(%ecx)\n"
        /* } scope */
        "movl $1, %eax\n" /* line 313 */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1190 */
__attribute__((naked))
LONG InterlockedExchange(volatile LONG *Target, LONG Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1190 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* Target */
        "movl 0xc(%ebp), %esi\n" /* Value */
        "movl (%eax), %ebx\n" /* line 1192 */
        "movl %eax, 8(%esp)\n" /* line 1222 */
        "movl %esi, 4(%esp)\n" /* Value */
        "movl %ebx, (%esp)\n"
        "calll OTCompareAndSwap32\n"
        "testb %al, %al\n"
        "cmovel %esi, %ebx\n" /* Value */
        "movl %ebx, %eax\n" /* line 1193 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2255 */
__attribute__((naked))
HANDLE FindFirstFileA(LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2255 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcac, %esp\n"
        "movl 8(%ebp), %eax\n" /* lpFileName */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 2258 */
        "je .Lfbd86_0000c0e9\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "testl %edx, %edx\n"
        "je .Lfbd86_0000c0e9\n"
        "movl $0, 8(%esp)\n" /* line 2266 */
        "leal -0xc62(%ebp), %edx\n" /* fileName */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll MacFiles_CleanPath\n"
        "movl $0x14c, 8(%esp)\n" /* line 2275 */
        "movl $0, 4(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* lpFindFileData */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl $0x215b84, 4(%esp)\n" /* line 2280 */
        "leal -0xc62(%ebp), %edi\n" /* fileName, type */
        "movl %edi, (%esp)\n" /* type */
        "calll strstr\n"
        "movl %eax, %edi\n" /* type */
        "testl %eax, %eax\n" /* line 2281 */
        "je .Lfbd86_0000c22d\n"
        ".Lfbd86_0000bdfd:\n"
        "movl $1, -0xc84(%ebp)\n" /* line 2295 | findType */
        ".Lfbd86_0000be07:\n"
        "movl $0x2f, 4(%esp)\n" /* line 2354 */
        "leal -0xc62(%ebp), %eax\n" /* fileName */
        "movl %eax, (%esp)\n"
        "calll strrchr\n"
        "testl %eax, %eax\n" /* line 2355 */
        "je .Lfbd86_0000c0ac\n"
        /* { scope 2: count, changed */
        "movl %eax, %ebx\n" /* line 2357 | len */
        "leal -0xc62(%ebp), %eax\n" /* fileName */
        "subl %eax, %ebx\n" /* len */
        "movl %ebx, 8(%esp)\n" /* line 2358 | len */
        "movl %eax, 4(%esp)\n"
        "leal -0x862(%ebp), %esi\n" /* path */
        "movl %esi, (%esp)\n"
        "calll strncpy\n"
        "movb $0, -0x862(%ebp, %ebx)\n" /* line 2359 */
        "movl $0, 8(%esp)\n" /* line 2362 */
        "leal -0x74(%ebp), %ecx\n" /* ref */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll FSPathMakeRef\n"
        "testl %eax, %eax\n" /* line 2363 */
        "jne .Lfbd86_0000c10a\n"
        /* } scope */
        ".Lfbd86_0000be6c:\n"
        "movl $0, 0x14(%esp)\n" /* line 2420 */
        "movl $0, 0x10(%esp)\n"
        "leal -0x462(%ebp), %ebx\n" /* name, len */
        "movl %ebx, 0xc(%esp)\n" /* len */
        "leal -0x104(%ebp), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "movl $0x42, 4(%esp)\n"
        "leal -0x74(%ebp), %eax\n" /* ref */
        "movl %eax, (%esp)\n"
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 2421 */
        "jne .Lfbd86_0000c0e9\n"
        "testb $0x10, -0x104(%ebp)\n" /* line 2428 | info */
        "je .Lfbd86_0000c277\n"
        "movl $0x30, (%esp)\n" /* line 2441 */
        "calll __Znwm\n"
        "movl %eax, -0xc80(%ebp)\n" /* ffData */
        "movl $0, 0x24(%eax)\n" /* line 2238 */
        "movl $0, 0x28(%eax)\n" /* line 600 */
        "movb $0, 0x2c(%eax)\n" /* line 2238 */
        "movl -0xc84(%ebp), %edx\n" /* line 2442 | findType */
        "movl %edx, (%eax)\n"
        "movl %edi, 4(%esp)\n" /* line 2443 | type */
        "movl -0xc80(%ebp), %eax\n" /* ffData */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcpy\n"
        "leal -0x20(%ebp), %eax\n" /* line 2449 | iterator */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x74(%ebp), %ecx\n" /* ref */
        "movl %ecx, (%esp)\n"
        "calll FSOpenIterator\n"
        "testw %ax, %ax\n" /* line 2450 */
        "jne .Lfbd86_0000c038\n"
        /* { scope 2: count, changed */
        "movl $0x1c20, (%esp)\n" /* line 129 */
        "calll __Znam\n"
        "movl %eax, -0xc78(%ebp)\n"
        "movl $0xfa0, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, -0xc74(%ebp)\n"
        "movl $0x6400, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, -0xc70(%ebp)\n"
        "movl $0xc, (%esp)\n" /* line 2458 */
        "calll __Znwm\n"
        "movl $0, (%eax)\n" /* line 85 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl -0xc80(%ebp), %edi\n" /* line 2458 | ffData, type */
        "movl %eax, 0x24(%edi)\n" /* type */
        /* { scope 3: i */
        ".Lfbd86_0000bf7c:\n"
        "movl -0xc70(%ebp), %eax\n" /* line 2464 */
        "movl %eax, 0x20(%esp)\n"
        "movl $0, 0x1c(%esp)\n"
        "movl -0xc74(%ebp), %edx\n"
        "movl %edx, 0x18(%esp)\n"
        "movl -0xc78(%ebp), %ecx\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl $0x42, 0x10(%esp)\n"
        "leal -0x19(%ebp), %edi\n" /* changed, type */
        "movl %edi, 0xc(%esp)\n" /* type */
        "leal -0x24(%ebp), %eax\n" /* count */
        "movl %eax, 8(%esp)\n"
        "movl $0x32, 4(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* iterator */
        "movl %eax, (%esp)\n"
        "calll FSGetCatalogInfoBulk\n"
        "movw %ax, -0xc86(%ebp)\n"
        "testw %ax, %ax\n" /* line 2465 */
        "je .Lfbd86_0000c123\n"
        "cmpw $0xfa77, %ax\n"
        "je .Lfbd86_0000c123\n"
        /* } scope */
        ".Lfbd86_0000bfe5:\n"
        "movl -0x20(%ebp), %eax\n" /* line 2486 | iterator */
        "movl %eax, (%esp)\n"
        "calll FSCloseIterator\n"
        "movl -0xc70(%ebp), %eax\n" /* line 134 */
        "testl %eax, %eax\n"
        "je .Lfbd86_0000c008\n"
        "movl -0xc70(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lfbd86_0000c008:\n"
        "movl -0xc74(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfbd86_0000c020\n"
        "movl -0xc74(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lfbd86_0000c020:\n"
        "movl -0xc78(%ebp), %esi\n"
        "testl %esi, %esi\n"
        "je .Lfbd86_0000c038\n"
        "movl -0xc78(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll __ZdaPv\n"
        /* } scope */
        ".Lfbd86_0000c038:\n"
        "movl 0xc(%ebp), %edi\n" /* line 2491 | lpFindFileData, type */
        "movl %edi, 4(%esp)\n" /* type */
        "movl -0xc80(%ebp), %eax\n" /* ffData */
        "movl %eax, (%esp)\n"
        "calll FindNextFileA\n"
        "testl %eax, %eax\n"
        "jne .Lfbd86_0000c0f9\n"
        "movl -0xc80(%ebp), %edx\n" /* line 2244 | ffData */
        "movl 0x24(%edx), %ebx\n" /* this */
        "testl %ebx, %ebx\n" /* this */
        "je .Lfbd86_0000c2b6\n"
        /* { scope 2: count, changed */
        "movl 4(%ebx), %edx\n" /* line 273 | __last */
        "movl (%ebx), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 3: i */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lfbd86_0000c07a\n"
        ".Lfbd86_0000c071:\n"
        "addl $0x15e, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lfbd86_0000c071\n"
        /* } scope */
        ".Lfbd86_0000c07a:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lfbd86_0000c086\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lfbd86_0000c086:\n"
        "movl %ebx, (%esp)\n" /* line 2244 | this */
        "calll __ZdlPv\n"
        "movl -0xc80(%ebp), %ecx\n" /* ffData */
        ".Lfbd86_0000c094:\n"
        "movl %ecx, (%esp)\n" /* line 2499 */
        "calll __ZdlPv\n"
        "movl $0xffffffff, %eax\n"
        /* } scope */
        "addl $0xcac, %esp\n" /* line 2501 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: count, changed */
        ".Lfbd86_0000c0ac:\n"
        "movl $0x400, 4(%esp)\n" /* line 2403 */
        "leal -0x862(%ebp), %ebx\n" /* path, len */
        "movl %ebx, (%esp)\n" /* len */
        "calll getcwd\n"
        "testl %eax, %eax\n" /* line 2404 */
        "je .Lfbd86_0000c2bd\n"
        "movl $0, 8(%esp)\n" /* line 2406 */
        "leal -0x74(%ebp), %edx\n" /* ref */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* len */
        "calll FSPathMakeRef\n"
        ".Lfbd86_0000c0e1:\n"
        "testl %eax, %eax\n" /* line 2412 */
        "je .Lfbd86_0000be6c\n"
        /* } scope */
        ".Lfbd86_0000c0e9:\n"
        "movl $0xffffffff, %eax\n" /* line 2500 */
        /* } scope */
        ".Lfbd86_0000c0ee:\n"
        "addl $0xcac, %esp\n" /* line 2501 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfbd86_0000c0f9:\n"
        "movl -0xc80(%ebp), %eax\n" /* line 2493 | ffData */
        /* } scope */
        "addl $0xcac, %esp\n" /* line 2501 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: count, changed */
        ".Lfbd86_0000c10a:\n"
        "leal -0x74(%ebp), %eax\n" /* line 2367 | ref */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll MacFolders_GetDataFolderItemRef\n"
        "testl %eax, %eax\n" /* line 2368 */
        "je .Lfbd86_0000be6c\n"
        "jmp .Lfbd86_0000c0e9\n"
        /* } scope */
        /* { scope 2: count, changed */
        /* { scope 3: i */
        ".Lfbd86_0000c123:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2465 | count */
        "testl %eax, %eax\n"
        "je .Lfbd86_0000c21a\n"
        "movl -0xc74(%ebp), %edx\n"
        "movl %edx, -0xc6c(%ebp)\n"
        "movl -0xc70(%ebp), %edi\n" /* type */
        "movl -0xc78(%ebp), %esi\n"
        "movl $0, -0xc7c(%ebp)\n" /* i */
        "movl %edx, %ecx\n"
        "jmp .Lfbd86_0000c15a\n"
        ".Lfbd86_0000c154:\n"
        "movl -0xc6c(%ebp), %ecx\n"
        /* { scope 4: item */
        /* { scope 5 */
        ".Lfbd86_0000c15a:\n"
        "movl $0x50, 8(%esp)\n" /* line 2470 */
        "movl %ecx, 4(%esp)\n"
        "leal -0x262(%ebp), %eax\n" /* item */
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl $0x104, 8(%esp)\n" /* line 2471 */
        "leal -0x212(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* type */
        "calll MacStrings_GetCString\n"
        "movl 0x18(%esi), %eax\n" /* line 2472 */
        "movl 0x1c(%esi), %edx\n"
        "movl %eax, -0x10e(%ebp)\n"
        "movl %edx, -0x10a(%ebp)\n"
        "movzwl (%esi), %eax\n" /* line 2473 */
        "movw %ax, -0x106(%ebp)\n"
        "cmpb $0x2e, -0x212(%ebp)\n" /* line 2476 */
        "je .Lfbd86_0000c1f1\n"
        "movl -0xc80(%ebp), %ecx\n" /* line 2481 | ffData */
        "movl 0x24(%ecx), %ebx\n" /* len */
        "movl 4(%ebx), %eax\n" /* line 604 */
        "cmpl 8(%ebx), %eax\n"
        "je .Lfbd86_0000c25c\n"
        "testl %eax, %eax\n" /* line 104 */
        "je .Lfbd86_0000c1e9\n"
        "movl $0x15e, 8(%esp)\n"
        "leal -0x262(%ebp), %edx\n" /* item */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 4(%ebx), %eax\n"
        ".Lfbd86_0000c1e9:\n"
        "addl $0x15e, %eax\n" /* line 607 */
        "movl %eax, 4(%ebx)\n"
        /* } scope */
        ".Lfbd86_0000c1f1:\n"
        "addl $1, -0xc7c(%ebp)\n" /* line 2467 | i */
        "addl $0x50, -0xc6c(%ebp)\n"
        "addl $0x200, %edi\n" /* type */
        "addl $0x90, %esi\n"
        "movl -0xc7c(%ebp), %eax\n" /* i */
        "cmpl -0x24(%ebp), %eax\n" /* count */
        "jb .Lfbd86_0000c154\n"
        /* } scope */
        /* } scope */
        ".Lfbd86_0000c21a:\n"
        "cmpw $0, -0xc86(%ebp)\n" /* line 2460 */
        "je .Lfbd86_0000bf7c\n"
        "jmp .Lfbd86_0000bfe5\n"
        /* } scope */
        ".Lfbd86_0000c22d:\n"
        "movl $0x215b88, 4(%esp)\n" /* line 2287 */
        "leal -0xc62(%ebp), %eax\n" /* fileName */
        "movl %eax, (%esp)\n"
        "calll strstr\n"
        "movl %eax, %edi\n" /* type */
        "testl %eax, %eax\n" /* line 2288 */
        "je .Lfbd86_0000c2d1\n"
        "movl $2, -0xc84(%ebp)\n" /* findType */
        "jmp .Lfbd86_0000be07\n"
        /* { scope 2: count, changed */
        /* { scope 3: i */
        /* { scope 4: item */
        /* { scope 5 */
        ".Lfbd86_0000c25c:\n"
        "leal -0x262(%ebp), %ecx\n" /* line 610 | item */
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZNSt6vectorI6FFItemSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_\n"
        "jmp .Lfbd86_0000c1f1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfbd86_0000c277:\n"
        "movl 0xc(%ebp), %edx\n" /* line 2430 | lpFindFileData */
        "movl $0, (%edx)\n"
        "movl $0x104, 8(%esp)\n" /* line 2431 */
        "movl %edx, %eax\n"
        "addl $0x2c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* len */
        "calll MacStrings_GetCString\n"
        "movl -0xea(%ebp), %eax\n" /* line 2432 */
        "movl 0xc(%ebp), %ecx\n" /* lpFindFileData */
        "movl %eax, 0x14(%ecx)\n"
        "movzwl -0xec(%ebp), %eax\n" /* line 2433 */
        "movl %eax, 0x18(%ecx)\n"
        "xorl %eax, %eax\n"
        "jmp .Lfbd86_0000c0ee\n"
        ".Lfbd86_0000c2b6:\n"
        "movl %edx, %ecx\n"
        "jmp .Lfbd86_0000c094\n"
        /* { scope 2: count, changed */
        ".Lfbd86_0000c2bd:\n"
        "leal -0x74(%ebp), %ecx\n" /* line 2410 | ref */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* len */
        "calll MacFolders_GetDataFolderItemRef\n"
        "jmp .Lfbd86_0000c0e1\n"
        /* } scope */
        ".Lfbd86_0000c2d1:\n"
        "movl $2, %ecx\n" /* line 2295 */
        "cld\n"
        "movl $0x215b8c, %ebx\n" /* this */
        "leal -0xc62(%ebp), %esi\n" /* fileName */
        "movl %ebx, %edi\n" /* this, type */
        "repe cmpsb %es:(%edi), (%esi)\n" /* type */
        "movl $0, %ebx\n" /* this */
        "je .Lfbd86_0000c2f7\n"
        "movzbl -1(%esi), %ebx\n" /* this */
        "movzbl -1(%edi), %ecx\n" /* type */
        "subl %ecx, %ebx\n" /* this */
        ".Lfbd86_0000c2f7:\n"
        "testl %ebx, %ebx\n" /* this */
        "jne .Lfbd86_0000c305\n"
        "movl $0x215b8c, %edi\n" /* type */
        "jmp .Lfbd86_0000bdfd\n"
        ".Lfbd86_0000c305:\n"
        "movl $0, 8(%esp)\n" /* line 2319 */
        "leal -0x74(%ebp), %edi\n" /* ref, type */
        "movl %edi, 4(%esp)\n" /* type */
        "leal -0xc62(%ebp), %eax\n" /* fileName */
        "movl %eax, (%esp)\n"
        "calll FSPathMakeRef\n"
        "testl %eax, %eax\n" /* line 2320 */
        "je .Lfbd86_0000c343\n"
        "leal -0x74(%ebp), %edx\n" /* line 2324 | ref */
        "movl %edx, 4(%esp)\n"
        "leal -0xc62(%ebp), %ecx\n" /* fileName */
        "movl %ecx, (%esp)\n"
        "calll MacFolders_GetDataFolderItemRef\n"
        "testl %eax, %eax\n" /* line 2325 */
        "jne .Lfbd86_0000c0e9\n"
        ".Lfbd86_0000c343:\n"
        "movl $0, 0x14(%esp)\n" /* line 2332 */
        "movl $0, 0x10(%esp)\n"
        "leal -0x462(%ebp), %ebx\n" /* name, this */
        "movl %ebx, 0xc(%esp)\n" /* this */
        "leal -0x104(%ebp), %eax\n" /* info */
        "movl %eax, 8(%esp)\n"
        "movl $0x4042, 4(%esp)\n"
        "leal -0x74(%ebp), %edi\n" /* ref, type */
        "movl %edi, (%esp)\n" /* type */
        "calll FSGetCatalogInfo\n"
        "testw %ax, %ax\n" /* line 2333 */
        "jne .Lfbd86_0000c0e9\n"
        "movzwl -0x104(%ebp), %eax\n" /* line 2338 | info */
        "andl $0x10, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %eax, %eax\n"
        "notl %eax\n"
        "andl $0x10, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* lpFindFileData */
        "movl %eax, (%edx)\n"
        "movl $0x104, 8(%esp)\n" /* line 2339 */
        "movl %edx, %eax\n"
        "addl $0x2c, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll MacStrings_GetCString\n"
        "movl -0xea(%ebp), %eax\n" /* line 2340 */
        "movl 0xc(%ebp), %ecx\n" /* lpFindFileData */
        "movl %eax, 0x14(%ecx)\n"
        "movzwl -0xec(%ebp), %eax\n" /* line 2341 */
        "movl %eax, 0x18(%ecx)\n"
        "movl -0x98(%ebp), %eax\n" /* line 2342 */
        "movl %eax, 0x1c(%ecx)\n"
        "movl -0x9c(%ebp), %eax\n" /* line 2343 */
        "movl %eax, 0x20(%ecx)\n"
        "movl $0x30, (%esp)\n" /* line 2345 */
        "calll __Znwm\n"
        "movl $0, 0x24(%eax)\n" /* line 2238 */
        "movl $0, 0x28(%eax)\n" /* line 600 */
        "movb $0, 0x2c(%eax)\n" /* line 2238 */
        "movl $0, (%eax)\n" /* line 2346 */
        "jmp .Lfbd86_0000c0ee\n"
        "movl %eax, %ebx\n" /* this */
        /* { scope 2: count, changed */
        ".Lfbd86_0000c408:\n"
        "movl -0xc78(%ebp), %edi\n" /* line 134 */
        "testl %edi, %edi\n"
        "je .Lfbd86_0000c420\n"
        "movl -0xc78(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lfbd86_0000c420:\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl -0xc70(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfbd86_0000c442\n"
        "movl -0xc70(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll __ZdaPv\n"
        ".Lfbd86_0000c442:\n"
        "movl -0xc74(%ebp), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfbd86_0000c408\n"
        "movl -0xc74(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll __ZdaPv\n"
        "jmp .Lfbd86_0000c408\n"
        "movl %eax, %ebx\n"
        "jmp .Lfbd86_0000c442\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorI6FFItemSaIS0_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS0_S2_EERKS0_(void) /* std_vector<FFItem, std_allocator<FFItem> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x19c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x17c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl 4(%edx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "je .Lf2bc24c_002bc33c\n"
        "leal -0x15e(%eax), %edx\n"
        /* { scope 1 */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf2bc24c_002bc479\n"
        "movl $0x15e, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n"
        /* } scope */
        ".Lf2bc24c_002bc298:\n"
        "movl %eax, %ebx\n" /* line 255 */
        "addl $0x15e, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl $0x15e, 8(%esp)\n" /* line 256 */
        "movl 0x10(%ebp), %eax\n" /* __x */
        "movl %eax, 4(%esp)\n"
        "leal -0x176(%ebp), %edx\n" /* __x_copy */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal -0x15e(%ebx), %edx\n" /* line 257 */
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 411 */
        "subl -0x17c(%ebp), %eax\n"
        "sarl $1, %eax\n"
        "imull $0x1bcb564f, %eax, %eax\n"
        "movl %eax, -0x188(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf2bc24c_002bc314\n"
        "movl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "xorl %edi, %edi\n"
        ".Lf2bc24c_002bc2e5:\n"
        "leal -0x15e(%edx), %esi\n" /* line 412 */
        "leal -0x15e(%eax), %ebx\n"
        "movl $0x15e, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %edi\n"
        "movl %ebx, %eax\n"
        "movl %esi, %edx\n"
        "cmpl %edi, -0x188(%ebp)\n" /* line 411 */
        "jne .Lf2bc24c_002bc2e5\n"
        /* } scope */
        ".Lf2bc24c_002bc314:\n"
        "movl $0x15e, 8(%esp)\n" /* line 260 */
        "leal -0x176(%ebp), %eax\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        /* } scope */
        "addl $0x19c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bc24c_002bc33c:\n"
        "subl (%edx), %eax\n" /* line 759 */
        "sarl $1, %eax\n"
        "imull $0x1bcb564f, %eax, %eax\n"
        "cmpl $0xbb3ee7, %eax\n" /* line 265 */
        "je .Lf2bc24c_002bc4a3\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bc24c_002bc481\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bc24c_002bc35e:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 88 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal (, %eax, 8), %edx\n"
        "subl %eax, %edx\n"
        "addl %edx, %edx\n"
        "movl %edx, -0x18c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x184(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 279 | this */
        "movl (%eax), %esi\n"
        /* { scope 2 */
        "movl -0x184(%ebp), %ebx\n" /* line 82 */
        "cmpl %esi, 0xc(%ebp)\n" /* line 85 | __position */
        "je .Lf2bc24c_002bc3c2\n"
        "movl %esi, %eax\n"
        "jmp .Lf2bc24c_002bc399\n"
        ".Lf2bc24c_002bc397:\n"
        "movl %eax, %esi\n"
        ".Lf2bc24c_002bc399:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bc24c_002bc3b1\n"
        "movl $0x15e, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bc24c_002bc3b1:\n"
        "leal 0x15e(%esi), %eax\n" /* line 623 */
        "addl $0x15e, %ebx\n"
        "cmpl %eax, 0xc(%ebp)\n" /* line 85 | __position */
        "jne .Lf2bc24c_002bc397\n"
        /* } scope */
        ".Lf2bc24c_002bc3c2:\n"
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf2bc24c_002bc3dd\n"
        "movl $0x15e, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bc24c_002bc3dd:\n"
        "movl 8(%ebp), %eax\n" /* line 286 | this */
        "addl $4, %eax\n"
        "movl %eax, -0x180(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %edi\n"
        "movl -0x17c(%ebp), %eax\n" /* line 286 */
        /* { scope 2 */
        "addl $0x15e, %ebx\n" /* line 82 */
        "cmpl %eax, %edi\n" /* line 85 */
        "je .Lf2bc24c_002bc429\n"
        ".Lf2bc24c_002bc3ff:\n"
        "movl %eax, %esi\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bc24c_002bc419\n"
        "movl $0x15e, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bc24c_002bc419:\n"
        "leal 0x15e(%esi), %eax\n" /* line 623 */
        "addl $0x15e, %ebx\n"
        "cmpl %edi, %eax\n" /* line 85 */
        "jne .Lf2bc24c_002bc3ff\n"
        /* } scope */
        ".Lf2bc24c_002bc429:\n"
        "movl -0x180(%ebp), %eax\n" /* line 352 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* line 334 | this */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bc24c_002bc445\n"
        ".Lf2bc24c_002bc43c:\n"
        "addl $0x15e, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bc24c_002bc43c\n"
        ".Lf2bc24c_002bc445:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bc24c_002bc451\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bc24c_002bc451:\n"
        "movl -0x184(%ebp), %eax\n" /* line 302 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 303 */
        "movl -0x184(%ebp), %eax\n" /* line 304 */
        "addl -0x18c(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x19c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bc24c_002bc479:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf2bc24c_002bc298\n"
        /* { scope 1 */
        ".Lf2bc24c_002bc481:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bc24c_002bc499\n"
        "cmpl $0xbb3ee7, %edx\n" /* line 85 */
        "jbe .Lf2bc24c_002bc35e\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bc24c_002bc499:\n"
        "movl $0xbb3ee7, %edx\n" /* line 272 */
        "jmp .Lf2bc24c_002bc35e\n"
        ".Lf2bc24c_002bc4a3:\n"
        "movl $0x215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

