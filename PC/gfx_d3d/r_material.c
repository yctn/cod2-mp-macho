/* ASM dump from: r_material.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_material.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_vector.h"
 *   #include "PC/gfx_d3d/r_material.h"
 */

extern const D3DVERTEXELEMENT9 declEnd; /* declEnd — defined in rodata.c */
static const BuiltInMaterialTable s_fillTestMaterials[12]; /* s_fillTestMaterials */
extern unsigned char materialGlobals[]; /* materialGlobals — 10752 bytes in bss.c */
extern const stream_source_info_t s_streamSourceInfo[]; /* s_streamSourceInfo — defined in rodata.c */
extern const stream_dest_info_t s_streamDestInfo[]; /* s_streamDestInfo — defined in rodata.c */

/* s_builtInMaterials + RB_RenderCommandTable must be contiguous in memory.
   Material_Init loops from s_builtInMaterials to RB_RenderCommandTable. */
__asm__(
    ".section .data\n"
    ".globl s_builtInMaterials\n"
    ".align 4\n"
    "s_builtInMaterials:\n"
    ".long str_00224168, rgp+0x102c\n"  /* $default */
    ".long str_00224174, rgp+0x1034\n"  /* stencil_plane */
    ".long str_00224184, rgp+0x1038\n"  /* white */
    ".long str_0022418c, rgp+0x103c\n"  /* $additive */
    ".long str_00224198, rgp+0x1058\n"  /* $glare_blind */
    ".long str_002241a8, rgp+0x1040\n"  /* $point */
    ".long str_002241b0, rgp+0x1044\n"  /* $line */
    ".long str_002241b8, rgp+0x1048\n"  /* clear_alpha_stencil */
    ".long str_002241cc, rgp+0x104c\n"  /* shadowclear */
    ".long str_002241d8, rgp+0x1050\n"  /* shadowcookieoverlay */
    ".long str_002241ec, rgp+0x1054\n"  /* shadowcookieblur */
    ".long str_002182a8, rgp+0x10d0\n"  /* shellshock */
    ".long str_00224200, rgp+0x108c\n"  /* color_channel_mixer */
    ".long str_00224214, rgp+0x1090\n"  /* frame_color_debug */
    ".long str_00224228, rgp+0x1094\n"  /* frame_alpha_debug */
    ".long str_0022423c, rgp+0x10ac\n"  /* feedbackblend */
    ".long str_0022424c, rgp+0x10a8\n"  /* feedbackreplace */
    ".long str_0022425c, rgp+0x10d4\n"  /* glow_setup */
    ".long str_00224268, rgp+0x10dc\n"  /* glow_apply_bloom */
    ".long str_0022427c, rgp+0x10d8\n"  /* glow_apply_sky_bleed */
    ".long str_00224294, rgp+0x10b0\n"  /* filter_symmetric_1 */
    ".long str_002242a8, rgp+0x10b4\n"  /* filter_symmetric_2 */
    ".long str_002242bc, rgp+0x10b8\n"  /* filter_symmetric_3 */
    ".long str_002242d0, rgp+0x10bc\n"  /* filter_symmetric_4 */
    ".long str_002242e4, rgp+0x10c0\n"  /* filter_symmetric_5 */
    ".long str_002242f8, rgp+0x10c4\n"  /* filter_symmetric_6 */
    ".long str_0022430c, rgp+0x10c8\n"  /* filter_symmetric_7 */
    ".long str_00224320, rgp+0x10cc\n"  /* filter_symmetric_8 */
    /* RB_RenderCommandTable must follow immediately — loop terminator */
    ".globl RB_RenderCommandTable\n"
    "RB_RenderCommandTable:\n"
    ".space 136, 0\n"  /* 34 entries * 4 bytes, filled at runtime or later */
    ".previous\n"
);

extern int R_HashAssetName(const char *name);
extern int stricmp(const char *s1, const char *s2);
extern void R_Error(int errorLevel, const char *msg, ...);
extern r_global_permanent_t rgp; /* imp_rgp */

void * Material_Alloc(int size);
const float * Material_RegisterLiteral(const vec_t *literal);
static Bool Material_Compare(const Material *mtl0, const Material *mtl1);
void Material_SetTechnique(const char *name, MaterialTechnique *technique);
void Material_SetTechniqueSet(const char *name, MaterialTechniqueSet *techniqueSet);
void Material_SetStateMap(const char *name, MaterialStateMap *stateMap);
void Material_SetShader(const char *shaderName, MaterialShaderType shaderType, int shaderVersion, MaterialShader *mtlShader);
Bool Material_IsDefault(const Material *material);
Bool R_IsMaterialRefractive(MaterialHandle handle);
void Material_FinishLoading(void);
void Material_ReleaseAll(void);
void Material_UpdatePicmipAll(void);
int Material_LoadFile(const char *filename, fileHandle_t *file);
const char * R_GetMaterialName(_ValueType handle);
int R_GetMaterialSubimageCount(MaterialHandle handle);
void Material_Sort(void);
const char * Material_RegisterString(const char *string);
MaterialVertexDeclaration * Material_AllocVertexDecl(MaterialStreamRouting *routingData, int streamCount, Bool *existing);
MaterialStateMap * Material_FindStateMap(const char *name);
MaterialTechniqueSet * Material_FindTechniqueSet(const char *name);
MaterialTechnique * Material_FindTechnique(const char *name);
MaterialShader * Material_FindShader(const char *shaderName, MaterialShaderType shaderType, int shaderVersion);
void Material_Shutdown(void);
_ValueType R_RegisterRawImage(const char *name, int baseImageFlags, int imageTrack);
void Material_ReloadAll(void);
void Load_BuildVertexDecl(MaterialVertexDeclaration * *mtlVertDecl);
void R_Cmd_ReloadMaterialTextures(void);
_ValueType Material_Duplicate(_ValueType mtlCopy, const char *name);
MaterialHandle Material_Register(const char *name, int imageTrack);
MaterialHandle Material_RegisterHandle(const char *name, int baseImageFlags, int imageTrack);
void Material_Init(void);
void ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_(void); /* void std___adjust_heap<Material**, int, Material*, unsigned char (*)(Material const*, Material const*)> */
void ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_(void); /* void std___insertion_sort<Material**, unsigned char (*)(Material const*, Material const*)> */
void ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_(void); /* void std___introsort_loop<Material**, int, unsigned char (*)(Material const*, Material const*)> */

/* line 218 */
void * Material_Alloc(int size)
{
    return ((void *(*)(int))(*(void **)((char *)imp_ri + 0xc)))(size);
}

/* line 314 */
const float * Material_RegisterLiteral(const vec_t *literal)
{
    int literalCount = *(int *)((byte *)materialGlobals + 0x230c);
    float *literals = (float *)((byte *)materialGlobals + 0x2310);
    int i;

    for (i = 0; i < literalCount; i++) {
        float *entry = literals + i * 4;
        if (entry[0] == literal[0] && entry[1] == literal[1] &&
            entry[2] == literal[2] && entry[3] == literal[3]) {
            return entry;
        }
    }

    if (literalCount >= 16) {
        R_Error(1, "more than %i shader literals used", 16);
    }

    {
        float *dest = literals + literalCount * 4;
        dest[0] = literal[0];
        dest[1] = literal[1];
        dest[2] = literal[2];
        dest[3] = literal[3];
        return dest;
    }
}

/* line 529 */
static Bool Material_Compare(const Material *mtl0, const Material *mtl1)
{
    int diff = (int)mtl0->info.sortKey - (int)mtl1->info.sortKey;
    if (diff != 0)
        return (unsigned int)diff >> 31;
    diff = (int)((unsigned int)mtl0->techniqueSet - (unsigned int)mtl1->techniqueSet);
    if (diff == 0)
        return 0;
    return (unsigned int)diff >> 31;
}

/* line 581 */
void Material_SetTechnique(const char *name, MaterialTechnique *technique)
{
    if (*(int *)((char *)materialGlobals + 4872) == 0x3ff) {
        R_Error(1, "More than %i techniques in use", 0x3ff);
    }

    int hash = R_HashAssetName(name) & 0x3ff;

    while (*(void **)((char *)materialGlobals + 0x130C + hash * 4) != NULL) {
        if (stricmp(*(char **)((char *)materialGlobals + 0x130C + hash * 4), name) == 0)
            break;
        hash = (hash + 1) & 0x3ff;
    }

    (*(int *)((char *)materialGlobals + 4872))++;
    *(MaterialTechnique **)((char *)materialGlobals + 0x130C + hash * 4) = technique;
}

/* line 647 */
void Material_SetTechniqueSet(const char *name, MaterialTechniqueSet *techniqueSet)
{
    int hash = R_HashAssetName(name) & 0x3ff;

    while (*(void **)((char *)materialGlobals + 0x308 + hash * 4) != NULL) {
        if (stricmp(*(char **)((char *)materialGlobals + 0x308 + hash * 4), name) == 0)
            break;
        hash = (hash + 1) & 0x3ff;
    }

    *(MaterialTechniqueSet **)((char *)materialGlobals + 0x308 + hash * 4) = techniqueSet;
}

/* line 709 */
void Material_SetStateMap(const char *name, MaterialStateMap *stateMap)
{
    int hash = R_HashAssetName(name) & 0x1f;

    while (*(void **)((char *)materialGlobals + 0x2414 + hash * 4) != NULL) {
        if (strcmp(*(char **)((char *)materialGlobals + 0x2414 + hash * 4), name) == 0)
            break;
        hash = (hash + 1) & 0x1f;
    }

    *(MaterialStateMap **)((char *)materialGlobals + 0x2414 + hash * 4) = stateMap;
}

/* line 793 */
void Material_SetShader(const char *shaderName, MaterialShaderType shaderType, int shaderVersion, MaterialShader *mtlShader)
{
    (*(int *)((char *)materialGlobals + 9624))++;
    if (*(int *)((char *)materialGlobals + 9624) == 0x100) {
        R_Error(1, "More than %i unique pixel and vertex shaders", 0xff);
    }

    int hash = R_HashAssetName(shaderName);
    hash = ((int)shaderType * 97 + shaderVersion + hash) & 0xff;

    void *entry = *(void **)((char *)materialGlobals + 0x259C + hash * 4);
    while (entry != NULL) {
        if (*(byte *)((byte *)entry + 0xa) == (byte)shaderType &&
            *(byte *)((byte *)entry + 0xb) == (byte)shaderVersion &&
            strcmp(*(char **)entry, shaderName) == 0)
            break;
        hash = (hash + 1) & 0xff;
        entry = *(void **)((char *)materialGlobals + 0x259C + hash * 4);
    }

    *(MaterialShader **)((char *)materialGlobals + 0x259C + hash * 4) = mtlShader;
}

/* line 981 */
Bool Material_IsDefault(const Material *material)
{
    const Material *defaultMtl = *(const Material **)(*(int *)imp_rgp + 0x102c);
    if (material->textures != defaultMtl->textures)
        return 0;
    if (material->constants != defaultMtl->constants)
        return 0;
    if (material->techniqueSet != defaultMtl->techniqueSet)
        return 0;
    return 1;
}

/* line 1278 */
Bool R_IsMaterialRefractive(MaterialHandle handle)
{
    if (*(int *)((byte *)(*(void **)(*(int *)imp_r_rendererInUse)) + 8) == 2)
        return 0;
    MaterialTechniqueSet *ts = handle->techniqueSet;
    MaterialTechnique *tech = ts->techniques[21];
    if (!tech)
        return 0;
    if (!(tech->flags & 1))
        return 0;
    return 1;
}

