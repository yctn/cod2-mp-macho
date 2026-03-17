/* ASM dump from: r_material.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_material.cpp */

#include "common_types.h"
#include "imports.h"
#include <string.h>

extern void Com_Printf(const char *fmt, ...);
extern void Com_sprintf(char *dest, int size, const char *fmt, ...);
extern const char *R_ErrorDescription(int hr);

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
#ifndef __EMSCRIPTEN__
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
    /* end-of-builtInMaterials sentinel — loop terminator for Material_Init */
    ".globl s_builtInMaterials_end\n"
    "s_builtInMaterials_end:\n"
    ".previous\n"
);
#endif

extern int R_HashAssetName(const char *name);
extern int stricmp(const char *s1, const char *s2);
extern void R_SetPicmip(void);
extern void Image_UpdatePicmip(GfxImage *image);
extern void Image_Release(GfxImage *image);
extern void Image_Reload(GfxImage *image);
extern Bool Image_LoadRaw(GfxImage *image, const char *filepath, int imageTrack);
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
typedef unsigned char (*MaterialCompFunc)(const Material *, const Material *);
void ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_(Material **first, int holeIndex, int len, Material *value, MaterialCompFunc comp);
void ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_(Material **first, Material **last, MaterialCompFunc comp);
void ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_(Material **first, Material **last, int depth_limit, MaterialCompFunc comp);

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
    const Material *defaultMtl = *(const Material **)((byte *)imp_rgp + 0x102c);
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
    if (*(int *)((byte *)(*(int *)imp_r_rendererInUse) + 8) == 2)
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
extern void RB_ReleaseVertexDecl(void);

void Material_ReleaseAll(void)
{
    byte *outer;
    int j;
    void *obj;
    void **vtable;
    int i;

    RB_ReleaseVertexDecl();

    /* Release technique COM objects — skip vtable Release on Linux (no real COM) */
    for (outer = materialGlobals + 4; outer < materialGlobals + 772; outer += 24) {
        byte *slot = outer;
        for (j = 0; j < 4; j++) {
            void **pObj = (void **)(slot + 8);
            *pObj = NULL;
            slot += 4;
        }
    }

    /* Release shader COM objects — skip vtable Release on Linux (no real COM) */
}

/* line 1538 */
void Material_UpdatePicmipAll(void)
{
    byte *rg = (byte *)imp_rg;
    byte *slot;
    byte *rgEnd;
    int textureIndex, textureCount;
    byte *material;
    byte *texdef;
    byte *texdefs;
    GfxImage *image;

    R_SetPicmip();

    /* Iterate all material slots in rg (0x1000 byte stride, pointer at offset 0x28) */
    rgEnd = rg + 0x1000;
    for (slot = rg; slot < rgEnd; slot += 4) {
        material = *(byte **)(slot + 0x28);
        if (!material)
            continue;

        textureCount = *(unsigned short *)(material + 0x34);
        if (textureCount <= 0)
            continue;

        texdefs = *(byte **)(material + 0x3c);
        for (textureIndex = 0; textureIndex < textureCount; textureIndex++) {
            texdef = texdefs + textureIndex * 0xc;

            /* Skip water textures (semantic == 5) */
            if (*(byte *)(texdef + 5) == 5)
                continue;

            image = *(GfxImage **)(texdef + 8);
            if (!image)
                continue;

            Image_UpdatePicmip(image);
            /* Re-read count since UpdatePicmip may have side effects */
            textureCount = *(unsigned short *)(material + 0x34);
        }
    }
}

