/* ASM dump from: com_memory.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/com_memory.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/q_shared.h"
 */

extern const dvar_t *com_dedicated; /* 0x0 */
static fileData_t * com_fileDataHashTable[1024]; /* 0x3bcfa0 */
static fileData_t *com_hunkData; /* 0x3bcf98 */
static int g_largeLocalPos; /* 0x33cf00 */
static byte g_largeLocalBuf[524288]; /* 0x33cf80 */
static struct hunkUsed_t hunk_low; /* 0x3bcf88 */
static hunkUsed_t hunk_high; /* 0x3bcf80 */
static byte *s_hunkData; /* 0x3bcf90 */
static byte *s_origHunkData; /* 0x3bdfa0 */
static int s_hunkTotal; /* 0x3bcf94 */

void Z_FreeInternal(void *ptr);
void Z_VirtualFreeInternal(void *ptr);
void Z_VirtualDecommitInternal(void *ptr, int size);
void * Z_MallocGarbageInternal(int size);
void * Z_VirtualReserveInternal(int size);
void Z_VirtualCommitInternal(void *ptr, int size);
static void Com_Meminfo_f(void);
void Com_TouchMemory(void);
void * Hunk_FindDataForFile(int type, const char *name);
qboolean Hunk_DataOnHunk(void *data);
const char * Hunk_SetDataForFile(int type, const char *name, void *data, Alloc_t alloc);
void Hunk_AddData(int type, void *data, Alloc_t alloc);
void Hunk_OverrideDataForFile(int type, const char *name, void *data);
void DB_EnumXAssets(int type, XAssetEnum *func, void *inData, int includeOverride);
int Hunk_SetMark(void);
int Hunk_Used(void);
void * Hunk_AllocAlignInternal(int size, int alignment);
void * Hunk_AllocNoZeroInternal(int size);
void * Hunk_AllocateTempMemoryHighInternal(int size);
void Hunk_ClearTempMemoryHigh(void);
void * Hunk_AllocLowAlignInternal(int size, int alignment);
void Hunk_ConvertTempToPermLowInternal(void);
void * Hunk_ReallocateTempMemoryInternal(int size);
void Hunk_ClearTempMemory(void);
int Hunk_HideTempMemory(void);
void Hunk_ShowTempMemory(int mark);
void LargeLocalReset(void);
void ZN10LargeLocalD1Ev(void); /* LargeLocal_~LargeLocal */
void LargeLocal_LargeLocal(const LargeLocal * _this, int size);
void * Z_TryMallocInternal(int size);
void * LargeLocal_GetBuf(const LargeLocal * _this);
void Hunk_FreeTempMemory(void *buf);
void * Z_VirtualAllocInternal(int size);
void * Z_MallocInternal(int size);
static void Hunk_ClearData(void);
void Hunk_Clear(void);
void Hunk_ClearToMarkLow(int mark);
void Hunk_ClearToMark(int mark);
void Com_InitHunkMemory(void);
char * CopyStringInternal(const char *in);
void ReplaceStringInternal(char * *str, const char *in);
void * Hunk_AllocateTempMemoryInternal(int size);
void * Hunk_AllocLowInternal(int size);
void * Hunk_AllocInternal(int size);

/* line 194 */
__attribute__((naked))
void Z_FreeInternal(void *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 194 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 197 */
        "jmp free\n" /* line 196 */
    );
}

/* line 200 */
__attribute__((naked))
void Z_VirtualFreeInternal(void *ptr)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 200 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8000, 8(%esp)\n" /* line 202 */
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ptr */
        "movl %eax, (%esp)\n"
        "calll VirtualFree\n"
        "leave\n" /* line 203 */
        "retl\n"
    );
}

/* line 206 */
__attribute__((naked))
void Z_VirtualDecommitInternal(void *ptr, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 206 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x4000, 8(%esp)\n" /* line 208 */
        "movl 0xc(%ebp), %eax\n" /* size */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ptr */
        "movl %eax, (%esp)\n"
        "calll VirtualFree\n"
        "leave\n" /* line 209 */
        "retl\n"
    );
}

/* line 497 */
__attribute__((naked))
void * Z_MallocGarbageInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 497 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 471 | size */
        "movl %eax, (%esp)\n"
        "calll malloc\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 502 */
        "je .Lf37e14_00037e34\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 505 | buf */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf37e14_00037e34:\n"
        "movl $0xdc, 4(%esp)\n" /* line 220 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 505 | buf */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 535 */
__attribute__((naked))
void * Z_VirtualReserveInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 535 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $4, 0xc(%esp)\n" /* line 537 */
        "movl $0x2000, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* size */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll VirtualAlloc\n"
        "leave\n" /* line 538 */
        "retl\n"
    );
}

/* line 541 */
__attribute__((naked))
void Z_VirtualCommitInternal(void *ptr, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 541 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        /* { scope 1 */
        "movl $4, 0xc(%esp)\n" /* line 545 */
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* size */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* ptr */
        "movl %eax, (%esp)\n"
        "calll VirtualAlloc\n"
        "testl %eax, %eax\n" /* line 546 */
        "je .Lf37e7c_00037eaa\n"
        /* } scope */
        "leave\n" /* line 556 */
        "retl\n"
        /* { scope 1 */
        ".Lf37e7c_00037eaa:\n"
        "movl $0x225, 0xc(%ebp)\n" /* line 549 | size */
        "movl $0x2174d0, 8(%ebp)\n" /* ptr */
        /* } scope */
        "leave\n" /* line 556 */
        /* { scope 1 */
        "jmp Sys_OutOfMemErrorInternal\n" /* line 549 */
    );
}

