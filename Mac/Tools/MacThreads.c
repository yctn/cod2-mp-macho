/* ASM dump from: MacThreads.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacThreads.cp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/Tools/MacExceptions.h"
 */

void ZN6CMutexD1Ev(void); /* CMutex_~CMutex */
int CThread_Run(const CThread * _this, void *inArg);
void CThread_Stop(const CThread * _this);
Boolean CThread_IsRunning(const CThread * _this);
void * CThread_ExecuteProc(void *inArg);
void CMutex_CMutex(const CMutex * _this);
void CThread_CThread(const CThread * _this);
void ZN11StMutexLockD1Ev(void); /* StMutexLock_~StMutexLock */
void ZN12StThreadLockD1Ev(void); /* StThreadLock_~StThreadLock */
void ZN7CThreadD2Ev(void); /* CThread_~CThread */
void ZN7CThreadD1Ev(void); /* CThread_~CThread */
void ZN7CThreadD0Ev(void); /* CThread_~CThread */
void StMutexLock_StMutexLock(const StMutexLock * _this, CMutex *inMutex);
void StThreadLock_StThreadLock(const StThreadLock * _this, CThread *inThread);

/* line 33 */
__attribute__((naked))
void ZN6CMutexD1Ev(void) /* CMutex_~CMutex */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 33 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 35 | this */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "leave\n" /* line 36 */
        "retl\n"
    );
}

/* line 99 */
__attribute__((naked))
int CThread_Run(const CThread * _this, void *inArg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1 */
        "cmpb $0, 0x38(%ebx)\n" /* line 103 | this */
        "je .Lf117b50_00117b68\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf117b50_00117b62:\n"
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf117b50_00117b68:\n"
        "movl 0xc(%ebp), %eax\n" /* line 105 | inArg */
        "movl %eax, 8(%ebx)\n" /* this */
        "movb $1, 0x38(%ebx)\n" /* line 106 | this */
        "movl %ebx, 0xc(%esp)\n" /* line 108 | this */
        "movl $CThread_ExecuteProc, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll pthread_create\n"
        "testl %eax, %eax\n" /* line 110 */
        "je .Lf117b50_00117b62\n"
        "movb $0, 0x38(%ebx)\n" /* line 112 | this */
        /* } scope */
        "addl $0x14, %esp\n" /* line 117 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 122 */
__attribute__((naked))
void CThread_Stop(const CThread * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 124 | this */
        "movb $0, 0x38(%eax)\n"
        "movl $0x186a0, (%esp)\n" /* line 125 */
        "calll usleep\n"
        "leave\n" /* line 126 */
        "retl\n"
    );
}

/* line 131 */
__attribute__((naked))
Boolean CThread_IsRunning(const CThread * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movzbl 0x38(%eax), %eax\n" /* this */
        "popl %ebp\n" /* line 134 */
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
void * CThread_ExecuteProc(void *inArg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* inArg */
        "movl (%ebx), %edx\n" /* line 143 | inArg */
        "movl 8(%ebx), %eax\n" /* inArg */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* inArg */
        "calll *8(%edx)\n"
        "movb $0, 0x38(%ebx)\n" /* line 144 | inArg */
        "xorl %eax, %eax\n" /* line 146 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 16 */
__attribute__((naked))
void CMutex_CMutex(const CMutex * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 16 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        /* { scope 1 */
        "leal -0x14(%ebp), %esi\n" /* line 19 | attr */
        "movl %esi, (%esp)\n"
        "calll pthread_mutexattr_init\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf117bee_00117c41\n"
        "movl $2, 4(%esp)\n" /* line 22 */
        "movl %esi, (%esp)\n"
        "calll pthread_mutexattr_settype\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf117bee_00117c41\n"
        "movl %esi, 4(%esp)\n" /* line 25 */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_init\n"
        "movl %eax, %ebx\n" /* error */
        "testl %eax, %eax\n" /* line 30 */
        "jne .Lf117bee_00117c41\n"
        "movl %esi, (%esp)\n" /* line 28 */
        "calll pthread_mutexattr_destroy\n"
        /* } scope */
        "addl $0x20, %esp\n" /* line 29 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf117bee_00117c41:\n"
        "movl $4, (%esp)\n" /* line 21 */
        "calll ___cxa_allocate_exception\n"
        "movl %ebx, (%eax)\n" /* error */
        "movl $0, 8(%esp)\n"
        "movl __ZTIl, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___cxa_throw\n"
    );
}

/* line 81 */
__attribute__((naked))
void CThread_CThread(const CThread * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 81 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $0x332348, (%ebx)\n" /* line 84 | this */
        "movl $0, 4(%ebx)\n" /* this */
        "movl $0, 8(%ebx)\n" /* this */
        "leal 0xc(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CMutex_CMutex\n"
        "movb $0, 0x38(%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 69 */
__attribute__((naked))
void ZN11StMutexLockD1Ev(void) /* StMutexLock_~StMutexLock */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "cmpb $0, 4(%eax)\n" /* line 71 */
        "jne .Lf117ca0_00117cb1\n"
        "leave\n" /* line 75 */
        "retl\n"
        ".Lf117ca0_00117cb1:\n"
        "movl (%eax), %eax\n" /* line 53 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_unlock\n"
        "leave\n" /* line 75 */
        "retl\n"
    );
}

