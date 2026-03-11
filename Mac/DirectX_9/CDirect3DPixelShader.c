/* ASM dump from: CDirect3DPixelShader.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DPixelShader.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DPixelShader.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 *   #include "Mac/DirectX 9/CDirect3DDevice.h"
 */

typedef struct {
    void *methods[6];
    void (*Destroy)(const CDirect3DPixelShader *object);
} CDirect3DPixelShaderVTable;

typedef struct {
    void **vtable;
    ULONG refCount;
} CDirect3DPixelShaderImpl;

typedef struct {
    unsigned char pad0[0xc];
    GLuint programId;
} COpenGLATITextFragmentShaderImpl;

typedef struct {
    unsigned char pad0[0x10];
    UINT32 stageCount;
} COpenGLNVidiaRegisterCombinersProgramImpl;

typedef struct {
    unsigned char pad0[0x14];
    GLuint programId;
} COpenGLARBFragmentProgramImpl;

typedef struct {
    unsigned char pad0[0x81c];
    GLuint boundFragmentProgram;
    unsigned char fragmentProgramEnabled;
} COpenGLPixelState;

extern void *imp___ZN7COpenGL7sOpenGLE;
extern int g_fp_enable_count;
extern int g_fp_bind_count;

static CDirect3DPixelShaderVTable *CDirect3DPixelShader_GetVTable(const CDirect3DPixelShader *object)
{
    return *(CDirect3DPixelShaderVTable **)object;
}

static COpenGLPixelState *CDirect3DPixelShader_GetOpenGLState(void)
{
    return (COpenGLPixelState *)imp___ZN7COpenGL7sOpenGLE;
}

ULONG CDirect3DPixelShader_AddRef(const CDirect3DPixelShader * _this);
HRESULT CDirect3DPixelShader_QueryInterface(const CDirect3DPixelShader * _this, const IID *iid, J_COLOR_SPACE * *ppvObj);
ULONG CDirect3DPixelShader_Release(const CDirect3DPixelShader * _this);
J_COLOR_SPACE COpenGLATITextFragmentShader_SetConstants(const COpenGLATITextFragmentShader * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Enable(const COpenGLNVidiaRegisterCombinersProgram * _this);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_SetConstants(const COpenGLNVidiaRegisterCombinersProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber);
J_COLOR_SPACE COpenGLARBFragmentProgram_Disable(const COpenGLARBFragmentProgram * _this);
J_COLOR_SPACE COpenGLARBFragmentProgram_SetConstants(const COpenGLARBFragmentProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber);
void ZN20CDirect3DPixelShaderD0Ev(void); /* CDirect3DPixelShader_~CDirect3DPixelShader */
J_COLOR_SPACE COpenGLATITextFragmentShader_Enable(const COpenGLATITextFragmentShader * _this);
J_COLOR_SPACE COpenGLATITextFragmentShader_Disable(const COpenGLATITextFragmentShader * _this);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Disable(const COpenGLNVidiaRegisterCombinersProgram * _this);
J_COLOR_SPACE COpenGLARBFragmentProgram_Enable(const COpenGLARBFragmentProgram * _this);
void ZN20CDirect3DPixelShaderD2Ev(void); /* CDirect3DPixelShader_~CDirect3DPixelShader */
void ZN20CDirect3DPixelShaderD1Ev(void); /* CDirect3DPixelShader_~CDirect3DPixelShader */
void ZN28COpenGLATITextFragmentShaderD1Ev(void); /* COpenGLATITextFragmentShader_~COpenGLATITextFragmentShader */
void ZN28COpenGLATITextFragmentShaderD0Ev(void); /* COpenGLATITextFragmentShader_~COpenGLATITextFragmentShader */
J_COLOR_SPACE COpenGLATITextFragmentShader_COpenGLATITextFragmentShader(const COpenGLATITextFragmentShader * _this, const J_COLOR_SPACE * pSrcData);
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_COpenGLNVidiaRegisterCombinersProgram(const COpenGLNVidiaRegisterCombinersProgram * _this, const J_COLOR_SPACE *pSrcData);
void ZN37COpenGLNVidiaRegisterCombinersProgramD2Ev(void); /* COpenGLNVidiaRegisterCombinersProgram_~COpenGLNVidiaRegisterCombinersProgram */
void ZN37COpenGLNVidiaRegisterCombinersProgramD1Ev(void); /* COpenGLNVidiaRegisterCombinersProgram_~COpenGLNVidiaRegisterCombinersProgram */
void ZN37COpenGLNVidiaRegisterCombinersProgramD0Ev(void); /* COpenGLNVidiaRegisterCombinersProgram_~COpenGLNVidiaRegisterCombinersProgram */
J_COLOR_SPACE COpenGLARBFragmentProgram_COpenGLARBFragmentProgram(const COpenGLARBFragmentProgram * _this, const string *Name, const string *Code);
void ZN25COpenGLARBFragmentProgramD2Ev(void); /* COpenGLARBFragmentProgram_~COpenGLARBFragmentProgram */
void ZN25COpenGLARBFragmentProgramD1Ev(void); /* COpenGLARBFragmentProgram_~COpenGLARBFragmentProgram */
void ZN25COpenGLARBFragmentProgramD0Ev(void); /* COpenGLARBFragmentProgram_~COpenGLARBFragmentProgram */
HRESULT CDirect3DPixelShader_GetDevice(const CDirect3DPixelShader * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DPixelShader_GetFunction(const CDirect3DPixelShader * _this, J_COLOR_SPACE *pDstData, UINT *pSizeOfData);

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
        CDirect3DPixelShader_GetVTable(_this)->Destroy(_this);
    }

    return refCount;
}

