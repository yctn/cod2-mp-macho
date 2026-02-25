/* ASM dump from: r_debug.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_debug.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 */

static const int iEdgePairs[12][2]; /* 0x2f2ac0 */
static DebugGlobals debugGlobals; /* 0xc96d80 */

void R_InitDebugEntry(DebugGlobals *debugGlobalsEntry);
void R_ShutdownDebugEntry(DebugGlobals *debugGlobalsEntry);
void R_TransferDebugGlobals(DebugGlobals *debugGlobalsEntry);
void R_ShutdownDebug(void);
void R_LocateDebugStrings(trDebugString_t *strings, int stringCount, int maxStringCount);
void R_LocateDebugLines(trDebugLine_t *lines, int lineCount, int maxLineCount);
void R_AddDebugString(DebugGlobals *debugGlobalsEntry, const vec_t *origin, const vec_t *color, float scale, const char *string);
void R_AddPlume(const vec_t *origin, int score, const vec_t *color, int duration);
void R_AddDebugPolygon(DebugGlobals *debugGlobalsEntry, const vec_t *color, const int pointCount, vec3_t *points);
void R_AddDebugLine(DebugGlobals *debugGlobalsEntry, const vec_t *start, const vec_t *end, const vec_t *color);
void R_InitDebug(void);
void R_AddDebugBox(DebugGlobals *debugGlobalsEntry, const vec_t *mins, const vec_t *maxs, const vec_t *color);
void R_AddScaledDebugString(DebugGlobals *debugGlobalsEntry, const GfxViewParms *viewParms, const vec_t *origin, const vec_t *color, const char *string);

/* line 184 */
__attribute__((naked))
void R_InitDebugEntry(DebugGlobals *debugGlobalsEntry)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 184 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* debugGlobalsEntry */
        "movl $0x54, 8(%esp)\n" /* line 186 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* debugGlobalsEntry */
        "calll memset\n"
        "movl $__mh_execute_header, 8(%ebx)\n" /* line 188 | debugGlobalsEntry */
        "movl $0x200, 0x14(%ebx)\n" /* line 189 | debugGlobalsEntry */
        "movl $__mh_execute_header, 0x20(%ebx)\n" /* line 190 | debugGlobalsEntry */
        "movl $0x4000, 0x38(%ebx)\n" /* line 191 | debugGlobalsEntry */
        "movl $__mh_execute_header, 0x50(%ebx)\n" /* line 192 | debugGlobalsEntry */
        "addl $0x14, %esp\n" /* line 193 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 202 */
__attribute__((naked))
void R_ShutdownDebugEntry(DebugGlobals *debugGlobalsEntry)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 202 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* debugGlobalsEntry */
        "movl 0xc(%ebx), %eax\n" /* line 204 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edbbb\n"
        "movl %eax, (%esp)\n" /* line 206 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, 0xc(%ebx)\n" /* line 207 | debugGlobalsEntry */
        ".Lfedb98_000edbbb:\n"
        "movl (%ebx), %eax\n" /* line 209 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edbd2\n"
        "movl %eax, (%esp)\n" /* line 211 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, (%ebx)\n" /* line 212 | debugGlobalsEntry */
        ".Lfedb98_000edbd2:\n"
        "movl 0x18(%ebx), %eax\n" /* line 214 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edbeb\n"
        "movl %eax, (%esp)\n" /* line 216 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, 0x18(%ebx)\n" /* line 217 | debugGlobalsEntry */
        ".Lfedb98_000edbeb:\n"
        "movl 0x24(%ebx), %eax\n" /* line 219 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edc04\n"
        "movl %eax, (%esp)\n" /* line 221 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, 0x24(%ebx)\n" /* line 222 | debugGlobalsEntry */
        ".Lfedb98_000edc04:\n"
        "movl 0x30(%ebx), %eax\n" /* line 224 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edc1d\n"
        "movl %eax, (%esp)\n" /* line 226 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, 0x30(%ebx)\n" /* line 227 | debugGlobalsEntry */
        ".Lfedb98_000edc1d:\n"
        "movl 0x3c(%ebx), %eax\n" /* line 229 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edc36\n"
        "movl %eax, (%esp)\n" /* line 231 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, 0x3c(%ebx)\n" /* line 232 | debugGlobalsEntry */
        ".Lfedb98_000edc36:\n"
        "movl 0x48(%ebx), %eax\n" /* line 234 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedb98_000edc4f\n"
        "movl %eax, (%esp)\n" /* line 236 */
        "movl 0x195eee0, %eax\n"
        "calll *0x18(%eax)\n"
        "movl $0, 0x48(%ebx)\n" /* line 237 | debugGlobalsEntry */
        ".Lfedb98_000edc4f:\n"
        "addl $0x14, %esp\n" /* line 239 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 242 */
