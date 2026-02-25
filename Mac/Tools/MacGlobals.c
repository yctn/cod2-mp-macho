/* ASM dump from: MacGlobals.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacGlobals.cp */

#include "common_types.h"
#include "imports.h"

static int sSystemLock; /* 0x334a80 */

void MacGlobals_LockSystem(void);
void MacGlobals_UnlockSystem(void);
bool MacGlobals_IsSystemLocked(void);

/* line 19 */
__attribute__((naked))
void MacGlobals_LockSystem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 19 */
        "movl %esp, %ebp\n"
        "addl $1, sSystemLock\n" /* line 21 */
        "popl %ebp\n" /* line 22 */
        "retl\n"
    );
}

/* line 27 */
__attribute__((naked))
void MacGlobals_UnlockSystem(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "movl sSystemLock, %eax\n" /* line 29 */
        "testl %eax, %eax\n"
        "jle .Lf993c_00009950\n"
        "subl $1, %eax\n" /* line 31 */
        "movl %eax, sSystemLock\n"
        ".Lf993c_00009950:\n"
        "popl %ebp\n" /* line 33 */
        "retl\n"
    );
}

/* line 38 */
__attribute__((naked))
bool MacGlobals_IsSystemLocked(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "cmpl $0, sSystemLock\n"
        "setg %al\n"
        "popl %ebp\n" /* line 41 */
        "retl\n"
    );
}

