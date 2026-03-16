/* ASM dump from: r_material_load_obj.cpp */
/* Original path: /Users/kevin/Development/i5works/COD2/Project/PC/gfx_d3d/r_material_load_obj.cpp */

#include "common_types.h"
#include "imports.h"

/* Original includes (from N_BINCL debug info):
 *   #include "PC/universal/com_math.h"
 */

extern unsigned char mtlLoadGlob[]; /* mtlLoadGlob - 128 bytes in BSS */
extern const unsigned char g_useTechnique[]; /* g_useTechnique — defined in rodata.c */
/* Static data tables — defined in r_material_load_obj_data.h (extracted from binary) */
#include "r_material_load_obj_data.h"
extern const CodeSamplerSource s_lightSamplers[];
extern const CodeSamplerSource s_lightmapSamplers[];
extern const CodeSamplerSource s_lightGridSamplers[];
extern const CodeSamplerSource s_codeSamplers[];
extern const CodeSamplerSource s_defaultCodeSamplers[];
extern const CodeConstantSource s_lightConsts[];
extern const CodeConstantSource s_cameraConsts[];
extern const CodeConstantSource s_nearPlaneConsts[];
extern const CodeConstantSource s_lightGridConsts[];
extern const CodeConstantSource s_codeConsts[];
extern const CodeConstantSource s_defaultCodeConsts[];
extern const MtlStateMapBitName s_alphaTestBitNames[];
extern const MtlStateMapBitName s_blendOpRgbBitNames[];
extern const MtlStateMapBitName s_srcBlendRgbBitNames[];
extern const MtlStateMapBitName s_dstBlendRgbBitNames[];
extern const MtlStateMapBitName s_blendOpAlphaBitNames[];
extern const MtlStateMapBitName s_srcBlendAlphaBitNames[];
extern const MtlStateMapBitName s_dstBlendAlphaBitNames[];
extern const MtlStateMapBitName s_cullFaceBitNames[];
extern const MtlStateMapBitName s_depthTestBitNames[];
extern const MtlStateMapBitName s_depthWriteBitNames[];
extern const MtlStateMapBitName s_colorWriteRgbBitNames[];
extern const MtlStateMapBitName s_colorWriteAlphaBitNames[];
extern const MtlStateMapBitName s_fogBitNames[];
extern const MtlStateMapBitName s_polygonOffsetBitNames[];
extern const MtlStateMapBitName s_wireframeBitNames[];
extern const MtlStateMapBitName s_stencilBitNames[];
extern const MtlStateMapBitName s_stencilOpFrontPassBitNames[];
extern const MtlStateMapBitName s_stencilOpFrontFailBitNames[];
extern const MtlStateMapBitName s_stencilOpFrontZFailBitNames[];
extern const MtlStateMapBitName s_stencilFuncFrontBitNames[];
extern const MtlStateMapBitName s_stencilOpBackPassBitNames[];
extern const MtlStateMapBitName s_stencilOpBackFailBitNames[];
extern const MtlStateMapBitName s_stencilOpBackZFailBitNames[];
extern const MtlStateMapBitName s_stencilFuncBackBitNames[];
extern const MtlStateMapBitGroup s_stateMapSrcBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstAlphaTestBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstBlendFuncRgbBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstBlendFuncAlphaBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstCullFaceBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstDepthTestBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstDepthWriteBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstColorWriteBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstFogBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstPolygonOffsetBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstWireframeBitGroup[];
extern const MtlStateMapBitGroup s_stateMapDstStencilBitGroup[];
static const MtlTextureFunctionDx7 s_textureFuncsDx7[21]; /* s_textureFuncsDx7 — unused in DX9 path */
static const PassOptionDx7 s_passOptionsDx7[5]; /* s_passOptionsDx7 — unused in DX9 path */

HRESULT IncludeClass_Close(const IncludeClass * _this, LPCVOID data);
static Bool Material_ValidatePassArguments(const MaterialObj *material, const char *techniqueSetName, const char *techniqueName, int argCount, const MaterialShaderArgument *args);
static Bool Material_ValidatePassArguments_impl(const Material *material, const char *techniqueSetName, const char *techniqueName, int argCount, const MaterialShaderArgument *args);
static void Material_PreLoadSingleShaderText(const char *filename, const char *subdir, GfxCachedShaderText *cached);
static void Material_PreLoadSingleShaderText_impl(const char *filename, const char *subdir, GfxCachedShaderText *cached);
extern int Com_MatchToken(const char **text, const char *match, int allowLineBreaks);
extern float Com_ParseFloat(const char **text);
extern void Com_Printf(const char *fmt, ...);
extern int Com_sprintf(char *dest, int size, const char *fmt, ...);
extern int FS_FOpenFileRead(const char *filename, int *fileHandle, int uniqueFILE);
extern void FS_Read(void *buf, int len, int fileHandle);
extern void FS_FCloseFile(int fileHandle);
extern void *Hunk_AllocAlignInternal(int size, int align);
static Bool Material_CachedShaderTextLess(const GfxCachedShaderText *cached0, const GfxCachedShaderText *cached1);
HRESULT IncludeClass_Open(const IncludeClass * _this, D3DXINCLUDE_TYPE IncludeType, LPCSTR filename, LPCVOID parentData, LPCVOID *data, MaterialTechnique * (*byteCount)[4][34]);
void Material_PreLoadAllShaderText(void);
static Bool Material_ParseCodeConstantSource_r(const char * *text, ShaderConstantRouting *routing, int offset, const CodeConstantSource *sourceTable, MaterialShaderArgument *arg);
static Bool Material_ParseCodeConstantSource_r_impl(const char **text, const byte *routing, int offset, const CodeConstantSource *sourceTable, byte *arg);
extern void Com_UngetToken(void);
static Bool Material_ParseVector(int elemCount);
static Bool Material_ParseVector_impl(const char **text, int elemCount, float *vector);
static Bool Material_LoadPassTextureStateDx7(int samplerIndex, MtlTextureFunctionValidDx7 validTest, int *texStageBits);
static Bool Material_CodeSamplerSource_r(const char * *text, int offset, const CodeSamplerSource *sourceTable, MaterialShaderArgument *arg);
static Bool Material_CodeSamplerSource_r_impl(const char **text, int offset, const CodeSamplerSource *sourceTable, MaterialShaderArgument *arg);
static Bool Material_ParseSamplerSource(const char * *text, MaterialShaderArgument *arg);
static Bool Material_ParseSamplerSource_impl(const char **text, MaterialShaderArgument *arg);
extern void Com_ScriptWarning(const char *fmt, ...);
extern const char *Com_Parse(const char **text);
extern int Com_ParseInt(const char **text);
extern const char *Material_RegisterString(const char *string);
static Bool Material_SetPassShaderArguments(const char * *text, short unsigned int *techFlags, short unsigned int *argCount, MaterialShaderArgument * *args);
static MtlParseSuccess Material_ParseRuleSetConditionTest(const char * *text, MaterialStateMapRule *rule);
static MtlParseSuccess Material_ParseRuleSetConditionTest_impl(const char **text, const char *token, MaterialStateMapRule *rule);
static Bool Material_ParseRuleSet(const char * *text, const char *ruleSetName, const MtlStateMapBitGroup *stateSet, const MaterialStateMapRuleSet * *ruleSet);
static Bool Material_LoadPassStateMap(MaterialStateMap * *stateMap);
static MaterialShader * Material_LoadPassShader(MaterialShaderType shaderType);
static Bool Material_FinishLoadingInstance(MaterialObj *material, int imageTrack);
Material * Material_Load(const char *name, int imageTrack);
typedef unsigned char (*GfxCachedShaderTextCompFunc)(const GfxCachedShaderText *, const GfxCachedShaderText *);
void ZSt13__adjust_heapIP19GfxCachedShaderTextiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(GfxCachedShaderText *first, int holeIndex, int len, GfxCachedShaderText value, GfxCachedShaderTextCompFunc comp);
void ZSt16__introsort_loopIP19GfxCachedShaderTextiPFhRKS0_S3_EEvT_S6_T0_T1_(GfxCachedShaderText *first, GfxCachedShaderText *last, int depth_limit, GfxCachedShaderTextCompFunc comp);

/* line 907 */
HRESULT IncludeClass_Close(const IncludeClass * _this, LPCVOID data)
{
    return 0;
}

/* line 3290 — Material_ValidatePassArguments
 * Validates that all shader arguments reference textures/constants that exist in the material.
 * Actual convention: eax=material, edx=techniqueSetName, ecx=techniqueName, stack=argCount,args */
static Bool Material_ValidatePassArguments_impl(const Material *material, const char *techniqueSetName, const char *techniqueName, int argCount, const MaterialShaderArgument *args)
{
    int i, j;
    for (i = 0; i < argCount; i++) {
        const MaterialShaderArgument *arg = &args[i];

        if (arg->type == 2) {
            /* Constant argument: verify it exists in material's constants list (stride 0x14) */
            const char *argName = arg->u.name;
            byte *consts = (byte *)material->constants;
            int found = 0;
            for (j = 0; j < material->constantCount; j++) {
                if (*(const char **)(consts + j * 0x14) == argName) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                Com_Printf("material '%s' using technique '%s' from techniqueSet '%s' doesn't have constant '%s'\n",
                           material->info.name, techniqueName, techniqueSetName, argName);
                return 0;
            }
        } else if (arg->type == 4) {
            /* Texture argument: verify it exists in material's textures list (stride 0x0c) */
            const char *argName = arg->u.name;
            byte *texs = (byte *)material->textures;
            int found = 0;
            for (j = 0; j < material->textureCount; j++) {
                if (*(const char **)(texs + j * 0x0c) == argName) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                Com_Printf("material '%s' using technique '%s' from techniqueSet '%s' doesn't have texture '%s'\n",
                           material->info.name, techniqueName, techniqueSetName, argName);
                return 0;
            }
        }
    }
    return 1;
}

/* Trampoline: eax=material, edx=techniqueSetName, ecx=techniqueName, stack=argCount,args */
static __attribute__((naked))
Bool Material_ValidatePassArguments(const MaterialObj *material, const char *techniqueSetName, const char *techniqueName, int argCount, const MaterialShaderArgument *args)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 0xc(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_ValidatePassArguments_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 3553 — Material_PreLoadSingleShaderText
 * Loads a shader text file from disk into a GfxCachedShaderText entry.
 * Builds path "materials/shaders/{subdir}{filename}", allocates memory for
 * name + file contents, reads file, and populates the cached struct.
 * Actual convention: eax=filename, edx=subdir, ecx=cached */
static void Material_PreLoadSingleShaderText_impl(const char *filename, const char *subdir, GfxCachedShaderText *cached)
{
    char filepath[64];
    int fileHandle;

    Com_sprintf(filepath, 64, "materials/shaders/%s%s", subdir, filename);
    int fileSize = FS_FOpenFileRead(filepath, &fileHandle, 1);

    /* Allocate: room for "subdir" + "filename" + NUL + file contents + NUL */
    int allocSize = strlen(subdir) + strlen(filename) + fileSize + 2;
    char *buf = (char *)Hunk_AllocAlignInternal(allocSize, 1);

    cached->name = buf;
    int nameLen = sprintf(buf, "%s%s", subdir, filename);
    cached->text = buf + nameLen + 1;
    FS_Read((void *)cached->text, fileSize, fileHandle);
    FS_FCloseFile(fileHandle);
    ((char *)cached->text)[fileSize] = '\0';
    cached->textSize = fileSize;
}

/* Trampoline: eax=filename, edx=subdir, ecx=cached */
static __attribute__((naked))
void Material_PreLoadSingleShaderText(const char *filename, const char *subdir, GfxCachedShaderText *cached)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_PreLoadSingleShaderText_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}

/* line 3589 */
static Bool Material_CachedShaderTextLess(const GfxCachedShaderText *cached0, const GfxCachedShaderText *cached1)
{
    return strcmp(*(const char **)cached0, *(const char **)cached1) < 0;
}

/* line 897 — IncludeClass_Open
 * D3DX shader include handler. Binary-searches the pre-loaded cached shader text
 * array (mtlLoadGlob) for the requested filename. Tries exact match first,
 * then "lib/" prefix. Returns S_OK (0) on success, 1 on failure. */
extern const char *va(const char *fmt, ...);
extern int stricmp(const char *s1, const char *s2);

/* Binary search helper for cached shader text */
static int Material_FindCachedShaderText(const char *searchName)
{
    int count = *(int *)mtlLoadGlob;
    GfxCachedShaderText *cached = *(GfxCachedShaderText **)(mtlLoadGlob + 4);
    int bot = 0, top = count - 1;

    while (bot <= top) {
        int mid = (bot + top) / 2;
        int cmp = stricmp(searchName, cached[mid].name);
        if (cmp == 0)
            return mid;
        if (cmp > 0)
            bot = mid + 1;
        else
            top = mid - 1;
    }
    return -1;
}

HRESULT IncludeClass_Open(const IncludeClass * _this, D3DXINCLUDE_TYPE IncludeType, LPCSTR filename, LPCVOID parentData, LPCVOID *data, MaterialTechnique * (*byteCount)[4][34])
{
    GfxCachedShaderText *cached = *(GfxCachedShaderText **)(mtlLoadGlob + 4);
    int idx;

    /* Try exact filename match */
    idx = Material_FindCachedShaderText(filename);
    if (idx < 0) {
        /* Try "lib/" prefix */
        idx = Material_FindCachedShaderText(va("lib/%s", filename));
        if (idx < 0)
            return 1; /* not found */
    }

    /* Return text data and size */
    *(const char **)data = cached[idx].text;
    *(int *)byteCount = cached[idx].textSize;
    return 0;
}

/* line 3595 — Loads all shader text files from materials/shaders/ and materials/shaders/lib/,
 * builds a sorted GfxCachedShaderText cache for binary search during shader compilation.
 * Enumerates .hlsl files, allocates Hunk memory, reads file contents, sorts by name. */
extern char ** FS_ListFiles(const char *dir, const char *ext, int flags, int *count, int);
extern void FS_FreeFileList(char **list);
extern int FS_ReadFile(const char *path, void **buffer);
extern void FS_FreeFile(void *buffer);
extern void *Hunk_AllocInternal(int size);
extern unsigned char Material_CachedShaderTextLess(const GfxCachedShaderText *, const GfxCachedShaderText *);
/* mtlLoadGlob: [0]=count, [4]=array ptr — declared as extern byte[] at top of file */
void Material_PreLoadAllShaderText(void)
{
    int fileCountRoot, fileCountLib;
    char **shaderListRoot, **shaderListLib;
    GfxCachedShaderText *cache;
    int totalCount, i;

    /* Enumerate shader files */
    shaderListRoot = FS_ListFiles("materials/shaders/", "hlsl", 0, &fileCountRoot, 0x14);
    shaderListLib = FS_ListFiles("materials/shaders/lib/", "hlsl", 0, &fileCountLib, 0x14);

    totalCount = fileCountRoot + fileCountLib;
    *(int *)mtlLoadGlob = totalCount;
    cache = (GfxCachedShaderText *)Hunk_AllocInternal(totalCount * 12);
    *(int *)(mtlLoadGlob + 4) = (int)cache;

    /* Load root shader files */
    {
        GfxCachedShaderText *entry = cache;
        for (i = 0; i < fileCountRoot; i++) {
            const char *filename = shaderListRoot[i];
            char path[256];
            void *fileData;
            int fileLen;

            /* Build path: materials/shaders/<filename> */
            sprintf(path, "materials/shaders/%s", filename);

            /* Strip extension for name */
            entry->name = (const char *)Hunk_AllocInternal((int)strlen(filename) + 1);
            {
                char *dst = (char *)entry->name;
                const char *src = filename;
                while (*src && *src != '.') *dst++ = *src++;
                *dst = '\0';
            }

            fileLen = FS_ReadFile(path, &fileData);
            if (fileLen > 0) {
                entry->text = (const char *)Hunk_AllocInternal(fileLen + 1);
                memcpy((void *)entry->text, fileData, fileLen);
                ((char *)entry->text)[fileLen] = '\0';
                entry->textSize = fileLen;
                FS_FreeFile(fileData);
            } else {
                entry->text = "";
                entry->textSize = 0;
            }
            entry++;
        }

        /* Load lib shader files */
        for (i = 0; i < fileCountLib; i++) {
            const char *filename = shaderListLib[i];
            char path[256];
            void *fileData;
            int fileLen;

            sprintf(path, "materials/shaders/lib/%s", filename);

            /* Name includes "lib/" prefix */
            {
                int nameLen = (int)strlen(filename) + 5; /* "lib/" + name + null */
                entry->name = (const char *)Hunk_AllocInternal(nameLen);
                char *dst = (char *)entry->name;
                memcpy(dst, "lib/", 4);
                dst += 4;
                const char *src = filename;
                while (*src && *src != '.') *dst++ = *src++;
                *dst = '\0';
            }

            fileLen = FS_ReadFile(path, &fileData);
            if (fileLen > 0) {
                entry->text = (const char *)Hunk_AllocInternal(fileLen + 1);
                memcpy((void *)entry->text, fileData, fileLen);
                ((char *)entry->text)[fileLen] = '\0';
                entry->textSize = fileLen;
                FS_FreeFile(fileData);
            } else {
                entry->text = "";
                entry->textSize = 0;
            }
            entry++;
        }
    }

    /* Sort cache by name using introsort + insertion sort */
    {
        GfxCachedShaderText *first = *(GfxCachedShaderText **)(mtlLoadGlob + 4);
        GfxCachedShaderText *last = first + totalCount;
        if (first != last && totalCount > 1) {
            int n = totalCount, depth = 0;
            while (n > 1) { depth++; n >>= 1; }
            depth *= 2;
            ZSt16__introsort_loopIP19GfxCachedShaderTextiPFhRKS0_S3_EEvT_S6_T0_T1_(
                first, last, depth, Material_CachedShaderTextLess);
            /* Insertion sort for final cleanup */
            if ((char *)last - (char *)first > 12 * 16) {
                GfxCachedShaderText *threshold = first + 16;
                /* Sort first 16 elements */
                GfxCachedShaderText *ii;
                for (ii = first + 1; ii != threshold && ii != last; ii++) {
                    GfxCachedShaderText val = *ii;
                    if (Material_CachedShaderTextLess(&val, first)) {
                        memmove(first + 1, first, (char *)ii - (char *)first);
                        *first = val;
                    } else {
                        GfxCachedShaderText *prev = ii - 1;
                        GfxCachedShaderText *hole = ii;
                        while (Material_CachedShaderTextLess(&val, prev)) {
                            *hole = *prev;
                            hole = prev;
                            prev--;
                        }
                        *hole = val;
                    }
                }
                /* Unguarded insertion sort for remaining */
                for (; ii != last; ii++) {
                    GfxCachedShaderText val = *ii;
                    GfxCachedShaderText *prev = ii - 1;
                    GfxCachedShaderText *hole = ii;
                    while (Material_CachedShaderTextLess(&val, prev)) {
                        *hole = *prev;
                        hole = prev;
                        prev--;
                    }
                    *hole = val;
                }
            } else {
                /* Small array: direct insertion sort */
                GfxCachedShaderText *ii;
                for (ii = first + 1; ii != last; ii++) {
                    GfxCachedShaderText val = *ii;
                    if (Material_CachedShaderTextLess(&val, first)) {
                        memmove(first + 1, first, (char *)ii - (char *)first);
                        *first = val;
                    } else {
                        GfxCachedShaderText *prev = ii - 1;
                        GfxCachedShaderText *hole = ii;
                        while (Material_CachedShaderTextLess(&val, prev)) {
                            *hole = *prev;
                            hole = prev;
                            prev--;
                        }
                        *hole = val;
                    }
                }
            }
        }
    }

    FS_FreeFileList(shaderListRoot);
    FS_FreeFileList(shaderListLib);
}

#if 0 /* original naked (436 lines) */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3595 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x7c, %esp\n"
        /* { scope 1: __val, __last */
        "movl $0x14, 0x10(%esp)\n" /* line 3602 */
        "leal -0x1c(%ebp), %eax\n" /* fileCountRoot */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00227f64, 4(%esp)\n" /* "hlsl" */
        "movl $str_00227f6c, (%esp)\n" /* "materials/shaders/" */
        "calll FS_ListFiles\n"
        "movl %eax, -0x50(%ebp)\n" /* shaderListRoot */
        "movl $0x14, 0x10(%esp)\n" /* line 3603 */
        "leal -0x20(%ebp), %eax\n" /* fileCountLib */
        "movl %eax, 0xc(%esp)\n"
        "movl $0, 8(%esp)\n"
        "movl $str_00227f64, 4(%esp)\n" /* "hlsl" */
        "movl $str_00227f80, (%esp)\n" /* "materials/shaders/lib/" */
        "calll FS_ListFiles\n"
        "movl %eax, -0x4c(%ebp)\n" /* shaderListLib */
        "movl -0x1c(%ebp), %eax\n" /* line 3605 | fileCountRoot */
        "addl -0x20(%ebp), %eax\n" /* fileCountLib */
        "movl %eax, mtlLoadGlob\n"
        "leal (%eax, %eax, 2), %eax\n" /* line 3606 */
        "shll $2, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Hunk_AllocInternal\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, mtlLoadGlob+4\n"
        "movl -0x1c(%ebp), %edi\n" /* line 3607 | fileCountRoot, __last */
        /* { scope 2: __last, __val, __val */
        "testl %edi, %edi\n" /* line 3584 | __last */
        "jg .Lf101c2c_00102039\n"
        "movl %eax, %ebx\n"
        /* } scope */
        ".Lf101c2c_00101cbf:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 3608 | fileCount, cached */
        "movl %ebx, -0x5c(%ebp)\n"
        "leal (%ebx, %eax, 4), %eax\n" /* cached */
        "movl -0x20(%ebp), %edi\n" /* fileCountLib, fileCount */
        /* { scope 2: __last, __val, __val */
        /* { scope 3: __val, __val */
        "testl %edi, %edi\n" /* line 3584 | __last */
        "jg .Lf101c2c_00102009\n"
        "movl %ebx, %edx\n"
        /* } scope */
        /* } scope */
        ".Lf101c2c_00101cd5:\n"
        "movl mtlLoadGlob, %eax\n" /* line 3610 */
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%edx, %eax, 4), %eax\n"
        "movl %eax, -0x48(%ebp)\n" /* __last */
        /* { scope 2: __last, __val, __val */
        "cmpl %eax, %edx\n" /* line 2604 */
        "je .Lf101c2c_00101e6e\n"
        "movl %eax, %ebx\n" /* line 2606 | __n */
        "subl %edx, %ebx\n"
        "movl %ebx, %ecx\n"
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n" /* __n */
        "movl %eax, %edx\n" /* __n */
        "shll $4, %edx\n"
        "addl %edx, %eax\n" /* __n */
        "movl %eax, %edx\n" /* __n */
        "shll $8, %edx\n"
        "addl %edx, %eax\n" /* __n */
        "movl %eax, %edx\n" /* __n */
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n" /* __n */
        "leal (%ecx, %eax, 2), %eax\n" /* __n */
        /* { scope 3: __val, __val */
        /* { scope 4 */
        "cmpl $1, %eax\n" /* line 2253 */
        "je .Lf101c2c_00102067\n"
        "xorl %edx, %edx\n"
        ".Lf101c2c_00101d1a:\n"
        "addl $1, %edx\n" /* line 2254 */
        "sarl $1, %eax\n" /* line 2253 */
        "cmpl $1, %eax\n"
        "jne .Lf101c2c_00101d1a\n"
        "leal (%edx, %edx), %eax\n"
        /* } scope */
        /* } scope */
        ".Lf101c2c_00101d27:\n"
        "movl $Material_CachedShaderTextLess, 0xc(%esp)\n" /* line 2606 */
        "movl %eax, 8(%esp)\n" /* __n */
        "movl -0x48(%ebp), %eax\n" /* __last, __n */
        "movl %eax, 4(%esp)\n" /* __n */
        "movl -0x5c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll ZSt16__introsort_loopIP19GfxCachedShaderTextiPFhRKS0_S3_EEvT_S6_T0_T1_\n"
        "cmpl $0xcb, %ebx\n" /* line 2233 */
        "jg .Lf101c2c_00101e9c\n"
        /* { scope 3: __val, __val */
        "movl -0x5c(%ebp), %edi\n" /* line 2156 */
        "addl $0xc, %edi\n"
        "cmpl %edi, -0x48(%ebp)\n" /* __last */
        "je .Lf101c2c_00101e6e\n"
        /* { scope 4 */
        ".Lf101c2c_00101d60:\n"
        "movl (%edi), %ebx\n" /* line 2159 */
        "movl %ebx, -0x58(%ebp)\n"
        "movl %ebx, -0x38(%ebp)\n" /* __val */
        "movl 4(%edi), %esi\n"
        "movl %esi, -0x34(%ebp)\n"
        "movl 8(%edi), %ebx\n"
        "movl %ebx, -0x30(%ebp)\n"
        "movl -0x5c(%ebp), %eax\n" /* line 2160 */
        "movl %eax, 4(%esp)\n"
        "leal -0x38(%ebp), %edx\n" /* __val */
        "movl %edx, (%esp)\n"
        "calll Material_CachedShaderTextLess\n"
        "testb %al, %al\n"
        "je .Lf101c2c_00101fb0\n"
        "leal 0xc(%edi), %ebx\n" /* line 2162 */
        "movl %ebx, -0x44(%ebp)\n"
        /* { scope 5 */
        "movl %edi, %ecx\n" /* line 411 */
        "subl -0x5c(%ebp), %ecx\n"
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf101c2c_00101de0\n"
        "movl %edi, %ecx\n"
        "movl %ebx, %edx\n"
        "xorl %ebx, %ebx\n"
        ".Lf101c2c_00101dc1:\n"
        "movl -0xc(%ecx), %eax\n" /* line 412 */
        "movl %eax, -0xc(%edx)\n"
        "movl -8(%ecx), %eax\n"
        "movl %eax, -8(%edx)\n"
        "movl -4(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n"
        "subl $0xc, %ecx\n"
        "subl $0xc, %edx\n"
        "cmpl %esi, %ebx\n" /* line 411 */
        "jne .Lf101c2c_00101dc1\n"
        /* } scope */
        ".Lf101c2c_00101de0:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2163 | __val */
        "movl -0x5c(%ebp), %edx\n"
        "movl %eax, (%edx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 8(%edx)\n"
        "movl -0x44(%ebp), %edx\n"
        /* } scope */
        ".Lf101c2c_00101df7:\n"
        "cmpl %edx, -0x48(%ebp)\n" /* line 2156 | __last */
        "je .Lf101c2c_00101e6e\n"
        "movl %edx, %edi\n"
        "jmp .Lf101c2c_00101d60\n"
        ".Lf101c2c_00101e03:\n"
        "movl -0x3c(%ebp), %eax\n"
        /* } scope */
        /* { scope 3: __val, __val */
        ".Lf101c2c_00101e06:\n"
        "cmpl %eax, -0x48(%ebp)\n" /* line 2200 | __last */
        "je .Lf101c2c_00101e6e\n"
        ".Lf101c2c_00101e0b:\n"
        "movl -0x3c(%ebp), %edx\n" /* line 2201 */
        "movl 4(%edx), %eax\n"
        "movl (%edx), %ecx\n"
        "movl %edx, %ebx\n"
        "movl 8(%edx), %edx\n"
        "movl %edx, -0x30(%ebp)\n"
        "movl %eax, -0x34(%ebp)\n"
        "movl %ecx, -0x38(%ebp)\n" /* __val */
        "subl $0xc, %ebx\n"
        "movl -0x3c(%ebp), %esi\n" /* __last */
        "jmp .Lf101c2c_00101e3e\n"
        /* { scope 4 */
        ".Lf101c2c_00101e29:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl %ebx, %esi\n" /* line 2112 */
        "subl $0xc, %ebx\n"
        ".Lf101c2c_00101e3e:\n"
        "movl %ebx, 4(%esp)\n" /* line 2108 */
        "leal -0x38(%ebp), %eax\n" /* __val */
        "movl %eax, (%esp)\n"
        "calll Material_CachedShaderTextLess\n"
        "testb %al, %al\n"
        "jne .Lf101c2c_00101e29\n"
        "movl -0x38(%ebp), %eax\n" /* line 2114 | __val */
        "movl %eax, (%esi)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        /* } scope */
        "addl $0xc, -0x3c(%ebp)\n" /* line 2200 */
        "movl -0x3c(%ebp), %edx\n"
        "cmpl %edx, -0x48(%ebp)\n" /* __last */
        "jne .Lf101c2c_00101e0b\n"
        /* } scope */
        /* } scope */
        ".Lf101c2c_00101e6e:\n"
        "movl $0x14, 4(%esp)\n" /* line 3612 */
        "movl -0x4c(%ebp), %ebx\n" /* shaderListLib */
        "movl %ebx, (%esp)\n"
        "calll FS_FreeFileList\n"
        "movl $0x14, 4(%esp)\n" /* line 3613 */
        "movl -0x50(%ebp), %eax\n" /* shaderListRoot */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFileList\n"
        /* } scope */
        "addl $0x7c, %esp\n" /* line 3614 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __val, __last */
        ".Lf101c2c_00101e9c:\n"
        "movl -0x5c(%ebp), %ebx\n" /* line 2154 */
        "addl $0xc0, %ebx\n"
        "movl %ebx, -0x3c(%ebp)\n"
        "movl -0x5c(%ebp), %edi\n" /* line 2156 */
        "addl $0xc, %edi\n"
        "cmpl %edi, %ebx\n"
        "je .Lf101c2c_0010206e\n"
        /* { scope 2: __last, __val, __val */
        ".Lf101c2c_00101eb6:\n"
        "movl (%edi), %eax\n" /* line 2159 */
        "movl %eax, -0x54(%ebp)\n"
        "movl %eax, -0x38(%ebp)\n" /* __val */
        "movl 4(%edi), %esi\n"
        "movl %esi, -0x34(%ebp)\n"
        "movl 8(%edi), %ebx\n"
        "movl %ebx, -0x30(%ebp)\n"
        "movl -0x5c(%ebp), %edx\n" /* line 2160 */
        "movl %edx, 4(%esp)\n"
        "leal -0x38(%ebp), %eax\n" /* __val */
        "movl %eax, (%esp)\n"
        "calll Material_CachedShaderTextLess\n"
        "testb %al, %al\n"
        "je .Lf101c2c_00101f5a\n"
        "leal 0xc(%edi), %edx\n" /* line 2162 */
        "movl %edx, -0x40(%ebp)\n"
        /* { scope 3: __val, __val */
        "movl %edi, %ecx\n" /* line 411 */
        "subl -0x5c(%ebp), %ecx\n"
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %esi\n"
        "testl %esi, %esi\n"
        "jle .Lf101c2c_00101f33\n"
        "movl %edi, %ecx\n"
        "movl -0x40(%ebp), %edx\n"
        "xorl %ebx, %ebx\n"
        ".Lf101c2c_00101f14:\n"
        "movl -0xc(%ecx), %eax\n" /* line 412 */
        "movl %eax, -0xc(%edx)\n"
        "movl -8(%ecx), %eax\n"
        "movl %eax, -8(%edx)\n"
        "movl -4(%ecx), %eax\n"
        "movl %eax, -4(%edx)\n"
        "addl $1, %ebx\n"
        "subl $0xc, %ecx\n"
        "subl $0xc, %edx\n"
        "cmpl %ebx, %esi\n" /* line 411 */
        "jne .Lf101c2c_00101f14\n"
        /* } scope */
        ".Lf101c2c_00101f33:\n"
        "movl -0x38(%ebp), %eax\n" /* line 2163 | __val */
        "movl -0x5c(%ebp), %ebx\n"
        "movl %eax, (%ebx)\n"
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%ebx)\n"
        "movl -0x30(%ebp), %eax\n"
        "movl %eax, 8(%ebx)\n"
        "movl -0x40(%ebp), %ebx\n"
        /* } scope */
        ".Lf101c2c_00101f4a:\n"
        "cmpl %ebx, -0x3c(%ebp)\n" /* line 2156 */
        "je .Lf101c2c_00101e03\n"
        "movl %ebx, %edi\n"
        "jmp .Lf101c2c_00101eb6\n"
        /* { scope 2: __last, __val, __val */
        ".Lf101c2c_00101f5a:\n"
        "movl %ebx, -0x24(%ebp)\n" /* line 2166 */
        "movl %esi, -0x28(%ebp)\n"
        "movl -0x54(%ebp), %eax\n"
        "movl %eax, -0x2c(%ebp)\n" /* __val */
        /* { scope 3: __val, __val */
        "leal -0xc(%edi), %ebx\n" /* line 2107 */
        "movl %edi, %esi\n"
        "jmp .Lf101c2c_00101f82\n"
        ".Lf101c2c_00101f6d:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl %ebx, %esi\n" /* line 2112 */
        "subl $0xc, %ebx\n"
        ".Lf101c2c_00101f82:\n"
        "movl %ebx, 4(%esp)\n" /* line 2108 */
        "leal -0x2c(%ebp), %edx\n" /* __val */
        "movl %edx, (%esp)\n"
        "calll Material_CachedShaderTextLess\n"
        "testb %al, %al\n"
        "jne .Lf101c2c_00101f6d\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2114 | __val */
        "movl %eax, (%esi)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        "addl $0xc, %edi\n"
        "movl %edi, -0x40(%ebp)\n"
        "movl %edi, %ebx\n"
        "jmp .Lf101c2c_00101f4a\n"
        /* } scope */
        /* } scope */
        /* { scope 2: __last, __val, __val */
        /* { scope 3: __val, __val */
        ".Lf101c2c_00101fb0:\n"
        "movl %ebx, -0x24(%ebp)\n" /* line 2166 */
        "movl %esi, -0x28(%ebp)\n"
        "movl -0x58(%ebp), %ebx\n"
        "movl %ebx, -0x2c(%ebp)\n" /* __val */
        /* { scope 4 */
        "leal -0xc(%edi), %ebx\n" /* line 2107 */
        "movl %edi, %esi\n"
        "jmp .Lf101c2c_00101fd8\n"
        ".Lf101c2c_00101fc3:\n"
        "movl (%ebx), %eax\n" /* line 2110 */
        "movl %eax, (%esi)\n"
        "movl 4(%ebx), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl %ebx, %esi\n" /* line 2112 */
        "subl $0xc, %ebx\n"
        ".Lf101c2c_00101fd8:\n"
        "movl %ebx, 4(%esp)\n" /* line 2108 */
        "leal -0x2c(%ebp), %eax\n" /* __val */
        "movl %eax, (%esp)\n"
        "calll Material_CachedShaderTextLess\n"
        "testb %al, %al\n"
        "jne .Lf101c2c_00101fc3\n"
        "movl -0x2c(%ebp), %eax\n" /* line 2114 | __val */
        "movl %eax, (%esi)\n"
        "movl -0x28(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x24(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        "addl $0xc, %edi\n"
        "movl %edi, -0x44(%ebp)\n"
        "movl %edi, %edx\n"
        "jmp .Lf101c2c_00101df7\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2: __last, __val, __val */
        /* { scope 3: __val, __val */
        ".Lf101c2c_00102009:\n"
        "movl %eax, %ebx\n" /* line 3584 */
        "xorl %esi, %esi\n" /* fileIndex */
        ".Lf101c2c_0010200d:\n"
        "movl -0x4c(%ebp), %edx\n" /* line 3585 | shaderListLib */
        "movl (%edx, %esi, 4), %eax\n"
        "movl %ebx, %ecx\n"
        "movl $str_00227f98, %edx\n" /* "lib/" */
        "calll Material_PreLoadSingleShaderText\n"
        "addl $1, %esi\n" /* line 3584 | fileIndex */
        "addl $0xc, %ebx\n"
        "cmpl %esi, %edi\n" /* fileIndex, __last */
        "jne .Lf101c2c_0010200d\n"
        "movl mtlLoadGlob+4, %ebx\n"
        "movl %ebx, -0x5c(%ebp)\n"
        "movl %ebx, %edx\n"
        "jmp .Lf101c2c_00101cd5\n"
        /* } scope */
        /* } scope */
        /* { scope 2: __last, __val, __val */
        ".Lf101c2c_00102039:\n"
        "movl %eax, %ebx\n"
        "xorl %esi, %esi\n" /* fileIndex */
        ".Lf101c2c_0010203d:\n"
        "movl -0x50(%ebp), %edx\n" /* line 3585 | shaderListRoot */
        "movl (%edx, %esi, 4), %eax\n"
        "movl %ebx, %ecx\n"
        "movl $str_002157b8, %edx\n"
        "calll Material_PreLoadSingleShaderText\n"
        "addl $1, %esi\n" /* line 3584 | fileIndex */
        "addl $0xc, %ebx\n"
        "cmpl %esi, %edi\n" /* fileIndex, __last */
        "jne .Lf101c2c_0010203d\n"
        "movl -0x1c(%ebp), %edi\n" /* fileCountRoot, __last */
        "movl mtlLoadGlob+4, %ebx\n"
        "jmp .Lf101c2c_00101cbf\n"
        /* } scope */
        /* { scope 2: __last, __val, __val */
        /* { scope 3: __val, __val */
        ".Lf101c2c_00102067:\n"
        "xorb %al, %al\n" /* line 2253 */
        "jmp .Lf101c2c_00101d27\n"
        ".Lf101c2c_0010206e:\n"
        "movl %ebx, %eax\n"
        "jmp .Lf101c2c_00101e06\n"
    );
}
#endif /* original naked Material_PreLoadAllShaderText */