__attribute__((naked))
void R_TransferDebugGlobals(DebugGlobals *debugGlobalsEntry)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 242 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl $0, -0x1c(%ebp)\n" /* plumeIndex */
        "movl 0xc96dcc, %edx\n"
        "xorl %esi, %esi\n"
        /* { scope 1 */
        ".Lfedc56_000edc6e:\n"
        "cmpl %edx, -0x1c(%ebp)\n" /* line 248 | plumeIndex */
        "jge .Lfedc56_000edd02\n"
        ".Lfedc56_000edc77:\n"
        "movl 0xc96dc8, %ecx\n" /* line 250 */
        "leal (%esi, %ecx), %ebx\n"
        "movl 0x195f0f4, %edi\n"
        "movl 4(%edi), %eax\n"
        "subl 0x20(%ebx), %eax\n" /* line 251 */
        "js .Lfedc56_000edc97\n"
        "cmpl 0x24(%ebx), %eax\n"
        "jle .Lfedc56_000edd4b\n"
        ".Lfedc56_000edc97:\n"
        "subl $1, %edx\n" /* line 253 */
        "movl %edx, 0xc96dcc\n"
        "leal (%edx, %edx, 4), %edx\n" /* line 254 */
        "shll $3, %edx\n"
        "movl (%edx, %ecx), %eax\n"
        "movl %eax, (%ebx)\n"
        "movl 4(%edx, %ecx), %eax\n"
        "movl %eax, 4(%esi, %ecx)\n"
        "movl 8(%edx, %ecx), %eax\n"
        "movl %eax, 8(%esi, %ecx)\n"
        "movl 0xc(%edx, %ecx), %eax\n"
        "movl %eax, 0xc(%esi, %ecx)\n"
        "movl 0x10(%edx, %ecx), %eax\n"
        "movl %eax, 0x10(%esi, %ecx)\n"
        "movl 0x14(%edx, %ecx), %eax\n"
        "movl %eax, 0x14(%esi, %ecx)\n"
        "movl 0x18(%edx, %ecx), %eax\n"
        "movl %eax, 0x18(%esi, %ecx)\n"
        "movl 0x1c(%edx, %ecx), %eax\n"
        "movl %eax, 0x1c(%esi, %ecx)\n"
        "movl 0x20(%edx, %ecx), %eax\n"
        "movl %eax, 0x20(%esi, %ecx)\n"
        "movl 0x24(%edx, %ecx), %eax\n"
        "movl %eax, 0x24(%esi, %ecx)\n"
        "movl 0xc96dcc, %edx\n"
        "cmpl %edx, -0x1c(%ebp)\n" /* line 248 | plumeIndex */
        "jl .Lfedc56_000edc77\n"
        ".Lfedc56_000edd02:\n"
        "movl 0xc96dc8, %ebx\n" /* line 260 */
        "testl %ebx, %ebx\n"
        "je .Lfedc56_000edd3d\n"
        "movl 8(%ebp), %eax\n" /* line 262 | debugGlobalsEntry */
        "movl 0x48(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lfedc56_000edd57\n"
        "movl %eax, %ecx\n"
        ".Lfedc56_000edd18:\n"
        "movl 0x48(%ecx), %eax\n" /* line 265 */
        "leal (%edx, %edx, 4), %edx\n"
        "shll $3, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl 0xc96dc8, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 0xc96dcc, %edx\n"
        ".Lfedc56_000edd3d:\n"
        "movl 8(%ebp), %edi\n" /* line 268 | debugGlobalsEntry */
        "movl %edx, 0x4c(%edi)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 269 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfedc56_000edd4b:\n"
        "addl $1, -0x1c(%ebp)\n" /* line 257 | plumeIndex */
        "addl $0x28, %esi\n"
        "jmp .Lfedc56_000edc6e\n"
        ".Lfedc56_000edd57:\n"
        "movl 0xc96dd0, %eax\n" /* line 263 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl 8(%ebp), %edx\n" /* debugGlobalsEntry */
        "movl %eax, 0x48(%edx)\n"
        "movl 0xc96dcc, %edx\n"
        "movl 8(%ebp), %ecx\n" /* debugGlobalsEntry */
        "jmp .Lfedc56_000edd18\n"
    );
}