/* line 1588 */
extern int FS_FOpenFileRead(const char *filename, int *file, int uniqueFILE);
int Material_LoadFile(const char *filename, int *file)
{
    char fullFilename[64];
    Com_sprintf(fullFilename, 64, "materials/%s", filename);
    return FS_FOpenFileRead(fullFilename, file, 1);
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
/* line 876 — Sort the material pointer array using introsort + insertion sort,
 * then update each material's sortKey index. */
void Material_Sort(void)
{
    typedef void (*introsort_fn)(const Material **, const Material **, int, Bool (*)(const Material *, const Material *));
    typedef void (*insertion_sort_fn)(const Material **, const Material **, Bool (*)(const Material *, const Material *));

    char *rgp = (char *)imp_rgp;
    int count = *(int *)(rgp + 4);
    const Material **first = (const Material **)(rgp + 8);
    const Material **last = first + count;
    int i;

    if (first != last) {
        int n = count;
        int byteRange = (int)((byte *)last - (byte *)first);
        int depthLimit = 0;

        /* Compute introsort depth limit: 2 * floor(log2(n)) */
        if (n > 1) {
            int tmp = n;
            while (tmp > 1) {
                depthLimit++;
                tmp >>= 1;
            }
            depthLimit *= 2;
        }

        /* Phase 1: introsort partitioning */
        ((introsort_fn)ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_)(
            first, last, depthLimit, Material_Compare);

        /* Phase 2: insertion sort for final ordering */
        if (byteRange <= 0x43) {
            /* Small range: insertion sort the whole thing */
            ((insertion_sort_fn)ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_)(
                first, last, Material_Compare);
        } else {
            /* Large range: insertion sort first 18 elements, then rest */
            const Material **mid = (const Material **)((byte *)first + 0x48);
            ((insertion_sort_fn)ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_)(
                first, mid, Material_Compare);

            /* Unguarded insertion sort for remaining elements */
            while (mid != last) {
                const Material *val = *mid;
                const Material **hole = mid;
                const Material **prev = mid - 1;
                while (Material_Compare(val, *prev)) {
                    *hole = *prev;
                    hole = prev;
                    prev--;
                }
                *hole = val;
                mid++;
            }
        }
    }

    /* Update sortKey index for each material */
    rgp = (char *)imp_rgp;
    count = *(int *)(rgp + 4);
    for (i = 0; i < count; i++) {
        byte *mtl = *(byte **)(rgp + 8 + i * 4);
        *(unsigned short *)(mtl + 0xa) = (unsigned short)i;
    }
}

/* line 338 */
extern int R_HashString(const char *string);
extern void R_Error(int level, const char *msg, ...);

const char * Material_RegisterString(const char *string)
{
    int hash = R_HashString(string) & 0x3f;
    const char *existing;
    int count;
    int nameLen;
    void *(*hunkAlloc)(int);
    char *copy;

    /* Search hash table for existing string */
    existing = *(const char **)(materialGlobals + 9368 + hash * 4);
    while (existing) {
        if (strcmp(existing, string) == 0)
            return existing;
        hash = (hash + 1) & 0x3f;
        existing = *(const char **)(materialGlobals + 9368 + hash * 4);
    }

    /* Not found — register new string */
    count = *(int *)(materialGlobals + 9364) + 1;
    *(int *)(materialGlobals + 9364) = count;
    if (count == 64) {
        R_Error(1, "More than %i string identifiers used by shaders", 63);
    }

    /* Allocate and copy string via ri->hunkAlloc */
    nameLen = strlen(string) + 1;
    hunkAlloc = *(void *(**)(int))((byte *)imp_ri + 0xc);
    copy = (char *)hunkAlloc(nameLen);
    memcpy(copy, string, nameLen);

    /* Insert into hash table */
    *(const char **)(materialGlobals + 9368 + hash * 4) = copy;

    return copy;
}

/* line 492 */
MaterialVertexDeclaration * Material_AllocVertexDecl(MaterialStreamRouting *routingData, int streamCount, Bool *existing)
{
    int dataSize = streamCount * 2; /* each stream routing is 2 bytes */
    int hash = 0;
    int i;
    byte *routingBytes = (byte *)routingData;
    byte *mvd; /* MaterialVertexDeclaration pointer */
    byte *data;
    void *(*hunkAlloc)(int);

    /* Compute hash over routing data bytes */
    for (i = 0; i < dataSize; i++) {
        hash += (i + 0x77) * routingBytes[i];
    }
    hash &= 0x1f;

    /* Search hash table for existing match (24-byte entries in materialGlobals) */
    for (;;) {
        mvd = (byte *)&materialGlobals[hash * 6 + 1]; /* materialGlobals + hash*24 + 4 */
        data = *(byte **)mvd;

        if (!data)
            break; /* empty slot — need to allocate */

        /* Check streamCount and data match */
        if (*(int *)(mvd + 4) == streamCount &&
            memcmp(data, routingData, dataSize) == 0) {
            *existing = 1;
            return (MaterialVertexDeclaration *)mvd;
        }

        hash = (hash + 1) & 0x1f;
    }

    /* Allocate new entry */
    if (*(int *)materialGlobals == 0x1f) {
        R_Error(1, "More than %i vertex declarations in use", 31);
    }
    (*(int *)materialGlobals)++;

    hunkAlloc = *(void *(**)(int))((byte *)imp_ri + 0xc);
    data = (byte *)hunkAlloc(dataSize);
    memcpy(data, routingData, dataSize);

    /* Zero the mvd struct (24 bytes = 6 ints) and fill in fields */
    memset(mvd, 0, 24);
    *(byte **)(mvd + 0) = data;
    *(int *)(mvd + 4) = streamCount;

    *existing = 0;
    return (MaterialVertexDeclaration *)mvd;
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
void Material_Shutdown(void)
{
    byte *outer;
    int j, i;
    void *obj;
    void **vtable;

    RB_ReleaseVertexDecl();

    /* Release technique COM objects — skip vtable Release on Linux (no real COM) */
    for (outer = materialGlobals + 4; outer < materialGlobals + 772; outer += 24) {
        byte *slot = outer;
        for (j = 0; j < 4; j++) {
            void **pObj = (void **)(slot + 8);
            *pObj = NULL;
            slot += 4;
        }
    }

    memset(materialGlobals + 4, 0, 0x300);
    *(int *)materialGlobals = 0;

    /* Release shader COM objects — skip vtable Release on Linux (no real COM) */

    /* Clear all hash tables */
    for (i = 0; i < 256; i++)
        *(void **)(materialGlobals + 0x259c + i * 4) = NULL;
    *(int *)(materialGlobals + 8972) = 0;
    for (i = 0; i < 64; i++)
        *(void **)(materialGlobals + 0x2498 + i * 4) = NULL;
    for (i = 0; i < 32; i++)
        *(void **)(materialGlobals + 0x2414 + i * 4) = NULL;
    for (i = 0; i < 1024; i++)
        *(void **)(materialGlobals + 0x130c + i * 4) = NULL;
    for (i = 0; i < 1024; i++)
        *(void **)(materialGlobals + 0x308 + i * 4) = NULL;

    memset(materialGlobals, 0, 0x299c);
    memset((byte *)imp_rg + 0x28, 0, 0x1000);
    *(int *)((byte *)imp_rgp + 4) = 0;
}

/* line 1134 */
_ValueType R_RegisterRawImage(const char *name, int baseImageFlags, int imageTrack)
{
    byte *rgp = (byte *)imp_rgp;
    byte *defaultImage = *(byte **)(rgp + 0x102c);
    byte *rawImage = *(byte **)(rgp + 0x1030);
    _ValueType result;

    /* Empty name returns default image */
    if (*name == '\0') {
        *(void **)&result = defaultImage;
        return result;
    }

    /* Check if raw image matches default (no reload needed) */
    if (*(int *)(rawImage + 0x3c) == *(int *)(defaultImage + 0x3c) &&
        *(int *)(rawImage + 0x40) == *(int *)(defaultImage + 0x40) &&
        *(int *)(rawImage + 0x38) == *(int *)(defaultImage + 0x38)) {
        *(void **)&result = defaultImage;
        return result;
    }

    /* Release and reload raw image */
    Image_Release(*(GfxImage **)(rgp + 0x1098));
    if (Image_LoadRaw(*(GfxImage **)(rgp + 0x1098), name, imageTrack)) {
        *(void **)&result = *(void **)(rgp + 0x1030); /* rawImage */
    } else {
        *(void **)&result = *(void **)(rgp + 0x102c); /* defaultImage */
    }
    return result;
}

/* line 1479 — Rebuild all vertex declarations and reload D3D shaders for all materials.
 * Called after device recovery (lost device). */
void Material_ReloadAll(void)
{
    char *dx = (char *)imp_dx;
    /* materialGlobals layout:
     * +0x00: first vertDecl table entry (24 bytes each, stride 0x18)
     * Each entry at offset +4 has a sub-pointer, offset +0 has routing data count
     * 32 entries total from +4 to +772 */
    byte *vertDeclPtr = materialGlobals + 4;
    byte *routingPtr = materialGlobals + 8;
    int i;

    /* Phase 1: Rebuild all vertex declarations (same loop as Load_BuildVertexDecl) */
    while (vertDeclPtr < materialGlobals + 772) {
        int routingCount = *(int *)(routingPtr - 4);
        if (routingCount != 0) {
            /* Rebuild vertex decls for this material's vertex declaration set */
            const byte *sourceInfoBase = (const byte *)s_streamSourceInfo;
            int vertDeclType;

            for (vertDeclType = 0; vertDeclType < 4; vertDeclType++) {
                const byte *sourceInfo = sourceInfoBase + vertDeclType * 21;
                int elemCount = *(int *)(routingPtr);
                const byte *routingData = *(const byte **)(routingPtr - 4);
                D3DVERTEXELEMENT9 elemTable[256];
                void *decl = NULL;
                int numElems = 0;
                int routingIdx;
                const byte *rp = routingData;

                if (elemCount == 0)
                    goto writeEnd2;

                for (routingIdx = 0; routingIdx < elemCount; routingIdx++) {
                    byte sourceIdx = rp[0];
                    byte destIdx = rp[1];
                    const byte *src = sourceInfo + sourceIdx * 3;
                    const byte *dest = (const byte *)s_streamDestInfo + destIdx * 2;
                    int insertPos;

                    rp += 2;

                    if (src[0] == 0xFF) {
                        decl = NULL;
                        goto storeDecl2;
                    }

                    insertPos = numElems;
                    if (numElems > 0 && (unsigned)elemTable[numElems - 1].Stream > (unsigned)src[0]) {
                        int j = numElems - 1;
                        while (j > 0) {
                            elemTable[j] = elemTable[j - 1];
                            if ((unsigned)elemTable[j - 1].Stream <= (unsigned)src[0])
                                break;
                            j--;
                        }
                        insertPos = j;
                    }

                    *(unsigned short *)&elemTable[insertPos].Stream = (unsigned short)src[0];
                    *(unsigned short *)&elemTable[insertPos].Offset = (unsigned short)src[1];
                    ((byte *)&elemTable[insertPos])[4] = src[2];
                    ((byte *)&elemTable[insertPos])[5] = 0;
                    ((byte *)&elemTable[insertPos])[6] = dest[0];
                    ((byte *)&elemTable[insertPos])[7] = dest[1];
                    numElems++;
                }

writeEnd2:
                *(int *)&elemTable[numElems] = *(int *)&declEnd;
                *(int *)((byte *)&elemTable[numElems] + 4) = *((int *)&declEnd + 1);

                do {
                    void *device = *(void **)(dx + 8);
                    void **vtable = *(void ***)device;
                    ((int (__attribute__((stdcall)) *)(void *, const void *, void **))vtable[0x158/4])(
                        device, elemTable, &decl);
                } while (*(int *)imp_alwaysfails);

storeDecl2:
                *(void **)(vertDeclPtr + vertDeclType * 4) = decl;
            }
        }

        vertDeclPtr += 0x18;
        routingPtr += 0x18;
    }

    /* Phase 2: Reload D3D shaders for all materials */
    {
        byte *matSlot = materialGlobals;
        byte *matEnd = materialGlobals + 1024;
        void (*ri_Printf)(int, const char *, ...) = *(void (**)(int, const char *, ...))(
            (byte *)imp_ri + 4);

        for (; matSlot < matEnd; matSlot += 4) {
            /* Each slot at materialGlobals + 0x259c + slotIndex has a shader pointer */
            byte *shader = *(byte **)(matSlot + 0x259c);
            int hr;

            if (!shader)
                continue;

            /* Check shader managed flag at offset 0x0a */
            if (*(byte *)(shader + 0x0a) == 0) {
                /* Not managed: call D3D CreatePixelShader (vtable[0x16c/4]) */
                void *device = *(void **)(dx + 8);
                void **vtable = *(void ***)device;
                hr = ((int (__attribute__((stdcall)) *)(void *, const void *, void **))vtable[0x16c/4])(
                    device, *(void **)(shader + 4), (void **)(shader + 0xc));
            } else {
                /* Managed: call D3D CreateVertexShader (vtable[0x1a8/4]) */
                void *device = *(void **)(dx + 8);
                void **vtable = *(void ***)device;
                hr = ((int (__attribute__((stdcall)) *)(void *, const void *, void **))vtable[0x1a8/4])(
                    device, *(void **)(shader + 4), (void **)(shader + 0xc));
            }

            if (hr < 0) {
                ri_Printf(0, "Couldn't reload shader '%s' when recovering from a lost devi",
                    *(const char **)shader, R_ErrorDescription(hr), hr);
            }
        }
    }
}

#if 0 /* original naked — replaced above */
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
#endif

/* line 481 — Build D3D vertex declarations from stream routing data.
 * For each of 4 vertex declaration types, reads routing pairs from the
 * material's vertex declaration, looks up source/dest info, builds a sorted
 * D3DVERTEXELEMENT9 array, and calls CreateVertexDeclaration. */
void Load_BuildVertexDecl(MaterialVertexDeclaration **mtlVertDecl)
{
    const byte *sourceInfoBase = (const byte *)s_streamSourceInfo;
    int vertDeclType;

    for (vertDeclType = 0; vertDeclType < 4; vertDeclType++) {
        MaterialVertexDeclaration *vd = *mtlVertDecl;
        int elemCount = *(int *)((byte *)vd + 4); /* routing count */
        const byte *routingData = *(const byte **)vd;
        D3DVERTEXELEMENT9 elemTable[256];
        void *decl = NULL;
        int numElems = 0;
        int routingIdx;
        const byte *routingPtr;
        const byte *sourceInfo;

        sourceInfo = sourceInfoBase + vertDeclType * 21; /* s_streamSourceInfo stride = 21 (0x15) */
        routingPtr = routingData;

        if (elemCount == 0)
            goto writeEnd;

        /* For each routing pair (2 bytes: sourceIdx, destIdx) */
        for (routingIdx = 0; routingIdx < elemCount; routingIdx++) {
            byte sourceIdx = routingPtr[0];
            byte destIdx = routingPtr[1];
            const byte *src = sourceInfo + sourceIdx * 3;
            const byte *dest = (const byte *)s_streamDestInfo + destIdx * 2;
            int insertPos;

            routingPtr += 2;

            /* Check if this source is valid (0xFF = skip) */
            if (src[0] == 0xFF) {
                decl = NULL;
                goto storeDecl;
            }

            /* Binary insertion sort: find position to insert by source stream */
            insertPos = numElems;
            if (numElems > 0 && (unsigned)elemTable[numElems - 1].Stream > (unsigned)src[0]) {
                /* Shift elements down to make room */
                int j = numElems - 1;
                while (j > 0) {
                    int prev = j - 1;
                    elemTable[j] = elemTable[j - 1];
                    if ((unsigned)elemTable[prev].Stream <= (unsigned)src[0])
                        break;
                    j = prev;
                }
                insertPos = j;
            }

            /* Insert the new element */
            *(unsigned short *)&elemTable[insertPos].Stream = (unsigned short)src[0];
            *(unsigned short *)&elemTable[insertPos].Offset = (unsigned short)src[1];
            ((byte *)&elemTable[insertPos])[4] = src[2]; /* Type */
            ((byte *)&elemTable[insertPos])[5] = 0;      /* Method */
            ((byte *)&elemTable[insertPos])[6] = dest[0]; /* Usage */
            ((byte *)&elemTable[insertPos])[7] = dest[1]; /* UsageIndex */
            numElems++;
        }

writeEnd:
        /* Append D3DDECL_END() sentinel */
        *(int *)&elemTable[numElems] = *(int *)&declEnd;
        *(int *)((byte *)&elemTable[numElems] + 4) = *((int *)&declEnd + 1);

        /* CreateVertexDeclaration: device->vtable[0x158/4] */
        do {
            void *device = *(void **)((byte *)imp_dx + 8);
            void **vtable = *(void ***)device;
            ((int (__attribute__((stdcall)) *)(void *, const void *, void **))vtable[0x158/4])(
                device, elemTable, &decl);
        } while (*(int *)imp_alwaysfails);

storeDecl:
        /* Store the vertex declaration pointer in mtlVertDecl struct */
        *(void **)((byte *)vd + 8 + vertDeclType * 4) = decl;

        sourceInfoBase += 21; /* advance to next vertDeclType's source info block */
    }
}

#if 0 /* original naked — replaced above */
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
#endif

/* line 1560 */
extern void RB_BindDefaultImages(void);
extern const char * va(const char *fmt, ...);

void R_Cmd_ReloadMaterialTextures(void)
{
    byte *ri = (byte *)imp_ri;
    void (*ri_Printf)(int, const char *, ...) = *(void (**)(int, const char *, ...))ri;
    int (*Cmd_Argc)(void) = *(int (**)(void))(ri + 0x100);
    const char *(*Cmd_Argv)(int) = *(const char *(**)(int))(ri + 0x104);
    const char *name;
    byte *rg;
    int hash;
    byte *existing;
    byte *material;
    int textureCount, i;
    byte *texdefs;
    GfxImage *best;
    GfxImage *lastReloaded;

    if (Cmd_Argc() != 2) {
        ri_Printf(0, "Usage: reloadMaterialTextures <materialName>\n");
        return;
    }

    name = Cmd_Argv(1);

    /* Look up material in hash table */
    hash = R_HashAssetName(name);
    hash &= 0x3ff;
    rg = (byte *)imp_rg;
    existing = *(byte **)(rg + 0x28 + hash * 4);
    while (existing) {
        if (strcmp(*(const char **)existing, name) == 0)
            break;
        hash = (hash + 1) & 0x3ff;
        rg = (byte *)imp_rg;
        existing = *(byte **)(rg + 0x28 + hash * 4);
    }

    material = existing ? *(byte **)((byte *)imp_rg + 0x28 + hash * 4) : NULL;

    if (!material) {
        ri_Printf(0, "%s", va("ReloadMaterialTextures: Material '%s' is not currently loaded\n", name));
        return;
    }

    RB_BindDefaultImages();

    /* Reload textures in order: repeatedly find the smallest image pointer
     * greater than lastReloaded, and reload it. This ensures ordered reload. */
    textureCount = *(unsigned short *)(material + 0x34);
    if (textureCount == 0)
        return;

    texdefs = *(byte **)(material + 0x3c);
    lastReloaded = NULL;

    for (;;) {
        best = NULL;
        for (i = 0; i < textureCount; i++) {
            byte *texdef = texdefs + i * 0xc;
            GfxImage *img;

            if (*(byte *)(texdef + 5) == 5) /* skip water */
                continue;

            img = *(GfxImage **)(texdef + 8);
            if (!lastReloaded) {
                /* First pass: find largest image pointer */
                if ((unsigned int)img > (unsigned int)best)
                    best = img;
            } else {
                /* Subsequent passes: find largest below lastReloaded */
                if ((unsigned int)img > (unsigned int)best &&
                    (unsigned int)img < (unsigned int)lastReloaded)
                    best = img;
            }
        }

        if (!best)
            return;

        Image_Reload(best);
        lastReloaded = best;
    }
}

/* line 920 */
_ValueType Material_Duplicate(_ValueType mtlCopy, const char *name)
{
    byte *rg = (byte *)imp_rg;
    byte *rgp;
    int hash = R_HashAssetName(name) & 0x3ff;
    byte *material;
    byte *existing;
    int nameLen;
    void *(*hunkAlloc)(int);
    char *nameDst;
    int count;
    _ValueType result;

    /* Search for existing material with this name */
    existing = *(byte **)(rg + 0x28 + hash * 4);
    while (existing) {
        if (strcmp(*(const char **)existing, name) == 0) {
            /* Found — overwrite with new data, preserve name pointer */
            char *savedName = *(char **)existing;
            memcpy(existing, (void *)*(int *)&mtlCopy, 0x44);
            *(char **)existing = savedName;
            *(int *)imp_rgp = 1; /* rgp->needsSort = true */
            *(void **)&result = existing;
            return result;
        }
        hash = (hash + 1) & 0x3ff;
        rg = (byte *)imp_rg;
        existing = *(byte **)(rg + 0x28 + hash * 4);
    }

    /* Not found — allocate new material (0x44 struct + name string) */
    nameLen = strlen(name) + 1;
    hunkAlloc = *(void *(**)(int))((byte *)imp_ri + 0xc);
    material = (byte *)hunkAlloc(0x44 + nameLen);

    /* Copy material struct from source */
    memcpy(material, (void *)*(int *)&mtlCopy, 0x44);

    /* Name stored after struct, set name pointer */
    nameDst = (char *)(material + 0x44);
    *(char **)material = nameDst;
    memcpy(nameDst, name, nameLen);

    /* Register in rgp and rg */
    rgp = (byte *)imp_rgp;
    *(int *)rgp = 1; /* needsSort */
    *(unsigned short *)(material + 8) = (unsigned short)hash;
    count = *(int *)(rgp + 4);
    *(unsigned short *)(material + 0xa) = (unsigned short)count;
    *(void **)(rgp + 8 + count * 4) = material;
    rg = (byte *)imp_rg;
    *(void **)(rg + 0x28 + hash * 4) = material;
    count++;
    *(int *)(rgp + 4) = count;

    if (count == 0x400)
        R_Error(0, "Too many unique materials (%i or more)\n", 0x400);

    *(void **)&result = material;
    return result;
}

/* line 1019 */
extern Material * Material_Load(const char *name, int imageTrack);

MaterialHandle Material_Register(const char *name, int imageTrack)
{
    byte *rg;
    byte *rgp;
    int hash = R_HashAssetName(name) & 0x3ff;
    byte *existing;
    Material *material;
    int count;

    /* Search for existing material */
    rg = (byte *)imp_rg;
    existing = *(byte **)(rg + 0x28 + hash * 4);
    while (existing) {
        if (strcmp(*(const char **)existing, name) == 0) {
            /* Found existing material */
            return (MaterialHandle)*(void **)((byte *)imp_rg + 0x28 + hash * 4);
        }
        hash = (hash + 1) & 0x3ff;
        rg = (byte *)imp_rg;
        existing = *(byte **)(rg + 0x28 + hash * 4);
    }

    /* Not found — try loading */
    material = Material_Load(name, imageTrack);
    if (!material) {
        /* Load failed — duplicate from default material */
        rgp = (byte *)imp_rgp;
        if (!*(void **)(rgp + 0x102c))
            R_Error(0, "No default material loaded for %s fallback", name);

        Com_Printf("^3WARNING: Could not find material '%s'\n", name);
        {
            _ValueType dup = Material_Duplicate(*(_ValueType *)(rgp + 0x102c), name);
            return *(MaterialHandle *)&dup;
        }
    }

    /* Register new material */
    rgp = (byte *)imp_rgp;
    *(int *)rgp = 1; /* needsSort */
    *(unsigned short *)((byte *)material + 8) = (unsigned short)hash;
    count = *(int *)(rgp + 4);
    *(unsigned short *)((byte *)material + 0xa) = (unsigned short)count;
    *(void **)(rgp + 8 + count * 4) = material;
    rg = (byte *)imp_rg;
    *(void **)(rg + 0x28 + hash * 4) = material;
    count++;
    *(int *)(rgp + 4) = count;

    if (count == 0x400)
        R_Error(0, "Too many unique materials (%i or more)\n", 0x400);

    return (MaterialHandle)material;
}

/* line 1119 */
MaterialHandle Material_RegisterHandle(const char *name, int baseImageFlags, int imageTrack)
{
    MaterialHandle material;

    (void)baseImageFlags;

    if (name == NULL || *name == '\0')
        return rgp.defaultMaterial;

    material = Material_Register(name, imageTrack);
    if (material != NULL)
        return material;

    if (strncmp(name, "ui/", 3) == 0 || strncmp(name, "ui_", 3) == 0)
        return rgp.whiteMaterial ? rgp.whiteMaterial : rgp.defaultMaterial;

    return rgp.defaultMaterial;
}

/* line 1345 — Material_Init
 * Initializes the material system: registers all built-in materials,
 * optionally registers fill-test materials, registers $raw material,
 * and validates technique set compatibility with $default. */
extern void Material_PreLoadAllShaderText(void);
extern void Com_Error(int errorLevel, const char *msg, ...);
extern BuiltInMaterialTable s_builtInMaterials[];
extern BuiltInMaterialTable s_builtInMaterials_end[];

void Material_Init(void)
{
    byte *rgp_ptr = (byte *)&rgp;

    memset(materialGlobals, 0, 0x299c);
    Material_PreLoadAllShaderText();

    /* Register all built-in materials */
    BuiltInMaterialTable *entry;
    for (entry = s_builtInMaterials; entry < s_builtInMaterials_end; entry++) {
        *(Material **)entry->material = Material_Register(entry->name, 0);
        if (!*(Material **)entry->material)
            Com_Error(0, "Could not find material '%s'", entry->name);
    }

    /* If fill-rate testing enabled, register fill-test materials */
    if (*(byte *)(*(int *)imp_r_testFillEnable + 8)) {
        for (entry = (BuiltInMaterialTable *)&s_fillTestMaterials; entry < s_builtInMaterials; entry++) {
            *(Material **)entry->material = Material_Register(entry->name, 0);
            if (!*(Material **)entry->material)
                Com_Error(0, "Could not find material '%s'", entry->name);
        }
    }

    /* Register $raw material and validate against $default */
    Material *rawMaterial = Material_Register("$raw", 0);
    *(Material **)(rgp_ptr + 0x1030) = rawMaterial; /* rgp.rawMaterial */
    Material *defaultMaterial = *(Material **)(rgp_ptr + 0x102c); /* rgp.defaultMaterial */

    /* First pass: check if raw material is compatible with default */
    if (rawMaterial->textures != defaultMaterial->textures ||
        rawMaterial->constants != defaultMaterial->constants ||
        rawMaterial->techniqueSet != defaultMaterial->techniqueSet) {
        if (rawMaterial->textureCount != 1) {
            /* Incompatible: fall back to $default */
            typedef void (*ri_Printf_fn)(int, const char *, ...);
            ((ri_Printf_fn)(*(void **)imp_ri))(3, "$raw material is not compatible with $default");
            rawMaterial = defaultMaterial;
            *(Material **)(rgp_ptr + 0x1030) = defaultMaterial;
        }
    }

    /* Reload pointers (may have changed after fallback) */
    rawMaterial = *(Material **)(rgp_ptr + 0x1030);
    defaultMaterial = *(Material **)(rgp_ptr + 0x102c);

    /* Second pass: if textures/constants/techniqueSet still differ, copy technique data */
    if (rawMaterial->textures != defaultMaterial->textures ||
        rawMaterial->constants != defaultMaterial->constants ||
        rawMaterial->techniqueSet != defaultMaterial->techniqueSet) {
        /* Copy first entry from raw's textures to rgp fallback slot, redirect pointer */
        *(int *)(rgp_ptr + 0x10e4) = *(int *)rawMaterial->textures;
        rawMaterial->textures = (MaterialTextureDef *)(rgp_ptr + 0x10e4);
    }
}

/* std::__adjust_heap for Material** — heap sift-down + push-up */
void ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_(
    Material **first, int holeIndex, int len, Material *value, MaterialCompFunc comp)
{
    int topIndex = holeIndex;
    int secondChild = 2 * holeIndex + 2;
    while (secondChild < len) {
        if (comp(first[secondChild], first[secondChild - 1]))
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
        if (!comp(first[parent], value))
            break;
        first[holeIndex] = first[parent];
        holeIndex = parent;
    }
    first[holeIndex] = value;
}

/* std::__insertion_sort for Material** — insertion sort with comparator */
void ZSt16__insertion_sortIPP8MaterialPFhPKS0_S4_EEvT_S7_T0_(
    Material **first, Material **last, MaterialCompFunc comp)
{
    Material **i;
    if (first == last) return;
    for (i = first + 1; i != last; i++) {
        Material *val = *i;
        if (comp(val, *first)) {
            unsigned int n = (unsigned int)((char *)i - (char *)first) & ~3u;
            memmove(first + 1, first, n);
            *first = val;
        } else {
            Material **prev = i - 1;
            Material **hole = i;
            while (comp(val, *prev)) {
                *hole = *prev;
                hole = prev;
                prev--;
            }
            *hole = val;
        }
    }
}

/* std::__introsort_loop for Material** — introsort with heapsort fallback */
void ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_(
    Material **first, Material **last, int depth_limit, MaterialCompFunc comp)
{
    while ((char *)last - (char *)first > 64) {
        if (depth_limit == 0) {
            int n = (int)(last - first);
            int half = (n - 2) / 2;
            int i;
            Material **end;
            for (i = half; i >= 0; i--)
                ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_(
                    first, i, n, first[i], comp);
            for (end = last - 1; end - first > 0; end--) {
                Material *value = *end;
                *end = *first;
                ZSt13__adjust_heapIPP8MaterialiS1_PFhPKS0_S4_EEvT_T0_S8_T1_T2_(
                    first, 0, (int)(end - first), value, comp);
            }
            return;
        }
        depth_limit--;
        {
            int n = (int)(last - first);
            Material **midPtr = first + n / 2;
            Material **pivotPtr;
            Material *pivot;
            Material **lo, **hi;
            if (comp(*first, *midPtr)) {
                if (comp(*midPtr, *(last - 1)))
                    pivotPtr = midPtr;
                else if (comp(*first, *(last - 1)))
                    pivotPtr = last - 1;
                else
                    pivotPtr = first;
            } else {
                if (comp(*first, *(last - 1)))
                    pivotPtr = first;
                else if (comp(*(last - 1), *midPtr))
                    pivotPtr = midPtr;
                else
                    pivotPtr = last - 1;
            }
            pivot = *pivotPtr;
            lo = first;
            hi = last;
            for (;;) {
                while (!comp(pivot, *lo)) lo++;
                hi--;
                while (!comp(*hi, pivot)) hi--;
                if (lo >= hi) break;
                { Material *tmp = *lo; *lo = *hi; *hi = tmp; }
                lo++;
            }
            ZSt16__introsort_loopIPP8MaterialiPFhPKS0_S4_EEvT_S7_T0_T1_(
                lo, last, depth_limit, comp);
            last = lo;
        }
    }
}

#if 0 /* original naked — replaced above */
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
#endif /* original naked Material introsort */
