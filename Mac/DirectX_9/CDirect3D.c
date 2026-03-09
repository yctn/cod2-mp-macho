/* ASM dump from: CDirect3D.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3D.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3D.h"
 *   #include "Mac/DirectX 9/CVAOPacket.h"
 *   #include "Mac/DirectX 9/COpenGLVAO.h"
 *   #include "Mac/DirectX 9/CDirect3DDevice.h"
 *   #include "Mac/DirectX 9/COpenGLVertexProgram.h"
 *   #include "Mac/DirectX 9/CDirect3DVertexBuffer.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 *   #include "Mac/DirectX 9/MacOpenGLMath.h"
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DVolumeTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DCubeTexture.h"
 *   #include "Mac/DirectX 9/CDirect3DPixelShader.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 */

extern bool g_special; /* 0x0 */
extern CVAOPacket *g_CurrentGenericPacket; /* 0x0 */
extern UINT32 g_Low; /* 0x0 */
extern UINT32 g_High; /* 0x0 */
extern GLenum D3DToOpenGLPrimitive[7]; /* 0x30824c */
static CDirect3D *sDirect3DInterface; /* 0x334d80 */

HRESULT CDirect3DDevice_DrawPrimitive(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
HRESULT CDirect3DDevice_DrawPrimitiveUP(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride);
ULONG CDirect3D_AddRef(const CDirect3D * _this);
void ZN9CDirect3DD1Ev(void); /* CDirect3D_~CDirect3D */
void ZN9CDirect3DD0Ev(void); /* CDirect3D_~CDirect3D */
HRESULT CDirect3D_QueryInterface(const CDirect3D * _this, const IID *iid, LPVOID *ppvObj);
ULONG CDirect3D_Release(const CDirect3D * _this);
UINT CDirect3D_GetAdapterCount(const CDirect3D * _this);
HRESULT CDirect3D_GetAdapterIdentifier(const CDirect3D * _this, UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9 *pIdentifier);
UINT CDirect3D_GetAdapterModeCount(const CDirect3D * _this, UINT Adapter, D3DFORMAT Format);
HRESULT CDirect3D_EnumAdapterModes(const CDirect3D * _this, UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE *pMode);
HRESULT CDirect3D_GetAdapterDisplayMode(const CDirect3D * _this, UINT Adapter, D3DDISPLAYMODE *pMode);
HRESULT CDirect3D_CheckDeviceFormat(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat);
HRESULT CDirect3D_CheckDeviceMultiSampleType(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD *pQualityLevels);
HRESULT CDirect3D_CheckDepthStencilMatch(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat);
HRESULT CDirect3D_GetDeviceCaps(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 *pCaps);
HRESULT CDirect3D_CreateDevice(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS *pPresentationParameters, HRESULT (*ppReturnedDeviceInterface)());
HRESULT CDirect3DDevice_SetDepthStencilSurface(const CDirect3DDevice * _this, IDirect3DSurface9 *pNewZStencil);
void CDirect3DDevice_CreateAndSetGenericProgrammableVAO(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices);
void COpenGL_SetTexBorderColor(const COpenGL * _this, UINT32 Unit, GLenum Target, GLuint Value);
HRESULT CDirect3DDevice_SetTexture(const CDirect3DDevice * _this, DWORD Stage, IDirect3DBaseTexture9 *pTexture);
bool CDirect3DDevice_GetStreamPtrs(const CDirect3DDevice * _this, UINT32 StartVertex);
bool CDirect3DDevice_GetCanUseVAOWithTexCoordStreams(const CDirect3DDevice * _this, int CanUseVAO);
void CDirect3DDevice_CreateAndSetGenericFixedFunctionVAO(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices, int NeedsNormals);
void CDirect3DDevice_ValidateLighting(const CDirect3DDevice * _this);
void COpenGL_SetTex(const COpenGL * _this, UINT32 Unit, GLenum Target, const COpenGLTexture * pOpenGLTexInfo);
void CDirect3DDevice_SetStream(const CDirect3DDevice * _this, bool *IsTexCoordStream, UINT32 ActiveStream, UINT32 VertexRegisterAddress, UINT32 Offset, UINT32 Stride, GLint VSize, GLenum VType);
void CDirect3DDevice_ParseShaderDeclaration(const CDirect3DDevice * _this, int IsFixedFunction, bool *CanUseVAO);
void CDirect3DDevice_ValidateModelViewMatrix(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_SetTransform(const CDirect3DDevice * _this, D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix);
CDirect3D * CDirect3D_GetDirect3DInterface(void);
IDirect3D9 * Direct3DCreate9(UINT SDKVersion);
void CDirect3DDevice_CreateAndSetFixedFunctionVAO(const CDirect3DDevice * _this, bool *CanUseVAO, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices, int NeedsNormals);
void CDirect3DDevice_CreateAndSetProgrammableVAO(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices);
void CDirect3DDevice_ValidateTransformation(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices);
void CDirect3DDevice_SynchronizeD3DAndOpenGLTextureState(const CDirect3DDevice * _this, IDirect3DBaseTexture9 *pTex, UINT32 Stage);
void CDirect3DDevice_ValidateRasterization(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 EndVertex);
HRESULT CDirect3DDevice_DrawIndexedPrimitive(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount);
HRESULT CDirect3D_RegisterSoftwareDevice(const CDirect3D * _this, void *pInitializeFunction);
HRESULT CDirect3D_CheckDeviceType(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed);
HRESULT CDirect3D_CheckDeviceFormatConversion(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat);
HMONITOR CDirect3D_GetAdapterMonitor(const CDirect3D * _this, UINT Adapter);
bool CVAOPacketFixedFunction_IsFixedFunction(const CVAOPacketFixedFunction * _this);
bool CVAOPacketProgrammable_IsFixedFunction(const CVAOPacketProgrammable * _this);
void ZN22CVAOPacketProgrammableD1Ev(void); /* CVAOPacketProgrammable_~CVAOPacketProgrammable */
void ZN22CVAOPacketProgrammableD0Ev(void); /* CVAOPacketProgrammable_~CVAOPacketProgrammable */
void ZN23CVAOPacketFixedFunctionD1Ev(void); /* CVAOPacketFixedFunction_~CVAOPacketFixedFunction */
void ZN23CVAOPacketFixedFunctionD0Ev(void); /* CVAOPacketFixedFunction_~CVAOPacketFixedFunction */

/* line 177 */
__attribute__((naked))
HRESULT CDirect3DDevice_DrawPrimitive(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 177 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 311 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 382 */
__attribute__((naked))
HRESULT CDirect3DDevice_DrawPrimitiveUP(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 382 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 483 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3192 */
__attribute__((naked))
ULONG CDirect3D_AddRef(const CDirect3D * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3192 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 3194 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 3195 */
        "retl\n"
    );
}

/* line 3153 */
__attribute__((naked))
void ZN9CDirect3DD1Ev(void) /* CDirect3D_~CDirect3D */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3153 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3D, (%eax)\n"
        "movl $0, sDirect3DInterface\n" /* line 3155 */
        "popl %ebp\n" /* line 3156 */
        "retl\n"
    );
}

/* line 3153 */
__attribute__((naked))
void ZN9CDirect3DD0Ev(void) /* CDirect3D_~CDirect3D */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3153 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl $vtbl_CDirect3D, (%eax)\n"
        "movl $0, sDirect3DInterface\n" /* line 3155 */
        "movl %eax, 8(%ebp)\n" /* line 3156 | this */
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 3181 */
__attribute__((naked))
HRESULT CDirect3D_QueryInterface(const CDirect3D * _this, const IID *iid, LPVOID *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3181 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 3183 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 3184 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 3187 */
        "leave\n"
        "retl\n"
    );
}

/* line 3200 */
__attribute__((naked))
ULONG CDirect3D_Release(const CDirect3D * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3200 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 3202 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 3204 */
        "jne .Lfe092_0000e0b1\n"
        "movl (%edx), %eax\n" /* line 3206 */
        "movl %edx, (%esp)\n"
        "calll *0x48(%eax)\n"
        ".Lfe092_0000e0b1:\n"
        "movl %ebx, %eax\n" /* line 3210 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3215 */
__attribute__((naked))
UINT CDirect3D_GetAdapterCount(const CDirect3D * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3215 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n" /* line 3220 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3229 */
__attribute__((naked))
HRESULT CDirect3D_GetAdapterIdentifier(const CDirect3D * _this, UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9 *pIdentifier)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3229 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 3260 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3268 */
__attribute__((naked))
UINT CDirect3D_GetAdapterModeCount(const CDirect3D * _this, UINT Adapter, D3DFORMAT Format)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3268 */
        "movl %esp, %ebp\n"
        "cmpl $0x16, 0x10(%ebp)\n" /* line 3275 | Format */
        "je .Lfe0cc_0000e0d9\n"
        "xorl %eax, %eax\n" /* line 3294 */
        "popl %ebp\n"
        "retl\n"
        ".Lfe0cc_0000e0d9:\n"
        "popl %ebp\n"
        "jmp MacDisplay_GetNumModes\n" /* line 3278 */
    );
}

/* line 3304 */
__attribute__((naked))
HRESULT CDirect3D_EnumAdapterModes(const CDirect3D * _this, UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE *pMode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3304 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x10(%ebp), %esi\n" /* Format */
        "movl 0x14(%ebp), %edi\n" /* Mode */
        "movl 0x18(%ebp), %ebx\n" /* pMode */
        /* { scope 1 */
        "movl $0, 8(%ebx)\n" /* line 3312 | pMode */
        "movl $0, 4(%ebx)\n" /* pMode */
        "movl $0, (%ebx)\n" /* pMode */
        "movl $0, 0xc(%ebx)\n" /* line 3313 | pMode */
        "movl (%ecx), %edx\n" /* line 3315 */
        "movl %esi, 8(%esp)\n" /* Format */
        "movl 0xc(%ebp), %eax\n" /* Adapter */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *0x18(%edx)\n"
        "cmpl %edi, %eax\n" /* Mode */
        "jbe .Lfe0e0_0000e1af\n"
        "leal -0x15(%esi), %ecx\n" /* line 3323 | Allow32BitFormat */
        "cmpl $0xe, %ecx\n"
        "jbe .Lfe0e0_0000e174\n"
        ".Lfe0e0_0000e133:\n"
        "movb $0, -0x29(%ebp)\n" /* Allow16BitFormat */
        "xorl %esi, %esi\n" /* Allow32BitFormat */
        ".Lfe0e0_0000e139:\n"
        "leal -0x28(%ebp), %eax\n" /* line 3342 | rate */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* depth */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* height */
        "movl %eax, 8(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* width */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* Mode */
        "calll MacDisplay_GetNthMode\n"
        "movl -0x24(%ebp), %eax\n" /* line 3350 | depth */
        "cmpl $0x10, %eax\n"
        "je .Lfe0e0_0000e1ca\n"
        "cmpl $0x20, %eax\n" /* line 3354 */
        "je .Lfe0e0_0000e18e\n"
        ".Lfe0e0_0000e16a:\n"
        "xorl %eax, %eax\n" /* line 3364 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 3368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe0e0_0000e174:\n"
        "movl $1, %eax\n" /* line 3323 */
        "shll %cl, %eax\n"
        "testl $0x4003, %eax\n"
        "jne .Lfe0e0_0000e1bc\n"
        "testb $0x1c, %al\n"
        "je .Lfe0e0_0000e133\n"
        "movb $1, -0x29(%ebp)\n" /* Allow16BitFormat */
        "xorl %esi, %esi\n" /* Allow32BitFormat */
        "jmp .Lfe0e0_0000e139\n"
        ".Lfe0e0_0000e18e:\n"
        "movl %esi, %eax\n" /* line 3354 | Allow32BitFormat */
        "testb %al, %al\n"
        "je .Lfe0e0_0000e16a\n"
        "movl $0x16, %edx\n"
        ".Lfe0e0_0000e199:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 3361 | width */
        "movl %eax, (%ebx)\n" /* pMode */
        "movl -0x20(%ebp), %eax\n" /* line 3362 | height */
        "movl %eax, 4(%ebx)\n" /* pMode */
        "movl -0x28(%ebp), %eax\n" /* line 3363 | rate */
        "movl %eax, 8(%ebx)\n" /* pMode */
        "movl %edx, 0xc(%ebx)\n" /* line 3364 | pMode */
        "jmp .Lfe0e0_0000e16a\n"
        ".Lfe0e0_0000e1af:\n"
        "movl $0x8876086c, %eax\n" /* line 3315 */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 3368 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe0e0_0000e1bc:\n"
        "movb $0, -0x29(%ebp)\n" /* line 3323 | Allow16BitFormat */
        "movl $1, %esi\n" /* Allow32BitFormat */
        "jmp .Lfe0e0_0000e139\n"
        ".Lfe0e0_0000e1ca:\n"
        "cmpb $0, -0x29(%ebp)\n" /* line 3350 | Allow16BitFormat */
        "je .Lfe0e0_0000e16a\n"
        "movl $0x19, %edx\n"
        "jmp .Lfe0e0_0000e199\n"
    );
}

/* line 3376 */
__attribute__((naked))
HRESULT CDirect3D_GetAdapterDisplayMode(const CDirect3D * _this, UINT Adapter, D3DDISPLAYMODE *pMode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3376 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x24, %esp\n"
        "movl 0x10(%ebp), %ebx\n" /* pMode */
        "movl 0xc(%ebp), %eax\n" /* line 3386 | Adapter */
        "testl %eax, %eax\n"
        "je .Lfe1d8_0000e1f4\n"
        "movl $0x8876086c, %eax\n"
        "addl $0x24, %esp\n" /* line 3409 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe1d8_0000e1f4:\n"
        "leal -0x18(%ebp), %eax\n" /* line 3389 | rate */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* depth */
        "movl %eax, 8(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* height */
        "movl %eax, 4(%esp)\n"
        "leal -0xc(%ebp), %eax\n" /* width */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetCurrentMode\n"
        "movl -0xc(%ebp), %eax\n" /* line 3391 | width */
        "movl %eax, (%ebx)\n" /* pMode */
        "movl -0x10(%ebp), %eax\n" /* line 3392 | height */
        "movl %eax, 4(%ebx)\n" /* pMode */
        "movl -0x18(%ebp), %eax\n" /* line 3393 | rate */
        "movl %eax, 8(%ebx)\n" /* pMode */
        "xorl %eax, %eax\n" /* line 3394 */
        "cmpl $0x10, -0x14(%ebp)\n" /* depth */
        "sete %al\n"
        "leal 0x15(, %eax, 4), %eax\n"
        "movl %eax, 0xc(%ebx)\n" /* pMode */
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x24, %esp\n" /* line 3409 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3421 */
__attribute__((naked))
HRESULT CDirect3D_CheckDeviceFormat(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3421 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %ecx\n" /* line 3428 | Adapter */
        "testl %ecx, %ecx\n"
        "je .Lfe240_0000e254\n"
        "movl $0x8876086c, %eax\n"
        /* } scope */
        "leave\n" /* line 3489 */
        "retl\n"
        /* { scope 1 */
        ".Lfe240_0000e254:\n"
        "calll MacDisplay_GetCurrentDepth\n" /* line 3435 */
        "movl 0x18(%ebp), %edx\n" /* line 3439 | Usage */
        "testl %edx, %edx\n"
        "jne .Lfe240_0000e28e\n"
        "cmpl $0x31545844, 0x20(%ebp)\n" /* line 3441 | CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x32545844, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x33545844, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x35545844, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        ".Lfe240_0000e284:\n"
        "cmpl $0x16, 0x20(%ebp)\n" /* line 3478 | CheckFormat */
        "jne .Lfe240_0000e2c8\n"
        ".Lfe240_0000e28a:\n"
        "xorl %eax, %eax\n" /* line 3482 */
        /* } scope */
        ".Lfe240_0000e28c:\n"
        "leave\n" /* line 3489 */
        "retl\n"
        /* { scope 1 */
        ".Lfe240_0000e28e:\n"
        "cmpl $2, 0x18(%ebp)\n" /* line 3447 | Usage */
        "jne .Lfe240_0000e2d5\n"
        "cmpl $1, 0x1c(%ebp)\n" /* line 3449 | RType */
        "jne .Lfe240_0000e2b2\n"
        "cmpl $0x10, %eax\n" /* line 3451 */
        "jne .Lfe240_0000e2e2\n"
        "cmpl $0x50, 0x20(%ebp)\n" /* line 3453 | CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x49, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        ".Lfe240_0000e2ab:\n"
        "movl $0x8876086a, %eax\n" /* line 3482 */
        /* } scope */
        ".Lfe240_0000e2b0:\n"
        "leave\n" /* line 3489 */
        "retl\n"
        /* { scope 1 */
        ".Lfe240_0000e2b2:\n"
        "cmpl $3, 0x1c(%ebp)\n" /* line 3466 | RType */
        "jne .Lfe240_0000e2ab\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 3469 */
        "cmpl $0xffff01ff, %eax\n"
        "jbe .Lfe240_0000e2ab\n"
        "xorl %eax, %eax\n" /* line 3482 */
        "jmp .Lfe240_0000e28c\n"
        ".Lfe240_0000e2c8:\n"
        "cmpl $0x15, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        "movl $0x8876086a, %eax\n"
        "jmp .Lfe240_0000e2b0\n"
        ".Lfe240_0000e2d5:\n"
        "cmpl $1, 0x18(%ebp)\n" /* line 3476 | Usage */
        "je .Lfe240_0000e284\n"
        "movl $0x8876086a, %eax\n" /* line 3482 */
        "jmp .Lfe240_0000e2b0\n"
        ".Lfe240_0000e2e2:\n"
        "cmpl $0x20, %eax\n" /* line 3458 */
        "jne .Lfe240_0000e2ab\n"
        "cmpl $0x50, 0x20(%ebp)\n" /* line 3460 | CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x49, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x47, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        "cmpl $0x4b, 0x20(%ebp)\n" /* CheckFormat */
        "je .Lfe240_0000e28a\n"
        "movl $0x8876086a, %eax\n" /* line 3482 */
        "jmp .Lfe240_0000e2b0\n"
    );
}

/* line 3494 */
__attribute__((naked))
HRESULT CDirect3D_CheckDeviceMultiSampleType(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD *pQualityLevels)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3494 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 0x1c(%ebp), %ebx\n" /* MultiSampleType */
        /* { scope 1 */
        "leal -0xb(%ebp), %eax\n" /* line 3513 | DoesAlphaSampling */
        "movl %eax, 0x10(%esp)\n"
        "leal -0xa(%ebp), %eax\n" /* DoesMultiSampling */
        "movl %eax, 0xc(%esp)\n"
        "leal -9(%ebp), %eax\n" /* DoesSuperSampling */
        "movl %eax, 8(%esp)\n"
        "leal -0x14(%ebp), %eax\n" /* MaxSamples */
        "movl %eax, 4(%esp)\n"
        "leal -0x10(%ebp), %eax\n" /* MaxSampleBuffers */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetAntiAliasingMultiSampleInfo\n"
        "testl %ebx, %ebx\n" /* line 3515 | MultiSampleType */
        "jne .Lfe306_0000e346\n"
        ".Lfe306_0000e33b:\n"
        "movl $0x8876086a, %eax\n" /* line 3523 */
        /* } scope */
        ".Lfe306_0000e340:\n"
        "addl $0x34, %esp\n" /* line 3531 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe306_0000e346:\n"
        "movl 0x18(%ebp), %eax\n" /* line 3518 | Windowed */
        "testl %eax, %eax\n"
        "jne .Lfe306_0000e33b\n"
        "cmpb $0, -9(%ebp)\n" /* DoesSuperSampling */
        "je .Lfe306_0000e33b\n"
        "cmpl -0x14(%ebp), %ebx\n" /* MaxSamples, MultiSampleType */
        "ja .Lfe306_0000e33b\n"
        "movl 0x20(%ebp), %ebx\n" /* line 3520 | pQualityLevels, MultiSampleType */
        "testl %ebx, %ebx\n" /* MultiSampleType */
        "je .Lfe306_0000e368\n"
        "movl 0x20(%ebp), %eax\n" /* line 3523 | pQualityLevels */
        "movl $1, (%eax)\n"
        ".Lfe306_0000e368:\n"
        "xorl %eax, %eax\n"
        "jmp .Lfe306_0000e340\n"
    );
}

/* line 3542 */
__attribute__((naked))
HRESULT CDirect3D_CheckDepthStencilMatch(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3542 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 3546 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3556 */
__attribute__((naked))
HRESULT CDirect3D_GetDeviceCaps(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9 *pCaps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3556 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x34, %esp\n"
        "movl 0x14(%ebp), %ebx\n" /* pCaps */
        "movl $0x130, 8(%esp)\n" /* line 3575 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pCaps */
        "calll memset\n"
        "movl $1, (%ebx)\n" /* line 3579 | pCaps */
        "movl 0xc(%ebp), %eax\n" /* line 3580 | Adapter */
        "movl %eax, 4(%ebx)\n" /* pCaps */
        "movl $0, 8(%ebx)\n" /* line 3583 | pCaps */
        "movl $0x30020000, 0xc(%ebx)\n" /* line 3589 | pCaps */
        "movl $0x120, 0x10(%ebx)\n" /* line 3593 | pCaps */
        "movl $0x80000001, 0x14(%ebx)\n" /* line 3598 | pCaps */
        "movl $1, 0x18(%ebx)\n" /* line 3601 | pCaps */
        "movl $0x19bfc0, 0x1c(%ebx)\n" /* line 3617 | pCaps */
        "movl $0xcaf2, 0x20(%ebx)\n" /* line 3630 | pCaps */
        "calll MacDisplay_GetSupportsSeparateBlendFunc\n" /* line 3633 */
        "testb %al, %al\n"
        "je .Lfe374_0000e3e3\n"
        "orl $0x20000, 0x20(%ebx)\n" /* line 3635 | pCaps */
        ".Lfe374_0000e3e3:\n"
        "movl $0x7622081, 0x24(%ebx)\n" /* line 3654 | pCaps */
        "movl $0xff, 0x28(%ebx)\n" /* line 3664 | pCaps */
        "movl $0x7ff, 0x2c(%ebx)\n" /* line 3678 | pCaps */
        "movl $0x7ff, 0x30(%ebx)\n" /* line 3697 | pCaps */
        "movl $0xff, 0x34(%ebx)\n" /* line 3707 | pCaps */
        "movl $0x84208, 0x38(%ebx)\n" /* line 3713 | pCaps */
        "movl $0x234d07, 0x3c(%ebx)\n" /* line 3730 | pCaps */
        "movl $0x3030300, 0x40(%ebx)\n" /* line 3735 | pCaps */
        "movl $0x3030300, 0x44(%ebx)\n" /* line 3740 | pCaps */
        "calll MacDisplay_GetSupportsAnisotropicFiltering\n" /* line 3743 */
        "testb %al, %al\n"
        "je .Lfe374_0000e439\n"
        "orl $0x4000400, 0x40(%ebx)\n" /* line 3745 | pCaps */
        "orl $0x4000400, 0x44(%ebx)\n" /* line 3746 | pCaps */
        ".Lfe374_0000e439:\n"
        "movl $0, 0x48(%ebx)\n" /* line 3753 | pCaps */
        "movl $0xd, 0x4c(%ebx)\n" /* line 3758 | pCaps */
        "movl $0, 0x50(%ebx)\n" /* line 3762 | pCaps */
        "movl $0, 0x54(%ebx)\n" /* line 3766 | pCaps */
        "movl $0x800, 0x58(%ebx)\n" /* line 3772 | pCaps */
        "movl $0x800, 0x5c(%ebx)\n" /* line 3773 | pCaps */
        "movl $0, 0x60(%ebx)\n" /* line 3775 | pCaps */
        "movl $0, 0x64(%ebx)\n" /* line 3779 | pCaps */
        "movl $0x800, 0x68(%ebx)\n" /* line 3781 | pCaps */
        "calll MacDisplay_GetSupportsAnisotropicFiltering\n" /* line 3786 */
        "testb %al, %al\n"
        "jne .Lfe374_0000e5d7\n"
        ".Lfe374_0000e485:\n"
        "xorl %eax, %eax\n" /* line 3794 */
        "movl %eax, 0x70(%ebx)\n" /* pCaps */
        "movl %eax, 0x74(%ebx)\n" /* line 3798 | pCaps */
        "movl %eax, 0x78(%ebx)\n" /* line 3799 | pCaps */
        "movl %eax, 0x7c(%ebx)\n" /* line 3800 | pCaps */
        "movl %eax, 0x80(%ebx)\n" /* line 3801 | pCaps */
        "movl %eax, 0x84(%ebx)\n" /* line 3803 | pCaps */
        "movl $0xff, 0x88(%ebx)\n" /* line 3814 | pCaps */
        "movl $0, 0x8c(%ebx)\n" /* line 3820 | pCaps */
        "movl $0x3feffff, 0x90(%ebx)\n" /* line 3855 | pCaps */
        "movl $0x3b, 0x9c(%ebx)\n" /* line 3863 | pCaps */
        "movl $8, 0xa0(%ebx)\n" /* line 3867 | pCaps */
        "movl $0, 0xa4(%ebx)\n" /* line 3869 | pCaps */
        "movl $0, 0xa8(%ebx)\n" /* line 3872 | pCaps */
        "movl $0, 0xac(%ebx)\n" /* line 3873 | pCaps */
        "movl $0xffff, 0xb4(%ebx)\n" /* line 3875 | pCaps */
        "movl $0xffff, 0xb8(%ebx)\n" /* line 3876 | pCaps */
        "movl $0x10, 0xbc(%ebx)\n" /* line 3878 | pCaps */
        "movl $0x400, 0xc0(%ebx)\n" /* line 3879 | pCaps */
        "movl $0x3f800000, 0xb0(%ebx)\n" /* line 3882 | pCaps */
        "movl $0xfffe0200, 0xc4(%ebx)\n" /* line 3885 | pCaps */
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 3886 */
        "movl %eax, 0xcc(%ebx)\n" /* pCaps */
        "movl $0x100, 0xc8(%ebx)\n" /* line 3887 | pCaps */
        "movl $0x41000000, 0xd0(%ebx)\n" /* line 3888 | pCaps */
        "calll MacDisplay_GetMaxTextureImageUnits\n" /* line 3894 */
        "movl %eax, -0x10(%ebp)\n" /* __b */
        "calll MacDisplay_GetMaxTextureUnits\n"
        "movl %eax, -0xc(%ebp)\n" /* __b */
        /* { scope 1 */
        "cmpl -0x10(%ebp), %eax\n" /* line 211 */
        "jge .Lfe374_0000e5d2\n"
        "leal -0x10(%ebp), %eax\n"
        /* } scope */
        ".Lfe374_0000e562:\n"
        "movl (%eax), %eax\n" /* line 3894 | __b */
        "movl %eax, 0x98(%ebx)\n" /* __b, pCaps */
        "movl %eax, 0x94(%ebx)\n" /* __b, pCaps */
        "movl $1, 0xd4(%ebx)\n" /* line 3903 | pCaps */
        "movl $0, 0xd8(%ebx)\n" /* line 3904 | pCaps */
        "movl $0, 0xec(%ebx)\n" /* line 3905 | pCaps */
        "movl $1, 0xf0(%ebx)\n" /* line 3906 | pCaps */
        "movl $0x200, 0xf4(%ebx)\n" /* line 3908 | pCaps */
        "movl $0, 0x11c(%ebx)\n" /* line 3929 | pCaps */
        "movl $0, 0x120(%ebx)\n" /* line 3930 | pCaps */
        "movl $0, 0x124(%ebx)\n" /* line 3931 | pCaps */
        "movl $0, 0x128(%ebx)\n" /* line 3932 | pCaps */
        "xorl %eax, %eax\n" /* line 3935 */
        "addl $0x34, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe374_0000e5d2:\n"
        "leal -0xc(%ebp), %eax\n" /* line 211 */
        "jmp .Lfe374_0000e562\n"
        /* } scope */
        ".Lfe374_0000e5d7:\n"
        "calll MacDisplay_GetMaxSupportedAnisotropy\n" /* line 3788 */
        "fnstcw -0x1a(%ebp)\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x1c(%ebp)\n"
        "fldcw -0x1c(%ebp)\n"
        "fistpll -0x28(%ebp)\n"
        "fldcw -0x1a(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x6c(%ebx)\n" /* pCaps */
        "jmp .Lfe374_0000e485\n"
    );
}

