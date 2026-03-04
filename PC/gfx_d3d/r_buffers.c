/* Converted to C from ASM: r_buffers.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_buffers.cpp */

#include "common_types.h"
#include "imports.h"

/* g_dx was imp_dx, g_dxIter was imp_alwaysfails */

extern const char *va(const char *fmt, ...);
extern void R_FatalInitError(const char *msg);
extern const char *R_ErrorDescription(HRESULT hr);

void * R_AllocStaticVertexBuffer(IDirect3DVertexBuffer9 * *vb, int sizeInBytes);
void R_FinishStaticVertexBuffer(IDirect3DVertexBuffer9 *vb);
void R_FreeStaticVertexBuffer(IDirect3DVertexBuffer9 *vb);
void * R_AllocStaticIndexBuffer(IDirect3DIndexBuffer9 * *ib, int sizeInBytes);
void R_FinishStaticIndexBuffer(IDirect3DIndexBuffer9 *ib);
void R_FreeStaticIndexBuffer(IDirect3DIndexBuffer9 *ib);

/*
 * D3D9 COM vtable offsets used in this file:
 *   IDirect3DDevice9:
 *     0x68 / 4 = 26 = CreateVertexBuffer
 *     0x6c / 4 = 27 = CreateIndexBuffer
 *   IDirect3DVertexBuffer9 / IDirect3DIndexBuffer9:
 *     0x08 / 4 =  2 = Release
 *     0x2c / 4 = 11 = Lock
 *     0x30 / 4 = 12 = Unlock
 */

#define VTABLE(obj) (*(void ***)((void *)(obj)))

typedef HRESULT (*CreateVertexBufferFn)(void *device, UINT length, DWORD usage, DWORD fvf, int pool, IDirect3DVertexBuffer9 **ppVB, void *sharedHandle);
typedef HRESULT (*CreateIndexBufferFn)(void *device, UINT length, DWORD usage, DWORD fvf, int format, IDirect3DIndexBuffer9 **ppIB, void *sharedHandle);
typedef HRESULT (*BufferLockFn)(void *buffer, UINT offsetToLock, UINT sizeToLock, void **ppbData, DWORD flags);
typedef HRESULT (*BufferUnlockFn)(void *buffer);
typedef ULONG (*ReleaseFn)(void *obj);

/* line 101 */
void * R_AllocStaticVertexBuffer(IDirect3DVertexBuffer9 * *vb, int sizeInBytes)
{
    void *vertexBufferData;
    byte *dxPtr;
    void *device;
    void **vtable;
    HRESULT hr;

    dxPtr = (byte *)imp_dx;
    device = *(void **)(dxPtr + 8);
    vtable = VTABLE(device);

    /* IDirect3DDevice9::CreateVertexBuffer(sizeInBytes, D3DUSAGE_WRITEONLY(8), 0, 0, vb, NULL) */
    hr = ((CreateVertexBufferFn)vtable[0x68 / 4])(device, sizeInBytes, 8, 0, 0, vb, NULL);
    if (hr < 0) {
        R_FatalInitError(va("DirectX didn't create a %i-byte vertex buffer: %s\n", sizeInBytes, R_ErrorDescription(hr)));
    }

    /* IDirect3DVertexBuffer9::Lock(0, 0, &vertexBufferData, 0) */
    hr = ((BufferLockFn)VTABLE(*vb)[0x2c / 4])((void *)*vb, 0, 0, &vertexBufferData, 0);
    if (hr < 0) {
        R_FatalInitError(va("DirectX didn't lock a vertex buffer: %s\n", R_ErrorDescription(hr)));
    }

    return vertexBufferData;
}

/* line 122 */
void R_FinishStaticVertexBuffer(IDirect3DVertexBuffer9 *vb)
{
    /* IDirect3DVertexBuffer9::Unlock, retrying while device is lost */
    do {
        ((BufferUnlockFn)VTABLE(vb)[0x30 / 4])((void *)vb);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

/* line 128 */
void R_FreeStaticVertexBuffer(IDirect3DVertexBuffer9 *vb)
{
    /* IDirect3DVertexBuffer9::Release, retrying while device is lost */
    do {
        ((ReleaseFn)VTABLE(vb)[0x08 / 4])((void *)vb);
        vb = NULL;
    } while (*(volatile int *)imp_alwaysfails != 0);
}

/* line 134 */
void * R_AllocStaticIndexBuffer(IDirect3DIndexBuffer9 * *ib, int sizeInBytes)
{
    void *indexBufferData;
    byte *dxPtr;
    void *device;
    void **devVtable;
    HRESULT hr;

    dxPtr = (byte *)imp_dx;
    device = *(void **)(dxPtr + 8);
    devVtable = VTABLE(device);

    /* IDirect3DDevice9::CreateIndexBuffer(sizeInBytes, D3DUSAGE_WRITEONLY(8), D3DFMT_INDEX16(0x65), 0, ib, NULL) */
    hr = ((CreateIndexBufferFn)devVtable[0x6c / 4])(device, sizeInBytes, 8, 0x65, 0, ib, NULL);
    if (hr < 0) {
        return NULL;
    }

    /* IDirect3DIndexBuffer9::Lock(0, 0, &indexBufferData, 0) */
    hr = ((BufferLockFn)VTABLE(*ib)[0x2c / 4])((void *)*ib, 0, 0, &indexBufferData, 0);
    if (hr < 0) {
        /* Release the buffer and return NULL */
        ((ReleaseFn)VTABLE(*ib)[0x08 / 4])((void *)*ib);
        return NULL;
    }

    return indexBufferData;
}

/* line 158 */
void R_FinishStaticIndexBuffer(IDirect3DIndexBuffer9 *ib)
{
    /* IDirect3DIndexBuffer9::Unlock, retrying while device is lost */
    do {
        ((BufferUnlockFn)VTABLE(ib)[0x30 / 4])((void *)ib);
    } while (*(volatile int *)imp_alwaysfails != 0);
}

/* line 164 */
void R_FreeStaticIndexBuffer(IDirect3DIndexBuffer9 *ib)
{
    /* IDirect3DIndexBuffer9::Release, retrying while device is lost */
    do {
        ((ReleaseFn)VTABLE(ib)[0x08 / 4])((void *)ib);
        ib = NULL;
    } while (*(volatile int *)imp_alwaysfails != 0);
}