/* line 1759 — Material_ParseCodeConstantSource_r
 * Recursively resolves a code constant source from a dot-separated path.
 * Handles simple constants (source <= 186), matrix constants (source > 186) with
 * optional row selection [N], array indexing [N], and subtable recursion.
 * Actual convention: eax=text, edx=routing, ecx=offset, stack=sourceTable,arg */
static Bool Material_ParseCodeConstantSource_r_impl(const char **text, const byte *routing, int offset, const CodeConstantSource *sourceTable, byte *arg)
{
    if (!Com_MatchToken(text, ".", 1))
        return 0;

    const char *token = Com_Parse(text);

    /* Search source table for matching name (stride 0x14 = 20 bytes) */
    int sourceIndex;
    for (sourceIndex = 0; sourceTable[sourceIndex].name; sourceIndex++) {
        if (strcmp(token, sourceTable[sourceIndex].name) == 0)
            goto found;
    }
    Com_ScriptWarning("unknown constant source '%s'\n", token);
    return 0;

found:;
    const CodeConstantSource *entry = &sourceTable[sourceIndex];
    int arrayCount = entry->arrayCount;
    int arrayIndex = 0;

    /* If no array but routing requires multi-component access, handle index parsing */
    if (arrayCount == 0 && entry->subtable == 0) {
        byte componentCount = *(routing + 5);
        if (componentCount > 1) {
            /* Check for explicit array index "[N, M]" syntax */
            const char *peek = Com_Parse(text);
            if (*peek == '[') {
                /* Parse starting index */
                arrayIndex = Com_ParseInt(text);
                if (arrayIndex < 0 || arrayIndex >= entry->arrayCount) {
                    Com_ScriptWarning("index %i is not in the range [0, %i]\n", arrayIndex, entry->arrayCount - 1);
                    return 0;
                }
                /* Multi-component: parse ", endIndex" and validate range */
                if (componentCount > 1) {
                    if (!Com_MatchToken(text, ",", 1))
                        return 0;
                    int endIndex = Com_ParseInt(text);
                    int expectedEnd = arrayIndex + componentCount - 1;
                    if (endIndex != expectedEnd) {
                        Com_ScriptWarning("ending index %i should be %i instead\n", endIndex, expectedEnd);
                        return 0;
                    }
                }
                if (!Com_MatchToken(text, "]", 1))
                    return 0;
                offset += arrayIndex;
                goto after_array;
            } else {
                Com_UngetToken();
                /* Validate component count fits */
                if ((int)componentCount > entry->arrayCount) {
                    Com_ScriptWarning("code constant '%s' has only %i members, but %i were requested\n",
                                      entry->name, entry->arrayCount, (int)componentCount);
                    return 0;
                }
                offset += 0; /* no index offset */
                goto after_array;
            }
        }
    }

    /* Handle array indexing [N] if entry has arrayCount */
    if (arrayCount != 0) {
        int arrayStride = entry->arrayStride;
        if (!Com_MatchToken(text, "[", 1))
            return 0;
        arrayIndex = Com_ParseInt(text);
        if (arrayIndex < 0 || arrayIndex >= arrayCount) {
            Com_ScriptWarning("array index must be in range [0, %i]\n", arrayCount - 1);
            return 0;
        }
        if (!Com_MatchToken(text, "]", 1))
            return 0;
        offset += arrayIndex * arrayStride;
    }

after_array:
    /* Check for subtable (recurse deeper) */
    if (entry->subtable) {
        return Material_ParseCodeConstantSource_r_impl(text, routing, offset,
            (const CodeConstantSource *)(intptr_t)entry->subtable, arg);
    }

    /* Leaf: compute final source value */
    int source = offset + (unsigned char)entry->source;

    if (source <= 0xBA) {
        /* Simple code constant */
        *(unsigned short *)(arg + 4) = (unsigned short)source;
        *(arg + 6) = 0;
        *(arg + 7) = *(routing + 5); /* component count */
        return 1;
    }

    /* Matrix constant (source > 186): may need row selection or component info */
    /* Check if routing's pixel shader type == 3 → XOR source with 2 */
    short *routingShaderType = *(short **)(routing + 0xc);
    if (*routingShaderType == 3)
        source ^= 2;

    /* Parse next token to determine mode */
    const char *nextToken = Com_Parse(text);
    if (*nextToken == ';') {
        /* Semicolon: use full matrix constant with routing's component count */
        Com_UngetToken();
        *(unsigned short *)(arg + 4) = (unsigned short)source;
        *(arg + 6) = 0;
        byte *routingShader = *(byte **)(routing + 8);
        *(arg + 7) = (byte)*(unsigned short *)(routingShader + 8);
        return 1;
    }

    if (*nextToken == '[') {
        /* Row selection: source[rowIndex] */
        *(unsigned short *)(arg + 4) = (unsigned short)source;
        int rowIndex = Com_ParseInt(text);
        if ((unsigned)rowIndex > 3) {
            Com_ScriptWarning("row index %i should be in the range [0, 3]\n", rowIndex);
            return 0;
        }
        *(arg + 6) = (byte)rowIndex;
        *(arg + 7) = 1;
        return Com_MatchToken(text, "]", 1) ? 1 : 0;
    }

    Com_ScriptWarning("expected ';' or '[', found '%s' instead\n", nextToken);
    return 0;
}

/* Trampoline: eax=text, edx=routing, ecx=offset, stack=sourceTable,arg */
static __attribute__((naked))
Bool Material_ParseCodeConstantSource_r(const char * *text, ShaderConstantRouting *routing, int offset, const CodeConstantSource *sourceTable, MaterialShaderArgument *arg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 0xc(%ebp)\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_ParseCodeConstantSource_r_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1670 — Material_ParseVector
 * Parses a vector of floats from text in format "( x, y, z )" or "( x, y, z, w )".
 * Actual convention: eax=text(const char**), edx=elemCount, ecx=vector(float*) */
static Bool Material_ParseVector_impl(const char **text, int elemCount, float *vector)
{
    int i;

    if (!Com_MatchToken(text, "(", 1))
        return 0;

    /* Parse first element */
    vector[0] = Com_ParseFloat(text);

    /* Parse remaining elements separated by commas */
    for (i = 1; i < elemCount; i++) {
        if (!Com_MatchToken(text, ",", 1))
            return 0;
        vector[i] = Com_ParseFloat(text);
    }

    return Com_MatchToken(text, ")", 1) ? 1 : 0;
}

/* Trampoline: eax=text, edx=elemCount, ecx=vector */
static __attribute__((naked))
Bool Material_ParseVector(int elemCount)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_ParseVector_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}

/* line 2659 — Dx7 texture stage state parser: reads textureFunction/alphaFunction tokens
 * from material text, validates against function table, builds texture stage bits.
 * Register convention: eax=text, edx=samplerIndex, ecx=validTest, stack=texStageBits.
 * 416 lines of token parsing with string comparisons and bit manipulation. */
