/* ASM dump from: MacOpenGLUtils.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/MacOpenGLUtils.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

extern UINT32 sD3DTextureOpToOpenGL[15]; /* 0x308360 */
extern UINT8 FastTranslateTbl[8]; /* 0x308340 */
extern UINT32 sDeclarationTable[8]; /* 0x308320 */

bool MacOpenGLUtils_IsGLExtensionSupported(const char * pExtension);
bool MacOpenGLUtils_AreMatricesDifferent4x4(const int * pA, const int * pB);
bool MacOpenGLUtils_IsCompressed(const D3DFORMAT *f);
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f);
int MacOpenGLUtils_GetOpenGLTextureOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp);
int MacOpenGLUtils_GetOpenGLTextureAlphaOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp);
UINT32 MacOpenGLUtils_GetElementCount(GLenum Mode, UINT32 PrimitiveCount);
UINT32 MacOpenGLUtils_GetPCPixelShaderVersion(void);
UINT32 MacOpenGLUtils_GetNumTextureLevels(UINT32 Width, UINT32 Height, UINT32 Depth);
int MacOpenGLUtils_GetDeclarationInfo(GLint *VSize, GLenum *VType, UINT32 *ComponentSize, GLboolean *Normalized, UINT32 Type);
int MacOpenGLUtils_GetSubPixelOffset(float *XOffset, float *YOffset);
int MacOpenGLUtils_GetOpenGLTextureType(bool *CreateOpenGLResources, GLenum *OpenGLInternalFormat, GLenum *OpenGLFormat, GLenum *OpenGLElementType, D3DFORMAT mFormat);
UINT32 MacOpenGLUtils_GetLevelSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, const D3DFORMAT *f);
float MacOpenGLUtils_SquareRootLowPrecision(float fp0);
int MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL(float *m, float ViewportWidth, float ViewportHeight);
UINT32 MacOpenGLUtils_GetImageSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 LevelCount, const D3DFORMAT *f);
int MacDisplay_GetCardType(void);

/* line 104 */
__attribute__((naked))
bool MacOpenGLUtils_IsGLExtensionSupported(const char * pExtension)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 107 | pExtension */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_IsGLExtensionSupported\n"
        "testb %al, %al\n"
        "setne %al\n"
        "movzbl %al, %eax\n"
        "leave\n" /* line 111 */
        "retl\n"
    );
}

/* line 116 */
__attribute__((naked))
bool MacOpenGLUtils_AreMatricesDifferent4x4(const int * pA, const int * pB)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 116 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        /* { scope 1 */
        "movl 8(%ebp), %ecx\n" /* line 122 | pA */
        "subl $4, %ecx\n"
        "movl 0xc(%ebp), %edx\n" /* line 124 | pB */
        "subl $4, %edx\n"
        "movl $4, %esi\n" /* count */
        "xorl %ebx, %ebx\n"
        ".Lf257e0_000257f8:\n"
        "movl 4(%ecx), %eax\n" /* line 131 */
        "xorl 4(%edx), %eax\n"
        "orl %eax, %ebx\n" /* code */
        "movl 8(%ecx), %eax\n" /* line 132 */
        "xorl 8(%edx), %eax\n"
        "orl %eax, %ebx\n" /* code */
        "movl 0xc(%ecx), %eax\n" /* line 133 */
        "xorl 0xc(%edx), %eax\n"
        "orl %eax, %ebx\n" /* code */
        "addl $0x10, %ecx\n" /* line 134 */
        "addl $0x10, %edx\n"
        "movl (%ecx), %eax\n"
        "xorl (%edx), %eax\n"
        "orl %eax, %ebx\n" /* code */
        "subl $1, %esi\n" /* line 129 | count */
        "jne .Lf257e0_000257f8\n"
        "xorl %eax, %eax\n"
        "testl %ebx, %ebx\n" /* code */
        "setne %al\n"
        /* } scope */
        "popl %ebx\n" /* line 139 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 144 */
__attribute__((naked))
bool MacOpenGLUtils_IsCompressed(const D3DFORMAT *f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* line 146 | f */
        "movl (%eax), %eax\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf2582c_0002585d\n"
        "jle .Lf2582c_0002584f\n"
        "cmpl $0x34545844, %eax\n"
        "je .Lf2582c_0002585d\n"
        "cmpl $0x35545844, %eax\n"
        "je .Lf2582c_0002585d\n"
        ".Lf2582c_0002584b:\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n" /* line 198 */
        "retl\n"
        ".Lf2582c_0002584f:\n"
        "cmpl $0x31545844, %eax\n" /* line 146 */
        "je .Lf2582c_0002585d\n"
        "cmpl $0x32545844, %eax\n"
        "jne .Lf2582c_0002584b\n"
        ".Lf2582c_0002585d:\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 198 */
        "retl\n"
    );
}

