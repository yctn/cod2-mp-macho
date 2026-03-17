/* Clean D3DXTex implementation for Linux/WASM */
/* Debug visualization tools — stubbed since they use fixed-function GL (glBegin/glEnd) */
/* Original: /Users/kevin/Development/i5works/COD2/Project/Mac/DirectX 9/D3DXTex.cpp */

#include "common_types.h"
#include "imports.h"

int g_NumShadowCookies = 0;
int g_ShadowCookieMemory = 0;

/* Debug texture viewer — uses fixed-function GL, not available in WebGL2. No-op. */
void ViewSingleTexture(GLuint TextureID, IDirect3DDevice9 *pDevice, LPCVOID pSrcData, UINT SrcDataSize, IDirect3DCubeTexture9 **ppCubeTexture, IDirect3DDevice9 *pDevice_5, LPCVOID pSrcData_6, UINT SrcDataSize_7, IDirect3DTexture9 **ppTexture)
{
    (void)TextureID; (void)pDevice; (void)pSrcData; (void)SrcDataSize;
    (void)ppCubeTexture; (void)pDevice_5; (void)pSrcData_6; (void)SrcDataSize_7;
    (void)ppTexture;
}

/* Debug shadow cookie display — uses fixed-function GL. No-op. */
void ShowShadowCookies(void)
{
    g_NumShadowCookies = 0;
}