/* line 272 */
__attribute__((naked))
void R_ShutdownDebug(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 272 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $debugGlobals, (%esp)\n" /* line 274 */
        "calll R_ShutdownDebugEntry\n"
        "leave\n" /* line 275 */
        "retl\n"
    );
}

/* line 278 */
__attribute__((naked))
void R_LocateDebugStrings(trDebugString_t *strings, int stringCount, int maxStringCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 278 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* strings */
        "movl 0xc(%ebp), %edi\n" /* stringCount */
        /* { scope 1 */
        "movl 0x195eef4, %eax\n" /* line 282 */
        "movl (%eax), %ebx\n" /* debugGlobalsEntry */
        "addl $0x249d18, %ebx\n" /* debugGlobalsEntry */
        "testl %esi, %esi\n" /* line 284 | strings */
        "je .Lfedd92_000eddd1\n"
        "movl 0x24(%ebx), %eax\n" /* line 286 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedd92_000edddc\n"
        "movl 0x24(%ebx), %edx\n" /* debugGlobalsEntry */
        ".Lfedd92_000eddbc:\n"
        "movl %edi, %eax\n" /* line 289 | stringCount */
        "shll $7, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* strings */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        ".Lfedd92_000eddd1:\n"
        "movl %edi, 0x28(%ebx)\n" /* line 292 | stringCount, debugGlobalsEntry */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 293 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfedd92_000edddc:\n"
        "shll $7, 0x10(%ebp)\n" /* line 287 | maxStringCount */
        "movl 0x10(%ebp), %eax\n" /* maxStringCount */
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, 0x24(%ebx)\n" /* debugGlobalsEntry */
        "movl %eax, %edx\n"
        "jmp .Lfedd92_000eddbc\n"
    );
}

/* line 296 */
__attribute__((naked))
void R_LocateDebugLines(trDebugLine_t *lines, int lineCount, int maxLineCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 296 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* lines */
        "movl 0xc(%ebp), %esi\n" /* lineCount */
        /* { scope 1 */
        "movl 0x195eef4, %eax\n" /* line 300 */
        "movl (%eax), %ebx\n" /* debugGlobalsEntry */
        "addl $0x249d18, %ebx\n" /* debugGlobalsEntry */
        "testl %edi, %edi\n" /* line 302 | lines */
        "je .Lfeddf6_000ede39\n"
        "movl 0x3c(%ebx), %eax\n" /* line 304 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfeddf6_000ede44\n"
        "movl 0x3c(%ebx), %edx\n" /* debugGlobalsEntry */
        ".Lfeddf6_000ede20:\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 307 | lineCount */
        "leal (%esi, %eax, 2), %eax\n" /* lineCount */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* lines */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        ".Lfeddf6_000ede39:\n"
        "movl %esi, 0x40(%ebx)\n" /* line 310 | lineCount, debugGlobalsEntry */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfeddf6_000ede44:\n"
        "movl 0x10(%ebp), %edx\n" /* line 305 | maxLineCount */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, 0x3c(%ebx)\n" /* debugGlobalsEntry */
        "movl %eax, %edx\n"
        "jmp .Lfeddf6_000ede20\n"
    );
}