/* line 673 */
static __attribute__((naked))
void Com_Meminfo_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 673 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl s_hunkTotal, %eax\n" /* line 688 */
        "movl %eax, 4(%esp)\n"
        "movl $0x21751c, (%esp)\n" /* "%8i bytes total hunk
" */
        "calll Com_Printf\n"
        "movl $0x2160e8, (%esp)\n" /* line 689 */
        "calll Com_Printf\n"
        "movl hunk_low, %eax\n" /* line 690 */
        "movl %eax, 4(%esp)\n"
        "movl $0x217534, (%esp)\n" /* "%8i low permanent
" */
        "calll Com_Printf\n"
        "movl 0x3bcf8c, %eax\n" /* line 691 */
        "cmpl hunk_low, %eax\n"
        "je .Lf37ebe_00037f17\n"
        "movl %eax, 4(%esp)\n" /* line 693 */
        "movl $0x217548, (%esp)\n" /* "%8i low temp
" */
        "calll Com_Printf\n"
        ".Lf37ebe_00037f17:\n"
        "movl $0x2160e8, (%esp)\n" /* line 695 */
        "calll Com_Printf\n"
        "movl hunk_high, %eax\n" /* line 696 */
        "movl %eax, 4(%esp)\n"
        "movl $0x217558, (%esp)\n" /* "%8i high permanent
" */
        "calll Com_Printf\n"
        "movl 0x3bcf84, %eax\n" /* line 697 */
        "cmpl hunk_high, %eax\n"
        "je .Lf37ebe_00037f55\n"
        "movl %eax, 4(%esp)\n" /* line 699 */
        "movl $0x21756c, (%esp)\n" /* "%8i high temp
" */
        "calll Com_Printf\n"
        ".Lf37ebe_00037f55:\n"
        "movl $0x2160e8, (%esp)\n" /* line 701 */
        "calll Com_Printf\n"
        "movl hunk_low, %eax\n" /* line 702 */
        "addl hunk_high, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x21757c, (%esp)\n" /* "%8i total hunk in use
" */
        "calll Com_Printf\n"
        "movl $0x2160e8, (%esp)\n" /* line 704 */
        "calll Com_Printf\n"
        "leave\n" /* line 707 */
        "retl\n"
    );
}

/* line 738 */
__attribute__((naked))
void Com_TouchMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 738 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "calll Sys_Milliseconds\n" /* line 746 */
        "movl %eax, %esi\n" /* start */
        "movl hunk_low, %edx\n" /* line 750 */
        "sarl $2, %edx\n"
        "testl %edx, %edx\n" /* line 751 */
        "jle .Lf37f8a_0003800b\n"
        "movl s_hunkData, %ecx\n" /* line 753 */
        "xorl %eax, %eax\n"
        "xorl %ebx, %ebx\n" /* sum */
        ".Lf37f8a_00037fb0:\n"
        "addl (%ecx, %eax, 4), %ebx\n" /* sum */
        "addl $0x40, %eax\n" /* line 751 */
        "cmpl %eax, %edx\n"
        "jg .Lf37f8a_00037fb0\n"
        ".Lf37f8a_00037fba:\n"
        "movl hunk_high, %eax\n" /* line 756 */
        "movl s_hunkTotal, %edx\n"
        "subl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %eax, %ecx\n" /* line 757 */
        "sarl $2, %ecx\n"
        "cmpl %ecx, %edx\n" /* line 758 */
        "jge .Lf37f8a_00037fe9\n"
        "movl s_hunkData, %eax\n"
        "leal (%eax, %edx, 4), %eax\n"
        ".Lf37f8a_00037fdb:\n"
        "addl (%eax), %ebx\n" /* line 760 | sum */
        "addl $0x40, %edx\n" /* line 758 */
        "addl $0x100, %eax\n"
        "cmpl %edx, %ecx\n"
        "jg .Lf37f8a_00037fdb\n"
        ".Lf37f8a_00037fe9:\n"
        "calll Sys_Milliseconds\n" /* line 763 */
        "movl %ebx, 8(%esp)\n" /* line 765 | sum */
        "subl %esi, %eax\n" /* start */
        "movl %eax, 4(%esp)\n"
        "movl $0x217594, (%esp)\n" /* "Com_TouchMemory: %i msec. Using sum: %d
" */
        "calll Com_Printf\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 766 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf37f8a_0003800b:\n"
        "xorl %ebx, %ebx\n" /* line 751 | sum */
        "jmp .Lf37f8a_00037fba\n"
    );
}

/* line 924 */
__attribute__((naked))
void * Hunk_FindDataForFile(int type, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 924 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* type */
        "movl 0xc(%ebp), %edi\n" /* name */
        "movl $0x400, 4(%esp)\n" /* line 928 */
        "movl %edi, (%esp)\n" /* name */
        "calll FS_HashFileName\n"
        /* { scope 1 */
        "movl com_fileDataHashTable(, %eax, 4), %ebx\n" /* line 906 | searchFileData */
        "testl %ebx, %ebx\n" /* searchFileData */
        "je .Lf38010_0003805c\n"
        ".Lf38010_0003803a:\n"
        "movzbl 8(%ebx), %eax\n" /* line 908 | searchFileData */
        "cmpl %eax, %esi\n"
        "jne .Lf38010_00038055\n"
        "movl %edi, 4(%esp)\n" /* line 910 */
        "leal 9(%ebx), %eax\n" /* searchFileData */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "je .Lf38010_00038066\n"
        ".Lf38010_00038055:\n"
        "movl 4(%ebx), %ebx\n" /* line 906 | searchFileData */
        "testl %ebx, %ebx\n" /* searchFileData */
        "jne .Lf38010_0003803a\n"
        ".Lf38010_0003805c:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1c, %esp\n" /* line 930 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38010_00038066:\n"
        "movl (%ebx), %eax\n" /* line 911 | searchFileData */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 930 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 939 */
__attribute__((naked))
qboolean Hunk_DataOnHunk(void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 939 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* data */
        "movl s_hunkData, %eax\n" /* line 944 */
        "cmpl %eax, %edx\n"
        "jb .Lf38070_00038089\n"
        "addl s_hunkTotal, %eax\n" /* line 946 */
        "cmpl %eax, %edx\n"
        "jb .Lf38070_0003808d\n"
        ".Lf38070_00038089:\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 949 */
        "retl\n"
        ".Lf38070_0003808d:\n"
        "movl $1, %eax\n" /* line 946 */
        "popl %ebp\n" /* line 949 */
        "retl\n"
    );
}