/* line 1366 */
void Material_FinishLoading(void)
{
}

/* line 1470 */
__attribute__((naked))
void Material_ReleaseAll(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1470 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "calll RB_ReleaseVertexDecl\n" /* line 1381 */
        "movl $materialGlobals+4, -0x1c(%ebp)\n"
        ".Lfd346a_000d347f:\n"
        "movl -0x1c(%ebp), %esi\n"
        "movl $4, %edi\n"
        ".Lfd346a_000d3487:\n"
        "leal 8(%esi), %ebx\n" /* line 1470 */
        "movl 8(%esi), %eax\n" /* line 1389 */
        "testl %eax, %eax\n"
        "je .Lfd346a_000d34ac\n"
        ".Lfd346a_000d3491:\n"
        "movl (%ebx), %eax\n" /* line 1390 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, (%ebx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd346a_000d3491\n"
        ".Lfd346a_000d34ac:\n"
        "addl $4, %esi\n"
        "subl $1, %edi\n" /* line 1387 */
        "jne .Lfd346a_000d3487\n"
        "addl $0x18, -0x1c(%ebp)\n" /* line 1393 */
        "cmpl $materialGlobals+772, -0x1c(%ebp)\n" /* line 1385 */
        "jne .Lfd346a_000d347f\n"
        "movl $materialGlobals, %ebx\n"
        ".Lfd346a_000d34c6:\n"
        "movl 0x259c(%ebx), %eax\n" /* line 838 */
        "testl %eax, %eax\n"
        "je .Lfd346a_000d34db\n"
        "movl 0xc(%eax), %eax\n" /* line 813 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        ".Lfd346a_000d34db:\n"
        "addl $4, %ebx\n"
        "cmpl $materialGlobals+1024, %ebx\n" /* line 836 */
        "jne .Lfd346a_000d34c6\n"
        "addl $0x2c, %esp\n" /* line 1476 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1538 */
__attribute__((naked))
void Material_UpdatePicmipAll(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1538 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "calll R_SetPicmip\n" /* line 1545 */
        "movl imp_rg, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "movl %eax, %ecx\n"
        "movl %eax, -0x20(%ebp)\n"
        ".Lfd34ee_000d3509:\n"
        "movl 0x28(%eax), %ebx\n" /* line 1550 | material */
        "testl %ebx, %ebx\n" /* line 1551 | material */
        "je .Lfd34ee_000d3547\n"
        "movzwl 0x34(%ebx), %edx\n" /* line 1554 | material */
        "testl %edx, %edx\n"
        "jle .Lfd34ee_000d3547\n"
        "xorl %edi, %edi\n" /* textureIndex */
        "xorl %esi, %esi\n"
        ".Lfd34ee_000d351c:\n"
        "movl %esi, %eax\n" /* line 1555 | texdef */
        "addl 0x3c(%ebx), %eax\n" /* material, texdef */
        /* { scope 2 */
        "cmpb $5, 5(%eax)\n" /* line 1530 */
        "je .Lfd34ee_000d353a\n"
        "movl 8(%eax), %eax\n" /* line 1532 */
        "testl %eax, %eax\n"
        "je .Lfd34ee_000d353a\n"
        "movl %eax, (%esp)\n" /* line 1534 */
        "calll Image_UpdatePicmip\n"
        "movzwl 0x34(%ebx), %edx\n"
        /* } scope */
        ".Lfd34ee_000d353a:\n"
        "addl $1, %edi\n" /* line 1554 | textureIndex */
        "addl $0xc, %esi\n"
        "cmpl %edx, %edi\n" /* textureIndex */
        "jl .Lfd34ee_000d351c\n"
        "movl -0x20(%ebp), %ecx\n"
        ".Lfd34ee_000d3547:\n"
        "addl $4, -0x1c(%ebp)\n"
        "leal 0x1000(%ecx), %eax\n" /* line 1538 */
        "cmpl -0x1c(%ebp), %eax\n" /* line 1548 */
        "je .Lfd34ee_000d355b\n"
        "movl -0x1c(%ebp), %eax\n"
        "jmp .Lfd34ee_000d3509\n"
        /* } scope */
        ".Lfd34ee_000d355b:\n"
        "addl $0x2c, %esp\n" /* line 1557 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1588 */
__attribute__((naked))
int Material_LoadFile(const char *filename, fileHandle_t *file)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1588 */
        "movl %esp, %ebp\n"
        "pushl %ebx\n"
        "subl $0x54, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 1592 | filename */
        "movl %eax, 0xc(%esp)\n"
        "movl $str_002243a8, 8(%esp)\n" /* "materials/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x48(%ebp), %ebx\n" /* fullFilename */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $1, 8(%esp)\n" /* line 1593 */
        "movl 0xc(%ebp), %eax\n" /* file */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0x130(%eax)\n"
        /* } scope */
        "addl $0x54, %esp\n" /* line 1594 */
        "popl %ebx\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1261 */
const char * R_GetMaterialName(_ValueType handle)
{
    return *(const char **)(*(int *)&handle);
}

/* line 1268 */
int R_GetMaterialSubimageCount(MaterialHandle handle)
{
    return handle->info.textureAtlasColumnCount * handle->info.textureAtlasRowCount;
}

/* line 876 */
__attribute__((naked))
void Material_Sort(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 876 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_rgp, %ebx\n" /* line 884 */
        "movl 4(%ebx), %eax\n"
        "leal 8(%ebx), %edx\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x24(%ebp)\n" /* __last */
        /* { scope 2: __last */
        "cmpl %edx, %eax\n" /* line 2604 */
        "je .Lfd35d0_000d36a6\n"
        "movl %eax, %edi\n" /* line 2606 | __n */
        "subl %edx, %edi\n"
        "movl %edi, %eax\n" /* __n */
        "sarl $2, %eax\n" /* __n */
        /* { scope 3 */
        /* { scope 4: __val */
        "cmpl $1, %eax\n" /* line 2253 */
        "je .Lfd35d0_000d36ed\n"
        "xorl %edx, %edx\n"
        ".Lfd35d0_000d3607:\n"
        "addl $1, %edx\n" /* line 2254 */
        "sarl $1, %eax\n" /* line 2253 */
        "cmpl $1, %eax\n"
        "jne .Lfd35d0_000d3607\n"
        "leal (%edx, %edx), %eax\n"
        /* } scope */
        /* } scope */
        ".Lfd35d0_000d3614:\n"
        "movl $Material_Compare, 0xc(%esp)\n" /* line 2606 */
        "movl %eax, 8(%esp)\n" /* __n */
        "movl -0x24(%ebp), %eax\n" /* __last, __n */
        "movl %eax, 4(%esp)\n" /* __n */
        "leal 8(%ebx), %esi\n" /* __last */
        "movl %esi, (%esp)\n"
        "calll ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_\n"
        "cmpl $0x43, %edi\n" /* line 2233 */
        "jle .Lfd35d0_000d36cb\n"
        "movl $Material_Compare, 8(%esp)\n" /* line 2235 */
        "addl $0x48, %ebx\n" /* __last */
        "movl %ebx, 4(%esp)\n" /* __last */
        "movl %esi, (%esp)\n"
        "calll ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_\n"
        /* { scope 3 */
        /* { scope 4: __val */
        "cmpl %ebx, -0x24(%ebp)\n" /* line 2200 | __last */
        "je .Lfd35d0_000d36a0\n"
        "movl %ebx, -0x1c(%ebp)\n"
        "movl %ebx, %eax\n"
        "movl %ebx, %edi\n"
        ".Lfd35d0_000d365e:\n"
        "movl (%eax), %eax\n" /* line 2201 */
        "movl %eax, -0x20(%ebp)\n" /* __val */
        "movl -0x1c(%ebp), %ebx\n" /* __last */
        "subl $4, %ebx\n" /* __last */
        "jmp .Lfd35d0_000d3675\n"
        /* { scope 5 */
        ".Lfd35d0_000d366b:\n"
        "movl %esi, (%edi)\n" /* line 2110 */
        "movl %ebx, %edi\n" /* line 2112 */
        "subl $4, %ebx\n"
        "movl -0x20(%ebp), %eax\n" /* __val */
        ".Lfd35d0_000d3675:\n"
        "movl (%ebx), %esi\n" /* line 2108 */
        "movl %esi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Material_Compare\n"
        "testb %al, %al\n"
        "jne .Lfd35d0_000d366b\n"
        "movl -0x20(%ebp), %eax\n" /* line 2114 | __val */
        "movl %eax, (%edi)\n"
        /* } scope */
        "addl $4, -0x1c(%ebp)\n" /* line 2200 */
        "movl -0x1c(%ebp), %eax\n"
        "cmpl %eax, -0x24(%ebp)\n" /* __last */
        "je .Lfd35d0_000d36a0\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl -0x1c(%ebp), %edi\n"
        "jmp .Lfd35d0_000d365e\n"
        ".Lfd35d0_000d36a0:\n"
        "movl imp_rgp, %ebx\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lfd35d0_000d36a6:\n"
        "movl 4(%ebx), %ecx\n" /* line 886 */
        "testl %ecx, %ecx\n"
        "jle .Lfd35d0_000d36c3\n"
        "xorl %edx, %edx\n"
        "movl %ebx, %ecx\n"
        ".Lfd35d0_000d36b1:\n"
        "movl 8(%ecx), %eax\n" /* line 887 */
        "movw %dx, 0xa(%eax)\n"
        "addl $1, %edx\n" /* line 886 */
        "addl $4, %ecx\n"
        "cmpl 4(%ebx), %edx\n"
        "jl .Lfd35d0_000d36b1\n"
        /* } scope */
        ".Lfd35d0_000d36c3:\n"
        "addl $0x2c, %esp\n" /* line 888 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd35d0_000d36cb:\n"
        "movl $Material_Compare, 8(%esp)\n" /* line 2240 */
        "movl -0x24(%ebp), %eax\n" /* __last */
        "movl %eax, 4(%esp)\n"
        "movl imp_rgp, %ebx\n" /* __last */
        "leal 8(%ebx), %eax\n" /* __last */
        "movl %eax, (%esp)\n"
        "calll ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_\n"
        "jmp .Lfd35d0_000d36a6\n"
        /* { scope 2: __last */
        /* { scope 3 */
        ".Lfd35d0_000d36ed:\n"
        "xorb %al, %al\n" /* line 2253 */
        "jmp .Lfd35d0_000d3614\n"
    );
}

/* line 338 */
__attribute__((naked))
const char * Material_RegisterString(const char *string)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 338 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 8(%ebp), %eax\n" /* line 344 | string */
        "movl %eax, (%esp)\n"
        "calll R_HashString\n"
        "movl %eax, %esi\n" /* hashIndex */
        "andl $0x3f, %esi\n" /* hashIndex */
        "movl materialGlobals+9368(, %esi, 4), %ebx\n" /* line 345 */
        "testl %ebx, %ebx\n"
        "je .Lfd36f4_000d373c\n"
        ".Lfd36f4_000d3718:\n"
        "movl 8(%ebp), %eax\n" /* line 347 | string */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfd36f4_000d3792\n"
        "addl $1, %esi\n" /* line 350 | hashIndex */
        "andl $0x3f, %esi\n" /* hashIndex */
        "movl materialGlobals+9368(, %esi, 4), %ebx\n" /* line 345 */
        "testl %ebx, %ebx\n"
        "jne .Lfd36f4_000d3718\n"
        ".Lfd36f4_000d373c:\n"
        "movl materialGlobals+9364, %eax\n" /* line 353 */
        "addl $1, %eax\n"
        "movl %eax, materialGlobals+9364\n"
        "cmpl $0x40, %eax\n" /* line 354 */
        "je .Lfd36f4_000d379c\n"
        ".Lfd36f4_000d374e:\n"
        "cld\n" /* line 357 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* string */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "movl %ebx, (%esp)\n" /* line 221 */
        "movl imp_ri, %eax\n"
        "calll *0xc(%eax)\n"
        "movl %eax, %edi\n"
        "movl %ebx, 8(%esp)\n" /* line 359 */
        "movl 8(%ebp), %eax\n" /* string */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll memcpy\n"
        "movl $materialGlobals+9360, %eax\n" /* line 361 */
        "movl %edi, 8(%eax, %esi, 4)\n"
        "movl %edi, %eax\n" /* line 362 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd36f4_000d3792:\n"
        "movl %ebx, %eax\n" /* line 348 */
        /* } scope */
        "addl $0x1c, %esp\n" /* line 363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd36f4_000d379c:\n"
        "movl $0x3f, 8(%esp)\n" /* line 355 */
        "movl $str_002243b8, 4(%esp)\n" /* "More than %i string identifiers used by shaders" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfd36f4_000d374e\n"
    );
}

/* line 492 */
__attribute__((naked))
MaterialVertexDeclaration * Material_AllocVertexDecl(MaterialStreamRouting *routingData, int streamCount, Bool *existing)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 492 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        /* { scope 2 */
        "movl 0xc(%ebp), %eax\n" /* line 402 | streamCount */
        "addl %eax, %eax\n"
        "movl %eax, -0x1c(%ebp)\n"
        "testl %eax, %eax\n" /* line 403 */
        "jg .Lfd37ba_000d388a\n"
        "xorl %ebx, %ebx\n" /* hash */
        "jmp .Lfd37ba_000d37e5\n"
        /* } scope */
        ".Lfd37ba_000d37d7:\n"
        "movl 0xc(%ebp), %eax\n" /* line 502 | streamCount */
        "cmpl 4(%edx), %eax\n"
        "je .Lfd37ba_000d385c\n"
        ".Lfd37ba_000d37df:\n"
        "addl $1, %ebx\n" /* line 508 | data */
        "andl $0x1f, %ebx\n" /* data */
        ".Lfd37ba_000d37e5:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 499 | data */
        "leal materialGlobals(, %eax, 8), %eax\n"
        "leal 4(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n" /* mvd */
        "movl 4(%eax), %esi\n" /* line 500 */
        "testl %esi, %esi\n"
        "jne .Lfd37ba_000d37d7\n"
        "cmpl $0x1f, materialGlobals\n" /* line 511 */
        "je .Lfd37ba_000d38ad\n"
        ".Lfd37ba_000d3809:\n"
        "addl $1, materialGlobals\n" /* line 513 */
        "movl -0x1c(%ebp), %esi\n" /* line 221 */
        "movl %esi, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0xc(%eax)\n"
        "movl %eax, %ebx\n"
        "movl %esi, 8(%esp)\n" /* line 516 */
        "movl 8(%ebp), %eax\n" /* routingData */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* data */
        "calll memcpy\n"
        "cld\n" /* line 518 */
        "movl $6, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x20(%ebp), %edi\n" /* mvd */
        "rep stosl %eax, %es:(%edi)\n"
        "movl -0x20(%ebp), %edx\n" /* line 519 | mvd */
        "movl %ebx, (%edx)\n" /* data */
        "movl 0xc(%ebp), %esi\n" /* line 520 | streamCount */
        "movl %esi, 4(%edx)\n"
        "movl 0x10(%ebp), %eax\n" /* line 522 | existing */
        "movb $0, (%eax)\n"
        /* } scope */
        ".Lfd37ba_000d3851:\n"
        "movl -0x20(%ebp), %eax\n" /* line 524 | mvd */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd37ba_000d385c:\n"
        "cld\n" /* line 502 */
        "movl -0x1c(%ebp), %eax\n"
        "cmpl %eax, %eax\n"
        "movl 8(%ebp), %edi\n" /* routingData */
        "movl %eax, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lfd37ba_000d387a\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lfd37ba_000d387a:\n"
        "testl %eax, %eax\n"
        "jne .Lfd37ba_000d37df\n"
        "movl 0x10(%ebp), %edx\n" /* line 504 | existing */
        "movb $1, (%edx)\n"
        "jmp .Lfd37ba_000d3851\n"
        /* { scope 2 */
        ".Lfd37ba_000d388a:\n"
        "xorl %ecx, %ecx\n" /* line 403 */
        "xorl %ebx, %ebx\n" /* hash */
        "movl 8(%ebp), %esi\n" /* routingData */
        ".Lfd37ba_000d3891:\n"
        "leal 0x77(%ecx), %eax\n" /* line 404 */
        "movzbl (%esi, %ecx), %edx\n"
        "imull %edx, %eax\n"
        "addl %eax, %ebx\n" /* hash */
        "addl $1, %ecx\n" /* line 403 */
        "cmpl %ecx, -0x1c(%ebp)\n"
        "jne .Lfd37ba_000d3891\n"
        "andl $0x1f, %ebx\n" /* hash */
        "jmp .Lfd37ba_000d37e5\n"
        /* } scope */
        ".Lfd37ba_000d38ad:\n"
        "movl $0x1f, 8(%esp)\n" /* line 512 */
        "movl $str_002243e8, 4(%esp)\n" /* "More than %i vertex declarations in use" */
        "movl $1, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfd37ba_000d3809\n"
    );
}

