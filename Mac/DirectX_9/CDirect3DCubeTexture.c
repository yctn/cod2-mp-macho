/* ASM dump from: CDirect3DCubeTexture.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DCubeTexture.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DCubeTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DSurface.h"
 *   #include "Mac/Win32 SDK/objbase.h"
 *   #include "Mac/Win32 SDK/DirectX SDK/d3d9.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 */

HRESULT CDirect3DCubeTexture_QueryInterface(const CDirect3DCubeTexture * _this, const IID *iid, GLenum (*ppvObj)());
HRESULT CDirect3DCubeTexture_AddDirtyRect(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect);
void CDirect3DCubeTexture_UpdateOpenGLSurfaces(const CDirect3DCubeTexture * _this, int RecreateTextureData);
HRESULT CDirect3DCubeTexture_GetLevelDesc(const CDirect3DCubeTexture * _this, UINT Level, D3DSURFACE_DESC *pDesc);
void ZN20CDirect3DCubeTextureD0Ev(void); /* CDirect3DCubeTexture_~CDirect3DCubeTexture */
HRESULT CDirect3DCubeTexture_GetCubeMapSurface(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9 * *ppCubeMapSurface);
HRESULT CDirect3DCubeTexture_LockRect(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags);
HRESULT CDirect3DCubeTexture_UnlockRect(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, UINT Level);
void ZN20CDirect3DCubeTextureD1Ev(void); /* CDirect3DCubeTexture_~CDirect3DCubeTexture */
void ZN20CDirect3DCubeTextureD2Ev(void); /* CDirect3DCubeTexture_~CDirect3DCubeTexture */
void CDirect3DCubeTexture_CDirect3DCubeTexture(const CDirect3DCubeTexture * _this, UINT32 EdgeLength, UINT32 Levels, DWORD Usage, D3DFORMAT Format);
void COpenGLTexture_UpdateOpenGLSurfaces(const COpenGLTexture * _this);
ULONG CDirect3DCubeTexture_AddRef(const CDirect3DCubeTexture * _this);
ULONG CDirect3DCubeTexture_Release(const CDirect3DCubeTexture * _this);
HRESULT CDirect3DCubeTexture_GetDevice(const CDirect3DCubeTexture * _this, void (*ppDevice)());
HRESULT CDirect3DCubeTexture_SetPrivateData(const CDirect3DCubeTexture * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DCubeTexture_GetPrivateData(const CDirect3DCubeTexture * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData);
HRESULT CDirect3DCubeTexture_FreePrivateData(const CDirect3DCubeTexture * _this, const GUID *refguid);
DWORD CDirect3DCubeTexture_SetPriority(const CDirect3DCubeTexture * _this, DWORD PriorityNew);
DWORD CDirect3DCubeTexture_GetPriority(const CDirect3DCubeTexture * _this);
void CDirect3DCubeTexture_PreLoad(const CDirect3DCubeTexture * _this);
D3DRESOURCETYPE CDirect3DCubeTexture_GetType(const CDirect3DCubeTexture * _this);
DWORD CDirect3DCubeTexture_SetLOD(const CDirect3DCubeTexture * _this, DWORD LODNew);
DWORD CDirect3DCubeTexture_GetLOD(const CDirect3DCubeTexture * _this);
DWORD CDirect3DCubeTexture_GetLevelCount(const CDirect3DCubeTexture * _this);
HRESULT CDirect3DCubeTexture_SetAutoGenFilterType(const CDirect3DCubeTexture * _this, D3DTEXTUREFILTERTYPE FilterType);
D3DTEXTUREFILTERTYPE CDirect3DCubeTexture_GetAutoGenFilterType(const CDirect3DCubeTexture * _this);
void CDirect3DCubeTexture_GenerateMipSubLevels(const CDirect3DCubeTexture * _this);
void ZN14COpenGLTextureD1Ev(void); /* COpenGLTexture_~COpenGLTexture */
void ZN14COpenGLTextureD0Ev(void); /* COpenGLTexture_~COpenGLTexture */
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_(void); /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >__M_fill_insert */
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void); /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >_erase */

/* line 105 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_QueryInterface(const CDirect3DCubeTexture * _this, const IID *iid, GLenum (*ppvObj)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 105 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 107 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 108 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 111 */
        "leave\n"
        "retl\n"
    );
}

/* line 213 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_AddDirtyRect(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 213 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x70(%eax), %edx\n" /* line 334 */
        "leal 0x74(%eax), %ecx\n" /* line 352 */
        "cmpl 0x74(%eax), %edx\n" /* line 217 */
        "je .Lf12e5e_00012e7c\n"
        ".Lf12e5e_00012e6f:\n"
        "movl (%edx), %eax\n" /* line 63 */
        "movb $1, 0x24(%eax)\n"
        "addl $4, %edx\n" /* line 623 */
        "cmpl (%ecx), %edx\n" /* line 217 */
        "jne .Lf12e5e_00012e6f\n"
        ".Lf12e5e_00012e7c:\n"
        "xorl %eax, %eax\n" /* line 223 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 228 */
