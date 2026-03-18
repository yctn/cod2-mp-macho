/* Clean CDirect3DCubeTexture implementation for Linux */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DCubeTexture.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern void *vtbl_CDirect3DCubeTexture[];
extern void *vtbl_CDirect3DCubeTexture_secondary[];

void __ZdlPv(void *ptr);
UINT32 MacOpenGLUtils_GetLevelSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, const D3DFORMAT *f);
UINT32 MacOpenGLUtils_GetNumTextureLevels(UINT32 Width, UINT32 Height, UINT32 Depth);
int MacOpenGLUtils_GetOpenGLTextureType(bool *CreateOpenGLResources, GLenum *OpenGLInternalFormat, GLenum *OpenGLFormat, GLenum *OpenGLElementType, D3DFORMAT mFormat);
void CDirect3DSurface_CDirect3DSurface(const CDirect3DSurface *_this, SurfaceType s, GLenum CubemapID, UINT32 Level, UINT32 Width, UINT32 Height, D3DFORMAT Format, const void *pSurfaceMemory, COpenGLTexture *pOpenGLTextureInfo);
void CDirect3DSurface_CreateOpenGLSurfaceObject(const CDirect3DSurface *_this);
ULONG CDirect3DSurface_AddRef(const CDirect3DSurface *_this);
void CDirect3DSurface_UpdateOpenGLSurfaceObject(const CDirect3DSurface *_this, int bRecreateSurface);
bool CDirect3DSurface_IsDirty(const CDirect3DSurface *_this);

#define GL_TEXTURE_CUBE_MAP           0x8513
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_MAG_FILTER         0x2800
#define GL_TEXTURE_MIN_FILTER         0x2801
#define GL_TEXTURE_WRAP_S             0x2802
#define GL_TEXTURE_WRAP_T             0x2803
#define GL_LINEAR                     0x2601
#define GL_REPEAT                     0x2901
#define GL_TEXTURE_BINDING_CUBE_MAP   0x8514
#define MAX_MIP_LEVELS 16

/* Same layout as CDirect3DTexture for COpenGLTexture compatibility */
typedef struct {
    void **primaryVtable;       /* +0x00 */
    void **secondaryVtable;     /* +0x04 */
    GLuint *mpTexID;            /* +0x08 */
    GLenum mTexWrapS;           /* +0x0C */
    GLenum mTexWrapT;           /* +0x10 */
    GLenum mTexWrapR;           /* +0x14 */
    GLuint mTexBorderColor;     /* +0x18 */
    GLenum mTexMinFilter;       /* +0x1C */
    GLenum mTexMagFilter;       /* +0x20 */
    GLfloat mTexAniso;          /* +0x24 */
    UINT32 reserved;            /* +0x28 */
    GLint glWidth;              /* +0x2C */
    GLint glHeight;             /* +0x30 */
    GLint glDepth;              /* +0x34 */
    ULONG refCount;             /* +0x38 */
    UINT32 edgeLength;          /* +0x3C */
    UINT32 pad_height;          /* +0x40 */
    UINT32 levelCount;          /* +0x44 */
    D3DFORMAT format;           /* +0x48 */
    void **surfaces;            /* +0x4C — 6*levels surfaces */
    byte *pixelData;            /* +0x50 */
    GLuint texIDStorage;        /* +0x54 */
} CDirect3DCubeTextureClean;

ULONG CDirect3DCubeTexture_AddRef(const CDirect3DCubeTexture *_this);
void ZN20CDirect3DCubeTextureD0Ev(void *_this);
void ZN20CDirect3DCubeTextureD1Ev(void *_this);

/* --- IUnknown --- */

ULONG CDirect3DCubeTexture_AddRef(const CDirect3DCubeTexture *_this)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    return ++tex->refCount;
}

HRESULT CDirect3DCubeTexture_QueryInterface(const CDirect3DCubeTexture *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    CDirect3DCubeTexture_AddRef(_this);
    return 0;
}

ULONG CDirect3DCubeTexture_Release(const CDirect3DCubeTexture *_this)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    ULONG rc = --tex->refCount;
    if (!rc) ZN20CDirect3DCubeTextureD0Ev((void *)_this);
    return rc;
}

/* --- IDirect3DCubeTexture9 --- */

HRESULT CDirect3DCubeTexture_GetLevelDesc(const CDirect3DCubeTexture *_this, UINT Level, D3DSURFACE_DESC *pDesc)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    HRESULT CDirect3DSurface_GetDesc(const CDirect3DSurface *_this, D3DSURFACE_DESC *pDesc);
    if (Level >= tex->levelCount) return -1;
    return CDirect3DSurface_GetDesc((CDirect3DSurface *)tex->surfaces[Level * 6], pDesc);
}

