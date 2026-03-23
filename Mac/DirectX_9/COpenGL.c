/* Clean COpenGL implementation for Linux */
/* Replaces Mac OpenGL state management with stubs */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/COpenGL.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

/* --- External vtables --- */
extern void *vtbl_COpenGL[];
extern void *vtbl_COpenGLVertexProgram[];

/* --- COpenGL global state (accessed by other files via asm symbol) --- */
/* COpenGL::sOpenGL — large struct, accessed by offset from other .c files */
/* The asm symbol __ZN7COpenGL7sOpenGLE is the mangled name for COpenGL::sOpenGL */
unsigned char __attribute__((visibility("default")))
    COpenGL_sOpenGL_storage[4096] = {0};

/* Pointer used by generated_syms.h: imp__ZN7COpenGL7sOpenGLE */
void *imp__ZN7COpenGL7sOpenGLE = COpenGL_sOpenGL_storage;

/* Other COpenGL statics */
UINT32 COpenGL_sFrameCount = 0;
bool COpenGL_sDrawFlag = 0;
GLuint COpenGL_sShowTextureID = 0;
GLint g_VAOID = 0;

/* ============================================================ */
/* COpenGL methods                                              */
/* ============================================================ */

unsigned int COpenGL_SetColorMaterialEnable(const COpenGL *_this, int Value)
{
    (void)_this; (void)Value;
    return 0;
}

unsigned int COpenGL_SetActiveTexUnit(const COpenGL *_this, UINT32 Unit)
{
    (void)_this; (void)Unit;
    return 0;
}

unsigned int COpenGL_SetDither(const COpenGL *_this, int Value)
{
    (void)_this; (void)Value;
    return 0;
}

unsigned int COpenGL_SetBlendEXT(const COpenGL *_this, int ForceValidation,
    GLenum SrcFactorRGB, GLenum DstFactorRGB, GLenum SrcFactorAlpha, GLenum DstFactorAlpha)
{
    (void)_this; (void)ForceValidation;
    (void)SrcFactorRGB; (void)DstFactorRGB; (void)SrcFactorAlpha; (void)DstFactorAlpha;
    return 0;
}

unsigned int COpenGL_SetBlend(const COpenGL *_this, int ForceValidation,
    GLenum SrcFactorRGB, GLenum DstFactorRGB)
{
    (void)_this; (void)ForceValidation; (void)SrcFactorRGB; (void)DstFactorRGB;
    return 0;
}

unsigned int COpenGL_SetVertexProgram(const COpenGL *_this, const COpenGLVertexProgram *pOGLVertexProgramInfo)
{
    (void)_this; (void)pOGLVertexProgramInfo;
    return 0;
}

unsigned int COpenGL_SetVARInfo(const COpenGL *_this, const unsigned int *pVAStart, UINT32 Size)
{
    (void)_this; (void)pVAStart; (void)Size;
    return 0;
}

unsigned int COpenGL_DisableVertexProgramStream(const COpenGL *_this, UINT32 AttribArray)
{
    (void)_this; (void)AttribArray;
    return 0;
}

unsigned int COpenGL_CTexUnit_SetTex(const CTexUnit *_this, GLenum Target, const COpenGLTexture *pOpenGLTexInfo)
{
    (void)_this; (void)Target; (void)pOpenGLTexInfo;
    return 0;
}

/* Alternate name used in CDirect3DDevice.c ASM: COpenGL_SetTex */
unsigned int COpenGL_SetTex(const COpenGL *_this, UINT32 Unit, GLenum Target, const COpenGLTexture *pOpenGLTexInfo)
{
    (void)_this; (void)Unit; (void)Target; (void)pOpenGLTexInfo;
    return 0;
}

unsigned int COpenGL_SetVertexProgramStreamInfo(const COpenGL *_this, UINT32 AttribArray,
    GLint VSize, GLenum VType, int Normalized, GLsizei Stride, const unsigned int *pStream)
{
    (void)_this; (void)AttribArray; (void)VSize; (void)VType;
    (void)Normalized; (void)Stride; (void)pStream;
    return 0;
}

unsigned int COpenGL_CTexUnit_Reset(const CTexUnit *_this, int SupportsAnisotropicFiltering,
    int SupportsLODBias, int IsProgramableOnly)
{
    (void)_this; (void)SupportsAnisotropicFiltering; (void)SupportsLODBias; (void)IsProgramableOnly;
    return 0;
}

