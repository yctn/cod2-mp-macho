/* ASM dump from: cg_drawtools_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_drawtools_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/universal/com_math.h"
 */

static vec4_t color; /* 0xf31700 */
static vec2_t sign[4]; /* 0x303100 */

void CG_DrawStringExt(float x, float y, const char *string, const vec_t *setColor, qboolean forceColor, qboolean shadow, float charHeight, qboolean adjust);
int CG_DrawDevString(float x, float y, const char *s, const vec_t *color, int align, FontHandle font, int style);
int CG_DrawBigDevStringColor(float x, float y, const char *s, const vec_t *color, int align);
int CG_DrawSmallDevStringColor(float x, float y, const char *s, const vec_t *color, int align);
float * CG_FadeColor(int startMsec, int totalMsec, int fadeMsec);
void CG_NorthDirectionChanged(void);
void CG_UpdateCompassOrientation(void);
void CG_UpdateCompPointerOrientation(void);
void CG_TileClear(void);
int CG_DrawBigDevString(float x, float y, const char *s, float alpha, int align);
void CG_DrawRotatedPicPhysical(float x, float y, float width, float height, float angle, const vec_t *color, MaterialHandle material);
void CG_DrawRotatedPic(float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const vec_t *color, MaterialHandle material);
void CG_DrawRotatedQuadPic(float x, float y, vec2_t *verts, float angle, const vec_t *color, MaterialHandle material);

/* line 228 */
__attribute__((naked))
void CG_DrawStringExt(float x, float y, const char *string, const vec_t *setColor, qboolean forceColor, qboolean shadow, float charHeight, qboolean adjust)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        "movl 0x14(%ebp), %ebx\n" /* setColor */
        "movss 0x20(%ebp), %xmm0\n" /* charHeight */
        /* { scope 1 */
        "movaps %xmm0, %xmm1\n" /* line 233 */
        "mulss 0x2ed7f0, %xmm1\n" /* 0.800000011920929f */
        "addss 0xc(%ebp), %xmm1\n" /* y */
        "movss %xmm1, -0xc(%ebp)\n"
        "divss 0x2ed6b8, %xmm0\n" /* line 235 | 48.0f */
        "testl %ebx, %ebx\n" /* line 237 | setColor */
        "cmovel 0x195ed2c, %ebx\n" /* setColor */
        "movss %xmm0, 4(%esp)\n" /* line 240 */
        "movl $5, (%esp)\n"
        "movss %xmm0, -0x28(%ebp)\n"
        "calll UI_GetFontHandle\n"
        "cmpl $1, 0x1c(%ebp)\n" /* line 241 | shadow */
        "sbbl %edx, %edx\n"
        "notl %edx\n"
        "andl $3, %edx\n"
        "movl %edx, 0x24(%esp)\n"
        "movl %ebx, 0x20(%esp)\n" /* setColor */
        "movss -0x28(%ebp), %xmm0\n"
        "movss %xmm0, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movss -0xc(%ebp), %xmm0\n"
        "movss %xmm0, 0x10(%esp)\n"
        "movl 8(%ebp), %edx\n" /* x */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x7fffffff, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* string */
        "movl %eax, (%esp)\n"
        "calll UI_DrawText\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 242 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 245 */
__attribute__((naked))
int CG_DrawDevString(float x, float y, const char *s, const vec_t *color, int align, FontHandle font, int style)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 245 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x18(%ebp), %edi\n" /* align */
        "movl 0x1c(%ebp), %ebx\n" /* font */
        /* { scope 1 */
        "movl %edi, %eax\n" /* line 257 | align */
        "andl $3, %eax\n"
        "subl $1, %eax\n"
        "je .Lf19f632_0019f662\n"
        "movl %ebx, 8(%esp)\n" /* line 259 | font */
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll CL_TextWidth\n"
        ".Lf19f632_0019f662:\n"
        "movl %ebx, (%esp)\n" /* line 265 | font */
        "calll CL_TextHeight\n"
        "movl %eax, %esi\n" /* step */
        "cvtsi2ssl %eax, %xmm0\n" /* line 266 */
        "movl %edi, %eax\n" /* line 268 | align */
        "andl $0xc, %eax\n"
        "cmpl $8, %eax\n"
        "je .Lf19f632_0019f68d\n"
        "cmpl $0xc, %eax\n" /* line 270 */
        "je .Lf19f632_0019f70c\n"
        ".Lf19f632_0019f683:\n"
        "addss 0xc(%ebp), %xmm0\n" /* line 272 | y */
        "movss %xmm0, 0xc(%ebp)\n" /* y */
        ".Lf19f632_0019f68d:\n"
        "movl %ebx, 8(%esp)\n" /* line 275 | font */
        "movl $0, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll CL_TextWidth\n"
        "movl 0x20(%ebp), %edx\n" /* line 276 | style */
        "movl %edx, 0x28(%esp)\n"
        "movl 0x14(%ebp), %edx\n" /* color */
        "movl %edx, 0x24(%esp)\n"
        "movl $0x3f800000, %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %edx, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movl $3, 0x14(%esp)\n"
        "movss 0xc(%ebp), %xmm0\n" /* y */
        "movss %xmm0, 0x10(%esp)\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "xorps 0x3030c0, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %ebx, 8(%esp)\n" /* font */
        "movl $0x7fffffff, 4(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* s */
        "movl %eax, (%esp)\n"
        "calll CL_DrawText\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 278 | step */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f632_0019f70c:\n"
        "mulss 0x2ed5d8, %xmm0\n" /* line 271 | 0.5f */
        "jmp .Lf19f632_0019f683\n"
    );
}

