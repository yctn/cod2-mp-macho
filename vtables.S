/* Auto-generated vtable definitions for DirectX wrapper classes */
/* Replaces hardcoded vtable addresses from original binary */
.section .data

.section .text

.globl ZThn4_N20CDirect3DCubeTextureD1Ev
.type ZThn4_N20CDirect3DCubeTextureD1Ev, @function
ZThn4_N20CDirect3DCubeTextureD1Ev:
    subl $4, 4(%esp)
    jmp ZN20CDirect3DCubeTextureD1Ev

.globl ZThn4_N20CDirect3DCubeTextureD0Ev
.type ZThn4_N20CDirect3DCubeTextureD0Ev, @function
ZThn4_N20CDirect3DCubeTextureD0Ev:
    subl $4, 4(%esp)
    jmp ZN20CDirect3DCubeTextureD0Ev

.globl ZThn4_N16CDirect3DTextureD1Ev
.type ZThn4_N16CDirect3DTextureD1Ev, @function
ZThn4_N16CDirect3DTextureD1Ev:
    subl $4, 4(%esp)
    jmp ZN16CDirect3DTextureD1Ev

.globl ZThn4_N16CDirect3DTextureD0Ev
.type ZThn4_N16CDirect3DTextureD0Ev, @function
ZThn4_N16CDirect3DTextureD0Ev:
    subl $4, 4(%esp)
    jmp ZN16CDirect3DTextureD0Ev

.globl ZThn4_N21CDirect3DVertexShaderD1Ev
.type ZThn4_N21CDirect3DVertexShaderD1Ev, @function
ZThn4_N21CDirect3DVertexShaderD1Ev:
    subl $4, 4(%esp)
    jmp ZN21CDirect3DVertexShaderD1Ev

.globl ZThn4_N21CDirect3DVertexShaderD0Ev
.type ZThn4_N21CDirect3DVertexShaderD0Ev, @function
ZThn4_N21CDirect3DVertexShaderD0Ev:
    subl $4, 4(%esp)
    jmp ZN21CDirect3DVertexShaderD0Ev

.section .data

.globl vtbl_StdConverterARGB
.type vtbl_StdConverterARGB, @object
.align 4
vtbl_StdConverterARGB: /* orig: 0x32f5c8 */
    .long StdConverterARGB_Convert /* [0] */
    .long StdConverterARGB_Convert4ub4f /* [4] */
    .long StdConverterARGB_Convert4f4ubInverse /* [8] */
    .long StdConverterARGB_Convert3f4ubInverse /* [12] */
    .long StdConverterARGB_ArrayConvert4f4ub /* [16] */
    .long StdConverterARGB_GetType /* [20] */
    .long ZN16StdConverterARGBD1Ev /* [24] */
    .long ZN16StdConverterARGBD0Ev /* [28] */
.size vtbl_StdConverterARGB, .-vtbl_StdConverterARGB

.globl vtbl_StdConverterABGR
.type vtbl_StdConverterABGR, @object
.align 4
vtbl_StdConverterABGR: /* orig: 0x32f608 */
    .long StdConverterABGR_Convert /* [0] */
    .long StdConverterABGR_Convert4ub4f /* [4] */
    .long StdConverterABGR_Convert4f4ubInverse /* [8] */
    .long StdConverterABGR_Convert3f4ubInverse /* [12] */
    .long StdConverterABGR_ArrayConvert4f4ub /* [16] */
    .long StdConverterABGR_GetType /* [20] */
    .long ZN16StdConverterABGRD1Ev /* [24] */
    .long ZN16StdConverterABGRD0Ev /* [28] */
.size vtbl_StdConverterABGR, .-vtbl_StdConverterABGR

.globl vtbl_ATI4CompsConverterARGB
.type vtbl_ATI4CompsConverterARGB, @object
.align 4
vtbl_ATI4CompsConverterARGB: /* orig: 0x32f648 */
    .long ATI4CompsConverterARGB_Convert /* [0] */
    .long ATI4CompsConverterARGB_Convert4ub4f /* [4] */
    .long ATI4CompsConverterARGB_Convert4f4ubInverse /* [8] */
    .long ATI4CompsConverterARGB_Convert3f4ubInverse /* [12] */
    .long ATI4CompsConverterARGB_ArrayConvert4f4ub /* [16] */
    .long ATI4CompsConverterARGB_GetType /* [20] */
    .long ZN22ATI4CompsConverterARGBD1Ev /* [24] */
    .long ZN22ATI4CompsConverterARGBD0Ev /* [28] */
.size vtbl_ATI4CompsConverterARGB, .-vtbl_ATI4CompsConverterARGB

