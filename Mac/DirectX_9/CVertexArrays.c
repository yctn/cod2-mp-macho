/* ASM dump from: CVertexArrays.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CVertexArrays.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CVertexArrays.h"
 */

void CBaseVA_CBaseVA(const CBaseVA * _this);
void CBaseVA_Reset(const CBaseVA * _this);
void CBaseVA_Enable(const CBaseVA * _this, GLenum VA);
void CBaseVA_Disable(const CBaseVA * _this, GLenum VA);
void CTexCoordArray_SetGuard(const CTexCoordArray * _this, int vEnable);
void CBaseVA_Force(const CBaseVA * _this);
void CColorArray_Set(const CColorArray * _this, GLenum Type, GLsizei Stride, const void * Pointer, GLint Size);
void CColorArray_SetGuard(const CColorArray * _this, int vEnable, GLenum Type, GLsizei Stride, const void * Pointer, GLint Size);
void CNormalArray_Set(const CNormalArray * _this, GLenum Type, GLsizei Stride, const void * Pointer);
void CNormalArray_SetGuard(const CNormalArray * _this, int vEnable, GLenum Type, GLsizei Stride, const void * Pointer);
void CVertexArray_Set(const CVertexArray * _this, GLenum Type, GLsizei Stride, const void *Pointer, GLint Size);
void CVertexArray_SetGuard(const CVertexArray * _this, int vEnable, GLenum Type, GLsizei Stride, const void * Pointer, GLint Size);
void CTexCoordArray_Set(const CTexCoordArray * _this, GLenum Type, GLsizei Stride, const void *Pointer, GLint Size);

/* line 14 */
__attribute__((naked))
void CBaseVA_CBaseVA(const CBaseVA * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 14 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 20 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movb $0, 4(%eax)\n"
        "movb $1, 5(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0x1406, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "popl %ebp\n" /* line 21 */
        "retl\n"
    );
}

/* line 26 */
__attribute__((naked))
void CBaseVA_Reset(const CBaseVA * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 26 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movb $0, 4(%eax)\n" /* line 28 */
        "movb $1, 5(%eax)\n" /* line 29 */
        "movl $0, 8(%eax)\n" /* line 30 */
        "movl $0x1406, 0xc(%eax)\n" /* line 31 */
        "movl $0, 0x10(%eax)\n" /* line 32 */
        "movl $0, 0x14(%eax)\n" /* line 33 */
        "popl %ebp\n" /* line 34 */
        "retl\n"
    );
}

/* line 68 */
__attribute__((naked))
void CBaseVA_Enable(const CBaseVA * _this, GLenum VA)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 70 | this */
        "movb $1, 4(%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 71 | VA */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 73 */
        "jmp glEnableClientState\n" /* line 71 */
    );
}

/* line 78 */
__attribute__((naked))
void CBaseVA_Disable(const CBaseVA * _this, GLenum VA)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 78 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 80 | this */
        "movb $0, 4(%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 81 | VA */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 83 */
        "jmp glDisableClientState\n" /* line 81 */
    );
}

/* line 199 */
__attribute__((naked))
void CTexCoordArray_SetGuard(const CTexCoordArray * _this, int vEnable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 199 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 201 | vEnable */
        "movl 8(%ebp), %eax\n" /* this */
        "movb %dl, 4(%eax)\n"
        "popl %ebp\n" /* line 202 */
        "retl\n"
    );
}

/* line 39 */
__attribute__((naked))
void CBaseVA_Force(const CBaseVA * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 39 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 4(%ebx)\n" /* line 42 | this */
        "je .Lf113a02_00113a24\n"
        "movl (%ebx), %eax\n" /* line 44 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *8(%eax)\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        "addl $0x14, %esp\n" /* line 52 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf113a02_00113a24:\n"
        "movl (%ebx), %eax\n" /* line 49 | this */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0xc(%eax)\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        "addl $0x14, %esp\n" /* line 52 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 88 */
__attribute__((naked))
void CColorArray_Set(const CColorArray * _this, GLenum Type, GLsizei Stride, const void * Pointer, GLint Size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Type */
        "movl 0x10(%ebp), %ecx\n" /* Stride */
        "movl 0x14(%ebp), %edx\n" /* Pointer */
        "movl 0x18(%ebp), %ebx\n" /* Size */
        "movl %esi, 0xc(%eax)\n" /* line 59 */
        "movl %ecx, 0x10(%eax)\n" /* line 60 */
        "movl %edx, 0x14(%eax)\n" /* line 61 */
        "movl %ebx, 8(%eax)\n" /* line 62 */
        "movl %edx, 0x14(%ebp)\n" /* line 91 | Pointer */
        "movl %ecx, 0x10(%ebp)\n" /* Stride */
        "movl %esi, 0xc(%ebp)\n" /* Type */
        "movl %ebx, 8(%ebp)\n" /* Size, this */
        "popl %ebx\n" /* line 93 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp glColorPointer\n" /* line 91 */
    );
}