/* line 959 */
__attribute__((naked))
const char * Hunk_SetDataForFile(int type, const char *name, void *data, Alloc_t alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 959 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl $0x400, 4(%esp)\n" /* line 966 */
        "movl 0xc(%ebp), %eax\n" /* name */
        "movl %eax, (%esp)\n"
        "calll FS_HashFileName\n"
        "movl %eax, %esi\n"
        "movl 0xc(%ebp), %edi\n" /* line 896 | name */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "addl $9, %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* alloc */
        "movl %eax, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* line 975 | data */
        "movl %eax, (%ebx)\n"
        "movl 8(%ebp), %eax\n" /* line 976 | type */
        "movb %al, 8(%ebx)\n"
        "leal 9(%ebx), %edi\n" /* line 978 */
        "movl 0xc(%ebp), %eax\n" /* name */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll strcpy\n"
        "movl $com_fileDataHashTable, %edx\n" /* line 979 */
        "movl (%edx, %esi, 4), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl %ebx, (%edx, %esi, 4)\n" /* line 980 */
        "movl %edi, %eax\n" /* line 982 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 991 */
__attribute__((naked))
void Hunk_AddData(int type, void *data, Alloc_t alloc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 991 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $9, (%esp)\n" /* line 997 */
        "calll *0x10(%ebp)\n" /* alloc */
        "movl 0xc(%ebp), %edx\n" /* line 1003 | data */
        "movl %edx, (%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 1004 | type */
        "movb %dl, 8(%eax)\n"
        "movl com_hunkData, %edx\n" /* line 1006 */
        "movl %edx, 4(%eax)\n"
        "movl %eax, com_hunkData\n" /* line 1007 */
        "leave\n" /* line 1008 */
        "retl\n"
    );
}

/* line 1017 */
__attribute__((naked))
void Hunk_OverrideDataForFile(int type, const char *name, void *data)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1017 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* type */
        "movl 0xc(%ebp), %edi\n" /* name */
        /* { scope 1 */
        "movl $0x400, 4(%esp)\n" /* line 1024 */
        "movl %edi, (%esp)\n" /* name */
        "calll FS_HashFileName\n"
        "movl com_fileDataHashTable(, %eax, 4), %ebx\n" /* line 1026 | searchFileData */
        "testl %ebx, %ebx\n" /* searchFileData */
        "jne .Lf3812e_00038161\n"
        "jmp .Lf3812e_00038181\n"
        ".Lf3812e_0003815a:\n"
        "movl 4(%ebx), %ebx\n" /* searchFileData */
        "testl %ebx, %ebx\n" /* searchFileData */
        "je .Lf3812e_00038181\n"
        ".Lf3812e_00038161:\n"
        "movzbl 8(%ebx), %eax\n" /* line 1028 | searchFileData */
        "cmpl %esi, %eax\n" /* type */
        "jne .Lf3812e_0003815a\n"
        "movl %edi, 4(%esp)\n" /* line 1030 | name */
        "leal 9(%ebx), %eax\n" /* searchFileData */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "testl %eax, %eax\n"
        "jne .Lf3812e_0003815a\n"
        "movl 0x10(%ebp), %eax\n" /* line 1032 | data */
        "movl %eax, (%ebx)\n" /* searchFileData */
        /* } scope */
        ".Lf3812e_00038181:\n"
        "addl $0x1c, %esp\n" /* line 1038 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1167 */
__attribute__((naked))
void DB_EnumXAssets(int type, XAssetEnum *func, void *inData, int includeOverride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1167 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "cmpl $1, 8(%ebp)\n" /* line 1173 | type */
        "je .Lf3818a_000381a1\n"
        /* } scope */
        ".Lf3818a_00038199:\n"
        "addl $0x1c, %esp\n" /* line 1199 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf3818a_000381a1:\n"
        "movl $com_fileDataHashTable, %esi\n" /* line 1173 */
        "movl $s_origHunkData, %edi\n"
        ".Lf3818a_000381ab:\n"
        "movl (%esi), %ebx\n" /* line 1196 | fileData */
        /* { scope 2 */
        "testl %ebx, %ebx\n" /* line 1133 */
        "jne .Lf3818a_000381ba\n"
        "jmp .Lf3818a_000381d6\n"
        ".Lf3818a_000381b3:\n"
        "movl 4(%ebx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf3818a_000381d6\n"
        ".Lf3818a_000381ba:\n"
        "cmpb $4, 8(%ebx)\n" /* line 1135 */
        "jne .Lf3818a_000381b3\n"
        "movl (%ebx), %eax\n" /* line 1143 */
        "movl 0x10(%ebp), %edx\n" /* line 1150 | inData */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%ebp)\n" /* func */
        "movl 4(%ebx), %ebx\n" /* line 1133 */
        "testl %ebx, %ebx\n"
        "jne .Lf3818a_000381ba\n"
        ".Lf3818a_000381d6:\n"
        "addl $4, %esi\n"
        /* } scope */
        "cmpl %esi, %edi\n" /* line 1194 */
        "jne .Lf3818a_000381ab\n"
        "jmp .Lf3818a_00038199\n"
    );
}

/* line 1209 */
__attribute__((naked))
int Hunk_SetMark(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1209 */
        "movl %esp, %ebp\n"
        "movl hunk_high, %eax\n"
        "popl %ebp\n" /* line 1216 */
        "retl\n"
    );
}

/* line 1306 */
__attribute__((naked))
int Hunk_Used(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1306 */
        "movl %esp, %ebp\n"
        "movl hunk_low, %eax\n"
        "addl hunk_high, %eax\n"
        "popl %ebp\n" /* line 1311 */
        "retl\n"
    );
}

