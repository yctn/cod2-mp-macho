/* ASM dump from: cl_cin_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/client_mp/cl_cin_mp.cpp */

#include "common_types.h"
#include "imports.h"

e_status CIN_StopCinematic(int handle);
e_status CIN_RunCinematic(int handle);
int CIN_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits);
long int CIN_SetExtents(int handle, int x, int y, int w, int h);
long int CIN_DrawCinematic(int handle);
long int CL_PlayCinematic_f(void);
long int SCR_DrawCinematic(void);
long int SCR_RunCinematic(void);
long int SCR_StopCinematic(void);
long int CIN_UploadCinematic(int handle);
long int CIN_CloseAllVideos(void);

/* line 80 */
__attribute__((naked))
e_status CIN_StopCinematic(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 80 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 89 */
        "jmp ROQ_StopCinematicFromHandle\n" /* line 87 */
    );
}

/* line 92 */
__attribute__((naked))
e_status CIN_RunCinematic(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 92 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 101 */
        "jmp ROQ_RunCinematicFromHandle\n" /* line 99 */
    );
}

/* line 104 */
__attribute__((naked))
int CIN_PlayCinematic(const char *arg, int x, int y, int w, int h, int systemBits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 153 */
        "jmp ROQ_PlayCinematic\n" /* line 151 */
    );
}

/* line 156 */
__attribute__((naked))
long int CIN_SetExtents(int handle, int x, int y, int w, int h)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 156 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 165 */
        "jmp ROQ_SetExtentsFromHandle\n" /* line 163 */
    );
}

/* line 180 */
__attribute__((naked))
long int CIN_DrawCinematic(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 180 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 185 */
        "jmp ROQ_DrawCinematicFromHandle\n" /* line 183 */
    );
}

/* line 188 */
__attribute__((naked))
long int CL_PlayCinematic_f(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 188 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 218 */
        "jmp ROQ_PlayCinematic_f\n" /* line 216 */
    );
}

/* line 221 */
__attribute__((naked))
long int SCR_DrawCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 221 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 226 */
        "jmp ROQ_DrawCinematic\n" /* line 224 */
    );
}

/* line 229 */
__attribute__((naked))
long int SCR_RunCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 229 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 234 */
        "jmp ROQ_RunCinematic\n" /* line 232 */
    );
}

/* line 237 */
__attribute__((naked))
long int SCR_StopCinematic(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 237 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 246 */
        "jmp ROQ_StopCinematic\n" /* line 244 */
    );
}

/* line 249 */
__attribute__((naked))
long int CIN_UploadCinematic(int handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 258 */
        "jmp ROQ_UploadCinematicFromHandle\n" /* line 256 */
    );
}

/* line 260 */
__attribute__((naked))
long int CIN_CloseAllVideos(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 260 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 265 */
        "jmp ROQ_CloseAllVideos\n" /* line 263 */
    );
}

