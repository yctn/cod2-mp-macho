/* ASM dump from: CDirect3DSwapChain.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DSwapChain.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DSwapChain.h"
 */

ULONG CDirect3DSwapChain_AddRef(const CDirect3DSwapChain * _this);
void ZN18CDirect3DSwapChainD1Ev(void); /* CDirect3DSwapChain_~CDirect3DSwapChain */
void ZN18CDirect3DSwapChainD0Ev(void); /* CDirect3DSwapChain_~CDirect3DSwapChain */
HRESULT CDirect3DSwapChain_QueryInterface(const CDirect3DSwapChain * _this, const IID *iid, LPVOID *ppvObj);
ULONG CDirect3DSwapChain_Release(const CDirect3DSwapChain * _this);
HRESULT CDirect3DSwapChain_GetBackBuffer(const CDirect3DSwapChain * _this, UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9 * *ppBackBuffer);
int CDirect3DSwapChain_SetBackBuffer(const CDirect3DSwapChain * _this, const IDirect3DSurface9 * pBackBuffer);
int CDirect3DSwapChain_CDirect3DSwapChain(const CDirect3DSwapChain * _this);
HRESULT CDirect3DSwapChain_Present(const CDirect3DSwapChain * _this, const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion, DWORD dwFlags);
HRESULT CDirect3DSwapChain_GetFrontBufferData(const CDirect3DSwapChain * _this, IDirect3DSurface9 *pDestSurface);
HRESULT CDirect3DSwapChain_GetRasterStatus(const CDirect3DSwapChain * _this, D3DRASTER_STATUS *pRasterStatus);
HRESULT CDirect3DSwapChain_GetDisplayMode(const CDirect3DSwapChain * _this, D3DDISPLAYMODE *pMode);
HRESULT CDirect3DSwapChain_GetDevice(const CDirect3DSwapChain * _this, D3DDEVICE_CREATION_PARAMETERS * (*ppDevice)());
HRESULT CDirect3DSwapChain_GetPresentParameters(const CDirect3DSwapChain * _this, D3DPRESENT_PARAMETERS *pPresentationParameters);

/* line 52 */
__attribute__((naked))
ULONG CDirect3DSwapChain_AddRef(const CDirect3DSwapChain * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 52 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 54 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 55 */
        "retl\n"
    );
}

/* line 27 */
__attribute__((naked))
void ZN18CDirect3DSwapChainD1Ev(void) /* CDirect3DSwapChain_~CDirect3DSwapChain */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DSwapChain, (%eax)\n"
        "movl 8(%eax), %edx\n" /* line 29 */
        "testl %edx, %edx\n"
        "je .Lf1e1ca_0001e1e8\n"
        "movl (%edx), %eax\n" /* line 31 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1e1ca_0001e1e8:\n"
        "leave\n" /* line 33 */
        "retl\n"
    );
}

/* line 27 */
__attribute__((naked))
void ZN18CDirect3DSwapChainD0Ev(void) /* CDirect3DSwapChain_~CDirect3DSwapChain */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 27 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DSwapChain, (%ebx)\n" /* this */
        "movl 8(%ebx), %edx\n" /* line 29 | this */
        "testl %edx, %edx\n"
        "je .Lf1e1ea_0001e209\n"
        "movl (%edx), %eax\n" /* line 31 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1e1ea_0001e209:\n"
        "movl %ebx, 8(%ebp)\n" /* line 33 | this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 41 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_QueryInterface(const CDirect3DSwapChain * _this, const IID *iid, LPVOID *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 43 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 44 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 47 */
        "leave\n"
        "retl\n"
    );
}

/* line 60 */
__attribute__((naked))
ULONG CDirect3DSwapChain_Release(const CDirect3DSwapChain * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 60 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 62 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 64 */
        "jne .Lf1e230_0001e24f\n"
        "movl (%edx), %eax\n" /* line 66 */
        "movl %edx, (%esp)\n"
        "calll *0x2c(%eax)\n"
        ".Lf1e230_0001e24f:\n"
        "movl %ebx, %eax\n" /* line 70 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 79 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_GetBackBuffer(const CDirect3DSwapChain * _this, UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9 * *ppBackBuffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 8(%ecx), %edx\n" /* line 81 */
        "movl 0x14(%ebp), %eax\n" /* ppBackBuffer */
        "movl %edx, (%eax)\n"
        "movl 8(%ecx), %eax\n" /* line 82 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 85 */
        "leave\n"
        "retl\n"
    );
}

/* line 90 */
__attribute__((naked))
int CDirect3DSwapChain_SetBackBuffer(const CDirect3DSwapChain * _this, const IDirect3DSurface9 * pBackBuffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 90 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* pBackBuffer */
        "movl 8(%ebp), %edx\n" /* line 92 | this */
        "movl %eax, 8(%edx)\n"
        "movl (%eax), %edx\n" /* line 93 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "leave\n" /* line 94 */
        "retl\n"
    );
}

/* line 18 */
__attribute__((naked))
int CDirect3DSwapChain_CDirect3DSwapChain(const CDirect3DSwapChain * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DSwapChain, (%eax)\n" /* line 20 */
        "movl $0, 8(%eax)\n"
        "movl $1, 4(%eax)\n" /* line 54 */
        "popl %ebp\n" /* line 23 */
        "retl\n"
    );
}

/* line 38 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_Present(const CDirect3DSwapChain * _this, const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion, DWORD dwFlags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 38 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 40 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_GetFrontBufferData(const CDirect3DSwapChain * _this, IDirect3DSurface9 *pDestSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 40 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 41 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_GetRasterStatus(const CDirect3DSwapChain * _this, D3DRASTER_STATUS *pRasterStatus)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 41 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 42 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_GetDisplayMode(const CDirect3DSwapChain * _this, D3DDISPLAYMODE *pMode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 43 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_GetDevice(const CDirect3DSwapChain * _this, D3DDEVICE_CREATION_PARAMETERS * (*ppDevice)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 43 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 44 */
__attribute__((naked))
HRESULT CDirect3DSwapChain_GetPresentParameters(const CDirect3DSwapChain * _this, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 44 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

