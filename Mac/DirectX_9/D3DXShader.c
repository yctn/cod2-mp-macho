/* Clean D3DXShader implementation for Linux/WebGL2 */
/* Shader compilation stubs — WebGL2 will use GLSL ES compiled differently */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern void *vtbl_CD3DXBuffer[];
extern void *vtbl_CD3DXConstantTable[];

/* --- CD3DXBuffer (ID3DXBuffer) --- */

typedef struct {
    void **vtable;
    ULONG refCount;
    void *data;
    UINT32 size;
} CD3DXBufferImpl;

HRESULT CD3DXBuffer_QueryInterface(const void *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    return 0;
}

ULONG CD3DXBuffer_AddRef(const void *_this)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)_this;
    return ++buf->refCount;
}

ULONG CD3DXBuffer_Release(const void *_this)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)_this;
    ULONG rc = --buf->refCount;
    if (!rc) {
        free(buf->data);
        free(buf);
    }
    return rc;
}

void *CD3DXBuffer_GetBufferPointer(const void *_this)
{
    return ((CD3DXBufferImpl *)_this)->data;
}

UINT32 CD3DXBuffer_GetBufferSize(const void *_this)
{
    return ((CD3DXBufferImpl *)_this)->size;
}

void ZN11CD3DXBufferD1Ev(const void *_this)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)_this;
    buf->vtable = vtbl_CD3DXBuffer;
    free(buf->data);
    buf->data = NULL;
}

void ZN11CD3DXBufferD0Ev(const void *_this)
{
    ZN11CD3DXBufferD1Ev(_this);
    free((void *)_this);
}

static CD3DXBufferImpl *CD3DXBuffer_Create(const void *data, UINT32 size)
{
    CD3DXBufferImpl *buf = (CD3DXBufferImpl *)calloc(1, sizeof(CD3DXBufferImpl));
    buf->vtable = vtbl_CD3DXBuffer;
    buf->refCount = 1;
    buf->size = size;
    if (size && data) {
        buf->data = malloc(size);
        memcpy(buf->data, data, size);
    } else if (size) {
        buf->data = calloc(1, size);
    }
    return buf;
}

/* --- CD3DXConstantTable (ID3DXConstantTable) --- */

typedef struct {
    void **vtable;
    ULONG refCount;
    void *data;
    UINT32 size;
} CD3DXConstantTableImpl;

HRESULT CD3DXConstantTable_QueryInterface(const void *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    return 0;
}

ULONG CD3DXConstantTable_AddRef(const void *_this)
{
    return ++((CD3DXConstantTableImpl *)_this)->refCount;
}

ULONG CD3DXConstantTable_Release(const void *_this)
{
    CD3DXConstantTableImpl *ct = (CD3DXConstantTableImpl *)_this;
    ULONG rc = --ct->refCount;
    if (!rc) {
        free(ct->data);
        free(ct);
    }
    return rc;
}