/* line 98 */
__attribute__((naked))
void CColorArray_SetGuard(const CColorArray * _this, int vEnable, GLenum Type, GLsizei Stride, const void * Pointer, GLint Size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 98 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 100 | vEnable */
        "movb %al, 4(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 59 | Type */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 60 | Stride */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 61 | Pointer */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 62 | Size */
        "movl %eax, 8(%edx)\n"
        "popl %ebp\n" /* line 102 */
        "retl\n"
    );
}

/* line 121 */
__attribute__((naked))
void CNormalArray_Set(const CNormalArray * _this, GLenum Type, GLsizei Stride, const void * Pointer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 121 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* Type */
        "movl 0x10(%ebp), %ecx\n" /* Stride */
        "movl 0x14(%ebp), %edx\n" /* Pointer */
        "movl %ebx, 0xc(%eax)\n" /* line 59 */
        "movl %ecx, 0x10(%eax)\n" /* line 60 */
        "movl %edx, 0x14(%eax)\n" /* line 61 */
        "movl $3, 8(%eax)\n" /* line 62 */
        "movl %edx, 0x10(%ebp)\n" /* line 124 | Stride */
        "movl %ecx, 0xc(%ebp)\n" /* Type */
        "movl %ebx, 8(%ebp)\n" /* Type, this */
        "popl %ebx\n" /* line 126 */
        "popl %ebp\n"
        "jmp glNormalPointer\n" /* line 124 */
    );
}

/* line 131 */
__attribute__((naked))
void CNormalArray_SetGuard(const CNormalArray * _this, int vEnable, GLenum Type, GLsizei Stride, const void * Pointer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 131 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 133 | vEnable */
        "movb %al, 4(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 59 | Type */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 60 | Stride */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 61 | Pointer */
        "movl %eax, 0x14(%edx)\n"
        "movl $3, 8(%edx)\n" /* line 62 */
        "popl %ebp\n" /* line 135 */
        "retl\n"
    );
}

/* line 140 */
__attribute__((naked))
void CVertexArray_Set(const CVertexArray * _this, GLenum Type, GLsizei Stride, const void *Pointer, GLint Size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 140 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Type */
        "movl 0x10(%ebp), %ecx\n" /* Stride */
        "movl 0x14(%ebp), %edx\n" /* Pointer */
        "movl 0x18(%ebp), %ebx\n" /* Size */
        "movl %esi, 0xc(%eax)\n" /* line 59 */
        "movl %ecx, 0x10(%eax)\n" /* line 60 */
        "movl %edx, 0x14(%eax)\n" /* line 61 */
        "movl %ebx, 8(%eax)\n" /* line 62 */
        "movl %edx, 0x14(%ebp)\n" /* line 143 | Pointer */
        "movl %ecx, 0x10(%ebp)\n" /* Stride */
        "movl %esi, 0xc(%ebp)\n" /* Type */
        "movl %ebx, 8(%ebp)\n" /* Size, this */
        "popl %ebx\n" /* line 145 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp glVertexPointer\n" /* line 143 */
    );
}

/* line 150 */
__attribute__((naked))
void CVertexArray_SetGuard(const CVertexArray * _this, int vEnable, GLenum Type, GLsizei Stride, const void * Pointer, GLint Size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 150 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 152 | vEnable */
        "movb %al, 4(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 59 | Type */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 60 | Stride */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 61 | Pointer */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 62 | Size */
        "movl %eax, 8(%edx)\n"
        "popl %ebp\n" /* line 154 */
        "retl\n"
    );
}

/* line 180 */
__attribute__((naked))
void CTexCoordArray_Set(const CTexCoordArray * _this, GLenum Type, GLsizei Stride, const void *Pointer, GLint Size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 180 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Type */
        "movl 0x10(%ebp), %ecx\n" /* Stride */
        "movl 0x14(%ebp), %edx\n" /* Pointer */
        "movl 0x18(%ebp), %ebx\n" /* Size */
        "movl %esi, 0xc(%eax)\n" /* line 59 */
        "movl %ecx, 0x10(%eax)\n" /* line 60 */
        "movl %edx, 0x14(%eax)\n" /* line 61 */
        "movl %ebx, 8(%eax)\n" /* line 62 */
        "movl %edx, 0x14(%ebp)\n" /* line 183 | Pointer */
        "movl %ecx, 0x10(%ebp)\n" /* Stride */
        "movl %esi, 0xc(%ebp)\n" /* Type */
        "movl %ebx, 8(%ebp)\n" /* Size, this */
        "popl %ebx\n" /* line 185 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp glTexCoordPointer\n" /* line 183 */
    );
}

/* overload skip: CTexCoordArray_SetGuard (0x113b76) */