/* line 290 */
__attribute__((naked))
int CG_DrawBigDevStringColor(float x, float y, const char *s, const vec_t *color, int align)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 290 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, 0x18(%esp)\n" /* line 292 */
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xbc80(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* align */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* color */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* s */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_DrawDevString\n"
        "leave\n" /* line 293 */
        "retl\n"
    );
}

/* line 305 */
__attribute__((naked))
int CG_DrawSmallDevStringColor(float x, float y, const char *s, const vec_t *color, int align)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 305 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl $0, 0x18(%esp)\n" /* line 307 */
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xbc7c(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* align */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* color */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* s */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_DrawDevString\n"
        "leave\n" /* line 308 */
        "retl\n"
    );
}

/* line 394 */
__attribute__((naked))
float * CG_FadeColor(int startMsec, int totalMsec, int fadeMsec)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 394 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* startMsec */
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 399 */
        "jne .Lf19f7aa_0019f7b8\n"
        ".Lf19f7aa_0019f7b4:\n"
        "xorl %eax, %eax\n" /* line 421 */
        /* } scope */
        "popl %ebp\n" /* line 422 */
        "retl\n"
        /* { scope 1 */
        ".Lf19f7aa_0019f7b8:\n"
        "movl 0x195f584, %eax\n" /* line 404 */
        "movl (%eax), %eax\n"
        "movl 0x25bb0(%eax), %eax\n"
        "subl %edx, %eax\n"
        "cmpl 0xc(%ebp), %eax\n" /* line 406 | totalMsec */
        "jge .Lf19f7aa_0019f7b4\n"
        "movl 0xc(%ebp), %edx\n" /* line 412 | totalMsec */
        "subl %eax, %edx\n"
        "cmpl 0x10(%ebp), %edx\n" /* fadeMsec */
        "jge .Lf19f7aa_0019f810\n"
        "cvtsi2ssl %edx, %xmm0\n" /* line 414 */
        "cvtsi2ssl 0x10(%ebp), %xmm1\n" /* fadeMsec */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xf3170c\n"
        ".Lf19f7aa_0019f7eb:\n"
        "movl $0x3f800000, 0xf31708\n" /* line 420 */
        "movl $0x3f800000, 0xf31704\n"
        "movl $0x3f800000, color\n"
        "movl $color, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 422 */
        "retl\n"
        /* { scope 1 */
        ".Lf19f7aa_0019f810:\n"
        "movl $0x3f800000, 0xf3170c\n" /* line 418 */
        "jmp .Lf19f7aa_0019f7eb\n"
    );
}