__attribute__((naked))
void CDirect3DCubeTexture_UpdateOpenGLSurfaces(const CDirect3DCubeTexture * _this, int RecreateTextureData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movzbl 0xc(%ebp), %eax\n" /* RecreateTextureData */
        "movb %al, -0x2d(%ebp)\n" /* RecreateTextureData */
        "movl $0, -0x2c(%ebp)\n" /* FaceType */
        "leal 0x70(%edi), %edx\n" /* this */
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x70(%edi), %ecx\n" /* this */
        ".Lf12e80_00012ea3:\n"
        "xorl %esi, %esi\n"
        "jmp .Lf12e80_00012efb\n"
        /* { scope 1 */
        /* { scope 2: i */
        /* { scope 3 */
        ".Lf12e80_00012ea7:\n"
        "movl (%edi), %eax\n" /* line 240 | this */
        "leal -0x1c(%ebp), %edx\n" /* i */
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* Level */
        "movl -0x2c(%ebp), %edx\n" /* FaceType */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* this */
        "calll *0x48(%eax)\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 241 | i, pSurface */
        "movl %ebx, (%esp)\n" /* line 243 | pSurface */
        "calll CDirect3DSurface_IsDirty\n"
        "testb %al, %al\n"
        "jne .Lf12e80_00012ed6\n"
        "cmpb $0, -0x2d(%ebp)\n" /* RecreateTextureData */
        "je .Lf12e80_00012eea\n"
        ".Lf12e80_00012ed6:\n"
        "movzbl -0x2d(%ebp), %eax\n" /* line 245 | RecreateTextureData */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pSurface */
        "calll CDirect3DSurface_UpdateOpenGLSurfaceObject\n"
        "movb $0, 0x24(%ebx)\n" /* line 63 */
        ".Lf12e80_00012eea:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 249 | i */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        /* } scope */
        "addl $1, %esi\n" /* line 237 | Level */
        "movl 0x70(%edi), %ecx\n" /* this */
        ".Lf12e80_00012efb:\n"
        "movl -0x34(%ebp), %eax\n" /* line 361 */
        "movl 4(%eax), %edx\n"
        "subl %ecx, %edx\n" /* line 237 */
        "sarl $2, %edx\n"
        "movl $0xaaaaaaab, %eax\n"
        "mull %edx\n"
        "shrl $2, %edx\n"
        "cmpl %edx, %esi\n" /* Level */
        "jb .Lf12e80_00012ea7\n"
        /* } scope */
        "addl $1, -0x2c(%ebp)\n" /* line 235 | FaceType */
        "cmpl $6, -0x2c(%ebp)\n" /* FaceType */
        "jne .Lf12e80_00012ea3\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 252 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 119 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_GetLevelDesc(const CDirect3DCubeTexture * _this, UINT Level, D3DSURFACE_DESC *pDesc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 119 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        /* { scope 1 */
        "movl 0x44(%edx), %eax\n" /* line 495 */
        "addl 0xc(%ebp), %eax\n" /* Level */
        "shll $2, %eax\n" /* line 654 */
        "addl 0x70(%edx), %eax\n"
        "movl (%eax), %edx\n" /* line 43 */
        "movl (%edx), %ecx\n" /* line 126 */
        "movl 0x10(%ebp), %eax\n" /* pDesc */
        "movl %eax, 0xc(%ebp)\n" /* Level */
        "movl %edx, 8(%ebp)\n" /* this */
        "movl 0x30(%ecx), %ecx\n"
        /* } scope */
        "popl %ebp\n" /* line 127 */
        /* { scope 1 */
        "jmpl *%ecx\n" /* line 126 */
    );
}

