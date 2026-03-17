/* Clean CDirect3D (IDirect3D9) implementation for Linux/WebGL2 */
/* Factory object: creates device, enumerates display modes */

#include "common_types.h"
#include "imports.h"
#include <stdlib.h>
#include <string.h>

extern void *vtbl_CDirect3D[];
extern void *vtbl_CDirect3DDevice[];

/* Device constructor — defined in CDirect3DDevice.c */
void CDirect3DDevice_Init(void *device);

/* The CDirect3D object */
typedef struct {
    void **vtable;
    ULONG refCount;
} CDirect3DImpl;

static CDirect3DImpl g_d3d9;

/* --- IUnknown --- */

HRESULT CDirect3D_QueryInterface(const void *_this, const IID *iid, void **ppvObj)
{
    (void)iid;
    *ppvObj = (void *)_this;
    return 0;
}

ULONG CDirect3D_AddRef(const void *_this) { (void)_this; return ++g_d3d9.refCount; }
ULONG CDirect3D_Release(const void *_this) { (void)_this; return --g_d3d9.refCount; }

/* --- IDirect3D9 --- */

HRESULT CDirect3D_RegisterSoftwareDevice(const void *_this, void *pInitializeFunction)
{
    (void)_this; (void)pInitializeFunction;
    return 0;
}

UINT CDirect3D_GetAdapterCount(const void *_this)
{
    (void)_this;
    return 1;
}

HRESULT CDirect3D_GetAdapterIdentifier(const void *_this, UINT Adapter, DWORD Flags, void *pIdentifier)
{
    (void)_this; (void)Adapter; (void)Flags;
    memset(pIdentifier, 0, 1024); /* D3DADAPTER_IDENTIFIER9 */
    return 0;
}

UINT CDirect3D_GetAdapterModeCount(const void *_this, UINT Adapter, D3DFORMAT Format)
{
    (void)_this; (void)Adapter; (void)Format;
    return 1; /* Report single mode */
}

HRESULT CDirect3D_EnumAdapterModes(const void *_this, UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE *pMode)
{
    /* D3DDISPLAYMODE layout: Width(+0), Height(+4), RefreshRate(+8), Format(+12)
       (common_types.h has wrong field names due to decompiler artifact) */
    int *p = (int *)pMode;
    (void)_this; (void)Adapter; (void)Format; (void)Mode;
    p[0] = 1024;  /* Width */
    p[1] = 768;   /* Height */
    p[2] = 60;    /* RefreshRate */
    p[3] = 22;    /* D3DFMT_X8R8G8B8 */
    return 0;
}

HRESULT CDirect3D_GetAdapterDisplayMode(const void *_this, UINT Adapter, D3DDISPLAYMODE *pMode)
{
    int *p = (int *)pMode;
    (void)_this; (void)Adapter;
    p[0] = 1024; p[1] = 768; p[2] = 60; p[3] = 22;
    return 0;
}

HRESULT CDirect3D_CheckDeviceType(const void *t, UINT a, int dt, D3DFORMAT ab, D3DFORMAT bb, BOOL w) { (void)t; (void)a; (void)dt; (void)ab; (void)bb; (void)w; return 0; }
HRESULT CDirect3D_CheckDeviceFormat(const void *t, UINT a, int dt, D3DFORMAT af, DWORD u, int rt, D3DFORMAT cf) { (void)t; (void)a; (void)dt; (void)af; (void)u; (void)rt; (void)cf; return 0; }
HRESULT CDirect3D_CheckDeviceMultiSampleType(const void *t, UINT a, int dt, D3DFORMAT sf, BOOL w, int ms, DWORD *q) { (void)t; (void)a; (void)dt; (void)sf; (void)w; (void)ms; (void)q; return 0; }
HRESULT CDirect3D_CheckDepthStencilMatch(const void *t, UINT a, int dt, D3DFORMAT af, D3DFORMAT rt, D3DFORMAT ds) { (void)t; (void)a; (void)dt; (void)af; (void)rt; (void)ds; return 0; }
HRESULT CDirect3D_CheckDeviceFormatConversion(const void *t, UINT a, int dt, D3DFORMAT sf, D3DFORMAT tf) { (void)t; (void)a; (void)dt; (void)sf; (void)tf; return 0; }

HRESULT CDirect3D_GetDeviceCaps(const void *_this, UINT Adapter, int DeviceType, void *pCaps)
{
    (void)_this; (void)Adapter; (void)DeviceType;
    /* Fill with reasonable WebGL2 caps */
    memset(pCaps, 0, 304); /* D3DCAPS9 size */
    return 0;
}

void *CDirect3D_GetAdapterMonitor(const void *_this, UINT Adapter)
{
    (void)_this; (void)Adapter;
    return NULL;
}

HRESULT CDirect3D_CreateDevice(const void *_this, UINT Adapter, int DeviceType, void *hFocusWindow, DWORD BehaviorFlags, void *pPresentationParameters, void **ppReturnedDeviceInterface)
{
    static char deviceMem[4096]; /* generous static allocation for device struct */

    (void)_this; (void)Adapter; (void)DeviceType; (void)hFocusWindow;
    (void)BehaviorFlags; (void)pPresentationParameters;

    memset(deviceMem, 0, sizeof(deviceMem));
    *(void ***)deviceMem = vtbl_CDirect3DDevice; /* set vtable */
    CDirect3DDevice_Init(deviceMem);
    *ppReturnedDeviceInterface = deviceMem;
    return 0;
}

/* --- Destructors --- */

void ZN9CDirect3DD1Ev(const void *_this) { (void)_this; }
void ZN9CDirect3DD0Ev(const void *_this) { (void)_this; }

/* --- Direct3DCreate9 entry point --- */

int Direct3DCreate9(int sdkVersion)
{
    (void)sdkVersion;
    g_d3d9.vtable = vtbl_CDirect3D;
    g_d3d9.refCount = 1;
    return (int)(unsigned long)&g_d3d9;
}
