/* ASM dump from: CDirect3DTexture.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DTexture.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DSurface.h"
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/Win32 SDK/objbase.h"
 *   #include "Mac/Win32 SDK/DirectX SDK/d3d9.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

ULONG CDirect3DTexture_AddRef(const CDirect3DTexture * _this);
HRESULT CDirect3DTexture_QueryInterface(const CDirect3DTexture * _this, const IID *iid, GLenum (*ppvObj)());
ULONG CDirect3DTexture_Release(const CDirect3DTexture * _this);
HRESULT CDirect3DTexture_GetLevelDesc(const CDirect3DTexture * _this, UINT Level, D3DSURFACE_DESC *pDesc);
void CDirect3DTexture_UpdateOpenGLSurfaces(const CDirect3DTexture * _this, int RecreateTextureData);
HRESULT CDirect3DTexture_AddDirtyRect(const CDirect3DTexture * _this, const RECT *pDirtyRect);
HRESULT CDirect3DTexture_UnlockRect(const CDirect3DTexture * _this, UINT Level);
void ZN16CDirect3DTextureD0Ev(void); /* CDirect3DTexture_~CDirect3DTexture */
HRESULT CDirect3DTexture_LockRect(const CDirect3DTexture * _this, UINT Level, serverInfo_t (*pLockedRect)[20000], const RECT *pRect, DWORD Flags);
HRESULT CDirect3DTexture_GetSurfaceLevel(const CDirect3DTexture * _this, UINT Level, void *ppSurfaceLevel);
void CDirect3DTexture_CDirect3DTexture(const CDirect3DTexture * _this, UINT32 Width, UINT32 Height, UINT32 Levels, DWORD Usage, D3DFORMAT Format);
void ZN16CDirect3DTextureD2Ev(void); /* CDirect3DTexture_~CDirect3DTexture */
void ZN16CDirect3DTextureD1Ev(void); /* CDirect3DTexture_~CDirect3DTexture */
HRESULT CDirect3DTexture_GetDevice(const CDirect3DTexture * _this, void (*ppDevice)());
HRESULT CDirect3DTexture_SetPrivateData(const CDirect3DTexture * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
HRESULT CDirect3DTexture_GetPrivateData(const CDirect3DTexture * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData);
HRESULT CDirect3DTexture_FreePrivateData(const CDirect3DTexture * _this, const GUID *refguid);
DWORD CDirect3DTexture_SetPriority(const CDirect3DTexture * _this, DWORD PriorityNew);
DWORD CDirect3DTexture_GetPriority(const CDirect3DTexture * _this);
void CDirect3DTexture_PreLoad(const CDirect3DTexture * _this);
D3DRESOURCETYPE CDirect3DTexture_GetType(const CDirect3DTexture * _this);
DWORD CDirect3DTexture_SetLOD(const CDirect3DTexture * _this, DWORD LODNew);
DWORD CDirect3DTexture_GetLOD(const CDirect3DTexture * _this);
DWORD CDirect3DTexture_GetLevelCount(const CDirect3DTexture * _this);
HRESULT CDirect3DTexture_SetAutoGenFilterType(const CDirect3DTexture * _this, D3DTEXTUREFILTERTYPE FilterType);
D3DTEXTUREFILTERTYPE CDirect3DTexture_GetAutoGenFilterType(const CDirect3DTexture * _this);
void CDirect3DTexture_GenerateMipSubLevels(const CDirect3DTexture * _this);
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >__M_insert_aux */
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE7reserveEm(void); /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >_reserve */

/* line 202 */
__attribute__((naked))
ULONG CDirect3DTexture_AddRef(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 202 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x38(%edx), %eax\n" /* line 204 */
        "addl $1, %eax\n"
        "movl %eax, 0x38(%edx)\n"
        "popl %ebp\n" /* line 205 */
        "retl\n"
    );
}

/* line 191 */
__attribute__((naked))
HRESULT CDirect3DTexture_QueryInterface(const CDirect3DTexture * _this, const IID *iid, GLenum (*ppvObj)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 191 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 193 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 194 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 197 */
        "leave\n"
        "retl\n"
    );
}