static __attribute__((naked))
Bool Material_LoadPassTextureStateDx7(int samplerIndex, MtlTextureFunctionValidDx7 validTest, int *texStageBits)
{
    (void)samplerIndex; (void)validTest; (void)texStageBits;
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2659 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl %eax, %ebx\n" /* text */
        "movl %edx, -0x34(%ebp)\n"
        "movl %ecx, %esi\n" /* texStateName */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_002280d0, 4(%esp)\n" /* "stage" */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 976 */
        "jne .Lf1024a2_001024d8\n"
        ".Lf1024a2_001024ce:\n"
        "xorl %eax, %eax\n" /* line 2671 */
        ".Lf1024a2_001024d0:\n"
        "addl $0x3c, %esp\n" /* line 2672 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: argCount */
        ".Lf1024a2_001024d8:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 958 */
        "jne .Lf1024a2_001025c6\n"
        /* } scope */
        ".Lf1024a2_001024f8:\n"
        "testb %al, %al\n" /* line 2661 */
        "je .Lf1024a2_001024ce\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2663 */
        "je .Lf1024a2_001024ce\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl %esi, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2665 */
        "je .Lf1024a2_001024ce\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222904, 4(%esp)\n" /* "=" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2667 */
        "je .Lf1024a2_001024ce\n"
        /* { scope 1: argCount */
        "movl %ebx, (%esp)\n" /* line 2589 */
        "calll Com_Parse\n"
        "movl %eax, -0x30(%ebp)\n" /* token */
        "xorl %edi, %edi\n" /* fnIndex */
        "movl $s_textureFuncsDx7, %esi\n" /* matchIndex */
        "movl %eax, %edx\n"
        "jmp .Lf1024a2_00102574\n"
        ".Lf1024a2_00102562:\n"
        "addl $1, %edi\n" /* line 2590 | fnIndex */
        "addl $0x10, %esi\n" /* matchIndex */
        "cmpl $0x15, %edi\n" /* fnIndex */
        "je .Lf1024a2_00102613\n"
        "movl -0x30(%ebp), %edx\n" /* token */
        ".Lf1024a2_00102574:\n"
        "movl (%esi), %eax\n" /* line 2592 | matchIndex */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1024a2_00102562\n"
        "movl %edi, %edx\n" /* line 2594 | fnIndex */
        "shll $4, %edx\n"
        "movl 8(%ebp), %ecx\n" /* validTest */
        "testl %ecx, s_textureFuncsDx7+12(%edx)\n"
        "jne .Lf1024a2_00102661\n"
        "movl $str_0021a8d8, %eax\n" /* line 2596 */
        "subl $1, %ecx\n"
        "movl $str_002278dc, %edx\n" /* "color" */
        "cmovnel %edx, %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x30(%ebp), %eax\n" /* token */
        "movl %eax, 4(%esp)\n"
        "movl $str_002280f8, (%esp)\n" /* "%s is only valid for %s" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1024a2_001024ce\n"
        /* } scope */
        /* { scope 1: argCount */
        ".Lf1024a2_001025c6:\n"
        "movl %ebx, (%esp)\n" /* line 961 */
        "calll Com_ParseInt\n"
        "cmpl %eax, -0x34(%ebp)\n" /* line 962 */
        "je .Lf1024a2_001025f1\n"
        "movl %eax, 8(%esp)\n" /* line 964 */
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002280d8, (%esp)\n" /* "expected %i, found %i instead
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1024a2_001024f8\n"
        ".Lf1024a2_001025f1:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "jmp .Lf1024a2_001024f8\n"
        /* } scope */
        /* { scope 1: argCount */
        ".Lf1024a2_00102613:\n"
        "movl -0x30(%ebp), %eax\n" /* line 2606 | token */
        "movl %eax, 4(%esp)\n"
        "movl $str_002281bc, (%esp)\n" /* "expected a texture function, found '%s' instead.
" */
        "calll Com_ScriptWarning\n"
        "movl -0x30(%ebp), %edx\n" /* line 2607 | token */
        "movl %edx, 4(%esp)\n"
        "movl $str_002281f0, (%esp)\n" /* "Valid texture functions:.
" */
        "calll Com_Printf\n"
        "movl $s_textureFuncsDx7, %esi\n" /* matchIndex */
        "movl $s_textureFuncsDx7+336, %ebx\n"
        ".Lf1024a2_00102643:\n"
        "movl (%esi), %eax\n" /* line 2609 | matchIndex */
        "movl %eax, 4(%esp)\n"
        "movl $str_002182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "addl $0x10, %esi\n" /* matchIndex */
        "cmpl %esi, %ebx\n" /* line 2608 | matchIndex */
        "jne .Lf1024a2_00102643\n"
        "jmp .Lf1024a2_001024ce\n"
        ".Lf1024a2_00102661:\n"
        "movl s_textureFuncsDx7+4(%edx), %eax\n" /* line 2599 */
        "movl 0xc(%ebp), %ecx\n" /* texStageBits */
        "movl %eax, (%ecx)\n"
        "movl s_textureFuncsDx7+8(%edx), %edx\n" /* line 2600 */
        "movl %edx, -0x2c(%ebp)\n" /* argCount */
        /* { scope 2: argIndex, texArg */
        /* { scope 3: token */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_002221e8, 4(%esp)\n" /* "(" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2561 */
        "je .Lf1024a2_001024ce\n"
        "movl -0x2c(%ebp), %esi\n" /* line 2564 | argCount, matchIndex */
        "testl %esi, %esi\n" /* matchIndex */
        "jle .Lf1024a2_00102857\n"
        "movl $0, -0x28(%ebp)\n" /* argIndex */
        "movl $0xa, -0x1c(%ebp)\n"
        ".Lf1024a2_001026ae:\n"
        "movl $0, -0x24(%ebp)\n" /* line 2568 | texArg */
        /* { scope 4 */
        ".Lf1024a2_001026b5:\n"
        "movl %ebx, (%esp)\n" /* line 2505 */
        "calll Com_Parse\n"
        "movl %eax, -0x20(%ebp)\n" /* token */
        "movl $0xb, %ecx\n" /* line 2506 */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $str_00228110, %edi\n" /* "complement" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1024a2_001026e0\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1024a2_001026e0:\n"
        "testl %eax, %eax\n"
        "jne .Lf1024a2_00102717\n"
        ".Lf1024a2_001026e4:\n"
        "orl $8, -0x24(%ebp)\n" /* line 2507 | texArg */
        "movl %ebx, (%esp)\n" /* line 2505 */
        "calll Com_Parse\n"
        "movl %eax, -0x20(%ebp)\n" /* token */
        "movl $0xb, %ecx\n" /* line 2506 */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $str_00228110, %edi\n" /* "complement" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1024a2_00102713\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1024a2_00102713:\n"
        "testl %eax, %eax\n"
        "je .Lf1024a2_001026e4\n"
        ".Lf1024a2_00102717:\n"
        "movl $0xf, %ecx\n" /* line 2508 */
        "cld\n"
        "movl -0x20(%ebp), %esi\n" /* token */
        "movl $str_0022811c, %edi\n" /* "alphaReplicate" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1024a2_00102738\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1024a2_00102738:\n"
        "testl %eax, %eax\n"
        "jne .Lf1024a2_00102745\n"
        "orl $0x10, -0x24(%ebp)\n" /* line 2509 | texArg */
        "jmp .Lf1024a2_001026b5\n"
        ".Lf1024a2_00102745:\n"
        "movl $7, %ecx\n" /* line 2514 */
        "cld\n"
        "movl -0x20(%ebp), %esi\n" /* token */
        "movl $str_0022812c, %edi\n" /* "vertex" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1024a2_00102766\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1024a2_00102766:\n"
        "testl %eax, %eax\n"
        "jne .Lf1024a2_001027e1\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2516 */
        "je .Lf1024a2_001024ce\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_002278dc, 4(%esp)\n" /* "color" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2518 */
        "je .Lf1024a2_001024ce\n"
        "orl $2, -0x24(%ebp)\n" /* line 2520 | texArg */
        /* } scope */
        ".Lf1024a2_001027ae:\n"
        "movzbl -0x1c(%ebp), %ecx\n" /* line 2577 */
        "shll %cl, -0x24(%ebp)\n" /* texArg */
        "movl -0x24(%ebp), %edx\n" /* texArg */
        "movl 0xc(%ebp), %eax\n" /* texStageBits */
        "orl %edx, (%eax)\n"
        "addl $1, -0x28(%ebp)\n" /* line 2564 | argIndex */
        "movl -0x28(%ebp), %ecx\n" /* argIndex */
        "cmpl %ecx, -0x2c(%ebp)\n" /* argCount */
        "je .Lf1024a2_00102857\n"
        "movl -0x28(%ebp), %eax\n" /* line 2566 | argIndex */
        "testl %eax, %eax\n"
        "jne .Lf1024a2_001028dd\n"
        "addl $5, -0x1c(%ebp)\n" /* line 2568 */
        "jmp .Lf1024a2_001026ae\n"
        /* { scope 4 */
        ".Lf1024a2_001027e1:\n"
        "movl $str_00228134, %edi\n" /* line 2524 */
        "movl $8, %ecx\n"
        "cld\n"
        "movl -0x20(%ebp), %esi\n" /* token */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1024a2_00102802\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1024a2_00102802:\n"
        "testl %edx, %edx\n"
        "jne .Lf1024a2_0010289c\n"
        /* { scope 5 */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 958 */
        "je .Lf1024a2_001024ce\n"
        "movl %ebx, (%esp)\n" /* line 961 */
        "calll Com_ParseInt\n"
        "cmpl %eax, -0x34(%ebp)\n" /* line 962 */
        "je .Lf1024a2_0010297f\n"
        "movl %eax, 8(%esp)\n" /* line 964 */
        "movl -0x34(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl $str_002280d8, (%esp)\n" /* "expected %i, found %i instead
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1024a2_001024ce\n"
        /* } scope */
        /* } scope */
        ".Lf1024a2_00102857:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222224, 4(%esp)\n" /* ")" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        /* } scope */
        /* } scope */
        "testl %eax, %eax\n" /* line 2600 */
        "je .Lf1024a2_001024ce\n"
        /* } scope */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2671 */
        "setne %al\n"
        "andl $1, %eax\n"
        "jmp .Lf1024a2_001024d0\n"
        /* { scope 1: argCount */
        /* { scope 2: argIndex, texArg */
        /* { scope 3: token */
        /* { scope 4 */
        ".Lf1024a2_0010289c:\n"
        "movl $str_002280d0, %edi\n" /* line 2532 */
        "movl $6, %ecx\n"
        "cld\n"
        "movl -0x20(%ebp), %esi\n" /* token */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1024a2_001028bd\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1024a2_001028bd:\n"
        "testl %edx, %edx\n"
        "jne .Lf1024a2_00102951\n"
        "movl -0x34(%ebp), %edi\n" /* line 2534 */
        "testl %edi, %edi\n"
        "jne .Lf1024a2_00102906\n"
        "movl $str_0022813c, (%esp)\n" /* line 2536 */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1024a2_001024ce\n"
        /* } scope */
        ".Lf1024a2_001028dd:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021f88c, 4(%esp)\n" /* "," */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2568 */
        "je .Lf1024a2_001024ce\n"
        "addl $5, -0x1c(%ebp)\n"
        "jmp .Lf1024a2_001026ae\n"
        /* { scope 4 */
        ".Lf1024a2_00102906:\n"
        "movl -0x34(%ebp), %esi\n" /* line 2539 | matchIndex */
        "subl $1, %esi\n" /* matchIndex */
        /* { scope 5 */
        /* { scope 6 */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 958 */
        "je .Lf1024a2_001024ce\n"
        "movl %ebx, (%esp)\n" /* line 961 */
        "calll Com_ParseInt\n"
        "cmpl %eax, %esi\n" /* line 962 */
        "je .Lf1024a2_001029a8\n"
        "movl %eax, 8(%esp)\n" /* line 964 */
        "movl %esi, 4(%esp)\n"
        "movl $str_002280d8, (%esp)\n" /* "expected %i, found %i instead
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1024a2_001024ce\n"
        /* } scope */
        /* } scope */
        ".Lf1024a2_00102951:\n"
        "movl $str_00228188, %edi\n" /* line 2545 */
        "movl $9, %ecx\n"
        "cld\n"
        "movl -0x20(%ebp), %esi\n" /* token, matchIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* matchIndex */
        "movl $0, %edx\n"
        "je .Lf1024a2_00102972\n"
        "movzbl -1(%esi), %edx\n" /* matchIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1024a2_00102972:\n"
        "testl %edx, %edx\n"
        "jne .Lf1024a2_001029d1\n"
        "orl $6, -0x24(%ebp)\n" /* line 2547 | texArg */
        "jmp .Lf1024a2_001027ae\n"
        /* { scope 5 */
        ".Lf1024a2_0010297f:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2526 */
        "je .Lf1024a2_001024ce\n"
        "orl $5, -0x24(%ebp)\n" /* line 2528 | texArg */
        "jmp .Lf1024a2_001027ae\n"
        /* { scope 5 */
        /* { scope 6 */
        ".Lf1024a2_001029a8:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "movl %ebx, (%esp)\n"
        "calll Com_MatchToken\n"
        /* } scope */
        /* } scope */
        "testl %eax, %eax\n" /* line 2539 */
        "je .Lf1024a2_001024ce\n"
        "orl $1, -0x24(%ebp)\n" /* line 2541 | texArg */
        "jmp .Lf1024a2_001027ae\n"
        ".Lf1024a2_001029d1:\n"
        "movl -0x20(%ebp), %edx\n" /* line 2551 | token */
        "movl %edx, 4(%esp)\n"
        "movl $str_00228194, (%esp)\n" /* "unknown texture function argument '%s'
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1024a2_001024ce\n"
    );
}

/* line 1574 — Material_CodeSamplerSource_r
 * Recursively resolves a code sampler source from a dot-separated path.
 * Matches token against sourceTable entries, handles array indexing [N],
 * recurses into subtables, and stores final source index in arg.
 * Actual convention: eax=text, edx=offset, ecx=sourceTable, stack=arg */
static Bool Material_CodeSamplerSource_r_impl(const char **text, int offset, const CodeSamplerSource *sourceTable, MaterialShaderArgument *arg)
{
    if (!Com_MatchToken(text, ".", 1))
        return 0;

    const char *token = Com_Parse(text);

    /* Search source table for matching name */
    int sourceIndex;
    for (sourceIndex = 0; sourceTable[sourceIndex].name; sourceIndex++) {
        if (strcmp(token, sourceTable[sourceIndex].name) == 0)
            goto found;
    }
    Com_ScriptWarning("unknown sampler source '%s'\n", token);
    return 0;

found:;
    const CodeSamplerSource *entry = &sourceTable[sourceIndex];
    int arrayIndex = 0;

    if (entry->arrayCount != 0) {
        /* Parse array index: source[N] */
        int arrayStride = entry->arrayStride;
        if (!Com_MatchToken(text, "[", 1))
            return 0;
        arrayIndex = Com_ParseInt(text);
        if (arrayIndex < 0 || arrayIndex >= entry->arrayCount) {
            Com_ScriptWarning("array index must be in range [0, %i]\n", entry->arrayCount - 1);
            return 0;
        }
        if (!Com_MatchToken(text, "]", 1))
            return 0;
        offset += arrayIndex * arrayStride;
    }

    /* Check for subtable (recurse deeper) */
    if (entry->subtable) {
        return Material_CodeSamplerSource_r_impl(text, offset, (const CodeSamplerSource *)(intptr_t)entry->subtable, arg);
    }

    /* Leaf: store final sampler source index */
    offset += entry->source;
    *(int *)((byte *)arg + 4) = offset; /* arg->u.codeSampler = offset */
    return 1;
}

/* Trampoline: eax=text, edx=offset, ecx=sourceTable, stack=arg */
static __attribute__((naked))
Bool Material_CodeSamplerSource_r(const char * *text, int offset, const CodeSamplerSource *sourceTable, MaterialShaderArgument *arg)
{
    __asm__ __volatile__ (
        "pushl %ebp\n"
        "movl %esp, %ebp\n"
        "pushl 8(%ebp)\n"
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_CodeSamplerSource_r_impl\n"
        "movl %ebp, %esp\n"
        "popl %ebp\n"
        "retl\n"
    );
}

/* line 1610 — Material_ParseSamplerSource
 * Parses a sampler source declaration: either "sampler.codePath" or "material.textureName".
 * Actual convention: eax=text, edx=arg */
static Bool Material_ParseSamplerSource_impl(const char **text, MaterialShaderArgument *arg)
{
    const char *token = Com_Parse(text);

    if (memcmp(token, "sampler", 8) == 0) {
        /* Code sampler: parse dot-separated source path */
        arg->type = 3;
        return Material_CodeSamplerSource_r_impl(text, 0, s_codeSamplers, arg);
    }

    if (memcmp(token, "material", 9) == 0) {
        /* Material texture reference */
        if (!Com_MatchToken(text, ".", 1))
            return 0;
        const char *texName = Com_Parse(text);
        arg->type = 4;
        *(const char **)((byte *)arg + 4) = Material_RegisterString(texName); /* arg->u.name */
        return *(const char **)((byte *)arg + 4) != NULL;
    }

    Com_ScriptWarning("expected 'sampler' or 'material', found '%s' instead\n", token);
    return 0;
}

/* Trampoline: eax=text, edx=arg */
static __attribute__((naked))
Bool Material_ParseSamplerSource(const char * *text, MaterialShaderArgument *arg)
{
    __asm__ __volatile__ (
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_ParseSamplerSource_impl\n"
        "addl $8, %esp\n"
        "retl\n"
    );
}

/* line 2317 — Shader argument binder: iterates pixel+vertex shader parameters,
 * resolves each to code constant/sampler/literal sources, validates argument counts,
 * builds sorted MaterialShaderArgument array for runtime binding.
 * Register convention: eax=text, edx=techFlags, ecx=argCount, stack=args.
 * 842 lines — the largest material parsing function after FinishLoadingInstance. */
static __attribute__((naked))
Bool Material_SetPassShaderArguments(const char * *text, short unsigned int *techFlags, short unsigned int *argCount, MaterialShaderArgument * *args)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2317 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x1ac, %esp\n"
        "movl %eax, -0x178(%ebp)\n"
        "movl %edx, %esi\n" /* mtlShader */
        "movl %ecx, -0x17c(%ebp)\n"
        /* { scope 1: routing, usedConstant, usedCount */
        "leal -0x1c(%ebp), %eax\n" /* line 2326 | constants */
        "movl %eax, 4(%esp)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, (%esp)\n"
        "calll D3DXGetShaderConstantTable\n"
        "movl %eax, %ebx\n" /* success */
        "testl %eax, %eax\n" /* line 2327 */
        "js .Lf102c46_00102d8b\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2334 | constants */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *0xc(%edx)\n"
        "movl %eax, -0x170(%ebp)\n" /* constantTable */
        "movzbl 0xc(%eax), %eax\n" /* line 2335 */
        "movzbw %al, %dx\n"
        "movl 8(%ebp), %ecx\n" /* argCount */
        "movw %dx, (%ecx)\n"
        "testb %al, %al\n" /* line 2336 */
        "je .Lf102c46_00102d37\n"
        "movzwl %dx, %eax\n" /* line 2343 */
        "shll $3, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, -0x174(%ebp)\n"
        "movl 0xc(%ebp), %ecx\n" /* args */
        "movl %eax, (%ecx)\n"
        "movl (%esi), %esi\n" /* line 2344 | mtlShader */
        "movl %esi, -0x15c(%ebp)\n" /* mtlShader, shaderName */
        /* { scope 2: constantInfo, shaderName, constantName */
        "movl -0x170(%ebp), %edi\n" /* line 2063 | constantTable */
        "addl 0x10(%edi), %edi\n"
        "movl %edi, -0x164(%ebp)\n" /* constantInfo */
        "movl -0x170(%ebp), %edx\n" /* line 2065 | constantTable */
        "movl 0xc(%edx), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "leal -0x13c(%ebp), %ecx\n" /* usedConstant */
        "movl %ecx, (%esp)\n"
        "calll memset\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e50c, 4(%esp)\n" /* "{" */
        "movl -0x178(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2068 */
        "jne .Lf102c46_00102db4\n"
        ".Lf102c46_00102d1c:\n"
        "xorl %ebx, %ebx\n" /* line 2144 | sourceIndex */
        /* } scope */
        ".Lf102c46_00102d1e:\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2346 | constants */
        "movl (%eax), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *8(%edx)\n"
        "movzbl %bl, %eax\n" /* line 2347 | success */
        /* } scope */
        "addl $0x1ac, %esp\n" /* line 2348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: routing, usedConstant, usedCount */
        ".Lf102c46_00102d37:\n"
        "movl 0xc(%ebp), %edi\n" /* line 2338 | args, name */
        "movl $0, (%edi)\n" /* name */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e50c, 4(%esp)\n" /* "{" */
        "movl -0x178(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2339 */
        "je .Lf102c46_00102d1c\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e508, 4(%esp)\n" /* "}" */
        "movl -0x178(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2339 */
        "je .Lf102c46_00102d1c\n"
        /* { scope 2: constantInfo, shaderName, constantName */
        ".Lf102c46_00102d84:\n"
        "movl $1, %ebx\n" /* line 2144 | sourceIndex */
        "jmp .Lf102c46_00102d1e\n"
        /* } scope */
        ".Lf102c46_00102d8b:\n"
        "movl %eax, (%esp)\n" /* line 2329 */
        "calll R_ErrorDescription\n"
        "movl %ebx, 8(%esp)\n" /* success */
        "movl %eax, 4(%esp)\n"
        "movl $str_00228278, (%esp)\n" /* "Couldn't get the constant table: %s (%08x)
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x1ac, %esp\n" /* line 2348 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: routing, usedConstant, usedCount */
        /* { scope 2: constantInfo, shaderName, constantName */
        ".Lf102c46_00102db4:\n"
        "movl $0, -0x168(%ebp)\n" /* line 2068 | usedCount */
        ".Lf102c46_00102dbe:\n"
        "movl -0x178(%ebp), %eax\n" /* line 2072 */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %edi\n"
        "movzbl (%eax), %eax\n" /* line 2073 */
        "testb %al, %al\n"
        "je .Lf102c46_00102fbc\n"
        "cmpb $0x7d, %al\n" /* line 2078 */
        "je .Lf102c46_00102fcf\n"
        /* { scope 3: literal */
        "movl -0x170(%ebp), %eax\n" /* line 1543 | constantTable */
        "movl 0xc(%eax), %eax\n"
        "movl %eax, -0x160(%ebp)\n"
        "testl %eax, %eax\n"
        "je .Lf102c46_00102e26\n"
        "movl -0x164(%ebp), %ebx\n" /* constantInfo */
        "xorl %esi, %esi\n"
        ".Lf102c46_00102dfc:\n"
        "movl -0x170(%ebp), %eax\n" /* line 1546 | constantTable */
        "addl (%ebx), %eax\n"
        "movl %edi, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf102c46_00102ea5\n"
        "addl $1, %esi\n" /* line 1543 */
        "addl $0x14, %ebx\n"
        "cmpl %esi, -0x160(%ebp)\n"
        "jne .Lf102c46_00102dfc\n"
        ".Lf102c46_00102e26:\n"
        "movl -0x15c(%ebp), %edx\n" /* line 1549 | shaderName */
        "movl %edx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n"
        "movl $str_002282bc, (%esp)\n" /* "*WARNING*: constant '%s' is not used by shader '%s'
" */
        "calll printf\n"
        /* } scope */
        ".Lf102c46_00102e40:\n"
        "movl $str_002282f4, (%esp)\n" /* line 2084 */
        "calll Com_SetScriptWarningPrefix\n"
        "movl -0x15c(%ebp), %ecx\n" /* line 2085 | shaderName */
        "movl %ecx, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* name */
        "movl $str_00228300, (%esp)\n" /* "'%s' is not defined by %s
" */
        "calll Com_ScriptWarning\n"
        "movl $str_0022831c, (%esp)\n" /* line 2086 */
        "calll Com_SetScriptWarningPrefix\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222904, 4(%esp)\n" /* "=" */
        "movl -0x178(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2087 */
        "je .Lf102c46_00102d1c\n"
        "movl %edi, (%esp)\n" /* line 2089 | name */
        "calll Com_SkipRestOfLine\n"
        "jmp .Lf102c46_00102dbe\n"
        ".Lf102c46_00102ea5:\n"
        "cmpl $-1, %esi\n" /* line 2082 | constantIndex */
        "je .Lf102c46_00102e40\n"
        "cmpb $0, -0x13c(%ebp, %esi)\n" /* line 2092 */
        "jne .Lf102c46_00103423\n"
        "movb $1, -0x13c(%ebp, %esi)\n" /* line 2097 */
        "movl %ebx, -0x24(%ebp)\n" /* line 2099 | sourceIndex */
        "movl -0x170(%ebp), %edx\n" /* line 2100 | constantTable */
        "addl 0xc(%ebx), %edx\n" /* sourceIndex */
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x168(%ebp), %edx\n" /* line 2101 | usedCount */
        "movl -0x174(%ebp), %ecx\n"
        "leal (%ecx, %edx, 8), %edx\n"
        "movl %edx, -0x19c(%ebp)\n"
        "movzwl 6(%ebx), %eax\n" /* sourceIndex */
        "movw %ax, 2(%edx)\n"
        /* { scope 3: literal */
        "movl -0x20(%ebp), %eax\n" /* line 1989 */
        "cmpw $1, (%eax)\n"
        "je .Lf102c46_00103167\n"
        "movb $0, -0x28(%ebp)\n" /* line 1996 */
        ".Lf102c46_00102efd:\n"
        "movb $1, -0x27(%ebp)\n" /* line 1997 */
        ".Lf102c46_00102f01:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222904, 4(%esp)\n" /* "=" */
        "movl -0x178(%ebp), %edi\n"
        "movl %edi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2000 */
        "je .Lf102c46_00102d1c\n"
        "movl -0x20(%ebp), %eax\n" /* line 2003 */
        "movzwl 2(%eax), %eax\n"
        "movzwl %ax, %edx\n"
        "cmpw $0xa, %ax\n"
        "je .Lf102c46_00102f61\n"
        "ja .Lf102c46_00102f58\n"
        "cmpw $3, %ax\n"
        "je .Lf102c46_001032ca\n"
        ".Lf102c46_00102f43:\n"
        "movl %edx, 4(%esp)\n" /* line 2015 */
        "movl $str_002284a0, (%esp)\n" /* "unknown constant type '%i'
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf102c46_00102d1c\n"
        ".Lf102c46_00102f58:\n"
        "subl $0xc, %eax\n" /* line 2003 */
        "cmpw $2, %ax\n"
        "ja .Lf102c46_00102f43\n"
        ".Lf102c46_00102f61:\n"
        "movl -0x19c(%ebp), %edx\n" /* line 2012 */
        "movl -0x178(%ebp), %eax\n"
        "calll Material_ParseSamplerSource\n"
        /* } scope */
        ".Lf102c46_00102f72:\n"
        "testb %al, %al\n" /* line 2102 */
        "je .Lf102c46_00102d1c\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "movl -0x178(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2105 */
        "je .Lf102c46_00102d1c\n"
        "movl -0x19c(%ebp), %ecx\n" /* line 2108 */
        "cmpw $3, (%ecx)\n"
        "je .Lf102c46_0010327d\n"
        ".Lf102c46_00102fb0:\n"
        "addl $1, -0x168(%ebp)\n" /* line 2115 | usedCount */
        "jmp .Lf102c46_00102dbe\n"
        ".Lf102c46_00102fbc:\n"
        "movl $str_002282a4, (%esp)\n" /* line 2075 */
        "calll Com_ScriptWarning\n"
        "xorl %ebx, %ebx\n" /* sourceIndex */
        "jmp .Lf102c46_00102d1e\n"
        ".Lf102c46_00102fcf:\n"
        "movl -0x170(%ebp), %ecx\n" /* line 2118 | constantTable */
        "movl 0xc(%ecx), %edx\n"
        "cmpl %edx, -0x168(%ebp)\n" /* usedCount */
        "je .Lf102c46_00102d84\n"
        "testl %edx, %edx\n" /* line 2121 */
        "je .Lf102c46_0010320d\n"
        "movl -0x164(%ebp), %ecx\n" /* constantInfo */
        "movl %ecx, -0x154(%ebp)\n"
        "movl $1, -0x14c(%ebp)\n"
        "jmp .Lf102c46_00103039\n"
        ".Lf102c46_00103004:\n"
        "cmpw $3, %ax\n" /* line 2033 */
        "je .Lf102c46_00103196\n"
        ".Lf102c46_0010300e:\n"
        "movl -0x170(%ebp), %edi\n" /* constantTable */
        "movl 0xc(%edi), %edx\n"
        ".Lf102c46_00103017:\n"
        "movl -0x14c(%ebp), %eax\n" /* line 2121 */
        "addl $1, %eax\n"
        "addl $0x14, -0x154(%ebp)\n"
        "cmpl %edx, -0x14c(%ebp)\n"
        "jae .Lf102c46_0010320d\n"
        "movl %eax, -0x14c(%ebp)\n" /* line 2118 */
        ".Lf102c46_00103039:\n"
        "leal -0x13c(%ebp), %eax\n" /* line 2317 | usedConstant */
        "addl -0x14c(%ebp), %eax\n"
        "leal -1(%eax), %edi\n" /* name */
        "movl %edi, -0x150(%ebp)\n" /* name */
        "cmpb $0, -1(%eax)\n" /* line 2123 */
        "jne .Lf102c46_00103017\n"
        "movl -0x154(%ebp), %eax\n" /* line 2126 */
        "movl %eax, -0x24(%ebp)\n"
        "movl -0x170(%ebp), %edx\n" /* line 2127 | constantTable */
        "addl 0xc(%eax), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x168(%ebp), %edx\n" /* line 2128 | usedCount */
        "movl -0x174(%ebp), %ecx\n"
        "leal (%ecx, %edx, 8), %edx\n"
        "movl %edx, -0x16c(%ebp)\n"
        "movl %eax, %ecx\n"
        "movzwl 6(%eax), %eax\n"
        "movw %ax, 2(%edx)\n"
        "movl -0x170(%ebp), %edi\n" /* line 2129 | constantTable, name */
        "addl (%ecx), %edi\n" /* name */
        "movl %edi, -0x158(%ebp)\n" /* name, constantName */
        "movb $0, -0x28(%ebp)\n" /* line 2027 */
        "movl -0x20(%ebp), %edx\n" /* line 2028 */
        "cmpw $1, (%edx)\n"
        "je .Lf102c46_001032a1\n"
        "movb $1, -0x27(%ebp)\n" /* line 2031 */
        ".Lf102c46_001030ab:\n"
        "movzwl 2(%edx), %eax\n" /* line 2033 */
        "cmpw $0xa, %ax\n"
        "je .Lf102c46_001030c8\n"
        "jbe .Lf102c46_00103004\n"
        "subl $0xc, %eax\n"
        "cmpw $2, %ax\n"
        "ja .Lf102c46_0010300e\n"
        ".Lf102c46_001030c8:\n"
        "movl -0x16c(%ebp), %edi\n" /* line 1663 */
        "movw $3, (%edi)\n"
        /* { scope 3: literal */
        /* { scope 4: token */
        "movl s_defaultCodeSamplers, %edx\n" /* line 1644 */
        "testl %edx, %edx\n"
        "je .Lf102c46_00103206\n"
        "movl $s_defaultCodeSamplers+20, %ebx\n"
        "xorl %esi, %esi\n" /* sourceIndex */
        "movl $s_defaultCodeSamplers, %eax\n"
        "xorl %edi, %edi\n"
        "jmp .Lf102c46_00103105\n"
        ".Lf102c46_001030f1:\n"
        "addl $1, %esi\n" /* sourceIndex */
        "movl %esi, %edi\n" /* sourceIndex */
        "movl %ebx, %eax\n"
        "movl (%ebx), %edx\n"
        "addl $0x14, %ebx\n"
        "testl %edx, %edx\n"
        "je .Lf102c46_00103206\n"
        ".Lf102c46_00103105:\n"
        "movl 8(%eax), %ecx\n" /* line 1646 */
        "testl %ecx, %ecx\n"
        "jne .Lf102c46_001030f1\n"
        "movl 0xc(%eax), %eax\n" /* line 1648 */
        "testl %eax, %eax\n"
        "jne .Lf102c46_001030f1\n"
        "movl %edx, 4(%esp)\n" /* line 1650 */
        "movl -0x158(%ebp), %eax\n" /* constantName */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf102c46_001030f1\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 1653 */
        "movl s_defaultCodeSamplers+4(, %eax, 4), %eax\n"
        "movl -0x16c(%ebp), %ecx\n"
        "movl %eax, 4(%ecx)\n"
        ".Lf102c46_0010313c:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf102c46_00103141:\n"
        "testb %al, %al\n" /* line 2130 */
        "je .Lf102c46_0010300e\n"
        "movl -0x150(%ebp), %edx\n" /* line 2132 */
        "movb $1, (%edx)\n"
        "addl $1, -0x168(%ebp)\n" /* line 2133 | usedCount */
        "movl -0x170(%ebp), %ecx\n" /* constantTable */
        "movl 0xc(%ecx), %edx\n"
        "jmp .Lf102c46_00103017\n"
        /* { scope 3: literal */
        /* { scope 4: token */
        ".Lf102c46_00103167:\n"
        "movl -0x178(%ebp), %ecx\n" /* line 1943 */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "cmpb $0x5b, (%eax)\n" /* line 1944 */
        "je .Lf102c46_00103354\n"
        "calll Com_UngetToken\n" /* line 1946 */
        "movb $0, -0x28(%ebp)\n" /* line 1947 */
        "movl -0x20(%ebp), %eax\n" /* line 1948 */
        "movzwl 8(%eax), %eax\n"
        "movb %al, -0x27(%ebp)\n"
        "jmp .Lf102c46_00102f01\n"
        /* } scope */
        /* } scope */
        ".Lf102c46_00103196:\n"
        "movl -0x16c(%ebp), %ecx\n" /* line 1927 */
        "movw $1, (%ecx)\n"
        /* { scope 3: literal */
        "movl s_codeConsts, %eax\n" /* line 1895 */
        "testl %eax, %eax\n"
        "je .Lf102c46_001031d3\n"
        "movl $s_codeConsts+20, %ebx\n" /* sourceIndex */
        "xorl %esi, %esi\n" /* sourceIndex */
        "xorl %edi, %edi\n"
        "movl $s_codeConsts, %edx\n"
        ".Lf102c46_001031b8:\n"
        "movl 8(%edx), %edx\n" /* line 1897 */
        "testl %edx, %edx\n"
        "je .Lf102c46_00103444\n"
        ".Lf102c46_001031c3:\n"
        "addl $1, %esi\n" /* line 1895 | sourceIndex */
        "movl %esi, %edi\n" /* sourceIndex */
        "movl %ebx, %edx\n" /* sourceIndex */
        "movl (%ebx), %eax\n" /* sourceIndex */
        "addl $0x14, %ebx\n" /* sourceIndex */
        "testl %eax, %eax\n"
        "jne .Lf102c46_001031b8\n"
        /* } scope */
        /* { scope 3: literal */
        ".Lf102c46_001031d3:\n"
        "movl s_defaultCodeConsts, %edx\n"
        "testl %edx, %edx\n"
        "je .Lf102c46_00103206\n"
        "movl $s_defaultCodeConsts+20, %edi\n"
        "xorl %ebx, %ebx\n" /* sourceIndex */
        "xorl %esi, %esi\n" /* sourceIndex */
        "movl $s_defaultCodeConsts, %eax\n"
        ".Lf102c46_001031eb:\n"
        "movl 8(%eax), %eax\n" /* line 1897 */
        "testl %eax, %eax\n"
        "je .Lf102c46_00103491\n"
        ".Lf102c46_001031f6:\n"
        "addl $1, %ebx\n" /* line 1895 | sourceIndex */
        "movl %ebx, %esi\n" /* sourceIndex */
        "movl %edi, %eax\n"
        "movl (%edi), %edx\n"
        "leal 0x14(%edi), %edi\n"
        "testl %edx, %edx\n"
        "jne .Lf102c46_001031eb\n"
        /* } scope */
        /* { scope 3: literal */
        /* { scope 4: token */
        ".Lf102c46_00103206:\n"
        "xorl %eax, %eax\n" /* line 1644 */
        "jmp .Lf102c46_00103141\n"
        /* } scope */
        /* } scope */
        ".Lf102c46_0010320d:\n"
        "cmpl -0x168(%ebp), %edx\n" /* line 2135 | usedCount */
        "je .Lf102c46_00102d84\n"
        "movl -0x15c(%ebp), %eax\n" /* line 2138 | shaderName */
        "movl %eax, 4(%esp)\n"
        "movl $str_002284bc, (%esp)\n" /* "Undefined shader constant(s) in %s
" */
        "calll Com_ScriptWarning\n"
        "movl -0x170(%ebp), %ecx\n" /* line 2139 | constantTable */
        "movl 0xc(%ecx), %edx\n"
        "testl %edx, %edx\n"
        "je .Lf102c46_001032ad\n"
        "movl -0x164(%ebp), %ebx\n" /* constantInfo, sourceIndex */
        "xorl %esi, %esi\n" /* constantIndex */
        "jmp .Lf102c46_00103250\n"
        ".Lf102c46_00103246:\n"
        "addl $1, %esi\n" /* constantIndex */
        "addl $0x14, %ebx\n" /* sourceIndex */
        "cmpl %esi, %edx\n" /* constantIndex */
        "jbe .Lf102c46_001032ad\n"
        ".Lf102c46_00103250:\n"
        "cmpb $0, -0x13c(%esi, %ebp)\n" /* line 2141 | constantIndex */
        "jne .Lf102c46_00103246\n"
        "movl -0x170(%ebp), %eax\n" /* line 2142 | constantTable */
        "addl (%ebx), %eax\n" /* sourceIndex */
        "movl %eax, 4(%esp)\n"
        "movl $str_002182fc, (%esp)\n" /* "  %s
" */
        "calll Com_Printf\n"
        "movl -0x170(%ebp), %edi\n" /* constantTable, name */
        "movl 0xc(%edi), %edx\n" /* name */
        "jmp .Lf102c46_00103246\n"
        ".Lf102c46_0010327d:\n"
        "movl 4(%ecx), %eax\n" /* line 2110 */
        "cmpl $0xe, %eax\n"
        "je .Lf102c46_001033dc\n"
        "cmpl $0xf, %eax\n" /* line 2112 */
        "jne .Lf102c46_00102fb0\n"
        "movl -0x17c(%ebp), %eax\n" /* line 2113 */
        "orw $2, (%eax)\n"
        "jmp .Lf102c46_00102fb0\n"
        ".Lf102c46_001032a1:\n"
        "movzwl 8(%edx), %eax\n" /* line 2029 */
        "movb %al, -0x27(%ebp)\n"
        "jmp .Lf102c46_001030ab\n"
        ".Lf102c46_001032ad:\n"
        "subl -0x168(%ebp), %edx\n" /* line 2144 | usedCount */
        "movl %edx, 4(%esp)\n"
        "movl $str_002284e0, (%esp)\n" /* "%i constant(s) were undefined
" */
        "calll Com_Printf\n"
        "xorl %ebx, %ebx\n" /* sourceIndex */
        "jmp .Lf102c46_00102d1e\n"
        /* { scope 3: literal */
        /* { scope 4: token */
        ".Lf102c46_001032ca:\n"
        "movl -0x178(%ebp), %eax\n" /* line 1851 */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x1a0(%ebp)\n" /* token */
        /* { scope 5 */
        "xorl %eax, %eax\n" /* line 1696 */
        "movl %eax, -0x3c(%ebp)\n" /* literal */
        "movl %eax, -0x38(%ebp)\n" /* line 1697 */
        "movl %eax, -0x34(%ebp)\n" /* line 1698 */
        "movl $0x3f800000, -0x30(%ebp)\n" /* line 1699 */
        "movl $str_002283f4, %ebx\n" /* line 1701 */
        "movl $7, -0x180(%ebp)\n"
        "cld\n"
        "movl -0x1a0(%ebp), %esi\n" /* token, sourceIndex */
        "movl %ebx, %edi\n"
        "movl $7, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* sourceIndex */
        "movl $0, %eax\n"
        "je .Lf102c46_00103320\n"
        "movzbl -1(%esi), %eax\n" /* sourceIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf102c46_00103320:\n"
        "testl %eax, %eax\n"
        "jne .Lf102c46_0010338f\n"
        "leal -0x3c(%ebp), %ecx\n" /* line 1702 | literal */
        "movl $1, %edx\n"
        "movl -0x178(%ebp), %eax\n"
        "calll Material_ParseVector\n"
        /* } scope */
        ".Lf102c46_00103337:\n"
        "cmpb $1, -0x27(%ebp)\n" /* line 1854 */
        "jbe .Lf102c46_0010353b\n"
        "movl $str_00228414, (%esp)\n" /* line 1856 */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf102c46_00102f72\n"
        /* } scope */
        /* { scope 4: token */
        ".Lf102c46_00103354:\n"
        "movl -0x178(%ebp), %edi\n" /* line 1952 */
        "movl %edi, (%esp)\n"
        "calll Com_ParseInt\n"
        "movb %al, -0x28(%ebp)\n"
        "movzbl %al, %edx\n" /* line 1953 */
        "movl -0x20(%ebp), %eax\n"
        "movzwl 8(%eax), %eax\n"
        "cmpl %eax, %edx\n"
        "jb .Lf102c46_001033eb\n"
        "subl $1, %eax\n" /* line 1955 */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl $str_00228368, (%esp)\n" /* "row index '%i' is not in the range [0, %i]
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf102c46_00102d1c\n"
        /* } scope */
        /* { scope 4: token */
        /* { scope 5 */
        ".Lf102c46_0010338f:\n"
        "movl $str_002283fc, %ebx\n" /* line 1703 */
        "movl $7, -0x184(%ebp)\n"
        "cld\n"
        "movl -0x1a0(%ebp), %esi\n" /* token, sourceIndex */
        "movl %ebx, %edi\n"
        "movl $7, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* sourceIndex */
        "movl $0, %edx\n"
        "je .Lf102c46_001033bf\n"
        "movzbl -1(%esi), %edx\n" /* sourceIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf102c46_001033bf:\n"
        "testl %edx, %edx\n"
        "jne .Lf102c46_001034ee\n"
        "leal -0x3c(%ebp), %ecx\n" /* line 1704 | literal */
        "movb $2, %dl\n"
        "movl -0x178(%ebp), %eax\n"
        "calll Material_ParseVector\n"
        "jmp .Lf102c46_00103337\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf102c46_001033dc:\n"
        "movl -0x17c(%ebp), %edi\n" /* line 2111 | name */
        "orw $1, (%edi)\n" /* name */
        "jmp .Lf102c46_00102fb0\n"
        /* { scope 3: literal */
        /* { scope 4: token */
        ".Lf102c46_001033eb:\n"
        "movl -0x178(%ebp), %eax\n" /* line 1959 */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 1960 */
        "cmpb $0x5d, %dl\n"
        "je .Lf102c46_00102efd\n"
        "cmpb $0x2c, %dl\n" /* line 1965 */
        "je .Lf102c46_00103564\n"
        "movl %eax, 4(%esp)\n" /* line 1967 */
        "movl $str_00228394, (%esp)\n" /* "expected ',' or ']', found '%s' instead
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf102c46_00102d1c\n"
        /* } scope */
        /* } scope */
        ".Lf102c46_00103423:\n"
        "movl -0x15c(%ebp), %eax\n" /* line 2094 | shaderName */
        "movl %eax, 8(%esp)\n"
        "movl %edi, 4(%esp)\n" /* name */
        "movl $str_00228328, (%esp)\n" /* "shader constant '%s' defined more than once for shader '%s'
" */
        "calll Com_ScriptWarning\n"
        "xorl %ebx, %ebx\n" /* sourceIndex */
        "jmp .Lf102c46_00102d1e\n"
        /* { scope 3: literal */
        ".Lf102c46_00103444:\n"
        "movl %eax, 4(%esp)\n" /* line 1899 */
        "movl -0x158(%ebp), %eax\n" /* constantName */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf102c46_001031c3\n"
        "leal (%edi, %edi, 4), %eax\n" /* line 1902 */
        "movzbl s_codeConsts+4(, %eax, 4), %ecx\n"
        "cmpl $0xba, %ecx\n" /* line 1903 */
        "jg .Lf102c46_001034c2\n"
        "movl -0x16c(%ebp), %eax\n" /* line 1905 */
        "movw %cx, 4(%eax)\n"
        "movb $0, 6(%eax)\n" /* line 1906 */
        "movzbl -0x27(%ebp), %eax\n" /* line 1907 */
        "movl -0x16c(%ebp), %edx\n"
        "movb %al, 7(%edx)\n"
        "jmp .Lf102c46_0010313c\n"
        /* } scope */
        /* { scope 3: literal */
        ".Lf102c46_00103491:\n"
        "movl %edx, 4(%esp)\n" /* line 1899 */
        "movl -0x158(%ebp), %eax\n" /* constantName */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf102c46_001031f6\n"
        "leal (%esi, %esi, 4), %eax\n" /* line 1902 | sourceIndex */
        "movzbl s_defaultCodeConsts+4(, %eax, 4), %ecx\n"
        "cmpl $0xba, %ecx\n" /* line 1903 */
        "jle .Lf102c46_001035ff\n"
        ".Lf102c46_001034c2:\n"
        "movl %ecx, %edx\n" /* line 1912 */
        "xorl $2, %edx\n"
        "movl -0x20(%ebp), %eax\n"
        "cmpw $3, (%eax)\n"
        "cmovel %edx, %ecx\n"
        "movl -0x16c(%ebp), %edx\n" /* line 1914 */
        "movw %cx, 4(%edx)\n"
        "movb $0, 6(%edx)\n" /* line 1915 */
        "movl -0x24(%ebp), %eax\n" /* line 1916 */
        "movzwl 8(%eax), %eax\n"
        "movb %al, 7(%edx)\n"
        "jmp .Lf102c46_0010313c\n"
        /* } scope */
        /* { scope 3: literal */
        /* { scope 4: token */
        /* { scope 5 */
        ".Lf102c46_001034ee:\n"
        "movl $str_00228404, %ebx\n" /* line 1705 */
        "movl $7, -0x188(%ebp)\n"
        "cld\n"
        "movl -0x1a0(%ebp), %esi\n" /* token, sourceIndex */
        "movl %ebx, %edi\n"
        "movl $7, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* sourceIndex */
        "movl $0, %edx\n"
        "je .Lf102c46_0010351e\n"
        "movzbl -1(%esi), %edx\n" /* sourceIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf102c46_0010351e:\n"
        "testl %edx, %edx\n"
        "jne .Lf102c46_001035b6\n"
        "leal -0x3c(%ebp), %ecx\n" /* line 1706 | literal */
        "movb $3, %dl\n"
        "movl -0x178(%ebp), %eax\n"
        "calll Material_ParseVector\n"
        "jmp .Lf102c46_00103337\n"
        /* } scope */
        ".Lf102c46_0010353b:\n"
        "movl -0x19c(%ebp), %eax\n" /* line 1859 */
        "movw $0, (%eax)\n"
        "leal -0x3c(%ebp), %eax\n" /* line 1860 | literal */
        "movl %eax, (%esp)\n"
        "calll Material_RegisterLiteral\n"
        "movl -0x19c(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "jmp .Lf102c46_00102f72\n"
        /* } scope */
        /* { scope 4: token */
        ".Lf102c46_00103564:\n"
        "movl -0x178(%ebp), %edx\n" /* line 1971 */
        "movl %edx, (%esp)\n"
        "calll Com_ParseInt\n"
        "movl %eax, %ecx\n"
        "movzbl -0x28(%ebp), %ebx\n" /* line 1972 | sourceIndex */
        "movzbl %bl, %esi\n" /* sourceIndex */
        "cmpl %esi, %eax\n" /* sourceIndex */
        "jl .Lf102c46_001036ac\n"
        "movl -0x20(%ebp), %edx\n"
        "movzwl 8(%edx), %eax\n"
        "cmpl %eax, %ecx\n"
        "jl .Lf102c46_00103678\n"
        ".Lf102c46_00103592:\n"
        "movzwl 8(%edx), %eax\n" /* line 1974 */
        "subl $1, %eax\n"
        "movl %eax, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n" /* sourceIndex */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002283c0, (%esp)\n" /* "end row index '%i' is not in the range [%i, %i]
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf102c46_00102d1c\n"
        /* } scope */
        /* { scope 4: token */
        /* { scope 5 */
        ".Lf102c46_001035b6:\n"
        "movl $str_0022840c, %ebx\n" /* line 1707 */
        "movl $7, -0x18c(%ebp)\n"
        "cld\n"
        "movl -0x1a0(%ebp), %esi\n" /* token, sourceIndex */
        "movl %ebx, %edi\n"
        "movl $7, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* sourceIndex */
        "movl $0, %edx\n"
        "je .Lf102c46_001035e6\n"
        "movzbl -1(%esi), %edx\n" /* sourceIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf102c46_001035e6:\n"
        "testl %edx, %edx\n"
        "jne .Lf102c46_00103619\n"
        "leal -0x3c(%ebp), %ecx\n" /* line 1708 | literal */
        "movb $4, %dl\n"
        "movl -0x178(%ebp), %eax\n"
        "calll Material_ParseVector\n"
        "jmp .Lf102c46_00103337\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 3: literal */
        ".Lf102c46_001035ff:\n"
        "movl -0x16c(%ebp), %edi\n" /* line 1905 */
        "movw %cx, 4(%edi)\n"
        "movb $0, 6(%edi)\n" /* line 1906 */
        "movzbl -0x27(%ebp), %eax\n" /* line 1907 */
        "movb %al, 7(%edi)\n"
        "jmp .Lf102c46_0010313c\n"
        /* } scope */
        /* { scope 3: literal */
        /* { scope 4: token */
        ".Lf102c46_00103619:\n"
        "movl $str_00228188, %ebx\n" /* line 1864 */
        "movl $9, -0x190(%ebp)\n"
        "cld\n"
        "movl -0x1a0(%ebp), %esi\n" /* token, sourceIndex */
        "movl %ebx, %edi\n"
        "movl $9, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* sourceIndex */
        "movl $0, %edx\n"
        "je .Lf102c46_00103649\n"
        "movzbl -1(%esi), %edx\n" /* sourceIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf102c46_00103649:\n"
        "testl %edx, %edx\n"
        "jne .Lf102c46_001036b4\n"
        "movl -0x19c(%ebp), %eax\n" /* line 1866 */
        "movw $1, (%eax)\n"
        "leal -0x2c(%ebp), %edx\n" /* line 1867 | routing */
        "movl %eax, 4(%esp)\n"
        "movl $s_codeConsts, (%esp)\n"
        "xorl %ecx, %ecx\n"
        "movl -0x178(%ebp), %eax\n"
        "calll Material_ParseCodeConstantSource_r\n"
        "jmp .Lf102c46_00102f72\n"
        /* } scope */
        /* { scope 4: token */
        ".Lf102c46_00103678:\n"
        "movl %ecx, %eax\n" /* line 1978 */
        "subb %bl, %al\n" /* sourceIndex */
        "addb $1, %al\n"
        "movb %al, -0x27(%ebp)\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "movl -0x178(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 1991 */
        "je .Lf102c46_00102d1c\n"
        "jmp .Lf102c46_00102f01\n"
        ".Lf102c46_001036ac:\n"
        "movl -0x20(%ebp), %edx\n"
        "jmp .Lf102c46_00103592\n"
        /* { scope 4: token */
        ".Lf102c46_001036b4:\n"
        "movl $str_00228234, %ebx\n" /* line 1870 */
        "movl $9, -0x194(%ebp)\n"
        "cld\n"
        "movl -0x1a0(%ebp), %esi\n" /* token, sourceIndex */
        "movl %ebx, %edi\n"
        "movl $9, %ecx\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* sourceIndex */
        "movl $0, %edx\n"
        "je .Lf102c46_001036e4\n"
        "movzbl -1(%esi), %edx\n" /* sourceIndex */
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf102c46_001036e4:\n"
        "testl %edx, %edx\n"
        "jne .Lf102c46_00103701\n"
        "cmpb $1, -0x27(%ebp)\n" /* line 1872 */
        "jbe .Lf102c46_0010371e\n"
        "movl $str_00228454, (%esp)\n" /* line 1874 */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf102c46_00102f72\n"
        ".Lf102c46_00103701:\n"
        "movl -0x1a0(%ebp), %eax\n" /* line 1885 | token */
        "movl %eax, 4(%esp)\n"
        "movl $str_00228240, (%esp)\n" /* "expected 'sampler' or 'material', found '%s' instead
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf102c46_00102f72\n"
        ".Lf102c46_0010371e:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "movl -0x178(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1877 */
        "je .Lf102c46_00102f72\n"
        "movl -0x178(%ebp), %edx\n" /* line 1879 */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl -0x19c(%ebp), %ecx\n" /* line 1880 */
        "movw $2, (%ecx)\n"
        "movl %eax, (%esp)\n" /* line 1881 */
        "calll Material_RegisterString\n"
        "movl -0x19c(%ebp), %edi\n"
        "movl %eax, 4(%edi)\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "jmp .Lf102c46_00102f72\n"
    );
}

/* line 1000 — Material_ParseRuleSetConditionTest
 * Parses a state map condition test: "sourceName == valueName".
 * Looks up sourceName in s_stateMapSrcBitGroup, then valueName in that group's bitNames.
 * On match, ORs the condition mask and value bits into the rule.
 * Returns: 0=success, 1=unrecognized source (not an error), 2=parse error.
 * Actual convention: eax=text, edx=token(source name), ecx=rule */
static MtlParseSuccess Material_ParseRuleSetConditionTest_impl(const char **text, const char *token, MaterialStateMapRule *rule)
{
    byte *srcGroup = (byte *)&s_stateMapSrcBitGroup;

    /* Search for source name in s_stateMapSrcBitGroup (stride 0x10) */
    int sourceIndex;
    for (sourceIndex = 0; *(const char **)(srcGroup + sourceIndex * 0x10); sourceIndex++) {
        if (strcmp(token, *(const char **)(srcGroup + sourceIndex * 0x10)) == 0)
            goto foundSource;
    }
    return 1; /* unrecognized source — not an error */

foundSource:
    /* Match "==" operator */
    if (!Com_MatchToken(text, "==", 1))
        return 2;

    /* Get bitNames table for this source */
    byte *bitNames = *(byte **)(srcGroup + sourceIndex * 0x10 + 4);

    /* Parse value token and search in bitNames (stride 8: {name, bits}) */
    const char *valueToken = Com_Parse(text);
    int valueIndex;
    for (valueIndex = 0; *(const char **)(bitNames + valueIndex * 8); valueIndex++) {
        if (strcmp(valueToken, *(const char **)(bitNames + valueIndex * 8)) == 0)
            goto foundValue;
    }
    Com_ScriptWarning("%s is not a valid state value\n", valueToken);
    return 2;

foundValue:;
    byte *bitEntry = bitNames + valueIndex * 8;

    /* Determine the destination word offset for this source group.
     * If srcGroup[sourceIndex].destOffset (at +8) is set, use 0; otherwise count NULL entries before it. */
    int destWordIndex = *(int *)(srcGroup + sourceIndex * 0x10 + 8);
    if (!destWordIndex) {
        destWordIndex = 0;
        byte *scan = srcGroup;
        while (!*(int *)(scan + 0x0c)) {
            destWordIndex++;
            scan += 4;
        }
    } else {
        destWordIndex = 0;
    }

    /* OR the source mask and value bits into the rule at the computed word offset */
    int *ruleWords = (int *)rule;
    ruleWords[destWordIndex] |= *(int *)(srcGroup + (destWordIndex + sourceIndex * 4) * 4 + 8);
    ruleWords[destWordIndex + 2] |= *(int *)(bitEntry + 4);

    return 0; /* success */
}

/* Trampoline: eax=text, edx=token, ecx=rule */
static __attribute__((naked))
MtlParseSuccess Material_ParseRuleSetConditionTest(const char * *text, MaterialStateMapRule *rule)
{
    __asm__ __volatile__ (
        "pushl %ecx\n"
        "pushl %edx\n"
        "pushl %eax\n"
        "calll Material_ParseRuleSetConditionTest_impl\n"
        "addl $12, %esp\n"
        "retl\n"
    );
}

/* line 1141 */
/* line 1141 — State map rule set parser: reads condition→action rule pairs from text.
 * Each rule has: condition (test source against value) → action (set state bits).
 * Parses "default:" fallback and multiple "condition == value:" cases.
 * Register convention: eax=text, edx=ruleSetName, ecx=stateSet, stack=ruleSet.
 * 421 lines of text parsing with Material_ParseRuleSetConditionTest dispatch. */
static __attribute__((naked))
Bool Material_ParseRuleSet(const char * *text, const char *ruleSetName, const MtlStateMapBitGroup *stateSet, const MaterialStateMapRuleSet * *ruleSet)
{
    (void)text; (void)ruleSetName; (void)stateSet; (void)ruleSet;
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1141 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x207c, %esp\n"
        "movl %eax, -0x205c(%ebp)\n"
        "movl %edx, -0x2060(%ebp)\n"
        "movl %ecx, -0x2064(%ebp)\n"
        /* { scope 1: rule, rule */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1150 */
        "jne .Lf1038c4_00103907\n"
        ".Lf1038c4_001038fa:\n"
        "xorl %eax, %eax\n" /* line 1203 */
        /* } scope */
        ".Lf1038c4_001038fc:\n"
        "addl $0x207c, %esp\n" /* line 1204 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: rule, rule */
        ".Lf1038c4_00103907:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e50c, 4(%esp)\n" /* "{" */
        "movl -0x205c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1152 */
        "je .Lf1038c4_001038fa\n"
        "movl $0x2020, 8(%esp)\n" /* line 1155 */
        "movl $0, 4(%esp)\n"
        "leal -0x2038(%ebp), %edx\n" /* rules */
        "movl %edx, (%esp)\n"
        "calll memset\n"
        "movl $0, -0x2058(%ebp)\n" /* firstRule */
        "movl $0, -0x2054(%ebp)\n" /* ruleCount */
        "movl $0, -0x2068(%ebp)\n"
        ".Lf1038c4_00103965:\n"
        "movl -0x205c(%ebp), %ecx\n" /* line 1160 */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* ruleIndex */
        "cmpb $0x7d, (%eax)\n" /* line 1161 */
        "je .Lf1038c4_00103d34\n"
        "leal -0x2038(%ebp), %ecx\n" /* line 1177 | rules */
        "addl -0x2068(%ebp), %ecx\n"
        "movl %ecx, -0x2050(%ebp)\n" /* rule */
        /* { scope 2 */
        /* { scope 3: bitNames */
        "movl $str_00220284, %edi\n" /* line 1044 | token */
        "movl $8, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n"
        "repe cmpsb %es:(%edi), (%esi)\n" /* token */
        "movl $0, %edx\n"
        "je .Lf1038c4_001039b0\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %edx\n"
        ".Lf1038c4_001039b0:\n"
        "testl %edx, %edx\n"
        "je .Lf1038c4_00103a7b\n"
        "movl -0x2050(%ebp), %ecx\n" /* line 1047 | rule */
        "movl %ebx, %edx\n" /* valueIndex */
        "movl -0x205c(%ebp), %eax\n"
        "calll Material_ParseRuleSetConditionTest\n"
        "testl %eax, %eax\n" /* line 1048 */
        "je .Lf1038c4_00103ae4\n"
        /* } scope */
        /* } scope */
        "cmpl $2, %eax\n" /* line 1183 */
        "je .Lf1038c4_001038fa\n"
        "movl -0x2054(%ebp), %ecx\n" /* line 1186 | ruleCount */
        "cmpl %ecx, -0x2058(%ebp)\n" /* firstRule */
        "je .Lf1038c4_00103d69\n"
        "movl -0x2058(%ebp), %eax\n" /* line 1192 | firstRule */
        "shll $5, %eax\n"
        "leal -0x2038(%ebp), %edx\n" /* rules */
        "addl %eax, %edx\n"
        "movl %edx, -0x204c(%ebp)\n" /* rule */
        /* { scope 2 */
        /* { scope 3: bitNames */
        "movl $str_002285f8, %edi\n" /* line 1083 | token */
        "movl $0xc, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* bitName */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token */
        "movl $0, %eax\n"
        "je .Lf1038c4_00103a25\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %eax\n"
        ".Lf1038c4_00103a25:\n"
        "testl %eax, %eax\n"
        "jne .Lf1038c4_00103b8d\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "movl -0x205c(%ebp), %ecx\n"
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        /* } scope */
        /* } scope */
        ".Lf1038c4_00103a50:\n"
        "testb %al, %al\n" /* line 1192 */
        "je .Lf1038c4_001038fa\n"
        "movl -0x2058(%ebp), %eax\n" /* line 1194 | firstRule */
        "addl $1, %eax\n"
        "cmpl -0x2054(%ebp), %eax\n" /* ruleCount */
        "jl .Lf1038c4_00103c1a\n"
        ".Lf1038c4_00103a6d:\n"
        "movl -0x2054(%ebp), %edx\n" /* ruleCount */
        "movl %edx, -0x2058(%ebp)\n" /* firstRule */
        "jmp .Lf1038c4_00103aaf\n"
        /* { scope 2 */
        /* { scope 3: bitNames */
        ".Lf1038c4_00103a7b:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222928, 4(%esp)\n" /* ":" */
        "movl -0x205c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1045 */
        "je .Lf1038c4_001038fa\n"
        /* } scope */
        /* } scope */
        ".Lf1038c4_00103aa1:\n"
        "addl $1, -0x2054(%ebp)\n" /* line 1180 | ruleCount */
        "addl $0x20, -0x2068(%ebp)\n"
        ".Lf1038c4_00103aaf:\n"
        "cmpl $0x100, -0x2054(%ebp)\n" /* line 1158 | ruleCount */
        "jle .Lf1038c4_00103965\n"
        "movl $0x100, 8(%esp)\n" /* line 1202 */
        "movl -0x2060(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $str_00228604, (%esp)\n" /* "state %s has more than %i rules
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        /* { scope 2 */
        /* { scope 3: bitNames */
        ".Lf1038c4_00103ae4:\n"
        "movl -0x205c(%ebp), %edx\n" /* line 1053 */
        "movl %edx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x206c(%ebp)\n"
        "movl $2, %ebx\n" /* line 1054 | valueIndex */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $str_00222928, %edi\n" /* token */
        "movl %ebx, %ecx\n" /* valueIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token */
        "movl $0, %eax\n"
        "je .Lf1038c4_00103b1a\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %eax\n"
        ".Lf1038c4_00103b1a:\n"
        "testl %eax, %eax\n"
        "je .Lf1038c4_00103aa1\n"
        "movl $str_00216c3c, %edi\n" /* line 1056 | token */
        "movb $3, %bl\n" /* valueIndex */
        "movl -0x206c(%ebp), %esi\n"
        "movl %ebx, %ecx\n" /* valueIndex */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token */
        "movl $0, %edx\n"
        "je .Lf1038c4_00103b40\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %edx\n"
        ".Lf1038c4_00103b40:\n"
        "testl %edx, %edx\n"
        "jne .Lf1038c4_00103d17\n"
        "movl -0x205c(%ebp), %eax\n" /* line 1058 */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl -0x2050(%ebp), %ecx\n" /* line 1059 | rule */
        "movl %eax, %edx\n"
        "movl -0x205c(%ebp), %eax\n"
        "calll Material_ParseRuleSetConditionTest\n"
        "testl %eax, %eax\n" /* line 1060 */
        "je .Lf1038c4_00103ae4\n"
        "subl $1, %eax\n" /* line 1062 */
        "jne .Lf1038c4_001038fa\n"
        "movl $str_00228584, (%esp)\n" /* line 1063 */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: bitNames */
        ".Lf1038c4_00103b8d:\n"
        "calll Com_UngetToken\n" /* line 1086 */
        "movl -0x2064(%ebp), %eax\n"
        "movl %eax, -0x2040(%ebp)\n"
        "addl $0x10, %eax\n"
        "movl %eax, -0x203c(%ebp)\n"
        ".Lf1038c4_00103ba7:\n"
        "movl -0x2040(%ebp), %edx\n" /* line 1090 */
        "movl 4(%edx), %edx\n"
        "movl %edx, -0x2048(%ebp)\n" /* bitNames */
        /* { scope 4 */
        /* { scope 5 */
        "movl -0x205c(%ebp), %ecx\n" /* line 988 */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %edi\n" /* token */
        "movl -0x2048(%ebp), %edx\n" /* line 989 | bitNames */
        "movl (%edx), %eax\n"
        "testl %eax, %eax\n"
        "je .Lf1038c4_00103c05\n"
        "movl %edx, %esi\n"
        "addl $8, %esi\n"
        "xorl %ebx, %ebx\n" /* valueIndex */
        "movl $0, -0x2044(%ebp)\n"
        ".Lf1038c4_00103be3:\n"
        "movl %eax, 4(%esp)\n" /* line 991 */
        "movl %edi, (%esp)\n" /* token */
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1038c4_00103c6a\n"
        "addl $1, %ebx\n" /* line 989 | valueIndex */
        "movl %ebx, -0x2044(%ebp)\n" /* valueIndex */
        "movl (%esi), %eax\n"
        "addl $8, %esi\n"
        "testl %eax, %eax\n"
        "jne .Lf1038c4_00103be3\n"
        ".Lf1038c4_00103c05:\n"
        "movl %edi, 4(%esp)\n" /* line 995 | token */
        "movl $str_00228500, (%esp)\n" /* "%s is not a valid state value
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1038c4_001038fa\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1038c4_00103c1a:\n"
        "movl %eax, %ebx\n" /* line 1194 | ruleIndex */
        "shll $5, -0x2058(%ebp)\n" /* firstRule */
        "movl -0x2058(%ebp), %eax\n" /* firstRule */
        "leal -0x2028(%eax, %ebp), %ecx\n"
        "leal 8(%ecx), %edi\n" /* token */
        "movl -0x2054(%ebp), %esi\n" /* ruleCount */
        "movl %ebx, %eax\n" /* ruleIndex */
        "shll $5, %eax\n"
        "leal -0x2028(%eax, %ebp), %edx\n"
        ".Lf1038c4_00103c45:\n"
        "movl (%ecx), %eax\n" /* line 1196 */
        "movl %eax, (%edx)\n"
        "movl 4(%ecx), %eax\n"
        "movl %eax, 4(%edx)\n"
        "movl 8(%ecx), %eax\n" /* line 1197 */
        "movl %eax, 8(%edx)\n"
        "movl 4(%edi), %eax\n" /* token */
        "movl %eax, 0xc(%edx)\n"
        "addl $1, %ebx\n" /* line 1194 | ruleIndex */
        "addl $0x20, %edx\n"
        "cmpl %esi, %ebx\n" /* ruleIndex */
        "jne .Lf1038c4_00103c45\n"
        "jmp .Lf1038c4_00103a6d\n"
        /* { scope 2 */
        /* { scope 3: bitNames */
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1038c4_00103c6a:\n"
        "movl -0x2044(%ebp), %ecx\n" /* line 993 */
        "movl -0x2048(%ebp), %eax\n" /* bitNames */
        "leal (%eax, %ecx, 8), %ebx\n" /* valueIndex */
        /* } scope */
        /* } scope */
        "testl %ebx, %ebx\n" /* line 1091 | bitName */
        "je .Lf1038c4_001038fa\n"
        "movl -0x2040(%ebp), %edx\n" /* line 1097 */
        "movl 8(%edx), %esi\n"
        "testl %esi, %esi\n"
        "jne .Lf1038c4_00103d13\n"
        "xorl %ecx, %ecx\n"
        ".Lf1038c4_00103c94:\n"
        "addl $1, %ecx\n" /* line 1103 */
        "movl 0xc(%edx), %eax\n" /* line 1097 */
        "addl $4, %edx\n"
        "testl %eax, %eax\n"
        "je .Lf1038c4_00103c94\n"
        ".Lf1038c4_00103ca1:\n"
        "movl -0x204c(%ebp), %edx\n" /* line 1099 | rule */
        "movl 0x10(%edx, %ecx, 4), %eax\n"
        "orl 4(%ebx), %eax\n" /* bitName */
        "movl %eax, 0x10(%edx, %ecx, 4)\n"
        "movl 0x18(%edx, %ecx, 4), %eax\n" /* line 1100 */
        "movl -0x2040(%ebp), %edx\n"
        "orl 8(%edx, %ecx, 4), %eax\n"
        "movl -0x204c(%ebp), %edx\n" /* rule */
        "movl %eax, 0x18(%edx, %ecx, 4)\n"
        "movl -0x203c(%ebp), %ecx\n" /* line 1108 */
        "movl (%ecx), %ebx\n" /* bitName */
        "testl %ebx, %ebx\n" /* bitName */
        "je .Lf1038c4_00103e1b\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021f88c, 4(%esp)\n" /* "," */
        "movl -0x205c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "addl $0x10, -0x2040(%ebp)\n"
        "addl $0x10, -0x203c(%ebp)\n"
        "testl %eax, %eax\n" /* line 1110 */
        "jne .Lf1038c4_00103ba7\n"
        "jmp .Lf1038c4_001038fa\n"
        /* { scope 4 */
        /* { scope 5 */
        ".Lf1038c4_00103d13:\n"
        "xorl %ecx, %ecx\n" /* line 995 */
        "jmp .Lf1038c4_00103ca1\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 2 */
        /* { scope 3: bitNames */
        ".Lf1038c4_00103d17:\n"
        "movl -0x206c(%ebp), %edx\n" /* line 1066 */
        "movl %edx, 4(%esp)\n"
        "movl $str_002285ac, (%esp)\n" /* "expected ':' or '&&', found '%s'
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        /* } scope */
        /* } scope */
        ".Lf1038c4_00103d34:\n"
        "movl -0x2054(%ebp), %eax\n" /* line 1163 | ruleCount */
        "testl %eax, %eax\n"
        "je .Lf1038c4_00103d86\n"
        "movl -0x2054(%ebp), %eax\n" /* line 1168 | ruleCount */
        "cmpl %eax, -0x2058(%ebp)\n" /* firstRule */
        "je .Lf1038c4_00103da3\n"
        "movl -0x2060(%ebp), %edx\n" /* line 1170 */
        "movl %edx, 4(%esp)\n"
        "movl $str_00228568, (%esp)\n" /* "missing value for state %s
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        ".Lf1038c4_00103d69:\n"
        "movl -0x2060(%ebp), %ecx\n" /* line 1188 */
        "movl %ecx, 4(%esp)\n"
        "movl $str_002285d0, (%esp)\n" /* "missing rule condition for state %s
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        ".Lf1038c4_00103d86:\n"
        "movl -0x2060(%ebp), %eax\n" /* line 1165 */
        "movl %eax, 4(%esp)\n"
        "movl $str_00228520, (%esp)\n" /* "no entries for state %s: you may want to do 'default: passth" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        /* { scope 2 */
        ".Lf1038c4_00103da3:\n"
        "movl -0x2068(%ebp), %eax\n" /* line 1126 */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, %esi\n"
        "movl -0x2054(%ebp), %edx\n" /* line 1130 | ruleCount */
        "movl %edx, (%eax)\n"
        "movl -0x2068(%ebp), %ecx\n" /* line 1131 */
        "movl %ecx, 8(%esp)\n"
        "leal -0x2038(%ebp), %eax\n" /* rules */
        "movl %eax, 4(%esp)\n"
        "leal 4(%esi), %eax\n"
        "movl %eax, (%esp)\n"
        "calll Com_Memcpy\n"
        "movl -0x2054(%ebp), %edi\n" /* line 1132 | ruleCount, token */
        "testl %edi, %edi\n" /* token */
        "jle .Lf1038c4_00103e0c\n"
        "xorl %ebx, %ebx\n" /* ruleIndex */
        "movl %esi, %ecx\n"
        ".Lf1038c4_00103deb:\n"
        "leal 4(%ecx), %eax\n"
        "movl $2, %edx\n"
        ".Lf1038c4_00103df3:\n"
        "notl 0x18(%eax)\n" /* line 1135 */
        "addl $4, %eax\n"
        "subl $1, %edx\n" /* line 1134 */
        "jne .Lf1038c4_00103df3\n"
        "addl $1, %ebx\n" /* line 1132 | ruleIndex */
        "addl $0x20, %ecx\n"
        "cmpl %ebx, -0x2058(%ebp)\n" /* ruleIndex, firstRule */
        "jne .Lf1038c4_00103deb\n"
        /* } scope */
        ".Lf1038c4_00103e0c:\n"
        "movl 8(%ebp), %edx\n" /* line 1173 | ruleSet */
        "movl %esi, (%edx)\n"
        "movl $1, %eax\n"
        "jmp .Lf1038c4_001038fc\n"
        /* { scope 2 */
        /* { scope 3: bitNames */
        ".Lf1038c4_00103e1b:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "movl -0x205c(%ebp), %edx\n"
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "jmp .Lf1038c4_00103a50\n"
    );
}

/* line 1371 */
static __attribute__((naked))
Bool Material_LoadPassStateMap(MaterialStateMap * *stateMap)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 1371 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x8c, %esp\n"
        "movl %eax, %esi\n" /* text */
        "movl %edx, -0x80(%ebp)\n"
        /* { scope 1 */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00228628, 4(%esp)\n" /* "stateMap" */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1375 */
        "jne .Lf103e44_00103e7e\n"
        ".Lf103e44_00103e71:\n"
        "xorl %eax, %eax\n" /* line 1386 */
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf103e44_00103e7e:\n"
        "movl %esi, (%esp)\n" /* line 1377 | text */
        "calll Com_Parse\n"
        "movl %eax, -0x7c(%ebp)\n" /* token */
        "movzbl (%eax), %eax\n" /* line 1378 */
        "testb %al, %al\n"
        "je .Lf103e44_00103ed9\n"
        "cmpb $0x3b, %al\n"
        "je .Lf103e44_00103ed9\n"
        /* { scope 2: filename, file, text */
        "movl -0x7c(%ebp), %eax\n" /* line 1358 | token */
        "movl %eax, (%esp)\n"
        "calll Material_FindStateMap\n"
        "movl %eax, %edi\n" /* stateMap */
        "testl %eax, %eax\n" /* line 1359 */
        "je .Lf103e44_00103ef2\n"
        /* } scope */
        ".Lf103e44_00103ea5:\n"
        "movl -0x80(%ebp), %edx\n" /* line 1383 */
        "movl %edi, (%edx)\n" /* stateMap */
        "testl %edi, %edi\n" /* line 1384 | stateMap */
        "je .Lf103e44_00103e71\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1386 */
        "setne %al\n"
        "andl $1, %eax\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        ".Lf103e44_00103ed9:\n"
        "movl $str_00228634, (%esp)\n" /* line 1380 */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        /* } scope */
        "addl $0x8c, %esp\n" /* line 1387 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: filename, file, text */
        /* { scope 3: ruleSet, ruleIndex */
        ".Lf103e44_00103ef2:\n"
        "movl -0x7c(%ebp), %edx\n" /* line 1327 | token */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_00228650, 8(%esp)\n" /* "materials/statemaps/%s.sm" */
        "movl $0x40, 4(%esp)\n"
        "leal -0x60(%ebp), %ebx\n" /* filename */
        "movl %ebx, (%esp)\n"
        "calll Com_sprintf\n"
        "leal -0x1c(%ebp), %eax\n" /* line 1328 | file */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 1329 */
        "js .Lf103e44_00104174\n"
        "movl -0x1c(%ebp), %eax\n" /* line 1335 | file */
        "movl %eax, -0x20(%ebp)\n" /* text */
        "movl %ebx, (%esp)\n" /* line 1336 */
        "calll Com_BeginParseSession\n"
        "movl $str_0022831c, (%esp)\n" /* line 1337 */
        "calll Com_SetScriptWarningPrefix\n"
        "movl $0, (%esp)\n" /* line 1338 */
        "calll Com_SetSpaceDelimited\n"
        "cld\n" /* line 1340 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x7c(%ebp), %edi\n" /* token */
        "repne scasb %es:(%edi), %al\n"
        "movl %ecx, %ebx\n"
        "notl %ebx\n"
        "leal 0x30(%ebx), %eax\n" /* line 1341 */
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, %edi\n"
        "leal 0x30(%eax), %eax\n" /* line 1342 */
        "movl %eax, (%edi)\n"
        "movl %ebx, 8(%esp)\n" /* line 1343 */
        "movl -0x7c(%ebp), %edx\n" /* token */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "leal 4(%edi), %eax\n" /* line 1278 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstAlphaTestBitGroup, %ecx\n"
        "movl $str_00226ca8, %edx\n" /* "alphaTest" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "jne .Lf103e44_00103fd1\n"
        ".Lf103e44_00103fa3:\n"
        "xorl %edi, %edi\n" /* line 1345 */
        ".Lf103e44_00103fa5:\n"
        "calll Com_EndParseSession\n" /* line 1348 */
        "movl -0x1c(%ebp), %eax\n" /* line 1349 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "testl %edi, %edi\n" /* line 1363 | stateMap */
        "je .Lf103e44_00103ea5\n"
        "movl %edi, 4(%esp)\n" /* line 1366 | stateMap */
        "movl -0x7c(%ebp), %eax\n" /* token */
        "movl %eax, (%esp)\n"
        "calll Material_SetStateMap\n"
        "jmp .Lf103e44_00103ea5\n"
        /* { scope 3: ruleSet, ruleIndex */
        ".Lf103e44_00103fd1:\n"
        "leal 8(%edi), %eax\n" /* line 1281 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstBlendFuncRgbBitGroup, %ecx\n"
        "movl $str_0022868c, %edx\n" /* "blendFunc" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "movl 8(%edi), %eax\n"
        "movl %eax, -0x78(%ebp)\n" /* ruleSet */
        /* { scope 4: ruleIndex */
        /* { scope 5 */
        "movl imp_dx, %eax\n" /* line 1213 */
        "cmpb $0, 0x2d7c(%eax)\n"
        "je .Lf103e44_00104189\n"
        /* } scope */
        /* } scope */
        ".Lf103e44_00104005:\n"
        "leal 0xc(%edi), %eax\n" /* line 1285 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstBlendFuncAlphaBitGroup, %ecx\n"
        "movl $str_00228698, %edx\n" /* "separateAlphaBlendFunc" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "movl 0xc(%edi), %ecx\n"
        /* { scope 4: ruleIndex */
        "movl imp_dx, %eax\n" /* line 1240 */
        "cmpb $0, 0x2d7d(%eax)\n"
        "jne .Lf103e44_001041e6\n"
        "movl $1, (%ecx)\n" /* line 1242 */
        "movl $0, 4(%ecx)\n" /* line 1243 */
        "movl $0, 8(%ecx)\n" /* line 1244 */
        "movl $0, 0xc(%ecx)\n" /* line 1245 */
        "movl $0, 0x10(%ecx)\n" /* line 1246 */
        "orl $0x7ff0000, 0x1c(%ecx)\n" /* line 1247 */
        "movl 0x14(%ecx), %eax\n" /* line 1251 */
        "andl $0xf800ffff, %eax\n"
        "orl $0x120000, %eax\n"
        "movl %eax, 0x14(%ecx)\n"
        /* } scope */
        ".Lf103e44_0010406f:\n"
        "leal 0x10(%edi), %eax\n" /* line 1289 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstCullFaceBitGroup, %ecx\n"
        "movl $str_00226bc0, %edx\n" /* "cullFace" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x14(%edi), %eax\n" /* line 1292 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstDepthTestBitGroup, %ecx\n"
        "movl $str_00226bb4, %edx\n" /* "depthTest" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x18(%edi), %eax\n" /* line 1295 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstDepthWriteBitGroup, %ecx\n"
        "movl $str_00226ba8, %edx\n" /* "depthWrite" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x1c(%edi), %eax\n" /* line 1298 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstColorWriteBitGroup, %ecx\n"
        "movl $str_00226b9c, %edx\n" /* "colorWrite" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x20(%edi), %eax\n" /* line 1301 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstFogBitGroup, %ecx\n"
        "movl $str_00226b98, %edx\n" /* "fog" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x24(%edi), %eax\n" /* line 1304 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstPolygonOffsetBitGroup, %ecx\n"
        "movl $str_00226b84, %edx\n" /* "polygonOffset" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x28(%edi), %eax\n" /* line 1307 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstStencilBitGroup, %ecx\n"
        "movl $str_00226ad4, %edx\n" /* "stencil" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "je .Lf103e44_00103fa3\n"
        "leal 0x2c(%edi), %eax\n" /* line 1310 */
        "movl %eax, (%esp)\n"
        "movl $s_stateMapDstWireframeBitGroup, %ecx\n"
        "movl $str_00226ab8, %edx\n" /* "wireframe" */
        "leal -0x20(%ebp), %eax\n" /* text */
        "calll Material_ParseRuleSet\n"
        "testb %al, %al\n"
        "jne .Lf103e44_00103fa5\n"
        "jmp .Lf103e44_00103fa3\n"
        ".Lf103e44_00104174:\n"
        "movl %ebx, 4(%esp)\n" /* line 1331 */
        "movl $str_0022866c, (%esp)\n" /* "Couldn't open statemap '%s'
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf103e44_00103ea5\n"
        /* { scope 4: ruleIndex */
        /* { scope 5 */
        ".Lf103e44_00104189:\n"
        "movl -0x78(%ebp), %eax\n" /* line 1216 | ruleSet */
        "movl (%eax), %edx\n"
        "testl %edx, %edx\n"
        "jle .Lf103e44_00104005\n"
        "movl %eax, %ecx\n"
        "movl $0, -0x74(%ebp)\n" /* ruleIndex */
        ".Lf103e44_0010419f:\n"
        "movl 0x1c(%ecx), %edx\n" /* line 1218 */
        "testb $7, %dh\n"
        "je .Lf103e44_001041d0\n"
        "movl 0x14(%ecx), %ebx\n" /* line 1221 */
        "movl %ebx, %eax\n"
        "andl $0x700, %eax\n"
        "cmpl $0x100, %eax\n"
        "jbe .Lf103e44_001041d0\n"
        "orl $0x7ff, %edx\n" /* line 1224 */
        "movl %edx, 0x1c(%ecx)\n"
        "andl $0xfffff800, %ebx\n" /* line 1228 */
        "orl $0x111, %ebx\n"
        "movl %ebx, 0x14(%ecx)\n"
        ".Lf103e44_001041d0:\n"
        "addl $1, -0x74(%ebp)\n" /* line 1216 | ruleIndex */
        "addl $0x20, %ecx\n"
        "movl -0x74(%ebp), %eax\n" /* ruleIndex */
        "movl -0x78(%ebp), %edx\n" /* ruleSet */
        "cmpl %eax, (%edx)\n"
        "jg .Lf103e44_0010419f\n"
        "jmp .Lf103e44_00104005\n"
        /* } scope */
        /* } scope */
        /* { scope 4: ruleIndex */
        ".Lf103e44_001041e6:\n"
        "cmpb $0, 0x2d7c(%eax)\n" /* line 1255 */
        "jne .Lf103e44_0010406f\n"
        "movl (%ecx), %eax\n" /* line 1258 */
        "testl %eax, %eax\n"
        "jle .Lf103e44_0010406f\n"
        "movl %ecx, -0x6c(%ebp)\n"
        "movl $0, -0x70(%ebp)\n" /* ruleIndex */
        "movl %ecx, %edx\n"
        "jmp .Lf103e44_0010420e\n"
        ".Lf103e44_0010420b:\n"
        "movl -0x6c(%ebp), %edx\n"
        ".Lf103e44_0010420e:\n"
        "movl 0x1c(%edx), %ebx\n" /* line 1260 */
        "testl $0x7000000, %ebx\n"
        "je .Lf103e44_00104245\n"
        "movl 0x14(%edx), %edx\n" /* line 1263 */
        "movl %edx, %eax\n"
        "andl $0x7000000, %eax\n"
        "cmpl $0x01000000, %eax\n"
        "jbe .Lf103e44_00104245\n"
        "orl $0x7ff0000, %ebx\n" /* line 1266 */
        "movl -0x6c(%ebp), %eax\n"
        "movl %ebx, 0x1c(%eax)\n"
        "andl $0xf800ffff, %edx\n" /* line 1270 */
        "orl $0x01110000, %edx\n"
        "movl %edx, 0x14(%eax)\n"
        ".Lf103e44_00104245:\n"
        "addl $1, -0x70(%ebp)\n" /* line 1258 | ruleIndex */
        "addl $0x20, -0x6c(%ebp)\n"
        "movl -0x70(%ebp), %edx\n" /* ruleIndex */
        "cmpl %edx, (%ecx)\n"
        "jg .Lf103e44_0010420b\n"
        "jmp .Lf103e44_0010406f\n"
    );
}

