/* macOS libc compatibility stubs for Linux */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

/* Forward declaration for ___maskrune */
static unsigned int bsd_rune_data[13 + 256];

/* macOS ___tolower / ___maskrune are used by naked ASM code */
int ___tolower(int c) { return tolower(c); }
int ___maskrune(int c, unsigned long f) {
    /* Look up BSD __runetype and mask with requested flags */
    if ((unsigned int)c > 0xFF) return 0;
    unsigned int *rt = &bsd_rune_data[13]; /* __runetype at offset 0x34 */
    return rt[(unsigned char)c] & f;
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
/* ASM references patched to use Linux stdin/stdout/stderr directly */
/* Keep symbol defined to avoid link errors from any remaining refs */
void *___sF[3] = {0, 0, 0};

/*
 * BSD _DefaultRuneLocale compatibility for macOS ctype.
 * macOS code accesses __runetype[c] at offset 0x34 from base:
 *   movl __DefaultRuneLocale, %eax    (load import pointer)
 *   movl 0x34(%eax, %edx, 4), %eax   (load __runetype[edx])
 *
 * Flag bits used by the code:
 *   bit  8 (0x0100) = _CTYPE_A (alpha)     - shrl $8 + andl $1
 *   bit 10 (0x0400) = _CTYPE_D (digit)     - testl $0x500, testb $4 at +1
 *   bit 14 (0x4000) = _CTYPE_S (space)     - shrl $0xe + andl $1
 *   bit  2 (0x0004) = old BSD _N (digit)   - C code: & 4
 */
static unsigned int bsd_rune_data[13 + 256]; /* 0x34 header + __runetype[256] */
void *__DefaultRuneLocale;

__attribute__((constructor))
static void init_rune_locale(void) {
    unsigned int *rt = &bsd_rune_data[13]; /* __runetype starts at offset 0x34 */
    int i;

    __DefaultRuneLocale = bsd_rune_data;

    /* Control characters 0x00-0x1f, 0x7f */
    for (i = 0; i < 0x20; i++)
        rt[i] = 0x0200;
    rt[0x7f] = 0x0200;

    /* Whitespace: \t \n \v \f \r */
    rt['\t'] |= 0x4000 | 0x20000 | 0x08 | 0x80;  /* space + blank */
    rt['\n'] |= 0x4000 | 0x08;
    rt['\v'] |= 0x4000 | 0x08;
    rt['\f'] |= 0x4000 | 0x08;
    rt['\r'] |= 0x4000 | 0x08;

    /* Space (0x20): space + blank + print */
    rt[' '] = 0x4000 | 0x20000 | 0x40000 | 0x08 | 0x80;

    /* Digits 0-9 */
    for (i = '0'; i <= '9'; i++)
        rt[i] = 0x0400 | 0x0004 | 0x0800 | 0x40000 | 0x10000 | 0x40;

    /* Uppercase A-Z */
    for (i = 'A'; i <= 'Z'; i++) {
        rt[i] = 0x0100 | 0x8000 | 0x0800 | 0x40000 | 0x01;
        if (i <= 'F') rt[i] |= 0x10000 | 0x40;
    }

    /* Lowercase a-z */
    for (i = 'a'; i <= 'z'; i++) {
        rt[i] = 0x0100 | 0x1000 | 0x0800 | 0x40000 | 0x02;
        if (i <= 'f') rt[i] |= 0x10000 | 0x40;
    }

    /* Punctuation: printable non-alnum non-space */
    for (i = '!'; i <= '/'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
    for (i = ':'; i <= '@'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
    for (i = '['; i <= '`'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
    for (i = '{'; i <= '~'; i++)
        rt[i] = 0x2000 | 0x0800 | 0x40000 | 0x10;
}