/* line 135 */
__attribute__((naked))
void R_AddDebugString(DebugGlobals *debugGlobalsEntry, const vec_t *origin, const vec_t *color, float scale, const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 135 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* debugGlobalsEntry */
        "movl 0xc(%ebp), %edi\n" /* origin */
        /* { scope 1 */
        "movl 0x20(%esi), %ecx\n" /* line 143 | debugGlobalsEntry */
        "movl 0x1c(%esi), %edx\n" /* debugGlobalsEntry */
        "leal 1(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jg .Lfede62_000edee6\n"
        "movl 0x18(%esi), %eax\n" /* line 151 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfede62_000edeee\n"
        ".Lfede62_000ede85:\n"
        "movl %edx, %ebx\n" /* line 154 | pDebugString */
        "shll $7, %ebx\n" /* pDebugString */
        "addl 0x18(%esi), %ebx\n" /* debugGlobalsEntry, pDebugString */
        "movl (%edi), %eax\n" /* line 199 | origin */
        "movl %eax, (%ebx)\n" /* pDebugString */
        "movl 4(%edi), %eax\n" /* line 200 | origin */
        "movl %eax, 4(%ebx)\n" /* pDebugString */
        "movl 8(%edi), %eax\n" /* line 201 | origin */
        "movl %eax, 8(%ebx)\n" /* pDebugString */
        "leal 0xc(%ebx), %edx\n" /* line 156 | pDebugString, to */
        /* { scope 2 */
        "movl 0x10(%ebp), %ecx\n" /* line 456 | color */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* pDebugString */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movss 0x14(%ebp), %xmm0\n" /* line 157 | scale */
        "movss %xmm0, 0x1c(%ebx)\n" /* pDebugString */
        "movl $0x5f, 8(%esp)\n" /* line 158 */
        "movl 0x18(%ebp), %eax\n" /* string */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%ebx), %eax\n" /* pDebugString */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0x7f(%ebx)\n" /* line 159 | pDebugString */
        "addl $1, 0x1c(%esi)\n" /* line 160 | debugGlobalsEntry */
        /* } scope */
        ".Lfede62_000edee6:\n"
        "addl $0x1c, %esp\n" /* line 165 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfede62_000edeee:\n"
        "shll $7, %ecx\n" /* line 152 */
        "movl %ecx, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, 0x18(%esi)\n" /* debugGlobalsEntry */
        "movl 0x1c(%esi), %edx\n" /* debugGlobalsEntry */
        "jmp .Lfede62_000ede85\n"
    );
}

/* line 314 */
__attribute__((naked))
void R_AddPlume(const vec_t *origin, int score, const vec_t *color, int duration)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 314 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* origin */
        "movl 0x10(%ebp), %esi\n" /* color */
        "movl 0xc96dc8, %eax\n" /* line 320 */
        "testl %eax, %eax\n"
        "je .Lfedf04_000edfc3\n"
        ".Lfedf04_000edf1f:\n"
        "movl 0xc96dcc, %eax\n" /* line 326 */
        "cmpl 0xc96dd0, %eax\n"
        "je .Lfedf04_000edfbc\n"
        "leal (%eax, %eax, 4), %edx\n" /* line 334 | to */
        "movl 0xc96dc8, %eax\n"
        "leal (%eax, %edx, 8), %edx\n" /* to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "movl 0xc96dcc, %eax\n" /* line 335 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0xc96dc8, %edx\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 0xc(%eax), %ecx\n" /* to */
        /* { scope 1 */
        "movl (%esi), %edx\n" /* line 199 */
        "movl %edx, 0xc(%eax)\n"
        "movl 4(%esi), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%esi), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "movl 0xc96dcc, %eax\n" /* line 336 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0xc96dc8, %edx\n"
        "movl 0xc(%ebp), %ecx\n" /* score */
        "movl %ecx, 0x1c(%edx, %eax, 8)\n"
        "movl 0xc96dcc, %eax\n" /* line 337 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0x195f0f4, %edx\n"
        "movl 4(%edx), %ecx\n"
        "movl 0xc96dc8, %edx\n"
        "movl %ecx, 0x20(%edx, %eax, 8)\n"
        "movl 0xc96dcc, %eax\n" /* line 338 */
        "leal (%eax, %eax, 4), %eax\n"
        "movl 0xc96dc8, %edx\n"
        "movl 0x14(%ebp), %ecx\n" /* duration */
        "movl %ecx, 0x24(%edx, %eax, 8)\n"
        "addl $1, 0xc96dcc\n" /* line 339 */
        ".Lfedf04_000edfbc:\n"
        "addl $0x10, %esp\n" /* line 344 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfedf04_000edfc3:\n"
        "movl 0xc96dd0, %eax\n" /* line 322 */
        "leal (%eax, %eax, 4), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, 0xc96dc8\n"
        "movl $0, 0xc96dcc\n" /* line 323 */
        "jmp .Lfedf04_000edf1f\n"
    );
}

