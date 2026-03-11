/* ASM dump from: CDirect3DSurface.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DSurface.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DSurface.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 */

extern bool g_NoTextureID; /* 0x0 */
extern bool g_WarmOff; /* 0x0 */

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

extern void *vtbl_CDirect3DSurface[];
void __ZdlPv(void *ptr);
bool MacOpenGLUtils_IsCompressed(const D3DFORMAT *f);
UINT32 MacOpenGLUtils_GetFormatSizeInBits(const D3DFORMAT *f);

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

void CDirect3DSurface_IgnorePixelStorei(GLenum pname, GLint param)
{
    (void)pname;
    (void)param;
}

void CDirect3DSurface_IgnoreTexParameteri(GLenum target, GLenum pname, GLint param)
{
    (void)target;
    (void)pname;
    (void)param;
}

ULONG CDirect3DSurface_AddRef(const CDirect3DSurface * _this);
void ZN16CDirect3DSurfaceD1Ev(const CDirect3DSurface * _this); /* CDirect3DSurface_~CDirect3DSurface */
void ZN16CDirect3DSurfaceD0Ev(const CDirect3DSurface * _this); /* CDirect3DSurface_~CDirect3DSurface */
HRESULT CDirect3DSurface_QueryInterface(const CDirect3DSurface * _this, const IID *iid, void * *ppvObj);
ULONG CDirect3DSurface_Release(const CDirect3DSurface * _this);
HRESULT CDirect3DSurface_GetDesc(const CDirect3DSurface * _this, D3DSURFACE_DESC *pDesc);
HRESULT CDirect3DSurface_LockRect(const CDirect3DSurface * _this, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags);
HRESULT CDirect3DSurface_UnlockRect(const CDirect3DSurface * _this);
void CDirect3DSurface_CreateOpenGLSurfaceObject(const CDirect3DSurface * _this);
void CDirect3DSurface_CDirect3DSurface(const CDirect3DSurface * _this, SurfaceType s, GLenum CubemapID, UINT32 Level, UINT32 Width, UINT32 Height, D3DFORMAT Format, const void * pSurfaceMemory, COpenGLTexture *pOpenGLTextureInfo);
bool CDirect3DSurface_IsDirty(const CDirect3DSurface * _this);
void CDirect3DSurface_RecreateSurface(const CDirect3DSurface * _this);
void CDirect3DSurface_UpdateOpenGLSurfaceObject(const CDirect3DSurface * _this, int bRecreateSurface);
HRESULT CDirect3DSurface_GetDevice(const CDirect3DSurface * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DSurface_SetPrivateData(const CDirect3DSurface * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DSurface_GetPrivateData(const CDirect3DSurface * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData);
HRESULT CDirect3DSurface_FreePrivateData(const CDirect3DSurface * _this, const GUID *refguid);
DWORD CDirect3DSurface_SetPriority(const CDirect3DSurface * _this, DWORD PriorityNew);
DWORD CDirect3DSurface_GetPriority(const CDirect3DSurface * _this);
void CDirect3DSurface_PreLoad(const CDirect3DSurface * _this);
D3DRESOURCETYPE CDirect3DSurface_GetType(const CDirect3DSurface * _this);
HRESULT CDirect3DSurface_GetContainer(const CDirect3DSurface * _this, const IID *riid, void * *ppContainer);
HRESULT CDirect3DSurface_GetDC(const CDirect3DSurface * _this, HDC *phdc);
HRESULT CDirect3DSurface_ReleaseDC(const CDirect3DSurface * _this, HDC hdc);

ULONG CDirect3DSurface_AddRef(const CDirect3DSurface * _this)
{
    CDirect3DSurfaceImpl *surface;

    surface = (CDirect3DSurfaceImpl *)_this;
    ++surface->refCount;
    return surface->refCount;
}

void ZN16CDirect3DSurfaceD1Ev(const CDirect3DSurface * _this) /* CDirect3DSurface_~CDirect3DSurface */
{
    CDirect3DSurface_Destroy((CDirect3DSurfaceImpl *)_this);
}

void ZN16CDirect3DSurfaceD0Ev(const CDirect3DSurface * _this) /* CDirect3DSurface_~CDirect3DSurface */
{
    CDirect3DSurface_Destroy((CDirect3DSurfaceImpl *)_this);
    __ZdlPv((void *)_this);
}

HRESULT CDirect3DSurface_QueryInterface(const CDirect3DSurface * _this, const IID *iid, void * *ppvObj)
{
    (void)iid;

    *ppvObj = (void *)_this;
    CDirect3DSurface_AddRef(_this);
    return 0;
}

ULONG CDirect3DSurface_Release(const CDirect3DSurface * _this)
{
    CDirect3DSurfaceImpl *surface;
    ULONG refCount;

    surface = (CDirect3DSurfaceImpl *)_this;
    refCount = --surface->refCount;
    if (!refCount) {
        ZN16CDirect3DSurfaceD0Ev(_this);
    }

    return refCount;
}

HRESULT CDirect3DSurface_GetDesc(const CDirect3DSurface * _this, D3DSURFACE_DESC *pDesc)
{
    const CDirect3DSurfaceImpl *surface;

    surface = (const CDirect3DSurfaceImpl *)_this;
    pDesc->Format = surface->format;
    pDesc->Width = surface->width;
    pDesc->Height = surface->height;
    return 0;
}

HRESULT CDirect3DSurface_LockRect(const CDirect3DSurface * _this, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags)
{
    CDirect3DSurfaceImpl *surface;
    UINT32 formatBits;

    (void)Flags;

    surface = (CDirect3DSurfaceImpl *)_this;
    pLockedRect->pBits = surface->surfaceMemory;

    if (MacOpenGLUtils_IsCompressed(&surface->format)) {
        UINT32 blocksWide;
        UINT32 blockSize;

        blocksWide = surface->width ? surface->width + 3 : 4;
        blockSize = surface->format == D3DFMT_DXT1 ? 8 : 16;
        pLockedRect->Pitch = (INT)(blockSize * (blocksWide >> 2));
    } else {
        formatBits = MacOpenGLUtils_GetFormatSizeInBits(&surface->format);
        pLockedRect->Pitch = (INT)((surface->width * formatBits) >> 3);
    }

    if (pRect) {
        byte *address;
        UINT32 byteOffset;

        address = (byte *)pLockedRect->pBits;
        formatBits = MacOpenGLUtils_GetFormatSizeInBits(&surface->format);
        byteOffset = ((UINT32)pRect->left * formatBits) >> 3;
        byteOffset += (UINT32)pRect->top * (UINT32)pLockedRect->Pitch;
        pLockedRect->pBits = address + byteOffset;
    }

    surface->isDirty = 1;
    return 0;
}

HRESULT CDirect3DSurface_UnlockRect(const CDirect3DSurface * _this)
{
    (void)_this;
    return 0;
}

/* line 77 */
__attribute__((naked))
void CDirect3DSurface_CreateOpenGLSurfaceObject(const CDirect3DSurface * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 77 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: OpenGLWidth */
        "movl 8(%ebx), %edx\n" /* line 83 | this */
        "testl %edx, %edx\n"
        "jne .Lf1d870_0001d9e8\n"
        "movl $0xde1, %esi\n" /* Target */
        "cmpl $0x1902, 0x30(%ebx)\n" /* line 98 | this */
        "sete -0x1d(%ebp)\n" /* IsDepthTexture */
        "cmpb $0, -0x1d(%ebp)\n" /* line 104 | IsDepthTexture */
        "je .Lf1d870_0001da09\n"
        ".Lf1d870_0001d8a1:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 114 | this */
        "cmpl $0x35545844, %eax\n"
        "je .Lf1d870_0001d959\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf1d870_0001d959\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf1d870_0001d959\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf1d870_0001d959\n"
        /* { scope 2 */
        "movl 0x14(%ebx), %edx\n" /* line 121 | this, i */
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf1d870_0001da42\n"
        "movl $1, -0x1c(%ebp)\n" /* OpenGLWidth */
        /* } scope */
        ".Lf1d870_0001d8e3:\n"
        "movl 0x18(%ebx), %ecx\n" /* line 122 | this, i */
        /* { scope 3 */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf1d870_0001da6b\n"
        ".Lf1d870_0001d8ef:\n"
        "movl $1, -0x2c(%ebp)\n"
        ".Lf1d870_0001d8f5:\n"
        /* } scope */
        "cmpb $0, -0x1d(%ebp)\n" /* line 134 | IsDepthTexture */
        "je .Lf1d870_0001da8d\n"
        ".Lf1d870_0001d900:\n"
        "movl $0, -0x24(%ebp)\n"
        ".Lf1d870_0001d907:\n"
        "movl 0x38(%ebx), %ecx\n" /* this */
        "movl 0x34(%ebx), %edx\n" /* this */
        "movl 0x30(%ebx), %esi\n" /* this, Target */
        "movl 0x10(%ebx), %edi\n" /* this */
        "cmpl $1, 8(%ebx)\n" /* this */
        "je .Lf1d870_0001da98\n"
        "movl $0xde1, %ebx\n" /* this */
        ".Lf1d870_0001d922:\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %ecx, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %ecx\n" /* OpenGLWidth */
        "movl %ecx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* Target */
        "movl %edi, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll glTexImage2D\n"
        "jmp .Lf1d870_0001d9c6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1d870_0001d959:\n"
        "leal 0x1c(%ebx), %eax\n" /* line 116 | this, LevelSize */
        "movl %eax, 0xc(%esp)\n" /* LevelSize */
        "movl $1, 8(%esp)\n"
        "movl 0x18(%ebx), %eax\n" /* this, LevelSize */
        "movl %eax, 4(%esp)\n" /* LevelSize */
        "movl 0x14(%ebx), %eax\n" /* this, LevelSize */
        "movl %eax, (%esp)\n" /* LevelSize */
        "calll MacOpenGLUtils_GetLevelSizeInBytes\n"
        "movl 0x20(%ebx), %edx\n" /* line 117 | this */
        "movl 0x18(%ebx), %ecx\n" /* this */
        "movl %ecx, -0x28(%ebp)\n"
        "movl 0x14(%ebx), %edi\n" /* this */
        "movl 0x30(%ebx), %ecx\n" /* this */
        "movl 0x10(%ebx), %esi\n" /* this, Target */
        "cmpl $1, 8(%ebx)\n" /* this */
        "je .Lf1d870_0001da3a\n"
        "movl $0xde1, %ebx\n" /* this */
        ".Lf1d870_0001d99b:\n"
        "movl %edx, 0x1c(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %edi, 0xc(%esp)\n"
        "movl %ecx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* Target */
        "movl %ebx, (%esp)\n" /* this */
        "calll glCompressedTexImage2DARB\n"
        /* } scope */
        ".Lf1d870_0001d9c6:\n"
        "cmpb $0, -0x1d(%ebp)\n" /* line 139 | IsDepthTexture */
        "jne .Lf1d870_0001d9e0\n"
        "movl $0, 4(%esp)\n" /* line 141 */
        "movl $0x85b2, (%esp)\n"
        "calll CDirect3DSurface_IgnorePixelStorei\n"
        /* } scope */
        ".Lf1d870_0001d9e0:\n"
        "addl $0x5c, %esp\n" /* line 153 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: OpenGLWidth */
        ".Lf1d870_0001d9e8:\n"
        "cmpl $1, 8(%ebx)\n" /* line 87 | this */
        "movl $0x8513, %eax\n"
        "cmovel %eax, %esi\n" /* Target */
        "cmpl $0x1902, 0x30(%ebx)\n" /* line 98 | this */
        "sete -0x1d(%ebp)\n" /* IsDepthTexture */
        "cmpb $0, -0x1d(%ebp)\n" /* line 104 | IsDepthTexture */
        "jne .Lf1d870_0001d8a1\n"
        ".Lf1d870_0001da09:\n"
        "movl $1, 4(%esp)\n" /* line 106 */
        "movl $0x85b2, (%esp)\n"
        "calll CDirect3DSurface_IgnorePixelStorei\n"
        "movl $0x85bf, 8(%esp)\n" /* line 107 */
        "movl $0x85bc, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* Target */
        "calll CDirect3DSurface_IgnoreTexParameteri\n"
        "jmp .Lf1d870_0001d8a1\n"
        /* { scope 2 */
        ".Lf1d870_0001da3a:\n"
        "movl 0xc(%ebx), %ebx\n" /* line 62 */
        "jmp .Lf1d870_0001d99b\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf1d870_0001da42:\n"
        "movl %edx, -0x1c(%ebp)\n" /* OpenGLWidth */
        "jmp .Lf1d870_0001d8e3\n"
        /* } scope */
        "movl 0x18(%ebx), %ecx\n" /* line 122 | this, i */
        /* { scope 3 */
        "cmpl $1, %ecx\n" /* line 144 */
        "jbe .Lf1d870_0001d8ef\n"
        ".Lf1d870_0001da6b:\n"
        "movl %ecx, -0x2c(%ebp)\n"
        "jmp .Lf1d870_0001d8f5\n"
        /* } scope */
        "cmpb $0, -0x1d(%ebp)\n" /* line 134 | IsDepthTexture */
        "jne .Lf1d870_0001d900\n"
        ".Lf1d870_0001da8d:\n"
        "movl 0x20(%ebx), %edx\n" /* this */
        "movl %edx, -0x24(%ebp)\n"
        "jmp .Lf1d870_0001d907\n"
        ".Lf1d870_0001da98:\n"
        "movl 0xc(%ebx), %ebx\n" /* line 62 */
        "jmp .Lf1d870_0001d922\n"
    );
}

/* line 240 */
__attribute__((naked))
void CDirect3DSurface_CDirect3DSurface(const CDirect3DSurface * _this, SurfaceType s, GLenum CubemapID, UINT32 Level, UINT32 Width, UINT32 Height, D3DFORMAT Format, const void * pSurfaceMemory, COpenGLTexture *pOpenGLTextureInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 240 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x18(%ebp), %ecx\n" /* Width */
        "movl 0x28(%ebp), %esi\n" /* pOpenGLTextureInfo */
        "movl $vtbl_CDirect3DSurface, (%ebx)\n" /* line 251 | this */
        "movl $0, 4(%ebx)\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* s */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* CubemapID */
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* Level */
        "movl %eax, 0x10(%ebx)\n" /* this */
        "movl %ecx, 0x14(%ebx)\n" /* this */
        "movl 0x1c(%ebp), %eax\n" /* Height */
        "movl %eax, 0x18(%ebx)\n" /* this */
        "movl 0x20(%ebp), %eax\n" /* Format */
        "movl %eax, 0x1c(%ebx)\n" /* this */
        "movl 0x24(%ebp), %eax\n" /* pSurfaceMemory */
        "movl %eax, 0x20(%ebx)\n" /* this */
        "movb $0, 0x24(%ebx)\n" /* this */
        "movl $0, 0x28(%ebx)\n" /* this */
        "testl %esi, %esi\n" /* pOpenGLTextureInfo */
        "sete 0x2c(%ebx)\n" /* this */
        /* { scope 1: Height, Width */
        "movzbl g_NoTextureID, %edx\n" /* line 254 */
        "movl %edx, %eax\n"
        "xorb $1, %al\n"
        "movb %al, -0x19(%ebp)\n" /* CreateOpenGLResources */
        "cmpb $0, 0x2c(%ebx)\n" /* line 256 | this */
        "je .Lf1daa0_0001db0f\n"
        "testb %dl, %dl\n"
        "je .Lf1daa0_0001db53\n"
        ".Lf1daa0_0001db0f:\n"
        "movl %esi, 0x28(%ebx)\n" /* line 265 | this */
        ".Lf1daa0_0001db12:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 268 | this */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x38(%ebx), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x34(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "leal 0x30(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* CreateOpenGLResources */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureType\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 270 | CreateOpenGLResources */
        "je .Lf1daa0_0001db47\n"
        "movl %ebx, (%esp)\n" /* line 272 | this */
        "calll CDirect3DSurface_CreateOpenGLSurfaceObject\n"
        ".Lf1daa0_0001db47:\n"
        "addl $1, 4(%ebx)\n" /* line 307 | this */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 276 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Height, Width */
        ".Lf1daa0_0001db53:\n"
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf1daa0_0001dc4d\n"
        "movl $1, -0x30(%ebp)\n" /* Width */
        ".Lf1daa0_0001db63:\n"
        "movl 0x18(%ebx), %edx\n" /* line 260 | this, i */
        /* { scope 2 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf1daa0_0001dc76\n"
        "movl $1, -0x34(%ebp)\n" /* Height */
        /* } scope */
        ".Lf1daa0_0001db76:\n"
        "movl $0x34, (%esp)\n" /* line 260 */
        "calll __Znwm\n"
        "movl %eax, %esi\n" /* this */
        /* { scope 2 */
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        "movl %eax, (%esi)\n" /* this */
        /* { scope 3 */
        "movl $4, (%esp)\n" /* line 564 */
        "calll __Znwm\n"
        "movl %eax, %edi\n" /* TexID */
        "movl %eax, 4(%esp)\n" /* line 565 */
        "movl $1, (%esp)\n"
        "calll glGenTextures\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 597 */
        "addl $0x66c, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        /* { scope 4 */
        "movl $0xc, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %edi, 8(%eax)\n" /* line 104 */
        "movl -0x2c(%ebp), %edx\n" /* line 1152 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        /* } scope */
        "leal 4(%esi), %eax\n" /* line 91 | this */
        /* { scope 3 */
        "movl %edi, 4(%esi)\n" /* line 40 */
        "movl $0x2901, 4(%eax)\n"
        "movl $0x2901, 8(%eax)\n"
        "movl $0x2901, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0x2702, 0x14(%eax)\n"
        "movl $0x2601, 0x18(%eax)\n"
        "movl $0x3e8, 0x1c(%eax)\n"
        "movl $0x3f800000, 0x20(%eax)\n"
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 91 | Width, this */
        "movl %eax, 0x28(%esi)\n" /* this */
        "movl -0x34(%ebp), %edx\n" /* Height */
        "movl %edx, 0x2c(%esi)\n"
        "movl $1, 0x30(%esi)\n"
        /* } scope */
        "movl %esi, 0x28(%ebx)\n" /* line 260 | this */
        "movl 4(%esi), %eax\n" /* line 261 | this */
        "movl (%eax), %eax\n"
        "movl 8(%ebx), %ecx\n" /* this */
        "testl %ecx, %ecx\n"
        "je .Lf1daa0_0001dc6f\n"
        "movl $0x8513, %edx\n"
        ".Lf1daa0_0001dc3c:\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll glBindTexture\n"
        "jmp .Lf1daa0_0001db12\n"
        ".Lf1daa0_0001dc4d:\n"
        "movl $1, -0x30(%ebp)\n" /* line 144 | Width */
        "movl $0x20, %eax\n"
        ".Lf1daa0_0001dc59:\n"
        "shll -0x30(%ebp)\n" /* Width */
        "cmpl -0x30(%ebp), %ecx\n" /* Width */
        "jbe .Lf1daa0_0001db63\n"
        "subl $1, %eax\n"
        "jne .Lf1daa0_0001dc59\n"
        "jmp .Lf1daa0_0001db63\n"
        ".Lf1daa0_0001dc6f:\n"
        "movl $0xde1, %edx\n" /* line 260 | i */
        "jmp .Lf1daa0_0001dc3c\n"
        /* { scope 2 */
        ".Lf1daa0_0001dc76:\n"
        "movl $1, -0x34(%ebp)\n" /* line 144 | Height */
        "movl $0x20, %eax\n"
        ".Lf1daa0_0001dc82:\n"
        "shll -0x34(%ebp)\n" /* Height */
        "cmpl -0x34(%ebp), %edx\n" /* Height */
        "jbe .Lf1daa0_0001db76\n"
        "subl $1, %eax\n"
        "jne .Lf1daa0_0001dc82\n"
        "jmp .Lf1daa0_0001db76\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 260 | this */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 25 */
__attribute__((naked))
bool CDirect3DSurface_IsDirty(const CDirect3DSurface * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "cmpb $0, 0x24(%eax)\n" /* line 27 */
        "jne .Lf1dcaa_0001dcc6\n"
        "movl 0x28(%eax), %eax\n" /* line 33 */
        "testl %eax, %eax\n"
        "je .Lf1dcaa_0001dccd\n"
        "movl 4(%eax), %eax\n" /* line 35 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf1dcaa_0001dccd\n"
        ".Lf1dcaa_0001dcc6:\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 43 */
        "retl\n"
        ".Lf1dcaa_0001dccd:\n"
        "xorl %eax, %eax\n" /* line 35 */
        "popl %ebp\n" /* line 43 */
        "retl\n"
    );
}

/* line 48 */
__attribute__((naked))
void CDirect3DSurface_RecreateSurface(const CDirect3DSurface * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        /* { scope 1: Height, Width */
        "cmpb $0, 0x2c(%edi)\n" /* line 52 | this */
        "je .Lf1dcd2_0001ddd2\n"
        "movl 0x28(%edi), %edx\n" /* line 56 | this */
        "testl %edx, %edx\n"
        "je .Lf1dcd2_0001dcf7\n"
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf1dcd2_0001dcf7:\n"
        "movl 0x14(%edi), %edx\n" /* line 57 | this, i */
        /* { scope 2 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf1dcd2_0001de13\n"
        "movl $1, -0x30(%ebp)\n" /* Width */
        /* } scope */
        ".Lf1dcd2_0001dd0a:\n"
        "movl 0x18(%edi), %edx\n" /* line 57 | this, i */
        /* { scope 2 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf1dcd2_0001de3c\n"
        ".Lf1dcd2_0001dd16:\n"
        "movl $1, -0x34(%ebp)\n" /* Height */
        /* } scope */
        ".Lf1dcd2_0001dd1d:\n"
        "movl $0x34, (%esp)\n" /* line 57 */
        "calll __Znwm\n"
        "movl %eax, %esi\n" /* this */
        /* { scope 2 */
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        "movl %eax, (%esi)\n" /* this */
        /* { scope 3 */
        "movl $4, (%esp)\n" /* line 564 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* TexID */
        "movl %eax, 4(%esp)\n" /* line 565 */
        "movl $1, (%esp)\n"
        "calll glGenTextures\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 597 */
        "addl $0x66c, %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        /* { scope 4 */
        "movl $0xc, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %ebx, 8(%eax)\n" /* line 104 */
        "movl -0x2c(%ebp), %edx\n" /* line 1152 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        /* } scope */
        "leal 4(%esi), %eax\n" /* line 91 | this */
        /* { scope 3 */
        "movl %ebx, 4(%esi)\n" /* line 40 */
        "movl $0x2901, 4(%eax)\n"
        "movl $0x2901, 8(%eax)\n"
        "movl $0x2901, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0x2702, 0x14(%eax)\n"
        "movl $0x2601, 0x18(%eax)\n"
        "movl $0x3e8, 0x1c(%eax)\n"
        "movl $0x3f800000, 0x20(%eax)\n"
        /* } scope */
        "movl -0x30(%ebp), %eax\n" /* line 91 | Width, this */
        "movl %eax, 0x28(%esi)\n" /* this */
        "movl -0x34(%ebp), %edx\n" /* Height */
        "movl %edx, 0x2c(%esi)\n" /* this */
        "movl $1, 0x30(%esi)\n" /* this */
        /* } scope */
        "movl %esi, 0x28(%edi)\n" /* line 57 | this */
        ".Lf1dcd2_0001ddd2:\n"
        "movb $1, -0x19(%ebp)\n" /* line 64 | CreateOpenGLResources */
        "movl 0x1c(%edi), %eax\n" /* line 65 | this */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x38(%edi), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x34(%edi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "leal 0x30(%edi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* CreateOpenGLResources */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureType\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 67 | CreateOpenGLResources */
        "je .Lf1dcd2_0001de0b\n"
        "movl %edi, (%esp)\n" /* line 69 | this */
        "calll CDirect3DSurface_CreateOpenGLSurfaceObject\n"
        /* } scope */
        ".Lf1dcd2_0001de0b:\n"
        "addl $0x4c, %esp\n" /* line 71 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: Height, Width */
        /* { scope 2 */
        ".Lf1dcd2_0001de13:\n"
        "movl $1, -0x30(%ebp)\n" /* line 144 | Width */
        "movl $0x20, %eax\n"
        ".Lf1dcd2_0001de1f:\n"
        "shll -0x30(%ebp)\n" /* Width */
        "cmpl -0x30(%ebp), %edx\n" /* Width */
        "jbe .Lf1dcd2_0001dd0a\n"
        "subl $1, %eax\n"
        "jne .Lf1dcd2_0001de1f\n"
        /* } scope */
        "movl 0x18(%edi), %edx\n" /* line 57 | this, i */
        /* { scope 2 */
        "cmpl $1, %edx\n" /* line 144 */
        "jbe .Lf1dcd2_0001dd16\n"
        ".Lf1dcd2_0001de3c:\n"
        "movl $1, -0x34(%ebp)\n" /* Height */
        "movl $0x20, %eax\n"
        ".Lf1dcd2_0001de48:\n"
        "shll -0x34(%ebp)\n" /* Height */
        "cmpl -0x34(%ebp), %edx\n" /* Height */
        "jbe .Lf1dcd2_0001dd1d\n"
        "subl $1, %eax\n"
        "jne .Lf1dcd2_0001de48\n"
        "jmp .Lf1dcd2_0001dd1d\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 57 | this */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 158 */
__attribute__((naked))
void CDirect3DSurface_UpdateOpenGLSurfaceObject(const CDirect3DSurface * _this, int bRecreateSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 158 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0xc(%ebp)\n" /* line 165 | bRecreateSurface */
        "jne .Lf1de70_0001df95\n"
        "movl 0x28(%ebx), %eax\n" /* this */
        "movl 4(%eax), %edx\n"
        "movl (%edx), %edx\n"
        "cmpl $1, 8(%ebx)\n" /* this */
        "movl $0xde1, %eax\n"
        "jne .Lf1de70_0001dec1\n"
        "movl $0x8513, %eax\n"
        ".Lf1de70_0001dec1:\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glBindTexture\n"
        "movl 0x1c(%ebx), %eax\n" /* line 191 | this */
        "cmpl $0x35545844, %eax\n"
        "je .Lf1de70_0001df0a\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf1de70_0001df0a\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf1de70_0001df0a\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf1de70_0001df0a\n"
        "movl 0x20(%ebx), %edx\n" /* line 210 | this */
        "movl 0x38(%ebx), %eax\n" /* this */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x34(%ebx), %edi\n" /* this, LevelSize */
        "movl 0x18(%ebx), %ecx\n" /* this */
        "movl 0x14(%ebx), %esi\n" /* this */
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, -0x1c(%ebp)\n"
        "cmpl $1, 8(%ebx)\n" /* this */
        "je .Lf1de70_0001dfa6\n"
        "movl $0xde1, %ebx\n" /* this */
        ".Lf1de70_0001decc:\n"
        "movl %edx, 0x20(%esp)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl %edi, 0x18(%esp)\n" /* LevelSize */
        "movl %ecx, 0x14(%esp)\n"
        "movl %esi, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll glTexSubImage2D\n"
        ".Lf1de70_0001df02:\n"
        "addl $0x5c, %esp\n" /* line 227 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1de70_0001df0a:\n"
        "leal 0x1c(%ebx), %eax\n" /* line 193 | this */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl 0x18(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetLevelSizeInBytes\n"
        "movl %eax, %edi\n" /* LevelSize */
        "movl 0x14(%ebx), %edx\n" /* line 195 | this */
        "cmpl $3, %edx\n"
        "jbe .Lf1de70_0001df02\n"
        "movl 0x18(%ebx), %ecx\n" /* this */
        "cmpl $3, %ecx\n"
        "jbe .Lf1de70_0001df02\n"
        "movl 0x20(%ebx), %eax\n" /* line 198 | this */
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x30(%ebx), %esi\n" /* this */
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $1, 8(%ebx)\n" /* this */
        "je .Lf1de70_0001dfa1\n"
        "movl $0xde1, %ebx\n" /* this */
        ".Lf1de70_0001df57:\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n" /* LevelSize */
        "movl %esi, 0x18(%esp)\n"
        "movl %ecx, 0x14(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll glCompressedTexSubImage2D\n"
        /* } scope */
        "addl $0x5c, %esp\n" /* line 227 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1de70_0001df95:\n"
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp CDirect3DSurface_RecreateSurface\n" /* line 168 */
        /* { scope 1 */
        ".Lf1de70_0001dfa1:\n"
        "movl 0xc(%ebx), %ebx\n" /* line 62 */
        "jmp .Lf1de70_0001df57\n"
        /* } scope */
        ".Lf1de70_0001dfa6:\n"
        "movl 0xc(%ebx), %ebx\n"
        "jmp .Lf1de70_0001decc\n"
    );
}

/* overload skip: CDirect3DSurface_CDirect3DSurface (0x1dfae) */

HRESULT CDirect3DSurface_GetDevice(const CDirect3DSurface * _this, IDirect3DDevice9 * *ppDevice)
{
    (void)_this;
    (void)ppDevice;
    return 0;
}

HRESULT CDirect3DSurface_SetPrivateData(const CDirect3DSurface * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    (void)_this;
    (void)refguid;
    (void)pData;
    (void)SizeOfData;
    (void)Flags;
    return 0;
}

HRESULT CDirect3DSurface_GetPrivateData(const CDirect3DSurface * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    (void)_this;
    (void)refguid;
    (void)pData;
    (void)pSizeOfData;
    return 0;
}

HRESULT CDirect3DSurface_FreePrivateData(const CDirect3DSurface * _this, const GUID *refguid)
{
    (void)_this;
    (void)refguid;
    return 0;
}

DWORD CDirect3DSurface_SetPriority(const CDirect3DSurface * _this, DWORD PriorityNew)
{
    (void)_this;
    (void)PriorityNew;
    return 0;
}

DWORD CDirect3DSurface_GetPriority(const CDirect3DSurface * _this)
{
    (void)_this;
    return 0;
}

void CDirect3DSurface_PreLoad(const CDirect3DSurface * _this)
{
    (void)_this;
}

D3DRESOURCETYPE CDirect3DSurface_GetType(const CDirect3DSurface * _this)
{
    (void)_this;
    return D3DRTYPE_SURFACE;
}

HRESULT CDirect3DSurface_GetContainer(const CDirect3DSurface * _this, const IID *riid, void * *ppContainer)
{
    (void)_this;
    (void)riid;
    (void)ppContainer;
    return 0;
}

HRESULT CDirect3DSurface_GetDC(const CDirect3DSurface * _this, HDC *phdc)
{
    (void)_this;
    (void)phdc;
    return 0;
}

HRESULT CDirect3DSurface_ReleaseDC(const CDirect3DSurface * _this, HDC hdc)
{
    (void)_this;
    (void)hdc;
    return 0;
}