/* line 528 */
__attribute__((naked))
void CG_NorthDirectionChanged(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 528 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        /* { scope 1 */
        "movl $0xb, (%esp)\n" /* line 532 */
        "calll CL_GetConfigString\n"
        "movl 0x195f584, %edx\n" /* line 533 */
        "movl (%edx), %ebx\n"
        "movl %eax, (%esp)\n"
        "calll atof\n"
        "fstpl -0x10(%ebp)\n"
        "cvtsd2ss -0x10(%ebp), %xmm0\n"
        "movss %xmm0, 0x2c5ac(%ebx)\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 534 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 542 */
__attribute__((naked))
void CG_UpdateCompassOrientation(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 542 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0x195f584, %edi\n" /* line 560 */
        "movl (%edi), %ebx\n"
        "movss 0x285cc(%ebx), %xmm0\n"
        "subss 0x2c5ac(%ebx), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps -0x1c(%ebp)\n" /* fTargetYaw */
        "movl 0x2c5a8(%ebx), %edx\n" /* line 562 */
        "movl 0x25bb0(%ebx), %eax\n"
        "cmpl %eax, %edx\n"
        "jg .Lf19f858_0019f8a7\n"
        "movl %eax, %esi\n" /* iTotalTime */
        "subl %edx, %esi\n" /* iTotalTime */
        "cvtsi2ssl %esi, %xmm0\n" /* iTotalTime */
        "ucomiss 0x2ed7a4, %xmm0\n" /* 500.0f */
        "jbe .Lf19f858_0019f8cc\n"
        ".Lf19f858_0019f8a7:\n"
        "movl %eax, 0x2c5a8(%ebx)\n" /* line 564 */
        "movss -0x1c(%ebp), %xmm0\n" /* line 565 | fTargetYaw */
        "movss %xmm0, 0x2c5b0(%ebx)\n"
        "movl $0, 0x2c5b4(%ebx)\n" /* line 566 */
        /* } scope */
        ".Lf19f858_0019f8c4:\n"
        "addl $0x4c, %esp\n" /* line 640 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f858_0019f8cc:\n"
        "movl %eax, 0x2c5a8(%ebx)\n" /* line 571 */
        "movss -0x1c(%ebp), %xmm1\n" /* line 573 | fTargetYaw */
        "movss %xmm1, 4(%esp)\n"
        "movl 0x2c5b0(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm4\n"
        "testl %esi, %esi\n" /* line 576 | iTotalTime */
        "jle .Lf19f858_0019fb70\n"
        "movl %edi, %edx\n"
        "xorl %edi, %edi\n"
        ".Lf19f858_0019f8ff:\n"
        "cmpl $5, %esi\n" /* line 579 | iTotalTime */
        "jg .Lf19f858_0019fa64\n"
        "cvtsi2ssl %esi, %xmm0\n" /* iTotalTime */
        "xorl %esi, %esi\n" /* iTotalTime */
        "movaps %xmm0, %xmm2\n" /* line 589 */
        "mulss 0x2ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movaps %xmm4, %xmm0\n" /* line 592 */
        "andps 0x3030d0, %xmm0\n"
        "ucomiss 0x2ed604, %xmm0\n" /* 0.25f */
        "jae .Lf19f858_0019fa91\n"
        ".Lf19f858_0019f930:\n"
        "jp .Lf19f858_0019fa91\n"
        "movl (%edx), %eax\n"
        "movss 0x2c5b4(%eax), %xmm0\n"
        "andps 0x3030d0, %xmm0\n"
        "ucomiss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "jb .Lf19f858_0019fb2e\n"
        ".Lf19f858_0019f954:\n"
        "movl %eax, %ebx\n"
        ".Lf19f858_0019f956:\n"
        "movaps %xmm2, %xmm0\n" /* line 601 */
        "mulss 0x2c5b4(%ebx), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x38(%ebp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm4\n"
        "movl %edi, -0x3c(%ebp)\n" /* line 604 */
        "movss -0x3c(%ebp), %xmm5\n"
        "ucomiss %xmm5, %xmm4\n"
        "movss -0x38(%ebp), %xmm2\n"
        "jbe .Lf19f858_0019fae3\n"
        "movaps %xmm2, %xmm1\n" /* line 605 */
        "mulss 0x2ed5c8, %xmm1\n" /* 1000.0f */
        "movss 0x2c5b4(%ebx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c5b4(%ebx)\n"
        ".Lf19f858_0019f9b1:\n"
        "movl 0x195f584, %edx\n"
        "movl (%edx), %eax\n"
        ".Lf19f858_0019f9b9:\n"
        "movss 0x2c5b4(%eax), %xmm1\n" /* line 610 */
        "movaps %xmm1, %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c5b4(%eax)\n"
        "movaps %xmm5, %xmm3\n" /* line 611 */
        "ucomiss %xmm5, %xmm1\n"
        "jbe .Lf19f858_0019fab1\n"
        "ucomiss %xmm5, %xmm4\n" /* line 613 */
        "jbe .Lf19f858_0019fb21\n"
        "movaps %xmm1, %xmm0\n" /* line 614 */
        "mulss 0x2ed980, %xmm0\n" /* 3.5f */
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c5b4(%eax)\n"
        "movaps %xmm1, %xmm0\n"
        ".Lf19f858_0019fa0b:\n"
        "subss %xmm2, %xmm0\n" /* line 616 */
        "movss %xmm0, 0x2c5b4(%eax)\n"
        "ucomiss %xmm0, %xmm3\n" /* line 617 */
        "ja .Lf19f858_0019fb14\n"
        ".Lf19f858_0019fa20:\n"
        "movl (%edx), %eax\n" /* line 631 */
        "movss 0x2c5b4(%eax), %xmm0\n"
        "ucomiss 0x2ed984, %xmm0\n" /* 30000.0f */
        "jbe .Lf19f858_0019fa98\n"
        "movl $0x46ea6000, 0x2c5b4(%eax)\n" /* line 632 */
        ".Lf19f858_0019fa3d:\n"
        "testl %esi, %esi\n" /* line 576 | iTotalTime */
        "jg .Lf19f858_0019f8ff\n"
        ".Lf19f858_0019fa45:\n"
        "movl (%edx), %ebx\n" /* line 639 */
        "addss -0x1c(%ebp), %xmm4\n" /* fTargetYaw */
        "movss %xmm4, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c5b0(%ebx)\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 640 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19f858_0019fa64:\n"
        "subl $5, %esi\n" /* line 582 | iTotalTime */
        "movss 0x2ed6d4, %xmm0\n" /* 5.0f */
        "movaps %xmm0, %xmm2\n" /* line 589 */
        "mulss 0x2ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movaps %xmm4, %xmm0\n" /* line 592 */
        "andps 0x3030d0, %xmm0\n"
        "ucomiss 0x2ed604, %xmm0\n" /* 0.25f */
        "jb .Lf19f858_0019f930\n"
        ".Lf19f858_0019fa91:\n"
        "movl (%edx), %ebx\n"
        "jmp .Lf19f858_0019f956\n"
        ".Lf19f858_0019fa98:\n"
        "movss 0x2ed988, %xmm1\n" /* line 633 | -30000.0f */
        "ucomiss %xmm0, %xmm1\n"
        "jbe .Lf19f858_0019fa3d\n"
        "movl $0xc6ea6000, 0x2c5b4(%eax)\n" /* line 634 */
        "jmp .Lf19f858_0019fa3d\n"
        ".Lf19f858_0019fab1:\n"
        "ucomiss %xmm4, %xmm5\n" /* line 622 */
        "ja .Lf19f858_0019fb50\n"
        ".Lf19f858_0019faba:\n"
        "addss 0x2c5b4(%eax), %xmm2\n" /* line 625 */
        "movaps %xmm5, %xmm0\n" /* line 627 */
        "movaps %xmm5, %xmm1\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c5b4(%eax)\n"
        "jmp .Lf19f858_0019fa20\n"
        ".Lf19f858_0019fae3:\n"
        "ucomiss %xmm4, %xmm5\n" /* line 606 */
        "jbe .Lf19f858_0019f9b1\n"
        "movl 0x195f584, %edx\n" /* line 607 */
        "movl (%edx), %eax\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x2ed5c8, %xmm0\n" /* 1000.0f */
        "addss 0x2c5b4(%eax), %xmm0\n"
        "movss %xmm0, 0x2c5b4(%eax)\n"
        "jmp .Lf19f858_0019f9b9\n"
        ".Lf19f858_0019fb14:\n"
        "movss %xmm3, 0x2c5b4(%eax)\n" /* line 618 */
        "jmp .Lf19f858_0019fa20\n"
        ".Lf19f858_0019fb21:\n"
        "movss 0x2c5b4(%eax), %xmm0\n"
        "jmp .Lf19f858_0019fa0b\n"
        ".Lf19f858_0019fb2e:\n"
        "jp .Lf19f858_0019f954\n" /* line 592 */
        "movss -0x1c(%ebp), %xmm0\n" /* line 594 | fTargetYaw */
        "movss %xmm0, 0x2c5b0(%eax)\n"
        "movl $0, 0x2c5b4(%eax)\n" /* line 595 */
        "jmp .Lf19f858_0019f8c4\n"
        ".Lf19f858_0019fb50:\n"
        "movaps %xmm1, %xmm0\n" /* line 623 */
        "mulss 0x2ed980, %xmm0\n" /* 3.5f */
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c5b4(%eax)\n"
        "jmp .Lf19f858_0019faba\n"
        ".Lf19f858_0019fb70:\n"
        "movl 0x195f584, %edx\n"
        "jmp .Lf19f858_0019fa45\n"
    );
}

