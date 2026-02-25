/* ASM dump from: com_profilemapload.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/com_profilemapload.cpp */

#include "common_types.h"
#include "imports.h"

Bool Com_IsMapProfilerActive(void);

/* line 578 */
__attribute__((naked))
Bool Com_IsMapProfilerActive(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 581 */
        "popl %ebp\n"
        "retl\n"
    );
}