/* line 2299 — Shader loader: reads D3DX shader from cached text, compiles via D3DXCompileShader
 * or loads pre-compiled binary, creates IDirect3DPixelShader9/IDirect3DVertexShader9.
 * Register convention: eax=text, edx=shaderType.
 * 553 lines of shader compilation with include handler, error reporting, caching. */
static __attribute__((naked))
MaterialShader * Material_LoadPassShader(MaterialShaderType shaderType)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 2299 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0xfc, %esp\n"
        "movl %eax, %ebx\n" /* text */
        "movl %edx, -0xc4(%ebp)\n"
        /* { scope 1 */
        "movl %eax, (%esp)\n" /* line 2304 */
        "calll Com_ParseFloat\n"
        "fstps -0xcc(%ebp)\n"
        "movss -0xcc(%ebp), %xmm0\n"
        "mulss lit4_002ed6b4, %xmm0\n" /* line 428 | 10.0f */
        "addss lit4_002ed5d8, %xmm0\n" /* 0.5f */
        "movss %xmm0, (%esp)\n"
        "calll floorf\n"
        "fstps -0xc8(%ebp)\n"
        "cvttss2si -0xc8(%ebp), %eax\n"
        "movl %eax, -0xc0(%ebp)\n" /* shaderVersion */
        "cmpl $0x13, %eax\n" /* line 2308 */
        "movl $0x14, %eax\n"
        "cmovgl -0xc0(%ebp), %eax\n" /* shaderVersion */
        "movl %eax, -0xc0(%ebp)\n" /* shaderVersion */
        "movl %ebx, (%esp)\n" /* line 2313 | text */
        "calll Com_Parse\n"
        "movl %eax, -0xb4(%ebp)\n" /* filename */
        /* { scope 2: filename, file, fileSize, target, ... */
        "movl -0xc0(%ebp), %edx\n" /* line 2286 | shaderVersion */
        "movl %edx, 8(%esp)\n"
        "movl -0xc4(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll Material_FindShader\n"
        "movl %eax, %edi\n" /* mtlShader */
        "testl %eax, %eax\n" /* line 2287 */
        "je .Lf10425a_00104304\n"
        /* } scope */
        /* } scope */
        ".Lf10425a_001042f7:\n"
        "movl %edi, %eax\n" /* line 2314 | mtlShader */
        "addl $0xfc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: filename, file, fileSize, target, ... */
        /* { scope 3: filename */
        ".Lf10425a_00104304:\n"
        "movl $__ZTV12IncludeClass+8, -0x44(%ebp)\n" /* line 861 | include */
        "movl $str_002286b0, -0x68(%ebp)\n" /* line 2177 | defines */
        "movl $str_002157b8, -0x64(%ebp)\n"
        "movl $0, -0x60(%ebp)\n"
        "movl $0, -0x5c(%ebp)\n"
        "movl -0xc4(%ebp), %ebx\n" /* line 2179 | mid */
        "testl %ebx, %ebx\n" /* mid */
        "jne .Lf10425a_001043e2\n"
        "movl $0x66666667, %edx\n" /* line 2181 */
        "movl -0xc0(%ebp), %eax\n" /* shaderVersion */
        "imull %edx\n"
        "sarl $2, %edx\n"
        "movl -0xc0(%ebp), %eax\n" /* shaderVersion */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "addl %eax, %eax\n"
        "movl -0xc0(%ebp), %ecx\n" /* shaderVersion */
        "subl %eax, %ecx\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002286b4, 8(%esp)\n" /* "vs_%i_%i" */
        "movl $0x10, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* target */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $str_002286c0, -0xb8(%ebp)\n" /* entryPoint */
        ".Lf10425a_0010438a:\n"
        "movl -0xb4(%ebp), %edx\n" /* line 2191 | filename */
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002286dc, 8(%esp)\n" /* "materials/shaders/%s" */
        "movl $0x40, 4(%esp)\n"
        "leal -0xa8(%ebp), %ecx\n" /* filename */
        "movl %ecx, (%esp)\n"
        "calll Com_sprintf\n"
        /* { scope 4: bot */
        /* { scope 5 */
        "movl mtlLoadGlob, %edi\n" /* line 877 | top */
        "subl $1, %edi\n" /* top */
        "jns .Lf10425a_0010443c\n"
        /* } scope */
        /* } scope */
        ".Lf10425a_001043bd:\n"
        "leal -0xa8(%ebp), %edx\n" /* line 2194 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $str_002286f4, (%esp)\n" /* "Shader '%s' wasn't preloaded
" */
        "calll Com_ScriptWarning\n"
        "xorl %edi, %edi\n" /* top */
        /* } scope */
        /* } scope */
        /* } scope */
        "movl %edi, %eax\n" /* line 2314 | mtlShader */
        "addl $0xfc, %esp\n"
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1 */
        /* { scope 2: filename, file, fileSize, target, ... */
        /* { scope 3: filename */
        ".Lf10425a_001043e2:\n"
        "movl $0x66666667, %edx\n" /* line 2187 */
        "movl -0xc0(%ebp), %eax\n" /* shaderVersion */
        "imull %edx\n"
        "sarl $2, %edx\n"
        "movl -0xc0(%ebp), %eax\n" /* shaderVersion */
        "sarl $0x1f, %eax\n"
        "subl %eax, %edx\n"
        "leal (%edx, %edx, 4), %eax\n"
        "addl %eax, %eax\n"
        "movl -0xc0(%ebp), %ecx\n" /* shaderVersion */
        "subl %eax, %ecx\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl $str_002286c8, 8(%esp)\n" /* "ps_%i_%i" */
        "movl $0x10, 4(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* target */
        "movl %eax, (%esp)\n"
        "calll Com_sprintf\n"
        "movl $str_002286d4, -0xb8(%ebp)\n" /* entryPoint */
        "jmp .Lf10425a_0010438a\n"
        /* { scope 4: bot */
        /* { scope 5 */
        ".Lf10425a_0010443c:\n"
        "movl $0, -0xb0(%ebp)\n" /* line 877 | bot */
        "jmp .Lf10425a_0010445d\n"
        ".Lf10425a_00104448:\n"
        "addl $1, %ebx\n" /* line 890 | mid */
        "movl %ebx, -0xb0(%ebp)\n" /* mid, bot */
        ".Lf10425a_00104451:\n"
        "cmpl %edi, -0xb0(%ebp)\n" /* line 877 | top, bot */
        "jg .Lf10425a_001043bd\n"
        ".Lf10425a_0010445d:\n"
        "movl -0xb0(%ebp), %ebx\n" /* line 879 | bot, mid */
        "addl %edi, %ebx\n" /* top, mid */
        "sarl $1, %ebx\n" /* mid */
        "leal (%ebx, %ebx, 2), %eax\n" /* line 880 | mid */
        "leal (, %eax, 4), %esi\n"
        "movl %esi, %eax\n"
        "addl mtlLoadGlob+4, %eax\n"
        "movl (%eax), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xb4(%ebp), %eax\n" /* filename */
        "movl %eax, (%esp)\n"
        "calll stricmp\n"
        "cmpl $0, %eax\n" /* line 881 */
        "je .Lf10425a_00104499\n"
        "jge .Lf10425a_00104448\n" /* line 887 */
        "leal -1(%ebx), %edi\n" /* line 888 | mid, top */
        "jmp .Lf10425a_00104451\n"
        ".Lf10425a_00104499:\n"
        "movl %esi, %eax\n" /* line 883 */
        "addl mtlLoadGlob+4, %eax\n"
        "movl 8(%eax), %ecx\n"
        "movl %ecx, -0xbc(%ebp)\n" /* fileSize */
        "movl 4(%eax), %eax\n" /* line 884 */
        "movl %eax, -0x38(%ebp)\n" /* file */
        /* } scope */
        /* } scope */
        "leal -0x1b(%ebp), %eax\n" /* line 2201 */
        "movl %eax, 8(%esp)\n"
        "movl -0xb4(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "leal -0x28(%ebp), %edi\n" /* sourceName, top */
        "movl %edi, (%esp)\n" /* top */
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl -0xc4(%ebp), %ecx\n" /* line 2202 */
        "testl %ecx, %ecx\n"
        "jne .Lf10425a_0010474e\n"
        "leal -0x21(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_00228714, 4(%esp)\n" /* ".vs" */
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        ".Lf10425a_001044f4:\n"
        "leal -0x1f(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $str_002172a8, 4(%esp)\n" /* ".hlsl" */
        "leal -0x30(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl -0x30(%ebp), %eax\n" /* line 591 */
        "movl -0xc(%eax), %esi\n"
        "movl -0x28(%ebp), %eax\n" /* sourceName */
        "movl -0xc(%eax), %ebx\n"
        "leal -0x1d(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 8(%esp)\n"
        "movl $str_002172a8, 4(%esp)\n" /* ".hlsl" */
        "leal -0x2c(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "movl -0x2c(%ebp), %eax\n" /* line 591 */
        "movl -0xc(%eax), %ecx\n"
        /* { scope 4: bot */
        "movl -0x34(%ebp), %edx\n" /* line 269 */
        "movl -0xc(%edx), %eax\n" /* line 585 */
        "movl %eax, 0x10(%esp)\n" /* line 1170 */
        "movl %edx, 0xc(%esp)\n"
        "movl %esi, 8(%esp)\n"
        "subl %ecx, %ebx\n" /* mid */
        "movl %ebx, 4(%esp)\n" /* mid */
        "movl %edi, (%esp)\n" /* top */
        "calll __ZNSs7replaceEmmPKcm\n"
        /* } scope */
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %edx\n" /* line 178 */
        "movl %edx, -0xac(%ebp)\n"
        "cmpl %edx, %ebx\n" /* line 224 */
        "jne .Lf10425a_0010488f\n"
        ".Lf10425a_00104574:\n"
        "movl -0x30(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0xac(%ebp)\n" /* line 224 */
        "jne .Lf10425a_00104831\n"
        ".Lf10425a_00104586:\n"
        "movl -0x34(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0xac(%ebp)\n" /* line 224 */
        "jne .Lf10425a_00104802\n"
        ".Lf10425a_00104598:\n"
        "leal -0x40(%ebp), %eax\n" /* line 2204 | constants */
        "movl %eax, 0x24(%esp)\n"
        "leal -0x3c(%ebp), %eax\n" /* messages */
        "movl %eax, 0x20(%esp)\n"
        "leal -0x48(%ebp), %eax\n" /* shader */
        "movl %eax, 0x1c(%esp)\n"
        "movl $0, 0x18(%esp)\n"
        "leal -0x58(%ebp), %ecx\n" /* target */
        "movl %ecx, 0x14(%esp)\n"
        "movl -0xb8(%ebp), %eax\n" /* entryPoint */
        "movl %eax, 0x10(%esp)\n"
        "leal -0x44(%ebp), %eax\n" /* include */
        "movl %eax, 0xc(%esp)\n"
        "leal -0x68(%ebp), %eax\n" /* defines */
        "movl %eax, 8(%esp)\n"
        "movl -0xbc(%ebp), %edx\n" /* fileSize */
        "movl %edx, 4(%esp)\n"
        "movl -0x28(%ebp), %eax\n" /* sourceName */
        "movl %eax, (%esp)\n"
        "calll D3DXCompileShader\n"
        "movl %eax, %ebx\n" /* mid */
        "movl -0x3c(%ebp), %edx\n" /* line 2211 | messages */
        "testl %edx, %edx\n"
        "je .Lf10425a_00104623\n"
        "movl (%edx), %eax\n" /* line 2213 */
        "movl 0xc(%eax), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *%eax\n"
        "movl %eax, 8(%esp)\n"
        "leal -0xa8(%ebp), %ecx\n" /* filename */
        "movl %ecx, 4(%esp)\n"
        "movl $str_0022871c, (%esp)\n" /* "compiler message(s) for %s:
%s
" */
        "calll Com_Printf\n"
        "movl -0x3c(%ebp), %eax\n" /* line 2214 | messages */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        ".Lf10425a_00104623:\n"
        "testl %ebx, %ebx\n" /* line 2216 | mid */
        "js .Lf10425a_001047d9\n"
        "movl -0x48(%ebp), %edx\n" /* line 2221 | shader */
        "testl %edx, %edx\n"
        "je .Lf10425a_00104782\n"
        "movl (%edx), %eax\n" /* line 2239 */
        "movl 0x10(%eax), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *%eax\n"
        "movl %eax, %esi\n" /* __n */
        "cld\n" /* line 2240 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0xb4(%ebp), %edi\n" /* filename, top */
        "repne scasb %es:(%edi), %al\n" /* top */
        "movl %ecx, %ebx\n" /* mid */
        "notl %ebx\n" /* mid */
        "leal 0x10(%esi, %ebx), %eax\n" /* line 2243 | __n */
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, %edi\n" /* top */
        "leal 0x10(%eax), %eax\n" /* line 2245 */
        "movl %eax, 4(%edi)\n" /* top */
        "leal 0x10(%edi, %esi), %eax\n" /* line 2246 | top */
        "movl %eax, (%edi)\n" /* top */
        "movl %ebx, 8(%esp)\n" /* line 2248 | mid */
        "movl -0xb4(%ebp), %ecx\n" /* filename */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x48(%ebp), %edx\n" /* line 2249 | shader */
        "movl (%edx), %eax\n"
        "movl 0xc(%eax), %eax\n"
        "movl %edx, (%esp)\n"
        "calll *%eax\n"
        "movl 4(%edi), %edx\n" /* top */
        "movl %esi, 8(%esp)\n" /* __n */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        "movl %esi, %eax\n" /* line 2250 | __n */
        "shrw $2, %ax\n"
        "movw %ax, 8(%edi)\n" /* top */
        "movzbl -0xc4(%ebp), %eax\n" /* line 2252 */
        "movb %al, 0xa(%edi)\n" /* top */
        "movzbl -0xc0(%ebp), %edx\n" /* line 2253 | shaderVersion */
        "movb %dl, 0xb(%edi)\n" /* top */
        "cmpb $0, -0xc4(%ebp)\n" /* line 2256 */
        "jne .Lf10425a_0010476d\n"
        "movl imp_dx, %eax\n" /* line 2258 */
        "movl 8(%eax), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 0x16c(%eax), %ebx\n" /* mid */
        ".Lf10425a_001046e1:\n"
        "leal 0xc(%edi), %eax\n" /* line 2263 | top */
        "movl 4(%edi), %edx\n" /* top */
        "movl %eax, 8(%esp)\n"
        "movl %edx, 4(%esp)\n"
        "movl %ecx, (%esp)\n"
        "calll *%ebx\n" /* mid */
        "testl %eax, %eax\n" /* line 2266 */
        "js .Lf10425a_0010479f\n"
        "movl -0x48(%ebp), %eax\n" /* line 2273 | shader */
        "movl (%eax), %edx\n"
        "movl 8(%edx), %edx\n"
        "movl %eax, (%esp)\n"
        "calll *%edx\n"
        ".Lf10425a_00104709:\n"
        "movl -0x28(%ebp), %eax\n" /* line 277 | sourceName */
        "leal -0xc(%eax), %ebx\n"
        "cmpl %ebx, -0xac(%ebp)\n" /* line 224 */
        "jne .Lf10425a_00104860\n"
        /* } scope */
        ".Lf10425a_0010471b:\n"
        "testl %edi, %edi\n" /* line 2291 | mtlShader */
        "je .Lf10425a_001042f7\n"
        "movl %edi, 0xc(%esp)\n" /* line 2294 | mtlShader */
        "movl -0xc0(%ebp), %ecx\n" /* shaderVersion */
        "movl %ecx, 8(%esp)\n"
        "movl -0xc4(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0xb4(%ebp), %edx\n" /* filename */
        "movl %edx, (%esp)\n"
        "calll Material_SetShader\n"
        "jmp .Lf10425a_001042f7\n"
        /* { scope 3: filename */
        ".Lf10425a_0010474e:\n"
        "leal -0x19(%ebp), %eax\n" /* line 2202 */
        "movl %eax, 8(%esp)\n"
        "movl $str_00228718, 4(%esp)\n" /* ".ps" */
        "leal -0x34(%ebp), %eax\n"
        "movl %eax, (%esp)\n"
        "calll __ZNSsC1EPKcRKSaIcE\n"
        "jmp .Lf10425a_001044f4\n"
        ".Lf10425a_0010476d:\n"
        "movl imp_dx, %eax\n" /* line 2263 */
        "movl 8(%eax), %ecx\n"
        "movl (%ecx), %eax\n"
        "movl 0x1a8(%eax), %ebx\n" /* mid */
        "jmp .Lf10425a_001046e1\n"
        ".Lf10425a_00104782:\n"
        "leal -0xa8(%ebp), %edx\n" /* line 2227 | filename */
        "movl %edx, 4(%esp)\n"
        "movl $str_00228758, (%esp)\n" /* "%s compilation failed - NULL shader
" */
        "calll Com_ScriptWarning\n"
        "xorl %edi, %edi\n" /* line 472 */
        "jmp .Lf10425a_00104709\n"
        ".Lf10425a_0010479f:\n"
        "movl %eax, (%esp)\n" /* line 2268 */
        "calll R_ErrorDescription\n"
        "movl %eax, 0x10(%esp)\n"
        "movl -0xb8(%ebp), %ecx\n" /* entryPoint */
        "movl %ecx, 0xc(%esp)\n"
        "leal -0x58(%ebp), %eax\n" /* target */
        "movl %eax, 8(%esp)\n"
        "leal -0xa8(%ebp), %edx\n" /* filename */
        "movl %edx, 4(%esp)\n"
        "movl $str_00228780, (%esp)\n" /* "shader creation failed for %s %s %s: %s
" */
        "calll Com_ScriptWarning\n"
        "xorl %edi, %edi\n" /* line 472 */
        "jmp .Lf10425a_00104709\n"
        ".Lf10425a_001047d9:\n"
        "movl %ebx, (%esp)\n" /* line 2218 | mid */
        "calll R_ErrorDescription\n"
        "movl %eax, 8(%esp)\n"
        "leal -0xa8(%ebp), %eax\n" /* filename */
        "movl %eax, 4(%esp)\n"
        "movl $str_0022873c, (%esp)\n" /* "%s compilation failed - %s
" */
        "calll Com_ScriptWarning\n"
        "xorl %edi, %edi\n" /* line 472 */
        "jmp .Lf10425a_00104709\n"
        ".Lf10425a_00104802:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_00104598\n"
        "leal -0x1e(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf10425a_00104598\n"
        ".Lf10425a_00104831:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_00104586\n"
        "leal -0x20(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf10425a_00104586\n"
        ".Lf10425a_00104860:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_0010471b\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf10425a_0010471b\n"
        ".Lf10425a_0010488f:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_00104574\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf10425a_00104574\n"
        ".Lf10425a_001048be:\n"
        "movl %eax, %esi\n"
        ".Lf10425a_001048c0:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        ".Lf10425a_001048c6:\n"
        "movl -0x28(%ebp), %eax\n" /* line 277 | sourceName */
        "leal -0xc(%eax), %edi\n"
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf10425a_00104922\n"
        ".Lf10425a_001048d0:\n"
        "movl %esi, (%esp)\n" /* line 249 */
        "calll __Unwind_Resume\n"
        ".Lf10425a_001048d8:\n"
        "movl %eax, %esi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        ".Lf10425a_001048e0:\n"
        "movl -0x30(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %ebx, %edi\n" /* line 224 */
        "jne .Lf10425a_0010494a\n"
        ".Lf10425a_001048ea:\n"
        "movl -0x34(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "cmpl %ebx, %edi\n" /* line 224 */
        "je .Lf10425a_001048c6\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_001048c0\n"
        "leal -0x1e(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf10425a_001048c6\n"
        ".Lf10425a_00104922:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_001048d0\n"
        "leal -0x1c(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf10425a_001048d0\n"
        ".Lf10425a_0010494a:\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_00104970\n"
        "leal -0x20(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        ".Lf10425a_00104970:\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n"
        "jmp .Lf10425a_001048ea\n"
        ".Lf10425a_0010497b:\n"
        "movl %eax, %esi\n"
        "jmp .Lf10425a_00104970\n"
        ".Lf10425a_0010497f:\n"
        "movl %eax, %esi\n"
        "jmp .Lf10425a_001048d0\n"
        "jmp .Lf10425a_001048be\n"
        "movl %eax, %esi\n"
        "movl -0x2c(%ebp), %eax\n" /* line 277 */
        "leal -0xc(%eax), %edi\n"
        "movl __ZNSs4_Rep20_S_empty_rep_storageE, %ebx\n" /* line 178 */
        "cmpl %ebx, %edi\n" /* line 224 */
        "je .Lf10425a_001048e0\n"
        "subl $4, %eax\n" /* line 226 */
        "movl $0xffffffff, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll __ZN9__gnu_cxx18__exchange_and_addEPVii\n"
        "testl %eax, %eax\n"
        "jg .Lf10425a_001048e0\n"
        "leal -0x1a(%ebp), %eax\n" /* line 227 */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll __ZNSs4_Rep10_M_destroyERKSaIcE\n"
        "jmp .Lf10425a_001048e0\n"
        "jmp .Lf10425a_001048be\n"
        "jmp .Lf10425a_001048d8\n"
        "jmp .Lf10425a_0010497f\n"
        "jmp .Lf10425a_0010497b\n"
    );
}

