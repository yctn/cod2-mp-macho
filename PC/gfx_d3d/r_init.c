/* ASM dump from: r_init.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_init.cpp */

#include "common_types.h"
#include "imports.h"
#include <stdio.h>
#include <stdarg.h>

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/r_local.h"
 *   #include "PC/universal/com_math.h"
 */

extern int alwaysfails; /* 0x0 */
extern int g_disableRendering; /* 0x0 */
extern struct DxGlobals dx; /* 0x0 */
extern struct r_global_permanent_t rgp; /* 0x0 */
extern struct r_globals_t rg; /* 0x0 */
extern refimport_t ri; /* 0x0 */
extern vidConfig_t vidConfig; /* 0x0 */
extern const char * DXGetErrorDescription9A(HRESULT hr);
extern void Material_FinishLoading(void);
extern void R_AddCmdTouchAllImages(void);
extern void R_InitImages(void);
extern void Material_Init(void);
extern int R_InitFonts(void);
extern void R_InitLightDefs(void);
extern void R_ClearFogs(void);
extern void R_InitDebug(void);
extern void * R_AllocStaticVertexBuffer(void *outBuf, int size);
extern void * R_AllocStaticIndexBuffer(void *outBuf, int size);
extern void R_FinishStaticVertexBuffer(void *buf);
extern void R_FinishStaticIndexBuffer(void *buf);
extern int rand(void);
extern void R_ShutdownRenderTargets(void);
extern void R_ShutdownStaticModelCache(void);
extern void R_FreeStaticVertexBuffer(void *buf);
extern void R_FreeStaticIndexBuffer(void *buf);
extern void WinSleep(int ms);
extern void R_ShutdownBackendData(void);
extern void R_ShutdownDebug(void);
extern void RB_SaveLightVisHistory(void);
extern void R_ShutdownLightDefs(void);
extern void R_ShutdownWorld(void);
extern void R_ShutdownFonts(void);
extern void R_ShutdownModels(void);
extern void Material_Shutdown(void);
extern void R_ShutdownImages(void);
extern void R_UnlockSkinnedCache(void);
extern void R_FlushStaticModelCache(void);
extern void R_UnregisterCmds(void);
extern void R_UnregisterDvars(void);
extern void RB_ClearAllStreamSources(void);
extern void R_EndDrawGroupLoop(int section, int viewIndex);
extern Bool Sys_IsMainThread(void);
extern void R_SyncRenderThread(void);
extern void RB_SetGammaRamp(const void *gammaTable);
extern int vsnprintf(char *, unsigned int, const char *, va_list);
extern double pow(double, double);
extern float floorf(float);
extern void R_EndDrawGroupSection(int section);
extern void R_IssueDrawGroups(void);

static vec2_t cornerTexCoords[4]; /* cornerTexCoords */
static const r_index_t quadIndices[6]; /* quadIndices */
refexport_t re; /* re */

void R_FatalInitError(const char *msg);
const char * R_ErrorDescription(HRESULT hr);
static void R_CreateParticleCloudBuffer(void);
static void R_ReleaseForShutdownOrReset(void);
static Bool R_DisplayModeLess(const _D3DDISPLAYMODE *mode0, const _D3DDISPLAYMODE *mode1);
static HRESULT R_CreateDevice(HWND hwnd, DWORD behavior);
void R_UpdateGpuSyncType(void);
void R_EndRegistration(void);
static void R_EndView(int viewIndex);
static void R_DoneRenderingViews(void);
static void R_TrackStatistics(trStatistics_t *stats);
refexport_t * GetRefAPI(int apiVersion, refimport_t *rimp);
void R_Error(errorParm_t errorLevel, const char *msg, ...);
void R_GammaCorrect(byte *buffer, int bufSize);
static void R_InitSystems(void);
void R_FatalLockError(HRESULT hr);
static void R_Shutdown(qboolean destroyWindow);
void R_SetColorMappings(void);
static Bool R_CreateForInitOrReset(void);
void R_BeginRegistration(vidConfig_t *vidConfigOut);
Bool R_RecoverLostDevice(void);
typedef unsigned char (*D3DDispModeCompFunc)(const _D3DDISPLAYMODE *, const _D3DDISPLAYMODE *);
void ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(_D3DDISPLAYMODE *first, int holeIndex, int len, _D3DDISPLAYMODE value, D3DDispModeCompFunc comp);
void ZSt16__insertion_sortIP15_D3DDISPLAYMODEPFhRKS0_S3_EEvT_S6_T0_(_D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, D3DDispModeCompFunc comp);
void ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_(_D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, int depth_limit, D3DDispModeCompFunc comp);

/* line 123 */
void R_FatalInitError(const char *msg)
{
    void (*printFunc)(int, const char *, ...) = *(void (**)(int, const char *, ...))&ri;
    printFunc(0, (const char *)str_002238dc);
    printFunc(0, (const char *)str_00223938);
    printFunc(0, (const char *)str_00223994);
    printFunc(0, "\n%s\n", msg);
    ((void (*)(void))*(void * *)((char *)&ri + 72))();
}

/* line 169 */
const char * R_ErrorDescription(HRESULT hr)
{
    return DXGetErrorDescription9A(hr);
}

/* line 629 */
/* line 629 — Create static vertex+index buffers for particle cloud rendering.
 * Generates 8x8x16 = 1024 particles, each with 4 vertices and 6 indices.
 * Vertices have randomized positions + corner texcoords. */
static void R_CreateParticleCloudBuffer(void)
{
    float *verts;
    unsigned short *indices;
    int xIter, yIter, zIter, corner;
    int vertexIndex = 0;

    verts = R_AllocStaticVertexBuffer((IDirect3DVertexBuffer9 **)((byte *)&dx + 11704), 0x14000);
    indices = R_AllocStaticIndexBuffer((IDirect3DIndexBuffer9 **)((byte *)&dx + 11708), 0x3000);

    for (xIter = 0; xIter < 8; xIter++) {
        float xBase = (float)xIter;
        int baseVertForX = xIter * 128; /* 8*16 particles per X slice, 4 verts each */

        for (yIter = 0; yIter < 8; yIter++) {
            float yBase = (float)yIter;

            for (zIter = 0; zIter < 16; zIter++) {
                /* Randomized particle position: map to [-1,1] cube */
                float px = ((float)rand() * 4.656612873077393e-10f + xBase) * 0.25f - 1.0f;
                float py = ((float)rand() * 4.656612873077393e-10f + yBase) * 0.25f - 1.0f;
                float pz = ((float)rand() * 4.656612873077393e-10f + (float)zIter) * 0.125f - 1.0f;

                /* 4 vertices per particle (billboard corners) */
                for (corner = 0; corner < 4; corner++) {
                    /* position (vec3) */
                    *verts++ = px;
                    *verts++ = py;
                    *verts++ = pz;
                    /* texcoord (vec2) from cornerTexCoords */
                    *verts++ = cornerTexCoords[corner][0];
                    *verts++ = cornerTexCoords[corner][1];
                }

                /* 6 indices per particle (2 triangles) from quadIndices template */
                {
                    int baseVert = (baseVertForX + zIter) * 4;
                    int qi;
                    for (qi = 0; qi < 6; qi++) {
                        *indices++ = (unsigned short)(baseVert + quadIndices[qi]);
                    }
                }
            }
            baseVertForX += 16; /* advance by particles in this Y row */
        }
    }

    R_FinishStaticIndexBuffer(*(void **)((byte *)&dx + 11708));
    R_FinishStaticVertexBuffer(*(void **)((byte *)&dx + 11704));
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 629 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x6c, %esp\n"
        /* { scope 1 */
        "movl $0x14000, 4(%esp)\n" /* line 649 */
        "movl $dx+11704, (%esp)\n"
        "calll R_AllocStaticVertexBuffer\n"
        "movl %eax, %ebx\n" /* particleVertsIter */
        "movl $0x3000, 4(%esp)\n" /* line 650 */
        "movl $dx+11708, (%esp)\n"
        "calll R_AllocStaticIndexBuffer\n"
        "movl %eax, -0x20(%ebp)\n"
        "movl %ebx, -0x1c(%ebp)\n" /* particleVertsIter */
        "movl $0, -0x44(%ebp)\n" /* xIter */
        ".Lfcab7e_000cabbe:\n"
        "cvtsi2ssl -0x44(%ebp), %xmm0\n" /* xIter */
        "movss %xmm0, -0x38(%ebp)\n"
        "movl -0x44(%ebp), %eax\n" /* xIter */
        "shll $7, %eax\n"
        "movw %ax, -0x2a(%ebp)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, -0x24(%ebp)\n"
        "movl $0, -0x40(%ebp)\n" /* yIter */
        ".Lfcab7e_000cabe5:\n"
        "cvtsi2ssl -0x40(%ebp), %xmm0\n" /* yIter */
        "movss %xmm0, -0x34(%ebp)\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x28(%ebp), %edi\n"
        "movl $0, -0x3c(%ebp)\n" /* zIter */
        "movl %eax, %esi\n" /* particleIndicesIter */
        ".Lfcab7e_000cabfe:\n"
        "movl %edi, %ebx\n" /* particleVertsIter */
        "calll rand\n" /* line 665 */
        "cvtsi2ssl %eax, %xmm3\n"
        "mulss lit4_002ed630, %xmm3\n" /* 4.656612873077393e-10f */
        "addss -0x38(%ebp), %xmm3\n"
        "mulss lit4_002ed604, %xmm3\n" /* 0.25f */
        "subss lit4_002ed5d0, %xmm3\n" /* 1.0f */
        "movss %xmm3, -0x68(%ebp)\n" /* line 666 */
        "calll rand\n"
        "cvtsi2ssl %eax, %xmm2\n"
        "mulss lit4_002ed630, %xmm2\n" /* 4.656612873077393e-10f */
        "addss -0x34(%ebp), %xmm2\n"
        "mulss lit4_002ed604, %xmm2\n" /* 0.25f */
        "subss lit4_002ed5d0, %xmm2\n" /* 1.0f */
        "movss %xmm2, -0x58(%ebp)\n" /* line 667 */
        "calll rand\n"
        "cvtsi2ssl %eax, %xmm1\n"
        "mulss lit4_002ed630, %xmm1\n" /* 4.656612873077393e-10f */
        "cvtsi2ssl -0x3c(%ebp), %xmm0\n" /* zIter */
        "addss %xmm0, %xmm1\n"
        "mulss lit4_002ed610, %xmm1\n" /* 0.125f */
        "subss lit4_002ed5d0, %xmm1\n" /* 1.0f */
        "xorl %ecx, %ecx\n"
        "xorl %edx, %edx\n"
        "movss -0x68(%ebp), %xmm3\n"
        "movss -0x58(%ebp), %xmm2\n"
        ".Lfcab7e_000cac8e:\n"
        "movss %xmm3, (%ebx)\n" /* line 199 */
        "movss %xmm2, 4(%ebx)\n" /* line 200 */
        "movss %xmm1, 8(%ebx)\n" /* line 201 */
        "movl cornerTexCoords(%edx), %eax\n" /* line 37 */
        "movl %eax, 0xc(%ebx)\n"
        "movl cornerTexCoords+4(%edx), %eax\n" /* line 38 */
        "movl %eax, 0x10(%ebx)\n"
        "addl $0x14, %ebx\n" /* line 673 | particleVertsIter */
        "addl $1, %ecx\n" /* line 669 */
        "addl $8, %edx\n"
        "cmpl $4, %ecx\n"
        "jne .Lfcab7e_000cac8e\n"
        "movzwl -0x2a(%ebp), %eax\n"
        "addl -0x3c(%ebp), %eax\n" /* zIter */
        "leal (, %eax, 4), %ecx\n"
        "movl $quadIndices, %edx\n"
        ".Lfcab7e_000caccf:\n"
        "movl %ecx, %eax\n" /* line 678 */
        "addw (%edx), %ax\n"
        "movw %ax, (%esi)\n" /* particleIndicesIter */
        "addl $2, %esi\n" /* line 680 | particleIndicesIter */
        "addl $2, %edx\n"
        "movl $quadIndices+12, %eax\n" /* line 676 */
        "cmpl %edx, %eax\n"
        "jne .Lfcab7e_000caccf\n"
        "addl $1, -0x3c(%ebp)\n" /* line 660 | zIter */
        "addl $0xc, -0x30(%ebp)\n"
        "addl $0x50, %edi\n"
        "cmpl $0x10, -0x3c(%ebp)\n" /* zIter */
        "je .Lfcab7e_000cacff\n"
        "movl -0x30(%ebp), %esi\n" /* particleIndicesIter */
        "jmp .Lfcab7e_000cabfe\n"
        ".Lfcab7e_000cacff:\n"
        "addl $1, -0x40(%ebp)\n" /* line 658 | yIter */
        "addw $0x10, -0x2a(%ebp)\n"
        "addl $0x500, -0x28(%ebp)\n"
        "addl $0xc0, -0x24(%ebp)\n"
        "cmpl $8, -0x40(%ebp)\n" /* yIter */
        "je .Lfcab7e_000cad24\n"
        "movl -0x24(%ebp), %eax\n"
        "jmp .Lfcab7e_000cabe5\n"
        ".Lfcab7e_000cad24:\n"
        "addl $1, -0x44(%ebp)\n" /* line 656 | xIter */
        "addl $0x600, -0x20(%ebp)\n"
        "addl $0x2800, -0x1c(%ebp)\n"
        "cmpl $8, -0x44(%ebp)\n" /* xIter */
        "jne .Lfcab7e_000cabbe\n"
        "movl dx+11708, %eax\n" /* line 687 */
        "movl %eax, (%esp)\n"
        "calll R_FinishStaticIndexBuffer\n"
        "movl dx+11704, %eax\n" /* line 688 */
        "movl %eax, (%esp)\n"
        "calll R_FinishStaticVertexBuffer\n"
        /* } scope */
        "addl $0x6c, %esp\n" /* line 695 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}
#endif

/* line 930 */
/* Helper: release a COM object and null the pointer */
static inline void R_SafeRelease(void **objPtr)
{
    void *obj = *objPtr;
    if (obj) {
        do {
            ((void (__attribute__((stdcall)) *)(void *))((*(void ***)obj)[2]))(obj);
            *objPtr = NULL;
        } while (*(int *)&alwaysfails);
    }
}

/* line 930 — Release all D3D resources for shutdown or device reset.
 * Releases swap chains, render targets, depth stencil, back buffer,
 * dynamic VB/IB lock slots, particle buffers, font surface, and sun flare textures. */
static void R_ReleaseForShutdownOrReset(void)
{
    byte *d = (byte *)&dx;
    int i;

    /* Release swap chain presentation surfaces */
    {
        int scCount = *(int *)(d + 11592);
        for (i = 0; i < scCount; i++) {
            void **psc = (void **)(d + 0x2d50 + i * 16);
            R_SafeRelease(psc);
        }
    }

    R_ShutdownRenderTargets();
    R_ShutdownStaticModelCache();

    /* Release depth stencil surface (dx+11656) */
    R_SafeRelease((void **)(d + 11656));

    /* Release back buffer surface (dx+11696) */
    R_SafeRelease((void **)(d + 11696));

    /* Release dynamic VB/IB lock slots (2 entries at dx+0x2d98, stride 12) */
    for (i = 0; i < 2; i++) {
        R_SafeRelease((void **)(d + 0x2d98 + i * 12));
    }

    /* Free shader cache buffer (dx+11728) */
    if (*(void **)(d + 11728)) {
        /* Call ri.Hunk_FreeTempMemory (ri+44) */
        ((void (*)(void *))*(void **)((byte *)&ri + 44))(*(void **)(d + 11728));
        *(void **)(d + 11728) = NULL;
        *(int *)(d + 11732) = 0;
    }

    /* Free particle cloud VB and IB */
    if (*(void **)(d + 11704)) {
        R_FreeStaticVertexBuffer(*(void **)(d + 11704));
        *(void **)(d + 11704) = NULL;
    }
    if (*(void **)(d + 11708)) {
        R_FreeStaticIndexBuffer(*(void **)(d + 11708));
        *(void **)(d + 11708) = NULL;
    }

    /* Release font surface (dx+11612) */
    R_SafeRelease((void **)(d + 11612));

    /* Release sun flare textures (4 views × 2 textures each) */
    {
        byte *sunFlare = (byte *)imp_sunFlareArray;
        int view;
        for (view = 0; view < 4; view++) {
            byte *viewBase = sunFlare + view * 0x30;
            int tex;
            for (tex = 0; tex < 2; tex++) {
                R_SafeRelease((void **)(viewBase + 0x24 + tex * 4));
            }
        }
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 930 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl dx+11592, %edx\n" /* line 936 */
        "testl %edx, %edx\n"
        "jg .Lfcad62_000caef3\n"
        ".Lfcad62_000cad79:\n"
        "calll R_ShutdownRenderTargets\n" /* line 943 */
        "calll R_ShutdownStaticModelCache\n" /* line 945 */
        "movl dx+11656, %eax\n" /* line 722 */
        "testl %eax, %eax\n"
        "je .Lfcad62_000cadac\n"
        ".Lfcad62_000cad8c:\n"
        "movl dx+11656, %eax\n" /* line 723 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, dx+11656\n"
        "movl alwaysfails, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcad62_000cad8c\n"
        ".Lfcad62_000cadac:\n"
        "movl dx+11696, %eax\n" /* line 729 */
        "testl %eax, %eax\n"
        "je .Lfcad62_000cadd5\n"
        ".Lfcad62_000cadb5:\n"
        "movl dx+11696, %eax\n" /* line 730 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, dx+11696\n"
        "movl alwaysfails, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcad62_000cadb5\n"
        ".Lfcad62_000cadd5:\n"
        "movl $dx, %esi\n"
        "movl $dx+24, %edi\n"
        ".Lfcad62_000caddf:\n"
        "leal 0x2d98(%esi), %ebx\n" /* line 930 */
        "movl 0x2d98(%esi), %eax\n" /* line 736 */
        "testl %eax, %eax\n"
        "je .Lfcad62_000cae08\n"
        ".Lfcad62_000cadef:\n"
        "movl (%ebx), %eax\n" /* line 737 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, (%ebx)\n"
        "movl alwaysfails, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcad62_000cadef\n"
        ".Lfcad62_000cae08:\n"
        "addl $0xc, %esi\n"
        "cmpl %esi, %edi\n" /* line 734 */
        "jne .Lfcad62_000caddf\n"
        "movl dx+11728, %eax\n" /* line 740 */
        "testl %eax, %eax\n"
        "je .Lfcad62_000cae35\n"
        "movl %eax, (%esp)\n" /* line 742 */
        "calll *ri+44\n"
        "movl $0, dx+11728\n" /* line 743 */
        "movl $0, dx+11732\n" /* line 744 */
        ".Lfcad62_000cae35:\n"
        "movl dx+11704, %eax\n" /* line 702 */
        "testl %eax, %eax\n"
        "je .Lfcad62_000cae50\n"
        "movl %eax, (%esp)\n" /* line 704 */
        "calll R_FreeStaticVertexBuffer\n"
        "movl $0, dx+11704\n" /* line 705 */
        ".Lfcad62_000cae50:\n"
        "movl dx+11708, %eax\n" /* line 708 */
        "testl %eax, %eax\n"
        "je .Lfcad62_000cae6b\n"
        "movl %eax, (%esp)\n" /* line 710 */
        "calll R_FreeStaticIndexBuffer\n"
        "movl $0, dx+11708\n" /* line 711 */
        ".Lfcad62_000cae6b:\n"
        "movl dx+11612, %ebx\n" /* line 952 */
        "testl %ebx, %ebx\n"
        "je .Lfcad62_000cae96\n"
        ".Lfcad62_000cae75:\n"
        "movl dx+11612, %eax\n" /* line 953 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, dx+11612\n"
        "movl alwaysfails, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcad62_000cae75\n"
        ".Lfcad62_000cae96:\n"
        "movl $0, -0x1c(%ebp)\n" /* viewIndex */
        "movl $0, -0x20(%ebp)\n"
        ".Lfcad62_000caea4:\n"
        "movl -0x20(%ebp), %esi\n" /* windowIndex */
        "addl imp_sunFlareArray, %esi\n" /* windowIndex */
        "movl $2, %edi\n"
        ".Lfcad62_000caeb2:\n"
        "leal 0x24(%esi), %ebx\n" /* line 930 */
        "movl 0x24(%esi), %edx\n" /* line 959 | windowIndex */
        "testl %edx, %edx\n"
        "je .Lfcad62_000caed5\n"
        ".Lfcad62_000caebc:\n"
        "movl (%ebx), %eax\n" /* line 960 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, (%ebx)\n"
        "movl alwaysfails, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcad62_000caebc\n"
        ".Lfcad62_000caed5:\n"
        "addl $4, %esi\n" /* windowIndex */
        "subl $1, %edi\n" /* line 957 */
        "jne .Lfcad62_000caeb2\n"
        "addl $1, -0x1c(%ebp)\n" /* line 955 | viewIndex */
        "addl $0x30, -0x20(%ebp)\n"
        "cmpl $4, -0x1c(%ebp)\n" /* viewIndex */
        "jne .Lfcad62_000caea4\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 963 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcad62_000caef3:\n"
        "xorl %esi, %esi\n" /* line 936 | windowIndex */
        "movl $dx, %ebx\n"
        /* { scope 2 */
        ".Lfcad62_000caefa:\n"
        "movl 0x2d50(%ebx), %eax\n" /* line 938 | psc */
        "movl (%eax), %edx\n" /* line 939 */
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, 0x2d50(%ebx)\n" /* line 940 */
        /* } scope */
        "addl $1, %esi\n" /* line 936 | windowIndex */
        "addl $0x10, %ebx\n"
        "cmpl dx+11592, %esi\n" /* windowIndex */
        "jl .Lfcad62_000caefa\n"
        "jmp .Lfcad62_000cad79\n"
    );
}
#endif

/* line 968 */
static Bool R_DisplayModeLess(const _D3DDISPLAYMODE *mode0, const _D3DDISPLAYMODE *mode1)
{
    if (mode0->Width > mode1->Width)
        return 0;
    if (mode0->Width < mode1->Width)
        return 1;
    if (mode0->Height > mode1->Height)
        return 0;
    if (mode0->Height < mode1->Height)
        return 1;
    return mode0->RefreshRate < mode1->RefreshRate;
}

/* line 1107 */
/* line 1107 — Create D3D device with retry logic. Uses register calling convention:
 * eax=hwnd, edx=behavior, ecx=d3dpp. Tries CreateDevice up to 20 times with 100ms
 * sleeps, falling back to adapter 0 if initial adapter fails. */
static HRESULT R_CreateDevice_impl(HWND hwnd, DWORD behavior, void *d3dpp)
{
    byte *d = (byte *)&dx;
    HRESULT hr;
    int attempt;

    for (;;) {
        /* Print "Creating D3D device..." */
        ((void (*)(int, const char *))*(void **)&ri)(0, "Creating D3D device...\n");

        for (attempt = 0; attempt < 20; attempt++) {
            /* IDirect3D9::CreateDevice (vtable[0x40/4] = index 16) */
            void *d3d9 = *(void **)(d + 4);
            void **vtable = *(void ***)d3d9;
            hr = ((HRESULT (__attribute__((stdcall)) *)(void *, int, int, HWND, DWORD, void *, void **))
                  vtable[0x40/4])(d3d9, *(int *)(d + 12), 1, hwnd, behavior, d3dpp, (void **)(d + 8));

            if (hr >= 0)
                return hr;

            WinSleep(100);
        }

        /* After 20 failures, try falling back to default adapter */
        if (*(int *)(d + 12) == 0)
            return hr; /* Already on adapter 0, give up */

        *(int *)(d + 12) = 0; /* Reset to default adapter and retry */
    }
}

static __attribute__((naked))
HRESULT R_CreateDevice(HWND hwnd, DWORD behavior)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll R_CreateDevice_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1107 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl %ecx, %edi\n" /* d3dpp */
        /* { scope 1 */
        ".Lfcaf5a_000caf6b:\n"
        "movl $str_002239f8, 4(%esp)\n" /* line 1113 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "xorl %esi, %esi\n" /* attempt */
        "jmp .Lfcaf5a_000caf98\n"
        ".Lfcaf5a_000caf84:\n"
        "movl $0x64, (%esp)\n" /* line 1120 */
        "calll WinSleep\n"
        "addl $1, %esi\n" /* line 1121 | attempt */
        "cmpl $0x14, %esi\n" /* line 1115 | attempt */
        "je .Lfcaf5a_000cafe1\n"
        ".Lfcaf5a_000caf98:\n"
        "movl dx+4, %eax\n" /* line 1117 */
        "movl (%eax), %ecx\n"
        "movl $dx+8, 0x18(%esp)\n"
        "movl %edi, 0x14(%esp)\n" /* d3dpp */
        "movl -0x20(%ebp), %edx\n"
        "movl %edx, 0x10(%esp)\n"
        "movl -0x1c(%ebp), %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl dx+12, %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x40(%ecx)\n"
        "movl %eax, %ebx\n" /* hr */
        "testl %eax, %eax\n" /* line 1118 */
        "js .Lfcaf5a_000caf84\n"
        /* } scope */
        ".Lfcaf5a_000cafd7:\n"
        "movl %ebx, %eax\n" /* line 1137 | hr */
        "addl $0x3c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfcaf5a_000cafe1:\n"
        "movl dx+12, %ecx\n" /* line 1124 */
        "testl %ecx, %ecx\n"
        "je .Lfcaf5a_000cafd7\n"
        "movl $0, dx+12\n" /* line 1126 */
        "jmp .Lfcaf5a_000caf6b\n"
    );
}
#endif

