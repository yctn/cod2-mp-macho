/* macOS libc compatibility stubs for Linux */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

/* macOS ___tolower / ___maskrune are used by naked ASM code */
int ___tolower(int c) { return tolower(c); }
int ___maskrune(int c, unsigned long f) { 
    /* Simplified: just check basic character classes */
    if (f & 0x00000100) return isalpha(c);  /* _CTYPE_A */
    if (f & 0x00000400) return isdigit(c);  /* _CTYPE_D */
    if (f & 0x00002000) return isspace(c);  /* _CTYPE_S */
    if (f & 0x00008000) return isupper(c);  /* _CTYPE_U */
    if (f & 0x00004000) return islower(c);  /* _CTYPE_L */
    return 0;
}

/* Mac threading */
int pthread_main_np(void) { return 1; }

/* Mac timing functions used by WinSleep (now replaced, but some ASM still refs) */
typedef struct { unsigned int hi; unsigned int lo; } AbsoluteTime;
AbsoluteTime UpTime(void) { AbsoluteTime t = {0,0}; return t; }
AbsoluteTime AddDurationToAbsolute(int duration, AbsoluteTime absTime) { return absTime; }
int MPDelayUntil(AbsoluteTime *expiration) { return 0; }
void Microseconds(long long *us) { 
    struct timeval tv;
    gettimeofday(&tv, 0);
    *us = (long long)tv.tv_sec * 1000000LL + tv.tv_usec;
}

/* Mac memory */
void *NewPtrClear(long size) { return calloc(1, size); }
void DisposePtr(void *p) { free(p); }

/* Mac Toolbox atomic ops (used by unconverted ASM) */
int OTAtomicAdd32(int val, volatile int *addr) {
    return __sync_add_and_fetch(addr, val);
}
int OTCompareAndSwap32(int oldVal, int newVal, volatile int *addr) {
    return __sync_bool_compare_and_swap(addr, oldVal, newVal);
}

/* ___isnanf - macOS mangling of isnanf */
int ___isnanf(float f) { return isnan(f); }

/* ___toupper */
int ___toupper(int c) { return toupper(c); }

/* ___dynamic_cast is handled in cpp_compat.S */

/* ___sF - macOS stdio FILE array (stdin/stdout/stderr) */
/* This is referenced by unconverted ASM that uses macOS FILE* offsets */
/* Provide a dummy - the converted code doesn't need it */
void *___sF[3] = {0, 0, 0};
