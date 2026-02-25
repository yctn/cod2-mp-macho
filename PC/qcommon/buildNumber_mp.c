/* ASM dump from: buildNumber_mp.c */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/qcommon/buildNumber_mp.c */

#include "common_types.h"
#include "imports.h"

extern char buf[128]; /* 0x0 */

char * getBuildNumber(void);

/* line 5 */
__attribute__((naked))
char * getBuildNumber(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x2ae9d0, 0xc(%esp)\n" /* line 7 */
        "movl $0x2ae9ec, 8(%esp)\n" /* "crc6_v1" */
        "movl $0x2ae9f4, 4(%esp)\n" /* "%s %s" */
        "movl $buf, (%esp)\n"
        "calll sprintf\n"
        "movl $buf, %eax\n" /* line 9 */
        "leave\n"
        "retl\n"
    );
}

