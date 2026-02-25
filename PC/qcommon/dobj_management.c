/* ASM dump from: dobj_management.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/dobj_management.cpp */

#include "common_types.h"
#include "imports.h"

static objBufEntry objBuf[2048]; /* 0x4b7580 */
static Bool objAlloced[2048]; /* 0x4b6d80 */
static int objFreeCount; /* 0x4b6d00 */
static short int clientObjMap[1152]; /* 0x4b6400 */
static short int serverObjMap[1024]; /* 0x4b5c00 */
static int com_lastDObjIndex; /* 0x4b5b84 */
static qboolean g_bDObjInited; /* 0x4b5b80 */

struct DObj_s * Com_GetClientDObj(int handle, int localClientNum);
struct DObj_s * Com_GetServerDObj(int handle);
int Com_ClientDObjClearAllSkel(void);
int Com_ServerDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle);
int Com_SafeClientDObjFree(int handle);
int Com_SafeServerDObjFree(int handle);
int Com_InitDObj(void);
int Com_ShutdownDObj(void);
int Com_AbortDObj(void);
int Com_ClientDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle);

/* line 71 */
__attribute__((naked))
struct DObj_s * Com_GetClientDObj(int handle, int localClientNum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* localClientNum */
        "leal (%eax, %eax, 8), %eax\n" /* line 80 */
        "shll $7, %eax\n"
        "addl 8(%ebp), %eax\n" /* handle */
        "movzwl clientObjMap(%eax, %eax), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf73c9c_00073cc8\n"
        "cwtl\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 81 */
        "retl\n"
        ".Lf73c9c_00073cc8:\n"
        "xorl %eax, %eax\n" /* line 80 */
        "popl %ebp\n" /* line 81 */
        "retl\n"
    );
}

/* line 90 */
__attribute__((naked))
struct DObj_s * Com_GetServerDObj(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 94 | handle */
        "movzwl serverObjMap(%eax, %eax), %eax\n"
        "testw %ax, %ax\n"
        "je .Lf73ccc_00073cef\n"
        "cwtl\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "popl %ebp\n" /* line 95 */
        "retl\n"
        ".Lf73ccc_00073cef:\n"
        "xorl %eax, %eax\n" /* line 94 */
        "popl %ebp\n" /* line 95 */
        "retl\n"
    );
}

/* line 243 */
__attribute__((naked))
int Com_ClientDObjClearAllSkel(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 243 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl $clientObjMap, %ebx\n"
        "movl $objFreeCount, %esi\n"
        "jmp .Lf73cf4_00073d0f\n"
        /* { scope 1 */
        ".Lf73cf4_00073d08:\n"
        "addl $2, %ebx\n" /* line 264 */
        "cmpl %ebx, %esi\n" /* line 255 */
        "je .Lf73cf4_00073d36\n"
        ".Lf73cf4_00073d0f:\n"
        "movzwl (%ebx), %eax\n" /* line 260 */
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 262 */
        "je .Lf73cf4_00073d08\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 264 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "movl %eax, (%esp)\n"
        "calll DObjSkelClear\n"
        "addl $2, %ebx\n"
        "cmpl %ebx, %esi\n" /* line 255 */
        "jne .Lf73cf4_00073d0f\n"
        /* } scope */
        ".Lf73cf4_00073d36:\n"
        "addl $0x10, %esp\n" /* line 266 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 275 */
__attribute__((naked))
int Com_ServerDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 275 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* dobjModels */
        "movl %eax, -0x1c(%ebp)\n" /* dobjModels */
        "movl 0x10(%ebp), %eax\n" /* tree */
        "movl %eax, -0x20(%ebp)\n" /* tree */
        "movl 0x14(%ebp), %esi\n" /* handle */
        "movl 0xc(%ebp), %edi\n" /* numModels */
        /* { scope 1 */
        "movl com_lastDObjIndex, %ebx\n" /* line 163 */
        "leal 1(%ebx), %edx\n"
        "cmpl $0x7ff, %edx\n"
        "jg .Lf73d3e_00073dda\n"
        "cmpb $0, objAlloced(%edx)\n" /* line 165 */
        "jne .Lf73d3e_00073e07\n"
        ".Lf73d3e_00073d77:\n"
        "movl %edx, com_lastDObjIndex\n" /* line 185 */
        "movb $1, objAlloced(%edx)\n" /* line 188 */
        "subl $1, objFreeCount\n" /* line 190 */
        "movl %edx, %eax\n"
        ".Lf73d3e_00073d8d:\n"
        "movw %ax, serverObjMap(%esi, %esi)\n" /* line 289 | handle */
        "leal 1(%esi), %eax\n" /* line 291 | handle */
        "movzwl %ax, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* tree */
        "movl %eax, 8(%esp)\n"
        "movzwl %di, %eax\n" /* numModels */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* dobjModels */
        "movl %eax, (%esp)\n"
        "calll DObjCreate\n"
        "movl objFreeCount, %eax\n" /* line 293 */
        "testl %eax, %eax\n"
        "je .Lf73d3e_00073e28\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 295 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf73d3e_00073dda:\n"
        "testl %ebx, %ebx\n" /* line 181 */
        "jg .Lf73d3e_00073de4\n"
        ".Lf73d3e_00073dde:\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf73d3e_00073d8d\n"
        ".Lf73d3e_00073de4:\n"
        "cmpb $0, 0x4b6d81\n" /* line 183 */
        "je .Lf73d3e_00073e42\n"
        "movl $1, %edx\n"
        ".Lf73d3e_00073df2:\n"
        "addl $1, %edx\n" /* line 181 */
        "cmpl %edx, %ebx\n"
        "jl .Lf73d3e_00073dde\n"
        "cmpb $0, objAlloced(%edx)\n" /* line 183 */
        "jne .Lf73d3e_00073df2\n"
        "jmp .Lf73d3e_00073d77\n"
        ".Lf73d3e_00073e07:\n"
        "leal objAlloced(%edx), %ecx\n" /* line 165 */
        ".Lf73d3e_00073e0d:\n"
        "addl $1, %edx\n" /* line 163 */
        "cmpl $0x800, %edx\n"
        "je .Lf73d3e_00073dda\n"
        "movzbl 1(%ecx), %eax\n" /* line 165 */
        "addl $1, %ecx\n"
        "testb %al, %al\n"
        "jne .Lf73d3e_00073e0d\n"
        "jmp .Lf73d3e_00073d77\n"
        ".Lf73d3e_00073e28:\n"
        "movl $0x21bf60, 0xc(%ebp)\n" /* line 294 | numModels */
        "movl $1, 8(%ebp)\n" /* dobjModels */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 295 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Error\n" /* line 294 */
        ".Lf73d3e_00073e42:\n"
        "movl $1, %edx\n" /* line 183 */
        "jmp .Lf73d3e_00073d77\n"
    );
}

