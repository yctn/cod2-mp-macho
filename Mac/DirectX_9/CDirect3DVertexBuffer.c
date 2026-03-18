/* Clean CDirect3DVertexBuffer implementation for Linux */
/* Replaces Mac Apple-extension-based implementation with simple malloc buffers */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVertexBuffer.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern void *vtbl_CDirect3DVertexBuffer[];
extern void *vtbl_CStaticCacheInfo[];
extern void *imp___ZTV15CCacheInfoBlock;

/* Clean VB struct — no CMemoryBuffer, no fences, no CStaticCacheInfo */
typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 lengthBytes;
    byte *data;
    DWORD usage;
} CDirect3DVertexBufferClean;

/* Forward declarations */
ULONG CDirect3DVertexBuffer_AddRef(const CDirect3DVertexBuffer *_this);
void ZN21CDirect3DVertexBufferD0Ev(void *_this);
void ZN21CDirect3DVertexBufferD1Ev(void *_this);
void ZN21CDirect3DVertexBufferD2Ev(void *_this);

/* --- IUnknown --- */

ULONG CDirect3DVertexBuffer_AddRef(const CDirect3DVertexBuffer *_this)
{
    CDirect3DVertexBufferClean *vb = (CDirect3DVertexBufferClean *)_this;
    return ++vb->refCount;
}

HRESULT CDirect3DVertexBuffer_QueryInterface(const CDirect3DVertexBuffer *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    CDirect3DVertexBuffer_AddRef(_this);
    return 0;
}

ULONG CDirect3DVertexBuffer_Release(const CDirect3DVertexBuffer *_this)
{
    CDirect3DVertexBufferClean *vb = (CDirect3DVertexBufferClean *)_this;
    ULONG rc = --vb->refCount;
    if (!rc) {
        /* Call deleting destructor via vtable slot [15] (offset 60) */
        ((void (*)(void *))vb->vtable[15])((void *)_this);
    }
    return rc;
}

/* --- IDirect3DVertexBuffer9 --- */

HRESULT CDirect3DVertexBuffer_Lock(const CDirect3DVertexBuffer *_this, UINT OffsetToLock, UINT SizeToLock, void **ppbData, DWORD Flags)
{
    CDirect3DVertexBufferClean *vb = (CDirect3DVertexBufferClean *)_this;
    static int lock_count = 0;
    (void)SizeToLock;
    (void)Flags;
    *ppbData = vb->data + OffsetToLock;
    if (lock_count++ < 10)
        fprintf(stderr, "[VB_LOCK] vb=%p off=%d size=%d data=%p flags=0x%x\n",
                (void*)_this, OffsetToLock, SizeToLock, *ppbData, Flags);
    return 0;
}

HRESULT CDirect3DVertexBuffer_Unlock(const CDirect3DVertexBuffer *_this)
{
    (void)_this;
    return 0;
}

HRESULT CDirect3DVertexBuffer_GetDesc(const CDirect3DVertexBuffer *_this, D3DVERTEXBUFFER_DESC *pDesc)
{
    CDirect3DVertexBufferClean *vb = (CDirect3DVertexBufferClean *)_this;
    pDesc->Format = 0;
    pDesc->Type = D3DRTYPE_VERTEXBUFFER;
    pDesc->Usage = vb->usage;
    pDesc->Pool = 0;
    pDesc->Size = vb->lengthBytes;
    pDesc->FVF = 0;
    return 0;
}

/* --- Destructors --- */

void ZN21CDirect3DVertexBufferD1Ev(void *_this)
{
    CDirect3DVertexBufferClean *vb = (CDirect3DVertexBufferClean *)_this;
    vb->vtable = vtbl_CDirect3DVertexBuffer;
    free(vb->data);
    vb->data = NULL;
}

void ZN21CDirect3DVertexBufferD0Ev(void *_this)
{
    ZN21CDirect3DVertexBufferD1Ev(_this);
    free(_this);
}

void ZN21CDirect3DVertexBufferD2Ev(void *_this)
{
    ZN21CDirect3DVertexBufferD1Ev(_this);
}

/* --- Constructor --- */