/* line 20 */
__attribute__((naked))
void R_AddDebugPolygon(DebugGlobals *debugGlobalsEntry, const vec_t *color, const int pointCount, vec3_t *points)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 20 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* debugGlobalsEntry */
        "movl 0x10(%ebp), %edi\n" /* pointCount */
        "movl 4(%esi), %ebx\n" /* line 26 | debugGlobalsEntry */
        "leal (%edi, %ebx), %eax\n" /* pointCount */
        "cmpl 8(%esi), %eax\n" /* debugGlobalsEntry */
        "jg .Lfedfee_000ee083\n"
        "movl 0x14(%esi), %edx\n" /* line 34 | debugGlobalsEntry */
        "movl 0x10(%esi), %ecx\n" /* debugGlobalsEntry */
        "leal 1(%ecx), %eax\n"
        "cmpl %edx, %eax\n"
        "jg .Lfedfee_000ee083\n"
        "movl 0xc(%esi), %eax\n" /* line 42 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfedfee_000ee08b\n"
        ".Lfedfee_000ee01c:\n"
        "movl 0xc(%esi), %edx\n" /* line 51 | debugGlobalsEntry */
        "leal (%ecx, %ecx, 2), %eax\n"
        "movl %ebx, 0x10(%edx, %eax, 8)\n"
        "movl 0x10(%esi), %eax\n" /* line 52 | debugGlobalsEntry */
        "movl 0xc(%esi), %edx\n" /* debugGlobalsEntry */
        "leal (%eax, %eax, 2), %eax\n"
        "movl %edi, 0x14(%edx, %eax, 8)\n" /* pointCount */
        "movl 0x10(%esi), %eax\n" /* line 53 | debugGlobalsEntry, to */
        "leal (%eax, %eax, 2), %eax\n" /* to */
        "movl 0xc(%esi), %edx\n" /* debugGlobalsEntry */
        "leal (%edx, %eax, 8), %eax\n" /* to */
        /* { scope 1 */
        "movl 0xc(%ebp), %ecx\n" /* line 456 | color */
        "movl (%ecx), %edx\n"
        "movl %edx, (%eax)\n"
        "movl 4(%ecx), %edx\n" /* line 457 */
        "movl %edx, 4(%eax)\n"
        "movl 8(%ecx), %edx\n" /* line 458 */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%ecx), %edx\n" /* line 459 */
        "movl %edx, 0xc(%eax)\n"
        /* } scope */
        "addl $1, 0x10(%esi)\n" /* line 54 | debugGlobalsEntry */
        "movl 4(%esi), %edx\n" /* line 57 | debugGlobalsEntry */
        "leal (%edx, %edx, 2), %edx\n"
        "movl (%esi), %eax\n" /* debugGlobalsEntry */
        "leal (%eax, %edx, 4), %edx\n"
        "leal (%edi, %edi, 2), %eax\n" /* pointCount */
        "shll $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* points */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "addl %edi, 4(%esi)\n" /* line 60 | pointCount, debugGlobalsEntry */
        ".Lfedfee_000ee083:\n"
        "addl $0x1c, %esp\n" /* line 65 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfedfee_000ee08b:\n"
        "movl 0x195eee0, %ebx\n" /* line 45 */
        "leal (%edx, %edx, 2), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebx)\n"
        "movl %eax, 0xc(%esi)\n" /* debugGlobalsEntry */
        "movl 8(%esi), %eax\n" /* line 46 | debugGlobalsEntry */
        "leal (%eax, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebx)\n"
        "movl %eax, (%esi)\n" /* debugGlobalsEntry */
        "movl 4(%esi), %ebx\n" /* debugGlobalsEntry */
        "movl 0x10(%esi), %ecx\n" /* debugGlobalsEntry */
        "jmp .Lfedfee_000ee01c\n"
    );
}