/* line 3947 */
__attribute__((naked))
HRESULT CDirect3D_CreateDevice(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS *pPresentationParameters, HRESULT (*ppReturnedDeviceInterface)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3947 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x1bcc, (%esp)\n" /* line 3956 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x1c(%ebp), %eax\n" /* pPresentationParameters */
        "movl %eax, 0x10(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 8(%eax), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* DeviceType */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Adapter */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DDevice_CDirect3DDevice\n"
        "movl 0x20(%ebp), %eax\n" /* ppReturnedDeviceInterface */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 3959 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 3956 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 499 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetDepthStencilSurface(const CDirect3DDevice * _this, IDirect3DSurface9 *pNewZStencil)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* pNewZStencil */
        "testl %esi, %esi\n" /* line 501 | pNewZStencil */
        "je .Lfe65c_0000e6ce\n"
        "movl 0x18(%ebx), %edx\n" /* line 529 | this */
        "testl %edx, %edx\n"
        "je .Lfe65c_0000e691\n"
        ".Lfe65c_0000e675:\n"
        "movl (%edx), %eax\n" /* line 552 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lfe65c_0000e67d:\n"
        "movl %esi, 0x18(%ebx)\n" /* line 554 | pNewZStencil, this */
        "movl (%esi), %eax\n" /* line 557 | pNewZStencil */
        "movl %esi, (%esp)\n" /* pNewZStencil */
        "calll *4(%eax)\n"
        "xorl %eax, %eax\n" /* line 562 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe65c_0000e691:\n"
        "movl 0x544(%ebx), %eax\n" /* line 532 | this */
        "testl %eax, %eax\n"
        "jne .Lfe65c_0000e771\n"
        ".Lfe65c_0000e69f:\n"
        "movl 0x53c(%ebx), %eax\n" /* line 536 | this */
        "testl %eax, %eax\n"
        "jne .Lfe65c_0000e760\n"
        ".Lfe65c_0000e6ad:\n"
        "movl 0x574(%ebx), %eax\n" /* line 540 | this */
        "testl %eax, %eax\n"
        "jne .Lfe65c_0000e74e\n"
        ".Lfe65c_0000e6bb:\n"
        "movl 0x554(%ebx), %eax\n" /* line 544 | this */
        "testl %eax, %eax\n"
        "jne .Lfe65c_0000e728\n"
        ".Lfe65c_0000e6c5:\n"
        "movl 0x18(%ebx), %edx\n" /* line 550 | this */
        "testl %edx, %edx\n"
        "jne .Lfe65c_0000e675\n"
        "jmp .Lfe65c_0000e67d\n"
        ".Lfe65c_0000e6ce:\n"
        "movl 0x18(%ebx), %esi\n" /* line 504 | this, pNewZStencil */
        "testl %esi, %esi\n" /* pNewZStencil */
        "je .Lfe65c_0000e718\n"
        "movl 0x544(%ebx), %ecx\n" /* line 506 | this */
        "testl %ecx, %ecx\n"
        "jne .Lfe65c_0000e782\n"
        ".Lfe65c_0000e6e3:\n"
        "movl 0x53c(%ebx), %edx\n" /* line 510 | this */
        "testl %edx, %edx\n"
        "jne .Lfe65c_0000e7ca\n"
        ".Lfe65c_0000e6f1:\n"
        "movl 0x574(%ebx), %eax\n" /* line 514 | this */
        "testl %eax, %eax\n"
        "jne .Lfe65c_0000e7b9\n"
        ".Lfe65c_0000e6ff:\n"
        "movl 0x554(%ebx), %eax\n" /* line 518 | this */
        "testl %eax, %eax\n"
        "jne .Lfe65c_0000e793\n"
        ".Lfe65c_0000e70d:\n"
        "movl 0x18(%ebx), %eax\n" /* line 523 | this */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        ".Lfe65c_0000e718:\n"
        "movl $0, 0x18(%ebx)\n" /* line 525 | this */
        "xorl %eax, %eax\n" /* line 562 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe65c_0000e728:\n"
        "movl $0, 4(%esp)\n" /* line 546 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0xb90, (%esp)\n" /* line 547 */
        "calll glEnable\n"
        "jmp .Lfe65c_0000e6c5\n"
        ".Lfe65c_0000e74e:\n"
        "andl $0xff, %eax\n" /* line 542 */
        "movl %eax, (%esp)\n"
        "calll glStencilMask\n"
        "jmp .Lfe65c_0000e6bb\n"
        ".Lfe65c_0000e760:\n"
        "movl $0xb71, (%esp)\n" /* line 538 */
        "calll glEnable\n"
        "jmp .Lfe65c_0000e6ad\n"
        ".Lfe65c_0000e771:\n"
        "movl $1, (%esp)\n" /* line 534 */
        "calll glDepthMask\n"
        "jmp .Lfe65c_0000e69f\n"
        ".Lfe65c_0000e782:\n"
        "movl $0, (%esp)\n" /* line 508 */
        "calll glDepthMask\n"
        "jmp .Lfe65c_0000e6e3\n"
        ".Lfe65c_0000e793:\n"
        "movl $0, 4(%esp)\n" /* line 520 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0xb90, (%esp)\n" /* line 521 */
        "calll glDisable\n"
        "jmp .Lfe65c_0000e70d\n"
        ".Lfe65c_0000e7b9:\n"
        "movl $0, (%esp)\n" /* line 516 */
        "calll glStencilMask\n"
        "jmp .Lfe65c_0000e6ff\n"
        ".Lfe65c_0000e7ca:\n"
        "movl $0xb71, (%esp)\n" /* line 512 */
        "calll glDisable\n"
        "jmp .Lfe65c_0000e6f1\n"
    );
}

/* line 2422 */
__attribute__((naked))
void CDirect3DDevice_CreateAndSetGenericProgrammableVAO(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2422 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        /* { scope 1: i */
        "movl imp___ZN10CVAOPacket14sCurrentPacketE, %eax\n" /* line 58 */
        "movl (%eax), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %esi\n"
        "shll $4, %esi\n"
        "addl imp___ZN10CVAOPacket14sGenericPacketE, %esi\n"
        "movl %esi, g_CurrentGenericPacket\n" /* line 2429 */
        "movl $0, 4(%esp)\n" /* line 2433 */
        "movl $0, (%esp)\n"
        "calll CVAOPacket_SetGenericVAO\n"
        "movl 8(%ebp), %eax\n" /* line 2435 | this */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* pVB */
        "movl 8(%ebp), %edx\n" /* line 2439 | this */
        "movl 0xac(%edx), %ecx\n"
        "movl 0x14(%eax), %eax\n"
        "movl 8(%ebp), %edx\n" /* this */
        "addl 0x64(%edx), %eax\n"
        "movl %ecx, %edx\n"
        "imull g_Low, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* pVAStart */
        "movl %ecx, %edi\n" /* line 2440 | Size */
        "imull 0x10(%ebp), %edi\n" /* NumVertices, Size */
        "movl %eax, 8(%esi)\n" /* line 155 */
        "movl %edi, 0xc(%esi)\n"
        "movl %edi, 8(%esp)\n" /* line 2464 | Size */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* VType */
        "movl %ebx, (%esp)\n" /* VType */
        "calll COpenGL_SetVARInfo\n"
        "cmpb $0, 0x668(%ebx)\n" /* line 2466 | VType */
        "je .Lfe7dc_0000e888\n"
        "cmpb $0, g_special\n" /* line 2468 */
        "jne .Lfe7dc_0000e97c\n"
        "movl -0x24(%ebp), %eax\n" /* line 2474 | pVAStart */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* Size */
        "calll glFlushVertexArrayRangeAPPLE\n"
        ".Lfe7dc_0000e888:\n"
        "movl $0, -0x20(%ebp)\n" /* i */
        "leal 0x130(%esi), %edi\n" /* Size */
        "movl 8(%ebp), %esi\n" /* this */
        "addl $0xf0, %esi\n"
        "jmp .Lfe7dc_0000e91b\n"
        /* { scope 2: Stride */
        /* { scope 3 */
        /* { scope 4 */
        ".Lfe7dc_0000e8a0:\n"
        "movl 0xc(%esi), %eax\n" /* line 2293 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x24(%edx, %eax, 4), %eax\n"
        "movl 0x14(%eax), %edx\n"
        "addl 0x10(%esi), %edx\n"
        "movl -0x1c(%ebp), %eax\n" /* Stride */
        "imull 0xc(%ebp), %eax\n" /* StartVertex */
        "addl %eax, %edx\n"
        "movl 0x18(%esi), %ebx\n" /* line 63 */
        "movl 0x14(%esi), %eax\n" /* line 62 */
        "movzbl 0x1c(%esi), %ecx\n" /* line 167 */
        /* { scope 5 */
        "movb $1, 1(%edi)\n" /* line 60 */
        /* { scope 6 */
        "movl %eax, 4(%edi)\n" /* line 61 */
        /* } scope */
        /* { scope 6 */
        "movl %ebx, 8(%edi)\n" /* line 62 */
        /* } scope */
        "movb %cl, 0xc(%edi)\n" /* line 63 */
        "movl -0x1c(%ebp), %eax\n" /* line 64 | Stride */
        "movl %eax, 0x10(%edi)\n"
        "movl %edx, 0x14(%edi)\n" /* line 65 */
        /* } scope */
        "movl %edx, 0x18(%esp)\n" /* line 2495 */
        "movl %eax, 0x14(%esp)\n"
        "movzbl 0x1c(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x18(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* i */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetVertexProgramStreamInfo\n"
        /* } scope */
        /* } scope */
        "addl $1, -0x20(%ebp)\n" /* line 2483 | i */
        "addl $0x1c, %esi\n"
        "addl $0x18, %edi\n" /* Size */
        "cmpl $0x10, -0x20(%ebp)\n" /* i */
        "je .Lfe7dc_0000e974\n"
        /* { scope 3 */
        ".Lfe7dc_0000e91b:\n"
        "movl 0x20(%esi), %edx\n" /* line 2486 */
        "movl %edx, -0x1c(%ebp)\n" /* Stride */
        "cmpb $0, 8(%esi)\n" /* line 2488 */
        "jne .Lfe7dc_0000e8a0\n"
        "movl 0x18(%esi), %eax\n" /* line 63 */
        "movl 0x14(%esi), %edx\n" /* line 62 */
        "movzbl 0x1c(%esi), %ecx\n" /* line 167 */
        /* { scope 4 */
        "movb $0, 1(%edi)\n" /* line 60 */
        /* { scope 5 */
        "movl %edx, 4(%edi)\n" /* line 61 */
        /* } scope */
        /* { scope 5 */
        "movl %eax, 8(%edi)\n" /* line 62 */
        /* } scope */
        "movb %cl, 0xc(%edi)\n" /* line 63 */
        "movl -0x1c(%ebp), %edx\n" /* line 64 | Stride */
        "movl %edx, 0x10(%edi)\n"
        "movl $0, 0x14(%edi)\n" /* line 65 */
        /* } scope */
        "movl -0x20(%ebp), %eax\n" /* line 2500 | i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_DisableVertexProgramStream\n"
        /* } scope */
        "addl $1, -0x20(%ebp)\n" /* line 2483 | i */
        "addl $0x1c, %esi\n"
        "addl $0x18, %edi\n" /* Size */
        "cmpl $0x10, -0x20(%ebp)\n" /* i */
        "jne .Lfe7dc_0000e91b\n"
        /* } scope */
        /* } scope */
        ".Lfe7dc_0000e974:\n"
        "addl $0x3c, %esp\n" /* line 2503 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: i */
        ".Lfe7dc_0000e97c:\n"
        "movl -0x24(%ebp), %eax\n" /* line 128 | pVAStart */
        "addl %edi, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* pVAStart */
        "movl %eax, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n" /* pVB */
        "movl 0x38(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CStaticCacheInfo_Flush\n"
        "jmp .Lfe7dc_0000e888\n"
    );
}

/* line 832 */
__attribute__((naked))
void COpenGL_SetTexBorderColor(const COpenGL * _this, UINT32 Unit, GLenum Target, GLuint Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 832 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* Target */
        "movl 0x14(%ebp), %esi\n" /* Value */
        "leal (%edx, %edx, 8), %eax\n" /* line 654 */
        "leal (%edx, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "addl 0x65c(%ecx), %ebx\n"
        "cmpl $0xde1, %edi\n" /* line 87 */
        "je .Lfe9a0_0000e9e4\n"
        "cmpl $0x806f, %edi\n" /* line 91 */
        "je .Lfe9a0_0000eaef\n"
        "cmpl $0x8513, %edi\n" /* line 95 */
        "je .Lfe9a0_0000eaf9\n"
        ".Lfe9a0_0000e9e4:\n"
        "xorl %eax, %eax\n"
        ".Lfe9a0_0000e9e6:\n"
        "cmpl %esi, 0x34(%ebx, %eax, 4)\n" /* line 836 | Value */
        "je .Lfe9a0_0000eae7\n"
        "movl %edx, 4(%esp)\n" /* line 838 */
        "movl %ecx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        /* { scope 1 */
        "movl $0, -0x28(%ebp)\n" /* line 159 | rgba */
        "movl $0, -0x24(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n"
        "movl %esi, %edx\n"
        "shrl $0x10, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lfe9a0_0000eb0e\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* rgba */
        "movl %esi, %edx\n"
        "shrl $8, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lfe9a0_0000eb34\n"
        ".Lfe9a0_0000ea45:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl %esi, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lfe9a0_0000eb55\n"
        ".Lfe9a0_0000ea5b:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl %esi, %edx\n"
        "shrl $0x18, %edx\n"
        "js .Lfe9a0_0000eb76\n"
        ".Lfe9a0_0000ea6f:\n"
        "cvtsi2ssl %edx, %xmm2\n"
        ".Lfe9a0_0000ea73:\n"
        "movss lit4_002ed5cc, %xmm1\n" /* line 161 | 0.003921568859368563f */
        "movss -0x28(%ebp), %xmm0\n" /* rgba */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* rgba */
        "movss -0x24(%ebp), %xmm0\n" /* line 162 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n" /* line 163 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "mulss %xmm1, %xmm2\n" /* line 164 */
        "movss %xmm2, -0x1c(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 166 | rgba */
        "movl %eax, 8(%esp)\n"
        "movl $0x1004, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll glTexParameterfv\n"
        "cmpl $0xde1, %edi\n" /* line 87 */
        "je .Lfe9a0_0000eae1\n"
        "cmpl $0x806f, %edi\n" /* line 91 */
        "je .Lfe9a0_0000eb8d\n"
        "cmpl $0x8513, %edi\n" /* line 95 */
        "je .Lfe9a0_0000eb03\n"
        ".Lfe9a0_0000eae1:\n"
        "xorl %eax, %eax\n"
        "movl %esi, 0x34(%ebx, %eax, 4)\n" /* line 166 */
        /* } scope */
        ".Lfe9a0_0000eae7:\n"
        "addl $0x2c, %esp\n" /* line 841 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe9a0_0000eaef:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lfe9a0_0000e9e6\n"
        ".Lfe9a0_0000eaf9:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lfe9a0_0000e9e6\n"
        /* { scope 1 */
        ".Lfe9a0_0000eb03:\n"
        "movl $2, %eax\n"
        "movl %esi, 0x34(%ebx, %eax, 4)\n" /* line 166 */
        "jmp .Lfe9a0_0000eae7\n"
        ".Lfe9a0_0000eb0e:\n"
        "shrl $1, %eax\n" /* line 159 */
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* rgba */
        "movl %esi, %edx\n"
        "shrl $8, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "jns .Lfe9a0_0000ea45\n"
        ".Lfe9a0_0000eb34:\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -0x24(%ebp)\n"
        "movl %esi, %eax\n"
        "andl $0xff, %eax\n"
        "jns .Lfe9a0_0000ea5b\n"
        ".Lfe9a0_0000eb55:\n"
        "shrl $1, %eax\n"
        "movl %esi, %edx\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -0x20(%ebp)\n"
        "movl %esi, %edx\n"
        "shrl $0x18, %edx\n"
        "jns .Lfe9a0_0000ea6f\n"
        ".Lfe9a0_0000eb76:\n"
        "movl %esi, %eax\n"
        "shrl $0x19, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "addss %xmm2, %xmm2\n"
        "jmp .Lfe9a0_0000ea73\n"
        ".Lfe9a0_0000eb8d:\n"
        "movl $1, %eax\n" /* line 91 */
        "movl %esi, 0x34(%ebx, %eax, 4)\n" /* line 166 */
        "jmp .Lfe9a0_0000eae7\n"
    );
}

/* line 573 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetTexture(const CDirect3DDevice * _this, DWORD Stage, IDirect3DBaseTexture9 *pTexture)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 573 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* Stage */
        "movl 0x10(%ebp), %edi\n" /* pTexture */
        "leal 0x504(%esi), %eax\n" /* this */
        "leal 0x508(%esi), %ecx\n" /* this */
        /* { scope 1 */
        "movl 0x504(%esi), %edx\n" /* line 211 */
        "cmpl 0x508(%esi), %edx\n"
        "cmovbl %ecx, %eax\n"
        /* } scope */
        "cmpl %ebx, (%eax)\n" /* line 575 | Stage */
        "jbe .Lfeb9e_0000ec0d\n"
        "leal (%ebx, %ebx, 4), %eax\n" /* line 654 | Stage */
        "leal (%ebx, %eax, 8), %eax\n" /* Stage */
        "leal (, %eax, 4), %ebx\n" /* Stage */
        "addl 0x608(%esi), %ebx\n" /* this, Stage */
        "cmpl %edi, 4(%ebx)\n" /* line 581 | pTexture, Stage */
        "je .Lfeb9e_0000ec0d\n"
        /* { scope 1 */
        "movl 4(%ebx), %edx\n" /* line 103 */
        "testl %edx, %edx\n" /* line 584 */
        "je .Lfeb9e_0000ebf6\n"
        "movl (%edx), %eax\n" /* line 586 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lfeb9e_0000ebf6:\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "movl %edi, 4(%ebx)\n" /* line 128 */
        "testl %edi, %edi\n" /* line 593 | pTexture */
        "je .Lfeb9e_0000ec0d\n"
        "movl (%edi), %eax\n" /* line 595 | pTexture */
        "movl %edi, (%esp)\n" /* pTexture */
        "calll *4(%eax)\n"
        /* } scope */
        ".Lfeb9e_0000ec0d:\n"
        "xorl %eax, %eax\n" /* line 601 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2508 */
__attribute__((naked))
bool CDirect3DDevice_GetStreamPtrs(const CDirect3DDevice * _this, UINT32 StartVertex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2508 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $8, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* StartVertex */
        "movl 0x2c0(%ecx), %eax\n" /* line 2513 */
        "movl 0x24(%ecx, %eax, 4), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "addl 0x2c4(%ecx), %eax\n"
        "movl %ebx, %edx\n" /* StartVertex */
        "imull 0x2d0(%ecx), %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, 0x2bc(%ecx)\n"
        "cmpb $0, 0x2d4(%ecx)\n" /* line 2516 */
        "je .Lfec18_0000ecbb\n"
        "movl 0x584(%ecx), %eax\n" /* line 2518 */
        "testl %eax, %eax\n"
        "je .Lfec18_0000eca4\n"
        ".Lfec18_0000ec5e:\n"
        "movl 0x2dc(%ecx), %eax\n" /* line 2546 */
        "movl 0x24(%ecx, %eax, 4), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "addl 0x2e0(%ecx), %eax\n"
        "movl %ebx, %edx\n" /* StartVertex */
        "imull 0x2e8(%ecx), %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, 0x2d8(%ecx)\n"
        "movl $1, %edx\n"
        "cmpb $0, 0x2ec(%ecx)\n" /* line 2554 */
        "jne .Lfec18_0000ecc6\n"
        ".Lfec18_0000ec90:\n"
        "movl $0, 0x2f0(%ecx)\n" /* line 2560 */
        "movl %edx, %eax\n" /* line 2564 */
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfec18_0000eca4:\n"
        "movl 0x504(%ecx), %eax\n" /* line 2525 */
        "movl %eax, -0x14(%ebp)\n"
        "testl %eax, %eax\n"
        "jne .Lfec18_0000ecf2\n"
        /* } scope */
        ".Lfec18_0000ecb1:\n"
        "movl $0, 0x2d8(%ecx)\n" /* line 2550 */
        ".Lfec18_0000ecbb:\n"
        "xorl %edx, %edx\n"
        "cmpb $0, 0x2ec(%ecx)\n" /* line 2554 */
        "je .Lfec18_0000ec90\n"
        ".Lfec18_0000ecc6:\n"
        "movl 0x2f4(%ecx), %eax\n" /* line 2556 */
        "movl 0x24(%ecx, %eax, 4), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "addl 0x2f8(%ecx), %eax\n"
        "imull 0x304(%ecx), %ebx\n" /* StartVertex */
        "addl %ebx, %eax\n" /* StartVertex */
        "movl %eax, 0x2f0(%ecx)\n"
        "movl %edx, %eax\n" /* line 2564 */
        "addl $8, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfec18_0000ecf2:\n"
        "leal 0x608(%ecx), %eax\n" /* line 334 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 0x608(%ecx), %edx\n"
        "movl 0x50(%edx), %eax\n" /* line 2529 | Tci */
        "xorw %ax, %ax\n" /* Tci */
        "cmpl $0x10000, %eax\n" /* line 2531 */
        "je .Lfec18_0000ec5e\n"
        "cmpl $0x30000, %eax\n"
        "je .Lfec18_0000ec5e\n"
        "cmpl $1, 0x2c(%edx)\n" /* line 2537 */
        "je .Lfec18_0000ecb1\n"
        "xorl %esi, %esi\n" /* line 2539 | i */
        "movl $0xa4, %edx\n"
        /* } scope */
        ".Lfec18_0000ed2a:\n"
        "addl $1, %esi\n" /* line 2525 | i */
        "cmpl %esi, -0x14(%ebp)\n" /* i */
        "je .Lfec18_0000ecb1\n"
        /* { scope 2 */
        "movl %edx, %edi\n" /* line 654 */
        "movl -0x10(%ebp), %eax\n"
        "addl (%eax), %edi\n"
        "movl 0x50(%edi), %eax\n" /* line 2529 | Tci */
        "xorw %ax, %ax\n" /* Tci */
        "cmpl $0x10000, %eax\n" /* line 2531 */
        "je .Lfec18_0000ec5e\n"
        "cmpl $0x30000, %eax\n"
        "je .Lfec18_0000ec5e\n"
        "addl $0xa4, %edx\n"
        "cmpl $1, 0x2c(%edi)\n" /* line 2537 */
        "jne .Lfec18_0000ed2a\n"
        "jmp .Lfec18_0000ecb1\n"
    );
}

/* line 2569 */
__attribute__((naked))
bool CDirect3DDevice_GetCanUseVAOWithTexCoordStreams(const CDirect3DDevice * _this, int CanUseVAO)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2569 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movzbl 0xc(%ebp), %eax\n" /* CanUseVAO */
        "movb %al, -0x2d(%ebp)\n" /* CanUseVAO */
        /* { scope 1: UsesTexFactor */
        "movl 8(%ebp), %edx\n" /* line 2574 | this */
        "movl 0x504(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfed6a_0000ee1c\n"
        /* { scope 2 */
        "addl $0x608, %edx\n" /* line 334 */
        "movl %edx, -0x2c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x608(%edx), %eax\n"
        "movl %eax, %ebx\n" /* line 2576 | ts */
        "cmpl $1, 0x2c(%eax)\n" /* line 2578 */
        "je .Lfed6a_0000ee1c\n"
        "xorl %edi, %edi\n" /* line 2580 | i */
        "movl $0xa4, %esi\n"
        "jmp .Lfed6a_0000ee00\n"
        /* { scope 3 */
        ".Lfed6a_0000edae:\n"
        "movl 0x50(%ebx), %eax\n" /* line 117 */
        "movl %eax, %edx\n" /* line 2588 | Tci */
        "xorw %dx, %dx\n" /* Tci */
        "cmpl $0x10000, %edx\n" /* line 2589 */
        "je .Lfed6a_0000ee28\n"
        "cmpl $0x30000, %edx\n"
        "je .Lfed6a_0000ee28\n"
        "cmpl $0x40000, %edx\n"
        "je .Lfed6a_0000ee28\n"
        "andl $0xffff, %eax\n" /* line 2596 */
        "movl 8(%ebp), %edx\n" /* this */
        "cmpb $0, 0x308(%eax, %edx)\n"
        "je .Lfed6a_0000ee28\n"
        "movl %edx, %eax\n"
        /* } scope */
        /* } scope */
        ".Lfed6a_0000ede2:\n"
        "addl $1, %edi\n" /* line 2574 | i */
        "cmpl %edi, 0x504(%eax)\n" /* i */
        "jbe .Lfed6a_0000ee1c\n"
        /* { scope 2 */
        "movl %esi, %ebx\n" /* line 2576 | ts */
        "movl -0x2c(%ebp), %eax\n"
        "addl (%eax), %ebx\n" /* ts */
        "addl $0xa4, %esi\n"
        "cmpl $1, 0x2c(%ebx)\n" /* line 2578 | ts */
        "je .Lfed6a_0000ee1c\n"
        ".Lfed6a_0000ee00:\n"
        "movb $0, -0x19(%ebp)\n" /* line 2583 | UsesTexFactor */
        "leal -0x19(%ebp), %edx\n" /* line 2584 | UsesTexFactor */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ts */
        "calll CDirect3DDevice_CTexStage_GetUsesTexture\n"
        "testb %al, %al\n" /* line 2586 */
        "jne .Lfed6a_0000edae\n"
        "movl 8(%ebp), %eax\n" /* this */
        "jmp .Lfed6a_0000ede2\n"
        /* } scope */
        /* } scope */
        ".Lfed6a_0000ee1c:\n"
        "movzbl -0x2d(%ebp), %eax\n" /* line 2604 | CanUseVAO */
        ".Lfed6a_0000ee20:\n"
        "addl $0x3c, %esp\n" /* line 2605 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfed6a_0000ee28:\n"
        "xorl %eax, %eax\n" /* line 2604 */
        "jmp .Lfed6a_0000ee20\n"
    );
}

