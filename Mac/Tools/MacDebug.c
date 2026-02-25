/* ASM dump from: MacDebug.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacDebug.cp */

#include "common_types.h"
#include "imports.h"

extern bool g_InhibitOpenGLErrors; /* 0x0 */

inflate_huft game_dprintf(const char *inFormat);

/* line 99 */
__attribute__((naked))
inflate_huft game_dprintf(const char *inFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 99 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "leave\n" /* line 112 */
        "retl\n"
    );
}