/* line 699 */
MaterialStateMap * Material_FindStateMap(const char *name)
{
    int hash = R_HashAssetName(name) & 0x1f;
    MaterialStateMap *entry = ((MaterialStateMap * *)((char *)materialGlobals + 9236))[hash];
    while (entry) {
        if (strcmp(entry->name, name) == 0)
            return entry;
        hash = (hash + 1) & 0x1f;
        entry = ((MaterialStateMap * *)((char *)materialGlobals + 9236))[hash];
    }
    return NULL;
}

/* line 636 */
MaterialTechniqueSet * Material_FindTechniqueSet(const char *name)
{
    int hash = R_HashAssetName(name) & 0x3ff;
    MaterialTechniqueSet *entry = ((MaterialTechniqueSet * *)((char *)materialGlobals + 776))[hash];
    while (entry) {
        if (stricmp(entry->name, name) == 0)
            return entry;
        hash = (hash + 1) & 0x3ff;
        entry = ((MaterialTechniqueSet * *)((char *)materialGlobals + 776))[hash];
    }
    return NULL;
}

/* line 569 */
MaterialTechnique * Material_FindTechnique(const char *name)
{
    int hash = R_HashAssetName(name) & 0x3ff;
    MaterialTechnique *entry = ((MaterialTechnique * *)((char *)materialGlobals + 4876))[hash];
    while (entry) {
        if (stricmp(entry->name, name) == 0)
            return entry;
        hash = (hash + 1) & 0x3ff;
        entry = ((MaterialTechnique * *)((char *)materialGlobals + 4876))[hash];
    }
    return NULL;
}

/* line 780 */
MaterialShader * Material_FindShader(const char *shaderName, MaterialShaderType shaderType, int shaderVersion)
{
    int hash = (R_HashAssetName(shaderName) + shaderType * 97 + shaderVersion) & 0xff;
    MaterialShader *entry = ((MaterialShader * *)((char *)materialGlobals + 9628))[hash];
    while (entry) {
        if (entry->shaderType == shaderType && entry->shaderVersion == shaderVersion && strcmp(entry->name, shaderName) == 0)
            return entry;
        hash = (hash + 1) & 0xff;
        entry = ((MaterialShader * *)((char *)materialGlobals + 9628))[hash];
    }
    return NULL;
}