/* line 161 */
__attribute__((naked))
void ZN12StThreadLockD1Ev(void) /* StThreadLock_~StThreadLock */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 161 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "cmpb $0, 4(%eax)\n" /* line 163 */
        "jne .Lf117cbe_00117ccf\n"
        "leave\n" /* line 167 */
        "retl\n"
        ".Lf117cbe_00117ccf:\n"
        "movl (%eax), %eax\n" /* line 53 */
        "addl $0xc, %eax\n"
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_unlock\n"
        "leave\n" /* line 167 */
        "retl\n"
    );
}

/* line 90 */
__attribute__((naked))
void ZN7CThreadD2Ev(void) /* CThread_~CThread */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $0x332348, (%esi)\n" /* this */
        "movb $0, 0x38(%esi)\n" /* line 124 | this */
        "movl $0x186a0, (%esp)\n" /* line 125 */
        "calll usleep\n"
        "leal 0xc(%esi), %eax\n" /* line 35 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "addl $0x10, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "leal 0xc(%esi), %eax\n" /* line 35 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "movl %ebx, (%esp)\n" /* line 36 */
        "calll __Unwind_Resume\n"
    );
}

/* line 90 */
__attribute__((naked))
void ZN7CThreadD1Ev(void) /* CThread_~CThread */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $0x332348, (%esi)\n" /* this */
        "movb $0, 0x38(%esi)\n" /* line 124 | this */
        "movl $0x186a0, (%esp)\n" /* line 125 */
        "calll usleep\n"
        "leal 0xc(%esi), %eax\n" /* line 35 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "addl $0x10, %esp\n" /* line 93 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "leal 0xc(%esi), %eax\n" /* line 35 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "movl %ebx, (%esp)\n" /* line 36 */
        "calll __Unwind_Resume\n"
    );
}

/* line 90 */
__attribute__((naked))
void ZN7CThreadD0Ev(void) /* CThread_~CThread */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $0x332348, (%esi)\n" /* this */
        "movb $0, 0x38(%esi)\n" /* line 124 | this */
        "movl $0x186a0, (%esp)\n" /* line 125 */
        "calll usleep\n"
        "leal 0xc(%esi), %eax\n" /* line 35 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "movl %esi, 8(%ebp)\n" /* line 93 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl %eax, %ebx\n"
        "leal 0xc(%esi), %eax\n" /* line 35 */
        "movl %eax, (%esp)\n"
        "calll pthread_mutex_destroy\n"
        "movl %ebx, (%esp)\n" /* line 36 */
        "calll __Unwind_Resume\n"
    );
}

/* line 61 */
__attribute__((naked))
void StMutexLock_StMutexLock(const StMutexLock * _this, CMutex *inMutex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 61 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* inMutex */
        "movl %eax, (%ebx)\n" /* line 62 | this */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 43 | error */
        "calll pthread_mutex_lock\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 64 */
        "sete 4(%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 65 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 153 */
__attribute__((naked))
void StThreadLock_StThreadLock(const StThreadLock * _this, CThread *inThread)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 153 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* inThread */
        "movl %eax, (%ebx)\n" /* line 154 | this */
        /* { scope 1 */
        "addl $0xc, %eax\n" /* line 43 | error */
        "movl %eax, (%esp)\n" /* error */
        "calll pthread_mutex_lock\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 156 */
        "sete 4(%ebx)\n" /* this */
        "addl $0x14, %esp\n" /* line 157 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