/* line 1415 */
__attribute__((naked))
void * Hunk_AllocAlignInternal(int size, int alignment)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1415 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* size */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 1434 | alignment */
        "subl $1, %eax\n"
        "movl %edi, %edx\n" /* line 1443 | size */
        "addl hunk_high, %edx\n"
        "leal (%eax, %edx), %edx\n"
        "notl %eax\n"
        "andl %eax, %edx\n"
        "movl %edx, hunk_high\n"
        "movl s_hunkTotal, %ecx\n" /* line 1445 */
        "movl %ecx, %ebx\n" /* buf */
        "addl s_hunkData, %ebx\n" /* buf */
        "subl %edx, %ebx\n" /* buf */
        "movl %edx, 0x3bcf84\n" /* line 1447 */
        "movl 0x3bcf8c, %esi\n" /* line 1449 */
        "leal (%edx, %esi), %eax\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf381fc_0003829d\n"
        "movl %edx, %eax\n" /* line 1454 */
        "leal 0xfffff(%edx), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, %eax\n"
        "leal 0xfffff(%esi), %edx\n"
        "cmpl $-1, %esi\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* size */
        "movl $0x2175c0, 4(%esp)\n" /* "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB," */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf381fc_0003829d:\n"
        "movl %edi, 8(%esp)\n" /* line 1463 | size */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* buf */
        "calll memset\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1466 | buf */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1344 */
__attribute__((naked))
void * Hunk_AllocNoZeroInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1344 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* size */
        /* { scope 1 */
        "movl %edi, %eax\n" /* line 1372 | size */
        "addl hunk_high, %eax\n"
        "leal 0x1f(%eax), %edx\n"
        "andl $0xffffffe0, %edx\n"
        "movl %edx, hunk_high\n"
        "movl s_hunkTotal, %ecx\n" /* line 1374 */
        "movl %ecx, %ebx\n" /* buf */
        "addl s_hunkData, %ebx\n" /* buf */
        "subl %edx, %ebx\n" /* buf */
        "movl %edx, 0x3bcf84\n" /* line 1376 */
        "movl 0x3bcf8c, %esi\n" /* line 1378 */
        "leal (%edx, %esi), %eax\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf382bc_00038356\n"
        "movl %edx, %eax\n" /* line 1383 */
        "leal 0xfffff(%edx), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, %eax\n"
        "leal 0xfffff(%esi), %edx\n"
        "cmpl $-1, %esi\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* size */
        "movl $0x2175c0, 4(%esp)\n" /* "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB," */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf382bc_00038356:\n"
        "movl %ebx, %eax\n" /* line 1395 | buf */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1478 */
__attribute__((naked))
void * Hunk_AllocateTempMemoryHighInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1478 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %esi\n" /* size */
        "movl %esi, %eax\n" /* line 1492 | size */
        "addl 0x3bcf84, %eax\n"
        "leal 0xf(%eax), %edx\n"
        "andl $0xfffffff0, %edx\n"
        "movl %edx, 0x3bcf84\n"
        "movl 0x3bcf8c, %ebx\n" /* line 1494 */
        "movl s_hunkTotal, %ecx\n"
        "leal (%edx, %ebx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jg .Lf38360_000383a3\n"
        "addl s_hunkData, %ecx\n" /* line 1499 */
        "subl %edx, %ecx\n"
        "movl %ecx, %eax\n" /* line 1510 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf38360_000383a3:\n"
        "movl %edx, %eax\n" /* line 1499 */
        "testl %edx, %edx\n"
        "js .Lf38360_00038407\n"
        ".Lf38360_000383a9:\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ebx, %eax\n"
        "leal 0xfffff(%ebx), %edx\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, %eax\n"
        "testl %ecx, %ecx\n"
        "js .Lf38360_0003840f\n"
        ".Lf38360_000383cb:\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* size */
        "movl $0x21760c, 4(%esp)\n" /* "Hunk_AllocateTempMemoryHigh: failed on %i bytes (total %i M" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "movl 0x3bcf84, %edx\n"
        "movl s_hunkTotal, %ecx\n"
        "addl s_hunkData, %ecx\n"
        "subl %edx, %ecx\n"
        "movl %ecx, %eax\n" /* line 1510 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf38360_00038407:\n"
        "leal 0xfffff(%edx), %eax\n" /* line 1499 */
        "jmp .Lf38360_000383a9\n"
        ".Lf38360_0003840f:\n"
        "leal 0xfffff(%ecx), %eax\n"
        "jmp .Lf38360_000383cb\n"
    );
}

/* line 1519 */
__attribute__((naked))
void Hunk_ClearTempMemoryHigh(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1519 */
        "movl %esp, %ebp\n"
        "movl hunk_high, %eax\n" /* line 1523 */
        "movl %eax, 0x3bcf84\n"
        "popl %ebp\n" /* line 1528 */
        "retl\n"
    );
}

/* line 1574 */
__attribute__((naked))
void * Hunk_AllocLowAlignInternal(int size, int alignment)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1574 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* size */
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 1593 | alignment */
        "subl $1, %eax\n"
        "movl %eax, %edx\n" /* line 1601 */
        "addl hunk_low, %edx\n"
        "notl %eax\n"
        "andl %eax, %edx\n"
        "movl %edx, %edi\n" /* line 1603 | buf */
        "addl s_hunkData, %edi\n" /* buf */
        "leal (%edx, %esi), %ecx\n" /* line 1604 */
        "movl %ecx, hunk_low\n"
        "movl %ecx, 0x3bcf8c\n" /* line 1606 */
        "movl 0x3bcf84, %edx\n" /* line 1608 */
        "movl s_hunkTotal, %ebx\n"
        "leal (%ecx, %edx), %eax\n"
        "cmpl %ebx, %eax\n"
        "jle .Lf38428_000384c7\n"
        "movl %edx, %eax\n" /* line 1613 */
        "leal 0xfffff(%edx), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, %eax\n"
        "leal 0xfffff(%ebx), %edx\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* size */
        "movl $0x217664, 4(%esp)\n" /* "Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i " */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf38428_000384c7:\n"
        "movl %esi, 8(%esp)\n" /* line 1622 | size */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buf */
        "calll memset\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 1625 | buf */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1634 */
__attribute__((naked))
void Hunk_ConvertTempToPermLowInternal(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1634 */
        "movl %esp, %ebp\n"
        "movl 0x3bcf8c, %eax\n" /* line 1646 */
        "movl %eax, hunk_low\n"
        "popl %ebp\n" /* line 1647 */
        "retl\n"
    );
}

