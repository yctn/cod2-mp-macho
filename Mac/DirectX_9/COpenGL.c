/* ASM dump from: COpenGL.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/COpenGL.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CVertexArrays.h"
 *   #include "Mac/DirectX 9/COpenGLVertexProgram.h"
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 *   #include "Mac/Tools/MacFastCopy.h"
 *   #include "Mac/DirectX 9/MacOpenGLMath.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "Mac/DirectX 9/CDirect3DDevice.h"
 */

extern GLint g_VAOID; /* 0x0 */
extern COpenGL COpenGL_sOpenGL; /* 0x0 */
extern UINT32 COpenGL_sFrameCount; /* 0x0 */
extern bool COpenGL_sDrawFlag; /* 0x0 */
extern GLuint COpenGL_sShowTextureID; /* 0x0 */

unsigned int COpenGL_SetColorMaterialEnable(const COpenGL * _this, int Value);
unsigned int COpenGL_SetActiveTexUnit(const COpenGL * _this, UINT32 Unit);
unsigned int COpenGL_SetDither(const COpenGL * _this, int Value);
unsigned int COpenGL_SetBlendEXT(const COpenGL * _this, int ForceValidation, GLenum SrcFactorRGB, GLenum DstFactorRGB, GLenum SrcFactorAlpha, GLenum DstFactorAlpha);
unsigned int COpenGL_SetBlend(const COpenGL * _this, int ForceValidation, GLenum SrcFactorRGB, GLenum DstFactorRGB);
unsigned int COpenGL_SetVertexProgram(const COpenGL * _this, const COpenGLVertexProgram *pOGLVertexProgramInfo);
unsigned int COpenGL_SetVARInfo(const COpenGL * _this, const unsigned int *pVAStart, UINT32 Size);
unsigned int COpenGL_DisableVertexProgramStream(const COpenGL * _this, UINT32 AttribArray);
unsigned int COpenGL_CTexUnit_SetTex(const CTexUnit * _this, GLenum Target, const COpenGLTexture * pOpenGLTexInfo);
unsigned int COpenGL_SetVertexProgramStreamInfo(const COpenGL * _this, UINT32 AttribArray, GLint VSize, GLenum VType, int Normalized, GLsizei Stride, const unsigned int * pStream);
unsigned int COpenGL_CTexUnit_Reset(const CTexUnit * _this, int SupportsAnisotropicFiltering, int SupportsLODBias, int IsProgramableOnly);
unsigned int COpenGL_SetVAO(const COpenGL * _this, const COpenGLVAO *VAO, int IsFixedFunction, int ForceValidation);
unsigned int COpenGL_EnableColorArray(const COpenGL * _this, GLint Size, GLenum Type, GLsizei Stride, const unsigned int * Pointer);
unsigned int COpenGL_DisableColorArray(const COpenGL * _this);
unsigned int COpenGL_EnableNormalArray(const COpenGL * _this, GLenum Type, GLsizei Stride, const unsigned int *Pointer);
unsigned int COpenGL_DisableNormalArray(const COpenGL * _this);
unsigned int COpenGL_EnableVertexArray(const COpenGL * _this, GLint Size, GLenum Type, GLsizei Stride, const unsigned int * Pointer);
unsigned int COpenGL_SetLight(const COpenGL * _this, UINT32 Light, const LightInfoType *Src);
unsigned int COpenGL_EnableTexCoordArray(const COpenGL * _this, UINT32 Unit, GLint Size, GLenum Type, GLsizei Stride, const unsigned int * Pointer);
unsigned int COpenGL_DisableTexCoordArray(const COpenGL * _this, UINT32 Unit);
unsigned int COpenGL_SetTexMatrix(const COpenGL * _this, UINT32 Unit, const float *m);
unsigned int COpenGL_SetTexMatrixIdentity(const COpenGL * _this, UINT32 Unit);
unsigned int COpenGL_Shutdown(const COpenGL * _this);
unsigned int COpenGL_SetTexGenEnable(const COpenGL * _this, UINT32 Unit, int Enable, int EnableReflection, int EnableNormalMap);
unsigned int COpenGL_DisableTexUnit(const COpenGL * _this, UINT32 Unit);
unsigned int COpenGL_ReleaseVAOBinding(const COpenGL * _this, const GLuint * TexID);
unsigned int COpenGL_ReleaseTextureBinding(const COpenGL * _this, const GLuint * TexID);
unsigned int COpenGL_Init(const COpenGL * _this, UINT32 Buffers, UINT32 MaxTextureUnits, UINT32 MaxTextureImageUnits);
void ZN7COpenGLD0Ev(void); /* COpenGL_~COpenGL */
unsigned int COpenGL_COpenGL(const COpenGL * _this);
void ZN7COpenGLD1Ev(void); /* COpenGL_~COpenGL */
static unsigned int __static_initialization_and_destruction_0(void);
static void GLOBAL__D__ZN7COpenGL7sOpenGLE(void); /* global destructors keyed to COpenGL_sOpenGL */
void GLOBAL__I__ZN7COpenGL7sOpenGLE(void); /* global constructors keyed to COpenGL_sOpenGL */
unsigned int COpenGLVertexProgram_COpenGLVertexProgram(const COpenGLVertexProgram * _this, const char * pSrcData);
void ZN20COpenGLVertexProgramD2Ev(void); /* COpenGLVertexProgram_~COpenGLVertexProgram */
void ZN20COpenGLVertexProgramD1Ev(void); /* COpenGLVertexProgram_~COpenGLVertexProgram */
void ZN20COpenGLVertexProgramD0Ev(void); /* COpenGLVertexProgram_~COpenGLVertexProgram */
void ZN7CBaseVAD1Ev(void); /* CBaseVA_~CBaseVA */
void ZN7CBaseVAD0Ev(void); /* CBaseVA_~CBaseVA */
unsigned int CColorArray_Enable(const CColorArray * _this);
unsigned int CColorArray_Disable(const CColorArray * _this);
unsigned int CSecondaryColorArray_Enable(const CSecondaryColorArray * _this);
unsigned int CSecondaryColorArray_Disable(const CSecondaryColorArray * _this);
unsigned int CNormalArray_Enable(const CNormalArray * _this);
unsigned int CNormalArray_Disable(const CNormalArray * _this);
unsigned int CVertexArray_Enable(const CVertexArray * _this);
unsigned int CVertexArray_Disable(const CVertexArray * _this);
unsigned int CTexCoordArray_Enable(const CTexCoordArray * _this);
unsigned int CTexCoordArray_Disable(const CTexCoordArray * _this);
void ZN14CTexCoordArrayD1Ev(void); /* CTexCoordArray_~CTexCoordArray */
void ZN11CColorArrayD0Ev(void); /* CColorArray_~CColorArray */
void ZN11CColorArrayD1Ev(void); /* CColorArray_~CColorArray */
void ZN20CSecondaryColorArrayD0Ev(void); /* CSecondaryColorArray_~CSecondaryColorArray */
void ZN20CSecondaryColorArrayD1Ev(void); /* CSecondaryColorArray_~CSecondaryColorArray */
void ZN12CVertexArrayD0Ev(void); /* CVertexArray_~CVertexArray */
void ZN12CVertexArrayD1Ev(void); /* CVertexArray_~CVertexArray */
void ZN12CNormalArrayD0Ev(void); /* CNormalArray_~CNormalArray */
void ZN12CNormalArrayD1Ev(void); /* CNormalArray_~CNormalArray */
void ZN14CTexCoordArrayD0Ev(void); /* CTexCoordArray_~CTexCoordArray */
void ZNSt4listIPmSaIS0_EE5eraseESt14_List_iteratorIS0_E(void); /* std_list<unsigned long*, std_allocator<unsigned long*> >_erase */
void ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<COpenGL_CTexUnit, std_allocator<COpenGL_CTexUnit> >__M_insert_aux */
void ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void); /* std_vector<COpenGL_CTexUnit, std_allocator<COpenGL_CTexUnit> >_erase */

/* line 316 */
__attribute__((naked))
unsigned int COpenGL_SetColorMaterialEnable(const COpenGL * _this, int Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 316 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Value */
        "cmpb %dl, 0x80e(%ecx)\n" /* line 320 */
        "je .Lf20820_00020855\n"
        "movb %dl, 0x80e(%ecx)\n" /* line 322 */
        "testb %dl, %dl\n" /* line 323 */
        "jne .Lf20820_00020848\n"
        "movl $0xb57, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 325 */
        "jmp glDisable\n" /* line 323 */
        ".Lf20820_00020848:\n"
        "movl $0xb57, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 325 */
        "jmp glEnable\n" /* line 323 */
        ".Lf20820_00020855:\n"
        "popl %ebp\n" /* line 325 */
        "retl\n"
    );
}

/* line 378 */
__attribute__((naked))
unsigned int COpenGL_SetActiveTexUnit(const COpenGL * _this, UINT32 Unit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 378 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* Unit */
        "cmpl %eax, 4(%edx)\n" /* line 382 */
        "je .Lf2085a_00020879\n"
        "movl %eax, 4(%edx)\n" /* line 384 */
        "addl $0x84c0, %eax\n" /* line 385 */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 387 */
        "jmp glActiveTextureARB\n" /* line 385 */
        ".Lf2085a_00020879:\n"
        "popl %ebp\n" /* line 387 */
        "retl\n"
    );
}

/* line 752 */
__attribute__((naked))
unsigned int COpenGL_SetDither(const COpenGL * _this, int Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 752 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Value */
        "cmpb %dl, 0xb8(%ecx)\n" /* line 756 */
        "je .Lf2087c_000208b1\n"
        "movb %dl, 0xb8(%ecx)\n" /* line 758 */
        "testb %dl, %dl\n" /* line 759 */
        "jne .Lf2087c_000208a4\n"
        "movl $0xbd0, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 761 */
        "jmp glDisable\n" /* line 759 */
        ".Lf2087c_000208a4:\n"
        "movl $0xbd0, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 761 */
        "jmp glEnable\n" /* line 759 */
        ".Lf2087c_000208b1:\n"
        "popl %ebp\n" /* line 761 */
        "retl\n"
    );
}

/* line 2430 */
__attribute__((naked))
unsigned int COpenGL_SetBlendEXT(const COpenGL * _this, int ForceValidation, GLenum SrcFactorRGB, GLenum DstFactorRGB, GLenum SrcFactorAlpha, GLenum DstFactorAlpha)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2430 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %ebx\n" /* SrcFactorRGB */
        "movl 0x14(%ebp), %esi\n" /* DstFactorRGB */
        "movl 0x18(%ebp), %ecx\n" /* SrcFactorAlpha */
        "movl 0x1c(%ebp), %edx\n" /* DstFactorAlpha */
        "cmpb $0, 0xc(%ebp)\n" /* line 2432 | ForceValidation */
        "jne .Lf208b6_000208d8\n"
        "cmpl 0x824(%eax), %ebx\n" /* SrcFactorRGB */
        "je .Lf208b6_00020904\n"
        ".Lf208b6_000208d8:\n"
        "movl %ebx, 0x824(%eax)\n" /* line 2434 | SrcFactorRGB */
        "movl %esi, 0x828(%eax)\n" /* line 2435 | DstFactorRGB */
        "movl %ecx, 0x82c(%eax)\n" /* line 2436 */
        "movl %edx, 0x830(%eax)\n" /* line 2437 */
        "movl %edx, 0x14(%ebp)\n" /* line 2438 | DstFactorRGB */
        "movl %ecx, 0x10(%ebp)\n" /* SrcFactorRGB */
        "movl %esi, 0xc(%ebp)\n" /* DstFactorRGB, ForceValidation */
        "movl %ebx, 8(%ebp)\n" /* SrcFactorRGB, this */
        "popl %ebx\n" /* line 2440 */
        "popl %esi\n"
        "popl %ebp\n"
        "jmp glBlendFuncSeparateEXT\n" /* line 2438 */
        ".Lf208b6_00020904:\n"
        "cmpl 0x828(%eax), %esi\n" /* line 2432 | DstFactorRGB */
        "jne .Lf208b6_000208d8\n"
        "cmpl 0x82c(%eax), %ecx\n"
        "jne .Lf208b6_000208d8\n"
        "cmpl 0x830(%eax), %edx\n"
        "jne .Lf208b6_000208d8\n"
        "popl %ebx\n" /* line 2440 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2445 */
__attribute__((naked))
unsigned int COpenGL_SetBlend(const COpenGL * _this, int ForceValidation, GLenum SrcFactorRGB, GLenum DstFactorRGB)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2445 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %ecx\n" /* SrcFactorRGB */
        "movl 0x14(%ebp), %edx\n" /* DstFactorRGB */
        "cmpb $0, 0xc(%ebp)\n" /* line 2447 | ForceValidation */
        "jne .Lf20920_0002093a\n"
        "cmpl 0x824(%eax), %ecx\n"
        "je .Lf20920_00020952\n"
        ".Lf20920_0002093a:\n"
        "movl %ecx, 0x824(%eax)\n" /* line 2449 */
        "movl %edx, 0x828(%eax)\n" /* line 2450 */
        "movl %edx, 0xc(%ebp)\n" /* line 2451 | ForceValidation */
        "movl %ecx, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 2453 */
        "jmp glBlendFunc\n" /* line 2451 */
        ".Lf20920_00020952:\n"
        "cmpl 0x828(%eax), %edx\n" /* line 2447 */
        "jne .Lf20920_0002093a\n"
        "popl %ebp\n" /* line 2453 */
        "retl\n"
    );
}

/* line 2174 */
__attribute__((naked))
unsigned int COpenGL_SetVertexProgram(const COpenGL * _this, const COpenGLVertexProgram *pOGLVertexProgramInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2174 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "incl g_vp_enable_count\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 108 | pOGLVertexProgramInfo */
        "movl 0xc(%eax), %eax\n"
        "cmpl 0x67c(%edx), %eax\n" /* line 2185 */
        "je .Lf2095c_00020986\n"
        "movl %eax, 0x67c(%edx)\n" /* line 112 */
        "movl %eax, 0xc(%ebp)\n" /* line 2188 | pOGLVertexProgramInfo */
        "movl $0x8620, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebp\n" /* line 2191 */
        /* { scope 1 */
        "jmp glBindProgramARB\n" /* line 2188 */
        /* } scope */
        ".Lf2095c_00020986:\n"
        "popl %ebp\n" /* line 2191 */
        "retl\n"
    );
}

/* line 704 */
__attribute__((naked))
unsigned int COpenGL_SetVARInfo(const COpenGL * _this, const unsigned int *pVAStart, UINT32 Size)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 704 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* pVAStart */
        "movl 0x10(%ebp), %ecx\n" /* Size */
        "cmpl %edx, 0xc(%eax)\n" /* line 706 */
        "je .Lf20988_000209b6\n"
        ".Lf20988_00020999:\n"
        "movl %edx, 0xc(%eax)\n" /* line 708 */
        "movl %ecx, 0x10(%eax)\n" /* line 709 */
        "cmpb $0, 0x668(%eax)\n" /* line 710 */
        "jne .Lf20988_000209aa\n"
        "popl %ebp\n" /* line 715 */
        "retl\n"
        ".Lf20988_000209aa:\n"
        "movl %edx, 0xc(%ebp)\n" /* line 712 | pVAStart */
        "movl %ecx, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 715 */
        "jmp glVertexArrayRangeAPPLE\n" /* line 712 */
        ".Lf20988_000209b6:\n"
        "cmpl 0x10(%eax), %ecx\n" /* line 706 */
        "jne .Lf20988_00020999\n"
        "popl %ebp\n" /* line 715 */
        "retl\n"
    );
}

/* line 2249 */
__attribute__((naked))
unsigned int COpenGL_DisableVertexProgramStream(const COpenGL * _this, UINT32 AttribArray)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2249 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %ecx\n" /* AttribArray */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 110 | this */
        "addl $0x67c, %edx\n"
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "leal 4(%eax), %edx\n"
        "cmpb $0, 1(%edx)\n" /* line 2254 */
        "jne .Lf209be_000209e2\n"
        "cmpb $0, 4(%eax)\n"
        "je .Lf209be_000209f3\n"
        ".Lf209be_000209e2:\n"
        "movb $0, 1(%edx)\n" /* line 60 */
        "movb $0, 4(%eax)\n" /* line 94 */
        "movl %ecx, 8(%ebp)\n" /* line 2258 | this */
        /* } scope */
        "popl %ebp\n" /* line 2260 */
        /* { scope 1 */
        "jmp glDisableVertexAttribArrayARB\n" /* line 2258 */
        /* } scope */
        ".Lf209be_000209f3:\n"
        "popl %ebp\n" /* line 2260 */
        "retl\n"
    );
}

/* line 30 */
__attribute__((naked))
unsigned int COpenGL_CTexUnit_SetTex(const CTexUnit * _this, GLenum Target, const COpenGLTexture * pOpenGLTexInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 30 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* Target */
        "movl 0x10(%ebp), %eax\n" /* pOpenGLTexInfo */
        /* { scope 1 */
        "leal 4(%eax), %ebx\n" /* line 124 */
        "movl 4(%eax), %eax\n" /* line 60 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* Target */
        "calll glBindTexture\n"
        "cmpl $0xde1, %edi\n" /* line 87 | Target */
        "je .Lf209f6_00020a3c\n"
        "cmpl $0x806f, %edi\n" /* line 91 | Target */
        "je .Lf209f6_00020ae1\n"
        "cmpl $0x8513, %edi\n" /* line 95 | Target */
        "je .Lf209f6_00020b03\n"
        ".Lf209f6_00020a3c:\n"
        "xorl %edx, %edx\n"
        ".Lf209f6_00020a3e:\n"
        "movl (%ebx), %eax\n" /* line 72 */
        "movl %eax, 4(%esi, %edx, 4)\n" /* this */
        "movl 4(%ebx), %eax\n" /* line 74 */
        "movl %eax, 0x10(%esi, %edx, 4)\n" /* this */
        "movl 8(%ebx), %eax\n" /* line 75 */
        "movl %eax, 0x1c(%esi, %edx, 4)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 76 */
        "movl %eax, 0x28(%esi, %edx, 4)\n" /* this */
        "movl 0x14(%ebx), %eax\n" /* line 77 */
        "movl %eax, 0x40(%esi, %edx, 4)\n" /* this */
        "movl 0x18(%ebx), %eax\n" /* line 78 */
        "movl %eax, 0x4c(%esi, %edx, 4)\n" /* this */
        "movl 0x20(%ebx), %eax\n" /* line 79 */
        "movl %eax, 0x58(%esi, %edx, 4)\n" /* this */
        "movl 0x1c(%ebx), %eax\n" /* line 80 */
        "movl %eax, 0x64(%esi, %edx, 4)\n" /* this */
        "cmpl $0x8513, %edi\n" /* line 87 | Target */
        "je .Lf209f6_00020ac3\n"
        "cmpl $0x806f, %edi\n" /* line 95 | Target */
        "je .Lf209f6_00020aeb\n"
        "cmpl $0xde1, %edi\n" /* line 108 | Target */
        "je .Lf209f6_00020a95\n"
        /* } scope */
        ".Lf209f6_00020a8d:\n"
        "addl $0x1c, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf209f6_00020a95:\n"
        "cmpb $0, 1(%esi)\n" /* line 111 | this */
        "je .Lf209f6_00020b1f\n"
        ".Lf209f6_00020a9f:\n"
        "cmpb $0, 2(%esi)\n" /* line 117 | this */
        "jne .Lf209f6_00020b0d\n"
        ".Lf209f6_00020aa5:\n"
        "cmpb $0, 3(%esi)\n" /* line 122 | this */
        "je .Lf209f6_00020a8d\n"
        "movl $0x8513, (%esp)\n" /* line 124 */
        "calll glDisable\n"
        "movb $0, 3(%esi)\n" /* line 125 | this */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf209f6_00020ac3:\n"
        "cmpb $0, 3(%esi)\n" /* line 89 | this */
        "jne .Lf209f6_00020a8d\n"
        "movl $0x8513, (%esp)\n" /* line 91 */
        "calll glEnable\n"
        "movb $1, 3(%esi)\n" /* line 92 | this */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf209f6_00020ae1:\n"
        "movl $1, %edx\n" /* line 91 */
        "jmp .Lf209f6_00020a3e\n"
        ".Lf209f6_00020aeb:\n"
        "cmpb $0, 2(%esi)\n" /* line 97 | this */
        "jne .Lf209f6_00020aa5\n"
        "movl $0x806f, (%esp)\n" /* line 99 */
        "calll glEnable\n"
        "movb $1, 2(%esi)\n" /* line 100 | this */
        "jmp .Lf209f6_00020aa5\n"
        ".Lf209f6_00020b03:\n"
        "movl $2, %edx\n" /* line 95 */
        "jmp .Lf209f6_00020a3e\n"
        ".Lf209f6_00020b0d:\n"
        "movl $0x806f, (%esp)\n" /* line 119 */
        "calll glDisable\n"
        "movb $0, 2(%esi)\n" /* line 120 | this */
        "jmp .Lf209f6_00020aa5\n"
        ".Lf209f6_00020b1f:\n"
        "movl $0xde1, (%esp)\n" /* line 113 */
        "calll glEnable\n"
        "movb $1, 1(%esi)\n" /* line 114 | this */
        "jmp .Lf209f6_00020a9f\n"
    );
}