/* line 203 */
__attribute__((naked))
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 203 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 210 | f */
        "movl (%eax), %eax\n"
        "cmpl $0x3d, %eax\n"
        "jg .Lf25864_0002587d\n"
        "cmpl $0x3c, %eax\n"
        "jl .Lf25864_000258a4\n"
        ".Lf25864_00025876:\n"
        "movl $0x10, %eax\n" /* line 227 */
        /* } scope */
        "popl %ebp\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf25864_0002587d:\n"
        "cmpl $0x4f, %eax\n" /* line 210 */
        "je .Lf25864_000258d2\n"
        "jle .Lf25864_000258c6\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf25864_0002591f\n"
        "jg .Lf25864_0002590b\n"
        "cmpl $0x65, %eax\n"
        "je .Lf25864_00025876\n"
        "cmpl $0x66, %eax\n"
        "je .Lf25864_000258d2\n"
        "cmpl $0x50, %eax\n"
        "je .Lf25864_00025876\n"
        ".Lf25864_000258a0:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf25864_000258a2:\n"
        "popl %ebp\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf25864_000258a4:\n"
        "cmpl $0x1c, %eax\n" /* line 210 */
        "jle .Lf25864_000258d9\n"
        "cmpl $0x29, %eax\n"
        "je .Lf25864_000258bf\n"
        "jle .Lf25864_00025926\n"
        "cmpl $0x33, %eax\n"
        "je .Lf25864_00025876\n"
        "cmpl $0x34, %eax\n"
        "je .Lf25864_000258bf\n"
        "cmpl $0x32, %eax\n"
        "jne .Lf25864_000258a0\n"
        ".Lf25864_000258bf:\n"
        "movl $8, %eax\n" /* line 244 */
        /* } scope */
        "popl %ebp\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf25864_000258c6:\n"
        "cmpl $0x47, %eax\n" /* line 210 */
        "je .Lf25864_000258d2\n"
        "jg .Lf25864_000258f4\n"
        "cmpl $0x40, %eax\n"
        "jg .Lf25864_0002593f\n"
        ".Lf25864_000258d2:\n"
        "movl $0x20, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf25864_000258d9:\n"
        "cmpl $0x1b, %eax\n" /* line 210 */
        "jge .Lf25864_000258bf\n"
        "cmpl $0x16, %eax\n"
        "jg .Lf25864_00025876\n"
        "cmpl $0x15, %eax\n"
        "jge .Lf25864_000258d2\n"
        "cmpl $0x14, %eax\n"
        "jne .Lf25864_000258a0\n"
        "movl $0x18, %eax\n" /* line 223 */
        /* } scope */
        "popl %ebp\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf25864_000258f4:\n"
        "cmpl $0x4b, %eax\n" /* line 210 */
        "je .Lf25864_000258d2\n"
        "cmpl $0x4d, %eax\n"
        "je .Lf25864_000258d2\n"
        "cmpl $0x49, %eax\n"
        "je .Lf25864_00025876\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25864_000258a2\n"
        ".Lf25864_0002590b:\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf25864_000258bf\n"
        "jg .Lf25864_0002594f\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf25864_000258bf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25864_000258a2\n"
        ".Lf25864_0002591f:\n"
        "movl $4, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf25864_00025926:\n"
        "cmpl $0x1e, %eax\n" /* line 210 */
        "jle .Lf25864_00025876\n"
        "cmpl $0x28, %eax\n"
        "je .Lf25864_00025876\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25864_000258a2\n"
        ".Lf25864_0002593f:\n"
        "cmpl $0x46, %eax\n"
        "je .Lf25864_00025876\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25864_000258a2\n"
        ".Lf25864_0002594f:\n"
        "cmpl $0x34545844, %eax\n"
        "je .Lf25864_000258bf\n"
        "cmpl $0x35545844, %eax\n"
        "je .Lf25864_000258bf\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25864_000258a2\n"
    );
}

/* line 367 */
__attribute__((naked))
int MacOpenGLUtils_GetOpenGLTextureOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 367 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %ebx\n" /* Params */
        "movl 0x10(%ebp), %ecx\n" /* D3DTextureOp */
        "movl %ecx, %eax\n" /* line 371 */
        "andl $0xf, %eax\n"
        "movl sD3DTextureOpToOpenGL(, %eax, 4), %edx\n"
        "movl 8(%ebp), %eax\n" /* Source */
        "movl %edx, (%eax)\n"
        "movl %ecx, %eax\n" /* line 374 */
        "shrl $4, %eax\n"
        "movl %eax, %edx\n"
        "andb $1, %dl\n"
        "cmpb $1, %dl\n"
        "sbbl %eax, %eax\n"
        "addl $0x301, %eax\n"
        "movl %eax, (%ebx)\n" /* Params */
        "andb $0x20, %cl\n" /* line 376 */
        "je .Lf2596c_000259ae\n"
        "cmpb $1, %dl\n" /* line 378 */
        "sbbl %eax, %eax\n"
        "addl $0x303, %eax\n"
        "movl %eax, (%ebx)\n" /* Params */
        ".Lf2596c_000259ae:\n"
        "popl %ebx\n" /* line 380 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 385 */
