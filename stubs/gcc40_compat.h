#ifndef COD2_GCC40_COMPAT_H
#define COD2_GCC40_COMPAT_H

/* GCC 4.0 predates the __sync_* builtins used by some Linux shim code. */

#ifdef __EMSCRIPTEN__
/* Emscripten: use __sync builtins (available in clang/WASM) */
static __inline__ int cod2_sync_fetch_and_add_i32(volatile int *ptr, int val)
{ return __sync_fetch_and_add(ptr, val); }
static __inline__ int cod2_sync_add_and_fetch_i32(volatile int *ptr, int val)
{ return __sync_add_and_fetch(ptr, val); }
static __inline__ int cod2_sync_val_compare_and_swap_i32(volatile int *ptr, int oldval, int newval)
{ return __sync_val_compare_and_swap(ptr, oldval, newval); }
static __inline__ int cod2_sync_bool_compare_and_swap_i32(volatile int *ptr, int oldval, int newval)
{ return __sync_bool_compare_and_swap(ptr, oldval, newval); }
static __inline__ int cod2_sync_lock_test_and_set_i32(volatile int *ptr, int val)
{ return __sync_lock_test_and_set(ptr, val); }
#else
static __inline__ int cod2_sync_fetch_and_add_i32(volatile int *ptr, int val)
{
    __asm__ __volatile__(
        "lock; xaddl %0, %1"
        : "+r"(val), "+m"(*ptr)
        :
        : "memory", "cc");
    return val;
}

static __inline__ int cod2_sync_add_and_fetch_i32(volatile int *ptr, int val)
{
    return cod2_sync_fetch_and_add_i32(ptr, val) + val;
}

static __inline__ int cod2_sync_val_compare_and_swap_i32(volatile int *ptr, int oldval, int newval)
{
    int prev;
    __asm__ __volatile__(
        "lock; cmpxchgl %2, %1"
        : "=a"(prev), "+m"(*ptr)
        : "r"(newval), "0"(oldval)
        : "memory", "cc");
    return prev;
}

static __inline__ int cod2_sync_bool_compare_and_swap_i32(volatile int *ptr, int oldval, int newval)
{
    unsigned char swapped;
    __asm__ __volatile__(
        "lock; cmpxchgl %3, %1\n\t"
        "sete %0"
        : "=q"(swapped), "+m"(*ptr), "+a"(oldval)
        : "r"(newval)
        : "memory", "cc");
    return swapped;
}

static __inline__ int cod2_sync_lock_test_and_set_i32(volatile int *ptr, int val)
{
    __asm__ __volatile__(
        "xchgl %0, %1"
        : "+r"(val), "+m"(*ptr)
        :
        : "memory", "cc");
    return val;
}
#endif

static __inline__ unsigned int cod2_bswap32(unsigned int x)
{
    return ((x & 0x000000FFu) << 24)
         | ((x & 0x0000FF00u) << 8)
         | ((x & 0x00FF0000u) >> 8)
         | ((x & 0xFF000000u) >> 24);
}

#endif