/* line 3407 — Material instance finalizer: the main material compilation orchestrator.
 * Parses technique set from text, iterates each technique type, loads passes with
 * shaders/state maps/texture states, builds vertex declarations, validates arguments.
 * Register convention: eax=text, edx=material, ecx=imageTrack.
 * 1660 lines — the LARGEST material function, orchestrating the full compilation pipeline:
 * technique iteration → pass loading → shader compilation → argument binding → validation. */
static __attribute__((naked))
Bool Material_FinishLoadingInstance(MaterialObj *material, int imageTrack)
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 3407 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x34c, %esp\n"
        "movl %eax, -0x308(%ebp)\n"
        "movl %edx, -0x30c(%ebp)\n"
        /* { scope 1: techniqueSet, passIndex, setup */
        "addl %eax, (%eax)\n" /* line 3435 */
        "addl %eax, 4(%eax)\n" /* line 3436 */
        "movl -0x308(%ebp), %eax\n" /* line 3440 */
        "addl 0x3c(%eax), %eax\n"
        "movl -0x308(%ebp), %edx\n" /* line 3441 */
        "movl %eax, 0x3c(%edx)\n"
        "cmpw $0, 0x34(%edx)\n" /* line 3442 */
        "jne .Lf1049de_00104db1\n"
        "movl -0x308(%ebp), %eax\n"
        "movl -0x308(%ebp), %ecx\n"
        ".Lf1049de_00104a24:\n"
        "addl 0x40(%eax), %eax\n" /* line 3448 */
        "movl %eax, 0x40(%ecx)\n" /* line 3449 */
        "cmpw $0, 0x36(%ecx)\n" /* line 3450 */
        "jne .Lf1049de_00104ae6\n"
        "movl -0x308(%ebp), %ecx\n"
        "addl 0x38(%ecx), %ecx\n" /* line 3465 */
        "movl %ecx, -0x304(%ebp)\n" /* techniqueSet */
        /* { scope 2: filename, file, text, techType, ... */
        "movl %ecx, (%esp)\n" /* line 3251 */
        "calll Material_FindTechniqueSet\n"
        "movl %eax, -0x300(%ebp)\n" /* techniqueSet */
        "testl %eax, %eax\n" /* line 3252 */
        "je .Lf1049de_00104b3d\n"
        ".Lf1049de_00104a5a:\n"
        "movl %eax, %esi\n" /* usingTechnique */
        /* } scope */
        ".Lf1049de_00104a5c:\n"
        "movl -0x308(%ebp), %ecx\n" /* line 3466 */
        "movl %esi, 0x38(%ecx)\n" /* constantIndex */
        "testl %esi, %esi\n" /* line 3467 | constantIndex */
        "je .Lf1049de_00104da4\n"
        "movl %esi, -0x2e4(%ebp)\n" /* constantIndex */
        "movl %esi, %eax\n" /* constantIndex */
        "jmp .Lf1049de_00104aa6\n"
        /* { scope 2: filename, file, text, techType, ... */
        ".Lf1049de_00104a77:\n"
        "cmpw $0, 6(%esi)\n" /* line 3339 | usingTechnique */
        "jne .Lf1049de_00104d2f\n"
        /* } scope */
        ".Lf1049de_00104a82:\n"
        "addl $4, -0x2e4(%ebp)\n" /* line 3358 */
        "movl -0x300(%ebp), %eax\n" /* line 3354 | techniqueSet */
        "addl $0x88, %eax\n"
        "cmpl -0x2e4(%ebp), %eax\n"
        "je .Lf1049de_00104ed5\n"
        "movl -0x2e4(%ebp), %eax\n"
        ".Lf1049de_00104aa6:\n"
        "movl 4(%eax), %esi\n" /* line 3356 | usingTechnique */
        "testl %esi, %esi\n" /* usingTechnique */
        "je .Lf1049de_00104a82\n"
        "movl -0x300(%ebp), %edx\n" /* line 3358 | techniqueSet */
        "movl (%edx), %edi\n" /* techniqueSetName */
        /* { scope 2: filename, file, text, techType, ... */
        "movl imp_r_rendererInUse, %eax\n" /* line 3335 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lf1049de_00104a77\n"
        /* { scope 3: passIndex, techniqueNames, name, filename, ... */
        /* { scope 4: filename, file, text, passCount, ... */
        "cmpw $0, 6(%esi)\n" /* line 3320 | usingTechnique */
        "jne .Lf1049de_00104cc5\n"
        ".Lf1049de_00104acd:\n"
        "movl $1, %eax\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1049de_00104ad2:\n"
        "testb %al, %al\n" /* line 3358 */
        "jne .Lf1049de_00104a82\n"
        ".Lf1049de_00104ad6:\n"
        "xorl %eax, %eax\n"
        ".Lf1049de_00104ad8:\n"
        "movzbl %al, %eax\n" /* line 3469 */
        /* } scope */
        "addl $0x34c, %esp\n" /* line 3470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: techniqueSet, passIndex, setup */
        ".Lf1049de_00104ae6:\n"
        "movl %eax, %ebx\n" /* line 3450 | techniqueIndex */
        "xorl %esi, %esi\n" /* constantIndex */
        "movl -0x308(%ebp), %eax\n"
        "jmp .Lf1049de_00104af4\n"
        ".Lf1049de_00104af2:\n"
        "movl %edx, %eax\n"
        ".Lf1049de_00104af4:\n"
        "addl (%ebx), %eax\n" /* line 3454 | techniqueIndex */
        "movl %eax, (%esp)\n"
        "calll Material_RegisterString\n"
        "movl %eax, (%ebx)\n" /* techniqueIndex */
        "testl %eax, %eax\n" /* line 3455 */
        "je .Lf1049de_00104da4\n"
        "addl $1, %esi\n" /* line 3450 | constantIndex */
        "addl $0x14, %ebx\n" /* techniqueIndex */
        "movl -0x308(%ebp), %edx\n"
        "movzwl 0x36(%edx), %eax\n"
        "cmpl %eax, %esi\n" /* constantIndex */
        "jl .Lf1049de_00104af2\n"
        "movl %edx, %ecx\n"
        "addl 0x38(%ecx), %ecx\n" /* line 3465 */
        "movl %ecx, -0x304(%ebp)\n" /* techniqueSet */
        /* { scope 2: filename, file, text, techType, ... */
        "movl %ecx, (%esp)\n" /* line 3251 */
        "calll Material_FindTechniqueSet\n"
        "movl %eax, -0x300(%ebp)\n" /* techniqueSet */
        "testl %eax, %eax\n" /* line 3252 */
        "jne .Lf1049de_00104a5a\n"
        /* { scope 3: passIndex, techniqueNames, name, filename, ... */
        ".Lf1049de_00104b3d:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 3139 */
        "movl (%eax), %eax\n"
        "movl $str_002287ac, %edx\n" /* "materials_dx7/techniquesets/%s.techset" */
        "cmpl $2, 8(%eax)\n"
        "movl $str_002287d4, %eax\n" /* "materials/techniquesets/%s.techset" */
        "cmovnel %eax, %edx\n"
        "movl -0x304(%ebp), %esi\n" /* line 3163 | techniqueSet, usingTechnique */
        "movl %esi, 0xc(%esp)\n" /* usingTechnique */
        "movl %edx, 8(%esp)\n"
        "movl $0x40, 4(%esp)\n"
        "leal -0x8c(%ebp), %esi\n" /* filename, usingTechnique */
        "movl %esi, (%esp)\n" /* usingTechnique */
        "calll Com_sprintf\n"
        "leal -0x2c(%ebp), %eax\n" /* line 3164 | file */
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n" /* usingTechnique */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 3165 */
        "js .Lf1049de_001059c2\n"
        "cld\n" /* line 3171 */
        "movl $0xffffffff, %ecx\n"
        "xorl %eax, %eax\n"
        "movl -0x304(%ebp), %edi\n" /* techniqueSet, technique */
        "repne scasb %es:(%edi), %al\n" /* technique */
        "movl %ecx, %ebx\n" /* techniqueIndex */
        "notl %ebx\n" /* techniqueIndex */
        "leal 0x8c(%ebx), %eax\n" /* line 3172 | techniqueIndex */
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, -0x300(%ebp)\n" /* techniqueSet */
        "addl $0x8c, %eax\n" /* line 3173 */
        "movl -0x300(%ebp), %edx\n" /* techniqueSet */
        "movl %eax, (%edx)\n"
        "movl %ebx, 8(%esp)\n" /* line 3174 | techniqueIndex */
        "movl -0x304(%ebp), %ecx\n" /* techniqueSet */
        "movl %ecx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x2c(%ebp), %eax\n" /* line 3176 | file */
        "movl %eax, -0x20(%ebp)\n" /* text */
        "movl %esi, (%esp)\n" /* line 3177 | usingTechnique */
        "calll Com_BeginParseSession\n"
        "movl $str_0022831c, (%esp)\n" /* line 3178 */
        "calll Com_SetScriptWarningPrefix\n"
        "movl $0, (%esp)\n" /* line 3179 */
        "calll Com_SetSpaceDelimited\n"
        "movl $1, (%esp)\n" /* line 3180 */
        "calll Com_SetKeepStringQuotes\n"
        "movl $0, -0x2fc(%ebp)\n" /* techTypeCount */
        "xorl %esi, %esi\n" /* usingTechnique */
        ".Lf1049de_00104c19:\n"
        "leal -0x20(%ebp), %eax\n" /* line 3185 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, -0x2f4(%ebp)\n" /* name */
        "movzbl (%eax), %eax\n" /* line 3186 */
        "testb %al, %al\n"
        "je .Lf1049de_00104fa5\n"
        "cmpb $0x22, %al\n" /* line 3189 */
        "je .Lf1049de_00104ef0\n"
        "movl -0x2fc(%ebp), %eax\n" /* line 3215 | techTypeCount */
        "testl %eax, %eax\n"
        "je .Lf1049de_001059dd\n"
        "movl %esi, %eax\n" /* line 3221 | usingTechnique */
        "testb %al, %al\n"
        "je .Lf1049de_00104c91\n"
        "movl -0x2f4(%ebp), %edx\n" /* line 3048 | name */
        "movl %edx, (%esp)\n"
        "calll Material_FindTechnique\n"
        "movl %eax, %edi\n" /* token */
        "testl %eax, %eax\n" /* line 3049 */
        "je .Lf1049de_00104ff0\n"
        ".Lf1049de_00104c69:\n"
        "movl -0x2fc(%ebp), %eax\n" /* line 3229 | techTypeCount */
        "testl %eax, %eax\n"
        "jle .Lf1049de_00104c91\n"
        "xorl %edx, %edx\n"
        ".Lf1049de_00104c75:\n"
        "movl -0x158(%ebp, %edx, 4), %eax\n" /* line 3230 */
        "movl -0x300(%ebp), %ecx\n" /* techniqueSet */
        "movl %edi, 4(%ecx, %eax, 4)\n" /* technique */
        "addl $1, %edx\n" /* line 3229 */
        "cmpl %edx, -0x2fc(%ebp)\n" /* techTypeCount */
        "jne .Lf1049de_00104c75\n"
        ".Lf1049de_00104c91:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "leal -0x20(%ebp), %esi\n" /* text */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 3234 */
        "je .Lf1049de_00104f9b\n"
        "movl $0, -0x2fc(%ebp)\n" /* line 3180 | techTypeCount */
        "xorl %esi, %esi\n" /* usingTechnique */
        "jmp .Lf1049de_00104c19\n"
        /* } scope */
        /* } scope */
        /* { scope 2: filename, file, text, techType, ... */
        /* { scope 3: passIndex, techniqueNames, name, filename, ... */
        /* { scope 4: filename, file, text, passCount, ... */
        ".Lf1049de_00104cc5:\n"
        "movl $0, -0x2e8(%ebp)\n" /* line 3320 | passIndex */
        "leal 0x14(%esi), %ebx\n" /* usingTechnique, techniqueIndex */
        "movl %ebx, 4(%esp)\n" /* line 3322 | techniqueIndex */
        "movl $2, (%esp)\n"
        "movl (%esi), %ecx\n" /* usingTechnique */
        "movl %edi, %edx\n" /* technique */
        "movl -0x308(%ebp), %eax\n"
        "calll Material_ValidatePassArguments\n"
        "testb %al, %al\n"
        "je .Lf1049de_00104d28\n"
        ".Lf1049de_00104cf0:\n"
        "addl $1, -0x2e8(%ebp)\n" /* line 3320 | passIndex */
        "addl $0x5c, %ebx\n" /* techniqueIndex */
        "movzwl 6(%esi), %eax\n" /* usingTechnique */
        "cmpl %eax, -0x2e8(%ebp)\n" /* passIndex */
        "jge .Lf1049de_00104acd\n"
        "movl %ebx, 4(%esp)\n" /* line 3322 | techniqueIndex */
        "movl $2, (%esp)\n"
        "movl (%esi), %ecx\n" /* usingTechnique */
        "movl %edi, %edx\n" /* technique */
        "movl -0x308(%ebp), %eax\n"
        "calll Material_ValidatePassArguments\n"
        "testb %al, %al\n"
        "jne .Lf1049de_00104cf0\n"
        ".Lf1049de_00104d28:\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1049de_00104ad2\n"
        /* } scope */
        /* } scope */
        ".Lf1049de_00104d2f:\n"
        "movl %esi, %ebx\n" /* line 3339 | usingTechnique, techniqueIndex */
        "movl $0, -0x2ec(%ebp)\n" /* passIndex */
        "jmp .Lf1049de_00104d7c\n"
        ".Lf1049de_00104d3d:\n"
        "movl 0x1c(%ebx), %eax\n" /* line 3343 | techniqueIndex */
        "movl %eax, 4(%esp)\n"
        "movzwl 0x18(%ebx), %eax\n" /* techniqueIndex */
        "movl %eax, (%esp)\n"
        "movl (%esi), %ecx\n" /* usingTechnique */
        "movl %edi, %edx\n" /* techniqueSetName */
        "movl -0x308(%ebp), %eax\n"
        "calll Material_ValidatePassArguments\n"
        "testb %al, %al\n"
        "je .Lf1049de_00104ad6\n"
        "addl $1, -0x2ec(%ebp)\n" /* line 3339 | passIndex */
        "addl $0x1c, %ebx\n" /* techniqueIndex */
        "movzwl 6(%esi), %eax\n" /* usingTechnique */
        "cmpl %eax, -0x2ec(%ebp)\n" /* passIndex */
        "jge .Lf1049de_00104a82\n"
        ".Lf1049de_00104d7c:\n"
        "movl 0x20(%ebx), %eax\n" /* line 3341 | techniqueIndex */
        "movl %eax, 4(%esp)\n"
        "movzwl 0x1a(%ebx), %eax\n" /* techniqueIndex */
        "movl %eax, (%esp)\n"
        "movl (%esi), %ecx\n" /* usingTechnique */
        "movl %edi, %edx\n" /* techniqueSetName */
        "movl -0x308(%ebp), %eax\n"
        "calll Material_ValidatePassArguments\n"
        "testb %al, %al\n"
        "jne .Lf1049de_00104d3d\n"
        /* } scope */
        "xorl %eax, %eax\n" /* line 3358 */
        "jmp .Lf1049de_00104ad8\n"
        ".Lf1049de_00104da4:\n"
        "xorl %eax, %eax\n" /* line 3469 */
        /* } scope */
        "addl $0x34c, %esp\n" /* line 3470 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: techniqueSet, passIndex, setup */
        ".Lf1049de_00104db1:\n"
        "movl %eax, %esi\n" /* line 3442 | constantIndex */
        "xorl %edi, %edi\n" /* textureIndex */
        "movl -0x308(%ebp), %eax\n"
        "addl (%esi), %eax\n" /* line 3032 | stageIndex */
        "movl %eax, (%esp)\n"
        "calll Material_RegisterString\n"
        "movl %eax, (%esi)\n" /* stageIndex */
        "movzbl 5(%esi), %eax\n" /* line 3033 | stageIndex */
        "cmpb $5, %al\n"
        "je .Lf1049de_00104e49\n"
        ".Lf1049de_00104dcf:\n"
        "leal 8(%esi), %ebx\n" /* line 3040 | stageIndex, image */
        "movl %eax, %edx\n" /* semantic */
        /* { scope 2: filename, file, text, techType, ... */
        "movl imp_r_rendererInUse, %eax\n" /* line 2981 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "jne .Lf1049de_00104dec\n"
        "leal -3(%edx), %eax\n" /* line 2983 */
        "cmpb $1, %al\n"
        "jbe .Lf1049de_00104edf\n"
        ".Lf1049de_00104dec:\n"
        "movl -0x30c(%ebp), %ecx\n" /* line 2992 */
        "movl %ecx, 8(%esp)\n"
        "movzbl %dl, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl -0x308(%ebp), %eax\n"
        "addl (%ebx), %eax\n" /* error */
        "movl %eax, (%esp)\n"
        "calll Image_Register\n"
        "movl %eax, (%ebx)\n" /* error */
        "testl %eax, %eax\n"
        "setne %al\n"
        /* } scope */
        ".Lf1049de_00104e14:\n"
        "movzbl %al, %eax\n" /* line 3040 */
        ".Lf1049de_00104e17:\n"
        "testl %eax, %eax\n" /* line 3444 */
        "je .Lf1049de_00104da4\n"
        "addl $1, %edi\n" /* line 3442 | textureIndex */
        "addl $0xc, %esi\n" /* constantIndex */
        "movl -0x308(%ebp), %edx\n"
        "movzwl 0x34(%edx), %eax\n"
        "cmpl %eax, %edi\n" /* textureIndex */
        "jge .Lf1049de_00104ecc\n"
        "movl %edx, %eax\n"
        "addl (%esi), %eax\n" /* line 3032 | stageIndex */
        "movl %eax, (%esp)\n"
        "calll Material_RegisterString\n"
        "movl %eax, (%esi)\n" /* stageIndex */
        "movzbl 5(%esi), %eax\n" /* line 3033 | stageIndex */
        "cmpb $5, %al\n"
        "jne .Lf1049de_00104dcf\n"
        ".Lf1049de_00104e49:\n"
        "movl -0x308(%ebp), %ebx\n" /* line 3035 | error */
        "addl 8(%esi), %ebx\n" /* stageIndex, error */
        "movl %ebx, 8(%esi)\n" /* error, stageIndex */
        /* { scope 2: filename, file, text, techType, ... */
        "movzwl (%ebx), %eax\n" /* line 2958 | error */
        "movl %eax, -0xc4(%ebp)\n"
        "movl %eax, -0xc0(%ebp)\n" /* line 2959 */
        "movl 4(%ebx), %eax\n" /* line 2960 | error */
        "movl %eax, -0xbc(%ebp)\n"
        "movl 8(%ebx), %eax\n" /* line 2961 | error */
        "movl %eax, -0xb8(%ebp)\n"
        "movl $0x44480000, -0xb4(%ebp)\n" /* line 2962 */
        "movl 0x10(%ebx), %eax\n" /* line 2963 | error */
        "movl %eax, -0xb0(%ebp)\n"
        "movl 0x14(%ebx), %eax\n" /* line 2964 | error */
        "movl %eax, -0xac(%ebp)\n"
        "movl 0x18(%ebx), %eax\n" /* line 2965 | error */
        "movl %eax, -0xa8(%ebp)\n"
        "movl 0xc(%ebx), %eax\n" /* line 2966 | error */
        "movl %eax, -0xa4(%ebp)\n"
        "movl $0, -0x90(%ebp)\n" /* line 2967 */
        "leal -0xd0(%ebp), %eax\n" /* line 2969 | setup */
        "movl %eax, (%esp)\n"
        "calll R_LoadWaterSetup\n"
        "movl %eax, 0x1c(%ebx)\n" /* error */
        /* } scope */
        "testl %eax, %eax\n" /* line 3037 */
        "setne %al\n"
        "movzbl %al, %eax\n"
        "jmp .Lf1049de_00104e17\n"
        ".Lf1049de_00104ecc:\n"
        "movl %edx, %eax\n"
        "movl %edx, %ecx\n"
        "jmp .Lf1049de_00104a24\n"
        ".Lf1049de_00104ed5:\n"
        "movl $1, %eax\n" /* line 3354 */
        "jmp .Lf1049de_00104ad8\n"
        /* { scope 2: filename, file, text, techType, ... */
        ".Lf1049de_00104edf:\n"
        "movl $0, 8(%esi)\n" /* line 2985 | stageIndex */
        "movl $1, %eax\n"
        "jmp .Lf1049de_00104e14\n"
        /* } scope */
        /* { scope 2: filename, file, text, techType, ... */
        /* { scope 3: passIndex, techniqueNames, name, filename, ... */
        ".Lf1049de_00104ef0:\n"
        "cmpl $0x22, -0x2fc(%ebp)\n" /* line 3191 | techTypeCount */
        "je .Lf1049de_00105b11\n"
        /* { scope 4: filename, file, text, passCount, ... */
        "leal -0x2c8(%ebp), %eax\n" /* line 3123 | techniqueNames */
        "movl $0x88, 8(%esp)\n"
        "movl $__ZZ29Material_TechniqueTypeForNamePKcE5C.359, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "xorl %ebx, %ebx\n" /* techniqueIndex */
        "jmp .Lf1049de_00104f2b\n"
        ".Lf1049de_00104f1f:\n"
        "addl $1, %ebx\n" /* line 3126 | techniqueIndex */
        "cmpl $0x22, %ebx\n" /* techniqueIndex */
        "je .Lf1049de_00104fe6\n"
        ".Lf1049de_00104f2b:\n"
        "movl -0x2c8(%ebp, %ebx, 4), %eax\n" /* line 3128 */
        "movl %eax, 4(%esp)\n"
        "movl -0x2f4(%ebp), %ecx\n" /* name */
        "movl %ecx, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "jne .Lf1049de_00104f1f\n"
        "movl %ebx, %eax\n" /* techniqueIndex */
        /* } scope */
        ".Lf1049de_00104f4a:\n"
        "movl -0x2fc(%ebp), %edx\n" /* line 3197 | techTypeCount */
        "movl %eax, -0x158(%ebp, %edx, 4)\n"
        "cmpl $0x22, %eax\n" /* line 3198 */
        "je .Lf1049de_00105aec\n"
        "cmpb $0, g_useTechnique(%eax)\n" /* line 3204 */
        "movl $1, %eax\n"
        "cmovnel %eax, %esi\n" /* usingTechnique */
        "addl $1, %edx\n" /* line 3206 */
        "movl %edx, -0x2fc(%ebp)\n" /* techTypeCount */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222928, 4(%esp)\n" /* ":" */
        "leal -0x20(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 3207 */
        "jne .Lf1049de_00104c19\n"
        ".Lf1049de_00104f9b:\n"
        "movl $0, -0x300(%ebp)\n" /* line 3234 | techniqueSet */
        ".Lf1049de_00104fa5:\n"
        "calll Com_EndParseSession\n" /* line 3241 */
        "movl -0x2c(%ebp), %eax\n" /* line 3242 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        /* } scope */
        "movl -0x300(%ebp), %esi\n" /* line 3256 | techniqueSet, usingTechnique */
        "testl %esi, %esi\n" /* usingTechnique */
        "je .Lf1049de_00105985\n"
        "movl -0x300(%ebp), %eax\n" /* line 3259 | techniqueSet */
        "movl %eax, 4(%esp)\n"
        "movl -0x304(%ebp), %edx\n" /* techniqueSet */
        "movl %edx, (%esp)\n"
        "calll Material_SetTechniqueSet\n"
        "movl -0x300(%ebp), %esi\n" /* techniqueSet, usingTechnique */
        "jmp .Lf1049de_00104a5c\n"
        /* { scope 3: passIndex, techniqueNames, name, filename, ... */
        /* { scope 4: filename, file, text, passCount, ... */
        ".Lf1049de_00104fe6:\n"
        "movl $0x22, %eax\n" /* line 3126 */
        "jmp .Lf1049de_00104f4a\n"
        /* } scope */
        ".Lf1049de_00104ff0:\n"
        "movl imp_r_rendererInUse, %eax\n" /* line 3054 */
        "movl (%eax), %eax\n"
        "cmpl $2, 8(%eax)\n"
        "je .Lf1049de_00105444\n"
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        "movl -0x2f4(%ebp), %esi\n" /* line 2798 | name, stageIndex */
        "movl %esi, 0xc(%esp)\n" /* stageIndex */
        "movl $str_002289b4, 8(%esp)\n" /* "materials/techniques/%s.tech" */
        "movl $0x40, 4(%esp)\n"
        "leal -0xd0(%ebp), %ebx\n" /* setup, error */
        "movl %ebx, (%esp)\n" /* error */
        "calll Com_sprintf\n"
        "leal -0x24(%ebp), %eax\n" /* line 2799 | file */
        "movl %eax, 4(%esp)\n"
        "movl %ebx, (%esp)\n" /* error */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 2800 */
        "js .Lf1049de_00105d9b\n"
        "movl -0x24(%ebp), %eax\n" /* line 2806 | file */
        "movl %eax, -0x28(%ebp)\n" /* text */
        "movl %ebx, (%esp)\n" /* line 2807 | error */
        "calll Com_BeginParseSession\n"
        "movl $str_0022831c, (%esp)\n" /* line 2808 */
        "calll Com_SetScriptWarningPrefix\n"
        "movl $0, (%esp)\n" /* line 2809 */
        "calll Com_SetSpaceDelimited\n"
        "movw $0, -0x1c(%ebp)\n" /* line 2812 | techFlags */
        "movl $0, -0x2d0(%ebp)\n"
        "leal -0x2c8(%ebp), %edx\n" /* techniqueNames */
        "movl %edx, -0x318(%ebp)\n"
        ".Lf1049de_00105082:\n"
        "movl -0x2d0(%ebp), %ecx\n"
        "movw %cx, -0x2f0(%ebp)\n" /* passCount */
        "leal -0x28(%ebp), %esi\n" /* line 2815 | text, stageIndex */
        "movl %esi, (%esp)\n" /* stageIndex */
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 2816 */
        "testb %dl, %dl\n"
        "je .Lf1049de_00105d48\n"
        "cmpb $0x7b, %dl\n" /* line 2818 */
        "jne .Lf1049de_00105d4f\n"
        "movl -0x318(%ebp), %edx\n" /* line 2381 */
        "movl %esi, %eax\n"
        "calll Material_LoadPassStateMap\n"
        "testb %al, %al\n"
        "je .Lf1049de_0010530e\n"
        "movl $0, -0x2cc(%ebp)\n"
        "movl $0xfffffffe, -0x2d4(%ebp)\n"
        "movl $0xffffffff, -0x314(%ebp)\n"
        /* { scope 6 */
        ".Lf1049de_001050e1:\n"
        "leal -0x28(%ebp), %eax\n" /* line 1488 | text */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl $7, %ecx\n" /* line 1489 */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $str_0022812c, %edi\n" /* source */
        "repe cmpsb %es:(%edi), (%esi)\n" /* source */
        "movl $0, %ebx\n" /* token */
        "je .Lf1049de_0010510c\n"
        "movzbl -1(%esi), %ebx\n" /* token */
        "movzbl -1(%edi), %ecx\n" /* source */
        "subl %ecx, %ebx\n" /* token */
        ".Lf1049de_0010510c:\n"
        "testl %ebx, %ebx\n" /* token */
        "jne .Lf1049de_00105c02\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "leal -0x28(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1499 */
        "je .Lf1049de_0010530e\n"
        "leal -0x28(%ebp), %esi\n" /* line 1501 | text */
        "movl %esi, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* token */
        /* { scope 7 */
        /* { scope 8 */
        "movl $9, %ecx\n" /* line 1404 */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $str_002278d0, %edi\n" /* "position" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1049de_00105164\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1049de_00105164:\n"
        "testl %eax, %eax\n"
        "jne .Lf1049de_001053de\n"
        "movb $0, -0x2ed(%ebp)\n" /* dest */
        /* } scope */
        /* } scope */
        ".Lf1049de_00105173:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222904, 4(%esp)\n" /* "=" */
        "leal -0x28(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1504 */
        "je .Lf1049de_0010530e\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00228a20, 4(%esp)\n" /* "code" */
        "leal -0x28(%ebp), %esi\n" /* text */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1506 */
        "je .Lf1049de_0010530e\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00217ff8, 4(%esp)\n" /* "." */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1508 */
        "je .Lf1049de_0010530e\n"
        "movl %esi, (%esp)\n" /* line 1510 */
        "calll Com_Parse\n"
        "movl %eax, %ebx\n" /* destName */
        /* { scope 7 */
        /* { scope 8 */
        "movl $9, %ecx\n" /* line 1438 */
        "cld\n"
        "movl %eax, %esi\n"
        "movl $str_002278d0, %edi\n" /* "position" */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %eax\n"
        "je .Lf1049de_00105203\n"
        "movzbl -1(%esi), %eax\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %eax\n"
        ".Lf1049de_00105203:\n"
        "testl %eax, %eax\n"
        "jne .Lf1049de_00105412\n"
        "xorl %edi, %edi\n"
        /* } scope */
        /* } scope */
        ".Lf1049de_0010520d:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "leal -0x28(%ebp), %edx\n" /* text */
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1513 */
        "je .Lf1049de_0010530e\n"
        "movl -0x2cc(%ebp), %eax\n" /* line 1516 */
        "testl %eax, %eax\n"
        "jle .Lf1049de_001053d3\n"
        "movl -0x314(%ebp), %edx\n" /* line 1518 */
        "movzbl -0x4c(%ebp, %edx, 2), %eax\n"
        "movl %edi, %ecx\n" /* source */
        "cmpb %al, %cl\n"
        "ja .Lf1049de_001053d3\n"
        "movl -0x2d4(%ebp), %esi\n" /* line 1519 */
        "leal -0x4c(%ebp, %esi, 2), %ebx\n" /* sourceName */
        "movl %edx, %ecx\n"
        "movl -0x2cc(%ebp), %esi\n"
        "jmp .Lf1049de_0010529d\n"
        ".Lf1049de_00105267:\n"
        "movl -0x314(%ebp), %eax\n" /* line 1522 */
        "subl -0x2d4(%ebp), %eax\n"
        "movzwl (%ebx, %eax, 2), %eax\n" /* sourceName */
        "movw %ax, -0x4c(%ebp, %esi, 2)\n"
        "testl %ecx, %ecx\n" /* line 1516 */
        "jle .Lf1049de_001052c7\n"
        "leal -1(%ecx), %esi\n" /* line 1518 */
        "movl %esi, -0x330(%ebp)\n" /* insertIndex */
        "movzbl (%ebx), %eax\n" /* sourceName */
        "subl $2, %ebx\n" /* sourceName */
        "movl %edi, %edx\n" /* source */
        "cmpb %al, %dl\n"
        "ja .Lf1049de_001052c7\n"
        "movl %ecx, %esi\n" /* line 1519 */
        "movl -0x330(%ebp), %ecx\n" /* insertIndex */
        ".Lf1049de_0010529d:\n"
        "movl %edi, %edx\n" /* line 1520 | source */
        "cmpb %al, %dl\n"
        "jne .Lf1049de_00105267\n"
        "movl -0x314(%ebp), %edx\n"
        "leal -0x4b(%ebp, %edx, 2), %eax\n"
        "movl -0x2d4(%ebp), %edx\n"
        "leal -0x4c(%ebp, %edx, 2), %edx\n"
        "subl %edx, %eax\n"
        "movzbl -0x2ed(%ebp), %edx\n" /* dest */
        "cmpb %dl, (%ebx, %eax)\n" /* sourceName */
        "jae .Lf1049de_00105267\n"
        "movl %esi, %ecx\n"
        ".Lf1049de_001052c7:\n"
        "movl %edi, %eax\n" /* line 1524 | source */
        "movb %al, -0x4c(%ebp, %ecx, 2)\n"
        "movzbl -0x2ed(%ebp), %edx\n" /* line 1525 | dest */
        "movb %dl, -0x4b(%ebp, %ecx, 2)\n"
        "addl $1, -0x2cc(%ebp)\n" /* line 1486 */
        "addl $1, -0x314(%ebp)\n"
        "addl $1, -0x2d4(%ebp)\n"
        "cmpl $0x10, -0x2cc(%ebp)\n"
        "jne .Lf1049de_001050e1\n"
        "movl $0x10, 4(%esp)\n" /* line 1527 */
        "movl $str_00228a58, (%esp)\n" /* "More than %i vertex mappings
" */
        "calll Com_ScriptWarning\n"
        /* } scope */
        ".Lf1049de_0010530e:\n"
        "movl $1, %ebx\n" /* line 2813 | error */
        ".Lf1049de_00105313:\n"
        "calll Com_EndParseSession\n" /* line 2835 */
        "movl -0x24(%ebp), %eax\n" /* line 2836 | file */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "testb %bl, %bl\n" /* line 2837 | error */
        "jne .Lf1049de_00104f9b\n"
        "cmpw $0, -0x2f0(%ebp)\n" /* line 2840 | passCount */
        "je .Lf1049de_00105dba\n"
        "cld\n" /* line 2846 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x2f4(%ebp), %edi\n" /* name, token */
        "movl %ebx, %eax\n" /* error */
        "repne scasb %es:(%edi), %al\n" /* token */
        "movl %ecx, %esi\n" /* stageIndex */
        "notl %esi\n" /* stageIndex */
        "movzwl -0x2f0(%ebp), %ebx\n" /* line 2848 | passCount, error */
        "leal (%ebx, %ebx, 2), %eax\n" /* line 2849 | error */
        "shll $3, %eax\n"
        "subl %ebx, %eax\n" /* error */
        "leal 8(%esi, %eax, 4), %eax\n" /* stageIndex */
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, %edi\n" /* token */
        "leal (, %ebx, 4), %eax\n" /* line 2853 */
        "shll $5, %ebx\n" /* error */
        "subl %eax, %ebx\n" /* error */
        "leal 8(%edi, %ebx), %eax\n" /* token */
        "movl %eax, (%edi)\n" /* token */
        "movl %esi, 8(%esp)\n" /* line 2854 | stageIndex */
        "movl -0x2f4(%ebp), %edx\n" /* name */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movl -0x1c(%ebp), %eax\n" /* line 2855 | techFlags */
        "movw %ax, 4(%edi)\n" /* token */
        "movl -0x2f0(%ebp), %ecx\n" /* line 2856 | passCount */
        ".Lf1049de_0010539f:\n"
        "movw %cx, 6(%edi)\n" /* token */
        "leal 8(%edi), %edx\n" /* line 2857 | token */
        "leal -0x2c8(%ebp), %eax\n" /* techniqueNames */
        "movl %ebx, 8(%esp)\n" /* error */
        "movl %eax, 4(%esp)\n"
        "movl %edx, (%esp)\n"
        "calll memcpy\n"
        /* } scope */
        /* } scope */
        "movl %edi, 4(%esp)\n" /* line 3068 | token */
        "movl -0x2f4(%ebp), %esi\n" /* name, stageIndex */
        "movl %esi, (%esp)\n" /* stageIndex */
        "calll Material_SetTechnique\n"
        "jmp .Lf1049de_00104c69\n"
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        ".Lf1049de_001053d3:\n"
        "movl -0x2cc(%ebp), %ecx\n" /* line 1516 */
        "jmp .Lf1049de_001052c7\n"
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_001053de:\n"
        "movl $str_00222fb0, %edi\n" /* line 1409 */
        "movl $7, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_001053fe\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_001053fe:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_001058db\n"
        "movb $1, -0x2ed(%ebp)\n" /* dest */
        "jmp .Lf1049de_00105173\n"
        /* } scope */
        /* } scope */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_00105412:\n"
        "movl $str_00222fb0, %edi\n" /* line 1443 */
        "movl $7, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_00105432\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_00105432:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105990\n"
        "movl $1, %edi\n"
        "jmp .Lf1049de_0010520d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: filename, file, text, passCount, ... */
        ".Lf1049de_00105444:\n"
        "movl -0x2f4(%ebp), %ecx\n" /* line 2877 | name */
        "movl %ecx, 0xc(%esp)\n"
        "movl $str_00228868, 8(%esp)\n" /* "materials_dx7/techniques/%s.tech" */
        "movl $0x40, 4(%esp)\n"
        "leal -0xd0(%ebp), %ebx\n" /* setup, error */
        "movl %ebx, (%esp)\n" /* error */
        "calll Com_sprintf\n"
        "leal -0x28(%ebp), %esi\n" /* line 2878 | text, stageIndex */
        "movl %esi, 4(%esp)\n" /* stageIndex */
        "movl %ebx, (%esp)\n" /* error */
        "calll FS_ReadFile\n"
        "testl %eax, %eax\n" /* line 2879 */
        "js .Lf1049de_00105d9b\n"
        "movl -0x28(%ebp), %eax\n" /* line 2885 | text */
        "movl %eax, -0x24(%ebp)\n" /* file */
        "movl %ebx, (%esp)\n" /* line 2886 | error */
        "calll Com_BeginParseSession\n"
        "movl $str_0022831c, (%esp)\n" /* line 2887 */
        "calll Com_SetScriptWarningPrefix\n"
        "movl $0, (%esp)\n" /* line 2888 */
        "calll Com_SetSpaceDelimited\n"
        "movl $0, -0x2d8(%ebp)\n"
        "leal -0x2c8(%ebp), %eax\n" /* techniqueNames */
        "movl %eax, -0x324(%ebp)\n"
        ".Lf1049de_001054bf:\n"
        "movl -0x2d8(%ebp), %edx\n"
        "movw %dx, -0x2f6(%ebp)\n" /* passCount */
        "leal -0x24(%ebp), %ecx\n" /* line 2893 | file */
        "movl %ecx, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %edx\n" /* line 2894 */
        "testb %dl, %dl\n"
        "je .Lf1049de_0010581e\n"
        "cmpb $0x7b, %dl\n" /* line 2896 */
        "jne .Lf1049de_00105e17\n"
        "movl -0x324(%ebp), %edx\n" /* line 2771 */
        "leal -0x24(%ebp), %eax\n" /* file */
        "calll Material_LoadPassStateMap\n"
        "testb %al, %al\n"
        "jne .Lf1049de_00105588\n"
        ".Lf1049de_00105501:\n"
        "movl $1, %ebx\n" /* line 2891 | error */
        ".Lf1049de_00105506:\n"
        "calll Com_EndParseSession\n" /* line 2913 */
        "movl -0x28(%ebp), %eax\n" /* line 2914 | text */
        "movl %eax, (%esp)\n"
        "calll FS_FreeFile\n"
        "testb %bl, %bl\n" /* line 2915 | error */
        "jne .Lf1049de_00104f9b\n"
        "cmpw $0, -0x2f6(%ebp)\n" /* line 2918 | passCount */
        "je .Lf1049de_00105f0b\n"
        "cld\n" /* line 2924 */
        "movl $0xffffffff, %ecx\n"
        "movl -0x2f4(%ebp), %edi\n" /* name, token */
        "movl %ebx, %eax\n" /* error */
        "repne scasb %es:(%edi), %al\n" /* token */
        "movl %ecx, %esi\n" /* stageIndex */
        "notl %esi\n" /* stageIndex */
        "movzwl -0x2f6(%ebp), %eax\n" /* line 2926 | passCount */
        "leal (%eax, %eax, 2), %ebx\n" /* error */
        "shll $3, %ebx\n" /* error */
        "subl %eax, %ebx\n" /* error */
        "shll $2, %ebx\n" /* error */
        "leal 8(%ebx, %esi), %eax\n" /* line 2927 | error */
        "movl %eax, (%esp)\n"
        "calll Material_Alloc\n"
        "movl %eax, %edi\n" /* token */
        "leal 8(%eax, %ebx), %eax\n" /* line 2931 */
        "movl %eax, (%edi)\n" /* token */
        "movl %esi, 8(%esp)\n" /* line 2932 | stageIndex */
        "movl -0x2f4(%ebp), %edx\n" /* name */
        "movl %edx, 4(%esp)\n"
        "movl %eax, (%esp)\n"
        "calll memcpy\n"
        "movzwl -0x2f6(%ebp), %ecx\n" /* line 2933 | passCount */
        "jmp .Lf1049de_0010539f\n"
        ".Lf1049de_00105588:\n"
        "xorl %edx, %edx\n" /* line 2771 */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        ".Lf1049de_0010558a:\n"
        "movl s_passOptionsDx7+4(, %edx, 8), %eax\n" /* line 2414 */
        "movl -0x324(%ebp), %esi\n"
        "movb $0, (%esi, %eax)\n"
        "addl $1, %edx\n" /* line 2424 */
        "cmpl $5, %edx\n"
        "jne .Lf1049de_0010558a\n"
        /* } scope */
        /* { scope 6 */
        ".Lf1049de_001055a3:\n"
        "leal -0x24(%ebp), %eax\n" /* line 2441 | file */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl %eax, %edi\n" /* token */
        "xorl %esi, %esi\n" /* optionIter */
        "movl $s_passOptionsDx7, %ebx\n" /* sourceName */
        ".Lf1049de_001055b7:\n"
        "movl (%ebx), %eax\n" /* line 2445 | sourceName */
        "movl %edi, 4(%esp)\n" /* token */
        "movl %eax, (%esp)\n"
        "calll strcmp\n"
        "testl %eax, %eax\n"
        "je .Lf1049de_00105b2c\n"
        "addl $1, %esi\n" /* line 2443 | optionIter */
        "addl $8, %ebx\n" /* sourceName */
        "cmpl $5, %esi\n" /* optionIter */
        "jne .Lf1049de_001055b7\n"
        "calll Com_UngetToken\n" /* line 2459 */
        "xorl %eax, %eax\n"
        /* } scope */
        /* } scope */
        ".Lf1049de_001055df:\n"
        "testb %al, %al\n" /* line 2773 */
        "jne .Lf1049de_00105501\n"
        "movl $0, -0x2dc(%ebp)\n"
        "movl -0x324(%ebp), %ecx\n"
        "addl $0xc, %ecx\n"
        "movl %ecx, -0x320(%ebp)\n"
        /* { scope 5: existing, dest, routing, insertIndex */
        ".Lf1049de_00105600:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00228134, 4(%esp)\n" /* "texture" */
        "leal -0x24(%ebp), %esi\n" /* file */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 976 */
        "jne .Lf1049de_00105855\n"
        ".Lf1049de_00105623:\n"
        "xorl %eax, %eax\n" /* line 947 */
        ".Lf1049de_00105625:\n"
        "testb %al, %al\n" /* line 2708 */
        "je .Lf1049de_00105501\n"
        "movl -0x324(%ebp), %ecx\n" /* line 2710 */
        "addl -0x2dc(%ebp), %ecx\n"
        "movl %ecx, -0x310(%ebp)\n"
        /* { scope 6 */
        "movb $0, 9(%ecx)\n" /* line 2618 */
        "leal -0x24(%ebp), %esi\n" /* line 2620 | file, optionIter */
        "movl %esi, (%esp)\n" /* optionIter */
        "calll Com_Parse\n"
        "movl $str_002288cc, %edi\n" /* line 2621 | token */
        "movl $9, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* optionIter */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token, optionIter */
        "movl $0, %ebx\n" /* token */
        "je .Lf1049de_0010566e\n"
        "movzbl -1(%esi), %ebx\n" /* optionIter, token */
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %ebx\n" /* token */
        ".Lf1049de_0010566e:\n"
        "testl %ebx, %ebx\n" /* token */
        "je .Lf1049de_00105ba9\n"
        "calll Com_UngetToken\n" /* line 2623 */
        /* } scope */
        ".Lf1049de_0010567b:\n"
        "movl -0x2dc(%ebp), %ebx\n" /* line 2710 | samplerIndex */
        "addl $1, %ebx\n" /* samplerIndex */
        "cmpl $1, -0x2dc(%ebp)\n" /* line 2714 */
        "je .Lf1049de_001056df\n"
        "leal -0x24(%ebp), %eax\n" /* line 2717 | file */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movl $str_00228134, %edi\n" /* line 2718 | token */
        "movl $8, %ecx\n"
        "cld\n"
        "movl %eax, %esi\n" /* token */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token */
        "movl $0, %eax\n"
        "je .Lf1049de_001056b8\n"
        "movzbl -1(%esi), %eax\n" /* token */
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %eax\n"
        ".Lf1049de_001056b8:\n"
        "movl %eax, -0x334(%ebp)\n"
        "calll Com_UngetToken\n" /* line 2719 */
        "addl $1, -0x2dc(%ebp)\n"
        "addl $8, -0x320(%ebp)\n"
        "movl -0x334(%ebp), %eax\n" /* line 2706 */
        "testl %eax, %eax\n"
        "je .Lf1049de_00105600\n"
        ".Lf1049de_001056df:\n"
        "cmpw $1, %bx\n" /* line 2722 | samplerIndex */
        "jbe .Lf1049de_00105825\n"
        /* } scope */
        ".Lf1049de_001056e9:\n"
        "movl $0, -0x2e0(%ebp)\n" /* line 2775 */
        "movl -0x324(%ebp), %edi\n" /* token */
        "addl $0x10, %edi\n" /* token */
        "movl -0x324(%ebp), %esi\n" /* stageIndex */
        "addl $0x30, %esi\n" /* stageIndex */
        "movl %esi, -0x31c(%ebp)\n" /* stageIndex */
        /* { scope 5: existing, dest, routing, insertIndex */
        ".Lf1049de_0010570b:\n"
        "movl -0x31c(%ebp), %ebx\n" /* line 2744 | alphaStageBits */
        "addl $0xc, %ebx\n" /* alphaStageBits */
        "leal 0xc(%edi), %eax\n" /* token, colorStageBits */
        /* { scope 6 */
        "movl $0, 0xc(%edi)\n" /* line 2677 | token */
        "movl %eax, 4(%esp)\n" /* line 2678 */
        "movl $1, (%esp)\n"
        "movl $str_0021a750, %ecx\n" /* "rgb" */
        "movl -0x2e0(%ebp), %edx\n"
        "leal -0x24(%ebp), %eax\n" /* file */
        "calll Material_LoadPassTextureStateDx7\n"
        "testb %al, %al\n"
        "je .Lf1049de_00105501\n"
        "movl $0, 0x2c(%edi)\n" /* line 2681 | token */
        "movl %ebx, 4(%esp)\n" /* line 2682 | token */
        "movl $2, (%esp)\n"
        "movl $str_00228950, %ecx\n" /* "a" */
        "movl -0x2e0(%ebp), %edx\n"
        "leal -0x24(%ebp), %eax\n" /* file */
        "calll Material_LoadPassTextureStateDx7\n"
        "testb %al, %al\n"
        "je .Lf1049de_00105501\n"
        /* } scope */
        "movl -0x2e0(%ebp), %esi\n" /* line 2744 | stageIndex */
        "addl $1, %esi\n" /* stageIndex */
        "cmpl $7, -0x2e0(%ebp)\n" /* line 2748 */
        "je .Lf1049de_001057b0\n"
        "leal -0x24(%ebp), %eax\n" /* line 2751 | file */
        "movl %eax, (%esp)\n"
        "calll Com_Parse\n"
        "movzbl (%eax), %ebx\n" /* line 2752 | alphaStageBits */
        "calll Com_UngetToken\n" /* line 2753 */
        "addl $1, -0x2e0(%ebp)\n"
        "addl $4, -0x31c(%ebp)\n"
        "addl $4, %edi\n" /* token */
        "cmpb $0x7d, %bl\n" /* line 2742 | samplerIndex */
        "jne .Lf1049de_0010570b\n"
        ".Lf1049de_001057b0:\n"
        "cmpw $7, %si\n" /* line 2756 | stageIndex */
        "ja .Lf1049de_001057d8\n"
        ".Lf1049de_001057b6:\n"
        "movzwl %si, %eax\n" /* line 2758 | stageIndex */
        "movl -0x324(%ebp), %edx\n"
        "movl $0, 0x1c(%edx, %eax, 4)\n"
        "movl $0, 0x3c(%edx, %eax, 4)\n" /* line 2759 */
        "addl $1, %esi\n" /* line 2760 | stageIndex */
        "cmpw $8, %si\n" /* line 2756 | stageIndex */
        "jne .Lf1049de_001057b6\n"
        /* } scope */
        ".Lf1049de_001057d8:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e508, 4(%esp)\n" /* "}" */
        "leal -0x24(%ebp), %ecx\n" /* file */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2907 */
        "je .Lf1049de_00105501\n"
        "addw $1, -0x2f6(%ebp)\n" /* passCount */
        "addl $1, -0x2d8(%ebp)\n"
        "addl $0x5c, -0x324(%ebp)\n"
        "cmpl $4, -0x2d8(%ebp)\n" /* line 2891 */
        "jne .Lf1049de_001054bf\n"
        ".Lf1049de_0010581e:\n"
        "xorl %ebx, %ebx\n" /* error */
        "jmp .Lf1049de_00105506\n"
        /* { scope 5: existing, dest, routing, insertIndex */
        ".Lf1049de_00105825:\n"
        "movzwl %bx, %eax\n" /* line 2724 | samplerIndex */
        "movl -0x324(%ebp), %ecx\n"
        "movw %bx, 0xe(%ecx, %eax, 8)\n" /* samplerIndex */
        "movw $3, 0xc(%ecx, %eax, 8)\n" /* line 2725 */
        "movl $1, 0x10(%ecx, %eax, 8)\n" /* line 2726 */
        "movb $0, 9(%ecx, %eax)\n" /* line 2727 */
        "addl $1, %ebx\n" /* line 2728 | samplerIndex */
        "cmpw $2, %bx\n" /* line 2722 | samplerIndex */
        "jne .Lf1049de_00105825\n"
        "jmp .Lf1049de_001056e9\n"
        /* { scope 6 */
        ".Lf1049de_00105855:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 958 */
        "jne .Lf1049de_00105ddf\n"
        /* } scope */
        ".Lf1049de_00105875:\n"
        "testb %al, %al\n" /* line 2486 */
        "je .Lf1049de_00105623\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222904, 4(%esp)\n" /* "=" */
        "leal -0x24(%ebp), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2488 */
        "je .Lf1049de_00105623\n"
        "movl -0x320(%ebp), %edx\n" /* line 2491 */
        "leal -0x24(%ebp), %eax\n" /* file */
        "calll Material_ParseSamplerSource\n"
        "testb %al, %al\n"
        "je .Lf1049de_00105623\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "leal -0x24(%ebp), %edx\n" /* file */
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "jmp .Lf1049de_00105625\n"
        /* } scope */
        /* } scope */
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_001058db:\n"
        "movl $str_002278dc, %edi\n" /* line 1414 */
        "movl $6, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_001058fb\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_001058fb:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105a02\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "leal -0x28(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1392 */
        "je .Lf1049de_0010530e\n"
        "leal -0x28(%ebp), %edx\n" /* line 1394 | text */
        "movl %edx, (%esp)\n"
        "calll Com_ParseInt\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 1395 */
        "js .Lf1049de_0010593c\n"
        "cmpl $1, %eax\n"
        "jle .Lf1049de_00105954\n"
        ".Lf1049de_0010593c:\n"
        "movl $1, 8(%esp)\n" /* line 1396 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002289d4, (%esp)\n" /* "index '%i' is not in the range [0, %i]
" */
        "calll Com_ScriptWarning\n"
        ".Lf1049de_00105954:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "leal -0x28(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1416 */
        "je .Lf1049de_0010530e\n"
        "addb $2, %bl\n" /* line 1418 | index */
        "movb %bl, -0x2ed(%ebp)\n" /* index, dest */
        "jmp .Lf1049de_00105173\n"
        ".Lf1049de_00105985:\n"
        "movl -0x300(%ebp), %esi\n" /* techniqueSet */
        "jmp .Lf1049de_00104a5c\n"
        /* } scope */
        /* } scope */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_00105990:\n"
        "movl $str_00228a28, %edi\n" /* line 1448 */
        "movl $8, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_001059b0\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_001059b0:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105aba\n"
        "movl $6, %edi\n"
        "jmp .Lf1049de_0010520d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1049de_001059c2:\n"
        "movl %esi, 4(%esp)\n" /* line 3167 | usingTechnique */
        "movl $str_002287f8, (%esp)\n" /* "^1ERROR: Couldn't open techniqueSet '%s'
" */
        "calll Com_Printf\n"
        "movl -0x300(%ebp), %esi\n" /* techniqueSet, usingTechnique */
        "jmp .Lf1049de_00104a5c\n"
        ".Lf1049de_001059dd:\n"
        "movl -0x2f4(%ebp), %edx\n" /* line 3217 | name */
        "movl %edx, 4(%esp)\n"
        "movl $str_00228848, (%esp)\n" /* "Unknown technique type '%s'
" */
        "calll Com_ScriptWarning\n"
        "movl $0, -0x300(%ebp)\n" /* techniqueSet */
        "jmp .Lf1049de_00104fa5\n"
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_00105a02:\n"
        "movl $str_002288cc, %edi\n" /* line 1421 */
        "movl $9, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_00105a22\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_00105a22:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105aa5\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "leal -0x28(%ebp), %esi\n" /* text */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1392 */
        "je .Lf1049de_0010530e\n"
        "movl %esi, (%esp)\n" /* line 1394 */
        "calll Com_ParseInt\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 1395 */
        "js .Lf1049de_00105a5c\n"
        "cmpl $7, %eax\n"
        "jle .Lf1049de_00105a74\n"
        ".Lf1049de_00105a5c:\n"
        "movl $7, 8(%esp)\n" /* line 1396 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002289d4, (%esp)\n" /* "index '%i' is not in the range [0, %i]
" */
        "calll Com_ScriptWarning\n"
        ".Lf1049de_00105a74:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "leal -0x28(%ebp), %edx\n" /* text */
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1423 */
        "je .Lf1049de_0010530e\n"
        "addb $4, %bl\n" /* line 1425 | index */
        "movb %bl, -0x2ed(%ebp)\n" /* index, dest */
        "jmp .Lf1049de_00105173\n"
        ".Lf1049de_00105aa5:\n"
        "movl %ebx, 4(%esp)\n" /* line 1429 | index */
        "movl $str_002289fc, (%esp)\n" /* "unknown stream destination '%s'
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1049de_0010530e\n"
        /* } scope */
        /* } scope */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_00105aba:\n"
        "movl $str_00228a30, %edi\n" /* line 1453 */
        "movl $9, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_00105ada\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_00105ada:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105d69\n"
        "movl $5, %edi\n"
        "jmp .Lf1049de_0010520d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1049de_00105aec:\n"
        "movl -0x2f4(%ebp), %eax\n" /* line 3200 | name */
        "movl %eax, 4(%esp)\n"
        "movl $str_00228848, (%esp)\n" /* "Unknown technique type '%s'
" */
        "calll Com_ScriptWarning\n"
        "movl $0, -0x300(%ebp)\n" /* techniqueSet */
        "jmp .Lf1049de_00104fa5\n"
        ".Lf1049de_00105b11:\n"
        "movl $str_00228824, (%esp)\n" /* line 3193 */
        "calll Com_ScriptWarning\n"
        "movl $0, -0x300(%ebp)\n" /* techniqueSet */
        "jmp .Lf1049de_00104fa5\n"
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        ".Lf1049de_00105b2c:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_002221e8, 4(%esp)\n" /* "(" */
        "leal -0x24(%ebp), %edx\n" /* file */
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2398 */
        "jne .Lf1049de_00105b55\n"
        ".Lf1049de_00105b4b:\n"
        "movl $1, %eax\n" /* line 2447 */
        "jmp .Lf1049de_001055df\n"
        ".Lf1049de_00105b55:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222224, 4(%esp)\n" /* ")" */
        "leal -0x24(%ebp), %ecx\n" /* file */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2400 */
        "je .Lf1049de_00105b4b\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "leal -0x24(%ebp), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2402 */
        "je .Lf1049de_00105b4b\n"
        "movl s_passOptionsDx7+4(, %esi, 8), %eax\n" /* line 2414 */
        "movl -0x324(%ebp), %edx\n"
        "movb $1, (%edx, %eax)\n"
        "jmp .Lf1049de_001055a3\n"
        /* } scope */
        /* } scope */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf1049de_00105ba9:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "leal -0x24(%ebp), %eax\n" /* file */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 958 */
        "je .Lf1049de_00105501\n"
        "leal -0x24(%ebp), %edx\n" /* line 961 | file */
        "movl %edx, (%esp)\n"
        "calll Com_ParseInt\n"
        "cmpl %eax, -0x2dc(%ebp)\n" /* line 962 */
        "je .Lf1049de_00105f30\n"
        "movl %eax, 8(%esp)\n" /* line 964 */
        "movl -0x2dc(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $str_002280d8, (%esp)\n" /* "expected %i, found %i instead
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1049de_00105501\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        ".Lf1049de_00105c02:\n"
        "calll Com_UngetToken\n" /* line 1491 */
        "leal -0x19(%ebp), %eax\n" /* line 1492 | existing */
        "movl %eax, 8(%esp)\n"
        "movl -0x2cc(%ebp), %eax\n"
        "movl %eax, 4(%esp)\n"
        "leal -0x4c(%ebp), %eax\n" /* routing */
        "movl %eax, (%esp)\n"
        "calll Material_AllocVertexDecl\n"
        "movl -0x318(%ebp), %edx\n"
        "movl %eax, 4(%edx)\n"
        "cmpb $0, -0x19(%ebp)\n" /* line 1494 | existing */
        "jne .Lf1049de_00105c3f\n"
        "movl %edx, %eax\n" /* line 1495 */
        "addl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "calll Load_BuildVertexDecl\n"
        /* } scope */
        /* { scope 6 */
        ".Lf1049de_00105c3f:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00228a78, 4(%esp)\n" /* "vertexShader" */
        "leal -0x28(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2355 */
        "je .Lf1049de_0010530e\n"
        "xorl %edx, %edx\n" /* line 2357 */
        "leal -0x28(%ebp), %eax\n" /* text */
        "calll Material_LoadPassShader\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2358 */
        "je .Lf1049de_0010530e\n"
        "movl -0x318(%ebp), %esi\n" /* line 2360 */
        "movl %eax, 8(%esi)\n"
        "movl %esi, %eax\n" /* line 2361 */
        "addl $0x14, %eax\n"
        "movl %eax, 4(%esp)\n"
        "subl $4, %eax\n"
        "movl %eax, (%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* techFlags */
        "leal -0x28(%ebp), %eax\n" /* text */
        "calll Material_SetPassShaderArguments\n"
        /* } scope */
        "testb %al, %al\n" /* line 2385 */
        "je .Lf1049de_0010530e\n"
        /* { scope 6 */
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00228a88, 4(%esp)\n" /* "pixelShader" */
        "leal -0x28(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2369 */
        "je .Lf1049de_0010530e\n"
        "movl $1, %edx\n" /* line 2371 */
        "leal -0x28(%ebp), %eax\n" /* text */
        "calll Material_LoadPassShader\n"
        "movl %eax, %edx\n"
        "testl %eax, %eax\n" /* line 2372 */
        "je .Lf1049de_0010530e\n"
        "movl %eax, 0xc(%esi)\n" /* line 2374 */
        "movl %esi, %eax\n" /* line 2375 */
        "addl $0x18, %eax\n"
        "movl %eax, 4(%esp)\n"
        "subl $6, %eax\n"
        "movl %eax, (%esp)\n"
        "leal -0x1c(%ebp), %ecx\n" /* techFlags */
        "leal -0x28(%ebp), %eax\n" /* text */
        "calll Material_SetPassShaderArguments\n"
        /* } scope */
        "testb %al, %al\n" /* line 2387 */
        "je .Lf1049de_0010530e\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e508, 4(%esp)\n" /* "}" */
        "leal -0x28(%ebp), %edx\n" /* text */
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2829 */
        "je .Lf1049de_0010530e\n"
        "addw $1, -0x2f0(%ebp)\n" /* passCount */
        "addl $1, -0x2d0(%ebp)\n"
        "addl $0x1c, %esi\n" /* stageIndex */
        "movl %esi, -0x318(%ebp)\n" /* stageIndex */
        "cmpl $4, -0x2d0(%ebp)\n" /* line 2813 */
        "jne .Lf1049de_00105082\n"
        ".Lf1049de_00105d48:\n"
        "xorl %ebx, %ebx\n" /* error */
        "jmp .Lf1049de_00105313\n"
        ".Lf1049de_00105d4f:\n"
        "movl %eax, 4(%esp)\n" /* line 2820 */
        "movl $str_002288ac, (%esp)\n" /* "expected '{' but found '%s'
" */
        "calll Com_ScriptWarning\n"
        "movl $1, %ebx\n" /* error */
        "jmp .Lf1049de_00105313\n"
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_00105d69:\n"
        "movl $str_002278dc, %edi\n" /* line 1458 */
        "movl $6, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_00105d89\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_00105d89:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105e31\n"
        "movl $2, %edi\n"
        "jmp .Lf1049de_0010520d\n"
        /* } scope */
        /* } scope */
        /* } scope */
        ".Lf1049de_00105d9b:\n"
        "movl %ebx, 4(%esp)\n" /* line 2802 | error */
        "movl $str_0022888c, (%esp)\n" /* "Couldn't open technique '%s'
" */
        "calll Com_ScriptWarning\n"
        "movl $0, -0x300(%ebp)\n" /* techniqueSet */
        "jmp .Lf1049de_00104fa5\n"
        ".Lf1049de_00105dba:\n"
        "movl -0x2f4(%ebp), %esi\n" /* line 2842 | name, stageIndex */
        "movl %esi, 4(%esp)\n" /* stageIndex */
        "movl $str_00228954, (%esp)\n" /* "Technique '%s' has no passes.  The technique should be left " */
        "calll Com_ScriptWarning\n"
        "movl $0, -0x300(%ebp)\n" /* techniqueSet */
        "jmp .Lf1049de_00104fa5\n"
        /* } scope */
        /* } scope */
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        ".Lf1049de_00105ddf:\n"
        "leal -0x24(%ebp), %edx\n" /* line 961 | file */
        "movl %edx, (%esp)\n"
        "calll Com_ParseInt\n"
        "cmpl %eax, -0x2dc(%ebp)\n" /* line 962 */
        "je .Lf1049de_00105ee6\n"
        "movl %eax, 8(%esp)\n" /* line 964 */
        "movl -0x2dc(%ebp), %ecx\n"
        "movl %ecx, 4(%esp)\n"
        "movl $str_002280d8, (%esp)\n" /* "expected %i, found %i instead
" */
        "calll Com_ScriptWarning\n"
        "xorl %eax, %eax\n"
        "jmp .Lf1049de_00105875\n"
        /* } scope */
        /* } scope */
        ".Lf1049de_00105e17:\n"
        "movl %eax, 4(%esp)\n" /* line 2898 */
        "movl $str_002288ac, (%esp)\n" /* "expected '{' but found '%s'
" */
        "calll Com_ScriptWarning\n"
        "movl $1, %ebx\n" /* error */
        "jmp .Lf1049de_00105506\n"
        /* } scope */
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        /* { scope 7 */
        /* { scope 8 */
        ".Lf1049de_00105e31:\n"
        "movl $str_002288cc, %edi\n" /* line 1463 */
        "movl $9, %ecx\n"
        "cld\n"
        "movl %ebx, %esi\n" /* index */
        "repe cmpsb %es:(%edi), (%esi)\n"
        "movl $0, %edx\n"
        "je .Lf1049de_00105e51\n"
        "movzbl -1(%esi), %edx\n"
        "movzbl -1(%edi), %ecx\n"
        "subl %ecx, %edx\n"
        ".Lf1049de_00105e51:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00105ed1\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e510, 4(%esp)\n" /* "[" */
        "leal -0x28(%ebp), %ecx\n" /* text */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1392 */
        "je .Lf1049de_0010530e\n"
        "leal -0x28(%ebp), %esi\n" /* line 1394 | text */
        "movl %esi, (%esp)\n"
        "calll Com_ParseInt\n"
        "movl %eax, %ebx\n"
        "testl %eax, %eax\n" /* line 1395 */
        "js .Lf1049de_00105e8e\n"
        "cmpl $1, %eax\n"
        "jle .Lf1049de_00105ea6\n"
        ".Lf1049de_00105e8e:\n"
        "movl $1, 8(%esp)\n" /* line 1396 */
        "movl %ebx, 4(%esp)\n"
        "movl $str_002289d4, (%esp)\n" /* "index '%i' is not in the range [0, %i]
" */
        "calll Com_ScriptWarning\n"
        ".Lf1049de_00105ea6:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "leal -0x28(%ebp), %eax\n" /* text */
        "movl %eax, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 1465 */
        "je .Lf1049de_0010530e\n"
        "leal 3(%ebx), %edi\n" /* line 1467 | index */
        "jmp .Lf1049de_0010520d\n"
        ".Lf1049de_00105ed1:\n"
        "movl %ebx, 4(%esp)\n" /* line 1471 | index */
        "movl $str_00228a3c, (%esp)\n" /* "unknown stream source '%s'
" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1049de_0010530e\n"
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* } scope */
        /* { scope 4: filename, file, text, passCount, ... */
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        ".Lf1049de_00105ee6:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "leal -0x24(%ebp), %esi\n" /* file */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n"
        "setne %al\n"
        "jmp .Lf1049de_00105875\n"
        /* } scope */
        /* } scope */
        ".Lf1049de_00105f0b:\n"
        "movl -0x2f4(%ebp), %ecx\n" /* line 2920 | name */
        "movl %ecx, 4(%esp)\n"
        "movl $str_00228954, (%esp)\n" /* "Technique '%s' has no passes.  The technique should be left " */
        "calll Com_ScriptWarning\n"
        "movl $0, -0x300(%ebp)\n" /* techniqueSet */
        "jmp .Lf1049de_00104fa5\n"
        /* { scope 5: existing, dest, routing, insertIndex */
        /* { scope 6 */
        /* { scope 7 */
        ".Lf1049de_00105f30:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_0021e504, 4(%esp)\n" /* "]" */
        "leal -0x24(%ebp), %esi\n" /* file */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        /* } scope */
        "testl %eax, %eax\n" /* line 2627 */
        "je .Lf1049de_00105501\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222904, 4(%esp)\n" /* "=" */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2629 */
        "je .Lf1049de_00105501\n"
        "movl %esi, (%esp)\n" /* line 2632 | optionIter */
        "calll Com_Parse\n"
        "movl %eax, -0x32c(%ebp)\n"
        "movl $str_002288d8, %edi\n" /* line 2633 | token */
        "movl $0x10, %ebx\n" /* token */
        "cld\n"
        "movl %eax, %esi\n" /* optionIter */
        "movl %ebx, %ecx\n" /* token */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token, optionIter */
        "movl $0, %edx\n"
        "je .Lf1049de_00105fa3\n"
        "movzbl -1(%esi), %edx\n" /* optionIter */
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %edx\n"
        ".Lf1049de_00105fa3:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_0010601f\n"
        "movl -0x310(%ebp), %esi\n" /* line 2635 | optionIter */
        "movb $1, 9(%esi)\n" /* optionIter */
        ".Lf1049de_00105fb1:\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_002221e8, 4(%esp)\n" /* "(" */
        "leal -0x24(%ebp), %edx\n" /* file */
        "movl %edx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2648 */
        "je .Lf1049de_00105501\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222224, 4(%esp)\n" /* ")" */
        "leal -0x24(%ebp), %ecx\n" /* file */
        "movl %ecx, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2650 */
        "je .Lf1049de_00105501\n"
        "movl $1, 8(%esp)\n" /* line 947 */
        "movl $str_00222924, 4(%esp)\n" /* ";" */
        "leal -0x24(%ebp), %esi\n" /* file */
        "movl %esi, (%esp)\n"
        "calll Com_MatchToken\n"
        "testl %eax, %eax\n" /* line 2652 */
        "je .Lf1049de_00105501\n"
        "jmp .Lf1049de_0010567b\n"
        ".Lf1049de_0010601f:\n"
        "movl $str_002288e8, %edi\n" /* line 2637 | token */
        "movl $0xa, %ebx\n" /* token */
        "cld\n"
        "movl -0x32c(%ebp), %esi\n" /* optionIter */
        "movl %ebx, %ecx\n" /* token */
        "repe cmpsb %es:(%edi), (%esi)\n" /* token, optionIter */
        "movl $0, %edx\n"
        "je .Lf1049de_00106045\n"
        "movzbl -1(%esi), %edx\n" /* optionIter */
        "movzbl -1(%edi), %ecx\n" /* token */
        "subl %ecx, %edx\n"
        ".Lf1049de_00106045:\n"
        "testl %edx, %edx\n"
        "jne .Lf1049de_00106058\n"
        "movl -0x310(%ebp), %esi\n" /* line 2639 | optionIter */
        "movb $2, 9(%esi)\n" /* optionIter */
        "jmp .Lf1049de_00105fb1\n"
        ".Lf1049de_00106058:\n"
        "movl -0x32c(%ebp), %eax\n" /* line 2643 */
        "movl %eax, 4(%esp)\n"
        "movl $str_002288f4, (%esp)\n" /* "expected 'genEyeDirCoords', 'genEyeFacingDotCoords', or 'tex" */
        "calll Com_ScriptWarning\n"
        "jmp .Lf1049de_00105501\n"
    );
}

/* line 3473 — Material_Load
 * Main entry point for loading a material from file.
 * Opens file, allocates memory, reads data, then calls Material_FinishLoadingInstance to parse. */
extern int Material_LoadFile(const char *filename, int *fileHandle);
extern void *Material_Alloc(int size);

Material * Material_Load(const char *name, int imageTrack)
{
    int fileHandle;
    int fileSize = Material_LoadFile(name, &fileHandle);

    if (fileSize < 0) {
        /* File not found — silent for $-prefixed names (built-in) */
        if (name[0] != '$')
            Com_Printf("^1ERROR: Couldn't find material '%s'\n", name);
        return NULL;
    }

    if (fileSize == 0) {
        FS_FCloseFile(fileHandle);
        Com_Printf("^1ERROR: material '%s' has zero length\n", name);
        return NULL;
    }

    /* Allocate, read, and close */
    void *mtlData = Material_Alloc(fileSize);
    FS_Read(mtlData, fileSize, fileHandle);
    FS_FCloseFile(fileHandle);

    /* Material_FinishLoadingInstance uses register convention: eax=mtlData, edx=imageTrack */
    Bool result;
    __asm__ __volatile__ (
        "calll Material_FinishLoadingInstance\n"
        : "=a"(result)
        : "a"(mtlData), "d"(imageTrack)
        : "ecx", "memory"
    );

    if (!result)
        return NULL;
    return (Material *)mtlData;
}

/* std::__adjust_heap for GfxCachedShaderText* — heap sift-down + push-up (12-byte elements) */
void ZSt13__adjust_heapIP19GfxCachedShaderTextiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(
    GfxCachedShaderText *first, int holeIndex, int len, GfxCachedShaderText value, GfxCachedShaderTextCompFunc comp)
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

#if 0 /* original naked */
{
    __asm__ __volatile__ (
        "pushl %ebp\n" /* line 273 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x3c, %esp\n"
        "movl 0x1c(%ebp), %eax\n"
        "movl %eax, -0x30(%ebp)\n"
        "movl 0x18(%ebp), %edx\n"
        "movl %edx, -0x34(%ebp)\n"
        "movl 0x14(%ebp), %ecx\n" /* __value */
        "movl %ecx, -0x38(%ebp)\n"
        /* { scope 1: __value */
        "movl 0xc(%ebp), %eax\n" /* line 276 | __holeIndex */
        "addl %eax, %eax\n"
        "leal 2(%eax), %ebx\n" /* __secondChild */
        "cmpl 0x10(%ebp), %ebx\n" /* line 277 | __len, __secondChild */
        "jl .Lf2c0032_002c0117\n"
        "addl 0xc(%ebp), %eax\n" /* __holeIndex */
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %esi\n"
        "movl 0xc(%ebp), %edi\n" /* __holeIndex */
        ".Lf2c0032_002c006a:\n"
        "cmpl %ebx, 0x10(%ebp)\n" /* line 286 | __secondChild, __len */
        "je .Lf2c0032_002c017a\n"
        ".Lf2c0032_002c0073:\n"
        "movl -0x30(%ebp), %eax\n" /* line 289 */
        "movl %eax, -0x1c(%ebp)\n"
        "movl -0x34(%ebp), %edx\n"
        "movl %edx, -0x20(%ebp)\n"
        "movl -0x38(%ebp), %ecx\n"
        "movl %ecx, -0x24(%ebp)\n" /* __value */
        /* { scope 2 */
        "leal -1(%edi), %edx\n" /* line 165 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "leal (%eax, %edx), %ebx\n"
        "sarl $1, %ebx\n"
        "cmpl 0xc(%ebp), %edi\n" /* line 166 | __holeIndex */
        "jg .Lf2c0032_002c00b3\n"
        "movl %ecx, %eax\n"
        ".Lf2c0032_002c0099:\n"
        "movl %eax, (%esi)\n" /* line 173 */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __value */
        /* { scope 2 */
        ".Lf2c0032_002c00af:\n"
        "movl %ebx, %edi\n" /* line 166 */
        "movl %eax, %ebx\n"
        ".Lf2c0032_002c00b3:\n"
        "leal (%ebx, %ebx, 2), %eax\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %esi\n"
        "leal -0x24(%ebp), %ecx\n" /* __value */
        "movl %ecx, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *0x20(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2c0032_002c01ab\n"
        "leal (%edi, %edi, 2), %edx\n" /* line 169 */
        "shll $2, %edx\n"
        "movl (%esi), %eax\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "movl %eax, (%edx, %ecx)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx, %ecx)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edx, %ecx)\n"
        "leal -1(%ebx), %edx\n" /* line 171 */
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "cmpl 0xc(%ebp), %ebx\n" /* line 166 | __holeIndex */
        "jg .Lf2c0032_002c00af\n"
        "movl -0x24(%ebp), %eax\n" /* __value */
        "movl %eax, (%esi)\n" /* line 173 */
        "movl -0x20(%ebp), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl -0x1c(%ebp), %eax\n"
        "movl %eax, 8(%esi)\n"
        /* } scope */
        /* } scope */
        "addl $0x3c, %esp\n" /* line 291 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __value */
        ".Lf2c0032_002c0117:\n"
        "movl 0xc(%ebp), %ecx\n" /* line 277 | __holeIndex */
        "movl %ecx, -0x2c(%ebp)\n"
        "movl %ebx, %edi\n" /* __secondChild */
        "jmp .Lf2c0032_002c015b\n"
        ".Lf2c0032_002c0121:\n"
        "leal -1(%ebx), %edi\n" /* line 281 | __secondChild */
        "leal (%edi, %edi, 2), %eax\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%ecx, %eax, 4), %esi\n"
        ".Lf2c0032_002c012d:\n"
        "movl -0x2c(%ebp), %eax\n" /* line 282 */
        "leal (%eax, %eax, 2), %edx\n"
        "shll $2, %edx\n"
        "movl (%esi), %eax\n"
        "movl %eax, (%edx, %ecx)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edx, %ecx)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edx, %ecx)\n"
        "leal 2(%edi, %edi), %ebx\n" /* line 284 | __secondChild */
        "cmpl %ebx, 0x10(%ebp)\n" /* line 277 | __secondChild, __len */
        "jle .Lf2c0032_002c006a\n"
        "movl %edi, -0x2c(%ebp)\n"
        "movl %ebx, %edi\n" /* __secondChild */
        ".Lf2c0032_002c015b:\n"
        "leal (%ebx, %ebx, 2), %eax\n" /* line 279 | __secondChild */
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %esi\n"
        "leal -0xc(%esi), %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl %esi, (%esp)\n"
        "calll *0x20(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2c0032_002c0121\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "jmp .Lf2c0032_002c012d\n"
        ".Lf2c0032_002c017a:\n"
        "movl 0x10(%ebp), %edx\n" /* line 288 | __len */
        "leal (%edx, %edx, 2), %eax\n"
        "movl 8(%ebp), %ecx\n" /* __first */
        "leal (%ecx, %eax, 4), %eax\n"
        "leal -0xc(%eax), %edx\n"
        "movl -0xc(%eax), %eax\n"
        "movl %eax, (%esi)\n"
        "movl 4(%edx), %eax\n"
        "movl %eax, 4(%esi)\n"
        "movl 8(%edx), %eax\n"
        "movl %eax, 8(%esi)\n"
        "movl 0x10(%ebp), %edi\n" /* line 289 | __len */
        "subl $1, %edi\n"
        "leal (%edi, %edi, 2), %eax\n"
        "leal (%ecx, %eax, 4), %esi\n"
        "jmp .Lf2c0032_002c0073\n"
        /* { scope 2 */
        ".Lf2c0032_002c01ab:\n"
        "leal (%edi, %edi, 2), %eax\n" /* line 166 */
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %esi\n"
        "movl -0x24(%ebp), %eax\n" /* __value */
        "jmp .Lf2c0032_002c0099\n"
    );
}
#endif /* original naked adjust_heap GfxCachedShaderText */

