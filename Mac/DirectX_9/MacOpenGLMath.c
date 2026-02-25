/* ASM dump from: MacOpenGLMath.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/MacOpenGLMath.cpp */

#include "common_types.h"
#include "imports.h"

extern float COpenGLMatrix_sIdentity[16]; /* 0x0 */

void COpenGLMatrix_SetIdentity(const COpenGLMatrix * _this);
void COpenGLMatrix_Transpose(const COpenGLMatrix * _this);
bool COpenGLMatrix_Inverse(const COpenGLMatrix * _this, COpenGLMatrix *mResult);

/* line 144 */
__attribute__((naked))
void COpenGLMatrix_SetIdentity(const COpenGLMatrix * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x3f800000, (%eax)\n" /* line 148 */
        "movl $0, 4(%eax)\n" /* line 149 */
        "movl $0, 8(%eax)\n" /* line 150 */
        "movl $0, 0xc(%eax)\n" /* line 151 */
        "movl $0, 0x10(%eax)\n" /* line 152 */
        "movl $0x3f800000, 0x14(%eax)\n" /* line 153 */
        "movl $0, 0x18(%eax)\n" /* line 154 */
        "movl $0, 0x1c(%eax)\n" /* line 155 */
        "movl $0, 0x20(%eax)\n" /* line 156 */
        "movl $0, 0x24(%eax)\n" /* line 157 */
        "movl $0x3f800000, 0x28(%eax)\n" /* line 158 */
        "movl $0, 0x2c(%eax)\n" /* line 159 */
        "movl $0, 0x30(%eax)\n" /* line 160 */
        "movl $0, 0x34(%eax)\n" /* line 161 */
        "movl $0, 0x38(%eax)\n" /* line 162 */
        "movl $0x3f800000, 0x3c(%eax)\n" /* line 163 */
        "popl %ebp\n" /* line 164 */
        "retl\n"
    );
}