/* line 2917 */
__attribute__((naked))
void CDirect3DDevice_CreateAndSetGenericFixedFunctionVAO(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices, int NeedsNormals)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2917 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movzbl 0x1c(%ebp), %eax\n" /* NeedsNormals */
        "movb %al, -0x25(%ebp)\n" /* NeedsNormals */
        /* { scope 1 */
        "movl imp___ZN10CVAOPacket14sCurrentPacketE, %eax\n" /* line 58 */
        "movl (%eax), %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "leal (%edx, %eax, 2), %eax\n"
        "shll $4, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl imp___ZN10CVAOPacket14sGenericPacketE, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, g_CurrentGenericPacket\n" /* line 2926 */
        "movl 0x24(%esi), %eax\n" /* line 2930 | this */
        "movl %eax, -0x20(%ebp)\n" /* pVB */
        "movl 0xac(%esi), %ecx\n" /* line 2934 | this */
        "movl 0x14(%eax), %eax\n"
        "addl 0x64(%esi), %eax\n" /* this */
        "movl %ecx, %edx\n"
        "imull g_Low, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, -0x1c(%ebp)\n" /* pVAStart */
        "movl %ecx, %edi\n" /* line 2935 | Size */
        "imull 0x10(%ebp), %edi\n" /* NumVertices, Size */
        "movl $0, 4(%esp)\n" /* line 2950 */
        "movl $1, (%esp)\n"
        "calll CVAOPacket_SetGenericVAO\n"
        "movl -0x1c(%ebp), %edx\n" /* line 155 | pVAStart */
        "movl -0x24(%ebp), %eax\n"
        "movl %edx, 8(%eax)\n"
        "movl %edi, 0xc(%eax)\n"
        "movl %edi, 8(%esp)\n" /* line 2959 | Size */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGL_SetVARInfo\n"
        "cmpb $0, 0x668(%ebx)\n" /* line 2962 */
        "je .Lfee2c_0000eee6\n"
        "cmpb $0, g_special\n" /* line 2964 */
        "jne .Lfee2c_0000f0dc\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2970 | pVAStart */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* Size */
        "calll glFlushVertexArrayRangeAPPLE\n"
        ".Lfee2c_0000eee6:\n"
        "movl 0x2c8(%esi), %eax\n" /* line 159 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2bc(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2d0(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2cc(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "addl $0x58, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CVertexArray_SetGuard\n"
        "movl 0x2bc(%esi), %eax\n" /* line 2980 | this */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2d0(%esi), %eax\n" /* this */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2cc(%esi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 0x2c8(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGL_EnableVertexArray\n"
        "cmpb $0, -0x25(%ebp)\n" /* line 2986 | NeedsNormals */
        "je .Lfee2c_0000f041\n"
        "movl 0x2d8(%esi), %eax\n" /* line 160 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2e8(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2e4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "addl $0x40, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CNormalArray_SetGuard\n"
        "movl 0x2d8(%esi), %eax\n" /* line 2989 | this */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2e8(%esi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl 0x2e4(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGL_EnableNormalArray\n"
        "cmpb $0, 0x2ec(%esi)\n" /* line 2997 | this */
        "je .Lfee2c_0000f08a\n"
        ".Lfee2c_0000efcb:\n"
        "movl 0x2fc(%esi), %eax\n" /* line 161 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2f0(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x304(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x300(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CColorArray_SetGuard\n"
        "movl 0x2f0(%esi), %eax\n" /* line 3000 | this */
        "movl %eax, 0x18(%ebp)\n" /* NumIndices */
        "movl 0x304(%esi), %eax\n" /* this */
        "movl %eax, 0x14(%ebp)\n" /* pIndices */
        "movl 0x300(%esi), %eax\n" /* this */
        "movl %eax, 0x10(%ebp)\n" /* NumVertices */
        "movl 0x2fc(%esi), %eax\n" /* this */
        "movl %eax, 0xc(%ebp)\n" /* StartVertex */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3009 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp COpenGL_EnableColorArray\n" /* line 3000 */
        ".Lfee2c_0000f041:\n"
        "movl 0x2d8(%esi), %eax\n" /* line 160 */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2e8(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2e4(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "addl $0x40, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CNormalArray_SetGuard\n"
        "movl %ebx, (%esp)\n" /* line 2994 */
        "calll COpenGL_DisableNormalArray\n"
        "cmpb $0, 0x2ec(%esi)\n" /* line 2997 | this */
        "jne .Lfee2c_0000efcb\n"
        ".Lfee2c_0000f08a:\n"
        "movl 0x2fc(%esi), %eax\n" /* line 161 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2f0(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x304(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x300(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl -0x24(%ebp), %eax\n"
        "addl $0x10, %eax\n"
        "movl %eax, (%esp)\n"
        "calll CColorArray_SetGuard\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 3005 */
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3009 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp COpenGL_DisableColorArray\n" /* line 3005 */
        ".Lfee2c_0000f0dc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 128 | pVAStart */
        "addl %edi, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* pVAStart */
        "movl %eax, 4(%esp)\n"
        "movl -0x20(%ebp), %edx\n" /* pVB */
        "movl 0x38(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CStaticCacheInfo_Flush\n"
        "jmp .Lfee2c_0000eee6\n"
    );
}

/* line 606 */
__attribute__((naked))
void CDirect3DDevice_ValidateLighting(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 606 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 612 */
        "cmpb $0, 0x800(%eax)\n"
        "jne .Lff100_0000f25c\n"
        "movl 8(%ebp), %edx\n" /* line 617 | this */
        "movl 0x584(%edx), %ebx\n"
        "testl %ebx, %ebx\n"
        "je .Lff100_0000f28b\n"
        "movl 0x52c(%edx), %ecx\n" /* line 641 */
        "testl %ecx, %ecx\n"
        "je .Lff100_0000f146\n"
        "cmpb $0, 0x2ec(%edx)\n"
        "jne .Lff100_0000f296\n"
        ".Lff100_0000f146:\n"
        "movl $0, 4(%esp)\n" /* line 648 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        /* { scope 1: LightDirection, b */
        ".Lff100_0000f156:\n"
        "movl 8(%ebp), %ebx\n" /* line 675 | this, pLI */
        "addl $0x614, %ebx\n" /* pLI */
        "movb $0, -0xb9(%ebp)\n" /* LightingMatrixCalculated */
        "movl $0x4000, %edi\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "addl $0x78, %eax\n"
        "movl %eax, -0xc0(%ebp)\n"
        "jmp .Lff100_0000f1c0\n"
        ".Lff100_0000f17b:\n"
        "leal -0x78(%ebp), %esi\n" /* lm */
        /* { scope 2: InvModelView */
        ".Lff100_0000f17e:\n"
        "movl %esi, 8(%esp)\n" /* line 700 */
        "leal -0x28(%ebp), %eax\n" /* LightDirection */
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* b */
        "movl %edx, (%esp)\n"
        "calll D3DXVec4Transform\n"
        "leal -0x38(%ebp), %eax\n" /* line 702 | b */
        "movl %eax, 8(%esp)\n"
        "movl $0x1203, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll glLightfv\n"
        /* } scope */
        ".Lff100_0000f1ab:\n"
        "addl $0xb4, %ebx\n" /* line 679 | pLI */
        "addl $1, %edi\n"
        "cmpl $0x4008, %edi\n"
        "je .Lff100_0000f28b\n"
        ".Lff100_0000f1c0:\n"
        "cmpb $0, (%ebx)\n" /* line 683 | pLI */
        "je .Lff100_0000f1ab\n"
        /* { scope 2: InvModelView */
        "leal 0x3c(%ebx), %eax\n" /* line 687 | pLI */
        "movss 8(%eax), %xmm2\n"
        "xorps 0x2ede40, %xmm2\n"
        "movss 4(%eax), %xmm1\n"
        "xorps 0x2ede40, %xmm1\n"
        "movss 0x3c(%ebx), %xmm0\n" /* line 64 */
        "xorps 0x2ede40, %xmm0\n"
        "movss %xmm0, -0x28(%ebp)\n" /* LightDirection */
        "movss %xmm1, -0x24(%ebp)\n"
        "movss %xmm2, -0x20(%ebp)\n"
        "movl $0, -0x1c(%ebp)\n"
        "cmpb $0, -0xb9(%ebp)\n" /* line 689 | LightingMatrixCalculated */
        "jne .Lff100_0000f17b\n"
        /* { scope 3 */
        "movl -0xc0(%ebp), %edx\n" /* line 694 */
        "movl %edx, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0xb8(%ebp), %eax\n" /* InvModelView */
        "movl %eax, (%esp)\n"
        "calll D3DXMatrixInverse\n"
        "leal -0xb8(%ebp), %edx\n" /* line 696 | InvModelView */
        "movl %edx, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x474, %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x78(%ebp), %esi\n" /* lm */
        "movl %esi, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        "movb $1, -0xb9(%ebp)\n" /* LightingMatrixCalculated */
        "jmp .Lff100_0000f17e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lff100_0000f25c:\n"
        "movl 8(%ebp), %edx\n" /* line 764 | this */
        "movl 0x584(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lff100_0000f28b\n"
        "cmpb $0, 0x2ec(%edx)\n" /* line 766 */
        "jne .Lff100_0000f28b\n"
        "movl $0x3f800000, %eax\n" /* line 768 */
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glColor4f\n"
        ".Lff100_0000f28b:\n"
        "addl $0xcc, %esp\n" /* line 777 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff100_0000f296:\n"
        "movl $1, 4(%esp)\n" /* line 644 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lff100_0000f156\n"
    );
}

/* line 318 */
__attribute__((naked))
void COpenGL_SetTex(const COpenGL * _this, UINT32 Unit, GLenum Target, const COpenGLTexture * pOpenGLTexInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 318 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Unit */
        "movl 0x10(%ebp), %esi\n" /* Target */
        "movl 0x14(%ebp), %eax\n" /* pOpenGLTexInfo */
        "movl %eax, -0x1c(%ebp)\n" /* pOpenGLTexInfo */
        /* { scope 1 */
        "leal (%ecx, %ecx, 8), %eax\n" /* line 654 */
        "leal (%ecx, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "addl 0x65c(%edi), %ebx\n" /* this */
        "cmpl $0xde1, %esi\n" /* line 87 */
        "je .Lff2ac_0000f2f3\n"
        "cmpl $0x806f, %esi\n" /* line 91 */
        "je .Lff2ac_0000f385\n"
        "cmpl $0x8513, %esi\n" /* line 95 */
        "je .Lff2ac_0000f3b0\n"
        ".Lff2ac_0000f2f3:\n"
        "xorl %eax, %eax\n"
        ".Lff2ac_0000f2f5:\n"
        "movl 4(%ebx, %eax, 4), %eax\n" /* line 112 */
        "testl %eax, %eax\n" /* line 325 */
        "je .Lff2ac_0000f396\n"
        ".Lff2ac_0000f301:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 344 | pOpenGLTexInfo */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl (%eax), %eax\n"
        "cmpl (%edx), %eax\n"
        "setne %dl\n"
        ".Lff2ac_0000f311:\n"
        "cmpl $0xde1, %esi\n" /* line 350 | Target */
        "je .Lff2ac_0000f35f\n"
        "cmpl $0x806f, %esi\n" /* line 357 | Target */
        "je .Lff2ac_0000f378\n"
        "cmpl $0x8513, %esi\n" /* line 364 | Target */
        "je .Lff2ac_0000f3a0\n"
        ".Lff2ac_0000f329:\n"
        "xorl %eax, %eax\n" /* line 366 */
        ".Lff2ac_0000f32b:\n"
        "testb %dl, %dl\n" /* line 372 */
        "jne .Lff2ac_0000f333\n"
        "testb %al, %al\n"
        "je .Lff2ac_0000f357\n"
        ".Lff2ac_0000f333:\n"
        "movl %ecx, 4(%esp)\n" /* line 374 */
        "movl %edi, (%esp)\n" /* this */
        "calll COpenGL_SetActiveTexUnit\n"
        "movl -0x1c(%ebp), %eax\n" /* line 375 | pOpenGLTexInfo */
        "movl %eax, 0x10(%ebp)\n" /* Target */
        "movl %esi, 0xc(%ebp)\n" /* Target, Unit */
        "movl %ebx, 8(%ebp)\n" /* this */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp COpenGL_CTexUnit_SetTex\n" /* line 375 */
        /* } scope */
        ".Lff2ac_0000f357:\n"
        "addl $0x3c, %esp\n" /* line 379 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff2ac_0000f35f:\n"
        "cmpb $0, 1(%ebx)\n" /* line 352 */
        "je .Lff2ac_0000f371\n"
        "cmpb $0, 2(%ebx)\n"
        "jne .Lff2ac_0000f371\n"
        ".Lff2ac_0000f36b:\n"
        "cmpb $0, 3(%ebx)\n" /* line 359 */
        "je .Lff2ac_0000f329\n"
        ".Lff2ac_0000f371:\n"
        "movl $1, %eax\n" /* line 366 */
        "jmp .Lff2ac_0000f32b\n"
        ".Lff2ac_0000f378:\n"
        "cmpb $0, 2(%ebx)\n" /* line 359 */
        "jne .Lff2ac_0000f36b\n"
        "movl $1, %eax\n" /* line 366 */
        "jmp .Lff2ac_0000f32b\n"
        ".Lff2ac_0000f385:\n"
        "movl $1, %eax\n" /* line 91 */
        "movl 4(%ebx, %eax, 4), %eax\n" /* line 112 */
        "testl %eax, %eax\n" /* line 325 */
        "jne .Lff2ac_0000f301\n"
        ".Lff2ac_0000f396:\n"
        "movl $1, %edx\n"
        "jmp .Lff2ac_0000f311\n"
        ".Lff2ac_0000f3a0:\n"
        "cmpb $0, 3(%ebx)\n" /* line 366 */
        "jne .Lff2ac_0000f329\n"
        "movl $1, %eax\n"
        "jmp .Lff2ac_0000f32b\n"
        ".Lff2ac_0000f3b0:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lff2ac_0000f2f5\n"
    );
}

/* line 2149 */
__attribute__((naked))
void CDirect3DDevice_SetStream(const CDirect3DDevice * _this, bool *IsTexCoordStream, UINT32 ActiveStream, UINT32 VertexRegisterAddress, UINT32 Offset, UINT32 Stride, GLint VSize, GLenum VType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2149 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* VertexRegisterAddress */
        "cmpl $3, %eax\n" /* line 2151 */
        "je .Lff3ba_0000f446\n"
        "cmpl $5, %eax\n"
        "je .Lff3ba_0000f473\n"
        "testl %eax, %eax\n"
        "je .Lff3ba_0000f410\n"
        /* { scope 1 */
        "subl $8, %eax\n" /* line 2185 | ThisStreamID */
        "movb $1, 0x308(%eax, %edx)\n" /* line 2131 */
        "movl 0x10(%ebp), %ecx\n" /* line 2132 | ActiveStream */
        "movl %ecx, 0x310(%edx, %eax, 4)\n"
        "movl 0x18(%ebp), %ecx\n" /* line 2133 | Offset */
        "movl %ecx, 0x330(%edx, %eax, 4)\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 2134 | Stride */
        "movl %ecx, 0x370(%edx, %eax, 4)\n"
        "movl 0x20(%ebp), %ecx\n" /* line 2135 | VSize */
        "movl %ecx, 0x350(%edx, %eax, 4)\n"
        "movl 0xc(%ebp), %eax\n" /* line 2188 | IsTexCoordStream */
        "movb $1, (%eax)\n"
        /* } scope */
        "popl %ebp\n" /* line 2191 */
        "retl\n"
        ".Lff3ba_0000f410:\n"
        "movb $1, 0x2b8(%edx)\n" /* line 2076 */
        "movl 0x10(%ebp), %eax\n" /* line 2077 | ActiveStream */
        "movl %eax, 0x2c0(%edx)\n"
        "movl 0x18(%ebp), %ecx\n" /* line 2078 | Offset */
        "movl %ecx, 0x2c4(%edx)\n"
        "movl 0x1c(%ebp), %eax\n" /* line 2079 | Stride */
        "movl %eax, 0x2d0(%edx)\n"
        "movl 0x20(%ebp), %ecx\n" /* line 2080 | VSize */
        "movl %ecx, 0x2c8(%edx)\n"
        "movl 0x24(%ebp), %eax\n" /* line 2081 | VType */
        "movl %eax, 0x2cc(%edx)\n"
        "popl %ebp\n" /* line 2191 */
        "retl\n"
        ".Lff3ba_0000f446:\n"
        "movb $1, 0x2d4(%edx)\n" /* line 2094 */
        "movl 0x10(%ebp), %ecx\n" /* line 2095 | ActiveStream */
        "movl %ecx, 0x2dc(%edx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 2096 | Offset */
        "movl %eax, 0x2e0(%edx)\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 2097 | Stride */
        "movl %ecx, 0x2e8(%edx)\n"
        "movl 0x24(%ebp), %eax\n" /* line 2098 | VType */
        "movl %eax, 0x2e4(%edx)\n"
        "popl %ebp\n" /* line 2191 */
        "retl\n"
        ".Lff3ba_0000f473:\n"
        "movb $1, 0x2ec(%edx)\n" /* line 2112 */
        "movl 0x10(%ebp), %ecx\n" /* line 2113 | ActiveStream */
        "movl %ecx, 0x2f4(%edx)\n"
        "movl 0x18(%ebp), %eax\n" /* line 2114 | Offset */
        "movl %eax, 0x2f8(%edx)\n"
        "movl 0x1c(%ebp), %ecx\n" /* line 2115 | Stride */
        "movl %ecx, 0x304(%edx)\n"
        "movl 0x20(%ebp), %eax\n" /* line 2116 | VSize */
        "movl %eax, 0x2fc(%edx)\n"
        "movl 0x24(%ebp), %ecx\n" /* line 2117 | VType */
        "movl %ecx, 0x300(%edx)\n"
        "popl %ebp\n" /* line 2191 */
        "retl\n"
    );
}

/* line 2196 */
__attribute__((naked))
void CDirect3DDevice_ParseShaderDeclaration(const CDirect3DDevice * _this, int IsFixedFunction, bool *CanUseVAO)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2196 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movzbl 0xc(%ebp), %eax\n" /* IsFixedFunction */
        "movb %al, -0x3d(%ebp)\n" /* IsFixedFunction */
        /* { scope 1 */
        "movl 8(%ebp), %edi\n" /* line 2198 | this, pShaderDeclaration */
        "addl $0xbcc, %edi\n" /* pShaderDeclaration */
        "movl $0xffffffff, -0x3c(%ebp)\n" /* ActiveStream */
        "movl $0, -0x38(%ebp)\n" /* ActiveStreamOffset */
        "movl $0, -0x34(%ebp)\n" /* ActiveStreamStrideSize */
        /* { scope 2: VSize, VType, Normalized, ComponentSize, ... */
        ".Lff4aa_0000f4d8:\n"
        "movl (%edi), %edx\n" /* line 2206 | pShaderDeclaration, RawToken */
        "addl $4, %edi\n" /* pShaderDeclaration */
        "movl %edx, %eax\n" /* line 2209 */
        "shrl $0x1d, %eax\n"
        "cmpl $2, %eax\n"
        "je .Lff4aa_0000f51a\n"
        ".Lff4aa_0000f4e7:\n"
        "cmpl $7, %eax\n"
        "je .Lff4aa_0000f530\n"
        "subl $1, %eax\n"
        "jne .Lff4aa_0000f4d8\n"
        "andl $0xf, %edx\n" /* line 2218 */
        "movl %edx, -0x3c(%ebp)\n" /* ActiveStream */
        "movl 8(%ebp), %ecx\n" /* line 2220 | this */
        "movl 0xac(%ecx, %edx, 4), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n" /* ActiveStreamStrideSize */
        "movl $0, -0x38(%ebp)\n" /* ActiveStreamOffset */
        "movl (%edi), %edx\n" /* line 2206 | pShaderDeclaration, RawToken */
        "addl $4, %edi\n" /* pShaderDeclaration */
        "movl %edx, %eax\n" /* line 2209 */
        "shrl $0x1d, %eax\n"
        "cmpl $2, %eax\n"
        "jne .Lff4aa_0000f4e7\n"
        ".Lff4aa_0000f51a:\n"
        "testl $0x10000000, %edx\n" /* line 2224 */
        "je .Lff4aa_0000f538\n"
        "andl $0xf0000, %edx\n" /* line 2228 */
        "shrl $0x10, %edx\n"
        "addl %edx, -0x38(%ebp)\n" /* ActiveStreamOffset */
        "jmp .Lff4aa_0000f4d8\n"
        /* } scope */
        /* } scope */
        ".Lff4aa_0000f530:\n"
        "addl $0x5c, %esp\n" /* line 2285 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: VSize, VType, Normalized, ComponentSize, ... */
        /* { scope 3: VType, VSize */
        ".Lff4aa_0000f538:\n"
        "movl %edx, %esi\n" /* line 2235 | VertexRegisterAddress */
        "andl $0x1f, %esi\n" /* VertexRegisterAddress */
        "movb $0, -0x19(%ebp)\n" /* line 2239 | Normalized */
        "andl $0xf0000, %edx\n" /* line 2242 */
        "shrl $0x10, %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* Normalized */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* ComponentSize */
        "movl %eax, 8(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* VType */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* VSize */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetDeclarationInfo\n"
        "movb $0, -0x1a(%ebp)\n" /* line 2246 | IsTexCoordStream */
        "cmpb $0, -0x3d(%ebp)\n" /* line 2247 | IsFixedFunction */
        "jne .Lff4aa_0000f60e\n"
        "movl -0x24(%ebp), %eax\n" /* line 2254 | VType, this */
        "movl %eax, -0x30(%ebp)\n" /* this, VType */
        "movl -0x20(%ebp), %edx\n" /* VSize */
        "movl %edx, -0x2c(%ebp)\n" /* VSize */
        "movl -0x38(%ebp), %ebx\n" /* ActiveStreamOffset, StreamOffset */
        "movl -0x3c(%ebp), %ecx\n" /* ActiveStream */
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x64(%eax, %ecx, 4), %ebx\n" /* StreamOffset */
        "leal (, %esi, 4), %eax\n" /* this */
        "shll $5, %esi\n" /* VertexRegisterAddress */
        "subl %eax, %esi\n" /* this, VertexRegisterAddress */
        "movl 8(%ebp), %ecx\n" /* this */
        "leal 0xf0(%esi, %ecx), %edx\n" /* VertexRegisterAddress */
        "leal 8(%edx), %eax\n" /* this */
        "movzbl -0x19(%ebp), %ecx\n" /* Normalized */
        /* { scope 4 */
        "movb $1, 8(%edx)\n" /* line 48 */
        "movl -0x3c(%ebp), %edx\n" /* line 49 | ActiveStream */
        "movl %edx, 4(%eax)\n"
        "movl %ebx, 8(%eax)\n" /* line 50 */
        "movl -0x2c(%ebp), %edx\n" /* line 51 | VSize */
        "movl %edx, 0xc(%eax)\n"
        "movl -0x30(%ebp), %edx\n" /* line 52 | VType */
        "movl %edx, 0x10(%eax)\n"
        "movb %cl, 0x14(%eax)\n" /* line 53 */
        "movl -0x34(%ebp), %ecx\n" /* line 54 | ActiveStreamStrideSize */
        "movl %ecx, 0x18(%eax)\n"
        /* } scope */
        ".Lff4aa_0000f5d4:\n"
        "cmpb $0, -0x1a(%ebp)\n" /* line 2257 | IsTexCoordStream */
        "jne .Lff4aa_0000f5ea\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2260 | ActiveStream */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x24(%ecx, %edx, 4), %eax\n"
        "testb $2, 0x21(%eax)\n"
        "jne .Lff4aa_0000f5f9\n"
        ".Lff4aa_0000f5ea:\n"
        "movl -0x28(%ebp), %eax\n" /* line 2266 | ComponentSize */
        "imull -0x20(%ebp), %eax\n" /* VSize */
        "addl %eax, -0x38(%ebp)\n" /* ActiveStreamOffset */
        "jmp .Lff4aa_0000f4d8\n"
        ".Lff4aa_0000f5f9:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2262 | CanUseVAO */
        "movb $0, (%eax)\n"
        "movl -0x28(%ebp), %eax\n" /* line 2266 | ComponentSize */
        "imull -0x20(%ebp), %eax\n" /* VSize */
        "addl %eax, -0x38(%ebp)\n" /* ActiveStreamOffset */
        "jmp .Lff4aa_0000f4d8\n"
        ".Lff4aa_0000f60e:\n"
        "movl -0x24(%ebp), %eax\n" /* line 2249 | VType */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* VSize */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* ActiveStreamStrideSize */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x38(%ebp), %eax\n" /* ActiveStreamOffset */
        "movl -0x3c(%ebp), %edx\n" /* ActiveStream */
        "movl 8(%ebp), %ecx\n" /* this */
        "addl 0x64(%ecx, %edx, 4), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n" /* VertexRegisterAddress */
        "movl %edx, 8(%esp)\n"
        "leal -0x1a(%ebp), %eax\n" /* IsTexCoordStream */
        "movl %eax, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll CDirect3DDevice_SetStream\n"
        "jmp .Lff4aa_0000f5d4\n"
    );
}