/* line 210 */
__attribute__((naked))
ULONG CDirect3DTexture_Release(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x38(%edx), %ebx\n" /* line 212 */
        "subl $1, %ebx\n"
        "movl %ebx, 0x38(%edx)\n"
        "testl %ebx, %ebx\n" /* line 214 */
        "jne .Lf1e2dc_0001e2fb\n"
        "movl (%edx), %eax\n" /* line 216 */
        "movl %edx, (%esp)\n"
        "calll *0x5c(%eax)\n"
        ".Lf1e2dc_0001e2fb:\n"
        "movl %ebx, %eax\n" /* line 220 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 228 */
__attribute__((naked))
HRESULT CDirect3DTexture_GetLevelDesc(const CDirect3DTexture * _this, UINT Level, D3DSURFACE_DESC *pDesc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 228 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        /* { scope 1 */
        "movl (%edx), %ecx\n" /* line 233 */
        "leal -0xc(%ebp), %eax\n" /* Surface */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Level */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x48(%ecx)\n"
        "testl %eax, %eax\n" /* line 235 */
        "js .Lf1e304_0001e34f\n"
        "movl -0xc(%ebp), %eax\n" /* line 237 | Surface */
        "movl (%eax), %edx\n"
        "movl 0x10(%ebp), %ecx\n" /* pDesc */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl %eax, %ebx\n" /* hr */
        "movl -0xc(%ebp), %eax\n" /* line 238 | Surface */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 246 | hr */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1e304_0001e34f:\n"
        "movl $0x8876086c, %ebx\n" /* line 235 | hr */
        /* } scope */
        "movl %ebx, %eax\n" /* line 246 | hr */
        "addl $0x24, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 506 */
__attribute__((naked))
void CDirect3DTexture_UpdateOpenGLSurfaces(const CDirect3DTexture * _this, int RecreateTextureData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 506 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movzbl 0xc(%ebp), %ecx\n" /* RecreateTextureData */
        "movl 0x5c(%eax), %edx\n" /* line 334 */
        "leal 0x60(%eax), %esi\n" /* line 352 */
        "cmpl 0x60(%eax), %edx\n" /* line 513 */
        "je .Lf1e35c_0001e3b4\n"
        "testb %cl, %cl\n" /* line 522 */
        "jne .Lf1e35c_0001e3bb\n"
        "movl %edx, %ebx\n"
        "jmp .Lf1e35c_0001e387\n"
        ".Lf1e35c_0001e37e:\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl (%esi), %ebx\n" /* line 513 */
        "je .Lf1e35c_0001e3b4\n"
        ".Lf1e35c_0001e385:\n"
        "movl %ebx, %edx\n" /* line 515 */
        ".Lf1e35c_0001e387:\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CDirect3DSurface_IsDirty\n"
        "testb %al, %al\n"
        "je .Lf1e35c_0001e37e\n"
        "movl $0, 4(%esp)\n" /* line 518 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CDirect3DSurface_UpdateOpenGLSurfaceObject\n"
        "movl (%ebx), %eax\n" /* line 63 */
        "movb $0, 0x24(%eax)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl (%esi), %ebx\n" /* line 513 */
        "jne .Lf1e35c_0001e385\n"
        ".Lf1e35c_0001e3b4:\n"
        "addl $0x10, %esp\n" /* line 522 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e35c_0001e3bb:\n"
        "movl %edx, %ebx\n" /* line 513 */
        ".Lf1e35c_0001e3bd:\n"
        "movl (%edx), %eax\n" /* line 515 */
        "movl %eax, (%esp)\n"
        "calll CDirect3DSurface_IsDirty\n"
        "movl $1, 4(%esp)\n" /* line 518 */
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CDirect3DSurface_UpdateOpenGLSurfaceObject\n"
        "movl (%ebx), %eax\n" /* line 63 */
        "movb $0, 0x24(%eax)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl (%esi), %ebx\n" /* line 513 */
        "je .Lf1e35c_0001e3b4\n"
        "movl %ebx, %edx\n"
        "jmp .Lf1e35c_0001e3bd\n"
    );
}

/* line 491 */
__attribute__((naked))
HRESULT CDirect3DTexture_AddDirtyRect(const CDirect3DTexture * _this, const RECT *pDirtyRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x5c(%eax), %edx\n" /* line 334 */
        "leal 0x60(%eax), %ecx\n" /* line 352 */
        "cmpl 0x60(%eax), %edx\n" /* line 495 */
        "je .Lf1e3ea_0001e408\n"
        ".Lf1e3ea_0001e3fb:\n"
        "movl (%edx), %eax\n" /* line 63 */
        "movb $1, 0x24(%eax)\n"
        "addl $4, %edx\n" /* line 623 */
        "cmpl (%ecx), %edx\n" /* line 495 */
        "jne .Lf1e3ea_0001e3fb\n"
        ".Lf1e3ea_0001e408:\n"
        "xorl %eax, %eax\n" /* line 501 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 305 */
__attribute__((naked))
HRESULT CDirect3DTexture_UnlockRect(const CDirect3DTexture * _this, UINT Level)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 305 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Level */
        "movl 0x5c(%eax), %edx\n" /* line 343 */
        "movl 0x60(%eax), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 311 */
        "sarl $2, %eax\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf1e40c_0001e42b\n"
        "movl $0x8876086c, %eax\n" /* line 486 */
        "popl %ebp\n"
        "retl\n"
        ".Lf1e40c_0001e42b:\n"
        "movl (%edx, %ecx, 4), %eax\n" /* line 41 */
        "movl (%eax), %edx\n" /* line 317 */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x38(%edx), %ecx\n"
        "popl %ebp\n" /* line 486 */
        "jmpl *%ecx\n" /* line 317 */
    );
}