/* line 1256 */
void R_UpdateGpuSyncType(void)
{
    if (*(byte *)(*(int *)(*(int *)imp_r_multiGpu) + 8)) {
        *(int *)((char *)&dx + 11296) = 0;
    } else {
        *(int *)((char *)&dx + 11296) = *(int *)(*(int *)(*(int *)imp_r_gpuSync) + 8);
    }
}

/* line 2011 */
void R_EndRegistration(void)
{
    Material_FinishLoading();
    R_AddCmdTouchAllImages();
}

/* line 2025 */
static void R_EndView(int viewIndex)
{
    R_EndDrawGroupLoop(4, viewIndex);
    R_EndDrawGroupSection(4);
}

/* line 2032 */
static void R_DoneRenderingViews(void)
{
    R_IssueDrawGroups();
}

/* line 2038 */
static void R_TrackStatistics(trStatistics_t *stats)
{
    *(trStatistics_t * *)((char *)&rg + 12664) = stats;
}

/* line 2097 — GetRefAPI
 * Renderer DLL entry point: copies refimport function table, fills refexport table
 * with all renderer API function pointers, and returns it to the engine. */
refexport_t * GetRefAPI(int apiVersion, refimport_t *rimp)
{
    typedef void (*ri_Printf_fn)(int, const char *, ...);

    memcpy(&ri, rimp, sizeof(ri));
    memset(&re, 0, sizeof(re));

    if (apiVersion != 59) {
        ((ri_Printf_fn)(*(void **)&ri))(0, "Mismatched REF_API_VERSION: expected %i, got %i\n", 59, apiVersion);
        return NULL;
    }

    /* Fill refexport function pointer table — using byte offsets to match original ASM layout */
    byte *r = (byte *)&re;
    #define RE(off, fn) *(void **)(r + off) = (void *)(fn)

    /* Core lifecycle (offsets 0-68) */
    RE(0,   R_Shutdown);
    RE(4,   R_BeginRegistration);
    RE(8,   imp_R_RegisterModel);
    RE(12,  imp_R_RegisterInlineModel);
    RE(16,  imp_Material_RegisterHandle);
    RE(20,  imp_R_RegisterRawImage);
    RE(24,  imp_Material_IsDefault);
    RE(28,  imp_R_LoadWorld);
    RE(32,  imp_R_GetWorldBounds);
    RE(36,  imp_R_FinishLoadingModels);
    RE(40,  imp_R_SetIgnorePrecacheErrors);
    RE(44,  imp_R_GetIgnorePrecacheErrors);
    RE(48,  imp_R_GetMinSpecImageMemory);
    RE(52,  imp_R_GetMaterialName);
    RE(56,  imp_R_GetMaterialSubimageCount);
    RE(60,  imp_R_IsMaterialRefractive);
    RE(64,  imp_R_GetFarPlaneDist);
    RE(68,  R_EndRegistration);

    /* Scene management (offsets 72-140) */
    RE(72,  imp_R_ClearScene);
    RE(76,  imp_R_DefaultVertexFrames);
    RE(80,  imp_R_AddPolyToScene);
    RE(84,  imp_R_AddLightToScene);
    RE(88,  imp_R_InterpretSunLightParseParams);
    RE(92,  imp_R_ResetSunLightParseParams);
    RE(96,  imp_R_SetCullDist);
    RE(100, imp_R_SetFog);
    RE(104, imp_R_SwitchFog);
    RE(108, imp_R_ArchiveFogState);
    RE(112, imp_R_ClearFogs);
    RE(116, imp_R_SetSunLightOverride);
    RE(120, imp_R_ResetSunLightOverride);
    RE(124, imp_R_RenderScene);
    RE(128, imp_R_BeginDelayedDrawing);
    RE(132, imp_R_EndDelayedDrawing);
    RE(136, imp_R_IssueDelayedDrawing);
    RE(140, imp_R_ClearFlares);

    /* 2D drawing (offsets 144-164) */
    RE(144, imp_R_AddCmdSetMaterialColor);
    RE(148, imp_R_AddCmdDrawStretchPic);
    RE(152, imp_R_AddCmdDrawStretchPicRotate);
    RE(156, imp_R_AddCmdDrawStretchRaw);
    RE(160, imp_R_AddCmdDrawQuadPic);
    RE(164, imp_R_AddCmdDrawSprite);

    /* Frame control (offsets 168-212) */
    RE(168, imp_R_BeginFrame);
    RE(172, imp_R_EndFrame);
    RE(176, imp_R_BeginDebugFrame);
    RE(180, imp_R_EndDebugFrame);
    RE(184, R_EndView);
    RE(188, R_DoneRenderingViews);
    RE(192, imp_R_AddCmdSaveScreen);
    RE(196, imp_R_AddCmdBlendSavedScreen);
    RE(200, imp_R_AddCmdClearScreen);
    RE(204, imp_R_AddCmdSetViewport);
    RE(208, imp_R_MarkFragments);
    RE(212, imp_R_ModelBounds);

    /* Statistics (offsets 216-220) */
    RE(216, R_TrackStatistics);
    RE(220, imp_R_PickMaterial);

    /* Font / image (offsets 224-248) */
    RE(224, imp_R_RegisterFont);
    RE(228, imp_R_ResetImageAllocations);
    RE(232, imp_R_FreeImageAllocations);
    RE(236, imp_R_BeginCubemapShot);
    RE(240, imp_R_EndCubemapShot);
    RE(244, imp_R_SaveCubemapShot);
    RE(248, imp_R_LightingFromCubemapShots);

    /* Debug (offsets 252-264) */
    RE(252, imp_R_LocateDebugStrings);
    RE(256, imp_R_LocateDebugLines);
    RE(260, imp_R_AddPlume);
    RE(264, imp_R_ShutdownDebug);

    /* Backend / text (offsets 268-348) */
    RE(268, imp_RB_UpdateColor);
    RE(272, imp_R_NormalizedTextScale);
    RE(276, imp_R_TextWidth);
    RE(280, imp_R_TextHeight);
    RE(284, imp_R_DrawText);
    RE(288, imp_R_AddCmdDrawTextInSpace);
    RE(292, imp_R_ConsoleTextWidth);
    RE(296, imp_R_DrawConsoleText);
    RE(300, imp_R_AddCmdDrawTextWithCursor);
    RE(304, imp_R_DObjGetSurfMaterials);
    RE(308, imp_R_DObjReplaceMaterial);
    RE(312, imp_R_ParseSunLight);
    RE(316, imp_Material_Duplicate);
    RE(320, imp_R_DuplicateFont);
    *(byte *)(r + 324) = 1; /* initialized flag */
    RE(328, imp_R_SyncRenderThread);
    RE(332, imp_R_AbortRenderCommands);
    RE(336, imp_RB_IsGpuFenceFinished);
    RE(340, imp_RB_AdaptiveGpuSyncWait);
    RE(344, imp_RB_GpuWaited);
    RE(348, imp_R_SetLodOrigin);

    #undef RE

    return &re;
}

