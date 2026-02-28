/* Converted to C from ASM: MacThreads.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacThreads.cp */
/* Linux replacement: pthreads */

#include "common_types.h"
#include "imports.h"

#include <pthread.h>
#include <unistd.h>

extern void __ZdlPv(void *); /* operator delete */

/* CMutex layout: pthread_mutex_t at offset 0 (size 0xc on Mac, 24 on Linux 32-bit) */
/* CThread layout: vtable(0), pthread_t(4), arg(8), mutex at 0xc, running at 0x38 */

static void *CThread_ExecuteProc(void *inArg);

void ZN6CMutexD1Ev(void) /* CMutex_~CMutex */
{
    /* Stub - mutex destroyed in CThread destructor */
}

int CThread_Run(const CThread *_this, void *inArg)
{
    CThread *self = (CThread *)_this;
    char *p = (char *)self;

    if (*(char *)(p + 0x38)) /* already running */
        return 0;

    *(void **)(p + 8) = inArg;
    *(char *)(p + 0x38) = 1;

    int err = pthread_create((pthread_t *)(p + 4), NULL, CThread_ExecuteProc, self);
    if (err != 0) {
        *(char *)(p + 0x38) = 0;
    }
    return err;
}

void CThread_Stop(const CThread *_this)
{
    char *p = (char *)_this;
    *(char *)(p + 0x38) = 0;
    usleep(100000); /* 100ms */
}

Boolean CThread_IsRunning(const CThread *_this)
{
    const char *p = (const char *)_this;
    return *(unsigned char *)(p + 0x38);
}

static void *CThread_ExecuteProc(void *inArg)
{
    char *self = (char *)inArg;
    void **vtable = *(void ***)self;
    /* vtable[2] is the virtual Execute method */
    typedef int (*ExecuteFn)(void *, void *);
    ExecuteFn execute = (ExecuteFn)vtable[2];
    execute(self, *(void **)(self + 8));
    *(char *)(self + 0x38) = 0;
    return NULL;
}

void CMutex_CMutex(const CMutex *_this)
{
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init((pthread_mutex_t *)_this, &attr);
    pthread_mutexattr_destroy(&attr);
}

void CThread_CThread(const CThread *_this)
{
    char *p = (char *)_this;
    *(void **)(p + 0) = (void *)0x332348; /* vtable */
    *(int *)(p + 4) = 0; /* thread */
    *(void **)(p + 8) = NULL; /* arg */
    CMutex_CMutex((const CMutex *)(p + 0xc));
    *(char *)(p + 0x38) = 0; /* running */
}

void ZN11StMutexLockD1Ev(void) /* StMutexLock_~StMutexLock */
{
    /* Destructor unlocks mutex if locked.
     * Layout: mutex_ptr(0), locked(4) */
    /* Stub - will be called via C++ mechanism */
}

void ZN12StThreadLockD1Ev(void) /* StThreadLock_~StThreadLock */
{
    /* Stub */
}

void ZN7CThreadD2Ev(void) /* CThread_~CThread (base) */
{
    /* Stub - cleanup done in D1 */
}

void ZN7CThreadD1Ev(void) /* CThread_~CThread (complete) */
{
    /* Stub */
}

void ZN7CThreadD0Ev(void) /* CThread_~CThread (deleting) */
{
    /* Stub */
}

void StMutexLock_StMutexLock(const StMutexLock *_this, CMutex *inMutex)
{
    char *p = (char *)_this;
    *(CMutex **)(p + 0) = inMutex;
    int err = pthread_mutex_lock((pthread_mutex_t *)inMutex);
    *(char *)(p + 4) = (err == 0) ? 1 : 0;
}

void StThreadLock_StThreadLock(const StThreadLock *_this, CThread *inThread)
{
    char *p = (char *)_this;
    *(CThread **)(p + 0) = inThread;
    int err = pthread_mutex_lock((pthread_mutex_t *)((char *)inThread + 0xc));
    *(char *)(p + 4) = (err == 0) ? 1 : 0;
}
