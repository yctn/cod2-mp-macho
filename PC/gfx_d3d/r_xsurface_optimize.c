/* ASM dump from: r_xsurface_optimize.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_xsurface_optimize.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/gfx_d3d/r_local.h"
 */

/*
 * Absolute-address globals from the original Mach-O binary.
 * These are pointers-to-pointers used for D3D COM vtable dispatch.
 *
 * imp_r_rendererInUse - dx_config: pointer to D3D config struct (offset 8 == adapter type, 2 => DX7)
 * imp_dx - dx_device_wrapper: pointer to wrapper, offset 8 is the IDirect3DDevice9*
 * imp_ri - xmodel_vtable: XModel interface function table (GetLodCount @ 0x174, GetSurfaces @ 0x168)
 * imp_alwaysfails - gpu_fence_flag: GPU fence / pending-release flag
 */
#define DX_CONFIG        (*(void **)imp_r_rendererInUse)
#define DX_DEVICE_WRAP   (*(void **)imp_dx)
#define XMODEL_VTABLE    (*(char **)imp_ri)
#define GPU_FENCE_FLAG   (*(volatile int **)imp_alwaysfails)

/* Helper to read an int at byte offset from a void pointer */
#define DEREF_INT(ptr, off)       (*(int *)((char *)(ptr) + (off)))
#define DEREF_PTR(ptr, off)       (*(void **)((char *)(ptr) + (off)))

/* COM vtable call helpers: vtable is at *(void***)obj, function at byte offset */
typedef int  (__attribute__((cdecl)) *vtable_func_t)();
#define VTABLE(obj)               (*(vtable_func_t **)((void *)(obj)))
#define VTABLE_CALL(obj, off, ...) (VTABLE(obj)[(off)/sizeof(vtable_func_t *)](__VA_ARGS__))

/* Function pointer at byte offset in a flat table */
typedef int (__attribute__((cdecl)) *flat_func_t)();
#define FLAT_CALL(base, off, ...) ((*(flat_func_t *)((base) + (off)))(__VA_ARGS__))

extern void R_FinishStaticVertexBuffer(IDirect3DVertexBuffer9 *vb);
extern void *R_AllocStaticIndexBuffer(IDirect3DIndexBuffer9 **ib, int sizeInBytes);
extern void R_FinishStaticIndexBuffer(IDirect3DIndexBuffer9 *ib);
extern void R_FreeStaticIndexBuffer(IDirect3DIndexBuffer9 *ib);
extern int XSurfaceGetBoneOffset(const XSurface *surf);
extern unsigned long XSurfaceTransfer(const XVertexBuffer *surfVerts, void *verts, int vertCount);
extern unsigned long XSurfaceTransferDx7(const XVertexBuffer *surfVerts, void *verts, int vertCount);
extern void Com_Memcpy(void *dst, const void *src, int size);

void XSurfaceOptimizeRigid(XModel *model, XSurface *surface, XVertexBuffer *surfVerts);
void XModelOptimize(XModel *model);
void XModelUnoptimize(XModel *model);

/* line 12 */
void XSurfaceOptimizeRigid(XModel *model, XSurface *surface, XVertexBuffer *surfVerts)
{
    IDirect3DVertexBuffer9 **surfRigid;
    void *vertexBuffer;
    int vertCount;
    int vertexStride;
    void *dxConfig;
    void *deviceWrapper;
    void *device;
    void **deviceVtable;
    void **vbVtable;
    int hr;

    /* surfRigid is &surface->surfRigid.vb (offset 0x10) */
    surfRigid = &surface->surfRigid.vb;

    /* If the vertex buffer is already created, nothing to do */
    if (surface->surfRigid.vb != NULL)
        return;

    vertCount = (int)surface->vertCount;

    /* Check DX adapter type: if offset 8 of the config object == 2, it's DX7 mode */
    dxConfig = DX_CONFIG;
    if (DEREF_INT(dxConfig, 8) == 2)
        vertexStride = 0x24; /* sizeof(GfxVertexDx7) = 36 */
    else
        vertexStride = 0x40; /* sizeof(GfxVertex) = 64 */

    /* Get the D3D device: device wrapper -> offset 8 -> device pointer */
    deviceWrapper = DX_DEVICE_WRAP;
    device = DEREF_PTR(deviceWrapper, 8);
    deviceVtable = *(void ***)device;

    /* CreateVertexBuffer(device, sizeInBytes, usage=8, fvf=0, pool=0, &surfRigid, sharedHandle=0)
     * vtable offset 0x68 = CreateVertexBuffer */
    hr = ((int (__attribute__((cdecl)) *)(void *, int, int, int, int, void *, void *))deviceVtable[0x68 / 4])
         (device, vertCount * vertexStride, 8, 0, 0, surfRigid, 0);

    if (hr < 0) {
        /* CreateVertexBuffer failed */
        surface->surfRigid.vb = NULL;
        return;
    }

    /* Lock the vertex buffer: vb->Lock(0, 0, &vertexBuffer, 0)
     * vtable offset 0x2c = Lock */
    vbVtable = *(void ***)surface->surfRigid.vb;
    hr = ((int (__attribute__((cdecl)) *)(void *, int, int, void *, int))vbVtable[0x2c / 4])
         (surface->surfRigid.vb, 0, 0, &vertexBuffer, 0);

    if (hr < 0) {
        /* Lock failed - Release the vertex buffer */
        /* vtable offset 8 = Release */
        vbVtable = *(void ***)surface->surfRigid.vb;
        ((void (__attribute__((cdecl)) *)(void *))vbVtable[8 / 4])(surface->surfRigid.vb);
        surface->surfRigid.vb = NULL;
        return;
    }

    /* Transfer vertex data based on DX version */
    dxConfig = DX_CONFIG;
    if (DEREF_INT(dxConfig, 8) == 2) {
        /* DX7 path */
        XSurfaceTransferDx7(surfVerts, vertexBuffer, (int)surface->vertCount);
    } else {
        /* DX9 path */
        XSurfaceTransfer(surfVerts, vertexBuffer, (int)surface->vertCount);
    }

    /* Finish (unlock) the vertex buffer */
    R_FinishStaticVertexBuffer(surface->surfRigid.vb);
}