.globl vtbl_ATI4CompsConverterABGR
.type vtbl_ATI4CompsConverterABGR, @object
.align 4
vtbl_ATI4CompsConverterABGR: /* orig: 0x32f688 */
    .long ATI4CompsConverterABGR_Convert /* [0] */
    .long ATI4CompsConverterABGR_Convert4ub4f /* [4] */
    .long ATI4CompsConverterABGR_Convert4f4ubInverse /* [8] */
    .long ATI4CompsConverterABGR_Convert3f4ubInverse /* [12] */
    .long ATI4CompsConverterABGR_ArrayConvert4f4ub /* [16] */
    .long ATI4CompsConverterABGR_GetType /* [20] */
    .long ZN22ATI4CompsConverterABGRD1Ev /* [24] */
    .long ZN22ATI4CompsConverterABGRD0Ev /* [28] */
.size vtbl_ATI4CompsConverterABGR, .-vtbl_ATI4CompsConverterABGR

.globl vtbl_CDirect3D
.type vtbl_CDirect3D, @object
.align 4
vtbl_CDirect3D: /* orig: 0x32f6c8 */
    .long CDirect3D_QueryInterface /* [0] */
    .long CDirect3D_AddRef /* [4] */
    .long CDirect3D_Release /* [8] */
    .long CDirect3D_RegisterSoftwareDevice /* [12] */
    .long CDirect3D_GetAdapterCount /* [16] */
    .long CDirect3D_GetAdapterIdentifier /* [20] */
    .long CDirect3D_GetAdapterModeCount /* [24] */
    .long CDirect3D_EnumAdapterModes /* [28] */
    .long CDirect3D_GetAdapterDisplayMode /* [32] */
    .long CDirect3D_CheckDeviceType /* [36] */
    .long CDirect3D_CheckDeviceFormat /* [40] */
    .long CDirect3D_CheckDeviceMultiSampleType /* [44] */
    .long CDirect3D_CheckDepthStencilMatch /* [48] */
    .long CDirect3D_CheckDeviceFormatConversion /* [52] */
    .long CDirect3D_GetDeviceCaps /* [56] */
    .long CDirect3D_GetAdapterMonitor /* [60] */
    .long CDirect3D_CreateDevice /* [64] */
    .long ZN9CDirect3DD1Ev /* [68] */
    .long ZN9CDirect3DD0Ev /* [72] */
.size vtbl_CDirect3D, .-vtbl_CDirect3D

.globl vtbl_CDirect3DCubeTexture
.type vtbl_CDirect3DCubeTexture, @object
.align 4
vtbl_CDirect3DCubeTexture: /* orig: 0x32f728 */
    .long CDirect3DCubeTexture_QueryInterface /* [0] */
    .long CDirect3DCubeTexture_AddRef /* [4] */
    .long CDirect3DCubeTexture_Release /* [8] */
    .long CDirect3DCubeTexture_GetDevice /* [12] */
    .long CDirect3DCubeTexture_SetPrivateData /* [16] */
    .long CDirect3DCubeTexture_GetPrivateData /* [20] */
    .long CDirect3DCubeTexture_FreePrivateData /* [24] */
    .long CDirect3DCubeTexture_SetPriority /* [28] */
    .long CDirect3DCubeTexture_GetPriority /* [32] */
    .long CDirect3DCubeTexture_PreLoad /* [36] */
    .long CDirect3DCubeTexture_GetType /* [40] */
    .long CDirect3DCubeTexture_SetLOD /* [44] */
    .long CDirect3DCubeTexture_GetLOD /* [48] */
    .long CDirect3DCubeTexture_GetLevelCount /* [52] */
    .long CDirect3DCubeTexture_SetAutoGenFilterType /* [56] */
    .long CDirect3DCubeTexture_GetAutoGenFilterType /* [60] */
    .long CDirect3DCubeTexture_GenerateMipSubLevels /* [64] */
    .long CDirect3DCubeTexture_GetLevelDesc /* [68] */
    .long CDirect3DCubeTexture_GetCubeMapSurface /* [72] */
    .long CDirect3DCubeTexture_LockRect /* [76] */
    .long CDirect3DCubeTexture_UnlockRect /* [80] */
    .long CDirect3DCubeTexture_AddDirtyRect /* [84] */
    .long ZN20CDirect3DCubeTextureD1Ev /* [88] */
    .long ZN20CDirect3DCubeTextureD0Ev /* [92] */
.size vtbl_CDirect3DCubeTexture, .-vtbl_CDirect3DCubeTexture

.globl vtbl_CDirect3DCubeTexture_secondary
.type vtbl_CDirect3DCubeTexture_secondary, @object
.align 4
vtbl_CDirect3DCubeTexture_secondary: /* orig: 0x32f790 */
    .long ZThn4_N20CDirect3DCubeTextureD1Ev /* [0] thunk */
    .long ZThn4_N20CDirect3DCubeTextureD0Ev /* [4] thunk */
    .long COpenGLTexture_UpdateOpenGLSurfaces /* [8] */
