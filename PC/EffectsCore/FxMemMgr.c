/* ASM dump from: FxMemMgr.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/EffectsCore/FxMemMgr.cpp */

#include "common_types.h"
#include "imports.h"

void FxMem_Init(void);

/* line 40 */
__attribute__((naked))
void FxMem_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 40 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 53 */
        "retl\n"
    );
}