/* line 1719 */
__attribute__((naked))
void * Hunk_ReallocateTempMemoryInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1719 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* size */
        /* { scope 1 */
        "movl hunk_low, %eax\n" /* line 1727 */
        "addl $0x1f, %eax\n"
        "andl $0xffffffe0, %eax\n"
        "movl %eax, %esi\n" /* line 1729 | buf */
        "addl s_hunkData, %esi\n" /* buf */
        "leal (%eax, %edi), %ecx\n" /* line 1730 */
        "movl %ecx, 0x3bcf8c\n"
        "movl 0x3bcf84, %edx\n" /* line 1732 */
        "movl s_hunkTotal, %ebx\n"
        "leal (%ecx, %edx), %eax\n"
        "cmpl %ebx, %eax\n"
        "jle .Lf384f6_00038588\n"
        "movl %edx, %eax\n" /* line 1737 */
        "leal 0xfffff(%edx), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, %eax\n"
        "leal 0xfffff(%ebx), %edx\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* size */
        "movl $0x2176b0, 4(%esp)\n" /* "Hunk_ReallocateTempMemory: failed on %i bytes (total %i MB," */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        /* } scope */
        ".Lf384f6_00038588:\n"
        "movl %esi, %eax\n" /* line 1745 | buf */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1791 */
__attribute__((naked))
void Hunk_ClearTempMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1791 */
        "movl %esp, %ebp\n"
        "movl s_hunkData, %eax\n" /* line 1795 */
        "testl %eax, %eax\n"
        "je .Lf38592_000385a8\n"
        "movl hunk_low, %eax\n" /* line 1796 */
        "movl %eax, 0x3bcf8c\n"
        ".Lf38592_000385a8:\n"
        "popl %ebp\n" /* line 1801 */
        "retl\n"
    );
}

/* line 1839 */
__attribute__((naked))
int Hunk_HideTempMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1839 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl hunk_low, %eax\n" /* line 1845 */
        "movl 0x3bcf8c, %edx\n" /* line 1846 */
        "movl %edx, hunk_low\n"
        /* } scope */
        "popl %ebp\n" /* line 1849 */
        "retl\n"
    );
}

/* line 1857 */
__attribute__((naked))
void Hunk_ShowTempMemory(int mark)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1857 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 1863 | mark */
        "movl %eax, hunk_low\n"
        "popl %ebp\n" /* line 1864 */
        "retl\n"
    );
}

/* line 1991 */
__attribute__((naked))
void LargeLocalReset(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1991 */
        "movl %esp, %ebp\n"
        "movl $0, g_largeLocalPos\n" /* line 1995 */
        "popl %ebp\n" /* line 1996 */
        "retl\n"
    );
}

/* line 1965 */
__attribute__((naked))
void ZN10LargeLocalD1Ev(void) /* LargeLocal_~LargeLocal */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1965 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 1930 | this */
        "movl (%eax), %eax\n"
        "movl %eax, g_largeLocalPos\n"
        "popl %ebp\n" /* line 1970 */
        "retl\n"
    );
}

/* line 1952 */
__attribute__((naked))
void LargeLocal_LargeLocal(const LargeLocal * _this, int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1952 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl g_largeLocalPos, %eax\n" /* line 1914 */
        "movl 0xc(%ebp), %edx\n" /* line 1915 | size */
        "addl $3, %edx\n"
        "andl $0xfffffffc, %edx\n"
        "addl %eax, %edx\n"
        "movl %edx, g_largeLocalPos\n"
        /* } scope */
        "movl 8(%ebp), %edx\n" /* line 1956 | this */
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 1957 */
        "retl\n"
    );
}

/* line 475 */
__attribute__((naked))
void * Z_TryMallocInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 475 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* size */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 471 */
        "calll malloc\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf3860e_0003863b\n"
        "movl %esi, 8(%esp)\n" /* line 481 | size */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        /* } scope */
        ".Lf3860e_0003863b:\n"
        "movl %ebx, %eax\n" /* line 483 | buf */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1978 */
__attribute__((naked))
void * LargeLocal_GetBuf(const LargeLocal * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1978 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl (%eax), %eax\n" /* this */
        "addl $g_largeLocalBuf, %eax\n" /* this */
        "popl %ebp\n" /* line 1983 */
        "retl\n"
    );
}

/* line 1753 */
__attribute__((naked))
void Hunk_FreeTempMemory(void *buf)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1753 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* buf */
        /* { scope 1 */
        "movl s_hunkData, %edx\n" /* line 1762 */
        "testl %edx, %edx\n"
        "je .Lf38654_000386a4\n"
        "leal -0x10(%ebx), %esi\n" /* line 1768 | buf, hdr */
        "cmpl $0x89537892, -0x10(%ebx)\n" /* line 1769 | buf */
        "je .Lf38654_00038689\n"
        "movl $0x217704, 4(%esp)\n" /* line 1770 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        ".Lf38654_00038689:\n"
        "movl $0x89537893, -0x10(%ebx)\n" /* line 1772 | buf */
        "movl 0x3bcf8c, %eax\n" /* line 1777 */
        "subl 4(%esi), %eax\n" /* hdr */
        "movl %eax, 0x3bcf8c\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 1782 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf38654_000386a4:\n"
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp free\n" /* line 196 */
    );
}

/* line 516 */
__attribute__((naked))
void * Z_VirtualAllocInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 516 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        /* { scope 1 */
        "movl $4, 0xc(%esp)\n" /* line 512 */
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* size */
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll VirtualAlloc\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 521 */
        "je .Lf386b0_000386e8\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 532 | buf */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf386b0_000386e8:\n"
        "movl $0x20c, 4(%esp)\n" /* line 524 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 532 | buf */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 486 */
__attribute__((naked))
void * Z_MallocInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 486 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* size */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 471 */
        "calll malloc\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf38704_0003873a\n"
        "movl %esi, 8(%esp)\n" /* line 481 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 494 | buf */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38704_0003873a:\n"
        "movl $0xdc, 4(%esp)\n" /* line 220 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 494 | buf */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1096 */