/* line 648 */
__attribute__((naked))
void CG_UpdateCompPointerOrientation(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 648 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x40, %esp\n"
        /* { scope 1 */
        "movl 0x195f6d8, %eax\n" /* line 667 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lf19fb7c_0019fbab\n"
        "movl 0x195f584, %eax\n" /* line 669 */
        "movl (%eax), %edx\n"
        "movl 0x285cc(%edx), %eax\n"
        "movl %eax, 0x2c5b8(%edx)\n"
        /* } scope */
        ".Lf19fb7c_0019fba4:\n"
        "addl $0x40, %esp\n" /* line 765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19fb7c_0019fbab:\n"
        "movl 0x195f584, %eax\n" /* line 673 */
        "movl (%eax), %eax\n"
        "movl 0x2c5a8(%eax), %ecx\n"
        "movl 0x25bb0(%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "je .Lf19fb7c_0019fba4\n"
        "movss 0x285cc(%eax), %xmm0\n" /* line 676 */
        "movss %xmm0, -0xc(%ebp)\n" /* fTargetYaw */
        "jg .Lf19fb7c_0019fbe2\n" /* line 678 */
        "movl %edx, %esi\n" /* iTotalTime */
        "subl %ecx, %esi\n" /* iTotalTime */
        "cvtsi2ssl %esi, %xmm0\n" /* iTotalTime */
        "ucomiss 0x2ed7a4, %xmm0\n" /* 500.0f */
        "jbe .Lf19fb7c_0019fc06\n"
        ".Lf19fb7c_0019fbe2:\n"
        "movl %edx, 0x2c5a8(%eax)\n" /* line 680 */
        ".Lf19fb7c_0019fbe8:\n"
        "movss -0xc(%ebp), %xmm1\n" /* line 681 | fTargetYaw */
        "movss %xmm1, 0x2c5b8(%eax)\n"
        "movl $0, 0x2c5bc(%eax)\n" /* line 682 */
        /* } scope */
        "addl $0x40, %esp\n" /* line 765 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf19fb7c_0019fc06:\n"
        "movl %edx, 0x2c5a8(%eax)\n" /* line 687 */
        "movss -0xc(%ebp), %xmm0\n" /* line 689 | fTargetYaw */
        "movss %xmm0, 4(%esp)\n"
        "movl 0x2c5b8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll AngleSubtract\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm4\n"
        "movss 0x3030e0, %xmm1\n" /* line 692 */
        "movaps %xmm4, %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "ucomiss 0x2ed6b4, %xmm0\n" /* 10.0f */
        "ja .Lf19fb7c_0019fe72\n"
        ".Lf19fb7c_0019fc48:\n"
        "testl %esi, %esi\n" /* line 701 | iTotalTime */
        "jle .Lf19fb7c_0019fe93\n"
        "movl 0x195f584, %ecx\n"
        "cmpl $5, %esi\n" /* line 704 | iTotalTime */
        "jle .Lf19fb7c_0019fdae\n"
        ".Lf19fb7c_0019fc5f:\n"
        "subl $5, %esi\n" /* line 707 | iTotalTime */
        "movss 0x2ed6d4, %xmm0\n" /* 5.0f */
        "movaps %xmm0, %xmm2\n" /* line 714 */
        "mulss 0x2ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movaps %xmm4, %xmm0\n" /* line 717 */
        "andps %xmm1, %xmm0\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "jae .Lf19fb7c_0019fdd2\n"
        ".Lf19fb7c_0019fc88:\n"
        "jp .Lf19fb7c_0019fdd2\n"
        "movl (%ecx), %eax\n"
        "movss 0x2c5bc(%eax), %xmm0\n"
        "andps %xmm1, %xmm0\n"
        "ucomiss 0x2ed62c, %xmm0\n" /* 2.0f */
        "jb .Lf19fb7c_0019fe88\n"
        ".Lf19fb7c_0019fca8:\n"
        "movl %eax, %ebx\n"
        ".Lf19fb7c_0019fcaa:\n"
        "movaps %xmm2, %xmm0\n" /* line 726 */
        "mulss 0x2c5bc(%ebx), %xmm0\n"
        "addss %xmm4, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "movss %xmm2, -0x28(%ebp)\n"
        "calll AngleNormalize180\n"
        "fstps -0x2c(%ebp)\n"
        "movss -0x2c(%ebp), %xmm4\n"
        "pxor %xmm5, %xmm5\n" /* line 729 */
        "ucomiss %xmm5, %xmm4\n"
        "movss -0x28(%ebp), %xmm2\n"
        "jbe .Lf19fb7c_0019fe27\n"
        "movaps %xmm2, %xmm1\n" /* line 730 */
        "mulss 0x2ed950, %xmm1\n" /* 1500.0f */
        "movss 0x2c5bc(%ebx), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c5bc(%ebx)\n"
        ".Lf19fb7c_0019fd01:\n"
        "movl 0x195f584, %ecx\n"
        "movl (%ecx), %eax\n"
        ".Lf19fb7c_0019fd09:\n"
        "movss 0x2c5bc(%eax), %xmm1\n" /* line 735 */
        "movaps %xmm1, %xmm0\n"
        "mulss 0x2ed720, %xmm0\n" /* 3.0f */
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c5bc(%eax)\n"
        "movaps %xmm5, %xmm3\n" /* line 736 */
        "ucomiss %xmm5, %xmm1\n"
        "jbe .Lf19fb7c_0019fdf1\n"
        "ucomiss %xmm5, %xmm4\n" /* line 738 */
        "jbe .Lf19fb7c_0019fe65\n"
        "movaps %xmm1, %xmm0\n" /* line 739 */
        "mulss 0x2ed6d4, %xmm0\n" /* 5.0f */
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c5bc(%eax)\n"
        "movaps %xmm1, %xmm0\n"
        ".Lf19fb7c_0019fd5f:\n"
        "addss %xmm2, %xmm2\n" /* line 741 */
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, 0x2c5bc(%eax)\n"
        "ucomiss %xmm0, %xmm3\n" /* line 742 */
        "ja .Lf19fb7c_0019fe58\n"
        ".Lf19fb7c_0019fd78:\n"
        "movl (%ecx), %edx\n" /* line 756 */
        "movss 0x2c5bc(%edx), %xmm0\n"
        "ucomiss 0x2ed990, %xmm0\n" /* 2000.0f */
        "jbe .Lf19fb7c_0019fdd9\n"
        "movl $0x44fa0000, 0x2c5bc(%edx)\n" /* line 757 */
        ".Lf19fb7c_0019fd95:\n"
        "testl %esi, %esi\n" /* line 701 | iTotalTime */
        "jle .Lf19fb7c_0019fe99\n"
        "movss 0x3030e0, %xmm1\n"
        "cmpl $5, %esi\n" /* line 704 | iTotalTime */
        "jg .Lf19fb7c_0019fc5f\n"
        ".Lf19fb7c_0019fdae:\n"
        "cvtsi2ssl %esi, %xmm0\n" /* iTotalTime */
        "xorl %esi, %esi\n" /* iTotalTime */
        "movaps %xmm0, %xmm2\n" /* line 714 */
        "mulss 0x2ed658, %xmm2\n" /* 0.0010000000474974513f */
        "movaps %xmm4, %xmm0\n" /* line 717 */
        "andps %xmm1, %xmm0\n"
        "ucomiss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "jb .Lf19fb7c_0019fc88\n"
        ".Lf19fb7c_0019fdd2:\n"
        "movl (%ecx), %ebx\n"
        "jmp .Lf19fb7c_0019fcaa\n"
        ".Lf19fb7c_0019fdd9:\n"
        "ucomiss 0x2ed994, %xmm0\n" /* line 758 | -2000.0f */
        "jae .Lf19fb7c_0019fd95\n"
        "jp .Lf19fb7c_0019fd95\n"
        "movl $0xc4fa0000, %eax\n" /* line 759 */
        "movl %eax, 0x2c5bc(%edx)\n"
        "jmp .Lf19fb7c_0019fd95\n"
        ".Lf19fb7c_0019fdf1:\n"
        "ucomiss %xmm4, %xmm5\n" /* line 747 */
        "ja .Lf19fb7c_0019feb5\n"
        ".Lf19fb7c_0019fdfa:\n"
        "addss %xmm2, %xmm2\n" /* line 750 */
        "addss 0x2c5bc(%eax), %xmm2\n"
        "movaps %xmm5, %xmm0\n" /* line 752 */
        "movaps %xmm5, %xmm1\n"
        "cmpltss %xmm2, %xmm0\n"
        "andps %xmm0, %xmm1\n"
        "andnps %xmm2, %xmm0\n"
        "orps %xmm1, %xmm0\n"
        "movss %xmm0, 0x2c5bc(%eax)\n"
        "jmp .Lf19fb7c_0019fd78\n"
        ".Lf19fb7c_0019fe27:\n"
        "ucomiss %xmm4, %xmm5\n" /* line 731 */
        "jbe .Lf19fb7c_0019fd01\n"
        "movl 0x195f584, %ecx\n" /* line 732 */
        "movl (%ecx), %eax\n"
        "movaps %xmm2, %xmm0\n"
        "mulss 0x2ed950, %xmm0\n" /* 1500.0f */
        "addss 0x2c5bc(%eax), %xmm0\n"
        "movss %xmm0, 0x2c5bc(%eax)\n"
        "jmp .Lf19fb7c_0019fd09\n"
        ".Lf19fb7c_0019fe58:\n"
        "movss %xmm3, 0x2c5bc(%eax)\n" /* line 743 */
        "jmp .Lf19fb7c_0019fd78\n"
        ".Lf19fb7c_0019fe65:\n"
        "movss 0x2c5bc(%eax), %xmm0\n"
        "jmp .Lf19fb7c_0019fd5f\n"
        ".Lf19fb7c_0019fe72:\n"
        "ucomiss 0x2ed5e8, %xmm4\n" /* line 694 | 0.0f */
        "jb .Lf19fb7c_0019fed5\n"
        ".Lf19fb7c_0019fe7b:\n"
        "movss 0x2ed6b4, %xmm4\n" /* 10.0f */
        "jmp .Lf19fb7c_0019fc48\n"
        ".Lf19fb7c_0019fe88:\n"
        "jnp .Lf19fb7c_0019fbe8\n" /* line 717 */
        "jmp .Lf19fb7c_0019fca8\n"
        ".Lf19fb7c_0019fe93:\n"
        "movl 0x195f584, %ecx\n"
        ".Lf19fb7c_0019fe99:\n"
        "movl (%ecx), %ebx\n" /* line 764 */
        "addss -0xc(%ebp), %xmm4\n" /* fTargetYaw */
        "movss %xmm4, (%esp)\n"
        "calll AngleNormalize360\n"
        "fstps 0x2c5b8(%ebx)\n"
        "jmp .Lf19fb7c_0019fba4\n"
        ".Lf19fb7c_0019feb5:\n"
        "movaps %xmm1, %xmm0\n" /* line 748 */
        "mulss 0x2ed6d4, %xmm0\n" /* 5.0f */
        "mulss %xmm2, %xmm0\n"
        "subss %xmm0, %xmm1\n"
        "movss %xmm1, 0x2c5bc(%eax)\n"
        "jmp .Lf19fb7c_0019fdfa\n"
        ".Lf19fb7c_0019fed5:\n"
        "jp .Lf19fb7c_0019fe7b\n" /* line 694 */
        "movss 0x2ed98c, %xmm4\n" /* -10.0f */
        "jmp .Lf19fb7c_0019fc48\n"
    );
}

