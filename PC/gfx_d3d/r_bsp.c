/* ASM dump from: r_bsp.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_bsp.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/r_local.h"
 */

extern vec3_t vec3_colorintensity; /* 0x0 */

void R_ResetSunLightOverride(void);
void R_ReleaseWorld(void);
void R_GetWorldBounds(vec_t *min, vec_t *max);
void R_InterpretSunLightParseParams(SunLightParseParams *sunParse);
void R_SetSunLightOverride(const vec_t *sunColor);
IDirect3DVertexBuffer9 * R_CreateWorldVertexBuffer(GfxWorldVertex *vertices, int vertexCount);
void R_ReloadWorld(void);
void R_ShutdownWorld(void);
void R_UpdateLightsFromDvars(void);
void R_LoadWorld(const char *name, int *checksum);
void R_ResetSunLightParseParams(void);

/* line 273 */
__attribute__((naked))
void R_ResetSunLightOverride(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 0x195eebc, %eax\n" /* line 276 */
        "movl 0x109c(%eax), %eax\n"
        "leal 0xc8(%eax), %ebx\n" /* to */
        "leal 0xe0(%eax), %ecx\n" /* from */
        /* { scope 1 */
        "movl 0xe0(%eax), %edx\n" /* line 199 */
        "movl %edx, 0xc8(%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "popl %ebx\n" /* line 277 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 366 */
__attribute__((naked))
void R_ReleaseWorld(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 366 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eebc, %ebx\n" /* line 373 */
        "movl 0x109c(%ebx), %eax\n"
        "movl 0x30(%eax), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfe212a_000e2159\n"
        "movl %eax, (%esp)\n" /* line 375 */
        "calll R_FreeStaticVertexBuffer\n"
        "movl 0x109c(%ebx), %eax\n" /* line 376 */
        "movl $0, 0x30(%eax)\n"
        ".Lfe212a_000e2159:\n"
        "addl $0x14, %esp\n" /* line 378 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 166 */
__attribute__((naked))
void R_GetWorldBounds(vec_t *min, vec_t *max)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 166 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %edx\n" /* min */
        "movl 0xc(%ebp), %ebx\n" /* max */
        "movl 0x195eebc, %esi\n"
        "movl 0x109c(%esi), %eax\n"
        "leal 0x13c(%eax), %ecx\n"
        /* { scope 1 */
        "movl 0x13c(%eax), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl 0x109c(%esi), %eax\n"
        "leal 0x148(%eax), %edx\n"
        /* } scope */
        /* { scope 1 */
        "movl 0x148(%eax), %eax\n" /* line 199 */
        "movl %eax, (%ebx)\n" /* max */
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n" /* max */
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n" /* max */
        /* } scope */
        "popl %ebx\n" /* line 172 */
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 244 */
__attribute__((naked))
void R_InterpretSunLightParseParams(SunLightParseParams *sunParse)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 244 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eebc, %ebx\n" /* line 247 */
        "movl 0x109c(%ebx), %eax\n"
        "addl $0xb4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* sunParse */
        "movl %eax, (%esp)\n"
        "calll R_InterpretSunLightParseParamsIntoLights\n"
        "movl 0x109c(%ebx), %eax\n" /* line 248 | to */
        "leal 0xe0(%eax), %ebx\n" /* to */
        "leal 0xc8(%eax), %ecx\n" /* from */
        /* { scope 1 */
        "movl 0xc8(%eax), %edx\n" /* line 199 */
        "movl %edx, 0xe0(%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        "addl $0x14, %esp\n" /* line 249 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 261 */
__attribute__((naked))
void R_SetSunLightOverride(const vec_t *sunColor)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 261 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "movl 8(%ebp), %ebx\n" /* sunColor */
        "movl 0x195eec0, %eax\n" /* line 266 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe220e_000e2247\n"
        "movl 0x195eebc, %eax\n" /* line 269 */
        "movl 0x109c(%eax), %edx\n"
        "leal 0xc8(%edx), %ecx\n" /* to */
        /* { scope 1 */
        "movl (%ebx), %eax\n" /* line 199 */
        "movl %eax, 0xc8(%edx)\n"
        "movl 4(%ebx), %eax\n" /* line 200 */
        "movl %eax, 4(%ecx)\n"
        "movl 8(%ebx), %eax\n" /* line 201 */
        "movl %eax, 8(%ecx)\n"
        /* } scope */
        ".Lfe220e_000e2247:\n"
        "popl %ebx\n" /* line 270 */
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 24 */
__attribute__((naked))
IDirect3DVertexBuffer9 * R_CreateWorldVertexBuffer(GfxWorldVertex *vertices, int vertexCount)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 24 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %edi\n" /* vertexCount */
        /* { scope 1 */
        "movl 0x195eec0, %ebx\n" /* line 1078 | vertIndex */
        "movl (%ebx), %eax\n" /* vertIndex */
        "movl $0x20, %esi\n" /* sizeVerts */
        "cmpl $2, 8(%eax)\n"
        "movl $0x44, %eax\n"
        "cmovnel %eax, %esi\n" /* sizeVerts */
        "imull %edi, %esi\n" /* line 37 | vertexCount, sizeVerts */
        "movl %esi, 4(%esp)\n" /* line 39 | sizeVerts */
        "leal -0x1c(%ebp), %eax\n" /* worldVb */
        "movl %eax, (%esp)\n"
        "calll R_AllocStaticVertexBuffer\n"
        "movl %eax, %edx\n"
        "movl (%ebx), %eax\n" /* line 42 | vertIndex */
        "cmpl $2, 8(%eax)\n"
        "je .Lfe224a_000e22b4\n"
        "movl %esi, 8(%esp)\n" /* line 61 | sizeVerts */
        "movl 8(%ebp), %eax\n" /* vertices */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll Com_Memcpy\n"
        ".Lfe224a_000e229e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 65 | worldVb */
        "movl %eax, (%esp)\n"
        "calll R_FinishStaticVertexBuffer\n"
        "movl -0x1c(%ebp), %eax\n" /* worldVb */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 68 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfe224a_000e22b4:\n"
        "testl %edi, %edi\n" /* line 46 | vertexCount */
        "jle .Lfe224a_000e229e\n"
        "xorl %ebx, %ebx\n" /* vertIndex */
        "movl 8(%ebp), %ecx\n" /* vertices */
        ".Lfe224a_000e22bd:\n"
        "movl (%ecx), %eax\n" /* line 199 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%edx)\n"
        "movl 0x18(%ecx), %eax\n" /* line 50 */
        "movl %eax, 0xc(%edx)\n"
        "movl 0x1c(%ecx), %eax\n" /* line 37 */
        "movl %eax, 0x10(%edx)\n"
        "movl 0x20(%ecx), %eax\n" /* line 38 */
        "movl %eax, 0x14(%edx)\n"
        "movl 0x24(%ecx), %eax\n" /* line 37 */
        "movl %eax, 0x18(%edx)\n"
        "movl 0x28(%ecx), %eax\n" /* line 38 */
        "movl %eax, 0x1c(%edx)\n"
        "addl $1, %ebx\n" /* line 46 | vertIndex */
        "addl $0x20, %edx\n"
        "addl $0x44, %ecx\n"
        "cmpl %ebx, %edi\n" /* vertIndex, vertexCount */
        "jne .Lfe224a_000e22bd\n"
        "movl -0x1c(%ebp), %eax\n" /* line 65 | worldVb */
        "movl %eax, (%esp)\n"
        "calll R_FinishStaticVertexBuffer\n"
        "movl -0x1c(%ebp), %eax\n" /* worldVb */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 68 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 381 */
__attribute__((naked))
void R_ReloadWorld(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 381 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eebc, %eax\n" /* line 387 */
        "movl 0x109c(%eax), %ebx\n"
        "movl 0x28(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x2c(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll R_CreateWorldVertexBuffer\n"
        "movl %eax, 0x30(%ebx)\n"
        "addl $0x14, %esp\n" /* line 388 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 355 */
__attribute__((naked))
void R_ShutdownWorld(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 355 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x14, %esp\n"
        "movl 0x195eebc, %ebx\n" /* line 357 */
        "movl 0x109c(%ebx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfe233c_000e2379\n"
        "movl 0x30(%eax), %eax\n" /* line 373 */
        "testl %eax, %eax\n"
        "je .Lfe233c_000e236f\n"
        "movl %eax, (%esp)\n" /* line 375 */
        "calll R_FreeStaticVertexBuffer\n"
        "movl 0x109c(%ebx), %eax\n" /* line 376 */
        "movl $0, 0x30(%eax)\n"
        ".Lfe233c_000e236f:\n"
        "movl $0, 0x109c(%ebx)\n" /* line 362 */
        ".Lfe233c_000e2379:\n"
        "addl $0x14, %esp\n" /* line 363 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 252 */
__attribute__((naked))
void R_UpdateLightsFromDvars(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 252 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x90, %esp\n"
        /* { scope 1 */
        "movl 0x195ef38, %eax\n" /* line 229 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x48(%ebp)\n"
        "movl 0x195ef34, %eax\n" /* line 230 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl 0x195ef48, %eax\n" /* line 231 */
        "movl (%eax), %eax\n"
        "movl 8(%eax), %eax\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl 0x195ef3c, %eax\n"
        "movl (%eax), %edx\n"
        "xorl %ebx, %ebx\n" /* channelIter */
        "leal -0x88(%ebp), %esi\n" /* sunParse */
        "leal -0x44(%ebp), %ecx\n"
        /* { scope 2 */
        ".Lfe2380_000e23c4:\n"
        "movzbl 8(%edx), %eax\n" /* line 221 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%ecx)\n"
        "addl $1, %ebx\n" /* line 220 | channelIter */
        "addl $4, %ecx\n"
        "addl $1, %edx\n"
        "cmpl $3, %ebx\n" /* channelIter */
        "jne .Lfe2380_000e23c4\n"
        "leal -0x44(%ebp), %eax\n" /* line 223 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ColorNormalize\n"
        "fstp %st(0)\n"
        "movl 0x195ef30, %eax\n"
        "movl (%eax), %ecx\n"
        "xorb %bl, %bl\n" /* channelIter */
        "leal 0x58(%esi), %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lfe2380_000e23fb:\n"
        "movzbl 8(%ecx), %eax\n" /* line 221 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ebx\n" /* line 220 | channelIter */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $3, %ebx\n" /* channelIter */
        "jne .Lfe2380_000e23fb\n"
        "leal -0x30(%ebp), %eax\n" /* line 223 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ColorNormalize\n"
        "fstp %st(0)\n"
        "movl 0x195ef44, %eax\n"
        "movl (%eax), %ecx\n"
        "xorb %bl, %bl\n" /* channelIter */
        "leal 0x64(%esi), %edx\n"
        /* } scope */
        /* { scope 2 */
        ".Lfe2380_000e2432:\n"
        "movzbl 8(%ecx), %eax\n" /* line 221 */
        "cvtsi2ssl %eax, %xmm0\n"
        "movss %xmm0, (%edx)\n"
        "addl $1, %ebx\n" /* line 220 | channelIter */
        "addl $4, %edx\n"
        "addl $1, %ecx\n"
        "cmpl $3, %ebx\n" /* channelIter */
        "jne .Lfe2380_000e2432\n"
        "leal -0x24(%ebp), %eax\n" /* line 223 */
        "movl %eax, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll ColorNormalize\n"
        "fstp %st(0)\n"
        /* } scope */
        "movb $1, -0x18(%ebp)\n" /* line 237 */
        "movl 0x195ef4c, %eax\n"
        "movl (%eax), %eax\n"
        "movl 8(%eax), %edx\n"
        /* { scope 2 */
        "movl (%edx), %eax\n" /* line 199 */
        "movl %eax, -0x14(%ebp)\n"
        "movl 4(%edx), %eax\n" /* line 200 */
        "movl %eax, -0x10(%ebp)\n"
        "movl 8(%edx), %eax\n" /* line 201 */
        "movl %eax, -0xc(%ebp)\n"
        /* } scope */
        "movl 0x195eebc, %ebx\n" /* line 247 | channelIter */
        "movl 0x109c(%ebx), %eax\n" /* channelIter */
        "addl $0xb4, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll R_InterpretSunLightParseParamsIntoLights\n"
        "movl 0x109c(%ebx), %eax\n" /* line 248 | to */
        "leal 0xe0(%eax), %ebx\n" /* to */
        "leal 0xc8(%eax), %ecx\n" /* from */
        /* { scope 2 */
        "movl 0xc8(%eax), %edx\n" /* line 199 */
        "movl %edx, 0xe0(%eax)\n"
        "movl 4(%ecx), %eax\n" /* line 200 */
        "movl %eax, 4(%ebx)\n"
        "movl 8(%ecx), %eax\n" /* line 201 */
        "movl %eax, 8(%ebx)\n"
        /* } scope */
        /* } scope */
        "addl $0x90, %esp\n" /* line 258 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 317 */
__attribute__((naked))
void R_LoadWorld(const char *name, int *checksum)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 317 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %ebx\n" /* name */
        "movl 0xc(%ebp), %esi\n" /* checksum */
        "movl %ebx, (%esp)\n" /* line 321 | name */
        "calll RB_InitLightVisHistory\n"
        "movl %ebx, (%esp)\n" /* line 324 | name */
        "calll R_LoadWorldInternal\n"
        "movl 0x195eebc, %edx\n"
        "movl %eax, 0x109c(%edx)\n"
        "testl %esi, %esi\n" /* line 332 | checksum */
        "je .Lfe24ce_000e27b8\n"
        "movl 0x154(%eax), %eax\n" /* line 333 */
        "movl %eax, (%esi)\n" /* checksum */
        "movl 0x195eebc, %eax\n"
        ".Lfe24ce_000e250e:\n"
        "movl 0x109c(%eax), %ebx\n" /* name */
        "addl $0x34, %ebx\n" /* name */
        /* { scope 1 */
        "movl 0x195eee0, %esi\n" /* line 282 */
        "movl 0x40(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef38, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x9c(%esi)\n"
        "movl 0x50(%ebx), %eax\n" /* line 283 */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef34, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x9c(%esi)\n"
        "movl 0x54(%ebx), %eax\n" /* line 284 */
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef48, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x9c(%esi)\n"
        "movl $0x3f800000, %edi\n" /* line 286 */
        "movl %edi, 0x10(%esp)\n"
        "movl 0x4c(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x48(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x44(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef3c, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xa4(%esi)\n"
        "movl %edi, 0x10(%esp)\n" /* line 287 */
        "movl 0x60(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x5c(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x58(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef30, %edx\n"
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xa4(%esi)\n"
        "movl %edi, 0x10(%esp)\n" /* line 288 */
        "movl 0x6c(%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl 0x68(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x64(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef44, %edi\n"
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xa4(%esi)\n"
        "movl 0x7c(%ebx), %eax\n" /* line 290 */
        "movl %eax, 0xc(%esp)\n"
        "movl 0x78(%ebx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0x74(%ebx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 0x195ef4c, %ebx\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0xac(%esi)\n"
        "movl 0x80(%esi), %ecx\n" /* line 292 */
        "movl 0x195ef38, %eax\n"
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x80(%esi), %ecx\n" /* line 293 */
        "movl 0x195ef34, %eax\n"
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x80(%esi), %ecx\n" /* line 294 */
        "movl 0x195ef48, %eax\n"
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x80(%esi), %ecx\n" /* line 296 */
        "movl 0x195ef3c, %eax\n"
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x80(%esi), %ecx\n" /* line 297 */
        "movl 0x195ef30, %eax\n"
        "movl (%eax), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x80(%esi), %ecx\n" /* line 298 */
        "movl (%edi), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        "movl 0x80(%esi), %ecx\n" /* line 300 */
        "movl (%ebx), %edx\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *%ecx\n"
        /* } scope */
        "calll R_UpdateLightsFromDvars\n" /* line 336 */
        "calll R_FlushSun\n" /* line 338 */
        "calll R_ResetShadowCookies\n" /* line 339 */
        "calll R_InitStaticModelIndexCache\n" /* line 342 */
        "movl 0x195eebc, %edx\n" /* line 308 */
        "movl 0x109c(%edx), %eax\n"
        "movl 0xf4(%eax), %eax\n"
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl 0x195eec8, %ebx\n"
        "movl %eax, 0x3194(%ebx)\n"
        "movl 0x195eebc, %edx\n" /* line 309 */
        "movl 0x109c(%edx), %eax\n"
        "movl 0x10(%eax), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x3198(%ebx)\n"
        "movl 0x195eebc, %edx\n" /* line 310 */
        "movl 0x109c(%edx), %eax\n"
        "movl 0xec(%eax), %eax\n"
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, 0x319c(%ebx)\n"
        "movl 0x195eebc, %edx\n" /* line 312 */
        "movl 0x109c(%edx), %eax\n"
        "movl 0xf4(%eax), %eax\n"
        "testl %eax, %eax\n"
        "jg .Lfe24ce_000e275e\n"
        "movl 0x195eec0, %eax\n" /* line 347 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lfe24ce_000e2788\n"
        ".Lfe24ce_000e2756:\n"
        "addl $0x2c, %esp\n" /* line 350 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe24ce_000e275e:\n"
        "xorl %ebx, %ebx\n" /* line 312 */
        "movl %edx, %esi\n"
        ".Lfe24ce_000e2762:\n"
        "movl %ebx, (%esp)\n" /* line 313 */
        "calll R_InitStaticModelDynamicData\n"
        "addl $1, %ebx\n" /* line 312 */
        "movl 0x109c(%esi), %eax\n"
        "cmpl 0xf4(%eax), %ebx\n"
        "jl .Lfe24ce_000e2762\n"
        "movl 0x195eec0, %eax\n" /* line 347 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lfe24ce_000e2756\n"
        ".Lfe24ce_000e2788:\n"
        "movl $0, 8(%esp)\n" /* line 348 */
        "movl $1, 4(%esp)\n"
        "movl $0x224af8, (%esp)\n" /* "$sunhalfangle" */
        "calll Image_Register\n"
        "movl 0x195eebc, %edx\n"
        "movl %eax, 0x10a0(%edx)\n"
        "addl $0x2c, %esp\n" /* line 350 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfe24ce_000e27b8:\n"
        "movl %edx, %eax\n"
        "jmp .Lfe24ce_000e250e\n"
    );
}

/* line 210 */
__attribute__((naked))
void R_ResetSunLightParseParams(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 210 */
        "movl %esp, %ebp\n"
        "popl %ebp\n" /* line 213 */
        "jmp R_UpdateLightsFromDvars\n" /* line 212 */
    );
}