/* line 68 */
__attribute__((naked))
void R_AddDebugLine(DebugGlobals *debugGlobalsEntry, const vec_t *start, const vec_t *end, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* debugGlobalsEntry */
        "movl 0xc(%ebp), %esi\n" /* start */
        "movl 0x10(%ebp), %edi\n" /* end */
        /* { scope 1 */
        "movl 0x38(%ebx), %edx\n" /* line 76 | debugGlobalsEntry */
        "movl 0x34(%ebx), %ecx\n" /* debugGlobalsEntry */
        "leal 1(%ecx), %eax\n"
        "cmpl %edx, %eax\n"
        "jg .Lfee0bc_000ee13a\n"
        "movl 0x30(%ebx), %eax\n" /* line 84 | debugGlobalsEntry */
        "testl %eax, %eax\n"
        "je .Lfee0bc_000ee142\n"
        "movl 0x30(%ebx), %eax\n" /* debugGlobalsEntry */
        ".Lfee0bc_000ee0e5:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 87 */
        "leal (%ecx, %edx, 2), %edx\n"
        "leal (%eax, %edx, 4), %edx\n"
        "movl (%esi), %eax\n" /* line 199 | start */
        "movl %eax, (%edx)\n"
        "movl 4(%esi), %eax\n" /* line 200 | start */
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n" /* line 201 | start */
        "movl %eax, 8(%edx)\n"
        "leal 0xc(%edx), %ecx\n" /* line 89 | to */
        /* { scope 2 */
        "movl (%edi), %eax\n" /* line 199 | end */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%edi), %eax\n" /* line 200 | end */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%edi), %eax\n" /* line 201 | end */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x18(%edx), %ecx\n" /* line 90 | to */
        /* { scope 2 */
        "movl 0x14(%ebp), %esi\n" /* line 456 | color, start */
        "movl (%esi), %eax\n" /* start */
        "movl %eax, 0x18(%edx)\n"
        "movl 4(%esi), %eax\n" /* line 457 | start */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%esi), %eax\n" /* line 458 | start */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%esi), %eax\n" /* line 459 | start */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "movl $0, 0x28(%edx)\n" /* line 91 */
        "addl $1, 0x34(%ebx)\n" /* line 92 | debugGlobalsEntry */
        /* } scope */
        ".Lfee0bc_000ee13a:\n"
        "addl $0x1c, %esp\n" /* line 97 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfee0bc_000ee142:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 85 */
        "leal (%edx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "calll *0x14(%eax)\n"
        "movl %eax, 0x30(%ebx)\n" /* debugGlobalsEntry */
        "movl 0x34(%ebx), %ecx\n" /* debugGlobalsEntry */
        "jmp .Lfee0bc_000ee0e5\n"
    );
}

/* line 196 */
__attribute__((naked))
void R_InitDebug(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 196 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x54, 8(%esp)\n" /* line 186 */
        "movl $0, 4(%esp)\n"
        "movl $debugGlobals, (%esp)\n"
        "calll memset\n"
        "movl $__mh_execute_header, 0xc96d88\n" /* line 188 */
        "movl $0x200, 0xc96d94\n" /* line 189 */
        "movl $__mh_execute_header, 0xc96da0\n" /* line 190 */
        "movl $0x4000, 0xc96db8\n" /* line 191 */
        "movl $__mh_execute_header, 0xc96dd0\n" /* line 192 */
        "leave\n" /* line 199 */
        "retl\n"
    );
}