/* line 173 */
__attribute__((naked))
void ZN16CDirect3DTextureD0Ev(void) /* CDirect3DTexture_~CDirect3DTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl $vtbl_CDirect3DTexture, (%edi)\n" /* this */
        "movl $vtbl_CDirect3DTexture_secondary, 4(%edi)\n" /* this */
        "leal 0x5c(%edi), %eax\n" /* line 179 | this */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 0x5c(%edi), %eax\n" /* line 334 | this */
        "leal 0x60(%edi), %esi\n" /* line 352 | this */
        "cmpl 0x60(%edi), %eax\n" /* line 179 | this */
        "je .Lf1e43a_0001e47b\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1e43a_0001e46a\n"
        ".Lf1e43a_0001e468:\n"
        "movl %ebx, %eax\n"
        ".Lf1e43a_0001e46a:\n"
        "movl (%eax), %eax\n" /* line 181 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 179 */
        "jne .Lf1e43a_0001e468\n"
        ".Lf1e43a_0001e47b:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1e43a_0001e490\n"
        ".Lf1e43a_0001e489:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1e43a_0001e489\n"
        /* } scope */
        ".Lf1e43a_0001e490:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1e43a_0001e49c\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1e43a_0001e49c:\n"
        "leal 0x48(%edi), %eax\n" /* line 183 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%edi), %eax\n" /* line 99 */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf1e43a_0001e4ca\n"
        "movl %edi, 8(%ebp)\n" /* line 183 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        ".Lf1e43a_0001e4ca:\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        "movl %edi, 8(%ebp)\n" /* line 183 | this */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl %eax, %ebx\n"
        ".Lf1e43a_0001e4ec:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%edi), %eax\n" /* line 99 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf1e43a_0001e511\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1e43a_0001e511:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl -0x1c(%ebp), %eax\n" /* line 273 */
        "movl 4(%eax), %edx\n" /* __last */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1e43a_0001e530\n"
        ".Lf1e43a_0001e529:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1e43a_0001e529\n"
        /* } scope */
        ".Lf1e43a_0001e530:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1e43a_0001e53c\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1e43a_0001e53c:\n"
        "leal 0x48(%edi), %eax\n" /* line 183 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf1e43a_0001e4ec\n"
    );
}

/* line 282 */
__attribute__((naked))
HRESULT CDirect3DTexture_LockRect(const CDirect3DTexture * _this, UINT Level, serverInfo_t (*pLockedRect)[20000], const RECT *pRect, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Level */
        "movl 0x10(%ebp), %edi\n" /* pLockedRect */
        "movl 0x14(%ebp), %esi\n" /* pRect */
        "movl 0x18(%ebp), %ebx\n" /* Flags */
        "movl 0x5c(%eax), %edx\n" /* line 343 */
        "movl 0x60(%eax), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 288 */
        "sarl $2, %eax\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf1e54a_0001e578\n"
        "movl $0x8876086c, %eax\n" /* line 298 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e54a_0001e578:\n"
        "movl (%edx, %ecx, 4), %eax\n" /* line 41 */
        "movl (%eax), %edx\n" /* line 294 */
        "movl %ebx, 0x14(%ebp)\n" /* Flags, pRect */
        "movl %esi, 0x10(%ebp)\n" /* pRect, pLockedRect */
        "movl %edi, 0xc(%ebp)\n" /* pLockedRect, Level */
        "movl %eax, 8(%ebp)\n" /* this */
        "movl 0x34(%edx), %ecx\n"
        "popl %ebx\n" /* line 298 */
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "jmpl *%ecx\n" /* line 294 */
    );
}

/* line 254 */
__attribute__((naked))
HRESULT CDirect3DTexture_GetSurfaceLevel(const CDirect3DTexture * _this, UINT Level, void *ppSurfaceLevel)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 254 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Level */
        /* { scope 1 */
        "movl 0x5c(%eax), %edx\n" /* line 343 */
        "movl 0x60(%eax), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 260 */
        "sarl $2, %eax\n"
        "cmpl %ecx, %eax\n"
        "ja .Lf1e592_0001e5b4\n"
        "movl $0x8876086c, %eax\n"
        /* } scope */
        "leave\n" /* line 272 */
        "retl\n"
        /* { scope 1 */
        ".Lf1e592_0001e5b4:\n"
        "movl (%edx, %ecx, 4), %eax\n" /* line 266 */
        "movl 0x10(%ebp), %edx\n" /* ppSurfaceLevel */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 267 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 272 */
        "retl\n"
    );
}

