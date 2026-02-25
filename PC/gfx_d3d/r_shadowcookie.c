/* ASM dump from: r_shadowcookie.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_shadowcookie.cpp */

#include "common_types.h"
#include "imports.h"

static struct ShadowCookieGlob shadowCookieGlob; /* 0xcb6f80 */

unsigned char R_ResetShadowCookies(void);

/* line 717 */
__attribute__((naked))
unsigned char R_ResetShadowCookies(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 717 */
        "movl %esp, %ebp\n"
        "movl $0x41200000, shadowCookieGlob\n" /* line 720 */
        "movl $0xffffffff, 0xcb6f84\n" /* line 721 */
        "popl %ebp\n" /* line 722 */
        "retl\n"
    );
}

