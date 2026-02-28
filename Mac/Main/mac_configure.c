/* ASM dump from: mac_configure.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/Main/mac_configure.cpp */

#include "common_types.h"
#include "imports.h"

double Sys_CpuGHz(void);
int Sys_SystemMemoryMB(void);
float Sys_DetectVideoCard(int descLimit, char *description);
bool Sys_SupportsSSE(void);

/* line 18 */
__attribute__((naked))
double Sys_CpuGHz(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll MacFeatures_GetCPUSpeedInGHz\n" /* line 20 */
        "fstps -0xc(%ebp)\n"
        "cvtss2sd -0xc(%ebp), %xmm0\n"
        "movsd %xmm0, -0x18(%ebp)\n"
        "fldl -0x18(%ebp)\n" /* line 21 */
        "leave\n"
        "retl\n"
    );
}

/* line 25 */
__attribute__((naked))
int Sys_SystemMemoryMB(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "calll MacFeatures_GetMemorySizeInMB\n" /* line 27 */
        "cmpl $0x8000001, %eax\n" /* line 33 */
        "movl $0x8000000, %edx\n"
        "cmovgel %edx, %eax\n"
        /* } scope */
        "leave\n" /* line 39 */
        "retl\n"
    );
}

/* line 43 */
__attribute__((naked))
float Sys_DetectVideoCard(int descLimit, char *description)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "calll MacDisplay_GetGLRenderer\n" /* line 45 */
        "movl 8(%ebp), %edx\n" /* descLimit */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* description */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "leave\n" /* line 46 */
        "retl\n"
    );
}

/* line 50 */
__attribute__((naked))
bool Sys_SupportsSSE(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 50 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x19, 4(%esp)\n" /* line 53 */
        "movl $0x78383666, (%esp)\n"
        "calll MacFeatures_HasGestaltAttribute\n"
        "testb %al, %al\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 57 */
        "retl\n"
    );
}

