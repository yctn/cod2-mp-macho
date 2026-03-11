/* ASM dump from: CDirect3DVertexShader.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVertexShader.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DVertexShader.h"
 *   #include "Mac/Win32 SDK/objbase.h"
 *   #include "Mac/Win32 SDK/DirectX SDK/d3d9.h"
 */

typedef struct {
    void **vtablePrimary;
    void **vtableSecondary;
    unsigned char baseState[0x18c];
    ULONG refCount;
    unsigned char isBound;
} CDirect3DVertexShaderImpl;

extern void *vtbl_CDirect3DVertexShader[];
extern void *vtbl_CDirect3DVertexShader_secondary[];
unsigned int COpenGLVertexProgram_COpenGLVertexProgram(const COpenGLVertexProgram * _this, const char * pSrcData);
void ZN20COpenGLVertexProgramD2Ev(const COpenGLVertexProgram * _this); /* COpenGLVertexProgram_~COpenGLVertexProgram */
void __ZdlPv(void *ptr);

ULONG CDirect3DVertexShader_AddRef(const CDirect3DVertexShader * _this);
void ZN21CDirect3DVertexShaderD1Ev(const CDirect3DVertexShader * _this); /* CDirect3DVertexShader_~CDirect3DVertexShader */
void ZN21CDirect3DVertexShaderD0Ev(const CDirect3DVertexShader * _this); /* CDirect3DVertexShader_~CDirect3DVertexShader */
HRESULT CDirect3DVertexShader_QueryInterface(const CDirect3DVertexShader * _this, const IID *iid, unsigned char * *ppvObj);
ULONG CDirect3DVertexShader_Release(const CDirect3DVertexShader * _this);
HRESULT CDirect3DVertexShader_GetDevice(const CDirect3DVertexShader * _this, IDirect3DDevice9 * *ppDevice);
unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader * _this, const char * pSrcData);
HRESULT CDirect3DVertexShader_GetFunction(const CDirect3DVertexShader * _this, UINT *pSizeOfData);

/* line 48 */
ULONG CDirect3DVertexShader_AddRef(const CDirect3DVertexShader * _this)
{
    CDirect3DVertexShaderImpl *shader;

    shader = (CDirect3DVertexShaderImpl *)_this;
    ++shader->refCount;
    return shader->refCount;
}

/* line 28 */
void ZN21CDirect3DVertexShaderD1Ev(const CDirect3DVertexShader * _this) /* CDirect3DVertexShader_~CDirect3DVertexShader */
{
    CDirect3DVertexShaderImpl *shader;

    shader = (CDirect3DVertexShaderImpl *)_this;
    shader->vtablePrimary = vtbl_CDirect3DVertexShader;
    shader->vtableSecondary = vtbl_CDirect3DVertexShader_secondary;
    ZN20COpenGLVertexProgramD2Ev((const COpenGLVertexProgram *)((const unsigned char *)_this + 4));
}

/* line 28 */
void ZN21CDirect3DVertexShaderD0Ev(const CDirect3DVertexShader * _this) /* CDirect3DVertexShader_~CDirect3DVertexShader */
{
    ZN21CDirect3DVertexShaderD1Ev(_this);
    __ZdlPv((void *)_this);
}

/* line 37 */
HRESULT CDirect3DVertexShader_QueryInterface(const CDirect3DVertexShader * _this, const IID *iid, unsigned char * *ppvObj)
{
    (void)iid;

    *ppvObj = (unsigned char *)_this;
    CDirect3DVertexShader_AddRef(_this);
    return 0;
}

/* line 56 */
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

/* line 71 */
HRESULT CDirect3DVertexShader_GetDevice(const CDirect3DVertexShader * _this, IDirect3DDevice9 * *ppDevice)
{
    (void)_this;
    (void)ppDevice;
    return 0;
}

/* line 18 */
unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader * _this, const char * pSrcData)
{
    CDirect3DVertexShaderImpl *shader;
    unsigned int result;

    shader = (CDirect3DVertexShaderImpl *)_this;
    result = COpenGLVertexProgram_COpenGLVertexProgram((const COpenGLVertexProgram *)((const unsigned char *)_this + 4), pSrcData);
    shader->vtablePrimary = vtbl_CDirect3DVertexShader;
    shader->vtableSecondary = vtbl_CDirect3DVertexShader_secondary;
    shader->isBound = 0;
    shader->refCount = 1;
    return (unsigned char)result;
}

/* line 40 */
HRESULT CDirect3DVertexShader_GetFunction(const CDirect3DVertexShader * _this, UINT *pSizeOfData)
{
    (void)_this;
    (void)pSizeOfData;
    return 0;
}