/* line 26 */
__attribute__((naked))
void CDirect3DTexture_CDirect3DTexture(const CDirect3DTexture * _this, UINT32 Width, UINT32 Height, UINT32 Levels, DWORD Usage, D3DFORMAT Format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 26 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
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
        "movl imp___ZTV17IDirect3DTexture9, %eax\n" /* line 1091 */
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "addl $4, %edx\n" /* line 33 */
        "movl %edx, -0x40(%ebp)\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n" /* this */
        /* { scope 1: TotalBufferSize, Offset */
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
        "movl %ebx, 8(%eax)\n" /* line 104 | TextureSizeInBytes */
        "movl %esi, 4(%esp)\n" /* line 1152 */
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 91 | this */
        "addl $8, %eax\n" /* this */
        /* { scope 1: TotalBufferSize, Offset */
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
        "movl -0x40(%ebp), %eax\n" /* this */
        "movl %edx, 0x28(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 0x2c(%eax)\n"
        "movl $1, 0x30(%eax)\n"
        "movl 8(%ebp), %eax\n" /* line 33 | this */
        "movl $vtbl_CDirect3DTexture, (%eax)\n"
        "movl $vtbl_CDirect3DTexture_secondary, 4(%eax)\n"
        "movl $0, 0x38(%eax)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, 0x3c(%eax)\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 0x40(%eax)\n"
        "movl $0, 0x44(%eax)\n"
        "addl $0x48, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll CMemoryBuffer_CMemoryBuffer\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x5c, %eax\n"
        "movl %eax, -0x38(%ebp)\n" /* this */
        /* { scope 1: TotalBufferSize, Offset */
        "movl 8(%ebp), %edx\n" /* line 85 | this */
        "movl $0, 0x5c(%edx)\n"
        "movl $0, 4(%eax)\n"
        "movl $0, 8(%eax)\n"
        /* } scope */
        /* { scope 1: TotalBufferSize, Offset */
        "movl 0x14(%ebp), %edi\n" /* line 50 | Levels */
        "testl %edi, %edi\n"
        "jne .Lf1e5c8_0001e7ec\n"
        "movl $1, 8(%esp)\n" /* line 52 */
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, (%esp)\n"
        "calll MacOpenGLUtils_GetNumTextureLevels\n"
        "movl %eax, 0x14(%ebp)\n" /* Levels */
        ".Lf1e5c8_0001e738:\n"
        "movl %eax, 4(%esp)\n" /* line 58 */
        "movl -0x38(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE7reserveEm\n"
        "leal -0x24(%ebp), %eax\n" /* line 61 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x8069, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl -0x40(%ebp), %edx\n" /* line 62 */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "cmpl $1, 0x18(%ebp)\n" /* line 64 | Usage */
        "je .Lf1e5c8_0001e84e\n"
        /* { scope 2: Level */
        /* { scope 3 */
        "movl 0x14(%ebp), %edi\n" /* line 103 | Levels, Level */
        "testl %edi, %edi\n" /* Level */
        "jne .Lf1e5c8_0001e7f4\n"
        "movl $0, -0x34(%ebp)\n" /* TotalBufferSize */
        /* } scope */
        ".Lf1e5c8_0001e78a:\n"
        "movl -0x34(%ebp), %edx\n" /* line 118 | TotalBufferSize */
        "movl %edx, 4(%esp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CMemoryBuffer_Resize\n"
        "movl -0x3c(%ebp), %edx\n" /* line 119 */
        "movl 8(%edx), %eax\n"
        "movl -0x34(%ebp), %edx\n" /* TotalBufferSize */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        /* { scope 3 */
        "movl 0x14(%ebp), %esi\n" /* line 121 | Levels */
        "testl %esi, %esi\n"
        "jne .Lf1e5c8_0001e936\n"
        /* } scope */
        /* } scope */
        ".Lf1e5c8_0001e7c4:\n"
        "movl -0x24(%ebp), %eax\n" /* line 164 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl 0x14(%ebp), %eax\n" /* line 166 | Levels */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x44(%edx)\n"
        "addl $1, 0x38(%edx)\n" /* line 204 */
        /* } scope */
        "addl $0x6c, %esp\n" /* line 169 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1e5c8_0001e7ec:\n"
        "movl 0x14(%ebp), %eax\n" /* Levels */
        "jmp .Lf1e5c8_0001e738\n"
        /* { scope 1: TotalBufferSize, Offset */
        /* { scope 2: Level */
        ".Lf1e5c8_0001e7f4:\n"
        "movl 0xc(%ebp), %esi\n" /* line 610 | Width */
        "movl 0x10(%ebp), %ebx\n" /* Height, TexID */
        "xorl %edi, %edi\n" /* Level */
        "movl $0, -0x34(%ebp)\n" /* TotalBufferSize */
        /* } scope */
        /* { scope 2: Level */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf1e5c8_0001e803:\n"
        "leal 0x1c(%ebp), %eax\n" /* line 105 | Format, TextureSizeInBytes */
        "movl %eax, 0x10(%esp)\n" /* TextureSizeInBytes */
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* TextureSizeInBytes */
        "movl %esi, (%esp)\n"
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "addl $0x1f, %eax\n" /* line 106 */
        "andl $0xffffffe0, %eax\n" /* line 107 */
        "addl %eax, -0x34(%ebp)\n" /* TotalBufferSize */
        "movl %esi, %eax\n" /* line 109 */
        "shrl $1, %eax\n"
        "testl %esi, %esi\n"
        "cmovnel %eax, %esi\n"
        "movl %ebx, %eax\n" /* line 113 | TextureSizeInBytes */
        "shrl $1, %eax\n"
        "testl %ebx, %ebx\n" /* TextureSizeInBytes */
        "cmovnel %eax, %ebx\n" /* TextureSizeInBytes */
        /* } scope */
        "addl $1, %edi\n" /* line 103 | Level */
        "cmpl %edi, 0x14(%ebp)\n" /* Level, Levels */
        "jne .Lf1e5c8_0001e803\n"
        "jmp .Lf1e5c8_0001e78a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: Level */
        ".Lf1e5c8_0001e84e:\n"
        "cmpl $1, 0xc(%ebp)\n" /* line 144 | Width */
        "ja .Lf1e5c8_0001ea42\n"
        "movl $1, %edx\n"
        ".Lf1e5c8_0001e85d:\n"
        "cmpl $1, 0x10(%ebp)\n" /* Height */
        "ja .Lf1e5c8_0001ea61\n"
        "movl $1, %ecx\n"
        ".Lf1e5c8_0001e86c:\n"
        "leal 0x1c(%ebp), %eax\n" /* line 79 | Format */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Levels */
        "movl %eax, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "movl %eax, %ebx\n" /* TextureSizeInBytes */
        "movl %eax, 4(%esp)\n" /* line 80 */
        "movl -0x3c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll CMemoryBuffer_Resize\n"
        "movl -0x3c(%ebp), %edx\n" /* line 88 */
        "movl 8(%edx), %eax\n"
        "movl %ebx, 8(%esp)\n" /* TextureSizeInBytes */
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl -0x3c(%ebp), %eax\n" /* line 92 */
        "movl 8(%eax), %esi\n"
        "movl $0x3c, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* TextureSizeInBytes */
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %esi, 0x1c(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* TextureSizeInBytes */
        "calll CDirect3DSurface_CDirect3DSurface\n"
        "movl %ebx, -0x20(%ebp)\n" /* TextureSizeInBytes */
        "movl -0x38(%ebp), %eax\n" /* line 604 | this */
        "movl 4(%eax), %edx\n"
        "cmpl 8(%eax), %edx\n"
        "je .Lf1e5c8_0001ea80\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1e5c8_0001e928\n"
        "movl %ebx, (%edx)\n" /* TextureSizeInBytes */
        "movl 4(%eax), %edx\n"
        ".Lf1e5c8_0001e928:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl -0x38(%ebp), %eax\n" /* this */
        "movl %edx, 4(%eax)\n"
        "jmp .Lf1e5c8_0001e7c4\n"
        /* } scope */
        /* { scope 2: Level */
        /* { scope 3 */
        ".Lf1e5c8_0001e936:\n"
        "movl $0, -0x30(%ebp)\n" /* line 121 | Offset */
        "movl $0, -0x2c(%ebp)\n" /* Level */
        "jmp .Lf1e5c8_0001e971\n"
        /* { scope 4 */
        ".Lf1e5c8_0001e946:\n"
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf1e5c8_0001e94f\n"
        "movl %ebx, (%edx)\n" /* TextureSizeInBytes */
        "movl 4(%eax), %edx\n"
        ".Lf1e5c8_0001e94f:\n"
        "addl $4, %edx\n" /* line 607 */
        "movl -0x38(%ebp), %eax\n" /* this */
        "movl %edx, 4(%eax)\n"
        ".Lf1e5c8_0001e958:\n"
        "addl %edi, -0x30(%ebp)\n" /* line 134 | Level, Offset */
        /* } scope */
        "addl $1, -0x2c(%ebp)\n" /* line 121 | Level */
        "shrl 0xc(%ebp)\n" /* Width */
        "shrl 0x10(%ebp)\n" /* Height */
        "movl -0x2c(%ebp), %eax\n" /* Level */
        "cmpl %eax, 0x14(%ebp)\n" /* Levels */
        "je .Lf1e5c8_0001e7c4\n"
        /* { scope 4 */
        ".Lf1e5c8_0001e971:\n"
        "leal 0x1c(%ebp), %eax\n" /* line 123 | Format, TextureSizeInBytes */
        "movl %eax, 0x10(%esp)\n" /* TextureSizeInBytes */
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* Height */
        "movl %edx, 4(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Width, TextureSizeInBytes */
        "movl %eax, (%esp)\n" /* TextureSizeInBytes */
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "leal 0x1f(%eax), %edi\n" /* line 124 | Level */
        "andl $0xffffffe0, %edi\n" /* Level */
        "movl $1, %eax\n" /* line 125 */
        "movl 0xc(%ebp), %ebx\n" /* Width, TextureSizeInBytes */
        "testl %ebx, %ebx\n" /* TextureSizeInBytes */
        "movl 0xc(%ebp), %edx\n" /* Width */
        "cmovel %eax, %edx\n"
        "movl %edx, 0xc(%ebp)\n" /* Width */
        "movl 0x10(%ebp), %ecx\n" /* line 129 | Height */
        "testl %ecx, %ecx\n"
        "cmovnel 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 0x10(%ebp)\n" /* Height */
        "movl -0x30(%ebp), %esi\n" /* line 133 | Offset */
        "movl -0x3c(%ebp), %eax\n"
        "addl 8(%eax), %esi\n"
        "movl $0x3c, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* TextureSizeInBytes */
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x20(%esp)\n"
        "movl %esi, 0x1c(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* Width */
        "movl %edx, 0x10(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Level */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* TextureSizeInBytes */
        "calll CDirect3DSurface_CDirect3DSurface\n"
        "movl %ebx, -0x1c(%ebp)\n" /* TextureSizeInBytes */
        "movl -0x38(%ebp), %eax\n" /* line 604 | this */
        "movl 4(%eax), %edx\n"
        "cmpl 8(%eax), %edx\n"
        "jne .Lf1e5c8_0001e946\n"
        "leal -0x1c(%ebp), %eax\n" /* line 610 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "jmp .Lf1e5c8_0001e958\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e5c8_0001ea42:\n"
        "movl $1, %edx\n" /* line 64 */
        "movl $0x20, %eax\n"
        /* { scope 2: Level */
        ".Lf1e5c8_0001ea4c:\n"
        "addl %edx, %edx\n" /* line 144 */
        "cmpl %edx, 0xc(%ebp)\n" /* Width */
        "jbe .Lf1e5c8_0001e85d\n"
        "subl $1, %eax\n"
        "jne .Lf1e5c8_0001ea4c\n"
        "jmp .Lf1e5c8_0001e85d\n"
        ".Lf1e5c8_0001ea61:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lf1e5c8_0001ea6b:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, 0x10(%ebp)\n" /* Height */
        "jbe .Lf1e5c8_0001e86c\n"
        "subl $1, %eax\n"
        "jne .Lf1e5c8_0001ea6b\n"
        "jmp .Lf1e5c8_0001e86c\n"
        ".Lf1e5c8_0001ea80:\n"
        "leal -0x20(%ebp), %eax\n" /* line 610 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl -0x38(%ebp), %edx\n" /* this */
        "movl %edx, (%esp)\n"
        "calll ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "jmp .Lf1e5c8_0001e7c4\n"
        "movl %eax, %esi\n"
        /* } scope */
        /* { scope 2: Level */
        /* { scope 3 */
        /* { scope 4 */
        "movl %ebx, (%esp)\n" /* line 133 | TextureSizeInBytes */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1e5c8_0001eaa5:\n"
        "movl -0x38(%ebp), %edx\n" /* line 273 | this */
        "movl 4(%edx), %ecx\n" /* __last */
        "movl (%edx), %edx\n"
        "movl %edx, %eax\n"
        /* { scope 1: TotalBufferSize, Offset */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf1e5c8_0001eaba\n"
        ".Lf1e5c8_0001eab3:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf1e5c8_0001eab3\n"
        /* } scope */
        ".Lf1e5c8_0001eaba:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf1e5c8_0001eac6\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1e5c8_0001eac6:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 169 */
        "movl %edx, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf1e5c8_0001ead5\n"
        "movl %eax, %esi\n"
        ".Lf1e5c8_0001ead5:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl -0x40(%ebp), %edx\n" /* line 99 */
        "movl 4(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1e5c8_0001eb00\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1e5c8_0001eb00:\n"
        "movl %esi, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        "jmp .Lf1e5c8_0001eaa5\n"
    );
}

