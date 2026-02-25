/* ASM dump from: CDirect3DVolumeTexture.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVolumeTexture.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DVolumeTexture.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/Win32 SDK/objbase.h"
 *   #include "Mac/Win32 SDK/DirectX SDK/d3d9.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 */

ULONG CDirect3DVolume_AddRef(const CDirect3DVolume * _this);
void ZN15CDirect3DVolumeD1Ev(void); /* CDirect3DVolume_~CDirect3DVolume */
void ZN15CDirect3DVolumeD0Ev(void); /* CDirect3DVolume_~CDirect3DVolume */
HRESULT CDirect3DVolume_QueryInterface(const CDirect3DVolume * _this, const IID *iid, void * *ppvObj);
ULONG CDirect3DVolume_Release(const CDirect3DVolume * _this);
HRESULT CDirect3DVolume_GetDesc(const CDirect3DVolume * _this, D3DVOLUME_DESC *pDesc);
HRESULT CDirect3DVolume_UnlockBox(const CDirect3DVolume * _this);
ULONG CDirect3DVolumeTexture_AddRef(const CDirect3DVolumeTexture * _this);
HRESULT CDirect3DVolumeTexture_QueryInterface(const CDirect3DVolumeTexture * _this, const IID *iid, void * *ppvObj);
ULONG CDirect3DVolumeTexture_Release(const CDirect3DVolumeTexture * _this);
HRESULT CDirect3DVolumeTexture_GetLevelDesc(const CDirect3DVolumeTexture * _this, UINT Level, D3DVOLUME_DESC *pDesc);
HRESULT CDirect3DVolume_LockBox(const CDirect3DVolume * _this, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags);
HRESULT CDirect3DVolumeTexture_AddDirtyBox(const CDirect3DVolumeTexture * _this, const D3DBOX *pDirtyBox);
void CDirect3DVolume_CreateOpenGLSurfaceObject(const CDirect3DVolume * _this);
HRESULT CDirect3DVolumeTexture_UnlockBox(const CDirect3DVolumeTexture * _this, UINT Level);
bool CDirect3DVolume_IsDirty(const CDirect3DVolume * _this);
void ZN22CDirect3DVolumeTextureD0Ev(void); /* CDirect3DVolumeTexture_~CDirect3DVolumeTexture */
HRESULT CDirect3DVolumeTexture_LockBox(const CDirect3DVolumeTexture * _this, UINT Level, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags);
HRESULT CDirect3DVolumeTexture_GetVolumeLevel(const CDirect3DVolumeTexture * _this, UINT Level, IDirect3DVolume9 * *ppVolumeSurface);
void CDirect3DVolume_UpdateOpenGLSurfaceObject(const CDirect3DVolume * _this, int bRecreateSurface);
void CDirect3DVolumeTexture_UpdateOpenGLSurfaces(const CDirect3DVolumeTexture * _this, int RecreateTextureData);
void CDirect3DVolumeTexture_CDirect3DVolumeTexture(const CDirect3DVolumeTexture * _this, UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 Levels, DWORD Usage, D3DFORMAT Format);
void ZN22CDirect3DVolumeTextureD2Ev(void); /* CDirect3DVolumeTexture_~CDirect3DVolumeTexture */
void ZN22CDirect3DVolumeTextureD1Ev(void); /* CDirect3DVolumeTexture_~CDirect3DVolumeTexture */
HRESULT CDirect3DVolume_GetDevice(const CDirect3DVolume * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DVolume_SetPrivateData(const CDirect3DVolume * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DVolume_GetPrivateData(const CDirect3DVolume * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData);
HRESULT CDirect3DVolume_FreePrivateData(const CDirect3DVolume * _this, const GUID *refguid);
HRESULT CDirect3DVolume_GetContainer(const CDirect3DVolume * _this, const IID *riid, void * *ppContainer);
HRESULT CDirect3DVolumeTexture_GetDevice(const CDirect3DVolumeTexture * _this, IDirect3DDevice9 * *ppDevice);
HRESULT CDirect3DVolumeTexture_SetPrivateData(const CDirect3DVolumeTexture * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DVolumeTexture_GetPrivateData(const CDirect3DVolumeTexture * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData);
HRESULT CDirect3DVolumeTexture_FreePrivateData(const CDirect3DVolumeTexture * _this, const GUID *refguid);
DWORD CDirect3DVolumeTexture_SetPriority(const CDirect3DVolumeTexture * _this, DWORD PriorityNew);
DWORD CDirect3DVolumeTexture_GetPriority(const CDirect3DVolumeTexture * _this);
void CDirect3DVolumeTexture_PreLoad(const CDirect3DVolumeTexture * _this);
D3DRESOURCETYPE CDirect3DVolumeTexture_GetType(const CDirect3DVolumeTexture * _this);
DWORD CDirect3DVolumeTexture_SetLOD(const CDirect3DVolumeTexture * _this, DWORD LODNew);
DWORD CDirect3DVolumeTexture_GetLOD(const CDirect3DVolumeTexture * _this);
DWORD CDirect3DVolumeTexture_GetLevelCount(const CDirect3DVolumeTexture * _this);
HRESULT CDirect3DVolumeTexture_SetAutoGenFilterType(const CDirect3DVolumeTexture * _this, D3DTEXTUREFILTERTYPE FilterType);
D3DTEXTUREFILTERTYPE CDirect3DVolumeTexture_GetAutoGenFilterType(const CDirect3DVolumeTexture * _this);
void CDirect3DVolumeTexture_GenerateMipSubLevels(const CDirect3DVolumeTexture * _this);
void ZNSt6vectorIP15CDirect3DVolumeSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<CDirect3DVolume*, std_allocator<CDirect3DVolume*> >__M_insert_aux */
void ZNSt6vectorIP15CDirect3DVolumeSaIS1_EE7reserveEm(void); /* std_vector<CDirect3DVolume*, std_allocator<CDirect3DVolume*> >_reserve */

/* line 73 */
__attribute__((naked))
ULONG CDirect3DVolume_AddRef(const CDirect3DVolume * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 73 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 75 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 76 */
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
void ZN15CDirect3DVolumeD1Ev(void) /* CDirect3DVolume_~CDirect3DVolume */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332368, (%eax)\n"
        "popl %ebp\n" /* line 54 */
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
void ZN15CDirect3DVolumeD0Ev(void) /* CDirect3DVolume_~CDirect3DVolume */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x332368, (%eax)\n"
        "movl %eax, 8(%ebp)\n" /* line 54 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 62 */
__attribute__((naked))
HRESULT CDirect3DVolume_QueryInterface(const CDirect3DVolume * _this, const IID *iid, void * *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 64 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 65 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 68 */
        "leave\n"
        "retl\n"
    );
}

/* line 81 */
__attribute__((naked))
ULONG CDirect3DVolume_Release(const CDirect3DVolume * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 81 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 83 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 85 */
        "jne .Lf117e5e_00117e7d\n"
        "movl (%edx), %eax\n" /* line 87 */
        "movl %edx, (%esp)\n"
        "calll *0x30(%eax)\n"
        ".Lf117e5e_00117e7d:\n"
        "movl %ebx, %eax\n" /* line 91 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 264 */
__attribute__((naked))
HRESULT CDirect3DVolume_GetDesc(const CDirect3DVolume * _this, D3DVOLUME_DESC *pDesc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 264 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* pDesc */
        "movl 0x18(%edx), %eax\n" /* line 266 */
        "movl %eax, (%ecx)\n"
        "movl 0xc(%edx), %eax\n" /* line 267 */
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x10(%edx), %eax\n" /* line 268 */
        "movl %eax, 0x14(%ecx)\n"
        "movl 0x14(%edx), %eax\n" /* line 269 */
        "movl %eax, 0x18(%ecx)\n"
        "xorl %eax, %eax\n" /* line 274 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 325 */
__attribute__((naked))
HRESULT CDirect3DVolume_UnlockBox(const CDirect3DVolume * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 325 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 330 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 451 */
__attribute__((naked))
ULONG CDirect3DVolumeTexture_AddRef(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 451 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x38(%edx), %eax\n" /* line 453 */
        "addl $1, %eax\n"
        "movl %eax, 0x38(%edx)\n"
        "popl %ebp\n" /* line 454 */
        "retl\n"
    );
}

/* line 440 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_QueryInterface(const CDirect3DVolumeTexture * _this, const IID *iid, void * *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 440 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 442 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 443 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 446 */
        "leave\n"
        "retl\n"
    );
}

/* line 459 */
__attribute__((naked))
ULONG CDirect3DVolumeTexture_Release(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 459 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x38(%edx), %ebx\n" /* line 461 */
        "subl $1, %ebx\n"
        "movl %ebx, 0x38(%edx)\n"
        "testl %ebx, %ebx\n" /* line 463 */
        "jne .Lf117ede_00117efd\n"
        "movl (%edx), %eax\n" /* line 465 */
        "movl %edx, (%esp)\n"
        "calll *0x5c(%eax)\n"
        ".Lf117ede_00117efd:\n"
        "movl %ebx, %eax\n" /* line 469 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 477 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_GetLevelDesc(const CDirect3DVolumeTexture * _this, UINT Level, D3DVOLUME_DESC *pDesc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 477 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        /* { scope 1 */
        "movl (%edx), %ecx\n" /* line 482 */
        "leal -0xc(%ebp), %eax\n" /* Volume */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Level */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x48(%ecx)\n"
        "testl %eax, %eax\n" /* line 484 */
        "js .Lf117f06_00117f51\n"
        "movl -0xc(%ebp), %eax\n" /* line 486 | Volume */
        "movl (%eax), %edx\n"
        "movl 0x10(%ebp), %ecx\n" /* pDesc */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x20(%edx)\n"
        "movl %eax, %ebx\n" /* hr */
        "movl -0xc(%ebp), %eax\n" /* line 487 | Volume */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 495 | hr */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf117f06_00117f51:\n"
        "movl $0x8876086c, %ebx\n" /* line 484 | hr */
        /* } scope */
        "movl %ebx, %eax\n" /* line 495 | hr */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 283 */
__attribute__((naked))
HRESULT CDirect3DVolume_LockBox(const CDirect3DVolume * _this, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 283 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0x1c(%edi), %eax\n" /* line 290 | this */
        "movl 0xc(%ebp), %edx\n" /* pLockedVolume */
        "movl %eax, 8(%edx)\n"
        "leal 0x18(%edi), %esi\n" /* line 292 | this */
        "movl %esi, (%esp)\n"
        "calll MacOpenGLUtils_IsCompressed\n"
        "testb %al, %al\n"
        "je .Lf117f5e_00117fcb\n"
        /* { scope 1 */
        "movl 0xc(%edi), %eax\n" /* line 302 | this, Width */
        "testl %eax, %eax\n" /* line 305 */
        "jne .Lf117f5e_00117fc6\n"
        "movl $4, %edx\n"
        ".Lf117f5e_00117f8e:\n"
        "xorl %eax, %eax\n" /* line 310 | BlockSize */
        "cmpl $0x31545844, 0x18(%edi)\n" /* this */
        "setne %al\n" /* BlockSize */
        "leal 8(, %eax, 8), %eax\n" /* BlockSize */
        "shrl $2, %edx\n" /* line 312 */
        "imull %edx, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* pLockedVolume */
        "movl %eax, (%edx)\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 315 | pLockedVolume */
        "movl (%edx), %eax\n"
        "imull 0x10(%edi), %eax\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movb $1, 0x20(%edi)\n" /* line 67 */
        "xorl %eax, %eax\n" /* line 320 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf117f5e_00117fc6:\n"
        "leal 3(%eax), %edx\n" /* line 305 */
        "jmp .Lf117f5e_00117f8e\n"
        /* } scope */
        ".Lf117f5e_00117fcb:\n"
        "movl 0xc(%edi), %ebx\n" /* line 294 | this */
        "movl %esi, (%esp)\n"
        "calll MacOpenGLUtils_GetFormatSizeInBits\n"
        "imull %eax, %ebx\n"
        "shrl $3, %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* pLockedVolume */
        "movl %ebx, (%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* line 315 | pLockedVolume */
        "movl (%edx), %eax\n"
        "imull 0x10(%edi), %eax\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movb $1, 0x20(%edi)\n" /* line 67 */
        "xorl %eax, %eax\n" /* line 320 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 575 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_AddDirtyBox(const CDirect3DVolumeTexture * _this, const D3DBOX *pDirtyBox)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 575 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x60(%eax), %edx\n" /* line 334 */
        "leal 0x64(%eax), %ecx\n" /* line 352 */
        "cmpl 0x64(%eax), %edx\n" /* line 579 */
        "je .Lf117ffc_0011801a\n"
        ".Lf117ffc_0011800d:\n"
        "movl (%edx), %eax\n" /* line 67 */
        "movb $1, 0x20(%eax)\n"
        "addl $4, %edx\n" /* line 623 */
        "cmpl (%ecx), %edx\n" /* line 579 */
        "jne .Lf117ffc_0011800d\n"
        ".Lf117ffc_0011801a:\n"
        "xorl %eax, %eax\n" /* line 585 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 96 */
__attribute__((naked))
void CDirect3DVolume_CreateOpenGLSurfaceObject(const CDirect3DVolume * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 96 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: OpenGLWidth */
        "cmpl $0x1902, 0x28(%ebx)\n" /* line 104 | this */
        "sete %al\n"
        "movl %eax, %esi\n" /* IsDepthTexture */
        "testb %al, %al\n" /* line 110 */
        "je .Lf11801e_00118177\n"
        ".Lf11801e_0011803e:\n"
        "movl 0x18(%ebx), %eax\n" /* line 120 | this */
        "cmpl $0x35545844, %eax\n"
        "je .Lf11801e_001180f3\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf11801e_001180f3\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf11801e_001180f3\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf11801e_001180f3\n"
        /* { scope 2 */
        "movl 0xc(%ebx), %edx\n" /* line 127 | this, i */
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf11801e_001181ac\n"
        "movl $1, -0x1c(%ebp)\n" /* OpenGLWidth */
        /* } scope */
        ".Lf11801e_00118080:\n"
        "movl 0x10(%ebx), %edx\n" /* line 128 | this, i */
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf11801e_001181d5\n"
        ".Lf11801e_0011808c:\n"
        "movl $1, %edi\n" /* OpenGLHeight */
        /* } scope */
        ".Lf11801e_00118091:\n"
        "movl 0x14(%ebx), %ecx\n" /* line 129 | this, i */
        /* { scope 3 */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf11801e_001181fa\n"
        ".Lf11801e_0011809d:\n"
        "movl $1, %edx\n"
        /* } scope */
        ".Lf11801e_001180a2:\n"
        "movl %esi, %eax\n" /* line 142 | IsDepthTexture */
        "testb %al, %al\n"
        "je .Lf11801e_0011821d\n"
        ".Lf11801e_001180ac:\n"
        "xorl %eax, %eax\n"
        ".Lf11801e_001180ae:\n"
        "movl %eax, 0x24(%esp)\n"
        "movl 0x30(%ebx), %eax\n" /* this */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x2c(%ebx), %eax\n" /* this */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %edi, 0x10(%esp)\n" /* OpenGLHeight */
        "movl -0x1c(%ebp), %eax\n" /* OpenGLWidth */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x28(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexImage3D\n"
        "jmp .Lf11801e_00118155\n"
        /* } scope */
        /* { scope 2 */
        ".Lf11801e_001180f3:\n"
        "leal 0x18(%ebx), %eax\n" /* line 122 | this, LevelSize */
        "movl %eax, 0xc(%esp)\n" /* LevelSize */
        "movl 0x14(%ebx), %eax\n" /* this, LevelSize */
        "movl %eax, 8(%esp)\n" /* LevelSize */
        "movl 0x10(%ebx), %eax\n" /* this, LevelSize */
        "movl %eax, 4(%esp)\n" /* LevelSize */
        "movl 0xc(%ebx), %eax\n" /* this, LevelSize */
        "movl %eax, (%esp)\n" /* LevelSize */
        "calll MacOpenGLUtils_GetLevelSizeInBytes\n"
        "movl 0x1c(%ebx), %edx\n" /* line 123 | this */
        "movl %edx, 0x20(%esp)\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* this */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, 0x10(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x28(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glCompressedTexImage3DARB\n"
        /* } scope */
        ".Lf11801e_00118155:\n"
        "movl %esi, %eax\n" /* line 147 | IsDepthTexture */
        "testb %al, %al\n"
        "jne .Lf11801e_0011816f\n"
        "movl $0, 4(%esp)\n" /* line 149 */
        "movl $0x85b2, (%esp)\n"
        "calll glPixelStorei\n"
        /* } scope */
        ".Lf11801e_0011816f:\n"
        "addl $0x4c, %esp\n" /* line 161 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: OpenGLWidth */
        ".Lf11801e_00118177:\n"
        "movl $1, 4(%esp)\n" /* line 112 */
        "movl $0x85b2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $0x85bf, 8(%esp)\n" /* line 113 */
        "movl $0x85bc, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexParameteri\n"
        "jmp .Lf11801e_0011803e\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf11801e_001181ac:\n"
        "movl $1, -0x1c(%ebp)\n" /* line 144 | OpenGLWidth */
        "movl $0x20, %eax\n"
        ".Lf11801e_001181b8:\n"
        "shll -0x1c(%ebp)\n" /* OpenGLWidth */
        "cmpl -0x1c(%ebp), %edx\n" /* OpenGLWidth */
        "jbe .Lf11801e_00118080\n"
        "subl $1, %eax\n"
        "jne .Lf11801e_001181b8\n"
        /* } scope */
        "movl 0x10(%ebx), %edx\n" /* line 128 | this, i */
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "jbe .Lf11801e_0011808c\n"
        ".Lf11801e_001181d5:\n"
        "movl $1, %edi\n" /* OpenGLHeight */
        "movl $0x20, %eax\n"
        ".Lf11801e_001181df:\n"
        "addl %edi, %edi\n" /* OpenGLHeight */
        "cmpl %edi, %edx\n" /* OpenGLHeight */
        "jbe .Lf11801e_00118091\n"
        "subl $1, %eax\n"
        "jne .Lf11801e_001181df\n"
        /* } scope */
        "movl 0x14(%ebx), %ecx\n" /* line 129 | this, i */
        /* { scope 3 */
        "cmpl $1, %ecx\n" /* line 144 */
        "jbe .Lf11801e_0011809d\n"
        ".Lf11801e_001181fa:\n"
        "movl $1, %edx\n"
        "movl $0x20, %eax\n"
        ".Lf11801e_00118204:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ecx\n"
        "jbe .Lf11801e_001180a2\n"
        "subl $1, %eax\n"
        "jne .Lf11801e_00118204\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 142 | IsDepthTexture */
        "testb %al, %al\n"
        "jne .Lf11801e_001180ac\n"
        ".Lf11801e_0011821d:\n"
        "movl 0x1c(%ebx), %eax\n" /* this */
        "jmp .Lf11801e_001180ae\n"
    );
}

/* line 554 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_UnlockBox(const CDirect3DVolumeTexture * _this, UINT Level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 554 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Level */
        "movl 0x60(%eax), %edx\n" /* line 343 */
        "movl 0x64(%eax), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 560 */
        "sarl $2, %eax\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf118228_00118247\n"
        "movl $0x8876086c, %eax\n" /* line 570 */
        "popl %ebp\n"
        "retl\n"
        ".Lf118228_00118247:\n"
        "movl (%edx, %ecx, 4), %eax\n" /* line 91 */
        "movl (%eax), %edx\n" /* line 566 */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x28(%edx), %ecx\n"
        "popl %ebp\n" /* line 570 */
        "jmpl *%ecx\n" /* line 566 */
    );
}

/* line 227 */
__attribute__((naked))
bool CDirect3DVolume_IsDirty(const CDirect3DVolume * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 227 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "cmpb $0, 0x20(%eax)\n" /* line 229 */
        "jne .Lf118256_00118272\n"
        "movl 0x24(%eax), %eax\n" /* line 235 */
        "testl %eax, %eax\n"
        "je .Lf118256_00118279\n"
        "movl 4(%eax), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf118256_00118279\n"
        ".Lf118256_00118272:\n"
        "movl $1, %eax\n"
        "popl %ebp\n" /* line 245 */
        "retl\n"
        ".Lf118256_00118279:\n"
        "xorl %eax, %eax\n" /* line 237 */
        "popl %ebp\n" /* line 245 */
        "retl\n"
    );
}

/* line 422 */
__attribute__((naked))
void ZN22CDirect3DVolumeTextureD0Ev(void) /* CDirect3DVolumeTexture_~CDirect3DVolumeTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 422 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $0x3323a8, (%edi)\n" /* this */
        "movl $0x332410, 4(%edi)\n" /* this */
        "leal 0x60(%edi), %eax\n" /* line 428 | this */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x60(%edi), %eax\n" /* line 334 */
        "leal 0x64(%edi), %esi\n" /* line 352 */
        "cmpl 0x64(%edi), %eax\n" /* line 428 | this */
        "je .Lf11827e_001182bf\n"
        "movl %eax, %ebx\n"
        "jmp .Lf11827e_001182ae\n"
        ".Lf11827e_001182ac:\n"
        "movl %ebx, %eax\n"
        ".Lf11827e_001182ae:\n"
        "movl (%eax), %eax\n" /* line 430 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 428 */
        "jne .Lf11827e_001182ac\n"
        ".Lf11827e_001182bf:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf11827e_001182d4\n"
        ".Lf11827e_001182cd:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf11827e_001182cd\n"
        /* } scope */
        ".Lf11827e_001182d4:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf11827e_001182e0\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf11827e_001182e0:\n"
        "leal 0x4c(%edi), %eax\n" /* line 432 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%edi), %eax\n" /* line 99 */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf11827e_0011830e\n"
        "movl %edi, 8(%ebp)\n" /* line 432 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf11827e_0011830e:\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        "movl %edi, 8(%ebp)\n" /* line 432 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl %eax, %ebx\n"
        ".Lf11827e_00118330:\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%edi), %eax\n" /* line 99 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf11827e_00118355\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf11827e_00118355:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf11827e_00118374\n"
        ".Lf11827e_0011836d:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf11827e_0011836d\n"
        /* } scope */
        ".Lf11827e_00118374:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf11827e_00118380\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf11827e_00118380:\n"
        "leal 0x4c(%edi), %eax\n" /* line 432 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf11827e_00118330\n"
    );
}

/* line 531 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_LockBox(const CDirect3DVolumeTexture * _this, UINT Level, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 531 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Level */
        "movl 0x10(%ebp), %edi\n" /* pLockedVolume */
        "movl 0x14(%ebp), %esi\n" /* pBox */
        "movl 0x18(%ebp), %ebx\n" /* Flags */
        "movl 0x60(%eax), %edx\n" /* line 343 */
        "movl 0x64(%eax), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 537 */
        "sarl $2, %eax\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf118390_001183be\n"
        "movl $0x8876086c, %eax\n" /* line 547 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf118390_001183be:\n"
        "movl (%edx, %ecx, 4), %eax\n" /* line 91 */
        "movl (%eax), %edx\n" /* line 543 */
        "movl %ebx, 0x14(%ebp)\n" /* Flags, pBox */
        "movl %esi, 0x10(%ebp)\n" /* pBox, pLockedVolume */
        "movl %edi, 0xc(%ebp)\n" /* pLockedVolume, Level */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x24(%edx), %ecx\n"
        "popl %ebx\n" /* line 547 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 543 */
    );
}