/* line 360 */
__attribute__((naked))
int Com_SafeClientDObjFree(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 360 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* handle */
        /* { scope 1 */
        "movzwl clientObjMap(%ecx, %ecx), %eax\n" /* line 375 */
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 376 */
        "jne .Lf73e4c_00073e64\n"
        /* } scope */
        "popl %ebp\n" /* line 395 */
        "retl\n"
        /* { scope 1 */
        ".Lf73e4c_00073e64:\n"
        "movw $0, clientObjMap(%ecx, %ecx)\n" /* line 378 */
        "movb $0, objAlloced(%edx)\n" /* line 388 */
        "addl $1, objFreeCount\n" /* line 389 */
        "leal (%edx, %edx, 4), %eax\n" /* line 390 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* handle */
        /* } scope */
        "popl %ebp\n" /* line 395 */
        /* { scope 1 */
        "jmp DObjFree\n" /* line 390 */
    );
}

/* line 404 */
__attribute__((naked))
int Com_SafeServerDObjFree(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 404 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* handle */
        /* { scope 1 */
        "movzwl serverObjMap(%ecx, %ecx), %eax\n" /* line 410 */
        "movswl %ax, %edx\n"
        "testw %ax, %ax\n" /* line 411 */
        "jne .Lf73e92_00073eaa\n"
        /* } scope */
        "popl %ebp\n" /* line 434 */
        "retl\n"
        /* { scope 1 */
        ".Lf73e92_00073eaa:\n"
        "movw $0, serverObjMap(%ecx, %ecx)\n" /* line 413 */
        "movb $0, objAlloced(%edx)\n" /* line 427 */
        "addl $1, objFreeCount\n" /* line 428 */
        "leal (%edx, %edx, 4), %eax\n" /* line 429 */
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "movl %eax, 8(%ebp)\n" /* handle */
        /* } scope */
        "popl %ebp\n" /* line 434 */
        /* { scope 1 */
        "jmp DObjFree\n" /* line 429 */
    );
}