/* line 2196 */
__attribute__((naked))
unsigned int COpenGL_SetVertexProgramStreamInfo(const COpenGL * _this, UINT32 AttribArray, GLint VSize, GLenum VType, int Normalized, GLsizei Stride, const unsigned int * pStream)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2196 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* AttribArray */
        "movzbl 0x18(%ebp), %eax\n" /* Normalized */
        "movb %al, -0x1d(%ebp)\n" /* Normalized */
        /* { scope 1 */
        "leal (%esi, %esi, 2), %eax\n" /* line 110 */
        "leal 0x67c(%edi, %eax, 8), %eax\n"
        "leal 4(%eax), %ebx\n"
        "cmpb $0, 1(%ebx)\n" /* line 2200 | Stream */
        "je .Lf20b34_00020bec\n"
        "cmpb $0, 4(%eax)\n"
        "jne .Lf20b34_00020bec\n"
        "cmpl $3, %esi\n" /* line 2209 | AttribArray */
        "je .Lf20b34_00020c01\n"
        ".Lf20b34_00020b74:\n"
        "cmpl $5, %esi\n" /* AttribArray */
        "je .Lf20b34_00020c68\n"
        "testl %esi, %esi\n" /* AttribArray */
        "jne .Lf20b34_00020c11\n"
        "movb $1, 0x49(%edi)\n" /* line 34 */
        ".Lf20b34_00020b89:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2225 | VSize */
        "cmpl %eax, 4(%ebx)\n" /* Stream */
        "jne .Lf20b34_00020c0d\n"
        ".Lf20b34_00020b91:\n"
        "movl 0x14(%ebp), %edx\n" /* VType */
        "cmpl 8(%ebx), %edx\n" /* Stream */
        "je .Lf20b34_00020c71\n"
        ".Lf20b34_00020b9d:\n"
        "movl 0x10(%ebp), %edx\n" /* VSize */
        ".Lf20b34_00020ba0:\n"
        "movl %edx, 4(%ebx)\n" /* line 61 */
        "movl 0x14(%ebp), %eax\n" /* line 62 | VType */
        "movl %eax, 8(%ebx)\n"
        "movzbl -0x1d(%ebp), %eax\n" /* line 2236 | Normalized */
        "movb %al, 0xc(%ebx)\n" /* line 63 */
        "movl 0x1c(%ebp), %edx\n" /* line 64 | Stride */
        "movl %edx, 0x10(%ebx)\n"
        "movl 0x20(%ebp), %edx\n" /* line 65 | pStream */
        "movl %edx, 0x14(%ebx)\n"
        "movl %edx, 0x14(%esp)\n" /* line 2240 */
        "movl 0x1c(%ebp), %edx\n" /* Stride */
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* VType */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* VSize */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* AttribArray */
        "calll glVertexAttribPointerARB\n"
        ".Lf20b34_00020be1:\n"
        "movb $0, (%ebx)\n" /* line 94 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2244 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf20b34_00020bec:\n"
        "movb $1, 1(%ebx)\n" /* line 60 */
        "movl %esi, (%esp)\n" /* line 2203 | AttribArray */
        "calll glEnableVertexAttribArrayARB\n"
        "cmpl $3, %esi\n" /* line 2209 | AttribArray */
        "jne .Lf20b34_00020b74\n"
        ".Lf20b34_00020c01:\n"
        "movb $1, 0x61(%edi)\n" /* line 34 */
        "movl 0x10(%ebp), %eax\n" /* line 2225 | VSize */
        "cmpl %eax, 4(%ebx)\n" /* Stream */
        "je .Lf20b34_00020b91\n"
        ".Lf20b34_00020c0d:\n"
        "movl %eax, %edx\n"
        "jmp .Lf20b34_00020ba0\n"
        ".Lf20b34_00020c11:\n"
        "cmpl $7, %esi\n" /* line 2215 | AttribArray */
        "jbe .Lf20b34_00020b89\n"
        "leal -8(%esi), %ecx\n" /* line 2217 | AttribArray */
        "movl 0x65c(%edi), %edx\n" /* line 343 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x660(%edi), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 2217 */
        "sarl $4, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "addl %eax, %edx\n"
        "negl %edx\n"
        "cmpl %edx, %ecx\n"
        "jae .Lf20b34_00020b89\n"
        "leal (%ecx, %ecx, 8), %eax\n" /* line 654 */
        "leal (%ecx, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* line 34 */
        "movb $1, 0x109(%edx, %eax)\n"
        "jmp .Lf20b34_00020b89\n"
        ".Lf20b34_00020c68:\n"
        "movb $1, 0x19(%edi)\n"
        "jmp .Lf20b34_00020b89\n"
        ".Lf20b34_00020c71:\n"
        "movzbl -0x1d(%ebp), %eax\n" /* line 2225 | Normalized */
        "cmpb %al, 0xc(%ebx)\n" /* Stream */
        "jne .Lf20b34_00020b9d\n"
        "movl 0x1c(%ebp), %edx\n" /* Stride */
        "cmpl 0x10(%ebx), %edx\n" /* Stream */
        "jne .Lf20b34_00020b9d\n"
        "movl 0x20(%ebp), %eax\n" /* pStream */
        "cmpl 0x14(%ebx), %eax\n" /* Stream */
        "jne .Lf20b34_00020b9d\n"
        "cmpb $0, (%ebx)\n" /* Stream */
        "jne .Lf20b34_00020b9d\n"
        "jmp .Lf20b34_00020be1\n"
    );
}

/* line 162 */
__attribute__((naked))
unsigned int COpenGL_CTexUnit_Reset(const CTexUnit * _this, int SupportsAnisotropicFiltering, int SupportsLODBias, int IsProgramableOnly)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 162 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movzbl 0xc(%ebp), %eax\n" /* SupportsAnisotropicFiltering */
        "movb %al, -0x29(%ebp)\n" /* SupportsAnisotropicFiltering */
        "movzbl 0x10(%ebp), %eax\n" /* SupportsLODBias */
        "movb %al, -0x2a(%ebp)\n" /* SupportsLODBias */
        /* { scope 1 */
        "movzbl 0x14(%ebp), %eax\n" /* line 152 | IsProgramableOnly */
        "movb %al, (%esi)\n"
        "movl imp_g_InhibitOpenGLErrors, %ebx\n" /* line 201 */
        "movb $1, (%ebx)\n"
        "movl $0xde0, (%esp)\n" /* line 202 */
        "calll glDisable\n"
        "movb $1, 1(%esi)\n" /* line 205 | this */
        "movl $0xde1, (%esp)\n" /* line 206 */
        "calll glEnable\n"
        "movl $0, 4(%esi)\n" /* line 208 | this */
        "movb $0, 2(%esi)\n" /* line 210 | this */
        "movl $0x806f, (%esp)\n" /* line 211 */
        "calll glDisable\n"
        "movl $0, 8(%esi)\n" /* line 213 | this */
        "movb $0, 3(%esi)\n" /* line 215 | this */
        "movl $0x8513, (%esp)\n" /* line 216 */
        "calll glDisable\n"
        "movl $0, 0xc(%esi)\n" /* line 218 | this */
        "movb $0, (%ebx)\n" /* line 219 */
        "cmpb $0, (%esi)\n" /* line 221 | this */
        "je .Lf20ca4_000213e9\n"
        ".Lf20ca4_00020d2a:\n"
        "movl $0x3f800000, %edi\n" /* line 229 */
        "movl %edi, -0x28(%ebp)\n" /* rgba */
        "movl %edi, -0x24(%ebp)\n"
        "movl %edi, -0x20(%ebp)\n"
        "movl %edi, -0x1c(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 193 | rgba */
        "movl %eax, 8(%esp)\n"
        "movl $0x2201, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvfv\n"
        "leal 0xb0(%esi), %edx\n" /* this */
        "movl -0x28(%ebp), %eax\n" /* rgba */
        "movl %eax, 0xb0(%esi)\n" /* this */
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "cmpb $0, -0x2a(%ebp)\n" /* line 232 | SupportsLODBias */
        "jne .Lf20ca4_000213c4\n"
        ".Lf20ca4_00020d81:\n"
        "movl $0x2901, 8(%esp)\n" /* line 154 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x10(%esi)\n"
        "movl $0x2901, 8(%esp)\n" /* line 155 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x1c(%esi)\n"
        "movl $0x2901, 8(%esp)\n" /* line 156 */
        "movl $0x8072, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x28(%esi)\n"
        "movl $0x2702, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2702, 0x40(%esi)\n" /* this */
        "movl $0x2601, 8(%esp)\n" /* line 170 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 0x4c(%esi)\n" /* this */
        "movl $0x3e8, 8(%esp)\n" /* line 172 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x3e8, 0x64(%esi)\n" /* this */
        "cmpb $0, -0x29(%ebp)\n" /* line 244 | SupportsAnisotropicFiltering */
        "jne .Lf20ca4_000213a4\n"
        ".Lf20ca4_00020e5d:\n"
        "movl $0x2901, 8(%esp)\n" /* line 154 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x14(%esi)\n"
        "movl $0x2901, 8(%esp)\n" /* line 155 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x20(%esi)\n"
        "movl $0x2901, 8(%esp)\n" /* line 156 */
        "movl $0x8072, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x2c(%esi)\n"
        "movl $0x2702, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2702, 0x44(%esi)\n" /* this */
        "movl $0x2601, 8(%esp)\n" /* line 170 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 0x50(%esi)\n" /* this */
        "movl $0x3e8, 8(%esp)\n" /* line 172 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x3e8, 0x68(%esi)\n" /* this */
        "cmpb $0, -0x29(%ebp)\n" /* line 256 | SupportsAnisotropicFiltering */
        "jne .Lf20ca4_00021384\n"
        ".Lf20ca4_00020f39:\n"
        "movl $0x2901, 8(%esp)\n" /* line 154 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x18(%esi)\n"
        "movl $0x2901, 8(%esp)\n" /* line 155 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x24(%esi)\n"
        "movl $0x2901, 8(%esp)\n" /* line 156 */
        "movl $0x8072, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2901, 0x30(%esi)\n"
        "movl $0x2702, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2702, 0x48(%esi)\n" /* this */
        "movl $0x2601, 8(%esp)\n" /* line 170 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 0x54(%esi)\n" /* this */
        "movl $0x3e8, 8(%esp)\n" /* line 172 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x3e8, 0x6c(%esi)\n" /* this */
        "cmpb $0, -0x29(%ebp)\n" /* line 268 | SupportsAnisotropicFiltering */
        "jne .Lf20ca4_00021364\n"
        ".Lf20ca4_00021015:\n"
        "cmpb $0, (%esi)\n" /* line 274 | this */
        "jne .Lf20ca4_0002135c\n"
        "movb $0, 0x11c(%esi)\n" /* line 205 | this */
        "movl $0xc60, (%esp)\n" /* line 206 */
        "calll glDisable\n"
        "movb $0, 0x11d(%esi)\n" /* line 205 | this */
        "movl $0xc61, (%esp)\n" /* line 206 */
        "calll glDisable\n"
        "movb $0, 0x11e(%esi)\n" /* line 205 | this */
        "movl $0xc62, (%esp)\n" /* line 206 */
        "calll glDisable\n"
        "movb $0, 0x11f(%esi)\n" /* line 205 | this */
        "movl $0xc63, (%esp)\n" /* line 206 */
        "calll glDisable\n"
        "movl $0x2401, 0x120(%esi)\n" /* line 210 | this */
        "movl $0x2401, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "movl $0x2000, (%esp)\n"
        "calll glTexGeni\n"
        "movl $0x2401, 0x124(%esi)\n" /* line 210 | this */
        "movl $0x2401, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "movl $0x2001, (%esp)\n"
        "calll glTexGeni\n"
        "movl $0x2401, 0x128(%esi)\n" /* line 210 | this */
        "movl $0x2401, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "movl $0x2002, (%esp)\n"
        "calll glTexGeni\n"
        "movl $0x2401, 0x12c(%esi)\n" /* line 210 | this */
        "movl $0x2401, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "movl $0x2003, (%esp)\n"
        "calll glTexGeni\n"
        "movl $0x2100, 8(%esp)\n" /* line 174 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x2100, 0x70(%esi)\n" /* this */
        "movl $0x1702, 8(%esp)\n" /* line 176 */
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 0x74(%esi)\n" /* this */
        "movl $0x300, 8(%esp)\n" /* line 177 */
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 0x78(%esi)\n" /* this */
        "movl $0x8578, 8(%esp)\n" /* line 178 */
        "movl $0x8581, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x8578, 0x7c(%esi)\n" /* this */
        "movl $0x300, 8(%esp)\n" /* line 179 */
        "movl $0x8591, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 0x80(%esi)\n" /* this */
        "movl $0x8576, 8(%esp)\n" /* line 180 */
        "movl $0x8582, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x8576, 0x84(%esi)\n" /* this */
        "movl $0x302, 8(%esp)\n" /* line 181 */
        "movl $0x8592, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 0x88(%esi)\n" /* this */
        "movl %edi, 8(%esp)\n" /* line 182 */
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl %edi, 0xa8(%esi)\n" /* this */
        "movl $0x2100, 8(%esp)\n" /* line 184 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x2100, 0x8c(%esi)\n" /* this */
        "movl $0x1702, 8(%esp)\n" /* line 185 */
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 0x90(%esi)\n" /* this */
        "movl $0x302, 8(%esp)\n" /* line 186 */
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 0x94(%esi)\n" /* this */
        "movl $0x8578, 8(%esp)\n" /* line 187 */
        "movl $0x8589, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x8578, 0x98(%esi)\n" /* this */
        "movl $0x302, 8(%esp)\n" /* line 188 */
        "movl $0x8599, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 0x9c(%esi)\n" /* this */
        "movl $0x8576, 8(%esp)\n" /* line 189 */
        "movl $0x858a, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x8576, 0xa0(%esi)\n" /* this */
        "movl $0x302, 8(%esp)\n" /* line 190 */
        "movl $0x859a, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 0xa4(%esi)\n" /* this */
        "movl %edi, 8(%esp)\n" /* line 191 */
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl %edi, 0xac(%esi)\n" /* this */
        "leal 0x104(%esi), %ebx\n" /* line 306 | this */
        "movl %ebx, (%esp)\n"
        "calll CBaseVA_Reset\n"
        "movl %ebx, (%esp)\n" /* line 307 */
        "calll CBaseVA_Force\n"
        /* } scope */
        ".Lf20ca4_0002135c:\n"
        "addl $0x3c, %esp\n" /* line 311 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf20ca4_00021364:\n"
        "movl %edi, 8(%esp)\n" /* line 171 */
        "movl $0x84fe, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glTexParameterf\n"
        "movl %edi, 0x60(%esi)\n" /* this */
        "jmp .Lf20ca4_00021015\n"
        ".Lf20ca4_00021384:\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x84fe, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameterf\n"
        "movl %edi, 0x5c(%esi)\n" /* this */
        "jmp .Lf20ca4_00020f39\n"
        ".Lf20ca4_000213a4:\n"
        "movl %edi, 8(%esp)\n"
        "movl $0x84fe, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameterf\n"
        "movl %edi, 0x58(%esi)\n" /* this */
        "jmp .Lf20ca4_00020e5d\n"
        ".Lf20ca4_000213c4:\n"
        "xorl %ebx, %ebx\n" /* line 194 */
        "movl %ebx, 8(%esp)\n"
        "movl $0x8501, 4(%esp)\n"
        "movl $0x8500, (%esp)\n"
        "calll glTexEnvf\n"
        "movl %ebx, 0xc0(%esi)\n" /* this */
        "jmp .Lf20ca4_00020d81\n"
        ".Lf20ca4_000213e9:\n"
        "leal 0xc4(%esi), %ecx\n" /* line 223 | this */
        "movl imp___ZN13COpenGLMatrix9sIdentityE, %eax\n"
        "movl (%eax), %edx\n"
        "movl %edx, 0xc4(%esi)\n" /* this */
        "movl 4(%eax), %edx\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, 8(%ecx)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, 0x10(%ecx)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, 0x18(%ecx)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, 0x1c(%ecx)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, 0x20(%ecx)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, 0x24(%ecx)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, 0x28(%ecx)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, 0x2c(%ecx)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, 0x30(%ecx)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, 0x34(%ecx)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, 0x38(%ecx)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, 0x3c(%ecx)\n"
        "calll glLoadIdentity\n" /* line 224 */
        "movl $0x8570, 8(%esp)\n" /* line 225 */
        "movl $0x2200, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "jmp .Lf20ca4_00020d2a\n"
    );
}

/* line 2326 */
__attribute__((naked))
unsigned int COpenGL_SetVAO(const COpenGL * _this, const COpenGLVAO *VAO, int IsFixedFunction, int ForceValidation)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2326 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movzbl 0x10(%ebp), %eax\n" /* IsFixedFunction */
        "movb %al, -0x19(%ebp)\n" /* IsFixedFunction */
        "movzbl 0x14(%ebp), %edx\n" /* ForceValidation */
        "movb %dl, -0x1a(%ebp)\n" /* ForceValidation */
        "movl 0xc(%ebp), %ecx\n" /* line 2328 | VAO */
        "movl 4(%ecx), %eax\n"
        "movl (%eax), %eax\n"
        "cmpl g_VAOID, %eax\n"
        "je .Lf2147c_00021721\n"
        "movl %ecx, %ebx\n"
        /* { scope 1 */
        ".Lf2147c_000214ac:\n"
        "movl %eax, g_VAOID\n" /* line 2330 */
        "movl 4(%ebx), %eax\n" /* line 2331 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll glBindVertexArrayAPPLE\n"
        "leal 0x65c(%edi), %eax\n" /* line 316 */
        "movl %eax, -0x24(%ebp)\n"
        "movl 4(%eax), %eax\n" /* line 361 */
        "subl 0x65c(%edi), %eax\n" /* line 759 */
        "sarl $4, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "addl %eax, %edx\n"
        "negl %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 2338 | i */
        "movl %eax, 0xc(%edi)\n" /* this */
        "movl 0xc(%ebx), %eax\n" /* line 2339 | i */
        "movl %eax, 0x10(%edi)\n" /* this */
        "cmpb $0, -0x19(%ebp)\n" /* line 2341 | IsFixedFunction */
        "je .Lf2147c_000216a4\n"
        /* { scope 2 */
        ".Lf2147c_00021502:\n"
        "movl 0xc(%ebp), %edx\n" /* line 74 | VAO */
        "addl $0x10, %edx\n"
        "leal 0x14(%edi), %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "movb $0, 0x19(%edi)\n" /* line 35 */
        "movl 0xc(%ebp), %edx\n" /* line 85 | VAO */
        "addl $0x28, %edx\n"
        "leal 0x2c(%edi), %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "movb $0, 0x31(%edi)\n" /* line 35 */
        "movl 0xc(%ebp), %edx\n" /* line 95 | VAO */
        "addl $0x40, %edx\n"
        "leal 0x5c(%edi), %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "movb $0, 0x61(%edi)\n" /* line 35 */
        "movl 0xc(%ebp), %edx\n" /* line 106 | VAO */
        "addl $0x58, %edx\n"
        "leal 0x44(%edi), %ecx\n" /* this */
        /* { scope 3 */
        "movzbl 4(%edx), %eax\n" /* line 19 */
        "movb %al, 4(%ecx)\n"
        "movzbl 5(%edx), %eax\n"
        "movb %al, 5(%ecx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "movb $0, 0x49(%edi)\n" /* line 35 */
        "movl -0x20(%ebp), %ebx\n" /* line 2358 | i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf2147c_000216b3\n"
        ".Lf2147c_000215d9:\n"
        "leal 0x680(%edi), %eax\n" /* line 2378 | this, pDstV */
        "xorl %edx, %edx\n"
        ".Lf2147c_000215e1:\n"
        "movb $1, (%eax)\n" /* line 95 */
        "addl $0x18, %eax\n" /* line 2382 */
        "addl $1, %edx\n" /* line 2379 */
        "cmpl $0x10, %edx\n"
        "jne .Lf2147c_000215e1\n"
        /* } scope */
        "cmpb $0, -0x19(%ebp)\n" /* line 2386 | IsFixedFunction */
        "je .Lf2147c_000215ff\n"
        "cmpb $0, -0x1a(%ebp)\n" /* ForceValidation */
        "je .Lf2147c_0002169c\n"
        ".Lf2147c_000215ff:\n"
        "leal 0x698(%edi), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* VAO */
        "xorl %ebx, %ebx\n" /* i */
        ".Lf2147c_0002160a:\n"
        "movl 0x130(%edx), %eax\n" /* line 2396 */
        "movl %eax, -0x18(%ecx)\n"
        "movl 0x134(%edx), %eax\n"
        "movl %eax, -0x14(%ecx)\n"
        "movl 0x138(%edx), %eax\n"
        "movl %eax, -0x10(%ecx)\n"
        "movl 0x13c(%edx), %eax\n"
        "movl %eax, -0xc(%ecx)\n"
        "movl 0x140(%edx), %eax\n"
        "movl %eax, -8(%ecx)\n"
        "movl 0x144(%edx), %eax\n"
        "movl %eax, -4(%ecx)\n"
        "movb $0, -0x18(%ecx)\n" /* line 94 */
        "addl $1, %ebx\n" /* line 2394 | i */
        "addl $0x18, %ecx\n"
        "addl $0x18, %edx\n"
        "cmpl $0x10, %ebx\n" /* i */
        "jne .Lf2147c_0002160a\n"
        "movb $1, 0x19(%edi)\n" /* line 34 */
        "movb $1, 0x31(%edi)\n"
        "movb $1, 0x61(%edi)\n"
        "movb $1, 0x49(%edi)\n"
        "movl -0x20(%ebp), %ecx\n" /* line 2410 */
        "testl %ecx, %ecx\n"
        "je .Lf2147c_0002169c\n"
        /* { scope 2 */
        "movl 0x65c(%edi), %eax\n" /* line 334 */
        "cmpb $0, (%eax)\n" /* line 2413 */
        "jne .Lf2147c_0002169c\n"
        "xorl %ecx, %ecx\n" /* line 2420 */
        "movl $0x130, %edx\n"
        ".Lf2147c_0002167b:\n"
        "movb $1, 0x109(%eax)\n" /* line 34 */
        /* } scope */
        "addl $1, %ecx\n" /* line 2410 */
        "cmpl %ecx, -0x20(%ebp)\n"
        "jbe .Lf2147c_0002169c\n"
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 495 */
        "movl -0x24(%ebp), %ebx\n"
        "addl (%ebx), %eax\n"
        "addl $0x130, %edx\n"
        "cmpb $0, (%eax)\n" /* line 2413 */
        "je .Lf2147c_0002167b\n"
        /* } scope */
        /* } scope */
        ".Lf2147c_0002169c:\n"
        "addl $0x2c, %esp\n" /* line 2425 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2147c_000216a4:\n"
        "cmpb $0, -0x1a(%ebp)\n" /* line 2341 | ForceValidation */
        "je .Lf2147c_000215ff\n"
        "jmp .Lf2147c_00021502\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf2147c_000216b3:\n"
        "movl 0x65c(%edi), %eax\n" /* line 334 */
        "movl %eax, %edx\n" /* line 495 */
        "cmpb $0, (%eax)\n" /* line 2361 */
        "jne .Lf2147c_000215d9\n"
        "xorl %ebx, %ebx\n" /* line 2369 | i */
        "movl $0x130, %esi\n"
        ".Lf2147c_000216cb:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 117 */
        "movl 0xc(%ebp), %ecx\n" /* VAO, this */
        "leal 0x70(%ecx, %eax, 8), %eax\n"
        "leal 0x104(%edx), %ecx\n" /* this */
        /* { scope 4 */
        "movzbl 4(%eax), %edx\n" /* line 19 */
        "movb %dl, 4(%ecx)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, 8(%ecx)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, 0x10(%ecx)\n"
        "movl 0x14(%eax), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        "movb $0, 5(%ecx)\n" /* line 35 */
        /* } scope */
        "addl $1, %ebx\n" /* line 2358 | i */
        "cmpl %ebx, -0x20(%ebp)\n" /* i */
        "jbe .Lf2147c_000215d9\n"
        /* { scope 3 */
        "movl %esi, %edx\n" /* line 495 */
        "movl -0x24(%ebp), %ecx\n"
        "addl (%ecx), %edx\n"
        "addl $0x130, %esi\n"
        "cmpb $0, (%edx)\n" /* line 2361 */
        "je .Lf2147c_000216cb\n"
        "jmp .Lf2147c_000215d9\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf2147c_00021721:\n"
        "testb %dl, %dl\n" /* line 2328 */
        "je .Lf2147c_0002169c\n"
        "movl 0xc(%ebp), %ebx\n" /* VAO */
        "jmp .Lf2147c_000214ac\n"
    );
}