/* line 231 */
__attribute__((naked))
void COpenGLMatrix_Transpose(const COpenGLMatrix * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 231 */
        "movl %esp, %ebp\n"
        "subl $0x48, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        /* { scope 1 */
        "movl (%eax), %edx\n" /* line 237 */
        "movl %edx, -0x48(%ebp)\n" /* mCopy */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0x44(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x18(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x14(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x10(%ebp)\n"
        "movl 0x3c(%eax), %edx\n"
        "movl %edx, -0xc(%ebp)\n"
        "movl -0x48(%ebp), %edx\n" /* line 238 | mCopy */
        "movl %edx, (%eax)\n"
        "movl -0x38(%ebp), %edx\n" /* line 239 */
        "movl %edx, 4(%eax)\n"
        "movl -0x28(%ebp), %edx\n" /* line 240 */
        "movl %edx, 8(%eax)\n"
        "movl -0x18(%ebp), %edx\n" /* line 241 */
        "movl %edx, 0xc(%eax)\n"
        "movl -0x44(%ebp), %edx\n" /* line 242 */
        "movl %edx, 0x10(%eax)\n"
        "movl -0x34(%ebp), %edx\n" /* line 243 */
        "movl %edx, 0x14(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* line 244 */
        "movl %edx, 0x18(%eax)\n"
        "movl -0x14(%ebp), %edx\n" /* line 245 */
        "movl %edx, 0x1c(%eax)\n"
        "movl -0x40(%ebp), %edx\n" /* line 246 */
        "movl %edx, 0x20(%eax)\n"
        "movl -0x30(%ebp), %edx\n" /* line 247 */
        "movl %edx, 0x24(%eax)\n"
        "movl -0x20(%ebp), %edx\n" /* line 248 */
        "movl %edx, 0x28(%eax)\n"
        "movl -0x10(%ebp), %edx\n" /* line 249 */
        "movl %edx, 0x2c(%eax)\n"
        "movl -0x3c(%ebp), %edx\n" /* line 250 */
        "movl %edx, 0x30(%eax)\n"
        "movl -0x2c(%ebp), %edx\n" /* line 251 */
        "movl %edx, 0x34(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 252 */
        "movl %edx, 0x38(%eax)\n"
        "movl -0xc(%ebp), %edx\n" /* line 253 */
        "movl %edx, 0x3c(%eax)\n"
        /* } scope */
        "leave\n" /* line 254 */
        "retl\n"
    );
}

/* line 259 */
__attribute__((naked))
bool COpenGLMatrix_Inverse(const COpenGLMatrix * _this, COpenGLMatrix *mResult)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 259 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x84, %esp\n"
        /* { scope 1: i, msub3, i */
        "pxor %xmm0, %xmm0\n" /* line 264 */
        "movss %xmm0, -0x84(%ebp)\n" /* mdet */
        "movss 0x2ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x7c(%ebp)\n" /* i */
        "xorl %edi, %edi\n" /* j */
        "movl 8(%ebp), %esi\n" /* this */
        ".Lf254d6_00025500:\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %ebx, %ebx\n" /* jdst */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_00025506:\n"
        "leal (%ecx, %ecx, 2), %eax\n" /* line 98 */
        "leal -0x58(%ebp, %eax, 4), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* pmb */
        "testl %edx, %edx\n"
        "jne .Lf254d6_0002574b\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        "xorl %eax, %eax\n" /* line 278 */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_0002551a:\n"
        "cmpl %edi, %eax\n" /* line 103 */
        "jae .Lf254d6_0002553c\n"
        "movl %eax, %ebx\n" /* jdst */
        ".Lf254d6_00025520:\n"
        "addl $1, %eax\n" /* line 101 */
        "cmpl $4, %eax\n"
        "jne .Lf254d6_0002551a\n"
        /* } scope */
        ".Lf254d6_00025528:\n"
        "leal 1(%edx), %eax\n" /* line 87 */
        "cmpl $4, %eax\n"
        "je .Lf254d6_00025543\n"
        /* { scope 5 */
        "testl %eax, %eax\n" /* line 93 */
        "cmovnel %edx, %ecx\n"
        "addl $0x10, %esi\n"
        "movl %eax, %edx\n"
        "jmp .Lf254d6_00025506\n"
        ".Lf254d6_0002553c:\n"
        "jbe .Lf254d6_00025520\n" /* line 107 */
        "leal -1(%eax), %ebx\n" /* line 101 | jdst */
        "jmp .Lf254d6_00025520\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf254d6_00025543:\n"
        "movss -0x48(%ebp), %xmm5\n" /* line 75 */
        "movss -0x38(%ebp), %xmm1\n"
        "movss -0x3c(%ebp), %xmm3\n"
        "movss -0x44(%ebp), %xmm4\n"
        "movss -0x4c(%ebp), %xmm6\n"
        "movss -0x40(%ebp), %xmm7\n"
        "movaps %xmm5, %xmm0\n" /* line 135 */
        "mulss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "mulss -0x58(%ebp), %xmm0\n" /* msub3 */
        "mulss %xmm6, %xmm1\n"
        "mulss %xmm7, %xmm4\n"
        "subss %xmm4, %xmm1\n"
        "mulss -0x54(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm3\n"
        "mulss %xmm7, %xmm5\n"
        "subss %xmm5, %xmm3\n"
        "mulss -0x50(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "movl 8(%ebp), %edx\n" /* this */
        "mulss (%edx, %edi, 4), %xmm0\n"
        "mulss -0x7c(%ebp), %xmm0\n" /* i */
        "addss -0x84(%ebp), %xmm0\n" /* mdet */
        "movss %xmm0, -0x84(%ebp)\n" /* mdet */
        "addl $1, %edi\n" /* line 130 */
        "xorl $0x80000000, -0x7c(%ebp)\n" /* i */
        "cmpl $4, %edi\n"
        "je .Lf254d6_000255d5\n"
        "movl %edx, %esi\n"
        "jmp .Lf254d6_00025500\n"
        /* } scope */
        ".Lf254d6_000255d5:\n"
        "andps 0x2ef880, %xmm0\n" /* line 272 */
        "ucomiss 0x2ed618, %xmm0\n" /* 0.0005000000237487257f */
        "jb .Lf254d6_00025738\n"
        ".Lf254d6_000255e9:\n"
        "movl $0, -0x74(%ebp)\n" /* i */
        ".Lf254d6_000255f0:\n"
        "movl -0x74(%ebp), %eax\n" /* i */
        "movl %eax, -0x6c(%ebp)\n"
        "xorl %edi, %edi\n" /* j */
        /* { scope 2 */
        /* { scope 3 */
        "addl %edi, %eax\n" /* line 281 | j */
        "andl $0x80000001, %eax\n"
        "js .Lf254d6_000256f0\n"
        ".Lf254d6_00025605:\n"
        "addl %eax, %eax\n"
        "movl $1, -0x80(%ebp)\n" /* sign */
        "subl %eax, -0x80(%ebp)\n" /* sign */
        "movl 8(%ebp), %ecx\n" /* this */
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n" /* jdst */
        "xorl %edx, %edx\n"
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_0002561a:\n"
        "cmpl %edx, -0x74(%ebp)\n" /* line 89 | i */
        "jbe .Lf254d6_0002570c\n"
        "movl %edx, %ebx\n" /* jdst */
        ".Lf254d6_00025625:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 98 | jdst */
        "leal -0x34(%ebp, %eax, 4), %eax\n"
        "movl %eax, -0x70(%ebp)\n" /* pmb */
        "cmpl %edx, -0x74(%ebp)\n" /* i */
        "jne .Lf254d6_0002577e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        "xorl %eax, %eax\n" /* line 107 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_0002563a:\n"
        "cmpl %edi, %eax\n" /* line 103 */
        "jae .Lf254d6_000256fe\n"
        "movl %eax, %esi\n"
        ".Lf254d6_00025644:\n"
        "addl $1, %eax\n" /* line 101 */
        "cmpl $4, %eax\n"
        "jne .Lf254d6_0002563a\n"
        /* } scope */
        ".Lf254d6_0002564c:\n"
        "addl $1, %edx\n" /* line 87 */
        "addl $0x10, %ecx\n"
        "cmpl $4, %edx\n"
        "jne .Lf254d6_0002561a\n"
        /* } scope */
        "movss -0x24(%ebp), %xmm5\n" /* line 75 */
        "movss -0x14(%ebp), %xmm1\n"
        "movss -0x18(%ebp), %xmm3\n"
        "movss -0x20(%ebp), %xmm4\n"
        "movss -0x28(%ebp), %xmm6\n"
        "movss -0x1c(%ebp), %xmm7\n"
        "movaps %xmm5, %xmm0\n" /* line 283 */
        "mulss %xmm1, %xmm0\n"
        "movaps %xmm3, %xmm2\n"
        "mulss %xmm4, %xmm2\n"
        "subss %xmm2, %xmm0\n"
        "mulss -0x34(%ebp), %xmm0\n" /* mtemp */
        "mulss %xmm6, %xmm1\n"
        "mulss %xmm7, %xmm4\n"
        "subss %xmm4, %xmm1\n"
        "mulss -0x30(%ebp), %xmm1\n"
        "subss %xmm1, %xmm0\n"
        "mulss %xmm6, %xmm3\n"
        "mulss %xmm7, %xmm5\n"
        "subss %xmm5, %xmm3\n"
        "mulss -0x2c(%ebp), %xmm3\n"
        "addss %xmm3, %xmm0\n"
        "cvtsi2ssl -0x80(%ebp), %xmm1\n" /* sign */
        "mulss %xmm1, %xmm0\n"
        "divss -0x84(%ebp), %xmm0\n" /* mdet */
        "movl -0x6c(%ebp), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* mResult */
        "movss %xmm0, (%eax, %edx, 4)\n"
        "addl $1, %edi\n" /* line 279 | j */
        "addl $4, %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "cmpl $4, %edi\n" /* j */
        "je .Lf254d6_0002571a\n"
        "movl -0x74(%ebp), %eax\n" /* i */
        "addl %edi, %eax\n" /* line 281 | j */
        "andl $0x80000001, %eax\n"
        "jns .Lf254d6_00025605\n"
        ".Lf254d6_000256f0:\n"
        "subl $1, %eax\n"
        "orl $0xfffffffe, %eax\n"
        "addl $1, %eax\n"
        "jmp .Lf254d6_00025605\n"
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_000256fe:\n"
        "jbe .Lf254d6_00025644\n" /* line 107 */
        "leal -1(%eax), %esi\n" /* line 101 */
        "jmp .Lf254d6_00025644\n"
        ".Lf254d6_0002570c:\n"
        "leal -1(%edx), %eax\n" /* line 93 */
        "cmpl %edx, -0x74(%ebp)\n" /* i */
        "cmovbl %eax, %ebx\n" /* jdst */
        "jmp .Lf254d6_00025625\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf254d6_0002571a:\n"
        "addl $1, -0x74(%ebp)\n" /* line 278 | i */
        "cmpl $4, -0x74(%ebp)\n" /* i */
        "jne .Lf254d6_000255f0\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x84, %esp\n" /* line 287 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, msub3, i */
        ".Lf254d6_00025738:\n"
        "jp .Lf254d6_000255e9\n" /* line 272 */
        "xorb %al, %al\n"
        /* } scope */
        "addl $0x84, %esp\n" /* line 287 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i, msub3, i */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_0002574b:\n"
        "movl $0, -0x68(%ebp)\n" /* line 98 */
        ".Lf254d6_00025752:\n"
        "cmpl -0x68(%ebp), %edi\n" /* line 103 */
        "ja .Lf254d6_000257b5\n"
        "jae .Lf254d6_000257b1\n" /* line 107 */
        "movl -0x68(%ebp), %ebx\n" /* jdst */
        "subl $1, %ebx\n" /* jdst */
        ".Lf254d6_0002575f:\n"
        "movl -0x68(%ebp), %eax\n" /* line 113 */
        "movss (%esi, %eax, 4), %xmm0\n"
        "movl -0x78(%ebp), %eax\n" /* pmb */
        "movss %xmm0, (%eax, %ebx, 4)\n"
        ".Lf254d6_0002576f:\n"
        "addl $1, -0x68(%ebp)\n" /* line 101 */
        "cmpl $4, -0x68(%ebp)\n"
        "jne .Lf254d6_00025752\n"
        "jmp .Lf254d6_00025528\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_0002577e:\n"
        "movl $0, -0x64(%ebp)\n" /* line 98 */
        ".Lf254d6_00025785:\n"
        "cmpl -0x64(%ebp), %edi\n" /* line 103 */
        "ja .Lf254d6_000257be\n"
        "jae .Lf254d6_000257ba\n" /* line 107 */
        "movl -0x64(%ebp), %esi\n"
        "subl $1, %esi\n"
        ".Lf254d6_00025792:\n"
        "movl -0x64(%ebp), %eax\n" /* line 113 */
        "movss (%ecx, %eax, 4), %xmm0\n"
        "movl -0x70(%ebp), %eax\n" /* pmb */
        "movss %xmm0, (%eax, %esi, 4)\n"
        ".Lf254d6_000257a2:\n"
        "addl $1, -0x64(%ebp)\n" /* line 101 */
        "cmpl $4, -0x64(%ebp)\n"
        "jne .Lf254d6_00025785\n"
        "jmp .Lf254d6_0002564c\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_000257b1:\n"
        "jne .Lf254d6_0002575f\n" /* line 111 */
        "jmp .Lf254d6_0002576f\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4: pmb, pmb */
        /* { scope 5 */
        ".Lf254d6_000257b5:\n"
        "movl -0x68(%ebp), %ebx\n" /* line 107 | jdst */
        "jmp .Lf254d6_0002575f\n"
        ".Lf254d6_000257ba:\n"
        "jne .Lf254d6_00025792\n" /* line 111 */
        "jmp .Lf254d6_000257a2\n"
        ".Lf254d6_000257be:\n"
        "movl -0x64(%ebp), %esi\n" /* line 107 */
        "jmp .Lf254d6_00025792\n"
    );
}