/* line 503 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_GetVolumeLevel(const CDirect3DVolumeTexture * _this, UINT Level, IDirect3DVolume9 * *ppVolumeSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 503 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Level */
        /* { scope 1 */
        "movl 0x60(%eax), %edx\n" /* line 343 */
        "movl 0x64(%eax), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 509 */
        "sarl $2, %eax\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf1183d8_001183fa\n"
        "movl $0x8876086c, %eax\n"
        /* } scope */
        "leave\n" /* line 521 */
        "retl\n"
        /* { scope 1 */
        ".Lf1183d8_001183fa:\n"
        "movl (%edx, %ecx, 4), %eax\n" /* line 515 */
        "movl 0x10(%ebp), %edx\n" /* ppVolumeSurface */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 516 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 521 */
        "retl\n"
    );
}

/* line 166 */
__attribute__((naked))
void CDirect3DVolume_UpdateOpenGLSurfaceObject(const CDirect3DVolume * _this, int bRecreateSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "cmpb $0, 0xc(%ebp)\n" /* line 173 | bRecreateSurface */
        "jne .Lf118410_0011852d\n"
        "movl 0x18(%ebx), %eax\n" /* line 186 | this */
        "cmpl $0x35545844, %eax\n"
        "je .Lf118410_001184a2\n"
        "cmpl $0x33545844, %eax\n"
        "je .Lf118410_001184a2\n"
        "cmpl $0x32545844, %eax\n"
        "je .Lf118410_001184a2\n"
        "cmpl $0x31545844, %eax\n"
        "je .Lf118410_001184a2\n"
        "movl 0x1c(%ebx), %eax\n" /* line 205 | this */
        "movl %eax, 0x28(%esp)\n"
        "movl 0x30(%ebx), %eax\n" /* this */
        "movl %eax, 0x24(%esp)\n"
        "movl 0x2c(%ebx), %eax\n" /* this */
        "movl %eax, 0x20(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* this */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, 0x18(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* this */
        "movl %eax, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glTexSubImage3D\n"
        ".Lf118410_0011849a:\n"
        "addl $0x4c, %esp\n" /* line 222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf118410_001184a2:\n"
        "leal 0x18(%ebx), %eax\n" /* line 188 | this */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetLevelSizeInBytes\n"
        "movl %eax, %edi\n" /* LevelSize */
        "movl 0xc(%ebx), %edx\n" /* line 190 | this */
        "cmpl $3, %edx\n"
        "jbe .Lf118410_0011849a\n"
        "movl 0x10(%ebx), %esi\n" /* this */
        "cmpl $3, %esi\n"
        "jbe .Lf118410_0011849a\n"
        "movl 0x14(%ebx), %ecx\n" /* this */
        "cmpl $3, %ecx\n"
        "jbe .Lf118410_0011849a\n"
        "movl 0x1c(%ebx), %eax\n" /* line 193 | this */
        "movl %eax, 0x28(%esp)\n"
        "movl %edi, 0x24(%esp)\n" /* LevelSize */
        "movl 0x28(%ebx), %eax\n" /* this */
        "movl %eax, 0x20(%esp)\n"
        "movl %ecx, 0x1c(%esp)\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl 8(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glCompressedTexSubImage3D\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf118410_0011852d:\n"
        "movb $1, -0x19(%ebp)\n" /* line 252 | CreateOpenGLResources */
        "movl 0x18(%ebx), %eax\n" /* line 253 | this */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x30(%ebx), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "leal 0x2c(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "leal 0x28(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* CreateOpenGLResources */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureType\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 255 | CreateOpenGLResources */
        "je .Lf118410_0011849a\n"
        "movl %ebx, (%esp)\n" /* line 257 | this */
        "calll CDirect3DVolume_CreateOpenGLSurfaceObject\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 222 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 590 */
__attribute__((naked))
void CDirect3DVolumeTexture_UpdateOpenGLSurfaces(const CDirect3DVolumeTexture * _this, int RecreateTextureData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 590 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movzbl 0xc(%ebp), %edx\n" /* RecreateTextureData */
        "movl 0x60(%eax), %ebx\n" /* line 334 */
        "leal 0x64(%eax), %esi\n" /* line 352 */
        "cmpl 0x64(%eax), %ebx\n" /* line 597 */
        "je .Lf118572_001185d2\n"
        "testb %dl, %dl\n" /* line 606 */
        "jne .Lf118572_001185d9\n"
        "movl %ebx, %eax\n"
        "jmp .Lf118572_001185b3\n"
        ".Lf118572_00118594:\n"
        "movl $0, 4(%esp)\n" /* line 602 */
        "movl %edx, (%esp)\n"
        "calll CDirect3DVolume_UpdateOpenGLSurfaceObject\n"
        "movl (%ebx), %eax\n" /* line 67 */
        "movb $0, 0x20(%eax)\n"
        ".Lf118572_001185aa:\n"
        "leal 4(%ebx), %eax\n" /* line 623 */
        "cmpl (%esi), %eax\n" /* line 597 */
        "je .Lf118572_001185d2\n"
        /* { scope 1 */
        ".Lf118572_001185b1:\n"
        "movl %eax, %ebx\n" /* line 229 */
        /* } scope */
        ".Lf118572_001185b3:\n"
        "movl (%eax), %edx\n" /* line 599 | this */
        /* { scope 1 */
        "cmpb $0, 0x20(%edx)\n" /* line 229 */
        "jne .Lf118572_00118594\n"
        "movl 0x24(%edx), %eax\n" /* line 235 */
        "testl %eax, %eax\n"
        "je .Lf118572_001185aa\n"
        "movl 4(%eax), %eax\n" /* line 237 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf118572_00118594\n"
        /* } scope */
        "leal 4(%ebx), %eax\n" /* line 623 */
        "cmpl (%esi), %eax\n" /* line 597 */
        "jne .Lf118572_001185b1\n"
        ".Lf118572_001185d2:\n"
        "addl $0x10, %esp\n" /* line 606 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf118572_001185d9:\n"
        "movl $1, 4(%esp)\n" /* line 602 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CDirect3DVolume_UpdateOpenGLSurfaceObject\n"
        "movl (%ebx), %eax\n" /* line 67 */
        "movb $0, 0x20(%eax)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl (%esi), %ebx\n" /* line 597 */
        "jne .Lf118572_001185d9\n"
        "jmp .Lf118572_001185d2\n"
    );
}

/* line 347 */
__attribute__((naked))
void CDirect3DVolumeTexture_CDirect3DVolumeTexture(const CDirect3DVolumeTexture * _this, UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 Levels, DWORD Usage, D3DFORMAT Format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 347 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0x14(%ebp), %edi\n" /* Depth */
        "movl 0x195ec38, %eax\n" /* line 77 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl 0x195ec48, %eax\n" /* line 852 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 0x195ec40, %eax\n" /* line 1020 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 0x195f250, %eax\n" /* line 1192 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "addl $4, %edx\n" /* line 355 */
        "movl %edx, -0x3c(%ebp)\n"
        "movl 0x195ec3c, %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n" /* this */
        /* { scope 1: Level */
        "movl $4, (%esp)\n" /* line 564 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* TexID */
        "movl %eax, 4(%esp)\n" /* line 565 */
        "movl $1, (%esp)\n"
        "calll glGenTextures\n"
        "movl 0x195ec0c, %esi\n" /* line 597 | pSurfaceMemory */
        "addl $0x66c, %esi\n" /* pSurfaceMemory */
        /* { scope 2: CreateOpenGLResources */
        "movl $0xc, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %ebx, 8(%eax)\n" /* line 104 | this */
        "movl %esi, 4(%esp)\n" /* line 1152 | pSurfaceMemory */
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        /* { scope 1: Level */
        "movl 8(%ebp), %edx\n" /* line 40 | this */
        "movl %ebx, 8(%edx)\n"
        "movl $0x2901, 4(%eax)\n"
        "movl $0x2901, 8(%eax)\n"
        "movl $0x2901, 0xc(%eax)\n"
        "movl $0, 0x10(%eax)\n"
        "movl $0x2702, 0x14(%eax)\n"
        "movl $0x2601, 0x18(%eax)\n"
        "movl $0x3e8, 0x1c(%eax)\n"
        "movl $0x3f800000, 0x20(%eax)\n"
        /* } scope */
        "movl 0xc(%ebp), %edx\n" /* line 91 | Width */
        "movl -0x3c(%ebp), %eax\n" /* this */
        "movl %edx, 0x28(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 0x2c(%eax)\n"
        "movl %edi, 0x30(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 355 | this */
        "movl $0x3323a8, (%eax)\n"
        "movl $0x332410, 4(%eax)\n"
        "movl $0, 0x38(%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, 0x3c(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 0x40(%eax)\n"
        "movl %edi, 0x44(%eax)\n" /* Depth */
        "movl $0, 0x48(%eax)\n"
        "addl $0x4c, %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CMemoryBuffer_CMemoryBuffer\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x60, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* this */
        /* { scope 1: Level */
        "movl 8(%ebp), %edx\n" /* line 85 | this */
        "movl $0, 0x60(%edx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        /* } scope */
        /* { scope 1: Level */
        "movl 0x18(%ebp), %eax\n" /* line 368 | Levels */
        "testl %eax, %eax\n"
        "jne .Lf1185fa_00118980\n"
        "movl %edi, 8(%esp)\n" /* line 370 | Depth */
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, (%esp)\n"
        "calll MacOpenGLUtils_GetNumTextureLevels\n"
        "movl %eax, 0x18(%ebp)\n" /* Levels */
        ".Lf1185fa_00118768:\n"
        "movl %eax, 4(%esp)\n" /* line 376 */
        "movl -0x34(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorIP15CDirect3DVolumeSaIS1_EE7reserveEm\n"
        "leal -0x24(%ebp), %eax\n" /* line 379 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl -0x3c(%ebp), %edx\n" /* line 380 */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glBindTexture\n"
        "leal 0x20(%ebp), %eax\n" /* line 387 | Format */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* Levels */
        "movl %edx, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* Depth */
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, (%esp)\n"
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "movl %eax, %ebx\n" /* TextureSizeInBytes */
        "movl %eax, 4(%esp)\n" /* line 388 */
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CMemoryBuffer_Resize\n"
        "movl -0x38(%ebp), %edx\n" /* line 391 */
        "movl 8(%edx), %eax\n"
        "movl %ebx, 8(%esp)\n" /* TextureSizeInBytes */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0x18(%ebp), %esi\n" /* line 394 | Levels */
        "testl %esi, %esi\n"
        "je .Lf1185fa_00118958\n"
        "movl $0, -0x30(%ebp)\n" /* Offset */
        "movl $0, -0x2c(%ebp)\n" /* Level */
        "jmp .Lf1185fa_00118870\n"
        /* { scope 2: CreateOpenGLResources */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1185fa_0011880c:\n"
        "addl $1, 4(%ebx)\n" /* line 75 | this */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %ebx, -0x20(%ebp)\n" /* line 408 | TextureSizeInBytes */
        "movl -0x34(%ebp), %eax\n" /* line 604 | this */
        "movl 4(%eax), %edx\n"
        "cmpl 8(%eax), %edx\n"
        "je .Lf1185fa_00118935\n"
        ".Lf1185fa_00118822:\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1185fa_00118950\n"
        "movl %ebx, (%edx)\n" /* this */
        "movl -0x34(%ebp), %eax\n" /* this */
        "movl 4(%eax), %edx\n"
        ".Lf1185fa_00118832:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl %edx, 4(%eax)\n"
        ".Lf1185fa_00118838:\n"
        "leal 0x20(%ebp), %eax\n" /* line 409 | Format */
        "movl %eax, 0xc(%esp)\n"
        "movl %edi, 8(%esp)\n" /* Depth */
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Width */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetLevelSizeInBytes\n"
        "addl %eax, -0x30(%ebp)\n" /* Offset */
        "addl $1, -0x2c(%ebp)\n" /* line 394 | Level */
        "shrl 0xc(%ebp)\n" /* Width */
        "shrl 0x10(%ebp)\n" /* Height */
        "shrl $1, %edi\n" /* Depth */
        "movl -0x2c(%ebp), %edx\n" /* Level */
        "cmpl %edx, 0x18(%ebp)\n" /* Levels */
        "je .Lf1185fa_00118958\n"
        ".Lf1185fa_00118870:\n"
        "movl $1, %eax\n" /* line 396 */
        "movl 0xc(%ebp), %ebx\n" /* Width, TextureSizeInBytes */
        "testl %ebx, %ebx\n" /* TextureSizeInBytes */
        "movl 0xc(%ebp), %edx\n" /* Width */
        "cmovel %eax, %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* Width */
        "movl 0x10(%ebp), %ecx\n" /* line 400 | Height */
        "testl %ecx, %ecx\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "cmovel %eax, %edx\n"
        "movl %edx, 0x10(%ebp)\n" /* Height */
        "testl %edi, %edi\n" /* line 404 | Depth */
        "cmovel %eax, %edi\n" /* Depth */
        "movl -0x30(%ebp), %esi\n" /* line 408 | Offset, pSurfaceMemory */
        "movl -0x38(%ebp), %eax\n" /* Format */
        "addl 8(%eax), %esi\n" /* pSurfaceMemory */
        "movl $0x34, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* Format, TextureSizeInBytes */
        "movl 0x20(%ebp), %eax\n" /* Format */
        /* { scope 2: CreateOpenGLResources */
        "movl $0x332368, (%ebx)\n" /* line 35 */
        "movl $0, 4(%ebx)\n"
        "movl -0x2c(%ebp), %edx\n" /* Level */
        "movl %edx, 8(%ebx)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, 0xc(%ebx)\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 0x10(%ebx)\n"
        "movl %edi, 0x14(%ebx)\n"
        "movl %eax, 0x18(%ebx)\n"
        "movl %esi, 0x1c(%ebx)\n"
        "movb $0, 0x20(%ebx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x24(%ebx)\n"
        /* { scope 3 */
        "movb $1, -0x19(%ebp)\n" /* line 37 | CreateOpenGLResources */
        "movl 0x18(%ebx), %eax\n" /* line 38 */
        "movl %eax, 0x10(%esp)\n"
        "leal 0x30(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "leal 0x2c(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x28(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* CreateOpenGLResources */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureType\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 40 | CreateOpenGLResources */
        "je .Lf1185fa_0011880c\n"
        "movl %ebx, (%esp)\n" /* line 42 */
        "calll CDirect3DVolume_CreateOpenGLSurfaceObject\n"
        /* { scope 4 */
        "addl $1, 4(%ebx)\n" /* line 75 | this */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %ebx, -0x20(%ebp)\n" /* line 408 | TextureSizeInBytes */
        "movl -0x34(%ebp), %eax\n" /* line 604 | this */
        "movl 4(%eax), %edx\n"
        "cmpl 8(%eax), %edx\n"
        "jne .Lf1185fa_00118822\n"
        ".Lf1185fa_00118935:\n"
        "leal -0x20(%ebp), %eax\n" /* line 610 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x34(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorIP15CDirect3DVolumeSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "jmp .Lf1185fa_00118838\n"
        ".Lf1185fa_00118950:\n"
        "movl -0x34(%ebp), %eax\n" /* this */
        "jmp .Lf1185fa_00118832\n"
        ".Lf1185fa_00118958:\n"
        "movl -0x24(%ebp), %eax\n" /* line 413 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x806f, (%esp)\n"
        "calll glBindTexture\n"
        "movl 0x18(%ebp), %edx\n" /* line 415 | Levels */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, 0x48(%eax)\n"
        "addl $1, 0x38(%eax)\n" /* line 453 */
        /* } scope */
        "addl $0x5c, %esp\n" /* line 418 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1185fa_00118980:\n"
        "movl 0x18(%ebp), %eax\n" /* Levels */
        "jmp .Lf1185fa_00118768\n"
        "movl %eax, %esi\n" /* pSurfaceMemory */
        ".Lf1185fa_0011898a:\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl -0x3c(%ebp), %edx\n" /* line 99 */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1185fa_001189b5\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1185fa_001189b5:\n"
        "movl %esi, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        /* { scope 1: Level */
        "movl %ebx, (%esp)\n" /* line 408 | TextureSizeInBytes */
        "calll __ZdlPv\n"
        /* } scope */
        ".Lf1185fa_001189c7:\n"
        "movl -0x34(%ebp), %eax\n" /* line 273 | this */
        "movl 4(%eax), %ecx\n" /* __last */
        "movl (%eax), %edx\n"
        "movl %edx, %eax\n"
        /* { scope 1: Level */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf1185fa_001189dc\n"
        ".Lf1185fa_001189d5:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf1185fa_001189d5\n"
        /* } scope */
        ".Lf1185fa_001189dc:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf1185fa_001189e8\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1185fa_001189e8:\n"
        "movl -0x38(%ebp), %edx\n" /* line 418 */
        "movl %edx, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf1185fa_0011898a\n"
        "movl %eax, %esi\n" /* pSurfaceMemory */
        "jmp .Lf1185fa_001189c7\n"
    );
}

/* overload skip: CDirect3DVolumeTexture_CDirect3DVolumeTexture (0x1189fa) */

/* line 422 */
__attribute__((naked))
void ZN22CDirect3DVolumeTextureD2Ev(void) /* CDirect3DVolumeTexture_~CDirect3DVolumeTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 422 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x3323a8, (%eax)\n"
        "movl $0x332410, 4(%eax)\n"
        "movl %eax, %edi\n" /* line 428 */
        "addl $0x60, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 334 | this */
        "movl 0x60(%edx), %eax\n"
        "movl %edx, %esi\n" /* line 352 */
        "addl $0x64, %esi\n"
        "cmpl 0x64(%edx), %eax\n" /* line 428 */
        "je .Lf118dfa_00118e3f\n"
        "movl %eax, %ebx\n"
        "jmp .Lf118dfa_00118e2e\n"
        ".Lf118dfa_00118e2c:\n"
        "movl %ebx, %eax\n"
        ".Lf118dfa_00118e2e:\n"
        "movl (%eax), %eax\n" /* line 430 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 428 */
        "jne .Lf118dfa_00118e2c\n"
        ".Lf118dfa_00118e3f:\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf118dfa_00118e51\n"
        ".Lf118dfa_00118e4a:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf118dfa_00118e4a\n"
        /* } scope */
        ".Lf118dfa_00118e51:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf118dfa_00118e5d\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf118dfa_00118e5d:\n"
        "movl 8(%ebp), %eax\n" /* line 432 | this */
        "addl $0x4c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf118dfa_00118e93\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf118dfa_00118e93:\n"
        "addl $0x1c, %esp\n" /* line 432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        ".Lf118dfa_00118e9d:\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf118dfa_00118ec5\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf118dfa_00118ec5:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf118dfa_00118ee1\n"
        ".Lf118dfa_00118eda:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf118dfa_00118eda\n"
        /* } scope */
        ".Lf118dfa_00118ee1:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf118dfa_00118eed\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf118dfa_00118eed:\n"
        "movl 8(%ebp), %eax\n" /* line 432 | this */
        "addl $0x4c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf118dfa_00118e9d\n"
    );
}

