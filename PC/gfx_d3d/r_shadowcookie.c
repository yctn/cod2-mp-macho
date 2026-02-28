/* Converted to C from ASM: r_shadowcookie.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_shadowcookie.cpp */

#include "common_types.h"
#include "imports.h"

static ShadowCookieGlob shadowCookieGlob; /* shadowCookieGlob */

void R_ResetShadowCookies(void)
{
    shadowCookieGlob.weightCap = 10.0f;
    shadowCookieGlob.lastTime = -1;
}