/* line 2463 */
void R_Error(errorParm_t errorLevel, const char *msg, ...)
{
    char text[1024];
    va_list vargs;

    if (Sys_IsMainThread())
        R_SyncRenderThread();

    /* End scene if in progress */
    if (*(byte *)((char *)&dx + 11581)) {
        void *dev = *(void **)((char *)&dx + 8);
        void **vt = *(void ***)dev;
        ((int (*)(void *))vt[0xa8 / 4])(dev);
        *(byte *)((char *)&dx + 11581) = 0;
    }

    va_start(vargs, msg);
    vsnprintf(text, 0x3ff, msg, vargs);
    va_end(vargs);
    text[1023] = '\0';

    ((void (*)(int, const char *, ...))*(void **)((char *)&ri + 4))(errorLevel, str_00216058, text);
}

/* line 802 */
void R_GammaCorrect(byte *buffer, int bufSize)
{
    unsigned short gammaTable[256];
    float invGamma;
    int i;

    invGamma = 1.0f / *(float *)(*(int *)imp_r_gamma + 8);

    if (invGamma == 1.0f) {
        /* Identity gamma: table[i] = i | (i << 8) */
        for (i = 0; i < 256; i++)
            gammaTable[i] = (unsigned short)(i + (i << 8));
    } else {
        /* Compute gamma-corrected table */
        for (i = 0; i < 256; i++)
            gammaTable[i] = (unsigned short)(int)floorf((float)pow((double)(i / 255.0f), (double)invGamma) * 65535.0f + 0.5f);
    }

    /* Apply gamma table to buffer (16-bit table value / 257 → 8-bit) */
    for (i = 0; i < bufSize; i++)
        buffer[i] = (byte)(gammaTable[buffer[i]] / 257);
}

/* line 830 */
static void R_InitSystems(void)
{
    R_InitImages();
    Material_Init();
    R_InitFonts();
    *(int *)((char *)&rg + 4136) = 0;
    R_InitLightDefs();
    R_ClearFogs();
    R_InitDebug();
    *(char *)&rg = 1;
}

/* line 140 */
void R_FatalLockError(HRESULT hr)
{
    void (*printFunc)(int, const char *, ...) = *(void (**)(int, const char *, ...))&ri;
    printFunc(0, (const char *)str_00223a4c);
    printFunc(0, "********** error information:  %s\n", DXGetErrorDescription9A(hr));
    ((void (*)(void))*(void * *)((char *)&ri + 72))();
}

/* line 1920 */
/* line 1920 — Full renderer shutdown. Releases all subsystems, and if
 * destroyWindow is true, also releases the D3D device and IDirect3D9 objects. */
static void R_Shutdown(qboolean destroyWindow)
{
    byte *d = (byte *)&dx;

    *(byte *)&rg = 0; /* rg.registered = false */

    /* If device exists and in windowed mode, clear stream sources */
    if (*(void **)(d + 8)) {
        if (*(byte *)(d + 11580))
            RB_ClearAllStreamSources();
    }

    /* Shutdown all subsystems */
    R_ShutdownBackendData();
    R_ShutdownDebug();
    RB_SaveLightVisHistory();
    R_ShutdownLightDefs();
    R_ShutdownWorld();
    R_ShutdownFonts();
    R_ShutdownModels();
    Material_Shutdown();
    R_ShutdownImages();

    *(int *)((byte *)&rgp + 4252) = 0;
    R_UnlockSkinnedCache();
    R_FlushStaticModelCache();

    if (destroyWindow) {
        R_ReleaseForShutdownOrReset();

        /* Release swap chains in reverse order */
        while (*(int *)(d + 11592) > 0) {
            int idx = *(int *)(d + 11592) - 1;
            *(int *)(d + 11592) = idx;
            *(void **)(d + 11584 + idx * 16 + 12) = NULL;
        }

        /* Release D3D device (dx+8) */
        R_SafeRelease((void **)(d + 8));

        /* Release IDirect3D9 (dx+4) */
        R_SafeRelease((void **)(d + 4));

        R_UnregisterDvars();
    }

    R_UnregisterCmds();
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1920 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 8(%ebp), %ebx\n" /* destroyWindow */
        "movb $0, rg\n" /* line 1923 */
        "movl dx+8, %eax\n" /* line 1908 */
        "testl %eax, %eax\n"
        "je .Lfcb66e_000cb695\n"
        "cmpb $0, dx+11580\n" /* line 1912 */
        "je .Lfcb66e_000cb776\n"
        ".Lfcb66e_000cb695:\n"
        "calll R_ShutdownBackendData\n" /* line 1935 */
        "calll R_ShutdownDebug\n" /* line 1936 */
        "calll RB_SaveLightVisHistory\n" /* line 1937 */
        "calll R_ShutdownLightDefs\n" /* line 1938 */
        "calll R_ShutdownWorld\n" /* line 1940 */
        "calll R_ShutdownFonts\n" /* line 1941 */
        "calll R_ShutdownModels\n" /* line 1942 */
        "calll Material_Shutdown\n" /* line 1943 */
        "calll R_ShutdownImages\n" /* line 1944 */
        "movl $0, rgp+4252\n" /* line 1953 */
        "calll R_UnlockSkinnedCache\n" /* line 1957 */
        "calll R_FlushStaticModelCache\n" /* line 1961 */
        "testl %ebx, %ebx\n" /* line 1964 | destroyWindow */
        "jne .Lfcb66e_000cb6e4\n"
        "addl $0x14, %esp\n" /* line 1973 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp R_UnregisterCmds\n" /* line 1972 */
        ".Lfcb66e_000cb6e4:\n"
        "calll R_ReleaseForShutdownOrReset\n" /* line 1741 */
        "movl dx+11592, %eax\n" /* line 1743 */
        "testl %eax, %eax\n"
        "je .Lfcb66e_000cb713\n"
        "movl $dx+11584, %edx\n"
        ".Lfcb66e_000cb6f7:\n"
        "subl $1, %eax\n" /* line 1745 */
        "movl %eax, dx+11592\n"
        "shll $4, %eax\n" /* line 1754 */
        "movl $0, 0xc(%eax, %edx)\n"
        "movl dx+11592, %eax\n" /* line 1743 */
        "testl %eax, %eax\n"
        "jne .Lfcb66e_000cb6f7\n"
        ".Lfcb66e_000cb713:\n"
        "movl dx+8, %eax\n" /* line 1757 */
        "testl %eax, %eax\n"
        "je .Lfcb66e_000cb73c\n"
        ".Lfcb66e_000cb71c:\n"
        "movl dx+8, %eax\n" /* line 1758 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, dx+8\n"
        "movl alwaysfails, %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfcb66e_000cb71c\n"
        ".Lfcb66e_000cb73c:\n"
        "movl dx+4, %ebx\n" /* line 1760 */
        "testl %ebx, %ebx\n"
        "je .Lfcb66e_000cb767\n"
        ".Lfcb66e_000cb746:\n"
        "movl dx+4, %eax\n" /* line 1761 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, dx+4\n"
        "movl alwaysfails, %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcb66e_000cb746\n"
        ".Lfcb66e_000cb767:\n"
        "calll R_UnregisterDvars\n" /* line 1968 */
        "addl $0x14, %esp\n" /* line 1973 */
        "popl %ebx\n"
        "popl %ebp\n"
        "jmp R_UnregisterCmds\n" /* line 1972 */
        ".Lfcb66e_000cb776:\n"
        "calll RB_ClearAllStreamSources\n" /* line 1916 */
        "jmp .Lfcb66e_000cb695\n"
    );
}
#endif

/* line 789 */
void R_SetColorMappings(void)
{
    unsigned short gammaRamp[256];
    float invGamma;
    int i;

    if (!*(byte *)((char *)&vidConfig + 40))
        return;

    invGamma = 1.0f / *(float *)(*(int *)imp_r_gamma + 8);

    if (invGamma == 1.0f) {
        for (i = 0; i < 256; i++)
            gammaRamp[i] = (unsigned short)(i + (i << 8));
    } else {
        for (i = 0; i < 256; i++)
            gammaRamp[i] = (unsigned short)(int)floorf((float)pow((double)(i / 255.0f), (double)invGamma) * 65535.0f + 0.5f);
    }

    RB_SetGammaRamp(gammaRamp);
}

/* line 871 — R_CreateForInitOrReset
 * Creates D3D dynamic vertex/index buffers, allocates memory, initializes
 * particle cloud, sun flare array, and render state. Called during init and device reset. */
extern void R_InitRenderTargets(void);
extern void R_InitStaticModelCache(void);
extern void RB_SetInitialState(void);
extern const char *va(const char *fmt, ...);

/* Fatal D3D error handler: prints error info via ri function table, then calls ri.Error */
static void R_DxFatalError(const char *fmt, int size, HRESULT hr)
{
    typedef void (*ri_fn)(int, const char *, ...);
    typedef void (*ri_err_fn)(void);
    ri_fn Printf = *(ri_fn *)&ri;
    ri_err_fn Error = *(ri_err_fn *)((byte *)&ri + 72);
    const char *msg = va(fmt, size, DXGetErrorDescription9A(hr));
    Printf(0, "------- Initializing Renderer -------");
    Printf(0, "------- Renderer Initialization -------");
    Printf(0, "------- Server Initialization -------");
    Printf(0, "\n%s\n", msg);
    Error();
}

static Bool R_CreateForInitOrReset(void)
{
    typedef void (*ri_fn)(int, const char *, ...);
    typedef void *(*ri_alloc_fn)(int);
    ri_fn Printf = *(ri_fn *)&ri;
    ri_alloc_fn Hunk_Alloc = *(ri_alloc_fn *)((byte *)&ri + 32);
    byte *dxp = (byte *)(void *)&dx;
    int i;

    Printf(0, "R_InitRenderTargets");
    R_InitRenderTargets();
    Printf(0, "R_InitStaticModelCache");
    R_InitStaticModelCache();
    Printf(0, "Dynamic buffers");

    /* Choose VB size based on renderer type */
    int isDx7 = (*(int *)(*(int *)imp_r_rendererInUse + 8) == 2);
    int vbSize = isDx7 ? 0x120000 : 0x200000;

    /* Create primary dynamic vertex buffer */
    *(int *)(dxp + 11688) = 0;
    *(int *)(dxp + 11692) = vbSize;
    void *d3dDevice = *(void **)(dxp + 8);
    void **vtable = *(void ***)d3dDevice;
    typedef HRESULT (*CreateVB_fn)(void *, int, int, int, int, void **, void *);
    HRESULT hr = ((CreateVB_fn)vtable[26])(d3dDevice, vbSize, 0x208, 0, 0, (void **)(dxp + 11696), NULL);
    if (hr < 0)
        R_DxFatalError("Couldn't create a %i-byte dynamic vertex buffer: %s", vbSize, hr);

    /* Store VB wrapper pointer */
    *(int *)(dxp + 11700) = (int)(intptr_t)(dxp + 11688);

    /* Create 2 additional VBs for multi-buffering */
    int loopVbSize = isDx7 ? 0x480000 : 0x800000;
    int offset = 0x2d90;
    byte *vbOut = dxp + 11672;
    for (i = 0; i < 2; i++) {
        isDx7 = (*(int *)(*(int *)imp_r_rendererInUse + 8) == 2);
        loopVbSize = isDx7 ? 0x480000 : 0x800000;
        *(int *)(dxp + offset) = 0;
        *(int *)(dxp + offset + 4) = loopVbSize;
        d3dDevice = *(void **)(dxp + 8);
        vtable = *(void ***)d3dDevice;
        hr = ((CreateVB_fn)vtable[26])(d3dDevice, loopVbSize, 0x208, 0, 0, (void **)vbOut, NULL);
        if (hr < 0)
            R_DxFatalError("Couldn't create a %i-byte dynamic vertex buffer: %s", loopVbSize, hr);
        offset += 0xc;
        vbOut += 0xc;
    }

    /* Create dynamic index buffer (2MB) */
    *(int *)(dxp + 11648) = 0;
    *(int *)(dxp + 11652) = 0x200000;
    d3dDevice = *(void **)(dxp + 8);
    vtable = *(void ***)d3dDevice;
    typedef HRESULT (*CreateIB_fn)(void *, int, int, int, int, void **, void *);
    hr = ((CreateIB_fn)vtable[27])(d3dDevice, 0x200000, 0x208, 0x65, 0, (void **)(dxp + 11656), NULL);
    if (hr < 0)
        R_DxFatalError("Couldn't create a %i-byte dynamic index buffer: %s", 0x200000, hr);

    *(int *)(dxp + 11660) = (int)(intptr_t)(dxp + 11648);

    /* Allocate large memory block (10MB) */
    *(void **)(dxp + 11728) = Hunk_Alloc(0xa00000);

    Printf(0, "Particle cloud");
    R_CreateParticleCloudBuffer();
    Printf(0, "State");

    /* Clear flags */
    *(byte *)(dxp + 11624) = 0;
    *(int *)(dxp + 11612) = 0;

    /* Clear sun flare textures for all 4 views */
    byte *sunFlares = (byte *)imp_sunFlareArray;
    for (i = 0; i < 4; i++) {
        sunFlares[i * 0x30 + 0x2c] = 0;
        sunFlares[i * 0x30 + 0x2d] = 0;
    }

    Printf(0, "Initial state");
    RB_SetInitialState();
    return 1;
}