J_COLOR_SPACE COpenGLATITextFragmentShader_SetConstants(const COpenGLATITextFragmentShader * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber)
{
    UINT32 i;

    (void)_this;
    (void)CommandNumber;

    for (i = 0; i < Vector4fCount; ++i) {
        glProgramEnvParameter4fvARB(0x8200, Register + i, pConstantData + (i * 4));
    }

    return 0;
}

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Enable(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    (void)_this;
    return 0;
}

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_SetConstants(const COpenGLNVidiaRegisterCombinersProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber)
{
    const COpenGLNVidiaRegisterCombinersProgramImpl *program;

    (void)Register;
    (void)Vector4fCount;

    program = (const COpenGLNVidiaRegisterCombinersProgramImpl *)_this;
    if (program->stageCount <= 2) {
        glCombinerParameterfvNV(0x852a + CommandNumber, pConstantData);
    } else {
        glCombinerStageParameterfvNV(0x8550 + CommandNumber, 0x852a, pConstantData);
    }

    return 0;
}

J_COLOR_SPACE COpenGLARBFragmentProgram_Disable(const COpenGLARBFragmentProgram * _this)
{
    COpenGLPixelState *openGLState;

    (void)_this;

    openGLState = CDirect3DPixelShader_GetOpenGLState();
    if (!openGLState->fragmentProgramEnabled) {
        return 0;
    }

    openGLState->fragmentProgramEnabled = 0;
    glDisable(0x8804);
    return 0;
}

J_COLOR_SPACE COpenGLARBFragmentProgram_SetConstants(const COpenGLARBFragmentProgram * _this, UINT32 Register, const float * pConstantData, UINT32 Vector4fCount, UINT32 CommandNumber)
{
    UINT32 i;

    (void)_this;
    (void)CommandNumber;

    for (i = 0; i < Vector4fCount; ++i) {
        glProgramEnvParameter4fvARB(0x8804, Register + i, pConstantData + (i * 4));
    }

    return 0;
}

/* line 29 */
__attribute__((naked))
void ZN20CDirect3DPixelShaderD0Ev(void) /* CDirect3DPixelShader_~CDirect3DPixelShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_base, (%edx)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 33 */
        "cmpl %edx, 0x818(%eax)\n"
        "je .Lf1c138_0001c172\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "movl %edx, 8(%ebp)\n" /* line 43 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf1c138_0001c172:\n"
        "movl $0, 0x818(%eax)\n" /* line 345 */
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "movl %edx, 8(%ebp)\n" /* line 43 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

J_COLOR_SPACE COpenGLATITextFragmentShader_Enable(const COpenGLATITextFragmentShader * _this)
{
    const COpenGLATITextFragmentShaderImpl *shader;
    COpenGLPixelState *openGLState;

    shader = (const COpenGLATITextFragmentShaderImpl *)_this;
    openGLState = CDirect3DPixelShader_GetOpenGLState();

    if (openGLState->boundFragmentProgram != shader->programId) {
        glBindProgramARB(0x8200, shader->programId);
        openGLState->boundFragmentProgram = shader->programId;
    }

    if (!openGLState->fragmentProgramEnabled) {
        openGLState->fragmentProgramEnabled = 1;
        glEnable(0x8200);
    }

    return 0;
}

J_COLOR_SPACE COpenGLATITextFragmentShader_Disable(const COpenGLATITextFragmentShader * _this)
{
    COpenGLPixelState *openGLState;

    (void)_this;

    openGLState = CDirect3DPixelShader_GetOpenGLState();
    if (!openGLState->fragmentProgramEnabled) {
        return 0;
    }

    openGLState->fragmentProgramEnabled = 0;
    glDisable(0x8200);
    return 0;
}

J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_Disable(const COpenGLNVidiaRegisterCombinersProgram * _this)
{
    COpenGLPixelState *openGLState;

    (void)_this;

    openGLState = CDirect3DPixelShader_GetOpenGLState();
    if (!openGLState->fragmentProgramEnabled) {
        return 0;
    }

    openGLState->fragmentProgramEnabled = 0;
    glDisable(0x86de);
    glDisable(0x8522);
    return 0;
}

J_COLOR_SPACE COpenGLARBFragmentProgram_Enable(const COpenGLARBFragmentProgram * _this)
{
    const COpenGLARBFragmentProgramImpl *program;
    COpenGLPixelState *openGLState;

    program = (const COpenGLARBFragmentProgramImpl *)_this;
    openGLState = CDirect3DPixelShader_GetOpenGLState();
    ++g_fp_enable_count;

    if (openGLState->boundFragmentProgram != program->programId) {
        ++g_fp_bind_count;
        glBindProgramARB(0x8804, program->programId);
        openGLState->boundFragmentProgram = program->programId;
    }

    if (!openGLState->fragmentProgramEnabled) {
        openGLState->fragmentProgramEnabled = 1;
        glEnable(0x8804);
    }

    return 0;
}

/* line 29 */
__attribute__((naked))
void ZN20CDirect3DPixelShaderD2Ev(void) /* CDirect3DPixelShader_~CDirect3DPixelShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_base, (%eax)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n" /* line 33 */
        "cmpl %eax, 0x818(%edx)\n"
        "je .Lf1c2b8_0001c2ec\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "popl %ebp\n" /* line 43 */
        "retl\n"
        ".Lf1c2b8_0001c2ec:\n"
        "movl $0, 0x818(%edx)\n" /* line 345 */
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "popl %ebp\n" /* line 43 */
        "retl\n"
    );
}