/* line 337 */
__attribute__((naked))
void CG_TileClear(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 337 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0x195f5c4, %eax\n" /* line 330 */
        "movl (%eax), %ecx\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %edx\n"
        "movl 0x5e84(%ecx), %eax\n"
        "cmpl 0x28570(%edx), %eax\n"
        "je .Lf19fee6_0019ff42\n"
        ".Lf19fee6_0019ff08:\n"
        "calll CL_SetFullScreenViewport\n" /* line 368 */
        "movl 0x195f584, %eax\n" /* line 385 */
        "movl (%eax), %edx\n"
        "movl 0x2857c(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x28578(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x28574(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x28570(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CL_SetViewport\n"
        "leave\n" /* line 386 */
        "retl\n"
        ".Lf19fee6_0019ff42:\n"
        "movl 0x5e88(%ecx), %eax\n" /* line 330 */
        "cmpl 0x28574(%edx), %eax\n"
        "jne .Lf19fee6_0019ff08\n"
        "movl 0x5e8c(%ecx), %eax\n"
        "cmpl 0x28578(%edx), %eax\n"
        "jne .Lf19fee6_0019ff08\n"
        "movl 0x5e90(%ecx), %eax\n"
        "cmpl 0x2857c(%edx), %eax\n"
        "jne .Lf19fee6_0019ff08\n"
        "leave\n" /* line 386 */
        "retl\n"
    );
}

