/* ASM dump from: CDirect3DIndexBuffer.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DIndexBuffer.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DIndexBuffer.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

ULONG CDirect3DIndexBuffer_AddRef(const CDirect3DIndexBuffer * _this);
void ZN20CDirect3DIndexBufferD1Ev(void); /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
void ZN20CDirect3DIndexBufferD0Ev(void); /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
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

/* line 66 */
__attribute__((naked))
ULONG CDirect3DIndexBuffer_AddRef(const CDirect3DIndexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 66 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 68 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 69 */
        "retl\n"
    );
}

/* line 44 */
__attribute__((naked))
void ZN20CDirect3DIndexBufferD1Ev(void) /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DIndexBuffer, (%eax)\n"
        "addl $0xc, %eax\n" /* line 47 */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN13CMemoryBufferD1Ev\n"
    );
}

/* line 44 */
__attribute__((naked))
void ZN20CDirect3DIndexBufferD0Ev(void) /* CDirect3DIndexBuffer_~CDirect3DIndexBuffer */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DIndexBuffer, (%ebx)\n" /* this */
        "leal 0xc(%ebx), %eax\n" /* line 47 | this */
        "movl %eax, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 55 */
__attribute__((naked))
HRESULT CDirect3DIndexBuffer_QueryInterface(const CDirect3DIndexBuffer * _this, const IID *iid, LPVOID *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 57 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 58 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 61 */
        "leave\n"
        "retl\n"
    );
}

/* line 74 */
__attribute__((naked))
ULONG CDirect3DIndexBuffer_Release(const CDirect3DIndexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 74 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 76 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 78 */
        "jne .Lf1be54_0001be73\n"
        "movl (%edx), %eax\n" /* line 80 */
        "movl %edx, (%esp)\n"
        "calll *0x3c(%eax)\n"
        ".Lf1be54_0001be73:\n"
        "movl %ebx, %eax\n" /* line 84 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 168 */
__attribute__((naked))
HRESULT CDirect3DIndexBuffer_Unlock(const CDirect3DIndexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 168 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 171 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 94 */
__attribute__((naked))
HRESULT CDirect3DIndexBuffer_Lock(const CDirect3DIndexBuffer * _this, UINT OffsetToLock, UINT SizeToLock, J_COLOR_SPACE * *ppbDat, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 94 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* OffsetToLock */
        "movl 0x10(%ebp), %eax\n" /* SizeToLock, ppbDat */
        "movb $1, 0x30(%edi)\n" /* line 64 */
        "testl %eax, %eax\n" /* line 109 */
        "jne .Lf1be84_0001bea1\n"
        "movl 8(%edi), %eax\n" /* this */
        ".Lf1be84_0001bea1:\n"
        "movl %eax, 0x2c(%edi)\n" /* this */
        "testb $2, 0x25(%edi)\n" /* line 115 | this */
        "je .Lf1be84_0001beb3\n"
        "testl $0x2000, 0x18(%ebp)\n" /* line 119 | Flags */
        "jne .Lf1be84_0001beca\n"
        ".Lf1be84_0001beb3:\n"
        "addl 0x14(%edi), %esi\n" /* line 157 | this, OffsetToLock */
        "movl %esi, 0x28(%edi)\n" /* OffsetToLock, this */
        "movl %esi, %edx\n" /* OffsetToLock */
        "movl 0x14(%ebp), %eax\n" /* line 160 | ppbDat */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 163 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1be84_0001beca:\n"
        "leal 0xc(%edi), %ebx\n" /* line 129 | this */
        "movl $2, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll CMemoryBuffer_FreeLater\n"
        "movl %ebx, (%esp)\n" /* line 130 */
        "calll CMemoryBuffer_Recreate\n"
        "addl 8(%ebx), %esi\n" /* line 132 | OffsetToLock */
        "movl %esi, 0x28(%edi)\n" /* OffsetToLock, this */
        "movl %esi, %edx\n" /* OffsetToLock */
        "movl 0x14(%ebp), %eax\n" /* line 160 | ppbDat */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 163 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 25 */
__attribute__((naked))
J_COLOR_SPACE CDirect3DIndexBuffer_CDirect3DIndexBuffer(const CDirect3DIndexBuffer * _this, UINT32 Length, D3DFORMAT Format, DWORD Usage, D3DPOOL Pool)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 25 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DIndexBuffer, (%ebx)\n" /* line 33 | this */
        "movl $0, 4(%ebx)\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 147 | Length */
        "addl $3, %eax\n"
        "andl $0xfffffffc, %eax\n"
        "movl %eax, 8(%ebx)\n" /* line 33 | this */
        "leal 0xc(%ebx), %esi\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CMemoryBuffer_CMemoryBuffer\n"
        "leal 0x10(%ebp), %eax\n" /* Format */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetFormatSizeInBits\n"
        "shrl $3, %eax\n"
        "movl %eax, 0x20(%ebx)\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* Usage */
        "movl %eax, 0x24(%ebx)\n" /* this */
        "movl $0, 0x28(%ebx)\n" /* this */
        "movl $0, 0x2c(%ebx)\n" /* this */
        "movb $0, 0x30(%ebx)\n" /* this */
        "addl $1, 4(%ebx)\n" /* line 68 | this */
        "addl $0x10, %esp\n" /* line 40 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n" /* this */
        "movl %esi, (%esp)\n"
        "calll ZN13CMemoryBufferD1Ev\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* overload skip: CDirect3DIndexBuffer_CDirect3DIndexBuffer (0x1bf76) */

/* line 51 */
__attribute__((naked))
HRESULT CDirect3DIndexBuffer_GetDevice(const CDirect3DIndexBuffer * _this, IDirect3DDevice9 * *ppDevice)
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
HRESULT CDirect3DIndexBuffer_SetPrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid, const J_COLOR_SPACE *pData, DWORD SizeOfData, DWORD Flags)
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
HRESULT CDirect3DIndexBuffer_GetPrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid, J_COLOR_SPACE *pData, DWORD *pSizeOfData)
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
HRESULT CDirect3DIndexBuffer_FreePrivateData(const CDirect3DIndexBuffer * _this, const GUID *refguid)
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
DWORD CDirect3DIndexBuffer_SetPriority(const CDirect3DIndexBuffer * _this, DWORD PriorityNew)
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
DWORD CDirect3DIndexBuffer_GetPriority(const CDirect3DIndexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 57 */
__attribute__((naked))
J_COLOR_SPACE CDirect3DIndexBuffer_PreLoad(const CDirect3DIndexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 57 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 58 */
__attribute__((naked))
D3DRESOURCETYPE CDirect3DIndexBuffer_GetType(const CDirect3DIndexBuffer * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 58 */
        "movl %esp, %ebp\n"
        "movl $7, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 61 */
__attribute__((naked))
HRESULT CDirect3DIndexBuffer_GetDesc(const CDirect3DIndexBuffer * _this, D3DINDEXBUFFER_DESC *pDesc)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 61 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