/* line 51 */
__attribute__((naked))
void CDirect3DDevice_ValidateModelViewMatrix(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 51 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "cmpb $0, 0x4b4(%edx)\n" /* line 53 */
        "jne .Lff64e_0000f669\n"
        "addl $0x50, %esp\n" /* line 67 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lff64e_0000f669:\n"
        "movb $0, 0x4b4(%edx)\n" /* line 56 */
        "leal -0x48(%ebp), %esi\n" /* line 59 | ModelView */
        "leal 0x474(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal 0x3b0(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 427 */
        "cmpl $0x1700, 0x74(%ebx)\n"
        "je .Lff64e_0000f6b1\n"
        "movl $0x1700, 0x74(%ebx)\n" /* line 429 */
        "movl $0x1700, (%esp)\n" /* line 430 */
        "calll glMatrixMode\n"
        ".Lff64e_0000f6b1:\n"
        "movl -0x48(%ebp), %eax\n" /* line 437 | ModelView */
        "movl %eax, 0x78(%ebx)\n"
        "movl -0x44(%ebp), %eax\n"
        "movl %eax, 0x7c(%ebx)\n"
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x80(%ebx)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, 0x84(%ebx)\n"
        "movl -0x38(%ebp), %eax\n"
        "movl %eax, 0x88(%ebx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 0x8c(%ebx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x90(%ebx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0x94(%ebx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x98(%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 0x9c(%ebx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 0xa0(%ebx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xa4(%ebx)\n"
        "movl -0x18(%ebp), %eax\n"
        "movl %eax, 0xa8(%ebx)\n"
        "movl -0x14(%ebp), %eax\n"
        "movl %eax, 0xac(%ebx)\n"
        "movl -0x10(%ebp), %eax\n"
        "movl %eax, 0xb0(%ebx)\n"
        "movl -0xc(%ebp), %eax\n"
        "movl %eax, 0xb4(%ebx)\n"
        "movl %esi, (%esp)\n" /* line 438 */
        "calll glLoadMatrixf\n"
        /* } scope */
        "addl $0x50, %esp\n" /* line 67 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
    );
}

/* line 79 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetTransform(const CDirect3DDevice * _this, D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 79 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 0xc(%ebp), %edx\n" /* State */
        "movl 0x10(%ebp), %edi\n" /* pMatrix */
        "cmpl $0x100, %edx\n" /* line 87 */
        "je .Lff752_0000f824\n"
        "cmpl $2, %edx\n" /* line 100 */
        "je .Lff752_0000f8b9\n"
        "cmpl $3, %edx\n" /* line 116 */
        "je .Lff752_0000fa0b\n"
        "cmpl $0xf, %edx\n" /* line 141 */
        "jle .Lff752_0000f794\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x504(%ecx), %eax\n"
        "addl $0x10, %eax\n"
        "cmpl %eax, %edx\n"
        "jl .Lff752_0000f79e\n"
        ".Lff752_0000f794:\n"
        "xorl %eax, %eax\n" /* line 156 */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff752_0000f79e:\n"
        "subl $0x10, %edx\n" /* line 654 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl 0x608(%ecx), %eax\n"
        "leal 0x64(%eax), %edx\n" /* line 187 */
        "movl (%edi), %ecx\n" /* pMatrix */
        "movl %ecx, 0x64(%eax)\n"
        "movl 4(%edi), %eax\n" /* pMatrix */
        "movl %eax, 4(%edx)\n"
        "movl 8(%edi), %eax\n" /* pMatrix */
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x10(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x14(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x18(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x18(%edx)\n"
        "movl 0x1c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x1c(%edx)\n"
        "movl 0x20(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x20(%edx)\n"
        "movl 0x24(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x24(%edx)\n"
        "movl 0x28(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x28(%edx)\n"
        "movl 0x2c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x2c(%edx)\n"
        "movl 0x30(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x30(%edx)\n"
        "movl 0x34(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x34(%edx)\n"
        "movl 0x38(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x38(%edx)\n"
        "movl 0x3c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x3c(%edx)\n"
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %eax\n" /* line 646 */
        "movb $1, (%eax)\n"
        "xorl %eax, %eax\n" /* line 156 */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lff752_0000f824:\n"
        "movl 8(%ebp), %ebx\n" /* line 92 | this */
        "addl $0x3b0, %ebx\n"
        "movl %edi, 4(%esp)\n" /* pMatrix */
        "movl %ebx, (%esp)\n"
        "calll MacOpenGLUtils_AreMatricesDifferent4x4\n"
        "testb %al, %al\n"
        "je .Lff752_0000f794\n"
        "movl (%edi), %eax\n" /* line 106 | pMatrix */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x3b0(%edx)\n"
        "movl 4(%edi), %eax\n" /* pMatrix */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edi), %eax\n" /* pMatrix */
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x10(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x10(%ebx)\n"
        "movl 0x14(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x14(%ebx)\n"
        "movl 0x18(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x18(%ebx)\n"
        "movl 0x1c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x1c(%ebx)\n"
        "movl 0x20(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x20(%ebx)\n"
        "movl 0x24(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x24(%ebx)\n"
        "movl 0x28(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x28(%ebx)\n"
        "movl 0x2c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x2c(%ebx)\n"
        "movl 0x30(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x30(%ebx)\n"
        "movl 0x34(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x34(%ebx)\n"
        "movl 0x38(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x38(%ebx)\n"
        "movl 0x3c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x3c(%ebx)\n"
        "movb $1, 0x470(%edx)\n" /* line 97 */
        "movb $1, 0x4b4(%edx)\n" /* line 98 */
        "jmp .Lff752_0000f794\n"
        ".Lff752_0000f8b9:\n"
        "movl 8(%ebp), %ebx\n" /* line 105 | this */
        "addl $0x3f0, %ebx\n"
        "movl %edi, 4(%esp)\n" /* pMatrix */
        "movl %ebx, (%esp)\n"
        "calll MacOpenGLUtils_AreMatricesDifferent4x4\n"
        "testb %al, %al\n"
        "je .Lff752_0000f794\n"
        "movl (%edi), %eax\n" /* line 106 | pMatrix */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x3f0(%ecx)\n"
        "movl 4(%edi), %eax\n" /* pMatrix */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edi), %eax\n" /* pMatrix */
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x10(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x10(%ebx)\n"
        "movl 0x14(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x14(%ebx)\n"
        "movl 0x18(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x18(%ebx)\n"
        "movl 0x1c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x1c(%ebx)\n"
        "movl 0x20(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x20(%ebx)\n"
        "movl 0x24(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x24(%ebx)\n"
        "movl 0x28(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x28(%ebx)\n"
        "movl 0x2c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x2c(%ebx)\n"
        "movl 0x30(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x30(%ebx)\n"
        "movl 0x34(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x34(%ebx)\n"
        "movl 0x38(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x38(%ebx)\n"
        "movl 0x3c(%edi), %eax\n" /* pMatrix */
        "movl %eax, 0x3c(%ebx)\n"
        "movl %ecx, %eax\n" /* line 110 | this */
        "addl $0x474, %eax\n" /* this */
        /* { scope 1 */
        "movl (%edi), %edx\n" /* line 106 | pMatrix */
        "movl %edx, 0x474(%ecx)\n"
        "movl 4(%edi), %edx\n" /* pMatrix */
        "movl %edx, 4(%eax)\n"
        "movl 8(%edi), %edx\n" /* pMatrix */
        "movl %edx, 8(%eax)\n"
        "movl 0xc(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0xc(%eax)\n"
        "movl 0x10(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x10(%eax)\n"
        "movl 0x14(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x14(%eax)\n"
        "movl 0x18(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x18(%eax)\n"
        "movl 0x1c(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x1c(%eax)\n"
        "movl 0x20(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x20(%eax)\n"
        "movl 0x24(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x24(%eax)\n"
        "movl 0x28(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x28(%eax)\n"
        "movl 0x2c(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x2c(%eax)\n"
        "movl 0x30(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x30(%eax)\n"
        "movl 0x34(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x34(%eax)\n"
        "movl 0x38(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x38(%eax)\n"
        "movl 0x3c(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x3c(%eax)\n"
        /* } scope */
        "movb $1, 0x470(%ecx)\n" /* line 111 */
        "movss 0x2ede50, %xmm1\n" /* line 113 */
        "movss 0x47c(%ecx), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x47c(%ecx)\n"
        "movss 0x48c(%ecx), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x48c(%ecx)\n"
        "movss 0x49c(%ecx), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x49c(%ecx)\n"
        "movss 0x4ac(%ecx), %xmm0\n"
        "xorps %xmm1, %xmm0\n"
        "movss %xmm0, 0x4ac(%ecx)\n"
        "movb $1, 0x4b4(%ecx)\n" /* line 114 */
        "jmp .Lff752_0000f794\n"
        /* { scope 1 */
        ".Lff752_0000fa0b:\n"
        "movl 8(%ebp), %esi\n" /* line 123 | this */
        "addl $0x4b8, %esi\n"
        "movl %edi, 4(%esp)\n" /* pMatrix */
        "movl %esi, (%esp)\n"
        "calll MacOpenGLUtils_AreMatricesDifferent4x4\n"
        "testb %al, %al\n"
        "je .Lff752_0000f794\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 427 */
        "cmpl $0x1701, 0x74(%eax)\n"
        "je .Lff752_0000fa49\n"
        "movl $0x1701, 0x74(%eax)\n" /* line 429 */
        "movl $0x1701, (%esp)\n" /* line 430 */
        "calll glMatrixMode\n"
        ".Lff752_0000fa49:\n"
        "movl (%edi), %eax\n" /* line 106 | pMatrix */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, 0x4b8(%edx)\n"
        "movl 4(%edi), %ecx\n" /* pMatrix */
        "movl %ecx, -0x54(%ebp)\n"
        "movl %ecx, 4(%esi)\n"
        "movl 8(%edi), %eax\n" /* pMatrix */
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, 8(%esi)\n"
        "movl 0xc(%edi), %edx\n" /* pMatrix */
        "movl %edx, -0x4c(%ebp)\n"
        "movl %edx, 0xc(%esi)\n"
        "movl 0x10(%edi), %ecx\n" /* pMatrix */
        "movl %ecx, -0x48(%ebp)\n"
        "movl %ecx, 0x10(%esi)\n"
        "movl 0x14(%edi), %eax\n" /* pMatrix */
        "movl %eax, -0x44(%ebp)\n"
        "movl %eax, 0x14(%esi)\n"
        "movl 0x18(%edi), %edx\n" /* pMatrix */
        "movl %edx, -0x40(%ebp)\n"
        "movl %edx, 0x18(%esi)\n"
        "movl 0x1c(%edi), %ecx\n" /* pMatrix */
        "movl %ecx, -0x3c(%ebp)\n"
        "movl %ecx, 0x1c(%esi)\n"
        "movl 0x20(%edi), %eax\n" /* pMatrix */
        "movl %eax, -0x38(%ebp)\n"
        "movl %eax, 0x20(%esi)\n"
        "movl 0x24(%edi), %edx\n" /* pMatrix */
        "movl %edx, -0x34(%ebp)\n"
        "movl %edx, 0x24(%esi)\n"
        "movl 0x28(%edi), %ecx\n" /* pMatrix */
        "movl %ecx, -0x30(%ebp)\n"
        "movl %ecx, 0x28(%esi)\n"
        "movl 0x2c(%edi), %eax\n" /* pMatrix */
        "movl %eax, -0x2c(%ebp)\n"
        "movl %eax, 0x2c(%esi)\n"
        "movl 0x30(%edi), %edx\n" /* pMatrix */
        "movl %edx, -0x28(%ebp)\n"
        "movl %edx, 0x30(%esi)\n"
        "movl 0x34(%edi), %ebx\n" /* pMatrix */
        "movl %ebx, 0x34(%esi)\n"
        "movl 0x38(%edi), %ecx\n" /* pMatrix */
        "movl %ecx, 0x38(%esi)\n"
        "movl 0x3c(%edi), %edx\n" /* pMatrix */
        "movl %edx, 0x3c(%esi)\n"
        "movl 8(%ebp), %esi\n" /* line 135 | this */
        "movl 0x4b8(%esi), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* mp */
        "movl %ebx, -0x24(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl %edx, -0x1c(%ebp)\n"
        "movl 0x5fc(%esi), %edx\n" /* line 137 */
        "testl %edx, %edx\n"
        "js .Lff752_0000fb3d\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lff752_0000faf5:\n"
        "movss %xmm0, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x5f8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "js .Lff752_0000fb2a\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lff752_0000fb0c:\n"
        "movss %xmm0, 4(%esp)\n"
        "leal -0x58(%ebp), %ebx\n" /* mp */
        "movl %ebx, (%esp)\n"
        "calll MacOpenGLUtils_ConvertD3DProjectionMatrixToOpenGL\n"
        "movl %ebx, (%esp)\n" /* line 450 */
        "calll glLoadMatrixf\n"
        "jmp .Lff752_0000f794\n"
        ".Lff752_0000fb2a:\n"
        "movl %edx, %eax\n" /* line 137 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lff752_0000fb0c\n"
        ".Lff752_0000fb3d:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lff752_0000faf5\n"
    );
}

/* line 3161 */
__attribute__((naked))
CDirect3D * CDirect3D_GetDirect3DInterface(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3161 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl sDirect3DInterface, %edx\n" /* line 3163 */
        "testl %edx, %edx\n"
        "je .Lffb50_0000fb6f\n"
        "movl (%edx), %eax\n" /* line 3169 */
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        "movl sDirect3DInterface, %eax\n"
        "leave\n" /* line 3173 */
        "retl\n"
        ".Lffb50_0000fb6f:\n"
        "movl $0xc, (%esp)\n" /* line 3165 */
        "calll __Znwm\n"
        "movl $vtbl_CDirect3D, (%eax)\n" /* line 3146 */
        "movl $0, 8(%eax)\n"
        "movl $1, 4(%eax)\n" /* line 3194 */
        "movl %eax, sDirect3DInterface\n" /* line 3165 */
        "leave\n" /* line 3173 */
        "retl\n"
    );
}

/* line 3966 */
__attribute__((naked))
IDirect3D9 * Direct3DCreate9(UINT SDKVersion)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3966 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll CDirect3D_GetDirect3DInterface\n" /* line 3968 */
        "leave\n" /* line 3969 */
        "retl\n"
    );
}

/* line 2629 */
__attribute__((naked))
void CDirect3DDevice_CreateAndSetFixedFunctionVAO(const CDirect3DDevice * _this, bool *CanUseVAO, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices, int NeedsNormals)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2629 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5cc, %esp\n"
        "movzbl 0x20(%ebp), %eax\n" /* NeedsNormals */
        "movb %al, -0x59d(%ebp)\n" /* NeedsNormals */
        /* { scope 1: UsesTexFactor, VirginVAO */
        "leal -0x2cc(%ebp), %edx\n" /* line 63 | v */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_CVAOPacket\n"
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x2cc(%ebp)\n" /* v */
        "movl 8(%ebp), %ecx\n" /* line 2634 | this */
        "movl 0x24(%ecx), %ecx\n"
        "movl %ecx, -0x59c(%ebp)\n" /* pVB */
        "movl 8(%ebp), %eax\n" /* line 2638 | this */
        "movl 0x504(%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "je .Lffba4_0000ff92\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edx\n"
        /* { scope 2: UsesTexFactor */
        "addl $0x608, %ecx\n" /* line 334 */
        "movl %ecx, -0x598(%ebp)\n"
        "movl 0x608(%eax), %eax\n"
        "movl %eax, %ebx\n" /* line 2640 | ts */
        "cmpl $1, 0x2c(%eax)\n" /* line 2642 */
        "je .Lffba4_0000fc8f\n"
        "xorl %edi, %edi\n" /* line 2644 | i */
        "movl $0xa4, %esi\n"
        "jmp .Lffba4_0000fc71\n"
        ".Lffba4_0000fc1a:\n"
        "movl 0x50(%ebx), %edx\n" /* line 117 */
        "movl %edx, %eax\n" /* line 2655 */
        "xorw %ax, %ax\n"
        "cmpl $0x20000, %eax\n"
        "je .Lffba4_0000fc88\n"
        "movzwl %dx, %eax\n" /* line 2658 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x310(%edx, %eax, 4), %eax\n"
        "movl 0x24(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x59c(%ebp)\n" /* pVB */
        "testb $2, 0x21(%eax)\n" /* line 2659 */
        "jne .Lffba4_000104ba\n"
        "movl %edx, %ecx\n"
        /* } scope */
        ".Lffba4_0000fc4c:\n"
        "addl $1, %edi\n" /* line 2638 | i */
        "cmpl %edi, 0x504(%ecx)\n" /* i */
        "jbe .Lffba4_0000fc8d\n"
        /* { scope 2: UsesTexFactor */
        "movl %esi, %ebx\n" /* line 2640 | ts */
        "movl -0x598(%ebp), %edx\n"
        "addl (%edx), %ebx\n" /* ts */
        "addl $0xa4, %esi\n"
        "cmpl $1, 0x2c(%ebx)\n" /* line 2642 | ts */
        "je .Lffba4_0000ff92\n"
        ".Lffba4_0000fc71:\n"
        "movb $0, -0x19(%ebp)\n" /* line 2647 | UsesTexFactor */
        "leal -0x19(%ebp), %ecx\n" /* line 2648 | UsesTexFactor */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ts */
        "calll CDirect3DDevice_CTexStage_GetUsesTexture\n"
        "testb %al, %al\n" /* line 2650 */
        "jne .Lffba4_0000fc1a\n"
        ".Lffba4_0000fc88:\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "jmp .Lffba4_0000fc4c\n"
        ".Lffba4_0000fc8d:\n"
        "movl %ecx, %edx\n"
        /* } scope */
        ".Lffba4_0000fc8f:\n"
        "movl 0xac(%edx), %eax\n" /* line 2668 */
        "movl -0x59c(%ebp), %ecx\n" /* pVB */
        "movl 0x14(%ecx), %edx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "addl 0x64(%ecx), %edx\n"
        "movl %eax, %ecx\n"
        "imull g_Low, %ecx\n"
        "leal (%edx, %ecx), %esi\n" /* pVAStart */
        "movl %eax, %ebx\n" /* line 2669 | Size */
        "imull 0x14(%ebp), %ebx\n" /* NumVertices, Size */
        "movl %esi, -0x2c4(%ebp)\n" /* line 155 */
        "movl %ebx, -0x2c0(%ebp)\n"
        "leal -0x2cc(%ebp), %eax\n" /* line 2701 | v */
        "movl %eax, (%esp)\n"
        "calll CVAOPacket_IsCached\n"
        "testb %al, %al\n"
        "je .Lffba4_0000ff9a\n"
        "movl $1, 4(%esp)\n" /* line 2706 */
        "leal -0x2cc(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_SetVAO\n"
        "movl 8(%ebp), %ecx\n" /* line 159 | this */
        "movl 0x2c8(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2bc(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2d0(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2cc(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x274(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CVertexArray_SetGuard\n"
        "movl -0x260(%ebp), %eax\n" /* line 2716 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x264(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x268(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x26c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* Size */
        "movl %ebx, (%esp)\n" /* Size */
        "calll COpenGL_EnableVertexArray\n"
        "cmpb $0, -0x59d(%ebp)\n" /* line 2718 | NeedsNormals */
        "je .Lffba4_0001034d\n"
        "movl 8(%ebp), %edx\n" /* line 160 | this */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2e8(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2e4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x28c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CNormalArray_SetGuard\n"
        "movl -0x278(%ebp), %eax\n" /* line 2721 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x27c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x280(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* Size */
        "calll COpenGL_EnableNormalArray\n"
        ".Lffba4_0000fdcf:\n"
        "movl 8(%ebp), %ecx\n" /* line 2728 | this */
        "cmpb $0, 0x2ec(%ecx)\n"
        "je .Lffba4_0001033b\n"
        "movl 0x2fc(%ecx), %eax\n" /* line 161 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2f0(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x304(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x300(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x2bc(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CColorArray_SetGuard\n"
        "movl -0x2a8(%ebp), %eax\n" /* line 2731 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x2ac(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x2b0(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x2b4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableColorArray\n"
        ".Lffba4_0000fe52:\n"
        "movl 8(%ebp), %eax\n" /* line 2738 | this */
        "movl 0x504(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lffba4_00010162\n"
        "movl %eax, %ecx\n"
        /* { scope 2: UsesTexFactor */
        "addl $0x608, %ecx\n" /* line 334 */
        "movl %ecx, -0x594(%ebp)\n"
        "movl 0x608(%eax), %eax\n"
        "movl %eax, %ebx\n" /* line 2740 | ts */
        "cmpl $1, 0x2c(%eax)\n" /* line 2742 */
        "je .Lffba4_00010162\n"
        "xorl %esi, %esi\n" /* line 2744 | pVAStart */
        "movl $0xa4, %edi\n" /* i */
        "jmp .Lffba4_0000ff64\n"
        ".Lffba4_0000fe8f:\n"
        "movl 0x50(%ebx), %edx\n" /* line 117 */
        "movl %edx, %eax\n" /* line 2755 */
        "xorw %ax, %ax\n"
        "cmpl $0x20000, %eax\n"
        "je .Lffba4_0001035a\n"
        /* { scope 3 */
        "andl $0xffff, %edx\n" /* line 2762 | TexCoordStreamToUse */
        "movl 8(%ebp), %eax\n" /* line 2763 | this */
        "movl 0x310(%eax, %edx, 4), %ecx\n"
        "movl 0xac(%eax, %ecx, 4), %ebx\n" /* TexCoordStride */
        "movl 0x350(%eax, %edx, 4), %eax\n" /* line 162 */
        "movl %eax, 0x14(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x24(%eax, %ecx, 4), %ecx\n"
        "movl 0x14(%ecx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "addl 0x330(%ecx, %edx, 4), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* StartVertex */
        "imull %ebx, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl $0x1406, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal (%esi, %esi, 2), %eax\n"
        "leal -0x25c(%ebp, %eax, 8), %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        "movl 0x14(%ebx), %eax\n" /* line 2767 | TexCoordStride */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%ebx), %eax\n" /* TexCoordStride */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x1406, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n" /* TexCoordStride */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pVAStart */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableTexCoordArray\n"
        /* } scope */
        /* } scope */
        ".Lffba4_0000ff38:\n"
        "addl $1, %esi\n" /* line 2738 | pVAStart */
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl 0x504(%eax), %esi\n" /* pVAStart */
        "jae .Lffba4_00010162\n"
        /* { scope 2: UsesTexFactor */
        "movl %edi, %ebx\n" /* line 2740 | i, ts */
        "movl -0x594(%ebp), %edx\n"
        "addl (%edx), %ebx\n" /* ts */
        "addl $0xa4, %edi\n" /* i */
        "cmpl $1, 0x2c(%ebx)\n" /* line 2742 | ts */
        "je .Lffba4_00010162\n"
        ".Lffba4_0000ff64:\n"
        "movb $0, -0x19(%ebp)\n" /* line 2747 | UsesTexFactor */
        "leal -0x19(%ebp), %ecx\n" /* line 2748 | UsesTexFactor */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ts */
        "calll CDirect3DDevice_CTexStage_GetUsesTexture\n"
        "testb %al, %al\n" /* line 2750 */
        "jne .Lffba4_0000fe8f\n"
        "movl %esi, 4(%esp)\n" /* line 2772 | pVAStart */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_DisableTexCoordArray\n"
        "jmp .Lffba4_0000ff38\n"
        ".Lffba4_0000ff92:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lffba4_0000fc8f\n"
        /* } scope */
        /* { scope 2: UsesTexFactor */
        ".Lffba4_0000ff9a:\n"
        "leal -0x57c(%ebp), %ecx\n" /* line 63 | VirginVAO */
        "movl %ecx, (%esp)\n"
        "calll CVAOPacket_CVAOPacket\n"
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x57c(%ebp)\n" /* VirginVAO */
        "leal -0x57c(%ebp), %eax\n" /* line 2784 | VirginVAO */
        "movl %eax, (%esp)\n"
        "calll COpenGLVAO_CreateNewBinding\n"
        "movl $0, 4(%esp)\n" /* line 2785 */
        "leal -0x57c(%ebp), %edx\n" /* VirginVAO */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_SetVAO\n"
        "movl %esi, -0x574(%ebp)\n" /* line 155 */
        "movl %ebx, -0x570(%ebp)\n"
        "movl 8(%ebp), %ecx\n" /* line 159 | this */
        "movl 0x2c8(%ecx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2bc(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2d0(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2cc(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x524(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CVertexArray_SetGuard\n"
        "cmpb $0, -0x59d(%ebp)\n" /* line 2795 | NeedsNormals */
        "jne .Lffba4_0001041b\n"
        ".Lffba4_00010034:\n"
        "movl 8(%ebp), %ecx\n" /* line 2799 | this */
        "cmpb $0, 0x2ec(%ecx)\n"
        "jne .Lffba4_000103d5\n"
        "movl %ecx, %eax\n"
        ".Lffba4_00010046:\n"
        "movl 0x504(%eax), %edi\n" /* line 2803 | i */
        "testl %edi, %edi\n" /* i */
        "je .Lffba4_00010197\n"
        "movl %eax, %ecx\n"
        /* { scope 3 */
        "addl $0x608, %ecx\n" /* line 334 */
        "movl %ecx, -0x590(%ebp)\n"
        "movl 0x608(%eax), %eax\n"
        "movl %eax, %ebx\n" /* line 2805 | ts */
        "cmpl $1, 0x2c(%eax)\n" /* line 2807 */
        "je .Lffba4_00010197\n"
        "xorl %esi, %esi\n" /* line 2809 | pVAStart */
        "movl $0xa4, %edi\n" /* i */
        "jmp .Lffba4_00010114\n"
        /* { scope 4 */
        ".Lffba4_00010080:\n"
        "andl $0xffff, %edx\n" /* line 2826 | TexCoordStreamToUse */
        "movl 8(%ebp), %eax\n" /* line 2827 | this */
        "movl 0x310(%eax, %edx, 4), %ecx\n"
        "movl 0xac(%eax, %ecx, 4), %ebx\n" /* TexCoordStride */
        "movl 0x350(%eax, %edx, 4), %eax\n" /* line 162 */
        "movl %eax, 0x14(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x24(%eax, %ecx, 4), %ecx\n"
        "movl 0x14(%ecx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "addl 0x330(%ecx, %edx, 4), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* StartVertex */
        "imull %ebx, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        ".Lffba4_000100c6:\n"
        "movl $0x1406, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal (%esi, %esi, 2), %eax\n"
        "leal -0x50c(%ebp, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        /* } scope */
        /* } scope */
        ".Lffba4_000100e8:\n"
        "addl $1, %esi\n" /* line 2803 | pVAStart */
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl %esi, 0x504(%eax)\n" /* pVAStart */
        "jbe .Lffba4_00010197\n"
        /* { scope 3 */
        "movl -0x590(%ebp), %edx\n" /* line 2805 */
        "movl (%edx), %ebx\n" /* ts */
        "addl %edi, %ebx\n" /* i, ts */
        "addl $0xa4, %edi\n" /* i */
        "cmpl $1, 0x2c(%ebx)\n" /* line 2807 | ts */
        "je .Lffba4_00010197\n"
        ".Lffba4_00010114:\n"
        "movb $0, -0x19(%ebp)\n" /* line 2812 | UsesTexFactor */
        "leal -0x19(%ebp), %ecx\n" /* line 2813 | UsesTexFactor */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ts */
        "calll CDirect3DDevice_CTexStage_GetUsesTexture\n"
        "testb %al, %al\n" /* line 2815 */
        "je .Lffba4_000100e8\n"
        "movl 0x50(%ebx), %edx\n" /* line 117 */
        "movl %edx, %eax\n" /* line 2820 */
        "xorw %ax, %ax\n"
        "cmpl $0x20000, %eax\n"
        "jne .Lffba4_00010080\n"
        "movl $3, 0x14(%esp)\n" /* line 162 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x2bc(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2d0(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "jmp .Lffba4_000100c6\n"
        /* } scope */
        /* } scope */
        ".Lffba4_00010162:\n"
        "leal -0x2cc(%ebp), %edx\n" /* line 2777 | v */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_Cache\n"
        ".Lffba4_00010170:\n"
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n" /* line 63 */
        "addl $8, %eax\n"
        "movl %eax, -0x2cc(%ebp)\n" /* v */
        "leal -0x2cc(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        /* } scope */
        ".Lffba4_0001018c:\n"
        "addl $0x5cc, %esp\n" /* line 2912 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: UsesTexFactor, VirginVAO */
        /* { scope 2: UsesTexFactor */
        ".Lffba4_00010197:\n"
        "movl -0x574(%ebp), %esi\n" /* line 142 */
        "movl -0x570(%ebp), %ebx\n" /* line 143 */
        "movl %ebx, 8(%esp)\n" /* line 2851 | TexCoordStride */
        "movl %esi, 4(%esp)\n" /* pBuffer */
        "movl imp___ZN7COpenGL7sOpenGLE, %edi\n" /* i */
        "movl %edi, (%esp)\n" /* i */
        "calll COpenGL_SetVARInfo\n"
        "cmpb $0, 0x668(%edi)\n" /* line 2852 | i */
        "je .Lffba4_000101ce\n"
        "movl %esi, 4(%esp)\n" /* line 2854 | pBuffer */
        "movl %ebx, (%esp)\n" /* TexCoordStride */
        "calll glFlushVertexArrayRangeAPPLE\n"
        ".Lffba4_000101ce:\n"
        "movl -0x510(%ebp), %eax\n" /* line 2867 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x514(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x518(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x51c(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll COpenGL_EnableVertexArray\n"
        "cmpb $0, -0x59d(%ebp)\n" /* line 2869 | NeedsNormals */
        "jne .Lffba4_0001048f\n"
        ".Lffba4_0001020b:\n"
        "movl 8(%ebp), %edx\n" /* line 2874 | this */
        "cmpb $0, 0x2ec(%edx)\n"
        "jne .Lffba4_00010457\n"
        "movl %edx, %ecx\n"
        ".Lffba4_0001021d:\n"
        "movl 0x504(%ecx), %esi\n" /* line 2879 | pBuffer */
        "testl %esi, %esi\n" /* pBuffer */
        "je .Lffba4_0001030c\n"
        /* { scope 3 */
        "addl $0x608, %ecx\n" /* line 334 */
        "movl %ecx, -0x58c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x608(%edx), %eax\n"
        "movl %eax, %ebx\n" /* line 2881 | ts */
        "cmpl $1, 0x2c(%eax)\n" /* line 2883 */
        "je .Lffba4_0001030c\n"
        "xorl %esi, %esi\n" /* line 2885 | pBuffer */
        "movl $0xa4, %edi\n" /* i */
        "jmp .Lffba4_000102b1\n"
        ".Lffba4_00010255:\n"
        "leal (%esi, %esi, 2), %edx\n" /* line 2903 | pBuffer */
        "leal -0x50c(%ebp, %edx, 8), %edx\n"
        "movl 0x14(%edx), %eax\n"
        "movl %eax, 0x14(%esp)\n"
        "movl 0x10(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x1406, 0xc(%esp)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pBuffer */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableTexCoordArray\n"
        /* } scope */
        ".Lffba4_0001028d:\n"
        "addl $1, %esi\n" /* line 2879 | pBuffer */
        "movl 8(%ebp), %ecx\n" /* this */
        "cmpl 0x504(%ecx), %esi\n" /* pBuffer */
        "jae .Lffba4_0001030c\n"
        /* { scope 3 */
        "movl %edi, %ebx\n" /* line 2881 | i, ts */
        "movl -0x58c(%ebp), %eax\n"
        "addl (%eax), %ebx\n" /* ts */
        "addl $0xa4, %edi\n" /* i */
        "cmpl $1, 0x2c(%ebx)\n" /* line 2883 | ts */
        "je .Lffba4_0001030c\n"
        ".Lffba4_000102b1:\n"
        "movb $0, -0x19(%ebp)\n" /* line 2888 | UsesTexFactor */
        "leal -0x19(%ebp), %edx\n" /* line 2889 | UsesTexFactor */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ts */
        "calll CDirect3DDevice_CTexStage_GetUsesTexture\n"
        "testb %al, %al\n" /* line 2891 */
        "je .Lffba4_0001028d\n"
        "movl 0x50(%ebx), %eax\n" /* line 2897 | ts */
        "xorw %ax, %ax\n"
        "cmpl $0x20000, %eax\n"
        "jne .Lffba4_00010255\n"
        "movl -0x510(%ebp), %eax\n" /* line 2899 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x514(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x1406, 0xc(%esp)\n"
        "movl $3, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pBuffer */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableTexCoordArray\n"
        "jmp .Lffba4_0001028d\n"
        /* } scope */
        ".Lffba4_0001030c:\n"
        "leal -0x57c(%ebp), %eax\n" /* line 2910 | VirginVAO */
        "movl %eax, (%esp)\n"
        "calll CVAOPacket_Cache\n"
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n" /* line 63 */
        "addl $8, %eax\n"
        "movl %eax, -0x57c(%ebp)\n" /* VirginVAO */
        "leal -0x57c(%ebp), %ecx\n" /* VirginVAO */
        "movl %ecx, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        "jmp .Lffba4_00010170\n"
        /* } scope */
        ".Lffba4_0001033b:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 2735 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_DisableColorArray\n"
        "jmp .Lffba4_0000fe52\n"
        ".Lffba4_0001034d:\n"
        "movl %ebx, (%esp)\n" /* line 2725 | Size */
        "calll COpenGL_DisableNormalArray\n"
        "jmp .Lffba4_0000fdcf\n"
        /* { scope 2: UsesTexFactor */
        ".Lffba4_0001035a:\n"
        "movl $3, 0x14(%esp)\n" /* line 162 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x2bc(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2d0(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0x1406, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal (%esi, %esi, 2), %eax\n"
        "leal -0x25c(%ebp, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        "movl -0x260(%ebp), %eax\n" /* line 2758 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x264(%ebp), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x1406, 0xc(%esp)\n"
        "movl $3, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* pVAStart */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableTexCoordArray\n"
        "jmp .Lffba4_0000ff38\n"
        /* } scope */
        /* { scope 2: UsesTexFactor */
        ".Lffba4_000103d5:\n"
        "movl 0x2fc(%ecx), %eax\n" /* line 161 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2f0(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x304(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x300(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x56c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CColorArray_SetGuard\n"
        "movl 8(%ebp), %eax\n" /* this */
        "jmp .Lffba4_00010046\n"
        ".Lffba4_0001041b:\n"
        "movl 8(%ebp), %edx\n" /* line 160 | this */
        "movl 0x2d8(%edx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2e8(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x2e4(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x53c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CNormalArray_SetGuard\n"
        "jmp .Lffba4_00010034\n"
        ".Lffba4_00010457:\n"
        "movl -0x558(%ebp), %eax\n" /* line 2876 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x55c(%ebp), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x560(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x564(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll COpenGL_EnableColorArray\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "jmp .Lffba4_0001021d\n"
        ".Lffba4_0001048f:\n"
        "movl -0x528(%ebp), %eax\n" /* line 2871 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x52c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x530(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* i */
        "calll COpenGL_EnableNormalArray\n"
        "jmp .Lffba4_0001020b\n"
        /* } scope */
        /* { scope 2: UsesTexFactor */
        ".Lffba4_000104ba:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 2661 | CanUseVAO */
        "movb $0, (%ecx)\n"
        /* } scope */
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n" /* line 63 */
        "addl $8, %eax\n"
        "movl %eax, -0x2cc(%ebp)\n" /* v */
        "leal -0x2cc(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        "jmp .Lffba4_0001018c\n"
        "movl %eax, %ebx\n"
        /* { scope 2: UsesTexFactor */
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x57c(%ebp)\n" /* VirginVAO */
        "leal -0x57c(%ebp), %edx\n" /* VirginVAO */
        "movl %edx, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        /* } scope */
        ".Lffba4_000104ff:\n"
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, -0x2cc(%ebp)\n" /* v */
        "leal -0x2cc(%ebp), %eax\n" /* v */
        "movl %eax, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n"
        "jmp .Lffba4_000104ff\n"
    );
}

