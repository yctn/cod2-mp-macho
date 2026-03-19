/* Clean CDirect3DSurface implementation for Linux */
/* Replaces Mac implementation — adds explicit GL upload since we don't have Apple VAR */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DSurface.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern bool g_NoTextureID;
extern bool g_WarmOff;
extern void *vtbl_CDirect3DSurface[];

void __ZdlPv(void *ptr);
bool MacOpenGLUtils_IsCompressed(const D3DFORMAT *f);
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f);
int MacOpenGLUtils_GetOpenGLTextureType(bool *CreateOpenGLResources, GLenum *OpenGLInternalFormat, GLenum *OpenGLFormat, GLenum *OpenGLElementType, D3DFORMAT mFormat);
UINT32 MacOpenGLUtils_GetLevelSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, const D3DFORMAT *f);

typedef struct {
    void *QueryInterface;
    ULONG (*AddRef)(void *object);
    ULONG (*Release)(void *object);
} IUnknownLikeVTable;

typedef struct {
    void **vtable;
    ULONG refCount;
    SurfaceType surfaceType;
    GLenum cubemapTarget;
    UINT32 level;
    UINT32 width;
    UINT32 height;
    D3DFORMAT format;
    byte *surfaceMemory;
    unsigned char isDirty;
    unsigned char pad0[3];
    void *owner;
    unsigned char releaseOwnerOnDestroy;
    unsigned char pad1[3];
    GLenum openGLInternalFormat;
    GLenum openGLFormat;
    GLenum openGLElementType;
} CDirect3DSurfaceImpl;

/* Forward declarations */
ULONG CDirect3DSurface_AddRef(const CDirect3DSurface *_this);
void ZN16CDirect3DSurfaceD0Ev(const CDirect3DSurface *_this);
void ZN16CDirect3DSurfaceD1Ev(const CDirect3DSurface *_this);

static IUnknownLikeVTable *CDirect3DSurface_GetIUnknownVTable(void *object)
{
    return *(IUnknownLikeVTable **)object;
}

static void CDirect3DSurface_Destroy(CDirect3DSurfaceImpl *surface)
{
    surface->vtable = vtbl_CDirect3DSurface;
    if (surface->releaseOwnerOnDestroy && surface->owner) {
        CDirect3DSurface_GetIUnknownVTable(surface->owner)->Release(surface->owner);
    }
}

/* --- IUnknown --- */

ULONG CDirect3DSurface_AddRef(const CDirect3DSurface *_this)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    return ++surface->refCount;
}

void ZN16CDirect3DSurfaceD1Ev(const CDirect3DSurface *_this)
{
    CDirect3DSurface_Destroy((CDirect3DSurfaceImpl *)_this);
}

void ZN16CDirect3DSurfaceD0Ev(const CDirect3DSurface *_this)
{
    CDirect3DSurface_Destroy((CDirect3DSurfaceImpl *)_this);
    __ZdlPv((void *)_this);
}

HRESULT CDirect3DSurface_QueryInterface(const CDirect3DSurface *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    CDirect3DSurface_AddRef(_this);
    return 0;
}

ULONG CDirect3DSurface_Release(const CDirect3DSurface *_this)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    ULONG rc = --surface->refCount;
    if (!rc) {
        ZN16CDirect3DSurfaceD0Ev(_this);
    }
    return rc;
}

/* --- IDirect3DSurface9 --- */

HRESULT CDirect3DSurface_GetDesc(const CDirect3DSurface *_this, D3DSURFACE_DESC *pDesc)
{
    const CDirect3DSurfaceImpl *surface = (const CDirect3DSurfaceImpl *)_this;
    pDesc->Format = surface->format;
    pDesc->Width = surface->width;
    pDesc->Height = surface->height;
    return 0;
}