/* line 392 */
__attribute__((naked))
unsigned int COpenGL_EnableColorArray(const COpenGL * _this, GLint Size, GLenum Type, GLsizei Stride, const unsigned int * Pointer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 392 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* Size */
        /* { scope 1 */
        "movb $1, 0x6f8(%eax)\n" /* line 95 */
        "leal 0x14(%eax), %ebx\n" /* line 398 */
        "movzbl 5(%ebx), %esi\n" /* NeedsValidation */
        "cmpb $0, 4(%ebx)\n" /* line 400 */
        "je .Lf21732_0002178d\n"
        "movl %esi, %eax\n" /* NeedsValidation */
        "testb %al, %al\n"
        "jne .Lf21732_0002178d\n"
        "cmpl 8(%ebx), %edi\n" /* line 405 | Size */
        "je .Lf21732_000217a8\n"
        ".Lf21732_00021760:\n"
        "movl 0x18(%ebp), %edx\n" /* Pointer */
        ".Lf21732_00021763:\n"
        "movl %edi, 0x10(%esp)\n" /* line 407 | Size */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Stride */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* Type */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CColorArray_Set\n"
        ".Lf21732_00021781:\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 411 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf21732_0002178d:\n"
        "movl $0x8076, 4(%esp)\n" /* line 76 */
        "movl %ebx, (%esp)\n"
        "calll CBaseVA_Enable\n"
        "movl %esi, %edx\n" /* line 405 | NeedsValidation */
        "testb %dl, %dl\n"
        "jne .Lf21732_00021760\n"
        "cmpl 8(%ebx), %edi\n" /* Size */
        "jne .Lf21732_00021760\n"
        ".Lf21732_000217a8:\n"
        "movl 0x10(%ebp), %eax\n" /* Type */
        "cmpl 0xc(%ebx), %eax\n"
        "jne .Lf21732_00021760\n"
        "movl 0x14(%ebp), %edx\n" /* Stride */
        "cmpl 0x10(%ebx), %edx\n"
        "jne .Lf21732_00021760\n"
        "movl 0x18(%ebp), %eax\n" /* Pointer */
        "cmpl 0x14(%ebx), %eax\n"
        "je .Lf21732_00021781\n"
        "movl %eax, %edx\n"
        "jmp .Lf21732_00021763\n"
    );
}

/* line 416 */
__attribute__((naked))
unsigned int COpenGL_DisableColorArray(const COpenGL * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 416 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* line 421 | this */
        "addl $0x14, %ebx\n"
        "movzbl 5(%ebx), %eax\n" /* line 42 */
        "cmpb $0, 4(%ebx)\n" /* line 423 */
        "jne .Lf217c4_000217df\n"
        "testb %al, %al\n"
        "je .Lf217c4_000217ef\n"
        ".Lf217c4_000217df:\n"
        "movl $0x8076, 4(%esp)\n" /* line 77 */
        "movl %ebx, (%esp)\n"
        "calll CBaseVA_Disable\n"
        ".Lf217c4_000217ef:\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        "addl $0x14, %esp\n" /* line 429 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 593 */
__attribute__((naked))
unsigned int COpenGL_EnableNormalArray(const COpenGL * _this, GLenum Type, GLsizei Stride, const unsigned int *Pointer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 593 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* Type */
        /* { scope 1 */
        "movb $1, 0x6c8(%eax)\n" /* line 95 */
        "leal 0x5c(%eax), %ebx\n" /* line 598 */
        "movzbl 5(%ebx), %esi\n" /* NeedsValidation */
        "cmpb $0, 4(%ebx)\n" /* line 600 */
        "je .Lf217fa_0002184e\n"
        "movl %esi, %eax\n" /* NeedsValidation */
        "testb %al, %al\n"
        "jne .Lf217fa_0002184e\n"
        "cmpl 0xc(%ebx), %edi\n" /* line 605 | Type */
        "je .Lf217fa_00021869\n"
        ".Lf217fa_00021828:\n"
        "movl 0x14(%ebp), %eax\n" /* Pointer */
        ".Lf217fa_0002182b:\n"
        "movl %eax, 0xc(%esp)\n" /* line 607 */
        "movl 0x10(%ebp), %edx\n" /* Stride */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* Type */
        "movl %ebx, (%esp)\n"
        "calll CNormalArray_Set\n"
        ".Lf217fa_00021842:\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 610 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf217fa_0002184e:\n"
        "movl $0x8075, 4(%esp)\n" /* line 97 */
        "movl %ebx, (%esp)\n"
        "calll CBaseVA_Enable\n"
        "movl %esi, %edx\n" /* line 605 | NeedsValidation */
        "testb %dl, %dl\n"
        "jne .Lf217fa_00021828\n"
        "cmpl 0xc(%ebx), %edi\n" /* Type */
        "jne .Lf217fa_00021828\n"
        ".Lf217fa_00021869:\n"
        "movl 0x10(%ebp), %eax\n" /* Stride */
        "cmpl 0x10(%ebx), %eax\n"
        "jne .Lf217fa_00021828\n"
        "movl 0x14(%ebp), %edx\n" /* Pointer */
        "cmpl 0x14(%ebx), %edx\n"
        "je .Lf217fa_00021842\n"
        "movl %edx, %eax\n"
        "jmp .Lf217fa_0002182b\n"
    );
}

/* line 615 */
__attribute__((naked))
unsigned int COpenGL_DisableNormalArray(const COpenGL * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 615 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* line 620 | this */
        "addl $0x5c, %ebx\n"
        "movzbl 5(%ebx), %eax\n" /* line 42 */
        "cmpb $0, 4(%ebx)\n" /* line 622 */
        "jne .Lf2187e_00021899\n"
        "testb %al, %al\n"
        "je .Lf2187e_000218a9\n"
        ".Lf2187e_00021899:\n"
        "movl $0x8075, 4(%esp)\n" /* line 98 */
        "movl %ebx, (%esp)\n"
        "calll CBaseVA_Disable\n"
        ".Lf2187e_000218a9:\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        "addl $0x14, %esp\n" /* line 630 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 542 */
__attribute__((naked))
unsigned int COpenGL_EnableVertexArray(const COpenGL * _this, GLint Size, GLenum Type, GLsizei Stride, const unsigned int * Pointer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 542 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* Size */
        /* { scope 1 */
        "movb $1, 0x680(%eax)\n" /* line 95 */
        "leal 0x44(%eax), %ebx\n" /* line 547 */
        "movzbl 5(%ebx), %esi\n" /* NeedsValidation */
        "cmpb $0, 4(%ebx)\n" /* line 549 */
        "je .Lf218b4_0002190f\n"
        "movl %esi, %eax\n" /* NeedsValidation */
        "testb %al, %al\n"
        "jne .Lf218b4_0002190f\n"
        "cmpl 8(%ebx), %edi\n" /* line 554 | Size */
        "je .Lf218b4_0002192a\n"
        ".Lf218b4_000218e2:\n"
        "movl 0x18(%ebp), %edx\n" /* Pointer */
        ".Lf218b4_000218e5:\n"
        "movl %edi, 0x10(%esp)\n" /* line 556 | Size */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Stride */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* Type */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CVertexArray_Set\n"
        ".Lf218b4_00021903:\n"
        "movb $0, 5(%ebx)\n" /* line 35 */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 559 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf218b4_0002190f:\n"
        "movl $0x8074, 4(%esp)\n" /* line 108 */
        "movl %ebx, (%esp)\n"
        "calll CBaseVA_Enable\n"
        "movl %esi, %edx\n" /* line 554 | NeedsValidation */
        "testb %dl, %dl\n"
        "jne .Lf218b4_000218e2\n"
        "cmpl 8(%ebx), %edi\n" /* Size */
        "jne .Lf218b4_000218e2\n"
        ".Lf218b4_0002192a:\n"
        "movl 0x10(%ebp), %eax\n" /* Type */
        "cmpl 0xc(%ebx), %eax\n"
        "jne .Lf218b4_000218e2\n"
        "movl 0x14(%ebp), %edx\n" /* Stride */
        "cmpl 0x10(%ebx), %edx\n"
        "jne .Lf218b4_000218e2\n"
        "movl 0x18(%ebp), %eax\n" /* Pointer */
        "cmpl 0x14(%ebx), %eax\n"
        "je .Lf218b4_00021903\n"
        "movl %eax, %edx\n"
        "jmp .Lf218b4_000218e5\n"
    );
}

/* line 792 */
__attribute__((naked))
unsigned int COpenGL_SetLight(const COpenGL * _this, UINT32 Light, const LightInfoType *Src)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 792 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %ecx\n" /* Light */
        "movl 0x10(%ebp), %ebx\n" /* Src */
        /* { scope 1: Src0, Src1, Src2, Src3, ... */
        "leal (%ecx, %ecx, 2), %edx\n" /* line 796 */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "leal 0xb0(, %eax, 4), %eax\n"
        "addl 8(%ebp), %eax\n" /* this */
        "leal 0xc(%eax), %esi\n" /* Dst */
        "addl $0x4000, %ecx\n" /* line 798 */
        "movl %ecx, -0x38(%ebp)\n" /* LightIndex */
        "leal 0xc(%ebx), %edi\n" /* line 800 | Src, Src0 */
        /* { scope 2 */
        "movl 0xc(%ebx), %edx\n" /* line 53 */
        "movl %edx, -0x34(%ebp)\n" /* Src0 */
        "movl 4(%edi), %ecx\n" /* line 54 | Src0 */
        "movl %ecx, -0x3c(%ebp)\n" /* Src1 */
        "movl 8(%edi), %edx\n" /* line 55 | Src0 */
        "movl %edx, -0x30(%ebp)\n" /* Src2 */
        "movl 0xc(%edi), %ecx\n" /* line 56 | Src0 */
        "movl %ecx, -0x2c(%ebp)\n" /* Src3 */
        "leal 0x18(%eax), %edx\n" /* line 57 */
        "movl -0x34(%ebp), %ecx\n" /* line 60 | Src0 */
        "cmpl 0x18(%eax), %ecx\n"
        "je .Lf21948_00021b68\n"
        "movl %ecx, 0x18(%eax)\n" /* line 62 */
        "movl -0x3c(%ebp), %eax\n" /* line 63 | Src1 */
        "movl %eax, 4(%edx)\n"
        "movl -0x30(%ebp), %ecx\n" /* line 64 | Src2 */
        "movl %ecx, 8(%edx)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 65 | Src3 */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        ".Lf21948_000219b6:\n"
        "movl %edi, 8(%esp)\n" /* line 802 | Src0 */
        "movl $0x1201, 4(%esp)\n"
        "movl -0x38(%ebp), %ecx\n" /* LightIndex */
        "movl %ecx, (%esp)\n"
        "calll glLightfv\n"
        ".Lf21948_000219cd:\n"
        "leal 0x1c(%ebx), %ecx\n" /* line 804 | Src */
        /* { scope 2 */
        "movl 0x1c(%ebx), %edi\n" /* line 53 | Src0 */
        "movl 4(%ecx), %edx\n" /* line 54 | Src1 */
        "movl 8(%ecx), %eax\n" /* line 55 */
        "movl %eax, -0x28(%ebp)\n" /* Src2 */
        "movl 0xc(%ecx), %eax\n" /* line 56 */
        "movl %eax, -0x24(%ebp)\n" /* Src3 */
        "leal 0x1c(%esi), %eax\n" /* line 57 */
        "cmpl 0x1c(%esi), %edi\n" /* line 60 | Src0 */
        "je .Lf21948_00021b4f\n"
        "movl %edi, 0x1c(%esi)\n" /* line 62 | Src0 */
        "movl %edx, 4(%eax)\n" /* line 63 */
        "movl -0x28(%ebp), %edx\n" /* line 64 | Src2 */
        "movl %edx, 8(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* line 65 | Src3 */
        "movl %edx, 0xc(%eax)\n"
        /* } scope */
        ".Lf21948_00021a00:\n"
        "movl %ecx, 8(%esp)\n" /* line 806 */
        "movl $0x1202, 4(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* LightIndex */
        "movl %edx, (%esp)\n"
        "calll glLightfv\n"
        ".Lf21948_00021a17:\n"
        "leal 0x2c(%ebx), %ecx\n" /* line 808 | Src */
        /* { scope 2 */
        "movl 0x2c(%ebx), %edi\n" /* line 53 | Src0 */
        "movl 4(%ecx), %edx\n" /* line 54 | Src1 */
        "movl 8(%ecx), %eax\n" /* line 55 */
        "movl %eax, -0x20(%ebp)\n" /* Src2 */
        "movl 0xc(%ecx), %eax\n" /* line 56 */
        "movl %eax, -0x1c(%ebp)\n" /* Src3 */
        "leal 0x2c(%esi), %eax\n" /* line 57 */
        "cmpl 0x2c(%esi), %edi\n" /* line 60 | Src0 */
        "je .Lf21948_00021b36\n"
        "movl %edi, 0x2c(%esi)\n" /* line 62 | Src0 */
        "movl %edx, 4(%eax)\n" /* line 63 */
        "movl -0x20(%ebp), %edx\n" /* line 64 | Src2 */
        "movl %edx, 8(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 65 | Src3 */
        "movl %edx, 0xc(%eax)\n"
        /* } scope */
        ".Lf21948_00021a4a:\n"
        "movl %ecx, 8(%esp)\n" /* line 810 */
        "movl $0x1200, 4(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* LightIndex */
        "movl %edx, (%esp)\n"
        "calll glLightfv\n"
        ".Lf21948_00021a61:\n"
        "movl 0x60(%ebx), %eax\n" /* line 813 | Src */
        "cmpl 0x60(%esi), %eax\n" /* Dst */
        "je .Lf21948_00021a89\n"
        "movl 0x60(%ebx), %eax\n" /* line 815 | Src */
        "movl %eax, 0x60(%esi)\n" /* Dst */
        "movl 0x60(%ebx), %eax\n" /* line 816 | Src */
        "movl %eax, 8(%esp)\n"
        "movl $0x1205, 4(%esp)\n"
        "movl -0x38(%ebp), %ecx\n" /* LightIndex */
        "movl %ecx, (%esp)\n"
        "calll glLightf\n"
        ".Lf21948_00021a89:\n"
        "movl 0x64(%ebx), %eax\n" /* line 818 | Src */
        "cmpl 0x64(%esi), %eax\n" /* Dst */
        "je .Lf21948_00021ab1\n"
        "movl 0x64(%ebx), %eax\n" /* line 820 | Src */
        "movl %eax, 0x64(%esi)\n" /* Dst */
        "movl 0x64(%ebx), %eax\n" /* line 821 | Src */
        "movl %eax, 8(%esp)\n"
        "movl $0x1206, 4(%esp)\n"
        "movl -0x38(%ebp), %eax\n" /* LightIndex */
        "movl %eax, (%esp)\n"
        "calll glLightf\n"
        ".Lf21948_00021ab1:\n"
        "movl 0x74(%ebx), %eax\n" /* line 823 | Src */
        "cmpl 0x74(%esi), %eax\n" /* Dst */
        "je .Lf21948_00021ad9\n"
        "movl 0x74(%ebx), %eax\n" /* line 825 | Src */
        "movl %eax, 0x74(%esi)\n" /* Dst */
        "movl 0x74(%ebx), %eax\n" /* line 826 | Src */
        "movl %eax, 8(%esp)\n"
        "movl $0x1207, 4(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* LightIndex */
        "movl %edx, (%esp)\n"
        "calll glLightf\n"
        ".Lf21948_00021ad9:\n"
        "movl 0x78(%ebx), %eax\n" /* line 828 | Src */
        "cmpl 0x78(%esi), %eax\n" /* Dst */
        "je .Lf21948_00021b01\n"
        "movl 0x78(%ebx), %eax\n" /* line 830 | Src */
        "movl %eax, 0x78(%esi)\n" /* Dst */
        "movl 0x78(%ebx), %eax\n" /* line 831 | Src */
        "movl %eax, 8(%esp)\n"
        "movl $0x1208, 4(%esp)\n"
        "movl -0x38(%ebp), %ecx\n" /* LightIndex */
        "movl %ecx, (%esp)\n"
        "calll glLightf\n"
        ".Lf21948_00021b01:\n"
        "movl 0x7c(%ebx), %eax\n" /* line 833 | Src */
        "cmpl 0x7c(%esi), %eax\n" /* Dst */
        "je .Lf21948_00021b2e\n"
        "movl 0x7c(%ebx), %eax\n" /* line 835 | Src */
        "movl %eax, 0x7c(%esi)\n" /* Dst */
        "movl 0x7c(%ebx), %eax\n" /* line 836 | Src */
        "movl %eax, 0x10(%ebp)\n" /* Src */
        "movl $0x1209, 0xc(%ebp)\n" /* Light */
        "movl -0x38(%ebp), %eax\n" /* LightIndex */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 838 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1: Src0, Src1, Src2, Src3, ... */
        "jmp glLightf\n" /* line 836 */
        /* } scope */
        ".Lf21948_00021b2e:\n"
        "addl $0x4c, %esp\n" /* line 838 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Src0, Src1, Src2, Src3, ... */
        /* { scope 2 */
        ".Lf21948_00021b36:\n"
        "cmpl 0x30(%esi), %edx\n" /* line 71 */
        "je .Lf21948_00021b84\n"
        "movl %edx, 0x30(%esi)\n" /* line 73 */
        "movl -0x20(%ebp), %edx\n" /* line 74 | Src2 */
        "movl %edx, 8(%eax)\n"
        "movl -0x1c(%ebp), %edx\n" /* line 75 | Src3 */
        "movl %edx, 0xc(%eax)\n"
        "jmp .Lf21948_00021a4a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021b4f:\n"
        "cmpl 0x20(%esi), %edx\n" /* line 71 */
        "je .Lf21948_00021bb0\n"
        "movl %edx, 0x20(%esi)\n" /* line 73 */
        "movl -0x28(%ebp), %edx\n" /* line 74 | Src2 */
        "movl %edx, 8(%eax)\n"
        "movl -0x24(%ebp), %edx\n" /* line 75 | Src3 */
        "movl %edx, 0xc(%eax)\n"
        "jmp .Lf21948_00021a00\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021b68:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 71 | Src1 */
        "cmpl 0x1c(%eax), %ecx\n"
        "je .Lf21948_00021b9a\n"
        "movl %ecx, 0x1c(%eax)\n" /* line 73 */
        "movl -0x30(%ebp), %eax\n" /* line 74 | Src2 */
        "movl %eax, 8(%edx)\n"
        "movl -0x2c(%ebp), %ecx\n" /* line 75 | Src3 */
        "movl %ecx, 0xc(%edx)\n"
        "jmp .Lf21948_000219b6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021b84:\n"
        "movl -0x20(%ebp), %edx\n" /* line 81 | Src2 */
        "cmpl 0x34(%esi), %edx\n"
        "je .Lf21948_00021bc6\n"
        "movl %edx, 0x34(%esi)\n" /* line 83 */
        "movl -0x1c(%ebp), %edx\n" /* line 84 | Src3 */
        "movl %edx, 0xc(%eax)\n"
        "jmp .Lf21948_00021a4a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021b9a:\n"
        "movl -0x30(%ebp), %ecx\n" /* line 81 | Src2 */
        "cmpl 0x20(%eax), %ecx\n"
        "je .Lf21948_00021bee\n"
        "movl %ecx, 0x20(%eax)\n" /* line 83 */
        "movl -0x2c(%ebp), %eax\n" /* line 84 | Src3 */
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf21948_000219b6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021bb0:\n"
        "movl -0x28(%ebp), %edx\n" /* line 81 | Src2 */
        "cmpl 0x24(%esi), %edx\n"
        "je .Lf21948_00021bda\n"
        "movl %edx, 0x24(%esi)\n" /* line 83 */
        "movl -0x24(%ebp), %edx\n" /* line 84 | Src3 */
        "movl %edx, 0xc(%eax)\n"
        "jmp .Lf21948_00021a00\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021bc6:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 90 | Src3 */
        "cmpl 0x38(%esi), %eax\n"
        "je .Lf21948_00021a61\n"
        "movl %eax, 0x38(%esi)\n" /* line 92 */
        "jmp .Lf21948_00021a4a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021bda:\n"
        "movl -0x24(%ebp), %eax\n" /* line 90 | Src3 */
        "cmpl 0x28(%esi), %eax\n"
        "je .Lf21948_00021a17\n"
        "movl %eax, 0x28(%esi)\n" /* line 92 */
        "jmp .Lf21948_00021a00\n"
        /* } scope */
        /* { scope 2 */
        ".Lf21948_00021bee:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 90 | Src3 */
        "cmpl 0x24(%eax), %edx\n"
        "je .Lf21948_000219cd\n"
        "movl %edx, 0x24(%eax)\n" /* line 92 */
        "jmp .Lf21948_000219b6\n"
    );
}