/* overload skip: CDirect3DTexture_CDirect3DTexture (0x1eb0c) */

/* line 173 */
__attribute__((naked))
void ZN16CDirect3DTextureD2Ev(void) /* CDirect3DTexture_~CDirect3DTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DTexture, (%eax)\n"
        "movl $vtbl_CDirect3DTexture_secondary, 4(%eax)\n"
        "movl %eax, %edi\n" /* line 179 */
        "addl $0x5c, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 334 | this */
        "movl 0x5c(%edx), %eax\n"
        "movl %edx, %esi\n" /* line 352 */
        "addl $0x60, %esi\n"
        "cmpl 0x60(%edx), %eax\n" /* line 179 */
        "je .Lf1f050_0001f095\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1f050_0001f084\n"
        ".Lf1f050_0001f082:\n"
        "movl %ebx, %eax\n"
        ".Lf1f050_0001f084:\n"
        "movl (%eax), %eax\n" /* line 181 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 179 */
        "jne .Lf1f050_0001f082\n"
        ".Lf1f050_0001f095:\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1f050_0001f0a7\n"
        ".Lf1f050_0001f0a0:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1f050_0001f0a0\n"
        /* } scope */
        ".Lf1f050_0001f0a7:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1f050_0001f0b3\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1f050_0001f0b3:\n"
        "movl 8(%ebp), %eax\n" /* line 183 | this */
        "addl $0x48, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1f050_0001f0e9\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1f050_0001f0e9:\n"
        "addl $0x1c, %esp\n" /* line 183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        ".Lf1f050_0001f0f3:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lf1f050_0001f11b\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1f050_0001f11b:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1f050_0001f137\n"
        ".Lf1f050_0001f130:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1f050_0001f130\n"
        /* } scope */
        ".Lf1f050_0001f137:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1f050_0001f143\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1f050_0001f143:\n"
        "movl 8(%ebp), %eax\n" /* line 183 | this */
        "addl $0x48, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf1f050_0001f0f3\n"
    );
}