static __attribute__((naked))
void Hunk_ClearData(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1096 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl s_hunkData, %eax\n" /* line 1105 */
        "movl %eax, %edi\n" /* low */
        "addl hunk_low, %edi\n" /* low */
        "movl %eax, %esi\n" /* line 1106 | high */
        "addl s_hunkTotal, %esi\n" /* high */
        "subl hunk_high, %esi\n" /* high */
        "movl $0, -0x1c(%ebp)\n" /* hash */
        ".Lf38758_00038783:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1110 | hash */
        "leal com_fileDataHashTable(, %eax, 4), %ebx\n" /* pFileData */
        /* { scope 2 */
        ".Lf38758_0003878d:\n"
        "movl (%ebx), %edx\n" /* line 1054 */
        "testl %edx, %edx\n"
        "je .Lf38758_000387c2\n"
        ".Lf38758_00038793:\n"
        "cmpl %edx, %edi\n" /* line 1057 */
        "ja .Lf38758_0003880d\n"
        "cmpl %edx, %esi\n"
        "jbe .Lf38758_0003880d\n"
        "movl 4(%edx), %eax\n" /* line 1063 */
        "movl %eax, (%ebx)\n"
        "movl (%edx), %ecx\n" /* line 1064 */
        "movzbl 8(%edx), %eax\n" /* line 1066 */
        "cmpb $4, %al\n"
        "je .Lf38758_00038833\n"
        "ja .Lf38758_0003881a\n"
        "cmpb $3, %al\n"
        "jne .Lf38758_0003878d\n"
        "movl %ecx, (%esp)\n" /* line 1069 */
        "calll XModelPartsFree\n"
        "movl (%ebx), %edx\n" /* line 1054 */
        "testl %edx, %edx\n"
        "jne .Lf38758_00038793\n"
        /* } scope */
        ".Lf38758_000387c2:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 1108 | hash */
        "cmpl $0x400, -0x1c(%ebp)\n" /* hash */
        "jne .Lf38758_00038783\n"
        "movl $com_hunkData, %ebx\n" /* pFileData */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf38758_000387d4:\n"
        "movl (%ebx), %edx\n" /* line 1054 */
        "testl %edx, %edx\n"
        "je .Lf38758_00038805\n"
        ".Lf38758_000387da:\n"
        "cmpl %edx, %edi\n" /* line 1057 */
        "ja .Lf38758_00038815\n"
        "cmpl %edx, %esi\n"
        "jbe .Lf38758_00038815\n"
        "movl 4(%edx), %eax\n" /* line 1063 */
        "movl %eax, (%ebx)\n"
        "movl (%edx), %ecx\n" /* line 1064 */
        "movzbl 8(%edx), %eax\n" /* line 1066 */
        "cmpb $4, %al\n"
        "je .Lf38758_00038866\n"
        "ja .Lf38758_0003884d\n"
        "cmpb $3, %al\n"
        "jne .Lf38758_000387d4\n"
        "movl %ecx, (%esp)\n" /* line 1069 */
        "calll XModelPartsFree\n"
        "movl (%ebx), %edx\n" /* line 1054 */
        "testl %edx, %edx\n"
        "jne .Lf38758_000387da\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf38758_00038805:\n"
        "addl $0x2c, %esp\n" /* line 1115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf38758_0003880d:\n"
        "leal 4(%edx), %ebx\n" /* line 1059 */
        "jmp .Lf38758_0003878d\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf38758_00038815:\n"
        "leal 4(%edx), %ebx\n"
        "jmp .Lf38758_000387d4\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        ".Lf38758_0003881a:\n"
        "cmpb $5, %al\n" /* line 1066 */
        "je .Lf38758_00038840\n"
        "cmpb $6, %al\n"
        "jne .Lf38758_0003878d\n"
        "movl %ecx, (%esp)\n" /* line 1081 */
        "calll XAnimFreeList\n"
        "jmp .Lf38758_0003878d\n"
        ".Lf38758_00038833:\n"
        "movl %ecx, (%esp)\n" /* line 1073 */
        "calll XModelFree\n"
        "jmp .Lf38758_0003878d\n"
        ".Lf38758_00038840:\n"
        "movl %ecx, (%esp)\n" /* line 1077 */
        "calll XAnimFree\n"
        "jmp .Lf38758_0003878d\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf38758_0003884d:\n"
        "cmpb $5, %al\n" /* line 1066 */
        "je .Lf38758_00038873\n"
        "cmpb $6, %al\n"
        "jne .Lf38758_000387d4\n"
        "movl %ecx, (%esp)\n" /* line 1081 */
        "calll XAnimFreeList\n"
        "jmp .Lf38758_000387d4\n"
        ".Lf38758_00038866:\n"
        "movl %ecx, (%esp)\n" /* line 1073 */
        "calll XModelFree\n"
        "jmp .Lf38758_000387d4\n"
        ".Lf38758_00038873:\n"
        "movl %ecx, (%esp)\n" /* line 1077 */
        "calll XAnimFree\n"
        "jmp .Lf38758_000387d4\n"
    );
}

/* line 1280 */
__attribute__((naked))
void Hunk_Clear(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1280 */
        "movl %esp, %ebp\n"
        "movl $0, hunk_low\n" /* line 1284 */
        "movl $0, 0x3bcf8c\n" /* line 1285 */
        "movl $0, hunk_high\n" /* line 1287 */
        "movl $0, 0x3bcf84\n" /* line 1288 */
        "popl %ebp\n" /* line 1297 */
        "jmp Hunk_ClearData\n" /* line 1296 */
    );
}

/* line 1259 */
__attribute__((naked))
void Hunk_ClearToMarkLow(int mark)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1259 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* mark */
        "movl %eax, 0x3bcf8c\n" /* line 1265 */
        "movl %eax, hunk_low\n"
        "popl %ebp\n" /* line 1271 */
        "jmp Hunk_ClearData\n" /* line 1266 */
    );
}