/* line 1985 */
__attribute__((naked))
static void R_BeginRegistration_impl(vidConfig_t *vidConfigOut)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1985 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xddc, %esp\n"
        "movl $str_00223bfc, 4(%esp)\n" /* line 1861 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll Swap_Init\n" /* line 1869 */
        "calll R_RegisterDvars\n" /* line 1788 */
        "calll R_RegisterCmds\n" /* line 1789 */
        "movl $0x31a0, 8(%esp)\n" /* line 1795 */
        "movl $0, 4(%esp)\n"
        "movl $rg, (%esp)\n"
        "calll memset\n"
        "movl $0x10f0, 8(%esp)\n" /* line 1798 */
        "movl $0, 4(%esp)\n"
        "movl $rgp, (%esp)\n"
        "calll memset\n"
        "calll RB_InitBackendGlobalStructs\n" /* line 1801 */
        "calll RB_DecideDefaultSamplerState\n" /* line 1803 */
        "calll R_InitBackendData\n" /* line 1874 */
        "calll R_InitDrawGroups\n" /* line 1876 */
        "movl dx+8, %esi\n" /* line 1568 */
        "testl %esi, %esi\n"
        "je .Lfcbc3e_000cbdf9\n"
        "calll R_InitSystems\n" /* line 1571 */
        ".Lfcbc3e_000cbccd:\n"
        "calll RB_RegisterBackendAssets\n" /* line 1886 */
        "xorl %ebx, %ebx\n"
        "movl $rg, %edi\n"
        ".Lfcbc3e_000cbcd9:\n"
        "cvtsi2ssl %ebx, %xmm0\n" /* line 1812 */
        "mulss lit4_002ed850, %xmm0\n" /* 0.3515625f */
        "cvtss2sd %xmm0, %xmm0\n"
        "mulsd lit8_00307c48, %xmm0\n" /* 0.017453292519943295 */
        "movsd %xmm0, (%esp)\n"
        "calll sin\n"
        "fstpl -0xdb8(%ebp)\n"
        "cvtsd2ss -0xdb8(%ebp), %xmm0\n"
        "movss %xmm0, 0x1510(%edi)\n"
        "addl $1, %ebx\n" /* line 1811 */
        "addl $4, %edi\n"
        "cmpl $0x400, %ebx\n"
        "jne .Lfcbc3e_000cbcd9\n"
        "movl $rg+9488, 4(%esp)\n" /* line 1818 */
        "movl $rg+11536, (%esp)\n"
        "calll FFT_Init\n"
        "movl $0, -0x170(%ebp)\n" /* line 1834 */
        "movl $0, -0x16c(%ebp)\n" /* line 1835 */
        "movl $0, -0x168(%ebp)\n" /* line 1836 */
        "movl $0, 0x10(%esp)\n" /* line 1838 */
        "movl $rg+12564, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $1, 4(%esp)\n"
        "leal -0x170(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *ri+476\n"
        "movl $rg+12564, rg+12560\n" /* line 1839 */
        "calll RB_CalcSunSpriteSamples\n" /* line 1896 */
        "movl %eax, dx+11308\n"
        "movl vidConfig, %eax\n" /* line 2007 */
        "movl 8(%ebp), %edx\n" /* vidConfigOut */
        "movl %eax, (%edx)\n"
        "movl vidConfig+4, %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl vidConfig+8, %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl vidConfig+12, %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl vidConfig+16, %eax\n"
        "movl %eax, 0x10(%edx)\n"
        "movl vidConfig+20, %eax\n"
        "movl %eax, 0x14(%edx)\n"
        "movl vidConfig+24, %eax\n"
        "movl %eax, 0x18(%edx)\n"
        "movl vidConfig+28, %eax\n"
        "movl %eax, 0x1c(%edx)\n"
        "movl vidConfig+32, %eax\n"
        "movl %eax, 0x20(%edx)\n"
        "movl vidConfig+36, %eax\n"
        "movl %eax, 0x24(%edx)\n"
        "movl vidConfig+40, %eax\n"
        "movl %eax, 0x28(%edx)\n"
        "addl $0xddc, %esp\n" /* line 2008 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfcbc3e_000cbdf9:\n"
        "movl dx+4, %ebx\n" /* line 1228 */
        "testl %ebx, %ebx\n"
        "je .Lfcbc3e_000ccd37\n"
        ".Lfcbc3e_000cbe07:\n"
        "movl $0, dx+12\n" /* line 1245 */
        "xorl %edi, %edi\n"
        "jmp .Lfcbc3e_000cbe2d\n"
        ".Lfcbc3e_000cbe15:\n"
        "movl $0x64, (%esp)\n" /* line 411 */
        "calll WinSleep\n"
        "addl $1, %edi\n" /* line 412 */
        "cmpl $0x14, %edi\n" /* line 406 */
        "je .Lfcbc3e_000ccafb\n"
        ".Lfcbc3e_000cbe2d:\n"
        "movl dx+4, %eax\n" /* line 408 */
        "movl (%eax), %edx\n"
        "leal -0x170(%ebp), %ecx\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x38(%edx)\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 409 */
        "js .Lfcbc3e_000cbe15\n"
        ".Lfcbc3e_000cbe5a:\n"
        "movl -0xa4(%ebp), %eax\n" /* line 443 */
        "movzbl %al, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movzbl %ah, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00223c74, 4(%esp)\n" /* "Pixel shader version is %i.%i
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl -0xac(%ebp), %eax\n" /* line 444 */
        "movzbl %al, %edx\n"
        "movl %edx, 0xc(%esp)\n"
        "movzbl %ah, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00223c94, 4(%esp)\n" /* "Vertex shader version is %i.%i
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "leal -0x170(%ebp), %ebx\n" /* line 446 */
        "movl %ebx, (%esp)\n"
        "calll R_CheckDxCaps\n"
        "movl %eax, %edx\n"
        "movl imp_r_rendererPreference, %eax\n" /* line 464 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edi\n"
        "testl %edi, %edi\n"
        "jne .Lnone_fix_skip\n"
        "movl $1, %edi\n" /* treat "none" as "dx9" preference */
        ".Lnone_fix_skip:\n"
        "movl %edi, %ecx\n" /* line 466 */
        "sarl %cl, %edx\n"
        "andb $1, %dl\n"
        "jne .Lfcbc3e_000ccb82\n"
        "movl $str_00223cb4, %eax\n" /* line 428 */
        "subl $1, %edi\n"
        "movl $str_00223cc0, %edx\n" /* "Direct3D 7" */
        "cmovnel %edx, %eax\n"
        "movl %eax, 0xc(%esp)\n" /* line 473 */
        "movl $str_00223cc0, 8(%esp)\n" /* "Direct3D 7" */
        "movl $str_00223d0c, 4(%esp)\n" /* "Using %s code path because the requested %s code path is una" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $2, %ecx\n"
        ".Lfcbc3e_000cbf11:\n"
        "movl %ecx, 4(%esp)\n" /* line 480 */
        "movl imp_r_rendererInUse, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *ri+152\n"
        "movl -0x114(%ebp), %eax\n" /* line 512 */
        "movl -0x118(%ebp), %edx\n"
        "cmpl %edx, %eax\n" /* line 154 */
        "cmovnsl %edx, %eax\n"
        "movl %eax, vidConfig+24\n" /* line 512 */
        "movl -0xd8(%ebp), %eax\n" /* line 513 */
        "movl %eax, vidConfig+28\n"
        "movl -0xdc(%ebp), %eax\n" /* line 514 */
        "movl %eax, vidConfig+32\n"
        "movl -0xd0(%ebp), %eax\n" /* line 515 */
        "movl %eax, vidConfig+36\n"
        "movl -0x164(%ebp), %eax\n" /* line 516 */
        "shrl $0x11, %eax\n"
        "andl $1, %eax\n"
        "movb %al, vidConfig+40\n"
        "movl -0xcc(%ebp), %eax\n" /* line 520 */
        "movl %eax, %ebx\n" /* line 154 */
        "subl $6, %ebx\n"
        "movl $6, %edx\n"
        "cmovnsl %edx, %eax\n"
        "movl %eax, dx+11636\n" /* line 520 */
        "movl -0x104(%ebp), %eax\n" /* line 521 */
        "movl %eax, dx+11632\n"
        "movl -0xe8(%ebp), %edx\n" /* line 522 */
        "movl %edx, %eax\n"
        "shrl $8, %eax\n"
        "andl $1, %eax\n"
        "movb %al, dx+11640\n"
        "andl $0xc0, %edx\n" /* line 523 */
        "cmpl $0xc0, %edx\n"
        "sete dx+11641\n"
        "movl -0x14c(%ebp), %eax\n" /* line 524 */
        "shrl $0x19, %eax\n"
        "andl $1, %eax\n"
        "movb %al, dx+11642\n"
        "movzwl -0x132(%ebp), %eax\n" /* line 525 */
        "andl $1, %eax\n"
        "movb %al, dx+11643\n"
        "movl -0x150(%ebp), %eax\n" /* line 526 */
        "shrl $0xb, %eax\n"
        "movl %eax, %edx\n"
        "andl $1, %edx\n"
        "movb %dl, dx+11644\n"
        "shrl $6, %eax\n" /* line 527 */
        "andl $1, %eax\n"
        "movb %al, dx+11645\n"
        "movl imp_r_aaSamples, %eax\n" /* line 490 */
        "movl (%eax), %eax\n"
        "cmpl $1, 8(%eax)\n"
        "je .Lfcbc3e_000cc04c\n"
        "movl dx+4, %eax\n" /* line 494 */
        "movl (%eax), %edx\n"
        "movl $0x41415353, 0x18(%esp)\n"
        "movl $1, 0x14(%esp)\n"
        "movl $0, 0x10(%esp)\n"
        "movl $0x15, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x28(%edx)\n"
        "testl %eax, %eax\n"
        "je .Lfcbc3e_000ccb78\n"
        ".Lfcbc3e_000cc04c:\n"
        "xorl %eax, %eax\n"
        ".Lfcbc3e_000cc04e:\n"
        "movb %al, dx+11646\n" /* line 530 */
        "movl dx+12, %edi\n" /* line 1248 */
        "movl %edi, -0xda8(%ebp)\n"
        "movl dx+4, %eax\n" /* line 1040 */
        "movl (%eax), %edx\n"
        "movl $0x16, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%edx)\n"
        "movl %eax, %edi\n"
        "movl $0, dx+20\n" /* line 1041 */
        "testl %eax, %eax\n" /* line 1042 */
        "je .Lfcbc3e_000cc104\n"
        "xorl %esi, %esi\n"
        "xorl %ebx, %ebx\n"
        "jmp .Lfcbc3e_000cc09d\n"
        ".Lfcbc3e_000cc08f:\n"
        "movl dx+20, %eax\n"
        "movl %eax, %ebx\n"
        "cmpl $0xff, %eax\n"
        "ja .Lfcbc3e_000cc109\n"
        ".Lfcbc3e_000cc09d:\n"
        "movl dx+4, %edx\n" /* line 1044 */
        "movl (%edx), %ecx\n"
        "shll $4, %ebx\n"
        "leal dx+24(%ebx), %eax\n"
        "movl %eax, 0x10(%esp)\n"
        "movl %esi, 0xc(%esp)\n"
        "movl $0x16, 8(%esp)\n"
        "movl -0xda8(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x1c(%ecx)\n"
        "testl %eax, %eax\n" /* line 1045 */
        "js .Lfcbc3e_000cc0fd\n"
        "movl dx+20, %eax\n" /* line 1047 */
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "movl dx+32(%edx), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfcbc3e_000cc0f5\n"
        "movl $0x3c, dx+32(%edx)\n" /* line 1048 */
        "movl dx+20, %eax\n"
        ".Lfcbc3e_000cc0f5:\n"
        "addl $1, %eax\n" /* line 1049 */
        "movl %eax, dx+20\n"
        ".Lfcbc3e_000cc0fd:\n"
        "addl $1, %esi\n" /* line 1042 */
        "cmpl %esi, %edi\n"
        "jne .Lfcbc3e_000cc08f\n"
        ".Lfcbc3e_000cc104:\n"
        "movl dx+20, %eax\n"
        ".Lfcbc3e_000cc109:\n"
        "shll $4, %eax\n" /* line 1052 */
        "addl $dx+24, %eax\n"
        "movl %eax, -0xd98(%ebp)\n"
        "cmpl $dx+24, %eax\n" /* line 2604 */
        "je .Lfcbc3e_000cc254\n"
        "movl %eax, %ebx\n" /* line 2606 */
        "subl $dx+24, %ebx\n"
        "movl %ebx, %eax\n"
        "sarl $4, %eax\n"
        "cmpl $1, %eax\n" /* line 2253 */
        "je .Lfcbc3e_000ccc9e\n"
        "xorl %edx, %edx\n"
        ".Lfcbc3e_000cc13a:\n"
        "addl $1, %edx\n" /* line 2254 */
        "sarl $1, %eax\n" /* line 2253 */
        "cmpl $1, %eax\n"
        "jne .Lfcbc3e_000cc13a\n"
        "leal (%edx, %edx), %eax\n"
        ".Lfcbc3e_000cc147:\n"
        "movl $R_DisplayModeLess, 0xc(%esp)\n" /* line 2606 */
        "movl %eax, 8(%esp)\n"
        "movl -0xd98(%ebp), %edx\n"
        "movl %edx, 4(%esp)\n"
        "movl $dx+24, (%esp)\n"
        "calll ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_\n"
        "cmpl $0x10f, %ebx\n" /* line 2233 */
        "jle .Lfcbc3e_000ccca5\n"
        "movl $R_DisplayModeLess, 8(%esp)\n" /* line 2235 */
        "movl $dx+280, 4(%esp)\n"
        "movl $dx+24, (%esp)\n"
        "calll ZSt16__insertion_sortIP15_D3DDISPLAYMODEPFhRKS0_S3_EEvT_S6_T0_\n"
        "cmpl $dx+280, -0xd98(%ebp)\n" /* line 2200 */
        "je .Lfcbc3e_000cc254\n"
        "movl $dx+280, -0xd94(%ebp)\n"
        "movl $dx+292, %esi\n"
        ".Lfcbc3e_000cc1b0:\n"
        "movl -4(%esi), %edx\n" /* line 2201 */
        "movl -8(%esi), %ecx\n"
        "movl -0xc(%esi), %ebx\n"
        "movl (%esi), %eax\n"
        "movl %eax, -0x164(%ebp)\n"
        "movl %edx, -0x168(%ebp)\n"
        "movl %ecx, -0x16c(%ebp)\n"
        "movl %ebx, -0x170(%ebp)\n"
        "movl -0xd94(%ebp), %ebx\n"
        "subl $0x10, %ebx\n"
        "movl -0xd94(%ebp), %edi\n"
        "jmp .Lfcbc3e_000cc1ff\n"
        ".Lfcbc3e_000cc1e4:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%edi)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "movl %ebx, %edi\n" /* line 2112 */
        "subl $0x10, %ebx\n"
        ".Lfcbc3e_000cc1ff:\n"
        "movl %ebx, 4(%esp)\n" /* line 2108 */
        "leal -0x170(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll R_DisplayModeLess\n"
        "testb %al, %al\n"
        "jne .Lfcbc3e_000cc1e4\n"
        "movl -0x170(%ebp), %eax\n" /* line 2114 */
        "movl %eax, (%edi)\n"
        "movl -0x16c(%ebp), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl -0x168(%ebp), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl -0x164(%ebp), %eax\n"
        "movl %eax, 0xc(%edi)\n"
        "addl $0x10, -0xd94(%ebp)\n" /* line 2200 */
        "addl $0x10, %esi\n"
        "movl -0xd94(%ebp), %ebx\n"
        "cmpl %ebx, -0xd98(%ebp)\n"
        "jne .Lfcbc3e_000cc1b0\n"
        ".Lfcbc3e_000cc254:\n"
        "movl dx+20, %esi\n" /* line 1055 */
        "testl %esi, %esi\n"
        "jne .Lfcbc3e_000cc95c\n"
        "movl $0, -0xda4(%ebp)\n"
        "movl $0, -0xda0(%ebp)\n"
        ".Lfcbc3e_000cc276:\n"
        "movl $0x1e0, 8(%esp)\n" /* line 1063 */
        "movl $0x280, 4(%esp)\n"
        "movl $str_00223da0, (%esp)\n" /* "No valid resolutions of %i x %i or above found" */
        "calll va\n"
        "movl %eax, %ebx\n"
        "movl $str_002238dc, 4(%esp)\n" /* line 125 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223938, 4(%esp)\n" /* line 126 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223994, 4(%esp)\n" /* line 127 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl %ebx, 8(%esp)\n" /* line 128 */
        "movl $str_002239f0, 4(%esp)\n" /* "
%s
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll *ri+72\n" /* line 131 */
        ".Lfcbc3e_000cc2f2:\n"
        "movl -0xda4(%ebp), %eax\n" /* line 1066 */
        "testl %eax, %eax\n"
        "jg .Lfcbc3e_000ccbe8\n"
        "movl $dx+6176, -0xd9c(%ebp)\n"
        "xorl %esi, %esi\n"
        "movl $0, -0xda4(%ebp)\n"
        ".Lfcbc3e_000cc316:\n"
        "movl -0xda4(%ebp), %ecx\n" /* line 1073 */
        "movl $0, dx+4120(, %ecx, 4)\n"
        "movl $0x2021, 0xc(%esp)\n" /* line 1074 */
        "movl %esi, 8(%esp)\n"
        "movl $dx+4120, 4(%esp)\n"
        "movl $str_00223dd8, (%esp)\n" /* "r_mode" */
        "calll *ri+104\n"
        "movl imp_r_mode, %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0xda0(%ebp), %eax\n" /* line 1077 */
        "testl %eax, %eax\n"
        "jg .Lfcbc3e_000cccd3\n"
        "xorl %edi, %edi\n"
        "movl $0, -0xda0(%ebp)\n"
        ".Lfcbc3e_000cc36a:\n"
        "movl -0xda0(%ebp), %ebx\n" /* line 1084 */
        "movl $0, dx+5148(, %ebx, 4)\n"
        "movl $0x2021, 0xc(%esp)\n" /* line 1085 */
        "movl %edi, 8(%esp)\n"
        "movl $dx+5148, 4(%esp)\n"
        "movl $str_00223de8, (%esp)\n" /* "r_displayRefresh" */
        "calll *ri+104\n"
        "movl imp_r_displayRefresh, %edx\n"
        "movl %eax, (%edx)\n"
        ".Lfcbc3e_000cc3a4:\n"
        "movl imp_r_mode, %eax\n" /* line 1495 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *ri+240\n"
        "leal -0x28(%ebp), %edi\n" /* line 1496 */
        "movl %edi, 0xc(%esp)\n"
        "leal -0x2c(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl $str_00223dd0, 4(%esp)\n" /* "%ix%i" */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "movl imp_r_displayRefresh, %eax\n" /* line 1498 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *ri+240\n"
        "leal -0x1c(%ebp), %ecx\n" /* line 1499 */
        "movl %ecx, 8(%esp)\n"
        "movl $str_00223de0, 4(%esp)\n" /* "%i Hz" */
        "movl %eax, (%esp)\n"
        "calll sscanf\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 1500 */
        "movl %ebx, -0xd90(%ebp)\n"
        "movl -0x28(%ebp), %edi\n"
        "movl %edi, -0xd8c(%ebp)\n"
        "movl -0x2c(%ebp), %edi\n"
        "movl dx+20, %ebx\n" /* line 1451 */
        "subl $1, %ebx\n"
        "jns .Lfcbc3e_000cc6c0\n"
        "xorl %esi, %esi\n"
        ".Lfcbc3e_000cc41f:\n"
        "movl %ebx, %eax\n" /* line 1475 */
        "shll $4, %eax\n"
        "cmpl dx+24(%eax), %edi\n"
        "je .Lfcbc3e_000cc83b\n"
        ".Lfcbc3e_000cc430:\n"
        "shll $4, %esi\n" /* line 1478 */
        "movl dx+32(%esi), %esi\n"
        "movl %esi, -0xd90(%ebp)\n"
        "movl %esi, %ecx\n"
        ".Lfcbc3e_000cc441:\n"
        "movl %ecx, -0x3c(%ebp)\n" /* line 1500 */
        "movl imp_vid_xpos, %eax\n" /* line 1502 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl imp_vid_ypos, %eax\n" /* line 1503 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movb $1, -0x38(%ebp)\n" /* line 1505 */
        "movl $0, -0x40(%ebp)\n" /* line 1509 */
        "movl imp_r_aaSamples, %eax\n" /* line 1511 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "calll MacDisplay_GetMainWindow\n" /* line 1374 */
        "movl %eax, -0x40(%ebp)\n"
        "movl $str_00223dfc, 4(%esp)\n" /* line 1376 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl -0x40(%ebp), %ebx\n" /* line 1274 */
        "movl %ebx, -0xd88(%ebp)\n"
        "movl %ebx, %edx\n"
        "movl -0x20(%ebp), %eax\n" /* line 212 */
        "cmpl $1, %eax\n" /* line 213 */
        "jle .Lfcbc3e_000cc507\n"
        "movl %eax, %ebx\n"
        "leal -2(%eax), %eax\n"
        "negl %eax\n"
        "leal -1(%eax, %ebx), %esi\n"
        ".Lfcbc3e_000cc4b1:\n"
        "movl %ebx, dx+11300\n" /* line 215 */
        "movl dx+4, %edx\n" /* line 216 */
        "movl (%edx), %ecx\n"
        "leal -0x1c(%ebp), %edi\n"
        "movl %edi, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpb $0, -0x38(%ebp)\n"
        "sete %al\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x15, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 217 */
        "jns .Lfcbc3e_000cc8c3\n"
        "subl $1, %ebx\n" /* line 222 */
        "cmpl %ebx, %esi\n" /* line 213 */
        "jne .Lfcbc3e_000cc4b1\n"
        "movl -0x40(%ebp), %edx\n"
        ".Lfcbc3e_000cc507:\n"
        "movl $0, dx+11300\n" /* line 225 */
        "movl $0, dx+11304\n" /* line 226 */
        ".Lfcbc3e_000cc51b:\n"
        "cld\n" /* line 246 */
        "movl $0xe, %ecx\n"
        "xorl %eax, %eax\n"
        "leal -0x170(%ebp), %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 247 */
        "movl %eax, -0x170(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 248 */
        "movl %eax, -0x16c(%ebp)\n"
        "movl $0x15, -0x168(%ebp)\n" /* line 249 */
        "movl $1, -0x164(%ebp)\n" /* line 250 */
        "movl dx+11300, %eax\n" /* line 251 */
        "movl %eax, -0x160(%ebp)\n"
        "movl dx+11304, %eax\n" /* line 252 */
        "movl %eax, -0x15c(%ebp)\n"
        "movl $1, -0x158(%ebp)\n" /* line 253 */
        "movl $0, -0x14c(%ebp)\n" /* line 254 */
        "movl $0x4b, -0x148(%ebp)\n" /* line 255 */
        "movl imp_r_swapInterval, %eax\n" /* line 276 */
        "movl (%eax), %eax\n"
        "cmpb $1, 8(%eax)\n"
        "sbbl %eax, %eax\n"
        "andl $0x7fffffff, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x13c(%ebp)\n"
        "movl %edx, -0x154(%ebp)\n" /* line 278 */
        "movl $0, -0x144(%ebp)\n" /* line 279 */
        "cmpb $0, -0x38(%ebp)\n" /* line 280 */
        "je .Lfcbc3e_000cc714\n"
        "movl $0, -0x150(%ebp)\n" /* line 282 */
        "movl -0x3c(%ebp), %eax\n" /* line 283 */
        "movl %eax, -0x140(%ebp)\n"
        "leal -0x170(%ebp), %ecx\n" /* line 1296 */
        "movl $0x40, %edx\n"
        "movl -0xd88(%ebp), %eax\n"
        "calll R_CreateDevice\n"
        "testl %eax, %eax\n" /* line 1304 */
        "js .Lfcbc3e_000cc746\n"
        ".Lfcbc3e_000cc5eb:\n"
        "movb $0, dx+11580\n" /* line 1313 */
        "movl imp_r_multiGpu, %eax\n" /* line 1258 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "je .Lfcbc3e_000cc82c\n"
        "xorl %eax, %eax\n"
        ".Lfcbc3e_000cc605:\n"
        "movl %eax, dx+11296\n"
        "movl -0x2c(%ebp), %eax\n" /* line 347 */
        "movl %eax, vidConfig\n"
        "movl -0x28(%ebp), %eax\n" /* line 348 */
        "movl %eax, vidConfig+4\n"
        "movl -0x3c(%ebp), %eax\n" /* line 351 */
        "movl %eax, vidConfig+8\n"
        "movzbl -0x38(%ebp), %edx\n" /* line 352 */
        "movzbl %dl, %eax\n"
        "movl %eax, vidConfig+12\n"
        "movl imp_r_aspectRatio, %eax\n" /* line 355 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "cmpl $1, %eax\n"
        "je .Lfcbc3e_000cc8d6\n"
        "jle .Lfcbc3e_000cc8e5\n"
        "cmpl $2, %eax\n"
        "je .Lfcbc3e_000cc94d\n"
        "cmpl $3, %eax\n"
        "je .Lfcbc3e_000cc93e\n"
        ".Lfcbc3e_000cc659:\n"
        "cvtsi2ssl vidConfig+4, %xmm0\n" /* line 393 */
        "mulss vidConfig+16, %xmm0\n"
        "cvtsi2ssl vidConfig, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "movss %xmm0, vidConfig+20\n"
        "calll RB_InitSceneViewport\n" /* line 1321 */
        "leal -0x40(%ebp), %edx\n" /* line 1323 */
        "leal -0x170(%ebp), %eax\n"
        "calll R_CreateForInitOrReset\n"
        "testb %al, %al\n"
        "jne .Lfcbc3e_000cc860\n"
        "movl imp_r_aaSamples, %eax\n" /* line 1541 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jle .Lfcbc3e_000cc77c\n"
        ".Lfcbc3e_000cc6ab:\n"
        "subl $1, %eax\n" /* line 1555 */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *ri+152\n"
        "jmp .Lfcbc3e_000cc3a4\n"
        ".Lfcbc3e_000cc6c0:\n"
        "xorl %esi, %esi\n" /* line 1451 */
        "jmp .Lfcbc3e_000cc6cf\n"
        ".Lfcbc3e_000cc6c4:\n"
        "leal -1(%ecx), %ebx\n" /* line 1470 */
        ".Lfcbc3e_000cc6c7:\n"
        "cmpl %esi, %ebx\n" /* line 1451 */
        "jl .Lfcbc3e_000cc41f\n"
        ".Lfcbc3e_000cc6cf:\n"
        "leal (%esi, %ebx), %edx\n" /* line 1453 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ecx\n"
        "sarl $1, %ecx\n"
        "movl %ecx, %edx\n" /* line 1455 */
        "shll $4, %edx\n"
        "movl dx+24(%edx), %eax\n"
        "subl %edi, %eax\n" /* line 1456 */
        "jne .Lfcbc3e_000cc70b\n"
        "movl dx+28(%edx), %eax\n" /* line 1458 */
        "subl -0xd8c(%ebp), %eax\n" /* line 1459 */
        "jne .Lfcbc3e_000cc70b\n"
        "movl dx+32(%edx), %eax\n" /* line 1461 */
        "subl -0xd90(%ebp), %eax\n" /* line 1462 */
        "je .Lfcbc3e_000cccc8\n"
        ".Lfcbc3e_000cc70b:\n"
        "testl %eax, %eax\n" /* line 1467 */
        "jns .Lfcbc3e_000cc6c4\n"
        "leal 1(%ecx), %esi\n" /* line 1468 */
        "jmp .Lfcbc3e_000cc6c7\n"
        ".Lfcbc3e_000cc714:\n"
        "movl $1, -0x150(%ebp)\n" /* line 287 */
        "movl $0, -0x140(%ebp)\n" /* line 288 */
        "leal -0x170(%ebp), %ecx\n" /* line 1296 */
        "movl $0x40, %edx\n"
        "movl -0xd88(%ebp), %eax\n"
        "calll R_CreateDevice\n"
        "testl %eax, %eax\n" /* line 1304 */
        "jns .Lfcbc3e_000cc5eb\n"
        ".Lfcbc3e_000cc746:\n"
        "movl ri, %ebx\n" /* line 1306 */
        "movl %eax, (%esp)\n" /* line 177 */
        "calll DXGetErrorDescription9A\n"
        "movl %eax, 8(%esp)\n" /* line 1306 */
        "movl $str_00223e20, 4(%esp)\n" /* "Couldn't create a Direct3D device: %s
" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl imp_r_aaSamples, %eax\n" /* line 1541 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "cmpl $1, %eax\n"
        "jg .Lfcbc3e_000cc6ab\n"
        ".Lfcbc3e_000cc77c:\n"
        "movl imp_r_displayRefresh, %eax\n" /* line 1547 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfcbc3e_000cc797\n"
        "cmpl $0x3c, vidConfig+8\n"
        "jg .Lfcbc3e_000cc6ab\n"
        ".Lfcbc3e_000cc797:\n"
        "movl imp_r_mode, %eax\n" /* line 1553 */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "testl %eax, %eax\n"
        "jle .Lfcbc3e_000cc7c5\n"
        "cmpl $0x280, vidConfig\n"
        "jg .Lfcbc3e_000cc6ab\n"
        "cmpl $0x1e0, vidConfig+4\n"
        "jg .Lfcbc3e_000cc6ab\n"
        ".Lfcbc3e_000cc7c5:\n"
        "movl $str_002238dc, 4(%esp)\n" /* line 125 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223938, 4(%esp)\n" /* line 126 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223994, 4(%esp)\n" /* line 127 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223e48, 8(%esp)\n" /* line 128 */
        "movl $str_002239f0, 4(%esp)\n" /* "
%s
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll *ri+72\n" /* line 131 */
        "jmp .Lfcbc3e_000cc3a4\n"
        ".Lfcbc3e_000cc82c:\n"
        "movl imp_r_gpuSync, %eax\n" /* line 1258 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "jmp .Lfcbc3e_000cc605\n"
        ".Lfcbc3e_000cc83b:\n"
        "movl -0xd8c(%ebp), %edx\n" /* line 1475 */
        "cmpl %edx, dx+28(%eax)\n"
        "jne .Lfcbc3e_000cc430\n"
        "movl dx+32(%eax), %eax\n" /* line 1476 */
        "movl %eax, -0xd90(%ebp)\n"
        "movl %eax, %ecx\n"
        "jmp .Lfcbc3e_000cc441\n"
        ".Lfcbc3e_000cc860:\n"
        "movl imp_r_gamma, %eax\n" /* line 755 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *ri+140\n"
        "calll R_InitSystems\n" /* line 1349 */
        "movl dx+11592, %eax\n" /* line 863 */
        "movl $dx+11584, %ecx\n"
        "shll $4, %eax\n"
        "movl -0x40(%ebp), %edx\n"
        "movl %edx, 0xc(%eax, %ecx)\n"
        "movl dx+11592, %eax\n" /* line 864 */
        "shll $4, %eax\n"
        "movl -0x2c(%ebp), %edx\n"
        "movl %edx, 0x14(%eax, %ecx)\n"
        "movl dx+11592, %eax\n" /* line 865 */
        "shll $4, %eax\n"
        "movl -0x28(%ebp), %edx\n"
        "movl %edx, 0x18(%eax, %ecx)\n"
        "addl $1, dx+11592\n" /* line 866 */
        "calll *ri+80\n" /* line 1433 */
        "movl $0, dx+11588\n" /* line 1434 */
        "jmp .Lfcbc3e_000cbccd\n"
        ".Lfcbc3e_000cc8c3:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 219 */
        "subl $1, %eax\n"
        "movl %eax, dx+11304\n"
        "movl -0x40(%ebp), %edx\n"
        "jmp .Lfcbc3e_000cc51b\n"
        ".Lfcbc3e_000cc8d6:\n"
        "movl $0x3faaaaab, vidConfig+16\n" /* line 368 */
        "jmp .Lfcbc3e_000cc659\n"
        ".Lfcbc3e_000cc8e5:\n"
        "testl %eax, %eax\n" /* line 355 */
        "jne .Lfcbc3e_000cc659\n"
        "testb %dl, %dl\n" /* line 305 */
        "jne .Lfcbc3e_000ccd7f\n"
        ".Lfcbc3e_000cc8f5:\n"
        "movl vidConfig, %ebx\n" /* line 324 */
        "movl vidConfig+4, %eax\n" /* line 325 */
        ".Lfcbc3e_000cc900:\n"
        "cvtsi2ssl %eax, %xmm0\n" /* line 428 */
        "mulss lit4_002ed6a8, %xmm0\n" /* 16.0f */
        "cvtsi2ssl %ebx, %xmm1\n"
        "divss %xmm1, %xmm0\n"
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xdac(%ebp)\n"
        "cvttss2si -0xdac(%ebp), %eax\n"
        "cmpl $0xa, %eax\n" /* line 360 */
        "je .Lfcbc3e_000cc94d\n"
        "cmpl $9, %eax\n" /* line 362 */
        "jg .Lfcbc3e_000cc8d6\n"
        ".Lfcbc3e_000cc93e:\n"
        "movl $0x3fe38e39, vidConfig+16\n" /* line 371 */
        "jmp .Lfcbc3e_000cc659\n"
        ".Lfcbc3e_000cc94d:\n"
        "movl $0x3fcccccd, vidConfig+16\n" /* line 374 */
        "jmp .Lfcbc3e_000cc659\n"
        ".Lfcbc3e_000cc95c:\n"
        "movl $0, -0xd7c(%ebp)\n" /* line 1055 */
        "movl $0, -0xda4(%ebp)\n"
        "movl $0, -0xda0(%ebp)\n"
        "movl $dx, -0xd80(%ebp)\n"
        "leal -0xd70(%ebp), %eax\n"
        "movl %eax, -0xdc0(%ebp)\n"
        ".Lfcbc3e_000cc990:\n"
        "movl -0xd80(%ebp), %edx\n" /* line 1057 */
        "movl 0x1c(%edx), %ecx\n"
        "movl 0x18(%edx), %eax\n"
        "movl -0xda4(%ebp), %ebx\n" /* line 1009 */
        "testl %ebx, %ebx\n"
        "jle .Lfcbc3e_000cc9be\n"
        "movl -0xdc0(%ebp), %edx\n" /* line 1011 */
        "subl $8, %edx\n"
        "movl -0xdc0(%ebp), %ebx\n"
        "cmpl -8(%ebx), %eax\n"
        "je .Lfcbc3e_000cca89\n"
        ".Lfcbc3e_000cc9be:\n"
        "cmpl $0x27f, %eax\n" /* line 1015 */
        "jle .Lfcbc3e_000cc9e8\n"
        "cmpl $0x1df, %ecx\n"
        "jle .Lfcbc3e_000cc9e8\n"
        "movl -0xdc0(%ebp), %edi\n" /* line 1018 */
        "movl %eax, (%edi)\n"
        "movl %ecx, 4(%edi)\n" /* line 1019 */
        "addl $1, -0xda4(%ebp)\n" /* line 1021 */
        "addl $8, %edi\n"
        "movl %edi, -0xdc0(%ebp)\n"
        ".Lfcbc3e_000cc9e8:\n"
        "movl -0xd80(%ebp), %eax\n" /* line 1058 */
        "movl 0x20(%eax), %esi\n"
        "movl -0xda0(%ebp), %edx\n" /* line 988 */
        "testl %edx, %edx\n"
        "jle .Lfcbc3e_000cca50\n"
        "cmpl %esi, -0x570(%ebp)\n" /* line 990 */
        "je .Lfcbc3e_000cca1d\n"
        "xorl %eax, %eax\n"
        ".Lfcbc3e_000cca05:\n"
        "addl $1, %eax\n" /* line 988 */
        "cmpl %eax, -0xda0(%ebp)\n"
        "je .Lfcbc3e_000cca97\n"
        "cmpl %esi, -0x570(%ebp, %eax, 4)\n" /* line 990 */
        "jne .Lfcbc3e_000cca05\n"
        ".Lfcbc3e_000cca1d:\n"
        "addl $1, -0xd7c(%ebp)\n" /* line 1055 */
        "addl $0x10, -0xd80(%ebp)\n"
        "movl -0xd7c(%ebp), %eax\n"
        "cmpl %eax, dx+20\n"
        "ja .Lfcbc3e_000cc990\n"
        ".Lfcbc3e_000cca3d:\n"
        "movl -0xda4(%ebp), %eax\n" /* line 1062 */
        "testl %eax, %eax\n"
        "jne .Lfcbc3e_000cc2f2\n"
        "jmp .Lfcbc3e_000cc276\n"
        ".Lfcbc3e_000cca50:\n"
        "movl -0xda0(%ebp), %eax\n" /* line 988 */
        "shll $2, %eax\n"
        ".Lfcbc3e_000cca59:\n"
        "movl %esi, -0x570(%ebp, %eax)\n" /* line 1000 */
        "addl $1, -0xda0(%ebp)\n" /* line 1001 */
        "addl $1, -0xd7c(%ebp)\n" /* line 1055 */
        "addl $0x10, -0xd80(%ebp)\n"
        "movl -0xd7c(%ebp), %eax\n"
        "cmpl %eax, dx+20\n"
        "ja .Lfcbc3e_000cc990\n"
        "jmp .Lfcbc3e_000cca3d\n"
        ".Lfcbc3e_000cca89:\n"
        "cmpl 4(%edx), %ecx\n" /* line 1011 */
        "jne .Lfcbc3e_000cc9be\n"
        "jmp .Lfcbc3e_000cc9e8\n"
        ".Lfcbc3e_000cca97:\n"
        "movl -0xda0(%ebp), %eax\n" /* line 995 */
        "shll $2, %eax\n"
        "movl -0x574(%ebp, %eax), %ecx\n"
        "cmpl %ecx, %esi\n"
        "jge .Lfcbc3e_000cca59\n"
        "leal -4(%eax), %edx\n"
        "movl -0xda0(%ebp), %ebx\n"
        "movl %ebx, %edi\n"
        "subl $1, %edi\n"
        "movl %edi, -0xdbc(%ebp)\n"
        "jmp .Lfcbc3e_000ccac5\n"
        ".Lfcbc3e_000ccac1:\n"
        "movl %edx, %eax\n" /* line 988 */
        "movl %edi, %edx\n"
        ".Lfcbc3e_000ccac5:\n"
        "movl %ecx, -0x570(%ebp, %eax)\n" /* line 997 */
        "subl $1, %ebx\n" /* line 998 */
        "movl -0xda0(%ebp), %eax\n" /* line 995 */
        "subl -0xdbc(%ebp), %eax\n"
        "subl $1, %eax\n"
        "cmpl %ebx, %eax\n"
        "je .Lfcbc3e_000ccdae\n"
        "movl -0x574(%ebp, %edx), %ecx\n"
        "leal -4(%edx), %edi\n"
        "cmpl %ecx, %esi\n"
        "jl .Lfcbc3e_000ccac1\n"
        "movl %edx, %eax\n"
        "jmp .Lfcbc3e_000cca59\n"
        ".Lfcbc3e_000ccafb:\n"
        "movl %ebx, (%esp)\n" /* line 177 */
        "calll DXGetErrorDescription9A\n"
        "movl %eax, 4(%esp)\n" /* line 415 */
        "movl $str_00223c58, (%esp)\n" /* "GetDeviceCaps failed: %s" */
        "calll va\n"
        "movl %eax, %ebx\n"
        "movl $str_002238dc, 4(%esp)\n" /* line 125 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223938, 4(%esp)\n" /* line 126 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223994, 4(%esp)\n" /* line 127 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl %ebx, 8(%esp)\n" /* line 128 */
        "movl $str_002239f0, 4(%esp)\n" /* "
%s
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll *ri+72\n" /* line 131 */
        "jmp .Lfcbc3e_000cbe5a\n"
        ".Lfcbc3e_000ccb78:\n"
        "movl $1, %eax\n" /* line 494 */
        "jmp .Lfcbc3e_000cc04e\n"
        ".Lfcbc3e_000ccb82:\n"
        "movl ri, %ebx\n" /* line 469 */
        "movl %eax, (%esp)\n"
        "calll *ri+240\n"
        "movl $str_00223cb4, %ecx\n" /* line 428 */
        "cmpl $1, %edi\n"
        "movl $str_00223cc0, %edx\n" /* "Direct3D 7" */
        "cmovnel %edx, %ecx\n"
        "movl %eax, 0xc(%esp)\n" /* line 469 */
        "movl %ecx, 8(%esp)\n"
        "movl $str_00223ccc, 4(%esp)\n" /* "Using %s code path because r_rendererPreference is set to %s" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "movl %edi, %ecx\n"
        "jmp .Lfcbc3e_000cbf11\n"
        ".Lfcbc3e_000ccbc1:\n"
        "movl $str_00223cc0, 8(%esp)\n" /* line 478 */
        "movl $str_00223d54, 4(%esp)\n" /* "Using %s code path because it is the best available path on " */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $2, %ecx\n"
        "jmp .Lfcbc3e_000cbf11\n"
        ".Lfcbc3e_000ccbe8:\n"
        "xorl %edi, %edi\n" /* line 1066 */
        "movl $dx+6176, -0xd9c(%ebp)\n"
        "xorl %esi, %esi\n"
        "movl $dx, -0xd84(%ebp)\n"
        "xorl %ebx, %ebx\n"
        ".Lfcbc3e_000ccc02:\n"
        "movl -0xd9c(%ebp), %ecx\n" /* line 1068 */
        "movl -0xd84(%ebp), %edx\n"
        "movl %ecx, 0x1018(%edx)\n"
        "movl -0xd6c(%ebx, %ebp), %eax\n" /* line 1069 */
        "movl %eax, 0xc(%esp)\n"
        "movl -0xd70(%ebx, %ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00223dd0, 4(%esp)\n" /* "%ix%i" */
        "movl %ecx, (%esp)\n"
        "calll sprintf\n"
        "movl -0xd9c(%ebp), %edx\n"
        "leal 1(%edx, %eax), %eax\n"
        "movl %eax, -0xd9c(%ebp)\n"
        "cmpl $0x27f, -0xd70(%ebp, %esi, 8)\n" /* line 1070 */
        "jle .Lfcbc3e_000ccc7e\n"
        "cmpl $0x1df, -0xd6c(%ebp, %esi, 8)\n"
        "jle .Lfcbc3e_000ccc7e\n"
        "addl $1, %edi\n" /* line 1066 */
        "addl $8, %ebx\n"
        "addl $4, -0xd84(%ebp)\n"
        "cmpl -0xda4(%ebp), %edi\n"
        "jne .Lfcbc3e_000ccc02\n"
        "jmp .Lfcbc3e_000cc316\n"
        ".Lfcbc3e_000ccc7e:\n"
        "movl %edi, %esi\n" /* line 1070 */
        "addl $1, %edi\n" /* line 1066 */
        "addl $8, %ebx\n"
        "addl $4, -0xd84(%ebp)\n"
        "cmpl -0xda4(%ebp), %edi\n"
        "jne .Lfcbc3e_000ccc02\n"
        "jmp .Lfcbc3e_000cc316\n"
        ".Lfcbc3e_000ccc9e:\n"
        "xorb %al, %al\n" /* line 2253 */
        "jmp .Lfcbc3e_000cc147\n"
        ".Lfcbc3e_000ccca5:\n"
        "movl $R_DisplayModeLess, 8(%esp)\n" /* line 2240 */
        "movl -0xd98(%ebp), %edi\n"
        "movl %edi, 4(%esp)\n"
        "movl $dx+24, (%esp)\n"
        "calll ZSt16__insertion_sortIP15_D3DDISPLAYMODEPFhRKS0_S3_EEvT_S6_T0_\n"
        "jmp .Lfcbc3e_000cc254\n"
        ".Lfcbc3e_000cccc8:\n"
        "movl -0xd90(%ebp), %ecx\n"
        "jmp .Lfcbc3e_000cc441\n"
        ".Lfcbc3e_000cccd3:\n"
        "xorl %edi, %edi\n" /* line 1077 */
        "xorl %ebx, %ebx\n"
        "movl $dx, %esi\n"
        "movl -0xd9c(%ebp), %eax\n"
        ".Lfcbc3e_000ccce2:\n"
        "movl %eax, 0x141c(%esi)\n" /* line 1079 */
        "movl -0x570(%ebp, %ebx, 4), %eax\n" /* line 1080 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00223de0, 4(%esp)\n" /* "%i Hz" */
        "movl -0xd9c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll sprintf\n"
        "movl -0xd9c(%ebp), %ecx\n"
        "leal 1(%ecx, %eax), %eax\n"
        "movl %eax, -0xd9c(%ebp)\n"
        "cmpl $0x3b, -0x570(%ebp, %edi, 4)\n" /* line 1081 */
        "cmovlel %ebx, %edi\n"
        "addl $1, %ebx\n" /* line 1077 */
        "addl $4, %esi\n"
        "cmpl -0xda0(%ebp), %ebx\n"
        "jne .Lfcbc3e_000ccce2\n"
        "jmp .Lfcbc3e_000cc36a\n"
        ".Lfcbc3e_000ccd37:\n"
        "movl $str_00223c10, 4(%esp)\n" /* line 1230 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $0x20, (%esp)\n" /* line 1231 */
        "calll Direct3DCreate9\n"
        "movl %eax, dx+4\n"
        "testl %eax, %eax\n" /* line 1232 */
        "jne .Lfcbc3e_000cbe07\n"
        "movl $str_00223c34, 4(%esp)\n" /* line 1234 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "jmp .Lfcbc3e_000cc3a4\n"
        ".Lfcbc3e_000ccd7f:\n"
        "movl $0, (%esp)\n" /* line 318 */
        "calll GetSystemMetrics\n"
        "movl %eax, %ebx\n"
        "movl $1, (%esp)\n" /* line 319 */
        "calll GetSystemMetrics\n"
        "testl %ebx, %ebx\n" /* line 320 */
        "jle .Lfcbc3e_000cc8f5\n"
        "testl %eax, %eax\n"
        "jg .Lfcbc3e_000cc900\n"
        "jmp .Lfcbc3e_000cc8f5\n"
        ".Lfcbc3e_000ccdae:\n"
        "leal (, %ebx, 4), %eax\n" /* line 995 */
        "jmp .Lfcbc3e_000cca59\n"
    );
}

