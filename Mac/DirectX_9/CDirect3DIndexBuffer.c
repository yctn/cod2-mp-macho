/* ASM dump from: CDirect3DIndexBuffer.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DIndexBuffer.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DIndexBuffer.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

typedef struct {
    int vptr;
    byte *allocation;
    byte *data;
    UINT32 length;
    int freedLater;
} CMemoryBufferImpl;

typedef struct {
    void **vtable;
    ULONG refCount;
    UINT32 lengthBytes;
    CMemoryBufferImpl memory;
    UINT32 indexSizeBytes;
    DWORD usage;
    byte *lockPtr;
    UINT32 lockSize;
    unsigned char isLocked;
} CDirect3DIndexBufferImpl;

extern void *vtbl_CDirect3DIndexBuffer[];
void __ZdlPv(void *ptr);
void CMemoryBuffer_CMemoryBuffer(const CMemoryBuffer * _this, UINT32 Length);
void CMemoryBuffer_Recreate(const CMemoryBuffer * _this);
void ZN13CMemoryBufferD1Ev(const CMemoryBuffer * _this); /* CMemoryBuffer_~CMemoryBuffer */
void CMemoryBuffer_FreeLater(const CMemoryBuffer * _this, UINT32 Frames);
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f);

ULONG CDirect3DIndexBuffer_AddRef(const CDirect3DIndexBuffer * _this);
void ZN20CDirect3DIndexBufferD1Ev(const CDirect3DIndexBuffer * _this); /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
void ZN20CDirect3DIndexBufferD0Ev(const CDirect3DIndexBuffer * _this); /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
HRESULT CDirect3DIndexBuffer_QueryInterface(const CDirect3DIndexBuffer * _this, const IID *iid, LPVOID *ppvObj);
ULONG CDirect3DIndexBuffer_Release(const CDirect3DIndexBuffer * _this);
HRESULT CDirect3DIndexBuffer_Unlock(const CDirect3DIndexBuffer * _this);
HRESULT CDirect3DIndexBuffer_Lock(const CDirect3DIndexBuffer * _this, UINT OffsetToLock, UINT SizeToLock, J_COLOR_SPACE * *ppbDat, DWORD Flags);
J_COLOR_SPACE CDirect3DIndexBuffer_CDirect3DIndexBuffer(const CDirect3DIndexBuffer * _this, UINT32 Length, D3DFORMAT Format, DWORD Usage, D3DPOOL Pool);
HRESULT CDirect3DIndexBuffer_GetDevice(const CDirect3DIndexBuffer * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DIndexBuffer_SetPrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid, const J_COLOR_SPACE *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DIndexBuffer_GetPrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid, J_COLOR_SPACE *pData, DWORD *pSizeOfData);
HRESULT CDirect3DIndexBuffer_FreePrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid);
DWORD CDirect3DIndexBuffer_SetPriority(const CDirect3DIndexBuffer * _this, DWORD PriorityNew);
DWORD CDirect3DIndexBuffer_GetPriority(const CDirect3DIndexBuffer * _this);
J_COLOR_SPACE CDirect3DIndexBuffer_PreLoad(const CDirect3DIndexBuffer * _this);
D3DRESOURCETYPE CDirect3DIndexBuffer_GetType(const CDirect3DIndexBuffer * _this);
HRESULT CDirect3DIndexBuffer_GetDesc(const CDirect3DIndexBuffer * _this, D3DINDEXBUFFER_DESC *pDesc);

ULONG CDirect3DIndexBuffer_AddRef(const CDirect3DIndexBuffer * _this)
{
    CDirect3DIndexBufferImpl *indexBuffer;

    indexBuffer = (CDirect3DIndexBufferImpl *)_this;
    ++indexBuffer->refCount;
    return indexBuffer->refCount;
}

void ZN20CDirect3DIndexBufferD1Ev(const CDirect3DIndexBuffer * _this) /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
{
    CDirect3DIndexBufferImpl *indexBuffer;

    indexBuffer = (CDirect3DIndexBufferImpl *)_this;
    indexBuffer->vtable = vtbl_CDirect3DIndexBuffer;
    ZN13CMemoryBufferD1Ev((const CMemoryBuffer *)((const byte *)_this + 0xc));
}

void ZN20CDirect3DIndexBufferD0Ev(const CDirect3DIndexBuffer * _this) /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
{
    ZN20CDirect3DIndexBufferD1Ev(_this);
    __ZdlPv((void *)_this);
}

HRESULT CDirect3DIndexBuffer_QueryInterface(const CDirect3DIndexBuffer * _this, const IID *iid, LPVOID *ppvObj)
{
    (void)iid;

    *ppvObj = (LPVOID)_this;
    CDirect3DIndexBuffer_AddRef(_this);
    return 0;
}

