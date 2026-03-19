/* Override stubs for ASM functions with stale Mac address relocations.
 * Uses --wrap linker flag: calls to FX_TryRegisterEffect are redirected
 * to __wrap_FX_TryRegisterEffect. */
#include "common_types.h"
#include <string.h>

extern void *Hunk_AllocAlignInternal(int size, int align);
extern void *defaultEffect;

void *__wrap_FX_TryRegisterEffect(const char *name)
{
    /* The binary ASM version crashes iterating FX templates with stale
       Mac pointers.  Return NULL to force fallback to default effect. */
    (void)name;
    return NULL;
}

/* Override FX_RegisterEffect via --wrap because --wrap can't intercept the
   internal call from FX_RegisterEffect to FX_TryRegisterEffect (same .o file).
   This replacement just returns defaultEffect for all effects. */
void *__wrap_FX_RegisterEffect(const char *fileName)
{
    (void)fileName;
    return defaultEffect;
}

float __wrap_FX_CreateDefaultEffect(void)
{
    /* Create a minimal empty effect template. */
    void *effect = Hunk_AllocAlignInternal(0x68, 4);
    memset(effect, 0, 0x68);
    char *nameBuf = (char *)Hunk_AllocAlignInternal(11, 4);
    strcpy(nameBuf, "default_fx");
    *(char **)effect = nameBuf;
    defaultEffect = effect;
    return 0.0f;
}