.size vtbl_CDirect3DCubeTexture_secondary, .-vtbl_CDirect3DCubeTexture_secondary

.globl vtbl_CDirect3DDevice
.type vtbl_CDirect3DDevice, @object
.align 4
vtbl_CDirect3DDevice: /* orig: 0x32f7a8 */
    .long CDirect3DDevice_QueryInterface /* [0] */
    .long CDirect3DDevice_AddRef /* [4] */
    .long CDirect3DDevice_Release /* [8] */
    .long CDirect3DDevice_TestCooperativeLevel /* [12] */
    .long CDirect3DDevice_GetAvailableTextureMem /* [16] */
    .long CDirect3DDevice_EvictManagedResources /* [20] */
    .long CDirect3DDevice_GetDirect3D /* [24] */
    .long CDirect3DDevice_GetDeviceCaps /* [28] */
    .long CDirect3DDevice_GetDisplayMode /* [32] */
    .long CDirect3DDevice_GetCreationParameters /* [36] */
    .long CDirect3DDevice_SetCursorProperties /* [40] */
    .long CDirect3DDevice_SetCursorPosition /* [44] */
    .long CDirect3DDevice_ShowCursor /* [48] */
    .long CDirect3DDevice_CreateAdditionalSwapChain /* [52] */
    .long CDirect3DDevice_GetSwapChain /* [56] */
    .long CDirect3DDevice_GetNumberOfSwapChains /* [60] */
    .long CDirect3DDevice_Reset /* [64] */
    .long CDirect3DDevice_Present /* [68] */
    .long CDirect3DDevice_GetBackBuffer /* [72] */
    .long CDirect3DDevice_GetRasterStatus /* [76] */
    .long CDirect3DDevice_SetDialogBoxMode /* [80] */
    .long CDirect3DDevice_SetGammaRamp /* [84] */
    .long CDirect3DDevice_GetGammaRamp /* [88] */
    .long CDirect3DDevice_CreateTexture /* [92] */
    .long CDirect3DDevice_CreateVolumeTexture /* [96] */
    .long CDirect3DDevice_CreateCubeTexture /* [100] */
    .long CDirect3DDevice_CreateVertexBuffer /* [104] */
    .long CDirect3DDevice_CreateIndexBuffer /* [108] */
    .long CDirect3DDevice_CreateRenderTarget /* [112] */
    .long CDirect3DDevice_CreateDepthStencilSurface /* [116] */
    .long CDirect3DDevice_UpdateSurface /* [120] */
    .long CDirect3DDevice_UpdateTexture /* [124] */
    .long CDirect3DDevice_GetRenderTargetData /* [128] */
    .long CDirect3DDevice_GetFrontBufferData /* [132] */
    .long CDirect3DDevice_StretchRect /* [136] */
    .long CDirect3DDevice_ColorFill /* [140] */
    .long CDirect3DDevice_CreateOffscreenPlainSurface /* [144] */
    .long CDirect3DDevice_SetRenderTarget /* [148] */
    .long CDirect3DDevice_GetRenderTarget /* [152] */
    .long CDirect3DDevice_SetDepthStencilSurface /* [156] */
    .long CDirect3DDevice_GetDepthStencilSurface /* [160] */
    .long CDirect3DDevice_BeginScene /* [164] */
    .long CDirect3DDevice_EndScene /* [168] */
    .long CDirect3DDevice_Clear /* [172] */
    .long CDirect3DDevice_SetTransform /* [176] */
    .long CDirect3DDevice_GetTransform /* [180] */
    .long CDirect3DDevice_MultiplyTransform /* [184] */
    .long CDirect3DDevice_SetViewport /* [188] */
    .long CDirect3DDevice_GetViewport /* [192] */
    .long CDirect3DDevice_SetMaterial /* [196] */
    .long CDirect3DDevice_GetMaterial /* [200] */
    .long CDirect3DDevice_SetLight /* [204] */
    .long CDirect3DDevice_GetLight /* [208] */
    .long CDirect3DDevice_LightEnable /* [212] */
    .long CDirect3DDevice_GetLightEnable /* [216] */
    .long CDirect3DDevice_SetClipPlane /* [220] */
    .long CDirect3DDevice_GetClipPlane /* [224] */
    .long CDirect3DDevice_SetRenderState /* [228] */
    .long CDirect3DDevice_GetRenderState /* [232] */
    .long CDirect3DDevice_CreateStateBlock /* [236] */
    .long CDirect3DDevice_BeginStateBlock /* [240] */
    .long CDirect3DDevice_EndStateBlock /* [244] */
    .long CDirect3DDevice_SetClipStatus /* [248] */
    .long CDirect3DDevice_GetClipStatus /* [252] */
    .long CDirect3DDevice_GetTexture /* [256] */
    .long CDirect3DDevice_SetTexture /* [260] */
    .long CDirect3DDevice_GetTextureStageState /* [264] */
    .long CDirect3DDevice_SetTextureStageState /* [268] */
    .long CDirect3DDevice_GetSamplerState /* [272] */
    .long CDirect3DDevice_SetSamplerState /* [276] */
    .long CDirect3DDevice_ValidateDevice /* [280] */
    .long CDirect3DDevice_SetPaletteEntries /* [284] */
    .long CDirect3DDevice_GetPaletteEntries /* [288] */
    .long CDirect3DDevice_SetCurrentTexturePalette /* [292] */
    .long CDirect3DDevice_GetCurrentTexturePalette /* [296] */
    .long CDirect3DDevice_SetScissorRect /* [300] */
    .long CDirect3DDevice_GetScissorRect /* [304] */
    .long CDirect3DDevice_SetSoftwareVertexProcessing /* [308] */
    .long CDirect3DDevice_GetSoftwareVertexProcessing /* [312] */
    .long CDirect3DDevice_SetNPatchMode /* [316] */
    .long CDirect3DDevice_GetNPatchMode /* [320] */
    .long CDirect3DDevice_DrawPrimitive /* [324] */
    .long CDirect3DDevice_DrawIndexedPrimitive /* [328] */
    .long CDirect3DDevice_DrawPrimitiveUP /* [332] */
    .long CDirect3DDevice_DrawIndexedPrimitiveUP /* [336] */
    .long CDirect3DDevice_ProcessVertices /* [340] */
    .long CDirect3DDevice_CreateVertexDeclaration /* [344] */
    .long CDirect3DDevice_SetVertexDeclaration /* [348] */
    .long CDirect3DDevice_GetVertexDeclaration /* [352] */
    .long CDirect3DDevice_SetFVF /* [356] */
    .long CDirect3DDevice_GetFVF /* [360] */
    .long CDirect3DDevice_CreateVertexShader /* [364] */
    .long CDirect3DDevice_SetVertexShader /* [368] */
    .long CDirect3DDevice_GetVertexShader /* [372] */
    .long CDirect3DDevice_SetVertexShaderConstantF /* [376] */
    .long CDirect3DDevice_GetVertexShaderConstantF /* [380] */
    .long CDirect3DDevice_SetVertexShaderConstantI /* [384] */
    .long CDirect3DDevice_GetVertexShaderConstantI /* [388] */
    .long CDirect3DDevice_SetVertexShaderConstantB /* [392] */
    .long CDirect3DDevice_GetVertexShaderConstantB /* [396] */
    .long CDirect3DDevice_SetStreamSource /* [400] */
    .long CDirect3DDevice_GetStreamSource /* [404] */
    .long CDirect3DDevice_SetStreamSourceFreq /* [408] */
    .long CDirect3DDevice_GetStreamSourceFreq /* [412] */
    .long CDirect3DDevice_SetIndices /* [416] */
    .long CDirect3DDevice_GetIndices /* [420] */
    .long CDirect3DDevice_CreatePixelShader /* [424] */
    .long CDirect3DDevice_SetPixelShader /* [428] */
    .long CDirect3DDevice_GetPixelShader /* [432] */
    .long CDirect3DDevice_SetPixelShaderConstantF /* [436] */
    .long CDirect3DDevice_GetPixelShaderConstantF /* [440] */
    .long CDirect3DDevice_SetPixelShaderConstantI /* [444] */
    .long CDirect3DDevice_GetPixelShaderConstantI /* [448] */
    .long CDirect3DDevice_SetPixelShaderConstantB /* [452] */
    .long CDirect3DDevice_GetPixelShaderConstantB /* [456] */
    .long CDirect3DDevice_DrawRectPatch /* [460] */
    .long CDirect3DDevice_DrawTriPatch /* [464] */
    .long CDirect3DDevice_DeletePatch /* [468] */
    .long CDirect3DDevice_CreateQuery /* [472] */
    .long ZN15CDirect3DDeviceD1Ev /* [476] */
    .long ZN15CDirect3DDeviceD0Ev /* [480] */
    .long 0 /* [484] NULL */