/* line 281 */
__attribute__((naked))
int CG_DrawBigDevString(float x, float y, const char *s, float alpha, int align)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 281 */
        "movl %esp, %ebp\n"
        "subl $0x38, %esp\n"
        /* { scope 1 */
        "movl $0x3f800000, %eax\n" /* line 447 */
        "movl %eax, -0x18(%ebp)\n" /* color */
        "movl %eax, -0x14(%ebp)\n" /* line 448 */
        "movl %eax, -0x10(%ebp)\n" /* line 449 */
        "movl 0x14(%ebp), %eax\n" /* line 450 | alpha */
        "movl %eax, -0xc(%ebp)\n"
        "movl $0, 0x18(%esp)\n" /* line 292 */
        "movl 0x195f5c4, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0xbc80(%eax), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* align */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x18(%ebp), %eax\n" /* color */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* s */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_DrawDevString\n"
        /* } scope */
        "leave\n" /* line 287 */
        "retl\n"
    );
}

/* line 144 */
__attribute__((naked))
void CG_DrawRotatedPicPhysical(float x, float y, float width, float height, float angle, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "subl $0x58, %esp\n"
        /* { scope 1: radians */
        "cvtss2sd 0x18(%ebp), %xmm0\n" /* line 163 | angle */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x38(%ebp)\n"
        "movss -0x34(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        /* } scope */
        "movss 0x2ed5d8, %xmm0\n" /* line 164 | 0.5f */
        "movss 0x10(%ebp), %xmm1\n" /* width */
        "mulss %xmm0, %xmm1\n"
        "mulss 0x14(%ebp), %xmm0\n" /* line 165 | height */
        "movaps %xmm1, %xmm3\n" /* line 166 */
        "addss 8(%ebp), %xmm3\n" /* x */
        "movss %xmm3, -0x2c(%ebp)\n"
        "movaps %xmm0, %xmm3\n" /* line 167 */
        "addss 0xc(%ebp), %xmm3\n" /* y */
        "movss %xmm3, -0x30(%ebp)\n"
        "movaps %xmm2, %xmm7\n" /* line 168 */
        "mulss %xmm1, %xmm7\n"
        "movss -0x38(%ebp), %xmm6\n" /* line 169 */
        "mulss %xmm1, %xmm6\n"
        "movss -0x38(%ebp), %xmm5\n" /* line 170 */
        "mulss %xmm0, %xmm5\n"
        "movaps %xmm2, %xmm4\n" /* line 171 */
        "mulss %xmm0, %xmm4\n"
        "xorl %ecx, %ecx\n"
        "movl $sign, %edx\n"
        "xorl %eax, %eax\n"
        ".Lf19ffca_001a0063:\n"
        "movss (%edx), %xmm1\n" /* line 176 */
        "movss 4(%edx), %xmm3\n"
        "movaps %xmm7, %xmm0\n"
        "mulss %xmm1, %xmm0\n"
        "addss -0x2c(%ebp), %xmm0\n"
        "movaps %xmm6, %xmm2\n"
        "mulss %xmm3, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "movss %xmm0, -0x28(%eax, %ebp)\n"
        "mulss %xmm5, %xmm1\n" /* line 177 */
        "addss -0x30(%ebp), %xmm1\n"
        "mulss %xmm4, %xmm3\n"
        "addss %xmm3, %xmm1\n"
        "movss %xmm1, -0x24(%eax, %ebp)\n"
        "addl $1, %ecx\n" /* line 174 */
        "addl $8, %eax\n"
        "addl $8, %edx\n"
        "cmpl $4, %ecx\n"
        "jne .Lf19ffca_001a0063\n"
        "movl 0x20(%ebp), %eax\n" /* line 180 | material */
        "movl %eax, 8(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* verts */
        "movl %eax, (%esp)\n"
        "calll CL_DrawQuadPic\n"
        /* } scope */
        "leave\n" /* line 181 */
        "retl\n"
    );
}