__attribute__((naked))
int MacOpenGLUtils_GetOpenGLTextureAlphaOp(GLenum *Source, GLenum *Params, UINT32 D3DTextureOp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 385 */
        "movl %esp, %ebp\n"
        "movl 0x10(%ebp), %edx\n" /* D3DTextureOp, Params */
        "movl %edx, %eax\n" /* line 389 */
        "andl $0xf, %eax\n"
        "movl sD3DTextureOpToOpenGL(, %eax, 4), %ecx\n"
        "movl 8(%ebp), %eax\n" /* Source */
        "movl %ecx, (%eax)\n"
        "andl $0x10, %edx\n" /* line 391 */
        "cmpl $1, %edx\n"
        "sbbl %eax, %eax\n"
        "addl $0x303, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* Params */
        "movl %eax, (%edx)\n"
        "popl %ebp\n" /* line 394 */
        "retl\n"
    );
}

/* line 433 */
__attribute__((naked))
UINT32 MacOpenGLUtils_GetElementCount(GLenum Mode, UINT32 PrimitiveCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 433 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 439 | Mode */
        "movzbl FastTranslateTbl(%eax), %edx\n" /* MultAdd */
        "movl %edx, %eax\n" /* MultAdd */
        "shrl $4, %eax\n"
        "imull 0xc(%ebp), %eax\n" /* PrimitiveCount */
        "andl $0xf, %edx\n" /* MultAdd */
        "addl %edx, %eax\n" /* MultAdd */
        /* } scope */
        "popl %ebp\n" /* line 442 */
        "retl\n"
    );
}

/* line 496 */
__attribute__((naked))
UINT32 MacOpenGLUtils_GetPCPixelShaderVersion(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 496 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 505 */
        "jmp MacDisplay_GetPCPixelShaderVersion\n" /* line 501 */
    );
}

/* line 510 */
__attribute__((naked))
UINT32 MacOpenGLUtils_GetNumTextureLevels(UINT32 Width, UINT32 Height, UINT32 Depth)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 510 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* Width */
        "movl 0xc(%ebp), %edx\n" /* Height */
        "movl 0x10(%ebp), %ecx\n" /* Depth */
        "xorl %esi, %esi\n"
        "jmp .Lf25a0a_00025a2e\n"
        /* { scope 1 */
        ".Lf25a0a_00025a1c:\n"
        "testl %edx, %edx\n" /* line 516 */
        "je .Lf25a0a_00025a3c\n"
        "shrl $1, %edx\n"
        ".Lf25a0a_00025a22:\n"
        "movl %ecx, %eax\n" /* line 527 */
        "shrl $1, %eax\n"
        "testl %ecx, %ecx\n"
        "cmovnel %eax, %ecx\n"
        "addl $1, %esi\n" /* line 516 | ActualLevels */
        ".Lf25a0a_00025a2e:\n"
        "testl %ebx, %ebx\n" /* TempWidth */
        "je .Lf25a0a_00025a1c\n"
        "testl %edx, %edx\n" /* line 523 */
        "je .Lf25a0a_00025a45\n"
        "shrl $1, %ebx\n" /* TempWidth */
        "shrl $1, %edx\n"
        "jmp .Lf25a0a_00025a22\n"
        ".Lf25a0a_00025a3c:\n"
        "testl %ecx, %ecx\n" /* line 516 */
        "je .Lf25a0a_00025a4b\n"
        "movl $1, %ebx\n" /* line 523 | TempWidth */
        ".Lf25a0a_00025a45:\n"
        "shrl $1, %ebx\n" /* TempWidth */
        "xorl %edx, %edx\n"
        "jmp .Lf25a0a_00025a22\n"
        /* } scope */
        ".Lf25a0a_00025a4b:\n"
        "movl %esi, %eax\n" /* line 534 | ActualLevels */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 552 */
__attribute__((naked))
int MacOpenGLUtils_GetDeclarationInfo(GLint *VSize, GLenum *VType, UINT32 *ComponentSize, GLboolean *Normalized, UINT32 Type)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 552 */
        "movl %esp, %ebp\n"
        /* { scope 1 */
        "movl 0x18(%ebp), %eax\n" /* line 556 | Type */
        "movl sDeclarationTable(, %eax, 4), %ecx\n" /* DeclarationInfo */
        "movl %ecx, %edx\n" /* line 558 */
        "shrl $0x1c, %edx\n"
        "movl 8(%ebp), %eax\n" /* VSize */
        "movl %edx, (%eax)\n"
        "movl %ecx, %eax\n" /* line 559 */
        "shrl $0xc, %eax\n"
        "andl $0xffff, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* VType */
        "movl %eax, (%edx)\n"
        "movl %ecx, %eax\n" /* line 560 */
        "shrl $4, %eax\n"
        "andl $0xf, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* ComponentSize */
        "movl %eax, (%edx)\n"
        "andl $1, %ecx\n" /* line 561 */
        "movl 0x14(%ebp), %eax\n" /* Normalized */
        "movb %cl, (%eax)\n"
        /* } scope */
        "popl %ebp\n" /* line 562 */
        "retl\n"
    );
}

/* line 584 */
__attribute__((naked))
int MacOpenGLUtils_GetSubPixelOffset(float *XOffset, float *YOffset)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 584 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* XOffset */
        "movl 0xc(%ebp), %esi\n" /* YOffset */
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 587 */
        "je .Lf25a92_00025ab7\n"
        "movl $0xbe19999a, (%ebx)\n" /* line 594 | XOffset */
        "movl $0xbd99999a, (%esi)\n" /* line 595 | YOffset */
        "popl %ebx\n" /* line 618 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf25a92_00025ab7:\n"
        "movl $0xbe99999a, %eax\n" /* line 589 */
        "movl %eax, (%ebx)\n" /* XOffset */
        "movl %eax, (%esi)\n" /* line 590 | YOffset */
        "popl %ebx\n" /* line 618 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 629 */