.size vtbl_CDirect3DDevice, .-vtbl_CDirect3DDevice

.globl vtbl_CDirect3DIndexBuffer
.type vtbl_CDirect3DIndexBuffer, @object
.align 4
vtbl_CDirect3DIndexBuffer: /* orig: 0x32f9a8 */
    .long CDirect3DIndexBuffer_QueryInterface /* [0] */
    .long CDirect3DIndexBuffer_AddRef /* [4] */
    .long CDirect3DIndexBuffer_Release /* [8] */
    .long CDirect3DIndexBuffer_GetDevice /* [12] */
    .long CDirect3DIndexBuffer_SetPrivateData /* [16] */
    .long CDirect3DIndexBuffer_GetPrivateData /* [20] */
    .long CDirect3DIndexBuffer_FreePrivateData /* [24] */
    .long CDirect3DIndexBuffer_SetPriority /* [28] */
    .long CDirect3DIndexBuffer_GetPriority /* [32] */
    .long CDirect3DIndexBuffer_PreLoad /* [36] */
    .long CDirect3DIndexBuffer_GetType /* [40] */
    .long CDirect3DIndexBuffer_Lock /* [44] */
    .long CDirect3DIndexBuffer_Unlock /* [48] */
    .long CDirect3DIndexBuffer_GetDesc /* [52] */
    .long ZN20CDirect3DIndexBufferD1Ev /* [56] */
    .long ZN20CDirect3DIndexBufferD0Ev /* [60] */