/* line 647 */
__attribute__((naked))
unsigned int COpenGL_EnableTexCoordArray(const COpenGL * _this, UINT32 Unit, GLint Size, GLenum Type, GLsizei Stride, const unsigned int * Pointer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 647 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* Unit */
        /* { scope 1 */
        "leal (%edi, %edi, 2), %eax\n" /* line 95 */
        "movl 8(%ebp), %edx\n" /* this */
        "movb $1, 0x740(%edx, %eax, 8)\n"
        "leal (%edi, %edi, 8), %eax\n" /* line 654 | Unit */
        "leal (%edi, %eax, 2), %ebx\n" /* Unit */
        "shll $4, %ebx\n"
        "addl 0x65c(%edx), %ebx\n"
        "leal 0x104(%ebx), %esi\n" /* line 150 */
        "movzbl 5(%esi), %eax\n" /* line 653 | ta */
        "movb %al, -0x19(%ebp)\n" /* NeedsValidation */
        "cmpb $0, 4(%esi)\n" /* line 655 | ta */
        "je .Lf21c02_00021c93\n"
        "testb %al, %al\n"
        "jne .Lf21c02_00021c93\n"
        "movl 0x10(%ebp), %eax\n" /* line 661 | Size */
        "cmpl 8(%esi), %eax\n" /* ta */
        "je .Lf21c02_00021cc6\n"
        ".Lf21c02_00021c4a:\n"
        "movl 8(%ebp), %eax\n" /* line 368 | this */
        "cmpl 8(%eax), %edi\n"
        "je .Lf21c02_00021c63\n"
        "movl %edi, 8(%eax)\n" /* line 370 */
        "leal 0x84c0(%edi), %eax\n" /* line 371 */
        "movl %eax, (%esp)\n"
        "calll glClientActiveTextureARB\n"
        ".Lf21c02_00021c63:\n"
        "movl 0x10(%ebp), %edx\n" /* line 664 | Size */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* Pointer */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* Stride */
        "movl %edx, 8(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Type */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* ta */
        "calll CTexCoordArray_Set\n"
        ".Lf21c02_00021c87:\n"
        "movb $0, 5(%esi)\n" /* line 35 */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 667 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf21c02_00021c93:\n"
        "movl 8(%ebp), %edx\n" /* line 368 | this */
        "cmpl 8(%edx), %edi\n"
        "je .Lf21c02_00021cac\n"
        "movl %edi, 8(%edx)\n" /* line 370 */
        "leal 0x84c0(%edi), %eax\n" /* line 371 */
        "movl %eax, (%esp)\n"
        "calll glClientActiveTextureARB\n"
        ".Lf21c02_00021cac:\n"
        "movl 0x104(%ebx), %eax\n" /* line 658 */
        "movl %esi, (%esp)\n" /* ta */
        "calll *8(%eax)\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 661 | NeedsValidation */
        "jne .Lf21c02_00021c4a\n"
        "movl 0x10(%ebp), %eax\n" /* Size */
        "cmpl 8(%esi), %eax\n" /* ta */
        "jne .Lf21c02_00021c4a\n"
        ".Lf21c02_00021cc6:\n"
        "movl 0x14(%ebp), %edx\n" /* Type */
        "cmpl 0xc(%esi), %edx\n" /* ta */
        "jne .Lf21c02_00021c4a\n"
        "movl 0x18(%ebp), %eax\n" /* Stride */
        "cmpl 0x10(%esi), %eax\n" /* ta */
        "jne .Lf21c02_00021c4a\n"
        "movl 0x1c(%ebp), %edx\n" /* Pointer */
        "cmpl 0x14(%esi), %edx\n" /* ta */
        "jne .Lf21c02_00021c4a\n"
        "jmp .Lf21c02_00021c87\n"
    );
}