void CDirect3DVertexBuffer_CDirect3DVertexBuffer(const CDirect3DVertexBuffer *_this, UINT32 Length, DWORD Usage, D3DPOOL Pool)
{
    CDirect3DVertexBufferClean *vb = (CDirect3DVertexBufferClean *)_this;
    (void)Pool;
    vb->vtable = vtbl_CDirect3DVertexBuffer;
    vb->refCount = 1;
    vb->lengthBytes = Length;
    vb->data = (byte *)calloc(1, Length);
    vb->usage = Usage;
}

/* --- IDirect3DResource9 stubs --- */

HRESULT CDirect3DVertexBuffer_GetDevice(const CDirect3DVertexBuffer *_this, IDirect3DDevice9 **ppDevice)
{
    (void)_this;
    (void)ppDevice;
    return 0;
}

HRESULT CDirect3DVertexBuffer_SetPrivateData(const CDirect3DVertexBuffer *_this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    (void)_this; (void)refguid; (void)pData; (void)SizeOfData; (void)Flags;
    return 0;
}

HRESULT CDirect3DVertexBuffer_GetPrivateData(const CDirect3DVertexBuffer *_this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    (void)_this; (void)refguid; (void)pData; (void)pSizeOfData;
    return 0;
}

HRESULT CDirect3DVertexBuffer_FreePrivateData(const CDirect3DVertexBuffer *_this, const GUID *refguid)
{
    (void)_this; (void)refguid;
    return 0;
}

DWORD CDirect3DVertexBuffer_SetPriority(const CDirect3DVertexBuffer *_this, DWORD PriorityNew)
{
    (void)_this; (void)PriorityNew;
    return 0;
}

DWORD CDirect3DVertexBuffer_GetPriority(const CDirect3DVertexBuffer *_this)
{
    (void)_this;
    return 0;
}

void CDirect3DVertexBuffer_PreLoad(const CDirect3DVertexBuffer *_this)
{
    (void)_this;
}

D3DRESOURCETYPE CDirect3DVertexBuffer_GetType(const CDirect3DVertexBuffer *_this)
{
    (void)_this;
    return D3DRTYPE_VERTEXBUFFER;
}

/* --- Fence management (no-ops on Linux, no Apple VAR extensions) --- */

void CDirect3DVertexBuffer_WaitFence(const CDirect3DVertexBuffer *_this, const void *pStart, UINT32 SizeInBytes)
{
    (void)_this; (void)pStart; (void)SizeInBytes;
}

void CDirect3DVertexBuffer_SetFence(const CDirect3DVertexBuffer *_this, const void *pStart, UINT32 SizeInBytes, const CDirect3DVertexBuffer *_this_3)
{
    (void)_this; (void)pStart; (void)SizeInBytes; (void)_this_3;
}

/* --- CStaticCacheInfo stubs (not needed on Linux) --- */

void ZN16CStaticCacheInfoD0Ev(void *_this)
{
    free(_this);
}

void ZN16CStaticCacheInfoD1Ev(void *_this)
{
    (void)_this;
}

void ZN16CStaticCacheInfoD2Ev(void *_this)
{
    (void)_this;
}

void CStaticCacheInfo_Flush(const CStaticCacheInfo *_this, void (*pStart)(), void (*pEnd)())
{
    (void)_this; (void)pStart; (void)pEnd;
}

/* --- CCacheInfoBlock stubs --- */

void ZN15CCacheInfoBlockD1Ev(void *_this)
{
    (void)_this;
}

void ZN15CCacheInfoBlockD0Ev(void *_this)
{
    free(_this);
}

/* --- std:: template stubs (only used by fence code, which is now no-op) --- */

void *ZNSt4listIP6CFenceSaIS1_EE5eraseESt14_List_iteratorIS1_E(void *list, void *pos)
{
    (void)list;
    return pos;
}

void ZNSt6vectorI15CCacheInfoBlockSaIS0_EEC1Em(void *vec, unsigned long n)
{
    (void)vec; (void)n;
}

void ZNSt6vectorImSaImEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPmS1_EERKm(void *vec, void *pos, const unsigned long *val)
{
    (void)vec; (void)pos; (void)val;
}