.size vtbl_CDirect3DIndexBuffer, .-vtbl_CDirect3DIndexBuffer

.globl vtbl_CDirect3DPixelShader_base
.type vtbl_CDirect3DPixelShader_base, @object
.align 4
vtbl_CDirect3DPixelShader_base: /* orig: 0x32fa08 */
    .long CDirect3DPixelShader_QueryInterface /* [0] */
    .long CDirect3DPixelShader_AddRef /* [4] */
    .long CDirect3DPixelShader_Release /* [8] */
    .long CDirect3DPixelShader_GetDevice /* [12] */
    .long CDirect3DPixelShader_GetFunction /* [16] */
    .long ZN20CDirect3DPixelShaderD1Ev /* [20] */
    .long ZN20CDirect3DPixelShaderD0Ev /* [24] */
.size vtbl_CDirect3DPixelShader_base, .-vtbl_CDirect3DPixelShader_base

.globl vtbl_CDirect3DPixelShader_ATI
.type vtbl_CDirect3DPixelShader_ATI, @object
.align 4
vtbl_CDirect3DPixelShader_ATI: /* orig: 0x32fa48 */
    .long CDirect3DPixelShader_QueryInterface /* [0] */
    .long CDirect3DPixelShader_AddRef /* [4] */
    .long CDirect3DPixelShader_Release /* [8] */
    .long CDirect3DPixelShader_GetDevice /* [12] */
    .long CDirect3DPixelShader_GetFunction /* [16] */
    .long ZN28COpenGLATITextFragmentShaderD1Ev /* [20] */
    .long ZN28COpenGLATITextFragmentShaderD0Ev /* [24] */
    .long COpenGLATITextFragmentShader_Enable /* [28] */
    .long COpenGLATITextFragmentShader_Disable /* [32] */
    .long COpenGLATITextFragmentShader_SetConstants /* [36] */
.size vtbl_CDirect3DPixelShader_ATI, .-vtbl_CDirect3DPixelShader_ATI

.globl vtbl_CDirect3DPixelShader_NVidia
.type vtbl_CDirect3DPixelShader_NVidia, @object
.align 4
vtbl_CDirect3DPixelShader_NVidia: /* orig: 0x32fa88 */
    .long CDirect3DPixelShader_QueryInterface /* [0] */
    .long CDirect3DPixelShader_AddRef /* [4] */
    .long CDirect3DPixelShader_Release /* [8] */
    .long CDirect3DPixelShader_GetDevice /* [12] */
    .long CDirect3DPixelShader_GetFunction /* [16] */
    .long ZN37COpenGLNVidiaRegisterCombinersProgramD1Ev /* [20] */
    .long ZN37COpenGLNVidiaRegisterCombinersProgramD0Ev /* [24] */
    .long COpenGLNVidiaRegisterCombinersProgram_Enable /* [28] */
    .long COpenGLNVidiaRegisterCombinersProgram_Disable /* [32] */
    .long COpenGLNVidiaRegisterCombinersProgram_SetConstants /* [36] */
.size vtbl_CDirect3DPixelShader_NVidia, .-vtbl_CDirect3DPixelShader_NVidia

.globl vtbl_CDirect3DPixelShader_ARB
.type vtbl_CDirect3DPixelShader_ARB, @object
.align 4
vtbl_CDirect3DPixelShader_ARB: /* orig: 0x32fac8 */
    .long CDirect3DPixelShader_QueryInterface /* [0] */
    .long CDirect3DPixelShader_AddRef /* [4] */
    .long CDirect3DPixelShader_Release /* [8] */
    .long CDirect3DPixelShader_GetDevice /* [12] */
    .long CDirect3DPixelShader_GetFunction /* [16] */
    .long ZN25COpenGLARBFragmentProgramD1Ev /* [20] */
    .long ZN25COpenGLARBFragmentProgramD0Ev /* [24] */
    .long COpenGLARBFragmentProgram_Enable /* [28] */
    .long COpenGLARBFragmentProgram_Disable /* [32] */
    .long COpenGLARBFragmentProgram_SetConstants /* [36] */