/* line 1437 */
__attribute__((naked))
void Material_Shutdown(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1437 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "calll RB_ReleaseVertexDecl\n" /* line 1381 */
        "movl $materialGlobals+4, -0x1c(%ebp)\n"
        ".Lfd3a6c_000d3a81:\n"
        "movl -0x1c(%ebp), %esi\n"
        "xorl %edi, %edi\n"
        ".Lfd3a6c_000d3a86:\n"
        "leal 8(%esi), %ebx\n" /* line 1437 */
        "movl 8(%esi), %eax\n" /* line 1389 */
        "testl %eax, %eax\n"
        "je .Lfd3a6c_000d3aab\n"
        ".Lfd3a6c_000d3a90:\n"
        "movl (%ebx), %eax\n" /* line 1390 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movl $0, (%ebx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %ecx\n"
        "testl %ecx, %ecx\n"
        "jne .Lfd3a6c_000d3a90\n"
        ".Lfd3a6c_000d3aab:\n"
        "addl $1, %edi\n" /* line 1387 */
        "addl $4, %esi\n"
        "cmpl $4, %edi\n"
        "jne .Lfd3a6c_000d3a86\n"
        "addl $0x18, -0x1c(%ebp)\n" /* line 1393 */
        "cmpl $materialGlobals+772, -0x1c(%ebp)\n" /* line 1385 */
        "jne .Lfd3a6c_000d3a81\n"
        "movl $0x300, 8(%esp)\n" /* line 1420 */
        "movl $0, 4(%esp)\n"
        "movl $materialGlobals+4, (%esp)\n"
        "calll memset\n"
        "movl $0, materialGlobals\n" /* line 1421 */
        "movl $materialGlobals, %ebx\n"
        ".Lfd3a6c_000d3aee:\n"
        "movl 0x259c(%ebx), %eax\n" /* line 838 */
        "testl %eax, %eax\n"
        "je .Lfd3a6c_000d3b03\n"
        "movl 0xc(%eax), %eax\n" /* line 813 */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        ".Lfd3a6c_000d3b03:\n"
        "addl $4, %ebx\n"
        "cmpl $materialGlobals+1024, %ebx\n" /* line 836 */
        "jne .Lfd3a6c_000d3aee\n"
        "movl $materialGlobals, %eax\n"
        ".Lfd3a6c_000d3b13:\n"
        "movl $0, 0x259c(%eax)\n" /* line 869 */
        "addl $4, %eax\n"
        "cmpl %eax, %ebx\n" /* line 864 */
        "jne .Lfd3a6c_000d3b13\n"
        "movl $0, materialGlobals+8972\n" /* line 334 */
        "movl $materialGlobals, %eax\n"
        ".Lfd3a6c_000d3b33:\n"
        "movl 0x2498(%eax), %edx\n" /* line 372 */
        "testl %edx, %edx\n"
        "je .Lfd3a6c_000d3b47\n"
        "movl $0, 0x2498(%eax)\n" /* line 377 */
        ".Lfd3a6c_000d3b47:\n"
        "addl $4, %eax\n"
        "cmpl $materialGlobals+256, %eax\n" /* line 370 */
        "jne .Lfd3a6c_000d3b33\n"
        "movl $materialGlobals, %eax\n"
        ".Lfd3a6c_000d3b56:\n"
        "movl 0x2414(%eax), %edi\n" /* line 736 */
        "testl %edi, %edi\n"
        "je .Lfd3a6c_000d3b6a\n"
        "movl $0, 0x2414(%eax)\n" /* line 739 */
        ".Lfd3a6c_000d3b6a:\n"
        "addl $4, %eax\n"
        "cmpl $materialGlobals+128, %eax\n" /* line 734 */
        "jne .Lfd3a6c_000d3b56\n"
        "movl $materialGlobals, %eax\n"
        "movl $materialGlobals+4096, %ecx\n"
        ".Lfd3a6c_000d3b7e:\n"
        "movl 0x130c(%eax), %esi\n" /* line 608 */
        "testl %esi, %esi\n"
        "je .Lfd3a6c_000d3b92\n"
        "movl $0, 0x130c(%eax)\n" /* line 611 */
        ".Lfd3a6c_000d3b92:\n"
        "addl $4, %eax\n"
        "movl $materialGlobals+4096, %edx\n" /* line 1437 */
        "cmpl %eax, %ecx\n" /* line 606 */
        "jne .Lfd3a6c_000d3b7e\n"
        "movl $materialGlobals, %eax\n"
        ".Lfd3a6c_000d3ba3:\n"
        "movl 0x308(%eax), %ebx\n" /* line 672 */
        "testl %ebx, %ebx\n"
        "je .Lfd3a6c_000d3bb7\n"
        "movl $0, 0x308(%eax)\n" /* line 675 */
        ".Lfd3a6c_000d3bb7:\n"
        "addl $4, %eax\n"
        "cmpl %eax, %edx\n" /* line 670 */
        "jne .Lfd3a6c_000d3ba3\n"
        "movl $0x299c, 8(%esp)\n" /* line 1463 */
        "movl $0, 4(%esp)\n"
        "movl $materialGlobals, (%esp)\n"
        "calll memset\n"
        "movl imp_rg, %eax\n" /* line 1464 */
        "addl $0x28, %eax\n"
        "movl $__mh_execute_header, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memset\n"
        "movl imp_rgp, %eax\n" /* line 1465 */
        "movl $0, 4(%eax)\n"
        "addl $0x2c, %esp\n" /* line 1466 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1134 */
__attribute__((naked))
_ValueType R_RegisterRawImage(const char *name, int baseImageFlags, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1134 */
        "movl %esp, %ebp\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x10, %esp\n"
        "movl 8(%ebp), %esi\n" /* name */
        /* { scope 1 */
        "cmpb $0, (%esi)\n" /* line 1141 | name */
        "jne .Lfd3c0e_000d3c32\n"
        "movl imp_rgp, %eax\n" /* line 1142 */
        "movl 0x102c(%eax), %edx\n"
        /* } scope */
        ".Lfd3c0e_000d3c29:\n"
        "movl %edx, %eax\n" /* line 1146 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd3c0e_000d3c32:\n"
        "movl imp_rgp, %ebx\n" /* line 1081 */
        "movl 0x1030(%ebx), %edx\n"
        "movl 0x102c(%ebx), %ecx\n" /* line 986 */
        "movl 0x3c(%edx), %eax\n"
        "cmpl 0x3c(%ecx), %eax\n"
        "je .Lfd3c0e_000d3c95\n"
        ".Lfd3c0e_000d3c4c:\n"
        "movl 0x1098(%ebx), %eax\n" /* line 1084 */
        "movl %eax, (%esp)\n"
        "calll Image_Release\n"
        "movl 0x10(%ebp), %eax\n" /* line 1086 | imageTrack */
        "movl %eax, 8(%esp)\n"
        "movl %esi, 4(%esp)\n"
        "movl 0x1098(%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Image_LoadRaw\n"
        "testb %al, %al\n"
        "jne .Lfd3c0e_000d3c86\n"
        "movl 0x102c(%ebx), %edx\n" /* line 1087 */
        /* } scope */
        "movl %edx, %eax\n" /* line 1146 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd3c0e_000d3c86:\n"
        "movl 0x1030(%ebx), %edx\n" /* line 1089 */
        /* } scope */
        "movl %edx, %eax\n" /* line 1146 */
        "addl $0x10, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd3c0e_000d3c95:\n"
        "movl 0x40(%edx), %eax\n" /* line 988 */
        "cmpl 0x40(%ecx), %eax\n"
        "jne .Lfd3c0e_000d3c4c\n"
        "movl 0x38(%edx), %eax\n" /* line 990 */
        "cmpl 0x38(%ecx), %eax\n"
        "jne .Lfd3c0e_000d3c4c\n"
        "jmp .Lfd3c0e_000d3c29\n"
    );
}

/* line 1479 */
__attribute__((naked))
void Material_ReloadAll(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1479 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x87c, %esp\n"
        "movl $materialGlobals+4, -0x85c(%ebp)\n"
        "movl $materialGlobals+8, -0x83c(%ebp)\n"
        "movl imp_dx, %eax\n"
        "movl %eax, -0x864(%ebp)\n"
        ".Lfd3ca8_000d3cd3:\n"
        "movl -0x83c(%ebp), %edx\n"
        "subl $4, %edx\n"
        "movl %edx, -0x838(%ebp)\n"
        "movl -0x83c(%ebp), %ecx\n" /* line 1408 */
        "movl -4(%ecx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd3ca8_000d3f4d\n"
        "movl -0x85c(%ebp), %ebx\n"
        "movl %ebx, -0x840(%ebp)\n"
        "movl $0, -0x858(%ebp)\n"
        ".Lfd3ca8_000d3d09:\n"
        "movl -0x858(%ebp), %edx\n" /* line 486 */
        "leal (%edx, %edx, 4), %eax\n"
        "leal s_streamSourceInfo(%edx, %eax, 4), %eax\n"
        "movl %eax, -0x854(%ebp)\n"
        "movl -0x83c(%ebp), %ecx\n"
        "movl (%ecx), %ecx\n"
        "movl %ecx, -0x830(%ebp)\n"
        "movl -0x838(%ebp), %ebx\n"
        "movl (%ebx), %edx\n"
        "movl $0, -0x1c(%ebp)\n" /* line 440 */
        "testl %ecx, %ecx\n" /* line 451 */
        "je .Lfd3ca8_000d3edb\n"
        "movl %eax, %edi\n"
        "movzbl (%edx), %eax\n" /* line 453 */
        "leal (%eax, %eax, 2), %eax\n"
        "addl %eax, %edi\n"
        "cmpb $0xff, (%edi)\n" /* line 454 */
        "je .Lfd3ca8_000d4047\n"
        "leal 2(%edx), %eax\n"
        "movl %eax, -0x860(%ebp)\n"
        "movl %eax, -0x844(%ebp)\n"
        "movl $0, -0x82c(%ebp)\n"
        "movzbl 1(%edx), %eax\n" /* line 456 */
        "leal s_streamDestInfo(%eax, %eax), %eax\n"
        "movl %eax, -0x850(%ebp)\n"
        "movl -0x82c(%ebp), %eax\n" /* line 458 */
        "testl %eax, %eax\n"
        "jle .Lfd3ca8_000d3ec3\n"
        ".Lfd3ca8_000d3d8f:\n"
        "movl -0x82c(%ebp), %ecx\n" /* line 1479 */
        "subl $1, %ecx\n"
        "movzbl (%edi), %edx\n" /* line 458 */
        "movl -0x82c(%ebp), %ebx\n"
        "movzwl -0x824(%ebp, %ebx, 8), %eax\n"
        "cmpl %eax, %edx\n"
        "jae .Lfd3ca8_000d3ece\n"
        "movl %ebx, %esi\n"
        "leal -0x81c(%ebp, %ecx, 8), %eax\n" /* line 1479 */
        "movl %eax, -0x848(%ebp)\n"
        "movl %eax, %ebx\n"
        "jmp .Lfd3ca8_000d3dcc\n"
        ".Lfd3ca8_000d3dc4:\n"
        "movl %ecx, %esi\n" /* line 458 */
        "movl -0x834(%ebp), %ecx\n"
        ".Lfd3ca8_000d3dcc:\n"
        "movl (%ebx), %eax\n" /* line 459 */
        "movl 4(%ebx), %edx\n"
        "movl %eax, -0x81c(%ebp, %esi, 8)\n"
        "movl %edx, -0x818(%ebp, %esi, 8)\n"
        "testl %ecx, %ecx\n" /* line 458 */
        "jle .Lfd3ca8_000d3e0d\n"
        "leal -1(%ecx), %eax\n"
        "movl %eax, -0x834(%ebp)\n"
        "movl -0x82c(%ebp), %edx\n"
        "leal -0x82c(%ebp, %edx, 8), %eax\n"
        "subl -0x848(%ebp), %eax\n"
        "movzwl (%eax, %ebx), %edx\n"
        "subl $8, %ebx\n"
        "movzbl (%edi), %eax\n"
        "cmpl %eax, %edx\n"
        "ja .Lfd3ca8_000d3dc4\n"
        ".Lfd3ca8_000d3e0d:\n"
        "movzbw (%edi), %ax\n" /* line 461 */
        "movw %ax, -0x81c(%ebp, %ecx, 8)\n"
        "movzbw 1(%edi), %ax\n" /* line 462 */
        "movw %ax, -0x81a(%ebp, %ecx, 8)\n"
        "movzbl 2(%edi), %eax\n" /* line 463 */
        "movb %al, -0x818(%ebp, %ecx, 8)\n"
        "movb $0, -0x817(%ebp, %ecx, 8)\n" /* line 464 */
        "movl -0x850(%ebp), %ebx\n" /* line 465 */
        "movzbl (%ebx), %eax\n"
        "movb %al, -0x816(%ebp, %ecx, 8)\n"
        "movzbl 1(%ebx), %eax\n" /* line 466 */
        "movb %al, -0x815(%ebp, %ecx, 8)\n"
        "addl $1, -0x82c(%ebp)\n" /* line 468 */
        "movl -0x860(%ebp), %edx\n" /* line 469 */
        "movl -0x82c(%ebp), %eax\n" /* line 451 */
        "cmpl %eax, -0x830(%ebp)\n"
        "je .Lfd3ca8_000d3ed5\n"
        "movl -0x844(%ebp), %ecx\n" /* line 453 */
        "movzbl (%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x854(%ebp), %edi\n"
        "addl %eax, %edi\n"
        "addl $2, %ecx\n"
        "movl %ecx, -0x844(%ebp)\n"
        "cmpb $0xff, (%edi)\n" /* line 454 */
        "je .Lfd3ca8_000d4047\n"
        "movl -0x860(%ebp), %ebx\n"
        "addl $2, %ebx\n"
        "movl %ebx, -0x860(%ebp)\n"
        "movzbl 1(%edx), %eax\n" /* line 456 */
        "leal s_streamDestInfo(%eax, %eax), %eax\n"
        "movl %eax, -0x850(%ebp)\n"
        "movl -0x82c(%ebp), %eax\n" /* line 458 */
        "testl %eax, %eax\n"
        "jg .Lfd3ca8_000d3d8f\n"
        ".Lfd3ca8_000d3ec3:\n"
        "movl -0x82c(%ebp), %ecx\n"
        "jmp .Lfd3ca8_000d3e0d\n"
        ".Lfd3ca8_000d3ece:\n"
        "movl %ebx, %ecx\n"
        "jmp .Lfd3ca8_000d3e0d\n"
        ".Lfd3ca8_000d3ed5:\n"
        "movl -0x830(%ebp), %ecx\n"
        ".Lfd3ca8_000d3edb:\n"
        "movl declEnd, %eax\n" /* line 472 */
        "movl declEnd+4, %edx\n"
        "movl %eax, -0x81c(%ebp, %ecx, 8)\n"
        "movl %edx, -0x818(%ebp, %ecx, 8)\n"
        ".Lfd3ca8_000d3ef4:\n"
        "movl imp_dx, %ebx\n" /* line 474 */
        "movl 8(%ebx), %eax\n"
        "movl (%eax), %edx\n"
        "leal -0x1c(%ebp), %ecx\n"
        "movl %ecx, 8(%esp)\n"
        "leal -0x81c(%ebp), %ebx\n"
        "movl %ebx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x158(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd3ca8_000d3ef4\n"
        "movl -0x1c(%ebp), %eax\n" /* line 477 */
        ".Lfd3ca8_000d3f27:\n"
        "movl -0x840(%ebp), %edx\n" /* line 486 */
        "movl %eax, 8(%edx)\n"
        "addl $1, -0x858(%ebp)\n" /* line 485 */
        "addl $4, %edx\n"
        "movl %edx, -0x840(%ebp)\n"
        "cmpl $4, -0x858(%ebp)\n"
        "jne .Lfd3ca8_000d3d09\n"
        ".Lfd3ca8_000d3f4d:\n"
        "addl $0x18, -0x85c(%ebp)\n" /* line 1410 */
        "addl $0x18, -0x83c(%ebp)\n"
        "cmpl $materialGlobals+772, -0x85c(%ebp)\n" /* line 1406 */
        "jne .Lfd3ca8_000d3cd3\n"
        "movl $materialGlobals, -0x84c(%ebp)\n"
        "jmp .Lfd3ca8_000d3fb7\n"
        ".Lfd3ca8_000d3f77:\n"
        "movl -0x864(%ebp), %ebx\n" /* line 824 */
        "movl 8(%ebx), %edx\n"
        "movl (%edx), %ecx\n"
        "leal 0xc(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x16c(%ecx)\n"
        "movl %eax, %edi\n"
        "testl %edi, %edi\n" /* line 827 */
        "js .Lfd3ca8_000d3ff5\n"
        ".Lfd3ca8_000d3f9f:\n"
        "addl $4, -0x84c(%ebp)\n" /* line 828 */
        "movl $materialGlobals+1024, %edx\n" /* line 849 */
        "cmpl -0x84c(%ebp), %edx\n"
        "je .Lfd3ca8_000d403c\n"
        ".Lfd3ca8_000d3fb7:\n"
        "movl -0x84c(%ebp), %ecx\n" /* line 851 */
        "movl 0x259c(%ecx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lfd3ca8_000d3f9f\n"
        "cmpb $0, 0xa(%esi)\n" /* line 823 */
        "je .Lfd3ca8_000d3f77\n"
        "movl -0x864(%ebp), %eax\n" /* line 826 */
        "movl 8(%eax), %edx\n"
        "movl (%edx), %ecx\n"
        "leal 0xc(%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll *0x1a8(%ecx)\n"
        "movl %eax, %edi\n"
        "testl %edi, %edi\n" /* line 827 */
        "jns .Lfd3ca8_000d3f9f\n"
        ".Lfd3ca8_000d3ff5:\n"
        "movl imp_ri, %eax\n" /* line 828 */
        "movl 4(%eax), %ebx\n"
        "movl %edi, (%esp)\n"
        "calll R_ErrorDescription\n"
        "movl %edi, 0x10(%esp)\n"
        "movl %eax, 0xc(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00224410, 4(%esp)\n" /* "Couldn't reload shader '%s' when recovering from a lost devi" */
        "movl $0, (%esp)\n"
        "calll *%ebx\n"
        "addl $4, -0x84c(%ebp)\n"
        "movl $materialGlobals+1024, %edx\n" /* line 849 */
        "cmpl -0x84c(%ebp), %edx\n"
        "jne .Lfd3ca8_000d3fb7\n"
        ".Lfd3ca8_000d403c:\n"
        "addl $0x87c, %esp\n" /* line 1485 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd3ca8_000d4047:\n"
        "xorl %eax, %eax\n" /* line 477 */
        "jmp .Lfd3ca8_000d3f27\n"
    );
}