/* line 2300 */
__attribute__((naked))
void CDirect3DDevice_CreateAndSetProgrammableVAO(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2300 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x59c, %esp\n"
        /* { scope 1: VirginVAO */
        "leal -0x2c8(%ebp), %eax\n" /* line 70 | v, VType */
        "movl %eax, (%esp)\n" /* VType */
        "calll CVAOPacket_CVAOPacket\n"
        "movl imp___ZTV22CVAOPacketProgrammable, %edi\n"
        "addl $8, %edi\n"
        "movl %edi, -0x2c8(%ebp)\n" /* v */
        "movl 8(%ebp), %edx\n" /* line 2321 | this */
        "movl 0xac(%edx), %ecx\n"
        "movl 0x24(%edx), %eax\n"
        "movl 0x14(%eax), %eax\n"
        "addl 0x64(%edx), %eax\n"
        "movl %ecx, %edx\n"
        "imull g_Low, %edx\n"
        "leal (%eax, %edx), %esi\n" /* pVAStart */
        "movl %ecx, %ebx\n" /* line 2322 | Size */
        "imull 0x10(%ebp), %ebx\n" /* NumVertices, Size */
        "movl %esi, -0x2c0(%ebp)\n" /* line 155 | VSize */
        "movl %ebx, -0x2bc(%ebp)\n"
        "leal -0x2c8(%ebp), %eax\n" /* line 2329 | v */
        "movl %eax, (%esp)\n"
        "calll CVAOPacket_IsCached\n"
        "testb %al, %al\n"
        "je .Lf10528_000106d7\n"
        "movl $1, 4(%esp)\n" /* line 2334 */
        "leal -0x2c8(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_SetVAO\n"
        "movl $0, -0x57c(%ebp)\n"
        "leal -0x198(%ebp), %edi\n"
        "movl 8(%ebp), %esi\n" /* this, pVAStart */
        "addl $0xf0, %esi\n" /* pVAStart */
        "jmp .Lf10528_00010643\n"
        /* { scope 2: VSize */
        ".Lf10528_000105c8:\n"
        "movl 8(%ebp), %edx\n" /* line 2293 | this */
        "movl 0x24(%edx, %eax, 4), %eax\n"
        "movl 0x14(%eax), %edx\n"
        "addl 0x10(%esi), %edx\n" /* VSize */
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "imull %ebx, %eax\n"
        "addl %eax, %edx\n"
        "movl 0x18(%esi), %ecx\n" /* line 63 */
        "movzbl 0x1c(%esi), %eax\n" /* line 167 | VSize */
        "movl %eax, 0x10(%esp)\n"
        "movb $1, 1(%edi)\n" /* line 60 */
        /* { scope 3: VType */
        "movl 0x14(%esi), %eax\n" /* line 61 */
        "movl %eax, 4(%edi)\n"
        /* } scope */
        /* { scope 3: VType */
        "movl %ecx, 8(%edi)\n" /* line 62 */
        /* } scope */
        "movzbl 0x10(%esp), %eax\n" /* line 63 */
        "movb %al, 0xc(%edi)\n"
        "movl %ebx, 0x10(%edi)\n" /* line 64 */
        "movl %edx, 0x14(%edi)\n" /* line 65 */
        "movl %edx, 0x18(%esp)\n" /* line 2352 */
        "movl %ebx, 0x14(%esp)\n" /* Stride */
        "movl %ecx, 0xc(%esp)\n"
        "movl 0x14(%esi), %edx\n" /* pVAStart */
        "movl %edx, 8(%esp)\n"
        "movl -0x57c(%ebp), %ebx\n" /* Stride */
        "movl %ebx, 4(%esp)\n" /* Stride */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetVertexProgramStreamInfo\n"
        /* } scope */
        "addl $1, -0x57c(%ebp)\n" /* line 2341 */
        "addl $0x1c, %esi\n" /* pVAStart */
        "addl $0x18, %edi\n"
        "cmpl $0x10, -0x57c(%ebp)\n"
        "je .Lf10528_000106a2\n"
        /* { scope 2: VSize */
        ".Lf10528_00010643:\n"
        "movl 0x20(%esi), %ebx\n" /* line 2345 | pVAStart, Stride */
        "movl 0xc(%esi), %eax\n" /* line 60 */
        "cmpb $0, 8(%esi)\n" /* line 2347 | pVAStart */
        "jne .Lf10528_000105c8\n"
        "movl 0x18(%esi), %eax\n" /* line 63 */
        "movl 0x14(%esi), %edx\n" /* line 62 */
        "movzbl 0x1c(%esi), %ecx\n" /* line 167 | VSize */
        /* { scope 3: VType */
        "movb $0, 1(%edi)\n" /* line 60 */
        /* { scope 4 */
        "movl %edx, 4(%edi)\n" /* line 61 */
        /* } scope */
        /* { scope 4 */
        "movl %eax, 8(%edi)\n" /* line 62 */
        /* } scope */
        "movb %cl, 0xc(%edi)\n" /* line 63 */
        "movl %ebx, 0x10(%edi)\n" /* line 64 */
        "movl $0, 0x14(%edi)\n" /* line 65 */
        /* } scope */
        "movl -0x57c(%ebp), %edx\n" /* line 2357 */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* Stride */
        "movl %ebx, (%esp)\n" /* Stride */
        "calll COpenGL_DisableVertexProgramStream\n"
        /* } scope */
        "addl $1, -0x57c(%ebp)\n" /* line 2341 */
        "addl $0x1c, %esi\n" /* pVAStart */
        "addl $0x18, %edi\n"
        "cmpl $0x10, -0x57c(%ebp)\n"
        "jne .Lf10528_00010643\n"
        ".Lf10528_000106a2:\n"
        "leal -0x2c8(%ebp), %eax\n" /* line 2362 | v */
        "movl %eax, (%esp)\n"
        "calll CVAOPacket_Cache\n"
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n" /* line 70 | VType */
        "addl $8, %eax\n" /* VType */
        "movl %eax, -0x2c8(%ebp)\n" /* VType, v */
        "leal -0x2c8(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        /* } scope */
        "addl $0x59c, %esp\n" /* line 2417 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: VirginVAO */
        /* { scope 2: VSize */
        ".Lf10528_000106d7:\n"
        "leal -0x578(%ebp), %edx\n" /* line 70 | VirginVAO */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_CVAOPacket\n"
        "movl %edi, -0x578(%ebp)\n" /* VirginVAO */
        "leal -0x578(%ebp), %eax\n" /* line 2369 | VirginVAO */
        "movl %eax, (%esp)\n"
        "calll COpenGLVAO_CreateNewBinding\n"
        "movl $0, 4(%esp)\n" /* line 2370 */
        "leal -0x578(%ebp), %edx\n" /* VirginVAO */
        "movl %edx, (%esp)\n"
        "calll CVAOPacket_SetVAO\n"
        "movl %esi, -0x570(%ebp)\n" /* line 155 | VSize */
        "movl %ebx, -0x56c(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* line 2379 | Stride */
        "movl %esi, 4(%esp)\n" /* pVAStart */
        "movl imp___ZN7COpenGL7sOpenGLE, %edi\n"
        "movl %edi, (%esp)\n"
        "calll COpenGL_SetVARInfo\n"
        "cmpb $0, 0x668(%edi)\n" /* line 2380 */
        "jne .Lf10528_00010863\n"
        ".Lf10528_0001073e:\n"
        "movl $0, -0x580(%ebp)\n" /* line 2382 | i */
        "leal -0x448(%ebp), %ebx\n" /* Stride */
        "movl %ebx, -0x584(%ebp)\n" /* Stride */
        "movl 8(%ebp), %edi\n" /* this */
        "addl $0xf0, %edi\n"
        "jmp .Lf10528_0001077d\n"
        ".Lf10528_0001075f:\n"
        "addl $1, -0x580(%ebp)\n" /* line 2396 | i */
        "addl $0x1c, %edi\n"
        "addl $0x18, -0x584(%ebp)\n"
        "cmpl $0x10, -0x580(%ebp)\n" /* i */
        "je .Lf10528_00010812\n"
        ".Lf10528_0001077d:\n"
        "cmpb $0, 8(%edi)\n" /* line 2402 */
        "je .Lf10528_0001075f\n"
        /* { scope 3: VType */
        "movl 0x20(%edi), %ecx\n" /* line 2404 | Stride */
        "movl 0xc(%edi), %eax\n" /* line 2293 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x24(%edx, %eax, 4), %eax\n"
        "movl 0x14(%eax), %edx\n"
        "addl 0x10(%edi), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "imull %ecx, %eax\n"
        "addl %eax, %edx\n"
        "movl 0x14(%edi), %esi\n" /* line 62 */
        "movzbl 0x1c(%edi), %ebx\n" /* line 167 */
        "movl %ebx, 0x10(%esp)\n"
        "movl -0x584(%ebp), %eax\n" /* line 60 */
        "movb $1, 1(%eax)\n"
        /* { scope 4 */
        "movl %esi, 4(%eax)\n" /* line 61 */
        /* } scope */
        /* { scope 4 */
        "movl 0x18(%edi), %ebx\n" /* line 62 */
        "movl %ebx, 8(%eax)\n"
        /* } scope */
        "movzbl 0x10(%esp), %ebx\n" /* line 63 */
        "movb %bl, 0xc(%eax)\n"
        "movl %ecx, 0x10(%eax)\n" /* line 64 */
        "movl %edx, 0x14(%eax)\n" /* line 65 */
        "movl %edx, 0x18(%esp)\n" /* line 2410 */
        "movl %ecx, 0x14(%esp)\n"
        "movl 0x18(%edi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* pVAStart */
        "movl -0x580(%ebp), %edx\n" /* i */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetVertexProgramStreamInfo\n"
        /* } scope */
        "addl $1, -0x580(%ebp)\n" /* line 2396 | i */
        "addl $0x1c, %edi\n"
        "addl $0x18, -0x584(%ebp)\n"
        "cmpl $0x10, -0x580(%ebp)\n" /* i */
        "jne .Lf10528_0001077d\n"
        ".Lf10528_00010812:\n"
        "leal -0x578(%ebp), %ebx\n" /* line 2415 | VirginVAO, Stride */
        "movl %ebx, (%esp)\n" /* Stride */
        "calll CVAOPacket_Cache\n"
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n" /* line 70 | VType */
        "addl $8, %eax\n" /* VType */
        "movl %eax, -0x578(%ebp)\n" /* VType, VirginVAO */
        "leal -0x578(%ebp), %edx\n" /* VirginVAO */
        "movl %edx, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        /* } scope */
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n" /* VType */
        "addl $8, %eax\n" /* VType */
        "movl %eax, -0x2c8(%ebp)\n" /* VType, v */
        "leal -0x2c8(%ebp), %edx\n" /* v */
        "movl %edx, (%esp)\n"
        "calll ZN10CVAOPacketD2Ev\n"
        /* } scope */
        "addl $0x59c, %esp\n" /* line 2417 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: VirginVAO */
        /* { scope 2: VSize */
        ".Lf10528_00010863:\n"
        "movl %esi, 4(%esp)\n" /* line 2382 | pVAStart */
        "movl %ebx, (%esp)\n" /* Stride */
        "calll glFlushVertexArrayRangeAPPLE\n"
        "jmp .Lf10528_0001073e\n"
        "movl %eax, %ebx\n" /* Stride */
        /* } scope */
        ".Lf10528_00010876:\n"
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n" /* line 70 | VType */
        "addl $8, %eax\n" /* VType */
        "movl %eax, -0x2c8(%ebp)\n" /* VType, v */
        "leal -0x2c8(%ebp), %eax\n" /* v, VType */
        "movl %eax, (%esp)\n" /* VType */
        "calll ZN10CVAOPacketD2Ev\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* VType */
        /* { scope 2: VSize */
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n" /* VType */
        "addl $8, %eax\n" /* VType */
        "movl %eax, -0x578(%ebp)\n" /* VType, VirginVAO */
        "leal -0x578(%ebp), %eax\n" /* VirginVAO, VType */
        "movl %eax, (%esp)\n" /* VType */
        "calll ZN10CVAOPacketD2Ev\n"
        "jmp .Lf10528_00010876\n"
    );
}

/* line 3041 */
__attribute__((naked))
void CDirect3DDevice_ValidateTransformation(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 NumVertices, const void * pIndices, UINT32 NumIndices)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3041 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x18(%ebp), %edi\n" /* NumIndices */
        /* { scope 1 */
        "movb $1, -0x19(%ebp)\n" /* line 3051 | CanUseVAO */
        "movl 0xbb4(%ebx), %esi\n" /* line 3053 | this */
        "testl %esi, %esi\n"
        "je .Lf108ba_00010960\n"
        "xorl %edx, %edx\n"
        "leal 0xf8(%ebx), %eax\n" /* this */
        ".Lf108ba_000108e3:\n"
        "movb $0, (%eax)\n" /* line 57 */
        "addl $1, %edx\n" /* line 3057 */
        "addl $0x1c, %eax\n"
        "cmpl $0x10, %edx\n"
        "jne .Lf108ba_000108e3\n"
        "leal -0x19(%ebp), %eax\n" /* line 3062 | CanUseVAO */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_ParseShaderDeclaration\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 3064 | CanUseVAO */
        "je .Lf108ba_00010937\n"
        "movl %edi, 0x10(%esp)\n" /* line 3066 | NumIndices */
        "movl 0x14(%ebp), %eax\n" /* pIndices */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* NumVertices */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_CreateAndSetProgrammableVAO\n"
        /* } scope */
        ".Lf108ba_0001092f:\n"
        "addl $0x3c, %esp\n" /* line 3132 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf108ba_00010937:\n"
        "movl %edi, 0x10(%esp)\n" /* line 3070 | NumIndices */
        "movl 0x14(%ebp), %eax\n" /* pIndices */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* NumVertices */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_CreateAndSetGenericProgrammableVAO\n"
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3132 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf108ba_00010960:\n"
        "movb $0, 0x2b8(%ebx)\n" /* line 3079 | this */
        "movb $0, 0x2d4(%ebx)\n" /* line 3080 | this */
        "movb $0, 0x2ec(%ebx)\n" /* line 3081 | this */
        "movl %ebx, %eax\n" /* this */
        "movl $8, %edx\n"
        ".Lf108ba_0001097c:\n"
        "movb $0, 0x308(%eax)\n" /* line 3085 */
        "addl $1, %eax\n"
        "subl $1, %edx\n" /* line 3083 */
        "jne .Lf108ba_0001097c\n"
        "leal -0x19(%ebp), %eax\n" /* line 3088 | CanUseVAO */
        "movl %eax, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_ParseShaderDeclaration\n"
        "movl 0xc(%ebp), %eax\n" /* line 3102 | StartVertex */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_GetStreamPtrs\n"
        "movl %eax, %esi\n" /* NeedsNormals */
        "cmpb $0, -0x19(%ebp)\n" /* line 3104 | CanUseVAO */
        "jne .Lf108ba_00010a2f\n"
        ".Lf108ba_000109b9:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 3109 | CanUseVAO */
        "jne .Lf108ba_000109f2\n"
        "andl $0xff, %esi\n" /* NeedsNormals */
        ".Lf108ba_000109c5:\n"
        "movl %esi, 0x14(%esp)\n" /* line 3121 | NeedsNormals */
        "movl %edi, 0x10(%esp)\n" /* NumIndices */
        "movl 0x14(%ebp), %eax\n" /* pIndices */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* NumVertices */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_CreateAndSetGenericFixedFunctionVAO\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 3132 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf108ba_000109f2:\n"
        "andl $0xff, %esi\n" /* line 3111 | NeedsNormals */
        "movl %esi, 0x18(%esp)\n" /* NeedsNormals */
        "movl %edi, 0x14(%esp)\n" /* NumIndices */
        "movl 0x14(%ebp), %eax\n" /* pIndices */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* NumVertices */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "movl %eax, 8(%esp)\n"
        "leal -0x19(%ebp), %eax\n" /* CanUseVAO */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_CreateAndSetFixedFunctionVAO\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 3113 | CanUseVAO */
        "je .Lf108ba_000109c5\n"
        "jmp .Lf108ba_0001092f\n"
        ".Lf108ba_00010a2f:\n"
        "movl $1, 4(%esp)\n" /* line 3106 */
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_GetCanUseVAOWithTexCoordStreams\n"
        "movb %al, -0x19(%ebp)\n" /* CanUseVAO */
        "jmp .Lf108ba_000109b9\n"
    );
}