/* line 88 */
__attribute__((naked))
void ZN20CDirect3DCubeTextureD0Ev(void) /* CDirect3DCubeTexture_~CDirect3DCubeTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_CDirect3DCubeTexture, (%edi)\n" /* this */
        "movl $vtbl_CDirect3DCubeTexture_secondary, 4(%edi)\n" /* this */
        "leal 0x70(%edi), %eax\n" /* line 93 | this */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x70(%edi), %eax\n" /* line 334 | this */
        "leal 0x74(%edi), %esi\n" /* line 352 | this */
        "cmpl 0x74(%edi), %eax\n" /* line 93 | this */
        "je .Lf12f4c_00012f8d\n"
        "movl %eax, %ebx\n"
        "jmp .Lf12f4c_00012f7c\n"
        ".Lf12f4c_00012f7a:\n"
        "movl %ebx, %eax\n"
        ".Lf12f4c_00012f7c:\n"
        "movl (%eax), %eax\n" /* line 95 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 93 */
        "jne .Lf12f4c_00012f7a\n"
        ".Lf12f4c_00012f8d:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf12f4c_00012fa2\n"
        ".Lf12f4c_00012f9b:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf12f4c_00012f9b\n"
        /* } scope */
        ".Lf12f4c_00012fa2:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf12f4c_00012fae\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf12f4c_00012fae:\n"
        "leal 0x5c(%edi), %eax\n" /* line 97 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 4(%edi)\n" /* this */
        "movl 8(%edi), %eax\n" /* line 99 | this */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf12f4c_00012fdc\n"
        "movl %edi, 8(%ebp)\n" /* line 97 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf12f4c_00012fdc:\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        "movl %edi, 8(%ebp)\n" /* line 97 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl %eax, %ebx\n"
        ".Lf12f4c_00012ffe:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 4(%edi)\n" /* this */
        "movl 8(%edi), %eax\n" /* line 99 | this */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf12f4c_00013023\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf12f4c_00013023:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf12f4c_00013042\n"
        ".Lf12f4c_0001303b:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf12f4c_0001303b\n"
        /* } scope */
        ".Lf12f4c_00013042:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf12f4c_0001304e\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf12f4c_0001304e:\n"
        "leal 0x5c(%edi), %eax\n" /* line 97 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf12f4c_00012ffe\n"
    );
}

/* line 136 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_GetCubeMapSurface(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9 * *ppCubeMapSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 136 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x10(%ebp), %ecx\n" /* Level */
        /* { scope 1 */
        "movl 0x70(%ebx), %esi\n" /* line 343 | this */
        "movl 0x74(%ebx), %edx\n" /* line 361 | this */
        "subl %esi, %edx\n" /* line 142 */
        "sarl $2, %edx\n"
        "movl $0xaaaaaaab, %eax\n"
        "mull %edx\n"
        "shrl $2, %edx\n"
        "cmpl %ecx, %edx\n"
        "ja .Lf1305c_0001308f\n"
        "movl $0x8876086c, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1305c_0001308f:\n"
        "movl 0xc(%ebp), %eax\n" /* line 495 | FaceType */
        "addl 0x44(%ebx, %eax, 4), %ecx\n" /* this */
        "movl (%esi, %ecx, 4), %eax\n" /* line 148 */
        "movl 0x14(%ebp), %edx\n" /* ppCubeMapSurface */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 149 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x10, %esp\n" /* line 154 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 165 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_LockRect(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 165 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xc, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* FaceType */
        "movl %eax, -0x10(%ebp)\n" /* FaceType */
        "movl 0x10(%ebp), %ebx\n" /* Level */
        "movl 0x14(%ebp), %eax\n" /* pLockedRect */
        "movl %eax, -0x14(%ebp)\n" /* pLockedRect */
        "movl 0x18(%ebp), %eax\n" /* pRect */
        "movl %eax, -0x18(%ebp)\n" /* pRect */
        "movl 0x1c(%ebp), %edi\n" /* Flags */
        "movl 0x70(%ecx), %esi\n" /* line 343 */
        "movl 0x74(%ecx), %edx\n" /* line 361 */
        "subl %esi, %edx\n" /* line 171 */
        "sarl $2, %edx\n"
        "movl $0xaaaaaaab, %eax\n"
        "mull %edx\n"
        "shrl $2, %edx\n"
        "cmpl %ebx, %edx\n" /* Level */
        "ja .Lf130b0_000130fa\n"
        "movl $0x8876086c, %eax\n" /* line 181 */
        "addl $0xc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf130b0_000130fa:\n"
        "movl -0x10(%ebp), %eax\n" /* line 495 | FaceType */
        "addl 0x44(%ecx, %eax, 4), %ebx\n" /* Level */
        "movl (%esi, %ebx, 4), %eax\n" /* line 43 */
        "movl (%eax), %edx\n" /* line 177 */
        "movl %edi, 0x14(%ebp)\n" /* Flags, pLockedRect */
        "movl -0x18(%ebp), %ecx\n" /* pRect */
        "movl %ecx, 0x10(%ebp)\n" /* Level */
        "movl -0x14(%ebp), %ecx\n" /* pLockedRect */
        "movl %ecx, 0xc(%ebp)\n" /* FaceType */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x34(%edx), %ecx\n"
        "addl $0xc, %esp\n" /* line 181 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 177 */
    );
}

/* line 189 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_UnlockRect(const CDirect3DCubeTexture * _this, D3DCUBEMAP_FACES FaceType, UINT Level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edi\n" /* FaceType */
        "movl 0x10(%ebp), %ebx\n" /* Level */
        "movl 0x70(%ecx), %esi\n" /* line 343 */
        "movl 0x74(%ecx), %edx\n" /* line 361 */
        "subl %esi, %edx\n" /* line 195 */
        "sarl $2, %edx\n"
        "movl $0xaaaaaaab, %eax\n"
        "mull %edx\n"
        "shrl $2, %edx\n"
        "cmpl %ebx, %edx\n" /* Level */
        "ja .Lf13124_00013156\n"
        "movl $0x8876086c, %eax\n" /* line 205 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13124_00013156:\n"
        "addl 0x44(%ecx, %edi, 4), %ebx\n" /* line 495 | Level */
        "movl (%esi, %ebx, 4), %eax\n" /* line 43 */
        "movl (%eax), %edx\n" /* line 201 */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x38(%edx), %ecx\n"
        "popl %ebx\n" /* line 205 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 201 */
    );
}