/* line 672 */
__attribute__((naked))
unsigned int COpenGL_DisableTexCoordArray(const COpenGL * _this, UINT32 Unit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 672 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Unit */
        /* { scope 1 */
        "leal (%edx, %edx, 8), %eax\n" /* line 654 */
        "leal (%edx, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "addl 0x65c(%ecx), %ebx\n"
        "leal 0x104(%ebx), %esi\n" /* line 150 */
        "movzbl 5(%esi), %eax\n" /* line 42 */
        "cmpb $0, 4(%esi)\n" /* line 680 | ta */
        "jne .Lf21cec_00021d1d\n"
        "testb %al, %al\n"
        "je .Lf21cec_00021d3f\n"
        ".Lf21cec_00021d1d:\n"
        "cmpl 8(%ecx), %edx\n" /* line 368 */
        "je .Lf21cec_00021d33\n"
        "movl %edx, 8(%ecx)\n" /* line 370 */
        "leal 0x84c0(%edx), %eax\n" /* line 371 */
        "movl %eax, (%esp)\n"
        "calll glClientActiveTextureARB\n"
        ".Lf21cec_00021d33:\n"
        "movl 0x104(%ebx), %eax\n" /* line 683 */
        "movl %esi, (%esp)\n" /* ta */
        "calll *0xc(%eax)\n"
        ".Lf21cec_00021d3f:\n"
        "movb $0, 5(%esi)\n" /* line 35 */
        /* } scope */
        "addl $0x10, %esp\n" /* line 686 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 720 */
__attribute__((naked))
unsigned int COpenGL_SetTexMatrix(const COpenGL * _this, UINT32 Unit, const float *m)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 720 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x1c(%ebp)\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %ebx\n" /* m */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %edi\n"
        "shll $4, %edi\n"
        "movl %edi, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "addl 0x65c(%edx), %eax\n"
        "movl %ebx, 4(%esp)\n" /* line 725 | m */
        "addl $0xc4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_AreMatricesDifferent4x4\n"
        "testb %al, %al\n"
        "je .Lf21d4c_00021e53\n"
        "movl -0x1c(%ebp), %eax\n" /* line 382 | this */
        "cmpl 4(%eax), %esi\n"
        "je .Lf21d4c_00021e4c\n"
        "movl %esi, 4(%eax)\n" /* line 384 */
        "leal 0x84c0(%esi), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf21d4c_00021dae:\n"
        "cmpl $0x1702, 0x74(%edx)\n" /* line 427 */
        "je .Lf21d4c_00021dcd\n"
        "movl $0x1702, 0x74(%edx)\n" /* line 429 */
        "movl $0x1702, (%esp)\n" /* line 430 */
        "calll glMatrixMode\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf21d4c_00021dcd:\n"
        "movl %edi, %eax\n" /* line 654 */
        "addl 0x65c(%edx), %eax\n"
        "leal 0xc4(%eax), %edx\n" /* line 143 */
        "movl (%ebx), %ecx\n"
        "movl %ecx, 0xc4(%eax)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%ebx), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 0x14(%ebx), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl 0x18(%ebx), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 0x1c(%ebx), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x20(%ebx), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl 0x24(%ebx), %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl 0x28(%ebx), %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "movl 0x2c(%ebx), %eax\n"
        "movl %eax, 0x2c(%edx)\n"
        "movl 0x30(%ebx), %eax\n"
        "movl %eax, 0x30(%edx)\n"
        "movl 0x34(%ebx), %eax\n"
        "movl %eax, 0x34(%edx)\n"
        "movl 0x38(%ebx), %eax\n"
        "movl %eax, 0x38(%edx)\n"
        "movl 0x3c(%ebx), %eax\n"
        "movl %eax, 0x3c(%edx)\n"
        "movl %ebx, 8(%ebp)\n" /* line 144 | this */
        "addl $0x2c, %esp\n" /* line 731 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp glLoadMatrixf\n" /* line 144 */
        ".Lf21d4c_00021e4c:\n"
        "movl %eax, %edx\n"
        "jmp .Lf21d4c_00021dae\n"
        ".Lf21d4c_00021e53:\n"
        "addl $0x2c, %esp\n" /* line 731 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 736 */
__attribute__((naked))
unsigned int COpenGL_SetTexMatrixIdentity(const COpenGL * _this, UINT32 Unit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 736 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x1c(%ebp)\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* Unit */
        "leal (%ebx, %ebx, 8), %eax\n" /* line 654 */
        "leal (%ebx, %eax, 2), %edi\n"
        "shll $4, %edi\n"
        "movl %edi, %eax\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "addl 0x65c(%edx), %eax\n"
        "movl imp___ZN13COpenGLMatrix9sIdentityE, %esi\n" /* line 741 */
        "movl %esi, 4(%esp)\n"
        "addl $0xc4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_AreMatricesDifferent4x4\n"
        "testb %al, %al\n"
        "je .Lf21e5c_00021f63\n"
        "movl -0x1c(%ebp), %eax\n" /* line 382 | this */
        "cmpl 4(%eax), %ebx\n"
        "je .Lf21e5c_00021f5c\n"
        "movl %ebx, 4(%eax)\n" /* line 384 */
        "leal 0x84c0(%ebx), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf21e5c_00021ec1:\n"
        "cmpl $0x1702, 0x74(%edx)\n" /* line 427 */
        "je .Lf21e5c_00021ee0\n"
        "movl $0x1702, 0x74(%edx)\n" /* line 429 */
        "movl $0x1702, (%esp)\n" /* line 430 */
        "calll glMatrixMode\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf21e5c_00021ee0:\n"
        "movl %edi, %eax\n" /* line 654 */
        "addl 0x65c(%edx), %eax\n"
        "leal 0xc4(%eax), %edx\n" /* line 155 */
        "movl (%esi), %ecx\n"
        "movl %ecx, 0xc4(%eax)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%esi), %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl 0x18(%esi), %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl 0x1c(%esi), %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x20(%esi), %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl 0x24(%esi), %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl 0x28(%esi), %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "movl 0x2c(%esi), %eax\n"
        "movl %eax, 0x2c(%edx)\n"
        "movl 0x30(%esi), %eax\n"
        "movl %eax, 0x30(%edx)\n"
        "movl 0x34(%esi), %eax\n"
        "movl %eax, 0x34(%edx)\n"
        "movl 0x38(%esi), %eax\n"
        "movl %eax, 0x38(%edx)\n"
        "movl 0x3c(%esi), %eax\n"
        "movl %eax, 0x3c(%edx)\n"
        "addl $0x2c, %esp\n" /* line 747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp glLoadIdentity\n" /* line 156 */
        ".Lf21e5c_00021f5c:\n"
        "movl %eax, %edx\n"
        "jmp .Lf21e5c_00021ec1\n"
        ".Lf21e5c_00021f63:\n"
        "addl $0x2c, %esp\n" /* line 747 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1963 */
__attribute__((naked))
unsigned int COpenGL_Shutdown(const COpenGL * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1963 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "calll glFinish\n" /* line 1967 */
        "calll CMemoryBuffer_Reset\n" /* line 1969 */
        "xorl %ebx, %ebx\n"
        "leal 0x65c(%edi), %esi\n" /* this */
        "movl 0x65c(%edi), %ecx\n" /* this */
        /* { scope 1 */
        "movl 4(%esi), %eax\n" /* line 361 */
        "subl %ecx, %eax\n" /* line 1979 */
        "sarl $4, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "addl %eax, %edx\n"
        "negl %edx\n"
        "cmpl %edx, %ebx\n" /* i */
        "jae .Lf21f6c_00021ff3\n"
        ".Lf21f6c_00021fb2:\n"
        "cmpl 4(%edi), %ebx\n" /* line 382 */
        "je .Lf21f6c_00021fce\n"
        "movl %ebx, 4(%edi)\n" /* line 384 */
        "leal 0x84c0(%ebx), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl 0x65c(%edi), %ecx\n"
        ".Lf21f6c_00021fce:\n"
        "addl $1, %ebx\n" /* line 1979 | i */
        "movl 4(%esi), %eax\n" /* line 361 */
        "subl %ecx, %eax\n" /* line 1979 */
        "sarl $4, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "addl %eax, %edx\n"
        "negl %edx\n"
        "cmpl %edx, %ebx\n" /* i */
        "jb .Lf21f6c_00021fb2\n"
        /* } scope */
        ".Lf21f6c_00021ff3:\n"
        "leal 0x66c(%edi), %eax\n" /* line 1996 | this */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x66c(%edi), %esi\n" /* line 580 */
        "cmpl %eax, %esi\n" /* line 1996 */
        "je .Lf21f6c_00022026\n"
        /* { scope 1 */
        ".Lf21f6c_00022006:\n"
        "movl 8(%esi), %ebx\n" /* line 1998 | TexID */
        "movl %ebx, 4(%esp)\n" /* line 1999 | TexID */
        "movl $1, (%esp)\n"
        "calll glDeleteTextures\n"
        "movl $0, (%ebx)\n" /* line 2000 | TexID */
        /* } scope */
        "movl (%esi), %esi\n" /* line 140 */
        "cmpl -0x20(%ebp), %esi\n" /* line 1996 */
        "jne .Lf21f6c_00022006\n"
        ".Lf21f6c_00022026:\n"
        "leal 0x674(%edi), %eax\n" /* line 2006 | this */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x674(%edi), %eax\n" /* line 580 */
        "cmpl -0x1c(%ebp), %eax\n" /* line 2006 */
        "je .Lf21f6c_00022060\n"
        "movl %eax, %esi\n"
        "jmp .Lf21f6c_00022040\n"
        ".Lf21f6c_0002203e:\n"
        "movl %esi, %eax\n"
        /* { scope 1 */
        ".Lf21f6c_00022040:\n"
        "movl 8(%eax), %ebx\n" /* line 2008 | VAOID */
        "movl %ebx, 4(%esp)\n" /* line 2009 | VAOID */
        "movl $1, (%esp)\n"
        "calll glDeleteVertexArraysAPPLE\n"
        "movl $0, (%ebx)\n" /* line 2010 | VAOID */
        /* } scope */
        "movl (%esi), %esi\n" /* line 140 */
        "cmpl -0x1c(%ebp), %esi\n" /* line 2006 */
        "jne .Lf21f6c_0002203e\n"
        ".Lf21f6c_00022060:\n"
        "calll CVAOPacket_Shutdown\n" /* line 2013 */
        "calll CFence_Shutdown\n" /* line 2015 */
        "cmpb $0, 0x668(%edi)\n" /* line 2017 | this */
        "je .Lf21f6c_000220a1\n"
        "movl $0x851d, (%esp)\n" /* line 2020 */
        "calll glDisableClientState\n"
        "movl $0, 4(%esp)\n" /* line 2021 */
        "movl $0, (%esp)\n"
        "calll glVertexArrayRangeAPPLE\n"
        "movl $0, 0xc(%edi)\n" /* line 2023 | this */
        "movl $0, 0x10(%edi)\n" /* line 2024 | this */
        ".Lf21f6c_000220a1:\n"
        "addl $0x2c, %esp\n" /* line 2026 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2031 */
__attribute__((naked))
unsigned int COpenGL_SetTexGenEnable(const COpenGL * _this, UINT32 Unit, int Enable, int EnableReflection, int EnableNormalMap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2031 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x28(%ebp)\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Unit, EnableReflection */
        "movl %edx, -0x2c(%ebp)\n" /* EnableReflection, Unit */
        "movzbl 0x14(%ebp), %edx\n" /* EnableReflection */
        "movzbl 0x18(%ebp), %ecx\n" /* EnableNormalMap */
        /* { scope 1 */
        "movl -0x2c(%ebp), %ebx\n" /* line 654 | Unit */
        "leal (%ebx, %ebx, 8), %eax\n"
        "leal (%ebx, %eax, 2), %edi\n"
        "shll $4, %edi\n"
        "movl -0x28(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %edi\n"
        "cmpb $0, 0x10(%ebp)\n" /* line 2037 | Enable */
        "je .Lf220aa_000221e1\n"
        "testb %dl, %dl\n" /* line 2039 */
        "je .Lf220aa_00022241\n"
        "movl %edi, %esi\n"
        "movl %edi, -0x24(%ebp)\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl -0x2c(%ebp), %edx\n" /* Unit */
        "addl $0x84c0, %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        ".Lf220aa_00022101:\n"
        "cmpb $0, 0x11c(%ebx, %edi)\n" /* line 2048 | i */
        "jne .Lf220aa_0002213c\n"
        "movl -0x2c(%ebp), %eax\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %edx\n" /* this */
        "cmpl 4(%edx), %eax\n"
        "je .Lf220aa_00022124\n"
        "movl %eax, 4(%edx)\n" /* line 384 */
        "movl -0x30(%ebp), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_00022124:\n"
        "movl -0x24(%ebp), %edx\n" /* line 200 */
        "movb $1, 0x11c(%edx)\n"
        "leal 0xc60(%ebx), %eax\n" /* line 201 */
        "movl %eax, (%esp)\n"
        "calll glEnable\n"
        ".Lf220aa_0002213c:\n"
        "cmpl $0x8512, 0x120(%edi, %ebx, 4)\n" /* line 2053 */
        "je .Lf220aa_0002218a\n"
        "movl -0x2c(%ebp), %eax\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %edx\n" /* this */
        "cmpl 4(%edx), %eax\n"
        "je .Lf220aa_00022162\n"
        "movl %eax, 4(%edx)\n" /* line 384 */
        "movl -0x30(%ebp), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_00022162:\n"
        "movl $0x8512, 0x120(%esi)\n" /* line 210 */
        "movl $0x8512, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "leal 0x2000(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll glTexGeni\n"
        ".Lf220aa_0002218a:\n"
        "addl $1, %ebx\n" /* line 2046 | i */
        "addl $4, %esi\n"
        "addl $1, -0x24(%ebp)\n"
        "cmpl $3, %ebx\n" /* i */
        "jne .Lf220aa_00022101\n"
        "cmpb $0, 0x11f(%edi)\n" /* line 2063 */
        "je .Lf220aa_00022239\n"
        "movl -0x2c(%ebp), %edx\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %ebx\n" /* this */
        "cmpl 4(%ebx), %edx\n"
        "je .Lf220aa_000221c7\n"
        "movl %edx, 4(%ebx)\n" /* line 384 */
        "movl %edx, %eax\n" /* line 385 */
        "addl $0x84c0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_000221c7:\n"
        "movb $0, 0x11f(%edi)\n" /* line 205 */
        "movl $0xc63, 8(%ebp)\n" /* line 206 | this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp glDisable\n" /* line 206 */
        ".Lf220aa_000221e1:\n"
        "cmpb $0, 0x11c(%edi)\n" /* line 2119 */
        "je .Lf220aa_00022300\n"
        ".Lf220aa_000221ee:\n"
        "movl %edi, %ebx\n" /* i */
        "xorl %esi, %esi\n"
        ".Lf220aa_000221f2:\n"
        "cmpb $0, 0x11c(%esi, %edi)\n" /* line 2125 */
        "je .Lf220aa_0002222e\n"
        "movl -0x2c(%ebp), %edx\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %eax\n" /* this */
        "cmpl 4(%eax), %edx\n"
        "je .Lf220aa_00022219\n"
        "movl %edx, 4(%eax)\n" /* line 384 */
        "movl %edx, %eax\n" /* line 385 */
        "addl $0x84c0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_00022219:\n"
        "movb $0, 0x11c(%ebx)\n" /* line 205 */
        "leal 0xc60(%esi), %eax\n" /* line 206 */
        "movl %eax, (%esp)\n"
        "calll glDisable\n"
        ".Lf220aa_0002222e:\n"
        "addl $1, %esi\n" /* line 2123 */
        "addl $1, %ebx\n" /* i */
        "cmpl $4, %esi\n"
        "jne .Lf220aa_000221f2\n"
        /* } scope */
        ".Lf220aa_00022239:\n"
        "addl $0x3c, %esp\n" /* line 2133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf220aa_00022241:\n"
        "testb %cl, %cl\n" /* line 2071 */
        "jne .Lf220aa_0002232c\n"
        "movl %edi, %esi\n" /* line 206 */
        "movl %edi, -0x1c(%ebp)\n"
        "xorl %ebx, %ebx\n"
        "movl -0x2c(%ebp), %edx\n" /* Unit */
        "addl $0x84c0, %edx\n"
        "movl %edx, -0x38(%ebp)\n"
        ".Lf220aa_0002225c:\n"
        "cmpb $0, 0x11c(%ebx, %edi)\n" /* line 2103 | i */
        "jne .Lf220aa_00022297\n"
        "movl -0x2c(%ebp), %eax\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %edx\n" /* this */
        "cmpl 4(%edx), %eax\n"
        "je .Lf220aa_0002227f\n"
        "movl %eax, 4(%edx)\n" /* line 384 */
        "movl -0x38(%ebp), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_0002227f:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 200 */
        "movb $1, 0x11c(%edx)\n"
        "leal 0xc60(%ebx), %eax\n" /* line 201 */
        "movl %eax, (%esp)\n"
        "calll glEnable\n"
        ".Lf220aa_00022297:\n"
        "cmpl $0x2401, 0x120(%edi, %ebx, 4)\n" /* line 2108 */
        "je .Lf220aa_000222e5\n"
        "movl -0x2c(%ebp), %eax\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %edx\n" /* this */
        "cmpl 4(%edx), %eax\n"
        "je .Lf220aa_000222bd\n"
        "movl %eax, 4(%edx)\n" /* line 384 */
        "movl -0x38(%ebp), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_000222bd:\n"
        "movl $0x2401, 0x120(%esi)\n" /* line 210 */
        "movl $0x2401, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "leal 0x2000(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll glTexGeni\n"
        ".Lf220aa_000222e5:\n"
        "addl $1, %ebx\n" /* line 2101 | i */
        "addl $4, %esi\n"
        "addl $1, -0x1c(%ebp)\n"
        "cmpl $4, %ebx\n" /* i */
        "jne .Lf220aa_0002225c\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 2133 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf220aa_00022300:\n"
        "cmpb $0, 0x11d(%edi)\n" /* line 2119 */
        "jne .Lf220aa_000221ee\n"
        "cmpb $0, 0x11e(%edi)\n"
        "jne .Lf220aa_000221ee\n"
        "cmpb $0, 0x11f(%edi)\n"
        "jne .Lf220aa_000221ee\n"
        "jmp .Lf220aa_00022239\n"
        ".Lf220aa_0002232c:\n"
        "movl %edi, %esi\n" /* line 2071 */
        "movl %edi, -0x20(%ebp)\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl -0x2c(%ebp), %eax\n" /* Unit */
        "addl $0x84c0, %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        ".Lf220aa_0002233e:\n"
        "cmpb $0, 0x11c(%ebx, %edi)\n" /* line 2075 | i */
        "jne .Lf220aa_00022379\n"
        "movl -0x2c(%ebp), %edx\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %eax\n" /* this */
        "cmpl 4(%eax), %edx\n"
        "je .Lf220aa_00022361\n"
        "movl %edx, 4(%eax)\n" /* line 384 */
        "movl -0x34(%ebp), %edx\n" /* line 385 */
        "movl %edx, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_00022361:\n"
        "movl -0x20(%ebp), %eax\n" /* line 200 */
        "movb $1, 0x11c(%eax)\n"
        "leal 0xc60(%ebx), %eax\n" /* line 201 */
        "movl %eax, (%esp)\n"
        "calll glEnable\n"
        ".Lf220aa_00022379:\n"
        "cmpl $0x8511, 0x120(%edi, %ebx, 4)\n" /* line 2080 */
        "je .Lf220aa_000223c7\n"
        "movl -0x2c(%ebp), %edx\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %eax\n" /* this */
        "cmpl 4(%eax), %edx\n"
        "je .Lf220aa_0002239f\n"
        "movl %edx, 4(%eax)\n" /* line 384 */
        "movl -0x34(%ebp), %edx\n" /* line 385 */
        "movl %edx, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf220aa_0002239f:\n"
        "movl $0x8511, 0x120(%esi)\n" /* line 210 */
        "movl $0x8511, 8(%esp)\n" /* line 211 */
        "movl $0x2500, 4(%esp)\n"
        "leal 0x2000(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll glTexGeni\n"
        ".Lf220aa_000223c7:\n"
        "addl $1, %ebx\n" /* line 2073 | i */
        "addl $4, %esi\n"
        "addl $1, -0x20(%ebp)\n"
        "cmpl $3, %ebx\n" /* i */
        "jne .Lf220aa_0002233e\n"
        "cmpb $0, 0x11f(%edi)\n" /* line 2090 */
        "je .Lf220aa_00022239\n"
        "movl -0x2c(%ebp), %ebx\n" /* line 382 | Unit */
        "movl -0x28(%ebp), %eax\n" /* this */
        "cmpl 4(%eax), %ebx\n"
        "je .Lf220aa_000221c7\n"
        "movl %ebx, 4(%eax)\n" /* line 384 */
        "movl %ebx, %eax\n" /* line 385 */
        "addl $0x84c0, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "jmp .Lf220aa_000221c7\n"
    );
}

/* line 2138 */
__attribute__((naked))
unsigned int COpenGL_DisableTexUnit(const COpenGL * _this, UINT32 Unit)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2138 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "addl 0x65c(%edi), %ebx\n"
        "cmpb $0, 1(%ebx)\n" /* line 2145 */
        "je .Lf2240e_00022458\n"
        "cmpl 4(%edi), %esi\n" /* line 382 */
        "je .Lf2240e_00022448\n"
        "movl %esi, 4(%edi)\n" /* line 384 */
        "leal 0x84c0(%esi), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf2240e_00022448:\n"
        "movl $0xde1, (%esp)\n" /* line 2148 */
        "calll glDisable\n"
        "movb $0, 1(%ebx)\n" /* line 2149 */
        ".Lf2240e_00022458:\n"
        "cmpb $0, 2(%ebx)\n" /* line 2151 */
        "je .Lf2240e_00022484\n"
        "cmpl 4(%edi), %esi\n" /* line 382 */
        "je .Lf2240e_00022474\n"
        "movl %esi, 4(%edi)\n" /* line 384 */
        "leal 0x84c0(%esi), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf2240e_00022474:\n"
        "movl $0x806f, (%esp)\n" /* line 2154 */
        "calll glDisable\n"
        "movb $0, 2(%ebx)\n" /* line 2155 */
        ".Lf2240e_00022484:\n"
        "cmpb $0, 3(%ebx)\n" /* line 2157 */
        "je .Lf2240e_000224b0\n"
        "cmpl 4(%edi), %esi\n" /* line 382 */
        "je .Lf2240e_000224a0\n"
        "movl %esi, 4(%edi)\n" /* line 384 */
        "leal 0x84c0(%esi), %eax\n" /* line 385 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf2240e_000224a0:\n"
        "movl $0x8513, (%esp)\n" /* line 2160 */
        "calll glDisable\n"
        "movb $0, 3(%ebx)\n" /* line 2161 */
        ".Lf2240e_000224b0:\n"
        "addl $0x1c, %esp\n" /* line 2169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1096 */
__attribute__((naked))
unsigned int COpenGL_ReleaseVAOBinding(const COpenGL * _this, const GLuint * TexID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1096 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* TexID */
        "leal 0x674(%eax), %edi\n" /* line 1101 */
        "movl 0x674(%eax), %eax\n" /* line 580 */
        "movl %eax, %ebx\n" /* line 1101 */
        "cmpl %edi, %eax\n"
        "je .Lf224b8_0002251a\n"
        "movl %eax, %esi\n" /* line 131 */
        "movl (%ecx), %edx\n" /* line 1103 */
        "movl 8(%eax), %eax\n"
        "cmpl %edx, (%eax)\n"
        "je .Lf224b8_000224f3\n"
        ".Lf224b8_000224e4:\n"
        "movl (%ebx), %ebx\n" /* line 140 */
        "cmpl %edi, %ebx\n" /* line 1101 */
        "je .Lf224b8_0002251a\n"
        "movl %ebx, %esi\n" /* line 131 */
        "movl 8(%ebx), %eax\n" /* line 1103 */
        "cmpl %edx, (%eax)\n"
        "jne .Lf224b8_000224e4\n"
        ".Lf224b8_000224f3:\n"
        "movl %ecx, 4(%esp)\n" /* line 1105 */
        "movl $1, (%esp)\n"
        "calll glDeleteVertexArraysAPPLE\n"
        "movl 8(%esi), %eax\n" /* line 1106 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl %ebx, 4(%esp)\n" /* line 1107 */
        "movl %edi, (%esp)\n"
        "calll ZNSt4listIPmSaIS0_EE5eraseESt14_List_iteratorIS0_E\n"
        ".Lf224b8_0002251a:\n"
        "addl $0x1c, %esp\n" /* line 1115 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1072 */
__attribute__((naked))
unsigned int COpenGL_ReleaseTextureBinding(const COpenGL * _this, const GLuint * TexID)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1072 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* TexID */
        "leal 0x66c(%eax), %edi\n" /* line 1077 */
        "movl 0x66c(%eax), %eax\n" /* line 580 */
        "movl %eax, %ebx\n" /* line 1077 */
        "cmpl %edi, %eax\n"
        "je .Lf22522_00022584\n"
        "movl %eax, %esi\n" /* line 131 */
        "movl (%ecx), %edx\n" /* line 1079 */
        "movl 8(%eax), %eax\n"
        "cmpl %edx, (%eax)\n"
        "je .Lf22522_0002255d\n"
        ".Lf22522_0002254e:\n"
        "movl (%ebx), %ebx\n" /* line 140 */
        "cmpl %edi, %ebx\n" /* line 1077 */
        "je .Lf22522_00022584\n"
        "movl %ebx, %esi\n" /* line 131 */
        "movl 8(%ebx), %eax\n" /* line 1079 */
        "cmpl %edx, (%eax)\n"
        "jne .Lf22522_0002254e\n"
        ".Lf22522_0002255d:\n"
        "movl %ecx, 4(%esp)\n" /* line 1081 */
        "movl $1, (%esp)\n"
        "calll glDeleteTextures\n"
        "movl 8(%esi), %eax\n" /* line 1082 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        "movl %ebx, 4(%esp)\n" /* line 1083 */
        "movl %edi, (%esp)\n"
        "calll ZNSt4listIPmSaIS0_EE5eraseESt14_List_iteratorIS0_E\n"
        ".Lf22522_00022584:\n"
        "addl $0x1c, %esp\n" /* line 1091 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1530 */
__attribute__((naked))
unsigned int COpenGL_Init(const COpenGL * _this, UINT32 Buffers, UINT32 MaxTextureUnits, UINT32 MaxTextureImageUnits)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1530 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1cc, %esp\n"
        /* { scope 1 */
        "movl $0, __ZN7COpenGL11sFrameCountE\n" /* line 670 */
        "movl $str_00215c34, (%esp)\n" /* line 1541 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movb %al, 0x809(%edx)\n"
        "movl $str_00215c4c, (%esp)\n" /* line 1542 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movb %al, 0x80a(%ecx)\n"
        "movl $str_00215c60, (%esp)\n" /* line 1543 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movb %al, 0x800(%edx)\n"
        "movb $0, 0x801(%edx)\n" /* line 1544 */
        "movl $str_00215984, (%esp)\n" /* line 1545 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movb %al, 0x80b(%ecx)\n"
        "movl $str_00215c84, (%esp)\n" /* line 1547 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movb %al, 0x80c(%edx)\n"
        "movl $str_002159a0, (%esp)\n" /* line 1549 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movb %al, 0x802(%ecx)\n"
        "testb %al, %al\n" /* line 1550 */
        "jne .Lf2258c_000231a6\n"
        ".Lf2258c_0002262f:\n"
        "movl $str_00215c98, (%esp)\n" /* line 1554 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movb %al, 0x808(%edx)\n"
        "movl $str_00215cb0, (%esp)\n" /* line 1560 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "testb %al, %al\n"
        "jne .Lf2258c_00023159\n"
        ".Lf2258c_00022658:\n"
        "xorl %eax, %eax\n"
        ".Lf2258c_0002265a:\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movb %al, 0x668(%ecx)\n"
        "movl $0, 0xc(%ecx)\n" /* line 1603 */
        "movl $0, 0x10(%ecx)\n" /* line 1604 */
        "cmpb $0, 0x800(%ecx)\n" /* line 1606 */
        "jne .Lf2258c_00023266\n"
        ".Lf2258c_0002267e:\n"
        "movl 8(%ebp), %eax\n" /* line 1612 | this */
        "cmpb $0, 0x668(%eax)\n"
        "jne .Lf2258c_0002322d\n"
        ".Lf2258c_0002268e:\n"
        "movl $1, 4(%esp)\n" /* line 1623 */
        "movl $0xcf5, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $1, 4(%esp)\n" /* line 1624 */
        "movl $0xd05, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $0, 4(%esp)\n" /* line 1632 */
        "movl $0x85b2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $0xbc0, (%esp)\n" /* line 1636 */
        "calll glDisable\n"
        "movl $0, 4(%esp)\n" /* line 1637 */
        "movl $0x207, (%esp)\n"
        "calll glAlphaFunc\n"
        "movl $0, 4(%esp)\n" /* line 1639 */
        "movl $1, (%esp)\n"
        "calll glBlendFunc\n"
        "movl 8(%ebp), %ecx\n" /* line 1640 | this */
        "movl $1, 0x824(%ecx)\n"
        "movl $0, 0x828(%ecx)\n" /* line 1641 */
        "movl $1, 0x82c(%ecx)\n" /* line 1642 */
        "movl $0, 0x830(%ecx)\n" /* line 1643 */
        "leal -0x1c(%ebp), %eax\n" /* line 1648 | Count */
        "movl %eax, 4(%esp)\n"
        "movl $0xd32, (%esp)\n"
        "calll glGetIntegerv\n"
        "pxor %xmm0, %xmm0\n" /* line 1651 */
        "movsd %xmm0, -0x70(%ebp)\n" /* Zero */
        "movsd %xmm0, -0x68(%ebp)\n"
        "movsd %xmm0, -0x60(%ebp)\n"
        "movsd %xmm0, -0x58(%ebp)\n"
        /* { scope 2: NextUnit */
        "movl -0x1c(%ebp), %eax\n" /* line 1652 | Count */
        "testl %eax, %eax\n"
        "jg .Lf2258c_00023201\n"
        /* } scope */
        ".Lf2258c_0002275f:\n"
        "movl $1, 0xc(%esp)\n" /* line 1660 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl $0x3f800000, %eax\n" /* line 1661 */
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glColor4f\n"
        "movl 8(%ebp), %edx\n" /* line 1663 | this */
        "cmpb $0, 0x809(%edx)\n"
        "jne .Lf2258c_00022a48\n"
        "cmpb $0, 0x80a(%edx)\n"
        "jne .Lf2258c_00022a48\n"
        ".Lf2258c_000227b9:\n"
        "movl $0xb44, (%esp)\n" /* line 1670 */
        "calll glDisable\n"
        "movl $0xb71, (%esp)\n" /* line 1673 */
        "calll glEnable\n"
        "movl $0x203, (%esp)\n" /* line 1674 */
        "calll glDepthFunc\n"
        "movl $1, (%esp)\n" /* line 1675 */
        "calll glDepthMask\n"
        "movl $0, 8(%esp)\n" /* line 1676 */
        "movl $0x3ff00000, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $0, 4(%esp)\n"
        "calll glDepthRange\n"
        "movl $0xbd0, (%esp)\n" /* line 1679 */
        "calll glDisable\n"
        "xorl %eax, %eax\n" /* line 1680 */
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glClearColor\n"
        "movl $0x409, (%esp)\n" /* line 1681 */
        "calll glDrawBuffer\n"
        "movl $0x4000, (%esp)\n" /* line 1682 */
        "calll glClear\n"
        "movl $0x40a, (%esp)\n" /* line 1683 */
        "calll glDrawBuffer\n"
        "movl $0x4000, (%esp)\n" /* line 1684 */
        "calll glClear\n"
        "movl $0x405, (%esp)\n" /* line 1687 */
        "calll glDrawBuffer\n"
        "movl $0x4000, (%esp)\n" /* line 1688 */
        "calll glClear\n"
        "calll MacDisplay_IsFullscreen\n" /* line 1689 */
        "testb %al, %al\n"
        "jne .Lf2258c_000231e4\n"
        ".Lf2258c_00022884:\n"
        "xorl %eax, %eax\n" /* line 1696 */
        "cmpl $1, 0xc(%ebp)\n" /* Buffers */
        "setne %al\n"
        "addl $0x404, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glDrawBuffer\n"
        "movl $0xd80, (%esp)\n" /* line 1700 */
        "calll glDisable\n"
        "movl $0xbe2, (%esp)\n" /* line 1701 */
        "calll glDisable\n"
        "movl $0xbf2, (%esp)\n" /* line 1702 */
        "calll glDisable\n"
        "movl 8(%ebp), %ecx\n" /* line 1704 | this */
        "movb $0, 0xb8(%ecx)\n"
        "movl $0xbd0, (%esp)\n" /* line 1705 */
        "calll glDisable\n"
        "movl $0xb60, (%esp)\n" /* line 1707 */
        "calll glDisable\n"
        "movl $0x2601, 4(%esp)\n" /* line 1708 */
        "movl $0xb65, (%esp)\n"
        "calll glFogi\n"
        "movl $0xbf1, (%esp)\n" /* line 1710 */
        "calll glDisable\n"
        "movl 8(%ebp), %eax\n" /* line 1714 | this */
        "cmpb $0, 0x800(%eax)\n"
        "je .Lf2258c_000231d3\n"
        ".Lf2258c_00022910:\n"
        "leal -0x1c(%ebp), %edx\n" /* line 1719 | Count */
        "movl %edx, 4(%esp)\n"
        "movl $0xd31, (%esp)\n"
        "calll glGetIntegerv\n"
        "xorl %esi, %esi\n" /* i */
        "movl 8(%ebp), %ebx\n" /* this */
        "addl $0xb0, %ebx\n"
        "jmp .Lf2258c_000229c1\n"
        /* { scope 2: NextUnit */
        /* { scope 3 */
        ".Lf2258c_00022933:\n"
        "movl $0x3f800000, 0x18(%ebx)\n" /* line 64 */
        "movl $0x3f800000, 0x1c(%ebx)\n"
        "movl $0x3f800000, 0x20(%ebx)\n"
        "movl $0x3f800000, 0x24(%ebx)\n"
        "leal 0x1c(%edi), %eax\n" /* line 1726 | l, this */
        "testl %esi, %esi\n" /* i */
        "jne .Lf2258c_00022a27\n"
        ".Lf2258c_0002295a:\n"
        "movl $0x3f800000, 0x28(%ebx)\n" /* line 64 */
        "movl $0x3f800000, 0x2c(%ebx)\n"
        "movl $0x3f800000, 0x30(%ebx)\n"
        "movl $0x3f800000, 0x34(%ebx)\n"
        ".Lf2258c_00022976:\n"
        "movl $0, 0x6c(%ebx)\n" /* line 1727 */
        "movl $0x43340000, 0x70(%ebx)\n" /* line 1728 */
        "movl $0x3f800000, 0x80(%ebx)\n" /* line 1729 */
        "leal 0x4000(%esi), %eax\n" /* line 1730 | i */
        "movl %eax, (%esp)\n"
        "calll glDisable\n"
        "movl %edi, 8(%esp)\n" /* line 1731 | l */
        "movl %esi, 4(%esp)\n" /* i */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %ecx, (%esp)\n"
        "calll COpenGL_SetLight\n"
        /* } scope */
        "addl $1, %esi\n" /* line 1720 | i */
        "addl $0xb4, %ebx\n"
        "cmpl $8, %esi\n" /* i */
        "je .Lf2258c_00022a59\n"
        /* { scope 3 */
        ".Lf2258c_000229c1:\n"
        "leal 0xc(%ebx), %edi\n" /* line 1722 | l */
        "movl $0xb4, 8(%esp)\n" /* line 1723 */
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* l */
        "calll memset\n"
        "movl $0x3f800000, 0x44(%ebx)\n" /* line 1724 */
        "movl $0, 0x40(%ebx)\n"
        "movl $0, 0x3c(%ebx)\n"
        "movl $0, 0x38(%ebx)\n"
        "testl %esi, %esi\n" /* line 1725 | i */
        "je .Lf2258c_00022933\n"
        "movl $0, 0x18(%ebx)\n" /* line 64 */
        "movl $0, 0x1c(%ebx)\n"
        "movl $0, 0x20(%ebx)\n"
        "movl $0x3f800000, 0x24(%ebx)\n"
        "leal 0x1c(%edi), %eax\n" /* line 1726 | l, this */
        "testl %esi, %esi\n" /* i */
        "je .Lf2258c_0002295a\n"
        /* { scope 4 */
        ".Lf2258c_00022a27:\n"
        "movl $0, 0x28(%ebx)\n" /* line 64 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        "movl $0x3f800000, 0xc(%eax)\n"
        "jmp .Lf2258c_00022976\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf2258c_00022a48:\n"
        "movl $0x8006, (%esp)\n" /* line 1665 */
        "calll glBlendEquationEXT\n"
        "jmp .Lf2258c_000227b9\n"
        ".Lf2258c_00022a59:\n"
        "movl $0xb20, (%esp)\n" /* line 1736 */
        "calll glDisable\n"
        "movl $0xb24, (%esp)\n" /* line 1737 */
        "calll glDisable\n"
        "movl $0xd90, (%esp)\n" /* line 1741 */
        "calll glDisable\n"
        "movl $0xd91, (%esp)\n" /* line 1742 */
        "calll glDisable\n"
        "movl $0xd92, (%esp)\n" /* line 1743 */
        "calll glDisable\n"
        "movl $0xd93, (%esp)\n" /* line 1744 */
        "calll glDisable\n"
        "movl $0xd94, (%esp)\n" /* line 1745 */
        "calll glDisable\n"
        "movl $0xd95, (%esp)\n" /* line 1746 */
        "calll glDisable\n"
        "movl $0xd96, (%esp)\n" /* line 1747 */
        "calll glDisable\n"
        "movl $0xd97, (%esp)\n" /* line 1748 */
        "calll glDisable\n"
        "movl $0xd98, (%esp)\n" /* line 1749 */
        "calll glDisable\n"
        "movl $0xdb0, (%esp)\n" /* line 1750 */
        "calll glDisable\n"
        "movl $0xdb1, (%esp)\n" /* line 1751 */
        "calll glDisable\n"
        "movl $0xdb2, (%esp)\n" /* line 1752 */
        "calll glDisable\n"
        "movl $0xdb3, (%esp)\n" /* line 1753 */
        "calll glDisable\n"
        "movl $0xdb4, (%esp)\n" /* line 1754 */
        "calll glDisable\n"
        "movl $0xdb5, (%esp)\n" /* line 1755 */
        "calll glDisable\n"
        "movl $0xdb6, (%esp)\n" /* line 1756 */
        "calll glDisable\n"
        "movl $0xdb7, (%esp)\n" /* line 1757 */
        "calll glDisable\n"
        "movl $0xdb8, (%esp)\n" /* line 1758 */
        "calll glDisable\n"
        "movl $0xba1, (%esp)\n" /* line 1762 */
        "calll glEnable\n"
        "movl $0xb10, (%esp)\n" /* line 1763 */
        "calll glDisable\n"
        "movl $0x8037, (%esp)\n" /* line 1765 */
        "calll glDisable\n"
        "movl $0, 4(%esp)\n" /* line 1766 */
        "movl $0, (%esp)\n"
        "calll glPolygonOffset\n"
        "movl 8(%ebp), %eax\n" /* line 1767 | this */
        "movb $0, 0x80f(%eax)\n"
        "movl $0x2a02, (%esp)\n" /* line 1769 */
        "calll glDisable\n"
        "movl $0x2a01, (%esp)\n" /* line 1770 */
        "calll glDisable\n"
        "movl $0xb41, (%esp)\n" /* line 1774 */
        "calll glDisable\n"
        "movl $0xb42, (%esp)\n" /* line 1775 */
        "calll glDisable\n"
        "movl $0xc11, (%esp)\n" /* line 1777 */
        "calll glDisable\n"
        "movl $0x1101, 4(%esp)\n" /* line 1781 */
        "movl $0xc54, (%esp)\n"
        "calll glHint\n"
        "movl $0x1101, 4(%esp)\n" /* line 1782 */
        "movl $0xc52, (%esp)\n"
        "calll glHint\n"
        "movl $0x1102, 4(%esp)\n" /* line 1783 */
        "movl $0xc50, (%esp)\n"
        "calll glHint\n"
        "movl $0x1101, 4(%esp)\n" /* line 1784 */
        "movl $0xc51, (%esp)\n"
        "calll glHint\n"
        "movl $0x1101, 4(%esp)\n" /* line 1785 */
        "movl $0xc53, (%esp)\n"
        "calll glHint\n"
        "movl $0, -0x2c(%ebp)\n" /* line 1791 | rgba */
        "movl $0, -0x28(%ebp)\n"
        "movl $0, -0x24(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        "leal -0x2c(%ebp), %eax\n" /* line 1792 | rgba */
        "movl %eax, 4(%esp)\n"
        "movl $0xb53, (%esp)\n"
        "calll glLightModelfv\n"
        "movl $0, 4(%esp)\n" /* line 1800 */
        "movl $0xb52, (%esp)\n"
        "calll glLightModeli\n"
        "movl $0x1700, (%esp)\n" /* line 1806 */
        "calll glMatrixMode\n"
        "movl 8(%ebp), %eax\n" /* line 1807 | this */
        "addl $0x78, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "calll glLoadIdentity\n" /* line 1808 */
        "movl $0x1701, (%esp)\n" /* line 1809 */
        "calll glMatrixMode\n"
        "calll glLoadIdentity\n" /* line 1811 */
        "movl $0, -0x3c(%ebp)\n" /* line 1815 | fZero */
        "movl $0, -0x38(%ebp)\n"
        "movl $0, -0x34(%ebp)\n"
        "movl $0, -0x30(%ebp)\n"
        "movl $0x3f800000, -0x4c(%ebp)\n" /* line 1816 | One */
        "movl $0x3f800000, -0x48(%ebp)\n"
        "movl $0x3f800000, -0x44(%ebp)\n"
        "movl $0x3f800000, -0x40(%ebp)\n"
        "leal -0x3c(%ebp), %esi\n" /* line 1817 | fZero, i */
        "movl %esi, 8(%esp)\n" /* i */
        "movl $0x1200, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "leal -0x4c(%ebp), %ebx\n" /* line 1818 | One */
        "movl %ebx, 8(%esp)\n"
        "movl $0x1201, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl %esi, 8(%esp)\n" /* line 1819 | i */
        "movl $0x1202, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl %ebx, 8(%esp)\n" /* line 1820 */
        "movl $0x1600, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl $0, 8(%esp)\n" /* line 1821 */
        "movl $0x1601, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialf\n"
        "movl $0x3f800000, (%esp)\n" /* line 1825 */
        "calll glPointSize\n"
        "movl $0x1b02, 4(%esp)\n" /* line 1827 */
        "movl $0x408, (%esp)\n"
        "calll glPolygonMode\n"
        "movl $0x1d01, (%esp)\n" /* line 1829 */
        "calll glShadeModel\n"
        "movl 8(%ebp), %edx\n" /* line 1835 | this */
        "movl $0, 4(%edx)\n"
        "movl $0x84c0, (%esp)\n" /* line 1836 */
        "calll glActiveTextureARB\n"
        "movl 8(%ebp), %ecx\n" /* line 1837 | this */
        "movl $0, 8(%ecx)\n"
        "movl $0x84c0, (%esp)\n" /* line 1838 */
        "calll glClientActiveTextureARB\n"
        "movl $0xb90, (%esp)\n" /* line 1841 */
        "calll glDisable\n"
        "movl 8(%ebp), %edi\n" /* line 1845 | this, l */
        "addl $0x65c, %edi\n" /* l */
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "addl $0x660, %eax\n"
        "movl %eax, -0x1b0(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x660(%edx), %eax\n"
        "movl 0x65c(%edx), %edx\n" /* line 334 */
        "movl %eax, 8(%esp)\n" /* line 749 */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_\n"
        /* { scope 2: NextUnit */
        "movl 0x10(%ebp), %eax\n" /* line 211 | MaxTextureUnits */
        "cmpl 0x14(%ebp), %eax\n" /* MaxTextureImageUnits */
        "jae .Lf2258c_00023151\n"
        "leal 0x14(%ebp), %eax\n" /* MaxTextureImageUnits */
        /* } scope */
        ".Lf2258c_00022e01:\n"
        "movl (%eax), %eax\n" /* line 1850 | __b */
        "movl %eax, -0x1b4(%ebp)\n" /* __b, NumTextureUnits */
        /* { scope 2: NextUnit */
        "testl %eax, %eax\n" /* line 1852 */
        "je .Lf2258c_00022f56\n"
        "xorl %esi, %esi\n" /* i */
        "movl $0x84c0, -0x1ac(%ebp)\n"
        "jmp .Lf2258c_00022f14\n"
        /* { scope 3 */
        ".Lf2258c_00022e22:\n"
        "movl 8(%ebp), %ecx\n" /* line 368 | this */
        "cmpl 8(%ecx), %esi\n"
        "je .Lf2258c_00022e3b\n"
        "movl %esi, 8(%ecx)\n" /* line 370 */
        "movl -0x1ac(%ebp), %eax\n" /* line 371 */
        "movl %eax, (%esp)\n"
        "calll glClientActiveTextureARB\n"
        ".Lf2258c_00022e3b:\n"
        "movl $0x1702, (%esp)\n" /* line 1861 */
        "calll glMatrixMode\n"
        "movl 8(%ebp), %edx\n" /* line 1862 | this */
        "movl $0x1702, 0x74(%edx)\n"
        ".Lf2258c_00022e51:\n"
        "leal -0x9c(%ebp), %eax\n" /* line 117 */
        "movl %eax, (%esp)\n"
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV14CTexCoordArray, %edx\n" /* i */
        "addl $8, %edx\n" /* i */
        "movl %edx, -0x1b8(%ebp)\n" /* i */
        "movl %edx, -0x9c(%ebp)\n" /* i */
        "movl %ebx, %eax\n" /* line 218 */
        "andl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movzbl 0x808(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl 0x802(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x1a0(%ebp), %eax\n" /* NextUnit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_CTexUnit_Reset\n"
        "movl 4(%edi), %ebx\n" /* line 604 */
        "cmpl 8(%edi), %ebx\n"
        "je .Lf2258c_0002312e\n"
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf2258c_00022eeb\n"
        "leal 0x104(%ebx), %eax\n" /* line 107 | this */
        /* { scope 4 */
        "movl %eax, (%esp)\n" /* line 117 */
        "calll CBaseVA_CBaseVA\n"
        "movl -0x1b8(%ebp), %edx\n" /* i */
        "movl %edx, 0x104(%ebx)\n" /* i */
        /* } scope */
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "leal -0x1a0(%ebp), %ecx\n" /* NextUnit */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl 4(%edi), %ebx\n"
        ".Lf2258c_00022eeb:\n"
        "leal 0x130(%ebx), %eax\n" /* line 607 */
        "movl %eax, 4(%edi)\n"
        ".Lf2258c_00022ef4:\n"
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 1852 | i */
        "addl $1, -0x1ac(%ebp)\n"
        "cmpl %esi, -0x1b4(%ebp)\n" /* i, NumTextureUnits */
        "je .Lf2258c_00022f56\n"
        /* { scope 3 */
        ".Lf2258c_00022f14:\n"
        "cmpl 0x10(%ebp), %esi\n" /* line 1854 | MaxTextureUnits, i */
        "setae %bl\n" /* IsProgramableOnly */
        "movl 8(%ebp), %eax\n" /* line 382 | this */
        "cmpl 4(%eax), %esi\n"
        "je .Lf2258c_00022f33\n"
        "movl %esi, 4(%eax)\n" /* line 384 */
        "movl -0x1ac(%ebp), %edx\n" /* line 385 */
        "movl %edx, (%esp)\n"
        "calll glActiveTextureARB\n"
        ".Lf2258c_00022f33:\n"
        "testb %bl, %bl\n" /* line 1858 | IsProgramableOnly */
        "je .Lf2258c_00022e22\n"
        "movl 8(%ebp), %ecx\n" /* line 1866 | this */
        "movl $0x1700, 0x74(%ecx)\n"
        "movl $0x1700, (%esp)\n" /* line 1867 */
        "calll glMatrixMode\n"
        "jmp .Lf2258c_00022e51\n"
        /* } scope */
        /* } scope */
        ".Lf2258c_00022f56:\n"
        "movl 8(%ebp), %ebx\n" /* line 1876 | this, IsProgramableOnly */
        "addl $0x14, %ebx\n" /* IsProgramableOnly */
        "movl %ebx, (%esp)\n" /* IsProgramableOnly */
        "calll CBaseVA_Reset\n"
        "movl %ebx, (%esp)\n" /* line 1877 | IsProgramableOnly */
        "calll CBaseVA_Force\n"
        "movl 8(%ebp), %ebx\n" /* line 1878 | this, IsProgramableOnly */
        "addl $0x2c, %ebx\n" /* IsProgramableOnly */
        "movl %ebx, (%esp)\n" /* IsProgramableOnly */
        "calll CBaseVA_Reset\n"
        "movl %ebx, (%esp)\n" /* line 1879 | IsProgramableOnly */
        "calll CBaseVA_Force\n"
        "movl 8(%ebp), %ebx\n" /* line 1880 | this, IsProgramableOnly */
        "addl $0x44, %ebx\n" /* IsProgramableOnly */
        "movl %ebx, (%esp)\n" /* IsProgramableOnly */
        "calll CBaseVA_Reset\n"
        "movl %ebx, (%esp)\n" /* line 1881 | IsProgramableOnly */
        "calll CBaseVA_Force\n"
        "movl 8(%ebp), %ebx\n" /* line 1882 | this, IsProgramableOnly */
        "addl $0x5c, %ebx\n" /* IsProgramableOnly */
        "movl %ebx, (%esp)\n" /* IsProgramableOnly */
        "calll CBaseVA_Reset\n"
        "movl %ebx, (%esp)\n" /* line 1883 | IsProgramableOnly */
        "calll CBaseVA_Force\n"
        "movl $0x8079, (%esp)\n" /* line 1888 */
        "calll glDisableClientState\n"
        "movl $0x8077, (%esp)\n" /* line 1889 */
        "calll glDisableClientState\n"
        "movl 8(%ebp), %eax\n" /* line 1891 | this */
        "movl $0x1700, 0x74(%eax)\n"
        "movl $0x1700, (%esp)\n" /* line 1892 */
        "calll glMatrixMode\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x60, %edx\n"
        ".Lf2258c_00022fe4:\n"
        "movl $1, 0x834(%eax)\n" /* line 1905 */
        "addl $0x14, %eax\n"
        "subl $1, %edx\n" /* line 1903 */
        "jne .Lf2258c_00022fe4\n"
        "movl $0xb57, (%esp)\n" /* line 1908 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* line 1909 | this */
        "movb $0, 0x80e(%edx)\n"
        "movb $0, 0x810(%edx)\n" /* line 1911 */
        "movl $0, 0x67c(%edx)\n" /* line 116 */
        "xorl %edx, %edx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "leal 0x67c(%ecx), %eax\n"
        /* { scope 2: NextUnit */
        ".Lf2258c_00023028:\n"
        "movb $1, 4(%eax)\n" /* line 95 */
        "movb $0, 5(%eax)\n" /* line 44 */
        "movl $4, 8(%eax)\n" /* line 45 */
        "movl $0x1406, 0xc(%eax)\n" /* line 46 */
        "movb $0, 0x10(%eax)\n" /* line 47 */
        "movl $0, 0x14(%eax)\n" /* line 48 */
        "movl $0, 0x18(%eax)\n" /* line 49 */
        "addl $1, %edx\n" /* line 117 | i */
        "addl $0x18, %eax\n"
        "cmpl $0x10, %edx\n" /* i */
        "jne .Lf2258c_00023028\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 1914 | this */
        "movb $0, 0x80d(%eax)\n"
        "movl $0x8620, (%esp)\n" /* line 1915 */
        "calll glDisable\n"
        "xorl %ebx, %ebx\n" /* IsProgramableOnly */
        /* { scope 2: NextUnit */
        ".Lf2258c_00023073:\n"
        "movl %ebx, (%esp)\n" /* line 1918 | i */
        "calll glDisableVertexAttribArrayARB\n"
        "movl $0, 0x14(%esp)\n" /* line 1919 */
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0x1406, 8(%esp)\n"
        "movl $4, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertexAttribPointerARB\n"
        "addl $1, %ebx\n" /* line 1916 | i */
        "cmpl $0x10, %ebx\n" /* i */
        "jne .Lf2258c_00023073\n"
        /* } scope */
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 1922 */
        "je .Lf2258c_00023286\n"
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 1927 */
        "je .Lf2258c_000232a3\n"
        ".Lf2258c_000230cf:\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 1931 */
        "cmpl $0xffff01ff, %eax\n"
        "ja .Lf2258c_000231c2\n"
        ".Lf2258c_000230df:\n"
        "movl 8(%ebp), %edx\n" /* line 382 | this */
        "movl 4(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf2258c_0002318b\n"
        "movl %edx, %ecx\n"
        ".Lf2258c_000230ef:\n"
        "movl $0, 0x814(%ecx)\n" /* line 344 */
        "movl $0xffffffff, 0x818(%ecx)\n" /* line 345 */
        "movl $0xffffffff, 0x81c(%ecx)\n" /* line 346 */
        "movb $0, 0x820(%ecx)\n" /* line 347 */
        "movl $0xffffffff, g_VAOID\n" /* line 1942 */
        "calll CVAOPacket_InitializeGenericVAO\n" /* line 1943 */
        /* } scope */
        "addl $0x1cc, %esp\n" /* line 1946 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: NextUnit */
        /* { scope 3 */
        ".Lf2258c_0002312e:\n"
        "movl -0x1b0(%ebp), %edx\n" /* line 352 */
        "movl (%edx), %eax\n"
        "leal -0x1a0(%ebp), %ecx\n" /* line 610 | NextUnit */
        "movl %ecx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "jmp .Lf2258c_00022ef4\n"
        /* } scope */
        /* } scope */
        /* { scope 2: NextUnit */
        ".Lf2258c_00023151:\n"
        "leal 0x10(%ebp), %eax\n" /* line 211 | MaxTextureUnits */
        "jmp .Lf2258c_00022e01\n"
        /* } scope */
        ".Lf2258c_00023159:\n"
        "movl $str_00215cd0, (%esp)\n" /* line 1560 */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "testb %al, %al\n"
        "je .Lf2258c_00022658\n"
        "movl $str_00215ce0, (%esp)\n" /* "GL_APPLE_element_array" */
        "calll MacOpenGLUtils_IsGLExtensionSupported\n"
        "testb %al, %al\n"
        "je .Lf2258c_00022658\n"
        "movl $1, %eax\n"
        "jmp .Lf2258c_0002265a\n"
        ".Lf2258c_0002318b:\n"
        "movl $0, 4(%edx)\n" /* line 384 */
        "movl $0x84c0, (%esp)\n" /* line 385 */
        "calll glActiveTextureARB\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "jmp .Lf2258c_000230ef\n"
        ".Lf2258c_000231a6:\n"
        "movl %ecx, %eax\n" /* line 1552 */
        "addl $0x804, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x84ff, (%esp)\n"
        "calll glGetFloatv\n"
        "jmp .Lf2258c_0002262f\n"
        ".Lf2258c_000231c2:\n"
        "movl $0x8804, (%esp)\n" /* line 1933 */
        "calll glDisable\n"
        "jmp .Lf2258c_000230df\n"
        ".Lf2258c_000231d3:\n"
        "movl $0xb50, (%esp)\n" /* line 1716 */
        "calll glEnable\n"
        "jmp .Lf2258c_00022910\n"
        ".Lf2258c_000231e4:\n"
        "movl $0x404, (%esp)\n" /* line 1692 */
        "calll glDrawBuffer\n"
        "movl $0x4000, (%esp)\n" /* line 1693 */
        "calll glClear\n"
        "jmp .Lf2258c_00022884\n"
        /* { scope 2: NextUnit */
        ".Lf2258c_00023201:\n"
        "xorl %esi, %esi\n" /* line 1652 | i */
        "leal -0x70(%ebp), %edi\n" /* Zero */
        ".Lf2258c_00023206:\n"
        "leal 0x3000(%esi), %ebx\n" /* i */
        "movl %ebx, (%esp)\n" /* line 1654 */
        "calll glDisable\n"
        "movl %edi, 4(%esp)\n" /* line 1655 */
        "movl %ebx, (%esp)\n"
        "calll glClipPlane\n"
        "addl $1, %esi\n" /* line 1652 | i */
        "cmpl -0x1c(%ebp), %esi\n" /* Count, i */
        "jl .Lf2258c_00023206\n"
        "jmp .Lf2258c_0002275f\n"
        /* } scope */
        ".Lf2258c_0002322d:\n"
        "movl %eax, %edx\n" /* line 1614 */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll glVertexArrayRangeAPPLE\n"
        "movl $0x851d, (%esp)\n" /* line 1615 */
        "calll glEnableClientState\n"
        "movl $0x85bf, 4(%esp)\n" /* line 1616 */
        "movl $0x851f, (%esp)\n"
        "calll glVertexArrayParameteriAPPLE\n"
        "jmp .Lf2258c_0002268e\n"
        ".Lf2258c_00023266:\n"
        "movb $1, 0x801(%ecx)\n" /* line 1608 */
        "movl $1, 4(%esp)\n" /* line 1609 */
        "movl $0x897c, (%esp)\n"
        "calll glVertexArrayParameteriAPPLE\n"
        "jmp .Lf2258c_0002267e\n"
        ".Lf2258c_00023286:\n"
        "movl $0x86de, (%esp)\n" /* line 1924 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 1925 */
        "calll glDisable\n"
        "jmp .Lf2258c_000230cf\n"
        ".Lf2258c_000232a3:\n"
        "movl $0x8200, (%esp)\n" /* line 1929 */
        "calll glDisable\n"
        "jmp .Lf2258c_000230cf\n"
        "movl %eax, %edx\n"
        /* { scope 2: NextUnit */
        /* { scope 3 */
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl %edx, (%esp)\n" /* line 223 */
        "calll __Unwind_Resume\n"
    );
}

/* line 1957 */
__attribute__((naked))
void ZN7COpenGLD0Ev(void) /* COpenGL_~COpenGL */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1957 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_COpenGL, (%esi)\n" /* this */
        "leal 0x674(%esi), %edi\n" /* line 392 | this */
        /* { scope 1 */
        "movl 0x674(%esi), %eax\n" /* line 72 */
        "cmpl %eax, %edi\n" /* line 73 */
        "jne .Lf232cc_000232f2\n"
        "jmp .Lf232cc_00023300\n"
        ".Lf232cc_000232f0:\n"
        "movl %ebx, %eax\n"
        ".Lf232cc_000232f2:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        "cmpl %ebx, %edi\n" /* line 73 */
        "jne .Lf232cc_000232f0\n"
        /* } scope */
        ".Lf232cc_00023300:\n"
        "leal 0x66c(%esi), %edi\n" /* line 392 | this */
        /* { scope 1 */
        "movl 0x66c(%esi), %eax\n" /* line 72 */
        "cmpl %eax, %edi\n" /* line 73 */
        "jne .Lf232cc_00023314\n"
        "jmp .Lf232cc_00023322\n"
        ".Lf232cc_00023312:\n"
        "movl %ebx, %eax\n"
        ".Lf232cc_00023314:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        "cmpl %ebx, %edi\n" /* line 73 */
        "jne .Lf232cc_00023312\n"
        /* } scope */
        ".Lf232cc_00023322:\n"
        "leal 0x65c(%esi), %ebx\n" /* line 1958 | this */
        /* { scope 1 */
        "movl 4(%ebx), %edx\n" /* line 273 | __last */
        "movl 0x65c(%esi), %eax\n"
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf232cc_0002334d\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "addl $8, %ecx\n"
        /* { scope 3 */
        ".Lf232cc_0002333e:\n"
        "movl %ecx, 0x104(%eax)\n" /* line 32 */
        /* } scope */
        "addl $0x130, %eax\n" /* line 173 */
        "cmpl %eax, %edx\n"
        "jne .Lf232cc_0002333e\n"
        /* } scope */
        ".Lf232cc_0002334d:\n"
        "movl (%ebx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf232cc_0002335b\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf232cc_0002335b:\n"
        "movl imp___ZTV12CNormalArray, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 0x5c(%esi)\n"
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, 0x5c(%esi)\n"
        "movl %eax, 0x44(%esi)\n"
        "movl %eax, 0x2c(%esi)\n"
        "movl %eax, 0x14(%esi)\n"
        "movl %esi, 8(%ebp)\n" /* line 1958 | this */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 1950 */
__attribute__((naked))
unsigned int COpenGL_COpenGL(const COpenGL * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1950 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_COpenGL, (%ebx)\n" /* line 1952 | this */
        "leal 0x14(%ebx), %eax\n" /* this */
        "movl %eax, -0x20(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 74 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV11CColorArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 0x14(%ebx)\n"
        /* } scope */
        "leal 0x2c(%ebx), %ecx\n" /* line 1952 | this */
        "movl %ecx, -0x1c(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %ecx, (%esp)\n" /* line 85 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV20CSecondaryColorArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 0x2c(%ebx)\n"
        /* } scope */
        "leal 0x44(%ebx), %edi\n" /* line 1952 | this */
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 106 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV12CVertexArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 0x44(%ebx)\n"
        /* } scope */
        "leal 0x5c(%ebx), %esi\n" /* line 1952 | this */
        /* { scope 1 */
        "movl %esi, (%esp)\n" /* line 95 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV12CNormalArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 0x5c(%ebx)\n"
        /* } scope */
        "leal 0x78(%ebx), %eax\n" /* line 97 | this */
        "movl %eax, (%esp)\n" /* this */
        "calll COpenGLMatrix_SetIdentity\n"
        "movl $8, %eax\n" /* this */
        ".Lf2338a_0002340a:\n"
        "subl $1, %eax\n" /* line 1952 */
        "jne .Lf2338a_0002340a\n"
        "leal 0x65c(%ebx), %eax\n" /* line 97 | this */
        /* { scope 1 */
        "movl $0, 0x65c(%ebx)\n" /* line 85 */
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        /* } scope */
        "leal 0x66c(%ebx), %eax\n" /* line 458 */
        /* { scope 1 */
        "movl %eax, 0x66c(%ebx)\n" /* line 340 */
        "movl %eax, 4(%eax)\n" /* line 341 */
        /* } scope */
        "leal 0x674(%ebx), %eax\n" /* line 458 */
        /* { scope 1 */
        "movl %eax, 0x674(%ebx)\n" /* line 340 */
        "movl %eax, 4(%eax)\n" /* line 341 */
        /* } scope */
        "movl $0, 0x67c(%ebx)\n" /* line 106 */
        "leal 0x680(%ebx), %eax\n"
        "movl $0x10, %edx\n"
        ".Lf2338a_00023460:\n"
        "movb $1, (%eax)\n" /* line 38 */
        "movb $0, 1(%eax)\n"
        "movl $4, 4(%eax)\n"
        "movl $0x1406, 8(%eax)\n"
        "movb $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "addl $0x18, %eax\n" /* line 106 */
        "subl $1, %edx\n"
        "jne .Lf2338a_00023460\n"
        "addl $0x2c, %esp\n" /* line 1953 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        ".Lf2338a_0002349f:\n"
        "leal 8(%ecx), %eax\n" /* line 32 */
        "movl -0x20(%ebp), %ecx\n" /* this */
        "movl %eax, (%ecx)\n"
        "movl %edx, (%esp)\n" /* line 74 */
        "calll __Unwind_Resume\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV12CNormalArray, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, (%esi)\n"
        "movl imp___ZTV7CBaseVA, %ecx\n" /* line 32 */
        "leal 8(%ecx), %eax\n"
        "movl %eax, (%esi)\n"
        ".Lf2338a_000234c6:\n"
        "leal 8(%ecx), %eax\n"
        "movl %eax, (%edi)\n"
        ".Lf2338a_000234cb:\n"
        "leal 8(%ecx), %eax\n"
        "movl -0x1c(%ebp), %ebx\n" /* this */
        "movl %eax, (%ebx)\n"
        "jmp .Lf2338a_0002349f\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "jmp .Lf2338a_000234c6\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "jmp .Lf2338a_000234cb\n"
    );
}

/* overload skip: COpenGL_COpenGL (0x234ea) */

/* line 1957 */
__attribute__((naked))
void ZN7COpenGLD1Ev(void) /* COpenGL_~COpenGL */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1957 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_COpenGL, (%edi)\n" /* this */
        "leal 0x674(%edi), %esi\n" /* line 392 | this */
        /* { scope 1 */
        "movl 0x674(%edi), %eax\n" /* line 72 */
        "cmpl %eax, %esi\n" /* line 73 */
        "jne .Lf2364c_00023672\n"
        "jmp .Lf2364c_00023680\n"
        ".Lf2364c_00023670:\n"
        "movl %ebx, %eax\n"
        ".Lf2364c_00023672:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        "cmpl %ebx, %esi\n" /* line 73 */
        "jne .Lf2364c_00023670\n"
        /* } scope */
        ".Lf2364c_00023680:\n"
        "leal 0x66c(%edi), %esi\n" /* line 392 | this */
        /* { scope 1 */
        "movl 0x66c(%edi), %eax\n" /* line 72 */
        "cmpl %eax, %esi\n" /* line 73 */
        "jne .Lf2364c_00023694\n"
        "jmp .Lf2364c_000236a2\n"
        ".Lf2364c_00023692:\n"
        "movl %ebx, %eax\n"
        ".Lf2364c_00023694:\n"
        "movl (%eax), %ebx\n" /* line 76 */
        /* { scope 2 */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        "cmpl %ebx, %esi\n" /* line 73 */
        "jne .Lf2364c_00023692\n"
        /* } scope */
        ".Lf2364c_000236a2:\n"
        "leal 0x65c(%edi), %ebx\n" /* line 1958 | this */
        /* { scope 1 */
        "movl 4(%ebx), %edx\n" /* line 273 | __last */
        "movl 0x65c(%edi), %eax\n"
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2364c_000236cd\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "addl $8, %ecx\n"
        /* { scope 3 */
        ".Lf2364c_000236be:\n"
        "movl %ecx, 0x104(%eax)\n" /* line 32 */
        /* } scope */
        "addl $0x130, %eax\n" /* line 173 */
        "cmpl %eax, %edx\n"
        "jne .Lf2364c_000236be\n"
        /* } scope */
        ".Lf2364c_000236cd:\n"
        "movl (%ebx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf2364c_000236db\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf2364c_000236db:\n"
        "movl imp___ZTV12CNormalArray, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 0x5c(%edi)\n"
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, 0x5c(%edi)\n"
        "movl %eax, 0x44(%edi)\n"
        "movl %eax, 0x2c(%edi)\n"
        "movl %eax, 0x14(%edi)\n"
        "addl $0x1c, %esp\n" /* line 1958 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2453 */
static __attribute__((naked))
unsigned int __static_initialization_and_destruction_0(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2453 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "cmpl $0xffff, %edx\n" /* line 21 */
        "je .Lf23702_00023712\n"
        ".Lf23702_00023710:\n"
        "leave\n" /* line 2453 */
        "retl\n"
        ".Lf23702_00023712:\n"
        "cmpl $1, %eax\n" /* line 21 */
        "je .Lf23702_00023729\n"
        "testl %eax, %eax\n"
        "jne .Lf23702_00023710\n"
        "movl $__ZN7COpenGL7sOpenGLE, (%esp)\n"
        "calll ZN7COpenGLD1Ev\n"
        "leave\n" /* line 2453 */
        "retl\n"
        ".Lf23702_00023729:\n"
        "movl $__ZN7COpenGL7sOpenGLE, (%esp)\n" /* line 21 */
        "calll COpenGL_COpenGL\n"
        "leave\n" /* line 2453 */
        "retl\n"
    );
}

/* line 2455 */
static __attribute__((naked))
void GLOBAL__D__ZN7COpenGL7sOpenGLE(void) /* global destructors keyed to COpenGL_sOpenGL */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2455 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 2454 */
__attribute__((naked))
void GLOBAL__I__ZN7COpenGL7sOpenGLE(void) /* global constructors keyed to COpenGL_sOpenGL */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2454 */
        "movl %esp, %ebp\n"
        "movl $0xffff, %edx\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "jmp __static_initialization_and_destruction_0\n"
    );
}