/* line 896 */
__attribute__((naked))
void CDirect3DDevice_SynchronizeD3DAndOpenGLTextureState(const CDirect3DDevice * _this, IDirect3DBaseTexture9 *pTex, UINT32 Stage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 896 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1: this, Value */
        "movl 0xc(%ebp), %edx\n" /* line 908 | pTex */
        "movl (%edx), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *0x28(%eax)\n"
        "movl %eax, %edi\n" /* TextureType */
        "cmpl $3, %eax\n" /* line 912 */
        "je .Lf10a4a_00011149\n"
        "cmpl $4, %eax\n" /* line 918 */
        "je .Lf10a4a_000112a4\n"
        "cmpl $5, %eax\n" /* line 924 */
        "je .Lf10a4a_000113ca\n"
        "movl $0, -0x50(%ebp)\n" /* pOGLTexInfo */
        "movl $0, -0x4c(%ebp)\n" /* p2DTexture */
        "movl $0, -0x48(%ebp)\n" /* pVolumeTexture */
        "movl $0, -0x44(%ebp)\n" /* pCubeTexture */
        "movl $0, -0x40(%ebp)\n" /* Target */
        "movl -0x50(%ebp), %ecx\n" /* pOGLTexInfo */
        ".Lf10a4a_00010aa1:\n"
        "movl 4(%ecx), %eax\n" /* line 937 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf10a4a_000110bc\n"
        "xorl %ebx, %ebx\n" /* RecreateTextureData */
        ".Lf10a4a_00010ab0:\n"
        "movl -0x50(%ebp), %edx\n" /* line 949 | pOGLTexInfo */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTex\n"
        "cmpl $3, %edi\n" /* line 951 | TextureType */
        "je .Lf10a4a_00011173\n"
        "cmpl $4, %edi\n" /* line 959 | TextureType */
        "je .Lf10a4a_000112e0\n"
        "cmpl $5, %edi\n" /* line 968 | TextureType */
        "je .Lf10a4a_00011506\n"
        ".Lf10a4a_00010aed:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 654 | Stage */
        "leal (%ecx, %ecx, 4), %eax\n"
        "leal (%ecx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x608(%eax), %edx\n"
        "addl %edx, -0x54(%ebp)\n"
        "movl -0x54(%ebp), %ecx\n" /* line 112 */
        "movl 8(%ecx), %eax\n"
        "cmpl $1, %eax\n" /* line 987 */
        "je .Lf10a4a_000111bc\n"
        "cmpl $3, %eax\n" /* line 991 */
        "je .Lf10a4a_00011333\n"
        "cmpl $4, %eax\n" /* line 995 */
        "je .Lf10a4a_000114f8\n"
        "movb $0, -0x39(%ebp)\n" /* UsesBorderColor */
        "xorl %ebx, %ebx\n" /* togl */
        ".Lf10a4a_00010b2f:\n"
        "movl 0x10(%ebp), %edx\n" /* line 654 | Stage */
        "leal (%edx, %edx, 8), %eax\n"
        "leal (%edx, %eax, 2), %esi\n"
        "shll $4, %esi\n"
        "movl %esi, %edi\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %edi\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010b6c\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_000112d6\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001141c\n"
        ".Lf10a4a_00010b6c:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010b6e:\n"
        "cmpl 0x10(%edi, %eax, 4), %ebx\n" /* line 806 | TexID */
        "je .Lf10a4a_00010bc9\n"
        "movl 0x10(%ebp), %eax\n" /* line 808 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %ebx, 8(%esp)\n" /* line 154 */
        "movl $0x2802, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010bc3\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011589\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011456\n"
        ".Lf10a4a_00010bc3:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010bc5:\n"
        "movl %ebx, 0x10(%edi, %eax, 4)\n" /* line 154 */
        ".Lf10a4a_00010bc9:\n"
        "movl -0x50(%ebp), %eax\n" /* line 134 | pOGLTexInfo */
        "addl $4, %eax\n"
        "movl %eax, -0x34(%ebp)\n" /* this */
        /* { scope 2 */
        "movl %ebx, 4(%eax)\n" /* line 56 */
        /* } scope */
        "movl -0x54(%ebp), %edx\n" /* line 113 */
        "movl 0xc(%edx), %eax\n"
        "cmpl $1, %eax\n" /* line 1009 */
        "je .Lf10a4a_000111ca\n"
        "cmpl $3, %eax\n" /* line 1013 */
        "je .Lf10a4a_00011329\n"
        "cmpl $4, %eax\n" /* line 1017 */
        "je .Lf10a4a_0001154f\n"
        "xorl %ebx, %ebx\n" /* togl */
        ".Lf10a4a_00010bf8:\n"
        "movl %esi, %edi\n" /* line 654 */
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %edi\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010c29\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011341\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011412\n"
        ".Lf10a4a_00010c29:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010c2b:\n"
        "cmpl 0x1c(%edi, %eax, 4), %ebx\n" /* line 816 | TexID */
        "je .Lf10a4a_00010c86\n"
        "movl 0x10(%ebp), %eax\n" /* line 818 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %ebx, 8(%esp)\n" /* line 155 */
        "movl $0x2803, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010c80\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_0001157f\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001146a\n"
        ".Lf10a4a_00010c80:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010c82:\n"
        "movl %ebx, 0x1c(%edi, %eax, 4)\n" /* line 155 */
        ".Lf10a4a_00010c86:\n"
        "movl -0x34(%ebp), %eax\n" /* line 57 | this */
        "movl %ebx, 8(%eax)\n"
        "movl -0x54(%ebp), %edx\n" /* line 114 */
        "movl 0x10(%edx), %eax\n"
        "cmpl $1, %eax\n" /* line 1031 */
        "je .Lf10a4a_000111d4\n"
        "cmpl $3, %eax\n" /* line 1035 */
        "je .Lf10a4a_000112cc\n"
        "cmpl $4, %eax\n" /* line 1039 */
        "je .Lf10a4a_0001155d\n"
        "xorl %ebx, %ebx\n" /* togl */
        ".Lf10a4a_00010caf:\n"
        "movl %esi, %edi\n" /* line 654 */
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %edi\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010ce0\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011290\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011408\n"
        ".Lf10a4a_00010ce0:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010ce2:\n"
        "cmpl 0x28(%edi, %eax, 4), %ebx\n" /* line 826 | TexID */
        "je .Lf10a4a_00010d3d\n"
        "movl 0x10(%ebp), %eax\n" /* line 828 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %ebx, 8(%esp)\n" /* line 156 */
        "movl $0x8072, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010d37\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011593\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001147e\n"
        ".Lf10a4a_00010d37:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010d39:\n"
        "movl %ebx, 0x28(%edi, %eax, 4)\n" /* line 156 */
        ".Lf10a4a_00010d3d:\n"
        "movl -0x34(%ebp), %eax\n" /* line 58 | this */
        "movl %ebx, 0xc(%eax)\n"
        "cmpb $0, -0x39(%ebp)\n" /* line 1052 | UsesBorderColor */
        "jne .Lf10a4a_00011086\n"
        ".Lf10a4a_00010d4d:\n"
        "movl -0x50(%ebp), %edx\n" /* line 120 | pOGLTexInfo */
        "movl 0x28(%edx), %eax\n"
        "movl 0x2c(%edx), %edx\n" /* line 121 */
        "testl %eax, %eax\n" /* line 1067 */
        "je .Lf10a4a_00010d68\n"
        "cmpl $3, %eax\n" /* line 1070 */
        "jbe .Lf10a4a_00010d68\n"
        "cmpl $3, %edx\n"
        "ja .Lf10a4a_00011426\n"
        ".Lf10a4a_00010d68:\n"
        "xorl %ebx, %ebx\n" /* line 1067 | togl */
        ".Lf10a4a_00010d6a:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1095 | pTex */
        "movl (%edx), %eax\n" /* __b */
        "movl %edx, (%esp)\n"
        "calll *0x34(%eax)\n"
        "movl %eax, -0x20(%ebp)\n" /* __b */
        "movl %ebx, -0x1c(%ebp)\n" /* togl */
        /* { scope 2 */
        "cmpl %ebx, %eax\n" /* line 189 */
        "jge .Lf10a4a_00011062\n"
        "leal -0x20(%ebp), %eax\n"
        /* } scope */
        "movl (%eax), %ecx\n" /* line 1096 */
        "subl $1, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* LastLevel */
        "js .Lf10a4a_00011073\n"
        ".Lf10a4a_00010d94:\n"
        "movl %ecx, -0x2c(%ebp)\n"
        ".Lf10a4a_00010d97:\n"
        "movl -0x54(%ebp), %edx\n" /* line 119 */
        "movl 0x18(%edx), %eax\n"
        "cmpl $3, %eax\n" /* line 1108 */
        "je .Lf10a4a_00010dab\n"
        "cmpl $1, %eax\n" /* line 1113 */
        "jbe .Lf10a4a_000113c0\n"
        ".Lf10a4a_00010dab:\n"
        "movl $0x2601, %ebx\n" /* togl */
        ".Lf10a4a_00010db0:\n"
        "movl %esi, %edi\n" /* line 654 */
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %edi\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010de1\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_0001129a\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000113f4\n"
        ".Lf10a4a_00010de1:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010de3:\n"
        "cmpl 0x4c(%edi, %eax, 4), %ebx\n" /* line 856 | TexID */
        "je .Lf10a4a_00010e3e\n"
        "movl 0x10(%ebp), %eax\n" /* line 858 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %ebx, 8(%esp)\n" /* line 170 */
        "movl $0x2800, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010e38\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011575\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011460\n"
        ".Lf10a4a_00010e38:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010e3a:\n"
        "movl %ebx, 0x4c(%edi, %eax, 4)\n" /* line 170 */
        ".Lf10a4a_00010e3e:\n"
        "movl -0x34(%ebp), %eax\n" /* line 61 | this */
        "movl %ebx, 0x18(%eax)\n"
        "movl -0x54(%ebp), %edx\n" /* line 120 */
        "movl 0x1c(%edx), %ecx\n"
        "movl 0x14(%edx), %edx\n" /* line 118 */
        "cmpl $3, %edx\n" /* line 1120 */
        "movl $2, %eax\n"
        "cmovel %eax, %edx\n"
        "testl %ecx, %ecx\n" /* line 1126 */
        "je .Lf10a4a_00010e67\n"
        "movl -0x38(%ebp), %edi\n" /* line 1128 | LastLevel, TextureType */
        "testl %edi, %edi\n" /* TextureType */
        "jne .Lf10a4a_0001161b\n"
        ".Lf10a4a_00010e67:\n"
        "cmpl $1, %edx\n" /* line 1137 */
        "jbe .Lf10a4a_000111de\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "addl 0x65c(%eax), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010ea0\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_000114a9\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011442\n"
        ".Lf10a4a_00010ea0:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010ea2:\n"
        "cmpl $0x2601, 0x40(%ebx, %eax, 4)\n" /* line 846 | TexID */
        "je .Lf10a4a_00010f09\n"
        "movl 0x10(%ebp), %edx\n" /* line 848 | Stage */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0x2601, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* Target */
        "movl %eax, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010eff\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_000115be\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001149f\n"
        ".Lf10a4a_00010eff:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010f01:\n"
        "movl $0x2601, 0x40(%ebx, %eax, 4)\n" /* line 169 */
        ".Lf10a4a_00010f09:\n"
        "movl -0x34(%ebp), %edx\n" /* line 60 | this */
        "movl $0x2601, 0x14(%edx)\n"
        ".Lf10a4a_00010f13:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n" /* line 1182 */
        "cmpb $0, 0x808(%edx)\n"
        "je .Lf10a4a_0001105b\n"
        "movl -0x54(%ebp), %ecx\n" /* line 121 */
        "movss 0x24(%ecx), %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n" /* Value */
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "addl 0x65c(%edx), %ebx\n" /* TexID */
        "ucomiss 0xc0(%ebx), %xmm0\n" /* line 888 | TexID */
        "jp .Lf10a4a_000114b3\n"
        "jne .Lf10a4a_000114b3\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        ".Lf10a4a_00010f53:\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "addl 0x65c(%eax), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010f7e\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011286\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000113fe\n"
        ".Lf10a4a_00010f7e:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010f80:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 866 */
        "cmpl %edx, 0x64(%ebx, %eax, 4)\n" /* TexID */
        "je .Lf10a4a_00010fe3\n"
        "movl 0x10(%ebp), %ecx\n" /* line 868 | Stage */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl -0x2c(%ebp), %edx\n" /* line 172 */
        "movl %edx, 8(%esp)\n"
        "movl $0x813d, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00010fda\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_0001159d\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011474\n"
        ".Lf10a4a_00010fda:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00010fdc:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 172 */
        "movl %edx, 0x64(%ebx, %eax, 4)\n"
        ".Lf10a4a_00010fe3:\n"
        "movl -0x38(%ebp), %eax\n" /* line 62 | LastLevel */
        "movl -0x34(%ebp), %ecx\n" /* this */
        "movl %eax, 0x1c(%ecx)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n" /* line 1191 */
        "cmpb $0, 0x802(%edx)\n"
        "je .Lf10a4a_00011053\n"
        "movl -0x54(%ebp), %ecx\n" /* line 124 */
        "movss 0x20(%ecx), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "addl 0x65c(%edx), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00011033\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_0001156b\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001144c\n"
        ".Lf10a4a_00011033:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00011035:\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 877 */
        "ucomiss 0x58(%ebx, %eax, 4), %xmm0\n" /* TexID */
        "jp .Lf10a4a_0001134b\n"
        "jne .Lf10a4a_0001134b\n"
        ".Lf10a4a_0001104b:\n"
        "movl -0x34(%ebp), %eax\n" /* line 63 | this */
        "movss %xmm0, 0x20(%eax)\n"
        /* } scope */
        ".Lf10a4a_00011053:\n"
        "addl $0x5c, %esp\n" /* line 1198 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf10a4a_0001105b:\n"
        "movl %edx, %eax\n"
        "jmp .Lf10a4a_00010f53\n"
        /* { scope 1: this, Value */
        /* { scope 2 */
        ".Lf10a4a_00011062:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 189 */
        /* } scope */
        "movl (%eax), %ecx\n" /* line 1096 */
        "subl $1, %ecx\n"
        "movl %ecx, -0x38(%ebp)\n" /* LastLevel */
        "jns .Lf10a4a_00010d94\n"
        ".Lf10a4a_00011073:\n"
        "movl $0, -0x38(%ebp)\n" /* LastLevel */
        "movl $0, -0x2c(%ebp)\n"
        "jmp .Lf10a4a_00010d97\n"
        ".Lf10a4a_00011086:\n"
        "movl -0x54(%ebp), %edx\n" /* line 1054 */
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexBorderColor\n"
        "movl -0x54(%ebp), %edx\n" /* line 59 */
        "movl 0x28(%edx), %eax\n"
        "movl -0x34(%ebp), %ecx\n" /* this */
        "movl %eax, 0x10(%ecx)\n"
        "jmp .Lf10a4a_00010d4d\n"
        /* { scope 2 */
        ".Lf10a4a_000110bc:\n"
        "movl $4, (%esp)\n" /* line 564 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* TexID */
        "movl %eax, 4(%esp)\n" /* line 565 */
        "movl $1, (%esp)\n"
        "calll glGenTextures\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %esi\n" /* line 597 */
        "addl $0x66c, %esi\n"
        /* { scope 3 */
        "movl $0xc, (%esp)\n" /* line 88 */
        "calll __Znwm\n"
        "movl %ebx, 8(%eax)\n" /* line 104 */
        "movl %esi, 4(%esp)\n" /* line 1152 */
        "movl %eax, (%esp)\n"
        "calll __ZNSt15_List_node_base4hookEPS_\n"
        "movl -0x50(%ebp), %eax\n" /* line 117 | pOGLTexInfo */
        "movl $0x3f800000, 0x24(%eax)\n"
        "movl $0x3e8, 0x20(%eax)\n"
        "movl $0x2601, 0x1c(%eax)\n"
        "movl $0x2702, 0x18(%eax)\n"
        "movl $0, 0x14(%eax)\n"
        "movl $0x2901, 0x10(%eax)\n"
        "movl $0x2901, 0xc(%eax)\n"
        "movl $0x2901, 8(%eax)\n"
        "movl %ebx, 4(%eax)\n"
        "movl $1, %ebx\n"
        "jmp .Lf10a4a_00010ab0\n"
        /* } scope */
        /* } scope */
        ".Lf10a4a_00011149:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 914 | pTex */
        "movl %ecx, -0x4c(%ebp)\n" /* p2DTexture */
        "movl %ecx, %eax\n" /* line 915 */
        "addl $4, %eax\n"
        "movl %eax, -0x50(%ebp)\n" /* pOGLTexInfo */
        "movl $0, -0x48(%ebp)\n" /* pVolumeTexture */
        "movl $0, -0x44(%ebp)\n" /* pCubeTexture */
        "movl $0xde1, -0x40(%ebp)\n" /* Target */
        "movl %eax, %ecx\n"
        "jmp .Lf10a4a_00010aa1\n"
        ".Lf10a4a_00011173:\n"
        "movl -0x4c(%ebp), %ecx\n" /* line 343 | p2DTexture */
        "movl 0x5c(%ecx), %edx\n"
        "movl 0x60(%ecx), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 73 */
        "sarl $2, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf10a4a_000115a7\n"
        ".Lf10a4a_00011189:\n"
        "testb %bl, %bl\n" /* line 953 | RecreateTextureData */
        "je .Lf10a4a_00010aed\n"
        ".Lf10a4a_00011191:\n"
        "movl 0x10(%ebp), %eax\n" /* line 955 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movzbl %bl, %eax\n" /* line 956 | RecreateTextureData */
        "movl %eax, 4(%esp)\n"
        "movl -0x4c(%ebp), %edx\n" /* p2DTexture */
        "movl %edx, (%esp)\n"
        "calll CDirect3DTexture_UpdateOpenGLSurfaces\n"
        "jmp .Lf10a4a_00010aed\n"
        ".Lf10a4a_000111bc:\n"
        "movb $0, -0x39(%ebp)\n" /* line 987 | UsesBorderColor */
        "movl $0x2901, %ebx\n" /* togl */
        "jmp .Lf10a4a_00010b2f\n"
        ".Lf10a4a_000111ca:\n"
        "movl $0x2901, %ebx\n" /* line 1009 | togl */
        "jmp .Lf10a4a_00010bf8\n"
        ".Lf10a4a_000111d4:\n"
        "movl $0x2901, %ebx\n" /* line 1031 | togl */
        "jmp .Lf10a4a_00010caf\n"
        ".Lf10a4a_000111de:\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "addl 0x65c(%edx), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_0001120f\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_000115fd\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000115c8\n"
        ".Lf10a4a_0001120f:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00011211:\n"
        "cmpl $0x2600, 0x40(%ebx, %eax, 4)\n" /* line 846 | TexID */
        "je .Lf10a4a_00011277\n"
        "movl 0x10(%ebp), %ecx\n" /* line 848 | Stage */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0x2600, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* Target */
        "movl %edx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_0001126d\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011611\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000115dc\n"
        ".Lf10a4a_0001126d:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_0001126f:\n"
        "movl $0x2600, 0x40(%ebx, %eax, 4)\n" /* line 169 */
        ".Lf10a4a_00011277:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 60 | this */
        "movl $0x2600, 0x14(%ecx)\n"
        "jmp .Lf10a4a_00010f13\n"
        ".Lf10a4a_00011286:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00010f80\n"
        ".Lf10a4a_00011290:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010ce2\n"
        ".Lf10a4a_0001129a:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010de3\n"
        ".Lf10a4a_000112a4:\n"
        "movl 0xc(%ebp), %edx\n" /* line 920 | pTex */
        "movl %edx, -0x48(%ebp)\n" /* pVolumeTexture */
        "movl %edx, %ecx\n" /* line 921 */
        "addl $4, %ecx\n"
        "movl %ecx, -0x50(%ebp)\n" /* pOGLTexInfo */
        "movl $0, -0x4c(%ebp)\n" /* p2DTexture */
        "movl $0, -0x44(%ebp)\n" /* pCubeTexture */
        "movl $0x806f, -0x40(%ebp)\n" /* Target */
        "jmp .Lf10a4a_00010aa1\n"
        ".Lf10a4a_000112cc:\n"
        "movl $0x812f, %ebx\n" /* line 1035 | togl */
        "jmp .Lf10a4a_00010caf\n"
        ".Lf10a4a_000112d6:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00010b6e\n"
        ".Lf10a4a_000112e0:\n"
        "movl -0x48(%ebp), %ecx\n" /* line 343 | pVolumeTexture */
        "movl 0x60(%ecx), %edx\n"
        "movl 0x64(%ecx), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 96 */
        "sarl $2, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf10a4a_00011488\n"
        ".Lf10a4a_000112f6:\n"
        "testb %bl, %bl\n" /* line 962 | RecreateTextureData */
        "je .Lf10a4a_00010aed\n"
        ".Lf10a4a_000112fe:\n"
        "movl 0x10(%ebp), %eax\n" /* line 964 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movzbl %bl, %eax\n" /* line 965 | RecreateTextureData */
        "movl %eax, 4(%esp)\n"
        "movl -0x48(%ebp), %edx\n" /* pVolumeTexture */
        "movl %edx, (%esp)\n"
        "calll CDirect3DVolumeTexture_UpdateOpenGLSurfaces\n"
        "jmp .Lf10a4a_00010aed\n"
        ".Lf10a4a_00011329:\n"
        "movl $0x812f, %ebx\n" /* line 1013 | togl */
        "jmp .Lf10a4a_00010bf8\n"
        ".Lf10a4a_00011333:\n"
        "movb $0, -0x39(%ebp)\n" /* line 991 | UsesBorderColor */
        "movl $0x812f, %ebx\n" /* togl */
        "jmp .Lf10a4a_00010b2f\n"
        ".Lf10a4a_00011341:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00010c2b\n"
        ".Lf10a4a_0001134b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 879 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 171 */
        "movss %xmm0, 8(%esp)\n"
        "movl $0x84fe, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* Target */
        "movl %eax, (%esp)\n"
        "calll glTexParameterf\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_000113a1\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011607\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000115d2\n"
        ".Lf10a4a_000113a1:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_000113a3:\n"
        "movss -0x58(%ebp), %xmm0\n" /* line 171 */
        "movss %xmm0, 0x58(%ebx, %eax, 4)\n"
        "movl -0x54(%ebp), %eax\n"
        "movss 0x20(%eax), %xmm0\n"
        "movss %xmm0, -0x58(%ebp)\n"
        "jmp .Lf10a4a_0001104b\n"
        ".Lf10a4a_000113c0:\n"
        "movl $0x2600, %ebx\n" /* line 1113 | togl */
        "jmp .Lf10a4a_00010db0\n"
        ".Lf10a4a_000113ca:\n"
        "movl 0xc(%ebp), %eax\n" /* line 926 | pTex */
        "movl %eax, -0x44(%ebp)\n" /* pCubeTexture */
        "movl %eax, %edx\n" /* line 927 */
        "addl $4, %edx\n"
        "movl %edx, -0x50(%ebp)\n" /* pOGLTexInfo */
        "movl $0, -0x4c(%ebp)\n" /* p2DTexture */
        "movl $0, -0x48(%ebp)\n" /* pVolumeTexture */
        "movl $0x8513, -0x40(%ebp)\n" /* Target */
        "movl %edx, %ecx\n"
        "jmp .Lf10a4a_00010aa1\n"
        ".Lf10a4a_000113f4:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00010de3\n"
        ".Lf10a4a_000113fe:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010f80\n"
        ".Lf10a4a_00011408:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010ce2\n"
        ".Lf10a4a_00011412:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010c2b\n"
        ".Lf10a4a_0001141c:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010b6e\n"
        ".Lf10a4a_00011426:\n"
        "xorl %ecx, %ecx\n" /* line 1070 */
        ".Lf10a4a_00011428:\n"
        "shrl $1, %edx\n" /* line 1089 */
        "addl $1, %ecx\n" /* line 1067 */
        "shrl $1, %eax\n"
        "je .Lf10a4a_0001143b\n"
        "cmpl $3, %eax\n" /* line 1070 */
        "jbe .Lf10a4a_0001143b\n"
        "cmpl $3, %edx\n"
        "ja .Lf10a4a_00011428\n"
        ".Lf10a4a_0001143b:\n"
        "movl %ecx, %ebx\n" /* togl */
        "jmp .Lf10a4a_00010d6a\n"
        ".Lf10a4a_00011442:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00010ea2\n"
        ".Lf10a4a_0001144c:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00011035\n"
        ".Lf10a4a_00011456:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010bc5\n"
        ".Lf10a4a_00011460:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010e3a\n"
        ".Lf10a4a_0001146a:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010c82\n"
        ".Lf10a4a_00011474:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010fdc\n"
        ".Lf10a4a_0001147e:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_00010d39\n"
        ".Lf10a4a_00011488:\n"
        "movl (%edx), %eax\n" /* line 98 */
        "movl %eax, (%esp)\n"
        "calll CDirect3DVolume_IsDirty\n"
        "testb %al, %al\n" /* line 962 */
        "jne .Lf10a4a_000112fe\n"
        "jmp .Lf10a4a_000112f6\n"
        ".Lf10a4a_0001149f:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00010f01\n"
        ".Lf10a4a_000114a9:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00010ea2\n"
        ".Lf10a4a_000114b3:\n"
        "movl 0x10(%ebp), %eax\n" /* line 890 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        /* { scope 2 */
        "movss -0x30(%ebp), %xmm0\n" /* line 194 | Value */
        "movss %xmm0, 8(%esp)\n"
        "movl $0x8501, 4(%esp)\n"
        "movl $0x8500, (%esp)\n"
        "calll glTexEnvf\n"
        "movss -0x30(%ebp), %xmm0\n" /* Value */
        "movss %xmm0, 0xc0(%ebx)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "jmp .Lf10a4a_00010f53\n"
        /* } scope */
        ".Lf10a4a_000114f8:\n"
        "movb $1, -0x39(%ebp)\n" /* line 995 | UsesBorderColor */
        "movl $0x812d, %ebx\n" /* togl */
        "jmp .Lf10a4a_00010b2f\n"
        ".Lf10a4a_00011506:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 343 | pCubeTexture */
        "movl 0x70(%ecx), %edx\n"
        "movl 0x74(%ecx), %eax\n" /* line 361 */
        "subl %edx, %eax\n" /* line 86 */
        "sarl $2, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lf10a4a_000115e6\n"
        ".Lf10a4a_0001151c:\n"
        "testb %bl, %bl\n" /* line 970 | RecreateTextureData */
        "je .Lf10a4a_00010aed\n"
        ".Lf10a4a_00011524:\n"
        "movl 0x10(%ebp), %eax\n" /* line 972 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movzbl %bl, %eax\n" /* line 973 | RecreateTextureData */
        "movl %eax, 4(%esp)\n"
        "movl -0x44(%ebp), %edx\n" /* pCubeTexture */
        "movl %edx, (%esp)\n"
        "calll CDirect3DCubeTexture_UpdateOpenGLSurfaces\n"
        "jmp .Lf10a4a_00010aed\n"
        ".Lf10a4a_0001154f:\n"
        "movb $1, -0x39(%ebp)\n" /* line 1017 | UsesBorderColor */
        "movl $0x812d, %ebx\n" /* togl */
        "jmp .Lf10a4a_00010bf8\n"
        ".Lf10a4a_0001155d:\n"
        "movb $1, -0x39(%ebp)\n" /* line 1039 | UsesBorderColor */
        "movl $0x812d, %ebx\n" /* togl */
        "jmp .Lf10a4a_00010caf\n"
        ".Lf10a4a_0001156b:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00011035\n"
        ".Lf10a4a_00011575:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010e3a\n"
        ".Lf10a4a_0001157f:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010c82\n"
        ".Lf10a4a_00011589:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010bc5\n"
        ".Lf10a4a_00011593:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010d39\n"
        ".Lf10a4a_0001159d:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_00010fdc\n"
        ".Lf10a4a_000115a7:\n"
        "movl (%edx), %eax\n" /* line 76 */
        "movl %eax, (%esp)\n"
        "calll CDirect3DSurface_IsDirty\n"
        "testb %al, %al\n" /* line 953 */
        "jne .Lf10a4a_00011191\n"
        "jmp .Lf10a4a_00011189\n"
        ".Lf10a4a_000115be:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00010f01\n"
        ".Lf10a4a_000115c8:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00011211\n"
        ".Lf10a4a_000115d2:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_000113a3\n"
        ".Lf10a4a_000115dc:\n"
        "movl $2, %eax\n"
        "jmp .Lf10a4a_0001126f\n"
        ".Lf10a4a_000115e6:\n"
        "movl (%edx), %eax\n" /* line 88 */
        "movl %eax, (%esp)\n"
        "calll CDirect3DSurface_IsDirty\n"
        "testb %al, %al\n" /* line 970 */
        "jne .Lf10a4a_00011524\n"
        "jmp .Lf10a4a_0001151c\n"
        ".Lf10a4a_000115fd:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00011211\n"
        ".Lf10a4a_00011607:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_000113a3\n"
        ".Lf10a4a_00011611:\n"
        "movl $1, %eax\n"
        "jmp .Lf10a4a_0001126f\n"
        ".Lf10a4a_0001161b:\n"
        "cmpl $1, %ecx\n" /* line 1134 */
        "je .Lf10a4a_00011636\n"
        "cmpl $2, %ecx\n"
        "je .Lf10a4a_00011796\n"
        "testl %ecx, %ecx\n"
        "jne .Lf10a4a_00010f13\n"
        "jmp .Lf10a4a_00010e67\n"
        ".Lf10a4a_00011636:\n"
        "cmpl $1, %edx\n" /* line 1150 */
        "jbe .Lf10a4a_000116ed\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "addl 0x65c(%edx), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00011670\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011928\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001191e\n"
        ".Lf10a4a_00011670:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00011672:\n"
        "cmpl $0x2702, 0x40(%ebx, %eax, 4)\n" /* line 846 | TexID */
        "je .Lf10a4a_000116d0\n"
        "movl 0x10(%ebp), %ecx\n" /* line 848 | Stage */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0x2702, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl -0x40(%ebp), %edx\n" /* Target */
        "movl %edx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_000116c6\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_000116e6\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000116df\n"
        ".Lf10a4a_000116c6:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_000116c8:\n"
        "movl $0x2702, 0x40(%ebx, %eax, 4)\n" /* line 169 */
        ".Lf10a4a_000116d0:\n"
        "movl -0x34(%ebp), %ecx\n" /* line 60 | this */
        "movl $0x2702, 0x14(%ecx)\n"
        "jmp .Lf10a4a_00010f13\n"
        ".Lf10a4a_000116df:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_000116c8\n"
        ".Lf10a4a_000116e6:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_000116c8\n"
        ".Lf10a4a_000116ed:\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_0001171e\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_0001193c\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011932\n"
        ".Lf10a4a_0001171e:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00011720:\n"
        "cmpl $0x2700, 0x40(%ebx, %eax, 4)\n" /* line 846 | TexID */
        "je .Lf10a4a_00011787\n"
        "movl 0x10(%ebp), %eax\n" /* line 848 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0x2700, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_0001177d\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011950\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_00011946\n"
        ".Lf10a4a_0001177d:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_0001177f:\n"
        "movl $0x2700, 0x40(%ebx, %eax, 4)\n" /* line 169 */
        ".Lf10a4a_00011787:\n"
        "movl -0x34(%ebp), %eax\n" /* line 60 | this */
        "movl $0x2700, 0x14(%eax)\n"
        "jmp .Lf10a4a_00010f13\n"
        ".Lf10a4a_00011796:\n"
        "cmpl $1, %edx\n" /* line 1163 */
        "jbe .Lf10a4a_00011848\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_000117d0\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011964\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001195a\n"
        ".Lf10a4a_000117d0:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_000117d2:\n"
        "cmpl $0x2703, 0x40(%ebx, %eax, 4)\n" /* line 846 | TexID */
        "je .Lf10a4a_00011839\n"
        "movl 0x10(%ebp), %eax\n" /* line 848 | Stage */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0x2703, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl -0x40(%ebp), %ecx\n" /* Target */
        "movl %ecx, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_0001182f\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011900\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000118f6\n"
        ".Lf10a4a_0001182f:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_00011831:\n"
        "movl $0x2703, 0x40(%ebx, %eax, 4)\n" /* line 169 */
        ".Lf10a4a_00011839:\n"
        "movl -0x34(%ebp), %eax\n" /* line 60 | this */
        "movl $0x2703, 0x14(%eax)\n"
        "jmp .Lf10a4a_00010f13\n"
        ".Lf10a4a_00011848:\n"
        "movl %esi, %ebx\n" /* line 654 | TexID */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "addl 0x65c(%eax), %ebx\n" /* TexID */
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_00011878\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_00011914\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_0001190a\n"
        ".Lf10a4a_00011878:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_0001187a:\n"
        "cmpl $0x2701, 0x40(%ebx, %eax, 4)\n" /* line 846 | TexID */
        "je .Lf10a4a_000118d9\n"
        "movl 0x10(%ebp), %edx\n" /* line 848 | Stage */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl $0x2701, 8(%esp)\n" /* line 169 */
        "movl $0x2801, 4(%esp)\n"
        "movl -0x40(%ebp), %eax\n" /* Target */
        "movl %eax, (%esp)\n"
        "calll glTexParameteri\n"
        "cmpl $0xde1, -0x40(%ebp)\n" /* line 87 | Target */
        "je .Lf10a4a_000118cf\n"
        "cmpl $0x806f, -0x40(%ebp)\n" /* line 91 | Target */
        "je .Lf10a4a_000118ef\n"
        "cmpl $0x8513, -0x40(%ebp)\n" /* line 95 | Target */
        "je .Lf10a4a_000118e8\n"
        ".Lf10a4a_000118cf:\n"
        "xorl %eax, %eax\n"
        ".Lf10a4a_000118d1:\n"
        "movl $0x2701, 0x40(%ebx, %eax, 4)\n" /* line 169 */
        ".Lf10a4a_000118d9:\n"
        "movl -0x34(%ebp), %edx\n" /* line 60 | this */
        "movl $0x2701, 0x14(%edx)\n"
        "jmp .Lf10a4a_00010f13\n"
        ".Lf10a4a_000118e8:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_000118d1\n"
        ".Lf10a4a_000118ef:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_000118d1\n"
        ".Lf10a4a_000118f6:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00011831\n"
        ".Lf10a4a_00011900:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00011831\n"
        ".Lf10a4a_0001190a:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_0001187a\n"
        ".Lf10a4a_00011914:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_0001187a\n"
        ".Lf10a4a_0001191e:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00011672\n"
        ".Lf10a4a_00011928:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00011672\n"
        ".Lf10a4a_00011932:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_00011720\n"
        ".Lf10a4a_0001193c:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_00011720\n"
        ".Lf10a4a_00011946:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_0001177f\n"
        ".Lf10a4a_00011950:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_0001177f\n"
        ".Lf10a4a_0001195a:\n"
        "movl $2, %eax\n" /* line 95 */
        "jmp .Lf10a4a_000117d2\n"
        ".Lf10a4a_00011964:\n"
        "movl $1, %eax\n" /* line 91 */
        "jmp .Lf10a4a_000117d2\n"
    );
}