unsigned int COpenGL_SetVAO(const COpenGL *_this, const COpenGLVAO *VAO,
    int IsFixedFunction, int ForceValidation)
{
    (void)_this; (void)VAO; (void)IsFixedFunction; (void)ForceValidation;
    return 0;
}

unsigned int COpenGL_EnableColorArray(const COpenGL *_this, GLint Size, GLenum Type,
    GLsizei Stride, const unsigned int *Pointer)
{
    (void)_this; (void)Size; (void)Type; (void)Stride; (void)Pointer;
    return 0;
}

unsigned int COpenGL_DisableColorArray(const COpenGL *_this)
{
    (void)_this;
    return 0;
}

unsigned int COpenGL_EnableNormalArray(const COpenGL *_this, GLenum Type, GLsizei Stride, const unsigned int *Pointer)
{
    (void)_this; (void)Type; (void)Stride; (void)Pointer;
    return 0;
}

unsigned int COpenGL_DisableNormalArray(const COpenGL *_this)
{
    (void)_this;
    return 0;
}

unsigned int COpenGL_EnableVertexArray(const COpenGL *_this, GLint Size, GLenum Type,
    GLsizei Stride, const unsigned int *Pointer)
{
    (void)_this; (void)Size; (void)Type; (void)Stride; (void)Pointer;
    return 0;
}

unsigned int COpenGL_SetLight(const COpenGL *_this, UINT32 Light, const LightInfoType *Src)
{
    (void)_this; (void)Light; (void)Src;
    return 0;
}

unsigned int COpenGL_EnableTexCoordArray(const COpenGL *_this, UINT32 Unit, GLint Size,
    GLenum Type, GLsizei Stride, const unsigned int *Pointer)
{
    (void)_this; (void)Unit; (void)Size; (void)Type; (void)Stride; (void)Pointer;
    return 0;
}

unsigned int COpenGL_DisableTexCoordArray(const COpenGL *_this, UINT32 Unit)
{
    (void)_this; (void)Unit;
    return 0;
}

unsigned int COpenGL_SetTexMatrix(const COpenGL *_this, UINT32 Unit, const float *m)
{
    (void)_this; (void)Unit; (void)m;
    return 0;
}

unsigned int COpenGL_SetTexMatrixIdentity(const COpenGL *_this, UINT32 Unit)
{
    (void)_this; (void)Unit;
    return 0;
}

unsigned int COpenGL_Shutdown(const COpenGL *_this)
{
    (void)_this;
    return 0;
}

unsigned int COpenGL_SetTexGenEnable(const COpenGL *_this, UINT32 Unit,
    int Enable, int EnableReflection, int EnableNormalMap)
{
    (void)_this; (void)Unit; (void)Enable; (void)EnableReflection; (void)EnableNormalMap;
    return 0;
}

unsigned int COpenGL_DisableTexUnit(const COpenGL *_this, UINT32 Unit)
{
    (void)_this; (void)Unit;
    return 0;
}

unsigned int COpenGL_ReleaseVAOBinding(const COpenGL *_this, const GLuint *TexID)
{
    (void)_this; (void)TexID;
    return 0;
}

unsigned int COpenGL_ReleaseTextureBinding(const COpenGL *_this, const GLuint *TexID)
{
    (void)_this; (void)TexID;
    return 0;
}

unsigned int COpenGL_Init(const COpenGL *_this, UINT32 Buffers, UINT32 MaxTextureUnits, UINT32 MaxTextureImageUnits)
{
    (void)_this; (void)Buffers; (void)MaxTextureUnits; (void)MaxTextureImageUnits;
    return 0;
}

/* ============================================================ */
/* COpenGL constructor                                           */
/* ============================================================ */

unsigned int COpenGL_COpenGL(const COpenGL *_this)
{
    (void)_this;
    return 0;
}

/* ============================================================ */
/* COpenGL destructors                                           */
/* ============================================================ */

void ZN7COpenGLD1Ev(void *_this)
{
    (void)_this;
}

void ZN7COpenGLD0Ev(void *_this)
{
    (void)_this;
}

void ZN7COpenGLD2Ev(void *_this)
{
    (void)_this;
}

/* ============================================================ */
/* Global constructors/destructors for COpenGL::sOpenGL          */
/* ============================================================ */

static void GLOBAL__D__ZN7COpenGL7sOpenGLE(void)
{
    /* Global destructor for COpenGL::sOpenGL — no-op */
}