/* line 88 */
__attribute__((naked))
void ZN20CDirect3DCubeTextureD1Ev(void) /* CDirect3DCubeTexture_~CDirect3DCubeTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DCubeTexture, (%eax)\n"
        "movl $vtbl_CDirect3DCubeTexture_secondary, 4(%eax)\n"
        "movl %eax, %edi\n" /* line 93 */
        "addl $0x70, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 334 | this */
        "movl 0x70(%edx), %eax\n"
        "movl %edx, %esi\n" /* line 352 */
        "addl $0x74, %esi\n"
        "cmpl 0x74(%edx), %eax\n" /* line 93 */
        "je .Lf1316c_000131b1\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1316c_000131a0\n"
        ".Lf1316c_0001319e:\n"
        "movl %ebx, %eax\n"
        ".Lf1316c_000131a0:\n"
        "movl (%eax), %eax\n" /* line 95 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 93 */
        "jne .Lf1316c_0001319e\n"
        ".Lf1316c_000131b1:\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1316c_000131c3\n"
        ".Lf1316c_000131bc:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1316c_000131bc\n"
        /* } scope */
        ".Lf1316c_000131c3:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1316c_000131cf\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1316c_000131cf:\n"
        "movl 8(%ebp), %eax\n" /* line 97 | this */
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf1316c_00013205\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1316c_00013205:\n"
        "addl $0x1c, %esp\n" /* line 97 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        ".Lf1316c_0001320f:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1316c_00013237\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1316c_00013237:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1316c_00013253\n"
        ".Lf1316c_0001324c:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1316c_0001324c\n"
        /* } scope */
        ".Lf1316c_00013253:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1316c_0001325f\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1316c_0001325f:\n"
        "movl 8(%ebp), %eax\n" /* line 97 | this */
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf1316c_0001320f\n"
    );
}

/* line 88 */
__attribute__((naked))
void ZN20CDirect3DCubeTextureD2Ev(void) /* CDirect3DCubeTexture_~CDirect3DCubeTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 88 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DCubeTexture, (%eax)\n"
        "movl $vtbl_CDirect3DCubeTexture_secondary, 4(%eax)\n"
        "movl %eax, %edi\n" /* line 93 */
        "addl $0x70, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 334 | this */
        "movl 0x70(%edx), %eax\n"
        "movl %edx, %esi\n" /* line 352 */
        "addl $0x74, %esi\n"
        "cmpl 0x74(%edx), %eax\n" /* line 93 */
        "je .Lf13270_000132b5\n"
        "movl %eax, %ebx\n"
        "jmp .Lf13270_000132a4\n"
        ".Lf13270_000132a2:\n"
        "movl %ebx, %eax\n"
        ".Lf13270_000132a4:\n"
        "movl (%eax), %eax\n" /* line 95 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 93 */
        "jne .Lf13270_000132a2\n"
        ".Lf13270_000132b5:\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf13270_000132c7\n"
        ".Lf13270_000132c0:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf13270_000132c0\n"
        /* } scope */
        ".Lf13270_000132c7:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf13270_000132d3\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf13270_000132d3:\n"
        "movl 8(%ebp), %eax\n" /* line 97 | this */
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf13270_00013309\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf13270_00013309:\n"
        "addl $0x1c, %esp\n" /* line 97 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        ".Lf13270_00013313:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf13270_0001333b\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf13270_0001333b:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf13270_00013357\n"
        ".Lf13270_00013350:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf13270_00013350\n"
        /* } scope */
        ".Lf13270_00013357:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf13270_00013363\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf13270_00013363:\n"
        "movl 8(%ebp), %eax\n" /* line 97 | this */
        "addl $0x5c, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf13270_00013313\n"
    );
}