/* line 1203 */
__attribute__((naked))
void CDirect3DDevice_ValidateRasterization(const CDirect3DDevice * _this, UINT32 StartVertex, UINT32 EndVertex)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1203 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        /* { scope 1: IsFixedFunctionStage, Source0, Source1, Source2, ... */
        "movb $0, -0x19(%ebp)\n" /* line 1209 | UsesTexFactor */
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 332 */
        "movl 0x818(%ebx), %ecx\n"
        "movl 8(%ebp), %eax\n" /* line 1213 | this */
        "movl 0xbb8(%eax), %edx\n"
        "cmpl %edx, %ecx\n"
        "je .Lf1196e_00011ec7\n"
        "testl %edx, %edx\n" /* line 1215 */
        "je .Lf1196e_00011a26\n"
        "movl (%edx), %eax\n" /* line 1225 */
        "movl %edx, (%esp)\n"
        "calll *0x1c(%eax)\n"
        "movl 8(%ebp), %edx\n" /* line 345 | this */
        "movl 0xbb8(%edx), %eax\n"
        "movl %eax, 0x818(%ebx)\n"
        "movl %edx, %ecx\n"
        ".Lf1196e_000119bc:\n"
        "movl 0xbb8(%ecx), %edx\n" /* line 1237 */
        "testl %edx, %edx\n"
        "je .Lf1196e_00011a4a\n"
        ".Lf1196e_000119ca:\n"
        "movl %ecx, %ebx\n" /* rgba */
        "movb $0, -0x19(%ebp)\n" /* line 1239 | UsesTexFactor */
        "movl 0xbb8(%ecx), %eax\n" /* line 44 */
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x58(%ebp)\n" /* TextureUseMask */
        "movl %ecx, %eax\n"
        "movl %ebx, %esi\n"
        "addl $0x504, %eax\n"
        "addl $0x508, %ecx\n"
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        "movl 0x504(%esi), %edx\n" /* line 211 */
        "cmpl 0x508(%esi), %edx\n"
        "cmovbl %ecx, %eax\n"
        /* } scope */
        "movl (%eax), %eax\n" /* line 1244 | __b */
        "movl %eax, -0x50(%ebp)\n" /* __b, TotalUnits */
        "testl %eax, %eax\n" /* line 1245 */
        "jne .Lf1196e_00011a7d\n"
        ".Lf1196e_00011a03:\n"
        "movl $0, -0x54(%ebp)\n" /* i */
        ".Lf1196e_00011a0a:\n"
        "movl 8(%ebp), %esi\n" /* line 1628 | this, UsesTexNormalMap */
        "movl 0xbb8(%esi), %eax\n" /* UsesTexNormalMap */
        "testl %eax, %eax\n"
        "je .Lf1196e_00011e3e\n"
        /* } scope */
        ".Lf1196e_00011a1b:\n"
        "addl $0x8c, %esp\n" /* line 1648 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: IsFixedFunctionStage, Source0, Source1, Source2, ... */
        ".Lf1196e_00011a26:\n"
        "cmpl $-1, %ecx\n" /* line 1217 */
        "je .Lf1196e_00011a33\n"
        "movl (%ecx), %eax\n" /* line 1219 */
        "movl %ecx, (%esp)\n"
        "calll *0x20(%eax)\n"
        ".Lf1196e_00011a33:\n"
        "movl $0, 0x818(%ebx)\n" /* line 345 */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xbb8(%ecx), %edx\n" /* line 1237 */
        "testl %edx, %edx\n"
        "jne .Lf1196e_000119ca\n"
        ".Lf1196e_00011a4a:\n"
        "movl $0, -0x58(%ebp)\n" /* TextureUseMask */
        "movl 8(%ebp), %eax\n" /* this */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 8(%ebp), %esi\n" /* this */
        "addl $0x504, %eax\n" /* line 44 */
        "addl $0x508, %ecx\n"
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        "movl 0x504(%esi), %edx\n" /* line 211 */
        "cmpl 0x508(%esi), %edx\n"
        "cmovbl %ecx, %eax\n"
        /* } scope */
        "movl (%eax), %eax\n" /* line 1244 | __b */
        "movl %eax, -0x50(%ebp)\n" /* __b, TotalUnits */
        "testl %eax, %eax\n" /* line 1245 */
        "je .Lf1196e_00011a03\n"
        ".Lf1196e_00011a7d:\n"
        "movl $0, -0x54(%ebp)\n" /* i */
        "movl $0, -0x40(%ebp)\n"
        "movl $0, -0x3c(%ebp)\n"
        "jmp .Lf1196e_00011ac3\n"
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        ".Lf1196e_00011a94:\n"
        "movl 8(%ebp), %ebx\n" /* line 1607 | this, ModulateFactor */
        "movl 0xbb8(%ebx), %eax\n" /* ModulateFactor */
        "testl %eax, %eax\n"
        "je .Lf1196e_00011cb9\n"
        /* } scope */
        ".Lf1196e_00011aa5:\n"
        "addl $1, -0x54(%ebp)\n" /* line 1245 | i */
        "addl $0xa4, -0x40(%ebp)\n"
        "addl $0x130, -0x3c(%ebp)\n"
        "movl -0x54(%ebp), %ebx\n" /* i, rgba */
        "cmpl %ebx, -0x50(%ebp)\n" /* rgba, TotalUnits */
        "je .Lf1196e_00011a0a\n"
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        ".Lf1196e_00011ac3:\n"
        "movl -0x40(%ebp), %edx\n" /* line 654 */
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x608(%eax), %edx\n"
        "movl %edx, -0x60(%ebp)\n"
        "movzbl (%edx), %ecx\n" /* line 1248 */
        "xorb $1, %cl\n"
        "movb %cl, -0x4b(%ebp)\n" /* IsFixedFunctionStage */
        "movl 0xbb8(%eax), %eax\n" /* line 1250 */
        "testl %eax, %eax\n"
        "je .Lf1196e_00011b80\n"
        "movl $1, %eax\n" /* line 1260 */
        "movzbl -0x54(%ebp), %ecx\n" /* i */
        "shll %cl, %eax\n"
        "testl %eax, -0x58(%ebp)\n" /* TextureUseMask */
        "setne -0x59(%ebp)\n" /* UsesTexture */
        "movl 8(%ebp), %ebx\n" /* line 1263 | this, rgba */
        "movl 0xbb4(%ebx), %eax\n" /* rgba */
        "testl %eax, %eax\n"
        "je .Lf1196e_00011bad\n"
        ".Lf1196e_00011b0c:\n"
        "movl $0, -0x34(%ebp)\n" /* line 1414 | Source2 */
        "movl $0, -0x24(%ebp)\n" /* Source1 */
        "movl $0, -0x20(%ebp)\n" /* Source0 */
        "movl $0, -0x30(%ebp)\n" /* line 1415 | Param2 */
        "movl $0, -0x2c(%ebp)\n" /* Param1 */
        "movl $0, -0x28(%ebp)\n" /* Param0 */
        "cmpb $0, -0x4b(%ebp)\n" /* line 1417 | IsFixedFunctionStage */
        "je .Lf1196e_00011b4d\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xbb8(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1196e_00011e1b\n"
        ".Lf1196e_00011b4d:\n"
        "movl -0x60(%ebp), %ecx\n" /* line 103 */
        "movl 4(%ecx), %eax\n"
        "testl %eax, %eax\n" /* line 1593 */
        "je .Lf1196e_00011c78\n"
        "cmpb $0, -0x59(%ebp)\n" /* UsesTexture */
        "je .Lf1196e_00011a94\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1597 | i, ModulateFactor */
        "movl %ebx, 8(%esp)\n" /* ModulateFactor */
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %esi\n" /* this, UsesTexNormalMap */
        "movl %esi, (%esp)\n" /* UsesTexNormalMap */
        "calll CDirect3DDevice_SynchronizeD3DAndOpenGLTextureState\n"
        "jmp .Lf1196e_00011aa5\n"
        ".Lf1196e_00011b80:\n"
        "cmpl $1, 0x2c(%edx)\n" /* line 1252 */
        "je .Lf1196e_00011a0a\n"
        "leal -0x19(%ebp), %eax\n" /* line 1256 | UsesTexFactor */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CDirect3DDevice_CTexStage_GetUsesTexture\n"
        "movb %al, -0x59(%ebp)\n" /* UsesTexture */
        "movl 8(%ebp), %ebx\n" /* line 1263 | this, rgba */
        "movl 0xbb4(%ebx), %eax\n" /* rgba */
        "testl %eax, %eax\n"
        "jne .Lf1196e_00011b0c\n"
        /* { scope 3: pRGBA */
        ".Lf1196e_00011bad:\n"
        "cmpb $0, -0x59(%ebp)\n" /* line 1274 | UsesTexture */
        "je .Lf1196e_00011dd2\n"
        /* { scope 4: pSrc2Coords */
        "movl -0x60(%ebp), %esi\n" /* line 1276 | UsesTexNormalMap */
        "movl 0x50(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, %ebx\n" /* line 1285 | Tci */
        "andl $0xffff0000, %ebx\n" /* Tci */
        "je .Lf1196e_00011f15\n"
        /* { scope 5 */
        "cmpl $0x10000, %ebx\n" /* line 1338 | Tci */
        "je .Lf1196e_000129c3\n"
        "cmpl $0x20000, %ebx\n" /* line 1356 | Tci */
        "je .Lf1196e_00012966\n"
        "cmpl $0x30000, %ebx\n" /* line 1364 | Tci */
        "je .Lf1196e_0001298f\n"
        "movb $0, -0x4a(%ebp)\n" /* UsesTexCoordStream */
        "xorl %edi, %edi\n" /* UsesTexGen */
        "movb $0, -0x49(%ebp)\n" /* UsesTexReflection */
        "xorl %esi, %esi\n" /* UsesTexNormalMap */
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "movl $0, -0x48(%ebp)\n" /* pSrc2Coords */
        "xorl %ecx, %ecx\n"
        ".Lf1196e_00011c08:\n"
        "movl %ecx, 0x2c(%esp)\n" /* line 1392 */
        "movl -0x48(%ebp), %ecx\n" /* pSrc2Coords */
        "movl %ecx, 0x28(%esp)\n"
        "movl %eax, 0x24(%esp)\n"
        "movl %edx, 0x20(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* EndVertex */
        "movl %eax, 0x1c(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* StartVertex */
        "movl %edx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n" /* Tci */
        "movl $0, 0x10(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "addl $0x64, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x60(%ebp), %ecx\n"
        "movl 0x4c(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x54(%ebp), %ebx\n" /* i, Tci */
        "movl %ebx, 4(%esp)\n" /* Tci */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll CDirect3DDevice_SetTextureCoordStream\n"
        /* } scope */
        /* } scope */
        "cmpb $0, -0x4a(%ebp)\n" /* line 1396 | UsesTexCoordStream */
        "je .Lf1196e_00011dda\n"
        "movl %esi, %edx\n" /* UsesTexNormalMap */
        "movzbl %dl, %ecx\n"
        "movzbl -0x49(%ebp), %edx\n" /* UsesTexReflection */
        "movl %edi, %ebx\n" /* UsesTexGen, Tci */
        "movzbl %bl, %eax\n" /* Tci */
        "jmp .Lf1196e_00011df6\n"
        /* } scope */
        ".Lf1196e_00011c78:\n"
        "movl 8(%ebp), %edx\n" /* line 1604 | this */
        "movl 0xf0(%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1196e_00011c88\n"
        "addl $4, %eax\n"
        ".Lf1196e_00011c88:\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0xde1, 8(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTex\n"
        "movl 8(%ebp), %ebx\n" /* line 1607 | this, ModulateFactor */
        "movl 0xbb8(%ebx), %eax\n" /* ModulateFactor */
        "testl %eax, %eax\n"
        "jne .Lf1196e_00011aa5\n"
        ".Lf1196e_00011cb9:\n"
        "cmpb $0, -0x59(%ebp)\n" /* line 1609 | UsesTexture */
        "je .Lf1196e_00011aa5\n"
        "cmpb $0, -0x4b(%ebp)\n" /* line 1611 | IsFixedFunctionStage */
        "je .Lf1196e_00011aa5\n"
        "movl -0x60(%ebp), %esi\n" /* line 1613 | UsesTexNormalMap */
        "movl 0x34(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "cmpl $0x1702, -0x24(%ebp)\n" /* line 1614 | Source1 */
        "jne .Lf1196e_00011aa5\n"
        "movl 0xf0(%ebx), %eax\n" /* line 1617 | ModulateFactor */
        "testl %eax, %eax\n"
        "je .Lf1196e_00011d03\n"
        "addl $4, %eax\n"
        ".Lf1196e_00011d03:\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0xde1, 8(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* ModulateFactor */
        "movl %ebx, (%esp)\n" /* ModulateFactor */
        "calll COpenGL_SetTex\n"
        "movl $0x3f800000, %esi\n" /* line 1619 | UsesTexNormalMap */
        "movl %esi, 0x14(%esp)\n" /* UsesTexNormalMap */
        "movl $0x300, 0x10(%esp)\n"
        "movl $0x8578, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %edx\n" /* i */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ModulateFactor */
        "calll COpenGL_SetTexCombinerRGB1\n"
        "movl %esi, 0x14(%esp)\n" /* line 1620 | UsesTexNormalMap */
        "movl $0x302, 0x10(%esp)\n"
        "movl $0x8578, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* ModulateFactor */
        "calll COpenGL_SetTexCombinerAlpha1\n"
        "jmp .Lf1196e_00011aa5\n"
        /* { scope 3: pRGBA */
        /* { scope 4: pSrc2Coords */
        /* { scope 5 */
        ".Lf1196e_00011d84:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1321 | i, Tci */
        "movl %ebx, 4(%esp)\n" /* Tci */
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* Tci */
        "movl %ebx, (%esp)\n" /* Tci */
        "calll COpenGL_SetActiveTexUnit\n"
        "cmpl $0x1702, 0x74(%ebx)\n" /* line 427 */
        "je .Lf1196e_00011db5\n"
        "movl $0x1702, 0x74(%ebx)\n" /* line 429 */
        "movl $0x1702, (%esp)\n" /* line 430 */
        "calll glMatrixMode\n"
        ".Lf1196e_00011db5:\n"
        "calll glPushMatrix\n" /* line 1323 */
        "calll glLoadIdentity\n" /* line 1324 */
        "xorl %eax, %eax\n" /* line 1325 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glTexCoord2f\n"
        "calll glPopMatrix\n" /* line 1326 */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1196e_00011dd2:\n"
        "xorl %edi, %edi\n" /* line 1631 | UsesTexGen */
        "movb $0, -0x49(%ebp)\n" /* UsesTexReflection */
        "xorl %esi, %esi\n" /* UsesTexNormalMap */
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        /* { scope 3: pRGBA */
        ".Lf1196e_00011dda:\n"
        "movl imp___ZN10CVAOPacket10sVAOStatusE, %eax\n" /* line 1399 */
        "cmpl $3, (%eax)\n"
        "jne .Lf1196e_00011ece\n"
        "movl %esi, %eax\n" /* UsesTexNormalMap */
        "movzbl %al, %ecx\n"
        "movzbl -0x49(%ebp), %edx\n" /* UsesTexReflection */
        "movl %edi, %ebx\n" /* UsesTexGen, Tci */
        "movzbl %bl, %eax\n" /* Tci */
        ".Lf1196e_00011df6:\n"
        "movl %ecx, 0x10(%esp)\n" /* line 1408 */
        "movl %edx, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x54(%ebp), %esi\n" /* i, UsesTexNormalMap */
        "movl %esi, 4(%esp)\n" /* UsesTexNormalMap */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexGenEnable\n"
        "jmp .Lf1196e_00011b0c\n"
        /* } scope */
        /* { scope 3: pRGBA */
        ".Lf1196e_00011e1b:\n"
        "movl -0x60(%ebp), %edx\n" /* line 1422 */
        "cmpl $0x1a, 0x2c(%edx)\n"
        "jbe .Lf1196e_00011fb6\n"
        "movl %edx, %esi\n" /* UsesTexNormalMap */
        ".Lf1196e_00011e2a:\n"
        "cmpl $0xc, 0x3c(%esi)\n" /* line 1538 | UsesTexNormalMap */
        "ja .Lf1196e_00012038\n"
        "movl 0x3c(%esi), %eax\n" /* UsesTexNormalMap */
        "jmpl *.Ljt_2ede60(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ede60:\n"
        ".long .Lf1196e_00012038\n"
        ".long .Lf1196e_000120dc\n"
        ".long .Lf1196e_00012115\n"
        ".long .Lf1196e_00012168\n"
        ".long .Lf1196e_000121bb\n"
        ".long .Lf1196e_00011fc0\n"
        ".long .Lf1196e_00012038\n"
        ".long .Lf1196e_00012235\n"
        ".long .Lf1196e_00012038\n"
        ".long .Lf1196e_00012038\n"
        ".long .Lf1196e_00012038\n"
        ".long .Lf1196e_00012038\n"
        ".long .Lf1196e_0001229e\n"
        ".popsection\n"
        /* } scope */
        /* } scope */
        ".Lf1196e_00011e3e:\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1631 | i */
        "movl 8(%ebp), %edx\n" /* this */
        "cmpl 0x504(%edx), %ecx\n"
        "jb .Lf1196e_00011eae\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1648 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: IsFixedFunctionStage, Source0, Source1, Source2, ... */
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        ".Lf1196e_00011e57:\n"
        "movl $0, 4(%esp)\n" /* line 163 */
        "movl -0x54(%ebp), %ecx\n" /* i */
        "leal (%ecx, %ecx, 2), %eax\n"
        "leal 0x70(%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        ".Lf1196e_00011e71:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1641 | i, ModulateFactor */
        "movl %ebx, 4(%esp)\n" /* ModulateFactor */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_DisableTexCoordArray\n"
        /* } scope */
        ".Lf1196e_00011e85:\n"
        "movl -0x54(%ebp), %esi\n" /* line 1643 | i, UsesTexNormalMap */
        "movl %esi, 4(%esp)\n" /* UsesTexNormalMap */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_DisableTexUnit\n"
        "addl $1, %esi\n" /* line 1631 | UsesTexNormalMap */
        "movl %esi, -0x54(%ebp)\n" /* UsesTexNormalMap, i */
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl 0x504(%eax), %esi\n" /* UsesTexNormalMap */
        "jae .Lf1196e_00011a1b\n"
        ".Lf1196e_00011eae:\n"
        "movl imp___ZN10CVAOPacket10sVAOStatusE, %eax\n" /* line 50 */
        "movl (%eax), %eax\n"
        "cmpl $3, %eax\n" /* line 1633 */
        "je .Lf1196e_00011e85\n"
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        "movl g_CurrentGenericPacket, %edx\n" /* line 1635 | GenericVAO */
        "subl $1, %eax\n" /* line 1637 */
        "jne .Lf1196e_00011e71\n"
        "jmp .Lf1196e_00011e57\n"
        ".Lf1196e_00011ec7:\n"
        "movl %eax, %ecx\n"
        "jmp .Lf1196e_000119bc\n"
        /* } scope */
        /* { scope 2: UsesTexCoordStream, UsesTexReflection */
        /* { scope 3: pRGBA */
        ".Lf1196e_00011ece:\n"
        "movl $0, 4(%esp)\n" /* line 163 */
        "movl -0x54(%ebp), %edx\n" /* i */
        "leal (%edx, %edx, 2), %eax\n"
        "movl g_CurrentGenericPacket, %edx\n"
        "leal 0x70(%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        "movl -0x54(%ebp), %ecx\n" /* line 1404 | i */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_DisableTexCoordArray\n"
        "movl %esi, %ebx\n" /* UsesTexNormalMap, Tci */
        "movzbl %bl, %ecx\n" /* Tci */
        "movzbl -0x49(%ebp), %edx\n" /* UsesTexReflection */
        "movl %edi, %ebx\n" /* UsesTexGen, Tci */
        "movzbl %bl, %eax\n" /* Tci */
        "jmp .Lf1196e_00011df6\n"
        /* { scope 4: pSrc2Coords */
        /* { scope 5 */
        ".Lf1196e_00011f15:\n"
        "movzwl %ax, %ecx\n" /* line 1289 | TexCoordStreamToUse */
        "movl 8(%ebp), %eax\n" /* line 1294 | this */
        "cmpb $0, 0x308(%ecx, %eax)\n"
        "je .Lf1196e_00011d84\n"
        /* { scope 6 */
        "movl %eax, %edx\n" /* line 1300 */
        "movl 0x310(%eax, %ecx, 4), %eax\n"
        "movl %edx, %ebx\n" /* line 1301 | Tci */
        "movl 0xac(%edx, %eax, 4), %edx\n"
        "movl $0, 0x2c(%esp)\n" /* line 1317 */
        "movl $0, 0x28(%esp)\n"
        "movl %edx, 0x24(%esp)\n"
        "movl 0x24(%ebx, %eax, 4), %eax\n" /* Tci */
        "movl 0x14(%eax), %eax\n"
        "addl 0x330(%ebx, %ecx, 4), %eax\n" /* Tci */
        "imull 0xc(%ebp), %edx\n" /* StartVertex */
        "addl %edx, %eax\n"
        "movl %eax, 0x20(%esp)\n"
        "movl 0x10(%ebp), %esi\n" /* EndVertex, UsesTexNormalMap */
        "movl %esi, 0x1c(%esp)\n" /* UsesTexNormalMap */
        "movl 0xc(%ebp), %eax\n" /* StartVertex */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl 0x350(%ebx, %ecx, 4), %eax\n" /* Tci */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x60(%ebp), %eax\n"
        "addl $0x64, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x60(%ebp), %edx\n"
        "movl 0x4c(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* Tci */
        "calll CDirect3DDevice_SetTextureCoordStream\n"
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1196e_00011df6\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3: pRGBA */
        ".Lf1196e_00011fb6:\n"
        "movl 0x2c(%edx), %eax\n" /* line 1422 */
        "jmpl *0x2ede94(, %eax, 4)\n"
        ".Lf1196e_00011fc0:\n"
        "movl -0x60(%ebp), %edx\n" /* line 1563 */
        "movl 0x44(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1564 */
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl $0x40000000, 0x1c(%esp)\n" /* line 1565 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2100, 8(%esp)\n"
        ".Lf1196e_00012024:\n"
        "movl -0x54(%ebp), %ebx\n" /* i, ModulateFactor */
        "movl %ebx, 4(%esp)\n" /* ModulateFactor */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerAlpha2\n"
        ".Lf1196e_00012038:\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 1584 | UsesTexFactor */
        "je .Lf1196e_00011b4d\n"
        "movl -0x60(%ebp), %ebx\n" /* line 122 */
        "addl $0x54, %ebx\n"
        /* { scope 4: pSrc2Coords */
        "movl -0x3c(%ebp), %esi\n" /* line 654 */
        "movl imp___ZN7COpenGL7sOpenGLE, %ecx\n"
        "addl 0x65c(%ecx), %esi\n"
        "movl %esi, -0x64(%ebp)\n"
        "addl $0xb0, %esi\n" /* line 140 */
        "movl %esi, -0x44(%ebp)\n" /* pRGBA */
        "movl $0x10, %ecx\n" /* line 554 */
        "cld\n"
        "movl %ebx, %edi\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1196e_0001207e\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1196e_0001207e:\n"
        "testl %eax, %eax\n"
        "je .Lf1196e_00011b4d\n"
        "movl -0x54(%ebp), %eax\n" /* line 556 | i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edx\n"
        "movl %edx, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        /* { scope 5 */
        "movl %ebx, 8(%esp)\n" /* line 193 */
        "movl $0x2201, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvfv\n"
        "movl -0x60(%ebp), %ecx\n"
        "movl 0x54(%ecx), %eax\n"
        "movl -0x64(%ebp), %esi\n"
        "movl %eax, 0xb0(%esi)\n"
        "movl 4(%ebx), %eax\n"
        "movl -0x44(%ebp), %edx\n" /* pRGBA */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "jmp .Lf1196e_00011b4d\n"
        /* } scope */
        /* } scope */
        ".Lf1196e_000120dc:\n"
        "movl $0x3f800000, 0x14(%esp)\n" /* line 1575 */
        "movl $0x302, 0x10(%esp)\n"
        "movl $0x8578, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %edx\n" /* i */
        "movl %edx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerAlpha1\n"
        "jmp .Lf1196e_00012038\n"
        ".Lf1196e_00012115:\n"
        "movl -0x60(%ebp), %esi\n" /* line 1547 | UsesTexNormalMap */
        "movl 0x44(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl $0x3f800000, 0x14(%esp)\n" /* line 1548 */
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerAlpha1\n"
        "jmp .Lf1196e_00012038\n"
        ".Lf1196e_00012168:\n"
        "movl -0x60(%ebp), %edx\n" /* line 1552 */
        "movl 0x48(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl $0x3f800000, 0x14(%esp)\n" /* line 1553 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerAlpha1\n"
        "jmp .Lf1196e_00012038\n"
        ".Lf1196e_000121bb:\n"
        "movl -0x60(%ebp), %ebx\n" /* line 1557 | ModulateFactor */
        "movl 0x44(%ebx), %eax\n" /* ModulateFactor */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl 0x48(%ebx), %eax\n" /* line 1558 | ModulateFactor */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl $0x3f800000, 0x1c(%esp)\n" /* line 1559 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2100, 8(%esp)\n"
        "movl -0x54(%ebp), %esi\n" /* i, UsesTexNormalMap */
        "movl %esi, 4(%esp)\n" /* UsesTexNormalMap */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerAlpha2\n"
        "jmp .Lf1196e_00012038\n"
        ".Lf1196e_00012235:\n"
        "movl -0x60(%ebp), %edx\n" /* line 1541 */
        "movl 0x44(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1542 */
        "movl 0x48(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl $0x3f800000, 0x1c(%esp)\n" /* line 1543 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x104, 8(%esp)\n"
        "jmp .Lf1196e_00012024\n"
        ".Lf1196e_0001229e:\n"
        "movl -0x60(%ebp), %esi\n" /* line 1569 | UsesTexNormalMap */
        "movl 0x44(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl 0x48(%esi), %eax\n" /* line 1570 | UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureAlphaOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1571 */
        "movl $0x302, 0x20(%esp)\n"
        "movl $0x8577, 0x1c(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x8575, 8(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerAlpha3\n"
        "jmp .Lf1196e_00012038\n"
        "movl -0x60(%ebp), %esi\n" /* line 1441 | UsesTexNormalMap */
        "movl 0x34(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x14(%esp)\n" /* line 1442 */
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB1\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl -0x60(%ebp), %edx\n" /* line 1446 */
        "movl 0x38(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x14(%esp)\n" /* line 1447 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x1e01, 8(%esp)\n"
        "movl -0x54(%ebp), %ecx\n" /* i */
        "movl %ecx, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB1\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl $0x3f800000, %ebx\n" /* line 1422 | ModulateFactor */
        ".Lf1196e_000123d9:\n"
        "movl -0x60(%ebp), %edx\n" /* line 1435 */
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1436 */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl %ebx, 0x1c(%esp)\n" /* line 1437 | ModulateFactor */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x2100, 8(%esp)\n"
        ".Lf1196e_00012439:\n"
        "movl -0x54(%ebp), %ebx\n" /* line 1485 | i, ModulateFactor */
        "movl %ebx, 4(%esp)\n" /* ModulateFactor */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB2\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl $0x40000000, %ebx\n" /* line 1422 | ModulateFactor */
        "jmp .Lf1196e_000123d9\n"
        "movl $0x40800000, %ebx\n" /* line 1428 | ModulateFactor */
        "jmp .Lf1196e_000123d9\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1425 */
        "movl 0x34(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ebx\n" /* line 1426 | ModulateFactor */
        "movl 0x38(%ebx), %eax\n" /* ModulateFactor */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x1c(%esp)\n" /* line 1427 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x104, 8(%esp)\n"
        "movl -0x54(%ebp), %esi\n" /* i, UsesTexNormalMap */
        "movl %esi, 4(%esp)\n" /* UsesTexNormalMap */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB2\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl -0x60(%ebp), %edx\n" /* line 1483 */
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1484 */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x1c(%esp)\n" /* line 1485 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x84e7, 8(%esp)\n"
        "jmp .Lf1196e_00012439\n"
        "movl -0x60(%ebp), %edx\n" /* line 1457 */
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1458 */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1459 */
        "movl $0x302, 0x20(%esp)\n"
        "movl $0x8577, 0x1c(%esp)\n"
        ".Lf1196e_000125a2:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1471 | Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x8575, 8(%esp)\n"
        "movl -0x54(%ebp), %ebx\n" /* i, ModulateFactor */
        "movl %ebx, 4(%esp)\n" /* ModulateFactor */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB3\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl -0x60(%ebp), %ebx\n" /* line 1451 | ModulateFactor */
        "movl 0x34(%ebx), %eax\n" /* ModulateFactor */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl 0x38(%ebx), %eax\n" /* line 1452 | ModulateFactor */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1453 */
        "movl $0x302, 0x20(%esp)\n"
        "movl $0x1702, 0x1c(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x8575, 8(%esp)\n"
        ".Lf1196e_00012653:\n"
        "movl -0x54(%ebp), %esi\n" /* line 1510 | i, UsesTexNormalMap */
        "movl %esi, 4(%esp)\n" /* UsesTexNormalMap */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB3\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl -0x60(%ebp), %edx\n" /* line 1469 */
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1470 */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1471 */
        "movl $0x302, 0x20(%esp)\n"
        "movl $0x8576, 0x1c(%esp)\n"
        "jmp .Lf1196e_000125a2\n"
        "movl -0x60(%ebp), %esi\n" /* line 1463 | UsesTexNormalMap */
        "movl 0x34(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl 0x38(%esi), %eax\n" /* line 1464 | UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1465 */
        "movl $0x302, 0x20(%esp)\n"
        "movl $0x8578, 0x1c(%esp)\n"
        ".Lf1196e_00012711:\n"
        "movl -0x30(%ebp), %eax\n" /* line 1495 | Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x8575, 8(%esp)\n"
        ".Lf1196e_00012735:\n"
        "movl -0x54(%ebp), %eax\n" /* i */
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB3\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl -0x60(%ebp), %edx\n" /* line 1500 */
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1501 */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ebx\n" /* line 1510 | ModulateFactor */
        "movl 0x38(%ebx), %eax\n" /* ModulateFactor */
        "andl $0x10, %eax\n"
        "cmpl $1, %eax\n"
        "sbbl %eax, %eax\n"
        "addl $0x301, %eax\n"
        "movl 0x34(%ebx), %ecx\n" /* ModulateFactor */
        "andl $0x10, %ecx\n"
        "cmpl $1, %ecx\n"
        "sbbl %edx, %edx\n"
        "addl $0x301, %edx\n"
        "cmpl $1, %ecx\n"
        "sbbl %ecx, %ecx\n"
        "addl $0x303, %ecx\n"
        "movl -0x24(%ebp), %ebx\n" /* Source1, ModulateFactor */
        "movl $0x3f800000, 0x24(%esp)\n"
        "movl %eax, 0x20(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x1c(%esp)\n"
        "movl %edx, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n" /* ModulateFactor */
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* ModulateFactor */
        "movl $0x8744, 8(%esp)\n"
        "jmp .Lf1196e_00012653\n"
        "movl -0x60(%ebp), %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011e2a\n"
        "movl -0x60(%ebp), %edx\n" /* line 1519 */
        "movl 0x34(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl -0x60(%ebp), %ecx\n" /* line 1520 */
        "movl 0x38(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x1c(%esp)\n" /* line 1521 */
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x86af, 8(%esp)\n"
        "movl -0x54(%ebp), %ebx\n" /* i, ModulateFactor */
        "movl %ebx, 4(%esp)\n" /* ModulateFactor */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexCombinerRGB2\n"
        "jmp .Lf1196e_00012038\n"
        "movl -0x60(%ebp), %esi\n" /* line 1475 | UsesTexNormalMap */
        "movl 0x34(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl 0x38(%esi), %eax\n" /* line 1476 | UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl 0x30(%esi), %eax\n" /* line 1477 | UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* Param0 */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* Source0 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1478 */
        "movl -0x28(%ebp), %eax\n" /* Param0 */
        "movl %eax, 0x20(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 0x18(%esp)\n"
        "movl -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x14(%esp)\n"
        "movl -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 0x10(%esp)\n"
        "movl -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x8744, 8(%esp)\n"
        "jmp .Lf1196e_00012735\n"
        "movl -0x60(%ebp), %esi\n" /* line 1492 | UsesTexNormalMap */
        "movl 0x34(%esi), %eax\n" /* UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Param1 */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* Source1 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl 0x38(%esi), %eax\n" /* line 1493 | UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* Param2 */
        "movl %eax, 4(%esp)\n"
        "leal -0x34(%ebp), %eax\n" /* Source2 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl 0x30(%esi), %eax\n" /* line 1494 | UsesTexNormalMap */
        "movl %eax, 8(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* Param0 */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* Source0 */
        "movl %eax, (%esp)\n"
        "calll MacOpenGLUtils_GetOpenGLTextureOp\n"
        "movl $0x3f800000, 0x24(%esp)\n" /* line 1495 */
        "movl -0x28(%ebp), %eax\n" /* Param0 */
        "movl %eax, 0x20(%esp)\n"
        "movl -0x20(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x1c(%esp)\n"
        "jmp .Lf1196e_00012711\n"
        /* } scope */
        /* { scope 3: pRGBA */
        /* { scope 4: pSrc2Coords */
        /* { scope 5 */
        ".Lf1196e_00012966:\n"
        "movl 8(%ebp), %esi\n" /* line 1358 | this, UsesTexNormalMap */
        "movl 0x2bc(%esi), %edx\n" /* UsesTexNormalMap */
        "movl 0x2d0(%esi), %eax\n" /* line 1359 | UsesTexNormalMap */
        ".Lf1196e_00012975:\n"
        "movb $1, -0x4a(%ebp)\n" /* UsesTexCoordStream */
        "xorl %edi, %edi\n" /* UsesTexGen */
        "movb $0, -0x49(%ebp)\n" /* UsesTexReflection */
        "xorl %esi, %esi\n" /* UsesTexNormalMap */
        "movl $0, -0x48(%ebp)\n" /* pSrc2Coords */
        "xorl %ecx, %ecx\n"
        "jmp .Lf1196e_00011c08\n"
        ".Lf1196e_0001298f:\n"
        "movl 8(%ebp), %eax\n" /* line 1368 | this */
        "movl 0x2bc(%eax), %edx\n"
        "movl %eax, %ecx\n" /* line 1369 */
        "movl 0x2d0(%eax), %eax\n"
        "movl 0x2d8(%ecx), %esi\n" /* line 1371 | UsesTexNormalMap */
        "movl %esi, -0x48(%ebp)\n" /* UsesTexNormalMap, pSrc2Coords */
        "movl 0x2e8(%ecx), %ecx\n" /* line 1372 */
        "movb $0, -0x4a(%ebp)\n" /* UsesTexCoordStream */
        "movl $1, %edi\n" /* UsesTexGen */
        "movb $1, -0x49(%ebp)\n" /* UsesTexReflection */
        "xorl %esi, %esi\n" /* UsesTexNormalMap */
        "jmp .Lf1196e_00011c08\n"
        ".Lf1196e_000129c3:\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 1340 */
        "je .Lf1196e_000129fc\n"
        "movl 8(%ebp), %eax\n" /* line 1351 | this */
        "movl 0x2d8(%eax), %edx\n"
        "movl 0x2e8(%eax), %eax\n" /* line 1352 */
        "movb $0, -0x4a(%ebp)\n" /* UsesTexCoordStream */
        "movl $1, %edi\n" /* UsesTexGen */
        "movb $0, -0x49(%ebp)\n" /* UsesTexReflection */
        "movl $1, %esi\n" /* UsesTexNormalMap */
        "movl $0, -0x48(%ebp)\n" /* pSrc2Coords */
        "xorl %ecx, %ecx\n"
        "jmp .Lf1196e_00011c08\n"
        ".Lf1196e_000129fc:\n"
        "movl 8(%ebp), %esi\n" /* line 1343 | this, UsesTexNormalMap */
        "movl 0x2d8(%esi), %edx\n" /* UsesTexNormalMap */
        "movl 0x2e8(%esi), %eax\n" /* line 1344 | UsesTexNormalMap */
        "jmp .Lf1196e_00012975\n"
    );
}