void *CD3DXConstantTable_GetBufferPointer(const void *_this) { return ((CD3DXConstantTableImpl *)_this)->data; }
UINT32 CD3DXConstantTable_GetBufferSize(const void *_this) { return ((CD3DXConstantTableImpl *)_this)->size; }
HRESULT CD3DXConstantTable_GetDesc(const void *_this, void *pDesc) { (void)_this; memset(pDesc, 0, 32); return 0; }
HRESULT CD3DXConstantTable_GetConstantDesc(const void *_this, const void *hConstant, void *pConstantDesc, UINT *pCount) { (void)_this; (void)hConstant; (void)pConstantDesc; *pCount = 0; return 0; }
UINT CD3DXConstantTable_GetSamplerIndex(const void *_this, const void *hConstant) { (void)_this; (void)hConstant; return 0; }
void *CD3DXConstantTable_GetConstant(const void *_this, const void *hConstant, UINT Index) { (void)_this; (void)hConstant; (void)Index; return NULL; }
void *CD3DXConstantTable_GetConstantByName(const void *_this, const void *hConstant, const char *pName) { (void)_this; (void)hConstant; (void)pName; return NULL; }
void *CD3DXConstantTable_GetConstantElement(const void *_this, const void *hConstant, UINT Index) { (void)_this; (void)hConstant; (void)Index; return NULL; }
HRESULT CD3DXConstantTable_SetDefaults(const void *_this, void *pDevice) { (void)_this; (void)pDevice; return 0; }
HRESULT CD3DXConstantTable_SetValue(const void *_this, void *pDevice, const void *hConstant, const void *pData, UINT Bytes) { (void)_this; (void)pDevice; (void)hConstant; (void)pData; (void)Bytes; return 0; }
HRESULT CD3DXConstantTable_SetBool(const void *_this, void *d, const void *h, BOOL b) { (void)_this; (void)d; (void)h; (void)b; return 0; }
HRESULT CD3DXConstantTable_SetBoolArray(const void *_this, void *d, const void *h, const BOOL *b, UINT n) { (void)_this; (void)d; (void)h; (void)b; (void)n; return 0; }
HRESULT CD3DXConstantTable_SetInt(const void *_this, void *d, const void *h, INT n) { (void)_this; (void)d; (void)h; (void)n; return 0; }
HRESULT CD3DXConstantTable_SetIntArray(const void *_this, void *d, const void *h, const INT *n, UINT c) { (void)_this; (void)d; (void)h; (void)n; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetFloat(const void *_this, void *d, const void *h, float f) { (void)_this; (void)d; (void)h; (void)f; return 0; }
HRESULT CD3DXConstantTable_SetFloatArray(const void *_this, void *d, const void *h, const float *f, UINT c) { (void)_this; (void)d; (void)h; (void)f; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetVector(const void *_this, void *d, const void *h, const void *v) { (void)_this; (void)d; (void)h; (void)v; return 0; }
HRESULT CD3DXConstantTable_SetVectorArray(const void *_this, void *d, const void *h, const void *v, UINT c) { (void)_this; (void)d; (void)h; (void)v; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrix(const void *_this, void *d, const void *h, const void *m) { (void)_this; (void)d; (void)h; (void)m; return 0; }
HRESULT CD3DXConstantTable_SetMatrixArray(const void *_this, void *d, const void *h, const void *m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrixPointerArray(const void *_this, void *d, const void *h, const void **m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrixTranspose(const void *_this, void *d, const void *h, const void *m) { (void)_this; (void)d; (void)h; (void)m; return 0; }
HRESULT CD3DXConstantTable_SetMatrixTransposeArray(const void *_this, void *d, const void *h, const void *m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }
HRESULT CD3DXConstantTable_SetMatrixTransposePointerArray(const void *_this, void *d, const void *h, const void **m, UINT c) { (void)_this; (void)d; (void)h; (void)m; (void)c; return 0; }

void ZN18CD3DXConstantTableD1Ev(const void *_this)
{
    CD3DXConstantTableImpl *ct = (CD3DXConstantTableImpl *)_this;
    ct->vtable = vtbl_CD3DXConstantTable;
    free(ct->data);
    ct->data = NULL;
}

void ZN18CD3DXConstantTableD0Ev(const void *_this)
{
    ZN18CD3DXConstantTableD1Ev(_this);
    free((void *)_this);
}

/* --- D3DXCompileShader --- */
/* The renderer calls this to compile HLSL shaders. On Mac, this translated HLSL→GLSL.
   For WebGL2, we'll need a proper GLSL ES translation pass eventually.
   For now, return a dummy shader blob so the renderer doesn't crash. */

HRESULT D3DXCompileShader(
    const char *pSrcData, UINT SrcDataLen,
    const void *pDefines, void *pInclude,
    const char *pFunctionName, const char *pProfile,
    DWORD Flags, void **ppShader, void **ppErrorMsgs,
    void **ppConstantTable)
{
    (void)pSrcData; (void)SrcDataLen; (void)pDefines; (void)pInclude;
    (void)pFunctionName; (void)pProfile; (void)Flags;

    /* Create a minimal shader blob — 4 bytes of dummy data */
    if (ppShader) {
        *ppShader = CD3DXBuffer_Create("\0\0\0\0", 4);
    }
    if (ppErrorMsgs) {
        *ppErrorMsgs = NULL;
    }
    if (ppConstantTable) {
        CD3DXConstantTableImpl *ct = (CD3DXConstantTableImpl *)calloc(1, sizeof(CD3DXConstantTableImpl));
        ct->vtable = vtbl_CD3DXConstantTable;
        ct->refCount = 1;
        *ppConstantTable = ct;
    }
    return 0;
}

/* --- IncludeClass for D3DX shader includes --- */
/* The renderer's Material_PreLoadSingleShaderText creates an include handler.
   IncludeClass_Open is called during shader compilation to resolve #include directives. */

int IncludeClass_Open(void *_this, int IncludeType, const char *pFileName,
    const void *pParentData, const void **ppData, UINT *pBytes)
{
    (void)_this; (void)IncludeType; (void)pParentData;
    (void)pFileName;
    /* Return empty include — shader compilation is stubbed anyway */
    *ppData = "";
    *pBytes = 0;
    return 0;
}

int IncludeClass_Close(void *_this, const void *pData)
{
    (void)_this; (void)pData;
    return 0;
}
