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

/* Override R_Error to make vertex type errors non-fatal.
   The binary renderer triggers a fatal R_Error when a surface's vertex type
   doesn't match the shader requirements.  This happens because the vertex
   buffer was created with Dx7 format (type 1) which lacks tangent/binormal.
   Converting to a warning lets the game continue — those surfaces just
   won't render correctly. */
extern void Com_Printf(const char *fmt, ...);
extern void __real_R_Error(int level, const char *fmt, ...);

#include <stdarg.h>
#include <stdio.h>

void __wrap_R_Error(int level, const char *fmt, ...)
{
    /* Check if this is the "Vertex type" error we want to suppress */
    if (fmt) {
        /* Match the known vertex type error format string address or content */
        va_list args;
        char buf[512];
        va_start(args, fmt);
        vsnprintf(buf, sizeof(buf), fmt, args);
        va_end(args);

        if (strstr(buf, "Vertex type") && strstr(buf, "doesn't have")) {
            /* Downgrade to warning — print first few then suppress */
            static int vtypeWarnCount = 0;
            vtypeWarnCount++;
            if (vtypeWarnCount <= 5)
                Com_Printf("WARNING: %s", buf);
            else if (vtypeWarnCount == 6)
                Com_Printf("WARNING: Suppressing further vertex type warnings...\n");
            return;
        }
    }

    /* For all other errors, call the real R_Error */
    va_list args;
    va_start(args, fmt);
    char buf[512];
    vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    __real_R_Error(level, "%s", buf);
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