.size vtbl_CDirect3DPixelShader_ARB, .-vtbl_CDirect3DPixelShader_ARB

.globl vtbl_CDirect3DSurface
.type vtbl_CDirect3DSurface, @object
.align 4
vtbl_CDirect3DSurface: /* orig: 0x32fb08 */
    .long CDirect3DSurface_QueryInterface /* [0] */
    .long CDirect3DSurface_AddRef /* [4] */
    .long CDirect3DSurface_Release /* [8] */
    .long CDirect3DSurface_GetDevice /* [12] */
    .long CDirect3DSurface_SetPrivateData /* [16] */
    .long CDirect3DSurface_GetPrivateData /* [20] */
    .long CDirect3DSurface_FreePrivateData /* [24] */
    .long CDirect3DSurface_SetPriority /* [28] */
    .long CDirect3DSurface_GetPriority /* [32] */
    .long CDirect3DSurface_PreLoad /* [36] */
    .long CDirect3DSurface_GetType /* [40] */
    .long CDirect3DSurface_GetContainer /* [44] */
    .long CDirect3DSurface_GetDesc /* [48] */
    .long CDirect3DSurface_LockRect /* [52] */
    .long CDirect3DSurface_UnlockRect /* [56] */
    .long CDirect3DSurface_GetDC /* [60] */
    .long CDirect3DSurface_ReleaseDC /* [64] */
    .long ZN16CDirect3DSurfaceD1Ev /* [68] */
    .long ZN16CDirect3DSurfaceD0Ev /* [72] */
.size vtbl_CDirect3DSurface, .-vtbl_CDirect3DSurface

.globl vtbl_CDirect3DSwapChain
.type vtbl_CDirect3DSwapChain, @object
.align 4
vtbl_CDirect3DSwapChain: /* orig: 0x32fb68 */
    .long CDirect3DSwapChain_QueryInterface /* [0] */
    .long CDirect3DSwapChain_AddRef /* [4] */
    .long CDirect3DSwapChain_Release /* [8] */
    .long CDirect3DSwapChain_Present /* [12] */
    .long CDirect3DSwapChain_GetFrontBufferData /* [16] */
    .long CDirect3DSwapChain_GetBackBuffer /* [20] */
    .long CDirect3DSwapChain_GetRasterStatus /* [24] */
    .long CDirect3DSwapChain_GetDisplayMode /* [28] */
    .long CDirect3DSwapChain_GetDevice /* [32] */
    .long CDirect3DSwapChain_GetPresentParameters /* [36] */
    .long ZN18CDirect3DSwapChainD1Ev /* [40] */
    .long ZN18CDirect3DSwapChainD0Ev /* [44] */
.size vtbl_CDirect3DSwapChain, .-vtbl_CDirect3DSwapChain

.globl vtbl_CDirect3DTexture
.type vtbl_CDirect3DTexture, @object
.align 4
vtbl_CDirect3DTexture: /* orig: 0x32fba8 */
    .long CDirect3DTexture_QueryInterface /* [0] */
    .long CDirect3DTexture_AddRef /* [4] */
    .long CDirect3DTexture_Release /* [8] */
    .long CDirect3DTexture_GetDevice /* [12] */
    .long CDirect3DTexture_SetPrivateData /* [16] */
    .long CDirect3DTexture_GetPrivateData /* [20] */
    .long CDirect3DTexture_FreePrivateData /* [24] */
    .long CDirect3DTexture_SetPriority /* [28] */
    .long CDirect3DTexture_GetPriority /* [32] */
    .long CDirect3DTexture_PreLoad /* [36] */
    .long CDirect3DTexture_GetType /* [40] */
    .long CDirect3DTexture_SetLOD /* [44] */
    .long CDirect3DTexture_GetLOD /* [48] */
    .long CDirect3DTexture_GetLevelCount /* [52] */
    .long CDirect3DTexture_SetAutoGenFilterType /* [56] */
    .long CDirect3DTexture_GetAutoGenFilterType /* [60] */
    .long CDirect3DTexture_GenerateMipSubLevels /* [64] */
    .long CDirect3DTexture_GetLevelDesc /* [68] */
    .long CDirect3DTexture_GetSurfaceLevel /* [72] */
    .long CDirect3DTexture_LockRect /* [76] */
    .long CDirect3DTexture_UnlockRect /* [80] */
    .long CDirect3DTexture_AddDirtyRect /* [84] */
    .long ZN16CDirect3DTextureD1Ev /* [88] */
    .long ZN16CDirect3DTextureD0Ev /* [92] */
.size vtbl_CDirect3DTexture, .-vtbl_CDirect3DTexture