/* line 29 */
__attribute__((naked))
void ZN20CDirect3DPixelShaderD1Ev(void) /* CDirect3DPixelShader_~CDirect3DPixelShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 29 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_base, (%eax)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n" /* line 33 */
        "cmpl %eax, 0x818(%edx)\n"
        "je .Lf1c310_0001c344\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "popl %ebp\n" /* line 43 */
        "retl\n"
        ".Lf1c310_0001c344:\n"
        "movl $0, 0x818(%edx)\n" /* line 345 */
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %eax\n" /* line 644 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "popl %ebp\n" /* line 43 */
        "retl\n"
    );
}

/* line 104 */
__attribute__((naked))
void ZN28COpenGLATITextFragmentShaderD1Ev(void) /* COpenGLATITextFragmentShader_~COpenGLATITextFragmentShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_ATI, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 108 */
        "cmpl %esi, 0x818(%eax)\n" /* this */
        "je .Lf1c368_0001c3a7\n"
        ".Lf1c368_0001c386:\n"
        "leal 0xc(%esi), %eax\n" /* line 115 | this */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl %esi, 8(%ebp)\n" /* line 116 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ZN20CDirect3DPixelShaderD2Ev\n"
        ".Lf1c368_0001c3a7:\n"
        "cmpb $0, 0x820(%eax)\n" /* line 144 */
        "je .Lf1c368_0001c386\n"
        "movb $0, 0x820(%eax)\n" /* line 347 */
        "movl $0x8200, (%esp)\n" /* line 147 */
        "calll glDisable\n"
        "jmp .Lf1c368_0001c386\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 116 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 104 */
__attribute__((naked))
void ZN28COpenGLATITextFragmentShaderD0Ev(void) /* COpenGLATITextFragmentShader_~COpenGLATITextFragmentShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 104 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_ATI, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 108 */
        "cmpl %esi, 0x818(%eax)\n" /* this */
        "je .Lf1c3d8_0001c41f\n"
        ".Lf1c3d8_0001c3f6:\n"
        "leal 0xc(%esi), %eax\n" /* line 115 | this */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl %esi, (%esp)\n" /* line 116 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %esi, 8(%ebp)\n" /* this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf1c3d8_0001c41f:\n"
        "cmpb $0, 0x820(%eax)\n" /* line 144 */
        "je .Lf1c3d8_0001c3f6\n"
        "movb $0, 0x820(%eax)\n" /* line 347 */
        "movl $0x8200, (%esp)\n" /* line 147 */
        "calll glDisable\n"
        "jmp .Lf1c3d8_0001c3f6\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 116 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 83 */