/* line 25 */
__attribute__((naked))
void CDirect3DCubeTexture_CDirect3DCubeTexture(const CDirect3DCubeTexture * _this, UINT32 EdgeLength, UINT32 Levels, DWORD Usage, D3DFORMAT Format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl imp___ZTV8IUnknown, %eax\n" /* line 77 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl imp___ZTV18IDirect3DResource9, %eax\n" /* line 852 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl imp___ZTV21IDirect3DBaseTexture9, %eax\n" /* line 1020 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl imp___ZTV21IDirect3DCubeTexture9, %eax\n" /* line 1294 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "addl $4, %edx\n" /* line 31 */
        "movl %edx, -0x4c(%ebp)\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n" /* this */
        /* { scope 1: i */
        "movl $4, (%esp)\n" /* line 564 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* TexID */
        "movl %eax, 4(%esp)\n" /* line 565 */
        "movl $1, (%esp)\n"
        "calll glGenTextures\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %esi\n" /* line 597 */
        "addl $0x66c, %esi\n"
        /* { scope 2: Level */
        "movl $0xc, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %ebx, 8(%eax)\n" /* line 104 */
        "movl %esi, 4(%esp)\n" /* line 1152 */
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        /* { scope 1: i */
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
        "movl 0xc(%ebp), %edx\n" /* line 91 | EdgeLength */
        "movl -0x4c(%ebp), %eax\n" /* this */
        "movl %edx, 0x28(%eax)\n"
        "movl %edx, 0x2c(%eax)\n"
        "movl $1, 0x30(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 31 | this */
        "movl $vtbl_CDirect3DCubeTexture, (%eax)\n"
        "movl $vtbl_CDirect3DCubeTexture_secondary, 4(%eax)\n"
        "movl $0, 0x38(%eax)\n"
        "movl %edx, 0x3c(%eax)\n"
        "movl $0, 0x40(%eax)\n"
        "addl $0x5c, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CMemoryBuffer_CMemoryBuffer\n"
        "movl 8(%ebp), %edx\n" /* this */
        "addl $0x70, %edx\n"
        "movl %edx, -0x40(%ebp)\n" /* this */
        /* { scope 1: i */
        "movl 8(%ebp), %eax\n" /* line 85 | this */
        "movl $0, 0x70(%eax)\n"
        "movl $0, 4(%edx)\n"
        "movl $0, 8(%edx)\n"
        /* } scope */
        /* { scope 1: i */
        "movl 0x10(%ebp), %ecx\n" /* line 40 | Levels */
        "testl %ecx, %ecx\n"
        "je .Lf13374_000136c0\n"
        "movl 0x10(%ebp), %eax\n" /* Levels */
        ".Lf13374_000134be:\n"
        "leal (%eax, %eax, 2), %esi\n" /* line 48 */
        "leal (%esi, %esi), %eax\n"
        "movl $0, -0x1c(%ebp)\n" /* line 442 */
        "movl 8(%ebp), %edx\n" /* line 343 | this */
        "movl 0x70(%edx), %ebx\n"
        "movl -0x40(%ebp), %edx\n" /* line 361 | this */
        "movl 4(%edx), %ecx\n"
        "movl %ecx, %edx\n" /* line 424 */
        "subl %ebx, %edx\n"
        "sarl $2, %edx\n"
        "cmpl %edx, %eax\n"
        "jae .Lf13374_0001369f\n"
        "leal (%ebx, %esi, 8), %eax\n" /* line 654 | TexID */
        "movl %ecx, 8(%esp)\n" /* line 425 */
        "movl %eax, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_\n"
        ".Lf13374_000134fc:\n"
        "leal 0x18(%ebp), %eax\n" /* line 51 | Format, TextureSizeInBytes */
        "movl %eax, 0x10(%esp)\n" /* TextureSizeInBytes */
        "movl 0x10(%ebp), %edx\n" /* Levels */
        "movl %edx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* EdgeLength, TextureSizeInBytes */
        "movl %eax, 4(%esp)\n" /* TextureSizeInBytes */
        "movl %eax, (%esp)\n" /* TextureSizeInBytes */
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 52 */
        "leal (%eax, %eax), %ebx\n"
        "movl %ebx, 4(%esp)\n" /* line 53 */
        "movl -0x44(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CMemoryBuffer_Resize\n"
        "movl -0x44(%ebp), %edx\n" /* line 56 */
        "movl 8(%edx), %eax\n"
        "movl %ebx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal -0x20(%ebp), %eax\n" /* line 59 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x8514, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl -0x4c(%ebp), %edx\n" /* line 60 */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glBindTexture\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x2c(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n" /* Offset */
        "movl $0, -0x38(%ebp)\n" /* i */
        "movl %eax, %edx\n"
        "jmp .Lf13374_000135a8\n"
        /* { scope 2: Level */
        ".Lf13374_00013593:\n"
        "addl $1, -0x38(%ebp)\n" /* line 67 | i */
        "addl $4, -0x2c(%ebp)\n"
        "cmpl $6, -0x38(%ebp)\n" /* i */
        "je .Lf13374_00013677\n"
        ".Lf13374_000135a5:\n"
        "movl -0x2c(%ebp), %edx\n"
        ".Lf13374_000135a8:\n"
        "movl 0x10(%ebp), %eax\n" /* line 69 | Levels */
        "imull -0x38(%ebp), %eax\n" /* i */
        "movl %eax, 0x44(%edx)\n"
        /* { scope 3 */
        "movl 0x10(%ebp), %edx\n" /* line 71 | Levels */
        "testl %edx, %edx\n"
        "je .Lf13374_00013593\n"
        "shll $2, %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0xc(%ebp), %ebx\n" /* EdgeLength */
        "movl $0, -0x34(%ebp)\n" /* Level */
        "movl %eax, %edx\n"
        "jmp .Lf13374_000135d0\n"
        ".Lf13374_000135cd:\n"
        "movl -0x30(%ebp), %edx\n"
        ".Lf13374_000135d0:\n"
        "movl -0x40(%ebp), %eax\n" /* line 654 | this */
        "addl (%eax), %edx\n"
        "movl %edx, -0x48(%ebp)\n"
        "movl -0x3c(%ebp), %edi\n" /* line 73 | Offset */
        "movl -0x44(%ebp), %eax\n"
        "addl 8(%eax), %edi\n"
        "movl $0x3c, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl -0x4c(%ebp), %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %edi, 0x1c(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %ebx, 0x10(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Level */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x38(%ebp), %eax\n" /* i */
        "addl $0x8515, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DSurface_CDirect3DSurface\n"
        "movl -0x48(%ebp), %edx\n"
        "movl %esi, (%edx)\n"
        "leal 0x18(%ebp), %eax\n" /* line 74 | Format */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll MacOpenGLUtils_GetLevelSizeInBytes\n"
        "addl %eax, -0x3c(%ebp)\n" /* Offset */
        "addl $1, -0x34(%ebp)\n" /* line 71 | Level */
        "shrl $1, %ebx\n"
        "addl $4, -0x30(%ebp)\n"
        "movl -0x34(%ebp), %edx\n" /* Level */
        "cmpl %edx, 0x10(%ebp)\n" /* Levels */
        "jne .Lf13374_000135cd\n"
        /* } scope */
        "addl $1, -0x38(%ebp)\n" /* line 67 | i */
        "addl $4, -0x2c(%ebp)\n"
        "cmpl $6, -0x38(%ebp)\n" /* i */
        "jne .Lf13374_000135a5\n"
        /* } scope */
        ".Lf13374_00013677:\n"
        "movl -0x20(%ebp), %eax\n" /* line 79 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x8513, (%esp)\n"
        "calll glBindTexture\n"
        "movl 0x10(%ebp), %edx\n" /* line 81 | Levels */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, 0x40(%eax)\n"
        "addl $1, 0x38(%eax)\n" /* line 51 */
        /* } scope */
        "addl $0x7c, %esp\n" /* line 84 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lf13374_0001369f:\n"
        "subl %edx, %eax\n" /* line 427 | __n */
        /* { scope 2: Level */
        "leal -0x1c(%ebp), %edx\n" /* line 658 */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_\n"
        "jmp .Lf13374_000134fc\n"
        /* } scope */
        ".Lf13374_000136c0:\n"
        "movl $1, 8(%esp)\n" /* line 42 */
        "movl 0xc(%ebp), %edx\n" /* EdgeLength */
        "movl %edx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MacOpenGLUtils_GetNumTextureLevels\n"
        "movl %eax, 0x10(%ebp)\n" /* Levels */
        "jmp .Lf13374_000134be\n"
        "movl %eax, %ebx\n"
        /* } scope */
        ".Lf13374_000136e1:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl -0x4c(%ebp), %edx\n" /* line 99 */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf13374_0001370c\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf13374_0001370c:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        /* { scope 1: i */
        /* { scope 2: Level */
        /* { scope 3 */
        "movl %esi, (%esp)\n" /* line 73 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf13374_0001371e:\n"
        "movl -0x40(%ebp), %eax\n" /* line 273 | this */
        "movl 4(%eax), %ecx\n" /* __last */
        "movl (%eax), %edx\n"
        "movl %edx, %eax\n"
        /* { scope 1: i */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf13374_00013733\n"
        ".Lf13374_0001372c:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf13374_0001372c\n"
        /* } scope */
        ".Lf13374_00013733:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf13374_0001373f\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf13374_0001373f:\n"
        "movl -0x44(%ebp), %edx\n" /* line 84 */
        "movl %edx, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf13374_000136e1\n"
        "movl %eax, %ebx\n"
        "jmp .Lf13374_0001371e\n"
    );
}