.globl vtbl_CDirect3DTexture_secondary
.type vtbl_CDirect3DTexture_secondary, @object
.align 4
vtbl_CDirect3DTexture_secondary: /* orig: 0x32fc10 */
    .long ZThn4_N16CDirect3DTextureD1Ev /* [0] thunk */
    .long ZThn4_N16CDirect3DTextureD0Ev /* [4] thunk */
    .long COpenGLTexture_UpdateOpenGLSurfaces /* [8] */
.size vtbl_CDirect3DTexture_secondary, .-vtbl_CDirect3DTexture_secondary

.globl vtbl_CStaticCacheInfo
.type vtbl_CStaticCacheInfo, @object
.align 4
vtbl_CStaticCacheInfo: /* orig: 0x32fc28 */
    .long ZN16CStaticCacheInfoD1Ev /* [0] */
    .long ZN16CStaticCacheInfoD0Ev /* [4] */
.size vtbl_CStaticCacheInfo, .-vtbl_CStaticCacheInfo

.globl vtbl_CDirect3DVertexBuffer
.type vtbl_CDirect3DVertexBuffer, @object
.align 4
vtbl_CDirect3DVertexBuffer: /* orig: 0x32fc48 */
    .long CDirect3DVertexBuffer_QueryInterface /* [0] */
    .long CDirect3DVertexBuffer_AddRef /* [4] */
    .long CDirect3DVertexBuffer_Release /* [8] */
    .long CDirect3DVertexBuffer_GetDevice /* [12] */
    .long CDirect3DVertexBuffer_SetPrivateData /* [16] */
    .long CDirect3DVertexBuffer_GetPrivateData /* [20] */
    .long CDirect3DVertexBuffer_FreePrivateData /* [24] */
    .long CDirect3DVertexBuffer_SetPriority /* [28] */
    .long CDirect3DVertexBuffer_GetPriority /* [32] */
    .long CDirect3DVertexBuffer_PreLoad /* [36] */
    .long CDirect3DVertexBuffer_GetType /* [40] */
    .long CDirect3DVertexBuffer_Lock /* [44] */
    .long CDirect3DVertexBuffer_Unlock /* [48] */
    .long CDirect3DVertexBuffer_GetDesc /* [52] */
    .long ZN21CDirect3DVertexBufferD1Ev /* [56] */
    .long ZN21CDirect3DVertexBufferD0Ev /* [60] */
.size vtbl_CDirect3DVertexBuffer, .-vtbl_CDirect3DVertexBuffer

.globl vtbl_CDirect3DVertexDeclaration
.type vtbl_CDirect3DVertexDeclaration, @object
.align 4
vtbl_CDirect3DVertexDeclaration: /* orig: 0x32fca8 */
    .long CDirect3DVertexDeclaration_QueryInterface /* [0] */
    .long CDirect3DVertexDeclaration_AddRef /* [4] */
    .long CDirect3DVertexDeclaration_Release /* [8] */
    .long CDirect3DVertexDeclaration_GetDevice /* [12] */
    .long CDirect3DVertexDeclaration_GetDeclaration /* [16] */
    .long ZN26CDirect3DVertexDeclarationD1Ev /* [20] */
    .long ZN26CDirect3DVertexDeclarationD0Ev /* [24] */
.size vtbl_CDirect3DVertexDeclaration, .-vtbl_CDirect3DVertexDeclaration

.globl vtbl_CDirect3DVertexShader
.type vtbl_CDirect3DVertexShader, @object
.align 4
vtbl_CDirect3DVertexShader: /* orig: 0x32fce8 */
    .long CDirect3DVertexShader_QueryInterface /* [0] */
    .long CDirect3DVertexShader_AddRef /* [4] */
    .long CDirect3DVertexShader_Release /* [8] */
    .long CDirect3DVertexShader_GetDevice /* [12] */
    .long CDirect3DVertexShader_GetFunction /* [16] */
    .long ZN21CDirect3DVertexShaderD1Ev /* [20] */
    .long ZN21CDirect3DVertexShaderD0Ev /* [24] */
.size vtbl_CDirect3DVertexShader, .-vtbl_CDirect3DVertexShader

.globl vtbl_CDirect3DVertexShader_secondary
.type vtbl_CDirect3DVertexShader_secondary, @object
.align 4
vtbl_CDirect3DVertexShader_secondary: /* orig: 0x32fd0c */
    .long ZThn4_N21CDirect3DVertexShaderD1Ev /* [0] thunk */
    .long ZThn4_N21CDirect3DVertexShaderD0Ev /* [4] thunk */
.size vtbl_CDirect3DVertexShader_secondary, .-vtbl_CDirect3DVertexShader_secondary

.globl vtbl_CMemoryBuffer
.type vtbl_CMemoryBuffer, @object
.align 4
vtbl_CMemoryBuffer: /* orig: 0x32fd28 */
    .long ZN13CMemoryBufferD1Ev /* [0] */
    .long ZN13CMemoryBufferD0Ev /* [4] */
