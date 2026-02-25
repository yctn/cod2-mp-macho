/* ASM dump from: cg_marks_mp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/cgame_mp/cg_marks_mp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 *   #include "PC/universal/com_vector.h"
 */

extern MarkPoly cg_markPolys[1024]; /* 0x0 */
extern MarkPoly *cg_freeMarkPolys; /* 0x0 */
extern MarkVertAssemblyBuffer markVerts; /* 0x0 */

void CG_InitMarkPolys(void);
void CG_AddMarks(void);
void CG_ImpactMark(MaterialHandle markMaterial, const vec_t *origin, const vec_t *dir, float orientation, const vec_t *color, float radius);

/* line 34 */
__attribute__((naked))
void CG_InitMarkPolys(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 34 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        /* { scope 1 */
        "movl 0x195f5f8, %eax\n" /* line 44 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %ebx\n" /* lasttrav */
        "leal (%ebx, %ebx, 8), %eax\n" /* line 46 | lasttrav */
        "leal (%eax, %eax, 8), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $cg_markPolys, (%esp)\n"
        "calll memset\n"
        "movl 0x195f584, %eax\n" /* line 48 */
        "movl (%eax), %eax\n"
        "leal 0xf3714(%eax), %edx\n"
        "movl %edx, 0xf3718(%eax)\n"
        "movl %edx, 0xf3714(%eax)\n" /* line 49 */
        "movl $0x173b880, cg_freeMarkPolys\n" /* line 50 */
        "leal -1(%ebx), %esi\n" /* line 52 | lasttrav */
        "testl %esi, %esi\n"
        "jle .Lf17a7b0_0017a82f\n"
        "xorl %ecx, %ecx\n"
        "movl $0x173bb08, %eax\n"
        "movl $cg_markPolys, %ebx\n" /* lasttrav */
        "jmp .Lf17a7b0_0017a81d\n"
        ".Lf17a7b0_0017a81b:\n"
        "movl %edx, %eax\n"
        ".Lf17a7b0_0017a81d:\n"
        "movl %eax, 4(%ebx)\n" /* line 54 | lasttrav */
        "addl $1, %ecx\n" /* line 52 */
        "leal 0x288(%eax), %edx\n"
        "movl %eax, %ebx\n" /* lasttrav */
        "cmpl %ecx, %esi\n"
        "jne .Lf17a7b0_0017a81b\n"
        /* } scope */
        ".Lf17a7b0_0017a82f:\n"
        "addl $0x10, %esp\n" /* line 57 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 220 */
__attribute__((naked))
void CG_AddMarks(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 220 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x195f5fc, %eax\n" /* line 228 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17a838_0017a8de\n"
        "movl 0x195f584, %edx\n" /* line 234 */
        "movl (%edx), %eax\n"
        "movl 0xf3718(%eax), %ebx\n" /* markPoly */
        "addl $0xf3714, %eax\n"
        "cmpl %eax, %ebx\n" /* markPoly */
        "je .Lf17a838_0017a8de\n"
        "movl 0x195ed88, %edi\n"
        "movl %edx, %esi\n"
        "jmp .Lf17a838_0017a881\n"
        ".Lf17a838_0017a873:\n"
        "movl 4(%ebx), %ebx\n" /* markPoly */
        "movl (%esi), %eax\n"
        "addl $0xf3714, %eax\n"
        "cmpl %eax, %ebx\n" /* markPoly */
        "je .Lf17a838_0017a8de\n"
        ".Lf17a838_0017a881:\n"
        "movl (%edi), %edx\n" /* line 236 */
        "movl 0x80(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebx), %eax\n" /* markPoly */
        "movl %eax, 8(%esp)\n"
        "leal 0xc(%ebx), %eax\n" /* markPoly */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll FxHelper_CullSphere\n"
        "testb %al, %al\n" /* line 238 */
        "jne .Lf17a838_0017a873\n"
        "movl (%esi), %eax\n" /* line 241 */
        "movl (%eax), %eax\n"
        "movl %eax, 8(%ebx)\n" /* markPoly */
        "leal 0x24(%ebx), %eax\n" /* line 243 | markPoly */
        "movl %eax, 0xc(%esp)\n"
        "movzbl 0x22(%ebx), %eax\n" /* markPoly */
        "movl %eax, 8(%esp)\n"
        "movzwl 0x20(%ebx), %eax\n" /* markPoly */
        "movl %eax, 4(%esp)\n"
        "movl 0x1c(%ebx), %eax\n" /* markPoly */
        "movl %eax, (%esp)\n"
        "calll CL_AddPolyToScene\n"
        "movl 4(%ebx), %ebx\n" /* line 234 | markPoly */
        "movl (%esi), %eax\n"
        "addl $0xf3714, %eax\n"
        "cmpl %eax, %ebx\n" /* markPoly */
        "jne .Lf17a838_0017a881\n"
        /* } scope */
        ".Lf17a838_0017a8de:\n"
        "addl $0x1c, %esp\n" /* line 247 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 138 */
__attribute__((naked))
void CG_ImpactMark(MaterialHandle markMaterial, const vec_t *origin, const vec_t *dir, float orientation, const vec_t *color, float radius)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x12cc, %esp\n"
        /* { scope 1 */
        "movl 0x195f5fc, %eax\n" /* line 158 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lf17a8e6_0017a910\n"
        "movl 0x195f584, %eax\n"
        "movl (%eax), %eax\n"
        "movl 0x2bee8(%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf17a8e6_0017a91b\n"
        /* } scope */
        ".Lf17a8e6_0017a910:\n"
        "addl $0x12cc, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17a8e6_0017a91b:\n"
        "leal -0x40(%ebp), %eax\n" /* line 165 | axis */
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* dir */
        "movl %edx, (%esp)\n"
        "calll Vec3NormalizeTo\n"
        "fstp %st(0)\n"
        "leal -0x34(%ebp), %esi\n" /* line 166 */
        "movl %esi, 4(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* axis */
        "movl %eax, (%esp)\n"
        "calll PerpendicularVector\n"
        "movss 0x14(%ebp), %xmm0\n" /* line 167 | orientation */
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* axis */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll RotatePointAroundVector\n"
        "movl %esi, 8(%esp)\n" /* line 168 */
        "movl %ebx, 4(%esp)\n"
        "leal -0x40(%ebp), %edx\n" /* axis */
        "movl %edx, (%esp)\n"
        "calll Vec3Cross\n"
        "movl $1, %esi\n"
        "leal -0x70(%ebp), %edi\n" /* originalPoints, fragmentIndex */
        ".Lf17a8e6_0017a97d:\n"
        "leal (, %esi, 4), %edx\n" /* line 138 */
        "movl 0xc(%ebp), %eax\n" /* origin */
        "addl %edx, %eax\n"
        "leal 0xc(%edx), %ecx\n" /* line 175 */
        "movss 0x1c(%ebp), %xmm2\n" /* radius */
        "mulss -0x44(%ebp, %ecx), %xmm2\n"
        "leal 0x18(%edx), %ebx\n"
        "movss 0x1c(%ebp), %xmm1\n" /* radius */
        "mulss -0x44(%ebp, %ebx), %xmm1\n"
        "movss -4(%eax), %xmm0\n"
        "subss %xmm2, %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edi, %edx)\n" /* fragmentIndex */
        "movaps %xmm2, %xmm0\n" /* line 176 */
        "addss -4(%eax), %xmm0\n"
        "subss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edi, %ecx)\n" /* fragmentIndex */
        "movaps %xmm2, %xmm0\n" /* line 177 */
        "addss -4(%eax), %xmm0\n"
        "addss %xmm1, %xmm0\n"
        "movss %xmm0, -4(%edi, %ebx)\n" /* fragmentIndex */
        "movss -4(%eax), %xmm0\n" /* line 178 */
        "subss %xmm2, %xmm0\n"
        "addss %xmm0, %xmm1\n"
        "movss %xmm1, 0x20(%edx, %edi)\n"
        "addl $1, %esi\n"
        "cmpl $4, %esi\n" /* line 173 */
        "jne .Lf17a8e6_0017a97d\n"
        "movl 8(%ebp), %eax\n" /* line 183 | markMaterial */
        "movl %eax, 0x20(%esp)\n"
        "leal -0x1270(%ebp), %eax\n" /* markFragments */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0x180, 0x18(%esp)\n"
        "movl $markVerts, 0x14(%esp)\n"
        "movl $0x400, 0x10(%esp)\n"
        "movss 0x1c(%ebp), %xmm0\n" /* radius */
        "movss %xmm0, 0xc(%esp)\n"
        "leal -0x40(%ebp), %eax\n" /* axis */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* origin */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* fragmentIndex */
        "calll CL_MarkFragments\n"
        "movl %eax, -0x127c(%ebp)\n" /* fragmentCount */
        "movl 0x18(%ebp), %eax\n" /* line 428 | color */
        "movss (%eax), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1280(%ebp)\n"
        "cvttss2si -0x1280(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lf17a8e6_0017acc3\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf17a8e6_0017aa88:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf17a8e6_0017aa8a:\n"
        "movb %al, -0x1b(%ebp)\n" /* line 188 */
        "movl 0x18(%ebp), %edx\n" /* line 428 | color */
        "movss 4(%edx), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1284(%ebp)\n"
        "cvttss2si -0x1284(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lf17a8e6_0017acfc\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf17a8e6_0017aacf:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf17a8e6_0017aad1:\n"
        "movb %al, -0x1a(%ebp)\n" /* line 189 */
        "movl 0x18(%ebp), %edx\n" /* line 428 | color */
        "movss 8(%edx), %xmm0\n"
        "mulss 0x2ed5d4, %xmm0\n" /* 255.0f */
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x1288(%ebp)\n"
        "cvttss2si -0x1288(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lf17a8e6_0017ace9\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf17a8e6_0017ab16:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf17a8e6_0017ab18:\n"
        "movb %al, -0x19(%ebp)\n" /* line 190 */
        "movss 0x2ed5d4, %xmm0\n" /* line 428 | 255.0f */
        "movl 0x18(%ebp), %edx\n" /* color */
        "mulss 0xc(%edx), %xmm0\n"
        "addss 0x2ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0x128c(%ebp)\n"
        "cvttss2si -0x128c(%ebp), %edx\n"
        "movl %edx, %eax\n" /* line 154 */
        "subl $0xff, %eax\n"
        "js .Lf17a8e6_0017acd6\n"
        "movl $0xff, %edx\n"
        /* { scope 2 */
        ".Lf17a8e6_0017ab5d:\n"
        "movl %edx, %eax\n"
        /* } scope */
        ".Lf17a8e6_0017ab5f:\n"
        "movb %al, -0x1c(%ebp)\n" /* line 191 | nativeColor */
        "movl -0x127c(%ebp), %ebx\n" /* line 196 | fragmentCount */
        "testl %ebx, %ebx\n"
        "jle .Lf17a8e6_0017a910\n"
        "xorl %edi, %edi\n" /* fragmentIndex */
        "leal -0x126a(%ebp), %esi\n"
        ".Lf17a8e6_0017ab78:\n"
        "movl 2(%esi), %edx\n" /* line 201 */
        "movl %edx, %eax\n"
        "shll $6, %eax\n"
        "leal markVerts(%eax, %edx, 4), %eax\n"
        "movzbl (%esi), %ecx\n"
        "testl %ecx, %ecx\n"
        "jle .Lf17a8e6_0017aba0\n"
        "xorl %edx, %edx\n"
        "movl -0x1c(%ebp), %ebx\n" /* nativeColor */
        ".Lf17a8e6_0017ab93:\n"
        "movl %ebx, 0x18(%eax)\n" /* line 606 | to */
        "addl $1, %edx\n" /* line 201 */
        "addl $0x44, %eax\n"
        "cmpl %ecx, %edx\n"
        "jl .Lf17a8e6_0017ab93\n"
        ".Lf17a8e6_0017aba0:\n"
        "movl cg_freeMarkPolys, %ecx\n" /* line 108 */
        "testl %ecx, %ecx\n"
        "je .Lf17a8e6_0017ac72\n"
        "movl cg_freeMarkPolys, %ecx\n"
        ".Lf17a8e6_0017abb4:\n"
        "movl 4(%ecx), %eax\n" /* line 119 */
        "movl %eax, cg_freeMarkPolys\n"
        "movl 0x195f584, %eax\n" /* line 126 */
        "movl (%eax), %edx\n"
        "movl 0xf3718(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "leal 0xf3714(%edx), %eax\n" /* line 127 */
        "movl %eax, (%ecx)\n"
        "movl 0xf3718(%edx), %eax\n" /* line 128 */
        "movl %ecx, (%eax)\n"
        "movl %ecx, 0xf3718(%edx)\n" /* line 129 */
        "leal 0xc(%ecx), %ebx\n" /* line 207 | to */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 199 | origin */
        "movss (%eax), %xmm0\n"
        "movss %xmm0, 0xc(%ecx)\n"
        "movss 4(%eax), %xmm0\n" /* line 200 */
        "movss %xmm0, 4(%ebx)\n"
        "movss 8(%eax), %xmm0\n" /* line 201 */
        "movss %xmm0, 8(%ebx)\n"
        /* } scope */
        "movss 0x1c(%ebp), %xmm0\n" /* line 208 | radius */
        "movss %xmm0, 0x18(%ecx)\n"
        "movl -6(%esi), %eax\n" /* line 210 */
        "movl %eax, 0x1c(%ecx)\n"
        "movzwl -2(%esi), %eax\n" /* line 211 */
        "movw %ax, 0x20(%ecx)\n"
        "movzbl (%esi), %eax\n" /* line 212 */
        "movb %al, 0x22(%ecx)\n"
        "movl (%edx), %eax\n" /* line 213 */
        "movl %eax, 8(%ecx)\n"
        "addl $0x24, %ecx\n" /* line 215 */
        "movzbl (%esi), %ebx\n" /* to */
        "movl %ebx, %eax\n" /* to */
        "shll $6, %eax\n"
        "leal (%eax, %ebx, 4), %ebx\n" /* to */
        "movl 2(%esi), %eax\n"
        "movl %eax, %edx\n"
        "shll $6, %edx\n"
        "leal markVerts(%edx, %eax, 4), %eax\n"
        "movl %ebx, 8(%esp)\n" /* to */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %edi\n" /* line 196 | fragmentIndex */
        "addl $0xc, %esi\n"
        "cmpl %edi, -0x127c(%ebp)\n" /* fragmentIndex, fragmentCount */
        "jne .Lf17a8e6_0017ab78\n"
        /* } scope */
        "addl $0x12cc, %esp\n" /* line 217 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf17a8e6_0017ac72:\n"
        "movl 0x195f584, %edx\n" /* line 83 */
        "movl (%edx), %eax\n"
        "movl 0xf3714(%eax), %ebx\n"
        "leal 0xf3714(%eax), %ecx\n" /* line 86 */
        "cmpl %ecx, %ebx\n"
        "je .Lf17a8e6_0017ac9b\n"
        "movl %ebx, %edx\n"
        ".Lf17a8e6_0017ac8c:\n"
        "movl 8(%edx), %eax\n" /* line 90 */
        "cmpl 8(%ebx), %eax\n"
        "cmovll %edx, %ebx\n"
        "movl (%edx), %edx\n" /* line 86 */
        "cmpl %ecx, %edx\n"
        "jne .Lf17a8e6_0017ac8c\n"
        ".Lf17a8e6_0017ac9b:\n"
        "movl (%ebx), %edx\n" /* line 62 */
        "testl %edx, %edx\n"
        "je .Lf17a8e6_0017ad0f\n"
        ".Lf17a8e6_0017aca1:\n"
        "movl (%ebx), %edx\n" /* line 66 */
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 67 */
        "movl %edx, (%eax)\n"
        "movl cg_freeMarkPolys, %eax\n" /* line 70 */
        "movl %eax, 4(%ebx)\n"
        "movl %ebx, cg_freeMarkPolys\n" /* line 71 */
        "movl %ebx, %ecx\n"
        "jmp .Lf17a8e6_0017abb4\n"
        ".Lf17a8e6_0017acc3:\n"
        "movl %edx, %eax\n" /* line 154 */
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf17a8e6_0017aa88\n"
        "xorl %eax, %eax\n"
        "jmp .Lf17a8e6_0017aa8a\n"
        /* } scope */
        ".Lf17a8e6_0017acd6:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf17a8e6_0017ab5d\n"
        "xorl %eax, %eax\n"
        "jmp .Lf17a8e6_0017ab5f\n"
        /* } scope */
        ".Lf17a8e6_0017ace9:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf17a8e6_0017ab16\n"
        "xorl %eax, %eax\n"
        "jmp .Lf17a8e6_0017ab18\n"
        /* } scope */
        ".Lf17a8e6_0017acfc:\n"
        "movl %edx, %eax\n"
        "negl %eax\n"
        /* { scope 2 */
        "testl %eax, %eax\n"
        "js .Lf17a8e6_0017aacf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf17a8e6_0017aad1\n"
        /* } scope */
        ".Lf17a8e6_0017ad0f:\n"
        "movl $0x2ade80, 4(%esp)\n" /* line 63 */
        "movl $1, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lf17a8e6_0017aca1\n"
    );
}