/* line 184 */
__attribute__((naked))
void CG_DrawRotatedPic(float x, float y, float width, float height, int horzAlign, int vertAlign, float angle, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 184 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 0x1c(%ebp), %eax\n" /* line 186 | vertAlign */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* horzAlign */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x14(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x10(%ebp), %eax\n" /* width */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "leal 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CalcScreenPlacement\n"
        "movl 0x28(%ebp), %eax\n" /* line 187 | material */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x24(%ebp), %eax\n" /* color */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x20(%ebp), %eax\n" /* angle */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* height */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* width */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* y */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* x */
        "movl %eax, (%esp)\n"
        "calll CG_DrawRotatedPicPhysical\n"
        "leave\n" /* line 188 */
        "retl\n"
    );
}

/* line 199 */
__attribute__((naked))
void CG_DrawRotatedQuadPic(float x, float y, vec2_t *verts, float angle, const vec_t *color, MaterialHandle material)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1: radians */
        "cvtss2sd 0x14(%ebp), %xmm0\n" /* line 206 | angle */
        "mulsd 0x307c48, %xmm0\n" /* 0.017453292519943295 */
        "cvtsd2ss %xmm0, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n" /* radians */
        /* { scope 2 */
        "movss %xmm0, (%esp)\n" /* line 485 */
        "calll sinf\n"
        "fstps -0x30(%ebp)\n" /* s */
        "movss -0x2c(%ebp), %xmm0\n" /* line 486 | radians */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x3c(%ebp)\n"
        "movss -0x3c(%ebp), %xmm2\n"
        "movl 0x10(%ebp), %eax\n" /* verts */
        "movl $1, %ecx\n"
        "leal -0x28(%ebp), %ebx\n" /* xy */
        "movl $8, %edx\n"
        /* } scope */
        ".Lf1a0136_001a0187:\n"
        "movaps %xmm2, %xmm0\n" /* line 210 */
        "mulss (%eax), %xmm0\n"
        "addss 8(%ebp), %xmm0\n" /* x */
        "movss -0x30(%ebp), %xmm1\n" /* s */
        "mulss 4(%eax), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -8(%edx, %ebx)\n"
        "movss -0x30(%ebp), %xmm0\n" /* line 211 | s */
        "mulss (%eax), %xmm0\n"
        "addss 0xc(%ebp), %xmm0\n" /* y */
        "movaps %xmm2, %xmm1\n"
        "mulss 4(%eax), %xmm1\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edx, %ebx)\n"
        "addl $1, %ecx\n"
        "addl $8, %edx\n"
        "addl $8, %eax\n"
        "cmpl $5, %ecx\n" /* line 208 */
        "jne .Lf1a0136_001a0187\n"
        "movl 0x1c(%ebp), %eax\n" /* line 214 | material */
        "movl %eax, 8(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* color */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CL_DrawQuadPic\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 215 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