HRESULT CDirect3DSurface_LockRect(const CDirect3DSurface *_this, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    UINT32 formatBits;

    (void)Flags;

    /* If surfaceMemory is NULL or in library space (stale pointer from
       before a device reset), return a static scratch buffer so writes
       don't SIGSEGV.  The pixels won't display but the engine won't crash. */
    if (!surface->surfaceMemory || (unsigned int)surface->surfaceMemory >= 0xf0000000) {
        static byte scratch[4 * 1024 * 1024]; /* 4MB scratch for lightmaps */
        pLockedRect->pBits = scratch;
    } else {
        pLockedRect->pBits = surface->surfaceMemory;
    }

    if (MacOpenGLUtils_IsCompressed(&surface->format)) {
        UINT32 blocksWide = surface->width ? surface->width + 3 : 4;
        UINT32 blockSize = surface->format == D3DFMT_DXT1 ? 8 : 16;
        pLockedRect->Pitch = (INT)(blockSize * (blocksWide >> 2));
    } else {
        formatBits = MacOpenGLUtils_GetFormatSizeInBits(&surface->format);
        pLockedRect->Pitch = (INT)((surface->width * formatBits) >> 3);
    }

    if (pRect) {
        byte *address = (byte *)pLockedRect->pBits;
        formatBits = MacOpenGLUtils_GetFormatSizeInBits(&surface->format);
        UINT32 byteOffset = ((UINT32)pRect->left * formatBits) >> 3;
        byteOffset += (UINT32)pRect->top * (UINT32)pLockedRect->Pitch;
        pLockedRect->pBits = address + byteOffset;
    }

    surface->isDirty = 1;
    { static int slk = 0; if (slk++ < 10) fprintf(stderr, "[SURF_LOCK] w=%d h=%d pBits=%p pitch=%d mem=%p\n", surface->width, surface->height, pLockedRect->pBits, pLockedRect->Pitch, (void*)surface->surfaceMemory); }
    return 0;
}

HRESULT CDirect3DSurface_UnlockRect(const CDirect3DSurface *_this)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;

    /* Upload dirty surface data to GL using parent texture's GL ID.
     * owner field (set by CDirect3DTexture constructor) points to parent CDirect3DTextureClean.
     * CDirect3DTextureClean.texIDStorage is at offset 0x54. */
    if (surface->isDirty && surface->surfaceMemory && surface->owner) {
        unsigned int texID = *(unsigned int *)((byte *)surface->owner + 0x54);
        if (texID) {
            int prevTex = 0;
            glGetIntegerv(0x8069 /* GL_TEXTURE_BINDING_2D */, &prevTex);
            glBindTexture(0x0DE1 /* GL_TEXTURE_2D */, texID);
            CDirect3DSurface_UpdateOpenGLSurfaceObject(_this, 1); /* bRecreateSurface=1 for glTexImage2D */
            glBindTexture(0x0DE1, prevTex);
        }
    }

    return 0;
}

/* --- OpenGL texture operations (were naked ASM) --- */

void CDirect3DSurface_CreateOpenGLSurfaceObject(const CDirect3DSurface *_this)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    GLenum target;
    UINT32 w, h;

    if (!surface->surfaceMemory)
        return;

    /* Determine GL target */
    if (surface->surfaceType == 1) /* SURFACE_CUBE */
        target = surface->cubemapTarget;
    else
        target = 0x0DE1; /* GL_TEXTURE_2D */

    w = surface->width ? surface->width : 1;
    h = surface->height ? surface->height : 1;

    if (MacOpenGLUtils_IsCompressed(&surface->format)) {
        UINT32 dataSize = MacOpenGLUtils_GetLevelSizeInBytes(w, h, 1, &surface->format);
        glCompressedTexImage2DARB(target, surface->level,
            surface->openGLInternalFormat, w, h, 0, dataSize, surface->surfaceMemory);
    } else {
        glTexImage2D(target, surface->level,
            surface->openGLInternalFormat, w, h, 0,
            surface->openGLFormat, surface->openGLElementType, surface->surfaceMemory);
    }
}

void CDirect3DSurface_UpdateOpenGLSurfaceObject(const CDirect3DSurface *_this, int bRecreateSurface)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    GLenum target;
    UINT32 w, h;

    if (!surface->surfaceMemory)
        return;

    if (surface->surfaceType == 1)
        target = surface->cubemapTarget;
    else
        target = 0x0DE1; /* GL_TEXTURE_2D */

    w = surface->width ? surface->width : 1;
    h = surface->height ? surface->height : 1;

    if (bRecreateSurface) {
        CDirect3DSurface_CreateOpenGLSurfaceObject(_this);
    } else if (MacOpenGLUtils_IsCompressed(&surface->format)) {
        UINT32 dataSize = MacOpenGLUtils_GetLevelSizeInBytes(w, h, 1, &surface->format);
        glCompressedTexSubImage2D(target, surface->level, 0, 0,
            w, h, surface->openGLInternalFormat, dataSize, surface->surfaceMemory);
    } else {
        glTexSubImage2D(target, surface->level, 0, 0,
            w, h, surface->openGLFormat, surface->openGLElementType, surface->surfaceMemory);
    }

    surface->isDirty = 0;
}

