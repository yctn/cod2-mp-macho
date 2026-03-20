/* Clean CDirect3DVertexShader implementation for Linux/Emscripten */
/* Replaces Mac OpenGL ARB vertex program implementation with stubs */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVertexShader.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

/*
 * The original Mac implementation stored a COpenGLVertexProgram at offset +4
 * (0x18c bytes of base state) plus refCount and isBound fields.
 * For the WebGL2 port, we stub the OpenGL program and just track refcount.
 */
typedef struct {
    void **vtablePrimary;
    void **vtableSecondary;
    unsigned char baseState[0x18c]; /* placeholder for COpenGLVertexProgram base */
    ULONG refCount;
    unsigned char isBound;
} CDirect3DVertexShaderImpl;

extern void *vtbl_CDirect3DVertexShader[];
extern void *vtbl_CDirect3DVertexShader_secondary[];

/* Forward declarations */
ULONG CDirect3DVertexShader_AddRef(const CDirect3DVertexShader * _this);
void ZN21CDirect3DVertexShaderD1Ev(const CDirect3DVertexShader * _this);
void ZN21CDirect3DVertexShaderD0Ev(const CDirect3DVertexShader * _this);
HRESULT CDirect3DVertexShader_QueryInterface(const CDirect3DVertexShader * _this, const IID *iid, unsigned char * *ppvObj);
ULONG CDirect3DVertexShader_Release(const CDirect3DVertexShader * _this);
HRESULT CDirect3DVertexShader_GetDevice(const CDirect3DVertexShader * _this, IDirect3DDevice9 * *ppDevice);
unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader * _this, const char * pSrcData);
HRESULT CDirect3DVertexShader_GetFunction(const CDirect3DVertexShader * _this, UINT *pSizeOfData);

/*
 * COpenGLVertexProgram constructor/destructor are defined in COpenGL.c.
 * They create ARB vertex programs via glGenProgramsARB/glProgramStringARB.
 * When COpenGL.c is converted for WebGL2, those will become stubs too.
 * We just declare them extern here.
 */
extern unsigned int COpenGLVertexProgram_COpenGLVertexProgram(const COpenGLVertexProgram * _this, const char * pSrcData);
extern void ZN20COpenGLVertexProgramD2Ev(void);

/* --- IUnknown --- */

ULONG CDirect3DVertexShader_AddRef(const CDirect3DVertexShader * _this)
{
    CDirect3DVertexShaderImpl *shader;

    shader = (CDirect3DVertexShaderImpl *)_this;
    ++shader->refCount;
    return shader->refCount;
}

HRESULT CDirect3DVertexShader_QueryInterface(const CDirect3DVertexShader * _this, const IID *iid, unsigned char * *ppvObj)
{
    (void)iid;

    *ppvObj = (unsigned char *)_this;
    CDirect3DVertexShader_AddRef(_this);
    return 0;
}

ULONG CDirect3DVertexShader_Release(const CDirect3DVertexShader * _this)
{
    CDirect3DVertexShaderImpl *shader;
    ULONG refCount;

    shader = (CDirect3DVertexShaderImpl *)_this;
    refCount = --shader->refCount;
    if (!refCount) {
        ZN21CDirect3DVertexShaderD0Ev(_this);
    }

    return refCount;
}

/* --- Destructors --- */

void ZN21CDirect3DVertexShaderD1Ev(const CDirect3DVertexShader * _this)
{
    CDirect3DVertexShaderImpl *shader;

    shader = (CDirect3DVertexShaderImpl *)_this;
    shader->vtablePrimary = vtbl_CDirect3DVertexShader;
    shader->vtableSecondary = vtbl_CDirect3DVertexShader_secondary;
    /* Original called ZN20COpenGLVertexProgramD2Ev on the embedded base; stub is no-op */
}

void ZN21CDirect3DVertexShaderD0Ev(const CDirect3DVertexShader * _this)
{
    ZN21CDirect3DVertexShaderD1Ev(_this);
    free((void *)_this);
}

/* --- Constructor --- */

unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader * _this, const char * pSrcData)
{
    CDirect3DVertexShaderImpl *shader;

    shader = (CDirect3DVertexShaderImpl *)_this;
    memset(shader->baseState, 0, sizeof(shader->baseState));
    /* Compile the ARB vertex program via COpenGLVertexProgram constructor.
     * The VP program ID is stored at baseState[0] (offset +8 from shader start). */
    COpenGLVertexProgram_COpenGLVertexProgram(
        (const COpenGLVertexProgram *)shader->baseState, pSrcData);
    shader->vtablePrimary = vtbl_CDirect3DVertexShader;
    shader->vtableSecondary = vtbl_CDirect3DVertexShader_secondary;
    shader->isBound = 0;
    shader->refCount = 1;
    return 0;
}

/* --- IDirect3DVertexShader9 stubs --- */

HRESULT CDirect3DVertexShader_GetDevice(const CDirect3DVertexShader * _this, IDirect3DDevice9 * *ppDevice)
{
    (void)_this;
    (void)ppDevice;
    return 0;
}

HRESULT CDirect3DVertexShader_GetFunction(const CDirect3DVertexShader * _this, UINT *pSizeOfData)
{
    (void)_this;
    (void)pSizeOfData;
    return 0;
}