__attribute__((naked))
int MacOpenGLUtils_GetOpenGLTextureType(bool *CreateOpenGLResources, GLenum *OpenGLInternalFormat, GLenum *OpenGLFormat, GLenum *OpenGLElementType, D3DFORMAT mFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 629 */
        "movl %esp, %ebp\n"
        "movl 0x18(%ebp), %eax\n" /* mFormat */
        "cmpl $0x47, %eax\n" /* line 642 */
        "je .Lf25ac4_00025b57\n"
        "jle .Lf25ac4_00025b05\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf25ac4_00025bc1\n"
        "jle .Lf25ac4_00025b44\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf25ac4_00025b87\n"
        "cmpl $0x35545844, %eax\n"
        "je .Lf25ac4_00025c35\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf25ac4_00025b87\n"
        ".Lf25ac4_00025b03:\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025b05:\n"
        "cmpl $0x17, %eax\n" /* line 642 */
        "je .Lf25ac4_00025ba4\n"
        "jle .Lf25ac4_00025b5f\n"
        "cmpl $0x1a, %eax\n"
        "je .Lf25ac4_00025c18\n"
        "cmpl $0x32, %eax\n"
        "je .Lf25ac4_00025c52\n"
        "cmpl $0x19, %eax\n"
        "jne .Lf25ac4_00025b03\n"
        "movl 0xc(%ebp), %eax\n" /* line 646 | OpenGLInternalFormat */
        "movl $0x8057, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 647 | OpenGLFormat */
        "movl $0x80e1, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 648 | OpenGLElementType */
        "movl $0x8366, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025b44:\n"
        "cmpl $0x4b, %eax\n" /* line 642 */
        "je .Lf25ac4_00025bde\n"
        "cmpl $0x50, %eax\n"
        "je .Lf25ac4_00025b57\n"
        "cmpl $0x49, %eax\n"
        "jne .Lf25ac4_00025b03\n"
        ".Lf25ac4_00025b57:\n"
        "movl 8(%ebp), %eax\n" /* line 720 | CreateOpenGLResources */
        "movb $0, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025b5f:\n"
        "cmpl $0x14, %eax\n" /* line 642 */
        "je .Lf25ac4_00025bfb\n"
        "jl .Lf25ac4_00025b03\n"
        "movl 0xc(%ebp), %eax\n" /* line 675 | OpenGLInternalFormat */
        "movl $0x1908, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 676 | OpenGLFormat */
        "movl $0x80e1, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 678 | OpenGLElementType */
        "movl $0x8035, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025b87:\n"
        "movl 0xc(%ebp), %eax\n" /* line 702 | OpenGLInternalFormat */
        "movl $0x83f2, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 703 | OpenGLElementType */
        "movl $0, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* OpenGLFormat */
        "movl $0, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025ba4:\n"
        "movl 0xc(%ebp), %eax\n" /* line 653 | OpenGLInternalFormat */
        "movl $0x1907, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 654 | OpenGLFormat */
        "movl $0x1907, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 655 | OpenGLElementType */
        "movl $0x8363, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025bc1:\n"
        "movl 0xc(%ebp), %eax\n" /* line 691 | OpenGLInternalFormat */
        "movl $0x83f1, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 692 | OpenGLElementType */
        "movl $0, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* OpenGLFormat */
        "movl $0, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025bde:\n"
        "movl 0xc(%ebp), %eax\n" /* line 725 | OpenGLInternalFormat */
        "movl $0x1902, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 726 | OpenGLFormat */
        "movl $0x1902, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 727 | OpenGLElementType */
        "movl $0x1401, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025bfb:\n"
        "movl 0xc(%ebp), %eax\n" /* line 667 | OpenGLInternalFormat */
        "movl $0x1907, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 668 | OpenGLFormat */
        "movl $0x1907, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 669 | OpenGLElementType */
        "movl $0x1401, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025c18:\n"
        "movl 0xc(%ebp), %eax\n" /* line 660 | OpenGLInternalFormat */
        "movl $0x8056, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 661 | OpenGLFormat */
        "movl $0x80e1, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 662 | OpenGLElementType */
        "movl $0x8365, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025c35:\n"
        "movl 0xc(%ebp), %eax\n" /* line 707 | OpenGLInternalFormat */
        "movl $0x83f3, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 708 | OpenGLElementType */
        "movl $0, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* OpenGLFormat */
        "movl $0, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
        ".Lf25ac4_00025c52:\n"
        "movl 0xc(%ebp), %eax\n" /* line 712 | OpenGLInternalFormat */
        "movl $0x1909, (%eax)\n"
        "movl 0x10(%ebp), %eax\n" /* line 713 | OpenGLFormat */
        "movl $0x1909, (%eax)\n"
        "movl 0x14(%ebp), %eax\n" /* line 714 | OpenGLElementType */
        "movl $0x1401, (%eax)\n"
        "popl %ebp\n" /* line 732 */
        "retl\n"
    );
}