/* line 2274 */
__attribute__((naked))
unsigned int COpenGLVertexProgram_COpenGLVertexProgram(const COpenGLVertexProgram * _this, const char * pSrcData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2274 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 2277 | this */
        "movl $vtbl_COpenGLVertexProgram, (%eax)\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x3c(%ebp)\n" /* this */
        /* { scope 1 */
        "movl %edx, %eax\n" /* line 207 */
        "addl $0xc, %eax\n"
        /* } scope */
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl %eax, 4(%edx)\n"
        /* } scope */
        "movl %eax, 8(%edx)\n"
        "movl $0, 0xc(%edx)\n" /* line 106 */
        "movl %edx, %eax\n" /* this */
        "addl $0x10, %eax\n" /* this */
        "movl $0x10, %edx\n"
        /* { scope 1 */
        ".Lf2375c_00023796:\n"
        "movb $1, (%eax)\n" /* line 38 */
        "movb $0, 1(%eax)\n"
        "movl $4, 4(%eax)\n"
        "movl $0x1406, 8(%eax)\n"
        "movb $0, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        /* } scope */
        "addl $0x18, %eax\n" /* line 106 | this */
        "subl $1, %edx\n"
        "jne .Lf2375c_00023796\n"
        /* { scope 1 */
        "leal -0x1a(%ebp), %eax\n" /* line 2280 */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* pSrcData */
        "movl %eax, 4(%esp)\n"
        "leal -0x30(%ebp), %ebx\n" /* shaderNameAndCode */
        "movl %ebx, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl $2, 0xc(%esp)\n" /* line 1570 */
        "movl $0, 8(%esp)\n"
        "movl $str_00215bf8, 4(%esp)\n" /* "::" */
        "movl %ebx, (%esp)\n"
        "calll __ZNKSs4findEPKcmm\n"
        "movl %eax, %esi\n" /* this */
        "movl -0x30(%ebp), %eax\n" /* line 591 | shaderNameAndCode */
        "movl -0xc(%eax), %eax\n"
        "leal 2(%esi), %edx\n" /* line 2282 | this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 299 */
        "ja .Lf2375c_00023923\n"
        "movl %eax, 0xc(%esp)\n" /* line 1899 */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x2c(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSsC1ERKSsmm\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 2282 | this */
        "addl $8, %eax\n" /* this */
        /* { scope 2 */
        "movl %edi, 4(%esp)\n" /* line 480 */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %edi, -0x3c(%ebp)\n" /* line 224 | this */
        "jne .Lf2375c_00023986\n"
        ".Lf2375c_00023849:\n"
        "movl %esi, 0xc(%esp)\n" /* line 1899 | this */
        "movl $0, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSsC1ERKSsmm\n"
        "movl 8(%ebp), %eax\n" /* line 2283 | this */
        "addl $4, %eax\n" /* this */
        /* { scope 2 */
        "movl %edi, 4(%esp)\n" /* line 480 */
        "movl %eax, (%esp)\n"
        "calll __ZNSs6assignERKSs\n"
        /* } scope */
        "movl -0x28(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %edi, -0x3c(%ebp)\n" /* line 224 | this */
        "jne .Lf2375c_00023957\n"
        ".Lf2375c_00023885:\n"
        "leal -0x34(%ebp), %eax\n" /* line 2289 | CurrentProgram */
        "movl %eax, 8(%esp)\n"
        "movl $0x8677, 4(%esp)\n"
        "movl $0x8620, (%esp)\n"
        "calll glGetProgramivARB\n"
        "leal -0x24(%ebp), %eax\n" /* line 2292 | ProgramID */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glGenProgramsARB\n"
        "movl -0x24(%ebp), %eax\n" /* line 2293 | ProgramID */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 112 | this */
        "movl %eax, 0xc(%edx)\n"
        /* } scope */
        "movl %eax, 4(%esp)\n" /* line 2294 */
        "movl $0x8620, (%esp)\n"
        "calll glBindProgramARB\n"
        "movl 8(%ebp), %eax\n" /* line 269 | this */
        "movl 8(%eax), %edi\n"
        "movl %edi, 0xc(%esp)\n" /* line 2295 */
        "cld\n"
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x8875, 4(%esp)\n"
        "movl $0x8620, (%esp)\n"
        "calll glProgramStringARB\n"
        "movl -0x34(%ebp), %eax\n" /* line 2297 | CurrentProgram */
        "movl %eax, 4(%esp)\n"
        "movl $0x8620, (%esp)\n"
        "calll glBindProgramARB\n"
        "movl -0x30(%ebp), %eax\n" /* line 277 | shaderNameAndCode */
        "leal -0xc(%eax), %edi\n"
        /* { scope 2 */
        "cmpl %edi, -0x3c(%ebp)\n" /* line 224 | this */
        "jne .Lf2375c_0002392f\n"
        /* } scope */
        /* } scope */
        ".Lf2375c_0002391b:\n"
        "addl $0x4c, %esp\n" /* line 2298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2375c_00023923:\n"
        "movl $str_00215bfc, (%esp)\n" /* line 300 */
        "calll __ZSt20__throw_out_of_rangePKc\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2375c_0002392f:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_0002391b\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_0002391b\n"
        /* } scope */
        ".Lf2375c_00023957:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_00023885\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_00023885\n"
        ".Lf2375c_00023986:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_00023849\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_00023849\n"
        ".Lf2375c_000239b5:\n"
        "movl %eax, %ebx\n"
        /* } scope */
        ".Lf2375c_000239b7:\n"
        "movl 8(%ebp), %edx\n" /* line 269 | this */
        "movl 8(%edx), %eax\n"
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "cmpl %esi, -0x3c(%ebp)\n" /* line 224 | this */
        "jne .Lf2375c_00023a7f\n"
        /* } scope */
        ".Lf2375c_000239c9:\n"
        "movl 8(%ebp), %edx\n" /* line 269 | this */
        "movl 4(%edx), %eax\n"
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "cmpl %esi, -0x3c(%ebp)\n" /* line 224 | this */
        "jne .Lf2375c_00023a50\n"
        /* } scope */
        ".Lf2375c_000239d7:\n"
        "movl %ebx, (%esp)\n" /* line 472 */
        "calll __Unwind_Resume\n"
        ".Lf2375c_000239df:\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        ".Lf2375c_000239e1:\n"
        "movl -0x30(%ebp), %eax\n" /* line 277 | shaderNameAndCode */
        "leal -0xc(%eax), %esi\n"
        /* { scope 2 */
        "cmpl %esi, -0x3c(%ebp)\n" /* line 224 | this */
        "je .Lf2375c_000239b7\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_000239b7\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_000239b7\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl -0x28(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x3c(%ebp)\n" /* line 224 | this */
        "je .Lf2375c_000239e1\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_000239e1\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_000239e1\n"
        "jmp .Lf2375c_000239b5\n"
        "jmp .Lf2375c_000239df\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2375c_00023a50:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_000239d7\n"
        "leal -0x1d(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_000239d7\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2375c_00023a7f:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_000239c9\n"
        "leal -0x1e(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_000239c9\n"
        /* } scope */
        "movl %eax, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "jmp .Lf2375c_000239c9\n"
        "movl %eax, %ebx\n"
        /* { scope 1 */
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %esi, -0x3c(%ebp)\n" /* line 224 | this */
        "je .Lf2375c_000239e1\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf2375c_000239e1\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf2375c_000239e1\n"
        "jmp .Lf2375c_000239df\n"
        "jmp .Lf2375c_000239df\n"
    );
}

