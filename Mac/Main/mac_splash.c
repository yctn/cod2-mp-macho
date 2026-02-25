/* ASM dump from: mac_splash.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_splash.cpp */

#include "common_types.h"
#include "imports.h"

void Sys_CreateSplashWindow(void);
void Sys_DestroySplashWindow(void);
void Sys_ShowSplashWindow(void);
void Sys_HideSplashWindow(void);

/* line 11 */
__attribute__((naked))
void Sys_CreateSplashWindow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 11 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 14 */
        "retl\n"
    );
}

/* line 18 */
__attribute__((naked))
void Sys_DestroySplashWindow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 21 */
        "retl\n"
    );
}

/* line 25 */
__attribute__((naked))
void Sys_ShowSplashWindow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x222d8c, (%esp)\n" /* line 27 */
        "calll CMacGameEngine_DrawSplashScreen\n"
        "leave\n" /* line 28 */
        "retl\n"
    );
}

/* line 32 */
__attribute__((naked))
void Sys_HideSplashWindow(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 35 */
        "retl\n"
    );
}