/* line 1224 */
__attribute__((naked))
void Hunk_ClearToMark(int mark)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1224 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* mark */
        "movl %eax, 0x3bcf84\n" /* line 1230 */
        "movl %eax, hunk_high\n"
        "popl %ebp\n" /* line 1236 */
        "jmp Hunk_ClearData\n" /* line 1231 */
    );
}

/* line 797 */
__attribute__((naked))
void Com_InitHunkMemory(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 797 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        /* { scope 1 */
        "calll FS_LoadStack\n" /* line 807 */
        "testl %eax, %eax\n"
        "jne .Lf388de_000389a6\n"
        ".Lf388de_000388f1:\n"
        "movl $0x1021, 0x10(%esp)\n" /* line 812 */
        "movl $0x200, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0xa0, 4(%esp)\n"
        "movl $0x217764, (%esp)\n" /* "com_hunkMegs" */
        "calll Dvar_RegisterInt\n"
        "movl 8(%eax), %eax\n" /* line 814 */
        "cmpl $0x4f, %eax\n"
        "jle .Lf388de_000389bf\n"
        "shll $0x14, %eax\n" /* line 821 */
        "movl %eax, s_hunkTotal\n"
        ".Lf388de_00038931:\n"
        "movl $4, 0xc(%esp)\n" /* line 837 */
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll VirtualAlloc\n"
        "movl %eax, s_hunkData\n"
        "testl %eax, %eax\n" /* line 840 */
        "je .Lf388de_000389ef\n"
        ".Lf388de_0003895e:\n"
        "movl %eax, s_origHunkData\n" /* line 857 */
        "movl $0, hunk_low\n" /* line 1284 */
        "movl $0, 0x3bcf8c\n" /* line 1285 */
        "movl $0, hunk_high\n" /* line 1287 */
        "movl $0, 0x3bcf84\n" /* line 1288 */
        "calll Hunk_ClearData\n" /* line 1296 */
        "movl $Com_Meminfo_f, 4(%esp)\n" /* line 867 */
        "movl $0x2177bc, (%esp)\n" /* "meminfo" */
        "calll Cmd_AddCommand\n"
        /* } scope */
        "leave\n" /* line 874 */
        "retl\n"
        /* { scope 1 */
        ".Lf388de_000389a6:\n"
        "movl $0x217724, 4(%esp)\n" /* line 808 */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf388de_000388f1\n"
        ".Lf388de_000389bf:\n"
        "movl $0x50, 8(%esp)\n" /* line 816 */
        "movl $0x50, 4(%esp)\n"
        "movl $0x217774, (%esp)\n" /* "Minimum com_hunkMegs for a dedicated server is %i, allocatin" */
        "calll Com_Printf\n"
        "movl $0x5000000, s_hunkTotal\n" /* line 817 */
        "movl s_hunkTotal, %eax\n"
        "jmp .Lf388de_00038931\n"
        ".Lf388de_000389ef:\n"
        "movl $0x34b, 4(%esp)\n" /* line 843 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        "movl s_hunkData, %eax\n"
        "jmp .Lf388de_0003895e\n"
    );
}

/* line 565 */
__attribute__((naked))
char * CopyStringInternal(const char *in)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 565 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* in */
        "cld\n" /* line 896 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n" /* in, buf */
        "repne scasb %es:(%edi), %al\n" /* buf */
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        /* { scope 1 */
        "movl %ebx, (%esp)\n" /* line 471 */
        "calll malloc\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf38a0e_00038a62\n"
        "movl %ebx, 8(%esp)\n" /* line 481 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        /* } scope */
        "movl %esi, 4(%esp)\n" /* line 570 | in */
        "movl %edi, (%esp)\n" /* buf */
        "calll strcpy\n"
        "movl %edi, %eax\n" /* line 572 | buf */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38a0e_00038a62:\n"
        "movl $0xdc, 4(%esp)\n" /* line 220 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        /* } scope */
        "movl %esi, 4(%esp)\n" /* line 570 | in */
        "movl %edi, (%esp)\n" /* buf */
        "calll strcpy\n"
        "movl %edi, %eax\n" /* line 572 | buf */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 581 */
__attribute__((naked))
void ReplaceStringInternal(char * *str, const char *in)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 581 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl $0xffffffff, %esi\n" /* line 896 */
        "cld\n"
        "movl %esi, %ecx\n"
        "movl 0xc(%ebp), %edi\n" /* in, buf */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* buf */
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "leal -1(%ebx), %edx\n"
        "movl 8(%ebp), %eax\n" /* line 588 | str */
        "movl (%eax), %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* newStr */
        "testl %eax, %eax\n" /* line 589 */
        "je .Lf38a8c_00038aef\n"
        "movl %esi, %ecx\n"
        "movl %eax, %edi\n" /* buf */
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n" /* buf */
        "movl %ecx, %esi\n"
        "notl %esi\n"
        "leal -1(%esi), %ecx\n"
        "cmpl %edx, %ecx\n"
        "jb .Lf38a8c_00038ae4\n"
        "movl 0xc(%ebp), %eax\n" /* line 601 | in */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* newStr */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38a8c_00038ae4:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 196 | newStr */
        "movl %eax, (%esp)\n"
        "calll free\n"
        /* { scope 2 */
        ".Lf38a8c_00038aef:\n"
        "movl %ebx, (%esp)\n" /* line 471 */
        "calll malloc\n"
        "movl %eax, %edi\n"
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf38a8c_00038b33\n"
        "movl %ebx, 8(%esp)\n" /* line 481 */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memset\n"
        /* } scope */
        ".Lf38a8c_00038b11:\n"
        "movl %edi, -0x1c(%ebp)\n" /* line 597 | buf, newStr */
        "movl 8(%ebp), %edx\n" /* line 598 | str */
        "movl %edi, (%edx)\n" /* buf */
        "movl 0xc(%ebp), %eax\n" /* line 601 | in */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %edx\n" /* newStr */
        "movl %edx, (%esp)\n"
        "calll strcpy\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 602 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf38a8c_00038b33:\n"
        "movl $0xdc, 4(%esp)\n" /* line 220 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        "jmp .Lf38a8c_00038b11\n"
    );
}

/* line 1659 */
__attribute__((naked))
void * Hunk_AllocateTempMemoryInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1659 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1 */
        "movl s_hunkData, %edx\n" /* line 1676 */
        "testl %edx, %edx\n"
        "je .Lf38b4a_00038c13\n"
        "movl 8(%ebp), %eax\n" /* line 1679 | size */
        "addl $0x10, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x3bcf8c, %edi\n" /* line 1681 | prev_temp */
        "leal 0xf(%edi), %eax\n" /* line 1682 | prev_temp */
        "andl $0xfffffff0, %eax\n"
        "leal (%edx, %eax), %esi\n" /* line 1684 */
        "movl -0x1c(%ebp), %ecx\n" /* line 1685 */
        "addl %eax, %ecx\n"
        "movl %ecx, 0x3bcf8c\n"
        "movl 0x3bcf84, %eax\n" /* line 1687 */
        "leal (%ecx, %eax), %edx\n"
        "movl s_hunkTotal, %ebx\n" /* buf */
        "cmpl %ebx, %edx\n" /* buf */
        "jg .Lf38b4a_00038bb3\n"
        ".Lf38b4a_00038b96:\n"
        "leal 0x10(%esi), %ebx\n" /* line 1696 | buf */
        "movl $0x89537892, (%esi)\n" /* line 1699 */
        "movl 0x3bcf8c, %eax\n" /* line 1700 */
        "subl %edi, %eax\n" /* prev_temp */
        "movl %eax, 4(%esi)\n"
        /* } scope */
        ".Lf38b4a_00038ba9:\n"
        "movl %ebx, %eax\n" /* line 1708 | buf */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf38b4a_00038bb3:\n"
        "subl %ebx, %edx\n" /* line 1692 | buf */
        "movl %edx, 0x18(%esp)\n"
        "leal 0xfffff(%eax), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, %eax\n" /* buf */
        "leal 0xfffff(%ebx), %edx\n" /* buf */
        "cmpl $-1, %ebx\n" /* buf */
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x2177c4, 4(%esp)\n" /* "Hunk_AllocateTempMemory: failed on %i bytes (total %i MB, l" */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf38b4a_00038b96\n"
        ".Lf38b4a_00038c13:\n"
        "movl 8(%ebp), %eax\n" /* line 471 | size */
        "movl %eax, (%esp)\n"
        "calll malloc\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 480 */
        "je .Lf38b4a_00038c40\n"
        "movl 8(%ebp), %eax\n" /* line 481 | size */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_Memset\n"
        "jmp .Lf38b4a_00038ba9\n"
        ".Lf38b4a_00038c40:\n"
        "movl $0xdc, 4(%esp)\n" /* line 220 */
        "movl $0x2174d0, (%esp)\n" /* "/Users/kevin/Development/i5works/COD2/Project/PC/universal/c" */
        "calll Sys_OutOfMemErrorInternal\n"
        "jmp .Lf38b4a_00038ba9\n"
    );
}