bool CDirect3DSurface_IsDirty(const CDirect3DSurface *_this)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    return surface->isDirty;
}

void CDirect3DSurface_RecreateSurface(const CDirect3DSurface *_this)
{
    CDirect3DSurface_CreateOpenGLSurfaceObject(_this);
}

/* --- Constructor --- */

void CDirect3DSurface_CDirect3DSurface(const CDirect3DSurface *_this, SurfaceType s, GLenum CubemapID, UINT32 Level, UINT32 Width, UINT32 Height, D3DFORMAT Format, const void *pSurfaceMemory, COpenGLTexture *pOpenGLTextureInfo)
{
    CDirect3DSurfaceImpl *surface = (CDirect3DSurfaceImpl *)_this;
    bool createGL = 0;

    (void)pOpenGLTextureInfo;

    surface->vtable = vtbl_CDirect3DSurface;
    surface->refCount = 1;
    surface->surfaceType = s;
    surface->cubemapTarget = CubemapID;
    surface->level = Level;
    surface->width = Width;
    surface->height = Height;
    surface->format = Format;
    surface->surfaceMemory = (byte *)pSurfaceMemory;
    surface->isDirty = 0;
    surface->owner = NULL;
    surface->releaseOwnerOnDestroy = 0;
    surface->openGLInternalFormat = 0;
    surface->openGLFormat = 0;
    surface->openGLElementType = 0;

    /* Get GL format info */
    MacOpenGLUtils_GetOpenGLTextureType(&createGL,
        &surface->openGLInternalFormat,
        &surface->openGLFormat,
        &surface->openGLElementType,
        Format);

    /* Upload initial texture data to GL */
    if (!g_NoTextureID && createGL && pSurfaceMemory) {
        CDirect3DSurface_CreateOpenGLSurfaceObject(_this);
    }
}

/* --- Stubs --- */

void CDirect3DSurface_IgnorePixelStorei(GLenum pname, GLint param) { (void)pname; (void)param; }
void CDirect3DSurface_IgnoreTexParameteri(GLenum target, GLenum pname, GLint param) { (void)target; (void)pname; (void)param; }

HRESULT CDirect3DSurface_GetDevice(const CDirect3DSurface *_this, IDirect3DDevice9 **ppDevice) { (void)_this; (void)ppDevice; return 0; }
HRESULT CDirect3DSurface_SetPrivateData(const CDirect3DSurface *_this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags) { (void)_this; (void)refguid; (void)pData; (void)SizeOfData; (void)Flags; return 0; }
HRESULT CDirect3DSurface_GetPrivateData(const CDirect3DSurface *_this, const GUID *refguid, void *pData, DWORD *pSizeOfData) { (void)_this; (void)refguid; (void)pData; (void)pSizeOfData; return 0; }
HRESULT CDirect3DSurface_FreePrivateData(const CDirect3DSurface *_this, const GUID *refguid) { (void)_this; (void)refguid; return 0; }
DWORD CDirect3DSurface_SetPriority(const CDirect3DSurface *_this, DWORD PriorityNew) { (void)_this; (void)PriorityNew; return 0; }
DWORD CDirect3DSurface_GetPriority(const CDirect3DSurface *_this) { (void)_this; return 0; }
void CDirect3DSurface_PreLoad(const CDirect3DSurface *_this) { (void)_this; }
D3DRESOURCETYPE CDirect3DSurface_GetType(const CDirect3DSurface *_this) { (void)_this; return D3DRTYPE_SURFACE; }
HRESULT CDirect3DSurface_GetContainer(const CDirect3DSurface *_this, const IID *riid, void **ppContainer) { (void)_this; (void)riid; (void)ppContainer; return 0; }
HRESULT CDirect3DSurface_GetDC(const CDirect3DSurface *_this, HDC *phdc) { (void)_this; (void)phdc; return 0; }
HRESULT CDirect3DSurface_ReleaseDC(const CDirect3DSurface *_this, HDC hdc) { (void)_this; (void)hdc; return 0; }