/* line 481 */
__attribute__((naked))
void Load_BuildVertexDecl(MaterialVertexDeclaration * *mtlVertDecl)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 481 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x85c, %esp\n"
        "movl $0, -0x844(%ebp)\n" /* vertDeclType */
        "movl $s_streamSourceInfo, -0x850(%ebp)\n"
        /* { scope 1 */
        ".Lfd404e_000d406e:\n"
        "movl 8(%ebp), %eax\n" /* line 486 | mtlVertDecl */
        "movl (%eax), %eax\n"
        "movl %eax, -0x848(%ebp)\n"
        "movl 4(%eax), %edx\n" /* routingData */
        "movl %edx, -0x83c(%ebp)\n" /* routingData, elemIndexInsert */
        "movl (%eax), %edx\n" /* routingData */
        /* { scope 2: decl, destInfo, elemIndexInsert, elemTable */
        /* { scope 3 */
        "movl $0, -0x1c(%ebp)\n" /* line 440 | decl */
        "movl -0x83c(%ebp), %ecx\n" /* line 451 | elemIndexInsert */
        "testl %ecx, %ecx\n"
        "je .Lfd404e_000d422b\n"
        "movzbl (%edx), %eax\n" /* line 453 */
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x850(%ebp), %edi\n" /* sourceInfo */
        "addl %eax, %edi\n" /* sourceInfo */
        "cmpb $0xff, (%edi)\n" /* line 454 | sourceInfo */
        "je .Lfd404e_000d42b1\n"
        "leal 2(%edx), %ecx\n"
        "movl %ecx, -0x84c(%ebp)\n"
        "movl %ecx, -0x834(%ebp)\n"
        "movl $0, -0x830(%ebp)\n"
        "movzbl 1(%edx), %eax\n" /* line 456 */
        "leal s_streamDestInfo(%eax, %eax), %eax\n"
        "movl %eax, -0x840(%ebp)\n" /* destInfo */
        "movl -0x830(%ebp), %eax\n" /* line 458 */
        "testl %eax, %eax\n"
        "jle .Lfd404e_000d4220\n"
        ".Lfd404e_000d40e8:\n"
        "movl -0x830(%ebp), %ecx\n" /* line 481 */
        "subl $1, %ecx\n"
        "movl -0x830(%ebp), %eax\n" /* line 458 */
        "movzwl -0x824(%ebp, %eax, 8), %edx\n"
        "movzbl (%edi), %eax\n" /* sourceInfo */
        "cmpl %eax, %edx\n"
        "jbe .Lfd404e_000d4220\n"
        "leal -0x81c(%ebp, %ecx, 8), %edx\n" /* line 481 */
        "movl %edx, -0x838(%ebp)\n"
        "movl %edx, %ebx\n"
        "movl -0x830(%ebp), %esi\n"
        "jmp .Lfd404e_000d4129\n"
        ".Lfd404e_000d4121:\n"
        "movl %ecx, %esi\n" /* line 458 */
        "movl -0x82c(%ebp), %ecx\n"
        ".Lfd404e_000d4129:\n"
        "movl (%ebx), %eax\n" /* line 459 */
        "movl 4(%ebx), %edx\n"
        "movl %eax, -0x81c(%ebp, %esi, 8)\n"
        "movl %edx, -0x818(%ebp, %esi, 8)\n"
        "testl %ecx, %ecx\n" /* line 458 */
        "jle .Lfd404e_000d416a\n"
        "leal -1(%ecx), %edx\n"
        "movl %edx, -0x82c(%ebp)\n"
        "movl -0x830(%ebp), %edx\n"
        "leal -0x82c(%ebp, %edx, 8), %eax\n"
        "subl -0x838(%ebp), %eax\n"
        "movzwl (%ebx, %eax), %edx\n"
        "subl $8, %ebx\n"
        "movzbl (%edi), %eax\n" /* sourceInfo */
        "cmpl %edx, %eax\n"
        "jb .Lfd404e_000d4121\n"
        ".Lfd404e_000d416a:\n"
        "movzbw (%edi), %ax\n" /* line 461 | sourceInfo */
        "movw %ax, -0x81c(%ebp, %ecx, 8)\n"
        "movzbw 1(%edi), %ax\n" /* line 462 | sourceInfo */
        "movw %ax, -0x81a(%ebp, %ecx, 8)\n"
        "movzbl 2(%edi), %eax\n" /* line 463 | sourceInfo */
        "movb %al, -0x818(%ebp, %ecx, 8)\n"
        "movb $0, -0x817(%ebp, %ecx, 8)\n" /* line 464 */
        "movl -0x840(%ebp), %edx\n" /* line 465 | destInfo */
        "movzbl (%edx), %eax\n"
        "movb %al, -0x816(%ebp, %ecx, 8)\n"
        "movzbl 1(%edx), %eax\n" /* line 466 */
        "movb %al, -0x815(%ebp, %ecx, 8)\n"
        "addl $1, -0x830(%ebp)\n" /* line 468 */
        "movl -0x84c(%ebp), %edx\n" /* line 469 */
        "movl -0x830(%ebp), %ecx\n" /* line 451 */
        "cmpl %ecx, -0x83c(%ebp)\n" /* elemIndexInsert */
        "je .Lfd404e_000d422b\n"
        "movl -0x834(%ebp), %ecx\n" /* line 453 */
        "movzbl (%ecx), %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl -0x850(%ebp), %edi\n" /* sourceInfo */
        "addl %eax, %edi\n" /* sourceInfo */
        "addl $2, %ecx\n"
        "movl %ecx, -0x834(%ebp)\n"
        "cmpb $0xff, (%edi)\n" /* line 454 | sourceInfo */
        "je .Lfd404e_000d42b1\n"
        "movl -0x84c(%ebp), %eax\n"
        "addl $2, %eax\n"
        "movl %eax, -0x84c(%ebp)\n"
        "movzbl 1(%edx), %eax\n" /* line 456 */
        "leal s_streamDestInfo(%eax, %eax), %eax\n"
        "movl %eax, -0x840(%ebp)\n" /* destInfo */
        "movl -0x830(%ebp), %eax\n" /* line 458 */
        "testl %eax, %eax\n"
        "jg .Lfd404e_000d40e8\n"
        ".Lfd404e_000d4220:\n"
        "movl -0x830(%ebp), %ecx\n"
        "jmp .Lfd404e_000d416a\n"
        ".Lfd404e_000d422b:\n"
        "movl declEnd, %eax\n" /* line 472 */
        "movl declEnd+4, %edx\n"
        "movl -0x83c(%ebp), %ecx\n" /* elemIndexInsert */
        "movl %eax, -0x81c(%ebp, %ecx, 8)\n"
        "movl %edx, -0x818(%ebp, %ecx, 8)\n"
        ".Lfd404e_000d424a:\n"
        "movl imp_dx, %edx\n" /* line 474 */
        "movl 8(%edx), %eax\n"
        "movl (%eax), %edx\n"
        "leal -0x1c(%ebp), %ecx\n" /* decl */
        "movl %ecx, 8(%esp)\n"
        "leal -0x81c(%ebp), %ecx\n" /* elemTable */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll *0x158(%edx)\n"
        "movl imp_alwaysfails, %eax\n"
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd404e_000d424a\n"
        "movl -0x1c(%ebp), %eax\n" /* line 477 | decl */
        /* } scope */
        /* } scope */
        ".Lfd404e_000d427d:\n"
        "movl -0x844(%ebp), %edx\n" /* line 486 | vertDeclType, routingData */
        "movl -0x848(%ebp), %ecx\n"
        "movl %eax, 8(%ecx, %edx, 4)\n"
        "addl $1, %edx\n" /* line 485 */
        "movl %edx, -0x844(%ebp)\n" /* vertDeclType */
        "addl $0x15, -0x850(%ebp)\n"
        "cmpl $4, %edx\n"
        "jne .Lfd404e_000d406e\n"
        /* } scope */
        "addl $0x85c, %esp\n" /* line 487 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: decl, destInfo, elemIndexInsert, elemTable */
        /* { scope 3 */
        ".Lfd404e_000d42b1:\n"
        "xorl %eax, %eax\n" /* line 477 */
        "jmp .Lfd404e_000d427d\n"
    );
}

