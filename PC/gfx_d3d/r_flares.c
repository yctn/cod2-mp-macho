/* ASM dump from: r_flares.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_flares.cpp */

#include "common_types.h"
#include "imports.h"

void R_ClearFlares(void);

/* line 12 */
__attribute__((naked))
void R_ClearFlares(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 12 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 14 */
        "retl\n"
    );
}