void GLOBAL__I__ZN7COpenGL7sOpenGLE(void)
{
    /* Global constructor for COpenGL::sOpenGL — call COpenGL_COpenGL */
    COpenGL_COpenGL((const COpenGL *)COpenGL_sOpenGL_storage);
}

/* ============================================================ */
/* COpenGLVertexProgram                                          */
/* ============================================================ */

unsigned int COpenGLVertexProgram_COpenGLVertexProgram(const COpenGLVertexProgram *_this, const char *pSrcData)
{
    /* COpenGLVertexProgram: compile ARB vertex program.
     * Store the GL program ID at offset 0 of the embedded object. */
    GLuint *progIdPtr = (GLuint *)_this;

    if (!pSrcData || pSrcData[0] != '!' || pSrcData[1] != '!') {
        *progIdPtr = 0;
        return 0;
    }

    {
        int len = strlen(pSrcData);
        int errorPos = -1;

        glGenProgramsARB(1, progIdPtr);
        glBindProgramARB(0x8620 /* GL_VERTEX_PROGRAM_ARB */, *progIdPtr);
        glProgramStringARB(0x8620, 0x8875 /* GL_PROGRAM_FORMAT_ASCII_ARB */,
                           len, pSrcData);

        glGetIntegerv(0x864B /* GL_PROGRAM_ERROR_POSITION_ARB */, &errorPos);
        if (errorPos != -1) {
            fprintf(stderr, "[ARB VP] Compile error at position %d in program %u\n",
                    errorPos, *progIdPtr);
        }

        glBindProgramARB(0x8620, 0);
    }

    return 0;
}

void ZN20COpenGLVertexProgramD1Ev(void *_this)
{
    (void)_this;
}

void ZN20COpenGLVertexProgramD0Ev(void *_this)
{
    (void)_this;
}

void ZN20COpenGLVertexProgramD2Ev(void *_this)
{
    (void)_this;
}

/* ============================================================ */
/* CBaseVA destructors                                           */
/* ============================================================ */

void ZN7CBaseVAD1Ev(void *_this) { (void)_this; }
void ZN7CBaseVAD0Ev(void *_this) { (void)_this; }

/* ============================================================ */
/* Vertex array Enable/Disable stubs                             */
/* ============================================================ */

unsigned int CColorArray_Enable(const CColorArray *_this) { (void)_this; return 0; }
unsigned int CColorArray_Disable(const CColorArray *_this) { (void)_this; return 0; }
unsigned int CSecondaryColorArray_Enable(const CSecondaryColorArray *_this) { (void)_this; return 0; }
unsigned int CSecondaryColorArray_Disable(const CSecondaryColorArray *_this) { (void)_this; return 0; }
unsigned int CNormalArray_Enable(const CNormalArray *_this) { (void)_this; return 0; }
unsigned int CNormalArray_Disable(const CNormalArray *_this) { (void)_this; return 0; }
unsigned int CVertexArray_Enable(const CVertexArray *_this) { (void)_this; return 0; }
unsigned int CVertexArray_Disable(const CVertexArray *_this) { (void)_this; return 0; }
unsigned int CTexCoordArray_Enable(const CTexCoordArray *_this) { (void)_this; return 0; }
unsigned int CTexCoordArray_Disable(const CTexCoordArray *_this) { (void)_this; return 0; }

/* ============================================================ */
/* Array class destructors                                       */
/* ============================================================ */

void ZN14CTexCoordArrayD1Ev(void *_this) { (void)_this; }
void ZN14CTexCoordArrayD0Ev(void *_this) { (void)_this; }
void ZN11CColorArrayD0Ev(void *_this) { (void)_this; }
void ZN11CColorArrayD1Ev(void *_this) { (void)_this; }
void ZN20CSecondaryColorArrayD0Ev(void *_this) { (void)_this; }
void ZN20CSecondaryColorArrayD1Ev(void *_this) { (void)_this; }
void ZN12CVertexArrayD0Ev(void *_this) { (void)_this; }
void ZN12CVertexArrayD1Ev(void *_this) { (void)_this; }
void ZN12CNormalArrayD0Ev(void *_this) { (void)_this; }
void ZN12CNormalArrayD1Ev(void *_this) { (void)_this; }

/* ============================================================ */
/* std:: template stubs from original                            */
/* ============================================================ */

void ZNSt4listIPmSaIS0_EE5eraseESt14_List_iteratorIS0_E(void) {}
void ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) {}
void ZNSt6vectorIN7COpenGL8CTexUnitESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void) {}
