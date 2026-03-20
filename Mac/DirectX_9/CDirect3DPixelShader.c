/* Clean CDirect3DPixelShader implementation for Linux/Emscripten */
/* Replaces Mac OpenGL ATI/NVidia/ARB fragment program implementations with stubs */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DPixelShader.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

/*
 * Pixel shader hierarchy on Mac:
 *   CDirect3DPixelShader (base) — vtbl_CDirect3DPixelShader_base
 *     COpenGLATITextFragmentShader — vtbl_CDirect3DPixelShader_ATI
 *     COpenGLNVidiaRegisterCombinersProgram — vtbl_CDirect3DPixelShader_NVidia
 *     COpenGLARBFragmentProgram — vtbl_CDirect3DPixelShader_ARB
 *
 * For WebGL2, all OpenGL ARB/ATI/NVidia program operations are no-ops.
 * We preserve the struct layouts and vtable assignments so vtables.S references resolve.
 */

typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 textureUsageMask; /* offset 0x8: bitmask of which texture[] units are used */
} CDirect3DPixelShaderImpl;

/* ATI text fragment shader: base + programId at offset 0xc */
typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 textureUsageMask;
    GLuint programId;
} COpenGLATITextFragmentShaderImpl;

/* NVidia register combiners: base + padding at 0xc + stageCount at 0x10 */
typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 textureUsageMask;
    UINT32 pad0xc;
    UINT32 stageCount;
} COpenGLNVidiaRegisterCombinersProgramImpl;

/* ARB fragment program: base + name string (0xc) + code string (0x10) + programId (0x14) */
typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 textureUsageMask;
    void *nameStr;   /* offset 0xc: std::string placeholder */
    void *codeStr;   /* offset 0x10: std::string placeholder */
    GLuint programId;/* offset 0x14 */
} COpenGLARBFragmentProgramImpl;

extern void *vtbl_CDirect3DPixelShader_base[];
extern void *vtbl_CDirect3DPixelShader_ATI[];
extern void *vtbl_CDirect3DPixelShader_NVidia[];
extern void *vtbl_CDirect3DPixelShader_ARB[];

extern void *imp___ZN7COpenGL7sOpenGLE;
extern int g_fp_enable_count;
extern int g_fp_bind_count;

/* Validation flag pointers (import_pointers.S indirect pointers) */
extern unsigned char *imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE;
extern unsigned char *imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE;
extern unsigned char *imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE;

/*
 * Helper: invalidate all device validation flags.
 * The original ASM set all three validation bytes to 1 in every destructor.
 */
static void CDirect3DPixelShader_InvalidateDeviceState(void)
{
    if (imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE)
        *imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE = 1;
    if (imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE)
        *imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE = 1;
    if (imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE)
        *imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE = 1;
}