/* std::__introsort_loop for GfxCachedShaderText* — introsort with heapsort fallback (12-byte elements) */
void ZSt16__introsort_loopIP19GfxCachedShaderTextiPFhRKS0_S3_EEvT_S6_T0_T1_(
    GfxCachedShaderText *first, GfxCachedShaderText *last, int depth_limit, GfxCachedShaderTextCompFunc comp)
{
    while ((char *)last - (char *)first > 12 * 16) {
        if (depth_limit == 0) {
            int n = (int)(last - first);
            int half = (n - 2) / 2;
            int i;
            GfxCachedShaderText *end;
            for (i = half; i >= 0; i--)
                ZSt13__adjust_heapIP19GfxCachedShaderTextiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(first, i, n, first[i], comp);
            for (end = last - 1; end - first > 0; end--) {
                GfxCachedShaderText value = *end;
                *end = *first;
                ZSt13__adjust_heapIP19GfxCachedShaderTextiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_(first, 0, (int)(end - first), value, comp);
            }
            return;
        }
        depth_limit--;
        {
            int n = (int)(last - first);
            GfxCachedShaderText *midPtr = first + n / 2;
            GfxCachedShaderText *pivotPtr;
            GfxCachedShaderText pivot;
            GfxCachedShaderText *lo, *hi;
            if (comp(first, midPtr)) {
                if (comp(midPtr, last - 1)) pivotPtr = midPtr;
                else if (comp(first, last - 1)) pivotPtr = last - 1;
                else pivotPtr = first;
            } else {
                if (comp(first, last - 1)) pivotPtr = first;
                else if (comp(last - 1, midPtr)) pivotPtr = midPtr;
                else pivotPtr = last - 1;
            }
            pivot = *pivotPtr;
            lo = first; hi = last;
            for (;;) {
                while (!comp(&pivot, lo)) lo++;
                hi--;
                while (!comp(hi, &pivot)) hi--;
                if (lo >= hi) break;
                { GfxCachedShaderText tmp = *lo; *lo = *hi; *hi = tmp; }
                lo++;
            }
            ZSt16__introsort_loopIP19GfxCachedShaderTextiPFhRKS0_S3_EEvT_S6_T0_T1_(lo, last, depth_limit, comp);
            last = lo;
        }
    }
}