/* line 100 */
__attribute__((naked))
void R_AddDebugBox(DebugGlobals *debugGlobalsEntry, const vec_t *mins, const vec_t *maxs, const vec_t *color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 100 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "xorl %ebx, %ebx\n" /* from */
        "xorl %esi, %esi\n" /* from */
        ".Lfee1b4_000ee1c1:\n"
        "leal -0x78(%ebp), %edx\n" /* v */
        "addl %esi, %edx\n" /* from */
        "xorl %ecx, %ecx\n"
        /* { scope 1 */
        ".Lfee1b4_000ee1c8:\n"
        "movl %ebx, %eax\n" /* line 126 | i */
        "sarl %cl, %eax\n"
        "testb $1, %al\n"
        "je .Lfee1b4_000ee2a7\n"
        "movl 0x10(%ebp), %edi\n" /* maxs */
        "movl (%edi, %ecx, 4), %eax\n"
        ".Lfee1b4_000ee1da:\n"
        "movl %eax, (%edx)\n"
        "addl $1, %ecx\n" /* line 124 */
        "addl $4, %edx\n"
        "cmpl $3, %ecx\n"
        "jne .Lfee1b4_000ee1c8\n"
        "addl $1, %ebx\n" /* line 122 | i */
        "addl $0xc, %esi\n" /* from */
        "cmpl $8, %ebx\n" /* i */
        "jne .Lfee1b4_000ee1c1\n"
        "movl $0x2f2ac4, %edi\n"
        "movl 8(%ebp), %eax\n" /* debugGlobalsEntry */
        "movl 0x34(%eax), %ecx\n"
        ".Lfee1b4_000ee1fd:\n"
        "movl -4(%edi), %eax\n" /* line 100 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x78(%ebp, %eax, 4), %ebx\n" /* from */
        "movl (%edi), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal -0x78(%ebp, %eax, 4), %esi\n" /* from */
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 76 | debugGlobalsEntry */
        "movl 0x38(%eax), %edx\n"
        "leal 1(%ecx), %eax\n"
        "cmpl %edx, %eax\n"
        "jg .Lfee1b4_000ee290\n"
        "movl 8(%ebp), %eax\n" /* line 84 | debugGlobalsEntry */
        "movl 0x30(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfee1b4_000ee2b2\n"
        ".Lfee1b4_000ee22b:\n"
        "leal (%ecx, %ecx, 4), %edx\n" /* line 87 */
        "leal (%ecx, %edx, 2), %edx\n"
        "movl 8(%ebp), %ecx\n" /* debugGlobalsEntry */
        "movl 0x30(%ecx), %eax\n"
        "leal (%eax, %edx, 4), %edx\n"
        /* { scope 3 */
        "movl (%ebx), %eax\n" /* line 199 | i */
        "movl %eax, (%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 | i */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 | i */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "leal 0xc(%edx), %ecx\n" /* line 89 | to */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 199 | from */
        "movl %eax, 0xc(%edx)\n"
        "movl 4(%esi), %eax\n" /* line 200 | from */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%esi), %eax\n" /* line 201 | from */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        "leal 0x18(%edx), %ecx\n" /* line 90 | to */
        /* { scope 3 */
        "movl 0x14(%ebp), %ebx\n" /* line 456 | color, i */
        "movl (%ebx), %eax\n" /* i */
        "movl %eax, 0x18(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 457 | i */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 458 | i */
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%ebx), %eax\n" /* line 459 | i */
        "movl %eax, 0xc(%ecx)\n"
        /* } scope */
        "movl $0, 0x28(%edx)\n" /* line 91 */
        "movl 8(%ebp), %edx\n" /* line 92 | debugGlobalsEntry */
        "movl 0x34(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, %ecx\n"
        "movl %eax, 0x34(%edx)\n"
        ".Lfee1b4_000ee290:\n"
        "addl $8, %edi\n"
        /* } scope */
        "cmpl $0x2f2b24, %edi\n" /* line 130 */
        "jne .Lfee1b4_000ee1fd\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 132 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfee1b4_000ee2a7:\n"
        "movl 0xc(%ebp), %edi\n" /* line 126 | mins */
        "movl (%edi, %ecx, 4), %eax\n"
        "jmp .Lfee1b4_000ee1da\n"
        /* { scope 2 */
        ".Lfee1b4_000ee2b2:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 85 */
        "leal (%edx, %eax, 2), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "movl 0x195eee0, %edx\n"
        "calll *0x14(%edx)\n"
        "movl 8(%ebp), %ecx\n" /* debugGlobalsEntry */
        "movl %eax, 0x30(%ecx)\n"
        "movl 8(%ebp), %eax\n" /* debugGlobalsEntry */
        "movl 0x34(%eax), %ecx\n"
        "jmp .Lfee1b4_000ee22b\n"
    );
}