/* line 443 */
__attribute__((naked))
int Com_InitDObj(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 443 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x800, 8(%esp)\n" /* line 445 */
        "movl $0, 4(%esp)\n"
        "movl $objAlloced, (%esp)\n"
        "calll Com_Memset\n"
        "movl $0x7ff, objFreeCount\n" /* line 446 */
        "movl $0x900, 8(%esp)\n" /* line 450 */
        "movl $0, 4(%esp)\n"
        "movl $clientObjMap, (%esp)\n"
        "calll Com_Memset\n"
        "movl $0x800, 8(%esp)\n" /* line 451 */
        "movl $0, 4(%esp)\n"
        "movl $serverObjMap, (%esp)\n"
        "calll Com_Memset\n"
        "movl $1, com_lastDObjIndex\n" /* line 452 */
        "movl $1, g_bDObjInited\n" /* line 453 */
        "leave\n" /* line 454 */
        "retl\n"
    );
}

/* line 463 */
__attribute__((naked))
int Com_ShutdownDObj(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 463 */
        "movl %esp, %ebp\n"
        "movl $0, g_bDObjInited\n" /* line 471 */
        "popl %ebp\n" /* line 486 */
        "retl\n"
    );
}

/* line 495 */
__attribute__((naked))
int Com_AbortDObj(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 495 */
        "movl %esp, %ebp\n"
        "movl $0, g_bDObjInited\n" /* line 497 */
        "popl %ebp\n" /* line 498 */
        "retl\n"
    );
}

/* line 210 */
__attribute__((naked))
int Com_ClientDObjCreate(DObjModel_s *dobjModels, int numModels, struct XAnimTree_s *tree, int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* dobjModels */
        "movl %eax, -0x1c(%ebp)\n" /* dobjModels */
        "movl 0x10(%ebp), %eax\n" /* tree */
        "movl %eax, -0x20(%ebp)\n" /* tree */
        "movl 0x14(%ebp), %esi\n" /* handle */
        "movl 0xc(%ebp), %edi\n" /* numModels */
        /* { scope 1 */
        "movl com_lastDObjIndex, %ebx\n" /* line 163 */
        "leal 1(%ebx), %edx\n"
        "cmpl $0x7ff, %edx\n"
        "jg .Lf73f72_0007400d\n"
        "cmpb $0, objAlloced(%edx)\n" /* line 165 */
        "jne .Lf73f72_0007403a\n"
        ".Lf73f72_00073fab:\n"
        "movl %edx, com_lastDObjIndex\n" /* line 185 */
        "movb $1, objAlloced(%edx)\n" /* line 188 */
        "subl $1, objFreeCount\n" /* line 190 */
        "movl %edx, %eax\n"
        ".Lf73f72_00073fc1:\n"
        "movw %ax, clientObjMap(%esi, %esi)\n" /* line 228 | handle */
        "movl $0, 0x10(%esp)\n" /* line 230 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%eax, %eax, 4), %eax\n"
        "leal objBuf(, %eax, 4), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* tree */
        "movl %eax, 8(%esp)\n"
        "movzwl %di, %eax\n" /* numModels */
        "movl %eax, 4(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* dobjModels */
        "movl %eax, (%esp)\n"
        "calll DObjCreate\n"
        "movl objFreeCount, %edx\n" /* line 232 */
        "testl %edx, %edx\n"
        "je .Lf73f72_0007405b\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf73f72_0007400d:\n"
        "testl %ebx, %ebx\n" /* line 181 */
        "jg .Lf73f72_00074017\n"
        ".Lf73f72_00074011:\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf73f72_00073fc1\n"
        ".Lf73f72_00074017:\n"
        "cmpb $0, 0x4b6d81\n" /* line 183 */
        "je .Lf73f72_00074075\n"
        "movl $1, %edx\n"
        ".Lf73f72_00074025:\n"
        "addl $1, %edx\n" /* line 181 */
        "cmpl %edx, %ebx\n"
        "jl .Lf73f72_00074011\n"
        "cmpb $0, objAlloced(%edx)\n" /* line 183 */
        "jne .Lf73f72_00074025\n"
        "jmp .Lf73f72_00073fab\n"
        ".Lf73f72_0007403a:\n"
        "leal objAlloced(%edx), %ecx\n" /* line 165 */
        ".Lf73f72_00074040:\n"
        "addl $1, %edx\n" /* line 163 */
        "cmpl $0x800, %edx\n"
        "je .Lf73f72_0007400d\n"
        "movzbl 1(%ecx), %eax\n" /* line 165 */
        "addl $1, %ecx\n"
        "testb %al, %al\n"
        "jne .Lf73f72_00074040\n"
        "jmp .Lf73f72_00073fab\n"
        ".Lf73f72_0007405b:\n"
        "movl $0x21bf60, 0xc(%ebp)\n" /* line 233 | numModels */
        "movl $1, 8(%ebp)\n" /* dobjModels */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 234 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Com_Error\n" /* line 233 */
        ".Lf73f72_00074075:\n"
        "movl $1, %edx\n" /* line 183 */
        "jmp .Lf73f72_00073fab\n"
    );
}