/* line 173 */
__attribute__((naked))
void ZN16CDirect3DTextureD1Ev(void) /* CDirect3DTexture_~CDirect3DTexture */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 173 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DTexture, (%eax)\n"
        "movl $vtbl_CDirect3DTexture_secondary, 4(%eax)\n"
        "movl %eax, %edi\n" /* line 179 */
        "addl $0x5c, %edi\n"
        "movl 8(%ebp), %edx\n" /* line 334 | this */
        "movl 0x5c(%edx), %eax\n"
        "movl %edx, %esi\n" /* line 352 */
        "addl $0x60, %esi\n"
        "cmpl 0x60(%edx), %eax\n" /* line 179 */
        "je .Lf1f154_0001f199\n"
        "movl %eax, %ebx\n"
        "jmp .Lf1f154_0001f188\n"
        ".Lf1f154_0001f186:\n"
        "movl %ebx, %eax\n"
        ".Lf1f154_0001f188:\n"
        "movl (%eax), %eax\n" /* line 181 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "addl $4, %ebx\n" /* line 623 */
        "cmpl %ebx, (%esi)\n" /* line 179 */
        "jne .Lf1f154_0001f186\n"
        ".Lf1f154_0001f199:\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1f154_0001f1ab\n"
        ".Lf1f154_0001f1a4:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1f154_0001f1a4\n"
        /* } scope */
        ".Lf1f154_0001f1ab:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1f154_0001f1b7\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1f154_0001f1b7:\n"
        "movl 8(%ebp), %eax\n" /* line 183 | this */
        "addl $0x48, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lf1f154_0001f1ed\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1f154_0001f1ed:\n"
        "addl $0x1c, %esp\n" /* line 183 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        ".Lf1f154_0001f1f7:\n"
        "movl imp___ZTV14COpenGLTexture, %eax\n" /* line 95 */
        "addl $8, %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edx), %eax\n" /* line 99 */
        "movl (%eax), %esi\n"
        "testl %esi, %esi\n"
        "je .Lf1f154_0001f21f\n"
        "movl %eax, 4(%esp)\n" /* line 101 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_ReleaseTextureBinding\n"
        ".Lf1f154_0001f21f:\n"
        "movl %ebx, (%esp)\n" /* line 103 */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "movl 4(%edi), %edx\n" /* line 273 | __last */
        "movl (%edi), %ecx\n"
        "movl %ecx, %eax\n"
        /* { scope 1 */
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf1f154_0001f23b\n"
        ".Lf1f154_0001f234:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1f154_0001f234\n"
        /* } scope */
        ".Lf1f154_0001f23b:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf1f154_0001f247\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf1f154_0001f247:\n"
        "movl 8(%ebp), %eax\n" /* line 183 | this */
        "addl $0x48, %eax\n"
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "jmp .Lf1f154_0001f1f7\n"
    );
}