/* line 277 */
__attribute__((naked))
UINT32 MacOpenGLUtils_GetLevelSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, const D3DFORMAT *f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 277 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* Width */
        "movl 0xc(%ebp), %ebx\n" /* Height */
        "movl 0x10(%ebp), %ecx\n" /* Depth */
        /* { scope 1 */
        "movl $1, %eax\n" /* line 285 */
        "testl %edx, %edx\n"
        "cmovel %eax, %edx\n"
        "testl %ebx, %ebx\n" /* line 289 | Height */
        "cmovel %eax, %ebx\n" /* Height */
        "testl %ecx, %ecx\n" /* line 293 */
        "cmovel %eax, %ecx\n"
        "movl 0x14(%ebp), %eax\n" /* line 146 | f */
        "movl (%eax), %eax\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf25c72_00025cf6\n"
        "jle .Lf25c72_00025ce8\n"
        "cmpl $0x34545844, %eax\n"
        "je .Lf25c72_00025cf6\n"
        "cmpl $0x35545844, %eax\n"
        "je .Lf25c72_00025cf6\n"
        ".Lf25c72_00025cb0:\n"
        "imull %ebx, %edx\n" /* line 306 | Height */
        "imull %ecx, %edx\n"
        "cmpl $0x3d, %eax\n" /* line 210 */
        "jle .Lf25c72_00025d1d\n"
        "cmpl $0x4f, %eax\n"
        "je .Lf25c72_00025d46\n"
        "jg .Lf25c72_00025d57\n"
        "cmpl $0x47, %eax\n"
        "je .Lf25c72_00025d46\n"
        "jg .Lf25c72_00025de4\n"
        "cmpl $0x40, %eax\n"
        "jle .Lf25c72_00025d46\n"
        "cmpl $0x46, %eax\n"
        "je .Lf25c72_00025d3c\n"
        ".Lf25c72_00025cdf:\n"
        "xorl %eax, %eax\n"
        ".Lf25c72_00025ce1:\n"
        "shrl $3, %eax\n" /* line 306 */
        /* } scope */
        ".Lf25c72_00025ce4:\n"
        "popl %ebx\n" /* line 310 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf25c72_00025ce8:\n"
        "cmpl $0x31545844, %eax\n" /* line 146 */
        "je .Lf25c72_00025d50\n"
        "cmpl $0x32545844, %eax\n"
        "jne .Lf25c72_00025cb0\n"
        /* { scope 2 */
        ".Lf25c72_00025cf6:\n"
        "cmpl $0x31545844, %eax\n" /* line 300 */
        "je .Lf25c72_00025d50\n"
        "movl $0x10, %esi\n" /* BlockSize */
        ".Lf25c72_00025d02:\n"
        "addl $3, %edx\n" /* line 302 */
        "shrl $2, %edx\n"
        "leal 3(%ebx), %eax\n" /* Height */
        "shrl $2, %eax\n"
        "imull %eax, %edx\n"
        "imull %edx, %ecx\n"
        "movl %esi, %eax\n" /* BlockSize */
        "imull %ecx, %eax\n"
        /* } scope */
        /* } scope */
        "popl %ebx\n" /* line 310 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf25c72_00025d1d:\n"
        "cmpl $0x3c, %eax\n" /* line 210 */
        "jge .Lf25c72_00025d3c\n"
        "cmpl $0x1c, %eax\n"
        "jle .Lf25c72_00025d76\n"
        "cmpl $0x29, %eax\n"
        "je .Lf25c72_00025dbe\n"
        "jg .Lf25c72_00025dab\n"
        "cmpl $0x1e, %eax\n"
        "jle .Lf25c72_00025d3c\n"
        "cmpl $0x28, %eax\n"
        "jne .Lf25c72_00025cdf\n"
        /* { scope 2 */
        ".Lf25c72_00025d3c:\n"
        "movl %edx, %eax\n" /* line 227 */
        "shll $4, %eax\n"
        /* } scope */
        "shrl $3, %eax\n" /* line 306 */
        "jmp .Lf25c72_00025ce4\n"
        /* { scope 2 */
        ".Lf25c72_00025d46:\n"
        "movl %edx, %eax\n" /* line 302 */
        "shll $5, %eax\n"
        /* } scope */
        "shrl $3, %eax\n" /* line 306 */
        "jmp .Lf25c72_00025ce4\n"
        ".Lf25c72_00025d50:\n"
        "movl $8, %esi\n" /* line 210 */
        "jmp .Lf25c72_00025d02\n"
        ".Lf25c72_00025d57:\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf25c72_00025d9c\n"
        "jg .Lf25c72_00025dcd\n"
        "cmpl $0x65, %eax\n"
        "je .Lf25c72_00025d3c\n"
        "cmpl $0x66, %eax\n"
        "je .Lf25c72_00025d46\n"
        "cmpl $0x50, %eax\n"
        "je .Lf25c72_00025d3c\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25c72_00025ce1\n"
        ".Lf25c72_00025d76:\n"
        "cmpl $0x1b, %eax\n"
        "jge .Lf25c72_00025dbe\n"
        "cmpl $0x16, %eax\n"
        "jg .Lf25c72_00025d3c\n"
        "cmpl $0x15, %eax\n"
        "jge .Lf25c72_00025d46\n"
        "cmpl $0x14, %eax\n"
        "jne .Lf25c72_00025cdf\n"
        /* { scope 2 */
        "leal (%edx, %edx, 2), %eax\n" /* line 223 */
        "shll $3, %eax\n"
        /* } scope */
        "shrl $3, %eax\n" /* line 306 */
        "jmp .Lf25c72_00025ce4\n"
        /* { scope 2 */
        ".Lf25c72_00025d9c:\n"
        "leal (, %edx, 4), %eax\n" /* line 256 */
        /* } scope */
        "shrl $3, %eax\n" /* line 306 */
        "jmp .Lf25c72_00025ce4\n"
        ".Lf25c72_00025dab:\n"
        "cmpl $0x33, %eax\n" /* line 210 */
        "je .Lf25c72_00025d3c\n"
        "cmpl $0x34, %eax\n"
        "je .Lf25c72_00025dbe\n"
        "cmpl $0x32, %eax\n"
        "jne .Lf25c72_00025cdf\n"
        /* { scope 2 */
        ".Lf25c72_00025dbe:\n"
        "leal (, %edx, 8), %eax\n" /* line 244 */
        /* } scope */
        "shrl $3, %eax\n" /* line 306 */
        "jmp .Lf25c72_00025ce4\n"
        ".Lf25c72_00025dcd:\n"
        "cmpl $0x33545844, %eax\n" /* line 210 */
        "je .Lf25c72_00025dbe\n"
        "jg .Lf25c72_00025e06\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf25c72_00025dbe\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25c72_00025ce1\n"
        ".Lf25c72_00025de4:\n"
        "cmpl $0x4b, %eax\n"
        "je .Lf25c72_00025d46\n"
        "cmpl $0x4d, %eax\n"
        "je .Lf25c72_00025d46\n"
        "cmpl $0x49, %eax\n"
        "je .Lf25c72_00025d3c\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25c72_00025ce1\n"
        ".Lf25c72_00025e06:\n"
        "cmpl $0x34545844, %eax\n"
        "je .Lf25c72_00025dbe\n"
        "cmpl $0x35545844, %eax\n"
        "je .Lf25c72_00025dbe\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25c72_00025ce1\n"
    );
}

