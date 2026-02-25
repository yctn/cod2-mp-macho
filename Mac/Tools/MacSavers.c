/* ASM dump from: MacSavers.cp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Tools/MacSavers.cp */

#include "common_types.h"
#include "imports.h"

void StPortState_StPortState(const StPortState * _this, WindowRef inWindow);
void ZN11StPortStateD1Ev(void); /* StPortState_~StPortState */

/* line 31 */
__attribute__((naked))
void StPortState_StPortState(const StPortState * _this, WindowRef inWindow)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 31 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* inWindow */
        "movl 8(%ebp), %eax\n" /* line 33 | this */
        "movl %eax, (%esp)\n"
        "calll GetPort\n"
        "movl %ebx, 8(%ebp)\n" /* line 34 | inWindow, this */
        "addl $0x14, %esp\n" /* line 35 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp SetPortWindowPort\n" /* line 34 */
    );
}

/* line 39 */
__attribute__((naked))
void ZN11StPortStateD1Ev(void) /* StPortState_~StPortState */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 41 | this */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 42 */
        "jmp SetPort\n" /* line 41 */
    );
}