HRESULT CDirect3DCubeTexture_GetCubeMapSurface(const CDirect3DCubeTexture *_this, D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9 **ppCubeMapSurface)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    UINT32 idx;
    if (Level >= tex->levelCount || FaceType >= 6) return -1;
    idx = Level * 6 + FaceType;
    CDirect3DSurface_AddRef((CDirect3DSurface *)tex->surfaces[idx]);
    *ppCubeMapSurface = (IDirect3DSurface9 *)tex->surfaces[idx];
    return 0;
}

HRESULT CDirect3DCubeTexture_LockRect(const CDirect3DCubeTexture *_this, D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    HRESULT CDirect3DSurface_LockRect(const CDirect3DSurface *_this, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags);
    UINT32 idx;
    if (Level >= tex->levelCount || FaceType >= 6) return -1;
    idx = Level * 6 + FaceType;
    return CDirect3DSurface_LockRect((CDirect3DSurface *)tex->surfaces[idx], pLockedRect, pRect, Flags);
}

HRESULT CDirect3DCubeTexture_UnlockRect(const CDirect3DCubeTexture *_this, D3DCUBEMAP_FACES FaceType, UINT Level)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    UINT32 idx;
    CDirect3DSurface *surface;

    if (Level >= tex->levelCount || FaceType >= 6) return -1;
    idx = Level * 6 + FaceType;
    surface = (CDirect3DSurface *)tex->surfaces[idx];

    if (CDirect3DSurface_IsDirty(surface)) {
        int prevTex = 0;
        glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &prevTex);
        glBindTexture(GL_TEXTURE_CUBE_MAP, tex->texIDStorage);
        CDirect3DSurface_UpdateOpenGLSurfaceObject(surface, 0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, prevTex);
    }
    return 0;
}

HRESULT CDirect3DCubeTexture_AddDirtyRect(const CDirect3DCubeTexture *_this, D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect)
{
    (void)_this; (void)FaceType; (void)pDirtyRect;
    return 0;
}

DWORD CDirect3DCubeTexture_SetLOD(const CDirect3DCubeTexture *_this, DWORD LODNew) { (void)_this; (void)LODNew; return 0; }
DWORD CDirect3DCubeTexture_GetLOD(const CDirect3DCubeTexture *_this) { (void)_this; return 0; }
DWORD CDirect3DCubeTexture_GetLevelCount(const CDirect3DCubeTexture *_this) { return ((CDirect3DCubeTextureClean *)_this)->levelCount; }
D3DRESOURCETYPE CDirect3DCubeTexture_GetType(const CDirect3DCubeTexture *_this) { (void)_this; return D3DRTYPE_CUBETEXTURE; }
HRESULT CDirect3DCubeTexture_SetAutoGenFilterType(const CDirect3DCubeTexture *_this, D3DTEXTUREFILTERTYPE f) { (void)_this; (void)f; return 0; }
D3DTEXTUREFILTERTYPE CDirect3DCubeTexture_GetAutoGenFilterType(const CDirect3DCubeTexture *_this) { (void)_this; return 0; }
void CDirect3DCubeTexture_GenerateMipSubLevels(const CDirect3DCubeTexture *_this) { (void)_this; }

/* COpenGLTexture_UpdateOpenGLSurfaces — uploads dirty surfaces to GL.
 * Called via secondary vtable with this = texture + 4 (COpenGLTexture subobject).
 * Shared between CDirect3DTexture and CDirect3DCubeTexture. */
void COpenGLTexture_UpdateOpenGLSurfaces(const COpenGLTexture *_this)
{
    /* Adjust this pointer: called with texture+4, need texture+0 */
    byte *texBase = (byte *)_this - 4;
    extern void CDirect3DTexture_UpdateOpenGLSurfaces(const void *);
    CDirect3DTexture_UpdateOpenGLSurfaces(texBase);
}

/* --- Destructors --- */

void ZN20CDirect3DCubeTextureD1Ev(void *_this)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    UINT32 i, total;

    tex->primaryVtable = vtbl_CDirect3DCubeTexture;
    tex->secondaryVtable = vtbl_CDirect3DCubeTexture_secondary;

    total = tex->levelCount * 6;
    if (tex->surfaces) {
        for (i = 0; i < total; i++) {
            if (tex->surfaces[i]) __ZdlPv(tex->surfaces[i]);
        }
        free(tex->surfaces);
        tex->surfaces = NULL;
    }
    if (tex->texIDStorage) {
        glDeleteTextures(1, &tex->texIDStorage);
        tex->texIDStorage = 0;
    }
    free(tex->pixelData);
    tex->pixelData = NULL;
}

void ZN20CDirect3DCubeTextureD0Ev(void *_this)
{
    ZN20CDirect3DCubeTextureD1Ev(_this);
    free(_this);
}

void ZN20CDirect3DCubeTextureD2Ev(void *_this)
{
    ZN20CDirect3DCubeTextureD1Ev(_this);
}