/* line 1560 */
__attribute__((naked))
void R_Cmd_ReloadMaterialTextures(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1560 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl imp_ri, %ebx\n" /* line 1565 | hashIndex */
        "calll *0x100(%ebx)\n" /* hashIndex */
        "cmpl $2, %eax\n"
        "je .Lfd42b6_000d42e9\n"
        "movl $str_00224460, 4(%esp)\n" /* line 1567 */
        "movl $0, (%esp)\n"
        "calll *(%ebx)\n" /* hashIndex */
        /* } scope */
        ".Lfd42b6_000d42e1:\n"
        "addl $0x2c, %esp\n" /* line 1585 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd42b6_000d42e9:\n"
        "movl $1, (%esp)\n" /* line 1571 */
        "calll *0x104(%ebx)\n" /* hashIndex */
        "movl %eax, %edi\n" /* name */
        /* { scope 2 */
        "movl %eax, (%esp)\n" /* line 385 */
        "calll R_HashAssetName\n"
        "movl %eax, %ebx\n" /* line 1004 */
        "jmp .Lfd42b6_000d4319\n"
        ".Lfd42b6_000d4304:\n"
        "movl %edi, 4(%esp)\n" /* line 1007 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfd42b6_000d435b\n"
        "addl $1, %ebx\n" /* line 1013 */
        ".Lfd42b6_000d4319:\n"
        "andw $0x3ff, %bx\n" /* line 1004 */
        "movzwl %bx, %esi\n" /* line 1005 */
        "movl imp_rg, %edx\n"
        "movl 0x28(%edx, %esi, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd42b6_000d4304\n"
        /* } scope */
        ".Lfd42b6_000d432f:\n"
        "movl imp_ri, %eax\n" /* line 1578 */
        "movl (%eax), %ebx\n" /* hashIndex */
        "movl %edi, 4(%esp)\n" /* name */
        "movl $str_00224490, (%esp)\n" /* "ReloadMaterialTextures: Material '%s' is not currently loade" */
        "calll va\n"
        "movl %eax, 4(%esp)\n"
        "movl $0, (%esp)\n"
        "calll *%ebx\n" /* hashIndex */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1585 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lfd42b6_000d435b:\n"
        "movl imp_rg, %eax\n" /* line 1111 */
        "movl 0x28(%eax, %esi, 4), %esi\n"
        "movl %esi, -0x1c(%ebp)\n" /* material */
        /* } scope */
        "testl %esi, %esi\n" /* line 1576 | maxConvert */
        "je .Lfd42b6_000d432f\n"
        "calll RB_BindDefaultImages\n" /* line 1582 */
        /* { scope 2 */
        "movl -0x1c(%ebp), %edx\n" /* line 1500 | material */
        "movzwl 0x34(%edx), %eax\n"
        "movzwl %ax, %edi\n" /* textureCount */
        "testw %ax, %ax\n" /* line 1509 */
        "je .Lfd42b6_000d42e1\n"
        "xorl %esi, %esi\n" /* maxConvert */
        ".Lfd42b6_000d4385:\n"
        "movl -0x1c(%ebp), %edx\n" /* line 1511 | material */
        "movl 0x3c(%edx), %eax\n"
        "testl %esi, %esi\n" /* maxConvert */
        "je .Lfd42b6_000d43c6\n"
        "movl %eax, %edx\n" /* line 1522 */
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* hashIndex */
        ".Lfd42b6_000d4395:\n"
        "cmpb $5, 5(%edx)\n" /* line 1512 */
        "je .Lfd42b6_000d43a8\n"
        "movl 8(%edx), %eax\n" /* line 1515 */
        "cmpl %eax, %ebx\n" /* line 1516 | hashIndex */
        "jae .Lfd42b6_000d43a8\n"
        "cmpl %eax, %esi\n" /* maxConvert */
        "jbe .Lfd42b6_000d43a8\n"
        "movl %eax, %ebx\n" /* hashIndex */
        ".Lfd42b6_000d43a8:\n"
        "addl $1, %ecx\n" /* line 1509 */
        "addl $0xc, %edx\n"
        "cmpl %ecx, %edi\n" /* textureCount */
        "jne .Lfd42b6_000d4395\n"
        ".Lfd42b6_000d43b2:\n"
        "testl %ebx, %ebx\n" /* line 1521 | hashIndex */
        "je .Lfd42b6_000d42e1\n"
        "movl %ebx, (%esp)\n" /* line 1522 | hashIndex */
        "calll Image_Reload\n"
        "movl %ebx, %esi\n" /* hashIndex, maxConvert */
        "jmp .Lfd42b6_000d4385\n"
        ".Lfd42b6_000d43c6:\n"
        "movl %eax, %edx\n" /* line 1511 */
        "xorl %ecx, %ecx\n"
        "xorl %ebx, %ebx\n" /* hashIndex */
        ".Lfd42b6_000d43cc:\n"
        "cmpb $5, 5(%edx)\n" /* line 1512 */
        "je .Lfd42b6_000d43da\n"
        "movl 8(%edx), %eax\n" /* line 1515 */
        "cmpl %eax, %ebx\n" /* line 1516 | hashIndex */
        "cmovbl %eax, %ebx\n" /* hashIndex */
        ".Lfd42b6_000d43da:\n"
        "addl $1, %ecx\n" /* line 1509 */
        "addl $0xc, %edx\n"
        "cmpl %ecx, %edi\n" /* textureCount */
        "jne .Lfd42b6_000d43cc\n"
        "jmp .Lfd42b6_000d43b2\n"
    );
}

/* line 920 */
__attribute__((naked))
_ValueType Material_Duplicate(_ValueType mtlCopy, const char *name)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 920 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 385 | name */
        "movl %eax, (%esp)\n"
        "calll R_HashAssetName\n"
        "movl %eax, %edi\n" /* line 1004 | hashIndex */
        "andw $0x3ff, %di\n" /* hashIndex */
        "movzwl %di, %esi\n" /* line 1005 | hashIndex */
        "movl imp_rg, %ebx\n" /* nameBackup */
        "movl 0x28(%ebx, %esi, 4), %eax\n" /* nameBackup */
        "testl %eax, %eax\n"
        "je .Lfd43e6_000d443e\n"
        ".Lfd43e6_000d4412:\n"
        "movl 0xc(%ebp), %edx\n" /* line 1007 | name */
        "movl %edx, 4(%esp)\n"
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfd43e6_000d44cd\n"
        "addl $1, %edi\n" /* line 1013 | hashIndex */
        "andw $0x3ff, %di\n" /* hashIndex */
        "movzwl %di, %esi\n" /* line 1005 | hashIndex */
        "movl 0x28(%ebx, %esi, 4), %eax\n" /* nameBackup */
        "testl %eax, %eax\n"
        "jne .Lfd43e6_000d4412\n"
        ".Lfd43e6_000d443e:\n"
        "cld\n" /* line 944 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl 0xc(%ebp), %edi\n" /* name, hashIndex */
        "repne scasb %es:(%edi), %al\n" /* hashIndex */
        "movl %ecx, %ebx\n" /* nameBackup */
        "notl %ebx\n" /* nameBackup */
        "leal 0x44(%ebx), %eax\n" /* line 946 | nameBackup */
        "movl %eax, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *0xc(%eax)\n"
        "movl %eax, %edi\n" /* hashIndex */
        "movl $0x44, 8(%esp)\n" /* line 951 */
        "movl 8(%ebp), %eax\n" /* mtlCopy */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* hashIndex */
        "calll memcpy\n"
        "leal 0x44(%edi), %eax\n" /* line 952 | hashIndex */
        "movl %eax, (%edi)\n" /* hashIndex */
        "movl %ebx, 8(%esp)\n" /* line 955 | nameBackup */
        "movl 0xc(%ebp), %edx\n" /* name */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl imp_rgp, %ecx\n" /* line 907 */
        "movl $1, (%ecx)\n"
        "movw %si, 8(%edi)\n" /* line 910 */
        "movl 4(%ecx), %eax\n" /* line 911 */
        "movw %ax, 0xa(%edi)\n"
        "movl 4(%ecx), %eax\n" /* line 912 */
        "movl %edi, 8(%ecx, %eax, 4)\n"
        "movl imp_rg, %edx\n" /* line 913 */
        "movl %edi, 0x28(%edx, %esi, 4)\n"
        "addl $1, %eax\n" /* line 914 */
        "movl %eax, 4(%ecx)\n"
        "cmpl $0x400, %eax\n" /* line 915 */
        "je .Lfd43e6_000d4501\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 961 | hashIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd43e6_000d44cd:\n"
        "movl 0x28(%ebx, %esi, 4), %edi\n" /* line 934 | nameBackup, hashIndex */
        "movl (%edi), %ebx\n" /* line 935 | hashIndex, nameBackup */
        "movl $0x44, 8(%esp)\n" /* line 936 */
        "movl 8(%ebp), %eax\n" /* mtlCopy */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* hashIndex */
        "calll memcpy\n"
        "movl %ebx, (%edi)\n" /* line 937 | nameBackup, hashIndex */
        "movl imp_rgp, %eax\n" /* line 939 */
        "movl $1, (%eax)\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 961 | hashIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd43e6_000d4501:\n"
        "movl $0x400, 8(%esp)\n" /* line 916 */
        "movl $str_002244d0, 4(%esp)\n" /* "Too many unique materials (%i or more)
" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 961 | hashIndex */
        "addl $0x1c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1019 */