#if 0 /* original naked introsort GfxCachedShaderText */
{
    __asm__ __volatile__ (
        ".Lf2c01bc_002c01bc:\n"
        "pushl %ebp\n" /* line 2514 */
        "movl %esp, %ebp\n"
        "pushl %edi\n"
        "pushl %esi\n"
        "pushl %ebx\n"
        "subl $0x9c, %esp\n"
        /* { scope 1: __pivot */
        "movl 0xc(%ebp), %eax\n" /* line 2519 | __last */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0xcb, %eax\n"
        "jle .Lf2c01bc_002c0327\n"
        /* { scope 2 */
        "movl 0x10(%ebp), %edx\n" /* line 2521 | __depth_limit */
        "testl %edx, %edx\n"
        "jne .Lf2c01bc_002c0332\n"
        /* { scope 3 */
        /* { scope 4 */
        ".Lf2c01bc_002c01e4:\n"
        "cmpl $0x17, %eax\n" /* line 397 */
        "jle .Lf2c01bc_002c0327\n"
        "movl %eax, %ecx\n" /* line 400 */
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl %eax, -0x5c(%ebp)\n"
        "movl %eax, %edx\n" /* line 2514 */
        "subl $2, %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "movl %eax, -0x6c(%ebp)\n"
        "leal (%eax, %eax, 2), %eax\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "leal (%edx, %eax, 4), %ebx\n"
        "xorl %edi, %edi\n"
        "jmp .Lf2c01bc_002c0231\n"
        ".Lf2c01bc_002c022e:\n"
        "addl $1, %edi\n" /* line 406 */
        ".Lf2c01bc_002c0231:\n"
        "movl (%ebx), %ecx\n" /* line 404 */
        "movl %ecx, -0x30(%ebp)\n"
        "movl 4(%ebx), %edx\n"
        "movl %edx, -0x2c(%ebp)\n"
        "movl 8(%ebx), %eax\n"
        "movl %eax, -0x28(%ebp)\n"
        "movl 0x14(%ebp), %esi\n" /* __comp */
        "movl %esi, 0x18(%esp)\n"
        "movl %ecx, 0xc(%esp)\n"
        "movl %edx, 0x10(%esp)\n"
        "movl %eax, 0x14(%esp)\n"
        "movl -0x5c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl -0x6c(%ebp), %eax\n"
        "subl %edi, %eax\n"
        "movl %eax, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, (%esp)\n"
        "calll ZSt13__adjust_heapIP19GfxCachedShaderTextiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_\n"
        "subl $0xc, %ebx\n"
        "cmpl -0x6c(%ebp), %edi\n" /* line 406 */
        "jne .Lf2c01bc_002c022e\n"
        /* } scope */
        /* } scope */
        "movl 0xc(%ebp), %edi\n" /* line 2521 | __last */
        "movl %edi, %esi\n"
        "subl $4, %esi\n"
        "movl %edi, %eax\n" /* line 2514 */
        "subl 8(%ebp), %eax\n" /* __first */
        "movl %eax, -0x54(%ebp)\n"
        "subl $0xc, %eax\n"
        "movl %eax, -0x58(%ebp)\n"
        ".Lf2c01bc_002c028e:\n"
        "movl (%esi), %ebx\n" /* line 330 */
        "movl -4(%esi), %ecx\n"
        "movl -8(%esi), %edx\n"
        /* { scope 3 */
        /* { scope 4 */
        "movl 8(%ebp), %eax\n" /* line 301 | __first */
        "movl (%eax), %eax\n"
        "movl %eax, -0xc(%edi)\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl 4(%eax), %eax\n"
        "movl %eax, -8(%edi)\n"
        "movl 8(%ebp), %eax\n" /* __first */
        "movl 8(%eax), %eax\n"
        "movl %eax, -4(%edi)\n"
        "movl %ebx, -0x1c(%ebp)\n" /* line 302 */
        "movl %ecx, -0x20(%ebp)\n"
        "movl %edx, -0x24(%ebp)\n"
        "movl 0x14(%ebp), %eax\n" /* __comp */
        "movl %eax, 0x18(%esp)\n"
        "movl %edx, 0xc(%esp)\n"
        "movl %ecx, 0x10(%esp)\n"
        "movl %ebx, 0x14(%esp)\n"
        "movl -0x58(%ebp), %ecx\n"
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 4), %eax\n"
        "movl %eax, %edx\n"
        "shll $4, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $8, %edx\n"
        "addl %edx, %eax\n"
        "movl %eax, %edx\n"
        "shll $0x10, %edx\n"
        "addl %edx, %eax\n"
        "leal (%ecx, %eax, 2), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl $0, 4(%esp)\n"
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, (%esp)\n"
        "calll ZSt13__adjust_heapIP19GfxCachedShaderTextiS0_PFhRKS0_S3_EEvT_T0_S7_T1_T2_\n"
        "subl $0xc, %edi\n"
        "subl $0xc, %esi\n"
        "subl $0xc, -0x58(%ebp)\n"
        /* } scope */
        /* } scope */
        "movl 8(%ebp), %eax\n" /* line 457 | __first */
        "subl 0xc(%ebp), %eax\n" /* __last */
        "addl -0x54(%ebp), %eax\n"
        "movl -0x58(%ebp), %edx\n"
        "leal 0xc(%eax, %edx), %eax\n"
        "cmpl $0x17, %eax\n"
        "jg .Lf2c01bc_002c028e\n"
        /* } scope */
        /* } scope */
        ".Lf2c01bc_002c0327:\n"
        "addl $0x9c, %esp\n" /* line 2538 */
        "popl %ebx\n"
        "popl %esi\n"
        "popl %edi\n"
        "popl %ebp\n"
        "retl\n"
        /* { scope 1: __pivot */
        ".Lf2c01bc_002c0332:\n"
        "movl 0x10(%ebp), %esi\n" /* line 457 | __depth_limit */
        "movl %esi, -0x4c(%ebp)\n"
        "movl $0, -0x50(%ebp)\n"
        "movl 0xc(%ebp), %edi\n" /* __last */
        ".Lf2c01bc_002c0342:\n"
        "subl $1, -0x4c(%ebp)\n" /* line 2526 */
        "movl 8(%ebp), %esi\n" /* __first */
        "movl %eax, %ecx\n"
        "sarl $2, %ecx\n"
        "leal (%ecx, %ecx, 4), %edx\n"
        "movl %edx, %eax\n"
        "shll $4, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $8, %eax\n"
        "addl %eax, %edx\n"
        "movl %edx, %eax\n"
        "shll $0x10, %eax\n"
        "addl %eax, %edx\n"
        "leal (%ecx, %edx, 2), %edx\n"
        "movl %edx, %eax\n"
        "shrl $0x1f, %eax\n"
        "addl %edx, %eax\n"
        "sarl $1, %eax\n"
        "leal (%eax, %eax, 2), %eax\n"
        "leal (%esi, %eax, 4), %ebx\n"
        "subl $0xc, %edi\n"
        /* { scope 2 */
        "movl %ebx, 4(%esp)\n" /* line 124 */
        "movl %esi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2c01bc_002c0477\n"
        "movl %edi, 4(%esp)\n" /* line 125 */
        "movl %ebx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2c01bc_002c0416\n"
        ".Lf2c01bc_002c039b:\n"
        "movl %ebx, %esi\n" /* line 133 */
        ".Lf2c01bc_002c039d:\n"
        "movl 4(%esi), %eax\n" /* line 2536 | __b */
        "movl (%esi), %ecx\n" /* __b */
        "movl 8(%esi), %edx\n" /* __b */
        "movl %edx, -0x34(%ebp)\n"
        "movl %eax, -0x38(%ebp)\n"
        "movl %ecx, -0x3c(%ebp)\n" /* __pivot */
        "movl 8(%ebp), %edi\n" /* __first, __cut */
        "movl 0xc(%ebp), %esi\n" /* __last, __b */
        /* } scope */
        /* { scope 2 */
        ".Lf2c01bc_002c03b4:\n"
        "leal -0x3c(%ebp), %eax\n" /* line 2056 | __pivot */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2c01bc_002c0411\n"
        ".Lf2c01bc_002c03c5:\n"
        "subl $0xc, %esi\n" /* line 2060 */
        "movl %esi, 4(%esp)\n" /* line 2059 */
        "leal -0x3c(%ebp), %edx\n" /* __pivot */
        "movl %edx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2c01bc_002c03c5\n"
        "cmpl %esi, %edi\n" /* line 2061 */
        "jae .Lf2c01bc_002c0432\n"
        /* } scope */
        /* } scope */
        "movl 8(%edi), %edx\n" /* line 97 */
        "movl 4(%edi), %ecx\n"
        "movl (%edi), %ebx\n"
        /* { scope 1: __pivot */
        /* { scope 2 */
        /* { scope 3 */
        "movl (%esi), %eax\n" /* line 98 */
        "movl %eax, (%edi)\n"
        "movl 4(%esi), %eax\n"
        "movl %eax, 4(%edi)\n"
        "movl 8(%esi), %eax\n"
        "movl %eax, 8(%edi)\n"
        "movl %edx, 8(%esi)\n" /* line 99 */
        "movl %ecx, 4(%esi)\n"
        "movl %ebx, (%esi)\n"
        /* } scope */
        "addl $0xc, %edi\n" /* line 2064 */
        "leal -0x3c(%ebp), %eax\n" /* line 2056 | __pivot */
        "movl %eax, 4(%esp)\n"
        "movl %edi, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2c01bc_002c03c5\n"
        ".Lf2c01bc_002c0411:\n"
        "addl $0xc, %edi\n" /* line 2057 */
        "jmp .Lf2c01bc_002c03b4\n"
        /* } scope */
        /* { scope 2 */
        ".Lf2c01bc_002c0416:\n"
        "movl %edi, 4(%esp)\n" /* line 127 */
        "movl 8(%ebp), %eax\n" /* __first */
        "movl %eax, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2c01bc_002c039d\n"
        "movl %edi, %esi\n" /* line 133 */
        "jmp .Lf2c01bc_002c039d\n"
        /* } scope */
        ".Lf2c01bc_002c0432:\n"
        "movl 0x14(%ebp), %esi\n" /* line 2537 | __comp, __b */
        "movl %esi, 0xc(%esp)\n" /* __b */
        "movl -0x4c(%ebp), %eax\n"
        "movl %eax, 8(%esp)\n"
        "movl 0xc(%ebp), %edx\n" /* __last */
        "movl %edx, 4(%esp)\n"
        "movl %edi, (%esp)\n" /* __cut */
        "calll ZSt16__introsort_loopIP19GfxCachedShaderTextiPFhRKS0_S3_EEvT_S6_T0_T1_\n"
        /* } scope */
        "movl %edi, %eax\n" /* line 2519 */
        "subl 8(%ebp), %eax\n" /* __first */
        "cmpl $0xcb, %eax\n"
        "jle .Lf2c01bc_002c0327\n"
        "addl $1, -0x50(%ebp)\n"
        "movl %edi, 0xc(%ebp)\n" /* __last */
        /* { scope 1: __pivot */
        "movl -0x50(%ebp), %edx\n" /* line 2521 */
        "cmpl %edx, 0x10(%ebp)\n" /* __depth_limit */
        "jne .Lf2c01bc_002c0342\n"
        "jmp .Lf2c01bc_002c01e4\n"
        /* { scope 2 */
        ".Lf2c01bc_002c0477:\n"
        "movl %edi, 4(%esp)\n" /* line 131 */
        "movl 8(%ebp), %edx\n" /* __first */
        "movl %edx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "jne .Lf2c01bc_002c039d\n"
        "movl %edi, 4(%esp)\n" /* line 133 */
        "movl %ebx, (%esp)\n"
        "calll *0x14(%ebp)\n" /* __comp */
        "testb %al, %al\n"
        "je .Lf2c01bc_002c039b\n"
        "movl %edi, %esi\n"
        "jmp .Lf2c01bc_002c039d\n"
    );
}
#endif /* original naked introsort GfxCachedShaderText */