__attribute__((naked))
J_COLOR_SPACE COpenGLATITextFragmentShader_COpenGLATITextFragmentShader(const COpenGLATITextFragmentShader * _this, const J_COLOR_SPACE * pSrcData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 83 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* pSrcData */
        "movl $0, 8(%esi)\n" /* line 22 */
        "movl $1, 4(%esi)\n" /* line 64 */
        "movl $vtbl_CDirect3DPixelShader_ATI, (%esi)\n" /* line 85 | this */
        "movl $0, 0xc(%esi)\n" /* this */
        /* { scope 1 */
        "leal -0x1c(%ebp), %eax\n" /* line 90 | CurrentProgram */
        "movl %eax, 8(%esp)\n"
        "movl $0x8677, 4(%esp)\n"
        "movl $0x8200, (%esp)\n"
        "calll glGetProgramivARB\n"
        "leal 0xc(%esi), %eax\n" /* line 94 | this */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glGenProgramsARB\n"
        "movl 0xc(%esi), %eax\n" /* line 95 | this */
        "movl %eax, 4(%esp)\n"
        "movl $0x8200, (%esp)\n"
        "calll glBindProgramARB\n"
        "movl %ebx, 0xc(%esp)\n" /* line 97 | pSrcData */
        "cld\n" /* line 96 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %ebx, %edi\n" /* pSrcData */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x8875, 4(%esp)\n"
        "movl $0x8200, (%esp)\n"
        "calll glProgramStringARB\n"
        "movl -0x1c(%ebp), %eax\n" /* line 99 | CurrentProgram */
        "movl %eax, 4(%esp)\n"
        "movl $0x8200, (%esp)\n"
        "calll glBindProgramARB\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 100 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* pSrcData */
        "movl %esi, (%esp)\n" /* this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %ebx, (%esp)\n" /* pSrcData */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: COpenGLATITextFragmentShader_COpenGLATITextFragmentShader (0x1c516) */

/* line 168 */
__attribute__((naked))
J_COLOR_SPACE COpenGLNVidiaRegisterCombinersProgram_COpenGLNVidiaRegisterCombinersProgram(const COpenGLNVidiaRegisterCombinersProgram * _this, const J_COLOR_SPACE *pSrcData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 168 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0, 8(%eax)\n" /* line 22 */
        "movl $1, 4(%eax)\n" /* line 64 */
        "movl $vtbl_CDirect3DPixelShader_NVidia, (%eax)\n" /* line 171 */
        "movl 0xc(%ebp), %edx\n" /* pSrcData */
        "movl %edx, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "popl %ebp\n" /* line 174 */
        "retl\n"
    );
}

/* line 178 */
__attribute__((naked))
void ZN37COpenGLNVidiaRegisterCombinersProgramD2Ev(void) /* COpenGLNVidiaRegisterCombinersProgram_~COpenGLNVidiaRegisterCombinersProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 178 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_NVidia, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 182 */
        "cmpl %esi, 0x818(%eax)\n" /* this */
        "je .Lf1c608_0001c634\n"
        ".Lf1c608_0001c626:\n"
        "movl %esi, 8(%ebp)\n" /* line 188 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ZN20CDirect3DPixelShaderD2Ev\n"
        ".Lf1c608_0001c634:\n"
        "cmpb $0, 0x820(%eax)\n" /* line 235 */
        "je .Lf1c608_0001c626\n"
        "movb $0, 0x820(%eax)\n" /* line 347 */
        "movl $0x86de, (%esp)\n" /* line 238 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 239 */
        "calll glDisable\n"
        "movl %esi, 8(%ebp)\n" /* line 188 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 178 */
__attribute__((naked))
void ZN37COpenGLNVidiaRegisterCombinersProgramD1Ev(void) /* COpenGLNVidiaRegisterCombinersProgram_~COpenGLNVidiaRegisterCombinersProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 178 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_NVidia, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 182 */
        "cmpl %esi, 0x818(%eax)\n" /* this */
        "je .Lf1c67c_0001c6a8\n"
        ".Lf1c67c_0001c69a:\n"
        "movl %esi, 8(%ebp)\n" /* line 188 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ZN20CDirect3DPixelShaderD2Ev\n"
        ".Lf1c67c_0001c6a8:\n"
        "cmpb $0, 0x820(%eax)\n" /* line 235 */
        "je .Lf1c67c_0001c69a\n"
        "movb $0, 0x820(%eax)\n" /* line 347 */
        "movl $0x86de, (%esp)\n" /* line 238 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 239 */
        "calll glDisable\n"
        "movl %esi, 8(%ebp)\n" /* line 188 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 178 */
__attribute__((naked))
void ZN37COpenGLNVidiaRegisterCombinersProgramD0Ev(void) /* COpenGLNVidiaRegisterCombinersProgram_~COpenGLNVidiaRegisterCombinersProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 178 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_NVidia, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 182 */
        "cmpl %esi, 0x818(%eax)\n" /* this */
        "je .Lf1c6f0_0001c724\n"
        ".Lf1c6f0_0001c70e:\n"
        "movl %esi, (%esp)\n" /* line 188 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %esi, 8(%ebp)\n" /* this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf1c6f0_0001c724:\n"
        "cmpb $0, 0x820(%eax)\n" /* line 235 */
        "je .Lf1c6f0_0001c70e\n"
        "movb $0, 0x820(%eax)\n" /* line 347 */
        "movl $0x86de, (%esp)\n" /* line 238 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 239 */
        "calll glDisable\n"
        "movl %esi, (%esp)\n" /* line 188 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %esi, 8(%ebp)\n" /* this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 273 */