/* line 95 */
__attribute__((naked))
float MacOpenGLUtils_SquareRootLowPrecision(float fp0)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movss 8(%ebp), %xmm3\n" /* fp0 */
        "movss %xmm3, -4(%ebp)\n" /* fp0 */
        /* { scope 1: i */
        /* { scope 2 */
        "movl -4(%ebp), %edx\n" /* line 85 | fp0 */
        "sarl $1, %edx\n"
        "movl $0x5f375a86, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, -8(%ebp)\n" /* i */
        "movss -8(%ebp), %xmm2\n" /* line 86 | i */
        "movaps %xmm3, %xmm1\n"
        "mulss 0x2ed5d8, %xmm1\n" /* 0.5f */
        "mulss %xmm2, %xmm1\n"
        "mulss %xmm2, %xmm1\n"
        "movss 0x2ed600, %xmm0\n" /* 1.5f */
        "subss %xmm1, %xmm0\n"
        "mulss %xmm0, %xmm2\n"
        "mulss %xmm2, %xmm3\n"
        /* } scope */
        /* } scope */
        "movss %xmm3, -0x14(%ebp)\n" /* line 99 */
        "flds -0x14(%ebp)\n"
        "leave\n"
        "retl\n"
    );
}

/* line 737 */
int MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL(float *m, float ViewportWidth, float ViewportHeight)
{
    float x;
    float y;

    if (MacDisplay_GetCardType() == 2) {
        x = -0.30000001192092896f;
        y = -0.30000001192092896f;
    } else {
        x = -0.15000000596046448f;
        y = -0.07500000298023224f;
    }

    x /= ViewportWidth;
    y /= ViewportHeight;

    m[0] += x * m[3];
    m[1] += y * m[3];
    m[2] = 2.0f * m[2] - m[3];

    m[4] += x * m[7];
    m[5] += y * m[7];
    m[6] = 2.0f * m[6] - m[7];

    m[8] = -(m[8] + x * m[11]);
    m[9] = -(m[9] + y * m[11]);
    m[10] = m[11] - 2.0f * m[10];
    m[11] = -m[11];

    m[12] += x * m[15];
    m[13] += y * m[15];
    m[14] = 2.0f * m[14] - m[15];

    return 0;
}