/* Forward declarations — all symbols referenced by vtables.S */
ULONG CDirect3DPixelShader_AddRef(const CDirect3DPixelShader * _this);
HRESULT CDirect3DPixelShader_QueryInterface(const CDirect3DPixelShader * _this, const IID *iid, J_COLOR_SPACE * *ppvObj);
ULONG CDirect3DPixelShader_Release(const CDirect3DPixelShader * _this);
HRESULT CDirect3DPixelShader_GetDevice(const CDirect3DPixelShader * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DPixelShader_GetFunction(const CDirect3DPixelShader * _this, J_COLOR_SPACE *pDstData, UINT *pSizeOfData);

/* Base class destructors — take this pointer (cdecl, vtable-called) */
void ZN20CDirect3DPixelShaderD0Ev(const CDirect3DPixelShader * _this);
void ZN20CDirect3DPixelShaderD1Ev(const CDirect3DPixelShader * _this);
void ZN20CDirect3DPixelShaderD2Ev(const CDirect3DPixelShader * _this);

/* ATI text fragment shader */
J_COLOR_SPACE COpenGLATITextFragmentShader_Enable(const COpenGLATITextFragmentShader * _this);
J_COLOR_SPACE COpenGLATITextFragmentShader_Disable(const COpenGLATITextFragmentShader * _this);
J_COLOR_SPACE COpenGLATITextFragmentShader_SetConstants(const COpenGLATITextFragmentShader * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber);
J_COLOR_SPACE COpenGLATITextFragmentShader_COpenGLATITextFragmentShader(const COpenGLATITextFragmentShader * _this, const J_COLOR_SPACE * pSrcData);
void ZN28COpenGLATITextFragmentShaderD0Ev(const COpenGLATITextFragmentShader * _this);
void ZN28COpenGLATITextFragmentShaderD1Ev(const COpenGLATITextFragmentShader * _this);

/* NVidia register combiners */
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Enable(const COpenGLNVidiaRegisterCombinersProgram * _this);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Disable(const COpenGLNVidiaRegisterCombinersProgram * _this);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_SetConstants(const COpenGLNVidiaRegisterCombinersProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_COpenGLNVidiaRegisterCombinersProgram(const COpenGLNVidiaRegisterCombinersProgram * _this, const J_COLOR_SPACE *pSrcData);
void ZN37COpenGLNVidiaRegisterCombinersProgramD0Ev(const COpenGLNVidiaRegisterCombinersProgram * _this);
void ZN37COpenGLNVidiaRegisterCombinersProgramD1Ev(const COpenGLNVidiaRegisterCombinersProgram * _this);
void ZN37COpenGLNVidiaRegisterCombinersProgramD2Ev(const COpenGLNVidiaRegisterCombinersProgram * _this);

/* ARB fragment program */
J_COLOR_SPACE COpenGLARBFragmentProgram_Enable(const COpenGLARBFragmentProgram * _this);
J_COLOR_SPACE COpenGLARBFragmentProgram_Disable(const COpenGLARBFragmentProgram * _this);
J_COLOR_SPACE COpenGLARBFragmentProgram_SetConstants(const COpenGLARBFragmentProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber);
J_COLOR_SPACE COpenGLARBFragmentProgram_COpenGLARBFragmentProgram(const COpenGLARBFragmentProgram * _this, const string *Name, const string *Code);
void ZN25COpenGLARBFragmentProgramD0Ev(const COpenGLARBFragmentProgram * _this);
void ZN25COpenGLARBFragmentProgramD1Ev(const COpenGLARBFragmentProgram * _this);
void ZN25COpenGLARBFragmentProgramD2Ev(const COpenGLARBFragmentProgram * _this);

/* ========================================================================= */
/* CDirect3DPixelShader base class                                           */
/* ========================================================================= */

ULONG CDirect3DPixelShader_AddRef(const CDirect3DPixelShader * _this)
{
    CDirect3DPixelShaderImpl *shader;

    shader = (CDirect3DPixelShaderImpl *)_this;
    ++shader->refCount;
    return shader->refCount;
}

HRESULT CDirect3DPixelShader_QueryInterface(const CDirect3DPixelShader * _this, const IID *iid, J_COLOR_SPACE * *ppvObj)
{
    (void)iid;

    *ppvObj = (J_COLOR_SPACE *)_this;
    CDirect3DPixelShader_AddRef(_this);
    return 0;
}

ULONG CDirect3DPixelShader_Release(const CDirect3DPixelShader * _this)
{
    CDirect3DPixelShaderImpl *shader;
    ULONG refCount;

    shader = (CDirect3DPixelShaderImpl *)_this;
    refCount = --shader->refCount;
    if (!refCount) {
        /* Call the deleting destructor via vtable slot [6] (offset 24) */
        void **vtable = shader->vtable;
        ((void (*)(const CDirect3DPixelShader *))vtable[6])(_this);
    }

    return refCount;
}

/*
 * Base destructors: set vtable to base, invalidate device state.
 * Original ASM also checked if this == openGLState->boundFragmentProgram (offset 0x818)
 * and cleared it. For stubs, we just invalidate.
 */
void ZN20CDirect3DPixelShaderD2Ev(const CDirect3DPixelShader * _this)
{
    CDirect3DPixelShaderImpl *shader = (CDirect3DPixelShaderImpl *)_this;
    shader->vtable = vtbl_CDirect3DPixelShader_base;
    CDirect3DPixelShader_InvalidateDeviceState();
}

void ZN20CDirect3DPixelShaderD1Ev(const CDirect3DPixelShader * _this)
{
    ZN20CDirect3DPixelShaderD2Ev(_this);
}

void ZN20CDirect3DPixelShaderD0Ev(const CDirect3DPixelShader * _this)
{
    ZN20CDirect3DPixelShaderD2Ev(_this);
    free((void *)_this);
}

/* ========================================================================= */
/* COpenGLATITextFragmentShader                                              */
/* ========================================================================= */

J_COLOR_SPACE COpenGLATITextFragmentShader_Enable(const COpenGLATITextFragmentShader * _this)
{
    (void)_this;
    /* Original: bind ARB program 0x8200, enable 0x8200. Stub for WebGL2. */
    return 0;
}

J_COLOR_SPACE COpenGLATITextFragmentShader_Disable(const COpenGLATITextFragmentShader * _this)
{
    (void)_this;
    /* Original: glDisable(0x8200). Stub for WebGL2. */
    return 0;
}

J_COLOR_SPACE COpenGLATITextFragmentShader_SetConstants(const COpenGLATITextFragmentShader * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber)
{
    (void)_this;
    (void)Register;
    (void)pConstantData;
    (void)Vector4fCount;
    (void)CommandNumber;
    /* Original: glProgramEnvParameter4fvARB(0x8200, ...). Stub for WebGL2. */
    return 0;
}

J_COLOR_SPACE COpenGLATITextFragmentShader_COpenGLATITextFragmentShader(const COpenGLATITextFragmentShader * _this, const J_COLOR_SPACE * pSrcData)
{
    COpenGLATITextFragmentShaderImpl *shader;

    (void)pSrcData;

    shader = (COpenGLATITextFragmentShaderImpl *)_this;
    shader->vtable = vtbl_CDirect3DPixelShader_ATI;
    shader->refCount = 1;
    shader->textureUsageMask = 0;
    shader->programId = 0;
    /* Original: glGenProgramsARB, glBindProgramARB, glProgramStringARB. Stub for WebGL2. */
    return 0;
}

/* ATI destructor helpers */
static void COpenGLATITextFragmentShader_DestroyImpl(const COpenGLATITextFragmentShader * _this)
{
    COpenGLATITextFragmentShaderImpl *shader = (COpenGLATITextFragmentShaderImpl *)_this;
    shader->vtable = vtbl_CDirect3DPixelShader_ATI;
    /* Original: glDeleteProgramsARB(1, &programId), then call base D2. Stub for WebGL2. */
    ZN20CDirect3DPixelShaderD2Ev((const CDirect3DPixelShader *)_this);
}

void ZN28COpenGLATITextFragmentShaderD1Ev(const COpenGLATITextFragmentShader * _this)
{
    COpenGLATITextFragmentShader_DestroyImpl(_this);
}

void ZN28COpenGLATITextFragmentShaderD0Ev(const COpenGLATITextFragmentShader * _this)
{
    COpenGLATITextFragmentShader_DestroyImpl(_this);
    free((void *)_this);
}

/* ========================================================================= */
/* COpenGLNVidiaRegisterCombinersProgram                                     */
/* ========================================================================= */

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Enable(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    (void)_this;
    return 0;
}

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Disable(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    (void)_this;
    /* Original: glDisable(0x86de), glDisable(0x8522). Stub for WebGL2. */
    return 0;
}

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_SetConstants(const COpenGLNVidiaRegisterCombinersProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber)
{
    (void)_this;
    (void)Register;
    (void)pConstantData;
    (void)Vector4fCount;
    (void)CommandNumber;
    /* Original: glCombinerParameterfvNV/glCombinerStageParameterfvNV. Stub for WebGL2. */
    return 0;
}

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_COpenGLNVidiaRegisterCombinersProgram(const COpenGLNVidiaRegisterCombinersProgram * _this, const J_COLOR_SPACE *pSrcData)
{
    COpenGLNVidiaRegisterCombinersProgramImpl *program;

    program = (COpenGLNVidiaRegisterCombinersProgramImpl *)_this;
    program->vtable = vtbl_CDirect3DPixelShader_NVidia;
    program->refCount = 1;
    program->textureUsageMask = 0;
    program->pad0xc = (UINT32)(unsigned long)pSrcData; /* original stored pSrcData at offset 0xc */
    program->stageCount = 0;
    return 0;
}

/* NVidia destructor helpers */
static void COpenGLNVidiaRegisterCombinersProgram_DestroyImpl(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    COpenGLNVidiaRegisterCombinersProgramImpl *program;
    program = (COpenGLNVidiaRegisterCombinersProgramImpl *)_this;
    program->vtable = vtbl_CDirect3DPixelShader_NVidia;
    /* Original: optional glDisable(0x86de + 0x8522), then call base D2. Stub. */
    ZN20CDirect3DPixelShaderD2Ev((const CDirect3DPixelShader *)_this);
}

void ZN37COpenGLNVidiaRegisterCombinersProgramD2Ev(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    COpenGLNVidiaRegisterCombinersProgram_DestroyImpl(_this);
}

void ZN37COpenGLNVidiaRegisterCombinersProgramD1Ev(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    COpenGLNVidiaRegisterCombinersProgram_DestroyImpl(_this);
}

void ZN37COpenGLNVidiaRegisterCombinersProgramD0Ev(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    COpenGLNVidiaRegisterCombinersProgram_DestroyImpl(_this);
    free((void *)_this);
}

/* ========================================================================= */
/* COpenGLARBFragmentProgram                                                 */
/* ========================================================================= */

J_COLOR_SPACE COpenGLARBFragmentProgram_Enable(const COpenGLARBFragmentProgram * _this)
{
    COpenGLARBFragmentProgramImpl *program = (COpenGLARBFragmentProgramImpl *)_this;
    if (program->programId) {
        glEnable(0x8804); /* GL_FRAGMENT_PROGRAM_ARB */
        glBindProgramARB(0x8804, program->programId);
    }
    ++g_fp_enable_count;
    return 0;
}

J_COLOR_SPACE COpenGLARBFragmentProgram_Disable(const COpenGLARBFragmentProgram * _this)
{
    (void)_this;
    glDisable(0x8804); /* GL_FRAGMENT_PROGRAM_ARB */
    glBindProgramARB(0x8804, 0);
    return 0;
}

J_COLOR_SPACE COpenGLARBFragmentProgram_SetConstants(const COpenGLARBFragmentProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber)
{
    UINT32 i;
    const float *pf = pConstantData;
    (void)_this;
    (void)CommandNumber;
    for (i = 0; i < Vector4fCount; i++) {
        glProgramEnvParameter4fvARB(0x8804, Register + i, pf);
        pf += 4;
    }
    return 0;
}

J_COLOR_SPACE COpenGLARBFragmentProgram_COpenGLARBFragmentProgram(const COpenGLARBFragmentProgram * _this, const string *Name, const string *Code)
{
    COpenGLARBFragmentProgramImpl *program;
    const char *codeStr;
    int codeLen;

    program = (COpenGLARBFragmentProgramImpl *)_this;
    program->vtable = vtbl_CDirect3DPixelShader_ARB;
    program->refCount = 1;
    program->textureUsageMask = 0;
    program->nameStr = NULL;
    program->codeStr = NULL;
    program->programId = 0;

    /* Code is a std::string — on i386 GCC, the c_str data pointer is at offset 0.
     * The Mac std::string layout: pointer to char data at offset 0. */
    codeStr = *(const char **)Code;
    if (!codeStr || !codeStr[0])
        return 0;

    codeLen = strlen(codeStr);

    /* Build texture usage mask by scanning for "texture[ N ]" patterns */
    {
        const char *p = codeStr;
        while ((p = strstr(p, "texture[")) != NULL) {
            p += 8; /* skip "texture[" */
            while (*p == ' ') p++;
            if (*p >= '0' && *p <= '9') {
                int idx = *p - '0';
                if (idx < 16)
                    program->textureUsageMask |= (1u << idx);
            }
            p++;
        }
    }

    /* Create ARB fragment program */
    glGenProgramsARB(1, &program->programId);
    glBindProgramARB(0x8804, program->programId);
    glProgramStringARB(0x8804, 0x8875 /* GL_PROGRAM_FORMAT_ASCII_ARB */,
                       codeLen, codeStr);

    /* Check for compile errors */
    {
        int errorPos = 0;
        glGetIntegerv(0x864B /* GL_PROGRAM_ERROR_POSITION_ARB */, &errorPos);
        if (errorPos != -1) {
            fprintf(stderr, "[ARB FP] Compile error at position %d in program %u\n",
                    errorPos, program->programId);
        }
    }

    /* Unbind after setup */
    glBindProgramARB(0x8804, 0);

    return 0;
}

/* ARB destructor helpers */
static void COpenGLARBFragmentProgram_DestroyImpl(const COpenGLARBFragmentProgram * _this)
{
    COpenGLARBFragmentProgramImpl *program;
    program = (COpenGLARBFragmentProgramImpl *)_this;
    program->vtable = vtbl_CDirect3DPixelShader_ARB;
    if (program->programId) {
        glDeleteProgramsARB(1, &program->programId);
        program->programId = 0;
    }
    ZN20CDirect3DPixelShaderD2Ev((const CDirect3DPixelShader *)_this);
}

void ZN25COpenGLARBFragmentProgramD2Ev(const COpenGLARBFragmentProgram * _this)
{
    COpenGLARBFragmentProgram_DestroyImpl(_this);
}

void ZN25COpenGLARBFragmentProgramD1Ev(const COpenGLARBFragmentProgram * _this)
{
    COpenGLARBFragmentProgram_DestroyImpl(_this);
}

void ZN25COpenGLARBFragmentProgramD0Ev(const COpenGLARBFragmentProgram * _this)
{
    COpenGLARBFragmentProgram_DestroyImpl(_this);
    free((void *)_this);
}

/* ========================================================================= */
/* IDirect3DPixelShader9 interface stubs                                     */
/* ========================================================================= */

HRESULT CDirect3DPixelShader_GetDevice(const CDirect3DPixelShader * _this, IDirect3DDevice9 * *ppDevice)
{
    (void)_this;
    *ppDevice = NULL;
    return 0;
}

HRESULT CDirect3DPixelShader_GetFunction(const CDirect3DPixelShader * _this, J_COLOR_SPACE *pDstData, UINT *pSizeOfData)
{
    (void)_this;
    (void)pDstData;
    *pSizeOfData = 0;
    return 0;
}