__attribute__((naked))
J_COLOR_SPACE COpenGLARBFragmentProgram_COpenGLARBFragmentProgram(const COpenGLARBFragmentProgram * _this, const string *Name, const string *Code)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 22 | this */
        "movl $0, 8(%eax)\n"
        "movl $1, 4(%eax)\n" /* line 64 */
        "movl $vtbl_CDirect3DPixelShader_ARB, (%eax)\n" /* line 277 */
        "movl %eax, %edx\n"
        "addl $0xc, %edx\n"
        "movl 0xc(%ebp), %eax\n" /* Name */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x10, %eax\n"
        "movl 0x10(%ebp), %edx\n" /* Code */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1ERKSs\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl $0, 0x14(%ecx)\n"
        /* { scope 1: i */
        "leal -0x38(%ebp), %eax\n" /* line 280 | CurrentProgram */
        "movl %eax, 8(%esp)\n"
        "movl $0x8677, 4(%esp)\n"
        "movl $0x8804, (%esp)\n"
        "calll glGetProgramivARB\n"
        "movl 0x10(%ebp), %eax\n" /* line 269 | Code */
        "movl (%eax), %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* pSrcDataString */
        "movl $0, -0x4c(%ebp)\n" /* line 1509 | i */
        /* { scope 2: Number, TextureNameUse */
        /* { scope 3 */
        ".Lf1c774_0001c7f1:\n"
        "leal -0x22(%ebp), %edx\n" /* line 290 */
        "movl %edx, 8(%esp)\n"
        "movl $str_00215c14, 4(%esp)\n" /* " ]" */
        "leal -0x34(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl $0xa, 8(%esp)\n"
        "leal -0x25(%ebp), %eax\n" /* Number */
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %eax\n" /* i */
        "movl %eax, (%esp)\n"
        "calll itoa\n"
        "movl %eax, %esi\n"
        "leal -0x21(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00215c18, 4(%esp)\n" /* "texture[ " */
        "leal -0x3c(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl %edi, 4(%esp)\n" /* line 2083 */
        "leal -0x2c(%ebp), %ebx\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll __ZNSsC1ERKSs\n"
        "cld\n" /* line 257 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs6appendEPKcm\n"
        "movl %ebx, 4(%esp)\n" /* line 2046 | this */
        "leal -0x30(%ebp), %ebx\n" /* TextureNameUse, this */
        "movl %ebx, (%esp)\n" /* this */
        "calll __ZNSsC1ERKSs\n"
        "leal -0x34(%ebp), %edx\n" /* line 2047 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __ZNSs6appendERKSs\n"
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001c98a\n"
        ".Lf1c774_0001c8a3:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001c9b9\n"
        ".Lf1c774_0001c8b1:\n"
        "movl -0x34(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001c9e8\n"
        ".Lf1c774_0001c8bf:\n"
        "movl -0x30(%ebp), %edx\n" /* line 269 | TextureNameUse */
        "movl -0xc(%edx), %eax\n" /* line 585 */
        "movl %eax, 0xc(%esp)\n" /* line 1554 */
        "movl $0, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl 0x10(%ebp), %ecx\n" /* Code */
        "movl %ecx, (%esp)\n"
        "calll __ZNKSs4findEPKcmm\n"
        "addl $1, %eax\n" /* line 292 */
        "je .Lf1c774_0001c8f6\n"
        "movl $1, %eax\n" /* line 294 */
        "movzbl -0x4c(%ebp), %ecx\n" /* i */
        "shll %cl, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "orl %eax, 8(%edx)\n"
        ".Lf1c774_0001c8f6:\n"
        "movl -0x30(%ebp), %eax\n" /* line 277 | TextureNameUse */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 4 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001ca17\n"
        /* } scope */
        /* } scope */
        ".Lf1c774_0001c904:\n"
        "addl $1, -0x4c(%ebp)\n" /* line 287 | i */
        "cmpl $0x10, -0x4c(%ebp)\n" /* i */
        "jne .Lf1c774_0001c7f1\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 299 | this */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glGenProgramsARB\n"
        "movl 8(%ebp), %ecx\n" /* line 300 | this */
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x8804, (%esp)\n"
        "calll glBindProgramARB\n"
        "movl -0x50(%ebp), %eax\n" /* line 302 | pSrcDataString */
        "movl %eax, 0xc(%esp)\n"
        "cld\n" /* line 301 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x50(%ebp), %edi\n" /* pSrcDataString */
        "repne scasb %es:(%edi), %al\n"
        "notl %ecx\n"
        "subl $1, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl $0x8875, 4(%esp)\n"
        "movl $0x8804, (%esp)\n"
        "calll glProgramStringARB\n"
        "movl -0x38(%ebp), %eax\n" /* line 304 | CurrentProgram */
        "movl %eax, 4(%esp)\n"
        "movl $0x8804, (%esp)\n"
        "calll glBindProgramARB\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 305 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        /* { scope 2: Number, TextureNameUse */
        /* { scope 3 */
        ".Lf1c774_0001c98a:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001c8a3\n"
        "leal -0x1e(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001c8a3\n"
        ".Lf1c774_0001c9b9:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001c8b1\n"
        "leal -0x1d(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001c8b1\n"
        ".Lf1c774_0001c9e8:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001c8bf\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001c8bf\n"
        /* { scope 4 */
        ".Lf1c774_0001ca17:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001c904\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001c904\n"
        ".Lf1c774_0001ca46:\n"
        "movl %eax, %edi\n"
        ".Lf1c774_0001ca48:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        /* } scope */
        ".Lf1c774_0001ca4e:\n"
        "movl -0x34(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001cc22\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1c774_0001ca5c:\n"
        "movl 8(%ebp), %edx\n" /* line 269 | this */
        "movl 0x10(%edx), %eax\n"
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1: i */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001cabb\n"
        /* } scope */
        ".Lf1c774_0001ca69:\n"
        "movl 8(%ebp), %ecx\n" /* line 269 | this */
        "movl 0xc(%ecx), %eax\n"
        "leal -0xc(%eax), %esi\n" /* line 277 */
        /* { scope 1: i */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001ca93\n"
        /* } scope */
        ".Lf1c774_0001ca76:\n"
        "movl 8(%ebp), %eax\n" /* line 305 | this */
        "movl %eax, (%esp)\n"
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %edi, (%esp)\n"
        "calll __Unwind_Resume\n"
        ".Lf1c774_0001ca89:\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001ca5c\n"
        /* { scope 1: i */
        ".Lf1c774_0001ca93:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001ca76\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001ca76\n"
        /* } scope */
        /* { scope 1: i */
        ".Lf1c774_0001cabb:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jle .Lf1c774_0001cc6a\n"
        ".Lf1c774_0001cad6:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001ca69\n"
        ".Lf1c774_0001cade:\n"
        "movl %eax, %edi\n"
        ".Lf1c774_0001cae0:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001ca5c\n"
        ".Lf1c774_0001caeb:\n"
        "movl %eax, %edi\n"
        ".Lf1c774_0001caed:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        /* } scope */
        /* { scope 1: i */
        /* { scope 2: Number, TextureNameUse */
        /* { scope 3 */
        ".Lf1c774_0001caf3:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "je .Lf1c774_0001ca4e\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001ca48\n"
        "leal -0x1d(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001ca4e\n"
        "jmp .Lf1c774_0001ca46\n"
        "jmp .Lf1c774_0001ca46\n"
        "jmp .Lf1c774_0001caeb\n"
        "movl %eax, %edi\n"
        "movl -0x30(%ebp), %eax\n" /* line 277 | TextureNameUse */
        "leal -0xc(%eax), %esi\n"
        /* { scope 4 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 178 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1c774_0001cbf3\n"
        /* } scope */
        ".Lf1c774_0001cb58:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        "cmpl %ebx, %esi\n" /* line 224 */
        "je .Lf1c774_0001caf3\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001caed\n"
        "leal -0x1e(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001caf3\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001cb58\n"
        "movl %eax, %edi\n"
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %esi\n"
        /* { scope 4 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 178 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "je .Lf1c774_0001caf3\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001caf3\n"
        "leal -0x20(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001caf3\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001caf3\n"
        /* } scope */
        /* { scope 4 */
        ".Lf1c774_0001cbf3:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001cb58\n"
        "leal -0x1f(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001cb58\n"
        /* } scope */
        ".Lf1c774_0001cc22:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001cae0\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001ca5c\n"
        "movl %eax, %edi\n"
        "jmp .Lf1c774_0001ca76\n"
        "jmp .Lf1c774_0001ca89\n"
        "movl %eax, %edi\n"
        "jmp .Lf1c774_0001cad6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 1: i */
        ".Lf1c774_0001cc6a:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1c774_0001ca69\n"
        "jmp .Lf1c774_0001cade\n"
        "movl %eax, %edi\n"
        /* } scope */
        /* { scope 1: i */
        /* { scope 2: Number, TextureNameUse */
        /* { scope 3 */
        "movl -0x30(%ebp), %eax\n" /* line 277 | TextureNameUse */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 4 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "je .Lf1c774_0001cae0\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1c774_0001cae0\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1c774_0001cae0\n"
    );
}

