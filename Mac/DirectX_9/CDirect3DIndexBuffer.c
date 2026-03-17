/* Clean CDirect3DIndexBuffer implementation for Linux */
/* Replaces Mac implementation with simple malloc buffers */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DIndexBuffer.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern void *vtbl_CDirect3DIndexBuffer[];

/* Clean IB struct — no CMemoryBuffer */
typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 lengthBytes;
    byte *data;
    UINT32 indexSizeBytes;
    DWORD usage;
    byte *lockPtr;
    UINT32 lockSize;
    unsigned char isLocked;
} CDirect3DIndexBufferClean;

/* Forward declarations */
ULONG CDirect3DIndexBuffer_AddRef(const CDirect3DIndexBuffer *_this);
void ZN20CDirect3DIndexBufferD0Ev(const CDirect3DIndexBuffer *_this);
void ZN20CDirect3DIndexBufferD1Ev(const CDirect3DIndexBuffer *_this);

/* --- IUnknown --- */

ULONG CDirect3DIndexBuffer_AddRef(const CDirect3DIndexBuffer *_this)
{
    CDirect3DIndexBufferClean *ib = (CDirect3DIndexBufferClean *)_this;
    return ++ib->refCount;
}

HRESULT CDirect3DIndexBuffer_QueryInterface(const CDirect3DIndexBuffer *_this, const IID *iid, LPVOID *ppvObj)
{
    (void)iid;
    *ppvObj = (LPVOID)_this;
    CDirect3DIndexBuffer_AddRef(_this);
    return 0;
}

ULONG CDirect3DIndexBuffer_Release(const CDirect3DIndexBuffer *_this)
{
    CDirect3DIndexBufferClean *ib = (CDirect3DIndexBufferClean *)_this;
    ULONG rc = --ib->refCount;
    if (!rc) {
        ZN20CDirect3DIndexBufferD0Ev(_this);
    }
    return rc;
}

/* --- Destructors --- */

void ZN20CDirect3DIndexBufferD1Ev(const CDirect3DIndexBuffer *_this)
{
    CDirect3DIndexBufferClean *ib = (CDirect3DIndexBufferClean *)_this;
    ib->vtable = vtbl_CDirect3DIndexBuffer;
    free(ib->data);
    ib->data = NULL;
}

void ZN20CDirect3DIndexBufferD0Ev(const CDirect3DIndexBuffer *_this)
{
    ZN20CDirect3DIndexBufferD1Ev(_this);
    free((void *)_this);
}

/* --- IDirect3DIndexBuffer9 --- */

HRESULT CDirect3DIndexBuffer_Lock(const CDirect3DIndexBuffer *_this, UINT OffsetToLock, UINT SizeToLock, void **ppbData, DWORD Flags)
{
    CDirect3DIndexBufferClean *ib = (CDirect3DIndexBufferClean *)_this;
    (void)Flags;
    ib->isLocked = 1;
    ib->lockSize = SizeToLock ? SizeToLock : ib->lengthBytes;
    ib->lockPtr = ib->data + OffsetToLock;
    *ppbData = ib->lockPtr;
    return 0;
}

HRESULT CDirect3DIndexBuffer_Unlock(const CDirect3DIndexBuffer *_this)
{
    (void)_this;
    return 0;
}

HRESULT CDirect3DIndexBuffer_GetDesc(const CDirect3DIndexBuffer *_this, D3DINDEXBUFFER_DESC *pDesc)
{
    CDirect3DIndexBufferClean *ib = (CDirect3DIndexBufferClean *)_this;
    pDesc->Format = ib->indexSizeBytes == 2 ? D3DFMT_INDEX16 : D3DFMT_INDEX32;
    pDesc->Type = D3DRTYPE_INDEXBUFFER;
    pDesc->Usage = ib->usage;
    pDesc->Pool = 0;
    pDesc->Size = ib->lengthBytes;
    return 0;
}

/* --- Constructor --- */

void CDirect3DIndexBuffer_CDirect3DIndexBuffer(const CDirect3DIndexBuffer *_this, UINT32 Length, D3DFORMAT Format, DWORD Usage, D3DPOOL Pool)
{
    CDirect3DIndexBufferClean *ib = (CDirect3DIndexBufferClean *)_this;
    (void)Pool;
    ib->vtable = vtbl_CDirect3DIndexBuffer;
    ib->refCount = 1;
    ib->lengthBytes = (Length + 3) & ~3U;
    ib->data = (byte *)calloc(1, ib->lengthBytes);
    /* D3DFMT_INDEX16 = 0x65 (16 bits = 2 bytes), D3DFMT_INDEX32 = 0x66 (32 bits = 4 bytes) */
    ib->indexSizeBytes = (Format == D3DFMT_INDEX16) ? 2 : 4;
    ib->usage = Usage;
    ib->lockPtr = NULL;
    ib->lockSize = 0;
    ib->isLocked = 0;
}

/* --- IDirect3DResource9 stubs --- */

HRESULT CDirect3DIndexBuffer_GetDevice(const CDirect3DIndexBuffer *_this, IDirect3DDevice9 **ppDevice)
{
    (void)_this; (void)ppDevice;
    return 0;
}

HRESULT CDirect3DIndexBuffer_SetPrivateData(const CDirect3DIndexBuffer *_this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    (void)_this; (void)refguid; (void)pData; (void)SizeOfData; (void)Flags;
    return 0;
}

HRESULT CDirect3DIndexBuffer_GetPrivateData(const CDirect3DIndexBuffer *_this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    (void)_this; (void)refguid; (void)pData; (void)pSizeOfData;
    return 0;
}

HRESULT CDirect3DIndexBuffer_FreePrivateData(const CDirect3DIndexBuffer *_this, const GUID *refguid)
{
    (void)_this; (void)refguid;
    return 0;
}

DWORD CDirect3DIndexBuffer_SetPriority(const CDirect3DIndexBuffer *_this, DWORD PriorityNew)
{
    (void)_this; (void)PriorityNew;
    return 0;
}

DWORD CDirect3DIndexBuffer_GetPriority(const CDirect3DIndexBuffer *_this)
{
    (void)_this;
    return 0;
}

void CDirect3DIndexBuffer_PreLoad(const CDirect3DIndexBuffer *_this)
{
    (void)_this;
}

D3DRESOURCETYPE CDirect3DIndexBuffer_GetType(const CDirect3DIndexBuffer *_this)
{
    (void)_this;
    return D3DRTYPE_INDEXBUFFER;
}