/* line 422 */
__attribute__((naked))
void ZN22CDirect3DVolumeTextureD1Ev(void) /* CDirect3DVolumeTexture_~CDirect3DVolumeTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 422 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $0x3323a8, (%eax)\n"
        "movl $0x332410, 4(%eax)\n"
        "movl %eax, %edi\n" /* line 428 */
        "addl $0x60, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 334 | this */
        "movl 0x60(%edx), %eax\n"
        "movl %edx, %esi\n" /* line 352 */
        "addl $0x64, %esi\n"
        "cmpl 0x64(%edx), %eax\n" /* line 428 */
        "je .Lf118efe_00118f43\n"
        "movl %eax, %ebx\n"
        "jmp .Lf118efe_00118f32\n"
        ".Lf118efe_00118f30:\n"
        "movl %ebx, %eax\n"
        ".Lf118efe_00118f32:\n"
        "movl (%eax), %eax\n" /* line 430 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 428 */
        "jne .Lf118efe_00118f30\n"
        ".Lf118efe_00118f43:\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf118efe_00118f55\n"
        ".Lf118efe_00118f4e:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf118efe_00118f4e\n"
        /* } scope */
        ".Lf118efe_00118f55:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf118efe_00118f61\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf118efe_00118f61:\n"
        "movl 8(%ebp), %eax\n" /* line 432 | this */
        "addl $0x4c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf118efe_00118f97\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf118efe_00118f97:\n"
        "addl $0x1c, %esp\n" /* line 432 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        ".Lf118efe_00118fa1:\n"
        "movl 0x195ec3c, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf118efe_00118fc9\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl 0x195ec0c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf118efe_00118fc9:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf118efe_00118fe5\n"
        ".Lf118efe_00118fde:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf118efe_00118fde\n"
        /* } scope */
        ".Lf118efe_00118fe5:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf118efe_00118ff1\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf118efe_00118ff1:\n"
        "movl 8(%ebp), %eax\n" /* line 432 | this */
        "addl $0x4c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf118efe_00118fa1\n"
    );
}