/* line 50 */
__attribute__((naked))
HRESULT CDirect3DTexture_GetDevice(const CDirect3DTexture * _this, void (*ppDevice)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 50 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 51 */
__attribute__((naked))
HRESULT CDirect3DTexture_SetPrivateData(const CDirect3DTexture * _this, const GUID *refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 52 */
__attribute__((naked))
HRESULT CDirect3DTexture_GetPrivateData(const CDirect3DTexture * _this, const GUID *refguid, void *pData, DWORD *pSizeOfData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 52 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 53 */
__attribute__((naked))
HRESULT CDirect3DTexture_FreePrivateData(const CDirect3DTexture * _this, const GUID *refguid)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 53 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 54 */
__attribute__((naked))
DWORD CDirect3DTexture_SetPriority(const CDirect3DTexture * _this, DWORD PriorityNew)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 54 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 55 */
__attribute__((naked))
DWORD CDirect3DTexture_GetPriority(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 56 */
__attribute__((naked))
void CDirect3DTexture_PreLoad(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 57 */
__attribute__((naked))
D3DRESOURCETYPE CDirect3DTexture_GetType(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "movl $3, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 58 */
__attribute__((naked))
DWORD CDirect3DTexture_SetLOD(const CDirect3DTexture * _this, DWORD LODNew)
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
DWORD CDirect3DTexture_GetLOD(const CDirect3DTexture * _this)
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
DWORD CDirect3DTexture_GetLevelCount(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x44(%eax), %eax\n" /* this */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 66 */
__attribute__((naked))
HRESULT CDirect3DTexture_SetAutoGenFilterType(const CDirect3DTexture * _this, D3DTEXTUREFILTERTYPE FilterType)
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
D3DTEXTUREFILTERTYPE CDirect3DTexture_GetAutoGenFilterType(const CDirect3DTexture * _this)
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
void CDirect3DTexture_GenerateMipSubLevels(const CDirect3DTexture * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 68 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >__M_insert_aux */
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
        "je .Lf2bdc3c_002bdc94\n"
        /* { scope 1 */
        "testl %edx, %edx\n" /* line 104 */
        "je .Lf2bdc3c_002bdc5c\n"
        "movl -4(%edx), %eax\n"
        "movl %eax, (%edx)\n"
        "movl 4(%edi), %edx\n"
        ".Lf2bdc3c_002bdc5c:\n"
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
        ".Lf2bdc3c_002bdc94:\n"
        "movl %edx, %eax\n" /* line 759 */
        "subl (%edi), %eax\n" /* this */
        "sarl $2, %eax\n"
        "cmpl $0x3fffffff, %eax\n" /* line 265 */
        "je .Lf2bdc3c_002bdd62\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bdc3c_002bdd40\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bdc3c_002bdcb3:\n"
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
        "je .Lf2bdc3c_002bdcec\n"
        "movl 0x10(%ebp), %ecx\n" /* __x */
        "movl (%ecx), %eax\n"
        "movl %eax, (%edx)\n"
        ".Lf2bdc3c_002bdcec:\n"
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
        "je .Lf2bdc3c_002bdd1c\n"
        ".Lf2bdc3c_002bdd15:\n"
        "addl $4, %eax\n" /* line 623 */
        "cmpl %edx, %eax\n" /* line 173 */
        "jne .Lf2bdc3c_002bdd15\n"
        ".Lf2bdc3c_002bdd1c:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bdc3c_002bdd28\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bdc3c_002bdd28:\n"
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
        ".Lf2bdc3c_002bdd40:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bdc3c_002bdd58\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "jbe .Lf2bdc3c_002bdcb3\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bdc3c_002bdd58:\n"
        "movl $0x3fffffff, %edx\n" /* line 272 */
        "jmp .Lf2bdc3c_002bdcb3\n"
        ".Lf2bdc3c_002bdd62:\n"
        "movl $0x215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}

/* line 69 */
__attribute__((naked))
void ZNSt6vectorIP16CDirect3DSurfaceSaIS1_EE7reserveEm(void) /* std_vector<CDirect3DSurface*, std_allocator<CDirect3DSurface*> >_reserve */
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
        "ja .Lf2bdd6e_002bde15\n"
        "movl 8(%ebp), %eax\n" /* line 343 | this */
        "movl (%eax), %esi\n"
        "movl %eax, %ecx\n" /* line 73 */
        "movl 8(%eax), %eax\n"
        "subl %esi, %eax\n"
        "sarl $2, %eax\n"
        "cmpl %eax, %edx\n"
        "ja .Lf2bdd6e_002bdda1\n"
        "addl $0x2c, %esp\n" /* line 86 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bdd6e_002bdda1:\n"
        "movl 4(%ecx), %ebx\n" /* line 361 */
        "subl %esi, %ebx\n" /* line 403 */
        "movl %ebx, %eax\n"
        "sarl $2, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $0x3fffffff, %edx\n" /* line 85 */
        "ja .Lf2bdd6e_002bde21\n"
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
        "je .Lf2bdd6e_002bddeb\n"
        "movl %ecx, %eax\n"
        ".Lf2bdd6e_002bdde4:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf2bdd6e_002bdde4\n"
        /* } scope */
        ".Lf2bdd6e_002bddeb:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bdd6e_002bddf7\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bdd6e_002bddf7:\n"
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
        ".Lf2bdd6e_002bde15:\n"
        "movl $0x215c24, (%esp)\n" /* line 72 */
        "calll __ZSt20__throw_length_errorPKc\n"
        /* { scope 1 */
        ".Lf2bdd6e_002bde21:\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
    );
}