extern int g_draw_count;
extern unsigned char glIsEnabled(unsigned int);
extern void glGetIntegerv(unsigned int, int *);
int g_dip_vs_null = 0;     /* DIP VP binding: shader was null */
int g_dip_vs_bound = 0;    /* DIP VP binding: called SetVP */
int g_dip_vs_skip = 0;     /* DIP VP validation: flag was 0 (skipped) */

/* Diagnostic called from DIP asm at VP validation check point */
extern char dip_mNeedsVSVal __asm__("__ZN15CDirect3DDevice28mNeedsVertexShaderValidationE");
static int g_dip_vp_diag = 0;
void dip_vp_check(void *device) {
    if (g_dip_vp_diag < 5 && g_draw_count > 880) {
        g_dip_vp_diag++;
        int vsValid = dip_mNeedsVSVal;
        void *shader = *(void **)((char *)device + 0xbb4);
        fprintf(stderr, "[DIP-VP#%d] dc=%d vsValid=%d shader=%p\n",
                g_draw_count, g_dip_vp_diag, vsValid, shader);
    }
}

static int g_dip_diag_done = 0;
void dip_gl_diag(int mode, int low, int high, int count) {
    if (g_dip_diag_done < 10 && g_draw_count > 880) {
        g_dip_diag_done++;
        int vp_en = glIsEnabled(0x8620 /*GL_VERTEX_PROGRAM_ARB*/);
        int fp_en = glIsEnabled(0x8804 /*GL_FRAGMENT_PROGRAM_ARB*/);
        int vp_id = 0, fp_id = 0;
        glGetIntegerv(0x8626 /*GL_VERTEX_PROGRAM_BINDING_ARB*/, &vp_id);
        glGetIntegerv(0x8677 /*GL_FRAGMENT_PROGRAM_BINDING_ARB*/, &fp_id);
        int depth = glIsEnabled(0xb71 /*GL_DEPTH_TEST*/);
        int cm[4] = {0};
        glGetIntegerv(0x0C23 /*GL_COLOR_WRITEMASK*/, cm);
        int dm = 0;
        glGetIntegerv(0x0B72 /*GL_DEPTH_WRITEMASK*/, &dm);
        fprintf(stderr, "[DIP#%d] mode=%d low=%d high=%d count=%d vp_en=%d vp_id=%d fp_en=%d fp_id=%d depth=%d cm=(%d%d%d%d) dm=%d\n",
                g_draw_count, mode, low, high, count, vp_en, vp_id, fp_en, fp_id, depth, cm[0],cm[1],cm[2],cm[3], dm);
    }
}

/* line 1774 */
int g_draw_count = 0; /* diagnostic draw call counter */
__attribute__((naked))
HRESULT CDirect3DDevice_DrawIndexedPrimitive(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1774 */
        "movl %esp, %ebp\n"
        "incl g_draw_count\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* BaseVertexIndex */
        /* { scope 1: pVBInterface, FirstStreamStride, OffsetInBytes, RunVPInSoftware */
        "movl %esi, (%esp)\n" /* line 1785 | this */
        "calll CDirect3DDevice_ValidateModelViewMatrix\n"
        "cmpl %edi, 0xa8(%esi)\n" /* line 1790 | BaseVertexIndex, this */
        "je .Lf12a10_00012a3d\n"
        "movl %edi, 0xa8(%esi)\n" /* line 1792 | BaseVertexIndex, this */
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 645 */
        "movb $1, (%eax)\n"
        ".Lf12a10_00012a3d:\n"
        "movl 0xa4(%esi), %eax\n" /* line 1801 | this */
        "movl 0x14(%eax), %edx\n"
        "movl 0x1c(%ebp), %eax\n" /* StartIndex */
        "leal (%edx, %eax, 2), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* p16Indices */
        "movl 0xc(%ebp), %eax\n" /* line 1803 | PrimitiveType */
        "movl %eax, g_dip_last_mode\n" /* save D3D PrimType before lookup */
        "movl D3DToOpenGLPrimitive(, %eax, 4), %ebx\n" /* Mode */
        "movl 0x20(%ebp), %eax\n" /* line 1804 | PrimitiveCount */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* Mode */
        "calll MacOpenGLUtils_GetElementCount\n"
        "movl %eax, -0x44(%ebp)\n" /* NumElements */
        "movl %eax, g_dip_last_numelems\n"
        "cmpb $0, g_special\n" /* line 1808 */
        "jne .Lf12a10_00012b7f\n"
        "movl 0x14(%ebp), %edx\n" /* line 1819 | MinIndex */
        "addl %edi, %edx\n" /* BaseVertexIndex */
        "movl %edx, -0x1c(%ebp)\n" /* Low */
        "movl %edx, g_Low\n"
        "movl 0x14(%ebp), %eax\n" /* line 1820 | MinIndex */
        "addl 0x18(%ebp), %eax\n" /* NumVertices */
        "leal -1(%edi, %eax), %eax\n" /* BaseVertexIndex */
        ".Lf12a10_00012a90:\n"
        "movl %eax, -0x20(%ebp)\n" /* High */
        "movl %eax, g_High\n"
        "subl %edx, %eax\n" /* line 1821 */
        "addl $1, %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %ecx\n" /* line 645 */
        "movb $1, (%ecx)\n"
        "movl imp___ZN7COpenGL9sDrawFlagE, %edx\n" /* line 671 */
        "movzbl (%edx), %eax\n"
        "cmpl $4, %ebx\n" /* line 1856 | Mode */
        "jne .Lf12a10_not_tri\n"
        "incl g_dip_is_tri\n"
        "jmp .Lf12a10_00012bb4\n"
        ".Lf12a10_not_tri:\n"
        "testb %al, %al\n" /* line 1955 */
        "je .Lf12a10_00012b0b\n"
        ".Lf12a10_00012abf:\n"
        "movl 0x2bc(%esi), %eax\n" /* line 1961 | this */
        "testl %eax, %eax\n"
        "je .Lf12a10_00012b69\n"
        /* { scope 2 */
        ".Lf12a10_00012acd:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 1970 | FirstStreamStride */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x30(%ebp), %eax\n" /* OffsetInBytes */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* pVBInterface */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll CDirect3DDevice_GetStreamSource\n"
        "movl -0x28(%ebp), %edx\n" /* line 1973 | pVBInterface */
        "movl 0x20(%edx), %eax\n" /* line 1975 */
        "testb $2, %ah\n"
        "je .Lf12a10_00012b18\n"
        ".Lf12a10_00012afd:\n"
        "movl (%edx), %eax\n" /* line 2007 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl imp___ZN7COpenGL9sDrawFlagE, %edx\n"
        /* } scope */
        ".Lf12a10_00012b0b:\n"
        "incl g_dip_drawflag_zero\n"
        "movb $1, (%edx)\n" /* line 672 */
        /* } scope */
        "xorl %eax, %eax\n" /* line 2021 */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: pVBInterface, FirstStreamStride, OffsetInBytes, RunVPInSoftware */
        /* { scope 2 */
        ".Lf12a10_00012b18:\n"
        "testb $8, %al\n" /* line 1979 */
        "jne .Lf12a10_00012afd\n"
        "movl 0xbb4(%esi), %ecx\n" /* line 1987 | this */
        "testl %ecx, %ecx\n"
        "je .Lf12a10_00012de6\n"
        /* { scope 3 */
        "leal 0xf8(%esi), %edx\n" /* line 1990 | this, PS */
        "movl 4(%edx), %eax\n" /* line 1994 */
        "movl 0x24(%esi, %eax, 4), %ebx\n" /* this, Mode */
        "movl 0x18(%edx), %ecx\n" /* line 65 */
        "movl -0x3c(%ebp), %eax\n" /* line 1999 */
        "imull %ecx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x14(%ebx), %eax\n" /* Mode */
        "addl 8(%edx), %eax\n"
        "imull %ecx, %edi\n" /* BaseVertexIndex */
        "addl %edi, %eax\n" /* BaseVertexIndex */
        "addl -0x30(%ebp), %eax\n" /* OffsetInBytes */
        "imull 0x14(%ebp), %ecx\n" /* MinIndex */
        "addl %ecx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* Mode */
        "calll CDirect3DVertexBuffer_SetFence\n"
        "movl -0x28(%ebp), %edx\n" /* pVBInterface */
        "jmp .Lf12a10_00012afd\n"
        /* } scope */
        /* } scope */
        ".Lf12a10_00012b69:\n"
        "movl 0xbb4(%esi), %ebx\n" /* line 1961 | this, Mode */
        "testl %ebx, %ebx\n" /* Mode */
        "jne .Lf12a10_00012acd\n"
        "movl imp___ZN7COpenGL9sDrawFlagE, %edx\n"
        "jmp .Lf12a10_00012b0b\n"
        ".Lf12a10_00012b7f:\n"
        "movl %eax, 0xc(%esp)\n" /* line 1812 */
        "movl -0x48(%ebp), %eax\n" /* p16Indices */
        "movl %eax, 8(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* High */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* Low */
        "movl %eax, (%esp)\n"
        "calll GetHighAndLowIndices\n"
        "movl %edi, %edx\n" /* line 1813 | BaseVertexIndex */
        "addl -0x1c(%ebp), %edx\n" /* Low */
        "movl %edx, -0x1c(%ebp)\n" /* Low */
        "movl %edx, g_Low\n"
        "movl %edi, %eax\n" /* line 1814 | BaseVertexIndex */
        "addl -0x20(%ebp), %eax\n" /* High */
        "jmp .Lf12a10_00012a90\n"
        ".Lf12a10_00012bb4:\n"
        /* DIAG: call dip_vp_check(device=esi) */
        "pushal\n"
        "pushl %esi\n"
        "calll dip_vp_check\n"
        "addl $4, %esp\n"
        "popal\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %ebx\n" /* line 1858 | Mode */
        "cmpb $0, (%ebx)\n" /* Mode */
        "jne .Lf12a10_00012d15_diag\n"
        "incl g_dip_vs_skip\n"
        "jmp .Lf12a10_00012bc3\n"
        ".Lf12a10_00012d15_diag:\n"
        "jmp .Lf12a10_00012d15\n"
        ".Lf12a10_00012bc3:\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n" /* line 1863 */
        "cmpb $0, (%eax)\n"
        "jne .Lf12a10_00012d80\n"
        ".Lf12a10_00012bd1:\n"
        "movl imp___ZN7COpenGL9sDrawFlagE, %edx\n" /* line 1872 */
        "cmpb $0, (%edx)\n"
        "je .Lf12a10_00012b0b\n"
        /* { scope 2 */
        "movl imp___ZN15CDirect3DDevice29mNeedsRasterizationValidationE, %ebx\n" /* line 1874 | Mode */
        "cmpb $0, (%ebx)\n" /* Mode */
        "jne .Lf12a10_00012bf5\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %eax\n"
        "cmpb $0, (%eax)\n"
        "je .Lf12a10_00012c16\n"
        ".Lf12a10_00012bf5:\n"
        "movl -0x3c(%ebp), %eax\n" /* line 1876 */
        "addl %edi, %eax\n" /* BaseVertexIndex */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* BaseVertexIndex */
        "movl %esi, (%esp)\n" /* this */
        "calll CDirect3DDevice_ValidateRasterization\n"
        "movl imp___ZN15CDirect3DDevice30mNeedsTransformationValidationE, %ecx\n" /* line 645 */
        "movb $0, (%ecx)\n"
        "movb $0, (%ebx)\n" /* line 646 */
        ".Lf12a10_00012c16:\n"
        "movl %esi, (%esp)\n" /* line 1881 | this */
        "calll CDirect3DDevice_ValidateLighting\n"
        "movl 0x54c(%esi), %eax\n" /* line 789 */
        "testl %eax, %eax\n"
        "je .Lf12a10_00012d4f\n"
        "movl 0x3a0(%esi), %eax\n" /* line 791 */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x398(%esi), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x39c(%esi), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x394(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl 0x518(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetBlendEXT\n"
        ".Lf12a10_00012c6c:\n"
        "movb $0, 0x518(%esi)\n" /* line 797 */
        "movl 0xbb4(%esi), %eax\n" /* line 1884 | this */
        "testl %eax, %eax\n"
        "je .Lf12a10_00012ddd\n"
        "movzbl 0x198(%eax), %eax\n"
        "movb %al, -0x3d(%ebp)\n" /* RunVPInSoftware */
        "testb %al, %al\n" /* line 1885 */
        "jne .Lf12a10_00012dcc\n"
        ".Lf12a10_00012c93:\n"
        "movl -0x44(%ebp), %eax\n" /* line 1904 | NumElements */
        "movl %eax, -0x28(%ebp)\n" /* pVBInterface */
        "testl %eax, %eax\n" /* line 1909 */
        "jne .Lf12a10_00012d02\n"
        "incl g_dip_numelems_zero\n"
        ".Lf12a10_00012c9d:\n"
        "cmpb $0, -0x3d(%ebp)\n" /* line 1942 | RunVPInSoftware */
        "je .Lf12a10_00012abf\n"
        "movl $0x3f800000, (%esp)\n" /* line 1944 */
        "calll glPointSize\n"
        "jmp .Lf12a10_00012abf\n"
        /* { scope 3 */
        ".Lf12a10_00012cb8:\n"
        "leal -0x28(%ebp), %edx\n" /* line 189 | pVBInterface */
        /* } scope */
        ".Lf12a10_00012cbb:\n"
        "movl (%edx), %ebx\n" /* line 1911 | Mode */
        "subl %ebx, %eax\n" /* line 1912 | Mode */
        "movl %eax, -0x28(%ebp)\n" /* pVBInterface */
        "movl -0x48(%ebp), %ecx\n" /* line 1935 | p16Indices */
        "movl %ecx, 0x14(%esp)\n"
        "movl $0x1403, 0x10(%esp)\n"
        "movl %ebx, 0xc(%esp)\n" /* Mode */
        "movl -0x20(%ebp), %eax\n" /* High */
        "movl %eax, 8(%esp)\n"
        "movl -0x1c(%ebp), %eax\n" /* Low */
        "movl %eax, 4(%esp)\n"
        "movl $4, (%esp)\n"
        /* diagnostic: save args and call dip_gl_diag */
        "pushl %ebx\n"       /* count (Mode) */
        "pushl -0x20(%ebp)\n" /* High */
        "pushl -0x1c(%ebp)\n" /* Low */
        "pushl $4\n"          /* mode */
        "calll dip_gl_diag\n"
        "addl $16, %esp\n"
        "incl g_dip_gl_draw\n"
        "calll glDrawRangeElements\n"
        "movl -0x48(%ebp), %eax\n" /* line 1939 | p16Indices */
        "leal (%eax, %ebx, 2), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* p16Indices */
        "movl -0x28(%ebp), %eax\n" /* line 1909 | pVBInterface */
        "testl %eax, %eax\n"
        "je .Lf12a10_00012c9d\n"
        "movl -0x28(%ebp), %eax\n" /* pVBInterface */
        ".Lf12a10_00012d02:\n"
        "movl $0xffff, -0x24(%ebp)\n" /* line 1911 */
        /* { scope 3 */
        "cmpl $0xfffe, %eax\n" /* line 189 */
        "jbe .Lf12a10_00012cb8\n"
        "leal -0x24(%ebp), %edx\n"
        "jmp .Lf12a10_00012cbb\n"
        /* } scope */
        /* } scope */
        ".Lf12a10_00012d15:\n"
        "movl 0xbb4(%esi), %eax\n" /* line 3018 | this */
        "testl %eax, %eax\n"
        "jne .Lf12a10_vs_notnull\n"
        "incl g_dip_vs_null\n"
        "jmp .Lf12a10_00012e14\n"
        ".Lf12a10_vs_notnull:\n"
        "incl g_dip_vs_bound\n"
        /* { scope 2 */
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 587 */
        "cmpb $0, 0x80d(%ebx)\n"
        "je .Lf12a10_00012da6\n"
        ".Lf12a10_00012d32:\n"
        "addl $4, %eax\n" /* line 3023 | pOGLVertexProgramInfo */
        ".Lf12a10_00012d35:\n"
        "movl %eax, 4(%esp)\n" /* line 3024 */
        "movl %ebx, (%esp)\n" /* Mode */
        "calll COpenGL_SetVertexProgram\n"
        "movl imp___ZN15CDirect3DDevice28mNeedsVertexShaderValidationE, %ebx\n" /* Mode */
        /* } scope */
        ".Lf12a10_00012d47:\n"
        "movb $0, (%ebx)\n" /* line 644 */
        "jmp .Lf12a10_00012bc3\n"
        /* { scope 2 */
        ".Lf12a10_00012d4f:\n"
        "movl 0x39c(%esi), %eax\n" /* line 795 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x394(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl 0x518(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetBlend\n"
        "jmp .Lf12a10_00012c6c\n"
        /* } scope */
        ".Lf12a10_00012d80:\n"
        "movl -0x44(%ebp), %ecx\n" /* line 1868 | NumElements */
        "movl %ecx, 0x10(%esp)\n"
        "movl -0x48(%ebp), %eax\n" /* p16Indices */
        "movl %eax, 0xc(%esp)\n"
        "movl -0x3c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* BaseVertexIndex */
        "movl %esi, (%esp)\n" /* this */
        "calll CDirect3DDevice_ValidateTransformation\n"
        "jmp .Lf12a10_00012bd1\n"
        /* { scope 2 */
        ".Lf12a10_00012da6:\n"
        "movb $1, 0x80d(%ebx)\n" /* line 589 */
        "movl $0x8620, (%esp)\n" /* line 590 */
        "calll glEnable\n"
        "movl 0xbb4(%esi), %eax\n" /* line 3023 | this, pOGLVertexProgramInfo */
        "testl %eax, %eax\n" /* pOGLVertexProgramInfo */
        "jne .Lf12a10_00012d32\n"
        "jmp .Lf12a10_00012d35\n"
        /* } scope */
        /* { scope 2 */
        ".Lf12a10_00012dcc:\n"
        "movl $0x40000000, (%esp)\n" /* line 1887 */
        "calll glPointSize\n"
        "jmp .Lf12a10_00012c93\n"
        ".Lf12a10_00012ddd:\n"
        "movb $0, -0x3d(%ebp)\n" /* line 1884 | RunVPInSoftware */
        "jmp .Lf12a10_00012c93\n"
        /* } scope */
        /* { scope 2 */
        ".Lf12a10_00012de6:\n"
        "movl 0x2d0(%esi), %eax\n" /* line 2004 | this */
        "movl -0x3c(%ebp), %ecx\n"
        "imull %eax, %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "imull 0x14(%ebp), %eax\n" /* MinIndex */
        "addl 0x2bc(%esi), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll CDirect3DVertexBuffer_SetFence\n"
        "movl -0x28(%ebp), %edx\n" /* pVBInterface */
        "jmp .Lf12a10_00012afd\n"
        /* } scope */
        ".Lf12a10_00012e14:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 596 */
        "cmpb $0, 0x80d(%eax)\n"
        "je .Lf12a10_00012d47\n"
        "movb $0, 0x80d(%eax)\n" /* line 598 */
        "movl $0x8620, (%esp)\n" /* line 599 */
        "calll glDisable\n"
        "movb $0, (%ebx)\n" /* line 644 */
        "jmp .Lf12a10_00012bc3\n"
    );
}

/* line 42 */
__attribute__((naked))
HRESULT CDirect3D_RegisterSoftwareDevice(const CDirect3D * _this, void *pInitializeFunction)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 42 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 49 */
__attribute__((naked))
HRESULT CDirect3D_CheckDeviceType(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL Windowed)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 49 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 52 */
__attribute__((naked))
HRESULT CDirect3D_CheckDeviceFormatConversion(const CDirect3D * _this, UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 52 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 55 */
__attribute__((naked))
HMONITOR CDirect3D_GetAdapterMonitor(const CDirect3D * _this, UINT Adapter)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 55 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 66 */
__attribute__((naked))
bool CVAOPacketFixedFunction_IsFixedFunction(const CVAOPacketFixedFunction * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 66 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 73 */
__attribute__((naked))
bool CVAOPacketProgrammable_IsFixedFunction(const CVAOPacketProgrammable * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 73 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 70 */
__attribute__((naked))
void ZN22CVAOPacketProgrammableD1Ev(void) /* CVAOPacketProgrammable_~CVAOPacketProgrammable */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl %edx, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN10CVAOPacketD2Ev\n"
    );
}

/* line 70 */
__attribute__((naked))
void ZN22CVAOPacketProgrammableD0Ev(void) /* CVAOPacketProgrammable_~CVAOPacketProgrammable */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 70 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl imp___ZTV22CVAOPacketProgrammable, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll ZN10CVAOPacketD2Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

/* line 63 */
__attribute__((naked))
void ZN23CVAOPacketFixedFunctionD1Ev(void) /* CVAOPacketFixedFunction_~CVAOPacketFixedFunction */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%edx)\n"
        "movl %edx, 8(%ebp)\n" /* this */
        "popl %ebp\n"
        "jmp ZN10CVAOPacketD2Ev\n"
    );
}

/* line 63 */
__attribute__((naked))
void ZN23CVAOPacketFixedFunctionD0Ev(void) /* CVAOPacketFixedFunction_~CVAOPacketFixedFunction */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 63 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl imp___ZTV23CVAOPacketFixedFunction, %eax\n"
        "addl $8, %eax\n"
        "movl %eax, (%ebx)\n" /* this */
        "movl %ebx, (%esp)\n" /* this */
        "calll ZN10CVAOPacketD2Ev\n"
        "movl %ebx, 8(%ebp)\n" /* this */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
    );
}