void R_BeginRegistration(vidConfig_t *vidConfigOut)
{
    R_BeginRegistration_impl(vidConfigOut);
    /* Set rg.registered = 1 so R_EndFrame doesn't early-return */
    *(char *)&rg = 1;
}

/* line 2408 — R_RecoverLostDevice
 * Attempts to recover a lost D3D device. Tests cooperative level, releases resources,
 * determines anti-aliasing support, resets device, recreates resources, reloads assets. */
extern void R_ReleaseAllModels(void);
extern void R_ReleaseLostImages(void);
extern void Material_ReleaseAll(void);
extern void R_ReleaseWorld(void);
extern void R_ReleaseForShutdownOrReset(void);
extern void R_ReloadWorld(void);
extern void Material_ReloadAll(void);
extern void R_ReloadLostImages(void);
extern void R_OptimizeAllModels(void);
extern int RB_CalcSunSpriteSamples(void);
extern r_global_permanent_t rgp;

Bool R_RecoverLostDevice(void)
{
    byte *dxp = (byte *)(void *)&dx;
    typedef void (*ri_fn)(int, const char *, ...);
    typedef void (*ri_err_fn)(void);
    ri_fn Printf = *(ri_fn *)&ri;
    ri_err_fn Error = *(ri_err_fn *)((byte *)&ri + 72);

    /* Test cooperative level */
    void *d3dDevice = *(void **)(dxp + 8);
    void **vtable = *(void ***)d3dDevice;
    typedef HRESULT (*TestCoopLevel_fn)(void *);
    HRESULT hr = ((TestCoopLevel_fn)vtable[3])(d3dDevice);

    if (hr == (HRESULT)0x88760868) /* D3DERR_DEVICELOST */
        return 0;

    Printf(0, "Recovering lost device");

    /* Release all resources */
    R_ReleaseAllModels();
    R_ReleaseLostImages();
    Material_ReleaseAll();

    if (*(int *)((byte *)&rgp + 4252)) /* rgp.world != NULL */
        R_ReleaseWorld();

    /* Save current display parameters */
    int displayMode = *(int *)(dxp + 11596);
    int backBufWidth = *(int *)(dxp + 11604);
    int backBufHeight = *(int *)(dxp + 11608);
    int refreshRate = *(int *)((byte *)&vidConfig + 8);
    int isFullscreen = *(int *)((byte *)&vidConfig + 12) != 0;
    int aaSamples = *(int *)(*(int *)imp_r_aaSamples + 8);

    /* Find supported AA level */
    if (aaSamples > 1) {
        void *d3d = *(void **)(dxp + 4);
        void **d3dVtable = *(void ***)d3d;
        typedef HRESULT (*CheckMultiSample_fn)(void *, int, int, int, int, int, void *);
        int qualityLevels;
        int testSamples = aaSamples;
        while (testSamples > 1) {
            *(int *)(dxp + 11300) = testSamples;
            hr = ((CheckMultiSample_fn)d3dVtable[11])(d3d, 0, 1, 0x15, !isFullscreen, testSamples, &qualityLevels);
            if (hr >= 0) {
                *(int *)(dxp + 11304) = qualityLevels - 1;
                goto aa_done;
            }
            testSamples--;
        }
        *(int *)(dxp + 11300) = 0;
        *(int *)(dxp + 11304) = 0;
    }

aa_done:;
    /* Build D3DPRESENT_PARAMETERS */
    int d3dpp[14];
    memset(d3dpp, 0, sizeof(d3dpp));
    d3dpp[0] = backBufWidth;
    d3dpp[1] = backBufHeight;
    d3dpp[2] = 0x15; /* BackBufferFormat = D3DFMT_X8R8G8B8 */
    d3dpp[3] = 1;    /* BackBufferCount */
    d3dpp[4] = *(int *)(dxp + 11300); /* MultiSampleType */
    d3dpp[5] = *(int *)(dxp + 11304); /* MultiSampleQuality */
    d3dpp[6] = 1;    /* SwapEffect = D3DSWAPEFFECT_DISCARD */
    d3dpp[8] = 0x4b; /* AutoDepthStencilFormat */
    /* PresentationInterval: 1 if vsync, 0x80000000 if not */
    int swapInterval = *(byte *)(*(int *)imp_r_swapInterval + 8);
    d3dpp[11] = swapInterval ? 1 : 0x80000001;
    d3dpp[10] = displayMode;
    d3dpp[9] = 0; /* Windowed (set below) */
    if (isFullscreen) {
        d3dpp[7] = 0; /* hDeviceWindow = NULL (fullscreen) */
        d3dpp[12] = refreshRate;
    } else {
        d3dpp[7] = 1; /* Windowed = TRUE */
        d3dpp[12] = 0;
    }

    /* Release and reset device */
    R_ReleaseForShutdownOrReset();

    d3dDevice = *(void **)(dxp + 8);
    vtable = *(void ***)d3dDevice;
    typedef HRESULT (*Reset_fn)(void *, void *);
    hr = ((Reset_fn)vtable[16])(d3dDevice, d3dpp);

    if (hr < 0) {
        const char *msg = va("Couldn't reset a lost Direct3D device - IDirect3DDevice9::Reset returned %s", DXGetErrorDescription9A(hr));
        Printf(0, "------- Initializing Renderer -------");
        Printf(0, "------- Renderer Initialization -------");
        Printf(0, "------- Server Initialization -------");
        Printf(0, "\n%s\n", msg);
        Error();
    }

    *(byte *)(dxp + 11580) = 0;

    /* Recreate resources */
    if (!R_CreateForInitOrReset()) {
        Printf(0, "------- Initializing Renderer -------");
        Printf(0, "------- Renderer Initialization -------");
        Printf(0, "------- Server Initialization -------");
        Printf(0, "\nFailed to recreate resources after device reset\n");
        Error();
    }

    /* Reload assets */
    if (*(int *)((byte *)&rgp + 4252))
        R_ReloadWorld();

    Material_ReloadAll();
    R_ReloadLostImages();
    R_OptimizeAllModels();
    *(int *)(dxp + 11308) = RB_CalcSunSpriteSamples();

    Printf(0, "Device recovered successfully");
    return 1;
}