/* line 168 */
__attribute__((naked))
void R_AddScaledDebugString(DebugGlobals *debugGlobalsEntry, const GfxViewParms *viewParms, const vec_t *origin, const vec_t *color, const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 168 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %esi\n" /* debugGlobalsEntry */
        "movl 0xc(%ebp), %ebx\n" /* viewParms */
        "movl 0x10(%ebp), %edi\n" /* origin */
        /* { scope 1 */
        "movss (%edi), %xmm0\n" /* line 248 | origin */
        "subss (%ebx), %xmm0\n" /* viewParms */
        "movss %xmm0, -0x24(%ebp)\n" /* delta */
        "movss 4(%edi), %xmm0\n" /* line 249 | origin */
        "subss 4(%ebx), %xmm0\n" /* viewParms */
        "movss %xmm0, -0x20(%ebp)\n"
        "movss 8(%edi), %xmm0\n" /* line 250 | origin */
        "subss 8(%ebx), %xmm0\n" /* viewParms */
        "movss %xmm0, -0x1c(%ebp)\n"
        "leal -0x24(%ebp), %eax\n" /* line 175 | delta */
        "movl %eax, (%esp)\n"
        "calll Vec3Normalize\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "leal 0xc(%ebx), %eax\n" /* line 176 | viewParms */
        "movss -0x24(%ebp), %xmm1\n" /* line 177 | delta */
        "mulss 0xc(%ebx), %xmm1\n" /* viewParms */
        "movss -0x20(%ebp), %xmm0\n"
        "mulss 4(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss -0x1c(%ebp), %xmm0\n"
        "mulss 8(%eax), %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "subss 0x2ed87c, %xmm1\n" /* 0.9950000047683716f */
        "mulss %xmm1, %xmm2\n"
        "movss 0x2ed5d0, %xmm0\n" /* line 178 | 1.0f */
        "maxss %xmm2, %xmm0\n"
        "movaps %xmm0, %xmm2\n"
        /* { scope 2 */
        "movl 0x20(%esi), %ecx\n" /* line 143 */
        "movl 0x1c(%esi), %edx\n"
        "leal 1(%edx), %eax\n"
        "cmpl %ecx, %eax\n"
        "jg .Lfee2d8_000ee3dc\n"
        "movl 0x18(%esi), %eax\n" /* line 151 */
        "testl %eax, %eax\n"
        "je .Lfee2d8_000ee3e4\n"
        ".Lfee2d8_000ee380:\n"
        "movl %edx, %ebx\n" /* line 154 | pDebugString */
        "shll $7, %ebx\n" /* pDebugString */
        "addl 0x18(%esi), %ebx\n" /* pDebugString */
        "movl (%edi), %eax\n" /* line 199 | origin */
        "movl %eax, (%ebx)\n" /* viewParms */
        "movl 4(%edi), %eax\n" /* line 200 | origin */
        "movl %eax, 4(%ebx)\n" /* viewParms */
        "movl 8(%edi), %eax\n" /* line 201 | origin */
        "movl %eax, 8(%ebx)\n" /* viewParms */
        "leal 0xc(%ebx), %edx\n" /* line 156 | pDebugString, to */
        /* { scope 3 */
        "movl 0x14(%ebp), %ecx\n" /* line 456 | color */
        "movl (%ecx), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* viewParms */
        "movl 4(%ecx), %eax\n" /* line 457 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 458 */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ecx), %eax\n" /* line 459 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movss %xmm2, 0x1c(%ebx)\n" /* line 157 | pDebugString */
        "movl $0x5f, 8(%esp)\n" /* line 158 */
        "movl 0x18(%ebp), %eax\n" /* string */
        "movl %eax, 4(%esp)\n"
        "leal 0x20(%ebx), %eax\n" /* pDebugString */
        "movl %eax, (%esp)\n"
        "calll strncpy\n"
        "movb $0, 0x7f(%ebx)\n" /* line 159 | pDebugString */
        "addl $1, 0x1c(%esi)\n" /* line 160 */
        /* } scope */
        /* } scope */
        ".Lfee2d8_000ee3dc:\n"
        "addl $0x4c, %esp\n" /* line 181 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfee2d8_000ee3e4:\n"
        "shll $7, %ecx\n" /* line 152 */
        "movl %ecx, (%esp)\n"
        "movl 0x195eee0, %eax\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "calll *0x14(%eax)\n"
        "movl %eax, 0x18(%esi)\n"
        "movl 0x1c(%esi), %edx\n"
        "movss -0x38(%ebp), %xmm2\n"
        "jmp .Lfee2d8_000ee380\n"
    );
}