/* line 142 */
void XModelOptimize(XModel *model)
{
    char *vtable;
    int lodCount;
    int lodIndex;
    int surfCount;
    int surfIndex;
    XSurface **surfaces;
    XPartBits partBits;
    XSurface *surf;
    int indexDataSize;
    int indexBytes;
    void *indexBuffer;

    vtable = XMODEL_VTABLE;

    /* GetLodCount(model) at vtable offset 0x174 */
    lodCount = FLAT_CALL(vtable, 0x174, model);
    if (lodCount <= 0)
        return;

    for (lodIndex = 0; lodIndex < lodCount; lodIndex++) {
        /* GetSurfaces(model, &surfaces, lodIndex, &partBits) at vtable offset 0x168 */
        surfCount = FLAT_CALL(vtable, 0x168, model, &surfaces, lodIndex, &partBits);
        if (surfCount <= 0)
            continue;

        for (surfIndex = 0; surfIndex < surfCount; surfIndex++) {
            surf = surfaces[surfIndex];

            /* If index buffer already exists, just optimize rigid */
            if (surf->indexBuffer != NULL) {
                if (XSurfaceGetBoneOffset(surf) != -1) {
                    XSurfaceOptimizeRigid(model, surf, surf->verts);
                }
                continue;
            }

            /* Compute index data size: triCount * 3 indices * 2 bytes each = triCount * 6 */
            indexDataSize = (int)surf->triCount * 6;

            /* Align to 32-byte boundary */
            indexBytes = (indexDataSize + 0x1f) & ~0x1f;

            /* Allocate static index buffer */
            indexBuffer = R_AllocStaticIndexBuffer(&surf->indexBuffer, indexBytes);
            if (indexBuffer == NULL)
                continue;

            /* Copy index data */
            Com_Memcpy(indexBuffer, surf->triIndices, indexDataSize);

            /* Zero-fill padding */
            memset((char *)indexBuffer + indexDataSize, 0, indexBytes - indexDataSize);

            /* Finalize the index buffer */
            R_FinishStaticIndexBuffer(surf->indexBuffer);

            /* Now optimize rigid if applicable */
            if (XSurfaceGetBoneOffset(surf) != -1) {
                XSurfaceOptimizeRigid(model, surf, surf->verts);
            }
        }
    }
}

/* line 163 */
void XModelUnoptimize(XModel *model)
{
    char *vtable;
    volatile int *fenceFlag;
    int lodCount;
    int lodIndex;
    int surfCount;
    int surfIndex;
    XSurface **surfaces;
    XPartBits partBits;
    XSurface *surf;
    void **vbVtable;

    vtable = XMODEL_VTABLE;

    /* GetLodCount(model) at vtable offset 0x174 */
    lodCount = FLAT_CALL(vtable, 0x174, model);
    if (lodCount <= 0)
        return;

    fenceFlag = GPU_FENCE_FLAG;

    for (lodIndex = 0; lodIndex < lodCount; lodIndex++) {
        /* GetSurfaces(model, &surfaces, lodIndex, &partBits) at vtable offset 0x168 */
        surfCount = FLAT_CALL(vtable, 0x168, model, &surfaces, lodIndex, &partBits);
        if (surfCount <= 0)
            continue;

        for (surfIndex = 0; surfIndex < surfCount; surfIndex++) {
            surf = surfaces[surfIndex];

            /* Free the index buffer if present */
            if (surf->indexBuffer != NULL) {
                R_FreeStaticIndexBuffer(surf->indexBuffer);
                surf->indexBuffer = NULL;
            }

            /* Release the vertex buffer if present */
            if (surf->surfRigid.vb != NULL) {
                do {
                    /* Release via COM vtable offset 8 */
                    vbVtable = *(void ***)surf->surfRigid.vb;
                    ((void (__attribute__((cdecl)) *)(void *))vbVtable[8 / 4])(surf->surfRigid.vb);
                    surf->surfRigid.vb = NULL;
                } while (*fenceFlag != 0);
            }
        }
    }
}