/* line 57 */
__attribute__((naked))
HRESULT CDirect3DVolume_GetDevice(const CDirect3DVolume * _this, IDirect3DDevice9 * *ppDevice)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 58 */
__attribute__((naked))
HRESULT CDirect3DVolume_SetPrivateData(const CDirect3DVolume * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 58 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 59 */
__attribute__((naked))
HRESULT CDirect3DVolume_GetPrivateData(const CDirect3DVolume * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 59 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
HRESULT CDirect3DVolume_FreePrivateData(const CDirect3DVolume * _this, const GUID *refguid)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 61 */
__attribute__((naked))
HRESULT CDirect3DVolume_GetContainer(const CDirect3DVolume * _this, const IID *riid, void * *ppContainer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 61 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 114 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_GetDevice(const CDirect3DVolumeTexture * _this, IDirect3DDevice9 * *ppDevice)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 114 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 115 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_SetPrivateData(const CDirect3DVolumeTexture * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 115 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 116 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_GetPrivateData(const CDirect3DVolumeTexture * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 116 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 117 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_FreePrivateData(const CDirect3DVolumeTexture * _this, const GUID *refguid)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 117 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 118 */
__attribute__((naked))
DWORD CDirect3DVolumeTexture_SetPriority(const CDirect3DVolumeTexture * _this, DWORD PriorityNew)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 118 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 119 */
__attribute__((naked))
DWORD CDirect3DVolumeTexture_GetPriority(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 120 */
__attribute__((naked))
void CDirect3DVolumeTexture_PreLoad(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 120 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 122 */
__attribute__((naked))
D3DRESOURCETYPE CDirect3DVolumeTexture_GetType(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "movl $4, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 123 */
__attribute__((naked))
DWORD CDirect3DVolumeTexture_SetLOD(const CDirect3DVolumeTexture * _this, DWORD LODNew)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 123 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 124 */
__attribute__((naked))
DWORD CDirect3DVolumeTexture_GetLOD(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 124 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 125 */
__attribute__((naked))
DWORD CDirect3DVolumeTexture_GetLevelCount(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 125 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x48(%eax), %eax\n" /* this */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 126 */
__attribute__((naked))
HRESULT CDirect3DVolumeTexture_SetAutoGenFilterType(const CDirect3DVolumeTexture * _this, D3DTEXTUREFILTERTYPE FilterType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 126 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 127 */
__attribute__((naked))
D3DTEXTUREFILTERTYPE CDirect3DVolumeTexture_GetAutoGenFilterType(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 127 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 128 */
__attribute__((naked))
void CDirect3DVolumeTexture_GenerateMipSubLevels(const CDirect3DVolumeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 128 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorIP15CDirect3DVolumeSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) /* std_vector<CDirect3DVolume*, std_allocator<CDirect3DVolume*> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 4(%edi), %edx\n" /* line 251 | this */
        "cmpl 8(%edi), %edx\n" /* this */
        "je .Lf2c1142_002c119a\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2c1142_002c1162\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %edx\n"
        ".Lf2c1142_002c1162:\n"
        "movl %edx, %eax\n" /* line 255 */
        "addl $4, %edx\n"
        "movl %edx, 4(%edi)\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 256 | __x */
        "movl (%edx), %ebx\n" /* __x_copy */
        "leal -4(%eax), %edx\n" /* line 257 */
        /* { scope 2 */
        "subl 0xc(%ebp), %edx\n" /* line 424 | __position */
        "andl $0xfffffffc, %edx\n" /* line 425 */
        "movl %edx, 8(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* __position */
        "movl %ecx, 4(%esp)\n"
        "subl %edx, %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        "movl 0xc(%ebp), %eax\n" /* line 260 | __position */
        "movl %ebx, (%eax)\n" /* __x_copy */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c1142_002c119a:\n"
        "movl %edx, %eax\n" /* line 759 */
        "subl (%edi), %eax\n" /* this */
        "sarl $2, %eax\n"
        "cmpl $0x3fffffff, %eax\n" /* line 265 */
        "je .Lf2c1142_002c1268\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2c1142_002c1246\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2c1142_002c11b9:\n"
        "shll $2, %edx\n" /* line 88 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl (%edi), %eax\n" /* line 279 | this */
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %ebx\n" /* line 300 | __position, __x_copy */
        "subl %eax, %ebx\n" /* __x_copy */
        "movl %ebx, 8(%esp)\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        "movl -0x20(%ebp), %edx\n" /* line 104 */
        "addl %ebx, %edx\n"
        "je .Lf2c1142_002c11f2\n"
        "movl 0x10(%ebp), %ecx\n" /* __x */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf2c1142_002c11f2:\n"
        "leal 4(%edx), %esi\n" /* line 286 */
        "movl 4(%edi), %ebx\n" /* line 603 | this, __x_copy */
        /* { scope 2 */
        /* { scope 3 */
        "subl 0xc(%ebp), %ebx\n" /* line 300 | __position, __x_copy */
        "movl %ebx, 8(%esp)\n" /* __x_copy */
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memmove\n"
        "addl %esi, %ebx\n" /* line 354 | __x_copy */
        /* } scope */
        /* } scope */
        "movl 4(%edi), %edx\n" /* line 352 | this */
        "movl (%edi), %ecx\n" /* line 334 | this */
        "movl %ecx, %eax\n"
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf2c1142_002c1222\n"
        ".Lf2c1142_002c121b:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %edx, %eax\n" /* line 173 */
        "jne .Lf2c1142_002c121b\n"
        ".Lf2c1142_002c1222:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2c1142_002c122e\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2c1142_002c122e:\n"
        "movl -0x20(%ebp), %edx\n" /* line 302 */
        "movl %edx, (%edi)\n" /* this */
        "movl %ebx, 4(%edi)\n" /* line 303 | __x_copy, this */
        "movl %edx, %eax\n" /* line 304 */
        "addl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n" /* this */
        /* } scope */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c1142_002c1246:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2c1142_002c125e\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "jbe .Lf2c1142_002c11b9\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2c1142_002c125e:\n"
        "movl $0x3fffffff, %edx\n" /* line 272 */
        "jmp .Lf2c1142_002c11b9\n"
        ".Lf2c1142_002c1268:\n"
        "movl $0x215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

/* line 69 */
__attribute__((naked))
void ZNSt6vectorIP15CDirect3DVolumeSaIS1_EE7reserveEm(void) /* std_vector<CDirect3DVolume*, std_allocator<CDirect3DVolume*> >_reserve */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 69 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* __n */
        "cmpl $0x3fffffff, %edx\n" /* line 71 */
        "ja .Lf2c1274_002c131b\n"
        "movl 8(%ebp), %eax\n" /* line 343 | this */
        "movl (%eax), %esi\n"
        "movl %eax, %ecx\n" /* line 73 */
        "movl 8(%eax), %eax\n"
        "subl %esi, %eax\n"
        "sarl $2, %eax\n"
        "cmpl %eax, %edx\n"
        "ja .Lf2c1274_002c12a7\n"
        "addl $0x2c, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2c1274_002c12a7:\n"
        "movl 4(%ecx), %ebx\n" /* line 361 */
        "subl %esi, %ebx\n" /* line 403 */
        "movl %ebx, %eax\n"
        "sarl $2, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "ja .Lf2c1274_002c1327\n"
        "shll $2, %edx\n" /* line 88 */
        "movl %edx, -0x1c(%ebp)\n"
        "movl %edx, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %edi\n" /* __tmp */
        /* { scope 2 */
        /* { scope 3 */
        "movl %ebx, 8(%esp)\n" /* line 300 */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 79 | this */
        "movl 4(%ecx), %edx\n" /* __last */
        "movl (%ecx), %ecx\n"
        /* { scope 2 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2c1274_002c12f1\n"
        "movl %ecx, %eax\n"
        ".Lf2c1274_002c12ea:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2c1274_002c12ea\n"
        /* } scope */
        ".Lf2c1274_002c12f1:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2c1274_002c12fd\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2c1274_002c12fd:\n"
        "movl 8(%ebp), %edx\n" /* line 84 | this */
        "movl %edi, (%edx)\n" /* __tmp */
        "movl -0x20(%ebp), %ecx\n" /* line 85 */
        "leal (%edi, %ecx, 4), %eax\n" /* __tmp */
        "movl %eax, 4(%edx)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 86 */
        "addl %edi, %eax\n" /* __tmp */
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2c1274_002c131b:\n"
        "movl $0x215c24, (%esp)\n" /* line 72 */
        "calll __ZSt20__throw_length_errorPKc\n"
        /* { scope 1 */
        ".Lf2c1274_002c1327:\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
    );
}