/* overload skip: COpenGLVertexProgram_COpenGLVertexProgram (0x23b08) */

/* line 2302 */
__attribute__((naked))
void ZN20COpenGLVertexProgramD2Ev(void) /* COpenGLVertexProgram_~COpenGLVertexProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2302 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_COpenGLVertexProgram, (%edi)\n" /* this */
        /* { scope 1 */
        "movl 0xc(%edi), %eax\n" /* line 108 */
        "movl %eax, -0x20(%ebp)\n" /* line 2306 | ProgramID */
        "leal -0x20(%ebp), %eax\n" /* line 2307 | ProgramID */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl __ZN7COpenGL7sOpenGLE + 0x67c, %eax\n" /* line 2311 */
        "cmpl -0x20(%ebp), %eax\n" /* ProgramID */
        "je .Lf23eb4_00023f23\n"
        ".Lf23eb4_00023ee9:\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        /* } scope */
        "movl 8(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf23eb4_00023f4b\n"
        /* } scope */
        ".Lf23eb4_00023f11:\n"
        "movl 4(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf23eb4_00023f73\n"
        /* } scope */
        ".Lf23eb4_00023f1b:\n"
        "addl $0x3c, %esp\n" /* line 2321 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf23eb4_00023f23:\n"
        "movl $0, __ZN7COpenGL7sOpenGLE + 0x67c\n" /* line 112 */
        "cmpb $0, __ZN7COpenGL7sOpenGLE + 0x80d\n" /* line 596 */
        "je .Lf23eb4_00023ee9\n"
        "movb $0, __ZN7COpenGL7sOpenGLE + 0x80d\n" /* line 598 */
        "movl $0x8620, (%esp)\n" /* line 599 */
        "calll glDisable\n"
        "jmp .Lf23eb4_00023ee9\n"
        /* } scope */
        /* { scope 1 */
        ".Lf23eb4_00023f4b:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf23eb4_00023f11\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf23eb4_00023f11\n"
        /* } scope */
        /* { scope 1 */
        ".Lf23eb4_00023f73:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf23eb4_00023f1b\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf23eb4_00023f1b\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl 8(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edx, %esi\n" /* line 224 */
        "jne .Lf23eb4_00023ffc\n"
        /* } scope */
        ".Lf23eb4_00023fb0:\n"
        "movl 4(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "cmpl -0x2c(%ebp), %esi\n" /* line 224 */
        "jne .Lf23eb4_00023fd4\n"
        /* } scope */
        ".Lf23eb4_00023fbb:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf23eb4_00023fb0\n"
        "movl %eax, %ebx\n"
        "jmp .Lf23eb4_00023fbb\n"
        /* { scope 1 */
        ".Lf23eb4_00023fd4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf23eb4_00023fbb\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf23eb4_00023fbb\n"
        /* } scope */
        /* { scope 1 */
        ".Lf23eb4_00023ffc:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf23eb4_00023fb0\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf23eb4_00023fb0\n"
        "movl %eax, %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf23eb4_00023fb0\n"
    );
}

/* line 2302 */
__attribute__((naked))
void ZN20COpenGLVertexProgramD1Ev(void) /* COpenGLVertexProgram_~COpenGLVertexProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2302 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_COpenGLVertexProgram, (%edi)\n" /* this */
        /* { scope 1 */
        "movl 0xc(%edi), %eax\n" /* line 108 */
        "movl %eax, -0x20(%ebp)\n" /* line 2306 | ProgramID */
        "leal -0x20(%ebp), %eax\n" /* line 2307 | ProgramID */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl __ZN7COpenGL7sOpenGLE + 0x67c, %eax\n" /* line 2311 */
        "cmpl -0x20(%ebp), %eax\n" /* ProgramID */
        "je .Lf24030_0002409f\n"
        ".Lf24030_00024065:\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        /* } scope */
        "movl 8(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf24030_000240c7\n"
        /* } scope */
        ".Lf24030_0002408d:\n"
        "movl 4(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf24030_000240ef\n"
        /* } scope */
        ".Lf24030_00024097:\n"
        "addl $0x3c, %esp\n" /* line 2321 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf24030_0002409f:\n"
        "movl $0, __ZN7COpenGL7sOpenGLE + 0x67c\n" /* line 112 */
        "cmpb $0, __ZN7COpenGL7sOpenGLE + 0x80d\n" /* line 596 */
        "je .Lf24030_00024065\n"
        "movb $0, __ZN7COpenGL7sOpenGLE + 0x80d\n" /* line 598 */
        "movl $0x8620, (%esp)\n" /* line 599 */
        "calll glDisable\n"
        "jmp .Lf24030_00024065\n"
        /* } scope */
        /* { scope 1 */
        ".Lf24030_000240c7:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf24030_0002408d\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf24030_0002408d\n"
        /* } scope */
        /* { scope 1 */
        ".Lf24030_000240ef:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf24030_00024097\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf24030_00024097\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl 8(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edx, %esi\n" /* line 224 */
        "jne .Lf24030_00024178\n"
        /* } scope */
        ".Lf24030_0002412c:\n"
        "movl 4(%edi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "cmpl -0x2c(%ebp), %esi\n" /* line 224 */
        "jne .Lf24030_00024150\n"
        /* } scope */
        ".Lf24030_00024137:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf24030_0002412c\n"
        "movl %eax, %ebx\n"
        "jmp .Lf24030_00024137\n"
        /* { scope 1 */
        ".Lf24030_00024150:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf24030_00024137\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf24030_00024137\n"
        /* } scope */
        /* { scope 1 */
        ".Lf24030_00024178:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf24030_0002412c\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf24030_0002412c\n"
        "movl %eax, %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf24030_0002412c\n"
    );
}

