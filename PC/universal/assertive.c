/* Converted to C from ASM: assertive.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/universal/assertive.cpp */

#include "common_types.h"
#include "imports.h"

extern Bool Dvar_IsSystemActive(void);
extern Bool Dvar_GetBool(const char *name);
extern int Dvar_GetInt(const char *name);

static Bool shouldQuitOnError; /* shouldQuitOnError */

static void RefreshQuitOnErrorCondition_inline(void)
{
    if (!Dvar_IsSystemActive())
        return;

    if (Dvar_GetBool("QuitOnError") || Dvar_GetInt("r_vc_compile") == 2)
        shouldQuitOnError = 1;
    else
        shouldQuitOnError = 0;
}

void RefreshQuitOnErrorCondition(void)
{
    RefreshQuitOnErrorCondition_inline();
}

Bool QuitOnError(void)
{
    RefreshQuitOnErrorCondition_inline();
    return shouldQuitOnError;
}