/* overload skip: CDirect3DCubeTexture_CDirect3DCubeTexture (0x13750) */

/* line 144 */
__attribute__((naked))
void COpenGLTexture_UpdateOpenGLSurfaces(const COpenGLTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 144 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
ULONG CDirect3DCubeTexture_AddRef(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x38(%edx), %eax\n"
        "addl $1, %eax\n"
        "movl %eax, 0x38(%edx)\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 52 */
__attribute__((naked))
ULONG CDirect3DCubeTexture_Release(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 52 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x38(%edx), %ebx\n" /* line 54 */
        "subl $1, %ebx\n"
        "movl %ebx, 0x38(%edx)\n"
        "testl %ebx, %ebx\n" /* line 55 */
        "jne .Lf2bce6e_002bce8d\n"
        "movl (%edx), %eax\n" /* line 57 */
        "movl %edx, (%esp)\n"
        "calll *0x5c(%eax)\n"
        ".Lf2bce6e_002bce8d:\n"
        "movl %ebx, %eax\n" /* line 60 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 62 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_GetDevice(const CDirect3DCubeTexture * _this, void (*ppDevice)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 62 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 63 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_SetPrivateData(const CDirect3DCubeTexture * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 64 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_GetPrivateData(const CDirect3DCubeTexture * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 64 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 65 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_FreePrivateData(const CDirect3DCubeTexture * _this, const GUID *refguid)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 65 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 66 */
__attribute__((naked))
DWORD CDirect3DCubeTexture_SetPriority(const CDirect3DCubeTexture * _this, DWORD PriorityNew)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 66 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 67 */
__attribute__((naked))
DWORD CDirect3DCubeTexture_GetPriority(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 67 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 68 */
__attribute__((naked))
void CDirect3DCubeTexture_PreLoad(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 70 */
__attribute__((naked))
D3DRESOURCETYPE CDirect3DCubeTexture_GetType(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "movl $5, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 71 */
__attribute__((naked))
DWORD CDirect3DCubeTexture_SetLOD(const CDirect3DCubeTexture * _this, DWORD LODNew)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 72 */
__attribute__((naked))
DWORD CDirect3DCubeTexture_GetLOD(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 72 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 73 */
__attribute__((naked))
DWORD CDirect3DCubeTexture_GetLevelCount(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 73 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x40(%eax), %eax\n" /* this */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 74 */
__attribute__((naked))
HRESULT CDirect3DCubeTexture_SetAutoGenFilterType(const CDirect3DCubeTexture * _this, D3DTEXTUREFILTERTYPE FilterType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 75 */
__attribute__((naked))
D3DTEXTUREFILTERTYPE CDirect3DCubeTexture_GetAutoGenFilterType(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 75 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 76 */
__attribute__((naked))
void CDirect3DCubeTexture_GenerateMipSubLevels(const CDirect3DCubeTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 76 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 94 */
__attribute__((naked))
void ZN14COpenGLTextureD1Ev(void) /* COpenGLTexture_~COpenGLTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edx), %eax\n" /* line 99 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jne .Lf2bcf08_002bcf26\n"
        "leave\n" /* line 103 */
        "retl\n"
        ".Lf2bcf08_002bcf26:\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        "leave\n" /* line 103 */
        "retl\n"
    );
}

/* line 94 */
__attribute__((naked))
void ZN14COpenGLTextureD0Ev(void) /* COpenGLTexture_~COpenGLTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* this */
        "movl 4(%ebx), %eax\n" /* line 99 | this */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf2bcf3a_002bcf68\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf2bcf3a_002bcf68:\n"
        "movl %ebx, 8(%ebp)\n" /* line 103 | this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 311 */
__attribute__((naked))
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEmRKS1_(void) /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >__M_fill_insert */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 311 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* line 313 | __n */
        "testl %ecx, %ecx\n"
        "je .Lf2bcf8a_002bd09c\n"
        "movl 8(%ebp), %edx\n" /* line 315 | this */
        "movl 4(%edx), %esi\n"
        "movl %esi, %ebx\n"
        "movl 8(%edx), %eax\n"
        "subl %esi, %eax\n"
        "sarl $2, %eax\n"
        "cmpl %eax, %ecx\n"
        "jbe .Lf2bcf8a_002bd0a4\n"
        "movl %edx, %ebx\n"
        /* { scope 1 */
        "movl %esi, %edx\n" /* line 403 */
        "subl (%ebx), %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* line 348 | __old_size */
        "movl $0x3fffffff, %eax\n" /* line 349 */
        "subl %edx, %eax\n"
        "cmpl %eax, %ecx\n"
        "ja .Lf2bcf8a_002bd1cc\n"
        /* { scope 2 */
        "cmpl %edx, %ecx\n" /* line 211 */
        "jbe .Lf2bcf8a_002bd119\n"
        "leal 0x10(%ebp), %eax\n" /* __n */
        /* } scope */
        "movl (%eax), %ecx\n" /* line 353 */
        "leal (%edx, %ecx), %eax\n" /* __len */
        "cmpl %eax, %edx\n" /* line 354 */
        "jbe .Lf2bcf8a_002bd129\n"
        ".Lf2bcf8a_002bcfef:\n"
        "movl $0x3fffffff, %eax\n"
        ".Lf2bcf8a_002bcff4:\n"
        "shll $2, %eax\n" /* line 88 */
        "movl %eax, -0x34(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ebp), %ebx\n" /* line 334 | this */
        "movl (%ebx), %eax\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl 0xc(%ebp), %ebx\n" /* line 300 | __position */
        "subl %eax, %ebx\n"
        "movl %ebx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll memmove\n"
        "movl -0x3c(%ebp), %edx\n" /* line 354 */
        "leal (%ebx, %edx), %eax\n"
        /* } scope */
        /* } scope */
        "movl 0x10(%ebp), %ecx\n" /* line 365 | __n */
        "movl %eax, %edx\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl 0x14(%ebp), %ebx\n" /* line 616 | __x */
        "movl (%ebx), %edi\n" /* __tmp */
        "testl %ecx, %ecx\n" /* line 617 */
        "je .Lf2bcf8a_002bd047\n"
        "xorl %esi, %esi\n"
        ".Lf2bcf8a_002bd038:\n"
        "movl %edi, (%edx)\n" /* line 618 | __tmp */
        "addl $4, %edx\n" /* line 623 */
        "addl $1, %esi\n"
        "cmpl %ecx, %esi\n" /* line 617 */
        "jne .Lf2bcf8a_002bd038\n"
        "movl 0x10(%ebp), %ecx\n" /* __n */
        /* } scope */
        /* } scope */
        ".Lf2bcf8a_002bd047:\n"
        "leal (%eax, %ecx, 4), %esi\n" /* line 368 */
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "movl 4(%eax), %ebx\n"
        /* { scope 2 */
        /* { scope 3 */
        "subl -0x30(%ebp), %ebx\n" /* line 300 */
        "movl %ebx, 8(%esp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memmove\n"
        "addl %esi, %ebx\n" /* line 354 */
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %ecx\n" /* line 379 | this */
        "movl 4(%ecx), %edx\n" /* __last */
        "movl (%ecx), %ecx\n"
        /* { scope 2 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bcf8a_002bd07d\n"
        "movl %ecx, %eax\n"
        ".Lf2bcf8a_002bd076:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bcf8a_002bd076\n"
        /* } scope */
        ".Lf2bcf8a_002bd07d:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bcf8a_002bd089\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bcf8a_002bd089:\n"
        "movl -0x3c(%ebp), %ecx\n" /* line 384 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %ecx, (%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 385 */
        "movl %ecx, %eax\n" /* line 386 */
        "addl -0x34(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        ".Lf2bcf8a_002bd09c:\n"
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bcf8a_002bd0a4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 318 | __x */
        "movl (%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* __x_copy */
        "movl %esi, %edi\n" /* line 319 */
        "subl -0x30(%ebp), %edi\n"
        "sarl $2, %edi\n"
        "movl %esi, -0x2c(%ebp)\n" /* line 603 */
        "cmpl %edi, %ecx\n" /* line 321 */
        "jb .Lf2bcf8a_002bd15a\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl %ecx, %edx\n" /* line 617 */
        "subl %edi, %edx\n" /* __tmp */
        "jne .Lf2bcf8a_002bd139\n"
        "movl 8(%ebp), %eax\n" /* this */
        /* } scope */
        /* } scope */
        ".Lf2bcf8a_002bd0c8:\n"
        "subl %edi, %ecx\n" /* line 338 */
        "leal (%esi, %ecx, 4), %esi\n"
        "movl %esi, 4(%eax)\n"
        /* { scope 2 */
        /* { scope 3 */
        "movl -0x2c(%ebp), %eax\n" /* line 300 */
        "subl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        "leal (, %edi, 4), %esi\n" /* line 342 */
        "movl 8(%ebp), %ecx\n" /* this */
        "addl %esi, 4(%ecx)\n"
        "movl 0xc(%ebp), %edx\n" /* line 343 | __position */
        "cmpl %edx, -0x2c(%ebp)\n" /* line 542 */
        "je .Lf2bcf8a_002bd09c\n"
        "movl %edx, %eax\n"
        "jmp .Lf2bcf8a_002bd104\n"
        ".Lf2bcf8a_002bd102:\n"
        "movl %eax, %edx\n"
        ".Lf2bcf8a_002bd104:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 543 | __x_copy */
        "movl %ecx, (%eax)\n"
        "leal 4(%edx), %eax\n" /* line 623 */
        "cmpl %eax, -0x2c(%ebp)\n" /* line 542 */
        "jne .Lf2bcf8a_002bd102\n"
        /* } scope */
        "addl $0x4c, %esp\n" /* line 386 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2bcf8a_002bd119:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 211 | __old_size */
        /* } scope */
        "movl (%eax), %ecx\n" /* line 353 */
        "leal (%edx, %ecx), %eax\n" /* __len */
        "cmpl %eax, %edx\n" /* line 354 */
        "ja .Lf2bcf8a_002bcfef\n"
        ".Lf2bcf8a_002bd129:\n"
        "cmpl $0x3fffffff, %eax\n" /* line 85 */
        "jbe .Lf2bcf8a_002bcff4\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        /* } scope */
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2bcf8a_002bd139:\n"
        "xorl %eax, %eax\n" /* line 617 */
        ".Lf2bcf8a_002bd13b:\n"
        "movl -0x38(%ebp), %ecx\n" /* line 618 | __x_copy */
        "movl %ecx, (%ebx)\n"
        "addl $4, %ebx\n" /* line 617 */
        "addl $1, %eax\n"
        "cmpl %edx, %eax\n"
        "jne .Lf2bcf8a_002bd13b\n"
        "movl 0x10(%ebp), %ecx\n" /* __n */
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 4(%ebx), %esi\n"
        "movl %ebx, %eax\n"
        "jmp .Lf2bcf8a_002bd0c8\n"
        /* } scope */
        ".Lf2bcf8a_002bd15a:\n"
        "leal (, %ecx, 4), %eax\n" /* line 321 */
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        "movl %esi, %edx\n" /* line 300 */
        "subl %eax, %edx\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl 0x10(%ebp), %eax\n" /* line 327 | __n */
        "shll $2, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "addl %eax, 4(%edx)\n"
        "movl %esi, %ecx\n" /* line 662 */
        "subl %eax, %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 2 */
        "subl -0x30(%ebp), %eax\n" /* line 424 */
        "andl $0xfffffffc, %eax\n" /* line 425 */
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "subl %eax, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll memmove\n"
        "movl 0x10(%ebp), %eax\n" /* line 654 | __n */
        "movl -0x30(%ebp), %ebx\n" /* __first */
        "leal (%ebx, %eax, 4), %ecx\n" /* __first */
        /* } scope */
        "movl %ebx, %eax\n" /* line 330 */
        "cmpl %ebx, %ecx\n" /* line 542 */
        "je .Lf2bcf8a_002bd09c\n"
        "movl %ebx, %edx\n"
        "jmp .Lf2bcf8a_002bd1bb\n"
        ".Lf2bcf8a_002bd1b9:\n"
        "movl %eax, %edx\n"
        ".Lf2bcf8a_002bd1bb:\n"
        "movl -0x38(%ebp), %ebx\n" /* line 543 | __x_copy */
        "movl %ebx, (%edx)\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %eax, %ecx\n" /* line 542 */
        "jne .Lf2bcf8a_002bd1b9\n"
        "jmp .Lf2bcf8a_002bd09c\n"
        /* } scope */
        /* { scope 1 */
        ".Lf2bcf8a_002bd1cc:\n"
        "movl $0x215ba4, (%esp)\n" /* line 350 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

/* line 122 */
__attribute__((naked))
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void) /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* __first */
        "movl 0x10(%ebp), %esi\n" /* __last */
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "movl 4(%eax), %ebx\n"
        /* { scope 1 */
        "subl %esi, %ebx\n" /* line 300 | __last */
        "movl %ebx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* __last */
        "movl %edi, (%esp)\n" /* __first */
        "calll memmove\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "movl 4(%eax), %edx\n"
        "leal (%edi, %ebx), %eax\n" /* __first */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf2bd1d8_002bd213\n"
        ".Lf2bd1d8_002bd20c:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bd1d8_002bd20c\n"
        ".Lf2bd1d8_002bd213:\n"
        "subl %edi, %esi\n" /* line 126 | __first, __last */
        "andl $0xfffffffc, %esi\n" /* __last */
        "subl %esi, %edx\n" /* __last */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, 4(%eax)\n"
        "movl %edi, %eax\n" /* line 127 | __first */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