/* line 1548 */
__attribute__((naked))
void * Hunk_AllocLowInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1548 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* size */
        /* { scope 1 */
        "movl hunk_low, %eax\n" /* line 1601 */
        "addl $0x1f, %eax\n"
        "andl $0xffffffe0, %eax\n"
        "movl %eax, %edi\n" /* line 1603 | buf */
        "addl s_hunkData, %edi\n" /* buf */
        "leal (%esi, %eax), %ecx\n" /* line 1604 | size */
        "movl %ecx, hunk_low\n"
        "movl %ecx, 0x3bcf8c\n" /* line 1606 */
        "movl 0x3bcf84, %edx\n" /* line 1608 */
        "movl s_hunkTotal, %ebx\n"
        "leal (%ecx, %edx), %eax\n"
        "cmpl %ebx, %eax\n"
        "jle .Lf38c5a_00038cf2\n"
        "movl %edx, %eax\n" /* line 1613 */
        "leal 0xfffff(%edx), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, %eax\n"
        "leal 0xfffff(%ebx), %edx\n"
        "cmpl $-1, %ebx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* size */
        "movl $0x217664, 4(%esp)\n" /* "Hunk_AllocLowAlign failed on %i bytes (total %i MB, low %i " */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf38c5a_00038cf2:\n"
        "movl %esi, 8(%esp)\n" /* line 1622 | size */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* buf */
        "calll memset\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 1553 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1331 */
__attribute__((naked))
void * Hunk_AllocInternal(int size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1331 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* size */
        /* { scope 1 */
        "movl %edi, %eax\n" /* line 1443 | size */
        "addl hunk_high, %eax\n"
        "leal 0x1f(%eax), %edx\n"
        "andl $0xffffffe0, %edx\n"
        "movl %edx, hunk_high\n"
        "movl s_hunkTotal, %ecx\n" /* line 1445 */
        "movl %ecx, %ebx\n" /* buf */
        "addl s_hunkData, %ebx\n" /* buf */
        "subl %edx, %ebx\n" /* buf */
        "movl %edx, 0x3bcf84\n" /* line 1447 */
        "movl 0x3bcf8c, %esi\n" /* line 1449 */
        "leal (%edx, %esi), %eax\n"
        "cmpl %eax, %ecx\n"
        "jge .Lf38d10_00038daa\n"
        "movl %edx, %eax\n" /* line 1454 */
        "leal 0xfffff(%edx), %edx\n"
        "cmpl $-1, %eax\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl %esi, %eax\n"
        "leal 0xfffff(%esi), %edx\n"
        "cmpl $-1, %esi\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ecx, %eax\n"
        "leal 0xfffff(%ecx), %edx\n"
        "cmpl $-1, %ecx\n"
        "cmovlel %edx, %eax\n"
        "sarl $0x14, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* size */
        "movl $0x2175c0, 4(%esp)\n" /* "Hunk_AllocAlign failed on %i bytes (total %i MB, low %i MB," */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        ".Lf38d10_00038daa:\n"
        "movl %edi, 8(%esp)\n" /* line 1463 | size */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* buf */
        "calll memset\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1336 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

