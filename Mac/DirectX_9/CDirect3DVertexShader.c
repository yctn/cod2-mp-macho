/* ASM dump from: CDirect3DVertexShader.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DVertexShader.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DVertexShader.h"
 *   #include "Mac/Win32 SDK/objbase.h"
 *   #include "Mac/Win32 SDK/DirectX SDK/d3d9.h"
 */

ULONG CDirect3DVertexShader_AddRef(const CDirect3DVertexShader * _this);
void ZN21CDirect3DVertexShaderD1Ev(void); /* CDirect3DVertexShader_~CDirect3DVertexShader */
void ZN21CDirect3DVertexShaderD0Ev(void); /* CDirect3DVertexShader_~CDirect3DVertexShader */
HRESULT CDirect3DVertexShader_QueryInterface(const CDirect3DVertexShader * _this, const IID *iid, unsigned char * *ppvObj);
ULONG CDirect3DVertexShader_Release(const CDirect3DVertexShader * _this);
HRESULT CDirect3DVertexShader_GetDevice(const CDirect3DVertexShader * _this, IDirect3DDevice9 * *ppDevice);
unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader * _this, const char * pSrcData);
HRESULT CDirect3DVertexShader_GetFunction(const CDirect3DVertexShader * _this, UINT *pSizeOfData);

/* line 48 */
__attribute__((naked))
ULONG CDirect3DVertexShader_AddRef(const CDirect3DVertexShader * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x194(%edx), %eax\n" /* line 50 */
        "addl $1, %eax\n"
        "movl %eax, 0x194(%edx)\n"
        "popl %ebp\n" /* line 51 */
        "retl\n"
    );
}

/* line 28 */
__attribute__((naked))
void ZN21CDirect3DVertexShaderD1Ev(void) /* CDirect3DVertexShader_~CDirect3DVertexShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3DVertexShader, (%eax)\n"
        "movl $vtbl_CDirect3DVertexShader_secondary, 4(%eax)\n"
        "addl $4, %eax\n" /* line 29 */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN20COpenGLVertexProgramD2Ev\n"
    );
}

/* line 28 */
__attribute__((naked))
void ZN21CDirect3DVertexShaderD0Ev(void) /* CDirect3DVertexShader_~CDirect3DVertexShader */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 28 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DVertexShader, (%ebx)\n" /* this */
        "movl $vtbl_CDirect3DVertexShader_secondary, 4(%ebx)\n" /* this */
        "leal 4(%ebx), %eax\n" /* line 29 | this */
        "movl %eax, (%esp)\n"
        "calll ZN20COpenGLVertexProgramD2Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 37 */
__attribute__((naked))
HRESULT CDirect3DVertexShader_QueryInterface(const CDirect3DVertexShader * _this, const IID *iid, unsigned char * *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 37 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 39 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 40 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 43 */
        "leave\n"
        "retl\n"
    );
}

/* line 56 */
__attribute__((naked))
ULONG CDirect3DVertexShader_Release(const CDirect3DVertexShader * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 56 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x194(%edx), %ebx\n" /* line 58 */
        "subl $1, %ebx\n"
        "movl %ebx, 0x194(%edx)\n"
        "testl %ebx, %ebx\n" /* line 60 */
        "jne .Lf202b2_000202d7\n"
        "movl (%edx), %eax\n" /* line 62 */
        "movl %edx, (%esp)\n"
        "calll *0x18(%eax)\n"
        ".Lf202b2_000202d7:\n"
        "movl %ebx, %eax\n" /* line 66 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 71 */
__attribute__((naked))
HRESULT CDirect3DVertexShader_GetDevice(const CDirect3DVertexShader * _this, IDirect3DDevice9 * *ppDevice)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 71 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 76 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 18 */
__attribute__((naked))
unsigned char CDirect3DVertexShader_CDirect3DVertexShader(const CDirect3DVertexShader * _this, const char * pSrcData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 18 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl imp___ZTV8IUnknown, %eax\n" /* line 77 */
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* this */
        "movl imp___ZTV22IDirect3DVertexShader9, %eax\n" /* line 942 */
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* line 21 | pSrcData */
        "movl %eax, 4(%esp)\n"
        "leal 4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGLVertexProgram_COpenGLVertexProgram\n"
        "movl $vtbl_CDirect3DVertexShader, (%ebx)\n" /* this */
        "movl $vtbl_CDirect3DVertexShader_secondary, 4(%ebx)\n" /* this */
        "movb $0, 0x198(%ebx)\n" /* this */
        "movl $1, 0x194(%ebx)\n" /* line 50 | this */
        "addl $0x14, %esp\n" /* line 24 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 40 */
__attribute__((naked))
HRESULT CDirect3DVertexShader_GetFunction(const CDirect3DVertexShader * _this, UINT *pSizeOfData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 40 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