.size vtbl_CMemoryBuffer, .-vtbl_CMemoryBuffer

.globl vtbl_COpenGL
.type vtbl_COpenGL, @object
.align 4
vtbl_COpenGL: /* orig: 0x32fd48 */
    .long ZN7COpenGLD1Ev /* [0] */
    .long ZN7COpenGLD0Ev /* [4] */
.size vtbl_COpenGL, .-vtbl_COpenGL

.globl vtbl_COpenGLVertexProgram
.type vtbl_COpenGLVertexProgram, @object
.align 4
vtbl_COpenGLVertexProgram: /* orig: 0x32fd58 */
    .long ZN20COpenGLVertexProgramD1Ev /* [0] */
    .long ZN20COpenGLVertexProgramD0Ev /* [4] */
.size vtbl_COpenGLVertexProgram, .-vtbl_COpenGLVertexProgram

.globl vtbl_CVAOPacket
.type vtbl_CVAOPacket, @object
.align 4
vtbl_CVAOPacket: /* orig: 0x3322a8 */
    .long ZN10CVAOPacketD1Ev /* [0] D1 destructor */
    .long ZN10CVAOPacketD0Ev /* [4] D0 destructor */
    .long CVAOPacket_IsFixedFunction /* [8] IsFixedFunction */
.size vtbl_CVAOPacket, .-vtbl_CVAOPacket

.globl vtbl_CD3DXBuffer
.type vtbl_CD3DXBuffer, @object
.align 4
vtbl_CD3DXBuffer: /* orig: 0x332428 */
    .long CD3DXBuffer_QueryInterface    /* [0x00] */
    .long CD3DXBuffer_AddRef            /* [0x04] */
    .long CD3DXBuffer_Release           /* [0x08] */
    .long CD3DXBuffer_GetBufferPointer  /* [0x0c] */
    .long CD3DXBuffer_GetBufferSize     /* [0x10] */
    .long ZN11CD3DXBufferD1Ev           /* [0x14] D1 destructor */
    .long ZN11CD3DXBufferD0Ev           /* [0x18] D0 destructor */
.size vtbl_CD3DXBuffer, .-vtbl_CD3DXBuffer

.globl vtbl_CD3DXConstantTable
.type vtbl_CD3DXConstantTable, @object
.align 4
vtbl_CD3DXConstantTable: /* orig: 0x332468 */
    .long CD3DXConstantTable_QueryInterface    /* [0x00] */
    .long CD3DXConstantTable_AddRef            /* [0x04] */
    .long CD3DXConstantTable_Release           /* [0x08] */
    .long CD3DXConstantTable_GetBufferPointer  /* [0x0c] */
    .long CD3DXConstantTable_GetBufferSize     /* [0x10] */
    .long CD3DXConstantTable_GetDesc           /* [0x14] */
    .long CD3DXConstantTable_GetConstantDesc   /* [0x18] */
    .long CD3DXConstantTable_GetSamplerIndex   /* [0x1c] */
    .long CD3DXConstantTable_GetConstant       /* [0x20] */
    .long CD3DXConstantTable_GetConstantByName /* [0x24] */
    .long CD3DXConstantTable_GetConstantElement /* [0x28] */
    .long CD3DXConstantTable_SetDefaults       /* [0x2c] */
    .long CD3DXConstantTable_SetValue          /* [0x30] */
    .long CD3DXConstantTable_SetBool           /* [0x34] */
    .long CD3DXConstantTable_SetBoolArray      /* [0x38] */
    .long CD3DXConstantTable_SetInt            /* [0x3c] */
    .long CD3DXConstantTable_SetIntArray       /* [0x40] */
    .long CD3DXConstantTable_SetFloat          /* [0x44] */
    .long CD3DXConstantTable_SetFloatArray     /* [0x48] */
    .long CD3DXConstantTable_SetVector         /* [0x4c] */
    .long CD3DXConstantTable_SetVectorArray    /* [0x50] */
    .long CD3DXConstantTable_SetMatrix         /* [0x54] */
    .long CD3DXConstantTable_SetMatrixArray    /* [0x58] */
    .long CD3DXConstantTable_SetMatrixPointerArray   /* [0x5c] */
    .long CD3DXConstantTable_SetMatrixTranspose      /* [0x60] */
    .long CD3DXConstantTable_SetMatrixTransposeArray /* [0x64] */
    .long CD3DXConstantTable_SetMatrixTransposePointerArray /* [0x68] */
    .long ZN18CD3DXConstantTableD1Ev           /* [0x6c] D1 destructor */
    .long ZN18CD3DXConstantTableD0Ev           /* [0x70] D0 destructor */
.size vtbl_CD3DXConstantTable, .-vtbl_CD3DXConstantTable