__attribute__((naked))
MaterialHandle Material_Register(const char *name, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1019 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 8(%ebp), %edi\n" /* name */
        "movl 0xc(%ebp), %eax\n" /* imageTrack */
        "movl %eax, -0x1c(%ebp)\n" /* imageTrack */
        /* { scope 1 */
        "movl %edi, (%esp)\n" /* line 385 */
        "calll R_HashAssetName\n"
        "movl %eax, %ebx\n" /* line 1004 */
        "andw $0x3ff, %bx\n"
        "movzwl %bx, %esi\n" /* line 1005 */
        "movl imp_rg, %edx\n"
        "movl 0x28(%edx, %esi, 4), %eax\n"
        "testl %eax, %eax\n"
        "je .Lfd4528_000d4585\n"
        ".Lfd4528_000d455a:\n"
        "movl %edi, 4(%esp)\n" /* line 1007 */
        "movl (%eax), %eax\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lfd4528_000d45d9\n"
        "addl $1, %ebx\n" /* line 1013 */
        "andw $0x3ff, %bx\n" /* line 1004 */
        "movzwl %bx, %esi\n" /* line 1005 */
        "movl imp_rg, %edx\n"
        "movl 0x28(%edx, %esi, 4), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd4528_000d455a\n"
        ".Lfd4528_000d4585:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1032 | imageTrack */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* name */
        "calll Material_Load\n"
        "movl %eax, %ebx\n" /* hashIndex */
        "testl %eax, %eax\n" /* line 1033 */
        "je .Lfd4528_000d4613\n"
        "movl imp_rgp, %ecx\n" /* line 907 */
        "movl $1, (%ecx)\n"
        "movw %si, 8(%eax)\n" /* line 910 */
        "movl 4(%ecx), %eax\n" /* line 911 */
        "movw %ax, 0xa(%ebx)\n"
        "movl 4(%ecx), %eax\n" /* line 912 */
        "movl %ebx, 8(%ecx, %eax, 4)\n"
        "movl imp_rg, %edx\n" /* line 913 */
        "movl %ebx, 0x28(%edx, %esi, 4)\n"
        "addl $1, %eax\n" /* line 914 */
        "movl %eax, 4(%ecx)\n"
        "cmpl $0x400, %eax\n" /* line 915 */
        "je .Lfd4528_000d45ed\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1038 | hashIndex */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd4528_000d45d9:\n"
        "movl imp_rg, %edx\n" /* line 1030 */
        "movl 0x28(%edx, %esi, 4), %ebx\n" /* hashIndex */
        /* } scope */
        "movl %ebx, %eax\n" /* line 1038 | hashIndex */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd4528_000d45ed:\n"
        "movl $0x400, 8(%esp)\n" /* line 916 */
        "movl $str_002244d0, 4(%esp)\n" /* "Too many unique materials (%i or more)
" */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        /* } scope */
        "movl %ebx, %eax\n" /* line 1038 | hashIndex */
        "addl $0x2c, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lfd4528_000d4613:\n"
        "movl imp_rgp, %ebx\n" /* line 968 */
        "movl 0x102c(%ebx), %esi\n"
        "testl %esi, %esi\n"
        "je .Lfd4528_000d464b\n"
        ".Lfd4528_000d4623:\n"
        "movl %edi, 4(%esp)\n" /* line 974 */
        "movl $str_0022451c, (%esp)\n" /* "^3WARNING: Could not find material '%s'
" */
        "calll Com_Printf\n"
        "movl %edi, 0xc(%ebp)\n" /* line 975 | imageTrack */
        "movl 0x102c(%ebx), %eax\n"
        "movl %eax, 8(%ebp)\n" /* name */
        /* } scope */
        "addl $0x2c, %esp\n" /* line 1038 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        /* { scope 1 */
        "jmp Material_Duplicate\n" /* line 975 */
        ".Lfd4528_000d464b:\n"
        "movl $str_002244f8, 4(%esp)\n" /* line 971 */
        "movl $0, (%esp)\n"
        "calll R_Error\n"
        "jmp .Lfd4528_000d4623\n"
    );
}

/* line 1119 */
MaterialHandle Material_RegisterHandle(const char *name, int baseImageFlags, int imageTrack)
{
    if (*name == '\0')
        return rgp.defaultMaterial;
    return Material_Register(name, imageTrack);
}

/* line 1345 */
__attribute__((naked))
void Material_Init(void)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1345 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1c, %esp\n"
        "movl $0x299c, 8(%esp)\n" /* line 1348 */
        "movl $0, 4(%esp)\n"
        "movl $materialGlobals, (%esp)\n"
        "calll memset\n"
        "calll Material_PreLoadAllShaderText\n" /* line 1349 */
        "movl $s_builtInMaterials+4, %esi\n"
        "movl $RB_RenderCommandTable+4, %edi\n"
        "jmp .Lfd4686_000d46c3\n"
        ".Lfd4686_000d46bc:\n"
        "addl $8, %esi\n" /* line 1325 */
        "cmpl %esi, %edi\n" /* line 1320 */
        "je .Lfd4686_000d4704\n"
        ".Lfd4686_000d46c3:\n"
        "movl (%esi), %ebx\n" /* line 1323 */
        "movl $0, 4(%esp)\n"
        "movl -4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_Register\n"
        "movl %eax, (%ebx)\n"
        "movl (%esi), %eax\n" /* line 1324 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd4686_000d46bc\n"
        "movl -4(%esi), %eax\n" /* line 1325 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224548, 4(%esp)\n" /* "Could not find material '%s'" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "addl $8, %esi\n"
        "cmpl %esi, %edi\n" /* line 1320 */
        "jne .Lfd4686_000d46c3\n"
        ".Lfd4686_000d4704:\n"
        "movl imp_r_testFillEnable, %eax\n" /* line 1353 */
        "movl (%eax), %eax\n"
        "cmpb $0, 8(%eax)\n"
        "jne .Lfd4686_000d47cf\n"
        ".Lfd4686_000d4715:\n"
        "movl $0, 4(%esp)\n" /* line 1062 */
        "movl $str_00224568, (%esp)\n" /* "$raw" */
        "calll Material_Register\n"
        "movl %eax, %edx\n"
        "movl imp_rgp, %esi\n"
        "movl %eax, 0x1030(%esi)\n"
        "movl 0x102c(%esi), %ecx\n" /* line 986 */
        "movl 0x3c(%eax), %eax\n"
        "cmpl 0x3c(%ecx), %eax\n"
        "je .Lfd4686_000d479b\n"
        ".Lfd4686_000d4745:\n"
        "cmpw $1, 0x34(%edx)\n" /* line 1066 */
        "je .Lfd4686_000d47ab\n"
        "movl $str_00224570, 4(%esp)\n" /* line 1068 */
        "movl $3, (%esp)\n"
        "movl imp_ri, %eax\n"
        "calll *(%eax)\n"
        "movl imp_rgp, %esi\n" /* line 1069 */
        "movl 0x102c(%esi), %eax\n"
        "movl %eax, 0x1030(%esi)\n"
        "movl %eax, %ecx\n"
        "movl %eax, %edx\n"
        "movl 0x3c(%ecx), %ebx\n" /* line 986 */
        "cmpl 0x3c(%edx), %ebx\n"
        "je .Lfd4686_000d47bf\n"
        ".Lfd4686_000d4780:\n"
        "movl %ecx, %edx\n"
        ".Lfd4686_000d4782:\n"
        "movl (%ebx), %eax\n" /* line 1339 */
        "movl %eax, 0x10e4(%esi)\n"
        "leal 0x10e4(%esi), %eax\n" /* line 1340 */
        "movl %eax, 0x3c(%edx)\n"
        ".Lfd4686_000d4793:\n"
        "addl $0x1c, %esp\n" /* line 1363 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        ".Lfd4686_000d479b:\n"
        "movl 0x40(%edx), %eax\n" /* line 988 */
        "cmpl 0x40(%ecx), %eax\n"
        "jne .Lfd4686_000d4745\n"
        "movl 0x38(%edx), %eax\n" /* line 990 */
        "cmpl 0x38(%ecx), %eax\n"
        "jne .Lfd4686_000d4745\n"
        ".Lfd4686_000d47ab:\n"
        "movl 0x1030(%esi), %ecx\n"
        "movl 0x102c(%esi), %edx\n"
        "movl 0x3c(%ecx), %ebx\n" /* line 986 */
        "cmpl 0x3c(%edx), %ebx\n"
        "jne .Lfd4686_000d4780\n"
        ".Lfd4686_000d47bf:\n"
        "movl 0x40(%ecx), %eax\n" /* line 988 */
        "cmpl 0x40(%edx), %eax\n"
        "je .Lfd4686_000d4822\n"
        ".Lfd4686_000d47c7:\n"
        "movl 0x1030(%esi), %edx\n"
        "jmp .Lfd4686_000d4782\n"
        ".Lfd4686_000d47cf:\n"
        "movl $s_fillTestMaterials+4, %esi\n" /* line 1353 */
        "movl $s_builtInMaterials+4, %edi\n"
        "jmp .Lfd4686_000d47e6\n"
        ".Lfd4686_000d47db:\n"
        "addl $8, %esi\n" /* line 1325 */
        "cmpl %esi, %edi\n" /* line 1320 */
        "je .Lfd4686_000d4715\n"
        ".Lfd4686_000d47e6:\n"
        "movl (%esi), %ebx\n" /* line 1323 */
        "movl $0, 4(%esp)\n"
        "movl -4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_Register\n"
        "movl %eax, (%ebx)\n"
        "movl (%esi), %eax\n" /* line 1324 */
        "movl (%eax), %eax\n"
        "testl %eax, %eax\n"
        "jne .Lfd4686_000d47db\n"
        "movl -4(%esi), %eax\n" /* line 1325 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00224548, 4(%esp)\n" /* "Could not find material '%s'" */
        "movl $0, (%esp)\n"
        "calll Com_Error\n"
        "jmp .Lfd4686_000d47db\n"
        ".Lfd4686_000d4822:\n"
        "movl 0x38(%ecx), %eax\n" /* line 990 */
        "cmpl 0x38(%edx), %eax\n"
        "jne .Lfd4686_000d47c7\n"
        "jmp .Lfd4686_000d4793\n"
    );
}

/* line 273 */
__attribute__((naked))
void ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_(void) /* void std___adjust_heap<Material**, int, Material*, unsigned char (*)(Material const*, Material const*)> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 276 | __holeIndex */
        "leal 2(%eax, %eax), %ebx\n" /* __secondChild */
        "cmpl 0x10(%ebp), %ebx\n" /* line 277 | __len, __secondChild */
        "jl .Lf2bf8e2_002bf965\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %esi\n"
        "movl %eax, %edi\n"
        ".Lf2bf8e2_002bf8ff:\n"
        "cmpl %ebx, 0x10(%ebp)\n" /* line 286 | __secondChild, __len */
        "je .Lf2bf8e2_002bf9b7\n"
        ".Lf2bf8e2_002bf908:\n"
        "leal -1(%edi), %edx\n" /* line 165 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ebx\n"
        "sarl $1, %ebx\n"
        "cmpl 0xc(%ebp), %edi\n" /* line 166 | __holeIndex */
        "jg .Lf2bf8e2_002bf944\n"
        ".Lf2bf8e2_002bf91a:\n"
        "movl 0x14(%ebp), %eax\n" /* line 173 | __value */
        "movl %eax, (%esi)\n"
        /* } scope */
        "addl $0x2c, %esp\n" /* line 291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bf8e2_002bf927:\n"
        "movl (%esi), %eax\n" /* line 169 */
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %eax, (%edx, %edi, 4)\n"
        "leal -1(%ebx), %edx\n" /* line 171 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl 0xc(%ebp), %ebx\n" /* line 166 | __holeIndex */
        "jle .Lf2bf8e2_002bf91a\n"
        "movl %ebx, %edi\n"
        "movl %eax, %ebx\n"
        ".Lf2bf8e2_002bf944:\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "leal (%eax, %ebx, 4), %esi\n"
        "movl 0x14(%ebp), %edx\n" /* __value */
        "movl %edx, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf8e2_002bf927\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%ecx, %edi, 4), %esi\n"
        "jmp .Lf2bf8e2_002bf91a\n"
        ".Lf2bf8e2_002bf965:\n"
        "movl %eax, -0x1c(%ebp)\n" /* line 277 */
        "movl %ebx, %edi\n" /* __secondChild */
        "jmp .Lf2bf8e2_002bf98f\n"
        ".Lf2bf8e2_002bf96c:\n"
        "leal -1(%ebx), %edi\n" /* line 281 | __secondChild */
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%ecx, %edi, 4), %esi\n"
        ".Lf2bf8e2_002bf975:\n"
        "movl (%esi), %eax\n" /* line 282 */
        "movl -0x1c(%ebp), %edx\n"
        "movl %eax, (%ecx, %edx, 4)\n"
        "leal 2(%edi, %edi), %ebx\n" /* line 284 | __secondChild */
        "cmpl %ebx, 0x10(%ebp)\n" /* line 277 | __secondChild, __len */
        "jle .Lf2bf8e2_002bf8ff\n"
        "movl %edi, -0x1c(%ebp)\n"
        "movl %ebx, %edi\n" /* __secondChild */
        ".Lf2bf8e2_002bf98f:\n"
        "leal (, %ebx, 4), %eax\n" /* line 279 */
        "movl 8(%ebp), %esi\n" /* __first */
        "addl %eax, %esi\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl -4(%edx, %eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x18(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf8e2_002bf96c\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "jmp .Lf2bf8e2_002bf975\n"
        ".Lf2bf8e2_002bf9b7:\n"
        "movl 0x10(%ebp), %edx\n" /* line 288 | __len */
        "movl 8(%ebp), %ecx\n" /* __first */
        "movl -4(%ecx, %edx, 4), %eax\n"
        "movl %eax, (%esi)\n"
        "movl %edx, %edi\n" /* line 289 */
        "subl $1, %edi\n"
        "leal (%ecx, %edi, 4), %esi\n"
        "jmp .Lf2bf8e2_002bf908\n"
    );
}

