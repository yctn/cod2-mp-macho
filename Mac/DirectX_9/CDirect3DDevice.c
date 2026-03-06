/* ASM dump from: CDirect3DDevice.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/CDirect3DDevice.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "Mac/DirectX 9/CDirect3DDevice.h"
 *   #include "Mac/DirectX 9/CDirect3DVertexBuffer.h"
 *   #include "Mac/DirectX 9/MacOpenGLUtils.h"
 *   #include "Mac/DirectX 9/COpenGLTexture.h"
 *   #include "Mac/DirectX 9/COpenGL.h"
 *   #include "Mac/Tools/MacFastCopy.h"
 *   #include "Mac/DirectX 9/MacOpenGLMath.h"
 *   #include "Mac/DirectX 9/COpenGLVAO.h"
 */

extern bool g_ShowShadowCookies; /* 0x0 */
extern UINT32 g_NumBlurShadowPasses; /* 0x0 */
extern bool g_RenderToShadowCookie; /* 0x0 */
extern UINT32 g_showtexid; /* 0x0 */
extern float g_scale1; /* 0x0 */
extern float g_scale2; /* 0x0 */
extern bool g_InhibitCopy; /* 0x0 */
extern bool g_NoTextureID; /* 0x0 */
extern bool CDirect3DDevice_mNeedsVertexShaderValidation; /* 0x0 */
extern bool CDirect3DDevice_mNeedsTransformationValidation; /* 0x0 */
extern bool CDirect3DDevice_mNeedsRasterizationValidation; /* 0x0 */
static const float GaussianBlurWeights[5]; /* 0x2edf6c */
static float sPointScale[3]; /* 0x334e00 */

extern UINT32 MacOpenGLUtils_GetImageSizeInBytes(UINT32 Width, UINT32 Height, UINT32 Depth, UINT32 LevelCount, const D3DFORMAT *f);
extern UINT32 MacOpenGLUtils_GetPCPixelShaderVersion(void);
extern int MacDisplay_GetCardType(void);
extern void *SDL_GL_GetProcAddress(const char *proc);
extern void *malloc(unsigned int size);
extern void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
extern void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
extern void CDirect3DSurface_CDirect3DSurface(const CDirect3DSurface * _this, SurfaceType s, GLenum CubemapID, UINT32 Level, UINT32 Width, UINT32 Height, D3DFORMAT Format, const void * pSurfaceMemory, COpenGLTexture *pOpenGLTextureInfo);
extern void CDirect3DSurface_UpdateOpenGLSurfaceObject(const CDirect3DSurface * _this, int bRecreateSurface);

ULONG CDirect3DDevice_AddRef(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_QueryInterface(const CDirect3DDevice * _this, const IID *iid, LPVOID *ppvObj);
ULONG CDirect3DDevice_Release(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_CreateIndexBuffer(const CDirect3DDevice * _this, UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9 * *ppIndexBuffer, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_TestCooperativeLevel(const CDirect3DDevice * _this);
UINT CDirect3DDevice_GetAvailableTextureMem(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetDirect3D(const CDirect3DDevice * _this, IDirect3D9 * *ppD3D8);
HRESULT CDirect3DDevice_GetDeviceCaps(const CDirect3DDevice * _this, D3DCAPS9 *pCaps);
HRESULT CDirect3DDevice_GetDisplayMode(const CDirect3DDevice * _this, UINT iSwapChain, D3DDISPLAYMODE *pMode);
HRESULT CDirect3DDevice_GetBackBuffer(const CDirect3DDevice * _this, UINT iSwapChain, UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9 * *ppBackBuffer);
long unsigned int CDirect3DDevice_SetGammaRamp(const CDirect3DDevice * _this, UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP *pRamp);
long unsigned int CDirect3DDevice_GetGammaRamp(const CDirect3DDevice * _this, UINT iSwapChain, D3DGAMMARAMP *pRamp);
HRESULT CDirect3DDevice_CreateTexture(const CDirect3DDevice * _this, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9 * *ppTexture, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_CreateVolumeTexture(const CDirect3DDevice * _this, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9 * *ppVolumeTexture, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_CreateCubeTexture(const CDirect3DDevice * _this, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9 * *ppCubeTexture, HANDLE *pSharedHandle);
HRESULT CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9 * *ppVolumeTexture, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_CreateVertexBuffer(const CDirect3DDevice * _this, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9 * *ppVertexBuffer, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_UpdateTexture(const CDirect3DDevice * _this, IDirect3DBaseTexture9 *pSourceTexture, IDirect3DBaseTexture9 *pDestinationTexture);
long unsigned int CDirect3DDevice_StartPixelOneToOneState(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetDepthStencilSurface(const CDirect3DDevice * _this, IDirect3DSurface9 * *ppZStencilSurface);
HRESULT CDirect3DDevice_BeginScene(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_EndScene(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetTransform(const CDirect3DDevice * _this, D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix);
HRESULT CDirect3DDevice_SetViewport(const CDirect3DDevice * _this, const D3DVIEWPORT9 *pViewport);
long unsigned int CDirect3DDevice_SetAlphaFuncAndRef(const CDirect3DDevice * _this, DWORD AlphaFuncValue, DWORD AlphaRefValue);
GLenum CDirect3DDevice_GetStencilOpFunc(const CDirect3DDevice * _this, UINT32 Value);
HRESULT CDirect3DDevice_GetRenderState(const CDirect3DDevice * _this, D3DRENDERSTATETYPE State, DWORD *pValue);
HRESULT CDirect3DDevice_CreateVertexDeclaration(const CDirect3DDevice * _this, const D3DVERTEXELEMENT9 *pVertexElements, IDirect3DVertexDeclaration9 * *ppDecl);
HRESULT CDirect3DDevice_CreateVertexShader(const CDirect3DDevice * _this, const DWORD *pFunction, IDirect3DVertexShader9 * *ppShader);
HRESULT CDirect3DDevice_GetStreamSource(const CDirect3DDevice * _this, UINT StreamNumber, IDirect3DVertexBuffer9 * *ppStreamData, UINT *pOffsetInBytes, UINT *pStride);
HRESULT CDirect3DDevice_CreateDepthStencilSurface(const CDirect3DDevice * _this, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9 * *ppSurface, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_CreateRenderTarget(const CDirect3DDevice * _this, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9 * *ppSurface, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_SetVertexDeclaration(const CDirect3DDevice * _this, IDirect3DVertexDeclaration9 *pDecl);
HRESULT CDirect3DDevice_SetVertexShader(const CDirect3DDevice * _this, IDirect3DVertexShader9 *pShader);
HRESULT CDirect3DDevice_SetFVF(const CDirect3DDevice * _this, DWORD FVF);
HRESULT CDirect3DDevice_Clear(const CDirect3DDevice * _this, DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil);
HRESULT CDirect3DDevice_SetMaterial(const CDirect3DDevice * _this, const D3DMATERIAL9 *pMaterial);
HRESULT CDirect3DDevice_LightEnable(const CDirect3DDevice * _this, DWORD Index, BOOL Enable);
long unsigned int CDirect3DDevice_CopyColorToRenderTargetTexture(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_SetRenderTarget(const CDirect3DDevice * _this, DWORD RenderTargetIndex, IDirect3DSurface9 *pRenderTarget);
bool CDirect3DDevice_CTexStage_GetUsesTexture(const CTexStage * _this, bool *UsesTexFactor);
HRESULT CDirect3DDevice_Present(const CDirect3DDevice * _this, const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion);
HRESULT CDirect3DDevice_SetLight(const CDirect3DDevice * _this, DWORD Index, const D3DLIGHT9 *pLight);
HRESULT CDirect3DDevice_SetSamplerState(const CDirect3DDevice * _this, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value);
HRESULT CDirect3DDevice_GetSamplerState(const CDirect3DDevice * _this, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD *pValue);
HRESULT CDirect3DDevice_SetTextureStageState(const CDirect3DDevice * _this, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
HRESULT CDirect3DDevice_GetTextureStageState(const CDirect3DDevice * _this, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue);
HRESULT CDirect3DDevice_SetRenderState(const CDirect3DDevice * _this, D3DRENDERSTATETYPE State, DWORD Value);
long unsigned int COpenGL_SetTexCombinerAlpha3(const COpenGL * _this, UINT32 Unit, GLenum AlphaOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLenum Source2, GLenum Operand2, float Scale);
long unsigned int COpenGL_SetTexCombinerRGB3(const COpenGL * _this, UINT32 Unit, GLenum ColorOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLenum Source2, GLenum Operand2, GLfloat Scale);
long unsigned int CDirect3DDevice_EndPixelOneToOneState(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_StretchRect(const CDirect3DDevice * _this, IDirect3DSurface9 *pSourceSurface, const RECT *pSourceRect, IDirect3DSurface9 *pDestSurface, const RECT *pDestRect, D3DTEXTUREFILTERTYPE Filter);
long unsigned int COpenGL_SetTexCombinerRGB1(const COpenGL * _this, UINT32 Unit, GLenum ColorOp, GLenum Source0, GLenum Operand0, GLfloat Scale);
long unsigned int COpenGL_SetTexCombinerRGB2(const COpenGL * _this, UINT32 Unit, GLenum ColorOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLfloat Scale);
long unsigned int COpenGL_SetTexCombinerAlpha1(const COpenGL * _this, UINT32 Unit, GLenum AlphaOp, GLenum Source0, GLenum Operand0, float Scale);
long unsigned int COpenGL_SetTexCombinerAlpha2(const COpenGL * _this, UINT32 Unit, GLenum AlphaOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, float Scale);
long unsigned int CDirect3DDevice_SetTextureCoordStream(const CDirect3DDevice * _this, UINT32 TexUnit, UINT32 TransformFlags, const D3DMATRIX *OriginalTexTransform, GLint VSize, UINT32 Tci, UINT32 StartVertex, UINT32 EndVertex, const float *pSrcCoords, UINT32 SrcStride, const float *pSrc2Coords, UINT32 Src2Stride);
void ZN15CDirect3DDeviceD0Ev(void); /* CDirect3DDevice_~CDirect3DDevice */
HRESULT CDirect3DDevice_Reset(const CDirect3DDevice * _this, D3DPRESENT_PARAMETERS *pPresentationParameters);
long unsigned int CDirect3DDevice_CDirect3DDevice(const CDirect3DDevice * _this, UINT Adapter, D3DDEVTYPE DeviceType, ContextRef Context, D3DPRESENT_PARAMETERS *pPresentationParameters);
void ZN15CDirect3DDeviceD2Ev(void); /* CDirect3DDevice_~CDirect3DDevice */
void ZN15CDirect3DDeviceD1Ev(void); /* CDirect3DDevice_~CDirect3DDevice */
HRESULT CDirect3DDevice_CreatePixelShaderOpenGL(const CDirect3DDevice * _this, OpenGLPixelShaderType ShaderType, const long unsigned int *pSrcData, IDirect3DPixelShader9 * *ppShader);
HRESULT CDirect3DDevice_CreatePixelShader(const CDirect3DDevice * _this, const DWORD *pFunction, IDirect3DPixelShader9 * *ppShader);
void ZNSt11char_traitsIcE2eqERKcS2_(void); /* std_char_traits<char>_eq */
HRESULT CDirect3DDevice_EvictManagedResources(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetCreationParameters(const CDirect3DDevice * _this, D3DDEVICE_CREATION_PARAMETERS *pParameters);
HRESULT CDirect3DDevice_SetCursorProperties(const CDirect3DDevice * _this, UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9 *pCursorBitmap);
long unsigned int CDirect3DDevice_SetCursorPosition(const CDirect3DDevice * _this, int XScreenSpace, int YScreenSpace, DWORD Flags);
BOOL CDirect3DDevice_ShowCursor(const CDirect3DDevice * _this, BOOL bShow);
HRESULT CDirect3DDevice_CreateAdditionalSwapChain(const CDirect3DDevice * _this, D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 * *pSwapChain);
HRESULT CDirect3DDevice_GetSwapChain(const CDirect3DDevice * _this, UINT iSwapChain, IDirect3DSwapChain9 * *pSwapChain);
UINT CDirect3DDevice_GetNumberOfSwapChains(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetRasterStatus(const CDirect3DDevice * _this, UINT iSwapChain, D3DRASTER_STATUS *pRasterStatus);
HRESULT CDirect3DDevice_SetDialogBoxMode(const CDirect3DDevice * _this, BOOL bEnableDialogs);
HRESULT CDirect3DDevice_UpdateSurface(const CDirect3DDevice * _this, IDirect3DSurface9 *pSourceSurface, const RECT *pSourceRect, IDirect3DSurface9 *pDestinationSurface, const POINT *pDestPoint);
HRESULT CDirect3DDevice_GetRenderTargetData(const CDirect3DDevice * _this, IDirect3DSurface9 *pRenderTarget, IDirect3DSurface9 *pDestSurface);
HRESULT CDirect3DDevice_GetFrontBufferData(const CDirect3DDevice * _this, UINT iSwapChain, IDirect3DSurface9 *pDestSurface);
HRESULT CDirect3DDevice_ColorFill(const CDirect3DDevice * _this, IDirect3DSurface9 *pSurface, const RECT *pRect, D3DCOLOR color);
HRESULT CDirect3DDevice_CreateOffscreenPlainSurface(const CDirect3DDevice * _this, UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9 * *ppSurface, HANDLE *pSharedHandle);
HRESULT CDirect3DDevice_GetRenderTarget(const CDirect3DDevice * _this, DWORD RenderTargetIndex, IDirect3DSurface9 * *ppRenderTarget);
HRESULT CDirect3DDevice_MultiplyTransform(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetViewport(const CDirect3DDevice * _this, IDirect3DIndexBuffer9 * (*pViewport)[10]);
HRESULT CDirect3DDevice_GetMaterial(const CDirect3DDevice * _this, char (*pMaterial)[4]);
HRESULT CDirect3DDevice_GetLight(const CDirect3DDevice * _this, DWORD Index);
HRESULT CDirect3DDevice_GetLightEnable(const CDirect3DDevice * _this, DWORD Index, BOOL *pEnable);
HRESULT CDirect3DDevice_SetClipPlane(const CDirect3DDevice * _this, DWORD Index, const float *pPlane);
HRESULT CDirect3DDevice_GetClipPlane(const CDirect3DDevice * _this, DWORD Index, float *pPlane);
HRESULT CDirect3DDevice_BeginStateBlock(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_CreateStateBlock(const CDirect3DDevice * _this, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9 * *ppSB);
HRESULT CDirect3DDevice_EndStateBlock(const CDirect3DDevice * _this, IDirect3DStateBlock9 * *ppSB);
HRESULT CDirect3DDevice_SetClipStatus(const CDirect3DDevice * _this, const D3DCLIPSTATUS9 *pClipStatus);
HRESULT CDirect3DDevice_GetClipStatus(const CDirect3DDevice * _this, D3DCLIPSTATUS9 *pClipStatus);
HRESULT CDirect3DDevice_ValidateDevice(const CDirect3DDevice * _this, DWORD *pNumPasses);
HRESULT CDirect3DDevice_SetPaletteEntries(const CDirect3DDevice * _this, UINT PaletteNumber, const PALETTEENTRY *pEntries);
HRESULT CDirect3DDevice_GetPaletteEntries(const CDirect3DDevice * _this, UINT PaletteNumber, _D3DFORMAT (*pEntries)[4][4]);
HRESULT CDirect3DDevice_SetCurrentTexturePalette(const CDirect3DDevice * _this, UINT PaletteNumber);
HRESULT CDirect3DDevice_GetCurrentTexturePalette(const CDirect3DDevice * _this, UINT *PaletteNumber);
HRESULT CDirect3DDevice_SetScissorRect(const CDirect3DDevice * _this, const RECT *pRect);
HRESULT CDirect3DDevice_GetScissorRect(const CDirect3DDevice * _this, RECT *pRect);
HRESULT CDirect3DDevice_SetSoftwareVertexProcessing(const CDirect3DDevice * _this, BOOL bSoftware);
BOOL CDirect3DDevice_GetSoftwareVertexProcessing(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_SetNPatchMode(const CDirect3DDevice * _this, float nSegments);
float CDirect3DDevice_GetNPatchMode(const CDirect3DDevice * _this);
HRESULT CDirect3DDevice_GetVertexDeclaration(const CDirect3DDevice * _this, IDirect3DVertexDeclaration9 * *ppDecl);
HRESULT CDirect3DDevice_GetFVF(const CDirect3DDevice * _this, DWORD *pFVF);
HRESULT CDirect3DDevice_DrawIndexedPrimitiveUP(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const long unsigned int *pIndexData, D3DFORMAT IndexDataFormat, const long unsigned int *pVertexStreamZeroData, UINT VertexStreamZeroStride);
HRESULT CDirect3DDevice_ProcessVertices(const CDirect3DDevice * _this, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9 *pDestBuffer, IDirect3DVertexDeclaration9 *pVertexDecl, DWORD Flags);
HRESULT CDirect3DDevice_GetVertexShader(const CDirect3DDevice * _this, IDirect3DVertexShader9 * *ppShader);
HRESULT CDirect3DDevice_SetStreamSource(const CDirect3DDevice * _this, UINT StreamNumber, IDirect3DVertexBuffer9 *pStreamData, UINT OffsetInBytes, UINT Stride);
HRESULT CDirect3DDevice_GetVertexShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, float *pConstantData, UINT Vector4fCount);
HRESULT CDirect3DDevice_SetVertexShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, const int *pConstantData, UINT Vector4iCount);
HRESULT CDirect3DDevice_GetVertexShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, int *pConstantData, UINT Vector4iCount);
HRESULT CDirect3DDevice_SetVertexShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, const BOOL *pConstantData, UINT BoolCount);
HRESULT CDirect3DDevice_GetVertexShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, BOOL *pConstantData, UINT BoolCount);
HRESULT CDirect3DDevice_SetStreamSourceFreq(const CDirect3DDevice * _this, UINT StreamNumber, UINT Setting);
HRESULT CDirect3DDevice_GetStreamSourceFreq(const CDirect3DDevice * _this, UINT StreamNumber, UINT *pSetting);
HRESULT CDirect3DDevice_SetIndices(const CDirect3DDevice * _this, IDirect3DIndexBuffer9 *pIndexData);
HRESULT CDirect3DDevice_GetIndices(const CDirect3DDevice * _this, IDirect3DIndexBuffer9 * *ppIndexData);
HRESULT CDirect3DDevice_GetPixelShader(const CDirect3DDevice * _this, IDirect3DPixelShader9 * *ppShader);
HRESULT CDirect3DDevice_GetPixelShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, float *pConstantData, UINT Vector4fCount);
HRESULT CDirect3DDevice_SetPixelShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, const int *pConstantData, UINT Vector4iCount);
HRESULT CDirect3DDevice_GetPixelShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, int *pConstantData, UINT Vector4iCount);
HRESULT CDirect3DDevice_SetPixelShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, const BOOL *pConstantData, UINT BoolCount);
HRESULT CDirect3DDevice_GetPixelShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, BOOL *pConstantData, UINT BoolCount);
HRESULT CDirect3DDevice_DrawRectPatch(const CDirect3DDevice * _this, UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo);
HRESULT CDirect3DDevice_DrawTriPatch(const CDirect3DDevice * _this, UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo);
HRESULT CDirect3DDevice_DeletePatch(const CDirect3DDevice * _this, UINT Handle);
HRESULT CDirect3DDevice_CreateQuery(const CDirect3DDevice * _this, D3DQUERYTYPE Type, bool (*ppQuery)());
HRESULT CDirect3DDevice_GetTexture(const CDirect3DDevice * _this, DWORD Stage, IDirect3DBaseTexture9 * *ppTexture);
void ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void); /* std_vector<CDirect3DDevice_CTexStage, std_allocator<CDirect3DDevice_CTexStage> >_erase */
long unsigned int CDirect3DDevice_CTexStage_Init(const CTexStage * _this, UINT32 Stage, int IsProgrammableStage);
HRESULT CDirect3DDevice_SetPixelShader(const CDirect3DDevice * _this, IDirect3DPixelShader9 *pShader);
HRESULT CDirect3DDevice_SetPixelShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, const float *pConstantData, UINT Vector4fCount);
HRESULT CDirect3DDevice_SetVertexShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, const float *pConstantData, UINT Vector4fCount);
void ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void); /* std_vector<CDirect3DDevice_CTexStage, std_allocator<CDirect3DDevice_CTexStage> >__M_insert_aux */

/* line 201 */
__attribute__((naked))
ULONG CDirect3DDevice_AddRef(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 201 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n" /* line 203 */
        "addl $1, %eax\n"
        "movl %eax, 4(%edx)\n"
        "popl %ebp\n" /* line 204 */
        "retl\n"
    );
}

/* line 190 */
__attribute__((naked))
HRESULT CDirect3DDevice_QueryInterface(const CDirect3DDevice * _this, const IID *iid, LPVOID *ppvObj)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 190 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x10(%ebp), %edx\n" /* line 192 | ppvObj */
        "movl %eax, (%edx)\n"
        "movl (%eax), %edx\n" /* line 193 */
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 196 */
        "leave\n"
        "retl\n"
    );
}

/* line 209 */
__attribute__((naked))
ULONG CDirect3DDevice_Release(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 209 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %ebx\n" /* line 211 */
        "subl $1, %ebx\n"
        "movl %ebx, 4(%edx)\n"
        "testl %ebx, %ebx\n" /* line 212 */
        "jne .Lf13b58_00013b7a\n"
        "movl (%edx), %eax\n" /* line 214 */
        "movl %edx, (%esp)\n"
        "calll *0x1e0(%eax)\n"
        ".Lf13b58_00013b7a:\n"
        "movl %ebx, %eax\n" /* line 218 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 282 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateIndexBuffer(const CDirect3DDevice * _this, UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9 * *ppIndexBuffer, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 282 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x34, (%esp)\n" /* line 286 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x18(%ebp), %eax\n" /* Pool */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Usage */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Format */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Length */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DIndexBuffer_CDirect3DIndexBuffer\n"
        "movl 0x1c(%ebp), %eax\n" /* ppIndexBuffer */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 289 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 286 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 353 */
__attribute__((naked))
HRESULT CDirect3DDevice_TestCooperativeLevel(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 353 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 356 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 361 */
__attribute__((naked))
UINT CDirect3DDevice_GetAvailableTextureMem(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 361 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x4fc(%eax), %eax\n" /* this */
        "popl %ebp\n" /* line 366 */
        "retl\n"
    );
}

/* line 379 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetDirect3D(const CDirect3DDevice * _this, IDirect3D9 * *ppD3D8)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 379 */
        "movl %esp, %ebp\n"
        "subl $8, %esp\n"
        "calll CDirect3D_GetDirect3DInterface\n" /* line 382 */
        "movl 0xc(%ebp), %edx\n" /* ppD3D8 */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 385 */
        "leave\n"
        "retl\n"
    );
}

/* line 390 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetDeviceCaps(const CDirect3DDevice * _this, D3DCAPS9 *pCaps)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 390 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x30, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* pCaps */
        "movl $0x130, 8(%esp)\n" /* line 397 */
        "movl $0, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pCaps */
        "calll memset\n"
        "movl $1, (%ebx)\n" /* line 401 | pCaps */
        "movl 0xc(%esi), %eax\n" /* line 402 | this */
        "movl %eax, 4(%ebx)\n" /* pCaps */
        "movl $0, 8(%ebx)\n" /* line 404 | pCaps */
        "movl $0x30020000, 0xc(%ebx)\n" /* line 409 | pCaps */
        "movl $0x120, 0x10(%ebx)\n" /* line 413 | pCaps */
        "movl $0x80000001, 0x14(%ebx)\n" /* line 418 | pCaps */
        "movl $1, 0x18(%ebx)\n" /* line 421 | pCaps */
        "movl $0x19bfc0, 0x1c(%ebx)\n" /* line 437 | pCaps */
        "movl $0xcaf2, 0x20(%ebx)\n" /* line 450 | pCaps */
        "calll MacDisplay_GetSupportsSeparateBlendFunc\n" /* line 454 */
        "testb %al, %al\n"
        "je .Lf13c06_00013c79\n"
        "orl $0x20000, 0x20(%ebx)\n" /* line 456 | pCaps */
        ".Lf13c06_00013c79:\n"
        "movl $0, 0x24(%ebx)\n" /* line 463 | pCaps */
        "calll MacDisplay_GetSupportsAnisotropicFiltering\n" /* line 465 */
        "testb %al, %al\n"
        "je .Lf13c06_00013e97\n"
        "movl 0x24(%ebx), %eax\n" /* line 467 | pCaps */
        "orl $0x20000, %eax\n"
        "movl %eax, 0x24(%ebx)\n" /* pCaps */
        ".Lf13c06_00013c98:\n"
        "orl $0x5602081, %eax\n" /* line 478 */
        "andl $0xfffeffff, %eax\n" /* line 479 */
        "orl $0x2000000, %eax\n" /* line 480 */
        "movl %eax, 0x24(%ebx)\n" /* pCaps */
        "movl $0xff, 0x28(%ebx)\n" /* line 490 | pCaps */
        "movl $0x7ff, 0x2c(%ebx)\n" /* line 504 | pCaps */
        "movl $0x7ff, 0x30(%ebx)\n" /* line 521 | pCaps */
        "movl $0xff, 0x34(%ebx)\n" /* line 534 | pCaps */
        "movl $0x84208, 0x38(%ebx)\n" /* line 540 | pCaps */
        "movl $0x234d07, 0x3c(%ebx)\n" /* line 556 | pCaps */
        "movl $0x3030300, 0x40(%ebx)\n" /* line 561 | pCaps */
        "movl $0x3030300, 0x44(%ebx)\n" /* line 566 | pCaps */
        "calll MacDisplay_GetSupportsAnisotropicFiltering\n" /* line 569 */
        "testb %al, %al\n"
        "je .Lf13c06_00013cf9\n"
        "orl $0x4000400, 0x40(%ebx)\n" /* line 571 | pCaps */
        "orl $0x4000400, 0x44(%ebx)\n" /* line 572 | pCaps */
        ".Lf13c06_00013cf9:\n"
        "movl $0, 0x48(%ebx)\n" /* line 579 | pCaps */
        "movl $0xd, 0x4c(%ebx)\n" /* line 582 | pCaps */
        "movl $0, 0x50(%ebx)\n" /* line 584 | pCaps */
        "movl $0, 0x54(%ebx)\n" /* line 585 | pCaps */
        "movl $0, 0x60(%ebx)\n" /* line 586 | pCaps */
        "movl $0, 0x64(%ebx)\n" /* line 587 | pCaps */
        "movl $0x800, 0x68(%ebx)\n" /* line 589 | pCaps */
        "calll MacDisplay_GetSupportsAnisotropicFiltering\n" /* line 591 */
        "testb %al, %al\n"
        "jne .Lf13c06_00013ea4\n"
        ".Lf13c06_00013d37:\n"
        "xorl %eax, %eax\n" /* line 599 */
        "movl %eax, 0x70(%ebx)\n" /* pCaps */
        "movl %eax, 0x74(%ebx)\n" /* line 600 | pCaps */
        "movl %eax, 0x78(%ebx)\n" /* line 601 | pCaps */
        "movl %eax, 0x7c(%ebx)\n" /* line 602 | pCaps */
        "movl %eax, 0x80(%ebx)\n" /* line 603 | pCaps */
        "movl %eax, 0x84(%ebx)\n" /* line 604 | pCaps */
        "movl $0xff, 0x88(%ebx)\n" /* line 614 | pCaps */
        "movl $0, 0x8c(%ebx)\n" /* line 616 | pCaps */
        "movl $0x3feffff, 0x90(%ebx)\n" /* line 650 | pCaps */
        "movl $0x3b, 0x9c(%ebx)\n" /* line 657 | pCaps */
        "movl $8, 0xa0(%ebx)\n" /* line 659 | pCaps */
        "movl $0, 0xa4(%ebx)\n" /* line 660 | pCaps */
        "movl $0, 0xa8(%ebx)\n" /* line 661 | pCaps */
        "movl $0, 0xac(%ebx)\n" /* line 662 | pCaps */
        "movl $0xffff, 0xb4(%ebx)\n" /* line 664 | pCaps */
        "movl $0xffff, 0xb8(%ebx)\n" /* line 665 | pCaps */
        "movl $0x10, 0xbc(%ebx)\n" /* line 666 | pCaps */
        "movl $0x400, 0xc0(%ebx)\n" /* line 667 | pCaps */
        "movl 0x500(%esi), %eax\n" /* line 671 | this */
        "movl %eax, 0x58(%ebx)\n" /* pCaps */
        "movl 0x500(%esi), %eax\n" /* line 672 | this */
        "movl %eax, 0x5c(%ebx)\n" /* pCaps */
        "movl $0x3f800000, 0xb0(%ebx)\n" /* line 674 | pCaps */
        "movl $0xfffe0200, 0xc4(%ebx)\n" /* line 676 | pCaps */
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 677 */
        "movl %eax, 0xcc(%ebx)\n" /* pCaps */
        "movl $0x100, 0xc8(%ebx)\n" /* line 678 | pCaps */
        "movl $0x41000000, 0xd0(%ebx)\n" /* line 679 | pCaps */
        "calll MacDisplay_GetMaxTextureImageUnits\n" /* line 682 */
        "movl %eax, -0x10(%ebp)\n" /* __b */
        "calll MacDisplay_GetMaxTextureUnits\n"
        "movl %eax, -0xc(%ebp)\n" /* __b */
        /* { scope 1 */
        "cmpl -0x10(%ebp), %eax\n" /* line 211 */
        "jge .Lf13c06_00013e9f\n"
        "leal -0x10(%ebp), %eax\n"
        /* } scope */
        ".Lf13c06_00013e26:\n"
        "movl (%eax), %eax\n" /* line 682 | __b */
        "movl %eax, 0x98(%ebx)\n" /* __b, pCaps */
        "movl %eax, 0x94(%ebx)\n" /* __b, pCaps */
        "movl $1, 0xd4(%ebx)\n" /* line 691 | pCaps */
        "movl $0, 0xd8(%ebx)\n" /* line 692 | pCaps */
        "movl $0, 0xec(%ebx)\n" /* line 693 | pCaps */
        "movl $1, 0xf0(%ebx)\n" /* line 694 | pCaps */
        "movl $0x200, 0xf4(%ebx)\n" /* line 696 | pCaps */
        "movl $0, 0x11c(%ebx)\n" /* line 717 | pCaps */
        "movl $0, 0x120(%ebx)\n" /* line 718 | pCaps */
        "movl $0, 0x124(%ebx)\n" /* line 719 | pCaps */
        "movl $0, 0x128(%ebx)\n" /* line 720 | pCaps */
        "xorl %eax, %eax\n" /* line 723 */
        "addl $0x30, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf13c06_00013e97:\n"
        "movl 0x24(%ebx), %eax\n" /* pCaps */
        "jmp .Lf13c06_00013c98\n"
        /* { scope 1 */
        ".Lf13c06_00013e9f:\n"
        "leal -0xc(%ebp), %eax\n" /* line 211 */
        "jmp .Lf13c06_00013e26\n"
        /* } scope */
        ".Lf13c06_00013ea4:\n"
        "calll MacDisplay_GetMaxSupportedAnisotropy\n" /* line 593 */
        "fnstcw -0x1a(%ebp)\n"
        "movzwl -0x1a(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0x1c(%ebp)\n"
        "fldcw -0x1c(%ebp)\n"
        "fistpll -0x28(%ebp)\n"
        "fldcw -0x1a(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x6c(%ebx)\n" /* pCaps */
        "jmp .Lf13c06_00013d37\n"
    );
}

/* line 731 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetDisplayMode(const CDirect3DDevice * _this, UINT iSwapChain, D3DDISPLAYMODE *pMode)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 731 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 742 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1225 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetBackBuffer(const CDirect3DDevice * _this, UINT iSwapChain, UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9 * *ppBackBuffer)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1225 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x1c(%ecx), %edx\n" /* line 1232 */
        "movl 0x18(%ebp), %eax\n" /* ppBackBuffer */
        "movl %edx, (%eax)\n"
        "movl 0x1c(%ecx), %eax\n" /* line 1233 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 1236 */
        "leave\n"
        "retl\n"
    );
}

/* line 1245 */
__attribute__((naked))
long unsigned int CDirect3DDevice_SetGammaRamp(const CDirect3DDevice * _this, UINT iSwapChain, DWORD Flags, const D3DGAMMARAMP *pRamp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1245 */
        "movl %esp, %ebp\n"
        "movl 0x14(%ebp), %eax\n" /* line 1249 | pRamp */
        "movl %eax, 8(%ebp)\n" /* this */
        "popl %ebp\n" /* line 1253 */
        "jmp MacDisplay_SetGammaRamp\n" /* line 1249 */
    );
}

/* line 1261 */
__attribute__((naked))
long unsigned int CDirect3DDevice_GetGammaRamp(const CDirect3DDevice * _this, UINT iSwapChain, D3DGAMMARAMP *pRamp)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1261 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 1264 */
        "retl\n"
    );
}

/* line 1278 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateTexture(const CDirect3DDevice * _this, UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9 * *ppTexture, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1278 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x68, (%esp)\n" /* line 1302 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x1c(%ebp), %eax\n" /* Format */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* Usage */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Levels */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Width */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DTexture_CDirect3DTexture\n"
        "movl 0x24(%ebp), %eax\n" /* ppTexture */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 1305 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 1302 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1320 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateVolumeTexture(const CDirect3DDevice * _this, UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9 * *ppVolumeTexture, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1320 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x6c, (%esp)\n" /* line 1322 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x20(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x1c(%ebp), %eax\n" /* Usage */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* Levels */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Depth */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Height */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Width */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DVolumeTexture_CDirect3DVolumeTexture\n"
        "movl 0x28(%ebp), %eax\n" /* ppVolumeTexture */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 1325 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 1322 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1338 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateCubeTexture(const CDirect3DDevice * _this, UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9 * *ppCubeTexture, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1338 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x7c, (%esp)\n" /* line 1340 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x18(%ebp), %eax\n" /* Format */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Usage */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Levels */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* EdgeLength */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DCubeTexture_CDirect3DCubeTexture\n"
        "movl 0x20(%ebp), %eax\n" /* ppCubeTexture */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 1343 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 1340 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1349 */
__attribute__((naked))
HRESULT CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9 * *ppVolumeTexture, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1349 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl $0x6c, (%esp)\n" /* line 1351 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x1c(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* Usage */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Levels */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Depth */
        "movl %eax, 0xc(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Height */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %eax\n" /* Width */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DVolumeTexture_CDirect3DVolumeTexture\n"
        "movl 0x24(%ebp), %eax\n" /* ppVolumeTexture */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 1354 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 1351 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1366 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateVertexBuffer(const CDirect3DDevice * _this, UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9 * *ppVertexBuffer, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1366 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl $0x3c, (%esp)\n" /* line 1372 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0x18(%ebp), %eax\n" /* Pool */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Usage */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* Length */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DVertexBuffer_CDirect3DVertexBuffer\n"
        "movl 0x1c(%ebp), %eax\n" /* ppVertexBuffer */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 1375 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 1372 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 1383 */
__attribute__((naked))
HRESULT CDirect3DDevice_UpdateTexture(const CDirect3DDevice * _this, IDirect3DBaseTexture9 *pSourceTexture, IDirect3DBaseTexture9 *pDestinationTexture)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1383 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 1389 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2109 */
__attribute__((naked))
long unsigned int CDirect3DDevice_StartPixelOneToOneState(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2109 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $1, 0xc(%esp)\n" /* line 2118 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl $0, (%esp)\n" /* line 2124 */
        "calll glStencilMask\n"
        "movl $0xbc0, (%esp)\n" /* line 2131 */
        "calll glDisable\n"
        "movl $0xb71, (%esp)\n" /* line 2136 */
        "calll glDisable\n"
        "movl $0xbe2, (%esp)\n" /* line 2140 */
        "calll glDisable\n"
        "movl $0xbd0, (%esp)\n" /* line 2144 */
        "calll glDisable\n"
        "movl $0xb50, (%esp)\n" /* line 2148 */
        "calll glDisable\n"
        "movl $0xb60, (%esp)\n" /* line 2152 */
        "calll glDisable\n"
        /* { scope 1 */
        "movl 0x504(%ebx), %edx\n" /* line 2157 | this */
        "movl %edx, %eax\n" /* i */
        "subl $1, %eax\n" /* i */
        "js .Lf140f0_000141be\n"
        "leal 0x84bf(%edx), %ebx\n" /* this */
        "movl $0x84bf, %esi\n"
        ".Lf140f0_0001418b:\n"
        "movl %ebx, (%esp)\n" /* line 2160 | this */
        "calll glActiveTextureARB\n"
        "movl $0xde1, (%esp)\n" /* line 2164 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 2167 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 2170 */
        "calll glDisable\n"
        "subl $1, %ebx\n" /* this */
        "cmpl %esi, %ebx\n" /* line 2157 | this */
        "jne .Lf140f0_0001418b\n"
        /* } scope */
        ".Lf140f0_000141be:\n"
        "movl $0xb90, (%esp)\n" /* line 2175 */
        "calll glDisable\n"
        "movl $0, (%esp)\n" /* line 2180 */
        "calll glDepthMask\n"
        "movl $0x207, (%esp)\n" /* line 2184 */
        "calll glDepthFunc\n"
        "movl $0x1d00, (%esp)\n" /* line 2188 */
        "calll glShadeModel\n"
        "movl $0xb44, 8(%ebp)\n" /* line 2191 | this */
        "addl $0x10, %esp\n" /* line 2194 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp glDisable\n" /* line 2191 */
    );
}

/* line 2310 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetDepthStencilSurface(const CDirect3DDevice * _this, IDirect3DSurface9 * *ppZStencilSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2310 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x20(%ecx), %edx\n" /* line 2314 */
        "movl 0xc(%ebp), %eax\n" /* ppZStencilSurface */
        "movl %edx, (%eax)\n"
        "movl 0x20(%ecx), %eax\n" /* line 2315 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 2318 */
        "leave\n"
        "retl\n"
    );
}

/* line 2323 */
__attribute__((naked))
HRESULT CDirect3DDevice_BeginScene(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2323 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 2329 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2334 */
__attribute__((naked))
HRESULT CDirect3DDevice_EndScene(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2334 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n" /* line 2340 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2510 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetTransform(const CDirect3DDevice * _this, D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2510 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0xc(%ebp), %eax\n" /* State */
        "movl 0x10(%ebp), %ecx\n" /* pMatrix */
        "cmpl $0x100, %eax\n" /* line 2512 */
        "je .Lf14230_000142ca\n"
        "cmpl $2, %eax\n" /* line 2516 */
        "je .Lf14230_000142dd\n"
        "cmpl $3, %eax\n" /* line 2520 */
        "je .Lf14230_00014258\n"
        "xorl %eax, %eax\n" /* line 2530 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14230_00014258:\n"
        "movl 8(%ebp), %eax\n" /* line 2522 | this */
        "addl $0x4b8, %eax\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x4b8(%ebx), %edx\n"
        ".Lf14230_00014269:\n"
        "movl %edx, (%ecx)\n"
        "movl 4(%eax), %edx\n"
        "movl %edx, 4(%ecx)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, 8(%ecx)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, 0xc(%ecx)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, 0x10(%ecx)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, 0x14(%ecx)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, 0x18(%ecx)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, 0x1c(%ecx)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, 0x20(%ecx)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, 0x24(%ecx)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, 0x28(%ecx)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, 0x2c(%ecx)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, 0x30(%ecx)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, 0x34(%ecx)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, 0x38(%ecx)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, 0x3c(%ecx)\n"
        "xorl %eax, %eax\n" /* line 2530 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14230_000142ca:\n"
        "movl 8(%ebp), %eax\n" /* line 2514 | this */
        "addl $0x3b0, %eax\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x3b0(%ebx), %edx\n"
        "jmp .Lf14230_00014269\n"
        ".Lf14230_000142dd:\n"
        "movl 8(%ebp), %eax\n" /* line 2518 | this */
        "addl $0x3f0, %eax\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x3f0(%ebx), %edx\n"
        "jmp .Lf14230_00014269\n"
    );
}

/* line 2539 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetViewport(const CDirect3DDevice * _this, const D3DVIEWPORT9 *pViewport)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2539 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* pViewport */
        "movl 8(%ebp), %eax\n" /* line 2547 | this */
        "addl $0x5f0, %eax\n"
        "movl $0x18, -0x3c(%ebp)\n"
        "cld\n"
        "movl %eax, %esi\n"
        "movl %ebx, %edi\n" /* pViewport */
        "movl $0x18, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf142f4_0001432c\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf142f4_0001432c:\n"
        "testl %eax, %eax\n"
        "je .Lf142f4_000143bc\n"
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 2549 | pViewport */
        "movl 8(%ebp), %ecx\n" /* this */
        "movl %eax, 0x5f0(%ecx)\n"
        "movl 4(%ebx), %eax\n" /* pViewport */
        "movl %eax, 0x5f4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* pViewport */
        "movl %eax, 0x5f8(%ecx)\n"
        "movl 0xc(%ebx), %eax\n" /* pViewport */
        "movl %eax, 0x5fc(%ecx)\n"
        "movl 0x10(%ebx), %eax\n" /* pViewport */
        "movl %eax, 0x600(%ecx)\n"
        "movl 0x14(%ebx), %eax\n" /* pViewport */
        "movl %eax, 0x604(%ecx)\n"
        "movl 0x14(%ecx), %edx\n" /* line 2553 */
        "movl (%edx), %ecx\n"
        "leal -0x38(%ebp), %eax\n" /* RenderTargetDesc */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%ecx)\n"
        "movl 0xc(%ebx), %edx\n" /* line 2555 | pViewport */
        "movl %edx, 0xc(%esp)\n"
        "movl 8(%ebx), %eax\n" /* pViewport */
        "movl %eax, 8(%esp)\n"
        "addl 4(%ebx), %edx\n" /* pViewport */
        "movl -0x1c(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n" /* pViewport */
        "movl %eax, (%esp)\n"
        "calll glViewport\n"
        "cvtss2sd 0x14(%ebx), %xmm0\n" /* line 2556 | pViewport */
        "movsd %xmm0, 8(%esp)\n"
        "cvtss2sd 0x10(%ebx), %xmm0\n" /* pViewport */
        "movsd %xmm0, (%esp)\n"
        "calll glDepthRange\n"
        /* } scope */
        ".Lf142f4_000143bc:\n"
        "xorl %eax, %eax\n" /* line 2562 */
        "addl $0x7c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2720 */
__attribute__((naked))
long unsigned int CDirect3DDevice_SetAlphaFuncAndRef(const CDirect3DDevice * _this, DWORD AlphaFuncValue, DWORD AlphaRefValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2720 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* AlphaFuncValue */
        "movl 0x10(%ebp), %edx\n" /* AlphaRefValue */
        /* { scope 1 */
        "cmpl %edx, 0x510(%ecx)\n" /* line 2726 */
        "je .Lf143c6_00014438\n"
        "movl %edx, 0x510(%ecx)\n" /* line 2728 */
        "testl %edx, %edx\n" /* line 2729 */
        "js .Lf143c6_0001443c\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf143c6_000143e9:\n"
        "divss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "movss %xmm0, 0x3a8(%ecx)\n"
        "movl $1, %eax\n"
        ".Lf143c6_000143fe:\n"
        "cmpl %ebx, 0x514(%ecx)\n" /* line 2734 | AlphaFuncValue */
        "je .Lf143c6_00014431\n"
        "movl %ebx, 0x514(%ecx)\n" /* line 2736 | AlphaFuncValue */
        "cmpl $8, %ebx\n" /* line 2737 | AlphaFuncValue */
        "jbe .Lf143c6_0001442a\n"
        ".Lf143c6_00014411:\n"
        "movl 0x3a8(%ecx), %eax\n" /* line 2755 */
        "movl %eax, 0xc(%ebp)\n" /* AlphaFuncValue */
        "movl 0x3ac(%ecx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* this */
        /* } scope */
        "popl %ebx\n" /* line 2757 */
        "popl %ebp\n"
        /* { scope 1 */
        "jmp glAlphaFunc\n" /* line 2755 */
        ".Lf143c6_0001442a:\n"
        "jmpl *.Ljt_2edf00(, %ebx, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2edf00:\n"
        ".long .Lf143c6_00014411\n"
        ".long .Lf143c6_0001444f\n"
        ".long .Lf143c6_000144a9\n"
        ".long .Lf143c6_0001449a\n"
        ".long .Lf143c6_0001448b\n"
        ".long .Lf143c6_0001447f\n"
        ".long .Lf143c6_00014473\n"
        ".long .Lf143c6_00014467\n"
        ".long .Lf143c6_0001445b\n"
        ".popsection\n"
        ".Lf143c6_00014431:\n"
        "testb %al, %al\n" /* line 2753 */
        "jne .Lf143c6_00014411\n"
        /* } scope */
        "popl %ebx\n" /* line 2757 */
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf143c6_00014438:\n"
        "xorl %eax, %eax\n" /* line 2726 */
        "jmp .Lf143c6_000143fe\n"
        ".Lf143c6_0001443c:\n"
        "movl %edx, %eax\n" /* line 2729 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf143c6_000143e9\n"
        ".Lf143c6_0001444f:\n"
        "movl $0x200, 0x3ac(%ecx)\n" /* line 2739 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_0001445b:\n"
        "movl $0x207, 0x3ac(%ecx)\n" /* line 2746 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_00014467:\n"
        "movl $0x206, 0x3ac(%ecx)\n" /* line 2745 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_00014473:\n"
        "movl $0x205, 0x3ac(%ecx)\n" /* line 2744 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_0001447f:\n"
        "movl $0x204, 0x3ac(%ecx)\n" /* line 2743 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_0001448b:\n"
        "movl $0x203, 0x3ac(%ecx)\n" /* line 2742 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_0001449a:\n"
        "movl $0x202, 0x3ac(%ecx)\n" /* line 2741 */
        "jmp .Lf143c6_00014411\n"
        ".Lf143c6_000144a9:\n"
        "movl $0x201, 0x3ac(%ecx)\n" /* line 2740 */
        "jmp .Lf143c6_00014411\n"
    );
}

/* line 2763 */
__attribute__((naked))
GLenum CDirect3DDevice_GetStencilOpFunc(const CDirect3DDevice * _this, UINT32 Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2763 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* Value */
        /* { scope 1 */
        "cmpl $8, %eax\n" /* line 2769 */
        "ja .Lf144b8_000144ca\n"
        "jmpl *.Ljt_2edf24(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2edf24:\n"
        ".long .Lf144b8_000144ca\n"
        ".long .Lf144b8_000144ce\n"
        ".long .Lf144b8_000144ca\n"
        ".long .Lf144b8_000144f8\n"
        ".long .Lf144b8_000144f1\n"
        ".long .Lf144b8_000144ea\n"
        ".long .Lf144b8_000144e3\n"
        ".long .Lf144b8_000144dc\n"
        ".long .Lf144b8_000144d5\n"
        ".popsection\n"
        ".Lf144b8_000144ca:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144ce:\n"
        "movl $0x1e00, %eax\n" /* line 2769 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144d5:\n"
        "movl $0x8508, %eax\n" /* line 2769 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144dc:\n"
        "movl $0x8507, %eax\n" /* line 2776 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144e3:\n"
        "movl $0x150a, %eax\n" /* line 2775 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144ea:\n"
        "movl $0x1e03, %eax\n" /* line 2774 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144f1:\n"
        "movl $0x1e02, %eax\n" /* line 2773 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
        /* { scope 1 */
        ".Lf144b8_000144f8:\n"
        "movl $0x1e01, %eax\n" /* line 2771 */
        /* } scope */
        "popl %ebp\n" /* line 2788 */
        "retl\n"
    );
}

/* line 3720 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetRenderState(const CDirect3DDevice * _this, D3DRENDERSTATETYPE State, DWORD *pValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3720 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %eax\n" /* State */
        "cmpl $0x18, %eax\n" /* line 3722 */
        "je .Lf14500_0001455d\n"
        "jle .Lf14500_00014532\n"
        "cmpl $0x3c, %eax\n"
        "je .Lf14500_000145ab\n"
        "jle .Lf14500_0001456f\n"
        "cmpl $0xa8, %eax\n"
        "je .Lf14500_000145f4\n"
        "cmpl $0xce, %eax\n"
        "je .Lf14500_000145cf\n"
        ".Lf14500_0001452e:\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_00014532:\n"
        "cmpl $0x13, %eax\n" /* line 3722 */
        "je .Lf14500_000145bd\n"
        "jle .Lf14500_0001458f\n"
        "cmpl $0x14, %eax\n"
        "je .Lf14500_00014618\n"
        "cmpl $0x16, %eax\n"
        "jne .Lf14500_0001452e\n"
        ".Lf14500_0001454b:\n"
        "movl 8(%ebp), %edx\n" /* line 3750 | this */
        "movl 0x538(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_0001455d:\n"
        "movl 8(%ebp), %edx\n" /* line 3725 | this */
        "movl 0x510(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_0001456f:\n"
        "cmpl $0x19, %eax\n" /* line 3722 */
        "je .Lf14500_00014606\n"
        "cmpl $0x1b, %eax\n"
        "jne .Lf14500_0001452e\n"
        "movl 8(%ebp), %edx\n" /* line 3745 | this */
        "movl 0x548(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_0001458f:\n"
        "cmpl $0xe, %eax\n" /* line 3722 */
        "je .Lf14500_000145e2\n"
        "cmpl $0xf, %eax\n"
        "jne .Lf14500_0001452e\n"
        "movl 8(%ebp), %edx\n" /* line 3728 | this */
        "movl 0x50c(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_000145ab:\n"
        "movl 8(%ebp), %edx\n" /* line 3742 | this */
        "movl 0x578(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_000145bd:\n"
        "movl 8(%ebp), %edx\n" /* line 3735 | this */
        "movl 0x51c(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_000145cf:\n"
        "movl 8(%ebp), %edx\n" /* line 3748 | this */
        "movl 0x54c(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "jmp .Lf14500_0001454b\n"
        ".Lf14500_000145e2:\n"
        "movl 8(%ebp), %edx\n" /* line 3756 | this */
        "movl 0x544(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_000145f4:\n"
        "movl 8(%ebp), %edx\n" /* line 3753 | this */
        "movl 0x590(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_00014606:\n"
        "movl 8(%ebp), %edx\n" /* line 3731 | this */
        "movl 0x514(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
        ".Lf14500_00014618:\n"
        "movl 8(%ebp), %edx\n" /* line 3739 | this */
        "movl 0x524(%edx), %eax\n"
        "movl 0x10(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3762 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4133 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateVertexDeclaration(const CDirect3DDevice * _this, const D3DVERTEXELEMENT9 *pVertexElements, IDirect3DVertexDeclaration9 * *ppDecl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4133 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl $0x10, (%esp)\n" /* line 4135 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0xc(%ebp), %eax\n" /* pVertexElements */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DVertexDeclaration_CDirect3DVertexDeclaration\n"
        "movl 0x10(%ebp), %eax\n" /* ppDecl */
        "movl %esi, (%eax)\n"
        "xorl %eax, %eax\n" /* line 4138 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %ebx\n"
        "movl %esi, (%esp)\n" /* line 4135 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 4175 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateVertexShader(const CDirect3DDevice * _this, const DWORD *pFunction, IDirect3DVertexShader9 * *ppShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4175 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x420, %esp\n"
        /* { scope 1: MyError */
        "movl $0x19c, (%esp)\n" /* line 4179 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl 0xc(%ebp), %eax\n" /* pFunction */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DVertexShader_CDirect3DVertexShader\n"
        "movl 0x10(%ebp), %eax\n" /* ppShader */
        "movl %esi, (%eax)\n"
        "leal -0xc(%ebp), %eax\n" /* line 4182 | ErrorPosition */
        "movl %eax, 4(%esp)\n"
        "movl $0x864b, (%esp)\n"
        "calll glGetIntegerv\n"
        "cmpl $-1, -0xc(%ebp)\n" /* line 4185 | ErrorPosition */
        "jne .Lf14670_000146c2\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf14670_000146b8:\n"
        "addl $0x420, %esp\n" /* line 4203 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: MyError */
        /* { scope 2 */
        ".Lf14670_000146c2:\n"
        "movl $0x8874, (%esp)\n" /* line 4189 */
        "calll glGetString\n"
        "movl %eax, 8(%esp)\n" /* line 4192 */
        "movl $str_00215bbc, 4(%esp)\n" /* "%s
" */
        "leal -0x40c(%ebp), %eax\n" /* MyError */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "movl $0x8876086c, %eax\n"
        "jmp .Lf14670_000146b8\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 4179 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n"
        "calll __Unwind_Resume\n"
    );
}

/* line 4397 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetStreamSource(const CDirect3DDevice * _this, UINT StreamNumber, IDirect3DVertexBuffer9 * *ppStreamData, UINT *pOffsetInBytes, UINT *pStride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4397 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* StreamNumber */
        "movl 0x24(%esi, %ebx, 4), %edx\n" /* line 4401 | this */
        "movl 0x10(%ebp), %eax\n" /* ppStreamData */
        "movl %edx, (%eax)\n"
        "movl 0x24(%esi, %ebx, 4), %edx\n" /* line 4403 | this */
        "testl %edx, %edx\n"
        "je .Lf14704_0001472b\n"
        "movl (%edx), %eax\n" /* line 4405 */
        "movl %edx, (%esp)\n"
        "calll *4(%eax)\n"
        ".Lf14704_0001472b:\n"
        "movl 0xac(%esi, %ebx, 4), %edx\n" /* line 4408 | this */
        "movl 0x18(%ebp), %eax\n" /* pStride */
        "movl %edx, (%eax)\n"
        "movl 0x64(%esi, %ebx, 4), %edx\n" /* line 4409 | this */
        "movl 0x14(%ebp), %eax\n" /* pOffsetInBytes */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* line 4412 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 303 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateDepthStencilSurface(const CDirect3DDevice * _this, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9 * *ppSurface, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 303 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* Height */
        /* { scope 1 */
        "movl imp_g_NoTextureID, %eax\n" /* line 309 */
        "cmpb $0, (%eax)\n"
        "je .Lf1474c_000147e9\n"
        "xorl %ebx, %ebx\n" /* p */
        ".Lf1474c_00014768:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 311 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x8069, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x3c, (%esp)\n" /* line 313 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl $0, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* p */
        "movl 0x14(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* Height */
        "movl 0xc(%ebp), %eax\n" /* Width */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DSurface_CDirect3DSurface\n"
        "movl 0x24(%ebp), %eax\n" /* ppSurface */
        "movl %esi, (%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 314 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 318 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf1474c_000147e9:\n"
        "cmpl $1, %edi\n" /* line 144 */
        "ja .Lf1474c_00014830\n"
        "movl $1, %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1474c_000147f3:\n"
        "cmpl $1, 0xc(%ebp)\n" /* Width */
        "ja .Lf1474c_0001484b\n"
        ".Lf1474c_000147f9:\n"
        "movl $1, %ecx\n"
        /* } scope */
        ".Lf1474c_000147fe:\n"
        "leal 0x14(%ebp), %eax\n" /* line 309 | Format */
        "movl %eax, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* p */
        "jmp .Lf1474c_00014768\n"
        ".Lf1474c_00014830:\n"
        "movl $1, %edx\n"
        "movl $0x20, %eax\n"
        /* { scope 2 */
        ".Lf1474c_0001483a:\n"
        "addl %edx, %edx\n" /* line 144 */
        "cmpl %edx, %edi\n"
        "jbe .Lf1474c_000147f3\n"
        "subl $1, %eax\n"
        "jne .Lf1474c_0001483a\n"
        /* } scope */
        /* { scope 2 */
        "cmpl $1, 0xc(%ebp)\n" /* Width */
        "jbe .Lf1474c_000147f9\n"
        ".Lf1474c_0001484b:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lf1474c_00014855:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* Width */
        "jbe .Lf1474c_000147fe\n"
        "subl $1, %eax\n"
        "jne .Lf1474c_00014855\n"
        "jmp .Lf1474c_000147fe\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 313 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n" /* p */
        "calll __Unwind_Resume\n"
    );
}

/* line 332 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateRenderTarget(const CDirect3DDevice * _this, UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9 * *ppSurface, HANDLE *pSharedHandle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 332 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x10(%ebp), %edi\n" /* Height */
        /* { scope 1 */
        "movl imp_g_NoTextureID, %eax\n" /* line 338 */
        "cmpb $0, (%eax)\n"
        "je .Lf14876_00014913\n"
        "xorl %ebx, %ebx\n" /* p */
        ".Lf14876_00014892:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 341 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x8069, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x3c, (%esp)\n" /* line 343 */
        "calll __Znwm\n"
        "movl %eax, %esi\n"
        "movl $0, 0x20(%esp)\n"
        "movl %ebx, 0x1c(%esp)\n" /* p */
        "movl 0x14(%ebp), %eax\n" /* Format */
        "movl %eax, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* Height */
        "movl 0xc(%ebp), %eax\n" /* Width */
        "movl %eax, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll CDirect3DSurface_CDirect3DSurface\n"
        "movl 0x24(%ebp), %eax\n" /* ppSurface */
        "movl %esi, (%eax)\n"
        "movl -0x1c(%ebp), %eax\n" /* line 344 | CurrentTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 348 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf14876_00014913:\n"
        "cmpl $1, %edi\n" /* line 144 */
        "ja .Lf14876_0001495a\n"
        "movl $1, %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf14876_0001491d:\n"
        "cmpl $1, 0xc(%ebp)\n" /* Width */
        "ja .Lf14876_00014975\n"
        ".Lf14876_00014923:\n"
        "movl $1, %ecx\n"
        /* } scope */
        ".Lf14876_00014928:\n"
        "leal 0x14(%ebp), %eax\n" /* line 338 | Format */
        "movl %eax, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll MacOpenGLUtils_GetImageSizeInBytes\n"
        "movl %eax, (%esp)\n"
        "calll __Znam\n"
        "movl %eax, %ebx\n" /* p */
        "jmp .Lf14876_00014892\n"
        ".Lf14876_0001495a:\n"
        "movl $1, %edx\n"
        "movl $0x20, %eax\n"
        /* { scope 2 */
        ".Lf14876_00014964:\n"
        "addl %edx, %edx\n" /* line 144 */
        "cmpl %edx, %edi\n"
        "jbe .Lf14876_0001491d\n"
        "subl $1, %eax\n"
        "jne .Lf14876_00014964\n"
        /* } scope */
        /* { scope 2 */
        "cmpl $1, 0xc(%ebp)\n" /* Width */
        "jbe .Lf14876_00014923\n"
        ".Lf14876_00014975:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lf14876_0001497f:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, 0xc(%ebp)\n" /* Width */
        "jbe .Lf14876_00014928\n"
        "subl $1, %eax\n"
        "jne .Lf14876_0001497f\n"
        "jmp .Lf14876_00014928\n"
        "movl %eax, %ebx\n"
        /* } scope */
        "movl %esi, (%esp)\n" /* line 343 */
        "calll __ZdlPv\n"
        "movl %ebx, (%esp)\n" /* p */
        "calll __Unwind_Resume\n"
    );
}

/* line 4143 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetVertexDeclaration(const CDirect3DDevice * _this, IDirect3DVertexDeclaration9 *pDecl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4143 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        "movl 0xc(%ebp), %ebx\n" /* pDecl */
        "cmpl %ebx, 0xbbc(%esi)\n" /* line 4145 | pDecl, this */
        "je .Lf149a0_000149dc\n"
        "leal 0xbcc(%esi), %eax\n" /* line 4147 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pDecl */
        "calll CDirect3DVertexDeclaration_GetShaderDeclaration\n"
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        "movl %ebx, 0xbbc(%esi)\n" /* line 4152 | pDecl, this */
        ".Lf149a0_000149dc:\n"
        "xorl %eax, %eax\n" /* line 4158 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4222 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetVertexShader(const CDirect3DDevice * _this, IDirect3DVertexShader9 *pShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4222 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* pShader */
        "cmpl %eax, 0xbb4(%edx)\n" /* line 4224 */
        "je .Lf149e6_00014a12\n"
        "movl %eax, 0xbb4(%edx)\n" /* line 4232 */
        "movb $1, __ZN15CDirect3DDevice28mNeedsVertexShaderValidationE\n" /* line 644 */
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        ".Lf149e6_00014a12:\n"
        "xorl %eax, %eax\n" /* line 4240 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 4277 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetFVF(const CDirect3DDevice * _this, DWORD FVF)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4277 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* FVF */
        /* { scope 1 */
        "leal 0xbcc(%eax), %ebx\n" /* line 4279 | pDeclaration */
        "testl %esi, %esi\n" /* line 4281 | FVF */
        "je .Lf14a16_00014ae3\n"
        /* { scope 2 */
        "movl $0x20000000, 0xbcc(%eax)\n" /* line 4294 */
        "leal 0xbd0(%eax), %edx\n"
        "testl $2, %esi\n" /* line 4296 | FVF */
        "jne .Lf14a16_00014afe\n"
        "movl %edx, %ebx\n" /* pDeclaration */
        ".Lf14a16_00014a4e:\n"
        "testl $0x10, %esi\n" /* line 4301 | FVF */
        "je .Lf14a16_00014a5f\n"
        "movl $0x40020003, (%ebx)\n" /* line 4303 | pDeclaration */
        "addl $4, %ebx\n" /* pDeclaration */
        ".Lf14a16_00014a5f:\n"
        "testl $0x40, %esi\n" /* line 4306 | FVF */
        "je .Lf14a16_00014a70\n"
        "movl $0x40040005, (%ebx)\n" /* line 4308 | pDeclaration */
        "addl $4, %ebx\n" /* pDeclaration */
        ".Lf14a16_00014a70:\n"
        "movl %esi, %eax\n" /* line 4313 | FVF */
        "andl $0xf00, %eax\n"
        "je .Lf14a16_00014ae3\n"
        /* { scope 3 */
        "shrl $8, %eax\n" /* line 4317 */
        "je .Lf14a16_00014ae3\n"
        "movl $8, %edx\n"
        "leal 8(%eax), %edi\n"
        "jmp .Lf14a16_00014ab4\n"
        ".Lf14a16_00014a88:\n"
        "cmpl $2, %eax\n" /* line 4323 */
        "je .Lf14a16_00014b1a\n"
        "cmpl $3, %eax\n"
        "je .Lf14a16_00014b24\n"
        "movl $0xffffffff, %eax\n"
        ".Lf14a16_00014a9f:\n"
        "shll $0x10, %eax\n" /* line 4339 */
        "orl %edx, %eax\n"
        "orl $0x40000000, %eax\n"
        "movl %eax, -0x20(%ebx, %edx, 4)\n" /* pDeclaration */
        "addl $1, %edx\n" /* line 4341 */
        "cmpl %edx, %edi\n" /* line 4317 */
        "je .Lf14a16_00014adf\n"
        ".Lf14a16_00014ab4:\n"
        "leal (%edx, %edx), %ecx\n" /* line 4323 */
        "movl %esi, %eax\n" /* FVF */
        "shrl %cl, %eax\n"
        "andl $3, %eax\n"
        "cmpl $1, %eax\n"
        "je .Lf14a16_00014b13\n"
        "jae .Lf14a16_00014a88\n"
        "movl $1, %eax\n" /* line 4327 */
        "shll $0x10, %eax\n" /* line 4339 */
        "orl %edx, %eax\n"
        "orl $0x40000000, %eax\n"
        "movl %eax, -0x20(%ebx, %edx, 4)\n" /* pDeclaration */
        "addl $1, %edx\n" /* line 4341 */
        "cmpl %edx, %edi\n" /* line 4317 */
        "jne .Lf14a16_00014ab4\n"
        ".Lf14a16_00014adf:\n"
        "leal -0x20(%ebx, %edx, 4), %ebx\n" /* pDeclaration */
        /* } scope */
        /* } scope */
        ".Lf14a16_00014ae3:\n"
        "movl $0xffffffff, (%ebx)\n" /* line 4346 | pDeclaration */
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        /* } scope */
        "xorl %eax, %eax\n" /* line 4354 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf14a16_00014afe:\n"
        "movl $0x40020000, 0xbd0(%eax)\n" /* line 4298 */
        "leal 0xbd4(%eax), %ebx\n" /* pDeclaration */
        "jmp .Lf14a16_00014a4e\n"
        /* { scope 3 */
        ".Lf14a16_00014b13:\n"
        "movl $2, %eax\n" /* line 4330 */
        "jmp .Lf14a16_00014a9f\n"
        ".Lf14a16_00014b1a:\n"
        "movl $3, %eax\n" /* line 4323 */
        "jmp .Lf14a16_00014a9f\n"
        ".Lf14a16_00014b24:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf14a16_00014a9f\n"
    );
}

/* line 2352 */
__attribute__((naked))
HRESULT CDirect3DDevice_Clear(const CDirect3DDevice * _this, DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2352 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x14(%ebp), %edi\n" /* Flags */
        "movl 0x18(%ebp), %esi\n" /* Color */
        /* { scope 1 */
        "movl %edi, %eax\n" /* line 2364 | Flags */
        "andb $1, %al\n"
        "movb %al, -0x39(%ebp)\n"
        "jne .Lf14b2c_00014cda\n"
        "xorl %esi, %esi\n" /* Mask */
        ".Lf14b2c_00014b4d:\n"
        "movl 0x18(%ebx), %eax\n" /* line 2386 | this */
        "testl %eax, %eax\n"
        "je .Lf14b2c_00014bb9\n"
        "testl $2, %edi\n" /* Flags */
        "je .Lf14b2c_00014bad\n"
        "movl 0x544(%ebx), %eax\n" /* line 2391 | this */
        "testl %eax, %eax\n"
        "je .Lf14b2c_00014ec4\n"
        "movl 0x53c(%ebx), %eax\n" /* line 2395 | this */
        "testl %eax, %eax\n"
        "je .Lf14b2c_00014ede\n"
        ".Lf14b2c_00014b78:\n"
        "cmpl $8, 0x540(%ebx)\n" /* line 2399 | this */
        "je .Lf14b2c_00014b8d\n"
        "movl $0x207, (%esp)\n" /* line 2401 */
        "calll glDepthFunc\n"
        ".Lf14b2c_00014b8d:\n"
        "orl $0x100, %esi\n" /* line 2403 | Mask */
        "movss 0x1c(%ebp), %xmm0\n" /* line 2405 | Z */
        "cvtss2sd %xmm0, %xmm0\n"
        "movsd %xmm0, (%esp)\n"
        "calll glClearDepth\n"
        "movl 0x18(%ebx), %eax\n" /* line 2408 | this */
        "testl %eax, %eax\n"
        "je .Lf14b2c_00014bb9\n"
        ".Lf14b2c_00014bad:\n"
        "testl $4, %edi\n" /* Flags */
        "jne .Lf14b2c_00014d9f\n"
        ".Lf14b2c_00014bb9:\n"
        "movl 0x14(%ebx), %edx\n" /* line 2421 | this */
        "movl (%edx), %ecx\n"
        "leal -0x38(%ebp), %eax\n" /* RenderTargetDesc */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%ecx)\n"
        "movl $0xc11, (%esp)\n" /* line 2424 */
        "calll glEnable\n"
        "movl 0x5fc(%ebx), %edx\n" /* line 2425 | this */
        "movl %edx, 0xc(%esp)\n"
        "movl 0x5f8(%ebx), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "addl 0x5f4(%ebx), %edx\n" /* this */
        "movl -0x1c(%ebp), %eax\n"
        "subl %edx, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x5f0(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glScissor\n"
        "movl %esi, (%esp)\n" /* line 2427 | Mask */
        "calll glClear\n"
        "movl $0xc11, (%esp)\n" /* line 2429 */
        "calll glDisable\n"
        "cmpb $0, -0x39(%ebp)\n" /* line 2433 */
        "je .Lf14b2c_00014c69\n"
        "movl 0x590(%ebx), %edx\n" /* line 2435 | this */
        "cmpl $0xf, %edx\n"
        "je .Lf14b2c_00014c5b\n"
        "movl %edx, %eax\n" /* line 2442 */
        "shrl $3, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $2, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "andl $1, %edx\n"
        "movl %edx, (%esp)\n"
        "calll glColorMask\n"
        ".Lf14b2c_00014c5b:\n"
        "movl 0x57c(%ebx), %eax\n" /* line 2445 | this */
        "testl %eax, %eax\n"
        "jne .Lf14b2c_00014dd4\n"
        ".Lf14b2c_00014c69:\n"
        "movl 0x18(%ebx), %esi\n" /* line 2452 | this, Mask */
        "testl %esi, %esi\n" /* Mask */
        "je .Lf14b2c_00014cd0\n"
        "testl $2, %edi\n" /* Flags */
        "je .Lf14b2c_00014cb6\n"
        "movl 0x544(%ebx), %ecx\n" /* line 2454 | this */
        "testl %ecx, %ecx\n"
        "je .Lf14b2c_00014e99\n"
        "movl 0x53c(%ebx), %edx\n" /* line 2458 | this */
        "testl %edx, %edx\n"
        "je .Lf14b2c_00014eb3\n"
        ".Lf14b2c_00014c94:\n"
        "movl 0x540(%ebx), %eax\n" /* line 2463 | this */
        "cmpl $8, %eax\n"
        "je .Lf14b2c_00014caf\n"
        /* { scope 2 */
        "jbe .Lf14b2c_00014dcd\n" /* line 2466 */
        "xorl %eax, %eax\n"
        ".Lf14b2c_00014ca7:\n"
        "movl %eax, (%esp)\n" /* line 2480 */
        "calll glDepthFunc\n"
        /* } scope */
        ".Lf14b2c_00014caf:\n"
        "movl 0x18(%ebx), %eax\n" /* line 2485 | this */
        "testl %eax, %eax\n"
        "je .Lf14b2c_00014cd0\n"
        ".Lf14b2c_00014cb6:\n"
        "andl $4, %edi\n" /* Flags */
        "je .Lf14b2c_00014cd0\n"
        "movl 0x574(%ebx), %eax\n" /* line 2487 | this */
        "cmpl $0xff, %eax\n"
        "je .Lf14b2c_00014cd0\n"
        "movl %eax, (%esp)\n" /* line 2489 */
        "calll glStencilMask\n"
        /* } scope */
        ".Lf14b2c_00014cd0:\n"
        "xorl %eax, %eax\n" /* line 2502 */
        "addl $0x4c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf14b2c_00014cda:\n"
        "cmpl $0xf, 0x590(%ebx)\n" /* line 2371 | this */
        "je .Lf14b2c_00014d07\n"
        "movl $1, 0xc(%esp)\n" /* line 2373 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        ".Lf14b2c_00014d07:\n"
        "movl 0x57c(%ebx), %eax\n" /* line 2378 | this */
        "testl %eax, %eax\n"
        "jne .Lf14b2c_00014de5\n"
        "movl %esi, %edx\n" /* line 2382 | Mask */
        "shrl $0x18, %edx\n"
        "js .Lf14b2c_00014dfc\n"
        ".Lf14b2c_00014d20:\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "movss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, %eax\n" /* Mask */
        "andl $0xff, %eax\n"
        "js .Lf14b2c_00014e2d\n"
        ".Lf14b2c_00014d43:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %esi, %edx\n" /* Mask */
        "shrl $8, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lf14b2c_00014e5a\n"
        ".Lf14b2c_00014d63:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, %edx\n" /* Mask */
        "shrl $0x10, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lf14b2c_00014e85\n"
        ".Lf14b2c_00014d83:\n"
        "cvtsi2ssl %eax, %xmm0\n"
        ".Lf14b2c_00014d87:\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll glClearColor\n"
        "movl $0x4000, %esi\n" /* Mask */
        "jmp .Lf14b2c_00014b4d\n"
        ".Lf14b2c_00014d9f:\n"
        "orl $0x400, %esi\n" /* line 2410 | Mask */
        "cmpl $0xff, 0x574(%ebx)\n" /* line 2412 | this */
        "je .Lf14b2c_00014dbd\n"
        "movl $0xff, (%esp)\n" /* line 2414 */
        "calll glStencilMask\n"
        ".Lf14b2c_00014dbd:\n"
        "movl 0x20(%ebp), %eax\n" /* line 2416 | Stencil */
        "movl %eax, (%esp)\n"
        "calll glClearStencil\n"
        "jmp .Lf14b2c_00014bb9\n"
        /* { scope 2 */
        ".Lf14b2c_00014dcd:\n"
        "jmpl *0x2edf48(, %eax, 4)\n" /* line 2466 */
        /* } scope */
        ".Lf14b2c_00014dd4:\n"
        "movl $0xbd0, (%esp)\n" /* line 2447 */
        "calll glEnable\n"
        "jmp .Lf14b2c_00014c69\n"
        ".Lf14b2c_00014de5:\n"
        "movl $0xbd0, (%esp)\n" /* line 2380 */
        "calll glDisable\n"
        "movl %esi, %edx\n" /* line 2382 | Mask */
        "shrl $0x18, %edx\n"
        "jns .Lf14b2c_00014d20\n"
        ".Lf14b2c_00014dfc:\n"
        "movl %esi, %eax\n" /* Mask */
        "shrl $0x19, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss lit4_002ed5d4, %xmm1\n" /* 255.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xc(%esp)\n"
        "movl %esi, %eax\n" /* Mask */
        "andl $0xff, %eax\n"
        "jns .Lf14b2c_00014d43\n"
        ".Lf14b2c_00014e2d:\n"
        "shrl $1, %eax\n"
        "movl %esi, %edx\n" /* Mask */
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 8(%esp)\n"
        "movl %esi, %edx\n" /* Mask */
        "shrl $8, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "jns .Lf14b2c_00014d63\n"
        ".Lf14b2c_00014e5a:\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl %esi, %edx\n" /* Mask */
        "shrl $0x10, %edx\n"
        "movl %edx, %eax\n"
        "andl $0xff, %eax\n"
        "jns .Lf14b2c_00014d83\n"
        ".Lf14b2c_00014e85:\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf14b2c_00014d87\n"
        ".Lf14b2c_00014e99:\n"
        "movl $0, (%esp)\n" /* line 2456 */
        "calll glDepthMask\n"
        "movl 0x53c(%ebx), %edx\n" /* line 2458 | this */
        "testl %edx, %edx\n"
        "jne .Lf14b2c_00014c94\n"
        ".Lf14b2c_00014eb3:\n"
        "movl $0xb71, (%esp)\n" /* line 2460 */
        "calll glDisable\n"
        "jmp .Lf14b2c_00014c94\n"
        ".Lf14b2c_00014ec4:\n"
        "movl $1, (%esp)\n" /* line 2393 */
        "calll glDepthMask\n"
        "movl 0x53c(%ebx), %eax\n" /* line 2395 | this */
        "testl %eax, %eax\n"
        "jne .Lf14b2c_00014b78\n"
        ".Lf14b2c_00014ede:\n"
        "movl $0xb71, (%esp)\n" /* line 2397 */
        "calll glEnable\n"
        "jmp .Lf14b2c_00014b78\n"
        /* { scope 2 */
        "movl $0x200, %eax\n" /* line 2466 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x201, %eax\n" /* line 2468 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x202, %eax\n" /* line 2469 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x203, %eax\n" /* line 2470 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x204, %eax\n" /* line 2471 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x205, %eax\n" /* line 2472 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x206, %eax\n" /* line 2473 */
        "jmp .Lf14b2c_00014ca7\n"
        "movl $0x207, %eax\n" /* line 2466 */
        "jmp .Lf14b2c_00014ca7\n"
    );
}

/* line 2567 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetMaterial(const CDirect3DDevice * _this, const D3DMATERIAL9 *pMaterial)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2567 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 2569 */
        "cmpb $0, 0x800(%eax)\n"
        "je .Lf14f42_00014f82\n"
        "movl 8(%ebp), %eax\n" /* line 2571 | this */
        "addl $0x5ac, %eax\n"
        "movl $0x44, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* pMaterial */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        ".Lf14f42_00014f78:\n"
        "xorl %eax, %eax\n" /* line 2593 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf14f42_00014f82:\n"
        "movl 8(%ebp), %ebx\n" /* line 2578 | this */
        "addl $0x5ac, %ebx\n"
        "movl $0x44, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n"
        "movl 0xc(%ebp), %edi\n" /* pMaterial */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf14f42_00014fa9\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf14f42_00014fa9:\n"
        "testl %eax, %eax\n"
        "je .Lf14f42_00014f78\n"
        "movl $0x44, 8(%esp)\n" /* line 2580 */
        "movl 0xc(%ebp), %eax\n" /* pMaterial */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        "movl %ebx, 8(%esp)\n" /* line 2582 */
        "movl $0x1201, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl 8(%ebp), %eax\n" /* line 2583 | this */
        "addl $0x5bc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1200, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl 8(%ebp), %eax\n" /* line 2584 | this */
        "addl $0x5cc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1202, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl 8(%ebp), %eax\n" /* line 2585 | this */
        "addl $0x5dc, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1600, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialfv\n"
        "movl 8(%ebp), %edx\n" /* line 2586 | this */
        "movl 0x5ec(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x1601, 4(%esp)\n"
        "movl $0x408, (%esp)\n"
        "calll glMaterialf\n"
        "xorl %eax, %eax\n" /* line 2593 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2689 */
__attribute__((naked))
HRESULT CDirect3DDevice_LightEnable(const CDirect3DDevice * _this, DWORD Index, BOOL Enable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2689 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* Index */
        "movl 0x10(%ebp), %edx\n" /* line 2695 | Enable */
        "testl %edx, %edx\n"
        "setne %cl\n"
        "leal (%ebx, %ebx, 2), %edx\n" /* line 2697 | Index */
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "subl %edx, %eax\n"
        "shll $2, %eax\n"
        "addl 8(%ebp), %eax\n" /* this */
        "addl $0x610, %eax\n"
        "cmpb 4(%eax), %cl\n"
        "je .Lf15068_000150b7\n"
        "movb %cl, 4(%eax)\n" /* line 2699 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 2704 */
        "cmpb $0, 0x800(%eax)\n"
        "jne .Lf15068_000150b7\n"
        /* { scope 1 */
        "leal 0x4000(%ebx), %eax\n" /* line 2706 | Index, LightID */
        "testb %cl, %cl\n" /* line 2708 */
        "jne .Lf15068_000150bf\n"
        "movl %eax, (%esp)\n"
        "calll glDisable\n"
        /* } scope */
        ".Lf15068_000150b7:\n"
        "xorl %eax, %eax\n" /* line 2714 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15068_000150bf:\n"
        "movl %eax, (%esp)\n" /* line 2708 */
        "calll glEnable\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 2714 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 5382 */
__attribute__((naked))
long unsigned int CDirect3DDevice_CopyColorToRenderTargetTexture(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5382 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xbc, %esp\n"
        /* { scope 1: FirstTextureMatrix */
        "leal -0x1c(%ebp), %eax\n" /* line 5387 | CurrentActiveTexture */
        "movl %eax, 4(%esp)\n"
        "movl $0x84e0, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x84c0, (%esp)\n" /* line 5388 */
        "calll glActiveTextureARB\n"
        "leal -0x20(%ebp), %eax\n" /* line 5390 | CurrentID */
        "movl %eax, 4(%esp)\n"
        "movl $0x8069, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl 8(%ebp), %edx\n" /* line 5394 | this */
        "movl 0x14(%edx), %eax\n"
        "movl 0x28(%eax), %eax\n"
        "movl %eax, -0xa0(%ebp)\n" /* pSurface */
        "movl 4(%eax), %eax\n" /* line 5403 */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl -0xa0(%ebp), %eax\n" /* line 120 | pSurface */
        "movl 0x28(%eax), %ecx\n"
        /* { scope 2: Passes */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf150d0_000158ef\n"
        "movl $1, %ebx\n"
        /* } scope */
        ".Lf150d0_00015149:\n"
        "movl 8(%ebp), %eax\n" /* line 5408 | this */
        "movl 0x1c(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "leal -0x40(%ebp), %eax\n" /* Desc */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 5410 */
        "movl %eax, 4(%esp)\n"
        "movl $0xcf2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl %ebx, 4(%esp)\n" /* line 5411 */
        "movl $0xd02, (%esp)\n"
        "calll glPixelStorei\n"
        "movl -0xa0(%ebp), %edx\n" /* line 5422 | pSurface */
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glCopyTexSubImage2D\n"
        "cmpb $0, g_RenderToShadowCookie\n" /* line 5425 */
        "je .Lf150d0_0001589e\n"
        /* { scope 2: Passes */
        "movl 8(%ebp), %eax\n" /* line 5427 | this */
        "movl 0xbb4(%eax), %edi\n"
        "testl %edi, %edi\n"
        "je .Lf150d0_0001590b\n"
        "movl $0x8620, (%esp)\n" /* line 5429 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* this */
        ".Lf150d0_000151f6:\n"
        "movl 0xbb8(%edx), %esi\n" /* line 5432 */
        "testl %esi, %esi\n"
        "je .Lf150d0_0001520c\n"
        "movl $0x8804, (%esp)\n" /* line 5436 */
        "calll glDisable\n"
        ".Lf150d0_0001520c:\n"
        "movl $0x1700, (%esp)\n" /* line 5439 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 5440 */
        "calll glLoadIdentity\n" /* line 5441 */
        "movl $0x1701, (%esp)\n" /* line 5442 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 5443 */
        "calll glLoadIdentity\n" /* line 5444 */
        "pxor %xmm1, %xmm1\n" /* line 5445 */
        "movsd %xmm1, 0x18(%esp)\n"
        "movsd lit8_00307c10, %xmm0\n" /* 1.0 */
        "movsd %xmm0, 0x10(%esp)\n"
        "movsd %xmm0, 8(%esp)\n"
        "movsd %xmm1, (%esp)\n"
        "calll gluOrtho2D\n"
        "movl 8(%ebp), %eax\n" /* line 5447 | this */
        "movl 0x584(%eax), %ebx\n"
        "testl %ebx, %ebx\n"
        "jne .Lf150d0_00015df3\n"
        "movl %eax, %edx\n"
        "movl 0x548(%edx), %ecx\n" /* line 5451 */
        "testl %ecx, %ecx\n"
        "je .Lf150d0_00015e10\n"
        ".Lf150d0_00015281:\n"
        "movl %edx, %eax\n"
        "movl 0x50c(%eax), %edx\n" /* line 5455 */
        "testl %edx, %edx\n"
        "jne .Lf150d0_00015e2d\n"
        ".Lf150d0_00015291:\n"
        "movl %eax, %edx\n"
        "movl 0x53c(%edx), %eax\n" /* line 5459 */
        "testl %eax, %eax\n"
        "jne .Lf150d0_00015e4a\n"
        ".Lf150d0_000152a1:\n"
        "movl %edx, %eax\n"
        "movl 0x57c(%eax), %edi\n" /* line 5463 */
        "testl %edi, %edi\n"
        "jne .Lf150d0_00015e67\n"
        ".Lf150d0_000152b1:\n"
        "movl %eax, %edx\n"
        ".Lf150d0_000152b3:\n"
        "movl 0x574(%edx), %esi\n" /* line 5467 */
        "testl %esi, %esi\n"
        "jne .Lf150d0_00015b1c\n"
        "movl %edx, %eax\n"
        ".Lf150d0_000152c3:\n"
        "cmpl $0xf, 0x590(%eax)\n" /* line 5472 */
        "je .Lf150d0_00015af8\n"
        "movl $1, 0xc(%esp)\n" /* line 5474 */
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glColorMask\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x544(%edx), %ebx\n" /* line 5477 */
        "testl %ebx, %ebx\n"
        "jne .Lf150d0_00015b08\n"
        ".Lf150d0_00015305:\n"
        "movl %edx, %eax\n"
        ".Lf150d0_00015307:\n"
        "cmpl $1, 0x538(%eax)\n" /* line 5482 */
        "je .Lf150d0_00015ab7\n"
        "movl $0xb44, (%esp)\n" /* line 5484 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x580(%edx), %ecx\n" /* line 5487 */
        "testl %ecx, %ecx\n"
        "jne .Lf150d0_00015ac7\n"
        ".Lf150d0_00015331:\n"
        "movl %edx, %eax\n"
        "movl 0x554(%eax), %edx\n" /* line 5492 */
        "testl %edx, %edx\n"
        "jne .Lf150d0_00015ae4\n"
        ".Lf150d0_00015341:\n"
        "movl %eax, %edx\n"
        ".Lf150d0_00015343:\n"
        "movl 0x504(%edx), %eax\n" /* line 5500 */
        "subl $1, %eax\n"
        "js .Lf150d0_000154fe\n"
        "movl %eax, %ebx\n" /* i */
        "movl $0xffffffff, %esi\n"
        "jmp .Lf150d0_000154bd\n"
        ".Lf150d0_0001535e:\n"
        "movl $0xc60, (%esp)\n" /* line 5506 */
        "calll glDisable\n"
        "movl $0xc61, (%esp)\n" /* line 5507 */
        "calll glDisable\n"
        "movl $0xc62, (%esp)\n" /* line 5508 */
        "calll glDisable\n"
        "movl $0xc63, (%esp)\n" /* line 5509 */
        "calll glDisable\n"
        "movl $0x1702, (%esp)\n" /* line 5511 */
        "calll glMatrixMode\n"
        "leal -0x80(%ebp), %eax\n" /* line 5512 | FirstTextureMatrix */
        "movl %eax, 4(%esp)\n"
        "movl $0xba8, (%esp)\n"
        "calll glGetFloatv\n"
        "calll glLoadIdentity\n" /* line 5513 */
        "movl $0xde1, (%esp)\n" /* line 5515 */
        "calll glEnable\n"
        "movl $0x806f, (%esp)\n" /* line 5517 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 5518 */
        "calll glDisable\n"
        "movl $0x2100, 8(%esp)\n" /* line 5519 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x2100, 8(%esp)\n" /* line 5520 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 5521 */
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 8(%esp)\n" /* line 5522 */
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 5523 */
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 8(%esp)\n" /* line 5524 */
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 5525 */
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 5526 */
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "subl $1, %ebx\n" /* line 5500 | i */
        "cmpl %ebx, %esi\n" /* i */
        "je .Lf150d0_000154fe\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 5502 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "testl %ebx, %ebx\n" /* line 5504 | i */
        "je .Lf150d0_0001535e\n"
        "movl $0xde1, (%esp)\n" /* line 5530 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 5532 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 5533 */
        "calll glDisable\n"
        "subl $1, %ebx\n" /* line 5500 | i */
        "cmpl %ebx, %esi\n" /* i */
        "jne .Lf150d0_000154bd\n"
        /* { scope 3: Dx, Dy */
        "movl g_NumBlurShadowPasses, %eax\n" /* line 5538 */
        "addl %eax, %eax\n"
        ".Lf150d0_000154bd:\n"
        "testl %eax, %eax\n"
        "jne .Lf150d0_00015b30\n"
        /* } scope */
        ".Lf150d0_0001550d:\n"
        "leal -0x80(%ebp), %eax\n" /* line 5600 | FirstTextureMatrix */
        "movl %eax, (%esp)\n"
        "calll glLoadMatrixf\n"
        "movl $0x1701, (%esp)\n" /* line 5602 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 5603 */
        "movl $0x1700, (%esp)\n" /* line 5604 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 5605 */
        "movl 8(%ebp), %edx\n" /* line 5609 | this */
        "movl 0x54c(%edx), %eax\n"
        "testl %eax, %eax\n"
        ".Lf150d0_000154fe:\n"
        "je .Lf150d0_00015956\n"
        "movl 0x3a0(%edx), %eax\n" /* line 5611 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x398(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x39c(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x394(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll glBlendFuncSeparateEXT\n"
        "movl 8(%ebp), %eax\n" /* line 5618 | this */
        "movl 0x584(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lf150d0_0001597f\n"
        ".Lf150d0_00015588:\n"
        "movl %eax, %edx\n"
        "movl 0x548(%edx), %esi\n" /* line 5622 */
        "testl %esi, %esi\n"
        "je .Lf150d0_0001599c\n"
        ".Lf150d0_00015598:\n"
        "movl %edx, %eax\n"
        "movl 0x50c(%eax), %ebx\n" /* line 5626 | i */
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf150d0_000159b9\n"
        ".Lf150d0_000155a8:\n"
        "movl %eax, %edx\n"
        "movl 0x53c(%edx), %ecx\n" /* line 5630 */
        "testl %ecx, %ecx\n"
        "jne .Lf150d0_000159d6\n"
        ".Lf150d0_000155b8:\n"
        "movl %edx, %eax\n"
        "movl 0x57c(%eax), %edx\n" /* line 5634 */
        "testl %edx, %edx\n"
        "jne .Lf150d0_000159f3\n"
        ".Lf150d0_000155c8:\n"
        "movl %eax, %edx\n"
        "movl 0x574(%edx), %eax\n" /* line 5638 */
        "testl %eax, %eax\n"
        "jne .Lf150d0_00015a10\n"
        ".Lf150d0_000155d8:\n"
        "movl %edx, %eax\n"
        "movl 0x590(%eax), %edx\n" /* line 5643 */
        "cmpl $0xf, %edx\n"
        "je .Lf150d0_00015a2a\n"
        ".Lf150d0_000155e9:\n"
        "movl %edx, %eax\n" /* line 5650 */
        "shrl $3, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $2, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "andl $1, %edx\n"
        "movl %edx, (%esp)\n"
        "calll glColorMask\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x544(%edx), %eax\n" /* line 5653 */
        "testl %eax, %eax\n"
        "jne .Lf150d0_00015a3a\n"
        ".Lf150d0_00015628:\n"
        "movl %edx, %eax\n"
        "cmpl $1, 0x538(%eax)\n" /* line 5658 */
        "je .Lf150d0_00015a56\n"
        ".Lf150d0_00015637:\n"
        "movl $0xb44, (%esp)\n" /* line 5660 */
        "calll glEnable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x580(%edx), %edi\n" /* line 5663 */
        "testl %edi, %edi\n"
        "jne .Lf150d0_00015a66\n"
        ".Lf150d0_00015654:\n"
        "movl %edx, %eax\n"
        "movl 0x554(%eax), %esi\n" /* line 5668 */
        "testl %esi, %esi\n"
        "jne .Lf150d0_00015a83\n"
        ".Lf150d0_00015664:\n"
        "movl %eax, %edx\n"
        "movl 0xbb4(%edx), %ebx\n" /* line 5673 | i */
        "testl %ebx, %ebx\n" /* i */
        "je .Lf150d0_00015aa0\n"
        ".Lf150d0_00015674:\n"
        "movl $0x8620, (%esp)\n" /* line 5675 */
        "calll glEnable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xbb8(%eax), %ecx\n" /* line 5678 */
        "testl %ecx, %ecx\n"
        "je .Lf150d0_00015ab0\n"
        ".Lf150d0_00015691:\n"
        "movl $0x8804, (%esp)\n" /* line 5680 */
        "calll glEnable\n"
        "movl 8(%ebp), %edx\n" /* this */
        ".Lf150d0_000156a0:\n"
        "movl 0x504(%edx), %esi\n" /* line 5684 */
        "subl $1, %esi\n"
        "js .Lf150d0_0001589e\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 5382 */
        "leal (%esi, %eax, 2), %edi\n"
        "shll $4, %edi\n"
        "jmp .Lf150d0_000156e4\n"
        ".Lf150d0_000156ba:\n"
        "cmpb $0, 2(%ebx)\n" /* line 5727 | i */
        "jne .Lf150d0_00015866\n"
        ".Lf150d0_000156c4:\n"
        "cmpb $0, 3(%ebx)\n" /* line 5731 | i */
        "jne .Lf150d0_0001587c\n"
        ".Lf150d0_000156ce:\n"
        "subl $1, %esi\n" /* line 5684 */
        "subl $0x130, %edi\n"
        "movl $0xffffffff, %edx\n"
        "cmpl %esi, %edx\n"
        "je .Lf150d0_0001589e\n"
        ".Lf150d0_000156e4:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 654 */
        "movl 0x65c(%eax), %ebx\n"
        "addl %edi, %ebx\n"
        "leal 0x84c0(%esi), %eax\n" /* line 5688 */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "testl %esi, %esi\n" /* line 5690 */
        "jne .Lf150d0_00015846\n"
        "cmpb $0, 0x11c(%ebx)\n" /* line 5692 | i */
        "jne .Lf150d0_00015945\n"
        ".Lf150d0_00015714:\n"
        "cmpb $0, 0x11c(%ebx)\n" /* line 5696 | i */
        "jne .Lf150d0_00015934\n"
        ".Lf150d0_00015721:\n"
        "cmpb $0, 0x11c(%ebx)\n" /* line 5700 | i */
        "jne .Lf150d0_00015923\n"
        ".Lf150d0_0001572e:\n"
        "cmpb $0, 0x11c(%ebx)\n" /* line 5704 | i */
        "jne .Lf150d0_00015912\n"
        ".Lf150d0_0001573b:\n"
        "movl $0x1702, (%esp)\n" /* line 5709 */
        "calll glMatrixMode\n"
        "leal -0x80(%ebp), %eax\n" /* line 5710 | FirstTextureMatrix */
        "movl %eax, 4(%esp)\n"
        "movl $0xba8, (%esp)\n"
        "calll glGetFloatv\n"
        "calll glLoadIdentity\n" /* line 5711 */
        "movl 0x70(%ebx), %eax\n" /* line 5713 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x8c(%ebx), %eax\n" /* line 5714 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x74(%ebx), %eax\n" /* line 5715 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x78(%ebx), %eax\n" /* line 5716 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x90(%ebx), %eax\n" /* line 5717 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x94(%ebx), %eax\n" /* line 5718 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0xa8(%ebx), %eax\n" /* line 5719 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl 0xac(%ebx), %eax\n" /* line 5720 | i */
        "movl %eax, 8(%esp)\n"
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "cmpb $0, 1(%ebx)\n" /* line 5722 | i */
        "je .Lf150d0_000156ba\n"
        "movl $0xde1, (%esp)\n" /* line 5724 */
        "calll glEnable\n"
        "cmpb $0, 2(%ebx)\n" /* line 5727 | i */
        "je .Lf150d0_000156c4\n"
        "movl $0x806f, (%esp)\n" /* line 5729 */
        "calll glEnable\n"
        ".Lf150d0_00015846:\n"
        "cmpb $0, 3(%ebx)\n" /* line 5731 | i */
        "je .Lf150d0_000156ce\n"
        "movl $0x8513, (%esp)\n" /* line 5733 */
        "calll glEnable\n"
        "subl $1, %esi\n" /* line 5684 */
        "subl $0x130, %edi\n"
        ".Lf150d0_00015866:\n"
        "movl $0xffffffff, %edx\n"
        "cmpl %esi, %edx\n"
        "jne .Lf150d0_000156e4\n"
        /* } scope */
        "movl $0, 4(%esp)\n" /* line 5739 */
        ".Lf150d0_0001587c:\n"
        "movl $0xcf2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $0, 4(%esp)\n" /* line 5740 */
        "movl $0xd02, (%esp)\n"
        "calll glPixelStorei\n"
        "movl -0x20(%ebp), %eax\n" /* line 5743 | CurrentID */
        "movl %eax, 4(%esp)\n"
        ".Lf150d0_0001589e:\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl -0x1c(%ebp), %eax\n" /* line 5744 | CurrentActiveTexture */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        /* } scope */
        "addl $0xbc, %esp\n" /* line 5748 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: FirstTextureMatrix */
        /* { scope 2: Passes */
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ecx\n"
        "jbe .Lf150d0_00015904\n"
        "subl $1, %eax\n"
        "jne .Lf150d0_000158f9\n"
        "movl %edx, %ebx\n"
        "jmp .Lf150d0_00015149\n"
        "movl %eax, %edx\n"
        ".Lf150d0_000158ef:\n"
        "jmp .Lf150d0_000151f6\n"
        /* } scope */
        /* { scope 2: Passes */
        "movl $0xc63, (%esp)\n" /* line 5706 */
        ".Lf150d0_000158f9:\n"
        "calll glEnable\n"
        "jmp .Lf150d0_0001573b\n"
        "movl $0xc62, (%esp)\n" /* line 5702 */
        "calll glEnable\n"
        "jmp .Lf150d0_0001572e\n"
        ".Lf150d0_00015904:\n"
        "movl $0xc61, (%esp)\n" /* line 5698 */
        "calll glEnable\n"
        ".Lf150d0_0001590b:\n"
        "jmp .Lf150d0_00015721\n"
        "movl $0xc60, (%esp)\n" /* line 5694 */
        ".Lf150d0_00015912:\n"
        "calll glEnable\n"
        "jmp .Lf150d0_00015714\n"
        "movl 0x39c(%edx), %eax\n" /* line 5615 */
        ".Lf150d0_00015923:\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x394(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        ".Lf150d0_00015934:\n"
        "calll glBlendFunc\n"
        "movl 8(%ebp), %eax\n" /* line 5618 | this */
        "movl 0x584(%eax), %edi\n"
        ".Lf150d0_00015945:\n"
        "testl %edi, %edi\n"
        "je .Lf150d0_00015588\n"
        "movl $0xb50, (%esp)\n" /* line 5620 */
        ".Lf150d0_00015956:\n"
        "calll glEnable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x548(%edx), %esi\n" /* line 5622 */
        "testl %esi, %esi\n"
        "jne .Lf150d0_00015598\n"
        "movl $0xbe2, (%esp)\n" /* line 5624 */
        "calll glDisable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x50c(%eax), %ebx\n" /* line 5626 | i */
        ".Lf150d0_0001597f:\n"
        "testl %ebx, %ebx\n" /* i */
        "je .Lf150d0_000155a8\n"
        "movl $0xbc0, (%esp)\n" /* line 5628 */
        "calll glEnable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x53c(%edx), %ecx\n" /* line 5630 */
        ".Lf150d0_0001599c:\n"
        "testl %ecx, %ecx\n"
        "je .Lf150d0_000155b8\n"
        "movl $0xb71, (%esp)\n" /* line 5632 */
        "calll glEnable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x57c(%eax), %edx\n" /* line 5634 */
        ".Lf150d0_000159b9:\n"
        "testl %edx, %edx\n"
        "je .Lf150d0_000155c8\n"
        "movl $0xbd0, (%esp)\n" /* line 5636 */
        "calll glEnable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x574(%edx), %eax\n" /* line 5638 */
        ".Lf150d0_000159d6:\n"
        "testl %eax, %eax\n"
        "je .Lf150d0_000155d8\n"
        "movl %eax, (%esp)\n" /* line 5640 */
        "calll glStencilMask\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x590(%eax), %edx\n" /* line 5643 */
        ".Lf150d0_000159f3:\n"
        "cmpl $0xf, %edx\n"
        "jne .Lf150d0_000155e9\n"
        "movl %eax, %edx\n"
        "movl 0x544(%edx), %eax\n" /* line 5653 */
        "testl %eax, %eax\n"
        "je .Lf150d0_00015628\n"
        ".Lf150d0_00015a10:\n"
        "movl $1, (%esp)\n" /* line 5655 */
        "calll glDepthMask\n"
        "movl 8(%ebp), %eax\n" /* this */
        "cmpl $1, 0x538(%eax)\n" /* line 5658 */
        "jne .Lf150d0_00015637\n"
        "movl %eax, %edx\n"
        ".Lf150d0_00015a2a:\n"
        "movl 0x580(%edx), %edi\n" /* line 5663 */
        "testl %edi, %edi\n"
        "je .Lf150d0_00015654\n"
        "movl $0xb60, (%esp)\n" /* line 5665 */
        ".Lf150d0_00015a3a:\n"
        "calll glEnable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x554(%eax), %esi\n" /* line 5668 */
        "testl %esi, %esi\n"
        "je .Lf150d0_00015664\n"
        ".Lf150d0_00015a56:\n"
        "movl $0xb90, (%esp)\n" /* line 5670 */
        "calll glEnable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xbb4(%edx), %ebx\n" /* line 5673 | i */
        ".Lf150d0_00015a66:\n"
        "testl %ebx, %ebx\n" /* i */
        "jne .Lf150d0_00015674\n"
        "movl %edx, %eax\n"
        "movl 0xbb8(%eax), %ecx\n" /* line 5678 */
        "testl %ecx, %ecx\n"
        "jne .Lf150d0_00015691\n"
        ".Lf150d0_00015a83:\n"
        "movl %eax, %edx\n"
        "jmp .Lf150d0_000156a0\n"
        "movl %eax, %edx\n"
        "movl 0x580(%edx), %ecx\n" /* line 5487 */
        "testl %ecx, %ecx\n"
        "je .Lf150d0_00015331\n"
        ".Lf150d0_00015aa0:\n"
        "movl $0xb60, (%esp)\n" /* line 5489 */
        "calll glDisable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x554(%eax), %edx\n" /* line 5492 */
        ".Lf150d0_00015ab0:\n"
        "testl %edx, %edx\n"
        "je .Lf150d0_00015341\n"
        ".Lf150d0_00015ab7:\n"
        "movl $0xb90, (%esp)\n" /* line 5494 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf150d0_00015343\n"
        ".Lf150d0_00015ac7:\n"
        "movl %eax, %edx\n"
        "movl 0x544(%edx), %ebx\n" /* line 5477 */
        "testl %ebx, %ebx\n"
        "je .Lf150d0_00015305\n"
        "movl $0, (%esp)\n" /* line 5479 */
        "calll glDepthMask\n"
        ".Lf150d0_00015ae4:\n"
        "movl 8(%ebp), %eax\n" /* this */
        "jmp .Lf150d0_00015307\n"
        "movl $0, (%esp)\n" /* line 5469 */
        "calll glStencilMask\n"
        ".Lf150d0_00015af8:\n"
        "movl 8(%ebp), %eax\n" /* this */
        "jmp .Lf150d0_000152c3\n"
        /* { scope 3: Dx, Dy */
        "movl $0, -0x9c(%ebp)\n" /* line 5538 | Passes */
        /* { scope 4: BaseX, BaseY */
        ".Lf150d0_00015b3a:\n"
        "movl $0, 4(%esp)\n" /* line 5542 */
        ".Lf150d0_00015b08:\n"
        "movl $1, (%esp)\n"
        "calll glBlendFunc\n"
        "movl $7, (%esp)\n" /* line 5546 */
        "calll glBegin\n"
        /* { scope 5 */
        ".Lf150d0_00015b5a:\n"
        ".Lf150d0_00015b1c:\n"
        "pxor %xmm1, %xmm1\n" /* line 5549 */
        "movss %xmm1, -0x94(%ebp)\n" /* Dy */
        "movss %xmm1, -0x98(%ebp)\n" /* Dx */
        "xorl %esi, %esi\n"
        ".Lf150d0_00015b30:\n"
        "movl $GaussianBlurWeights, %edi\n"
        "movaps %xmm1, %xmm2\n"
        ".Lf150d0_00015b78:\n"
        "movss (%edi), %xmm0\n" /* line 5558 | Weight */
        "divss lit4_002ed5e0, %xmm0\n" /* 6.0f, Weight */
        "movss lit4_002ed5e4, %xmm1\n" /* line 5565 | 0.0078125f */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x90(%ebp)\n" /* BaseX */
        "movss -0x94(%ebp), %xmm2\n" /* line 5566 | Dy */
        "mulss %xmm1, %xmm2\n"
        "movss %xmm2, -0x8c(%ebp)\n" /* BaseY */
        "movss %xmm0, 0xc(%esp)\n" /* line 5571 */
        "movss %xmm0, 8(%esp)\n"
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll glColor4f\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 5573 */
        "xorl %ebx, %ebx\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %ebx, 8(%esp)\n" /* line 5574 | i */
        "movss -0x8c(%ebp), %xmm0\n" /* BaseY */
        "movss %xmm0, 4(%esp)\n"
        "movss -0x90(%ebp), %xmm1\n" /* BaseX */
        "movss %xmm1, (%esp)\n"
        "calll glVertex3f\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 5576 */
        "movl $0x3f800000, (%esp)\n"
        "calll glTexCoord2f\n"
        "movss lit4_002ed5d0, %xmm2\n" /* line 5577 | 1.0f */
        "addss -0x90(%ebp), %xmm2\n" /* BaseX */
        "movss %xmm2, -0xa8(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* i */
        "movss -0x8c(%ebp), %xmm0\n" /* BaseY */
        "movss %xmm0, 4(%esp)\n"
        "movss %xmm2, (%esp)\n"
        "calll glVertex3f\n"
        "movl %ebx, 4(%esp)\n" /* line 5579 | i */
        "movl $0x3f800000, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl $0x3f800000, -0xa4(%ebp)\n" /* line 5580 */
        "movss -0x8c(%ebp), %xmm1\n" /* BaseY */
        "addss -0xa4(%ebp), %xmm1\n"
        "movss %xmm1, -0xa4(%ebp)\n"
        "movl %ebx, 8(%esp)\n" /* i */
        "movss %xmm1, 4(%esp)\n"
        "movss -0xa8(%ebp), %xmm2\n"
        "movss %xmm2, (%esp)\n"
        "calll glVertex3f\n"
        "movl %ebx, 4(%esp)\n" /* line 5582 | i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %ebx, 8(%esp)\n" /* line 5583 | i */
        "movss -0xa4(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movss -0x90(%ebp), %xmm1\n" /* BaseX */
        "movss %xmm1, (%esp)\n"
        "calll glVertex3f\n"
        /* } scope */
        "addl $1, %esi\n" /* line 5547 */
        "cmpl $5, %esi\n"
        "je .Lf150d0_00015d87\n"
        /* { scope 5 */
        "cmpl $4, %esi\n" /* line 5549 */
        "ja .Lf150d0_00015d19\n"
        "jmpl *.Ljt_2edf80(, %esi, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2edf80:\n"
        ".long .Lf150d0_00015b5a\n"
        ".long .Lf150d0_00015cdc\n"
        ".long .Lf150d0_00015d29\n"
        ".long .Lf150d0_00015d65\n"
        ".long .Lf150d0_00015d4b\n"
        ".popsection\n"
        ".Lf150d0_00015cdc:\n"
        "calll glEnd\n" /* line 5552 */
        "movl $1, 4(%esp)\n"
        "movl $1, (%esp)\n"
        "calll glBlendFunc\n"
        "movl $7, (%esp)\n"
        "calll glBegin\n"
        "movss lit4_002ed5dc, %xmm2\n" /* -1.0f */
        "movss %xmm2, -0x94(%ebp)\n" /* Dy */
        "movss %xmm2, -0x98(%ebp)\n" /* Dx */
        ".Lf150d0_00015d19:\n"
        "addl $4, %edi\n" /* line 5553 */
        "movss -0x98(%ebp), %xmm2\n" /* Dx */
        "jmp .Lf150d0_00015b78\n"
        ".Lf150d0_00015d29:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 5552 | 1.0f */
        "movss %xmm0, -0x98(%ebp)\n" /* Dx */
        "movss lit4_002ed5dc, %xmm1\n" /* -1.0f */
        "movss %xmm1, -0x94(%ebp)\n" /* Dy */
        "jmp .Lf150d0_00015d19\n"
        ".Lf150d0_00015d4b:\n"
        "movss lit4_002ed5d0, %xmm0\n" /* line 5549 | 1.0f */
        "movss %xmm0, -0x94(%ebp)\n" /* Dy */
        "movss %xmm0, -0x98(%ebp)\n" /* Dx */
        "jmp .Lf150d0_00015d19\n"
        ".Lf150d0_00015d65:\n"
        "movss lit4_002ed5dc, %xmm2\n" /* line 5553 | -1.0f */
        "movss %xmm2, -0x98(%ebp)\n" /* Dx */
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "movss %xmm0, -0x94(%ebp)\n" /* Dy */
        "jmp .Lf150d0_00015d19\n"
        /* } scope */
        ".Lf150d0_00015d87:\n"
        "calll glEnd\n" /* line 5585 */
        "movl -0xa0(%ebp), %edx\n" /* line 5596 | pSurface */
        "movl 0x2c(%edx), %eax\n"
        "movl %eax, 0x1c(%esp)\n"
        "movl 0x28(%edx), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glCopyTexSubImage2D\n"
        /* } scope */
        "addl $1, -0x9c(%ebp)\n" /* line 5538 | Passes */
        "movl g_NumBlurShadowPasses, %eax\n"
        "addl %eax, %eax\n"
        "cmpl -0x9c(%ebp), %eax\n" /* Passes */
        "ja .Lf150d0_00015b3a\n"
        "jmp .Lf150d0_0001550d\n"
        /* } scope */
        ".Lf150d0_00015df3:\n"
        "movl $0xb50, (%esp)\n" /* line 5449 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x548(%edx), %ecx\n" /* line 5451 */
        "testl %ecx, %ecx\n"
        "jne .Lf150d0_00015281\n"
        ".Lf150d0_00015e10:\n"
        "movl $0xbe2, (%esp)\n" /* line 5453 */
        "calll glEnable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x50c(%eax), %edx\n" /* line 5455 */
        "testl %edx, %edx\n"
        "je .Lf150d0_00015291\n"
        ".Lf150d0_00015e2d:\n"
        "movl $0xbc0, (%esp)\n" /* line 5457 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0x53c(%edx), %eax\n" /* line 5459 */
        "testl %eax, %eax\n"
        "je .Lf150d0_000152a1\n"
        ".Lf150d0_00015e4a:\n"
        "movl $0xb71, (%esp)\n" /* line 5461 */
        "calll glDisable\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0x57c(%eax), %edi\n" /* line 5463 */
        "testl %edi, %edi\n"
        "je .Lf150d0_000152b1\n"
        ".Lf150d0_00015e67:\n"
        "movl $0xbd0, (%esp)\n" /* line 5465 */
        "calll glDisable\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf150d0_000152b3\n"
    );
}

/* line 5759 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetRenderTarget(const CDirect3DDevice * _this, DWORD RenderTargetIndex, IDirect3DSurface9 *pRenderTarget)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5759 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %ebx\n"
        "subl $0x50, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x10(%ebp), %edi\n" /* pRenderTarget */
        /* { scope 1 */
        "testl %edi, %edi\n" /* line 5761 | pRenderTarget */
        "je .Lf15e7c_00015eb2\n"
        "movl 0x14(%ebx), %edx\n" /* line 5769 | this */
        "cmpl 0x1c(%ebx), %edx\n" /* this */
        "je .Lf15e7c_00015e9f\n"
        "cmpb $0, g_InhibitCopy\n"
        "je .Lf15e7c_00015eff\n"
        ".Lf15e7c_00015e9f:\n"
        "movl (%edx), %eax\n" /* line 5844 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        "movl %edi, 0x14(%ebx)\n" /* line 5845 | pRenderTarget, this */
        "movl (%edi), %eax\n" /* line 5846 | pRenderTarget */
        "movl %edi, (%esp)\n" /* pRenderTarget */
        "calll *4(%eax)\n"
        ".Lf15e7c_00015eb2:\n"
        "movl 0x14(%ebx), %edx\n" /* line 5852 | this */
        "movl (%edx), %ecx\n"
        "leal -0x40(%ebp), %eax\n" /* SourceDesc */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x30(%ecx)\n"
        "leal -0x20(%ebp), %edi\n" /* line 5854 | NewViewport, pRenderTarget */
        "cld\n"
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* pRenderTarget */
        "movl $0x3f800000, -0xc(%ebp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, -0x18(%ebp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, -0x14(%ebp)\n"
        "movl (%ebx), %edx\n" /* line 5855 | this */
        "leal -0x20(%ebp), %eax\n" /* NewViewport */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll *0xbc(%edx)\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 5861 */
        "addl $0x50, %esp\n"
        "popl %ebx\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15e7c_00015eff:\n"
        "movl %ebx, (%esp)\n" /* line 5771 | this */
        "calll CDirect3DDevice_CopyColorToRenderTargetTexture\n"
        "movl 0x14(%ebx), %edx\n" /* this */
        "jmp .Lf15e7c_00015e9f\n"
    );
}

/* line 5236 */
__attribute__((naked))
bool CDirect3DDevice_CTexStage_GetUsesTexture(const CTexStage * _this, bool *UsesTexFactor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 5236 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        /* { scope 1 */
        "movl 0x34(%ecx), %edx\n" /* line 5250 | Source1 */
        "andl $0xf, %edx\n" /* Source1 */
        "movl 0x38(%ecx), %ebx\n" /* line 5251 | Source2 */
        "andl $0xf, %ebx\n" /* Source2 */
        "movl 0x30(%ecx), %esi\n" /* line 5252 | Source0 */
        "andl $0xf, %esi\n" /* Source0 */
        "movl 0xc(%ebp), %eax\n" /* line 5255 | UsesTexFactor */
        "movb $0, (%eax)\n"
        "cmpl $0x1a, 0x2c(%ecx)\n" /* line 5257 */
        "ja .Lf15f0c_00015f43\n"
        "movl 0x2c(%ecx), %eax\n"
        "jmpl *.Ljt_2edf94(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2edf94:\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015f3d\n"
        ".long .Lf15f0c_00015f98\n"
        ".long .Lf15f0c_00016044\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015fdd\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015f43\n"
        ".long .Lf15f0c_00015fb6\n"
        ".long .Lf15f0c_00016009\n"
        ".long .Lf15f0c_00016009\n"
        ".popsection\n"
        ".Lf15f0c_00015f3d:\n"
        "movl 0xc(%ebp), %eax\n" /* line 5295 | UsesTexFactor */
        "movb $0, (%eax)\n"
        ".Lf15f0c_00015f43:\n"
        "movl 0x40(%ecx), %esi\n" /* line 5305 | Source0 */
        "andl $0xf, %esi\n" /* Source0 */
        "movl 0x44(%ecx), %edx\n" /* line 5306 */
        "andl $0xf, %edx\n"
        "movl 0x48(%ecx), %ebx\n" /* line 5307 | Source2 */
        "andl $0xf, %ebx\n" /* Source2 */
        "cmpl $0x18, 0x3c(%ecx)\n" /* line 5309 */
        "jbe .Lf15f0c_00015f84\n"
        ".Lf15f0c_00015f5b:\n"
        "xorl %edi, %edi\n" /* line 5331 | UsesTexture */
        ".Lf15f0c_00015f5d:\n"
        "movl 0xc(%ebp), %edx\n" /* line 5339 | UsesTexFactor */
        "cmpb $0, (%edx)\n"
        "jne .Lf15f0c_00015f7d\n"
        "movl 0x40(%ecx), %esi\n" /* line 5342 | Source0 */
        "andl $0xf, %esi\n" /* Source0 */
        "movl 0x44(%ecx), %edx\n" /* line 5343 */
        "andl $0xf, %edx\n"
        "movl 0x48(%ecx), %ebx\n" /* line 5344 | Source2 */
        "andl $0xf, %ebx\n" /* Source2 */
        "cmpl $0x18, 0x3c(%ecx)\n" /* line 5346 */
        "jbe .Lf15f0c_00015f8e\n"
        /* } scope */
        ".Lf15f0c_00015f7d:\n"
        "movl %edi, %eax\n" /* line 5377 | UsesTexture */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15f0c_00015f84:\n"
        "movl 0x3c(%ecx), %eax\n" /* line 5309 */
        "jmpl *.Ljt_2ee000(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee000:\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_0001605a\n"
        ".long .Lf15f0c_00016067\n"
        ".long .Lf15f0c_0001609a\n"
        ".long .Lf15f0c_000160a8\n"
        ".long .Lf15f0c_000160a8\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_000160a8\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_000160a8\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00015f5b\n"
        ".long .Lf15f0c_00016075\n"
        ".popsection\n"
        ".Lf15f0c_00015f8e:\n"
        "movl 0x3c(%ecx), %eax\n" /* line 5346 */
        "jmpl *.Ljt_2ee064(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee064:\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_000160c4\n"
        ".long .Lf15f0c_000160cf\n"
        ".long .Lf15f0c_000160dd\n"
        ".long .Lf15f0c_000160eb\n"
        ".long .Lf15f0c_000160eb\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_000160eb\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_000160eb\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00015f7d\n"
        ".long .Lf15f0c_00016103\n"
        ".popsection\n"
        ".Lf15f0c_00015f98:\n"
        "cmpl $2, %edx\n" /* line 5274 */
        "sete %al\n"
        "movl %eax, %edi\n" /* UsesTexture */
        "cmpl $3, %edx\n" /* line 5275 */
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "sete (%edx)\n"
        ".Lf15f0c_00015fa9:\n"
        "movl %edi, %edx\n" /* line 5302 | UsesTexture */
        "testb %dl, %dl\n"
        "je .Lf15f0c_00015f43\n"
        ".Lf15f0c_00015faf:\n"
        "movl $1, %edi\n" /* line 5331 | UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_00015fb6:\n"
        "cmpl $2, %edx\n" /* line 5269 */
        "je .Lf15f0c_00016132\n"
        "cmpl $2, %ebx\n" /* Source2 */
        "je .Lf15f0c_00016132\n"
        "xorl %edi, %edi\n" /* UsesTexture */
        ".Lf15f0c_00015fca:\n"
        "cmpl $3, %edx\n" /* line 5270 */
        "je .Lf15f0c_00016035\n"
        "cmpl $3, %ebx\n" /* Source2 */
        "je .Lf15f0c_00016035\n"
        ".Lf15f0c_00015fd4:\n"
        "xorl %eax, %eax\n" /* line 5291 */
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "movb %al, (%edx)\n"
        "jmp .Lf15f0c_00015fa9\n"
        ".Lf15f0c_00015fdd:\n"
        "cmpl $3, %edx\n" /* line 5285 */
        "je .Lf15f0c_00016128\n"
        "cmpl $3, %ebx\n" /* Source2 */
        "je .Lf15f0c_00016128\n"
        "cmpl $3, %esi\n" /* Source0 */
        "je .Lf15f0c_00016128\n"
        "xorl %eax, %eax\n"
        ".Lf15f0c_00015ffa:\n"
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "movb %al, (%edx)\n"
        "movl $1, %edi\n" /* UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_00016009:\n"
        "cmpl $2, %edx\n" /* line 5290 */
        "je .Lf15f0c_0001611e\n"
        "cmpl $2, %ebx\n" /* Source2 */
        "je .Lf15f0c_0001611e\n"
        "cmpl $2, %esi\n" /* Source0 */
        "je .Lf15f0c_0001611e\n"
        "xorl %edi, %edi\n" /* UsesTexture */
        ".Lf15f0c_00016026:\n"
        "cmpl $3, %edx\n" /* line 5291 */
        "je .Lf15f0c_00016035\n"
        "cmpl $3, %ebx\n" /* Source2 */
        "je .Lf15f0c_00016035\n"
        "cmpl $3, %esi\n" /* Source0 */
        "jne .Lf15f0c_00015fd4\n"
        ".Lf15f0c_00016035:\n"
        "movl $1, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "movb %al, (%edx)\n"
        "jmp .Lf15f0c_00015fa9\n"
        ".Lf15f0c_00016044:\n"
        "cmpl $2, %ebx\n" /* line 5279 | Source2 */
        "sete %al\n"
        "movl %eax, %edi\n" /* UsesTexture */
        "cmpl $3, %ebx\n" /* line 5280 | Source2 */
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "sete (%edx)\n"
        "jmp .Lf15f0c_00015fa9\n"
        ".Lf15f0c_0001605a:\n"
        "movl 0xc(%ebp), %eax\n" /* line 5331 | UsesTexFactor */
        "movb $0, (%eax)\n"
        "xorl %edi, %edi\n" /* UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_00016067:\n"
        "cmpl $2, %edx\n" /* line 5315 */
        "sete %al\n"
        "movzbl %al, %edi\n" /* UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_00016075:\n"
        "cmpl $2, %edx\n" /* line 5327 */
        "je .Lf15f0c_00015faf\n"
        "cmpl $2, %ebx\n" /* Source2 */
        "je .Lf15f0c_00015faf\n"
        "cmpl $2, %esi\n" /* Source0 */
        "jne .Lf15f0c_00015f5b\n"
        "movl $1, %edi\n" /* line 5331 | UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_0001609a:\n"
        "cmpl $2, %ebx\n" /* line 5320 | Source2 */
        "sete %al\n"
        "movzbl %al, %edi\n" /* UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_000160a8:\n"
        "cmpl $2, %edx\n" /* line 5315 */
        "je .Lf15f0c_00015faf\n"
        "cmpl $2, %ebx\n" /* Source2 */
        "jne .Lf15f0c_00015f5b\n"
        "movl $1, %edi\n" /* line 5331 | UsesTexture */
        "jmp .Lf15f0c_00015f5d\n"
        ".Lf15f0c_000160c4:\n"
        "movl 0xc(%ebp), %eax\n" /* line 5368 | UsesTexFactor */
        "movb $0, (%eax)\n"
        "jmp .Lf15f0c_00015f7d\n"
        ".Lf15f0c_000160cf:\n"
        "cmpl $3, %edx\n" /* line 5356 */
        "movl 0xc(%ebp), %eax\n" /* UsesTexFactor */
        "sete (%eax)\n"
        "jmp .Lf15f0c_00015f7d\n"
        ".Lf15f0c_000160dd:\n"
        "cmpl $3, %ebx\n" /* line 5360 | Source2 */
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "sete (%edx)\n"
        "jmp .Lf15f0c_00015f7d\n"
        ".Lf15f0c_000160eb:\n"
        "cmpl $3, %edx\n" /* line 5352 */
        "je .Lf15f0c_00016112\n"
        "cmpl $3, %ebx\n" /* Source2 */
        "je .Lf15f0c_00016112\n"
        ".Lf15f0c_000160f5:\n"
        "xorl %eax, %eax\n" /* line 5364 */
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "movb %al, (%edx)\n"
        /* } scope */
        ".Lf15f0c_000160fc:\n"
        "movl %edi, %eax\n" /* line 5377 | UsesTexture */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf15f0c_00016103:\n"
        "cmpl $2, %edx\n" /* line 5364 */
        "je .Lf15f0c_00016112\n"
        "cmpl $2, %ebx\n" /* Source2 */
        "je .Lf15f0c_00016112\n"
        "cmpl $2, %esi\n" /* Source0 */
        "jne .Lf15f0c_000160f5\n"
        ".Lf15f0c_00016112:\n"
        "movl $1, %eax\n"
        "movl 0xc(%ebp), %edx\n" /* UsesTexFactor */
        "movb %al, (%edx)\n"
        "jmp .Lf15f0c_000160fc\n"
        ".Lf15f0c_0001611e:\n"
        "movl $1, %edi\n" /* line 5290 | UsesTexture */
        "jmp .Lf15f0c_00016026\n"
        ".Lf15f0c_00016128:\n"
        "movl $1, %eax\n" /* line 5285 */
        "jmp .Lf15f0c_00015ffa\n"
        ".Lf15f0c_00016132:\n"
        "movl $1, %edi\n" /* line 5269 | UsesTexture */
        "jmp .Lf15f0c_00015fca\n"
    );
}

/* line 1120 */
__attribute__((naked))
HRESULT CDirect3DDevice_Present(const CDirect3DDevice * _this, const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1120 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl g_showtexid, %edx\n" /* line 1184 */
        "movl imp___ZN7COpenGL14sShowTextureIDE, %eax\n" /* line 674 */
        "movl %edx, (%eax)\n"
        "testl %edx, %edx\n" /* line 1185 */
        "jne .Lf1613c_00016180\n"
        ".Lf1613c_00016153:\n"
        "cmpb $0, g_ShowShadowCookies\n" /* line 1194 */
        "je .Lf1613c_00016161\n"
        "calll ShowShadowCookies\n" /* line 1200 */
        ".Lf1613c_00016161:\n"
        "movl 8(%ebp), %eax\n" /* line 1207 | this */
        "movl 8(%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll MacDisplay_SwapContext\n"
        "calll CMemoryBuffer_Update\n" /* line 1211 */
        "movl imp___ZN7COpenGL11sFrameCountE, %eax\n" /* line 669 */
        "addl $1, (%eax)\n"
        "xorl %eax, %eax\n" /* line 1215 */
        "leave\n"
        "retl\n"
        ".Lf1613c_00016180:\n"
        "movl %edx, (%esp)\n" /* line 1191 */
        "calll ViewSingleTexture\n"
        "jmp .Lf1613c_00016153\n"
    );
}

/* line 2601 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetLight(const CDirect3DDevice * _this, DWORD Index, const D3DLIGHT9 *pLight)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2601 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x5c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %edx\n" /* line 2606 | Index */
        "leal (%edx, %edx, 2), %eax\n"
        "movl %eax, %ebx\n"
        "shll $4, %ebx\n"
        "subl %eax, %ebx\n"
        "leal 0x610(, %ebx, 4), %ebx\n"
        "addl 8(%ebp), %ebx\n" /* this */
        "leal 4(%ebx), %esi\n" /* Temp3 */
        "movl %esi, -0x1c(%ebp)\n" /* Temp3, l */
        "movzbl 4(%ebx), %esi\n" /* line 2608 | SaveEnable */
        "movl $0xb4, 8(%esp)\n" /* line 2610 */
        "movl $0, 4(%esp)\n"
        "movl -0x1c(%ebp), %edi\n" /* l, Temp4 */
        "movl %edi, (%esp)\n" /* Temp4 */
        "calll memset\n"
        "movl %esi, %eax\n" /* line 2612 | SaveEnable */
        "movb %al, 4(%ebx)\n"
        "movl 0x10(%ebp), %edx\n" /* line 2613 | pLight */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%edi)\n" /* Temp4 */
        "movl 0x4c(%edx), %eax\n" /* line 2614 */
        "movl %eax, 8(%edi)\n" /* Temp4 */
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 27 */
        "addl $0x40, %eax\n"
        "movl 4(%eax), %ecx\n" /* line 28 | Temp2 */
        "movl 8(%eax), %esi\n" /* line 29 | Temp3 */
        "leal 0x40(%ebx), %edx\n" /* line 31 */
        "movl 0x10(%ebp), %edi\n" /* pLight */
        "movl 0x40(%edi), %eax\n"
        "movl %eax, 0x40(%ebx)\n"
        "movl %ecx, 4(%edx)\n" /* line 32 */
        "movl %esi, 8(%edx)\n" /* line 33 | Temp3 */
        /* } scope */
        /* { scope 2 */
        "movl %edi, %eax\n" /* line 27 */
        "addl $0x34, %eax\n"
        "movl 4(%eax), %ecx\n" /* line 28 | Temp2 */
        "movl 8(%eax), %esi\n" /* line 29 | Temp3 */
        "leal 0x4c(%ebx), %edx\n" /* line 31 */
        "movl 0x34(%edi), %eax\n"
        "movl %eax, 0x4c(%ebx)\n"
        "movl %ecx, 4(%edx)\n" /* line 32 */
        "movl %esi, 8(%edx)\n" /* line 33 | Temp3 */
        /* } scope */
        /* { scope 2 */
        "movl %edi, %eax\n" /* line 39 */
        "addl $4, %eax\n"
        "movl 4(%eax), %ecx\n" /* line 40 | Temp2 */
        "movl 8(%eax), %esi\n" /* line 41 | Temp3 */
        "movl 0xc(%eax), %edi\n" /* line 42 | Temp4 */
        "leal 0x10(%ebx), %edx\n" /* line 44 */
        "movl 0x10(%ebp), %eax\n" /* pLight */
        "movl 4(%eax), %eax\n"
        "movl %eax, 0x10(%ebx)\n"
        "movl %ecx, 4(%edx)\n" /* line 45 */
        "movl %esi, 8(%edx)\n" /* line 46 | Temp3 */
        "movl %edi, 0xc(%edx)\n" /* line 47 | Temp4 */
        /* } scope */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 39 | pLight */
        "addl $0x14, %eax\n"
        "movl 4(%eax), %ecx\n" /* line 40 | Temp2 */
        "movl 8(%eax), %esi\n" /* line 41 | Temp3 */
        "movl 0xc(%eax), %edi\n" /* line 42 | Temp4 */
        "leal 0x20(%ebx), %edx\n" /* line 44 */
        "movl 0x10(%ebp), %eax\n" /* pLight */
        "movl 0x14(%eax), %eax\n"
        "movl %eax, 0x20(%ebx)\n"
        "movl %ecx, 4(%edx)\n" /* line 45 */
        "movl %esi, 8(%edx)\n" /* line 46 | Temp3 */
        "movl %edi, 0xc(%edx)\n" /* line 47 | Temp4 */
        /* } scope */
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 39 | pLight */
        "addl $0x24, %eax\n"
        "movl 4(%eax), %ecx\n" /* line 40 | Temp2 */
        "movl 8(%eax), %esi\n" /* line 41 | Temp3 */
        "movl 0xc(%eax), %edi\n" /* line 42 | Temp4 */
        "leal 0x30(%ebx), %edx\n" /* line 44 */
        "movl 0x10(%ebp), %eax\n" /* pLight */
        "movl 0x24(%eax), %eax\n"
        "movl %eax, 0x30(%ebx)\n"
        "movl %ecx, 4(%edx)\n" /* line 45 */
        "movl %esi, 8(%edx)\n" /* line 46 | Temp3 */
        "movl %edi, 0xc(%edx)\n" /* line 47 | Temp4 */
        /* } scope */
        "movl 0x10(%ebp), %edx\n" /* line 2620 | pLight */
        "movss 0x60(%edx), %xmm1\n"
        "movl -0x1c(%ebp), %esi\n" /* l, SaveEnable */
        "movss %xmm1, 0x68(%esi)\n" /* SaveEnable */
        "movl 0x64(%edx), %eax\n" /* line 2621 */
        "movl %eax, 0x6c(%esi)\n" /* SaveEnable */
        "movl 0x50(%edx), %eax\n" /* line 2622 */
        "movl %eax, 0x70(%esi)\n" /* SaveEnable */
        "cmpl $2, (%edx)\n" /* line 2624 */
        "je .Lf1618a_00016305\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 2655 */
        "cmpb $0, 0x800(%ebx)\n"
        "je .Lf1618a_000162f2\n"
        ".Lf1618a_000162b4:\n"
        "movl 0x10(%ebp), %esi\n" /* line 2664 | pLight, SaveEnable */
        "movl 0x58(%esi), %eax\n" /* SaveEnable, b */
        "movl 0x5c(%esi), %ecx\n" /* line 2665 | SaveEnable, c */
        "movl 0x54(%esi), %edx\n" /* line 2669 | SaveEnable */
        "movl -0x1c(%ebp), %edi\n" /* l, Temp4 */
        "movl %edx, 0x74(%edi)\n" /* Temp4 */
        "movl %eax, 0x78(%edi)\n" /* line 2670 | Temp4 */
        "movl %ecx, 0x7c(%edi)\n" /* line 2671 | Temp4 */
        "cmpb $0, 0x800(%ebx)\n" /* line 2673 */
        "jne .Lf1618a_000162e8\n"
        "movl %edi, 8(%esp)\n" /* line 2675 | Temp4 */
        "movl 0xc(%ebp), %eax\n" /* Index */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGL_SetLight\n"
        /* } scope */
        ".Lf1618a_000162e8:\n"
        "xorl %eax, %eax\n" /* line 2681 */
        "addl $0x5c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf1618a_000162f2:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 2658 | l */
        "movl $0, 0x60(%edx)\n"
        "movl $0x43340000, 0x64(%edx)\n" /* line 2659 */
        "jmp .Lf1618a_000162b4\n"
        ".Lf1618a_00016305:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %ebx\n" /* line 2626 */
        "cmpb $0, 0x800(%ebx)\n"
        "jne .Lf1618a_000163c6\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %eax\n" /* line 2636 | pLight */
        "movss 0x50(%eax), %xmm2\n"
        "ucomiss lit4_002ed5e8, %xmm2\n" /* 0.0f */
        "je .Lf1618a_00016360\n"
        ".Lf1618a_00016329:\n"
        "movss 0x60(%eax), %xmm0\n" /* line 2642 */
        "movss 0x64(%eax), %xmm1\n"
        "subss %xmm0, %xmm1\n"
        "addss %xmm2, %xmm2\n"
        "divss %xmm2, %xmm1\n"
        "addss %xmm0, %xmm1\n"
        "ucomiss lit4_002ed5f0, %xmm1\n" /* line 2645 | 9.999999747378752e-05f */
        "jae .Lf1618a_00016430\n"
        "jp .Lf1618a_00016430\n"
        "movss lit4_002ed5f4, %xmm0\n" /* 4.999999873689376e-05f */
        "jmp .Lf1618a_0001636a\n"
        ".Lf1618a_00016360:\n"
        "jp .Lf1618a_00016329\n" /* line 2636 */
        "movss lit4_002ed5ec, %xmm0\n" /* 3.140000104904175f */
        ".Lf1618a_0001636a:\n"
        "cvtss2sd %xmm0, %xmm0\n" /* line 2647 */
        "movsd %xmm0, (%esp)\n"
        "calll cos\n"
        "fstpl (%esp)\n"
        "calll log\n"
        "fstpl -0x40(%ebp)\n"
        "movsd -0x40(%ebp), %xmm0\n"
        "mulsd lit8_00307c18, %xmm0\n" /* -0.30000001192092896 */
        "cvtsd2ss %xmm0, %xmm1\n"
        "movl -0x1c(%ebp), %esi\n" /* l, SaveEnable */
        "movss %xmm1, 0x60(%esi)\n" /* SaveEnable */
        "movss lit4_002ed5f8, %xmm0\n" /* line 2650 | 90.0f */
        "movl 0x10(%ebp), %eax\n" /* pLight */
        "mulss 0x64(%eax), %xmm0\n"
        "divss lit4_002ed5fc, %xmm0\n" /* 3.141592502593994f */
        "divss lit4_002ed600, %xmm0\n" /* 1.5f */
        "movss %xmm0, 0x64(%esi)\n" /* SaveEnable */
        "jmp .Lf1618a_000162b4\n"
        /* } scope */
        ".Lf1618a_000163c6:\n"
        "movss lit4_002ed5d8, %xmm0\n" /* line 2628 | 0.5f */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, (%esp)\n"
        "movss %xmm0, -0x38(%ebp)\n"
        "calll cosf\n"
        "fstps 0xa8(%esi)\n" /* SaveEnable */
        "movss -0x38(%ebp), %xmm0\n" /* line 2629 */
        "mulss 0x6c(%esi), %xmm0\n" /* SaveEnable */
        "movss %xmm0, (%esp)\n"
        "calll cosf\n"
        "fstps -0x20(%ebp)\n"
        "movss -0x20(%ebp), %xmm0\n"
        "movss %xmm0, 0xac(%esi)\n" /* SaveEnable */
        "movss 0xa8(%esi), %xmm1\n" /* line 2631 | SaveEnable */
        "subss %xmm0, %xmm1\n"
        "movss lit4_002ed5d0, %xmm0\n" /* 1.0f */
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, 0xb0(%esi)\n" /* SaveEnable */
        "jmp .Lf1618a_000162b4\n"
        /* { scope 2 */
        ".Lf1618a_00016430:\n"
        "movaps %xmm1, %xmm0\n" /* line 2645 */
        "mulss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "jmp .Lf1618a_0001636a\n"
    );
}

/* line 4044 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetSamplerState(const CDirect3DDevice * _this, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4044 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Sampler */
        "leal 0x504(%ebx), %eax\n" /* this */
        "leal 0x508(%ebx), %ecx\n" /* this */
        /* { scope 1 */
        "movl 0x504(%ebx), %edx\n" /* line 211 */
        "cmpl 0x508(%ebx), %edx\n"
        "cmovbl %ecx, %eax\n"
        /* } scope */
        "cmpl %esi, (%eax)\n" /* line 4047 | Sampler */
        "ja .Lf16440_00016478\n"
        ".Lf16440_0001646e:\n"
        "xorl %eax, %eax\n" /* line 4124 */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16440_00016478:\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 654 */
        "leal (%esi, %eax, 8), %eax\n"
        "leal (, %eax, 4), %edi\n"
        "addl 0x608(%ebx), %edi\n"
        "movl (%ebx), %edx\n" /* line 4052 | this */
        "leal -0x1c(%ebp), %eax\n" /* CurrentValue */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Type */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n" /* Sampler */
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x110(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 4053 | Value */
        "cmpl %eax, -0x1c(%ebp)\n" /* CurrentValue */
        "je .Lf16440_0001646e\n"
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        "cmpl $0xa, 0x10(%ebp)\n" /* line 4057 | Type */
        "ja .Lf16440_0001646e\n"
        "movl 0x10(%ebp), %edx\n" /* Type */
        "jmpl *.Ljt_2ee0c8(, %edx, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee0c8:\n"
        ".long .Lf16440_0001646e\n"
        ".long .Lf16440_000164c7\n"
        ".long .Lf16440_000164cc\n"
        ".long .Lf16440_000164d1\n"
        ".long .Lf16440_000164d6\n"
        ".long .Lf16440_000164db\n"
        ".long .Lf16440_000164e0\n"
        ".long .Lf16440_000164e5\n"
        ".long .Lf16440_000164ea\n"
        ".long .Lf16440_0001646e\n"
        ".long .Lf16440_00016501\n"
        ".popsection\n"
        ".Lf16440_000164c7:\n"
        "movl %eax, 8(%edi)\n" /* line 141 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164cc:\n"
        "movl %eax, 0xc(%edi)\n" /* line 146 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164d1:\n"
        "movl %eax, 0x10(%edi)\n" /* line 151 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164d6:\n"
        "movl %eax, 0x28(%edi)\n" /* line 153 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164db:\n"
        "movl %eax, 0x18(%edi)\n" /* line 166 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164e0:\n"
        "movl %eax, 0x14(%edi)\n" /* line 161 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164e5:\n"
        "movl %eax, 0x1c(%edi)\n" /* line 171 */
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_000164ea:\n"
        "movss lit4_002ed604, %xmm0\n" /* line 175 | 0.25f */
        "mulss 0x14(%ebp), %xmm0\n" /* Value */
        "movss %xmm0, 0x24(%edi)\n"
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_00016501:\n"
        "calll MacDisplay_GetSupportsAnisotropicFiltering\n" /* line 4092 */
        "testb %al, %al\n"
        "je .Lf16440_00016515\n"
        "movl 0x14(%ebp), %eax\n" /* line 183 | Value */
        "movl %eax, 0x20(%edi)\n"
        "jmp .Lf16440_0001646e\n"
        ".Lf16440_00016515:\n"
        "movl $0x3f800000, 0x20(%edi)\n"
        "jmp .Lf16440_0001646e\n"
    );
}

/* line 3976 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetSamplerState(const CDirect3DDevice * _this, DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD *pValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3976 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %esi\n" /* Sampler */
        "leal 0x504(%ebx), %eax\n" /* this */
        "leal 0x508(%ebx), %ecx\n" /* this */
        /* { scope 1 */
        "movl 0x504(%ebx), %edx\n" /* line 211 */
        "cmpl 0x508(%ebx), %edx\n"
        "cmovbl %ecx, %eax\n"
        /* } scope */
        "cmpl %esi, (%eax)\n" /* line 3979 | Sampler */
        "jbe .Lf16522_00016564\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 654 */
        "leal (%esi, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl 0x608(%ebx), %eax\n"
        "cmpl $0xa, 0x10(%ebp)\n" /* line 3983 | Type */
        "jbe .Lf16522_0001656d\n"
        ".Lf16522_00016564:\n"
        "xorl %eax, %eax\n" /* line 4035 */
        "addl $0x14, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf16522_0001656d:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3983 | Type */
        "jmpl *.Ljt_2ee0f4(, %edx, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee0f4:\n"
        ".long .Lf16522_00016564\n"
        ".long .Lf16522_00016577\n"
        ".long .Lf16522_00016617\n"
        ".long .Lf16522_0001660a\n"
        ".long .Lf16522_000165fd\n"
        ".long .Lf16522_000165f0\n"
        ".long .Lf16522_000165e3\n"
        ".long .Lf16522_000165d9\n"
        ".long .Lf16522_000165a4\n"
        ".long .Lf16522_00016564\n"
        ".long .Lf16522_00016581\n"
        ".popsection\n"
        ".Lf16522_00016577:\n"
        "movl 8(%eax), %eax\n" /* line 3986 */
        "movl 0x14(%ebp), %ecx\n" /* pValue */
        "movl %eax, (%ecx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_00016581:\n"
        "flds 0x20(%eax)\n" /* line 4013 */
        "fnstcw -0xa(%ebp)\n"
        "movzwl -0xa(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0xc(%ebp)\n"
        "fldcw -0xc(%ebp)\n"
        "fistpll -0x18(%ebp)\n"
        "fldcw -0xa(%ebp)\n"
        "movl -0x18(%ebp), %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* pValue */
        "movl %eax, (%ecx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_000165a4:\n"
        "movss lit4_002ed608, %xmm0\n" /* line 4007 | 4.0f */
        "mulss 0x24(%eax), %xmm0\n"
        "fnstcw -0xa(%ebp)\n"
        "movzwl -0xa(%ebp), %eax\n"
        "movb $0xc, %ah\n"
        "movw %ax, -0xc(%ebp)\n"
        "movss %xmm0, -0x1c(%ebp)\n"
        "flds -0x1c(%ebp)\n"
        "fldcw -0xc(%ebp)\n"
        "fistpll -0x18(%ebp)\n"
        "fldcw -0xa(%ebp)\n"
        "movl -0x18(%ebp), %eax\n"
        "movl 0x14(%ebp), %ecx\n" /* pValue */
        "movl %eax, (%ecx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_000165d9:\n"
        "movl 0x1c(%eax), %eax\n" /* line 4004 */
        "movl 0x14(%ebp), %ecx\n" /* pValue */
        "movl %eax, (%ecx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_000165e3:\n"
        "movl 0x14(%eax), %eax\n" /* line 4001 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_000165f0:\n"
        "movl 0x18(%eax), %eax\n" /* line 3998 */
        "movl 0x14(%ebp), %ecx\n" /* pValue */
        "movl %eax, (%ecx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_000165fd:\n"
        "movl 0x28(%eax), %eax\n" /* line 3995 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_0001660a:\n"
        "movl 0x10(%eax), %eax\n" /* line 3992 */
        "movl 0x14(%ebp), %ecx\n" /* pValue */
        "movl %eax, (%ecx)\n"
        "jmp .Lf16522_00016564\n"
        ".Lf16522_00016617:\n"
        "movl 0xc(%eax), %eax\n" /* line 3989 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "jmp .Lf16522_00016564\n"
    );
}

/* line 3825 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetTextureStageState(const CDirect3DDevice * _this, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3825 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x20, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* Stage */
        "cmpl %ecx, 0x504(%ebx)\n" /* line 3829 | this */
        "ja .Lf16624_00016643\n"
        ".Lf16624_0001663a:\n"
        "xorl %eax, %eax\n" /* line 3967 */
        "addl $0x20, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf16624_00016643:\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* line 654 */
        "leal (%ecx, %eax, 8), %eax\n"
        "leal (, %eax, 4), %esi\n"
        "addl 0x608(%ebx), %esi\n"
        "movl (%ebx), %edx\n" /* line 3834 | this */
        "leal -0xc(%ebp), %eax\n" /* CurrentValue */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* Type */
        "movl %eax, 8(%esp)\n"
        "movl %ecx, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll *0x108(%edx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 3835 | Value */
        "cmpl %eax, -0xc(%ebp)\n" /* CurrentValue */
        "je .Lf16624_0001663a\n"
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        "cmpl $0x1b, 0x10(%ebp)\n" /* line 3896 | Type */
        "ja .Lf16624_0001663a\n"
        "movl 0x10(%ebp), %eax\n" /* Type */
        "jmpl *.Ljt_2ee120(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee120:\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_00016692\n"
        ".long .Lf16624_0001669a\n"
        ".long .Lf16624_000166a2\n"
        ".long .Lf16624_000166aa\n"
        ".long .Lf16624_000166b2\n"
        ".long .Lf16624_000166ba\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_000166c5\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_000166d7\n"
        ".long .Lf16624_0001663a\n"
        ".long .Lf16624_000166e9\n"
        ".long .Lf16624_000166f4\n"
        ".popsection\n"
        ".Lf16624_00016692:\n"
        "movl 0x14(%ebp), %eax\n" /* line 129 | Value */
        "movl %eax, 0x2c(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_0001669a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 131 | Value */
        "movl %eax, 0x34(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166a2:\n"
        "movl 0x14(%ebp), %eax\n" /* line 132 | Value */
        "movl %eax, 0x38(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166aa:\n"
        "movl 0x14(%ebp), %eax\n" /* line 133 | Value */
        "movl %eax, 0x3c(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166b2:\n"
        "movl 0x14(%ebp), %eax\n" /* line 135 | Value */
        "movl %eax, 0x44(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166ba:\n"
        "movl 0x14(%ebp), %eax\n" /* line 136 | Value */
        "movl %eax, 0x48(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166c5:\n"
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movl 0x14(%ebp), %eax\n" /* line 156 | Value */
        "movl %eax, 0x50(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166d7:\n"
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movl 0x14(%ebp), %eax\n" /* line 155 | Value */
        "movl %eax, 0x4c(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166e9:\n"
        "movl 0x14(%ebp), %eax\n" /* line 130 | Value */
        "movl %eax, 0x30(%esi)\n"
        "jmp .Lf16624_0001663a\n"
        ".Lf16624_000166f4:\n"
        "movl 0x14(%ebp), %eax\n" /* line 134 | Value */
        "movl %eax, 0x40(%esi)\n"
        "jmp .Lf16624_0001663a\n"
    );
}

/* line 3775 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetTextureStageState(const CDirect3DDevice * _this, DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3775 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Stage */
        "cmpl %edx, 0x504(%ecx)\n" /* line 3778 */
        "jb .Lf16700_00016726\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 654 */
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl 0x608(%ecx), %eax\n"
        "cmpl $0x18, 0x10(%ebp)\n" /* line 3782 | Type */
        "jbe .Lf16700_0001672a\n"
        ".Lf16700_00016726:\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_0001672a:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3782 | Type */
        "jmpl *.Ljt_2ee190(, %edx, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee190:\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016734\n"
        ".long .Lf16700_00016788\n"
        ".long .Lf16700_0001677c\n"
        ".long .Lf16700_00016770\n"
        ".long .Lf16700_00016764\n"
        ".long .Lf16700_00016758\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_0001674c\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016726\n"
        ".long .Lf16700_00016740\n"
        ".popsection\n"
        ".Lf16700_00016734:\n"
        "movl 0x2c(%eax), %eax\n" /* line 3785 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_00016740:\n"
        "movl 0x4c(%eax), %eax\n" /* line 3806 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_0001674c:\n"
        "movl 0x50(%eax), %eax\n" /* line 3803 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_00016758:\n"
        "movl 0x48(%eax), %eax\n" /* line 3800 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_00016764:\n"
        "movl 0x44(%eax), %eax\n" /* line 3797 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_00016770:\n"
        "movl 0x3c(%eax), %eax\n" /* line 3794 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_0001677c:\n"
        "movl 0x38(%eax), %eax\n" /* line 3791 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
        ".Lf16700_00016788:\n"
        "movl 0x34(%eax), %eax\n" /* line 3788 */
        "movl 0x14(%ebp), %edx\n" /* pValue */
        "movl %eax, (%edx)\n"
        "xorl %eax, %eax\n" /* line 3816 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 2800 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetRenderState(const CDirect3DDevice * _this, D3DRENDERSTATETYPE State, DWORD Value)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2800 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        /* { scope 1: rgba, f */
        "movl 0xc(%ebp), %eax\n" /* line 2805 | State */
        "subl $7, %eax\n"
        "cmpl $0xca, %eax\n"
        "ja .Lf16794_0001688a\n"
        "jmpl *.Ljt_2ee1f4(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee1f4:\n"
        ".long .Lf16794_00016894\n"
        ".long .Lf16794_000168c5\n"
        ".long .Lf16794_00016a96\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_000169f9\n"
        ".long .Lf16794_00016f77\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_000169ae\n"
        ".long .Lf16794_00016ad1\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016a2f\n"
        ".long .Lf16794_00016a70\n"
        ".long .Lf16794_00016905\n"
        ".long .Lf16794_00016d29\n"
        ".long .Lf16794_0001694f\n"
        ".long .Lf16794_00016976\n"
        ".long .Lf16794_000169c8\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017003\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016fa8\n"
        ".long .Lf16794_000170d2\n"
        ".long .Lf16794_00016aeb\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016b03\n"
        ".long .Lf16794_00017129\n"
        ".long .Lf16794_00017158\n"
        ".long .Lf16794_00016fde\n"
        ".long .Lf16794_000171fd\n"
        ".long .Lf16794_00017187\n"
        ".long .Lf16794_000171c2\n"
        ".long .Lf16794_00016b49\n"
        ".long .Lf16794_000167b8\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_00016cda\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016ce6\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016b7b\n"
        ".long .Lf16794_00016c7c\n"
        ".long .Lf16794_00016cb0\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016cbe\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016d4f\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017295\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017223\n"
        ".long .Lf16794_000172e2\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017108\n"
        ".long .Lf16794_00017274\n"
        ".long .Lf16794_0001723b\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001725c\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016d9c\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016de4\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016e81\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016f17\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00016e46\n"
        ".long .Lf16794_00016e67\n"
        ".long .Lf16794_00016ee1\n"
        ".long .Lf16794_00016efb\n"
        ".popsection\n"
        /* { scope 2 */
        ".Lf16794_000167b8:\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3337 | Value */
        "movl %ecx, 0x578(%ebx)\n" /* this */
        "movl $0, -0x34(%ebp)\n" /* line 3343 | rgba */
        "movl $0, -0x30(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl %ecx, %eax\n"
        "shrl $0x10, %eax\n"
        "movl %eax, %edx\n"
        "andl $0xff, %edx\n"
        "js .Lf16794_00017cb3\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_000167f4:\n"
        "movss %xmm0, -0x34(%ebp)\n" /* rgba */
        "movl %ecx, %eax\n"
        "shrl $8, %eax\n"
        "movl %eax, %edx\n"
        "andl $0xff, %edx\n"
        "js .Lf16794_00017c9f\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_00016810:\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %ecx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lf16794_00017c89\n"
        "cvtsi2ssl %eax, %xmm0\n"
        ".Lf16794_00016826:\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl %ecx, %esi\n" /* m */
        "shrl $0x18, %esi\n" /* m */
        "js .Lf16794_00017c72\n"
        "cvtsi2ssl %esi, %xmm2\n" /* m */
        ".Lf16794_0001683a:\n"
        "movss lit4_002ed5cc, %xmm1\n" /* line 3345 | 0.003921568859368563f */
        "movss -0x34(%ebp), %xmm0\n" /* rgba */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* rgba */
        "movss -0x30(%ebp), %xmm0\n" /* line 3346 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 3347 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss %xmm1, %xmm2\n" /* line 3348 */
        "movss %xmm2, -0x28(%ebp)\n"
        /* { scope 3 */
        "movl 0x504(%ebx), %eax\n" /* line 3350 | this */
        "testl %eax, %eax\n"
        "jne .Lf16794_00017afe\n"
        /* } scope */
        ".Lf16794_00016883:\n"
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        /* } scope */
        /* } scope */
        ".Lf16794_0001688a:\n"
        "xorl %eax, %eax\n" /* line 3715 */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rgba, f */
        ".Lf16794_00016894:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2810 | Value */
        "cmpl %eax, 0x53c(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x53c(%ebx)\n" /* line 2812 | this */
        "movl 0x18(%ebx), %eax\n" /* line 2815 | this */
        "testl %eax, %eax\n"
        "je .Lf16794_0001688a\n"
        "movl 0x10(%ebp), %eax\n" /* line 2817 | Value */
        "testl %eax, %eax\n"
        "jne .Lf16794_00017ac3\n"
        "movl $0xb71, (%esp)\n"
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000168c5:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2822 | Value */
        "cmpl %eax, 0x588(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x588(%ebx)\n" /* line 2824 | this */
        "cmpl $2, %eax\n" /* line 2825 */
        "je .Lf16794_00017b71\n"
        "cmpl $3, %eax\n"
        "je .Lf16794_00017d86\n"
        "subl $1, %eax\n"
        "je .Lf16794_00017da6\n"
        "xorl %eax, %eax\n"
        ".Lf16794_000168f3:\n"
        "movl %eax, 4(%esp)\n" /* line 2835 */
        "movl $0x408, (%esp)\n"
        "calll glPolygonMode\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016905:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3043 | Value */
        "cmpl %edx, 0x510(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %edx, 0x510(%ebx)\n" /* line 3045 | this */
        "testl %edx, %edx\n" /* line 3046 */
        "js .Lf16794_00017d90\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_00016926:\n"
        "divss lit4_002ed5d4, %xmm0\n" /* 255.0f */
        "movss %xmm0, 0x3a8(%ebx)\n" /* this */
        "movss %xmm0, 4(%esp)\n" /* line 3047 */
        "movl 0x3ac(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glAlphaFunc\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001694f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3072 | Value */
        "movl %eax, 0x57c(%ebx)\n" /* this */
        "testl %eax, %eax\n" /* line 3073 */
        "setne %al\n"
        "movzbl %al, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetDither\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016976:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3076 | Value */
        "cmpl %eax, 0x548(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x548(%ebx)\n" /* line 3078 | this */
        "movb $1, 0x518(%ebx)\n" /* line 3079 | this */
        "movl 0x10(%ebp), %esi\n" /* line 3080 | Value, m */
        "testl %esi, %esi\n" /* m */
        "je .Lf16794_00017a86\n"
        "movl $0xbe2, (%esp)\n"
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000169ae:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2880 | Value */
        "movl %eax, 0x51c(%ebx)\n" /* this */
        "cmpl $0xb, 0x10(%ebp)\n" /* line 2882 | Value */
        "ja .Lf16794_0001688a\n"
        "jmpl *.Ljt_2ee520(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee520:\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017935\n"
        ".long .Lf16794_000176ab\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_000176ba\n"
        ".long .Lf16794_000176c9\n"
        ".long .Lf16794_000176d8\n"
        ".long .Lf16794_000176e7\n"
        ".long .Lf16794_000176f6\n"
        ".long .Lf16794_00017705\n"
        ".long .Lf16794_00017714\n"
        ".popsection\n"
        ".Lf16794_000169c8:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3198 | Value */
        "cmpl %eax, 0x580(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x580(%ebx)\n" /* line 3200 | this */
        "movl 0x10(%ebp), %ebx\n" /* line 3201 | Value, this */
        "testl %ebx, %ebx\n" /* this */
        "je .Lf16794_00017a64\n"
        "movl $0xb60, (%esp)\n"
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000169f9:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2855 | Value */
        "cmpl %eax, 0x544(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x544(%ebx)\n" /* line 2857 | this */
        "movl 0x18(%ebx), %eax\n" /* line 2860 | this */
        "testl %eax, %eax\n"
        "je .Lf16794_0001688a\n"
        "xorl %eax, %eax\n" /* line 2862 */
        "cmpl $0, 0x10(%ebp)\n" /* Value */
        "setne %al\n"
        "movl %eax, (%esp)\n"
        "calll glDepthMask\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016a2f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3006 | Value */
        "cmpl %eax, 0x538(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x538(%ebx)\n" /* line 3009 | this */
        "cmpl $2, %eax\n" /* line 3010 */
        "je .Lf16794_00017b54\n"
        "cmpl $3, %eax\n"
        "je .Lf16794_00017d69\n"
        "subl $1, %eax\n"
        "jne .Lf16794_0001688a\n"
        "movl $0xb44, (%esp)\n" /* line 3012 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016a70:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3020 | Value */
        "cmpl %eax, 0x540(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x540(%ebx)\n" /* line 3022 | this */
        "cmpl $8, 0x10(%ebp)\n" /* line 3023 | Value */
        "ja .Lf16794_00017465\n"
        "jmpl *.Ljt_2ee550(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee550:\n"
        ".long .Lf16794_00017465\n"
        ".long .Lf16794_0001792b\n"
        ".long .Lf16794_00017606\n"
        ".long .Lf16794_00017610\n"
        ".long .Lf16794_0001761a\n"
        ".long .Lf16794_00017624\n"
        ".long .Lf16794_000175f2\n"
        ".long .Lf16794_000175fc\n"
        ".long .Lf16794_000175e8\n"
        ".popsection\n"
        ".Lf16794_00016a96:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2839 | Value */
        "cmpl %eax, 0x58c(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x58c(%ebx)\n" /* line 2841 | this */
        "cmpl $1, %eax\n" /* line 2842 */
        "je .Lf16794_00017b7b\n"
        "movl $0x1d01, %edx\n"
        "cmpl $2, %eax\n"
        "movl $0, %eax\n"
        "cmovnel %eax, %edx\n"
        ".Lf16794_00016ac4:\n"
        "movl %edx, (%esp)\n" /* line 2851 */
        "calll glShadeModel\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016ad1:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2903 | Value */
        "movl %eax, 0x524(%ebx)\n" /* this */
        "cmpl $0xb, 0x10(%ebp)\n" /* line 2905 | Value */
        "ja .Lf16794_0001688a\n"
        "jmpl *.Ljt_2ee574(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee574:\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001778c\n"
        ".long .Lf16794_0001779b\n"
        ".long .Lf16794_000177b9\n"
        ".long .Lf16794_000177c8\n"
        ".long .Lf16794_000177d7\n"
        ".long .Lf16794_000177e6\n"
        ".long .Lf16794_000177f5\n"
        ".long .Lf16794_00017804\n"
        ".long .Lf16794_00017813\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017822\n"
        ".popsection\n"
        ".Lf16794_00016aeb:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3242 | Value */
        "movl %eax, 4(%esp)\n"
        "movl $0xb62, (%esp)\n"
        "calll glFogf\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016b03:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3254 | Value */
        "cmpl %eax, 0x554(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x554(%ebx)\n" /* line 3256 | this */
        "movl $0, 4(%esp)\n" /* line 3257 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3258 | Value */
        "testl %ecx, %ecx\n"
        "je .Lf16794_00017aed\n"
        "movl $0xb90, (%esp)\n"
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016b49:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3324 | Value */
        "cmpl %eax, 0x574(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "andl $0xff, %eax\n" /* line 3326 */
        "movl %eax, 0x574(%ebx)\n" /* this */
        "movl 0x18(%ebx), %edx\n" /* line 3329 | this */
        "testl %edx, %edx\n"
        "je .Lf16794_0001688a\n"
        "movl %eax, (%esp)\n" /* line 3331 */
        "calll glStencilMask\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_00016b7b:\n"
        "movl $0, -0x34(%ebp)\n" /* line 3394 | rgba */
        "movl $0, -0x30(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* Value */
        "movl %ecx, %eax\n"
        "shrl $0x10, %eax\n"
        "movl %eax, %edx\n"
        "andl $0xff, %edx\n"
        "js .Lf16794_00017c4d\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_00016bb1:\n"
        "movss %xmm0, -0x34(%ebp)\n" /* rgba */
        "movl %ecx, %eax\n"
        "shrl $8, %eax\n"
        "movl %eax, %edx\n"
        "andl $0xff, %edx\n"
        "js .Lf16794_00017c39\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_00016bcd:\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %ecx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lf16794_00017c23\n"
        "cvtsi2ssl %eax, %xmm0\n"
        ".Lf16794_00016be3:\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl %ecx, %esi\n" /* m */
        "shrl $0x18, %esi\n" /* m */
        "js .Lf16794_00017c0c\n"
        "cvtsi2ssl %esi, %xmm4\n" /* m */
        ".Lf16794_00016bf7:\n"
        "movss lit4_002ed5cc, %xmm0\n" /* line 3396 | 0.003921568859368563f */
        "movss -0x34(%ebp), %xmm3\n" /* rgba */
        "mulss %xmm0, %xmm3\n"
        "movss %xmm3, -0x34(%ebp)\n" /* rgba */
        "movss -0x30(%ebp), %xmm2\n" /* line 3397 */
        "mulss %xmm0, %xmm2\n"
        "movss %xmm2, -0x30(%ebp)\n"
        "movss -0x2c(%ebp), %xmm1\n" /* line 3398 */
        "mulss %xmm0, %xmm1\n"
        "movss %xmm1, -0x2c(%ebp)\n"
        "mulss %xmm4, %xmm0\n" /* line 3399 */
        "movss %xmm0, -0x28(%ebp)\n"
        "movss %xmm3, 0x59c(%ebx)\n" /* line 3401 | this */
        "movss %xmm2, 0x5a0(%ebx)\n" /* line 3402 | this */
        "movss %xmm1, 0x5a4(%ebx)\n" /* line 3403 | this */
        "movss %xmm0, 0x5a8(%ebx)\n" /* line 3404 | this */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 3406 */
        "cmpb $0, 0x800(%eax)\n"
        "jne .Lf16794_0001688a\n"
        "leal -0x34(%ebp), %eax\n" /* line 3408 | rgba */
        "movl %eax, 4(%esp)\n"
        "movl $0xb53, (%esp)\n"
        "calll glLightModelfv\n"
        "jmp .Lf16794_0001688a\n"
        /* } scope */
        ".Lf16794_00016c7c:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3413 | Value */
        "cmpl $2, %eax\n"
        "je .Lf16794_00017b3b\n"
        "jb .Lf16794_00017ad4\n"
        "cmpl $3, %eax\n"
        "jne .Lf16794_0001688a\n"
        "movl $0x46180400, 4(%esp)\n" /* line 3418 */
        "movl $0xb65, (%esp)\n"
        "calll glFogf\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016cb0:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3423 | Value */
        "movl %eax, 0x52c(%ebx)\n" /* this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016cbe:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3430 | Value */
        "testl %eax, %eax\n"
        "je .Lf16794_00017a53\n"
        "movl $0xba1, (%esp)\n"
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016cda:\n"
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016ce6:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 3377 */
        "cmpb $0, 0x800(%eax)\n"
        "jne .Lf16794_00017a45\n"
        "movl 0x10(%ebp), %eax\n" /* line 3379 | Value */
        "cmpl %eax, 0x584(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x584(%ebx)\n" /* line 3381 | this */
        "movl 0x10(%ebp), %eax\n" /* line 3382 | Value */
        "testl %eax, %eax\n"
        "je .Lf16794_00017bfb\n"
        "movl $0xb50, (%esp)\n"
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016d29:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3051 | Value */
        "cmpl %eax, 0x514(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x514(%ebx)\n" /* line 3053 | this */
        "cmpl $8, 0x10(%ebp)\n" /* line 3054 | Value */
        "ja .Lf16794_00017356\n"
        "jmpl *.Ljt_2ee5a4(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee5a4:\n"
        ".long .Lf16794_00017356\n"
        ".long .Lf16794_000177aa\n"
        ".long .Lf16794_000178d1\n"
        ".long .Lf16794_000178e0\n"
        ".long .Lf16794_000178ef\n"
        ".long .Lf16794_000178fe\n"
        ".long .Lf16794_0001790d\n"
        ".long .Lf16794_0001791c\n"
        ".long .Lf16794_0001734c\n"
        ".popsection\n"
        ".Lf16794_00016d4f:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3444 | Value */
        "cmpl %eax, 0x534(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x534(%ebx)\n" /* line 3446 | this */
        "cmpl $1, %eax\n" /* line 3447 */
        "je .Lf16794_00017b85\n"
        "testl %eax, %eax\n" /* line 3460 */
        "jne .Lf16794_0001688a\n"
        "cmpl $1, 0x530(%ebx)\n" /* line 3462 | this */
        "je .Lf16794_00017db0\n"
        "movl $0, 4(%esp)\n" /* line 3469 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016d9c:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3579 | Value */
        "cmpl %edx, 0x590(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %edx, 0x590(%ebx)\n" /* line 3581 | this */
        "movl %edx, %eax\n" /* line 3587 */
        "shrl $3, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $2, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "andl $1, %edx\n"
        "movl %edx, (%esp)\n"
        "calll glColorMask\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016de4:\n"
        "movl 0x10(%ebp), %ecx\n" /* Value */
        ".Lf16794_00016de7:\n"
        "cmpl %ecx, 0x594(%ebx)\n" /* line 3611 | this */
        "je .Lf16794_0001688a\n"
        "movl %ecx, 0x594(%ebx)\n" /* line 3613 | this */
        "cmpl $1, %ecx\n" /* line 3615 */
        "je .Lf16794_00017a97\n"
        "leal -2(%ecx), %eax\n" /* line 3626 */
        "cmpl $1, %eax\n"
        "jbe .Lf16794_00017d24\n"
        "leal -4(%ecx), %eax\n" /* line 3637 */
        "cmpl $1, %eax\n"
        "ja .Lf16794_0001688a\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 3639 */
        "cmpb $0, 0x80a(%eax)\n"
        "je .Lf16794_0001688a\n"
        "xorl %eax, %eax\n" /* line 3641 */
        "cmpl $4, %ecx\n"
        "setne %al\n"
        "addl $0x8007, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glBlendEquationEXT\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016e46:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3085 | Value */
        "cmpl %eax, 0x54c(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x54c(%ebx)\n" /* line 3087 | this */
        "movb $1, 0x518(%ebx)\n" /* line 3088 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016e67:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3093 | Value */
        "movl %eax, 0x520(%ebx)\n" /* this */
        "cmpl $0xb, 0x10(%ebp)\n" /* line 3095 | Value */
        "ja .Lf16794_0001688a\n"
        "jmpl *.Ljt_2ee5c8(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee5c8:\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001764c\n"
        ".long .Lf16794_000179bc\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_000179cb\n"
        ".long .Lf16794_000179da\n"
        ".long .Lf16794_000179e9\n"
        ".long .Lf16794_000179f8\n"
        ".long .Lf16794_00017a07\n"
        ".long .Lf16794_00017a16\n"
        ".long .Lf16794_00017a25\n"
        ".popsection\n"
        ".Lf16794_00016e81:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3669 | Value */
        "movss %xmm0, 0xbc4(%ebx)\n" /* this */
        "mulss g_scale1, %xmm0\n" /* line 3670 */
        "movss %xmm0, 0xbc4(%ebx)\n" /* this */
        "movl 0xbc8(%ebx), %eax\n" /* line 3671 | this */
        "movl %eax, 4(%esp)\n"
        "movss %xmm0, (%esp)\n"
        "calll glPolygonOffset\n"
        "pxor %xmm0, %xmm0\n" /* line 3672 */
        "ucomiss 0xbc8(%ebx), %xmm0\n" /* this */
        "jne .Lf16794_00016ed0\n"
        "jp .Lf16794_00016ed0\n"
        "ucomiss 0xbc4(%ebx), %xmm0\n" /* this */
        "jp .Lf16794_00016ed0\n"
        "je .Lf16794_00017c61\n"
        ".Lf16794_00016ed0:\n"
        "movl $0x8037, (%esp)\n" /* line 3674 */
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016ee1:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3115 | Value */
        "movl %eax, 0x528(%ebx)\n" /* this */
        "cmpl $0xb, 0x10(%ebp)\n" /* line 3117 | Value */
        "ja .Lf16794_0001688a\n"
        "jmpl *.Ljt_2ee5f8(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee5f8:\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017944\n"
        ".long .Lf16794_00017953\n"
        ".long .Lf16794_00017962\n"
        ".long .Lf16794_0001688a\n"
        ".long .Lf16794_00017971\n"
        ".long .Lf16794_00017980\n"
        ".long .Lf16794_0001798f\n"
        ".long .Lf16794_0001799e\n"
        ".long .Lf16794_000179ad\n"
        ".long .Lf16794_0001762e\n"
        ".long .Lf16794_0001763d\n"
        ".popsection\n"
        ".Lf16794_00016efb:\n"
        "movl 0x54c(%ebx), %eax\n" /* line 3596 | this */
        "testl %eax, %eax\n"
        "je .Lf16794_0001688a\n"
        "movl 0x10(%ebp), %ecx\n" /* line 3602 | Value */
        "movl %ecx, 0x598(%ebx)\n" /* this */
        "jmp .Lf16794_00016de7\n"
        ".Lf16794_00016f17:\n"
        "movss 0x10(%ebp), %xmm0\n" /* line 3656 | Value */
        "movss %xmm0, 0xbc8(%ebx)\n" /* this */
        "mulss g_scale2, %xmm0\n" /* line 3657 */
        "movss %xmm0, 0xbc8(%ebx)\n" /* this */
        "movss %xmm0, 4(%esp)\n" /* line 3658 */
        "movl 0xbc4(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glPolygonOffset\n"
        "pxor %xmm0, %xmm0\n" /* line 3659 */
        "ucomiss 0xbc8(%ebx), %xmm0\n" /* this */
        "jne .Lf16794_00016f66\n"
        "jp .Lf16794_00016f66\n"
        "ucomiss 0xbc4(%ebx), %xmm0\n" /* this */
        "jp .Lf16794_00016f66\n"
        "je .Lf16794_00017d50\n"
        ".Lf16794_00016f66:\n"
        "movl $0x8037, (%esp)\n" /* line 3661 */
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00016f77:\n"
        "movl 0x10(%ebp), %eax\n" /* line 2867 | Value */
        "cmpl %eax, 0x50c(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x50c(%ebx)\n" /* line 2869 | this */
        "movl 0x10(%ebp), %edi\n" /* line 2870 | Value */
        "testl %edi, %edi\n"
        "je .Lf16794_00017a75\n"
        "movl $0xbc0, (%esp)\n"
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_00016fa8:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3227 | Value */
        "movl %eax, -0x24(%ebp)\n" /* f */
        "pxor %xmm0, %xmm0\n" /* line 3228 */
        "movss %xmm0, -0x1c(%ebp)\n"
        /* { scope 3 */
        "ucomiss -0x24(%ebp), %xmm0\n" /* line 211 | f */
        "ja .Lf16794_00017d1c\n"
        "leal -0x24(%ebp), %eax\n" /* f */
        /* } scope */
        ".Lf16794_00016fc4:\n"
        "movl (%eax), %eax\n" /* line 3228 | __b */
        "movl %eax, -0x24(%ebp)\n" /* __b, f */
        "movl %eax, 4(%esp)\n" /* line 3229 */
        "movl $0xb63, (%esp)\n"
        "calll glFogf\n"
        "jmp .Lf16794_0001688a\n"
        /* } scope */
        ".Lf16794_00016fde:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3276 | Value */
        "cmpl %eax, 0x560(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x560(%ebx)\n" /* line 3278 | this */
        /* { scope 2 */
        "cmpl $8, %eax\n" /* line 2769 */
        "ja .Lf16794_0001741e\n"
        "jmpl *.Ljt_2ee628(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee628:\n"
        ".long .Lf16794_0001741e\n"
        ".long .Lf16794_00017683\n"
        ".long .Lf16794_0001741e\n"
        ".long .Lf16794_0001768d\n"
        ".long .Lf16794_00017697\n"
        ".long .Lf16794_000176a1\n"
        ".long .Lf16794_0001766f\n"
        ".long .Lf16794_00017679\n"
        ".long .Lf16794_0001758e\n"
        ".popsection\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017003:\n"
        "movl $0, -0x34(%ebp)\n" /* line 3211 | rgba */
        "movl $0, -0x30(%ebp)\n"
        "movl $0, -0x2c(%ebp)\n"
        "movl $0, -0x28(%ebp)\n"
        "movl 0x10(%ebp), %ecx\n" /* Value */
        "movl %ecx, %eax\n"
        "shrl $0x10, %eax\n"
        "movl %eax, %edx\n"
        "andl $0xff, %edx\n"
        "js .Lf16794_00017d08\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_00017039:\n"
        "movss %xmm0, -0x34(%ebp)\n" /* rgba */
        "movl %ecx, %eax\n"
        "shrl $8, %eax\n"
        "movl %eax, %edx\n"
        "andl $0xff, %edx\n"
        "js .Lf16794_00017cf4\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf16794_00017055:\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movl %ecx, %eax\n"
        "andl $0xff, %eax\n"
        "js .Lf16794_00017cde\n"
        "cvtsi2ssl %eax, %xmm0\n"
        ".Lf16794_0001706b:\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "movl %ecx, %ebx\n" /* this */
        "shrl $0x18, %ebx\n" /* this */
        "js .Lf16794_00017cc7\n"
        "cvtsi2ssl %ebx, %xmm2\n" /* this */
        ".Lf16794_0001707f:\n"
        "movss lit4_002ed5cc, %xmm1\n" /* line 3213 | 0.003921568859368563f */
        "movss -0x34(%ebp), %xmm0\n" /* rgba */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x34(%ebp)\n" /* rgba */
        "movss -0x30(%ebp), %xmm0\n" /* line 3214 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x30(%ebp)\n"
        "movss -0x2c(%ebp), %xmm0\n" /* line 3215 */
        "mulss %xmm1, %xmm0\n"
        "movss %xmm0, -0x2c(%ebp)\n"
        "mulss %xmm1, %xmm2\n" /* line 3216 */
        "movss %xmm2, -0x28(%ebp)\n"
        "leal -0x34(%ebp), %eax\n" /* line 3218 | rgba */
        "movl %eax, 4(%esp)\n"
        "movl $0xb66, (%esp)\n"
        "calll glFogfv\n"
        "jmp .Lf16794_0001688a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000170d2:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3234 | Value */
        "movl %eax, -0x24(%ebp)\n" /* f */
        "pxor %xmm0, %xmm0\n" /* line 3235 */
        "movss %xmm0, -0x20(%ebp)\n"
        /* { scope 3 */
        "ucomiss -0x24(%ebp), %xmm0\n" /* line 211 | f */
        "ja .Lf16794_00017d61\n"
        "leal -0x24(%ebp), %eax\n" /* f */
        /* } scope */
        ".Lf16794_000170ee:\n"
        "movl (%eax), %eax\n" /* line 3235 | __b */
        "movl %eax, -0x24(%ebp)\n" /* __b, f */
        "movl %eax, 4(%esp)\n" /* line 3236 */
        "movl $0xb64, (%esp)\n"
        "calll glFogf\n"
        "jmp .Lf16794_0001688a\n"
        /* } scope */
        ".Lf16794_00017108:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3549 | Value */
        "movl %eax, sPointScale\n"
        "movl $sPointScale, 4(%esp)\n" /* line 3550 */
        "movl $0x8129, (%esp)\n"
        "calll glPointParameterfvARB\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017129:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3262 | Value */
        "cmpl %edx, 0x558(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %edx, 0x558(%ebx)\n" /* line 3264 | this */
        /* { scope 2 */
        "cmpl $8, 0x560(%ebx)\n" /* line 2769 */
        "ja .Lf16794_000173a4\n"
        "movl 0x560(%ebx), %eax\n"
        "jmpl *.Ljt_2ee64c(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee64c:\n"
        ".long .Lf16794_000173a4\n"
        ".long .Lf16794_000174ee\n"
        ".long .Lf16794_000173a4\n"
        ".long .Lf16794_000174f8\n"
        ".long .Lf16794_00017502\n"
        ".long .Lf16794_0001750c\n"
        ".long .Lf16794_0001749e\n"
        ".long .Lf16794_000174a8\n"
        ".long .Lf16794_00017831\n"
        ".popsection\n"
        /* } scope */
        ".Lf16794_00017158:\n"
        "movl 0x10(%ebp), %edx\n" /* line 3269 | Value */
        "cmpl %edx, 0x55c(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %edx, 0x55c(%ebx)\n" /* line 3271 | this */
        /* { scope 2 */
        "cmpl $8, 0x560(%ebx)\n" /* line 2769 */
        "ja .Lf16794_000173e1\n"
        "movl 0x560(%ebx), %eax\n"
        "jmpl *.Ljt_2ee670(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee670:\n"
        ".long .Lf16794_000173e1\n"
        ".long .Lf16794_000178a9\n"
        ".long .Lf16794_000173e1\n"
        ".long .Lf16794_000178b3\n"
        ".long .Lf16794_000178bd\n"
        ".long .Lf16794_000178c7\n"
        ".long .Lf16794_00017895\n"
        ".long .Lf16794_0001789f\n"
        ".long .Lf16794_0001788b\n"
        ".popsection\n"
        /* } scope */
        ".Lf16794_00017187:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3308 | Value */
        "cmpl %eax, 0x56c(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "andl $0xff, %eax\n" /* line 3310 */
        "movl %eax, 0x56c(%ebx)\n" /* this */
        "movl 0x570(%ebx), %edx\n" /* line 3311 | this */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x568(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glStencilFunc\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000171c2:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3317 | Value */
        "cmpl %eax, 0x570(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "andl $0xff, %eax\n" /* line 3319 */
        "movl %eax, 0x570(%ebx)\n" /* this */
        "movl %eax, 8(%esp)\n" /* line 3320 */
        "movl 0x56c(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x568(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glStencilFunc\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000171fd:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3285 | Value */
        "cmpl %eax, 0x564(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x564(%ebx)\n" /* line 3287 | this */
        "cmpl $8, 0x10(%ebp)\n" /* line 3288 | Value */
        "ja .Lf16794_0001737d\n"
        "jmpl *.Ljt_2ee694(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee694:\n"
        ".long .Lf16794_0001737d\n"
        ".long .Lf16794_00017723\n"
        ".long .Lf16794_00017750\n"
        ".long .Lf16794_0001775f\n"
        ".long .Lf16794_0001776e\n"
        ".long .Lf16794_0001777d\n"
        ".long .Lf16794_00017732\n"
        ".long .Lf16794_00017741\n"
        ".long .Lf16794_00017373\n"
        ".popsection\n"
        ".Lf16794_00017223:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3535 | Value */
        "movl %eax, 4(%esp)\n"
        "movl $0x8126, (%esp)\n"
        "calll glPointParameterfARB\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001723b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3557 | Value */
        "movl %eax, 0x334e08\n"
        "movl $sPointScale, 4(%esp)\n" /* line 3558 */
        "movl $0x8129, (%esp)\n"
        "calll glPointParameterfvARB\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001725c:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3573 | Value */
        "movl %eax, 4(%esp)\n"
        "movl $0x8127, (%esp)\n"
        "calll glPointParameterfARB\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017274:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3553 | Value */
        "movl %eax, 0x334e04\n"
        "movl $sPointScale, 4(%esp)\n" /* line 3554 */
        "movl $0x8129, (%esp)\n"
        "calll glPointParameterfvARB\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017295:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3486 | Value */
        "cmpl %eax, 0x530(%ebx)\n" /* this */
        "je .Lf16794_0001688a\n"
        "movl %eax, 0x530(%ebx)\n" /* line 3488 | this */
        "cmpl $1, %eax\n" /* line 3489 */
        "je .Lf16794_00017bc0\n"
        "testl %eax, %eax\n" /* line 3502 */
        "jne .Lf16794_0001688a\n"
        "cmpl $1, 0x534(%ebx)\n" /* line 3504 | this */
        "je .Lf16794_00017dde\n"
        "movl $0, 4(%esp)\n" /* line 3511 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000172e2:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3538 | Value */
        "testl %eax, %eax\n"
        "je .Lf16794_00017a34\n"
        "movl $0x8861, (%esp)\n"
        "calll glEnable\n"
        /* { scope 2 */
        ".Lf16794_000172f9:\n"
        "movl 0x504(%ebx), %eax\n" /* line 3540 | this */
        "testl %eax, %eax\n"
        "je .Lf16794_0001688a\n"
        "xorl %esi, %esi\n" /* i */
        "movl imp___ZN7COpenGL7sOpenGLE, %edi\n" /* i */
        ".Lf16794_0001730f:\n"
        "movl %esi, 4(%esp)\n" /* line 3542 | i */
        "movl %edi, (%esp)\n" /* i */
        "calll COpenGL_SetActiveTexUnit\n"
        "xorl %eax, %eax\n" /* line 3543 */
        "cmpl $0, 0x10(%ebp)\n" /* Value */
        "setne %al\n"
        "movl %eax, 8(%esp)\n"
        "movl $0x8862, 4(%esp)\n"
        "movl $0x8861, (%esp)\n"
        "calll glTexEnvi\n"
        "addl $1, %esi\n" /* line 3540 | i */
        "cmpl %esi, 0x504(%ebx)\n" /* i, this */
        "ja .Lf16794_0001730f\n"
        "jmp .Lf16794_0001688a\n"
        /* } scope */
        ".Lf16794_0001734c:\n"
        "movl $0x207, 0x3ac(%ebx)\n" /* line 3063 | this */
        ".Lf16794_00017356:\n"
        "movl 0x3a8(%ebx), %eax\n" /* line 3068 | this */
        "movl %eax, 4(%esp)\n"
        "movl 0x3ac(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glAlphaFunc\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017373:\n"
        "movl $0x207, 0x568(%ebx)\n" /* line 3297 | this */
        ".Lf16794_0001737d:\n"
        "movl 0x570(%ebx), %eax\n" /* line 3302 | this */
        "movl %eax, 8(%esp)\n"
        "movl 0x56c(%ebx), %eax\n" /* this */
        "movl %eax, 4(%esp)\n"
        "movl 0x568(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll glStencilFunc\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_000173a4:\n"
        "xorl %esi, %esi\n" /* line 2769 | m */
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000173a6:\n"
        "cmpl $8, 0x55c(%ebx)\n"
        "ja .Lf16794_000173bc\n"
        "movl 0x55c(%ebx), %eax\n"
        "jmpl *.Ljt_2ee6b8(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee6b8:\n"
        ".long .Lf16794_000173bc\n"
        ".long .Lf16794_0001783b\n"
        ".long .Lf16794_000173bc\n"
        ".long .Lf16794_00017845\n"
        ".long .Lf16794_0001784f\n"
        ".long .Lf16794_00017859\n"
        ".long .Lf16794_00017863\n"
        ".long .Lf16794_0001786d\n"
        ".long .Lf16794_00017877\n"
        ".popsection\n"
        ".Lf16794_000173bc:\n"
        "xorl %ecx, %ecx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000173be:\n"
        "cmpl $8, %edx\n"
        "ja .Lf16794_000173ca\n"
        "jmpl *.Ljt_2ee6dc(, %edx, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee6dc:\n"
        ".long .Lf16794_000173ca\n"
        ".long .Lf16794_00017881\n"
        ".long .Lf16794_000173ca\n"
        ".long .Lf16794_000174b2\n"
        ".long .Lf16794_000174bc\n"
        ".long .Lf16794_000174c6\n"
        ".long .Lf16794_000174d0\n"
        ".long .Lf16794_000174da\n"
        ".long .Lf16794_000174e4\n"
        ".popsection\n"
        ".Lf16794_000173ca:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf16794_000173cc:\n"
        "movl %esi, 8(%esp)\n" /* line 3265 | m */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glStencilOp\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_000173e1:\n"
        "xorl %ecx, %ecx\n" /* line 2769 */
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000173e3:\n"
        "cmpl $8, %edx\n"
        "ja .Lf16794_000173ef\n"
        "jmpl *.Ljt_2ee700(, %edx, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee700:\n"
        ".long .Lf16794_000173ef\n"
        ".long .Lf16794_0001753e\n"
        ".long .Lf16794_000173ef\n"
        ".long .Lf16794_0001765b\n"
        ".long .Lf16794_00017665\n"
        ".long .Lf16794_00017516\n"
        ".long .Lf16794_00017520\n"
        ".long .Lf16794_0001752a\n"
        ".long .Lf16794_00017534\n"
        ".popsection\n"
        ".Lf16794_000173ef:\n"
        "xorl %edx, %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000173f1:\n"
        "cmpl $8, 0x558(%ebx)\n"
        "ja .Lf16794_00017407\n"
        "movl 0x558(%ebx), %eax\n"
        "jmpl *.Ljt_2ee724(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee724:\n"
        ".long .Lf16794_00017407\n"
        ".long .Lf16794_00017548\n"
        ".long .Lf16794_00017407\n"
        ".long .Lf16794_00017552\n"
        ".long .Lf16794_0001755c\n"
        ".long .Lf16794_00017566\n"
        ".long .Lf16794_00017570\n"
        ".long .Lf16794_0001757a\n"
        ".long .Lf16794_00017584\n"
        ".popsection\n"
        ".Lf16794_00017407:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf16794_00017409:\n"
        "movl %ecx, 8(%esp)\n" /* line 3272 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glStencilOp\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_0001741e:\n"
        "xorl %ecx, %ecx\n" /* line 2769 */
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017420:\n"
        "cmpl $8, 0x55c(%ebx)\n"
        "ja .Lf16794_00017436\n"
        "movl 0x55c(%ebx), %eax\n"
        "jmpl *.Ljt_2ee748(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee748:\n"
        ".long .Lf16794_00017436\n"
        ".long .Lf16794_00017598\n"
        ".long .Lf16794_00017436\n"
        ".long .Lf16794_000175a2\n"
        ".long .Lf16794_000175ac\n"
        ".long .Lf16794_000175b6\n"
        ".long .Lf16794_000175c0\n"
        ".long .Lf16794_000175ca\n"
        ".long .Lf16794_000175d4\n"
        ".popsection\n"
        ".Lf16794_00017436:\n"
        "xorl %edx, %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017438:\n"
        "cmpl $8, 0x558(%ebx)\n"
        "ja .Lf16794_0001744e\n"
        "movl 0x558(%ebx), %eax\n"
        "jmpl *.Ljt_2ee76c(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee76c:\n"
        ".long .Lf16794_0001744e\n"
        ".long .Lf16794_000175de\n"
        ".long .Lf16794_0001744e\n"
        ".long .Lf16794_00017474\n"
        ".long .Lf16794_0001747b\n"
        ".long .Lf16794_00017482\n"
        ".long .Lf16794_00017489\n"
        ".long .Lf16794_00017490\n"
        ".long .Lf16794_00017497\n"
        ".popsection\n"
        ".Lf16794_0001744e:\n"
        "xorl %eax, %eax\n"
        /* } scope */
        ".Lf16794_00017450:\n"
        "movl %ecx, 8(%esp)\n" /* line 3279 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glStencilOp\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017465:\n"
        "xorl %eax, %eax\n" /* line 3023 */
        ".Lf16794_00017467:\n"
        "movl %eax, (%esp)\n" /* line 3037 */
        "calll glDepthFunc\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_00017474:\n"
        "movl $0x1e01, %eax\n" /* line 2771 */
        "jmp .Lf16794_00017450\n"
        ".Lf16794_0001747b:\n"
        "movl $0x1e02, %eax\n" /* line 2773 */
        "jmp .Lf16794_00017450\n"
        ".Lf16794_00017482:\n"
        "movl $0x1e03, %eax\n" /* line 2774 */
        "jmp .Lf16794_00017450\n"
        ".Lf16794_00017489:\n"
        "movl $0x150a, %eax\n" /* line 2775 */
        "jmp .Lf16794_00017450\n"
        ".Lf16794_00017490:\n"
        "movl $0x8507, %eax\n" /* line 2776 */
        "jmp .Lf16794_00017450\n"
        ".Lf16794_00017497:\n"
        "movl $0x8508, %eax\n" /* line 2769 */
        "jmp .Lf16794_00017450\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_0001749e:\n"
        "movl $0x150a, %esi\n" /* line 2775 | m */
        "jmp .Lf16794_000173a6\n"
        ".Lf16794_000174a8:\n"
        "movl $0x8507, %esi\n" /* line 2776 | m */
        "jmp .Lf16794_000173a6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000174b2:\n"
        "movl $0x1e01, %eax\n" /* line 2771 */
        "jmp .Lf16794_000173cc\n"
        ".Lf16794_000174bc:\n"
        "movl $0x1e02, %eax\n" /* line 2773 */
        "jmp .Lf16794_000173cc\n"
        ".Lf16794_000174c6:\n"
        "movl $0x1e03, %eax\n" /* line 2774 */
        "jmp .Lf16794_000173cc\n"
        ".Lf16794_000174d0:\n"
        "movl $0x150a, %eax\n" /* line 2775 */
        "jmp .Lf16794_000173cc\n"
        ".Lf16794_000174da:\n"
        "movl $0x8507, %eax\n" /* line 2776 */
        "jmp .Lf16794_000173cc\n"
        ".Lf16794_000174e4:\n"
        "movl $0x8508, %eax\n" /* line 2769 */
        "jmp .Lf16794_000173cc\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000174ee:\n"
        "movl $0x1e00, %esi\n" /* m */
        "jmp .Lf16794_000173a6\n"
        ".Lf16794_000174f8:\n"
        "movl $0x1e01, %esi\n" /* line 2771 | m */
        "jmp .Lf16794_000173a6\n"
        ".Lf16794_00017502:\n"
        "movl $0x1e02, %esi\n" /* line 2773 | m */
        "jmp .Lf16794_000173a6\n"
        ".Lf16794_0001750c:\n"
        "movl $0x1e03, %esi\n" /* line 2774 | m */
        "jmp .Lf16794_000173a6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017516:\n"
        "movl $0x1e03, %edx\n"
        "jmp .Lf16794_000173f1\n"
        ".Lf16794_00017520:\n"
        "movl $0x150a, %edx\n" /* line 2775 */
        "jmp .Lf16794_000173f1\n"
        ".Lf16794_0001752a:\n"
        "movl $0x8507, %edx\n" /* line 2776 */
        "jmp .Lf16794_000173f1\n"
        ".Lf16794_00017534:\n"
        "movl $0x8508, %edx\n" /* line 2769 */
        "jmp .Lf16794_000173f1\n"
        ".Lf16794_0001753e:\n"
        "movl $0x1e00, %edx\n"
        "jmp .Lf16794_000173f1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017548:\n"
        "movl $0x1e00, %eax\n"
        "jmp .Lf16794_00017409\n"
        ".Lf16794_00017552:\n"
        "movl $0x1e01, %eax\n" /* line 2771 */
        "jmp .Lf16794_00017409\n"
        ".Lf16794_0001755c:\n"
        "movl $0x1e02, %eax\n" /* line 2773 */
        "jmp .Lf16794_00017409\n"
        ".Lf16794_00017566:\n"
        "movl $0x1e03, %eax\n" /* line 2774 */
        "jmp .Lf16794_00017409\n"
        ".Lf16794_00017570:\n"
        "movl $0x150a, %eax\n" /* line 2775 */
        "jmp .Lf16794_00017409\n"
        ".Lf16794_0001757a:\n"
        "movl $0x8507, %eax\n" /* line 2776 */
        "jmp .Lf16794_00017409\n"
        ".Lf16794_00017584:\n"
        "movl $0x8508, %eax\n" /* line 2769 */
        "jmp .Lf16794_00017409\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_0001758e:\n"
        "movl $0x8508, %ecx\n"
        "jmp .Lf16794_00017420\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017598:\n"
        "movl $0x1e00, %edx\n"
        "jmp .Lf16794_00017438\n"
        ".Lf16794_000175a2:\n"
        "movl $0x1e01, %edx\n" /* line 2771 */
        "jmp .Lf16794_00017438\n"
        ".Lf16794_000175ac:\n"
        "movl $0x1e02, %edx\n" /* line 2773 */
        "jmp .Lf16794_00017438\n"
        ".Lf16794_000175b6:\n"
        "movl $0x1e03, %edx\n" /* line 2774 */
        "jmp .Lf16794_00017438\n"
        ".Lf16794_000175c0:\n"
        "movl $0x150a, %edx\n" /* line 2775 */
        "jmp .Lf16794_00017438\n"
        ".Lf16794_000175ca:\n"
        "movl $0x8507, %edx\n" /* line 2776 */
        "jmp .Lf16794_00017438\n"
        ".Lf16794_000175d4:\n"
        "movl $0x8508, %edx\n" /* line 2769 */
        "jmp .Lf16794_00017438\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_000175de:\n"
        "movl $0x1e00, %eax\n"
        "jmp .Lf16794_00017450\n"
        /* } scope */
        ".Lf16794_000175e8:\n"
        "movl $0x207, %eax\n" /* line 3023 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_000175f2:\n"
        "movl $0x205, %eax\n" /* line 3029 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_000175fc:\n"
        "movl $0x206, %eax\n" /* line 3030 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_00017606:\n"
        "movl $0x201, %eax\n" /* line 3025 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_00017610:\n"
        "movl $0x202, %eax\n" /* line 3026 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_0001761a:\n"
        "movl $0x203, %eax\n" /* line 3027 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_00017624:\n"
        "movl $0x204, %eax\n" /* line 3028 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_0001762e:\n"
        "movl $0x307, 0x3a0(%ebx)\n" /* line 3127 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001763d:\n"
        "movl $0x308, 0x3a0(%ebx)\n" /* line 3128 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001764c:\n"
        "movl $0, 0x398(%ebx)\n" /* line 3097 | this */
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_0001765b:\n"
        "movl $0x1e01, %edx\n" /* line 2771 */
        "jmp .Lf16794_000173f1\n"
        ".Lf16794_00017665:\n"
        "movl $0x1e02, %edx\n" /* line 2773 */
        "jmp .Lf16794_000173f1\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_0001766f:\n"
        "movl $0x150a, %ecx\n" /* line 2775 */
        "jmp .Lf16794_00017420\n"
        ".Lf16794_00017679:\n"
        "movl $0x8507, %ecx\n" /* line 2776 */
        "jmp .Lf16794_00017420\n"
        ".Lf16794_00017683:\n"
        "movl $0x1e00, %ecx\n" /* line 2769 */
        "jmp .Lf16794_00017420\n"
        ".Lf16794_0001768d:\n"
        "movl $0x1e01, %ecx\n" /* line 2771 */
        "jmp .Lf16794_00017420\n"
        ".Lf16794_00017697:\n"
        "movl $0x1e02, %ecx\n" /* line 2773 */
        "jmp .Lf16794_00017420\n"
        ".Lf16794_000176a1:\n"
        "movl $0x1e03, %ecx\n" /* line 2774 */
        "jmp .Lf16794_00017420\n"
        /* } scope */
        ".Lf16794_000176ab:\n"
        "movl $1, 0x394(%ebx)\n" /* line 2885 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000176ba:\n"
        "movl $0x302, 0x394(%ebx)\n" /* line 2886 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000176c9:\n"
        "movl $0x303, 0x394(%ebx)\n" /* line 2887 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000176d8:\n"
        "movl $0x304, 0x394(%ebx)\n" /* line 2888 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000176e7:\n"
        "movl $0x305, 0x394(%ebx)\n" /* line 2889 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000176f6:\n"
        "movl $0x306, 0x394(%ebx)\n" /* line 2890 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017705:\n"
        "movl $0x307, 0x394(%ebx)\n" /* line 2891 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017714:\n"
        "movl $0x308, 0x394(%ebx)\n" /* line 2892 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017723:\n"
        "movl $0x200, 0x568(%ebx)\n" /* line 3290 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_00017732:\n"
        "movl $0x205, 0x568(%ebx)\n" /* line 3295 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_00017741:\n"
        "movl $0x206, 0x568(%ebx)\n" /* line 3296 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_00017750:\n"
        "movl $0x201, 0x568(%ebx)\n" /* line 3291 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_0001775f:\n"
        "movl $0x202, 0x568(%ebx)\n" /* line 3292 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_0001776e:\n"
        "movl $0x203, 0x568(%ebx)\n" /* line 3293 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_0001777d:\n"
        "movl $0x204, 0x568(%ebx)\n" /* line 3294 | this */
        "jmp .Lf16794_0001737d\n"
        ".Lf16794_0001778c:\n"
        "movl $0, 0x39c(%ebx)\n" /* line 2907 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001779b:\n"
        "movl $1, 0x39c(%ebx)\n" /* line 2908 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000177aa:\n"
        "movl $0x200, 0x3ac(%ebx)\n" /* line 3056 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_000177b9:\n"
        "movl $0x300, 0x39c(%ebx)\n" /* line 2909 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000177c8:\n"
        "movl $0x301, 0x39c(%ebx)\n" /* line 2910 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000177d7:\n"
        "movl $0x302, 0x39c(%ebx)\n" /* line 2911 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000177e6:\n"
        "movl $0x303, 0x39c(%ebx)\n" /* line 2912 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000177f5:\n"
        "movl $0x304, 0x39c(%ebx)\n" /* line 2913 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017804:\n"
        "movl $0x305, 0x39c(%ebx)\n" /* line 2914 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017813:\n"
        "movl $0x306, 0x39c(%ebx)\n" /* line 2915 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017822:\n"
        "movl $0x308, 0x39c(%ebx)\n" /* line 2916 | this */
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_00017831:\n"
        "movl $0x8508, %esi\n" /* line 2769 | m */
        "jmp .Lf16794_000173a6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_0001783b:\n"
        "movl $0x1e00, %ecx\n"
        "jmp .Lf16794_000173be\n"
        ".Lf16794_00017845:\n"
        "movl $0x1e01, %ecx\n" /* line 2771 */
        "jmp .Lf16794_000173be\n"
        ".Lf16794_0001784f:\n"
        "movl $0x1e02, %ecx\n" /* line 2773 */
        "jmp .Lf16794_000173be\n"
        ".Lf16794_00017859:\n"
        "movl $0x1e03, %ecx\n" /* line 2774 */
        "jmp .Lf16794_000173be\n"
        ".Lf16794_00017863:\n"
        "movl $0x150a, %ecx\n" /* line 2775 */
        "jmp .Lf16794_000173be\n"
        ".Lf16794_0001786d:\n"
        "movl $0x8507, %ecx\n" /* line 2776 */
        "jmp .Lf16794_000173be\n"
        ".Lf16794_00017877:\n"
        "movl $0x8508, %ecx\n" /* line 2769 */
        "jmp .Lf16794_000173be\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017881:\n"
        "movl $0x1e00, %eax\n"
        "jmp .Lf16794_000173cc\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_0001788b:\n"
        "movl $0x8508, %ecx\n"
        "jmp .Lf16794_000173e3\n"
        ".Lf16794_00017895:\n"
        "movl $0x150a, %ecx\n" /* line 2775 */
        "jmp .Lf16794_000173e3\n"
        ".Lf16794_0001789f:\n"
        "movl $0x8507, %ecx\n" /* line 2776 */
        "jmp .Lf16794_000173e3\n"
        ".Lf16794_000178a9:\n"
        "movl $0x1e00, %ecx\n" /* line 2769 */
        "jmp .Lf16794_000173e3\n"
        ".Lf16794_000178b3:\n"
        "movl $0x1e01, %ecx\n" /* line 2771 */
        "jmp .Lf16794_000173e3\n"
        ".Lf16794_000178bd:\n"
        "movl $0x1e02, %ecx\n" /* line 2773 */
        "jmp .Lf16794_000173e3\n"
        ".Lf16794_000178c7:\n"
        "movl $0x1e03, %ecx\n" /* line 2774 */
        "jmp .Lf16794_000173e3\n"
        /* } scope */
        ".Lf16794_000178d1:\n"
        "movl $0x201, 0x3ac(%ebx)\n" /* line 3057 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_000178e0:\n"
        "movl $0x202, 0x3ac(%ebx)\n" /* line 3058 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_000178ef:\n"
        "movl $0x203, 0x3ac(%ebx)\n" /* line 3059 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_000178fe:\n"
        "movl $0x204, 0x3ac(%ebx)\n" /* line 3060 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_0001790d:\n"
        "movl $0x205, 0x3ac(%ebx)\n" /* line 3061 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_0001791c:\n"
        "movl $0x206, 0x3ac(%ebx)\n" /* line 3062 | this */
        "jmp .Lf16794_00017356\n"
        ".Lf16794_0001792b:\n"
        "movl $0x200, %eax\n" /* line 3023 */
        "jmp .Lf16794_00017467\n"
        ".Lf16794_00017935:\n"
        "movl $0, 0x394(%ebx)\n" /* line 2884 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017944:\n"
        "movl $0, 0x3a0(%ebx)\n" /* line 3119 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017953:\n"
        "movl $1, 0x3a0(%ebx)\n" /* line 3120 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017962:\n"
        "movl $0x300, 0x3a0(%ebx)\n" /* line 3121 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017971:\n"
        "movl $0x302, 0x3a0(%ebx)\n" /* line 3122 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017980:\n"
        "movl $0x303, 0x3a0(%ebx)\n" /* line 3123 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001798f:\n"
        "movl $0x304, 0x3a0(%ebx)\n" /* line 3124 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_0001799e:\n"
        "movl $0x305, 0x3a0(%ebx)\n" /* line 3125 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000179ad:\n"
        "movl $0x306, 0x3a0(%ebx)\n" /* line 3126 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000179bc:\n"
        "movl $1, 0x398(%ebx)\n" /* line 3098 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000179cb:\n"
        "movl $0x302, 0x398(%ebx)\n" /* line 3099 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000179da:\n"
        "movl $0x303, 0x398(%ebx)\n" /* line 3100 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000179e9:\n"
        "movl $0x304, 0x398(%ebx)\n" /* line 3101 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_000179f8:\n"
        "movl $0x305, 0x398(%ebx)\n" /* line 3102 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a07:\n"
        "movl $0x306, 0x398(%ebx)\n" /* line 3103 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a16:\n"
        "movl $0x307, 0x398(%ebx)\n" /* line 3104 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a25:\n"
        "movl $0x308, 0x398(%ebx)\n" /* line 3105 | this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a34:\n"
        "movl $0x8861, (%esp)\n" /* line 3538 */
        "calll glDisable\n"
        "jmp .Lf16794_000172f9\n"
        ".Lf16794_00017a45:\n"
        "movl 0x10(%ebp), %eax\n" /* line 3387 | Value */
        "movl %eax, 0x584(%ebx)\n" /* this */
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a53:\n"
        "movl $0xba1, (%esp)\n" /* line 3430 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a64:\n"
        "movl $0xb60, (%esp)\n" /* line 3201 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a75:\n"
        "movl $0xbc0, (%esp)\n" /* line 2870 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a86:\n"
        "movl $0xbe2, (%esp)\n" /* line 3080 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017a97:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 3617 */
        "cmpb $0, 0x809(%eax)\n"
        "jne .Lf16794_00017ab2\n"
        "cmpb $0, 0x80a(%eax)\n"
        "je .Lf16794_0001688a\n"
        ".Lf16794_00017ab2:\n"
        "movl $0x8006, (%esp)\n" /* line 3619 */
        "calll glBlendEquationEXT\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017ac3:\n"
        "movl $0xb71, (%esp)\n" /* line 2817 */
        "calll glEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017ad4:\n"
        "movl $0x45000000, 4(%esp)\n" /* line 3416 */
        "movl $0xb65, (%esp)\n"
        "calll glFogf\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017aed:\n"
        "movl $0xb90, (%esp)\n" /* line 3258 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf16794_00017afe:\n"
        "xorl %edi, %edi\n" /* line 3350 | i */
        "xorl %esi, %esi\n" /* m */
        ".Lf16794_00017b02:\n"
        "movl 0x608(%ebx), %edx\n" /* line 654 */
        "addl %esi, %edx\n"
        "leal 0x54(%edx), %ecx\n" /* line 179 */
        "movl -0x34(%ebp), %eax\n" /* rgba */
        "movl %eax, 0x54(%edx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "addl $1, %edi\n" /* line 3350 | i */
        "addl $0xa4, %esi\n" /* m */
        "cmpl %edi, 0x504(%ebx)\n" /* i, this */
        "ja .Lf16794_00017b02\n"
        "jmp .Lf16794_00016883\n"
        /* } scope */
        /* } scope */
        ".Lf16794_00017b3b:\n"
        "movl $0x45001000, 4(%esp)\n" /* line 3417 */
        "movl $0xb65, (%esp)\n"
        "calll glFogf\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017b54:\n"
        "movl $0xb44, (%esp)\n" /* line 3013 */
        "calll glEnable\n"
        "movl $0x901, (%esp)\n"
        "calll glFrontFace\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017b71:\n"
        "movl $0x1b01, %eax\n" /* line 2827 */
        "jmp .Lf16794_000168f3\n"
        ".Lf16794_00017b7b:\n"
        "movl $0x1d00, %edx\n" /* line 2842 */
        "jmp .Lf16794_00016ac4\n"
        ".Lf16794_00017b85:\n"
        "cmpl $1, 0x530(%ebx)\n" /* line 3449 | this */
        "je .Lf16794_00017e3a\n"
        "movl $0x1201, 4(%esp)\n" /* line 3456 */
        "movl $0x408, (%esp)\n"
        "calll glColorMaterial\n"
        "movl $1, 4(%esp)\n" /* line 3457 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017bc0:\n"
        "cmpl $1, 0x534(%ebx)\n" /* line 3491 | this */
        "je .Lf16794_00017e0c\n"
        "movl $0x1200, 4(%esp)\n" /* line 3498 */
        "movl $0x408, (%esp)\n"
        "calll glColorMaterial\n"
        "movl $1, 4(%esp)\n" /* line 3499 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017bfb:\n"
        "movl $0xb50, (%esp)\n" /* line 3382 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_00017c0c:\n"
        "movl %ecx, %eax\n" /* line 3394 */
        "shrl $0x19, %eax\n"
        "andl $1, %esi\n" /* m */
        "orl %esi, %eax\n" /* m */
        "cvtsi2ssl %eax, %xmm4\n"
        "addss %xmm4, %xmm4\n"
        "jmp .Lf16794_00016bf7\n"
        ".Lf16794_00017c23:\n"
        "shrl $1, %eax\n"
        "movl %ecx, %edx\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00016be3\n"
        ".Lf16794_00017c39:\n"
        "shrl $1, %edx\n"
        "andl $1, %eax\n"
        "orl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00016bcd\n"
        ".Lf16794_00017c4d:\n"
        "shrl $1, %edx\n"
        "andl $1, %eax\n"
        "orl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00016bb1\n"
        /* } scope */
        ".Lf16794_00017c61:\n"
        "movl $0x8037, (%esp)\n" /* line 3678 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        ".Lf16794_00017c72:\n"
        "movl %ecx, %eax\n" /* line 3343 */
        "shrl $0x19, %eax\n"
        "andl $1, %esi\n" /* m */
        "orl %esi, %eax\n" /* m */
        "cvtsi2ssl %eax, %xmm2\n"
        "addss %xmm2, %xmm2\n"
        "jmp .Lf16794_0001683a\n"
        ".Lf16794_00017c89:\n"
        "shrl $1, %eax\n"
        "movl %ecx, %edx\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00016826\n"
        ".Lf16794_00017c9f:\n"
        "shrl $1, %edx\n"
        "andl $1, %eax\n"
        "orl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00016810\n"
        ".Lf16794_00017cb3:\n"
        "shrl $1, %edx\n"
        "andl $1, %eax\n"
        "orl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_000167f4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf16794_00017cc7:\n"
        "movl %ecx, %eax\n" /* line 3211 */
        "shrl $0x19, %eax\n"
        "andl $1, %ebx\n" /* this */
        "orl %ebx, %eax\n" /* this */
        "cvtsi2ssl %eax, %xmm2\n"
        "addss %xmm2, %xmm2\n"
        "jmp .Lf16794_0001707f\n"
        ".Lf16794_00017cde:\n"
        "shrl $1, %eax\n"
        "movl %ecx, %edx\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_0001706b\n"
        ".Lf16794_00017cf4:\n"
        "shrl $1, %edx\n"
        "andl $1, %eax\n"
        "orl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00017055\n"
        ".Lf16794_00017d08:\n"
        "shrl $1, %edx\n"
        "andl $1, %eax\n"
        "orl %eax, %edx\n"
        "cvtsi2ssl %edx, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00017039\n"
        /* } scope */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf16794_00017d1c:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 211 */
        "jmp .Lf16794_00016fc4\n"
        /* } scope */
        /* } scope */
        ".Lf16794_00017d24:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 3628 */
        "cmpb $0, 0x809(%eax)\n"
        "je .Lf16794_0001688a\n"
        "xorl %eax, %eax\n" /* line 3630 */
        "cmpl $2, %ecx\n"
        "setne %al\n"
        "addl $0x800a, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glBlendEquationEXT\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017d50:\n"
        "movl $0x8037, (%esp)\n" /* line 3665 */
        "calll glDisable\n"
        "jmp .Lf16794_0001688a\n"
        /* { scope 2 */
        /* { scope 3 */
        ".Lf16794_00017d61:\n"
        "leal -0x20(%ebp), %eax\n" /* line 211 */
        "jmp .Lf16794_000170ee\n"
        /* } scope */
        /* } scope */
        ".Lf16794_00017d69:\n"
        "movl $0xb44, (%esp)\n" /* line 3014 */
        "calll glEnable\n"
        "movl $0x900, (%esp)\n"
        "calll glFrontFace\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017d86:\n"
        "movl $0x1b02, %eax\n" /* line 2825 */
        "jmp .Lf16794_000168f3\n"
        ".Lf16794_00017d90:\n"
        "movl %edx, %eax\n" /* line 3046 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf16794_00016926\n"
        ".Lf16794_00017da6:\n"
        "movl $0x1b00, %eax\n" /* line 2825 */
        "jmp .Lf16794_000168f3\n"
        ".Lf16794_00017db0:\n"
        "movl $0x1200, 4(%esp)\n" /* line 3464 */
        "movl $0x408, (%esp)\n"
        "calll glColorMaterial\n"
        "movl $1, 4(%esp)\n" /* line 3465 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017dde:\n"
        "movl $0x1201, 4(%esp)\n" /* line 3506 */
        "movl $0x408, (%esp)\n"
        "calll glColorMaterial\n"
        "movl $1, 4(%esp)\n" /* line 3507 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017e0c:\n"
        "movl $0x1602, 4(%esp)\n" /* line 3493 */
        "movl $0x408, (%esp)\n"
        "calll glColorMaterial\n"
        "movl $1, 4(%esp)\n" /* line 3494 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
        ".Lf16794_00017e3a:\n"
        "movl $0x1602, 4(%esp)\n" /* line 3451 */
        "movl $0x408, (%esp)\n"
        "calll glColorMaterial\n"
        "movl $1, 4(%esp)\n" /* line 3452 */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetColorMaterialEnable\n"
        "jmp .Lf16794_0001688a\n"
    );
}

/* line 4755 */
__attribute__((naked))
long unsigned int COpenGL_SetTexCombinerAlpha3(const COpenGL * _this, UINT32 Unit, GLenum AlphaOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLenum Source2, GLenum Operand2, float Scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4755 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* AlphaOp */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %ebx\n"
        "cmpl %edi, 0x8c(%ebx)\n" /* line 4759 | AlphaOp */
        "je .Lf17e68_00017ebb\n"
        "movl %esi, 4(%esp)\n" /* line 4761 | Unit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %edi, 8(%esp)\n" /* line 184 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl %edi, 0x8c(%ebx)\n"
        ".Lf17e68_00017ebb:\n"
        "movss 0x2c(%ebp), %xmm0\n" /* line 4764 | Scale */
        "ucomiss 0xac(%ebx), %xmm0\n"
        "jp .Lf17e68_0001804f\n"
        "jne .Lf17e68_0001804f\n"
        ".Lf17e68_00017ed3:\n"
        "movl 0x24(%ebp), %eax\n" /* line 4770 | Source2 */
        "cmpl %eax, 0xa0(%ebx)\n"
        "je .Lf17e68_00017f11\n"
        "movl %esi, 4(%esp)\n" /* line 4772 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x24(%ebp), %eax\n" /* line 189 | Source2 */
        "movl %eax, 8(%esp)\n"
        "movl $0x858a, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x24(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0xa0(%ebx)\n"
        ".Lf17e68_00017f11:\n"
        "movl 0x28(%ebp), %eax\n" /* line 4775 | Operand2 */
        "cmpl %eax, 0xa4(%ebx)\n"
        "je .Lf17e68_00017f4f\n"
        "movl %esi, 4(%esp)\n" /* line 4777 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x28(%ebp), %eax\n" /* line 190 | Operand2 */
        "movl %eax, 8(%esp)\n"
        "movl $0x859a, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x28(%ebp), %eax\n" /* Operand2 */
        "movl %eax, 0xa4(%ebx)\n"
        ".Lf17e68_00017f4f:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 4781 | Source1 */
        "cmpl %eax, 0x98(%ebx)\n"
        "je .Lf17e68_00017f8d\n"
        "movl %esi, 4(%esp)\n" /* line 4783 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x1c(%ebp), %eax\n" /* line 187 | Source1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8589, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x1c(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0x98(%ebx)\n"
        ".Lf17e68_00017f8d:\n"
        "movl 0x20(%ebp), %eax\n" /* line 4786 | Operand1 */
        "cmpl %eax, 0x9c(%ebx)\n"
        "je .Lf17e68_00017fcb\n"
        "movl %esi, 4(%esp)\n" /* line 4788 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x20(%ebp), %eax\n" /* line 188 | Operand1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8599, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x20(%ebp), %eax\n" /* Operand1 */
        "movl %eax, 0x9c(%ebx)\n"
        ".Lf17e68_00017fcb:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4792 | Source0 */
        "cmpl %eax, 0x90(%ebx)\n"
        "je .Lf17e68_00018009\n"
        "movl %esi, 4(%esp)\n" /* line 4794 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x14(%ebp), %eax\n" /* line 185 | Source0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x14(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x90(%ebx)\n"
        ".Lf17e68_00018009:\n"
        "movl 0x18(%ebp), %eax\n" /* line 4797 | Operand0 */
        "cmpl %eax, 0x94(%ebx)\n"
        "je .Lf17e68_00018047\n"
        "movl %esi, 4(%esp)\n" /* line 4799 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x18(%ebp), %eax\n" /* line 186 | Operand0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x18(%ebp), %eax\n" /* Operand0 */
        "movl %eax, 0x94(%ebx)\n"
        ".Lf17e68_00018047:\n"
        "addl $0x1c, %esp\n" /* line 4802 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf17e68_0001804f:\n"
        "movl %esi, 4(%esp)\n" /* line 4766 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss 0x2c(%ebp), %xmm0\n" /* line 191 | Scale */
        "movss %xmm0, 8(%esp)\n"
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movss 0x2c(%ebp), %xmm0\n" /* Scale */
        "movss %xmm0, 0xac(%ebx)\n"
        "jmp .Lf17e68_00017ed3\n"
    );
}

/* line 4608 */
__attribute__((naked))
long unsigned int COpenGL_SetTexCombinerRGB3(const COpenGL * _this, UINT32 Unit, GLenum ColorOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLenum Source2, GLenum Operand2, GLfloat Scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4608 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* ColorOp */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %ebx\n"
        "cmpl %edi, 0x70(%ebx)\n" /* line 4612 | ColorOp */
        "je .Lf18090_000180dd\n"
        "movl %esi, 4(%esp)\n" /* line 4614 | Unit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %edi, 8(%esp)\n" /* line 174 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl %edi, 0x70(%ebx)\n"
        ".Lf18090_000180dd:\n"
        "movss 0x2c(%ebp), %xmm0\n" /* line 4617 | Scale */
        "ucomiss 0xa8(%ebx), %xmm0\n"
        "jp .Lf18090_0001825f\n"
        "jne .Lf18090_0001825f\n"
        ".Lf18090_000180f5:\n"
        "movl 0x24(%ebp), %eax\n" /* line 4623 | Source2 */
        "cmpl %eax, 0x84(%ebx)\n"
        "je .Lf18090_00018133\n"
        "movl %esi, 4(%esp)\n" /* line 4625 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x24(%ebp), %eax\n" /* line 180 | Source2 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8582, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x24(%ebp), %eax\n" /* Source2 */
        "movl %eax, 0x84(%ebx)\n"
        ".Lf18090_00018133:\n"
        "movl 0x28(%ebp), %eax\n" /* line 4628 | Operand2 */
        "cmpl %eax, 0x88(%ebx)\n"
        "je .Lf18090_00018171\n"
        "movl %esi, 4(%esp)\n" /* line 4630 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x28(%ebp), %eax\n" /* line 181 | Operand2 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8592, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x28(%ebp), %eax\n" /* Operand2 */
        "movl %eax, 0x88(%ebx)\n"
        ".Lf18090_00018171:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 4634 | Source1 */
        "cmpl %eax, 0x7c(%ebx)\n"
        "je .Lf18090_000181a9\n"
        "movl %esi, 4(%esp)\n" /* line 4636 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x1c(%ebp), %eax\n" /* line 178 | Source1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8581, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x1c(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0x7c(%ebx)\n"
        ".Lf18090_000181a9:\n"
        "movl 0x20(%ebp), %eax\n" /* line 4639 | Operand1 */
        "cmpl %eax, 0x80(%ebx)\n"
        "je .Lf18090_000181e7\n"
        "movl %esi, 4(%esp)\n" /* line 4641 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x20(%ebp), %eax\n" /* line 179 | Operand1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8591, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x20(%ebp), %eax\n" /* Operand1 */
        "movl %eax, 0x80(%ebx)\n"
        ".Lf18090_000181e7:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4645 | Source0 */
        "cmpl %eax, 0x74(%ebx)\n"
        "je .Lf18090_0001821f\n"
        "movl %esi, 4(%esp)\n" /* line 4647 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x14(%ebp), %eax\n" /* line 176 | Source0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x14(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x74(%ebx)\n"
        ".Lf18090_0001821f:\n"
        "movl 0x18(%ebp), %eax\n" /* line 4650 | Operand0 */
        "cmpl %eax, 0x78(%ebx)\n"
        "je .Lf18090_00018257\n"
        "movl %esi, 4(%esp)\n" /* line 4652 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x18(%ebp), %eax\n" /* line 177 | Operand0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x18(%ebp), %eax\n" /* Operand0 */
        "movl %eax, 0x78(%ebx)\n"
        ".Lf18090_00018257:\n"
        "addl $0x1c, %esp\n" /* line 4655 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf18090_0001825f:\n"
        "movl %esi, 4(%esp)\n" /* line 4619 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss 0x2c(%ebp), %xmm0\n" /* line 182 | Scale */
        "movss %xmm0, 8(%esp)\n"
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movss 0x2c(%ebp), %xmm0\n" /* Scale */
        "movss %xmm0, 0xa8(%ebx)\n"
        "jmp .Lf18090_000180f5\n"
    );
}

/* line 2197 */
__attribute__((naked))
long unsigned int CDirect3DDevice_EndPixelOneToOneState(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2197 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, -0x1c(%ebp)\n" /* this */
        /* { scope 1 */
        "movl 0x18(%eax), %edi\n" /* line 2201 */
        "testl %edi, %edi\n"
        "setne %bl\n" /* RenderTargetHasDepthStencil */
        "movl 0x544(%eax), %eax\n" /* line 2204 */
        "testl %eax, %eax\n"
        "je .Lf182a0_000182c9\n"
        "testb %bl, %bl\n" /* RenderTargetHasDepthStencil */
        "jne .Lf182a0_00018567\n"
        ".Lf182a0_000182c9:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2209 | this */
        "movl 0x590(%eax), %edx\n"
        "cmpl $0xf, %edx\n"
        "je .Lf182a0_000184c7\n"
        "movl %edx, %eax\n" /* line 2216 */
        "shrl $3, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $2, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %eax\n"
        "movl %eax, 4(%esp)\n"
        "andl $1, %edx\n"
        "movl %edx, (%esp)\n"
        "calll glColorMask\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf182a0_0001830c:\n"
        "movl 0x574(%edx), %eax\n" /* line 2220 */
        "testl %eax, %eax\n"
        "je .Lf182a0_00018321\n"
        "testb %bl, %bl\n" /* RenderTargetHasDepthStencil */
        "jne .Lf182a0_00018577\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf182a0_00018321:\n"
        "movl 0x540(%edx), %eax\n" /* line 2225 */
        "cmpl $8, %eax\n"
        "je .Lf182a0_00018560\n"
        /* { scope 2 */
        "jbe .Lf182a0_0001849c\n" /* line 2228 */
        ".Lf182a0_00018336:\n"
        "xorl %eax, %eax\n"
        ".Lf182a0_00018338:\n"
        "movl %eax, (%esp)\n" /* line 2240 */
        "calll glDepthFunc\n"
        "movl -0x1c(%ebp), %eax\n" /* this */
        /* } scope */
        ".Lf182a0_00018343:\n"
        "movl 0x580(%eax), %esi\n" /* line 2243 */
        "testl %esi, %esi\n"
        "jne .Lf182a0_000184e1\n"
        "movl %eax, %edx\n"
        "movl 0x584(%edx), %ecx\n" /* line 2247 */
        "testl %ecx, %ecx\n"
        "jne .Lf182a0_000184fe\n"
        ".Lf182a0_00018361:\n"
        "movl %edx, %eax\n"
        "movl 0x57c(%eax), %edx\n" /* line 2251 */
        "testl %edx, %edx\n"
        "jne .Lf182a0_0001851b\n"
        ".Lf182a0_00018371:\n"
        "movl %eax, %edx\n"
        "movl 0x548(%edx), %edi\n" /* line 2255 */
        "testl %edi, %edi\n"
        "jne .Lf182a0_00018538\n"
        ".Lf182a0_00018381:\n"
        "movl %edx, %eax\n"
        ".Lf182a0_00018383:\n"
        "movl 0x53c(%eax), %esi\n" /* line 2260 */
        "testl %esi, %esi\n"
        "je .Lf182a0_000184a3\n"
        "testb %bl, %bl\n" /* RenderTargetHasDepthStencil */
        "jne .Lf182a0_0001858c\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        ".Lf182a0_0001839c:\n"
        "movl 0x50c(%edx), %ecx\n" /* line 2264 */
        "testl %ecx, %ecx\n"
        "jne .Lf182a0_000184b3\n"
        ".Lf182a0_000183aa:\n"
        "movl %edx, %eax\n"
        /* { scope 2 */
        ".Lf182a0_000183ac:\n"
        "movl 0x504(%eax), %esi\n" /* line 2272 | i */
        "subl $1, %esi\n" /* i */
        "js .Lf182a0_00018458\n"
        "leal (%esi, %esi, 8), %eax\n" /* line 2197 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %edi\n"
        "jmp .Lf182a0_000183ec\n"
        ".Lf182a0_000183cc:\n"
        "cmpb $0, 2(%eax, %ebx)\n" /* line 2281 */
        "jne .Lf182a0_0001841e\n"
        ".Lf182a0_000183d3:\n"
        "cmpb $0, 3(%ebx, %eax)\n" /* line 2286 | RenderTargetHasDepthStencil */
        "jne .Lf182a0_00018437\n"
        ".Lf182a0_000183da:\n"
        "subl $1, %esi\n" /* line 2272 | i */
        "subl $0x130, %ebx\n" /* RenderTargetHasDepthStencil */
        "movl $0xffffffff, %edx\n"
        "cmpl %esi, %edx\n" /* i */
        "je .Lf182a0_00018455\n"
        ".Lf182a0_000183ec:\n"
        "movl %esi, 4(%esp)\n" /* line 2274 | i */
        "movl %edi, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x65c(%edi), %eax\n" /* line 343 */
        "cmpb $0, 1(%ebx, %eax)\n" /* line 2276 | RenderTargetHasDepthStencil */
        "je .Lf182a0_000183cc\n"
        "movl $0xde1, (%esp)\n" /* line 2278 */
        "calll glEnable\n"
        "movl 0x65c(%edi), %eax\n"
        "cmpb $0, 2(%eax, %ebx)\n" /* line 2281 */
        "je .Lf182a0_000183d3\n"
        ".Lf182a0_0001841e:\n"
        "movl $0x806f, (%esp)\n" /* line 2283 */
        "calll glEnable\n"
        "movl 0x65c(%edi), %eax\n"
        "cmpb $0, 3(%ebx, %eax)\n" /* line 2286 | RenderTargetHasDepthStencil */
        "je .Lf182a0_000183da\n"
        ".Lf182a0_00018437:\n"
        "movl $0x8513, (%esp)\n" /* line 2288 */
        "calll glEnable\n"
        "subl $1, %esi\n" /* line 2272 | i */
        "subl $0x130, %ebx\n" /* RenderTargetHasDepthStencil */
        "movl $0xffffffff, %edx\n"
        "cmpl %esi, %edx\n" /* i */
        "jne .Lf182a0_000183ec\n"
        ".Lf182a0_00018455:\n"
        "movl -0x1c(%ebp), %eax\n" /* this */
        /* } scope */
        ".Lf182a0_00018458:\n"
        "movl 0x554(%eax), %edx\n" /* line 2291 */
        "testl %edx, %edx\n"
        "jne .Lf182a0_0001854c\n"
        "movl %eax, %edx\n"
        ".Lf182a0_00018468:\n"
        "cmpl $1, 0x58c(%edx)\n" /* line 2295 */
        "je .Lf182a0_000184ce\n"
        "movl $0x1d01, (%esp)\n" /* line 2297 */
        "calll glShadeModel\n"
        "movl -0x1c(%ebp), %eax\n" /* this */
        "cmpl $1, 0x538(%eax)\n" /* line 2300 */
        "je .Lf182a0_000184d9\n"
        ".Lf182a0_00018489:\n"
        "movl $0xb44, 8(%ebp)\n" /* line 2302 | this */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 2305 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp glEnable\n" /* line 2302 */
        /* { scope 2 */
        ".Lf182a0_0001849c:\n"
        "jmpl *.Ljt_2ee790(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee790:\n"
        ".long .Lf182a0_00018336\n"
        ".long .Lf182a0_000185a0\n"
        ".popsection\n"
        ".Lf182a0_000184a3:\n"
        "movl %eax, %edx\n"
        /* } scope */
        "movl 0x50c(%edx), %ecx\n" /* line 2264 */
        "testl %ecx, %ecx\n"
        "je .Lf182a0_000183aa\n"
        ".Lf182a0_000184b3:\n"
        "movl $0xbc0, (%esp)\n" /* line 2266 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %eax\n" /* this */
        "jmp .Lf182a0_000183ac\n"
        ".Lf182a0_000184c7:\n"
        "movl %eax, %edx\n"
        "jmp .Lf182a0_0001830c\n"
        ".Lf182a0_000184ce:\n"
        "movl %edx, %eax\n"
        "cmpl $1, 0x538(%eax)\n" /* line 2300 */
        "jne .Lf182a0_00018489\n"
        /* } scope */
        ".Lf182a0_000184d9:\n"
        "addl $0x2c, %esp\n" /* line 2305 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf182a0_000184e1:\n"
        "movl $0xb60, (%esp)\n" /* line 2245 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "movl 0x584(%edx), %ecx\n" /* line 2247 */
        "testl %ecx, %ecx\n"
        "je .Lf182a0_00018361\n"
        ".Lf182a0_000184fe:\n"
        "movl $0xb50, (%esp)\n" /* line 2249 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %eax\n" /* this */
        "movl 0x57c(%eax), %edx\n" /* line 2251 */
        "testl %edx, %edx\n"
        "je .Lf182a0_00018371\n"
        ".Lf182a0_0001851b:\n"
        "movl $0xbd0, (%esp)\n" /* line 2253 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "movl 0x548(%edx), %edi\n" /* line 2255 */
        "testl %edi, %edi\n"
        "je .Lf182a0_00018381\n"
        ".Lf182a0_00018538:\n"
        "movl $0xbe2, (%esp)\n" /* line 2257 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %eax\n" /* this */
        "jmp .Lf182a0_00018383\n"
        ".Lf182a0_0001854c:\n"
        "movl $0xb90, (%esp)\n" /* line 2293 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "jmp .Lf182a0_00018468\n"
        ".Lf182a0_00018560:\n"
        "movl %edx, %eax\n"
        "jmp .Lf182a0_00018343\n"
        ".Lf182a0_00018567:\n"
        "movzbl %al, %eax\n" /* line 2206 */
        "movl %eax, (%esp)\n"
        "calll glDepthMask\n"
        "jmp .Lf182a0_000182c9\n"
        ".Lf182a0_00018577:\n"
        "andl $0xff, %eax\n" /* line 2222 */
        "movl %eax, (%esp)\n"
        "calll glStencilMask\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "jmp .Lf182a0_00018321\n"
        ".Lf182a0_0001858c:\n"
        "movl $0xb71, (%esp)\n" /* line 2262 */
        "calll glEnable\n"
        "movl -0x1c(%ebp), %edx\n" /* this */
        "jmp .Lf182a0_0001839c\n"
        /* { scope 2 */
        ".Lf182a0_000185a0:\n"
        "movl $0x200, %eax\n" /* line 2228 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x205, %eax\n" /* line 2234 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x204, %eax\n" /* line 2233 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x203, %eax\n" /* line 2232 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x202, %eax\n" /* line 2231 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x207, %eax\n" /* line 2228 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x206, %eax\n" /* line 2235 */
        "jmp .Lf182a0_00018338\n"
        "movl $0x201, %eax\n" /* line 2230 */
        "jmp .Lf182a0_00018338\n"
    );
}

static UINT32 d3d_u32(const void *base, unsigned int offset)
{
    return *(const UINT32 *)((const char *)base + offset);
}

static void *d3d_ptr(const void *base, unsigned int offset)
{
    return *(void * const *)((const char *)base + offset);
}

typedef void (*PFNGLWINDOWPOS2IPROC)(GLint x, GLint y);
typedef void (*PFNGLGENFRAMEBUFFERSPROC)(GLsizei n, GLuint *framebuffers);
typedef void (*PFNGLDELETEFRAMEBUFFERSPROC)(GLsizei n, const GLuint *framebuffers);
typedef void (*PFNGLBINDFRAMEBUFFERPROC)(GLenum target, GLuint framebuffer);
typedef void (*PFNGLFRAMEBUFFERTEXTURE2DPROC)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef void (*PFNGLBLITFRAMEBUFFERPROC)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef GLenum (*PFNGLCHECKFRAMEBUFFERSTATUSPROC)(GLenum target);

static PFNGLGENFRAMEBUFFERSPROC    s_glGenFramebuffers;
static PFNGLDELETEFRAMEBUFFERSPROC s_glDeleteFramebuffers;
static PFNGLBINDFRAMEBUFFERPROC    s_glBindFramebuffer;
static PFNGLFRAMEBUFFERTEXTURE2DPROC s_glFramebufferTexture2D;
static PFNGLBLITFRAMEBUFFERPROC    s_glBlitFramebuffer;

static int d3d_load_fbo_procs(void)
{
    static int loaded = 0;
    if (!loaded) {
        loaded = 1;
        s_glGenFramebuffers    = (PFNGLGENFRAMEBUFFERSPROC)SDL_GL_GetProcAddress("glGenFramebuffers");
        s_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)SDL_GL_GetProcAddress("glDeleteFramebuffers");
        s_glBindFramebuffer    = (PFNGLBINDFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBindFramebuffer");
        s_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)SDL_GL_GetProcAddress("glFramebufferTexture2D");
        s_glBlitFramebuffer    = (PFNGLBLITFRAMEBUFFERPROC)SDL_GL_GetProcAddress("glBlitFramebuffer");
    }
    return s_glGenFramebuffers && s_glDeleteFramebuffers &&
           s_glBindFramebuffer && s_glFramebufferTexture2D && s_glBlitFramebuffer;
}

static PFNGLWINDOWPOS2IPROC d3d_get_window_pos2i(void)
{
    static PFNGLWINDOWPOS2IPROC s_windowPos2i;
    static int s_windowPosLookedUp;

    if (!s_windowPosLookedUp) {
        s_windowPosLookedUp = 1;
        s_windowPos2i = (PFNGLWINDOWPOS2IPROC)SDL_GL_GetProcAddress("glWindowPos2i");
        if (s_windowPos2i == NULL) {
            s_windowPos2i = (PFNGLWINDOWPOS2IPROC)SDL_GL_GetProcAddress("glWindowPos2iARB");
        }
        if (s_windowPos2i == NULL) {
            s_windowPos2i = (PFNGLWINDOWPOS2IPROC)SDL_GL_GetProcAddress("glWindowPos2iMESA");
        }
    }

    return s_windowPos2i;
}

static GLuint d3d_surface_texture_name(const void *surface)
{
    void *textureInfo;
    GLuint *textureNamePtr;

    textureInfo = d3d_ptr(surface, 0x28);
    if (textureInfo == NULL) {
        return 0;
    }

    textureNamePtr = *(GLuint **)((char *)textureInfo + 4);
    if (textureNamePtr == NULL) {
        return 0;
    }

    return *textureNamePtr;
}

static GLenum d3d_surface_target(const void *surface)
{
    if (d3d_u32(surface, 0x8) == 1) {
        return d3d_u32(surface, 0xc);
    }

    return 0xde1;
}

static HRESULT CDirect3DDevice_StretchRectToBackBuffer(
    const CDirect3DDevice * _this,
    IDirect3DSurface9 *pSourceSurface,
    const RECT *pSourceRect,
    IDirect3DSurface9 *pDestSurface,
    const RECT *pDestRect,
    D3DTEXTUREFILTERTYPE Filter)
{
    RECT sourceRect;
    RECT destRect;
    GLenum sourceTarget;
    GLuint textureName;
    UINT32 sourceWidth;
    UINT32 sourceHeight;
    UINT32 destWidth;
    UINT32 destHeight;
    const void *surfaceMemory;
    GLenum surfaceFormat;
    GLenum surfaceType;
    GLint textureStageCount;
    GLint stageIndex;
    GLint filterMode;
    GLfloat savedTextureMatrices[16][16];
    GLfloat whiteRgba[4];
    GLfloat texLeft;
    GLfloat texTop;
    GLfloat texRight;
    GLfloat texBottom;
    GLfloat ndcLeft;
    GLfloat ndcTop;
    GLfloat ndcRight;
    GLfloat ndcBottom;
    PFNGLWINDOWPOS2IPROC windowPos2i;

    sourceTarget = d3d_surface_target(pSourceSurface);
    textureName = d3d_surface_texture_name(pSourceSurface);
    if (textureName == 0) {
        return 0;
    }

    sourceWidth = d3d_u32(pSourceSurface, 0x14);
    sourceHeight = d3d_u32(pSourceSurface, 0x18);
    destWidth = d3d_u32(pDestSurface, 0x14);
    destHeight = d3d_u32(pDestSurface, 0x18);
    surfaceMemory = d3d_ptr(pSourceSurface, 0x20);
    surfaceFormat = d3d_u32(pSourceSurface, 0x34);
    surfaceType = d3d_u32(pSourceSurface, 0x38);
    if (sourceWidth == 0 || sourceHeight == 0 || destWidth == 0 || destHeight == 0) {
        return 0;
    }

    if (pSourceRect == NULL) {
        sourceRect.left = 0;
        sourceRect.top = 0;
        sourceRect.right = sourceWidth;
        sourceRect.bottom = sourceHeight;
        pSourceRect = &sourceRect;
    }

    if (pDestRect == NULL) {
        destRect.left = 0;
        destRect.top = 0;
        destRect.right = destWidth;
        destRect.bottom = destHeight;
        pDestRect = &destRect;
    }

    filterMode = 0x2601;
    if (Filter == D3DTEXF_POINT) {
        filterMode = 0x2600;
    }

    whiteRgba[0] = 1.0f;
    whiteRgba[1] = 1.0f;
    whiteRgba[2] = 1.0f;
    whiteRgba[3] = 1.0f;

    glPushAttrib(0xfffff);
    glPushClientAttrib(0xffffffff);

    glDisable(0x8620);
    if (MacDisplay_GetCardType() == 2) {
        glDisable(0x86de);
        glDisable(0x8522);
    } else if (MacDisplay_GetCardType() == 1) {
        glDisable(0x8200);
    }
    if (MacOpenGLUtils_GetPCPixelShaderVersion() > 0xffff01ff) {
        glDisable(0x8804);
    }

    CDirect3DDevice_StartPixelOneToOneState(_this);

    glDrawBuffer(0x405);
    glReadBuffer(0x405);

    /* Use FBO blit to copy GPU render target directly — no CPU re-upload needed */
    if (d3d_load_fbo_procs()) {
        GLuint fbo;
        GLenum fboStatus;
        /* src rect in GL texture coords (Y=0 at bottom of texture, opposite of D3D) */
        GLint srcY0 = (GLint)sourceHeight - pSourceRect->bottom;
        GLint srcY1 = (GLint)sourceHeight - pSourceRect->top;
        /* dst rect in window coords (Y=0 at bottom) */
        GLint dstY0 = (GLint)destHeight - pDestRect->bottom;
        GLint dstY1 = (GLint)destHeight - pDestRect->top;
        GLenum blitFilter = (Filter == 1 /*D3DTEXF_LINEAR*/) ? 0x2601 /*GL_LINEAR*/ : 0x2600 /*GL_NEAREST*/;

        static int diag_count = 0;
        if (diag_count < 3) {
            fprintf(stderr, "[StretchRect#%d] tex=%u target=0x%x src=(%d,%d,%d,%d) srcH=%u dst=(%d,%d,%d,%d) dstH=%u srcGL=(%d,%d,%d,%d) dstGL=(%d,%d,%d,%d)\n",
                diag_count, textureName, sourceTarget,
                pSourceRect->left, pSourceRect->top, pSourceRect->right, pSourceRect->bottom, sourceHeight,
                pDestRect->left,   pDestRect->top,   pDestRect->right,   pDestRect->bottom,   destHeight,
                pSourceRect->left, srcY0, pSourceRect->right, srcY1,
                pDestRect->left,   dstY0, pDestRect->right,   dstY1);
        }

        s_glGenFramebuffers(1, &fbo);
        s_glBindFramebuffer(0x8ca8 /*GL_READ_FRAMEBUFFER*/, fbo);
        s_glFramebufferTexture2D(0x8ca8, 0x8ce0 /*GL_COLOR_ATTACHMENT0*/, sourceTarget, textureName, 0);
        fboStatus = ((PFNGLCHECKFRAMEBUFFERSTATUSPROC)SDL_GL_GetProcAddress("glCheckFramebufferStatus"))(0x8ca8);
        if (diag_count < 3) {
            unsigned char spx[4] = {0};
            glReadBuffer(0x8ce0 /*GL_COLOR_ATTACHMENT0*/);
            glReadPixels((pSourceRect->left + pSourceRect->right)/2,
                         (srcY0 + srcY1)/2, 1, 1, 0x1908, 0x1401, spx);
            fprintf(stderr, "[StretchRect#%d] FBO status=0x%x src_center_px=(%d,%d,%d,%d) err=0x%x\n",
                    diag_count, fboStatus, spx[0],spx[1],spx[2],spx[3], glGetError());
            diag_count++;
        }
        if (fboStatus != 0x8cd5 /*GL_FRAMEBUFFER_COMPLETE*/) {
            s_glBindFramebuffer(0x8d40 /*GL_FRAMEBUFFER*/, 0);
            s_glDeleteFramebuffers(1, &fbo);
            goto texture_path;
        }
        s_glBindFramebuffer(0x8ca9 /*GL_DRAW_FRAMEBUFFER*/, 0);
        glDisable(0xc11); /* GL_SCISSOR_TEST */
        s_glBlitFramebuffer(
            pSourceRect->left, srcY0, pSourceRect->right, srcY1,
            pDestRect->left,   dstY0, pDestRect->right,   dstY1,
            0x4000 /*GL_COLOR_BUFFER_BIT*/, blitFilter);
        s_glBindFramebuffer(0x8d40 /*GL_FRAMEBUFFER*/, 0);
        s_glDeleteFramebuffers(1, &fbo);

        glPopClientAttrib();
        glPopAttrib();
        return 0;
    }
    texture_path:;

    windowPos2i = d3d_get_window_pos2i(); (void)windowPos2i;

    glActiveTextureARB(0x84c0);
    glClientActiveTextureARB(0x84c0);
    glBindTexture(sourceTarget, textureName);
    /* Do NOT call UpdateOpenGLSurfaceObject here: the source is a GPU render target,
       its texture already contains the rendered frame. Re-uploading from the CPU
       shadow buffer (offset 0x20) would overwrite the rendered content. */
    glTexParameteri(sourceTarget, 0x2801, filterMode);
    glTexParameteri(sourceTarget, 0x2800, filterMode);
    glTexParameteri(sourceTarget, 0x2802, 0x2900);
    glTexParameteri(sourceTarget, 0x2803, 0x2900);
    glTexParameteri(sourceTarget, 0x813d, 0);

    textureStageCount = (GLint)d3d_u32(_this, 0x504);
    if (textureStageCount > 16) {
        textureStageCount = 16;
    }

    glMatrixMode(0x1702);
    for (stageIndex = textureStageCount - 1; stageIndex >= 0; --stageIndex) {
        glActiveTextureARB(0x84c0 + stageIndex);
        glGetFloatv(0xba8, savedTextureMatrices[stageIndex]);
        glLoadIdentity();
        glDisable(0xde0);
        glDisable(0xc60);
        glDisable(0xc61);
        glDisable(0xc62);
        glDisable(0xc63);
        if (stageIndex == 0) {
            glEnable(0xde1);
            glDisable(0x806f);
            glDisable(0x8513);
            glDisable(0x84f5);
            glTexEnvfv(0x2300, 0x2201, whiteRgba);
            glTexEnvi(0x2300, 0x2200, 0x8570);
            glTexEnvi(0x2300, 0x8571, 0x2100);
            glTexEnvi(0x2300, 0x8580, 0x1702);
            glTexEnvi(0x2300, 0x8590, 0x300);
            glTexEnvi(0x2300, 0x8581, 0x8578);
            glTexEnvi(0x2300, 0x8591, 0x300);
            glTexEnvi(0x2300, 0x8582, 0x8576);
            glTexEnvi(0x2300, 0x8592, 0x302);
            glTexEnvf(0x2300, 0x8573, 1.0f);
            glTexEnvi(0x2300, 0x8572, 0x2100);
            glTexEnvi(0x2300, 0x8588, 0x1702);
            glTexEnvi(0x2300, 0x8598, 0x302);
            glTexEnvi(0x2300, 0x8589, 0x8578);
            glTexEnvi(0x2300, 0x8599, 0x302);
            glTexEnvi(0x2300, 0x858a, 0x8576);
            glTexEnvi(0x2300, 0x859a, 0x302);
            glTexEnvf(0x2300, 0xd1c, 1.0f);
        } else {
            glDisable(0xde0);
            glDisable(0xde1);
            glDisable(0x806f);
            glDisable(0x8513);
            glDisable(0x84f5);
        }
    }

    texLeft = (GLfloat)pSourceRect->left / (GLfloat)sourceWidth;
    texTop = (GLfloat)pSourceRect->top / (GLfloat)sourceHeight;
    texRight = (GLfloat)pSourceRect->right / (GLfloat)sourceWidth;
    texBottom = (GLfloat)pSourceRect->bottom / (GLfloat)sourceHeight;

    ndcLeft = ((2.0f * (GLfloat)pDestRect->left) / (GLfloat)destWidth) - 1.0f;
    ndcTop = 1.0f - ((2.0f * (GLfloat)pDestRect->top) / (GLfloat)destHeight);
    ndcRight = ((2.0f * (GLfloat)pDestRect->right) / (GLfloat)destWidth) - 1.0f;
    ndcBottom = 1.0f - ((2.0f * (GLfloat)pDestRect->bottom) / (GLfloat)destHeight);

    glMatrixMode(0x1701);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(0x1700);
    glPushMatrix();
    glLoadIdentity();

    glBegin(7);
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
    glTexCoord2f(texLeft, texTop);
    glVertex2f(ndcLeft, ndcTop);
    glTexCoord2f(texRight, texTop);
    glVertex2f(ndcRight, ndcTop);
    glTexCoord2f(texRight, texBottom);
    glVertex2f(ndcRight, ndcBottom);
    glTexCoord2f(texLeft, texBottom);
    glVertex2f(ndcLeft, ndcBottom);
    glEnd();

    glMatrixMode(0x1700);
    glPopMatrix();
    glMatrixMode(0x1701);
    glPopMatrix();

    glMatrixMode(0x1702);
    for (stageIndex = 0; stageIndex < textureStageCount; ++stageIndex) {
        glActiveTextureARB(0x84c0 + stageIndex);
        glLoadMatrixf(savedTextureMatrices[stageIndex]);
    }
    glActiveTextureARB(0x84c0);
    glClientActiveTextureARB(0x84c0);

    glPopClientAttrib();
    glPopAttrib();
    return 0;
}

/* line 1394 */
__attribute__((naked))
static HRESULT CDirect3DDevice_StretchRect_impl(const CDirect3DDevice * _this, IDirect3DSurface9 *pSourceSurface, const RECT *pSourceRect, IDirect3DSurface9 *pDestSurface, const RECT *pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1394 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x29c, %esp\n"
        "movl 0xc(%ebp), %ebx\n" /* pSourceSurface */
        "movl 8(%ebp), %edx\n" /* line 1411 | this */
        "movl 0x1c(%edx), %eax\n"
        "cmpl %eax, %ebx\n" /* pSourceSurface */
        "je .Lf185f0_00018cc2\n"
        /* { scope 1: SurfacePO2Height, Matrices, NullTexID, AuxWidth, ... */
        "cmpl %eax, 0x14(%ebp)\n" /* line 1671 | pDestSurface */
        "sete -0x269(%ebp)\n" /* DestIsBackbuffer */
        "movl $0xfffff, (%esp)\n" /* line 1675 */
        "calll glPushAttrib\n"
        "movl $0xffffffff, (%esp)\n" /* line 1676 */
        "calll glPushClientAttrib\n"
        "movl $0x8620, (%esp)\n" /* line 1683 */
        "calll glDisable\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 1684 */
        "je .Lf185f0_00018c55\n"
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 1689 */
        "je .Lf185f0_00018cb1\n"
        ".Lf185f0_00018657:\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 1693 */
        "cmpl $0xffff01ff, %eax\n"
        "ja .Lf185f0_00018ae2\n"
        ".Lf185f0_00018667:\n"
        "movl 8(%ebp), %edx\n" /* line 1698 | this */
        "movl %edx, (%esp)\n"
        "calll CDirect3DDevice_StartPixelOneToOneState\n"
        "cmpb $1, -0x269(%ebp)\n" /* line 1700 | DestIsBackbuffer */
        "sbbl %eax, %eax\n"
        "andl $4, %eax\n"
        "addl $0x405, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glDrawBuffer\n"
        "cmpb $1, -0x269(%ebp)\n" /* line 1701 | DestIsBackbuffer */
        "sbbl %eax, %eax\n"
        "andl $4, %eax\n"
        "addl $0x405, %eax\n"
        "movl %eax, (%esp)\n"
        "calll glReadBuffer\n"
        "movl 0x14(%ebp), %eax\n" /* line 1704 | pDestSurface */
        "movl (%eax), %edx\n"
        "leal -0x40(%ebp), %eax\n" /* Dst */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* pDestSurface */
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl (%ebx), %edx\n" /* line 1705 | pDstSurface */
        "leal -0x60(%ebp), %eax\n" /* Src */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pDstSurface */
        "calll *0x30(%edx)\n"
        "movl $0x84c0, (%esp)\n" /* line 1707 */
        "calll glActiveTextureARB\n"
        "movl 0x28(%ebx), %eax\n" /* line 1709 | pDstSurface */
        "movl 4(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0, 4(%esp)\n" /* line 1710 */
        "movl %ebx, (%esp)\n" /* pDstSurface */
        "calll CDirect3DSurface_UpdateOpenGLSurfaceObject\n"
        "movl $0x2601, 8(%esp)\n" /* line 1713 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 8(%esp)\n" /* line 1714 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1715 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1716 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0, 8(%esp)\n" /* line 1717 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x1702, (%esp)\n" /* line 1721 */
        "calll glMatrixMode\n"
        "movl 8(%ebp), %eax\n" /* line 1722 | this */
        "movl 0xf0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf185f0_00018adb\n"
        "movl $0xfffffffe, 0xc(%esp)\n"
        "movl imp___ZTI14COpenGLTexture, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl imp___ZTI17IDirect3DTexture9, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___dynamic_cast\n"
        ".Lf185f0_000187c7:\n"
        "movl 4(%eax), %eax\n"
        "movl (%eax), %edi\n" /* NullTexID */
        /* { scope 2 */
        "movl 8(%ebp), %edx\n" /* line 1723 | this */
        "movl 0x504(%edx), %eax\n"
        "subl $1, %eax\n"
        "js .Lf185f0_00018988\n"
        "movl %eax, %ebx\n" /* i */
        "shll $6, %eax\n"
        "leal -0x260(%ebp, %eax), %esi\n"
        "jmp .Lf185f0_000188f6\n"
        ".Lf185f0_000187ef:\n"
        "movl $0xde1, (%esp)\n" /* line 1736 */
        "calll glEnable\n"
        "movl $0x8513, (%esp)\n" /* line 1737 */
        "calll glDisable\n"
        "movl $0x1e01, 8(%esp)\n" /* line 1738 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1e01, 8(%esp)\n" /* line 1739 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 1740 */
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 8(%esp)\n" /* line 1741 */
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 1742 */
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 8(%esp)\n" /* line 1743 */
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 1744 */
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 1745 */
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "subl $1, %ebx\n" /* line 1723 | i */
        "subl $0x40, %esi\n"
        "cmpl $-1, %ebx\n" /* i */
        "je .Lf185f0_00018988\n"
        ".Lf185f0_000188f6:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 1725 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, 4(%esp)\n" /* line 1726 */
        "movl $0xba8, (%esp)\n"
        "calll glGetFloatv\n"
        "calll glLoadIdentity\n" /* line 1727 */
        "movl $0xc60, (%esp)\n" /* line 1729 */
        "calll glDisable\n"
        "movl $0xc61, (%esp)\n" /* line 1730 */
        "calll glDisable\n"
        "movl $0xc62, (%esp)\n" /* line 1731 */
        "calll glDisable\n"
        "movl $0xc63, (%esp)\n" /* line 1732 */
        "calll glDisable\n"
        "testl %ebx, %ebx\n" /* line 1734 | i */
        "je .Lf185f0_000187ef\n"
        "movl %edi, 4(%esp)\n" /* line 1749 | NullTexID */
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0xde1, (%esp)\n" /* line 1750 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 1751 */
        "calll glDisable\n"
        "subl $1, %ebx\n" /* line 1723 | i */
        "subl $0x40, %esi\n"
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf185f0_000188f6\n"
        /* } scope */
        ".Lf185f0_00018988:\n"
        "movl $0x1700, (%esp)\n" /* line 1755 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 1756 */
        "calll glLoadIdentity\n" /* line 1757 */
        "movl $0x1701, (%esp)\n" /* line 1758 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 1759 */
        "calll glLoadIdentity\n" /* line 1760 */
        "movl $0x3f800000, %esi\n" /* line 1761 */
        "movl %esi, 8(%esp)\n"
        "movl $0xbf800000, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll glScalef\n"
        "movsd lit8_00307c10, %xmm1\n" /* line 1763 | 1.0 */
        "movsd %xmm1, 0x18(%esp)\n"
        "pxor %xmm0, %xmm0\n"
        "movsd %xmm0, 0x10(%esp)\n"
        "movsd %xmm1, 8(%esp)\n"
        "movsd %xmm0, (%esp)\n"
        "calll gluOrtho2D\n"
        "movl $7, (%esp)\n" /* line 1765 */
        "calll glBegin\n"
        "movl %esi, 0xc(%esp)\n" /* line 1766 */
        "movl %esi, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll glColor4f\n"
        "xorl %ebx, %ebx\n" /* line 1767 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %ebx, 4(%esp)\n" /* line 1768 | i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertex2f\n"
        "movl %ebx, 4(%esp)\n" /* line 1769 | i */
        "movl %esi, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl %ebx, 4(%esp)\n" /* line 1770 | i */
        "movl %esi, (%esp)\n"
        "calll glVertex2f\n"
        "movl %esi, 4(%esp)\n" /* line 1771 */
        "movl %esi, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl %esi, 4(%esp)\n" /* line 1772 */
        "movl %esi, (%esp)\n"
        "calll glVertex2f\n"
        "movl %esi, 4(%esp)\n" /* line 1773 */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %esi, 4(%esp)\n" /* line 1774 */
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertex2f\n"
        "calll glEnd\n" /* line 1775 */
        "movl $0x1701, (%esp)\n" /* line 1777 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 1778 */
        "movl $0x1700, (%esp)\n" /* line 1779 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 1780 */
        "movl $0x1702, (%esp)\n" /* line 1784 */
        "calll glMatrixMode\n"
        /* { scope 2 */
        "movl 8(%ebp), %eax\n" /* line 1785 | this */
        "movl 0x504(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf185f0_00018c21\n"
        /* } scope */
        ".Lf185f0_00018abb:\n"
        "cmpb $0, -0x269(%ebp)\n" /* line 1794 | DestIsBackbuffer */
        "je .Lf185f0_00018af3\n"
        ".Lf185f0_00018ac4:\n"
        "calll glPopClientAttrib\n" /* line 1829 */
        "calll glPopAttrib\n" /* line 1830 */
        /* } scope */
        ".Lf185f0_00018ace:\n"
        "xorl %eax, %eax\n" /* line 2087 */
        "addl $0x29c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: SurfacePO2Height, Matrices, NullTexID, AuxWidth, ... */
        ".Lf185f0_00018adb:\n"
        "xorl %eax, %eax\n" /* line 1722 */
        "jmp .Lf185f0_000187c7\n"
        ".Lf185f0_00018ae2:\n"
        "movl $0x8804, (%esp)\n" /* line 1695 */
        "calll glDisable\n"
        "jmp .Lf185f0_00018667\n"
        /* { scope 2 */
        ".Lf185f0_00018af3:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1797 | pDestSurface */
        "movl 0x28(%eax), %ebx\n" /* pDstSurface */
        "movl 4(%ebx), %eax\n" /* line 1798 | pDstSurface */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0x409, (%esp)\n" /* line 1800 */
        "calll glReadBuffer\n"
        "movl $0x2601, 8(%esp)\n" /* line 1804 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 8(%esp)\n" /* line 1805 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1806 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1807 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0, 8(%esp)\n" /* line 1808 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl 0x2c(%ebx), %ecx\n" /* line 121 */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf185f0_00018c72\n"
        "movl $1, %esi\n"
        /* } scope */
        /* } scope */
        "movl 0x28(%ebx), %edx\n" /* line 120 */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf185f0_00018c95\n"
        ".Lf185f0_00018bc3:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf185f0_00018bc8:\n"
        "movl %esi, 0x1c(%esp)\n" /* line 1819 */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glCopyTexSubImage2D\n"
        "movl $0x405, (%esp)\n" /* line 1825 */
        "calll glReadBuffer\n"
        "movl $0x405, (%esp)\n" /* line 1826 */
        "calll glDrawBuffer\n"
        "jmp .Lf185f0_00018ac4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf185f0_00018c21:\n"
        "xorl %ebx, %ebx\n" /* line 1785 | i */
        "leal -0x260(%ebp), %esi\n" /* Matrices */
        ".Lf185f0_00018c29:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 1787 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, (%esp)\n" /* line 1788 */
        "calll glLoadMatrixf\n"
        "addl $1, %ebx\n" /* line 1785 | i */
        "addl $0x40, %esi\n"
        "movl 8(%ebp), %edx\n" /* this */
        "cmpl %ebx, 0x504(%edx)\n" /* i */
        "jg .Lf185f0_00018c29\n"
        "jmp .Lf185f0_00018abb\n"
        /* } scope */
        ".Lf185f0_00018c55:\n"
        "movl $0x86de, (%esp)\n" /* line 1686 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 1687 */
        "calll glDisable\n"
        "jmp .Lf185f0_00018657\n"
        /* { scope 2 */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf185f0_00018c72:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lf185f0_00018c7c:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ecx\n"
        "jbe .Lf185f0_00018c87\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_00018c7c\n"
        ".Lf185f0_00018c87:\n"
        "movl %edx, %esi\n"
        /* } scope */
        /* } scope */
        "movl 0x28(%ebx), %edx\n" /* line 120 */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, %edx\n" /* line 144 */
        "jbe .Lf185f0_00018bc3\n"
        ".Lf185f0_00018c95:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lf185f0_00018c9f:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lf185f0_00018caa\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_00018c9f\n"
        ".Lf185f0_00018caa:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf185f0_00018bc8\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf185f0_00018cb1:\n"
        "movl $0x8200, (%esp)\n" /* line 1691 */
        "calll glDisable\n"
        "jmp .Lf185f0_00018657\n"
        /* } scope */
        /* { scope 1: SurfacePO2Height, Matrices, NullTexID, AuxWidth, ... */
        ".Lf185f0_00018cc2:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1424 | pDestSurface */
        "movl (%eax), %edx\n"
        "leal -0x60(%ebp), %eax\n" /* Src */
        "movl %eax, 4(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* pDestSurface */
        "movl %eax, (%esp)\n"
        "calll *0x30(%edx)\n"
        "movl (%ebx), %edx\n" /* line 1425 | pSourceSurface */
        "leal -0x40(%ebp), %eax\n" /* Dst */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* pSourceSurface */
        "calll *0x30(%edx)\n"
        "movl -0x48(%ebp), %eax\n" /* line 1427 */
        "cmpl -0x28(%ebp), %eax\n"
        "jne .Lf185f0_00018cfa\n"
        "movl -0x44(%ebp), %eax\n"
        "cmpl -0x24(%ebp), %eax\n"
        "je .Lf185f0_000195f3\n"
        /* { scope 2 */
        ".Lf185f0_00018cfa:\n"
        "movl $0xfffff, (%esp)\n" /* line 1467 */
        "calll glPushAttrib\n"
        "movl $0xffffffff, (%esp)\n" /* line 1468 */
        "calll glPushClientAttrib\n"
        "movl $0x8620, (%esp)\n" /* line 1475 */
        "calll glDisable\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 1476 */
        "je .Lf185f0_000194f9\n"
        "calll MacDisplay_GetCardType\n" /* line 178 */
        "subl $1, %eax\n" /* line 1481 */
        "je .Lf185f0_000195e2\n"
        ".Lf185f0_00018d3a:\n"
        "calll MacOpenGLUtils_GetPCPixelShaderVersion\n" /* line 1485 */
        "cmpl $0xffff01ff, %eax\n"
        "ja .Lf185f0_000194b4\n"
        ".Lf185f0_00018d4a:\n"
        "movl 8(%ebp), %eax\n" /* line 1490 | this */
        "movl %eax, (%esp)\n"
        "calll CDirect3DDevice_StartPixelOneToOneState\n"
        "movl $0x84c0, (%esp)\n" /* line 1493 */
        "calll glActiveTextureARB\n"
        "movl 0x28(%ebx), %eax\n" /* line 1495 | pSourceSurface */
        "movl 4(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0x2601, 8(%esp)\n" /* line 1499 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 8(%esp)\n" /* line 1500 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1501 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1502 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0, 8(%esp)\n" /* line 1503 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl -0x28(%ebp), %edx\n" /* line 1505 | i */
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf185f0_00019457\n"
        "movl $1, %edi\n"
        /* } scope */
        ".Lf185f0_00018e16:\n"
        "movl -0x24(%ebp), %edx\n" /* line 1506 | i */
        /* { scope 3 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf185f0_0001942c\n"
        "movl $1, -0x274(%ebp)\n" /* SurfacePO2Height */
        /* } scope */
        ".Lf185f0_00018e2c:\n"
        "movl %edi, 4(%esp)\n" /* line 1509 | SurfacePO2Width */
        "movl $0xcf2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl %edi, 4(%esp)\n" /* line 1510 | SurfacePO2Width */
        "movl $0xd02, (%esp)\n"
        "calll glPixelStorei\n"
        "movl -0x24(%ebp), %eax\n" /* line 1521 */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glCopyTexSubImage2D\n"
        "movl $0x1702, (%esp)\n" /* line 1528 */
        "calll glMatrixMode\n"
        "movl 8(%ebp), %eax\n" /* line 1529 | this */
        "movl 0xf0(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf185f0_000194ad\n"
        "movl $0xfffffffe, 0xc(%esp)\n"
        "movl imp___ZTI14COpenGLTexture, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl imp___ZTI17IDirect3DTexture9, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll ___dynamic_cast\n"
        ".Lf185f0_00018ecd:\n"
        "movl 4(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, -0x270(%ebp)\n" /* NullTexID */
        /* { scope 3 */
        "movl 8(%ebp), %edx\n" /* line 1530 | this */
        "movl 0x504(%edx), %eax\n"
        "subl $1, %eax\n"
        "js .Lf185f0_000190b2\n"
        "movl %eax, %ebx\n" /* i */
        "shll $6, %eax\n"
        "leal -0x260(%ebp, %eax), %esi\n"
        "jmp .Lf185f0_0001900e\n"
        ".Lf185f0_00018efb:\n"
        "movl $0xde1, (%esp)\n" /* line 1543 */
        "calll glEnable\n"
        "movl $0x806f, (%esp)\n" /* line 1544 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 1545 */
        "calll glDisable\n"
        "movl $0x1e01, 8(%esp)\n" /* line 1546 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1e01, 8(%esp)\n" /* line 1547 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 1548 */
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x300, 8(%esp)\n" /* line 1549 */
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x1702, 8(%esp)\n" /* line 1550 */
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x302, 8(%esp)\n" /* line 1551 */
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 1552 */
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movl $0x3f800000, 8(%esp)\n" /* line 1553 */
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "subl $1, %ebx\n" /* line 1530 | i */
        "subl $0x40, %esi\n"
        "cmpl $-1, %ebx\n" /* i */
        "je .Lf185f0_000190b2\n"
        ".Lf185f0_0001900e:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 1532 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, 4(%esp)\n" /* line 1533 */
        "movl $0xba8, (%esp)\n"
        "calll glGetFloatv\n"
        "calll glLoadIdentity\n" /* line 1534 */
        "movl $0xc60, (%esp)\n" /* line 1536 */
        "calll glDisable\n"
        "movl $0xc61, (%esp)\n" /* line 1537 */
        "calll glDisable\n"
        "movl $0xc62, (%esp)\n" /* line 1538 */
        "calll glDisable\n"
        "movl $0xc63, (%esp)\n" /* line 1539 */
        "calll glDisable\n"
        "testl %ebx, %ebx\n" /* line 1541 | i */
        "je .Lf185f0_00018efb\n"
        "movl -0x270(%ebp), %eax\n" /* line 1557 | NullTexID */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0xde1, (%esp)\n" /* line 1558 */
        "calll glDisable\n"
        "movl $0x806f, (%esp)\n" /* line 1559 */
        "calll glDisable\n"
        "movl $0x8513, (%esp)\n" /* line 1560 */
        "calll glDisable\n"
        "subl $1, %ebx\n" /* line 1530 | i */
        "subl $0x40, %esi\n"
        "cmpl $-1, %ebx\n" /* i */
        "jne .Lf185f0_0001900e\n"
        /* } scope */
        ".Lf185f0_000190b2:\n"
        "movl $0x1700, (%esp)\n" /* line 1564 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 1565 */
        "calll glLoadIdentity\n" /* line 1566 */
        "movl $0x1701, (%esp)\n" /* line 1567 */
        "calll glMatrixMode\n"
        "calll glPushMatrix\n" /* line 1568 */
        "calll glLoadIdentity\n" /* line 1569 */
        "leal -0x20(%ebp), %eax\n" /* line 1577 | AuxHeight */
        "movl %eax, 4(%esp)\n"
        "leal -0x1c(%ebp), %eax\n" /* AuxWidth */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetCurrentDimensions\n"
        "cvtsi2ssl -0x20(%ebp), %xmm1\n" /* line 1585 | AuxHeight */
        "movl -0x44(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf185f0_00019516\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf185f0_00019104:\n"
        "divss %xmm0, %xmm1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 0x18(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "cvtsi2ssl -0x1c(%ebp), %xmm1\n" /* AuxWidth */
        "movl -0x48(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf185f0_000195cc\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf185f0_00019136:\n"
        "divss %xmm0, %xmm1\n"
        "cvtss2sd %xmm1, %xmm1\n"
        "movsd %xmm1, 8(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $0, 4(%esp)\n"
        "calll gluOrtho2D\n"
        "movl $0x40a, (%esp)\n" /* line 1588 */
        "calll glDrawBuffer\n"
        "movl $7, (%esp)\n" /* line 1589 */
        "calll glBegin\n"
        "movl $0x3f800000, %eax\n" /* line 1590 */
        "movl %eax, 0xc(%esp)\n"
        "movl %eax, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glColor4f\n"
        "xorl %ebx, %ebx\n" /* line 1591 | i */
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl %ebx, 4(%esp)\n" /* line 1592 | i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertex2f\n"
        "testl %edi, %edi\n" /* line 1593 | SurfacePO2Width */
        "js .Lf185f0_000195ae\n"
        "cvtsi2ssl %edi, %xmm0\n" /* SurfacePO2Width */
        "movss %xmm0, -0x27c(%ebp)\n"
        ".Lf185f0_000191b7:\n"
        "movl $0, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf185f0_00019598\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf185f0_000191ce:\n"
        "divss -0x27c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl $0, 4(%esp)\n" /* line 1594 */
        "movl $0x3f800000, (%esp)\n"
        "calll glVertex2f\n"
        "movl -0x274(%ebp), %eax\n" /* line 1595 | SurfacePO2Height */
        "testl %eax, %eax\n"
        "js .Lf185f0_0001956e\n"
        "cvtsi2ssl -0x274(%ebp), %xmm0\n" /* SurfacePO2Height */
        "movss %xmm0, -0x278(%ebp)\n"
        ".Lf185f0_00019212:\n"
        "movl -0x24(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf185f0_00019558\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf185f0_00019221:\n"
        "divss -0x278(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "movl -0x28(%ebp), %edx\n"
        "testl %edx, %edx\n"
        "js .Lf185f0_00019542\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf185f0_0001923e:\n"
        "divss -0x27c(%ebp), %xmm0\n"
        "movss %xmm0, (%esp)\n"
        "calll glTexCoord2f\n"
        "movl $0x3f800000, %eax\n" /* line 1596 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll glVertex2f\n"
        "movl -0x24(%ebp), %edx\n" /* line 1597 */
        "testl %edx, %edx\n"
        "js .Lf185f0_0001952c\n"
        "cvtsi2ssl %edx, %xmm0\n"
        ".Lf185f0_00019270:\n"
        "divss -0x278(%ebp), %xmm0\n"
        "movss %xmm0, 4(%esp)\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl %ebx, (%esp)\n" /* i */
        "calll glTexCoord2f\n"
        "movl $0x3f800000, 4(%esp)\n" /* line 1598 */
        "movl %ebx, (%esp)\n" /* i */
        "calll glVertex2f\n"
        "calll glEnd\n" /* line 1599 */
        "movl $0x1701, (%esp)\n" /* line 1601 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 1602 */
        "movl $0x1700, (%esp)\n" /* line 1603 */
        "calll glMatrixMode\n"
        "calll glPopMatrix\n" /* line 1604 */
        "movl $0x1702, (%esp)\n" /* line 1608 */
        "calll glMatrixMode\n"
        /* { scope 3 */
        "movl 8(%ebp), %eax\n" /* line 1609 | this */
        "movl 0x504(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lf185f0_000194c5\n"
        /* } scope */
        ".Lf185f0_000192dc:\n"
        "movl 0x14(%ebp), %eax\n" /* line 1616 | pDestSurface */
        "movl 0x28(%eax), %ebx\n" /* pDstSurface */
        "movl 4(%ebx), %eax\n" /* line 1617 | pDstSurface */
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl $0x40a, (%esp)\n" /* line 1621 */
        "calll glReadBuffer\n"
        "movl $0x2601, 8(%esp)\n" /* line 1625 */
        "movl $0x2801, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2601, 8(%esp)\n" /* line 1626 */
        "movl $0x2800, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1627 */
        "movl $0x2802, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0x2900, 8(%esp)\n" /* line 1628 */
        "movl $0x2803, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl $0, 8(%esp)\n" /* line 1629 */
        "movl $0x813d, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glTexParameteri\n"
        "movl 0x2c(%ebx), %ecx\n" /* line 121 */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf185f0_00019491\n"
        "movl $1, %esi\n"
        /* } scope */
        /* } scope */
        ".Lf185f0_000193a0:\n"
        "movl 0x28(%ebx), %edx\n" /* line 120 */
        /* { scope 3 */
        /* { scope 4 */
        "cmpl $1, %edx\n" /* line 144 */
        "ja .Lf185f0_00019475\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf185f0_000193b1:\n"
        "movl %esi, 0x1c(%esp)\n" /* line 1643 */
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glCopyTexSubImage2D\n"
        "movl $0, 4(%esp)\n" /* line 1646 */
        "movl $0xcf2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $0, 4(%esp)\n" /* line 1647 */
        "movl $0xd02, (%esp)\n"
        "calll glPixelStorei\n"
        "calll glPopClientAttrib\n" /* line 1651 */
        "calll glPopAttrib\n" /* line 1652 */
        /* } scope */
        /* } scope */
        "xorl %eax, %eax\n" /* line 2087 */
        "addl $0x29c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: SurfacePO2Height, Matrices, NullTexID, AuxWidth, ... */
        /* { scope 2 */
        /* { scope 3 */
        ".Lf185f0_0001942c:\n"
        "movl $1, -0x274(%ebp)\n" /* line 144 | SurfacePO2Height */
        "movl $0x20, %eax\n"
        ".Lf185f0_0001943b:\n"
        "shll -0x274(%ebp)\n" /* SurfacePO2Height */
        "cmpl -0x274(%ebp), %edx\n" /* SurfacePO2Height */
        "jbe .Lf185f0_00018e2c\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_0001943b\n"
        "jmp .Lf185f0_00018e2c\n"
        /* } scope */
        /* { scope 3 */
        ".Lf185f0_00019457:\n"
        "movl $1, %edi\n"
        "movl $0x20, %eax\n"
        ".Lf185f0_00019461:\n"
        "addl %edi, %edi\n"
        "cmpl %edi, %edx\n"
        "jbe .Lf185f0_00018e16\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_00019461\n"
        "jmp .Lf185f0_00018e16\n"
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf185f0_00019475:\n"
        "movl $1, %ecx\n"
        "movl $0x20, %eax\n"
        ".Lf185f0_0001947f:\n"
        "addl %ecx, %ecx\n"
        "cmpl %ecx, %edx\n"
        "jbe .Lf185f0_0001948a\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_0001947f\n"
        ".Lf185f0_0001948a:\n"
        "movl %ecx, %eax\n"
        "jmp .Lf185f0_000193b1\n"
        /* } scope */
        /* } scope */
        /* { scope 3 */
        /* { scope 4 */
        ".Lf185f0_00019491:\n"
        "movl $1, %edx\n"
        "movl $0x20, %eax\n"
        ".Lf185f0_0001949b:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ecx\n"
        "jbe .Lf185f0_000194a6\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_0001949b\n"
        ".Lf185f0_000194a6:\n"
        "movl %edx, %esi\n"
        "jmp .Lf185f0_000193a0\n"
        /* } scope */
        /* } scope */
        ".Lf185f0_000194ad:\n"
        "xorl %eax, %eax\n" /* line 1529 */
        "jmp .Lf185f0_00018ecd\n"
        ".Lf185f0_000194b4:\n"
        "movl $0x8804, (%esp)\n" /* line 1487 */
        "calll glDisable\n"
        "jmp .Lf185f0_00018d4a\n"
        /* { scope 3 */
        ".Lf185f0_000194c5:\n"
        "xorl %ebx, %ebx\n" /* line 1609 | i */
        "leal -0x260(%ebp), %esi\n" /* Matrices */
        ".Lf185f0_000194cd:\n"
        "leal 0x84c0(%ebx), %eax\n" /* line 1611 | i */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "movl %esi, (%esp)\n" /* line 1612 */
        "calll glLoadMatrixf\n"
        "addl $1, %ebx\n" /* line 1609 | i */
        "addl $0x40, %esi\n"
        "movl 8(%ebp), %edx\n" /* this */
        "cmpl %ebx, 0x504(%edx)\n" /* i */
        "jg .Lf185f0_000194cd\n"
        "jmp .Lf185f0_000192dc\n"
        /* } scope */
        ".Lf185f0_000194f9:\n"
        "movl $0x86de, (%esp)\n" /* line 1478 */
        "calll glDisable\n"
        "movl $0x8522, (%esp)\n" /* line 1479 */
        "calll glDisable\n"
        "jmp .Lf185f0_00018d3a\n"
        ".Lf185f0_00019516:\n"
        "movl %edx, %eax\n" /* line 1585 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf185f0_00019104\n"
        ".Lf185f0_0001952c:\n"
        "movl %edx, %eax\n" /* line 1597 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf185f0_00019270\n"
        ".Lf185f0_00019542:\n"
        "movl %edx, %eax\n" /* line 1595 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf185f0_0001923e\n"
        ".Lf185f0_00019558:\n"
        "movl %edx, %eax\n"
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf185f0_00019221\n"
        ".Lf185f0_0001956e:\n"
        "movl -0x274(%ebp), %eax\n" /* SurfacePO2Height */
        "shrl $1, %eax\n"
        "andl $1, -0x274(%ebp)\n" /* SurfacePO2Height */
        "orl -0x274(%ebp), %eax\n" /* SurfacePO2Height */
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -0x278(%ebp)\n"
        "jmp .Lf185f0_00019212\n"
        ".Lf185f0_00019598:\n"
        "movl %edx, %eax\n" /* line 1593 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf185f0_000191ce\n"
        ".Lf185f0_000195ae:\n"
        "movl %edi, %eax\n" /* SurfacePO2Width */
        "shrl $1, %eax\n"
        "andl $1, %edi\n" /* SurfacePO2Width */
        "orl %edi, %eax\n" /* SurfacePO2Width */
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "movss %xmm0, -0x27c(%ebp)\n"
        "jmp .Lf185f0_000191b7\n"
        ".Lf185f0_000195cc:\n"
        "movl %edx, %eax\n" /* line 1585 */
        "shrl $1, %eax\n"
        "andl $1, %edx\n"
        "orl %edx, %eax\n"
        "cvtsi2ssl %eax, %xmm0\n"
        "addss %xmm0, %xmm0\n"
        "jmp .Lf185f0_00019136\n"
        ".Lf185f0_000195e2:\n"
        "movl $0x8200, (%esp)\n" /* line 1483 */
        "calll glDisable\n"
        "jmp .Lf185f0_00018d3a\n"
        /* } scope */
        /* { scope 2 */
        ".Lf185f0_000195f3:\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1431 | AuxWidth */
        "movl %eax, 4(%esp)\n"
        "movl $0x84e0, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl $0x84c0, (%esp)\n" /* line 1432 */
        "calll glActiveTextureARB\n"
        "leal -0x20(%ebp), %eax\n" /* line 1435 | AuxHeight */
        "movl %eax, 4(%esp)\n"
        "movl $0x8069, (%esp)\n"
        "calll glGetIntegerv\n"
        "movl 0x14(%ebp), %edx\n" /* line 1438 | pDestSurface */
        "movl 0x28(%edx), %eax\n"
        "movl 4(%eax), %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl -0x28(%ebp), %ecx\n" /* line 1440 | i */
        /* { scope 3 */
        "cmpl $1, %ecx\n" /* line 144 */
        "ja .Lf185f0_000196fe\n"
        "movl $1, %ebx\n"
        /* } scope */
        ".Lf185f0_00019651:\n"
        "movl %ebx, 4(%esp)\n" /* line 1442 | pSourceSurface */
        "movl $0xcf2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl %ebx, 4(%esp)\n" /* line 1443 | pSourceSurface */
        "movl $0xd02, (%esp)\n"
        "calll glPixelStorei\n"
        "movl -0x44(%ebp), %eax\n" /* line 1454 */
        "movl %eax, 0x1c(%esp)\n"
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glCopyTexSubImage2D\n"
        "movl $0, 4(%esp)\n" /* line 1457 */
        "movl $0xcf2, (%esp)\n"
        "calll glPixelStorei\n"
        "movl $0, 4(%esp)\n" /* line 1458 */
        "movl $0xd02, (%esp)\n"
        "calll glPixelStorei\n"
        "movl -0x20(%ebp), %eax\n" /* line 1460 | AuxHeight */
        "movl %eax, 4(%esp)\n"
        "movl $0xde1, (%esp)\n"
        "calll glBindTexture\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1461 | AuxWidth */
        "movl %eax, (%esp)\n"
        "calll glActiveTextureARB\n"
        "jmp .Lf185f0_00018ace\n"
        /* { scope 3 */
        ".Lf185f0_000196fe:\n"
        "movl $1, %edx\n" /* line 144 */
        "movl $0x20, %eax\n"
        ".Lf185f0_00019708:\n"
        "addl %edx, %edx\n"
        "cmpl %edx, %ecx\n"
        "jbe .Lf185f0_00019713\n"
        "subl $1, %eax\n"
        "jne .Lf185f0_00019708\n"
        ".Lf185f0_00019713:\n"
        "movl %edx, %ebx\n"
        "jmp .Lf185f0_00019651\n"
    );
}

/* line 4521 */
__attribute__((naked))
long unsigned int COpenGL_SetTexCombinerRGB1(const COpenGL * _this, UINT32 Unit, GLenum ColorOp, GLenum Source0, GLenum Operand0, GLfloat Scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4521 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* ColorOp */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %ebx\n"
        "cmpl %edi, 0x70(%ebx)\n" /* line 4525 | ColorOp */
        "je .Lf1971a_00019767\n"
        "movl %esi, 4(%esp)\n" /* line 4527 | Unit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %edi, 8(%esp)\n" /* line 174 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl %edi, 0x70(%ebx)\n"
        ".Lf1971a_00019767:\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 4530 | Scale */
        "ucomiss 0xa8(%ebx), %xmm0\n"
        "jp .Lf1971a_000197ef\n"
        "jne .Lf1971a_000197ef\n"
        ".Lf1971a_00019777:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4536 | Source0 */
        "cmpl %eax, 0x74(%ebx)\n"
        "je .Lf1971a_000197af\n"
        "movl %esi, 4(%esp)\n" /* line 4538 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x14(%ebp), %eax\n" /* line 176 | Source0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x14(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x74(%ebx)\n"
        ".Lf1971a_000197af:\n"
        "movl 0x18(%ebp), %eax\n" /* line 4541 | Operand0 */
        "cmpl %eax, 0x78(%ebx)\n"
        "je .Lf1971a_000197e7\n"
        "movl %esi, 4(%esp)\n" /* line 4543 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x18(%ebp), %eax\n" /* line 177 | Operand0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x18(%ebp), %eax\n" /* Operand0 */
        "movl %eax, 0x78(%ebx)\n"
        ".Lf1971a_000197e7:\n"
        "addl $0x1c, %esp\n" /* line 4546 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1971a_000197ef:\n"
        "movl %esi, 4(%esp)\n" /* line 4532 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 182 | Scale */
        "movss %xmm0, 8(%esp)\n"
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movss 0x1c(%ebp), %xmm0\n" /* Scale */
        "movss %xmm0, 0xa8(%ebx)\n"
        "jmp .Lf1971a_00019777\n"
    );
}

/* line 4559 */
__attribute__((naked))
long unsigned int COpenGL_SetTexCombinerRGB2(const COpenGL * _this, UINT32 Unit, GLenum ColorOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, GLfloat Scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4559 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* ColorOp */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %ebx\n"
        "cmpl %edi, 0x70(%ebx)\n" /* line 4562 | ColorOp */
        "je .Lf19830_0001987d\n"
        "movl %esi, 4(%esp)\n" /* line 4564 | Unit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %edi, 8(%esp)\n" /* line 174 */
        "movl $0x8571, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl %edi, 0x70(%ebx)\n"
        ".Lf19830_0001987d:\n"
        "movss 0x24(%ebp), %xmm0\n" /* line 4567 | Scale */
        "ucomiss 0xa8(%ebx), %xmm0\n"
        "jp .Lf19830_00019983\n"
        "jne .Lf19830_00019983\n"
        ".Lf19830_00019895:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 4573 | Source1 */
        "cmpl %eax, 0x7c(%ebx)\n"
        "je .Lf19830_000198cd\n"
        "movl %esi, 4(%esp)\n" /* line 4575 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x1c(%ebp), %eax\n" /* line 178 | Source1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8581, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x1c(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0x7c(%ebx)\n"
        ".Lf19830_000198cd:\n"
        "movl 0x20(%ebp), %eax\n" /* line 4578 | Operand1 */
        "cmpl %eax, 0x80(%ebx)\n"
        "je .Lf19830_0001990b\n"
        "movl %esi, 4(%esp)\n" /* line 4580 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x20(%ebp), %eax\n" /* line 179 | Operand1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8591, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x20(%ebp), %eax\n" /* Operand1 */
        "movl %eax, 0x80(%ebx)\n"
        ".Lf19830_0001990b:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4583 | Source0 */
        "cmpl %eax, 0x74(%ebx)\n"
        "je .Lf19830_00019943\n"
        "movl %esi, 4(%esp)\n" /* line 4585 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x14(%ebp), %eax\n" /* line 176 | Source0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8580, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x14(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x74(%ebx)\n"
        ".Lf19830_00019943:\n"
        "movl 0x18(%ebp), %eax\n" /* line 4588 | Operand0 */
        "cmpl %eax, 0x78(%ebx)\n"
        "je .Lf19830_0001997b\n"
        "movl %esi, 4(%esp)\n" /* line 4590 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x18(%ebp), %eax\n" /* line 177 | Operand0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8590, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x18(%ebp), %eax\n" /* Operand0 */
        "movl %eax, 0x78(%ebx)\n"
        ".Lf19830_0001997b:\n"
        "addl $0x1c, %esp\n" /* line 4593 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19830_00019983:\n"
        "movl %esi, 4(%esp)\n" /* line 4569 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss 0x24(%ebp), %xmm0\n" /* line 182 | Scale */
        "movss %xmm0, 8(%esp)\n"
        "movl $0x8573, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movss 0x24(%ebp), %xmm0\n" /* Scale */
        "movss %xmm0, 0xa8(%ebx)\n"
        "jmp .Lf19830_00019895\n"
    );
}

/* line 4666 */
__attribute__((naked))
long unsigned int COpenGL_SetTexCombinerAlpha1(const COpenGL * _this, UINT32 Unit, GLenum AlphaOp, GLenum Source0, GLenum Operand0, float Scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4666 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* AlphaOp */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %ebx\n"
        "cmpl %edi, 0x8c(%ebx)\n" /* line 4670 | AlphaOp */
        "je .Lf199c4_00019a17\n"
        "movl %esi, 4(%esp)\n" /* line 4672 | Unit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %edi, 8(%esp)\n" /* line 184 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl %edi, 0x8c(%ebx)\n"
        ".Lf199c4_00019a17:\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 4675 | Scale */
        "ucomiss 0xac(%ebx), %xmm0\n"
        "jp .Lf199c4_00019ab3\n"
        "jne .Lf199c4_00019ab3\n"
        ".Lf199c4_00019a2f:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4681 | Source0 */
        "cmpl %eax, 0x90(%ebx)\n"
        "je .Lf199c4_00019a6d\n"
        "movl %esi, 4(%esp)\n" /* line 4683 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x14(%ebp), %eax\n" /* line 185 | Source0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x14(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x90(%ebx)\n"
        ".Lf199c4_00019a6d:\n"
        "movl 0x18(%ebp), %eax\n" /* line 4686 | Operand0 */
        "cmpl %eax, 0x94(%ebx)\n"
        "je .Lf199c4_00019aab\n"
        "movl %esi, 4(%esp)\n" /* line 4688 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x18(%ebp), %eax\n" /* line 186 | Operand0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x18(%ebp), %eax\n" /* Operand0 */
        "movl %eax, 0x94(%ebx)\n"
        ".Lf199c4_00019aab:\n"
        "addl $0x1c, %esp\n" /* line 4691 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf199c4_00019ab3:\n"
        "movl %esi, 4(%esp)\n" /* line 4677 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss 0x1c(%ebp), %xmm0\n" /* line 191 | Scale */
        "movss %xmm0, 8(%esp)\n"
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movss 0x1c(%ebp), %xmm0\n" /* Scale */
        "movss %xmm0, 0xac(%ebx)\n"
        "jmp .Lf199c4_00019a2f\n"
    );
}

/* line 4704 */
__attribute__((naked))
long unsigned int COpenGL_SetTexCombinerAlpha2(const COpenGL * _this, UINT32 Unit, GLenum AlphaOp, GLenum Source0, GLenum Operand0, GLenum Source1, GLenum Operand1, float Scale)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4704 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 0xc(%ebp), %esi\n" /* Unit */
        "movl 0x10(%ebp), %edi\n" /* AlphaOp */
        "leal (%esi, %esi, 8), %eax\n" /* line 654 */
        "leal (%esi, %eax, 2), %ebx\n"
        "shll $4, %ebx\n"
        "movl 8(%ebp), %eax\n" /* this */
        "addl 0x65c(%eax), %ebx\n"
        "cmpl %edi, 0x8c(%ebx)\n" /* line 4708 | AlphaOp */
        "je .Lf19af4_00019b47\n"
        "movl %esi, 4(%esp)\n" /* line 4710 | Unit */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl %edi, 8(%esp)\n" /* line 184 */
        "movl $0x8572, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl %edi, 0x8c(%ebx)\n"
        ".Lf19af4_00019b47:\n"
        "movss 0x24(%ebp), %xmm0\n" /* line 4713 | Scale */
        "ucomiss 0xac(%ebx), %xmm0\n"
        "jp .Lf19af4_00019c5f\n"
        "jne .Lf19af4_00019c5f\n"
        ".Lf19af4_00019b5f:\n"
        "movl 0x1c(%ebp), %eax\n" /* line 4719 | Source1 */
        "cmpl %eax, 0x98(%ebx)\n"
        "je .Lf19af4_00019b9d\n"
        "movl %esi, 4(%esp)\n" /* line 4721 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x1c(%ebp), %eax\n" /* line 187 | Source1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8589, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x1c(%ebp), %eax\n" /* Source1 */
        "movl %eax, 0x98(%ebx)\n"
        ".Lf19af4_00019b9d:\n"
        "movl 0x20(%ebp), %eax\n" /* line 4724 | Operand1 */
        "cmpl %eax, 0x9c(%ebx)\n"
        "je .Lf19af4_00019bdb\n"
        "movl %esi, 4(%esp)\n" /* line 4726 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x20(%ebp), %eax\n" /* line 188 | Operand1 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8599, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x20(%ebp), %eax\n" /* Operand1 */
        "movl %eax, 0x9c(%ebx)\n"
        ".Lf19af4_00019bdb:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4730 | Source0 */
        "cmpl %eax, 0x90(%ebx)\n"
        "je .Lf19af4_00019c19\n"
        "movl %esi, 4(%esp)\n" /* line 4732 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x14(%ebp), %eax\n" /* line 185 | Source0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8588, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x14(%ebp), %eax\n" /* Source0 */
        "movl %eax, 0x90(%ebx)\n"
        ".Lf19af4_00019c19:\n"
        "movl 0x18(%ebp), %eax\n" /* line 4735 | Operand0 */
        "cmpl %eax, 0x94(%ebx)\n"
        "je .Lf19af4_00019c57\n"
        "movl %esi, 4(%esp)\n" /* line 4737 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 0x18(%ebp), %eax\n" /* line 186 | Operand0 */
        "movl %eax, 8(%esp)\n"
        "movl $0x8598, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvi\n"
        "movl 0x18(%ebp), %eax\n" /* Operand0 */
        "movl %eax, 0x94(%ebx)\n"
        ".Lf19af4_00019c57:\n"
        "addl $0x1c, %esp\n" /* line 4740 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf19af4_00019c5f:\n"
        "movl %esi, 4(%esp)\n" /* line 4715 | Unit */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movss 0x24(%ebp), %xmm0\n" /* line 191 | Scale */
        "movss %xmm0, 8(%esp)\n"
        "movl $0xd1c, 4(%esp)\n"
        "movl $0x2300, (%esp)\n"
        "calll glTexEnvf\n"
        "movss 0x24(%ebp), %xmm0\n" /* Scale */
        "movss %xmm0, 0xac(%ebx)\n"
        "jmp .Lf19af4_00019b5f\n"
    );
}

/* line 4853 */
__attribute__((naked))
long unsigned int CDirect3DDevice_SetTextureCoordStream(const CDirect3DDevice * _this, UINT32 TexUnit, UINT32 TransformFlags, const D3DMATRIX *OriginalTexTransform, GLint VSize, UINT32 Tci, UINT32 StartVertex, UINT32 EndVertex, const float *pSrcCoords, UINT32 SrcStride, const float *pSrc2Coords, UINT32 Src2Stride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4853 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xcc, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* TexUnit */
        "movl 0x10(%ebp), %edx\n" /* TransformFlags */
        "movl 0x14(%ebp), %ebx\n" /* OriginalTexTransform */
        "movl 0x1c(%ebp), %ecx\n" /* Tci */
        /* { scope 1: NewMatrix, s, t */
        "movl %edx, %eax\n" /* line 4857 */
        "shrl $8, %eax\n"
        "andb $1, %al\n"
        "movl %eax, %esi\n" /* IsProjected */
        "andb $0xfe, %dh\n" /* line 4858 */
        "testl %ecx, %ecx\n" /* line 4863 */
        "jne .Lf19ca0_00019d03\n"
        "testl %edx, %edx\n" /* line 4865 */
        "jne .Lf19ca0_00019d4b\n"
        "xorl %ebx, %ebx\n" /* UseOutputTexTransform */
        ".Lf19ca0_00019cce:\n"
        "movl imp___ZN10CVAOPacket10sVAOStatusE, %eax\n" /* line 4898 */
        "cmpl $1, (%eax)\n"
        "je .Lf19ca0_0001a005\n"
        ".Lf19ca0_00019cdc:\n"
        "testb %bl, %bl\n" /* line 5222 | UseOutputTexTransform */
        "je .Lf19ca0_00019d2f\n"
        ".Lf19ca0_00019ce0:\n"
        "leal -0x78(%ebp), %eax\n" /* line 5224 | OutputTexTransform */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* TexUnit */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexMatrix\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 5231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: NewMatrix, s, t */
        ".Lf19ca0_00019d03:\n"
        "cmpl $0x20000, %ecx\n" /* line 4908 */
        "je .Lf19ca0_00019dc2\n"
        "cmpl $0x30000, %ecx\n" /* line 4978 */
        "je .Lf19ca0_00019f99\n"
        "cmpl $0x10000, %ecx\n" /* line 5026 */
        "je .Lf19ca0_00019e5b\n"
        ".Lf19ca0_00019d27:\n"
        "movl imp___ZN7COpenGL9sDrawFlagE, %eax\n" /* line 672 */
        "movb $0, (%eax)\n"
        ".Lf19ca0_00019d2f:\n"
        "movl %edi, 4(%esp)\n" /* line 5228 | TexUnit */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetTexMatrixIdentity\n"
        /* } scope */
        "addl $0xcc, %esp\n" /* line 5231 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: NewMatrix, s, t */
        ".Lf19ca0_00019d4b:\n"
        "movl (%ebx), %eax\n" /* line 4872 | UseOutputTexTransform */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl 4(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x70(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x18(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x60(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x28(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x2c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x38(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x3c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x3c(%ebp)\n"
        "cmpl $1, %edx\n" /* line 4874 */
        "je .Lf19ca0_00019db8\n"
        "cmpl $2, %edx\n" /* line 4878 */
        "je .Lf19ca0_0001a074\n"
        ".Lf19ca0_00019db8:\n"
        "movl $1, %ebx\n" /* line 4885 | UseOutputTexTransform */
        "jmp .Lf19ca0_00019cce\n"
        ".Lf19ca0_00019dc2:\n"
        "testb %al, %al\n" /* line 4910 */
        "jne .Lf19ca0_0001a21a\n"
        "cmpl $3, %edx\n" /* line 4924 */
        "je .Lf19ca0_0001a36a\n"
        "cmpl $2, %edx\n" /* line 4946 */
        "je .Lf19ca0_0001a420\n"
        /* { scope 2 */
        "xorl %ebx, %ebx\n" /* line 99 */
        /* } scope */
        ".Lf19ca0_00019dde:\n"
        "movl imp___ZN10CVAOPacket10sVAOStatusE, %eax\n" /* line 4967 */
        "cmpl $1, (%eax)\n"
        "jne .Lf19ca0_00019cdc\n"
        "movl 0x18(%ebp), %edx\n" /* line 162 | VSize */
        "movl %edx, 0x14(%esp)\n"
        "movl 0x28(%ebp), %eax\n" /* pSrcCoords */
        "movl %eax, 0x10(%esp)\n"
        "movl 0x2c(%ebp), %edx\n" /* SrcStride */
        "movl %edx, 0xc(%esp)\n"
        "movl $0x1406, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal (%edi, %edi, 2), %eax\n"
        "movl imp_g_CurrentGenericPacket, %edx\n"
        "movl (%edx), %edx\n"
        "leal 0x70(%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        "movl 0x28(%ebp), %eax\n" /* line 4973 | pSrcCoords */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x2c(%ebp), %edx\n" /* SrcStride */
        "movl %edx, 0x10(%esp)\n"
        "movl $0x1406, 0xc(%esp)\n"
        "movl 0x18(%ebp), %eax\n" /* VSize */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* TexUnit */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableTexCoordArray\n"
        "jmp .Lf19ca0_00019cdc\n"
        ".Lf19ca0_00019e5b:\n"
        "cmpl $2, %edx\n" /* line 5028 */
        "jne .Lf19ca0_00019d27\n"
        "calll MacDisplay_GetCardType\n" /* line 179 */
        "cmpl $2, %eax\n" /* line 5030 */
        "je .Lf19ca0_00019d2f\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 5038 | UseOutputTexTransform */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl 4(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x74(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x44(%ebp)\n"
        "xorl %eax, %eax\n" /* line 5039 */
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 5040 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl $0x3f800000, -0x3c(%ebp)\n" /* line 5041 */
        "movl 8(%ebp), %edx\n" /* line 4831 | this */
        "cmpb $0, 0x470(%edx)\n"
        "jne .Lf19ca0_0001a4d3\n"
        "leal 0x430(%edx), %ebx\n"
        ".Lf19ca0_00019ed5:\n"
        "movl %edi, 4(%esp)\n" /* line 5046 | TexUnit */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_SetActiveTexUnit\n"
        "movl 8(%ebp), %edx\n" /* line 5047 | this */
        "movl 0x430(%edx), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* s */
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x24(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x1c(%ebp)\n"
        "leal -0x28(%ebp), %eax\n" /* line 5048 | s */
        "movl %eax, 8(%esp)\n"
        "movl $0x2501, 4(%esp)\n"
        "movl $0x2000, (%esp)\n"
        "calll glTexGenfv\n"
        "movl 4(%ebx), %eax\n" /* line 5049 | UseOutputTexTransform */
        "movl %eax, -0x38(%ebp)\n" /* t */
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x2c(%ebp)\n"
        "leal -0x38(%ebp), %eax\n" /* line 5050 | t */
        "movl %eax, 8(%esp)\n"
        "movl $0x2501, 4(%esp)\n"
        "movl $0x2001, (%esp)\n"
        "calll glTexGenfv\n"
        "movl 8(%ebx), %eax\n" /* line 5051 | UseOutputTexTransform */
        "movl %eax, -0xb8(%ebp)\n" /* NewMatrix */
        "movl 0x18(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0xb4(%ebp)\n"
        "movl 0x28(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0xb0(%ebp)\n"
        "movl 0x38(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0xac(%ebp)\n"
        "leal -0xb8(%ebp), %eax\n" /* line 5052 | NewMatrix */
        "movl %eax, 8(%esp)\n"
        "movl $0x2501, 4(%esp)\n"
        "movl $0x2002, (%esp)\n"
        "calll glTexGenfv\n"
        "jmp .Lf19ca0_00019ce0\n"
        /* } scope */
        ".Lf19ca0_00019f99:\n"
        "testl %edx, %edx\n" /* line 4980 */
        "je .Lf19ca0_00019d2f\n"
        "cmpl $3, %edx\n" /* line 4986 */
        "je .Lf19ca0_0001a09e\n"
        "cmpl $2, %edx\n" /* line 5014 */
        "jne .Lf19ca0_00019d27\n"
        "movl (%ebx), %eax\n" /* line 5017 | UseOutputTexTransform */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl 4(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x74(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x44(%ebp)\n"
        "xorl %eax, %eax\n" /* line 5018 */
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 5019 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl $0x3f800000, -0x3c(%ebp)\n" /* line 5020 */
        "jmp .Lf19ca0_00019ce0\n"
        ".Lf19ca0_0001a005:\n"
        "movl 0x18(%ebp), %eax\n" /* line 162 | VSize */
        "movl %eax, 0x14(%esp)\n"
        "movl 0x28(%ebp), %edx\n" /* pSrcCoords */
        "movl %edx, 0x10(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* SrcStride */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x1406, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal (%edi, %edi, 2), %eax\n"
        "movl imp_g_CurrentGenericPacket, %edx\n"
        "movl (%edx), %edx\n"
        "leal 0x70(%edx, %eax, 8), %eax\n"
        "movl %eax, (%esp)\n"
        "calll CTexCoordArray_SetGuard\n"
        "movl 0x28(%ebp), %edx\n" /* line 4904 | pSrcCoords */
        "movl %edx, 0x14(%esp)\n"
        "movl 0x2c(%ebp), %eax\n" /* SrcStride */
        "movl %eax, 0x10(%esp)\n"
        "movl $0x1406, 0xc(%esp)\n"
        "movl 0x18(%ebp), %edx\n" /* VSize */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* TexUnit */
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_EnableTexCoordArray\n"
        "jmp .Lf19ca0_00019cdc\n"
        ".Lf19ca0_0001a074:\n"
        "movl -0x58(%ebp), %eax\n" /* line 4881 */
        "movl %eax, -0x48(%ebp)\n"
        "movl -0x54(%ebp), %eax\n" /* line 4882 */
        "movl %eax, -0x44(%ebp)\n"
        "xorl %eax, %eax\n" /* line 4883 */
        "movl %eax, -0x54(%ebp)\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl %eax, -0x40(%ebp)\n" /* line 4885 */
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl $1, %ebx\n" /* UseOutputTexTransform */
        "jmp .Lf19ca0_00019cce\n"
        /* { scope 2 */
        ".Lf19ca0_0001a09e:\n"
        "leal -0xb8(%ebp), %ecx\n" /* line 105 | NewMatrix */
        "movl 8(%ebp), %eax\n" /* this */
        "addl $0x474, %eax\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl 0x474(%ebx), %edx\n"
        "movl %edx, -0xb8(%ebp)\n" /* NewMatrix */
        "movl 4(%eax), %edx\n"
        "movl %edx, -0xb4(%ebp)\n"
        "movl 8(%eax), %edx\n"
        "movl %edx, -0xb0(%ebp)\n"
        "movl 0xc(%eax), %edx\n"
        "movl %edx, -0xac(%ebp)\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0xa8(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0xa4(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0xa0(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x98(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x94(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x8c(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x84(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x7c(%ebp)\n"
        "movl %esi, %eax\n" /* line 4992 | IsProjected */
        "testb %al, %al\n"
        "je .Lf19ca0_0001a159\n"
        "xorl %eax, %eax\n" /* line 4994 */
        "movl %eax, -0x80(%ebp)\n"
        "movl %eax, -0x90(%ebp)\n"
        "movl %eax, -0xa0(%ebp)\n"
        "movl %eax, -0xb0(%ebp)\n"
        ".Lf19ca0_0001a159:\n"
        "movl %ecx, (%esp)\n" /* line 5002 */
        "calll COpenGLMatrix_Transpose\n"
        "xorl %eax, %eax\n" /* line 5004 */
        "movl %eax, -0x8c(%ebp)\n"
        "movl %eax, -0x9c(%ebp)\n"
        "movl %eax, -0xac(%ebp)\n"
        "movl $0x3f800000, -0x7c(%ebp)\n" /* line 5005 */
        "movl %eax, -0x80(%ebp)\n" /* line 5008 */
        "movl %eax, -0x84(%ebp)\n"
        "movl %eax, -0x88(%ebp)\n"
        "movl -0xb8(%ebp), %eax\n" /* line 5010 | NewMatrix */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl -0xb4(%ebp), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl -0xb0(%ebp), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl -0xac(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0xa4(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "jmp .Lf19ca0_00019ce0\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19ca0_0001a21a:\n"
        "leal -0x78(%ebp), %esi\n" /* line 4913 | OutputTexTransform, IsProjected */
        "movl (%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl 4(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x70(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x18(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x60(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x28(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x2c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x38(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x3c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 4831 | this */
        "cmpb $0, 0x470(%edx)\n"
        "je .Lf19ca0_0001a35f\n"
        "movb $0, 0x470(%edx)\n" /* line 4833 */
        "movl %edx, %eax\n" /* line 4834 */
        "addl $0x3f0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "subl $0x40, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %ebx\n"
        "addl $0x430, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        ".Lf19ca0_0001a2b5:\n"
        "leal -0xb8(%ebp), %eax\n" /* line 4919 | NewMatrix */
        "movl %esi, 8(%esp)\n" /* IsProjected */
        "movl %ebx, 4(%esp)\n" /* UseOutputTexTransform */
        "movl %eax, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19ca0_0001a2cb:\n"
        "movl -0xb8(%ebp), %eax\n" /* line 4959 | NewMatrix */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl -0xb4(%ebp), %eax\n"
        "movl %eax, -0x74(%ebp)\n"
        "movl -0xb0(%ebp), %eax\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl -0xac(%ebp), %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl -0xa8(%ebp), %eax\n"
        "movl %eax, -0x68(%ebp)\n"
        "movl -0xa4(%ebp), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        "movl -0xa0(%ebp), %eax\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl -0x9c(%ebp), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl -0x98(%ebp), %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        "movl -0x94(%ebp), %eax\n"
        "movl %eax, -0x54(%ebp)\n"
        "movl -0x90(%ebp), %eax\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl -0x8c(%ebp), %eax\n"
        "movl %eax, -0x4c(%ebp)\n"
        "movl -0x88(%ebp), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl -0x84(%ebp), %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x80(%ebp), %eax\n"
        "movl %eax, -0x40(%ebp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "movl %eax, -0x3c(%ebp)\n"
        "movl $1, %ebx\n" /* UseOutputTexTransform */
        "jmp .Lf19ca0_00019dde\n"
        ".Lf19ca0_0001a35f:\n"
        "leal 0x430(%edx), %ebx\n" /* UseOutputTexTransform */
        "jmp .Lf19ca0_0001a2b5\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19ca0_0001a36a:\n"
        "leal -0x78(%ebp), %esi\n" /* line 4932 | OutputTexTransform, IsProjected */
        "movl (%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl 4(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x74(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x70(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x6c(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x18(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x60(%ebp)\n"
        "movl 0x1c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x5c(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x28(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x50(%ebp)\n"
        "movl 0x2c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x4c(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x44(%ebp)\n"
        "movl 0x38(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x40(%ebp)\n"
        "movl 0x3c(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x3c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 4831 | this */
        "cmpb $0, 0x470(%edx)\n"
        "je .Lf19ca0_0001a4c0\n"
        "movb $0, 0x470(%edx)\n" /* line 4833 */
        "movl %edx, %eax\n" /* line 4834 */
        "addl $0x3f0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "subl $0x40, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %ebx\n"
        "addl $0x430, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        ".Lf19ca0_0001a405:\n"
        "leal -0xb8(%ebp), %eax\n" /* line 4940 | NewMatrix */
        "movl %esi, 8(%esp)\n" /* IsProjected */
        "movl %ebx, 4(%esp)\n" /* UseOutputTexTransform */
        "movl %eax, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        "jmp .Lf19ca0_0001a2cb\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19ca0_0001a420:\n"
        "leal -0x78(%ebp), %esi\n" /* line 4949 | OutputTexTransform, IsProjected */
        "movl (%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x78(%ebp)\n" /* OutputTexTransform */
        "movl 4(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x74(%ebp)\n"
        "movl 0x10(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x68(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x64(%ebp)\n"
        "movl 0x20(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x58(%ebp)\n"
        "movl 0x24(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x54(%ebp)\n"
        "movl 0x30(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x34(%ebx), %eax\n" /* UseOutputTexTransform */
        "movl %eax, -0x44(%ebp)\n"
        "xorl %eax, %eax\n" /* line 4950 */
        "movl %eax, -0x40(%ebp)\n"
        "movl %eax, -0x50(%ebp)\n"
        "movl %eax, -0x60(%ebp)\n"
        "movl %eax, -0x70(%ebp)\n"
        "movl %eax, -0x4c(%ebp)\n" /* line 4951 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, -0x6c(%ebp)\n"
        "movl $0x3f800000, -0x3c(%ebp)\n" /* line 4952 */
        "movl 8(%ebp), %edx\n" /* line 4831 | this */
        "cmpb $0, 0x470(%edx)\n"
        "je .Lf19ca0_0001a4cb\n"
        "movb $0, 0x470(%edx)\n" /* line 4833 */
        "movl %edx, %eax\n" /* line 4834 */
        "addl $0x3f0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "subl $0x40, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %ebx\n"
        "addl $0x430, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        ".Lf19ca0_0001a4a5:\n"
        "leal -0xb8(%ebp), %eax\n" /* line 4958 | NewMatrix */
        "movl %esi, 8(%esp)\n" /* IsProjected */
        "movl %ebx, 4(%esp)\n" /* UseOutputTexTransform */
        "movl %eax, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        "jmp .Lf19ca0_0001a2cb\n"
        ".Lf19ca0_0001a4c0:\n"
        "leal 0x430(%edx), %ebx\n" /* UseOutputTexTransform */
        "jmp .Lf19ca0_0001a405\n"
        ".Lf19ca0_0001a4cb:\n"
        "leal 0x430(%edx), %ebx\n" /* UseOutputTexTransform */
        "jmp .Lf19ca0_0001a4a5\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19ca0_0001a4d3:\n"
        "movb $0, 0x470(%edx)\n" /* line 4833 */
        "movl %edx, %eax\n" /* line 4834 */
        "addl $0x3f0, %eax\n"
        "movl %eax, 8(%esp)\n"
        "subl $0x40, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, %ebx\n"
        "addl $0x430, %ebx\n"
        "movl %ebx, (%esp)\n"
        "calll D3DXMatrixMultiply\n"
        "jmp .Lf19ca0_00019ed5\n"
        /* } scope */
        /* { scope 2 */
        ".Lf19ca0_0001a501:\n"
        "movl %eax, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
        "jmp .Lf19ca0_0001a501\n"
        "jmp .Lf19ca0_0001a501\n"
    );
}

/* line 138 */
__attribute__((naked))
void ZN15CDirect3DDeviceD0Ev(void) /* CDirect3DDevice_~CDirect3DDevice */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DDevice, (%ebx)\n" /* this */
        "movl 0xec(%ebx), %edx\n" /* line 143 | this */
        "testl %edx, %edx\n"
        "je .Lf1a50e_0001a531\n"
        "movl (%edx), %eax\n" /* line 145 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a50e_0001a531:\n"
        "movl 0x1c(%ebx), %edx\n" /* line 148 | this */
        "testl %edx, %edx\n"
        "je .Lf1a50e_0001a540\n"
        "movl (%edx), %eax\n" /* line 150 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a50e_0001a540:\n"
        "movl 0x18(%ebx), %edx\n" /* line 153 | this */
        "testl %edx, %edx\n"
        "je .Lf1a50e_0001a54f\n"
        "movl (%edx), %eax\n" /* line 155 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a50e_0001a54f:\n"
        "movl 0xf0(%ebx), %edx\n" /* line 158 | this */
        "testl %edx, %edx\n"
        "je .Lf1a50e_0001a561\n"
        "movl (%edx), %eax\n" /* line 160 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a50e_0001a561:\n"
        "movl 0xf4(%ebx), %edx\n" /* line 164 | this */
        "testl %edx, %edx\n"
        "je .Lf1a50e_0001a573\n"
        "movl (%edx), %eax\n" /* line 166 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a50e_0001a573:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 173 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_Shutdown\n"
        "leal 8(%ebx), %eax\n" /* line 176 | this */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_ReleaseContext\n"
        "leal 0x608(%ebx), %ecx\n" /* line 182 | this */
        /* { scope 1 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x608(%ebx), %eax\n" /* this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf1a50e_0001a5a7\n"
        ".Lf1a50e_0001a59e:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1a50e_0001a59e\n"
        /* } scope */
        ".Lf1a50e_0001a5a7:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1a50e_0001a5b5\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf1a50e_0001a5b5:\n"
        "movl %ebx, 8(%ebp)\n" /* line 182 | this */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "jmp __ZdlPv\n"
        "movl %eax, %esi\n"
        "leal 0x608(%ebx), %ecx\n" /* this */
        /* { scope 1 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x608(%ebx), %eax\n" /* this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf1a50e_0001a5e1\n"
        ".Lf1a50e_0001a5d8:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1a50e_0001a5d8\n"
        /* } scope */
        ".Lf1a50e_0001a5e1:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1a50e_0001a5ef\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf1a50e_0001a5ef:\n"
        "movl %esi, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
    );
}

/* line 747 */
__attribute__((naked))
HRESULT CDirect3DDevice_Reset(const CDirect3DDevice * _this, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 747 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x14c, %esp\n"
        "movl 8(%ebp), %esi\n" /* this */
        /* { scope 1: L, VideoMemory, TextureMemory */
        "movl 0xc(%ebp), %eax\n" /* line 769 | pPresentationParameters */
        "movl 8(%eax), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf1a5f8_0001a760\n"
        ".Lf1a5f8_0001a615:\n"
        "movl 8(%esi), %eax\n" /* line 827 | this */
        "testl %eax, %eax\n"
        "je .Lf1a5f8_0001a641\n"
        "movl $0x405, (%esp)\n" /* line 829 */
        "calll glDrawBuffer\n"
        "movl $0x405, (%esp)\n" /* line 830 */
        "calll glReadBuffer\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 834 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_Shutdown\n"
        ".Lf1a5f8_0001a641:\n"
        "movl 0x1c(%esi), %edx\n" /* line 838 | this */
        "testl %edx, %edx\n"
        "je .Lf1a5f8_0001a650\n"
        "movl (%edx), %eax\n" /* line 840 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a5f8_0001a650:\n"
        "movl 0x20(%esi), %edx\n" /* line 842 | this */
        "testl %edx, %edx\n"
        "je .Lf1a5f8_0001a65f\n"
        "movl (%edx), %eax\n" /* line 844 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a5f8_0001a65f:\n"
        "movl 0xf0(%esi), %edx\n" /* line 847 | this */
        "testl %edx, %edx\n"
        "je .Lf1a5f8_0001a671\n"
        "movl (%edx), %eax\n" /* line 849 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a5f8_0001a671:\n"
        "movl 0xf4(%esi), %edx\n" /* line 853 | this */
        "testl %edx, %edx\n"
        "je .Lf1a5f8_0001a683\n"
        "movl (%edx), %eax\n" /* line 855 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a5f8_0001a683:\n"
        "movl 0xec(%esi), %edx\n" /* line 859 | this */
        "testl %edx, %edx\n"
        "je .Lf1a5f8_0001a695\n"
        "movl (%edx), %eax\n" /* line 861 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1a5f8_0001a695:\n"
        "movl $0, 0xbb4(%esi)\n" /* line 865 | this */
        "movl $0, 0xbb8(%esi)\n" /* line 866 | this */
        "movl $0, 0xbbc(%esi)\n" /* line 867 | this */
        "leal 0xbcc(%esi), %eax\n" /* line 868 | this */
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl 0xc(%ebp), %ecx\n" /* line 871 | pPresentationParameters */
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x128(%ebp)\n" /* Width */
        "movl 0xc(%ebp), %eax\n" /* line 872 | pPresentationParameters */
        "movl 4(%eax), %eax\n"
        "movl %eax, -0x124(%ebp)\n" /* Height */
        "movl $0, (%esp)\n" /* line 875 */
        "calll MacDisplay_FadeOut\n"
        "movl 8(%esi), %eax\n" /* line 878 | this */
        "testl %eax, %eax\n"
        "je .Lf1a5f8_0001a706\n"
        "leal 8(%esi), %eax\n" /* line 880 | this */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_ReleaseContext\n"
        ".Lf1a5f8_0001a706:\n"
        "movl 0xc(%ebp), %edx\n" /* line 885 | pPresentationParameters */
        "movl 8(%edx), %eax\n"
        "subl $0x15, %eax\n"
        "cmpl $1, %eax\n"
        "jbe .Lf1a5f8_0001a78c\n"
        "movl 0x30(%edx), %eax\n" /* line 891 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x10, 8(%esp)\n"
        ".Lf1a5f8_0001a723:\n"
        "movl -0x124(%ebp), %ecx\n" /* Height */
        "movl %ecx, 4(%esp)\n"
        "movl -0x128(%ebp), %eax\n" /* Width */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_SetMode\n"
        "movl 0xc(%ebp), %edx\n" /* line 900 | pPresentationParameters */
        "movl 0x28(%edx), %eax\n"
        "subl $0x46, %eax\n"
        "cmpl $0xa, %eax\n"
        "ja .Lf1a5f8_0001a750\n"
        "jmpl *.Ljt_2ee7b4(, %eax, 4)\n"
        ".pushsection .rodata\n"
        ".align 4\n"
        ".Ljt_2ee7b4:\n"
        ".long .Lf1a5f8_0001b0cf\n"
        ".long .Lf1a5f8_0001a79d\n"
        ".long .Lf1a5f8_0001a750\n"
        ".long .Lf1a5f8_0001a750\n"
        ".long .Lf1a5f8_0001a750\n"
        ".long .Lf1a5f8_0001b0d9\n"
        ".long .Lf1a5f8_0001a750\n"
        ".long .Lf1a5f8_0001b0d9\n"
        ".long .Lf1a5f8_0001a750\n"
        ".long .Lf1a5f8_0001a750\n"
        ".long .Lf1a5f8_0001b0cf\n"
        ".popsection\n"
        /* { scope 2: TexStage */
        ".Lf1a5f8_0001a750:\n"
        "movl $0x88760869, %eax\n" /* line 99 */
        /* } scope */
        /* } scope */
        ".Lf1a5f8_0001a755:\n"
        "addl $0x14c, %esp\n" /* line 1108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: L, VideoMemory, TextureMemory */
        /* { scope 2: TexStage */
        ".Lf1a5f8_0001a760:\n"
        "leal -0x24(%ebp), %eax\n" /* line 772 | VideoMemory */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %eax\n" /* TextureMemory */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetCurrentDimensions\n"
        "movl -0x20(%ebp), %eax\n" /* line 776 | TextureMemory */
        "movl 0xc(%ebp), %edx\n" /* pPresentationParameters */
        "movl %eax, (%edx)\n"
        "movl -0x24(%ebp), %eax\n" /* line 777 | VideoMemory */
        "movl %eax, 4(%edx)\n"
        "movl $0x16, 8(%edx)\n" /* line 778 */
        "jmp .Lf1a5f8_0001a615\n"
        /* } scope */
        ".Lf1a5f8_0001a78c:\n"
        "movl 0x30(%edx), %eax\n" /* line 887 */
        "movl %eax, 0xc(%esp)\n"
        "movl $0x20, 8(%esp)\n"
        "jmp .Lf1a5f8_0001a723\n"
        ".Lf1a5f8_0001a79d:\n"
        "movl $0x20, %edx\n" /* line 900 */
        ".Lf1a5f8_0001a7a2:\n"
        "leal -0x19(%ebp), %eax\n" /* line 925 | hasAuxBuffer */
        "movl %eax, 0x14(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* pPresentationParameters */
        "movl 0x34(%ecx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl 0x14(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ecx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movzbl 0x24(%ecx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll MacDisplay_CreateScreenContext\n"
        "movl %eax, 8(%esi)\n" /* this */
        "testl %eax, %eax\n" /* line 927 */
        "je .Lf1a5f8_0001b106\n"
        "calll MacDisplay_GetMaxTextureUnits\n" /* line 938 */
        "movl %eax, 0x504(%esi)\n" /* this */
        "calll MacDisplay_GetMaxTextureImageUnits\n" /* line 939 */
        "movl %eax, 0x508(%esi)\n" /* this */
        "movl %eax, 0xc(%esp)\n" /* line 943 */
        "movl 0x504(%esi), %eax\n" /* this */
        "movl %eax, 8(%esp)\n"
        "movl $2, 4(%esp)\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n"
        "movl %eax, (%esp)\n"
        "calll COpenGL_Init\n"
        "movl 8(%esi), %eax\n" /* line 946 | this */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_SwapContext\n"
        "movl $0x3e4ccccd, (%esp)\n" /* line 947 */
        "calll MacDisplay_FadeIn\n"
        "leal 0x608(%esi), %ebx\n" /* line 949 | this */
        "leal 0x60c(%esi), %ecx\n" /* line 352 */
        "movl %ecx, -0x11c(%ebp)\n"
        "movl 0x60c(%esi), %eax\n"
        "movl 0x608(%esi), %edx\n" /* line 334 */
        "movl %eax, 8(%esp)\n" /* line 749 */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_\n"
        "leal 0x504(%esi), %edx\n" /* this */
        "leal 0x508(%esi), %ecx\n" /* this */
        /* { scope 2: TexStage */
        "movl 0x504(%esi), %eax\n" /* line 211 */
        "cmpl 0x508(%esi), %eax\n"
        "cmovbl %ecx, %edx\n"
        /* } scope */
        "movl (%edx), %edx\n" /* line 950 | __b */
        "movl %edx, -0x120(%ebp)\n" /* __b, TotalStages */
        /* { scope 2: TexStage */
        "testl %edx, %edx\n" /* line 951 */
        "je .Lf1a5f8_0001a8e4\n"
        "xorl %edi, %edi\n" /* i */
        /* { scope 3 */
        ".Lf1a5f8_0001a883:\n"
        "xorl %eax, %eax\n" /* line 954 */
        "cmpl 0x504(%esi), %edi\n" /* this, i */
        "setae %al\n"
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* i */
        "leal -0x110(%ebp), %eax\n" /* L */
        "movl %eax, (%esp)\n"
        "calll CDirect3DDevice_CTexStage_Init\n"
        "movl 4(%ebx), %eax\n" /* line 604 */
        "cmpl 8(%ebx), %eax\n"
        "je .Lf1a5f8_0001b0e3\n"
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf1a5f8_0001a8d1\n"
        "movl $0xa4, 8(%esp)\n"
        "leal -0x110(%ebp), %edx\n" /* L */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 4(%ebx), %eax\n"
        ".Lf1a5f8_0001a8d1:\n"
        "addl $0xa4, %eax\n" /* line 607 */
        "movl %eax, 4(%ebx)\n"
        /* } scope */
        ".Lf1a5f8_0001a8d9:\n"
        "addl $1, %edi\n" /* line 951 | i */
        "cmpl %edi, -0x120(%ebp)\n" /* i, TotalStages */
        "jne .Lf1a5f8_0001a883\n"
        /* } scope */
        ".Lf1a5f8_0001a8e4:\n"
        "movl imp_g_NoTextureID, %ebx\n" /* line 964 */
        "movb $1, (%ebx)\n"
        "movl (%esi), %edx\n" /* line 965 | this */
        "movl $0, 0x20(%esp)\n"
        "leal 0x1c(%esi), %eax\n" /* this */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "movl $0, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl 0xc(%ebp), %ecx\n" /* pPresentationParameters */
        "movl 8(%ecx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x124(%ebp), %eax\n" /* Height */
        "movl %eax, 8(%esp)\n"
        "movl -0x128(%ebp), %ecx\n" /* Width */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll *0x70(%edx)\n"
        "movb $0, (%ebx)\n" /* line 966 */
        "movl (%esi), %edx\n" /* line 970 | this */
        "movl $0, 0x20(%esp)\n"
        "leal 0xf0(%esi), %eax\n" /* this */
        "movl %eax, 0x1c(%esp)\n"
        "movl $1, 0x18(%esp)\n"
        "movl $0x15, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $1, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* this */
        "calll *0x5c(%edx)\n"
        "movl 0xf0(%esi), %edx\n" /* line 972 | this */
        "movl (%edx), %ecx\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0, 0xc(%esp)\n"
        "leal -0x2c(%ebp), %eax\n" /* Rect */
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x4c(%ecx)\n"
        "movl -0x28(%ebp), %eax\n" /* line 973 */
        "movl $0xff, (%eax)\n"
        "movl 0xf0(%esi), %eax\n" /* line 974 | this */
        "movl (%eax), %edx\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x50(%edx)\n"
        /* { scope 2: TexStage */
        "movl -0x120(%ebp), %eax\n" /* line 979 | TotalStages */
        "testl %eax, %eax\n"
        "je .Lf1a5f8_0001aa36\n"
        "xorl %ebx, %ebx\n" /* i */
        "movl imp___ZN7COpenGL7sOpenGLE, %edi\n" /* i */
        ".Lf1a5f8_0001a9e5:\n"
        "movl 0xf0(%esi), %eax\n" /* line 981 | this */
        "testl %eax, %eax\n"
        "je .Lf1a5f8_0001aa13\n"
        "movl $0xfffffffe, 0xc(%esp)\n"
        "movl imp___ZTI14COpenGLTexture, %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl imp___ZTI17IDirect3DTexture9, %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ___dynamic_cast\n"
        ".Lf1a5f8_0001aa13:\n"
        "movl %eax, 0xc(%esp)\n"
        "movl $0xde1, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %edi, (%esp)\n" /* i */
        "calll COpenGL_SetTex\n"
        "addl $1, %ebx\n" /* line 979 | i */
        "cmpl %ebx, -0x120(%ebp)\n" /* i, TotalStages */
        "jne .Lf1a5f8_0001a9e5\n"
        /* } scope */
        ".Lf1a5f8_0001aa36:\n"
        "movl $0xc, (%esp)\n" /* line 985 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n" /* i */
        "movl %eax, (%esp)\n"
        "calll CDirect3DSwapChain_CDirect3DSwapChain\n"
        "movl %ebx, 0xec(%esi)\n" /* i, this */
        "movl 0x1c(%esi), %eax\n" /* line 986 | this */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* i */
        "calll CDirect3DSwapChain_SetBackBuffer\n"
        "movl 0x1c(%esi), %eax\n" /* line 988 | this */
        "movl %eax, 0x14(%esi)\n" /* this */
        "movl 0x20(%esi), %eax\n" /* line 989 | this */
        "movl %eax, 0x18(%esi)\n" /* this */
        "leal 0x24(%esi), %edi\n" /* line 991 | this, i */
        "cld\n"
        "movl $0x10, %edx\n"
        "movl %edx, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* i */
        "leal 0x64(%esi), %edi\n" /* line 992 | this, i */
        "movl %edx, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* i */
        "movl $0, 0xa4(%esi)\n" /* line 994 | this */
        "movl $0xffffffff, 0xa8(%esi)\n" /* line 995 | this */
        "leal 0xac(%esi), %edi\n" /* line 996 | this, i */
        "movl %edx, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* i */
        "movl $1, 0x398(%esi)\n" /* line 997 | this */
        "movl $1, 0x394(%esi)\n" /* this */
        "movl $0, 0x3a0(%esi)\n" /* line 998 | this */
        "movl $0, 0x39c(%esi)\n" /* this */
        "movl $0, 0x3a8(%esi)\n" /* line 999 | this */
        "movl $0x207, 0x3ac(%esi)\n" /* line 1000 | this */
        /* { scope 2: TexStage */
        "leal -0x6c(%ebp), %eax\n" /* line 97 | m */
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "movl -0x6c(%ebp), %eax\n" /* line 1004 | m */
        "movl %eax, 0x3b0(%esi)\n" /* this */
        "movl -0x68(%ebp), %edx\n"
        "movl %edx, 0x3b4(%esi)\n" /* this */
        "movl -0x64(%ebp), %ecx\n"
        "movl %ecx, 0x3b8(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x3bc(%esi)\n" /* this */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, 0x3c0(%esi)\n" /* this */
        "movl -0x58(%ebp), %ecx\n"
        "movl %ecx, 0x3c4(%esi)\n" /* this */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x3c8(%esi)\n" /* this */
        "movl -0x50(%ebp), %edx\n"
        "movl %edx, 0x3cc(%esi)\n" /* this */
        "movl -0x4c(%ebp), %ecx\n"
        "movl %ecx, 0x3d0(%esi)\n" /* this */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x3d4(%esi)\n" /* this */
        "movl -0x44(%ebp), %edi\n" /* i */
        "movl %edi, 0x3d8(%esi)\n" /* i, this */
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0x3dc(%esi)\n" /* this */
        "movl -0x3c(%ebp), %ebx\n" /* i */
        "movl %ebx, 0x3e0(%esi)\n" /* i, this */
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, 0x3e4(%esi)\n" /* this */
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, 0x3e8(%esi)\n" /* this */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x3ec(%esi)\n" /* this */
        "movl -0x6c(%ebp), %eax\n" /* line 1005 | m */
        "movl %eax, 0x3f0(%esi)\n" /* this */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x3f4(%esi)\n" /* this */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x3f8(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x3fc(%esi)\n" /* this */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x400(%esi)\n" /* this */
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x404(%esi)\n" /* this */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x408(%esi)\n" /* this */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x40c(%esi)\n" /* this */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x410(%esi)\n" /* this */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x414(%esi)\n" /* this */
        "movl %edi, 0x418(%esi)\n" /* i, this */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x41c(%esi)\n" /* this */
        "movl %ebx, 0x420(%esi)\n" /* i, this */
        "movl %ecx, 0x424(%esi)\n" /* this */
        "movl %edx, 0x428(%esi)\n" /* this */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x42c(%esi)\n" /* this */
        "movl -0x6c(%ebp), %eax\n" /* line 1006 | m */
        "movl %eax, 0x430(%esi)\n" /* this */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x434(%esi)\n" /* this */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x438(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x43c(%esi)\n" /* this */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x440(%esi)\n" /* this */
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x444(%esi)\n" /* this */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x448(%esi)\n" /* this */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x44c(%esi)\n" /* this */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x450(%esi)\n" /* this */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x454(%esi)\n" /* this */
        "movl %edi, 0x458(%esi)\n" /* i, this */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x45c(%esi)\n" /* this */
        "movl %ebx, 0x460(%esi)\n" /* i, this */
        "movl %ecx, 0x464(%esi)\n" /* this */
        "movl %edx, 0x468(%esi)\n" /* this */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x46c(%esi)\n" /* this */
        "movb $1, 0x470(%esi)\n" /* line 1007 | this */
        "movl -0x6c(%ebp), %eax\n" /* line 1008 | m */
        "movl %eax, 0x474(%esi)\n" /* this */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x478(%esi)\n" /* this */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x47c(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x480(%esi)\n" /* this */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x484(%esi)\n" /* this */
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x488(%esi)\n" /* this */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x48c(%esi)\n" /* this */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x490(%esi)\n" /* this */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x494(%esi)\n" /* this */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x498(%esi)\n" /* this */
        "movl %edi, 0x49c(%esi)\n" /* i, this */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x4a0(%esi)\n" /* this */
        "movl %ebx, 0x4a4(%esi)\n" /* i, this */
        "movl %ecx, 0x4a8(%esi)\n" /* this */
        "movl %edx, 0x4ac(%esi)\n" /* this */
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 0x4b0(%esi)\n" /* this */
        "movb $1, 0x4b4(%esi)\n" /* line 1009 | this */
        "movl -0x6c(%ebp), %eax\n" /* line 1010 | m */
        "movl %eax, 0x4b8(%esi)\n" /* this */
        "movl -0x68(%ebp), %eax\n"
        "movl %eax, 0x4bc(%esi)\n" /* this */
        "movl -0x64(%ebp), %eax\n"
        "movl %eax, 0x4c0(%esi)\n" /* this */
        "movl -0x60(%ebp), %eax\n"
        "movl %eax, 0x4c4(%esi)\n" /* this */
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 0x4c8(%esi)\n" /* this */
        "movl -0x58(%ebp), %eax\n"
        "movl %eax, 0x4cc(%esi)\n" /* this */
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, 0x4d0(%esi)\n" /* this */
        "movl -0x50(%ebp), %eax\n"
        "movl %eax, 0x4d4(%esi)\n" /* this */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 0x4d8(%esi)\n" /* this */
        "movl -0x48(%ebp), %eax\n"
        "movl %eax, 0x4dc(%esi)\n" /* this */
        "movl %edi, 0x4e0(%esi)\n" /* i, this */
        "movl -0x40(%ebp), %eax\n"
        "movl %eax, 0x4e4(%esi)\n" /* this */
        "movl %ebx, 0x4e8(%esi)\n" /* i, this */
        "movl %ecx, 0x4ec(%esi)\n" /* this */
        "movl %edx, 0x4f0(%esi)\n" /* this */
        "movl -0x30(%ebp), %edx\n"
        "movl %edx, 0x4f4(%esi)\n" /* this */
        "movl $0, 0x4f8(%esi)\n" /* line 1011 | this */
        "movl $0, 0x4fc(%esi)\n" /* line 1012 | this */
        "movl $0, 0x500(%esi)\n" /* line 1013 | this */
        "movl $0, 0x50c(%esi)\n" /* line 1016 | this */
        "movl $0, 0x510(%esi)\n" /* line 1017 | this */
        "movl $8, 0x514(%esi)\n" /* line 1018 | this */
        "movb $1, 0x518(%esi)\n" /* line 1019 | this */
        "movl $2, 0x51c(%esi)\n" /* line 1020 | this */
        "movl $2, 0x520(%esi)\n" /* line 1021 | this */
        "movl $1, 0x524(%esi)\n" /* line 1022 | this */
        "movl $1, 0x528(%esi)\n" /* line 1023 | this */
        "movl $1, 0x52c(%esi)\n" /* line 1024 | this */
        "movl $0, 0x530(%esi)\n" /* line 1025 | this */
        "movl $1, 0x534(%esi)\n" /* line 1026 | this */
        "movl $1, 0x538(%esi)\n" /* line 1027 | this */
        "movl $1, 0x53c(%esi)\n" /* line 1028 | this */
        "movl $4, 0x540(%esi)\n" /* line 1029 | this */
        "movl $1, 0x544(%esi)\n" /* line 1030 | this */
        "movl $0, 0x548(%esi)\n" /* line 1031 | this */
        "movl $0, 0x54c(%esi)\n" /* line 1032 | this */
        "movl $0, 0x550(%esi)\n" /* line 1033 | this */
        "movl $0, 0x554(%esi)\n" /* line 1034 | this */
        "movl $1, 0x558(%esi)\n" /* line 1035 | this */
        "movl $1, 0x55c(%esi)\n" /* line 1036 | this */
        "movl $1, 0x560(%esi)\n" /* line 1037 | this */
        "movl $8, 0x564(%esi)\n" /* line 1038 | this */
        "movl $0x207, 0x568(%esi)\n" /* line 1039 | this */
        "movl $0, 0x56c(%esi)\n" /* line 1040 | this */
        "movl $0xffffffff, 0x570(%esi)\n" /* line 1041 | this */
        "movl $0xffffffff, 0x574(%esi)\n" /* line 1042 | this */
        "movl $0xffffffff, 0x578(%esi)\n" /* line 1043 | this */
        "movl $0, 0x57c(%esi)\n" /* line 1044 | this */
        "movl $0, 0x580(%esi)\n" /* line 1045 | this */
        "movl $1, 0x584(%esi)\n" /* line 1046 | this */
        "movl $3, 0x588(%esi)\n" /* line 1047 | this */
        "movl $2, 0x58c(%esi)\n" /* line 1048 | this */
        "movl $0xf, 0x590(%esi)\n" /* line 1049 | this */
        "movl $1, 0x594(%esi)\n" /* line 1050 | this */
        "movl $1, 0x598(%esi)\n" /* line 1051 | this */
        "movl $0, 0xbc8(%esi)\n" /* line 1052 | this */
        "movl $0, 0xbc4(%esi)\n" /* line 1053 | this */
        "movl $0, 0x59c(%esi)\n" /* line 1055 | this */
        "movl $0, 0x5a0(%esi)\n" /* line 1056 | this */
        "movl $0, 0x5a4(%esi)\n" /* line 1057 | this */
        "movl $0, 0x5a8(%esi)\n" /* line 1058 | this */
        "leal 0x5ac(%esi), %eax\n" /* line 1060 | this */
        "movl $0x44, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x5f0(%esi), %edi\n" /* line 1061 | this, i */
        "cld\n"
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "rep stosl %eax, %es:(%edi)\n" /* i */
        "movl 0xc(%ebp), %edx\n" /* line 1063 | pPresentationParameters */
        "movl 4(%edx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll glViewport\n"
        "movl $0, 8(%esp)\n" /* line 1064 */
        "movl $0x3ff00000, 0xc(%esp)\n"
        "movl $0, (%esp)\n"
        "movl $0, 4(%esp)\n"
        "calll glDepthRange\n"
        "leal 0x614(%esi), %eax\n" /* line 1067 | this */
        "movl $0x5a0, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl $0x68, 8(%esp)\n" /* line 1069 */
        "movl $0, 4(%esp)\n"
        "leal -0x110(%ebp), %ecx\n" /* L */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl $3, -0x110(%ebp)\n" /* line 1070 | L */
        "xorl %ebx, %ebx\n" /* i */
        /* { scope 3 */
        ".Lf1a5f8_0001b013:\n"
        "movl (%esi), %eax\n" /* line 1074 | this */
        "leal -0x110(%ebp), %edx\n" /* L */
        "movl %edx, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n" /* i */
        "movl %esi, (%esp)\n" /* this */
        "calll *0xcc(%eax)\n"
        "addl $1, %ebx\n" /* line 1072 | i */
        "cmpl $8, %ebx\n" /* i */
        "jne .Lf1a5f8_0001b013\n"
        /* } scope */
        "leal -0x20(%ebp), %eax\n" /* line 1081 | TextureMemory */
        "movl %eax, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* VideoMemory */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_GetVideoMemoryInfo\n"
        "movl -0x24(%ebp), %eax\n" /* line 1082 | VideoMemory */
        "movl %eax, 0x4f8(%esi)\n" /* this */
        "movl -0x20(%ebp), %eax\n" /* line 1083 | TextureMemory */
        "movl %eax, 0x4fc(%esi)\n" /* this */
        "leal 0x500(%esi), %eax\n" /* line 1092 | this */
        "movl %eax, 4(%esp)\n"
        "movl $0xd33, (%esp)\n"
        "calll glGetIntegerv\n"
        "calll MacDisplay_GetGLVendor\n" /* line 1095 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bc0, (%esp)\n" /* "GL_VENDOR = %s" */
        "calll game_dprintf\n"
        "calll MacDisplay_GetGLRenderer\n" /* line 1096 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215bd0, (%esp)\n" /* "GL_RENDERER = %s" */
        "calll game_dprintf\n"
        "calll MacDisplay_GetGLExtensions\n" /* line 1097 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00215be4, (%esp)\n" /* "GL_EXTENSIONS = %s" */
        "calll game_dprintf\n"
        "movb $1, __ZN15CDirect3DDevice28mNeedsVertexShaderValidationE\n" /* line 644 */
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        "addl $0x14c, %esp\n" /* line 1108 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: L, VideoMemory, TextureMemory */
        /* { scope 2: TexStage */
        ".Lf1a5f8_0001b0cf:\n"
        "movl $0x10, %edx\n" /* line 99 */
        "jmp .Lf1a5f8_0001a7a2\n"
        /* } scope */
        ".Lf1a5f8_0001b0d9:\n"
        "movl $0x18, %edx\n" /* line 900 */
        "jmp .Lf1a5f8_0001a7a2\n"
        /* { scope 2: TexStage */
        /* { scope 3 */
        ".Lf1a5f8_0001b0e3:\n"
        "movl -0x11c(%ebp), %ecx\n" /* line 352 */
        "movl (%ecx), %eax\n"
        "leal -0x110(%ebp), %edx\n" /* line 610 | L */
        "movl %edx, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_\n"
        "jmp .Lf1a5f8_0001a8d9\n"
        /* } scope */
        /* } scope */
        ".Lf1a5f8_0001b106:\n"
        "movl $0x3e4ccccd, (%esp)\n" /* line 929 */
        "calll MacDisplay_FadeIn\n"
        "movl $0x88760869, %eax\n"
        "jmp .Lf1a5f8_0001a755\n"
        /* { scope 2: TexStage */
        "movl %eax, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 985 | i */
        "calll __ZdlPv\n"
        "movl %esi, (%esp)\n" /* this */
        "calll __Unwind_Resume\n"
    );
}

/* line 48 */
__attribute__((naked))
long unsigned int CDirect3DDevice_CDirect3DDevice(const CDirect3DDevice * _this, UINT Adapter, D3DDEVTYPE DeviceType, ContextRef Context, D3DPRESENT_PARAMETERS *pPresentationParameters)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 48 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DDevice, (%ebx)\n" /* line 125 | this */
        "movl $0, 4(%ebx)\n" /* this */
        "movl 0x14(%ebp), %eax\n" /* Context */
        "movl %eax, 8(%ebx)\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* Adapter */
        "movl %eax, 0xc(%ebx)\n" /* this */
        "movl 0x10(%ebp), %eax\n" /* DeviceType */
        "movl %eax, 0x10(%ebx)\n" /* this */
        "movl $0, 0x14(%ebx)\n" /* this */
        "movl $0, 0x18(%ebx)\n" /* this */
        "movl $0, 0x1c(%ebx)\n" /* this */
        "movl $0, 0x20(%ebx)\n" /* this */
        "leal 0x24(%ebx), %edi\n" /* this */
        "cld\n"
        "xorl %eax, %eax\n"
        "movl $0x10, %esi\n"
        "movl %esi, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* this */
        "leal 0x64(%ebx), %edi\n" /* this */
        "movl %esi, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* this */
        "movl $0, 0xa4(%ebx)\n" /* this */
        "movl $0xffffffff, 0xa8(%ebx)\n" /* this */
        "leal 0xac(%ebx), %edi\n" /* this */
        "movl %esi, %ecx\n"
        "rep stosl %eax, %es:(%edi)\n" /* this */
        "movl $0, 0xec(%ebx)\n" /* this */
        "movl $0, 0xf0(%ebx)\n" /* this */
        "movl $0, 0xf4(%ebx)\n" /* this */
        "movl $1, 0x394(%ebx)\n" /* this */
        "movl $1, 0x398(%ebx)\n" /* this */
        "movl $0, 0x39c(%ebx)\n" /* this */
        "movl $0, 0x3a0(%ebx)\n" /* this */
        "movl $0, 0x3a8(%ebx)\n" /* this */
        "movl $0x207, 0x3ac(%ebx)\n" /* this */
        "leal 0x3b0(%ebx), %eax\n" /* line 97 | this */
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "leal 0x3f0(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "leal 0x430(%ebx), %eax\n" /* this */
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "movb $1, 0x470(%ebx)\n" /* line 125 | this */
        "leal 0x474(%ebx), %eax\n" /* line 97 | this */
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "movb $1, 0x4b4(%ebx)\n" /* line 125 | this */
        "leal 0x4b8(%ebx), %eax\n" /* line 97 | this */
        "movl %eax, (%esp)\n"
        "calll COpenGLMatrix_SetIdentity\n"
        "movl $0, 0x4f8(%ebx)\n" /* line 125 | this */
        "movl $0, 0x4fc(%ebx)\n" /* this */
        "movl $0, 0x500(%ebx)\n" /* this */
        "movl $0, 0x50c(%ebx)\n" /* this */
        "movl $0, 0x510(%ebx)\n" /* this */
        "movl $8, 0x514(%ebx)\n" /* this */
        "movb $1, 0x518(%ebx)\n" /* this */
        "movl $2, 0x51c(%ebx)\n" /* this */
        "movl $2, 0x520(%ebx)\n" /* this */
        "movl $1, 0x524(%ebx)\n" /* this */
        "movl $1, 0x528(%ebx)\n" /* this */
        "movl $1, 0x52c(%ebx)\n" /* this */
        "movl $0, 0x530(%ebx)\n" /* this */
        "movl $1, 0x534(%ebx)\n" /* this */
        "movl $1, 0x538(%ebx)\n" /* this */
        "movl $1, 0x53c(%ebx)\n" /* this */
        "movl $4, 0x540(%ebx)\n" /* this */
        "movl $1, 0x544(%ebx)\n" /* this */
        "movl $0, 0x548(%ebx)\n" /* this */
        "movl $0, 0x54c(%ebx)\n" /* this */
        "movl $0, 0x550(%ebx)\n" /* this */
        "movl $0, 0x554(%ebx)\n" /* this */
        "movl $1, 0x558(%ebx)\n" /* this */
        "movl $1, 0x55c(%ebx)\n" /* this */
        "movl $1, 0x560(%ebx)\n" /* this */
        "movl $8, 0x564(%ebx)\n" /* this */
        "movl $0x207, 0x568(%ebx)\n" /* this */
        "movl $0, 0x56c(%ebx)\n" /* this */
        "movl $0xffffffff, 0x570(%ebx)\n" /* this */
        "movl $0xffffffff, 0x574(%ebx)\n" /* this */
        "movl $0xffffffff, 0x578(%ebx)\n" /* this */
        "movl $0, 0x57c(%ebx)\n" /* this */
        "movl $0, 0x580(%ebx)\n" /* this */
        "movl $1, 0x584(%ebx)\n" /* this */
        "movl $3, 0x588(%ebx)\n" /* this */
        "movl $2, 0x58c(%ebx)\n" /* this */
        "movl $0xf, 0x590(%ebx)\n" /* this */
        "movl $1, 0x594(%ebx)\n" /* this */
        "movl $1, 0x598(%ebx)\n" /* this */
        "leal 0x5ac(%ebx), %eax\n" /* this */
        "movl $0x44, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "leal 0x608(%ebx), %edi\n" /* this */
        /* { scope 1 */
        "movl $0, 0x608(%ebx)\n" /* line 85 | this */
        "movl $0, 4(%edi)\n"
        "movl $0, 8(%edi)\n"
        "movl $7, %eax\n"
        /* } scope */
        ".Lf1b136_0001b423:\n"
        "subl $1, %eax\n" /* line 125 */
        "cmpl $-1, %eax\n"
        "jne .Lf1b136_0001b423\n"
        "movl $0, 0xbb4(%ebx)\n" /* this */
        "movl $0, 0xbb8(%ebx)\n" /* this */
        "movl $0, 0xbbc(%ebx)\n" /* this */
        "movb $0, 0xbc0(%ebx)\n" /* this */
        "xorl %eax, %eax\n"
        "movl %eax, 0xbc4(%ebx)\n" /* this */
        "movl %eax, 0xbc8(%ebx)\n" /* this */
        "leal 0xbcc(%ebx), %eax\n" /* this */
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl $__ZZN15CDirect3DDeviceC4Ej11_D3DDEVTYPEP16OpaqueContextRefP23_D3DPRESENT_PARAMETERS_E5C.232, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movb $1, __ZN15CDirect3DDevice28mNeedsVertexShaderValidationE\n" /* line 127 */
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 128 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 129 */
        "movl 0x18(%ebp), %eax\n" /* line 131 | pPresentationParameters */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* this */
        "calll CDirect3DDevice_Reset\n"
        "addl $1, 4(%ebx)\n" /* line 203 | this */
        "addl $0x1c, %esp\n" /* line 134 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf1b136_0001b4ac:\n"
        "movl %eax, %ebx\n" /* this */
        ".Lf1b136_0001b4ae:\n"
        "movl %ebx, (%esp)\n" /* line 99 | this */
        "calll __Unwind_Resume\n"
        "movl %eax, %ebx\n" /* this */
        "movl 4(%edi), %ecx\n" /* line 273 | this, __last */
        "movl (%edi), %edx\n" /* this */
        "movl %edx, %eax\n"
        /* { scope 1 */
        "cmpl %edx, %ecx\n" /* line 173 */
        "je .Lf1b136_0001b4cc\n"
        ".Lf1b136_0001b4c3:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %ecx\n"
        "jne .Lf1b136_0001b4c3\n"
        /* } scope */
        ".Lf1b136_0001b4cc:\n"
        "testl %edx, %edx\n" /* line 122 */
        "je .Lf1b136_0001b4ae\n"
        "movl %edx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        "jmp .Lf1b136_0001b4ae\n"
        "jmp .Lf1b136_0001b4ac\n"
        "jmp .Lf1b136_0001b4ac\n"
    );
}

/* overload skip: CDirect3DDevice_CDirect3DDevice (0x1b4de) */

/* line 138 */
__attribute__((naked))
void ZN15CDirect3DDeviceD2Ev(void) /* CDirect3DDevice_~CDirect3DDevice */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DDevice, (%ebx)\n" /* this */
        "movl 0xec(%ebx), %edx\n" /* line 143 | this */
        "testl %edx, %edx\n"
        "je .Lf1b886_0001b8a9\n"
        "movl (%edx), %eax\n" /* line 145 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b886_0001b8a9:\n"
        "movl 0x1c(%ebx), %edx\n" /* line 148 | this */
        "testl %edx, %edx\n"
        "je .Lf1b886_0001b8b8\n"
        "movl (%edx), %eax\n" /* line 150 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b886_0001b8b8:\n"
        "movl 0x18(%ebx), %edx\n" /* line 153 | this */
        "testl %edx, %edx\n"
        "je .Lf1b886_0001b8c7\n"
        "movl (%edx), %eax\n" /* line 155 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b886_0001b8c7:\n"
        "movl 0xf0(%ebx), %edx\n" /* line 158 | this */
        "testl %edx, %edx\n"
        "je .Lf1b886_0001b8d9\n"
        "movl (%edx), %eax\n" /* line 160 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b886_0001b8d9:\n"
        "movl 0xf4(%ebx), %edx\n" /* line 164 | this */
        "testl %edx, %edx\n"
        "je .Lf1b886_0001b8eb\n"
        "movl (%edx), %eax\n" /* line 166 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b886_0001b8eb:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 173 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_Shutdown\n"
        "leal 8(%ebx), %eax\n" /* line 176 | this */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_ReleaseContext\n"
        "leal 0x608(%ebx), %ecx\n" /* line 182 | this */
        /* { scope 1 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x608(%ebx), %eax\n" /* this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf1b886_0001b91f\n"
        ".Lf1b886_0001b916:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1b886_0001b916\n"
        /* } scope */
        ".Lf1b886_0001b91f:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1b886_0001b933\n"
        /* { scope 2 */
        "movl %eax, 8(%ebp)\n" /* line 94 | this */
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp __ZdlPv\n" /* line 94 */
        /* } scope */
        /* } scope */
        ".Lf1b886_0001b933:\n"
        "addl $0x10, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %esi\n"
        "leal 0x608(%ebx), %ecx\n" /* this */
        /* { scope 1 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x608(%ebx), %eax\n" /* this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf1b886_0001b958\n"
        ".Lf1b886_0001b94f:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1b886_0001b94f\n"
        /* } scope */
        ".Lf1b886_0001b958:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1b886_0001b966\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf1b886_0001b966:\n"
        "movl %esi, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
    );
}

/* line 138 */
__attribute__((naked))
void ZN15CDirect3DDeviceD1Ev(void) /* CDirect3DDevice_~CDirect3DDevice */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 138 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ebx\n" /* this */
        "movl $vtbl_CDirect3DDevice, (%ebx)\n" /* this */
        "movl 0xec(%ebx), %edx\n" /* line 143 | this */
        "testl %edx, %edx\n"
        "je .Lf1b96e_0001b991\n"
        "movl (%edx), %eax\n" /* line 145 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b96e_0001b991:\n"
        "movl 0x1c(%ebx), %edx\n" /* line 148 | this */
        "testl %edx, %edx\n"
        "je .Lf1b96e_0001b9a0\n"
        "movl (%edx), %eax\n" /* line 150 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b96e_0001b9a0:\n"
        "movl 0x18(%ebx), %edx\n" /* line 153 | this */
        "testl %edx, %edx\n"
        "je .Lf1b96e_0001b9af\n"
        "movl (%edx), %eax\n" /* line 155 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b96e_0001b9af:\n"
        "movl 0xf0(%ebx), %edx\n" /* line 158 | this */
        "testl %edx, %edx\n"
        "je .Lf1b96e_0001b9c1\n"
        "movl (%edx), %eax\n" /* line 160 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b96e_0001b9c1:\n"
        "movl 0xf4(%ebx), %edx\n" /* line 164 | this */
        "testl %edx, %edx\n"
        "je .Lf1b96e_0001b9d3\n"
        "movl (%edx), %eax\n" /* line 166 */
        "movl %edx, (%esp)\n"
        "calll *8(%eax)\n"
        ".Lf1b96e_0001b9d3:\n"
        "movl imp___ZN7COpenGL7sOpenGLE, %eax\n" /* line 173 */
        "movl %eax, (%esp)\n"
        "calll COpenGL_Shutdown\n"
        "leal 8(%ebx), %eax\n" /* line 176 | this */
        "movl %eax, (%esp)\n"
        "calll MacDisplay_ReleaseContext\n"
        "leal 0x608(%ebx), %ecx\n" /* line 182 | this */
        /* { scope 1 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x608(%ebx), %eax\n" /* this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf1b96e_0001ba07\n"
        ".Lf1b96e_0001b9fe:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1b96e_0001b9fe\n"
        /* } scope */
        ".Lf1b96e_0001ba07:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1b96e_0001ba1b\n"
        /* { scope 2 */
        "movl %eax, 8(%ebp)\n" /* line 94 | this */
        /* } scope */
        /* } scope */
        "addl $0x10, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        /* { scope 1 */
        /* { scope 2 */
        "jmp __ZdlPv\n" /* line 94 */
        /* } scope */
        /* } scope */
        ".Lf1b96e_0001ba1b:\n"
        "addl $0x10, %esp\n" /* line 182 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        "movl %eax, %esi\n"
        "leal 0x608(%ebx), %ecx\n" /* this */
        /* { scope 1 */
        "movl 4(%ecx), %edx\n" /* line 273 | __last */
        "movl 0x608(%ebx), %eax\n" /* this */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 173 */
        "je .Lf1b96e_0001ba40\n"
        ".Lf1b96e_0001ba37:\n"
        "addl $0xa4, %eax\n"
        "cmpl %eax, %edx\n"
        "jne .Lf1b96e_0001ba37\n"
        /* } scope */
        ".Lf1b96e_0001ba40:\n"
        "movl (%ecx), %eax\n" /* line 109 */
        "testl %eax, %eax\n" /* line 122 */
        "je .Lf1b96e_0001ba4e\n"
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        /* } scope */
        /* } scope */
        ".Lf1b96e_0001ba4e:\n"
        "movl %esi, (%esp)\n" /* line 99 */
        "calll __Unwind_Resume\n"
    );
}

/* line 4421 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreatePixelShaderOpenGL(const CDirect3DDevice * _this, OpenGLPixelShaderType ShaderType, const long unsigned int *pSrcData, IDirect3DPixelShader9 * *ppShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4421 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x43c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* ShaderType */
        /* { scope 1: MyError */
        "leal -0x1c(%ebp), %eax\n" /* line 4426 */
        "movl %eax, 8(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* pSrcData */
        "movl %eax, 4(%esp)\n"
        "leal -0x20(%ebp), %esi\n" /* shaderNameAndCode */
        "movl %esi, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl $2, 0xc(%esp)\n" /* line 1570 */
        "movl $0, 8(%esp)\n"
        "movl $str_00215bf8, 4(%esp)\n" /* "::" */
        "movl %esi, (%esp)\n"
        "calll __ZNKSs4findEPKcmm\n"
        "movl %eax, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* line 591 | shaderNameAndCode */
        "movl -0xc(%eax), %eax\n"
        "leal 2(%ebx), %edx\n" /* line 4428 */
        /* { scope 2 */
        "cmpl %eax, %edx\n" /* line 299 */
        "ja .Lf1ba56_0001bbef\n"
        "movl %eax, 0xc(%esp)\n" /* line 1899 */
        "movl %edx, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x24(%ebp), %eax\n" /* shaderCode */
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1ERKSsmm\n"
        /* } scope */
        "movl %ebx, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "leal -0x28(%ebp), %esi\n" /* shaderName */
        "movl %esi, (%esp)\n"
        "calll __ZNSsC1ERKSsmm\n"
        "cmpl $1, %edi\n" /* line 4431 | ShaderType */
        "je .Lf1ba56_0001bbc6\n"
        "cmpl $2, %edi\n" /* ShaderType */
        "je .Lf1ba56_0001bba0\n"
        "testl %edi, %edi\n" /* ShaderType */
        "jne .Lf1ba56_0001bb1b\n"
        "movl $0x10, (%esp)\n" /* line 4434 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* pSrcData */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGLATITextFragmentShader_COpenGLATITextFragmentShader\n"
        ".Lf1ba56_0001bb16:\n"
        "movl 0x14(%ebp), %eax\n" /* line 4440 | ppShader */
        "movl %ebx, (%eax)\n"
        ".Lf1ba56_0001bb1b:\n"
        "leal -0x2c(%ebp), %eax\n" /* line 4447 | ErrorPosition */
        "movl %eax, 4(%esp)\n"
        "movl $0x864b, (%esp)\n"
        "calll glGetIntegerv\n"
        "cmpl $-1, -0x2c(%ebp)\n" /* line 4450 | ErrorPosition */
        "je .Lf1ba56_0001bbe8\n"
        /* { scope 2 */
        "movl $0x8874, (%esp)\n" /* line 4452 */
        "calll glGetString\n"
        "movl %eax, 8(%esp)\n" /* line 4455 */
        "movl $str_00215bbc, 4(%esp)\n" /* "%s
" */
        "leal -0x42c(%ebp), %eax\n" /* MyError */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "movl $0x8876086c, %edi\n" /* hr */
        /* } scope */
        ".Lf1ba56_0001bb63:\n"
        "movl -0x28(%ebp), %eax\n" /* line 277 | shaderName */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 2 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %esi\n" /* line 178 */
        "cmpl %esi, %ebx\n" /* line 224 */
        "jne .Lf1ba56_0001bbfb\n"
        /* } scope */
        ".Lf1ba56_0001bb77:\n"
        "movl -0x24(%ebp), %eax\n" /* line 277 | shaderCode */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 2 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1ba56_0001bc2a\n"
        /* } scope */
        ".Lf1ba56_0001bb85:\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 | shaderNameAndCode */
        "leal -0xc(%eax), %ebx\n"
        /* { scope 2 */
        "cmpl %ebx, %esi\n" /* line 224 */
        "jne .Lf1ba56_0001bc59\n"
        /* } scope */
        /* } scope */
        ".Lf1ba56_0001bb93:\n"
        "movl %edi, %eax\n" /* line 4465 | hr */
        "addl $0x43c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: MyError */
        ".Lf1ba56_0001bba0:\n"
        "movl $0x18, (%esp)\n" /* line 4440 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n"
        "leal -0x24(%ebp), %eax\n" /* shaderCode */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGLARBFragmentProgram_COpenGLARBFragmentProgram\n"
        "jmp .Lf1ba56_0001bb16\n"
        ".Lf1ba56_0001bbc6:\n"
        "movl $0x14, (%esp)\n" /* line 4437 */
        "calll __Znwm\n"
        "movl %eax, %ebx\n"
        "movl 0x10(%ebp), %eax\n" /* pSrcData */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll COpenGLNVidiaRegisterCombinersProgram_COpenGLNVidiaRegisterCombinersProgram\n"
        "jmp .Lf1ba56_0001bb16\n"
        ".Lf1ba56_0001bbe8:\n"
        "xorl %edi, %edi\n" /* line 4450 | hr */
        "jmp .Lf1ba56_0001bb63\n"
        /* { scope 2 */
        ".Lf1ba56_0001bbef:\n"
        "movl $str_00215bfc, (%esp)\n" /* line 300 */
        "calll __ZSt20__throw_out_of_rangePKc\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ba56_0001bbfb:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1ba56_0001bb77\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1ba56_0001bb77\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ba56_0001bc2a:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1ba56_0001bb85\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1ba56_0001bb85\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ba56_0001bc59:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1ba56_0001bb93\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1ba56_0001bb93\n"
        ".Lf1ba56_0001bc88:\n"
        "movl %eax, %esi\n"
        /* } scope */
        "movl %ebx, (%esp)\n" /* line 4440 */
        "calll __ZdlPv\n"
        ".Lf1ba56_0001bc92:\n"
        "movl -0x28(%ebp), %eax\n" /* line 277 | shaderName */
        "leal -0xc(%eax), %edi\n"
        /* { scope 2 */
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 178 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf1ba56_0001bd0b\n"
        /* } scope */
        ".Lf1ba56_0001bca2:\n"
        "movl -0x24(%ebp), %eax\n" /* line 277 | shaderCode */
        "leal -0xc(%eax), %edi\n"
        /* { scope 2 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf1ba56_0001bcec\n"
        /* } scope */
        ".Lf1ba56_0001bcac:\n"
        "movl -0x20(%ebp), %eax\n" /* line 277 | shaderNameAndCode */
        "leal -0xc(%eax), %edi\n"
        /* { scope 2 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf1ba56_0001bcc4\n"
        /* } scope */
        ".Lf1ba56_0001bcb6:\n"
        "movl %esi, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        ".Lf1ba56_0001bcbe:\n"
        "movl %eax, %esi\n"
        "jmp .Lf1ba56_0001bcb6\n"
        "jmp .Lf1ba56_0001bc88\n"
        /* { scope 2 */
        ".Lf1ba56_0001bcc4:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1ba56_0001bcb6\n"
        "leal -0x19(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1ba56_0001bcb6\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ba56_0001bcec:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jle .Lf1ba56_0001bd53\n"
        ".Lf1ba56_0001bd03:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1ba56_0001bcac\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ba56_0001bd0b:\n"
        "subl $4, %eax\n"
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf1ba56_0001bca2\n"
        "leal -0x1b(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf1ba56_0001bca2\n"
        ".Lf1ba56_0001bd36:\n"
        "movl %eax, %esi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1ba56_0001bca2\n"
        ".Lf1ba56_0001bd43:\n"
        "movl %eax, %esi\n"
        "jmp .Lf1ba56_0001bd03\n"
        "jmp .Lf1ba56_0001bcbe\n"
        "movl %eax, %esi\n"
        "jmp .Lf1ba56_0001bc92\n"
        /* } scope */
        /* { scope 2 */
        ".Lf1ba56_0001bd53:\n"
        "leal -0x1a(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf1ba56_0001bcac\n"
        "jmp .Lf1ba56_0001bd36\n"
        "jmp .Lf1ba56_0001bd43\n"
    );
}

/* line 4245 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreatePixelShader(const CDirect3DDevice * _this, const DWORD *pFunction, IDirect3DPixelShader9 * *ppShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 4245 */
        "movl %esp, %ebp\n"
        "subl $0x428, %esp\n"
        /* { scope 1: MyError */
        "movl 0x10(%ebp), %eax\n" /* line 4249 | ppShader, hr */
        "movl %eax, 0xc(%esp)\n" /* hr */
        "movl 0xc(%ebp), %eax\n" /* pFunction, hr */
        "movl %eax, 8(%esp)\n" /* hr */
        "movl $2, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* this, hr */
        "movl %eax, (%esp)\n" /* hr */
        "calll CDirect3DDevice_CreatePixelShaderOpenGL\n"
        "leal -0xc(%ebp), %eax\n" /* line 4252 | ErrorPosition */
        "movl %eax, 4(%esp)\n"
        "movl $0x864b, (%esp)\n"
        "calll glGetIntegerv\n"
        "cmpl $-1, -0xc(%ebp)\n" /* line 4254 | ErrorPosition */
        "jne .Lf1bd72_0001bdb9\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "leave\n" /* line 4272 */
        "retl\n"
        /* { scope 1: MyError */
        /* { scope 2 */
        ".Lf1bd72_0001bdb9:\n"
        "movl $0x8874, (%esp)\n" /* line 4258 */
        "calll glGetString\n"
        "movl %eax, 8(%esp)\n" /* line 4261 */
        "movl $str_00215bbc, 4(%esp)\n" /* "%s
" */
        "leal -0x40c(%ebp), %eax\n" /* MyError */
        "movl %eax, (%esp)\n"
        "calll sprintf\n"
        "movl $0x8876086c, %eax\n"
        /* } scope */
        /* } scope */
        "leave\n" /* line 4272 */
        "retl\n"
    );
}

/* line 244 */
__attribute__((naked))
void ZNSt11char_traitsIcE2eqERKcS2_(void) /* std_char_traits<char>_eq */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 244 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* __c1, __c2 */
        "movzbl (%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* __c2 */
        "cmpb (%eax), %dl\n"
        "sete %al\n" /* __c2 */
        "movzbl %al, %eax\n" /* __c2 */
        "popl %ebp\n" /* line 245 */
        "retl\n"
    );
}

/* line 389 */
__attribute__((naked))
HRESULT CDirect3DDevice_EvictManagedResources(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 389 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 393 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetCreationParameters(const CDirect3DDevice * _this, D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 393 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 394 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetCursorProperties(const CDirect3DDevice * _this, UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9 *pCursorBitmap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 394 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 395 */
__attribute__((naked))
long unsigned int CDirect3DDevice_SetCursorPosition(const CDirect3DDevice * _this, int XScreenSpace, int YScreenSpace, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 395 */
        "movl %esp, %ebp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 396 */
__attribute__((naked))
BOOL CDirect3DDevice_ShowCursor(const CDirect3DDevice * _this, BOOL bShow)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 396 */
        "movl %esp, %ebp\n"
        "movl $1, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 397 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateAdditionalSwapChain(const CDirect3DDevice * _this, D3DPRESENT_PARAMETERS *pPresentationParameters, IDirect3DSwapChain9 * *pSwapChain)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 397 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

HRESULT CDirect3DDevice_StretchRect(const CDirect3DDevice * _this, IDirect3DSurface9 *pSourceSurface, const RECT *pSourceRect, IDirect3DSurface9 *pDestSurface, const RECT *pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    void *backBuffer;

    backBuffer = d3d_ptr(_this, 0x1c);
    if (pSourceSurface != backBuffer && pDestSurface == backBuffer) {
        return CDirect3DDevice_StretchRectToBackBuffer(_this, pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
    }

    return CDirect3DDevice_StretchRect_impl(_this, pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

/* line 398 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetSwapChain(const CDirect3DDevice * _this, UINT iSwapChain, IDirect3DSwapChain9 * *pSwapChain)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 398 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xec(%ecx), %edx\n" /* line 400 */
        "movl 0x10(%ebp), %eax\n" /* pSwapChain */
        "movl %edx, (%eax)\n"
        "movl 0xec(%ecx), %eax\n" /* line 401 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* line 404 */
        "leave\n"
        "retl\n"
    );
}

/* line 405 */
__attribute__((naked))
UINT CDirect3DDevice_GetNumberOfSwapChains(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 405 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 409 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetRasterStatus(const CDirect3DDevice * _this, UINT iSwapChain, D3DRASTER_STATUS *pRasterStatus)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 409 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 410 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetDialogBoxMode(const CDirect3DDevice * _this, BOOL bEnableDialogs)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 410 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 420 */
__attribute__((naked))
HRESULT CDirect3DDevice_UpdateSurface(const CDirect3DDevice * _this, IDirect3DSurface9 *pSourceSurface, const RECT *pSourceRect, IDirect3DSurface9 *pDestinationSurface, const POINT *pDestPoint)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 420 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 422 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetRenderTargetData(const CDirect3DDevice * _this, IDirect3DSurface9 *pRenderTarget, IDirect3DSurface9 *pDestSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 422 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 423 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetFrontBufferData(const CDirect3DDevice * _this, UINT iSwapChain, IDirect3DSurface9 *pDestSurface)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 423 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 425 */
__attribute__((naked))
HRESULT CDirect3DDevice_ColorFill(const CDirect3DDevice * _this, IDirect3DSurface9 *pSurface, const RECT *pRect, D3DCOLOR color)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 425 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 426 */
HRESULT CDirect3DDevice_CreateOffscreenPlainSurface(const CDirect3DDevice * _this, UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9 * *ppSurface, HANDLE *pSharedHandle)
{
    CDirect3DSurface *surface;
    void *surfaceMemory;
    int currentTexture;
    UINT allocWidth;
    UINT allocHeight;
    UINT imageSize;

    (void)_this;
    (void)Pool;

    surfaceMemory = NULL;
    currentTexture = 0;

    glGetIntegerv(0x8069, &currentTexture);

    if (!g_NoTextureID) {
        allocWidth = 1;
        while (allocWidth < Width) {
            allocWidth <<= 1;
        }

        allocHeight = 1;
        while (allocHeight < Height) {
            allocHeight <<= 1;
        }

        imageSize = MacOpenGLUtils_GetImageSizeInBytes(allocWidth, allocHeight, 1, 1, &Format);
        surfaceMemory = malloc(imageSize);
    }

    surface = (CDirect3DSurface *)malloc(0x3c);
    CDirect3DSurface_CDirect3DSurface(surface, 0, 0, 0, Width, Height, Format, surfaceMemory, 0);

    if (ppSurface != NULL) {
        *ppSurface = (IDirect3DSurface9 *)surface;
    }
    if (pSharedHandle != NULL) {
        *pSharedHandle = 0;
    }

    glBindTexture(0xde1, currentTexture);
    return 0;
}

/* line 428 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetRenderTarget(const CDirect3DDevice * _this, DWORD RenderTargetIndex, IDirect3DSurface9 * *ppRenderTarget)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 428 */
        "movl %esp, %ebp\n"
        "subl $0x18, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0x14(%ecx), %edx\n"
        "movl 0x10(%ebp), %eax\n" /* ppRenderTarget */
        "movl %edx, (%eax)\n"
        "movl 0x14(%ecx), %eax\n" /* ppRenderTarget */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n" /* ppRenderTarget */
        "calll *4(%edx)\n"
        "xorl %eax, %eax\n" /* ppRenderTarget */
        "leave\n"
        "retl\n"
    );
}

/* line 436 */
__attribute__((naked))
HRESULT CDirect3DDevice_MultiplyTransform(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 436 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 438 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetViewport(const CDirect3DDevice * _this, IDirect3DIndexBuffer9 * (*pViewport)[10])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 438 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %ecx\n" /* pViewport */
        "movl 0x5f0(%edx), %eax\n"
        "movl %eax, (%ecx)\n"
        "movl 0x5f4(%edx), %eax\n"
        "movl %eax, 4(%ecx)\n"
        "movl 0x5f8(%edx), %eax\n"
        "movl %eax, 8(%ecx)\n"
        "movl 0x5fc(%edx), %eax\n"
        "movl %eax, 0xc(%ecx)\n"
        "movl 0x600(%edx), %eax\n"
        "movl %eax, 0x10(%ecx)\n"
        "movl 0x604(%edx), %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 440 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetMaterial(const CDirect3DDevice * _this, char (*pMaterial)[4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 440 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 442 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetLight(const CDirect3DDevice * _this, DWORD Index)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 442 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 444 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetLightEnable(const CDirect3DDevice * _this, DWORD Index, BOOL *pEnable)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 444 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 445 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetClipPlane(const CDirect3DDevice * _this, DWORD Index, const float *pPlane)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 445 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 446 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetClipPlane(const CDirect3DDevice * _this, DWORD Index, float *pPlane)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 446 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 449 */
__attribute__((naked))
HRESULT CDirect3DDevice_BeginStateBlock(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 449 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 450 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateStateBlock(const CDirect3DDevice * _this, D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9 * *ppSB)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 450 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 451 */
__attribute__((naked))
HRESULT CDirect3DDevice_EndStateBlock(const CDirect3DDevice * _this, IDirect3DStateBlock9 * *ppSB)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 451 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 452 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetClipStatus(const CDirect3DDevice * _this, const D3DCLIPSTATUS9 *pClipStatus)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 452 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 453 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetClipStatus(const CDirect3DDevice * _this, D3DCLIPSTATUS9 *pClipStatus)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 453 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 483 */
__attribute__((naked))
HRESULT CDirect3DDevice_ValidateDevice(const CDirect3DDevice * _this, DWORD *pNumPasses)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 483 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 485 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetPaletteEntries(const CDirect3DDevice * _this, UINT PaletteNumber, const PALETTEENTRY *pEntries)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 485 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 486 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetPaletteEntries(const CDirect3DDevice * _this, UINT PaletteNumber, _D3DFORMAT (*pEntries)[4][4])
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 486 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 487 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetCurrentTexturePalette(const CDirect3DDevice * _this, UINT PaletteNumber)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 487 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 488 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetCurrentTexturePalette(const CDirect3DDevice * _this, UINT *PaletteNumber)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 488 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 489 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetScissorRect(const CDirect3DDevice * _this, const RECT *pRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 489 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 490 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetScissorRect(const CDirect3DDevice * _this, RECT *pRect)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 490 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 491 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetSoftwareVertexProcessing(const CDirect3DDevice * _this, BOOL bSoftware)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 491 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 492 */
__attribute__((naked))
BOOL CDirect3DDevice_GetSoftwareVertexProcessing(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 492 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 493 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetNPatchMode(const CDirect3DDevice * _this, float nSegments)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 493 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 494 */
__attribute__((naked))
float CDirect3DDevice_GetNPatchMode(const CDirect3DDevice * _this)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 494 */
        "movl %esp, %ebp\n"
        "fldz\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 497 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetVertexDeclaration(const CDirect3DDevice * _this, IDirect3DVertexDeclaration9 * *ppDecl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 497 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 499 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetFVF(const CDirect3DDevice * _this, DWORD *pFVF)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 499 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 503 */
__attribute__((naked))
HRESULT CDirect3DDevice_DrawIndexedPrimitiveUP(const CDirect3DDevice * _this, D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const long unsigned int *pIndexData, D3DFORMAT IndexDataFormat, const long unsigned int *pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 503 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 504 */
__attribute__((naked))
HRESULT CDirect3DDevice_ProcessVertices(const CDirect3DDevice * _this, UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9 *pDestBuffer, IDirect3DVertexDeclaration9 *pVertexDecl, DWORD Flags)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 504 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 507 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetVertexShader(const CDirect3DDevice * _this, IDirect3DVertexShader9 * *ppShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 507 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 508 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetStreamSource(const CDirect3DDevice * _this, UINT StreamNumber, IDirect3DVertexBuffer9 *pStreamData, UINT OffsetInBytes, UINT Stride)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 508 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* StreamNumber */
        "movl 0x10(%ebp), %eax\n" /* pStreamData */
        "movl 0x14(%ebp), %esi\n" /* OffsetInBytes */
        /* { scope 1 */
        "testl %eax, %eax\n" /* line 519 */
        "je .Lf2bd410_002bd46f\n"
        "movzbl 0x2c(%eax), %ebx\n" /* line 526 | ForceRevalidation */
        "testb %bl, %bl\n" /* line 527 | ForceRevalidation */
        "jne .Lf2bd410_002bd459\n"
        ".Lf2bd410_002bd42d:\n"
        "cmpl 0x24(%ecx, %edx, 4), %eax\n" /* line 537 */
        "je .Lf2bd410_002bd463\n"
        ".Lf2bd410_002bd433:\n"
        "movl %eax, 0x24(%ecx, %edx, 4)\n" /* line 546 */
        "movl %esi, 0x64(%ecx, %edx, 4)\n" /* line 547 | OffsetInBytes */
        "movl 0x18(%ebp), %eax\n" /* line 551 | Stride */
        "movl %eax, 0xac(%ecx, %edx, 4)\n"
        "movb $1, __ZN15CDirect3DDevice30mNeedsTransformationValidationE\n" /* line 645 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        /* } scope */
        ".Lf2bd410_002bd453:\n"
        "xorl %eax, %eax\n" /* line 565 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bd410_002bd459:\n"
        "movb $0, 0x2c(%eax)\n" /* line 125 */
        "cmpl 0x24(%ecx, %edx, 4), %eax\n" /* line 537 */
        "jne .Lf2bd410_002bd433\n"
        ".Lf2bd410_002bd463:\n"
        "cmpl 0x64(%ecx, %edx, 4), %esi\n" /* OffsetInBytes */
        "jne .Lf2bd410_002bd433\n"
        "testb %bl, %bl\n" /* ForceRevalidation */
        "jne .Lf2bd410_002bd433\n"
        "jmp .Lf2bd410_002bd453\n"
        ".Lf2bd410_002bd46f:\n"
        "movl $1, %ebx\n" /* line 519 | ForceRevalidation */
        "jmp .Lf2bd410_002bd42d\n"
    );
}

/* line 570 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetVertexShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, float *pConstantData, UINT Vector4fCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 570 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 571 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetVertexShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, const int *pConstantData, UINT Vector4iCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 571 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 572 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetVertexShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, int *pConstantData, UINT Vector4iCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 572 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 573 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetVertexShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, const BOOL *pConstantData, UINT BoolCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 573 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 574 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetVertexShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, BOOL *pConstantData, UINT BoolCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 574 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 576 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetStreamSourceFreq(const CDirect3DDevice * _this, UINT StreamNumber, UINT Setting)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 576 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 577 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetStreamSourceFreq(const CDirect3DDevice * _this, UINT StreamNumber, UINT *pSetting)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 577 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 578 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetIndices(const CDirect3DDevice * _this, IDirect3DIndexBuffer9 *pIndexData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 578 */
        "movl %esp, %ebp\n"
        "movl 0xc(%ebp), %edx\n" /* line 580 | pIndexData */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %edx, 0xa4(%eax)\n"
        "xorl %eax, %eax\n" /* line 583 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 584 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetIndices(const CDirect3DDevice * _this, IDirect3DIndexBuffer9 * *ppIndexData)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 584 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 0xa4(%eax), %edx\n"
        "movl 0xc(%ebp), %eax\n" /* ppIndexData, this */
        "movl %edx, (%eax)\n"
        "xorl %eax, %eax\n" /* this */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 598 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetPixelShader(const CDirect3DDevice * _this, IDirect3DPixelShader9 * *ppShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 598 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 600 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetPixelShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, float *pConstantData, UINT Vector4fCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 600 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 601 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetPixelShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, const int *pConstantData, UINT Vector4iCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 601 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 602 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetPixelShaderConstantI(const CDirect3DDevice * _this, UINT StartRegister, int *pConstantData, UINT Vector4iCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 602 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 603 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetPixelShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, const BOOL *pConstantData, UINT BoolCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 603 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 604 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetPixelShaderConstantB(const CDirect3DDevice * _this, UINT StartRegister, BOOL *pConstantData, UINT BoolCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 604 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 606 */
__attribute__((naked))
HRESULT CDirect3DDevice_DrawRectPatch(const CDirect3DDevice * _this, UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 606 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 607 */
__attribute__((naked))
HRESULT CDirect3DDevice_DrawTriPatch(const CDirect3DDevice * _this, UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 607 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 608 */
__attribute__((naked))
HRESULT CDirect3DDevice_DeletePatch(const CDirect3DDevice * _this, UINT Handle)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 608 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 609 */
__attribute__((naked))
HRESULT CDirect3DDevice_CreateQuery(const CDirect3DDevice * _this, D3DQUERYTYPE Type, bool (*ppQuery)())
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 609 */
        "movl %esp, %ebp\n"
        "xorl %eax, %eax\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 454 */
__attribute__((naked))
HRESULT CDirect3DDevice_GetTexture(const CDirect3DDevice * _this, DWORD Stage, IDirect3DBaseTexture9 * *ppTexture)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 454 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %ecx\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Stage */
        "movl 0x10(%ebp), %esi\n" /* ppTexture */
        "cmpl %edx, 0x504(%ecx)\n" /* line 456 */
        "jbe .Lf2bd528_002bd56a\n"
        /* { scope 1 */
        "leal (%edx, %edx, 4), %eax\n" /* line 654 */
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "addl 0x608(%ecx), %eax\n"
        "movl 4(%eax), %ebx\n" /* line 103 */
        "testl %ebx, %ebx\n" /* line 463 | pCurrentTexture */
        "je .Lf2bd528_002bd55f\n"
        "movl (%ebx), %eax\n" /* line 465 | pCurrentTexture */
        "movl %ebx, (%esp)\n" /* pCurrentTexture */
        "calll *4(%eax)\n"
        ".Lf2bd528_002bd55f:\n"
        "movl %ebx, (%esi)\n" /* line 468 | pCurrentTexture, ppTexture */
        /* } scope */
        "xorl %eax, %eax\n" /* line 477 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bd528_002bd56a:\n"
        "movl $0, (%esi)\n" /* line 473 | ppTexture */
        "xorl %eax, %eax\n" /* line 477 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 122 */
__attribute__((naked))
void ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_(void) /* std_vector<CDirect3DDevice_CTexStage, std_allocator<CDirect3DDevice_CTexStage> >_erase */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 122 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 352 | this */
        "addl $4, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 4(%eax), %ecx\n"
        "movl 0x10(%ebp), %ebx\n" /* line 124 | __last */
        "movl 0xc(%ebp), %esi\n" /* __first */
        /* { scope 1 */
        /* { scope 2 */
        "movl %ecx, %eax\n" /* line 283 */
        "subl %ebx, %eax\n"
        "sarl $2, %eax\n"
        "imull $0xc18f9c19, %eax, %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf2bd57a_002bd5dc\n"
        "xorl %edi, %edi\n"
        ".Lf2bd57a_002bd5ae:\n"
        "movl $0xa4, 8(%esp)\n" /* line 285 */
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "addl $0xa4, %ebx\n" /* line 286 */
        "addl $0xa4, %esi\n" /* line 287 */
        "addl $1, %edi\n"
        "cmpl %edi, -0x20(%ebp)\n" /* line 283 */
        "jne .Lf2bd57a_002bd5ae\n"
        "movl 8(%ebp), %eax\n" /* this */
        "movl 4(%eax), %ecx\n"
        /* } scope */
        /* } scope */
        ".Lf2bd57a_002bd5dc:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 352 */
        "movl (%eax), %edx\n"
        "movl %esi, %eax\n"
        "cmpl %esi, %edx\n" /* line 173 */
        "je .Lf2bd57a_002bd5f0\n"
        ".Lf2bd57a_002bd5e7:\n"
        "addl $0xa4, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bd57a_002bd5e7\n"
        ".Lf2bd57a_002bd5f0:\n"
        "movl 0xc(%ebp), %eax\n" /* line 126 | __first */
        "subl %eax, 0x10(%ebp)\n" /* __last */
        "andl $0xfffffffc, 0x10(%ebp)\n" /* __last */
        "subl 0x10(%ebp), %ecx\n" /* __last */
        "movl 8(%ebp), %eax\n" /* this */
        "movl %ecx, 4(%eax)\n"
        "movl 0xc(%ebp), %eax\n" /* line 127 | __first */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 189 */
__attribute__((naked))
long unsigned int CDirect3DDevice_CTexStage_Init(const CTexStage * _this, UINT32 Stage, int IsProgrammableStage)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 189 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        "movl 8(%ebp), %edi\n" /* this */
        "movl 0xc(%ebp), %edx\n" /* Stage */
        /* { scope 1 */
        "movzbl 0x10(%ebp), %eax\n" /* line 127 | IsProgrammableStage */
        "movb %al, (%edi)\n"
        "movl $0, 4(%edi)\n" /* line 128 */
        "testb %al, %al\n" /* line 194 */
        "jne .Lf2bd60e_002bd680\n"
        "cmpl $1, %edx\n" /* line 197 */
        "sbbl %eax, %eax\n" /* Value */
        "andl $3, %eax\n" /* Value */
        "addl $1, %eax\n" /* Value */
        /* { scope 2 */
        "movl %eax, 0x2c(%edi)\n" /* line 129 */
        /* } scope */
        "movl $3, 0x30(%edi)\n" /* line 130 */
        "movl $2, 0x34(%edi)\n" /* line 131 */
        "movl $1, 0x38(%edi)\n" /* line 132 */
        "cmpl $1, %edx\n" /* line 201 */
        "sbbl %eax, %eax\n" /* Value */
        "notl %eax\n" /* Value */
        "addl $2, %eax\n" /* Value */
        /* { scope 2 */
        "movl %eax, 0x3c(%edi)\n" /* line 133 */
        /* } scope */
        "movl $3, 0x40(%edi)\n" /* line 134 */
        "movl $0, 0x44(%edi)\n" /* line 135 */
        "movl $1, 0x48(%edi)\n" /* line 136 */
        "movl $0, 0x4c(%edi)\n" /* line 155 */
        "movl %edx, 0x50(%edi)\n" /* line 156 */
        ".Lf2bd60e_002bd680:\n"
        "movl $1, 8(%edi)\n" /* line 141 */
        "movl $1, 0xc(%edi)\n" /* line 146 */
        "movl $1, 0x10(%edi)\n" /* line 151 */
        "movl $0, 0x28(%edi)\n" /* line 153 */
        "movl $1, 0x14(%edi)\n" /* line 161 */
        "movl $1, 0x18(%edi)\n" /* line 166 */
        "movl $0, 0x1c(%edi)\n" /* line 171 */
        "movl $0, 0x24(%edi)\n" /* line 175 */
        "movl $0x3f800000, %ecx\n" /* line 217 */
        "movl %ecx, -0x28(%ebp)\n" /* rgba */
        "movl %ecx, -0x24(%ebp)\n"
        "movl %ecx, -0x20(%ebp)\n"
        "movl %ecx, -0x1c(%ebp)\n"
        "leal 0x54(%edi), %edx\n" /* line 179 */
        "movl -0x28(%ebp), %eax\n" /* rgba */
        "movl %eax, 0x54(%edi)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl %ecx, 0x20(%edi)\n" /* line 183 */
        "movl imp___ZN13COpenGLMatrix9sIdentityE, %eax\n" /* line 221 */
        "movl (%eax), %edx\n"
        "movl %edx, -0x9c(%ebp)\n"
        "movl 4(%eax), %ecx\n"
        "movl 8(%eax), %ebx\n"
        "movl 0xc(%eax), %esi\n"
        "movl 0x10(%eax), %edx\n"
        "movl %edx, -0x6c(%ebp)\n"
        "movl 0x14(%eax), %edx\n"
        "movl %edx, -0x70(%ebp)\n"
        "movl 0x18(%eax), %edx\n"
        "movl %edx, -0x74(%ebp)\n"
        "movl 0x1c(%eax), %edx\n"
        "movl %edx, -0x78(%ebp)\n"
        "movl 0x20(%eax), %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl 0x24(%eax), %edx\n"
        "movl %edx, -0x80(%ebp)\n"
        "movl 0x28(%eax), %edx\n"
        "movl %edx, -0x84(%ebp)\n"
        "movl 0x2c(%eax), %edx\n"
        "movl %edx, -0x88(%ebp)\n"
        "movl 0x30(%eax), %edx\n"
        "movl %edx, -0x8c(%ebp)\n"
        "movl 0x34(%eax), %edx\n"
        "movl %edx, -0x90(%ebp)\n"
        "movl 0x38(%eax), %edx\n"
        "movl %edx, -0x94(%ebp)\n"
        "movl 0x3c(%eax), %eax\n"
        "movl %eax, -0x98(%ebp)\n"
        "leal 0x64(%edi), %eax\n" /* line 187 */
        "movl -0x9c(%ebp), %edx\n"
        "movl %edx, 0x64(%edi)\n"
        "movl %ecx, 4(%eax)\n"
        "movl %ebx, 8(%eax)\n"
        "movl %esi, 0xc(%eax)\n"
        "movl -0x6c(%ebp), %edx\n"
        "movl %edx, 0x10(%eax)\n"
        "movl -0x70(%ebp), %edx\n"
        "movl %edx, 0x14(%eax)\n"
        "movl -0x74(%ebp), %edx\n"
        "movl %edx, 0x18(%eax)\n"
        "movl -0x78(%ebp), %edx\n"
        "movl %edx, 0x1c(%eax)\n"
        "movl -0x7c(%ebp), %edx\n"
        "movl %edx, 0x20(%eax)\n"
        "movl -0x80(%ebp), %edx\n"
        "movl %edx, 0x24(%eax)\n"
        "movl -0x84(%ebp), %edx\n"
        "movl %edx, 0x28(%eax)\n"
        "movl -0x88(%ebp), %edx\n"
        "movl %edx, 0x2c(%eax)\n"
        "movl -0x8c(%ebp), %edx\n"
        "movl %edx, 0x30(%eax)\n"
        "movl -0x90(%ebp), %edx\n"
        "movl %edx, 0x34(%eax)\n"
        "movl -0x94(%ebp), %edx\n"
        "movl %edx, 0x38(%eax)\n"
        "movl -0x98(%ebp), %edx\n"
        "movl %edx, 0x3c(%eax)\n"
        /* } scope */
        "addl $0x9c, %esp\n" /* line 223 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 592 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetPixelShader(const CDirect3DDevice * _this, IDirect3DPixelShader9 *pShader)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 592 */
        "movl %esp, %ebp\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 0xc(%ebp), %eax\n" /* pShader */
        "cmpl 0xbb8(%edx), %eax\n" /* line 4474 */
        "je .Lf2bd7d2_002bd7f0\n"
        "movl %eax, 0xbb8(%edx)\n" /* line 4482 */
        "movb $1, __ZN15CDirect3DDevice29mNeedsRasterizationValidationE\n" /* line 646 */
        ".Lf2bd7d2_002bd7f0:\n"
        "xorl %eax, %eax\n" /* line 597 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 599 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetPixelShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, const float *pConstantData, UINT Vector4fCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 599 */
        "movl %esp, %ebp\n"
        "subl $0x28, %esp\n"
        "movl 8(%ebp), %eax\n" /* line 4505 | this */
        "movl 0xbb8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "movl $0, 0x10(%esp)\n"
        "movl 0x14(%ebp), %eax\n" /* Vector4fCount */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x10(%ebp), %eax\n" /* pConstantData */
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* StartRegister */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x24(%ecx)\n"
        "xorl %eax, %eax\n" /* line 599 | this */
        "leave\n"
        "retl\n"
    );
}

/* line 566 */
__attribute__((naked))
HRESULT CDirect3DDevice_SetVertexShaderConstantF(const CDirect3DDevice * _this, UINT StartRegister, const float *pConstantData, UINT Vector4fCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 566 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0x10(%ebp), %esi\n" /* line 4369 | pConstantData, pf */
        "movl 0x14(%ebp), %eax\n" /* line 4371 | Vector4fCount */
        "subl $1, %eax\n"
        "cmpl $-1, %eax\n"
        "je .Lf2bd82c_002bd868\n"
        "movl 0xc(%ebp), %ebx\n" /* StartRegister */
        "leal 1(%ebx, %eax), %edi\n"
        ".Lf2bd82c_002bd84a:\n"
        "movl %esi, 8(%esp)\n" /* line 4378 | pf */
        "movl %ebx, 4(%esp)\n"
        "movl $0x8620, (%esp)\n"
        "calll glProgramEnvParameter4fvARB\n"
        "addl $1, %ebx\n" /* line 4382 */
        "addl $0x10, %esi\n" /* line 4383 | pf */
        "cmpl %edi, %ebx\n" /* line 4371 */
        "jne .Lf2bd82c_002bd84a\n"
        /* } scope */
        ".Lf2bd82c_002bd868:\n"
        "xorl %eax, %eax\n" /* line 569 */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 249 */
__attribute__((naked))
void ZNSt6vectorIN15CDirect3DDevice9CTexStageESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_(void) /* std_vector<CDirect3DDevice_CTexStage, std_allocator<CDirect3DDevice_CTexStage> >__M_insert_aux */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 249 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xec, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* __position */
        "movl %eax, -0xcc(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 251 | this */
        "movl 4(%edx), %eax\n"
        "cmpl 8(%edx), %eax\n"
        "je .Lf2bd872_002bd963\n"
        "leal -0xa4(%eax), %edx\n"
        /* { scope 1 */
        /* { scope 2 */
        "testl %eax, %eax\n" /* line 104 */
        "je .Lf2bd872_002bda99\n"
        "movl $0xa4, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl 8(%ebp), %edx\n" /* this */
        "movl 4(%edx), %eax\n"
        /* } scope */
        ".Lf2bd872_002bd8be:\n"
        "movl %eax, %ebx\n" /* line 255 */
        "addl $0xa4, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl $0xa4, 8(%esp)\n" /* line 256 */
        "movl 0x10(%ebp), %eax\n" /* __x */
        "movl %eax, 4(%esp)\n"
        "leal -0xbc(%ebp), %edx\n" /* __x_copy */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "leal -0xa4(%ebx), %edx\n" /* line 257 */
        /* { scope 2 */
        "movl %edx, %eax\n" /* line 411 */
        "subl -0xcc(%ebp), %eax\n"
        "sarl $2, %eax\n"
        "imull $0xc18f9c19, %eax, %eax\n"
        "movl %eax, -0xd8(%ebp)\n"
        "testl %eax, %eax\n"
        "jle .Lf2bd872_002bd93b\n"
        "movl %edx, %eax\n"
        "movl %ebx, %edx\n"
        "xorl %edi, %edi\n"
        ".Lf2bd872_002bd90c:\n"
        "leal -0xa4(%edx), %esi\n" /* line 412 */
        "leal -0xa4(%eax), %ebx\n"
        "movl $0xa4, 8(%esp)\n"
        "movl %ebx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll memcpy\n"
        "addl $1, %edi\n"
        "movl %ebx, %eax\n"
        "movl %esi, %edx\n"
        "cmpl %edi, -0xd8(%ebp)\n" /* line 411 */
        "jne .Lf2bd872_002bd90c\n"
        /* } scope */
        ".Lf2bd872_002bd93b:\n"
        "movl $0xa4, 8(%esp)\n" /* line 260 */
        "leal -0xbc(%ebp), %eax\n" /* __x_copy */
        "movl %eax, 4(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __position */
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        /* } scope */
        "addl $0xec, %esp\n" /* line 304 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bd872_002bd963:\n"
        "subl (%edx), %eax\n" /* line 759 */
        "sarl $2, %eax\n"
        "imull $0xc18f9c19, %eax, %eax\n"
        "cmpl $0x18f9c18, %eax\n" /* line 265 */
        "je .Lf2bd872_002bdac3\n"
        "testl %eax, %eax\n" /* line 271 */
        "jne .Lf2bd872_002bdaa1\n"
        "movl $1, %edx\n" /* __len */
        ".Lf2bd872_002bd986:\n"
        "leal (%edx, %edx, 4), %eax\n" /* line 88 */
        "leal (%edx, %eax, 8), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, -0xdc(%ebp)\n"
        "movl %eax, (%esp)\n"
        "calll __Znwm\n"
        "movl %eax, -0xd4(%ebp)\n"
        "movl 8(%ebp), %eax\n" /* line 279 | this */
        "movl (%eax), %esi\n"
        /* { scope 2 */
        "movl -0xd4(%ebp), %ebx\n" /* line 82 */
        "cmpl %esi, 0xc(%ebp)\n" /* line 85 | __position */
        "je .Lf2bd872_002bd9e2\n"
        "movl %esi, %eax\n"
        "jmp .Lf2bd872_002bd9b9\n"
        ".Lf2bd872_002bd9b7:\n"
        "movl %eax, %esi\n"
        ".Lf2bd872_002bd9b9:\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bd872_002bd9d1\n"
        "movl $0xa4, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bd872_002bd9d1:\n"
        "leal 0xa4(%esi), %eax\n" /* line 623 */
        "addl $0xa4, %ebx\n"
        "cmpl %eax, 0xc(%ebp)\n" /* line 85 | __position */
        "jne .Lf2bd872_002bd9b7\n"
        /* } scope */
        ".Lf2bd872_002bd9e2:\n"
        "testl %ebx, %ebx\n" /* line 104 */
        "je .Lf2bd872_002bd9fd\n"
        "movl $0xa4, 8(%esp)\n"
        "movl 0x10(%ebp), %edx\n" /* __x */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bd872_002bd9fd:\n"
        "movl 8(%ebp), %eax\n" /* line 286 | this */
        "addl $4, %eax\n"
        "movl %eax, -0xd0(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 603 | this */
        "movl 4(%edx), %edi\n"
        "movl -0xcc(%ebp), %eax\n" /* line 286 */
        /* { scope 2 */
        "addl $0xa4, %ebx\n" /* line 82 */
        "cmpl %eax, %edi\n" /* line 85 */
        "je .Lf2bd872_002bda49\n"
        ".Lf2bd872_002bda1f:\n"
        "movl %eax, %esi\n"
        "testl %ebx, %ebx\n" /* line 81 */
        "je .Lf2bd872_002bda39\n"
        "movl $0xa4, 8(%esp)\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll memcpy\n"
        ".Lf2bd872_002bda39:\n"
        "leal 0xa4(%esi), %eax\n" /* line 623 */
        "addl $0xa4, %ebx\n"
        "cmpl %edi, %eax\n" /* line 85 */
        "jne .Lf2bd872_002bda1f\n"
        /* } scope */
        ".Lf2bd872_002bda49:\n"
        "movl -0xd0(%ebp), %eax\n" /* line 352 */
        "movl (%eax), %edx\n"
        "movl 8(%ebp), %eax\n" /* line 334 | this */
        "movl (%eax), %ecx\n"
        "movl %ecx, %eax\n"
        "cmpl %ecx, %edx\n" /* line 173 */
        "je .Lf2bd872_002bda65\n"
        ".Lf2bd872_002bda5c:\n"
        "addl $0xa4, %eax\n" /* line 623 */
        "cmpl %eax, %edx\n" /* line 173 */
        "jne .Lf2bd872_002bda5c\n"
        ".Lf2bd872_002bda65:\n"
        "testl %ecx, %ecx\n" /* line 122 */
        "je .Lf2bd872_002bda71\n"
        "movl %ecx, (%esp)\n" /* line 94 */
        "calll __ZdlPv\n"
        ".Lf2bd872_002bda71:\n"
        "movl -0xd4(%ebp), %eax\n" /* line 302 */
        "movl 8(%ebp), %edx\n" /* this */
        "movl %eax, (%edx)\n"
        "movl %ebx, 4(%edx)\n" /* line 303 */
        "movl -0xd4(%ebp), %eax\n" /* line 304 */
        "addl -0xdc(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        /* } scope */
        "addl $0xec, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lf2bd872_002bda99:\n"
        "movl 8(%ebp), %edx\n" /* this */
        "jmp .Lf2bd872_002bd8be\n"
        /* { scope 1 */
        ".Lf2bd872_002bdaa1:\n"
        "leal (%eax, %eax), %edx\n" /* line 271 | __len */
        "cmpl %eax, %edx\n" /* line 272 */
        "jb .Lf2bd872_002bdab9\n"
        "cmpl $0x18f9c18, %edx\n" /* line 85 */
        "jbe .Lf2bd872_002bd986\n"
        "calll __ZSt17__throw_bad_allocv\n" /* line 86 */
        ".Lf2bd872_002bdab9:\n"
        "movl $0x18f9c18, %edx\n" /* line 272 */
        "jmp .Lf2bd872_002bd986\n"
        ".Lf2bd872_002bdac3:\n"
        "movl $str_00215858, (%esp)\n" /* line 266 */
        "calll __ZSt20__throw_length_errorPKc\n"
    );
}