/* line 315 */
__attribute__((naked))
UINT32 MacOpenGLUtils_GetImageSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 LevelCount, const D3DFORMAT *f)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 315 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %edx\n" /* Width */
        "movl 0xc(%ebp), %ebx\n" /* Height */
        "movl 0x10(%ebp), %ecx\n" /* Depth */
        /* { scope 1: Level */
        /* { scope 2 */
        "movl 0x14(%ebp), %esi\n" /* line 321 | LevelCount, BlockSize */
        "testl %esi, %esi\n" /* BlockSize */
        "jne .Lf25fae_00025fd9\n"
        "movl $0, -0x1c(%ebp)\n" /* ImageSizeInBytes */
        /* } scope */
        /* } scope */
        ".Lf25fae_00025fce:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 343 | ImageSizeInBytes */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Level */
        /* { scope 2 */
        ".Lf25fae_00025fd9:\n"
        "movl $0, -0x18(%ebp)\n" /* line 321 | Level */
        "movl $0, -0x1c(%ebp)\n" /* ImageSizeInBytes */
        "testl %edx, %edx\n"
        "jne .Lf25fae_00026096\n"
        ".Lf25fae_00025fef:\n"
        "testl %ebx, %ebx\n" /* Height */
        "je .Lf25fae_00026104\n"
        "movl %ebx, %esi\n" /* Height, BlockSize */
        "shrl $1, %esi\n" /* BlockSize */
        "movl %esi, -0x14(%ebp)\n" /* BlockSize */
        "movb $1, %dl\n"
        "xorl %edi, %edi\n"
        ".Lf25fae_00026002:\n"
        "testl %ecx, %ecx\n" /* line 332 */
        "jne .Lf25fae_000260ad\n"
        ".Lf25fae_0002600a:\n"
        "movb $1, %cl\n"
        "movl $0, -0x10(%ebp)\n"
        /* { scope 3 */
        "movl $1, %eax\n" /* line 285 */
        "testl %edx, %edx\n"
        "cmovel %eax, %edx\n"
        "testl %ebx, %ebx\n" /* line 289 */
        "cmovel %eax, %ebx\n"
        "testl %ecx, %ecx\n" /* line 293 */
        "cmovel %eax, %ecx\n"
        "movl 0x18(%ebp), %esi\n" /* line 146 | f */
        "movl (%esi), %eax\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf25fae_000260d8\n"
        ".Lf25fae_00026037:\n"
        "jg .Lf25fae_00026126\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf25fae_000261c0\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf25fae_000260d8\n"
        "imull %ebx, %edx\n" /* line 306 */
        "imull %ecx, %edx\n"
        "cmpl $0x3d, %eax\n" /* line 210 */
        "jg .Lf25fae_00026143\n"
        ".Lf25fae_00026062:\n"
        "cmpl $0x3c, %eax\n"
        "jl .Lf25fae_00026179\n"
        /* { scope 4 */
        ".Lf25fae_0002606b:\n"
        "movl %edx, %eax\n" /* line 227 */
        "shll $4, %eax\n"
        /* } scope */
        ".Lf25fae_00026070:\n"
        "shrl $3, %eax\n" /* line 306 */
        /* } scope */
        ".Lf25fae_00026073:\n"
        "addl %eax, -0x1c(%ebp)\n" /* line 336 | ImageSizeInBytes */
        "addl $1, -0x18(%ebp)\n" /* line 321 | Level */
        "movl -0x18(%ebp), %eax\n" /* Level */
        "cmpl %eax, 0x14(%ebp)\n" /* LevelCount */
        "je .Lf25fae_00025fce\n"
        "movl %edi, %edx\n"
        "movl -0x14(%ebp), %ebx\n" /* Height */
        "movl -0x10(%ebp), %ecx\n"
        "testl %edx, %edx\n"
        "je .Lf25fae_00025fef\n"
        ".Lf25fae_00026096:\n"
        "testl %ebx, %ebx\n" /* line 328 | Height */
        "je .Lf25fae_00026111\n"
        "movl %edx, %edi\n"
        "shrl $1, %edi\n"
        "movl %ebx, %eax\n" /* Height */
        "shrl $1, %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "testl %ecx, %ecx\n" /* line 332 */
        "je .Lf25fae_0002600a\n"
        ".Lf25fae_000260ad:\n"
        "movl %ecx, %esi\n" /* BlockSize */
        "shrl $1, %esi\n" /* BlockSize */
        "movl %esi, -0x10(%ebp)\n" /* BlockSize */
        /* { scope 3 */
        "movl $1, %eax\n" /* line 285 */
        "testl %edx, %edx\n"
        "cmovel %eax, %edx\n"
        "testl %ebx, %ebx\n" /* line 289 */
        "cmovel %eax, %ebx\n"
        "testl %ecx, %ecx\n" /* line 293 */
        "cmovel %eax, %ecx\n"
        "movl 0x18(%ebp), %esi\n" /* line 146 | f */
        "movl (%esi), %eax\n"
        "cmpl $0x33545844, %eax\n"
        "jne .Lf25fae_00026037\n"
        /* { scope 4 */
        ".Lf25fae_000260d8:\n"
        "cmpl $0x31545844, %eax\n" /* line 300 */
        "je .Lf25fae_000261c0\n"
        "movl $0x10, %esi\n" /* BlockSize */
        ".Lf25fae_000260e8:\n"
        "addl $3, %edx\n" /* line 302 */
        "shrl $2, %edx\n"
        "leal 3(%ebx), %eax\n"
        "shrl $2, %eax\n"
        "imull %eax, %edx\n"
        "imull %edx, %ecx\n"
        "movl %esi, %eax\n" /* BlockSize */
        "imull %ecx, %eax\n"
        "jmp .Lf25fae_00026073\n"
        /* } scope */
        /* } scope */
        ".Lf25fae_00026104:\n"
        "testl %ecx, %ecx\n" /* line 321 */
        "je .Lf25fae_00025fce\n"
        "movl $1, %edx\n" /* line 328 */
        ".Lf25fae_00026111:\n"
        "movl %edx, %edi\n"
        "shrl $1, %edi\n"
        "movl $1, %ebx\n" /* Height */
        "movl $0, -0x14(%ebp)\n"
        "jmp .Lf25fae_00026002\n"
        /* { scope 3 */
        ".Lf25fae_00026126:\n"
        "cmpl $0x34545844, %eax\n" /* line 146 */
        "je .Lf25fae_000260d8\n"
        "cmpl $0x35545844, %eax\n"
        "je .Lf25fae_000260d8\n"
        "imull %ebx, %edx\n" /* line 306 */
        "imull %ecx, %edx\n"
        "cmpl $0x3d, %eax\n" /* line 210 */
        "jle .Lf25fae_00026062\n"
        ".Lf25fae_00026143:\n"
        "cmpl $0x4f, %eax\n"
        "je .Lf25fae_000261b6\n"
        "jle .Lf25fae_000261a6\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf25fae_000261ed\n"
        "jg .Lf25fae_000261f9\n"
        "cmpl $0x65, %eax\n"
        "je .Lf25fae_0002606b\n"
        "cmpl $0x66, %eax\n"
        "je .Lf25fae_000261b6\n"
        "cmpl $0x50, %eax\n"
        "je .Lf25fae_0002606b\n"
        ".Lf25fae_00026172:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25fae_00026070\n"
        ".Lf25fae_00026179:\n"
        "cmpl $0x1c, %eax\n"
        "jle .Lf25fae_000261ca\n"
        "cmpl $0x29, %eax\n"
        "je .Lf25fae_00026214\n"
        "jg .Lf25fae_0002623a\n"
        "cmpl $0x1e, %eax\n"
        "jle .Lf25fae_0002606b\n"
        "cmpl $0x28, %eax\n"
        "je .Lf25fae_0002606b\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25fae_00026070\n"
        ".Lf25fae_000261a6:\n"
        "cmpl $0x47, %eax\n"
        "je .Lf25fae_000261b6\n"
        "jg .Lf25fae_00026220\n"
        "cmpl $0x40, %eax\n"
        "jg .Lf25fae_00026254\n"
        /* { scope 4 */
        ".Lf25fae_000261b6:\n"
        "movl %edx, %eax\n" /* line 302 */
        "shll $5, %eax\n"
        "jmp .Lf25fae_00026070\n"
        /* } scope */
        ".Lf25fae_000261c0:\n"
        "movl $8, %esi\n" /* line 210 */
        "jmp .Lf25fae_000260e8\n"
        ".Lf25fae_000261ca:\n"
        "cmpl $0x1b, %eax\n"
        "jge .Lf25fae_00026214\n"
        "cmpl $0x16, %eax\n"
        "jg .Lf25fae_0002606b\n"
        "cmpl $0x15, %eax\n"
        "jge .Lf25fae_000261b6\n"
        "cmpl $0x14, %eax\n"
        "jne .Lf25fae_00026172\n"
        /* { scope 4 */
        "leal (%edx, %edx, 2), %eax\n" /* line 223 */
        "shll $3, %eax\n"
        "jmp .Lf25fae_00026070\n"
        ".Lf25fae_000261ed:\n"
        "leal (, %edx, 4), %eax\n" /* line 256 */
        "jmp .Lf25fae_00026070\n"
        /* } scope */
        ".Lf25fae_000261f9:\n"
        "cmpl $0x33545844, %eax\n" /* line 210 */
        "je .Lf25fae_00026214\n"
        "jle .Lf25fae_00026264\n"
        "cmpl $0x34545844, %eax\n"
        "je .Lf25fae_00026214\n"
        "cmpl $0x35545844, %eax\n"
        "jne .Lf25fae_00026172\n"
        /* { scope 4 */
        ".Lf25fae_00026214:\n"
        "leal (, %edx, 8), %eax\n" /* line 244 */
        "jmp .Lf25fae_00026070\n"
        /* } scope */
        ".Lf25fae_00026220:\n"
        "cmpl $0x4b, %eax\n" /* line 210 */
        "je .Lf25fae_000261b6\n"
        "cmpl $0x4d, %eax\n"
        "je .Lf25fae_000261b6\n"
        "cmpl $0x49, %eax\n"
        "je .Lf25fae_0002606b\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25fae_00026070\n"
        ".Lf25fae_0002623a:\n"
        "cmpl $0x33, %eax\n"
        "je .Lf25fae_0002606b\n"
        "cmpl $0x34, %eax\n"
        "je .Lf25fae_00026214\n"
        "cmpl $0x32, %eax\n"
        "je .Lf25fae_00026214\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25fae_00026070\n"
        ".Lf25fae_00026254:\n"
        "cmpl $0x46, %eax\n"
        "je .Lf25fae_0002606b\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25fae_00026070\n"
        ".Lf25fae_00026264:\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf25fae_00026214\n"
        "xorl %eax, %eax\n"
        "jmp .Lf25fae_00026070\n"
    );
}