/* line 2302 */
__attribute__((naked))
void ZN20COpenGLVertexProgramD0Ev(void) /* COpenGLVertexProgram_~COpenGLVertexProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2302 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_COpenGLVertexProgram, (%esi)\n" /* this */
        /* { scope 1 */
        "movl 0xc(%esi), %eax\n" /* line 108 */
        "movl %eax, -0x20(%ebp)\n" /* line 2306 | ProgramID */
        "leal -0x20(%ebp), %eax\n" /* line 2307 | ProgramID */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl __ZN7COpenGL7sOpenGLE + 0x67c, %eax\n" /* line 2311 */
        "cmpl -0x20(%ebp), %eax\n" /* ProgramID */
        "je .Lf241ac_00024223\n"
        ".Lf241ac_000241e1:\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        /* } scope */
        "movl 8(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %ebx\n" /* line 224 */
        "jne .Lf241ac_0002424b\n"
        /* } scope */
        ".Lf241ac_00024209:\n"
        "movl 4(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf241ac_00024273\n"
        /* } scope */
        ".Lf241ac_00024213:\n"
        "movl %esi, (%esp)\n" /* line 2321 | this */
        "calll __ZdlPv\n"
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf241ac_00024223:\n"
        "movl $0, __ZN7COpenGL7sOpenGLE + 0x67c\n" /* line 112 */
        "cmpb $0, __ZN7COpenGL7sOpenGLE + 0x80d\n" /* line 596 */
        "je .Lf241ac_000241e1\n"
        "movb $0, __ZN7COpenGL7sOpenGLE + 0x80d\n" /* line 598 */
        "movl $0x8620, (%esp)\n" /* line 599 */
        "calll glDisable\n"
        "jmp .Lf241ac_000241e1\n"
        /* } scope */
        /* { scope 1 */
        ".Lf241ac_0002424b:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf241ac_00024209\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf241ac_00024209\n"
        /* } scope */
        /* { scope 1 */
        ".Lf241ac_00024273:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf241ac_00024213\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf241ac_00024213\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl 8(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %edi\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edx, %edi\n" /* line 224 */
        "jne .Lf241ac_000242ff\n"
        /* } scope */
        ".Lf241ac_000242b3:\n"
        "movl 4(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1 */
        "cmpl -0x2c(%ebp), %esi\n" /* line 224 */
        "jne .Lf241ac_000242d7\n"
        /* } scope */
        ".Lf241ac_000242be:\n"
        "movl %ebx, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf241ac_000242b3\n"
        "movl %eax, %ebx\n"
        "jmp .Lf241ac_000242be\n"
        /* { scope 1 */
        ".Lf241ac_000242d7:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf241ac_000242be\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf241ac_000242be\n"
        /* } scope */
        /* { scope 1 */
        ".Lf241ac_000242ff:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf241ac_000242b3\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf241ac_000242b3\n"
        "movl %eax, %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf241ac_000242b3\n"
    );
}

/* line 32 */
__attribute__((naked))
void ZN7CBaseVAD1Ev(void) /* CBaseVA_~CBaseVA */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "movl imp___ZTV7CBaseVA, %edx\n"
        "addl $8, %edx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, (%eax)\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 32 */
__attribute__((naked))
void ZN7CBaseVAD0Ev(void) /* CBaseVA_~CBaseVA */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 32 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl imp___ZTV7CBaseVA, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl %edx, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 76 */
__attribute__((naked))
unsigned int CColorArray_Enable(const CColorArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 76 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8076, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Enable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 77 */
__attribute__((naked))
unsigned int CColorArray_Disable(const CColorArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8076, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Disable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 87 */
__attribute__((naked))
unsigned int CSecondaryColorArray_Enable(const CSecondaryColorArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 87 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x845e, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Enable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 88 */
__attribute__((naked))
unsigned int CSecondaryColorArray_Disable(const CSecondaryColorArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x845e, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Disable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 97 */
__attribute__((naked))
unsigned int CNormalArray_Enable(const CNormalArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 97 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8075, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Enable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 98 */
__attribute__((naked))
unsigned int CNormalArray_Disable(const CNormalArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 98 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8075, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Disable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 108 */
__attribute__((naked))
unsigned int CVertexArray_Enable(const CVertexArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 108 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8074, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Enable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 109 */
__attribute__((naked))
unsigned int CVertexArray_Disable(const CVertexArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 109 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8074, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Disable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 119 */
__attribute__((naked))
unsigned int CTexCoordArray_Enable(const CTexCoordArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8078, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Enable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 120 */
__attribute__((naked))
unsigned int CTexCoordArray_Disable(const CTexCoordArray * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl $0x8078, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n" /* this */
        "calll CBaseVA_Disable\n"
        "leave\n"
        "retl\n"
    );
}

/* line 117 */
__attribute__((naked))
void ZN14CTexCoordArrayD1Ev(void) /* CTexCoordArray_~CTexCoordArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV14CTexCoordArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 117 */
        "retl\n"
    );
}

/* line 74 */
__attribute__((naked))
void ZN11CColorArrayD0Ev(void) /* CColorArray_~CColorArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV11CColorArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 74 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 74 */
__attribute__((naked))
void ZN11CColorArrayD1Ev(void) /* CColorArray_~CColorArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV11CColorArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 74 */
        "retl\n"
    );
}

/* line 85 */
__attribute__((naked))
void ZN20CSecondaryColorArrayD0Ev(void) /* CSecondaryColorArray_~CSecondaryColorArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV20CSecondaryColorArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 85 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 85 */
__attribute__((naked))
void ZN20CSecondaryColorArrayD1Ev(void) /* CSecondaryColorArray_~CSecondaryColorArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 85 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV20CSecondaryColorArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 85 */
        "retl\n"
    );
}

/* line 106 */
__attribute__((naked))
void ZN12CVertexArrayD0Ev(void) /* CVertexArray_~CVertexArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV12CVertexArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 106 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 106 */
__attribute__((naked))
void ZN12CVertexArrayD1Ev(void) /* CVertexArray_~CVertexArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 106 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV12CVertexArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 106 */
        "retl\n"
    );
}

/* line 95 */
__attribute__((naked))
void ZN12CNormalArrayD0Ev(void) /* CNormalArray_~CNormalArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV12CNormalArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 95 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 95 */
__attribute__((naked))
void ZN12CNormalArrayD1Ev(void) /* CNormalArray_~CNormalArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV12CNormalArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "popl %ebp\n" /* line 95 */
        "retl\n"
    );
}

/* line 117 */
__attribute__((naked))
void ZN14CTexCoordArrayD0Ev(void) /* CTexCoordArray_~CTexCoordArray */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl imp___ZTV14CTexCoordArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl imp___ZTV7CBaseVA, %edx\n" /* line 32 */
        "addl $8, %edx\n"
        "movl %edx, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 117 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 95 */
__attribute__((naked))
void ZNSt4listIPmSaIS0_EE5eraseESt14_List_iteratorIS0_E(void) /* std_list<unsigned long*, std_allocator<unsigned long*> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 95 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* __position */
        "movl (%ebx), %esi\n" /* line 97 | __position */
        "movl %ebx, (%esp)\n" /* line 1159 | __position */
        "calll __ZNSt15_List_node_base6unhookEv\n"
        "movl %ebx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "movl %esi, %eax\n" /* line 99 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) /* std_vector<COpenGL_CTexUnit, std_allocator<COpenGL_CTexUnit> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x17c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x15c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl 4(%edx), %ebx\n"
        "cmpl 8(%edx), %ebx\n"
        "je .Lf2be3e0_002be520\n"
        "leal -0x130(%ebx), %esi\n" /* Unit */
        /* { scope 1 */
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf2be3e0_002be73b\n"
        "leal 0x104(%ebx), %eax\n" /* line 107 | this */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 117 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV14CTexCoordArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, 0x104(%ebx)\n"
        /* } scope */
        /* { scope 2 */
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl %esi, 4(%esp)\n" /* Unit */
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 4(%eax), %ebx\n"
        "movl %eax, %edx\n"
        /* } scope */
        ".Lf2be3e0_002be44a:\n"
        "addl $0x130, %ebx\n" /* line 255 */
        "movl %ebx, 4(%edx)\n"
        "leal -0x44(%ebp), %eax\n" /* line 117 */
        "movl %eax, (%esp)\n"
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV14CTexCoordArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl 0x10(%ebp), %eax\n" /* __x */
        "movl %eax, 4(%esp)\n"
        "leal -0x148(%ebp), %edx\n" /* __x_copy */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %edx\n" /* line 257 | this */
        "movl 4(%edx), %eax\n"
        "leal -0x260(%eax), %esi\n" /* Unit */
        "leal -0x130(%eax), %edi\n"
        /* { scope 2 */
        "movl %esi, %eax\n" /* line 411 | Unit */
        "subl 0xc(%ebp), %eax\n" /* __position */
        "sarl $4, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "addl %eax, %edx\n"
        "negl %edx\n"
        "movl %edx, -0x168(%ebp)\n"
        "testl %edx, %edx\n"
        "jle .Lf2be3e0_002be4ed\n"
        "xorl %ebx, %ebx\n"
        ".Lf2be3e0_002be4c2:\n"
        "subl $0x130, %esi\n" /* line 412 | Unit */
        "subl $0x130, %edi\n"
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl %esi, 4(%esp)\n" /* Unit */
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %ebx\n"
        "cmpl %ebx, -0x168(%ebp)\n" /* line 411 */
        "jne .Lf2be3e0_002be4c2\n"
        /* } scope */
        ".Lf2be3e0_002be4ed:\n"
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "leal -0x148(%ebp), %eax\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl imp___ZTV7CBaseVA, %eax\n" /* line 32 */
        "addl $8, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        /* } scope */
        "addl $0x17c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2be3e0_002be520:\n"
        "subl (%edx), %ebx\n" /* line 759 */
        "sarl $4, %ebx\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "leal (%edx, %eax), %eax\n"
        "negl %eax\n"
        "cmpl $0xd79435, %eax\n" /* line 265 */
        "je .Lf2be3e0_002be76c\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2be3e0_002be743\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2be3e0_002be554:\n"
        "leal (%edx, %edx, 8), %eax\n" /* line 88 */
        "leal (%edx, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, -0x16c(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x164(%ebp)\n"
        "movl %eax, -0x158(%ebp)\n" /* line 276 */
        "movl 8(%ebp), %edx\n" /* line 279 | this */
        "movl (%edx), %edi\n"
        /* { scope 2 */
        "movl %eax, -0x154(%ebp)\n" /* line 82 */
        "cmpl %edi, 0xc(%ebp)\n" /* line 85 | __position */
        "je .Lf2be3e0_002be5e8\n"
        "movl %eax, %ebx\n"
        "movl %edi, %esi\n"
        "movl imp___ZTV14CTexCoordArray, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x170(%ebp)\n"
        "jmp .Lf2be3e0_002be59d\n"
        ".Lf2be3e0_002be59b:\n"
        "movl %esi, %edi\n"
        ".Lf2be3e0_002be59d:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2be3e0_002be5cf\n"
        "leal 0x104(%ebx), %eax\n" /* line 107 | this */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 117 */
        "calll CBaseVA_CBaseVA\n"
        "movl -0x170(%ebp), %edx\n"
        "movl %edx, 0x104(%ebx)\n"
        /* } scope */
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2be3e0_002be5cf:\n"
        "addl $0x130, %esi\n" /* line 623 | Unit */
        "addl $0x130, %ebx\n"
        "movl %ebx, -0x154(%ebp)\n"
        "cmpl %esi, 0xc(%ebp)\n" /* line 85 | __position */
        "jne .Lf2be3e0_002be59b\n"
        "movl %ebx, %eax\n"
        /* } scope */
        ".Lf2be3e0_002be5e8:\n"
        "movl %eax, -0x158(%ebp)\n" /* line 279 */
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf2be3e0_002be75b\n"
        "addl $0x104, %eax\n" /* line 107 | this */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 117 */
        "calll CBaseVA_CBaseVA\n"
        "movl imp___ZTV14CTexCoordArray, %eax\n"
        "addl $8, %eax\n"
        "movl -0x158(%ebp), %edx\n"
        "movl %eax, 0x104(%edx)\n"
        /* } scope */
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl 0x10(%ebp), %eax\n" /* __x */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl -0x154(%ebp), %edx\n"
        ".Lf2be3e0_002be634:\n"
        "addl $0x130, %edx\n" /* line 623 */
        "movl %edx, -0x158(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 286 | this */
        "addl $4, %eax\n"
        "movl %eax, -0x160(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x150(%ebp)\n"
        "movl -0x15c(%ebp), %esi\n" /* line 286 | Unit */
        /* { scope 2 */
        "movl -0x158(%ebp), %eax\n" /* line 82 */
        "movl %eax, -0x14c(%ebp)\n"
        "cmpl %edx, %esi\n" /* line 85 */
        "je .Lf2be3e0_002be6d1\n"
        "movl %eax, %ebx\n"
        "movl %esi, %edi\n"
        "movl imp___ZTV14CTexCoordArray, %edx\n"
        "addl $8, %edx\n"
        "movl %edx, -0x174(%ebp)\n"
        "jmp .Lf2be3e0_002be685\n"
        ".Lf2be3e0_002be683:\n"
        "movl %esi, %edi\n"
        ".Lf2be3e0_002be685:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2be3e0_002be6b7\n"
        "leal 0x104(%ebx), %eax\n" /* line 107 | this */
        /* { scope 3 */
        "movl %eax, (%esp)\n" /* line 117 */
        "calll CBaseVA_CBaseVA\n"
        "movl -0x174(%ebp), %eax\n"
        "movl %eax, 0x104(%ebx)\n"
        /* } scope */
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2be3e0_002be6b7:\n"
        "addl $0x130, %esi\n" /* line 623 | Unit */
        "addl $0x130, %ebx\n"
        "movl %ebx, -0x14c(%ebp)\n"
        "cmpl -0x150(%ebp), %esi\n" /* line 85 */
        "jne .Lf2be3e0_002be683\n"
        /* } scope */
        ".Lf2be3e0_002be6d1:\n"
        "movl -0x160(%ebp), %edx\n" /* line 352 */
        "movl (%edx), %ecx\n"
        "movl 8(%ebp), %eax\n" /* line 334 | this */
        "movl (%eax), %edx\n"
        "movl %edx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2be3e0_002be701\n"
        "movl imp___ZTV7CBaseVA, %edx\n"
        "addl $8, %edx\n"
        ".Lf2be3e0_002be6ed:\n"
        "movl %edx, 0x104(%eax)\n" /* line 32 */
        "addl $0x130, %eax\n" /* line 623 */
        "cmpl %ecx, %eax\n" /* line 173 */
        "jne .Lf2be3e0_002be6ed\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl (%eax), %edx\n"
        ".Lf2be3e0_002be701:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf2be3e0_002be70d\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2be3e0_002be70d:\n"
        "movl -0x164(%ebp), %eax\n" /* line 302 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl -0x14c(%ebp), %eax\n" /* line 303 */
        "movl %eax, 4(%edx)\n"
        "movl -0x164(%ebp), %eax\n" /* line 304 */
        "addl -0x16c(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x17c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2be3e0_002be73b:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf2be3e0_002be44a\n"
        /* { scope 1 */
        ".Lf2be3e0_002be743:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2be3e0_002be762\n"
        "cmpl $0xd79435, %edx\n" /* line 85 */
        "jbe .Lf2be3e0_002be554\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2be3e0_002be75b:\n"
        "movl %eax, %edx\n"
        "jmp .Lf2be3e0_002be634\n"
        ".Lf2be3e0_002be762:\n"
        "movl $0xd79435, %edx\n" /* line 272 */
        "jmp .Lf2be3e0_002be554\n"
        ".Lf2be3e0_002be76c:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
        "movl %eax, (%esp)\n" /* line 89 */
        "calll ___cxa_begin_catch\n"
        "movl -0x158(%ebp), %eax\n" /* line 91 */
        /* { scope 2 */
        "movl -0x14c(%ebp), %edx\n" /* line 121 */
        "cmpl %edx, %eax\n"
        "je .Lf2be3e0_002be7bb\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "addl $8, %ecx\n"
        ".Lf2be3e0_002be79b:\n"
        "movl %ecx, 0x104(%eax)\n" /* line 32 */
        "leal 0x130(%edx), %eax\n" /* line 623 */
        "cmpl -0x14c(%ebp), %eax\n" /* line 121 */
        "je .Lf2be3e0_002be7bb\n"
        "movl %eax, %edx\n"
        "jmp .Lf2be3e0_002be79b\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 108 */
        "calll __Unwind_Resume\n"
        /* } scope */
        /* } scope */
        /* { scope 1 */
        ".Lf2be3e0_002be7bb:\n"
        "calll ___cxa_rethrow\n" /* line 92 */
        "movl %eax, %ebx\n"
        ".Lf2be3e0_002be7c2:\n"
        "movl %ebx, (%esp)\n" /* line 292 */
        "calll ___cxa_begin_catch\n"
        "movl -0x164(%ebp), %eax\n" /* line 294 */
        "movl -0x158(%ebp), %edx\n" /* line 173 */
        "cmpl %edx, %eax\n"
        "je .Lf2be3e0_002be83f\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "addl $8, %ecx\n"
        ".Lf2be3e0_002be7e5:\n"
        "movl %ecx, 0x104(%edx)\n" /* line 32 */
        "addl $0x130, %eax\n" /* line 623 */
        "cmpl -0x158(%ebp), %eax\n" /* line 173 */
        "je .Lf2be3e0_002be83f\n"
        "movl %eax, %edx\n"
        "jmp .Lf2be3e0_002be7e5\n"
        "movl %eax, (%esp)\n" /* line 89 */
        "calll ___cxa_begin_catch\n"
        "movl -0x164(%ebp), %eax\n" /* line 91 */
        /* { scope 2 */
        "movl -0x154(%ebp), %edx\n" /* line 121 */
        "cmpl %edx, %eax\n"
        "je .Lf2be3e0_002be85c\n"
        "movl %eax, %edx\n"
        "movl imp___ZTV7CBaseVA, %ecx\n"
        "addl $8, %ecx\n"
        ".Lf2be3e0_002be81f:\n"
        "movl %ecx, 0x104(%edx)\n" /* line 32 */
        "addl $0x130, %eax\n" /* line 623 */
        "cmpl -0x154(%ebp), %eax\n" /* line 121 */
        "je .Lf2be3e0_002be85c\n"
        "movl %eax, %edx\n"
        "jmp .Lf2be3e0_002be81f\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "calll ___cxa_end_catch\n" /* line 89 */
        "jmp .Lf2be3e0_002be7c2\n"
        ".Lf2be3e0_002be83f:\n"
        "movl -0x164(%ebp), %eax\n" /* line 122 */
        "testl %eax, %eax\n"
        "je .Lf2be3e0_002be857\n"
        "movl -0x164(%ebp), %eax\n" /* line 94 */
        "movl %eax, (%esp)\n"
        "calll __ZdlPv\n"
        ".Lf2be3e0_002be857:\n"
        "calll ___cxa_rethrow\n" /* line 296 */
        ".Lf2be3e0_002be85c:\n"
        "calll ___cxa_rethrow\n" /* line 92 */
        "movl %eax, %ebx\n"
        "calll ___cxa_end_catch\n" /* line 292 */
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 122 */
__attribute__((naked))
void ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void) /* std_vector<COpenGL_CTexUnit, std_allocator<COpenGL_CTexUnit> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "addl $4, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n"
        "movl 0x10(%ebp), %edi\n" /* line 124 | __last */
        "movl 0xc(%ebp), %esi\n" /* __first */
        /* { scope 1 */
        /* { scope 2 */
        "subl %edi, %eax\n" /* line 283 */
        "sarl $4, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%eax, %eax, 8), %eax\n"
        "movl %eax, %edx\n"
        "shll $9, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x12, %eax\n"
        "addl %eax, %edx\n"
        "negl %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "testl %edx, %edx\n"
        "jle .Lf2be870_002be8da\n"
        "xorl %ebx, %ebx\n"
        ".Lf2be870_002be8b2:\n"
        "movl $0x130, 8(%esp)\n" /* line 108 */
        "movl %edi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "addl $0x130, %edi\n" /* line 286 */
        "addl $0x130, %esi\n" /* line 287 */
        "addl $1, %ebx\n"
        "cmpl %ebx, -0x20(%ebp)\n" /* line 283 */
        "jne .Lf2be870_002be8b2\n"
        /* } scope */
        /* } scope */
        ".Lf2be870_002be8da:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 352 */
        "movl (%eax), %ecx\n"
        "movl %esi, %eax\n"
        "cmpl %esi, %ecx\n" /* line 173 */
        "je .Lf2be870_002be904\n"
        "movl %esi, %edx\n"
        "movl imp___ZTV7CBaseVA, %ebx\n"
        "addl $8, %ebx\n"
        "jmp .Lf2be870_002be8f4\n"
        ".Lf2be870_002be8f2:\n"
        "movl %eax, %edx\n"
        ".Lf2be870_002be8f4:\n"
        "movl %ebx, 0x104(%eax)\n" /* line 32 */
        "leal 0x130(%edx), %eax\n" /* line 623 */
        "cmpl %ecx, %eax\n" /* line 173 */
        "jne .Lf2be870_002be8f2\n"
        ".Lf2be870_002be904:\n"
        "movl 0xc(%ebp), %edx\n" /* line 126 | __first */
        "subl %edx, 0x10(%ebp)\n" /* __last */
        "sarl $4, 0x10(%ebp)\n" /* __last */
        "movl 0x10(%ebp), %eax\n" /* __last */
        "leal (%eax, %eax, 2), %edx\n"
        "leal (%edx, %edx, 8), %edx\n"
        "movl %edx, %eax\n"
        "shll $9, %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x12, %edx\n"
        "addl %edx, %eax\n"
        "negl %eax\n"
        "leal (%eax, %eax, 8), %edx\n"
        "leal (%eax, %edx, 2), %edx\n"
        "shll $4, %edx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "subl %edx, 4(%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 127 | __first */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