/* overload skip: COpenGLARBFragmentProgram_COpenGLARBFragmentProgram (0x1ccc8) */

/* line 309 */
__attribute__((naked))
void ZN25COpenGLARBFragmentProgramD2Ev(void) /* COpenGLARBFragmentProgram_~COpenGLARBFragmentProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 309 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_ARB, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 313 */
        "cmpl %esi, 0x818(%ebx)\n" /* this */
        "je .Lf1d21c_0001d284\n"
        ".Lf1d21c_0001d23c:\n"
        "movl 0x14(%esi), %eax\n" /* line 318 | this */
        "cmpl %eax, 0x81c(%ebx)\n"
        "je .Lf1d21c_0001d2a2\n"
        ".Lf1d21c_0001d247:\n"
        "leal 0x14(%esi), %eax\n" /* line 324 | this */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl 0x10(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %ebx\n" /* line 224 */
        "jne .Lf1d21c_0001d2b8\n"
        /* } scope */
        ".Lf1d21c_0001d26a:\n"
        "movl 0xc(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf1d21c_0001d2e0\n"
        /* } scope */
        ".Lf1d21c_0001d274:\n"
        "movl %esi, (%esp)\n" /* line 325 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d21c_0001d284:\n"
        "cmpb $0, 0x820(%ebx)\n" /* line 354 */
        "je .Lf1d21c_0001d23c\n"
        "movb $0, 0x820(%ebx)\n" /* line 347 */
        "movl $0x8804, (%esp)\n" /* line 357 */
        "calll glDisable\n"
        "jmp .Lf1d21c_0001d23c\n"
        ".Lf1d21c_0001d2a2:\n"
        "movl $0xffffffff, 0x81c(%ebx)\n" /* line 346 */
        "movl $0xffffffff, 0x818(%ebx)\n" /* line 345 */
        "jmp .Lf1d21c_0001d247\n"
        /* { scope 1 */
        ".Lf1d21c_0001d2b8:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d21c_0001d26a\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d21c_0001d26a\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1d21c_0001d2e0:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d21c_0001d274\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d21c_0001d274\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edx, %ebx\n" /* line 224 */
        "jne .Lf1d21c_0001d378\n"
        /* } scope */
        ".Lf1d21c_0001d324:\n"
        "movl 0xc(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl -0x2c(%ebp), %ebx\n" /* line 224 */
        "jne .Lf1d21c_0001d350\n"
        /* } scope */
        ".Lf1d21c_0001d32f:\n"
        "movl %esi, (%esp)\n" /* line 325 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %edi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf1d21c_0001d324\n"
        "movl %eax, %edi\n"
        "jmp .Lf1d21c_0001d32f\n"
        /* { scope 1 */
        ".Lf1d21c_0001d350:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d21c_0001d32f\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d21c_0001d32f\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1d21c_0001d378:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d21c_0001d324\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d21c_0001d324\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1d21c_0001d324\n"
    );
}