#if 0 /* original naked */
Bool R_RecoverLostDevice_naked(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2408 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl dx+8, %eax\n" /* line 2400 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "cmpl $0x88760868, %eax\n" /* line 2418 */
        "jne .Lfccdba_000ccde7\n"
        "xorl %eax, %eax\n"
        "addl $0x8c, %esp\n" /* line 2459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfccdba_000ccde7:\n"
        "movl $str_00223e68, 4(%esp)\n" /* line 2421 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll R_ReleaseAllModels\n" /* line 2424 */
        "calll R_ReleaseLostImages\n" /* line 2426 */
        "calll Material_ReleaseAll\n" /* line 2427 */
        "movl rgp+4252, %eax\n" /* line 2434 */
        "testl %eax, %eax\n"
        "je .Lfccdba_000cce19\n"
        "calll R_ReleaseWorld\n" /* line 2435 */
        ".Lfccdba_000cce19:\n"
        "movl dx+11596, %eax\n" /* line 2351 */
        "movl %eax, -0x40(%ebp)\n"
        "movl $0, -0x34(%ebp)\n" /* line 2352 */
        "movl $0, -0x30(%ebp)\n" /* line 2353 */
        "movl dx+11604, %eax\n" /* line 2354 */
        "movl %eax, -0x2c(%ebp)\n"
        "movl dx+11608, %eax\n" /* line 2355 */
        "movl %eax, -0x28(%ebp)\n"
        "movl vidConfig+8, %eax\n" /* line 2356 */
        "movl %eax, -0x3c(%ebp)\n"
        "movl vidConfig+12, %eax\n" /* line 2357 */
        "testl %eax, %eax\n"
        "setne -0x38(%ebp)\n"
        "movl imp_r_aaSamples, %eax\n" /* line 2358 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x20(%ebp)\n"
        "cmpl $1, %eax\n" /* line 213 */
        "jle .Lfccdba_000ccec2\n"
        "movl %eax, %ebx\n"
        "leal -0x1c(%ebp), %esi\n"
        "leal -2(%eax), %eax\n"
        "negl %eax\n"
        "leal -1(%eax, %ebx), %edi\n"
        ".Lfccdba_000cce72:\n"
        "movl %ebx, dx+11300\n" /* line 215 */
        "movl dx+4, %edx\n" /* line 216 */
        "movl (%edx), %ecx\n"
        "movl %esi, 0x18(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "xorl %eax, %eax\n"
        "cmpb $0, -0x38(%ebp)\n"
        "sete %al\n"
        "movl %eax, 0x10(%esp)\n"
        "movl $0x15, 0xc(%esp)\n"
        "movl $1, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x2c(%ecx)\n"
        "testl %eax, %eax\n" /* line 217 */
        "jns .Lfccdba_000cd05c\n"
        "subl $1, %ebx\n" /* line 222 */
        "cmpl %ebx, %edi\n" /* line 213 */
        "jne .Lfccdba_000cce72\n"
        ".Lfccdba_000ccec2:\n"
        "movl $0, dx+11300\n" /* line 225 */
        "movl $0, dx+11304\n" /* line 226 */
        ".Lfccdba_000cced6:\n"
        "leal -0x78(%ebp), %esi\n" /* line 246 */
        "cld\n"
        "movl $0xe, %ecx\n"
        "xorl %eax, %eax\n"
        "movl %esi, %edi\n"
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x2c(%ebp), %eax\n" /* line 247 */
        "movl %eax, -0x78(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* line 248 */
        "movl %eax, -0x74(%ebp)\n"
        "movl $0x15, -0x70(%ebp)\n" /* line 249 */
        "movl $1, -0x6c(%ebp)\n" /* line 250 */
        "movl dx+11300, %eax\n" /* line 251 */
        "movl %eax, -0x68(%ebp)\n"
        "movl dx+11304, %eax\n" /* line 252 */
        "movl %eax, -0x64(%ebp)\n"
        "movl $1, -0x60(%ebp)\n" /* line 253 */
        "movl $0, -0x54(%ebp)\n" /* line 254 */
        "movl $0x4b, -0x50(%ebp)\n" /* line 255 */
        "movl imp_r_swapInterval, %eax\n" /* line 276 */
        "movl (%eax), %eax\n"
        "cmpb $1, 8(%eax)\n"
        "sbbl %eax, %eax\n"
        "andl $0x7fffffff, %eax\n"
        "addl $1, %eax\n"
        "movl %eax, -0x44(%ebp)\n"
        "movl -0x40(%ebp), %eax\n" /* line 278 */
        "movl %eax, -0x5c(%ebp)\n"
        "movl $0, -0x4c(%ebp)\n" /* line 279 */
        "cmpb $0, -0x38(%ebp)\n" /* line 280 */
        "je .Lfccdba_000ccfe2\n"
        "movl $0, -0x58(%ebp)\n" /* line 282 */
        "movl -0x3c(%ebp), %eax\n" /* line 283 */
        "movl %eax, -0x48(%ebp)\n"
        ".Lfccdba_000ccf60:\n"
        "calll R_ReleaseForShutdownOrReset\n" /* line 2362 */
        "movl dx+8, %eax\n" /* line 2364 */
        "movl (%eax), %edx\n"
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x40(%edx)\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 2366 */
        "js .Lfccdba_000cd06c\n"
        ".Lfccdba_000ccf80:\n"
        "movb $0, dx+11580\n" /* line 2368 */
        "leal -0x40(%ebp), %edx\n" /* line 2370 */
        "movl %esi, %eax\n"
        "calll R_CreateForInitOrReset\n"
        "testb %al, %al\n"
        "je .Lfccdba_000ccff5\n"
        ".Lfccdba_000ccf95:\n"
        "movl rgp+4252, %edi\n" /* line 2441 */
        "testl %edi, %edi\n"
        "je .Lfccdba_000ccfa4\n"
        "calll R_ReloadWorld\n" /* line 2442 */
        ".Lfccdba_000ccfa4:\n"
        "calll Material_ReloadAll\n" /* line 2449 */
        "calll R_ReloadLostImages\n" /* line 2450 */
        "calll R_OptimizeAllModels\n" /* line 2451 */
        "calll RB_CalcSunSpriteSamples\n" /* line 2454 */
        "movl %eax, dx+11308\n"
        "movl $str_00223f10, 4(%esp)\n" /* line 2457 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $1, %eax\n"
        "addl $0x8c, %esp\n" /* line 2459 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfccdba_000ccfe2:\n"
        "movl $1, -0x58(%ebp)\n" /* line 287 */
        "movl $0, -0x48(%ebp)\n" /* line 288 */
        "jmp .Lfccdba_000ccf60\n"
        ".Lfccdba_000ccff5:\n"
        "movl $str_002238dc, 4(%esp)\n" /* line 125 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223938, 4(%esp)\n" /* line 126 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223994, 4(%esp)\n" /* line 127 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223edc, 8(%esp)\n" /* line 128 */
        "movl $str_002239f0, 4(%esp)\n" /* "
%s
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll *ri+72\n" /* line 131 */
        "jmp .Lfccdba_000ccf95\n"
        ".Lfccdba_000cd05c:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 219 */
        "subl $1, %eax\n"
        "movl %eax, dx+11304\n"
        "jmp .Lfccdba_000cced6\n"
        ".Lfccdba_000cd06c:\n"
        "movl %eax, (%esp)\n" /* line 177 */
        "calll DXGetErrorDescription9A\n"
        "movl %eax, 8(%esp)\n" /* line 2367 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_00223e84, (%esp)\n" /* "Couldn't reset a lost Direct3D device - IDirect3DDevice9::Re" */
        "calll va\n"
        "movl %eax, %ebx\n"
        "movl $str_002238dc, 4(%esp)\n" /* line 125 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223938, 4(%esp)\n" /* line 126 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl $str_00223994, 4(%esp)\n" /* line 127 */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "movl %ebx, 8(%esp)\n" /* line 128 */
        "movl $str_002239f0, 4(%esp)\n" /* "
%s
" */
        "movl $0, (%esp)\n"
        "calll *ri\n"
        "calll *ri+72\n" /* line 131 */
        "jmp .Lfccdba_000ccf80\n"
    );
}
#endif /* original naked R_RecoverLostDevice */

