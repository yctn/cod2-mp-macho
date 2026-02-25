/* Converted to C from ASM: zutil.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/zlib/zutil.c */

#include "common_types.h"
#include "imports.h"

extern void *Z_MallocInternal(unsigned int size);
extern void Z_FreeInternal(void *ptr);

voidpf zcalloc(voidpf opaque, unsigned int items, unsigned int size)
{
    return Z_MallocInternal(items * size);
}

void zcfree(voidpf opaque, voidpf ptr)
{
    Z_FreeInternal(ptr);
}