/* line 309 */
__attribute__((naked))
void ZN25COpenGLARBFragmentProgramD1Ev(void) /* COpenGLARBFragmentProgram_~COpenGLARBFragmentProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 309 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_ARB, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 313 */
        "cmpl %esi, 0x818(%ebx)\n" /* this */
        "je .Lf1d3b0_0001d418\n"
        ".Lf1d3b0_0001d3d0:\n"
        "movl 0x14(%esi), %eax\n" /* line 318 | this */
        "cmpl %eax, 0x81c(%ebx)\n"
        "je .Lf1d3b0_0001d436\n"
        ".Lf1d3b0_0001d3db:\n"
        "leal 0x14(%esi), %eax\n" /* line 324 | this */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl 0x10(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %ebx\n" /* line 224 */
        "jne .Lf1d3b0_0001d44c\n"
        /* } scope */
        ".Lf1d3b0_0001d3fe:\n"
        "movl 0xc(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf1d3b0_0001d474\n"
        /* } scope */
        ".Lf1d3b0_0001d408:\n"
        "movl %esi, (%esp)\n" /* line 325 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d3b0_0001d418:\n"
        "cmpb $0, 0x820(%ebx)\n" /* line 354 */
        "je .Lf1d3b0_0001d3d0\n"
        "movb $0, 0x820(%ebx)\n" /* line 347 */
        "movl $0x8804, (%esp)\n" /* line 357 */
        "calll glDisable\n"
        "jmp .Lf1d3b0_0001d3d0\n"
        ".Lf1d3b0_0001d436:\n"
        "movl $0xffffffff, 0x81c(%ebx)\n" /* line 346 */
        "movl $0xffffffff, 0x818(%ebx)\n" /* line 345 */
        "jmp .Lf1d3b0_0001d3db\n"
        /* { scope 1 */
        ".Lf1d3b0_0001d44c:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d3b0_0001d3fe\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d3b0_0001d3fe\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1d3b0_0001d474:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d3b0_0001d408\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d3b0_0001d408\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edx, %ebx\n" /* line 224 */
        "jne .Lf1d3b0_0001d50c\n"
        /* } scope */
        ".Lf1d3b0_0001d4b8:\n"
        "movl 0xc(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl -0x2c(%ebp), %ebx\n" /* line 224 */
        "jne .Lf1d3b0_0001d4e4\n"
        /* } scope */
        ".Lf1d3b0_0001d4c3:\n"
        "movl %esi, (%esp)\n" /* line 325 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %edi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf1d3b0_0001d4b8\n"
        "movl %eax, %edi\n"
        "jmp .Lf1d3b0_0001d4c3\n"
        /* { scope 1 */
        ".Lf1d3b0_0001d4e4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d3b0_0001d4c3\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d3b0_0001d4c3\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1d3b0_0001d50c:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d3b0_0001d4b8\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d3b0_0001d4b8\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1d3b0_0001d4b8\n"
    );
}