ULONG CDirect3DIndexBuffer_Release(const CDirect3DIndexBuffer * _this)
{
    CDirect3DIndexBufferImpl *indexBuffer;
    ULONG refCount;

    indexBuffer = (CDirect3DIndexBufferImpl *)_this;
    refCount = --indexBuffer->refCount;
    if (!refCount) {
        ZN20CDirect3DIndexBufferD0Ev(_this);
    }

    return refCount;
}

HRESULT CDirect3DIndexBuffer_Unlock(const CDirect3DIndexBuffer * _this)
{
    (void)_this;
    return 0;
}

HRESULT CDirect3DIndexBuffer_Lock(const CDirect3DIndexBuffer * _this, UINT OffsetToLock, UINT SizeToLock, J_COLOR_SPACE * *ppbDat, DWORD Flags)
{
    CDirect3DIndexBufferImpl *indexBuffer;

    indexBuffer = (CDirect3DIndexBufferImpl *)_this;
    indexBuffer->isLocked = 1;
    indexBuffer->lockSize = SizeToLock ? SizeToLock : indexBuffer->lengthBytes;

    if ((indexBuffer->usage & 0x200) && (Flags & 0x2000)) {
        CMemoryBuffer_FreeLater((const CMemoryBuffer *)&indexBuffer->memory, 2);
        CMemoryBuffer_Recreate((const CMemoryBuffer *)&indexBuffer->memory);
    }

    indexBuffer->lockPtr = indexBuffer->memory.data + OffsetToLock;
    *ppbDat = (J_COLOR_SPACE *)indexBuffer->lockPtr;
    return 0;
}

J_COLOR_SPACE CDirect3DIndexBuffer_CDirect3DIndexBuffer(const CDirect3DIndexBuffer * _this, UINT32 Length, D3DFORMAT Format, DWORD Usage, D3DPOOL Pool)
{
    CDirect3DIndexBufferImpl *indexBuffer;

    (void)Pool;

    indexBuffer = (CDirect3DIndexBufferImpl *)_this;
    indexBuffer->vtable = vtbl_CDirect3DIndexBuffer;
    indexBuffer->refCount = 0;
    indexBuffer->lengthBytes = (Length + 3) & ~3U;

    CMemoryBuffer_CMemoryBuffer((const CMemoryBuffer *)&indexBuffer->memory, indexBuffer->lengthBytes);

    indexBuffer->indexSizeBytes = MacOpenGLUtils_GetFormatSizeInBits(&Format) >> 3;
    indexBuffer->usage = Usage;
    indexBuffer->lockPtr = NULL;
    indexBuffer->lockSize = 0;
    indexBuffer->isLocked = 0;
    ++indexBuffer->refCount;
    return 0;
}

HRESULT CDirect3DIndexBuffer_GetDevice(const CDirect3DIndexBuffer * _this, IDirect3DDevice9 * *ppDevice)
{
    (void)_this;
    (void)ppDevice;
    return 0;
}

HRESULT CDirect3DIndexBuffer_SetPrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid, const J_COLOR_SPACE *pData, DWORD SizeOfData, DWORD Flags)
{
    (void)_this;
    (void)refguid;
    (void)pData;
    (void)SizeOfData;
    (void)Flags;
    return 0;
}

HRESULT CDirect3DIndexBuffer_GetPrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid, J_COLOR_SPACE *pData, DWORD *pSizeOfData)
{
    (void)_this;
    (void)refguid;
    (void)pData;
    (void)pSizeOfData;
    return 0;
}

HRESULT CDirect3DIndexBuffer_FreePrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid)
{
    (void)_this;
    (void)refguid;
    return 0;
}

DWORD CDirect3DIndexBuffer_SetPriority(const CDirect3DIndexBuffer * _this, DWORD PriorityNew)
{
    (void)_this;
    (void)PriorityNew;
    return 0;
}

DWORD CDirect3DIndexBuffer_GetPriority(const CDirect3DIndexBuffer * _this)
{
    (void)_this;
    return 0;
}

J_COLOR_SPACE CDirect3DIndexBuffer_PreLoad(const CDirect3DIndexBuffer * _this)
{
    (void)_this;
    return 0;
}

D3DRESOURCETYPE CDirect3DIndexBuffer_GetType(const CDirect3DIndexBuffer * _this)
{
    (void)_this;
    return D3DRTYPE_INDEXBUFFER;
}

HRESULT CDirect3DIndexBuffer_GetDesc(const CDirect3DIndexBuffer * _this, D3DINDEXBUFFER_DESC *pDesc)
{
    CDirect3DIndexBufferImpl *indexBuffer;

    indexBuffer = (CDirect3DIndexBufferImpl *)_this;
    pDesc->Format = indexBuffer->indexSizeBytes == 2 ? D3DFMT_INDEX16 : D3DFMT_INDEX32;
    pDesc->Type = D3DRTYPE_INDEXBUFFER;
    pDesc->Usage = indexBuffer->usage;
    pDesc->Pool = 0;
    pDesc->Size = indexBuffer->lengthBytes;
    return 0;
}