/* line 2152 */
__attribute__((naked))
void ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_(void) /* void std___insertion_sort<Material**, unsigned char (*)(Material const*, Material const*)> */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2152 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x2c, %esp\n"
        "movl 0xc(%ebp), %eax\n" /* line 2154 | __last */
        "cmpl %eax, 8(%ebp)\n" /* __first */
        "je .Lf2bf9d0_002bfa35\n"
        /* { scope 1 */
        "movl 8(%ebp), %edx\n" /* line 2156 | __first */
        "addl $4, %edx\n"
        "movl %edx, -0x1c(%ebp)\n" /* __i */
        "cmpl %edx, %eax\n"
        "je .Lf2bf9d0_002bfa35\n"
        /* { scope 2 */
        ".Lf2bf9d0_002bf9ee:\n"
        "movl (%edx), %edi\n" /* line 2159 | __val */
        "movl 8(%ebp), %edx\n" /* line 2160 | __first */
        "movl (%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* __val */
        "calll *0x10(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf9d0_002bfa3d\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 2107 | __i */
        "subl $4, %ebx\n"
        "movl -0x1c(%ebp), %esi\n" /* __i */
        "jmp .Lf2bf9d0_002bfa17\n"
        ".Lf2bf9d0_002bfa0e:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%esi)\n"
        "movl %ebx, %esi\n" /* line 2112 */
        "subl $4, %ebx\n"
        ".Lf2bf9d0_002bfa17:\n"
        "movl (%ebx), %eax\n" /* line 2108 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x10(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bf9d0_002bfa0e\n"
        "movl %edi, (%esi)\n" /* line 2114 */
        "addl $4, -0x1c(%ebp)\n" /* __i */
        "movl -0x1c(%ebp), %edx\n" /* __i */
        /* } scope */
        ".Lf2bf9d0_002bfa30:\n"
        "cmpl %edx, 0xc(%ebp)\n" /* line 2156 | __last */
        "jne .Lf2bf9d0_002bf9ee\n"
        /* } scope */
        ".Lf2bf9d0_002bfa35:\n"
        "addl $0x2c, %esp\n" /* line 2166 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2 */
        ".Lf2bf9d0_002bfa3d:\n"
        "movl -0x1c(%ebp), %ebx\n" /* line 2162 | __i */
        "addl $4, %ebx\n"
        /* { scope 3 */
        "movl -0x1c(%ebp), %eax\n" /* line 424 | __i */
        "subl 8(%ebp), %eax\n" /* __first */
        "andl $0xfffffffc, %eax\n" /* line 425 */
        "movl %eax, 8(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, 4(%esp)\n"
        "movl %ebx, %edx\n"
        "subl %eax, %edx\n"
        "movl %edx, (%esp)\n"
        "calll memmove\n"
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 2163 | __first */
        "movl %edi, (%eax)\n" /* __val */
        "movl %ebx, -0x1c(%ebp)\n" /* __i */
        "movl %ebx, %edx\n"
        "jmp .Lf2bf9d0_002bfa30\n"
    );
}

/* line 2514 */
__attribute__((naked))
void ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_(void) /* void std___introsort_loop<Material**, int, unsigned char (*)(Material const*, Material const*)> */
{
    __asm__ __volatile__ (
        ".Lf2bfa70_002bfa70:\n"
        "pushl %ebp\n" /* line 2514 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x4c, %esp\n"
        /* { scope 1 */
        "movl 0xc(%ebp), %eax\n" /* line 2519 | __last */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0x43, %eax\n"
        "jle .Lf2bfa70_002bfb44\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 2521 | __depth_limit */
        "testl %edx, %edx\n"
        "jne .Lf2bfa70_002bfb4c\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf2bfa70_002bfa93:\n"
        "cmpl $7, %eax\n" /* line 397 */
        "jle .Lf2bfa70_002bfb44\n"
        "sarl $2, %eax\n" /* line 400 */
        "movl %eax, -0x24(%ebp)\n"
        "movl %eax, %edx\n" /* line 2514 */
        "subl $2, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %esi\n"
        "sarl $1, %esi\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "leal (%edi, %esi, 4), %ebx\n"
        "xorl %edi, %edi\n"
        "jmp .Lf2bfa70_002bfabe\n"
        ".Lf2bfa70_002bfabb:\n"
        "addl $1, %edi\n" /* line 406 */
        ".Lf2bfa70_002bfabe:\n"
        "movl 0x14(%ebp), %eax\n" /* line 404 | __comp */
        "movl %eax, 0x10(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl -0x24(%ebp), %edx\n"
        "movl %edx, 8(%esp)\n"
        "movl %esi, %eax\n"
        "subl %edi, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, (%esp)\n"
        "calll ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_\n"
        "subl $4, %ebx\n"
        "cmpl %esi, %edi\n" /* line 406 */
        "jne .Lf2bfa70_002bfabb\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %ecx\n" /* line 2521 | __last */
        "movl %ecx, %edi\n" /* line 2514 */
        "subl 8(%ebp), %edi\n" /* __first */
        "movl %edi, -0x2c(%ebp)\n"
        "movl %edi, %esi\n"
        "subl $4, %esi\n"
        ".Lf2bfa70_002bfafc:\n"
        "leal -4(%ecx), %ebx\n"
        /* { scope 3 */
        "movl -4(%ecx), %edx\n" /* line 330 | __value */
        /* { scope 4 */
        /* { scope 5 */
        "movl 8(%ebp), %edi\n" /* line 301 | __first */
        "movl (%edi), %eax\n"
        "movl %eax, -4(%ecx)\n"
        "movl 0x14(%ebp), %eax\n" /* line 302 | __comp */
        "movl %eax, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, %eax\n"
        "sarl $2, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_\n"
        "movl %ebx, %ecx\n"
        "subl $4, %esi\n"
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 457 */
        "subl 0xc(%ebp), %eax\n" /* __last */
        "addl -0x2c(%ebp), %eax\n"
        "leal 4(%eax, %esi), %eax\n"
        "cmpl $7, %eax\n"
        "jg .Lf2bfa70_002bfafc\n"
        /* } scope */
        /* } scope */
        ".Lf2bfa70_002bfb44:\n"
        "addl $0x4c, %esp\n" /* line 2538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf2bfa70_002bfb4c:\n"
        "movl 0x10(%ebp), %edx\n" /* line 457 | __depth_limit */
        "movl %edx, -0x1c(%ebp)\n"
        "movl $0, -0x20(%ebp)\n"
        "movl 0xc(%ebp), %esi\n" /* __last */
        ".Lf2bfa70_002bfb5c:\n"
        "subl $1, -0x1c(%ebp)\n" /* line 2526 */
        "movl %eax, %edx\n"
        "sarl $2, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl 8(%ebp), %edi\n" /* __first */
        "leal (%edi, %eax, 4), %ebx\n"
        "subl $4, %esi\n"
        /* { scope 2 */
        "movl (%ebx), %eax\n" /* line 124 */
        "movl %eax, 4(%esp)\n"
        "movl (%edi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bfa70_002bfc55\n"
        "movl 0xc(%ebp), %edx\n" /* line 125 | __last */
        "movl -4(%edx), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bfa70_002bfbf4\n"
        ".Lf2bfa70_002bfba3:\n"
        "movl %ebx, %esi\n" /* line 133 */
        /* } scope */
        ".Lf2bfa70_002bfba5:\n"
        "movl (%esi), %edi\n" /* line 2536 | __b, __pivot */
        "movl 8(%ebp), %esi\n" /* __first, __b */
        "movl 0xc(%ebp), %ebx\n" /* __last */
        /* { scope 2 */
        ".Lf2bfa70_002bfbad:\n"
        "movl %edi, 4(%esp)\n" /* line 2056 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bfa70_002bfbef\n"
        ".Lf2bfa70_002bfbbd:\n"
        "subl $4, %ebx\n" /* line 2060 */
        "movl (%ebx), %eax\n" /* line 2059 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bfa70_002bfbbd\n"
        "cmpl %ebx, %esi\n" /* line 2061 */
        "jae .Lf2bfa70_002bfc12\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl (%esi), %edx\n" /* line 97 | __tmp */
        "movl (%ebx), %eax\n" /* line 98 */
        "movl %eax, (%esi)\n"
        "movl %edx, (%ebx)\n" /* line 99 */
        /* } scope */
        /* } scope */
        "addl $4, %esi\n" /* line 2064 */
        "movl %edi, 4(%esp)\n" /* line 2056 */
        "movl (%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2bfa70_002bfbbd\n"
        ".Lf2bfa70_002bfbef:\n"
        "addl $4, %esi\n" /* line 2057 */
        "jmp .Lf2bfa70_002bfbad\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2bfa70_002bfbf4:\n"
        "movl 0xc(%ebp), %edi\n" /* line 127 | __last */
        "movl -4(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bfa70_002bfba5\n"
        ".Lf2bfa70_002bfc0d:\n"
        "movl 8(%ebp), %esi\n" /* line 133 | __first */
        "jmp .Lf2bfa70_002bfba5\n"
        /* } scope */
        ".Lf2bfa70_002bfc12:\n"
        "movl 0x14(%ebp), %edi\n" /* line 2537 | __comp, __pivot */
        "movl %edi, 0xc(%esp)\n" /* __pivot */
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __last */
        "movl %edx, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* __b */
        "calll ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_\n"
        /* } scope */
        "movl %esi, %eax\n" /* line 2519 */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0x43, %eax\n"
        "jle .Lf2bfa70_002bfb44\n"
        "addl $1, -0x20(%ebp)\n"
        "movl %esi, 0xc(%ebp)\n" /* __last */
        /* { scope 1 */
        "movl -0x20(%ebp), %edx\n" /* line 2521 */
        "cmpl %edx, 0x10(%ebp)\n" /* __depth_limit */
        "jne .Lf2bfa70_002bfb5c\n"
        "jmp .Lf2bfa70_002bfa93\n"
        /* { scope 2 */
        ".Lf2bfa70_002bfc55:\n"
        "movl 0xc(%ebp), %edi\n" /* line 131 | __last */
        "movl -4(%edi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl (%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bfa70_002bfc0d\n"
        "movl -4(%edi), %eax\n" /* line 133 */
        "movl %eax, 4(%esp)\n"
        "movl (%ebx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2bfa70_002bfba5\n"
        "jmp .Lf2bfa70_002bfba3\n"
    );
}