/* line 309 */
__attribute__((naked))
void ZN25COpenGLARBFragmentProgramD0Ev(void) /* COpenGLARBFragmentProgram_~COpenGLARBFragmentProgram */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 309 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl $vtbl_CDirect3DPixelShader_ARB, (%esi)\n" /* this */
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 313 */
        "cmpl %esi, 0x818(%ebx)\n" /* this */
        "je .Lf1d544_0001d5b4\n"
        ".Lf1d544_0001d564:\n"
        "movl 0x14(%esi), %eax\n" /* line 318 | this */
        "cmpl %eax, 0x81c(%ebx)\n"
        "je .Lf1d544_0001d5d2\n"
        ".Lf1d544_0001d56f:\n"
        "leal 0x14(%esi), %eax\n" /* line 324 | this */
        "movl %eax, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glDeleteProgramsARB\n"
        "movl 0x10(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edi\n" /* line 178 */
        "cmpl %edi, %ebx\n" /* line 224 */
        "jne .Lf1d544_0001d5e8\n"
        /* } scope */
        ".Lf1d544_0001d592:\n"
        "movl 0xc(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf1d544_0001d610\n"
        /* } scope */
        ".Lf1d544_0001d59c:\n"
        "movl %esi, (%esp)\n" /* line 325 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %esi, (%esp)\n" /* this */
        "calll __ZdlPv\n"
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1d544_0001d5b4:\n"
        "cmpb $0, 0x820(%ebx)\n" /* line 354 */
        "je .Lf1d544_0001d564\n"
        "movb $0, 0x820(%ebx)\n" /* line 347 */
        "movl $0x8804, (%esp)\n" /* line 357 */
        "calll glDisable\n"
        "jmp .Lf1d544_0001d564\n"
        ".Lf1d544_0001d5d2:\n"
        "movl $0xffffffff, 0x81c(%ebx)\n" /* line 346 */
        "movl $0xffffffff, 0x818(%ebx)\n" /* line 345 */
        "jmp .Lf1d544_0001d56f\n"
        /* { scope 1 */
        ".Lf1d544_0001d5e8:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d544_0001d592\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d544_0001d592\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1d544_0001d610:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d544_0001d59c\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d544_0001d59c\n"
        "movl %eax, %edi\n"
        /* } scope */
        "movl 0x10(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0x2c(%ebp)\n"
        "cmpl %edx, %ebx\n" /* line 224 */
        "jne .Lf1d544_0001d6a8\n"
        /* } scope */
        ".Lf1d544_0001d654:\n"
        "movl 0xc(%esi), %eax\n" /* line 269 */
        "leal -0xc(%eax), %ebx\n" /* line 277 */
        /* { scope 1 */
        "cmpl -0x2c(%ebp), %ebx\n" /* line 224 */
        "jne .Lf1d544_0001d680\n"
        /* } scope */
        ".Lf1d544_0001d65f:\n"
        "movl %esi, (%esp)\n" /* line 325 | this */
        "calll ZN20CDirect3DPixelShaderD2Ev\n"
        "movl %edi, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "jmp .Lf1d544_0001d654\n"
        "movl %eax, %edi\n"
        "jmp .Lf1d544_0001d65f\n"
        /* { scope 1 */
        ".Lf1d544_0001d680:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d544_0001d65f\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d544_0001d65f\n"
        /* } scope */
        /* { scope 1 */
        ".Lf1d544_0001d6a8:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1d544_0001d654\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1d544_0001d654\n"
        "movl %eax, %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "jmp .Lf1d544_0001d654\n"
    );
}

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