/* std::__adjust_heap for _D3DDISPLAYMODE* — heap sift-down + push-up (16-byte elements) */
void ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
    _D3DDISPLAYMODE *first, int holeIndex, int len, _D3DDISPLAYMODE value, D3DDispModeCompFunc comp)
{
    int topIndex = holeIndex;
    int secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (comp(&first[secondChild], &first[secondChild - 1]))
            secondChild--;
        first[holeIndex] = first[secondChild];
        holeIndex = secondChild;
        secondChild = 2 * secondChild + 2;
    }
    if (secondChild == len) {
        first[holeIndex] = first[len - 1];
        holeIndex = len - 1;
    }
    while (holeIndex > topIndex) {
        int parent = (holeIndex - 1) / 2;
        if (!comp(&first[parent], &value))
            break;
        first[holeIndex] = first[parent];
        holeIndex = parent;
    }
    first[holeIndex] = value;
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0x20(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x1c(%ebp), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x18(%ebp), %ecx\n"
        "movl %ecx, -0x38(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* __value */
        "movl %eax, -0x3c(%ebp)\n"
        /* { scope 1: __value */
        "movl 0xc(%ebp), %edx\n" /* line 276 | __holeIndex */
        "leal 2(%edx, %edx), %esi\n" /* __secondChild */
        "cmpl 0x10(%ebp), %esi\n" /* line 277 | __len, __secondChild */
        "jl .Lf2bf346_002bf432\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%eax, %ecx), %ebx\n"
        "movl %edx, %edi\n"
        "cmpl %esi, 0x10(%ebp)\n" /* line 286 | __secondChild, __len */
        "je .Lf2bf346_002bf49b\n"
        ".Lf2bf346_002bf38d:\n"
        "movl -0x30(%ebp), %eax\n" /* line 289 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl -0x3c(%ebp), %eax\n"
        "movl %eax, -0x28(%ebp)\n" /* __value */
        /* { scope 2 */
        "leal -1(%edi), %edx\n" /* line 165 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %esi\n"
        "sarl $1, %esi\n"
        "cmpl 0xc(%ebp), %edi\n" /* line 166 | __holeIndex */
        "jg .Lf2bf346_002bf40d\n"
        ".Lf2bf346_002bf3b7:\n"
        "movl -0x28(%ebp), %eax\n" /* line 173 | __value */
        "movl %eax, (%ebx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        /* } scope */
        /* } scope */
        "addl $0x4c, %esp\n" /* line 291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __value */
        /* { scope 2 */
        ".Lf2bf346_002bf3d6:\n"
        "movl %edi, %edx\n" /* line 169 */
        "shll $4, %edx\n"
        "movl (%ebx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "movl %eax, (%edx, %ecx)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx, %ecx)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%edx, %ecx)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%edx, %ecx)\n"
        "leal -1(%esi), %edx\n" /* line 171 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl 0xc(%ebp), %esi\n" /* line 166 | __holeIndex */
        "jle .Lf2bf346_002bf3b7\n"
        "movl %esi, %edi\n"
        "movl %eax, %esi\n"
        ".Lf2bf346_002bf40d:\n"
        "movl %esi, %eax\n"
        "shll $4, %eax\n"
        "movl 8(%ebp), %ebx\n" /* __first */
        "addl %eax, %ebx\n"
        "leal -0x28(%ebp), %edx\n" /* __value */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x24(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf346_002bf3d6\n"
        "shll $4, %edi\n"
        "movl 8(%ebp), %ebx\n" /* __first */
        "addl %edi, %ebx\n"
        "jmp .Lf2bf346_002bf3b7\n"
        /* } scope */
        ".Lf2bf346_002bf432:\n"
        "movl %edx, -0x2c(%ebp)\n" /* line 277 */
        "movl %esi, %edi\n" /* __secondChild */
        "jmp .Lf2bf346_002bf43e\n"
        ".Lf2bf346_002bf439:\n"
        "movl %edi, -0x2c(%ebp)\n"
        "movl %esi, %edi\n" /* __secondChild */
        ".Lf2bf346_002bf43e:\n"
        "movl %esi, %eax\n" /* line 279 | __secondChild */
        "shll $4, %eax\n"
        "movl 8(%ebp), %ebx\n" /* __first */
        "addl %eax, %ebx\n"
        "leal -0x10(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll *0x24(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf346_002bf466\n"
        "leal -1(%esi), %edi\n" /* line 281 | __secondChild */
        "movl %edi, %eax\n"
        "shll $4, %eax\n"
        "movl 8(%ebp), %ebx\n" /* __first */
        "addl %eax, %ebx\n"
        ".Lf2bf346_002bf466:\n"
        "movl -0x2c(%ebp), %edx\n" /* line 282 */
        "shll $4, %edx\n"
        "movl (%ebx), %eax\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "movl %eax, (%edx, %ecx)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%edx, %ecx)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%edx, %ecx)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%edx, %ecx)\n"
        "leal 2(%edi, %edi), %esi\n" /* line 284 | __secondChild */
        "cmpl %esi, 0x10(%ebp)\n" /* line 277 | __secondChild, __len */
        "jg .Lf2bf346_002bf439\n"
        "cmpl %esi, 0x10(%ebp)\n" /* line 286 | __secondChild, __len */
        "jne .Lf2bf346_002bf38d\n"
        ".Lf2bf346_002bf49b:\n"
        "movl 0x10(%ebp), %eax\n" /* line 288 | __len */
        "shll $4, %eax\n"
        "addl 8(%ebp), %eax\n" /* __first */
        "leal -0x10(%eax), %edx\n"
        "movl -0x10(%eax), %eax\n"
        "movl %eax, (%ebx)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 0xc(%ebx)\n"
        "movl 0x10(%ebp), %edi\n" /* line 289 | __len */
        "subl $1, %edi\n"
        "movl %edi, %eax\n"
        "shll $4, %eax\n"
        "movl 8(%ebp), %ebx\n" /* __first */
        "addl %eax, %ebx\n"
        "jmp .Lf2bf346_002bf38d\n"
    );
}
#endif /* original naked D3D adjust_heap */