/* --- Constructor --- */

void CDirect3DCubeTexture_CDirect3DCubeTexture(const CDirect3DCubeTexture *_this, UINT32 EdgeLength, UINT32 Levels, DWORD Usage, D3DFORMAT Format)
{
    CDirect3DCubeTextureClean *tex = (CDirect3DCubeTextureClean *)_this;
    UINT32 i, face, w, totalSize, offset;
    bool createGL = 0;
    int prevTex = 0;

    (void)Usage;
    memset(tex, 0, sizeof(*tex));

    tex->primaryVtable = vtbl_CDirect3DCubeTexture;
    tex->secondaryVtable = vtbl_CDirect3DCubeTexture_secondary;
    tex->mpTexID = &tex->texIDStorage;
    tex->mTexWrapS = GL_REPEAT;
    tex->mTexWrapT = GL_REPEAT;
    tex->mTexMinFilter = GL_LINEAR;
    tex->mTexMagFilter = GL_LINEAR;
    tex->mTexAniso = 1.0f;
    tex->glWidth = EdgeLength;
    tex->glHeight = EdgeLength;
    tex->glDepth = 1;
    tex->refCount = 1;
    tex->edgeLength = EdgeLength;
    tex->format = Format;

    if (Levels == 0)
        tex->levelCount = MacOpenGLUtils_GetNumTextureLevels(EdgeLength, EdgeLength, 1);
    else
        tex->levelCount = Levels;
    if (tex->levelCount > MAX_MIP_LEVELS) tex->levelCount = MAX_MIP_LEVELS;

    MacOpenGLUtils_GetOpenGLTextureType(&createGL, NULL, NULL, NULL, Format);

    glGenTextures(1, &tex->texIDStorage);
    glGetIntegerv(GL_TEXTURE_BINDING_CUBE_MAP, &prevTex);
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex->texIDStorage);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_REPEAT);

    /* Total size: 6 faces * sum of all mip levels */
    totalSize = 0;
    w = EdgeLength;
    for (i = 0; i < tex->levelCount; i++) {
        totalSize += MacOpenGLUtils_GetLevelSizeInBytes(w ? w : 1, w ? w : 1, 1, &Format) * 6;
        w >>= 1;
    }
    tex->pixelData = (byte *)calloc(1, totalSize ? totalSize : 1);

    tex->surfaces = (void **)calloc(tex->levelCount * 6, sizeof(void *));
    offset = 0;
    w = EdgeLength;
    for (i = 0; i < tex->levelCount; i++) {
        UINT32 levelW = w ? w : 1;
        UINT32 levelSize = MacOpenGLUtils_GetLevelSizeInBytes(levelW, levelW, 1, &Format);
        for (face = 0; face < 6; face++) {
            GLenum target = GL_TEXTURE_CUBE_MAP_POSITIVE_X + face;
            void *surf = calloc(1, 128);
            CDirect3DSurface_CDirect3DSurface((CDirect3DSurface *)surf, 1, target, i,
                levelW, levelW, Format, tex->pixelData + offset, NULL);
            tex->surfaces[i * 6 + face] = surf;
            if (createGL)
                CDirect3DSurface_CreateOpenGLSurfaceObject((CDirect3DSurface *)surf);
            offset += levelSize;
        }
        w >>= 1;
    }

    glBindTexture(GL_TEXTURE_CUBE_MAP, prevTex);
}

void CDirect3DCubeTexture_UpdateOpenGLSurfaces(const CDirect3DCubeTexture *_this) { (void)_this; }

/* --- Stubs --- */

HRESULT CDirect3DCubeTexture_GetDevice(const CDirect3DCubeTexture *_this, void (*ppDevice)()) { (void)_this; (void)ppDevice; return 0; }
HRESULT CDirect3DCubeTexture_SetPrivateData(const CDirect3DCubeTexture *_this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags) { (void)_this; (void)refguid; (void)pData; (void)SizeOfData; (void)Flags; return 0; }
HRESULT CDirect3DCubeTexture_GetPrivateData(const CDirect3DCubeTexture *_this, const GUID *refguid, void *pData, DWORD *pSizeOfData) { (void)_this; (void)refguid; (void)pData; (void)pSizeOfData; return 0; }
HRESULT CDirect3DCubeTexture_FreePrivateData(const CDirect3DCubeTexture *_this, const GUID *refguid) { (void)_this; (void)refguid; return 0; }
DWORD CDirect3DCubeTexture_SetPriority(const CDirect3DCubeTexture *_this, DWORD PriorityNew) { (void)_this; (void)PriorityNew; return 0; }
DWORD CDirect3DCubeTexture_GetPriority(const CDirect3DCubeTexture *_this) { (void)_this; return 0; }
void CDirect3DCubeTexture_PreLoad(const CDirect3DCubeTexture *_this) { (void)_this; }