/* std::__insertion_sort for _D3DDISPLAYMODE* — insertion sort with 16-byte element copies */
void ZSt16__insertion_sortIP15_D3DDISPLAYMODEPFhRKS0_S3_EEvT_S6_T0_(
    _D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, D3DDispModeCompFunc comp)
{
    _D3DDISPLAYMODE *i;
    if (first == last) return;
    for (i = first + 1; i != last; i++) {
        _D3DDISPLAYMODE val = *i;
        if (comp(&val, first)) {
            memmove(first + 1, first, (char *)i - (char *)first);
            *first = val;
        } else {
            _D3DDISPLAYMODE *prev = i - 1;
            _D3DDISPLAYMODE *hole = i;
            while (comp(&val, prev)) {
                *hole = *prev;
                hole = prev;
                prev--;
            }
            *hole = val;
        }
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2152 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 2154 | __last */
        "cmpl %eax, 8(%ebp)\n" /* __first */
        "je .Lf2bf4d4_002bf583\n"
        /* { scope 1: __val */
        "movl 8(%ebp), %edi\n" /* line 2156 | __first, __i */
        "addl $0x10, %edi\n" /* __i */
        "cmpl %edi, %eax\n" /* __i */
        "je .Lf2bf4d4_002bf583\n"
        /* { scope 2: __val */
        ".Lf2bf4d4_002bf4f7:\n"
        "movl (%edi), %eax\n" /* line 2159 | __i */
        "movl %eax, -0x28(%ebp)\n" /* __val */
        "movl 4(%edi), %eax\n" /* __i */
        "movl %eax, -0x24(%ebp)\n"
        "movl 8(%edi), %eax\n" /* __i */
        "movl %eax, -0x20(%ebp)\n"
        "movl 0xc(%edi), %eax\n" /* __i */
        "movl %eax, -0x1c(%ebp)\n"
        "movl 8(%ebp), %edx\n" /* line 2160 | __first */
        "movl %edx, 4(%esp)\n"
        "leal -0x28(%ebp), %eax\n" /* __val */
        "movl %eax, (%esp)\n"
        "calll *0x10(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf4d4_002bf58b\n"
        "leal 0x10(%edi), %edx\n" /* line 2162 | __i */
        "movl %edx, -0x3c(%ebp)\n"
        /* { scope 3 */
        "movl %edi, %esi\n" /* line 411 */
        "subl 8(%ebp), %esi\n" /* __first */
        "sarl $4, %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf2bf4d4_002bf55d\n"
        "movl %edi, %ecx\n"
        "xorl %ebx, %ebx\n"
        ".Lf2bf4d4_002bf538:\n"
        "movl -0x10(%ecx), %eax\n" /* line 412 */
        "movl %eax, -0x10(%edx)\n"
        "movl -0xc(%ecx), %eax\n"
        "movl %eax, -0xc(%edx)\n"
        "movl -8(%ecx), %eax\n"
        "movl %eax, -8(%edx)\n"
        "movl -4(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n"
        "subl $0x10, %ecx\n"
        "subl $0x10, %edx\n"
        "cmpl %esi, %ebx\n" /* line 411 */
        "jne .Lf2bf4d4_002bf538\n"
        /* } scope */
        ".Lf2bf4d4_002bf55d:\n"
        "movl -0x28(%ebp), %eax\n" /* line 2163 | __val */
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %eax, (%edx)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 0xc(%edx)\n"
        "movl -0x3c(%ebp), %edi\n" /* __i */
        /* } scope */
        ".Lf2bf4d4_002bf57a:\n"
        "cmpl %edi, 0xc(%ebp)\n" /* line 2156 | __i, __last */
        "jne .Lf2bf4d4_002bf4f7\n"
        /* } scope */
        ".Lf2bf4d4_002bf583:\n"
        "addl $0x4c, %esp\n" /* line 2166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __val */
        /* { scope 2: __val */
        ".Lf2bf4d4_002bf58b:\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl -0x28(%ebp), %eax\n" /* __val */
        "movl %eax, -0x38(%ebp)\n" /* __val */
        /* { scope 3 */
        "leal -0x10(%edi), %ebx\n" /* line 2107 */
        "movl %edi, %esi\n"
        "jmp .Lf2bf4d4_002bf5c5\n"
        ".Lf2bf4d4_002bf5aa:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl 0xc(%ebx), %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl %ebx, %esi\n" /* line 2112 */
        "subl $0x10, %ebx\n"
        ".Lf2bf4d4_002bf5c5:\n"
        "movl %ebx, 4(%esp)\n" /* line 2108 */
        "leal -0x38(%ebp), %eax\n" /* __val */
        "movl %eax, (%esp)\n"
        "calll *0x10(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf4d4_002bf5aa\n"
        "movl -0x38(%ebp), %eax\n" /* line 2114 | __val */
        "movl %eax, (%esi)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl -0x2c(%ebp), %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "addl $0x10, %edi\n"
        "jmp .Lf2bf4d4_002bf57a\n"
    );
}
#endif /* original naked D3D insertion_sort */

/* line 2514 */
/* std::__introsort_loop for _D3DDISPLAYMODE* — introsort with heapsort fallback (16-byte elements) */
void ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_(
    _D3DDISPLAYMODE *first, _D3DDISPLAYMODE *last, int depth_limit, D3DDispModeCompFunc comp)
{
    while ((char *)last - (char *)first > 16 * 16) { /* > 16 elements of 16 bytes */
        if (depth_limit == 0) {
            int n = (int)(last - first);
            int half = (n - 2) / 2;
            int i;
            _D3DDISPLAYMODE *end;
            for (i = half; i >= 0; i--)
                ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
                    first, i, n, first[i], comp);
            for (end = last - 1; end - first > 0; end--) {
                _D3DDISPLAYMODE value = *end;
                *end = *first;
                ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
                    first, 0, (int)(end - first), value, comp);
            }
            return;
        }
        depth_limit--;
        {
            int n = (int)(last - first);
            _D3DDISPLAYMODE *midPtr = first + n / 2;
            _D3DDISPLAYMODE *pivotPtr;
            _D3DDISPLAYMODE pivot;
            _D3DDISPLAYMODE *lo, *hi;
            if (comp(first, midPtr)) {
                if (comp(midPtr, last - 1))
                    pivotPtr = midPtr;
                else if (comp(first, last - 1))
                    pivotPtr = last - 1;
                else
                    pivotPtr = first;
            } else {
                if (comp(first, last - 1))
                    pivotPtr = first;
                else if (comp(last - 1, midPtr))
                    pivotPtr = midPtr;
                else
                    pivotPtr = last - 1;
            }
            pivot = *pivotPtr;
            lo = first;
            hi = last;
            for (;;) {
                while (!comp(&pivot, lo)) lo++;
                hi--;
                while (!comp(hi, &pivot)) hi--;
                if (lo >= hi) break;
                { _D3DDISPLAYMODE tmp = *lo; *lo = *hi; *hi = tmp; }
                lo++;
            }
            ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_(
                lo, last, depth_limit, comp);
            last = lo;
        }
    }
}

#if 0 /* original naked — replaced above */
{
    __asm__ __volatile__ (
        ".Lf2bf5f2_002bf5f2:\n"
        "pushl %ebp\n" /* line 2514 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: __pivot */
        "movl 0xc(%ebp), %eax\n" /* line 2519 | __last */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0x10f, %eax\n"
        "jle .Lf2bf5f2_002bf761\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 2521 | __depth_limit */
        "testl %edx, %edx\n"
        "jne .Lf2bf5f2_002bf76c\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf2bf5f2_002bf61a:\n"
        "cmpl $0x1f, %eax\n" /* line 397 */
        "jle .Lf2bf5f2_002bf761\n"
        "sarl $4, %eax\n" /* line 400 */
        "movl %eax, -0x6c(%ebp)\n"
        "subl $2, %eax\n" /* line 2514 */
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "movl %edx, -0x7c(%ebp)\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "movl 8(%ebp), %esi\n" /* __first */
        "addl %eax, %esi\n"
        "movl $0, -0x54(%ebp)\n"
        "jmp .Lf2bf5f2_002bf64f\n"
        ".Lf2bf5f2_002bf64b:\n"
        "addl $1, -0x54(%ebp)\n" /* line 406 */
        ".Lf2bf5f2_002bf64f:\n"
        "movl (%esi), %ebx\n" /* line 404 */
        "movl %ebx, -0x38(%ebp)\n"
        "movl 4(%esi), %ecx\n"
        "movl %ecx, -0x34(%ebp)\n"
        "movl 8(%esi), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl 0xc(%esi), %eax\n"
        "movl %eax, -0x2c(%ebp)\n"
        "movl 0x14(%ebp), %edi\n" /* __comp */
        "movl %edi, 0x1c(%esp)\n"
        "movl %ebx, 0xc(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0x14(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x7c(%ebp), %eax\n"
        "subl -0x54(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, (%esp)\n"
        "calll ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_\n"
        "subl $0x10, %esi\n"
        "movl -0x7c(%ebp), %edi\n" /* line 406 */
        "cmpl %edi, -0x54(%ebp)\n"
        "jne .Lf2bf5f2_002bf64b\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %esi\n" /* line 2521 | __last */
        "movl %esi, -0x60(%ebp)\n"
        "movl %esi, %edi\n"
        "subl $4, %edi\n"
        "movl %esi, %eax\n" /* line 2514 */
        "subl 8(%ebp), %eax\n" /* __first */
        "movl %eax, -0x58(%ebp)\n"
        "subl $0x10, %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        ".Lf2bf5f2_002bf6bd:\n"
        "movl (%edi), %eax\n" /* line 330 */
        "movl %eax, -0x68(%ebp)\n"
        "movl -4(%edi), %ebx\n"
        "movl -8(%edi), %ecx\n"
        "movl -0xc(%edi), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl 8(%ebp), %esi\n" /* line 301 | __first */
        "movl (%esi), %eax\n"
        "movl -0x60(%ebp), %esi\n"
        "movl %eax, -0x10(%esi)\n"
        "movl 8(%ebp), %esi\n" /* __first */
        "movl 4(%esi), %eax\n"
        "movl -0x60(%ebp), %esi\n"
        "movl %eax, -0xc(%esi)\n"
        "movl 8(%ebp), %esi\n" /* __first */
        "movl 8(%esi), %eax\n"
        "movl -0x60(%ebp), %esi\n"
        "movl %eax, -8(%esi)\n"
        "movl 8(%ebp), %esi\n" /* __first */
        "movl 0xc(%esi), %eax\n"
        "movl -0x60(%ebp), %esi\n"
        "movl %eax, -4(%esi)\n"
        "movl -0x68(%ebp), %eax\n" /* line 302 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl %ebx, -0x20(%ebp)\n"
        "movl %ecx, -0x24(%ebp)\n"
        "movl %edx, -0x28(%ebp)\n"
        "movl 0x14(%ebp), %esi\n" /* __comp */
        "movl %esi, 0x1c(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl %eax, 0x18(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "sarl $4, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, (%esp)\n"
        "calll ZSt13__adjust_heapIP15_D3DDISPLAYMODEiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_\n"
        "subl $0x10, -0x60(%ebp)\n"
        "subl $0x10, %edi\n"
        "subl $0x10, -0x5c(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 457 | __first */
        "subl 0xc(%ebp), %eax\n" /* __last */
        "addl -0x58(%ebp), %eax\n"
        "movl -0x5c(%ebp), %edx\n"
        "leal 0x10(%eax, %edx), %eax\n"
        "cmpl $0x1f, %eax\n"
        "jg .Lf2bf5f2_002bf6bd\n"
        /* } scope */
        /* } scope */
        ".Lf2bf5f2_002bf761:\n"
        "addl $0x9c, %esp\n" /* line 2538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __pivot */
        ".Lf2bf5f2_002bf76c:\n"
        "movl 0x10(%ebp), %esi\n" /* line 457 | __depth_limit */
        "movl %esi, -0x4c(%ebp)\n"
        "movl $0, -0x50(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* __last */
        ".Lf2bf5f2_002bf77c:\n"
        "subl $1, -0x4c(%ebp)\n" /* line 2526 */
        "movl 8(%ebp), %esi\n" /* __first */
        "sarl $4, %eax\n"
        "movl %eax, %edx\n"
        "shrl $0x1f, %edx\n"
        "addl %eax, %edx\n"
        "sarl $1, %edx\n"
        "shll $4, %edx\n"
        "movl %esi, %ebx\n"
        "addl %edx, %ebx\n"
        "subl $0x10, %edi\n"
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 124 */
        "movl %esi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf5f2_002bf8b3\n"
        "movl %edi, 4(%esp)\n" /* line 125 */
        "movl %ebx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf5f2_002bf850\n"
        ".Lf2bf5f2_002bf7bd:\n"
        "movl %ebx, %esi\n" /* line 133 */
        ".Lf2bf5f2_002bf7bf:\n"
        "movl 8(%esi), %edx\n" /* line 2536 | __b */
        "movl 4(%esi), %ecx\n" /* __b */
        "movl (%esi), %ebx\n" /* __b */
        "movl 0xc(%esi), %eax\n" /* __b */
        "movl %eax, -0x3c(%ebp)\n"
        "movl %edx, -0x40(%ebp)\n"
        "movl %ecx, -0x44(%ebp)\n"
        "movl %ebx, -0x48(%ebp)\n" /* __pivot */
        "movl 8(%ebp), %esi\n" /* __first, __b */
        "movl 0xc(%ebp), %edi\n" /* __last */
        /* } scope */
        /* { scope 2 */
        ".Lf2bf5f2_002bf7dc:\n"
        "leal -0x48(%ebp), %edx\n" /* line 2056 | __pivot */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf5f2_002bf84b\n"
        ".Lf2bf5f2_002bf7ed:\n"
        "subl $0x10, %edi\n" /* line 2060 */
        "movl %edi, 4(%esp)\n" /* line 2059 */
        "leal -0x48(%ebp), %eax\n" /* __pivot */
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf5f2_002bf7ed\n"
        "cmpl %edi, %esi\n" /* line 2061 */
        "jae .Lf2bf5f2_002bf86c\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%esi), %edx\n" /* line 97 */
        "movl 8(%esi), %ecx\n"
        "movl 4(%esi), %ebx\n"
        "movl (%esi), %eax\n"
        "movl %eax, -0x64(%ebp)\n"
        /* { scope 1: __pivot */
        /* { scope 2 */
        /* { scope 3 */
        "movl (%edi), %eax\n" /* line 98 */
        "movl %eax, (%esi)\n"
        "movl 4(%edi), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl 0xc(%edi), %eax\n"
        "movl %eax, 0xc(%esi)\n"
        "movl %edx, 0xc(%edi)\n" /* line 99 */
        "movl %ecx, 8(%edi)\n"
        "movl %ebx, 4(%edi)\n"
        "movl -0x64(%ebp), %edx\n"
        "movl %edx, (%edi)\n"
        /* } scope */
        "addl $0x10, %esi\n" /* line 2064 */
        "leal -0x48(%ebp), %edx\n" /* line 2056 | __pivot */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf5f2_002bf7ed\n"
        ".Lf2bf5f2_002bf84b:\n"
        "addl $0x10, %esi\n" /* line 2057 */
        "jmp .Lf2bf5f2_002bf7dc\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2bf5f2_002bf850:\n"
        "movl %edi, 4(%esp)\n" /* line 127 */
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf5f2_002bf7bf\n"
        "movl %edi, %esi\n" /* line 133 */
        "jmp .Lf2bf5f2_002bf7bf\n"
        /* } scope */
        ".Lf2bf5f2_002bf86c:\n"
        "movl 0x14(%ebp), %edx\n" /* line 2537 | __comp */
        "movl %edx, 0xc(%esp)\n"
        "movl -0x4c(%ebp), %edi\n"
        "movl %edi, 8(%esp)\n"
        "movl 0xc(%ebp), %eax\n" /* __last */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* __b */
        "calll ZSt16__introsort_loopIP15_D3DDISPLAYMODEiPFhRKS0_S3_EEvT_S6_T0_T1_\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 2519 */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0x10f, %eax\n"
        "jle .Lf2bf5f2_002bf761\n"
        "addl $1, -0x50(%ebp)\n"
        "movl %esi, 0xc(%ebp)\n" /* __last */
        /* { scope 1: __pivot */
        "movl 0x10(%ebp), %edx\n" /* line 2521 | __depth_limit */
        "cmpl %edx, -0x50(%ebp)\n"
        "je .Lf2bf5f2_002bf61a\n"
        "movl %esi, %edi\n"
        "jmp .Lf2bf5f2_002bf77c\n"
        /* { scope 2 */
        ".Lf2bf5f2_002bf8b3:\n"
        "movl %edi, 4(%esp)\n" /* line 131 */
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf5f2_002bf7bf\n"
        "movl %edi, 4(%esp)\n" /* line 133 */
        "movl %ebx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bf5f2_002bf7bd\n"
        "movl %edi, %esi\n"
        "jmp .Lf2bf5f2_002bf7bf\n"
    );
}
#endif /* original naked D3D introsort */
